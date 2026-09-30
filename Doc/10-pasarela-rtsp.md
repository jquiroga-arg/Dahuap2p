# 10. Pasarela RTSP para cámaras con registro activo

[← Índice](README.md)

## 10.1 ¿Se crea un túnel local para conectarse por RTSP?

**No.** Cuando una cámara se auto-registra ([09](09-registro-activo.md)), la conexión que abre hacia el servidor transporta **sólo el protocolo privado de Dahua (DVRIP)**, y únicamente lo entiende el SDK. El SDK:

- **no** abre un puerto local que reenvíe hacia el puerto RTSP (554) de la cámara;
- **no** incluye un servidor RTSP;
- **no** expone funciones de *port mapping* o túnel. Se revisaron las 1.034 funciones `CLIENT_*` de `libgeneral_netsdk.so`: no existe ninguna de túnel/proxy RTSP (hay `CLIENT_PlayBackBy...Proxy` y `CLIENT_TransmitInfo...`, que son otra cosa).

Por lo tanto `rtsp://ip_camara:554/...` **no es alcanzable** a través del registro activo. Para obtener RTSP hay que construir una **pasarela**: la aplicación recibe el video por el SDK y lo re-publica en un servidor RTSP local. Es lo que hacen las plataformas VMS con esta tecnología.

## 10.2 Qué se puede hacer después del registro

Una vez que `OnService` informa el registro y se hace `LoginEx(..., nSpecCap=2, ID, ...)`, la sesión es **igual a la de una cámara local**. Todo pasa por la conexión que abrió la cámara:

| Necesidad | Funciones | Referencia |
|---|---|---|
| Video en vivo (crudo, formato DHAV) | `RealPlayEx` + `SetRealDataCallBack` | [05 §5.3](05-flujos-secuencia.md) |
| **Re-publicar como RTSP** | Pasarela de este documento | §10.3 |
| Grabaciones de la SD/NVR remota | `QueryRecordFile`, `PlayBackByTimeEx`, `DownloadByTimeEx` | [05 §5.4-5.5](05-flujos-secuencia.md) |
| Alarmas y eventos IVS con imagen | `StartListenEx`, `RealLoadPictureEx` | [05 §5.6-5.7](05-flujos-secuencia.md) |
| Capturas JPEG | `SnapPicture` | [05 §5.8](05-flujos-secuencia.md) |
| PTZ / enfoque | `ZZPTZControlEx`, `FocusControl` | [05 §5.9](05-flujos-secuencia.md) |
| Audio bidireccional | `StartTalkEx`, `TalkSendData` | [05 §5.15](05-flujos-secuencia.md) |
| Configuración, hora, reinicio, firmware | `Get/SetNewDevConfig`, `SetupDeviceTime`, `RebootDev`, `StartUpgradeEx` | [04](04-funcionalidades.md) |
| Estado y capacidades | `QueryDevState`, `GetDevCaps`, `QueryNewSystemInfo` | [04](04-funcionalidades.md) |

## 10.3 Arquitectura de la pasarela

```mermaid
flowchart LR
    subgraph Sitio["Sitio remoto (NAT)"]
        CAM["Cámara<br/>ID CAM-SUC01-01"]
    end
    subgraph SRV["Servidor Ubuntu 24.04"]
        direction LR
        SDK["ZZNetSDK<br/>ListenServer :9500<br/>LoginEx nSpecCap=2<br/>RealPlayEx sub-flujo"]
        GW["rtsp_gateway<br/>callback -> cola -> pipe"]
        FF["ffmpeg -f dhav<br/>remux sin recodificar<br/>-c copy"]
        MTX["MediaMTX<br/>servidor RTSP :8554"]
        SDK -->|"DHAV (dwDataType=0)"| GW
        GW -->|stdin| FF
        FF -->|"RTSP publish<br/>/CAM-SUC01-01"| MTX
    end
    CAM -->|"DVRIP por conexión saliente<br/>TCP 9500"| SDK
    VLC["VLC / ffplay / VMS / NVR tercero"] -->|"rtsp://servidor:8554/CAM-SUC01-01"| MTX
```

Componentes:

| Componente | Rol | Por qué |
|---|---|---|
| **ZZNetSDK** | Recibe el registro, hace login y entrega el flujo | Único componente que habla el protocolo de la cámara |
| **rtsp_gateway** (programa propio, §10.6) | Por cada cámara registrada abre el video y lo escribe en un `ffmpeg` | Desacopla el callback del SDK (no bloquear) del proceso de salida |
| **FFmpeg** (demuxer `dhav`) | Convierte el contenedor privado DHAV en RTP/RTSP **sin recodificar** (`-c copy`) | CPU mínima; FFmpeg 6.1 de Ubuntu 24.04 trae el demuxer `dhav` (verificado) |
| **MediaMTX** | Servidor RTSP (también RTMP, HLS, WebRTC, SRT) | Liviano, un binario, sin dependencias |

> No se usa `libplay.so` ni `CLIENT_RealPlayByDataType` (que entregaría otros contenedores) porque este último depende de `libStreamConvertor.so`, que no viene en el paquete ([08 §8.4](08-hallazgos-y-limitaciones.md)).

## 10.4 Secuencia

```mermaid
sequenceDiagram
    autonumber
    participant Cam as Cámara remota
    participant SDK as ZZNetSDK
    participant GW as rtsp_gateway
    participant FF as ffmpeg (dhav)
    participant MTX as MediaMTX :8554
    participant Cli as Cliente RTSP

    GW->>SDK: Init + ListenServer(0.0.0.0, 9500)
    Cam->>SDK: conexión saliente + registro (ID)
    SDK->>GW: OnService(ip, puerto, 1, ID) encolado
    GW->>SDK: LoginEx(ip, puerto, user, pass, 2, ID)
    GW->>FF: popen ffmpeg -f dhav -i pipe:0 -c copy -f rtsp .../ID
    GW->>SDK: RealPlayEx(login, 0, NULL, sub-flujo) + SetRealDataCallBack
    GW->>SDK: MakeKeyFrame
    loop mientras la cámara esté registrada
        Cam-->>SDK: video
        SDK->>GW: OnRealData(DHAV) copiar a cola
        GW->>FF: write(stdin)
        FF->>MTX: RTP sobre RTSP (ANNOUNCE/RECORD)
    end
    Cli->>MTX: DESCRIBE/SETUP/PLAY rtsp://servidor:8554/ID
    MTX-->>Cli: H.264/H.265 por RTP
    Cam--xSDK: se corta el enlace
    SDK->>GW: OnService(-1)
    GW->>SDK: StopRealPlay + Logout
    GW->>FF: cerrar stdin (ffmpeg termina)
    Note over MTX,Cli: la ruta deja de existir hasta el próximo registro
```

## 10.5 Instalación en el servidor

```bash
# FFmpeg (incluye el demuxer dhav)
sudo apt install -y ffmpeg
ffmpeg -hide_banner -demuxers | grep dhav     # debe mostrar:  D  dhav  Video DAV

# MediaMTX: descargar la última versión para linux_amd64 desde
# https://github.com/bluenviron/mediamtx/releases
tar xzf mediamtx_vX.Y.Z_linux_amd64.tar.gz
sudo install -m 755 mediamtx /usr/local/bin/
sudo install -m 644 mediamtx.yml /etc/mediamtx.yml
```

Configuración mínima recomendada de MediaMTX (`/etc/mediamtx.yml`, archivo completo mínimo): publicar únicamente desde localhost (la pasarela) y exigir usuario para leer.

```yaml
rtspAddress: :8554
authInternalUsers:
  - user: any              # sólo la pasarela local puede publicar
    ips: ['127.0.0.1/32']
    permissions:
      - action: publish
  - user: visor            # clientes RTSP
    pass: CambiarEstaClave
    permissions:
      - action: read
paths:
  all_others:              # acepta cualquier ruta (una por cámara)
```

> Probado con MediaMTX v1.9.3: sin credenciales el cliente recibe `401 Unauthorized`; con `visor:CambiarEstaClave` obtiene el flujo. La sintaxis de autenticación puede variar en otras versiones; verificar contra el `mediamtx.yml` de la versión instalada.

Firewall: además del 9500/TCP del registro, abrir **8554/TCP** sólo hacia las redes que consumirán RTSP (o no abrirlo y consumir localmente).

```bash
sudo ufw allow from 10.0.0.0/8 to any port 8554 proto tcp comment 'RTSP interno'
```

Servicios systemd:

```ini
# /etc/systemd/system/mediamtx.service
[Unit]
Description=MediaMTX (servidor RTSP)
After=network-online.target
[Service]
ExecStart=/usr/local/bin/mediamtx /etc/mediamtx.yml
Restart=always
[Install]
WantedBy=multi-user.target
```

```ini
# /etc/systemd/system/rtsp-gateway.service
[Unit]
Description=Pasarela registro activo -> RTSP (ZZNetSDK)
After=network-online.target mediamtx.service
Requires=mediamtx.service
[Service]
Environment=LD_LIBRARY_PATH=/opt/zznetsdk/lib_linux64
ExecStart=/usr/local/bin/rtsp_gateway 9500
Restart=on-failure
RestartSec=5
LimitNOFILE=65536
[Install]
WantedBy=multi-user.target
```

```bash
sudo systemctl daemon-reload
sudo systemctl enable --now mediamtx rtsp-gateway
```

## 10.6 Programa: `rtsp_gateway.cpp`

> **Versión de producción:** el servicio completo, configurable por `.env` (puerto, redes permitidas, credenciales por archivo, flujo, canales, rutas, ffmpeg), con units de systemd e instrucciones de instalación está en la carpeta [`rtsp_gateway/`](../rtsp_gateway/install.md) del repositorio. El programa de esta sección es la versión mínima, para entender el mecanismo.

Puntos de diseño:

- Los callbacks del SDK **sólo encolan**; el login y la apertura de video se hacen en el hilo principal.
- Cada cámara tiene su propio `Publisher`: una cola acotada (8 MB) y un hilo escritor hacia `ffmpeg`. Si `ffmpeg` se atrasa, se descartan datos en lugar de bloquear el hilo del SDK.
- Se ignora `SIGPIPE` para que la caída de un `ffmpeg` no termine el proceso.
- Modo `--simular` para probar toda la cadena de salida **sin cámara**.

```cpp
// Pasarela Registro activo -> RTSP
// Cada cámara que se auto-registra se publica como rtsp://<servidor>:8554/<ID>
// Cadena: cámara --(DVRIP, conexión saliente)--> ZZNetSDK --(DHAV por callback)-->
//         ffmpeg -f dhav (remux sin recodificar) --> MediaMTX (servidor RTSP) --> clientes RTSP
#include <atomic>
#include <condition_variable>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>
#include <unistd.h>
#include "ZZNetSDK.h"

// ---------- Configuración ----------
static const char* kRtspBase = "rtsp://127.0.0.1:8554";          // MediaMTX local
static const std::map<std::string, std::pair<std::string, std::string>> kCams = {
    {"CAM-SUC01-01", {"admin", "ClaveCam01!"}},
    {"CAM-SUC02-01", {"admin", "ClaveCam02!"}},
};
static const ZZ_RealPlayType kStream = ZZ_RType_Realplay_1;         // sub-flujo (menos ancho de banda)
static const size_t kMaxQueueBytes = 8 * 1024 * 1024;               // descarta si ffmpeg no da abasto

// ---------- Publicador: cola + hilo escritor hacia ffmpeg ----------
class Publisher {
public:
    explicit Publisher(const std::string& id) : id_(id) {
        std::string cmd = "ffmpeg -hide_banner -loglevel warning -fflags +genpts "
                          "-probesize 1000000 -analyzeduration 1000000 "
                          "-f dhav -i pipe:0 -c copy -f rtsp -rtsp_transport tcp " +
                          std::string(kRtspBase) + "/" + id;
        pipe_ = popen(cmd.c_str(), "w");
        if (pipe_) th_ = std::thread([this] { run(); });
    }
    ~Publisher() {
        { std::lock_guard<std::mutex> lk(m_); stop_ = true; }
        cv_.notify_all();
        if (th_.joinable()) th_.join();
        if (pipe_) pclose(pipe_);
    }
    bool ok() const { return pipe_ != nullptr; }
    // Llamado desde el callback del SDK: sólo copia y encola (no bloquea)
    void push(const BYTE* p, DWORD n) {
        std::lock_guard<std::mutex> lk(m_);
        if (bytes_ + n > kMaxQueueBytes) { dropped_++; return; }
        q_.emplace_back(p, p + n);
        bytes_ += n;
        cv_.notify_one();
    }
private:
    void run() {
        for (;;) {
            std::vector<BYTE> b;
            {
                std::unique_lock<std::mutex> lk(m_);
                cv_.wait(lk, [this] { return stop_ || !q_.empty(); });
                if (stop_ && q_.empty()) return;
                b.swap(q_.front()); q_.pop_front(); bytes_ -= b.size();
            }
            if (fwrite(b.data(), 1, b.size(), pipe_) != b.size()) {
                fprintf(stderr, "[%s] ffmpeg terminó\n", id_.c_str()); return;
            }
            fflush(pipe_);
        }
    }
    std::string id_;
    FILE* pipe_ = nullptr;
    std::thread th_;
    std::mutex m_;
    std::condition_variable cv_;
    std::deque<std::vector<BYTE>> q_;
    size_t bytes_ = 0;
    unsigned long dropped_ = 0;
    bool stop_ = false;
};

// ---------- Estado ----------
struct Sesion { LLONG login = 0; LLONG real = 0; std::unique_ptr<Publisher> pub; };
struct Evento { std::string ip; WORD port; std::string id; bool alta; };

static std::mutex g_mx;
static std::queue<Evento> g_eventos;
static std::map<std::string, Sesion> g_ses;          // ID -> sesión
static std::map<std::string, std::string> g_origen;  // "ip:puerto" -> ID
static std::atomic<bool> g_run{true};

// ---------- Callbacks (hilos del SDK): sólo encolan ----------
static int CALLBACK OnService(LLONG, char* ip, WORD port, LONG cmd, void* param, DWORD len, LDWORD) {
    Evento e{ip ? ip : "", port, "", cmd == ZZ_DVR_SERIAL_RETURN};
    if (cmd == ZZ_DVR_SERIAL_RETURN && param)
        e.id.assign(static_cast<char*>(param), strnlen(static_cast<char*>(param), len));
    else if (cmd != ZZ_DVR_DISCONNECT) return 0;
    std::lock_guard<std::mutex> lk(g_mx);
    g_eventos.push(e);
    return 0;
}

static void CALLBACK OnRealData(LLONG, DWORD type, BYTE* buf, DWORD len, LDWORD user) {
    if (type != 0 || !buf || !len) return;          // 0 = flujo original (DHAV)
    reinterpret_cast<Publisher*>(user)->push(buf, len);
}

static void CALLBACK OnDisconnect(LLONG login, char* ip, LONG port, LDWORD) {
    fprintf(stderr, "[desconexión] %s:%d\n", ip, port);
}

// ---------- Lógica (hilo principal) ----------
static void cerrar(const std::string& id) {
    auto it = g_ses.find(id);
    if (it == g_ses.end()) return;
    if (it->second.real)  ZZNETSDK_StopRealPlay(it->second.real);
    if (it->second.login) ZZNETSDK_Logout(it->second.login);
    g_ses.erase(it);                                  // destruye Publisher -> cierra ffmpeg
    printf("[%s] sesión cerrada\n", id.c_str());
}

static void alta(const Evento& e) {
    auto cred = kCams.find(e.id);
    if (cred == kCams.end()) { printf("[rechazo] ID '%s' desde %s\n", e.id.c_str(), e.ip.c_str()); return; }
    cerrar(e.id);                                     // re-registro

    ZZNET_DEVICEINFO info{}; int err = 0;
    std::string id = e.id;
    LLONG login = ZZNETSDK_LoginEx(e.ip.c_str(), e.port, cred->second.first.c_str(),
                                   cred->second.second.c_str(), EM_ZZ_LOGIN_SPEC_CAP_SERVER_CONN,
                                   (void*)id.c_str(), &info, &err);
    if (!login) { printf("[%s] login falló err=%d 0x%08X\n", id.c_str(), err, ZZNETSDK_GetLastError()); return; }

    Sesion s; s.login = login;
    s.pub.reset(new Publisher(id));
    if (!s.pub->ok()) { printf("[%s] no se pudo lanzar ffmpeg\n", id.c_str()); ZZNETSDK_Logout(login); return; }

    s.real = ZZNETSDK_RealPlayEx(login, 0 /*canal*/, NULL, kStream);
    if (!s.real) { printf("[%s] RealPlayEx 0x%08X\n", id.c_str(), ZZNETSDK_GetLastError()); ZZNETSDK_Logout(login); return; }
    ZZNETSDK_SetRealDataCallBack(s.real, OnRealData, (LDWORD)s.pub.get());
    ZZNETSDK_MakeKeyFrame(login, 0, 1);

    g_origen[e.ip + ":" + std::to_string(e.port)] = id;
    g_ses[id] = std::move(s);
    printf("[%s] publicado en %s/%s\n", id.c_str(), kRtspBase, id.c_str());
}

static void baja(const Evento& e) {
    auto it = g_origen.find(e.ip + ":" + std::to_string(e.port));
    if (it == g_origen.end()) return;
    cerrar(it->second);
    g_origen.erase(it);
}

// Modo simulación: publica un flujo .dav (archivo o "-" = stdin, a ritmo real) como si
// viniera de una cámara, por el mismo camino que el callback del SDK (prueba sin equipo)
static int simular(const char* archivo, const char* id) {
    FILE* f = strcmp(archivo, "-") ? fopen(archivo, "rb") : stdin;   // "-" = stdin
    if (!f) { perror(archivo); return 1; }
    Publisher pub(id);
    printf("[sim] publicando %s en %s/%s\n", archivo, kRtspBase, id);
    std::vector<BYTE> buf(4096);
    size_t n;
    while (g_run && (n = fread(buf.data(), 1, buf.size(), f)) > 0) {
        OnRealData(0, 0, buf.data(), (DWORD)n, (LDWORD)&pub);   // mismo camino que el SDK
    }
    if (f != stdin) fclose(f);
    return 0;
}

int main(int argc, char** argv) {
    signal(SIGPIPE, SIG_IGN);
    signal(SIGINT,  [](int) { g_run = false; });
    signal(SIGTERM, [](int) { g_run = false; });
    if (argc == 4 && !strcmp(argv[1], "--simular")) return simular(argv[2], argv[3]);

    WORD puerto = argc > 1 ? (WORD)atoi(argv[1]) : 9500;
    ZZNETSDK_Init(OnDisconnect, 0);
    char ip[] = "0.0.0.0";
    LLONG srv = ZZNETSDK_ListenServer(ip, puerto, 0, OnService, 0);
    if (!srv) { printf("ListenServer 0x%08X\n", ZZNETSDK_GetLastError()); return 1; }
    printf("Registro activo en TCP %u; RTSP en %s/<ID>\n", puerto, kRtspBase);

    while (g_run) {
        std::queue<Evento> q;
        { std::lock_guard<std::mutex> lk(g_mx); std::swap(q, g_eventos); }
        for (; !q.empty(); q.pop()) q.front().alta ? alta(q.front()) : baja(q.front());
        usleep(200 * 1000);
    }
    while (!g_ses.empty()) cerrar(g_ses.begin()->first);
    ZZNETSDK_StopListenServer(srv);
    ZZNETSDK_Cleanup();
    return 0;
}
```

Compilación:

```bash
g++ -std=c++17 -Wall -O2 rtsp_gateway.cpp -I/opt/zznetsdk/include \
    -L/opt/zznetsdk/lib_linux64 -lZZNetSDK -lgeneral_netsdk -lgeneral_configsdk \
    -lssl -lcrypto -lpsl -lpthread -o rtsp_gateway
sudo install -m 755 rtsp_gateway /usr/local/bin/
```

## 10.7 Consumir el RTSP

```bash
ffplay -rtsp_transport tcp rtsp://visor:CambiarEstaClave@servidor:8554/CAM-SUC01-01
vlc rtsp://visor:CambiarEstaClave@servidor:8554/CAM-SUC01-01
# Grabar 60 s sin recodificar
ffmpeg -rtsp_transport tcp -i rtsp://visor:CambiarEstaClave@servidor:8554/CAM-SUC01-01 -t 60 -c copy clip.mp4
```

La URL se puede cargar como cámara "RTSP genérica" en VMS o NVR de terceros.

## 10.8 Validación realizada

Sin cámara física, se validó la cadena **de salida completa** en Ubuntu 24.04:

1. Se generó H.264 de prueba y se lo empaquetó en **DHAV** con el script `mkdav.py` (cabecera `DHAV` + extensiones de resolución/códec + carga útil + cola `dhav`, según el demuxer de FFmpeg).
2. `ffprobe -f dhav` reconoció el flujo: `Video: h264 (High), yuv420p, 640x480, 25 fps`.
3. `rtsp_gateway --simular - CAM-SIM-01` recibió el flujo por el **mismo camino que el callback del SDK** (`OnRealData` → cola → `ffmpeg`) y lo publicó en MediaMTX.
4. `ffprobe rtsp://127.0.0.1:8554/CAM-SIM-01` → `Video: h264 (High), 640x480, 25 fps`. Se extrajo un cuadro JPEG y se grabó un clip MP4.
5. Con la configuración de §10.5: lectura sin clave → `401 Unauthorized`; con `visor` → `h264,640,480`.

```bash
python3 mkdav.py test.h264 rt | ./rtsp_gateway --simular - CAM-SIM-01
ffprobe -rtsp_transport tcp rtsp://127.0.0.1:8554/CAM-SIM-01
```

`mkdav.py` (generador DHAV de prueba):

```python
# Genera un flujo DHAV sintético (formato privado Dahua) a partir de H.264 Annex B,
# para probar la cadena: callback SDK -> ffmpeg -f dhav -> RTSP.
import struct, sys, time
data = open(sys.argv[1], 'rb').read()
aud = b'\x00\x00\x00\x01\x09'
parts = [p for p in data.split(aud) if p]
out = sys.stdout.buffer
fps = 25
for n, p in enumerate(parts):
    au = aud + p
    # tipo: 0xFD si contiene IDR (nal type 5) o SPS (7), si no 0xFC
    i = au.find(b'\x00\x00\x01')
    key = False
    while i != -1:
        t = au[i+3] & 0x1f
        if t in (5, 7): key = True; break
        i = au.find(b'\x00\x00\x01', i+3)
    ext = bytes([0x80, 0, 640//8, 480//8, 0x81, 0, 0x08, fps])
    flen = 24 + len(ext) + len(au) + 8
    ts = (n * 1000 // fps) & 0xffff
    lt = time.localtime()
    date = (lt.tm_sec | lt.tm_min<<6 | lt.tm_hour<<12 | lt.tm_mday<<17 | lt.tm_mon<<22 | (lt.tm_year-2000)<<26)
    hdr = b'DHAV' + bytes([0xFD if key else 0xFC, 0, 0, 0]) + struct.pack('<IIIHBB', n, flen, date, ts, len(ext), 0)
    out.write(hdr + ext + au + b'dhav' + struct.pack('<I', flen))
    out.flush()
    if len(sys.argv) > 2: time.sleep(1/fps)   # tiempo real
```

Para generar `test.h264`:

```bash
ffmpeg -f lavfi -i testsrc=size=640x480:rate=25 -t 20 -c:v libx264 -g 25 -bf 0 \
       -pix_fmt yuv420p -bsf:v h264_metadata=aud=insert -f h264 test.h264
```

**Pendiente de validar con equipo real:** que el callback con `dwDataType = 0` entregue exactamente DHAV en el firmware de las cámaras del proyecto *(es el formato conocido del flujo original de Dahua; inferido)*. Prueba rápida: guardar el callback en un archivo con [07 §7.2](07-ejemplos.md) y ejecutar `ffprobe -f dhav canal.dav`.

## 10.9 Variantes y extensiones

| Necesidad | Cómo |
|---|---|
| **NVR** con varias cámaras | Un `RealPlayEx` por canal y rutas `/<ID>/ch1`, `/<ID>/ch2`... (un `Publisher` por canal) |
| Flujo principal además del sub-flujo | Segundo `RealPlayEx` con `ZZ_RType_Realplay_0` y ruta `/<ID>/main` |
| **Bajo demanda** (ahorrar ancho de banda) | Abrir `RealPlayEx` sólo cuando haya lectores: usar `runOnDemand` de MediaMTX o su API HTTP para avisar a la pasarela |
| Latencia menor | `SetRealplayBufferPolicy(..., nPolicy=2)`; reducir `-probesize`/`-analyzeduration` (con riesgo de no detectar el códec) |
| HLS / WebRTC para navegador | MediaMTX publica la misma ruta por HLS (`:8888`) y WebRTC (`:8889`) sin cambios en la pasarela |
| Reproducción de grabaciones por RTSP | Mismo patrón con `PlayBackByTimeEx` y su `cbData` (formato DHAV) hacia otra ruta |
| Audio | Si la cámara envía G.711, `ffmpeg -c copy` lo publica como PCMA/PCMU; verificar con `ffprobe` |

## 10.10 Alternativas sin pasarela

| Opción | Cómo funciona | Pros / contras |
|---|---|---|
| **VPN** (WireGuard/IPsec) entre sitio y servidor | La cámara queda accesible por IP privada; RTSP nativo `rtsp://ip:554/cam/realmonitor?channel=1&subtype=1` | RTSP nativo y cifrado. Requiere un router/equipo en el sitio que haga de cliente VPN |
| **Empuje RTMP desde la cámara** | Algunos firmwares Dahua permiten enviar el video por RTMP a un servidor (MediaMTX lo recibe y lo sirve como RTSP) | Sin SDK ni puertos abiertos en el sitio. Depende del modelo/firmware *(verificar en la web de la cámara si existe la opción RTMP)* y sin control PTZ/eventos |
| **Túnel P2P** | Componente externo que mapea el equipo a un puerto local | No incluido en este SDK ([08 §8.8](08-hallazgos-y-limitaciones.md)) |

## 10.11 Consideraciones

- **CPU:** el remux (`-c copy`) consume muy poco. Recodificar (por ejemplo para bajar el bitrate) multiplica el consumo; evitarlo o usar aceleración por hardware.
- **Ancho de banda:** cada ruta RTSP abierta de forma permanente consume la subida del sitio aunque nadie mire. Para muchas cámaras, preferir el modo bajo demanda.
- **Seguridad:** proteger el RTSP con usuario y clave (MediaMTX) y no exponer 8554 a Internet sin necesidad; el tramo cámara → servidor sigue el protocolo privado ([09 §9.9](09-registro-activo.md)).
- **Reconexión:** si la cámara se vuelve a registrar, la pasarela cierra la sesión anterior y vuelve a publicar la misma ruta; los clientes RTSP deben reintentar.
