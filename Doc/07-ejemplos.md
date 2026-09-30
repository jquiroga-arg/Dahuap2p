# 7. Ejemplos de código

[← Índice](README.md)

Todos los ejemplos **compilan sin advertencias** (`g++ 13.3 -std=c++17 -Wall`) en Ubuntu 24.04 contra el SDK instalado en `/opt/zznetsdk` según [02-instalacion-ubuntu.md](02-instalacion-ubuntu.md). Estado de validación:

| Ejemplo | Qué muestra | Validación |
|---|---|---|
| `demo.cpp` | Init → Login → Logout → Cleanup | **Ejecutado** (login contra host sin equipo → `0x80000066`) |
| `search.cpp` | Búsqueda de equipos en la LAN | **Ejecutado** (handle válido, carga dinámica verificada) |
| `cfgtest.cpp` | `ExportConfig` / `ImportConfig` | **Ejecutado** contra el emulador `fakecam.py` |
| `live_to_file.cpp` | Video en vivo por callback a archivo `.dav` | Compilado (requiere equipo real) |
| `alarms.cpp` | Alarmas + eventos IVS con imagen | Compilado (requiere equipo real) |
| `records.cpp` | Búsqueda y descarga de grabaciones | Compilado (requiere equipo real) |

## 7.1 Demo mínima: Init → Login → Logout

```cpp
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include "ZZNetSDK.h"

static void CALLBACK OnDisconnect(LLONG lLoginID, char *ip, LONG port, LDWORD) {
    printf("[cb] Desconectado de %s:%d (login=%ld)\n", ip, port, lLoginID);
}

int main(int argc, char **argv) {
    const char *ip   = argc > 1 ? argv[1] : "127.0.0.1";
    int port         = argc > 2 ? atoi(argv[2]) : 37777;
    const char *user = argc > 3 ? argv[3] : "admin";
    const char *pass = argc > 4 ? argv[4] : "admin123";

    if (!ZZNETSDK_Init(OnDisconnect, 0)) { printf("Init falló: 0x%x\n", ZZNETSDK_GetLastError()); return 1; }
    printf("ZZNetSDK versión: %s\n", ZZNETSDK_GetVersion());

    ZZNET_DEVICEINFO info; memset(&info, 0, sizeof(info));
    int err = 0;
    LLONG h = ZZNETSDK_LoginEx(ip, (WORD)port, user, pass, 0, NULL, &info, &err);
    if (h == 0) {
        printf("Login falló: err=%d lastError=0x%08x\n", err, ZZNETSDK_GetLastError());
    } else {
        printf("Login OK handle=%ld SN=%s canales=%d\n", h, info.sSerialNumber, info.byChanNum);
        ZZNETSDK_Logout(h);
    }
    ZZNETSDK_Cleanup();
    return 0;
}
```

Salida real:

```text
$ ./demo 127.0.0.1 37777
ZZNetSDK versión: 1.1.1.3
Login falló: err=3 lastError=0x80000066
```

## 7.2 Video en vivo a archivo (servidor sin pantalla)

```cpp
// Guarda el flujo en vivo de un canal en un archivo .dav durante N segundos.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <unistd.h>
#include "ZZNetSDK.h"

struct Ctx { FILE* f; std::mutex m; unsigned long bytes = 0; };

static void CALLBACK OnDisconnect(LLONG id, char* ip, LONG port, LDWORD) {
    fprintf(stderr, "Desconectado %s:%d\n", ip, port);
}

static void CALLBACK OnRealData(LLONG h, DWORD type, BYTE* buf, DWORD len, LDWORD user) {
    Ctx* c = reinterpret_cast<Ctx*>(user);
    if (type != 0) return;                       // 0 = flujo original del equipo
    std::lock_guard<std::mutex> lk(c->m);        // callback en hilo del SDK
    fwrite(buf, 1, len, c->f);                   // copiar/escribir: buf sólo es válido aquí
    c->bytes += len;
}

int main(int argc, char** argv) {
    if (argc < 5) { printf("uso: %s ip usuario clave canal [segundos]\n", argv[0]); return 1; }
    int canal = atoi(argv[4]), secs = argc > 5 ? atoi(argv[5]) : 10;

    ZZNETSDK_Init(OnDisconnect, 0);
    ZZNET_DEVICEINFO info{}; int err = 0;
    LLONG login = ZZNETSDK_LoginEx(argv[1], 37777, argv[2], argv[3], 0, NULL, &info, &err);
    if (!login) { printf("login 0x%08X\n", ZZNETSDK_GetLastError()); ZZNETSDK_Cleanup(); return 2; }

    Ctx ctx; ctx.f = fopen("canal.dav", "wb");
    LLONG rp = ZZNETSDK_RealPlayEx(login, canal, NULL, ZZ_RType_Realplay_1); // sub-flujo 1
    if (!rp) { printf("RealPlayEx 0x%08X\n", ZZNETSDK_GetLastError()); }
    else {
        ZZNETSDK_SetRealDataCallBack(rp, OnRealData, (LDWORD)&ctx);
        ZZNETSDK_MakeKeyFrame(login, canal, 1);
        sleep(secs);
        ZZNETSDK_StopRealPlay(rp);
        printf("Recibidos %lu bytes en canal.dav\n", ctx.bytes);
    }
    fclose(ctx.f);
    ZZNETSDK_Logout(login);
    ZZNETSDK_Cleanup();
    return 0;
}
```

El archivo `canal.dav` puede reproducirse con el reproductor de Dahua (Smart Player) o convertirse con herramientas que soporten el contenedor DAV.

## 7.3 Alarmas y eventos inteligentes

```cpp
// Suscribe alarmas y eventos inteligentes y los imprime.
#include <cstdio>
#include <cstring>
#include <csignal>
#include <unistd.h>
#include "ZZNetSDK.h"

static volatile bool g_run = true;

static BOOL CALLBACK OnAlarm(LONG cmd, LLONG login, char* buf, DWORD len,
                             char* ip, LONG port, LDWORD) {
    switch (cmd) {
    case ZZ_MOTION_ALARM_EX:
    case ZZ_VIDEOLOST_ALARM_EX:
    case ZZ_SHELTER_ALARM_EX:
    case ZZ_ALARM_ALARM_EX:
        printf("[%s] alarma 0x%X canales activos:", ip, (unsigned)cmd);
        for (DWORD i = 0; i < len; i++) if (buf[i]) printf(" %u", i);
        printf("\n");
        break;
    default:
        printf("[%s] alarma 0x%X (%u bytes)\n", ip, (unsigned)cmd, len);
    }
    return TRUE;
}

static int CALLBACK OnIVS(LLONG h, DWORD type, void* info, BYTE* img, DWORD imgLen,
                          LDWORD, int seq, void*) {
    printf("Evento IVS 0x%X, imagen %u bytes, seq=%d\n", type, imgLen, seq);
    if (type == ZZ_EVENT_IVS_CROSSLINEDETECTION && img && imgLen) {
        FILE* f = fopen("cruce.jpg", "wb"); fwrite(img, 1, imgLen, f); fclose(f);
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 4) { printf("uso: %s ip usuario clave\n", argv[0]); return 1; }
    signal(SIGINT, [](int){ g_run = false; });
    ZZNETSDK_Init(NULL, 0);
    ZZNETSDK_SetDVRMessCallBack(OnAlarm, 0);

    ZZNET_DEVICEINFO info{}; int err = 0;
    LLONG login = ZZNETSDK_LoginEx(argv[1], 37777, argv[2], argv[3], 0, NULL, &info, &err);
    if (!login) { printf("login 0x%08X\n", ZZNETSDK_GetLastError()); return 2; }

    ZZNETSDK_StartListenEx(login);
    LLONG ivs = ZZNETSDK_RealLoadPictureEx(login, 0, ZZ_EVENT_IVS_ALL, TRUE, OnIVS, 0, NULL);

    while (g_run) sleep(1);

    if (ivs) ZZNETSDK_StopLoadPic(ivs);
    ZZNETSDK_StopListen(login);
    ZZNETSDK_Logout(login);
    ZZNETSDK_Cleanup();
}
```

## 7.4 Búsqueda y descarga de grabaciones

```cpp
// Busca grabaciones de las últimas 24 h de un canal y descarga la primera.
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <atomic>
#include <unistd.h>
#include "ZZNetSDK.h"

static std::atomic<bool> g_done{false};

static void toZZ(time_t t, ZZNET_TIME& z) {
    struct tm tm; localtime_r(&t, &tm);
    z.dwYear = tm.tm_year + 1900; z.dwMonth = tm.tm_mon + 1; z.dwDay = tm.tm_mday;
    z.dwHour = tm.tm_hour; z.dwMinute = tm.tm_min; z.dwSecond = tm.tm_sec;
}

static void CALLBACK OnPos(LLONG h, DWORD total, DWORD done, LDWORD) {
    if ((int)done == -1) { printf("\ndescarga completa\n"); g_done = true; }
    else if ((int)done == -2) { printf("\nsin permiso\n"); g_done = true; }
    else printf("\r%u/%u KB", done, total);
    fflush(stdout);
}

int main(int argc, char** argv) {
    if (argc < 5) { printf("uso: %s ip usuario clave canal\n", argv[0]); return 1; }
    ZZNETSDK_Init(NULL, 0);
    ZZNET_DEVICEINFO info{}; int err = 0;
    LLONG login = ZZNETSDK_LoginEx(argv[1], 37777, argv[2], argv[3], 0, NULL, &info, &err);
    if (!login) { printf("login 0x%08X\n", ZZNETSDK_GetLastError()); return 2; }

    ZZNET_TIME t0, t1; time_t now = time(NULL);
    toZZ(now - 24 * 3600, t0); toZZ(now, t1);

    static ZZNET_RECORDFILE_INFO files[200];
    int n = 0;
    if (!ZZNETSDK_QueryRecordFile(login, atoi(argv[4]), 0, &t0, &t1, NULL,
                                  files, sizeof(files), &n, 5000, FALSE)) {
        printf("QueryRecordFile 0x%08X\n", ZZNETSDK_GetLastError());
    } else {
        printf("%d archivos\n", n);
        for (int i = 0; i < n; i++)
            printf("  %02u:%02u:%02u - %02u:%02u:%02u  %u KB  tipo=%u\n",
                   files[i].starttime.dwHour, files[i].starttime.dwMinute, files[i].starttime.dwSecond,
                   files[i].endtime.dwHour, files[i].endtime.dwMinute, files[i].endtime.dwSecond,
                   files[i].size, files[i].nRecordFileType);
        if (n > 0) {
            char path[] = "grabacion.dav";
            LLONG dl = ZZNETSDK_DownloadByRecordFileEx(login, &files[0], path, OnPos, 0, NULL, 0, NULL);
            if (dl) { while (!g_done) usleep(200000); ZZNETSDK_StopDownload(dl); }
        }
    }
    ZZNETSDK_Logout(login);
    ZZNETSDK_Cleanup();
}
```

## 7.5 Búsqueda de equipos en la LAN

```cpp
#include <cstdio>
#include <unistd.h>
#include "ZZNetSDK.h"
static void CALLBACK OnDev(ZZDEVICE_NET_INFO_EX* d, void*){ printf("Encontrado %s %s %s\n", d->szIP, d->szMac, d->szDeviceType); }
int main(){ ZZNETSDK_Init(NULL,0); LLONG h=ZZNETSDK_StartSearchDevices(OnDev,NULL,NULL); printf("search handle=%ld err=0x%x\n",h,ZZNETSDK_GetLastError()); sleep(3); ZZNETSDK_StopSearchDevices(h); ZZNETSDK_Cleanup(); }
```

## 7.6 Exportar e importar configuración

```cpp
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "ZZNetSDK.h"
int main(int argc,char**argv){
    ZZNETSDK_Init(NULL,0);
    ZZNET_CONFIG_PARAM p; memset(&p,0,sizeof(p));
    strcpy(p.szIP,"127.0.0.1"); strcpy(p.szUserName,"admin"); strcpy(p.szPassword,"admin123");
    p.nConfigNum=3; p.configs[0]=EM_ZZ_CONFIG_NTP; p.configs[1]=EM_ZZ_CONFIG_Locales; p.configs[2]=EM_ZZ_CONFIG_DVRIP;
    static unsigned char buf[65536]; ZZNET_EXPORT_CONFIG out; out.pBuf=buf; out.nBufLen=sizeof(buf); out.nRetLen=0;
    BOOL ok=ZZNETSDK_ExportConfig(&p,&out);
    printf("Export=%d nRetLen=%d\n%.*s\n",ok,out.nRetLen,out.nRetLen,buf);
    if(argc>1){ ZZNET_CONFIG_PARAM q; memset(&q,0,sizeof(q)); strcpy(q.szIP,"127.0.0.1"); strcpy(q.szUserName,"admin"); strcpy(q.szPassword,"admin123");
        ok=ZZNETSDK_ImportConfig(&q,argv[1]); printf("Import=%d\n",ok);}
    // bad password
    strcpy(p.szPassword,"bad"); out.nRetLen=0; ok=ZZNETSDK_ExportConfig(&p,&out); printf("Export(badpwd)=%d nRetLen=%d [%.*s]\n",ok,out.nRetLen,out.nRetLen,buf);
    ZZNETSDK_Cleanup();
}
```

Salida real contra el emulador:

```text
$ ./cfgtest cfg.json
Export=1 nRetLen=279
{"DVRIP":"table.DVRIP.TCPPort=37777\r\ntable.DVRIP.UDPPort=37778\r\n","Locales":"table.Locales.DSTEnable=false\r\n...","NTP":"table.NTP.Address=pool.ntp.org\r\n..."}
Import=1
Export(badpwd)=0 nRetLen=0 []
```

### Emulador de CGI para pruebas sin equipo (`fakecam.py`)

Permite probar `ExportConfig`/`ImportConfig` y ver exactamente qué peticiones HTTP genera el SDK (se registran en `/tmp/fakecam.log`). Requiere permisos para abrir el puerto 80 (`sudo`), ya que el SDK siempre usa `http://<IP>/`.

```python
import http.server, base64, urllib.parse, sys, json
LOG=open('/tmp/fakecam.log','a')
CFG={"NTP":"table.NTP.Address=pool.ntp.org\r\ntable.NTP.Enable=true\r\ntable.NTP.Port=123\r\ntable.NTP.TimeZone=22\r\n",
     "Locales":"table.Locales.DSTEnable=false\r\ntable.Locales.TimeFormat=yyyy-MM-dd HH:mm:ss\r\n",
     "DVRIP":"table.DVRIP.TCPPort=37777\r\ntable.DVRIP.UDPPort=37778\r\n"}
class H(http.server.BaseHTTPRequestHandler):
    def do_GET(self):
        LOG.write(f"{self.command} {self.path} AUTH={self.headers.get('Authorization')}\n"); LOG.flush()
        a=self.headers.get('Authorization','')
        if not a.startswith('Basic ') or base64.b64decode(a[6:]).decode()!='admin:admin123':
            self.send_response(401); self.send_header('WWW-Authenticate','Basic realm="x"'); self.end_headers(); return
        q=urllib.parse.urlparse(self.path); p=urllib.parse.parse_qs(q.query)
        if p.get('action')==['getConfig']:
            n=p['name'][0]; body=CFG.get(n,"Error\r\nBad Request!\r\n")
        else:
            body="OK\r\n"
        self.send_response(200); self.send_header('Content-Type','text/plain'); self.send_header('Content-Length',str(len(body))); self.end_headers(); self.wfile.write(body.encode())
    def log_message(self,*a): pass
http.server.ThreadingHTTPServer(('127.0.0.1',int(sys.argv[1])),H).serve_forever()
```

```bash
sudo python3 fakecam.py 80 &
./cfgtest cfg.json
cat /tmp/fakecam.log
```

## 7.7 Makefile

```makefile
SDK      ?= /opt/zznetsdk
CXX      ?= g++
CXXFLAGS ?= -std=c++17 -O2 -Wall -I$(SDK)/include
LDFLAGS  ?= -L$(SDK)/lib_linux64
LDLIBS   := -lZZNetSDK -lgeneral_netsdk -lgeneral_configsdk -lssl -lcrypto -lpsl -lpthread

PROGS := demo search cfgtest live_to_file alarms records

all: $(PROGS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(PROGS)

.PHONY: all clean
```

```bash
make SDK=/opt/zznetsdk
```

## 7.8 CMake

```cmake
cmake_minimum_required(VERSION 3.16)
project(zznetsdk_ejemplos CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ZZNETSDK_ROOT "/opt/zznetsdk" CACHE PATH "Ruta de instalación de ZZNetSDK")
find_package(OpenSSL 3 REQUIRED)
find_package(Threads REQUIRED)
find_library(PSL_LIB psl REQUIRED)

add_library(zznetsdk SHARED IMPORTED)
set_target_properties(zznetsdk PROPERTIES
    IMPORTED_LOCATION "${ZZNETSDK_ROOT}/lib_linux64/libZZNetSDK.so"
    INTERFACE_INCLUDE_DIRECTORIES "${ZZNETSDK_ROOT}/include")
target_link_libraries(zznetsdk INTERFACE
    "${ZZNETSDK_ROOT}/lib_linux64/libgeneral_netsdk.so"
    "${ZZNETSDK_ROOT}/lib_linux64/libgeneral_configsdk.so"
    OpenSSL::SSL OpenSSL::Crypto ${PSL_LIB} Threads::Threads)

foreach(prog demo search cfgtest live_to_file alarms records)
    add_executable(${prog} ${prog}.cpp)
    target_link_libraries(${prog} PRIVATE zznetsdk)
endforeach()
```

```bash
cmake -S . -B build -DZZNETSDK_ROOT=/opt/zznetsdk
cmake --build build -j
```

## 7.9 Buenas prácticas reflejadas en los ejemplos

1. **Inicializar estructuras en cero** (`ZZNET_DEVICEINFO info{}` / `memset`) y completar `dwSize` cuando exista.
2. **Pasar el contexto por `dwUser`** (`(LDWORD)&ctx`) y recuperarlo con `reinterpret_cast` en el callback.
3. **Copiar los datos dentro del callback** y procesarlos fuera; proteger con mutex.
4. **No llamar funciones del SDK dentro de callbacks** (excepto `TalkSendData` en modo cliente).
5. **Cerrar en orden inverso**: `Stop*` → `Logout` → `Cleanup`.
6. **Especificar siempre `rType`** en `RealPlayEx` (el valor por defecto es multi-ventana).
7. **Registrar `GetLastError()` en hexadecimal** inmediatamente después del fallo.
