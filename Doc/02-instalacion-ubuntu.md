# 2. Instalación en Ubuntu Linux

[← Índice](README.md)

Procedimiento **validado en Ubuntu 24.04.4 LTS (glibc 2.39, GCC 13)**. Todos los comandos se ejecutaron y sus salidas reales se muestran debajo.

## 2.1 Verificar la versión del sistema

```bash
lsb_release -ds          # debe ser Ubuntu 24.04 o superior
ldd --version | head -1  # glibc >= 2.38
uname -m                 # x86_64
```

Si `ldd` muestra 2.35 (Ubuntu 22.04) el SDK **no cargará**. Ver [§2.9](#29-alternativa-contenedor-docker-para-hosts-con-ubuntu-2204).

## 2.2 Instalar dependencias del sistema

```bash
sudo apt update
# Obligatorias (desarrollo + runtime)
sudo apt install -y build-essential libssl-dev libpsl-dev
# Opcionales: sólo si se usará libplay.so (decodificación/render/audio local)
sudo apt install -y libx11-6 libxv1 libgl1 libasound2t64
# Opcionales: decodificación por hardware
sudo apt install -y libva2 libva-x11-2 libva-glx2 libvdpau1 vainfo
```

## 2.3 Copiar el SDK a una ubicación del sistema

Se recomienda `/opt/zznetsdk`, respetando la estructura original:

```bash
SDK_SRC="/ruta/a/ZZNetSDK_Linux64_GCC13.3.0_V3.0.7.6.R.2026-02-06"
sudo mkdir -p /opt/zznetsdk
sudo cp -r "$SDK_SRC/include" "$SDK_SRC/lib_linux64" /opt/zznetsdk/
sudo chmod 755 /opt/zznetsdk/lib_linux64/*.so*
```

Estructura resultante:

```text
/opt/zznetsdk/
├── include/
│   ├── ZZNetSDK.h        # 122 funciones públicas
│   ├── ZZGlobal.h        # tipos, estructuras, enumeraciones, errores (11.851 líneas)
│   └── ZZConfig.h        # comandos/estructuras de configuración JSON (2.095 líneas)
└── lib_linux64/
    ├── libZZNetSDK.so            # fachada ZZ (la que enlaza la aplicación)
    ├── libgeneral_netsdk.so      # Dahua NetSDK (núcleo)
    ├── libgeneral_configsdk.so   # Dahua ConfigSDK (parseo JSON <-> estructuras)
    ├── libgeneral_avnetsdk.so    # Dahua AVNetSDK (carga dinámica)
    ├── libInfra.so, libNetFramework.so, libStream.so, libStreamSvr.so
    ├── libplay.so, libRenderEngine.so, libHWDec.so, libIvsDrawer.so, libPlayDiag.so, libsvac3dec.so
    ├── libcurl.so, libcurl.so.4
    ├── PlayConfig.ini, audio_aec_ans_16k.cfg, JudgeHW.sh
    └── Open_Source_Software_Licenses.txt
```

## 2.4 Crear los enlaces simbólicos de compatibilidad

`libgeneral_netsdk.so` intenta cargar con `dlopen()` los nombres **originales** de Dahua, que no existen en el paquete. Se verificó con `LD_DEBUG=files` que, sin estos enlaces, la carga falla silenciosamente:

```bash
cd /opt/zznetsdk/lib_linux64
sudo ln -sf libgeneral_avnetsdk.so  libavnetsdk.so
sudo ln -sf libgeneral_configsdk.so libdhconfigsdk.so
```

> **No ejecute `JudgeHW.sh`**: el script intenta enlazar `libHWDec.so.VA1`/`libHWDec.so.VA2`, archivos que no vienen en el paquete, y busca en `/usr/lib` con `find` (lento). La `libHWDec.so` incluida ya es utilizable.

## 2.5 Registrar la ruta de bibliotecas

`libZZNetSDK.so` trae un `RUNPATH` de la máquina del fabricante (`/mnt/f/Work/ZenoSDK/Trunk/DNetSDK/Depends/linux/x64/dahua/lib`). Como tiene `RUNPATH`, **el `rpath` del ejecutable no se aplica a sus dependencias** (comportamiento estándar del cargador), así que `-Wl,-rpath` no alcanza. Opciones:

**Opción A (recomendada): ldconfig**

```bash
echo /opt/zznetsdk/lib_linux64 | sudo tee /etc/ld.so.conf.d/zznetsdk.conf
sudo ldconfig
ldconfig -p | grep -E "ZZNet|general"
```

Salida esperada:

```text
libgeneral_netsdk.so (libc6,x86-64) => /opt/zznetsdk/lib_linux64/libgeneral_netsdk.so
libgeneral_configsdk.so (libc6,x86-64) => /opt/zznetsdk/lib_linux64/libgeneral_configsdk.so
libgeneral_avnetsdk.so (libc6,x86-64) => /opt/zznetsdk/lib_linux64/libgeneral_avnetsdk.so
libZZNetSDK.so (libc6,x86-64) => /opt/zznetsdk/lib_linux64/libZZNetSDK.so
```

**Opción B: variable de entorno** (útil en desarrollo o si no hay permisos de root). Además hace que `dlopen("libcurl.so")` encuentre la copia del paquete:

```bash
export LD_LIBRARY_PATH=/opt/zznetsdk/lib_linux64:$LD_LIBRARY_PATH
```

> Se recomienda **usar ambas** en producción (ldconfig + `LD_LIBRARY_PATH` en el unit de systemd), porque el NetSDK hace `dlopen("libcurl.so")` y la caché de ldconfig sólo registra `libcurl.so.4`.

## 2.6 Verificar la resolución de dependencias

```bash
cd /opt/zznetsdk/lib_linux64
LD_LIBRARY_PATH=. ldd libZZNetSDK.so
```

```text
libgeneral_configsdk.so => ./libgeneral_configsdk.so
libgeneral_netsdk.so => ./libgeneral_netsdk.so
libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6
libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1
libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6
libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6
```

`ldd -r` mostrará ~231 símbolos indefinidos (`SSL_*`, `X509_*`, `EVP_*`, `psl_*`, ...). **Es esperado**: se resuelven al enlazar la aplicación con `-lssl -lcrypto -lpsl`.

## 2.7 Compilar y ejecutar el primer programa

`demo.cpp` (ver [07-ejemplos.md](07-ejemplos.md#71-demo-mínima-init--login--logout)):

```bash
g++ -std=c++17 demo.cpp \
    -I/opt/zznetsdk/include \
    -L/opt/zznetsdk/lib_linux64 \
    -lZZNetSDK -lgeneral_netsdk -lgeneral_configsdk \
    -lssl -lcrypto -lpsl -lpthread \
    -o demo

./demo 192.168.1.108 37777 admin 'MiClave123'
```

Salida real contra una IP sin equipo (valida que el SDK carga e inicializa):

```text
ZZNetSDK versión: 1.1.1.3
Login falló: err=3 lastError=0x80000066     # 0x80000066 = ZZNET_LOGIN_ERROR_TIMEOUT (~5 s)
```

Notas de compilación:

- **Compilar como C++** (`g++`). `ZZGlobal.h` incluye `<cstdint>` y `ZZNetSDK.h` usa argumentos por defecto; con `gcc` en modo C no compila.
- Ubuntu enlaza con `--as-needed`: `-lgeneral_netsdk` y `-lcrypto` pueden quedar fuera del ejecutable, pero se cargan igualmente de forma transitiva. `-lssl -lpsl` **sí** deben quedar (proveen los símbolos que usa `libZZNetSDK.so`).
- Si se usa la API `PLAY_*` de `libplay.so`, agregar `-lplay` (no se incluye cabecera; ver [08](08-hallazgos-y-limitaciones.md)).

## 2.8 Ejecutar como servicio (systemd)

`/etc/systemd/system/mi-app-nvr.service`:

```ini
[Unit]
Description=Aplicación de videovigilancia basada en ZZNetSDK
After=network-online.target
Wants=network-online.target

[Service]
Type=simple
User=nvr
WorkingDirectory=/var/lib/mi-app-nvr
Environment=LD_LIBRARY_PATH=/opt/zznetsdk/lib_linux64
ExecStart=/usr/local/bin/mi-app-nvr
Restart=on-failure
RestartSec=5
# El SDK crea muchos hilos y sockets
LimitNOFILE=65536
TasksMax=4096

[Install]
WantedBy=multi-user.target
```

```bash
sudo systemctl daemon-reload
sudo systemctl enable --now mi-app-nvr
journalctl -u mi-app-nvr -f
```

`PlayConfig.ini` y `audio_aec_ans_16k.cfg` son leídos por `libplay.so` *(inferido: típicamente desde el directorio de trabajo o el de la biblioteca)*; si se usa `libplay.so`, copie ambos al `WorkingDirectory`.

## 2.9 Alternativa: contenedor Docker para hosts con Ubuntu 22.04

*(No validado en este análisis; se deja como receta.)*

```dockerfile
FROM ubuntu:24.04
RUN apt-get update && apt-get install -y --no-install-recommends \
      libssl3t64 libpsl5t64 libstdc++6 ca-certificates && rm -rf /var/lib/apt/lists/*
COPY lib_linux64/ /opt/zznetsdk/lib_linux64/
RUN cd /opt/zznetsdk/lib_linux64 && \
    ln -sf libgeneral_avnetsdk.so libavnetsdk.so && \
    ln -sf libgeneral_configsdk.so libdhconfigsdk.so && \
    echo /opt/zznetsdk/lib_linux64 > /etc/ld.so.conf.d/zznetsdk.conf && ldconfig
ENV LD_LIBRARY_PATH=/opt/zznetsdk/lib_linux64
COPY mi-app-nvr /usr/local/bin/
# network_mode host recomendado para búsqueda LAN y registro activo
CMD ["/usr/local/bin/mi-app-nvr"]
```

```bash
docker run --rm --network host mi-app-nvr:latest
```

## 2.10 Resolución de problemas

| Síntoma | Causa | Solución |
|---|---|---|
| `version 'GLIBC_2.38' not found` | Distribución anterior a Ubuntu 24.04 | Actualizar a 24.04 o usar contenedor ([§2.9](#29-alternativa-contenedor-docker-para-hosts-con-ubuntu-2204)) |
| `version 'GLIBCXX_3.4.32' not found` | libstdc++ antigua | Ídem |
| `error while loading shared libraries: libgeneral_configsdk.so: cannot open shared object file` | `RUNPATH` de `libZZNetSDK.so` apunta a una ruta inexistente; el `rpath` del ejecutable no aplica | [§2.5](#25-registrar-la-ruta-de-bibliotecas) (ldconfig o `LD_LIBRARY_PATH`) |
| `undefined symbol: SSL_...` / `psl_...` al ejecutar | No se enlazó OpenSSL/libpsl | Agregar `-lssl -lcrypto -lpsl` |
| `/usr/bin/ld: cannot find -lpsl` | Falta el paquete de desarrollo | `sudo apt install libpsl-dev` |
| `LD_DEBUG=files` muestra `libavnetsdk.so ... error: symbol lookup error: undefined symbol: ...NetFramework...` | `libgeneral_avnetsdk.so` depende de `libInfra/libNetFramework/libStream/libStreamSvr` y de símbolos no incluidos | Ver [08 §8.4](08-hallazgos-y-limitaciones.md). El NetSDK sigue funcionando por la vía principal |
| Login devuelve `0x80000066` tras ~5 s | Equipo inalcanzable / puerto 37777 filtrado | Verificar `nc -vz IP 37777` |
| Login devuelve `0x80000064` / `err=1` | Contraseña incorrecta | Revisar `ZZNET_DEVICEINFO.byLeftLogTimes` (intentos restantes) |
| `ExportConfig` devuelve `FALSE` con credenciales correctas | El equipo sólo acepta Digest en CGI, o HTTP/80 deshabilitado | Habilitar HTTP y autenticación Basic en el equipo, o usar `GetNewDevConfig` (protocolo 37777) |
| `ZZNETSDK_StartSearchDevices` no encuentra nada | Distinto segmento/VLAN, firewall, contenedor sin `--network host` | Mismo segmento L2, abrir UDP 5050/37810, o usar `SearchDevicesByIPs` |

Para diagnosticar cargas dinámicas:

```bash
LD_DEBUG=files ./mi-app 2>&1 | grep -E "dynamically loaded|error"
```
