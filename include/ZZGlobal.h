#pragma once

#include <cstdint>



#if !defined(LONG)
    #if defined(_WIN32) || defined(_WIN64)
        typedef long LONG;
    #else
        typedef int  LONG;
    #endif
#endif

// Cross-platform dynamic library export macro
#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #ifdef ZZNETSDK_EXPORTS
        #define ZZNETSDK_API __declspec(dllexport)
    #else
        #define ZZNETSDK_API __declspec(dllimport)
    #endif

    #ifndef LLONG
        #ifdef _WIN64
            typedef int64_t LLONG;
        #else 
            typedef int32_t LLONG;  // Explicitly specify 32-bit
        #endif
    #endif

    #ifndef LDWORD
        #ifdef _WIN64
            #define LDWORD  int64_t
        #else 
            #define LDWORD  DWORD
        #endif
    #endif

    typedef int  BOOL;
    #define CALLBACK        __stdcall
    #define CALL_METHOD     __stdcall  //__cdecl
#else
    #define ZZNETSDK_API extern "C"
    #define CALL_METHOD 
    #define CALLBACK
	#define LPVOID      void*
    
    #ifndef LLONG
        typedef long LLONG;
    #endif

    #ifndef LDWORD
        typedef long LDWORD;
    #endif
    typedef int  BOOL;

    #ifndef DWORD
    typedef uint32_t DWORD;
    #endif

	#ifndef MAX_PATH
	#define MAX_PATH    260
	#endif

    #ifndef NULL
    #define NULL        0
    #endif

    #define BYTE        unsigned char
    #define UINT        unsigned int
    #define WORD        unsigned short
    #define HWND        void*
    #define LPVOID      void*
    #define INT64       long long
    #define LDWORD      long 
    #define LPDWORD     DWORD*

#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif








/************************************************************************
 ** Constant definitions
 ***********************************************************************/

#define ZZ_SERIALNO_LEN                   48               // Device serial number character length
#define ZZ_MAX_DISKNUM                    256              // Maximum number of hard disks
#define ZZ_MAX_SDCARDNUM                  32               // Maximum number of SD cards
#define ZZ_MAX_BURNING_DEV_NUM            32               // Maximum number of burning devices
#define ZZ_BURNING_DEV_NAMELEN            32               // Maximum length of burning device name
#define ZZ_MAX_LINK                       6                
#define ZZ_MAX_CHANNUM                    16               // Maximum number of channels
#define ZZ_MAX_DECODER_CHANNUM            64               // Maximum number of decoder channels
#define ZZ_MAX_ALARMIN                    128              // Maximum number of alarm inputs
#define ZZ_MAX_ALARMOUT                   64               // Maximum number of alarm outputs
#define ZZ_MAX_RIGHT_NUM                  100              // Upper limit of user permissions
#define ZZ_MAX_GROUP_NUM                  20               // Upper limit of user groups
#define ZZ_MAX_USER_NUM                   200              // Upper limit of users
#define ZZ_RIGHT_NAME_LENGTH              32               // Permission name length
#define ZZ_USER_NAME_LENGTH               8                // Username length
#define ZZ_USER_PSW_LENGTH                8                // User password length
#define ZZ_CUSTOM_NAME_LENGTH             32               // Custom name length
#define ZZ_USER_NAME_LEN_EX               32               // Username length, for new platform extension
#define ZZ_USER_PSW_LEN_EX                32               // User password length, for new platform extension
#define ZZ_MEMO_LENGTH                    32               // Memo length
#define ZZ_MAX_STRING_LEN                 128              
#define ZZ_MAX_STRING_LINE_LEN            6                // Maximum of six lines
#define ZZ_MAX_PER_STRING_LEN             20               // Maximum length per line
#define ZZ_MAX_MAIL_NAME_LEN              64               // New email structure supported username length
#define ZZ_MAX_MAIL_PSW_LEN               64               // New email structure supported password length
#define ZZ_SPEEDLIMIT_TYPE_LEN            32               // Speed limit type string length
#define ZZ_VEHICLE_TYPE_LEN               32               // Vehicle custom information type string length
#define ZZ_VEHICLE_INFO_LEN               32               // Vehicle custom information string length
#define ZZ_VEHICLE_DRIVERNO_LEN           32               // Vehicle custom information driver number string length
#define ZZ_MAX_CROSSING_NUM               128              // Maximum number of crossing points
#define ZZ_MAX_CROSSING_ID                32               // Maximum length of crossing serial number
#define ZZ_MAX_CARD_INFO_LEN              256              // Maximum length of card information
#define ZZ_MAX_CHANNUM_EX                 32               // Maximum number of channels extended  
#define ZZ_MAX_SAERCH_IP_NUM              256              // Maximum number of search IPs
#define ZZ_MAX_HARDDISK_TYPE_LEN          32               // Maximum length of hard disk model
#define ZZ_MAX_HARDDISK_SERIAL_LEN        32               // Maximum length of hard disk serial number
#define ZZ_MAX_SIM_LEN                    16               // Maximum length of SIM card value
#define ZZ_MAX_SIM_NUM                    10               // Maximum number of vehicle SIM cards
#define ZZ_MAX_VERSION_LEN                32               // Maximum length of software version
#define ZZ_MAX_MDN_LEN                    36               // Maximum length of MDN value
#define ZZ_MAX_NETINTERFACE_NUM           64               // Supported number of network cards
#define ZZ_EVENT_NAME_LEN                 128              // Event name length
#define ZZ_STORAGE_NAME_LEN               128              // Storage device name length
#define ZZ_MAX_CARPORTLIGHT_NUM           4                // Maximum number of carport lights
#define ZZ_STATION_NAME_LEN               32               // Station name length   
#define ZZ_PTZ_PRESET_NAME_LEN            64               // PTZ preset name length
#define ZZ_MAX_GUARD_DETECT_ID_COUNT      64               // Maximum number of guard detection IDs
#define ZZ_MAX_VERSION_STR                64               // Maximum length of version string
#define ZZ_MAX_AUDIO_MATRIX_OUTPUT        8                // Maximum number of output channels supported by each audio matrix
#define ZZ_MAX_CHANNEL_COUNT              16               // Supported maximum number of channel overlays
#define ZZ_COMMON_STRING_4                4                // Common string length 4
#define ZZ_COMMON_STRING_8                8                // Common string length 8
#define ZZ_COMMON_STRING_16               16               // Common string length 16
#define ZZ_COMMON_STRING_32               32               // Common string length 32
#define ZZ_COMMON_STRING_64               64               // Common string length 64
#define ZZ_COMMON_STRING_128              128              // Common string length 128
#define ZZ_COMMON_STRING_256              256              // Common string length 256
#define ZZ_COMMON_STRING_512              512              // Common string length 512
#define ZZ_COMMON_STRING_1024             1024             // Common string length 1024
#define ZZ_COMMON_STRING_2048             2048             // Common string length 2048
#define ZZ_MAX_ACCESS_NAME_LEN            64               // Access control name length
#define ZZ_MAX_EXALARMCHANNEL_NAME_LEN    128              // Extended module alarm channel name length
#define ZZ_MAX_ALARM_SUBSYSTEM_NUM        256              // Maximum number of alarm subsystems
#define ZZ_MAX_BELL_NUM                   4                // Maximum number of bells
#define ZZ_MAX_KEYBOARD_NUM               256              // Maximum number of keyboards
#define ZZ_MAX_GOURP_NUM                  128              // Maximum number of face libraries
#define ZZ_MAX_POS_EXCHANGE_INFO          64               // Maximum value of POS transaction information array when querying POS transaction information each time
#define ZZNET_INTERFACE_DEFAULT_TIMEOUT   3000             // Default interface timeout
#define ZZ_MAX_BUSCARD_NUM                64               // Maximum length of bus card number
#define ZZ_MAX_POS_MAC_NUM                8                // Maximum length of card reader Mac code
#define ZZ_MAX_MARK_FILE_NAME_LEN         124              // Maximum length of recording control file name
#define ZZNET_MAX_ATTACHMENT_NUM          8                // Maximum number of vehicle objects
#define ZZNET_MAX_ANNUUALINSPECTION_NUM   8                // Maximum number of annual inspection identification positions
#define ZZNET_MAX_EVENT_PIC_NUM           6                // Maximum number of original pictures
#define ZZNET_MAX_MONTH_NUM               31               // Maximum number of months
#define ZZNET_IPADDRSTR_LEN               46               // IP address string length supporting ipv4-mapped-on-ipv6 
#define ZZNET_MAX_AP_NUM                  3                // Maximum number of APs
#define ZZ_MAX_WEP_KEY_NUM                4                // Maximum number of WEP passwords
#define ZZ_MAX_CARNO_LEN                  20               // Maximum vehicle number length
#define ZZ_MAX_COACHNO_LEN                12               // Maximum coach number length
#define ZZ_MAX_WORKPATTERN_NUM            2                // Maximum number of working modes
#define ZZ_MAX_NETPORT_NUM				  5				   // Maximum number of network ports
#define ZZ_MAX_ANTIFLICKERMODE_COUNT      8                // Maximum number of anti-flicker modes
#define ZZ_MAX_CATEGORY_LEN               64               // Maximum object type length
#define ZZ_MAX_DANGER_GRADE_NUM			  8				   // Maximum number of package danger levels
#define ZZ_MAX_INSIDE_OBJECT_TYPE_NUM     32			   // Maximum number of item types in packages
#define ZZ_MAX_PATH_LEN					  260			   // Maximum path length	
#define ZZ_MAX_XRAY_CHANNEL_NUM			  10			   // Maximum number of channels for X-ray package quantity statistics information
#define ZZ_MAX_HISTORY_TEMPERATURE_NUM	  64		       // Maximum number of historical temperature values
#define ZZ_MAX_TEMPERATURE_POINT_NUM	  8				   // Maximum number of monitored temperature points
#define ZZ_MAX_GROUP_LEN				  128			   // Maximum group name length
#define ZZ_MAX_ILLEGAL_LOGIN_IP_LEN		  40			   // Maximum illegal login IP length
#define ZZ_MAX_EVENT_LONGID_LEN			  52			   // Maximum length of event long ID
#define ZZ_MAX_HUMANTRAIT_EVENT_LEN		  36			   // Maximum length of reported human trait events

// Remote configuration structure related constants                 
#define ZZ_MAX_MAIL_ADDR_LEN              128              // Maximum length of email send(receive) address
#define ZZ_MAX_MAIL_SUBJECT_LEN           64               // Maximum length of email subject
#define ZZ_MAX_IPADDR_LEN                 16               // IP address string length
#define ZZ_MAX_IPADDR_LEN_EX              40               // Extended IP address string length, supporting IPV6
#define ZZ_MACADDR_LEN                    40               // MAC address string length
#define ZZ_MAX_URL_LEN                    128              // URL string length
#define ZZ_MAX_DEV_ID_LEN                 48               // Max device ID length
#define ZZ_MAX_HOST_NAMELEN               64               // Hostname length,
#define ZZ_MAX_HOST_PSWLEN                32               // Password length
#define ZZ_MAX_NAME_LEN                   16               // Common name string length
#define ZZ_MAX_ETHERNET_NUM               2                // Max ethernet port count
#define ZZ_MAX_ETHERNET_NUM_EX            10               // Max extended ethernet port count
#define ZZ_DEV_SERIALNO_LEN               48               // Serial number string length
#define ZZ_DEV_CLASS_LEN                  16               // Device type string (e.g., "IPC") length
#define ZZ_DEV_TYPE_LEN                   32               // Device model string (e.g., "IPC-F725") length
#define ZZ_N_WEEKS                        7                // Days in a week    
#define ZZ_N_TSECT                        6                // Number of common time sections
#define ZZ_N_REC_TSECT                    6                // Number of recording time sections
#define ZZ_N_COL_TSECT                    2                // Number of color time sections    
#define ZZ_CHAN_NAME_LEN                  32               // Channel name length, DVR DSP capability limit, max 32 bytes        
#define ZZ_N_ENCODE_AUX                   3                // Number of extra streams    
#define ZZ_N_TALK                         1                // Max number of talk channels
#define ZZ_N_COVERS                       1                // Number of cover regions    
#define ZZ_N_CHANNEL                      16               // Max number of channels    
#define ZZ_N_ALARM_TSECT                  2                // Number of alarm prompt time sections
#define ZZ_MAX_ALARMOUT_NUM               16               // Max alarm output port limit
#define ZZ_MAX_AUDIO_IN_NUM               16               // Max audio input port limit
#define ZZ_MAX_VIDEO_IN_NUM               16               // Max video input port limit
#define ZZ_MAX_ALARM_IN_NUM               16               // Max alarm input port limit
#define ZZ_MAX_DISK_NUM                   16               // Max hard disk limit, set to 16 temporarily
#define ZZ_MAX_DECODER_NUM                16               // Max decoder (485) limit    
#define ZZ_MAX_232FUNCS                   10               // Max 232 serial port functions limit
#define ZZ_MAX_232_NUM                    2                // Max 232 serial port limit
#define ZZ_MAX_232_NUM_EX                 16               // Max extended serial port config limit          
#define ZZ_MAX_DECPRO_LIST_SIZE           100              // Max decoder protocol list size
#define ZZ_FTP_MAXDIRLEN                  240              // Max FTP directory length
#define ZZ_MATRIX_MAXOUT                  16               // Max matrix output ports                                             
#define ZZ_TOUR_GROUP_NUM                 6                // Max matrix output groups
#define ZZ_MAX_DDNS_NUM                   10               // Max supported DDNS servers
#define ZZ_MAX_SERVER_TYPE_LEN            32               // DDNS server type, max string length
#define ZZ_MAX_DOMAIN_NAME_LEN            256              // DDNS domain name, max string length
#define ZZ_MAX_DDNS_ALIAS_LEN             32               // DDNS server alias, max string length
#define ZZ_MAX_DEFAULT_DOMAIN_LEN         60               // DDNS default domain, max string length     
#define ZZ_MOTION_ROW                     32               // Rows for motion detection area
#define ZZ_MOTION_COL                     32               // Columns for motion detection area
#define ZZ_STATIC_ROW                     32               // Rows for static detection area
#define ZZ_STATIC_COL                     32               // Columns for static detection area
#define ZZ_FTP_USERNAME_LEN               64               // FTP config, max username length
#define ZZ_FTP_PASSWORD_LEN               64               // FTP config, max password length
#define ZZ_TIME_SECTION                   2                // FTP config, time sections per day
#define ZZ_FTP_MAX_PATH                   240              // FTP config, max file path length
#define ZZ_FTP_MAX_SUB_PATH               128              // FTP config, max file path length
#define ZZ_INTERVIDEO_UCOM_CHANID         32               // Platform access config, UCOM channel ID
#define ZZ_INTERVIDEO_UCOM_DEVID          32               // Platform access config, UCOM device ID
#define ZZ_INTERVIDEO_UCOM_REGPSW         16               // Platform access config, UCOM register password
#define ZZ_INTERVIDEO_UCOM_USERNAME       32               // Platform access config, UCOM username
#define ZZ_INTERVIDEO_UCOM_USERPSW        32               // Platform access config, UCOM password
#define ZZ_INTERVIDEO_NSS_IP              32               // Platform access config, ZNV IP
#define ZZ_INTERVIDEO_NSS_SERIAL          32               // Platform access config, ZNV serial
#define ZZ_INTERVIDEO_NSS_USER            32               // Platform access config, ZNV user
#define ZZ_INTERVIDEO_NSS_PWD             50               // Platform access config, ZNV password
#define ZZ_MAX_VIDEO_COVER_NUM            16               // Max cover regions
#define ZZ_MAX_WATERMAKE_DATA             4096             // Max watermark image data length
#define ZZ_MAX_WATERMAKE_LETTER           128              // Max watermark text length
#define ZZ_MAX_WLANDEVICE_NUM             10               // Max searched wireless devices
#define ZZ_MAX_WLANDEVICE_NUM_EX          32               // Max searched wireless devices
#define ZZ_MAX_ALARM_NAME                 64               // Address length
#define ZZ_MAX_REGISTER_SERVER_NUM        10               // Number of active registration servers
#define ZZ_SNIFFER_FRAMEID_NUM            6                // 6 FRAME ID options
#define ZZ_SNIFFER_CONTENT_NUM            4                // 4 capture contents per FRAME
#define ZZ_SNIFFER_CONTENT_NUM_EX         8                // 8 capture contents per FRAME
#define ZZ_SNIFFER_PROTOCOL_SIZE          20               // Protocol name length
#define ZZ_MAX_PROTOCOL_NAME_LENGTH       20               
#define ZZ_SNIFFER_GROUP_NUM              4                // 4 groups of packet capture settings
#define ZZ_MAX_PATH_STOR                  240              // Remote directory length
#define ZZ_ALARM_OCCUR_TIME_LEN           40               // New alarm upload time length
#define ZZ_VIDEO_OSD_NAME_NUM             64               // Overlay name length, currently supports 32 English, 16 Chinese
#define ZZ_VIDEO_CUSTOM_OSD_NUM           8                // Number of supported custom overlays, excluding time and channel
#define ZZ_VIDEO_CUSTOM_OSD_NUM_EX        256              // Number of supported custom overlays, excluding time and channel
#define ZZ_CONTROL_AUTO_REGISTER_NUM      100              // Number of supported directed active registration servers
#define ZZ_MMS_RECEIVER_NUM               100              // Number of supported SMS receivers
#define ZZ_MMS_SMSACTIVATION_NUM          100              // Number of supported SMS senders
#define ZZ_MMS_DIALINACTIVATION_NUM       100              // Number of supported dial-up senders
#define ZZ_MAX_ALARMOUT_NUM_EX            32               // Extended max alarm output ports
#define ZZ_MAX_VIDEO_IN_NUM_EX            32               // Extended max video input ports
#define ZZ_MAX_ALARM_IN_NUM_EX            32               // Extended max alarm input ports
#define ZZ_MAX_IPADDR_OR_DOMAIN_LEN       64               // IP address string length
#define ZZ_MAX_CALLID                     32               // Call ID
#define ZZ_MAX_OBJECT_LIST                16               // Max detected object IDs for intelligent analysis device    
#define ZZ_MAX_RULE_LIST                  16               // Max rules for intelligent analysis device
#define ZZ_MAX_POLYGON_NUM                16               // Max polygon vertices
#define ZZ_MAX_DETECT_LINE_NUM            20               // Max rule detection line vertices
#define ZZ_MAX_DETECT_REGION_NUM          20               // Max rule detection region vertices
#define ZZ_MAX_CARGO_CHANNEL_NUM		  8				   // Max cargo channel number
#define ZZ_MAX_TRACK_LINE_NUM             20               // Max object tracking trajectory vertices
#define ZZ_MAX_CANDIDATE_NUM              50               // Max face recognition matches
#define ZZ_MAX_PERSON_IMAGE_NUM           48               // Max face images per person
#define ZZ_MAX_FENCE_LINE_NUM             2                // Max fence lines
#define ZZ_MAX_SMART_VALUE_NUM            30               // Max smart info count
#define ZZ_MACHINE_NAME_NUM               64               // Machine name length
#define ZZ_INTERVIDEO_AMP_DEVICESERIAL    48               // Platform access config, TDS Device Serial string length
#define ZZ_INTERVIDEO_AMP_DEVICENAME      16               // Platform access config, TDS Device Name string length
#define ZZ_INTERVIDEO_AMP_USER            32               // Platform access config, TDS Register Username string length
#define ZZ_INTERVIDEO_AMP_PWD             32               // Platform access config, TDS Register Password string length
#define ZZ_MAX_SUBMODULE_NUM              32               // Max submodule info count
#define ZZ_MAX_CARWAY_NUM                 8                // Traffic snapshot, max lanes
#define ZZ_MAX_SNAP_SIGNAL_NUM            3                // Max snapshots per lane
#define ZZ_MAX_CARD_NUM                   128              // Max card numbers
#define ZZ_MAX_CARDINFO_LEN               32               // Max characters per card number
#define ZZ_MAX_CONTROLER_NUM              64               // Max supported controllers
#define ZZ_MAX_LIGHT_NUM                  32               // Max control light groups
#define ZZ_MAX_SNMP_COMMON_LEN            64               // SNMP read/write data length
#define ZZ_MAX_DDNS_STATE_LEN             128              // DDNS status info length
#define ZZ_MAX_PHONE_NO_LEN               16               // Phone number length
#define ZZ_MAX_MSGTYPE_LEN                32               // Navigation type or SMS type length
#define ZZ_MAX_MSG_LEN                    256              // Navigation and SMS length
#define ZZ_MAX_DRIVINGDIRECTION           256              // Driving direction string length
#define ZZ_MAX_GRAB_INTERVAL_NUM          4                // Multi-image snapshot count
#define ZZ_MAX_FLASH_NUM                  5                // Max supported flashlights
#define ZZ_MAX_LANE_NUM                   8                // Max lanes per channel for video analysis device
#define ZZ_MAX_ISCSI_PATH_NUM             64               // Max ISCSI remote paths
#define ZZ_MAX_WIRELESS_CHN_NUM           256              // Max wireless router channels
#define ZZ_PROTOCOL3_BASE                 100              // 3rd Gen protocol version base
#define ZZ_PROTOCOL3_SUPPORT              11               // Supports only 3rd Gen protocol
#define ZZ_MAX_CHANMASK                   64               // Max channel mask value
#define ZZ_MAX_STAFF_NUM                  20               // Max rulers in synopsis video config
#define ZZ_MAX_CALIBRATEBOX_NUM           10               // Max calibration boxes in synopsis video config
#define ZZ_MAX_EXCLUDEREGION_NUM          10               // Max excluded regions in synopsis video config
#define ZZ_MAX_POLYLINE_NUM               20               // Max ruler lines in synopsis video config
#define ZZ_MAX_COLOR_NUM                  16               // Max colors
#define ZZ_MAX_OBJFILTER_NUM              16               // Max filter types
#define ZZ_MAX_SYNOPSIS_STATE_NAME        64               // Video synopsis status string length
#define ZZ_MAX_SYNOPSIS_QUERY_FILE_COUNT  10               // Max files when querying synopsis related original files by path
#define ZZ_MAX_SSID_LEN                   36               // SSID length
#define ZZ_MAX_APPIN_LEN                  16               // PIN code length
#define ZZ_NETINTERFACE_NAME_LEN          260              // Network interface name length
#define ZZ_NETINTERFACE_TYPE_LEN          260              // Network type length
#define ZZ_MAX_CONNECT_STATUS_LEN         260              // Connection status string length
#define ZZ_MAX_MODE_LEN                   64               // 3G supported network mode length
#define ZZ_MAX_MODE_NUM                   64               // 3G supported network mode count
#define ZZ_MAX_COMPRESSION_TYPES_NUM      16               // Max video encoding format types
#define ZZ_MAX_CAPTURE_SIZE_NUM           64               // Video resolution count
#define ZZ_NODE_NAME_LEN                  64               // Organization node name length
#define ZZ_MAX_CALIBPOINTS_NUM            256              // Max supported calibration points
#define ZZ_MAX_ATTR_NUM                   32               // Max display unit attributes
#define ZZ_MAX_CLOUDCONNECT_STATE_LEN     128              // Cloud register connection status info length
#define ZZ_MAX_IPADDR_EX_LEN              128              // Max extended IP address length
#define ZZ_PLATE_NUMBER_LEN               32               // License plate string length   
#define ZZ_MAX_AUTHORITY_LIST_NUM         16               // Max authority list count   
#define ZZ_MAX_CITY_NAME_LEN              64               // Max city name length
#define ZZ_MAX_PROVINCE_NAME_LEN          64               // Max province name length
#define ZZ_MAX_PERSON_ID_LEN              32               // Max person ID length
#define ZZ_MAX_FACE_AREA_NUM              8                // Max face areas 
#define ZZ_MAX_FACE_DB_NUM                8                // Max face databases
#define ZZ_MAX_EVENT_NAME                 128              // Max event name length
#define ZZ_MAX_ETH_NAME                   64               // Max ethernet card name
#define ZZ_MAX_PERSON_NAME_LEN            64               // Max person name length
#define ZZ_N_SCHEDULE_TSECT               8                // Schedule element count    
#define ZZ_MAX_URL_NUM                    8                // Max URL count
#define ZZ_MAX_LOWER_MITRIX_NUM           16               // Max lower matrix number
#define ZZ_MAX_BURN_CHANNEL_NUM           32               // Max burn channel number
#define ZZ_MAX_NET_STRORAGE_BLOCK_NUM     64               // Max remote storage block number
#define ZZ_MAX_CASE_PERSON_NUM            32               // Max case person number
#define ZZ_MAX_MULTIPLAYBACK_CHANNEL_NUM  64               // Max multi-channel preview playback channel number
#define ZZ_MAX_MULTIPLAYBACK_SPLIT_NUM    32               // Max multi-channel preview playback split modes
#define ZZ_MAX_AUDIO_ENCODE_TYPE          64               // Max audio encode types
#define ZZ_MAX_LOG_PATH_LEN               260              // Max log path name length
#define ZZ_MAX_CARD_RECORD_FIELD_NUM      16               // Max card number recording fields
#define ZZ_BATTERY_NUM_MAX                16               // Max battery number    
#define ZZ_POWER_NUM_MAX                  16               // Max power supply number        
#define ZZ_MAX_AUDIO_PATH                 260              // Max audio file path length
#define ZZ_MAX_DOORNAME_LEN               128              // Max door name length    
#define ZZ_MAX_CARDPWD_LEN                64               // Max card password length    
#define ZZNET_MAX_FISHEYE_MOUNTMODE_NUM   4                // Max fisheye mount modes
#define ZZNET_MAX_FISHEYE_CALIBRATEMODE_NUM 16               // Max fisheye calibration modes
#define ZZNET_MAX_FISHEYE_EPTZCMD_NUM     64               // Max fisheye e-PTZ commands   
#define ZZ_POINT_NUM_IN_PAIR              2                // Points in calibration pair
#define ZZ_MAX_POINT_PAIR_NUM             128              // Max calibration point pairs
#define ZZ_CHANNEL_NUM_IN_POINT_GROUP     2                // Video channels in calibration point group
#define ZZ_MAX_POINT_GROUP_NUM            32               // Max calibration point groups, needed for splicing every two channels
#define ZZ_MAX_LANE_INFO_NUM              32               // Max lane info count
#define ZZ_MAX_LANE_DIRECTION_NUM         8                // Max lane direction count
#define ZZ_MAX_MONITORWALL_NUM            32               // Max monitor wall count
#define ZZ_MAX_OPTIONAL_URL_NUM           8                // Max backup URL count
#define ZZ_MAX_CAMERA_CHANNEL_NUM         1024             // Max camera channel count
#define ZZ_MAX_SIMILARITY_COUNT			  1024			   // Max face comparison library threshold count
#define ZZ_MAX_FILE_SUMMARY_NUM           32               // Max file summary count
#define ZZ_MAX_AUDIO_ENCODE_NUM           64               // Max supported audio encoding count
#define ZZ_MAX_MONITORWALL_NAME_LEN       64               // Monitor wall name max length
#define ZZ_MAX_FLASH_LIGHT_NUM            8                // Max supported flash/strobe lights
#define ZZ_MAX_STROBOSCOPIC_LIGHT_NUM     8                // Max supported stroboscopic lights
#define ZZ_MAX_MOSAIC_NUM                 8                // Max supported mosaic count
#define ZZ_MAX_MOSAIC_CHANNEL_NUM         256              // Max channels supporting mosaic overlay
#define ZZ_MAX_FIREWARNING_INFO_NUM       4                // Max thermal imaging fire warning info count
#define ZZ_MAX_AXLE_NUM                   8                // Max axle count
#define ZZ_MAX_BULLET_HOLES               10               // Max bullet holes 
#define ZZ_MAX_PLATE_NUM                     64               // Max plates per image
#define ZZ_MAX_PREVIEW_CHANNEL_NUM           64               // Max preview channel count for directing 
#define ZZ_MAX_EVENT_RESTORE_UUID            36               // Event restore UUID array size
#define ZZ_MAX_EVENT_RESTORE_CODE_NUM        8                // Max event restore type count
#define ZZ_MAX_EVENT_RESOTER_CODE_TYPE       32               // Event restore type array size
#define ZZ_MAX_SNAP_TYPE                     3                // Snapshot type count
#define ZZ_MAX_MAINFORMAT_NUM                4                // Max supported main stream type count
#define ZZ_CUSTOM_TITLE_LEN                  1024             // Custom title length (Expanded to 1024)
#define ZZ_MAX_CUSTOM_TITLE_NUM              8                // Max video widget custom titles
#define ZZ_FORMAT_TYPE_LEN                   16               // Encode type name max length
#define ZZ_MAX_CHANNEL_NAME_LEN              256              // Channel name max length
#define ZZ_MAX_VIRTUALINFO_DOMAIN_LEN        64               // Virtual identity surfing domain length
#define ZZ_MAX_VIRTUALINFO_TITLE_LEN         64               // Virtual identity surfing title length
#define ZZ_MAX_VIRTUALINFO_USERNAME_LEN      32               // Virtual identity username length
#define ZZ_MAX_VIRTUALINFO_PASSWORD_LEN      32               // Virtual identity password length
#define ZZ_MAX_VIRTUALINFO_PHONENUM_LEN      12               // Virtual identity phone number length
#define ZZ_MAX_VIRTUALINFO_IMEI_LEN          16               // Virtual identity IMEI length
#define ZZ_MAX_VIRTUALINFO_IMSI_LEN          16               // Virtual identity IMSI length
#define ZZ_MAX_VIRTUALINFO_LATITUDE_LEN      16               // Virtual identity latitude length
#define ZZ_MAX_VIRTUALINFO_LONGITUDE_LEN     16               // Virtual identity longitude length
#define ZZ_MAX_VIRTUALINFO_NUM               1024             // Max virtual identity info count
#define ZZ_MAX_CALL_ID_LEN                   64               // Call ID length
#define ZZ_MAX_FACE_DATA_LEN                 2048             // Face template data max length
#define ZZ_MAX_FACE_DATA_NUM                 20               // Face template max count
#define ZZ_MAX_PHOTO_COUNT                   5                // Face photo max count
#define ZZ_MAX_FINGERPRINT_NUM               10               // Max fingerprint count
#define ZZ_MAX_RINGFILE_NUM                  64               // Max doorbell audio file count
#define ZZ_MAX_VIDEOIN_CONFLICT_NUM          128              // Video output capability conflict max combination count
#define ZZ_MAX_COURSE_LOGIC_CHANNEL          64               // Recording host max logic channel count
#define ZZ_MAX_COMMON_STRING_8               8                // Common string length 8
#define ZZ_MAX_COMMON_STRING_16              16               // Common string length 16
#define ZZ_MAX_COMMON_STRING_32              32               // Common string length 32
#define ZZ_MAX_COMMON_STRING_64              64               // Common string length 64
#define ZZ_MAX_MAN_LIST_COUNT                64               // Person list max count
#define ZZ_MAX_COMMON_STRING_128             128              // Common string length 128
#define ZZ_MAX_STREAM_NUM                    4                // Max stream count
#define ZZ_MAX_CELL_PHONE_NUMBER_LEN         32               // Max cell phone number length
#define ZZ_MAX_MAIL_LEN                      64               // Max email length
#define ZZ_MAX_USER_NAME_LEN                 128              // Max username length
#define ZZ_MAX_PWD_LEN                       128              // Max password length
#define ZZ_MAX_SECURITY_CODE_LEN             16               // Max security code length sent to reserved phone/email    
#define ZZ_MAX_PWD_SPEC_CHARS_ARRAY_LEN      128              // Max password special char list length in password spec
#define ZZ_MAX_PWD_BASIC_CHARS_ARRAY_LEN     128              // Max basic char type list length in password spec        
#define ZZ_MAX_COMMON_STRING_512             512              // Common string length 512
#define ZZ_MAX_RFIDELETAG_CARDID_LEN         16               // RFID electronic tag card ID max length
#define ZZ_MAX_RFIDELETAG_DATE_LEN           16               // RFID electronic tag date max length
#define ZZ_MAX_LINK_NAME_LEN                 16               // Link name length
#define ZZ_MAX_SERVER_ADDRESS_LEN            64               // Server IP length
#define ZZ_LINK_LAYER_VPN_NUM                64               // Link layer VPN config count
#define ZZ_MAX_SERVER_IP_LEN                 32               // Server IP length 
#define ZZ_MAX_SCENICSPOT_POINTS_NUM         256              // Total scenic spot points
#define ZZ_MAX_ACCESSSUBCONTROLLER_NUM       64               // Max access sub-controller count
#define ZZ_MAX_ACCESSDOOR_NUM                128              // Max door count                 
#define ZZ_MAX_ACCESS_READER_NUM             32               // Max card reader per door
#define ZZ_MAX_ACCESS_POINT_NUM              32               // Anti-passback path max nodes
#define ZZ_MAX_CONFIG_NAME_LEN               128              // Max config name length
#define ZZ_MAX_PLATE_NUMBER_LEN              64               // Max license plate number length
#define ZZ_MAX_MASTER_OF_CAR_LEN             32               // Max car owner name length
#define ZZ_MAX_USER_TYPE_LEN                 32               // Max user type length
#define ZZ_MAX_SUB_USER_TYPE_LEN			  64			  // Max sub-user type length
#define ZZ_MAX_REMARKS_LEN					  64			  // Max remarks info length
#define ZZ_MAX_PARK_CHARGE_LEN               32               // Max parking fee length
#define ZZ_MAX_IN_TIME_LEN                   32               // Max vehicle entry time length
#define ZZ_MAX_OUT_TIME_LEN                  32               // Max vehicle exit time length
#define ZZ_MAX_CUSTOM_LEN                    128              // Max custom display length
#define ZZ_MAX_DEAL_NUM_LEN                  32               // Max receipt transaction number length
#define ZZ_MAX_STORE_NO_LEN                  32               // Max store number length
#define ZZ_MAX_STORE_NAME_LEN                32               // Max store name length
#define ZZ_MAX_STORE_EMPLOYEE_ID_LEN         32               // Max cashier ID length
#define ZZ_MAX_PRODUCT_NO_LEN                32               // Max product code length
#define ZZ_MAX_PRODUCT_NAME_LEN              32               // Max product name length
#define ZZ_MAX_PRODUCT_CATEGORY_LEN          32               // Max product category length
#define ZZ_MAX_FINGER_PRINT                  10               // Fingerprint ID array max length
#define ZZ_MAX_SUBCHANNEL_NUM                16               // Video sub-channel (collector) max count
#define ZZ_MAX_NAME_LENGTH                   32               // Max name length
#define ZZ_MAX_SNAP_URL_LEN                  128              // Max snapshot URL length
#define ZZ_MAX_CODE_LEN                      64               // Max item code length
#define ZZ_MAX_PERSON_INFO_NUM               4                // Max face info count
#define ZZ_MAX_GOOD_INFO_NUM                 128              // Max item info count
#define ZZ_MAX_SUB_TAG_NUM                   20               // Max sub-tag count
#define ZZ_MAX_MANUFACTURER_LEN              32               // Max MAC address manufacturer length
#define ZZ_MAX_MACHISTORY_SSID_LEN           24               // Max history SSID length
#define ZZ_MAX_MACHISTORY_SSID_NUM	         5	              // Max history SSID count
#define ZZ_MAX_ROUTE_NUM                     16               // Max route count
#define ZZ_MAX_MCU_NUM                       10               // Max alarm host MCU count
#define ZZ_MAX_ALARM_CHANNEL_NAME_LEN		 64               // Max alarm name length
#define ZZ_MAX_INSIDEOBJECT_NUM			     32			      // Max items inside package
#define ZZ_PRETASK_CHANNEL				     4				  // Video synopsis pre-processing task
#define ZZ_MAX_AGE_NUM						 2				  // Max age count
#define ZZ_MAX_EMOTION_NUM					 8				  // Max emotion condition count
#define ZZ_MAX_CLASS_NUMBER_LEN			     32			      // Max class length
#define ZZ_MAX_PHONENUMBER_LEN				 16			      // Max phone length
#define ZZ_MAX_NASFILE_NUM                   8                // Max NAS file count
#define ZZ_MAX_CROWD_DETECTION_NAME_LEN	     128			  // Max crowd density detection event name length
#define	ZZ_MAX_CROWD_LIST_NUM				 5				  // Max global crowd density list count
#define ZZ_MAX_REGION_LIST_NUM			     8				  // Max region list count for people count limit alarm
#define ZZ_MAX_RECORD_ENCRYPT_PASSWD_LEN	 128			  // Max record encryption password length
#define ZZ_MAX_EVENT_NAME_LEN				 128			  // Max event name length
#define ZZ_MAX_ABSTRACT_INFO_NUM			 100			  // Max face feature vector reconstruction result count
#define	ZZNET_COUNTRY_LENGTH		         3		          // Country abbreviation length
#define ZZNET_COMMENT_LENGTH		         100		      // Remarks info length
#define ZZNET_GROUPID_LENGTH		         64		          // Group ID info length
#define ZZNET_GROUPNAME_LENGTH		         128		      // Group name info length
#define ZZNET_FEATUREVALUE_LENGTH	         128		      // Face feature info length
#define ZZNET_MAX_COMPOSITE_CHANNEL          256              // Combined fusion screen channel max count
#define ZZ_MAX_DETECT_VERSION_NUM            64
#define ZZ_MAX_BLIND_DETECT_VERSION_NUM      64

#define ZZ_USER_NAME_LENGTH_EX       16                 // Username length
#define ZZ_USER_PSW_LENGTH_EX        16                 // Password


// Max support 64 channels device, corresponding to extended interface ZZNetSDK_QueryUserInfoNew and ZZNetSDK_OperateUserInfoNew
#define ZZ_NEW_MAX_RIGHT_NUM        1024
#define ZZ_NEW_USER_NAME_LENGTH     128                 // Username length
#define ZZ_NEW_USER_PSW_LENGTH      128                 // Password

/////////////////////////////////// Matrix ///////////////////////////////////////

#define ZZ_MATRIX_INTERFACE_LEN         16          // Signal interface name length
#define ZZ_MATRIX_MAX_CARDS             128         // Matrix sub-card max count
#define ZZ_SPLIT_PIP_BASE               1000        // Split mode PIP base value
#define ZZ_MAX_SPLIT_MODE_NUM           64          // Max split mode count
#define ZZ_MATRIX_MAX_CHANNEL_IN        1500        // Matrix max input channel count
#define ZZ_MATRIX_MAX_CHANNEL_OUT       256         // Matrix max output channel count
#define ZZ_DEVICE_NAME_LEN              64          // Device name length
#define ZZ_MAX_CPU_NUM                  16          // Max CPU count
#define ZZ_MAX_FAN_NUM                  16          // Max fan count
#define ZZ_MAX_POWER_NUM                16          // Max power supply count
#define ZZ_MAX_BATTERY_NUM              16          // Max battery count
#define ZZ_MAX_TEMPERATURE_NUM          256         // Max temperature sensor count
#define ZZ_MAX_ISCSI_NAME_LEN           128         // ISCSI name length
#define ZZ_VERSION_LEN                  64          // Version info length
#define ZZ_MAX_STORAGE_PARTITION_NUM    32          // Max storage partition count
#define ZZ_STORAGE_MOUNT_LEN            64          // Mount point length
#define ZZ_STORAGE_FILE_SYSTEM_LEN      16          // File system name length
#define ZZ_MAX_MEMBER_PER_RAID          32          // RAID member max count
#define ZZ_DEV_ID_LEN_EX                128         // Device ID max length
#define ZZ_MAX_BLOCK_NUM                32          // Max block count
#define ZZ_MAX_SPLIT_WINDOW             128         // Max split window count
#define ZZ_FILE_TYPE_LEN                64          // File type length
#define ZZ_DEV_ID_LEN                   128         // Device ID max length
#define ZZ_DEV_NAME_LEN                 128         // Device name max length
#define ZZ_TSCHE_DAY_NUM                8           // Schedule first dimension size, represents days
#define ZZ_TSCHE_SEC_NUM                6           // Schedule second dimension size, represents periods
#define ZZ_SPLIT_INPUT_NUM              256         // Judicial device secondary switch first level split supported input channels


// Time
typedef struct 
{
    DWORD                dwYear;                  // Year
    DWORD                dwMonth;                 // Month
    DWORD                dwDay;                   // Day
    DWORD                dwHour;                  // Hour
    DWORD                dwMinute;                // Minute
    DWORD                dwSecond;                // Second
} ZZNET_TIME,*LPZZNET_TIME;

typedef struct 
{
    DWORD                dwYear;                  // Year
    DWORD                dwMonth;                 // Month
    DWORD                dwDay;                   // Day
    DWORD                dwHour;                  // Hour
    DWORD                dwMinute;                // Minute
    DWORD                dwSecond;                // Second
    DWORD                dwMillisecond;           // Millisecond
    DWORD                dwReserved[2];           // Reserved fields
} ZZNET_TIME_EX,*LPZZNET_TIME_EX;

// Region; Each margin proportional to length 8192
typedef struct 
{
   long             left;
   long             top;
   long             right;
   long             bottom;
} ZZ_RECT, *LPZZ_RECT;

typedef struct tagZZNET_RECT
{
    int             nLeft;
    int             nTop;
    int             nRight;
    int             nBottom;
} ZZNET_RECT;


// 2D space point
typedef struct 
{
   short            nx;
   short            ny;
} ZZ_POINT, * LPZZ_POINT, ZZNET_POINT, * LPZZNET_POINT; 

// Time section structure                                                                
typedef struct tagZZ_TSECT
{
    int             bEnable;                        // When representing recording time section, bits represent four enables: Motion Detect Record, Alarm Record, Normal Record, Motion and Alarm simultaneous record (low to high)
													// When representing Arm/Disarm time section, represents enable
    int             iBeginHour;
    int             iBeginMin;
    int             iBeginSec;
    int             iEndHour;
    int             iEndMin;
    int             iEndSec;
} ZZ_TSECT, *LPZZ_TSECT;

// Event corresponding file info
typedef struct
{
    BYTE               bCount;                               // Total files in the file group of current file
    BYTE               bIndex;                               // File index in file group (starts from 1)
    BYTE               bFileTag;                             // File tag, EM_ZZ_EVENT_FILETAG
    BYTE               bFileType;                            // File type, 0-Normal 1-Synthesized 2-Cutout
    ZZNET_TIME_EX      stuFileTime;                          // File time
    DWORD              nGroupId;                             // Unique ID for same group of snapshots
}ZZ_EVENT_FILE_INFO;


// Image resolution
typedef struct
{
    unsigned short   snWidth;    // Width
    unsigned short   snHight;    // Height
}ZZ_RESOLUTION_INFO;

// Color RGBA
typedef struct tagZZ_COLOR_RGBA
{
    int                 nRed;                       // Red
    int                 nGreen;                     // Green
    int                 nBlue;                      // Blue
    int                 nAlpha;                     // Alpha
} ZZ_COLOR_RGBA, ZZNET_COLOR_RGBA;


// Region or curve vertex info
typedef struct
{
    int        nPointNum;                               // Vertex count
    ZZ_POINT   stuPoints[ZZ_MAX_DETECT_REGION_NUM];     // Vertex info
}ZZ_POLY_POINTS;


// Permission info
typedef struct _ZZ_OPR_RIGHT_NEW
{
    DWORD               dwSize;
    DWORD               dwID;
    char                name[ZZ_RIGHT_NAME_LENGTH];
    char                memo[ZZ_MEMO_LENGTH];
} ZZ_OPR_RIGHT_NEW;

// User info
typedef struct _ZZ_USER_INFO_NEW
{
    DWORD               dwSize;
    DWORD               dwID;
    DWORD               dwGroupID;
    char                name[ZZ_NEW_USER_NAME_LENGTH];
    char                passWord[ZZ_NEW_USER_PSW_LENGTH];
    DWORD               dwRightNum;
    DWORD               rights[ZZ_NEW_MAX_RIGHT_NUM];
    char                memo[ZZ_MEMO_LENGTH];
    DWORD               dwFouctionMask;                 // Mask, 0x00000001 - Support user reuse
    ZZNET_TIME            stuTime;                        // Last modification time
    BYTE                byIsAnonymous;                  // Can login anonymously, 0: No, 1: Yes
    BYTE                byReserve[7];
} ZZ_USER_INFO_NEW;

// User group info
typedef struct _ZZ_USER_GROUP_INFO_NEW
{
    DWORD               dwSize;
    DWORD               dwID;
    char                name[ZZ_USER_NAME_LENGTH_EX];
    DWORD               dwRightNum;
    DWORD               rights[ZZ_NEW_MAX_RIGHT_NUM];
    char                memo[ZZ_MEMO_LENGTH];
} ZZ_USER_GROUP_INFO_NEW;

// User group info extended, extended group name length
typedef struct _ZZ_USER_GROUP_INFO_EX2
{
    DWORD               dwSize;
    DWORD               dwID;
    char                name[ZZ_NEW_USER_NAME_LENGTH];
    DWORD               dwRightNum;
    DWORD               rights[ZZ_NEW_MAX_RIGHT_NUM];
    char                memo[ZZ_MEMO_LENGTH];
} ZZ_USER_GROUP_INFO_EX2;

// User info table
typedef struct _ZZ_USER_MANAGE_INFO_NEW
{
    DWORD               dwSize;
    DWORD               dwRightNum;                         // Permission info
    ZZ_OPR_RIGHT_NEW    rightList[ZZ_NEW_MAX_RIGHT_NUM];
    DWORD               dwGroupNum;                         // User group count
    ZZ_USER_GROUP_INFO_NEW groupList[ZZ_MAX_GROUP_NUM];        // User group info, deprecated, use groupListEx
    DWORD               dwUserNum;                          // User info
    ZZ_USER_INFO_NEW    userList[ZZ_MAX_USER_NUM];
    DWORD               dwFouctionMask;                     // Mask; 0x00000001 - Support user reuse, 0x00000002 - Password modification requires verification
    BYTE                byNameMaxLength;                    // Supported max username length
    BYTE                byPSWMaxLength;                     // Supported max password length
    BYTE                byReserve[254];
    ZZ_USER_GROUP_INFO_EX2 groupListEx[ZZ_MAX_GROUP_NUM];      // User group info extended
} ZZ_USER_MANAGE_INFO_NEW;



// New audio detection alarm info
typedef struct
{
    int                 channel;                        // Alarm channel number
    int                 alarmType;                      // Alarm type; 0: Audio too low, 1: Audio too high
    unsigned int        volume;                         // Volume value
    BYTE                byState;                        // Audio alarm state, 0: Alarm appears, 1: Alarm disappears
    char                reserved[255];
} ZZNET_NEW_SOUND_ALARM_STATE;

typedef struct  
{
    int                         channelcount;           // Alarm channel count
    ZZNET_NEW_SOUND_ALARM_STATE   SoundAlarmInfo[ZZ_MAX_ALARM_IN_NUM];
} ZZ_NEW_SOUND_ALARM_STATE;

// 3G Flow Exceed Threshold State Info
typedef struct __ZZDEV_3GFLOW_EXCEED_STATE_INFO
{
    BYTE                bState;                 // 3G flow exceed threshold state, 0: not exceeded, 1: exceeded
    char                reserve[31];
} ZZDEV_3GFLOW_EXCEED_STATE_INFO;


// Preset Status Enum
typedef enum tagEM_ZZ_PTZ_PRESET_STATUS
{
    EM_ZZ_PTZ_PRESET_STATUS_UNKNOWN,        // Unknown
    EM_ZZ_PTZ_PRESET_STATUS_REACH,          // Preset Reached
    EM_ZZ_PTZ_PRESET_STATUS_UNREACH,        // Preset Not Reached
}EM_ZZ_PTZ_PRESET_STATUS;

// PTZ Positioning Info Alarm
typedef struct
{
    int     nChannelID;                 // Channel ID 
    int     nPTZPan;                    // PTZ Pan position, valid range: [0,3600]
    int     nPTZTilt;                   // PTZ Tilt position, valid range: [-1800,1800]
    int     nPTZZoom;                   // PTZ Zoom position, valid range: [0,128]
    BYTE    bState;                     // PTZ motion state, 0-Unknown 1-Moving 2-Idle 
    BYTE    bAction;                    // PTZ action, 255-Unknown, 0-Preset, 1-Line Scan, 2-Cruise, 3-Pattern, 4-Pan, 5-Normal Move, 6-Pattern Record, 7-Panorama Scan, 8-Heat Map
                                        // 9-Precise Positioning, 10-Device Calibration, 11-Smart Config, 12-PTZ Restart
    BYTE    bFocusState;                // PTZ focus state, 0-Unknown, 1-Moving, 2-Idle
    BYTE    bEffectiveInTimeSection;    // Preset state effective within time section
                                        // If currently reported preset is within time section, then 1, otherwise 0
    int     nPtzActionID;               // Cruise ID
    DWORD   dwPresetID;                 // Current Preset ID
    float   fFocusPosition;             // Focus position
    BYTE    bZoomState;                 // PTZ ZOOM state, 0-Unknown, 1-ZOOM, 2-Idle
    BYTE    bReserved[3];               // Alignment
    DWORD   dwSequence;                 // Packet sequence number, used for packet loss check
    DWORD   dwUTC;                      // Corresponding UTC (1970-1-1 00:00:00) seconds.
    EM_ZZ_PTZ_PRESET_STATUS emPresetStatus; // Preset position
	int	    nZoomValue;				    // Real zoom value, current magnification (multiplied by 100)
    int     reserved[244];              // Reserved field
}ZZ_PTZ_LOCATION_INFO;

// Blacklist Vehicle Snapshot Event
typedef struct __ZZ_BLACKLIST_SNAP_INFO
{
    DWORD     dwSize;
    char      szPlateNumber[32];                          // Plate Number
    ZZNET_TIME  stuTime;                                    // Event Time
}ZZ_BLACKLIST_SNAP_INFO;




// Alarm Type, corresponds to ZZNETSDK_StartListen interface
#define ZZ_COMM_ALARM                     0x1100           // Normal alarm (including external alarm, video loss, motion detection)
#define ZZ_SHELTER_ALARM                  0x1101           // Video shelter/blind alarm
#define ZZ_DISK_FULL_ALARM                0x1102           // Disk full alarm
#define ZZ_DISK_ERROR_ALARM               0x1103           // Disk error alarm
#define ZZ_SOUND_DETECT_ALARM             0x1104           // Audio detection alarm
#define ZZ_ALARM_DECODER_ALARM            0x1105           // Alarm decoder alarm

// Extended Alarm Type, corresponds to ZZNETSDK_StartListenEx interface
#define ZZ_ALARM_ALARM_EX                 0x2101           // External alarm, data bytes equal to device alarm channel count, each byte represents alarm status of a channel, 1: alarm, 0: no alarm.
#define ZZ_MOTION_ALARM_EX                0x2102           // Motion detection alarm, data bytes equal to device video channel count, each byte represents motion alarm status of a channel, 1: alarm, 0: no alarm.
#define ZZ_VIDEOLOST_ALARM_EX             0x2103           // Video loss alarm, data bytes equal to device video channel count, each byte represents video loss status of a channel, 1: alarm, 0: no alarm.
#define ZZ_SHELTER_ALARM_EX               0x2104           // Video shelter alarm, data bytes equal to device video channel count, each byte represents shelter (black screen) status of a channel, 1: alarm, 0: no alarm.
#define ZZ_SOUND_DETECT_ALARM_EX          0x2105           // Audio detection alarm, data is 16 bytes, each byte represents audio detection status of a video channel, 1: alarm, 0: no alarm.
#define ZZ_DISKFULL_ALARM_EX              0x2106           // Disk full alarm, data is 1 byte, 1: disk full alarm, 0: no alarm.
#define ZZ_DISKERROR_ALARM_EX             0x2107           // Bad disk alarm, data is 32 bytes, each byte represents failure status of a disk, 1: alarm, 0: no alarm.
#define ZZ_ENCODER_ALARM_EX               0x210A           // Encoder alarm, data is 16 bytes, each byte represents encoder status of a channel, 1: alarm, 0: no alarm.
#define ZZ_URGENCY_ALARM_EX               0x210B           // Urgency alarm, data is 16 bytes, each byte represents encoder status of a channel, 1: alarm, 0: no alarm.
#define ZZ_WIRELESS_ALARM_EX              0x210C           // Wireless alarm, data is 16 bytes, each byte represents encoder status of a channel, 1: alarm, 0: no alarm.
#define ZZ_NEW_SOUND_DETECT_ALARM_EX      0x210D           // New audio detection alarm, alarm info struct see ZZ_NEW_SOUND_ALARM_STATE;
#define ZZ_ALARM_DECODER_ALARM_EX         0x210E           // Alarm decoder alarm, alarm info struct see ALARM_DECODER_ALARM
#define ZZ_DECODER_DECODE_ABILITY         0x210F           // Decoder: decode ability alarm, data is 1 byte, 0: normal decode, 1: exceeds decode ability.
#define ZZ_FDDI_DECODER_ABILITY           0x2110           // Fiber encoder status alarm, alarm info struct see ALARM_FDDI_ALARM
#define ZZ_PANORAMA_SWITCH_ALARM_EX       0x2111           // Switch scene alarm, data is 16 bytes, each byte represents encoder status of a channel, 1: alarm, 0: no alarm.
#define ZZ_LOSTFOCUS_ALARM_EX             0x2112           // Lost focus alarm, data is 16 bytes, each byte represents encoder status of a channel, 1: alarm, 0: no alarm.
#define ZZ_OEMSTATE_EX                    0x2113           // OEM pause status, data is 1 BYTE.
#define ZZ_DSP_ALARM_EX                   0x2114           // DSP alarm, alarm info struct see DSP_ALARM
#define ZZ_ATMPOS_BROKEN_EX               0x2115           // ATM and POS disconnected alarm, data is 1 BYTE, 0: disconnected, 1: connected
#define ZZ_RECORD_CHANGED_EX              0x2116           // Record status changed alarm, alarm info is ALARM_RECORDING_CHANGED array
#define ZZ_CONFIG_CHANGED_EX              0x2117           // Configuration changed alarm, data None
#define ZZ_DEVICE_REBOOT_EX               0x2118           // Device reboot alarm, data None
#define ZZ_WINGDING_ALARM_EX              0x2119           // Coil/Vehicle detector fault alarm (corresponds to struct ALARM_WINGDING_INFO)
#define ZZ_TRAF_CONGESTION_ALARM_EX       0x211A           // Traffic congestion alarm (vehicle abnormal stop or queuing) (corresponds to struct ALARM_TRAF_CONGESTION_INFO)
#define ZZ_TRAF_EXCEPTION_ALARM_EX        0x211B           // Traffic exception alarm (traffic flow tends to 0 or abnormally idle) (corresponds to struct ALARM_TRAF_EXCEPTION_INFO)
#define ZZ_EQUIPMENT_FILL_ALARM_EX        0x211C           // Fill light device fault alarm (corresponds to struct ALARM_EQUIPMENT_FILL_INFO)
#define ZZ_ALARM_ARM_DISARM_STATE         0x211D           // Arm/Disarm state (corresponds to struct ALARM_EQUIPMENT_FILL_INFO)
#define ZZ_ALARM_ACC_POWEROFF             0x211E           // ACC power off alarm, data is DWORD 0: ACC On 1: ACC Off
#define ZZ_ALARM_3GFLOW_EXCEED            0x211F           // 3G Flow Exceed Threshold Alarm (corresponds to struct ZZDEV_3GFLOW_EXCEED_STATE_INFO)
#define ZZ_ALARM_SPEED_LIMIT              0x2120           // Speed limit alarm (corresponds to struct ALARM_SPEED_LIMIT)
#define ZZ_ALARM_VEHICLE_INFO_UPLOAD      0x2121           // Vehicle custom info upload (corresponds to struct ALARM_VEHICLE_INFO_UPLOAD)
#define ZZ_STATIC_ALARM_EX                0x2122           // Static detection alarm, data bytes equal to device video channel count, each byte represents static detection alarm status of a channel, 1: alarm, 0: no alarm.
#define ZZ_PTZ_LOCATION_EX                0x2123           // PTZ location info (corresponds to struct ZZ_PTZ_LOCATION_INFO)
#define ZZ_ALARM_CARD_RECORD_UPLOAD       0x2124           // Card record info upload (corresponds to struct ALARM_CARD_RECORD_INFO_UPLOAD)
#define ZZ_ALARM_ATM_INFO_UPLOAD          0x2125           // ATM transaction info upload (corresponds to struct ALARM_ATM_INFO_UPLOAD)
#define ZZ_ALARM_ENCLOSURE                0x2126           // Electronic fence alarm (corresponds to struct ALARM_ENCLOSURE_INFO)
#define ZZ_ALARM_SIP_STATE                0x2127           // SIP state alarm (corresponds to struct ALARM_SIP_STATE)
#define ZZ_ALARM_RAID_STATE               0x2128           // RAID exception alarm (corresponds to struct ALARM_RAID_INFO)
#define ZZ_ALARM_CROSSING_SPEED_LIMIT     0x2129           // Crossing speed limit alarm (corresponds to struct ALARM_SPEED_LIMIT)
#define ZZ_ALARM_OVER_LOADING             0x212A           // Overloading alarm (corresponds to struct ALARM_OVER_LOADING)
#define ZZ_ALARM_HARD_BRAKING             0x212B           // Hard braking alarm (corresponds to struct ALARM_HARD_BRAKING)
#define ZZ_ALARM_SMOKE_SENSOR             0x212C           // Smoke sensor alarm (corresponds to struct ALARM_SMOKE_SENSOR)
#define ZZ_ALARM_TRAFFIC_LIGHT_FAULT      0x212D           // Traffic light fault alarm (corresponds to struct ALARM_TRAFFIC_LIGHT_FAULT)
#define ZZ_ALARM_TRAFFIC_FLUX_STAT        0x212E           // Traffic flux statistics alarm (corresponds to struct ALARM_TRAFFIC_FLUX_LANE_INFO)
#define ZZ_ALARM_CAMERA_MOVE              0x212F           // Camera move alarm event (corresponds to struct ALARM_CAMERA_MOVE_INFO)
#define ZZ_ALARM_DETAILEDMOTION           0x2130           // Detailed motion alarm upload info (corresponds to struct ALARM_DETAILEDMOTION_CHNL_INFO)
#define ZZ_ALARM_STORAGE_FAILURE          0x2131           // Storage failure alarm (corresponds to struct ALARM_STORAGE_FAILURE array)
#define ZZ_ALARM_FRONTDISCONNECT          0x2132           // Front-end IPC disconnect alarm (corresponds to struct ALARM_FRONTDISCONNET_INFO)
#define ZZ_ALARM_ALARM_EX_REMOTE          0x2133           // Remote external alarm (corresponds to struct ALARM_REMOTE_ALARM_INFO)
#define ZZ_ALARM_BATTERYLOWPOWER          0x2134           // Battery low power alarm (corresponds to struct ALARM_BATTERYLOWPOWER_INFO)
#define ZZ_ALARM_TEMPERATURE              0x2135           // Temperature high alarm (corresponds to struct ALARM_TEMPERATURE_INFO)
#define ZZ_ALARM_TIREDDRIVE               0x2136           // Tired driving alarm (corresponds to struct ALARM_TIREDDRIVE_INFO)
#define ZZ_ALARM_LOST_RECORD              0x2137           // Lost record event alarm (corresponds to struct ALARM_LOST_RECORD)
#define ZZ_ALARM_HIGH_CPU                 0x2138           // High CPU usage event alarm (corresponds to struct ALARM_HIGH_CPU)
#define ZZ_ALARM_LOST_NETPACKET           0x2139           // Network packet loss event alarm (corresponds to struct ALARM_LOST_NETPACKET)
#define ZZ_ALARM_HIGH_MEMORY              0x213A           // High memory usage event alarm (corresponds to struct ALARM_HIGH_MEMORY)
#define ZZ_LONG_TIME_NO_OPERATION         0x213B           // WEB user long time no operation event (no extended info)
#define ZZ_BLACKLIST_SNAP                 0x213C           // Blacklist vehicle snapshot event (corresponds to struct ZZ_BLACKLIST_SNAP_INFO)         
#define ZZ_ALARM_DISK                     0x213E           // Disk alarm (corresponds to ALARM_DISK_INFO array)
#define ZZ_ALARM_FILE_SYSTEM              0x213F           // File system alarm (corresponds to ALARM_FILE_SYSTEM_INFO array)
#define ZZ_ALARM_IVS                      0x2140           // Intelligent alarm event (corresponds to struct ALARM_IVS_INFO)
#define ZZ_ALARM_GOODS_WEIGHT_UPLOAD      0x2141           // Goods weight info upload (corresponds to ALARM_GOODS_WEIGHT_UPLOAD_INFO)
#define ZZ_ALARM_GOODS_WEIGHT             0x2142           // Goods weight alarm (corresponds to ALARM_GOODS_WEIGHT_INFO)
#define ZZ_GPS_STATUS                     0x2143           // GPS status info (corresponds to NET_GPS_STATUS_INFO)
#define ZZ_ALARM_DISKBURNED_FULL          0x2144           // Disk burning full alarm (corresponds to ALARM_DISKBURNED_FULL_INFO)
#define ZZ_ALARM_STORAGE_LOW_SPACE        0x2145           // Storage low space event (corresponds to ALARM_STORAGE_LOW_SPACE_INFO)
#define ZZ_ALARM_DISK_FLUX                0x2160           // Disk flux exception event (corresponds to ALARM_DISK_FLUX)
#define ZZ_ALARM_NET_FLUX                 0x2161           // Network flux exception event (corresponds to ALARM_NET_FLUX)
#define ZZ_ALARM_FAN_SPEED                0x2162           // Fan speed exception event (corresponds to ALARM_FAN_SPEED)
#define ZZ_ALARM_STORAGE_FAILURE_EX       0x2163           // Storage error alarm (corresponds to struct ALARM_STORAGE_FAILURE_EX)
#define ZZ_ALARM_RECORD_FAILED            0x2164           // Record exception alarm (corresponds to struct ALARM_RECORD_FAILED_INFO)
#define ZZ_ALARM_STORAGE_BREAK_DOWN       0x2165           // Storage breakdown event (corresponds to struct ALARM_STORAGE_BREAK_DOWN_INFO)
#define ZZ_ALARM_VIDEO_ININVALID          0x2166           // Video input channel invalid event (e.g., input stream exceeds device processing capability) ALARM_VIDEO_ININVALID_INFO
#define ZZ_ALARM_VEHICLE_TURNOVER         0x2167           // Vehicle turnover alarm event (corresponds to struct ALARM_VEHICEL_TURNOVER_EVENT_INFO)
#define ZZ_ALARM_VEHICLE_COLLISION        0x2168           // Vehicle collision alarm event (corresponds to struct ALARM_VEHICEL_COLLISION_EVENT_INFO)
#define ZZ_ALARM_VEHICLE_CONFIRM          0x2169           // Vehicle confirm info upload event (corresponds to struct ALARM_VEHICEL_CONFIRM_INFO)
#define ZZ_ALARM_VEHICLE_LARGE_ANGLE      0x2170           // Vehicle camera large angle twist event (corresponds to struct ALARM_VEHICEL_LARGE_ANGLE)
#define ZZ_ALARM_TALKING_INVITE           0x2171           // Device requests peer to initiate talk event (corresponds to struct ALARM_TALKING_INVITE_INFO)
#define ZZ_ALARM_ALARM_EX2                0x2175           // Local alarm event (corresponds to struct ALARM_ALARM_INFO_EX2)
#define ZZ_ALARM_VIDEO_TIMING             0x2176           // Video timing detection event (corresponds to struct ALARM_VIDEO_TIMING)
#define ZZ_ALARM_COMM_PORT                0x2177           // Serial port event (corresponds to struct ALARM_COMM_PORT_EVENT_INFO)
#define ZZ_ALARM_AUDIO_ANOMALY            0x2178           // Audio anomaly event (corresponds to struct ALARM_AUDIO_ANOMALY)
#define ZZ_ALARM_AUDIO_MUTATION           0x2179           // Sound intensity mutation event (corresponds to struct ALARM_AUDIO_MUTATION)
#define ZZ_EVENT_TYREINFO                 0x2180           // Tyre info upload event (corresponds to struct EVENT_TYRE_INFO)
#define ZZ_ALARM_POWER_ABNORMAL           0x2181           // Redundant power abnormal alarm (corresponds to struct ALARM_POWER_ABNORMAL_INFO)
#define ZZ_EVENT_REGISTER_OFF             0x2182           // Vehicle device active offline event (corresponds to struct EVENT_REGISTER_OFF_INFO)
#define ZZ_ALARM_NO_DISK                  0x2183           // No disk alarm (corresponds to struct ZZALARM_NO_DISK_INFO)
#define ZZ_ALARM_FALLING                  0x2184           // Falling event alarm (corresponds to struct ALARM_FALLING_INFO)
#define ZZ_ALARM_PROTECTIVE_CAPSULE       0x2185           // Protective capsule event (corresponds to struct ALARM_PROTECTIVE_CAPSULE_INFO)
#define ZZ_ALARM_NO_RESPONSE              0x2186           // Call no response alarm (corresponds to struct ALARM_NO_RESPONSE_INFO)
#define ZZ_ALARM_CONFIG_ENABLE_CHANGE     0x2187           // Config enable change upload event (corresponds to struct ALARM_CONFIG_ENABLE_CHANGE_INFO)
#define ZZ_EVENT_CROSSLINE_DETECTION      0x2188           // Crossline detection event (corresponds to struct ALARM_EVENT_CROSSLINE_INFO)
#define ZZ_EVENT_CROSSREGION_DETECTION    0x2189           // Cross region detection event (corresponds to struct ALARM_EVENT_CROSSREGION_INFO)
#define ZZ_EVENT_LEFT_DETECTION           0x218a           // Left object detection event (corresponds to struct ALARM_EVENT_LEFT_INFO)
#define ZZ_EVENT_FACE_DETECTION           0x218b           // Face detection event (corresponds to struct ALARM_EVENT_FACE_INFO) 
#define ZZ_ALARM_IPC                      0x218c           // IPC Alarm, IPC reports local alarm via DVR or NVR (corresponds to struct ALARM_IPC_INFO)
#define ZZ_EVENT_TAKENAWAYDETECTION       0x218d           // Taken away detection event (corresponds to struct ALARM_TAKENAWAY_DETECTION_INFO)
#define ZZ_EVENT_VIDEOABNORMALDETECTION   0x218e           // Video abnormal detection event (corresponds to struct ALARM_VIDEOABNORMAL_DETECTION_INFO)
#define ZZ_EVENT_MOTIONDETECT             0x218f           // Video motion detection event (corresponds to struct ALARM_MOTIONDETECT_INFO)
#define ZZ_ALARM_PIR                      0x2190           // PIR alarm (corresponds to BYTE*, pBuf length dwBufLen)
#define ZZ_ALARM_STORAGE_HOT_PLUG         0x2191           // Storage hot plug event (corresponds to struct ALARM_STORAGE_HOT_PLUG_INFO)
#define ZZ_ALARM_FLOW_RATE                0x2192           // Flow rate usage event (corresponds to struct ALARM_FLOW_RATE_INFO)
#define ZZ_ALARM_MOVEDETECTION            0x2193           // Move detection event (corresponds to ALARM_MOVE_DETECTION_INFO)
#define ZZ_ALARM_WANDERDETECTION          0x2194           // Wander detection event (corresponds to ALARM_WANDERDETECTION_INFO)
#define ZZ_ALARM_CROSSFENCEDETECTION      0x2195           // Cross fence detection event (corresponds to ALARM_CROSSFENCEDETECTION_INFO)
#define ZZ_ALARM_PARKINGDETECTION         0x2196           // Illegal parking detection event (corresponds to ALARM_PARKINGDETECTION_INFO)
#define ZZ_ALARM_RIOTERDETECTION          0x2197           // Rioter detection event (corresponds to ALARM_RIOTERDETECTION_INFO)
#define ZZ_ALARM_STORAGE_NOT_EXIST        0x3167           // Storage group not exist event (corresponds to struct ALARM_STORAGE_NOT_EXIST_INFO)
#define ZZ_ALARM_NET_ABORT                0x3169           // Network fault event (corresponds to struct ALARM_NETABORT_INFO)
#define ZZ_ALARM_IP_CONFLICT              0x3170           // IP conflict event (corresponds to struct ALARM_IP_CONFLICT_INFO)
#define ZZ_ALARM_MAC_CONFLICT             0x3171           // MAC conflict event (corresponds to struct ALARM_MAC_CONFLICT_INFO)
#define ZZ_ALARM_POWERFAULT               0x3172           // Power fault event (corresponds to struct ALARM_POWERFAULT_INFO)
#define ZZ_ALARM_CHASSISINTRUDED          0x3173           // Chassis intruded (Tamper) alarm event (corresponds to struct ALARM_CHASSISINTRUDED_INFO)
#define ZZ_ALARM_ALARMEXTENDED            0x3174           // Local extended alarm event (corresponds to struct ALARM_ALARMEXTENDED_INFO)
#define ZZ_ALARM_ARMMODE_CHANGE_EVENT     0x3175           // Arm mode change event (corresponds to struct ALARM_ARMMODE_CHANGE_INFO)
#define ZZ_ALARM_BYPASSMODE_CHANGE_EVENT  0x3176           // Bypass mode change event (corresponds to struct ALARM_BYPASSMODE_CHANGE_INFO)
#define ZZ_ALARM_ACCESS_CTL_NOT_CLOSE     0x3177           // Access control not closed event (corresponds to struct ALARM_ACCESS_CTL_NOT_CLOSE_INFO)
#define ZZ_ALARM_ACCESS_CTL_BREAK_IN      0x3178           // Break in event (corresponds to struct ALARM_ACCESS_CTL_BREAK_IN_INFO)
#define ZZ_ALARM_ACCESS_CTL_REPEAT_ENTER  0x3179           // Repeat enter event (corresponds to struct ALARM_ACCESS_CTL_REPEAT_ENTER_INFO)
#define ZZ_ALARM_ACCESS_CTL_DURESS        0x3180           // Duress card swipe event (corresponds to struct ALARM_ACCESS_CTL_DURESS_INFO)
#define ZZ_ALARM_ACCESS_CTL_EVENT         0x3181           // Access control event (corresponds to struct ALARM_ACCESS_CTL_EVENT_INFO)
#define ZZ_URGENCY_ALARM_EX2              0x3182           // Urgency Alarm EX2 (Upgrade to ZZ_URGENCY_ALARM_EX, corresponds to struct ALARM_URGENCY_ALARM_EX2, manually triggered emergency event, usually linked to external communication for help
#define ZZ_ALARM_INPUT_SOURCE_SIGNAL      0x3183           // Alarm input source signal event (Generated whenever there is input, regardless of zone mode, cannot be masked, corresponds to ALARM_INPUT_SOURCE_SIGNAL_INFO)
#define ZZ_ALARM_ANALOGALARM_EVENT        0x3184           // Analog alarm input channel event (corresponds to struct ALARM_ANALOGALARM_EVENT_INFO)
#define ZZ_ALARM_ACCESS_CTL_STATUS        0x3185           // Access control status event (corresponds to struct ALARM_ACCESS_CTL_STATUS_INFO)
#define ZZ_ALARM_ACCESS_SNAP              0x3186           // Access control snapshot event (corresponds to struct ALARM_ACCESS_SNAP_INFO)
#define ZZ_ALARM_ALARMCLEAR               0x3187           // Alarm clear event (corresponds to struct ALARM_ALARMCLEAR_INFO)
#define ZZ_ALARM_CIDEVENT                 0x3188           // CID event (corresponds to struct ALARM_CIDEVENT_INFO)
#define ZZ_ALARM_TALKING_HANGUP           0x3189           // Device active hangup talk event (corresponds to struct ALARM_TALKING_HANGUP_INFO)
#define ZZ_ALARM_BANKCARDINSERT           0x318a           // Bank card insert event (corresponds to struct ALARM_BANKCARDINSERT_INFO)
#define ZZ_ALARM_RCEMERGENCY_CALL         0x318b           // Emergency call alarm event (corresponds to struct ALARM_RCEMERGENCY_CALL_INFO)
#define ZZ_ALARM_OPENDOORGROUP            0x318c           // Multi-person group open door event (corresponds to struct ALARM_OPEN_DOOR_GROUP_INFO)
#define ZZ_ALARM_FINGER_PRINT             0x318d           // Capture fingerprint event (corresponds to struct ALARM_CAPTURE_FINGER_PRINT_INFO)
#define ZZ_ALARM_CARD_RECORD              0x318e           // Card record event (corresponds to struct ALARM_CARD_RECORD_INFO)
#define ZZ_ALARM_SUBSYSTEM_STATE_CHANGE   0x318f           // Subsystem state change event (corresponds to struct ALARM_SUBSYSTEM_STATE_CHANGE_INFO)
#define ZZ_ALARM_BATTERYPOWER_EVENT       0x3190           // Battery power scheduled notification event (corresponds to struct ALARM_BATTERYPOWER_INFO)
#define ZZ_ALARM_BELLSTATUS_EVENT         0x3191           // Bell status event (corresponds to struct ALARM_BELLSTATUS_INFO)
#define ZZ_ALARM_DEFENCE_STATE_CHANGE_EVENT 0x3192         // Defence state change event (corresponds to struct ALARM_DEFENCE_STATUS_CHANGE_INFO), 
                                                           // Customized requirement, different from Arm/Disarm change event and Bypass state change event,
                                                           // This state is obtained via ZZNETSDK_QueryDevState() interface with ZZ_DEVSTATE_DEFENCE_STATE command
#define ZZ_ALARM_TICKET_STATISTIC         0x3193           // Ticket statistic info event (corresponds to struct ALARM_TICKET_STATISTIC)
#define ZZ_ALARM_LOGIN_FAILIUR            0x3194           // Login failure event (corresponds to struct ALARM_LOGIN_FAILIUR_INFO)
#define ZZ_ALARM_MODULE_LOST              0x3195           // Extension module lost event (corresponds to struct ALARM_MODULE_LOST_INFO)
#define ZZ_ALARM_PSTN_BREAK_LINE          0x3196           // PSTN break line event (corresponds to struct ALARM_PSTN_BREAK_LINE_INFO)
#define ZZ_ALARM_ANALOG_PULSE             0x3197           // Analog alarm event (Instantaneous event), triggered only by specific sensor types (corresponds to struct ALARM_ANALOGPULSE_INFO)
#define ZZ_ALARM_MISSION_CONFIRM          0x3198           // Mission confirm event (corresponds to struct ALARM_MISSION_CONFIRM_INFO)
#define ZZ_ALARM_DEVICE_MSG_NOTIFY        0x3199           // Event for device sending notification to platform (corresponds to struct ALARM_DEVICE_MSG_NOTIFY_INFO)
#define ZZ_ALARM_VEHICLE_STANDING_OVER_TIME 0x319A         // Vehicle standing over time alarm (corresponds to struct ALARM_VEHICLE_STANDING_OVER_TIME_INFO)
#define ZZ_ALARM_ENCLOSURE_ALARM          0x319B           // Enclosure alarm event (corresponds to struct ALARM_ENCLOSURE_ALARM_INFO)
#define ZZ_ALARM_GUARD_DETECT             0x319C           // Guard detect event, reports start event when first person enters booth, reports stop event when last person leaves (corresponds to struct ALARM_GUARD_DETECT_INFO)
#define ZZ_ALARM_GUARD_INFO_UPDATE        0x319D           // Guard info update event, reports whenever person enters/exits booth (corresponds to struct ALARM_GUARD_UPDATE_INFO)  
#define ZZ_ALARM_NODE_ACTIVE              0x319E           // Node active event (corresponds to struct ALARM_NODE_ACTIVE_INFO)
#define ZZ_ALARM_VIDEO_STATIC             0x319F           // Video static detection event (corresponds to struct ALARM_VIDEO_STATIC_INFO)
#define ZZ_ALARM_REGISTER_REONLINE        0x31a0           // Active register device re-online event (corresponds to struct ALARM_REGISTER_REONLINE_INFO)
#define ZZ_ALARM_ISCSI_STATUS             0x31a1           // ISCSI status alarm event (corresponds to struct ALARM_ISCSI_STATUS_INFO)
#define ZZ_ALARM_SCADA_DEV_ALARM          0x31a2           // SCADA device alarm event (corresponds to struct ALARM_SCADA_DEV_INFO)
#define ZZ_ALARM_AUXILIARY_DEV_STATE      0x31a3           // Auxiliary device state (corresponds to struct ALARM_AUXILIARY_DEV_STATE)
#define ZZ_ALARM_PARKING_CARD             0x31a4           // Parking card swipe event (corresponds to struct ALARM_PARKING_CARD)
#define ZZ_ALARM_PROFILE_ALARM_TRANSMIT   0x31a5           // Alarm transmit event (corresponds to struct ALARM_PROFILE_ALARM_TRANSMIT_INFO)
#define ZZ_ALARM_VEHICLE_ACC              0x31a6           // Vehicle ACC alarm event (corresponds to struct ALARM_VEHICLE_ACC_INFO)
#define ZZ_ALARM_TRAFFIC_SUSPICIOUSCAR    0x31a7           // Suspicious car report event (corresponds to struct ALARM_TRAFFIC_SUSPICIOUSCAR_INFO)
#define ZZ_ALARM_ACCESS_LOCK_STATUS       0x31a8           // Lock status event (corresponds to struct ALARM_ACCESS_LOCK_STATUS_INFO)
#define ZZ_ALARM_FINACE_SCHEME            0x31a9           // Finance scheme event (corresponds to struct ALARM_FINACE_SCHEME_INFO)
#define ZZ_ALARM_HEATIMG_TEMPER           0x31aa           // Thermal imaging temperature abnormal alarm event (corresponds to struct ALARM_HEATIMG_TEMPER_INFO)
#define ZZ_ALARM_TALKING_IGNORE_INVITE    0x31ab           // Device cancel talk invite event (corresponds to struct ALARM_TALKING_IGNORE_INVITE_INFO)
#define ZZ_ALARM_BUS_SHARP_TURN           0x31ac           // Bus sharp turn event (corresponds to struct ALARM_BUS_SHARP_TURN_INFO)
#define ZZ_ALARM_BUS_SCRAM                0x31ad           // Bus scram event (corresponds to struct ALARM_BUS_SCRAM_INFO)
#define ZZ_ALARM_BUS_SHARP_ACCELERATE     0x31ae           // Bus sharp accelerate event (corresponds to struct ALARM_BUS_SHARP_ACCELERATE_INFO)
#define ZZ_ALARM_BUS_SHARP_DECELERATE     0x31af           // Bus sharp decelerate event (corresponds to struct ALARM_BUS_SHARP_DECELERATE_INFO)
#define ZZ_ALARM_ACCESS_CARD_OPERATE      0x31b0           // Access card operate event (corresponds to struct ALARM_ACCESS_CARD_OPERATE_INFO)
#define ZZ_ALARM_POLICE_CHECK             0x31b1           // Police check event (corresponds to struct ALARM_POLICE_CHECK_INFO)
#define ZZ_ALARM_NET                      0x31b2           // Network alarm event (corresponds to struct ALARM_NET_INFO)
#define ZZ_ALARM_NEW_FILE                 0x31b3           // New file event (corresponds to struct ALARM_NEW_FILE_INFO)
#define ZZ_ALARM_FIREWARNING              0x31b5           // Thermal fire warning event (corresponds to struct ALARM_FIREWARNING_INFO)
#define ZZ_ALARM_RECORD_LOSS              0x31b6           // Record loss event, indicates HDD is good but record lost due to deletion etc. (corresponds to struct ALARM_RECORD_LOSS_INFO)
#define ZZ_ALARM_VIDEO_FRAME_LOSS         0x31b7           // Video frame loss event, caused by bad network or insufficient encoding capability (corresponds to struct ALARM_VIDEO_FRAME_LOSS_INFO)
#define ZZ_ALARM_RECORD_VOLUME_FAILURE    0x31b8           // Record exception caused by disk volume failure (corresponds to struct ALARM_RECORD_VOLUME_FAILURE_INFO)
#define ZZ_EVENT_SNAP_UPLOAD              0x31b9           // Image upload complete event (corresponds to struct EVENT_SNAP_UPLOAD_INFO)
#define ZZ_ALARM_AUDIO_DETECT             0x31ba           // Audio detection event (corresponds to struct ALARM_AUDIO_DETECT)
#define ZZ_ALARM_UPLOADPIC_FAILCOUNT      0x31bb           // Upload fail count info (corresponds to struct ALARM_UPLOADPIC_FAILCOUNT_INFO)
#define ZZ_ALARM_POS_MANAGE               0x31bc           // POS manage event (corresponds to struct ALARM_POS_MANAGE_INFO)
#define ZZ_ALARM_REMOTE_CTRL_STATUS       0x31bd           // Wireless remote control status event (corresponds to struct ALARM_REMOTE_CTRL_STATUS)
#define ZZ_ALARM_PASSENGER_CARD_CHECK     0x31be           // Deprecated, Passenger card check event (corresponds to struct ALARM_PASSENGER_CARD_CHECK)
#define ZZ_ALARM_SOUND                    0x31bf           // Sound event (corresponds to struct ALARM_SOUND)
#define ZZ_ALARM_LOCK_BREAK               0x31c0           // Lock break event (corresponds to struct ALARM_LOCK_BREAK_INFO)
#define ZZ_ALARM_HUMAN_INSIDE             0x31c1           // Human inside cabin event (corresponds to struct ALARM_HUMAN_INSIDE_INFO)
#define ZZ_ALARM_HUMAN_TUMBLE_INSIDE      0x31c2           // Human tumble inside cabin event (corresponds to struct ALARM_HUMAN_TUMBLE_INSIDE_INFO)
#define ZZ_ALARM_DISABLE_LOCKIN           0x31c3           // Disable lock-in button trigger event (corresponds to ALARM_DISABLE_LOCKIN_INFO)
#define ZZ_ALARM_DISABLE_LOCKOUT          0x31c4           // Disable lock-out button trigger event (corresponds to struct ALARM_DISABLE_LOCKOUT_INFO)
#define ZZ_ALARM_UPLOAD_PIC_FAILED        0x31c5           // Violation data upload failed event (corresponds to struct ALARM_UPLOAD_PIC_FAILED_INFO)
#define ZZ_ALARM_FLOW_METER               0x31c6           // Flow meter statistic info upload event (corresponds to struct ALARM_FLOW_METER_INFO)
#define ZZ_ALARM_WIFI_SEARCH              0x31c7           // Found WIFI device in environment upload event (corresponds to struct ALARM_WIFI_SEARCH_INFO)
#define ZZ_ALARM_WIRELESSDEV_LOWPOWER     0x31C8           // Wireless device low power upload event (corresponds to struct ALARM_WIRELESSDEV_LOWPOWER_INFO)
#define ZZ_ALARM_PTZ_DIAGNOSES            0x31c9           // PTZ diagnoses event (corresponds to struct ALARM_PTZ_DIAGNOSES_INFO)
#define ZZ_ALARM_FLASH_LIGHT_FAULT        0x31ca           // Flash light fault alarm event (corresponds to struct ALARM_FLASH_LIGHT_FAULT_INFO)
#define ZZ_ALARM_STROBOSCOPIC_LIGTHT_FAULT   0x31cb        // Stroboscopic light fault alarm event (corresponds to struct ALARM_STROBOSCOPIC_LIGTHT_FAULT_INFO)
#define ZZ_ALARM_HUMAM_NUMBER_STATISTIC   0x31cc           // Human number statistic event (corresponds to struct ALARM_HUMAN_NUMBER_STATISTIC_INFO)
#define ZZ_ALARM_VIDEOUNFOCUS             0x31ce           // Video unfocus alarm (corresponds to struct ALARM_VIDEOUNFOCUS_INFO)
#define ZZ_ALARM_BUF_DROP_FRAME           0x31cd           // Record buffer drop frame event (corresponds to struct ALARM_BUF_DROP_FRAME_INFO)
#define ZZ_ALARM_DOUBLE_DEV_VERSION_ABNORMAL 0x31cf        // Double device version abnormal event (corresponds to struct ALARM_DOUBLE_DEV_VERSION_ABNORMAL_INFO)
#define ZZ_ALARM_DCSSWITCH                 0x31d0          // Master-slave switch event, Cluster switch alarm (corresponds to struct ALARM_DCSSWITCH_INFO)
#define ZZ_ALARM_RADAR_CONNECT_STATE       0x31d1          // Radar connection state event (corresponds to struct ALARM_RADAR_CONNECT_STATE_INFO)
#define ZZ_ALARM_DEFENCE_ARMMODE_CHANGE    0x31d2          // Defence arm mode change event (corresponds to struct ALARM_DEFENCE_ARMMODECHANGE_INFO)
#define ZZ_ALARM_SUBSYSTEM_ARMMODE_CHANGE  0x31d3          // Subsystem arm mode change event (corresponds to struct ALARM_SUBSYSTEM_ARMMODECHANGE_INFO)
#define ZZ_ALARM_RFID_INFO                 0x31d4          // RFID info event (corresponds to struct ALARM_RFID_INFO)
#define ZZ_ALARM_SMOKE_DETECTION           0x31d5          // Smoke detection event (corresponds to struct ALARM_SMOKE_DETECTION_INFO)
#define ZZ_ALARM_BETWEENRULE_TEMP_DIFF     0x31d6          // Thermal imaging between-rule temperature difference abnormal alarm (corresponds to struct ALARM_BETWEENRULE_DIFFTEMPER_INFO)
#define ZZ_ALARM_TRAFFIC_PIC_ANALYSE       0x31d7          // Picture secondary analysis event (corresponds to ALARM_PIC_ANALYSE_INFO)
#define ZZ_ALARM_HOTSPOT_WARNING           0x31d8          // Thermal hotspot warning (corresponds to struct ALARM_HOTSPOT_WARNING_INFO)
#define ZZ_ALARM_COLDSPOT_WARNING          0x31d9          // Thermal coldspot warning (corresponds to struct ALARM_COLDSPOT_WARNING_INFO)
#define ZZ_ALARM_FIREWARNING_INFO          0x31da          // Thermal fire warning info upload (corresponds to struct ALARM_FIREWARNING_INFO_DETAIL)
#define ZZ_ALARM_FACE_OVERHEATING          0x31db          // Thermal face overheating warning (corresponds to struct ALARM_FACE_OVERHEATING_INFO)
#define ZZ_ALARM_SENSOR_ABNORMAL           0x31dc          // Detector abnormal alarm (corresponds to struct ALARM_SENSOR_ABNORMAL_INFO)
#define ZZ_ALARM_PATIENTDETECTION          0x31de          // Patient activity status alarm event (corresponds to struct ALARM_PATIENTDETECTION_INFO)
#define ZZ_ALARM_RADAR_HIGH_SPEED          0x31df          // Radar high speed alarm event (corresponds to struct ALARM_RADAR_HIGH_SPEED_INFO)
#define ZZ_ALARM_POLLING_ALARM             0x31e0          // Device polling alarm event (corresponds to struct ALARM_POLLING_ALARM_INFO)
#define ZZ_ALARM_ITC_HWS000                0x31e1          // ITC HWS000 device event and alarm (corresponds to struct ALARM_ITC_HWS000)
#define ZZ_ALARM_TRAFFICSTROBESTATE        0x31e2          // Traffic strobe state event (corresponds to struct ALARM_TRAFFICSTROBESTATE_INFO)
#define ZZ_ALARM_TELEPHONE_CHECK           0x31e3          // Telephone check upload event (corresponds to struct ALARM_TELEPHONE_CHECK_INFO)
#define ZZ_ALARM_PASTE_DETECTION           0x31e4          // Paste detection event (corresponds to struct ALARM_PASTE_DETECTION_INFO)
#define ZZ_ALARM_SHOOTINGSCORERECOGNITION  0x31e5          // Shooting score recognition event (corresponds to struct ALARM_PIC_SHOOTINGSCORERECOGNITION_INFO)
#define ZZ_ALARM_SWIPEOVERTIME             0x31e6          // Swipe overtime event (corresponds to struct ALARM_SWIPE_OVERTIME_INFO)
#define ZZ_ALARM_DRIVING_WITHOUTCARD       0x31e7          // Driving without card event (corresponds to struct ALARM_DRIVING_WITHOUTCARD_INFO)
#define ZZ_ALARM_TRAFFIC_PEDESTRIAN_RUN_REDLIGHT_DETECTION 0x31e8  // Pedestrian run red light event (corresponds to struct ALARM_TRAFFIC_PEDESTRIAN_RUN_REDLIGHT_DETECTION_INFO)
#define ZZ_ALARM_FIGHTDETECTION            0x31e9          // Fight detection event (corresponds to struct NET_ALARM_FIGHTDETECTION)
#define ZZ_ALARM_OIL_4G_OVERFLOW           0x31ea          // Fushan oilfield 4G flow overflow alarm event (corresponds to struct NET_ALARM_OIL_4G_OVERFLOW_INFO)
#define ZZ_ALARM_ACCESSIDENTIFY            0x31eb          // VTO face identify event (corresponds to struct NET_ALARM_ACCESSIDENTIFY)
#define ZZ_ALARM_POWER_SWITCHER_ALARM      0x31ec          // Power switcher abnormal alarm event (corresponds to struct DEV_ALRAM_POWERSWITCHER_INFO)
#define ZZ_ALARM_SCENNE_CHANGE_ALARM       0x31ed          // Scene change event (corresponds to struct ALARM_PIC_SCENECHANGE_INFO)
#define ZZ_ALARM_WIFI_VIRTUALINFO_SEARCH   0x31ef          // WIFI virtual info search event (corresponds to struct ALARM_WIFI_VIRTUALINFO_SEARCH_INFO)
#define ZZ_ALARM_TRAFFIC_OVERSPEED         0x31f0          // Traffic overspeed event (corresponds to struct ALARM_TRAFFIC_OVERSPEED_INFO)
#define ZZ_ALARM_TRAFFIC_UNDERSPEED        0x31f1          // Traffic underspeed event (corresponds to struct ALARM_TRAFFIC_UNDERSPEED_INFO)
#define ZZ_ALARM_TRAFFIC_PEDESTRAIN        0x31f2          // Traffic pedestrian event (corresponds to struct ALARM_TRAFFIC_PEDESTRAIN_INFO)
#define ZZ_ALARM_TRAFFIC_JAM               0x31f3          // Traffic jam event (corresponds to struct ALARM_TRAFFIC_JAM)
#define ZZ_ALARM_TRAFFIC_PARKING           0x31f4          // Illegal parking event (corresponds to struct ALARM_TRAFFIC_PARKING_INFO)
#define ZZ_ALARM_TRAFFIC_THROW             0x31f5          // Traffic throw event (corresponds to struct ALARM_TRAFFIC_THROW_INFO)
#define ZZ_ALARM_TRAFFIC_RETROGRADE        0x31f6          // Traffic retrograde event (corresponds to struct ALARM_TRAFFIC_RETROGRADE_INFO)
#define ZZ_ALARM_VTSTATE_UPDATE            0x31f7          // VTS state update (corresponds to struct ALARM_VTSTATE_UPDATE_INFO)
#define ZZ_ALARM_CALL_NO_ANSWERED          0x31f8          // Call no answered event (corresponds to struct NET_ALARM_CALL_NO_ANSWERED_INFO)
#define ZZ_ALARM_USER_LOCK_EVENT           0x31f9          // User lock alarm event
#define ZZ_ALARM_RETROGRADE_DETECTION      0x31fa          // Retrograde detection event (corresponds to struct ALARM_RETROGRADE_DETECTION_INFO)
#define ZZ_ALARM_AIO_APP_CONFIG_EVENT      0x31fb          // AIO app config event (corresponds to struct ALARM_AIO_APP_CONFIG_EVENT)
#define ZZ_ALARM_RAID_STATE_EX             0x31fc          // RAID state exception alarm (corresponds to struct ALARM_RAID_INFO_EX)
#define ZZ_ALARM_STORAGE_IPC_FAILURE       0x31fd          // IPC storage failure event (IPC SD card abnormal) (corresponds to struct ALARM_STORAGE_IPC_FAILURE_INFO)
#define ZZ_ALARM_DEVICE_STAY               0x31fe          // Device stay alarm, triggered if device coordinates do not change within specified time (corresponds to struct ALARM_DEVICE_STAY_INFO)
#define ZZ_ALARM_SUB_WAY_DOOR_STATE        0x31ff          // Subway door state (corresponds to struct ALARM_SUB_WAY_DOOR_STATE_INFO)
#define ZZ_ALARM_SUB_WAY_PECE_SWITCH       0x3200          // Subway PECE switch state (corresponds to struct ALARM_SUB_WAY_PECE_SWITCH_INFO)
#define ZZ_ALARM_SUB_WAY_FIRE_ALARM        0x3201          // Subway fire alarm event (corresponds to struct ALARM_SUB_WAY_FIRE_ALARM_INFO)
#define ZZ_ALARM_SUB_WAY_EMER_HANDLE       0x3202          // Subway emergency handle action (corresponds to struct ALARM_SUB_WAY_EMER_HANDLE_INFO)
#define ZZ_ALARM_SUB_WAY_CAB_COVER         0x3203          // Subway cab cover state (corresponds to struct ALARM_SUB_WAY_CAB_COVER_INFO)
#define ZZ_ALARM_SUB_WAY_DERA_OBST         0x3204          // Subway derailment/obstacle detection (corresponds to struct ALARM_SUB_WAY_DERA_OBST_INFO)
#define ZZ_ALARM_SUB_WAY_PECU_CALL         0x3205          // Subway PECU call state (corresponds to struct ALARM_SUB_WAY_PECU_CALL_INFO)
#define ZZ_ALARM_BOX                       0x3206          // Alarm box alarm event (corresponds to struct ALARM_BOX_INFO)
#define ZZ_ALARM_DOOR_CLOSEDMANUALLY       0x3207          // Door closed manually event (corresponds to struct ALARM_DOOR_CLOSEDMANUALLY_INFO)
#define ZZ_ALARM_DOOR_NOTCLOSED_LONGTIME   0x3208          // Door not closed for long time alarm event (corresponds to struct ALARM_DOOR_NOTCLOSED_LONGTIME_INFO)
#define ZZ_ALARM_UNDER_VOLTAGE             0x3209          // Voltage under 9V, power under voltage alarm, OSD icon overlay (corresponds to struct ALARM_UNDER_VOLTAGE_INFO)
#define ZZ_ALARM_OVER_VOLTAGE              0x320a          // Voltage over 19V, power over voltage alarm, OSD icon overlay (corresponds to struct ALARM_OVER_VOLTAGE_INFO)
#define ZZ_ALARM_CUT_LINE                  0x320b          // Cut line alarm (corresponds to struct ALARM_CUT_LINE_INFO)
#define ZZ_ALARM_VIDEOMOTION_EVENT         0x320c          // Video motion event (corresponds to struct ALARM_VIDEOMOTION_EVENT_INFO)
#define ZZ_ALARM_WIDE_VIEW_REGION_EVENT    0x320d          // WideViewRegions event (corresponds to struct ALARM_WIDE_VIEW_REGION_EVENT_INFO)
#define ZZ_ALARM_FIBRE_OPTIC_ABORT         0x320e          // Fiber optic abort alarm (corresponds to struct ALARM_FIBRE_OPTIC_ABORT)
#define ZZ_ALARM_TAIL_DETECTION            0x320f          // Tail detection event (corresponds to struct ALARM_TAIL_DETECTION_INFO)
#define ZZ_ALARM_BITRATES_OVERLIMIT        0x3210          // Bitrates overlimit alarm (corresponds to struct ALARM_BITRATES_OVERLIMIT_INFO)
#define ZZ_ALARM_RECORD_CHANGED_EX         0x3211          // Record status changed alarm (corresponds to struct ALARM_RECORD_CHANGED_INFO_EX)
#define ZZ_ALARM_HIGH_DECIBEL              0x3212          // High decibel detection alarm (corresponds to struct ALARM_HIGH_DECIBEL_INFO)
#define ZZ_ALARM_SHAKE_DETECTION           0x3213          // Shake detection alarm (corresponds to struct ALARM_SHAKE_DETECTION_INFO)
#define ZZ_ALARM_TUMBLE_DETECTION          0x3214          // Tumble detection alarm event (corresponds to struct ALARM_TUMBLE_DETECTION_INFO)
#define ZZ_ALARM_ACCESS_CTL_MALICIOUS      0x3215          // Malicious access event (corresponds to struct ALARM_ACCESS_CTL_MALICIOUS)
#define ZZ_ALARM_ACCESS_CTL_USERID_REGISTER 0x3216         // User ID register event (corresponds to struct ALARM_ACCESS_CTL_USERID_REGISTER)
#define ZZ_ALARM_ACCESS_CTL_REVERSELOCK    0x3217          // Reverse lock state change event (corresponds to struct ALARM_ACCESS_CTL_REVERSELOCK)
#define ZZ_ALARM_ACCESS_CTL_USERID_DELETE  0x3218          // User ID delete event (corresponds to struct ALARM_ACCESS_CTL_USERID_DELETE)
#define ZZ_ALARM_ACCESS_DOOR_BELL          0x3219          // Door bell event (corresponds to struct ALARM_ACCESS_DOOR_BELL_INFO)
#define ZZ_ALARM_ACCESS_FACTORY_RESET      0x321a          // Access factory reset (corresponds to struct ALARM_ACCESS_FACTORY_RESET)
#define ZZ_ALARM_POLICE_RECORD_PROGRESS    0x321b          // Police record progress event (corresponds to struct ALARM_POLICE_RECORD_PROGRESS_INFO)
#define ZZ_ALARM_POLICE_PLUGIN             0x321c          // Police plugin event (corresponds to struct ALARM_POLICE_PLUGIN_INFO)
#define ZZ_ALARM_GPS_NOT_ALIGNED           0x321d          // GPS not aligned alarm (corresponds to struct ALARM_GPS_NOT_ALIGNED_INFO)
#define ZZ_ALARM_WIRELESS_NOT_CONNECTED    0x321e          // Wireless not connected alarm (corresponds to struct ALARM_WIRELESS_NOT_CONNECTED_INFO)
#define ZZ_ALARM_CABINET                   0x321f          // Cabinet event (corresponds to struct ALARM_CABINET_INFO)
#define ZZ_SWITCH_SCREEN                   0x3220          // Switch screen event
#define ZZ_ALARM_NEAR_DISTANCE_DETECTION   0x3221            // Near distance detection alarm (corresponds to struct ALARM_NEAR_DISTANCE_INFO)
#define ZZ_ALARM_MAN_STAND_DETECTION       0x3222            // Man stand detection alarm (corresponds to struct ALARM_MAN_STAND_INFO)
#define ZZ_ALARM_MAN_NUM_DETECTION         0x3223            // Man num detection alarm (corresponds to struct ALARM_MAN_NUM_INFO)
#define ZZ_MCS_GENERAL_CAPACITY_LOW        0x3224            // MCS general capacity low (corresponds to struct ALARM_MCS_GENERAL_CAPACITY_LOW_INFO)
#define ZZ_MCS_DATA_NODE_OFFLINE           0x3225            // MCS data node offline (corresponds to struct ALARM_MCS_DATA_NODE_OFFLINE_INFO)
#define ZZ_MCS_DISK_OFFLINE                0x3226            // MCS disk offline (corresponds to struct ALARM_MCS_DISK_OFFLINE_INFO)
#define ZZ_MCS_DISK_SLOW                   0x3227            // MCS disk slow (corresponds to struct ALARM_MCS_DISK_SLOW_INFO)
#define ZZ_MCS_DISK_BROKEN                 0x3228            // MCS disk broken (corresponds to struct ALARM_MCS_DISK_BROKEN_INFO)
#define ZZ_MCS_DISK_UNKNOW_ERROR           0x3229            // MCS disk unknown error (corresponds to struct ALARM_MCS_DISK_UNKNOW_ERROR_INFO)
#define ZZ_MCS_METADATA_SERVER_ABNORMAL    0x322a            // MCS metadata server abnormal (corresponds to struct ALARM_MCS_METADATA_SERVER_ABNORMAL_INFO)
#define ZZ_MCS_CATALOG_SERVER_ABNORMAL     0x322b            // MCS catalog server abnormal (corresponds to struct ALARM_MCS_CATALOG_SERVER_ABNORMAL_INFO)
#define ZZ_MCS_GENERAL_CAPACITY_RESUME     0x322c            // MCS general capacity resume (corresponds to struct ALARM_MCS_GENERAL_CAPACITY_RESUME_INFO)
#define ZZ_MCS_DATA_NODE_ONLINE            0x322d            // MCS data node online (corresponds to struct ALARM_MCS_DATA_NODE_ONLINE_INFO)
#define ZZ_MCS_DISK_ONLINE                 0x322e            // MCS disk online (corresponds to struct ALARM_MCS_DISK_ONLINE_INFO)
#define ZZ_MCS_METADATA_SLAVE_ONLINE       0x322f            // MCS metadata slave online (corresponds to struct ALARM_MCS_METADATA_SLAVE_ONLINE_INFO)
#define ZZ_MCS_CATALOG_SERVER_ONLINE       0x3230            // MCS catalog server online (corresponds to struct ALARM_MCS_CATALOG_SERVER_ONLINE_INFO)
#define ZZ_ALARM_OFFLINE_LOGSYNC           0x3231            // Offline log sync event (corresponds to struct ALARM_OFFLINE_LOGSYNC_INFO)
#define ZZ_ALARM_UPGRADE_STATE             0x3232            // Device upgrade state event (corresponds to struct ALARM_UPGRADE_STATE)
#define ZZ_ALARM_LABELINFO                 0x3233            // RFID label info event (corresponds to struct ALARM_LABELINFO)
#define ZZ_ALARM_TIRED_PHYSIOLOGICAL       0x3234            // Physiological tired event (corresponds to struct ALARM_TIRED_PHYSIOLOGICAL)
#define ZZ_ALARM_CALLING_WHEN_DRIVING      0x3235            // Calling when driving event (corresponds to struct ALARM_CALLING_WHEN_DRIVING)
#define ZZ_ALARM_TRAFFIC_DRIVER_SMOKING    0x3236            // Driver smoking event (corresponds to struct ALARM_TRAFFIC_DRIVER_SMOKING)
#define ZZ_ALARM_TRAFFIC_DRIVER_LOWER_HEAD 0x3237            // Driver lower head event (corresponds to struct ALARM_TRAFFIC_DRIVER_LOWER_HEAD)
#define ZZ_ALARM_TRAFFIC_DRIVER_LOOK_AROUND     0x3238       // Driver look around event (corresponds to struct ALARM_TRAFFIC_DRIVER_LOOK_AROUND)
#define ZZ_ALARM_TRAFFIC_DRIVER_LEAVE_POST      0x3239       // Driver leave post event (corresponds to struct ALARM_TRAFFIC_DRIVER_LEAVE_POST)
#define ZZ_ALARM_TRAFFIC_DRIVER_YAWN            0x323a       // Driver yawn event (corresponds to struct ALARM_TRAFFIC_DRIVER_YAWN)
#define ZZ_ALARM_AUTO_INSPECTION                0x323b       // Device auto inspection event (corresponds to struct ALARM_AUTO_INSPECTION) 
#define ZZ_ALARM_TRAFFIC_VEHICLE_POSITION       0x323c       // Traffic vehicle position event (corresponds to struct ALARM_TRAFFIC_VEHICLE_POSITION)
#define ZZ_ALARM_FACE_VERIFICATION_ACCESS_SNAP  0x323d       // Face verification access snap event (corresponds to struct ALARM_FACE_VERIFICATION_ACCESS_SNAP_INFO) 
#define ZZ_ALARM_VIDEOBLIND                0x323e            // Video blind event (corresponds to struct ALARM_VIDEO_BLIND_INFO)
#define ZZ_ALARM_DRIVER_NOTCONFIRM         0x323f            // Driver not confirm alarm event (corresponds to struct ALARM_DRIVER_NOTCONFIRM_INFO)
#define ZZ_ALARM_FACEINFO_COLLECT          0x3240            // Face info collect event (corresponds to ALARM_FACEINFO_COLLECT_INFO)
#define ZZ_ALARM_HIGH_SPEED	               0x3241			 // High speed alarm event (corresponds to ALARM_HIGH_SPEED_INFO)
#define ZZ_ALARM_VIDEO_LOSS                0x3242			 // Video loss event (corresponds to ALARM_VIDEO_LOSS_INFO)
#define ZZ_ALARM_MPTBASE_CONNECT           0x3243			 // MPT base connect status event (corresponds to struct ALARM_MPTBASE_CONNECT) 
#define ZZ_ALARM_LATEST_SHUTDOWN           0x3244			 // Latest shutdown status event (corresponds to struct ALARM_LATEST_SHUTDOWN)


// ------------- Robot Specific Events ------------------
#define ZZ_ALARM_ROBOT_COLLISION	        0x3245			// Robot collision event (corresponds to struct ALARM_ROBOT_COLLISION)
#define ZZ_ALARM_ROBOT_FALLENDOWN		    0x3246			// Robot fallen down event (corresponds to struct ALARM_ROBOT_FALLENDOWN)
#define ZZ_ALARM_ROBOT_UNRECOGNIZED2DCODE   0x3247			// Robot unrecognized 2D code event (corresponds to struct ALARM_ROBOT_UNRECOGNIZED2DCODE) 
#define ZZ_ALARM_ROBOT_WRONG2DCODE	        0x3248			// Robot wrong 2D code event (corresponds to struct ALARM_ROBOT_WRONG2DCODE)
#define ZZ_ALARM_ROBOT_ROADBLOCKED	        0x3249		    // Robot road blocked event (corresponds to struct ALARM_ROBOT_ROADBLOCKED) 
#define ZZ_ALARM_ROBOT_FAULT				0x324a			// Robot fault event (corresponds to struct ALARM_ROBOT_FAULT)
#define ZZ_ALARM_ROBOT_OVERLOAD			    0x324b			// Robot overload event (corresponds to struct ALARM_ROBOT_OVERLOAD)
#define ZZ_ALARM_ROBOT_YAWEXCEPTION		    0x324c			// Robot yaw exception event (corresponds to ALARM_ROBOT_YAWEXCEPTION)
#define ZZ_ALARM_ROBOT_LOADTIMEOUT		    0x324e			// Robot load timeout event (corresponds to ALARM_ROBOT_LOADTIMEOUT )
#define ZZ_ALARM_ROBOT_UNLOADTIMEOUT		0x324f			// Robot unload timeout event (corresponds to ALARM_ROBOT_UNLOADTIMEOUT)
#define ZZ_ALARM_ROBOT_MAPUPDATE		    0x3250			// Robot map update event (corresponds to ALARM_ROBOT_MAPUPDATE)
#define	ZZ_ALARM_ROBOT_BRAKE				0x3252			// Robot brake event (corresponds to ALARM_ROBOT_BRAKE)
#define	ZZ_ALARM_ROBOT_MANUAL_INTERVENTION	0x3253			// Robot manual intervention event (corresponds to ALARM_ROBOT_MANUAL_INTERVENTION)
//Robot events reserved until 0x3299
// -----------------------------------------------


#define ZZ_ALARM_VIDEO_TALK_PATH		    0x324d			// Video talk path event (corresponds to struct ALARM_VIDEO_TALK_PATH_INFO)
#define ZZ_ALARM_CGIRECORD                  0x3251          // CGI record event (corresponds to ALARM_CGIRECORD)
#define ZZ_ALARM_BATTERY_TEMPERATURE	    0x3254			// Battery temperature upload event (corresponds to ALARM_BATTERY_TEMPERATURE_INFO)
#define ZZ_ALARM_TIRE_PRESSURE	            0x3255			// Tire pressure upload event (corresponds to ALARM_TIRE_PRESSURE_INFO )
#define ZZ_ALARM_VTH_CONFLICT				0x3256			// VTH conflict upload event (corresponds to ALARM_VTH_CONFLICT_INFO)
#define ZZ_ALARM_ACCESS_CTL_BLACKLIST       0x3257          // Access control blacklist event (corresponds to ALARM_ACCESS_CTL_BLACKLIST)
#define ZZ_ALARM_ROBOT_EMERGENCY_STOP		0x3258			// Robot emergency stop event (corresponds to ALARM_ROBOT_EMERFEBCY_STOP)
#define	ZZ_ALARM_ROBOT_PATH_PLAN_FAILED		0x3259			// Robot path plan failed event (corresponds to ALARM_ROBOT_PATH_PLAN_FAILED)
#define ZZ_ALARM_ROBOT_LOCAL_MAP_UPLOAD		0x325a			// Robot local map upload event (corresponds to ALARM_ROBOT_LOCAL_MAP_UPLOAD)
#define	ZZ_ALARM_ROBOT_SHELF_ERROR	        0x325b			// Robot shelf error event (corresponds to ALARM_ROBOT_SHELF_ERROR)
#define	ZZ_ALARM_ROBOT_SENSOR_ERROR	        0x325c			// Robot sensor error event (corresponds to ALARM_ROBOT_SENSOR_ERROR)
#define ZZ_ALARM_ROBOT_DERAILMENT           0x325d          // Robot derailment event (corresponds to ALARM_ROBOT_DERAILMENT)
#define ZZ_ALARM_ROBOT_MOTOR_UNINIT         0x325e          // Robot motor uninit event (corresponds to ALARM_ROBOT_MOTOR_UNINIT)
#define ZZ_ALARM_ROBOT_PREVENT_FALLING      0x325f          // Robot prevent falling event (corresponds to ALARM_ROBOT_PREVENT_FALLING)
#define ZZ_ALARM_ROBOT_LOCATION_EXCEPTION   0x3260			// Robot location exception event (corresponds to ALARM_ROBOT_LOCATION_EXCEPTION )
#define ZZ_ALARM_ROBOT_UPGRADER_FAIL        0x3261          // Robot upgrade fail feedback (corresponds to ALARM_ROBOT_UPGRADER_FAIL)
#define ZZ_ALARM_ROBOT_CHARGING_ERROR       0x3262          // Robot charging error event (corresponds to ALARM_ROBOT_CHARGING_ERROR)
#define ZZ_ALARM_ROBOT_STATIONCHARGING_ERROR       0x3263   // Robot station charging error event (corresponds to ALARM_ROBOT_STATIONCHARGING_ERROR)


//New events start from 0x3300
#define ZZ_ALARM_USERLOCK					0x3300			// User lock alarm event (corresponds to ALARM_USERLOCK_INFO)
#define ZZ_ALARM_DOWNLOAD_REMOTE_FILE		0x3301			// Download remote file event (corresponds to ALARM_DOWNLOAD_REMOTE_FILE_INFO)
#define ZZ_ALARM_NASFILE_STATUS             0x3302			// NAS file status event (corresponds to struct ALARM_NASFILE_STATUS_INFO) 
#define ZZ_ALARM_TALKING_CANCELCALL         0x3303          // Talking cancel call event (corresponds to struct ALARM_TALKING_CANCELCALL_INFO)
#define ZZ_ALARM_ACCESS_CTL_UNAUTHORIZED_MALICIOUSWIP      0x3304 // Unauthorized malicious swipe event (corresponds to struct ALARM_ACCESS_CTL_UNAUTHORIZED_MALICIOUSWIP) 
#define ZZ_ALARM_CROWD_DETECTION			0x3305			// Crowd detection event (corresponds to struct ALARM_CROWD_DETECTION_INFO)
#define ZZ_ALARM_FACE_FEATURE_ABSTRACT		0x3306			// Face feature abstract event (corresponds to struct ALARM_FACE_FEATURE_ABSTRACT_INFO)
#define	ZZ_ALARM_RECORD_SCHEDULE_CHANGE		0x3307			// Record schedule change event (corresponds to struct ALARM_RECORD_SCHEDULE_CHANGE_INFO)
#define ZZ_ALARM_NTP_CHANGE					0x3308			// NTP change event (corresponds to struct ALARM_NTP_CHANGE_INFO)

// Event Types
#define ZZ_CONFIG_RESULT_EVENT_EX           0x3000           // Modify config result code; returned structure DEV_SET_RESULT
#define ZZ_REBOOT_EVENT_EX                  0x3001           // Device reboot event; config won't take effect until reboot command sent
#define ZZ_AUTO_TALK_START_EX               0x3002           // Device proactively starts voice talk
#define ZZ_AUTO_TALK_STOP_EX                0x3003           // Device proactively stops voice talk
#define ZZ_CONFIG_CHANGE_EX                 0x3004           // Device config changed
#define ZZ_IPSEARCH_EVENT_EX                0x3005           // IP search event, return string format: DevName::Manufacturer::MAC::IP::Port::DevType::POEPort::SubMask::GateWay&&...
#define ZZ_AUTO_RECONNECT_FAILD             0x3006           // Auto reconnect failed event
#define ZZ_REALPLAY_FAILD_EVENT             0x3007           // Monitor failed event, return structure DEV_PLAY_RESULT
#define ZZ_PLAYBACK_FAILD_EVENT             0x3008           // Playback failed event, return structure DEV_PLAY_RESULT   
#define ZZ_IVS_TRAFFIC_REALFLOWINFO         0x3009           // Traffic real flow info event ALARM_IVS_TRAFFIC_REALFLOW_INFO
#define ZZ_DEVICE_ABORT_EVENT               0x300a           // Client kicked out, corresponds to structure DEV_CLIENT_ABORT_INFO
#define ZZ_TALK_FAILD_EVENT                 0x300b           // Request voice talk failed, corresponds to structure DEV_TALK_RESULT
#define ZZ_START_LISTEN_FINISH_EVENT        0x300c           // Subscribe event interface async notify complete, info is NULL
#define ZZ_YUEQINGLIGHTING_STATE_EVENT      0x300d           // Platform statistics lighting switch time event, corresponding structure DEV_YUEQINGLIGHTING_STATE_INFO
#define ZZ_ALARM_VIOLATE_NO_FLY_TIME        0x300e           // Violate no fly time event, corresponds to structure ALARM_VIOLATE_NO_FLY_TIME_INFO              
#define ZZ_ALARM_BOX_ALARM			        0x300f		    // Alarm box channel triggered alarm event (corresponds to structure ALARM_BOX_ALARM_INFO )
#define	ZZ_ALARM_SOSALERT					0x3010			 // SOS alert alarm (corresponds to structure ALARM_SOSALERT_INFO)
#define ZZ_ALARM_GYROABNORMALATTITUDE		0x3011			 // Vehicle abnormal attitude alarm caused by emergency braking, rollover, etc. (corresponds to ALARM_GYROABNORMALATTITUDE_INFO)



///@brief 8192 Coordinate Point
typedef struct tagZZNET_UINT_POINT
{
	UINT	nx;
	UINT	ny;
} ZZNET_UINT_POINT;

// No Disk Alarm
typedef struct tagZZALARM_NO_DISK_INFO
{
    DWORD               dwSize;
    ZZNET_TIME          stuTime;                            // Time
    DWORD               dwAction;                           // Event action, 0:Start, 1:Stop
}ZZALARM_NO_DISK_INFO;

// Object Left Event (Corresponds to event ZZ_EVENT_LEFT_DETECTION)
typedef struct tagZZALARM_EVENT_LEFT_INFO
{
    DWORD               dwSize;    
    int					nChannelID;						// Channel ID
    double				PTS;							// Timestamp (unit: milliseconds)
    ZZNET_TIME_EX			UTC;							// Time the event occurred
    int					nEventID;						// Event ID
    int                 nEventAction;                   // Event action, 0: pulse event, 1: continuous event start, 2: continuous event end;
    
    int                 nOccurrenceCount;               // Count of rule triggers
    int                 nLevel;                         // Event level, GB30147 requirement
	short				nPreserID;						// Preset ID triggered by event, starts from 1 (none indicates unknown)
	char				szPresetName[64];				// Preset name triggered by event
}ZZALARM_EVENT_LEFT_INFO;



// Object Corresponding Image File Info
typedef struct  
{
    DWORD           dwOffSet;                       // File offset in binary data block, unit: bytes
    DWORD           dwFileLenth;                    // File size, unit: bytes
    WORD            wWidth;                         // Image width, unit: pixels
    WORD            wHeight;                        // Image height, unit: pixels
    char*           pszFilePath;                    // Due to historical reasons, this member is only valid during event reporting
                                                    // File path
                                                    // User needs to allocate space to copy and save this field
    BYTE            bIsDetected;                    // Whether the image is detected by algorithm. When submitting to recognition server,
								                    // no need for detection positioning cutout if 1 (detected), 0 (not detected)
	
	BYTE            bReserved[7];                   // 12<--16
	ZZ_POINT		stuPoint;						// Top-left corner of small image in large image, using absolute coordinate system				
}ZZ_PIC_INFO;


// Color Type
typedef enum
{
    ZZNET_COLOR_TYPE_RED,                                     // Red
    ZZNET_COLOR_TYPE_YELLOW,                                  // Yellow
    ZZNET_COLOR_TYPE_GREEN,                                   // Green
    ZZNET_COLOR_TYPE_CYAN,                                    // Cyan
    ZZNET_COLOR_TYPE_BLUE,                                    // Blue
    ZZNET_COLOR_TYPE_PURPLE,                                  // Purple
    ZZNET_COLOR_TYPE_BLACK,                                   // Black
    ZZNET_COLOR_TYPE_WHITE,                                   // White
    ZZNET_COLOR_TYPE_MAX,
}EM_ZZ_COLOR_TYPE;

// Extended fields include int64, forced 4-byte alignment
#ifndef LINUX64_JNA
#pragma pack(push)
#pragma pack(4)
#endif
// Video Analysis Object Info Structure
typedef struct 
{
    int                 nObjectID;                          // Object ID, each ID represents a unique object
    char                szObjectType[128];                  // Object Type
    int                 nConfidence;                        // Confidence (0~255), larger value means higher confidence
    int                 nAction;                            // Object Action: 1:Appear 2:Move 3:Stay 4:Remove 5:Disappear 6:Split 7:Merge 8:Rename
    ZZ_RECT             BoundingBox;                        // Bounding Box
    ZZ_POINT            Center;                             // Object Centroid
    int                 nPolygonNum;                        // Polygon Vertex Count
    ZZ_POINT            Contour[ZZ_MAX_POLYGON_NUM];        // More precise contour polygon
    DWORD               rgbaMainColor;                      // Main color of plate, body etc.; represented by bytes: Red, Green, Blue, Alpha. e.g., RGB(0,255,0), Alpha 0 is 0x00ff0000.
    char                szText[128];                        // Related text on object with 0 terminator, e.g., plate number, container number etc.
                                                            // When "ObjectType" is "Vehicle" or "Logo" (Prefer Logo. Vehicle is for compatibility), it represents car logo, supports:
                                                            // "Unknown" 
                                                            // "Audi" 
                                                            // "Honda" 
                                                            // "Buick" 
                                                            // "Volkswagen" 
                                                            // "Toyota" 
                                                            // "BMW" 
                                                            // "Peugeot" 
                                                            // "Ford" 
                                                            // "Mazda" 
                                                            // "Nissan" 
                                                            // "Hyundai" 
                                                            // "Suzuki" 
                                                            // "Citroen" 
                                                            // "Benz" 
                                                            // "BYD" 
                                                            // "Geely" 
                                                            // "Lexus" 
                                                            // "Chevrolet" 
                                                            // "Chery" 
                                                            // "Kia" 
                                                            // "Charade" 
                                                            // "DF" 
                                                            // "Naveco" 
                                                            // "SGMW" 
                                                            // "Jinbei" 
                                                            
                                                            // "JAC" 
                                                            // "Emgrand" 
                                                            // "ChangAn" 
                                                            // "Great Wall" 
                                                            // "Skoda" 
                                                            // "BaoJun" 
                                                            // "Subaru" 
                                                            // "LandWind" 
                                                            // "Luxgen" 
                                                            // "Renault" 
                                                            // "Mitsubishi" 
                                                            // "Roewe" 
                                                            // "Cadillac" 
                                                            // "MG" 
                                                            // "Zotye" 
                                                            // "ZhongHua" 
                                                            // "Foton" 
                                                            // "SongHuaJiang" 
                                                            // "Opel" 
                                                            // "HongQi" 
                                                            // "Fiat" 
                                                            // "Jaguar" 
                                                            // "Volvo" 
                                                            // "Acura" 
                                                            // "Porsche" 
                                                            
                                                            // "Jeep" 
                                                            // "Bentley" 
                                                            // "Bugatti" 
                                                            // "ChuanQi" 
                                                            // "Daewoo" 
                                                            // "DongNan" 
                                                            // "Ferrari" 
                                                            // "Fudi" 
                                                            // "Huapu" 
                                                            // "HawTai" 
                                                            // "JMC" 
                                                            // "JingLong" 
                                                            // "JoyLong" 
                                                            // "Karry" 
                                                            // "Chrysler" 
                                                            // "Lamborghini" 
                                                            // "RollsRoyce" 
                                                            // "Linian" 
                                                            // "LiFan" 
                                                            // "LieBao" 
                                                            // "Lincoln" 
                                                            // "LandRover" 
                                                            // "Lotus" 
                                                            // "Maserati" 
                                                            // "Maybach" 

                                                            // "Mclaren" 
                                                            // "Youngman" 
                                                            // "Tesla" 
                                                            // "Rely" 
                                                            // "Lsuzu" 
                                                            // "Yiqi" 
                                                            // "Infiniti" 
                                                            // "YuTong" 
                                                            // "AnKai" 
                                                            // "Canghe" 
                                                            // "HaiMa" 
                                                            // "Crown" 
                                                            // "HuangHai" 
                                                            // "JinLv" 
                                                            // "JinNing" 
                                                            // "KuBo" 
                                                            // "Europestar" 
                                                            // "MINI" 
                                                            // "Gleagle" 
                                                            // "ShiDai" 
                                                            // "ShuangHuan" 
                                                            // "TianYe" 
                                                            // "WeiZi" 
                                                            // "Englon" 
                                                            // "ZhongTong" 

                                                            // "Changan" 
                                                            // "Yuejin" 
                                                            // "Taurus" 
                                                            // "Alto" 
                                                            // "Weiwang" 
                                                            // "Chenglong" 
                                                            // "Haige" 
                                                            // "Shaolin" 
                                                            // "Beifang" 
                                                            // "Beijing" 
                                                            // "Hafu" 

															// "BeijingTruck" 
															// "Besturn" 
															// "ChanganBus" 
															// "Dodge" 
															// "DongFangHong" 
															// "DongFengTruck" 
                                                            // "DongFengBus" 
															// "MultiBrand" 
															// "FotonTruck" 
															// "FotonBus" 
															// "GagcTruck" 
															// "HaFei" 
															// "HowoBus" 
															// "JACTruck" 
															// "JACBus" 
															// "JMCTruck" 
															// "JieFangTruck" 
															// "JinBeiTruck" 
															// "KaiMaTruck" 
															// "CoasterBus" 
															// "MudanBus" 
															// "NanJunTruck" 
															// "QingLing" 
															// "NissanCivilian" 
															// "NissanTruck" 
															// "MitsubishiFuso" 
															// "SanyTruck" 
															// "ShanQiTruck" 
															// "ShenLongBus" 
															// "TangJunTruck" 
															// "MicroTruck" 
															// "VolvoBus" 
															// "LsuzuTruck" 
															// "WuZhengTruck" 
															// "Seat" 
															// "YangZiBus" 
															// "YiqiBus" 
															// "YingTianTruck" 
															// "YueJinTruck" 
															// "ZhongDaBus" 
															// "ZxAuto" 

															// "ZhongQiWangPai" 
															// "WAW" 
															// "BeiQiWeiWang" 
															// "BYDDaimler"	
															// "ChunLan" 
															// "DaYun" 
															// "DFFengDu" 
															// "DFFengGuang" 
															// "DFFengShen" 
															// "DFFengXing" 
															// "DFLiuQi" 
															// "DFXiaoKang" 
															// "FeiChi" 
															// "FordMustang" 
															// "GuangQi" 
															// "GuangTong" 
															// "HuiZhongTruck" 
															// "JiangHuai" 
															// "SunWin" 
															// "ShiFeng" 
															// "TongXin" 
															// "WZL" 
															// "XiWo" 
															// "XuGong" 
															// "JingGong" 
															// "SAAB" 
															// "SanHuanShiTong" 
															// "KangDi" 
															// "YaoLong" 


    char                szObjectSubType[62];                // Object sub-type, based on different object types, can take following sub-types:
                                                            // Vehicle Category:"Unknown", "Motor", "Non-Motor", "Bus", "Bicycle", "Motorcycle", "PassengerCar",
                                                            // "LargeTruck", "MidTruck", "SaloonCar", "Microbus", "MicroTruck", "Tricycle", "Passerby"                                                    
                                                            //  Plate Category："Unknown", "Normal" (Blue/Black), "Yellow", "DoubleYellow", "Police", "Armed",
                                                            // "Military", "DoubleMilitary", "SAR", "Trainning"
                                                            // "Personal", "Agri", "Embassy", "Moto", "Tractor", "Other"
															// "Civilaviation", "Black"
															// "PureNewEnergyMicroCar", "MixedNewEnergyMicroCar, "PureNewEnergyLargeCar"
															// "MixedNewEnergyLargeCar"
                                                            // HumanFace Category: "Normal", "HideEye", "HideNose", "HideMouth", "TankCar"

    
    WORD                wColorLogoIndex;                    // Logo Index
    WORD                wSubBrand;                          // Vehicle Sub-brand, needs mapping table to get real sub-brand, see development manual
    BYTE                byReserved1;                     
    bool                bPicEnble;                          // Whether object has corresponding image file info
    ZZ_PIC_INFO         stPicInfo;                          // Object corresponding image info
    bool                bShotFrame;                         // Whether it is the recognition result of the snapshot frame
    bool                bColor;                             // Whether object color (rgbaMainColor) is available
    BYTE                byReserved2;
    BYTE                byTimeType;                         // Time representation type, see EM_TIME_TYPE
    ZZNET_TIME_EX       stuCurrentTime;                     // For video synopsis, current timestamp (when object is captured or recognized, this smart frame is attached to a video frame or jpeg image, its appearance time in original video)
    ZZNET_TIME_EX       stuStartTime;                       // Start timestamp (when object starts to appear)
    ZZNET_TIME_EX       stuEndTime;                         // End timestamp (when object disappears)
    ZZ_RECT             stuOriginalBoundingBox;             // Bounding box (absolute coordinates)
    ZZ_RECT             stuSignBoundingBox;                 // Sign bounding box
    DWORD               dwCurrentSequence;                  // Current frame sequence (frame when object was captured)
    DWORD               dwBeginSequence;                    // Start frame sequence (frame when object started to appear)
    DWORD               dwEndSequence;                      // End frame sequence (frame when object disappeared)
    INT64               nBeginFileOffset;                   // Start file offset, unit: byte (offset in original video file when object starts to appear)
    INT64               nEndFileOffset;                     // End file offset, unit: byte (offset in original video file when object disappears)
    BYTE                byColorSimilar[ZZNET_COLOR_TYPE_MAX]; // Object color similarity, range: 0-100, array index represents color, see EM_COLOR_TYPE
    BYTE                byUpperBodyColorSimilar[ZZNET_COLOR_TYPE_MAX]; // Upper body color similarity (valid when object type is human)
    BYTE                byLowerBodyColorSimilar[ZZNET_COLOR_TYPE_MAX]; // Lower body color similarity (valid when object type is human)
    int                 nRelativeID;                        // Related object ID
    char                szSubText[20];                      // When "ObjectType" is "Vehicle" or "Logo", represents car series under brand, e.g., Audi A6L. SDK passes this field through, device fills it.
    WORD                wBrandYear;                         // Vehicle brand year, needs mapping table to get real year, see development manual
} ZZ_MSG_OBJECT;

// Intrusion Direction
typedef enum tagEM_ZZ_MSG_OBJ_PERSON_DIRECTION
{
    EM_ZZ_MSG_OBJ_PERSON_DIRECTION_UNKOWN,         // Unknown direction
    EM_ZZ_MSG_OBJ_PERSON_DIRECTION_LEFT_TO_RIGHT,  // Left to Right
    EM_ZZ_MSG_OBJ_PERSON_DIRECTION_RIGHT_TO_LEFT   // Right to Left
}EM_ZZ_MSG_OBJ_PERSON_DIRECTION;

// Video Analysis Object Info Extended Structure
typedef struct tagZZ_MSG_OBJECT_EX
{
    DWORD               dwSize;
    int                 nObjectID;                          // Object ID, unique for each object
    char                szObjectType[128];                  // Object Type
    int                 nConfidence;                        // Confidence (0~255), larger value means higher confidence
    int                 nAction;                            // Object Action: 1:Appear 2:Move 3:Stay 4:Remove 5:Disappear 6:Split 7:Merge 8:Rename
    ZZ_RECT             BoundingBox;                        // Bounding Box
    ZZ_POINT            Center;                             // Object Centroid
    int                 nPolygonNum;                        // Polygon Vertex Count
    ZZ_POINT            Contour[ZZ_MAX_POLYGON_NUM];        // More precise contour polygon
    DWORD               rgbaMainColor;                      // Main color of plate, body etc.; represented by bytes: Red, Green, Blue, Alpha. e.g., RGB(0,255,0), Alpha 0 is 0x00ff0000.
    char                szText[128];                        // Same as ZZ_MSG_OBJECT field   
    char                szObjectSubType[64];                // Object sub-type, see ZZ_MSG_OBJECT
    BYTE                byReserved1[3];
    bool                bPicEnble;                          // Whether object has corresponding image file info
    ZZ_PIC_INFO         stPicInfo;                          // Object corresponding image info
    bool                bShotFrame;                         // Whether it is the recognition result of the snapshot frame
    bool                bColor;                             // Whether object color (rgbaMainColor) is available
    BYTE                bLowerBodyColor;                    // Whether lower body color (rgbaLowerBodyColor) is available
    BYTE                byTimeType;                         // Time representation type, see EM_TIME_TYPE
    ZZNET_TIME_EX         stuCurrentTime;                     // For video synopsis, current timestamp
    ZZNET_TIME_EX         stuStartTime;                       // Start timestamp
    ZZNET_TIME_EX         stuEndTime;                         // End timestamp
    ZZ_RECT             stuOriginalBoundingBox;             // Bounding box (absolute coordinates)
    ZZ_RECT             stuSignBoundingBox;                 // Sign bounding box
    DWORD               dwCurrentSequence;                  // Current frame sequence
    DWORD               dwBeginSequence;                    // Start frame sequence
    DWORD               dwEndSequence;                      // End frame sequence
    INT64               nBeginFileOffset;                   // Start file offset
    INT64               nEndFileOffset;                     // End file offset
    BYTE                byColorSimilar[ZZNET_COLOR_TYPE_MAX]; // Object color similarity
    BYTE                byUpperBodyColorSimilar[ZZNET_COLOR_TYPE_MAX]; // Upper body color similarity
    BYTE                byLowerBodyColorSimilar[ZZNET_COLOR_TYPE_MAX]; // Lower body color similarity
    int                 nRelativeID;                        // Related object ID
    char                szSubText[20];                      // Sub text

    int                 nPersonStature;                     // Intruder height, unit cm
    EM_ZZ_MSG_OBJ_PERSON_DIRECTION emPersonDirection;          // Intrusion direction
    DWORD               rgbaLowerBodyColor;                 // Usage same as rgbaMainColor, valid when object type is human 
} ZZ_MSG_OBJECT_EX;
#ifndef LINUX64_JNA
#pragma pack(pop)
#endif


// Major Business Scheme       
typedef enum tagEM_ZZ_CLASS_TYPE        
{
	EM_ZZ_CLASS_UNKNOWN                	= 0,    // Unknown       
    EM_ZZ_CLASS_VIDEO_SYNOPSIS            	= 1,    // Video Synopsis       
    EM_ZZ_CLASS_TRAFFIV_GATE            	= 2,    // Traffic Gate       
    EM_ZZ_CLASS_ELECTRONIC_POLICE        	= 3,    // Electronic Police       
    EM_ZZ_CLASS_SINGLE_PTZ_PARKING        	= 4,    // Single PTZ Parking       
    EM_ZZ_CLASS_PTZ_PARKINBG            	= 5,    // Master-Slave Parking       
    EM_ZZ_CLASS_TRAFFIC                	= 6,    // Traffic Event "Traffic"       
    EM_ZZ_CLASS_NORMAL                    	= 7,    // General Behavior Analysis "Normal"       
    EM_ZZ_CLASS_PRISON                    	= 8,    // Prison Behavior Analysis "Prison"       
    EM_ZZ_CLASS_ATM                    	= 9,    // Financial Behavior Analysis "ATM"       
    EM_ZZ_CLASS_METRO                    	= 10,   // Metro Behavior Analysis       
    EM_ZZ_CLASS_FACE_DETECTION            	= 11,   // Face Detection "FaceDetection"       
    EM_ZZ_CLASS_FACE_RECOGNITION        	= 12,   // Face Recognition "FaceRecognition"       
    EM_ZZ_CLASS_NUMBER_STAT            	= 13,   // Number Statistics "NumberStat"       
    EM_ZZ_CLASS_HEAT_MAP                	= 14,   // Heat Map "HeatMap"       
    EM_ZZ_CLASS_VIDEO_DIAGNOSIS        	= 15,   // Video Diagnosis "VideoDiagnosis"       
    EM_ZZ_CLASS_VIDEO_ENHANCE            	= 16,   // Video Enhancement       
    EM_ZZ_CLASS_SMOKEFIRE_DETECT        	= 17,   // Smoke Fire Detection       
    EM_ZZ_CLASS_VEHICLE_ANALYSE        	= 18,   // Vehicle Feature Recognition "VehicleAnalyse"       
    EM_ZZ_CLASS_PERSON_FEATURE            	= 19,   // Person Feature Recognition     
    EM_ZZ_CLASS_SDFACEDETECTION			= 20,	// Multi-Preset Face Detection "SDFaceDetect"  
    											// Configure one rule but effective under different presets
	EM_ZZ_CLASS_HEAT_MAP_PLAN				= 21,	// PTZ Heat Map Plan "HeatMapPlan" 
	EM_ZZ_CLASS_NUMBERSTAT_PLAN			= 22,	// PTZ Passenger Flow Statistics Plan "NumberStatPlan"
	EM_ZZ_CLASS_ATMFD						= 23,	// Financial Face Detection, includes normal, abnormal, adjacent, helmet faces optimized for ATM scenarios
	EM_ZZ_CLASS_HIGHWAY					= 24,	// Highway Traffic Event Detection "Highway"
	EM_ZZ_CLASS_CITY						= 25,	// City Traffic Event Detection "City"
	EM_ZZ_CLASS_LETRACK					= 26,	// Civil Simple Tracking "LeTrack"
	EM_ZZ_CLASS_SCR						= 27,	// Shooting Camera "SCR"
	EM_ZZ_CLASS_STEREO_VISION              = 28,   // Stereo Vision "StereoVision"
	EM_ZZ_CLASS_HUMANDETECT                = 29,   // Human Detection "HumanDetect"
	EM_ZZ_CLASS_FACE_ANALYSIS				= 30,	// Face Analysis "FaceAnalysis"
	EM_ZZ_CALSS_XRAY_DETECTION				= 31,	// X-Ray Detection "XRayDetection"
	EM_ZZ_CLASS_STEREO_NUMBER				= 32,	// Stereo Camera Passenger Flow Statistics "StereoNumber"
} EM_ZZ_CLASS_TYPE; 

// Intelligent Alarm Event Common Info
typedef struct tagZZEVENT_INTELLI_COMM_INFO
{
	EM_ZZ_CLASS_TYPE	emClassType;								// Intelligent event category
	int					nPresetID;									// Preset ID triggered by event, corresponds to rule preset
	BYTE                bReserved[124];                     		// Reserved bytes
} ZZEVENT_INTELLI_COMM_INFO;

// Major Business Scheme, consistent with EM_SCENE_TYPE
typedef enum tagEM_ZZ_SCENE_CLASS_TYPE
{
	EM_ZZ_SCENE_CLASS_UNKNOW,			// Unknown
	EM_ZZ_SCENE_CLASS_NORMAL,			// "Normal"
	EM_ZZ_SCENE_CLASS_TRAFFIC,			// "Traffic"
	EM_ZZ_SCENE_CLASS_TRAFFIC_PATROL,	// "TrafficPatrol"
	EM_ZZ_SCENE_CLASS_FACEDETECTION,	// "FaceDetection"
	EM_ZZ_SCENE_CLASS_ATM,				// "ATM"
	EM_ZZ_SENCE_CLASS_INDOOR,			// "Indoor"
	EM_ZZ_SENCE_CLASS_FACERECOGNITION,	// "FaceRecognition"
	EM_ZZ_SENCE_CLASS_PRISON,			// "Prison"
	EM_ZZ_SENCE_CLASS_NUMBERSTAT,		// "NumberStat"
	EM_ZZ_SENCE_CLASS_HEAT_MAP,		// "HeatMap"
	EM_ZZ_SENCE_CLASS_VIDEODIAGNOSIS,	// "VideoDiagnosis"
	EM_ZZ_SENCE_CLASS_VEHICLEANALYSE,	// "VehicleAnalyse"
	EM_ZZ_SENCE_CLASS_COURSERECORD,	// "CourseRecord"
	EM_ZZ_SENCE_CLASS_VEHICLE,			// "Vehicle"
	EM_ZZ_SENCE_CLASS_STANDUPDETECTION,// "StandUpDetection"
	EM_ZZ_SCENE_CLASS_GATE,			// "Gate"
	EM_ZZ_SCENE_CLASS_SDFACEDETECTION,	// "SDFaceDetect"
	EM_ZZ_SCENE_CLASS_HEAT_MAP_PLAN,	// "HeatMapPlan"
	EM_ZZ_SCENE_CLASS_NUMBERSTAT_PLAN,	// "NumberStatPlan"
	EM_ZZ_SCENE_CLASS_ATMFD,			// "ATMFD"
	EM_ZZ_SCENE_CLASS_HIGHWAY,			// "Highway"
	EM_ZZ_SCENE_CLASS_CITY,			// "City"
	EM_ZZ_SCENE_CLASS_LETRACK,			// "LeTrack"
	EM_ZZ_SCENE_CLASS_SCR,				// "SCR"
	EM_ZZ_SCENE_CLASS_STEREO_VISION,   // "StereoVision"
	EM_ZZ_SCENE_CLASS_HUMANDETECT,		// "HumanDetect"
	EM_ZZ_SCENE_CLASS_FACEANALYSIS,	// "FaceAnalysis"
	EM_ZZ_SCENE_CLASS_XRAY_DETECTION,	// "XRayDetection"
	EM_ZZ_SCENE_CLASS_STEREO_NUMBER,	// "StereoNumber"
} EM_ZZ_SCENE_CLASS_TYPE;

// Illegal Parking Event (ZZ_EVENT_IVS_PARKINGDETECTION) Data Structure
typedef struct tagZZDEV_EVENT_PARKINGDETECTION_INFO
{
    int                 nChannelID;                                 // Channel ID
    char                szName[128];                                // Event Name
    char                bReserved1[4];                              // Byte Alignment
    double              PTS;                                        // Timestamp (ms)
    ZZNET_TIME_EX       UTC;                                        // Event Time
    int                 nEventID;                                   // Event ID
    ZZ_MSG_OBJECT       stuObject;                                  // Detected Object
    int                 nDetectRegionNum;                           // Detection Region Vertices
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM];     // Detection Region
    ZZ_EVENT_FILE_INFO  stuFileInfo;                                // Event File Info
    BYTE                bEventAction;                               // Event Action: 0:Pulse, 1:Start, 2:End
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // Image Index
    DWORD               dwSnapFlagMask;                             // Snapshot Flag Mask
    int                 nSourceIndex;                               // Source Index
    char                szSourceDevice[MAX_PATH];                   // Source Device ID
    unsigned int        nOccurrenceCount;                           // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;                 // Intelligent Common Info
    BYTE                bReserved[616];                             // Reserved
} ZZDEV_EVENT_PARKINGDETECTION_INFO;




// Rioter Event (ZZ_EVENT_IVS_RIOTERDETECTION) Data Structure
typedef struct tagZZDEV_EVENT_RIOTER_INFO 
{
    int                 nChannelID;                         // Channel ID
    char                szName[128];                        // Event Name
    char                bReserved1[4];                      // Byte Alignment
    double              PTS;                                // Timestamp (ms)
    ZZNET_TIME_EX         UTC;                                // Event Time
    int                 nEventID;                           // Event ID
    int                 nObjectNum;                         // Object Count
    ZZ_MSG_OBJECT       stuObjectIDs[ZZ_MAX_OBJECT_LIST];   // Object List
    ZZ_EVENT_FILE_INFO  stuFileInfo;                        // Event File Info
    BYTE                bEventAction;                       // Event Action: 0:Pulse, 1:Start, 2:End
    BYTE                byReserved[2];                      // Reserved
    BYTE                byImageIndex;                       // Image Index
    int                 nDetectRegionNum;                   // Detection Region Vertices
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM];    // Detection Region

    DWORD               dwSnapFlagMask;                     // Snapshot Flag Mask    
    int                 nSourceIndex;                       // Source Index
    char                szSourceDevice[MAX_PATH];           // Source Device ID
    unsigned int        nOccurrenceCount;                   // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;         // Intelligent Common Info
    BYTE                bReserved[492];                     // Reserved
} ZZDEV_EVENT_RIOTERL_INFO;


// Leave Detection Event (ZZ_EVENT_IVS_LEAVEDETECTION) Data Structure
typedef struct tagZZDEV_EVENT_IVS_LEAVE_INFO
{
    int                 nChannelID;                                 // Channel ID
    char                szName[128];                                // Event Name
    char                bReserved1[4];                              // Byte Alignment
    double              PTS;                                        // Timestamp (ms)
    ZZNET_TIME_EX         UTC;                                        // Event Time
    int                 nEventID;                                   // Event ID
    ZZ_MSG_OBJECT       stuObject;                                  // Detected Object
    ZZ_EVENT_FILE_INFO  stuFileInfo;                                // Event File Info
    ZZ_RESOLUTION_INFO  stuResolution;                              // Resolution
    int                 nDetectRegionNum;                           // Detection Region Vertices
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM];     // Detection Region
    BYTE                bEventAction;                               // Event Action: 0:Pulse, 1:Start, 2:End    
    BYTE                byImageIndex;                               // Image Index
	ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;                 // Intelligent Common Info
	BYTE                bReserved[894];                            // Reserved
} ZZDEV_EVENT_IVS_LEAVE_INFO;

// Wander Detection Event (ZZ_EVENT_IVS_WANDERDETECTION) Data Structure
typedef struct tagZZDEV_EVENT_WANDER_INFO 
{
    int                 nChannelID;                         // Channel ID
    char                szName[128];                        // Event Name
    char                bReserved1[4];                      // Byte Alignment
    double              PTS;                                // Timestamp (ms)
    ZZNET_TIME_EX         UTC;                                // Event Time
    int                 nEventID;                           // Event ID
    ZZ_EVENT_FILE_INFO  stuFileInfo;                        // Event File Info
    BYTE                bEventAction;                       // Event Action: 0:Pulse, 1:Start, 2:End
    BYTE                byReserved[2];                      // Reserved
    BYTE                byImageIndex;                       // Image Index
    int                 nObjectNum;                         // Object Count
    ZZ_MSG_OBJECT       stuObjectIDs[ZZ_MAX_OBJECT_LIST];   // Objects
    int                 nTrackNum;                          // Track Count
    ZZ_POLY_POINTS      stuTrackInfo[ZZ_MAX_OBJECT_LIST];   // Track Info
    int                 nDetectRegionNum;                   // Detection Region Vertices
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM];    // Detection Region
    DWORD               dwSnapFlagMask;                     // Snapshot Flag Mask    
    int                 nSourceIndex;                       // Source Index
    char                szSourceDevice[MAX_PATH];           // Source Device ID
    unsigned int        nOccurrenceCount;                   // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;         // Intelligent Common Info
	short				nPreserID;							// Preset ID
	char				szPresetName[64];					// Preset Name
    BYTE                bReserved[558];                     // Reserved
} ZZDEV_EVENT_WANDER_INFO;


// Left Detection Event (ZZ_EVENT_IVS_LEFTDETECTION) Data Structure
typedef struct tagZZDEV_EVENT_LEFT_INFO 
{
    int                 nChannelID;                         // Channel ID
    char                szName[128];                        // Event Name
    char                bReserved1[4];                      // Byte Alignment
    double              PTS;                                // Timestamp (ms)
    ZZNET_TIME_EX         UTC;                                // Event Time
    int                 nEventID;                           // Event ID
    ZZ_MSG_OBJECT       stuObject;                          // Detected Object
    ZZ_EVENT_FILE_INFO  stuFileInfo;                        // Event File Info
    BYTE                bEventAction;                       // Event Action: 0:Pulse, 1:Start, 2:End
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // Image Index
    int                 nDetectRegionNum;                   // Detection Region Vertices
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM]; // Detection Region
    DWORD               dwSnapFlagMask;                     // Snapshot Flag Mask    
    int                 nSourceIndex;                       // Source Index
    char                szSourceDevice[MAX_PATH];           // Source Device ID
    unsigned int        nOccurrenceCount;                   // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;         // Intelligent Common Info
	short				nPreserID;							// Preset ID
	char				szPresetName[64];					// Preset Name
    BYTE                bReserved[422];                     // Reserved
} ZZDEV_EVENT_LEFT_INFO;


// Cargo Channel Info (IPC Czech Logistics Custom)
typedef struct tagZZNET_CUSTOM_INFO
{
	int					nCargoChannelNum;						// Cargo channel number
	float				fCoverageRate[ZZ_MAX_CARGO_CHANNEL_NUM];	// Cargo coverage rate
	BYTE				byReserved[40];							// Reserved bytes
} ZZNET_CUSTOM_INFO;

// Cross Region Detection Event (ZZ_EVENT_IVS_CROSSREGIONDETECTION) Data Structure
typedef struct tagZZDEV_EVENT_CROSSREGION_INFO 
{
    int                 nChannelID;                         // Channel ID
    char                szName[128];                        // Event Name
    char                bReserved2[4];                      // Byte Alignment
    double              PTS;                                // Timestamp (ms)
    ZZNET_TIME_EX       UTC;                                // Event Time
    int                 nEventID;                           // Event ID
    ZZ_MSG_OBJECT       stuObject;                          // Detected Object
    ZZ_EVENT_FILE_INFO  stuFileInfo;                        // Event File Info
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM]; // Detection Region
    int                 nDetectRegionNum;                   // Detection Region Vertices
    ZZ_POINT            TrackLine[ZZ_MAX_TRACK_LINE_NUM];   // Track Line
    int                 nTrackLineNum;                      // Track Line Vertices
    BYTE                bEventAction;                       // Event Action
    BYTE                bDirection;                         // Direction: 0-Enter, 1-Leave, 2-Appear, 3-Disappear
    BYTE                bActionType;                        // Action Type: 0-Appear, 1-Disappear, 2-Inside, 3-Cross
    BYTE                byImageIndex;                       // Image Index
    DWORD               dwSnapFlagMask;                     // Snapshot Flag Mask    
    int                 nSourceIndex;                       // Source Index
    char                szSourceDevice[MAX_PATH];           // Source Device ID
    unsigned int        nOccurrenceCount;                   // Occurrence Count
	ZZNET_CUSTOM_INFO   stuCustom;							// Custom Info
	BYTE                bReserved[460];                     // Reserved
    int                 nObjectNum;                         // Object Count
    ZZ_MSG_OBJECT       stuObjectIDs[ZZ_MAX_OBJECT_LIST];   // Object List
    int                 nTrackNum;                          // Track Count
    ZZ_POLY_POINTS      stuTrackInfo[ZZ_MAX_OBJECT_LIST];   // Track Info
	ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;         // Intelligent Common Info
} ZZDEV_EVENT_CROSSREGION_INFO;

// Cross Line Detection Event (ZZ_EVENT_IVS_CROSSLINEDETECTION) Data Structure
typedef struct tagZZDEV_EVENT_CROSSLINE_INFO 
{
    int                 nChannelID;                         // Channel ID
    char                szName[128];                        // Event Name
    char                bReserved1[4];                      // Byte Alignment
    double              PTS;                                // Timestamp (ms)
    ZZNET_TIME_EX         UTC;                                // Event Time
    int                 nEventID;                           // Event ID
    ZZ_MSG_OBJECT       stuObject;                          // Detected Object
    ZZ_EVENT_FILE_INFO  stuFileInfo;                        // Event File Info
    ZZ_POINT            DetectLine[ZZ_MAX_DETECT_LINE_NUM]; // Detection Line
    int                 nDetectLineNum;                     // Detection Line Vertices
    ZZ_POINT            TrackLine[ZZ_MAX_TRACK_LINE_NUM];   // Track Line
    int                 nTrackLineNum;                      // Track Line Vertices
    BYTE                bEventAction;                       // Event Action
    BYTE                bDirection;                         // Direction: 0-Left to Right, 1-Right to Left
    BYTE                byReserved[1];
    BYTE                byImageIndex;                       // Image Index
    DWORD               dwSnapFlagMask;                     // Snapshot Flag Mask
    int                 nSourceIndex;                       // Source Index
    char                szSourceDevice[MAX_PATH];           // Source Device ID
    unsigned int        nOccurrenceCount;                   // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;         // Intelligent Common Info
    BYTE                bReserved[476];                     // Reserved
} ZZDEV_EVENT_CROSSLINE_INFO;

// Multi-face Detection Info
typedef struct tagZZNET_FACE_INFO
{
    int                 nObjectID;                          // Object ID
    char                szObjectType[128];                  // Object Type
    int                 nRelativeID;                        // Relative ID
    ZZ_RECT             BoundingBox;                        // Bounding Box
    ZZ_POINT            Center;                             // Center
} ZZNET_FACE_INFO;

// Face Detection Sex Type
typedef enum tagEM_ZZ_DEV_EVENT_FACEDETECT_SEX_TYPE
{
    EM_ZZ_DEV_EVENT_FACEDETECT_SEX_TYPE_UNKNOWN,                   // Unknown
    EM_ZZ_DEV_EVENT_FACEDETECT_SEX_TYPE_MAN,                       // Man
    EM_ZZ_DEV_EVENT_FACEDETECT_SEX_TYPE_WOMAN,                     // Woman
}EM_ZZ_DEV_EVENT_FACEDETECT_SEX_TYPE;

///@brief Euler Angle
typedef struct tagZZNET_EULER_ANGLE
{
    int		nPitch;				/// Pitch
    int		nYaw;				/// Yaw
    int		nRoll;				/// Roll
} ZZNET_EULER_ANGLE;

///@brief Target Capture Angle Range
typedef struct  tagZZNET_ANGEL_RANGE
{
    int		nMin;				/// Min
    int		nMax;				/// Max
} ZZNET_ANGEL_RANGE;

///@brief Original Target Image Size
typedef struct tagZZNET_FACE_ORIGINAL_SIZE
{
    UINT    nWidth;             /// Width
    UINT    nHeight;            /// Height
}ZZNET_FACE_ORIGINAL_SIZE;


#define ZZ_MAX_FACEDETECT_FEATURE_NUM          32                      // Max face features
// Face Detection Feature Type
typedef enum tagEM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE
{
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_UNKNOWN,               // Unknown
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_WEAR_GLASSES,          // Wear Glasses
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_SMILE,                 // Smile
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_ANGER,                 // Anger
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_SADNESS,               // Sadness
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_DISGUST,               // Disgust
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_FEAR,                  // Fear
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_SURPRISE,              // Surprise
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_NEUTRAL,               // Neutral
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_LAUGH,                 // Laugh
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_NOGLASSES,				// No Glasses
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_HAPPY,					// Happy
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_CONFUSED,				// Confused
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_SCREAM,				// Scream
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE_WEAR_SUNGLASSES,       // Wear Sunglasses
}EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE;

// Glasses Type
typedef enum tagEM_ZZ_GLASSES_TYPE
{
	EM_ZZ_GLASSES_UNKNOWN,		// Unknown
	EM_ZZ_GLASSES_SUNGLASS,	// Sunglasses
	EM_ZZ_GLASSES_GLASS,		// Glasses
} EM_ZZ_GLASSES_TYPE;

// Race Type
typedef enum tagEM_ZZ_RACE_TYPE
{
	EM_ZZ_RACE_UNKNOWN,			// Unknown
	EM_ZZ_RACE_NODISTI,			// Undistinguished
	EM_ZZ_RACE_YELLOW,				// Yellow
	EM_ZZ_RACE_BLACK,				// Black
	EM_ZZ_RACE_WHITE,				// White
} EM_ZZ_RACE_TYPE;

// Eye State
typedef enum tagEM_ZZ_EYE_STATE_TYPE
{
	EM_ZZ_EYE_STATE_UNKNOWN,		// Unknown
	EM_ZZ_EYE_STATE_NODISTI,		// Undistinguished
	EM_ZZ_EYE_STATE_CLOSE,			// Close
	EM_ZZ_EYE_STATE_OPEN,			// Open
} EM_ZZ_EYE_STATE_TYPE;

// Mouth State
typedef enum tagEM_ZZ_MOUTH_STATE_TYPE
{
	EM_ZZ_MOUTH_STATE_UNKNOWN,		// Unknown
	EM_ZZ_MOUTH_STATE_NODISTI,		// Undistinguished
	EM_ZZ_MOUTH_STATE_CLOSE,		// Close
	EM_ZZ_MOUTH_STATE_OPEN,		// Open
} EM_ZZ_MOUTH_STATE_TYPE;

// Mask State
typedef enum tagEM_ZZ_MASK_STATE_TYPE
{
	EM_ZZ_MASK_STATE_UNKNOWN,		// Unknown
	EM_ZZ_MASK_STATE_NODISTI,		// Undistinguished
	EM_ZZ_MASK_STATE_NOMASK,		// No Mask
	EM_ZZ_MASK_STATE_WEAR,			// Wear Mask
} EM_ZZ_MASK_STATE_TYPE;

// Beard State
typedef enum tagEM_ZZ_BEARD_STATE_TYPE
{
	EM_ZZ_BEARD_STATE_UNKNOWN,		// Unknown
	EM_ZZ_BEARD_STATE_NODISTI,		// Undistinguished
	EM_ZZ_BEARD_STATE_NOBEARD,		// No Beard
	EM_ZZ_BEARD_STATE_HAVEBEARD,	// Have Beard
} EM_ZZ_BEARD_STATE_TYPE;


typedef enum tagEM_ZZ_OPEN_STROBE_STATE
{
    ZZNET_OPEN_STROBE_STATE_UNKOWN,                   // Unknown
    ZZNET_OPEN_STROBE_STATE_CLOSE,                    // Close Strobe
    ZZNET_OPEN_STROBE_STATE_AUTO,                     // Auto Open
    ZZNET_OPEN_STROBE_STATE_MANUAL,                   // Manual Open
}EM_ZZ_OPEN_STROBE_STATE;

typedef enum tagEM_ZZ_VEHICLE_DIRECTION
{
    ZZNET_VEHICLE_DIRECTION_UNKOWN,                   // Unknown
    ZZNET_VEHICLE_DIRECTION_HEAD,                     // Head
    ZZNET_VEHICLE_DIRECTION_TAIL,                     // Tail
}EM_ZZ_VEHICLE_DIRECTION;

//NTP Status
typedef enum  tagEM_ZZ_NTP_STATUS
{
    ZZNET_NTP_STATUS_UNKNOWN = 0 ,
    ZZNET_NTP_STATUS_DISABLE , 
    ZZNET_NTP_STATUS_SUCCESSFUL , 
    ZZNET_NTP_STATUS_FAILED , 
}EM_ZZ_NTP_STATUS;

#define ZZ_COMMON_SEAT_MAX_NUMBER        8             // Max common seats

typedef enum tagEM_ZZ_COMMON_SEAT_TYPE
{
    ZZ_COMMON_SEAT_TYPE_UNKNOWN    = 0,                // Unknown
    ZZ_COMMON_SEAT_TYPE_MAIN       = 1,                // Main Driver
    ZZ_COMMON_SEAT_TYPE_SLAVE      = 2,                // Co-Driver
}EM_ZZ_COMMON_SEAT_TYPE;

// Violation Status
typedef struct tagZZEVENT_COMM_STATUS                 
{
    BYTE bySmoking;                                 // Smoking
    BYTE byCalling;                                 // Calling
    char szReserved[14];                            // Reserved
}ZZEVENT_COMM_STATUS;

typedef enum tagZZNET_SAFEBELT_STATE
{
    ZZ_SS_NUKNOW   = 0 ,				// Unknown
	ZZ_SS_WITH_SAFE_BELT ,				                // With Safe Belt
	ZZ_SS_WITHOUT_SAFE_BELT ,			                // Without Safe Belt
}ZZNET_SAFEBELT_STATE;

// Sunshade State
typedef enum tagZZNET_SUNSHADE_STATE
{
    ZZ_SS_NUKNOW_SUN_SHADE	= 0 ,		// Unknown
	ZZ_SS_WITH_SUN_SHADE,				                // With Sunshade
	ZZ_SS_WITHOUT_SUN_SHADE,			                // Without Sunshade
}ZZNET_SUNSHADE_STATE;
// Seat Violation Info
typedef struct tagZZEVENT_COMM_SEAT
{
    BOOL                    bEnable;                // Enable
    EM_ZZ_COMMON_SEAT_TYPE  emSeatType;             // Seat Type
    ZZEVENT_COMM_STATUS     stStatus;               // Status
	ZZNET_SAFEBELT_STATE    emSafeBeltStatus;       // Safe Belt Status
    ZZNET_SUNSHADE_STATE    emSunShadeStatus;       // Sunshade Status
    char                    szReserved[24];         // Reserved
}ZZEVENT_COMM_SEAT;

// Vehicle Attachment Type
typedef enum tagEM_ZZ_COMM_ATTACHMENT_TYPE      
{       
	ZZ_COMM_ATTACHMENT_TYPE_UNKNOWN    = 0,            // Unknown       
    ZZ_COMM_ATTACHMENT_TYPE_FURNITURE  = 1,            // Furniture       
    ZZ_COMM_ATTACHMENT_TYPE_PENDANT    = 2,            // Pendant       
    ZZ_COMM_ATTACHMENT_TYPE_TISSUEBOX  = 3,            // Tissue Box       
    ZZ_COMM_ATTACHMENT_TYPE_DANGER     = 4,            // Danger  
    ZZ_COMM_ATTACHMENT_TYPE_PERFUMEBOX = 5,			// Perfume Box
 }EM_ZZ_COMM_ATTACHMENT_TYPE;

// Vehicle Attachment
typedef struct tagZZEVENT_COMM_ATTACHMENT      
{       
	EM_ZZ_COMM_ATTACHMENT_TYPE  emAttachmentType;       // Type       
	ZZNET_RECT                  stuRect;                // Rect   
    BYTE						bReserved[20];		    // Reserved
 }ZZEVENT_COMM_ATTACHMENT;

// Traffic Snapshot Info
typedef struct tagZZEVENT_PIC_INFO
{
    DWORD                       nOffset;                // Offset
    DWORD                       nLength;                // Length
}ZZEVENT_PIC_INFO;


// Card Province
typedef enum tagEM_ZZ_CARD_PROVINCE
{
	EM_ZZ_CARD_UNKNOWN			= 10,		// Unknown
	EM_ZZ_CARD_BEIJING			= 11,		// Beijing
	EM_ZZ_CARD_TIANJIN			= 12,		// Tianjin
	EM_ZZ_CARD_HEBEI			= 13,		// Hebei
	EM_ZZ_CARD_SHANXI_TAIYUAN	= 14,		// Shanxi
	EM_ZZ_CARD_NEIMENGGU		= 15,		// Inner Mongolia
	EM_ZZ_CARD_LIAONING		= 21,		// Liaoning
	EM_ZZ_CARD_JILIN			= 22,		// Jilin
	EM_ZZ_CARD_HEILONGJIANG	= 23,		// Heilongjiang
	EM_ZZ_CARD_SHANGHAI		= 31,		// Shanghai
	EM_ZZ_CARD_JIANGSU			= 32,		// Jiangsu
	EM_ZZ_CARD_ZHEJIANG		= 33,		// Zhejiang
	EM_ZZ_CARD_ANHUI			= 34,		// Anhui
	EM_ZZ_CARD_FUJIAN			= 35,		// Fujian
	EM_ZZ_CARD_JIANGXI			= 36,		// Jiangxi
	EM_ZZ_CARD_SHANDONG		= 37,		// Shandong
	EM_ZZ_CARD_HENAN			= 41,		// Henan
	EM_ZZ_CARD_HUBEI			= 42,		// Hubei
	EM_ZZ_CARD_HUNAN			= 43,		// Hunan
	EM_ZZ_CARD_GUANGDONG		= 44,		// Guangdong
	EM_ZZ_CARD_GUANGXI			= 45,		// Guangxi
	EM_ZZ_CARD_HAINAN			= 46,		// Hainan
	EM_ZZ_CARD_CHONGQING		= 50,		// Chongqing
	EM_ZZ_CARD_SICHUAN			= 51,		// Sichuan
	EM_ZZ_CARD_GUIZHOU			= 52,		// Guizhou
	EM_ZZ_CARD_YUNNAN			= 53,		// Yunnan
	EM_ZZ_CARD_XIZANG			= 54,		// Tibet
	EM_ZZ_CARD_SHANXI_XIAN		= 61,		// Shaanxi
	EM_ZZ_CARD_GANSU			= 62,		// Gansu
	EM_ZZ_CARD_QINGHAI			= 63,		// Qinghai
	EM_ZZ_CARD_NINGXIA			= 64,		// Ningxia
	EM_ZZ_CARD_XINJIANG		= 65,		// Xinjiang
	EM_ZZ_CARD_XIANGGANG		= 71,		// Hong Kong
	EM_ZZ_CARD_AOMEN			= 82,		// Macau
} EM_ZZ_CARD_PROVINCE;

// Vehicle Type
typedef enum tagEM_ZZ_CAR_TYPE
{
	EM_ZZ_CAR_UNKNOWN,				// Unknown
	EM_ZZ_CAR_BUS,					// Bus
	EM_ZZ_CAR_BIG_TRUCK,			// Big Truck
	EM_ZZ_CAR_MEDIUM_TRUCK,		// Medium Truck
	EM_ZZ_CAR_CAR,					// Car
	EM_ZZ_CAR_VAN,					// Van
	EM_ZZ_CAR_SMALL_TRUCK,			// Small Truck
	EM_ZZ_CAR_TRICYCLE,			// Tricycle
	EM_ZZ_CAR_MOTORCYCLE,			// Motorcycle
	EM_ZZ_CAR_PEDESTRIAN,			// Pedestrian
	EM_ZZ_CAR_SUVMPV,				// SUV-MPV
	EM_ZZ_CAR_MEDIUM_BUS,			// Medium Bus
	EM_ZZ_CAR_DANGE_VEHICLE,		// Danger Vehicle
} EM_ZZ_CAR_TYPE;

// Plate Type
typedef enum tagEM_ZZ_PLATE_TYPE
{
	EM_ZZ_PLATE_UNKNOWN,				// Unknown
	EM_ZZ_PLATE_BIGCAR,				// Big Car
	EM_ZZ_PLATE_SMALLCAR,				// Small Car
	EM_ZZ_PLATE_EMBASSYCAR,			// Embassy Car
	EM_ZZ_PLATE_CONSULATECAR,			// Consulate Car
	EM_ZZ_PLATE_ABROADCAR,				// Abroad Car
	EM_ZZ_PLATE_FOREIGNCAR,			// Foreign Car
	EM_ZZ_PLATE_POLICE,				// Police
	EM_ZZ_PLATE_ARMEDPOLICE,			// Armed Police
	EM_ZZ_PLATE_TROOPS,				// Troops
	EM_ZZ_PLATE_TROOPSDOUBLE,			// Troops Double	
	EM_ZZ_PLATE_YELLOWTAILDOUBLE,		// Yellow Tail Double	
	EM_ZZ_PLATE_COACHCAR,				// Coach Car
	EM_ZZ_PLATE_PERSONALITY,			// Personality
	EM_ZZ_PLATE_AGRICULTURAL,			// Agricultural
	EM_ZZ_PLATE_MOTORCYCLE,			// Motorcycle
	EM_ZZ_PLATE_TRACTOR,				// Tractor
	EM_ZZ_PLATE_SMALLCAR_BLACK,		// Small Car Black
	EM_ZZ_PLATE_RED,					// Red
	EM_ZZ_PLATE_BLUE,					// Blue
	EM_ZZ_PLATE_WHITE,					// White
	EM_ZZ_PLATE_PURE_NEW_SMALLCAR,		// Pure New Small Car
	EM_ZZ_PLATE_BLEND_NEW_SMALLCAR,	// Blend New Small Car 
	EM_ZZ_PLATE_PURE_NEW_BIGCAR,		// Pure New Big Car
	EM_ZZ_PLATE_BLEND_NEW_BIGCAR,		// Blend New Big Car
} EM_ZZ_PLATE_TYPE;

// Car Color
typedef enum tagEM_ZZ_CAR_COLOR_TYPE
{
	EM_ZZ_CAR_COLOR_WHITE,				// White
	EM_ZZ_CAR_COLOR_BLACK,				// Black
	EM_ZZ_CAR_COLOR_RED,				// Red
	EM_ZZ_CAR_COLOR_YELLOW,			// Yellow
	EM_ZZ_CAR_COLOR_GRAY,				// Gray
	EM_ZZ_CAR_COLOR_BLUE,				// Blue
	EM_ZZ_CAR_COLOR_GREEN,				// Green
	EM_ZZ_CAR_COLOR_PINK,				// Pink
	EM_ZZ_CAR_COLOR_PURPLE,			// Purple
	EM_ZZ_CAR_COLOR_DARK_PURPLE,		// Dark Purple
	EM_ZZ_CAR_COLOR_BROWN,				// Brown
	EM_ZZ_CAR_COLOR_MAROON,			// Maroon
	EM_ZZ_CAR_COLOR_SILVER_GRAY,		// Silver Gray
	EM_ZZ_CAR_COLOR_DARK_GRAY,			// Dark Gray
	EM_ZZ_CAR_COLOR_WHITE_SMOKE,		// White Smoke
	EM_ZZ_CAR_COLOR_DEEP_ORANGE,		// Deep Orange
	EM_ZZ_CAR_COLOR_LIGHT_ROSE,		// Light Rose
	EM_ZZ_CAR_COLOR_TOMATO_RED,		// Tomato Red
	EM_ZZ_CAR_COLOR_OLIVE,				// Olive
	EM_ZZ_CAR_COLOR_GOLDEN,			// Golden
	EM_ZZ_CAR_COLOR_DARK_OLIVE,		// Dark Olive
	EM_ZZ_CAR_COLOR_YELLOW_GREEN,		// Yellow Green
	EM_ZZ_CAR_COLOR_GREEN_YELLOW,		// Green Yellow
	EM_ZZ_CAR_COLOR_FOREST_GREEN,		// Forest Green
	EM_ZZ_CAR_COLOR_OCEAN_BLUE,		// Ocean Blue
	EM_ZZ_CAR_COLOR_DEEP_SKYBLUE,		// Deep Sky Blue	
	EM_ZZ_CAR_COLOR_CYAN,				// Cyan
	EM_ZZ_CAR_COLOR_DEEP_BLUE,			// Deep Blue
	EM_ZZ_CAR_COLOR_DEEP_RED,			// Deep Red
	EM_ZZ_CAR_COLOR_DEEP_GREEN,		// Deep Green
	EM_ZZ_CAR_COLOR_DEEP_YELLOW,		// Deep Yellow
	EM_ZZ_CAR_COLOR_DEEP_PINK,			// Deep Pink
	EM_ZZ_CAR_COLOR_DEEP_PURPLE,		// Deep Purple
	EM_ZZ_CAR_COLOR_DEEP_BROWN,		// Deep Brown
	EM_ZZ_CAR_COLOR_DEEP_CYAN,			// Deep Cyan
	EM_ZZ_CAR_COLOR_ORANGE,			// Orange
	EM_ZZ_CAR_COLOR_DEEP_GOLDEN,		// Deep Golden
	EM_ZZ_CAR_COLOR_OTHER	= 255,		// Other
} EM_ZZ_CAR_COLOR_TYPE;

// Use Property
typedef enum tagEM_ZZ_USE_PROPERTY_TYPE
{
	EM_ZZ_USE_PROPERTY_OTHER,					// Other
	EM_ZZ_USE_PROPERTY_NOTOPERATING,			// Not Operating
	EM_ZZ_USE_PROPERTY_HIGWAY,					// Highway
	EM_ZZ_USE_PROPERTY_BUS,					// Bus
	EM_ZZ_USE_PROPERTY_TAXI,					// Taxi
	EM_ZZ_USE_PROPERTY_TOURISM,				// Tourism
	EM_ZZ_USE_PROPERTY_FREIGHT,				// Freight
	EM_ZZ_USE_PROPERTY_LEASE,					// Lease
	EM_ZZ_USE_PROPERTY_POLICE,					// Police
	EM_ZZ_USE_PROPERTY_FIRE,					// Fire
	EM_ZZ_USE_PROPERTY_RESCUE,					// Rescue
	EM_ZZ_USE_PROPERTY_ENGINEERING,			// Engineering
	EM_ZZ_USE_PROPERTY_OPERATION_TO_NOT,		// Operation To Not
	EM_ZZ_USE_PROPERTY_TAXI_TO_NOT,			// Taxi To Not
	EM_ZZ_USE_PROPERTY_COACH,					// Coach
	EM_ZZ_USE_PROPERTY_KINDER_SCHOOLBUS,		// Kinder Schoolbus
	EM_ZZ_USE_PROPERTY_PUPIL_SCHOOLBUS,		// Pupil Schoolbus
	EM_ZZ_USE_PROPERTY_OTHER_SCHOOLBUS,		// Other Schoolbus
	EM_ZZ_USE_PROPERTY_FOR_DANGE_VEHICLE,		// Danger Vehicle
} EM_ZZ_USE_PROPERTY_TYPE;

// RFID Electronic Tag Info
typedef struct tagZZNET_RFIDELETAG_INFO
{
	BYTE					szCardID[ZZ_MAX_RFIDELETAG_CARDID_LEN];			// Card ID
	int						nCardType;										// Card Type
	EM_ZZ_CARD_PROVINCE		emCardPrivince;									// Card Province
	char					szPlateNumber[ZZ_MAX_PLATE_NUMBER_LEN];			// Plate Number
	char					szProductionDate[ZZ_MAX_RFIDELETAG_DATE_LEN];		// Production Date
	EM_ZZ_CAR_TYPE			emCarType;										// Car Type
	int						nPower;											// Power
	int						nDisplacement;									// Displacement
	int						nAntennaID;										// Antenna ID
	EM_ZZ_PLATE_TYPE		emPlateType;									// Plate Type
	char					szInspectionValidity[ZZ_MAX_RFIDELETAG_DATE_LEN];	// Inspection Validity
	int						nInspectionFlag;								// Inspection Flag
	int						nMandatoryRetirement;							// Mandatory Retirement
	EM_ZZ_CAR_COLOR_TYPE	emCarColor;										// Car Color
	int						nApprovedCapacity;								// Approved Capacity
	int						nApprovedTotalQuality;							// Approved Total Quality
	ZZNET_TIME_EX			stuThroughTime;									// Through Time
	EM_ZZ_USE_PROPERTY_TYPE	emUseProperty;									// Use Property
	char					szPlateCode[ZZ_MAX_COMMON_STRING_8];				// Plate Code
	char					szPlateSN[ZZ_MAX_COMMON_STRING_16];				// Plate SN
	BYTE               		bReserved[104];		                      		// Reserved
} ZZNET_RFIDELETAG_INFO;




#define ZZRESERVED_TYPE_FOR_INTEL_BOX 0x00000001
typedef struct ZZRESERVED_DATA_INTEL_BOX
{
    DWORD  dwEventCount;        // Event Count
    DWORD* dwPtrEventType;      // Event Type Pointer
    DWORD  dwInternalTime;      // Internal Time
    BYTE   bReserved[1020];     // Reserved
}ZZReservedDataIntelBox;

#define ZZRESERVED_TYPE_FOR_COMMON   0x00000010
typedef struct tagZZNET_RESERVED_COMMON
{
    DWORD                   dwStructSize;
    ZZReservedDataIntelBox*   pIntelBox;          // Intel Box
    DWORD                   dwSnapFlagMask;     // Snap Flag Mask
}ZZNET_RESERVED_COMMON;

// Face Detect Info
typedef struct tagZZDEV_EVENT_FACEDETECT_INFO 
{
    int                 nChannelID;                                 // Channel ID
    char                szName[128];                                // Event Name
    char                bReserved1[4];                              // Byte Alignment
    double              PTS;                                        // Timestamp (ms)
    ZZNET_TIME_EX         UTC;                                        // Event Time
    int                 nEventID;                                   // Event ID
    ZZ_MSG_OBJECT       stuObject;                                  // Detected Object
    ZZ_EVENT_FILE_INFO  stuFileInfo;                                // Event File Info
    BYTE                bEventAction;                               // Event Action
    BYTE                reserved[2];                                // Reserved
    BYTE                byImageIndex;                               // Image Index
    int                 nDetectRegionNum;                           // Detection Region Vertices
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM];     // Detection Region
    DWORD               dwSnapFlagMask;                             // Snapshot Flag Mask
    char                szSnapDevAddress[MAX_PATH];                 // Snap Dev Address
    unsigned int        nOccurrenceCount;                           // Occurrence Count
    EM_ZZ_DEV_EVENT_FACEDETECT_SEX_TYPE emSex;                         // Sex
    int        nAge;                                                // Age
    unsigned int        nFeatureValidNum;                           // Feature Valid Num
    EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE    emFeature[ZZ_MAX_FACEDETECT_FEATURE_NUM];   // Features
    int                 nFacesNum;                                  // Faces Num
    ZZNET_FACE_INFO       stuFaces[10];                               // Faces Info
	ZZEVENT_INTELLI_COMM_INFO   stuIntelliCommInfo;                 // Intelligent Common Info
	EM_ZZ_RACE_TYPE				emRace;								// Race
	EM_ZZ_EYE_STATE_TYPE	    emEye;								// Eye
	EM_ZZ_MOUTH_STATE_TYPE		emMouth;							// Mouth
	EM_ZZ_MASK_STATE_TYPE 		emMask;								// Mask
	EM_ZZ_BEARD_STATE_TYPE		emBeard;							// Beard
	int							nAttractive;						// Attractive
	char						szUID[ZZ_COMMON_STRING_32];			// UID
	BYTE                		bReserved[836];                     // Reserved
} ZZDEV_EVENT_FACEDETECT_INFO;

// Taken Away Detection Event Info
typedef struct tagZZDEV_EVENT_TAKENAWAYDETECTION_INFO
{
    int                 nChannelID;                                 // Channel ID
    char                szName[128];                                // Event Name
    char                bReserved1[4];                              // Byte Alignment
    double              PTS;                                        // Timestamp (ms)
    ZZNET_TIME_EX         UTC;                                        // Event Time
    int                 nEventID;                                   // Event ID
    ZZ_MSG_OBJECT       stuObject;                                  // Detected Object
    int                 nDetectRegionNum;                           // Detection Region Vertices
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM];     // Detection Region
    ZZ_EVENT_FILE_INFO  stuFileInfo;                                // Event File Info
    BYTE                bEventAction;                               // Event Action
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // Image Index
    DWORD               dwSnapFlagMask;                             // Snapshot Flag Mask
    int                 nSourceIndex;                               // Source Index
    char                szSourceDevice[MAX_PATH];                   // Source Device ID
    unsigned int        nOccurrenceCount;                           // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;                 // Intelligent Common Info
	short				nPreserID;									// Preset ID
	char				szPresetName[64];							// Preset Name
	BYTE                bReserved[550];                             // Reserved
} ZZDEV_EVENT_TAKENAWAYDETECTION_INFO;

// Number Stat Event Info
typedef struct tagZZDEV_EVENT_NUMBERSTAT_INFO 
{
    int                 nChannelID;                         // Channel ID
    char                szName[128];                        // Event Name
    char                bReserved2[4];                      // Byte Alignment
    double              PTS;                                // Timestamp (ms)
    ZZNET_TIME_EX         UTC;                                // Event Time
    int                 nEventID;                           // Event ID
    int                 nNumber;                            // Number
    int                 nUpperLimit;                        // Upper Limit
    ZZ_EVENT_FILE_INFO  stuFileInfo;                        // Event File Info
    BYTE                bEventAction;                       // Event Action
    BYTE                bReserved1[2];                      // Reserved
    BYTE                byImageIndex;                       // Image Index
    int                 nEnteredNumber;                     // Entered Number
    int                 nExitedNumber;                      // Exited Number
    DWORD               dwSnapFlagMask;                     // Snapshot Flag Mask
    unsigned int        nOccurrenceCount;                   // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;         // Intelligent Common Info
    BYTE                bReserved[828];                     // Reserved
} ZZDEV_EVENT_NUMBERSTAT_INFO;

// Scene Change Event Info
typedef struct tagZZDEV_ALRAM_SCENECHANGE_INFO
{
    int							nChannelID;									// Channel ID
	int                         nEventAction;								// Event Action
    double						dbPTS;										// Timestamp (ms)
    ZZNET_TIME_EX				stuUTC;										// Event Time
    int							nEventID;									// Event ID

    ZZ_EVENT_FILE_INFO			stuFileInfo;								// Event File Info
    BYTE						byImageIndex;								// Image Index
    DWORD						dwSnapFlagMask;								// Snapshot Flag Mask
    BYTE						bReserved[1024];							// Reserved
} ZZDEV_ALRAM_SCENECHANGE_INFO;

// Face Data
typedef struct tagZZNET_FACE_DATA
{
	EM_ZZ_DEV_EVENT_FACEDETECT_SEX_TYPE     emSex;						// Sex
	int        								nAge;						// Age
    unsigned int        					nFeatureValidNum;           // Feature Valid Num
    EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE  emFeature[ZZ_MAX_FACEDETECT_FEATURE_NUM];   // Features
	EM_ZZ_RACE_TYPE							emRace;						// Race
	EM_ZZ_EYE_STATE_TYPE					emEye;						// Eye
	EM_ZZ_MOUTH_STATE_TYPE					emMouth;					// Mouth
	EM_ZZ_MASK_STATE_TYPE 					emMask;						// Mask
	EM_ZZ_BEARD_STATE_TYPE					emBeard;					// Beard
	int										nAttractive;				// Attractive
    BYTE                					bReserved[128];             // Reserved
} ZZNET_FACE_DATA;

// Person Info Extended
typedef struct tagZZFACERECOGNITION_PERSON_INFOEX
{
	char                		szPersonName[ZZ_MAX_PERSON_NAME_LEN];           // Name
    WORD                		wYear;                                          // Year
    BYTE                		byMonth;                                        // Month
    BYTE                		byDay;                                          // Day
    BYTE                		bImportantRank;                                 // Important Rank
    BYTE                		bySex;                                          // Sex
	char                		szID[ZZ_MAX_PERSON_ID_LEN];                     // ID
    WORD                		wFacePicNum;                                    // Face Pic Num
    ZZ_PIC_INFO         		szFacePicInfo[ZZ_MAX_PERSON_IMAGE_NUM];         // Face Pic Info
    BYTE                		byType;                                         // Type
    BYTE                		byIDType;                                       // ID Type
	BYTE						byGlasses;										// Glasses
    BYTE                		byAge;											// Age
    char                		szProvince[ZZ_MAX_PROVINCE_NAME_LEN];           // Province
    char                		szCity[ZZ_MAX_CITY_NAME_LEN];                   // City
    char                		szUID[ZZ_MAX_PERSON_ID_LEN];                    // UID
                                                                        		
	char						szCountry[ZZNET_COUNTRY_LENGTH];					// Country
	BYTE						byIsCustomType;									// Is Custom Type
	char						szCustomType[ZZ_COMMON_STRING_16];				// Custom Type
	char						szComment[ZZNET_COMMENT_LENGTH];					// Comment
	char						szGroupID[ZZNET_GROUPID_LENGTH];					// Group ID
	char						szGroupName[ZZNET_GROUPNAME_LENGTH];				// Group Name
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE	emEmotion;							// Emotion
	char						szHomeAddress[ZZ_COMMON_STRING_128];			// Home Address
	EM_ZZ_GLASSES_TYPE			emGlassesType;									// Glasses Type
	EM_ZZ_RACE_TYPE				emRace;											// Race
	EM_ZZ_EYE_STATE_TYPE		emEye;											// Eye
	EM_ZZ_MOUTH_STATE_TYPE		emMouth;										// Mouth
	EM_ZZ_MASK_STATE_TYPE 		emMask;											// Mask
	EM_ZZ_BEARD_STATE_TYPE		emBeard;										// Beard
	int							nAttractive;									// Attractive
	BYTE                        byReserved[2048];   							// Reserved
} ZZFACERECOGNITION_PERSON_INFOEX;

// Picture Info Extended 3
typedef struct
{
    DWORD           dwOffSet;                       // Offset
    DWORD           dwFileLenth;                    // Length
    WORD            wWidth;                         // Width
    WORD            wHeight;                        // Height
	char            szFilePath[64];                 // File Path
    BYTE            bIsDetected;                    // Is Detected
    BYTE            bReserved[11];                  // Reserved
}ZZ_PIC_INFO_EX3;

typedef struct tagZZFACERECOGNITION_PERSON_INFO
{
    char                szPersonName[ZZ_MAX_NAME_LEN];                  // Name
    WORD                wYear;                                          // Year
    BYTE                byMonth;                                        // Month
    BYTE                byDay;                                          // Day
    char                szID[ZZ_MAX_PERSON_ID_LEN];                     // ID
    BYTE                bImportantRank;                                 // Important Rank
    BYTE                bySex;                                          // Sex
    WORD                wFacePicNum;                                    // Face Pic Num
    ZZ_PIC_INFO         szFacePicInfo[ZZ_MAX_PERSON_IMAGE_NUM];         // Face Pic Info
    BYTE                byType;                                         // Type
    BYTE                byIDType;                                       // ID Type
	BYTE				byGlasses;										// Glasses
    BYTE                byAge;											// Age
    char                szProvince[ZZ_MAX_PROVINCE_NAME_LEN];           // Province
    char                szCity[ZZ_MAX_CITY_NAME_LEN];                   // City
    char                szPersonNameEx[ZZ_MAX_PERSON_NAME_LEN];         // Name Ex
    char                szUID[ZZ_MAX_PERSON_ID_LEN];                    // UID
                                                                        
	char				szCountry[ZZNET_COUNTRY_LENGTH];					// Country
	BYTE				byIsCustomType;									// Is Custom Type
	char				*pszComment;									// Comment
																		
	char				*pszGroupID;									// Group ID
																		
	char				*pszGroupName;									// Group Name
																		
	char				*pszFeatureValue;								// Feature Value
																		
	BYTE				bGroupIdLen;									// Group ID Length
	BYTE				bGroupNameLen;									// Group Name Length
	BYTE				bFeatureValueLen;								// Feature Value Length
	BYTE				bCommentLen;									// Comment Length
	EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE	emEmotion;					// Emotion
}ZZFACERECOGNITION_PERSON_INFO;

// Candidate Info
typedef struct tagZZCANDIDATE_INFO
{
    ZZFACERECOGNITION_PERSON_INFO  stPersonInfo;            // Person Info

    BYTE                         bySimilarity;            // Similarity
    BYTE                         byRange;                 // Range
    BYTE                         byReserved1[2];
    ZZNET_TIME                     stTime;                  // Time
    char                         szAddress[MAX_PATH];     // Address
	BOOL                         bIsHit;                  // Is Hit
	ZZ_PIC_INFO_EX3              stuSceneImage;           // Scene Image
	int							 nChannelID;			  // Channel ID
    BYTE                         byReserved[32];          // Reserved
}ZZCANDIDATE_INFO;

// Candidate Info Extended
typedef struct tagZZCANDIDATE_INFOEX
{
	ZZFACERECOGNITION_PERSON_INFOEX  stPersonInfo;          // Person Info Ex

    BYTE                         bySimilarity;            // Similarity
    BYTE                         byRange;                 // Range
    BYTE                         byReserved1[2];
    ZZNET_TIME                     stTime;                  // Time
    char                         szAddress[MAX_PATH];     // Address
	BOOL                         bIsHit;                  // Is Hit
	ZZ_PIC_INFO_EX3              stuSceneImage;           // Scene Image
	int							 nChannelID;			  // Channel ID
	char            			 szFilePathEx[256];  	  // File Path Ex
    BYTE                         byReserved[1024];   	  // Reserved
} ZZCANDIDATE_INFOEX;

// Face Recognition Event Info
typedef struct tagZZDEV_EVENT_FACERECOGNITION_INFO
{
    int                 nChannelID;                                 // Channel ID
    char                szName[128];                                // Event Name
    int                 nEventID;                                   // Event ID
    ZZNET_TIME_EX         UTC;                                        // Event Time
    ZZ_MSG_OBJECT       stuObject;                                  // Object
    int                 nCandidateNum;                              // Candidate Num
    ZZCANDIDATE_INFO      stuCandidates[ZZ_MAX_CANDIDATE_NUM];        // Candidates
    BYTE                bEventAction;                               // Event Action
    BYTE                byImageIndex;                               // Image Index
    BYTE                byReserved1[2];                             // Alignment
    BOOL                bGlobalScenePic;                            // Global Scene Pic
    ZZ_PIC_INFO         stuGlobalScenePicInfo;                      // Global Scene Pic Info
    char                szSnapDevAddress[MAX_PATH];                 // Snap Dev Address
    unsigned int        nOccurrenceCount;                           // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;                 // Intelligent Common Info
	ZZNET_FACE_DATA		stuFaceData;								// Face Data
	char				szUID[ZZ_COMMON_STRING_32];					// UID
	BYTE                bReserved[1024];                            // Reserved
    int					nRetCandidatesExNum;						// Ret Candidates Ex Num
	ZZCANDIDATE_INFOEX     stuCandidatesEx[ZZ_MAX_CANDIDATE_NUM];     // Candidates Ex
}ZZDEV_EVENT_FACERECOGNITION_INFO;

// Video Abnormal Detection Event Info
typedef struct tagZZDEV_EVENT_VIDEOABNORMALDETECTION_INFO
{
    int                 nChannelID;                                 // Channel ID
    char                szName[128];                                // Event Name
    char                bReserved1[4];                              // Byte Alignment
    double              PTS;                                        // Timestamp (ms)
    ZZNET_TIME_EX       UTC;                                        // Event Time
    int                 nEventID;                                   // Event ID
    ZZ_EVENT_FILE_INFO  stuFileInfo;                                // Event File Info
    BYTE                bEventAction;                               // Event Action
    BYTE                bType;                                      // Type: 0-Video Loss, 1-Video Freeze, 2-Camera Mask, 3-Camera Move, 4-Too Dark, 5-Too Bright, 6-Color Cast, 7-Noise
    BYTE                byReserved[1];
    BYTE                byImageIndex;                               // Image Index
    DWORD               dwSnapFlagMask;                             // Snapshot Flag Mask    
    int                 nSourceIndex;                               // Source Index
    char                szSourceDevice[MAX_PATH];                   // Source Device ID
    unsigned int        nOccurrenceCount;                           // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;                 // Intelligent Common Info
    BYTE                bReserved[620];                             // Reserved
} ZZDEV_EVENT_VIDEOABNORMALDETECTION_INFO;


// Redundancy Info
typedef struct
{
    BYTE                byRedundance[8];                // Redundancy
    BYTE                bReserved[120];                 // Reserved
}ZZ_SIG_CARWAY_INFO_EX;

// Traffic Car Move Direction
typedef enum tagEM_ZZ_TRAFFICCAR_MOVE_DIRECTION
{
    EM_ZZ_TRAFFICCAR_MOVE_DIRECTION_UNKNOWN,                           // Unknown
    EM_ZZ_TRAFFICCAR_MOVE_DIRECTION_STRAIGHT,                          // Straight
    EM_ZZ_TRAFFICCAR_MOVE_DIRECTION_TURN_LEFT,                         // Turn Left
    EM_ZZ_TRAFFICCAR_MOVE_DIRECTION_TURN_RIGHT,                        // Turn Right
    EM_ZZ_TRAFFICCAR_MOVE_DIRECTION_TURN_AROUND,                       // Turn Around
}EM_ZZ_TRAFFICCAR_MOVE_DIRECTION;

// Traffic Car Info
typedef struct tagZZDEV_EVENT_TRAFFIC_TRAFFICCAR_INFO
{
    char               szPlateNumber[32];                   // Plate Number
    char               szPlateType[32];                     // Plate Type
                                                            
    char               szPlateColor[32];                    // Plate Color
    char               szVehicleColor[32];                  // Vehicle Color
    int                nSpeed;                              // Speed
    char               szEvent[64];                         // Event
    char               szViolationCode[32];                 // Violation Code
    char               szViolationDesc[64];                 // Violation Desc
    int                nLowerSpeedLimit;                    // Lower Speed Limit
    int                nUpperSpeedLimit;                    // Upper Speed Limit
    int                nOverSpeedMargin;                    // Over Speed Margin
    int                nUnderSpeedMargin;                   // Under Speed Margin
    int                nLane;                               // Lane
    int                nVehicleSize;                        // Vehicle Size
                                                            
    float              fVehicleLength;                      // Vehicle Length
    int                nSnapshotMode;                       // Snapshot Mode
    char               szChannelName[32];                   // Channel Name
    char               szMachineName[256];                  // Machine Name
    char               szMachineGroup[256];                 // Machine Group
    char               szRoadwayNo[64];                     // Roadway No
    char               szDrivingDirection[3][ZZ_MAX_DRIVINGDIRECTION];      // Driving Direction
                                                                            
    char              *szDeviceAddress;                     // Device Address
    char               szVehicleSign[32];                   // Vehicle Sign
    ZZ_SIG_CARWAY_INFO_EX stuSigInfo;                       // Signal Info
    char              *szMachineAddr;                       // Machine Addr
    float              fActualShutter;                      // Actual Shutter
    BYTE               byActualGain;                        // Actual Gain
    BYTE               byDirection;                         // Direction
    BYTE               byReserved[2];
    char*              szDetailedAddress;                   // Detailed Address
    char               szDefendCode[ZZ_COMMON_STRING_64];   // Defend Code
    int                nTrafficBlackListID;                 // Traffic Blacklist ID
    ZZ_COLOR_RGBA      stuRGBA;                             // RGBA
    ZZNET_TIME           stSnapTime;                          // Snap Time
    int                nRecNo;                              // Rec No
    char               szCustomParkNo[ZZ_COMMON_STRING_32 + 1]; // Custom Park No
    BYTE               byReserved1[3];
    int                nDeckNo;                             // Deck No
    int                nFreeDeckCount;                      // Free Deck Count
    int                nFullDeckCount;                      // Full Deck Count
    int                nTotalDeckCount;                     // Total Deck Count
    char               szViolationName[64];                 // Violation Name
	unsigned int	   nWeight;								// Weight
	char               szCustomRoadwayDirection[32];		// Custom Roadway Direction
    BYTE               byPhysicalLane;                      // Physical Lane
    BYTE               byReserved2[3];
    EM_ZZ_TRAFFICCAR_MOVE_DIRECTION emMovingDirection;         // Moving Direction
    ZZNET_TIME		   stuEleTagInfoUTC;					// Electronic Tag Info UTC
    BYTE               bReserved[552];                      // Reserved
}ZZDEV_EVENT_TRAFFIC_TRAFFICCAR_INFO;


typedef struct tagZZEVENT_COMM_INFO
{
    EM_ZZ_NTP_STATUS			emNTPStatus;											// NTP Status
    int							nDriversNum;											// Drivers Num
    ZZ_MSG_OBJECT_EX			*pstDriversInfo;										// Drivers Info
    char*						pszFilePath;											// File Path
    char*						pszFTPPath;												// FTP Path
    char*						pszVideoPath;											// Video Path
    ZZEVENT_COMM_SEAT			stCommSeat[ZZ_COMMON_SEAT_MAX_NUMBER];						// Comm Seat
	int							nAttachmentNum;											// Attachment Num
	ZZEVENT_COMM_ATTACHMENT		stuAttachment[ZZNET_MAX_ATTACHMENT_NUM];					// Attachment
	int							nAnnualInspectionNum;									// Annual Inspection Num
	ZZNET_RECT					stuAnnualInspection[ZZNET_MAX_ANNUUALINSPECTION_NUM];		// Annual Inspection
    float                       fHCRatio;                                               // HC Ratio
    float                       fNORatio;                                               // NO Ratio
    float                       fCOPercent;                                             // CO Percent
    float                       fCO2Percent;                                            // CO2 Percent
    float                       fLightObscuration;                                      // Light Obscuration
    int                         nPictureNum;                                            // Picture Num
    ZZEVENT_PIC_INFO            stuPicInfos[ZZNET_MAX_EVENT_PIC_NUM];                     // Pic Infos
    float                       fTemperature;                                           // Temperature
    int                         nHumidity;                                              // Humidity
    float                       fPressure;                                              // Pressure
    float                       fWindForce;                                             // Wind Force
    UINT                        nWindDirection;                                         // Wind Direction
    float                       fRoadGradient;                                          // Road Gradient
    float                       fAcceleration;                                          // Acceleration
	ZZNET_RFIDELETAG_INFO		stuRFIDEleTagInfo;										// RFID Info
	BYTE						bReserved[704];											// Reserved
    char						szCountry[20];											// Country
}ZZEVENT_COMM_INFO;


// Traffic Manual Snapshot Event Info
typedef struct tagZZDEV_EVENT_TRAFFIC_MANUALSNAP_INFO
{
    int                 nChannelID;                                 // Channel ID
    char                szName[128];                                // Event Name
    char                bReserved1[4];                              // Byte Alignment
    double              PTS;                                        // Timestamp (ms)
    ZZNET_TIME_EX         UTC;                                        // Event Time
    int                 nEventID;                                   // Event ID
    int                 nLane;                                      // Lane
    BYTE                szManualSnapNo[64];                         // Manual Snap No
    ZZ_MSG_OBJECT       stuObject;                                  // Object
    ZZ_MSG_OBJECT       stuVehicle;                                 // Vehicle
    ZZDEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // Traffic Car
    ZZ_EVENT_FILE_INFO  stuFileInfo;                                // Event File Info
    BYTE                bEventAction;                               // Event Action
    BYTE                byOpenStrobeState;                          // Open Strobe State
	BYTE                byReserved[1];
    BYTE                byImageIndex;                               // Image Index
    DWORD               dwSnapFlagMask;                             // Snap Flag Mask
    ZZ_RESOLUTION_INFO  stuResolution;                              // Resolution
    BYTE                bReserved[1016];                            // Reserved
    ZZEVENT_COMM_INFO     stCommInfo;                                 // Comm Info
}ZZDEV_EVENT_TRAFFIC_MANUALSNAP_INFO;


// Custom Weight Info
typedef struct tagZZEVENT_CUSTOM_WEIGHT_INFO
{
	DWORD        dwRoughWeight;                    // Rough Weight
    DWORD        dwTareWeight;                     // Tare Weight
    DWORD        dwNetWeight;                      // Net Weight
	BYTE		 bReserved[28];					   // Reserved
}ZZEVENT_CUSTOM_WEIGHT_INFO;

// Junction Custom Info
typedef struct tagZZEVENT_JUNCTION_CUSTOM_INFO
{
    ZZEVENT_CUSTOM_WEIGHT_INFO    stuWeightInfo;      // Weight Info
	BYTE						bReserved[60];		// Reserved
}ZZEVENT_JUNCTION_CUSTOM_INFO;


#ifndef LINUX64_JNA
#pragma pack(push)
#pragma pack(4)
#endif
// GPS Info
typedef struct tagZZNET_GPS_INFO
{
    unsigned int                    nLongitude;         	// Longitude
                                                            
                                                            
                                                            
    unsigned int					nLatidude;              // Latitude
                                                            
                                                            
															
    double                          dbAltitude;              // Altitude
    double                          dbSpeed;                 // Speed
    double                          dbBearing;               // Bearing
	BYTE                            bReserved[8];           // Reserved
}ZZNET_GPS_INFO;
#ifndef LINUX64_JNA
#pragma pack(pop)
#endif


#define ZZ_EVENT_MAX_CARD_NUM       16      // Max Card Num
#define ZZ_EVENT_CARD_LEN           36      // Card Len

// Event Card Info
typedef struct tagZZEVENT_CARD_INFO
{
    char szCardNumber[ZZ_EVENT_CARD_LEN];           // Card Number
    BYTE bReserved[32];                             // Reserved
}ZZEVENT_CARD_INFO;

// Extension Info
typedef struct tagZZNET_EXTENSION_INFO
{
	char		szEventLongID[ZZ_MAX_EVENT_LONGID_LEN];		// Event Long ID
	BYTE		byReserved[80];								// Reserved
} ZZNET_EXTENSION_INFO;

///@brief Scene Image Info Ex
typedef struct tagZZSCENE_IMAGE_INFO_EX
{
	unsigned int	   nOffSet;					/// Offset
	unsigned int	   nLength;					/// Length
	unsigned int	   nWidth;					/// Width
	unsigned int	   nHeight;					/// Height
	char               szFilePath[260];         /// File Path
	UINT			   nIndexInData;			/// Index In Data
	char			   szImageID[42];			/// Image ID
	char			   szReserved[6];			/// Reserved
	ZZNET_TIME_EX      SnapTime;                /// Snap Time
	BYTE			   byReserved[424];			/// Reserved
}ZZSCENE_IMAGE_INFO_EX;

///@brief Non-Motor Category Type
typedef enum tagEM_ZZ_CATEGORY_NONMOTOR_TYPE
{
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_UNKNOWN,									/// Unknown
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_TRICYCLE,									/// Tricycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_MOTORCYCLE,								/// Motorcycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_NON_MOTOR,								/// Non-Motor
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_BICYCLE,									/// Bicycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_DUALTRIWHEELMOTORCYCLE,					/// Dual/Tri Wheel Motorcycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_LIGHTMOTORCYCLE,							/// Light Motorcycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_EMBASSYMOTORCYCLE,						/// Embassy Motorcycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_MARGINALMOTORCYCLE,						/// Marginal Motorcycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_AREAOUTMOTORCYCLE,						/// Area Out Motorcycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_FOREIGNMOTORCYCLE,						/// Foreign Motorcycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_TRIALMOTORCYCLE,							/// Trial Motorcycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_COACHMOTORCYCLE,							/// Coach Motorcycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_PASSERBY,									/// Passerby
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_VANTRICYCLE,                              /// Van Tricycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_MANNEDCONVERTIBLETRICYCLE,                /// Manned Convertible Tricycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_NOMANNEDCONVERTIBLETRICYCLE,              /// No Manned Convertible Tricycle
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_ELECTRICBIKE,								/// Electric Bike
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_FOURWHEELER,								/// Four Wheeler
	EM_ZZ_CATEGORY_NONMOTOR_TYPE_SCOOTER,									/// Scooter
}EM_ZZ_CATEGORY_NONMOTOR_TYPE;

///@brief Object Color Type
typedef enum tagEM_ZZ_OBJECT_COLOR_TYPE
{
	EM_ZZ_OBJECT_COLOR_TYPE_UNKNOWN,									    /// Unknown
	EM_ZZ_OBJECT_COLOR_TYPE_WHITE,										    /// White
	EM_ZZ_OBJECT_COLOR_TYPE_ORANGE,									    /// Orange
	EM_ZZ_OBJECT_COLOR_TYPE_PINK,										    /// Pink
	EM_ZZ_OBJECT_COLOR_TYPE_BLACK,										    /// Black
	EM_ZZ_OBJECT_COLOR_TYPE_RED,										    /// Red
	EM_ZZ_OBJECT_COLOR_TYPE_YELLOW,									    /// Yellow
	EM_ZZ_OBJECT_COLOR_TYPE_GRAY,										    /// Gray
	EM_ZZ_OBJECT_COLOR_TYPE_BLUE,										    /// Blue
	EM_ZZ_OBJECT_COLOR_TYPE_GREEN,										    /// Green
	EM_ZZ_OBJECT_COLOR_TYPE_PURPLE,									    /// Purple
	EM_ZZ_OBJECT_COLOR_TYPE_BROWN,										    /// Brown
	EM_ZZ_OBJECT_COLOR_TYPE_SLIVER,									    /// Silver
	EM_ZZ_OBJECT_COLOR_TYPE_DARKVIOLET,								    /// Dark Violet
	EM_ZZ_OBJECT_COLOR_TYPE_MAROON,									    /// Maroon
	EM_ZZ_OBJECT_COLOR_TYPE_DIMGRAY,									    /// Dim Gray
	EM_ZZ_OBJECT_COLOR_TYPE_WHITESMOKE,								    /// White Smoke
	EM_ZZ_OBJECT_COLOR_TYPE_DARKORANGE,								    /// Dark Orange
	EM_ZZ_OBJECT_COLOR_TYPE_MISTYROSE,									    /// Misty Rose
	EM_ZZ_OBJECT_COLOR_TYPE_TOMATO,									    /// Tomato
	EM_ZZ_OBJECT_COLOR_TYPE_OLIVE,										    /// Olive
	EM_ZZ_OBJECT_COLOR_TYPE_GOLD,										    /// Gold
	EM_ZZ_OBJECT_COLOR_TYPE_DARKOLIVEGREEN,							    /// Dark Olive Green
	EM_ZZ_OBJECT_COLOR_TYPE_CHARTREUSE,								    /// Chartreuse
	EM_ZZ_OBJECT_COLOR_TYPE_GREENYELLOW,								    /// Green Yellow
	EM_ZZ_OBJECT_COLOR_TYPE_FORESTGREEN,								    /// Forest Green
	EM_ZZ_OBJECT_COLOR_TYPE_SEAGREEN,									    /// Sea Green
	EM_ZZ_OBJECT_COLOR_TYPE_DEEPSKYBLUE,								    /// Deep Sky Blue
	EM_ZZ_OBJECT_COLOR_TYPE_CYAN,									        /// Cyan
	EM_ZZ_OBJECT_COLOR_TYPE_OTHER,										    /// Other
	EM_ZZ_OBJECT_COLOR_TYPE_FUCHSIA = 31,									/// Fuchsia
	EM_ZZ_OBJECT_COLOR_TYPE_LIME,										    /// Lime
	EM_ZZ_OBJECT_COLOR_TYPE_NAVY,										    /// Navy
	EM_ZZ_OBJECT_COLOR_TYPE_TEAL,										    /// Teal
	EM_ZZ_OBJECT_COLOR_TYPE_AQUA,										    /// Aqua
	EM_ZZ_OBJECT_COLOR_TYPE_ORANGERED,										/// Orange Red
}EM_ZZ_OBJECT_COLOR_TYPE;

///@brief Non-Motor Pic Info
typedef struct tagZZNET_NONMOTOR_PIC_INFO
{
	UINT					uOffset;							/// Offset
	UINT					uLength;							/// Length
	UINT					uWidth;								/// Width
	UINT					uHeight;							/// Height
	char					szFilePath[ZZ_MAX_PATH_LEN];			/// File Path
	UINT			        nIndexInData;			            /// Index In Data
	BYTE					byReserved[508];					/// Reserved
}ZZNET_NONMOTOR_PIC_INFO;

#define ZZ_MAX_RIDER_NUM 16											/// Max Rider Num

///@brief Face Scene Image
typedef struct tagZZFACE_SCENE_IMAGE
{
	unsigned int	   nOffSet;					/// Offset
	unsigned int	   nLength;					/// Length
	unsigned int	   nWidth;					/// Width
	unsigned int	   nHeight;					/// Height
	UINT			   nIndexInData;			/// Index In Data
	BYTE			   byReserved[52];			/// Reserved
} ZZFACE_SCENE_IMAGE;

///@brief Non-Motor Plate Image
typedef struct tagZZNET_NONMOTOR_PLATE_IMAGE
{
	UINT        nOffset;            /// Offset
	UINT        nLength;            /// Length
	UINT        nWidth;             /// Width
	UINT        nHeight;            /// Height
	UINT	    nIndexInData;		/// Index In Data
	BYTE        byReserved[508];    /// Reserved
}ZZNET_NONMOTOR_PLATE_IMAGE;


///@brief Plate Color Type
typedef enum tagEM_ZZ_PLATE_COLOR_TYPE
{
	EM_ZZ_PLATE_COLOR_UNKNOWN,                            /// Unknown
	EM_ZZ_PLATE_COLOR_OTHER,                              /// Other
	EM_ZZ_PLATE_COLOR_BLUE,                               /// Blue
	EM_ZZ_PLATE_COLOR_YELLOW,                             /// Yellow
	EM_ZZ_PLATE_COLOR_WHITE,                              /// White
	EM_ZZ_PLATE_COLOR_BLACK,                              /// Black
	EM_ZZ_PLATE_COLOR_RED,                                /// Red
	EM_ZZ_PLATE_COLOR_GREEN,                              /// Green
	EM_ZZ_PLATE_COLOR_SHADOW_GREEN,					   /// Shadow Green
	EM_ZZ_PLATE_COLOR_YELLOW_GREEN,					   /// Yellow Green
	EM_ZZ_PLATE_COLOR_YELLOW_BOTTOM_BLACK_TEXT,			/// Yellow Bottom Black Text
	EM_ZZ_PLATE_COLOR_BLUE_BOTTOM_WHITE_TEXT,				/// Blue Bottom White Text
	EM_ZZ_PLATE_COLOR_BLACK_BOTTOM_WHITE_TEXT,				/// Black Bottom White Text
}EM_ZZ_PLATE_COLOR_TYPE;

///@brief Non-Motor Plate Info
typedef struct tagZZNET_NONMOTOR_PLATE_INFO
{
	char                        szPlateNumber[128];                 /// Plate Number
	ZZNET_RECT					stuBoundingBox;                     /// Bounding Box
	ZZNET_RECT					stuOriginalBoundingBox;             /// Original Bounding Box
	ZZNET_NONMOTOR_PLATE_IMAGE  stuPlateImage;                      /// Plate Image
	EM_ZZ_PLATE_COLOR_TYPE      emPlateColor;                       /// Plate Color

	BYTE						byReserved[132];					/// Reserved
}ZZNET_NONMOTOR_PLATE_INFO;

// Scene Image Info
typedef struct tagZZSCENE_IMAGE_INFO
{
    UINT	   nOffSet;					/// Offset
    UINT	   nLength;					/// Length
    UINT	   nWidth;					/// Width
    UINT	   nHeight;					/// Height
    UINT	   nIndexInData;			/// Index In Data
    BYTE	   byReserved[52];			/// Reserved
}ZZSCENE_IMAGE_INFO;

///@brief Non-Motor Object
typedef struct tagZZVA_OBJECT_NONMOTOR
{
	int							nObjectID;                          /// Object ID
	EM_ZZ_CATEGORY_NONMOTOR_TYPE	emCategory;							/// Category
	ZZ_RECT						stuBoundingBox;                     /// Bounding Box
	ZZ_RECT						stuOriginalBoundingBox;             /// Original Bounding Box
	ZZNET_COLOR_RGBA				stuMainColor;						/// Main Color
	EM_ZZ_OBJECT_COLOR_TYPE		emColor;							/// Color
	BOOL						bHasImage;							/// Has Image
	ZZNET_NONMOTOR_PIC_INFO		stuImage;							/// Image
	ZZSCENE_IMAGE_INFO			stuSceneImage;						/// Scene Image
	ZZFACE_SCENE_IMAGE			stuFaceSceneImage;					/// Face Scene Image
	int							nNumOfFace;							/// Num Of Face
	float						fSpeed;								/// Speed


	ZZNET_NONMOTOR_PLATE_INFO     stuNomotorPlateInfo;                /// Plate Info
	int 						nCategoryConf;						/// Category Conf
	char 						szNonMotorFeatureVersion[32];		/// Feature Version
	UINT 						nCompleteScore;						/// Complete Score
	UINT						nClarityScore;						/// Clarity Score
	UINT						nStartSequence;						/// Start Sequence
	UINT 						nEndSequence;						/// End Sequence
	BOOL						bIsErrorDetect;						/// Is Error Detect
	UINT 						nImageLightType;					/// Image Light Type
	UINT						nAbsScore;							/// Abs Score
	//EM_RAIN_SHED_TYPE emRainShedType;								/// Rain Shed Type
	char						szSerialUUID[22];					 /// Serial UUID
	/// Effective data bits 21, including '\0'
	/// First 2 bits %d%d: 01-Video Segment, 02-Image, 03-File, 99-Other
	/// Middle 14 bits YYYYMMDDhhmmss
	/// Last 5 bits %u%u%u%u%u: Object ID, e.g. 00001
	char						szReserved[2];							/// Alignment
	UINT						nHumanFeatureExtractSingle;			/// Human Feature Extract Single
	ZZSCENE_IMAGE_INFO			stuHumanImage;						/// Human Image
	BYTE						byReserved[2848];				    /// Reserved
}ZZVA_OBJECT_NONMOTOR;








// Traffic Junction Event Info (Old Rule)
// For historical reasons, for tollgate events, ZZDEV_EVENT_TRAFFICJUNCTION_INFO and ZZ_EVENT_IVS_TRAFFICGATE should be handled together
// ZZ_EVENT_IVS_TRAFFIC_TOLLGATE only supports new tollgate event config
typedef struct tagZZDEV_EVENT_TRAFFICJUNCTION_INFO 
{
    int                 nChannelID;                                 // Channel ID
    char                szName[128];                                // Event Name
    BYTE                byMainSeatBelt;                             // Main Seat Belt
    BYTE                bySlaveSeatBelt;                            // Slave Seat Belt
    BYTE                byVehicleDirection;                         // Vehicle Direction
    BYTE                byOpenStrobeState;                          // Open Strobe State
    double              PTS;                                        // Timestamp (ms)
    ZZNET_TIME_EX       UTC;                                        // Event Time
    int                 nEventID;                                   // Event ID
    ZZ_MSG_OBJECT       stuObject;                                  // Detected Object
    int                 nLane;                                      // Lane
    DWORD               dwBreakingRule;                             // Breaking Rule Mask
                                                                    // 1: Run Red Light;
                                                                    // 2: Wrong Route;
                                                                    // 3: Retrograde; 4: U-Turn;
                                                                    // 5: Traffic Jam; 6: Abnormal Idle;
                                                                    // 7: Over Line; Else: Traffic Junction

    ZZNET_TIME_EX       RedLightUTC;                                // Red Light UTC
    ZZ_EVENT_FILE_INFO  stuFileInfo;                                // Event File Info
    int                 nSequence;                                  // Sequence
    int                 nSpeed;                                     // Speed
    BYTE                bEventAction;                               // Event Action
    BYTE                byDirection;                                // Direction
    BYTE                byLightState;                               // Light State: 0 Unknown, 1 Green, 2 Red, 3 Yellow
    BYTE                byReserved;                                 // Reserved
    BYTE                byImageIndex;                               // Image Index
    ZZ_MSG_OBJECT       stuVehicle;                                 // Vehicle Info
    DWORD               dwSnapFlagMask;                             // Snapshot Flag Mask
    ZZ_RESOLUTION_INFO  stuResolution;                              // Resolution
    char                szRecordFile[ZZ_COMMON_STRING_128];         // Record File
	ZZEVENT_JUNCTION_CUSTOM_INFO   stuCustomInfo;                     // Custom Info
    BYTE                byPlateTextSource;                          // Plate Text Source
	BYTE                bReserved1[3];                               // Reserved
    ZZNET_GPS_INFO      stuGPSInfo;                                 // GPS Info

    BYTE                byNoneMotorInfo;                            // Non-Motor Info Flag
                                                                    
    BYTE                byBag;                                      // Bag
    BYTE                byUmbrella;                                 // Umbrella
    BYTE                byCarrierBag;                               // Carrier Bag    
    BYTE                byHat;                                      // Hat    
    BYTE                byHelmet;                                   // Helmet
    BYTE                bySex;                                      // Sex
    BYTE                byAge;                                      // Age
    ZZNET_COLOR_RGBA    stuUpperBodyColor;                          // Upper Body Color
    ZZNET_COLOR_RGBA    stuLowerBodyColor;                          // Lower Body Color
    BYTE                byUpClothes;                                // Upper Clothes
    BYTE                byDownClothes;                              // Lower Clothes   

    BYTE                bReserved[22];                              // Reserved
    int                 nTriggerType;                               // Trigger Type
    ZZDEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // Traffic Car
    DWORD                   dwRetCardNumber;                            // Ret Card Number
    ZZEVENT_CARD_INFO       stuCardInfo[ZZ_EVENT_MAX_CARD_NUM];         // Card Info   
    ZZEVENT_COMM_INFO       stCommInfo;                                 // Comm Info
	ZZNET_EXTENSION_INFO    stuExtensionInfo;							// Extension Info

    BOOL                    bNonMotorInfoEx;                            /// Non Motor Info Ex
	ZZVA_OBJECT_NONMOTOR    stuNonMotor;                                /// Non Motor
    BOOL                    bSceneImage;                                /// Scene Image Valid
    ZZSCENE_IMAGE_INFO_EX	stuSceneImage;			                    /// Scene Image
} ZZDEV_EVENT_TRAFFICJUNCTION_INFO;

// Man Num List Info
typedef struct tagZZMAN_NUM_LIST_INFO
{
	ZZ_RECT				stuBoudingBox;			// Bounding Box
	int					nStature;				// Stature
	char                szReversed[128];    	// Reserved
} ZZMAN_NUM_LIST_INFO;

// Man Num Detection Info
typedef struct tagZZDEV_EVENT_MANNUM_DETECTION_INFO
{
	int                 		nChannelID;                 // Channel ID
    char                		szName[ZZ_EVENT_NAME_LEN];  // Event Name
    char                		bReserved1[4];              // Alignment
    double              		PTS;                        // Timestamp (ms)
    ZZNET_TIME_EX         		UTC;                        // Event Time
    int                 		nEventID;                   // Event ID
    /////////////////////////////// Common fields above //////////////////////////////
	int                 		nAction;                    // Action
	int							nManListCount;				// Man List Count
	ZZMAN_NUM_LIST_INFO			stuManList[ZZ_MAX_MAN_LIST_COUNT];	// Man List
	ZZEVENT_INTELLI_COMM_INFO   stuIntelliCommInfo;         // Intelligent Common Info
	char                		szReversed[2048];           // Reserved
} ZZDEV_EVENT_MANNUM_DETECTION_INFO;

// Rioter Detection Event (ZZ_ALARM_RIOTERDETECTION)
typedef struct tagZZALARM_RIOTERDETECTION_INFO
{
	int                             nAction;                   		// Action
	int					            nChannelID;						// Channel ID
    double				            dbPTS;							// Timestamp
    ZZNET_TIME_EX			        stuTime;						// Time
    int					            nEventID;						// Event ID

	int 							nCount;							// Count
	BYTE                			byReserved[1024];   			// Reserved
} ZZALARM_RIOTERDETECTION_INFO;

// Crossline Direction
typedef enum tagZZNET_CROSSLINE_DIRECTION_INFO
{
    EM_ZZ_CROSSLINE_DIRECTION_UNKNOW = 0 , 
    EM_ZZ_CROSSLINE_DIRECTION_LEFT2RIGHT ,   // Left to Right
    EM_ZZ_CROSSLINE_DIRECTION_RIGHT2LEFT ,   // Right to Left
    EM_ZZ_CROSSLINE_DIRECTION_ANY        ,   
}ZZNET_CROSSLINE_DIRECTION_INFO;

// Cross Fence Detection Event (ZZ_ALARM_CROSSFENCEDETECTION)
typedef struct tagZZALARM_CROSSFENCEDETECTION_INFO
{
	int                             nAction;                   		// Action
	int					            nChannelID;						// Channel ID
    double				            dbPTS;							// Timestamp
    ZZNET_TIME_EX			        stuTime;						// Time
    int					            nEventID;						// Event ID

	ZZNET_CROSSLINE_DIRECTION_INFO	emCrossDirection;               // Direction
	int 							nCount;							// Count
	BYTE                			byReserved[1024];   			// Reserved
} ZZALARM_CROSSFENCEDETECTION_INFO;

// Move Event Info
typedef struct tagZZDEV_EVENT_MOVE_INFO 
{
    int                 nChannelID;                         // Channel ID
    char                szName[128];                        // Event Name
    char                bReserved1[4];                      // Byte Alignment
    double              PTS;                                // Timestamp
    ZZNET_TIME_EX       UTC;                                // Time
    int                 nEventID;                           // Event ID
    ZZ_MSG_OBJECT       stuObject;                          // Object
    ZZ_EVENT_FILE_INFO  stuFileInfo;                        // File Info
    BYTE                bEventAction;                       // Action
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // Image Index
    int                 nDetectRegionNum;                   // Detect Region Num
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM];    // Detect Region
    DWORD               dwSnapFlagMask;                     // Snap Flag Mask    
    int                 nSourceIndex;                       // Source Index
    char                szSourceDevice[MAX_PATH];           // Source Device
    int                 nTrackLineNum;                      // Track Line Num                 
    ZZ_POINT            stuTrackLine[ZZ_MAX_TRACK_LINE_NUM];// Track Line      
    unsigned int        nOccurrenceCount;                   // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;         // Intelligent Common Info
    BYTE                bReserved[404];                     // Reserved
} ZZDEV_EVENT_MOVE_INFO;

// Driver Calling Event Info
typedef struct  tagZZDEV_EVENT_TRAFFIC_DRIVER_CALLING
{
    int                     nChannelID;                     // Channel ID
    char                    szName[ZZ_EVENT_NAME_LEN];      // Event Name
    int                     nTriggerType;                   // Trigger Type
    DWORD                   PTS;                            // Timestamp
    ZZNET_TIME_EX           UTC;                            // Time
    int                     nEventID;                       // Event ID
    int                     nSequence;                      // Sequence
    BYTE                    byEventAction;                  // Action
    BYTE                    byImageIndex;                   // Image Index
    BYTE                    byReserved1[2];
    ZZ_EVENT_FILE_INFO      stuFileInfo;                    // File Info
    int                     nLane;                          // Lane
    int                     nMark;                          // Mark
    int                     nFrameSequence;                 // Frame Sequence
    int                     nSource;                        // Source
    ZZ_MSG_OBJECT           stuObject;                      // Object
    ZZ_MSG_OBJECT           stuVehicle;                     // Vehicle
    ZZDEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stuTrafficCar;        // Traffic Car
    int                     nSpeed;                         // Speed
    DWORD                   dwSnapFlagMask;                 // Snap Flag Mask    
    ZZ_RESOLUTION_INFO      stuResolution;                  // Resolution
    ZZEVENT_COMM_INFO         stCommInfo;                     // Comm Info
    ZZNET_GPS_INFO            stuGPSInfo;                     // GPS Info
    BYTE                    byReserved[984];                // Reserved
}ZZDEV_EVENT_TRAFFIC_DRIVER_CALLING;

// Fight Event Info
typedef struct tagZZDEV_EVENT_FIGHT_INFO 
{
    int                 nChannelID;                         // Channel ID
    char                szName[128];                        // Event Name
    char                bReserved1[4];                      // Byte Alignment
    double              PTS;                                // Timestamp
    ZZNET_TIME_EX       UTC;                                // Time
    int                 nEventID;                           // Event ID
    int                 nObjectNum;                         // Object Num
    ZZ_MSG_OBJECT       stuObjectIDs[ZZ_MAX_OBJECT_LIST];   // Object IDs
    ZZ_EVENT_FILE_INFO  stuFileInfo;                        // File Info
    BYTE                bEventAction;                       // Action
    BYTE                byReserved[2];                      // Reserved
    BYTE                byImageIndex;                       // Image Index
    int                 nDetectRegionNum;                   // Detect Region Num
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM];    // Detect Region
    
    DWORD               dwSnapFlagMask;                     // Snap Flag Mask    
    int                 nSourceIndex;                       // Source Index
    char                szSourceDevice[MAX_PATH];           // Source Device
    unsigned int        nOccurrenceCount;                   // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;       // Intelligent Common Info
    BYTE                bReserved[492];                     // Reserved
} ZZDEV_EVENT_FIGHT_INFO;

// Stay Event Info
typedef struct tagZZDEV_EVENT_STAY_INFO 
{
    int                 nChannelID;                         // Channel ID
    char                szName[128];                        // Event Name
    char                bReserved1[4];                      // Byte Alignment
    double              PTS;                                // Timestamp
    ZZNET_TIME_EX       UTC;                                // Time
    int                 nEventID;                           // Event ID
    ZZ_MSG_OBJECT       stuObject;                          // Object
    ZZ_EVENT_FILE_INFO  stuFileInfo;                        // File Info
    BYTE                bEventAction;                       // Action
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // Image Index
    int                 nDetectRegionNum;                   // Detect Region Num
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM]; // Detect Region
    DWORD               dwSnapFlagMask;                     // Snap Flag Mask    
    int                 nSourceIndex;                       // Source Index
    char                szSourceDevice[MAX_PATH];           // Source Device
    unsigned int        nOccurrenceCount;                   // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;         // Intelligent Common Info
    BYTE                bReserved[488];                     // Reserved
} ZZDEV_EVENT_STAY_INFO;

// Tumble Detection Event Info
typedef struct tagZZDEV_EVENT_TUMBLE_DETECTION_INFO
{
    int                     nChannelID;                             // Channel ID
    char                    szName[ZZ_EVENT_NAME_LEN];              // Event Name
    char                    bReserved1[4];                          // Byte Alignment
    double                  PTS;                                    // Timestamp
    ZZNET_TIME_EX           UTC;                                    // Time
    int                     nEventID;                               // Event ID
	int						UTCMS;									// UTC MS	

	EM_ZZ_CLASS_TYPE		emClassType;							// Class Type		
	int						nObjectID;								// Object ID
	char					szObjectType[ZZ_COMMON_STRING_16];		// Object Type
																	
																	
	ZZNET_RECT				stuBoundingBox;							// Bounding Box

	BYTE                    bReserved[1024];                        // Reserved
} ZZDEV_EVENT_TUMBLE_DETECTION_INFO;

// Abnormal Run Detection Event Info
typedef struct tagZZDEV_EVENT_ABNORMALRUNDETECTION 
{
    int                 nChannelID;                                 // Channel ID
    char                szName[128];                                // Event Name
    char                bReserved1[4];                              // Byte Alignment
    double              PTS;                                        // Timestamp
    ZZNET_TIME_EX         UTC;                                        // Time
    int                 nEventID;                                   // Event ID
    ZZ_MSG_OBJECT       stuObject;                                  // Object
    double              dbSpeed;                                    // Speed
    double              dbTriggerSpeed;                             // Trigger Speed
    int                 nDetectRegionNum;                           // Detect Region Num
    ZZ_POINT            DetectRegion[ZZ_MAX_DETECT_REGION_NUM];     // Detect Region
    int                 nTrackLineNum;                              // Track Line Num                 
    ZZ_POINT            TrackLine[ZZ_MAX_TRACK_LINE_NUM];           // Track Line
    ZZ_EVENT_FILE_INFO  stuFileInfo;                                // File Info
    BYTE                bEventAction;                               // Action
    BYTE                bRunType;                                   // Run Type
    BYTE                byReserved[1];
    BYTE                byImageIndex;                               // Image Index
    DWORD               dwSnapFlagMask;                             // Snap Flag Mask    
    int                 nSourceIndex;                               // Source Index
    char                szSourceDevice[MAX_PATH];                   // Source Device
    unsigned int        nOccurrenceCount;                           // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;                 // Intelligent Common Info
    BYTE                bReserved[616];                             // Reserved
} ZZDEV_EVENT_ABNORMALRUNDETECTION_INFO;

// PTZ Space Unit
typedef struct tagZZPTZ_SPACE_UNIT
{
    int                    nPositionX;           // Pan
    int                    nPositionY;           // Tilt
    int                    nZoom;                // Zoom
    char                   szReserve[32];        // Reserved
}ZZPTZ_SPACE_UNIT;

// Smoke Detection Event Info
typedef struct tagZZDEV_EVENT_SMOKE_INFO 
{
    int                 nChannelID;                         // Channel ID
    char                szName[128];                        // Event Name
    char                bReserved1[4];                      // Byte Alignment
    double              PTS;                                // Timestamp
    ZZNET_TIME_EX         UTC;                                // Time
    int                 nEventID;                           // Event ID
    ZZ_MSG_OBJECT       stuObject;                          // Object
    ZZ_EVENT_FILE_INFO  stuFileInfo;                        // File Info
    BYTE                bEventAction;                       // Action
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // Image Index
    DWORD               dwSnapFlagMask;                     // Snap Flag Mask   
    unsigned int        nOccurrenceCount;                   // Occurrence Count
    ZZEVENT_INTELLI_COMM_INFO     stuIntelliCommInfo;         // Intelligent Common Info
	ZZPTZ_SPACE_UNIT		stuPtzPosition;						// PTZ Position
    BYTE                bReserved[792];                     // Reserved
} ZZDEV_EVENT_SMOKE_INFO;





///@brief Age Segment
typedef enum tagEM_ZZ_AGE_SEG
{
    EM_ZZ_AGE_SEG_UNKOWN = 0,								/// Unknown
    EM_ZZ_AGE_SEG_BABY = 2,										/// Baby
    EM_ZZ_AGE_SEG_CHILD = 10,									/// Child
    EM_ZZ_AGE_SEG_YOUTH = 28,									/// Youth
    EM_ZZ_AGE_SEG_MIDDLE = 50,									/// Middle-aged
    EM_ZZ_AGE_SEG_OLD = 60,										/// Old
}EM_ZZ_AGE_SEG;

// Face Detect Glasses Type
typedef enum tagEM_ZZ_FACEDETECT_GLASSES_TYPE
{
	EM_ZZ_FACEDETECT_GLASSES_UNKNOWN,      // Unknown
	EM_ZZ_FACEDETECT_WITH_GLASSES,         // With Glasses
	EM_ZZ_FACEDETECT_WITHOUT_GLASSES,      // Without Glasses
}EM_ZZ_FACEDETECT_GLASSES_TYPE;


///@brief Face Attribute
typedef struct tagZZNET_FACE_ATTRIBUTE
{
    EM_ZZ_DEV_EVENT_FACEDETECT_SEX_TYPE     emSex;						/// Sex
    int        								nAge;						/// Age
    unsigned int        					nFeatureValidNum;           /// Feature Valid Num
    EM_ZZDEV_EVENT_FACEDETECT_FEATURE_TYPE  emFeatures[ZZ_MAX_FACEDETECT_FEATURE_NUM];   /// Features
    char									szReserved[4];
    EM_ZZ_EYE_STATE_TYPE				    emEye;						/// Eye
    EM_ZZ_MOUTH_STATE_TYPE					emMouth;					/// Mouth
    EM_ZZ_MASK_STATE_TYPE 					emMask;						/// Mask
    EM_ZZ_BEARD_STATE_TYPE					emBeard;					/// Beard
    int										nAttractive;				/// Attractive
    ZZNET_RECT								stuBoundingBox;				/// Bounding Box

    ZZNET_EULER_ANGLE				        stuFaceCaptureAngle;		/// Face Capture Angle
    /// Angle Range [-90,90], 999 means invalid
    UINT                                    nFaceQuality;               /// Face Quality
    int                                     nFaceAlignScore;            /// Face Align Score
    int                                     nFaceClarity;               /// Face Clarity
    ZZNET_POINT                             stuFaceCenter;              /// Face Center
    EM_ZZ_FACEDETECT_GLASSES_TYPE           emGlass;                    /// Glasses
    UINT									nFaceDetectConf;			/// Face Detect Confidence
    ZZNET_FACE_ORIGINAL_SIZE                stuOriginalSize;            /// Original Size
    int										arrAngleStatus[3];			/// Angle Status

    UINT 									nIlluminationScore;			/// Illumination Score
    char 									nLeftEyeCoverConf;			/// Left Eye Cover Conf
    char 									nLeftCheekCoverConf;		/// Left Cheek Cover Conf
    char 									nMouthCoverConf;			/// Mouth Cover Conf
    char 									nRightEyeCoverConf;			/// Right Eye Cover Conf
    char 									nRightCheekCoverConf;		/// Right Cheek Cover Conf
    char 									nChinCoverConf;				/// Chin Cover Conf
    char 									nIsCompleteFace;			/// Is Complete Face
    char 									nSaturationScore;			/// Saturation Score
    char 									nBrowCoverConf;				/// Brow Cover Conf
    char 									nNoseCoverConf;				/// Nose Cover Conf
    BYTE                					bReserved0[2];				/// Reserved
    EM_ZZ_AGE_SEG					        emAgeSeg;						/// Age Segment
    BYTE                					bReserved[36];              /// Reserved
} ZZNET_FACE_ATTRIBUTE;

// Human Trait Extension Info
typedef struct tagZZNET_HUMANTRAIT_EXTENSION_INFO
{
	char				szAdditionalCode[ZZ_MAX_HUMANTRAIT_EVENT_LEN];		// Additional Code			
	BYTE				byReserved[32];									// Reserved
} ZZNET_HUMANTRAIT_EXTENSION_INFO;

// Detect Object
typedef enum tagEM_ZZ_DETECT_OBJECT
{
	EM_ZZ_DETECT_OBJECT_UNKNOWN,					// Unknown
	EM_ZZ_DETECT_OBJECT_HUMAN_BODY_AND_FACE,		// Body and Face
	EM_ZZ_DETECT_OBJECT_HUMAN_BODY,				// Body Only
	EM_ZZ_DETECT_OBJECT_HUMAN_FACE,				// Face Only
}EM_ZZ_DETECT_OBJECT;

// Human Image Info
typedef struct tagZZHUMAN_IMAGE_INFO
{
    UINT       nOffSet;					/// Offset 		
    UINT	   nLength;					/// Length
    UINT	   nWidth;					/// Width
    UINT	   nHeight;					/// Height
    UINT	   nIndexInData;			/// Index In Data
    BYTE	   byReserved[52];			/// Reserved
}ZZHUMAN_IMAGE_INFO;

///@brief Face Image Info
typedef struct tagZZFACE_IMAGE_INFO
{
    UINT	   nOffSet;					/// Offset   
    UINT	   nLength;					/// Length
    UINT	   nWidth;					/// Width
    UINT	   nHeight;					/// Height
    UINT	   nIndexInData;			/// Index In Data
    BYTE	   byReserved[52];			/// Reserved
}ZZFACE_IMAGE_INFO;

// Clothes Color
typedef enum tagEM_ZZ_CLOTHES_COLOR
{
	EM_ZZ_CLOTHES_COLOR_UNKNOWN,		// Unknown
	EM_ZZ_CLOTHES_COLOR_WHITE,			// White
	EM_ZZ_CLOTHES_COLOR_ORANGE,		// Orange
	EM_ZZ_CLOTHES_COLOR_PINK,			// Pink
	EM_ZZ_CLOTHES_COLOR_BLACK,			// Black
	EM_ZZ_CLOTHES_COLOR_RED,			// Red
	EM_ZZ_CLOTHES_COLOR_YELLOW,		// Yellow
	EM_ZZ_CLOTHES_COLOR_GRAY,			// Gray
	EM_ZZ_CLOTHES_COLOR_BLUE,			// Blue
	EM_ZZ_CLOTHES_COLOR_GREEN,			// Green 
	EM_ZZ_CLOTHES_COLOR_PURPLE,		// Purple
	EM_ZZ_CLOTHES_COLOR_BROWN,			// Brown
}EM_ZZ_CLOTHES_COLOR;

// Coat Type
typedef enum tagEM_ZZ_COAT_TYPE
{
	EM_ZZ_COAT_TYPE_UNKNOWN,			// Unknown
	EM_ZZ_COAT_TYPE_LONG_SLEEVE,		// Long Sleeve
	EM_ZZ_COAT_TYPE_COTTA,				// Short Sleeve
}EM_ZZ_COAT_TYPE;

// Trousers Type
typedef enum tagEM_ZZ_TROUSERS_TYPE
{
	EM_ZZ_TROUSERS_TYPE_UNKNOWN,		// Unknown
	EM_ZZ_TROUSERS_TYPE_TROUSERS,		// Trousers
	EM_ZZ_TROUSERS_TYPE_SHORTS,		// Shorts
	EM_ZZ_TROUSERS_TYPE_SKIRT,			// Skirt
}EM_ZZ_TROUSERS_TYPE;

// Has Hat
typedef enum tagEM_ZZ_HAS_HAT
{
	EM_ZZ_HAS_HAT_UNKNOWN,				// Unknown
	EM_ZZ_HAS_HAT_NO,					// No Hat
	EM_ZZ_HAS_HAT_YES,					// Has Hat
}EM_ZZ_HAS_HAT;


// Has Bag
typedef enum tagEM_ZZ_HAS_BAG
{
	EM_ZZ_HAS_BAG_UNKNOWN,				// Unknown
	EM_ZZ_HAS_BAG_NO,					// No Bag
	EM_ZZ_HAS_BAG_YES,					// Has Bag
}EM_ZZ_HAS_BAG;

///@brief Sex Type
typedef enum tagEM_ZZ_SEX_TYPE
{
	EM_ZZ_SEX_TYPE_UNKNOWN,        /// Unknown
	EM_ZZ_SEX_TYPE_MALE,           /// Male
	EM_ZZ_SEX_TYPE_FEMALE,         /// Female
}EM_ZZ_SEX_TYPE;

// Human Attributes Info
typedef struct tagZZHUMAN_ATTRIBUTES_INFO
{
	EM_ZZ_CLOTHES_COLOR    emCoatColor;									// Coat Color
	EM_ZZ_COAT_TYPE		emCoatType;										// Coat Type
	EM_ZZ_CLOTHES_COLOR	emTrousersColor;								// Trousers Color
	EM_ZZ_TROUSERS_TYPE	emTrousersType;									// Trousers Type
	EM_ZZ_HAS_HAT			emHasHat;										// Has Hat
	EM_ZZ_HAS_BAG			emHasBag;										// Has Bag

	int					nAge;											/// Age
	EM_ZZ_SEX_TYPE			emSex;											/// Sex
	BYTE				byReserved[120];								// Reserved
}ZZHUMAN_ATTRIBUTES_INFO;








// Human Trait Info
typedef struct tagZZDEV_EVENT_HUMANTRAIT_INFO
{
	int					    nChannelID;									  // Channel ID
	char				    szName[ZZ_EVENT_NAME_LEN];					  // Event Name
	int                     nEventID;                                     // Event ID
	double                  PTS;                                          // Timestamp
	ZZNET_TIME_EX           UTC;                                          // Event Time
	int                     nAction;                                      // Action
	
	EM_ZZ_CLASS_TYPE		emClassType;								  // Class Type
	int					    nGroupID;									  // Group ID
	int					    nCountInGroup;								  // Count In Group
	int					    nIndexInGroup;								  // Index In Group
	ZZHUMAN_IMAGE_INFO	    stuHumanImage;								  // Human Image
	ZZFACE_IMAGE_INFO		stuFaceImage;								  // Face Image
	EM_ZZ_DETECT_OBJECT	    emDetectObject;								  // Detect Object
	ZZHUMAN_ATTRIBUTES_INFO stuHumanAttributes;						  // Human Attributes
    ZZSCENE_IMAGE_INFO      stuSceneImage;                                // Scene Image
    ZZNET_FACE_ATTRIBUTE	stuFaceAttributes;							  /// Face Attributes
    ZZFACE_SCENE_IMAGE	    stuFaceSceneImage;							  /// Face Scene Image
	ZZNET_EXTENSION_INFO    stuExtensionInfo;							  // Extension Info
	ZZNET_HUMANTRAIT_EXTENSION_INFO	stuHumanTrait;					  // Human Trait Extension
	BYTE				byReserved[452];							  // Reserved
}ZZDEV_EVENT_HUMANTRAIT_INFO;





///@brief Motion Detect Region Info
typedef struct tagZZNET_MOTIONDETECT_REGION_INFO
{
	UINT			nRegionID;					/// Region ID
	char			szRegionName[64];			/// Region Name
	BYTE        	bReserved[508];				/// Reserved
} ZZNET_MOTIONDETECT_REGION_INFO;

///@brief Smart Detect Human Object
typedef struct tagZZNET_SMARTDETECT_HUMAN_OBJECT
{
	UINT				nHumanID;					/// Human ID
	ZZNET_RECT			stuRect;					/// Position
	BYTE        	    bReserved[508];				/// Reserved
} ZZNET_SMARTDETECT_HUMAN_OBJECT;

///@brief Event Info Extend
typedef struct tagZZNET_EVENT_INFO_EXTEND
{
	BOOL				bRealUTC;							/// Real UTC Valid
	char				byReserved[4];						/// Alignment	
	ZZNET_TIME_EX       stuRealUTC;                         /// Real UTC
	BOOL			    bIsEventsTypeValid;					/// Events Type Valid
	UINT			    szEventsType;						/// Events Type
	char				szReserved[1012];					/// Reserved		
}ZZNET_EVENT_INFO_EXTEND;

///@brief Smart Detect Vehicle Object
typedef struct tagZZNET_SMARTDETECT_VEHICLE_OBJECT
{
	UINT				nVehicleID;					/// Vehicle ID
	ZZNET_RECT			stuRect;					/// Position
	BYTE        	    bReserved[508];				/// Reserved
} ZZNET_SMARTDETECT_VEHICLE_OBJECT;

///@brief Smart Motion Human Info
typedef struct tagZZDEV_EVENT_SMARTMOTION_HUMAN_INFO
{
	int                             nChannelID;                                 /// Channel ID
	int                             nAction;                                    /// Action
	char                            szName[128];                                /// Event Name
	double                          PTS;                                        /// Timestamp
	ZZNET_TIME_EX                   UTC;                                        /// Event Time
	UINT                            nEventID;                                   /// Event ID   

	ZZNET_MOTIONDETECT_REGION_INFO  stuSmartRegion[32];                         /// Smart Region
	UINT                            nSmartRegionNum;                            /// Smart Region Num
	UINT                            nHumanObjectNum;                            /// Human Object Num
	ZZNET_SMARTDETECT_HUMAN_OBJECT  stuHumanObject[64];   						/// Human Object
	ZZNET_EVENT_INFO_EXTEND		    stuEventInfoEx;						        /// Event Info Ex                      
	BYTE                            bReserved[1024];                            /// Reserved
} ZZDEV_EVENT_SMARTMOTION_HUMAN_INFO;

///@brief Smart Motion Vehicle Info
typedef struct tagZZDEV_EVENT_SMARTMOTION_VEHICLE_INFO
{
	int                             nChannelID;                                 /// Channel ID
	int                             nAction;                                    /// Action
	char                            szName[128];                                /// Event Name
	double                          PTS;                                        /// Timestamp
	ZZNET_TIME_EX                   UTC;                                        /// Event Time
	UINT                            nEventID;                                   /// Event ID   

	ZZNET_MOTIONDETECT_REGION_INFO  stuSmartRegion[32];                         /// Smart Region
	UINT                            nSmartRegionNum;                            /// Smart Region Num
	UINT                            nVehicleObjectNum;                          /// Vehicle Object Num
	ZZNET_SMARTDETECT_VEHICLE_OBJECT  stuVehicleObject[64];                       /// Vehicle Object
	ZZNET_EVENT_INFO_EXTEND		    stuEventInfoEx;						        /// Event Info Ex
	BYTE                            bReserved[1024];                            /// Reserved
} ZZDEV_EVENT_SMARTMOTION_VEHICLE_INFO;
















// Event File Tag Type
typedef enum __EM_ZZ_EVENT_FILETAG
{
    ZZ_ATMBEFOREPASTE = 1,                      // ATM Before Paste
    ZZ_ATMAFTERPASTE,                           // ATM After Paste
}EM_ZZ_EVENT_FILETAG;

// Corresponds to ZZNETSDK_StartSearchDevices interface
typedef struct 
{
    int                 iIPVersion;                             // 4 for IPV4, 6 for IPV6
    char                szIP[64];                               // IP
    int                 nPort;                                  // TCP Port
    char                szSubmask[64];                          // Submask
    char                szGateway[64];                          // Gateway
    char                szMac[ZZ_MACADDR_LEN];                  // MAC
    char                szDeviceType[ZZ_DEV_TYPE_LEN];          // Device Type
    BYTE                byManuFactory;                          // Manufacturer
    BYTE                byDefinition;                           // 1-SD 2-HD
    bool                bZzcpEn;                                // Zzcp Enable
    BYTE                byReserved1;                            // Alignment
    char                verifyData[88];                         // Verify Data
    char                szSerialNo[ZZ_DEV_SERIALNO_LEN];        // Serial No
    char                szDevSoftVersion[ZZ_MAX_URL_LEN];       // Soft Version    
    char                szDetailType[ZZ_DEV_TYPE_LEN];          // Detail Type
    char                szVendor[ZZ_MAX_STRING_LEN];            // Vendor
    char                szDevName[ZZ_MACHINE_NAME_NUM];         // Dev Name
    char                szUserName[ZZ_USER_NAME_LENGTH_EX];     // User Name
    char                szPassWord[ZZ_USER_NAME_LENGTH_EX];     // Password
    unsigned short      nHttpPort;                              // HTTP Port
    WORD                wVideoInputCh;                          // Video Input Channels
    WORD                wRemoteVideoInputCh;                    // Remote Video Input Channels
    WORD                wVideoOutputCh;                         // Video Output Channels
    WORD                wAlarmInputCh;                          // Alarm Input Channels
    WORD                wAlarmOutputCh;                         // Alarm Output Channels
    BOOL                bNewWordLen;                            // Use new password field
    char                szNewPassWord[ZZ_COMMON_STRING_64];     // New Password
    BYTE				byInitStatus;							// Init Status
																
																
																

	BYTE				byPwdResetWay;							// Password Reset Way
																
																
	BYTE				bySpecialAbility;						// Special Ability

    char                szNewDetailType[ZZ_COMMON_STRING_64];   // New Detail Type 
	BOOL				bNewUserName;							// Use new username field
	char				szNewUserName[ZZ_COMMON_STRING_64];		// New User Name
	char                cReserved[41];
}ZZDEVICE_NET_INFO_EX;

// Corresponds to ZZNETSDK_SearchDevicesByIPs interface
typedef struct
{
    DWORD               dwSize;                                 // Size
    int                 nIpNum;                                 // IP Num
    char                szIP[ZZ_MAX_SAERCH_IP_NUM][64];         // IPs
}ZZDEVICE_IP_SEARCH_INFO;

// Device Search Param
typedef struct tagZZNET_DEVICE_SEARCH_PARAM
{
    DWORD       dwSize;
    BOOL        bUseDefault;
    WORD        wBroadcastLocalPort;
    WORD        wBroadcastRemotePort;
    WORD        wMulticastRemotePort;
}ZZNET_DEVICE_SEARCH_PARAM;


///@brief Disconnect Callback
typedef void (CALLBACK *ffDisConnect)(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

// Message Callback (pBuf memory allocated/freed by SDK)
typedef BOOL (CALLBACK *fMessCallBack)(LONG lCommand, LLONG lLoginID, char *pBuf, DWORD dwBufLen, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);
// New parameters description
// bAlarmAckFlag : TRUE, event can be acknowledged; FALSE, cannot be acknowledged
// nEventID : Used for ZZNETSDK_AlarmAck input, valid when bAlarmAckFlag is TRUE
// pBuf memory allocated/freed by SDK
typedef BOOL (CALLBACK *fMessCallBackEx1)(LONG lCommand, LLONG lLoginID, char *pBuf, DWORD dwBufLen, char *pchDVRIP, LONG nDVRPort, BOOL bAlarmAckFlag, LONG nEventID, LDWORD dwUser);

// Snap Callback (pBuf memory allocated/freed by SDK)
// EncodeType 10: jpeg, 0: mpeg4 i-frame
typedef void (CALLBACK *fSnapRev)(LLONG lLoginID, BYTE *pBuf, UINT RevLen, UINT EncodeType, DWORD CmdSerial, LDWORD dwUser);

// Service Callback
typedef int (CALLBACK *fServiceCallBack)(LLONG lHandle, char *pIp, WORD wPort, LONG lCommand, void *pParam, DWORD dwParamLen, LDWORD dwUserData);

// Real Data Callback (pBuffer memory allocated/freed by SDK)
typedef void (CALLBACK *fRealDataCallBack)(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser);

// VT Event Callback
typedef int (CALLBACK *pfVtEventCallBack)(LLONG instId, LLONG ulRegisterId, LLONG ulSessionId, int nEvent, char *pDataBuf, DWORD dwBufSize, LDWORD dwUser);

// Download Position Callback
// dwDownLoadSize == -1 means complete
// dwDownLoadSize == -2 means no permission
typedef void (CALLBACK *fDownLoadPosCallBack)(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, LDWORD dwUser);

// Data Callback
// pBuffer: Data buffer, memory allocated/freed by SDK
// dwDataType: 0-Original record file data, 1-Private stream data
typedef int (CALLBACK *fDataCallBack)(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser);

// Async Search Devices Callback (pDevNetInfo memory allocated/freed by SDK)
typedef void (CALLBACK *ffSearchDevicesCB)(ZZDEVICE_NET_INFO_EX *pDevNetInfo, void* pUserData);

// Analyzer Data Callback
typedef int  (CALLBACK *fAnalyzerDataCallBack)(LLONG lAnalyzerHandle, DWORD dwAlarmType, void* pAlarmInfo, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser, int nSequence, void *reserved);


// Upgrade Callback
// nTotalSize = 0, nSendSize = -1: Complete
// nTotalSize = 0, nSendSize = -2: Error
// nTotalSize = 0, nSendSize = -3: No permission
// nTotalSize = -1, nSendSize = XX: Upgrade progress
// nTotalSize = XX, nSendSize = XX: File send progress
typedef void (CALLBACK *fUpgradeCallBack) (LLONG lLoginID, LLONG lUpgradechannel, int nTotalSize, int nSendSize, LDWORD dwUser);

// Audio Data Callback (pDataBuf memory allocated/freed by SDK)
// When byAudioFlag is 2, pDataBuf is raw PCM without header
typedef void (CALLBACK *pfAudioDataCallBack)(LLONG lTalkHandle, char *pDataBuf, DWORD dwBufSize, BYTE byAudioFlag, LDWORD dwUser);






// Query Type
typedef enum tagEM_ZZNET_QUERY_TYPE
{
    ZZNET_APP_DATA_STAT ,     // App Data Stat
    ZZNET_APP_LINK_STAT ,     // App Link Stat
}EM_ZZNET_QUERY_TYPE;

// Capture Formats
typedef enum tagZZNET_CAPTURE_FORMATS
{
    ZZNET_CAPTURE_BMP,
    ZZNET_CAPTURE_JPEG,       // 100% Quality
    ZZNET_CAPTURE_JPEG_70,    // 70% Quality
    ZZNET_CAPTURE_JPEG_50,
    ZZNET_CAPTURE_JPEG_30,
}ZZNET_CAPTURE_FORMATS;

// Device Type
typedef enum tagZZNET_DEVICE_TYPE 
{
    ZZNET_PRODUCT_NONE = 0,
    ZZNET_DVR_NONREALTIME_MACE,     // Non-Realtime MACE
    ZZNET_DVR_NONREALTIME,          // Non-Realtime
    ZZNET_NVS_MPEG1,                // NVS MPEG1
    ZZNET_DVR_MPEG1_2,              // MPEG1 2CH
    ZZNET_DVR_MPEG1_8,              // MPEG1 8CH
    ZZNET_DVR_MPEG4_8,              // MPEG4 8CH
    ZZNET_DVR_MPEG4_16,             // MPEG4 16CH
    ZZNET_DVR_MPEG4_SX2,            // LB Series
    ZZNET_DVR_MEPG4_ST2,            // GB Series
    ZZNET_DVR_MEPG4_SH2,            // HB Series               10
    ZZNET_DVR_MPEG4_GBE,            // GBE Series
    ZZNET_DVR_MPEG4_NVSII,          // NVS II
    ZZNET_DVR_STD_NEW,              // New Std
    ZZNET_DVR_DDNS,                 // DDNS Server
    ZZNET_DVR_ATM,                  // ATM
    ZZNET_NB_SERIAL,                // NB Series
    ZZNET_LN_SERIAL,                // LN Series
    ZZNET_BAV_SERIAL,               // BAV Series
    ZZNET_SDIP_SERIAL,              // SDIP Series
    ZZNET_IPC_SERIAL,               // IPC Series                20
    ZZNET_NVS_B,                    // NVS B
    ZZNET_NVS_C,                    // NVS H
    ZZNET_NVS_S,                    // NVS S
    ZZNET_NVS_E,                    // NVS E
    ZZNET_DVR_NEW_PROTOCOL,         // New Protocol
    ZZNET_NVD_SERIAL,               // Decoder
    ZZNET_DVR_N5,                   // N5
    ZZNET_DVR_MIX_DVR,              // Mix DVR
    ZZNET_SVR_SERIAL,               // SVR Series
    ZZNET_SVR_BS,                   // SVR-BS                     30
    ZZNET_NVR_SERIAL,               // NVR Series
    ZZNET_DVR_N51,                  // N51
    ZZNET_ITSE_SERIAL,              // ITSE
    ZZNET_ITC_SERIAL,               // ITC
    ZZNET_HWS_SERIAL,               // HWS
    ZZNET_PVR_SERIAL,               // PVR
    ZZNET_IVS_SERIAL,               // IVS
    ZZNET_IVS_B,                    // IVS B
    ZZNET_IVS_F,                    // IVS F
    ZZNET_IVS_V,                    // IVS V         40
    ZZNET_MATRIX_SERIAL,            // Matrix
    ZZNET_DVR_N52,                  // N52
    ZZNET_DVR_N56,                  // N56
    ZZNET_ESS_SERIAL,               // ESS
    ZZNET_IVS_PC,                   // IVS PC
    ZZNET_PC_NVR,                   // PC NVR
    ZZNET_DSCON,                    // Display Controller
    ZZNET_EVS,                      // EVS
    ZZNET_EIVS,                     // EIVS
    ZZNET_DVR_N6,                   // DVR-N6                     50
    ZZNET_UDS,                      // UDS
    ZZNET_AF6016,                   // AF6016
    ZZNET_AS5008,                   // AS5008
    ZZNET_AH2008,                   // AH2008
    ZZNET_A_SERIAL,                 // A Series
    ZZNET_BSC_SERIAL,               // BSC Series
    ZZNET_NVS_SERIAL,               // NVS Series
    ZZNET_VTO_SERIAL,               // VTO Series
    ZZNET_VTNC_SERIAL,              // VTNC Series
    ZZNET_TPC_SERIAL,               // TPC Series  60
    ZZNET_ASM_SERIAL,               // ASM Series
    ZZNET_VTS_SERIAL,               // VTS Series
    ZZNET_ARC2016C,                 // ARC2016C
    ZZNET_ASA,                      // ASA
	ZZNET_VTT_SERIAL,				  // VTT Series
	ZZNET_VTA_SERIAL,				  // VTA Series
	ZZNET_VTNS_SERIAL,			  // VTNS Series
	ZZNET_VTH_SERIAL,				  // VTH Series
	ZZNET_IVSS,					  // IVSS
}ZZNET_DEVICE_TYPE ;

// Language Type
typedef enum __ZZ_LANGUAGE_TYPE
{
    ZZ_LANGUAGE_ENGLISH,                // English    
    ZZ_LANGUAGE_CHINESE_SIMPLIFIED,     // Simplified Chinese    
    ZZ_LANGUAGE_CHINESE_TRADITIONAL,    // Traditional Chinese    
    ZZ_LANGUAGE_ITALIAN,                // Italian    
    ZZ_LANGUAGE_SPANISH,                // Spanish
    ZZ_LANGUAGE_JAPANESE,               // Japanese    
    ZZ_LANGUAGE_RUSSIAN,                // Russian        
    ZZ_LANGUAGE_FRENCH,                 // French        
    ZZ_LANGUAGE_GERMAN,                 // German        
    ZZ_LANGUAGE_PORTUGUESE,             // Portuguese    
    ZZ_LANGUAGE_TURKEY,                 // Turkish    
    ZZ_LANGUAGE_POLISH,                 // Polish    
    ZZ_LANGUAGE_ROMANIAN,               // Romanian    
    ZZ_LANGUAGE_HUNGARIAN,              // Hungarian    
    ZZ_LANGUAGE_FINNISH,                // Finnish    
    ZZ_LANGUAGE_ESTONIAN,               // Estonian    
    ZZ_LANGUAGE_KOREAN,                 // Korean    
    ZZ_LANGUAGE_FARSI,                  // Farsi     
    ZZ_LANGUAGE_DANSK,                  // Danish
    ZZ_LANGUAGE_CZECHISH,               // Czech
    ZZ_LANGUAGE_BULGARIA,               // Bulgarian
    ZZ_LANGUAGE_SLOVAKIAN,              // Slovakian
    ZZ_LANGUAGE_SLOVENIA,               // Slovenian
    ZZ_LANGUAGE_CROATIAN,               // Croatian
    ZZ_LANGUAGE_DUTCH,                  // Dutch
    ZZ_LANGUAGE_GREEK,                  // Greek
    ZZ_LANGUAGE_UKRAINIAN,              // Ukrainian
    ZZ_LANGUAGE_SWEDISH,                // Swedish
    ZZ_LANGUAGE_SERBIAN,                // Serbian
    ZZ_LANGUAGE_VIETNAMESE,             // Vietnamese
    ZZ_LANGUAGE_LITHUANIAN,             // Lithuanian
    ZZ_LANGUAGE_FILIPINO,               // Filipino
    ZZ_LANGUAGE_ARABIC,                 // Arabic
    ZZ_LANGUAGE_CATALAN,                // Catalan
    ZZ_LANGUAGE_LATVIAN,                // Latvian
    ZZ_LANGUAGE_THAI,                   // Thai
    ZZ_LANGUAGE_HEBREW,                 // Hebrew
    ZZ_LANGUAGE_Bosnian,                // Bosnian
} ZZ_LANGUAGE_TYPE;

// Upgrade Type
typedef enum __EM_ZZ_UPGRADE_TYPE
{
    ZZ_UPGRADE_BIOS_TYPE = 1,           // BIOS
    ZZ_UPGRADE_WEB_TYPE,                // WEB
    ZZ_UPGRADE_BOOT_YPE,                // BOOT
    ZZ_UPGRADE_CHARACTER_TYPE,          // Character
    ZZ_UPGRADE_LOGO_TYPE,               // LOGO
    ZZ_UPGRADE_EXE_TYPE,                // EXE
    ZZ_UPGRADE_DEVCONSTINFO_TYPE,       // Dev Const Info
    ZZ_UPGRADE_PERIPHERAL_TYPE,         // Peripheral
    ZZ_UPGRADE_GEOINFO_TYPE,            // Geo Info
    ZZ_UPGRADE_MENU,                    // Menu
    ZZ_UPGRADE_ROUTE,                   // Route
    ZZ_UPGRADE_ROUTE_STATE_AUTO,        // Route State Auto
    ZZ_UPGRADE_SCREEN,                  // Screen
} EM_ZZ_UPGRADE_TYPE;

// Record Type
typedef enum __ZZ_REC_TYPE
{
    ZZ_REC_TYPE_TIM = 0,
    ZZ_REC_TYPE_MTD,
    ZZ_REC_TYPE_ALM,
    ZZ_REC_TYPE_NUM,
} ZZ_REC_TYPE;

// Network Type 
typedef enum __ZZ_GPRSCDMA_NETWORK_TYPE
{
    ZZ_TYPE_AUTOSEL = 0,                        // Auto
    ZZ_TYPE_TD_SCDMA,                           // TD-SCDMA 
    ZZ_TYPE_WCDMA,                              // WCDMA
    ZZ_TYPE_CDMA_1x,                            // CDMA 1.x
    ZZ_TYPE_EDGE,                               // GPRS
    ZZ_TYPE_EVDO,                               // EVDO
    ZZ_TYPE_WIFI,                               // WIFI
} EM_ZZ_GPRSCDMA_NETWORK_TYPE;

// Interface Type
typedef enum __EM_ZZ_INTERFACE_TYPE
{
    ZZ_INTERFACE_OTHER = 0x00000000,            // Other
    ZZ_INTERFACE_REALPLAY,                      // Realplay
    ZZ_INTERFACE_PREVIEW,                       // Preview
    ZZ_INTERFACE_PLAYBACK,                      // Playback
    ZZ_INTERFACE_DOWNLOAD,                      // Download
    ZZ_INTERFACE_REALLOADPIC,                   // Real Load Pic
} EM_ZZ_INTERFACE_TYPE;

// Disconnect Event Type
typedef enum _EM_ZZ_REALPLAY_DISCONNECT_EVENT_TYPE
{
    ZZ_DISCONNECT_EVENT_REAVE,                     // Reave
    ZZ_DISCONNECT_EVENT_NETFORBID,                 // Forbid
    ZZ_DISCONNECT_EVENT_SUBCONNECT,                // Subconnect
}EM_ZZ_REALPLAY_DISCONNECT_EVENT_TYPE;

// IPC Type
typedef enum __EM_ZZ_IPC_TYPE
{
    ZZ_IPC_PRIVATE,                                 // Private
    ZZ_IPC_AEBELL,                                  // AEBELL
    ZZ_IPC_PANASONIC,                               // PANASONIC
    ZZ_IPC_SONY,                                    // SONY
    ZZ_IPC_DYNACOLOR,                               // DYNACOLOR
    ZZ_IPC_TCWS = 5,                                // TCWS
    ZZ_IPC_SAMSUNG,                                 // SAMSUNG
    ZZ_IPC_YOKO,                                    // YOKO
    ZZ_IPC_AXIS,                                    // AXIS
    ZZ_IPC_SANYO,                                   // SANYO       
    ZZ_IPC_BOSH = 10,                               // BOSH
    ZZ_IPC_PECLO,                                   // PECLO
    ZZ_IPC_PROVIDEO,                                // PROVIDEO
    ZZ_IPC_ACTI,                                    // ACTI
    ZZ_IPC_VIVOTEK,                                 // VIVOTEK
    ZZ_IPC_ARECONT = 15,                            // ARECONT
    ZZ_IPC_PRIVATEEH,                               // PRIVATEEH    
    ZZ_IPC_IMATEK,                                  // IMATEK
    ZZ_IPC_SHANY,                                   // SHANY
    ZZ_IPC_VIDEOTREC,                               // VIDEOTREC
    ZZ_IPC_URA = 20,                                // URA
    ZZ_IPC_BITICINO,                                // BITICINO 
    ZZ_IPC_ONVIF,                                   // ONVIF
    ZZ_IPC_SHEPHERD,                                // SHEPHERD
    ZZ_IPC_YAAN,                                    // YAAN
    ZZ_IPC_AIRPOINT = 25,                           // AIRPOINT
    ZZ_IPC_TYCO,                                    // TYCO
    ZZ_IPC_XUNMEI,                                  // XUNMEI
    ZZ_IPC_HIKVISION,                               // HIKVISION
    ZZ_IPC_LG,                                      // LG
    ZZ_IPC_AOQIMAN = 30,                            // AOQIMAN
    ZZ_IPC_BAOKANG,                                 // BAOKANG    
    ZZ_IPC_WATCHNET,                                // WATCHNET
    ZZ_IPC_XVISION,                                 // XVISION
    ZZ_IPC_FUSITSU,                                 // FUSITSU
    ZZ_IPC_CANON = 35,                              // CANON
    ZZ_IPC_GE,                                      // GE
    ZZ_IPC_Basler,                                  // BASLER
    ZZ_IPC_Patro,                                   // PATRO
    ZZ_IPC_CPKNC,                                   // CPKNC
    ZZ_IPC_CPRNC = 40,                              // CPRNC
    ZZ_IPC_CPUNC,                                   // CPUNC
    ZZ_IPC_CPPLUS,                                  // CPPLUS
    ZZ_IPC_XunmeiS,                                 // XUNMEIS
    ZZ_IPC_GDDW,                                    // GDDW
    ZZ_IPC_PSIA = 45,                               // PSIA
    ZZ_IPC_GB2818,                                  // GB2818    
    ZZ_IPC_GDYX,                                    // GDYX
    ZZ_IPC_OTHER,                                   // OTHER
    ZZ_IPC_CPUNR,                                   // CPUNR
    ZZ_IPC_CPUAR = 50,                              // CPUAR
    ZZ_IPC_AIRLIVE,                                 // AIRLIVE    
    ZZ_IPC_NPE,                                     // NPE    
    ZZ_IPC_AXVIEW,                                  // AXVIEW
    ZZ_IPC_DFWL,                                    // DFWL
    ZZ_IPC_HYUNDAI = 56,                            // HYUNDAI
    ZZ_IPC_APHD,                                    // APHD
    ZZ_IPC_WELLTRANS ,                              // WELLTRANS
    ZZ_IPC_CDJF,                                    // CDJF
    ZZ_IPC_JVC = 60,                                // JVC
    ZZ_IPC_INFINOVA,                                // INFINOVA
    ZZ_IPC_ADT,                                     // ADT
    ZZ_IPC_SIVIDI,                                  // SIVIDI
    ZZ_IPC_CPUNP,                                   // CPUNP
    ZZ_IPC_HX = 65,                                 // HX
    ZZ_IPC_TJGS,                                    // TJGS
    ZZ_IPC_MULTICAST = 79,                          // MULTICAST
    ZZ_IPC_RVI = 84,                                // RVI
}EM_ZZ_IPC_TYPE;

// H264 Profile Rank
typedef enum __EM_ZZ_H264_PROFILE_RANK
{
    ZZ_PROFILE_BASELINE = 1,                       // Baseline
    ZZ_PROFILE_MAIN,                               // Main
    ZZ_PROFILE_EXTENDED,                           // Extended
    ZZ_PROFILE_HIGH,                               // High
}EM_ZZ_H264_PROFILE_RANK;

typedef enum __EM_ZZ_DISK_TYPE
{
    ZZ_DISK_READ_WRITE,                         // Read Write
    ZZ_DISK_READ_ONLY,                          // Read Only
    ZZ_DISK_BACKUP,                             // Backup
    ZZ_DISK_REDUNDANT,                          // Redundant
    ZZ_DISK_SNAPSHOT,                           // Snapshot
}EM_ZZ_DISK_TYPE;

// Encrypt Mode
typedef enum  __EM_ZZ_ENCRYPT_ALOG_WORKMODE
{
    ZZ_ENCRYPT_ALOG_WORKMODE_ECB,                  // ECB
    ZZ_ENCRYPT_ALOG_WORKMODE_CBC,                  // CBC
    ZZ_ENCRYPT_ALOG_WORKMODE_CFB,                  // CFB
    ZZ_ENCRYPT_ALOG_WORKMODE_OFB,                  // OFB
}EM_ZZ_ENCRYPT_ALOG_WORKMODE;

typedef enum __EM_ZZ_MOBILE_PPP_STATE
{
    ZZ_MOBILE_PPP_UP = 0,                          // UP
    ZZ_MOBILE_PPP_DOWN,                            // DOWN        
    ZZ_MOBILE_PPP_CONNECTING,                      // CONNECTING        
    ZZ_MOBILE_PPP_CLOSEING,                        // CLOSEING
} EM_ZZ_MOBILE_PPP_STATE;

typedef enum __EM_ZZ_3GMOBILE_STATE
{
    ZZ_MOBILE_MODULE_OFF,                          // OFF           
    ZZ_MOBILE_MODULE_STARTING,                     // STARTING    
    ZZ_MOBILE_MODULE_WORKING,                      // WORKING
}EM_ZZ_3GMOBILE_STATE;

typedef enum tagEM_ZZ_LOGIN_SPAC_CAP_TYPE
{
    EM_ZZ_LOGIN_SPEC_CAP_TCP               = 0,    // TCP
    EM_ZZ_LOGIN_SPEC_CAP_ANY               = 1,    // Any
    EM_ZZ_LOGIN_SPEC_CAP_SERVER_CONN       = 2,    // Server Conn
    EM_ZZ_LOGIN_SPEC_CAP_MULTICAST         = 3,    // Multicast
    EM_ZZ_LOGIN_SPEC_CAP_UDP               = 4,    // UDP
    EM_ZZ_LOGIN_SPEC_CAP_MAIN_CONN_ONLY    = 6,    // Main Conn Only
    EM_ZZ_LOGIN_SPEC_CAP_SSL               = 7,    // SSL

    EM_ZZ_LOGIN_SPEC_CAP_INTELLIGENT_BOX   = 9,    // Intelligent Box
    EM_ZZ_LOGIN_SPEC_CAP_NO_CONFIG         = 10,   // No Config
    EM_ZZ_LOGIN_SPEC_CAP_U_LOGIN           = 11,   // U Login
    EM_ZZ_LOGIN_SPEC_CAP_LDAP              = 12,   // LDAP
    EM_ZZ_LOGIN_SPEC_CAP_AD                = 13,   // AD
    EM_ZZ_LOGIN_SPEC_CAP_RADIUS            = 14,   // Radius 
    EM_ZZ_LOGIN_SPEC_CAP_SOCKET_5          = 15,   // Socket 5
    EM_ZZ_LOGIN_SPEC_CAP_CLOUD             = 16,   // Cloud
    EM_ZZ_LOGIN_SPEC_CAP_AUTH_TWICE        = 17,   // Auth Twice
    EM_ZZ_LOGIN_SPEC_CAP_TS                = 18,   // TS
    EM_ZZ_LOGIN_SPEC_CAP_P2P               = 19,   // P2P
    EM_ZZ_LOGIN_SPEC_CAP_MOBILE            = 20,   // Mobile
    EM_ZZ_LOGIN_SPEC_CAP_INVALID                   // Invalid
}EM_ZZ_LOGIN_SPAC_CAP_TYPE;




// Split Mode
typedef enum tagZZ_SPLIT_MODE
{
    ZZ_SPLIT_1 = 1,                                 // 1-Window
    ZZ_SPLIT_2 = 2,                                 // 2-Window
    ZZ_SPLIT_4 = 4,                                 // 4-Window
    ZZ_SPLIT_6 = 6,                                 // 6-Window
    ZZ_SPLIT_8 = 8,                                 // 8-Window
    ZZ_SPLIT_9 = 9,                                 // 9-Window
    ZZ_SPLIT_12 = 12,                               // 12-Window
    ZZ_SPLIT_16 = 16,                               // 16-Window
    ZZ_SPLIT_20 = 20,                               // 20-Window
    ZZ_SPLIT_25 = 25,                               // 25-Window
    ZZ_SPLIT_36 = 36,                               // 36-Window
    ZZ_SPLIT_64 = 64,                               // 64-Window
    ZZ_SPLIT_144 = 144,                             // 144-Window
    ZZ_PIP_1 = ZZ_SPLIT_PIP_BASE + 1,               // PIP Mode, 1 full screen + 1 small window
    ZZ_PIP_3 = ZZ_SPLIT_PIP_BASE + 3,               // PIP Mode, 1 full screen + 3 small windows
    ZZ_SPLIT_FREE = ZZ_SPLIT_PIP_BASE * 2,          // Free window mode, can freely create/close windows, set position and Z-order
    ZZ_COMPOSITE_SPLIT_1 = ZZ_SPLIT_PIP_BASE * 3 + 1,    // Composite screen member 1 split
    ZZ_COMPOSITE_SPLIT_4 = ZZ_SPLIT_PIP_BASE * 3 + 4,    // Composite screen member 4 split
	ZZ_SPLIT_3  = 10,                                // 3-Window
	ZZ_SPLIT_3B = 11,								 // 3-Window Inverted (Inverted 'Pin' layout)
} ZZ_SPLIT_MODE;


///////////////////////////////Alarm Related Definitions///////////////////////////////
// General Alarm Information
typedef struct
{
    int                  channelcount;
    int                  alarminputcount;
    unsigned char        alarm[16];                // External Alarm
    unsigned char        motiondection[16];        // Motion Detection
    unsigned char        videolost[16];            // Video Loss
} ZZNET_CLIENT_STATE;


typedef enum _ZZ_SNAP_TYPE
{
    ZZ_SNAP_TYP_TIMING = 0,
    ZZ_SNAP_TYP_ALARM,
    ZZ_SNAP_TYP_NUM,
} ZZ_SNAP_TYPE;

// Three-state Boolean Type
typedef enum tagZZNET_THREE_STATUS_BOOL
{
    ZZ_BOOL_STATUS_FALSE  = 0 , 
    ZZ_BOOL_STATUS_TRUE       ,
    ZZ_BOOL_STATUS_UNKNOWN    ,  // Unknown
}ZZNET_THREE_STATUS_BOOL;


// Snapshot Parameter Structure
typedef struct _zzsnap_param
{
    unsigned int     Channel;                       // Channel for snapshot
    unsigned int     Quality;                       // Image quality; 1~6
    unsigned int     ImageSize;                     // Image size; 0:QCIF, 1:CIF, 2:D1
    unsigned int     mode;                          // Snapshot mode; -1: Stop, 0: Request one frame, 1: Timing request, 2: Continuous request
    unsigned int     InterSnap;                     // Time unit: second; Used when mode=1 (timing request)
													// Only some special devices (e.g., mobile devices) support configuring timing interval via this field.
													// It is recommended to use CFG_CMD_ENCODE to configure stuSnapFormat[nSnapMode].stuVideoFormat.nFrameRate field.
    unsigned int     CmdSerial;                     // Request serial number, valid range 0~65535, truncated to unsigned short if exceeded
    unsigned int     Reserved[4];
} ZZSNAP_PARAMS, *LPZZSNAP_PARAMS;

// Restore Factory Settings Input
typedef struct tagZZNET_IN_RESET_SYSTEM
{
    DWORD dwSize;
}ZZNET_IN_RESET_SYSTEM;

// Restore Factory Settings Output
typedef struct tagZZNET_OUT_RESET_SYSTEM
{
    DWORD dwSize;
}ZZNET_OUT_RESET_SYSTEM;

// Command types supported by ZZNETSDK_ListenServer callback fServiceCallBack
enum { 
    ZZ_DVR_DISCONNECT=-1,                           // Callback when device disconnects during verification
    ZZ_DVR_SERIAL_RETURN=1,                         // Device registration carries serial number, corresponds to char* szDevSerial
    ZZNET_DEV_AUTOREGISTER_RETURN,                    // Device registration carries serial number and token, corresponds to ZZNET_CB_AUTOREGISTER
    ZZNET_DEV_NOTIFY_IP_RETURN,                       // Device only reports IP, not for active registration. User gets IP and logs in via agreed port (non-active registration type)
};
typedef struct tagZZNET_CB_AUTOREGISTER
{
    DWORD           dwSize;                          // Structure size
    char            szDevSerial[ZZ_DEV_SERIALNO_LEN];// Serial Number
    char            szToken[MAX_PATH];               // Token
}ZZNET_CB_AUTOREGISTER;

// IP Modification Configuration
typedef struct __ZZCTRL_IPMODIFY_PARAM
{
    int             nStructSize;
    char            szRemoteIP[ZZ_MAX_IPADDR_OR_DOMAIN_LEN];        // Device IP
    char            szSubmask[ZZ_MAX_IPADDR_LEN];                   // Subnet Mask
    char            szGateway[ZZ_MAX_IPADDR_OR_DOMAIN_LEN];         // Gateway
    char            szMac[ZZ_MACADDR_LEN];                          // MAC Address
    char            szDeviceType[ZZ_DEV_TYPE_LEN];                  // Device Type
}ZZCTRL_IPMODIFY_PARAM;


typedef struct tagZZCTRL_CONNECT_WIFI_BYWPS_IN
{
    DWORD               dwSize;
    int                 nType;                              // WPS connection type, 0: Virtual button; 1: (Device side) PIN code; 2: (WiFi Hotspot side) PIN code
    char                szSSID[ZZ_MAX_SSID_LEN];            // SSID, valid when nType is 1 or 2, max 32 bytes
    char                szApPin[ZZ_MAX_APPIN_LEN];          // AP PIN code, valid when nType is 2, PIN is 8 digits, obtained from WiFi hotspot
    char                szWLanPin[ZZ_MAX_APPIN_LEN];        // Device PIN code, valid when nType is 1: Generated by device if empty; User-set if not empty, max 8 digits, need to add this PIN to WiFi hotspot
}ZZCTRL_CONNECT_WIFI_BYWPS_IN;

typedef struct tagZZCTRL_CONNECT_WIFI_BYWPS_OUT
{
    DWORD               dwSize;
    char                szRetWLanPin[ZZ_MAX_APPIN_LEN];// Returned Device PIN code, valid output when WPS connection type is (Device side) PIN code
}ZZCTRL_CONNECT_WIFI_BYWPS_OUT;

// ZZNETSDK_ControlDevice Interface ZZ_CTRL_WIFI_BY_WPS Command Parameters (WPS Quick Config WIFI)
typedef struct tagZZCTRL_CONNECT_WIFI_BYWPS
{
    DWORD                dwSize;
    ZZCTRL_CONNECT_WIFI_BYWPS_IN     stuWpsInfo;            // Connection parameters (Filled by user)
    ZZCTRL_CONNECT_WIFI_BYWPS_OUT    stuWpsResult;          // Return data (Returned by device)
} ZZCTRL_CONNECT_WIFI_BYWPS;


// "Restore Default Config" Mask, supports AND/OR operations, Interface ZZNETSDK_ControlDevice type ZZ_CTRL_RESTOREDEFAULT
#define ZZ_RESTORE_COMMON                 0x00000001       // Common Settings
#define ZZ_RESTORE_CODING                 0x00000002       // Encoding Settings
#define ZZ_RESTORE_VIDEO                  0x00000004       // Record Settings
#define ZZ_RESTORE_COMM                   0x00000008       // Serial Port Settings
#define ZZ_RESTORE_NETWORK                0x00000010       // Network Settings
#define ZZ_RESTORE_ALARM                  0x00000020       // Alarm Settings
#define ZZ_RESTORE_VIDEODETECT            0x00000040       // Video Detection
#define ZZ_RESTORE_PTZ                    0x00000080       // PTZ Control
#define ZZ_RESTORE_OUTPUTMODE             0x00000100       // Output Mode
#define ZZ_RESTORE_CHANNELNAME            0x00000200       // Channel Name
#define ZZ_RESTORE_VIDEOINOPTIONS         0x00000400       // Camera Properties
#define ZZ_RESTORE_CPS                    0x00000800       // Intelligent Traffic
#define ZZ_RESTORE_INTELLIGENT            0x00001000       // Video Analysis
#define ZZ_RESTORE_REMOTEDEVICE           0x00002000       // Remote Device Config
#define ZZ_RESTORE_DECODERVIDEOOUT        0x00004000       // Decoder Tour
#define ZZ_RESTORE_LINKMODE               0x00008000       // Connection Mode
#define ZZ_RESTORE_COMPOSITE              0x00010000       // Composite Screen    
#define ZZ_RESTORE_ALL                    0x80000000       // Reset All

// Control Type, corresponds to ZZNETSDK_ControlDevice Interface
typedef enum _ZZCtrlType
{
    ZZ_CTRL_REBOOT = 0,                            // Reboot Device    
    ZZ_CTRL_SHUTDOWN,                              // Shutdown Device
    ZZ_CTRL_DISK,                                  // Disk Management
    ZZ_KEYBOARD_POWER = 3,                         // Network Keyboard
    ZZ_KEYBOARD_ENTER,
    ZZ_KEYBOARD_ESC,
    ZZ_KEYBOARD_UP,
    ZZ_KEYBOARD_DOWN,
    ZZ_KEYBOARD_LEFT,
    ZZ_KEYBOARD_RIGHT,
    ZZ_KEYBOARD_BTN0,
    ZZ_KEYBOARD_BTN1,
    ZZ_KEYBOARD_BTN2,
    ZZ_KEYBOARD_BTN3,
    ZZ_KEYBOARD_BTN4,
    ZZ_KEYBOARD_BTN5,
    ZZ_KEYBOARD_BTN6,
    ZZ_KEYBOARD_BTN7,
    ZZ_KEYBOARD_BTN8,
    ZZ_KEYBOARD_BTN9,
    ZZ_KEYBOARD_BTN10,
    ZZ_KEYBOARD_BTN11,
    ZZ_KEYBOARD_BTN12,
    ZZ_KEYBOARD_BTN13,
    ZZ_KEYBOARD_BTN14,
    ZZ_KEYBOARD_BTN15,
    ZZ_KEYBOARD_BTN16,
    ZZ_KEYBOARD_SPLIT,
    ZZ_KEYBOARD_ONE,
    ZZ_KEYBOARD_NINE,
    ZZ_KEYBOARD_ADDR,
    ZZ_KEYBOARD_INFO,
    ZZ_KEYBOARD_REC,
    ZZ_KEYBOARD_FN1,
    ZZ_KEYBOARD_FN2,
    ZZ_KEYBOARD_PLAY,
    ZZ_KEYBOARD_STOP,
    ZZ_KEYBOARD_SLOW,
    ZZ_KEYBOARD_FAST,
    ZZ_KEYBOARD_PREW,
    ZZ_KEYBOARD_NEXT,
    ZZ_KEYBOARD_JMPDOWN,
    ZZ_KEYBOARD_JMPUP,
    ZZ_KEYBOARD_10PLUS,
    ZZ_KEYBOARD_SHIFT,
    ZZ_KEYBOARD_BACK,               
    ZZ_KEYBOARD_LOGIN ,                            // New Network Keyboard Function
    ZZ_KEYBOARD_CHNNEL ,                           // Switch Video Channel
    ZZ_TRIGGER_ALARM_IN = 100,                     // Trigger Alarm Input
    ZZ_TRIGGER_ALARM_OUT,                          // Trigger Alarm Output
    ZZ_CTRL_MATRIX,                                // Matrix Control
    ZZ_CTRL_SDCARD,                                // SD Card Control (IPC Product), params same as Disk Control
    ZZ_BURNING_START,                              // Burner Control, Start Burning
    ZZ_BURNING_STOP,                               // Burner Control, Stop Burning
    ZZ_BURNING_ADDPWD,                             // Burner Control, Overlay Password (string ending with '\0', max 8 bytes)
    ZZ_BURNING_ADDHEAD,                            // Burner Control, Overlay Header (string ending with '\0', max 1024 bytes, supports new line '\n')
    ZZ_BURNING_ADDSIGN,                            // Burner Control, Overlay Dot to burning info (no param)
    ZZ_BURNING_ADDCURSTOMINFO,                     // Burner Control, Custom Overlay (string ending with '\0', max 1024 bytes, supports new line '\n')
    ZZ_CTRL_RESTOREDEFAULT,                        // Restore Device Default Settings
    ZZ_CTRL_CAPTURE_START,                         // Trigger Device Snapshot
    ZZ_CTRL_CLEARLOG,                              // Clear Logs
    ZZ_TRIGGER_ALARM_WIRELESS = 200,               // Trigger Wireless Alarm (IPC Product)
    ZZ_MARK_IMPORTANT_RECORD,                      // Mark Important Record File
    ZZ_CTRL_DISK_SUBAREA,                          // Network Disk Partitioning    
    ZZ_BURNING_ATTACH,                             // Burner Control, Append Burning
    ZZ_BURNING_PAUSE,                              // Pause Burning
    ZZ_BURNING_CONTINUE,                           // Continue Burning
    ZZ_BURNING_POSTPONE,                           // Postpone Burning
    ZZ_CTRL_OEMCTRL,                               // Stop Service Control
    ZZ_BACKUP_START,                               // Device Backup Start
    ZZ_BACKUP_STOP,                                // Device Backup Stop
    ZZ_VIHICLE_WIFI_ADD,                           // Vehicle: Manually Add WiFi Config
    ZZ_VIHICLE_WIFI_DEC,                           // Vehicle: Manually Delete WiFi Config
    ZZ_BUZZER_START,                               // Start Buzzer
    ZZ_BUZZER_STOP,                                // Stop Buzzer
    ZZ_REJECT_USER,                                // Kick User
    ZZ_SHIELD_USER,                                // Block User
    ZZ_RAINBRUSH,                                  // Intelligent Traffic, Wiper Control
    ZZ_MANUAL_SNAP,                                // Intelligent Traffic, Manual Snapshot (Struct MANUAL_SNAP_PARAMETER)
    ZZ_MANUAL_NTP_TIMEADJUST,                      // Manual NTP Time Sync
    ZZ_NAVIGATION_SMS,                             // Navigation Info and SMS
    ZZ_CTRL_ROUTE_CROSSING,                        // Route Point Information
    ZZ_BACKUP_FORMAT,                              // Format Backup Device
    ZZ_DEVICE_LOCALPREVIEW_SLIPT,                  // Control Device Local Preview Split (Struct DEVICE_LOCALPREVIEW_SLIPT_PARAMETER)    
    ZZ_CTRL_INIT_RAID,                             // RAID Initialization
    ZZ_CTRL_RAID,                                  // RAID Operation
    ZZ_CTRL_SAPREDISK,                             // Hot Spare Disk Operation
    ZZ_WIFI_CONNECT,                               // Manually Initiate WiFi Connection (Struct WIFI_CONNECT)
    ZZ_WIFI_DISCONNECT,                            // Manually Disconnect WiFi (Struct WIFI_CONNECT)
    ZZ_CTRL_ARMED,                                 // Arm/Disarm Operation
    ZZ_CTRL_IP_MODIFY,                             // Modify Frontend IP (Struct ZZCTRL_IPMODIFY_PARAM)                     
    ZZ_CTRL_WIFI_BY_WPS,                           // WPS Connect WiFi (Struct ZZCTRL_CONNECT_WIFI_BYWPS)
    ZZ_CTRL_FORMAT_PATITION,                       // Format Partition (Struct ZZ_FORMAT_PATITION)
    ZZ_CTRL_EJECT_STORAGE,                         // Manually Eject Device (Struct ZZ_EJECT_STORAGE_DEVICE)
    ZZ_CTRL_LOAD_STORAGE,                          // Manually Load Device (Struct ZZ_LOAD_STORAGE_DEVICE)
    ZZ_CTRL_CLOSE_BURNER,                          // Close Burner Door (Struct NET_CTRL_BURNERDOOR) Usually need to wait 6 seconds
    ZZ_CTRL_EJECT_BURNER,                          // Eject Burner Door (Struct NET_CTRL_BURNERDOOR) Usually need to wait 4 seconds
    ZZ_CTRL_CLEAR_ALARM,                           // Clear Alarm (Struct NET_CTRL_CLEAR_ALARM)
    ZZ_CTRL_MONITORWALL_TVINFO,                    // Video Wall Info Display (Struct NET_CTRL_MONITORWALL_TVINFO)
    ZZ_CTRL_START_VIDEO_ANALYSE,                   // Start Video Intelligent Analysis (Struct NET_CTRL_START_VIDEO_ANALYSE)
    ZZ_CTRL_STOP_VIDEO_ANALYSE,                    // Stop Video Intelligent Analysis (Struct NET_CTRL_STOP_VIDEO_ANALYSE)
    ZZ_CTRL_UPGRADE_DEVICE,                        // Control Device Upgrade Start, device completes upgrade independently, no file transfer needed
    ZZ_CTRL_MULTIPLAYBACK_CHANNALES,               // Switch Channels for Multi-channel Preview/Playback (Struct NET_CTRL_MULTIPLAYBACK_CHANNALES)
    ZZ_CTRL_SEQPOWER_OPEN,                         // Power Sequencer: Open Switching Output (NET_CTRL_SEQPOWER_PARAM)
    ZZ_CTRL_SEQPOWER_CLOSE,                        // Power Sequencer: Close Switching Output (NET_CTRL_SEQPOWER_PARAM)
    ZZ_CTRL_SEQPOWER_OPEN_ALL,                     // Power Sequencer: Open All Switching Outputs (NET_CTRL_SEQPOWER_PARAM)
    ZZ_CTRL_SEQPOWER_CLOSE_ALL,                    // Power Sequencer: Close All Switching Outputs (NET_CTRL_SEQPOWER_PARAM)
    ZZ_CTRL_PROJECTOR_RISE,                        // Projector Rise (NET_CTRL_PROJECTOR_PARAM)
    ZZ_CTRL_PROJECTOR_FALL,                        // Projector Fall (NET_CTRL_PROJECTOR_PARAM)
    ZZ_CTRL_PROJECTOR_STOP,                        // Projector Stop (NET_CTRL_PROJECTOR_PARAM)
    ZZ_CTRL_INFRARED_KEY,                          // Infrared Key (NET_CTRL_INFRARED_KEY_PARAM)
    ZZ_CTRL_START_PLAYAUDIO,                       // Device Start Playing Audio File (Struct NET_CTRL_START_PLAYAUDIO)
    ZZ_CTRL_STOP_PLAYAUDIO,                        // Device Stop Playing Audio File
    ZZ_CTRL_START_ALARMBELL,                       // Turn On Alarm Bell (Struct NET_CTRL_ALARMBELL)
    ZZ_CTRL_STOP_ALARMBELL,                        // Turn Off Alarm Bell (Struct NET_CTRL_ALARMBELL)
    ZZ_CTRL_ACCESS_OPEN,                           // Access Control - Open Door (Struct NET_CTRL_ACCESS_OPEN)
    ZZ_CTRL_SET_BYPASS,                            // Set Bypass Function (Struct NET_CTRL_SET_BYPASS)
    ZZ_CTRL_RECORDSET_INSERT,                      // Add Record, Get Record Set ID (NET_CTRL_RECORDSET_INSERT_PARAM)
    ZZ_CTRL_RECORDSET_UPDATE,                      // Update Record by Set ID (NET_CTRL_RECORDSET_PARAM)
    ZZ_CTRL_RECORDSET_REMOVE,                      // Delete Record by Set ID (NET_CTRL_RECORDSET_PARAM)
    ZZ_CTRL_RECORDSET_CLEAR,                       // Clear All Record Set Info (NET_CTRL_RECORDSET_PARAM)
    ZZ_CTRL_ACCESS_CLOSE,                          // Access Control - Close Door (Struct NET_CTRL_ACCESS_CLOSE)
    ZZ_CTRL_ALARM_SUBSYSTEM_ACTIVE_SET,            // Alarm Subsystem Activation Setting (Struct NET_CTRL_ALARM_SUBSYSTEM_SETACTIVE)
    ZZ_CTRL_FORBID_OPEN_STROBE,                    // Forbid Device Opening Gate (Struct NET_CTRL_FORBID_OPEN_STROBE)
    ZZ_CTRL_OPEN_STROBE,                           // Open Gate/Barrier (Struct NET_CTRL_OPEN_STROBE)
    ZZ_CTRL_TALKING_REFUSE,                        // Intercom Refuse Answer (Struct NET_CTRL_TALKING_REFUSE)
    ZZ_CTRL_ARMED_EX,                              // Arm/Disarm Operation (Struct CTRL_ARM_DISARM_PARAM_EX), Upgrade of CTRL_ARM_DISARM_PARAM, Recommended
    ZZ_CTRL_REMOTE_TALK,                           // Remote Talk Control (Struct NET_CTRL_REMOTETALK_PARAM)
    ZZ_CTRL_NET_KEYBOARD = 400,                    // Network Keyboard Control (Struct ZZCTRL_NET_KEYBOARD)
    ZZ_CTRL_AIRCONDITION_OPEN,                     // Turn On Air Conditioner (Struct NET_CTRL_OPEN_AIRCONDITION)
    ZZ_CTRL_AIRCONDITION_CLOSE,                    // Turn Off Air Conditioner (Struct NET_CTRL_CLOSE_AIRCONDITION)
    ZZ_CTRL_AIRCONDITION_SET_TEMPERATURE,          // Set AC Temperature (Struct NET_CTRL_SET_TEMPERATURE)
    ZZ_CTRL_AIRCONDITION_ADJUST_TEMPERATURE,       // Adjust AC Temperature (Struct NET_CTRL_ADJUST_TEMPERATURE)
    ZZ_CTRL_AIRCONDITION_SETMODE,                  // Set AC Working Mode (Struct NET_CTRL_ADJUST_TEMPERATURE)
    ZZ_CTRL_AIRCONDITION_SETWINDMODE,              // Set AC Wind Mode (Struct NET_CTRL_AIRCONDITION_SETMODE)
    ZZ_CTRL_RESTOREDEFAULT_EX ,                    // Restore Device Default Settings New Protocol (Struct NET_CTRL_RESTORE_DEFAULT)
                                                   // Prefer using this enum for restore. If fails and ZZNETSDK_GetLastError returns NET_UNSUPPORTED, try ZZ_CTRL_RESTOREDEFAULT
    ZZ_CTRL_NOTIFY_EVENT,                          // Send Event to Device (Struct NET_NOTIFY_EVENT_DATA)
    ZZ_CTRL_SILENT_ALARM_SET,                      // Silent Alarm Setting
    ZZ_CTRL_START_PLAYAUDIOEX,                     // Device Start Voice Broadcast (Struct NET_CTRL_START_PLAYAUDIOEX)
    ZZ_CTRL_STOP_PLAYAUDIOEX,                      // Device Stop Voice Broadcast
    ZZ_CTRL_CLOSE_STROBE,                          // Close Gate/Barrier (Struct NET_CTRL_CLOSE_STROBE)
    ZZ_CTRL_SET_ORDER_STATE,                       // Set Parking Reservation Status (Struct NET_CTRL_SET_ORDER_STATE)
    ZZ_CTRL_RECORDSET_INSERTEX,                    // Add Fingerprint Record, Get Record Set ID (NET_CTRL_RECORDSET_INSERT_PARAM)
    ZZ_CTRL_RECORDSET_UPDATEEX,                    // Update Fingerprint Record by Set ID (NET_CTRL_RECORDSET_PARAM)
    ZZ_CTRL_CAPTURE_FINGER_PRINT,                  // Fingerprint Collection (Struct NET_CTRL_CAPTURE_FINGER_PRINT)
    ZZ_CTRL_ECK_LED_SET,                           // Parking Entrance Controller LED Setting (Struct NET_CTRL_ECK_LED_SET_PARAM)
    ZZ_CTRL_ECK_IC_CARD_IMPORT,                    // Intelligent Parking Entrance IC Card Import (Struct NET_CTRL_ECK_IC_CARD_IMPORT_PARAM)
    ZZ_CTRL_ECK_SYNC_IC_CARD,                      // Intelligent Parking Entrance IC Card Sync, Device deletes original IC info upon receipt (Struct NET_CTRL_ECK_SYNC_IC_CARD_PARAM)
    ZZ_CTRL_LOWRATEWPAN_REMOVE,                    // Remove Specified Wireless Device (Struct NET_CTRL_LOWRATEWPAN_REMOVE)
    ZZ_CTRL_LOWRATEWPAN_MODIFY,                    // Modify Wireless Device Info (Struct NET_CTRL_LOWRATEWPAN_MODIFY)
	ZZ_CTRL_ECK_SET_PARK_INFO,                     // Intelligent Parking Entrance Set Parking Info (Struct NET_CTRL_ECK_SET_PARK_INFO_PARAM)
    ZZ_CTRL_VTP_DISCONNECT,                        // Hang up Video Phone (Struct NET_CTRL_VTP_DISCONNECT)
    ZZ_CTRL_UPDATE_FILES,                          // Remote Multimedia File Update (Struct NET_CTRL_UPDATE_FILES)
    ZZ_CTRL_MATRIX_SAVE_SWITCH,                    // Save Matrix Output Relationship (Struct NET_CTRL_MATRIX_SAVE_SWITCH)
    ZZ_CTRL_MATRIX_RESTORE_SWITCH,                 // Restore Matrix Output Relationship (Struct NET_CTRL_MATRIX_RESTORE_SWITCH)
    ZZ_CTRL_VTP_DIVERTACK,                         // Call Diversion Ack (Struct NET_CTRL_VTP_DIVERTACK)	
    ZZ_CTRL_RAINBRUSH_MOVEONCE,                    // Wiper Moves Once, Valid when Wiper Mode is Manual (Struct NET_CTRL_RAINBRUSH_MOVEONCE)
    ZZ_CTRL_RAINBRUSH_MOVECONTINUOUSLY,            // Wiper Moves Continuously, Valid when Wiper Mode is Manual (Struct NET_CTRL_RAINBRUSH_MOVECONTINUOUSLY)
    ZZ_CTRL_RAINBRUSH_STOPMOVE,                    // Wiper Stops, Valid when Wiper Mode is Manual (Struct NET_CTRL_RAINBRUSH_STOPMOVE)
    ZZ_CTRL_ALARM_ACK,                             // Alarm Event Acknowledgment (Struct NET_CTRL_ALARM_ACK)
                                                   // DO NOT call ZZ_CTRL_ALARM_ACK within the alarm callback interface
    ZZ_CTRL_RECORDSET_IMPORT,                      // Batch Import Record Set Info (NET_CTRL_RECORDSET_PARAM)
    ZZ_CTRL_DELIVERY_FILE,                         // Deliver Video/Image to Output, For Video Intercom, deliver at same time (NET_CTRL_DELIVERY_FILE)
	ZZ_CTRL_FORCE_BREAKING,                        // Force Generate Violation Type (NET_CTRL_FORCE_BREAKING)
	ZZ_CTRL_RESTORE_EXCEPT,						   // Restore Default Config Except Specified Ones.
	ZZ_CTRL_SET_PARK_INFO,						   // Set Parking Info, Platform sets to camera, used for dot matrix display (Struct NET_CTRL_SET_PARK_INFO)
	ZZ_CTRL_CLEAR_SECTION_STAT,					   // Clear People Counting Info in Current Section, restart from 0 (Struct NET_CTRL_CLEAR_SECTION_STAT_INFO)
    ZZ_CTRL_DELIVERY_FILE_BYCAR,                   // Deliver Video/Image to Output, For Vehicle, ads delivered at separate times (NET_CTRL_DELIVERY_FILE_BYCAR)
                                                   // The following commands are only valid for ZZNETSDK_ControlDeviceEx
    ZZ_CTRL_THERMO_GRAPHY_ENSHUTTER = 0x10000,     // Set Thermal Imaging Shutter Enable/Disable, pInBuf= NET_IN_THERMO_EN_SHUTTER*, pOutBuf= NET_OUT_THERMO_EN_SHUTTER * 
    ZZ_CTRL_RADIOMETRY_SETOSDMARK,                 // Set Temperature Measurement Item OSD Highlight, pInBuf= NET_IN_RADIOMETRY_SETOSDMARK*, pOutBuf= NET_OUT_RADIOMETRY_SETOSDMARK *    
    ZZ_CTRL_AUDIO_REC_START_NAME,                  // Start Audio Recording and Get Filename, pInBuf = NET_IN_AUDIO_REC_MNG_NAME *, pOutBuf = NET_OUT_AUDIO_REC_MNG_NAME *
    ZZ_CTRL_AUDIO_REC_STOP_NAME,                   // Stop Audio Recording and Return Filename, pInBuf = NET_IN_AUDIO_REC_MNG_NAME *, pOutBuf = NET_OUT_AUDIO_REC_MNG_NAME *
    ZZ_CTRL_SNAP_MNG_SNAP_SHOT,                    // Instant Snapshot (Manual Snapshot), pInBuf = NET_IN_SNAP_MNG_SHOT *, pOutBuf = NET_OUT_SNAP_MNG_SHOT *
    ZZ_CTRL_LOG_STOP,                              // Force Sync Cache Data to DB and Close DB, pInBuf = NET_IN_LOG_MNG_CTRL *, pOutBuf = NET_OUT_LOG_MNG_CTRL *
    ZZ_CTRL_LOG_RESUME,                            // Resume DB, pInBuf = NET_IN_LOG_MNG_CTRL *, pOutBuf = NET_OUT_LOG_MNG_CTRL *
    ZZ_CTRL_POS_ADD,                               // Add a POS Device, pInBuf = NET_IN_POS_ADD *, pOutBuf = NET_OUT_POS_ADD *
    ZZ_CTRL_POS_REMOVE,                            // Remove a POS Device, pInBuf = NET_IN_POS_REMOVE *, pOutBuf = NET_OUT_POS_REMOVE *
    ZZ_CTRL_POS_REMOVE_MULTI,                      // Batch Remove POS Devices, pInBuf = NET_IN_POS_REMOVE_MULTI *, pOutBuf = NET_OUT_POS_REMOVE_MULTI *
    ZZ_CTRL_POS_MODIFY,                            // Modify a POS Device, pInBuf = NET_IN_POS_ADD *, pOutBuf = NET_OUT_POS_ADD *
    ZZ_CTRL_SET_SOUND_ALARM,                       // Trigger Audible Alarm, pInBuf = NET_IN_SOUND_ALARM *, pOutBuf = NET_OUT_SOUND_ALARM *
	ZZ_CTRL_AUDIO_MATRIX_SILENCE,				   // Audio Matrix One-key Mute Control (pInBuf = NET_IN_AUDIO_MATRIX_SILENCE, pOutBuf =  NET_OUT_AUDIO_MATRIX_SILENCE)
    ZZ_CTRL_MANUAL_UPLOAD_PICTURE,                 // Set Manual Upload, pInBuf = NET_IN_MANUAL_UPLOAD_PICTURE *, pOutBUf = NET_OUT_MANUAL_UPLOAD_PICTURE *
    ZZ_CTRL_REBOOT_NET_DECODING_DEV,               // Reboot Network Decoding Device, pInBuf = NET_IN_REBOOT_NET_DECODING_DEV *, pOutBuf = NET_OUT_REBOOT_NET_DECODING_DEV *
	ZZ_CTRL_SET_IC_SENDER,						   // ParkingControl Set Card Sender Device, pInBuf = NET_IN_SET_IC_SENDER *, pOutBuf = NET_OUT_SET_IC_SENDER * 
    ZZ_CTRL_SET_MEDIAKIND,                         // Set Monitoring Stream Composition, e.g., Audio only, Video only, Audio/Video pInBuf = NET_IN_SET_MEDIAKIND *, pOutBuf = NET_OUT_SET_MEDIAKIND *
                                                   // Use with feature list capabilities, EN_ENCODE_CHN, 2-Monitor supports getting audio/video separately
	ZZ_CTRL_LOWRATEWPAN_ADD,                       // Add Wireless Device Info (Struct pInBuf = NET_CTRL_LOWRATEWPAN_ADD *, pOutBUf = NULL)
	ZZ_CTRL_LOWRATEWPAN_REMOVEALL,                 // Remove All Wireless Device Info (Struct pInBuf = NET_CTRL_LOWRATEWPAN_REMOVEALL *, pOutBUf = NULL)
	ZZ_CTRL_SET_DOOR_WORK_MODE,                    // Set Door Lock Working Mode (Struct pInBuf = NET_IN_CTRL_ACCESS_SET_DOOR_WORK_MODE *, pOutBUf = NULL)	
    ZZ_CTRL_TEST_MAIL,                             // Test Email pInBuf = NET_IN_TEST_MAIL *, pOutBUf = NET_OUT_TEST_MAIL *
    ZZ_CTRL_CONTROL_SMART_SWITCH,                  // Control Smart Switch pInBuf = NET_IN_CONTROL_SMART_SWITCH *, pOutBUf = NET_OUT_CONTROL_SMART_SWITCH *
	ZZ_CTRL_LOWRATEWPAN_SETWORKMODE,          	   // Set Detector Working Mode (Struct pInBuf = NET_IN_CTRL_LOWRATEWPAN_SETWORKMODE *, pOutBUf = NULL)
	ZZ_CTRL_COAXIAL_CONTROL_IO,					   // Send Coaxial IO Control Command (Struct pInBuf = NET_IN_CONTROL_COAXIAL_CONTROL_IO*, pOutBUf = NET_OUT_CONTROL_COAXIAL_CONTROL_IO*)





	/**********LowRateWPAN Control(0x10100-0x10150)**********************************************************************************/
	ZZ_CTRL_LOWRATEWPAN_GETWIRELESSDEVSIGNAL = 0x10100,      // Get Wireless Device Signal Strength (Struct pInBuf = NET_IN_CTRL_LOWRATEWPAN_GETWIRELESSDEVSIGNAL *,pOutBuf = NET_OUT_CTRL_LOWRATEWPAN_GETWIRELESSDEVSIGNAL *)
} ZZCtrlType;


#define ZZ_MAX_PLATENUMBER_LEN    64                           // Max Plate Number Length

// Open Gate Parameters (Corresponds to ZZ_CTRL_OPEN_STROBE)
typedef struct tagZZNET_CTRL_OPEN_STROBE
{
    DWORD               dwSize;
    int                 nChannelId;                         // Channel ID
    char                szPlateNumber[ZZ_MAX_PLATENUMBER_LEN]; // Plate Number
}ZZNET_CTRL_OPEN_STROBE;

// Close Gate Parameters (Corresponds to ZZ_CTRL_CLOSE_STROBE)
typedef struct tagZZNET_CTRL_CLOSE_STROBE
{
    DWORD               dwSize;
    int                 nChannelId;                         // Channel ID
}ZZNET_CTRL_CLOSE_STROBE;

// Video Wall Display Info Control Parameters
typedef struct tagZZNET_CTRL_MONITORWALL_TVINFO 
{
    DWORD               dwSize;
    int                 nMonitorWallID;         // Video Wall ID, required for both ZZ_CTRL_MONITORWALL_TVINFO and ZZ_DEVSTATE_MONITORWALL_TVINFO
    BOOL                bDecodeChannel;         // Display Decode Channel Info, used in ZZ_CTRL_MONITORWALL_TVINFO
    BOOL                bControlID;             // Display Screen Control ID, used in ZZ_CTRL_MONITORWALL_TVINFO
    BOOL                bCameraID;              // Display Decode Channel Source ID, used in ZZ_CTRL_MONITORWALL_TVINFO
} ZZNET_CTRL_MONITORWALL_TVINFO;

// Initialize Device Account Input Struct
typedef struct tagZZNET_IN_INIT_DEVICE_ACCOUNT
{
	DWORD					dwSize;										// Structure size: Assign when initializing
	char					szMac[ZZ_MACADDR_LEN];						// Device MAC Address	
	char					szUserName[ZZ_MAX_USER_NAME_LEN];				// Username
	char					szPwd[ZZ_MAX_PWD_LEN];							// Device Password
	char					szCellPhone[ZZ_MAX_CELL_PHONE_NUMBER_LEN];		// Reserved Phone Number
	char					szMail[ZZ_MAX_MAIL_LEN];						// Reserved Email
	BYTE					byInitStatus;								// This field is deprecated															
	BYTE					byPwdResetWay;								// Password reset methods supported by device: value returned in byPwdResetWay from search interface (ZZNETSDK_SearchDevices, callback of ZZNETSDK_StartSearchDevices, ZZNETSDK_SearchDevicesByIPs)	
																		// See DEVICE_NET_INFO_EX struct for meaning, must match byPwdResetWay returned by search interface
																		// bit0 : 1-Supports reserved phone number, fill szCellPhone (if needed)
																		// bit1 : 1-Supports reserved email, fill szMail (if needed)
	BYTE					byReserved[2];								// Reserved fields
}ZZNET_IN_INIT_DEVICE_ACCOUNT;

// Initialize Device Account Output Struct
typedef struct tagZZNET_OUT_INIT_DEVICE_ACCOUNT
{
	DWORD					dwSize;// Structure size: Assign when initializing
}ZZNET_OUT_INIT_DEVICE_ACCOUNT;






// Alarm IO Control
typedef struct 
{
    unsigned short       index;                    // Port Index
    unsigned short       state;                    // Port State, 0 - Closed, 1 - Open
} ZZ_ALARM_CONTROL;

// Alarm Decoder Control
typedef struct 
{
    int                 decoderNo;               // Alarm Decoder No, starts from 0
    unsigned short      alarmChn;                // Alarm Output Port, starts from 0
    unsigned short      alarmState;              // Alarm Output State; 1: Open, 0: Closed
} ZZ_DECODER_ALARM_CONTROL;

// Trigger Mode
typedef struct
{
    unsigned short       index;                    // Port Index
    unsigned short       mode;                     // Trigger Mode (0: Closed, 1: Manual, 2: Auto); For unset channels, SDK keeps original settings by default.
    BYTE                 bReserved[28];            
} ZZ_TRIGGER_MODE_CONTROL;

// IO Control Command, corresponds to ZZNETSDK_QueryIOControlState
typedef enum _ZZIOTYPE
{
    ZZ_ALARMINPUT = 1,                             // Control Alarm Input, uses ZZ_ALARM_CONTROL
    ZZ_ALARMOUTPUT = 2,                            // Control Alarm Output, uses ZZ_ALARM_CONTROL
    ZZ_DECODER_ALARMOUT = 3,                       // Control Alarm Decoder Output, uses ZZ_DECODER_ALARM_CONTROL
    ZZ_WIRELESS_ALARMOUT = 5,                      // Control Wireless Alarm Output, uses ZZ_ALARM_CONTROL
    ZZ_ALARM_TRIGGER_MODE = 7,                     // Alarm Trigger Mode (Manual, Auto, Closed), uses ZZ_TRIGGER_MODE_CONTROL
} ZZ_IOTYPE;











//-------------------------------Device Property ---------------------------------
// Device information 
typedef struct
{
	BYTE				sSerialNumber[ZZ_SERIALNO_LEN];	// SN
	BYTE				byAlarmInPortNum;		// DVR alarm input amount
	BYTE				byAlarmOutPortNum;		// DVR alarm output amount
	BYTE				byDiskNum;				// DVR HDD amount 
	BYTE				byDVRType;				// DVR type.Please refer to NET_DEVICE_TYPE
    union
    {
	BYTE				byChanNum;				// DVR channel amount 
        BYTE            byLeftLogTimes;         // When login failed due to password error, notice user via this parameter, remaining login times, is 0 means this parameter is invalid
    };
} ZZNET_DEVICEINFO, *LPZZNET_DEVICEINFO;

// Realplay Type, corresponds to ZZNETSDK_RealPlayEx
typedef enum _ZZRealPlayType
{
    ZZ_RType_Realplay = 0,                      // Realtime Preview
    ZZ_RType_Multiplay,                         // Multi-window Preview
    ZZ_RType_Realplay_0,                        // Realtime Monitor - Main Stream, same as ZZ_RType_Realplay
    ZZ_RType_Realplay_1,                        // Realtime Monitor - Sub Stream 1
    ZZ_RType_Realplay_2,                        // Realtime Monitor - Sub Stream 2
    ZZ_RType_Realplay_3,                        // Realtime Monitor - Sub Stream 3    
    ZZ_RType_Multiplay_1,                       // Multi-window Preview - 1 Window
    ZZ_RType_Multiplay_4,                       // Multi-window Preview - 4 Windows
    ZZ_RType_Multiplay_8,                       // Multi-window Preview - 8 Windows
    ZZ_RType_Multiplay_9,                       // Multi-window Preview - 9 Windows
    ZZ_RType_Multiplay_16,                      // Multi-window Preview - 16 Windows
    ZZ_RType_Multiplay_6,                       // Multi-window Preview - 6 Windows
    ZZ_RType_Multiplay_12,                      // Multi-window Preview - 12 Windows
    ZZ_RType_Multiplay_25,                      // Multi-window Preview - 25 Windows
    ZZ_RType_Multiplay_36,                      // Multi-window Preview - 36 Windows
	ZZ_RType_Multiplay_64,						// Multi-window Preview - 64 Windows
    ZZ_RType_Realplay_Test = 255,               // Bandwidth Test Stream
} ZZ_RealPlayType;


/////////////////////////////////PTZ Related/////////////////////////////////

// Common PTZ Control Commands
typedef enum _ZZ_PTZ_ControlType
{

    ZZ_PTZ_UP_CONTROL = 0,                      // Up
    ZZ_PTZ_DOWN_CONTROL,                        // Down
    ZZ_PTZ_LEFT_CONTROL,                        // Left
    ZZ_PTZ_RIGHT_CONTROL,                       // Right
    ZZ_PTZ_ZOOM_ADD_CONTROL,                    // Zoom +
    ZZ_PTZ_ZOOM_DEC_CONTROL,                    // Zoom -
    ZZ_PTZ_FOCUS_ADD_CONTROL,                   // Focus +
    ZZ_PTZ_FOCUS_DEC_CONTROL,                   // Focus -
    ZZ_PTZ_APERTURE_ADD_CONTROL,                // Aperture +
    ZZ_PTZ_APERTURE_DEC_CONTROL,                // Aperture -
    ZZ_PTZ_POINT_MOVE_CONTROL,                  // Move to Preset
    ZZ_PTZ_POINT_SET_CONTROL,                   // Set Preset
    ZZ_PTZ_POINT_DEL_CONTROL,                   // Delete Preset
    ZZ_PTZ_POINT_LOOP_CONTROL,                  // Tour between points
    ZZ_PTZ_LAMP_CONTROL                         // Light/Wiper
} ZZ_PTZ_ControlType;

// PTZ Control Extended Commands
typedef enum _ZZ_EXTPTZ_ControlType
{
    ZZ_EXTPTZ_LEFTTOP = 0x20,                   // Top Left
    ZZ_EXTPTZ_RIGHTTOP,                         // Top Right
    ZZ_EXTPTZ_LEFTDOWN,                         // Bottom Left
    ZZ_EXTPTZ_RIGHTDOWN,                        // Bottom Right
    ZZ_EXTPTZ_ADDTOLOOP,                        // Add Preset to Tour | Tour Route | Preset Value
    ZZ_EXTPTZ_DELFROMLOOP,                      // Delete Preset from Tour | Tour Route | Preset Value
    ZZ_EXTPTZ_CLOSELOOP,                        // Clear Tour | Tour Route
    ZZ_EXTPTZ_STARTPANCRUISE,                   // Start Pan Rotation
    ZZ_EXTPTZ_STOPPANCRUISE,                    // Stop Pan Rotation
    ZZ_EXTPTZ_SETLEFTBORDER,                    // Set Left Border
    ZZ_EXTPTZ_SETRIGHTBORDER,                   // Set Right Border
    ZZ_EXTPTZ_STARTLINESCAN,                    // Start Line Scan
    ZZ_EXTPTZ_CLOSELINESCAN,                    // Stop Line Scan
    ZZ_EXTPTZ_SETMODESTART,                     // Set Mode Start | Mode Route
    ZZ_EXTPTZ_SETMODESTOP,                      // Set Mode Stop | Mode Route
    ZZ_EXTPTZ_RUNMODE,                          // Run Mode | Mode Route
    ZZ_EXTPTZ_STOPMODE,                         // Stop Mode | Mode Route
    ZZ_EXTPTZ_DELETEMODE,                       // Clear Mode | Mode Route
    ZZ_EXTPTZ_REVERSECOMM,                      // Reverse Command
    ZZ_EXTPTZ_FASTGOTO,                         // Fast Position | Horizontal(8192) | Vertical(8192) | Zoom(4)
    ZZ_EXTPTZ_AUXIOPEN,                         // Aux Switch On | Aux Point (param4 corresponds to PTZ_CONTROL_AUXILIARY, param1/2/3 invalid, dwStop set FALSE)
    ZZ_EXTPTZ_AUXICLOSE,                        // Aux Switch Off | Aux Point (param4 corresponds to PTZ_CONTROL_AUXILIARY, param1/2/3 invalid, dwStop set FALSE)
    ZZ_EXTPTZ_OPENMENU = 0x36,                  // Open Dome Menu
    ZZ_EXTPTZ_CLOSEMENU,                        // Close Menu
    ZZ_EXTPTZ_MENUOK,                           // Menu OK
    ZZ_EXTPTZ_MENUCANCEL,                       // Menu Cancel
    ZZ_EXTPTZ_MENUUP,                           // Menu Up
    ZZ_EXTPTZ_MENUDOWN,                         // Menu Down
    ZZ_EXTPTZ_MENULEFT,                         // Menu Left
    ZZ_EXTPTZ_MENURIGHT,                        // Menu Right
    ZZ_EXTPTZ_ALARMHANDLE = 0x40,               // Alarm Linkage PTZ parm1: Alarm Input Channel; parm2: Linkage Type 1-Preset 2-Line Scan 3-Tour; parm3: Linkage Value (e.g. Preset No.)
    ZZ_EXTPTZ_MATRIXSWITCH = 0x41,              // Matrix Switch parm1: Monitor ID (Video Out ID); parm2: Video In ID; parm3: Matrix ID
    ZZ_EXTPTZ_LIGHTCONTROL,                     // Light Control
    ZZ_EXTPTZ_EXACTGOTO,                        // 3D Exact Positioning parm1: Horizontal Angle(0~3600); parm2: Vertical Angle(0~900); parm3: Zoom(1~128)
    ZZ_EXTPTZ_RESETZERO,                        // 3D Positioning Reset Zero
    ZZ_EXTPTZ_MOVE_ABSOLUTELY,                  // Absolute Move Control, param4 corresponds to PTZ_CONTROL_ABSOLUTELY
    ZZ_EXTPTZ_MOVE_CONTINUOUSLY,                // Continuous Move Control, param4 corresponds to PTZ_CONTROL_CONTINUOUSLY
    ZZ_EXTPTZ_GOTOPRESET,                       // Go to Preset with Speed, parm4 corresponds to PTZ_CONTROL_GOTOPRESET
    ZZ_EXTPTZ_SET_VIEW_RANGE = 0x49,            // Set View Range (param4 corresponds to PTZ_VIEW_RANGE_INFO)
    ZZ_EXTPTZ_FOCUS_ABSOLUTELY = 0x4A,          // Absolute Focus (param4 corresponds to PTZ_FOCUS_ABSOLUTELY)
    ZZ_EXTPTZ_HORSECTORSCAN = 0x4B,             // Horizontal Sector Scan (param4 corresponds to PTZ_CONTROL_SECTORSCAN, param1/2/3 invalid)
    ZZ_EXTPTZ_VERSECTORSCAN = 0x4C,             // Vertical Sector Scan (param4 corresponds to PTZ_CONTROL_SECTORSCAN, param1/2/3 invalid)
    ZZ_EXTPTZ_SET_ABS_ZOOMFOCUS = 0x4D,         // Set Absolute Zoom/Focus, param1: Zoom [0,255], param2: Focus [0,255], param3/4 invalid
    ZZ_EXTPTZ_SET_FISHEYE_EPTZ = 0x4E,          // Control Fisheye E-PTZ, param4 corresponds to PTZ_CONTROL_SET_FISHEYE_EPTZ  
    ZZ_EXTPTZ_SET_TRACK_START = 0x4F,           // Start Track Control (param4 corresponds to PTZ_CONTROL_SET_TRACK_CONTROL, dwStop FALSE, param1/2/3 invalid)
    ZZ_EXTPTZ_SET_TRACK_STOP = 0x50,            // Stop Track Control (param4 corresponds to PTZ_CONTROL_SET_TRACK_CONTROL, dwStop FALSE, param1/2/3 invalid)
    ZZ_EXTPTZ_RESTART = 0x51,                   // PTZ Reboot (param1/2/3/4 invalid, dwStop FALSE)
	ZZ_EXTPTZ_INTELLI_TRACKMOVE = 0x52,         // PTZ Continuous Move, for Master-Slave Tracking, param4 corresponds to PTZ_CONTROL_INTELLI_TRACKMOVE
    ZZ_EXTPTZ_SET_FOCUS_REGION = 0x53,          // Set Region Focus (param4 corresponds to PTZ_CONTROL_SET_FOCUS_REGION, dwStop FALSE, param1/2/3 invalid)
    ZZ_EXTPTZ_PAUSELINESCAN = 0x54,             // Pause Line Scan (param1/2/3/4 invalid, dwStop FALSE)

    ZZ_EXTPTZ_UP_TELE = 0x70,                   // Up + TELE param1=Speed(1-8), same below
    ZZ_EXTPTZ_DOWN_TELE,                        // Down + TELE
    ZZ_EXTPTZ_LEFT_TELE,                        // Left + TELE
    ZZ_EXTPTZ_RIGHT_TELE,                       // Right + TELE
    ZZ_EXTPTZ_LEFTUP_TELE,                      // TopLeft + TELE
    ZZ_EXTPTZ_LEFTDOWN_TELE,                    // BottomLeft + TELE
    ZZ_EXTPTZ_TIGHTUP_TELE,                     // TopRight + TELE
    ZZ_EXTPTZ_RIGHTDOWN_TELE,                   // BottomRight + TELE
    ZZ_EXTPTZ_UP_WIDE,                          // Up + WIDE param1=Speed(1-8), same below
    ZZ_EXTPTZ_DOWN_WIDE,                        // Down + WIDE
    ZZ_EXTPTZ_LEFT_WIDE,                        // Left + WIDE
    ZZ_EXTPTZ_RIGHT_WIDE,                       // Right + WIDE
    ZZ_EXTPTZ_LEFTUP_WIDE,                      // TopLeft + WIDE
    ZZ_EXTPTZ_LEFTDOWN_WIDE,                    // BottomLeft + WIDE
    ZZ_EXTPTZ_TIGHTUP_WIDE,                     // TopRight + WIDE
    ZZ_EXTPTZ_RIGHTDOWN_WIDE,                   // BottomRight + WIDE
	ZZ_EXTPTZ_GOTOPRESETSNAP = 0x80,            // Go to Preset and Snapshot
    ZZ_EXTPTZ_DIRECTIONCALIBRATION = 0x82,      // Calibrate PTZ Direction (Dual Direction)
    ZZ_EXTPTZ_SINGLEDIRECTIONCALIBRATION = 0x83, // Calibrate PTZ Direction (Single Direction), param4 corresponds to NET_IN_CALIBRATE_SINGLEDIRECTION
    
    ZZ_EXTPTZ_TOTAL,                            // Max Command Value
} ZZ_EXTPTZ_ControlType;

// Fisheye E-PTZ Commands
typedef enum tagZZNET_FISHEYE_EPTZ_CMD
{
    ZZNET_FISHEYE_EPTZ_CMD_UNKOWN,                    // Unknown Type
	ZZNET_FISHEYE_EPTZ_CMD_ZOOMIN,                    // Zoom In, dwParam1 is step, range 1~8
	ZZNET_FISHEYE_EPTZ_CMD_ZOOMOUT,                   // Zoom Out, dwParam1 is step, range 1~8
    ZZNET_FISHEYE_EPTZ_CMD_UP,                        // Move Up, dwParam1 is step, range 1~8
    ZZNET_FISHEYE_EPTZ_CMD_DOWN,                      // Move Down, dwParam1 is step, range 1~8
    ZZNET_FISHEYE_EPTZ_CMD_LEFT,                      // Move Left, dwParam1 is step, range 1~8
    ZZNET_FISHEYE_EPTZ_CMD_RIGHT,                     // Move Right, dwParam1 is step, range 1~8
    ZZNET_FISHEYE_EPTZ_CMD_ROTATECLOCK,               // Auto Rotate Clockwise, dwParam1 is step, range 1~8
    ZZNET_FISHEYE_EPTZ_CMD_ROTATEANTICLOCK,           // Auto Rotate Counter-Clockwise, dwParam1 is step, range 1~8
    ZZNET_FISHEYE_EPTZ_CMD_STOP,                      // Stop Auto Rotation
    ZZNET_FISHEYE_EPTZ_CMD_TAPVIEW,                   // Display specified position (Tap View), dwParam1 is EPTZ focus X coord (in corrected image), max value is corrected image width
    // dwParam2 is EPTZ focus Y coord (in corrected image), max value is corrected image height
    ZZNET_FISHEYE_EPTZ_CMD_SHOEREGION,                // Box Zoom, wParam1 is center X of rect,
    // dwParam2 is center Y of rect, dwParam3 is rect width
    // dwParam4 is rect height
}ZZNET_FISHEYE_EPTZ_CMD;

// Track Control Commands
typedef enum tagZZNET_TRACK_CONTROL_CMD
{
    ZZNET_TRACK_CONTROL_CMD_UP,                       // Move Up, dwParam1 is step, range 1~8 
    ZZNET_TRACK_CONTROL_CMD_DOWN,                     // Move Down, dwParam1 is step, range 1~8
    ZZNET_TRACK_CONTROL_CMD_LEFT,                     // Move Left, dwParam1 is step, range 1~8
    ZZNET_TRACK_CONTROL_CMD_RIGHT,                    // Move Right, dwParam1 is step, range 1~8
    ZZNET_TRACK_CONTROL_CMD_SETPRESET,                // Set Preset, dwParam1 is preset value
    ZZNET_TRACK_CONTROL_CMD_CLEARPRESET,              // Clear Preset, dwParam1 is preset value
    ZZNET_TRACK_CONTROL_CMD_GOTOPRESET,               // Go to Preset, dwParam1 is preset value
} ZZNET_TRACK_CONTROL_CMD;

// Fisheye Calibration Mode
typedef enum tagZZNET_CALIBRATE_MODE
{
    ZZNET_FISHEYE_CALIBRATE_MODE_UNKOWN,                      // Unknown Mode 
    ZZNET_FISHEYE_CALIBRATE_MODE_ORIGIAL,                     // Original Image Mode
    ZZNET_FISHEYE_CALIBRATE_MODE_CONFIG,                      // Config Mode
    ZZNET_FISHEYE_CALIBRATE_MODE_PANORAMA,                    // Panorama Mode
    ZZNET_FISHEYE_CALIBRATE_MODE_DOUBLEPANORAMA,              // Double Panorama Mode
    ZZNET_FISHEYE_CALIBRATE_MODE_ORIGIALPLUSTHREEEPTZREGION,  // 1+3 Mode (1 Original Fisheye + 3 E-PTZ Regions)
    ZZNET_FISHEYE_CALIBRATE_MODE_SINGLE,                      // Single E-PTZ Mode (Only 1 E-PTZ Window)
    ZZNET_FISHEYE_CALIBRATE_MODE_FOUREPTZREGION,              // 4-Window Mode (4 E-PTZ Windows)
    ZZNET_FISHEYE_CALIBRATE_MODE_NORMAL,                      // Normal Mode
}ZZNET_FISHEYE_CALIBRATE_MODE;

typedef enum tagZZNET_FISHEYE_TYPE
{
    ZZNET_FISHEYE_UNKOWN =0   ,               // Unknown
    ZZNET_FISHEYE_CHIP        ,               // Only supports device-side correction
    ZZNET_FISHEYE_PLUGIN      ,               // Only supports plugin/control correction
    ZZNET_FISHEYE_CHIP_PLUGIN ,               // Supports both
}ZZNET_FISHEYE_TYPE;

// Fisheye Mount Mode
typedef enum tagZZNET_FISHEYE_MOUNT_MODE
{
    ZZNET_FISHEYE_MOUNT_MODE_UNKOWN,                          // Unknown Mode                  
    ZZNET_FISHEYE_MOUNT_MODE_CEIL,                            // Ceiling Mount 
    ZZNET_FISHEYE_MOUNT_MODE_WALL,                            // Wall Mount  
    ZZNET_FISHEYE_MOUNT_MODE_FLOOR,                           // Floor Mount  
}ZZNET_FISHEYE_MOUNT_MODE;


// Resolution Enum, used by ZZ_DSP_ENCODECAP
typedef enum _ZZ_CAPTURE_SIZE
{
    ZZ_CAPTURE_SIZE_D1,                               // 704*576(PAL)  704*480(NTSC)
    ZZ_CAPTURE_SIZE_HD1,                              // 352*576(PAL)  352*480(NTSC)
    ZZ_CAPTURE_SIZE_BCIF,                             // 704*288(PAL)  704*240(NTSC)
    ZZ_CAPTURE_SIZE_CIF,                              // 352*288(PAL)  352*240(NTSC)
    ZZ_CAPTURE_SIZE_QCIF,                             // 176*144(PAL)  176*120(NTSC)
    ZZ_CAPTURE_SIZE_VGA,                              // 640*480
    ZZ_CAPTURE_SIZE_QVGA,                             // 320*240
    ZZ_CAPTURE_SIZE_SVCD,                             // 480*480
    ZZ_CAPTURE_SIZE_QQVGA,                            // 160*128
    ZZ_CAPTURE_SIZE_SVGA,                             // 800*592
    ZZ_CAPTURE_SIZE_XVGA,                             // 1024*768
    ZZ_CAPTURE_SIZE_WXGA,                             // 1280*800
    ZZ_CAPTURE_SIZE_SXGA,                             // 1280*1024  
    ZZ_CAPTURE_SIZE_WSXGA,                            // 1600*1024  
    ZZ_CAPTURE_SIZE_UXGA,                             // 1600*1200
    ZZ_CAPTURE_SIZE_WUXGA,                            // 1920*1200
    ZZ_CAPTURE_SIZE_LTF,                              // 240*192
    ZZ_CAPTURE_SIZE_720,                              // 1280*720
    ZZ_CAPTURE_SIZE_1080,                             // 1920*1080
    ZZ_CAPTURE_SIZE_1_3M,                             // 1280*960
    ZZ_CAPTURE_SIZE_2M,                               // 1872*1408
    ZZ_CAPTURE_SIZE_5M,                               // 3744*1408
    ZZ_CAPTURE_SIZE_3M,                               // 2048*1536
    ZZ_CAPTURE_SIZE_5_0M,                             // 2432*2050
    ZZ_CPTRUTE_SIZE_1_2M,                             // 1216*1024
    ZZ_CPTRUTE_SIZE_1408_1024,                        // 1408*1024
    ZZ_CPTRUTE_SIZE_8M,                               // 3296*2472
    ZZ_CPTRUTE_SIZE_2560_1920,                        // 2560*1920(5M)
    ZZ_CAPTURE_SIZE_960H,                             // 960*576(PAL) 960*480(NTSC)
    ZZ_CAPTURE_SIZE_960_720,                          // 960*720
    ZZ_CAPTURE_SIZE_NHD,                              // 640*360
    ZZ_CAPTURE_SIZE_QNHD,                             // 320*180
    ZZ_CAPTURE_SIZE_QQNHD,                            // 160*90
    ZZ_CAPTURE_SIZE_960_540,                          // 960*540
    ZZ_CAPTURE_SIZE_640_352,                          // 640*352
    ZZ_CAPTURE_SIZE_640_400,                          // 640*400
    ZZ_CAPTURE_SIZE_320_192,                          // 320*192    
    ZZ_CAPTURE_SIZE_320_176,                          // 320*176
    ZZ_CAPTURE_SIZE_NR=255  
} ZZ_CAPTURE_SIZE;












// Set Network Adaptive Encoding Buffer Policy Input
typedef struct tagZZNET_IN_BUFFER_POLICY
{
    DWORD                   dwSize;             
    ZZ_RealPlayType         emRealPlayType;          // Stream type. Only supports Main, Sub, Adaptive Test stream
    unsigned int            nPolicy;                 // Buffer Policy: 0 Default, 1 Smooth, 2 Realtime
}ZZNET_IN_BUFFER_POLICY; 


// Audio Encoding Type
typedef enum __ZZ_TALK_CODING_TYPE 
{
    ZZ_TALK_DEFAULT = 0,                        // PCM without header
    ZZ_TALK_PCM = 1,                            // PCM with header
    ZZ_TALK_G711a,                              // G711a
    ZZ_TALK_AMR,                                // AMR
    ZZ_TALK_G711u,                              // G711u
    ZZ_TALK_G726,                               // G726
    ZZ_TALK_G723_53,                            // G723_53
    ZZ_TALK_G723_63,                            // G723_63
    ZZ_TALK_AAC,                                // AAC
    ZZ_TALK_OGG,                                // OGG
    ZZ_TALK_G729 = 10,                          // G729
    ZZ_TALK_MPEG2,                               // MPEG2
    ZZ_TALK_MPEG2_Layer2,                        // MPEG2-Layer2
    ZZ_TALK_G722_1,                             // G.722.1
    ZZ_TALK_ADPCM = 21,                         // ADPCM
    ZZ_TALK_MP3   = 22,                            // MP3
    
} ZZ_TALK_CODING_TYPE;

// Video Compression Format
typedef enum tagZZNET_EM_VIDEO_COMPRESSION
{
	EM_ZZ_VIDEO_FORMAT_MPEG4,								// MPEG4
	EM_ZZ_VIDEO_FORMAT_MS_MPEG4,							// MS-MPEG4
	EM_ZZ_VIDEO_FORMAT_MPEG2,								// MPEG2
	EM_ZZ_VIDEO_FORMAT_MPEG1,								// MPEG1
	EM_ZZ_VIDEO_FORMAT_H263,								// H.263
	EM_ZZ_VIDEO_FORMAT_MJPG,								// MJPG
	EM_ZZ_VIDEO_FORMAT_FCC_MPEG4,							// FCC-MPEG4
	EM_ZZ_VIDEO_FORMAT_H264,								// H.264
    EM_ZZ_VIDEO_FORMAT_H265,								// H.265
	EM_ZZ_VIDEO_FORMAT_SVAC,								// SVAC
} ZZNET_EM_VIDEO_COMPRESSION;

// Bitrate Control Mode
typedef enum tagZZNET_EM_BITRATE_CONTROL
{
	EM_ZZ_BITRATE_CBR,									// Constant Bitrate
	EM_ZZ_BITRATE_VBR,									// Variable Bitrate
} ZZNET_EM_BITRATE_CONTROL;

// Image Quality
typedef enum tagZZNET_EM_IMAGE_QUALITY
{
	EM_ZZ_IMAGE_QUALITY_Q10 = 1,							// Image Quality 10%
	EM_ZZ_IMAGE_QUALITY_Q30,								// Image Quality 30%
	EM_ZZ_IMAGE_QUALITY_Q50,								// Image Quality 50%
	EM_ZZ_IMAGE_QUALITY_Q60,								// Image Quality 60%
	EM_ZZ_IMAGE_QUALITY_Q80,								// Image Quality 80%
	EM_ZZ_IMAGE_QUALITY_Q100,								// Image Quality 100%
} ZZNET_EM_IMAGE_QUALITY;

// H264 Profile Rank
typedef enum tagZZNET_EM_H264_PROFILE_RANK
{
	EM_ZZ_PROFILE_UNKNOWN,							   // Unknown
	EM_ZZ_PROFILE_BASELINE = 1,                       // Provides I/P frames, only supports progressive and CAVLC
	EM_ZZ_PROFILE_MAIN,                               // Provides I/P/B frames, supports progressive and interlaced, provides CAVLC or CABAC
	EM_ZZ_PROFILE_EXTENDED,                           // Provides I/P/B/SP/SI frames, only supports progressive and CAVLC
	EM_ZZ_PROFILE_HIGH,                               // FRExt, Adds to Main Profile: 8x8 intra prediction, custom 
												   // quant, lossless video coding, more YUV formats
}ZZNET_EM_H264_PROFILE_RANK;

// Stream Type
typedef enum tagZZNET_EM_FORMAT_TYPE
{
	EM_ZZ_FORMAT_TYPE_UNKNOWN,				// Unknown
	/*Main Stream*/
	EM_ZZ_FORMAT_MAIN_NORMAL,				// Main Stream Normal Encode
	EM_ZZ_FORMAT_MAIN_MOVEEXAMINE,			// Main Stream Motion Detect Encode
	EM_ZZ_FORMAT_MAIN_ALARM,				// Main Stream Alarm Encode

	/*Sub Stream*/
	EM_ZZ_FORMAT_EXTRA1,					// Sub Stream 1
	EM_ZZ_FORMAT_EXTRA2,					// Sub Stream 2
	EM_ZZ_FORMAT_EXTRA3,					// Sub Stream 3
} ZZNET_EM_FORMAT_TYPE;

// Packaging Mode
typedef enum tagZZNET_EM_PACK_TYPE
{
	EM_ZZ_PACK_UNKOWN,				// UNKOWN
	EM_ZZ_PACK_ZLAV,				// ZLAV
	EM_ZZ_PACK_PS,					// ps
} ZZNET_EM_PACK_TYPE;


// Video Stream Type
typedef enum tagZZNET_STREAM_TYPE
{
    ZZNET_EM_STREAM_ERR,                      // Other
    ZZNET_EM_STREAM_MAIN,                     // "Main" Stream
    ZZNET_EM_STREAM_EXTRA_1,                  // "Extra1" Sub Stream 1
    ZZNET_EM_STREAM_EXTRA_2,                  // "Extra2" Sub Stream 2
    ZZNET_EM_STREAM_EXTRA_3,                  // "Extra3" Sub Stream 3
    ZZNET_EM_STREAM_SNAPSHOT,                 // "Snapshot" Stream
    ZZNET_EM_STREAM_OBJECT,                   // "Object" Stream
    ZZNET_EM_STREAM_AUTO,                     // "Auto" Select proper stream
    ZZNET_EM_STREAM_PREVIEW,                  // "Preview" Raw data stream
    ZZNET_EM_STREAM_NONE,                     // No Video Stream (Audio Only)
}ZZNET_STREAM_TYPE;


// Main (Sub) Stream Video Format (f6/f5/bin)
typedef struct tagZZNET_ENCODE_VIDEO_INFO
{
	DWORD						    dwSize;
	ZZNET_EM_FORMAT_TYPE			emFormatType;				// Stream type, need to set for both Get and Set
	BOOL						    bVideoEnable;				// Video Enable
	ZZNET_EM_VIDEO_COMPRESSION 	    emCompression;				// Video Compression Format
	int							    nWidth;						// Video Width
	int							    nHeight;					// Video Height
	ZZNET_EM_BITRATE_CONTROL		emBitRateControl;			// Bitrate Control Mode
	int							    nBitRate;					// Video Bitrate (kbps)
	float						    nFrameRate;					// Video Framerate
	int							    nIFrameInterval;			// I-Frame Interval (1-100), e.g., 50 means 1 I-frame per 49 B/P frames.
	ZZNET_EM_IMAGE_QUALITY		    emImageQuality;				// Image Quality
} ZZNET_ENCODE_VIDEO_INFO;




// Audio Encoding Info
typedef struct  
{
    ZZ_TALK_CODING_TYPE encodeType;                         // Encode Type, currently only supports ZZ_TALK_PCM
    int                 nAudioBit;                          // Bit depth, e.g. 8 or 16, currently only 16
    DWORD               dwSampleRate;                       // Sample Rate, e.g. 8000 or 16000, currently only 16000
    int                 nPacketPeriod;                      // Packaging Period, unit ms, currently only 25
    char                reserved[60];
} ZZDEV_TALKDECODE_INFO;



// Audio Talk Parameters
typedef struct __ZZNET_SPEAK_PARAM
{
    DWORD           dwSize;                     // Struct size
    int             nMode;                      // 0: Talk (default), 1: Shout; reset when switching from Shout to Talk
    											// 2: One-way listen, reset when switching to other modes
    int             nSpeakerChannel;            // Speaker channel, valid for Shout
    BOOL            bEnableWait;                // Wait for device response when starting talk. Default No. TRUE: Wait; FALSE: No wait
                                                // Timeout set by ZZNETSDK_SetNetworkParam, nWaittime in NET_PARAM
} ZZNET_SPEAK_PARAM;


// Talk Transfer Mode Enable
typedef struct tagZZNET_TALK_TRANSFER_PARAM
{
    DWORD           dwSize;
    BOOL            bTransfer;                  // Enable talk transfer mode, TRUE: Enable, FALSE: Disable
}ZZNET_TALK_TRANSFER_PARAM;




// Call Event Action EM_AUDIO_CB_FLAG_NEWCALL
typedef enum tagEM_ZZNEWCALL_ACTION
{
    EM_ZZNEWCALL_ACTION_UNKNOWN,                  // No Action
    EM_ZZNEWCALL_ACTION_REFUSE,                   // Refuse
    EM_ZZNEWCALL_ACTION_ACCEPT,                   // Accept
} EM_ZZNEWCALL_ACTION;

typedef enum tagEM_ZZVT_PARAM_VALID
{
    EM_ZZVT_PARAM_VALID_EVENT_CB     = 0x0001,
    EM_ZZVT_PARAM_VALID_USER_DATA    = 0x0002,
    EM_ZZVT_PARAM_VALID_MID_NUM      = 0x0004,
    EM_ZZVT_PARAM_VALID_ACTION       = 0x0008,
    EM_ZZVT_PARAM_VALID_WAITTIME     = 0x0010,
    EM_ZZVT_PARAM_VALID_VIDEOWND     = 0x0020,
    EM_ZZVT_PARAM_VALID_CSMODE       = 0x0040,
    EM_ZZVT_PARAM_VALID_AUDIO_ENCODE = 0x0080,
    EM_ZZVT_PARAM_VALID_LOCAL_IP     = 0x0100,
} EM_ZZVT_PARAM_VALID;

// VT Talk Parameters
typedef struct tagZZNET_VT_TALK_PARAM
{
    DWORD               dwSize;                  // Struct Size
    int                 nValidFlag;              // Bitwise flag for validity of following fields, combination of EM_ZZVT_PARAM_VALID
    pfVtEventCallBack   pfEventCb;               // Event Callback, EM_ZZVT_PARAM_VALID_EVENT_CB
    LDWORD              dwUser;                  // User data for callback, EM_ZZVT_PARAM_VALID_USER_DATA
    char                szPeerMidNum[16];        // Called Number, 8 digits, EM_ZZVT_PARAM_VALID_MID_NUM
    EM_ZZNEWCALL_ACTION   emAction;                // Action for call, 0: None, 1: Refuse, 2: Accept, EM_ZZVT_PARAM_VALID_ACTION
    int                 nWaitTime;               // Timeout, unit ms, EM_ZZVT_PARAM_VALID_WAITTIME
    HWND                hVideoWnd;               // Video Window for Video Talk, EM_ZZVT_PARAM_VALID_VIDEOWND
    BOOL                bClient;                 // Client/Server Mode, TRUE: Client, FALSE: Server, EM_ZZVT_PARAM_VALID_CSMODE
    ZZDEV_TALKDECODE_INFO stAudioEncode;         // Audio Encode Info, EM_ZZVT_PARAM_VALID_AUDIO_ENCODE
} ZZNET_VT_TALK_PARAM;


// Record File Type
typedef enum __ZZNET_RECORD_TYPE
{
    ZZNET_RECORD_TYPE_ALL,                        // All Recordings
    ZZNET_RECORD_TYPE_NORMAL,                     // Normal Recording
    ZZNET_RECORD_TYPE_ALARM,                      // External Alarm Recording
    ZZNET_RECORD_TYPE_MOTION,                     // Motion Detection Recording
}ZZNET_RECORD_TYPE;
// Device Usage Mode / Intercom Method
typedef enum __EM_ZZUSEDEV_MODE
{
    ZZ_TALK_CLIENT_MODE,                        // Set Client Mode for Talk
    ZZ_TALK_SERVER_MODE,                        // Set Server Mode for Talk
    ZZ_TALK_ENCODE_TYPE,                        // Set Audio Encode Format (ZZDEV_TALKDECODE_INFO)
    ZZ_ALARM_LISTEN_MODE,                       // Set Alarm Subscription Mode
    ZZ_CONFIG_AUTHORITY_MODE,                   // Set Config Management via Authority
    ZZ_TALK_TALK_CHANNEL,                       // Set Talk Channel (0~MaxChannel-1)
    ZZ_RECORD_STREAM_TYPE,                      // Set stream type for record query/playback (0-Main&Sub, 1-Main, 2-Sub)  
    ZZ_TALK_SPEAK_PARAM,                        // Set Talk Params, struct ZZNET_SPEAK_PARAM
    ZZ_RECORD_TYPE,                             // Set record file type for time playback/download (see ZZNET_RECORD_TYPE)
    ZZ_TALK_MODE3,                              // Set Talk Params for 3rd Gen Device, struct NET_TALK_EX
    ZZ_PLAYBACK_REALTIME_MODE ,                 // Set Realtime Playback (0-Off, 1-On)
    ZZ_TALK_TRANSFER_MODE,                      // Set Talk Transfer Mode, struct ZZNET_TALK_TRANSFER_PARAM
    ZZ_TALK_VT_PARAM,                           // Set VT Talk Params, struct ZZNET_VT_TALK_PARAM
    ZZ_TARGET_DEV_ID,                           // Set Target Device ID, for querying new system capability (non-0: forward system capability message)
	ZZ_AUDIO_RECORD_LENGTH = 15,                // Set Audio Record Cache, corresponds to an int
} EM_ZZUSEDEV_MODE;

// Time Definition in Log Info
typedef struct _ZZDEVTIME
{
    DWORD                second:6;                // Sec    1-60        
    DWORD                minute:6;                // Min    1-60        
    DWORD                hour:5;                  // Hour    1-24        
    DWORD                day:5;                   // Day    1-31        
    DWORD                month:4;                 // Month    1-12        
    DWORD                year:6;                  // Year    2000-2063    
} ZZDEVTIME, *LPZZDEVTIME;

typedef struct tagZZRANGE
{
    float               fMax;                               // Max Value
    float               fMin;                               // Min Value
    BOOL                abStep;                             // Enable Step
    float               fStep;                              // Step Value
    BOOL                abDefault;                          // Enable Default
    float               fDefault;                           // Default Value
    char reserved[16];
} ZZRANGE;






// OSD Attribute Structure
typedef struct  tagZZ_ENCODE_WIDGET
{
    DWORD               rgbaFrontground;                // Object Foreground; RGBA bytes
    DWORD               rgbaBackground;                 // Object Background; RGBA bytes
    ZZ_RECT             rcRect;                         // Position
    BYTE                bShow;                          // Show Enable
    BYTE                bExtFuncMask;                   // Extension Enable, Mask 
                                                        // bit0: Show Day of Week, 0-No 1-Yes 
    BYTE                byReserved[2];
} ZZ_ENCODE_WIDGET, *LPZZ_ENCODE_WIDGET;

// Channel Audio/Video Options
typedef struct 
{
    // Video Params
    BYTE                byVideoEnable;                  // Video Enable; 1:On, 0:Off
    BYTE                byBitRateControl;               // Bitrate Control; see "Bitrate Control" constants
    BYTE                byFramesPerSec;                 // Frame Rate
    BYTE                byEncodeMode;                   // Encode Mode; see "Encode Mode" constants
    BYTE                byImageSize;                    // Resolution; see "Resolution" constants
    BYTE                byImageQlty:7;                  // Extended byImageQlty. If 0, Snapshot ImgQlty is 10/30/50/60/80/100 (6 values), Stream ImgQlty is 1-6 (compatible). If ImgQltyType is 1, ImgQlty range is 0~100
    BYTE                byImageQltyType:1;       
    WORD                wLimitStream;                   // Limit Stream Parameter
    // Audio Params
    BYTE                byAudioEnable;                  // Audio Enable; 1:On, 0:Off
    BYTE                wFormatTag;                     // Audio Encode Type: 0:G711A, 1:PCM, 2:G711U, 3:AMR, 4:AAC
    WORD                nChannels;                      // Channel Count
    WORD                wBitsPerSample;                 // Sampling Depth    
    BYTE                bAudioOverlay;                  // Audio Overlay Enable
    BYTE                bH264ProfileRank;               // H.264 Profile Rank (Valid when encode mode is H264), see enum EM_H264_PROFILE_RANK. 0 compatible with old version (invalid).
    DWORD               nSamplesPerSec;                 // Sample Rate
    BYTE                bIFrameInterval;                // I-Frame Interval, Number of P frames between two I frames, 0-149
    BYTE                bScanMode;                      // NSP
    BYTE                bReserved_3;
    BYTE                bReserved_4;
} ZZ_VIDEOENC_OPT, *LPZZ_VIDEOENC_OPT;

// Screen Color Attributes
typedef struct 
{
    ZZ_TSECT            stSect;
    BYTE                byBrightness;                   // Brightness; 0-100
    BYTE                byContrast;                     // Contrast; 0-100
    BYTE                bySaturation;                   // Saturation; 0-100
    BYTE                byHue;                          // Hue; 0-100
    BYTE                byGainEn;                       // Gain Enable
    BYTE                byGain;                         // Gain; 0-100
    BYTE                byGamma;                        // Gamma; 0-100
    BYTE                byReserved[1];
} ZZ_COLOR_CFG, *LPZZ_COLOR_CFG;

// Image Channel Configuration Structure
typedef struct 
{
    WORD                dwSize;
    BYTE                bNoise;
    BYTE                bMode;                          // (Vehicle Special Requirement) Mode 1 (Quality Priority): Record 4ch D1, 2fps, 128kbps (225MB/hour)
                                                        // Mode 2 (Fluency Priority): Record 4ch CIF, 12fps, 256kbps (550MB/hour)
                                                        // Mode 3 (Custom): User defined recording resolution, max capability 4CIF/25fps
    char                szChannelName[ZZ_CHAN_NAME_LEN];
    ZZ_VIDEOENC_OPT     stMainVideoEncOpt[ZZ_REC_TYPE_NUM];
    ZZ_VIDEOENC_OPT     stAssiVideoEncOpt[ZZ_N_ENCODE_AUX];        
    ZZ_COLOR_CFG        stColorCfg[ZZ_N_COL_TSECT];
    ZZ_ENCODE_WIDGET    stTimeOSD;
    ZZ_ENCODE_WIDGET    stChannelOSD;
    ZZ_ENCODE_WIDGET    stBlindCover[ZZ_N_COVERS];      // Privacy Masking (Single Area)
    BYTE                byBlindEnable;                  // Privacy Mask Switch; 0x00: Disable, 0x01: Local Preview Only, 0x10: Record & Network Preview Only, 0x11: Both
    BYTE                byBlindMask;                    // Privacy Mask Mask; Bit 1: Local Preview; Bit 2: Record (& Network Preview) */
    BYTE                bVolume;                        // Volume Threshold (0~100 adjustable)
    BYTE                bVolumeEnable;                  // Volume Threshold Enable
} ZZDEV_CHANNEL_CFG, *LPZZDEV_CHANNEL_CFG;





// Record File Information
typedef struct
{
    unsigned int        ch;                         // Channel
    char                filename[124];              // Filename
    unsigned int        framenum;                   // Total frames
    unsigned int        size;                       // File size, Unit: Kbyte
    ZZNET_TIME            starttime;                  // Start Time
    ZZNET_TIME            endtime;                    // End Time
    unsigned int        driveno;                    // Disk No (Distinguish Network/Local Record. 0-127 Local, 64 is CD1, 128 is Network)
    unsigned int        startcluster;               // Start Cluster
    BYTE                nRecordFileType;            // Record File Type 0:Normal; 1:Alarm; 2:Motion Detect; 3:Card No; 4:Picture; 5:Intelligent; 19:POS; 255:All
    BYTE                bImportantRecID;            // 0:Normal Record 1:Important Record
    BYTE                bHint;                      // File Positioning Index (When nRecordFileType==4<Picture>, bImportantRecID<<8 +bHint forms picture positioning index)
    BYTE                bRecType;                   // 0-Main Stream 1-Sub Stream 1 2-Sub Stream 2 3-Sub Stream 3
} ZZNET_RECORDFILE_INFO, *LPZZNET_RECORDFILE_INFO;



// Playback by Time Progress Callback Prototype
typedef void (CALLBACK *ffTimeDownLoadPosCallBack) (LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, ZZNET_RECORDFILE_INFO recordfileinfo, LDWORD dwUser);

// Record Query Type
typedef enum tagEmZZQueryRecordType
{
    EM_ZZ_RECORD_TYPE_ALL              = 0,            // All Records
    EM_ZZ_RECORD_TYPE_ALARM            = 1,            // External Alarm Record
    EM_ZZ_RECORD_TYPE_MOTION_DETECT    = 2,            // Motion Detection Record
    EM_ZZ_RECORD_TYPE_ALARM_ALL        = 3,            // All Alarm Records
    EM_ZZ_RECORD_TYPE_CARD             = 4,            // Card Number Query
    EM_ZZ_RECORD_TYPE_CONDITION        = 5,            // Condition Query
    EM_ZZ_RECORD_TYPE_JOIN             = 6,            // Combined Query
    EM_ZZ_RECORD_TYPE_CARD_PICTURE     = 8,            // Query Picture by Card No (HB-U, NVS, etc.)
    EM_ZZ_RECORD_TYPE_PICTURE          = 9,            // Query Picture (HB-U, NVS, etc.)
    EM_ZZ_RECORD_TYPE_FIELD            = 10,           // Query by Field
    EM_ZZ_RECORD_TYPE_INTELLI_VIDEO   = 11,           // Intelligent Record Query
    EM_ZZ_RECORD_TYPE_NET_DATA         = 15,           // Query Network Data (Internet Cafe, etc.)
    EM_ZZ_RECORD_TYPE_TRANS_DATA       = 16,           // Query Transparent Serial Data Record
    EM_ZZ_RECORD_TYPE_IMPORTANT        = 17,           // Query Important Records
    EM_ZZ_RECORD_TYPE_TALK_DATA        = 18,           // Query Audio Records
    EM_ZZ_RECORD_TYPE_POS				= 19,			// POS Records

    EM_ZZ_RECORD_TYPE_INVALID          = 256,          // Invalid Query Type
    
}EM_ZZ_QUERY_RECORD_TYPE;

// Realtime Monitor Callback Data Type
typedef enum tagEM_ZZ_REAL_DATA_TYPE
{
    EM_ZZ_REAL_DATA_TYPE_PRIVATE,       // Private Stream
    EM_ZZ_REAL_DATA_TYPE_GBPS,          // GB PS Stream
    EM_ZZ_REAL_DATA_TYPE_TS,            // TS Stream
    EM_ZZ_REAL_DATA_TYPE_MP4,           // MP4 File (Private stream data from callback, dwDataType is 0)
    EM_ZZ_REAL_DATA_TYPE_H264,          // Raw H264 Stream
}EM_ZZ_REAL_DATA_TYPE;

// Start Download by Data Type Input
typedef struct tagZZNET_IN_DOWNLOAD_BY_DATA_TYPE
{
    DWORD                       dwSize;                 // Struct Size
    int                         nChannelID;             // Channel ID
    EM_ZZ_QUERY_RECORD_TYPE        emRecordType;           // Record Type
    char*                       szSavedFileName;        // Save Path
    ZZNET_TIME                    stStartTime;            // Start Time
    ZZNET_TIME                    stStopTime;             // End Time
    ffTimeDownLoadPosCallBack    cbDownLoadPos;          // Progress Callback
    LDWORD                      dwPosUser;              // Progress User Data
    fDataCallBack               fDownLoadDataCallBack;  // Data Callback
    EM_ZZ_REAL_DATA_TYPE           emDataType;             // Callback Data Type
    LDWORD                      dwDataUser;             // Data Callback User Data
}ZZNET_IN_DOWNLOAD_BY_DATA_TYPE;

// Start Download by Data Type Output
typedef struct tagZZNET_OUT_DOWNLOAD_BY_DATA_TYPE
{
    DWORD               dwSize;                 // Struct Size  
}ZZNET_OUT_DOWNLOAD_BY_DATA_TYPE;

typedef struct
{
    unsigned short      left;                        // 0~8192
    unsigned short      right;                       // 0~8192
    unsigned short      top;                         // 0~8192
    unsigned short      bottom;                      // 0~8192
} ZZMotionDetectRect;

// Intelligent Playback Info
typedef struct 
{
    ZZMotionDetectRect    motion_rect;               // Motion Frame Search Area
    ZZNET_TIME            stime;                     // Playback Start Time
    ZZNET_TIME            etime;                     // Playback End Time
    BYTE                bStart;                    // Start/Stop Command: 1:Start, 2:Stop
    BYTE                reserved[116];
} ZZIntelligentSearchPlay, *LPZZIntelligentSearchPlay;

// Earliest Recording Time
typedef struct  
{
    int                 nChnCount;                  // Channel Count
    ZZNET_TIME          stuFurthestTime[16];        // Earliest Time, valid for first 0 to (nChnCount-1). All 0 if no record.
    DWORD               dwFurthestTimeAllSize;      // Used when channel count > 16. Size of memory pointed by pStuFurthestTimeAll.
    ZZNET_TIME*         pStuFurthestTimeAll;        // Used when channel count > 16. User allocated memory (Channel Count * sizeof(ZZNET_TIME)).
    BYTE                bReserved[376];             // Reserved
} ZZNET_FURTHEST_RECORD_TIME;



// Query Type, corresponds to ZZNETSDK_QueryRemotDevState
#define ZZ_DEVSTATE_ALARM_REMOTE          0x1000           // Get Remote Device External Alarm (Struct ALARM_REMOTE_ALARM_INFO)
#define ZZ_DEVSTATE_ALARM_FRONTDISCONNECT 0x1001           // Get Frontend IPC Disconnect Alarm (Struct ALARM_FRONTDISCONNET_INFO)


// Remote External Alarm Info
typedef struct __ZZALARM_REMOTE_ALARM_INFO
{
    DWORD      dwSize;
    int        nChannelID;                               // Channel ID, starts from 1
    int        nState;                                   // Alarm State, 0-Reset, 1-Set
}ZZALARM_REMOTE_ALARM_INFO;

// Frontend Disconnect Alarm Info
typedef struct __ZZALARM_FRONTDISCONNET_INFO
{
    DWORD              dwSize;                           // Struct Size
    int                nChannelID;                       // Channel ID
    int                nAction;                          // 0: Start 1: Stop
    ZZNET_TIME         stuTime;                          // Event Time
    char               szIpAddress[MAX_PATH];            // Frontend IPC IP
}ZZALARM_FRONTDISCONNET_INFO;


// PTZ Preset
typedef struct tagZZNET_PTZ_PRESET 
{
    int                     nIndex;                             // Index
    char                    szName[ZZ_PTZ_PRESET_NAME_LEN];     // Name
    char                    szReserve[64];                      // Reserved 64 bytes
} ZZNET_PTZ_PRESET;

// PTZ Preset List
typedef struct tagZZNET_PTZ_PRESET_LIST 
{
    DWORD                   dwSize;
    DWORD                   dwMaxPresetNum;                 // Max Preset Count
    DWORD                   dwRetPresetNum;                 // Returned Preset Count
    ZZNET_PTZ_PRESET        *pstuPtzPorsetList;             // Preset List (Allocated by caller based on max count), size sizeof(NET_PTZ_PRESET)*dwMaxPresetNum
} ZZNET_PTZ_PRESET_LIST;









///@brief Tour Preset Point Info
typedef struct tagZZNET_PTZ_PRESET_POINT
{
	int		nIndexNum;			/// Index Number, starts from 0
	int		nDwellTime;			/// Dwell Time, unit: seconds
	int		nRotationalSpeed;	/// Rotation Speed Level [Range: 1~10]
	BYTE	byReserved[44];		/// Reserved bytes
}ZZNET_PTZ_PRESET_POINT_INFO;

///@brief PTZ Tour Info
typedef struct tagZZNET_PTZ_TOURS_INFO
{
	int			nCruiseNum;								/// Tour Number, starts from 1
	char		szName[64];								/// Tour Name
	ZZNET_PTZ_PRESET_POINT_INFO	stuPresetPoint[64];		/// Preset Point Info
	int			nPresetPointNum;						/// Number of Preset Points
	BYTE		byReserved[256];						/// Reserved bytes
}ZZNET_PTZ_TOURS_INFO;

///@brief Get Tour List Info (ZZ_DEVSTATE_GET_PTZ_TOURS)
typedef struct tagZZNET_GET_PTZ_TOURS_INFO 
{
	DWORD						dwSize;						/// Struct Size
	int							nMaxToursNum;				/// Max Tour Groups Applied
	ZZNET_PTZ_TOURS_INFO		*pstuToursInfo;				/// Tour Group Info
	int							nRetToursNum;				/// Actual Returned Tour Group Count
}ZZNET_GET_PTZ_TOURS_INFO;


















// Audio In Denoise Info
typedef struct tagZZNET_AUDIOIN_DENOISE_INFO
{
	DWORD				dwSize;
	BOOL				bEnable;			// Denoise Enable
} ZZNET_AUDIOIN_DENOISE_INFO;

// Audio In Volume Info
typedef struct tagZZNET_AUDIOIN_VOLUME_INFO
{
	DWORD				dwSize;
	int					nVolume;			// Audio Input Volume
} ZZNET_AUDIOIN_VOLUME_INFO;

// Audio Out Volume Info
typedef struct tagZZNET_AUDIOOUT_VOLUME_INFO
{
	DWORD				dwSize;
	int					nVolume;			// Audio Output Volume
} ZZNET_AUDIOOUT_VOLUME_INFO;

// Channel Name Config
typedef struct tagZZNET_ENCODE_CHANNELTITLE_INFO
{
	DWORD				dwSize;
	char				szChannelName[ZZ_MAX_CHANNEL_NAME_LEN];				// Channel Name
} ZZNET_ENCODE_CHANNELTITLE_INFO;

// Audio Input Type
typedef enum tagZZNET_EM_AUDIOIN_SOURCE_TYPE
{
	ZZNET_EM_AUDIOIN_SOURCE_UNKNOW,			// Unknown
	ZZNET_EM_AUDIOIN_SOURCE_COAXIAL,			// Coaxial
	ZZNET_EM_AUDIOIN_SOURCE_BNC,				// BNC
	ZZNET_EM_AUDIOIN_SOURCE_HDCVI_BNC,		// HDCVI_BNC
	ZZNET_EM_AUDIOIN_SOURCE_LINEIN,			// LineIn
	ZZNET_EM_AUDIOIN_SOURCE_LINEIN1,			// LineIn1
	ZZNET_EM_AUDIOIN_SOURCE_LINEIN2,			// LineIn2
	ZZNET_EM_AUDIOIN_SOURCE_LINEIN3,			// LineIn3
	ZZNET_EM_AUDIOIN_SOURCE_MIC,				// Mic
	ZZNET_EM_AUDIOIN_SOURCE_MIC1,				// Mic1
	ZZNET_EM_AUDIOIN_SOURCE_MIC2,				// Mic2
	ZZNET_EM_AUDIOIN_SOURCE_MIC3,				// Mic3
	ZZNET_EM_AUDIOIN_SOURCE_MICOUT,			// MicOut
	ZZNET_EM_AUDIOIN_SOURCE_REMOTE,			// Remote
	ZZNET_EM_AUDIOIN_SOURCE_REMOTE1,			// Remote1
	ZZNET_EM_AUDIOIN_SOURCE_REMOTE2,			// Remote2
	ZZNET_EM_AUDIOIN_SOURCE_REMOTE3,			// Remote3
} ZZNET_EM_AUDIOIN_SOURCE_TYPE;

// Audio Input Type Config
typedef struct tagZZNET_ENCODE_AUDIO_SOURCE_INFO
{
	DWORD						dwSize;
	int 						nMaxAudioInSource;		// Max Source Count
	int							nRetAudioInSource;		// Actual Returned Source Count
	ZZNET_EM_AUDIOIN_SOURCE_TYPE	emAudioInSource[24];	// Source Type
} ZZNET_ENCODE_AUDIO_SOURCE_INFO;

// Overlay Type
typedef enum tagZZNET_EM_OSD_BLEND_TYPE
{
    ZZNET_EM_OSD_BLEND_TYPE_UNKNOWN,                                  // Unknown
    ZZNET_EM_OSD_BLEND_TYPE_MAIN,                                     // Overlay to Main Stream
    ZZNET_EM_OSD_BLEND_TYPE_EXTRA1,                                   // Overlay to Sub Stream 1
    ZZNET_EM_OSD_BLEND_TYPE_EXTRA2,                                   // Overlay to Sub Stream 2
    ZZNET_EM_OSD_BLEND_TYPE_EXTRA3,                                   // Overlay to Sub Stream 3
    ZZNET_EM_OSD_BLEND_TYPE_SNAPSHOT,                                 // Overlay to Snapshot
    ZZNET_EM_OSD_BLEND_TYPE_PREVIEW,                                  // Overlay to Preview Video
}ZZNET_EM_OSD_BLEND_TYPE;


// Encode Widget - Channel Title
typedef struct tagZZNET_OSD_CHANNEL_TITLE
{
	DWORD				        dwSize;
    ZZNET_EM_OSD_BLEND_TYPE     emOsdBlendType;                 // Overlay Type, set for both Get and Set
    BOOL                        bEncodeBlend;                   // Overlay Enable
	ZZNET_COLOR_RGBA		    stuFrontColor;					// Foreground Color
	ZZNET_COLOR_RGBA		    stuBackColor;					// Background Color
	ZZNET_RECT		    	    stuRect;						// Region, Coord [0~8191], Use only left/top, point (left,top) should equal (right,bottom)
} ZZNET_OSD_CHANNEL_TITLE;

// Encode Widget - Time Title
typedef struct tagZZNET_OSD_TIME_TITLE
{
	DWORD				        dwSize;
    ZZNET_EM_OSD_BLEND_TYPE     emOsdBlendType;             // Overlay Type, set for both Get and Set
    BOOL                        bEncodeBlend;               // Overlay Enable
	ZZNET_COLOR_RGBA		    stuFrontColor;				// Foreground Color
	ZZNET_COLOR_RGBA		    stuBackColor;				// Background Color
	ZZNET_RECT 			        stuRect;					// Region, Coord [0~8191], Use only left/top, point (left,top) should equal (right,bottom)
	BOOL 				        bShowWeek;					// Show Week
} ZZNET_OSD_TIME_TITLE;

///@brief Overlay Title Usage
typedef enum tagZZNET_EM_TITLE_TYPE
{
	ZZNET_EM_TITLE_UNKNOWN,              /// Unknown
	ZZNET_EM_TITLE_RTINFO,               /// Realtime Burning Info
	ZZNET_EM_TITLE_CUSTOM,               /// Custom / Temp & Humidity
	ZZNET_EM_TITLE_TITLE,                /// Header Info
	ZZNET_EM_TITLE_CHECK,                /// Verification Code
	ZZNET_EM_TITLE_SPEEDOMETER,          /// Speedometer
	ZZNET_EM_TITLE_GEOGRAPHY,            /// Geographic Info
	ZZNET_EM_TITLE_ATMCARDINFP,          /// ATM Card Info
	ZZNET_EM_TITLE_CAMERAID,             /// Camera ID
}ZZNET_EM_TITLE_TYPE;

// Title Text Align
typedef enum tagEM_ZZ_TITLE_TEXT_ALIGNTYPE
{
    EM_ZZ_TEXT_ALIGNTYPE_INVALID,                              // Invalid
    EM_ZZ_TEXT_ALIGNTYPE_LEFT,                                 // Left Align
    EM_ZZ_TEXT_ALIGNTYPE_XCENTER,                              // X Center Align
    EM_ZZ_TEXT_ALIGNTYPE_YCENTER,                              // Y Center Align
    EM_ZZ_TEXT_ALIGNTYPE_CENTER,                               // Center Align
    EM_ZZ_TEXT_ALIGNTYPE_RIGHT,                                // Right Align
    EM_ZZ_TEXT_ALIGNTYPE_TOP,                                  // Top Align
    EM_ZZ_TEXT_ALIGNTYPE_BOTTOM,                               // Bottom Align
    EM_ZZ_TEXT_ALIGNTYPE_LEFTTOP,                              // Left Top Align
    EM_ZZ_TEXT_ALIGNTYPE_CHANGELINE,                           // New Line Align
}EM_ZZ_TITLE_TEXT_ALIGNTYPE;

// Encode Widget - Custom Title Info
typedef struct tagZZNET_CUSTOM_TITLE_INFO
{
    BOOL                        bEncodeBlend;                   // Overlay Enable
	ZZNET_COLOR_RGBA		    stuFrontColor;					// Foreground Color
	ZZNET_COLOR_RGBA		    stuBackColor;					// Background Color
	ZZNET_RECT			        stuRect;						// Region, Coord [0~8191], Use only left/top, point (left,top) should equal (right,bottom)
	char				        szText[ZZ_CUSTOM_TITLE_LEN];		// Title Content
    ZZNET_EM_TITLE_TYPE         emTitleType;                    /// Title Usage
	EM_ZZ_TITLE_TEXT_ALIGNTYPE	emTextAlign;					/// Text Alignment
	BYTE                        byReserved[512];                // Reserved
} ZZNET_CUSTOM_TITLE_INFO;

// Encode Widget - Custom Title
typedef struct tagZZNET_OSD_CUSTOM_TITLE
{
	DWORD					    dwSize;
	ZZNET_EM_OSD_BLEND_TYPE     emOsdBlendType;                         // Overlay Type, set for both Get and Set
	int						    nCustomTitleNum;						// Number of Custom Titles
	ZZNET_CUSTOM_TITLE_INFO	    stuCustomTitle[ZZ_MAX_CUSTOM_TITLE_NUM];	// Custom Titles
} ZZNET_OSD_CUSTOM_TITLE;



// Custom Title Text Alignment
typedef struct tagZZNET_OSD_CUSTOM_TITLE_TEXT_ALIGN
{
	DWORD					    dwSize;
	int						    nCustomTitleNum;						// Number of Custom Titles
    EM_ZZ_TITLE_TEXT_ALIGNTYPE  emTextAlign[ZZ_MAX_CUSTOM_TITLE_NUM];      // Alignment for each title
}ZZNET_OSD_CUSTOM_TITLE_TEXT_ALIGN;

// Main (Sub) Stream Video SVC Config (f6)
typedef struct tagZZNET_ENCODE_VIDEO_SVC_INFO
{
	DWORD						    dwSize;
	ZZNET_EM_FORMAT_TYPE			emFormatType;				// Stream type, set for both Get and Set
	int							    nSVC;						// SVC-T Layers
} ZZNET_ENCODE_VIDEO_SVC_INFO;

// Main (Sub) Stream Video Profile Config (f6/bin)
typedef struct tagZZNET_ENCODE_VIDEO_PROFILE_INFO
{
	DWORD						    dwSize;
	ZZNET_EM_FORMAT_TYPE			emFormatType;				// Stream type, set for both Get and Set
	ZZNET_EM_H264_PROFILE_RANK 	    emProfile;                	// H.264 Profile Rank
} ZZNET_ENCODE_VIDEO_PROFILE_INFO;


// Snapshot Type
typedef enum tagZZNET_EM_SNAP_TYPE
{
	EM_ZZ_SNAP_UNKNOWN,			    // Unknown
	EM_ZZ_SNAP_NORMAL,				// Normal Snapshot
	EM_ZZ_SNAP_MOVEEXAMINE,		    // Motion Detection Snapshot
	EM_ZZ_SNAP_ALARM,				// Alarm Snapshot
} ZZNET_EM_SNAP_TYPE;

// Snapshot Config
typedef struct tagZZNET_ENCODE_SNAP_INFO
{
	DWORD						dwSize;
	ZZNET_EM_SNAP_TYPE			emSnapType;					// Snapshot Type
	BOOL						bSnapEnable;				// Timing Snapshot Enable
	ZZNET_EM_VIDEO_COMPRESSION 	emCompression;				// Compression Format
	int							nWidth;						// Width
	int							nHeight;					// Height
	float						nFrameRate;					// Frame Rate
	int 						nQualityRange;				// Quality Range
	ZZNET_EM_IMAGE_QUALITY		emImageQuality;				// Image Quality
} ZZNET_ENCODE_SNAP_INFO;

// Snapshot Time Config
typedef struct tagZZNET_ENCODE_SNAP_TIME_INFO
{
	DWORD				dwSize;
	short           	shPicTimeInterval;             	// Timing snapshot interval (seconds), max 30 mins                           
	BYTE            	bPicIntervalHour;              	// Timing snapshot interval (hours)
	DWORD           	dwTrigPicIntervalSecond;       	// Interval after alarm trigger (seconds)
} ZZNET_ENCODE_SNAP_TIME_INFO;

// Config Type per Channel
typedef enum tagZZNET_EM_CONFIG_TYPE
{
	ZZNET_EM_CONFIG_DAYTIME,			// Daytime
	ZZNET_EM_CONFIG_NIGHT,			// Night
	ZZNET_EM_CONFIG_NORMAL,			// Normal
} ZZNET_EM_CONFIG_TYPE;

// sharpness mode
typedef enum tagZZNET_EM_SHARPNESS_MODE
{
	ZZNET_EM_SHARPNESS_AUTO,			// Auto
	ZZNET_EM_SHARPNESS_MANAUL,			// Manual
}ZZNET_EM_SHARPNESS_MODE;


// Sharpness Config
typedef struct tagZZNET_VIDEOIN_SHARPNESS_INFO
{
	DWORD							dwSize;
	ZZNET_EM_CONFIG_TYPE			emCfgType;					// Config Type, specify for both Get and Set
	ZZNET_EM_SHARPNESS_MODE			emSharpnessMode;			// Sharpness Mode
	int								nSharpness;					// Sharpness Value 0-100, valid when Manual
	int								nLevel;						// Restrain Level, 0-100, 0 means no restrain
} ZZNET_VIDEOIN_SHARPNESS_INFO;


// color style
typedef enum tagEM_ZZ_COLOR_STYLE_TYPE
{
	EM_ZZ_COLOR_STYLE_UNKNOWN,			// unknown
	EM_ZZ_COLOR_STYLE_GENTLE,			// gentle
	EM_ZZ_COLOR_STYLE_STANDARD,		// standard
	EM_ZZ_COLOR_STYLE_FLAMBOYANT,		// plamboyant
} EM_ZZ_COLOR_STYLE_TYPE;

// the color config of video input
typedef struct tagZZNET_VIDEOIN_COLOR_INFO
{
    DWORD				    dwSize;
	ZZNET_EM_CONFIG_TYPE	emCfgType;				// Config Type, specify for both Get and Set
	int					    nBrightness;			// Brightness 0-100
	int					    nContrast;				// Contrast 0-100
	int					    nSaturation;			// Saturation 0-100
	int					    nGamma;					// Gamma 0-100
	EM_ZZ_COLOR_STYLE_TYPE	emColorStyle;			// Color Style
    int					    nHue;					// Hue 0-100
	int                     nChromaSuppress;        // Chroma Suppress Level 0-100
	ZZ_TSECT                stuTimeSection;         // Corresponding Time Section
} ZZNET_VIDEOIN_COLOR_INFO;

// image options config of video input
typedef struct tagZZNET_VIDEOIN_IMAGE_INFO
{
	DWORD				    dwSize;
	ZZNET_EM_CONFIG_TYPE	emCfgType;				// Config Type, specify for both Get and Set
	BOOL				    bMirror;				// Mirror Enable
	BOOL				    bFlip;					// Flip Enable
	int					    nRotate90;				// 0-None, 1-CW 90, 2-CCW 90
} ZZNET_VIDEOIN_IMAGE_INFO;

// Stabilization Mode
typedef enum tagZZNET_EM_STABLE_TYPE
{
	ZZNET_EM_STABLE_OFF,				// Off
	ZZNET_EM_STABLE_ELEC,				// Electronic
	ZZNET_EM_STABLE_LIGHT,			    // Optical
	ZZNET_EM_STABLE_CONTORL = 4,		// Control (Plugin)
} ZZNET_EM_STABLE_TYPE;

// Stabilization Config
typedef struct tagZZNET_VIDEOIN_STABLE_INFO
{
	DWORD				    dwSize;
	ZZNET_EM_CONFIG_TYPE	emCfgType;			// Config Type, specify for both Get and Set
	ZZNET_EM_STABLE_TYPE	emStableType;		// Stabilization Config
} ZZNET_VIDEOIN_STABLE_INFO;

// Exposure Mode
typedef enum tagZZNET_EM_EXPOSURE_MODE
{
	ZZNET_EM_EXPOSURE_AUTO,					// Default Auto
	ZZNET_EM_EXPOSURE_LOWNICE,				// Low Noise
	ZZNET_EM_EXPOSURE_ANTISHADOW,				// Anti-Shadow
	ZZNET_EM_EXPOSURE_MANUALRANGE	= 4,		// Manual Range
	ZZNET_EM_EXPOSURE_APERTUREFIRST,			// Aperture Priority
	ZZNET_EM_EXPOSURE_MANUALFIXATION,			// Manual Fix
	ZZNET_EM_EXPOSURE_GIANFIRST,				// Gain Priority
	ZZNET_EM_EXPOSURE_SHUTTERFIRST,			// Shutter Priority
	ZZNET_EM_EXPOSURE_FLASHMATCH,				// Flash Match
} ZZNET_EM_EXPOSURE_MODE;

///@brief Double Shutter Support Type
typedef enum tagEM_ZZ_DOUBLE_EXPOSURE_TYPE
{
	EM_ZZ_DOUBLE_EXPOSURE_UNKNOWN = -1,				/// Unknown
	EM_ZZ_DOUBLE_EXPOSURE_NOT_SUPPORT,				    /// Not Supported
	EM_ZZ_DOUBLE_EXPOSURE_SUPPORT_FULL_FRAM,			/// Supports Full Frame Double Shutter (Image/Video only differ in shutter params)
	EM_ZZ_DOUBLE_EXPOSURE_SUPPORT_HALF_FRAM,		    /// Supports Half Frame Double Shutter (Image/Video differ in shutter & white balance)
	EM_ZZ_DOUBLE_EXPOSURE_ALL,		                    /// Supports Both
} EM_ZZ_DOUBLE_EXPOSURE_TYPE;

// General Exposure Config
typedef struct tagZZNET_VIDEOIN_EXPOSURE_NORMAL_INFO
{
	DWORD					dwSize;
	ZZNET_EM_CONFIG_TYPE	emCfgType;				// Config Type, specify for both Get and Set
	ZZNET_EM_EXPOSURE_MODE	emExposureMode;			// Exposure Mode
	int						nAntiFlicker;			// Anti-Flicker 0-Outdoor 1-50Hz 2-60Hz
	int						nCompensation;			// Exposure Compensation 0-100
	int						nGain;					// Gain
	int						nGainMin;				// Gain Min 0-100
	int						nGainMax;				// Gain Max 0-100
	int						nExposureIris;			// Iris Value 0-100, valid in Aperture Priority
	double					dbExposureValue1;		// Auto Exposure Min Time or Manual Exposure Time (ms), 0.1ms~80ms
	double					dbExposureValue2;		// Auto Exposure Max Time (ms), 0.1ms~80ms, must be >= ExposureValue1

    BOOL                    bIrisAuto;              /// Auto Iris Enable
	EM_ZZ_DOUBLE_EXPOSURE_TYPE emDoubleExposure;       /// Double Shutter Support Type
} ZZNET_VIDEOIN_EXPOSURE_NORMAL_INFO;

// Shutter Exposure Config
typedef struct tagZZNET_VIDEOIN_EXPOSURE_SHUTTER_INFO
{
	DWORD					dwSize;
	BOOL					bAutoSyncPhase;			// Auto Sync Phase Enable
	float					fShutter;				// Shutter Value, valid when AutoSyncPhase is true, unit ms, range 0.1~80,
													// must be within [ExposureValue1, ExposureValue2] of ZZNET_VIDEOIN_EXPOSURE_NORMAL_INFO
	int						nPhase;					// Phase Value 0~360
} ZZNET_VIDEOIN_EXPOSURE_SHUTTER_INFO;

// 3D Denoise Control Type
typedef enum tagZZNET_EM_3D_TYPE
{
	ZZNET_EM_3D_UNKONW,		    // Unknown
	ZZNET_EM_3D_OFF,			// Off
	ZZNET_EM_3D_AUTO,			// Auto
} ZZNET_EM_3D_TYPE;

///@brief 3D Denoise Manual Control Info
typedef struct tagZZNET_3D_DENOISE_MANUL_TYPE_INFO
{
	int						nTnfLevel;				/// Temporal Level, 0-255, main 3D denoise focus
	int						nSnfLevel;				/// Spatial Level, 0-255, optional spatial processing
	char					szReserved[128];		/// Reserved
}ZZNET_3D_DENOISE_MANUL_TYPE_INFO;

// 3D Denoise Config
typedef struct tagZZNET_VIDEOIN_3D_DENOISE_INFO
{
	DWORD							    dwSize;
	ZZNET_EM_CONFIG_TYPE				emCfgType;					// Config Type, specify for both Get and Set
	ZZNET_EM_3D_TYPE					em3DType;					// Control Type
	int								    nAutoLevel;					// Denoise Level, valid when em3DType is AUTO
    ZZNET_3D_DENOISE_MANUL_TYPE_INFO  stu3DManulType;             /// Manual Info
} ZZNET_VIDEOIN_3D_DENOISE_INFO;

// Backlight Mode
typedef enum tagZZNET_EM_BACK_MODE
{
	ZZNET_EM_BACKLIGHT_MODE_UNKNOW,					// Unknown
	ZZNET_EM_BACKLIGHT_MODE_OFF,						// Off
	ZZNET_EM_BACKLIGHT_MODE_BACKLIGHT,				// BLC
	ZZNET_EM_BACKLIGHT_MODE_WIDEDYNAMIC,				// WDR
	ZZNET_EM_BACKLIGHT_MODE_GLAREINHIBITION,			// HLC (Glare Inhibition)
	ZZNET_EM_BACKLIGHT_MODE_SSA,						// SSA (Scene Self Adaptation)
} ZZNET_EM_BACK_MODE;

// BLC Mode
typedef enum tagZZNET_EM_BLACKLIGHT_MODE
{
	ZZNET_EM_BLACKLIGHT_UNKNOW,						// Unknown
	ZZNET_EM_BLACKLIGHT_DEFAULT,						// Default
	ZZNET_EM_BLACKLIGHT_REGION,						// Custom Region
} ZZNET_EM_BLACKLIGHT_MODE;

// Backlight Config
typedef struct tagZZNET_VIDEOIN_BACKLIGHT_INFO
{
	DWORD					    dwSize;
	ZZNET_EM_CONFIG_TYPE		emCfgType;				// Config Type, specify for both Get and Set
	ZZNET_EM_BACK_MODE		    emBlackMode;			// Backlight Mode
	ZZNET_EM_BLACKLIGHT_MODE	emBlackLightMode;		// BLC Mode
	ZZNET_RECT				    stuBacklightRegion;     // BLC Region   
	int						    nWideDynamicRange;		// WDR Value, valid for WDR mode
	int						    nGlareInhibition;		// HLC Value 0-100, valid for Glare Inhibition mode
} ZZNET_VIDEOIN_BACKLIGHT_INFO;

// White Balance Mode
typedef enum tagZZNET_EM_WHITEBALANCE_TYPE
{
	ZZNET_EM_WHITEBALANCE_UNKNOW,					// Unknown
	ZZNET_EM_WHITEBALANCE_DISABLE,				    // Disable
	ZZNET_EM_WHITEBALANCE_AUTO,					    // Auto
	ZZNET_EM_WHITEBALANCE_SUNNY,					// Sunny, ~6500K
	ZZNET_EM_WHITEBALANCE_CLOUDY,					// Cloudy, ~7500K
	ZZNET_EM_WHITEBALANCE_HOME,					    // Home, ~5000K
	ZZNET_EM_WHITEBALANCE_OFFICE,					// Office, ~4400K 
	ZZNET_EM_WHITEBALANCE_NIGHT,					// Night, ~2800K
	ZZNET_EM_WHITEBALANCE_CUSTOM,					// Custom
	ZZNET_EM_WHITEBALANCE_HIGHCOLORTEMP,			// High Color Temp Range
	ZZNET_EM_WHITEBALANCE_LOWCOLORTEMP,			    // Low Color Temp Range
	ZZNET_EM_WHITEBALANCE_AUTOCOLORTEMP,			// Auto Color Temp Range
	ZZNET_EM_WHITEBALANCE_CUSTOMCOLORTEMP,		    // Custom Color Temp Level
	ZZNET_EM_WHITEBALANCE_INDOOR,					// Indoor
	ZZNET_EM_WHITEBALANCE_OUTDOOR,				    // Outdoor, focuses on green grass
	ZZNET_EM_WHITEBALANCE_ATW,					    // ATW
	ZZNET_EM_WHITEBALANCE_MANUAL,					// Manual
	ZZNET_EM_WHITEBALANCE_AUTOOUTDOOR,			    // AutoOutdoor
	ZZNET_EM_WHITEBALANCE_SODIUMAUTO,				// SodiumAuto
	ZZNET_EM_WHITEBALANCE_SODIUM,					// Sodium, ~2000K
	ZZNET_EM_WHITEBALANCE_MANUALDATUM,			    // ManualDatum (Single Region Custom)
	ZZNET_EM_WHITEBALANCE_PARTWHITEBALANCE,		    // PartWhiteBalance (Multi Region Custom)
	ZZNET_EM_WHITEBALANCE_NATURAL,				    // Natural, 2000K-12000K
	ZZNET_EM_WHITEBALANCE_STREETLAMP,				// StreetLamp, 1000K-5000K
} ZZNET_EM_WHITEBALANCE_TYPE;

// White Balance Config
typedef struct tagZZNET_VIDEOIN_WHITEBALANCE_INFO
{
	DWORD						dwSize;
	ZZNET_EM_CONFIG_TYPE		emCfgType;					// Config Type, specify for both Get and Set
	ZZNET_EM_WHITEBALANCE_TYPE	emWhiteBalanceType;			// WB Mode
	int							nGainRed;					// Red Gain 0-100, valid for Custom
	int							nGainBlue;					// Blue Gain 0-100, valid for Custom
	int							nGainGreen;					// Green Gain 0-100, valid for Custom
	int							nColorTemperature;			// Color Temp Level, valid for CustomColorTemperature
} ZZNET_VIDEOIN_WHITEBALANCE_INFO;

// Day/Night Switch Mode
typedef enum tagZZNET_EM_DAYNIGHT_TYPE
{
	ZZNET_EM_DAYNIGHT_COLOR,				// Always Color
	ZZNET_EM_DAYNIGHT_AUTO,				// Auto based on brightness
	ZZNET_EM_DAYNIGHT_WHITEBLACK,			// Always B&W
} ZZNET_EM_DAYNIGHT_TYPE;

// Day/Night Config
typedef struct tagZZNET_VIDEOIN_DAYNIGHT_INFO
{
	DWORD						dwSize;
	ZZNET_EM_CONFIG_TYPE		emCfgType;					// Config Type, specify for both Get and Set
	ZZNET_EM_DAYNIGHT_TYPE		emDayNightType;				// Mode
	int							nDayNightSensitivity;		// Sensitivity 1-3
	int							nDayNightSwitchDelay;		// Delay (seconds) 2-10
} ZZNET_VIDEOIN_DAYNIGHT_INFO;

// Defog Mode
typedef enum tagZZNET_EM_DEFOG_MODE
{
	ZZNET_EM_DEFOG_UNKNOW,			// Unknown
	ZZNET_EM_DEFOG_OFF,				// Off
	ZZNET_EM_DEFOG_AUTO,				// Auto
	ZZNET_EM_DEFOG_MANAUL,			// Manual
}ZZNET_EM_DEFOG_MODE;

// Intensity Mode
typedef enum tagZZNET_EM_INTENSITY_MODE
{
	ZZNET_EM_INTENSITY_MODE_UNKNOW,// Unknown
	ZZNET_EM_INTENSITY_MODE_AUTO,  // Auto
	ZZNET_EM_INTENSITY_MODE_MANUAL, // Manual
}ZZNET_EM_INTENSITY_MODE;


// Defog Config
typedef struct tagZZNET_VIDEOIN_DEFOG_INFO
{
	DWORD							dwSize;
	ZZNET_EM_CONFIG_TYPE			emCfgType;					// Config Type, specify for both Get and Set
	ZZNET_EM_DEFOG_MODE				emDefogMode;				// Mode
	int								nIntensity;					// Intensity 0-100
	ZZNET_EM_INTENSITY_MODE			emIntensityMode;			// Intensity Mode
	int								nLightIntensityLevel;		// Light Intensity Level (0-15)
	BOOL							bCamDefogEnable;			// Optical Defog Enable (TRUE/FALSE)
} ZZNET_VIDEOIN_DEFOG_INFO;






// ZZNETSDK_DownloadRemoteFile Input Param (File Download)
typedef struct tagZZ_IN_DOWNLOAD_REMOTE_FILE
{
    DWORD               dwSize;
    const char*         pszFileName;                    // File name to download
    const char*         pszFileDst;                     // Destination path
} ZZ_IN_DOWNLOAD_REMOTE_FILE;

// ZZNETSDK_DownloadRemoteFile Output Param (File Download)
typedef struct tagZZ_OUT_DOWNLOAD_REMOTE_FILE
{
    DWORD               dwSize;
} ZZ_OUT_DOWNLOAD_REMOTE_FILE;



///@brief PTZ
typedef struct tagZZNET_CFG_PATTERN_PTZ_INFO
{
	BOOL							bEnable;						/// Pattern Enable TRUE/FALSE
	char							szName[32];						/// Pattern Name (Unique)
	BYTE							byReserved[1020];				/// Reserved
}ZZNET_CFG_PATTERN_PTZ_INFO;

///@brief Auto Pattern Setting
typedef struct tagZZNET_CFG_AUTO_PATTERN_INFO
{
	DWORD						dwSize;								/// Struct Size
	ZZNET_CFG_PATTERN_PTZ_INFO	stuPatternPtzInfo[32];				/// PTZ Info
	int							nPatternPtzInfo;					/// PTZ Count
}ZZNET_CFG_AUTO_PATTERN_INFO;



///@brief Config Operation Type
typedef enum tagZZNET_EM_CFG_OPERATE_TYPE
{
    ZZNET_EM_CFG_SNAP_MODE,                   // Snapshot Mode Config, struct NET_SNAP_MODE
    ZZNET_EM_CFG_DEV_CAR_COACH,               // Railway Record Config, struct NET_DEV_CAR_COACH_INFO
	ZZNET_EM_CFG_YUEQING_SUPPLYLIGHTING,		// Yueqing External Lighting, struct NET_YUEQING_SUPPLYLIGHTING_INFO
	ZZNET_EM_CFG_MEDIA_GLOBAL,                // Media Global Config, struct NET_MEDIA_GLOBAL_INFO
	ZZNET_EM_CFG_PARKINGSPACECELL_STATUS,		// Parking Space Status (Private/Normal), struct NET_PARKINGSPACECELL_STATUS_INFO
	ZZNET_EM_CFG_PARKINGSPACELIGHT_STATE,		// Parking Space Light State, struct NET_PARKINGSPACELIGHT_STATE_INFO
	ZZNET_EM_CFG_COAXIAL_LIGHT,				// Coaxial Light Video Channel, struct NET_CFG_COAXIAL_LIGHT_INFO
	ZZNET_EM_CFG_DOWNLOAD_ENCRYPT,            // Record Download Encryption, struct NET_DOWNLOAD_ENCRYPT_INFO
	ZZNET_EM_CFG_RECORD_ENCRYPT,				// Auto Record Backup Config, struct NET_RECORD_ENCRYPT_INFO
	ZZNET_EM_CFG_MEDIA_ENCRYPT,				// Media Data Encryption, struct NET_MEDIA_ENCRYPT_INFO
	
	/*********OSD Related Configs*************************************************************************************************/
	ZZNET_EM_CFG_CHANNELTITLE = 1000,         // Channel Title OSD, struct ZZNET_OSD_CHANNEL_TITLE, emOsdBlendType required
	ZZNET_EM_CFG_TIMETITLE,               	// Time Title OSD, struct ZZNET_OSD_TIME_TITLE, emOsdBlendType required
	ZZNET_EM_CFG_CUSTOMTITLE,             	// Custom Title OSD, struct ZZNET_OSD_CUSTOM_TITLE, emOsdBlendType required
	ZZNET_EM_CFG_CUSTOMTITLETEXTALIGN,    	// Custom Title Text Align, struct ZZNET_OSD_CUSTOM_TITLE_TEXT_ALIGN
	ZZNET_EM_CFG_OSDCOMMINFO,             	// Common OSD Config, struct NET_OSD_COMM_INFO
	ZZNET_EM_CFG_OSD_PTZZOOM,					// PTZ Zoom OSD, struct NET_OSD_PTZZOOM_INFO
	ZZNET_EM_CFG_GPSTITLE,					// GPS Title OSD, struct NET_OSD_GPS_TITLE
	ZZNET_EM_CFG_OSD_NUMBERSTATPLAN,			// People Counting Plan OSD, for Dome supporting NumberStatPlan algo, struct NET_OSD_NUMBER_STATPLAN
    ZZNET_EM_CFG_GPSSTARNUM_OSD,              // GPS Satellite Count OSD, Mobile custom requirement, struct NET_CFG_GPSSTARNUM_OSD_INFO

	/*********Encode Related Configs*************************************************************************************************/
	ZZNET_EM_CFG_ENCODE_VIDEO = 1100,			// Video Encode Format, struct ZZNET_ENCODE_VIDEO_INFO
	ZZNET_EM_CFG_ENCODE_VIDEO_PACK,			// Video Encode Pack Mode, struct NET_ENCODE_VIDEO_PACK_INFO
	ZZNET_EM_CFG_ENCODE_VIDEO_SVC,			// Video Encode SVC, struct NET_ENCODE_VIDEO_SVC_INFO
	ZZNET_EM_CFG_ENCODE_VIDEO_PROFILE,		// Video Encode Profile, struct ZZNET_ENCODE_VIDEO_PROFILE_INFO
	ZZNET_EM_CFG_ENCODE_AUDIO_COMPRESSION,	// Audio Compression Format, struct NET_ENCODE_AUDIO_COMPRESSION_INFO
	ZZNET_EM_CFG_ENCODE_AUDIO_INFO,			// Audio Encode Format, struct NET_ENCODE_AUDIO_INFO
	ZZNET_EM_CFG_ENCODE_SNAP_INFO,			// Snapshot Config, struct ZZNET_ENCODE_SNAP_INFO
	ZZNET_EM_CFG_ENCODE_SNAPTIME, 			// Snapshot Time Config, struct ZZNET_ENCODE_SNAP_TIME_INFO
	ZZNET_EM_CFG_ENCODE_CHANNELTITLE,			// Channel Name Config, struct ZZNET_ENCODE_CHANNELTITLE_INFO
		
	/**********Audio Related Configs***************************************************************************************************/
	ZZNET_EM_CFG_AUDIOIN_SOURCE = 1200,		// Audio Input Source, struct ZZNET_ENCODE_AUDIO_SOURCE_INFO
	ZZNET_EM_CFG_AUDIOIN_DENOISE,				// Audio Denoise, struct ZZNET_AUDIOIN_DENOISE_INFO
	ZZNET_EM_CFG_AUDIOIN_VOLUME,				// Audio Input Volume, struct ZZNET_AUDIOIN_VOLUME_INFO
	ZZNET_EM_CFG_AUDIOOUT_VOLUME,				// Audio Output Volume, struct ZZNET_AUDIOOUT_VOLUME_INFO
	
	/**********Video Input Related Configs***********************************************************************************************/
	ZZNET_EM_CFG_VIDEOIN_SWITCHMODE = 1300,	// Switch Mode, struct NET_VIDEOIN_SWITCH_MODE_INFO
	ZZNET_EM_CFG_VIDEOIN_COLOR,				// Color Config, struct ZZNET_VIDEOIN_COLOR_INFO			
	ZZNET_EM_CFG_VIDEOIN_IMAGE_OPT,			// Image Options, struct ZZNET_VIDEOIN_IMAGE_INFO
	ZZNET_EM_CFG_VIDEOIN_STABLE,				// Stabilization, struct ZZNET_VIDEOIN_STABLE_INFO
	ZZNET_EM_CFG_VIDEOIN_IRISAUTO,			// Auto Iris, struct NET_VIDEOIN_IRISAUTO_INFO
	ZZNET_EM_CFG_VIDEOIN_IMAGEENHANCEMENT,	// Image Enhancement, struct NET_VIDEOIN_IMAGEENHANCEMENT_INFO
	ZZNET_EM_CFG_VIDEOIN_EXPOSURE_NORMAL,		// General Exposure, struct ZZNET_VIDEOIN_EXPOSURE_NORMAL_INFO
	ZZNET_EM_CFG_VIDEOIN_EXPOSURE_OTHER,		// Other Exposure, struct NET_VIDEOIN_EXPOSURE_OTHER_INFO
	ZZNET_EM_CFG_VIDEOIN_EXPOSURE_SHUTTER,	// Shutter Exposure, struct ZZNET_VIDEOIN_EXPOSURE_SHUTTER_INFO
	ZZNET_EM_CFG_VIDEOIN_BACKLIGHT,			// Backlight, struct ZZNET_VIDEOIN_BACKLIGHT_INFO
	ZZNET_EM_CFG_VIDEOIN_INTENSITY,			// SSA Intensity, struct NET_VIDEOIN_INTENSITY_INFO
	ZZNET_EM_CFG_VIDEOIN_LIGHTING,			// Fill Light, struct NET_VIDEOIN_LIGHTING_INFO
	ZZNET_EM_CFG_VIDEOIN_DEFOG,				// Defog, struct ZZNET_VIDEOIN_DEFOG_INFO
	ZZNET_EM_CFG_VIDEOIN_FOCUSMODE,			// Focus Mode, struct NET_VIDEOIN_FOCUSMODE_INFO
	ZZNET_EM_CFG_VIDEOIN_FOCUSVALUE,			// Focus Value, struct NET_VIDEOIN_FOCUSVALUE_INFO
	ZZNET_EM_CFG_VIDEOIN_WHITEBALANCE,		// White Balance, struct ZZNET_VIDEOIN_WHITEBALANCE_INFO
	ZZNET_EM_CFG_VIDEOIN_DAYNIGHT,			// Day/Night, struct ZZNET_VIDEOIN_DAYNIGHT_INFO
	ZZNET_EM_CFG_VIDEOIN_DAYNIGHT_ICR,		// ICR Switch, struct NET_VIDEOIN_DAYNIGHT_ICR_INFO
	ZZNET_EM_CFG_VIDEOIN_SHARPNESS,			// Sharpness, struct ZZNET_VIDEOIN_SHARPNESS_INFO
	ZZNET_EM_CFG_VIDEOIN_COMM_DENOISE,		// Common Denoise, struct NET_VIDEOIN_DENOISE_INFO
	ZZNET_EM_CFG_VIDEOIN_3D_DENOISE,			// 3D Denoise, struct NET_VIDEOIN_3D_DENOISE_INFO

	/***********Court Related Configs*****************************************************************************************/
	ZZNET_EM_CFG_ENCODE_PLAN = 1400,			// Burn Disc Encode Plan, struct NET_ENCODE_PLAN_INFO
	ZZNET_EM_CFG_COMPOSE_CHANNEL,				// Compose Channel, struct NET_COMPOSE_CHANNEL_INFO
	
	/**********Alarm Gateway Related Configs**************************************************************************************/
    ZZNET_EM_CFG_ALARM_SOUND = 1500,           // Alarm Gateway Voice, struct NET_ALARM_SOUND_INFO 

    /**********Network App Related Configs**************************************************************************************/
    ZZNET_EM_CFG_ACCESS_POINT = 1600,         // WiFi Hotspot Config, struct NET_NETAPP_ACCESSPOINT
	ZZNET_EM_CFG_LDAP,						// LDAP, struct NET_NETAPP_LDAP
	ZZNET_EM_CFG_SYSLOG,						// Syslog, struct NET_NETAPP_SYSLOG

	/**************Security Baseline Requirements**************************************************************************************/
	ZZNET_EM_CFG_NAS			= 1700,			// NAS Config, struct NET_NAS_INFO   
	ZZNET_EM_CFG_PPPOE,						// PPPOE Config, struct NET_PPPOE_INFO   
	ZZNET_EM_CFG_EMAIL,						// Email Config, struct NET_EAMIL_INFO  
	ZZNET_EM_CFG_DDNS,						// DDNS Config, struct NET_DDNS_INFO  

	/**************SCADA Config Requirements**************************************************************************************/
	ZZNET_EM_CFG_SCADA_PROTOCOLS_MANAGER  = 1800,   // Protocol Manager, struct NET_SCADA_PROTOCOLS_MANAGER
	ZZNET_EM_CFG_SCADA_DEVICEINFO_CFG,			  // Device Info Config, struct NET_SCADA_DEVICEINFO_CFG

	/**************NetApp Config Requirements*************************************************************************************/
	ZZNET_EM_CFG_NETAPP_LINK_LAYER_VPN = 1900,	  // Link Layer VPN, struct NET_NETAPP_LINK_LAYER_VPN_CFG

	/**************China Tower Platform Access***********************************************************************************/
	ZZNET_EM_CFG_VSP_CHINA_TOWER = 2000,			  // Anhui Overload Control Platform Access, struct NET_VSP_CHINA_TOWER 
	
	/**********Intelligent Related Configs*******************************************************************************************/
	ZZNET_EM_CFG_STEREO_CALIBRATE = 2100,		// Stereo Calibration Result, struct NET_STEREO_CALIBRATE_INFO
	ZZNET_EM_CFG_STEREO_CALIBRATEMATRIX_MULTISENSOR,		 // Multi-sensor Calibration Matrix, struct NET_MULTI_SENSOR_INFO
	/**********Radar Config***********************************************************************************************/
	ZZNET_EM_CFG_RADAR            = 2200,		// Radar Config, struct DEV_RADAR_CONFIG
	/**********Video Intercom/Phone General Configs***********************************************************************************/
	ZZNET_EM_CFG_VTH_PASSWORD		= 2300,		// Video Phone Password, struct NET_CFG_VTH_PASSWORD_INFO
    ZZNET_EM_CFG_REGISTAR         = 2301,     // Registrar Server, struct NET_CFG_REGISTAR_INFO
    ZZNET_EM_CFG_SIP              = 2302,     // SIP Config, struct NET_CFG_SIPSERVER_INFO
	/**********Lens Mask Config***************************************************************************************/
	ZZNET_EM_CFG_AELENSMASK       = 2400,     // AE Lens Mask Config, struct NET_CFG_AELENSMASK_INFO

	ZZNET_EM_CFG_ULTRASONIC       = 2500,     // Ultrasonic Config, struct NET_CFG_ULTRASONIC_INFO 
    /**********Alarm Host Related Configs***************************************************************************************/
    ZZNET_EM_CFG_ARMSCHEDULE      = 2600,     // Arming Schedule, struct NET_CFG_ARMSCHEDULE_INFO
	/**********Record Snapshot Function Related Configs***********************************************************************************/
	ZZNET_EM_CFG_RECORDEXTRA	= 3610,			// Sub Stream Record Config, struct NET_CFG_RECORDEXTRA_INFO

	/**********Video Diagnosis Related Configs***************************************************************************************/
	ZZNET_EM_VIDEODIAGNOSIS_PROJECT = 3700,	// Video Diagnosis Plan, struct NET_CFG_VIDEODIAGNOSIS_PROJECT_INFO
	/***********Mobile Related Configs******************************************************************************************/
	ZZNET_EM_CFG_POSITIONREPORTPOLICY	  = 3800,	// GPS Report Policy, struct NET_CFG_POSITIONREPORTPOLICY_INFO
	ZZNET_EM_CFG_VEHICLE_WORKTIMESCHEDULE,		// Vehicle Work Schedule, struct NET_CFG_VEHICLE_WORKTIMESCHEDULE_INFO
	ZZNET_EM_CFG_VEHICLE_LOAD,					// Vehicle Load Config, struct NET_CFG_VEHICLE_LOAD_INFO
    /***********Access Control Related Configs******************************************************************************************/
    ZZNET_EM_CFG_ACCESSCTL_BLACKLIST = 3900,      // Access Control Blacklist Alarm, struct NET_CFG_ACCESSCTL_BLACKLIST
    ZZNET_EM_CFG_ACCESSCTL_BLACKLIST_LINK = 3901, // Access Control Blacklist Linkage, struct NET_CFG_ALARM_MSG_HANDLE
    ZZNET_EM_CFG_ACCESSCTL_SPECIALDAY_GROUP = 3902,// Access Control Holiday Group, struct NET_CFG_ACCESSCTL_SPECIALDAY_GROUP_INFO
    ZZNET_EM_CFG_ACCESSCTL_SPECIALDAYS_SCHEDULE = 3903, // Access Control Holiday Schedule, struct NET_CFG_ACCESSCTL_SPECIALDAYS_SCHEDULE_INFO
    /***********Custom Configs************************************************************************************************/
    ZZNET_EM_CFG_SERIALNOWHITETABLE    = 4000,    // Serial Number Whitelist sent to NVR, struct NET_CFG_SERIALNOWHITETABLE_INFO

    /***********Cloud Operation Configs************************************************************************************************/
    ZZNET_EM_CFG_CLOUDUPLOADTIME    = 5000,    // Cloud Upload Time Period, struct NET_CFG_CLOUDUPLOADTIME_INFO

	/***********PTZ Related Configs************************************************************************************************/
	ZZNET_EM_CFG_PTZ_SPEED			= 7000,		// PTZ Speed Config, struct NET_CFG_PTZ_SPEED
    ZZNET_EM_CFG_PTZ_HORIZONTAL_ROTATION_GROUP_SCAN	= 7001,		/// PTZ Horizontal Rotation Group Scan, struct NET_CFG_HORIZONTAL_ROTATION_GROUP_SCAN_INFO 
	ZZNET_EM_CFG_AUTOSCAN				= 7002,						/// Auto Line Scan, struct NET_CFG_AUTOSCAN_INFO 
    ZZNET_EM_CFG_INTELLI_TOUR         = 7003,                     /// Intelligent Tour Group, struct NET_CFG_INTELLI_TOUR
 	ZZNET_EM_CFG_AUTO_PATTERN			= 7004,						/// Auto Pattern, struct NET_CFG_AUTO_PATTERN_INFO
	ZZNET_EM_CFG_PTZ_DIRECTION_CORRECT	= 7005,					/// PTZ Direction Correction, struct NET_CFG_PTZ_DIRECTION_CORRECT_INFO
	ZZNET_EM_CFG_RAIN_FALL_CONFIG     = 7006,                     /// Rainfall Config (struct NET_CFG_RAIN_FALL_CONFIG_INFO)
	ZZNET_EM_CFG_PTZ_ELEVATION     = 7007,                        /// PTZ Max Elevation (struct NET_CFG_PTZ_ELEVATION_INFO)
    ZZNET_EM_CFG_PTZ_MOVEMENT,						            /// PTZ Movement Config, struct NET_CFG_PTZ_MOVEMENT_INFO
    ZZNET_EM_CFG_PTZ_HEATER,					                    /// Heater Config, struct NET_CFG_PTZ_HEATER_INFO
	ZZNET_EM_CFG_FOV_CALIBRATION,									/// FOV Calibration, struct NET_CFG_FOV_CALIBRATION_INFO
	ZZNET_EM_CFG_PTZ_FAN,											/// Fan Config, struct NET_CFG_PTZ_FAN_INFO

} ZZNET_EM_CFG_OPERATE_TYPE;














///////////////////////////////////Face Recognition Module Structures///////////////////////////////////////

// Person Type
typedef enum 
{
    ZZ_PERSON_TYPE_UNKNOWN,
    ZZ_PERSON_TYPE_NORMAL,                                     // Normal
    ZZ_PERSON_TYPE_SUSPICION,                                  // Suspect
	ZZ_PERSON_TYPE_THIEF,                                      // Thief
	ZZ_PERSON_TYPE_VIP,                                        // VIP
	ZZ_PERSON_TYPE_FATECHECK,                                  // Counterfeit Check
	ZZ_PERSON_TYPE_STAFF,                                      // Staff
}EM_ZZ_PERSON_TYPE;

// Certificate Type
typedef enum
{
    ZZ_CERTIFICATE_TYPE_UNKNOWN,
    ZZ_CERTIFICATE_TYPE_IC,                                    // ID Card
    ZZ_CERTIFICATE_TYPE_PASSPORT,                              // Passport 
}EM_ZZ_CERTIFICATE_TYPE;


typedef struct tagZZNET_UID_CHAR
{
    char szUID[ZZ_MAX_PERSON_ID_LEN];  //UID Content
}ZZNET_UID_CHAR;


// Face Recognition DB Operation
typedef enum
{
    ZZNET_FACERECONGNITIONDB_UNKOWN, 
    ZZNET_FACERECONGNITIONDB_ADD,                         // Add Person/Face, merge image if exists
    ZZNET_FACERECONGNITIONDB_DELETE,                      // Delete Person/Face
    ZZNET_FACERECONGNITIONDB_MODIFY,                      // Modify Person/Face, UID required 
    ZZNET_FACERECONGNITIONDB_DELETE_BY_UID,               // Delete by UID
}EM_ZZ_OPERATE_FACERECONGNITIONDB_TYPE;

// Face Compare Mode
typedef enum 
{
    ZZNET_FACE_COMPARE_MODE_UNKOWN,
    ZZNET_FACE_COMPARE_MODE_NORMAL,                       // Normal
    ZZNET_FACE_COMPARE_MODE_AREA,                         // Specified Face Area Combination
    ZZNET_FACE_COMPARE_MODE_AUTO,                         // Intelligent Mode, algo auto-selects combination 
}EM_ZZ_FACE_COMPARE_MODE;

// Face Area
typedef enum
{
    NET_ZZ_FACE_AREA_TYPE_UNKOWN,
    NE_ZZ_FACE_AREA_TYPE_EYEBROW,                         // Eyebrow
    NET_ZZ_FACE_AREA_TYPE_EYE,                             // Eye
    NET_ZZ_FACE_AREA_TYPE_NOSE,                            // Nose
    NET_ZZ_FACE_AREA_TYPE_MOUTH,                           // Mouth
    NET_ZZ_FACE_AREA_TYPE_CHEEK,                           // Cheek
}EM_ZZ_FACE_AREA_TYPE;

// Face Data Type
typedef enum
{
    ZZNET_FACE_DB_TYPE_UNKOWN,
    ZZNET_FACE_DB_TYPE_HISTORY,                           // History DB, detected faces, usually no person info
    ZZNET_FACE_DB_TYPE_BLACKLIST,                         // Blacklist DB
    ZZNET_FACE_DB_TYPE_WHITELIST,                         // Whitelist DB, deprecated
    ZZNET_FACE_DB_TYPE_ALARM  ,                           // Alarm DB
}EM_ZZ_FACE_DB_TYPE;

// Face Recognition Event Type
typedef enum 
{
    ZZNET_FACERECOGNITION_ALARM_TYPE_UNKOWN,
    ZZNET_FACERECOGNITION_ALARM_TYPE_ALL,                // Black & Whitelist
    ZZNET_FACERECOGNITION_ALARM_TYPE_BLACKLIST,          // Blacklist
    ZZNET_FACERECOGNITION_ALARM_TYPE_WHITELIST,          // Whitelist
}EM_ZZ_FACERECOGNITION_ALARM_TYPE;

// Face Recognition Face Type
typedef enum
{
    EM_ZZ_FACERECOGNITION_FACE_TYPE_UNKOWN,
    EM_ZZ_FACERECOGNITION_FACE_TYPE_ALL,                  // All Faces   
    EM_ZZ_FACERECOGNITION_FACE_TYPE_REC_SUCCESS,          // Recognition Success
    EM_ZZ_FACERECOGNITION_FACE_TYPE_REC_FAIL,             // Recognition Fail
}EM_ZZ_FACERECOGNITION_FACE_TYPE;

// Frame Type Enum  
typedef enum __EM_ZZ_FRAME_TYPE
{
    EM_ZZ_FRAME_UNKOWN,                                   // Unknown Type 
    EM_ZZ_FRAME_TYPE_MOTION,                              // Motion Frame, struct NET_MOTION_FRAM_INFO
}EM_ZZ_FRAME_TYPE;





// ZZNETSDK_OperateFaceRecognitionDB Input Param
typedef struct __ZZNET_IN_OPERATE_FACERECONGNITIONDB
{
    DWORD             dwSize;
    EM_ZZ_OPERATE_FACERECONGNITIONDB_TYPE emOperateType;  // Operation Type
    ZZFACERECOGNITION_PERSON_INFO        stPersonInfo;   // Person Info 

    // Used when emOperateType is ET_FACERECONGNITIONDB_DELETE_BY_UID, stPeronInfo invalid
    DWORD            nUIDNum;                          // UID Count               
    ZZNET_UID_CHAR     *stuUIDs;                         // Person Unique Identifier, generated by server initially, distinct from ID
										               // Memory allocated by user, size sizeof(NET_UID_CHAR)*nUIDNum
    // Image Binary Data
    char              *pBuffer;                        // Buffer Address
    int               nBufferLen;                      // Buffer Length

	BOOL			  bUsePersonInfoEx;				   // Use Person Info Ex
	ZZFACERECOGNITION_PERSON_INFOEX	stPersonInfoEx;	   // Person Info Ex
}ZZNET_IN_OPERATE_FACERECONGNITIONDB;

// ZZNETSDK_OperateFaceRecognitionDB Output Param
typedef struct __ZZNET_OUT_OPERATE_FACERECONGNITIONDB
{
    DWORD               dwSize;
	char				szUID[ZZ_MAX_PERSON_ID_LEN];	// Person UID, valid only when adding
}ZZNET_OUT_OPERATE_FACERECONGNITIONDB;

// Disposition Video Channel Info
typedef struct tagZZNET_DISPOSITION_CHANNEL_INFO
{
	int					nChannelID;			// Video Channel ID
	int					nSimilary;			// Similarity Threshold, 0-100
	BYTE				bReserved[256];		// Reserved
} ZZNET_DISPOSITION_CHANNEL_INFO;

// ZZNETSDK_FaceRecognitionPutDisposition Input Param
typedef struct tagZZNET_IN_FACE_RECOGNITION_PUT_DISPOSITION_INFO
{
	DWORD               			dwSize;
	char                			szGroupId[ZZ_COMMON_STRING_64]; 					// Group ID 
	int								nDispositionChnNum;									// Disposition Channel Count
	ZZNET_DISPOSITION_CHANNEL_INFO	stuDispositionChnInfo[ZZ_MAX_CAMERA_CHANNEL_NUM];	// Disposition Channel Info
} ZZNET_IN_FACE_RECOGNITION_PUT_DISPOSITION_INFO;

// ZZNETSDK_FaceRecognitionPutDisposition Output Param
typedef struct tagZZNET_OUT_FACE_RECOGNITION_PUT_DISPOSITION_INFO
{
	DWORD               dwSize;
	int					nReportCnt;							// Result Count
	BOOL				bReport[ZZ_MAX_CAMERA_CHANNEL_NUM];	// Result, TRUE Success, FALSE Fail
} ZZNET_OUT_FACE_RECOGNITION_PUT_DISPOSITION_INFO;



// ZZNETSDK_FaceRecognitionDelDisposition Input Param
typedef struct tagZZNET_IN_FACE_RECOGNITION_DEL_DISPOSITION_INFO
{
	DWORD               			dwSize;
	char                			szGroupId[ZZ_COMMON_STRING_64]; 				// Group ID 
	int								nDispositionChnNum;								// Disposition Removal Channel Count
	int								nDispositionChn[ZZ_MAX_CAMERA_CHANNEL_NUM];		// Disposition Removal Channel List
} ZZNET_IN_FACE_RECOGNITION_DEL_DISPOSITION_INFO;

// ZZNETSDK_FaceRecognitionDelDisposition Output Param
typedef struct tagZZNET_OUT_FACE_RECOGNITION_DEL_DISPOSITION_INFO
{
	DWORD               dwSize;
	int					nReportCnt;							// Result Count
	BOOL				bReport[ZZ_MAX_CAMERA_CHANNEL_NUM];	// Result, TRUE Success, FALSE Fail
} ZZNET_OUT_FACE_RECOGNITION_DEL_DISPOSITION_INFO;



// Person Group Operation Enum
typedef enum tagEM_ZZ_OPERATE_FACERECONGNITION_GROUP_TYPE
{
    ZZNET_FACERECONGNITION_GROUP_UNKOWN,
    ZZNET_FACERECONGNITION_GROUP_ADD,                     // Add Group
    ZZNET_FACERECONGNITION_GROUP_MODIFY,                  // Modify Group  
    ZZNET_FACERECONGNITION_GROUP_DELETE,                  // Delete Group
}EM_ZZ_OPERATE_FACERECONGNITION_GROUP_TYPE;

// Person Group Info
typedef struct tagZZNET_FACERECONGNITION_GROUP_INFO
{
    DWORD               dwSize;
    EM_ZZ_FACE_DB_TYPE     emFaceDBType;							// Group Type, see EM_FACE_DB_TYPE
    char                szGroupId[ZZ_COMMON_STRING_64];			// Group ID, Unique (Cannot modify, invalid on Add)
    char                szGroupName[ZZ_COMMON_STRING_128];		// Group Name 
    char                szGroupRemarks[ZZ_COMMON_STRING_256];	// Remarks
    int                 nGroupSize;								// Person Count in Group
    int					nRetSimilarityCount;					// Actual Similarity Threshold Count
	int					nSimilarity[ZZ_MAX_SIMILARITY_COUNT];		// Similarity Thresholds, Match if higher
	int					nRetChnCount;							// Actual Channel Count
	int					nChannel[ZZ_MAX_CAMERA_CHANNEL_NUM];	// Binded Video Channels
}ZZNET_FACERECONGNITION_GROUP_INFO;

// Add Group Info
typedef struct tagZZNET_ADD_FACERECONGNITION_GROUP_INFO
{
    DWORD               dwSize;
    ZZNET_FACERECONGNITION_GROUP_INFO stuGroupInfo;      // Group Info 
}ZZNET_ADD_FACERECONGNITION_GROUP_INFO;

// Delete Group Info
typedef struct tagZZNET_DELETE_FACERECONGNITION_GROUP_INFO
{
    DWORD               dwSize;
    char                szGroupId[ZZ_COMMON_STRING_64];// Group ID
}ZZNET_DELETE_FACERECONGNITION_GROUP_INFO;

// Modify Group Info
typedef struct tagZZNET_MODIFY_FACERECONGNITION_GROUP_INFO
{
    DWORD               dwSize;
    ZZNET_FACERECONGNITION_GROUP_INFO stuGroupInfo;      // Group Info 
}ZZNET_MODIFY_FACERECONGNITION_GROUP_INFO;




// ZZNETSDK_FindGroupInfo Input Param
typedef struct tagZZNET_IN_FIND_GROUP_INFO   
{
    DWORD               dwSize;
    char                szGroupId[ZZ_COMMON_STRING_64];// Group ID, empty for all
}ZZNET_IN_FIND_GROUP_INFO;

// ZZNETSDK_FindGroupInfo Output Param
typedef struct tagZZNET_OUT_FIND_GROUP_INFO   
{
    DWORD               dwSize;
    ZZNET_FACERECONGNITION_GROUP_INFO *pGroupInfos;      // Group Info, user allocated, size sizeof(ZZNET_FACERECONGNITION_GROUP_INFO)*nMaxGroupNum
    int                 nMaxGroupNum;                  // Allocated Size
    int                 nRetGroupNum;                  // Returned Count
}ZZNET_OUT_FIND_GROUP_INFO;

// ZZNETSDK_OperateFaceRecognitionGroup Input Param
typedef struct tagZZNET_IN_OPERATE_FACERECONGNITION_GROUP
{
    DWORD               dwSize;
    EM_ZZ_OPERATE_FACERECONGNITION_GROUP_TYPE emOperateType; // Operation Type
    void                *pOPerateInfo;                    // Operation Info, user allocated based on type
														  // If ADD: ZZNET_ADD_FACERECONGNITION_GROUP_INFO;
														  // If MODIFY: ZZNET_MODIFY_FACERECONGNITION_GROUP_INFO
														  // If DELETE: ZZNET_DELETE_FACERECONGNITION_GROUP_INFO
}ZZNET_IN_OPERATE_FACERECONGNITION_GROUP;   

// ZZNETSDK_OperateFaceRecognitionGroup Output Param
typedef struct tagZZNET_OUT_OPERATE_FACERECONGNITION_GROUP
{
    DWORD               dwSize;
    char                szGroupId[ZZ_COMMON_STRING_64]; // New Group ID
}ZZNET_OUT_OPERATE_FACERECONGNITION_GROUP;  


/////////////////////////////////Log Related/////////////////////////////////



// Log Query Type
typedef enum _ZZ_LOG_QUERY_TYPE
{
    ZZLOG_ALL = 0,                              // All Logs
    ZZLOG_SYSTEM,                               // System Log
    ZZLOG_CONFIG,                               // Config Log
    ZZLOG_STORAGE,                              // Storage Related
    ZZLOG_ALARM,                                // Alarm Log
    ZZLOG_RECORD,                               // Record Related
    ZZLOG_ACCOUNT,                              // Account Related
    ZZLOG_CLEAR,                                // Clear Log
    ZZLOG_PLAYBACK,                             // Playback Related
    ZZLOG_MANAGER                               // Frontend Manager Running Related
} ZZ_LOG_QUERY_TYPE;

typedef struct _QUERY_ZZ_DEVICE_LOG_PARAM
{
    ZZ_LOG_QUERY_TYPE   emLogType;                  // Query Log Type
    ZZNET_TIME            stuStartTime;               // Start Time
    ZZNET_TIME            stuEndTime;                 // End Time
    int                 nStartNum;                  // Start Index (0 for first query)
    int                 nEndNum;                    // End Index (Max return count is 1024)
    BYTE                nLogStuType;                // Log Struct Type, 0: ZZ_DEVICE_LOG_ITEM; 1: ZZ_DEVICE_LOG_ITEM_EX
    BYTE                reserved[3];                // Reserved Alignment
    unsigned int        nChannelID;                 // Channel ID, 0: All (compatible), so Channel starts from 1; 1: First Channel
    BYTE                bReserved[40];
} QUERY_ZZ_DEVICE_LOG_PARAM;



// Log Info, corresponds to ZZNETSDK_QueryLog
typedef struct _ZZ_LOG_ITEM
{
    ZZDEVTIME           time;                       // Date
    unsigned short      type;                       // Log Type, see ZZ_LOG_TYPE
    unsigned char       reserved;                   // Reserved
    unsigned char       data;                       // Data
    unsigned char       context[8];                 // Content
} ZZ_LOG_ITEM, *LPZZ_LOG_ITEM;

// Log Info, corresponds to ZZNETSDK_QueryDeviceLog
typedef struct _ZZ_DEVICE_LOG_ITEM
{
    int                 nLogType;                   // Log Type
    ZZDEVTIME           stuOperateTime;             // Date
    char                szOperator[16];             // Operator
    BYTE                bReserved[3];
    BYTE                bUnionType;                 // Union Type, 0: szLogContext; 1: stuOldLog
    union
    {
        char            szLogContext[64];           // Log Remark
        struct 
        {
            ZZ_LOG_ITEM     stuLog;                 // Old Log Struct
            BYTE            bReserved[48];          // Reserved
        }stuOldLog;
    };
    char                reserved[16];
} ZZ_DEVICE_LOG_ITEM, *LPZZ_DEVICE_LOG_ITEM;

// New Log Info Structure, corresponds to ZZNETSDK_QueryDeviceLog
typedef struct _ZZ_DEVICE_LOG_ITEM_EX
{
    int                 nLogType;                   // Log Type
    ZZDEVTIME           stuOperateTime;             // Date
    char                szOperator[16];             // Operator
    BYTE                bReserved[3];
    BYTE                bUnionType;                 // Union Type, 0: szLogContext; 1: stuOldLog
    union
    {
        char            szLogContext[64];           // Log Remark
        struct 
        {
            ZZ_LOG_ITEM     stuLog;                 // Old Log Struct
            BYTE            bReserved[48];          // Reserved
        }stuOldLog;
    };
    char                szOperation[32];            // Specific Operation Content
    char                szDetailContext[4*1024];    // Detailed Log Description
} ZZ_DEVICE_LOG_ITEM_EX, *LPZZ_DEVICE_LOG_ITEM_EX;


// Log Type
typedef enum _ZZ_LOG_TYPE
{
    ZZ_LOG_REBOOT = 0x0000,                     // Device Reboot
    ZZ_LOG_SHUT,                                // Device Shutdown
    ZZ_LOG_REPORTSTOP,
    ZZ_LOG_REPORTSTART,
    ZZ_LOG_UPGRADE = 0x0004,                    // Device Upgrade
    ZZ_LOG_SYSTIME_UPDATE = 0x0005,             // System Time Update
    ZZ_LOG_GPS_TIME_UPDATE = 0x0006,            // GPS Time Update
    ZZ_LOG_AUDIO_TALKBACK,                      // Audio Talkback, true: On, false: Off    
    ZZ_LOG_COMM_ADAPTER,                        // Transparent Comm, true: On, false: Off    
    ZZ_LOG_NET_TIMING,                          // Network Time Sync
    ZZ_LOG_CONFSAVE = 0x0100,                   // Save Config
    ZZ_LOG_CONFLOAD,                            // Load Config
    ZZ_LOG_FSERROR = 0x0200,                    // Filesystem Error
    ZZ_LOG_HDD_WERR,                            // HDD Write Error
    ZZ_LOG_HDD_RERR,                            // HDD Read Error
    ZZ_LOG_HDD_TYPE,                            // Set HDD Type
    ZZ_LOG_HDD_FORMAT,                          // Format HDD
    ZZ_LOG_HDD_NOSPACE,                         // No Space on Working Disk
    ZZ_LOG_HDD_TYPE_RW,                         // Set HDD Type Read/Write
    ZZ_LOG_HDD_TYPE_RO,                         // Set HDD Type Read-Only    
    ZZ_LOG_HDD_TYPE_RE,                         // Set HDD Type Redundant
    ZZ_LOG_HDD_TYPE_SS,                         // Set HDD Type Snapshot
    ZZ_LOG_HDD_NONE,                            // No HDD Record
    ZZ_LOG_HDD_NOWORKHDD,                       // No Working HDD (No Read/Write Disk)
    ZZ_LOG_HDD_TYPE_BK,                         // Set HDD Type Backup
    ZZ_LOG_HDD_TYPE_REVERSE,                    // Set HDD Type Reserved Partition
    ZZ_LOG_HDD_START_INFO = 0x20e ,             // HDD Info at Startup
    ZZ_LOG_HDD_WORKING_DISK,                    // Working Disk No after Switch
    ZZ_LOG_HDD_OTHER_ERROR,                     // Other HDD Errors
    ZZ_LOG_HDD_SLIGHT_ERR,                      // HDD Slight Error
    ZZ_LOG_HDD_SERIOUS_ERR,                     // HDD Serious Error
    ZZ_LOG_HDD_NOSPACE_END,                     // No Space Alarm End
    ZZ_LOG_HDD_TYPE_RAID_CONTROL,               // Raid Operation
    ZZ_LOG_HDD_TEMPERATURE_HIGH,                // Temperature High
    ZZ_LOG_HDD_TEMPERATURE_LOW,                 // Temperature Low
    ZZ_LOG_HDD_ESATA_REMOVE,                    // Remove eSATA
    ZZ_LOG_ALM_IN = 0x0300,                     // External Alarm Input Start
    ZZ_LOG_NETALM_IN,                           // Network Alarm Input
    ZZ_LOG_ALM_END = 0x0302,                    // External Alarm Input Stop
    ZZ_LOG_LOSS_IN,                             // Video Loss Start
    ZZ_LOG_LOSS_END,                            // Video Loss End
    ZZ_LOG_MOTION_IN,                           // Motion Detect Start
    ZZ_LOG_MOTION_END,                          // Motion Detect End
    ZZ_LOG_ALM_BOSHI,                           // Alarm Sensor Input
    ZZ_LOG_NET_ABORT = 0x0308,                  // Network Disconnect
    ZZ_LOG_NET_ABORT_RESUME,                    // Network Resume
    ZZ_LOG_CODER_BREAKDOWN,                     // Encoder Breakdown
    ZZ_LOG_CODER_BREAKDOWN_RESUME,              // Encoder Breakdown Resume
    ZZ_LOG_BLIND_IN,                            // Video Blind
    ZZ_LOG_BLIND_END,                           // Video Blind Resume
    ZZ_LOG_ALM_TEMP_HIGH,                       // Temp High
    ZZ_LOG_ALM_VOLTAGE_LOW,                     // Voltage Low
    ZZ_LOG_ALM_BATTERY_LOW,                     // Battery Low
    ZZ_LOG_ALM_ACC_BREAK,                       // ACC Power Off
    ZZ_LOG_ALM_ACC_RES,
    ZZ_LOG_GPS_SIGNAL_LOST,                     // GPS Signal Lost
    ZZ_LOG_GPS_SIGNAL_RESUME,                   // GPS Signal Resume
    ZZ_LOG_3G_SIGNAL_LOST,                      // 3G Signal Lost
    ZZ_LOG_3G_SIGNAL_RESUME,                    // 3G Signal Resume
    ZZ_LOG_ALM_IPC_IN,                          // IPC External Alarm
    ZZ_LOG_ALM_IPC_END,                         // IPC External Alarm Resume
    ZZ_LOG_ALM_DIS_IN,                          // Net Disconnect Alarm
    ZZ_LOG_ALM_DIS_END,                         // Net Disconnect Alarm Resume
    ZZ_LOG_ALM_UPS_IN, 				            // UPS Alarm
    ZZ_LOG_ALM_UPS_END, 				        // UPS Alarm Resume
    ZZ_LOG_ALM_NAS_IN,				            // NAS Exception Alarm
    ZZ_LOG_ALM_NAS_END,				            // NAS Exception Alarm Resume
    ZZ_LOG_ALM_REDUNDANT_POWER_IN,              // Redundant Power Alarm
    ZZ_LOG_ALM_REDUNDANT_POWER_END,             // Redundant Power Alarm Resume
    ZZ_LOG_ALM_RECORD_FAILED_IN,				// Record Fail Alarm
    ZZ_LOG_ALM_RECORD_FAILED_END,			    // Record Fail Alarm Resume
    ZZ_LOG_ALM_VGEXCEPT_IN,				        // Storage Pool Exception Alarm
    ZZ_LOG_ALM_VGEXCEPT_END,				    // Storage Pool Exception Alarm Resume	
    ZZ_LOG_ALM_FANSPEED_IN,			            // Fan Alarm Start
    ZZ_LOG_ALM_FANSPEED_END,			        // Fan Alarm End
    ZZ_LOG_ALM_DROP_FRAME_IN,			        // Drop Frame Alarm Start
    ZZ_LOG_ALM_DROP_FRAME_END,			        // Drop Frame Alarm End
    ZZ_LOG_ALM_DISK_STATE_CHECK,		        // Disk Pre-check/Inspection Event
    ZZ_LOG_ALARM_COAXIAL_SMOKE,		            // Coaxial Smoke Alarm
    ZZ_LOG_ALARM_COAXIAL_TEMP_HIGH,	            // Coaxial Temp High Alarm
    ZZ_LOG_ALARM_COAXIAL_ALM_IN,		        // Coaxial External Alarm
    ZZ_LOG_INFRAREDALM_IN = 0x03a0,             // Wireless Alarm Start
    ZZ_LOG_INFRAREDALM_END,                     // Wireless Alarm End
    ZZ_LOG_IPCONFLICT,                          // IP Conflict
    ZZ_LOG_IPCONFLICT_RESUME,                   // IP Resume
    ZZ_LOG_SDPLUG_IN,                           // SD Card Plugged (If reserved=3, USB Plugged)
    ZZ_LOG_SDPLUG_OUT,                          // SD Card Removed (If reserved=3, USB Removed)
    ZZ_LOG_NET_PORT_BIND_FAILED,                // Network Port Bind Failed
    ZZ_LOG_HDD_BEEP_RESET,                      // HDD Error Beep Reset
    ZZ_LOG_MAC_CONFLICT,                        // MAC Conflict
    ZZ_LOG_MAC_CONFLICT_RESUME,                 // MAC Conflict Resume
    ZZ_LOG_ALARM_OUT,                           // Alarm Output State
    ZZ_LOG_ALM_RAID_STAT_EVENT,                 // RAID State Change 
    ZZ_LOG_ABLAZE_ON,                           // Fire Alarm On (Smoke/Temp)
    ZZ_LOG_ABLAZE_OFF,                          // Fire Alarm Off
    ZZ_LOG_INTELLI_ALARM_PLUSE,                 // Intelligent Pulse Alarm
    ZZ_LOG_INTELLI_ALARM_IN,                    // Intelligent Alarm Start
    ZZ_LOG_INTELLI_ALARM_END,                   // Intelligent Alarm End
    ZZ_LOG_3G_SIGNAL_SCAN,                      // 3G Signal Scan
    ZZ_LOG_GPS_SIGNAL_SCAN,                     // GPS Signal Scan
    ZZ_LOG_AUTOMATIC_RECORD = 0x0400,           // Auto Record
    ZZ_LOG_MANUAL_RECORD = 0x0401,              // Manual Record
    ZZ_LOG_CLOSED_RECORD,                       // Stop Record
    ZZ_LOG_LOGIN = 0x0500,                      // Login
    ZZ_LOG_LOGOUT,                              // Logout
    ZZ_LOG_ADD_USER,                            // Add User
    ZZ_LOG_DELETE_USER,                         // Delete User
    ZZ_LOG_MODIFY_USER,                         // Modify User
    ZZ_LOG_ADD_GROUP,                           // Add Group
    ZZ_LOG_DELETE_GROUP,                        // Delete Group
    ZZ_LOG_MODIFY_GROUP,                        // Modify Group
    ZZ_LOG_NET_LOGIN = 0x0508,                  // Network User Login
    ZZ_LOG_MODIFY_PASSWORD,                     // Modify Password
    ZZ_LOG_CLEAR = 0x0600,                      // Clear Log
    ZZ_LOG_SEARCHLOG,                           // Search Log
    ZZ_LOG_SEARCH = 0x0700,                     // Record Search
    ZZ_LOG_DOWNLOAD,                            // Record Download
    ZZ_LOG_PLAYBACK,                            // Record Playback
    ZZ_LOG_BACKUP,                              // Backup Record File
    ZZ_LOG_BACKUPERROR,                         // Backup Fail
    ZZ_LOG_BACK_UPRT,                           // Realtime Backup (Burning)
    ZZ_LOG_BACKUPCLONE,                         // Disc Copy
    ZZ_LOG_DISK_CHANGED,                        // Manual Disk Change
    ZZ_LOG_IMAGEPLAYBACK,                       // Image Playback
    ZZ_LOG_LOCKFILE,                            // Lock Record
    ZZ_LOG_UNLOCKFILE,                          // Unlock Record
    ZZ_LOG_ATMPOS,                              // ATM Card Overlay Log
    ZZ_PLAY_PAUSE,                              // Pause Playback
    ZZ_PLAY_START,                              // Start Playback
    ZZ_LOG_PLAY_STOP,                              // Stop Playback
    ZZ_LOG_PLAY_BACK,                              // Reverse Playback
    ZZ_LOG_PLAY_FAST,                              // Fast Forward
    ZZ_LOG_PLAY_SLOW,                              // Slow Forward
    ZZ_LOG_SMART_SEARCH,                           // Smart Search
    ZZ_LOG_RECORD_SNAP,                            // Record Snapshot
    ZZ_LOG_ADD_TAG,                                // Add Tag
    ZZ_LOG_DEL_TAG,                                // Del Tag
    ZZ_LOG_USB_IN,                                 // USB Plugged
    ZZ_LOG_USB_OUT,                                // USB Removed
    ZZ_LOG_BACKUP_FILE,                            // File Backup
    ZZ_LOG_BACKUP_LOG,                             // Log Backup
    ZZ_LOG_BACKUP_CONFIG,                          // Config Backup

    ZZ_LOG_TIME_UPDATE  = 0x0800,               // Time Sync
    ZZ_LOG_REMOTE_STATE = 0x0850,               // Remote Log 
    ZZ_LOG_USER_DEFINE = 0x0900,
    ZZ_LOG_TYPE_NR = 10,
} ZZ_LOG_TYPE;

// Extended Log Type, corresponds to ZZNETSDK_QueryLogEx, condition(int nType = 1; param reserved = &nType)
typedef enum _ZZ_NEWLOG_TYPE
{
    ZZ_NEWLOG_REBOOT = 0x0000,                     // Device Reboot
    ZZ_NEWLOG_SHUT,                                // Device Shutdown
    ZZ_NEWLOG_REPORTSTOP,
    ZZ_NEWLOG_REPORTSTART,
    ZZ_NEWLOG_UPGRADE = 0x0004,                    // Device Upgrade
    ZZ_NEWLOG_SYSTIME_UPDATE = 0x0005,             // System Time Update
    ZZ_NEWLOG_GPS_TIME_UPDATE = 0x0006,            // GPS Time Update

    ZZ_NEWLOG_AUDIO_TALKBACK,                      // Audio Talkback, true: On, false: Off    
    ZZ_NEWLOG_COMM_ADAPTER,                        // Transparent Comm, true: On, false: Off    
    ZZ_NEWLOG_NET_TIMING,                          // Network Time Sync

    ZZ_NEWLOG_CONFSAVE = 0x0100,                   // Save Config
    ZZ_NEWLOG_CONFLOAD,                            // Load Config
    ZZ_NEWLOG_FSERROR = 0x0200,                    // Filesystem Error
    ZZ_NEWLOG_HDD_WERR,                            // HDD Write Error
    ZZ_NEWLOG_HDD_RERR,                            // HDD Read Error
    ZZ_NEWLOG_HDD_TYPE,                            // Set HDD Type
    ZZ_NEWLOG_HDD_FORMAT,                          // Format HDD
    ZZ_NEWLOG_HDD_NOSPACE,                         // No Space on Working Disk
    ZZ_NEWLOG_HDD_TYPE_RW,                         // Set HDD Type Read/Write
    ZZ_NEWLOG_HDD_TYPE_RO,                         // Set HDD Type Read-Only    
    ZZ_NEWLOG_HDD_TYPE_RE,                         // Set HDD Type Redundant
    ZZ_NEWLOG_HDD_TYPE_SS,                         // Set HDD Type Snapshot
    ZZ_NEWLOG_HDD_NONE,                            // No HDD Record Log
    ZZ_NEWLOG_HDD_NOWORKHDD,                       // No Working HDD (No Read/Write Disk)
    ZZ_NEWLOG_HDD_TYPE_BK,                         // Set HDD Type Backup
    ZZ_NEWLOG_HDD_TYPE_REVERSE,                    // Set HDD Type Reserved Partition
    ZZ_NEWLOG_HDD_START_INFO = 0x20e,              // HDD Info at Startup
    ZZ_NEWLOG_HDD_WORKING_DISK,                    // Working Disk No after Switch
    ZZ_NEWLOG_HDD_OTHER_ERROR,                     // Other HDD Errors
    ZZ_NEWLOG_HDD_SLIGHT_ERR,                      // HDD Slight Error
    ZZ_NEWLOG_HDD_SERIOUS_ERR,                     // HDD Serious Error
    ZZ_NEWLOG_HDD_NOSPACE_END,                     // No Space Alarm End

    ZZ_NEWLOG_HDD_TYPE_RAID_CONTROL,               // Raid Operation
    ZZ_NEWLOG_HDD_TEMPERATURE_HIGH,                // Temperature High
    ZZ_NEWLOG_HDD_TEMPERATURE_LOW,                 // Temperature Low
    ZZ_NEWLOG_HDD_ESATA_REMOVE,                    // Remove eSATA

    ZZ_NEWLOG_ALM_IN = 0x0300,                     // External Alarm Input Start
    ZZ_NEWLOG_NETALM_IN,                           // Network Alarm
    ZZ_NEWLOG_ALM_END = 0x0302,                    // External Alarm Input Stop
    ZZ_NEWLOG_LOSS_IN,                             // Video Loss Start
    ZZ_NEWLOG_LOSS_END,                            // Video Loss End
    ZZ_NEWLOG_MOTION_IN,                           // Motion Detect Start
    ZZ_NEWLOG_MOTION_END,                          // Motion Detect End
    ZZ_NEWLOG_ALM_BOSHI,                           // Alarm Sensor Input
    ZZ_NEWLOG_NET_ABORT = 0x0308,                  // Network Disconnect
    ZZ_NEWLOG_NET_ABORT_RESUME,                    // Network Resume
    ZZ_NEWLOG_CODER_BREAKDOWN,                     // Encoder Breakdown
    ZZ_NEWLOG_CODER_BREAKDOWN_RESUME,              // Encoder Breakdown Resume
    ZZ_NEWLOG_BLIND_IN,                            // Video Blind
    ZZ_NEWLOG_BLIND_END,                           // Video Blind Resume
    ZZ_NEWLOG_ALM_TEMP_HIGH,                       // Temp High
    ZZ_NEWLOG_ALM_VOLTAGE_LOW,                     // Voltage Low
    ZZ_NEWLOG_ALM_BATTERY_LOW,                     // Battery Low
    ZZ_NEWLOG_ALM_ACC_BREAK,                       // ACC Power Off
    ZZ_NEWLOG_ALM_ACC_RES,
    ZZ_NEWLOG_GPS_SIGNAL_LOST,                     // GPS Signal Lost
    ZZ_NEWLOG_GPS_SIGNAL_RESUME,                   // GPS Signal Resume
    ZZ_NEWLOG_3G_SIGNAL_LOST,                      // 3G Signal Lost
    ZZ_NEWLOG_3G_SIGNAL_RESUME,                    // 3G Signal Resume

    ZZ_NEWLOG_ALM_IPC_IN,                          // IPC External Alarm
    ZZ_NEWLOG_ALM_IPC_END,                         // IPC External Alarm Resume
    ZZ_NEWLOG_ALM_DIS_IN,                          // Net Disconnect Alarm
    ZZ_NEWLOG_ALM_DIS_END,                         // Net Disconnect Alarm Resume

    ZZ_NEWLOG_INFRAREDALM_IN = 0x03a0,             // Wireless Alarm Start
    ZZ_NEWLOG_INFRAREDALM_END,                     // Wireless Alarm End
    ZZ_NEWLOG_IPCONFLICT,                          // IP Conflict
    ZZ_NEWLOG_IPCONFLICT_RESUME,                   // IP Resume
    ZZ_NEWLOG_SDPLUG_IN,                           // SD Card Plugged
    ZZ_NEWLOG_SDPLUG_OUT,                          // SD Card Removed
    ZZ_NEWLOG_NET_PORT_BIND_FAILED,                // Network Port Bind Failed
    ZZ_NEWLOG_HDD_BEEP_RESET,                      // HDD Error Beep Reset
    ZZ_NEWLOG_MAC_CONFLICT,                        // MAC Conflict
    ZZ_NEWLOG_MAC_CONFLICT_RESUME,                 // MAC Conflict Resume
    ZZ_NEWLOG_ALARM_OUT,                           // Alarm Output State
    ZZ_NEWLOG_ALM_RAID_STAT_EVENT,                 // RAID State Change 
    ZZ_NEWLOG_ABLAZE_ON,                           // Fire Alarm On (Smoke/Temp)
    ZZ_NEWLOG_ABLAZE_OFF,                          // Fire Alarm Off
    ZZ_NEWLOG_INTELLI_ALARM_PLUSE,                 // Intelligent Pulse Alarm
    ZZ_NEWLOG_INTELLI_ALARM_IN,                    // Intelligent Alarm Start
    ZZ_NEWLOG_INTELLI_ALARM_END,                   // Intelligent Alarm End
    ZZ_NEWLOG_3G_SIGNAL_SCAN,                      // 3G Signal Scan
    ZZ_NEWLOG_GPS_SIGNAL_SCAN,                     // GPS Signal Scan
    ZZ_NEWLOG_AUTOMATIC_RECORD = 0x0400,           // Auto Record
    ZZ_NEWLOG_MANUAL_RECORD,                       // Manual Record On
    ZZ_NEWLOG_CLOSED_RECORD,                       // Stop Record
    ZZ_NEWLOG_LOGIN = 0x0500,                      // Login
    ZZ_NEWLOG_LOGOUT,                              // Logout
    ZZ_NEWLOG_ADD_USER,                            // Add User
    ZZ_NEWLOG_DELETE_USER,                         // Delete User
    ZZ_NEWLOG_MODIFY_USER,                         // Modify User
    ZZ_NEWLOG_ADD_GROUP,                           // Add Group
    ZZ_NEWLOG_DELETE_GROUP,                        // Delete Group
    ZZ_NEWLOG_MODIFY_GROUP,                        // Modify Group
    ZZ_NEWLOG_NET_LOGIN = 0x0508,                  // Network User Login
    ZZ_NEWLOG_CLEAR = 0x0600,                      // Clear Log
    ZZ_NEWLOG_SEARCHLOG,                           // Search Log
    ZZ_NEWLOG_SEARCH = 0x0700,                     // Record Search
    ZZ_NEWLOG_DOWNLOAD,                            // Record Download
    ZZ_NEWLOG_PLAYBACK,                            // Record Playback
    ZZ_NEWLOG_BACKUP,                              // Backup Record File
    ZZ_NEWLOG_BACKUPERROR,                         // Backup Fail

    ZZ_NEWLOG_BACK_UPRT,                           // Realtime Backup (Burning)
    ZZ_NEWLOG_BACKUPCLONE,                         // Disc Copy
    ZZ_NEWLOG_DISK_CHANGED,                        // Manual Disk Change
    ZZ_NEWLOG_IMAGEPLAYBACK,                       // Image Playback
    ZZ_NEWLOG_LOCKFILE,                            // Lock Record
    ZZ_NEWLOG_UNLOCKFILE,                          // Unlock Record
    ZZ_NEWLOG_ATMPOS,                              // ATM Card Overlay Log

    ZZ_NEWLOG_TIME_UPDATE  = 0x0800,               // Time Update
    ZZ_NEWLOG_REMOTE_STATE = 0x0850,               // Remote Log 

    ZZ_NEWLOG_USER_DEFINE = 0x0900,
    ZZ_NEWLOG_TYPE_NR = 10,        
} ZZ_NEWLOG_TYPE;













// Audio Output Mode
typedef enum
{
    ZZ_AUDIO_AUTO,                              // Auto switch audio output, only one audio window
    ZZ_AUDIO_DISABLE,                           // Disable all audio output 
    ZZ_AUDIO_FORCE,                             // Force audio output on user specified window, only one audio window
    ZZ_AUDIO_ENABLE_ONE,                        // Enable specific window audio, supports multi-channel output   
    ZZ_AUDIO_DISABLE_ONE,                       // Disable specific window audio, supports multi-channel output
    ZZ_AUDIO_MULTI,                             // Multi-channel output, valid for Query, invalid for Set
} ZZ_AUDIO_OUTPUT_MODE;

// ZZNETSDK_SetSplitAudioOuput Input Param (Set Audio Output Mode)
typedef struct tagZZ_IN_SET_AUDIO_OUTPUT 
{
    DWORD                dwSize;
    int                  nChannel;              // Channel ID
    ZZ_AUDIO_OUTPUT_MODE emMode;                // Audio Output Mode
    int                  nWindow;               // Output Window No, valid when emMode is FORCE/ENABLE_ONE/DISABLE_ONE
} ZZ_IN_SET_AUDIO_OUTPUT;

// ZZNETSDK_SetSplitAudioOuput Output Param (Set Audio Output Mode)
typedef struct tagZZ_OUT_SET_AUDIO_OUTPUT
{
    DWORD                dwSize;
} ZZ_OUT_SET_AUDIO_OUTPUT;


// ZZNETSDK_GetSplitAudioOuput Input Param (Get Audio Output Mode)
typedef struct tagZZ_IN_GET_AUDIO_OUTPUT
{
    DWORD                dwSize;
    int                  nChannel;              // Channel ID
} ZZ_IN_GET_AUDIO_OUTPUT;

// ZZNETSDK_GetSplitAudioOuput Output Param (Get Audio Output Mode)
typedef struct tagZZ_OUT_GET_AUDIO_OUTPUT
{
    DWORD                dwSize;
    ZZ_AUDIO_OUTPUT_MODE emMode;                // Audio Output Mode
    int                  nWindow;               // Output Window No, valid when emMode is FORCE
    int*                 pMultiWindows;         // Window List, valid when emMode is MULTI, user allocates memory size sizeof(int)*nMaxMultiWindowCount
    int                  nMaxMultiWindowCount;  // Max Window Count, filled by user
    int                  nRetMultiWindowCount;  // Returned Window Count, valid when emMode is MULTI
} ZZ_OUT_GET_AUDIO_OUTPUT;


// Supported Talk Types List
typedef struct 
{
    int                     nSupportNum;                    // Count
    ZZDEV_TALKDECODE_INFO   type[64];                       // Encode Types
    char                    reserved[64];
} ZZDEV_TALKFORMAT_LIST;

// Composite Channel Info
typedef struct tagZZ_COMPOSITE_CHANNEL
{
    DWORD               dwSize;
    char                szMonitorWallName[ZZ_DEVICE_NAME_LEN];  // Video Wall Name
    char                szCompositeID[ZZ_DEV_ID_LEN_EX];        // Composite ID
    int                 nVirtualChannel;                        // Virtual Channel ID
} ZZ_COMPOSITE_CHANNEL;

// HDD Info
typedef struct
{
    DWORD               dwVolume;                           // Capacity, MB (B is byte)
    DWORD               dwFreeSpace;                        // Free Space, MB (B is byte)
    BYTE                dwStatus;                           // High 4 bits: Type (EM_DISK_TYPE); Low 4 bits: Status (0-Sleep, 1-Active, 2-Error)
    BYTE                bDiskNum;                           // Disk No
    BYTE                bSubareaNum;                        // Partition No
    BYTE                bSignal;                            // Flag, 0: Local, 1: Remote
} ZZNET_DEV_DISKSTATE,*LPZZNET_DEV_DISKSTATE;

// Device HDD State
typedef struct _ZZ_HARDDISK_STATE
{
    DWORD                dwDiskNum;                         // Count
    ZZNET_DEV_DISKSTATE    stDisks[ZZ_MAX_DISKNUM];           // Disk or Partition Info
} ZZ_HARDDISK_STATE, *LPZZ_HARDDISK_STATE;


// Query Type, corresponds to ZZNETSDK_QueryDevState
#define ZZ_DEVSTATE_DISK                  0x0004           // Query Disk Info

#define ZZ_DEVSTATE_PROTOCAL_VER          0x0008           // Query Protocol Version, pBuf = int*
#define ZZ_DEVSTATE_TALK_ECTYPE           0x0009           /// Query Talk Formats, see ZZDEV_TALKFORMAT_LIST

#define ZZ_DEVSTATE_SOFTWARE              0x000F           // Query Software Version

#define ZZ_DEVSTATE_COMPOSITE_CHN         0x0047           /// Query Composite Channel Info (ZZ_COMPOSITE_CHANNEL Array)


#define ZZ_DEVSTATE_PTZ_PRESET_LIST       0x0057           // Get PTZ Preset List (ZZNET_PTZ_PRESET_LIST)


#define ZZ_DEVSTATE_GET_PTZ_TOURS		  0x157c		   /// Get PTZ Tour List (NET_GET_PTZ_TOURS_INFO)






// DSP Capability, corresponds to ZZNETSDK_GetDevConfig
typedef struct 
{
    DWORD               dwVideoStandardMask;        // Video Standard Mask
    DWORD               dwImageSizeMask;            // Resolution Mask
    DWORD               dwEncodeModeMask;           // Encode Mode Mask    
    DWORD               dwStreamCap;                // Multimedia Features Mask
                                                    // Bit 1: Main Stream
                                                    // Bit 2: Sub Stream 1
                                                    // Bit 3: Sub Stream 2
                                                    // Bit 5: JPG Snapshot
    DWORD               dwImageSizeMask_Assi[8];    // Sub Stream Resolution Mask for corresponding Main Stream Resolution
    DWORD               dwMaxEncodePower;           // Max Encode Power of DSP 
    WORD                wMaxSupportChannel;         // Max Video Input per DSP 
    WORD                wChannelMaxSetSync;         // Sync Max Setting per Channel; 0:No 1:Yes
} ZZ_DSP_ENCODECAP, *LPZZ_DSP_ENCODECAP;


// Device Software Version Info, High 16 bits: Major, Low 16 bits: Minor
typedef struct 
{
    DWORD               dwSoftwareVersion;
    DWORD               dwSoftwareBuildDate;
    DWORD               dwDspSoftwareVersion;
    DWORD               dwDspSoftwareBuildDate;
    DWORD               dwPanelVersion;
    DWORD               dwPanelSoftwareBuildDate;
    DWORD               dwHardwareVersion;
    DWORD               dwHardwareDate;
    DWORD               dwWebVersion;
    DWORD               dwWebBuildDate;
} ZZ_VERSION_INFO, *LPZZ_VERSION_INFO;

// Device Version Info, corresponds to ZZNETSDK_QueryDevState
typedef struct  
{
    char                szDevSerialNo[ZZ_DEV_SERIALNO_LEN];         // Serial Number
    char                byDevType;                                  // Device Type, see NET_DEVICE_TYPE
    char                szDevType[ZZ_DEV_TYPE_LEN];                 // Detailed Model, string, may be empty
    int                 nProtocalVer;                               // Protocol Version
    char                szSoftWareVersion[ZZ_MAX_URL_LEN];
    DWORD               dwSoftwareBuildDate;
    char                szPeripheralSoftwareVersion[ZZ_MAX_URL_LEN];// Peripheral Version, string, may be empty
    DWORD               dwPeripheralSoftwareBuildDate;
    char                szGeographySoftwareVersion[ZZ_MAX_URL_LEN]; // GPS Chip Version, string, may be empty
    DWORD               dwGeographySoftwareBuildDate;
    char                szHardwareVersion[ZZ_MAX_URL_LEN];
    DWORD               dwHardwareDate;
    char                szWebVersion[ZZ_MAX_URL_LEN];
    DWORD               dwWebBuildDate;
    char                szDetailType[ZZ_MAX_COMMON_STRING_64];          // Detailed Model, string, may be empty
    char                reserved[192];
} ZZDEV_VERSION_INFO;

// System Info
typedef struct 
{
    DWORD               dwSize;
    /* Read-Only Part */
    ZZ_VERSION_INFO     stVersion;
    ZZ_DSP_ENCODECAP    stDspEncodeCap;                     // DSP Capability
    BYTE                szDevSerialNo[ZZ_DEV_SERIALNO_LEN]; // Serial Number
    BYTE                byDevType;                          // Device Type
    BYTE                szDevType[ZZ_DEV_TYPE_LEN];         // Detailed Model
    BYTE                byVideoCaptureNum;                  // Video Input Count
    BYTE                byAudioCaptureNum;                  // Audio Input Count
    BYTE                byTalkInChanNum;                    // Talk Input Count
    BYTE                byTalkOutChanNum;                   // Talk Output Count
    BYTE                byDecodeChanNum;                    // NSP
    BYTE                byAlarmInNum;                       // Alarm Input Count
    BYTE                byAlarmOutNum;                      // Alarm Output Count
    BYTE                byNetIONum;                         // Network Port Count
    BYTE                byUsbIONum;                         // USB Port Count
    BYTE                byIdeIONum;                         // IDE Count
    BYTE                byComIONum;                         // Serial Port Count
    BYTE                byLPTIONum;                         // Parallel Port Count
    BYTE                byVgaIONum;                         // NSP
    BYTE                byIdeControlNum;                    // NSP
    BYTE                byIdeControlType;                   // NSP
    BYTE                byCapability;                       // NSP, Extended Description
    BYTE                byMatrixOutNum;                     // Matrix Output Count
    /* Writable Part */
    BYTE                byOverWrite;                        // HDD Full Strategy (Overwrite, Stop)
    BYTE                byRecordLen;                        // Record Pack Length
    BYTE                byDSTEnable;                        // DST Enable 1-Yes 0-No
    WORD                wDevNo;                             // Device ID for Remote Control
    BYTE                byVideoStandard;                    // Video Standard: 0-PAL, 1-NTSC
    BYTE                byDateFormat;                       // Date Format
    BYTE                byDateSprtr;                        // Date Separator (0:".", 1:"-", 2:"/")
    BYTE                byTimeFmt;                          // Time Format (0-24H, 1-12H)
    BYTE                byLanguage;                         // Language, see ZZ_LANGUAGE_TYPE
} ZZDEV_SYSTEM_ATTR_CFG, *LPZZDEV_SYSTEM_ATTR_CFG;



// Ethernet Extended Config
typedef struct 
{
    char                sDevIPAddr[ZZ_MAX_IPADDR_LEN];      // DVR IP
    char                sDevIPMask[ZZ_MAX_IPADDR_LEN];      // Mask
    char                sGatewayIP[ZZ_MAX_IPADDR_LEN];      // Gateway

    /*
     * 1: 10Mbps Full
     * 2: 10Mbps Auto
     * 3: 10Mbps Half
     * 4: 100Mbps Full
     * 5: 100Mbps Auto
     * 6: 100Mbps Half
     * 7: Auto
     */
    // Split DWORD into 4 bytes
    BYTE                dwNetInterface;                     // NSP
    BYTE                bTranMedia;                         // 0: Wired, 1: Wireless
    BYTE                bValid;                             // Bit 1: Valid; Bit 2: ZZCP Enable; Bit 3: ZZCP Supported
    BYTE                bDefaultEth;                        // Is Default NIC 1:Yes 0:No
    char                byMACAddr[ZZ_MACADDR_LEN];          // MAC (Read-Only)
    BYTE                bMode;                              // NIC Mode, 0:Bonding, 1:Load Balance, 2:Multi-Address, 3:Fault Tolerance
    BYTE                bReserved1[3];                      // Alignment
    char                szEthernetName[ZZ_MAX_NAME_LEN];    // NIC Name (Read-Only)
    BYTE                bReserved[12];                      // Reserved   
} ZZ_ETHERNET_EX; 

// Remote Host Config
typedef struct 
{
    BYTE                byEnable;                           // Enable
    BYTE                byAssistant;                        // For PPPoE: 0-Wired, 1-Wireless
    WORD                wHostPort;                          // Port
    char                sHostIPAddr[ZZ_MAX_IPADDR_LEN];     // IP        
    char                sHostUser[ZZ_MAX_HOST_NAMELEN];     // Username
    char                sHostPassword[ZZ_MAX_HOST_PSWLEN];  // Password
} ZZ_REMOTE_HOST;

// Mail Config
typedef struct 
{
    char                sMailIPAddr[ZZ_MAX_IPADDR_LEN];     // Server IP
    WORD                wMailPort;                          // Port
    WORD                wReserved;                          // Reserved
    char                sSenderAddr[ZZ_MAX_MAIL_ADDR_LEN];  // Sender
    char                sUserName[ZZ_MAX_NAME_LEN];         // Username
    char                sUserPsw[ZZ_MAX_NAME_LEN];          // Password
    char                sDestAddr[ZZ_MAX_MAIL_ADDR_LEN];    // Recipient
    char                sCcAddr[ZZ_MAX_MAIL_ADDR_LEN];      // CC
    char                sBccAddr[ZZ_MAX_MAIL_ADDR_LEN];     // BCC
    char                sSubject[ZZ_MAX_MAIL_SUBJECT_LEN];  // Subject
} ZZ_MAIL_CFG;

// Extended Network Config Struct
typedef struct
{ 
    DWORD               dwSize; 
    char                sDevName[ZZ_MAX_NAME_LEN];          // Hostname
    WORD                wTcpMaxConnectNum;                  // TCP Max Connections
    WORD                wTcpPort;                           // TCP Port
    WORD                wUdpPort;                           // UDP Port
    WORD                wHttpPort;                          // HTTP Port
    WORD                wHttpsPort;                         // HTTPS Port
    WORD                wSslPort;                           // SSL Port
    int                 nEtherNetNum;                       // NIC Count
    ZZ_ETHERNET_EX      stEtherNet[ZZ_MAX_ETHERNET_NUM_EX]; // NIC Info
    ZZ_REMOTE_HOST      struAlarmHost;                      // Alarm Server
    ZZ_REMOTE_HOST      struLogHost;                        // Log Server
    ZZ_REMOTE_HOST      struSmtpHost;                       // SMTP Server
    ZZ_REMOTE_HOST      struMultiCast;                      // Multicast
    ZZ_REMOTE_HOST      struNfs;                            // NFS
    ZZ_REMOTE_HOST      struPppoe;                          // PPPoE
    char                sPppoeIP[ZZ_MAX_IPADDR_LEN];        // PPPoE IP
    ZZ_REMOTE_HOST      struDdns;                           // DDNS
    char                sDdnsHostName[ZZ_MAX_HOST_NAMELEN]; // DDNS Hostname
    ZZ_REMOTE_HOST      struDns;                            // DNS
    ZZ_MAIL_CFG         struMail;                           // Mail Config
    BYTE                bReserved[128];                     // Reserved
} ZZDEV_NET_CFG_EX;


// Timing Record
typedef struct 
{
    DWORD               dwSize;
    ZZ_TSECT            stSect[ZZ_N_WEEKS][ZZ_N_REC_TSECT];
    BYTE                byPreRecordLen;                     // Pre-record time (s), 0: Disable
    BYTE                byRedundancyEn;                     // Redundancy Switch
    BYTE                byRecordType;                       // Stream Type: 0-Main 1-Sub1 2-Sub2 3-Sub3
    BYTE                byReserved;
} ZZDEV_RECORD_CFG, *LPZZ_RECORD_CFG;

// NTP Config
typedef struct  
{
    BOOL                bEnable;                            // Enable
    int                 nHostPort;                          // Port (Default 123)
    char                szHostIp[32];                       // Host IP
    char                szDomainName[128];                  // Domain
    int                 nType;                              // Read-Only, 0:IP, 1:Domain, 2:Both
    int                 nUpdateInterval;                    // Update Interval (mins)
    int                 nTimeZone;                          // ZZ_TIME_ZONE_TYPE
    char                reserved[128];
} ZZDEV_NTP_CFG;

// Watermark Config
typedef struct __ZZDEV_WATERMAKE_CFG 
{
    DWORD               dwSize;
    int                 nEnable;                                // Enable
    int                 nStream;                                // Stream (1~n) 0-All
    int                 nKey;                                   // Type (1-Text, 2-Image)
    char                szLetterData[ZZ_MAX_WATERMAKE_LETTER];  //    Text
    char                szData[ZZ_MAX_WATERMAKE_DATA];          // Image Data
    BYTE                bReserved[512];                         // Reserved
} ZZDEV_WATERMAKE_CFG;




// Encoder Info
typedef struct __ZZDEV_ENCODER_INFO 
{
    char            szDevIp[ZZ_MAX_IPADDR_LEN];             // IP
    WORD            wDevPort;                               // Port
    BYTE            bDevChnEnable;                          // Enable
    BYTE            byDecoderID;                            // Deprecated, use dwDecoderID
    char            szDevUser[ZZ_USER_NAME_LENGTH_EX];      // Username
    char            szDevPwd[ZZ_USER_PSW_LENGTH_EX];        // Password
    int             nDevChannel;                            // Channel
    int             nStreamType;                            // Stream Type, 0:Main; 1:Sub1; 2:Snap; 3:Sub2
    BYTE            byConnType;                             // -1: Auto, 0:TCP; 1:UDP; 2:Multicast
    BYTE            byWorkMode;                             // 0: Direct; 1: Forward
    WORD            wListenPort;                            // Listen Port (Forward mode)
    DWORD           dwProtoType;                            // Protocol Type,
                                                            // 0: Compatible
                                                            // 1: Gen 2
                                                            // 2: Integration
                                                            // 3: DSS
                                                            // 4: RTSP
    char            szDevName[64];                          // Device Name
    BYTE            byVideoInType;                          // Source Type: 0-SD, 1-HD        
    char            szDevIpEx[ZZ_MAX_IPADDR_OR_DOMAIN_LEN]; // IP Extended (Domain supported)
    BYTE            bySnapMode;                             // Snapshot Mode (nStreamType==2) 0: Request one, 1: Timing
    BYTE            byManuFactory;                          // Manufacturer, see EM_IPC_TYPE
    BYTE            byDeviceType;                           // Device Type, 0:IPC
    BYTE            byDecodePolicy;                         // Decode Policy
                                                            // 1: Realtime High 2: Realtime Mid
                                                            // 3: Realtime Low 4: Default
                                                            // 5: Fluency High 6: Fluency Mid
                                                            // 7: Fluency Low
    BYTE            bReserved[3];                           // Reserved
    DWORD           dwHttpPort;                             // Http Port
    DWORD           dwRtspPort;                             // Rtsp Port
    char            szChnName[32];                          // Remote Channel Name
    DWORD           dwDecoderID;                            // Decoder ID
} ZZDEV_ENCODER_INFO, *LPZZDEV_ENCODER_INFO;

// Frontend Encoder Config Extended
typedef struct __ZZDEV_ENCODER_CFG_EX 
{
    int                 nChannels;                  // Channel Count
    ZZDEV_ENCODER_INFO  stuDevInfo[128];            // Encoder Info
    BYTE                byHDAbility;                // Max HD Channels (0: Not supported)
    // Note: HD channels are 0~N-1
    BYTE                bTVAdjust;                  // TV Adjust Support 0:No 1:Yes
    BYTE                bDecodeTour;                // Decode Tour Support, 0:No >0:Max Devices
    BYTE                bRemotePTZCtl;              // Remote PTZ Support
    char                reserved[256];
} ZZDEV_ENCODER_CFG_EX, *LPZZDEV_ENCODER_CFG_EX;

// Frontend Encoder Config Extended 2
typedef struct __ZZDEV_ENCODER_CFG_EX2
{
	int                 nChannels;                  // Actual Channel Count
	int					nDevInfoMaxNum;				// Max Allocated Channel Count
	ZZDEV_ENCODER_INFO  *pstuDevInfo;				// Encoder Info Pointer, size sizeof(DEV_ENCODER_INFO)*nDevInfoMaxNum;
	BYTE                byHDAbility;                // Max HD Channels
	// Note: HD channels are 0~N-1
	BYTE                bTVAdjust;                  // TV Adjust Support
	BYTE                bDecodeTour;                // Decode Tour Support
	BYTE                bRemotePTZCtl;              // Remote PTZ Support
	char                reserved[256];
} ZZDEV_ENCODER_CFG_EX2, *LPZZDEV_ENCODER_CFG_EX2;



// Config Types, corresponds to ZZNETSDK_GetDevConfig / SetDevConfig
#define ZZ_DEV_DEVICECFG                  0x0001           // Device Property Config

#define ZZ_DEV_CHANNELCFG                 0x0003           // Image Channel Config

#define ZZ_DEV_RECORDCFG                  0x0005           // Record Config

#define ZZ_DEV_WATERMAKE_CFG              0x0014           // Watermark Config

#define ZZ_DEV_NTP_CFG                    0x001D           // NTP Config

#define ZZ_DEV_NETCFG_EX                  0x005b           // Network Extended Config (ZZDEV_NET_CFG_EX)


#define ZZ_DEV_ENCODER_CFG_EX             0x007b           // Encoder Info Extended (ZZDEV_ENCODER_CFG_EX)
#define ZZ_DEV_ENCODER_CFG_EX2			  0x007c		   // Encoder Info Extended 2 (ZZDEV_ENCODER_CFG_EX2)








// Matrix Card Types (Combinable)
#define ZZ_MATRIX_CARD_MAIN                 0x10000000          // Main Card
#define ZZ_MATRIX_CARD_INPUT                0x00000001          // Input Card
#define ZZ_MATRIX_CARD_OUTPUT               0x00000002          // Output Card
#define ZZ_MATRIX_CARD_ENCODE               0x00000004          // Encode Card
#define ZZ_MATRIX_CARD_DECODE               0x00000008          // Decode Card
#define ZZ_MATRIX_CARD_CASCADE              0x00000010          // Cascade Card
#define ZZ_MATRIX_CARD_INTELLIGENT          0x00000020          // Intelligent Card
#define ZZ_MATRIX_CARD_ALARM                0x00000040          // Alarm Card
#define ZZ_MATRIX_CARD_RAID                 0x00000080          // Hardware RAID Card
#define ZZ_MATRIX_CARD_NET_DECODE           0x00000100          // Network Decode Card

// Matrix Card Info
typedef struct tagZZ_MATRIX_CARD
{
    DWORD               dwSize;
    BOOL                bEnable;                                // Enable
    DWORD               dwCardType;                             // Card Type
    char                szInterface[ZZ_MATRIX_INTERFACE_LEN];   // Signal Interface "CVBS", "VGA", "DVI"...
    char                szAddress[ZZ_MAX_IPADDR_OR_DOMAIN_LEN]; // IP or Domain
    int                 nPort;                                  // Port
    int                 nDefinition;                            // Definition, 0=SD, 1=HD
    int                 nVideoInChn;                            // Video In Count
    int                 nAudioInChn;                            // Audio In Count
    int                 nVideoOutChn;                           // Video Out Count
    int                 nAudioOutChn;                           // Audio Out Count
    int                 nVideoEncChn;                           // Video Enc Count
    int                 nAudioEncChn;                           // Audio Enc Count
    int                 nVideoDecChn;                           // Video Dec Count
    int                 nAudioDecChn;                           // Audio Dec Count
    int                 nStauts;                                // Status: -1-Unknown, 0-Normal, 1-No Response, 2-Offline, 3-Conflict, 4-Upgrading, 5-Link Error, 6-Backplane Error, 7-Version Error
    int                 nCommPorts;                             // Serial Port Count
    int                 nVideoInChnMin;                         // Video In Min
    int                 nVideoInChnMax;                         // Video In Max
    int                 nAudioInChnMin;                         // Audio In Min
    int                 nAudioInChnMax;                         // Audio In Max
    int                 nVideoOutChnMin;                        // Video Out Min
    int                 nVideoOutChnMax;                        // Video Out Max
    int                 nAudioOutChnMin;                        // Audio Out Min
    int                 nAudioOutChnMax;                        // Audio Out Max    
    int                 nVideoEncChnMin;                        // Video Enc Min
    int                 nVideoEncChnMax;                        // Video Enc Max
    int                 nAudioEncChnMin;                        // Audio Enc Min
    int                 nAudioEncChnMax;                        // Audio Enc Max
    int                 nVideoDecChnMin;                        // Video Dec Min
    int                 nVideoDecChnMax;                        // Video Dec Max
    int                 nAudioDecChnMin;                        // Audio Dec Min
    int                 nAudioDecChnMax;                        // Audio Dec Max
    int                 nCascadeChannels;                       // Cascade Channels
    int                 nCascadeChannelBitrate;                 // Cascade Bitrate Mbps
    int                 nAlarmInChnCount;                       // Alarm In Count
    int                 nAlarmInChnMin;                         // Alarm In Min
    int                 nAlarmInChnMax;                         // Alarm In Max
    int                 nAlarmOutChnCount;                      // Alarm Out Count
    int                 nAlarmOutChnMin;                        // Alarm Out Min
    int                 nAlarmOutChnMax;                        // Alarm Out Max
    int                 nVideoAnalyseChnCount;                  // Analysis Channel Count
    int                 nVideoAnalyseChnMin;                    // Analysis Channel Min
    int                 nVideoAnalyseChnMax;                    // Analysis Channel Max
    int                 nCommPortMin;                           // Comm Port Min
    int                 nCommPortMax;                           // Comm Port Max
    char                szVersion[ZZ_COMMON_STRING_32];         // Version
    ZZNET_TIME          stuBuildTime;                           // Build Time
    char                szBIOSVersion[ZZ_COMMON_STRING_64];     // BIOS Version
    char				szMAC[ZZ_MACADDR_LEN];					// MAC
} ZZ_MATRIX_CARD;

// Matrix Card List
typedef struct tagZZ_MATRIX_CARD_LIST 
{
    DWORD               dwSize;
    int                 nCount;                                 // Count
    ZZ_MATRIX_CARD      stuCards[ZZ_MATRIX_MAX_CARDS];          // List
} ZZ_MATRIX_CARD_LIST;








// Get Power Sequencer Capability Input
typedef struct tagZZNET_IN_CAP_SEQPOWER 
{
    DWORD                dwSize;
    const char*          pszDeviceID;                       // Device ID
} ZZNET_IN_CAP_SEQPOWER;

// Get Power Sequencer Capability Output
typedef struct tagZZNET_OUT_CAP_SEQPOWER
{
    DWORD                dwSize;
    int                  nChannelNum;                       // Channel Count
} ZZNET_OUT_CAP_SEQPOWER;

// Get Encode Config Caps Input
typedef struct tagZZNET_IN_ENCODE_CFG_CAPS
{
    DWORD               dwSize;           
    int                 nChannelId;                         // Channel ID    
    int                 nStreamType;                        // Stream Type 0:Main; 1:Sub1; 2:Sub2; 3:Sub3; 4:Snapshot
                                                            // Optional. Device returns capabilities for Main, Sub, Snapshot regardless.
    char*               pchEncodeJson;                      // Encode Config JSON, encapsulated via ZZNETSDK_PacketData
                                                            // Command: ZZ_CFG_CMD_ENCODE                 
}ZZNET_IN_ENCODE_CFG_CAPS;



// Stream Config Caps
typedef struct tagZZNET_STREAM_CFG_CAPS
{
    DWORD               dwSize;
    int                 nAudioCompressionTypes[ZZ_MAX_AUDIO_ENCODE_TYPE]; // Supported Audio Types
    int                 nAudioCompressionTypeNum;                   // Audio Type Count
    int                 dwEncodeModeMask;                           // Encode Mode Mask
    ZZ_RESOLUTION_INFO  stuResolutionTypes[ZZ_MAX_CAPTURE_SIZE_NUM];// Supported Resolutions
    int                 nResolutionFPSMax[ZZ_MAX_CAPTURE_SIZE_NUM]; // Max FPS per Resolution 
    int                 nResolutionTypeNum;                         // Resolution Count
    int                 nMaxBitRateOptions;                         // Max Bitrate (kbps) 
    int                 nMinBitRateOptions;                         // Min Bitrate (kbps)
    BYTE                bH264ProfileRank[ZZ_PROFILE_HIGH];          // Supported H.264 Profiles  
    int                 nH264ProfileRankNum;                        // Profile Count
    int                 nCifPFrameMaxSize;                          // Max P-Frame size for CIF (Kbps)
    int                 nCifPFrameMinSize;                          // Min P-Frame size for CIF (Kbps)
    int                 nFPSMax;                                    // Max FPS, if 0 check nResolutionFPSMax
    ZZ_RESOLUTION_INFO  stuIndivResolutionTypes[ZZ_MAX_COMPRESSION_TYPES_NUM][ZZ_MAX_CAPTURE_SIZE_NUM];// Supported Resolutions
	BOOL				abIndivResolution;							// 0: stuResolutionTypes valid 
                                                                    // 1: stuIndivResolutionTypes valid
    int                 nIndivResolutionNums[ZZ_MAX_COMPRESSION_TYPES_NUM];// Resolution count per compression
}ZZNET_STREAM_CFG_CAPS;

// Get Encode Config Caps Output
typedef struct tagZZNET_OUT_ENCODE_CFG_CAPS
{
    DWORD               dwSize;
    ZZNET_STREAM_CFG_CAPS stuMainFormatCaps[ZZ_REC_TYPE_NUM];         // Main Stream Caps (Normal, Motion, Alarm)
    ZZNET_STREAM_CFG_CAPS stuExtraFormatCaps[ZZ_N_ENCODE_AUX];        // Sub Stream Caps (Sub1, Sub2, Sub3)
    ZZNET_STREAM_CFG_CAPS stuSnapFormatCaps[ZZ_SNAP_TYP_NUM];         // Snapshot Caps (Normal, Motion, Alarm)
    int                 nMainFormCaps;                              // Valid Main Caps Count
    int                 nExtraFormCaps;                             // Valid Sub Caps Count
    int                 nSnapFormatCaps;                            // Valid Snapshot Caps Count
}ZZNET_OUT_ENCODE_CFG_CAPS;

// Get Fisheye Caps Input
typedef struct tagZZNET_IN_VIDEOIN_FISHEYE_CAPS
{
    DWORD                dwSize; 
    int                  nChannel;  // Channel
}ZZNET_IN_VIDEOIN_FISHEYE_CAPS;

// Get Fisheye Caps Output
typedef struct tagZZNET_OUT_VIDEOIN_FISHEYE_CAPS
{
    DWORD                       	dwSize; 
    int                         	nMountModeNum;                     // Supported Mount Mode Count         
    ZZNET_FISHEYE_MOUNT_MODE        emMountModes[ZZNET_MAX_FISHEYE_MOUNTMODE_NUM]; // Supported Mount Modes
    int                         	nCalibrateModeNum;                 // Supported Correction Mode Count  
    ZZNET_FISHEYE_CALIBRATE_MODE    emCalibrateModes[ZZNET_MAX_FISHEYE_CALIBRATEMODE_NUM]; // Supported Correction Modes
    int                         	nEPtzCmdNum;                       // Supported E-PTZ Command Count 
    ZZNET_FISHEYE_EPTZ_CMD          emEPtzCmds[ZZNET_MAX_FISHEYE_EPTZCMD_NUM]; // Supported E-PTZ Commands
    ZZNET_FISHEYE_TYPE        		emType;                                 // Fisheye Type
}ZZNET_OUT_VIDEOIN_FISHEYE_CAPS;

// Get Composite Caps Input
typedef struct tagZZNET_IN_COMPOSITE_CAPS 
{
    DWORD           dwSize;
    int             nChannelCount;                          // Window Count to Composite
    int             nChannels[ZZNET_MAX_COMPOSITE_CHANNEL];   // Channel List
    int             nLayoutX;                               // Horizontal Window Count
    int             nLayoutY;                               // Vertical Window Count
} ZZNET_IN_COMPOSITE_CAPS;

// Get Composite Caps Output
typedef struct tagZZNET_OUT_COMPOSITE_CAPS 
{
    DWORD           dwSize;
    int             nSplitModeCount;                        // Supported Split Mode Count
    ZZ_SPLIT_MODE   emSplitModes[ZZ_MAX_SPLIT_MODE_NUM];    // Supported Split Modes
    int             nMaxFreeWindow;                         // Max Free Windows
} ZZNET_OUT_COMPOSITE_CAPS;

// Get Video Detect Caps Input
typedef struct tagZZNET_IN_VIDEO_DETECT_CAPS
{
    DWORD               dwSize;           
    int                 nChannel;  // Channel 
}ZZNET_IN_VIDEO_DETECT_CAPS;

typedef enum tagEM_ZZ_DETECT_VERSION_TYPE
{
    EM_ZZ_DETECT_VERSION_UNKNOW = 0 , 
    EM_ZZ_DETECT_VERSION_V1_0 ,           // Ver 1.0 Motion Detect
    EM_ZZ_DETECT_VERSION_V3_0 ,           // Ver 3.0 Motion Detect
}EM_ZZ_DETECT_VERSION_TYPE;

typedef enum tagEM_ZZ_BLIND_DETECT_VERSION_TYPE
{
    EM_ZZ_BLIND_DETECT_VERSION_UNKNOW = 0 ,
    EM_ZZ_BLIND_DETECT_VERSION_FULL_SCREEN ,   // Full Screen Blind
    EM_ZZ_BLIND_DETECT_VERSION_MULTI_WINDOW ,  // Multi Window Blind
}EM_ZZ_BLIND_DETECT_VERSION_TYPE;


typedef struct tagZZNET_OUT_VIDEO_DETECT_CAPS
{
        DWORD                       dwSize;         
        BOOL                        bSupportBlind;          // Support Blind Detect
        BOOL                        bSupportLoss;           // Support Video Loss Detect
        BOOL                        bSupportMotion;         // Support Motion Detect
        BOOL                        bMotionResult;          // Support Region Result
        DWORD                       nMotionColumns;         // Motion Grid Columns
        DWORD                       nMotionRows;            // Motion Grid Rows
        DWORD                       nMotionDetectWindow;    // Motion Detect Windows
        DWORD                       nBlindColumns;          // Blind Grid Columns
        DWORD                       nBlindRows;             // Blind Grid Rows
        DWORD                       nBlindDetectWindow;     // Blind Detect Windows
        BOOL                        bPositionDetect;        // Support Position Detect
        DWORD                       nDetectVersionNum;      // Detect Version Count
        EM_ZZ_DETECT_VERSION_TYPE      emDetectVersions[ZZ_MAX_DETECT_VERSION_NUM];               // Detect Versions
        DWORD                       nBlindDetectVersionNum; // Blind Version Count
        EM_ZZ_BLIND_DETECT_VERSION_TYPE emBlindDetectVersions[ZZ_MAX_BLIND_DETECT_VERSION_NUM];   // Blind Versions
        BOOL                        bMotionLinkPtzPreset;   // Motion Link PTZ Preset
        BOOL                        bMotionLinkPtzTour;     // Motion Link PTZ Tour
        BOOL                        bMotionLinkPtzPattern;  // Motion Link PTZ Pattern
        BOOL                        bUnFocusDetect;         // Support Defocus Detect
        BOOL                        bAlarmDetect;           // Support Alarm Trigger with Motion
		BOOL						bSupportMoveDetect;		// Support Scene Change Detect
}ZZNET_OUT_VIDEO_DETECT_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_THERMO_GRAPHY_CAPS Input
typedef struct tagZZNET_IN_THERMO_GETCAPS
{
    DWORD               dwSize;
    int                 nChannel;                           // Channel
} ZZNET_IN_THERMO_GETCAPS;

// ZZNETSDK_GetDevCaps ZZNET_THERMO_GRAPHY_CAPS Output
typedef struct tagZZNET_OUT_THERMO_GETCAPS
{
    DWORD               dwSize;
    DWORD               dwModes;                            // Preset Mode Mask
    DWORD               dwColorization;                     // Preset Colorization Mask
    DWORD               dwROIModes;                         // Preset ROI Mask
    ZZRANGE             stBrightness;                       // Brightness Cap
    ZZRANGE             stSharpness;                        // Sharpness Cap
    ZZRANGE             stEZoom;                            // Zoom Cap
    ZZRANGE             stThermographyGamma;                // Gamma Cap
    ZZRANGE             stSmartOptimizer;                   // Optimizer Cap
} ZZNET_OUT_THERMO_GETCAPS;

// ZZNETSDK_GetDevCaps ZZNET_RADIOMETRY_CAPS Input
typedef struct tagZZNET_IN_RADIOMETRY_GETCAPS
{
    DWORD               dwSize;
    int                 nChannel;                           // Channel
} ZZNET_IN_RADIOMETRY_GETCAPS;

// Temperature Measurement Type
typedef enum tagZZNET_RADIOMETRY_METERTYPE 
{
    ZZNET_RADIOMETRY_METERTYPE_UNKNOWN,
    ZZNET_RADIOMETRY_METERTYPE_SPOT,                          // Spot
    ZZNET_RADIOMETRY_METERTYPE_LINE,                          // Line
    ZZNET_RADIOMETRY_METERTYPE_AREA,                          // Area
} ZZNET_RADIOMETRY_METERTYPE;

// Spot, Line, Area Total Count Capability
typedef struct tagZZNET_RADIOMETRY_TOTALNUM 
{
    DWORD               dwMaxNum;                           // Max Total
    DWORD               dwMaxSpots;                         // Max Spots
    DWORD               dwMaxLines;                         // Max Lines
    DWORD               dwMaxAreas;                         // Max Areas
    char				reserved[32]; 
} ZZNET_RADIOMETRY_TOTALNUM;

// ZZNETSDK_GetDevCaps ZZNET_RADIOMETRY_CAPS Output
typedef struct tagZZNET_OUT_RADIOMETRY_GETCAPS
{
    DWORD                       dwSize;
    ZZNET_RADIOMETRY_TOTALNUM   stTotalNum;                 // Total Num Caps
    DWORD                       dwMaxPresets;               // Max Presets
    DWORD                       dwMeterType;                // Meter Type Mask
    ZZRANGE                     stObjectEmissivity;         // Emissivity Cap
    ZZRANGE                     stObjectDistance;           // Distance Cap
    ZZRANGE                     stReflectedTemperature;     // Reflected Temp Cap
    ZZRANGE                     stRelativeHumidity;         // Humidity Cap
    ZZRANGE                     stAtmosphericTemperature;   // Atmospheric Temp Cap
    int                         nStatisticsMinPeriod;       // Min Stat Period (seconds)
    float                       fIsothermMaxTemp;           // Isotherm Max Temp
    float                       fIsothermMinTemp;           // Isotherm Min Temp
} ZZNET_OUT_RADIOMETRY_GETCAPS;

// ZZNETSDK_GetDevCaps ZZNET_POS_CAPS Input
typedef struct tagZZNET_IN_POS_GETCAPS
{
    DWORD               dwSize;
} ZZNET_IN_POS_GETCAPS;


// POS Connection Type
typedef enum tagEM_ZZ_CONN_TYPE
{
    EM_ZZ_CONN_TYPE_UNKNOWN,                            // Unknown
    EM_ZZ_CONN_TYPE_NET,                                // Network
    EM_ZZ_CONN_TYPE_RS232,                              // RS232
    EM_ZZ_CONN_TYPE_RS485,                              // RS485
} EM_ZZ_CONN_TYPE;

// POS Protocol
typedef enum tagEM_ZZ_CONN_PROT
{
    EM_ZZ_CONN_PROT_UNKNOWN,                            // Unknown
    EM_ZZ_CONN_PROT_NONE,                               // Custom
    EM_ZZ_CONN_PROT_POS,                                // POS
} EM_ZZ_CONN_PROT;

// ZZNETSDK_GetDevCaps ZZNET_POS_CAPS Output
typedef struct tagZZNET_OUT_POS_GETCAPS
{
    DWORD               dwSize;
    EM_ZZ_CONN_TYPE     emConnType[10];                    // Connection Types
    int                 nConnTypeNum;                      // Type Count
    EM_ZZ_CONN_PROT     emConnProt[10];                    // Protocols
    int                 nConnProtNum;                      // Protocol Count
    int                 nMaxPos;                           // Max POS Devices
	BOOL				bSupportPosRecord;				   // Support POS Record
} ZZNET_OUT_POS_GETCAPS;

// ZZNETSDK_GetDevCaps ZZNET_USER_MNG_CAPS Input
typedef struct tagZZNET_IN_USER_MNG_GETCAPS
{
    DWORD               dwSize;
} ZZNET_IN_USER_MNG_GETCAPS;

// ZZNETSDK_GetDevCaps ZZNET_USER_MNG_CAPS Output
typedef struct tagZZNET_OUT_USER_MNG_GETCAPS
{
    DWORD               dwSize;
    BOOL                bAccountLimitation;							// Account Limitation (Control concurrent requests)
    BOOL                bIndividualAccessFilter;					// Support Individual IP Filtering (Black/White list)
    DWORD               dwMaxPageSize;								// Max Users per Page Query
	unsigned int		nMaxPwdLen;									// Max Pwd Length
	unsigned int		nMinPwdLen;									// Min Pwd Length	
	char				szType[ZZ_MAX_PWD_BASIC_CHARS_ARRAY_LEN];		// Supported Char Types: "Number,Lower,Upper"
	char				szCharList[ZZ_MAX_PWD_SPEC_CHARS_ARRAY_LEN];	// Supported Special Chars e.g. "~!@#$%^" 
	int					nCombine;									// Pwd Combination Requirement: 0-None; 1-Must have special char; 2-At least 2 types
} ZZNET_OUT_USER_MNG_GETCAPS;

// Media Cap Type
typedef enum tagZZNET_MEDIA_CAP_TYPE
{
    ZZNET_MEDIA_CAP_TYPE_SENSORINFO,      // Sensor Info
} ZZNET_MEDIA_CAP_TYPE;

// ZZNETSDK_GetDevCaps ZZNET_MEDIAMANAGER_CAPS Input
typedef struct tagZZNET_IN_MEDIAMANAGER_GETCAPS
{
    DWORD               dwSize;
    ZZNET_MEDIA_CAP_TYPE  emType;         // Cap Type
} ZZNET_IN_MEDIAMANAGER_GETCAPS;

// Camera Sensor Type
typedef enum tagZZNET_CAMERA_SENSOR
{
    ZZNET_CAMERA_SENSOR_NORMAL,           // Normal (Visible)
    ZZNET_CAMERA_SENSOR_LEPTON,           // Lepton Thermal
    ZZNET_CAMERA_SENSOR_TAU,              // Tau Thermal
} ZZNET_CAMERA_SENSOR;

// Sensor Info
typedef struct tagZZNET_CAMERA_SENSORINFO
{
    ZZNET_CAMERA_SENSOR emSensorType;       // Sensor Type
    int                 nChannelsCount;     // Channel Count
    int                 nChannels[512];     // Channel List
    char                reserved[512];
} ZZNET_CAMERA_SENSORINFO;

// Media Info - Sensor
typedef struct tagZZNET_MEDIA_SENSORINFO
{
    BOOL                    bSupport;               // Supported
    int                     nSensorTypeCount;       // Sensor Type Count
    ZZNET_CAMERA_SENSORINFO   stuDetail[16];          // Details
    char                    reserved[1024];
} ZZNET_MEDIA_SENSORINFO;

// ZZNETSDK_GetDevCaps ZZNET_MEDIAMANAGER_CAPS Output
typedef struct tagZZNET_OUT_MEDIAMANAGER_GETCAPS
{
    DWORD                   dwSize;
    ZZNET_MEDIA_SENSORINFO    stuSensorInfo;          // Sensor Info
} ZZNET_OUT_MEDIAMANAGER_GETCAPS;

// ZZNETSDK_GetDevCaps  NET_VIDEO_MOSAIC_CAPS Input
typedef struct tagZZNET_IN_MEDIA_VIDEOMOSAIC_GETCAPS
{
	DWORD               dwSize;						// Size
} ZZNET_IN_MEDIA_VIDEOMOSAIC_GETCAPS;

// Dimensions
typedef struct tagZZ_SIZE 
{
	int					nWidth;							// Width
	int					nHeight;						// Height
} ZZ_SIZE;

// ZZNETSDK_GetDevCaps  NET_VIDEO_MOSAIC_CAPS Output
typedef struct tagZZNET_OUT_MEDIA_VIDEOMOSAIC_GETCAPS
{
	DWORD               dwSize;									// Size
	int					nSupportCount;							// Supported Channel Count
	short				snSupport[ZZ_MAX_MOSAIC_CHANNEL_NUM];		// Supported Channels, [-1] means all
	int					nMosaicCount;							// Mosaic Granularity Count
	char				szMosaic[ZZ_MAX_MOSAIC_NUM];				// Granularities
	ZZ_SIZE				stuRectMax;								// Max Block Size
	ZZ_SIZE				stuRectMin;								// Min Block Size
} ZZNET_OUT_MEDIA_VIDEOMOSAIC_GETCAPS;

// Get Encode Config Caps Input	 
typedef struct tagZZNET_IN_SNAP_CFG_CAPS	 	 	 
{        	 	 	 
    int                 nChannelId;                     // Channel ID (Start 0) 	 	 	 
    BYTE                bReserved[1024];                // Reserved	 	 	 
}ZZNET_IN_SNAP_CFG_CAPS;	 	  	 	 

#define ZZ_MAX_FPS_NUM                128                // Max FPS Count	 	 	 
#define ZZ_MAX_QUALITY_NUM            32                 // Max Quality Count	 	 	 

// Snapshot Config Caps		 	 	 
typedef struct tagZZNET_OUT_SNAP_CFG_CAPS 	 	 	 
{	 	 	 
    int                 nResolutionTypeNum;                // Resolution Info	 	 	 
    ZZ_RESOLUTION_INFO  stuResolutionTypes[ZZ_MAX_CAPTURE_SIZE_NUM];	 	 	 
    DWORD               dwFramesPerSecNum;                 // FPS Info	 	 	 
    int                 nFramesPerSecList[ZZ_MAX_FPS_NUM]; // -25: 1 frame per 25s; -24: 1 frame per 24s;	 	 	 
                                                           // 0: Invalid; 1: 1fps; 2: 2fps; 3: 3fps	 	 	 
                                                           // 4: 4fps; 5: 5fps; 17: 17fps; 18: 18fps	 	 	 
                                                           // 19: 19fps; 20: 20fps...	 	 	 
    DWORD               dwQualityMun;                      // Quality Info	 	 	 
    DWORD               nQualityList[ZZ_MAX_QUALITY_NUM];  // 1-6 (6 is highest) 	 	 
    DWORD               dwMode;                            // Mode Mask: Bit 1 Timing; Bit 2 Manual	 	 	 
    DWORD               dwFormat;                          // Format Mask: Bit 1 BMP; Bit 2 JPG	 	 	 
    BYTE                bReserved[2048];                   // Reserved	 	 	 
} ZZNET_OUT_SNAP_CFG_CAPS;

// Video In Capability Type
typedef enum tagZZNET_ENUM_VIDEOIN_CAP_TYPE
{
    ZZNET_VIDEOIN_CAP_TYPE_CONFLICT,                          // Conflict Capability, Out Param NET_OUT_VIDEOIN_CONFLICT_CAPS
}ZZNET_ENUM_VIDEOIN_CAP_TYPE;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_CAPS input parameter
typedef struct tagZZNET_IN_VIDEOIN_CAPS
{
    DWORD                               dwSize;
    int                                 nChannel;           // Channel
    ZZNET_ENUM_VIDEOIN_CAP_TYPE         emCapType;                   // Capability Type
}ZZNET_IN_VIDEOIN_CAPS;

// enumeration of conflict
typedef enum tagZZNET_ENUM_CONFLICT_TYPE
{
    ZZNET_ENUM_CONFLICT_TYPE_UNKNOWN,                          // Unknown
    ZZNET_ENUM_CONFLICT_TYPE_MAIN,                             // Main Stream
    ZZNET_ENUM_CONFLICT_TYPE_EXTRA1,                           // Sub Stream 1
    ZZNET_ENUM_CONFLICT_TYPE_EXTRA2,                           // Sub Stream 2
    ZZNET_ENUM_CONFLICT_TYPE_TVOUT,                            // Analog Output
    ZZNET_ENUM_CONFLICT_TYPE_DSP,                              // Intelligent
    ZZNET_ENUM_CONFLICT_TYPE_SMARTENC,                         // Smart Encode (Long GOP)
    ZZNET_ENUM_CONFLICT_TYPE_SETGOP,                           // Set GOP
    ZZNET_ENUM_CONFLICT_TYPE_ROI,                              // ROI
    ZZNET_ENUM_CONFLICT_TYPE_CBR,                              // CBR
    ZZNET_ENUM_CONFLICT_TYPE_SVC,                              // SVC
    ZZNET_ENUM_CONFLICT_TYPE_MJPEG,                            // MJPEG
    ZZNET_ENUM_CONFLICT_TYPE_ROTATE_90,                        // Rotate 90
}ZZNET_ENUM_CONFLICT_TYPE;

// Conflict
typedef struct tagZZNET_CONFLICT_TYPE
{
    ZZNET_ENUM_CONFLICT_TYPE    emConflict1;                 // Conflict 1              
    ZZNET_ENUM_CONFLICT_TYPE    emConflict2;                 // Conflict 2
    char                        reserved[64];
}ZZNET_CONFLICT_TYPE;

typedef struct tagZZNET_VIDEOIN_CONFLICT_CAPS
{
    BOOL                        bConflict;                  // Exists Conflict
    int                         nConflictNum;               // Conflict Count
    ZZNET_CONFLICT_TYPE         stuConflict[ZZ_MAX_VIDEOIN_CONFLICT_NUM];            // Conflicts
}ZZNET_VIDEOIN_CONFLICT_CAPS;

typedef struct tagZZNET_OUT_VIDEOIN_CAPS
{
    DWORD                       	dwSize;
    ZZNET_VIDEOIN_CONFLICT_CAPS   stuConflictCap;             // Conflict Struct
}ZZNET_OUT_VIDEOIN_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_FACE_BOARD_CAPS input parameter
typedef struct tagZZNET_IN_FACEBOARD_CAPS
{
    DWORD               dwSize;						            // Size
}ZZNET_IN_FACEBOARD_CAPS;

// temperature unit
typedef enum tagEM_ZZ_TEMPERATURE_UNIT
{
	EM_ZZ_TEMPERATURE_CENTIGRADE,			// Celsius
	EM_ZZ_TEMPERATURE_FAHRENHEIT,			// Fahrenheit
	EM_ZZ_TEMPERATURE_KELVIN,				// Kelvin
} EM_ZZ_TEMPERATURE_UNIT;

#define ZZ_MAX_UNIT_COUNT		8		// Max Units

// ZZNETSDK_GetDevCaps ZZNET_FACE_BOARD_CAPS Output
typedef struct tagZZNET_OUT_FACEBOARD_CAPS
{
    DWORD               	dwSize;						            // Size
    BOOL                	bHasBattery;                            // Has Battery
    BOOL                	bSupportPowerVoltageDetect;             // Support Voltage Detect
    BOOL					bTemperatures;							// Support Temp Sensor
    BOOL					bOSDTemperatureUnit;					// Support Temp Unit Selection
    int						nRetUnitCount;							// Actual Unit Count
    EM_ZZ_TEMPERATURE_UNIT		emTempreatureUnit[ZZ_MAX_UNIT_COUNT];		// Supported Units
}ZZNET_OUT_FACEBOARD_CAPS;

//ZZNETSDK_GetDevCaps interface ZZNET_EXTERNALSENSOR_CAPS Input
typedef struct tagZZNET_IN_EXTERNALSENSOR_CAPS
{
	DWORD				dwSize;
}ZZNET_IN_EXTERNALSENSOR_CAPS;

// External Sensor Networking Mode
typedef enum tagEM_ZZ_SENSOR_NERWORKING_MODE
{
	EM_ZZ_SENSOR_NERWORKING_MODE_UNKNOWN,			// Unknown
	EM_ZZ_SENSOR_NETWORKING_MODE_RS485,				// RS-485
	EM_ZZ_SENSOR_NETWORKING_MODE_RFID,				// RFID
}EM_ZZ_SENSOR_NERWORKING_MODE;

// ZZNETSDK_GetDevCaps interface ZZNET_EXTERNALSENSOR_CAPS Output
typedef struct tagZZNET_OUT_EXTERNALSENSOR_CAPS
{
	DWORD								dwSize;
	BOOL								bIsSupport;					// Supported
	EM_ZZ_SENSOR_NERWORKING_MODE		emNetworkingMode;			// Networking Mode
	int									nChannel;					// Max Collection Channels
}ZZNET_OUT_EXTERNALSENSOR_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEO_IMAGECONTROL_CAPS input parameter
typedef struct tagZZNET_IN_VIDEO_IMAGECONTROL_CAPS
{
	DWORD               dwSize;									// Size
	int					nChannel;								// Channel
} ZZNET_IN_VIDEO_IMAGECONTROL_CAPS;

// Stabilization Caps Type
typedef enum tagZZNET_EM_STABLE_CAPS_TYPE
{
	ZZ_EM_STABLE_UNSPPORT,					// Not Supported
	ZZ_EM_STABLE_ELEC,						// Electronic
	ZZ_EM_STABLE_LIGHT,						// Optical
	ZZ_EM_STAVLE_ELEC_AND_LIGHT,				// Electronic & Optical
	ZZ_EM_STABLE_CONTROL,					// Control (Plugin)
	ZZ_EM_STABLE_ELEC_AND_CONTROL,			// Electronic & Control
	ZZ_EM_STABLE_LIGHT_AND_CONTROL,			// Optical & Control
} ZZNET_EM_STABLE_CAPS_TYPE;

// ZZNETSDK_GetDevCaps ZZNET_VIDEO_IMAGECONTROL_CAPS output parameter
typedef struct tagZZNET_OUT_VIDEO_IMAGECONTROL_CAPS
{
	DWORD               			dwSize;							// Size
	BOOL							bSupport;						// True if any of Mirror, Flip, Rotate90 supported
	BOOL							bMirror;						// Mirror Support
	BOOL							bFlip;							// Flip Support
	BOOL							bRotate90;						// Rotate 90/270 Support
	BOOL							bFreeze;						// Freeze Support
	ZZNET_EM_STABLE_CAPS_TYPE		emStable;						// Stabilization Support
} ZZNET_OUT_VIDEO_IMAGECONTROL_CAPS;


// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_EXPOSURE_CAPS input parameter
typedef struct tagZZNET_IN_VIDEOIN_EXPOSURE_CAPS
{
	DWORD               dwSize;									// the size of this struct
	int					nChannel;								// channel ID
} ZZNET_IN_VIDEOIN_EXPOSURE_CAPS;

#define ZZ_MAX_EXPOSURE_COUNT	8

// the anti ficker mode
typedef enum tagZZNET_EM_ANTIFLICKER_MODE
{
	ZZNET_EM_ANTIFLICKER_OUTDOOR,		// Outdoor
	ZZNET_EM_ANTIFLICKER_50HZ,			// 50Hz
	ZZNET_EM_ANTIFLICKER_60HZ,			// 60Hz
} ZZNET_EM_ANTIFLICKER_MODE;


typedef struct tagZZNET_SPEED_CAPS
{
	int			nRetManual;								// Actual Manual Count
	int			nManual[ZZ_COMMON_STRING_16];			// Manual Shutter List
	int			nRetManual50Hz;							// Actual Manual Count (50Hz)
	int			nManual50Hz[ZZ_COMMON_STRING_16];		// Manual Shutter List (50Hz)
	int			nRetManual60Hz;							// Actual Manual Count (60Hz)
	int			nManual60Hz[ZZ_COMMON_STRING_16];		// Manual Shutter List (60Hz)
	int			nRetShutterPAL;							// Shutter Priority PAL Count
	int			nShutterPAL[ZZ_COMMON_STRING_16];		// Shutter Priority PAL List
	int			nRetShutterNTSC;						// Shutter Priority NTSC Count
	int			nShutterNTSC[ZZ_COMMON_STRING_16];		// Shutter Priority NTSC List
	BYTE		bReserved[128];							// Reserved
} ZZNET_SPEED_CAPS;

typedef struct tagZZNET_SLOW_SPEED_CAPS
{
	int			nRetPal;
	int			nPal[ZZ_COMMON_STRING_16];
	int			nRetNtsc;
	int			nNtsc[ZZ_COMMON_STRING_16];
	BYTE		bReserved[128];	
} ZZNET_SLOW_SPEED_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_EXPOSURE_CAPS output parameter
typedef struct tagZZNET_OUT_VIDEOIN_EXPOSURE_CAPS
{
	DWORD               		dwSize;									// Size
	BOOL						bSupport;								// Supported
	int							nExposureMode;							// Mode Count
	ZZNET_EM_EXPOSURE_MODE		emExposureMode[ZZ_MAX_EXPOSURE_COUNT];		// Modes
	BOOL						bAntiFlicker;							// Support Anti-Flicker
	int							nAntiFlicker;							// Anti-Flicker Count
	ZZNET_EM_ANTIFLICKER_MODE		emAntiFlicker[ZZ_MAX_ANTIFLICKERMODE_COUNT];	// Anti-Flicker Modes
	int							nMinCompensation;						// Min Compensation
	int							nMaxCompensation;						// Max Compensation
	BOOL						bGainUpperLimit;						// Gain Limit Support
																		// true: show option in auto, aperture, shutter priority.
																		// false: hide option
	int							nMinGain;								// Min Gain
	int							nMaxGain;								// Max Gain
	BOOL						bSlowAutoExposure;						// Slow Exposure Support (Default True)
																		// if false, do not send config; true/missing, send config
	int							nMinSlowAutoExposure;					// Min Slow Exp
	int							nMaxSlowAutoExposure;					// Max Slow Exp
	BOOL						bSlowShutter;							// Slow Shutter Support
	float						fMinValueLow;							// Auto Exposure Time Lower Min
	float						fMaxValueLow;							// Auto Exposure Time Lower Max
	float						fMinValueUp;							// Auto Exposure Time Upper Min
	float						fMaxValueUp;							// Auto Exposure Time Upper Max
	ZZNET_SPEED_CAPS			stuSpeedCaps;							// Speed Caps
	ZZNET_SLOW_SPEED_CAPS		stuSlowSpeedCaps;						// Slow Speed Caps
	BOOL						bIrisAuto;								// Auto Iris Support
	int							nIrisMin;								// Iris Min
	int							nIrisMax;								// Iris Max
	BOOL						bSupportIrisRange;						// Iris Range Adjustable
	BOOL						bDoubleExposure;						// ITC Double Shutter Support
	BOOL						bRecoveryTime;							// Auto Exposure Recovery Support
} ZZNET_OUT_VIDEOIN_EXPOSURE_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_DENOISE_CAPS input parameter
typedef struct tagZZNET_IN_VIDEOIN_DENOISE_CAPS
{
	DWORD				dwSize; 								// Size
	int 				nChannel;								// Channel
} ZZNET_IN_VIDEOIN_DENOISE_CAPS;

// the type of 3D denoise
typedef enum tagZZNET_EM_3DSUPPORT_TYPE
{
	ZZNET_EM_3DSUPPORT_UNKOWN,									// Unknown
	ZZNET_EM_3DSUPPORT_OFF,										// Off 
	ZZNET_EM_3DSUPPORT_AUTO,									// Auto 
	ZZNET_EM_3DSUPPORT_MANUAL,									// Manual
} ZZNET_EM_3DSUPPORT_TYPE;

// 3D Denoise Algo Modes
typedef struct tagZZNET_3D_ALGORITHM_MODE
{
	// Bitmask: bit0, bit1, bit2 correspond to algorithms. All 0 means no algorithm supported.
	DWORD	dwSingleExposure;				// Single Shutter
	DWORD	dwDoubleExposureFullRate;		// ITC Double Shutter Full Rate
	DWORD	dwDoubleExposureHalfRate;		// ITC Double Shutter Half Rate
	DWORD	dsThreeExposure;				// Three Shutter
	BYTE	bReserved[128];					// Reserved
} ZZNET_3DALGORITHM_MODE;

#define		ZZ_MAX_3DTYPE_COUNT			8			// Max 3D Types 
#define		ZZ_MAX_GROUP_COUNT			2			// Max Group
#define		ZZ_MAX_PROGRAM_COUNT		8			// Max Schemes

// 2D Denoise Caps
typedef struct tagZZNET_SUPPORT2D_CAPS
{
	BOOL						bSupport2D;								// 2D Support
	int							n2DLevelMin;							// Min Level
	int							n2DLevelMax;							// Max Level
	int							nMaxRAWLevel;							// Max RAW Domain Level, 0 means not supported
	BYTE						bReserved[128];							// Reserved
} ZZNET_SUPPORT2D_CAPS;

// the program of per denoise group
typedef struct tagZZNET_DENOISEGROUP_PROGRAM
{
	int							nProgramCount;								// Scheme Count
	int							nProgram[ZZ_MAX_PROGRAM_COUNT];			// Schemes
} ZZNET_DENOISEGROUP_PROGRAM;

// 3D Denoise Caps
typedef struct tagZZNET_SUPPORT3D_CAPS
{
	BOOL						bSupport3D;								// 3D Support
	int							n3DTypeCount;							// Type Count
	ZZNET_EM_3DSUPPORT_TYPE		em3DSupportType[ZZ_MAX_3DTYPE_COUNT];		// Types
	int							n3DLevelMin;							// Min Level
	int							n3DLevelMax;							// Max Level
	int							nAutoLevelMin;							// Auto Min
	int							nAutoLevelMax;							// Auto Max
	ZZNET_3DALGORITHM_MODE		stuAlgorithmSDMode;						// Algo Modes
	int							nGroupCount;							// Group Count
	ZZNET_DENOISEGROUP_PROGRAM	stuDenoiseGroup[ZZ_MAX_GROUP_COUNT]; 		// Groups, no reboot if switching within group, reboot otherwise
	int							nDenoiseScheme;							// Scheme: 1 New, 0 Old
	BYTE						bReserved[128];							// Reserved
} ZZNET_SUPPORT3D_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_DENOISE_CAPS Output
typedef struct tagZZNET_OUT_VIDEOIN_DENOISE_CAPS
{
	DWORD						dwSize; 								// Size
	BOOL						bSupport;								// Supported
	ZZNET_SUPPORT2D_CAPS		stu2DCaps;								// 2D Caps 
	ZZNET_SUPPORT3D_CAPS		stu3DCaps;								// 3D Caps
	BOOL						bSupportAlgorithm1;						// Support Algo 1
	int							nTnfLevelRangeMin;						// TNF Min
	int							nTnfLevelRangeMax;						// TNF Max
	int							nSnfLevelRangeMin;						// SNF Min
	int							nSnfLevelRangeMax;						// SNF Max
	int							nSeniotTypeCount;						// Senior Type Count
	ZZNET_EM_3DSUPPORT_TYPE		emSeniorType[ZZ_MAX_3DTYPE_COUNT];		// Senior Types
} ZZNET_OUT_VIDEOIN_DENOISE_CAPS;


// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_BACKLIGHT_CAPS Input
typedef struct tagZZNET_IN_VIDEOIN_BACKLIGHT_CAPS
{
	DWORD				dwSize; 								// Size
	int 				nChannel;								// Channel
} ZZNET_IN_VIDEOIN_BACKLIGHT_CAPS;

// SSA Intensity Mode
typedef enum tagZZNET_EM_BACK_INTENSITY_MODE
{
	ZZNET_EM_INTENSITY_UNKNOWN,			// Unknown
	ZZNET_EM_INTENSITY_OFF,				// Off
	ZZNET_EM_INTENSITY_AUTO,			// Auto
	ZZNET_EM_INTENSITY_MANUAL,			// Manual
} ZZNET_EM_BACK_INTENSITY_MODE;

// Glare Inhibition Mode (HLC)
typedef enum tagZZNET_EM_GLAREINHIBITION_MODE
{
	ZZNET_EM_GLAREINHIBITION_UNKNOWN,	// Unknown
	ZZNET_EM_GLAREINHIBITION_DEFAULT,	// Default
	ZZNET_EM_GLAREINHIBITION_FPGA,		// FPGA HLC
} ZZNET_EM_GLAREINHIBITION_MODE;

#define ZZ_MAX_MODE_COUNT		8		// Max Modes

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_BACKLIGHT_CAPS output parameter
typedef struct tagZZNET_OUT_VIDEOIN_BACKLIGHT_CAPS
{
	DWORD							dwSize; 								// Size
	BOOL							bSupport;								// Supported
	int								nBackModeCount;							// Mode Count
	ZZNET_EM_BACK_MODE				emBackMode[ZZ_MAX_MODE_COUNT];				// Modes
	int								nBackLightModeCount;					// BLC Mode Count
	ZZNET_EM_BLACKLIGHT_MODE		emBackLightMode[ZZ_MAX_MODE_COUNT];		// BLC Modes
	int								nWideDynamicRange;						// WDR Support
	int								nSSAIntensity;							// SSA Mode Count
	ZZNET_EM_BACK_INTENSITY_MODE	emIntensityMode[ZZ_MAX_MODE_COUNT];		// SSA Modes
	ZZNET_EM_GLAREINHIBITION_MODE	emGlareInhibition[ZZ_MAX_MODE_COUNT];		// HLC Modes
} ZZNET_OUT_VIDEOIN_BACKLIGHT_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_WHITEBALANCE_CAPS Input
typedef struct tagZZNET_IN_VIDEOIN_WHITEBALANCE_CAPS
{
	DWORD				dwSize; 								// the size of this struct
	int 				nChannel;								// channel ID
} ZZNET_IN_VIDEOIN_WHITEBALANCE_CAPS;

#define ZZ_MAX_BALANCEMODES_COUNT			16		// the max counts of white balance modes

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_WHITEBALANCE_CAPS output param
typedef struct tagZZNET_OUT_VIDEOIN_WHITEBALANCE_CAPS
{
	DWORD								dwSize; 								// Size
	BOOL								bSupport;								// Supported
	int									nWhiteBalance;							// Mode Count
	ZZNET_EM_WHITEBALANCE_TYPE			emWhiteBalance[ZZ_MAX_BALANCEMODES_COUNT];	// Modes
} ZZNET_OUT_VIDEOIN_WHITEBALANCE_CAPS;


// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_DAYNIGHT_CAPS input param
typedef struct tagZZNET_IN_VIDEOIN_DAYNIGHT_CAPS
{
	DWORD				dwSize; 								// the size of this struct
	int 				nChannel;								// channel ID
} ZZNET_IN_VIDEOIN_DAYNIGHT_CAPS;

// ICR switch type
typedef enum tagZZNET_EM_ICR_TYPE
{
	ZZNET_EM_ICR_UNKONOW,		// Unknown
	ZZNET_EM_ICR_ELECTRON,		// Electronic
	ZZNET_EM_ICR_MECHANISM,		// Mechanical
} ZZNET_EM_ICR_TYPE;

// color to black
typedef enum tagZZNET_EM_COLORBLACK_MODE
{
	ZZNET_EM_COLORBLACK_UNKNOWN,				// Unknown
	ZZNET_EM_COLORBLACK_COLOR,					// Always Color
	ZZNET_EM_COLORBLACK_BRIGHTNESS,				// Auto by Brightness
	ZZNET_EM_COLORBLACK_BLACKWHITE,				// Always B/W
	ZZNET_EM_COLORBLACK_PHOTORESISTOR,			// Photoresistor
	ZZNET_EM_COLORBLACK_GAIN,					// By Gain
	ZZNET_EM_COLORBLACK_ALARMINPUT,				// Alarm Input
	ZZNET_EM_COLORBLACK_IO,						// IO Input
} ZZNET_EM_COLORBLACK_MODE;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_DAYNIGHT_CAPS Output
typedef struct tagZZNET_OUT_VIDEOIN_DAYNIGHT_CAPS
{
	DWORD						dwSize; 								// Size
	BOOL						bSupport;								// Supported
	int							nICRType;								// ICR Type Count
	ZZNET_EM_ICR_TYPE			emICRType[ZZ_MAX_MODE_COUNT];			// ICR Types
	int							nColorBlackMode;						// C/B Mode Count
	ZZNET_EM_COLORBLACK_MODE	emColorBlackMode[ZZ_MAX_MODE_COUNT];	// C/B Modes
	int							nSensitivityRangeMin;					// Sensitivity Min
	int							nSensitivityRangeMax;					// Sensitivity Max
	int							nDelayRangeMin;							// Delay Min
	int							nDelayRangeMax;							// Delay Max
} ZZNET_OUT_VIDEOIN_DAYNIGHT_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_ZOOM_CAPS Input
typedef struct tagZZNET_IN_VIDEOIN_ZOOM_CAPS
{
	DWORD				dwSize; 								// Size
	int 				nChannel;								// Channel
} ZZNET_IN_VIDEOIN_ZOOM_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_ZOOM_CAPS Output
typedef struct tagZZNET_OUT_VIDEOIN_ZOOM_CAPS
{
	DWORD						dwSize; 								// Size

	BOOL						bSupport;								// Supported
	int							nSpeedRangeMin;							// Speed Min
	int 						nSpeedRangeMax;							// Speed Max
	BOOL						bDigitalZoomSupport;					// Digital Zoom Support
	int							nZoomLimitRangeMin;						// Limit Range Min	
	int							nZoomLimitRangeMax;						// Limit Range Max
} ZZNET_OUT_VIDEOIN_ZOOM_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_FOCUS_CAPS Input
typedef struct tagZZNET_IN_VIDEOIN_FOCUS_CAPS
{
	DWORD				dwSize; 								// Size
	int 				nChannel;								// Channel
} ZZNET_IN_VIDEOIN_FOCUS_CAPS;

// Focus Mode
typedef enum tagZZNET_EM_FOCUS_MODE
{
	ZZNET_EM_FOCUS_OFF,				// Off
	ZZNET_EM_FOCUS_ASSIST,			// Assist
	ZZNET_EM_FOCUS_AUTO,			// Auto
	ZZNET_EM_FOCUS_SEMI_AUTO,		// Semi-Auto
	ZZNET_EM_FOCUS_MANUAL,			// Manual
} ZZNET_EM_FOCUS_MODE;

// focus limit select mode
typedef enum tagZZNET_EM_FOCUS_LIMITSELECT_MODE
{
	ZZNET_EM_FOCUS_LIMITSELECT_UNKNOW,			// Unknown
	ZZNET_EM_FOCUS_LIMITSELECT_MANUAL,			// Manual
	ZZNET_EM_FOCUS_LIMITSELECT_AUTO,			// Auto
} ZZNET_EM_FOCUS_LIMITSELECT_MODE;

// focus type
typedef enum tagZZNET_EM_FOCUS_TYPE
{
	ZZNET_EM_FOCUS_UNKNOWN,						// Unknown
	ZZNET_EM_FOCUS_AUTOTRACE,					// Auto Trace
} ZZNET_EM_FOCUS_TYPE;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_FOCUS_CAPS Output
typedef struct tagZZNET_OUT_VIDEOIN_FOCUS_CAPS
{
	DWORD							dwSize; 								// Size
	BOOL							bSupport;								// Supported
	int								nFcousMode;								// Mode Count
	ZZNET_EM_FOCUS_MODE				emFocusMode[ZZ_MAX_MODE_COUNT];			// Modes
	int								nLimitMode;								// Limit Mode Count
	ZZNET_EM_FOCUS_LIMITSELECT_MODE	emLimitMode[ZZ_MAX_MODE_COUNT];			// Limit Modes
	BOOL							bSupportFocusRegion;					// Region Focus Support
	BOOL							bSensitivity;							// Sensitivity Support
	BOOL							bIRCorrection;							// IR Correction Support
	BOOL							bFocusLimit;							// Focus Limit Support
	int								nFocusTypeCount;						// Type Count
	ZZNET_EM_FOCUS_TYPE				emFocusType[ZZ_MAX_MODE_COUNT];			// Types
} ZZNET_OUT_VIDEOIN_FOCUS_CAPS;

//// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_SHARPNESS_CAPS Input
typedef struct tagZZNET_IN_VIDEOIN_SHARPNESS_CAPS
{
	DWORD				dwSize; 								// the size of this struct
	int 				nChannel;								// channel ID
} ZZNET_IN_VIDEOIN_SHARPNESS_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_SHARPNESS_CAPS Output
typedef struct tagZZNET_OUT_VIDEOIN_SHARPNESS_CAPS
{
	DWORD						dwSize; 								// Size
	BOOL						bSupport;								// Supported
	int							nSharpnessMode;							// Mode Count
	ZZNET_EM_SHARPNESS_MODE		emSharpnessMode[ZZ_MAX_MODE_COUNT];		// Modes
	int							nSharpnessMin;							// Min
	int							nSharpnessMax;							// Max

	BOOL						bSupportRestrain;						// Restrain Support
	int							nRestrainLevelMin;						// Restrain Min
	int							nRestrainLevelMax;						// Restrain Max
} ZZNET_OUT_VIDEOIN_SHARPNESS_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_COLOR_CAPS Input
typedef struct tagZZNET_IN_VIDEOIN_COLOR_CAPS
{
	DWORD				dwSize; 								// Size
	int 				nChannel;								// Channel
} ZZNET_IN_VIDEOIN_COLOR_CAPS;

// Image Style Cap Type
typedef enum tagZZNET_EM_STYLE_TYPE
{
	ZZNET_EM_STYLE_UNKONWON,		// Unknown
	ZZNET_EM_STYLE_GENTLE,			// Gentle
	ZZNET_EM_STYLE_STANDARD,		// Standard
	ZZNET_EM_STYLE_FLAMBOYANT,		// Flamboyant
} ZZNET_EM_STYLE_TYPE;

// Image Style Caps
typedef struct tagZZNET_COLOR_STYLE_CAPS
{
	BOOL				bSupport;								// Supported
	int					nStyleType;								// Type Count
	ZZNET_EM_STYLE_TYPE	emStyleType[ZZ_MAX_MODE_COUNT];			// Types
	BYTE				bReserved[128];							// Reserved
} ZZNET_COLOR_STYLE_CAPS;

#define ZZ_MAX_GRAYVALUE_COUNT			8  // Max Gray Values

// Gray Scale Caps
typedef struct tagZZNET_GRAY_SCALE_CAPS
{
	BOOL				bSupport;								// Supported
	int					nValueCount;							// Group Count
	int					nValue[ZZ_MAX_GRAYVALUE_COUNT][2];		// Min/Max of Range
	BYTE				bReserved[128];							// Reserved
} ZZNET_GRAY_SCALE_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_COLOR_CAPS Output
typedef struct tagZZNET_OUT_VIDEOIN_COLOR_CAPS
{
	DWORD					dwSize; 							// Size
	BOOL					bSupport;							// Supported
	BOOL					bBrightness;						// Brightness
	BOOL					bContrast;							// Contrast
	BOOL					bSaturation;						// Saturation
	BOOL					bHue;								// Hue
	BOOL					bGamma;								// Gamma
	BOOL					bChromaSuppress;					// Chroma Suppress
	ZZNET_COLOR_STYLE_CAPS	stuColorStype;						// Color Style Caps
	ZZNET_GRAY_SCALE_CAPS	stuGrayScale;						// Gray Scale Caps
} ZZNET_OUT_VIDEOIN_COLOR_CAPS;

// ZZNETSDK_GetDevCaps interface ZZNET_GET_MASTERSLAVEGROUP_CAPS Input
typedef struct tagZZNET_IN_GET_MASTERSLAVEGROUP_CAPS
{
	DWORD				dwSize;
}ZZNET_IN_GET_MASTERSLAVEGROUP_CAPS;

typedef enum tagEM_ZZ_MASTERSLAVEGROUP_MODE
{
	EM_ZZ_MASTERSLAVEGROUP_MODE_UNKNOWN,		//  Unknown
	EM_ZZ_MASTERSLAVEGROUP_MODE_COMMANDER,	    //  Commander, e.g., the Box Camera in a Box+Dome setup
	EM_ZZ_MASTERSLAVEGROUP_MODE_PROPOSER,       //  Proposer, the Box Camera in 2-Box+1-Dome setup
	EM_ZZ_MASTERSLAVEGROUP_MODE_JUDGE,			//  Judge, the Dome Camera in 2-Box+1-Dome setup
	EM_ZZ_MASTERSLAVEGROUP_MODE_HAWKEYE,		//  HawkEye
	EM_ZZ_MASTERSLAVEGROUP_MODE_MULTISENSOR,	//  MultiSensor, different calibration algo, different fields
	EM_ZZ_MASTERSLAVEGROUP_MODE_GLOBALCAMERA,	//  GlobalCamera, Box+Dome Integrated
	EM_ZZ_MASTERSLAVEGROUP_MODE_NEWCOMMANDER,   //  NewCommander, uses CalibrateMatrix(MultiSensor)
	EM_ZZ_MASTERSLAVEGROUP_MODE_NEWHAWEYE,      //  NewHawEye (Watcher), uses CalibrateMatrix(MultiSensor)
}EM_ZZ_MASTERSLAVEGROUP_MODE;

// ZZNETSDK_GetDevCaps interface ZZNET_GET_MASTERSLAVEGROUP_CAPS Output
typedef struct tagZZNET_OUT_GET_MASTERSLAVEGROUP_CAPS
{
	DWORD									dwSize;
	EM_ZZ_MASTERSLAVEGROUP_MODE				emRole;
}ZZNET_OUT_GET_MASTERSLAVEGROUP_CAPS;

// ZZNETSDK_GetDevCaps (ZZNET_FACERECOGNITIONSE_CAPS) input parameter
typedef struct tagZZNET_IN_FACERECOGNITIONSERVER_CAPSBILITYQUERY
{
    DWORD               dwSize;				// struct size
} ZZNET_IN_FACERECOGNITIONSERVER_CAPSBILITYQUERY;


// ZZNETSDK_GetDevCaps (ZZNET_FACERECOGNITIONSE_CAPS) Output
typedef struct tagZZNET_OUT_FACERECOGNITIONSERVER_CAPSBILITYQUERY
{
    DWORD               dwSize;				// Size
	BOOL				bmultiFind;			// Multi Channel Find Support
	UINT				nmaxFaceType;		// Max Custom Face Types
} ZZNET_OUT_FACERECOGNITIONSERVER_CAPSBILITYQUERY;

// ZZNETSDK_GetDevCaps interface ZZNET_STORAGE_CAPS command parameter
typedef struct tagZZNET_IN_STORAGE_CAPS
{
	DWORD									dwSize;
}ZZNET_IN_STORAGE_CAPS;

// Format Reboot Requirement
typedef enum tagZZNET_EM_FORMAT_NEEDREBOOT
{
	ZZNET_EM_FORMAT_NEEDREBOOT_UNKNOWN,						// Unknown
	ZZNET_EM_FORMAT_NEEDREBOOT_NOREBOOT,					// No Reboot
	ZZNET_EM_FORMAT_NEEDREBOOT_REBOOT						// Reboot Required. If using ZZ_CTRL_SDCARD/ZZ_CTRL_DISK, auto reboot.
															// If using ZZ_CTRL_FORMAT_PATITION, client must initiate reboot
}ZZNET_EM_FORMAT_NEEDREBOOT;

// ZZNETSDK_GetDevCaps interface ZZNET_STORAGE_CAPS Output
typedef struct tagZZNET_OUT_STORAGE_CAPS
{
	DWORD									dwSize;
	ZZNET_EM_FORMAT_NEEDREBOOT				emReboot; // Reboot requirement after format
}ZZNET_OUT_STORAGE_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_RAWFRAME_CAPS Input
typedef struct tagZZNET_IN_VIDEOIN_RAWFRAME_CAPS
{
	DWORD					dwSize;
}ZZNET_IN_VIDEOIN_RAWFRAME_CAPS;

// YUV Data Format Caps
typedef struct tagZZNET_RAWFRAMETYPE_DATA
{
	int						nListNum;										// Count
	char					szList[ZZ_COMMON_STRING_16][ZZ_COMMON_STRING_8];// Format List
	BYTE					byReserved[1024];
}ZZNET_RAWFRAMETYPE_DATA;

// ZZNETSDK_GetDevCaps ZZNET_VIDEOIN_RAWFRAME_CAPS Output
typedef struct tagZZNET_OUT_VIDEOIN_RAWFRAME_CAPS
{
	DWORD								dwSize;
	ZZNET_RAWFRAMETYPE_DATA				stuFrameData;
}ZZNET_OUT_VIDEOIN_RAWFRAME_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_COAXIAL_CONTROL_IO_CAPS Input
typedef struct tagZZNET_IN_GET_COAXIAL_CONTROL_IO_CAPS
{
	DWORD							dwSize;							// Size
	int								nChannel;						// Channel 
} ZZNET_IN_GET_COAXIAL_CONTROL_IO_CAPS;

// ZZNETSDK_GetDevCaps ZZNET_COAXIAL_CONTROL_IO_CAPS Output
typedef struct tagZZNET_OUT_GET_COAXIAL_CONTROL_IO_CAPS
{
	DWORD							dwSize;							// Size
	BOOL							bSupportControlLight;			// Support White Light
	BOOL							bSupportControlSpeaker;			// Support External Speaker
} ZZNET_OUT_GET_COAXIAL_CONTROL_IO_CAPS;








///@brief Input parameters for acquiring lighting control capabilities (Corresponding to: NET_LIGHTINGCONTROL_CAPS)
typedef struct tagZZNET_IN_LIGHTINGCONTROL_CAPS
{
	DWORD						dwSize;										/// Structure size
	int 						nChannel;											/// Channel number
}ZZNET_IN_LIGHTINGCONTROL_CAPS;

///@brief Versions supporting lighting configuration
typedef enum tagEM_ZZ_LC_CONFIG_VERSION
{
	EM_ZZ_LC_CONFIG_VERSION_UNKNOWN,					/// Unknown	
	EM_ZZ_LC_CONFIG_VERSION_LIGHTING,					/// Use Lighting configuration, default
	EM_ZZ_LC_CONFIG_VERSION_LIGHTING_V2,				/// Use Lighting_V2 configuration
}EM_ZZ_LC_CONFIG_VERSION;	

///@brief Light type
typedef enum tagEM_ZZ_LC_LIGHT_TYPE
{
	EM_ZZ_LC_LIGHT_TYPE_UNKNOWN,						/// Unknown
	EM_ZZ_LC_LIGHT_TYPE_INFRAREDLIGHT,					/// Infrared light
	EM_ZZ_LC_LIGHT_TYPE_WIHTELIGHT,					/// White light
	EM_ZZ_LC_LIGHT_TYPE_LASERLIGHT,					/// Laser light
	EM_ZZ_LC_LIGHT_TYPE_AIMIXLIGHT,					/// AI Mixed light (switches between Infrared and White light based on AI ID)
	EM_ZZ_LC_LIGHT_TYPE_PILOTLIGHT,					/// Pilot/Indicator light
}EM_ZZ_LC_LIGHT_TYPE;

///@brief Supported modes
typedef enum tagEM_ZZ_LC_MODE
{
	EM_ZZ_LC_MODE_UNKNOWN,								/// Unknown
	EM_ZZ_LC_MODE_MANUAL,								/// Manual
	EM_ZZ_LC_MODE_ZOOMPRIO,							/// Zoom priority
	EM_ZZ_LC_MODE_TIMING,								/// Timing
	EM_ZZ_LC_MODE_AUTO,								/// Auto
	EM_ZZ_LC_MODE_OFF,									/// Turn off light
	EM_ZZ_LC_MODE_EXCLUSIVEMANUAL,						/// Supports multiple lights (Exclusive Manual)
	EM_ZZ_LC_MODE_SMARTLIGHT,							/// Smart light
	EM_ZZ_LC_MODE_LINKING,								/// Event linking
	EM_ZZ_LC_MODE_DUSKTODAWN							/// Photosensitive (Dusk to Dawn)
}EM_ZZ_LC_MODE;

#define ZZ_SUPPORTED_LC_COMPLEX_MODES 3				/// Number of modes supported by the light
#define ZZ_SUPPORTED_AIMIX_LIGHT		8				/// Modes supported by AI Mixed light

///@brief Mode information supported by lights
typedef struct tagZZNET_MODES_COMPLEX_LIGHT
{
	EM_ZZ_LC_MODE	anInfraredLight[ZZ_SUPPORTED_LC_COMPLEX_MODES];		/// Modes supported by Infrared light
	int				nInfraredLightLen;									/// Number of modes supported by Infrared light
	EM_ZZ_LC_MODE	anWhiteLight[ZZ_SUPPORTED_LC_COMPLEX_MODES];			/// Modes supported by White light
	int				nWhiteLightLen;										/// Number of modes supported by White light
	EM_ZZ_LC_MODE	anLaserLight[ZZ_SUPPORTED_LC_COMPLEX_MODES];			/// Modes supported by Laser light
	int				nLaserLightLen;										/// Number of modes supported by Laser light
	EM_ZZ_LC_MODE	emAIMixLight[ZZ_SUPPORTED_AIMIX_LIGHT];				/// Modes supported by AI Mixed light
	int				nAIMixLight;										/// Number of modes supported by AI Mixed light
	BYTE			byReserved[92];				            			/// Reserved bytes
}ZZNET_MODES_COMPLEX_LIGHT;

#define ZZ_LC_LIGHT_COUNT 4			/// Number of lights in a light group

///@brief Light group information
typedef struct tagZZNET_LIGHT_TYPE_COMPLEX_DETAIL
{
	EM_ZZ_LC_LIGHT_TYPE		anNearLight[ZZ_LC_LIGHT_COUNT];		/// Light types in Near-light group
	int						nNearLightLen;						/// Number of lights in Near-light group
	EM_ZZ_LC_LIGHT_TYPE		anMiddleLight[ZZ_LC_LIGHT_COUNT];		/// Light types in Middle-light group
	int						nMiddleLightLen;					/// Number of lights in Middle-light group
	EM_ZZ_LC_LIGHT_TYPE		anFarLight[ZZ_LC_LIGHT_COUNT];			/// Light types in Far-light group
	int						nFarLightLen;						/// Number of lights in Far-light group
	BYTE					byReserved[128];				    /// Reserved bytes
}ZZNET_LIGHT_TYPE_COMPLEX_DETAIL;

///@brief Non-intelligent events supporting light linking
typedef enum tagEM_ZZ_LC_SUPPORT_EVENTS
{
	EM_ZZ_LC_SUPPORT_EVENTS_UNKNOWN,							/// Unknown
	EM_ZZ_LC_SUPPORT_EVENTS_MOTIONDETECT,						/// Motion detection
	EM_ZZ_LC_SUPPORT_EVENTS_MASK,								/// Mask/Occlusion
	EM_ZZ_LC_SUPPORT_EVENTS_ALARM,								/// Alarm
	EM_ZZ_LC_SUPPORT_EVENTS_ALL,								/// All events
}EM_ZZ_LC_SUPPORT_EVENTS;

#define ZZ_MAX_SUPPORT_EVENT_NUM 10					/// Number of non-intelligent events
#define ZZ_MAX_SUPPORT_INTELLISCENE_NUM 40				/// Number of intelligent events/scenes

///@brief Capability set for light linking
typedef struct tagZZNET_LINKING_ABILITY
{
	EM_ZZ_LC_SUPPORT_EVENTS		anSupportEvents[ZZ_MAX_SUPPORT_EVENT_NUM];						/// Supported non-intelligent events
	int							nSupportEventsLen;											/// Number of supported non-intelligent events
	EM_ZZ_SCENE_CLASS_TYPE		anSupportIntelliScence[ZZ_MAX_SUPPORT_INTELLISCENE_NUM];		/// Supported intelligent rules
	int							nSupportIntelliScenceLen;									/// Number of supported intelligent rules
	BYTE						byReserved[128];				            				/// Reserved bytes
}ZZNET_LINKING_ABILITY;

#define ZZ_LC_LIGHT_TYPE_NUM 3							/// Number of light types

///@brief Light flickering related information
typedef struct tagZZNET_FILCKER_LIGHTING
{
	BOOL				bSupported;							/// Whether light flickering is supported
	ZZNET_LINKING_ABILITY	stuAbility;							/// Capability set for light linking
	EM_ZZ_LC_LIGHT_TYPE	anLightType[ZZ_LC_LIGHT_TYPE_NUM];		/// Flickering light types
	int					nLightTypeLen;						/// Number of flickering lights
	int					anFilckerIntevalTime[2];			/// Range of flickering interval time
	int					anFilckerTimes[2];					/// Range of configurable flickering times
	BYTE				byReserved[128];				    /// Reserved bytes
}ZZNET_FILCKER_LIGHTING;

///@brief Solid light (Keep Lighting) information
typedef struct tagZZNET_KEEP_LIGHTING
{
	BOOL				bSupported;							/// Whether solid light is supported
	ZZNET_LINKING_ABILITY	stuAbility;							/// Capability set for light linking
	EM_ZZ_LC_LIGHT_TYPE	anLightType[ZZ_LC_LIGHT_TYPE_NUM];		/// Solid light types
	int					nLightTypeLen;						/// Number of solid lights
	BYTE				byReserved[128];				    /// Reserved bytes
}ZZNET_KEEP_LIGHTING;

///@brief PTZ linking light types
typedef struct tagZZNET_LINKING_DETAIL
{
	ZZNET_FILCKER_LIGHTING	stuFilckerLighting;			/// Flickering light information
	ZZNET_KEEP_LIGHTING		stuKeepLighting;			/// Solid light information
	BYTE					byReserved[128];			/// Reserved bytes
}ZZNET_LINKING_DETAIL;

///@brief Light compensation information
typedef struct tagZZNET_CORRECTION
{
	BOOL				bSupported;					/// Whether light compensation is supported
	int					nRange;						/// Maximum compensation range
	BYTE				byReserved[128];			/// Reserved bytes	
}ZZNET_CORRECTION;
///@brief Light sensitivity information
typedef struct tagZZNET_SENSITIVITY
{
	BOOL				bSupported;					/// Whether light sensitivity is supported
	int					nRange;						/// Maximum light sensitivity range
	BYTE				byReserved[128];			/// Reserved bytes
}ZZNET_SENSITIVITY;

#define ZZ_LC_POWER_NUM 3								/// Number of power levels
#define ZZ_LC_ANGLECONTROL_NUM 3						/// Number of laser angles
#define ZZ_LC_LIGHT_MODE_NUM 20						/// Number of modes

///@brief Output parameters for acquiring lighting control capabilities (Corresponding to: ZZNET_LIGHTINGCONTROL_CAPS)
typedef struct tagZZNET_OUT_LIGHTINGCONTROL_CAPS
{
	DWORD							dwSize;										/// Structure size
	BOOL							bSupport;									/// Whether lighting control is supported
	EM_ZZ_LC_CONFIG_VERSION			emConfigVersion;							/// Supported lighting configuration version						
	EM_ZZ_LC_LIGHT_TYPE				emLightType;								/// Light type
	EM_ZZ_LC_LIGHT_TYPE				anLightTypeComplex[ZZ_LC_LIGHT_TYPE_NUM];		/// Complex light types
	int								nLightTypeComplexLen;						/// Number of complex light types
	int								nNearLightNumber;							/// Number of Near-light groups
	int								nMiddleLightNumber;							/// Number of Middle-light groups
	int								nFarLightNumber;							/// Number of Far-light groups
	EM_ZZ_LC_MODE					emDefaultMode;								/// Default supported mode
	EM_ZZ_LC_MODE					anModes[ZZ_LC_LIGHT_MODE_NUM];					/// Supported mode types
	int								nModesLen;									/// Number of supported modes
	ZZNET_MODES_COMPLEX_LIGHT		stuModesComplex;							/// Complex light mode information
	ZZNET_LIGHT_TYPE_COMPLEX_DETAIL	stuLightTypeComplexDetail;					/// Light group information
	ZZNET_LINKING_DETAIL			stuLinkingDetail;							/// PTZ linking light information
	int								anPower[ZZ_LC_POWER_NUM];							/// Light group power control mask
	int								anAngleControl[ZZ_LC_ANGLECONTROL_NUM];			/// Light group laser angle control mask
	ZZNET_CORRECTION				stuCorrection;								/// Light compensation information
	ZZNET_SENSITIVITY				stuSensitivity;								/// Light sensitivity information
	BOOL							bSupportLaserLightMove;						/// Whether laser light optical axis adjustment is supported
	int								nLightingTimeSectionNum;					/// Number of time sections supported in timing mode
	BOOL							bSupportByTime;								/// Whether time-phased configuration is supported
	BOOL							bSupportModesComplex;						/// Whether complex light mode information is supported
}ZZNET_OUT_LIGHTINGCONTROL_CAPS;


///@brief ZZNETSDK_GetDevCaps Interface ZZNET_VIDEO_IN_DEFOG_CAPS command input parameters
typedef struct tagZZNET_IN_VIDEO_IN_DEFOG_CAPS
{
    DWORD                      dwSize;          /// Structure size
    int                        nChannel;        /// Channel number
}ZZNET_IN_VIDEO_IN_DEFOG_CAPS;

///@brief  Atmospheric light mode capability
typedef struct tagZZNET_LIGHT_INTENSITY_CAPS
{   
    BOOL            bSupportLightMode;  /// Whether atmospheric light mode capability is supported
    BYTE            byReserved[68];     /// Reserved bytes
}ZZNET_LIGHT_INTENSITY_CAPS;

///@brief Defog mode
typedef enum tagEM_ZZ_IN_DEFOG_MODE
{
    EM_ZZ_IN_DEFOG_MODE_UNKNOWN,          /// Unknown
    EM_ZZ_IN_DEFOG_MODE_OFF,              /// Off
    EM_ZZ_IN_DEFOG_MODE_MANUAL,           /// Manual
    EM_ZZ_IN_DEFOG_MODE_AUTO,             /// Auto
} EM_ZZ_IN_DEFOG_MODE;

///@brief ZZNETSDK_GetDevCaps Interface ZZNET_VIDEO_IN_DEFOG_CAPS command output parameters
typedef struct tagZZNET_OUT_VIDEO_IN_DEFOG_CAPS
{
    DWORD                       dwSize;             /// Structure size
    BOOL                        bSupportInDefog;    /// Whether defog setting capability is supported
    BOOL                        bSupportCamDefog;   /// Whether optical/physical defog is supported
    UINT                        nModeCount;         /// Number of defog modes    
    EM_ZZ_IN_DEFOG_MODE         emMode[8];          /// Defog modes
    ZZNET_LIGHT_INTENSITY_CAPS  stuLightIntensity;  /// Atmospheric light mode capability
}ZZNET_OUT_VIDEO_IN_DEFOG_CAPS;


////////////////////////////////// Large Screen Control ////////////////////////////////////////
// ZZNETSDK_OpenSplitWindow Interface Input Parameters (Open Window)
typedef struct tagZZ_IN_SPLIT_OPEN_WINDOW
{
    DWORD               dwSize;
    int                 nChannel;                   // Channel number (Screen number)
    ZZ_RECT             stuRect;                    // Window position, 0~8192
    BOOL                bDirectable;                // Whether coordinates meet direct pass-through conditions. Direct pass-through means in splicing screen mode, this window area matches the physical screen area exactly.
} ZZ_IN_SPLIT_OPEN_WINDOW;

// ZZNETSDK_OpenSplitWindow Interface Output Parameters (Open Window)
typedef struct tagZZ_OUT_SPLIT_OPEN_WINDOW
{
    DWORD               dwSize;
    unsigned int        nWindowID;                  // Window Index
    unsigned int        nZOrder;                    // Window Order        
} ZZ_OUT_SPLIT_OPEN_WINDOW;

// ZZNETSDK_CloseSplitWindow Interface Input Parameters (Close Window)
typedef struct tagZZ_IN_SPLIT_CLOSE_WINDOW
{
    DWORD               dwSize;
    int                 nChannel;                   // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    UINT                nWindowID;                  // Window Index
    const char*         pszCompositeID;             // Composite screen ID
} ZZ_IN_SPLIT_CLOSE_WINDOW;

// ZZNETSDK_CloseSplitWindow Interface Output Parameters (Close Window)
typedef struct tagZZ_OUT_SPLIT_CLOSE_WINDOW
{
    DWORD               dwSize;
} ZZ_OUT_SPLIT_CLOSE_WINDOW;



// Hot Plug Mode
typedef struct tagZZ_HOT_PLUG_MODE
{
    DWORD               dwSize;
    int                 nMode;                      // Hot plug mode, 0-Hot plug mode, 1-Forced output mode
} ZZ_HOT_PLUG_MODE;

// Color BCSH (Brightness, Contrast, Saturation, Hue)
typedef struct tagZZ_COLOR_BCSH 
{
    int                 nBirghtness;                // Brightness
    int                 nContrast;                  // Contrast
    int                 nSaturation;                // Saturation
    int                 nHue;                       // Hue
} ZZ_COLOR_BCSH;

// Video Output Options
typedef struct tagZZ_VIDEO_OUT_OPT
{
    DWORD               dwSize;
    ZZ_RECT*            pstuMargin;                 // Margin range
    ZZ_COLOR_BCSH*      pstuColor;                  // Output color
    ZZ_COLOR_RGBA*      pstuBackground;             // Background color
    ZZ_SIZE*            pstuSize;                   // Output size
    ZZ_HOT_PLUG_MODE*   pstuHotPlugMode;            // Hot plug mode
} ZZ_VIDEO_OUT_OPT;


// Device Protocol Type
typedef enum tagZZ_DEVICE_PROTOCOL
{
    ZZ_PROTOCOL_PRIVATE2,                   // Private Generation 2 Protocol
    ZZ_PROTOCOL_PRIVATE3,                   // Private Generation 3 Protocol
    ZZ_PROTOCOL_ONVIF,                      // Onvif    
    ZZ_PROTOCOL_VNC,                        // Virtual Network Computing
    ZZ_PROTOCOL_TS,                         // Standard TS
    
    ZZ_PROTOCOL_PRIVATE = 100,              // Private Protocol        
    ZZ_PROTOCOL_AEBELL,                     // AEBELL        
    ZZ_PROTOCOL_PANASONIC,                  // Panasonic        
    ZZ_PROTOCOL_SONY,                       // Sony        
    ZZ_PROTOCOL_DYNACOLOR,                  // Dynacolor        
    ZZ_PROTOCOL_TCWS,                       // TCWS        
    ZZ_PROTOCOL_SAMSUNG,                    // Samsung        
    ZZ_PROTOCOL_YOKO,                       // YOKO        
    ZZ_PROTOCOL_AXIS,                       // Axis        
    ZZ_PROTOCOL_SANYO,                      // Sanyo               
    ZZ_PROTOCOL_BOSH,                       // Bosch        
    ZZ_PROTOCOL_PECLO,                      // Pelco        
    ZZ_PROTOCOL_PROVIDEO,                   // Provideo        
    ZZ_PROTOCOL_ACTI,                       // ACTi        
    ZZ_PROTOCOL_VIVOTEK,                    // Vivotek        
    ZZ_PROTOCOL_ARECONT,                    // Arecont        
    ZZ_PROTOCOL_PRIVATEEH,                  // PrivateEH            
    ZZ_PROTOCOL_IMATEK,                     // IMatek        
    ZZ_PROTOCOL_SHANY,                      // Shany        
    ZZ_PROTOCOL_VIDEOTREC,                  // Videotrec        
    ZZ_PROTOCOL_URA,                        // Ura        
    ZZ_PROTOCOL_BITICINO,                   // Bticino         
    ZZ_PROTOCOL_ONVIF2,                     // Onvif Protocol Type, same as ZZ_PROTOCOL_ONVIF    
    ZZ_PROTOCOL_SHEPHERD,                   // Shepherd        
    ZZ_PROTOCOL_YAAN,                       // Yaan        
    ZZ_PROTOCOL_AIRPOINT,                   // Airpop        
    ZZ_PROTOCOL_TYCO,                       // TYCO        
    ZZ_PROTOCOL_XUNMEI,                     // Xunmei        
    ZZ_PROTOCOL_HIKVISION,                  // Hikvision        
    ZZ_PROTOCOL_LG,                         // LG        
    ZZ_PROTOCOL_AOQIMAN,                    // Aoqiman        
    ZZ_PROTOCOL_BAOKANG,                    // Baokang            
    ZZ_PROTOCOL_WATCHNET,                   // Watchnet        
    ZZ_PROTOCOL_XVISION,                    // Xvision        
    ZZ_PROTOCOL_FUSITSU,                    // Fujitsu        
    ZZ_PROTOCOL_CANON,                      // Canon        
    ZZ_PROTOCOL_GE,                         // GE        
    ZZ_PROTOCOL_Basler,                     // Basler        
    ZZ_PROTOCOL_Patro,                      // Patro        
    ZZ_PROTOCOL_CPKNC,                      // CPPLUS K Series        
    ZZ_PROTOCOL_CPRNC,                      // CPPLUS R Series        
    ZZ_PROTOCOL_CPUNC,                      // CPPLUS U Series        
    ZZ_PROTOCOL_CPPLUS,                     // CPPLUS IPC    
    ZZ_PROTOCOL_XunmeiS,                    // Xunmei S, actual protocol is Onvif        
    ZZ_PROTOCOL_GDDW,                       // Guangdong Power Grid        
    ZZ_PROTOCOL_PSIA,                       // PSIA        
    ZZ_PROTOCOL_GB2818,                     // GB2818            
    ZZ_PROTOCOL_GDYX,                       // GDYX        
    ZZ_PROTOCOL_OTHER,                      // User defined   
} ZZ_DEVICE_PROTOCOL;

// Split Mode Information for one screen
typedef struct tagZZ_SPLIT_MODE_INFO
{
    DWORD               dwSize;
    ZZ_SPLIT_MODE       emSplitMode;            // Split Mode
    int                 nGroupID;               // Group Index
    DWORD               dwDisplayType;          // Display Type; see ZZ_SPLIT_DISPLAY_TYPE. (Note: Display content in each mode is determined by "PicInPic", or by NVD legacy rules (DisChn field). Compatible: if this item is missing, defaults to general display type "General")
} ZZ_SPLIT_MODE_INFO;

// Split Capabilities
typedef struct tagZZ_SPLIT_CAPS 
{
    DWORD               dwSize;
    int                 nModeCount;                             // Number of supported split modes
    ZZ_SPLIT_MODE       emSplitMode[ZZ_MAX_SPLIT_MODE_NUM];     // Supported split modes
    int                 nMaxSourceCount;                        // Max display source configuration count
    int                 nFreeWindowCount;                       // Max supported free window count
    BOOL                bCollectionSupported;                   // Whether region collection is supported
    DWORD               dwDisplayType;                          // Mask indicating multiple display types, see ZZ_SPLIT_DISPLAY_TYPE. (Note: Display content in each mode is determined by "PicInPic", or by NVD legacy rules (DisChn field). Compatible: if this item is missing, defaults to general display type "General")
    int                 nPIPModeCount;                          // Number of supported PIP split modes
    ZZ_SPLIT_MODE       emPIPSplitMode[ZZ_MAX_SPLIT_MODE_NUM];  // Supported PIP split modes
    int                 nInputChannels[ZZ_SPLIT_INPUT_NUM];     // Supported input channels
    int                 nInputChannelCount;                     // Number of supported input channels, 0 means no limit
    int                 nBootModeCount;                         // Number of boot split modes
    ZZ_SPLIT_MODE       emBootMode[ZZ_MAX_SPLIT_MODE_NUM];      // Supported boot default split modes
} ZZ_SPLIT_CAPS;

// Cascade Authentication Information
typedef struct tagZZ_CASCADE_AUTHENTICATOR
{
    DWORD               dwSize;
    char                szUser[ZZ_NEW_USER_NAME_LENGTH];        // Username
    char                szPwd[ZZ_NEW_USER_PSW_LENGTH];          // Password
    char                szSerialNo[ZZ_SERIALNO_LEN];            // Device Serial Number
} ZZ_CASCADE_AUTHENTICATOR;

typedef enum tagEM_ZZ_SRC_PUSHSTREAM_TYPE
{   
    EM_ZZ_SRC_PUSHSTREAM_AUTO,        // Device automatically identifies based on stream header, default value
    EM_ZZ_SRC_PUSHSTREAM_HIKVISION,   // Hikvision private stream
    EM_ZZ_SRC_PUSHSTREAM_PS,          // PS stream
    EM_ZZ_SRC_PUSHSTREAM_TS,          // TS stream
    EM_ZZ_SRC_PUSHSTREAM_SVAC,        // SVAC stream
}EM_ZZ_SRC_PUSHSTREAM_TYPE;

// Display Source
typedef struct tagZZ_SPLIT_SOURCE
{
    DWORD               dwSize;
    BOOL                bEnable;                                // Enable
    char                szIp[ZZ_MAX_IPADDR_LEN];                // IP, empty means not set
    char                szUser[ZZ_USER_NAME_LENGTH];            // Username, suggested to use szUserEx
    char                szPwd[ZZ_USER_PSW_LENGTH];              // Password, suggested to use szPwdEx
    int                 nPort;                                  // Port
    int                 nChannelID;                             // Channel ID
    int                 nStreamType;                            // Video stream, -1-Auto, 0-Main, 1-Extra1, 2-Extra2, 3-Extra3, 4-Snap, 5-Preview
    int                 nDefinition;                            // Definition, 0-Standard, 1-High
    ZZ_DEVICE_PROTOCOL  emProtocol;                             // Protocol type
    char                szDevName[ZZ_DEVICE_NAME_LEN];          // Device Name
    int                 nVideoChannel;                          // Number of Video Input Channels
    int                 nAudioChannel;                          // Number of Audio Input Channels
    //--------------------------------------------------------------------------------------
    // The following are valid only for decoders
    BOOL                bDecoder;                               // Is Decoder
    BYTE                byConnType;                             // -1: auto, 0: TCP; 1: UDP; 2: Multicast
    BYTE                byWorkMode;                             // 0: Direct connection; 1: Forwarding
    WORD                wListenPort;                            // Listening port, valid when forwarding; used as multicast port if byConnType is Multicast
    char                szDevIpEx[ZZ_MAX_IPADDR_OR_DOMAIN_LEN]; // Extended szDevIp, IP address of frontend DVR (can input domain name)
    BYTE                bySnapMode;                             // Snapshot mode (valid when nStreamType==4) 0: Request one frame, 1: Scheduled request
    BYTE                byManuFactory;                          // Manufacturer of the target device, see EM_IPC_TYPE class
    BYTE                byDeviceType;                           // Target device type, 0: IPC
    BYTE                byDecodePolicy;                         // Target device decoding policy, 0: Compatible with previous
                                                                // 1: Realtime High 2: Realtime Medium
                                                                // 3: Realtime Low 4: Default Level
                                                                // 5: Fluency High 6: Fluency Medium
                                                                // 7: Fluency Low
    //--------------------------------------------------------------------------------------
    DWORD               dwHttpPort;                             // Http Port, 0-65535
    DWORD               dwRtspPort;                             // Rtsp Port, 0-65535
    char                szChnName[ZZ_DEVICE_NAME_LEN];          // Remote channel name, can only modify this channel's name if the read name is not empty
    char                szMcastIP[ZZ_MAX_IPADDR_LEN];           // Multicast IP address, valid when byConnType is Multicast
    char                szDeviceID[ZZ_DEV_ID_LEN_EX];           // Device ID, ""-null, "Local"-local channel, "Remote"-remote channel, or fill in specific Device ID from RemoteDevice
    BOOL                bRemoteChannel;                         // Is remote channel (Read-only)
    unsigned int        nRemoteChannelID;                       // Remote channel ID (Read-only), valid when bRemoteChannel=TRUE
    char                szDevClass[ZZ_DEV_TYPE_LEN];            // Device type class, e.g., IPC, DVR, NVR, etc.
    char                szDevType[ZZ_DEV_TYPE_LEN];             // Device specific model, e.g., IPC-HF3300
    char                szMainStreamUrl[MAX_PATH];              // Main stream URL, valid when byManuFactory is ZZ_IPC_OTHER
    char                szExtraStreamUrl[MAX_PATH];             // Extra stream URL, valid when byManuFactory is ZZ_IPC_OTHER
    int                 nUniqueChannel;                         // Unique channel number unified within the device, Read-only
    ZZ_CASCADE_AUTHENTICATOR stuCascadeAuth;                    // Cascade authentication info, valid when DeviceID is "Local/Cascade/SerialNo", where SerialNo is the device serial number
    int                 nHint;                                  // 0-Normal video source, 1-Alarm video source
    int                 nOptionalMainUrlCount;                  // Number of backup main stream URLs
    char                szOptionalMainUrls[ZZ_MAX_OPTIONAL_URL_NUM][MAX_PATH];  // List of backup main stream URLs
    int                 nOptionalExtraUrlCount;                 // Number of backup extra stream URLs
    char                szOptionalExtraUrls[ZZ_MAX_OPTIONAL_URL_NUM][MAX_PATH]; // List of backup extra stream URLs
    //--------------------------------------------------------------------------------------
    // Fields added in protocol updates
    int                 nInterval;                              // Tour time interval, Unit: seconds
    char                szUserEx[ZZ_NEW_USER_NAME_LENGTH];      // Username
    char                szPwdEx[ZZ_NEW_USER_PSW_LENGTH];        // Password
    EM_ZZ_SRC_PUSHSTREAM_TYPE  emPushStream;           // Push stream type, only valid if byConnType is TCP-Push or UDP-Push
	ZZNET_RECT			stuSRect;					// Video source region, valid when szDeviceID is not empty. If region is (0,0,0,0), data is invalid, device uses default (0,0,8192,8192)
} ZZ_SPLIT_SOURCE;


// ZZNETSDK_SetTourSource Interface Input Parameters (Set Window Tour Source)
typedef struct tagZZNET_IN_SET_TOUR_SOURCE 
{
    DWORD                   dwSize;
    int                     nChannel;               // Output channel number
    int                     nWindow;                // Window number
    ZZ_SPLIT_SOURCE*        pstuSrcs;               // Array of display sources for window touring, memory allocated by user, size is sizeof(ZZ_SPLIT_SOURCE)*nSrcCount
    int                     nSrcCount;              // Number of display sources
} ZZNET_IN_SET_TOUR_SOURCE;

// ZZNETSDK_SetTourSource Interface Output Parameters (Set Window Tour Source)
typedef struct tagZZNET_OUT_SET_TOUR_SOURCE
{
    DWORD                   dwSize;
} ZZNET_OUT_SET_TOUR_SOURCE;

// ZZNETSDK_GetTourSource Interface Input Parameters
typedef struct tagZZNET_IN_GET_TOUR_SOURCE 
{
    DWORD                   dwSize;
    int                     nChannel;               // Output channel number, valid when pszCompsiteID is NULL
    const char*             pszCompositeID;         // Splicing screen ID
    int                     nWindow;                // Window number, -1 means all windows
} ZZNET_IN_GET_TOUR_SOURCE;

// Window Tour Display Source Information
typedef struct tagZZNET_SPLIT_TOUR_SOURCE 
{
    DWORD                   dwSize;
    ZZ_SPLIT_SOURCE*        pstuSrcs;               // Display source array, memory allocated by user, size is sizeof(ZZ_SPLIT_SOURCE)*nMaxSrcCount
    int                     nMaxSrcCount;           // Maximum number of display sources
    int                     nRetSrcCount;           // Number of returned display sources
} ZZNET_SPLIT_TOUR_SOURCE;

// ZZNETSDK_GetTourSource Interface Output Parameters
typedef struct tagZZNET_OUT_GET_TOUR_SOURCE
{
    DWORD                   dwSize;    
    ZZNET_SPLIT_TOUR_SOURCE*  pstuWndSrcs;            // Window tour info array, memory allocated by user, size is sizeof(ZZNET_SPLIT_TOUR_SOURCE)*nMaxWndCount
    int                     nMaxWndCount;           // Max window array size, filled by user
    int                     nRetWndCount;           // Number of returned windows
} ZZNET_OUT_GET_TOUR_SOURCE;

// Video Output Control Method
typedef enum
{
    EM_ZZ_VIDEO_OUT_CTRL_CHANNEL,              // Logical channel number control method, valid for both physical screens and splicing screens
    EM_ZZ_VIDEO_OUT_CTRL_COMPOSITE_ID,         // Splicing screen ID control method, only valid for splicing screens
} EM_ZZ_VIDEO_OUT_CTRL_TYPE;

// ZZNETSDK_SplitSetMultiSource Interface Input Parameters
typedef struct tagZZNET_IN_SPLIT_SET_MULTI_SOURCE 
{
    DWORD                   dwSize;
    EM_ZZ_VIDEO_OUT_CTRL_TYPE  emCtrlType;         // Video output control method
    int                     nChannel;           // Video output logical channel number, valid when emCtrlType is EM_VIDEO_OUT_CTRL_CHANNEL
    const char*             pszCompositeID;     // Splicing screen ID, valid when emCtrlType is EM_VIDEO_OUT_CTRL_COMPOSITE_ID
    BOOL                    bSplitModeEnable;   // Whether to change split mode
    ZZ_SPLIT_MODE           emSplitMode;        // Split mode, valid when bSplitModeEnable=TRUE
    int                     nGroupID;           // Split group ID, valid when bSplitModeEnable=TRUE
    int*                    pnWindows;          // Window number array, memory allocated by user, size is sizeof(int)*nWindowCount
    int                     nWindowCount;       // Number of windows
    ZZ_SPLIT_SOURCE*        pstuSources;        // Video source info, corresponding to each window, count matches nWindowCount, memory allocated by user, size is sizeof(ZZ_SPLIT_SOURCE)*nWindowCount
} ZZNET_IN_SPLIT_SET_MULTI_SOURCE;

// ZZNETSDK_SplitSetMultiSource Interface Output Parameters
typedef struct tagZZNET_OUT_SPLIT_SET_MULTI_SOURCE 
{
    DWORD                   dwSize;
} ZZNET_OUT_SPLIT_SET_MULTI_SOURCE;

typedef enum tagZZ_SPLIT_DISPLAY_TYPE
{
    ZZ_SPLIT_DISPLAY_TYPE_GENERAL=1,          // General display type
    ZZ_SPLIT_DISPLAY_TYPE_PIP=2,              // Picture-in-Picture display type
    ZZ_SPLIT_DISPLAY_TYPE_CUSTOM=3,           // Free combination split mode
} ZZ_SPLIT_DISPLAY_TYPE;


/////// Video Wall / Monitor Wall ///////////////////////////////

// Video Input Channel Information
typedef struct tagZZ_VIDEO_INPUTS
{
    DWORD               dwSize;
    char                szChnName[ZZ_DEVICE_NAME_LEN];      // Channel Name
    BOOL                bEnable;                            // Enable
    char                szControlID[ZZ_DEV_ID_LEN_EX];      // Control ID
    char                szMainStreamUrl[MAX_PATH];          // Main Stream URL 
    char                szExtraStreamUrl[MAX_PATH];         // Extra Stream URL
    int                 nOptionalMainUrlCount;              // Number of backup main stream URLs
    char                szOptionalMainUrls[ZZ_MAX_OPTIONAL_URL_NUM][MAX_PATH];  // List of backup main stream URLs
    int                 nOptionalExtraUrlCount;             // Number of backup extra stream URLs
    char                szOptionalExtraUrls[ZZ_MAX_OPTIONAL_URL_NUM][MAX_PATH]; // List of backup extra stream URLs
} ZZ_VIDEO_INPUTS;

typedef struct tagZZ_REMOTE_DEVICE 
{
    DWORD               dwSize;
    BOOL                bEnable;                            // Enable
    char                szIp[ZZ_MAX_IPADDR_LEN];            // IP
    char                szUser[ZZ_USER_NAME_LENGTH];        // Username, suggested to use szUserEx
    char                szPwd[ZZ_USER_PSW_LENGTH];          // Password, suggested to use szPwdEx
    int                 nPort;                              // Port
    int                 nDefinition;                        // Definition, 0-Standard, 1-High
    ZZ_DEVICE_PROTOCOL  emProtocol;                         // Protocol Type
    char                szDevName[ZZ_DEVICE_NAME_LEN];      // Device Name
    int                 nVideoInputChannels;                // Number of Video Input Channels
    int                 nAudioInputChannels;                // Number of Audio Input Channels
    char                szDevClass[ZZ_DEV_TYPE_LEN];        // Device Type Class, e.g., IPC, DVR, NVR, etc.
    char                szDevType[ZZ_DEV_TYPE_LEN];         // Device Specific Model, e.g., IPC-HF3300
    int                 nHttpPort;                          // Http Port
    int                 nMaxVideoInputCount;                // Max Video Input Channels
    int                 nRetVideoInputCount;                // Returned actual channel count
    ZZ_VIDEO_INPUTS*    pstuVideoInputs;                    // Video Input Channel Info, memory allocated by user, size is sizeof(ZZ_VIDEO_INPUTS)*nMaxVideoInputCount
    char                szMachineAddress[ZZ_MAX_CARD_INFO_LEN]; // Device Deployment Location
    char                szSerialNo[ZZ_SERIALNO_LEN];        // Device Serial Number
    int                 nRtspPort;                          // Rtsp Port

	/* The following are for new platform extensions */
	char                szUserEx[ZZ_USER_NAME_LEN_EX];       // Username
    char                szPwdEx[ZZ_USER_PSW_LEN_EX];         // Password
} ZZ_REMOTE_DEVICE;

typedef enum tagZZNET_LOGIC_CHANNEL_TYPE
{
    ZZ_LOGIC_CHN_UNKNOWN,              // Unknown
    ZZ_LOGIC_CHN_LOCAL,                // Local Channel
    ZZ_LOGIC_CHN_REMOTE,               // Remote Channel
    ZZ_LOGIC_CHN_COMPOSE,              // Composite Channel, includes PIP and audio mixing channels for trial devices
    ZZ_LOGIC_CHN_MATRIX,               // Analog Matrix Channel
    ZZ_LOGIC_CHN_CASCADE,              // Cascade Channel
} ZZNET_LOGIC_CHN_TYPE;

// Available Display Source Information
typedef struct tagZZ_MATRIX_CAMERA_INFO
{
    DWORD               dwSize;
    char                szName[ZZ_DEV_ID_LEN_EX];           // Name
    char                szDevID[ZZ_DEV_ID_LEN_EX];          // Device ID
    char                szControlID[ZZ_DEV_ID_LEN_EX];      // Control ID
    int                 nChannelID;                         // Channel ID, unique within DeviceID device
    int                 nUniqueChannel;                     // Unique channel number unified within the device
    BOOL                bRemoteDevice;                      // Is Remote Device
    ZZ_REMOTE_DEVICE    stuRemoteDevice;                    // Remote Device Info
    ZZNET_STREAM_TYPE     emStreamType;                       // Video Stream Type
    ZZNET_LOGIC_CHN_TYPE  emChannelType;                      // Channel Type
} ZZ_MATRIX_CAMERA_INFO;

// ZZNetSDK_MatrixGetCameras Interface Input Parameters
typedef struct tagZZ_IN_MATRIX_GET_CAMERAS 
{
    DWORD               dwSize;
} ZZ_IN_MATRIX_GET_CAMERAS;

// ZZNetSDK_MatrixGetCameras Interface Output Parameters
typedef struct tagZZ_OUT_MATRIX_GET_CAMERAS 
{
    DWORD                   dwSize;
    ZZ_MATRIX_CAMERA_INFO*  pstuCameras;                    // Display source info array, memory allocated by user, size is sizeof(ZZ_MATRIX_CAMERA_INFO)*nMaxCameraCount
    int                     nMaxCameraCount;                // Display source array size
    int                     nRetCameraCount;                // Returned display source count
} ZZ_OUT_MATRIX_GET_CAMERAS;

// ZZNetSDK_QueryDevInfo, ZZNET_QUERY_DEV_REMOTE_DEVICE_INFO Query Remote Device Info Input Parameters
typedef struct tagZZNET_IN_GET_DEVICE_INFO
{
    DWORD                       dwSize;                                         // User must set dwSize to sizeof(ZZNET_IN_GET_DEVICE_INFO) when using this struct
    char                        szDevice[ZZ_DEV_ID_LEN_EX];                 // Device ID
    // Device attributes, valid when szDevice field is empty
    char                        szAttributeIP[ZZ_COMMON_STRING_32];             // Device Address
    int                         nAttributePort;                                 // Device Port
    char                        szAttributeUsername[ZZ_COMMON_STRING_128];      // Username
    char                        szAttributePassword[ZZ_COMMON_STRING_128];      // Password
    char                        szAttributeManufacturer[ZZ_COMMON_STRING_128];  // Manufacturer Protocol
}ZZNET_IN_GET_DEVICE_INFO;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_DEV_REMOTE_DEVICE_INFO Query Remote Device Info Output Parameters
typedef struct tagZZNET_OUT_GET_DEVICE_INFO
{
    DWORD                       dwSize;         // User must set dwSize to sizeof(NET_OUT_GET_DEVICE_INFO) when using this struct
    ZZ_REMOTE_DEVICE            stuInfo;        // Device Info, user must set dwSize of member struct
}ZZNET_OUT_GET_DEVICE_INFO;

// ZZNetSDK_MatrixSetCameras Interface Input Parameters
typedef struct tagZZ_IN_MATRIX_SET_CAMERAS 
{
    DWORD                   dwSize;
    ZZ_MATRIX_CAMERA_INFO*  pstuCameras;                    // Display source info array, memory allocated by user, size is sizeof(ZZ_MATRIX_CAMERA_INFO)*nCameraCount
    int                     nCameraCount;                   // Display source array size
} ZZ_IN_MATRIX_SET_CAMERAS;

// ZZNetSDK_MatrixSetCameras Interface Output Parameters
typedef struct tagZZ_OUT_MATRIX_SET_CAMERAS 
{
    DWORD                   dwSize;
} ZZ_OUT_MATRIX_SET_CAMERAS;

// Window Display Source Info
typedef struct tagZZ_SPLIT_WND_SOURCE 
{
    DWORD                   dwSize;
    BOOL                    bEnable;                        // Is display source valid
    char                    szDeviceID[ZZ_DEV_ID_LEN];      // Device ID
    char                    szControlID[ZZ_DEV_ID_LEN];     // Control ID
    int                     nVideoChannel;                  // Video Channel Number
    int                     nVideoStream;                   // Video Stream Type
    int                     nAudioChannel;                  // Audio Channel
    int                     nAudioStream;                   // Audio Stream Type
    int                     nUniqueChannel;                 // Unique channel number unified within the device, Read-only
    BOOL                    bRemoteDevice;                  // Is Remote Device
    ZZ_REMOTE_DEVICE        stuRemoteDevice;                // Remote Device Info
	ZZNET_RECT				stuSRect;						// Video source region, if region is (0,0,0,0) data is invalid, device uses default (0,0,8192,8192)
} ZZ_SPLIT_WND_SOURCE;

// Split Window Info
typedef struct tagZZ_SPLIT_WINDOW 
{
    DWORD                   dwSize;
    BOOL                    bEnable;                        // Does the window have a video source
    int                     nWindowID;                      // Window ID
    char                    szControlID[ZZ_DEV_ID_LEN];     // Control ID
    ZZ_RECT                 stuRect;                        // Window region, valid in free split mode
    BOOL                    bDirectable;                    // Whether coordinates meet direct pass-through conditions
    int                     nZOrder;                        // Window Z Order
    ZZ_SPLIT_WND_SOURCE     stuSource;                      // Display Info
} ZZ_SPLIT_WINDOW;

// Splicing Screen Scene
typedef struct tagZZ_SPLIT_SCENE 
{
    DWORD                   dwSize;
    char                    szCompositeID[ZZ_DEV_ID_LEN];   // Splicing Screen ID
    char                    szControlID[ZZ_DEV_ID_LEN];     // Control ID
    ZZ_SPLIT_MODE           emSplitMode;                    // Split Mode
    ZZ_SPLIT_WINDOW*        pstuWnds;                       // Window info array, memory allocated by user, size is sizeof(ZZ_SPLIT_WINDOW)*nMaxWndCount
    int                     nMaxWndCount;                   // Window info array size, filled by user
    int                     nRetWndCount;                   // Number of returned windows
} ZZ_SPLIT_SCENE;


// Video Split Operation Type
typedef enum tagZZNET_SPLIT_OPERATE_TYPE
{
    ZZNET_SPLIT_OPERATE_SET_BACKGROUND,           // Set background image, corresponds to NET_IN_SPLIT_SET_BACKGROUND and NET_OUT_SPLIT_SET_BACKBROUND
    ZZNET_SPLIT_OPERATE_GET_BACKGROUND,           // Get background image, corresponds to NET_IN_SPLIT_GET_BACKGROUND and NET_OUT_SPLIT_GET_BACKGROUND
    ZZNET_SPLIT_OPERATE_SET_PREPULLSRC,           // Set pre-pull source, corresponds to NET_IN_SPLIT_SET_PREPULLSRC and NET_OUT_SPLIT_SET_PREPULLSRC
    ZZNET_SPLIT_OPERATE_SET_HIGHLIGHT,            // Set source border highlight enable switch, corresponds to NET_IN_SPLIT_SET_HIGHLIGHT and NET_OUT_SPLIT_SET_HIGHLIGHT
    ZZNET_SPLIT_OPERATE_SET_ZORDER,               // Adjust window Z-order, corresponds to NET_IN_SPLIT_SET_ZORDER and NET_OUT_SPLIT_SET_ZORDER
    ZZNET_SPLIT_OPERATE_SET_TOUR,                 // Window tour control, corresponds to NET_IN_SPLIT_SET_TOUR and NET_OUT_SPLIT_SET_TOUR
    ZZNET_SPLIT_OPERATE_GET_TOUR_STATUS,          // Get window tour status, corresponds to NET_IN_SPLIT_GET_TOUR_STATUS and NET_OUT_SPLIT_GET_TOUR_STATUS
    ZZNET_SPLIT_OPERATE_GET_SCENE,                // Get in-screen window info, corresponds to NET_IN_SPLIT_GET_SCENE and NET_OUT_SPLIT_GET_SCENE
    ZZNET_SPLIT_OPERATE_OPEN_WINDOWS,             // Batch open windows, corresponds to NET_IN_SPLIT_OPEN_WINDOWS and NET_OUT_SPLIT_OPEN_WINDOWS
    ZZNET_SPLIT_OPERATE_SET_WORK_MODE,            // Set work mode, corresponds to NET_IN_SPLIT_SET_WORK_MODE and NET_OUT_SPLIT_SET_WORK_MODE
    ZZNET_SPLIT_OPERATE_GET_PLAYER,               // Get player instance, corresponds to NET_IN_SPLIT_GET_PLAYER and NET_OUT_SPLIT_GET_PLAYER
    ZZNET_WM_OPERATE_SET_WORK_MODE,               // Set window work mode, corresponds to NET_IN_WM_SET_WORK_MODE and NET_OUT_WM_SET_WORK_MODE
    ZZNET_WM_OPERATE_GET_WORK_MODE,               // Get window work mode, corresponds to NET_IN_WM_GET_WORK_MODE and NET_OUT_WM_GET_WORK_MODE
    ZZNET_SPLIT_OPERATE_CLOSE_WINDOWS,            // Batch close windows, corresponds to NET_IN_SPLIT_CLOSE_WINDOWS and NET_OUT_SPLIT_CLOSE_WINDOWS
    ZZNET_WM_OPERATE_SET_FISH_EYE_PARAM,          // Set output screen fisheye correction rules, corresponds to NET_IN_WM_SET_FISH_EYE_PARAM and NET_OUT_WM_SET_FISH_EYE_PARAM
	ZZNET_WM_OPERATE_SET_CORRIDOR_MODE,			// Set window corridor mode, corresponds to NET_IN_WM_SET_CORRIDOR_MODE and NET_OUT_WM_SET_CORRIDOR_MODE
	ZZNET_WM_OPERATE_GET_CORRIDOR_MODE,			// Get window corridor mode, corresponds to NET_IN_WM_GET_CORRIDOR_MODE and NET_OUT_WM_GET_CORRIDOR_MODE
	ZZNET_WM_OPERATE_SET_VOLUME_COLUMN,			// Set volume column display enable mode, corresponds to NET_IN_WM_SET_VOLUME_COLUMN and NET_OUT_WM_SET_VOLUME_COLUMN
	ZZNET_WM_OPERATE_GET_VOLUME_COLUMN,			// Get volume column display enable mode, corresponds to NET_IN_WM_GET_VOLUME_COLUMN and NET_OUT_WM_GET_VOLUME_COLUMN
	ZZNET_WM_OPERATE_SET_BACKGROUND,				// Set window background image, corresponds to NET_IN_WM_SET_BACKGROUND and NET_OUT_WM_SET_BACKGROUND
	ZZNET_WM_OPERATE_GET_BACKGROUND,				// Get window background image, corresponds to NET_IN_WM_GET_BACKGROUND and NET_OUT_WM_GET_BACKGROUND
} ZZNET_SPLIT_OPERATE_TYPE;


// Set Source Border Highlight Enable Switch Input Parameters
typedef struct tagZZNET_IN_SPLIT_SET_HIGHLIGHT
{
    DWORD           dwSize; 
    int             nChannel;                   // Video output channel
    int             nWindow;                    // Window number
    BOOL            bHighLightEn;               // Border highlight enable, TRUE-Highlight
    ZZ_COLOR_RGBA   stuColor;                   // Border color 
    int				nBlinkTimes;				// Border blink times
    int				nBlinkInterval;				// Blink interval time, unit ms
}ZZNET_IN_SPLIT_SET_HIGHLIGHT;

// Set Source Border Highlight Enable Switch Output Parameters
typedef struct tagZZNET_OUT_SPLIT_SET_HIGHLIGHT
{
    DWORD           dwSize;
}ZZNET_OUT_SPLIT_SET_HIGHLIGHT;

// Set Pre-pull Source Input Parameters
typedef struct tagZZNET_IN_SPLIT_SET_PREPULLSRC 
{
    DWORD           dwSize;
    int             nChannel;                   // Video output channel
    int             nWindow;                    // Window number
    int             nSrcCount;                  // Pre-pull source count
    ZZ_SPLIT_SOURCE* pSources;                  // Pre-pull source info, memory allocated by user, size is sizeof(ZZ_SPLIT_SOURCE)*nSrcCount
} ZZNET_IN_SPLIT_SET_PREPULLSRC;

// Set Pre-pull Source Return Result
typedef struct tagZZNET_SPLIT_SET_PREPULLSRC_RESULT 
{
    DWORD           dwSize;
    BOOL            bResult;                    // Set result, TRUE-Success, FALSE-Failure
    DWORD           dwErrorCode;                // Failure error code
} ZZNET_SPLIT_SET_PREPULLSRC_RESULT;

// Set Pre-pull Source Output Parameters
typedef struct tagZZNET_OUT_SPLIT_SET_PREPULLSRC 
{
    DWORD           dwSize;
    int             nResultCount;               // Result count, same as pre-pull source count
    ZZNET_SPLIT_SET_PREPULLSRC_RESULT* pResults;  // Results
} ZZNET_OUT_SPLIT_SET_PREPULLSRC;

// Set Video Output Background Image Input Parameters
typedef struct tagZZNET_IN_SPLIT_SET_BACKGROUND
{
    DWORD            dwSize;
    int              nChannel;                   // Video output channel number
    BOOL             bEnable;                    // Enable
    const char*      pszFileName;                // Background image filename
} ZZNET_IN_SPLIT_SET_BACKGROUND;

// Set Video Output Background Image Output Parameters
typedef struct tagZZNET_OUT_SPLIT_SET_BACKGROUND 
{
    DWORD            dwSize;
} ZZNET_OUT_SPLIT_SET_BACKGROUND;

// Get Video Output Background Image Input Parameters
typedef struct tagZZNET_IN_SPLIT_GET_BACKGROUND 
{
    DWORD            dwSize;
    int              nChannel;                   // Video output channel number
} ZZNET_IN_SPLIT_GET_BACKGROUND;

// Get Video Output Background Image Output Parameters
typedef struct tagZZNET_OUT_SPLIT_GET_BACKGROUND 
{
    DWORD            dwSize;
    BOOL             bEnable;                            // Enable
    char             szFileName[ZZ_COMMON_STRING_256];   // Background image filename
} ZZNET_OUT_SPLIT_GET_BACKGROUND;

// Set Window Background Image Input Parameters
typedef struct tagZZNET_IN_WM_SET_BACKGROUND
{
	DWORD				dwSize;
	int					nChannel;							// Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
	char			   *pszCompositeID;						// Composite screen ID
	int					nWindowID;							// Window ID
	BOOL				bEnable;							// Whether to overlay background image
	char				szFileName[ZZ_COMMON_STRING_128];	// Background image filename
} ZZNET_IN_WM_SET_BACKGROUND;

// Set Window Background Image Output Parameters
typedef struct tagZZNET_OUT_WM_SET_BACKGROUND
{
	DWORD            	dwSize;
} ZZNET_OUT_WM_SET_BACKGROUND;

// Get Window Background Image Input Parameters
typedef struct tagZZNET_IN_WM_GET_BACKGROUND
{
	DWORD            	dwSize;
	int					nChannel;				// Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
	char			   *pszCompositeID;			// Composite screen ID
	int					nWindowID;				// Window ID
} ZZNET_IN_WM_GET_BACKGROUND;

// Get Window Background Image Output Parameters
typedef struct tagZZNET_OUT_WM_GET_BACKGROUND
{
	DWORD            	dwSize;
	BOOL             	bEnable;                            // Whether to overlay background image
    char             	szFileName[ZZ_COMMON_STRING_128];   // Background image filename
} ZZNET_OUT_WM_GET_BACKGROUND;

// Window Z Order
typedef enum tagZZNET_WINDOW_ZORDER
{
    ZZNET_WINDOW_ZORDER_TOP,                              // Top layer
    ZZNET_WINDOW_ZORDER_BOTTOM,                           // Bottom layer
    ZZNET_WINDOW_ZORDER_UP,                               // Move up one layer
    ZZNET_WINDOW_ZORDER_DOWN,                             // Move down one layer
} ZZNET_WINDOW_ZORDER;

// Window Layering Order
typedef struct tagZZ_WND_ZORDER
{
    DWORD               dwSize;
    unsigned int        nWindowID;                      // Window ID
    unsigned int        nZOrder;                        // Z Order
} ZZ_WND_ZORDER;

// Set Window Z Order Input Parameters
typedef struct tagZZNET_IN_SPLIT_SET_ZORDER 
{
    DWORD               dwSize;
    int                 nChannel;                       // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    const char*         pszCompositeID;                 // Composite screen ID
    int                 nWindow;                        // Window number
    ZZNET_WINDOW_ZORDER   emZOrder;                       // Adjusted Z Order
} ZZNET_IN_SPLIT_SET_ZORDER;

// Set Window Z Order Output Parameters, Adjusting one window's Z order affects all windows, returns Z order of all windows after adjustment
typedef struct tagZZNET_OUT_SPLIT_SET_ZORDER
{
    DWORD               dwSize;
    ZZ_WND_ZORDER*      pZOders;                        // Window order array, memory allocated by user, size is sizeof(ZZ_WND_ZORDER)*nMaxWndCount
    int                 nMaxWndCount;                   // Window order array size
    int                 nWndCount;                      // Returned window count
} ZZNET_OUT_SPLIT_SET_ZORDER;

// Window Tour Action
typedef enum tagEM_ZZNET_WINDOW_TOUR_ACTION 
{
    EM_ZZNET_WND_TOUR_ACTION_START,                       // Start
    EM_ZZNET_WND_TOUR_ACTION_STOP,                        // Stop
} EM_ZZNET_WINDOW_TOUR_ACTION;

// Window Tour Control Input Parameters, corresponds to ZZNET_SPLIT_OPERATE_SET_TOUR
typedef struct tagZZNET_IN_SPLIT_SET_TOUR 
{
    DWORD               dwSize;
    int                 nChannel;                       // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    const char*         pszCompositeID;                 // Composite screen ID
    int                 nWindow;                        // Window number
    EM_ZZNET_WINDOW_TOUR_ACTION emAction;                 // Tour action
} ZZNET_IN_SPLIT_SET_TOUR;

// Window Tour Control Output Parameters, corresponds to ZZNET_SPLIT_OPERATE_SET_TOUR
typedef struct tagZZNET_OUT_SPLIT_SET_TOUR 
{
    DWORD               dwSize;
} ZZNET_OUT_SPLIT_SET_TOUR;

// Get Window Tour Status Input Parameters, corresponds to ZZNET_SPLIT_OPERATE_GET_TOUR_STATUS
typedef struct tagZZNET_IN_SPLIT_GET_TOUR_STATUS
{
    DWORD               dwSize;
    int                 nChannel;                       // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    const char*         pszCompositeID;                 // Composite screen ID
    int                 nWindow;                        // Window number, -1 means all windows
} ZZNET_IN_SPLIT_GET_TOUR_STATUS;

// Tour Status
typedef enum tagZZNET_TOUR_STATUS
{
    ZZNET_TOUR_UNKNOWN,                               // Unknown
    ZZNET_TOUR_START,                                 // Touring
    ZZNET_TOUR_STOP,                                  // Tour stopped
}ZZNET_TOUR_STATUS;

// Window Tour Status Info
typedef struct tagZZNET_WINDOW_TOUR_STATUS_INFO 
{
    DWORD               dwSize;
    int                 nWindow;                        // Window number
    ZZNET_TOUR_STATUS     emStatus;                       // Status
} ZZNET_WINDOW_TOUR_STATUS_INFO;

// Get Window Tour Status Output Parameters, corresponds to NET_SPLIT_OPERATE_GET_TOUR_STATUS
typedef struct tagZZNET_OUT_SPLIT_GET_TOUR_STATUS
{
    DWORD               dwSize;
    ZZNET_WINDOW_TOUR_STATUS_INFO* pstuStatus;            // Status info pointer, allocated by user. When querying window -1, indicates an array of info for multiple windows.
    int                 nMaxStatusCount;                // Max status info count, input by user
    int                 nRetStatusCount;                // Actual returned status count
} ZZNET_OUT_SPLIT_GET_TOUR_STATUS;

// Batch Open Window Input Parameters, corresponds to ZZNET_SPLIT_OPERATE_OPEN_WINDOWS
typedef struct tagZZNET_IN_SPLIT_OPEN_WINDOWS 
{
    DWORD               dwSize;
    int                 nChannel;                       // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    const char*         pszCompositeID;                 // Composite screen ID
    int                 nWindowNum;                     // Window count
    ZZNET_RECT*           pstuWindowRects;                // Window area array, memory allocated by user, size is sizeof(NET_RECT)*nWindowNum
    BOOL                bDirectable;                    // Satisfies direct pass-through condition
} ZZNET_IN_SPLIT_OPEN_WINDOWS;

// Window Info
typedef struct tagZZNET_SPLIT_WINDOW_INFO
{
    DWORD               dwSize;
    int                 nWindowID;                      // Window ID
    int                 nZOrder;                        // Z Order
    char                szControlID[ZZ_DEV_ID_LEN];     // Control ID
} ZZNET_SPLIT_WINDOW_INFO;

// Batch Open Window Output Parameters, corresponds to ZZNET_SPLIT_OPERATE_OPEN_WINDOWS
typedef struct tagZZNET_OUT_SPLIT_OPEN_WINDOWS 
{
    DWORD               dwSize;
    ZZNET_SPLIT_WINDOW_INFO*  pstuWindows;                // Window info, memory allocated by user, size is sizeof(NET_SPLIT_WINDOW_INFO)*nMaxWindowCount
    int                 nMaxWindowCount;                // Max window info count, input by user
    int                 nRetWindowCount;                // Number of opened windows
} ZZNET_OUT_SPLIT_OPEN_WINDOWS;

// Screen Split Work Mode
typedef enum tagZZNET_SPLIT_WORK_MODE
{
    ZZNET_SPLIT_WORK_MODE_UNKNOWN,                        // Unknown
    ZZNET_SPLIT_WORK_MODE_LOCAL,                          // Local normal mode
    ZZNET_SPLIT_WORK_MODE_REPLAY,                         // Replay mode
}ZZNET_SPLIT_WORK_MODE;

// Set Work Mode Input Parameters, corresponds to ZZNET_SPLIT_OPERATE_SET_WORK_MODE
typedef struct tagZZNET_IN_SPLIT_SET_WORK_MODE 
{
    DWORD               dwSize;
    int                 nChannel;                       // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    const char*         pszCompositeID;                 // Composite screen ID
    ZZNET_SPLIT_WORK_MODE emMode;                         // Work Mode
}ZZNET_IN_SPLIT_SET_WORK_MODE;

// Set Work Mode Output Parameters, corresponds to ZZNET_SPLIT_OPERATE_SET_WORK_MODE
typedef struct tagZZNET_OUT_SPLIT_SET_WORK_MODE 
{
    DWORD               dwSize;
}ZZNET_OUT_SPLIT_SET_WORK_MODE;

// Player Type
typedef enum tagZZNET_SPLIT_PLAYER_TYPE
{
    ZZNET_SPLIT_PLAYER_TYPE_UNKNOWN,                       // Unknown
    ZZNET_SPLIT_PLAYER_TYPE_FILE_LIST,                     // File List Player
    ZZNET_SPLIT_PLAYER_TYPE_FILE,                          // File Player
}ZZNET_SPLIT_PLAYER_TYPE;

// Get Player Instance Input Parameters, corresponds to ZZNET_SPLIT_OPERATE_GET_PLAYER
typedef struct tagZZNET_IN_SPLIT_GET_PLAYER
{
    DWORD                 dwSize;
    int                   nChannel;                       // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    const char*           pszCompositeID;                 // Composite screen ID
    ZZNET_SPLIT_PLAYER_TYPE emType;                         // Player Type
    int                   nWindow;                        // Window number where the player is located
}ZZNET_IN_SPLIT_GET_PLAYER;

// Get Player Instance Output Parameters, corresponds to ZZNET_SPLIT_OPERATE_GET_PLAYER
typedef struct tagZZNET_OUT_SPLIT_GET_PLAYER
{
    DWORD                 dwSize;
    LLONG                 lPlayerID;                      // Player Instance ID
}ZZNET_OUT_SPLIT_GET_PLAYER;

// Window Work Mode
typedef enum tagZZNET_WM_WORK_MODE
{
    ZZNET_WM_WORK_MODE_UNKNOWN,                             // Unknown
    ZZNET_WM_WORK_MODE_DISPLAY,                             // Preview Mode
    ZZNET_WM_WORK_MODE_REPLAY,                              // Replay Mode  
}ZZNET_WM_WORK_MODE;

// Set Window Work Mode Input Parameters, corresponds to ZZNET_WM_OPERATE_SET_WORK_MODE
typedef struct tagZZNET_IN_WM_SET_WORK_MODE
{
    DWORD                 dwSize;
    int                   nChannel;                       // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    const char*           pszCompositeID;                 // Composite screen ID
    int                   nWindow;                        // Window number
    ZZNET_WM_WORK_MODE      emMode;                         // Window work mode
}ZZNET_IN_WM_SET_WORK_MODE;

// Set Window Work Mode Output Parameters, corresponds to ZZNET_WM_OPERATE_SET_WORK_MODE
typedef struct tagZZNET_OUT_WM_SET_WORK_MODE
{
    DWORD                 dwSize;
}ZZNET_OUT_WM_SET_WORK_MODE;

// Get Window Work Mode Input Parameters, corresponds to ZZNET_WM_OPERATE_GET_WORK_MODE
typedef struct tagZZNET_IN_WM_GET_WORK_MODE
{
    DWORD                 dwSize;
    int                   nChannel;                       // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    const char*           pszCompositeID;                 // Composite screen ID
    int                   nWindow;                        // Window number
}ZZNET_IN_WM_GET_WORK_MODE;

// Get Window Work Mode Output Parameters, corresponds to NET_WM_OPERATE_GET_WORK_MODE
typedef struct tagZZNET_OUT_WM_GET_WORK_MODE
{
    DWORD                 dwSize;
    ZZNET_WM_WORK_MODE      emMode;                         // Window work mode
}ZZNET_OUT_WM_GET_WORK_MODE;

// Set Window Corridor Mode Input Parameters, corresponds to ZZNET_WM_OPERATE_SET_CORRIDOR_MODE
typedef struct tagZZNET_IN_WM_SET_CORRIDOR_MODE
{
	DWORD                 dwSize;			// User assigns struct size when using
	int 				  nChannel;			// Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
	const char* 		  pszCompositeID;	// Composite screen ID
	int 				  nWindow;			// Window number
	BOOL	  			  bIsCorridor;		// Window corridor mode (TRUE: On, FALSE: Off)
} ZZNET_IN_WM_SET_CORRIDOR_MODE;

// Set Window Corridor Mode Output Parameters, corresponds to ZZNET_WM_OPERATE_SET_CORRIDOR_MODE
typedef struct tagZZNET_OUT_WM_SET_CORRIDOR_MODE
{
	DWORD                 dwSize;		// User assigns struct size when using
} ZZNET_OUT_WM_SET_CORRIDOR_MODE;

// Get Window Corridor Mode Input Parameters, corresponds to ZZNET_WM_OPERATE_GET_CORRIDOR_MODE
typedef struct tagZZNET_IN_WM_GET_CORRIDOR_MODE
{
	DWORD                 dwSize;			// User assigns struct size when using
	int 				  nChannel;			// Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
	const char* 		  pszCompositeID;	// Composite screen ID
	int 				  nWindow;			// Window number
} ZZNET_IN_WM_GET_CORRIDOR_MODE;

// Get Window Corridor Mode Output Parameters, corresponds to NET_WM_OPERATE_GET_CORRIDOR_MODE
typedef struct tagZZNET_OUT_WM_GET_CORRIDOR_MODE
{
	DWORD                 dwSize;			// User assigns struct size when using
	BOOL	  			  bIsCorridor;		// Window corridor mode (TRUE: On, FALSE: Off)
} ZZNET_OUT_WM_GET_CORRIDOR_MODE;

// Set Volume Column Display Enable Mode Input Parameters, corresponds to NET_WM_OPERATE_SET_VOLUME_COLUMN
typedef struct tagZZNET_IN_WM_SET_VOLUME_COLUMN
{
	DWORD                 dwSize;			// User assigns struct size when using
	int 				  nChannel;			// Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
	const char* 		  pszCompositeID;	// Composite screen ID
	BOOL				  bIsEnable;	    // Whether to display volume column (TRUE: Display, FALSE: Off)
} ZZNET_IN_WM_SET_VOLUME_COLUMN;				

// Set Volume Column Display Enable Mode Output Parameters, corresponds to ZZNET_WM_OPERATE_SET_VOLUME_COLUMN
typedef struct tagZZNET_OUT_WM_SET_VOLUME_COLUMN
{
	DWORD				   dwSize;			// User assigns struct size when using
} ZZNET_OUT_WM_SET_VOLUME_COLUMN;

// Get Volume Column Display Enable Mode Input Parameters, corresponds to ZZNET_WM_OPERATE_GET_VOLUME_COLUMN
typedef struct tagZZNET_IN_WM_GET_VOLUME_COLUMN
{
	DWORD                 dwSize;			// User assigns struct size when using
	int 				  nChannel;			// Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
	const char* 		  pszCompositeID;	// Composite screen ID
} ZZNET_IN_WM_GET_VOLUME_COLUMN;

// Get Volume Column Display Enable Mode Output Parameters, corresponds to ZZNET_WM_OPERATE_GET_VOLUME_COLUMN
typedef struct tagZZNET_OUT_WM_GET_VOLUME_COLUMN
{
	DWORD				   dwSize;			// User assigns struct size when using
	BOOL				   bIsEnable;		// Whether to display volume column (TRUE: Display, FALSE: Off)	
} ZZNET_OUT_WM_GET_VOLUME_COLUMN;

// Batch Close Windows Input Parameters, corresponds to ZZNET_SPLIT_OPERATE_CLOSE_WINDOWS
typedef struct tagZZNET_IN_SPLIT_CLOSE_WINDOWS
{
    DWORD               dwSize;
    int                 nChannel;                       // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    const char*         pszCompositeID;                 // Composite screen ID
    int*                pnWindows;                      // Pointer to window number array, memory allocated by user, size is sizeof(int)*nWindowCount
    int                 nWindowCount;                   // Window count
} ZZNET_IN_SPLIT_CLOSE_WINDOWS;

// Close Window Operation Result
typedef struct tagZZNET_SPLIT_CLOSE_WINDOW_RESULT 
{
    BOOL                bResult;                        // Result
    char                reserved[256];                  // Reserved bytes
} ZZNET_SPLIT_CLOSE_WINDOW_RESULT ;

// Batch Close Windows Output Parameters, corresponds to ZZNET_SPLIT_OPERATE_CLOSE_WINDOWS
typedef struct tagZZNET_OUT_SPLIT_CLOSE_WINDOWS
{
    DWORD               dwSize;
    ZZNET_SPLIT_CLOSE_WINDOW_RESULT* pstuResults;         // Result array, memory allocated by user, size is sizeof(NET_SPLIT_CLOSE_WINDOW_RESULT)*nMaxResultCount. Can be NULL if results are not needed.
    int                 nMaxResultCount;                // Max result array count, input by user.
    int                 nRetResultCount;                // Returned result count
} ZZNET_OUT_SPLIT_CLOSE_WINDOWS;


// Get In-Screen Window Info Input Parameters, corresponds to ZZNET_SPLIT_OPERATE_GET_SCENE
typedef struct tagZZNET_IN_SPLIT_GET_SCENE 
{
    DWORD               dwSize;
    int                 nChannel;                       // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    const char*         pszCompositeID;                 // Composite screen ID
}ZZNET_IN_SPLIT_GET_SCENE;

// Get In-Screen Window Info Output Parameters, corresponds to ZZNET_SPLIT_OPERATE_GET_SCENE
typedef struct tagZZNET_OUT_SPLIT_GET_SCENE 
{
    DWORD               dwSize;
    ZZ_SPLIT_SCENE      stuScene;                       // Window info
}ZZNET_OUT_SPLIT_GET_SCENE;

// ZZNETSDK_SetSplitWindowRect Input Parameters (Set Window Position)
typedef struct tagZZ_IN_SPLIT_SET_RECT
{
    DWORD               dwSize;
    int                 nChannel;                   // Channel number (Screen number)
    UINT                nWindowID;                  // Window Index
    ZZ_RECT             stuRect;                    // Window Position, 0~8192
    BOOL                bDirectable;                // Whether coordinates meet direct pass-through conditions. Direct pass-through means in splicing screen mode, this window area matches the physical screen area exactly.
} ZZ_IN_SPLIT_SET_RECT;

// ZZNETSDK_SetSplitWindowRect Interface Output Parameters (Set Window Position)
typedef struct tagZZ_OUT_SPLIT_SET_RECT
{
    DWORD               dwSize;
} ZZ_OUT_SPLIT_SET_RECT;

// ZZNETSDK_GetSplitWindowRect Interface Input Parameters (Get Window Position)
typedef struct tagZZ_IN_SPLIT_GET_RECT
{
    DWORD               dwSize;
    int                 nChannel;                  // Channel number (Screen number)
    UINT                nWindowID;                 // Window Index
} ZZ_IN_SPLIT_GET_RECT;

// ZZNETSDK_GetSplitWindowRect Interface Output Parameters (Get Window Position)
typedef struct tagZZ_OUT_SPLIT_GET_RECT
{
    DWORD               dwSize;    
    ZZ_RECT             stuRect;                   // Window Position, 0~8192
} ZZ_OUT_SPLIT_GET_RECT;




// Output Screen Fisheye Correction Mode
typedef enum tagZZNET_WM_FISHEYE_CALIBRATE_MODE
{
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_UNKOWN ,            // Unknown mode
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_CLOSE ,             // Close fisheye algorithm
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_ORIGINAL,           // Original mode (Square) with zoom ratio
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_PANORAMA,           // 1P
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_PAN_PLUS_ONE,       // 1P+1
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_DOUBLE_PANORAMA,    // 2P        
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_ORI_DOUBLE_PAN,     // 1+2P
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_ORI_PLUS_THREEE,    // 1+3
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_PAN_PLUS_THREEE,    // 1P+3
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_ORI_PLUS_TWO,       // 1+2
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_ORI_PLUS_FOUR,      // 1+4
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_PAN_PLUS_FOUR,      // 1P+4
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_PAN_PLUS_SIX,       // 1P+6
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_ORI_PLUS_EIGHT,     // 1+8
    ZZNET_WM_FISHEYE_CALIBRATE_MODE_PAN_PLUS_EIGHT,     // 1P+8
}ZZNET_WM_FISHEYE_CALIBRATE_MODE;

// Fisheye Correction Window Region Parameters
typedef struct tagZZNET_WM_FISH_EYE_REGION_PARAM
{
    int     nCoordinateX;         // X coordinate of window center corresponding to original circle
    int     nCoordinateY;         // Y coordinate of window center corresponding to original circle
    int     nAngleH;              // Horizontal angle of correction region range centered at X, Y
    int     nAngleV;              // Vertical angle of correction region range centered at X, Y
    int 	nAvailable;			  // Indicates if available
    BYTE    Reserved[124];        // Reserved bytes
}ZZNET_WM_FISH_EYE_REGION_PARAM;

#define ZZ_MAX_FISH_EYE_REGION_NUM     9
// Mode initialization screen info, applicable for restoring to the previous state when switching modes
typedef struct tagZZNET_WM_SET_FISHEYE_INIT_PARAM
{
    BOOL                            bUseRegion;         // If TRUE, use the following members for initialization; if FALSE, the following members are invalid
    int                             nCircular;          // Annular offset (Meaningful in fisheye display modes with original image, e.g., screen 1 in 1+3, 1+8 modes)
    int                             nPanorama;          // Panorama offset (Meaningful in fisheye display modes with panorama, e.g., 1P, 2P modes)
	int                             nFishEyeRegionNum;  // Number of fisheye correction window region parameters (array count equals actual correction mode. e.g., 1+3 has 4 elements)
    ZZNET_WM_FISH_EYE_REGION_PARAM    stFishEyeRegions[ZZ_MAX_FISH_EYE_REGION_NUM];    // Fisheye correction window region parameters info
    BYTE                            Reserved[1024];                       // Reserved bytes
}ZZNET_WM_SET_FISHEYE_INIT_PARAM;

// Electronic PTZ (ePTZ) Zoom and Move Parameters
typedef struct tagZZNET_WM_SET_FISHEYE_EPTZ_PARAM
{
	int 							nOptWayType;		// Operation type (represents arg1 during fisheye PTZ control, indicates move or zoom)
	int 							nOptWinNum; 		// Small window number (currently operating small window number)
	int 							nOptWayData;		// Operation data (represents data size during fisheye PTZ control. Used with OptWayType)
	BYTE                            Reserved[512];      // Reserved bytes
}ZZNET_WM_SET_FISHEYE_EPTZ_PARAM;

// Set Output Screen Fisheye Correction Rules Input Parameters, corresponds to ZZNET_IN_WM_SET_FISH_EYE_PARAM
typedef struct tagZZNET_IN_WM_SET_FISH_EYE_PARAM
{
    DWORD                           dwSize;
    int                             nChannel;            // Output channel number or composite screen virtual channel number, valid when pszCompositeID is NULL
    const char*                     pszCompositeID;      // Composite screen ID
    int                             nWindowID;           // Window number corresponding to the output screen

    ZZNET_FISHEYE_MOUNT_MODE          emMount;            // Fisheye mount mode
    ZZNET_WM_FISHEYE_CALIBRATE_MODE   emCalibrate;        // Fisheye calibration mode
    ZZNET_WM_SET_FISHEYE_INIT_PARAM   stInitParam;        // Mode initialization screen info   
    ZZNET_WM_SET_FISHEYE_EPTZ_PARAM	stEPtzParam;		// Electronic PTZ zoom and move parameters
}ZZNET_IN_WM_SET_FISH_EYE_PARAM;

// Set Output Screen Fisheye Correction Rules Output Parameters, corresponds to ZZNET_OUT_WM_SET_FISH_EYE_PARAM
typedef struct tagZZNET_OUT_WM_SET_FISH_EYE_PARAM
{
    DWORD dwSize;
}ZZNET_OUT_WM_SET_FISH_EYE_PARAM;


// Recording status information for each day of a certain month
typedef struct
{
    BYTE        flag[32];           // Recording status mask for each day in a month, 0 means none, 1 means present.
    BYTE        Reserved[64];       // Reserved
}ZZNET_RECORD_STATUS, *LPZZNET_RECORD_STATUS;



// Asynchronous query result callback function prototype,
// nError = 0 Query successful;
// nError = 1 Memory allocation failed;
// nError = 2 Timeout, i.e., specified time period not fully queried within timeout, pFileinfos,nFileNum return already queried file list;
// nError = 3 Device returned data validation failed;
// nError = 4 Failed to send query request
typedef void (CALLBACK *ffQueryRecordFileCallBack)(LLONG lQueryHandle, LPZZNET_RECORDFILE_INFO pFileinfos, int nFileNum, int nError, void *pReserved, LDWORD dwUser);

// ZZNETSDK_StartQueryRecordFile Interface Input Parameters
typedef struct tagZZNET_IN_START_QUERY_RECORDFILE
{ 
    DWORD               dwSize;                            // Structure size, caller must initialize this field
    int                 nChannelId;                        // Channel number to query, starting from 0
    int                 nRecordFileType;                   // Recording type to query, see EM_QUERY_RECORD_TYPE
    int                 nStreamType;                       // Stream type to query, 0-Main & Extra, 1-Main, 2-Extra
    ZZNET_TIME            stStartTime;                       // Query start time
    ZZNET_TIME            stEndTime;                         // Query end time
    char*               pchCardid;                         // Card number info, valid only when querying by card number, memory allocated by user
														   // If nRecordFileType = 4 or 5 or 10, memory size not exceeding 256 bytes
														   // If nRecordFileType = 8, memory size not exceeding 20 bytes
    int                 nWaitTime;                         // Timeout wait time, unit ms 
    ffQueryRecordFileCallBack cbFunc;                       // Query result callback function 
    LDWORD              dwUser;                            // User info
	BOOL				bByTime;						   // Whether to query by time
}ZZNET_IN_START_QUERY_RECORDFILE;

typedef struct tagZZNET_OUT_START_QUERY_RECORDFILE
{
    DWORD                dwSize;                           // Structure size
    LLONG                lQueryHandle;                     // Return handle    
}ZZNET_OUT_START_QUERY_RECORDFILE;

// ZZNETSDK_FindFramInfo Interface Input Parameters
typedef struct __ZZNET_IN_FIND_FRAMEINFO_PRAM
{
    DWORD                 dwSize;                   // Structure size 
    BOOL                  abFileName;               // Whether filename is a valid query condition, if filename is valid, file info (stRecordInfo) need not be filled
    char                  szFileName[MAX_PATH];     // File Name
    ZZNET_RECORDFILE_INFO   stuRecordInfo;            // File Info
    DWORD                 dwFramTypeMask;           // Frame type mask, see "Frame Type Mask Definition"
}ZZNET_IN_FIND_FRAMEINFO_PRAM;

// ZZNETSDK_FindFramInfo Interface Output Parameters
typedef struct __ZZNET_OUT_FIND_FRAMEINFO_PRAM
{
    DWORD                 dwSize;               // Structure size 
    LLONG                 lFindHandle;          // File find handle
}ZZNET_OUT_FIND_FRAMEINFO_PRAM;

// Motion Detection Frame Info
typedef struct __ZZNET_MOTION_FRAME_INFO
{
    DWORD                 dwSize;               // Structure size
    ZZNET_TIME              stuTime;              // Current frame, timestamp 
    int                   nMotionRow;           // Motion detection region rows
    int                   nMotionCol;           // Motion detection region columns
    BYTE                  byRegion[ZZ_MOTION_ROW][ZZ_MOTION_COL];// Detection region, max 32*32 blocks
}ZZNET_MOTION_FRAME_INFO;

// File Frame Info
typedef struct __ZZNET_FILE_FRAME_INFO
{
    DWORD                 dwSize;               // Structure size
    int                   nChannelId;           // Channel ID
    ZZNET_TIME            stuStartTime;         // Start time
    ZZNET_TIME            stuEndTime;           // End time
    WORD                  wRecType;             // 0-Main stream record 1-Extra stream 1 record 2-Extra stream 2 3-Extra stream 3 record
    WORD                  wFameType;            // Frame type, see EM_FRAME_TYPE
    void*                 pFramInfo;            // Corresponding type frame info, space allocated by user, suggested size sizeof(NET_MOTION_FRAME_INFO)
}ZZNET_FILE_FRAME_INFO;

// ZZNETSDK_FindNextFramInfo Interface Input Parameters
typedef struct __ZZNET_IN_FINDNEXT_FRAMEINFO_PRAM
{
    DWORD                 dwSize;               // Structure size  
    int                   nFramCount;           // Number of frames to query, 0 means query all frame info meeting the condition
}ZZNET_IN_FINDNEXT_FRAMEINFO_PRAM;

// ZZNETSDK_FindNextFramInfo Interface Output Parameters
typedef struct __ZZNET_OUT_FINDNEXT_FRAMEINFO_PRAM
{
    DWORD                 dwSize;               // Structure size 
    ZZNET_FILE_FRAME_INFO*  pFramInfos;           // Frame info, space allocated by user, size is sizeof(ZZNET_FILE_FRAM_INFO) * nMaxFramCount
    int                   nMaxFramCount;        // Number of frame info allocated by user
    int                   nRetFramCount;        // Actual number of frame info returned
}ZZNET_OUT_FINDNEXT_FRAMEINFO_PRAM;


// Tag Array
typedef struct tagZZNET_FILE_STREAM_TAG_INFO
{
	DWORD				dwSize;									// Structure size
	ZZNET_TIME			stuTime;								// Tag time
	char				szContext[ZZ_COMMON_STRING_64];			// Tag content, Chinese must use utf8 encoding
	char				szUserName[ZZ_COMMON_STRING_32];		// Username, Chinese must use utf8 encoding, EVS customization addition
	char				szChannelName[ZZ_COMMON_STRING_64];		// Channel name, Chinese must use utf8 encoding, EVS customization addition
} ZZNET_FILE_STREAM_TAG_INFO;

// File Type
typedef enum tagZZNET_FILE_STREAM_TYPE
{
	ZZNET_FILE_STREAM_TYPE_UNKNOWN = 0,				// Unknown
	ZZNET_FILE_STREAM_TYPE_NORMAL,					// Normal
	ZZNET_FILE_STREAM_TYPE_ALARM,						// Alarm
	ZZNET_FILE_STREAM_TYPE_DETECTION,					// Motion Detection
} ZZNET_FILE_STREAM_TYPE;

// Queried Tag Information
typedef struct tagZZNET_FILE_STREAM_TAG_INFO_EX
{
	DWORD					dwSize;	
	ZZNET_TIME				stuTime;									// Tag time relative to video, precise to second
	int						nMillisecond;								// Millisecond
	int						nSequence;									// Video sequence number
	char					szContext[ZZ_COMMON_STRING_64];				// Tag content, Chinese must use utf8 encoding
	ZZNET_TIME				stuStartTime;								// Recording file start time
	ZZNET_TIME				stuEndTime;									// Recording file end time
	ZZNET_FILE_STREAM_TYPE	emType;										// File Type
	char					szUserName[ZZ_COMMON_STRING_32];			// Username, Chinese must use utf8 encoding, EVS customization addition
	char					szChannelName[ZZ_COMMON_STRING_64];			// Channel name, Chinese must use utf8 encoding, EVS customization addition
} ZZNET_FILE_STREAM_TAG_INFO_EX;



// ZZNETSDK_FileStreamClearTags / ZZNETSDK_FileStreamSetTags Interface Input Parameters
typedef struct tagZZNET_IN_FILE_STREAM_TAGS_INFO
{
	DWORD						dwSize;								// Structure size 
	int							nArrayCount;						// Tag array count
	ZZNET_FILE_STREAM_TAG_INFO*	pstuTagInfo;						// Tag array, relationship between items is "AND", memory allocated by user, size is sizeof(ZZNET_FILE_STREAM_TAG_INFO)*nArrayCount						
} ZZNET_IN_FILE_STREAM_TAGS_INFO;

// ZZNETSDK_FileStreamClearTags / ZZNETSDK_FileStreamSetTags Interface Output Parameters
typedef struct tagZZNET_OUT_FILE_STREAM_TAGS_INFO
{
	DWORD						dwSize;					// Structure size 
} ZZNET_OUT_FILE_STREAM_TAGS_INFO;


// ZZNETSDK_FileStreamGetTags Interface Input Parameters
typedef struct tagZZNET_IN_FILE_STREAM_GET_TAGS_INFO
{
	DWORD					dwSize;					// Structure size 
} ZZNET_IN_FILE_STREAM_GET_TAGS_INFO;

// ZZNETSDK_FileStreamGetTags / ZZNETSDK_FileStreamfilterTags Interface Output Parameters
typedef struct tagZZNET_OUT_FILE_STREAM_GET_TAGS_INFO
{
	DWORD							dwSize;								// Structure size 
	int								nMaxNumber;							// Max tag array count
	int								nRetTagsNumber;						// Actual returned tag array count
	ZZNET_FILE_STREAM_TAG_INFO_EX*	pstuTagInfo;						// Tag array
} ZZNET_OUT_FILE_STREAM_GET_TAGS_INFO;

// ZZNETSDK_StartQueryLog Input Parameters
typedef struct tagZZNET_IN_START_QUERYLOG
{
    DWORD               dwSize;
} ZZNET_IN_START_QUERYLOG;

// ZZNETSDK_StartQueryLog Output Parameters
typedef struct tagZZNET_OUT_START_QUERYLOG
{
    DWORD               dwSize;
}ZZNET_OUT_START_QUERYLOG;


// Detailed Log Message
typedef struct tagZZNET_LOG_MESSAGE
{
    DWORD               dwSize;
    char                szLogMessage[ZZ_COMMON_STRING_1024];    // Log Content
} ZZNET_LOG_MESSAGE;

// Log Information
typedef struct tagZZNET_LOG_INFO
{
    DWORD               dwSize;
    ZZNET_TIME            stuTime;                        // Time 
    char                szUserName[ZZ_COMMON_STRING_32];// Operator
    char                szLogType[ZZ_COMMON_STRING_128];// Type
    ZZNET_LOG_MESSAGE     stuLogMsg;                      // Log Message
} ZZNET_LOG_INFO;

// ZZNETSDK_QueryNextLog Input Parameters
typedef struct tagZZNET_IN_QUERYNEXTLOG
{
    DWORD               dwSize;
    int                 nGetCount;      // Number of logs to query
}ZZNET_IN_QUERYNEXTLOG;

// ZZNETSDK_QueryNextLog Output Parameters
typedef struct tagZZNET_OUT_QUERYNEXTLOG
{
    DWORD               dwSize;
    int                 nMaxCount;      // Number of structs allocated by user, must be >= nGetCount in NET_IN_GETNEXTLOG
    ZZNET_LOG_INFO*       pstuLogInfo;    // Returned log info, buffer size specified by user, size is nMaxCount*sizeof(NET_LOG_INFO)
    int                 nRetCount;      // Actual returned log count
}ZZNET_OUT_QUERYNEXTLOG;




// Device Capability Types, corresponding to ZZNETSDK_GetDevCaps interface
#define ZZNET_DEV_CAP_SEQPOWER          0x01                // Power Sequencer Capability, pInBuf=NET_IN_CAP_SEQPOWER*, pOutBuf=NET_OUT_CAP_SEQPOWER*
#define ZZNET_ENCODE_CFG_CAPS           0x02                // Device Encode Configuration Capability, pInBuf=NET_IN_ENCODE_CFG_CAPS*, pOutBuf= NET_OUT_ENCODE_CFG_CAPS*
#define ZZNET_VIDEOIN_FISHEYE_CAPS      0x03                // Fisheye Capability, pInBuf=NET_IN_VIDEOIN_FISHEYE_CAPS*, pOutBuf=NET_OUT_VIDEOIN_FISHEYE_CAPS*
#define ZZNET_COMPOSITE_CAPS            0x04                // Pre-acquire composite capabilities based on specified window number, pInBuf=NET_IN_COMPOSITE_CAPS*, pOutBuf=NET_OUT_COMPOSITE_CAPS*
#define ZZNET_VIDEO_DETECT_CAPS         0x05                // Get Video Detection Input Capability Set, pInBuf=NET_IN_VIDEO_DETECT_CAPS* , pOutBuf=NET_OUT_VIDEO_DETECT_CAPS*
#define ZZNET_THERMO_GRAPHY_CAPS        0x06                // Thermal Camera Attribute Capability, pInBuf=NET_IN_THERMO_GETCAPS*, pOutBuf=NET_OUT_THERMO_GETCAPS*
#define ZZNET_RADIOMETRY_CAPS           0x07                // Thermal Radiometry Global Configuration Capability, pInBuf=NET_IN_RADIOMETRY_GETCAPS*, pOutBuf=NET_OUT_RADIOMETRY_GETCAPS*
#define ZZNET_POS_CAPS                  0x08                // POS Capability, pInBuf = NET_IN_POS_GETCAPS *, pOutBuf = NET_OUT_POS_GETCAPS *
#define ZZNET_USER_MNG_CAPS             0x09                // User Management Capability, pInBuf = NET_IN_USER_MNG_GETCAPS *, pOutBuf = NET_OUT_USER_MNG_GETCAPS *
#define ZZNET_MEDIAMANAGER_CAPS         0x0a                // Get capabilities of VideoInput, pInBuf=NET_IN_MEDIAMANAGER_GETCAPS*, pOutBuf=NET_OUT_MEDIAMANAGER_GETCAPS*
#define	ZZNET_VIDEO_MOSAIC_CAPS			0x0b				// Get channel mosaic overlay capability, pInBuf=NET_IN_MEDIA_VIDEOMOSAIC_GETCAPS*, pOutBuf=NET_OUT_MEDIA_VIDEOMOSAIC_GETCAPS*
#define ZZNET_SNAP_CFG_CAPS             0x0c                // Device Snapshot Configuration Capability, pInBuf=NET_IN_SNAP_CFG_CAPS*, pOutBuf= NET_OUT_SNAP_CFG_CAPS*
#define ZZNET_VIDEOIN_CAPS              0x0d                // Device Video Output Capability, pInBUf = NET_IN_VIDEOIN_CAPS*, pOutBuf = NET_OUT_VIDEOIN_CAPS*
#define ZZNET_FACE_BOARD_CAPS           0x0e                // Face Board Device Capability Set, pInBuf = NET_IN_FACEBOARD_CAPS*, pOutBuf = NET_OUT_FACEBOARD_CAPS*
#define ZZNET_EXTERNALSENSOR_CAPS		0x0f				// External Sensor Management Capability Set, pInBuf = NET_IN_EXTERNALSENSOR_CAPS*, pOutBuf = NET_OUT_EXTERNALSENSOR_CAPS*
#define ZZNET_VIDEO_IMAGECONTROL_CAPS	0x10				// Image Rotation Setting Capability, pInBuf = NET_IN_VIDEO_IMAGECONTROL_CAPS*, pOutBuf = NET_OUT_VIDEO_IMAGECONTROL_CAPS*
#define ZZNET_VIDEOIN_EXPOSURE_CAPS		0x11				// Exposure Setting Capability, pInBuf = NET_IN_VIDEOIN_EXPOSURE_CAPS*, pOutBuf = NET_OUT_VIDEOIN_EXPOSURE_CAPS*
#define ZZNET_VIDEOIN_DENOISE_CAPS		0x12				// Denoise Capability, pInBuf = NET_IN_VIDEOIN_DENOISE_CAPS*, pOutBuf = NET_OUT_VIDEOIN_DENOISE_CAPS*
#define ZZNET_VIDEOIN_BACKLIGHT_CAPS	0x13				// Backlight Setting Capability, pInBuf = NET_IN_VIDEOIN_BACKLIGHT_CAPS*, pOutBuf = NET_OUT_VIDEOIN_BACKLIGHT_CAPS*
#define ZZNET_VIDEOIN_WHITEBALANCE_CAPS	0x14				// White Balance Setting Capability, pInBuf = NET_IN_VIDEOIN_WHITEBALANCE_CAPS*, pOutBuf = NET_OUT_VIDEOIN_WHITEBALANCE_CAPS*
#define ZZNET_VIDEOIN_DAYNIGHT_CAPS		0x15				// PTZ Movement Day/Night Setting Capability, pInBuf = NET_IN_VIDEOIN_DAYNIGHT_CAPS*, pOutBuf = NET_OUT_VIDEOIN_DAYNIGHT_CAPS*
#define ZZNET_VIDEOIN_ZOOM_CAPS			0x16				// Zoom Setting Capability, pInBuf = NET_IN_VIDEOIN_ZOOM_CAPS*, pOutBuf = NET_OUT_VIDEOIN_ZOOM_CAPS*
#define	ZZNET_VIDEOIN_FOCUS_CAPS		0x17				// Focus Setting Capability, pInBuf = NET_IN_VIDEOIN_FOCUS_CAPS*, pOutBuf = NET_OUT_VIDEOIN_FOCUS_CAPS*
#define ZZNET_VIDEOIN_SHARPNESS_CAPS	0x18				// Sharpness Setting Capability, pInBuf = NET_IN_VIDEOIN_SHARPNESS_CAPS*, pOutBuf = NET_OUT_VIDEOIN_SHARPNESS_CAPS*
#define ZZNET_VIDEOIN_COLOR_CAPS		0x19				// Image Setting Capability, pInBuf = NET_IN_VIDEOIN_COLOR_CAPS*, pOutBuf = NET_OUT_VIDEOIN_COLOR_CAPS*
#define ZZNET_GET_MASTERSLAVEGROUP_CAPS	0x1a				// Get Tracking Service Capability, pInBuf = NET_IN_GET_MASTERSLAVEGROUP_CAPS*, pOutBuf = NET_OUT_GET_MASTERSLAVEGROUP_CAPS*
#define ZZNET_FACERECOGNITIONSE_CAPS	0x1b				// Face Recognition Server Capability Query, pInBuf = NET_IN_FACERECOGNITIONSERVER_CAPSBILITYQUERY, pOutBuf = NET_OUT_FACERECOGNITIONSERVER_CAPSBILITYQUERY *
#define ZZNET_STORAGE_CAPS				0x1c				// Get Storage Capability Set, pInBuf = NET_IN_STORAGE_CAPS*, pOutBuf = NET_OUT_STORAGE_CAPS*
#define ZZNET_VIDEOIN_RAWFRAME_CAPS		0x1d				// Get Video Input Extended Capability Set, pInBuf = NET_IN_VIDEOIN_RAWFRAME_CAPS*, pOutBuf = NET_OUT_VIDEOIN_RAWFRAME_CAPS*
#define	ZZNET_COAXIAL_CONTROL_IO_CAPS	0x1e				// Get Coaxial IO Control Capability, pInBuf = NET_IN_GET_COAXIAL_CONTROL_IO_CAPS*, pOutBuf = NET_OUT_GET_COAXIAL_CONTROL_IO_CAPS*

#define ZZNET_LIGHTINGCONTROL_CAPS      0x22                /// Get Lighting Control Capability (used by IPC/SD), pInBuf =NET_IN_LIGHTINGCONTROL_CAPS* ,pOutBuf=NET_OUT_LIGHTINGCONTROL_CAPS*

#define ZZNET_VIDEO_IN_DEFOG_CAPS       0x30                /// Get Video Defog Capability Set, pInBuf = ZZNET_IN_VIDEO_IN_DEFOG_CAPS*, pOutBuf = ZZNET_OUT_VIDEO_IN_DEFOG_CAPS* 




// ISCSI Target Information
typedef struct tagZZ_ISCSI_TARGET 
{
    DWORD               dwSize;
    char                szName[ZZ_MAX_ISCSI_NAME_LEN];              // Name
    char                szAddress[ZZ_MAX_IPADDR_OR_DOMAIN_LEN];     // Server Address
    char                szUser[ZZ_NEW_USER_NAME_LENGTH];            // Username
    int                 nPort;                                      // Port
    UINT                nStatus;                                    // Status, 0-Unknown, 1-Connected, 2-Not Connected, 3-Connection Failed, 4-Auth Failed, 5-Connection Timeout, 6-Not Exists    
} ZZ_ISCSI_TARGET;
// RAID State
#define ZZ_RAID_STATE_ACTIVE            0x00000001
#define ZZ_RAID_STATE_INACTIVE          0x00000002
#define ZZ_RAID_STATE_CLEAN             0x00000004
#define ZZ_RAID_STATE_FAILED            0x00000008
#define ZZ_RAID_STATE_DEGRADED          0x00000010
#define ZZ_RAID_STATE_RECOVERING        0x00000020
#define ZZ_RAID_STATE_RESYNCING         0x00000040
#define ZZ_RAID_STATE_RESHAPING         0x00000080
#define ZZ_RAID_STATE_CHECKING          0x00000100
#define ZZ_RAID_STATE_NOTSTARTED        0x00000200

// RAID Member Information
typedef struct tagZZNET_RAID_MEMBER_INFO 
{
    DWORD               dwSize;
    DWORD               dwID;                                       // Disk ID, used to describe disk slot in the enclosure
    BOOL                bSpare;                                     // Is local hot spare, true-Local hot spare, false-RAID sub-disk
} ZZNET_RAID_MEMBER_INFO;

// RAID Information
typedef struct tagZZ_STORAGE_RAID
{
    DWORD               dwSize;
    int                 nLevel;                                     // Level    
    int                 nState;                                     // RAID state combination, e.g., ZZ_RAID_STATE_ACTIVE | ZZ_RAID_STATE_DEGRADED
    int                 nMemberNum;                                 // Number of members
    char                szMembers[ZZ_MAX_MEMBER_PER_RAID][ZZ_STORAGE_NAME_LEN];    // RAID members	
    float               fRecoverPercent;                            // Sync percentage, 0~100, valid when RAID state has "Recovering" or "Resyncing"
    float               fRecoverMBps;                               // Sync speed, Unit MBps, valid when RAID state has "Recovering" or "Resyncing"
    float               fRecoverTimeRemain;                         // Sync remaining time, Unit minutes, valid when RAID state has "Recovering" or "Resyncing"
    ZZNET_RAID_MEMBER_INFO stuMemberInfos[ZZ_MAX_MEMBER_PER_RAID];    // RAID Member Information
	int                 nRaidDevices;                               // Number of RAID devices
	int                 nTotalDevices;                              // Total number of devices
	int                 nActiveDevices;                             // Number of active devices
	int                 nWorkingDevices;                            // Number of working devices
	int                 nFailedDevices;                             // Number of failed devices
	int                 nSpareDevices;                              // Number of hot spare devices
} ZZ_STORAGE_RAID;

// Storage Partition Information
typedef struct tagZZ_STORAGE_PARTITION
{
    DWORD               dwSize;
    char                szName[ZZ_STORAGE_NAME_LEN];                // Name
    INT64               nTotalSpace;                                // Total Space, byte
    INT64               nFreeSpace;                                 // Free Space, byte
    char                szMountOn[ZZ_STORAGE_MOUNT_LEN];            // Mount point
    char                szFileSystem[ZZ_STORAGE_FILE_SYSTEM_LEN];   // File system
    int                 nStatus;                                    // Partition Status, 0-LV unavailable, 1-LV available
} ZZ_STORAGE_PARTITION;

// Expansion Cabinet (Tank) Information
typedef struct tagZZ_STORAGE_TANK 
{
    DWORD               dwSize;
    int                 nLevel;                                     // Level, Host is level 0, others follow
    int                 nTankNo;                                    // Expansion port number within the same level expansion cabinet, starts from 0
    int                 nSlot;                                      // Corresponding board card number on the main cabinet, starts from 0
} ZZ_STORAGE_TANK;

// Storage Device Status
#define ZZNET_STORAGE_DEV_OFFLINE                 0                   // Physical HDD Offline Status
#define ZZNET_STORAGE_DEV_RUNNING                 1                   // Physical HDD Running Status
#define ZZNET_STORAGE_DEV_ACTIVE                  2                   // RAID Active
#define ZZNET_STORAGE_DEV_SYNC                    3                   // RAID Sync
#define ZZNET_STORAGE_DEV_SPARE                   4                   // RAID Hot Spare (Local)
#define ZZNET_STORAGE_DEV_FAULTY                  5                   // RAID Faulty
#define ZZNET_STORAGE_DEV_REBUILDING              6                   // RAID Rebuilding
#define ZZNET_STORAGE_DEV_REMOVED                 7                   // RAID Removed
#define ZZNET_STORAGE_DEV_WRITE_ERROR             8                   // RAID Write Error
#define ZZNET_STORAGE_DEV_WANT_REPLACEMENT        9                   // RAID Needs Replacement
#define ZZNET_STORAGE_DEV_REPLACEMENT             10                  // RAID is Replacement Device
#define ZZNET_STORAGE_DEV_GLOBAL_SPARE            11                  // Global Hot Spare
#define ZZNET_STORAGE_DEV_ERROR                   12                  // Error, some partitions available
#define ZZNET_STORAGE_DEV_RAIDSUB                 13                  // This disk is currently a single disk, formerly a RAID sub-disk, may automatically join RAID after reboot

// Storage Device Information
typedef struct tagZZ_STORAGE_DEVICE 
{
    DWORD               dwSize;
    char                szName[ZZ_STORAGE_NAME_LEN];                    // Name
    INT64               nTotalSpace;                                    // Total Space, byte
    INT64               nFreeSpace;                                     // Free Space, byte
    BYTE                byMedia;                                        // Media, 0-DISK, 1-CDROM, 2-FLASH
    BYTE                byBUS;                                          // BUS, 0-ATA, 1-SATA, 2-USB, 3-SDIO, 4-SCSI
	BYTE                byVolume;                                       // Volume Type, 0-Physical Volume, 1-Raid Volume, 2-VG Virtual Volume, 3-ISCSI, 4-Independent Physical Volume, 5-Global Hot Spare Volume, 6-NAS Volume (including FTP, SAMBA, NFS)
    BYTE                byState;                                        // Physical HDD Status, values refer to NET_STORAGE_DEV_OFFLINE and NET_STORAGE_DEV_RUNNING etc.
    int                 nPhysicNo;                                      // Physical number of storage interface for same device type
    int                 nLogicNo;                                       // Logical number of storage interface for same device type
    char                szParent[ZZ_STORAGE_NAME_LEN];                  // Parent storage group name
    char                szModule[ZZ_STORAGE_NAME_LEN];                  // Device Module
    char                szSerial[ZZ_SERIALNO_LEN];                      // Device Serial Number
    char                szFirmware[ZZ_VERSION_LEN];                     // Firmware Version
    int                 nPartitionNum;                                  // Number of Partitions
    ZZ_STORAGE_PARTITION stuPartitions[ZZ_MAX_STORAGE_PARTITION_NUM];   // Partition Information
    ZZ_STORAGE_RAID     stuRaid;                                        // RAID Information, valid only for RAID (byVolume == 1)
    ZZ_ISCSI_TARGET     stuISCSI;                                       // ISCSI Information, valid only for ISCSI disk (byVolume == 3)
    BOOL                abTank;                                         // Expansion Cabinet Enable
    ZZ_STORAGE_TANK     stuTank;                                        // Info of expansion cabinet where HDD resides, valid when abTank is TRUE
} ZZ_STORAGE_DEVICE;

// Volume Type Enum
typedef enum tagZZNET_VOLUME_TYPE
{
    ZZ_VOLUME_TYPE_ALL = 0      ,      // All volumes
    ZZ_VOLUME_TYPE_PHYSICAL     ,      // Physical volume
    ZZ_VOLUME_TYPE_RAID         ,      // RAID volume
    ZZ_VOLUME_TYPE_VOLUME_GROUP ,      // VG Virtual Volume Group
    ZZ_VOLUME_TYPE_ISCSI        ,      // iSCSI volume
    ZZ_VOLUME_TYPE_INVIDUAL_PHY ,      // Independent physical volume (This physical disk is not joined in RAID, Virtual Volume Group, etc.)
    ZZ_VOLUME_TYPE_GLOBAL_SPARE ,      // Global hot spare volume
	ZZ_VOLUME_TYPE_NAS			 ,		// NAS disk (including FTP, SAMBA, NFS)
	ZZ_VOLUME_TYPE_INVIDUAL_RAID,		// Independent RAID volume (Not joined in Virtual Volume Group, etc.)
    ZZ_VOLUME_TYPE_MAX          ,
}ZZNET_VOLUME_TYPE;


#define    ZZ_MAX_DEVICE_VOLUME_NUMS        128                // Maximum limit of volume types

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_DEV_STORAGE_NAMES Type Interface Input Parameters
typedef struct tagZZNET_IN_STORAGE_DEV_NAMES
{
    DWORD                 dwSize;
    ZZNET_VOLUME_TYPE     emVolumeType;       // Volume type to get
} ZZNET_IN_STORAGE_DEV_NAMES;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_DEV_STORAGE_NAMES Type Interface Output Parameters
typedef struct tagZZNET_OUT_STORAGE_DEV_NAMES
{
    DWORD               dwSize;
    int                 nDevNamesNum;                       // Number of storage module names obtained
    char                szStoregeDevNames[ZZ_MAX_DEVICE_VOLUME_NUMS][ZZ_STORAGE_NAME_LEN]; // Device name list
}ZZNET_OUT_STORAGE_DEV_NAMES;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_DEV_STORAGE_INFOS Interface Input Parameters
typedef struct tagZZNET_IN_STORAGE_DEV_INFOS
{
    DWORD               dwSize;
    ZZNET_VOLUME_TYPE     emVolumeType;       // Volume type to get
} ZZNET_IN_STORAGE_DEV_INFOS;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_DEV_STORAGE_INFOS Interface Output Parameters
typedef struct tagZZNET_OUT_STORAGE_DEV_INFOS
{
    DWORD               dwSize;
    int                 nDevInfosNum;                      // List of storage module info obtained
    ZZ_STORAGE_DEVICE   stuStoregeDevInfos[ZZ_MAX_DEVICE_VOLUME_NUMS]; // Device info list, dwSize of ZZ_STORAGE_DEVICE must be assigned
} ZZNET_OUT_STORAGE_DEV_INFOS;

typedef enum tagZZNET_RECENCY_CAR_INFO
{
    ZZ_RECENCY_CAR_INFO_UNKNOW = 0 ,
    ZZ_RECENCY_CAR_INFOO_NEWEST    ,      // Newest
    ZZ_RECENCY_CAR_INFO_ODLEST     ,      // Oldest
    ZZ_RECENCY_CAR_INFO_MAX        ,
}ZZNET_RECENCY_CAR_INFO;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_RECENCY_JNNCTION_CAR_INFO Interface Input Parameters
typedef struct tagZZNET_IN_GET_RECENCY_JUNCTION_CAR_INFO
{
    DWORD                   dwSize;
    int                     nChannel;       // Capture channel number
    ZZNET_RECENCY_CAR_INFO    emRecencyType;  // Type of vehicle info to get, newest or oldest
    DWORD                   nIndex;         // Which vehicle info, starts from 1, if 0 also represents 1st
}ZZNET_IN_GET_RECENCY_JUNCTION_CAR_INFO;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_RECENCY_JNNCTION_CAR_INFO Interface Output Parameters
typedef struct tagZZNET_OUT_GET_RECENCY_JUNCTION_CAR_INFO
{
    DWORD           dwSize;
    ZZDEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;        // Traffic vehicle info
}ZZNET_OUT_GET_RECENCY_JUNCTION_CAR_INFO;

// 
#define ZZNET_MAX_FISHEYE_WINDOW_NUM               8         // Maximum fisheye window count

// Window Position Info
typedef struct tagZZNET_FISHEYE_WINDOW_INFO
{
    DWORD             dwSize;
    DWORD             dwWindowID;                        // Window ID
    int               nFocusX;                           // Focus X coordinate of EPtz (Electronic PTZ)
    int               nFocusY;                           // Focus Y coordinate of EPtz (Electronic PTZ)   
    int               nHorizontalAngle;                  // Horizontal Angle of EPtz
    int               nVerticalAngle;                    // Vertical Angle of EPtz
}ZZNET_FISHEYE_WINDOW_INFO;

// Corresponds to ZZNETSDK_QueryDevInfo interface, ZZNET_QUERY_DEV_FISHEYE_WININFO query fisheye window info input parameters
typedef struct tagZZNET_IN_FISHEYE_WININFO
{
    DWORD               dwSize;
    int                 nChannelId;                      // Channel Number
    int                 nWindowNum;                      // Number of windows to query
    int                 nWindows[ZZNET_MAX_FISHEYE_WINDOW_NUM]; // Window IDs, cannot repeat
}ZZNET_IN_FISHEYE_WININFO;

// Corresponds to ZZNETSDK_QueryDevInfo interface, ZZNET_QUERY_DEV_FISHEYE_WININFO query fisheye window info output parameters
typedef struct tagZZNET_OUT_FISHEYE_WININFO
{
    DWORD               dwSize;
    int                 nWindowNum;                      // Number of windows
    ZZNET_FISHEYE_WINDOW_INFO stuWindows[ZZNET_MAX_FISHEYE_WINDOW_NUM]; // Detailed window info
}ZZNET_OUT_FISHEYE_WININFO;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_LANES_STATE Interface Input Parameters
typedef struct tagZZNET_IN_GET_LANES_STATE
{
    DWORD                   dwSize;
    int                     nLaneNumber; //-1 means query all lanes, >=0 means query specific lane
}ZZNET_IN_GET_LANES_STATE;

// Traffic Light Indication Status
typedef enum tagZZNET_TRAFFIC_LIGHT_STATUS
{
    ZZ_LIGHT_STATUS_UNKNOWN  = 0   ,    // Unknown
    ZZ_LIGHT_STATUS_RED            ,    // Red light
    ZZ_LIGHT_STATUS_GREEN          ,    // Green light
    ZZ_LIGHT_STATUS_YELLOW         ,    // Yellow light
}ZZNET_TRAFFIC_LIGHT_STATUS;

// Traffic Light Indication Info
typedef struct tatZZNET_TRAFFIC_LIGHT_INFO
{
    DWORD                       dwSize;
    ZZNET_TRAFFIC_LIGHT_STATUS    emStraightLightInfo;    // Straight traffic light status
    ZZNET_TRAFFIC_LIGHT_STATUS    emLeftLightInfo;        // Left turn traffic light status
    ZZNET_TRAFFIC_LIGHT_STATUS    emRightLightInfo;       // Right turn traffic light status
    ZZNET_TRAFFIC_LIGHT_STATUS    emUTurnLightInfo;       // U-Turn traffic light status
}ZZNET_TRAFFIC_LIGHT_INFO;

// Lane Direction
typedef enum tagZZNET_TRAFFIC_DIRECTION
{
    ZZ_DIRECTION_UNKNOW    = 0 ,   // Unknown
    ZZ_DIRECTION_STRAIGHT      ,   // Straight
    ZZ_DIRECTION_LEFT          ,   // Left Turn
    ZZ_DIRECTION_RIGHT         ,   // Right Turn
    ZZ_DIRECTION_UTURN         ,   // U-Turn
}ZZNET_TRAFFIC_DIRECTION;

// Road Congestion Status
typedef enum tagZZNET_TRAFFIC_JAM_STATUS
{
    ZZ_JAM_STATUS_UNKNOW   =0  ,   // Unknown
    ZZ_JAM_STATUS_CLEAR        ,   // Clear/Free flow
    ZZ_JAM_STATUS_JAMMED       ,   // Jammed/Congested
}ZZNET_TRAFFIC_JAM_STATUS;

// Lane Information
typedef struct tagZZNET_TRAFFIC_LANE_INFO
{
    DWORD                   dwSize;
    UINT                    nLaneNumber;                                    // Lane Number, starts from 0
    UINT                    nSupportDirectionNum;                           // Number of allowed directions for the lane
    ZZNET_TRAFFIC_DIRECTION   emTrafficDirections[ZZ_MAX_LANE_DIRECTION_NUM];    // Lane Direction, indicates all allowed directions for this lane
    ZZNET_TRAFFIC_JAM_STATUS  emJamState;                                     // Road Congestion Status
    // Flow Info
    UINT                    nLargeVehicleNum;                               // Number of Large Vehicles
    UINT                    nMediumVehicleNum;                              // Number of Medium Vehicles
    UINT                    nSmallVehicleNum;                               // Number of Small Vehicles
    UINT                    nMotoNum;                                       // Number of Motorcycles
}ZZNET_TRAFFIC_LANE_INFO;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_LANES_STATE Interface Output Parameters
typedef struct tagZZNET_OUT_GET_LANES_STATE
{
    DWORD                   dwSize;
    int                     nGetLaneInfoNum;                    // Number of lane infos obtained
    ZZNET_TRAFFIC_LANE_INFO   stLaneInfos[ZZ_MAX_LANE_INFO_NUM];     // Obtained lane infos
    ZZNET_TRAFFIC_LIGHT_INFO  stLightInfo;                        // Traffic Light Indication Status
}ZZNET_OUT_GET_LANES_STATE;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_SYSTEM_INFO Type Interface Input Parameters
typedef struct tagZZNET_IN_SYSTEM_INFO
{
    DWORD               dwSize;
} ZZNET_IN_SYSTEM_INFO;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_SYSTEM_INFO Type Interface Output Parameters
typedef struct tagZZNET_OUT_SYSTEM_INFO
{
    DWORD               dwSize;
    BOOL                bHasRTC;                       // Has RTC chip (for recording system time), default TRUE means has RTC
    int                 nRetMCUNum;                   // Returned number of MCUs 	 	 
    char                szMCUVersion[ZZ_MAX_MCU_NUM][ZZ_MAX_VERSION_LEN];         // MCU Software Version
}ZZNET_OUT_SYSTEM_INFO;


// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_REG_DEVICE_NET_INFO Type Interface Input Parameters
typedef struct tagZZNET_IN_REGDEV_NET_INFO
{
    DWORD               dwSize;
    char                szDevSerial[ZZ_DEV_SERIALNO_LEN];   // Device Serial Number reported during active registration
}ZZNET_IN_REGDEV_NET_INFO;

// Network Type used for Active Registration Connection
typedef enum tagZZNET_CELLUAR_NET_TYPE 
{
    EM_ZZ_CELLUAR_NET_UNKNOW           =   -1  ,    // Unknown
    EM_ZZ_CELLUAR_NET_PRIVATE_3G_4G    =   0   ,    // Private 3G/4G network (e.g., Police internal network)
    EM_ZZ_CELLUAR_NET_COMMERCIAL_3G_4G =   1   ,    // Commercial 3G/4G network (e.g., Mobile, Telecom, etc.)
    EM_ZZ_CELLUAR_NET_MAX , 
}ZZNET_CELLUAR_NET_TYPE;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_REG_DEVICE_NET_INFO Type Interface Output Parameters
typedef struct tagZZNET_OUT_REGDEV_NET_INFO
{
    DWORD                   dwSize;
    ZZNET_CELLUAR_NET_TYPE    emCelluarNetType;           // Network Type used for Active Registration Connection
}ZZNET_OUT_REGDEV_NET_INFO;

// Subtype for Get Video Channel Attribute Command
typedef enum tagZZNET_VIDEO_CHANNEL_TYPE
{
    ZZNET_VIDEO_CHANNEL_TYPE_ALL,                         // All
    ZZNET_VIDEO_CHANNEL_TYPE_INPUT,                       // Input
    ZZNET_VIDEO_CHANNEL_TYPE_OUTPUT,                      // Output
} ZZNET_VIDEO_CHANNEL_TYPE;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_VIDEOCHANNELSINFO Command Input Parameters
typedef struct tagZZNET_IN_GET_VIDEOCHANNELSINFO
{
    DWORD                               dwSize;
    ZZNET_VIDEO_CHANNEL_TYPE              emType;         // Channel Type to get                     
} ZZNET_IN_GET_VIDEOCHANNELSINFO;

typedef struct tagZZNET_VIDEOCHANNELS_INPUT 
{
    int                     nThermographyCount;         // Number of Thermal Channels
    int                     nThermography[64];          // Thermal Channel Numbers
    int                     nMultiPreviewCount;         // Number of Multi-Preview Channels
    int                     nMultiPreview[4];	        // Multi-Preview Channel Numbers
    int                     nPIPCount;                  // Number of PIP Channels
    int                     nPIP[4];    	            // PIP Channel Numbers
    int                     nCompressPlayCount;         // Number of Secondary Compression Playback Channels
    int                     nCompressPlay[4];	        // Secondary Compression Playback Channel Numbers
	int						nSDCount;					// Number of PTZ/Speed Dome Channels
	int						nSD[64];					// PTZ/Speed Dome Channel Numbers
    char                    reserved[252];
} ZZNET_VIDEOCHANNELS_INPUT;

typedef struct tagZZNET_VIDEOCHANNELS_OUTPUT 
{
    int                     nVGACount;                  // Number of VGA Outputs
    int                     nVGA[128];                  // VGA Outputs
    int                     nTVCount;                   // Number of TV Outputs
    int                     nTV[128];                   // TV Outputs
    char                    reserved[512];
} ZZNET_VIDEOCHANNELS_OUTPUT;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_VIDEOCHANNELSINFO Command Output Parameters
typedef struct tagZZNET_OUT_GET_VIDEOCHANNELSINFO
{
    DWORD                       dwSize;
    ZZNET_VIDEOCHANNELS_INPUT     stInputChannels;        // Input Channel Info, valid when type is NET_VIDEO_CHANNEL_TYPE_ALL/INPUT        
    ZZNET_VIDEOCHANNELS_OUTPUT    stOutputChannels;       // Output Channel Info, valid when type is NET_VIDEO_CHANNEL_TYPE_ALL/OUTPUT
} ZZNET_OUT_GET_VIDEOCHANNELSINFO;


// Thermal Colorization
typedef enum tagZZNET_THERMO_COLORIZATION 
{
    ZZNET_THERMO_COLORIZATION_UNKNOWN,                        // Unknown
    ZZNET_THERMO_COLORIZATION_WHITE_HOT,                      // White Hot
    ZZNET_THERMO_COLORIZATION_BLACK_HOT,                      // Black Hot
    ZZNET_THERMO_COLORIZATION_IRONBOW2,                       // Ironbow 2
    ZZNET_THERMO_COLORIZATION_ICEFIRE,                        // Icefire
	ZZNET_THERMO_COLORIZATION_FUSION,                         // Fusion
	ZZNET_THERMO_COLORIZATION_RAINBOW,                        // Rainbow
	ZZNET_THERMO_COLORIZATION_GLOBOW,                         // Globow
	ZZNET_THERMO_COLORIZATION_IRONBOW1,                       // Ironbow 1
	ZZNET_THERMO_COLORIZATION_SEPIA,                          // Sepia
	ZZNET_THERMO_COLORIZATION_COLOR1,                         // Color 1
	ZZNET_THERMO_COLORIZATION_COLOR2,                         // Color 2
	ZZNET_THERMO_COLORIZATION_RAIN,                           // Rain
	ZZNET_THERMO_COLORIZATION_RED_HOT,                        // Red Hot
	ZZNET_THERMO_COLORIZATION_GREEN_HOT,                      // Green Hot
} ZZNET_THERMO_COLORIZATION;

// Thermal Region of Interest (ROI) Mode
typedef enum tagZZNET_THERMO_ROI 
{
    ZZNET_THERMO_ROI_UNKNOWN,                                 // Unknown
    ZZNET_THERMO_ROI_FULL_SCREEN,                             // Full Screen
    ZZNET_THERMO_ROI_SKY,                                     // Top / Sky
    ZZNET_THERMO_ROI_GROUND,                                  // Middle / Ground
    ZZNET_THERMO_ROI_HORIZONTAL,                              // Bottom / Horizontal
    ZZNET_THERMO_ROI_CENTER_75,                               // Center 75%
    ZZNET_THERMO_ROI_CENTER_50,                               // Center 50%
    ZZNET_THERMO_ROI_CENTER_25,                               // Center 25%
    ZZNET_THERMO_ROI_CUSTOM,                                  // Custom
} ZZNET_THERMO_ROI;

// Thermal Mode
typedef enum tagZZNET_THERMO_MODE 
{
    ZZNET_THERMO_MODE_UNKNOWN,                                // Unknown
    ZZNET_THERMO_MODE_DEFAULT,                                // Default
    ZZNET_THERMO_MODE_INDOOR,                                 // Indoor
    ZZNET_THERMO_MODE_OUTDOOR,                                // Outdoor
} ZZNET_THERMO_MODE;

// Thermal Optimization Region
typedef struct tagZZNET_THERMO_GRAPHY_OPT_REGION 
{
    BOOL                bOptimizedRegion;                   // Whether to enable optimized region
    int                 nOptimizedROIType;                  // Optimized ROI Type, see NET_THERMO_ROI
    int                 nCustomRegion;                      // Custom Region Count
    ZZNET_RECT          stCustomRegions[64];                // Custom Regions, valid only when nOptimizedROIType is ZZNET_THERMO_ROI_CUSTOM
    char                Reserved[256];
} ZZNET_THERMO_GRAPHY_OPTREGION;

// Thermal Info
typedef struct tagZZNET_THERMO_GRAPHY_INFO 
{
    int                         nBrightness;                // Brightness
    int                         nSharpness;                 // Sharpness
    int                         nEZoom;                     // E-Zoom multiplier
    int                         nThermographyGamma;         // Gamma Value
    int                         nColorization;              // Colorization, see NET_THERMO_COLORIZATION
    int                         nSmartOptimizer;            // Optimization Index
    ZZNET_THERMO_GRAPHY_OPTREGION stOptRegion;                // Optimized Region
    int                         nAgc;                       // Automatic Gain Control (AGC)
    int                         nAgcMaxGain;                // Max AGC Gain
    int                         nAgcPlateau;                // Gain Plateau/Equalization
    char                        reserved[244];
} ZZNET_THERMO_GRAPHY_INFO;


// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_DEV_THERMO_GRAPHY_PRESET Command Input Parameters
typedef struct tagZZNET_IN_THERMO_GET_PRESETINFO 
{
    DWORD               dwSize;
    int                 nChannel;                           // Channel Number
    ZZNET_THERMO_MODE     emMode;                             // Mode
} ZZNET_IN_THERMO_GET_PRESETINFO;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_DEV_THERMO_GRAPHY_PRESET Command Output Parameters
typedef struct tagZZNET_OUT_THERMO_GET_PRESETINFO 
{
    DWORD                       dwSize;
    ZZNET_THERMO_GRAPHY_INFO    stInfo;                     // Thermal Info
} ZZNET_OUT_THERMO_GET_PRESETINFO;



// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_DEV_THERMO_GRAPHY_OPTREGION Command Input Parameters
typedef struct tagZZNET_IN_THERMO_GET_OPTREGION
{
    DWORD               dwSize;
    int                 nChannel;                           // Channel Number
} ZZNET_IN_THERMO_GET_OPTREGION;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_DEV_THERMO_GRAPHY_OPTREGION Command Output Parameters
typedef struct tagZZNET_OUT_THERMO_GET_OPTREGION
{
    DWORD                         dwSize;
    ZZNET_THERMO_GRAPHY_OPTREGION stInfo;                     // Optimization Region Info
} ZZNET_OUT_THERMO_GET_OPTREGION;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_DEV_THERMO_GRAPHY_EXTSYSINFO Command Input Parameters
typedef struct tagZZNET_IN_THERMO_GET_EXTSYSINFO
{
    DWORD               dwSize;
    int                 nChannel;                           // Channel Number
} ZZNET_IN_THERMO_GET_EXTSYSINFO;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_LINKCHANNELS Command Input Parameters
typedef struct tagZZNET_IN_GET_LINKCHANNELS
{	
    DWORD               dwSize;
    int                 nChannel;	                        // Channel Number, query if this video channel has linked video channels
} ZZNET_IN_GET_LINKCHANNELS;


// Radiometry Info
typedef struct tagZZNET_RADIOMETRYINFO
{
    int                 nMeterType;                         // Return meter type, see NET_RADIOMETRY_METERTYPE
    int                 nTemperUnit;                        // Temperature Unit (currently configured), see NET_TEMPERATURE_UNIT
    float               fTemperAver;                        // Point temperature or average temperature. Returns this field only for points.
    float               fTemperMax;                         // Max Temperature 
    float               fTemperMin;                         // Min Temperature 
    float               fTemperMid;                         // Median Temperature    
    float               fTemperStd;                         // Standard Deviation
    char                reserved[64];
} ZZNET_RADIOMETRYINFO;

// Condition to get temperature of radiometry item   
typedef struct tagZZNET_RADIOMETRY_CONDITION
{
    int                 nPresetId;                          // Preset ID    
    int                 nRuleId;                            // Rule ID 
    int                 nMeterType;                         // Meter item type, see NET_RADIOMETRY_METERTYPE
    char                szName[64];                         // Name of meter item, selected from radiometry configuration rule names
    int                 nChannel;                           // Channel Number
    char                reserved[256];
} ZZNET_RADIOMETRY_CONDITION;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_DEV_RADIOMETRY_POINT_TEMPER Command Input Parameters
typedef struct tagZZNET_IN_RADIOMETRY_GETPOINTTEMPER
{
    DWORD               dwSize;
    int                 nChannel;                           // Channel Number
    ZZ_POINT            stCoordinate;                       // Coordinate of temperature measurement point, value 0~8192
} ZZNET_IN_RADIOMETRY_GETPOINTTEMPER;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_DEV_RADIOMETRY_POINT_TEMPER Command Output Parameters
typedef struct tagZZNET_OUT_RADIOMETRY_GETPOINTTEMPER
{
    DWORD                 dwSize;
    ZZNET_RADIOMETRYINFO  stPointTempInfo;                    // Get temperature measurement point parameter values
} ZZNET_OUT_RADIOMETRY_GETPOINTTEMPER;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_DEV_RADIOMETRY_TEMPER Command Input Parameters
typedef struct tagZZNET_IN_RADIOMETRY_GETTEMPER
{
    DWORD                         dwSize;
    ZZNET_RADIOMETRY_CONDITION    stCondition;                // Condition to get temperature of radiometry item
} ZZNET_IN_RADIOMETRY_GETTEMPER;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_DEV_RADIOMETRY_TEMPER Command Output Parameters
typedef struct tagZZNET_OUT_RADIOMETRY_GETTEMPER
{
    DWORD                 dwSize;
    ZZNET_RADIOMETRYINFO  stTempInfo;                         // Get radiometry parameter values
} ZZNET_OUT_RADIOMETRY_GETTEMPER;


// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_CAMERA_STATE Command Input Parameters
typedef struct tagZZNET_IN_GET_CAMERA_STATEINFO
{
    DWORD               dwSize;
    BOOL                bGetAllFlag;                                // Whether to query all camera states, if this member is TRUE, nChannels member does not need to be set
    int                 nValidNum;                                  // Valid count for nChannels member, effective when bGetAllFlag is FALSE
    int                 nChannels[ZZ_MAX_CAMERA_CHANNEL_NUM];       // Fill in channel numbers to query sequentially, effective when bGetAllFlag is FALSE
} ZZNET_IN_GET_CAMERA_STATEINFO;

typedef enum tagEM_ZZ_CAMERA_STATE_TYPE
{
    EM_ZZ_CAMERA_STATE_TYPE_UNKNOWN,       // Unknown
    EM_ZZ_CAMERA_STATE_TYPE_CONNECTING,    // Connecting
    EM_ZZ_CAMERA_STATE_TYPE_CONNECTED,     // Connected
    EM_ZZ_CAMERA_STATE_TYPE_UNCONNECT,     // Disconnected
    EM_ZZ_CAMERA_STATE_TYPE_EMPTY,         // Channel not configured, no info
    EM_ZZ_CAMERA_STATE_TYPE_DISABLE,       // Channel configured but disabled
}EM_ZZ_CAMERA_STATE_TYPE;

typedef struct tagZZNET_CAMERA_STATE_INFO
{
    int                     nChannel;           // Camera Channel Number, -1 indicates invalid channel number
    EM_ZZ_CAMERA_STATE_TYPE emConnectionState;  // Connection State
    char                    szReserved[1024];   // Reserved bytes
}ZZNET_CAMERA_STATE_INFO;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_CAMERA_STATE Command Output Parameters
typedef struct tagZZNET_OUT_GET_CAMERA_STATEINFO 
{
    DWORD                       dwSize;
    int                         nValidNum;              // Valid count of queried camera channel states, returned by sdk
    int                         nMaxNum;                // Max count of pCameraStateInfo array, filled by user
    ZZNET_CAMERA_STATE_INFO*      pCameraStateInfo;       // Camera channel state info array, allocated by user, size is sizeof(NET_CAMERA_STATE_INFO)*nMaxNum
} ZZNET_OUT_GET_CAMERA_STATEINFO;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_REMOTE_CHANNEL_AUDIO_ENCODE Command Input Parameters
typedef struct tagZZNET_IN_GET_REMOTE_CHANNEL_AUDIO_ENCODEINFO
{
    DWORD               dwSize;
    int                 nChannel;                                   // Channel Number
    int                 nStreamType;                                // Stream Type, 0: Main Stream; 1: Extra Stream 1; 2: Extra Stream 2; 3: Extra Stream 3; 4: Talk Stream
} ZZNET_IN_GET_REMOTE_CHANNEL_AUDIO_ENCODEINFO;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_REMOTE_CHANNEL_AUDIO_ENCODE Command Output Parameters
typedef struct tagZZNET_OUT_GET_REMOTE_CHANNEL_AUDIO_ENCODEINFO
{
    DWORD                       dwSize;
    int                         nValidNum;                                  // Valid audio encode count
    ZZDEV_TALKDECODE_INFO       stuListAudioEncode[ZZ_MAX_AUDIO_ENCODE_NUM];   // Audio encode list
} ZZNET_OUT_GET_REMOTE_CHANNEL_AUDIO_ENCODEINFO;


// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_COMM_PORT_INFO Command Input Parameters
typedef struct tagZZNET_IN_GET_COMM_PORT_INFO
{
    DWORD               dwSize;
} ZZNET_IN_GET_COMM_PORT_INFO;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_COMM_PORT_INFO Command Output Parameters
// Serial Port Type
typedef enum tagEM_ZZ_COMM_PORT_TYPE_INFO
{
    EM_ZZ_COMM_PORT_TYPE_UNKNOW = 0    ,
    EM_ZZ_COMM_PORT_TYPE_RS232         ,
    EM_ZZ_COMM_PORT_TYPE_RS485         ,
    EM_ZZ_COMM_PORT_TYPE_RS422         ,
    EM_ZZ_COMM_PORT_TYPE_RS485_422     ,
}EM_ZZ_COMM_PORT_TYPE_INFO;

// Serial Port Info
typedef struct  tagZZNET_COMM_PORT_INFO
{
    EM_ZZ_COMM_PORT_TYPE_INFO  emCommPortType;     // Serial Port Type
    int                     nCommPortNum;       // Serial Port Number
    BYTE                    bReserved[1024];    // Reserved bytes
}ZZNET_COMM_PORT_INFO;

#define ZZ_MAX_COMM_PORT_NUM       8
typedef struct tagZZNET_OUT_GET_COMM_PORT_INFO
{
    DWORD                       dwSize;
    int                         nPortInfosNum;                          // Number of serial port infos
    ZZNET_COMM_PORT_INFO          stCommPortInfos[ZZ_MAX_COMM_PORT_NUM];     // Serial port infos
} ZZNET_OUT_GET_COMM_PORT_INFO;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_VIDEOOUTPUTCHANNELS Command Input Parameters
typedef struct tagZZNET_IN_GET_VIDEOOUTPUTCHANNELS
{
    DWORD               dwSize;             // User must set dwSize to sizeof(ZZNET_IN_GET_VIDEOOUTPUTCHANNELS) when using this struct
} ZZNET_IN_GET_VIDEOOUTPUTCHANNELS;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_VIDEOOUTPUTCHANNELS Command Output Parameters
typedef struct tagZZNET_OUT_GET_VIDEOOUTPUTCHANNELS
{
    DWORD               dwSize;             // User must set dwSize to sizeof(ZZNET_OUT_GET_VIDEOOUTPUTCHANNELS) when using this struct
    int                 nMaxLocal;          // Total max local output channels, including mainboard and pluggable sub-card channels
} ZZNET_OUT_GET_VIDEOOUTPUTCHANNELS;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_VIDEOINFO Command Input Parameters
typedef struct tagZZNET_IN_GET_VIDEOINFO
{
    DWORD               dwSize;             // User must set dwSize to sizeof(ZZNET_IN_GET_VIDEOINFO) when using this struct
} ZZNET_IN_GET_VIDEOINFO;

// Decoding Channel State
typedef enum  tagZZNET_VIDEOCHANNEL_STATE
{
    ZZNET_VIDEOCHANNEL_STATE_UNKNOWN,        // Unknown Status
    ZZNET_VIDEOCHANNEL_STATE_IDLE,           // Idle
    ZZNET_VIDEOCHANNEL_STATE_PLAY,           // Playing
    ZZNET_VIDEOCHANNEL_STATE_MONITOR,        // Monitoring
    ZZNET_VIDEOCHANNEL_STATE_TOUR,           // Touring
} ZZNET_VIDEOCHANNEL_STATE;

// Decoding Channel Info
typedef struct tagZZNET_VIDEOCHANNELINFO
{
    BOOL                         bEnable;                // Channel Enable Status, when true, GB28181 protocol will report this channel to server
    ZZNET_VIDEOCHANNEL_STATE       emVideoChannelState;    // Decoding Channel State
    int                          nNetflow;               // Network Flow (Unit: kbps)
    int                          nBitrate;               // Bitrate (Unit: kbps)
    int                          nFrame;                 // Frame Rate
    ZZ_CAPTURE_SIZE                 emResolution;           // Resolution
    BYTE                         byReserved[512];        // Reserved bytes 
} ZZNET_VIDEOCHANNELINFO;


// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_VIDEOINFO Command Output Parameters
typedef struct tagZZNET_OUT_GET_VIDEOINFO
{
    DWORD                    dwSize;                // User must set dwSize to sizeof(ZZNET_OUT_GET_VIDEOINFO) when using this struct
    int                      nVideoInfoNum;         // Number of decoding channel infos required by user, starts from 0, specified by user
    ZZNET_VIDEOCHANNELINFO*  pNetVideoChannelInfo;  // Decoding channel info list, space allocated by user, count matches nVideoInfoNum, allocated memory size is sizeof(ZZNET_VIDEOCHANNELINFO)*nVideoInfoNum
    int                      nRetVideoInfoNum;      // Actual returned decoding channel info count, returned by SDK
} ZZNET_OUT_GET_VIDEOINFO;

// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_ALLLINKCHANNELS Command Input Parameters
typedef struct tagZZNET_IN_GET_ALLLINKCHANNELS
{	
    DWORD               dwSize;
} ZZNET_IN_GET_ALLLINKCHANNELS;


#define ZZNET_LINKCHANNEL_MAX     512                         // Max linked video channels
#define ZZNET_LINKGROUP_MAX       64                          // Max linked video channel groups
// ZZNETSDK_QueryDevInfo Interface ZZNET_QUERY_GET_ALLLINKCHANNELS Command Output Parameters
typedef struct tagZZNET_OUT_GET_ALLLINKCHANNELS
{	
    DWORD               dwSize;
    int                 nGroupCnt;                                              // Number of linked video channel groups
    int                 nLinkedCnt[ZZNET_LINKGROUP_MAX];                          // Number of linked video channels in each group
    int                 nLinked[ZZNET_LINKGROUP_MAX][ZZNET_LINKCHANNEL_MAX];	    // Linked video channel numbers, including the requesting channel number
                                                                                // First dimension is channel group, second dimension is channel number
                                                                                // e.g., nLinked[1][2] represents the third linked channel of the second channel group
} ZZNET_OUT_GET_ALLLINKCHANNELS;


// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_TRAFFICRADAR_VERSION Command Input Parameters
typedef struct tagZZNET_IN_TRAFFICRADAR_VERSION
{
    DWORD                   dwSize;
    int                     nChannel;                   // Serial Port Number
} ZZNET_IN_TRAFFICRADAR_VERSION;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_TRAFFICRADAR_VERSION Command Output Parameters
typedef struct tagZZNET_OUT_TRAFFICRADAR_VERSION
{
    DWORD                   dwSize;
    char                    szVersion[ZZ_MAX_VERSION_LEN];  // Version Number
} ZZNET_OUT_TRAFFICRADAR_VERSION;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_WORKGROUP_NAMES Command Input Parameters
typedef struct tagZZNET_IN_WORKGROUP_NAMES
{
    DWORD                       dwSize;
} ZZNET_IN_WORKGROUP_NAMES;

// Max Work Group Name Length
#define ZZ_WORKGROUP_NAME_LEN      32

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_WORKGROUP_NAMES Command Output Parameters
typedef struct tagZZNET_OUT_WORKGROUP_NAMES
{
    DWORD                       dwSize;
    int                         nCount;                         // Number of Work Groups
    char                        szName[64][ZZ_WORKGROUP_NAME_LEN]; // Name of each Work Group
} ZZNET_OUT_WORKGROUP_NAMES;


// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_WORKGROUP_INFO Command Input Parameters
typedef struct tagZZNET_IN_WORKGROUP_INFO
{
    DWORD                       dwSize;
    char                        szName[ZZ_WORKGROUP_NAME_LEN];     // Work Group to get info for                    
} ZZNET_IN_WORKGROUP_INFO;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_WORKGROUP_INFO Command Output Parameters
typedef struct tagZZNET_OUT_WORKGROUP_INFO
{
    DWORD                       dwSize;
    int                         nState;                         // Status: 0 Meaningless, 1 Normal, 2 Damaged, 3 Error
    int                         nTotalSpace;                    // Total Space Unit: MB -1 means failed to get
    int                         nFreeSpace;                     // Free Space Unit: MB -1 means failed to get
} ZZNET_OUT_WORKGROUP_INFO;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_WLAN_ACCESSPOINT Command Input Parameters
typedef struct tagZZNET_IN_WLAN_ACCESSPOINT
{
    DWORD                       dwSize;
    char                        szSSID[ZZ_MAX_SSID_LEN];        // SSID to get info for, searches all networks if empty                    
} ZZNET_IN_WLAN_ACCESSPOINT;

typedef struct tagZZNET_WLAN_ACCESSPOINT_INFO
{
    char                        szSSID[ZZ_MAX_SSID_LEN];        // SSID
    int                         nStrength;                      // Signal Strength Range 0-100
    int                         nAuthMode;                     // Auth Mode 0:OPEN; 1:SHARED; 2:WPA; 3:WPA-PSK; 4:WPA2; 5:WPA2-PSK;
                                                                // 6:WPA-NONE(used in adhoc network mode),
                                                                // 7-11 are mixed modes, can connect with any of them
                                                                // 7:WPA-PSK | WPA2-PSK; 8:WPA | WPA2; 9:WPA | WPA-PSK;
                                                                // 10:WPA2 | WPA2-PSK; 11:WPA | WPA-PSK |WPA2 |WPA2-PSK //12: UnKnown
    int                         nEncrAlgr;                     // Encryption Algorithm 0:off; 2:WEP64bit; 3:WEP128bit; 4:WEP; 5:TKIP; 6:AES(CCMP)
                                                                // 7: TKIP+AES(Mixed mode) 8: UnKnown
    char                        reserved[1016];
} ZZNET_WLAN_ACCESSPOINT_INFO;

// ZZNETSDK_QueryDevInfo, ZZNET_QUERY_WLAN_ACCESSPOINT Command Output Parameters
typedef struct tagZZNET_OUT_WLAN_ACCESSPOINT
{
    DWORD                       dwSize;
    int                         nCount;                         // Number of WLAN Access Points
    ZZNET_WLAN_ACCESSPOINT_INFO   stuInfo[64];                    // Access Point Info                       
} ZZNET_OUT_WLAN_ACCESSPOINT;


// GPS Info Query Conditions
typedef struct tagZZNET_IN_DEV_GPS_INFO
{
	DWORD                    dwSize;                         // Structure Size
    int                      nChannel;                       // Device Channel Number
} ZZNET_IN_DEV_GPS_INFO;

// GPS Work Status
typedef enum tagZZNET_GPS_WORK_STATUS
{
	EM_ZZ_WORK_STATE_UNKNOWN = 0,			// Unknown Work Status
	EM_ZZ_NO_POSITIONING,					// Not Positioning
	EM_ZZ_NO_DIFFERENTIAL_POSITIONING,		// Non-differential Positioning
	EM_ZZ_DIFFERENTIAL_POSITIONING,		// Differential Positioning
	EM_ZZ_INVALID_PPS,						// Invalid PPS
	EM_ZZ_EVALUATING,						// Evaluating
}ZZNET_GPS_WORK_STATUS;


// GPS Info Query Result
typedef struct tagZZNET_OUT_DEV_GPS_INFO
{
	DWORD                   dwSize;                          // Structure Size
    ZZNET_TIME				stuLocalTime;                    // Current Time 
	double                  dbLongitude;                     // Longitude (Unit: millionths of a degree, range 0-360 degrees)
    double                  dbLatitude;                      // Latitude (Unit: millionths of a degree, range 0-180 degrees)
	double                  dbAltitude;                      // Altitude (Unit: meters)
	double                  dbSpeed;                         // Speed (Unit: km/H)
	double                  dbBearing;                       // Bearing (Unit: degrees)
	ZZNET_THREE_STATUS_BOOL   emAntennasStatus;				 // Antenna Status (0: Bad 1: Good)
	ZZNET_THREE_STATUS_BOOL   emPositioningResult;             // Positioning Status (0: Not Positioning 1: Positioning)
	DWORD					dwSatelliteCount;				 // Satellite Count
	ZZNET_GPS_WORK_STATUS     emworkStatus;                    // Work Status
	int                     nAlarmCount;					 // Alarm Count
	int                     nAlarmState[128];                // Locations of alarms occurred, value can be multiple
	float					fHDOP;							 // Horizontal Dilution of Precision
} ZZNET_OUT_DEV_GPS_INFO;

// Query IVS Frontend Device Input Parameters
typedef struct tagZZNET_IN_IVS_REMOTE_DEV_INFO
{
    DWORD                   dwSize;                         // Structure Size   
    int                     nChannel;                       // Channel Number
}ZZNET_IN_IVS_REMOTE_DEV_INFO;

// Query IVS Frontend Device Output Parameters
typedef struct tagZZNET_OUT_IVS_REMOTE_DEV_INFO
{
    DWORD                   dwSize;                         // Structure Size 
    int                     nPort;                          // Port
    char                    szIP[64];                       // Device IP
    char                    szUser[64];                     // Username
    char                    szPassword[64];                 // Password    
    char                    szAddress[128];	                // Machine Deployment Address
}ZZNET_OUT_IVS_REMOTE_DEV_INFO;

#define ZZ_WIRELESS_DEVICE_SERIAL_NUMBER_MAX_LEN 32    // Max length of wireless device serial number

// Query Smart Switch Info Input Parameters
typedef struct tagZZNET_IN_SMART_SWITCH_INFO
{
    DWORD                   dwSize;                         // Structure Size 
    char                    szSerialNumber[ZZ_WIRELESS_DEVICE_SERIAL_NUMBER_MAX_LEN]; // Device Serial Number 
}ZZNET_IN_SMART_SWITCH_INFO;

// Query Smart Switch Info Output Parameters
typedef struct tagZZNET_OUT_SMART_SWITCH_INFO
{
    DWORD                   dwSize;                         // Structure Size 
    BOOL                    bSwitchEable;                   // Switch State, TRUE On, FALSE Off
    double                  dbCurrentPower;                 // Instant Power, unit: W 
    double                  dbHistoryPowerUsed;             // History Power Used, unit: kw/h
    double                  dbTodayPowerUsed;               // Today Power Used, unit: kw/h
    double                  dbMonthPowerUsed[ZZNET_MAX_MONTH_NUM]; // Monthly Power Used, unit: kw/h
}ZZNET_OUT_SMART_SWITCH_INFO; 

// Query Upgrade State Input Parameters
typedef struct tagZZNET_IN_UPGRADE_STATE
{
    DWORD                   dwSize;                         // Structure Size 
}ZZNET_IN_UPGRADE_STATE;

// Upgrade Package and Upgrade State
typedef enum tagEM_ZZ_UPGRADE_STATE
{
    EM_ZZ_UPGRADE_STATE_UNKNOWN,                               // Unknown State
    EM_ZZ_UPGRADE_STATE_NONE,                                  // No update detected
    EM_ZZ_UPGRADE_STATE_INVALID,                               // Upgrade package invalid
    EM_ZZ_UPGRADE_STATE_NOT_ENOUGH_MEMORY,                     // Not enough memory
    EM_ZZ_UPGRADE_STATE_DOWNLOADING,                           // Downloading data
    EM_ZZ_UPGRADE_STATE_DOWNLOAD_FAILED,                       // Download failed
    EM_ZZ_UPGRADE_STATE_DOWNLOAD_SUCCESSED,                    // Download succeeded
    EM_ZZ_UPGRADE_STATE_PREPARING,                             // Preparing to upgrade
    EM_ZZ_UPGRADE_STATE_UPGRADING,                             // Upgrading
    EM_ZZ_UPGRADE_STATE_UPGRADE_FAILED,                        // Upgrade failed
    EM_ZZ_UPGRADE_STATE_UPGRADE_SUCCESSED,                     // Upgrade succeeded
    EM_ZZ_UPGRADE_STATE_UPGRADE_CANCELLED,                     // Upgrade cancelled 
    EM_ZZ_UPGRADE_STATE_FILE_UNMATCH,                          // Upgrade package mismatch
}EM_ZZ_UPGRADE_STATE;

// Upgrade Package Type
typedef enum tagEM_ZZ_UPGRADE_PACKAGE_TYPE
{
    EM_ZZ_UPGRADE_PACKAGE_TYPE_UNKNOWN,                       // Unknown Type
    EM_ZZ_UPGRADE_PACKAGE_TYPE_REGULAR,                       // Regular Upgrade
    EM_ZZ_UPGRADE_PACKAGE_TYPE_EMERGENCY,                     // Forced Upgrade
}EM_ZZ_UPGRADE_PACKAGE_TYPE;

// Query Upgrade State Output Parameters
typedef struct tagZZNET_OUT_UPGRADE_STATE
{
    DWORD                   dwSize;                         // Structure Size
    char                    szOldVersion[ZZ_COMMON_STRING_64]; // Old Version Number
    char                    szNewVersion[ZZ_COMMON_STRING_64];  // New Version Number
    EM_ZZ_UPGRADE_STATE        emState;                        // Upgrade Package and Upgrade State
    EM_ZZ_UPGRADE_PACKAGE_TYPE emType;                         // Upgrade Package Type
    int                     nProgress;                      // Upgrade Progress, 0 ~ 100
}ZZNET_OUT_UPGRADE_STATE;


// Stream Type
enum ZZ_CFG_EM_STREAM_TYPES
{
	ZZ_CFG_EM_STREAMTYPE_ERR,                  // Other
	ZZ_CFG_EM_STREAMTYPE_MAIN,					// "Main"-Main Stream
	ZZ_CFG_EM_STREAMTYPE_EXTRA_1,				// "Extra1"-Extra Stream 1
	ZZ_CFG_EM_STREAMTYPE_EXTRA_2,				// "Extra2"-Extra Stream 2
	ZZ_CFG_EM_STREAMTYPE_EXTRA_3,				// "Extra3"-Extra Stream 3
	ZZ_CFG_EM_STREAMTYPE_SNAPSHOT,				// "Snapshot"-Snapshot Stream
	ZZ_CFG_EM_STREAMTYPE_TALKBACK,				// "Talkback"-Talkback Stream
};

// Get Video Encode Capability Set Input Parameters
typedef struct tagZZNET_IN_VIDEO_ENCODE_CAPS
{
	DWORD					dwSize;                         // Structure Size
	int						nChannel;						// Channel Number
	int						nGroup;							// Group Number
	ZZ_CFG_EM_STREAM_TYPES	stStreamType;					// Stream Type
}ZZNET_IN_VIDEO_ENCODE_CAPS;


///@brief Privacy Masking Version
typedef enum tagEM_ZZ_PRIVACY_MASKING_VERSION
{
	EM_ZZ_PRIVACY_MASKING_UNKNOWN,                        /// Unknown Type
	EM_ZZ_PRIVACY_MASKING_V1,                             /// V1: Version 1 privacy masking algorithm (original privacy masking algorithm, uses config)
	EM_ZZ_PRIVACY_MASKING_V2,                             /// V2: Version 2 privacy masking algorithm (based on field of view angle, uses interface)
	EM_ZZ_PRIVACY_MASKING_V3,                             /// V3: Unified version for PTZ and IPC protocols
}EM_ZZ_PRIVACY_MASKING_VERSION;

///@brief Mask Block Shape
typedef enum tagEM_ZZ_PRIVACY_MASKING_TYPE
{
	EM_ZZ_MASKING_TYPE_UNKNOWN,							/// Unknown Type
	EM_ZZ_MASKING_TYPE_RECT,								/// Rectangle
	EM_ZZ_MASKING_TYPE_POLYGON,                            /// Polygon
}EM_ZZ_PRIVACY_MASKING_TYPE;


///@brief Capability Set for Solid Color Privacy Masking Blocks
typedef struct tagZZNET_COLOR_MASKING_CAPS
{
	BOOL						bSupport;					/// Whether solid color privacy masking block is supported
	UINT						nMaxNum;					/// Maximum number of solid blocks supported by the system
	int							nSupportTypeNum;			/// Number of supported block shapes
	EM_ZZ_PRIVACY_MASKING_TYPE	emSupportType[8];			/// Supported block shapes
	UINT						nMaxPolygonPoints;			/// Maximum vertices for polygon masking blocks supported by the system (Valid when SupportType supports "Polygon")
	BOOL						bSetColorSupport;			/// Whether block color setting is supported
	BOOL						bSetColorIndependent;		/// Whether block colors are mutually independent
	BYTE						byReserved[128];			/// Reserved bytes
}ZZNET_COLOR_MASKING_CAPS;

///@brief Capability Set for Mosaic Privacy Masking Blocks
typedef struct tagZZNET_MOSAIC_MASKING_CAPS
{
	BOOL						bSupport;					/// Whether mosaic privacy masking block is supported
	UINT						nMaxNum;					/// Maximum number of mosaic blocks supported by the system
	int							nSupportTypeNum;			/// Number of supported block shapes
	EM_ZZ_PRIVACY_MASKING_TYPE	emSupportType[8];			/// Supported block shapes
	UINT						nMaxPolygonPoints;			/// Maximum vertices for polygon masking blocks supported by the system (Valid when SupportType supports "Polygon")
	int							nSupportMosaicTypeNum;		/// Number of supported mosaic types
	int							nSupportMosaicType[8];		/// Supported mosaic types (Valid when SetMosaicSupport is true, defaults to 24x24 mosaic if this config is missing)
	BYTE						byReserved[128];			/// Reserved bytes
}ZZNET_MOSAIC_MASKING_CAPS;

///@brief Shield Zoom Capability Set
typedef struct tagZZNET_SHIELD_ZOOM_CAPS
{
	BOOL						bSupport;					/// Whether setting shield zoom is supported, true-Supported, false-Not Supported
	int							nShieldZoomMin;				/// Minimum shield zoom, if field missing min is 0. Actual zoom multiplied by 10
	int							nShieldZoomMax;				/// Maximum shield zoom, if field missing max is not limited. Actual zoom multiplied by 10
	BYTE						byReserved[128];			/// Reserved bytes
}ZZNET_SHIELD_ZOOM_CAPS;

///@brief General Privacy Masking Capability Set
typedef struct tagZZNET_PRIVACY_MASKING_CAPS
{
	BOOL						bSupport;					/// Whether PrivacyMasking setting is supported
	EM_ZZ_PRIVACY_MASKING_VERSION	emVersion;					/// Privacy masking version number
	int							nSupportMaskingNum;			/// Max supported privacy masking blocks
	UINT						nMaxChipMaskingNum;			/// Max supported privacy masking blocks (including solid and mosaic) by the system, represents the maximum capacity of the chip platform.
	ZZNET_COLOR_MASKING_CAPS	stuColorMaskingCaps;		/// Capability Set for Solid Color Privacy Masking Blocks
	ZZNET_MOSAIC_MASKING_CAPS	stuMosaicMaskingCaps;		/// Capability Set for Mosaic Privacy Masking Blocks
	ZZNET_SHIELD_ZOOM_CAPS      stuShieldZoom;				/// Shield Zoom Capability Set
	BYTE						byReserved[1024];			/// Reserved bytes
}ZZNET_PRIVACY_MASKING_CAPS;

// Get Video Encode Capability Set Output Parameters
typedef struct tagZZNET_OUT_VIDEO_ENCODE_CAPS
{
	DWORD					dwSize;																// Structure Size
	int						nSvcEncodeTypesNum;													// Number of video formats supporting SVC encoding
	char					szSvcEncodeTypes[ZZ_COMMON_STRING_32][ZZ_COMMON_STRING_32];			// Video formats supporting SVC encoding
	int						nGOPCustomEncodesNum;												// Number of streams supporting custom I-frame interval
	char					szGOPCustomEncodes[ZZ_COMMON_STRING_32][ZZ_COMMON_STRING_32];		// Streams supporting custom I-frame interval
	int						nMaxSVCTLevel;														// Maximum SVC-T support levels
    ZZNET_PRIVACY_MASKING_CAPS  stuPrivacyMaskingCaps;											// General Privacy Masking Capability Set
}ZZNET_OUT_VIDEO_ENCODE_CAPS;



// Get Audio Encode Capability Set Input Parameters
typedef struct tagZZNET_IN_AUDIO_ENCODE_CAPS
{
	DWORD					dwSize;                         // Structure Size
	int						nChannel;						// Channel Number
	ZZ_CFG_EM_STREAM_TYPES		stStreamType;				// Stream Type
}ZZNET_IN_AUDIO_ENCODE_CAPS;

// Get Audio Encode Capability Set Output Parameters
typedef struct tagZZNET_OUT_AUDIO_ENCODE_CAPS
{
	DWORD					dwSize;														// Structure Size
	BOOL					bSupportSourceSelect;										// Whether multi-audio input is supported
	int						nSourceTypeNum;												// Number of audio source types
	char					szSourceType[ZZ_COMMON_STRING_32][ZZ_COMMON_STRING_32];		// List of audio source types
}ZZNET_OUT_AUDIO_ENCODE_CAPS;


// Get Audio Input Channel Capability Set Input Parameters
typedef struct tagZZNET_IN_AUDIO_IN_CAPS
{
	DWORD					dwSize;                         // Structure Size
	int						nChannel;						// Channel Number
}ZZNET_IN_AUDIO_IN_CAPS;

// Get Audio Input Channel Capability Set Output Parameters
typedef struct tagZZNET_IN_AUDIO_OUT_CAPS
{
	DWORD					dwSize;                         // Structure Size
	int						nMicNum;						// Mic Input Count, >0 means supports talk input
	int						nLineInNum;						// Line-In Input Count, >0 means supports audio input
}ZZNET_OUT_AUDIO_IN_CAPS;

// Smart Encode Info
typedef struct tagZZSMART_ENCODE_INFO
{
	DWORD					dwSize;							   // Structure Size
	char					szCompression[ZZ_MAX_COMMON_STRING_8]; // Video encode compression format, e.g., "H.264", "H.265"
	int						nPolicy;						   // Smart Encode Policy
	bool					bEnable;						   // Stream Enable
	int						nWidth;							   // Video Width, Optional
	int						nHeight;						   // Video Height, Optional
	float					fFPS;							   // Video FPS, Optional
}ZZSMART_ENCODE_INFO;

// Query Smart Encode Capability Set Input Parameters
typedef struct tagZZNET_IN_SMART_ENCODE_CAPS
{
	DWORD					dwSize;								// Structure Size
	int						nChannel;							// Channel Number
	int						nStreamNum;							// Actual stream count
	ZZSMART_ENCODE_INFO		stSmartEncodeInfo[ZZ_MAX_STREAM_NUM];  // Smart Encode Info for each stream, if actual stream count is 3, indices 0, 1, 2 represent main stream, extra stream 1, extra stream 2 encode info respectively	
}ZZNET_IN_SMART_ENCODE_CAPS;

// Smart Encode Enable
typedef struct tagZZSMART_ENCODE_CAPS_INFO
{
	DWORD					dwSize;																// Structure Size
	int						nSmartEncodeCap;													// 1: Supports enabling encoded P-frame relocation; 0: Does not support Smart Encode (but can output normal stream); -1: Does not support encoding (e.g., main stream resolution too large, insufficient resources, extra stream 2 cannot encode, but if main stream resolution is lowered, extra 2 can encode normally)
}ZZSMART_ENCODE_CAPS_INFO;

// Query Smart Encode Capability Set Output Parameters
typedef struct tagZZNET_OUT_SMART_ENCODE_CAPS
{
	DWORD						dwSize;																// Structure Size
	int							nSmartEncodeCapsNum;												// Smart Encode Enable Group Count
	ZZSMART_ENCODE_CAPS_INFO		stSmartEncodeCaps[ZZ_MAX_STREAM_NUM];									// Corresponding encode enable for each stream Smart Encode Info.
}ZZNET_OUT_SMART_ENCODE_CAPS;


// Query HDD Temperature Input Parameters
typedef struct tagZZNET_IN_HDD_TEMPERATURE
{
	DWORD					dwSize;
	char					szHardDiskName[ZZ_COMMON_STRING_16];		// Storage Device Name
	
}ZZNET_IN_HDD_TEMPERATURE;

// Query HDD Temperature Output Parameters
typedef struct tagZZNET_OUT_HDD_TEMPERATURE
{
	DWORD					dwSize;
	int						nID;										// Attribute ID
	char					szName[ZZ_COMMON_STRING_64];				// Attribute Name
	int						nCurrent;									// Attribute Value
	int						nWorst;										// Max Error Value
	int						nThreshold;									// Threshold
	char					szRaw[ZZ_COMMON_STRING_32];					// Actual Value
	int						nPredict;									// Status
	int						nSync;										// Raid Sync Status, 0 Adaptive; 1 Sync Priority, I/O prioritizes Raid Sync; 2 Business Priority, I/O prioritizes HDD write data; 3 Balanced																		
}ZZNET_OUT_HDD_TEMPERATURE; 

// Get YUV Data of Specified Format Input Parameters
typedef struct tagZZNET_IN_RAWFRAMEDATA
{
	DWORD					dwSize;										
	int						nChannel;									// Video Input Channel Number
	int						nSensorID;									// Sensor ID
	char					szRawFrameType[ZZ_COMMON_STRING_32];		// YUV Data Format, supported range obtained via ZZNETSDK_GetDevCaps method, command: NET_VIDEOIN_RAWFRAME_CAPS
}ZZNET_IN_RAWFRAMEDATA;

// Get YUV Data of Specified Format Output Parameters
typedef struct tagZZNET_OUT_RAWFRAMEDATA
{
	DWORD					dwSize;
	UINT					nHeight;									// Returned Image Height
	UINT					nWidth;										// Returned Image Width
	UINT					nDataLen;									// YUV binary data size, unit bytes
	char*					pszBuffer;									// YUV Data, allocated by user, size is nBufferLen
	int						nBufferLen;									// User allocated YUV data memory size
}ZZNET_OUT_RAWFRAMEDARA;


///@brief ZZNETSDK_QueryDevInfo ZZNET_QUERY_HTTP_PROXY_PORT Type Interface Input Parameters
typedef struct tagZZNET_IN_HTTP_PROXY_PORT
{
	DWORD                   dwSize;                 /// Structure Size
	int                     nChannel;               /// Video Channel Number
	char                    szIp[48];               /// Device IP, used in dual NIC scenarios
}ZZNET_IN_HTTP_PROXY_PORT;

///@brief ZZNETSDK_QueryDevInfo ZZNET_QUERY_HTTP_PROXY_PORT Type Interface Output Parameters
typedef struct tagZZNET_OUT_HTTP_PROXY_PORT
{
	DWORD                   dwSize;                 /// Structure Size
	int                     nProxyPort;             /// Web Proxy Port, 0-No need for web proxy redirection
	BOOL                    bProxyHttps;            /// Whether to enable https secure connection
}ZZNET_OUT_HTTP_PROXY_PORT;










// Device Information Types, corresponding to ZZNETSDK_QueryDevInfo interface
#define ZZNET_QUERY_DEV_STORAGE_NAMES                 0x01                // Query Device Storage Module Name List , pInBuf=ZZNET_IN_STORAGE_DEV_NAMES *, pOutBuf=ZZNET_OUT_STORAGE_DEV_NAMES *
#define ZZNET_QUERY_DEV_STORAGE_INFOS                 0x02                // Query Device Storage Module Info List, pInBuf=ZZNET_IN_STORAGE_DEV_INFOS*, pOutBuf= ZZNET_OUT_STORAGE_DEV_INFOS *
#define ZZNET_QUERY_RECENCY_JNNCTION_CAR_INFO         0x03                // Query Recent Checkpoint Vehicle Info Interface, pInBuf=ZZNET_IN_GET_RECENCY_JUNCTION_CAR_INFO*, pOutBuf=ZZNET_OUT_GET_RECENCY_JUNCTION_CAR_INFO*
#define ZZNET_QUERY_LANES_STATE                       0x04                // Query Lane Info, pInBuf = ZZNET_IN_GET_LANES_STATE , pOutBuf = ZZNET_OUT_GET_LANES_STATE
#define ZZNET_QUERY_DEV_FISHEYE_WININFO               0x05                // Query Fisheye Window Info , pInBuf= ZZNET_IN_FISHEYE_WININFO*, pOutBuf=ZZNET_OUT_FISHEYE_WININFO *
#define ZZNET_QUERY_DEV_REMOTE_DEVICE_INFO            0x06                // Query Remote Device Info , pInBuf= ZZNET_IN_GET_DEVICE_INFO*, pOutBuf= ZZNET_OUT_GET_DEVICE_INFO *
#define ZZNET_QUERY_SYSTEM_INFO                       0x07                // Query Device System Info , pInBuf= ZZNET_IN_SYSTEM_INFO*, pOutBuf= ZZNET_OUT_SYSTEM_INFO*
#define ZZNET_QUERY_REG_DEVICE_NET_INFO               0x08                // Query Active Registration Device Network Connection , pInBuf=ZZNET_IN_REGDEV_NET_INFO * , pOutBuf=ZZNET_OUT_REGDEV_NET_INFO *
#define ZZNET_QUERY_DEV_THERMO_GRAPHY_PRESET          0x09                // Query Thermal Preset Info , pInBuf= ZZNET_IN_THERMO_GET_PRESETINFO*, pOutBuf= ZZNET_OUT_THERMO_GET_PRESETINFO *
#define ZZNET_QUERY_DEV_THERMO_GRAPHY_OPTREGION       0x0a                // Query Thermal ROI Info, pInBuf= ZZNET_IN_THERMO_GET_OPTREGION*, pOutBuf= ZZNET_OUT_THERMO_GET_OPTREGION *
#define ZZNET_QUERY_DEV_THERMO_GRAPHY_EXTSYSINFO      0x0b                // Query Thermal External System Info, pInBuf= ZZNET_IN_THERMO_GET_EXTSYSINFO*, pOutBuf= ZZNET_OUT_THERMO_GET_EXTSYSINFO *
#define ZZNET_QUERY_DEV_RADIOMETRY_POINT_TEMPER       0x0c                // Query Temperature Measurement Point Parameter Values, pInBuf= ZZNET_IN_RADIOMETRY_GETPOINTTEMPER*, pOutBuf= ZZNET_OUT_RADIOMETRY_GETPOINTTEMPER *
#define ZZNET_QUERY_DEV_RADIOMETRY_TEMPER             0x0d                // Query Temperature Measurement Item Parameter Values, pInBuf= ZZNET_IN_RADIOMETRY_GETTEMPER*, pOutBuf= ZZNET_OUT_RADIOMETRY_GETTEMPER *
#define ZZNET_QUERY_GET_CAMERA_STATE                  0x0e                // Get Camera State, pInBuf= ZZNET_IN_GET_CAMERA_STATEINFO*, pOutBuf= ZZNET_OUT_GET_CAMERA_STATEINFO *
#define ZZNET_QUERY_GET_REMOTE_CHANNEL_AUDIO_ENCODE   0x0f                // Get Remote Channel Audio Encoding Mode, pInBuf= ZZNET_IN_GET_REMOTE_CHANNEL_AUDIO_ENCODEINFO*, pOutBuf= ZZNET_OUT_GET_REMOTE_CHANNEL_AUDIO_ENCODEINFO *
#define ZZNET_QUERY_GET_COMM_PORT_INFO                0x10                // Get Device Serial Port Info, pInBuf=ZZNET_IN_GET_COMM_PORT_INFO* , pOutBuf=ZZNET_OUT_GET_COMM_PORT_INFO* 
#define ZZNET_QUERY_GET_LINKCHANNELS                  0x11                // Query Linked Channel List of a Video Channel, pInBuf=ZZNET_IN_GET_LINKCHANNELS* , pOutBuf=ZZNET_OUT_GET_LINKCHANNELS*
#define ZZNET_QUERY_GET_VIDEOOUTPUTCHANNELS           0x12                // Get Decoding Channel Count Statistics, pInBuf=ZZNET_IN_GET_VIDEOOUTPUTCHANNELS*, pOutBuf=ZZNET_OUT_GET_VIDEOOUTPUTCHANNELS*
#define ZZNET_QUERY_GET_VIDEOINFO                     0x13                // Get Decoding Channel Info, pInBuf=ZZNET_IN_GET_VIDEOINFO*, pOutBuf=ZZNET_OUT_GET_VIDEOINFO*
#define ZZNET_QUERY_GET_ALLLINKCHANNELS               0x14                // Query All Linked Video Channel Lists, pInBuf=ZZNET_IN_GET_ALLLINKCHANNELS* , pOutBuf=ZZNET_OUT_GET_ALLLINKCHANNELS*
#define ZZNET_QUERY_VIDEOCHANNELSINFO                 0x15                // Query Video Channel Info, pInBuf=ZZNET_IN_GET_VIDEOCHANNELSINFO* , pOutBuf=ZZNET_OUT_GET_VIDEOCHANNELSINFO*
#define ZZNET_QUERY_TRAFFICRADAR_VERSION              0x16                // Query Radar Device Version, pInBuf=ZZNET_IN_TRAFFICRADAR_VERSION* , pOutBuf=ZZNET_OUT_TRAFFICRADAR_VERSION*
#define ZZNET_QUERY_WORKGROUP_NAMES                   0x17                // Query All Work Group Names, pInBuf=ZZNET_IN_WORKGROUP_NAMES* , pOutBuf=ZZNET_OUT_WORKGROUP_NAMES*
#define ZZNET_QUERY_WORKGROUP_INFO                    0x18                // Query Work Group Info, pInBuf=ZZNET_IN_WORKGROUP_INFO* , pOutBuf=ZZNET_OUT_WORKGROUP_INFO*
#define ZZNET_QUERY_WLAN_ACCESSPOINT                  0x19                // Query WLAN Access Point Info, pInBuf=ZZNET_IN_WLAN_ACCESSPOINT* , pOutBuf=ZZNET_OUT_WLAN_ACCESSPOINT*
#define ZZNET_QUERY_GPS_INFO						  0x1a				  // Query Device GPS Info, pInBuf=ZZNET_IN_DEV_GPS_INFO* , pOutBuf=ZZNET_OUT_DEV_GPS_INFO*
#define ZZNET_QUERY_IVS_REMOTE_DEVICE_INFO            0x1b                // Query Remote Device Info linked to IVS Frontend Device, pInBuf = ZZNET_IN_IVS_REMOTE_DEV_INFO*, pOutBuf = ZZNET_OUT_IVS_REMOTE_DEV_INFO*
#define ZZNET_QUERY_SMART_SWITCH_INFO                 0x1c                // Query Smart Switch Info, pInBuf = ZZNET_IN_SMART_SWITCH_INFO*,  pOutBuf = ZZNET_OUT_SMART_SWITCH_INFO*
#define ZZNET_QUERY_UPGRADE_STATE                     0x1d                // Query Upgrade State Info, pInBuf = ZZNET_IN_UPGRADE_STATE*, pOutBuf = ZZNET_OUT_UPGRADE_STATE* 
#define ZZNET_QUERY_VIDEO_ENCODE_CAPS				  0x1e				  // Get Video Encode Capability Set, pInBuf = ZZNET_IN_VIDEO_ENCODE_CAPS*, pOutBuf = ZZNET_OUT_VIDEO_ENCODE_CAPS* 
#define ZZNET_QUERY_AUDIO_ENCODE_CAPS				  0x1f				  // Get Audio Encode Capability Set, pInBuf = ZZNET_IN_AUDIO_ENCODE_CAPS*, pOutBuf = ZZNET_OUT_AUDIO_ENCODE_CAPS* 
#define ZZNET_QUERY_AUDIO_IN_CAPS					  0x20				  // Get Audio Input Channel Capability Set, pInBuf = ZZNET_IN_AUDIO_IN_CAPS*, pOutBuf = ZZNET_OUT_AUDIO_IN_CAPS* 
#define ZZNET_QUERY_SMART_ENCODE_CAPS				  0x21				  // Query Smart Encode Capability Set, pInBuf = ZZNET_IN_SMART_ENCODE_CAPS*, pOutBuf = ZZNET_OUT_SMART_ENCODE_CAPS* 
#define ZZNET_QUERY_HARDDISK_TEMPERATURE			  0x22				  // Get HDD Temperature, pInBuf = ZZNET_IN_HDD_TEMPERATURE*, pOutBuf = ZZNET_OUT_HDD_TEMPERATURE*
#define ZZNET_QUERY_RAWFRAMEDATA					  0x23				  // Get YUV Data of Specified Format, pInBuf = ZZNET_IN_RAWFRAMEDATA*, pOutBuf = ZZNET_OUT_RAWFRAMEDARA*


#define ZZNET_QUERY_HTTP_PROXY_PORT                   0x34                /// Get Virtual Host Web Proxy Port, pInBuf = ZZNET_IN_HTTP_PROXY_PORT*, pOutBuf = ZZNET_OUT_HTTP_PROXY_PORT*






















// Intelligent Analysis Event Types
#define ZZ_EVENT_IVS_ALL                           0x00000001        // Subscribe all events
#define ZZ_EVENT_IVS_CROSSLINEDETECTION            0x00000002        // Warning Line / Tripwire Event (Corresponds to DEV_EVENT_CROSSLINE_INFO)
#define ZZ_EVENT_IVS_CROSSREGIONDETECTION          0x00000003        // Warning Region / Intrusion Event (Corresponds to DEV_EVENT_CROSSREGION_INFO)
#define ZZ_EVENT_IVS_PASTEDETECTION                0x00000004        // Paste / Stick Detection Event (Corresponds to DEV_EVENT_PASTE_INFO)
#define ZZ_EVENT_IVS_LEFTDETECTION                 0x00000005        // Abandoned Object Event (Corresponds to DEV_EVENT_LEFT_INFO)
#define ZZ_EVENT_IVS_STAYDETECTION                 0x00000006        // Stay Detection Event (Corresponds to DEV_EVENT_STAY_INFO)
#define ZZ_EVENT_IVS_WANDERDETECTION               0x00000007        // Wandering Detection Event (Corresponds to DEV_EVENT_WANDER_INFO)
#define ZZ_EVENT_IVS_PRESERVATION                  0x00000008        // Object Preservation / Missing Object Event (Corresponds to DEV_EVENT_PRESERVATION_INFO)
#define ZZ_EVENT_IVS_MOVEDETECTION                 0x00000009        // Move Event (Corresponds to DEV_EVENT_MOVE_INFO)
#define ZZ_EVENT_IVS_TAILDETECTION                 0x0000000A        // Tailgating Event (Corresponds to DEV_EVENT_TAIL_INFO)
#define ZZ_EVENT_IVS_RIOTERDETECTION               0x0000000B        // Riot/Crowd Detection Event (Corresponds to DEV_EVENT_RIOTERL_INFO)
#define ZZ_EVENT_IVS_FIREDETECTION                 0x0000000C        // Fire Alarm Event (Corresponds to DEV_EVENT_FIRE_INFO)
#define ZZ_EVENT_IVS_SMOKEDETECTION                0x0000000D        // Smoke Alarm Event (Corresponds to DEV_EVENT_SMOKE_INFO)
#define ZZ_EVENT_IVS_FIGHTDETECTION                0x0000000E        // Fight Detection Event (Corresponds to DEV_EVENT_FLOWSTAT_INFO)
#define ZZ_EVENT_IVS_FLOWSTAT                      0x0000000F        // Flow Statistics Event (Corresponds to DEV_EVENT_FLOWSTAT_INFO)
#define ZZ_EVENT_IVS_NUMBERSTAT                    0x00000010        // Quantity Statistics Event (Corresponds to DEV_EVENT_NUMBERSTAT_INFO)
#define ZZ_EVENT_IVS_CAMERACOVERDDETECTION         0x00000011        // Camera Covered Event (Reserved)
#define ZZ_EVENT_IVS_CAMERAMOVEDDETECTION          0x00000012        // Camera Moved Event (Reserved)
#define ZZ_EVENT_IVS_VIDEOABNORMALDETECTION        0x00000013        // Video Abnormal Event (Corresponds to DEV_EVENT_VIDEOABNORMALDETECTION_INFO)
#define ZZ_EVENT_IVS_VIDEOBADDETECTION             0x00000014        // Video Bad Event (Reserved)
#define ZZ_EVENT_IVS_TRAFFICCONTROL                0x00000015        // Traffic Control Event (Corresponds to DEV_EVENT_TRAFFICCONTROL_INFO)
#define ZZ_EVENT_IVS_TRAFFICACCIDENT               0x00000016        // Traffic Accident Event (Corresponds to DEV_EVENT_TRAFFICACCIDENT_INFO)
#define ZZ_EVENT_IVS_TRAFFICJUNCTION               0x00000017        // Traffic Junction Event ---- Old Rule (Corresponds to DEV_EVENT_TRAFFICJUNCTION_INFO)
#define ZZ_EVENT_IVS_TRAFFICGATE                   0x00000018        // Traffic Gate / Checkpoint Event ---- Old Rule (Corresponds to DEV_EVENT_TRAFFICGATE_INFO)
#define ZZ_EVENT_TRAFFICSNAPSHOT                   0x00000019        // Traffic Snapshot Event (Corresponds to DEV_EVENT_TRAFFICSNAPSHOT_INFO)
#define ZZ_EVENT_IVS_FACEDETECT                    0x0000001A        // Face Detection Event (Corresponds to DEV_EVENT_FACEDETECT_INFO)
#define ZZ_EVENT_IVS_TRAFFICJAM                    0x0000001B        // Traffic Jam Event (Corresponds to DEV_EVENT_TRAFFICJAM_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_RUNREDLIGHT           0x00000100        // Traffic Violation - Run Red Light Event (Corresponds to DEV_EVENT_TRAFFIC_RUNREDLIGHT_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_OVERLINE              0x00000101        // Traffic Violation - Cross Lane Line Event (Corresponds to DEV_EVENT_TRAFFIC_OVERLINE_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_RETROGRADE            0x00000102        // Traffic Violation - Retrograde/Wrong-way Event (Corresponds to DEV_EVENT_TRAFFIC_RETROGRADE_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_TURNLEFT              0x00000103        // Traffic Violation - Illegal Left Turn (Corresponds to DEV_EVENT_TRAFFIC_TURNLEFT_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_TURNRIGHT             0x00000104        // Traffic Violation - Illegal Right Turn (Corresponds to DEV_EVENT_TRAFFIC_TURNRIGHT_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_UTURN                 0x00000105        // Traffic Violation - Illegal U-Turn (Corresponds to DEV_EVENT_TRAFFIC_UTURN_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_OVERSPEED             0x00000106        // Traffic Violation - Overspeed (Corresponds to DEV_EVENT_TRAFFIC_OVERSPEED_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_UNDERSPEED            0x00000107        // Traffic Violation - Underspeed (Corresponds to DEV_EVENT_TRAFFIC_UNDERSPEED_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_PARKING               0x00000108        // Traffic Violation - Illegal Parking (Corresponds to DEV_EVENT_TRAFFIC_PARKING_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_WRONGROUTE            0x00000109        // Traffic Violation - Wrong Route/Not Driving in Lane (Corresponds to DEV_EVENT_TRAFFIC_WRONGROUTE_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_CROSSLANE             0x0000010A        // Traffic Violation - Illegal Lane Change (Corresponds to DEV_EVENT_TRAFFIC_CROSSLANE_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_OVERYELLOWLINE        0x0000010B        // Traffic Violation - Cross Yellow Line (Corresponds to DEV_EVENT_TRAFFIC_OVERYELLOWLINE_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_DRIVINGONSHOULDER     0x0000010C        // Traffic Violation - Driving on Shoulder Event (Corresponds to DEV_EVENT_TRAFFIC_DRIVINGONSHOULDER_INFO)   
#define ZZ_EVENT_IVS_TRAFFIC_YELLOWPLATEINLANE     0x0000010E        // Traffic Violation - Yellow Plate Car in Lane Event (Corresponds to DEV_EVENT_TRAFFIC_YELLOWPLATEINLANE_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_PEDESTRAINPRIORITY    0x0000010F        // Traffic Violation - Pedestrian Priority at Crosswalk Event (Corresponds to DEV_EVENT_TRAFFIC_PEDESTRAINPRIORITY_INFO)
#define ZZ_EVENT_IVS_CROSSFENCEDETECTION           0x0000011F        // Cross Fence Detection Event (Corresponds to DEV_EVENT_CROSSFENCEDETECTION_INFO)
#define ZZ_EVENT_IVS_ELECTROSPARKDETECTION         0x00000110        // Electric Spark Event (Corresponds to DEV_EVENT_ELECTROSPARK_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_NOPASSING             0x00000111        // Traffic Violation - No Passing Event (Corresponds to DEV_EVENT_TRAFFIC_NOPASSING_INFO)
#define ZZ_EVENT_IVS_ABNORMALRUNDETECTION          0x00000112        // Abnormal Running Detection Event (Corresponds to DEV_EVENT_ABNORMALRUNDETECTION_INFO)
#define ZZ_EVENT_IVS_RETROGRADEDETECTION           0x00000113        // Person Retrograde Detection Event (Corresponds to DEV_EVENT_RETROGRADEDETECTION_INFO)
#define ZZ_EVENT_IVS_INREGIONDETECTION             0x00000114        // In-Region Detection Event (Corresponds to DEV_EVENT_INREGIONDETECTION_INFO)
#define ZZ_EVENT_IVS_TAKENAWAYDETECTION            0x00000115        // Taken Away Detection Event (Corresponds to DEV_EVENT_TAKENAWAYDETECTION_INFO)
#define ZZ_EVENT_IVS_PARKINGDETECTION              0x00000116        // Illegal Parking Detection Event (Corresponds to DEV_EVENT_PARKINGDETECTION_INFO)
#define ZZ_EVENT_IVS_FACERECOGNITION               0x00000117        // Face Recognition Event (Corresponds to DEV_EVENT_FACERECOGNITION_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_MANUALSNAP            0x00000118        // Traffic Manual Snapshot Event (Corresponds to DEV_EVENT_TRAFFIC_MANUALSNAP_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_FLOWSTATE             0x00000119        // Traffic Flow Statistics Event (Corresponds to DEV_EVENT_TRAFFIC_FLOW_STATE)
#define ZZ_EVENT_IVS_TRAFFIC_STAY                  0x0000011A        // Traffic Stay/Stranded Event (Corresponds to DEV_EVENT_TRAFFIC_STAY_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_VEHICLEINROUTE        0x0000011B        // Vehicle in Route Event (Corresponds to DEV_EVENT_TRAFFIC_VEHICLEINROUTE_INFO)
#define ZZ_EVENT_ALARM_MOTIONDETECT                0x0000011C        // Video Motion Detection Event (Corresponds to DEV_EVENT_ALARM_INFO)
#define ZZ_EVENT_ALARM_LOCALALARM                  0x0000011D        // External Alarm Event (Corresponds to DEV_EVENT_ALARM_INFO)
#define ZZ_EVENT_IVS_PRISONERRISEDETECTION         0x0000011E        // Prisoner Rise Detection Event (Corresponds to DEV_EVENT_PRISONERRISEDETECTION_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_TOLLGATE              0x00000120        // Traffic Violation - Tollgate/Checkpoint Event ---- New Rule (Corresponds to DEV_EVENT_TRAFFICJUNCTION_INFO)
#define ZZ_EVENT_IVS_DENSITYDETECTION              0x00000121        // Density Detection (Corresponds to DEV_EVENT_DENSITYDETECTION_INFO)
#define ZZ_EVENT_IVS_VIDEODIAGNOSIS                0x00000122        // Video Diagnosis Result Event (Corresponds to NET_VIDEODIAGNOSIS_COMMON_INFO and NET_REAL_DIAGNOSIS_RESULT)
#define ZZ_EVENT_IVS_QUEUEDETECTION                0x00000123        // Queue Detection Alarm Event (Corresponds to DEV_EVENT_QUEUEDETECTION_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_VEHICLEINBUSROUTE     0x00000124        // Vehicle in Bus Route Event (Corresponds to DEV_EVENT_TRAFFIC_VEHICLEINBUSROUTE_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_BACKING               0x00000125        // Traffic Illegal Reversing Event (Corresponds to DEV_EVENT_IVS_TRAFFIC_BACKING_INFO)
#define ZZ_EVENT_IVS_AUDIO_ABNORMALDETECTION       0x00000126        // Audio Abnormal Detection (Corresponds to DEV_EVENT_IVS_AUDIO_ABNORMALDETECTION_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_RUNYELLOWLIGHT        0x00000127        // Traffic Violation - Run Yellow Light Event (Corresponds to DEV_EVENT_TRAFFIC_RUNYELLOWLIGHT_INFO)
#define ZZ_EVENT_IVS_CLIMBDETECTION                0x00000128        // Climb Detection Event (Corresponds to DEV_EVENT_IVS_CLIMB_INFO)
#define ZZ_EVENT_IVS_LEAVEDETECTION                0x00000129        // Leave Post Detection Event (Corresponds to DEV_EVENT_IVS_LEAVE_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_PARKINGONYELLOWBOX    0x0000012A        // Parking on Yellow Box Snapshot Event (Corresponds to DEV_EVENT_TRAFFIC_PARKINGONYELLOWBOX_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_PARKINGSPACEPARKING   0x0000012B        // Parking Space Occupied Event (Corresponds to DEV_EVENT_TRAFFIC_PARKINGSPACEPARKING_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_PARKINGSPACENOPARKING 0x0000012C        // Parking Space Empty Event (Corresponds to DEV_EVENT_TRAFFIC_PARKINGSPACENOPARKING_INFO)    
#define ZZ_EVENT_IVS_TRAFFIC_PEDESTRAIN            0x0000012D        // Traffic Pedestrian Event (Corresponds to DEV_EVENT_TRAFFIC_PEDESTRAIN_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_THROW                 0x0000012E        // Traffic Throwing Objects Event (Corresponds to DEV_EVENT_TRAFFIC_THROW_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_IDLE                  0x0000012F        // Traffic Idle Event (Corresponds to DEV_EVENT_TRAFFIC_IDLE_INFO)
#define ZZ_EVENT_ALARM_VEHICLEACC                  0x00000130        // Vehicle ACC Power Off Alarm Event (Corresponds to DEV_EVENT_ALARM_VEHICLEACC_INFO)
#define ZZ_EVENT_ALARM_VEHICLE_TURNOVER            0x00000131        // Vehicle Turnover Alarm Event (Corresponds to DEV_EVENT_VEHICEL_ALARM_INFO)
#define ZZ_EVENT_ALARM_VEHICLE_COLLISION           0x00000132        // Vehicle Collision Alarm Event (Corresponds to DEV_EVENT_VEHICEL_ALARM_INFO)
#define ZZ_EVENT_ALARM_VEHICLE_LARGE_ANGLE         0x00000133        // Vehicle Camera Large Angle Rotation Event
#define ZZ_EVENT_IVS_TRAFFIC_PARKINGSPACEOVERLINE  0x00000134        // Parking Space Over Line Event (Corresponds to DEV_EVENT_TRAFFIC_PARKINGSPACEOVERLINE_INFO)
#define ZZ_EVENT_IVS_MULTISCENESWITCH              0x00000135        // Multi-Scene Switch Event (Corresponds to DEV_EVENT_IVS_MULTI_SCENE_SWICH_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_RESTRICTED_PLATE      0x00000136        // Restricted Plate Event (Corresponds to DEV_EVENT_TRAFFIC_RESTRICTED_PLATE)
#define ZZ_EVENT_IVS_TRAFFIC_OVERSTOPLINE          0x00000137        // Over Stop Line Event (Corresponds to DEV_EVENT_TRAFFIC_OVERSTOPLINE)
#define ZZ_EVENT_IVS_TRAFFIC_WITHOUT_SAFEBELT      0x00000138        // Traffic Without Seatbelt Event (Corresponds to DEV_EVENT_TRAFFIC_WITHOUT_SAFEBELT)
#define ZZ_EVENT_IVS_TRAFFIC_DRIVER_SMOKING        0x00000139        // Driver Smoking Event (Corresponds to DEV_EVENT_TRAFFIC_DRIVER_SMOKING)
#define ZZ_EVENT_IVS_TRAFFIC_DRIVER_CALLING        0x0000013A        // Driver Calling Event (Corresponds to DEV_EVENT_TRAFFIC_DRIVER_CALLING)
#define ZZ_EVENT_IVS_TRAFFIC_PEDESTRAINRUNREDLIGHT 0x0000013B        // Pedestrian Run Red Light Event (Corresponds to DEV_EVENT_TRAFFIC_PEDESTRAINRUNREDLIGHT_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_PASSNOTINORDER        0x0000013C        // Not Passing in Order (Corresponds to DEV_EVENT_TRAFFIC_PASSNOTINORDER_INFO)
#define ZZ_EVENT_IVS_OBJECT_DETECTION              0x00000141        // Object Feature Detection Event
#define ZZ_EVENT_ALARM_ANALOGALARM                 0x00000150        // Alarm Event of Analog Alarm Channel (Corresponds to DEV_EVENT_ALARM_ANALOGALRM_INFO)
#define ZZ_EVENT_IVS_CROSSLINEDETECTION_EX         0x00000151        // Warning Line / Tripwire Extension Event
#define ZZ_EVENT_ALARM_COMMON                      0x00000152        // Normal Recording
#define ZZ_EVENT_ALARM_VIDEOBLIND                  0x00000153        // Video Blind/Occlusion Event (Corresponds to DEV_EVENT_ALARM_VIDEOBLIND)
#define ZZ_EVENT_ALARM_VIDEOLOSS                   0x00000154        // Video Loss Event
#define ZZ_EVENT_IVS_GETOUTBEDDETECTION            0x00000155        // Get Out of Bed Detection Event (Corresponds to DEV_EVENT_GETOUTBED_INFO)
#define ZZ_EVENT_IVS_PATROLDETECTION               0x00000156        // Patrol Detection Event (Corresponds to DEV_EVENT_PATROL_INFO)
#define ZZ_EVENT_IVS_ONDUTYDETECTION               0x00000157        // On Duty Detection Event (Corresponds to DEV_EVENT_ONDUTY_INFO)
#define ZZ_EVENT_IVS_NOANSWERCALL                  0x00000158        // Door Unit Call No Answer Event
#define ZZ_EVENT_IVS_STORAGENOTEXIST               0x00000159        // Storage Group Not Exist Event
#define ZZ_EVENT_IVS_STORAGELOWSPACE               0x0000015A        // HDD Low Space Alarm Event
#define ZZ_EVENT_IVS_STORAGEFAILURE                0x0000015B        // Storage Failure Event
#define ZZ_EVENT_IVS_PROFILEALARMTRANSMIT          0x0000015C        // Alarm Transmission Event
#define ZZ_EVENT_IVS_VIDEOSTATIC                   0x0000015D        // Video Static Detection Event (Corresponds to DEV_EVENT_ALARM_VIDEOSTATIC_INFO)
#define ZZ_EVENT_IVS_VIDEOTIMING                   0x0000015E        // Video Timing Detection Event (Corresponds to DEV_EVENT_ALARM_VIDEOTIMING_INFO)
#define ZZ_EVENT_IVS_HEATMAP                       0x0000015F        // Heat Map (Corresponds to CFG_IVS_HEATMAP_INFO)
#define ZZ_EVENT_IVS_CITIZENIDCARD                 0x00000160        // Citizen ID Card Info Read Event (Corresponds to DEV_EVENT_ALARM_CITIZENIDCARD_INFO)
#define ZZ_EVENT_IVS_PICINFO                       0x00000161        // Picture Info Event (Corresponds to DEV_EVENT_ALARM_PIC_INFO)
#define ZZ_EVENT_IVS_NETPLAYCHECK                  0x00000162        // Internet Surfing Registration Event (Corresponds to DEV_EVENT_ALARM_NETPLAYCHECK_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_JAM_FORBID_INTO       0x00000163        // Traffic Jam Forbid Into Event (Corresponds to DEV_EVENT_ALARM_JAMFORBIDINTO_INFO)
#define ZZ_EVENT_IVS_SNAPBYTIME                    0x00000164        // Timing Snapshot Event (Corresponds to DEV_EVENT_SNAPBYTIME)
#define ZZ_EVENT_IVS_PTZ_PRESET                    0x00000165        // PTZ Rotate to Preset Event (Corresponds to DEV_EVENT_ALARM_PTZ_PRESET_INFO)
#define ZZ_EVENT_IVS_RFID_INFO                     0x00000166        // RFID Info Event (Corresponds to DEV_EVENT_ALARM_RFID_INFO)
#define ZZ_EVENT_IVS_STANDUPDETECTION              0x00000167        // Person Stand Up Detection Event 
#define ZZ_EVENT_IVS_QSYTRAFFICCARWEIGHT           0x00000168        // Traffic Checkpoint Weighing Event (Corresponds to DEV_EVENT_QSYTRAFFICCARWEIGHT_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_COMPAREPLATE          0x00000169        // Checkpoint Front & Rear Plate Comparison Event (Corresponds to DEV_EVENT_TRAFFIC_COMPAREPLATE_INFO)
#define ZZ_EVENT_IVS_SHOOTINGSCORERECOGNITION      0x0000016A        // Shooting Score Recognition Event (Corresponds to DEV_EVENT_SHOOTING_SCORE_RECOGNITION_INFO,CFG_IVS_SHOOTINGSCORERECOGNITION_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_FCC                   0x0000016B        // Gas Station Gun Lift/Hang Event (Corresponds to DEV_EVENT_TRAFFIC_FCC_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_TRANSFINITE           0x0000016C        // Over-limit Snapshot Upload Event, Shaoxing Technology Overload Control (Corresponds to DEV_EVENT_TRAFFIC_TRANSFINITE_INFO)
#define ZZ_EVENT_IVS_SCENE_CHANGE                  0x0000016D        // Scene Change Event (Corresponds to DEV_ALRAM_SCENECHANGE_INFO,CFG_VIDEOABNORMALDETECTION_INFO)
#define ZZ_EVENT_IVS_LETRACK                       0x0000016E        // Simple Tracking Event (No specific event yet)
#define ZZ_EVENT_IVS_OBJECT_ACTION                 0x0000016F        // Object Detection Event (No specific event yet)
#define ZZ_EVENT_IVS_TRAFFIC_ANALYSE_PRESNAP       0x00000170        // Pre-analysis Snapshot Event (Corresponds to DEV_EVENT_TRAFFIC_ANALYSE_PRESNAP_INFO)
#define ZZ_EVENT_ALARM_EQSTATE                     0x00000171        // Smart Socket Power State Report (No specific event yet)
#define ZZ_EVENT_IVS_ALARM_IPC                     0x00000172        // IPC Alarm on DVR/NVR device (No specific event yet)
#define ZZ_EVENT_IVS_POS_RECORD                    0x00000173        // POS Recording Query Event (No specific event yet)
#define ZZ_EVENT_IVS_NEAR_DISTANCE_DETECTION       0x00000174        // Near Distance Detection Event (Corresponds to DEV_EVENT_NEAR_DISTANCE_DETECTION_INFO)
#define ZZ_EVENT_IVS_OBJECTSTRUCTLIZE_PERSON       0x00000175        // Pedestrian Feature Detection Event (Corresponds to DEV_EVENT_OBJECTSTRUCTLIZE_PERSON_INFO)
#define ZZ_EVENT_IVS_OBJECTSTRUCTLIZE_NONMOTOR     0x00000176        // Non-motor Vehicle Feature Detection Event (Corresponds to DEV_EVENT_OBJECTSTRUCTLIZE_NONMOTOR_INFO)
#define ZZ_EVENT_IVS_TUMBLE_DETECTION              0x00000177        // Fall/Tumble Detection Alarm Event (Corresponds to DEV_EVENT_TUMBLE_DETECTION_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_ALL                   0x000001FF        // All events starting with traffic, currently refers to
                                                                  // EVENT_IVS_TRAFFICCONTROL -> EVENT_TRAFFICSNAPSHOT
                                                                  // EVENT_IVS_TRAFFIC_RUNREDLIGHT -> EVENT_IVS_TRAFFIC_UNDERSPEED
#define ZZ_EVENT_IVS_VIDEOANALYSE                  0x00000200      // All intelligent analysis events 
#define ZZ_EVENT_IVS_LINKSD                        0x00000201      // LinkSD Event (Corresponds to DEV_EVENT_LINK_SD)
#define ZZ_EVENT_IVS_VEHICLEANALYSE                0x00000202      // Vehicle Feature Analysis (Corresponds to DEV_EVENT_VEHICLEANALYSE)
#define ZZ_EVENT_IVS_FLOWRATE                      0x00000203      // Flow Usage Event (Corresponds to DEV_EVENT_FLOWRATE_INFO)
#define ZZ_EVENT_IVS_ACCESS_CTL                    0x00000204      // Access Control Event (Corresponds to DEV_EVENT_ACCESS_CTL_INFO)
#define ZZ_EVENT_IVS_SNAPMANUAL                    0x00000205      // SnapManual Event (Corresponds to DEV_EVENT_SNAPMANUAL)
#define ZZ_EVENT_IVS_TRAFFIC_ELETAGINFO            0x00000206      // RFID Electronic Plate Tag Event (Corresponds to DEV_EVENT_TRAFFIC_ELETAGINFO_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_TIREDPHYSIOLOGICAL    0x00000207      // Physiological Fatigue Driving Event (Corresponds to DEV_EVENT_TIREDPHYSIOLOGICAL_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_BUSSHARPTURN          0x00000208      // Vehicle Sharp Turn Alarm Event (Corresponds to DEV_EVENT_BUSSHARPTURN_INFO)
#define ZZ_EVENT_IVS_CITIZEN_PICTURE_COMPARE       0x00000209      // Person-ID Comparison Event (Corresponds to DEV_EVENT_CITIZEN_PICTURE_COMPARE_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_TIREDLOWERHEAD        0x0000020A      // Driving Lower Head Alarm Event (Corresponds to DEV_EVENT_TIREDLOWERHEAD_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_DRIVERLOOKAROUND      0x0000020B      // Driving Look Around Alarm Event (Corresponds to DEV_EVENT_DRIVERLOOKAROUND_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_DRIVERLEAVEPOST       0x0000020C      // Driving Leave Post Alarm Event (Corresponds to DEV_EVENT_DRIVERLEAVEPOST_INFO)
#define ZZ_EVENT_IVS_MAN_STAND_DETECTION           0x0000020D      // Stereo Vision Standing Event (Corresponds to DEV_EVENT_MANSTAND_DETECTION_INFO)
#define ZZ_EVENT_IVS_MAN_NUM_DETECTION             0x0000020E      // Stereo Vision People Counting in Region Event (Corresponds to DEV_EVENT_MANNUM_DETECTION_INFO)
#define ZZ_EVENT_IVS_STEREO_NUMBERSTAT             0x0000020F      // Passenger Flow Statistics Event (No specific event yet)
#define ZZ_EVENT_IVS_TRAFFIC_DRIVERYAWN            0x00000210      // Driving Yawn Event (Corresponds to DEV_EVENT_DRIVERYAWN_INFO)
#define ZZ_EVENT_IVS_NUMBERSTAT_PLAN               0x00000211      // Passenger Flow Statistics Plan (No specific event yet, used by PTZ, corresponds to rule config struct CFG_NUMBERSTAT_INFO)
#define ZZ_EVENT_IVS_HEATMAP_PLAN                  0x00000212      // Heat Map Plan (No specific event yet, used by PTZ, corresponds to rule config struct CFG_IVS_HEATMAP_INFO)
#define ZZ_EVENT_IVS_CALLNOANSWERED                0x00000213      // Call Not Answered Event
#define ZZ_EVENT_IVS_IGNOREINVITE                  0x00000214      // Ignore Invite Event
#define ZZ_EVENT_IVS_HUMANTRAIT                    0x00000215      // Human Trait Event (Corresponds to DEV_EVENT_HUMANTRAIT_INFO)
#define ZZ_EVENT_ALARM_LE_HEADDETECTION            0x00000216      // LeChange Head Detection Event, only used for subscribing to mobile push
#define ZZ_EVENT_IVS_FACEANALYSIS                  0x00000217      // Face Analysis Event (No specific event yet)
#define ZZ_EVENT_IVS_TRAFFIC_TURNLEFTAFTERSTRAIGHT 0x00000218      // Left Turn Not Yielding to Straight Event (Corresponds to DEV_EVENT_TURNLEFTAFTERSTRAIGHT_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_BIGBENDSMALLTURN      0x00000219      // Big Bend Small Turn Event (Corresponds to DEV_EVENT_BIGBENDSMALLTURN_INFO)
#define ZZ_EVENT_IVS_ROAD_CONSTRUCTION             0x0000021A      // Road Construction Monitoring Event (Corresponds to DEV_EVENT_ROAD_CONSTRUCTION_INFO)
#define ZZ_EVENT_IVS_ROAD_BLOCK                    0x0000021B      // Road Block Detection Event (Corresponds to DEV_EVENT_ROAD_BLOCK_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_QUEUEJUMP             0x0000021C      // Traffic Queue Jump / Cutting In Event (Corresponds to DEV_EVENT_TRAFFIC_QUEUEJUMP_INFO)
#define ZZ_EVENT_IVS_VEHICLE_SUSPICIOUSCAR         0x0000021D      // Suspicious Vehicle Event (Corresponds to DEV_EVENT_VEHICLE_SUSPICIOUSCAR_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_TURNRIGHTAFTERSTRAIGHT  0x0000021E    // Right Turn Not Yielding to Straight Event (Corresponds to DEV_EVENT_TURNRIGHTAFTERSTRAIGHT_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_TURNRIGHTAFTERPEOPLE    0x0000021F    // Right Turn Not Yielding to Pedestrian (Corresponds to DEV_EVENT_TURNRIGHTAFTERPEOPLE_INFO)
#define ZZ_EVENT_IVS_INSTALL_CARDREADER            0x00000220      // Install Card Reader Event (Corresponds to DEV_EVENT_INSTALL_CARDREADER_INFO)
#define ZZ_EVENT_ALARM_YALE_DROPBOX_BADTOKEN       0x00000221      // Yale token invalid event, only used for subscribing to mobile push
#define ZZ_EVENT_IVS_ACC_OFF_SNAP                  0x00000222      // Vehicle Device Power Off Snapshot Upload Event (Corresponds to DEV_EVENT_ACC_OFF_SNAP_INFO)
#define ZZ_EVENI_IVS_XRAY_DETECTION				0x00000223		// X-Ray Detection Event (Corresponds to DEV_EVENT_XRAY_DETECTION_INFO)
#define ZZ_EVENT_IVS_NOTCLEARCAR					0x00000224		// Not Clear Car Warning (Corresponds to DEV_EVENT_NOTCLEARCAR_INFO)
#define ZZ_EVENT_IVS_SOSALEART						0x00000225		// SOS Alert (Corresponds to DEV_EVENT_SOSALEART_INFO)
#define ZZ_EVENT_IVS_OVERLOAD						0x00000226		// Overload Snapshot (Corresponds to DEV_EVENT_OVERLOAD_INFO)
#define ZZ_EVENT_IVS_NONWORKINGTIME				0x00000227		// Non-working Time Alert (Corresponds to DEV_EVENT_NONWORKINGTIME_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_HIGH_BEAM				0x00000228		// High Beam Violation Event (Corresponds to DEV_EVENT_TRAFFIC_HIGH_BEAM_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_TRUCKFORBID			0x00000229		// Truck Forbidden Event (Corresponds to DEV_EVENT_TRAFFICTRUCKFORBID_INFO)
#define ZZ_EVENT_IVS_DRIVINGWITHOUTCARD			0x0000022A		// Driving Without Card Alarm Event (Corresponds to DEV_EVENT_DRIVINGWITHOUTCARD_INFO)
#define ZZ_EVENT_IVS_HIGHSPEED						0x0000022B		// Vehicle High Speed Alarm Event (Corresponds to DEV_EVENT_HIGHSPEED_INFO)
#define ZZ_EVENT_IVS_CROWDDETECTION				0x0000022C		// Crowd Density Detection Event (Corresponds to struct DEV_EVENT_CROWD_DETECTION_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_CARDISTANCESHORT		0x0000022D		// Car Distance Too Short Alarm Event (Corresponds to DEV_EVENT_TRAFFIC_CARDISTANCESHORT_INFO)
#define ZZ_EVENT_IVS_PEDESTRIAN_JUNCTION			0x00000230		// Pedestrian Junction Event (Corresponds to DEV_EVENT_PEDESTRIAN_JUNCTION_INFO)
#define ZZ_EVENT_IVS_VEHICLE_RECOGNITION           0x00000231      // License Plate Comparison Event (Sinopec Smart Gas Station Project) (Corresponds to DEV_EVENT_VEHICLE_RECOGNITION_INFO)
#define ZZ_EVENT_IVS_PASS_CHANGE					0x00000232		// Preset Image Change Event (Corresponds to DEV_EVENT_PASS_CHANGE_INFO)
#define ZZ_EVENT_IVS_TRAFFIC_PARKING_SPACEDETECTION 0x00000233		// Illegal Parking Camera Customized Single Ball Parking Space Detection Rule Event
#define ZZ_EVENT_IVS_TRAFFIC_WAITINGAREA           0x00000234		// Illegal Entry into Waiting Area Event (Corresponds to DEV_EVENT_TRAFFIC_WAITINGAREA_INFO)


#define ZZ_EVENT_ALARM_SMARTMOTION_HUMAN           0x00000279      /// Smart Video Motion Detection Event (Human), (Corresponds to DEV_EVENT_SMARTMOTION_HUMAN_INFO)
#define ZZ_EVENT_ALARM_SMARTMOTION_VEHICLE         0x0000027A      /// Smart Video Motion Detection Event (Vehicle), (Corresponds to DEV_EVENT_SMARTMOTION_VEHICLE_INFO)



// Device Storage Point Type, Device Disk Group Concept
#define STOR_POINT_READ_WRITE                   0x00001001      // Read/Write Group, prototype is "ReadWrite*", "ReadWrite*", represents read/write group, intermediate "*" can be empty or a number
#define STOR_POINT_READ_ONLY                    0x00001002      // Read-Only Group
#define STOR_POINT_REDUNDANT                    0x00001003      // Redundant Group, redundant copy of "ReadWirte" group
#define STOR_POINT_BACKUP                       0x00001004      // Backup Group, stops after full, will not loop overwrite
#define STOR_POINT_DRAW_FRAME                   0x00001005      // History Frame Extraction Group, extracts frames and writes to this group after specified time of real-time recording
#define STOR_POINT_NAS_FTP                      0x00001006      // Remote Network Storage Group (Protocol Type FTP), may have multiple
#define STOR_POINT_NAS_NFS                      0x00001007      // Remote Network Storage Group (Protocol Type NFS), may have multiple
#define STOR_POINT_NAS_SMB                      0x00001008      // Remote Network Storage Group (Protocol Type SMB), may have multiple
#define STOR_POINT_NAS_ISCSI                    0x00001009      // Remote Network Storage Group (Protocol Type ISCSI), may have multiple
#define STOR_POINT_NAS_CLOUD                    0x0000100A      // Remote Network Storage Group (Protocol Type Cloud), may have multiple












///@brief ZZNETSDK_GetPrivacyMasking Input Parameters
typedef struct tagZZNET_IN_GET_PRIVACY_MASKING
{
	DWORD							dwSize;							/// Structure Size
	int								nChannel;						/// Channel Number
	int								nOffset;						/// Get from which masking block index this time
	int								nLimit;							/// How many masking block infos to get this time, max not exceeding 24
}ZZNET_IN_GET_PRIVACY_MASKING;

///@brief Privacy Masking Information
typedef struct tagZZNET_PRIVACY_MASKING_INFO
{
	int								nIndex;							/// Masking block index, starts from 0
	int								nEnable;						/// Privacy Masking Switch Flag 1 On, 0 Off
	char							szName[64];						/// Each masking block can be named
	EM_ZZ_PRIVACY_MASKING_TYPE		emShapeType;					/// Shape type is Rectangle, Rect item valid (Default), Shape type is Polygon, then Polygon item valid
	ZZ_RECT							stuRect;                        /// Rectangular Area, uses relative coordinate system, values 0-8192
	ZZNET_UINT_POINT				stuPolygon[64];					/// Polygon Vertex Coordinates, polygon vertices not exceeding 64, uses relative coordinate system, values 0-8192	
	int								nPointNum;						/// Number of Polygon Vertex Coordinates
	ZZ_COLOR_RGBA					stuColor;						/// Masking block color, mandatory if nMosaic is 0 when sending
	int								nMosaic;						/// Masking block mosaic type, Color invalid when Mosaic, specific value refers to nSupportMosaicType field in NET_MOSAIC_MASKING_CAPS after getting capability
	int								nShieldZoom;					/// Shield Zoom, degrees multiplied by 10 
	char							szResvered[512];				/// Reserved bytes
}ZZNET_PRIVACY_MASKING_INFO;

///@brief ZZNETSDK_GetPrivacyMasking Output Parameters
typedef struct tagZZNET_OUT_GET_PRIVACY_MASKING
{
	DWORD							dwSize;							/// Structure Size
	int								nTotal;							/// Total number of masking blocks
	ZZNET_PRIVACY_MASKING_INFO      stuPrivacyMaskingInfo[24];		/// Privacy masking block info
	int								nPrivacyMasking;				/// Returned privacy masking array count
}ZZNET_OUT_GET_PRIVACY_MASKING;


///@brief ZZNETSDK_GetPrivacyMaskingEnable Input Parameters
typedef struct tagZZNET_IN_GET_PRIVACY_MASKING_ENABLE
{
	DWORD							dwSize;							/// Structure Size
	int								nChannel;						/// Channel Number
}ZZNET_IN_GET_PRIVACY_MASKING_ENABLE;

///@brief ZZNETSDK_GetPrivacyMaskingEnable Output Parameters
typedef struct tagZZNET_OUT_GET_PRIVACY_MASKING_ENABLE
{
	DWORD							dwSize;							/// Structure Size
	BOOL							bEnable;						/// true On false Off
}ZZNET_OUT_GET_PRIVACY_MASKING_ENABLE;


///@brief ZZNETSDK_SetPrivacyMasking Input Parameters
typedef struct tagZZNET_IN_SET_PRIVACY_MASKING
{
	DWORD							dwSize;							/// Structure Size
	int								nChannel;						/// Channel Number
	ZZNET_PRIVACY_MASKING_INFO      stuPrivacyMaskingInfo;			/// Privacy masking block info
}ZZNET_IN_SET_PRIVACY_MASKING;

///@brief ZZNETSDK_SetPrivacyMasking Output Parameters
typedef struct tagZZNET_OUT_SET_PRIVACY_MASKING
{
	DWORD							dwSize;							/// Structure Size
}ZZNET_OUT_SET_PRIVACY_MASKING;

///@brief ZZNETSDK_SetPrivacyMaskingEnable Input Parameters
typedef struct tagZZNET_IN_SET_PRIVACY_MASKING_ENABLE
{
	DWORD							dwSize;							/// Structure Size
	int								nChannel;						/// Channel Number
	BOOL							bEnable;						/// true Enable all privacy masking blocks false Disable all privacy masking blocks
}ZZNET_IN_SET_PRIVACY_MASKING_ENABLE;

///@brief ZZNETSDK_SetPrivacyMaskingEnable Output Parameters
typedef struct tagZZNET_OUT_SET_PRIVACY_MASKING_ENABLE
{
	DWORD							dwSize;							/// Structure Size
}ZZNET_OUT_SET_PRIVACY_MASKING_ENABLE;

///@brief ZZNETSDK_DeletePrivacyMasking Input Parameters
typedef struct tagZZNET_IN_DELETE_PRIVACY_MASKING
{
	DWORD							dwSize;							/// Structure Size
	int								nChannel;						/// Channel Number
	int								nIndex;							/// Masking block index, starts from 0
}ZZNET_IN_DELETE_PRIVACY_MASKING;

///@brief ZZNETSDK_DeletePrivacyMasking Output Parameters
typedef struct tagZZNET_OUT_DELETE_PRIVACY_MASKING
{
	DWORD							dwSize;							/// Structure Size
}ZZNET_OUT_DELETE_PRIVACY_MASKING;


typedef struct tagZZNET_IN_GET_THUMBNAIL
{
	DWORD							dwSize;							/// Structure size
	int								nChannel;						/// Channel number
	ZZNET_TIME					    stTime;							/// Thumbnail capture time
    int                             nStreamType;                    /// Stream type    
}ZZNET_IN_GET_THUMBNAIL;

typedef struct tagZZNET_OUT_GET_THUMBNAIL
{
	DWORD							dwSize;							/// Structure size
	unsigned char*					pBuf;							/// User allocated memory
	int								nBufLen;						/// Memory length
	int								nRetLen;						/// Returned data length
}ZZNET_OUT_GET_THUMBNAIL;



typedef enum tagEM_ZZ_CONFIG_TYPE
{
    EM_ZZ_CONFIG_VideoInOptions,
    EM_ZZ_CONFIG_VideoColor,
    EM_ZZ_CONFIG_VideoStandard,
    EM_ZZ_CONFIG_Encode,
    EM_ZZ_CONFIG_VideoWaterMark,
    EM_ZZ_CONFIG_VideoWidget,
    EM_ZZ_CONFIG_ChannelTitle,
    EM_ZZ_CONFIG_VideoEncodeROI,
    EM_ZZ_CONFIG_VideoInPreviewOptions,
    EM_ZZ_CONFIG_VideoInSensor,
    EM_ZZ_CONFIG_PushServer,
    EM_ZZ_CONFIG_MultiSnap,
    EM_ZZ_CONFIG_AudioVqe,
    EM_ZZ_CONFIG_AudioInputVolume,
    EM_ZZ_CONFIG_AudioOutputVolume,

    EM_ZZ_CONFIG_NetAbort,
    EM_ZZ_CONFIG_PPPoE,
    EM_ZZ_CONFIG_DDNS,
    EM_ZZ_CONFIG_AlarmServer,
    EM_ZZ_CONFIG_NTP,
    EM_ZZ_CONFIG_Email,
    EM_ZZ_CONFIG_UPnP,
    EM_ZZ_CONFIG_SNMP,
    EM_ZZ_CONFIG_Bonjour,
    EM_ZZ_CONFIG_Qos,
    EM_ZZ_CONFIG_UserGlobal,
    EM_ZZ_CONFIG_VSP_GAYS,
    EM_ZZ_CONFIG_DVRIP,
    EM_ZZ_CONFIG_HTTPS,
    EM_ZZ_CONFIG_WEB,

    EM_ZZ_CONFIG_MotionDetect,
    EM_ZZ_CONFIG_BlindDetect,
    EM_ZZ_CONFIG_LossDetect,
    EM_ZZ_CONFIG_Alarm,
    EM_ZZ_CONFIG_NetAlarm,
    EM_ZZ_CONFIG_ExAlarm,
    EM_ZZ_CONFIG_AlarmOut,
    EM_ZZ_CONFIG_ExAlarmOut,
    EM_ZZ_CONFIG_IPConflict,
    EM_ZZ_CONFIG_StorageNotExist,
    EM_ZZ_CONFIG_StorageFailure,
    EM_ZZ_CONFIG_StorageLowSpace,

    EM_ZZ_CONFIG_Record,
    EM_ZZ_CONFIG_Snap,
    EM_ZZ_CONFIG_RecordMode,
    EM_ZZ_CONFIG_SnapMode,
    EM_ZZ_CONFIG_RecordStoragePoint,
    EM_ZZ_CONFIG_NAS,
    EM_ZZ_CONFIG_MediaGlobal,
    EM_ZZ_CONFIG_Holiday,
    EM_ZZ_CONFIG_VideoAnalyseRuleV2,
    EM_ZZ_CONFIG_VideoAnalyseModule,

    EM_ZZ_CONFIG_StorageInternal,
    EM_ZZ_CONFIG_StorageGlobal,
    EM_ZZ_CONFIG_StorageGroup,
    EM_ZZ_CONFIG_Comm,
    EM_ZZ_CONFIG_AutoMaintain,
    EM_ZZ_CONFIG_Locales,

    EM_ZZ_CONFIG_MAX

}EM_ZZ_CONFIG_TYPE;


typedef struct tagZZNET_CONFIG_PARAM
{
	char   szIP[ZZ_MAX_ILLEGAL_LOGIN_IP_LEN];
	char   szUserName[ZZ_USER_NAME_LEN_EX];
	char   szPassword[ZZ_USER_PSW_LEN_EX];

    int    nConfigNum;                  //Exported Configuration Count | Invalid during import, leave blank
    EM_ZZ_CONFIG_TYPE  configs[128];    //Invalid during import, leave blank
}ZZNET_CONFIG_PARAM;

typedef struct tagZZNET_EXPORT_CONFIG
{
	unsigned char*					pBuf;							/// User allocated memory
	int								nBufLen;						/// Memory length
	int								nRetLen;						/// Returned data length
}ZZNET_EXPORT_CONFIG;



///@brief MACRO_GROUP_ERROR_0_BEGIN
/// Error type codes, corresponding to return value of ZZNETSDK_GetLastError interface
#define _ZZEC(x)                                  (0x80000000|x)
#define ZZNET_NOERROR                             0                 /// No Error
#define ZZNET_ERROR                               -1                /// Unknown Error
#define ZZNET_SYSTEM_ERROR                        _ZZEC(1)            /// System Error
#define ZZNET_NETWORK_ERROR                       _ZZEC(2)            /// Network Error, likely due to network timeout
#define ZZNET_DEV_VER_NOMATCH                     _ZZEC(3)            /// Device Protocol Mismatch
#define ZZNET_INVALID_HANDLE                      _ZZEC(4)            /// Invalid Handle
#define ZZNET_OPEN_CHANNEL_ERROR                  _ZZEC(5)            /// Open Channel Failed
#define ZZNET_CLOSE_CHANNEL_ERROR                 _ZZEC(6)            /// Close Channel Failed
#define ZZNET_ILLEGAL_PARAM                       _ZZEC(7)            /// User Parameter Illegal
#define ZZNET_SDK_INIT_ERROR                      _ZZEC(8)            /// SDK Init Error
#define ZZNET_SDK_UNINIT_ERROR                    _ZZEC(9)            /// SDK Cleanup Error
#define ZZNET_RENDER_OPEN_ERROR                   _ZZEC(10)           /// Request Render Resource Error
#define ZZNET_DEC_OPEN_ERROR                      _ZZEC(11)           /// Open Decode Library Error
#define ZZNET_DEC_CLOSE_ERROR                     _ZZEC(12)           /// Close Decode Library Error
#define ZZNET_MULTIPLAY_NOCHANNEL                 _ZZEC(13)           /// No channels detected in multi-play preview
#define ZZNET_TALK_INIT_ERROR                     _ZZEC(14)           /// Talk Library Init Failed
#define ZZNET_TALK_NOT_INIT                       _ZZEC(15)           /// Talk Library Not Initialized
#define ZZNET_TALK_SENDDATA_ERROR                 _ZZEC(16)           /// Send Audio Data Error
#define ZZNET_REAL_ALREADY_SAVING                 _ZZEC(17)           /// Real-time data is already being saved
#define ZZNET_NOT_SAVING                          _ZZEC(18)           /// Not saving real-time data
#define ZZNET_OPEN_FILE_ERROR                     _ZZEC(19)           /// Open File Error
#define ZZNET_PTZ_SET_TIMER_ERROR                 _ZZEC(20)           /// Start PTZ control timer failed
#define ZZNET_RETURN_DATA_ERROR                   _ZZEC(21)           /// Validation of returned data failed
#define ZZNET_INSUFFICIENT_BUFFER                 _ZZEC(22)           /// Insufficient Buffer
#define ZZNET_NOT_SUPPORTED                       _ZZEC(23)           /// Current SDK does not support this function
#define ZZNET_NO_RECORD_FOUND                     _ZZEC(24)           /// No recording found
#define ZZNET_NOT_AUTHORIZED                      _ZZEC(25)           /// Unauthorized operation
#define ZZNET_NOT_NOW                             _ZZEC(26)           /// Cannot execute now
#define ZZNET_NO_TALK_CHANNEL                     _ZZEC(27)           /// Talk channel not found
#define ZZNET_NO_AUDIO                            _ZZEC(28)           /// Audio not found
#define ZZNET_NO_INIT                             _ZZEC(29)           /// Network SDK Not Initialized
#define ZZNET_DOWNLOAD_END                        _ZZEC(30)           /// Download Ended
#define ZZNET_EMPTY_LIST                          _ZZEC(31)           /// Query Result Empty
#define ZZNET_ERROR_GETCFG_SYSATTR                _ZZEC(32)           /// Get System Attribute Config Failed
#define ZZNET_ERROR_GETCFG_SERIAL                 _ZZEC(33)           /// Get Serial Number Failed
#define ZZNET_ERROR_GETCFG_GENERAL                _ZZEC(34)           /// Get General Attribute Failed
#define ZZNET_ERROR_GETCFG_DSPCAP                 _ZZEC(35)           /// Get DSP Capability Description Failed
#define ZZNET_ERROR_GETCFG_NETCFG                 _ZZEC(36)           /// Get Network Config Failed
#define ZZNET_ERROR_GETCFG_CHANNAME               _ZZEC(37)           /// Get Channel Name Failed
#define ZZNET_ERROR_GETCFG_VIDEO                  _ZZEC(38)           /// Get Video Attribute Failed
#define ZZNET_ERROR_GETCFG_RECORD                 _ZZEC(39)           /// Get Record Config Failed
#define ZZNET_ERROR_GETCFG_PRONAME                _ZZEC(40)           /// Get Decoder Protocol Name Failed
#define ZZNET_ERROR_GETCFG_FUNCNAME               _ZZEC(41)           /// Get 232 Serial Port Function Name Failed
#define ZZNET_ERROR_GETCFG_485DECODER             _ZZEC(42)           /// Get Decoder Attribute Failed
#define ZZNET_ERROR_GETCFG_232COM                 _ZZEC(43)           /// Get 232 Serial Port Config Failed
#define ZZNET_ERROR_GETCFG_ALARMIN                _ZZEC(44)           /// Get External Alarm Input Config Failed
#define ZZNET_ERROR_GETCFG_ALARMDET               _ZZEC(45)           /// Get Motion Detection Alarm Failed
#define ZZNET_ERROR_GETCFG_SYSTIME                _ZZEC(46)           /// Get Device Time Failed
#define ZZNET_ERROR_GETCFG_PREVIEW                _ZZEC(47)           /// Get Preview Parameters Failed
#define ZZNET_ERROR_GETCFG_AUTOMT                 _ZZEC(48)           /// Get Auto Maintenance Config Failed
#define ZZNET_ERROR_GETCFG_VIDEOMTRX              _ZZEC(49)           /// Get Video Matrix Config Failed
#define ZZNET_ERROR_GETCFG_COVER                  _ZZEC(50)           /// Get Region Mask Config Failed
#define ZZNET_ERROR_GETCFG_WATERMAKE              _ZZEC(51)           /// Get Image Watermark Config Failed
#define ZZNET_ERROR_GETCFG_MULTICAST              _ZZEC(52)           /// Get Config Failed Position: Multicast Port Configured by Channel
#define ZZNET_ERROR_SETCFG_GENERAL                _ZZEC(55)           /// Modify General Attribute Failed
#define ZZNET_ERROR_SETCFG_NETCFG                 _ZZEC(56)           /// Modify Network Config Failed
#define ZZNET_ERROR_SETCFG_CHANNAME               _ZZEC(57)           /// Modify Channel Name Failed
#define ZZNET_ERROR_SETCFG_VIDEO                  _ZZEC(58)           /// Modify Video Attribute Failed
#define ZZNET_ERROR_SETCFG_RECORD                 _ZZEC(59)           /// Modify Record Config Failed
#define ZZNET_ERROR_SETCFG_485DECODER             _ZZEC(60)           /// Modify Decoder Attribute Failed
#define ZZNET_ERROR_SETCFG_232COM                 _ZZEC(61)           /// Modify 232 Serial Port Config Failed
#define ZZNET_ERROR_SETCFG_ALARMIN                _ZZEC(62)           /// Modify External Input Alarm Config Failed
#define ZZNET_ERROR_SETCFG_ALARMDET               _ZZEC(63)           /// Modify Motion Detection Alarm Config Failed
#define ZZNET_ERROR_SETCFG_SYSTIME                _ZZEC(64)           /// Modify Device Time Failed
#define ZZNET_ERROR_SETCFG_PREVIEW                _ZZEC(65)           /// Modify Preview Parameters Failed
#define ZZNET_ERROR_SETCFG_AUTOMT                 _ZZEC(66)           /// Modify Auto Maintenance Config Failed
#define ZZNET_ERROR_SETCFG_VIDEOMTRX              _ZZEC(67)           /// Modify Video Matrix Config Failed
#define ZZNET_ERROR_SETCFG_COVER                  _ZZEC(68)           /// Modify Region Mask Config Failed
#define ZZNET_ERROR_SETCFG_WATERMAKE              _ZZEC(69)           /// Modify Image Watermark Config Failed
#define ZZNET_ERROR_SETCFG_WLAN                   _ZZEC(70)           /// Modify Wireless Network Info Failed
#define ZZNET_ERROR_SETCFG_WLANDEV                _ZZEC(71)           /// Select Wireless Network Device Failed
#define ZZNET_ERROR_SETCFG_REGISTER               _ZZEC(72)           /// Modify Active Registration Parameter Config Failed
#define ZZNET_ERROR_SETCFG_CAMERA                 _ZZEC(73)           /// Modify Camera Attribute Config Failed
#define ZZNET_ERROR_SETCFG_INFRARED               _ZZEC(74)           /// Modify Infrared Alarm Config Failed
#define ZZNET_ERROR_SETCFG_SOUNDALARM             _ZZEC(75)           /// Modify Audio Alarm Config Failed
#define ZZNET_ERROR_SETCFG_STORAGE                _ZZEC(76)           /// Modify Storage Location Config Failed
#define ZZNET_AUDIOENCODE_NOTINIT                 _ZZEC(77)           /// Audio Encode Interface Not Successfully Initialized
#define ZZNET_DATA_TOOLONGH                       _ZZEC(78)           /// Data Too Long
#define ZZNET_UNSUPPORTED                         _ZZEC(79)           /// Device Does Not Support This Operation
#define ZZNET_DEVICE_BUSY                         _ZZEC(80)           /// Device Resource Insufficient
#define ZZNET_SERVER_STARTED                      _ZZEC(81)           /// Server Already Started
#define ZZNET_SERVER_STOPPED                      _ZZEC(82)           /// Server Not Started Successfully Yet
#define ZZNET_LISTER_INCORRECT_SERIAL             _ZZEC(83)           /// Input Serial Number Incorrect
#define ZZNET_QUERY_DISKINFO_FAILED               _ZZEC(84)           /// Get Hard Disk Info Failed
#define ZZNET_ERROR_GETCFG_SESSION                _ZZEC(85)           /// Get Connection Session Info
#define ZZNET_USER_FLASEPWD_TRYTIME               _ZZEC(86)           /// Input Password Error Exceeds Limit
#define ZZNET_LOGIN_ERROR_PASSWORD_EXPIRED        _ZZEC(99)           /// Password Expired
#define ZZNET_LOGIN_ERROR_PASSWORD                _ZZEC(100)          /// Password Incorrect
#define ZZNET_LOGIN_ERROR_USER                    _ZZEC(101)          /// Account Not Exist
#define ZZNET_LOGIN_ERROR_TIMEOUT                 _ZZEC(102)          /// Wait Login Return Timeout
#define ZZNET_LOGIN_ERROR_RELOGGIN                _ZZEC(103)          /// Account Already Logged In
#define ZZNET_LOGIN_ERROR_LOCKED                  _ZZEC(104)          /// Account Locked
#define ZZNET_LOGIN_ERROR_BLACKLIST               _ZZEC(105)          /// Account Blacklisted
#define ZZNET_LOGIN_ERROR_BUSY                    _ZZEC(106)          /// Insufficient Resources, System Busy
#define ZZNET_LOGIN_ERROR_CONNECT                 _ZZEC(107)          /// Network Connection Timeout, Please Check Network and Retry
#define ZZNET_LOGIN_ERROR_NETWORK                 _ZZEC(108)          /// Network Connection Failed
#define ZZNET_LOGIN_ERROR_SUBCONNECT              _ZZEC(109)          /// Login Device Successful, But Cannot Create Video Channel, Please Check Network Status
#define ZZNET_LOGIN_ERROR_MAXCONNECT              _ZZEC(110)          /// Exceeds Max Connection Count
#define ZZNET_LOGIN_ERROR_PROTOCOL3_ONLY          _ZZEC(111)          /// Only Supports Generation 3 Protocol
#define ZZNET_LOGIN_ERROR_UKEY_LOST               _ZZEC(112)          /// U-Key Not Inserted or Info Error
#define ZZNET_LOGIN_ERROR_NO_AUTHORIZED           _ZZEC(113)          /// Client IP Address Has No Login Permission
#define ZZNET_LOGIN_ERROR_USER_OR_PASSOWRD        _ZZEC(117)          /// Account or Password Error
#define ZZNET_LOGIN_ERROR_DEVICE_NOT_INIT		  _ZZEC(118)          /// Device Not Initialized, Cannot Login, Please Initialize Device First
#define ZZNET_LOGIN_ERROR_LIMITED				  _ZZEC(119)          /// Login Restricted, possibly IP restriction, Time period restriction, Validity restriction
#define ZZNET_RENDER_SOUND_ON_ERROR               _ZZEC(120)          /// Render Library Open Audio Error
#define ZZNET_RENDER_SOUND_OFF_ERROR              _ZZEC(121)          /// Render Library Close Audio Error
#define ZZNET_RENDER_SET_VOLUME_ERROR             _ZZEC(122)          /// Render Library Control Volume Error
#define ZZNET_RENDER_ADJUST_ERROR                 _ZZEC(123)          /// Render Library Set Image Parameters Error
#define ZZNET_RENDER_PAUSE_ERROR                  _ZZEC(124)          /// Render Library Pause Playback Error
#define ZZNET_RENDER_SNAP_ERROR                   _ZZEC(125)          /// Render Library Snapshot Error
#define ZZNET_RENDER_STEP_ERROR                   _ZZEC(126)          /// Render Library Step Error
#define ZZNET_RENDER_FRAMERATE_ERROR              _ZZEC(127)          /// Render Library Set Frame Rate Error
#define ZZNET_RENDER_DISPLAYREGION_ERROR          _ZZEC(128)          /// Render Library Set Display Region Error
#define ZZNET_RENDER_GETOSDTIME_ERROR             _ZZEC(129)          /// Render Library Get Current Play Time Error
#define ZZNET_GROUP_EXIST                         _ZZEC(140)          /// Group Name Exists
#define ZZNET_GROUP_NOEXIST                       _ZZEC(141)          /// Group Name Not Exists
#define ZZNET_GROUP_RIGHTOVER                     _ZZEC(142)          /// Group Permissions Exceed Permission List Range
#define ZZNET_GROUP_HAVEUSER                      _ZZEC(143)          /// Group Has Users, Cannot Delete
#define ZZNET_GROUP_RIGHTUSE                      _ZZEC(144)          /// Some Permission of Group In Use by User, Cannot Remove
#define ZZNET_GROUP_SAMENAME                      _ZZEC(145)          /// New Group Name Duplicates Existing Group Name
#define ZZNET_USER_EXIST                          _ZZEC(146)          /// User Exists
#define ZZNET_USER_NOEXIST                        _ZZEC(147)          /// User Not Exists
#define ZZNET_USER_RIGHTOVER                      _ZZEC(148)          /// User Permissions Exceed Group Permissions
#define ZZNET_USER_PWD                            _ZZEC(149)          /// Reserved Account, Cannot Modify Password
#define ZZNET_USER_FLASEPWD                       _ZZEC(150)          /// Password Incorrect
#define ZZNET_USER_NOMATCHING                     _ZZEC(151)          /// Password Mismatch
#define ZZNET_USER_INUSE                          _ZZEC(152)          /// Account In Use
#define ZZNET_ERROR_GETCFG_ETHERNET               _ZZEC(300)          /// Get Network Card Config Failed
#define ZZNET_ERROR_GETCFG_WLAN                   _ZZEC(301)          /// Get Wireless Network Info Failed
#define ZZNET_ERROR_GETCFG_WLANDEV                _ZZEC(302)          /// Get Wireless Network Device Failed
#define ZZNET_ERROR_GETCFG_REGISTER               _ZZEC(303)          /// Get Active Registration Parameters Failed
#define ZZNET_ERROR_GETCFG_CAMERA                 _ZZEC(304)          /// Get Camera Attributes Failed
#define ZZNET_ERROR_GETCFG_INFRARED               _ZZEC(305)          /// Get Infrared Alarm Config Failed
#define ZZNET_ERROR_GETCFG_SOUNDALARM             _ZZEC(306)          /// Get Audio Alarm Config Failed
#define ZZNET_ERROR_GETCFG_STORAGE                _ZZEC(307)          /// Get Storage Location Config Failed
#define ZZNET_ERROR_GETCFG_MAIL                   _ZZEC(308)          /// Get Mail Config Failed
#define ZZNET_CONFIG_DEVBUSY                      _ZZEC(309)          /// Temporarily Cannot Set
#define ZZNET_CONFIG_DATAILLEGAL                  _ZZEC(310)          /// Config Data Illegal
#define ZZNET_ERROR_GETCFG_DST                    _ZZEC(311)          /// Get Daylight Saving Time Config Failed
#define ZZNET_ERROR_SETCFG_DST                    _ZZEC(312)          /// Set Daylight Saving Time Config Failed
#define ZZNET_ERROR_GETCFG_VIDEO_OSD              _ZZEC(313)          /// Get Video OSD Overlay Config Failed
#define ZZNET_ERROR_SETCFG_VIDEO_OSD              _ZZEC(314)          /// Set Video OSD Overlay Config Failed
#define ZZNET_ERROR_GETCFG_GPRSCDMA               _ZZEC(315)          /// Get CDMA\GPRS Network Config Failed
#define ZZNET_ERROR_SETCFG_GPRSCDMA               _ZZEC(316)          /// Set CDMA\GPRS Network Config Failed
#define ZZNET_ERROR_GETCFG_IPFILTER               _ZZEC(317)          /// Get IP Filter Config Failed
#define ZZNET_ERROR_SETCFG_IPFILTER               _ZZEC(318)          /// Set IP Filter Config Failed
#define ZZNET_ERROR_GETCFG_TALKENCODE             _ZZEC(319)          /// Get Voice Talk Encode Config Failed
#define ZZNET_ERROR_SETCFG_TALKENCODE             _ZZEC(320)          /// Set Voice Talk Encode Config Failed
#define ZZNET_ERROR_GETCFG_RECORDLEN              _ZZEC(321)          /// Get Record Packing Length Config Failed
#define ZZNET_ERROR_SETCFG_RECORDLEN              _ZZEC(322)          /// Set Record Packing Length Config Failed
#define ZZNET_DONT_SUPPORT_SUBAREA                _ZZEC(323)          /// Does Not Support Network Hard Disk Partition
#define ZZNET_ERROR_GET_AUTOREGSERVER             _ZZEC(324)          /// Get Active Registration Server Info on Device Failed
#define ZZNET_ERROR_CONTROL_AUTOREGISTER          _ZZEC(325)          /// Active Registration Redirect Register Error
#define ZZNET_ERROR_DISCONNECT_AUTOREGISTER       _ZZEC(326)          /// Disconnect Active Registration Server Error
#define ZZNET_ERROR_GETCFG_MMS                    _ZZEC(327)          /// Get MMS Config Failed
#define ZZNET_ERROR_SETCFG_MMS                    _ZZEC(328)          /// Set MMS Config Failed
#define ZZNET_ERROR_GETCFG_SMSACTIVATION          _ZZEC(329)          /// Get SMS Activation Wireless Connection Config Failed
#define ZZNET_ERROR_SETCFG_SMSACTIVATION          _ZZEC(330)          /// Set SMS Activation Wireless Connection Config Failed
#define ZZNET_ERROR_GETCFG_DIALINACTIVATION       _ZZEC(331)          /// Get Dial-in Activation Wireless Connection Config Failed
#define ZZNET_ERROR_SETCFG_DIALINACTIVATION       _ZZEC(332)          /// Set Dial-in Activation Wireless Connection Config Failed
#define ZZNET_ERROR_GETCFG_VIDEOOUT               _ZZEC(333)          /// Query Video Output Parameter Config Failed
#define ZZNET_ERROR_SETCFG_VIDEOOUT               _ZZEC(334)          /// Set Video Output Parameter Config Failed
#define ZZNET_ERROR_GETCFG_OSDENABLE              _ZZEC(335)          /// Get OSD Overlay Enable Config Failed
#define ZZNET_ERROR_SETCFG_OSDENABLE              _ZZEC(336)          /// Set OSD Overlay Enable Config Failed
#define ZZNET_ERROR_SETCFG_ENCODERINFO            _ZZEC(337)          /// Set Digital Channel Frontend Encoder Access Config Failed
#define ZZNET_ERROR_GETCFG_TVADJUST               _ZZEC(338)          /// Get TV Adjustment Config Failed
#define ZZNET_ERROR_SETCFG_TVADJUST               _ZZEC(339)          /// Set TV Adjustment Config Failed
#define ZZNET_ERROR_CONNECT_FAILED                _ZZEC(340)          /// Request Connection Failed
#define ZZNET_ERROR_SETCFG_BURNFILE               _ZZEC(341)          /// Request Burn File Upload Failed
#define ZZNET_ERROR_SNIFFER_GETCFG                _ZZEC(342)          /// Get Sniffer Config Info Failed
#define ZZNET_ERROR_SNIFFER_SETCFG                _ZZEC(343)          /// Set Sniffer Config Info Failed
#define ZZNET_ERROR_DOWNLOADRATE_GETCFG           _ZZEC(344)          /// Query Download Limit Info Failed
#define ZZNET_ERROR_DOWNLOADRATE_SETCFG           _ZZEC(345)          /// Set Download Limit Info Failed
#define ZZNET_ERROR_SEARCH_TRANSCOM               _ZZEC(346)          /// Query Serial Port Params Failed
#define ZZNET_ERROR_GETCFG_POINT                  _ZZEC(347)          /// Get Preset Point Info Error
#define ZZNET_ERROR_SETCFG_POINT                  _ZZEC(348)          /// Set Preset Point Info Error
#define ZZNET_SDK_LOGOUT_ERROR                    _ZZEC(349)          /// SDK Did Not Logout Device Normally
#define ZZNET_ERROR_GET_VEHICLE_CFG               _ZZEC(350)          /// Get Vehicle Config Failed
#define ZZNET_ERROR_SET_VEHICLE_CFG               _ZZEC(351)          /// Set Vehicle Config Failed
#define ZZNET_ERROR_GET_ATM_OVERLAY_CFG           _ZZEC(352)          /// Get ATM Overlay Config Failed
#define ZZNET_ERROR_SET_ATM_OVERLAY_CFG           _ZZEC(353)          /// Set ATM Overlay Config Failed
#define ZZNET_ERROR_GET_ATM_OVERLAY_ABILITY       _ZZEC(354)          /// Get ATM Overlay Capability Failed
#define ZZNET_ERROR_GET_DECODER_TOUR_CFG          _ZZEC(355)          /// Get Decoder Tour Config Failed
#define ZZNET_ERROR_SET_DECODER_TOUR_CFG          _ZZEC(356)          /// Set Decoder Tour Config Failed
#define ZZNET_ERROR_CTRL_DECODER_TOUR             _ZZEC(357)          /// Control Decoder Tour Failed
#define ZZNET_GROUP_OVERSUPPORTNUM                _ZZEC(358)          /// Exceeds Device Supported Max User Group Count
#define ZZNET_USER_OVERSUPPORTNUM                 _ZZEC(359)          /// Exceeds Device Supported Max User Count
#define ZZNET_ERROR_GET_SIP_CFG                   _ZZEC(368)          /// Get SIP Config Failed
#define ZZNET_ERROR_SET_SIP_CFG                   _ZZEC(369)          /// Set SIP Config Failed
#define ZZNET_ERROR_GET_SIP_ABILITY               _ZZEC(370)          /// Get SIP Capability Failed
#define ZZNET_ERROR_GET_WIFI_AP_CFG               _ZZEC(371)          /// Get WIFI AP Config Failed
#define ZZNET_ERROR_SET_WIFI_AP_CFG               _ZZEC(372)          /// Set WIFI AP Config Failed
#define ZZNET_ERROR_GET_DECODE_POLICY             _ZZEC(373)          /// Get Decode Policy Config Failed
#define ZZNET_ERROR_SET_DECODE_POLICY             _ZZEC(374)          /// Set Decode Policy Config Failed
#define ZZNET_ERROR_TALK_REJECT                   _ZZEC(375)          /// Reject Talk
#define ZZNET_ERROR_TALK_OPENED                   _ZZEC(376)          /// Talk Opened by Other Client
#define ZZNET_ERROR_TALK_RESOURCE_CONFLICIT       _ZZEC(377)          /// Resource Conflict
#define ZZNET_ERROR_TALK_UNSUPPORTED_ENCODE       _ZZEC(378)          /// Unsupported Voice Encode Format
#define ZZNET_ERROR_TALK_RIGHTLESS                _ZZEC(379)          /// No Permission
#define ZZNET_ERROR_TALK_FAILED                   _ZZEC(380)          /// Request Talk Failed
#define ZZNET_ERROR_GET_MACHINE_CFG               _ZZEC(381)          /// Get Machine Related Config Failed
#define ZZNET_ERROR_SET_MACHINE_CFG               _ZZEC(382)          /// Set Machine Related Config Failed
#define ZZNET_ERROR_GET_DATA_FAILED               _ZZEC(383)          /// Device Failed to Get Current Requested Data
#define ZZNET_ERROR_MAC_VALIDATE_FAILED           _ZZEC(384)          /// MAC Address Validation Failed 
#define ZZNET_ERROR_GET_INSTANCE                  _ZZEC(385)          /// Get Server Instance Failed
#define ZZNET_ERROR_JSON_REQUEST                  _ZZEC(386)          /// Generated JSON String Error
#define ZZNET_ERROR_JSON_RESPONSE                 _ZZEC(387)          /// Response JSON String Error
#define ZZNET_ERROR_VERSION_HIGHER                _ZZEC(388)          /// Protocol Version Lower Than Currently Used Version
#define ZZNET_SPARE_NO_CAPACITY                   _ZZEC(389)          /// Hot Spare Operation Failed, Insufficient Capacity
#define ZZNET_ERROR_SOURCE_IN_USE                 _ZZEC(390)          /// Display Source Occupied by Other Output
#define ZZNET_ERROR_REAVE                         _ZZEC(391)          /// High Level User Preempts Low Level User Resource
#define ZZNET_ERROR_NETFORBID                     _ZZEC(392)          /// Network Access Forbidden 
#define ZZNET_ERROR_GETCFG_MACFILTER              _ZZEC(393)          /// Get MAC Filter Config Failed
#define ZZNET_ERROR_SETCFG_MACFILTER              _ZZEC(394)          /// Set MAC Filter Config Failed
#define ZZNET_ERROR_GETCFG_IPMACFILTER            _ZZEC(395)          /// Get IP/MAC Filter Config Failed
#define ZZNET_ERROR_SETCFG_IPMACFILTER            _ZZEC(396)          /// Set IP/MAC Filter Config Failed
#define ZZNET_ERROR_OPERATION_OVERTIME            _ZZEC(397)          /// Current Operation Timeout 
#define ZZNET_ERROR_SENIOR_VALIDATE_FAILED        _ZZEC(398)          /// Senior Validation Failed 
#define ZZNET_ERROR_DEVICE_ID_NOT_EXIST           _ZZEC(399)          /// Device ID Not Exist
#define ZZNET_ERROR_UNSUPPORTED                   _ZZEC(400)          /// Unsupported Current Operation
#define ZZNET_ERROR_PROXY_DLLLOAD                 _ZZEC(401)          /// Proxy DLL Load Failed
#define ZZNET_ERROR_PROXY_ILLEGAL_PARAM           _ZZEC(402)          /// Proxy User Parameter Illegal
#define ZZNET_ERROR_PROXY_INVALID_HANDLE          _ZZEC(403)          /// Proxy Handle Invalid
#define ZZNET_ERROR_PROXY_LOGIN_DEVICE_ERROR      _ZZEC(404)          /// Proxy Login Frontend Device Failed
#define ZZNET_ERROR_PROXY_START_SERVER_ERROR      _ZZEC(405)          /// Start Proxy Server Failed
#define ZZNET_ERROR_SPEAK_FAILED                  _ZZEC(406)          /// Request Broadcast Speak Failed
#define ZZNET_ERROR_NOT_SUPPORT_F6                _ZZEC(407)          /// Device Does Not Support This F6 Interface Call
#define ZZNET_ERROR_CD_UNREADY                    _ZZEC(408)          /// CD Not Ready
#define ZZNET_ERROR_DIR_NOT_EXIST                 _ZZEC(409)          /// Directory Not Exist
#define ZZNET_ERROR_UNSUPPORTED_SPLIT_MODE        _ZZEC(410)          /// Device Unsupported Split Mode
#define ZZNET_ERROR_OPEN_WND_PARAM                _ZZEC(411)          /// Open Window Parameter Illegal
#define ZZNET_ERROR_LIMITED_WND_COUNT             _ZZEC(412)          /// Open Window Count Exceeds Limit
#define ZZNET_ERROR_UNMATCHED_REQUEST             _ZZEC(413)          /// Request Command Mismatch with Current Mode
#define ZZNET_RENDER_ENABLELARGEPICADJUSTMENT_ERROR   _ZZEC(414)      /// Render Library Enable HD Image Internal Adjustment Strategy Error
#define ZZNET_ERROR_UPGRADE_FAILED                _ZZEC(415)          /// Device Upgrade Failed
#define ZZNET_ERROR_NO_TARGET_DEVICE              _ZZEC(416)          /// Cannot Find Target Device
#define ZZNET_ERROR_NO_VERIFY_DEVICE              _ZZEC(417)          /// Cannot Find Verify Device
#define ZZNET_ERROR_CASCADE_RIGHTLESS             _ZZEC(418)          /// No Cascade Permission
#define ZZNET_ERROR_LOW_PRIORITY                  _ZZEC(419)          /// Low Priority
#define ZZNET_ERROR_REMOTE_REQUEST_TIMEOUT        _ZZEC(420)          /// Remote Device Request Timeout
#define ZZNET_ERROR_LIMITED_INPUT_SOURCE          _ZZEC(421)          /// Input Source Exceeds Max Channel Limit
#define ZZNET_ERROR_SET_LOG_PRINT_INFO            _ZZEC(422)          /// Set Log Print Failed
#define ZZNET_ERROR_PARAM_DWSIZE_ERROR            _ZZEC(423)          /// Input Parameter dwsize Field Error
#define ZZNET_ERROR_LIMITED_MONITORWALL_COUNT     _ZZEC(424)          /// Monitor Wall Count Exceeds Limit
#define ZZNET_ERROR_PART_PROCESS_FAILED           _ZZEC(425)          /// Partial Process Execution Failed
#define ZZNET_ERROR_TARGET_NOT_SUPPORT            _ZZEC(426)          /// This Function Does Not Support Forwarding
#define ZZNET_ERROR_VISITE_FILE                   _ZZEC(510)          /// Visit File Failed
#define ZZNET_ERROR_DEVICE_STATUS_BUSY            _ZZEC(511)          /// Device Busy
#define ZZNET_USER_PWD_NOT_AUTHORIZED             _ZZEC(512)          /// Modify Password No Permission
#define ZZNET_USER_PWD_NOT_STRONG                 _ZZEC(513)          /// Password Strength Insufficient
#define ZZNET_ERROR_NO_SUCH_CONFIG                _ZZEC(514)          /// No Corresponding Config
#define ZZNET_ERROR_AUDIO_RECORD_FAILED           _ZZEC(515)          /// Audio Record Failed
#define ZZNET_ERROR_SEND_DATA_FAILED              _ZZEC(516)          /// Data Send Failed
#define ZZNET_ERROR_OBSOLESCENT_INTERFACE         _ZZEC(517)          /// Obsolete Interface
#define ZZNET_ERROR_INSUFFICIENT_INTERAL_BUF      _ZZEC(518)          /// Internal Buffer Insufficient
#define ZZNET_ERROR_NEED_ENCRYPTION_PASSWORD      _ZZEC(519)          /// Need to Verify Password When Modifying Device IP
#define ZZNET_ERROR_NOSUPPORT_RECORD              _ZZEC(520)          /// Device Does Not Support This Record Set
#define ZZNET_ERROR_DEVICE_IN_UPGRADING           _ZZEC(521)          /// Device Is Upgrading
#define ZZNET_ERROR_ANALYSE_TASK_NOT_EXIST        _ZZEC(522)          /// Intelligent Analysis Task Not Exist
#define ZZNET_ERROR_ANALYSE_TASK_FULL             _ZZEC(523)          /// Intelligent Analysis Task Full
#define ZZNET_ERROR_DEVICE_RESTART                _ZZEC(524)          /// Device Restart
#define ZZNET_ERROR_DEVICE_SHUTDOWN				  _ZZEC(525)          /// Device Shutdown
#define ZZNET_ERROR_FILE_SYSTEM_ERROR             _ZZEC(526)          /// File System Error
#define ZZNET_ERROR_HARDDISK_WRITE_ERROR          _ZZEC(527)          /// Hard Disk Write Error
#define ZZNET_ERROR_HARDDISK_READ_ERROR           _ZZEC(528)          /// Hard Disk Read Error
#define ZZNET_ERROR_NO_HARDDISK_RECORD_LOG        _ZZEC(529)          /// No Hard Disk Record Log
#define ZZNET_ERROR_NO_HARDDISK		              _ZZEC(530)          /// No Working Disk (No Read/Write Disk)
#define ZZNET_ERROR_HARDDISK_OTHER_ERRORS         _ZZEC(531)          /// Hard Disk Other Errors
#define ZZNET_ERROR_HARDDISK_BADSECTORS_MINOR_ERRORS				_ZZEC(532)          /// Hard Disk Bad Sectors Minor Errors
#define ZZNET_ERROR_HARDDISK_BADSECTORS_CRITICAL_ERRORS             _ZZEC(533)          /// Hard Disk Bad Sectors Critical Errors
#define ZZNET_ERROR_HARDDISK_PHYSICAL_BADSECTORS_SLIGHT             _ZZEC(534)          /// Hard Disk Physical Bad Sectors Slight
#define ZZNET_ERROR_HARDDISK_PHYSICAL_BADSECTORS_SERIOUS            _ZZEC(535)          /// Hard Disk Physical Bad Sectors Serious
#define ZZNET_ERROR_NETWORK_DISCONNECTION_ALARM					    _ZZEC(536)          /// Network Disconnection Alarm
#define ZZNET_ERROR_NETWORK_DISCONNECTION							_ZZEC(537)          /// Network Disconnected
#define ZZNET_ERROR_SET_SOURCE_EXCEED			    _ZZEC(538)          /// Set Video Source Count Exceeds Limit
#define ZZNET_ERROR_SIZE_EXCEED			            _ZZEC(539)          /// Upload File Size Exceeds Range (uploadFile method)
#define ZZNET_ERROR_LOGOPEN_DISABLE                 _ZZEC(540)          /// Log config file exists, based on log print config file, log print interface disabled
#define ZZNET_ERROR_STREAM_PACKAGE_ERROR            _ZZEC(541)          /// Packaging Audio Header Failed

#define ZZNET_ERROR_READ_LIMIT                _ZZEC(542)          /// Disk Read Data Limit
#define ZZNET_ERROR_PREVIEWOPENED             _ZZEC(543)          /// Multi-play preview already opened, insufficient resources, compression playback failed
#define ZZNET_ERROR_COMPRESSOPENED            _ZZEC(544)          /// Compression playback function already opened, causing failure 
#define ZZNET_ERROR_COMPRESSERROR_UNKNOWN     _ZZEC(545)          /// Unknown compression failure cause
#define ZZNET_ERROR_COMPRESSERROR_OVERDECODE  _ZZEC(546)          /// Exceeds decoding capability, causing compression failure
#define ZZNET_ERROR_COMPRESSERROR_OVERENCODE  _ZZEC(547)          /// Exceeds compression capability, causing compression failure
#define ZZNET_ERROR_COMPRESSERROR_NONESTREAM  _ZZEC(548)          /// No original stream, causing compression failure
#define ZZNET_ERROR_COMPRESSERROR_CHIPOFFLINE _ZZEC(549)          /// Slave chip where compression channel is located is offline, causing compression failure
#define ZZNET_ERROR_CHANNELNOTADD             _ZZEC(550)          /// Channel not added
#define ZZNET_ERROR_ENCODER_COVER_CAPS		  _ZZEC(551)			/// Exceeds device encoding capability
#define ZZNET_ERROR_DEVICE_NOT_EXIST		  _ZZEC(552)			/// System device does not exist
#define ZZNET_ERROR_IPSPEAKER_BROADCAST_PARTIALFAILED				            _ZZEC(553)			/// IPSpeaker broadcast speak failed on some channels
#define ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_GROUP_COUNT_EXCEED					_ZZEC(601)	/// Tip image library reached max count
#define ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_GROUP_NAME_EXISTED					_ZZEC(602)	/// Tip library name already exists
#define ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_UNKNOW								_ZZEC(603)	/// Unknown reason
#define ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_SCHEME_OR_GROUP_IMPORT_OR_EXPORT	_ZZEC(604)	/// Tip scheme or image library is importing or exporting
#define ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_NAME_EMPTY							_ZZEC(605)	/// Image library name cannot be empty
#define ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_GROUP_NOT_EXIST					_ZZEC(606)	/// Image library does not exist
#define ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_FORMAT_ERROR						_ZZEC(607)	/// Tip image format error
#define ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_TIP_NOT_EXIST						_ZZEC(608)	/// Tip does not exist
#define ZZNET_ERRPR_XRAY_TIP_PICTURE_MANAGER_DELETE_TIP_ERROR					_ZZEC(609)	/// Delete tip file error

#define ZZNET_ERRPR_XRAY_TIP_SCHEME_MAX_COUNT									_ZZEC(701)	/// Tip scheme count reached max value
#define ZZNET_ERRPR_XRAY_TIP_SCHEME_NAME_REPEAT									_ZZEC(702)	/// Tip scheme name repeated
#define ZZNET_ERRPR_XRAY_TIP_SCHEME_NOEXIST										_ZZEC(703)	/// Tip scheme does not exist
#define ZZNET_ERRPR_XRAY_TIP_SCHEME_UNKNOW										_ZZEC(704)	/// Unknown reason
#define ZZNET_ERRPR_XRAY_TIP_SCHEME_GROUP_NO_EXIST								_ZZEC(705)	/// Image library does not exist
#define ZZNET_ERRPR_XRAY_TIP_SCHEME_GROUP_MAX_COUNT								_ZZEC(706)	/// Scheme image library count reached max value
#define ZZNET_ERRPR_XRAY_TIP_SCHEME_PICTURE_NO_EXIST							_ZZEC(707)	/// Image does not exist
#define ZZNET_ERRPR_XRAY_TIP_SCHEME_NAME_EMPTY									_ZZEC(708)	/// Tip scheme name cannot be empty
#define ZZNET_ERRPR_XRAY_TIP_SCHEME_GROUP_EXISTED								_ZZEC(709)	/// Tip scheme library already exists
#define ZZNET_ERRPR_XRAY_TIP_SCHEME_TIP_GROUP_REPEAT							_ZZEC(710)	/// Image library in tip scheme repeated
#define ZZNET_ERRPR_XRAY_TIP_SCHEME_GROUP_NO_EXISTED							_ZZEC(711)	/// Tip scheme library does not exist
#define ZZNET_ERRPR_XRAY_TIP_SCHEME_GROUP_IMPORT_OR_EXPORT						_ZZEC(712)	/// Tip scheme or image library is importing or exporting

#define	NET_ERROR_FACE_RECOGNITION_SERVER_DELETE_GROUP_ERROR                _ZZEC(900)			/// Delete Target Library Failed
#define	NET_ERROR_FACE_RECOGNITION_SERVER_NAME_FORMAT_ERROR                 _ZZEC(901)			/// Naming Format Error
#define	NET_ERROR_FACE_RECOGNITION_SERVER_FILEPATH_NOT_SET                  _ZZEC(902)			/// Image Save Path Not Set
#define	NET_ERROR_FACE_RECOGNITION_SERVER_AREAS_NAME_REPEAT					_ZZEC(903)			/// Add Area Name Repeated
#define	NET_ERROR_FACE_RECOGNITION_SERVER_AREAS_ID_REPEAT					_ZZEC(904)           	/// Add Area ID Repeated
#define	NET_ERROR_FACE_RECOGNITION_SERVER_AREAS_CHANNEL_REPEAT				_ZZEC(905)           	/// Add Area Channel Repeated
#define	NET_ERROR_FACE_RECOGNITION_SERVER_EXPORT_TASK_COUNT_EXCEED			_ZZEC(906)           	/// Export Task Exceeds Limit
#define	NET_ERROR_FACE_RECOGNITION_SERVER_PIC_SEARCH_NOT_SUPPORT			_ZZEC(907)           	/// Device Does Not Support Image Search
#define	NET_ERROR_FACE_RECOGNITION_SERVER_DETECT_MULTI_FACE_NOT_SUPPORT		_ZZEC(908)           	/// Device Does Not Support Detecting Specific Target from Large Image
#define	NET_ERROR_FACE_RECOGNITION_SERVER_PERSON_ALREADY_EXISTS				_ZZEC(909)			/// Person Already Exists
#define ZZNET_ERROR_FACE_RECOGNITION_SERVER_COMPONENT_NOT_INIT_COMPLETED    _ZZEC(910)            /// Component Not Initialization Completed

#define ZZNET_ERROR_EXP_REGISTRY_GROUP_ID_EXCEED                              _ZZEC(911)            /// Group ID Exceeds Max Value
#define ZZNET_ERROR_EXP_REGISTRY_ABSTRACT_INIT_ERROR                          _ZZEC(912)            /// Modeling Analyzer Start Failed
#define ZZNET_ERROR_EXP_REGISTRY_GROUP_ID_NOT_FOUND                           _ZZEC(913)            /// ID Not Found or Empty
#define ZZNET_ERROR_EXP_REGISTRY_DATABASE_ERROR                               _ZZEC(914)            /// Database Operation Failed (Refers to database operation)
#define ZZNET_ERROR_EXP_REGISTRY_TOKEN_ERROR                                  _ZZEC(915)            /// Token Not Found or Empty
#define ZZNET_ERROR_EXP_REGISTRY_BEGIN_NUM_OVER_RUN                           _ZZEC(916)            /// Query Start Number Greater Than Total
#define ZZNET_ERROR_EXP_REGISTRY_ABSTRACT_STATE                               _ZZEC(917)            /// Device is Modeling
#define ZZNET_ERROR_EXP_REGISTRY_BIG_PIC_MAX_NUM                              _ZZEC(918)            /// Single Import Panorama Image Count Exceeds Limit
#define ZZNET_ERROR_EXP_REGISTRY_OBJECT_MAX_NUM                               _ZZEC(919)            /// Feature Count Exceeds Limit
#define ZZNET_ERROR_EXP_REGISTRY_GROUP_SPACE_EXCEED                           _ZZEC(920)            /// Exceeds Experience Library Space Limit
#define ZZNET_ERROR_EXP_REGISTRY_GROUP_NAME_EXIST                             _ZZEC(921)            /// Library Name Already Exists
#define ZZNET_ERROR_EXP_REGISTRY_INVALID_PARAM                                _ZZEC(922)            /// Invalid Parameter
#define ZZNET_ERROR_EXP_REGISTRY_UNKNOWN_ERROR                                _ZZEC(923)            /// Unknown Error
#define ZZNET_ERROR_EXP_REGISTRY_ATTACH_NUM_EXCEED                            _ZZEC(924)            /// Exceeds Max Subscription Count
#define ZZNET_ERROR_EXP_REGISTRY_FILE_IOE_ERROR                               _ZZEC(925)            /// File Operation Failed
#define ZZNET_ERROR_EXP_REGISTRY_FILE_NOT_EXIST                               _ZZEC(926)            /// File Not Exist
#define ZZNET_ERROR_EXP_REGISTRY_ABSTRACT_NUM_ZERO                            _ZZEC(927)            /// Number to Manually Model is 0
#define ZZNET_ERROR_EXP_REGISTRY_GROUP_LINKED                                 _ZZEC(928)            /// Library Already Linked
#define ZZNET_ERROR_EXP_REGISTRY_OTHER_TYPE_DEPLOYED                          _ZZEC(929)            /// Other Type of Base Library Already Deployed

#define ZZNET_ERROR_SERIALIZE_ERROR               _ZZEC(1010)         /// Data Serialization Error
#define ZZNET_ERROR_DESERIALIZE_ERROR             _ZZEC(1011)         /// Data Deserialization Error
#define ZZNET_ERROR_LOWRATEWPAN_ID_EXISTED        _ZZEC(1012)         /// Wireless ID Already Exists
#define ZZNET_ERROR_LOWRATEWPAN_ID_LIMIT          _ZZEC(1013)         /// Wireless ID Count Limit Exceeded
#define ZZNET_ERROR_LOWRATEWPAN_ID_ABNORMAL       _ZZEC(1014)         /// Wireless Abnormal Add
#define ZZNET_ERROR_ENCRYPT                       _ZZEC(1015)         /// Encrypt Data Failed
#define ZZNET_ERROR_PWD_ILLEGAL                   _ZZEC(1016)         /// New Password Not Standard
#define ZZNET_ERROR_DEVICE_ALREADY_INIT           _ZZEC(1017)         /// Device Already Initialized
#define ZZNET_ERROR_SECURITY_CODE                 _ZZEC(1018)         /// Security Code Error
#define ZZNET_ERROR_SECURITY_CODE_TIMEOUT         _ZZEC(1019)         /// Security Code Validity Expired
#define ZZNET_ERROR_GET_PWD_SPECI                 _ZZEC(1020)         /// Get Password Spec Failed
#define ZZNET_ERROR_NO_AUTHORITY_OF_OPERATION     _ZZEC(1021)         /// No Authority to Perform This Operation
#define ZZNET_ERROR_DECRYPT                       _ZZEC(1022)         /// Decrypt Data Failed
#define ZZNET_ERROR_2D_CODE                       _ZZEC(1023)         /// 2D code Validation Failed
#define ZZNET_ERROR_INVALID_REQUEST               _ZZEC(1024)         /// Illegal RPC Request
#define	ZZNET_ERROR_PWD_RESET_DISABLE			  _ZZEC(1025)		    /// Password Reset Function Disabled
#define ZZNET_ERROR_PLAY_PRIVATE_DATA             _ZZEC(1026)         /// Display Private Data (e.g., Rule Box) Failed
#define ZZNET_ERROR_ROBOT_OPERATE_FAILED          _ZZEC(1027)         /// Robot Operation Failed
#define ZZNET_ERROR_PHOTOSIZE_EXCEEDSLIMIT        _ZZEC(1028)         /// Photo Size Exceeds Limit
#define ZZNET_ERROR_USERID_INVALID                _ZZEC(1029)         /// User ID Not Exist
#define ZZNET_ERROR_EXTRACTFEATURE_FAILED         _ZZEC(1030)         /// Photo Feature Extraction Failed
#define ZZNET_ERROR_PHOTO_EXIST                   _ZZEC(1031)         /// Photo Already Exists
#define ZZNET_ERROR_PHOTO_OVERFLOW                _ZZEC(1032)         /// Photo Count Exceeds Limit
#define ZZNET_ERROR_CHANNEL_ALREADY_OPENED		  _ZZEC(1033)		    /// Channel Already Opened
#define ZZNET_ERROR_CREATE_SOCKET				  _ZZEC(1034)		    /// Create Socket Failed
#define ZZNET_ERROR_CHANNEL_NUM					  _ZZEC(1035)		    /// Channel Number Error
#define ZZNET_ERROR_PHOTO_FORMAT				  _ZZEC(1036)		    /// Photo Format Error
#define ZZNET_ERROR_DIGITAL_CERTIFICATE_INTERNAL_ERROR				_ZZEC(1037)		  /// Internal Error (e.g., Hardware issue, Get Public Key Failed, Internal Interface Call Failed, Write File Failed, etc.)
#define ZZNET_ERROR_DIGITAL_CERTIFICATE_GET_ID_FAILED				_ZZEC(1038)		  /// Get Device ID Failed
#define ZZNET_ERROR_DIGITAL_CERTIFICATE_IMPORT_ILLEGAL				_ZZEC(1039)		  /// Certificate File Illegal (Format not supported or not a certificate file)
#define ZZNET_ERROR_DIGITAL_CERTIFICATE_SN_ERROR					_ZZEC(1040)		  /// Certificate SN repeated or error or non-standard
#define ZZNET_ERROR_DIGITAL_CERTIFICATE_COMMON_NAME_ILLEGAL            _ZZEC(1041)      /// Certificate common name is invalid (Mismatch between local device certificate and system devid_cryptoID, or the remote end does not comply with the rules (devid_cryptoID)).
#define ZZNET_ERROR_DIGITAL_CERTIFICATE_NO_ROOT_CERT                   _ZZEC(1042)      /// Root certificate not imported or does not exist.
#define ZZNET_ERROR_DIGITAL_CERTIFICATE_CERT_REVOKED                   _ZZEC(1043)      /// Certificate has been revoked.
#define ZZNET_ERROR_DIGITAL_CERTIFICATE_CERT_INVALID                   _ZZEC(1044)      /// Certificate is unavailable, not yet valid, or has expired.
#define ZZNET_ERROR_DIGITAL_CERTIFICATE_CERT_ERROR_SIGN                _ZZEC(1045)      /// Certificate signature mismatch.
#define ZZNET_ERROR_DIGITAL_CERTIFICATE_COUNTS_UPPER_LIMIT             _ZZEC(1046)      /// Exceeds the upper limit for certificate imports.
#define ZZNET_ERROR_DIGITAL_CERTIFICATE_CERT_NO_EXIST                  _ZZEC(1047)      /// Certificate file does not exist (when exporting certificate or retrieving public key of the corresponding certificate).
#define ZZNET_ERROR_DEFULAT_SEARCH_PORT                                _ZZEC(1048)      /// Default search ports cannot be used (5050, 37810).
#define NET_ERROR_FACE_RECOGNITION_SERVER_MULTI_APPEND_STOUP               _ZZEC(1049)        /// Batch addition of targets stopped.
#define NET_ERROR_FACE_RECOGNITION_SERVER_MULTI_APPEND_ERROR               _ZZEC(1050)        /// Failed to batch add targets.
#define NET_ERROR_FACE_RECOGNITION_SERVER_GROUP_ID_EXCEED                   _ZZEC(1051)        /// Group ID exceeds maximum value.
#define NET_ERROR_FACE_RECOGNITION_SERVER_GROUP_ID_NOT_IN_REGISTER_GROUP   _ZZEC(1052)        /// Group ID does not exist or is empty.
#define NET_ERROR_FACE_RECOGNITION_SERVER_PICTURE_NOT_FOUND                 _ZZEC(1053)        /// No picture data available.
#define NET_ERROR_FACE_RECOGNITION_SERVER_GENERATE_GROUP_ID_FAILED         _ZZEC(1054)        /// Failed to generate group ID, out of range.
#define NET_ERROR_FACE_RECOGNITION_SERVER_SET_CONFIG_FAILED                 _ZZEC(1055)        /// Failed to set configuration.
#define NET_ERROR_FACE_RECOGNITION_SERVER_FILE_OPEN_FAILED                 _ZZEC(1056)        /// Failed to open picture file.
#define NET_ERROR_FACE_RECOGNITION_SERVER_FILE_READ_FAILED                  _ZZEC(1057)        /// Failed to read picture file.
#define NET_ERROR_FACE_RECOGNITION_SERVER_FILE_WRITE_FAILED                 _ZZEC(1058)        /// Failed to write picture file.
#define NET_ERROR_FACE_RECOGNITION_SERVER_PICTURE_DPI_ERROR                 _ZZEC(1059)        /// Picture DPI is abnormal.
#define NET_ERROR_FACE_RECOGNITION_SERVER_PICTURE_PX_ERROR                  _ZZEC(1060)        /// Picture pixels are abnormal.
#define NET_ERROR_FACE_RECOGNITION_SERVER_PICTURE_SIZE_ERROR               _ZZEC(1061)        /// Picture size is incorrect.
#define NET_ERROR_FACE_RECOGNITION_SERVER_DATA_BASE_ERROR                  _ZZEC(1062)        /// Database operation failed.
#define NET_ERROR_FACE_RECOGNITION_SERVER_FACE_MAX_NUM                     _ZZEC(1063)        /// Number of persons exceeds limit.
#define NET_ERROR_FACE_RECOGNITION_SERVER_BIRTH_DAY_FORMAT_ERROR            _ZZEC(1064)        /// Date of birth format is incorrect.
#define NET_ERROR_FACE_RECOGNITION_SERVER_UID_ERROR                         _ZZEC(1065)        /// Person UID does not exist or is empty.
#define NET_ERROR_FACE_RECOGNITION_SERVER_TOKEN_ERROR                       _ZZEC(1066)        /// Token does not exist or is empty.
#define NET_ERROR_FACE_RECOGNITION_SERVER_BEGIN_NUM_OVER_RUN                _ZZEC(1067)        /// Query start number is greater than total count.
#define NET_ERROR_FACE_RECOGNITION_SERVER_ABSTRACT_NUM_ZERO                 _ZZEC(1068)        /// Number of faces requiring manual modeling is zero.
#define NET_ERROR_FACE_RECOGNITION_SERVER_ABSTRACT_INIT_ERROR              _ZZEC(1069)        /// Failed to start modeling analyzer.
#define NET_ERROR_FACE_RECOGNITION_SERVER_AUTO_ABSTRACT_STATE              _ZZEC(1070)        /// Device is in automatic modeling.
#define NET_ERROR_FACE_RECOGNITION_SERVER_ABSTRACT_STATE                   _ZZEC(1071)        /// Device is in manual modeling.
#define NET_ERROR_FACE_RECOGNITION_SERVER_IM_EX_STATE                      _ZZEC(1072)        /// Device is importing or exporting.
#define NET_ERROR_FACE_RECOGNITION_SERVER_PIC_WRITE_FAILED                 _ZZEC(1073)        /// Failed to write picture.
#define NET_ERROR_FACE_RECOGNITION_SERVER_GROUP_SPACE_EXCEED               _ZZEC(1074)        /// Exceeds target library space limit.
#define NET_ERROR_FACE_RECOGNITION_SERVER_GROUP_PIC_COUNT_EXCEED           _ZZEC(1075)        /// Exceeds target library picture count limit.
#define NET_ERROR_FACE_RECOGNITION_SERVER_GROUP_NOT_FOUND                  _ZZEC(1076)        /// Target group not found.
#define NET_ERROR_FACE_RECOGNITION_SERVER_FIND_RECORDS_ERROR               _ZZEC(1077)        /// Query for original target library data returned invalid results.
#define NET_ERROR_FACE_RECOGNITION_SERVER_DELETE_PERSON_ERROR              _ZZEC(1078)        /// Failed to delete data from original target library.

#define ZZNET_ERROR_DEVICE_PARSE_PROTOCOL              _ZZEC(1079)      /// Device protocol parsing error.
#define ZZNET_ERROR_DEVICE_INVALID_REQUEST             _ZZEC(1080)      /// Device returned invalid request.
#define ZZNET_ERROR_DEVICE_INTERNAL_ERROR              _ZZEC(1081)      /// Device internal error.
#define ZZNET_ERROR_DEVICE_REQUEST_TIMEOUT             _ZZEC(1082)      /// Device internal request timeout.
#define ZZNET_ERROR_DEVICE_KEEPALIVE_FAIL              _ZZEC(1083)      /// Device keep-alive failed.
#define ZZNET_ERROR_DEVICE_NETWORK_ERROR               _ZZEC(1084)      /// Device network error.
#define ZZNET_ERROR_DEVICE_UNKNOWN_ERROR               _ZZEC(1085)      /// Device internal unknown error.
#define ZZNET_ERROR_DEVICE_COM_INTERFACE_NOTFOUND      _ZZEC(1086)      /// Device component interface not found.
#define ZZNET_ERROR_DEVICE_COM_IMPLEMENT_NOTFOUND      _ZZEC(1087)      /// Device component implementation not found.
#define ZZNET_ERROR_DEVICE_COM_NOTFOUND                _ZZEC(1088)      /// Device access component not found.
#define ZZNET_ERROR_DEVICE_COM_INSTANCE_NOTEXIST       _ZZEC(1089)      /// Device access component instance does not exist.
#define ZZNET_ERROR_DEVICE_CREATE_COM_FAIL             _ZZEC(1090)      /// Device component factory failed to create component.
#define ZZNET_ERROR_DEVICE_GET_COM_FAIL                _ZZEC(1091)      /// Device component factory failed to retrieve component instance.
#define ZZNET_ERROR_DEVICE_BAD_REQUEST                 _ZZEC(1092)      /// Device service request rejected.
#define ZZNET_ERROR_DEVICE_REQUEST_IN_PROGRESS         _ZZEC(1093)      /// Device is already processing the request, duplicate requests not accepted.
#define ZZNET_ERROR_DEVICE_LIMITED_RESOURCE            _ZZEC(1094)      /// Device resource insufficient.
#define ZZNET_ERROR_DEVICE_BUSINESS_TIMEOUT            _ZZEC(1095)      /// Device service timeout.
#define ZZNET_ERROR_DEVICE_TOO_MANY_REQUESTS           _ZZEC(1096)      /// Device received too many requests.
#define ZZNET_ERROR_DEVICE_NOT_ALREADY                 _ZZEC(1097)      /// Device not ready, service requests not accepted.
#define ZZNET_ERROR_DEVICE_SEARCHRECORD_TIMEOUT        _ZZEC(1098)      /// Device video search timeout.
#define ZZNET_ERROR_DEVICE_SEARCHTIME_INVALID          _ZZEC(1099)      /// Device video search time is invalid.
#define ZZNET_ERROR_DEVICE_SSID_INVALID                _ZZEC(1100)      /// Device SSID validation failed.
#define ZZNET_ERROR_DEVICE_CHANNEL_STREAMTYPE_ERROR          _ZZEC(1101)    /// Device channel number or stream type validation failed.
#define ZZNET_ERROR_DEVICE_STREAM_PACKINGFORMAT_UNSUPPORT _ZZEC(1102)    /// Device does not support this stream packing format.
#define ZZNET_ERROR_DEVICE_AUDIO_ENCODINGFORMAT_UNSUPPORT _ZZEC(1103)    /// Device does not support this audio encoding format.
#define ZZNET_ERROR_SECURITY_ERROR_SUPPORT_GUI             _ZZEC(1104)    /// Security code verification failed. Password can be reset via local GUI.
#define ZZNET_ERROR_SECURITY_ERROR_SUPPORT_MULT             _ZZEC(1105)    /// Security code verification failed. Password can be reset via APP or ConfigTool.
#define ZZNET_ERROR_SECURITY_ERROR_SUPPORT_UNIQUE           _ZZEC(1106)    /// Security code verification failed. Password can be reset by logging into the Web page.
#define ZZNET_ERROR_STREAMCONVERTOR_DEFECT                  _ZZEC(1107)    /// Transcode library is missing.

#define ZZNET_ERROR_SECURITY_GENERATE_SAFE_CODE            _ZZEC(1108)      /// Failed to generate security code using encryption library.
#define ZZNET_ERROR_SECURITY_GET_CONTACT                   _ZZEC(1109)      /// Failed to retrieve contact information.
#define ZZNET_ERROR_SECURITY_GET_QRCODE                    _ZZEC(1110)      /// Failed to retrieve QR code information for password reset.
#define ZZNET_ERROR_SECURITY_CANNOT_RESET                  _ZZEC(1111)      /// Device not initialized, cannot reset.
#define ZZNET_ERROR_SECURITY_NOT_SUPPORT_CONTACT_MODE      _ZZEC(1112)      /// Does not support setting this contact method (e.g., trying to set email when only phone number is supported).
#define ZZNET_ERROR_SECURITY_RESPONSE_TIMEOUT              _ZZEC(1113)      /// Remote end response timeout.
#define ZZNET_ERROR_SECURITY_AUTHCODE_FORBIDDEN            _ZZEC(1114)      /// Too many failed AuthCode verification attempts. Verification forbidden.
#define ZZNET_ERROR_TRANCODE_LOGIN_REMOTE_DEV              _ZZEC(1115)        /// (Virtual Transcode) Failed to log in to remote device.
#define NET_ERROR_TRANCODE_NOFREE_CHANNEL                   _ZZEC(1116)        /// (Virtual Transcode) No available channel resources.
#define ZZNET_ERROR_VK_INFO_DECRYPT_FAILED                 _ZZEC(1117)        /// VK information decryption failed.
#define ZZNET_ERROR_VK_INFO_DESERIALIZE_FAILED             _ZZEC(1118)        /// VK information deserialization failed.
#define ZZNET_ERROR_GDPR_ABILITY_NOT_ENABLE                _ZZEC(1119)        /// SDK GDPR feature not enabled.

/*Access Control Quick Import and Verification Error Codes Start*/
#define ZZNET_ERROR_FAST_CHECK_NO_AUTH                     _ZZEC(1120)    /// Access Control Quick Verification: No permission.
#define ZZNET_ERROR_FAST_CHECK_NO_FILE                     _ZZEC(1121)    /// Access Control Quick Verification: File not found.
#define ZZNET_ERROR_FAST_CHECK_FILE_FAIL                   _ZZEC(1122)    /// Access Control Quick Verification: File preparation failed.
#define ZZNET_ERROR_FAST_CHECK_BUSY                        _ZZEC(1123)    /// Access Control Quick Verification: System is busy.
#define ZZNET_ERROR_FAST_CHECK_NO_PASSWORD                 _ZZEC(1124)    /// Access Control Quick Verification: No password defined, export not allowed.
#define ZZNET_ERROR_IMPORT_ACCESS_SEND_FAILD               _ZZEC(1125)    /// Access Control Quick Import: Failed to send access control data.
#define ZZNET_ERROR_IMPORT_ACCESS_BUSY                     _ZZEC(1126)    /// Access Control Quick Import: System is busy, import task already in progress.
#define ZZNET_ERROR_IMPORT_ACCESS_DATAERROR                _ZZEC(1127)    /// Access Control Quick Import: Data packet verification failed.
#define ZZNET_ERROR_IMPORT_ACCESS_DATAINVALID              _ZZEC(1128)    /// Access Control Quick Import: Data packet is invalid.
#define ZZNET_ERROR_IMPORT_ACCESS_SYNC_FALID               _ZZEC(1129)    /// Access Control Quick Import: Synchronization failed, database cannot be generated.
#define ZZNET_ERROR_IMPORT_ACCESS_DBFULL                   _ZZEC(1130)    /// Access Control Quick Import: Database is full, cannot import.
#define ZZNET_ERROR_IMPORT_ACCESS_SDFULL                   _ZZEC(1131)    /// Access Control Quick Import: Storage space is full, cannot import.
#define ZZNET_ERROR_IMPORT_ACCESS_CIPHER_ERROR             _ZZEC(1132)    /// Access Control Quick Import: Incorrect password for import package.
/*Access Control Quick Import and Verification Error Codes End*/

#define ZZNET_ERROR_INVALID_PARAM                          _ZZEC(1133)    /// Invalid parameter.
#define ZZNET_ERROR_INVALID_PASSWORD                       _ZZEC(1134)    /// Invalid password.
#define ZZNET_ERROR_INVALID_FINGERPRINT                    _ZZEC(1135)    /// Invalid fingerprint data.
#define ZZNET_ERROR_INVALID_FACE                           _ZZEC(1136)    /// Invalid face template.
#define ZZNET_ERROR_INVALID_CARD                           _ZZEC(1137)    /// Invalid card.
#define ZZNET_ERROR_INVALID_USER                           _ZZEC(1138)    /// Invalid user.
#define ZZNET_ERROR_GET_SUBSERVICE                         _ZZEC(1139)    /// Failed to retrieve capability set sub-service.
#define ZZNET_ERROR_GET_METHOD                             _ZZEC(1140)      /// Failed to retrieve component method set.
#define ZZNET_ERROR_GET_SUBCAPS                            _ZZEC(1141)      /// Failed to retrieve resource entity capability set.
#define ZZNET_ERROR_UPTO_INSERT_LIMIT                      _ZZEC(1142)      /// Insert limit reached.
#define ZZNET_ERROR_UPTO_MAX_INSERT_RATE                   _ZZEC(1143)      /// Maximum insert rate reached.
#define ZZNET_ERROR_ERASE_FINGERPRINT                      _ZZEC(1144)      /// Failed to clear fingerprint data.
#define ZZNET_ERROR_ERASE_FACE                             _ZZEC(1145)      /// Failed to clear face data.
#define ZZNET_ERROR_ERASE_CARD                             _ZZEC(1146)      /// Failed to clear card data.
#define ZZNET_ERROR_NO_RECORD                              _ZZEC(1147)      /// No record found.
#define ZZNET_ERROR_NOMORE_RECORDS                         _ZZEC(1148)      /// End of records, no more records to find.
#define ZZNET_ERROR_RECORD_ALREADY_EXISTS                  _ZZEC(1149)      /// Data duplication when issuing card or fingerprint.
#define ZZNET_ERROR_EXCEED_MAX_FINGERPRINT_PERUSER         _ZZEC(1150)      /// Exceeds maximum number of fingerprints per user.
#define ZZNET_ERROR_EXCEED_MAX_CARD_PERUSER                _ZZEC(1151)      /// Exceeds maximum number of cards per user.
#define ZZNET_ERROR_EXCEED_ADMINISTRATOR_LIMIT             _ZZEC(1152)      /// Exceeds access control administrator limit.

#define ZZNET_LOGIN_ERROR_DEVICE_NOT_SUPPORT_HIGHLEVEL_SECURITY_LOGIN    _ZZEC(1153)      /// Device does not support high-level security login.
#define ZZNET_LOGIN_ERROR_DEVICE_ONLY_SUPPORT_HIGHLEVEL_SECURITY_LOGIN   _ZZEC(1154)      /// Device only supports high-level security login.

#define ZZNET_ERROR_VIDEO_CHANNEL_OFFLINE                  _ZZEC(1155)      /// Indicates this video channel is offline, streaming failed.
#define ZZNET_ERROR_USERID_FORMAT_INCORRECT                _ZZEC(1156)    /// User ID format is incorrect.
#define ZZNET_ERROR_CANNOT_FIND_CHANNEL_RELATE_TO_SN       _ZZEC(1157)    /// Cannot find the channel corresponding to this SN.
#define ZZNET_ERROR_TASK_QUEUE_OF_CHANNEL_IS_FULL          _ZZEC(1158)    /// The task queue for this channel is full.
#define ZZNET_ERROR_APPLY_USER_INFO_BLOCK_FAIL             _ZZEC(1159)    /// Failed to apply for a new user information (permission) block.
#define ZZNET_ERROR_EXCEED_MAX_PASSWD_PERUSER              _ZZEC(1160)    /// Number of user passwords exceeds limit.
#define ZZNET_ERROR_PARSE_PROTOCOL                         _ZZEC(1161)    /// Protocol parsing error caused by internal device exception.
#define NET_ERROR_CARD_NUM_EXIST                           _ZZEC(1162)    /// Card number already exists.
#define NET_ERROR_FINGERPRINT_EXIST                        _ZZEC(1163)    /// Fingerprint already exists.

#define ZZNET_ERROR_OPEN_PLAYGROUP_FAIL                    _ZZEC(1164)    /// Failed to open playgroup.
#define ZZNET_ERROR_ALREADY_IN_PLAYGROUP                   _ZZEC(1165)    /// Already in playgroup.
#define ZZNET_ERROR_QUERY_PLAYGROUP_TIME_FAIL              _ZZEC(1166)    /// Failed to query playgroup time.
#define ZZNET_ERROR_SET_PLAYGROUP_BASECHANNEL_FAIL         _ZZEC(1167)    /// Failed to set playgroup base channel.
#define ZZNET_ERROR_SET_PLAYGROUP_DIRECTION_FAIL           _ZZEC(1168)    /// Failed to set playgroup direction.
#define ZZNET_ERROR_SET_PLAYGROUP_SPEED_FAIL               _ZZEC(1169)    /// Failed to set playgroup speed.
#define ZZNET_ERROR_ADD_PLAYGROUP_FAIL                     _ZZEC(1170)    /// Failed to join playgroup.

#define ZZNET_ERROR_EXPORT_AOL_LOGFILE_NO_AUTH             _ZZEC(1171)    /// Export AOL Log: No permission.
#define ZZNET_ERROR_EXPORT_AOL_LOGFILE_NO_FILE             _ZZEC(1172)    /// Export AOL Log: File not found.
#define ZZNET_ERROR_EXPORT_AOL_LOGFILE_FILE_FAIL           _ZZEC(1173)    /// Export AOL Log: File preparation failed.
#define ZZNET_ERROR_EXPORT_AOL_LOGFILE_BUSY                _ZZEC(1174)    /// Export AOL Log: System is busy.

/// Device App Installation Related Error Codes
#define ZZNET_ERROR_EMPTY_LICENSE                         _ZZEC(1175)      /// License is empty.
#define ZZNET_ERROR_UNSUPPORTED_MODE                      _ZZEC(1176)      /// This mode is not supported.
#define ZZNET_ERROR_URL_APP_NOT_MATCH                     _ZZEC(1177)      /// URL does not match App.
#define ZZNET_ERROR_READ_INFO_FAILED                      _ZZEC(1178)      /// Failed to read information.
#define ZZNET_ERROR_WRITE_FAILED                          _ZZEC(1179)      /// Write failed.
#define ZZNET_ERROR_NO_SUCH_APP                           _ZZEC(1180)      /// App not found.
#define ZZNET_ERROR_VERIFIF_FAILED                        _ZZEC(1181)      /// Verification failed.
#define ZZNET_ERROR_LICENSE_OUT_DATE                      _ZZEC(1182)      /// License has expired.

#define ZZNET_ERROR_UPGRADE_PROGRAM_TOO_OLD                _ZZEC(1183)      /// Upgrade program version is too low.
#define ZZNET_ERROR_SECURE_TRANSMIT_BEEN_CUT               _ZZEC(1184)      /// Secure transmission has been truncated.
#define ZZNET_ERROR_DEVICE_NOT_SUPPORT_SECURE_TRANSMIT     _ZZEC(1185)      /// Device does not support secure transmission.

#define ZZNET_ERROR_EXTRA_STREAM_LOGIN_FAIL_CAUSE_BY_MAIN_STREAM _ZZEC(1186)    /// Sub-stream login failed while main stream login succeeded.
#define ZZNET_ERROR_EXTRA_STREAM_CLOSED_BY_REMOTE_DEVICE         _ZZEC(1187)    /// Sub-stream closed by remote device.

/*Face Database Import/Export Error Codes Start*/
#define ZZNET_ERROR_IMPORT_FACEDB_SEND_FAILD                _ZZEC(1188)    /// Face Database Import: Failed to send face database data.
#define ZZNET_ERROR_IMPORT_FACEDB_BUSY                      _ZZEC(1189)    /// Face Database Import: System is busy, import task already in progress.
#define ZZNET_ERROR_IMPORT_FACEDB_DATAERROR                 _ZZEC(1190)    /// Face Database Import: Data packet verification failed.
#define ZZNET_ERROR_IMPORT_FACEDB_DATAINVALID               _ZZEC(1191)    /// Face Database Import: Data packet is invalid.
#define ZZNET_ERROR_IMPORT_FACEDB_UPGRADE_FAILD             _ZZEC(1192)      /// Face Database Import: Upload failed.
#define ZZNET_ERROR_IMPORT_FACEDB_NO_AUTHORITY              _ZZEC(1193)      /// Face Database Import: User has no permission.
#define ZZNET_ERROR_IMPORT_FACEDB_ABNORMAL_FILE             _ZZEC(1194)      /// Face Database Import: File format is abnormal.
#define ZZNET_ERROR_IMPORT_FACEDB_SYNC_FALID                _ZZEC(1195)    /// Face Database Import: Synchronization failed, database cannot be generated.
#define ZZNET_ERROR_IMPORT_FACEDB_DBFULL                    _ZZEC(1196)    /// Face Database Import: Database is full, cannot import.
#define ZZNET_ERROR_IMPORT_FACEDB_SDFULL                    _ZZEC(1197)    /// Face Database Import: Storage space is full, cannot import.
#define ZZNET_ERROR_IMPORT_FACEDB_CIPHER_ERROR              _ZZEC(1198)    /// Face Database Import: Incorrect password for import package.

#define ZZNET_ERROR_EXPORT_FACEDB_NO_AUTH                   _ZZEC(1199)    /// Face Database Export: No permission.
#define ZZNET_ERROR_EXPORT_FACEDB_NO_FILE                   _ZZEC(1200)    /// Face Database Export: File not found.
#define ZZNET_ERROR_EXPORT_FACEDB_FILE_FAIL                 _ZZEC(1201)    /// Face Database Export: File preparation failed.
#define ZZNET_ERROR_EXPORT_FACEDB_BUSY                      _ZZEC(1202)    /// Face Database Export: System is busy.
#define ZZNET_ERROR_EXPORT_FACEDB_NO_PASSWORD               _ZZEC(1203)    /// Face Database Export: No password defined, export not allowed.
/*Face Database Import/Export Error Codes End*/

#define ZZNET_ERROR_REQUESTED_TOO_MUCH_DATA                _ZZEC(1204)    /// Too much data requested, device cannot process.
#define ZZNET_ERROR_BATCH_PROCESS_ERROR                    _ZZEC(1205)    /// An error occurred during batch business execution.
#define ZZNET_ERROR_OPERATION_CANCELLED                    _ZZEC(1206)    /// Business execution cancelled for some reason.

#define ZZNET_ERROR_DEVICE_INVALID                         _ZZEC(1207)    /// Device model is incorrect, cannot proceed further.
#define ZZNET_ERROR_DEVICE_UNAVAILABLE                     _ZZEC(1208)    /// Unable to retrieve device status information.

#define ZZNET_ERROR_FINGERPRINT_DOWNLOAD_FAIL              _ZZEC(1209)    /// Failed to download fingerprint via URL.
#define ZZNET_ERROR_ACCOUNT_IN_USE                         _ZZEC(1210)    /// Account is currently logged in.
#define ZZNET_ERROR_IRIS_INFO_NOT_EXISTED                   _ZZEC(1211)    /// When updating user iris information, the user has no iris templates.
#define ZZNET_ERROR_INVALID_IRIS_DATA                      _ZZEC(1212)    /// The issued iris data format or feature size is incorrect.
#define ZZNET_ERROR_IRIS_ALREADY_EXIST                     _ZZEC(1213)    /// Iris information already exists.
#define ZZNET_ERROR_ERASE_IRIS_FAILED                      _ZZEC(1214)    /// Failed to delete iris information.
#define ZZNET_ERROR_EXCEED_MAX_IRIS_GROUP_COUNT_PER_USER   _ZZEC(1215)    /// Exceeds the maximum number of iris groups supported per user (one group consists of two irises: left and right).
#define ZZNET_ERROR_EXCEED_MAX_IRIS_COUNT_PER_GROUP        _ZZEC(1216)    /// Exceeds the maximum number of iris records allowed per group for an individual.
#define ZZNET_ERROR_DOOR_IN_NORMALLY_OPEN_STATUS           _ZZEC(1217)    /// Door is in normally open state.
#define ZZNET_ERROR_DOOR_IN_NORMALLY_CLOSED_STATUS         _ZZEC(1218)    /// Door is in normally closed state.
#define ZZNET_ERROR_DOOR_IN_INTERLOCK_STATUS               _ZZEC(1219)    /// Door is in interlock state.
#define ZZNET_ERROR_INVALID_PWD_DATA                       _ZZEC(1220)    /// The issued password data is incorrect.
#define ZZNET_ERROR_TYPE_OR_NOT_SUPPORT                    _ZZEC(1221)    /// Password type is incorrect or this feature is not supported.
#define ZZNET_ERROR_DOOR_PERMISSION_NOT_EXIST              _ZZEC(1222)    /// Invalid door permission group.
#define ZZNET_ERROR_INVALID_DOOR_PERMISSION_DATA           _ZZEC(1223)    /// Invalid door permission group data.
#define ZZNET_ERROR_INVALID_HOLIDAY_SCHEDULE_DATA          _ZZEC(1224)    /// Invalid holiday schedule data.
#define ZZNET_ERROR_INVALID_PERMISSION_GROUP_DATA          _ZZEC(1225)    /// Invalid permission group data.
#define ZZNET_ERROR_INVALID_TASKID_DATA                    _ZZEC(1226)    /// Invalid task ID data.
#define ZZNET_ERROR_INVALID_TIME_TEMPLATE_DATA             _ZZEC(1227)    /// Invalid time template data.
#define ZZNET_ERROR_INVALID_USER_PERMISSION_DATA           _ZZEC(1228)    /// Invalid user permission data.
#define ZZNET_ERROR_TIME_TEMPLATE_ASSOCIATED               _ZZEC(1229)    /// Time template is bound and cannot be deleted.
#define ZZNET_ERROR_HOLIDAY_SCHEDULE_ASSOCIATED            _ZZEC(1230)    /// Holiday schedule is bound and cannot be deleted.
#define ZZNET_ERROR_NAME_ALREADY_EXIST                     _ZZEC(1231)    /// Name already exists.
#define ZZNET_ERROR_CONFIG_FAILED                          _ZZEC(1232)    /// Configuration issuance failed.
#define ZZNET_ERROR_INVALID_ATTENDANCE_DATA                _ZZEC(1233)    /// Incorrect attendance data issued.
#define ZZNET_ERROR_DO_NOT_EDIT                            _ZZEC(1234)    /// Data is not allowed to be edited.
#define ZZNET_ERROR_BINDING                                _ZZEC(1235)    /// Data is bound.
#define ZZNET_ERROR_HAND_PRINT_INFO_NOT_EXISTED            _ZZEC(1236)    /// When updating user palm print information, the user has no palm print data.
#define ZZNET_ERROR_INVALID_HAND_PRINT_DATA                _ZZEC(1237)    /// The issued palm print data format or feature size is incorrect.
#define ZZNET_ERROR_HANDPRINT_ALREADY_EXIST                _ZZEC(1238)    /// Palm print already exists.
#define ZZNET_ERROR_ERASE_HANDPRINT_FAILED                 _ZZEC(1239)    /// Failed to delete palm print information.
#define ZZNET_ERROR_EXCEED_MAX_HANDPRINT_GROUP_COUNT_PER_USER    _ZZEC(1240)    /// Exceeds the maximum number of palm print groups supported per user (one group consists of two palms: left and right).
#define ZZNET_ERROR_EXCEED_MAX_HANDPRINT_COUNT_PER_GROUP         _ZZEC(1241)    /// Exceeds the maximum number of palm print records allowed per group for an individual.
#define ZZNET_ERROR_FACEMANAGER_FEATURE_SIZE_ERROR        _ZZEC(1242)      /// Face feature size error.

/* Face Image Operation Error Codes Range _ZZEC(1300) ~ _ZZEC(1400) */
#define ZZNET_ERROR_FACEMANAGER_NO_FACE_DETECTED          _ZZEC(1300)      /// No faces detected in the image.
#define ZZNET_ERROR_FACEMANAGER_MULTI_FACE_DETECTED       _ZZEC(1301)      /// Multiple faces detected in the image, cannot return features.
#define ZZNET_ERROR_FACEMANAGER_PICTURE_DECODING_ERROR    _ZZEC(1302)      /// Image decoding error.
#define ZZNET_ERROR_FACEMANAGER_LOW_PICTURE_QUALITY       _ZZEC(1303)      /// Image quality is too low.
#define ZZNET_ERROR_FACEMANAGER_NOT_RECOMMENDED           _ZZEC(1304)      /// Results not recommended for use (e.g., for foreigners, feature extraction succeeds but algorithm support is poor, prone to misidentification).
#define ZZNET_ERROR_FACEMANAGER_FACE_FEATURE_ALREADY_EXIST  _ZZEC(1305)    /// Face feature already exists.
#define ZZNET_ERROR_FACEMANAGER_FACE_ANGLE_OVER_THRESHOLDS    _ZZEC(1307)    /// Face angle exceeds configured thresholds.
#define ZZNET_ERROR_FACEMANAGER_FACE_RADIO_EXCEEDS_RANGE      _ZZEC(1308)    /// Face ratio exceeds range. Algorithm recommended ratio: no more than 2/3; no less than 1/3.
#define ZZNET_ERROR_FACEMANAGER_FACE_OVER_EXPOSED         _ZZEC(1309)        /// Face is overexposed.
#define ZZNET_ERROR_FACEMANAGER_FACE_UNDER_EXPOSED        _ZZEC(1310)        /// Face is underexposed.
#define ZZNET_ERROR_FACEMANAGER_BRIGHTNESS_IMBALANCE      _ZZEC(1311)        /// Face brightness imbalance (used to judge阴阳脸/yin-yang face).
#define ZZNET_ERROR_FACEMANAGER_FACE_LOWER_CONFIDENCE     _ZZEC(1312)        /// Face confidence is low.
#define ZZNET_ERROR_FACEMANAGER_FACE_LOW_ALIGN            _ZZEC(1313)        /// Face alignment score is low.
#define ZZNET_ERROR_FACEMANAGER_FRAGMENTARY_FACE_DETECTED _ZZEC(1314)        /// Detected face is occluded or incomplete.
#define ZZNET_ERROR_FACEMANAGER_PUPIL_DISTANCE_NOT_ENOUGH _ZZEC(1315)        /// Inter-pupillary distance is less than threshold.
#define ZZNET_ERROR_FACEMANAGER_FACE_DATA_DOWNLOAD_FAILED _ZZEC(1316)        /// Failed to download face data.

/// Platform-Issued Collection Command Error Codes
#define ZZNET_ERROR_CITIZENMANAGER_ERROR_WORKINGMODE_ERROR    _ZZEC(1317)    /// Operation mode error.
#define ZZNET_ERROR_CITIZENMANAGER_ERROR_CAPTURE_BUSY          _ZZEC(1318)    /// Capture is busy.
#define ZZNET_ERROR_CITIZENMANAGER_ERROR_CAPTURE_TYPE_ERROR    _ZZEC(1319)    /// This capture method is not supported.

#define ZZNET_ERROR_NORMAL_USER_NOTSUPPORT                     _ZZEC(1320)    /// Regular users do not support issuance.

/// Thermostat
#define ZZNET_ERROR_THERMOGRAPHY_REF_SENSOR_OPEN_INVALID    _ZZEC(1321)    /// Forced start of thermostat is invalid; maximum daily start times reached.
#define ZZNET_ERROR_THERMOGRAPHY_REF_DELAY_SHUT_DOWN_INVALID _ZZEC(1322)    /// Delayed shutdown of thermostat is invalid; maximum daily delays reached.

#define ZZNET_ERROR_CITIZENID_EXIST                           _ZZEC(1323)        /// ID number already exists.

#define ZZNET_ERROR_FACEMANAGER_FACE_FFE_FAILED                _ZZEC(1324)        /// Face detected, but feature extraction failed (algorithm scenario).
#define ZZNET_ERROR_FACEMANAGER_PHOTO_FEATURE_FAILED_FOR_FA    _ZZEC(1325)        /// Face photo feature extraction failed due to non-compliant attributes (e.g., mask, hat, sunglasses).
#define ZZNET_ERROR_FACEMANAGER_FACE_DATA_PHOTO_INCOMPLETE     _ZZEC(1326)        /// Face photo is incomplete.

#define ZZNET_ERROR_DATABASE_ERROR_INSERT_OVERFLOW             _ZZEC(1327)        /// Database insertion overflow.

/*Work Uniform Detection Compliance Library Error Codes Start*/
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_GROUPID_EXCEED             _ZZEC(1328)    /// Work Uniform Detection Compliance Library: Group ID exceeds maximum value.
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_ABSTRACT_INIT_ERROR         _ZZEC(1329)    /// Work Uniform Detection Compliance Library: Failed to start modeling analyzer.
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_GROUPID_NOT_FOUND          _ZZEC(1330)    /// Work Uniform Detection Compliance Library: Group ID does not exist or is empty.
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_DATABASE_ERROR              _ZZEC(1331)    /// Work Uniform Detection Compliance Library: Database operation failed.
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_TOKEN_ERROR                  _ZZEC(1332)    /// Work Uniform Detection Compliance Library: Token does not exist or is empty.
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_BEGINNUM_OVERRUN            _ZZEC(1333)    /// Work Uniform Detection Compliance Library: Query start number is greater than total count.
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_ABSTRACT_STATE              _ZZEC(1334)    /// Work Uniform Detection Compliance Library: Device is modeling.
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_BIGPIC_MAXNUM                _ZZEC(1335)    /// Work Uniform Detection Compliance Library: Number of panoramic images imported at one time exceeds limit.
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_OBJECT_MAXNUM                _ZZEC(1336)    /// Work Uniform Detection Compliance Library: Number of work uniforms exceeds limit.
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_GROUP_SPACE_EXCEED           _ZZEC(1337)    /// Work Uniform Detection Compliance Library: Exceeds compliance library space limit.
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_ABSTRACTNUM_ZERO             _ZZEC(1338)    /// Work Uniform Detection Compliance Library: Number of items requiring manual modeling is zero.
#define ZZNET_ERROR_WORKSUIT_COMPARE_SERVER_INVALID_PARAM                _ZZEC(1339)    /// Work Uniform Detection Compliance Library: Invalid parameter.
/*Work Uniform Detection Compliance Library Error Codes End*/

#define ZZNET_ERROR_CARD_NOT_EXIST                                       _ZZEC(1340)    /// Card number does not exist.

#define ZZNET_ERROR_TEMPORARY_OUTDATED                                   _ZZEC(1341)    /// Temporary library is outdated.
#define ZZNET_ERROR_AUTH_CODE_TIME_OUT                                   _ZZEC(1342)      /// Security code has expired.

/*Device Sub-business Specific Error Codes Start, Range _ZZEC(1401) ~ _ZZEC(1500)*/
#define ZZNET_SUBBIZ_INVALID_SOCKET                                       _ZZEC(1401)    /// Invalid connection.
#define ZZNET_SUBBIZ_PAUSE_ERROR                                          _ZZEC(1402)      /// Failed to pause media file download.
#define ZZNET_SUBBIZ_GET_PORT_ERROR                                       _ZZEC(1403)    /// Failed to obtain private tunnel upward listening port.
/*Device Sub-business Specific Error Codes End*/

































