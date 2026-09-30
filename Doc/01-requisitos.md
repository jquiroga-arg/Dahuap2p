# 1. Requisitos de hardware y software

[← Índice](README.md)

## 1.1 Arquitectura de CPU

Todas las bibliotecas del paquete son `ELF 64-bit LSB shared object, x86-64`. **No hay binarios para ARM (aarch64) ni 32 bits.**

| Requisito | Valor |
|---|---|
| Arquitectura | x86-64 (AMD64 / Intel 64) |
| Sistema | Linux 64 bits |
| Máquinas virtuales / contenedores | Soportado (validado en contenedor Ubuntu 24.04 y VM) |
| Raspberry Pi / Jetson / ARM | **No soportado** con este paquete |

## 1.2 Hardware recomendado

Los valores mínimos se midieron con un programa de prueba; los recomendados son estimaciones para cargas típicas de videovigilancia *(inferido)*.

| Recurso | Mínimo (medido) | Recomendado |
|---|---|---|
| CPU | 1 núcleo x86-64 | 4+ núcleos si se decodifica video (con `libplay.so`) |
| RAM | ~30 MB de RSS tras `ZZNETSDK_Init` | 512 MB + ~20-50 MB por flujo de video decodificado |
| Hilos | El SDK crea **14 hilos** internos en `ZZNETSDK_Init` | Límite de hilos del proceso sin restricciones fuertes |
| Disco | ~163 MB (bibliotecas) | + espacio para grabaciones descargadas/capturas |
| GPU (opcional) | — | Intel/AMD con VA-API o NVIDIA con VDPAU para decodificación por hardware en `libplay.so` |

### Medición real

```text
antes Init:  RSS=25568 kB  hilos=1
tras Init:   RSS=29076 kB  hilos=15
tras Cleanup: RSS=26668 kB hilos=1
```

## 1.3 Red

| Puerto (equipo Dahua por defecto) | Protocolo | Uso en el SDK |
|---|---|---|
| **37777/TCP** | Protocolo privado Dahua (DVRIP) | Login, comandos, video en vivo, reproducción, alarmas |
| 37778/UDP | DVRIP UDP | Login UDP (`nSpecCap=4`) |
| **80/TCP** | HTTP CGI | `ZZNETSDK_ExportConfig` / `ZZNETSDK_ImportConfig` |
| 443/TCP | HTTPS | Login SSL (`nSpecCap=7`) según el equipo |
| 5050/UDP, 37810/UDP | Búsqueda/broadcast | `ZZNETSDK_StartSearchDevices`, `ZZNETSDK_SearchDevicesByIPs` (el SDK reserva estos puertos, ver error `ZZNET_ERROR_DEFULAT_SEARCH_PORT`) |
| Puerto a elección | TCP entrante | Servidor de registro activo (`ZZNETSDK_ListenServer`) |

Para la búsqueda en LAN el host debe estar en el mismo segmento (o permitir multicast/broadcast). Para el registro activo, el servidor debe ser alcanzable **desde** el equipo (NAT/firewall abiertos hacia el servidor).

## 1.4 Sistema operativo

El análisis de versiones de símbolos (`objdump -T`) arroja:

| Biblioteca | glibc máx. requerida | libstdc++ máx. requerida | Compilador |
|---|---|---|---|
| `libZZNetSDK.so` | **GLIBC_2.38** | GLIBCXX_3.4.31 | GCC 13.3.0 (Ubuntu 24.04) |
| `libgeneral_netsdk.so` | **GLIBC_2.38** | **GLIBCXX_3.4.32** | GCC 13.3.0 (Ubuntu 24.04) |
| `libgeneral_configsdk.so` | GLIBC_2.38 | GLIBCXX_3.4.32 | GCC 13.3.0 |
| `libgeneral_avnetsdk.so` | GLIBC_2.38 | GLIBCXX_3.4.32 | GCC 13.3.0 |
| `libplay.so` | GLIBC_2.7 | GLIBCXX_3.4.11 | GCC 4.4/4.8 (Red Hat) |
| resto (`libInfra`, `libStream*`, `libRender*`...) | ≤ GLIBC_2.14 | ≤ GLIBCXX_3.4.18 | — |

Consecuencia directa:

| Distribución | glibc | ¿Funciona? |
|---|---|---|
| **Ubuntu 24.04 LTS (Noble)** | 2.39 | **Sí (validado)** |
| Ubuntu 24.10 / 25.04 / 26.04 | ≥ 2.40 | Sí *(inferido, compatibilidad hacia adelante de glibc)* |
| Ubuntu 22.04 LTS (Jammy) | 2.35 | **No** — `version 'GLIBC_2.38' not found` (validado) |
| Ubuntu 20.04 LTS | 2.31 | No |
| Debian 13 (Trixie) | 2.41 | Sí *(inferido)* |
| Debian 12 (Bookworm) | 2.36 | No |
| RHEL/Rocky/Alma 9 | 2.34 | No |

Error obtenido en Ubuntu 22.04:

```text
./libZZNetSDK.so: /lib/x86_64-linux-gnu/libc.so.6: version `GLIBC_2.38' not found
./libZZNetSDK.so: /lib/x86_64-linux-gnu/libstdc++.so.6: version `GLIBCXX_3.4.31' not found
```

> Si se necesita correr en 22.04, la única vía es ejecutar la aplicación dentro de un contenedor Ubuntu 24.04 (Docker/Podman) — ver [02-instalacion-ubuntu.md §2.9](02-instalacion-ubuntu.md#29-alternativa-contenedor-docker-para-hosts-con-ubuntu-2204).

## 1.5 Paquetes de sistema requeridos (Ubuntu 24.04)

| Paquete | Para qué | Obligatorio |
|---|---|---|
| `build-essential` (g++ ≥ 13) | Compilar la aplicación. Las cabeceras son **C++** (usan `<cstdint>` y argumentos por defecto) | Sí (desarrollo) |
| `libssl3t64` / `libssl-dev` | OpenSSL 3: `libZZNetSDK.so` referencia ~200 símbolos `SSL_*`, `X509_*`, `EVP_*` sin declarar la dependencia | **Sí** |
| `libpsl5t64` / `libpsl-dev` | Public Suffix List: símbolos `psl_*` usados por el libcurl embebido | **Sí** |
| `libstdc++6`, `libgcc-s1` | Runtime C++ | Sí (ya en el sistema) |
| `libx11-6`, `libxv1`, `libgl1` | Requeridos por `libplay.so`, `libRenderEngine.so`, `libHWDec.so`, `libIvsDrawer.so` | Sólo si se usa `libplay.so` |
| `libasound2t64` | Audio ALSA en `libplay.so` | Sólo si se usa `libplay.so` |
| `libva2`, `libva-x11-2`, `libva-glx2`, `libvdpau1` | Decodificación por hardware (`enablevadecode=1` en `PlayConfig.ini`) | Opcional |

Validación en el contenedor de pruebas: `libssl-dev 3.0.13-0ubuntu3.9`, `libpsl-dev 0.21.2-1.1build1`.

## 1.6 Entorno gráfico

- Para **servidores sin pantalla (headless)** el patrón recomendado es: `ZZNETSDK_RealPlayEx(..., hWnd = NULL, ...)` + `ZZNETSDK_SetRealDataCallBack` para recibir el flujo crudo y procesarlo/almacenarlo/transcodificarlo. No se necesita X11.
- El parámetro `HWND` en Linux es `void*`. En el análisis de `libgeneral_netsdk.so` no aparece ninguna referencia a `libplay.so`, por lo que el render directo sobre ventana desde el NetSDK **no está garantizado** en esta build *(inferido)*. La decodificación/visualización debe hacerla la aplicación (con `libplay.so` + API `PLAY_*`, FFmpeg/GStreamer, etc.).

## 1.7 Credenciales y equipo

- Usuario/contraseña del equipo Dahua (o compatible OEM).
- Equipo **inicializado** (con contraseña establecida). Si no lo está, el login devuelve `ZZNET_LOGIN_ERROR_DEVICE_NOT_INIT`; se inicializa con `ZZNETSDK_InitDevAccount` (ver [05 §5.12](05-flujos-secuencia.md)).
- Para `ExportConfig`/`ImportConfig`: la interfaz **HTTP (puerto 80)** del equipo debe estar habilitada **y aceptar autenticación Basic** (ver [08](08-hallazgos-y-limitaciones.md)).
