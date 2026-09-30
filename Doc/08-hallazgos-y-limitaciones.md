# 8. Hallazgos, limitaciones y riesgos

[← Índice](README.md)

Resultados de la ingeniería inversa que afectan la operación, el despliegue o la seguridad. Cada hallazgo indica cómo fue verificado.

## 8.1 Resumen

| # | Hallazgo | Severidad | Verificación |
|---|---|---|---|
| H1 | Requiere glibc ≥ 2.38 → mínimo Ubuntu 24.04 | Alta | `objdump -T` + prueba en 22.04 (falla) y 24.04 (funciona) |
| H2 | OpenSSL 3 y libpsl usados sin declararse (`NEEDED`) | Alta | `readelf -d`, `ldd -r` (231 símbolos indefinidos) |
| H3 | `RUNPATH` fijo de la máquina del fabricante | Media | `readelf -d` + prueba de enlace con `-rpath` (falla) |
| H4 | Bibliotecas renombradas: `dlopen("libavnetsdk.so")`/`("libdhconfigsdk.so")` fallan | Media | `LD_DEBUG=files` |
| H5 | `libgeneral_avnetsdk.so` no puede resolverse por completo (faltan dependencias) | Media | `LD_DEBUG`, `ldd -r` |
| H6 | Export/Import de configuración usa **HTTP sin TLS con autenticación Basic** | **Alta (seguridad)** | Desensamblado (`CURLOPT_HTTPAUTH=1`) + captura de peticiones |
| H7 | `libcurl.so` incluido es 7.54.1 con OpenSSL 1.0.2a (2015) estático | **Alta (seguridad)** | `strings` |
| H8 | `libZZNetSDK.so` exporta 89 símbolos `curl_*` (posible colisión) | Media | `nm -D` |
| H9 | Sin cabecera ni integración para `libplay.so` desde el NetSDK | Media | `grep` de nombres de biblioteca en binarios |
| H10 | Sin biblioteca de túnel P2P | Media (para el objetivo "P2P") | Pruebas de login `nSpecCap=19` |
| H11 | Faltan bibliotecas opcionales (`libStreamConvertor.so`, módulos de libplay) | Baja/Media | `strings` + inventario |
| H12 | Inconsistencias y errores en cabeceras/documentación | Baja | Revisión de cabeceras |
| H13 | Las estructuras ZZ son copias binarias de las de Dahua (sin conversión) | Informativo | Desensamblado de thunks |

## 8.2 H1 — Compatibilidad de sistema operativo

Las bibliotecas nuevas (`libZZNetSDK`, `libgeneral_*`) se compilaron con **GCC 13.3.0 en Ubuntu 24.04** (`.comment`: `GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0`) y usan símbolos C23 de glibc 2.38 (`__isoc23_strtol`, `__isoc23_sscanf`...). No hay forma de ejecutarlas en distribuciones anteriores sin contenedor. `libplay.so` y demás bibliotecas multimedia, en cambio, son antiguas (GCC 4.4/4.8, Red Hat) y muy portables.

**Recomendación:** estandarizar servidores en Ubuntu 24.04 LTS (soporte hasta 2029) o empaquetar la aplicación en un contenedor `ubuntu:24.04`.

## 8.3 H2/H3 — Dependencias no declaradas y RUNPATH

- `libZZNetSDK.so` enlaza estáticamente libcurl, pero **no** OpenSSL ni libpsl, y tampoco los declara como `NEEDED`. Si la aplicación no enlaza `-lssl -lcrypto -lpsl`, el proceso falla con `undefined symbol` al cargar (o, con *lazy binding*, al primer uso).
- `RUNPATH = /mnt/f/Work/ZenoSDK/Trunk/DNetSDK/Depends/linux/x64/dahua/lib` revela la ruta de compilación del integrador (proyecto "ZenoSDK/DNetSDK"). Al existir `RUNPATH`, el cargador ignora el `RPATH` del ejecutable para las dependencias de esta biblioteca.

**Recomendación:** `ldconfig` + `LD_LIBRARY_PATH` como en [02 §2.5](02-instalacion-ubuntu.md#25-registrar-la-ruta-de-bibliotecas). Si se dispone de `patchelf`, también puede corregirse: `patchelf --set-rpath '$ORIGIN' libZZNetSDK.so` *(no probado)*.

## 8.4 H4/H5 — Carga dinámica del NetSDK

`libgeneral_netsdk.so` contiene los mensajes *"Load avnetsdk library dynamically"*, *"Load configsdk dynamically"*, *"Load curl dynamically"* y hace `dlopen` de:

| Nombre pedido | ¿Existe en el paquete? | Resultado sin corrección | Con corrección |
|---|---|---|---|
| `libcurl.so` | Sí | Falla si no está en `LD_LIBRARY_PATH` (la caché sólo tiene `libcurl.so.4`) | OK con `LD_LIBRARY_PATH` |
| `libdhconfigsdk.so` | Como `libgeneral_configsdk.so` | Falla | OK con symlink |
| `libavnetsdk.so` | Como `libgeneral_avnetsdk.so` | Falla | Carga, pero falla la resolución de símbolos |
| `libStreamConvertor.so` | **No** | Falla | — |

`libgeneral_avnetsdk.so` necesita símbolos de `libInfra`, `libNetFramework`, `libStream`, `libStreamSvr` (sin `NEEDED`), y además de **JsonCpp** (`Json::Value`...), **OpenSSL** (`AES_*`, `HMAC`) y funciones `AudioBroadcast*` que **no existen en ninguna biblioteca del paquete**. Incluso precargándolas con `LD_PRELOAD`, la carga termina en `undefined symbol: AudioBroadcastDelDev`.

**Impacto:** las funciones que el NetSDK delega en AVNetSDK (protocolos RTSP/AV de nueva generación en algunos equipos) no estarán disponibles; el NetSDK sigue operando por su vía principal (login, video, alarmas y búsqueda funcionaron en las pruebas). Las funciones de transcodificación (`DownloadByDataType` a MP4/TS, *(inferido)*) pueden devolver `ZZNET_ERROR_STREAMCONVERTOR_DEFECT`.

**Recomendación:** solicitar al proveedor un paquete completo (o las bibliotecas equivalentes del *Dahua General NetSDK* para la misma versión) y validar con equipos reales las funciones críticas.

## 8.5 H6 — Seguridad de `ExportConfig` / `ImportConfig`

Verificado en el binario y en tráfico real:

- URL fija `http://<IP>/cgi-bin/configManager.cgi...` → **sin TLS**, puerto 80 fijo (no configurable).
- `CURLOPT_HTTPAUTH = CURLAUTH_BASIC` → la cabecera `Authorization: Basic base64(usuario:clave)` viaja **en claro** en cada petición (se observó `YWRtaW46YWRtaW4xMjM=` = `admin:admin123`).
- `setConfig` se envía por **GET** con los valores en la URL (quedan en logs de proxies/equipo).
- Un fallo de autenticación devuelve simplemente `FALSE` con `nRetLen = 0`, sin código de error específico en `GetLastError`.
- Muchos firmwares Dahua actuales **deshabilitan Basic** y sólo aceptan Digest en CGI: en esos equipos la función fallará aunque las credenciales sean correctas *(inferido de la configuración por defecto de firmwares recientes)*.

**Recomendaciones:**

1. Usar estas funciones sólo en redes de gestión aisladas/VPN.
2. Para configuración en producción preferir `GetNewDevConfig`/`SetNewDevConfig` (protocolo del NetSDK, autenticación con desafío) — ver [05 §5.13](05-flujos-secuencia.md).
3. Si se necesita respaldo completo y seguro, implementar la exportación con `QueryNewSystemInfo`/`GetNewDevConfig` sobre la sesión ya autenticada.

## 8.6 H7/H8 — Componentes de terceros

| Componente | Dónde | Versión | Observación |
|---|---|---|---|
| libcurl | `lib_linux64/libcurl.so` (lo carga el NetSDK) | **7.54.1** (2017) | Enlazado estáticamente con **OpenSSL 1.0.2a (marzo 2015)**, versión con múltiples CVE conocidos y fuera de soporte |
| libcurl | embebido en `libZZNetSDK.so` | ≥ 8.12 *(inferido por la presencia de `curl_easy_ssls_export`)* | Usa el OpenSSL 3 del sistema |
| nlohmann/json | embebido en `libZZNetSDK.so` | 3.11.3 | — |
| OpenSSL | sistema | 3.0.x (Ubuntu 24.04) | Requerido por libZZNetSDK |

`libZZNetSDK.so` **exporta** 89 funciones `curl_*`. Si la aplicación también enlaza la libcurl del sistema, el orden de carga decide cuál implementación se usa (interposición de símbolos), lo que puede causar comportamientos inesperados.

**Recomendación:** si la aplicación necesita libcurl, cargarla en un proceso/servicio aparte o verificar con `LD_DEBUG=bindings` qué implementación se enlaza. Pedir al proveedor que compile con `-fvisibility=hidden` y actualice `libcurl.so`.

## 8.7 H9 — Decodificación y visualización

- No existe ninguna referencia a `libplay.so` en `libgeneral_netsdk.so` ni en `libZZNetSDK.so`: el parámetro `hWnd` de `RealPlayEx`/`PlayBackByTimeEx` probablemente **no produce video en pantalla** en esta build *(inferido; requiere prueba con equipo)*.
- `libplay.so` exporta 331 funciones `PLAY_*` (`PLAY_GetFreePort`, `PLAY_OpenStream`, `PLAY_InputData`, `PLAY_SetDecodeCallBack`, `PLAY_Play`, `PLAY_CatchPic`, `PLAY_Stop`, `PLAY_CloseStream`, ...) pero **no se entrega `dhplay.h`**. Para usarla hay que obtener la cabecera del PlaySDK de Dahua de la misma generación o declarar los prototipos manualmente.
- `CapturePicture`/`CapturePictureEx` y `RecordStart` (captura de micrófono) dependen de decodificación/audio local y pueden no funcionar sin PlaySDK integrado *(inferido)*.
- `JudgeHW.sh` hace referencia a `libHWDec.so.VA1`/`VA2`, que no están en el paquete.

**Recomendación:** para servidores, usar el patrón *callback* ([05 §5.3](05-flujos-secuencia.md)) y decodificar con FFmpeg/GStreamer o con `libplay.so` + cabecera oficial.

## 8.8 H10 — P2P

El proyecto se denomina "P2P Dahua", por lo que este punto es relevante:

- La API admite `nSpecCap = 19` (P2P), pero se comporta como un login TCP hacia la IP/puerto indicados. No acepta números de serie ni contacta servidores P2P.
- **No hay** en el paquete ninguna biblioteca de túnel P2P (en el ecosistema Dahua suele ser un SDK separado que mapea el equipo a un puerto local).
- En `libgeneral_netsdk.so` sólo aparecen referencias a parámetros P2P de red móvil (`EM_OPT_TYPE_P2P_NETPARAM_V1`, `GetNetAccessMobileP2P`).

**Recomendación:** para acceso remoto sin IP pública, usar **registro activo** (`ListenServer` + `nSpecCap=2`, [05 §5.10](05-flujos-secuencia.md)), que está completamente incluido en el SDK, o incorporar un componente de túnel P2P y luego hacer `LoginEx(127.0.0.1, puertoLocal, ..., 19, ...)` ([05 §5.11](05-flujos-secuencia.md)).

## 8.9 H12 — Inconsistencias en cabeceras y documentación

| Ubicación | Problema |
|---|---|
| `ZZNetSDK.h` `LoginEx` | Comentario `nSpecCap=9` "remote device login" vs enumeración `EM_ZZ_LOGIN_SPEC_CAP_INTELLIGENT_BOX`; `16` "proxy login" vs `..._CLOUD` |
| `ZZNetSDK.h` `LoginEx` | Hace referencia a "`ZZNETSDK_Login`" para los códigos de error, función que no existe |
| `ZZNetSDK.h` `RealPlayEx` | Valor por defecto `ZZ_RType_Multiplay` (mosaico), poco intuitivo |
| Cabeceras | Son **sólo C++** (`<cstdint>`, argumentos por defecto dentro de `extern "C"`); no pueden usarse desde C puro sin adaptar |
| `ZZGlobal.h` | `LONG` es de 32 bits en Linux (`typedef int LONG`) — cuidado al portar código de Windows |
| `ZZNET_DEVICEINFO` | Estructura antigua (`NET_DEVICEINFO`): `byChanNum` es un `BYTE` (máx. 255 canales) |
| Binario vs cabecera | `DevConfig::ExportConfig` usa internamente el tipo `tagCONFIG_PARAM`, mientras la cabecera publica `tagZZNET_CONFIG_PARAM` (no afecta al enlace C, sí indica que la cabecera fue re-editada) |
| Nombres con errores tipográficos (se mantienen por compatibilidad) | `SetSplitAudioOuput`, `QueryRemotDevState`, `ZZNET_LOGIN_ERROR_USER_OR_PASSOWRD`, `ZZNET_ERROR_DEFULAT_SEARCH_PORT`, `ZZNET_ERRPR_XRAY_*`, `ZZNET_USER_FLASEPWD` |
| `Doc/ZZNetSDK API.doc` | Es un resumen de las cabeceras (1.113 líneas); no documenta estructuras, callbacks, flujos ni requisitos |
| Comentarios de estructuras | Refieren a tipos Dahua no incluidos (`NET_SNAP_MODE`, `CFG_RECORD_INFO`, `NET_IN_...`) |

## 8.10 H13 — Compatibilidad con la documentación de Dahua

Como cada `ZZNETSDK_X` salta directamente a `CLIENT_X` pasando los mismos punteros, **las estructuras ZZ deben ser idénticas en memoria a las de Dahua**. Esto tiene dos consecuencias prácticas:

1. La documentación, foros y ejemplos del *Dahua NetSDK* aplican casi sin cambios (sustituir prefijos `CLIENT_`→`ZZNETSDK_`, `NET_`/`DH_`→`ZZNET_`/`ZZ_`).
2. Cualquier error del integrador al "renombrar" una estructura (un campo omitido o cambiado de tamaño) provocaría corrupción de memoria silenciosa. Las funciones más usadas (login, video, grabaciones, export/import) se ejercitaron sin problemas, pero se recomienda **validar con equipos reales** las estructuras de módulos específicos (rostros, video-wall, tránsito) antes de producción.

## 8.11 Lista de verificación para producción

- [ ] Servidor Ubuntu 24.04 LTS x86-64 (o contenedor equivalente).
- [ ] `libssl-dev`, `libpsl-dev` instalados; aplicación enlazada con `-lssl -lcrypto -lpsl`.
- [ ] `/etc/ld.so.conf.d/zznetsdk.conf` + `ldconfig`; `LD_LIBRARY_PATH` en el servicio.
- [ ] Symlinks `libavnetsdk.so` y `libdhconfigsdk.so` creados.
- [ ] Callbacks sin llamadas al SDK, con copia de buffers y colas.
- [ ] Lógica de reconexión ante `ffDisConnect`.
- [ ] Export/Import de configuración sólo en red de gestión segura (o reemplazado por `Get/SetNewDevConfig`).
- [ ] Pruebas con los modelos de equipos reales del proyecto (video, reproducción, alarmas, PTZ, IVS).
- [ ] Solicitar al proveedor: `dhplay.h`, `libStreamConvertor.so`, dependencias completas de AVNetSDK, libcurl actualizado, componente P2P si se requiere.
