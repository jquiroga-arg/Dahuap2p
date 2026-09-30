# ZZNetSDK para Linux x64 — Documentación técnica (ingeniería inversa)

> **Paquete analizado:** `ZZNetSDK_Linux64_GCC13.3.0_V3.0.7.6.R.2026-02-06`
> **Versión reportada por `ZZNETSDK_GetVersion()`:** `1.1.1.3`
> **Base subyacente:** Dahua General NetSDK (Linux x64, compilado con GCC 13.3.0 sobre Ubuntu 24.04)
> **Fecha del análisis:** 30/09/2026

Esta documentación fue generada a partir del análisis del código entregado (cabeceras C/C++, binarios `.so`, archivos de configuración y el documento `Doc/ZZNetSDK API.doc`). Todo lo que se afirma aquí proviene de una de estas fuentes:

| Fuente | Qué se obtuvo |
|---|---|
| `include/ZZNetSDK.h`, `ZZGlobal.h`, `ZZConfig.h` | Firmas de las 122 funciones, estructuras, enumeraciones, callbacks y códigos de error |
| Tabla de símbolos ELF (`nm`, `readelf`, `objdump`) | Dependencias, qué función de Dahua invoca cada función `ZZNETSDK_*`, clases internas (`DevConfig`) |
| Desensamblado de `libZZNetSDK.so` | Lógica propia del wrapper (exportación/importación de configuración vía HTTP CGI) |
| Pruebas reales en Ubuntu 24.04 | Compilación, enlace, carga dinámica, tiempos de login, exportación/importación contra un dispositivo simulado |
| `Doc/ZZNetSDK API.doc` | Descripción oficial (resumida) de cada función |

Cuando algo es una **inferencia** (no verificable sin un equipo físico) se indica explícitamente con la etiqueta *(inferido)*.

---

## Índice

| # | Documento | Contenido |
|---|---|---|
| 1 | [Requisitos de hardware y software](01-requisitos.md) | CPU, memoria, red, versión de Ubuntu, glibc, paquetes del sistema |
| 2 | [Instalación en Ubuntu Linux](02-instalacion-ubuntu.md) | Paso a paso verificado, compilación del primer programa, resolución de problemas |
| 3 | [Arquitectura y componentes](03-arquitectura.md) | Diagrama de arquitectura, diagrama de componentes, inventario de bibliotecas, carga dinámica |
| 4 | [Funcionalidades y referencia de la API](04-funcionalidades.md) | Las 122 funciones agrupadas por módulo, modelo de handles, callbacks, estructuras clave |
| 5 | [Flujos principales (diagramas de secuencia)](05-flujos-secuencia.md) | Inicialización, login, video en vivo, reproducción, descarga, alarmas, eventos inteligentes, registro activo, P2P, PTZ, audio, configuración |
| 6 | [Códigos de error](06-codigos-error.md) | Tabla de errores `ZZNET_*` y errores de login |
| 7 | [Ejemplos de código](07-ejemplos.md) | Programas probados, `Makefile`, `CMakeLists.txt` |
| 8 | [Hallazgos, limitaciones y riesgos](08-hallazgos-y-limitaciones.md) | Resultados de la ingeniería inversa, problemas de empaquetado, seguridad |
| 9 | [Guía: cámaras remotas por registro activo](09-registro-activo.md) | P2P vs registro activo, configuración de la cámara y del servidor, programa de ejemplo |

---

## Resumen ejecutivo

**¿Qué es?** `libZZNetSDK.so` es una **capa de fachada (wrapper) delgada** sobre el *Dahua General NetSDK*. Expone 122 funciones con prefijo `ZZNETSDK_` y tipos con prefijo `ZZ`/`ZZNET_`, que se traducen **1 a 1** a las funciones `CLIENT_*` de Dahua (por ejemplo, `ZZNETSDK_LoginEx` → `CLIENT_LoginEx`, `ZZNETSDK_ZZPTZControlEx` → `CLIENT_DHPTZControlEx`). El objetivo evidente es "marcar blanco" (re-branding) el SDK de Dahua, ocultando los nombres `DH`/`CLIENT`.

**¿Qué agrega por sí mismo?** Sólo dos funciones tienen lógica propia:

- `ZZNETSDK_ExportConfig` — descarga configuraciones del equipo por **HTTP** (`/cgi-bin/configManager.cgi?action=getConfig`) y las devuelve como JSON.
- `ZZNETSDK_ImportConfig` — lee ese JSON, lo compara contra la configuración actual del equipo y envía **sólo las diferencias** (`action=setConfig`), dejando para el final las claves que provocan reinicio.

Para esto el wrapper incluye estáticamente **libcurl** y **nlohmann/json 3.11.3**.

**Capacidades principales** (heredadas del NetSDK de Dahua):

- Conexión a cámaras IP, NVR, XVR, DVR: TCP, UDP, multicast, SSL, P2P, registro activo (el equipo se conecta al servidor).
- Video en vivo (flujo principal/sub-flujos), reproducción y descarga de grabaciones por archivo o por tiempo.
- Suscripción a alarmas y eventos inteligentes (IVS: línea de cruce, intrusión, rostros, tránsito, etc.) con imágenes.
- PTZ, enfoque, IO de alarmas, audio bidireccional (intercomunicador), capturas.
- Configuración (estructuras binarias y JSON), información y capacidades del equipo, usuarios, logs, actualización de firmware, reinicio y reseteo.
- Reconocimiento facial (bases y grupos), máscaras de privacidad, video-wall/matrices.
- Búsqueda de equipos en la LAN e inicialización de equipos nuevos.

**Hallazgos críticos para operar el SDK** (detalle en [08](08-hallazgos-y-limitaciones.md)):

1. **Requiere Ubuntu 24.04 LTS o superior** (glibc ≥ 2.38, libstdc++ con `GLIBCXX_3.4.32`). En Ubuntu 22.04 **no carga**.
2. `libZZNetSDK.so` usa OpenSSL 3 y libpsl **sin declararlos como dependencias**: la aplicación debe enlazar `-lssl -lcrypto -lpsl`.
3. `libZZNetSDK.so` tiene un `RUNPATH` fijo de la máquina de compilación; hay que usar `ldconfig` o `LD_LIBRARY_PATH`.
4. El NetSDK intenta cargar `libavnetsdk.so` y `libdhconfigsdk.so`, pero el paquete los trae renombrados como `libgeneral_*`. Se recomiendan enlaces simbólicos.
5. La exportación/importación de configuración envía la contraseña con **HTTP Basic sin cifrar**.
6. No incluye cabecera para `libplay.so` (decodificación/render), ni ejemplos, ni la biblioteca de túnel P2P.

**Cámaras remotas detrás de NAT:** el mecanismo soportado por este SDK es el **registro activo** (la cámara se conecta al servidor), no el P2P en la nube de Dahua. Ver la guía [09-registro-activo.md](09-registro-activo.md).
