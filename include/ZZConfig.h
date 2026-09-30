#pragma once


/*#if (defined(WIN32) || defined(_WIN32) || defined(_WIN64))
    #include <windows.h>
    #ifndef LLONG
        #if (defined(WIN32) || defined(_WIN32) || defined(_WIN64))
            #ifdef _WIN64
                #define LLONG       __int64
            #else //WIN32 
                #define LLONG       LONG
            #endif
        #else	//Linux
            #define LLONG           long 
        #endif
    #endif

    #ifndef LDWORD
        #if (defined(WIN32) || defined(_WIN32) || defined(_WIN64))
            #ifdef _WIN64
                #define LDWORD      __int64
            #else //WIN32 
                #define LDWORD      DWORD
            #endif
        #else	//Linux
            #define LDWORD          long 
        #endif
    #endif

#else	//Linux

    #define CALL_METHOD
    #define CALLBACK

#endif*/

#include <cstdint>


typedef int					ZZ_AV_int32;	


/************************************************************************
 ** Constant Definitions
 ***********************************************************************/

 #define ZZC_MAX_CHANNEL_COUNT                       16
 #define ZZC_MAX_VIDEO_CHANNEL_NUM                   256             // Max channel count 256
 #define ZZC_MAX_CHANNELNAME_LEN                     64              // Max channel name length
 #define ZZC_MAX_VIDEOSTREAM_NUM                     4               // Max number of video streams
 #define ZZC_MAX_VIDEO_COVER_NUM                     16              // Max number of cover regions
 #define ZZC_WEEK_DAY_NUM                            7               // Days in a week
 #define ZZC_MAX_REC_TSECT                           6               // Number of recording time sections
 #define ZZC_MAX_REC_TSECT_EX                        10              // Extended number of recording time sections
 #define ZZC_MAX_WATERMARK_LEN                       4096            // Max length of digital watermark data
 #define ZZC_MAX_MOTION_ROW                          32              // Rows for motion detection region
 #define ZZC_MAX_MOTION_COL                          32              // Columns for motion detection region
 #define ZZC_MAX_IMAGESIZE_NUM                       256             // Max number of supported resolutions
 #define ZZC_MAX_FPS_NUM                             1024            // Max number of supported frame rates
 #define ZZC_MAX_QUALITY_NUM                         32              // Max number of supported quality levels
 #define ZZC_MAX_ADDRESS_LEN                         256             // Max address length
 #define ZZC_MAX_USERNAME_LEN                        64              // Max username length
 #define ZZC_MAX_PASSWORD_LEN                        64              // Max password length
 #define ZZC_MAX_DIRECTORY_LEN                       256             // Directory name string length
 #define ZZC_MAX_NAS_TIME_SECTION                    2               // Number of NAS time sections
 #define ZZC_MAX_NAME_LEN                            128             // Common name string length
 #define ZZC_MAX_SCENE_TYPE_LIST_SIZE                8               // Max number of scenes supported in scene list
 #define ZZC_MAX_DECPRO_LIST_SIZE                    100             // Max number of decoder protocols
 #define ZZC_MAX_SCENE_LIST_SIZE                     32              // Max number of scene types supported by video analysis device
 #define ZZC_MAX_OBJECT_LIST_SIZE                    16              // Max number of object types supported by video analysis device
 #define ZZC_MAX_RULE_LIST_SIZE                      128             // Max number of rules supported by video analysis device
 #define ZZC_MAX_SUPPORTED_COMP_SIZE                 4               // Max supported scene composition items
 #define ZZC_MAX_SUPPORTED_COMP_DATA                 8               // Max supported scenes per composition item
 #define ZZC_MAX_ANALYSE_MODULE_NUM                  16              // Max detection modules for video analysis device
 #define ZZC_MAX_ANALYSE_RULE_NUM                    32              // Max rules for video analysis device
 #define ZZC_MAX_POLYGON_NUM                         20              // Max vertices for region in video analysis device
 #define ZZC_MAX_POLYLINE_NUM                        20              // Max vertices for polyline in video analysis device
 #define ZZC_MAX_TEMPLATEREGION_NUM                  32              // Max number of simulation region point pairs for video analysis
 #define ZZC_POINT_PAIR_NUM                          2               // Number of points in a point pair for simulation region
 #define ZZC_MAX_VEHICLE_SIZE_LIST                   4               // Max number of vehicle sizes
 #define ZZC_MAX_VEHICLE_TYPE_LIST                   4               // Max number of vehicle types
 #define ZZC_MAX_PLATE_TYPE_LIST                     32              // Max number of license plate types
 #define ZZC_MAX_LANE_NUM                            8               // Max number of lanes per channel
 #define ZZC_MAX_STAFF_NUM                           20              // Max number of rulers per channel
 #define ZZC_MAX_CALIBRATEAREA_NUM                   20              // Max number of calibration areas
 #define ZZC_MAX_EXCLUDEREGION_NUM                   10              // Max number of excluded regions in intelligent analysis
 #define ZZC_MAX_CALIBRATEBOX_NUM                    10              // Max number of calibration boxes in intelligent analysis
 #define ZZC_MAX_SPECIALDETECT_NUM                   10              // Max number of special detection regions
 #define ZZC_MAX_HUMANFACE_LIST_SIZE                 8               // Max number of face detection types supported
 #define ZZC_MAX_FEATURE_LIST_SIZE					32				// Max number of face attribute types supported
 #define ZZC_MAX_SEVER_NUM                           16              // Max number of service types
 #define ZZC_MAX_SERVER_NAME_LEN                     16              // Service name string length
 #define ZZC_MAX_POWER_NUM                           8               // Max number of power supplies
 #define ZZC_MAX_FUN_NUM                             8               // Max number of fans
 #define ZZC_MAX_CPU_NUM                             8               // Max number of CPUs
 #define ZZC_MAX_HARDDISK_NUM                        32              // Max number of hard disks
 #define ZZC_MAX_TANK_NUM                            16              // Max number of storage tanks/cabinets
 #define ZZC_MAX_CHAN_NUM                            256             // Max channel limit
 #define ZZC_MAX_RAID_NUM                            16              // Max RAID array limit
 #define ZZC_MAX_DEV_NUM                             16              // Max device limit
 #define ZZC_MAX_STORAGEPOOL_NUM                     16              // Max storage pool limit
 #define ZZC_MAX_STRORAGEPOS_NUM                     16              // Max storage position limit
 #define ZZC_MAX_VIDEODEV_NUM                        256             // Max front-end device limit
 #define ZZC_MAX_REMOTEDEVICENAME_LEN                32              // Max remote device name length
 #define ZZC_MAX_REMOTE_DEV_NUM                      256             // Max remote device quantity
 #define ZZC_MAX_PLATEHINT_NUM                       8               // Max number of plate character hints
 #define ZZC_MAX_LIGHT_NUM                           8               // Max number of traffic lights
 #define ZZC_MAX_LIGHTGROUP_NUM                      8               // Max number of traffic light groups
 #define ZZC_MAX_LIGHT_TYPE                          8               // Max number of traffic light types
 #define ZZC_MAX_LIGHT_DIRECTION                     8               // Max number of traffic light directions
 #define ZZC_MAX_TRIGGERMODE_NUM                     32              // Max number of traffic intersection rule trigger modes
 #define ZZC_MAX_VIOLATIONCODE                       16              // Max length of traffic violation code
 #define ZZC_MAX_DETECTOR                            6               // Max traffic detector configuration
 #define ZZC_MAX_COILCONFIG                          3               // Max traffic detector coil configuration
 #define ZZC_MAX_DEVICE_ADDRESS                      256             // TrafficSnapshot intelligent traffic device address
 #define ZZC_MAX_DEPARTMENT                          256             // Department for intelligent traffic device
 #define ZZC_MAX_ROADWAYNO                           128             // Road number, composed of 32 digits/letters
 #define ZZC_MAX_VIOLATIONCODE_DESCRIPT              64              // Max length of traffic violation description
 #define ZZC_MAX_DRIVINGDIRECTION                    256             // Driving direction string length
 #define ZZC_MAX_ACTIVEUSER_NUM                      64              // Max number of active users
 #define ZZC_MAX_POLYGON_NUM10                       10              // Max vertices for region (Limit 10)
 #define ZZC_MAX_VIDEODIAGNOSIS_DETECT_TYPE          11              // Max number of video diagnosis types
 #define ZZC_MAX_ACTION_LIST_SIZE                    16              // Max number of rule action types supported
 #define ZZC_MAX_STORAGEGROUPNAME_LEN                32              // Storage group name buffer limit
 #define ZZC_MAX_CALIBRATEAREA_TYPE_NUM              4               // Max number of calibration area types
 #define ZZC_MAX_PROTOCOL_NAME_LEN                   32              // Protocol name length
 #define ZZC_MAX_COMM_NUM                            16              // Max serial port quantity
 #define ZZC_MAX_DNS_SERVER_NUM                      2               // Max DNS quantity
 #define ZZC_MAX_NETWORK_INTERFACE_NUM               32              // Max network interface quantity
 #define ZZC_MAX_NAS_NUM                             16              // Max NAS server quantity
 #define ZZC_MAX_STORAGEPOINT_NUM                    32              // Max recording storage point mapping quantity
 #define ZZC_MAX_TRACKSCENE_NUM                      10              // Max intelligent tracking scene quantity
 #define ZZC_MAX_STATUS_NUM                          16              // Max traffic device status count
 #define ZZC_MAX_SERVICE_NUM                         128             // Max services supported by server
 #define ZZC_MAX_DBKEY_NUM                           64              // Max DB key value
 #define ZZC_MAX_SUMMARY_LEN                         1024            // Max length of summary info overlaid on JPEG
 #define ZZC_MAX_MOTION_WINDOW                       10              // Motion detection supported video windows
 #define ZZC_MAX_OSD_SUMMARY_LEN                     256             // Max OSD overlay content length
 #define ZZC_MAX_OSD_TITLE_LEN                       128             // Max OSD overlay title length
 #define ZZC_MAX_CUSTOMCASE_NUM                      16              // Max custom judicial case count
 #define ZZC_MAX_GLOBAL_MSTERSLAVE_NUM               64              // Max global configurations for master-slave tracker
 #define ZZC_MAX_OBJECT_ATTRIBUTES_SIZE              16              // Max number of detection object attribute types
 #define ZZC_MAX_MODEL_LEN                           32              // Device model length
 #define ZZC_MAX_BURNING_DEV_NUM                     32              // Max burning device count
 #define ZZC_MAX_NET_TYPE_NUM                        8               // Max network type count
 #define ZZC_MAX_NET_TYPE_LEN                        64              // Network type string length
 #define ZZC_MAX_DEVICE_NAME_LEN                     64              // Machine name
 #define ZZC_MAX_DEV_ID_LEN_EX                       128             // Device ID max length
 #define ZZC_MONTH_OF_YEAR                           12              // Months in a year
 #define ZZC_MAX_SERVER_NUM                          10              // Max server count
 #define ZZC_MAX_REGISTER_NUM                        10              // Max active register config count
 #define ZZC_MAX_VIDEO_IN_ZOOM                       32              // Max zoom speed configs per channel
 #define ZZC_MAX_ANALYSE_SCENE_NUM                   32              // Max video analysis global config scenes
 #define ZZC_MAX_CONFIG_NUM                          32              // Max configs per PTZ
 #define ZZC_MAX_PTZ_PRESET_NAME_LEN                 64              // PTZ preset name length
 #define ZZC_CFG_COMMON_STRING_8                     8               // Common string length 8
 #define ZZC_CFG_COMMON_STRING_16                    16              // Common string length 16
 #define ZZC_CFG_COMMON_STRING_32                    32              // Common string length 32
 #define ZZC_CFG_COMMON_STRING_64                    64              // Common string length 64
 #define ZZC_CFG_COMMON_STRING_128                   128             // Common string length 128
 #define ZZC_CFG_COMMON_STRING_256                   256             // Common string length 256
 #define ZZC_CFG_COMMON_STRING_512                   512             // Common string length 512
 #define ZZC_AV_CFG_Channel_Name_Len                 64              // Channel name length
 #define ZZC_CFG_MAX_CHANNEL_NAME_LEN                256             // Max channel name length
 #define ZZC_AV_CFG_Weekday_Num                      7               // Days in a week
 #define ZZC_AV_CFG_Max_TimeSection                  6               // Time section quantity
 #define ZZC_AV_CFG_Device_ID_Len                    64              // Device ID length
 #define ZZC_AV_CFG_IP_Address_Len                   32              // IP length
 #define ZZC_AV_CFG_IP_Address_Len_EX                40              // Extended IP address string length, supports IPV6
 #define ZZC_AV_CFG_User_Name_Len                    64              // User name length
 #define ZZC_AV_CFG_Password_Len                     64              // Password length
 #define ZZC_AV_CFG_Protocol_Len                     32              // Protocol name length
 #define ZZC_AV_CFG_Serial_Len                       32              // Serial number length
 #define ZZC_AV_CFG_Device_Class_Len                 16              // Device class length
 #define ZZC_AV_CFG_Device_Type_Len                  32              // Device specific model length
 #define ZZC_AV_CFG_Device_Name_Len                  128             // Machine name
 #define ZZC_AV_CFG_Address_Len                      128             // Machine deployment address
 #define ZZC_AV_CFG_Max_Path                         260             // Path length
 #define ZZC_AV_CFG_Max_Split_Window                 128             // Max split window quantity
 #define ZZC_AV_CFG_Monitor_Favorite_In_Channel      64              // Max tour favorites per output channel
 #define ZZC_AV_CFG_Monitor_Favorite_Name_Len        64              // Favorite name length
 #define ZZC_AV_CFG_Max_Monitor_Favorite_Window      64              // Max windows in favorite
 #define ZZC_AV_CFG_Max_Split_Group                  64              // Max split group quantity
 #define ZZC_AV_CFG_Max_Split_Mode                   32              // Max split mode quantity
 #define ZZC_AV_CFG_Raid_Name_Len                    64              // RAID name length
 #define ZZC_AV_CFG_Max_Rail_Member                  32              // Disks per RAID
 #define ZZC_AV_CFG_Max_Encode_Main_Format           3               // Main stream encode types
 #define ZZC_AV_CFG_Max_Encode_Extra_Format          3               // Extra stream encode types
 #define ZZC_AV_CFG_Max_Encode_Snap_Format           3               // Snapshot encode types
 #define ZZC_AV_CFG_Max_VideoColor                   24              // Max video input color configs per channel
 #define ZZC_AV_CFG_Custom_Title_Len                 1024            // Custom title name length (expanded to 1024)
 #define ZZC_AV_CFG_Custom_TitleType_Len             32              // Custom title type length
 #define ZZC_AV_CFG_Max_Video_Widget_Cover           16              // Max encode region cover quantity
 #define ZZC_AV_CFG_Max_Video_Widget_Custom_Title    8               // Max video widget custom titles
 #define ZZC_AV_CFG_Max_Video_Widget_Sensor_Info     2               // Max sensor info overlaid on video widget
 #define ZZC_AV_CFG_Max_Description_Num              4               // Max overlay region description info
 #define ZZC_AV_CFG_Group_Name_Len                   64              // Group name length
 #define ZZC_AV_CFG_DeviceNo_Len                     32              // Device number length
 #define ZZC_AV_CFG_Group_Memo_Len                   128             // Group memo length
 #define ZZC_AV_CFG_Max_Channel_Num                  1024            // Max channel quantity
 #define ZZC_AV_CFG_Time_Format_Len                  32              // Time format length
 #define ZZC_AV_CFG_Max_White_List                   1024            // White list quantity
 #define ZZC_AV_CFG_Max_Black_List                   1024            // Black list quantity
 #define ZZC_AV_CFG_Filter_IP_Len                    96              // Filter IP max length
 #define ZZC_AV_CFG_Max_ChannelRule                  32              // Max channel storage rule length, channel part only
 #define ZZC_AV_CFG_Max_DBKey_Num                    64              // Event key quantity
 #define ZZC_AV_CFG_DBKey_Len                        32              // Event key length
 #define ZZC_AV_CFG_Max_Summary_Len                  1024            // Summary length
 #define ZZC_AV_CFG_Max_Event_Title_Num              32              // Max event title quantity
 #define ZZC_AV_CFG_Max_Tour_Link_Num                128             // Max linkage tour quantity
 #define ZZC_AV_CFG_PIP_BASE                         1000            // PIP split mode base value
 #define ZZC_DES_KEY_LEN                             8               // DES key byte length
 #define ZZC_DES_KEY_NUM                             3               // 3DES key count
 #define ZZC_AES_KEY_LEN                             32              // AES key byte length
 #define ZZC_MAX_TIME_SCHEDULE_NUM                   8               // Time schedule element count
 #define ZZC_MAX_SCENE_SUBTYPE_LEN                   64              // Scene subtype string length
 #define ZZC_MAX_SCENE_SUBTYPE_NUM                   32              // Max scene subtype count    
 #define ZZC_MAX_VIDEO_IN_FOCUS                      32              // Max focus configs per channel
 #define ZZC_MAX_TIMESPEEDLIMIT_NUM                  16              // Max time section speed limit configs
 #define ZZC_MAX_VOICEALERT_NUM                      64              // Max voice alert configs
 #define ZZC_CFG_MAX_LOWER_MATRIX_NUM                16              // Max lower matrix quantity
 #define ZZC_CFG_MAX_LOWER_MATRIX_INPUT              64              // Max lower matrix input channels
 #define ZZC_CFG_MAX_LOWER_MATRIX_OUTPUT             32              // Max lower matrix output channels
 #define ZZC_CFG_MAX_AUDIO_MATRIX_INPUT              32              // Audio matrix max input channels
 #define ZZC_CFG_MAX_AUDIO_OUTPUT_CHN                32              // Audio matrix max output channels
 #define ZZC_CFG_MAX_AUDIO_MATRIX_NUM                4               // Max audio matrix quantity
 #define ZZC_CFG_MAX_AUDIO_MATRIX_OUTPUT             8               // Max output channels supported per audio matrix
 #define ZZC_CFG_MAX_VIDEO_IN_DEFOG                  3               // Max defog configs per channel
 #define ZZC_CFG_MAX_INFRARED_BOARD_TEMPLATE_NUM     16              // Max infrared board templates
 #define ZZC_CFG_MAX_INFRARED_KEY_NUM                128             // Max infrared board keys
 #define ZZC_CFG_MAX_INFRARED_BOARD_NUM              16              // Max infrared boards
 #define ZZC_CFG_MAX_VTO_NUM                         128             // Max VTO (Video Talk Outdoor) quantity
 #define ZZC_MAX_PHONE_NUMBER_LEN                    32              // Max phone number length
 #define ZZC_MAX_AUDIO_OUTPUT_NUM                    16              // Max audio output channels
 #define ZZC_MAX_AUDIO_INPUT_NUM                     32              // Max audio input channels
 #define ZZC_MAX_LIGHT_GLOBAL_NUM					16				// Max Lechange status light quantity
 #define ZZC_MAX_AUDIO_MIX_NUM                       16              // Max mixed audio channels
 #define ZZC_MAX_PSTN_SERVER_NUM                     8               // Max alarm phone server quantity
 #define ZZC_MAX_ALARM_CHANNEL_NUM                   32              // Max alarm channels
 #define ZZC_MAX_ALARM_DEFENCE_TYPE_NUM              8               // Max alarm defence zone types
 #define ZZC_MAX_ALARM_SENSE_METHOD_NUM              16              // Max alarm sensor methods
 #define ZZC_MAX_EXALARMBOX_PROTOCOL_NUM             8               // Max supported extended alarm box protocols
 #define ZZC_MAX_EXALARM_CHANNEL_NUM                 256             // Max alarm channels (Extended)
 #define ZZC_MAX_EXALARMBOX_NUM                      8               // Max alarm boxes
 #define ZZC_MAX_MAILTITLE_LEN                       256             // Max mail title length
 #define ZZC_MAX_DEVICE_ID_LEN                       48              // Max device code length
 #define ZZC_MAX_DEVICE_MARK_LEN                     64              // Max device description length
 #define ZZC_MAX_BRAND_NAME_LEN                      64              // Max device brand name length
 #define ZZC_MAX_ADDRESS_NUM                         16              // Max serial address count
 #define ZZC_MAX_AIRCONDITION_NUM                    16              // Max air conditioner quantity
 #define ZZC_CFG_MAX_COLLECTION_NUM                  64              // Max plans/collections
 #define ZZC_MAX_FLOOR_NUM                           128             // Max floor number
 #define ZZC_MAX_SEAT_NUM                            8               // Max seat number
 #define ZZC_AV_CFG_Local_Device_ID                  "Local"         // Local device ID
 #define ZZC_AV_CFG_Remote_Devce_ID                  "Remote"        // Remote device ID   
 #define ZZC_MAX_LANE_CONFIG_NUMBER                  32              // Max lane number
 #define ZZC_MAX_PRIORITY_NUMBER                     256             // Max violations in violation priority
 #define ZZC_MAX_CATEGORY_TYPE_NUMBER                128             // Subcategory type number
 #define ZZC_MAX_TRIGGER_MODE_NUMBER                 64              // Trigger mode number
 #define ZZC_MAX_ABNORMAL_DETECT_TYPE                32              // Abnormal detection type number
 #define ZZC_MAX_ABNORMAL_THRESHOLD_LEN              32              // Max abnormal detection thresholds
 #define ZZC_TS_POINT_NUM                            3               // Touch screen calibration points
 #define ZZC_CFG_FILTER_IP_LEN                       96              // Filter IP max length
 #define ZZC_CFG_MAX_TRUST_LIST                      1024            // White list quantity
 #define ZZC_CFG_MAX_BANNED_LIST                     1024            // Black list quantity
 #define ZZC_VIDEOIN_TSEC_NUM                        3               // VideoIn series protocol time sections: Normal, Day, Night
 #define ZZC_MAX_RECT_COUNT                          4               // Max mosaic regions supported per channel
 #define ZZC_CFG_MAX_SSID_LEN                        36              // SSID max length
 #define ZZC_MAX_OUTAUDIO_CHANNEL_COUNT              16              // Max audio output channel count
 #define ZZC_MAX_INAUDIO_CHANNEL_COUNT               32              // Max audio input channel count
 #define ZZC_MAX_FREQUENCY_COUNT                     16              // Max frequency band count
 #define ZZC_MAX_NTP_SERVER                          4               // Max backup NTP server addresses
 #define ZZC_MAX_ACCESS_TEXTDISPLAY_LEN              32              // Max access control display text length
 #define ZZC_CFG_MAX_NVR_ENCRYPT_COUNT               4               // Max encryption configs per channel
 #define ZZC_MAX_IP_ADDR_LEN                         16              // IP address string length
 #define ZZC_MAX_PRIVACY_MASKING_COUNT               64              // Privacy masking configs per channel
 #define ZZC_MAX_ALL_SNAP_CAR_COUNT					32				// Max all vehicle gate-open types
 #define ZZC_CFG_MAX_PLATE_NUMBER_LEN				32				// Max license plate number length
 #define ZZC_CFG_MAX_SN_LEN							32				// Max device serial number length
 #define ZZC_CFG_MAX_ACCESS_CONTROL_ADDRESS_LEN		64				// Max address length
 #define ZZC_MAX_CFG_APN_NAME						32				// Access Point Name length in Wireless
 #define ZZC_MAX_CFG_DAIL_NUMBER						32				// Dial number length in Wireless
 #define ZZC_MAX_CROWD_DISTRI_MAP_REGION_POINT_NUM	4				// Crowd distribution map region points
 #define ZZC_MAX_PEOPLESTATREGIONS_NUM				8				// Number of people counting regions


/************************************************************************
 ** Config Commands - Corresponding to ZZNETSDK_GetNewDevConfig and ZZNETSDK_SetNewDevConfig interfaces
 ***********************************************************************/

 #define ZZ_CFG_CMD_ENCODE                          "Encode"                    // Image channel attribute config (ZZ_CFG_ENCODE_INFO)
 #define ZZ_CFG_CMD_RECORD                          "Record"                    // Schedule record config (CFG_RECORD_INFO)
 #define ZZ_CFG_CMD_ALARMINPUT                      "Alarm"                     // External alarm input config (ZZ_CFG_ALARMIN_INFO)
 #define ZZ_CFG_CMD_NETALARMINPUT                   "NetAlarm"                  // Network alarm config (CFG_NETALARMIN_INFO)
 #define ZZ_CFG_CMD_MOTIONDETECT                    "MotionDetect"              // Motion detection alarm config (CFG_MOTION_INFO)
 #define ZZ_CFG_CMD_VIDEOLOST                       "LossDetect"                // Video loss alarm config (CFG_VIDEOLOST_INFO)
 #define ZZ_CFG_CMD_VIDEOBLIND                      "BlindDetect"               // Video blind/shelter alarm config (CFG_SHELTER_INFO)
 #define ZZ_CFG_CMD_STORAGENOEXIST                  "StorageNotExist"           // No storage device alarm config (CFG_STORAGENOEXIST_INFO)
 #define ZZ_CFG_CMD_STORAGEFAILURE                  "StorageFailure"            // Storage access failure alarm config (CFG_STORAGEFAILURE_INFO)
 #define ZZ_CFG_CMD_STORAGELOWSAPCE                 "StorageLowSpace"           // Storage low space alarm config (CFG_STORAGELOWSAPCE_INFO)
 #define ZZ_CFG_CMD_NETABORT                        "NetAbort"                  // Network abort/disconnect alarm config (CFG_NETABORT_INFO)	
 #define ZZ_CFG_CMD_IPCONFLICT                      "IPConflict"                // IP conflict alarm config (CFG_IPCONFLICT_INFO)
 #define ZZ_CFG_CMD_SNAPCAPINFO                     "SnapInfo"                  // Snapshot capability query (CFG_SNAPCAPINFO_INFO)
 #define ZZ_CFG_CMD_NAS                             "NAS"                       // Network storage server config (CFG_NAS_INFO)
 #define ZZ_CFG_CMD_PTZ                             "Ptz"                       // PTZ config (CFG_PTZ_INFO)
 #define ZZ_CFG_CMD_PTZ_AUTO_MOVEMENT               "PtzAutoMovement"           // PTZ scheduled movement config (CFG_PTZ_AUTOMOVE_INFO)
 #define ZZ_CFG_CMD_WATERMARK                       "WaterMark"                 // Video watermark config (CFG_WATERMARK_INFO)
 #define ZZ_CFG_CMD_ANALYSEGLOBAL                   "VideoAnalyseGlobal"        // Video analysis global config (CFG_ANALYSEGLOBAL_INFO)
 #define ZZ_CFG_CMD_ANALYSEMODULE                   "VideoAnalyseModule"        // Object detection module config (CFG_ANALYSEMODULES_INFO)
 #define ZZ_CFG_CMD_ANALYSERULE                     "VideoAnalyseRule"          // Video analysis rule config (CFG_ANALYSERULES_INFO)
 #define ZZ_CFG_CMD_ANALYSESOURCE                   "VideoAnalyseSource"        // Video analysis source config (CFG_ANALYSESOURCE_INFO)
 #define ZZ_CFG_CMD_RAINBRUSH                       "RainBrush"                 // Wiper config (CFG_RAINBRUSH_INFO)
 #define ZZ_CFG_CMD_INTELLECTIVETRAFFIC             "TrafficSnapshot"           // Intelligent traffic snapshot (CFG_TRAFFICSNAPSHOT_INFO only for compatibility; use CFG_CMD_TRAFFICSNAPSHOT_MULTI)
 #define ZZ_CFG_CMD_TRAFFICGLOBAL                   "TrafficGlobal"             // Intelligent traffic global config (CFG_TRAFFICGLOBAL_INFO)
 #define ZZ_CFG_CMD_DEV_GENERRAL                    "General"                   // General config (CFG_DEV_DISPOSITION_INFO)
 #define ZZ_CFG_CMD_ATMMOTION                       "FetchMoneyOverTime"        // ATM fetch money overtime config (CFG_ATMMOTION_INFO)
 #define ZZ_CFG_CMD_DEVICESTATUS                    "DeviceStatus"              // Device status info (CFG_DEVICESTATUS_INFO)
 #define ZZ_CFG_CMD_HARDDISKTANK                    "HardDiskTank"              // Extension cabinet info (CFG_HARDISKTANKGROUP_INFO)
 #define ZZ_CFG_CMD_RAIDGROUP                       "RaidGroup"                 // Raid group info (CFG_RAIDGROUP_INFO)
 #define ZZ_CFG_CMD_STORAGEPOOLGROUP                "StoragePoolGroup"          // Storage pool group info (CFG_STORAGEPOOLGROUP_INFO)
 #define ZZ_CFG_CMD_STORAGEPOSITIONGROUP            "StoragePositionGroup"      // File system group info (CFG_STORAGEPOSITIONGROUP_INFO)
 #define ZZ_CFG_CMD_VIDEOINDEVGROUP                 "VideoInDevGroup"           // Video input device group info (CFG_VIDEOINDEVGROUP_INFO)
 #define ZZ_CFG_CMD_DEVRECORDGROUP                  "DevRecordGroup"            // Channel record group status (CFG_DEVRECORDGROUP_INFO)
 #define ZZ_CFG_CMD_IPSSERVER                       "IpsServer"                 // Service status (CFG_IPSERVER_STATUS)
 #define ZZ_CFG_CMD_SNAPSOURCE                      "SnapSource"                // Snapshot source config (CFG_SNAPSOURCE_INFO)
 #define ZZ_CFG_CMD_TRANSRADER                      "TransRadar"                // TransRadar config
 #define ZZ_CFG_CMD_LANDUNRADER                     "LanDunRadar"               // LanDun Radar config
 #define ZZ_CFG_CMD_LANDUNCOILS                     "LanDunCoils"               // LanDun Coils config
 #define ZZ_CFG_CMD_MATRIX_SPOT                     "SpotMatrix"                // Spot video matrix (CFG_VIDEO_MATRIX)
 #define ZZ_CFG_CMD_HDVR_DSP                        "DspEncodeCap"              // HDVR dsp info per digital channel, IPC or DVR capabilities (CFG_DSPENCODECAP_INFO)
 #define ZZ_CFG_CMD_HDVR_ATTR_CFG                   "SystemAttr"                // HDVR connected device info per digital channel
 #define ZZ_CFG_CMD_CHANNEL_HOLIDAY                 "HolidaySchedule"           // Holiday record schedule (CFG_HOLIDAY_SCHEDULE array)
 #define ZZ_CFG_CMD_HEALTH_MAIL                     "HealthMail"                // Health status email
 #define ZZ_CFG_CMD_CAMERAMOVE                      "IntelliMoveDetect"         // Camera movement detection linkage 
 #define ZZ_CFG_CMD_SPLITTOUR                       "SplitTour"                 // Video split tour config (CFG_VIDEO_MATRIX)
 #define ZZ_CFG_CMD_VIDEOENCODEROI                  "VideoEncodeROI"            // Video Encode ROI (Region of Interest) config
 #define ZZ_CFG_CMD_VIDEO_INMETERING                "VideoInMetering"           // Metering config (CFG_VIDEO_INMETERING_INFO)
 #define ZZ_CFG_CMD_TRAFFIC_FLOWSTAT                "TrafficFlowStat"           // Traffic flow statistics config (CFG_TRAFFIC_FLOWSTAT_INFO)
 #define ZZ_CFG_CMD_HDMIMATRIX                      "HDMIMatrix"                // HDMI video matrix config
 #define ZZ_CFG_CMD_VIDEOINOPTIONS	                "VideoInOptions"            // Video input front-end options (CFG_VIDEO_IN_OPTIONS)
 #define ZZ_CFG_CMD_RTSP                            "RTSP"                      // RTSP config (CFG_RTSP_INFO_IN and CFG_RTSP_INFO_OUT)
 #define ZZ_CFG_CMD_TRAFFICSNAPSHOT                 "TrafficSnapshotNew"        // Intelligent traffic snapshot (CFG_TRAFFICSNAPSHOT_INFO deprecated, use CFG_CMD_TRAFFICSNAPSHOT_MULTI_EX)
 #define ZZ_CFG_CMD_TRAFFICSNAPSHOT_MULTI           "TrafficSnapshotNew"        // Intelligent traffic snapshot (CFG_TRAFFICSNAPSHOT_NEW_INFO deprecated, use CFG_CMD_TRAFFICSNAPSHOT_MULTI_EX)
 #define ZZ_CFG_CMD_TRAFFICSNAPSHOT_MULTI_EX        "TrafficSnapshotNew"        // Intelligent traffic snapshot (CFG_TRAFFICSNAPSHOT_NEW_EX_INFO)
 #define ZZ_CFG_CMD_MULTICAST                       "Multicast"                 // Multicast config (CFG_MULTICASTS_INFO_IN and CFG_MULTICASTS_INFO_OUT)
 #define ZZ_CFG_CMD_VIDEODIAGNOSIS_PROFILE          "VideoDiagnosisProfile"     // Video diagnosis profile (CFG_VIDEODIAGNOSIS_PROFILE)
 #define ZZ_CFG_CMD_VIDEODIAGNOSIS_TASK             "VideoDiagnosisTask"        // Video diagnosis task list (CFG_VIDEODIAGNOSIS_TASK)
 #define ZZ_CFG_CMD_VIDEODIAGNOSIS_PROJECT          "VideoDiagnosisProject"     // Video diagnosis project list (CFG_VIDEODIAGNOSIS_PROJECT)
 #define ZZ_CFG_CMD_VIDEODIAGNOSIS_REALPROJECT      "VideoDiagnosisRealProject" // Video diagnosis real-time project list (CFG_VIDEODIAGNOSIS_REALPROJECT)
 #define ZZ_CFG_CMD_VIDEODIAGNOSIS_GLOBAL           "VideoDiagnosisGlobal"      // Video diagnosis global table (CFG_VIDEODIAGNOSIS_GLOBAL)
 #define ZZ_CFG_CMD_VIDEODIAGNOSIS_TASK_ONE         "VideoDiagnosisTask.x"      // Video diagnosis task list (CFG_VIDEODIAGNOSIS_TASK)
 #define ZZ_CFG_CMD_TRAFFIC_WORKSTATE               "WorkState"                 // Device working state config (CFG_TRAFFIC_WORKSTATE_INFO)
 #define ZZ_CFG_CMD_STORAGEDEVGROUP                 "StorageDevGroup"           // Disk storage group config (CFG_STORAGEGROUP_INFO)
 #define ZZ_CFG_CMD_RECORDTOGROUP                   "RecordToGroup"             // Record storage group config (CFG_RECORDTOGROUP_INFO)
 #define ZZ_CFG_CMD_INTELLITRACKSCENE               "IntelliTrackScene"         // Intelligent tracking scene config (CFG_INTELLITRACKSCENE_INFO) 
 #define ZZ_CFG_CMD_IVSFRAM_RULE                    "IVSFramRule"               // Intelligent frame rule config (CFG_ANALYSERULES_INFO)
 #define ZZ_CFG_CMD_RECORD_STORAGEPOINT             "RecordStoragePoint"        // Record storage point mapping config (CFG_RECORDTOSTORAGEPOINT_INFO)
 #define ZZ_CFG_CMD_RECORD_STORAGEPOINT_EX			"RecordStoragePoint"		// Record storage point mapping config extended (CFG_RECORDTOSTORAGEPOINT_EX_INFO)
 #define ZZ_CFG_CMD_MD_SERVER                       "MetaDataServer"            // Metadata server config (CFG_METADATA_SERVER)
 #define ZZ_CFG_CMD_CHANNELTITLE                    "ChannelTitle"              // Channel name (AV_CFG_ChannelName)
 #define ZZ_CFG_CMD_RECORDMODE                      "RecordMode"                // Record mode (AV_CFG_RecordMode)
 #define ZZ_CFG_CMD_VIDEOOUT                        "VideoOut"                  // Video output attributes (AV_CFG_VideoOutAttr)
 #define ZZ_CFG_CMD_REMOTEDEVICE                    "RemoteDevice"              // Remote device info (AV_CFG_RemoteDevice array, channel independent)
 #define ZZ_CFG_CMD_REMOTECHANNEL                   "RemoteChannel"             // Remote channel (AV_CFG_RemoteChannel)
 #define ZZ_CFG_CMD_MONITORTOUR                     "MonitorTour"               // Monitor tour config (AV_CFG_MonitorTour)
 #define ZZ_CFG_CMD_MONITORCOLLECTION               "MonitorCollection"         // Monitor favorite config (AV_CFG_MonitorCollection)
 #define ZZ_CFG_CMD_DISPLAYSOURCE                   "DisplaySource"             // Split screen display source config (AV_CFG_ChannelDisplaySource) (Deprecated)
 #define ZZ_CFG_CMD_RAID                            "Raid"                      // Storage volume group config (AV_CFG_Raid array, channel independent)
 #define ZZ_CFG_CMD_RECORDSOURCE                    "RecordSource"              // Record source config (AV_CFG_RecordSource)
 #define ZZ_CFG_CMD_VIDEOCOLOR                      "VideoColor"                // Video input color config (AV_CFG_ChannelVideoColor)
 #define ZZ_CFG_CMD_VIDEOWIDGET                     "VideoWidget"               // Video encode widget config (AV_CFG_VideoWidget)
 #define ZZ_CFG_CMD_STORAGEGROUP                    "StorageGroup"              // Storage group info (AV_CFG_StorageGroup array, channel independent)
 #define ZZ_CFG_CMD_LOCALS                          "Locales"                   // Locale config (AV_CFG_Locales)
 #define ZZ_CFG_CMD_LANGUAGE                        "Language"                  // Language selection (AV_CFG_Language)
 #define ZZ_CFG_CMD_ACCESSFILTER                    "AccessFilter"              // Access address filter (AV_CFG_AccessFilter)
 #define ZZ_CFG_CMD_AUTOMAINTAIN                    "AutoMaintain"              // Auto maintain (AV_CFG_AutoMaintain)
 #define ZZ_CFG_CMD_REMOTEEVENT                     "RemoteEvent"               // Remote device event handling (AV_CFG_RemoteEvent array)
 #define ZZ_CFG_CMD_MONITORWALL                     "MonitorWall"               // Monitor wall config (AV_CFG_MonitorWall array, channel independent)
 #define ZZ_CFG_CMD_SPLICESCREEN                    "VideoOutputComposite"      // Spliced screen config (AV_CFG_SpliceScreen array, channel independent)
 #define ZZ_CFG_CMD_TEMPERATUREALARM                "TemperatureAlarm"          // Temperature alarm config (AV_CFG_TemperatureAlarm, channel independent)
 #define ZZ_CFG_CMD_FANSPEEDALARM                   "FanSpeedAlarm"             // Fan speed alarm config (AV_CFG_FanSpeedAlarm, channel independent)
 #define ZZ_CFG_CMD_RECORDBACKUP                    "RecordBackupRestore"       // Record backup config (AV_CFG_RecordBackup, channel independent)
 #define ZZ_CFG_CMD_RECORDDOWNLOADSPEED             "RecordDownloadSpeed"       // Record download speed config (CFG_RecordDownloadSpeed)
 #define ZZ_CFG_CMD_COMM                            "Comm"                      // Serial port config (CFG_COMMGROUP_INFO)
 #define ZZ_CFG_CMD_NETWORK                         "Network"                   // Network config (CFG_NETWORK_INFO)
 #define ZZ_CFG_CMD_NASEX                           "NAS"                       // Network storage server config, multi-server (CFG_NAS_INFO_EX)
 #define ZZ_CFG_CMD_LDAP                            "LDAP"                      // LDAP config
 #define ZZ_CFG_CMD_ACTIVE_DIR                      "ActiveDirectory"           // Active Directory config
 #define ZZ_CFG_CMD_FLASH                           "FlashLight"                // Flash light config (CFG_FLASH_LIGHT)
 #define ZZ_CFG_CMD_AUDIO_ANALYSERULE               "AudioAnalyseRule"          // Audio analysis rule config (CFG_ANALYSERULES_INFO)
 #define ZZ_CFG_CMD_JUDICATURE                      "Judicature"                // Judicial burning config (CFG_JUDICATURE_INFO)
 #define ZZ_CFG_CMD_GOODS_WEIGHT                    "CQDTSet"                   // Vehicle goods weight config (CFG_GOOD_WEIGHT_INFO)
 #define ZZ_CFG_CMD_VIDEOIN                         "VideoIn"                   // Input channel config (CFG_VIDEO_IN_INFO)
 #define ZZ_CFG_CMD_ENCODEPLAN                      "EncodePlan"                // Burning disc encode plan (CFG_ENCODE_PLAN_INFO)
 #define ZZ_CFG_CMD_PICINPIC                        "PicInPic"                  // Judicial trial PIP (CFG_PICINPIC_INFO), changed to array for compatibility
 #define ZZ_CFG_CMD_BURNFULL                        "BurnFull"                  // Burn full event config (CFG_BURNFULL_INFO)
 #define ZZ_CFG_CMD_MASTERSLAVE_GLOBAL              "MasterSlaveTrackerGlobal"  // Master-slave global config (CFG_MASTERSLAVE_GLOBAL_INFO)
 #define ZZ_CFG_CMD_MASTERSLAVE_LINKAGE             "MasterSlaveGlobal"         // Gun-Ball linkage global config (CFG_MASTERSLAVE_LINKAGE_INFO)
 #define ZZ_CFG_CMD_MASTERSLAVE_GROUP               "MasterSlaveGroup"          // Gun-Ball linkage binding config (CFG_MASTERSLAVE_GROUP_INFO)
 #define ZZ_CFG_CMD_ANALYSEWHOLE                    "VideoAnalyseWhole"         // Video analysis whole config (CFG_ANALYSEWHOLE_INFO)
 #define ZZ_CFG_CMD_VIDEO_IN_BOUNDARY               "VideoInBoundary"           // Video input boundary config (CFG_VIDEO_IN_BOUNDARY)
 #define ZZ_CFG_CMD_MONITORWALL_COLLECTION          "MonitorWallCollection"     // Monitor wall collection/plan (CFG_MONITORWALL_COLLECTION array)
 #define ZZ_CFG_CMD_ANALOGMATRIX                    "AnalogMatrix"              // Analog matrix (CFG_ANALOG_MATRIX_INFO)
 #define ZZ_CFG_CMD_ANALOG_MATRIX_PROTOCOL          "AnalogMatrixProtocol"      // Analog matrix protocol config (CFG_ANALOG_MATRIX_PROTOCOL array)
 #define ZZ_CFG_CMD_VIDEO_OUT_TITLE                 "VideoOutputTitle"          // Video output title (CFG_VIDEO_OUT_TITLE)
 #define ZZ_CFG_CMD_DISK_FLUX_ALARM                 "DiskFluxAlarm"             // Disk data flux alarm config (CFG_DISK_FLUX_INFO)
 #define ZZ_CFG_CMD_NET_FLUX_ALARM                  "NetFluxAlarm"              // Net data flux alarm config (CFG_NET_FLUX_INFO)
 #define ZZ_CFG_CMD_DVRIP                           "DVRIP"                     // Network protocol config (CFG_DVRIP_INFO)
 #define ZZ_CFG_CMD_CLIENT_CUSTOM_DATA              "ClientCustomData"          // Platform custom data (CFG_CLIENT_CUSTOM_INFO)
 #define ZZ_CFG_CMD_BURN_RECORD_FORMAT              "BurnRecordFormat"          // Burn format config (CFG_BURN_RECORD_FORMAT)
 #define ZZ_CFG_CMD_MULTIBURN                       "MultiBurn"                 // Multi-disc sync burn (CFG_MULTIBURN_INFO), array element
 #define ZZ_CFG_CMD_ENCODE_ENCRYPT                  "EncodeEncrypt"             // Encode encryption config (CFG_ENCODE_ENCRYPT_CHN_INFO)
 #define ZZ_CFG_CMD_VIDEO_IN_ZOOM                   "VideoInZoom"               // PTZ channel zoom config (CFG_VIDEO_IN_ZOOM)
 #define ZZ_CFG_CMD_SNAP                            "Snap"                      // Snapshot config (CFG_SNAP_INFO)
 #define ZZ_CFG_CMD_REMOTE_STORAGE_LIMIT            "RemoteStorageLimit"        // Remote storage limit config (CFG_REMOTE_STORAGELIMIT_GROUP)
 #define ZZ_CFG_CMD_SPECIAL_DIR                     "SpecialDirectoryDefine"    // Special directory definition (CFG_SPECIAL_DIR_INFO)
 #define ZZ_CFG_CMD_AUTO_STARTUP_DELAY              "AutoStartupDelay"          // Auto startup delay after shutdown config (CFG_AUTO_STARTUP_DELAY_INFO)
 #define ZZ_CFG_CMD_CANFILTER                       "CANFilter"                 // CAN filter config (CFG_CANFILTER_LIST)
 #define ZZ_CFG_CMD_VIDEOIN_FOCUS                   "VideoInFocus"              // Focus settings (CFG_VIDEO_IN_FOCUS)
 #define ZZ_CFG_CMD_ENCODE_ADAPT                    "EncodeAdapt"               // Encode adaptive config (CFG_ENCODE_ADAPT_INFO)
 #define ZZ_CFG_CMD_VIDEOANALYSE_CALIBRATE          "VideoAnalyseCalibrate"     // Video analysis calibration config (CFG_VIDEO_ANALYSE_CALIBRATEAREA)
 #define ZZ_CFG_CMD_PTZ_PRESET                      "PtzPreset"                 // PTZ preset config (PTZ_PRESET_INFO)
 #define ZZ_CFG_CMD_TIMESPEEDLIMIT                  "TimeSpeedLimit"            // Time section speed limit config (CFG_TIMESPEEDLIMIT_LIST)
 #define ZZ_CFG_CMD_VOICEALERT                      "VoiceAlert"                // Voice alert config (CFG_VOICEALERT_LIST)
 #define ZZ_CFG_CMD_DEVICEKEEPALIVE                 "DeviceKeepAlive"           // Device keep alive config (CFG_DEVICEKEEPALIVELIST)
 
 #define ZZ_CFG_CMD_AUDIO_SPIRIT                    "AudioSpirit"               // Audio spirit/voice activation (CFG_AUDIO_SPIRIT)
 #define ZZ_CFG_CMD_AUDIO_MATRIX_SILENCE            "AudioMatrixSilence"        // Audio matrix silence config (CFG_AUDIO_MATRIX_SILENCE)
 #define ZZ_CFG_CMD_AUDIO_MATRIX                    "AudioMatrixConfig"         // Audio matrix config (CFG_AUDIO_MATRIX)
 #define ZZ_CFG_CMD_COMPOSE_CHANNEL                 "ComposeChannel"            // Compose channel config (CFG_COMPOSE_CHANNEL)
 #define ZZ_CFG_CMD_COMPOSE_LINKAGE                 "ComposeLinkage"            // Compose linkage, for court host evidence switching (CFG_COMPOSE_CHANNEL)
 #define ZZ_CFG_CMD_LOWER_MATRIX                    "LowerMatrix"               // Lower matrix config (CFG_LOWER_MATRIX_LIST) 
 #define ZZ_CFG_CMD_INFRARED_BOARD_TEMPLATE	        "InfraredBoardTemplate"	    // Infrared board template (CFG_INFRARED_BOARD_TEMPLATE_GROUP)
 #define ZZ_CFG_CMD_INFRARED_BOARD                  "InfraredBoard"	            // Infrared board (CFG_INFRARED_BOARD_GROUP)
 #define ZZ_CFG_CMD_VIDEOIN_EXPOSURE                "VideoInExposure"           // Exposure settings (CFG_VIDEOIN_EXPOSURE_INFO)
 #define ZZ_CFG_CMD_VIDEOIN_BACKLIGHT               "VideoInBacklight"          // Backlight settings (CFG_VIDEOIN_BACKLIGHT_INFO)
 
 #define ZZ_CFG_CMD_ACCESS_GENERAL                  "AccessControlGeneral"      // Access control general config (CFG_ACCESS_GENERAL_INFO)
 #define ZZ_CFG_CMD_ACCESS_EVENT                    "AccessControl"             // Access control event config (CFG_ACCESS_EVENT_INFO array)     
 #define ZZ_CFG_CMD_WIRELESS                        "Wireless"                  // Wireless network config (CFG_WIRELESS_INFO)
 #define ZZ_CFG_CMD_ALARMSERVER                     "AlarmServer"               // Alarm server config (CFG_ALARMCENTER_INFO)
 #define ZZ_CFG_CMD_COMMGLOBAL                      "CommGlobal"                // Alarm global config (CFG_COMMGLOBAL_INFO)
 #define ZZ_CFG_CMD_ANALOGALARM                     "AnalogAlarm"               // Analog alarm channel config (CFG_ANALOGALARM_INFO)
 #define ZZ_CFG_CMD_ALARMOUT                        "AlarmOut"                  // Alarm output channel config (ZZ_CFG_ALARMOUT_INFO)
 #define ZZ_CFG_CMD_NTP                             "NTP"                       // NTP server (CFG_NTP_INFO)
 #define ZZ_CFG_CMD_ALARMBELL                       "AlarmBell"                 // Alarm bell config (CFG_ALARMBELL_INFO)
 #define ZZ_CFG_CMD_MOBILE                          "Mobile"                    // Mobile business config (CFG_MOBILE_INFO)
 #define ZZ_CFG_CMD_PHONEEVENTNOTIFY                "PhoneEventNotify"          // (CFG_PHONEEVENTNOTIFY_INFO)
 #define ZZ_CFG_CMD_PSTN_ALARM_SERVER               "PSTNAlarmServer"           // PSTN alarm center config (CFG_PSTN_ALARM_CENTER_INFO)
 #define ZZ_CFG_CMD_AUDIO_OUTPUT_VOLUME             "AudioOutputVolume"         // Audio output volume (CFG_AUDIO_OUTPUT_VOLUME)
 #define ZZ_CFG_CMD_AUDIO_INPUT_VOLUME              "AudioInputVolume"          // Audio input volume (ZZ_CFG_AUDIO_INPUT_VOLUME)
 #define ZZ_CFG_CMD_LIGHT_GLOBAL					"LightGlobal"				// Indicator light control config (CFG_LIGHT_GLOBAL)
 #define ZZ_CFG_CMD_AUDIO_MIX_VOLUME                "AudioMixVolume"            // Mixed audio volume, for court host (CFG_AUDIO_MIX_VOLUME)
 #define ZZ_CFG_CMD_ALARMKEYBOARD                   "AlarmKeyboard"             // Alarm keyboard config (CFG_ALARMKEYBOARD_INFO)
 #define ZZ_CFG_CMD_POWERFAULT                      "PowerFault"                // Power fault config (CFG_POWERFAULT_INFO)
 #define ZZ_CFG_CMD_CHASSISINTRUSION                "ChassisIntrusion"          // Chassis intrusion alarm (Tamper alarm) config (CFG_CHASSISINTRUSION_INFO)
 #define ZZ_CFG_CMD_EXALARMBOX                      "ExAlarmBox"                // Extended alarm box config (CFG_EXALARMBOX_INFO)
 #define ZZ_CFG_CMD_EXALARMOUTPUT                   "ExAlarmOut"                // Extended alarm output config (CFG_EXALARMOUTPUT_INFO)
 #define ZZ_CFG_CMD_EXALARMINPUT                    "ExAlarm"                   // Extended alarm input config (CFG_EXALARMINPUT_INFO)
 #define ZZ_CFG_CMD_ACCESSTIMESCHEDULE              "AccessTimeSchedule"        // Access control time schedule (CFG_ACCESS_TIMESCHEDULE_INFO)
 #define ZZ_CFG_CMD_URGENCY                         "Emergency"                 // Emergency event config (CFG_URGENCY_INFO)
 #define ZZ_CFG_CMD_SENSORSAMPLING                  "SensorSampling"            // Sensor sampling (CFG_SENSORSAMPLING_INFO)
 #define ZZ_CFG_CMD_STP                             "STP"                       // STP config (CFG_STP_INFO)
 #define ZZ_CFG_CMD_ALARM_SUBSYSTEM                 "AlarmSubSystem"            // Alarm subsystem config (CFG_ALARM_SUBSYSTEM_INFO)
 #define ZZ_CFG_CMD_BATTERY_LOW_POWER               "BatteryLowPowerAlarm"      // Battery low power config (CFG_BATTERY_LOW_POWER_INFO)
 #define ZZ_CFG_CMD_SNAPLIKAGE                      "SnapLinkage"               // Snapshot channel linkage peripheral config (CFG_SNAPLINKAGE_INFO)
 #define ZZ_CFG_CMD_AUDIOINPUT                      "AudioInput"                // Audio input config (ZZ_CFG_AUDIO_INPUT)
 #define ZZ_CFG_CMD_EMAIL                           "Email"                     // Email config (CFG_EMAIL_INFO)
 #define ZZ_CFG_CMD_TRAFFIC_TRANSFER_OFFLINE        "TrafficTransferOffline"    // Transfer offline file config (TRAFFIC_TRANSFER_OFFLINE_INFO)
 #define ZZ_CFG_CMD_COMMSUBSCRIBE                   "CommSubscribe"             // Subscribe serial data config (CFG_DEVCOMM_SUBSCRIBE)
 #define ZZ_CFG_CMD_PARKINGSPACE_LIGHT_STATE        "ParkingSpaceLightState"    // Parking space status light (CFG_PARKINGSPACE_LIGHT_STATE)
 #define ZZ_CFG_CMD_AIRCONDITION                    "AirCondition"              // Air conditioner device config (CFG_AIRCONDITION_INFO)
 #define ZZ_CFG_CMD_COMPRESS_PLAY                   "CompressPlay"              // Compressed playback config (CFG_COMPRESS_PLAY_INFO)
 #define ZZ_CFG_CMD_BUILDING                        "Building"                  // VTO building/floor config (CFG_BUILDING_INFO)
 #define ZZ_CFG_CMD_BUILDING_EXTERNAL               "BuildingExternal"          // VTO building/floor external config (CFG_BUILDING_EXTERNAL_INFO)
 #define ZZ_CFG_CMD_DIALRULE                        "DialRule"                  // Dial rule (CFG_DIALRULE_INFO)
 #define ZZ_CFG_CMD_OIL_MASS_INFO                   "OilMassInfo"               // Vehicle oil tank config (CFG_OIL_MASS_INFO)
 #define ZZ_CFG_CMD_FISHEYE_INFO                    "FishEye"                   // FishEye detail info config (CFG_FISHEYE_DETAIL_INFO)
 #define ZZ_CFG_CMD_VTNOANSWER_FORWARD              "VTNoAnswerForward"         // Platform call no answer forward config list (CFG_VT_NOANSWER_FORWARD_INFO)
 #define ZZ_CFG_CMD_VTO_CALL                        "VTOCall"                   // VTO call config (CFG_VTO_CALL_INFO)
 #define ZZ_CFG_CMD_MACCONFLICT                     "MacConflict"               // MAC conflict alarm config (CFG_MACCONFLICT_INFO)
 #define ZZ_CFG_CMD_IDLEMOTION_INFO                 "IdleMotion"                // Idle motion config (CFG_IDLE_MOTION_INFO)
 #define ZZ_CFG_CMD_MONITORWALL_COLL_TOUR           "MonitorWallCollectionTour" // Monitor wall collection tour config (CFG_MONITORWALL_COLLECTION_TOUR_INFO)
 #define ZZ_CFG_CMD_PSTN_BREAK_LINE                 "PSTNBreakLine"             // PSTN break line event config (CFG_PSTN_BREAK_LINE_INFO)
 #define ZZ_CFG_CMD_NET_COLLECTION                  "NetCollection"             // Network collection device config (CFG_NET_COLLECTION_INFO)
 #define ZZ_CFG_CMD_ALARM_SLOT_BOND                 "AlarmSlotBond"             // Virtual Slot node to physical device bond (CFG_ALARM_SLOT_BOND_INFO)
 #define ZZ_CFG_CMD_TRAFFICSTROBE                   "TrafficStrobe"             // Traffic strobe config (CFG_TRAFFICSTROBE_INFO)
 #define ZZ_CFG_CMD_TRAFFICVOICE                    "TrafficVoiceBroadcast"     // Traffic voice broadcast config ( CFG_TRAFFICVOICE_BROADCAST)
 #define ZZ_CFG_CMD_STANDING_TIME                   "StandingTime"              // Standing time config (CFG_STANDING_TIME_INFO)
 #define ZZ_CFG_CMD_ENCLOSURE_TIME_SCHEDULE         "EnclosureTimeSchedule"     // Electronic fence alarm time schedule config (CFG_ENCLOSURE_TIME_SCHEDULE_INFO)
 #define ZZ_CFG_CMD_ECKCONFIG                       "ECKConfig"                 // Parking lot entrance/exit controller config (CFG_ECKCONFIG_INFO)
 #define ZZ_CFG_CMD_PARKING_CARD                    "ParkingCard"               // Parking lot entrance/exit card swipe alarm event config (CFG_PARKING_CARD_INFO)
 #define ZZ_CFG_CMD_RCEMERGENCY_CALL                "RCEmergencyCall"           // Remote Control emergency call alarm event config (CFG_RCEMERGENCY_CALL_INFO)
 #define ZZ_CFG_CMD_LANES_STATE_REPORT              "LanesStateReport"          // Lanes state report config (CFG_LANES_STATE_REPORT)
 #define ZZ_CFG_CMD_OPEN_DOOR_GROUP                 "OpenDoorGroup"             // Multi-person multi-open door group config (CFG_OPEN_DOOR_GROUP_INFO)
 #define ZZ_CFG_CMD_OPEN_DOOR_ROUTE                 "OpenDoorRoute"             // Open door route set, or anti-passback route config (CFG_OPEN_DOOR_ROUTE_INFO)
 #define ZZ_CFG_CMD_BURNPLAN                        "BurnPlan"                  // Burn plan config (CFG_BURNPLAN_INFO)
 #define ZZ_CFG_CMD_SCADA_DEV                       "SCADADev"                  // Detection collection device config (CFG_SCADA_DEV_INFO)
 #define ZZ_CFG_CMD_VSP_GAYS                        "VSP_GAYS"                  // Public security platform access config (CFG_VSP_GAYS_INFO)
 #define ZZ_CFG_CMD_AUDIODETECT                     "AudioDetect"               // Audio detection alarm config (CFG_AUDIO_DETECT_INFO array)
 #define ZZ_CFG_CMD_GUIDESCREEN                     "GuideScreen"               // Guide screen system config (CFG_GUIDESCREEN_INFO)
 #define ZZ_CFG_CMD_VTS_CALL_INFO                   "VTSCallInfo"               // VTS call config (CFG_VTS_CALL_INFO)
 #define ZZ_CFG_CMD_DEV_LIST                        "DevList"                   // Device list config (CFG_DEV_LIST_INFO)
 #define ZZ_CFG_CMD_CALIBRATE_MATRIX                "CalibrateMatrix"           // Master-slave tracker calibration matrix config (CFG_CALIBRATE_MATRIX_INFO, New config corresponds to CFG_CALIBRATE_MATRIX_EX_INFO)
 #define ZZ_CFG_CMD_DEFENCE_AREA_DELAY              "DefenceAreaDelay"          // Defence area delay config (CFG_DEFENCE_AREA_DELAY_INFO)
 #define ZZ_CFG_CMD_THERMO_GRAPHY                   "ThermographyOptions"       // Thermal imaging camera attribute config (CFG_THERMOGRAPHY_INFO)
 #define ZZ_CFG_CMD_THERMOMETRY_RULE                "ThermometryRule"           // Thermal imaging thermometry rule config (CFG_RADIOMETRY_RULE_INFO)
 #define ZZ_CFG_CMD_TEMP_STATISTICS                 "TemperatureStatistics"     // Temperature statistics config (CFG_TEMP_STATISTICS_INFO)
 #define ZZ_CFG_CMD_THERMOMETRY                     "HeatImagingThermometry"    // Thermal imaging thermometry global config (CFG_THERMOMETRY_INFO)
 #define ZZ_CFG_CMD_LIGHTING                        "Lighting"                  // Lighting settings (CFG_LIGHTING_INFO)
 #define ZZ_CFG_CMD_RAINBRUSHMODE                   "RainBrushMode"             // Wiper mode related config (CFG_RAINBRUSHMODE_INFO array)
 #define ZZ_CFG_CMD_LIGHTINGSCHEDULE                "LightingSchedule"          // Lighting schedule config (CFG_LIGHTINGSCHEDULE_INFO)
 #define ZZ_CFG_CMD_EMERGENCY_RECORD_FOR_PULL       "EmergencyRecordForPull"    // Emergency record storage config for pull mode. Used when client pull stream storage is abnormal (CFG_EMERGENCY_RECORD_FOR_PULL_INFO)
 #define ZZ_CFG_CMD_ALARM_SHIELD_RULE               "AlarmShieldRule"           // Alarm shield rule (CFG_ALARM_SHIELD_RULE_INFO)
 #define ZZ_CFG_CMD_VIDEOIN_ANALYSERULE             "VideoInAnalyseRule"        // Video channel intelligent rule config (CFG_VIDEOIN_ANALYSE_RULE_INFO)
 #define ZZ_CFG_CMD_ACCESS_WORK_MODE                "AccessWorkMode"            // Door lock work mode (CFG_ACCESS_WORK_MODE_INFO array)
 #define ZZ_CFG_CMD_VIDEO_TALK_PHONE_GENERAL        "VideoTalkPhoneGeneral"     // Video talk phone general config (CFG_VIDEO_TALK_PHONE_GENERAL)
 #define ZZ_CFG_CMD_TRAFFIC_SNAP_MOSAIC             "TrafficSnapMosaic"         // Traffic snapshot mosaic config (CFG_TRAFFIC_SNAP_MOSAIC_INFO)
 #define ZZ_CFG_CMD_SCENE_SNAP_RULE                 "SceneSnapShotWithRule"     // Scene snapshot rule config (CFG_SCENE_SNAPSHOT_RULE_INFO)
 #define ZZ_CFG_CMD_PTZTOUR                         "PtzTour"                   // PTZ tour path config (CFG_PTZTOUR_INFO)
 #define ZZ_CFG_CMD_VTO_INFO                        "VTOInfo"                   // VTO config (CFG_VTO_LIST)
 #define ZZ_CFG_CMD_TS_POINT                        "TSPoint"                   // Touch screen calibration config (CFG_TSPOINT_INFO)
 #define ZZ_CFG_CMD_VTH_NUMBER_INFO                 "VTHNumberInfo"             // VTH (Video Talk Handset) number info (CFG_VTH_NUMBER_INFO)
 #define ZZ_CFG_CMD_GPS                             "GPS"                       // GPS config (CFG_GPS_INFO_ALL)
 #define ZZ_CFG_CMD_VTO_BASIC_INFO                  "VTOBasicInfo"              // VTO basic info (CFG_VTO_BASIC_INFO)
 #define ZZ_CFG_CMD_SHORTCUT_CALL                   "ShortcutCall"              // Shortcut call config (CFG_SHORTCUT_CALL_INFO)
 #define ZZ_CFG_CMD_GPS_LOCATION_VER                "GPSLocationVersion"        // Version number of GPSLocation record set (CFG_LOCATION_VER_INFO)
 #define ZZ_CFG_CMD_PARKING_SPACE_ACCESS_FILTER     "ParkingSpaceAccessFilter"  // Device access address filter config (CFG_PARKING_SPACE_ACCESS_FILTER_INFO)
 #define ZZ_CFG_CMD_WORK_TIME                       "WorkTime"                  // Work time config (CFG_WORK_TIME_INFO)
 #define ZZ_CFG_CMD_PARKING_SPACE_LIGHT_GROUP       "ParkingSpaceLightGroup"    // Parking space indicator light local config (CFG_PARKING_SPACE_LIGHT_GROUP_INFO_ALL)
 #define ZZ_CFG_CMD_CUSTOM_AUDIO                    "CustomAudio"               // Custom audio config (CFG_CUSTOM_AUDIO)
 #define ZZ_CFG_CMD_WIFI_SEARCH                     "AroudWifiSearch"           // Device scans surrounding WiFi config (CFG_WIFI_SEARCH_INFO)
 #define ZZ_CFG_CMD_G3G4AUTOCHANGE                  "G3G4AutoChange"            // Vehicle device 3G/4G auto switch (CFG_G3G4AUTOCHANGE)
 #define ZZ_CFG_CMD_CHECKCODE                       "CheckCode"                 // Card reader check code verification config (CFG_CHECKCODE_INFO)
 #define ZZ_CFG_CMD_VSP_SCYDKD                      "VSP_SCYDKD"                // Sichuan Mobile shop monitoring Qidi platform access config (CFG_VSP_SCYDKD_INFO)
 #define ZZ_CFG_CMD_VIDEOIN_DAYNIGHT                "VideoInDayNight"           // Dome camera core Day/Night config (CFG_VIDEOIN_DAYNIGHT_INFO)
 #define ZZ_CFG_CMD_PTZ_POWERUP                     "PowerUp"                   // PTZ power up action settings (CFG_PTZ_POWERUP_INFO)
 #define ZZ_CFG_CMD_AUDIO_MIX_CHANNEL               "AudioMixChannel"           // Definition of each pure audio channel composition (CFG_AUDIO_MIX_CHANNEL_INFO_ALL)
 #define ZZ_CFG_CMD_AUDIO_TOUCH                     "AudioTouch"                // Voice changing/pitch shifting (CFG_AUDIO_TOUCH_INFO_ALL)
 #define ZZ_CFG_CMD_VIDEO_MOSAIC                    "VideoMosaic"               // Mosaic overlay config (CFG_VIDEO_MOSAIC_INFO)
 #define ZZ_CFG_CMD_VTH_REMOTE_IPC_INFO             "VTHRemoteIPCInfo"          // Remote IPC config in VTH (CFG_VTH_REMOTE_IPC_INFO), global config, channel independent
 #define ZZ_CFG_CMD_UNFOCUSDETECT                   "UnFocusDetect"             // Unfocus detection config (CFG_UNFOCUSDETECT_INFO)
 #define ZZ_CFG_CMD_MOVE_DETECT                     "MovedDetect"               // Scene change detection config (CFG_MOVE_DETECT_INFO)
 #define ZZ_CFG_CMD_FLOODLIGHT                      "Floodlight"                // Protection cabin floodlight control config (CFG_FLOODLIGHT_CONTROLMODE_INFO)
 #define ZZ_CFG_CMD_AIRFAN                          "AirFan"                    // Protection cabin fan control config (CFG_AIRFAN_CONTROLMODE_INFO)
 #define ZZ_CFG_CMD_WLAN                            "WLan"                      // WLAN config (CFG_NETAPP_WLAN)
 #define ZZ_CFG_CMD_SMART_ENCODE                    "SmartEncode"               // Smart H264 encoding mode (CFG_SMART_ENCODE_INFO)
 #define ZZ_CFG_CMD_VEHICLE_HIGH_SPEED              "HighSpeed"                 // Vehicle high speed alarm config (CFG_VEHICLE_HIGHSPEED_INFO )
 #define ZZ_CFG_CMD_VEHICLE_LOW_SPEED               "LowSpeed"                  // Vehicle low speed alarm config (CFG_VEHICLE_LOWSPEED_INFO )
 #define ZZ_CFG_CMD_PSTN_PERSON_SERVER              "PSTNPersonServer"          // Personal phone receiver config (CFG_PSTN_PERSON_SERVER_INFO_ALL )
 #define ZZ_CFG_CMD_ARM_LINK                        "ArmLink"                   // Arm/Disarm linkage config (CFG_ARMLINK_INFO )
 #define ZZ_CFG_CMD_CABINLED_TIME_SCHEDULE          "CabinLedTimeSchedule"      // Protection cabin LED display schedule config (CFG_CABINLED_TIME_SCHEDULE)
 #define ZZ_CFG_CMD_PSTN_TESTPLAN                   "PSTNTestPlan"              // PSTN test plan config (CFG_PSTN_TESTPLAN_INFO)
 #define ZZ_CFG_CMD_DEFENCE_ARMMODE                 "DefenceArmMode"            // Single defence area arm/disarm enable config (CFG_DEFENCE_ARMMODE_INFO)
 #define ZZ_CFG_CMD_SENSORMODE                      "SensorMode"                // Detector installation work mode config (CFG_SENSORMODE_INFO)
 #define ZZ_CFG_CMD_ALARMLAMP                       "AlarmLamp"                 // Alarm lamp config (CFG_ALARMLAMP_INFO)
 #define ZZ_CFG_CMD_RADAR_SPEED_MEASURE             "RadarSpeedMeasure"         // Radar speed measurement config, Smart Building specific (CFG_RADAR_SPEED_MEASURE_INFO)
 #define ZZ_CFG_CMD_VIDEOINDEFOG                    "VideoInDefog"              // Defog settings config (CFG_VIDEOINDEFOG_LIST)
 #define ZZ_CFG_CMD_RTMP                            "RTMP"                      // RTMP config (CFG_RTMP_INFO)
 #define ZZ_CFG_CMD_AUDIO_OUT_EQUALIZER             "AudioOutEqualizer"         // Audio output equalizer config (CFG_AUDIO_OUTEQUALIZER_INFO)
 #define ZZ_CFG_CMD_AUDIO_OUT_SUPPRESSION           "AudioOutSuppression"       // Audio suppression settings (CFG_AUDIO_SUPPRESSION_INFO)
 #define ZZ_CFG_CMD_AUDIO_IN_CONTROL                "AudioInControl"            // Audio input control (CFG_AUDIO_INCONTROL_INFO)
 #define ZZ_CFG_CMD_LASER_DIST_MEASURE              "LaserDistMeasure"          // Laser distance measurement config (CFG_LASER_DIST_MEASURE_INFO)
 #define ZZ_CFG_CMD_OIL_4G_OVERFLOW                 "Oil4GFlow"                 // Fushan Oilfield 4G flow threshold and mode config (CFG_OIL_4G_OVERFLOW_INFO)
 #define ZZ_CFG_CMD_OIL_VIDEOWIDGET_4G_FLOW         "VideoWidget4GFlow"         // Fushan Oilfield 4G flow OSD overlay config (CFG_OIL_VIDEOWIDGET_4G_FLOW_INFO)
 #define ZZ_CFG_CMD_ATMOSPHERE_OSD                  "AtmosphereOSD"             // Atmosphere info overlay config (CFG_CMD_ATMOSPHERE_OSD_INFO)
 #define ZZ_CFG_CMD_PARK_SPACE_OUT_LIGHT            "ParkSpaceOutLight"         // External indicator light config (CFG_PARK_SPACE_OUT_LIGHT_INFO)
 #define ZZ_CFD_CMD_VTO_CALL_INFO_EXTEND            "VTOCallInfo"               // VTO call config extend (CFG_VTO_CALL_INFO_EXTEND)
 #define ZZ_CFG_CMD_ACCESS_TEXTDISPLAY              "AccessControlTextDisplay"  // Access control text display config (CFG_ACCESS_TEXTDISPLAY_INFO)
 #define ZZ_CFG_CMD_NETNVR_ENCRYPT               "NvrEncrypt"                // HangShiDa video encryption project config, involves IPC and NVR (CFG_NETNVR_ENCRYPT_INFO)
 #define ZZ_CFG_CMD_LIGHT                           "Light"                     // Light device config (CFG_LIGHT_INFO)
 #define ZZ_CFG_CMD_CURTAIN                         "Curtain"                   // Curtain config (CFG_CURTAIN_INFO)
 #define ZZ_CFG_CMD_FRESH_AIR                       "FreshAir"                  // Fresh air config (CFG_FRESH_AIR_INFO)
 #define ZZ_CFG_CMD_GROUND_HEAT                     "GroundHeat"                // Ground heat config (CFG_GROUND_HEAT_INFO)
 #define ZZ_CFG_CMD_SCENE_MODE                      "SceneMode"                 // Scene mode (CFG_SCENE_MODE_INFO)
 #define ZZ_CFG_CMD_AIO_APP_CONFIG                  "AIOAppConfig"              // Yubei smart sky net parameter settings (CFG_AIO_APP_CONFIG_INFO)
 #define ZZ_CFG_CMD_HTTPS                           "Https"                     // Https service config (CFG_HTTPS_INFO)
 #define ZZ_CFG_CMD_NETAUTOADAPTORENCODE            "NetAutoAdaptEncode"        // Network auto adapt encode config (CFG_NET_AUTO_ADAPT_ENCODE)
 #define ZZ_CFG_CMD_USERLOCKALARM                   "UserLockAlarm"             // Login lock alarm config (CFG_USERLOCKALARM_INFO)
 #define ZZ_CFG_CMD_STROBOSCOPIC_LAMP               "StroboscopicLamp"          // Stroboscopic lamp config (CFG_STROBOSCOPIC_LAMP_INFO)
 #define ZZ_CFG_CMD_FREECOMBINATION                 "FreeCombination"           // Free combination split window config (CFG_FREECOMBINATION_INFO)
 #define ZZ_CFG_CMD_IOT_INFRARED_DETECT             "IOT_InfraredDetect"        // IoT infrared detection config (CFG_IOT_INFRARED_DETECT_INFO)
 #define ZZ_CFG_CMD_IOT_RECORD_HANDLE               "IOT_RecordHandle"          // IoT record linkage config (CFG_IOT_RECORD_HANDLE_INFO)
 #define ZZ_CFG_CMD_IOT_SNAP_HANDLE                 "IOT_SnapHandle"            // IoT snapshot linkage config (CFG_IOT_SNAP_HANDLE_INFO)
 #define ZZ_CFG_CMD_PLATFORM_MONITOR_IPC            "PlatformMonitorIPC"        // Platform side monitor IPC config (CFG_PLATFORMMONITORIPC_INFO)
 #define ZZ_CFG_CMD_CALLFORWARD                     "CallForward"               // Call forward config (CFG_CALLFORWARD_INFO)
 #define ZZ_CFG_CMD_DOORBELLSOUND                   "DoorBellSound"             // Doorbell sound config (CFG_DOOR_BELLSOUND_INFO)
 #define ZZ_CFG_CMD_TELNET                          "Telnet"                    // Telnet config (CFG_TELNET_INFO)
 #define ZZ_CFG_CMD_OSDSYSABNORMAL                  "OSDSysAbnormal"            // System abnormal info overlay config (CFG_OSD_SYSABNORMAL_INFO)
 #define ZZ_CFG_CMD_VIDEO_WIDGET2                   "VideoWidget2"              // Video encode widget config (CFG_VIDEO_WIDGET2_INFO)
 #define ZZ_CFG_CMD_VIDEOWIDGET_NUMBERSTAT          "VideoWidgetNumberStat"     // People counting statistics OSD overlay config (CFG_VIDEOWIDGET_NUMBERSTAT_INFO)
 #define ZZ_CFG_CMD_PRIVACY_MASKING	                "PrivacyMasking"            // Privacy masking settings (CFG_PRIVACY_MASKING_INFO)
 #define ZZ_CFG_CMD_DEVICE_INFO                     "DeviceInfo"                // Device info (CFG_DEVICE_INFO)
 #define ZZ_CFG_CMD_POLICEID_MAP_INFO               "PoliceMap"                 // Police ID and device channel mapping info (CFG_POLICEID_MAP_INFO)
 #define ZZ_CFG_CMD_GPS_NOT_ALIGNED                 "GpsNotAligned"             // GPS not aligned config (CFG_GPS_NOT_ALIGNED_INFO) 
 #define ZZ_CFG_CMD_WIRELESS_NOT_CONNECTED          "WireLessNotConnected"      // Network not connected (including wifi, 3G/4G) config (CFG_WIRELESS_NOT_CONNECTED_INFO)
 #define ZZ_CFG_CMD_MCS_GENERAL_CAPACITY_LOW		"MCSGeneralCapacityLow"		// Micro cloud general capacity low alarm config (CFG_MCS_GENERAL_CAPACITY_LOW)
 #define ZZ_CFG_CMD_MCS_DATA_NODE_OFFLINE			"MCSDataNodeOffline"		// Micro cloud data node offline (CFG_MCS_DATA_NODE_OFFLINE)
 #define ZZ_CFG_CMD_MCS_DISK_OFFLINE				"MCSDiskOffline"			// Micro cloud disk offline alarm config (CFG_MCS_DISK_OFFLINE)
 #define ZZ_CFG_CMD_MCS_DISK_SLOW					"MCSDiskSlow"				// Micro cloud disk slow alarm config (CFG_MCS_DISK_SLOW)
 #define ZZ_CFG_CMD_MCS_DISK_BROKEN					"MCSDiskBroken"				// Micro cloud disk broken alarm config (CFG_MCS_DISK_BROKEN)
 #define ZZ_CFG_CMD_MCS_DISK_UNKNOW_ERROR			"MCSDiskUnknowError"		// Micro cloud disk unknown error alarm config (CFG_MCS_DISK_UNKNOW_ERROR)
 #define ZZ_CFG_CMD_MCS_METADATA_SERVER_ABNORMAL	"MCSMetadataServerAbnormal" // Micro cloud metadata server abnormal alarm config (CFG_MCS_METADATA_SERVER_ABNORMAL)
 #define ZZ_CFG_CMD_MCS_CATALOG_SERVER_ABNORMAL		"MCSCatalogServerAbnormal"	// Micro cloud catalog server abnormal alarm config (CFG_MCS_CATALOG_SERVER_ABNORMAL)
 #define ZZ_CFG_CMD_MCS_GENERAL_CAPACITY_RESUME		"MCSGeneralCapacityResume"	// Micro cloud general capacity resume alarm config (CFG_MCS_GENERAL_CAPACITY_RESUME)
 #define ZZ_CFG_CMD_MCS_DATA_NODE_ONLINE			"MCSDataNodeOnline"			// Micro cloud data node online alarm config (CFG_MCS_DATA_NODE_ONLINE)
 #define ZZ_CFG_CMD_MCS_DISK_ONLINE					"MCSDiskOnline"				// Micro cloud disk online alarm config (CFG_MCS_DISK_ONLINE)
 #define ZZ_CFG_CMD_MCS_METADATA_SLAVE_ONLINE		"MCSMetadataSlaveOnline"	// Micro cloud metadata slave online alarm config (CFG_MCS_METADATA_SLAVE_ONLINE)
 #define ZZ_CFG_CMD_MCS_CATALOG_SERVER_ONLINE		"MCSCatalogServerOnline"	// Micro cloud catalog server online alarm config (CFG_MCS_CATALOG_SERVER_ONLINE)
 #define ZZ_CFG_CMD_SECURITY_ALARMS_PRIVACY         "SecurityAlarmsPrivacy"     // SecurityAlarms customer customized function, privacy protection (CFG_SECURITY_ALARMS_PRIVACY)
 #define ZZ_CFG_CMD_NO_FLY_TIME                     "NoFlyTime"                 // UAV no fly time config (CFG_NO_FLY_TIME_INFO)
 #define ZZ_CFG_CMD_PWD_RESET                       "PwdReset"                  // Password reset function enable config (CFG_PWD_RESET_INFO)
 #define ZZ_CFG_CMD_NET_MONITOR_ABORT				"NetMonitorAbort"			// Network monitor abort event config (CFG_NET_MONITOR_ABORT_INFO)
 #define ZZ_CFG_CMD_LOCAL_EXT_ALARM                 "LocalExtAlarm"             // Local extended alarm config (CFG_LOCAL_EXT_ALARME_INFO)
 #define ZZ_CFG_CMD_ACCESSCONTROL_DELAYSTRATEGY     "DelayStrategy"             // Access control card arrears and pre-arrears status config (CFG_ACCESSCONTROL_DELAYSTRATEGY)
 #define ZZ_CFG_CMD_VIDEO_TALK_PHONE_BASIC			"VideoTalkPhoneBasic"		// Video talk phone basic config (CFG_VIDEO_TALK_PHONE_BASIC_INFO)
 #define ZZ_CFG_CMD_APP_EVENT_LANGUAGE				"AppEventLanguage"			// Mobile push message translation target language config (CFG_APP_EVENT_LANGUAGE_INFO)
 #define ZZ_CFG_CMD_LOGIN_FAILURE_ALARM				"LoginFailureAlarm"			// Login failure alarm config (CFG_LOGIN_FAILURE_ALARM)
 #define ZZ_CFG_CMD_DROPBOXTOKEN                    "DropBoxToken"              // Dropbox Token config (CFG_DROPBOXTOKEN_INFO)
 #define ZZ_CFG_CMD_IDLINGTIME						"IdlingTime"				// Idling time config (CFG_IDLINGTIME_INFO) 
 #define ZZ_CFG_CMD_CARDIVERSTATE					"CarDiverState"				// Car driving state config (CFG_CARDIVERSTATE_INFO)
 #define ZZ_CFG_CMD_VEHICLE							"Vehicle"					// Vehicle config (CFG_VEHICLE_INFO)
 #define ZZ_CFG_CMD_PTZDEVICE                       "PtzDevice"                 // Analog PTZ config (CFG_PTZDEVICE_INFO)
 #define ZZ_CFG_CMD_DEVLOCATION                     "DevLocation"               // GPS coordinates info of device installation location (CFG_DEVLOCATION_INFO)
 
 #define ZZ_CFG_CMD_LIGHTING_V2						"Lighting_V2"				// Full color camera fill light sensitivity config (CFG_LIGHTING_V2_INFO)

 /************************************************************************
 ** Capability Commands - Corresponding to ZZNETSDK_QueryNewSystemInfo
 ***********************************************************************/

#define ZZ_CFG_CAP_CMD_VIDEOANALYSE                "devVideoAnalyse.getCaps"                   // Video analysis capability (CFG_CAP_ANALYSE_INFO)
#define ZZ_CFG_CAP_CMD_VIDEOANALYSE_EX             "devVideoAnalyse.getCapsEx"                 // Video analysis capability (CFG_CAP_ANALYSE_INFO_EX)
#define ZZ_CFG_NETAPP_REMOTEDEVICE	               "netApp.getRemoteDeviceStatus"              // Get online status of backend devices (CFG_REMOTE_DEVICE_STATUS)
#define ZZ_CFG_CAP_CMD_PRODUCTDEFINITION           "magicBox.getProductDefinition"             // Connected device info
#define ZZ_CFG_DEVICE_CAP_CMD_VIDEOANALYSE         "intelli.getVideoAnalyseDeviceChannels"     // Device intelligent analysis capability (CFG_CAP_DEVICE_ANALYSE_INFO) compatible with old devices
#define ZZ_CFG_DEVICE_CAP_NEW_CMD_VIDEOANALYSE     "devVideoAnalyse.factory.getCollect"        // Device intelligent analysis capability (CFG_CAP_DEVICE_ANALYSE_INFO)
#define ZZ_CFG_CAP_CMD_CPU_COUNT                   "magicBox.getCPUCount"                      // Get CPU count
#define ZZ_CFG_CAP_CMD_CPU_USAGE                   "magicBox.getCPUUsage"                      // Get CPU usage
#define ZZ_CFG_CAP_CMD_MEMORY_INFO                 "magicBox.getMemoryInfo"                    // Get memory capacity
#define	ZZ_CFG_CAP_CMD_DEVICE_CLASS 			   "magicBox.getDeviceClass"				   // Get device class (CFG_DEVICE_CLASS_INFO)
#define ZZ_CFG_CAP_CMD_DEVICE_STATE                "trafficSnap.getDeviceStatus"               // Get device status info (CFG_CAP_TRAFFIC_DEVICE_STATUS)
#define ZZ_CFG_CAP_CMD_VIDEOINPUT                  "devVideoInput.getCaps"                     // Video input capability (CFG_CAP_VIDEOINPUT_INFO)
#define ZZ_CFG_USERMANAGER_ACTIVEUSER              "userManager.getActiveUserInfoAll"          // Get all active user info (CFG_ACTIVEUSER_INFO)
#define ZZ_CFG_CAP_VIDEOSTAT_SUMMARY               "videoStatServer.getSummary"                // Get video statistics summary info (CFG_VIDEOSATA_SUMMARY_INFO)
#define ZZ_CFG_CAP_CMD_VIDEODIAGNOSIS_SERVER       "videoDiagnosisServer.getCaps"              // Get video diagnosis service capability (CFG_VIDEODIAGNOSIS_CAPS_INFO)
#define ZZ_CFG_CMD_VIDEODIAGNOSIS_GETCOLLECT       "videoDiagnosisServer.factory.getCollect"   // Get video diagnosis channel count (CFG_VIDEODIAGNOSIS_GETCOLLECT_INFO)
#define ZZ_CFG_CMD_VIDEODIAGNOSIS_GETSTATE         "videoDiagnosisServer.getState"             // Get video diagnosis running state (CFG_VIDEODIAGNOSIS_STATE_INFO)
#define ZZ_CFG_CAP_CMD_SERVICE_LIST                "system.listService"                        // Get supported service list on server (CFG_DEV_SERVICE_LIST)
#define ZZ_CFG_CAP_CMD_EVENTHANDLER                "capsManager.get&EventManagerEventHandler"  // Get server alarm linkage capability (CFG_CAP_EVENTHANDLER_INFO)
#define ZZ_CFG_CAP_ALARM                           "alarm.getAlarmCaps"                        // Get alarm capability (CFG_CAP_ALARM_INFO)
#define ZZ_CFG_CAP_CMD_AUDIO_ANALYSE               "devAudioAnalyse.getCaps"                   // Get audio analysis capability (CFG_CAP_AUDIO_ANALYSE_INFO)
#define ZZ_CFG_CMD_MASTERSLAVE_GETCOLLECT          "masterSlaveTracker.factory.getCollect"     // Get master-slave tracker channel count (CFG_MASTERSLAVETRACKER_INFO)
#define ZZ_CFG_CAP_CMD_MASTERSLAVE                 "capsManager.get&MasterSlaveTracker"        // Get master-slave device capability (CFG_CAP_MASTERSLAVE_INFO)
#define ZZ_CFG_CAP_CMD_FOCUS_STATE                 "devVideoInput.getFocusStatus"              // Get lens focus status info (CFG_CAP_FOCUS_STATUS)
#define ZZ_CFG_CAP_CMD_NETAPP                      "netApp.getCaps"                            // Get network application capability (CFG_CAP_NETAPP)
#define ZZ_CFG_CAP_CMD_PTZ_ENABLE                  "ptz.factory.instance"                      // Get PTZ support info (CFG_CAP_PTZ_ENABLEINFO)
#define ZZ_CFG_CAP_CMD_RECORD                      "recordManager.getCaps"                     // Get record capability (CFG_CAP_RECORD_INFO)
#define ZZ_CFG_CAP_CMD_BURN_MANAGER                "BurnManager.getCaps"                       // Get burn manager capability (CFG_CAP_BURN_MANAGER)
#define ZZ_CFG_CAP_CMD_PTZ                         "ptz.getCurrentProtocolCaps"                // Get PTZ capability (CFG_PTZ_PROTOCOL_CAPS_INFO)
#define ZZ_CFG_CMD_ENCODE_GETCAPS                  "encode.getCaps"                            // Get encode capability (ZZ_CFG_ENCODECAP)
#define ZZ_CFG_CAP_CMD_VIDEOINPUT_EX               "devVideoInput.getCapsEx"                   // Video input capability extended (CFG_CAP_VIDEOINPUT_INFO_EX)
#define ZZ_CFG_CAP_CMD_ANALYSE_MODE                "intelli.getCaps.AnalyseMode"               // Get device intelligent analysis mode (CFG_ANALYSE_MODE)
#define ZZ_CFG_CAP_CMD_EVENTMANAGER                "eventManager.getCaps"                      // Get device alarm linkage capability, old protocol deprecated, use this for new dev (CFG_CAP_EVENTMANAGER_INFO)
#define ZZ_CFG_CAP_CMD_FILEMANAGER	               "FileManager.getCaps"                       // Get file manager capability (CFG_CAP_FILEMANAGER)
#define	ZZ_CFG_CAP_CMD_LOG                         "log.getCaps"                               // Get log service capability (CFG_CAP_LOG)
#define ZZ_CFG_CAP_CMD_SPEAK                       "speak.getCaps"                             // Speaker play capability (CFG_CAP_SPEAK)
#define ZZ_CFG_CAP_CMD_ACCESSCONTROLMANAGER        "accessControlManager.getCaps"              // Access control capability (CFG_CAP_ACCESSCONTROL)
#define ZZ_CFG_CAP_CMD_EXALARM                     "alarm.getExAlarmCaps"                      // Get extended alarm capability (CFG_CAP_EXALARM_INFO)
#define ZZ_CFG_CAP_CMD_EXALARMBOX                  "alarm.getExAlarmBoxCaps"                   // Get extended alarm box capability (CFG_CAP_EXALARMBOX_INFO)
#define ZZ_CFG_CAP_CMD_RECORDFINDER                "RecordFinder.getCaps"                      // Get record finder capability (CFG_CAP_RECORDFINDER_INFO)
#define ZZ_CFG_CAP_CMD_ANALOGALARM	               "AnalogAlarm.getCaps"                       // Analog alarm input channel capability (CFG_CAP_ANALOGALARM)
#define ZZ_CFG_CAP_CMD_LOWRATEWPAN	               "LowRateWPAN.getCaps"                       // Get LowRateWPAN capability (CFG_CAP_LOWRATEWPAN)
#define ZZ_CFG_CAP_CMD_ADAPTENCODE                 "encode.getNAACaps"                         // Get adaptive encoding capability (CFG_CAP_ADAPT_ENCODE_INFO)
#define ZZ_CFG_CAP_CMD_PTZPROTOCAL	               "ptz.getProtocol"                           // Get actual usable protocol for the PTZ, distinguished by medium (CFG_CAP_PTZ_PROTOCOL)
#define ZZ_CFG_CAP_CMD_MEDIACROP                   "encode.getCropCaps"                        // Query if video crop capability is supported (CFG_CAP_MEDIA_CROP)
#define ZZ_CFG_CAP_CMD_OSDMANAGER				   "OSDManager.getCaps"			               // Get OSD overlay capability (CFG_CAP_OSDMANAGER_INFO)
#define ZZ_CFG_CAP_CMD_CUSTOM					   "OSDManager.getCustomCaps"		           // Get custom title capability (CFG_CAP_CUSTOM_OSD_INFO)


/************************************************************************
** Intelligent Template Config Commands - Corresponding to ZZNETSDK_GetVideoInAnalyse
***********************************************************************/
#define ZZ_CFG_VIDEOINANALYSE_RULE                 "VideoInAnalyse.getTemplateRule"            // Get intelligent rule config template and default values (CFG_ANALYSERULES_INFO)
#define ZZ_CFG_VIDEOINANALYSE_GLOBAL               "VideoInAnalyse.getTemplateGlobal"          // Get intelligent global config template and default values (CFG_VIDEOINANALYSE_GLOBAL_INFO)
#define	ZZ_CFG_VIDEOINANALYSE_MODULE               "VideoInAnalyse.getTemplateModule"          // Get intelligent detection module config template and default values (CFG_VIDEOINANALYSE_MODULE_INFO)



// RGBA Information
typedef struct tagZZ_CFG_RGBA
{
	int					nRed;
	int					nGreen;
	int					nBlue;
	int					nAlpha;
} ZZ_CFG_RGBA;

// Region Information
typedef struct tagZZ_CFG_RECT
{
	int					nLeft;
	int					nTop;
    int					nRight;
    int					nBottom;				
} ZZ_CFG_RECT;

// Region Vertex Information
typedef struct tagZZ_CFG_POLYGON
{
	int					nX; //0~8191
	int					nY;		
} ZZ_CFG_POLYGON;

// Size
typedef struct tagZZ_CFG_SIZE
{
	union
	{
		float				nWidth;			// Width
		float				nArea;			// Area
	};
	float					nHeight;		// Height
	
} ZZ_CFG_SIZE;



#define ZZC_MAX_AUDIO_PROPERTY_NUM       32          // Max audio property count
#define ZZC_MAX_AUDIO_FORMAT_NUM         16          // Max audio format count
// Audio Encoding Compression Format
enum EM_ZZ_TALK_AUDIO_TYPE
{
	EM_ZZ_TALK_AUDIO_PCM,
	EM_ZZ_TALK_AUDIO_ADPCM, 
	EM_ZZ_TALK_AUDIO_G711A, 
	EM_ZZ_TALK_AUDIO_G711Mu, 
	EM_ZZ_TALK_AUDIO_G726, 
	EM_ZZ_TALK_AUDIO_G729, 
	EM_ZZ_TALK_AUDIO_MPEG2, 
	EM_ZZ_TALK_AUDIO_AMR, 
	EM_ZZ_TALK_AUDIO_AAC, 
};

// Audio Property
typedef struct ZZ_CFG_AUDIO_PROPERTY
{
	int            nBitRate;               // Bitrate size, unit: kbps, e.g., 192kbps
	int            nSampleBit;             // Sample bit depth, e.g., 8 or 16
	int            nSampleRate;            // Sample rate, unit: Hz, e.g., 44100Hz
}ZZ_CFG_AUDIO_PROPERTY;

// Supported Audio Formats
typedef struct ZZ_CFG_CAP_AUDIO_FORMAT
{
	EM_ZZ_TALK_AUDIO_TYPE  emCompression;          // Audio compression format, see enum AV_Talk_Audio_Type
	int		               nPropertyNum;           // Number of audio properties
	ZZ_CFG_AUDIO_PROPERTY  stuProperty[ZZC_MAX_AUDIO_PROPERTY_NUM]; // Audio properties
}ZZ_CFG_CAP_AUDIO_FORMAT;

// Speaker Capability
typedef struct ZZ_CFG_CAP_SPEAK
{
	int						nAudioCapNum;           // Number of supported audio formats
	ZZ_CFG_CAP_AUDIO_FORMAT	stuAudioCap[ZZC_MAX_AUDIO_FORMAT_NUM]; // Supported audio formats
}ZZ_CFG_CAP_SPEAK;

// Password storage mode in AccessControlCustomPassword record set
typedef enum tagEM_ZZ_CUSTOM_PASSWORD_ENCRYPTION_MODE
{
	EM_ZZ_CUSTOM_PASSWORD_ENCRYPTION_MODE_UNKNOWN,			// Unknown mode
	EM_ZZ_CUSTOM_PASSWORD_ENCRYPTION_MODE_PLAINTEXT,		// Plain text
	EM_ZZ_CUSTOM_PASSWORD_ENCRYPTION_MODE_MD5,				// MD5 encryption
}EM_ZZ_CUSTOM_PASSWORD_ENCRYPTION_MODE;

// Support for Fingerprint Function
typedef enum tagEM_ZZ_SUPPORTFINGERPRINT
{
	EM_ZZ_SUPPORTFINGERPRINT_UNKNOWN,				// Unknown
	EM_ZZ_SUPPORTFINGERPRINT_NONSUPPORT,			// Fingerprint function not supported
	EM_ZZ_SUPPORTFINGERPRINT_SUPPORT,				// Fingerprint function supported
}EM_ZZ_SUPPORTFINGERPRINT; 

// Holiday Schedule
typedef struct tagZZNET_SPECIAL_DAYS_SCHEDULE
{
	BOOL								bSupport;						// Whether holiday schedule is supported
	int									nMaxSpecialDaysSchedules;		// Max number of schedules supported by device
	int									nMaxTimePeriodsPerDay;			// Max time periods per day
	int									nMaxSpecialDayGroups;			// Max holiday groups supported by device
	int									nMaxDaysInSpecialDayGroup;		// Max holidays per holiday group
	BYTE								byReserved[128];				// Reserved bytes
} ZZNET_SPECIAL_DAYS_SCHEDULE;

// Access Control Capability
typedef struct tagZZ_CFG_CAP_ACCESSCONTROL
{
	int										nAccessControlGroups;			// Access control groups
    BOOL									bSupAccessControlAlarmRecord;   // Whether access control alarm logs are recorded
	EM_ZZ_CUSTOM_PASSWORD_ENCRYPTION_MODE   emCustomPasswordEncryption;		// Password storage mode in AccessControlCustomPassword
	EM_ZZ_SUPPORTFINGERPRINT				emSupportFingerPrint;			// Whether fingerprint function is supported
    BOOL									bOnlySingleDoorAuth;            // Whether only single door authorization (issuing cards) is supported
    BOOL									bAsynAuth;                      // Whether asynchronous authorization return is supported
	ZZNET_SPECIAL_DAYS_SCHEDULE				stSpecialDaysSchedule;			// Holiday schedule
}ZZ_CFG_CAP_ACCESSCONTROL;

// Sensor Sense Method Enum Type
typedef enum tagEM_ZZ_SENSE_METHOD
{
    EM_ZZ_SENSE_UNKNOWN = -1,		// Unknown type
	EM_ZZ_SENSE_DOOR=0,			// Door magnetic
	EM_ZZ_SENSE_PASSIVEINFRA,		// Passive infrared
	EM_ZZ_SENSE_GAS,				// Gas sensor
	EM_ZZ_SENSE_SMOKING,			// Smoke sensor
	EM_ZZ_SENSE_WATER,				// Water sensor
	EM_ZZ_SENSE_ACTIVEFRA,			// Active infrared
	EM_ZZ_SENSE_GLASS,				// Glass break
	EM_ZZ_SENSE_EMERGENCYSWITCH,	// Emergency switch
	EM_ZZ_SENSE_SHOCK,				// Shock/Vibration
	EM_ZZ_SENSE_DOUBLEMETHOD,		// Dual-tech (Infrared + Microwave)
	EM_ZZ_SENSE_THREEMETHOD,		// Tri-tech
	EM_ZZ_SENSE_TEMP,				// Temperature
	EM_ZZ_SENSE_HUMIDITY,			// Humidity
    EM_ZZ_SENSE_WIND,				// Wind speed
	EM_ZZ_SENSE_CALLBUTTON,		// Call button
	EM_ZZ_SENSE_GASPRESSURE,		// Gas pressure
	EM_ZZ_SENSE_GASCONCENTRATION,	// Gas concentration
	EM_ZZ_SENSE_GASFLOW,			// Gas flow
    EM_ZZ_SENSE_OIL,				// Oil level detection
    EM_ZZ_SENSE_MILEAGE,			// Mileage detection
	EM_ZZ_SENSE_OTHER,				// Other
	EM_ZZ_SEHSE_CO2,				// CO2 concentration detection
	EM_ZZ_SEHSE_SOUND,				// Noise detection
	EM_ZZ_SEHSE_PM25,				// PM2.5 detection
	EM_ZZ_SEHSE_SF6,				// SF6 concentration detection
	EM_ZZ_SEHSE_O3,				// Ozone
	EM_ZZ_SEHSE_AMBIENTLIGHT,		// Ambient light detection
	EM_ZZ_SEHSE_INFRARED,			// Infrared alarm
	EM_ZZ_SEHSE_TEMP1500,			// 1500 Temperature sensor
	EM_ZZ_SEHSE_TEMPDS18B20,		// DS18B20 Temperature sensor
	EM_ZZ_SEHSE_HUMIDITY1500,		// 1500 Humidity sensor
	EM_ZZ_SEHSE_URGENCYBUTTON,		// Emergency button
	EM_ZZ_SEHSE_STEAL,				// Theft/Steal
	EM_ZZ_SEHSE_PERIMETER,			// Perimeter
	EM_ZZ_SEHSE_PREVENTREMOVE,		// Tamper/Prevent remove
	EM_ZZ_SEHSE_DOORBELL,			// Doorbell
	EM_ZZ_SEHSE_ALTERVOLT,			// AC Voltage sensor
	EM_ZZ_SEHSE_DIRECTVOLT,		// DC Voltage sensor
	EM_ZZ_SEHSE_ALTERCUR,			// AC Current sensor
	EM_ZZ_SEHSE_DIRECTCUR,			// DC Current sensor
	EM_ZZ_SEHSE_RSUGENERAL,		// Gosuncn general analog
	EM_ZZ_SEHSE_RSUDOOR,			// Gosuncn access control sense
	EM_ZZ_SEHSE_RSUPOWEROFF,		// Gosuncn power off sense
	EM_ZZ_SEHSE_CURTAINSENSOR,		// Curtain sensor
	EM_ZZ_SEHSE_MOBILESENSOR,		// Mobile/Motion sensor
	EM_ZZ_SEHSE_FIREALARM,			// Fire alarm
	EM_ZZ_SENSE_NUM				// Total enum types, Note: cannot be used as a constant
}EM_ZZ_SENSE_METHOD;

// Sensor Alarm Method
typedef struct tagZZ_CFG_EXALARM_SENSE_METHOD
{
	int                 nSupportSenseMethodNum;								// Number of supported sensor methods
	EM_ZZ_SENSE_METHOD     emSupportSenseMethod[ZZC_MAX_ALARM_SENSE_METHOD_NUM];   // Supported sensor methods
}ZZ_CFG_EXALARM_SENSE_METHOD;
















//-----------------------------Image Channel Attributes-------------------------------


// Time Section Information
typedef struct tagZZ_CFG_TIME_SECTION 
{
	DWORD				dwRecordMask;						// Record mask, bitwise: Motion detect, Alarm, Schedule, Bit3~Bit15 reserved, Bit16 Motion Snapshot, Bit17 Alarm Snapshot, Bit18 Schedule Snapshot
	int					nBeginHour;
	int					nBeginMin;
	int					nBeginSec;
	int					nEndHour;
	int					nEndMin;
	int					nEndSec;
} ZZ_CFG_TIME_SECTION;

// Time Schedule Information
typedef struct tagZZ_CFG_TIME_SCHEDULE
{
    BOOL                bEnableHoliday;                     // Enable holiday config, default is unsupported unless TRUE is returned after getting config, do not enable holiday config
	ZZ_CFG_TIME_SECTION	stuTimeSection[ZZC_MAX_TIME_SCHEDULE_NUM][ZZC_MAX_REC_TSECT]; // First dimension: first 7 elements for week days, 8th for holiday; max 6 time sections per day
} ZZ_CFG_TIME_SCHEDULE;







// PTZ Linkage Type
typedef enum tagZZ_CFG_LINK_TYPE
{
	ZZ_LINK_TYPE_NONE,						    		// No linkage
	ZZ_LINK_TYPE_PRESET,								// Link preset
	ZZ_LINK_TYPE_TOUR,									// Link tour
	ZZ_LINK_TYPE_PATTERN,								// Link pattern/track
} ZZ_CFG_LINK_TYPE;

// Linked PTZ Information
typedef struct tagZZ_CFG_PTZ_LINK
{
	ZZ_CFG_LINK_TYPE	emType;						// Linkage type
	int					nValue;						// Linkage value corresponds to preset number, tour number, etc.
} ZZ_CFG_PTZ_LINK;

// Linked PTZ Information Extended
typedef struct tagZZ_CFG_PTZ_LINK_EX
{
	ZZ_CFG_LINK_TYPE	emType;				// Linkage type 
	int			    nParam1;			// Linkage parameter 1
	int			    nParam2;            // Linkage parameter 2
	int			    nParam3;            // Linkage parameter 3
	int			    nChannelID;         // Linked PTZ channel ID
} ZZ_CFG_PTZ_LINK_EX;

// Event Title Content Structure
typedef struct tagZZ_CFG_EVENT_TITLE
{
	char				szText[ZZC_MAX_CHANNELNAME_LEN];
	ZZ_CFG_POLYGON		stuPoint;			// Title top-left coordinate, using 0-8191 relative coordinate system
	ZZ_CFG_SIZE     	stuSize;			// Title width and height, using 0-8191 relative coordinate system, 0 means auto-adaptive to font
    ZZ_CFG_RGBA			stuFrontColor;		// Foreground color
    ZZ_CFG_RGBA			stuBackColor;		// Background color
} ZZ_CFG_EVENT_TITLE;

// Email Attachment Type
typedef enum tagZZ_CFG_ATTACHMENT_TYPE
{
	ZZ_CFG_ATTACHMENT_TYPE_PIC,							// Picture attachment
	ZZ_CFG_ATTACHMENT_TYPE_VIDEO,						// Video attachment
	ZZ_CFG_ATTACHMENT_TYPE_NUM,							// Attachment type count
} ZZ_CFG_ATTACHMENT_TYPE;
// Email Detailed Content
typedef struct tagZZ_CFG_MAIL_DETAIL
{
	   ZZ_CFG_ATTACHMENT_TYPE emAttachType;                 // Attachment type
       int                 nMaxSize;                     // File size limit, unit kB
       int                 nMaxTimeLength;               // Max record time length, unit seconds, valid for video
}ZZ_CFG_MAIL_DETAIL;

// Split Mode
typedef enum tagZZ_CFG_SPLITMODE
{
	ZZ_SPLITMODE_1  = 1,						// 1 Window
	ZZ_SPLITMODE_2  = 2,						// 2 Windows
	ZZ_SPLITMODE_4 = 4,						// 4 Windows
	ZZ_SPLITMODE_6 = 6,						// 6 Windows
	ZZ_SPLITMODE_8 = 8,						// 8 Windows
	ZZ_SPLITMODE_9 = 9,						// 9 Windows
	ZZ_SPLITMODE_12 = 12,				    	// 12 Windows
	ZZ_SPLITMODE_16 = 16,				    	// 16 Windows
	ZZ_SPLITMODE_20 = 20,				    	// 20 Windows
	ZZ_SPLITMODE_25 = 25,					    // 25 Windows
	ZZ_SPLITMODE_36 = 36,					    // 36 Windows
	ZZ_SPLITMODE_64 = 64,					    // 64 Windows
	ZZ_SPLITMODE_144 = 144,					// 144 Windows
	ZZ_SPLITMODE_PIP = 1000,                   // PIP split mode base value
	ZZ_SPLITMODE_PIP1 = ZZ_SPLITMODE_PIP + 1,		// PIP mode, 1 full screen + 1 small window
	ZZ_SPLITMODE_PIP3 = ZZ_SPLITMODE_PIP + 3,		// PIP mode, 1 full screen + 3 small windows
	ZZ_SPLITMODE_FREE = ZZ_SPLITMODE_PIP * 2,	// Free window mode, allows creating/closing windows, setting position and Z-order
	ZZ_SPLITMODE_COMPOSITE_1 = ZZ_SPLITMODE_PIP * 3 + 1,	// Fusion screen member 1 split
	ZZ_SPLITMODE_COMPOSITE_4 = ZZ_SPLITMODE_PIP * 3 + 4,	// Fusion screen member 4 split
	ZZ_SPLITMODE_3  = 10,						// 3 Windows
	ZZ_SPLITMODE_3B = 11,						// 3 Windows Inverted
	ZZ_SPLITMODE_EOF,                          // End Flag
} ZZ_CFG_SPLITMODE;

// Tour Linkage Config
typedef struct tagZZ_CFG_TOURLINK
{
	BOOL				bEnable;			             // Tour enable
	ZZ_CFG_SPLITMODE	emSplitMode;		             // Split mode during tour
	int			        nChannels[ZZC_MAX_VIDEO_CHANNEL_NUM];  // Tour channel ID list
	int			        nChannelCount;		             // Tour channel count
} ZZ_CFG_TOURLINK;

// Access Control Operation Type
enum EM_ZZ_CFG_ACCESSCONTROLTYPE
{
	EM_ZZ_CFG_ACCESSCONTROLTYPE_NULL = 0,					// No operation
	EM_ZZ_CFG_ACCESSCONTROLTYPE_AUTO,						// Auto
	EM_ZZ_CFG_ACCESSCONTROLTYPE_OPEN,						// Open door
	EM_ZZ_CFG_ACCESSCONTROLTYPE_CLOSE,						// Close door
	EM_ZZ_CFG_ACCESSCONTROLTYPE_OPENALWAYS,				// Always open
	EM_ZZ_CFG_ACCESSCONTROLTYPE_CLOSEALWAYS,				// Always closed
};

// Access Control Linkage Operation Combination
#define ZZC_MAX_ACCESSCONTROL_NUM	8						// Max access control operation combination count


// Voice Call Initiator
typedef enum
{
	EM_ZZ_CALLER_DEVICE = 0,								// Initiated by device
}EM_ZZ_CALLER_TYPE;

// Call Protocol
typedef enum
{
	EM_ZZ_CALLER_PROTOCOL_CELLULAR = 0,					// Cellular/Phone mode
}EM_ZZ_CALLER_PROTOCOL_TYPE;


// Voice Call Linkage Information
typedef struct tagZZ_CFG_TALKBACK_INFO
{
	BOOL						bCallEnable;					// Voice call enable
	EM_ZZ_CALLER_TYPE			emCallerType;					// Voice call initiator
	EM_ZZ_CALLER_PROTOCOL_TYPE	emCallerProtocol;			// Voice call protocol
}ZZ_CFG_TALKBACK_INFO;

// Alarm Phone Center Linkage Information
typedef struct tagZZ_CFG_PSTN_ALARM_SERVER
{
	BOOL				bNeedReport;						// Whether to report to alarm phone center
	int					nServerCount;						// Number of alarm phone servers					
	BYTE 				byDestination[ZZC_MAX_PSTN_SERVER_NUM];	// Index of reporting alarm center, see config CFG_PSTN_ALARM_CENTER_INFO
}ZZ_CFG_PSTN_ALARM_SERVER;

// Alarm Linkage Information
typedef struct tagZZ_CFG_ALARM_MSG_HANDLE
{
	// Capability
	bool				abRecordMask;
	bool				abRecordEnable;
	bool				abRecordLatch;
	bool				abAlarmOutMask;
	bool				abAlarmOutEn;
	bool				abAlarmOutLatch;	
	bool				abExAlarmOutMask;
	bool				abExAlarmOutEn;
	bool				abPtzLinkEn;
	bool				abTourMask;
	bool				abTourEnable;
	bool				abSnapshot;
	bool				abSnapshotEn;
	bool				abSnapshotPeriod;
	bool				abSnapshotTimes;
	bool				abTipEnable;
	bool				abMailEnable;
	bool				abMessageEnable;
	bool				abBeepEnable;
	bool				abVoiceEnable;
	bool				abMatrixMask;
	bool				abMatrixEnable;
	bool				abEventLatch;
	bool				abLogEnable;
	bool				abDelay;
	bool				abVideoMessageEn;
	bool				abMMSEnable;
	bool				abMessageToNetEn;
	bool				abTourSplit;
	bool				abSnapshotTitleEn;

    bool                abChannelCount;
	bool                abAlarmOutCount;
	bool                abPtzLinkEx;
	bool                abSnapshotTitle;
	bool                abMailDetail;
	bool                abVideoTitleEn;
	bool                abVideoTitle;
	bool                abTour;
	bool                abDBKeys;
	bool                abJpegSummary;
	bool                abFlashEn;
	bool                abFlashLatch;
	


	// Information
	int					nChannelCount;								 // Device video channel count
	int					nAlarmOutCount;								 // Device alarm output count
	DWORD				dwRecordMask[ZZC_MAX_CHANNEL_COUNT];			 // Record channel mask (bitwise)
	BOOL				bRecordEnable;								 // Record enable
	int					nRecordLatch;								 // Record latch/delay time (seconds)
	DWORD				dwAlarmOutMask[ZZC_MAX_CHANNEL_COUNT];			 // Alarm output channel mask
	BOOL				bAlarmOutEn;								 // Alarm output enable
	int					nAlarmOutLatch;								 // Alarm output latch/delay time (seconds)
	DWORD				dwExAlarmOutMask[ZZC_MAX_CHANNEL_COUNT];		 // Extended alarm output channel mask
	BOOL				bExAlarmOutEn;								 // Extended alarm output enable
	ZZ_CFG_PTZ_LINK		stuPtzLink[ZZC_MAX_VIDEO_CHANNEL_NUM];			 // PTZ linkage items
	BOOL				bPtzLinkEn;									 // PTZ linkage enable
	DWORD				dwTourMask[ZZC_MAX_CHANNEL_COUNT];				 // Tour channel mask
	BOOL				bTourEnable;								 // Tour enable
	DWORD				dwSnapshot[ZZC_MAX_CHANNEL_COUNT];				 // Snapshot channel mask
	BOOL				bSnapshotEn;								 // Snapshot enable
	int					nSnapshotPeriod;							 // Snapshot period (seconds)
	int					nSnapshotTimes;								 // Snapshot times
	BOOL				bTipEnable;									 // Local message box tip
	BOOL				bMailEnable;								 // Send email, if picture exists, as attachment
	BOOL				bMessageEnable;								  // Upload to alarm server
	BOOL				bBeepEnable;							 	  // Beep
	BOOL				bVoiceEnable;								  // Voice prompt
	DWORD				dwMatrixMask[ZZC_MAX_CHANNEL_COUNT];			  // Link video matrix channel mask
	BOOL				bMatrixEnable;								  // Link video matrix
	int					nEventLatch;								  // Link start delay time (seconds), 0-15
	BOOL				bLogEnable;									  // Whether to record log
	int					nDelay;										  // Delay before taking effect, unit: seconds
	BOOL				bVideoMessageEn;							  // Overlay tips subtitle on video. Includes event type, channel ID, second timer.
	BOOL				bMMSEnable;									  // MMS enable
	BOOL				bMessageToNetEn;							  // Upload message to network enable
	int					nTourSplit;									  // Split mode during tour 0: 1 window; 1: 8 windows
	BOOL				bSnapshotTitleEn;							  // Whether to overlay image title
	int                 nPtzLinkExNum;                                // PTZ config count
	ZZ_CFG_PTZ_LINK_EX     stuPtzLinkEx[ZZC_MAX_VIDEO_CHANNEL_NUM];          // Extended PTZ info
	int                 nSnapTitleNum;                                // Image title content count
	ZZ_CFG_EVENT_TITLE     stuSnapshotTitle[ZZC_MAX_VIDEO_CHANNEL_NUM];      // Image title content
	ZZ_CFG_MAIL_DETAIL     stuMailDetail;                                // Mail detail content
	BOOL                bVideoTitleEn;                                // Whether to overlay video title, mainly for main stream
    int                 nVideoTitleNum;                               // Video title content count
	ZZ_CFG_EVENT_TITLE     stuVideoTitle[ZZC_MAX_VIDEO_CHANNEL_NUM];         // Video title content
	int                 nTourNum;                                     // Tour linkage count
	ZZ_CFG_TOURLINK        stuTour[ZZC_MAX_VIDEO_CHANNEL_NUM];               // Tour linkage config
	int                 nDBKeysNum;			                          // Effective number of specified database keys
	char                szDBKeys[ZZC_MAX_DBKEY_NUM][ZZC_MAX_CHANNELNAME_LEN]; // Keys detailed info to write to database
	BYTE                byJpegSummary[ZZC_MAX_SUMMARY_LEN];               // Summary info overlaid on JPEG
	BOOL                bFlashEnable;                                 // Whether to enable flash/strobe light
	int                 nFlashLatch;                                  // Flash light delay time (seconds), range: [10,300]
	
	bool				abAudioFileName;
	bool				abAlarmBellEn;
	bool				abAccessControlEn;
	bool				abAccessControl;

	char				szAudioFileName[MAX_PATH];					// Linked audio file absolute path
	BOOL				bAlarmBellEn;								// Alarm bell enable
	BOOL				bAccessControlEn;							// Access control enable

	DWORD				dwAccessControl;							// Access control group count
	EM_ZZ_CFG_ACCESSCONTROLTYPE	emAccessControlType[ZZC_MAX_ACCESSCONTROL_NUM];	// Access control linkage operation info
	
	bool				abTalkBack;	
	ZZ_CFG_TALKBACK_INFO	stuTalkback;								// Voice call linkage info

	bool				abPSTNAlarmServer;
	ZZ_CFG_PSTN_ALARM_SERVER	stuPSTNAlarmServer;						// Alarm phone center linkage info
    ZZ_CFG_TIME_SCHEDULE       stuTimeSection;                         // Event response schedule
	bool				abAlarmBellLatch;
	int					nAlarmBellLatch;							// Alarm bell output delay time (10-300 seconds)

} ZZ_CFG_ALARM_MSG_HANDLE;



// Alarm Enable Control Mode Enum Type
typedef enum tagEM_ZZ_CTRL_ENABLE
{
	EM_ZZ_CTRL_NORMAL=0,   // Do not control enable
	EM_ZZ_CTRL_ALWAYS_EN,  // Always enable
	EM_ZZ_CTRL_ONCE_DIS,   // Bypass
	EM_ZZ_CTRL_ALWAYS_DIS, // Remove
	EM_ZZ_CTRL_NUM         // Total enum types
}EM_ZZ_CTRL_ENABLE;

// Defence Area Type
typedef enum tagEM_ZZ_CFG_DEFENCEAREATYPE
{
	EM_ZZ_CFG_DefenceAreaType_Unknown = 0,     // Unknown type
	EM_ZZ_CFG_DefenceAreaType_InTime,          // Instant area 
	EM_ZZ_CFG_DefenceAreaType_Delay,           // Delay area
	EM_ZZ_CFG_DefenceAreaType_FullDay,         // 24-hour area
    EM_ZZ_CFG_DefenceAreaType_Follow,          // Follow area
    EM_ZZ_CFG_DefenceAreaType_Medical,         // Medical emergency area
    EM_ZZ_CFG_DefenceAreaType_Panic,           // Panic area
    EM_ZZ_CFG_DefenceAreaType_Fire,            // Fire area
    EM_ZZ_CFG_DefenceAreaType_FullDaySound,    // 24-hour sound area
    EM_ZZ_CFG_DefenceAreaType_FullDaySlient,   // 24-hour silent area
    EM_ZZ_CFG_DefenceAreaType_Entrance1,       // Entrance area 1
    EM_ZZ_CFG_DefenceAreaType_Entrance2,       // Entrance area 2
    EM_ZZ_CFG_DefenceAreaType_InSide,          // Inside area
    EM_ZZ_CFG_DefenceAreaType_OutSide,         // Outside area
    EM_ZZ_CFG_DefenceAreaType_PeopleDetect,    // People detection area
}EM_ZZ_CFG_DEFENCEAREATYPE;

// External Alarm Input Config
typedef struct tagZZ_CFG_ALARMIN_INFO
{
	int						nChannelID;									// Alarm channel ID (starts from 0)
	BOOL					bEnable;									// Enable switch
	char					szChnName[ZZC_MAX_CHANNELNAME_LEN];			// Alarm channel name
	int						nAlarmType;									// Alarm type, 0: Normally Closed, 1: Normally Open
	ZZ_CFG_ALARM_MSG_HANDLE stuEventHandler;							// Alarm linkage
	ZZ_CFG_TIME_SECTION		stuTimeSection[ZZC_WEEK_DAY_NUM][ZZC_MAX_REC_TSECT];// Event response time section, this member takes precedence over stuEventHandler's stuTimeSection
	BOOL					abDevID;									// 
	char					szDevID[ZZC_MAX_NAME_LEN];					// Device ID
	int                 	nPole;                                      // Sensor trigger mode, 0: High level, 1: Low level;
	                                                                	// Specifics depend on Ground or Power, used with nAlarmType
	EM_ZZ_SENSE_METHOD      emSense;                                    // Sensor sense method
	EM_ZZ_CTRL_ENABLE       emCtrl;                                     // Alarm enable control mode
	int                     nDisDelay;                                  // Disarm delay time, valid only when defence area type is "Delay", unit: seconds, max time obtained via capability query
	                                                               		// Valid when emCtrl is EM_CTRL_NORMAL or EM_CTRL_ALWAYS_EN.

	EM_ZZ_CFG_DEFENCEAREATYPE emDefenceAreaType;						// Defence area type, supported types obtained via capability query
	int						nEnableDelay;								// Arm delay time, valid only when defence area type is "Delay", unit: seconds, max time obtained via capability query    
    int                 	nSlot;                                      // Root address, -1 means invalid, 0 means local channel, 1 means extended channel connected to first serial port, 2, 3... and so on
    int                 	nLevel1;                                    // First level cascade address, indicates the nLevel1-th detector or meter connected to the nSlot serial port, -1 invalid, starts from 0
    bool                	abLevel2;                                   // Indicates if nLevel2 field exists
    int                 	nLevel2;                                    // Second level cascade address, indicates the detector index on the nLevel1-th meter, -1 invalid, starts from 0
} ZZ_CFG_ALARMIN_INFO;





//////////////////////////////////////////////////////////////////////////
// Arm/Disarm Config

#define	ZZC_MAX_SCENE_COUNT	8		//	Max scene mode count

// Scene Mode
typedef enum tagemZZ_CFG_SCENE_MODE
{	
	emZZ_CFG_SCENE_MODE_UNKNOWN,			// Unknown mode
	emZZ_CFG_SCENE_MODE_OUTDOOR,			// Outdoor mode
	emZZ_CFG_SCENE_MODE_INDOOR,			// Indoor mode
    emZZ_CFG_SCENE_MODE_WHOLE ,            // Global mode
    emZZ_CFG_SCENE_MODE_RIGHTNOW,          // Immediate mode
    emZZ_CFG_SCENE_MODE_AUTO,              // Auto mode
    emZZ_CFG_SCENE_MODE_FORCE,             // Force mode
	emZZ_CFG_SCENE_MODE_SLEEPING,			// Sleeping mode
	emZZ_CFG_SCENE_MODE_CUSTOM,			// Custom mode
}emZZ_CFG_SCENE_MODE;

typedef struct tagZZ_CFG_SCENE_INFO
{
	emZZ_CFG_SCENE_MODE emName;							// Mode name
	int				    nAlarmInChannelsCount;				// Alarm channel count
	int				 	nRetAlarmInChannelsCount;			// Actual returned alarm channel count
	int*			 	pnAlarmInChannels;					// Enabled alarm input channel ID list, memory allocated by user, size sizeof(int)*nAlarmInChannelsCount
}ZZ_CFG_SCENE_INFO;

// Arm/Disarm Config, Corresponds to command (CFG_CMD_COMMGLOBAL)
// When product model is not AS5008, enable bSceneEnable and emCurrentScene, do not enable nSceneCount and stuScense[MAX_SCENE_COUNT]
// When product model is AS5008, do not enable bSceneEnable and emCurrentScene, enable nSceneCount and stuScense[MAX_SCENE_COUNT]
typedef struct tagZZ_CFG_COMMGLOBAL_INFO
{
    BOOL                	bEnable;                            // TRUE: Arm; FALSE: Disarm; Applies to whole device, not channel specific
    BOOL                	bSceneEnable;                       // Whether to enable scene mode
    emZZ_CFG_SCENE_MODE     emCurrentScene;                     // Currently selected scene mode
    int                 	nSceneCount;                        // Effective scene mode count
    ZZ_CFG_SCENE_INFO       stuScense[ZZC_MAX_SCENE_COUNT];         // Scene mode definitions, one config per mode
}ZZ_CFG_COMMGLOBAL_INFO;

#define ZZC_MAX_ALARM_LIMITS_NUM    8                                   // Max alarm limits count

// Analog Alarm Input Channel Config
typedef struct tagZZ_CFG_ANALOGALARM_INFO	// =>CFG_CMD_ANALOGALARM
{
	BOOL				bEnable;									// Enable switch (Bypassed if whole device is armed but channel is disabled)
	char				szChnName[ZZC_MAX_CHANNELNAME_LEN];				// Alarm channel name
	float				fUpperLimit;								// Range upper limit
	float				fLowerLimit;								// Range lower limit
	int					nSensitivity;								// Sensitivity, Unit: Percentage
	float				fCompensation;								// Compensation value, depends on sensor type
	float				fLimit1;									// Alarm limit 1, not recommended, use fAlarmLimits field
	float				fLimit2;									// Alarm limit 2, not recommended, use fAlarmLimits field
	float				fLimit3;									// Alarm limit 3, not recommended, use fAlarmLimits field
	float				fLimit4;									// Alarm limit 4, not recommended, use fAlarmLimits field
	BYTE				byMode;										// Alarm mode, represented by mask, possible values 1111, 1110, 1100, 1000, 0000
																	// 1 means exceeding alarm threshold, 0 means below alarm threshold
																	// Mode corresponds to 4 alarm thresholds from left to right, increasing order
																	// Example: 1110 means exceeding 1st, 2nd, 3rd thresholds, but below 4th threshold
	BYTE				byReserve[3];								// Reserved bytes
	ZZ_CFG_ALARM_MSG_HANDLE	stuEventHandler;						// Alarm linkage
	ZZ_CFG_TIME_SECTION	stuTimeSection[ZZC_WEEK_DAY_NUM][ZZC_MAX_REC_TSECT];// Event response time section, takes precedence over stuEventHandler
	EM_ZZ_SENSE_METHOD		emSense;									// Sensor method
	char				szSensorType[ZZC_CFG_COMMON_STRING_64];			// Sensor type
    int                 nSlot;                                      // Root address, 0 means local channel, 1 means extended channel on 1st serial port, 2, 3... etc., -1 invalid
	int                 nLevel1;                                    // First level cascade address, nLevel1-th detector/meter on nSlot port, starts from 0, -1 invalid
    bool                abLevel2;                                   // Indicates if nLevel2 field exists
    int                 nLevel2;                                    // Second level cascade address, detector index on nLevel1-th meter, starts from 0
    int                 nAlamrLimits;                               // Effective alarm limit count
    float               fAlarmLimits[ZZC_MAX_ALARM_LIMITS_NUM];         // Alarm limits
    int                 nNotifyInterval;                            // Analog upload interval, unit: seconds
    int                 nAlarmInterval;                             // Upload interval after triggering limits, unit: seconds
}ZZ_CFG_ANALOGALARM_INFO;

// Alarm Output Channel Status Config
typedef struct tagZZ_CFG_ALARMOUT_INFO		// =>CFG_CMD_ALARMOUT
{
	int					nChannelID;									// Alarm channel ID (starts from 0)
	char				szChnName[ZZC_MAX_CHANNELNAME_LEN];				// Alarm channel name
	char				szOutputType[ZZC_MAX_NAME_LEN];					// Output type, user defined
	int					nOutputMode;								// Output mode, 0-Auto alarm, 1-Force alarm, 2-Close alarm, 3-Switch mode
    int                 nPulseDelay;                                // Pulse mode output time, unit seconds (0-255 seconds)
    int                 nSlot;                                      // Root address, 0 means local, 1 means extended on 1st serial, 2, 3... etc., -1 invalid
    int                 nLevel1;                                    // First level cascade address, starts from 0, -1 invalid
    bool                abLevel2;                                   // Indicates if nLevel2 field exists
    int                 nLevel2;                                    // Second level cascade address, starts from 0
}ZZ_CFG_ALARMOUT_INFO;








// Image Quality
typedef enum tagZZ_CFG_IMAGE_QUALITY
{
	ZZ_IMAGE_QUALITY_Q10 = 1,							// Image quality 10%
	ZZ_IMAGE_QUALITY_Q30,								// Image quality 30%
	ZZ_IMAGE_QUALITY_Q50,								// Image quality 50%
	ZZ_IMAGE_QUALITY_Q60,								// Image quality 60%
	ZZ_IMAGE_QUALITY_Q80,								// Image quality 80%
	ZZ_IMAGE_QUALITY_Q100,								// Image quality 100%
} ZZ_CFG_IMAGE_QUALITY;

// Video Compression Format
typedef enum tagZZ_CFG_VIDEO_COMPRESSION
{
	ZZ_VIDEO_FORMAT_MPEG4,								// MPEG4
	ZZ_VIDEO_FORMAT_MS_MPEG4,							// MS-MPEG4
	ZZ_VIDEO_FORMAT_MPEG2,								// MPEG2
	ZZ_VIDEO_FORMAT_MPEG1,								// MPEG1
	ZZ_VIDEO_FORMAT_H263,								// H.263
	ZZ_VIDEO_FORMAT_MJPG,								// MJPG
	ZZ_VIDEO_FORMAT_FCC_MPEG4,							// FCC-MPEG4
	ZZ_VIDEO_FORMAT_H264,								// H.264
    ZZ_VIDEO_FORMAT_H265,								// H.265
	ZZ_VIDEO_FORMAT_SVAC,								// SVAC
} ZZ_CFG_VIDEO_COMPRESSION;
// Audio Encoding Format
typedef enum tatZZ_CFG_AUDIO_FORAMT
{
	ZZ_AUDIO_FORMAT_G711A,                              // G711a
    ZZ_AUDIO_FORMAT_PCM,                                // PCM
    ZZ_AUDIO_FORMAT_G711U,                              // G711u
    ZZ_AUDIO_FORMAT_AMR,                                // AMR
    ZZ_AUDIO_FORMAT_AAC,                                // AAC
} ZZ_CFG_AUDIO_FORMAT;

// Bitrate Control Mode
typedef enum tagZZ_CFG_BITRATE_CONTROL
{
	ZZ_BITRATE_CBR,									// Constant Bitrate
	ZZ_BITRATE_VBR,									// Variable Bitrate
} ZZ_CFG_BITRATE_CONTROL;

// H264 Profile Rank
typedef enum tagZZ_CFG_H264_PROFILE_RANK
{
	ZZ_CFG_PROFILE_BASELINE = 1,                       // Provides I/P frames, only supports progressive and CAVLC
	ZZ_CFG_PROFILE_MAIN,                               // Provides I/P/B frames, supports progressive and interlaced, provides CAVLC or CABAC
	ZZ_CFG_PROFILE_EXTENDED,                           // Provides I/P/B/SP/SI frames, only supports progressive and CAVLC
	ZZ_CFG_PROFILE_HIGH,                               // i.e., FRExt, Main_Profile plus: 8x8 intra prediction, custom 
												// quantization, lossless video coding, more YUV formats
}ZZ_CFG_H264_PROFILE_RANK;

// Resolution Enum
typedef enum tagZZ_CFG_CAPTURE_SIZE
{
	ZZ_IMAGE_SIZE_D1,								// 704*576(PAL)  704*480(NTSC)
	ZZ_IMAGE_SIZE_HD1,								// 352*576(PAL)  352*480(NTSC)
	ZZ_IMAGE_SIZE_BCIF,							// 704*288(PAL)  704*240(NTSC)
	ZZ_IMAGE_SIZE_CIF,								// 352*288(PAL)  352*240(NTSC)
	ZZ_IMAGE_SIZE_QCIF,							// 176*144(PAL)  176*120(NTSC)
	ZZ_IMAGE_SIZE_VGA,								// 640*480
	ZZ_IMAGE_SIZE_QVGA,							// 320*240
	ZZ_IMAGE_SIZE_SVCD,							// 480*480
	ZZ_IMAGE_SIZE_QQVGA,							// 160*128
	ZZ_IMAGE_SIZE_SVGA,							// 800*592
	ZZ_IMAGE_SIZE_XVGA,							// 1024*768
	ZZ_IMAGE_SIZE_WXGA,							// 1280*800
	ZZ_IMAGE_SIZE_SXGA,							// 1280*1024  
	ZZ_IMAGE_SIZE_WSXGA,							// 1600*1024  
	ZZ_IMAGE_SIZE_UXGA,							// 1600*1200
	ZZ_IMAGE_SIZE_WUXGA,							// 1920*1200
	ZZ_IMAGE_SIZE_LTF,								// 240*192
	ZZ_IMAGE_SIZE_720,								// 1280*720
	ZZ_IMAGE_SIZE_1080,							// 1920*1080
	ZZ_IMAGE_SIZE_1_3M,							// 1280*960
	ZZ_IMAGE_SIZE_2M,							    // 1872*1408
	ZZ_IMAGE_SIZE_5M,						   	    // 3744*1408
	ZZ_IMAGE_SIZE_3M,							    // 2048*1536
	ZZ_IMAGE_SIZE_5_0M,                            // 2432*2050
	ZZ_IMAGE_SIZE_1_2M,							// 1216*1024
	ZZ_IMAGE_SIZE_1408_1024,                       // 1408*1024
	ZZ_IMAGE_SIZE_8M,                              // 3296*2472
	ZZ_IMAGE_SIZE_2560_1920,                       // 2560*1920(5M)
	ZZ_IMAGE_SIZE_960H,                            // 960*576(PAL) 960*480(NTSC)
	ZZ_IMAGE_SIZE_960_720,                         // 960*720
	ZZ_IMAGE_SIZE_NHD,							    // 640*360
	ZZ_IMAGE_SIZE_QNHD,							// 320*180
	ZZ_IMAGE_SIZE_QQNHD,							// 160*90
	ZZ_IMAGE_SIZE_NR  
} ZZ_CFG_CAPTURE_SIZE;

// Video Format
typedef struct tagZZ_CFG_VIDEO_FORMAT
{
	// Capability
	bool				abCompression;
	bool				abWidth;
	bool				abHeight;
	bool				abBitRateControl;
	bool				abBitRate;
	bool				abFrameRate;
	bool				abIFrameInterval;
	bool				abImageQuality;
	bool				abFrameType;
	bool				abProfile;

	// Information
	ZZ_CFG_VIDEO_COMPRESSION emCompression;			// Video compression format
	int					nWidth;						// Video width
	int					nHeight;					// Video height
	ZZ_CFG_BITRATE_CONTROL	emBitRateControl;			// Bitrate control mode
	int					nBitRate;					// Video bitrate (kbps)
	float				nFrameRate;					// Video framerate
	int					nIFrameInterval;			// I-Frame interval (1-100), e.g., 50 means one I frame every 49 P/B frames.
	ZZ_CFG_IMAGE_QUALITY	emImageQuality;				// Image quality
	int					nFrameType;					// Packaging mode, 0-ZLAV, 1-"PS"
    ZZ_CFG_H264_PROFILE_RANK emProfile;                // H.264 encoding rank
} ZZ_CFG_VIDEO_FORMAT;

// Audio Format
typedef struct tagZZ_CFG_AUDIO_FORMAT 
{
	// Capability
	bool				abCompression;
	bool				abDepth;
	bool				abFrequency;
	bool				abMode;
	bool				abFrameType;
	bool				abPacketPeriod;

	// Information
	ZZ_CFG_AUDIO_FORMAT	emCompression;				// Audio compression mode
	ZZ_AV_int32			nDepth;						// Audio sample depth
	ZZ_AV_int32			nFrequency;					// Audio sample frequency
	ZZ_AV_int32			nMode;						// Audio encode mode
	ZZ_AV_int32			nFrameType;					// Audio packaging mode, 0-ZLAV, 1-PS
	ZZ_AV_int32			nPacketPeriod;				// Audio packaging period, ms
} ZZ_CFG_AUDIO_ENCODE_FORMAT;

// Video Encode Parameters
typedef struct tagZZ_CFG_VIDEOENC_OPT
{
	// Capability
	bool				abVideoEnable;
	bool				abAudioEnable;
	bool				abSnapEnable;
	bool                abAudioAdd;                 // Audio overlay capability
	bool				abAudioFormat;

	// Information
	BOOL				bVideoEnable;				// Video enable
	ZZ_CFG_VIDEO_FORMAT	stuVideoFormat;				// Video format
	BOOL				bAudioEnable;				// Audio enable
	BOOL				bSnapEnable;				// Schedule snapshot enable
	BOOL                bAudioAddEnable;            // Audio overlay enable
	ZZ_CFG_AUDIO_ENCODE_FORMAT	stuAudioFormat;			// Audio format
} ZZ_CFG_VIDEOENC_OPT;



 // Cover/Mask Information
typedef struct tagZZ_CFG_COVER_INFO
{
	// Capability
	bool				abBlockType;
	bool				abEncodeBlend;
	bool				abPreviewBlend;

	// Information
	ZZ_CFG_RECT			stuRect;					// Covered region coordinates
	ZZ_CFG_RGBA			stuColor;					// Cover color
	int					nBlockType;					// Cover type; 0-Black block, 1-Mosaic
	int					nEncodeBlend;				// Encode level blend; 1-Effective, 0-Ineffective
	int					nPreviewBlend;				// Preview blend; 1-Effective, 0-Ineffective
} ZZ_CFG_COVER_INFO;

// Multi-Region Cover Config
typedef struct tagZZ_CFG_VIDEO_COVER
{
	int                 nTotalBlocks;						// Supported cover blocks count
	int					nCurBlocks;							// Currently set blocks count
	ZZ_CFG_COVER_INFO	stuCoverBlock[ZZC_MAX_VIDEO_COVER_NUM];	// Cover regions	
} ZZ_CFG_VIDEO_COVER;

// OSD Information
typedef struct tagZZ_CFG_OSD_INFO
{
	// Capability
	bool				abShowEnable;

	// Information
	ZZ_CFG_RGBA			stuFrontColor;				// Foreground color
	ZZ_CFG_RGBA			stuBackColor;				// Background color
	ZZ_CFG_RECT			stuRect;					// Rectangular region
	BOOL				bShowEnable;				// Display enable
} ZZ_CFG_OSD_INFO;

// Image Color Attributes
typedef struct tagZZ_CFG_COLOR_INFO
{
	int					nBrightness;				// Brightness (0-100)
	int					nContrast;					// Contrast (0-100)
	int					nSaturation;				// Saturation (0-100)
	int					nHue;						// Hue (0-100)
	int					nGain;						// Gain (0-100)
	BOOL				bGainEn;					// Gain enable
} ZZ_CFG_COLOR_INFO;

// Image Channel Attribute Information
typedef struct tagZZ_CFG_ENCODE_INFO
{
	int                 nChannelID;							// Channel ID (starts from 0), valid when getting; invalid when setting
	char				szChnName[ZZC_MAX_CHANNELNAME_LEN];		// Invalid field
	ZZ_CFG_VIDEOENC_OPT	stuMainStream[ZZC_MAX_VIDEOSTREAM_NUM];	// Main stream, 0-Normal record, 1-Motion record, 2-Alarm record
	int                 nValidCountMainStream;              // Valid count in Main Stream array
	ZZ_CFG_VIDEOENC_OPT	stuExtraStream[ZZC_MAX_VIDEOSTREAM_NUM];// Extra stream, 0-Extra1, 1-Extra2, 2-Extra3
	int                 nValidCountExtraStream;             // Valid count in Extra Stream array
	ZZ_CFG_VIDEOENC_OPT	stuSnapFormat[ZZC_MAX_VIDEOSTREAM_NUM];	// Snapshot, 0-Normal snap, 1-Motion snap, 2-Alarm snap
	int                 nValidCountSnapFormat;              // Valid count in Snapshot array
	DWORD				dwCoverAbilityMask;					// Invalid field
	DWORD				dwCoverEnableMask;					// Invalid field
	ZZ_CFG_VIDEO_COVER	stuVideoCover;						// Invalid field
	ZZ_CFG_OSD_INFO		stuChnTitle;						// Invalid field
	ZZ_CFG_OSD_INFO		stuTimeTitle;						// Invalid field
	ZZ_CFG_COLOR_INFO	stuVideoColor;						// Invalid field
	ZZ_CFG_AUDIO_FORMAT emAudioFormat;                      // Invalid field
	int					nProtocolVer;						// Protocol version, read-only, valid when getting; invalid when setting
} ZZ_CFG_ENCODE_INFO;


// Audio Input Volume Config
typedef struct tagZZ_CFG_AUDIO_INPUT_VOLUME
{
	int				nAudioInputCount;									// Actual audio input channel count
	char			szAudioInputVolume[ZZC_MAX_AUDIO_INPUT_NUM];			// Each element corresponds to an audio input channel volume, range [0, 100]
}ZZ_CFG_AUDIO_INPUT_VOLUME;

// Video Input Config
typedef struct tagZZ_CFG_AUDIO_INPUT 
{
    char        szAudioSource[ZZC_CFG_COMMON_STRING_256];   // Input audio source. If audio channel input is mixed, separate with |.
                                                        // Example: "Mic|LineIn|Remote" means this audio channel is composed of Mic, LineIn, and Remote channel audio input.
                                                        // "Coaxial" Coaxial audio
                                                        // "BNC" Local BNC audio
                                                        // "HDCVI_BNC" Remote HDCVI device audio
                                                        // "LineIn" Line input
                                                        // "Mic" Microphone input
                                                        // "MicOut" Mic output
                                                        // "Remote" Remote channel (only meaningful for PIP channel, indicates PIP main screen is remote channel, using current remote channel's audio as input)
}ZZ_CFG_AUDIO_INPUT;

// Video Input Front-End Capabilities
typedef struct tagZZ_CFG_VIDEO_ENCODECAP
{
	int		nMaxCIFFrame;			// Max CIF P-frame, unit Kbits, default 40
	int		nMinCIFFrame;			// Min CIF P-frame, unit Kbits, default 7
}ZZ_CFG_VIDEO_ENCODECAP;

// Multi-Screen Preview Work Mode
typedef enum tagZZ_CFG_EM_PREVIEW_MODE
{
    ZZ_CFG_EM_PREVIEW_MODE_UNKNOWN = 0,        // 
    ZZ_CFG_EM_PREVIEW_MODE_SNAPSHOT,           // Snapshot mode
    ZZ_CFG_EM_PREVIEW_MODE_SPLITENCODE,        // Split encode mode
    ZZ_CFG_EM_PREVIEW_MODE_SPLITSNAP,          // Split snapshot mode
}ZZ_CFG_EM_PREVIEW_MODE;

#define ZZC_MAX_PREVIEW_MODE_SPLIT_TYPE_NUM     8                           // Max multi-screen preview window split types

// Encoding Capabilities
typedef struct tagZZ_CFG_ENCODECAP
{
	int                     nChannelNum;                                // Actual channel count
	ZZ_CFG_VIDEO_ENCODECAP  stuVideoEncodeCap[ZZC_MAX_VIDEO_CHANNEL_NUM];	// Encoding capabilities per channel array
    ZZ_CFG_EM_PREVIEW_MODE  emPreviewMode;                              // Multi-screen preview work mode
    int                     nSplitModeNum;                              // Effective multi-screen preview window split types
    int                     anSplitMode[ZZC_MAX_PREVIEW_MODE_SPLIT_TYPE_NUM];// Multi-screen preview window split count info, can be 1, 4, 6, 8, 9, 16, 25, 36...
                                                                        // -1 means default [1, 4, 8, 9, 16, … analog channel count], square number of N less than analog channels, includes 8 if analog channels > 8
}ZZ_CFG_ENCODECAP;


// Color
struct ZZ_AV_CFG_Color
{
	ZZ_AV_int32			nStructSize;
	ZZ_AV_int32			nRed;							// Red
	ZZ_AV_int32			nGreen;							// Green
	ZZ_AV_int32			nBlue;							// Blue
	ZZ_AV_int32			nAlpha;							// Alpha/Transparent
};

// Rect
struct ZZ_AV_CFG_Rect 
{
	ZZ_AV_int32			nStructSize;
	ZZ_AV_int32			nLeft;
	ZZ_AV_int32			nTop;
	ZZ_AV_int32			nRight;
	ZZ_AV_int32			nBottom;	
};


#define ZZC_AV_CFG_Monitor_Name_Len		64			// Monitor wall name length
#define ZZC_AV_CFG_Max_TV_In_Block		128			// Max TV count in block
#define ZZC_AV_CFG_Max_Block_In_Wall	128			// Max block count in wall

// Monitor Wall TV Output Channel Info
struct ZZ_AV_CFG_MonitorWallTVOut
{
	ZZ_AV_int32		nStructSize;
	char			szDeviceID[ZZC_AV_CFG_Device_ID_Len];	// Device ID, empty or "Local" means local device
	ZZ_AV_int32		nChannelID;								// Channel ID
	char			szName[ZZC_AV_CFG_Channel_Name_Len];	// Screen name
};

// Monitor Wall Block
struct ZZ_AV_CFG_MonitorWallBlock 
{
	ZZ_AV_int32					nStructSize;
	ZZ_AV_int32					nLine;				// Grid rows occupied by single TV
	ZZ_AV_int32					nColumn;			// Grid columns occupied by single TV
	ZZ_AV_CFG_Rect				stuRect;			// Block region coordinates
	ZZ_AV_int32					nTVCount;			// TV count
	ZZ_AV_CFG_MonitorWallTVOut	stuTVs[ZZC_AV_CFG_Max_TV_In_Block];					// TV array
	ZZ_CFG_TIME_SECTION			stuTimeSection[ZZC_WEEK_DAY_NUM][ZZC_MAX_REC_TSECT];	// Power on/off time
	char						szName[ZZC_AV_CFG_Channel_Name_Len];				// Block name
	char						szCompositeID[ZZC_AV_CFG_Device_ID_Len];			// Composite screen ID
};

// Monitor Wall
struct ZZ_AV_CFG_MonitorWall
{
	ZZ_AV_int32					nStructSize;
	char						szName[ZZC_AV_CFG_Monitor_Name_Len];	// Name
	ZZ_AV_int32					nLine;								// Grid rows
	ZZ_AV_int32					nColumn;							// Grid columns
	ZZ_AV_int32					nBlockCount;						// Block count
	ZZ_AV_CFG_MonitorWallBlock  stuBlocks[ZZC_AV_CFG_Max_Block_In_Wall];// Block array
    BOOL                		bDisable;                           // Disable flag, 0-Effective, 1-Ineffective
    char                		szDesc[ZZC_CFG_COMMON_STRING_256];      // Monitor wall description
};

// Lens Focus Status Info
typedef struct tagZZ_CFG_CAP_FOCUS_STATUS
{
	int					nAutofocusPeak;							// Current AF peak, valid in assistant focus mode
	double		        dFocus;									// Focus position, normalized to 0~1
	double		        dZoom;									// Zoom magnification, normalized to 0~1
	int					nStatus;								// Focus status, 0 Normal, 1 Auto focusing
}ZZ_CFG_CAP_FOCUS_STATUS;















// PTZ Motion Range, Unit: Degree
typedef struct tagZZ_CFG_PTZ_MOTION_RANGE
{
	int                 nHorizontalAngleMin;       // Horizontal angle range min, unit: degree
	int                 nHorizontalAngleMax;       // Horizontal angle range max, unit: degree
	int                 nVerticalAngleMin;          // Vertical angle range min, unit: degree
	int                 nVerticalAngleMax;          // Vertical angle range max, unit: degree
}ZZ_CFG_PTZ_MOTION_RANGE;

// Supported Focus Mode Enum
typedef enum tagZZ_SUPPORT_FOCUS_MODE
{
    ENUM_ZZ_SUPPORT_FOCUS_CAR        = 1,                // Clear car mode         
	ENUM_ZZ_SUPPORT_FOCUS_PLATE      = 2,                // Clear plate mode 
	ENUM_ZZ_SUPPORT_FOCUS_PEOPLE     = 3,                // Clear people mode     
	ENUM_ZZ_SUPPORT_FOCUS_FACE       = 4,                // Clear face mode     
}EM_ZZ_SUPPORT_FOCUS_MODE;

// PTZ Lighting Control
typedef struct tagZZ_CFG_PTZ_LIGHTING_CONTROL
{
	char                szMode[ZZC_CFG_COMMON_STRING_32];  // Manual light control mode
	                                                   // "on-off": Direct switch mode,
	                                                   // "adjustLight": Manual brightness adjustment mode

	DWORD               dwNearLightNumber;             // Near light group number
	DWORD               dwFarLightNumber;              // Far light group number
}ZZ_CFG_PTZ_LIGHTING_CONTROL;

// PTZ Area Scan Capability
typedef struct tagZZ_CFG_PTZ_AREA_SCAN
{
	BOOL                bIsSupportAutoAreaScan;     // Whether auto area scan is supported	
	WORD				wScanNum;		    		// Number of area scans
}ZZ_CFG_PTZ_AREA_SCAN;

// Mask Shape Type
typedef enum tagZZNET_EM_MASK_TYPE
{
	ZZNET_EM_MASK_UNKNOWN,			// Unknown
	ZZNET_EM_MASK_RECT,				// Rectangle
	ZZNET_EM_MASK_POLYGON,			// Polygon
} ZZNET_EM_MASK_TYPE;

// Mosaic Type
typedef enum tagZZNET_EM_MOSAIC_TYPE
{
	ZZNET_EM_MOSAIC_UNKNOWN	= 0,				// Unknown
	ZZNET_EM_MOSAIC_8			= 8,				// [8x8 size] Mosaic
	ZZNET_EM_MOSAIC_16		= 16,				// [16x16 size] Mosaic
	ZZNET_EM_MOSAIC_24		= 24,				// [24x24 size] Mosaic
	ZZNET_EM_MOSAIC_32		= 32,				// [32x32 size] Mosaic
} ZZNET_EM_MOSAIC_TYPE;

#define ZZC_MAX_MASKTYPE_COUNT	8
#define ZZC_MAX_MOSAICTYPE_COUNT	8

// Privacy Masking Capability
typedef struct tagZZ_CFG_PTZ_PRIVACY_MASKING
{
	BOOL				bPrivacyMasking;					// Whether privacy masking is supported
	BOOL				bSetColorSupport;					// Whether mask color setting is supported
	BOOL				abMaskType;							// Whether emMaskType is valid
	int					nMaskTypeCount;						// Actual supported mask shape count
	ZZNET_EM_MASK_TYPE	emMaskType[ZZC_MAX_MASKTYPE_COUNT];		// Supported mask shapes, defaults to rectangle if no config
	BOOL				bSetMosaicSupport;					// Whether mosaic mask setting is supported
	BOOL				bSetColorIndependent;				// Whether mask colors are independent (Valid if bSetColorSupport is true)
	BOOL				abMosaicType;						// Whether emMosaicType is valid
	int					nMosaicTypeCount;					// Actual supported mosaic type count
	ZZNET_EM_MOSAIC_TYPE	emMosaicType[ZZC_MAX_MOSAICTYPE_COUNT];	// Supported mosaic types (Valid if SetMosaicSupport is true, defaults to 24x24 if no config)
} ZZ_CFG_PTZ_PRIVACY_MASKING;

// Image Distance Measurement Capability
typedef struct tagZZ_CFG_PTZ_MEASURE_DISTANCE
{
	BOOL				bSupport;							// Whether image distance measurement is supported
	BOOL				bOsdEnable;							// Whether to overlay measurement result to stream
	int					nDisplayMin;						// Min display time for measurement info, unit: seconds
	int					nDisplayMax;						// Max display time for measurement info, unit: seconds
} ZZ_CFG_PTZ_MEASURE_DISTANCE;

// Get PTZ Capability Info
typedef struct tagZZ_CFG_PTZ_PROTOCOL_CAPS_INFO
{
	int                 nStructSize;
    BOOL                bPan;                       // Support Pan
	BOOL                bTile;                      // Support Tilt
	BOOL                bZoom;                      // Support Zoom
	BOOL                bIris;                      // Support Iris adjustment
	BOOL                bPreset;                    // Support Preset
	BOOL                bRemovePreset;              // Support Remove Preset
	BOOL                bTour;                      // Support Tour
	BOOL                bRemoveTour;                // Support Remove Tour
	BOOL                bPattern;                   // Support Pattern
	BOOL                bAutoPan;                   // Support Auto Pan
	BOOL                bAutoScan;                  // Support Auto Scan
	BOOL                bAux;                       // Support Aux functions
	BOOL                bAlarm;                     // Support Alarm functions
	BOOL                bLight;                     // Support Light, details in "stuPtzLightingControl", field deprecated
	BOOL                bWiper;                     // Support Wiper
	BOOL                bFlip;                      // Support Lens Flip
	BOOL                bMenu;                      // Support Built-in Menu
	BOOL                bMoveRelatively;            // Support Relative Move
	BOOL                bMoveAbsolutely;            // Support Absolute Move
    BOOL                bMoveDirectly;              // Support 3D Positioning
	BOOL                bReset;                     // Support Reset
	BOOL                bGetStatus;                 // Support Get Status and Coordinates
	BOOL                bSupportLimit;              // Support Limit
	BOOL                bPtzDevice;                 // Support PTZ Device
	BOOL                bIsSupportViewRange;        // Support View Range

	WORD				wCamAddrMin;		    	// Camera Address Min
	WORD				wCamAddrMax;			    // Camera Address Max
	WORD				wMonAddrMin;    			// Monitor Address Min
	WORD				wMonAddrMax;	    		// Monitor Address Max
	WORD				wPresetMin;			    	// Preset Min
	WORD				wPresetMax;				    // Preset Max
	WORD				wTourMin;    				// Tour Min
	WORD				wTourMax;	    			// Tour Max
	WORD				wPatternMin;	    		// Pattern Min
	WORD				wPatternMax;		    	// Pattern Max
	WORD				wTileSpeedMin;			    // Tilt Speed Min
	WORD				wTileSpeedMax;    			// Tilt Speed Max
	WORD				wPanSpeedMin;	    		// Pan Speed Min
	WORD				wPanSpeedMax;		    	// Pan Speed Max
	WORD				wAutoScanMin;			    // Auto Scan Min
	WORD				wAutoScanMax;    			// Auto Scan Max
	WORD				wAuxMin;		    		// Aux Function Min
	WORD				wAuxMax;			    	// Aux Function Max

	DWORD				dwInterval;				    // Command interval
	DWORD				dwType;				        // Protocol type, 0-Local, 1-Remote
	DWORD				dwAlarmLen;				    // Alarm length
	DWORD				dwNearLightNumber;		    // Near light group count, 0~4, 0 means unsupported
	DWORD				dwFarLightNumber;		    // Far light group count, 0~4, 0 means unsupported

	DWORD               dwSupportViewRangeType;     // Supported view range data acquisition mask, low to high bits
	                                                // Bit 1: 1 means supports "ElectronicCompass"

	DWORD               dwSupportFocusMode;         // Supported focus mode mask, low to high, see #EM_SUPPORT_FOCUS_MODE
	                  
	char				szName[ZZC_MAX_PROTOCOL_NAME_LEN];                       // Protocol name
	char                szAuxs[ZZC_CFG_COMMON_STRING_32][ZZC_CFG_COMMON_STRING_32];  // Aux function name list

	ZZ_CFG_PTZ_MOTION_RANGE stuPtzMotionRange;         // PTZ motion range, unit: degree
	ZZ_CFG_PTZ_LIGHTING_CONTROL stuPtzLightingControl; // Light control content, deprecated
	BOOL				bSupportPresetTimeSection;	// Support preset time section config
    BOOL                bFocus;                     // Support Zoom/Focus
	ZZ_CFG_PTZ_AREA_SCAN	stuPtzAreaScan;				// Area scan capability
	ZZ_CFG_PTZ_PRIVACY_MASKING		stuPtzPrivacyMasking;	// Privacy masking capability
	ZZ_CFG_PTZ_MEASURE_DISTANCE	stuPtzMeasureDistance;	// Image distance measurement capability
	BOOL				bSupportPtzPatternOSD;		// Support PTZ pattern OSD overlay
	BOOL				bSupportPtzRS485DetectOSD;	// Support PTZ RS485 detect OSD overlay
	BOOL				bSupportPTZCoordinates;		// Support PTZ coordinates overlay
	BOOL				bSupportPTZZoom;			// Support PTZ zoom overlay
	BOOL				bDirectionDisplay;			// Support PTZ direction display
}ZZ_CFG_PTZ_PROTOCOL_CAPS_INFO;





///@brief Light Type
typedef enum tagEM_ZZ_CFG_LC_LIGHT_TYPE
{
	EM_ZZ_CFG_LC_LIGHT_TYPEUNKNOWN,						// Unknown
	EM_ZZ_CFG_LC_LIGHT_TYPE_INFRAREDLIGHT,					// Infrared light
	EM_ZZ_CFG_LC_LIGHT_TYPE_WIHTELIGHT,					// White light
	EM_ZZ_CFG_LC_LIGHT_TYPE_LASERLIGHT,					// Laser light
	EM_ZZ_CFG_LC_LIGHT_TYPE_AIMIXLIGHT,					// AI Mix light (Switch IR/White based on intelligent ID)
	EM_ZZ_CFG_LC_LIGHT_TYPE_PILOTLIGHT,					// Pilot/Indicator light
}EM_ZZ_CFG_LC_LIGHT_TYPE;

///@brief Light Mode
typedef enum tagEM_ZZ_CFG_LC_MODE
{
	EM_ZZ_CFG_LC_MODE_UNKNOWN,								// Unknown
	EM_ZZ_CFG_LC_MODE_MANUAL,								// Manual
	EM_ZZ_CFG_LC_MODE_ZOOMPRIO,							// Zoom priority
	EM_ZZ_CFG_LC_MODE_TIMING,								// Timing (Deprecated)
	EM_ZZ_CFG_LC_MODE_AUTO,								// Auto
	EM_ZZ_CFG_LC_MODE_OFF,									// Off
	EM_ZZ_CFG_LC_MODE_EXCLUSIVEMANUAL,						// Exclusive Manual (Deprecated)
	EM_ZZ_CFG_LC_MODE_SMARTLIGHT,							// Smart Light (Deprecated)
	EM_ZZ_CFG_LC_MODE_LINKING,								// Event Linkage (Deprecated)
	EM_ZZ_CFG_LC_MODE_DUSKTODAWN,							// Dusk to Dawn / Photosensitive
    EM_ZZ_CFG_LC_MODE_FORCEON,                             // Force On 
}EM_ZZ_CFG_LC_MODE;

#define ZZC_CFG_LC_LIGHT_COUNT 4			// Light count in group

///@brief Light Info
typedef struct tagZZNET_LIGHT_INFO
{
	int			nLight;						// Brightness percentage
	int			nAngle;						// Laser angle normalized value
}ZZNET_LIGHT_INFO;

///@brief Fill Light Sensitivity Config Unit
typedef struct tagZZ_CFG_LIGHTING_V2_UNIT
{
	EM_ZZ_CFG_LC_LIGHT_TYPE	emLightType;					// Light type
	EM_ZZ_CFG_LC_MODE	emMode;							// Light mode
	int					nCorrection;					// Light correction
	int					nSensitive;						// Light sensitivity
	int					nLightSwitchDelay;				// Light switch delay
	ZZNET_LIGHT_INFO	anNearLight[ZZC_CFG_LC_LIGHT_COUNT];	// Near light group info
	int					nNearLightLen;					// Near light group count
	ZZNET_LIGHT_INFO	anMiddleLight[ZZC_CFG_LC_LIGHT_COUNT];	// Middle light group info
	int					nMiddleLightLen;				// Middle light group count
	ZZNET_LIGHT_INFO	anFarLight[ZZC_CFG_LC_LIGHT_COUNT];		// Far light group info
	int					nFarLightLen;					// Far light group count
    UINT				nPercentOfMaxBrightness;			// Current white light limit relative to max brightness percentage 0~100
	int					nAIMixLightSwitchDelay;				// Effective in AI mix light scheme, delay for switching between IR and White light to prevent frequent switching, unit seconds, range 0-300, default 30s
    BYTE                byReserved[120];			    	// Reserved bytes
}ZZ_CFG_LIGHTING_V2_UNIT;

#define ZZC_LC_LIGHT_TYPE_NUM 3							/// Light type count
///@brief Day/Night Fill Light Sensitivity Config
typedef struct tagZZ_CFG_LIGHTING_V2_DAYNIGHT
{
	ZZ_CFG_LIGHTING_V2_UNIT		anLightInfo[ZZC_LC_LIGHT_TYPE_NUM];			// Light info per type
	int							nLightInfoLen;							// Light type count
}ZZ_CFG_LIGHTING_V2_DAYNIGHT;

#define ZZC_CFG_LC_LIGHT_CONFIG 8                               // Max Day/Night light config count
///@brief Fill Light Sensitivity Config
typedef struct tagZZ_CFG_LIGHTING_V2_INFO
{
	int							nChannel;					// Channel
    int                         nDNLightInfoNum;            // Day/Night light config number             
	ZZ_CFG_LIGHTING_V2_DAYNIGHT	anDNLightInfo[ZZC_CFG_LC_LIGHT_CONFIG];			// Day/Night light configs
                                                                            // Elements start from 0 representing: Day, Night, Normal, Front Light, General Backlight, Strong Backlight, Low Illumination, Custom
}ZZ_CFG_LIGHTING_V2_INFO;






//----------------------------------Video input front-end options-------------------------------------------

// Video input night special configuration options, automatically switch to night configuration when the light is dim at night
typedef struct tagZZ_CFG_VIDEO_IN_NIGHT_OPTIONS
{
    BYTE                bySwitchMode;           // Deprecated, use CFG_VIDEO_IN_OPTIONS's bySwitchMode
                                                // 0-No switching, always use daytime configuration; 1-Switch based on brightness; 2-Switch based on time; 3-No switching, always use night configuration; 4-Use normal configuration
    BYTE                byProfile;              // Current profile in use.
                                                // 0-Daytime
                                                // 1-Nighttime
                                                // 2-Normal
                                                // 0,1,2 are temporary configurations for image effectiveness and debugging. Not clicking OK will not save these settings to the device.
                                                // 3-Non-temporary configuration. Clicking OK saves to the device, combined with SwitchMode, which determines the final effective configuration.
                                                // SwitchMode=0, Profile=3, set daytime configuration to the device;
                                                // SwitchMode=1, Profile=3, set night configuration to the device;
                                                // SwitchMode=2, Profile=3, switch according to sunrise and sunset time periods, use daytime configuration during the day and night configuration at night, save to the device;
                                                // SwitchMode=4, Profile=3; use normal configuration, save to the device
    BYTE                byBrightnessThreshold ; // Brightness threshold 0~100   
    BYTE                bySunriseHour;          // Approximate sunrise and sunset times, after sunset and before sunrise, switch to night special configuration.
    BYTE                bySunriseMinute;        // 00:00:00 ~ 23:59:59
    BYTE                bySunriseSecond;
    BYTE                bySunsetHour;
    BYTE                bySunsetMinute;
    BYTE                bySunsetSecond;  
    BYTE                byGainRed;              // Red gain adjustment, effective in "Custom" white balance mode 0~100
    BYTE                byGainBlue;             // Green gain adjustment, effective in "Custom" white balance mode 0~100
    BYTE                byGainGreen;            // Blue gain adjustment, effective in "Custom" white balance mode 0~100
    BYTE                byExposure;             // Exposure mode; range depends on device capabilities: 0-Auto exposure, 1-Exposure level 1, 2-Exposure level 2... n-1 max exposure level n Time-bounded auto exposure n+1 Custom manual exposure (n==byExposureEn)
    float               fExposureValue1;        // Auto exposure lower limit or custom manual exposure time, in milliseconds, range 0.1ms~80ms
    float               fExposureValue2;        // Auto exposure upper limit, in milliseconds, range 0.1ms~80ms   
    BYTE                byWhiteBalance ;        // White balance, 0-"Disable", 1-"Auto", 2-"Custom", 3-"Sunny", 4-"Cloudy", 5-"Home", 6-"Office", 7-"Night", 8-"HighColorTemperature", 9-"LowColorTemperature", 10-"AutoColorTemperature", 11-"CustomColorTemperature"
    BYTE                byGain;                 // 0~100, when GainAuto is true it indicates the upper limit of auto gain, otherwise it indicates a fixed gain value
    bool                bGainAuto;              // Auto gain
    bool                bIrisAuto;              // Auto iris
    float               fExternalSyncPhase;     // External sync phase setting 0~360
    BYTE                byGainMin;              // Gain lower limit
    BYTE                byGainMax;              // Gain upper limit
    BYTE                byBacklight;            // Backlight compensation: range depends on device capabilities: 0-Off 1-On 2-Specified area backlight compensation
    BYTE                byAntiFlicker;          // Anti-flicker mode 0-Outdoor 1-50Hz anti-flicker 2-60Hz anti-flicker
    BYTE                byDayNightColor;        // Day/Night mode; 0-Always color, 1-Auto switch based on brightness, 2-Always black and white
    BYTE                byExposureMode;         // Exposure mode adjustment, valid when exposure level is auto exposure, values: 0-Default auto, 1-Gain priority, 2-Shutter priority
    BYTE                byRotate90;             // 0-No rotation, 1-Clockwise 90°, 2-Counterclockwise 90°
    bool                bMirror;                // Mirror
    BYTE                byWideDynamicRange;     // Wide dynamic range value 0-Off, 1~100-Real range value
    BYTE                byGlareInhibition;      // Glare inhibition 0-Off, 1~100 Range value
    ZZ_CFG_RECT         stuBacklightRegion;     // Backlight compensation region
    BYTE                byFocusMode;            // 0-Off, 1-Assist focus, 2-Auto focus
    bool                bFlip;                  // Flip
    BYTE                reserved[74];           // Reserved
} ZZ_CFG_VIDEO_IN_NIGHT_OPTIONS;

typedef struct tagZZ_CFG_VIDEO_IN_NORMAL_OPTIONS
{
	BYTE                byGainRed;              // Red gain adjustment, effective in "Custom" white balance mode 0~100
	BYTE                byGainBlue;             // Green gain adjustment, effective in "Custom" white balance mode 0~100
	BYTE                byGainGreen;            // Blue gain adjustment, effective in "Custom" white balance mode 0~100
	BYTE                byExposure;             // Exposure mode; range depends on device capabilities: 0-Auto exposure, 1-Exposure level 1, 2-Exposure level 2... n-1 max exposure level n Time-bounded auto exposure n+1 Custom manual exposure (n==byExposureEn)
	float               fExposureValue1;        // Auto exposure lower limit or custom manual exposure time, in milliseconds, range 0.1ms~80ms
	float               fExposureValue2;        // Auto exposure upper limit, in milliseconds, range 0.1ms~80ms   
	BYTE                byWhiteBalance ;        // White balance, 0-"Disable", 1-"Auto", 2-"Custom", 3-"Sunny", 4-"Cloudy", 5-"Home", 6-"Office", 7-"Night", 8-"HighColorTemperature", 9-"LowColorTemperature", 10-"AutoColorTemperature", 11-"CustomColorTemperature"
	BYTE                byGain;                 // 0~100, when GainAuto is true it indicates the upper limit of auto gain, otherwise it indicates a fixed gain value
	bool                bGainAuto;              // Auto gain
	bool                bIrisAuto;              // Auto iris
	float               fExternalSyncPhase;     // External sync phase setting 0~360
	BYTE                byGainMin;              // Gain lower limit
	BYTE                byGainMax;              // Gain upper limit
	BYTE                byBacklight;            // Backlight compensation: range depends on device capabilities: 0-Off 1-On 2-Specified area backlight compensation
	BYTE                byAntiFlicker;          // Anti-flicker mode 0-Outdoor 1-50Hz anti-flicker 2-60Hz anti-flicker
	BYTE                byDayNightColor;        // Day/Night mode; 0-Always color, 1-Auto switch based on brightness, 2-Always black and white
	BYTE                byExposureMode;         // Exposure mode adjustment, valid when exposure level is auto exposure, values: 0-Default auto, 1-Gain priority, 2-Shutter priority
	BYTE                byRotate90;             // 0-No rotation, 1-Clockwise 90°, 2-Counterclockwise 90°
	bool                bMirror;                // Mirror
	BYTE                byWideDynamicRange;     // Wide dynamic range value 0-Off, 1~100-Real range value
	BYTE                byGlareInhibition;      // Glare inhibition 0-Off, 1~100 Range value
	ZZ_CFG_RECT         stuBacklightRegion;     // Backlight compensation region
	BYTE                byFocusMode;            // 0-Off, 1-Assist focus, 2-Auto focus
	bool                bFlip;                  // Flip
	BYTE                reserved[74];           // Reserved
}ZZ_CFG_VIDEO_IN_NORMAL_OPTIONS;

typedef struct tagZZ_CFG_FLASH_CONTROL
{
    BYTE                byMode;                 // Operating mode, 0-Disable flash, 1-Always flash, 2-Auto flash
    BYTE                byValue;                // Operating value, 0-0us, 1-64us, 2-128us, 3-192...15-960us
    BYTE                byPole;                 // Trigger mode, 0-Low level 1-High level 2-Rising edge 3-Falling edge
    BYTE                byPreValue;             // Brightness preset value  Range 0~100
    BYTE                byDutyCycle;            // Duty cycle, 0~100
    BYTE                byFreqMultiple;         // Frequency multiple, 0~10
    BYTE                reserved[122];          // Reserved
}ZZ_CFG_FLASH_CONTROL;

// Snapshot parameter special configuration
typedef struct tagZZ_CFG_VIDEO_IN_SNAPSHOT_OPTIONS
{
    BYTE                byGainRed;              // Red gain adjustment, effective in "Custom" white balance mode 0~100
    BYTE                byGainBlue;             // Green gain adjustment, effective in "Custom" white balance mode 0~100
    BYTE                byGainGreen;            // Blue gain adjustment, effective in "Custom" white balance mode 0~100
    BYTE                byExposure;             // Exposure mode; range depends on device capabilities: 0-Auto exposure, 1-Exposure level 1, 2-Exposure level 2... n-1 max exposure level n Time-bounded auto exposure n+1 Custom manual exposure (n==byExposureEn)
    float               fExposureValue1;        // Auto exposure lower limit or custom manual exposure time, in milliseconds, range 0.1ms~80ms
    float               fExposureValue2;        // Auto exposure upper limit, in milliseconds, range 0.1ms~80ms   
    BYTE                byWhiteBalance;         // White balance, 0-"Disable", 1-"Auto", 2-"Custom", 3-"Sunny", 4-"Cloudy", 5-"Home", 6-"Office", 7-"Night", 8-"HighColorTemperature", 9-"LowColorTemperature", 10-"AutoColorTemperature", 11-"CustomColorTemperature"
    BYTE                byColorTemperature;     // Color temperature level, effective in "CustomColorTemperature" white balance mode
    bool                bGainAuto;              // Auto gain
    BYTE                byGain;                 // Gain adjustment, when GainAuto is true it indicates the upper limit of auto gain, otherwise it indicates a fixed gain value
    BYTE                reversed[112];          // Reserved
} ZZ_CFG_VIDEO_IN_SNAPSHOT_OPTIONS;

// Fisheye lens configuration
typedef enum tagZZ_CFG_CALIBRATE_MODE
{
    ZZ_CFG_CALIBRATE_MODE_UNKOWN,                  // Unknown mode 
    ZZ_CFG_CALIBRATE_MODE_ORIGIAL,                 // Original image mode
    ZZ_CFG_CALIBRATE_MODE_CONFIG,                  // Configuration mode
    ZZ_CFG_CALIBRATE_MODE_PANORAMA,                // Panoramic mode
    ZZ_CFG_CALIBRATE_MODE_DOUBLEPANORAMA,          // Double panoramic mode
    ZZ_CFG_CALIBRATE_MODE_ORIGIALPLUSTHREEEPTZREGION, // 1+3 mode (one original fisheye image plus 3 EPtz images)
    ZZ_CFG_CALIBRATE_MODE_SINGLE,                  // Single EPtz mode (only one EPtz image)
    ZZ_CFG_CALIBRATE_MODE_FOUREPTZREGION,          // 4-image mode (4 EPtz control images)
    ZZ_CFG_CALIBRATE_MODE_NORMAL,                  // Normal mode
}ZZ_CFG_CALIBRATE_MODE;

// Fisheye lens configuration
typedef struct tagZZ_CFG_FISH_EYE
{
    ZZ_CFG_POLYGON      stuCenterPoint;         // Fisheye center coordinates, range [0,8192]
    unsigned int        nRadius;                // Fisheye radius size, range [0,8192]
    float               fDirection;             // Lens rotation direction, rotation angle [0,360.0]
    BYTE                byPlaceHolder;          // Lens installation method 1-ceiling mount, 2-wall mount; 3-ground mount, default 1
    BYTE                byCalibrateMode;        // Fisheye calibration mode, see CFG_CALIBRATE_MODE enumeration values
    BYTE                reversed[31];           // Reserved
}ZZ_CFG_FISH_EYE;

// Video input frontend options
typedef struct tagZZ_CFG_VIDEO_IN_OPTIONS
{
    BYTE                byBacklight;            // Backlight compensation: range depends on device capabilities: 0-Off 1-On 2-Specified area backlight compensation
    BYTE                byDayNightColor;        // Day/Night mode; 0-Always color, 1-Auto switch based on brightness, 2-Always black and white
    BYTE                byWhiteBalance;         // White balance, 0-"Disable", 1-"Auto", 2-"Custom", 3-"Sunny", 4-"Cloudy", 5-"Home", 6-"Office", 7-"Night", 8-"HighColorTemperature", 9-"LowColorTemperature", 10-"AutoColorTemperature", 11-"CustomColorTemperature"
    BYTE                byColorTemperature;     // Color temperature level, effective in "CustomColorTemperature" white balance mode
    bool                bMirror;                // Mirror
    bool                bFlip;                  // Flip
    bool                bIrisAuto;              // Auto iris
    bool                bInfraRed;              // Automatically turn on infrared compensation lamp based on ambient light
    BYTE                byGainRed;              // Red gain adjustment, effective in "Custom" white balance mode 0~100
    BYTE                byGainBlue;             // Green gain adjustment, effective in "Custom" white balance mode 0~100
    BYTE                byGainGreen;            // Blue gain adjustment, effective in "Custom" white balance mode 0~100
    BYTE                byExposure;             // Exposure mode; range depends on device capabilities: 0-Auto exposure, 1-Exposure level 1, 2-Exposure level 2... n-1 max exposure level n Time-bounded auto exposure n+1 Custom manual exposure (n==byExposureEn)
    float               fExposureValue1;        // Auto exposure lower limit or custom manual exposure time, in milliseconds, range 0.1ms~80ms
    float               fExposureValue2;        // Auto exposure upper limit, in milliseconds, range 0.1ms~80ms   
    bool                bGainAuto;              // Auto gain
    BYTE                byGain;                 // Gain adjustment, when GainAuto is true it indicates the upper limit of auto gain, otherwise it indicates a fixed gain value
    BYTE                bySignalFormat;         // Signal format, 0-Inside(internal input) 1-BT656 2-720p 3-1080p  4-1080i  5-1080sF
    BYTE                byRotate90;             // 0-No rotation, 1-Clockwise 90°, 2-Counterclockwise 90°  
    float               fExternalSyncPhase;     // External sync phase setting 0~360   
    BYTE                byExternalSync;         // External sync signal input, 0-Internal sync 1-External sync
    BYTE                bySwitchMode;           // 0-No switching, always use daytime configuration; 1-Switch based on brightness; 2-Switch based on time; 3-No switching, always use night configuration; 4-Use normal configuration
    BYTE                byDoubleExposure;       // Dual shutter, 0-Not enabled, 1-Dual shutter full frame rate, i.e., only the shutter parameters differ between image and video, 2-Dual shutter half frame rate, i.e., both the shutter and white balance parameters differ between image and video
    BYTE                byWideDynamicRange;     // Wide dynamic range value
    ZZ_CFG_VIDEO_IN_NIGHT_OPTIONS stuNightOptions;   // Night parameters
    ZZ_CFG_FLASH_CONTROL    stuFlash;               // Flash configuration
    ZZ_CFG_VIDEO_IN_SNAPSHOT_OPTIONS stuSnapshot;   // Snapshot parameters, valid in dual shutter mode
    ZZ_CFG_FISH_EYE        stuFishEye;             // Fisheye lens
    BYTE                byFocusMode;            // 0-Off, 1-Assist focus, 2-Auto focus
    BYTE                reserved[28];           // Reserved
    BYTE                byGainMin;              // Gain lower limit
    BYTE                byGainMax;              // Gain upper limit
    BYTE                byAntiFlicker;          // Anti-flicker mode 0-Outdoor 1-50Hz anti-flicker 2-60Hz anti-flicker
    BYTE                byExposureMode;         // Exposure mode adjustment, valid when exposure level is auto exposure, values: 0-Default auto, 1-Gain priority, 2-Shutter priority, 4-Manual
    BYTE                byGlareInhibition;      // Glare inhibition 0-Off, 1~100 Range value
    ZZ_CFG_RECT         stuBacklightRegion;     // Backlight compensation region            
    ZZ_CFG_VIDEO_IN_NORMAL_OPTIONS stuNormalOptions; // Normal parameters
} ZZ_CFG_VIDEO_IN_OPTIONS;