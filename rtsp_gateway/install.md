# zz-rtsp-gateway — Instalación y operación

Servicio para Ubuntu 24.04 que recibe cámaras/NVR Dahua conectados por **registro activo** (Auto Register) y publica su video como **RTSP**, sin recodificar.

```
cámara remota ──(conexión saliente TCP 9500)──> zz-rtsp-gateway (ZZNetSDK)
                                                   │ video DHAV por callback
                                                   ▼
                                  ffmpeg -f dhav -c copy (un proceso por canal)
                                                   │ RTSP publish (localhost)
                                                   ▼
                              MediaMTX :8554 ──> rtsp://visor:clave@servidor:8554/<ID>
```

Fundamentos y diagramas: `Doc/09-registro-activo.md` y `Doc/10-pasarela-rtsp.md`.

## Contenido del directorio

```text
rtsp_gateway/
├── install.md                     este documento
├── Makefile                       compilación e instalación (make / make install)
├── CMakeLists.txt                 alternativa con CMake
├── src/zz_rtsp_gateway.cpp        código fuente
├── tools/mkdav.py                 generador de flujo DHAV de prueba (modo simulación)
├── config/
│   ├── gateway.env.example        configuración del servicio (.env)
│   ├── cameras.conf.example       equipos autorizados y sus credenciales
│   └── mediamtx.yml               configuración mínima del servidor RTSP
└── systemd/
    ├── zz-rtsp-gateway.service
    └── mediamtx.service
```

## 1. Requisitos

| Elemento | Versión / valor |
|---|---|
| Sistema | Ubuntu 24.04 LTS x86-64 (glibc ≥ 2.38) |
| ZZNetSDK | Instalado en `/opt/zznetsdk` (`include/` y `lib_linux64/`) |
| Compilador | g++ ≥ 13 (`build-essential`) |
| Bibliotecas | `libssl-dev`, `libpsl-dev` |
| FFmpeg | ≥ 4.3 con demuxer `dhav` (Ubuntu 24.04 trae 6.1) |
| MediaMTX | Binario `linux_amd64` (probado con v1.9.3) |
| Red | TCP 9500 entrante (registro de cámaras); TCP 8554 para clientes RTSP |

## 2. Instalar ZZNetSDK

Resumen de `Doc/02-instalacion-ubuntu.md`:

```bash
sudo apt update
sudo apt install -y build-essential libssl-dev libpsl-dev ffmpeg

SDK_SRC="/ruta/a/ZZNetSDK_Linux64_GCC13.3.0_V3.0.7.6.R.2026-02-06"
sudo mkdir -p /opt/zznetsdk
sudo cp -r "$SDK_SRC/include" "$SDK_SRC/lib_linux64" /opt/zznetsdk/
cd /opt/zznetsdk/lib_linux64
sudo ln -sf libgeneral_avnetsdk.so  libavnetsdk.so
sudo ln -sf libgeneral_configsdk.so libdhconfigsdk.so
echo /opt/zznetsdk/lib_linux64 | sudo tee /etc/ld.so.conf.d/zznetsdk.conf
sudo ldconfig

ffmpeg -hide_banner -demuxers | grep dhav      # debe mostrar:  D  dhav  Video DAV
```

## 3. Instalar MediaMTX

```bash
# Descargar la última versión linux_amd64 desde https://github.com/bluenviron/mediamtx/releases
VER=v1.9.3        # o la más reciente
curl -LO https://github.com/bluenviron/mediamtx/releases/download/$VER/mediamtx_${VER}_linux_amd64.tar.gz
tar xzf mediamtx_${VER}_linux_amd64.tar.gz mediamtx
sudo install -m 755 mediamtx /usr/local/bin/mediamtx
```

> Si se usa una versión de MediaMTX distinta, verificar que las claves de `config/mediamtx.yml` existan en el `mediamtx.yml` de esa versión (`authInternalUsers` existe desde v1.8).

## 4. Crear usuarios de sistema

Ambos servicios corren sin privilegios:

```bash
sudo useradd --system --no-create-home --shell /usr/sbin/nologin zzgw
sudo useradd --system --no-create-home --shell /usr/sbin/nologin mediamtx
```

## 5. Compilar

### Con make (recomendado)

```bash
cd rtsp_gateway
make                         # SDK=/opt/zznetsdk por defecto
./zz-rtsp-gateway --version
```

Otra ruta del SDK: `make SDK=/otra/ruta`.

Comando equivalente, sin Makefile:

```bash
g++ -std=c++17 -O2 -Wall -Wextra src/zz_rtsp_gateway.cpp -o zz-rtsp-gateway \
    -I/opt/zznetsdk/include -L/opt/zznetsdk/lib_linux64 \
    -lZZNetSDK -lgeneral_netsdk -lgeneral_configsdk -lssl -lcrypto -lpsl -lpthread
```

### Con CMake

```bash
cmake -S . -B build -DZZNETSDK_ROOT=/opt/zznetsdk
cmake --build build -j
```

Notas:

- Debe compilarse como **C++17** (las cabeceras del SDK son C++).
- `-lssl -lcrypto -lpsl` son obligatorias: `libZZNetSDK.so` usa OpenSSL y libpsl sin declararlas.
- Si al ejecutar aparece `libgeneral_configsdk.so: cannot open shared object file`, falta el paso de `ldconfig` (o `LD_LIBRARY_PATH`) del punto 2.

## 6. Instalar

```bash
sudo make install
```

| Archivo instalado | Destino | Permisos |
|---|---|---|
| Binario | `/usr/local/bin/zz-rtsp-gateway` | 755 |
| Configuración | `/etc/zz-rtsp-gateway/gateway.env` | 640 root:zzgw (no se pisa si existe) |
| Cámaras | `/etc/zz-rtsp-gateway/cameras.conf` | 640 root:zzgw (no se pisa si existe) |
| MediaMTX | `/etc/mediamtx/mediamtx.yml` | 640 root:mediamtx (no se pisa si existe) |
| Units | `/etc/systemd/system/zz-rtsp-gateway.service`, `mediamtx.service` | 644 |
| Este documento | `/opt/zz-rtsp-gateway/install.md` | 644 |

Instalación manual equivalente:

```bash
sudo install -m 755 zz-rtsp-gateway /usr/local/bin/
sudo install -d -m 750 -g zzgw /etc/zz-rtsp-gateway
sudo install -m 640 -g zzgw config/gateway.env.example  /etc/zz-rtsp-gateway/gateway.env
sudo install -m 640 -g zzgw config/cameras.conf.example /etc/zz-rtsp-gateway/cameras.conf
sudo install -D -m 640 -g mediamtx config/mediamtx.yml  /etc/mediamtx/mediamtx.yml
sudo install -m 644 systemd/*.service /etc/systemd/system/
```

## 7. Configurar

### 7.1 `/etc/zz-rtsp-gateway/gateway.env`

Formato `.env`: `CLAVE=valor`, líneas `#` son comentarios, se admiten comillas y el prefijo `export`. Las **variables de entorno del proceso tienen prioridad** sobre el archivo (útil para pruebas: `ZZGW_LOG_LEVEL=debug zz-rtsp-gateway ...`).

| Variable | Defecto | Descripción | Recarga en caliente |
|---|---|---|:-:|
| `ZZGW_LISTEN_IP` | `0.0.0.0` | IP local donde escuchar los registros | No |
| `ZZGW_LISTEN_PORT` | `9500` | Puerto TCP (el mismo que se configura en la cámara) | No |
| `ZZGW_ALLOWED_CIDRS` | `0.0.0.0/0` | Redes IPv4 permitidas, separadas por coma (`181.10.20.0/24,200.45.1.7/32`) | **Sí** |
| `ZZGW_MAX_SESSIONS` | `64` | Máximo de equipos simultáneos | No |
| `ZZGW_CAMERAS_FILE` | — | Archivo de equipos autorizados | **Sí** (contenido) |
| `ZZGW_ALLOW_UNKNOWN_IDS` | `false` | Aceptar IDs no listados usando las credenciales por defecto | **Sí** |
| `ZZGW_DEFAULT_USER` / `ZZGW_DEFAULT_PASS` | `admin` / — | Credenciales para IDs no listados | **Sí** |
| `ZZGW_STREAM` | `sub` | Flujo por defecto: `main`, `sub`, `sub2` | No* |
| `ZZGW_DEFAULT_CHANNELS` | `0` | Canales por defecto: `0`, `0,1,2`, `all` | No* |
| `ZZGW_BUFFER_POLICY` | `0` | Buffer del SDK: 0 defecto, 1 fluidez, 2 tiempo real | No* |
| `ZZGW_RTSP_URL` | `rtsp://127.0.0.1:8554` | Servidor RTSP de destino | No |
| `ZZGW_PATH_TEMPLATE` | `{id}` | Ruta RTSP. `{id}`, `{ch}` (1..N), `{sn}` (nº de serie). Con varios canales se agrega `/ch{ch}` si falta | No* |
| `ZZGW_FFMPEG_BIN` | `/usr/bin/ffmpeg` | Ejecutable de ffmpeg | No |
| `ZZGW_FFMPEG_LOGLEVEL` | `warning` | Nivel de log de ffmpeg | No* |
| `ZZGW_FFMPEG_INPUT_ARGS` | `-probesize 1000000 -analyzeduration 1000000` | Argumentos de entrada de ffmpeg | No* |
| `ZZGW_FFMPEG_OUTPUT_ARGS` | `-c copy -f rtsp -rtsp_transport tcp` | Argumentos de salida (antes de la URL) | No* |
| `ZZGW_QUEUE_MAX_MB` | `8` | Cola por canal antes de descartar datos | No* |
| `ZZGW_RESTART_DELAY_SEC` | `3` | Espera antes de relanzar un ffmpeg caído | No* |
| `ZZGW_LOG_LEVEL` | `info` | `error`, `warn`, `info`, `debug` | **Sí** |
| `ZZGW_STATS_INTERVAL_SEC` | `60` | Intervalo del log de estadísticas (0 = desactivado) | No |

\* Se aplica a los equipos que se registren después de un `restart`. Los marcados "Sí" se aplican con `systemctl reload`.

Archivo de ejemplo completo (`config/gateway.env.example`):

```bash
# =====================================================================
# zz-rtsp-gateway — configuración
# Copiar a /etc/zz-rtsp-gateway/gateway.env  (chmod 640, root:zzgw)
# Las variables de entorno del proceso tienen prioridad sobre este archivo.
# Tras editar: sudo systemctl reload zz-rtsp-gateway   (ver qué se recarga en install.md)
# =====================================================================

# ---------- Registro activo (conexiones entrantes de las cámaras) ----------
# IP local donde escuchar (0.0.0.0 = todas las interfaces)        [requiere restart]
ZZGW_LISTEN_IP=0.0.0.0
# Puerto TCP configurado en la cámara (Red > Registro > Puerto)   [requiere restart]
ZZGW_LISTEN_PORT=9500
# Redes (IPv4 CIDR) desde las que se aceptan registros. Separar con coma.
# Ejemplos: 0.0.0.0/0 (cualquiera)   181.10.20.0/24,200.45.1.7/32   10.0.0.0/8
ZZGW_ALLOWED_CIDRS=0.0.0.0/0
# Máximo de equipos registrados simultáneamente
ZZGW_MAX_SESSIONS=64

# ---------- Credenciales de los equipos ----------
# Archivo con una línea por equipo:  ID  usuario  clave  [canales]  [flujo]
ZZGW_CAMERAS_FILE=/etc/zz-rtsp-gateway/cameras.conf
# Aceptar IDs que no están en el archivo usando las credenciales por defecto
ZZGW_ALLOW_UNKNOWN_IDS=false
ZZGW_DEFAULT_USER=admin
ZZGW_DEFAULT_PASS=

# ---------- Video ----------
# Flujo por defecto: main (principal) | sub (sub-flujo 1) | sub2 (sub-flujo 2)
ZZGW_STREAM=sub
# Canales por defecto (0 = primero). Ej.: 0  |  0,1,2  |  all (todos los del equipo)
ZZGW_DEFAULT_CHANNELS=0
# Política de buffer del SDK: 0 defecto | 1 fluidez | 2 tiempo real (baja latencia)
ZZGW_BUFFER_POLICY=0

# ---------- Salida RTSP ----------
# Servidor RTSP donde se publica (MediaMTX local)                 [requiere restart]
ZZGW_RTSP_URL=rtsp://127.0.0.1:8554
# Ruta de cada flujo. Variables: {id} ID del equipo, {ch} canal (1..N), {sn} nº de serie
# Si el equipo publica varios canales y la plantilla no tiene {ch}, se agrega /ch{ch}
ZZGW_PATH_TEMPLATE={id}

# ---------- ffmpeg ----------
ZZGW_FFMPEG_BIN=/usr/bin/ffmpeg
ZZGW_FFMPEG_LOGLEVEL=warning
ZZGW_FFMPEG_INPUT_ARGS="-probesize 1000000 -analyzeduration 1000000"
ZZGW_FFMPEG_OUTPUT_ARGS="-c copy -f rtsp -rtsp_transport tcp"
# Tamaño máximo de la cola por canal (MB) antes de descartar datos
ZZGW_QUEUE_MAX_MB=8
# Espera antes de relanzar ffmpeg si termina (por ejemplo, reinicio de MediaMTX)
ZZGW_RESTART_DELAY_SEC=3

# ---------- Operación ----------
# error | warn | info | debug
ZZGW_LOG_LEVEL=info
# Cada cuántos segundos registrar bitrate/descartes por flujo (0 = nunca)
ZZGW_STATS_INTERVAL_SEC=60
```

### 7.2 `/etc/zz-rtsp-gateway/cameras.conf`

Una línea por equipo. El **ID** debe coincidir con el "ID de sub-dispositivo" configurado en la cámara (Configuración → Red → Registro).

```text
# =====================================================================
# zz-rtsp-gateway — equipos autorizados
# Copiar a /etc/zz-rtsp-gateway/cameras.conf  (chmod 640, root:zzgw)
# Recargar sin reiniciar: sudo systemctl reload zz-rtsp-gateway
#
# Formato (separado por espacios):
#   ID  usuario  clave  [canales]  [flujo]
#
#   ID       = "ID de sub-dispositivo" configurado en la cámara (Red > Registro)
#              caracteres permitidos: letras, números, - _ .  (máx. 64)
#   canales  = 0 | 0,1,3 | all | -   ("-" = ZZGW_DEFAULT_CHANNELS)
#   flujo    = main | sub | sub2     (omitido = ZZGW_STREAM)
#   La clave no puede contener espacios.
# =====================================================================

# Cámara IP de una sola lente, sub-flujo -> rtsp://servidor:8554/CAM-SUC01-01
CAM-SUC01-01   plataforma   ClaveCam01!

# Cámara con flujo principal
CAM-SUC01-02   plataforma   ClaveCam02!   0      main

# NVR: publicar los canales 1 a 4 -> rtsp://servidor:8554/NVR-SUC02/ch1 ... /ch4
NVR-SUC02      plataforma   ClaveNvr02!   0,1,2,3 sub
```

Rutas RTSP resultantes con el ejemplo:

| Equipo | Ruta |
|---|---|
| `CAM-SUC01-01` | `rtsp://servidor:8554/CAM-SUC01-01` |
| `CAM-SUC01-02` | `rtsp://servidor:8554/CAM-SUC01-02` (flujo principal) |
| `NVR-SUC02` | `rtsp://servidor:8554/NVR-SUC02/ch1` … `/ch4` |

### 7.3 Reglas de admisión

Un registro se acepta sólo si se cumplen **todas** estas condiciones, en este orden:

1. La IP de origen está dentro de `ZZGW_ALLOWED_CIDRS`.
2. El ID sólo tiene caracteres `A-Z a-z 0-9 - _ .` (máx. 64). Así se evita inyección en rutas y logs, porque el ID llega desde la red.
3. El ID está en `cameras.conf` (o `ZZGW_ALLOW_UNKNOWN_IDS=true`).
4. No se superó `ZZGW_MAX_SESSIONS`.
5. El login con las credenciales del ID es exitoso.

Un registro rechazado queda en el log (`[rechazo] ...`). El filtro por IP es a nivel aplicación; conviene complementarlo con el firewall (§9) para que las IPs no permitidas ni siquiera lleguen al puerto.

Probar el filtro sin cámaras:

```bash
sudo -u zzgw zz-rtsp-gateway --env /etc/zz-rtsp-gateway/gateway.env --test-ip 181.10.20.55
# 181.10.20.55: PERMITIDA      (código de salida 0; RECHAZADA = 1)
```

### 7.4 MediaMTX (`/etc/mediamtx/mediamtx.yml`)

**Cambiar la clave del usuario `visor`.** Sólo `localhost` (la pasarela) puede publicar.

```yaml
# MediaMTX — configuración mínima para zz-rtsp-gateway
# Copiar a /etc/mediamtx/mediamtx.yml
logLevel: info
rtspAddress: :8554
# Deshabilitar lo que no se usa (habilitar hls/webrtc si se quiere ver en navegador)
rtmp: no
hls: no
webrtc: no
srt: no

authInternalUsers:
  # Sólo la pasarela (localhost) puede publicar
  - user: any
    ips: ['127.0.0.1/32', '::1/128']
    permissions:
      - action: publish
  # Clientes RTSP (VLC, VMS, NVR de terceros). CAMBIAR LA CLAVE.
  - user: visor
    pass: CambiarEstaClave
    permissions:
      - action: read
  # API/métricas sólo local
  - user: any
    ips: ['127.0.0.1/32', '::1/128']
    permissions:
      - action: api
      - action: metrics

paths:
  all_others:
```

## 8. Validar la configuración

```bash
sudo -u zzgw zz-rtsp-gateway --env /etc/zz-rtsp-gateway/gateway.env --check-config
```

Salida esperada (las claves se muestran como `***`):

```text
zz-rtsp-gateway 1.0.0 (ZZNetSDK 1.1.1.3)
  archivo .env           : /etc/zz-rtsp-gateway/gateway.env
  escucha                : 0.0.0.0:9500/TCP
  redes permitidas       : 181.10.20.0/24 200.45.1.7/32 10.0.0.0/8
  archivo de cámaras     : /etc/zz-rtsp-gateway/cameras.conf (3 cámaras)
      CAM-SUC01-01             usuario=plataforma clave=*** canales=0 flujo=sub
      ...
Configuración OK
```

Con errores devuelve el **código 78** y un mensaje, por ejemplo `configuración: ZZGW_STREAM debe ser main|sub|sub2`. El unit de systemd ejecuta esta validación antes de arrancar (`ExecStartPre`) y no reintenta en bucle ante el código 78.

## 9. Firewall

```bash
# Registro de cámaras: restringir a las redes de los sitios si se conocen
sudo ufw allow proto tcp from 181.10.20.0/24 to any port 9500 comment 'registro camaras'
sudo ufw allow proto tcp from 200.45.1.7     to any port 9500 comment 'registro camaras'
# (o abierto a todos:  sudo ufw allow 9500/tcp)

# RTSP sólo para la red de los clientes (VMS, operadores)
sudo ufw allow proto tcp from 10.0.0.0/8 to any port 8554 comment 'RTSP clientes'
sudo ufw status numbered
```

En la nube, abrir los mismos puertos en el *security group*/NSG. Si el servidor está detrás de un router, redirigir 9500/TCP hacia él.

## 10. Servicios systemd

### 10.1 `zz-rtsp-gateway.service`

```ini
[Unit]
Description=ZZNetSDK - pasarela de registro activo a RTSP
Documentation=file:///opt/zz-rtsp-gateway/install.md
After=network-online.target mediamtx.service
Wants=network-online.target mediamtx.service

[Service]
Type=simple
User=zzgw
Group=zzgw
Environment=LD_LIBRARY_PATH=/opt/zznetsdk/lib_linux64
ExecStartPre=/usr/local/bin/zz-rtsp-gateway --env /etc/zz-rtsp-gateway/gateway.env --check-config
ExecStart=/usr/local/bin/zz-rtsp-gateway --env /etc/zz-rtsp-gateway/gateway.env
ExecReload=/bin/kill -HUP $MAINPID
Restart=on-failure
RestartSec=5
# Configuración inválida (código 78): no reintentar en bucle
RestartPreventExitStatus=78
TimeoutStopSec=20
KillMode=mixed
LimitNOFILE=65536
TasksMax=4096

# Directorio de trabajo (el SDK puede escribir archivos auxiliares)
StateDirectory=zz-rtsp-gateway
WorkingDirectory=/var/lib/zz-rtsp-gateway

# Endurecimiento
NoNewPrivileges=yes
PrivateTmp=yes
ProtectSystem=strict
ProtectHome=yes
ProtectKernelTunables=yes
ProtectKernelModules=yes
ProtectControlGroups=yes
RestrictAddressFamilies=AF_INET AF_INET6 AF_UNIX AF_NETLINK
RestrictNamespaces=yes
LockPersonality=yes
# Descomentar sólo si ZZGW_LISTEN_PORT < 1024
#AmbientCapabilities=CAP_NET_BIND_SERVICE

[Install]
WantedBy=multi-user.target
```

### 10.2 `mediamtx.service`

```ini
[Unit]
Description=MediaMTX - servidor RTSP
After=network-online.target
Wants=network-online.target

[Service]
Type=simple
User=mediamtx
Group=mediamtx
ExecStart=/usr/local/bin/mediamtx /etc/mediamtx/mediamtx.yml
Restart=always
RestartSec=3
LimitNOFILE=65536
NoNewPrivileges=yes
PrivateTmp=yes
ProtectSystem=strict
ProtectHome=yes

[Install]
WantedBy=multi-user.target
```

### 10.3 Habilitar y arrancar

```bash
sudo systemctl daemon-reload
sudo systemctl enable --now mediamtx
sudo systemctl enable --now zz-rtsp-gateway
systemctl status mediamtx zz-rtsp-gateway --no-pager
```

### 10.4 Operación diaria

| Acción | Comando |
|---|---|
| Ver logs en vivo | `journalctl -u zz-rtsp-gateway -f` |
| Logs de MediaMTX | `journalctl -u mediamtx -f` |
| Recargar cámaras, redes permitidas y nivel de log (sin cortar video) | `sudo systemctl reload zz-rtsp-gateway` |
| Aplicar cambios de puerto, URL RTSP, flujo, ffmpeg | `sudo systemctl restart zz-rtsp-gateway` |
| Detener | `sudo systemctl stop zz-rtsp-gateway` |
| Sólo errores y avisos | `journalctl -u zz-rtsp-gateway -p warning` |

Si una recarga tiene errores (por ejemplo, una línea mal formada en `cameras.conf`) **se descarta** y se mantiene la configuración anterior. El log muestra `recarga descartada: ...`.

Mensajes típicos del log:

```text
zz-rtsp-gateway 1.0.0 escuchando registro activo en 0.0.0.0:9500; RTSP en rtsp://127.0.0.1:8554; 3 cámaras configuradas
[CAM-SUC01-01] login OK desde 181.10.20.55:51234 SN=7K0XXXXXXXXXXXX canales=1
[CAM-SUC01-01] canal 1 (sub) -> rtsp://127.0.0.1:8554/CAM-SUC01-01
[estado] sesiones=1
[estado] CAM-SUC01-01: 512 kbit/s descartado=0 B reinicios_ffmpeg=0
[rechazo] 8.8.8.8:40000 fuera de ZZGW_ALLOWED_CIDRS (ID 'X')
[rechazo] ID desconocido 'CAM-NUEVA' desde 181.10.20.60:50111
[CAM-SUC01-01] sesión cerrada (el equipo cerró el registro)
configuración recargada: 4 cámaras, 3 redes permitidas
```

## 11. Verificación de punta a punta

1. **Puerto escuchando**

   ```bash
   sudo ss -ltnp | grep -E ':9500|:8554'
   ```

2. **Cámara configurada** (web de la cámara → Configuración → Red → Registro): habilitado, IP pública del servidor, puerto 9500, ID igual al de `cameras.conf`. Ver `Doc/09-registro-activo.md` §9.4.

3. **Registro y login**: en `journalctl -u zz-rtsp-gateway -f` debe aparecer `login OK` y `canal 1 ... -> rtsp://...`.

4. **RTSP**:

   ```bash
   ffprobe -rtsp_transport tcp rtsp://visor:CLAVE@servidor:8554/CAM-SUC01-01
   ffplay  -rtsp_transport tcp rtsp://visor:CLAVE@servidor:8554/CAM-SUC01-01
   ```

### Prueba sin cámara (modo simulación)

Publica un flujo DHAV por el mismo camino que usaría el SDK. Sirve para validar ffmpeg, MediaMTX, permisos y firewall antes de tener cámaras. El generador de prueba está en `tools/mkdav.py`.

```bash
ffmpeg -f lavfi -i testsrc=size=640x480:rate=25 -t 60 -c:v libx264 -g 25 -bf 0 \
       -pix_fmt yuv420p -bsf:v h264_metadata=aud=insert -f h264 test.h264
python3 tools/mkdav.py test.h264 rt | \
  zz-rtsp-gateway --env /etc/zz-rtsp-gateway/gateway.env --simulate - CAM-PRUEBA
# en otra terminal:
ffprobe -rtsp_transport tcp rtsp://visor:CLAVE@127.0.0.1:8554/CAM-PRUEBA
```

## 12. Pruebas realizadas (Ubuntu 24.04, sin cámara física)

| Prueba | Resultado |
|---|---|
| Compilación con `make` y con CMake (`-Wall -Wextra`) | Sin errores ni advertencias |
| `--check-config` con configuración válida | OK, claves ocultas |
| Errores de configuración (flujo inválido, CIDR `/33`, `.env` inexistente) | Código 78 con mensaje claro |
| `--test-ip` sobre `181.10.20.0/24, 200.45.1.7/32, 10.0.0.0/8` | 181.10.20.55 ✔, 181.10.21.1 ✘, 200.45.1.7 ✔, 200.45.1.8 ✘, 10.9.8.7 ✔, 8.8.8.8 ✘ |
| Servicio escuchando en `0.0.0.0:9500` | Verificado (`LISTEN`) |
| Segunda instancia en el mismo puerto | Falla con `ListenServer ... 0x90010010`, código de salida 1 |
| `SIGHUP` con cámara nueva / con línea inválida | Recarga aplicada / recarga descartada manteniendo la anterior |
| `SIGTERM` | Cierre ordenado (`deteniendo...` → `detenido`) |
| `--simulate` → MediaMTX → `ffprobe` | `h264, 640x480` |
| Reinicio de MediaMTX con flujo activo | ffmpeg relanzado a los 3 s y flujo disponible de nuevo |
| Lectura RTSP sin clave / con `visor` | `401 Unauthorized` / flujo OK |
| `systemd-analyze verify` de ambos units | Sin errores |

**Pendiente con equipo real:** registro, login y formato del callback (`dwDataType=0` = DHAV) con el firmware de las cámaras del proyecto.

## 13. Resolución de problemas

| Síntoma | Causa | Solución |
|---|---|---|
| El servicio no arranca, `status=78` | Configuración inválida | `sudo -u zzgw zz-rtsp-gateway --check-config` y corregir |
| `no se puede abrir /etc/zz-rtsp-gateway/gateway.env: Permission denied` | Permisos | `sudo chgrp -R zzgw /etc/zz-rtsp-gateway && sudo chmod 640 /etc/zz-rtsp-gateway/*` |
| `ListenServer 0.0.0.0:9500 falló 0x90010010` | Puerto en uso (otra instancia u otro programa) | `sudo ss -ltnp \| grep 9500` |
| `libgeneral_configsdk.so: cannot open shared object file` | Falta la ruta del SDK | `ldconfig` del punto 2; el unit ya define `LD_LIBRARY_PATH` |
| No aparece ningún registro en el log | La cámara no llega al servidor | Firewall/NSG/port-forward; desde el sitio: `nc -vz servidor 9500` |
| `[rechazo] ... fuera de ZZGW_ALLOWED_CIDRS` | IP pública del sitio no incluida | Agregarla y `systemctl reload` |
| `[rechazo] ID desconocido` | ID no está en `cameras.conf` o difiere en mayúsculas | Corregir y `systemctl reload` |
| `login falló ... err=1 0x80000064` | Clave incorrecta | Credenciales en `cameras.conf` |
| `ffmpeg terminó; reinicio en 3 s` repetido | MediaMTX caído o rechaza la publicación | `journalctl -u mediamtx`; revisar `authInternalUsers` (publicación desde 127.0.0.1) |
| RTSP `404 Not Found` | La cámara no está registrada o la ruta difiere | Ver en el log la ruta exacta publicada |
| RTSP `401 Unauthorized` | Falta usuario/clave | `rtsp://visor:CLAVE@...` |
| `descartado=` crece en `[estado]` | ffmpeg/MediaMTX no da abasto o el disco/CPU está saturado | Revisar CPU; aumentar `ZZGW_QUEUE_MAX_MB`; usar sub-flujo |
| Video tarda en aparecer | Detección del códec por ffmpeg | Reducir `-probesize`/`-analyzeduration` en `ZZGW_FFMPEG_INPUT_ARGS` (con cuidado) |

## 14. Actualizar y desinstalar

```bash
# Actualizar el binario (la configuración no se toca)
git pull && make && sudo make install && sudo systemctl restart zz-rtsp-gateway

# Desinstalar
sudo systemctl disable --now zz-rtsp-gateway
sudo make uninstall
# Opcional: sudo rm -r /etc/zz-rtsp-gateway ; sudo userdel zzgw
```

## 15. Seguridad

- `gateway.env`, `cameras.conf` y `mediamtx.yml` contienen claves: permisos 640 y grupo del servicio (el programa avisa si `cameras.conf` es legible por todos).
- Ambos servicios corren con usuarios sin privilegios, con `ProtectSystem=strict` y `NoNewPrivileges`.
- Restringir 9500/TCP a las IPs de los sitios (firewall + `ZZGW_ALLOWED_CIDRS`) y 8554/TCP a la red de clientes.
- ffmpeg se ejecuta **sin shell** (`posix_spawn`) y el ID recibido se valida, así que un ID malicioso no puede inyectar comandos.
- El tramo cámara → servidor usa el protocolo privado de Dahua. Por Internet, evaluar VPN (ver `Doc/09-registro-activo.md` §9.9).
