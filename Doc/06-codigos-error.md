# 6. Códigos de error

[← Índice](README.md)

## 6.1 Cómo obtener el error

Toda función que devuelve `FALSE` o un handle `0` deja un código en `ZZNETSDK_GetLastError()`. Los códigos se construyen con la macro:

```c
#define _ZZEC(x)  (0x80000000 | x)
```

Por lo tanto un error se imprime cómodamente en hexadecimal: `printf("0x%08X", ZZNETSDK_GetLastError());` y el número `x` se obtiene con `err & 0x7FFFFFFF`.

```cpp
static const char* zzErrorStr(DWORD e) {
    switch (e) {
        case ZZNET_NOERROR:               return "Sin error";
        case ZZNET_NETWORK_ERROR:         return "Error de red / timeout";
        case ZZNET_INVALID_HANDLE:        return "Handle inválido";
        case ZZNET_LOGIN_ERROR_PASSWORD:  return "Contraseña incorrecta";
        case ZZNET_LOGIN_ERROR_TIMEOUT:   return "Timeout de login";
        // ...
        default:                          return "Ver tabla 6.4";
    }
}
```

## 6.2 Errores de `LoginEx` (parámetro `*error`)

Además de `GetLastError`, `ZZNETSDK_LoginEx` devuelve un código corto en `*error`. Valores observados/convención del NetSDK de Dahua *(los valores 1-19 corresponden a la convención Dahua; el valor 3 fue verificado en pruebas)*:

| `*error` | Significado | `GetLastError` asociado |
|---|---|---|
| 1 | Contraseña incorrecta | `0x80000064` `ZZNET_LOGIN_ERROR_PASSWORD` |
| 2 | El usuario no existe | `0x80000065` `ZZNET_LOGIN_ERROR_USER` |
| 3 | Timeout esperando respuesta (**verificado**) | `0x80000066` `ZZNET_LOGIN_ERROR_TIMEOUT` |
| 4 | La cuenta ya tiene sesión iniciada | `0x80000067` `ZZNET_LOGIN_ERROR_RELOGGIN` |
| 5 | Cuenta bloqueada | `0x80000068` `ZZNET_LOGIN_ERROR_LOCKED` |
| 6 | Cuenta en lista negra | `0x80000069` `ZZNET_LOGIN_ERROR_BLACKLIST` |
| 7 | Recursos insuficientes / equipo ocupado | `0x8000006A` `ZZNET_LOGIN_ERROR_BUSY` |
| 8 | Falló la sub-conexión (video) | `0x8000006D` `ZZNET_LOGIN_ERROR_SUBCONNECT` |
| 9 | Falló la conexión principal | `0x8000006C` `ZZNET_LOGIN_ERROR_NETWORK` |
| 10 | Se superó el máximo de conexiones | `0x8000006E` `ZZNET_LOGIN_ERROR_MAXCONNECT` |
| 11 | Sólo soporta protocolo de 3.ª generación | `0x8000006F` `ZZNET_LOGIN_ERROR_PROTOCOL3_ONLY` |
| 12 | Falta la U-Key o es inválida | `0x80000070` `ZZNET_LOGIN_ERROR_UKEY_LOST` |
| 13 | La IP del cliente no tiene permiso | `0x80000071` `ZZNET_LOGIN_ERROR_NO_AUTHORIZED` |
| 18 | Equipo no inicializado | `0x80000076` `ZZNET_LOGIN_ERROR_DEVICE_NOT_INIT` |
| 19 | Login restringido (IP, horario, vigencia) | `0x80000077` `ZZNET_LOGIN_ERROR_LIMITED` |

## 6.3 Errores más frecuentes (en español)

| Hex | Constante | Significado | Acción sugerida |
|---|---|---|---|
| `0x80000001` | `ZZNET_SYSTEM_ERROR` | Error del sistema | Revisar recursos del host (memoria, descriptores) |
| `0x80000002` | `ZZNET_NETWORK_ERROR` | Error de red, normalmente timeout | Conectividad, firewall, aumentar `waittime` |
| `0x80000003` | `ZZNET_DEV_VER_NOMATCH` | Protocolo del equipo no coincide | Actualizar firmware / SDK |
| `0x80000004` | `ZZNET_INVALID_HANDLE` | Handle inválido | Handle ya cerrado o de otro login |
| `0x80000005` | `ZZNET_OPEN_CHANNEL_ERROR` | No se pudo abrir el canal | Canal inexistente, sin permiso, sin recursos |
| `0x80000007` | `ZZNET_ILLEGAL_PARAM` | Parámetro inválido | Revisar punteros, tamaños, `dwSize` |
| `0x80000008` | `ZZNET_SDK_INIT_ERROR` | Error al inicializar el SDK | Dependencias no cargadas |
| `0x8000000A` | `ZZNET_RENDER_OPEN_ERROR` | No se pudo abrir el render | Usar `hWnd=NULL` en servidores |
| `0x8000000B` | `ZZNET_DEC_OPEN_ERROR` | No se pudo abrir el decodificador | PlaySDK no disponible |
| `0x80000011` | `ZZNET_REAL_ALREADY_SAVING` | Ya se está guardando el flujo | — |
| `0x80000016` | `ZZNET_INSUFFICIENT_BUFFER` | Buffer insuficiente | Aumentar el tamaño del buffer de salida |
| `0x80000017` | `ZZNET_NOT_SUPPORTED` | El SDK no soporta la función | — |
| `0x80000018` | `ZZNET_NO_RECORD_FOUND` | No se encontraron grabaciones | Revisar rango/tipo/canal |
| `0x80000019` | `ZZNET_NOT_AUTHORIZED` | Operación no autorizada | Permisos del usuario |
| `0x8000001A` | `ZZNET_NOT_NOW` | No se puede ejecutar ahora | Reintentar |
| `0x8000001D` | `ZZNET_NO_INIT` | SDK no inicializado | Llamar `ZZNETSDK_Init` primero |
| `0x8000001E` | `ZZNET_DOWNLOAD_END` | Descarga terminada | Normal |
| `0x8000001F` | `ZZNET_EMPTY_LIST` | Resultado vacío | Normal |
| `0x8000004F` | `ZZNET_UNSUPPORTED` | El equipo no soporta la operación | Consultar `GetDevCaps` |
| `0x80000050` | `ZZNET_DEVICE_BUSY` | Recursos del equipo insuficientes | Cerrar flujos, usar sub-flujo |
| `0x80000051` | `ZZNET_SERVER_STARTED` | El servidor ya está iniciado | `ListenServer` duplicado |
| `0x80000052` | `ZZNET_SERVER_STOPPED` | El servidor no se inició | — |
| `0x80000056` | `ZZNET_USER_FLASEPWD_TRYTIME` | Se superaron los intentos de contraseña | Esperar desbloqueo |
| `0x80000063` | `ZZNET_LOGIN_ERROR_PASSWORD_EXPIRED` | Contraseña vencida | Cambiarla (`OperateUserInfoNew`) |
| `0x80000075` | `ZZNET_LOGIN_ERROR_USER_OR_PASSOWRD` | Usuario o contraseña incorrectos | — |
| `0x80000135` | `ZZNET_CONFIG_DEVBUSY` | No se puede configurar ahora | Reintentar |
| `0x80000136` | `ZZNET_CONFIG_DATAILLEGAL` | Datos de configuración inválidos | Validar valores |
| `0x80000177` | `ZZNET_ERROR_TALK_REJECT` | Intercomunicador rechazado | — |
| `0x80000178` | `ZZNET_ERROR_TALK_OPENED` | Intercomunicador abierto por otro cliente | — |
| `0x80000182` | `ZZNET_ERROR_JSON_REQUEST` | JSON generado inválido | Revisar `PacketData` |
| `0x80000183` | `ZZNET_ERROR_JSON_RESPONSE` | JSON de respuesta inválido | — |
| `0x8000018D` | `ZZNET_ERROR_OPERATION_OVERTIME` | Operación con timeout | Aumentar `waittime` |
| `0x80000190` | `ZZNET_ERROR_UNSUPPORTED` | Operación no soportada | — |
| `0x8000019F` | `ZZNET_ERROR_UPGRADE_FAILED` | Falló la actualización | Verificar archivo de firmware |
| `0x800001A7` | `ZZNET_ERROR_PARAM_DWSIZE_ERROR` | Campo `dwSize` incorrecto | `stru.dwSize = sizeof(stru)` |
| `0x80000200` | `ZZNET_USER_PWD_NOT_AUTHORIZED` | Sin permiso para cambiar contraseña | — |
| `0x80000201` | `ZZNET_USER_PWD_NOT_STRONG` | Contraseña débil | Mayúsculas, minúsculas, números, símbolos |
| `0x80000202` | `ZZNET_ERROR_NO_SUCH_CONFIG` | No existe esa configuración | — |
| `0x80000207` | `ZZNET_ERROR_NEED_ENCRYPTION_PASSWORD` | Se requiere contraseña para cambiar la IP | Completar la clave en `ModifyDevice` |
| `0x80000209` | `ZZNET_ERROR_DEVICE_IN_UPGRADING` | Equipo actualizándose | Esperar |
| `0x800003F9` | `ZZNET_ERROR_DEVICE_ALREADY_INIT` | Equipo ya inicializado | Hacer login normal |
| `0x80000418` | `ZZNET_ERROR_DEFULAT_SEARCH_PORT` | Puertos de búsqueda por defecto (5050, 37810) no disponibles | Liberar puertos / otra instancia corriendo |
| `0x80000453` | `ZZNET_ERROR_STREAMCONVERTOR_DEFECT` | Falta la biblioteca de transcodificación | `libStreamConvertor.so` no incluida |

## 6.4 Tabla completa

Generada automáticamente desde `ZZGlobal.h` (576 códigos). Se conserva la descripción original del fabricante.

| Hex | Dec (x) | Constante | Descripción original (inglés, del fabricante) |
|---|---|---|---|
| `0` | — | `ZZNET_NOERROR` | No Error |
| `-1` | — | `ZZNET_ERROR` | Unknown Error |
| `0x80000001` | 1 | `ZZNET_SYSTEM_ERROR` | System Error |
| `0x80000002` | 2 | `ZZNET_NETWORK_ERROR` | Network Error, likely due to network timeout |
| `0x80000003` | 3 | `ZZNET_DEV_VER_NOMATCH` | Device Protocol Mismatch |
| `0x80000004` | 4 | `ZZNET_INVALID_HANDLE` | Invalid Handle |
| `0x80000005` | 5 | `ZZNET_OPEN_CHANNEL_ERROR` | Open Channel Failed |
| `0x80000006` | 6 | `ZZNET_CLOSE_CHANNEL_ERROR` | Close Channel Failed |
| `0x80000007` | 7 | `ZZNET_ILLEGAL_PARAM` | User Parameter Illegal |
| `0x80000008` | 8 | `ZZNET_SDK_INIT_ERROR` | SDK Init Error |
| `0x80000009` | 9 | `ZZNET_SDK_UNINIT_ERROR` | SDK Cleanup Error |
| `0x8000000A` | 10 | `ZZNET_RENDER_OPEN_ERROR` | Request Render Resource Error |
| `0x8000000B` | 11 | `ZZNET_DEC_OPEN_ERROR` | Open Decode Library Error |
| `0x8000000C` | 12 | `ZZNET_DEC_CLOSE_ERROR` | Close Decode Library Error |
| `0x8000000D` | 13 | `ZZNET_MULTIPLAY_NOCHANNEL` | No channels detected in multi-play preview |
| `0x8000000E` | 14 | `ZZNET_TALK_INIT_ERROR` | Talk Library Init Failed |
| `0x8000000F` | 15 | `ZZNET_TALK_NOT_INIT` | Talk Library Not Initialized |
| `0x80000010` | 16 | `ZZNET_TALK_SENDDATA_ERROR` | Send Audio Data Error |
| `0x80000011` | 17 | `ZZNET_REAL_ALREADY_SAVING` | Real-time data is already being saved |
| `0x80000012` | 18 | `ZZNET_NOT_SAVING` | Not saving real-time data |
| `0x80000013` | 19 | `ZZNET_OPEN_FILE_ERROR` | Open File Error |
| `0x80000014` | 20 | `ZZNET_PTZ_SET_TIMER_ERROR` | Start PTZ control timer failed |
| `0x80000015` | 21 | `ZZNET_RETURN_DATA_ERROR` | Validation of returned data failed |
| `0x80000016` | 22 | `ZZNET_INSUFFICIENT_BUFFER` | Insufficient Buffer |
| `0x80000017` | 23 | `ZZNET_NOT_SUPPORTED` | Current SDK does not support this function |
| `0x80000018` | 24 | `ZZNET_NO_RECORD_FOUND` | No recording found |
| `0x80000019` | 25 | `ZZNET_NOT_AUTHORIZED` | Unauthorized operation |
| `0x8000001A` | 26 | `ZZNET_NOT_NOW` | Cannot execute now |
| `0x8000001B` | 27 | `ZZNET_NO_TALK_CHANNEL` | Talk channel not found |
| `0x8000001C` | 28 | `ZZNET_NO_AUDIO` | Audio not found |
| `0x8000001D` | 29 | `ZZNET_NO_INIT` | Network SDK Not Initialized |
| `0x8000001E` | 30 | `ZZNET_DOWNLOAD_END` | Download Ended |
| `0x8000001F` | 31 | `ZZNET_EMPTY_LIST` | Query Result Empty |
| `0x80000020` | 32 | `ZZNET_ERROR_GETCFG_SYSATTR` | Get System Attribute Config Failed |
| `0x80000021` | 33 | `ZZNET_ERROR_GETCFG_SERIAL` | Get Serial Number Failed |
| `0x80000022` | 34 | `ZZNET_ERROR_GETCFG_GENERAL` | Get General Attribute Failed |
| `0x80000023` | 35 | `ZZNET_ERROR_GETCFG_DSPCAP` | Get DSP Capability Description Failed |
| `0x80000024` | 36 | `ZZNET_ERROR_GETCFG_NETCFG` | Get Network Config Failed |
| `0x80000025` | 37 | `ZZNET_ERROR_GETCFG_CHANNAME` | Get Channel Name Failed |
| `0x80000026` | 38 | `ZZNET_ERROR_GETCFG_VIDEO` | Get Video Attribute Failed |
| `0x80000027` | 39 | `ZZNET_ERROR_GETCFG_RECORD` | Get Record Config Failed |
| `0x80000028` | 40 | `ZZNET_ERROR_GETCFG_PRONAME` | Get Decoder Protocol Name Failed |
| `0x80000029` | 41 | `ZZNET_ERROR_GETCFG_FUNCNAME` | Get 232 Serial Port Function Name Failed |
| `0x8000002A` | 42 | `ZZNET_ERROR_GETCFG_485DECODER` | Get Decoder Attribute Failed |
| `0x8000002B` | 43 | `ZZNET_ERROR_GETCFG_232COM` | Get 232 Serial Port Config Failed |
| `0x8000002C` | 44 | `ZZNET_ERROR_GETCFG_ALARMIN` | Get External Alarm Input Config Failed |
| `0x8000002D` | 45 | `ZZNET_ERROR_GETCFG_ALARMDET` | Get Motion Detection Alarm Failed |
| `0x8000002E` | 46 | `ZZNET_ERROR_GETCFG_SYSTIME` | Get Device Time Failed |
| `0x8000002F` | 47 | `ZZNET_ERROR_GETCFG_PREVIEW` | Get Preview Parameters Failed |
| `0x80000030` | 48 | `ZZNET_ERROR_GETCFG_AUTOMT` | Get Auto Maintenance Config Failed |
| `0x80000031` | 49 | `ZZNET_ERROR_GETCFG_VIDEOMTRX` | Get Video Matrix Config Failed |
| `0x80000032` | 50 | `ZZNET_ERROR_GETCFG_COVER` | Get Region Mask Config Failed |
| `0x80000033` | 51 | `ZZNET_ERROR_GETCFG_WATERMAKE` | Get Image Watermark Config Failed |
| `0x80000034` | 52 | `ZZNET_ERROR_GETCFG_MULTICAST` | Get Config Failed Position: Multicast Port Configured by Channel |
| `0x80000037` | 55 | `ZZNET_ERROR_SETCFG_GENERAL` | Modify General Attribute Failed |
| `0x80000038` | 56 | `ZZNET_ERROR_SETCFG_NETCFG` | Modify Network Config Failed |
| `0x80000039` | 57 | `ZZNET_ERROR_SETCFG_CHANNAME` | Modify Channel Name Failed |
| `0x8000003A` | 58 | `ZZNET_ERROR_SETCFG_VIDEO` | Modify Video Attribute Failed |
| `0x8000003B` | 59 | `ZZNET_ERROR_SETCFG_RECORD` | Modify Record Config Failed |
| `0x8000003C` | 60 | `ZZNET_ERROR_SETCFG_485DECODER` | Modify Decoder Attribute Failed |
| `0x8000003D` | 61 | `ZZNET_ERROR_SETCFG_232COM` | Modify 232 Serial Port Config Failed |
| `0x8000003E` | 62 | `ZZNET_ERROR_SETCFG_ALARMIN` | Modify External Input Alarm Config Failed |
| `0x8000003F` | 63 | `ZZNET_ERROR_SETCFG_ALARMDET` | Modify Motion Detection Alarm Config Failed |
| `0x80000040` | 64 | `ZZNET_ERROR_SETCFG_SYSTIME` | Modify Device Time Failed |
| `0x80000041` | 65 | `ZZNET_ERROR_SETCFG_PREVIEW` | Modify Preview Parameters Failed |
| `0x80000042` | 66 | `ZZNET_ERROR_SETCFG_AUTOMT` | Modify Auto Maintenance Config Failed |
| `0x80000043` | 67 | `ZZNET_ERROR_SETCFG_VIDEOMTRX` | Modify Video Matrix Config Failed |
| `0x80000044` | 68 | `ZZNET_ERROR_SETCFG_COVER` | Modify Region Mask Config Failed |
| `0x80000045` | 69 | `ZZNET_ERROR_SETCFG_WATERMAKE` | Modify Image Watermark Config Failed |
| `0x80000046` | 70 | `ZZNET_ERROR_SETCFG_WLAN` | Modify Wireless Network Info Failed |
| `0x80000047` | 71 | `ZZNET_ERROR_SETCFG_WLANDEV` | Select Wireless Network Device Failed |
| `0x80000048` | 72 | `ZZNET_ERROR_SETCFG_REGISTER` | Modify Active Registration Parameter Config Failed |
| `0x80000049` | 73 | `ZZNET_ERROR_SETCFG_CAMERA` | Modify Camera Attribute Config Failed |
| `0x8000004A` | 74 | `ZZNET_ERROR_SETCFG_INFRARED` | Modify Infrared Alarm Config Failed |
| `0x8000004B` | 75 | `ZZNET_ERROR_SETCFG_SOUNDALARM` | Modify Audio Alarm Config Failed |
| `0x8000004C` | 76 | `ZZNET_ERROR_SETCFG_STORAGE` | Modify Storage Location Config Failed |
| `0x8000004D` | 77 | `ZZNET_AUDIOENCODE_NOTINIT` | Audio Encode Interface Not Successfully Initialized |
| `0x8000004E` | 78 | `ZZNET_DATA_TOOLONGH` | Data Too Long |
| `0x8000004F` | 79 | `ZZNET_UNSUPPORTED` | Device Does Not Support This Operation |
| `0x80000050` | 80 | `ZZNET_DEVICE_BUSY` | Device Resource Insufficient |
| `0x80000051` | 81 | `ZZNET_SERVER_STARTED` | Server Already Started |
| `0x80000052` | 82 | `ZZNET_SERVER_STOPPED` | Server Not Started Successfully Yet |
| `0x80000053` | 83 | `ZZNET_LISTER_INCORRECT_SERIAL` | Input Serial Number Incorrect |
| `0x80000054` | 84 | `ZZNET_QUERY_DISKINFO_FAILED` | Get Hard Disk Info Failed |
| `0x80000055` | 85 | `ZZNET_ERROR_GETCFG_SESSION` | Get Connection Session Info |
| `0x80000056` | 86 | `ZZNET_USER_FLASEPWD_TRYTIME` | Input Password Error Exceeds Limit |
| `0x80000063` | 99 | `ZZNET_LOGIN_ERROR_PASSWORD_EXPIRED` | Password Expired |
| `0x80000064` | 100 | `ZZNET_LOGIN_ERROR_PASSWORD` | Password Incorrect |
| `0x80000065` | 101 | `ZZNET_LOGIN_ERROR_USER` | Account Not Exist |
| `0x80000066` | 102 | `ZZNET_LOGIN_ERROR_TIMEOUT` | Wait Login Return Timeout |
| `0x80000067` | 103 | `ZZNET_LOGIN_ERROR_RELOGGIN` | Account Already Logged In |
| `0x80000068` | 104 | `ZZNET_LOGIN_ERROR_LOCKED` | Account Locked |
| `0x80000069` | 105 | `ZZNET_LOGIN_ERROR_BLACKLIST` | Account Blacklisted |
| `0x8000006A` | 106 | `ZZNET_LOGIN_ERROR_BUSY` | Insufficient Resources, System Busy |
| `0x8000006B` | 107 | `ZZNET_LOGIN_ERROR_CONNECT` | Network Connection Timeout, Please Check Network and Retry |
| `0x8000006C` | 108 | `ZZNET_LOGIN_ERROR_NETWORK` | Network Connection Failed |
| `0x8000006D` | 109 | `ZZNET_LOGIN_ERROR_SUBCONNECT` | Login Device Successful, But Cannot Create Video Channel, Please Check Network Status |
| `0x8000006E` | 110 | `ZZNET_LOGIN_ERROR_MAXCONNECT` | Exceeds Max Connection Count |
| `0x8000006F` | 111 | `ZZNET_LOGIN_ERROR_PROTOCOL3_ONLY` | Only Supports Generation 3 Protocol |
| `0x80000070` | 112 | `ZZNET_LOGIN_ERROR_UKEY_LOST` | U-Key Not Inserted or Info Error |
| `0x80000071` | 113 | `ZZNET_LOGIN_ERROR_NO_AUTHORIZED` | Client IP Address Has No Login Permission |
| `0x80000075` | 117 | `ZZNET_LOGIN_ERROR_USER_OR_PASSOWRD` | Account or Password Error |
| `0x80000076` | 118 | `ZZNET_LOGIN_ERROR_DEVICE_NOT_INIT` | Device Not Initialized, Cannot Login, Please Initialize Device First |
| `0x80000077` | 119 | `ZZNET_LOGIN_ERROR_LIMITED` | Login Restricted, possibly IP restriction, Time period restriction, Validity restriction |
| `0x80000078` | 120 | `ZZNET_RENDER_SOUND_ON_ERROR` | Render Library Open Audio Error |
| `0x80000079` | 121 | `ZZNET_RENDER_SOUND_OFF_ERROR` | Render Library Close Audio Error |
| `0x8000007A` | 122 | `ZZNET_RENDER_SET_VOLUME_ERROR` | Render Library Control Volume Error |
| `0x8000007B` | 123 | `ZZNET_RENDER_ADJUST_ERROR` | Render Library Set Image Parameters Error |
| `0x8000007C` | 124 | `ZZNET_RENDER_PAUSE_ERROR` | Render Library Pause Playback Error |
| `0x8000007D` | 125 | `ZZNET_RENDER_SNAP_ERROR` | Render Library Snapshot Error |
| `0x8000007E` | 126 | `ZZNET_RENDER_STEP_ERROR` | Render Library Step Error |
| `0x8000007F` | 127 | `ZZNET_RENDER_FRAMERATE_ERROR` | Render Library Set Frame Rate Error |
| `0x80000080` | 128 | `ZZNET_RENDER_DISPLAYREGION_ERROR` | Render Library Set Display Region Error |
| `0x80000081` | 129 | `ZZNET_RENDER_GETOSDTIME_ERROR` | Render Library Get Current Play Time Error |
| `0x8000008C` | 140 | `ZZNET_GROUP_EXIST` | Group Name Exists |
| `0x8000008D` | 141 | `ZZNET_GROUP_NOEXIST` | Group Name Not Exists |
| `0x8000008E` | 142 | `ZZNET_GROUP_RIGHTOVER` | Group Permissions Exceed Permission List Range |
| `0x8000008F` | 143 | `ZZNET_GROUP_HAVEUSER` | Group Has Users, Cannot Delete |
| `0x80000090` | 144 | `ZZNET_GROUP_RIGHTUSE` | Some Permission of Group In Use by User, Cannot Remove |
| `0x80000091` | 145 | `ZZNET_GROUP_SAMENAME` | New Group Name Duplicates Existing Group Name |
| `0x80000092` | 146 | `ZZNET_USER_EXIST` | User Exists |
| `0x80000093` | 147 | `ZZNET_USER_NOEXIST` | User Not Exists |
| `0x80000094` | 148 | `ZZNET_USER_RIGHTOVER` | User Permissions Exceed Group Permissions |
| `0x80000095` | 149 | `ZZNET_USER_PWD` | Reserved Account, Cannot Modify Password |
| `0x80000096` | 150 | `ZZNET_USER_FLASEPWD` | Password Incorrect |
| `0x80000097` | 151 | `ZZNET_USER_NOMATCHING` | Password Mismatch |
| `0x80000098` | 152 | `ZZNET_USER_INUSE` | Account In Use |
| `0x8000012C` | 300 | `ZZNET_ERROR_GETCFG_ETHERNET` | Get Network Card Config Failed |
| `0x8000012D` | 301 | `ZZNET_ERROR_GETCFG_WLAN` | Get Wireless Network Info Failed |
| `0x8000012E` | 302 | `ZZNET_ERROR_GETCFG_WLANDEV` | Get Wireless Network Device Failed |
| `0x8000012F` | 303 | `ZZNET_ERROR_GETCFG_REGISTER` | Get Active Registration Parameters Failed |
| `0x80000130` | 304 | `ZZNET_ERROR_GETCFG_CAMERA` | Get Camera Attributes Failed |
| `0x80000131` | 305 | `ZZNET_ERROR_GETCFG_INFRARED` | Get Infrared Alarm Config Failed |
| `0x80000132` | 306 | `ZZNET_ERROR_GETCFG_SOUNDALARM` | Get Audio Alarm Config Failed |
| `0x80000133` | 307 | `ZZNET_ERROR_GETCFG_STORAGE` | Get Storage Location Config Failed |
| `0x80000134` | 308 | `ZZNET_ERROR_GETCFG_MAIL` | Get Mail Config Failed |
| `0x80000135` | 309 | `ZZNET_CONFIG_DEVBUSY` | Temporarily Cannot Set |
| `0x80000136` | 310 | `ZZNET_CONFIG_DATAILLEGAL` | Config Data Illegal |
| `0x80000137` | 311 | `ZZNET_ERROR_GETCFG_DST` | Get Daylight Saving Time Config Failed |
| `0x80000138` | 312 | `ZZNET_ERROR_SETCFG_DST` | Set Daylight Saving Time Config Failed |
| `0x80000139` | 313 | `ZZNET_ERROR_GETCFG_VIDEO_OSD` | Get Video OSD Overlay Config Failed |
| `0x8000013A` | 314 | `ZZNET_ERROR_SETCFG_VIDEO_OSD` | Set Video OSD Overlay Config Failed |
| `0x8000013B` | 315 | `ZZNET_ERROR_GETCFG_GPRSCDMA` | Get CDMA\GPRS Network Config Failed |
| `0x8000013C` | 316 | `ZZNET_ERROR_SETCFG_GPRSCDMA` | Set CDMA\GPRS Network Config Failed |
| `0x8000013D` | 317 | `ZZNET_ERROR_GETCFG_IPFILTER` | Get IP Filter Config Failed |
| `0x8000013E` | 318 | `ZZNET_ERROR_SETCFG_IPFILTER` | Set IP Filter Config Failed |
| `0x8000013F` | 319 | `ZZNET_ERROR_GETCFG_TALKENCODE` | Get Voice Talk Encode Config Failed |
| `0x80000140` | 320 | `ZZNET_ERROR_SETCFG_TALKENCODE` | Set Voice Talk Encode Config Failed |
| `0x80000141` | 321 | `ZZNET_ERROR_GETCFG_RECORDLEN` | Get Record Packing Length Config Failed |
| `0x80000142` | 322 | `ZZNET_ERROR_SETCFG_RECORDLEN` | Set Record Packing Length Config Failed |
| `0x80000143` | 323 | `ZZNET_DONT_SUPPORT_SUBAREA` | Does Not Support Network Hard Disk Partition |
| `0x80000144` | 324 | `ZZNET_ERROR_GET_AUTOREGSERVER` | Get Active Registration Server Info on Device Failed |
| `0x80000145` | 325 | `ZZNET_ERROR_CONTROL_AUTOREGISTER` | Active Registration Redirect Register Error |
| `0x80000146` | 326 | `ZZNET_ERROR_DISCONNECT_AUTOREGISTER` | Disconnect Active Registration Server Error |
| `0x80000147` | 327 | `ZZNET_ERROR_GETCFG_MMS` | Get MMS Config Failed |
| `0x80000148` | 328 | `ZZNET_ERROR_SETCFG_MMS` | Set MMS Config Failed |
| `0x80000149` | 329 | `ZZNET_ERROR_GETCFG_SMSACTIVATION` | Get SMS Activation Wireless Connection Config Failed |
| `0x8000014A` | 330 | `ZZNET_ERROR_SETCFG_SMSACTIVATION` | Set SMS Activation Wireless Connection Config Failed |
| `0x8000014B` | 331 | `ZZNET_ERROR_GETCFG_DIALINACTIVATION` | Get Dial-in Activation Wireless Connection Config Failed |
| `0x8000014C` | 332 | `ZZNET_ERROR_SETCFG_DIALINACTIVATION` | Set Dial-in Activation Wireless Connection Config Failed |
| `0x8000014D` | 333 | `ZZNET_ERROR_GETCFG_VIDEOOUT` | Query Video Output Parameter Config Failed |
| `0x8000014E` | 334 | `ZZNET_ERROR_SETCFG_VIDEOOUT` | Set Video Output Parameter Config Failed |
| `0x8000014F` | 335 | `ZZNET_ERROR_GETCFG_OSDENABLE` | Get OSD Overlay Enable Config Failed |
| `0x80000150` | 336 | `ZZNET_ERROR_SETCFG_OSDENABLE` | Set OSD Overlay Enable Config Failed |
| `0x80000151` | 337 | `ZZNET_ERROR_SETCFG_ENCODERINFO` | Set Digital Channel Frontend Encoder Access Config Failed |
| `0x80000152` | 338 | `ZZNET_ERROR_GETCFG_TVADJUST` | Get TV Adjustment Config Failed |
| `0x80000153` | 339 | `ZZNET_ERROR_SETCFG_TVADJUST` | Set TV Adjustment Config Failed |
| `0x80000154` | 340 | `ZZNET_ERROR_CONNECT_FAILED` | Request Connection Failed |
| `0x80000155` | 341 | `ZZNET_ERROR_SETCFG_BURNFILE` | Request Burn File Upload Failed |
| `0x80000156` | 342 | `ZZNET_ERROR_SNIFFER_GETCFG` | Get Sniffer Config Info Failed |
| `0x80000157` | 343 | `ZZNET_ERROR_SNIFFER_SETCFG` | Set Sniffer Config Info Failed |
| `0x80000158` | 344 | `ZZNET_ERROR_DOWNLOADRATE_GETCFG` | Query Download Limit Info Failed |
| `0x80000159` | 345 | `ZZNET_ERROR_DOWNLOADRATE_SETCFG` | Set Download Limit Info Failed |
| `0x8000015A` | 346 | `ZZNET_ERROR_SEARCH_TRANSCOM` | Query Serial Port Params Failed |
| `0x8000015B` | 347 | `ZZNET_ERROR_GETCFG_POINT` | Get Preset Point Info Error |
| `0x8000015C` | 348 | `ZZNET_ERROR_SETCFG_POINT` | Set Preset Point Info Error |
| `0x8000015D` | 349 | `ZZNET_SDK_LOGOUT_ERROR` | SDK Did Not Logout Device Normally |
| `0x8000015E` | 350 | `ZZNET_ERROR_GET_VEHICLE_CFG` | Get Vehicle Config Failed |
| `0x8000015F` | 351 | `ZZNET_ERROR_SET_VEHICLE_CFG` | Set Vehicle Config Failed |
| `0x80000160` | 352 | `ZZNET_ERROR_GET_ATM_OVERLAY_CFG` | Get ATM Overlay Config Failed |
| `0x80000161` | 353 | `ZZNET_ERROR_SET_ATM_OVERLAY_CFG` | Set ATM Overlay Config Failed |
| `0x80000162` | 354 | `ZZNET_ERROR_GET_ATM_OVERLAY_ABILITY` | Get ATM Overlay Capability Failed |
| `0x80000163` | 355 | `ZZNET_ERROR_GET_DECODER_TOUR_CFG` | Get Decoder Tour Config Failed |
| `0x80000164` | 356 | `ZZNET_ERROR_SET_DECODER_TOUR_CFG` | Set Decoder Tour Config Failed |
| `0x80000165` | 357 | `ZZNET_ERROR_CTRL_DECODER_TOUR` | Control Decoder Tour Failed |
| `0x80000166` | 358 | `ZZNET_GROUP_OVERSUPPORTNUM` | Exceeds Device Supported Max User Group Count |
| `0x80000167` | 359 | `ZZNET_USER_OVERSUPPORTNUM` | Exceeds Device Supported Max User Count |
| `0x80000170` | 368 | `ZZNET_ERROR_GET_SIP_CFG` | Get SIP Config Failed |
| `0x80000171` | 369 | `ZZNET_ERROR_SET_SIP_CFG` | Set SIP Config Failed |
| `0x80000172` | 370 | `ZZNET_ERROR_GET_SIP_ABILITY` | Get SIP Capability Failed |
| `0x80000173` | 371 | `ZZNET_ERROR_GET_WIFI_AP_CFG` | Get WIFI AP Config Failed |
| `0x80000174` | 372 | `ZZNET_ERROR_SET_WIFI_AP_CFG` | Set WIFI AP Config Failed |
| `0x80000175` | 373 | `ZZNET_ERROR_GET_DECODE_POLICY` | Get Decode Policy Config Failed |
| `0x80000176` | 374 | `ZZNET_ERROR_SET_DECODE_POLICY` | Set Decode Policy Config Failed |
| `0x80000177` | 375 | `ZZNET_ERROR_TALK_REJECT` | Reject Talk |
| `0x80000178` | 376 | `ZZNET_ERROR_TALK_OPENED` | Talk Opened by Other Client |
| `0x80000179` | 377 | `ZZNET_ERROR_TALK_RESOURCE_CONFLICIT` | Resource Conflict |
| `0x8000017A` | 378 | `ZZNET_ERROR_TALK_UNSUPPORTED_ENCODE` | Unsupported Voice Encode Format |
| `0x8000017B` | 379 | `ZZNET_ERROR_TALK_RIGHTLESS` | No Permission |
| `0x8000017C` | 380 | `ZZNET_ERROR_TALK_FAILED` | Request Talk Failed |
| `0x8000017D` | 381 | `ZZNET_ERROR_GET_MACHINE_CFG` | Get Machine Related Config Failed |
| `0x8000017E` | 382 | `ZZNET_ERROR_SET_MACHINE_CFG` | Set Machine Related Config Failed |
| `0x8000017F` | 383 | `ZZNET_ERROR_GET_DATA_FAILED` | Device Failed to Get Current Requested Data |
| `0x80000180` | 384 | `ZZNET_ERROR_MAC_VALIDATE_FAILED` | MAC Address Validation Failed |
| `0x80000181` | 385 | `ZZNET_ERROR_GET_INSTANCE` | Get Server Instance Failed |
| `0x80000182` | 386 | `ZZNET_ERROR_JSON_REQUEST` | Generated JSON String Error |
| `0x80000183` | 387 | `ZZNET_ERROR_JSON_RESPONSE` | Response JSON String Error |
| `0x80000184` | 388 | `ZZNET_ERROR_VERSION_HIGHER` | Protocol Version Lower Than Currently Used Version |
| `0x80000185` | 389 | `ZZNET_SPARE_NO_CAPACITY` | Hot Spare Operation Failed, Insufficient Capacity |
| `0x80000186` | 390 | `ZZNET_ERROR_SOURCE_IN_USE` | Display Source Occupied by Other Output |
| `0x80000187` | 391 | `ZZNET_ERROR_REAVE` | High Level User Preempts Low Level User Resource |
| `0x80000188` | 392 | `ZZNET_ERROR_NETFORBID` | Network Access Forbidden |
| `0x80000189` | 393 | `ZZNET_ERROR_GETCFG_MACFILTER` | Get MAC Filter Config Failed |
| `0x8000018A` | 394 | `ZZNET_ERROR_SETCFG_MACFILTER` | Set MAC Filter Config Failed |
| `0x8000018B` | 395 | `ZZNET_ERROR_GETCFG_IPMACFILTER` | Get IP/MAC Filter Config Failed |
| `0x8000018C` | 396 | `ZZNET_ERROR_SETCFG_IPMACFILTER` | Set IP/MAC Filter Config Failed |
| `0x8000018D` | 397 | `ZZNET_ERROR_OPERATION_OVERTIME` | Current Operation Timeout |
| `0x8000018E` | 398 | `ZZNET_ERROR_SENIOR_VALIDATE_FAILED` | Senior Validation Failed |
| `0x8000018F` | 399 | `ZZNET_ERROR_DEVICE_ID_NOT_EXIST` | Device ID Not Exist |
| `0x80000190` | 400 | `ZZNET_ERROR_UNSUPPORTED` | Unsupported Current Operation |
| `0x80000191` | 401 | `ZZNET_ERROR_PROXY_DLLLOAD` | Proxy DLL Load Failed |
| `0x80000192` | 402 | `ZZNET_ERROR_PROXY_ILLEGAL_PARAM` | Proxy User Parameter Illegal |
| `0x80000193` | 403 | `ZZNET_ERROR_PROXY_INVALID_HANDLE` | Proxy Handle Invalid |
| `0x80000194` | 404 | `ZZNET_ERROR_PROXY_LOGIN_DEVICE_ERROR` | Proxy Login Frontend Device Failed |
| `0x80000195` | 405 | `ZZNET_ERROR_PROXY_START_SERVER_ERROR` | Start Proxy Server Failed |
| `0x80000196` | 406 | `ZZNET_ERROR_SPEAK_FAILED` | Request Broadcast Speak Failed |
| `0x80000197` | 407 | `ZZNET_ERROR_NOT_SUPPORT_F6` | Device Does Not Support This F6 Interface Call |
| `0x80000198` | 408 | `ZZNET_ERROR_CD_UNREADY` | CD Not Ready |
| `0x80000199` | 409 | `ZZNET_ERROR_DIR_NOT_EXIST` | Directory Not Exist |
| `0x8000019A` | 410 | `ZZNET_ERROR_UNSUPPORTED_SPLIT_MODE` | Device Unsupported Split Mode |
| `0x8000019B` | 411 | `ZZNET_ERROR_OPEN_WND_PARAM` | Open Window Parameter Illegal |
| `0x8000019C` | 412 | `ZZNET_ERROR_LIMITED_WND_COUNT` | Open Window Count Exceeds Limit |
| `0x8000019D` | 413 | `ZZNET_ERROR_UNMATCHED_REQUEST` | Request Command Mismatch with Current Mode |
| `0x8000019E` | 414 | `ZZNET_RENDER_ENABLELARGEPICADJUSTMENT_ERROR` | Render Library Enable HD Image Internal Adjustment Strategy Error |
| `0x8000019F` | 415 | `ZZNET_ERROR_UPGRADE_FAILED` | Device Upgrade Failed |
| `0x800001A0` | 416 | `ZZNET_ERROR_NO_TARGET_DEVICE` | Cannot Find Target Device |
| `0x800001A1` | 417 | `ZZNET_ERROR_NO_VERIFY_DEVICE` | Cannot Find Verify Device |
| `0x800001A2` | 418 | `ZZNET_ERROR_CASCADE_RIGHTLESS` | No Cascade Permission |
| `0x800001A3` | 419 | `ZZNET_ERROR_LOW_PRIORITY` | Low Priority |
| `0x800001A4` | 420 | `ZZNET_ERROR_REMOTE_REQUEST_TIMEOUT` | Remote Device Request Timeout |
| `0x800001A5` | 421 | `ZZNET_ERROR_LIMITED_INPUT_SOURCE` | Input Source Exceeds Max Channel Limit |
| `0x800001A6` | 422 | `ZZNET_ERROR_SET_LOG_PRINT_INFO` | Set Log Print Failed |
| `0x800001A7` | 423 | `ZZNET_ERROR_PARAM_DWSIZE_ERROR` | Input Parameter dwsize Field Error |
| `0x800001A8` | 424 | `ZZNET_ERROR_LIMITED_MONITORWALL_COUNT` | Monitor Wall Count Exceeds Limit |
| `0x800001A9` | 425 | `ZZNET_ERROR_PART_PROCESS_FAILED` | Partial Process Execution Failed |
| `0x800001AA` | 426 | `ZZNET_ERROR_TARGET_NOT_SUPPORT` | This Function Does Not Support Forwarding |
| `0x800001FE` | 510 | `ZZNET_ERROR_VISITE_FILE` | Visit File Failed |
| `0x800001FF` | 511 | `ZZNET_ERROR_DEVICE_STATUS_BUSY` | Device Busy |
| `0x80000200` | 512 | `ZZNET_USER_PWD_NOT_AUTHORIZED` | Modify Password No Permission |
| `0x80000201` | 513 | `ZZNET_USER_PWD_NOT_STRONG` | Password Strength Insufficient |
| `0x80000202` | 514 | `ZZNET_ERROR_NO_SUCH_CONFIG` | No Corresponding Config |
| `0x80000203` | 515 | `ZZNET_ERROR_AUDIO_RECORD_FAILED` | Audio Record Failed |
| `0x80000204` | 516 | `ZZNET_ERROR_SEND_DATA_FAILED` | Data Send Failed |
| `0x80000205` | 517 | `ZZNET_ERROR_OBSOLESCENT_INTERFACE` | Obsolete Interface |
| `0x80000206` | 518 | `ZZNET_ERROR_INSUFFICIENT_INTERAL_BUF` | Internal Buffer Insufficient |
| `0x80000207` | 519 | `ZZNET_ERROR_NEED_ENCRYPTION_PASSWORD` | Need to Verify Password When Modifying Device IP |
| `0x80000208` | 520 | `ZZNET_ERROR_NOSUPPORT_RECORD` | Device Does Not Support This Record Set |
| `0x80000209` | 521 | `ZZNET_ERROR_DEVICE_IN_UPGRADING` | Device Is Upgrading |
| `0x8000020A` | 522 | `ZZNET_ERROR_ANALYSE_TASK_NOT_EXIST` | Intelligent Analysis Task Not Exist |
| `0x8000020B` | 523 | `ZZNET_ERROR_ANALYSE_TASK_FULL` | Intelligent Analysis Task Full |
| `0x8000020C` | 524 | `ZZNET_ERROR_DEVICE_RESTART` | Device Restart |
| `0x8000020D` | 525 | `ZZNET_ERROR_DEVICE_SHUTDOWN` | Device Shutdown |
| `0x8000020E` | 526 | `ZZNET_ERROR_FILE_SYSTEM_ERROR` | File System Error |
| `0x8000020F` | 527 | `ZZNET_ERROR_HARDDISK_WRITE_ERROR` | Hard Disk Write Error |
| `0x80000210` | 528 | `ZZNET_ERROR_HARDDISK_READ_ERROR` | Hard Disk Read Error |
| `0x80000211` | 529 | `ZZNET_ERROR_NO_HARDDISK_RECORD_LOG` | No Hard Disk Record Log |
| `0x80000212` | 530 | `ZZNET_ERROR_NO_HARDDISK` | No Working Disk (No Read/Write Disk) |
| `0x80000213` | 531 | `ZZNET_ERROR_HARDDISK_OTHER_ERRORS` | Hard Disk Other Errors |
| `0x80000214` | 532 | `ZZNET_ERROR_HARDDISK_BADSECTORS_MINOR_ERRORS` | Hard Disk Bad Sectors Minor Errors |
| `0x80000215` | 533 | `ZZNET_ERROR_HARDDISK_BADSECTORS_CRITICAL_ERRORS` | Hard Disk Bad Sectors Critical Errors |
| `0x80000216` | 534 | `ZZNET_ERROR_HARDDISK_PHYSICAL_BADSECTORS_SLIGHT` | Hard Disk Physical Bad Sectors Slight |
| `0x80000217` | 535 | `ZZNET_ERROR_HARDDISK_PHYSICAL_BADSECTORS_SERIOUS` | Hard Disk Physical Bad Sectors Serious |
| `0x80000218` | 536 | `ZZNET_ERROR_NETWORK_DISCONNECTION_ALARM` | Network Disconnection Alarm |
| `0x80000219` | 537 | `ZZNET_ERROR_NETWORK_DISCONNECTION` | Network Disconnected |
| `0x8000021A` | 538 | `ZZNET_ERROR_SET_SOURCE_EXCEED` | Set Video Source Count Exceeds Limit |
| `0x8000021B` | 539 | `ZZNET_ERROR_SIZE_EXCEED` | Upload File Size Exceeds Range (uploadFile method) |
| `0x8000021C` | 540 | `ZZNET_ERROR_LOGOPEN_DISABLE` | Log config file exists, based on log print config file, log print interface disabled |
| `0x8000021D` | 541 | `ZZNET_ERROR_STREAM_PACKAGE_ERROR` | Packaging Audio Header Failed |
| `0x8000021E` | 542 | `ZZNET_ERROR_READ_LIMIT` | Disk Read Data Limit |
| `0x8000021F` | 543 | `ZZNET_ERROR_PREVIEWOPENED` | Multi-play preview already opened, insufficient resources, compression playback failed |
| `0x80000220` | 544 | `ZZNET_ERROR_COMPRESSOPENED` | Compression playback function already opened, causing failure |
| `0x80000221` | 545 | `ZZNET_ERROR_COMPRESSERROR_UNKNOWN` | Unknown compression failure cause |
| `0x80000222` | 546 | `ZZNET_ERROR_COMPRESSERROR_OVERDECODE` | Exceeds decoding capability, causing compression failure |
| `0x80000223` | 547 | `ZZNET_ERROR_COMPRESSERROR_OVERENCODE` | Exceeds compression capability, causing compression failure |
| `0x80000224` | 548 | `ZZNET_ERROR_COMPRESSERROR_NONESTREAM` | No original stream, causing compression failure |
| `0x80000225` | 549 | `ZZNET_ERROR_COMPRESSERROR_CHIPOFFLINE` | Slave chip where compression channel is located is offline, causing compression failure |
| `0x80000226` | 550 | `ZZNET_ERROR_CHANNELNOTADD` | Channel not added |
| `0x80000227` | 551 | `ZZNET_ERROR_ENCODER_COVER_CAPS` | Exceeds device encoding capability |
| `0x80000228` | 552 | `ZZNET_ERROR_DEVICE_NOT_EXIST` | System device does not exist |
| `0x80000229` | 553 | `ZZNET_ERROR_IPSPEAKER_BROADCAST_PARTIALFAILED` | IPSpeaker broadcast speak failed on some channels |
| `0x80000259` | 601 | `ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_GROUP_COUNT_EXCEED` | Tip image library reached max count |
| `0x8000025A` | 602 | `ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_GROUP_NAME_EXISTED` | Tip library name already exists |
| `0x8000025B` | 603 | `ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_UNKNOW` | Unknown reason |
| `0x8000025C` | 604 | `ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_SCHEME_OR_GROUP_IMPORT_OR_EXPORT` | Tip scheme or image library is importing or exporting |
| `0x8000025D` | 605 | `ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_NAME_EMPTY` | Image library name cannot be empty |
| `0x8000025E` | 606 | `ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_GROUP_NOT_EXIST` | Image library does not exist |
| `0x8000025F` | 607 | `ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_FORMAT_ERROR` | Tip image format error |
| `0x80000260` | 608 | `ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_TIP_NOT_EXIST` | Tip does not exist |
| `0x80000261` | 609 | `ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_DELETE_TIP_ERROR` | Delete tip file error |
| `0x800002BD` | 701 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_MAX_COUNT` | Tip scheme count reached max value |
| `0x800002BE` | 702 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_NAME_REPEAT` | Tip scheme name repeated |
| `0x800002BF` | 703 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_NOEXIST` | Tip scheme does not exist |
| `0x800002C0` | 704 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_UNKNOW` | Unknown reason |
| `0x800002C1` | 705 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_GROUP_NO_EXIST` | Image library does not exist |
| `0x800002C2` | 706 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_GROUP_MAX_COUNT` | Scheme image library count reached max value |
| `0x800002C3` | 707 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_PICTURE_NO_EXIST` | Image does not exist |
| `0x800002C4` | 708 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_NAME_EMPTY` | Tip scheme name cannot be empty |
| `0x800002C5` | 709 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_GROUP_EXISTED` | Tip scheme library already exists |
| `0x800002C6` | 710 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_TIP_GROUP_REPEAT` | Image library in tip scheme repeated |
| `0x800002C7` | 711 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_GROUP_NO_EXISTED` | Tip scheme library does not exist |
| `0x800002C8` | 712 | `ZZNET_ERRPR_XRAY_TIP_SCHEME_GROUP_IMPORT_OR_EXPORT` | Tip scheme or image library is importing or exporting |
| `0x8000038E` | 910 | `ZZNET_ERROR_FACE_RECOGNITION_SERVER_COMPONENT_NOT_INIT_COMPLETED` | Component Not Initialization Completed |
| `0x8000038F` | 911 | `ZZNET_ERROR_EXP_REGISTRY_GROUP_ID_EXCEED` | Group ID Exceeds Max Value |
| `0x80000390` | 912 | `ZZNET_ERROR_EXP_REGISTRY_ABSTRACT_INIT_ERROR` | Modeling Analyzer Start Failed |
| `0x80000391` | 913 | `ZZNET_ERROR_EXP_REGISTRY_GROUP_ID_NOT_FOUND` | ID Not Found or Empty |
| `0x80000392` | 914 | `ZZNET_ERROR_EXP_REGISTRY_DATABASE_ERROR` | Database Operation Failed (Refers to database operation) |
| `0x80000393` | 915 | `ZZNET_ERROR_EXP_REGISTRY_TOKEN_ERROR` | Token Not Found or Empty |
| `0x80000394` | 916 | `ZZNET_ERROR_EXP_REGISTRY_BEGIN_NUM_OVER_RUN` | Query Start Number Greater Than Total |
| `0x80000395` | 917 | `ZZNET_ERROR_EXP_REGISTRY_ABSTRACT_STATE` | Device is Modeling |
| `0x80000396` | 918 | `ZZNET_ERROR_EXP_REGISTRY_BIG_PIC_MAX_NUM` | Single Import Panorama Image Count Exceeds Limit |
| `0x80000397` | 919 | `ZZNET_ERROR_EXP_REGISTRY_OBJECT_MAX_NUM` | Feature Count Exceeds Limit |
| `0x80000398` | 920 | `ZZNET_ERROR_EXP_REGISTRY_GROUP_SPACE_EXCEED` | Exceeds Experience Library Space Limit |
| `0x80000399` | 921 | `ZZNET_ERROR_EXP_REGISTRY_GROUP_NAME_EXIST` | Library Name Already Exists |
| `0x8000039A` | 922 | `ZZNET_ERROR_EXP_REGISTRY_INVALID_PARAM` | Invalid Parameter |
| `0x8000039B` | 923 | `ZZNET_ERROR_EXP_REGISTRY_UNKNOWN_ERROR` | Unknown Error |
| `0x8000039C` | 924 | `ZZNET_ERROR_EXP_REGISTRY_ATTACH_NUM_EXCEED` | Exceeds Max Subscription Count |
| `0x8000039D` | 925 | `ZZNET_ERROR_EXP_REGISTRY_FILE_IOE_ERROR` | File Operation Failed |
| `0x8000039E` | 926 | `ZZNET_ERROR_EXP_REGISTRY_FILE_NOT_EXIST` | File Not Exist |
| `0x8000039F` | 927 | `ZZNET_ERROR_EXP_REGISTRY_ABSTRACT_NUM_ZERO` | Number to Manually Model is 0 |
| `0x800003A0` | 928 | `ZZNET_ERROR_EXP_REGISTRY_GROUP_LINKED` | Library Already Linked |
| `0x800003A1` | 929 | `ZZNET_ERROR_EXP_REGISTRY_OTHER_TYPE_DEPLOYED` | Other Type of Base Library Already Deployed |
| `0x800003F2` | 1010 | `ZZNET_ERROR_SERIALIZE_ERROR` | Data Serialization Error |
| `0x800003F3` | 1011 | `ZZNET_ERROR_DESERIALIZE_ERROR` | Data Deserialization Error |
| `0x800003F4` | 1012 | `ZZNET_ERROR_LOWRATEWPAN_ID_EXISTED` | Wireless ID Already Exists |
| `0x800003F5` | 1013 | `ZZNET_ERROR_LOWRATEWPAN_ID_LIMIT` | Wireless ID Count Limit Exceeded |
| `0x800003F6` | 1014 | `ZZNET_ERROR_LOWRATEWPAN_ID_ABNORMAL` | Wireless Abnormal Add |
| `0x800003F7` | 1015 | `ZZNET_ERROR_ENCRYPT` | Encrypt Data Failed |
| `0x800003F8` | 1016 | `ZZNET_ERROR_PWD_ILLEGAL` | New Password Not Standard |
| `0x800003F9` | 1017 | `ZZNET_ERROR_DEVICE_ALREADY_INIT` | Device Already Initialized |
| `0x800003FA` | 1018 | `ZZNET_ERROR_SECURITY_CODE` | Security Code Error |
| `0x800003FB` | 1019 | `ZZNET_ERROR_SECURITY_CODE_TIMEOUT` | Security Code Validity Expired |
| `0x800003FC` | 1020 | `ZZNET_ERROR_GET_PWD_SPECI` | Get Password Spec Failed |
| `0x800003FD` | 1021 | `ZZNET_ERROR_NO_AUTHORITY_OF_OPERATION` | No Authority to Perform This Operation |
| `0x800003FE` | 1022 | `ZZNET_ERROR_DECRYPT` | Decrypt Data Failed |
| `0x800003FF` | 1023 | `ZZNET_ERROR_2D_CODE` | 2D code Validation Failed |
| `0x80000400` | 1024 | `ZZNET_ERROR_INVALID_REQUEST` | Illegal RPC Request |
| `0x80000401` | 1025 | `ZZNET_ERROR_PWD_RESET_DISABLE` | Password Reset Function Disabled |
| `0x80000402` | 1026 | `ZZNET_ERROR_PLAY_PRIVATE_DATA` | Display Private Data (e.g., Rule Box) Failed |
| `0x80000403` | 1027 | `ZZNET_ERROR_ROBOT_OPERATE_FAILED` | Robot Operation Failed |
| `0x80000404` | 1028 | `ZZNET_ERROR_PHOTOSIZE_EXCEEDSLIMIT` | Photo Size Exceeds Limit |
| `0x80000405` | 1029 | `ZZNET_ERROR_USERID_INVALID` | User ID Not Exist |
| `0x80000406` | 1030 | `ZZNET_ERROR_EXTRACTFEATURE_FAILED` | Photo Feature Extraction Failed |
| `0x80000407` | 1031 | `ZZNET_ERROR_PHOTO_EXIST` | Photo Already Exists |
| `0x80000408` | 1032 | `ZZNET_ERROR_PHOTO_OVERFLOW` | Photo Count Exceeds Limit |
| `0x80000409` | 1033 | `ZZNET_ERROR_CHANNEL_ALREADY_OPENED` | Channel Already Opened |
| `0x8000040A` | 1034 | `ZZNET_ERROR_CREATE_SOCKET` | Create Socket Failed |
| `0x8000040B` | 1035 | `ZZNET_ERROR_CHANNEL_NUM` | Channel Number Error |
| `0x8000040C` | 1036 | `ZZNET_ERROR_PHOTO_FORMAT` | Photo Format Error |
| `0x8000040D` | 1037 | `ZZNET_ERROR_DIGITAL_CERTIFICATE_INTERNAL_ERROR` | Internal Error (e.g., Hardware issue, Get Public Key Failed, Internal Interface Call Failed, Write File Failed, etc.) |
| `0x8000040E` | 1038 | `ZZNET_ERROR_DIGITAL_CERTIFICATE_GET_ID_FAILED` | Get Device ID Failed |
| `0x8000040F` | 1039 | `ZZNET_ERROR_DIGITAL_CERTIFICATE_IMPORT_ILLEGAL` | Certificate File Illegal (Format not supported or not a certificate file) |
| `0x80000410` | 1040 | `ZZNET_ERROR_DIGITAL_CERTIFICATE_SN_ERROR` | Certificate SN repeated or error or non-standard |
| `0x80000411` | 1041 | `ZZNET_ERROR_DIGITAL_CERTIFICATE_COMMON_NAME_ILLEGAL` | Certificate common name is invalid (Mismatch between local device certificate and system devid_cryptoID, or the remote end does not comply with the rules (devid_cryptoID)). |
| `0x80000412` | 1042 | `ZZNET_ERROR_DIGITAL_CERTIFICATE_NO_ROOT_CERT` | Root certificate not imported or does not exist. |
| `0x80000413` | 1043 | `ZZNET_ERROR_DIGITAL_CERTIFICATE_CERT_REVOKED` | Certificate has been revoked. |
| `0x80000414` | 1044 | `ZZNET_ERROR_DIGITAL_CERTIFICATE_CERT_INVALID` | Certificate is unavailable, not yet valid, or has expired. |
| `0x80000415` | 1045 | `ZZNET_ERROR_DIGITAL_CERTIFICATE_CERT_ERROR_SIGN` | Certificate signature mismatch. |
| `0x80000416` | 1046 | `ZZNET_ERROR_DIGITAL_CERTIFICATE_COUNTS_UPPER_LIMIT` | Exceeds the upper limit for certificate imports. |
| `0x80000417` | 1047 | `ZZNET_ERROR_DIGITAL_CERTIFICATE_CERT_NO_EXIST` | Certificate file does not exist (when exporting certificate or retrieving public key of the corresponding certificate). |
| `0x80000418` | 1048 | `ZZNET_ERROR_DEFULAT_SEARCH_PORT` | Default search ports cannot be used (5050, 37810). |
| `0x80000437` | 1079 | `ZZNET_ERROR_DEVICE_PARSE_PROTOCOL` | Device protocol parsing error. |
| `0x80000438` | 1080 | `ZZNET_ERROR_DEVICE_INVALID_REQUEST` | Device returned invalid request. |
| `0x80000439` | 1081 | `ZZNET_ERROR_DEVICE_INTERNAL_ERROR` | Device internal error. |
| `0x8000043A` | 1082 | `ZZNET_ERROR_DEVICE_REQUEST_TIMEOUT` | Device internal request timeout. |
| `0x8000043B` | 1083 | `ZZNET_ERROR_DEVICE_KEEPALIVE_FAIL` | Device keep-alive failed. |
| `0x8000043C` | 1084 | `ZZNET_ERROR_DEVICE_NETWORK_ERROR` | Device network error. |
| `0x8000043D` | 1085 | `ZZNET_ERROR_DEVICE_UNKNOWN_ERROR` | Device internal unknown error. |
| `0x8000043E` | 1086 | `ZZNET_ERROR_DEVICE_COM_INTERFACE_NOTFOUND` | Device component interface not found. |
| `0x8000043F` | 1087 | `ZZNET_ERROR_DEVICE_COM_IMPLEMENT_NOTFOUND` | Device component implementation not found. |
| `0x80000440` | 1088 | `ZZNET_ERROR_DEVICE_COM_NOTFOUND` | Device access component not found. |
| `0x80000441` | 1089 | `ZZNET_ERROR_DEVICE_COM_INSTANCE_NOTEXIST` | Device access component instance does not exist. |
| `0x80000442` | 1090 | `ZZNET_ERROR_DEVICE_CREATE_COM_FAIL` | Device component factory failed to create component. |
| `0x80000443` | 1091 | `ZZNET_ERROR_DEVICE_GET_COM_FAIL` | Device component factory failed to retrieve component instance. |
| `0x80000444` | 1092 | `ZZNET_ERROR_DEVICE_BAD_REQUEST` | Device service request rejected. |
| `0x80000445` | 1093 | `ZZNET_ERROR_DEVICE_REQUEST_IN_PROGRESS` | Device is already processing the request, duplicate requests not accepted. |
| `0x80000446` | 1094 | `ZZNET_ERROR_DEVICE_LIMITED_RESOURCE` | Device resource insufficient. |
| `0x80000447` | 1095 | `ZZNET_ERROR_DEVICE_BUSINESS_TIMEOUT` | Device service timeout. |
| `0x80000448` | 1096 | `ZZNET_ERROR_DEVICE_TOO_MANY_REQUESTS` | Device received too many requests. |
| `0x80000449` | 1097 | `ZZNET_ERROR_DEVICE_NOT_ALREADY` | Device not ready, service requests not accepted. |
| `0x8000044A` | 1098 | `ZZNET_ERROR_DEVICE_SEARCHRECORD_TIMEOUT` | Device video search timeout. |
| `0x8000044B` | 1099 | `ZZNET_ERROR_DEVICE_SEARCHTIME_INVALID` | Device video search time is invalid. |
| `0x8000044C` | 1100 | `ZZNET_ERROR_DEVICE_SSID_INVALID` | Device SSID validation failed. |
| `0x8000044D` | 1101 | `ZZNET_ERROR_DEVICE_CHANNEL_STREAMTYPE_ERROR` | Device channel number or stream type validation failed. |
| `0x8000044E` | 1102 | `ZZNET_ERROR_DEVICE_STREAM_PACKINGFORMAT_UNSUPPORT` | Device does not support this stream packing format. |
| `0x8000044F` | 1103 | `ZZNET_ERROR_DEVICE_AUDIO_ENCODINGFORMAT_UNSUPPORT` | Device does not support this audio encoding format. |
| `0x80000450` | 1104 | `ZZNET_ERROR_SECURITY_ERROR_SUPPORT_GUI` | Security code verification failed. Password can be reset via local GUI. |
| `0x80000451` | 1105 | `ZZNET_ERROR_SECURITY_ERROR_SUPPORT_MULT` | Security code verification failed. Password can be reset via APP or ConfigTool. |
| `0x80000452` | 1106 | `ZZNET_ERROR_SECURITY_ERROR_SUPPORT_UNIQUE` | Security code verification failed. Password can be reset by logging into the Web page. |
| `0x80000453` | 1107 | `ZZNET_ERROR_STREAMCONVERTOR_DEFECT` | Transcode library is missing. |
| `0x80000454` | 1108 | `ZZNET_ERROR_SECURITY_GENERATE_SAFE_CODE` | Failed to generate security code using encryption library. |
| `0x80000455` | 1109 | `ZZNET_ERROR_SECURITY_GET_CONTACT` | Failed to retrieve contact information. |
| `0x80000456` | 1110 | `ZZNET_ERROR_SECURITY_GET_QRCODE` | Failed to retrieve QR code information for password reset. |
| `0x80000457` | 1111 | `ZZNET_ERROR_SECURITY_CANNOT_RESET` | Device not initialized, cannot reset. |
| `0x80000458` | 1112 | `ZZNET_ERROR_SECURITY_NOT_SUPPORT_CONTACT_MODE` | Does not support setting this contact method (e.g., trying to set email when only phone number is supported). |
| `0x80000459` | 1113 | `ZZNET_ERROR_SECURITY_RESPONSE_TIMEOUT` | Remote end response timeout. |
| `0x8000045A` | 1114 | `ZZNET_ERROR_SECURITY_AUTHCODE_FORBIDDEN` | Too many failed AuthCode verification attempts. Verification forbidden. |
| `0x8000045B` | 1115 | `ZZNET_ERROR_TRANCODE_LOGIN_REMOTE_DEV` | (Virtual Transcode) Failed to log in to remote device. |
| `0x8000045D` | 1117 | `ZZNET_ERROR_VK_INFO_DECRYPT_FAILED` | VK information decryption failed. |
| `0x8000045E` | 1118 | `ZZNET_ERROR_VK_INFO_DESERIALIZE_FAILED` | VK information deserialization failed. |
| `0x8000045F` | 1119 | `ZZNET_ERROR_GDPR_ABILITY_NOT_ENABLE` | SDK GDPR feature not enabled. |
| `0x80000460` | 1120 | `ZZNET_ERROR_FAST_CHECK_NO_AUTH` | Access Control Quick Verification: No permission. |
| `0x80000461` | 1121 | `ZZNET_ERROR_FAST_CHECK_NO_FILE` | Access Control Quick Verification: File not found. |
| `0x80000462` | 1122 | `ZZNET_ERROR_FAST_CHECK_FILE_FAIL` | Access Control Quick Verification: File preparation failed. |
| `0x80000463` | 1123 | `ZZNET_ERROR_FAST_CHECK_BUSY` | Access Control Quick Verification: System is busy. |
| `0x80000464` | 1124 | `ZZNET_ERROR_FAST_CHECK_NO_PASSWORD` | Access Control Quick Verification: No password defined, export not allowed. |
| `0x80000465` | 1125 | `ZZNET_ERROR_IMPORT_ACCESS_SEND_FAILD` | Access Control Quick Import: Failed to send access control data. |
| `0x80000466` | 1126 | `ZZNET_ERROR_IMPORT_ACCESS_BUSY` | Access Control Quick Import: System is busy, import task already in progress. |
| `0x80000467` | 1127 | `ZZNET_ERROR_IMPORT_ACCESS_DATAERROR` | Access Control Quick Import: Data packet verification failed. |
| `0x80000468` | 1128 | `ZZNET_ERROR_IMPORT_ACCESS_DATAINVALID` | Access Control Quick Import: Data packet is invalid. |
| `0x80000469` | 1129 | `ZZNET_ERROR_IMPORT_ACCESS_SYNC_FALID` | Access Control Quick Import: Synchronization failed, database cannot be generated. |
| `0x8000046A` | 1130 | `ZZNET_ERROR_IMPORT_ACCESS_DBFULL` | Access Control Quick Import: Database is full, cannot import. |
| `0x8000046B` | 1131 | `ZZNET_ERROR_IMPORT_ACCESS_SDFULL` | Access Control Quick Import: Storage space is full, cannot import. |
| `0x8000046C` | 1132 | `ZZNET_ERROR_IMPORT_ACCESS_CIPHER_ERROR` | Access Control Quick Import: Incorrect password for import package. |
| `0x8000046D` | 1133 | `ZZNET_ERROR_INVALID_PARAM` | Invalid parameter. |
| `0x8000046E` | 1134 | `ZZNET_ERROR_INVALID_PASSWORD` | Invalid password. |
| `0x8000046F` | 1135 | `ZZNET_ERROR_INVALID_FINGERPRINT` | Invalid fingerprint data. |
| `0x80000470` | 1136 | `ZZNET_ERROR_INVALID_FACE` | Invalid face template. |
| `0x80000471` | 1137 | `ZZNET_ERROR_INVALID_CARD` | Invalid card. |
| `0x80000472` | 1138 | `ZZNET_ERROR_INVALID_USER` | Invalid user. |
| `0x80000473` | 1139 | `ZZNET_ERROR_GET_SUBSERVICE` | Failed to retrieve capability set sub-service. |
| `0x80000474` | 1140 | `ZZNET_ERROR_GET_METHOD` | Failed to retrieve component method set. |
| `0x80000475` | 1141 | `ZZNET_ERROR_GET_SUBCAPS` | Failed to retrieve resource entity capability set. |
| `0x80000476` | 1142 | `ZZNET_ERROR_UPTO_INSERT_LIMIT` | Insert limit reached. |
| `0x80000477` | 1143 | `ZZNET_ERROR_UPTO_MAX_INSERT_RATE` | Maximum insert rate reached. |
| `0x80000478` | 1144 | `ZZNET_ERROR_ERASE_FINGERPRINT` | Failed to clear fingerprint data. |
| `0x80000479` | 1145 | `ZZNET_ERROR_ERASE_FACE` | Failed to clear face data. |
| `0x8000047A` | 1146 | `ZZNET_ERROR_ERASE_CARD` | Failed to clear card data. |
| `0x8000047B` | 1147 | `ZZNET_ERROR_NO_RECORD` | No record found. |
| `0x8000047C` | 1148 | `ZZNET_ERROR_NOMORE_RECORDS` | End of records, no more records to find. |
| `0x8000047D` | 1149 | `ZZNET_ERROR_RECORD_ALREADY_EXISTS` | Data duplication when issuing card or fingerprint. |
| `0x8000047E` | 1150 | `ZZNET_ERROR_EXCEED_MAX_FINGERPRINT_PERUSER` | Exceeds maximum number of fingerprints per user. |
| `0x8000047F` | 1151 | `ZZNET_ERROR_EXCEED_MAX_CARD_PERUSER` | Exceeds maximum number of cards per user. |
| `0x80000480` | 1152 | `ZZNET_ERROR_EXCEED_ADMINISTRATOR_LIMIT` | Exceeds access control administrator limit. |
| `0x80000481` | 1153 | `ZZNET_LOGIN_ERROR_DEVICE_NOT_SUPPORT_HIGHLEVEL_SECURITY_LOGIN` | Device does not support high-level security login. |
| `0x80000482` | 1154 | `ZZNET_LOGIN_ERROR_DEVICE_ONLY_SUPPORT_HIGHLEVEL_SECURITY_LOGIN` | Device only supports high-level security login. |
| `0x80000483` | 1155 | `ZZNET_ERROR_VIDEO_CHANNEL_OFFLINE` | Indicates this video channel is offline, streaming failed. |
| `0x80000484` | 1156 | `ZZNET_ERROR_USERID_FORMAT_INCORRECT` | User ID format is incorrect. |
| `0x80000485` | 1157 | `ZZNET_ERROR_CANNOT_FIND_CHANNEL_RELATE_TO_SN` | Cannot find the channel corresponding to this SN. |
| `0x80000486` | 1158 | `ZZNET_ERROR_TASK_QUEUE_OF_CHANNEL_IS_FULL` | The task queue for this channel is full. |
| `0x80000487` | 1159 | `ZZNET_ERROR_APPLY_USER_INFO_BLOCK_FAIL` | Failed to apply for a new user information (permission) block. |
| `0x80000488` | 1160 | `ZZNET_ERROR_EXCEED_MAX_PASSWD_PERUSER` | Number of user passwords exceeds limit. |
| `0x80000489` | 1161 | `ZZNET_ERROR_PARSE_PROTOCOL` | Protocol parsing error caused by internal device exception. |
| `0x8000048C` | 1164 | `ZZNET_ERROR_OPEN_PLAYGROUP_FAIL` | Failed to open playgroup. |
| `0x8000048D` | 1165 | `ZZNET_ERROR_ALREADY_IN_PLAYGROUP` | Already in playgroup. |
| `0x8000048E` | 1166 | `ZZNET_ERROR_QUERY_PLAYGROUP_TIME_FAIL` | Failed to query playgroup time. |
| `0x8000048F` | 1167 | `ZZNET_ERROR_SET_PLAYGROUP_BASECHANNEL_FAIL` | Failed to set playgroup base channel. |
| `0x80000490` | 1168 | `ZZNET_ERROR_SET_PLAYGROUP_DIRECTION_FAIL` | Failed to set playgroup direction. |
| `0x80000491` | 1169 | `ZZNET_ERROR_SET_PLAYGROUP_SPEED_FAIL` | Failed to set playgroup speed. |
| `0x80000492` | 1170 | `ZZNET_ERROR_ADD_PLAYGROUP_FAIL` | Failed to join playgroup. |
| `0x80000493` | 1171 | `ZZNET_ERROR_EXPORT_AOL_LOGFILE_NO_AUTH` | Export AOL Log: No permission. |
| `0x80000494` | 1172 | `ZZNET_ERROR_EXPORT_AOL_LOGFILE_NO_FILE` | Export AOL Log: File not found. |
| `0x80000495` | 1173 | `ZZNET_ERROR_EXPORT_AOL_LOGFILE_FILE_FAIL` | Export AOL Log: File preparation failed. |
| `0x80000496` | 1174 | `ZZNET_ERROR_EXPORT_AOL_LOGFILE_BUSY` | Export AOL Log: System is busy. |
| `0x80000497` | 1175 | `ZZNET_ERROR_EMPTY_LICENSE` | License is empty. |
| `0x80000498` | 1176 | `ZZNET_ERROR_UNSUPPORTED_MODE` | This mode is not supported. |
| `0x80000499` | 1177 | `ZZNET_ERROR_URL_APP_NOT_MATCH` | URL does not match App. |
| `0x8000049A` | 1178 | `ZZNET_ERROR_READ_INFO_FAILED` | Failed to read information. |
| `0x8000049B` | 1179 | `ZZNET_ERROR_WRITE_FAILED` | Write failed. |
| `0x8000049C` | 1180 | `ZZNET_ERROR_NO_SUCH_APP` | App not found. |
| `0x8000049D` | 1181 | `ZZNET_ERROR_VERIFIF_FAILED` | Verification failed. |
| `0x8000049E` | 1182 | `ZZNET_ERROR_LICENSE_OUT_DATE` | License has expired. |
| `0x8000049F` | 1183 | `ZZNET_ERROR_UPGRADE_PROGRAM_TOO_OLD` | Upgrade program version is too low. |
| `0x800004A0` | 1184 | `ZZNET_ERROR_SECURE_TRANSMIT_BEEN_CUT` | Secure transmission has been truncated. |
| `0x800004A1` | 1185 | `ZZNET_ERROR_DEVICE_NOT_SUPPORT_SECURE_TRANSMIT` | Device does not support secure transmission. |
| `0x800004A2` | 1186 | `ZZNET_ERROR_EXTRA_STREAM_LOGIN_FAIL_CAUSE_BY_MAIN_STREAM` | Sub-stream login failed while main stream login succeeded. |
| `0x800004A3` | 1187 | `ZZNET_ERROR_EXTRA_STREAM_CLOSED_BY_REMOTE_DEVICE` | Sub-stream closed by remote device. |
| `0x800004A4` | 1188 | `ZZNET_ERROR_IMPORT_FACEDB_SEND_FAILD` | Face Database Import: Failed to send face database data. |
| `0x800004A5` | 1189 | `ZZNET_ERROR_IMPORT_FACEDB_BUSY` | Face Database Import: System is busy, import task already in progress. |
| `0x800004A6` | 1190 | `ZZNET_ERROR_IMPORT_FACEDB_DATAERROR` | Face Database Import: Data packet verification failed. |
| `0x800004A7` | 1191 | `ZZNET_ERROR_IMPORT_FACEDB_DATAINVALID` | Face Database Import: Data packet is invalid. |
| `0x800004A8` | 1192 | `ZZNET_ERROR_IMPORT_FACEDB_UPGRADE_FAILD` | Face Database Import: Upload failed. |
| `0x800004A9` | 1193 | `ZZNET_ERROR_IMPORT_FACEDB_NO_AUTHORITY` | Face Database Import: User has no permission. |
| `0x800004AA` | 1194 | `ZZNET_ERROR_IMPORT_FACEDB_ABNORMAL_FILE` | Face Database Import: File format is abnormal. |
| `0x800004AB` | 1195 | `ZZNET_ERROR_IMPORT_FACEDB_SYNC_FALID` | Face Database Import: Synchronization failed, database cannot be generated. |
| `0x800004AC` | 1196 | `ZZNET_ERROR_IMPORT_FACEDB_DBFULL` | Face Database Import: Database is full, cannot import. |
| `0x800004AD` | 1197 | `ZZNET_ERROR_IMPORT_FACEDB_SDFULL` | Face Database Import: Storage space is full, cannot import. |
| `0x800004AE` | 1198 | `ZZNET_ERROR_IMPORT_FACEDB_CIPHER_ERROR` | Face Database Import: Incorrect password for import package. |
| `0x800004AF` | 1199 | `ZZNET_ERROR_EXPORT_FACEDB_NO_AUTH` | Face Database Export: No permission. |
| `0x800004B0` | 1200 | `ZZNET_ERROR_EXPORT_FACEDB_NO_FILE` | Face Database Export: File not found. |
| `0x800004B1` | 1201 | `ZZNET_ERROR_EXPORT_FACEDB_FILE_FAIL` | Face Database Export: File preparation failed. |
| `0x800004B2` | 1202 | `ZZNET_ERROR_EXPORT_FACEDB_BUSY` | Face Database Export: System is busy. |
| `0x800004B3` | 1203 | `ZZNET_ERROR_EXPORT_FACEDB_NO_PASSWORD` | Face Database Export: No password defined, export not allowed. |
| `0x800004B4` | 1204 | `ZZNET_ERROR_REQUESTED_TOO_MUCH_DATA` | Too much data requested, device cannot process. |
| `0x800004B5` | 1205 | `ZZNET_ERROR_BATCH_PROCESS_ERROR` | An error occurred during batch business execution. |
| `0x800004B6` | 1206 | `ZZNET_ERROR_OPERATION_CANCELLED` | Business execution cancelled for some reason. |
| `0x800004B7` | 1207 | `ZZNET_ERROR_DEVICE_INVALID` | Device model is incorrect, cannot proceed further. |
| `0x800004B8` | 1208 | `ZZNET_ERROR_DEVICE_UNAVAILABLE` | Unable to retrieve device status information. |
| `0x800004B9` | 1209 | `ZZNET_ERROR_FINGERPRINT_DOWNLOAD_FAIL` | Failed to download fingerprint via URL. |
| `0x800004BA` | 1210 | `ZZNET_ERROR_ACCOUNT_IN_USE` | Account is currently logged in. |
| `0x800004BB` | 1211 | `ZZNET_ERROR_IRIS_INFO_NOT_EXISTED` | When updating user iris information, the user has no iris templates. |
| `0x800004BC` | 1212 | `ZZNET_ERROR_INVALID_IRIS_DATA` | The issued iris data format or feature size is incorrect. |
| `0x800004BD` | 1213 | `ZZNET_ERROR_IRIS_ALREADY_EXIST` | Iris information already exists. |
| `0x800004BE` | 1214 | `ZZNET_ERROR_ERASE_IRIS_FAILED` | Failed to delete iris information. |
| `0x800004BF` | 1215 | `ZZNET_ERROR_EXCEED_MAX_IRIS_GROUP_COUNT_PER_USER` | Exceeds the maximum number of iris groups supported per user (one group consists of two irises: left and right). |
| `0x800004C0` | 1216 | `ZZNET_ERROR_EXCEED_MAX_IRIS_COUNT_PER_GROUP` | Exceeds the maximum number of iris records allowed per group for an individual. |
| `0x800004C1` | 1217 | `ZZNET_ERROR_DOOR_IN_NORMALLY_OPEN_STATUS` | Door is in normally open state. |
| `0x800004C2` | 1218 | `ZZNET_ERROR_DOOR_IN_NORMALLY_CLOSED_STATUS` | Door is in normally closed state. |
| `0x800004C3` | 1219 | `ZZNET_ERROR_DOOR_IN_INTERLOCK_STATUS` | Door is in interlock state. |
| `0x800004C4` | 1220 | `ZZNET_ERROR_INVALID_PWD_DATA` | The issued password data is incorrect. |
| `0x800004C5` | 1221 | `ZZNET_ERROR_TYPE_OR_NOT_SUPPORT` | Password type is incorrect or this feature is not supported. |
| `0x800004C6` | 1222 | `ZZNET_ERROR_DOOR_PERMISSION_NOT_EXIST` | Invalid door permission group. |
| `0x800004C7` | 1223 | `ZZNET_ERROR_INVALID_DOOR_PERMISSION_DATA` | Invalid door permission group data. |
| `0x800004C8` | 1224 | `ZZNET_ERROR_INVALID_HOLIDAY_SCHEDULE_DATA` | Invalid holiday schedule data. |
| `0x800004C9` | 1225 | `ZZNET_ERROR_INVALID_PERMISSION_GROUP_DATA` | Invalid permission group data. |
| `0x800004CA` | 1226 | `ZZNET_ERROR_INVALID_TASKID_DATA` | Invalid task ID data. |
| `0x800004CB` | 1227 | `ZZNET_ERROR_INVALID_TIME_TEMPLATE_DATA` | Invalid time template data. |
| `0x800004CC` | 1228 | `ZZNET_ERROR_INVALID_USER_PERMISSION_DATA` | Invalid user permission data. |
| `0x800004CD` | 1229 | `ZZNET_ERROR_TIME_TEMPLATE_ASSOCIATED` | Time template is bound and cannot be deleted. |
| `0x800004CE` | 1230 | `ZZNET_ERROR_HOLIDAY_SCHEDULE_ASSOCIATED` | Holiday schedule is bound and cannot be deleted. |
| `0x800004CF` | 1231 | `ZZNET_ERROR_NAME_ALREADY_EXIST` | Name already exists. |
| `0x800004D0` | 1232 | `ZZNET_ERROR_CONFIG_FAILED` | Configuration issuance failed. |
| `0x800004D1` | 1233 | `ZZNET_ERROR_INVALID_ATTENDANCE_DATA` | Incorrect attendance data issued. |
| `0x800004D2` | 1234 | `ZZNET_ERROR_DO_NOT_EDIT` | Data is not allowed to be edited. |
| `0x800004D3` | 1235 | `ZZNET_ERROR_BINDING` | Data is bound. |
| `0x800004D4` | 1236 | `ZZNET_ERROR_HAND_PRINT_INFO_NOT_EXISTED` | When updating user palm print information, the user has no palm print data. |
| `0x800004D5` | 1237 | `ZZNET_ERROR_INVALID_HAND_PRINT_DATA` | The issued palm print data format or feature size is incorrect. |
| `0x800004D6` | 1238 | `ZZNET_ERROR_HANDPRINT_ALREADY_EXIST` | Palm print already exists. |
| `0x800004D7` | 1239 | `ZZNET_ERROR_ERASE_HANDPRINT_FAILED` | Failed to delete palm print information. |
| `0x800004D8` | 1240 | `ZZNET_ERROR_EXCEED_MAX_HANDPRINT_GROUP_COUNT_PER_USER` | Exceeds the maximum number of palm print groups supported per user (one group consists of two palms: left and right). |
| `0x800004D9` | 1241 | `ZZNET_ERROR_EXCEED_MAX_HANDPRINT_COUNT_PER_GROUP` | Exceeds the maximum number of palm print records allowed per group for an individual. |
| `0x800004DA` | 1242 | `ZZNET_ERROR_FACEMANAGER_FEATURE_SIZE_ERROR` | Face feature size error. |
| `0x80000514` | 1300 | `ZZNET_ERROR_FACEMANAGER_NO_FACE_DETECTED` | No faces detected in the image. |
| `0x80000515` | 1301 | `ZZNET_ERROR_FACEMANAGER_MULTI_FACE_DETECTED` | Multiple faces detected in the image, cannot return features. |
| `0x80000516` | 1302 | `ZZNET_ERROR_FACEMANAGER_PICTURE_DECODING_ERROR` | Image decoding error. |
| `0x80000517` | 1303 | `ZZNET_ERROR_FACEMANAGER_LOW_PICTURE_QUALITY` | Image quality is too low. |
| `0x80000518` | 1304 | `ZZNET_ERROR_FACEMANAGER_NOT_RECOMMENDED` | Results not recommended for use (e.g., for foreigners, feature extraction succeeds but algorithm support is poor, prone to misidentification). |
| `0x80000519` | 1305 | `ZZNET_ERROR_FACEMANAGER_FACE_FEATURE_ALREADY_EXIST` | Face feature already exists. |
| `0x8000051B` | 1307 | `ZZNET_ERROR_FACEMANAGER_FACE_ANGLE_OVER_THRESHOLDS` | Face angle exceeds configured thresholds. |
| `0x8000051C` | 1308 | `ZZNET_ERROR_FACEMANAGER_FACE_RADIO_EXCEEDS_RANGE` | Face ratio exceeds range. Algorithm recommended ratio: no more than 2/3; no less than 1/3. |
| `0x8000051D` | 1309 | `ZZNET_ERROR_FACEMANAGER_FACE_OVER_EXPOSED` | Face is overexposed. |
| `0x8000051E` | 1310 | `ZZNET_ERROR_FACEMANAGER_FACE_UNDER_EXPOSED` | Face is underexposed. |
| `0x8000051F` | 1311 | `ZZNET_ERROR_FACEMANAGER_BRIGHTNESS_IMBALANCE` | Face brightness imbalance (used to judge阴阳脸/yin-yang face). |
| `0x80000520` | 1312 | `ZZNET_ERROR_FACEMANAGER_FACE_LOWER_CONFIDENCE` | Face confidence is low. |
| `0x80000521` | 1313 | `ZZNET_ERROR_FACEMANAGER_FACE_LOW_ALIGN` | Face alignment score is low. |
| `0x80000522` | 1314 | `ZZNET_ERROR_FACEMANAGER_FRAGMENTARY_FACE_DETECTED` | Detected face is occluded or incomplete. |
| `0x80000523` | 1315 | `ZZNET_ERROR_FACEMANAGER_PUPIL_DISTANCE_NOT_ENOUGH` | Inter-pupillary distance is less than threshold. |
| `0x80000524` | 1316 | `ZZNET_ERROR_FACEMANAGER_FACE_DATA_DOWNLOAD_FAILED` | Failed to download face data. |
| `0x80000525` | 1317 | `ZZNET_ERROR_CITIZENMANAGER_ERROR_WORKINGMODE_ERROR` | Operation mode error. |
| `0x80000526` | 1318 | `ZZNET_ERROR_CITIZENMANAGER_ERROR_CAPTURE_BUSY` | Capture is busy. |
| `0x80000527` | 1319 | `ZZNET_ERROR_CITIZENMANAGER_ERROR_CAPTURE_TYPE_ERROR` | This capture method is not supported. |
| `0x80000528` | 1320 | `ZZNET_ERROR_NORMAL_USER_NOTSUPPORT` | Regular users do not support issuance. |
| `0x80000529` | 1321 | `ZZNET_ERROR_THERMOGRAPHY_REF_SENSOR_OPEN_INVALID` | Forced start of thermostat is invalid; maximum daily start times reached. |
| `0x8000052A` | 1322 | `ZZNET_ERROR_THERMOGRAPHY_REF_DELAY_SHUT_DOWN_INVALID` | Delayed shutdown of thermostat is invalid; maximum daily delays reached. |
| `0x8000052B` | 1323 | `ZZNET_ERROR_CITIZENID_EXIST` | ID number already exists. |
| `0x8000052C` | 1324 | `ZZNET_ERROR_FACEMANAGER_FACE_FFE_FAILED` | Face detected, but feature extraction failed (algorithm scenario). |
| `0x8000052D` | 1325 | `ZZNET_ERROR_FACEMANAGER_PHOTO_FEATURE_FAILED_FOR_FA` | Face photo feature extraction failed due to non-compliant attributes (e.g., mask, hat, sunglasses). |
| `0x8000052E` | 1326 | `ZZNET_ERROR_FACEMANAGER_FACE_DATA_PHOTO_INCOMPLETE` | Face photo is incomplete. |
| `0x8000052F` | 1327 | `ZZNET_ERROR_DATABASE_ERROR_INSERT_OVERFLOW` | Database insertion overflow. |
| `0x80000530` | 1328 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_GROUPID_EXCEED` | Work Uniform Detection Compliance Library: Group ID exceeds maximum value. |
| `0x80000531` | 1329 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_ABSTRACT_INIT_ERROR` | Work Uniform Detection Compliance Library: Failed to start modeling analyzer. |
| `0x80000532` | 1330 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_GROUPID_NOT_FOUND` | Work Uniform Detection Compliance Library: Group ID does not exist or is empty. |
| `0x80000533` | 1331 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_DATABASE_ERROR` | Work Uniform Detection Compliance Library: Database operation failed. |
| `0x80000534` | 1332 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_TOKEN_ERROR` | Work Uniform Detection Compliance Library: Token does not exist or is empty. |
| `0x80000535` | 1333 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_BEGINNUM_OVERRUN` | Work Uniform Detection Compliance Library: Query start number is greater than total count. |
| `0x80000536` | 1334 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_ABSTRACT_STATE` | Work Uniform Detection Compliance Library: Device is modeling. |
| `0x80000537` | 1335 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_BIGPIC_MAXNUM` | Work Uniform Detection Compliance Library: Number of panoramic images imported at one time exceeds limit. |
| `0x80000538` | 1336 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_OBJECT_MAXNUM` | Work Uniform Detection Compliance Library: Number of work uniforms exceeds limit. |
| `0x80000539` | 1337 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_GROUP_SPACE_EXCEED` | Work Uniform Detection Compliance Library: Exceeds compliance library space limit. |
| `0x8000053A` | 1338 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_ABSTRACTNUM_ZERO` | Work Uniform Detection Compliance Library: Number of items requiring manual modeling is zero. |
| `0x8000053B` | 1339 | `ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_INVALID_PARAM` | Work Uniform Detection Compliance Library: Invalid parameter. |
| `0x8000053C` | 1340 | `ZZNET_ERROR_CARD_NOT_EXIST` | Card number does not exist. |
| `0x8000053D` | 1341 | `ZZNET_ERROR_TEMPORARY_OUTDATED` | Temporary library is outdated. |
| `0x8000053E` | 1342 | `ZZNET_ERROR_AUTH_CODE_TIME_OUT` | Security code has expired. |
| `0x80000579` | 1401 | `ZZNET_SUBBIZ_INVALID_SOCKET` | Invalid connection. |
| `0x8000057A` | 1402 | `ZZNET_SUBBIZ_PAUSE_ERROR` | Failed to pause media file download. |
| `0x8000057B` | 1403 | `ZZNET_SUBBIZ_GET_PORT_ERROR` | Failed to obtain private tunnel upward listening port. |
