# 5. Flujos principales — diagramas de secuencia

[← Índice](README.md)

Participantes usados en los diagramas:

| Participante | Qué representa |
|---|---|
| `App` | La aplicación del integrador |
| `ZZ` | `libZZNetSDK.so` (fachada) |
| `NetSDK` | `libgeneral_netsdk.so` (hilos internos incluidos) |
| `Dev` | Equipo Dahua (IPC/NVR/XVR) |
| `CB` | Callback de la aplicación, ejecutado en un hilo del SDK |

Los pasos de red internos del protocolo privado Dahua (DVRIP) se marcan *(inferido)*: no son visibles en la API, se deducen del comportamiento del NetSDK y de los códigos de error.

---

## 5.1 Ciclo de vida completo y desconexión

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as libZZNetSDK
    participant NetSDK as libgeneral_netsdk
    participant Dev as Equipo
    participant CB as Callback App

    App->>ZZ: ZZNETSDK_Init(OnDisconnect, dwUser)
    ZZ->>NetSDK: CLIENT_InitEx(OnDisconnect, dwUser, NULL)
    NetSDK-->>NetSDK: crea 14 hilos internos
    NetSDK-->>App: TRUE
    App->>ZZ: ZZNETSDK_LoginEx(ip, 37777, user, pass, 0, NULL, &info, &err)
    ZZ->>NetSDK: CLIENT_LoginEx(...)
    NetSDK->>Dev: TCP connect + autenticación (inferido)
    Dev-->>NetSDK: sesión aceptada + datos del equipo
    NetSDK-->>App: lLoginID != 0, info (SN, canales)
    Note over App,Dev: ... operación normal (video, alarmas, configuración) ...
    Dev--xNetSDK: caída de red / reinicio del equipo
    NetSDK->>CB: OnDisconnect(lLoginID, ip, port, dwUser)
    CB-->>CB: marcar equipo offline y encolar reconexión
    Note over App: no llamar al SDK dentro del callback
    App->>ZZ: ZZNETSDK_Logout(lLoginID viejo)
    loop cada N segundos hasta reconectar
        App->>ZZ: ZZNETSDK_LoginEx(...)
        ZZ-->>App: 0 y GetLastError = LOGIN_ERROR_TIMEOUT
    end
    ZZ-->>App: nuevo lLoginID
    App->>App: reabrir flujos y suscripciones
    App->>ZZ: ZZNETSDK_Logout(lLoginID)
    App->>ZZ: ZZNETSDK_Cleanup()
    ZZ->>NetSDK: CLIENT_Cleanup()
    NetSDK-->>NetSDK: finaliza hilos
```

Puntos clave:

- El SDK **no reabre** automáticamente los flujos de la aplicación: tras la reconexión hay que volver a llamar `RealPlayEx`, `StartListenEx`, `RealLoadPictureEx`, etc.
- Tiempo medido de fallo de login contra un host inalcanzable: **~5 s** (`ZZNET_LOGIN_ERROR_TIMEOUT`, `0x80000066`).

---

## 5.2 Login con manejo de errores

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNetSDK
    participant Dev as Equipo

    App->>ZZ: LoginEx(ip, port, user, pass, nSpecCap=0, NULL, &info, &err)
    ZZ->>Dev: conexión TCP principal (inferido)
    alt credenciales correctas
        Dev-->>ZZ: OK
        ZZ-->>App: lLoginID > 0
    else contraseña incorrecta
        Dev-->>ZZ: rechazo
        ZZ-->>App: 0, err=1, LastError=0x80000064, info.byLeftLogTimes = intentos restantes
    else cuenta bloqueada
        ZZ-->>App: 0, err=5, LastError=0x80000068
    else equipo sin inicializar
        ZZ-->>App: 0, LastError=0x80000076 (DEVICE_NOT_INIT)
        App->>ZZ: InitDevAccount(...) ver 5.12
    else sin respuesta
        ZZ-->>App: 0, err=3, LastError=0x80000066 (TIMEOUT, ~5 s)
    end
```

---

## 5.3 Video en vivo en servidor (sin ventana, por callback)

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNetSDK
    participant NetSDK
    participant Dev as Equipo
    participant CB as OnRealData (hilo SDK)
    participant Q as Cola de la App
    participant W as Worker App (decodificar/grabar/reenviar)

    App->>ZZ: RealPlayEx(lLoginID, canal, hWnd=NULL, ZZ_RType_Realplay_1)
    ZZ->>NetSDK: CLIENT_RealPlayEx
    NetSDK->>Dev: abre sub-conexión de medios (inferido)
    Dev-->>NetSDK: aceptado
    ZZ-->>App: lRealHandle
    App->>ZZ: SetRealDataCallBack(lRealHandle, OnRealData, this)
    opt baja latencia
        App->>ZZ: SetRealplayBufferPolicy(lRealHandle, nPolicy=2)
    end
    App->>ZZ: MakeKeyFrame(lLoginID, canal, 1)
    loop mientras el flujo esté abierto
        Dev-->>NetSDK: paquetes de video/audio (formato privado DAV)
        NetSDK->>CB: OnRealData(handle, dwDataType=0, pBuffer, size, this)
        CB->>Q: copiar pBuffer (válido sólo durante la llamada)
        Q-->>W: bloque
        W-->>W: PLAY_InputData / FFmpeg / archivo .dav / RTSP
    end
    App->>ZZ: StopRealPlay(lRealHandle)
    ZZ->>NetSDK: CLIENT_StopRealPlay
    NetSDK->>Dev: cierra sub-conexión
```

Notas:

- `dwDataType = 0` es el flujo original del equipo (contenedor privado Dahua, H.264/H.265 + audio). Para decodificarlo se puede usar `libplay.so` (`PLAY_OpenStream` → `PLAY_InputData` → `PLAY_SetDecodeCallBack` para obtener YUV) o un demuxer propio.
- Elegir explícitamente `rType`: el valor por defecto de la cabecera es `ZZ_RType_Multiplay` (mosaico), que no es lo habitual.

---

## 5.4 Búsqueda de grabaciones y reproducción por tiempo

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNetSDK
    participant Dev as NVR
    participant CBd as cbData (hilo SDK)
    participant CBp as cbPos (hilo SDK)

    App->>ZZ: QueryRecordStatus(lLoginID, canal, tipo, mes)
    ZZ-->>App: días del mes con grabación
    App->>ZZ: QueryRecordFile(lLoginID, canal, 0, inicio, fin, NULL, files[], sizeof, &n, 5000)
    ZZ->>Dev: consulta de índice
    Dev-->>ZZ: lista de archivos
    ZZ-->>App: TRUE, n archivos (ZZNET_RECORDFILE_INFO)
    App->>ZZ: PlayBackByTimeEx(lLoginID, canal, inicio, fin, NULL, cbPos, u1, cbData, u2)
    ZZ-->>App: lPlayHandle
    loop reproducción
        Dev-->>ZZ: datos
        ZZ->>CBd: cbData(lPlayHandle, 0, buf, len, u2)
        ZZ->>CBp: cbPos(lPlayHandle, total, actual, u1)
    end
    App->>ZZ: PausePlayBack(lPlayHandle, TRUE)
    App->>ZZ: SeekPlayBack(lPlayHandle, 600, 0)
    App->>ZZ: PausePlayBack(lPlayHandle, FALSE)
    App->>ZZ: FastPlayBack(lPlayHandle)
    ZZ->>CBp: cbPos(..., actual = -1) fin
    App->>ZZ: StopPlayBack(lPlayHandle)
```

---

## 5.5 Descarga de grabaciones

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNetSDK
    participant Dev as NVR
    participant CB as cbPos

    alt por archivo
        App->>ZZ: QueryRecordFile(...) -> files[]
        App->>ZZ: DownloadByRecordFileEx(lLoginID, &files[i], "/data/c1.dav", cbPos, u, NULL, 0)
    else por rango de tiempo
        App->>ZZ: DownloadByTimeEx(lLoginID, canal, 0, inicio, fin, "/data/c1.dav", cbTimePos, u, NULL, 0)
    end
    ZZ-->>App: lFileHandle
    loop transferencia
        Dev-->>ZZ: bloques de datos
        ZZ-->>ZZ: escribe en archivo (o entrega a cbData)
        ZZ->>CB: progreso(total, descargado)
    end
    alt completado
        ZZ->>CB: descargado = -1
    else sin permiso
        ZZ->>CB: descargado = -2
    end
    App->>ZZ: StopDownload(lFileHandle)
```

---

## 5.6 Suscripción a alarmas

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNetSDK
    participant Dev as Equipo
    participant CB as OnAlarm (hilo SDK)
    participant Q as Cola de eventos App

    App->>ZZ: SetDVRMessCallBack(OnAlarm, this)
    Note over App,ZZ: un solo callback para todos los equipos
    App->>ZZ: StartListenEx(lLoginID)
    ZZ->>Dev: suscripción de alarmas (inferido)
    Dev-->>ZZ: OK
    ZZ-->>App: TRUE
    Dev-->>ZZ: evento de movimiento en canal 3
    ZZ->>CB: OnAlarm(0x2102, lLoginID, pBuf[canales], len, ip, port, this)
    CB->>Q: push(equipo, tipo, canales activos)
    Dev-->>ZZ: entrada de alarma 1 activa
    ZZ->>CB: OnAlarm(0x2101, ...)
    CB->>Q: push(...)
    opt confirmar alarma (SetDVRMessCallBackEx1)
        Q-->>App: evento con bAlarmAckFlag y nEventID
        App->>ZZ: ControlDevice(lLoginID, ZZ_CTRL_ALARM_ACK, ...) fuera del callback
    end
    App->>ZZ: StopListen(lLoginID)
```

---

## 5.7 Eventos inteligentes (IVS) con imagen

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNetSDK
    participant Dev as Cámara IVS / NVR AI
    participant CB as OnAnalyzer (hilo SDK)

    App->>ZZ: RealLoadPictureEx(lLoginID, canal, ZZ_EVENT_IVS_ALL, TRUE, OnAnalyzer, this, NULL)
    ZZ->>Dev: suscripción a eventos inteligentes
    ZZ-->>App: lAnalyzerHandle
    Dev-->>ZZ: evento cruce de línea + JPEG
    ZZ->>CB: OnAnalyzer(handle, 0x02 CROSSLINE, pAlarmInfo, jpeg, len, this, seq)
    CB-->>CB: castear pAlarmInfo a la estructura del evento
    CB-->>CB: copiar JPEG y metadatos a cola
    Dev-->>ZZ: evento rostro reconocido + imágenes
    ZZ->>CB: OnAnalyzer(handle, FACERECOGNITION, info, buf, len, this, seq)
    App->>ZZ: StopLoadPic(lAnalyzerHandle)
```

`nSequence` indica la posición de la imagen cuando un mismo evento trae varias (0 primera, 1 intermedia, 2 última, en la convención Dahua *(inferido)*).

---

## 5.8 Captura remota (snapshot del equipo)

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNetSDK
    participant Dev as Equipo
    participant CB as OnSnap (hilo SDK)

    App->>ZZ: SetSnapRevCallBack(OnSnap, this)
    App->>ZZ: SnapPicture(lLoginID, {Channel=0, Quality=6, mode=0, CmdSerial=42})
    ZZ-->>ZZ: copia ZZSNAP_PARAMS y pone Reserved en 0
    ZZ->>Dev: CLIENT_SnapPicture
    Dev-->>ZZ: JPEG
    ZZ->>CB: OnSnap(lLoginID, buf, len, EncodeType=10, CmdSerial=42, this)
    CB-->>App: guardar /data/snap_42.jpg
```

---

## 5.9 Control PTZ

```mermaid
sequenceDiagram
    autonumber
    participant Op as Operador
    participant App
    participant ZZ as ZZNetSDK
    participant NetSDK
    participant Dev as Domo PTZ

    Op->>App: presiona flecha izquierda
    App->>ZZ: ZZPTZControlEx(lLoginID, canal, ZZ_PTZ_LEFT_CONTROL, 0, 4, 0, FALSE)
    ZZ->>NetSDK: CLIENT_DHPTZControlEx(...)
    NetSDK->>Dev: comando PTZ start
    Op->>App: suelta la flecha
    App->>ZZ: ZZPTZControlEx(lLoginID, canal, ZZ_PTZ_LEFT_CONTROL, 0, 4, 0, TRUE)
    NetSDK->>Dev: comando PTZ stop
    Op->>App: ir al preset 5
    App->>ZZ: ZZPTZControlEx(lLoginID, canal, ZZ_PTZ_POINT_MOVE_CONTROL, 0, 5, 0, FALSE)
    Op->>App: autofoco
    App->>ZZ: FocusControl(lLoginID, canal, 2, 0, 0, NULL, 500)
```

---

## 5.10 Registro activo (el equipo se conecta al servidor)

Útil cuando los equipos están detrás de NAT/CGNAT sin IP pública: el equipo se configura con la IP/puerto del servidor y abre la conexión hacia afuera.

```mermaid
sequenceDiagram
    autonumber
    participant App as Servidor App
    participant ZZ as ZZNetSDK
    participant CB as OnService (hilo SDK)
    participant Dev as Equipo remoto (NAT)

    App->>ZZ: ListenServer("0.0.0.0", 9500, 0, OnService, this)
    ZZ-->>App: lServerHandle
    Note over Dev: Configuración del equipo: Red > Registro<br/>IP servidor, puerto 9500, ID de equipo
    Dev->>ZZ: conexión TCP saliente a 9500
    ZZ->>CB: OnService(lServerHandle, ipDev, portDev, lCommand=1 SERIAL_RETURN, "SN o ID", len, this)
    CB-->>App: encolar(ipDev, portDev, SN)
    Note over CB,App: no hacer login dentro del callback
    App->>ZZ: LoginEx(ipDev, portDev, user, pass, nSpecCap=2, "SN o ID", &info, &err)
    ZZ-->>App: lLoginID (sobre la conexión ya establecida)
    App->>ZZ: RealPlayEx / StartListenEx / ...
    Dev--xZZ: se corta el enlace
    ZZ->>CB: OnService(..., lCommand=-1 DISCONNECT, ...)
    App->>ZZ: Logout(lLoginID)
    App->>ZZ: StopListenServer(lServerHandle)
```

---

## 5.11 Login P2P

`nSpecCap = 19` (`EM_ZZ_LOGIN_SPEC_CAP_P2P`) está disponible en la API, con `pCapParam = NULL`. **El paquete no incluye una biblioteca de túnel P2P** (cliente de la nube P2P de Dahua). Pruebas realizadas:

- `LoginEx("127.0.0.1", 37777, ..., 19, NULL, ...)` → se comporta como un login TCP: intenta conectar a esa IP/puerto y falla por timeout (`0x80000066`).
- `LoginEx("<número de serie>", ..., 19, ...)` → también `0x80000066`: el NetSDK **no** resuelve números de serie por sí mismo.

Conclusión: en este SDK el modo P2P es un **login sobre un túnel ya establecido** por otro componente, que expone el equipo en una IP/puerto local. El NetSDK marca la sesión como P2P (ajusta keep-alive/tiempos y el uso de sub-conexiones) *(inferido)*. Flujo típico:

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant P2P as Componente de túnel P2P (externo, no incluido)
    participant Cloud as Servidor P2P / relay
    participant Dev as Equipo con P2P habilitado
    participant ZZ as ZZNetSDK

    App->>P2P: iniciar(serverP2P, credenciales de nube)
    P2P->>Cloud: registrar cliente
    App->>P2P: abrir túnel(SN del equipo, puerto remoto 37777)
    P2P->>Cloud: solicitar conexión a SN
    Cloud->>Dev: notificar (el equipo mantiene conexión saliente con la nube)
    Dev-->>P2P: hole punching UDP o relay
    P2P-->>App: puerto local mapeado, por ejemplo 127.0.0.1:40001
    App->>ZZ: LoginEx("127.0.0.1", 40001, user, pass, nSpecCap=19, NULL, &info, &err)
    ZZ->>P2P: tráfico DVRIP por el túnel local
    P2P->>Dev: tráfico encapsulado
    ZZ-->>App: lLoginID
    App->>ZZ: RealPlayEx(lLoginID, 0, NULL, ZZ_RType_Realplay_1)
    Note over App,Dev: preferir sub-flujo: el ancho de banda del relay suele ser limitado
    App->>ZZ: Logout(lLoginID)
    App->>P2P: cerrar túnel
```

Alternativas cuando no se dispone de un componente P2P: **registro activo** (§5.10) o VPN.

---

## 5.12 Descubrimiento en LAN, cambio de IP e inicialización

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNetSDK
    participant CB as OnDevice (hilo SDK)
    participant LAN as Equipos en la LAN

    App->>ZZ: StartSearchDevices(OnDevice, ctx, NULL)
    ZZ->>LAN: multicast/broadcast de búsqueda (UDP)
    ZZ-->>App: lSearchHandle
    LAN-->>ZZ: respuestas
    ZZ->>CB: OnDevice(ZZDEVICE_NET_INFO_EX con IP, MAC, SN, tipo, byInitStatus)
    CB-->>App: agregar a la lista
    App->>ZZ: StopSearchDevices(lSearchHandle)
    alt equipo no inicializado
        App->>ZZ: InitDevAccount({MAC, usuario admin, nueva clave, ...}, &out, 5000, NULL)
        ZZ->>LAN: inicialización por multicast
        ZZ-->>App: TRUE
    end
    opt cambiar IP
        App->>ZZ: ModifyDevice(&info modificado, 5000, &err, NULL, NULL)
        ZZ-->>App: TRUE o ZZNET_ERROR_NEED_ENCRYPTION_PASSWORD
    end
    App->>ZZ: LoginEx(nuevaIP, 37777, "admin", nuevaClave, 0, ...)
```

Se verificó que `StartSearchDevices` devuelve un handle válido y dispara la carga dinámica de `libavnetsdk.so`, `libdhconfigsdk.so` y `libcurl.so` (ver [03 §3.4](03-arquitectura.md)).

---

## 5.13 Lectura/escritura de configuración JSON

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNetSDK
    participant NetSDK
    participant CFG as ConfigSDK
    participant Dev as Equipo

    App->>ZZ: GetNewDevConfig(lLoginID, "Encode", canal, bufJson, 64KB, &err, 3000)
    ZZ->>NetSDK: CLIENT_GetNewDevConfig
    NetSDK->>Dev: configManager.getConfig Encode (protocolo 37777)
    Dev-->>NetSDK: JSON
    ZZ-->>App: bufJson
    App->>ZZ: ParseData("Encode", bufJson, &ZZ_CFG_ENCODE_INFO, sizeof, NULL)
    ZZ->>CFG: CLIENT_ParseData
    CFG-->>App: estructura completa
    App->>App: cambiar bitrate / resolución / fps
    App->>ZZ: PacketData("Encode", &estructura, sizeof, bufJson, 64KB)
    ZZ->>CFG: CLIENT_PacketData
    CFG-->>App: JSON nuevo
    App->>ZZ: SetNewDevConfig(lLoginID, "Encode", canal, bufJson, len, &err, &restart, 3000)
    ZZ->>NetSDK: CLIENT_SetNewDevConfig
    NetSDK->>Dev: configManager.setConfig
    Dev-->>App: TRUE, restart = 0 o 1
    opt restart == 1
        App->>ZZ: RebootDev(lLoginID)
    end
```

---

## 5.14 Exportación e importación de configuración (lógica propia ZZ, verificada)

Secuencias reconstruidas del desensamblado y **confirmadas** ejecutando el SDK contra un servidor HTTP que emula el CGI de Dahua (se registraron las peticiones reales).

### Exportación

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNETSDK_ExportConfig
    participant DC as DevConfig
    participant Curl as libcurl (embebido)
    participant Dev as Equipo HTTP :80

    App->>ZZ: ExportConfig(&param{IP, user, pass, nConfigNum=3, [NTP, Locales, DVRIP]}, &out{pBuf, nBufLen})
    ZZ->>DC: DevConfig() y ExportConfig(param, out)
    loop por cada configs[i]
        DC->>DC: EM_ZZ_CONFIG_TYPE a nombre, por ejemplo NTP
        DC->>Curl: GET http://IP/cgi-bin/configManager.cgi?action=getConfig&name=NTP
        Note over Curl,Dev: Authorization Basic base64(user:pass) preventivo<br/>connect 2 s, total 7 s
        Curl->>Dev: petición
        Dev-->>Curl: 200 table.NTP.Address=...\r\ntable.NTP.Enable=true...
        Curl-->>DC: texto
        DC->>DC: json[NTP] = texto
    end
    DC->>DC: json.dump() y copiar a out.pBuf, out.nRetLen
    ZZ-->>App: TRUE, JSON en pBuf
```

Peticiones capturadas:

```text
GET /cgi-bin/configManager.cgi?action=getConfig&name=NTP     AUTH=Basic YWRtaW46YWRtaW4xMjM=
GET /cgi-bin/configManager.cgi?action=getConfig&name=Locales AUTH=Basic YWRtaW46YWRtaW4xMjM=
GET /cgi-bin/configManager.cgi?action=getConfig&name=DVRIP   AUTH=Basic YWRtaW46YWRtaW4xMjM=
```

### Importación

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNETSDK_ImportConfig
    participant DC as DevConfig
    participant Dev as Equipo HTTP :80

    App->>ZZ: ImportConfig(&param{IP, user, pass}, "backup.json")
    ZZ->>DC: ImportConfig
    DC->>DC: ReadFileContent y parse JSON
    loop por cada sección del archivo (orden alfabético)
        DC->>Dev: GET getConfig&name=Seccion
        Dev-->>DC: configuración actual
        DC->>DC: ParseConfig de ambos y CheckDiffConfig
        DC->>DC: acumular claves con valor distinto
    end
    DC->>DC: separar claves normales y claves de reinicio (IsRebootConfig)
    opt hay cambios normales
        DC->>Dev: GET setConfig&Locales.TimeFormat=dd/MM/yyyy%20HH:mm&NTP.Address=time.google.com&NTP.Port=124
        Dev-->>DC: 200 OK
    end
    opt hay cambios de reinicio (DVRIP.TCPPort, Web.Port, Https.*, VideoStandard...)
        DC->>Dev: GET setConfig&DVRIP.TCPPort=37779
        Dev-->>DC: 200 OK
    end
    ZZ-->>App: TRUE
```

Peticiones capturadas (sólo se envían las diferencias; las claves iguales no viajan):

```text
GET /cgi-bin/configManager.cgi?action=getConfig&name=DVRIP
GET /cgi-bin/configManager.cgi?action=getConfig&name=Locales
GET /cgi-bin/configManager.cgi?action=getConfig&name=NTP
GET /cgi-bin/configManager.cgi?action=setConfig&NTP.Address=time.google.com
GET /cgi-bin/configManager.cgi?action=setConfig&DVRIP.TCPPort=37779        <- clave de reinicio, al final
```

---

## 5.15 Audio bidireccional (intercomunicador)

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNetSDK
    participant Dev as Equipo con audio
    participant CB as OnAudio (hilo SDK)

    App->>ZZ: SetDeviceMode(lLoginID, ZZ_TALK_ENCODE_TYPE, &{G711a, 8000 Hz, 16 bit})
    App->>ZZ: SetDeviceMode(lLoginID, ZZ_TALK_CLIENT_MODE, NULL)
    App->>ZZ: StartTalkEx(lLoginID, OnAudio, this)
    ZZ->>Dev: abre canal de audio
    ZZ-->>App: lTalkHandle
    alt modo cliente (el SDK captura el micrófono)
        App->>ZZ: RecordStart()
        loop
            ZZ->>CB: OnAudio(lTalkHandle, pcm local, len, byAudioFlag=0)
            CB->>ZZ: TalkSendData(lTalkHandle, buf, len)
        end
    else modo servidor (la app entrega el audio)
        loop
            App->>ZZ: TalkSendData(lTalkHandle, audio codificado, len)
        end
    end
    Dev-->>ZZ: audio del equipo
    ZZ->>CB: OnAudio(lTalkHandle, buf, len, byAudioFlag=1)
    CB->>ZZ: AudioDec(buf, len) reproducir localmente
    App->>ZZ: RecordStop()
    App->>ZZ: StopTalkEx(lTalkHandle)
```

> Llamar `TalkSendData` desde el callback es el patrón clásico del NetSDK de Dahua para el modo cliente; es la única excepción habitual a la regla de "no llamar al SDK dentro de callbacks" *(inferido de la documentación general de Dahua)*.

---

## 5.16 Actualización de firmware

```mermaid
sequenceDiagram
    autonumber
    participant App
    participant ZZ as ZZNetSDK
    participant Dev as Equipo
    participant CB as OnUpgrade (hilo SDK)

    App->>ZZ: StartUpgradeEx(lLoginID, ZZ_UPGRADE_BIOS_TYPE, "/fw/IPC.bin", OnUpgrade, this)
    ZZ-->>App: lUpgradeID
    App->>ZZ: SendUpgrade(lUpgradeID)
    loop envío
        ZZ->>Dev: bloques del archivo
        ZZ->>CB: OnUpgrade(lLoginID, id, total=XX, enviado=YY)
    end
    loop grabación en flash
        ZZ->>CB: OnUpgrade(..., total=-1, progreso)
    end
    alt éxito
        ZZ->>CB: OnUpgrade(..., total=0, enviado=-1)
    else error
        ZZ->>CB: OnUpgrade(..., total=0, enviado=-2)
    else sin permiso
        ZZ->>CB: OnUpgrade(..., total=0, enviado=-3)
    end
    App->>ZZ: StopUpgrade(lUpgradeID)
    Dev--xZZ: el equipo reinicia
    ZZ->>App: OnDisconnect(lLoginID, ...)
```
