#ifndef ZZNETSDK_H
#define ZZNETSDK_H

#include "ZZGlobal.h"
#include "ZZConfig.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_Init(ffDisConnect cbDisConnect, LDWORD dwUser);

///@brief Return the error code of function execution failure
///@return Error code information
ZZNETSDK_API DWORD CALL_METHOD ZZNETSDK_GetLastError(void);

// Set alarm callback function
ZZNETSDK_API void CALL_METHOD ZZNETSDK_SetDVRMessCallBack(fMessCallBack cbMessage,LDWORD dwUser);

ZZNETSDK_API void CALL_METHOD ZZNETSDK_SetDVRMessCallBackEx1(fMessCallBackEx1 cbMessage,LDWORD dwUser);
// Set snapshot callback function
ZZNETSDK_API void CALL_METHOD ZZNETSDK_SetSnapRevCallBack(fSnapRev OnSnapRevMessage, LDWORD dwUser);

///@brief SDK exit cleanup
///@return
ZZNETSDK_API void CALL_METHOD ZZNETSDK_Cleanup();

///@brief Active registration function, start service; nTimeout parameter is invalid (default to SDK internal logout after device disconnection)
///@param[in] ip IP address
///@param[in] port Port information
///@param[in] nTimeout Timeout
///@param[in] cbListen Callback function
///@param[in] dwUserData User parameter
///@return Service handle
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_ListenServer(char* ip, WORD port, int nTimeout, fServiceCallBack cbListen, LDWORD dwUserData);

///@brief Stop service
///@param[in] lServerHandle Service handle
///@return TRUE for success, FALSE for failure
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StopListenServer(LLONG lServerHandle);

///@brief Login extended interface
///@param[in] pchDVRIP IP address
///@param[in] wDVRPort Port
///@param[in] pchUserName Username
///@param[in] pchPassword Password
///@param[in] nSpecCap Login type
///				nSpecCap = 0 for TCP login, void* pCapParam set to NULL
/// 			nSpecCap = 2 for active registration login, void* pCapParam set to active registration device ID
/// 			nSpecCap = 3 for multicast login, void* pCapParam set to NULL
///            	nSpecCap = 4 for UDP login, void* pCapParam set to NULL
/// 			nSpecCap = 6 for main connection only login, void* pCapParam set to NULL
///			 	nSpecCap = 7 for SSL encryption, void* pCapParam set to NULL
///            	nSpecCap = 9 for remote device login, void* pCapParam set to remote device name string
///            	nSpecCap = 12 for LDAP login, void* pCapParam set to NULL
///            	nSpecCap = 13 for AD login, void* pCapParam set to NULL
///            	nSpecCap = 14 for Radius login, void* pCapParam set to NULL
///            	nSpecCap = 15 for Socks5 login, void* pCapParam set to Socks5 server IP&&port&&ServerName&&ServerPassword string
///            	nSpecCap = 16 for proxy login, void* pCapParam set to SOCKET value
///            	nSpecCap = 19 for P2P login, void* pCapParam set to NULL
///            	nSpecCap = 20 for mobile client login, void* pCapParam set to NULL
///@param[in] pCapParam See nSpecCap definition, memory allocated and released by user
///@param[out] lpDeviceInfo Device information, memory allocated and released by user
///@param[out] error Error code, when login fails: error code description refer to ZZNETSDK_Login
///@return Login handle
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_LoginEx(const char *pchDVRIP, WORD wDVRPort, const char *pchUserName, const char *pchPassword, int nSpecCap, void* pCapParam, LPZZNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// Logout from device
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_Logout(LLONG lLoginID);

// Start real-time monitoring--extended
// For multi-screen preview, nChannelID NVR device fills video output channel number
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_RealPlayEx(LLONG lLoginID, int nChannelID, HWND hWnd, ZZ_RealPlayType rType = ZZ_RType_Multiplay);

// Set real-time monitoring data callback
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetRealDataCallBack(LLONG lRealHandle, fRealDataCallBack cbRealData, LDWORD dwUser);

///@brief Force I-frame; nChannelID: channel number, nSubChannel: stream type (0: main, 1: sub-stream 1)
///@param[in] lLoginID Login handle
///@param[in] nChannelID  Channel number
///@param[in] nSubChannel  Stream sequence number
///@return TRUE for success, FALSE for failure
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_MakeKeyFrame(LLONG lLoginID, int nChannelID, int nSubChannel=0);

// Set encoding buffer policy, pInBuf memory allocated and released by user
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetRealplayBufferPolicy(LLONG lPlayHandle, ZZNET_IN_BUFFER_POLICY* pInBuf, int nWaitTime);

///@brief Stop real-time preview
///@param[in] lRealHandle Play handle
///@return TRUE for success, FALSE for failure
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StopRealPlay(LLONG lRealHandle);

// Set voice intercom mode, client mode or server mode (pValue memory allocated and released by user, size according to EM_ZZUSEDEV_MODE corresponding structure)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetDeviceMode(LLONG lLoginID, EM_ZZUSEDEV_MODE emType, void* pValue);

// Query all recording files within time period
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_QueryRecordFile(LLONG lLoginID, int nChannelId, int nRecordFileType, LPZZNET_TIME tmStart, LPZZNET_TIME tmEnd, char* pchCardid, LPZZNET_RECORDFILE_INFO nriFileinfo, int maxlen, int *filecount, int waittime=1000, BOOL bTime = FALSE);

// Download recording file--extended
// When sSavedFileName is not empty, recording data is written to the file corresponding to that path; when fDownLoadDataCallBack is not empty, recording data is returned through callback function
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_DownloadByRecordFileEx(LLONG lLoginID, LPZZNET_RECORDFILE_INFO lpRecordFile, char *sSavedFileName, 
    fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData, 
    fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, void* pReserved = NULL);


    // Download by time--extended
// When sSavedFileName is not empty, recording data is written to the file corresponding to that path; when fDownLoadDataCallBack is not empty, recording data is returned through callback function
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_DownloadByTimeEx(LLONG lLoginID, int nChannelId, int nRecordFileType, LPZZNET_TIME tmStart, LPZZNET_TIME tmEnd, char *sSavedFileName, 
    ffTimeDownLoadPosCallBack cbTimeDownLoadPos, LDWORD dwUserData, 
    fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, void* pReserved = NULL);


// Specify stream type to start download, the file downloaded and data callback function fDownLoadDataCallBack will get the stream type specified by emDataType
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_DownloadByDataType(LLONG lLoginID, const ZZNET_IN_DOWNLOAD_BY_DATA_TYPE* pstInParam, ZZNET_OUT_DOWNLOAD_BY_DATA_TYPE* pstOutParam, DWORD dwWaitTime);


// Stop recording download
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StopDownload(LLONG lFileHandle);

// Playback by time--extended
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_PlayBackByTimeEx(LLONG lLoginID, int nChannelID, LPZZNET_TIME lpStartTime, LPZZNET_TIME lpStopTime, HWND hWnd, 
    fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
    fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser);

// Intelligent search playback (lpPlayBackParam memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SmartSearchPlayBack(LLONG lPlayHandle, LPZZIntelligentSearchPlay lpPlayBackParam);

// Stop recording playback
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StopPlayBack(LLONG lPlayHandle);

// Locate recording playback start point
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SeekPlayBack(LLONG lPlayHandle, unsigned int offsettime, unsigned int offsetbyte);

// Pause or resume recording playback
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_PausePlayBack(LLONG lPlayHandle, BOOL bPause);

// Fast forward recording playback
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_FastPlayBack(LLONG lPlayHandle);

// Slow forward recording playback
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SlowPlayBack(LLONG lPlayHandle);

// Query remote device status, when nType is ZZ_DEVSTATE_ALARM_FRONTDISCONNECT, channel number starts from 1 (pBuf memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_QueryRemotDevState(LLONG lLoginID, int nType, int nChannelID, char *pBuf, int nBufLen, int *pRetLen, int waittime=1000);

// Get configuration information (szOutBuffer memory allocated and released by user, see enumeration type description for details)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetConfig(LLONG lLoginID, ZZNET_EM_CFG_OPERATE_TYPE emCfgOpType, int nChannelID,
    void* szOutBuffer, DWORD dwOutBufferSize, int waittime=ZZNET_INTERFACE_DEFAULT_TIMEOUT, void *reserve = NULL);

// Set configuration information (szInBuffer memory allocated and released by user, see enumeration type description for details)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetConfig(LLONG lLoginID, ZZNET_EM_CFG_OPERATE_TYPE emCfgOpType, int nChannelID,
    void* szInBuffer, DWORD dwInBufferSize, int waittime=ZZNET_INTERFACE_DEFAULT_TIMEOUT, int *restart = NULL, void *reserve = NULL);

// Query earliest recording time (pFurthrestTime memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_QueryFurthestRecordTime(LLONG lLoginID, int nRecordFileType, char *pchCardid, ZZNET_FURTHEST_RECORD_TIME* pFurthrestTime, int nWaitTime);

// File download, only suitable for small files, pInParam and pOutParam memory allocated and released by user
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_DownloadRemoteFile(LLONG lLoginID, const ZZ_IN_DOWNLOAD_REMOTE_FILE* pInParam, ZZ_OUT_DOWNLOAD_REMOTE_FILE* pOutParam, int nWaitTime = 1000);

// Query device status (pBuf memory allocated and released by user, according to nType type determine corresponding structure, at least need to allocate memory of structure size)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_QueryDevState(LLONG lLoginID, int nType, char *pBuf, int nBufLen, int *pRetLen, int waittime=1000);

/////////////////////////////////Face Recognition Interface/////////////////////////////////////////
// Face recognition database information operation (including add, modify and delete), pstInParam and pstOutParam memory allocated and released by user
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_OperateFaceRecognitionDB(LLONG lLoginID, const ZZNET_IN_OPERATE_FACERECONGNITIONDB* pstInParam, ZZNET_OUT_OPERATE_FACERECONGNITIONDB *pstOutParam, int nWaitTime = 1000);

// Cancel control from face library perspective, pstInParam and pstOutParam memory allocated and released by user
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_FaceRecognitionDelDisposition(LLONG lLoginID, const ZZNET_IN_FACE_RECOGNITION_DEL_DISPOSITION_INFO* pstInParam, ZZNET_OUT_FACE_RECOGNITION_DEL_DISPOSITION_INFO *pstOutParam, int nWaitTime = 1000);

// Deploy control from face library perspective, pstInParam and pstOutParam memory allocated and released by user
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_FaceRecognitionPutDisposition(LLONG lLoginID, const ZZNET_IN_FACE_RECOGNITION_PUT_DISPOSITION_INFO* pstInParam, ZZNET_OUT_FACE_RECOGNITION_PUT_DISPOSITION_INFO *pstOutParam, int nWaitTime = 1000);

// Query face recognition personnel group information, pstInParam and pstOutParam memory allocated and released by user
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_FindGroupInfo(LLONG lLoginID, const ZZNET_IN_FIND_GROUP_INFO* pstInParam, ZZNET_OUT_FIND_GROUP_INFO *pstOutParam, int nWaitTime = 1000);

// Face recognition personnel group operation (including add, modify and delete), pstInParam and pstOutParam memory allocated and released by user
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_OperateFaceRecognitionGroup(LLONG lLoginID, const ZZNET_IN_OPERATE_FACERECONGNITION_GROUP* pstInParam, ZZNET_OUT_OPERATE_FACERECONGNITION_GROUP *pstOutParam, int nWaitTime = 1000);



// Query device logs, query by page (pQueryParam, pLogBuffer memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_QueryDeviceLog(LLONG lLoginID, QUERY_ZZ_DEVICE_LOG_PARAM *pQueryParam, char *pLogBuffer, int nLogBufferLen, int *pRecLogNum, int waittime=3000);


// Audio output mode (pInparam, pOutParam memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetSplitAudioOuput(LLONG lLoginID, const ZZ_IN_SET_AUDIO_OUTPUT* pInParam, ZZ_OUT_SET_AUDIO_OUTPUT* pOutParam, int nWaitTime = 1000);
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetSplitAudioOuput(LLONG lLoginID, const ZZ_IN_GET_AUDIO_OUTPUT* pInParam, ZZ_OUT_GET_AUDIO_OUTPUT* pOutParam, int nWaitTime = 1000);

// New configuration interface, query configuration information (in Json format, see configuration SDK for details) (szOutBuffer memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetNewDevConfig(LLONG lLoginID, char* szCommand, int nChannelID, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=500);

// New configuration interface, set configuration information (in Json format, see configuration SDK for details) (szInBuffer memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetNewDevConfig(LLONG lLoginID, char* szCommand, int nChannelID, char* szInBuffer, DWORD dwInBufferSize, int *error, int *restart, int waittime=500);

// New system capability query interface, query system capability information (in Json format, see configuration SDK for details) (szOutBuffer memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_QueryNewSystemInfo(LLONG lLoginID, char* szCommand, int nChannelID, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=1000);

// Get device capabilities (pInBuf, pOutBuf memory allocated and released by user, according to nType corresponding type find corresponding structure, then determine memory size to allocate)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetDevCaps(LLONG lLoginID, int nType, void* pInBuf, void* pOutBuf, int nWaitTime);

// Search device IP across network segments (pIpSearchInfo memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SearchDevicesByIPs(ZZDEVICE_IP_SEARCH_INFO* pIpSearchInfo, ffSearchDevicesCB cbSearchDevices, LDWORD dwUserData, char* szLocalIp, DWORD dwWaitTime);
// pstParam memory allocated and released by user
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetDeviceSearchParam(const ZZNET_DEVICE_SEARCH_PARAM* pstParam);

// Asynchronously search IPC, NVS and other devices in LAN, pUserData represents user data, does not support multi-threaded calls
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_StartSearchDevices(ffSearchDevicesCB cbSearchDevices, void* pUserData, char* szLocalIp=NULL);

// Stop asynchronously searching IPC, NVS and other devices in LAN
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StopSearchDevices(LLONG lSearchHandle);

// Query/set display source (pstuSplitSrc memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetSplitSource(LLONG lLoginID, int nChannel, int nWindow, ZZ_SPLIT_SOURCE* pstuSplitSrc, int nMaxCount, int* pnRetCount, int nWaitTime = 1000);
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetSplitSource(LLONG lLoginID, int nChannel, int nWindow, const ZZ_SPLIT_SOURCE* pstuSplitSrc, int nSrcCount, int nWaitTime = 1000);

// Private PTZ control extended interface, supports 3D fast positioning
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_ZZPTZControlEx(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, LONG lParam1, LONG lParam2, LONG lParam3, BOOL dwStop );

// Private PTZ control extended interface, supports 3D fast positioning, fisheye, param4 memory allocated and released by user, memory size according to ZZ_EXTPTZ_ControlType corresponding structure
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_ZZPTZControlEx2(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, LONG lParam1, LONG lParam2, LONG lParam3, BOOL dwStop , void* param4 = NULL);

// Query configuration information (lpOutBuffer memory allocated and released by user)
ZZNETSDK_API BOOL  CALL_METHOD ZZNETSDK_GetDevConfig(LLONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);

// Set configuration information (lpInBuffer memory allocated and released by user)
ZZNETSDK_API BOOL  CALL_METHOD ZZNETSDK_SetDevConfig(LLONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);

// Query device current time
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_QueryDeviceTime(LLONG lLoginID, LPZZNET_TIME pDeviceTime, int waittime=1000);

// Set device current time
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetupDeviceTime(LLONG lLoginID, LPZZNET_TIME pDeviceTime);

// Query device information (pInBuf, pOutBuf memory allocated and released by user, according to nQueryType corresponding type find corresponding structure, then determine memory size to allocate)
ZZNETSDK_API BOOL  CALL_METHOD ZZNETSDK_QueryDevInfo(LLONG lLoginID, int nQueryType, void* pInBuf, void* pOutBuf, void *pReserved = NULL , int nWaitTime = 1000);

// Subscribe to alarms from device
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StartListen(LLONG lLoginID);

// Subscribe to alarms from device--extended
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StartListenEx(LLONG lLoginID);

// Stop subscribing to alarms
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StopListen(LLONG lLoginID);

// Real-time upload intelligent analysis data-picture (extended interface, bNeedPicFile indicates whether to subscribe to picture files, Reserved type is RESERVED_PARA)
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_RealLoadPictureEx(LLONG lLoginID, int nChannelID, DWORD dwAlarmType, BOOL bNeedPicFile, fAnalyzerDataCallBack cbAnalyzerData, LDWORD dwUser, void* Reserved);

// Stop uploading intelligent analysis data-picture
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StopLoadPic(LLONG lAnalyzerHandle);

// Reboot device
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_RebootDev(LLONG lLoginID);

// Start upgrading device program--extended, pchFileName memory allocated and released by user, size is MAX_PATH
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_StartUpgradeEx(LLONG lLoginID, EM_ZZ_UPGRADE_TYPE emType, char *pchFileName, fUpgradeCallBack cbUpgrade, LDWORD dwUser);

// Send data
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SendUpgrade(LLONG lUpgradeID);

// End upgrading device program
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StopUpgrade(LLONG lUpgradeID);

// Query IO status (pState memory allocated and released by user, according to emType corresponding type find corresponding structure, then determine memory size to allocate)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_QueryIOControlState(LLONG lLoginID, ZZ_IOTYPE emType, void *pState, int maxlen, int *nIOCount, int waittime=1000);

// IO control (pState memory allocated and released by user, according to emType corresponding type find corresponding structure, then determine memory size to allocate)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_IOControl(LLONG lLoginID, ZZ_IOTYPE emType, void *pState, int maxlen);

// Operate device user--maximum support for 64-channel devices (opParam, subParam memory allocated and released by user, according to nOperateType corresponding type find corresponding structure, then determine memory size to allocate)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_OperateUserInfoNew(LLONG lLoginID, int nOperateType, void *opParam, void *subParam, void* pReserved, int waittime = 1000);

// Modify device IP (pDevNetInfo memory allocated and released by user): does not support multi-threaded calls
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_ModifyDevice(ZZDEVICE_NET_INFO_EX *pDevNetInfo, DWORD dwWaitTime, int *iError = NULL, char* szLocalIp = NULL, void *reserved = NULL);

// Capture image; hPlayHandle is monitor or playback handle
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_CapturePicture(LLONG hPlayHandle, const char *pchPicFileName);
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_CapturePictureEx(LLONG hPlayHandle, const char *pchPicFileName, ZZNET_CAPTURE_FORMATS eFormat);

// Capture request
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SnapPicture(LLONG lLoginID, ZZSNAP_PARAMS par);

// Restart system, restore factory defaults (including clearing configuration and deleting accounts) and reboot, implement hard reset function
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_ResetSystem(LLONG lLoginID, const ZZNET_IN_RESET_SYSTEM* pstInParam, ZZNET_OUT_RESET_SYSTEM* pstOutParam, int nWaitTime);

// Device control (param memory allocated and released by user, size according to type corresponding structure)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_ControlDevice(LLONG lLoginID, ZZCtrlType type, void *param, int waittime = 1000);

// Device control extended interface, compatible with ZZNETSDK_ControlDevice (pInBuf, pOutBuf memory allocated and released by user, according to emType determine corresponding structure)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_ControlDeviceEx(LLONG lLoginID, ZZCtrlType emType, void* pInBuf, void* pOutBuf = NULL, int nWaitTime = 1000);

// Initialize account
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_InitDevAccount(const ZZNET_IN_INIT_DEVICE_ACCOUNT* pInitAccountIn, ZZNET_OUT_INIT_DEVICE_ACCOUNT* pInitAccountOut, DWORD dwWaitTime, char* szLocalIp);

// Decode audio data (pAudioDataBuf memory allocated and released by user)
ZZNETSDK_API void CALL_METHOD ZZNETSDK_AudioDec(char *pAudioDataBuf, DWORD dwBufSize);

// Send voice data to device (pSendBuf memory allocated and released by user)
ZZNETSDK_API LONG  CALL_METHOD ZZNETSDK_TalkSendData(LLONG lTalkHandle, char *pSendBuf, DWORD dwBufSize);

// Open voice intercom
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_StartTalkEx(LLONG lLoginID, pfAudioDataCallBack pfcb, LDWORD dwUser);

// Start PC recording
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_RecordStart();

// Stop PC recording
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_RecordStop();

// Stop voice intercom
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StopTalkEx(LLONG lTalkHandle);

// Set volume of voice intercom
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetAudioClientVolume(LLONG lTalkHandle, WORD wVolume);

// Asynchronously query all recording files within time period (pInParam, pOutParam memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StartQueryRecordFile(LLONG lLoginID, ZZNET_IN_START_QUERY_RECORDFILE *pInParam, ZZNET_OUT_START_QUERY_RECORDFILE *pOutParam);

// Start searching recording file frame information (pInParam, pOutParam memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_FindFrameInfo(LLONG lLoginID, ZZNET_IN_FIND_FRAMEINFO_PRAM *pInParam, ZZNET_OUT_FIND_FRAMEINFO_PRAM* pOutParam, int nWaitTime);

// Search recording file frame information, query by specified information count (pInParam, pOutParam memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_FindNextFrameInfo(LLONG lFindHandle, ZZNET_IN_FINDNEXT_FRAMEINFO_PRAM *pInParam, ZZNET_OUT_FINDNEXT_FRAMEINFO_PRAM* pOutParam, int nWaitTime);

// End recording file search
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_FindFrameInfoClose(LLONG lFindHandle);

// Query whether recording files exist on each day of a month
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_QueryRecordStatus(LLONG lLoginID, int nChannelId, int nRecordFileType, LPZZNET_TIME tmMonth, char* pchCardid, LPZZNET_RECORD_STATUS pRecordStatus, int waittime=1000);

// Set tag information
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_FileStreamSetTags(LLONG lFindHandle, ZZNET_IN_FILE_STREAM_TAGS_INFO *pInParam, ZZNET_OUT_FILE_STREAM_TAGS_INFO *pOutParam, int nWaitTime);

// Get tag information
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_FileStreamGetTags(LLONG lFindHandle, ZZNET_IN_FILE_STREAM_GET_TAGS_INFO *pInParam, ZZNET_OUT_FILE_STREAM_GET_TAGS_INFO *pOutParam, int nWaitTime);

// Clear tag information
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_FileStreamClearTags(LLONG lFindHandle, ZZNET_IN_FILE_STREAM_TAGS_INFO *pInParam, ZZNET_OUT_FILE_STREAM_TAGS_INFO *pOutParam, int nWaitTime);

// Start querying logs (currently only supports access control BSC series), pInParam and pOutParam memory allocated and released by user
ZZNETSDK_API LLONG CALL_METHOD ZZNETSDK_StartQueryLog(LLONG lLoginID, const ZZNET_IN_START_QUERYLOG* pInParam, ZZNET_OUT_START_QUERYLOG* pOutParam, int nWaitTime);

// Get logs (currently only supports access control BSC series), pInParam and pOutParam memory allocated and released by user
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_QueryNextLog(LLONG lLogID, ZZNET_IN_QUERYNEXTLOG* pInParam, ZZNET_OUT_QUERYNEXTLOG* pOutParam, int nWaitTime);

// End querying logs (currently only supports access control BSC series)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_StopQueryLog(LLONG lLogID);

// Lens focus control
//    dwFocusCommand = 0 for focus adjustment
//    dwFocusCommand = 1 for continuous focus adjustment
//    dwFocusCommand = 2 for auto focus adjustment, adjust focus to best position. nFocus and nZoom are invalid.
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_FocusControl(LLONG lLoginID, int nChannelID, DWORD dwFocusCommand, double nFocus, double nZoom, void *reserved = NULL, int waittime=500);

ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetPrivacyMasking(LLONG lLoginID, const ZZNET_IN_GET_PRIVACY_MASKING* pstuInParam, ZZNET_OUT_GET_PRIVACY_MASKING* pstuOutParam, int nWaitTime);

ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetPrivacyMaskingEnable(LLONG lLoginID, const ZZNET_IN_GET_PRIVACY_MASKING_ENABLE* pstuInParam, ZZNET_OUT_GET_PRIVACY_MASKING_ENABLE* pstuOutParam, int nWaitTime);

ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetPrivacyMasking(LLONG lLoginID, const ZZNET_IN_SET_PRIVACY_MASKING* pstuInParam, ZZNET_OUT_SET_PRIVACY_MASKING* pstuOutParam, int nWaitTime);

ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetPrivacyMaskingEnable(LLONG lLoginID, const ZZNET_IN_SET_PRIVACY_MASKING_ENABLE* pstuInParam, ZZNET_OUT_SET_PRIVACY_MASKING_ENABLE* pstuOutParam, int nWaitTime);

ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_DeletePrivacyMasking(LLONG lLoginID, const ZZNET_IN_DELETE_PRIVACY_MASKING* pstuInParam, ZZNET_OUT_DELETE_PRIVACY_MASKING* pstuOutParam, int nWaitTime);

ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetThumbnail(LLONG lLoginID, const ZZNET_IN_GET_THUMBNAIL* pstuInParam, ZZNET_OUT_GET_THUMBNAIL* pstuOutParam, int nWaitTime);

///@brief Export device configuration information
///@param[in] pInParam Input parameters containing information related to exporting configuration
///@param[out] pOutParam Output parameters used to receive the exported configuration data
///@return TRUE for success, FALSE for failure
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_ExportConfig(ZZNET_CONFIG_PARAM *pInParam, ZZNET_EXPORT_CONFIG* pOutParam);

///@brief Import device configuration information
///@param[in] pInParam Input parameters containing information related to importing configuration
///@param[in] szFileName Configuration file path specifying the configuration file to import
///@return TRUE for success, FALSE for failure
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_ImportConfig(ZZNET_CONFIG_PARAM *pInParam,  const char *szFileName);

//////Video Wall
// Video split operation (pInparam, pOutParam memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_OperateSplit(LLONG lLoginID, ZZNET_SPLIT_OPERATE_TYPE emType, void* pInParam, void* pOutParam, int nWaitTime);

// Query matrix card information (pstuCardList memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_QueryMatrixCardInfo(LLONG lLoginID, ZZ_MATRIX_CARD_LIST* pstuCardList, int nWaitTime = 1000);

// Query split capabilities (pstuCaps memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetSplitCaps(LLONG lLoginID, int nChannel, ZZ_SPLIT_CAPS* pstuCaps, int nWaitTime = 1000);

// Set video output options (pstuVideoOut memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetVideoOutOption(LLONG lLoginID, int nChannel, const ZZ_VIDEO_OUT_OPT* pstuVideoOut, int nWaitTime = 1000);

// Open window/close window (pInparam, pOutParam memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_OpenSplitWindow(LLONG lLoginID, const ZZ_IN_SPLIT_OPEN_WINDOW* pInParam, ZZ_OUT_SPLIT_OPEN_WINDOW* pOutParam, int nWaitTime = 1000);
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_CloseSplitWindow(LLONG lLoginID, const ZZ_IN_SPLIT_CLOSE_WINDOW* pInParam, ZZ_OUT_SPLIT_CLOSE_WINDOW* pOutParam, int nWaitTime = 1000);

// Set window tour display source (pInparam, pOutParam memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetTourSource(LLONG lLoginID, const ZZNET_IN_SET_TOUR_SOURCE* pInParam, ZZNET_OUT_SET_TOUR_SOURCE* pOutParam, int nWaitTime = 1000);
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetTourSource(LLONG lLoginID, const ZZNET_IN_GET_TOUR_SOURCE* pInParam, ZZNET_OUT_GET_TOUR_SOURCE* pOutParam, int nWaitTime);

// Set window position (pInparam, pOutParam memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetSplitWindowRect(LLONG lLoginID, const ZZ_IN_SPLIT_SET_RECT* pInParam, ZZ_OUT_SPLIT_SET_RECT* pOutParam, int nWaitTime = 1000);
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetSplitWindowRect(LLONG lLoginID, const ZZ_IN_SPLIT_GET_RECT* pInParam, ZZ_OUT_SPLIT_GET_RECT* pOutParam, int nWaitTime = 1000);

// Query/set split mode (pstuSplitInfo memory allocated and released by user)
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_GetSplitMode(LLONG lLoginID, int nChannel, ZZ_SPLIT_MODE_INFO* pstuSplitInfo, int nWaitTime = 1000);
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_SetSplitMode(LLONG lLoginID, int nChannel, const ZZ_SPLIT_MODE_INFO* pstuSplitInfo, int nWaitTime = 1000);

// Get all valid display sources, pInParam and pOutParam memory allocated and released by user
ZZNETSDK_API BOOL CALL_METHOD ZZNETSDK_MatrixGetCameras(LLONG lLoginID, const ZZ_IN_MATRIX_GET_CAMERAS* pInParam, ZZ_OUT_MATRIX_GET_CAMERAS* pOutParam, int nWaitTime = 1000);

///@brief Parse queried configuration information (szInBuffer, lpOutBuffer memory allocated and released by user)
ZZNETSDK_API BOOL  CALL_METHOD ZZNETSDK_ParseData(char* szCommand, char* szInBuffer, LPVOID lpOutBuffer, DWORD dwOutBufferSize, void* pReserved);

// Compose configuration information to be set (lpInBuffer, szOutBuffer memory allocated and released by user)
ZZNETSDK_API BOOL  CALL_METHOD ZZNETSDK_PacketData(char* szCommand, LPVOID lpInBuffer, DWORD dwInBufferSize, char* szOutBuffer, DWORD dwOutBufferSize);

// Get SDK version
ZZNETSDK_API const char* CALL_METHOD ZZNETSDK_GetVersion();
#ifdef __cplusplus
}
#endif

#endif // ZZNETSDK_H