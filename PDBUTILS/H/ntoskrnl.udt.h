
enum {
	KTMOH_CommitTransaction_Result = 0x1,
	KTMOH_RollbackTransaction_Result = 0x2
};

struct BATTERY_REPORTING_SCALE {
	/*0000*/ ULONG Granularity;
	/*0004*/ ULONG Capacity;
	/*0008*/
};

enum BUS_QUERY_ID_TYPE {
	BusQueryDeviceID = 0x0,
	BusQueryHardwareIDs = 0x1,
	BusQueryCompatibleIDs = 0x2,
	BusQueryInstanceID = 0x3,
	BusQueryDeviceSerialNumber = 0x4,
	BusQueryContainerID = 0x5
};

struct CMP_OFFSET_ARRAY {
	/*0000*/ ULONG FileOffset;
	/*0008*/ void * DataBuffer;
	/*0010*/ ULONG DataLength;
	/*0018*/
};

enum DEVICE_TEXT_TYPE {
	DeviceTextDescription = 0x0,
	DeviceTextLocationInformation = 0x1
};

struct DOCK_INTERFACE {
	/*0000*/ USHORT Size;
	/*0002*/ USHORT Version;
	/*0008*/ void * Context;
	/*0010*/ void (* InterfaceReference)( void * );
	/*0018*/ void (* InterfaceDereference)( void * );
	/*0020*/ ULONG (* ProfileDepartureSetMode)( void * , PROFILE_DEPARTURE_STYLE );
	/*0028*/ ULONG (* ProfileDepartureUpdate)( void * );
	/*0030*/
};

enum ETW_COMPRESSION_RESUMPTION_MODE {
	EtwCompressionModeRestart = 0x0,
	EtwCompressionModeNoDisable = 0x1,
	EtwCompressionModeNoRestart = 0x2
};

enum HAL_APIC_DESTINATION_MODE {
	ApicDestinationModePhysical = 0x1,
	ApicDestinationModeLogicalFlat = 0x2,
	ApicDestinationModeLogicalClustered = 0x3,
	ApicDestinationModeUnknown = 0x4
};

enum HSTORAGE_TYPE {
	Stable = 0x0,
	Volatile = 0x1,
	InvalidStorage = 0x2
};

enum INTERRUPT_CONNECTION_TYPE {
	InterruptTypeControllerInput = 0x0,
	InterruptTypeXapicMessage = 0x1,
	InterruptTypeHypertransport = 0x2,
	InterruptTypeMessageRequest = 0x3
};

enum IRPLOCK {
	IRPLOCK_CANCELABLE = 0x0,
	IRPLOCK_CANCEL_STARTED = 0x1,
	IRPLOCK_CANCEL_COMPLETE = 0x2,
	IRPLOCK_COMPLETED = 0x3
};

enum JOB_OBJECT_IO_RATE_CONTROL_FLAGS {
	JOB_OBJECT_IO_RATE_CONTROL_ENABLE = 0x1,
	JOB_OBJECT_IO_RATE_CONTROL_STANDALONE_VOLUME = 0x2,
	JOB_OBJECT_IO_RATE_CONTROL_VALID_FLAGS = 0x3
};

enum JOB_OBJECT_NET_RATE_CONTROL_FLAGS {
	JOB_OBJECT_NET_RATE_CONTROL_ENABLE = 0x1,
	JOB_OBJECT_NET_RATE_CONTROL_MAX_BANDWIDTH = 0x2,
	JOB_OBJECT_NET_RATE_CONTROL_DSCP_TAG = 0x4,
	JOB_OBJECT_NET_RATE_CONTROL_VALID_FLAGS = 0x7
};

enum KTM_STATE {
	KKtmUninitialized = 0x0,
	KKtmInitialized = 0x1,
	KKtmRecovering = 0x2,
	KKtmOnline = 0x3,
	KKtmRecoveryFailed = 0x4,
	KKtmOffline = 0x5
};

struct LIST_ENTRY32 {
	/*0000*/ ULONG Flink;
	/*0004*/ ULONG Blink;
	/*0008*/
};

struct LIST_ENTRY64 {
	/*0000*/ ULONGLONG Flink;
	/*0008*/ ULONGLONG Blink;
	/*0010*/
};

enum LSA_FOREST_TRUST_RECORD_TYPE {
	ForestTrustTopLevelName = 0x0,
	ForestTrustTopLevelNameEx = 0x1,
	ForestTrustDomainInfo = 0x2,
	ForestTrustRecordTypeLast = 0x2
};

enum PDCCLIENTID {
	PDC_INVALID_CLIENT = 0x0,
	PDC_PLM_CLIENT = 0x1,
	PDC_NQM_CLIENT = 0x2,
	PDC_WNS_CLIENT = 0x3,
	PDC_DAM_CLIENT = 0x4,
	PDC_WCM_CLIENT = 0x5,
	PDC_NCSI_CLIENT = 0x7,
	PDC_DHCP_CLIENT = 0x8,
	PDC_TCPIP_CLIENT = 0x9,
	PDC_WU_CLIENT = 0xb,
	PDC_GP_CLIENT = 0xc,
	PDC_NCA_CLIENT = 0xe,
	PDC_BI_CLIENT = 0xf,
	PDC_MSCHED_CLIENT = 0x10,
	PDC_SUSPENDRESUME_CLIENT = 0x11,
	PDC_ACTIVATION_CLIENT = 0x12,
	PDC_ACTIVATION_TEST_CLIENT = 0x13,
	PDC_PLM_PHASE_TEST_CLIENT = 0x14,
	PDC_DAM_PHASE_TEST_CLIENT = 0x15,
	PDC_LOW_POWER_PHASE_TEST_CLIENT = 0x16,
	PDC_RESILIENCY_NOTIFICATION_PHASE_TEST_CLIENT = 0x17,
	PDC_NQM_RESILIENCY_TEST_CLIENT = 0x18,
	PDC_DAM_RESILIENCY_TEST_CLIENT = 0x19,
	PDC_DAM_KM_TEST_CLIENT = 0x1a,
	PDC_DAM_UM_TEST_CLIENT = 0x1b,
	PDC_SINGLETON_TEST_CLIENT = 0x1c,
	PDC_NETWORK_SERVICE_TEST_CLIENT = 0x1d,
	PDC_NETWORK_SERVICE2_TEST_CLIENT = 0x1e,
	PDC_SYSTEM_SERVICE_TEST_CLIENT = 0x1f,
	PDC_ACTIV_NOTIF_DAM_RESIL_TEST_CLIENT = 0x20,
	PDC_ACTIV_NOTIF_NET_RESIL_TEST_CLIENT = 0x21,
	PDC_SHELL_CLIENT = 0x22,
	PDC_MAINTENANCE_CLIENT = 0x23,
	PDC_SYNC_CLIENT = 0x24,
	PDC_IDM_CLIENT = 0x25,
	PDC_CORTANA_VOICE_ACTIVATION_CLIENT = 0x26,
	PDC_TETHERING_CLIENT = 0x27,
	PDC_AUDIO_CLIENT = 0x28,
	PDC_LOCK_SCREEN = 0x29,
	PDC_LREC_CLIENT = 0x2a,
	PDC_WP_BW_CLIENT = 0x2b,
	PDC_WP_MEDIA_STREAMING_CLIENT = 0x2c,
	PDC_WP_MAPS_CLIENT = 0x2e,
	PDC_WP_SYNC_CLIENT = 0x2f,
	PDC_SETTING_SYNC_CLIENT = 0x30,
	PDC_WP_EDM_CLIENT = 0x31,
	PDC_WP_WALLET_CLIENT = 0x32,
	PDC_WP_LOCATION_CLIENT = 0x33,
	PDC_WP_CM_CLIENT = 0x35,
	PDC_WP_DCP_CLIENT = 0x36,
	PDC_WP_WIFIAUTO_CLIENT = 0x37,
	PDC_BITLOCKER_CLIENT = 0x38,
	PDC_MDM_CERTINSTALLER_CLIENT = 0x39,
	PDC_WP_IM_CLIENT = 0x3a,
	PDC_WP_MMS_CLIENT = 0x3b,
	PDC_DEVICEENROLLER_CLIENT = 0x3c,
	PDC_WP_WIFI_SCANNING_CLIENT = 0x3d,
	PDC_WP_OMADM_CLIENT = 0x3e,
	PDC_WP_TELEMETRY_CHECK_CLIENT = 0x3f,
	PDC_WP_DIS_CLIENT = 0x40,
	PDC_BITS_CLIENT = 0x41,
	PDC_WP_VOIP_EXECUTION_CLIENT = 0x42,
	PDC_WP_RESERVED_CLIENT3 = 0x43,
	PDC_SLEEP_STUDY_CLIENT = 0x44,
	PDC_WP_AUTOTIMEUPDATE_CLIENT = 0x45,
	PDC_HYPERV_CLIENT = 0x46,
	PDC_KM_SIGNAL_CLIENT = 0x47,
	PDC_UM_SIGNAL_CLIENT = 0x48,
	PDC_DEVICE_HEALTH_ATTESTATION_CLIENT = 0x49,
	PDC_XB_SYSTEM_CLIENT = 0x4a,
	PDC_XB_HOST_CLIENT = 0x4b,
	PDC_PRINT_JOB_MANAGER_CLIENT = 0x4c,
	PDC_TELEMETRY_CLIENT = 0x4d,
	PDC_ERROR_REPORTING_CLIENT = 0x4e,
	PDC_XBOX_NTM = 0x4f,
	PDC_CBE_CLIENT = 0x50,
	PDC_FIND_MY_PHONE_CLIENT = 0x51,
	PDC_COMMAND_CHANNEL_CLIENT = 0x52,
	PDC_PPM_PROFILES_CLIENT = 0x53,
	PDC_WIFI_CALLING_CLIENT = 0x54,
	PDC_WU_REBOOT_CLIENT = 0x55,
	PDC_SYSMAIN_CLIENT = 0x56,
	PDC_XBOX_UPDATE_CLIENT = 0x57,
	PDC_CHAT_SERVICE_CLIENT = 0x58,
	PDC_FIND_MY_DEVICE_CLIENT = 0x59,
	PDC_NOTIFICATION_FORWARDING_AND_ACTION_CLIENT = 0x5a,
	PDC_INSTALL_AGENT_CLIENT = 0x5b,
	PDC_XBOX_WAKE_ON_VOICE = 0x5c,
	PDC_PLM_AUDIO_CLIENT = 0x5d,
	PDC_WP_BCKAUDIO_CLIENT = 0x5e,
	PDC_WAKE_ON_LAN_CLIENT = 0x5f,
	PDC_WP_CLOUD_MESSAGING_CLIENT = 0x60,
	PDC_DATA_MIGRATION_MANAGER = 0x61,
	PDC_EVENT_SOUND_MANAGER_CLIENT = 0x62,
	PDC_WWAN_DORMANCY_HINT_CLIENT = 0x63,
	PDC_HAM_CLIENT = 0x64,
	PDC_NUMBER_OF_CLIENTS = 0x65
};

enum PDC_ACTIVITY_TYPE {
	PdcNetwork = 0x0,
	PdcSystem = 0x1,
	PdcTimer = 0x2,
	PdcAllNetworks = 0x3,
	PdcInvalidActivity = 0x4,
	PdcMaxActivity = 0x4
};

struct PEPHANDLE__ {
	/*0000*/ INT unused;
	/*0004*/
};

enum POWER_ACTION {
	PowerActionNone = 0x0,
	PowerActionReserved = 0x1,
	PowerActionSleep = 0x2,
	PowerActionHibernate = 0x3,
	PowerActionShutdown = 0x4,
	PowerActionShutdownReset = 0x5,
	PowerActionShutdownOff = 0x6,
	PowerActionWarmEject = 0x7,
	PowerActionDisplayOff = 0x8
};

struct POWER_ACTION_POLICY {
	/*0000*/ POWER_ACTION Action;
	/*0004*/ ULONG Flags;
	/*0008*/ ULONG EventCode;
	/*000c*/
};

enum POWER_POLICY_DEVICE_TYPE {
	PolicyDeviceSystemButton = 0x0,
	PolicyDeviceThermalZone = 0x1,
	PolicyDeviceBattery = 0x2,
	PolicyDeviceMemory = 0x3,
	PolicyInitiatePowerActionAPI = 0x4,
	PolicySetPowerStateAPI = 0x5,
	PolicyImmediateDozeS4 = 0x6,
	PolicySystemIdle = 0x7,
	PolicyDeviceWakeAlarm = 0x8,
	PolicyDeviceFan = 0x9,
	PolicyCsBatterySaver = 0xa,
	PolicyImmediateDozeS4Predicted = 0xb,
	PolicyImmediateDozeS4PredictedNoWake = 0xc,
	PolicyImmediateDozeS4AdaptiveBudget = 0xd,
	PolicyImmediateDozeS4AdaptiveReserveNoWake = 0xe,
	PolicyDeviceMax = 0xf
};

struct PO_MEMORY_IMAGE {
	/*0000*/ ULONG Signature;
	/*0004*/ ULONG ImageType;
	/*0008*/ ULONG CheckSum;
	/*000c*/ ULONG LengthSelf;
	/*0010*/ ULONGLONG PageSelf;
	/*0018*/ ULONG PageSize;
	/*0020*/ _LARGE_INTEGER SystemTime;
	/*0028*/ ULONGLONG InterruptTime;
	/*0030*/ ULONGLONG FeatureFlags;
	/*0038*/ UCHAR HiberFlags;
	/*0039*/ UCHAR spare[0x3];
	/*003c*/ ULONG NoHiberPtes;
	/*0040*/ ULONGLONG HiberVa;
	/*0048*/ ULONG NoFreePages;
	/*004c*/ ULONG FreeMapCheck;
	/*0050*/ ULONG WakeCheck;
	/*0058*/ ULONGLONG NumPagesForLoader;
	/*0060*/ ULONGLONG FirstSecureRestorePage;
	/*0068*/ ULONGLONG FirstBootRestorePage;
	/*0070*/ ULONGLONG FirstKernelRestorePage;
	/*0078*/ ULONGLONG FirstChecksumRestorePage;
	/*0080*/ ULONGLONG NoChecksumEntries;
	/*0088*/ _PO_HIBER_PERF PerfInfo;
	/*0280*/ ULONG FirmwareRuntimeInformationPages;
	/*0288*/ ULONGLONG FirmwareRuntimeInformation[0x1];
	/*0290*/ ULONG SiLogOffset;
	/*0294*/ ULONG NoBootLoaderLogPages;
	/*0298*/ ULONGLONG BootLoaderLogPages[0x18];
	/*0358*/ ULONG NotUsed;
	/*035c*/ ULONG ResumeContextCheck;
	/*0360*/ ULONG ResumeContextPages;
	/*0364*/ UCHAR Hiberboot;
	/*0368*/ ULONGLONG HvCr3;
	/*0370*/ ULONGLONG HvEntryPoint;
	/*0378*/ ULONGLONG HvReservedTransitionAddress;
	/*0380*/ ULONGLONG HvReservedTransitionAddressSize;
	/*0388*/ ULONGLONG BootFlags;
	/*0390*/ ULONGLONG RestoreProcessorStateRoutine;
	/*0398*/ ULONGLONG HighestPhysicalPage;
	/*03a0*/ ULONGLONG BitlockerKeyPfns[0x4];
	/*03c0*/ ULONG HardwareSignature;
	/*03c8*/ _LARGE_INTEGER SMBiosTablePhysicalAddress;
	/*03d0*/ ULONG SMBiosTableLength;
	/*03d4*/ UCHAR SMBiosMajorVersion;
	/*03d5*/ UCHAR SMBiosMinorVersion;
	/*03d8*/
};

enum PPM_IDLE_BUCKET_TIME_TYPE {
	PpmIdleBucketTimeInQpc = 0x0,
	PpmIdleBucketTimeIn100ns = 0x1,
	PpmIdleBucketTimeMaximum = 0x2
};

struct PROCESSOR_IDLESTATE_INFO {
	/*0000*/ ULONG TimeCheck;
	/*0004*/ UCHAR DemotePercent;
	/*0005*/ UCHAR PromotePercent;
	/*0006*/ UCHAR Spare[0x2];
	/*0008*/
};

struct PROCESSOR_IDLESTATE_POLICY {
	/*0000*/ USHORT Revision;
	union {
		/*0002*/ USHORT AsUSHORT;
		/*0002*/ USHORT AllowScaling : 01; // 0x0001;
		/*0002*/ USHORT Disabled : 01; // 0x0002;
		/*0002*/ USHORT Reserved : 14; // 0xfffc;
		/*0004*/
	} Flags;
	/*0004*/ ULONG PolicyCount;
	/*0008*/ PROCESSOR_IDLESTATE_INFO Policy[0x3];
	/*0020*/
};

struct PROCESSOR_PERFSTATE_POLICY {
	/*0000*/ ULONG Revision;
	/*0004*/ UCHAR MaxThrottle;
	/*0005*/ UCHAR MinThrottle;
	/*0006*/ UCHAR BusyAdjThreshold;
	/*0007*/ UCHAR Spare;
	union {
		/*0007*/ UCHAR AsUCHAR;
		/*0007*/ UCHAR NoDomainAccounting : 01; // 0x01;
		/*0007*/ UCHAR IncreasePolicy : 02; // 0x06;
		/*0007*/ UCHAR DecreasePolicy : 02; // 0x18;
		/*0007*/ UCHAR Reserved : 03; // 0xe0;
		/*0008*/
	} Flags;
	/*0008*/ ULONG TimeCheck;
	/*000c*/ ULONG IncreaseTime;
	/*0010*/ ULONG DecreaseTime;
	/*0014*/ ULONG IncreasePercent;
	/*0018*/ ULONG DecreasePercent;
	/*001c*/
};

enum PROFILE_DEPARTURE_STYLE {
	PDS_UPDATE_DEFAULT = 0x1,
	PDS_UPDATE_ON_REMOVE = 0x2,
	PDS_UPDATE_ON_INTERFACE = 0x3,
	PDS_UPDATE_ON_EJECT = 0x4
};

enum PROFILE_STATUS {
	DOCK_NOTDOCKDEVICE = 0x0,
	DOCK_QUIESCENT = 0x1,
	DOCK_ARRIVING = 0x2,
	DOCK_DEPARTING = 0x3,
	DOCK_EJECTIRP_COMPLETED = 0x4
};

enum PS_CREATE_STATE {
	PsCreateInitialState = 0x0,
	PsCreateFailOnFileOpen = 0x1,
	PsCreateFailOnSectionCreate = 0x2,
	PsCreateFailExeFormat = 0x3,
	PsCreateFailMachineMismatch = 0x4,
	PsCreateFailExeName = 0x5,
	PsCreateSuccess = 0x6,
	PsCreateMaximumStates = 0x7
};

enum ReplacesCorHdrNumericDefines {
	COMIMAGE_FLAGS_ILONLY = 0x1,
	COMIMAGE_FLAGS_32BITREQUIRED = 0x2,
	COMIMAGE_FLAGS_IL_LIBRARY = 0x4,
	COMIMAGE_FLAGS_STRONGNAMESIGNED = 0x8,
	COMIMAGE_FLAGS_NATIVE_ENTRYPOINT = 0x10,
	COMIMAGE_FLAGS_TRACKDEBUGDATA = 0x10000,
	COMIMAGE_FLAGS_32BITPREFERRED = 0x20000,
	COR_VERSION_MAJOR_V2 = 0x2,
	COR_VERSION_MAJOR = 0x2,
	COR_VERSION_MINOR = 0x5,
	COR_DELETED_NAME_LENGTH = 0x8,
	COR_VTABLEGAP_NAME_LENGTH = 0x8,
	NATIVE_TYPE_MAX_CB = 0x1,
	COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE = 0xff,
	IMAGE_COR_MIH_METHODRVA = 0x1,
	IMAGE_COR_MIH_EHRVA = 0x2,
	IMAGE_COR_MIH_BASICBLOCK = 0x8,
	COR_VTABLE_32BIT = 0x1,
	COR_VTABLE_64BIT = 0x2,
	COR_VTABLE_FROM_UNMANAGED = 0x4,
	COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN = 0x8,
	COR_VTABLE_CALL_MOST_DERIVED = 0x10,
	IMAGE_COR_EATJ_THUNK_SIZE = 0x20,
	MAX_CLASS_NAME = 0x400,
	MAX_PACKAGE_NAME = 0x400
};

enum SE_WS_APPX_SIGNATURE_ORIGIN {
	SE_WS_APPX_SIGNATURE_ORIGIN_NOT_VALIDATED = 0x0,
	SE_WS_APPX_SIGNATURE_ORIGIN_UNKNOWN = 0x1,
	SE_WS_APPX_SIGNATURE_ORIGIN_APPSTORE = 0x2,
	SE_WS_APPX_SIGNATURE_ORIGIN_WINDOWS = 0x3,
	SE_WS_APPX_SIGNATURE_ORIGIN_ENTERPRISE = 0x4
};

enum SLEEPSTUDY_SPM_SCENARIO_CS_EXIT {
	SpmScenarioStopReasonUnspecified = 0x10,
	SpmScenarioStopReasonCsExit = 0x11,
	SpmScenarioStopReasonMax = 0x12
};

struct SYSTEM_POWER_CAPABILITIES {
	/*0000*/ UCHAR PowerButtonPresent;
	/*0001*/ UCHAR SleepButtonPresent;
	/*0002*/ UCHAR LidPresent;
	/*0003*/ UCHAR SystemS1;
	/*0004*/ UCHAR SystemS2;
	/*0005*/ UCHAR SystemS3;
	/*0006*/ UCHAR SystemS4;
	/*0007*/ UCHAR SystemS5;
	/*0008*/ UCHAR HiberFilePresent;
	/*0009*/ UCHAR FullWake;
	/*000a*/ UCHAR VideoDimPresent;
	/*000b*/ UCHAR ApmPresent;
	/*000c*/ UCHAR UpsPresent;
	/*000d*/ UCHAR ThermalControl;
	/*000e*/ UCHAR ProcessorThrottle;
	/*000f*/ UCHAR ProcessorMinThrottle;
	/*0010*/ UCHAR ProcessorMaxThrottle;
	/*0011*/ UCHAR FastSystemS4;
	/*0012*/ UCHAR Hiberboot;
	/*0013*/ UCHAR WakeAlarmPresent;
	/*0014*/ UCHAR AoAc;
	/*0015*/ UCHAR DiskSpinDown;
	/*0016*/ UCHAR HiberFileType;
	/*0017*/ UCHAR AoAcConnectivitySupported;
	/*0018*/ UCHAR spare3[0x6];
	/*001e*/ UCHAR SystemBatteriesPresent;
	/*001f*/ UCHAR BatteriesAreShortTerm;
	/*0020*/ BATTERY_REPORTING_SCALE BatteryScale[0x3];
	/*0038*/ _SYSTEM_POWER_STATE AcOnLineWake;
	/*003c*/ _SYSTEM_POWER_STATE SoftLidWake;
	/*0040*/ _SYSTEM_POWER_STATE RtcWake;
	/*0044*/ _SYSTEM_POWER_STATE MinDeviceWakeState;
	/*0048*/ _SYSTEM_POWER_STATE DefaultLowLatencyWake;
	/*004c*/
};

enum SYSTEM_POWER_CONDITION {
	PoAc = 0x0,
	PoDc = 0x1,
	PoHot = 0x2,
	PoConditionMaximum = 0x3
};

struct SYSTEM_POWER_LEVEL {
	/*0000*/ UCHAR Enable;
	/*0001*/ UCHAR Spare[0x3];
	/*0004*/ ULONG BatteryLevel;
	/*0008*/ POWER_ACTION_POLICY PowerPolicy;
	/*0014*/ _SYSTEM_POWER_STATE MinSystemState;
	/*0018*/
};

enum TlgIn_t {
	TlgInNULL = 0x0,
	TlgInUNICODESTRING = 0x1,
	TlgInANSISTRING = 0x2,
	TlgInINT8 = 0x3,
	TlgInUINT8 = 0x4,
	TlgInINT16 = 0x5,
	TlgInUINT16 = 0x6,
	TlgInINT32 = 0x7,
	TlgInUINT32 = 0x8,
	TlgInINT64 = 0x9,
	TlgInUINT64 = 0xa,
	TlgInFLOAT = 0xb,
	TlgInDOUBLE = 0xc,
	TlgInBOOL32 = 0xd,
	TlgInBINARY = 0xe,
	TlgInGUID = 0xf,
	_TlgInPOINTER_unsupported = 0x10,
	TlgInFILETIME = 0x11,
	TlgInSYSTEMTIME = 0x12,
	TlgInSID = 0x13,
	TlgInHEXINT32 = 0x14,
	TlgInHEXINT64 = 0x15,
	TlgInCOUNTEDSTRING = 0x16,
	TlgInCOUNTEDANSISTRING = 0x17,
	_TlgInSTRUCT = 0x18,
	_TlgInMax = 0x19,
	TlgInINTPTR = 0x9,
	TlgInUINTPTR = 0xa,
	TlgInPOINTER = 0x15,
	_TlgInCcount = 0x20,
	TlgInVcount = 0x40,
	_TlgInChain = 0x80,
	_TlgInCustom = 0x60,
	_TlgInTypeMask = 0x1f,
	_TlgInCountMask = 0x60,
	_TlgInFlagMask = 0xe0
};

enum TlgOut_t {
	TlgOutNULL = 0x0,
	TlgOutNOPRINT = 0x1,
	TlgOutSTRING = 0x2,
	TlgOutBOOLEAN = 0x3,
	TlgOutHEX = 0x4,
	TlgOutPID = 0x5,
	TlgOutTID = 0x6,
	TlgOutPORT = 0x7,
	TlgOutIPV4 = 0x8,
	TlgOutIPV6 = 0x9,
	TlgOutSOCKETADDRESS = 0xa,
	TlgOutXML = 0xb,
	TlgOutJSON = 0xc,
	TlgOutWIN32ERROR = 0xd,
	TlgOutNTSTATUS = 0xe,
	TlgOutHRESULT = 0xf,
	TlgOutFILETIME = 0x10,
	TlgOutSIGNED = 0x11,
	TlgOutUNSIGNED = 0x12,
	TlgOutUTF8 = 0x23,
	TlgOutPKCS7_WITH_TYPE_INFO = 0x24,
	TlgOutCODE_POINTER = 0x25,
	_TlgOutMax = 0x26,
	_TlgOutChain = 0x80,
	_TlgOutTypeMask = 0x7f
};

enum UoWActionType {
	UoWAddThisKey = 0x0,
	UoWAddChildKey = 0x1,
	UoWDeleteThisKey = 0x2,
	UoWDeleteChildKey = 0x3,
	UoWSetValueNew = 0x4,
	UoWSetValueExisting = 0x5,
	UoWDeleteValue = 0x6,
	UoWSetKeyUserFlags = 0x7,
	UoWSetLastWriteTime = 0x8,
	UoWSetSecurityDescriptor = 0x9,
	UoWRenameSubKey = 0xa,
	UoWRenameOldSubKey = 0xb,
	UoWRenameNewSubKey = 0xc,
	UoWIsolation = 0xd,
	UoWInvalid = 0xe
};

struct VACB_LEVEL_ALLOCATION_LIST {
	/*0000*/ _LIST_ENTRY VacbLevelList;
	/*0010*/ void * VacbLevelWithBcbListHeads;
	/*0018*/ ULONG VacbLevelsAllocated;
	/*0020*/
};

struct _ACCESS_REASONS {
	/*0000*/ ULONG Data[0x20];
	/*0080*/
};

struct _ACCESS_STATE {
	/*0000*/ _LUID OperationID;
	/*0008*/ UCHAR SecurityEvaluated;
	/*0009*/ UCHAR GenerateAudit;
	/*000a*/ UCHAR GenerateOnClose;
	/*000b*/ UCHAR PrivilegesAllocated;
	/*000c*/ ULONG Flags;
	/*0010*/ ULONG RemainingDesiredAccess;
	/*0014*/ ULONG PreviouslyGrantedAccess;
	/*0018*/ ULONG OriginalDesiredAccess;
	/*0020*/ _SECURITY_SUBJECT_CONTEXT SubjectSecurityContext;
	/*0040*/ void * SecurityDescriptor;
	/*0048*/ void * AuxData;
	union {
		/*0050*/ _INITIAL_PRIVILEGE_SET InitialPrivilegeSet;
		/*0050*/ _PRIVILEGE_SET PrivilegeSet;
		/*007c*/
	} Privileges;
	/*007c*/ UCHAR AuditPrivileges;
	/*0080*/ _UNICODE_STRING ObjectName;
	/*0090*/ _UNICODE_STRING ObjectTypeName;
	/*00a0*/
};

struct _ACL {
	/*0000*/ UCHAR AclRevision;
	/*0001*/ UCHAR Sbz1;
	/*0002*/ USHORT AclSize;
	/*0004*/ USHORT AceCount;
	/*0006*/ USHORT Sbz2;
	/*0008*/
};

struct _ACTIVATION_CONTEXT;

struct _ACTIVATION_CONTEXT_DATA;

struct _ACTIVATION_CONTEXT_STACK {
	/*0000*/ _RTL_ACTIVATION_CONTEXT_STACK_FRAME * ActiveFrame;
	/*0008*/ _LIST_ENTRY FrameListCache;
	/*0018*/ ULONG Flags;
	/*001c*/ ULONG NextCookieSequenceNumber;
	/*0020*/ ULONG StackId;
	/*0028*/
};

struct _ACTIVATION_CONTEXT_STACK32 {
	/*0000*/ ULONG ActiveFrame;
	/*0004*/ LIST_ENTRY32 FrameListCache;
	/*000c*/ ULONG Flags;
	/*0010*/ ULONG NextCookieSequenceNumber;
	/*0014*/ ULONG StackId;
	/*0018*/
};

struct _ACTIVATION_CONTEXT_STACK64 {
	/*0000*/ ULONGLONG ActiveFrame;
	/*0008*/ LIST_ENTRY64 FrameListCache;
	/*0018*/ ULONG Flags;
	/*001c*/ ULONG NextCookieSequenceNumber;
	/*0020*/ ULONG StackId;
	/*0028*/
};

struct _ADAPTER_OBJECT;

enum _ADD_DRIVER_STAGE {
	ClassConfigFilters = 0x0,
	LowerDeviceFilters = 0x1,
	LowerClassFilters = 0x2,
	DeviceService = 0x3,
	UpperDeviceFilters = 0x4,
	UpperClassFilters = 0x5,
	MaximumAddStage = 0x6
};

union _AER_BRIDGE_DESCRIPTOR_FLAGS {
	/*0000*/ USHORT UncorrectableErrorMaskRW : 01; // 0x0001;
	/*0000*/ USHORT UncorrectableErrorSeverityRW : 01; // 0x0002;
	/*0000*/ USHORT CorrectableErrorMaskRW : 01; // 0x0004;
	/*0000*/ USHORT AdvancedCapsAndControlRW : 01; // 0x0008;
	/*0000*/ USHORT SecondaryUncorrectableErrorMaskRW : 01; // 0x0010;
	/*0000*/ USHORT SecondaryUncorrectableErrorSevRW : 01; // 0x0020;
	/*0000*/ USHORT SecondaryCapsAndControlRW : 01; // 0x0040;
	/*0000*/ USHORT Reserved : 09; // 0xff80;
	/*0000*/ USHORT AsUSHORT;
	/*0002*/
};

union _AER_ENDPOINT_DESCRIPTOR_FLAGS {
	/*0000*/ USHORT UncorrectableErrorMaskRW : 01; // 0x0001;
	/*0000*/ USHORT UncorrectableErrorSeverityRW : 01; // 0x0002;
	/*0000*/ USHORT CorrectableErrorMaskRW : 01; // 0x0004;
	/*0000*/ USHORT AdvancedCapsAndControlRW : 01; // 0x0008;
	/*0000*/ USHORT Reserved : 12; // 0xfff0;
	/*0000*/ USHORT AsUSHORT;
	/*0002*/
};

union _AER_ROOTPORT_DESCRIPTOR_FLAGS {
	/*0000*/ USHORT UncorrectableErrorMaskRW : 01; // 0x0001;
	/*0000*/ USHORT UncorrectableErrorSeverityRW : 01; // 0x0002;
	/*0000*/ USHORT CorrectableErrorMaskRW : 01; // 0x0004;
	/*0000*/ USHORT AdvancedCapsAndControlRW : 01; // 0x0008;
	/*0000*/ USHORT RootErrorCommandRW : 01; // 0x0010;
	/*0000*/ USHORT Reserved : 11; // 0xffe0;
	/*0000*/ USHORT AsUSHORT;
	/*0002*/
};

struct _AGGREGATED_PAYLOAD_FILTER {
	/*0000*/ USHORT MagicValue : 12; // 0x0fff;
	/*0000*/ USHORT DescriptorVersion : 04; // 0xf000;
	/*0002*/ USHORT Size;
	/*0004*/ USHORT PredicateCount;
	/*0006*/ USHORT Reserved;
	/*0008*/ ULONGLONG HashedEventIdBitmap;
	/*0010*/ _GUID ProviderGuid;
	/*0020*/ USHORT EachEventTableOffset;
	/*0022*/ USHORT EachEventTableLength;
	/*0024*/ USHORT PayloadDecoderTableOffset;
	/*0026*/ USHORT PayloadDecoderTableLength;
	/*0028*/ USHORT EventFilterTableOffset;
	/*002a*/ USHORT EventFilterTableLength;
	/*002c*/ USHORT UNICODEStringTableOffset;
	/*002e*/ USHORT UNICODEStringTableLength;
	/*0030*/ USHORT ANSIStringTableOffset;
	/*0032*/ USHORT ANSIStringTableLength;
	/*0038*/ _EVENT_PAYLOAD_PREDICATE PredicateTable[0x1];
	/*0050*/
};

struct _ALPC_COMMUNICATION_INFO {
	/*0000*/ _ALPC_PORT * ConnectionPort;
	/*0008*/ _ALPC_PORT * ServerCommunicationPort;
	/*0010*/ _ALPC_PORT * ClientCommunicationPort;
	/*0018*/ _LIST_ENTRY CommunicationList;
	/*0028*/ _ALPC_HANDLE_TABLE HandleTable;
	/*0040*/ _KALPC_MESSAGE * CloseMessage;
	/*0048*/
};

struct _ALPC_COMPLETION_LIST {
	/*0000*/ _LIST_ENTRY Entry;
	/*0010*/ _EPROCESS * OwnerProcess;
	/*0018*/ _EX_PUSH_LOCK CompletionListLock;
	/*0020*/ _MDL * Mdl;
	/*0028*/ void * UserVa;
	/*0030*/ void * UserLimit;
	/*0038*/ void * DataUserVa;
	/*0040*/ void * SystemVa;
	/*0048*/ ULONGLONG TotalSize;
	/*0050*/ _ALPC_COMPLETION_LIST_HEADER * Header;
	/*0058*/ void * List;
	/*0060*/ ULONGLONG ListSize;
	/*0068*/ void * Bitmap;
	/*0070*/ ULONGLONG BitmapSize;
	/*0078*/ void * Data;
	/*0080*/ ULONGLONG DataSize;
	/*0088*/ ULONG BitmapLimit;
	/*008c*/ ULONG BitmapNextHint;
	/*0090*/ ULONG ConcurrencyCount;
	/*0094*/ ULONG AttributeFlags;
	/*0098*/ ULONG AttributeSize;
	/*00a0*/
};

struct _ALPC_COMPLETION_LIST_HEADER {
	/*0000*/ ULONGLONG StartMagic;
	/*0008*/ ULONG TotalSize;
	/*000c*/ ULONG ListOffset;
	/*0010*/ ULONG ListSize;
	/*0014*/ ULONG BitmapOffset;
	/*0018*/ ULONG BitmapSize;
	/*001c*/ ULONG DataOffset;
	/*0020*/ ULONG DataSize;
	/*0024*/ ULONG AttributeFlags;
	/*0028*/ ULONG AttributeSize;
	/*0040*/ _ALPC_COMPLETION_LIST_STATE volatile State;
	/*0048*/ ULONG volatile LastMessageId;
	/*004c*/ ULONG volatile LastCallbackId;
	/*0080*/ ULONG volatile PostCount;
	/*00c0*/ ULONG volatile ReturnCount;
	/*0100*/ ULONG volatile LogSequenceNumber;
	/*0140*/ _RTL_SRWLOCK UserLock;
	/*0148*/ ULONGLONG EndMagic;
	/*0180*/
};

struct _ALPC_COMPLETION_LIST_STATE {
	union {
		struct {
			/*0000*/ ULONGLONG Head : 24; // 0x0000000000ffffff;
			/*0000*/ ULONGLONG Tail : 24; // 0x0000ffffff000000;
			/*0000*/ ULONGLONG ActiveThreadCount : 16; // 0xffff000000000000;
			/*0008*/
		} s1;
		/*0000*/ LONGLONG Value;
		/*0008*/
	} u1;
	/*0008*/
};

struct _ALPC_COMPLETION_PACKET_LOOKASIDE {
	/*0000*/ ULONGLONG Lock;
	/*0008*/ ULONG Size;
	/*000c*/ ULONG ActiveCount;
	/*0010*/ ULONG PendingNullCount;
	/*0014*/ ULONG PendingCheckCompletionListCount;
	/*0018*/ ULONG PendingDelete;
	/*0020*/ _SINGLE_LIST_ENTRY FreeListHead;
	/*0028*/ void * CompletionPort;
	/*0030*/ void * CompletionKey;
	/*0038*/ _ALPC_COMPLETION_PACKET_LOOKASIDE_ENTRY Entry[0x1];
	/*0050*/
};

struct _ALPC_COMPLETION_PACKET_LOOKASIDE_ENTRY {
	/*0000*/ _SINGLE_LIST_ENTRY ListEntry;
	/*0008*/ _IO_MINI_COMPLETION_PACKET_USER * Packet;
	/*0010*/ _ALPC_COMPLETION_PACKET_LOOKASIDE * Lookaside;
	/*0018*/
};

struct _ALPC_DISPATCH_CONTEXT {
	/*0000*/ _ALPC_PORT * PortObject;
	/*0008*/ _KALPC_MESSAGE * Message;
	/*0010*/ _ALPC_COMMUNICATION_INFO * CommunicationInfo;
	/*0018*/ _ETHREAD * TargetThread;
	/*0020*/ _ALPC_PORT * TargetPort;
	/*0028*/ _KALPC_DIRECT_EVENT DirectEvent;
	/*0030*/ ULONG Flags;
	/*0034*/ USHORT TotalLength;
	/*0036*/ USHORT Type;
	/*0038*/ USHORT DataInfoOffset;
	/*003a*/ UCHAR SignalCompletion;
	/*003b*/ UCHAR PostedToCompletionList;
	/*0040*/
};

struct _ALPC_HANDLE_ENTRY {
	/*0000*/ void * Object;
	/*0008*/
};

struct _ALPC_HANDLE_TABLE {
	/*0000*/ _ALPC_HANDLE_ENTRY * Handles;
	/*0008*/ ULONG TotalHandles;
	/*000c*/ ULONG Flags;
	/*0010*/ _EX_PUSH_LOCK Lock;
	/*0018*/
};

struct _ALPC_MESSAGE_ATTRIBUTES {
	/*0000*/ ULONG AllocatedAttributes;
	/*0004*/ ULONG ValidAttributes;
	/*0008*/
};

struct _ALPC_PORT {
	/*0000*/ _LIST_ENTRY PortListEntry;
	/*0010*/ _ALPC_COMMUNICATION_INFO * CommunicationInfo;
	/*0018*/ _EPROCESS * OwnerProcess;
	/*0020*/ void * CompletionPort;
	/*0028*/ void * CompletionKey;
	/*0030*/ _ALPC_COMPLETION_PACKET_LOOKASIDE * CompletionPacketLookaside;
	/*0038*/ void * PortContext;
	/*0040*/ _SECURITY_CLIENT_CONTEXT StaticSecurity;
	/*0088*/ _EX_PUSH_LOCK IncomingQueueLock;
	/*0090*/ _LIST_ENTRY MainQueue;
	/*00a0*/ _LIST_ENTRY LargeMessageQueue;
	/*00b0*/ _EX_PUSH_LOCK PendingQueueLock;
	/*00b8*/ _LIST_ENTRY PendingQueue;
	/*00c8*/ _EX_PUSH_LOCK DirectQueueLock;
	/*00d0*/ _LIST_ENTRY DirectQueue;
	/*00e0*/ _EX_PUSH_LOCK WaitQueueLock;
	/*00e8*/ _LIST_ENTRY WaitQueue;
	/*00f8*/ _KSEMAPHORE * Semaphore;
	/*00f8*/ _KEVENT * DummyEvent;
	/*0100*/ _ALPC_PORT_ATTRIBUTES PortAttributes;
	/*0148*/ _EX_PUSH_LOCK ResourceListLock;
	/*0150*/ _LIST_ENTRY ResourceListHead;
	/*0160*/ _EX_PUSH_LOCK PortObjectLock;
	/*0168*/ _ALPC_COMPLETION_LIST * CompletionList;
	/*0170*/ _CALLBACK_OBJECT * CallbackObject;
	/*0178*/ void * CallbackContext;
	/*0180*/ _LIST_ENTRY CanceledQueue;
	/*0190*/ LONG SequenceNo;
	/*0194*/ LONG ReferenceNo;
	/*0198*/ _PALPC_PORT_REFERENCE_WAIT_BLOCK * ReferenceNoWait;
	union {
		struct {
			/*01a0*/ ULONG Initialized : 01; // 0x00000001;
			/*01a0*/ ULONG Type : 02; // 0x00000006;
			/*01a0*/ ULONG ConnectionPending : 01; // 0x00000008;
			/*01a0*/ ULONG ConnectionRefused : 01; // 0x00000010;
			/*01a0*/ ULONG Disconnected : 01; // 0x00000020;
			/*01a0*/ ULONG Closed : 01; // 0x00000040;
			/*01a0*/ ULONG NoFlushOnClose : 01; // 0x00000080;
			/*01a0*/ ULONG ReturnExtendedInfo : 01; // 0x00000100;
			/*01a0*/ ULONG Waitable : 01; // 0x00000200;
			/*01a0*/ ULONG DynamicSecurity : 01; // 0x00000400;
			/*01a0*/ ULONG Wow64CompletionList : 01; // 0x00000800;
			/*01a0*/ ULONG Lpc : 01; // 0x00001000;
			/*01a0*/ ULONG LpcToLpc : 01; // 0x00002000;
			/*01a0*/ ULONG HasCompletionList : 01; // 0x00004000;
			/*01a0*/ ULONG HadCompletionList : 01; // 0x00008000;
			/*01a0*/ ULONG EnableCompletionList : 01; // 0x00010000;
			/*01a4*/
		} s1;
		/*01a0*/ ULONG State;
		/*01a4*/
	} u1;
	/*01a8*/ _ALPC_PORT * TargetQueuePort;
	/*01b0*/ _ALPC_PORT * TargetSequencePort;
	/*01b8*/ _KALPC_MESSAGE * CachedMessage;
	/*01c0*/ ULONG MainQueueLength;
	/*01c4*/ ULONG LargeMessageQueueLength;
	/*01c8*/ ULONG PendingQueueLength;
	/*01cc*/ ULONG DirectQueueLength;
	/*01d0*/ ULONG CanceledQueueLength;
	/*01d4*/ ULONG WaitQueueLength;
	/*01d8*/
};

struct _ALPC_PORT_ATTRIBUTES {
	/*0000*/ ULONG Flags;
	/*0004*/ _SECURITY_QUALITY_OF_SERVICE SecurityQos;
	/*0010*/ ULONGLONG MaxMessageLength;
	/*0018*/ ULONGLONG MemoryBandwidth;
	/*0020*/ ULONGLONG MaxPoolUsage;
	/*0028*/ ULONGLONG MaxSectionSize;
	/*0030*/ ULONGLONG MaxViewSize;
	/*0038*/ ULONGLONG MaxTotalSectionSize;
	/*0040*/ ULONG DupObjectTypes;
	/*0044*/ ULONG Reserved;
	/*0048*/
};

struct _ALPC_PROCESS_CONTEXT {
	/*0000*/ _EX_PUSH_LOCK Lock;
	/*0008*/ _LIST_ENTRY ViewListHead;
	/*0018*/ ULONGLONG volatile PagedPoolQuotaCache;
	/*0020*/
};

struct _ALPC_WORK_ON_BEHALF_TICKET {
	/*0000*/ ULONG ThreadId;
	/*0004*/ ULONG ThreadCreationTimeLow;
	/*0008*/
};

enum _ALTERNATIVE_ARCHITECTURE_TYPE {
	StandardDesign = 0x0,
	NEC98x86 = 0x1,
	EndAlternatives = 0x2
};

struct _AMD64_DBGKD_CONTROL_SET {
	/*0000*/ ULONG TraceFlag;
	/*0004*/ ULONGLONG Dr7;
	/*000c*/ ULONGLONG CurrentSymbolStart;
	/*0014*/ ULONGLONG CurrentSymbolEnd;
	/*001c*/
};

enum _ARBITER_ACTION {
	ArbiterActionTestAllocation = 0x0,
	ArbiterActionRetestAllocation = 0x1,
	ArbiterActionCommitAllocation = 0x2,
	ArbiterActionRollbackAllocation = 0x3,
	ArbiterActionQueryAllocatedResources = 0x4,
	ArbiterActionWriteReservedResources = 0x5,
	ArbiterActionQueryConflict = 0x6,
	ArbiterActionQueryArbitrate = 0x7,
	ArbiterActionAddReserved = 0x8,
	ArbiterActionBootAllocation = 0x9
};

struct _ARBITER_ADD_RESERVED_PARAMETERS {
	/*0000*/ _DEVICE_OBJECT * ReserveDevice;
	/*0008*/
};

struct _ARBITER_ALLOCATION_STATE {
	/*0000*/ ULONGLONG Start;
	/*0008*/ ULONGLONG End;
	/*0010*/ ULONGLONG CurrentMinimum;
	/*0018*/ ULONGLONG CurrentMaximum;
	/*0020*/ _ARBITER_LIST_ENTRY * Entry;
	/*0028*/ _ARBITER_ALTERNATIVE * CurrentAlternative;
	/*0030*/ ULONG AlternativeCount;
	/*0038*/ _ARBITER_ALTERNATIVE * Alternatives;
	/*0040*/ USHORT Flags;
	/*0042*/ UCHAR RangeAttributes;
	/*0043*/ UCHAR RangeAvailableAttributes;
	/*0048*/ ULONGLONG WorkSpace;
	/*0050*/
};

struct _ARBITER_ALTERNATIVE {
	/*0000*/ ULONGLONG Minimum;
	/*0008*/ ULONGLONG Maximum;
	/*0010*/ ULONGLONG Length;
	/*0018*/ ULONGLONG Alignment;
	/*0020*/ LONG Priority;
	/*0024*/ ULONG Flags;
	/*0028*/ _IO_RESOURCE_DESCRIPTOR * Descriptor;
	/*0030*/ ULONG Reserved[0x3];
	/*0040*/
};

struct _ARBITER_BOOT_ALLOCATION_PARAMETERS {
	/*0000*/ _LIST_ENTRY * ArbitrationList;
	/*0008*/
};

struct _ARBITER_CONFLICT_INFO {
	/*0000*/ _DEVICE_OBJECT * OwningObject;
	/*0008*/ ULONGLONG Start;
	/*0010*/ ULONGLONG End;
	/*0018*/
};

struct _ARBITER_INSTANCE {
	/*0000*/ ULONG Signature;
	/*0008*/ _KEVENT * MutexEvent;
	/*0010*/ WCHAR * Name;
	/*0018*/ WCHAR * OrderingName;
	/*0020*/ INT ResourceType;
	/*0028*/ _RTL_RANGE_LIST * Allocation;
	/*0030*/ _RTL_RANGE_LIST * PossibleAllocation;
	/*0038*/ _ARBITER_ORDERING_LIST OrderingList;
	/*0048*/ _ARBITER_ORDERING_LIST ReservedList;
	/*0058*/ LONG ReferenceCount;
	/*0060*/ _ARBITER_INTERFACE * Interface;
	/*0068*/ ULONG AllocationStackMaxSize;
	/*0070*/ _ARBITER_ALLOCATION_STATE * AllocationStack;
	/*0078*/ LONG (* UnpackRequirement)( _IO_RESOURCE_DESCRIPTOR * , ULONGLONG * , ULONGLONG * , ULONGLONG * , ULONGLONG * );
	/*0080*/ LONG (* PackResource)( _IO_RESOURCE_DESCRIPTOR * , ULONGLONG , _CM_PARTIAL_RESOURCE_DESCRIPTOR * );
	/*0088*/ LONG (* UnpackResource)( _CM_PARTIAL_RESOURCE_DESCRIPTOR * , ULONGLONG * , ULONGLONG * );
	/*0090*/ LONG (* ScoreRequirement)( _IO_RESOURCE_DESCRIPTOR * );
	/*0098*/ LONG (* TestAllocation)( _ARBITER_INSTANCE * , _ARBITER_TEST_ALLOCATION_PARAMETERS * );
	/*00a0*/ LONG (* RetestAllocation)( _ARBITER_INSTANCE * , _ARBITER_RETEST_ALLOCATION_PARAMETERS * );
	/*00a8*/ LONG (* CommitAllocation)( _ARBITER_INSTANCE * );
	/*00b0*/ LONG (* RollbackAllocation)( _ARBITER_INSTANCE * );
	/*00b8*/ LONG (* BootAllocation)( _ARBITER_INSTANCE * , _ARBITER_BOOT_ALLOCATION_PARAMETERS * );
	/*00c0*/ LONG (* QueryArbitrate)( _ARBITER_INSTANCE * , _ARBITER_QUERY_ARBITRATE_PARAMETERS * );
	/*00c8*/ LONG (* QueryConflict)( _ARBITER_INSTANCE * , _ARBITER_QUERY_CONFLICT_PARAMETERS * );
	/*00d0*/ LONG (* AddReserved)( _ARBITER_INSTANCE * , _ARBITER_ADD_RESERVED_PARAMETERS * );
	/*00d8*/ LONG (* StartArbiter)( _ARBITER_INSTANCE * , _CM_RESOURCE_LIST * );
	/*00e0*/ LONG (* PreprocessEntry)( _ARBITER_INSTANCE * , _ARBITER_ALLOCATION_STATE * );
	/*00e8*/ LONG (* AllocateEntry)( _ARBITER_INSTANCE * , _ARBITER_ALLOCATION_STATE * );
	/*00f0*/ UCHAR (* GetNextAllocationRange)( _ARBITER_INSTANCE * , _ARBITER_ALLOCATION_STATE * );
	/*00f8*/ UCHAR (* FindSuitableRange)( _ARBITER_INSTANCE * , _ARBITER_ALLOCATION_STATE * );
	/*0100*/ void (* AddAllocation)( _ARBITER_INSTANCE * , _ARBITER_ALLOCATION_STATE * );
	/*0108*/ void (* BacktrackAllocation)( _ARBITER_INSTANCE * , _ARBITER_ALLOCATION_STATE * );
	/*0110*/ UCHAR (* OverrideConflict)( _ARBITER_INSTANCE * , _ARBITER_ALLOCATION_STATE * );
	/*0118*/ LONG (* InitializeRangeList)( _ARBITER_INSTANCE * , ULONG , _CM_PARTIAL_RESOURCE_DESCRIPTOR * , _RTL_RANGE_LIST * );
	/*0120*/ UCHAR TransactionInProgress;
	/*0128*/ _KEVENT * TransactionEvent;
	/*0130*/ void * Extension;
	/*0138*/ _DEVICE_OBJECT * BusDeviceObject;
	/*0140*/ void * ConflictCallbackContext;
	/*0148*/ UCHAR (* ConflictCallback)( void * , _RTL_RANGE * );
	/*0150*/
};

struct _ARBITER_INTERFACE {
	/*0000*/ USHORT Size;
	/*0002*/ USHORT Version;
	/*0008*/ void * Context;
	/*0010*/ void (* InterfaceReference)( void * );
	/*0018*/ void (* InterfaceDereference)( void * );
	/*0020*/ LONG (* ArbiterHandler)( void * , _ARBITER_ACTION , _ARBITER_PARAMETERS * );
	/*0028*/ ULONG Flags;
	/*0030*/
};

struct _ARBITER_LIST_ENTRY {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ ULONG AlternativeCount;
	/*0018*/ _IO_RESOURCE_DESCRIPTOR * Alternatives;
	/*0020*/ _DEVICE_OBJECT * PhysicalDeviceObject;
	/*0028*/ _ARBITER_REQUEST_SOURCE RequestSource;
	/*002c*/ ULONG Flags;
	/*0030*/ LONGLONG WorkSpace;
	/*0038*/ _INTERFACE_TYPE InterfaceType;
	/*003c*/ ULONG SlotNumber;
	/*0040*/ ULONG BusNumber;
	/*0048*/ _CM_PARTIAL_RESOURCE_DESCRIPTOR * Assignment;
	/*0050*/ _IO_RESOURCE_DESCRIPTOR * SelectedAlternative;
	/*0058*/ _ARBITER_RESULT Result;
	/*0060*/
};

struct _ARBITER_ORDERING {
	/*0000*/ ULONGLONG Start;
	/*0008*/ ULONGLONG End;
	/*0010*/
};

struct _ARBITER_ORDERING_LIST {
	/*0000*/ USHORT Count;
	/*0002*/ USHORT Maximum;
	/*0008*/ _ARBITER_ORDERING * Orderings;
	/*0010*/
};

struct _ARBITER_PARAMETERS {
	union {
		/*0000*/ _ARBITER_TEST_ALLOCATION_PARAMETERS TestAllocation;
		/*0000*/ _ARBITER_RETEST_ALLOCATION_PARAMETERS RetestAllocation;
		/*0000*/ _ARBITER_BOOT_ALLOCATION_PARAMETERS BootAllocation;
		/*0000*/ _ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS QueryAllocatedResources;
		/*0000*/ _ARBITER_QUERY_CONFLICT_PARAMETERS QueryConflict;
		/*0000*/ _ARBITER_QUERY_ARBITRATE_PARAMETERS QueryArbitrate;
		/*0000*/ _ARBITER_ADD_RESERVED_PARAMETERS AddReserved;
		/*0020*/
	} Parameters;
	/*0020*/
};

struct _ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS {
	/*0000*/ _CM_PARTIAL_RESOURCE_LIST * * AllocatedResources;
	/*0008*/
};

struct _ARBITER_QUERY_ARBITRATE_PARAMETERS {
	/*0000*/ _LIST_ENTRY * ArbitrationList;
	/*0008*/
};

struct _ARBITER_QUERY_CONFLICT_PARAMETERS {
	/*0000*/ _DEVICE_OBJECT * PhysicalDeviceObject;
	/*0008*/ _IO_RESOURCE_DESCRIPTOR * ConflictingResource;
	/*0010*/ ULONG * ConflictCount;
	/*0018*/ _ARBITER_CONFLICT_INFO * * Conflicts;
	/*0020*/
};

enum _ARBITER_REQUEST_SOURCE {
	ArbiterRequestUndefined = 0xffffffff,
	ArbiterRequestLegacyReported = 0x0,
	ArbiterRequestHalReported = 0x1,
	ArbiterRequestLegacyAssigned = 0x2,
	ArbiterRequestPnpDetected = 0x3,
	ArbiterRequestPnpEnumerated = 0x4
};

enum _ARBITER_RESULT {
	ArbiterResultUndefined = 0xffffffff,
	ArbiterResultSuccess = 0x0,
	ArbiterResultExternalConflict = 0x1,
	ArbiterResultNullRequest = 0x2
};

struct _ARBITER_RETEST_ALLOCATION_PARAMETERS {
	/*0000*/ _LIST_ENTRY * ArbitrationList;
	/*0008*/ ULONG AllocateFromCount;
	/*0010*/ _CM_PARTIAL_RESOURCE_DESCRIPTOR * AllocateFrom;
	/*0018*/
};

struct _ARBITER_TEST_ALLOCATION_PARAMETERS {
	/*0000*/ _LIST_ENTRY * ArbitrationList;
	/*0008*/ ULONG AllocateFromCount;
	/*0010*/ _CM_PARTIAL_RESOURCE_DESCRIPTOR * AllocateFrom;
	/*0018*/
};

struct _ARM64_DBGKD_CONTROL_SET {
	/*0000*/ ULONG Continue;
	/*0004*/ ULONG TraceFlag;
	/*0008*/ ULONGLONG CurrentSymbolStart;
	/*0010*/ ULONGLONG CurrentSymbolEnd;
	/*0018*/
};

struct _ARMCE_DBGKD_CONTROL_SET {
	/*0000*/ ULONG Continue;
	/*0004*/ ULONG CurrentSymbolStart;
	/*0008*/ ULONG CurrentSymbolEnd;
	/*000c*/
};

struct _ARM_DBGKD_CONTROL_SET {
	/*0000*/ ULONG Continue;
	/*0004*/ ULONG CurrentSymbolStart;
	/*0008*/ ULONG CurrentSymbolEnd;
	/*000c*/
};

struct _ASSEMBLY_STORAGE_MAP;

struct _ASYNC_READ_THREAD_STATS {
	/*0000*/ ULONG CurrentLoad[0x65];
	/*0194*/
};

struct _AUTHZBASEP_CLAIM_ATTRIBUTES_COLLECTION {
	/*0000*/ ULONG DeviceGroupsCount;
	/*0008*/ _SID_AND_ATTRIBUTES * pDeviceGroups;
	/*0010*/ ULONG RestrictedDeviceGroupsCount;
	/*0018*/ _SID_AND_ATTRIBUTES * pRestrictedDeviceGroups;
	/*0020*/ _SID_AND_ATTRIBUTES_HASH DeviceGroupsHash;
	/*0130*/ _SID_AND_ATTRIBUTES_HASH RestrictedDeviceGroupsHash;
	/*0240*/ _AUTHZBASEP_SECURITY_ATTRIBUTES_INFORMATION * pUserSecurityAttributes;
	/*0248*/ _AUTHZBASEP_SECURITY_ATTRIBUTES_INFORMATION * pDeviceSecurityAttributes;
	/*0250*/ _AUTHZBASEP_SECURITY_ATTRIBUTES_INFORMATION * pRestrictedUserSecurityAttributes;
	/*0258*/ _AUTHZBASEP_SECURITY_ATTRIBUTES_INFORMATION * pRestrictedDeviceSecurityAttributes;
	/*0260*/
};

struct _AUTHZBASEP_SECURITY_ATTRIBUTES_INFORMATION {
	/*0000*/ ULONG SecurityAttributeCount;
	/*0008*/ _LIST_ENTRY SecurityAttributesList;
	/*0018*/ ULONG WorkingSecurityAttributeCount;
	/*0020*/ _LIST_ENTRY WorkingSecurityAttributesList;
	/*0030*/
};

struct _AUX_ACCESS_DATA {
	/*0000*/ _PRIVILEGE_SET * PrivilegesUsed;
	/*0008*/ _GENERIC_MAPPING GenericMapping;
	/*0018*/ ULONG AccessesToAudit;
	/*001c*/ ULONG MaximumAuditMask;
	/*0020*/ _GUID TransactionId;
	/*0030*/ void * NewSecurityDescriptor;
	/*0038*/ void * ExistingSecurityDescriptor;
	/*0040*/ void * ParentSecurityDescriptor;
	/*0048*/ void (* DeRefSecurityDescriptor)( void * , void * );
	/*0050*/ void * SDLock;
	/*0058*/ _ACCESS_REASONS AccessReasons;
	/*00d8*/ UCHAR GenerateStagingEvents;
	/*00e0*/
};

struct _BITMAP_RANGE {
	/*0000*/ _LIST_ENTRY Links;
	/*0010*/ LONGLONG BasePage;
	/*0018*/ ULONG FirstDirtyPage;
	/*001c*/ ULONG LastDirtyPage;
	/*0020*/ ULONG DirtyPages;
	/*0028*/ ULONG * Bitmap;
	/*0030*/
};

struct _BLOB {
	/*0000*/ _LIST_ENTRY ResourceList;
	/*0000*/ _SLIST_ENTRY FreeListEntry;
	union {
		struct {
			/*0010*/ UCHAR ReferenceCache : 01; // 0x01;
			/*0010*/ UCHAR Lookaside : 01; // 0x02;
			/*0010*/ UCHAR Initializing : 01; // 0x04;
			/*0010*/ UCHAR Deleted : 01; // 0x08;
			/*0011*/
		} s1;
		/*0010*/ UCHAR Flags;
		/*0011*/
	} u1;
	/*0011*/ UCHAR ResourceId;
	/*0012*/ SHORT CachedReferences;
	/*0018*/ LONGLONG ReferenceCount;
	/*0020*/ _EX_PUSH_LOCK Lock;
	/*0030*/
};

struct _BLOB_COUNTERS {
	/*0000*/ ULONG CreatedObjects;
	/*0004*/ ULONG DeletedObjects;
	/*0008*/
};

enum _BLOB_ID {
	BLOB_TYPE_UNKNOWN = 0x0,
	BLOB_TYPE_CONNECTION_INFO = 0x1,
	BLOB_TYPE_MESSAGE = 0x2,
	BLOB_TYPE_SECURITY_CONTEXT = 0x3,
	BLOB_TYPE_SECTION = 0x4,
	BLOB_TYPE_REGION = 0x5,
	BLOB_TYPE_VIEW = 0x6,
	BLOB_TYPE_RESERVE = 0x7,
	BLOB_TYPE_DIRECT_TRANSFER = 0x8,
	BLOB_TYPE_HANDLE_DATA = 0x9,
	BLOB_TYPE_MAX_ID = 0xa
};

struct _BLOB_TYPE {
	/*0000*/ _BLOB_ID ResourceId;
	/*0004*/ ULONG PoolTag;
	/*0008*/ ULONG LookasideIndex;
	/*000c*/ ULONG Flags;
	/*0010*/ _BLOB_COUNTERS * Counters;
	/*0018*/ void (* DeleteProcedure)( void * );
	/*0020*/ LONG (* DestroyProcedure)( void * );
	/*0028*/ ULONGLONG UsualSize;
	/*0030*/
};

struct _BUS_EXTENSION_LIST {
	/*0000*/ void * Next;
	/*0008*/ _PI_BUS_EXTENSION * BusExtension;
	/*0010*/
};

struct _CACHED_CHILD_LIST {
	/*0000*/ ULONG Count;
	/*0008*/ ULONGLONG ValueList;
	/*0008*/ _CM_KEY_CONTROL_BLOCK * RealKcb;
	/*0010*/
};

struct _CACHED_KSTACK_LIST {
	/*0000*/ _SLIST_HEADER SListHead;
	/*0010*/ LONG MinimumFree;
	/*0014*/ ULONG Misses;
	/*0018*/ ULONG MissesLast;
	/*001c*/ ULONG AllStacksInUse;
	/*0020*/
};

struct _CACHE_DESCRIPTOR {
	/*0000*/ UCHAR Level;
	/*0001*/ UCHAR Associativity;
	/*0002*/ USHORT LineSize;
	/*0004*/ ULONG Size;
	/*0008*/ _PROCESSOR_CACHE_TYPE Type;
	/*000c*/
};

struct _CACHE_MANAGER_CALLBACKS {
	/*0000*/ UCHAR (* AcquireForLazyWrite)( void * , UCHAR );
	/*0008*/ void (* ReleaseFromLazyWrite)( void * );
	/*0010*/ UCHAR (* AcquireForReadAhead)( void * , UCHAR );
	/*0018*/ void (* ReleaseFromReadAhead)( void * );
	/*0020*/
};

struct _CACHE_UNINITIALIZE_EVENT {
	/*0000*/ _CACHE_UNINITIALIZE_EVENT * Next;
	/*0008*/ _KEVENT Event;
	/*0020*/
};

struct _CALLBACK_OBJECT;

struct _CALL_HASH_ENTRY {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ void * CallersAddress;
	/*0018*/ void * CallersCaller;
	/*0020*/ ULONG CallCount;
	/*0028*/
};

struct _CALL_PERFORMANCE_DATA {
	/*0000*/ ULONGLONG SpinLock;
	/*0008*/ _LIST_ENTRY HashTable[0x40];
	/*0408*/
};

struct _CC_ASYNC_READ_CONTEXT {
	/*0000*/ UCHAR (* CompletionRoutine)( void * );
	/*0008*/ void * Context;
	/*0010*/ _MDL * Mdl;
	/*0018*/ CHAR RequestorMode;
	/*001c*/ ULONG NestingLevel;
	/*0020*/
};

struct _CC_EXTERNAL_CACHE_INFO {
	/*0000*/ void (* Callback)( void * , ULONGLONG , ULONG );
	/*0008*/ _DIRTY_PAGE_STATISTICS DirtyPageStatistics;
	/*0020*/ _LIST_ENTRY Links;
	/*0030*/
};

struct _CC_PARTITION {
	/*0000*/ SHORT NodeTypeCode;
	/*0002*/ SHORT NodeByteSize;
	/*0008*/ _EPARTITION * PartitionObject;
	/*0010*/ _LIST_ENTRY CleanSharedCacheMapList;
	/*0020*/ _LIST_ENTRY CleanSharedCacheMapWithLogHandleList;
	/*0030*/ _SHARED_CACHE_MAP_LIST_CURSOR DirtySharedCacheMapList;
	/*0048*/ _SHARED_CACHE_MAP_LIST_CURSOR LazyWriteCursor;
	/*0060*/ _LIST_ENTRY DirtySharedCacheMapWithLogHandleList;
	/*0080*/ ULONGLONG PrivateLock;
	/*0088*/ ULONG ConsecutiveWorklessLazyScanCount;
	/*008c*/ UCHAR ForcedDisableLazywriteScan;
	/*00c0*/ ULONGLONG WorkQueueLock;
	/*00c8*/ ULONG NumberWorkerThreads;
	/*00cc*/ ULONG NumberActiveWorkerThreads;
	/*00d0*/ _LIST_ENTRY IdleWorkerThreadList;
	/*00e0*/ _LIST_ENTRY FastTeardownWorkQueue;
	/*00f0*/ _LIST_ENTRY ExpressWorkQueue;
	/*0100*/ _LIST_ENTRY RegularWorkQueue;
	/*0110*/ _LIST_ENTRY PostTickWorkQueue;
	/*0120*/ _LIST_ENTRY IdleExtraWriteBehindThreadList;
	/*0130*/ ULONG ActiveExtraWriteBehindThreads;
	/*0134*/ ULONG MaxExtraWriteBehindThreads;
	/*0138*/ UCHAR QueueThrottle;
	/*013c*/ ULONG PostTickWorkItemCount;
	/*0140*/ ULONG ThreadsActiveBeforeThrottle;
	/*0144*/ ULONG ExtraWBThreadsActiveBeforeThrottle;
	/*0148*/ ULONG ExecutingWriteBehindWorkItems;
	/*014c*/ ULONG ExecutingHighPriorityWorkItem;
	/*0150*/ _KEVENT LowMemoryEvent;
	/*0168*/ _KEVENT PowerEvent;
	/*0180*/ _KEVENT PeriodicEvent;
	/*0198*/ _KEVENT WaitingForTeardownEvent;
	/*01b0*/ _KEVENT CoalescingFlushEvent;
	/*01c8*/ ULONG PagesYetToWrite;
	/*01d0*/ _LAZY_WRITER LazyWriter;
	/*0258*/ _DIRTY_PAGE_STATISTICS DirtyPageStatistics;
	/*0270*/ _DIRTY_PAGE_THRESHOLDS DirtyPageThresholds;
	/*02a8*/ _WRITE_BEHIND_THROUGHPUT * ThroughputStats;
	/*02b0*/ LONG ThroughputTrend;
	/*02b8*/ ULONGLONG AverageAvailablePages;
	/*02c0*/ ULONGLONG AverageDirtyPages;
	/*02c8*/ ULONGLONG PagesSkippedDueToHotSpot;
	/*02d0*/ _LARGE_INTEGER PrevRegularQueueItemRunTime;
	/*02d8*/ _LARGE_INTEGER PrevExtraWBThreadCheckTime;
	/*02e0*/ UCHAR AddExtraWriteBehindThreads;
	/*02e1*/ UCHAR RemoveExtraThreadPending;
	/*02e8*/ _LIST_ENTRY DeferredWrites;
	/*0300*/ ULONGLONG DeferredWriteSpinLock;
	/*0308*/ _LIST_ENTRY * IdleAsyncReadWorkerThreadList;
	/*0310*/ ULONG * NumberActiveAsyncReadWorkerThreads;
	/*0318*/ ULONG * NumberActiveCompleteAsyncReadWorkItems;
	/*0320*/ _LIST_ENTRY * AsyncReadWorkQueue;
	/*0328*/ _LIST_ENTRY * AsyncReadCompletionWorkQueue;
	/*0330*/ _KEVENT * NewAsyncReadRequestEvent;
	/*0338*/ _ASYNC_READ_THREAD_STATS * ReaderThreadsStats;
	/*0340*/ _EX_PUSH_LOCK AsyncReadWorkQueueLock;
	/*0348*/ _LIST_ENTRY VacbFreeHighPriorityList;
	/*0358*/ ULONG NumberOfFreeHighPriorityVacbs;
	/*0360*/ _ETHREAD * LowPriWorkerThread;
	/*0368*/ _SHARED_CACHE_MAP * LowPriSharedCacheMap;
	/*0370*/ LONG LowPriOldCpuPriority;
	/*0374*/ _IO_PRIORITY_HINT LowPriOldIoPriority;
	/*0378*/ _EX_PUSH_LOCK LowPriorityWorkerThreadLock;
	/*0380*/ ULONG MaxNumberOfWriteBehindThreads;
	/*0384*/ UCHAR CoalescingState;
	/*0385*/ UCHAR RundownStarted;
	/*0388*/ LONGLONG RefCount;
	/*0390*/ _KEVENT ExitEvent;
	/*03a8*/ _KEVENT FinalDereferenceEvent;
	/*03c0*/ void * LazyWriteScanThreadHandle;
	/*0400*/
};

struct _CELL_DATA {
	/*0000*/ _u u;
	/*0050*/
};

struct _CHILD_LIST {
	/*0000*/ ULONG Count;
	/*0004*/ ULONG List;
	/*0008*/
};

struct _CI_NGEN_PATHS;

struct _CLIENT_ID {
	/*0000*/ void * UniqueProcess;
	/*0008*/ void * UniqueThread;
	/*0010*/
};

struct _CLIENT_ID32 {
	/*0000*/ ULONG UniqueProcess;
	/*0004*/ ULONG UniqueThread;
	/*0008*/
};

struct _CLIENT_ID64 {
	/*0000*/ ULONGLONG UniqueProcess;
	/*0008*/ ULONGLONG UniqueThread;
	/*0010*/
};

union _CLS_LSN {
	struct {
		/*0000*/ UINT idxRecord;
		/*0004*/ ULONG cidContainer;
		/*0008*/
	} offset;
	/*0000*/ ULONGLONG ullOffset;
	/*0008*/
};

struct _CMHIVE {
	/*0000*/ _HHIVE Hive;
	/*0a68*/ void * FileHandles[0x6];
	/*0a98*/ _LIST_ENTRY NotifyList;
	/*0aa8*/ _LIST_ENTRY HiveList;
	/*0ab8*/ _LIST_ENTRY PreloadedHiveList;
	/*0ac8*/ _LIST_ENTRY FailedUnloadList;
	/*0ad8*/ _EX_RUNDOWN_REF HiveRundown;
	/*0ae0*/ _LIST_ENTRY ParseCacheEntries;
	/*0af0*/ _CM_KEY_HASH_TABLE_ENTRY * KcbCacheTable;
	/*0af8*/ ULONG KcbCacheTableSize;
	/*0b00*/ _CM_KEY_HASH_TABLE_ENTRY * DeletedKcbTable;
	/*0b08*/ ULONG DeletedKcbTableSize;
	/*0b0c*/ ULONG Identity;
	/*0b10*/ _FAST_MUTEX * HiveLock;
	/*0b18*/ _FAST_MUTEX * WriterLock;
	/*0b20*/ _ERESOURCE * FlusherLock;
	/*0b28*/ _RTL_BITMAP FlushDirtyVector;
	/*0b38*/ ULONG FlushDirtyVectorSize;
	/*0b40*/ UCHAR * FlushLogEntry;
	/*0b48*/ ULONG FlushLogEntrySize;
	/*0b4c*/ ULONG FlushHiveTruncated;
	/*0b50*/ UCHAR FlushBaseBlockDirty;
	/*0b58*/ _RTL_BITMAP CapturedUnreconciledVector;
	/*0b68*/ ULONG CapturedUnreconciledVectorSize;
	/*0b70*/ CMP_OFFSET_ARRAY * UnreconciledOffsetArray;
	/*0b78*/ ULONG UnreconciledOffsetArrayCount;
	/*0b80*/ _HBASE_BLOCK * UnreconciledBaseBlock;
	/*0b88*/ _EX_PUSH_LOCK SecurityLock;
	/*0b90*/ ULONG UseCount;
	/*0b94*/ ULONG LastShrinkHiveSize;
	/*0b98*/ _LARGE_INTEGER ActualFileSize;
	/*0ba0*/ _LARGE_INTEGER LogFileSizes[0x2];
	/*0bb0*/ _UNICODE_STRING FileFullPath;
	/*0bc0*/ _UNICODE_STRING FileUserName;
	/*0bd0*/ _UNICODE_STRING HiveRootPath;
	/*0be0*/ ULONG SecurityCount;
	/*0be4*/ ULONG SecurityCacheSize;
	/*0be8*/ LONG SecurityHitHint;
	/*0bf0*/ _CM_KEY_SECURITY_CACHE_ENTRY * SecurityCache;
	/*0bf8*/ _LIST_ENTRY SecurityHash[0x40];
	/*0ff8*/ ULONG UnloadEventCount;
	/*1000*/ _KEVENT * * UnloadEventArray;
	/*1008*/ _CM_KEY_CONTROL_BLOCK * RootKcb;
	/*1010*/ UCHAR Frozen;
	/*1018*/ _CM_WORKITEM * UnloadWorkItem;
	/*1020*/ _CM_WORKITEM UnloadWorkItemHolder;
	/*1048*/ UCHAR GrowOnlyMode;
	/*104c*/ ULONG GrowOffset;
	/*1050*/ _LIST_ENTRY KcbConvertListHead;
	/*1060*/ _CM_CELL_REMAP_BLOCK * CellRemapArray;
	/*1068*/ _CM_DIRTY_VECTOR_LOG DirtyVectorLog;
	/*14f0*/ ULONG Flags;
	/*14f8*/ _LIST_ENTRY TrustClassEntry;
	/*1508*/ ULONGLONG DirtyTime;
	/*1510*/ ULONGLONG UnreconciledTime;
	/*1518*/ _CM_RM * CmRm;
	/*1520*/ ULONG CmRmInitFailPoint;
	/*1524*/ LONG CmRmInitFailStatus;
	/*1528*/ _KTHREAD * CreatorOwner;
	/*1530*/ _KTHREAD * RundownThread;
	/*1538*/ _LARGE_INTEGER LastWriteTime;
	/*1540*/ _HIVE_WRITE_WAIT_QUEUE FlushQueue;
	/*1558*/ _HIVE_WRITE_WAIT_QUEUE ReconcileQueue;
	/*1570*/ ULONG FlushFlags;
	/*1570*/ ULONG FlushActive : 01; // 0x00000001;
	/*1570*/ ULONG ReconcileActive : 01; // 0x00000002;
	/*1570*/ ULONG PrimaryFilePurged : 01; // 0x00000004;
	/*1570*/ ULONG DiskFileBad : 01; // 0x00000008;
	/*1574*/ ULONG PrimaryFileSizeBeforeLastFlush;
	/*1578*/ LONG volatile ReferenceCount;
	/*157c*/ LONG UnloadHistoryIndex;
	/*1580*/ ULONG UnloadHistory[0x80];
	/*1780*/ ULONG BootStart;
	/*1784*/ ULONG UnaccessedStart;
	/*1788*/ ULONG UnaccessedEnd;
	/*178c*/ ULONG LoadedKeyCount;
	/*1790*/ ULONG volatile HandleClosePending;
	/*1798*/ _EX_PUSH_LOCK HandleClosePendingEvent;
	/*17a0*/ UCHAR FinalFlushSucceeded;
	/*17a1*/ UCHAR FailedUnload;
	/*17a8*/
};

struct _CMP_DISCARD_AND_REPLACE_KCB_CONTEXT {
	/*0000*/ _CM_KEY_CONTROL_BLOCK * BaseKcb;
	/*0008*/ LONG PrepareStatus;
	/*0010*/ _LIST_ENTRY ClonedKcbListHead;
	/*0020*/
};

enum _CMP_FAILURE_INJECTION_POINT {
	CmpFailurePointPoolAllocation = 0x0,
	CmpFailurePointViewMapping = 0x1,
	CmpFailurePointViewPinning = 0x2,
	CmpFailurePointResourceCharging = 0x3,
	CmpFailurePointFileWrite = 0x4,
	CmpFailurePointFileRead = 0x5,
	CmpFailurePointCacheFlush = 0x6,
	CmpFailurePointFlush = 0x7,
	CmpFailurePointFlushAndPurge = 0x8,
	CmpFailurePointForceLargeBin = 0x9,
	CmpFailurePointDontFixAlignment = 0xa,
	CmpFailurePointAllocateCell = 0xb,
	CmpFailurePointMarkDirty = 0xc,
	CmpFailurePointAllocateKcb = 0xd,
	CmpFailurePointCreateKeyBody = 0xe,
	CmpFailurePointForcePoolAllocateKcb = 0xf,
	CmpFailurePointForceFreeKcb = 0x10,
	CmpFailurePointKeyEnumResumeContextVerification = 0x11,
	CmpFailurePointKeyEnumForceRetry = 0x12,
	CmpFailureInjectionPointCount = 0x13
};

struct _CM_BIG_DATA {
	/*0000*/ USHORT Signature;
	/*0002*/ USHORT Count;
	/*0004*/ ULONG List;
	/*0008*/
};

struct _CM_CACHED_VALUE_INDEX {
	/*0000*/ ULONG CellIndex;
	union {
		/*0008*/ _CELL_DATA CellData;
		/*0008*/ ULONGLONG List[0x1];
		/*0058*/
	} Data;
	/*0058*/
};

struct _CM_CELL_REMAP_BLOCK {
	/*0000*/ ULONG OldCell;
	/*0004*/ ULONG NewCell;
	/*0008*/
};

struct _CM_COMPONENT_HASH {
	/*0000*/ ULONG Hash;
	/*0004*/
};

struct _CM_DIRTY_VECTOR_LOG {
	/*0000*/ ULONG volatile Next;
	/*0004*/ ULONG Size;
	/*0008*/ _CM_DIRTY_VECTOR_LOG_ENTRY Log[0x10];
	/*0488*/
};

struct _CM_DIRTY_VECTOR_LOG_ENTRY {
	/*0000*/ _ETHREAD * Thread;
	/*0008*/ _CM_DIRTY_VECTOR_OPERATION Operation;
	union {
		struct {
			/*000c*/ ULONG Start;
			/*0010*/ ULONG Length;
			/*0014*/
		} DirtyVectorModifiedContext;
		struct {
			/*000c*/ ULONG RangeCount;
			/*0010*/ ULONG SetBitCount;
			/*0014*/
		} DirtyDataCaptureContext;
		struct {
			/*000c*/ ULONG Context1;
			/*0010*/ ULONG Context2;
			/*0014*/
		} Raw;
		/*0014*/
	} Data;
	/*0018*/ void * Stack[0x6];
	/*0048*/
};

enum _CM_DIRTY_VECTOR_OPERATION {
	DirtyVectorModified = 0x0,
	DirtyDataCaptureStart = 0x1,
	DirtyDataCaptureEnd = 0x2
};

struct _CM_FAST_LEAF_HINT {
	/*0000*/ UCHAR Characters[0x4];
	/*0000*/ ULONG FullHint;
	/*0004*/
};

struct _CM_FULL_RESOURCE_DESCRIPTOR {
	/*0000*/ _INTERFACE_TYPE InterfaceType;
	/*0004*/ ULONG BusNumber;
	/*0008*/ _CM_PARTIAL_RESOURCE_LIST PartialResourceList;
	/*0024*/
};

struct _CM_INDEX {
	/*0000*/ ULONG Cell;
	/*0004*/ _CM_FAST_LEAF_HINT NameHint;
	/*0004*/ _CM_COMPONENT_HASH HashKey;
	/*0008*/
};

struct _CM_INDEX_HINT_BLOCK {
	/*0000*/ ULONG Count;
	/*0004*/ ULONG HashKey[0x1];
	/*0008*/
};

struct _CM_INTENT_LOCK {
	/*0000*/ ULONG OwnerCount;
	/*0008*/ _CM_KCB_UOW * * OwnerTable;
	/*0010*/
};

struct _CM_KCB_LAYER_INFO {
	/*0000*/ _LIST_ENTRY LayerListEntry;
	/*0010*/ _CM_KEY_CONTROL_BLOCK * Kcb;
	/*0018*/ _CM_KCB_LAYER_INFO * LowerLayer;
	/*0020*/ _LIST_ENTRY UpperLayerListHead;
	/*0030*/
};

struct _CM_KCB_UOW {
	/*0000*/ _LIST_ENTRY TransactionListEntry;
	/*0010*/ _CM_INTENT_LOCK * KCBLock;
	/*0018*/ _CM_INTENT_LOCK * KeyLock;
	/*0020*/ _LIST_ENTRY KCBListEntry;
	/*0030*/ _CM_KEY_CONTROL_BLOCK * KeyControlBlock;
	/*0038*/ _CM_TRANS * Transaction;
	/*0040*/ ULONG UoWState;
	/*0044*/ UoWActionType ActionType;
	/*0048*/ HSTORAGE_TYPE StorageType;
	/*0050*/ _CM_KCB_UOW * ParentUoW;
	/*0058*/ _CM_KEY_CONTROL_BLOCK * ChildKCB;
	/*0058*/ ULONG VolatileKeyCell;
	/*0058*/ ULONG OldValueCell;
	/*005c*/ ULONG NewValueCell;
	/*0058*/ ULONG UserFlags;
	/*0058*/ _LARGE_INTEGER LastWriteTime;
	/*0058*/ _CM_KEY_SECURITY_CACHE * TxCachedSecurity;
	/*0060*/ ULONG TxSecurityCell;
	/*0058*/ _CM_KEY_CONTROL_BLOCK * OldChildKCB;
	/*0060*/ _CM_KEY_CONTROL_BLOCK * NewChildKCB;
	/*0058*/ _CM_KEY_CONTROL_BLOCK * OtherChildKCB;
	/*0060*/ ULONG ThisVolatileKeyCell;
	/*0068*/ void * PrepareDataPointer;
	/*0068*/ _CM_UOW_SET_SD_DATA * SecurityData;
	/*0068*/ _CM_UOW_KEY_STATE_MODIFICATION * ModifyKeysData;
	/*0068*/ _CM_UOW_SET_VALUE_LIST_DATA * SetValueData;
	/*0070*/ _CM_UOW_SET_VALUE_KEY_DATA * ValueData;
	/*0070*/ _CMP_DISCARD_AND_REPLACE_KCB_CONTEXT * DiscardReplaceContext;
	/*0078*/
};

struct _CM_KEY_BODY {
	/*0000*/ ULONG Type;
	/*0008*/ _CM_KEY_CONTROL_BLOCK * KeyControlBlock;
	/*0010*/ _CM_NOTIFY_BLOCK * NotifyBlock;
	/*0018*/ void * ProcessID;
	/*0020*/ _LIST_ENTRY KeyBodyList;
	/*0030*/ ULONG Flags : 16; // 0x0000ffff;
	/*0030*/ ULONG HandleTags : 16; // 0xffff0000;
	/*0038*/ _CM_TRANS_PTR Trans;
	/*0040*/ _GUID * KtmUow;
	/*0048*/ _LIST_ENTRY ContextListHead;
	/*0058*/ void * EnumerationResumeContext;
	/*0060*/
};

struct _CM_KEY_CONTROL_BLOCK {
	/*0000*/ ULONG RefCount;
	/*0004*/ ULONG ExtFlags : 16; // 0x0000ffff;
	/*0004*/ ULONG PrivateAlloc : 01; // 0x00010000;
	/*0004*/ ULONG Discarded : 01; // 0x00020000;
	/*0004*/ ULONG HiveUnloaded : 01; // 0x00040000;
	/*0004*/ ULONG Decommissioned : 01; // 0x00080000;
	/*0004*/ ULONG SpareExtFlag : 01; // 0x00100000;
	/*0004*/ ULONG TotalLevels : 10; // 0x7fe00000;
	/*0008*/ _CM_KEY_HASH KeyHash;
	/*0008*/ _CM_PATH_HASH ConvKey;
	/*0010*/ _CM_KEY_HASH * NextHash;
	/*0018*/ _HHIVE * KeyHive;
	/*0020*/ ULONG KeyCell;
	/*0028*/ _EX_PUSH_LOCK KcbPushlock;
	/*0030*/ _KTHREAD * Owner;
	/*0030*/ LONG SharedCount;
	/*0038*/ UCHAR DelayedDeref : 01; // 0x01;
	/*0038*/ UCHAR DelayedClose : 01; // 0x02;
	/*0038*/ UCHAR Parking : 01; // 0x04;
	/*0039*/ UCHAR LayerSemantics;
	/*003a*/ SHORT LayerHeight;
	/*003c*/ ULONG Spare1;
	/*0040*/ _CM_KEY_CONTROL_BLOCK * ParentKcb;
	/*0048*/ _CM_NAME_CONTROL_BLOCK * NameBlock;
	/*0050*/ _CM_KEY_SECURITY_CACHE * CachedSecurity;
	/*0058*/ _CACHED_CHILD_LIST ValueCache;
	/*0068*/ _CM_INDEX_HINT_BLOCK * IndexHint;
	/*0068*/ ULONG HashKey;
	/*0068*/ ULONG SubKeyCount;
	/*0070*/ _LIST_ENTRY KeyBodyListHead;
	/*0070*/ _LIST_ENTRY FreeListEntry;
	/*0080*/ _CM_KEY_BODY * KeyBodyArray[0x4];
	/*00a0*/ _LARGE_INTEGER KcbLastWriteTime;
	/*00a8*/ USHORT KcbMaxNameLen;
	/*00aa*/ USHORT KcbMaxValueNameLen;
	/*00ac*/ ULONG KcbMaxValueDataLen;
	/*00b0*/ ULONG KcbUserFlags : 04; // 0x0000000f;
	/*00b0*/ ULONG KcbVirtControlFlags : 04; // 0x000000f0;
	/*00b0*/ ULONG KcbDebug : 08; // 0x0000ff00;
	/*00b0*/ ULONG Flags : 16; // 0xffff0000;
	/*00b4*/ ULONG Spare3;
	/*00b8*/ _CM_KCB_LAYER_INFO * LayerInfo;
	/*00c0*/ CHAR * RealKeyName;
	/*00c8*/ _LIST_ENTRY KCBUoWListHead;
	/*00d8*/ _LIST_ENTRY DelayQueueEntry;
	/*00d8*/ UCHAR volatile * Stolen;
	/*00e8*/ _CM_TRANS * TransKCBOwner;
	/*00f0*/ _CM_INTENT_LOCK KCBLock;
	/*0100*/ _CM_INTENT_LOCK KeyLock;
	/*0110*/ _CHILD_LIST TransValueCache;
	/*0118*/ _CM_TRANS * TransValueListOwner;
	/*0120*/ _UNICODE_STRING * FullKCBName;
	/*0120*/ ULONGLONG FullKCBNameStale : 01; // 0x0000000000000001;
	/*0120*/ ULONGLONG Reserved : 63; // 0xfffffffffffffffe;
	/*0128*/ ULONGLONG SequenceNumber;
	/*0130*/
};

struct _CM_KEY_HASH {
	/*0000*/ _CM_PATH_HASH ConvKey;
	/*0008*/ _CM_KEY_HASH * NextHash;
	/*0010*/ _HHIVE * KeyHive;
	/*0018*/ ULONG KeyCell;
	/*0020*/
};

struct _CM_KEY_HASH_TABLE_ENTRY {
	/*0000*/ _EX_PUSH_LOCK Lock;
	/*0008*/ _KTHREAD * Owner;
	/*0010*/ _CM_KEY_HASH * Entry;
	/*0018*/
};

struct _CM_KEY_INDEX {
	/*0000*/ USHORT Signature;
	/*0002*/ USHORT Count;
	/*0004*/ ULONG List[0x1];
	/*0008*/
};

struct _CM_KEY_NODE {
	/*0000*/ USHORT Signature;
	/*0002*/ USHORT Flags;
	/*0004*/ _LARGE_INTEGER LastWriteTime;
	/*000c*/ UCHAR AccessBits;
	/*000d*/ UCHAR LayerSemantics : 02; // 0x03;
	/*000d*/ UCHAR Spare1 : 05; // 0x7c;
	/*000d*/ UCHAR InheritClass : 01; // 0x80;
	/*000e*/ USHORT Spare2;
	/*0010*/ ULONG Parent;
	/*0014*/ ULONG SubKeyCounts[0x2];
	/*001c*/ ULONG SubKeyLists[0x2];
	/*0024*/ _CHILD_LIST ValueList;
	/*001c*/ _CM_KEY_REFERENCE ChildHiveReference;
	/*002c*/ ULONG Security;
	/*0030*/ ULONG Class;
	/*0034*/ ULONG MaxNameLen : 16; // 0x0000ffff;
	/*0034*/ ULONG UserFlags : 04; // 0x000f0000;
	/*0034*/ ULONG VirtControlFlags : 04; // 0x00f00000;
	/*0034*/ ULONG Debug : 08; // 0xff000000;
	/*0038*/ ULONG MaxClassLen;
	/*003c*/ ULONG MaxValueNameLen;
	/*0040*/ ULONG MaxValueDataLen;
	/*0044*/ ULONG WorkVar;
	/*0048*/ USHORT NameLength;
	/*004a*/ USHORT ClassLength;
	/*004c*/ WCHAR Name[0x1];
	/*0050*/
};

struct _CM_KEY_REFERENCE {
	/*0000*/ ULONG KeyCell;
	/*0008*/ _HHIVE * KeyHive;
	/*0010*/
};

struct _CM_KEY_SECURITY {
	/*0000*/ USHORT Signature;
	/*0002*/ USHORT Reserved;
	/*0004*/ ULONG Flink;
	/*0008*/ ULONG Blink;
	/*000c*/ ULONG ReferenceCount;
	/*0010*/ ULONG DescriptorLength;
	/*0014*/ _SECURITY_DESCRIPTOR_RELATIVE Descriptor;
	/*0028*/
};

struct _CM_KEY_SECURITY_CACHE {
	/*0000*/ ULONG Cell;
	/*0004*/ ULONG ConvKey;
	/*0008*/ _LIST_ENTRY List;
	/*0018*/ ULONG DescriptorLength;
	/*001c*/ ULONG RealRefCount;
	/*0020*/ _SECURITY_DESCRIPTOR_RELATIVE Descriptor;
	/*0038*/
};

struct _CM_KEY_SECURITY_CACHE_ENTRY {
	/*0000*/ ULONG Cell;
	/*0008*/ _CM_KEY_SECURITY_CACHE * CachedSecurity;
	/*0010*/
};

struct _CM_KEY_VALUE {
	/*0000*/ USHORT Signature;
	/*0002*/ USHORT NameLength;
	/*0004*/ ULONG DataLength;
	/*0008*/ ULONG Data;
	/*000c*/ ULONG Type;
	/*0010*/ USHORT Flags;
	/*0012*/ USHORT Spare;
	/*0014*/ WCHAR Name[0x1];
	/*0018*/
};

enum _CM_LOAD_FAILURE_TYPE {
	_None = 0x0,
	_CmInitializeHive = 0x1,
	_HvInitializeHive = 0x2,
	_HvpBuildMap = 0x3,
	_HvpBuildMapForLoaderHive = 0x4,
	_HvpInitMap = 0x5,
	_HvLoadHive = 0x6,
	_HvpMapHiveImage = 0x7,
	_HvpRecoverData = 0x8,
	_CmpValidateHiveSecurityDescriptors = 0x9,
	_HvpEnlistBinInMap = 0xa,
	_CmCheckRegistry = 0xb,
	_CmRegistryIO = 0xc,
	_CmCheckRegistry2 = 0xd,
	_CmpCheckKey = 0xe,
	_CmpCheckValueList = 0xf,
	_HvCheckHive = 0x10,
	_HvCheckBin = 0x11,
	_HvpGetLogEntryDirtyVector = 0x12,
	_HvpReadLogEntryHeader = 0x13,
	_HvpReadLogEntry = 0x14,
	_CmpMountPreloadedHives = 0x15,
	_CmpLoadHiveThread = 0x16,
	_CmpCheckLeaf = 0x17
};

struct _CM_NAME_CONTROL_BLOCK {
	/*0000*/ ULONG Compressed : 01; // 0x00000001;
	/*0000*/ ULONG RefCount : 31; // 0xfffffffe;
	/*0008*/ _CM_NAME_HASH NameHash;
	/*0008*/ _CM_COMPONENT_HASH ConvKey;
	/*0010*/ _CM_KEY_HASH * NextHash;
	/*0018*/ USHORT NameLength;
	/*001a*/ WCHAR Name[0x1];
	/*0020*/
};

struct _CM_NAME_HASH {
	/*0000*/ _CM_COMPONENT_HASH ConvKey;
	/*0008*/ _CM_NAME_HASH * NextHash;
	/*0010*/ USHORT NameLength;
	/*0012*/ WCHAR Name[0x1];
	/*0018*/
};

struct _CM_NOTIFY_BLOCK {
	/*0000*/ _LIST_ENTRY HiveList;
	/*0010*/ _LIST_ENTRY PostList;
	/*0020*/ _CM_KEY_CONTROL_BLOCK * KeyControlBlock;
	/*0028*/ _CM_KEY_BODY * KeyBody;
	/*0030*/ ULONG Filter : 30; // 0x3fffffff;
	/*0030*/ ULONG WatchTree : 01; // 0x40000000;
	/*0030*/ ULONG NotifyPending : 01; // 0x80000000;
	/*0038*/ _SECURITY_SUBJECT_CONTEXT SubjectContext;
	/*0058*/
};

struct _CM_PARTIAL_RESOURCE_DESCRIPTOR {
	/*0000*/ UCHAR Type;
	/*0001*/ UCHAR ShareDisposition;
	/*0002*/ USHORT Flags;
	union {
		struct {
			/*0004*/ _LARGE_INTEGER Start;
			/*000c*/ ULONG Length;
			/*0010*/
		} Generic;
		struct {
			/*0004*/ _LARGE_INTEGER Start;
			/*000c*/ ULONG Length;
			/*0010*/
		} Port;
		struct {
			/*0004*/ USHORT Level;
			/*0006*/ USHORT Group;
			/*0008*/ ULONG Vector;
			/*000c*/ ULONGLONG Affinity;
			/*0014*/
		} Interrupt;
		struct {
			struct {
				/*0004*/ USHORT Group;
				/*0006*/ USHORT MessageCount;
				/*0008*/ ULONG Vector;
				/*000c*/ ULONGLONG Affinity;
				/*0014*/
			} Raw;
			struct {
				/*0004*/ USHORT Level;
				/*0006*/ USHORT Group;
				/*0008*/ ULONG Vector;
				/*000c*/ ULONGLONG Affinity;
				/*0014*/
			} Translated;
			/*0014*/
		} MessageInterrupt;
		struct {
			/*0004*/ _LARGE_INTEGER Start;
			/*000c*/ ULONG Length;
			/*0010*/
		} Memory;
		struct {
			/*0004*/ ULONG Channel;
			/*0008*/ ULONG Port;
			/*000c*/ ULONG Reserved1;
			/*0010*/
		} Dma;
		struct {
			/*0004*/ ULONG Channel;
			/*0008*/ ULONG RequestLine;
			/*000c*/ UCHAR TransferWidth;
			/*000d*/ UCHAR Reserved1;
			/*000e*/ UCHAR Reserved2;
			/*000f*/ UCHAR Reserved3;
			/*0010*/
		} DmaV3;
		struct {
			/*0004*/ ULONG Data[0x3];
			/*0010*/
		} DevicePrivate;
		struct {
			/*0004*/ ULONG Start;
			/*0008*/ ULONG Length;
			/*000c*/ ULONG Reserved;
			/*0010*/
		} BusNumber;
		struct {
			/*0004*/ ULONG DataSize;
			/*0008*/ ULONG Reserved1;
			/*000c*/ ULONG Reserved2;
			/*0010*/
		} DeviceSpecificData;
		struct {
			/*0004*/ _LARGE_INTEGER Start;
			/*000c*/ ULONG Length40;
			/*0010*/
		} Memory40;
		struct {
			/*0004*/ _LARGE_INTEGER Start;
			/*000c*/ ULONG Length48;
			/*0010*/
		} Memory48;
		struct {
			/*0004*/ _LARGE_INTEGER Start;
			/*000c*/ ULONG Length64;
			/*0010*/
		} Memory64;
		struct {
			/*0004*/ UCHAR Class;
			/*0005*/ UCHAR Type;
			/*0006*/ UCHAR Reserved1;
			/*0007*/ UCHAR Reserved2;
			/*0008*/ ULONG IdLowPart;
			/*000c*/ ULONG IdHighPart;
			/*0010*/
		} Connection;
		/*0014*/
	} u;
	/*0014*/
};

struct _CM_PARTIAL_RESOURCE_LIST {
	/*0000*/ USHORT Version;
	/*0002*/ USHORT Revision;
	/*0004*/ ULONG Count;
	/*0008*/ _CM_PARTIAL_RESOURCE_DESCRIPTOR PartialDescriptors[0x1];
	/*001c*/
};

struct _CM_PATH_HASH {
	/*0000*/ ULONG Hash;
	/*0004*/
};

struct _CM_RESOURCE_LIST {
	/*0000*/ ULONG Count;
	/*0004*/ _CM_FULL_RESOURCE_DESCRIPTOR List[0x1];
	/*0028*/
};

struct _CM_RM {
	/*0000*/ _LIST_ENTRY RmListEntry;
	/*0010*/ _LIST_ENTRY TransactionListHead;
	/*0020*/ void * TmHandle;
	/*0028*/ void * Tm;
	/*0030*/ void * RmHandle;
	/*0038*/ void * KtmRm;
	/*0040*/ ULONG RefCount;
	/*0044*/ ULONG ContainerNum;
	/*0048*/ ULONGLONG ContainerSize;
	/*0050*/ _CMHIVE * CmHive;
	/*0058*/ void * LogFileObject;
	/*0060*/ void * MarshallingContext;
	/*0068*/ ULONG RmFlags;
	/*006c*/ LONG LogStartStatus1;
	/*0070*/ LONG LogStartStatus2;
	/*0078*/ ULONGLONG BaseLsn;
	/*0080*/ _ERESOURCE * RmLock;
	/*0088*/
};

enum _CM_SHARE_DISPOSITION {
	CmResourceShareUndetermined = 0x0,
	CmResourceShareDeviceExclusive = 0x1,
	CmResourceShareDriverExclusive = 0x2,
	CmResourceShareShared = 0x3
};

struct _CM_TRANS {
	/*0000*/ _LIST_ENTRY TransactionListEntry;
	/*0010*/ _LIST_ENTRY KCBUoWListHead;
	/*0020*/ _LIST_ENTRY LazyCommitListEntry;
	/*0030*/ ULONG Prepared : 01; // 0x00000001;
	/*0030*/ ULONG Aborted : 01; // 0x00000002;
	/*0030*/ ULONG Committed : 01; // 0x00000004;
	/*0030*/ ULONG Initializing : 01; // 0x00000008;
	/*0030*/ ULONG Invalid : 01; // 0x00000010;
	/*0030*/ ULONG UseReservation : 01; // 0x00000020;
	/*0030*/ ULONG TmCallbacksActive : 01; // 0x00000040;
	/*0030*/ ULONG LightWeight : 01; // 0x00000080;
	/*0030*/ ULONG Freed1 : 01; // 0x00000100;
	/*0030*/ ULONG Freed2 : 01; // 0x00000200;
	/*0030*/ ULONG Spare1 : 02; // 0x00000c00;
	/*0030*/ ULONG Freed : 01; // 0x00001000;
	/*0030*/ ULONG Spare : 19; // 0xffffe000;
	/*0030*/ ULONG TransState;
	/*0038*/ _CM_TRANS_PTR Trans;
	/*0040*/ _CM_RM * CmRm;
	/*0048*/ _KENLISTMENT * KtmEnlistmentObject;
	/*0050*/ void * KtmEnlistmentHandle;
	/*0058*/ _GUID KtmUow;
	/*0068*/ ULONGLONG StartLsn;
	/*0070*/ ULONG HiveCount;
	/*0078*/ _CMHIVE * HiveArray[0x8];
	/*00b8*/
};

union _CM_TRANS_PTR {
	/*0000*/ ULONGLONG LightWeight : 01; // 0x0000000000000001;
	/*0000*/ void * TransPtr;
	/*0008*/
};

struct _CM_UOW_KEY_STATE_MODIFICATION {
	/*0000*/ ULONG RefCount;
	/*0004*/ ULONG SubKeyListCount[0x2];
	/*000c*/ ULONG NewSubKeyList[0x2];
	/*0014*/
};

struct _CM_UOW_SET_SD_DATA {
	/*0000*/ ULONG SecurityCell;
	/*0004*/
};

struct _CM_UOW_SET_VALUE_KEY_DATA {
	/*0000*/ ULONG PreparedCell;
	/*0004*/ ULONG OldValueCell;
	/*0008*/ USHORT NameLength;
	/*000c*/ ULONG DataSize;
	/*0010*/
};

struct _CM_UOW_SET_VALUE_LIST_DATA {
	/*0000*/ ULONG RefCount;
	/*0004*/ _CHILD_LIST ValueList;
	/*000c*/
};

struct _CM_WORKITEM {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ ULONG Private;
	/*0018*/ void (* WorkerRoutine)( void * );
	/*0020*/ void * Parameter;
	/*0028*/
};

struct _COMPRESSED_DATA_INFO {
	/*0000*/ USHORT CompressionFormatAndEngine;
	/*0002*/ UCHAR CompressionUnitShift;
	/*0003*/ UCHAR ChunkShift;
	/*0004*/ UCHAR ClusterShift;
	/*0005*/ UCHAR Reserved;
	/*0006*/ USHORT NumberOfChunks;
	/*0008*/ ULONG CompressedChunkSizes[0x1];
	/*000c*/
};

struct _CONTEXT {
	/*0000*/ ULONGLONG P1Home;
	/*0008*/ ULONGLONG P2Home;
	/*0010*/ ULONGLONG P3Home;
	/*0018*/ ULONGLONG P4Home;
	/*0020*/ ULONGLONG P5Home;
	/*0028*/ ULONGLONG P6Home;
	/*0030*/ ULONG ContextFlags;
	/*0034*/ ULONG MxCsr;
	/*0038*/ USHORT SegCs;
	/*003a*/ USHORT SegDs;
	/*003c*/ USHORT SegEs;
	/*003e*/ USHORT SegFs;
	/*0040*/ USHORT SegGs;
	/*0042*/ USHORT SegSs;
	/*0044*/ ULONG EFlags;
	/*0048*/ ULONGLONG Dr0;
	/*0050*/ ULONGLONG Dr1;
	/*0058*/ ULONGLONG Dr2;
	/*0060*/ ULONGLONG Dr3;
	/*0068*/ ULONGLONG Dr6;
	/*0070*/ ULONGLONG Dr7;
	/*0078*/ ULONGLONG Rax;
	/*0080*/ ULONGLONG Rcx;
	/*0088*/ ULONGLONG Rdx;
	/*0090*/ ULONGLONG Rbx;
	/*0098*/ ULONGLONG Rsp;
	/*00a0*/ ULONGLONG Rbp;
	/*00a8*/ ULONGLONG Rsi;
	/*00b0*/ ULONGLONG Rdi;
	/*00b8*/ ULONGLONG R8;
	/*00c0*/ ULONGLONG R9;
	/*00c8*/ ULONGLONG R10;
	/*00d0*/ ULONGLONG R11;
	/*00d8*/ ULONGLONG R12;
	/*00e0*/ ULONGLONG R13;
	/*00e8*/ ULONGLONG R14;
	/*00f0*/ ULONGLONG R15;
	/*00f8*/ ULONGLONG Rip;
	/*0100*/ _XSAVE_FORMAT FltSave;
	/*0100*/ _M128A Header[0x2];
	/*0120*/ _M128A Legacy[0x8];
	/*01a0*/ _M128A Xmm0;
	/*01b0*/ _M128A Xmm1;
	/*01c0*/ _M128A Xmm2;
	/*01d0*/ _M128A Xmm3;
	/*01e0*/ _M128A Xmm4;
	/*01f0*/ _M128A Xmm5;
	/*0200*/ _M128A Xmm6;
	/*0210*/ _M128A Xmm7;
	/*0220*/ _M128A Xmm8;
	/*0230*/ _M128A Xmm9;
	/*0240*/ _M128A Xmm10;
	/*0250*/ _M128A Xmm11;
	/*0260*/ _M128A Xmm12;
	/*0270*/ _M128A Xmm13;
	/*0280*/ _M128A Xmm14;
	/*0290*/ _M128A Xmm15;
	/*0300*/ _M128A VectorRegister[0x1a];
	/*04a0*/ ULONGLONG VectorControl;
	/*04a8*/ ULONGLONG DebugControl;
	/*04b0*/ ULONGLONG LastBranchToRip;
	/*04b8*/ ULONGLONG LastBranchFromRip;
	/*04c0*/ ULONGLONG LastExceptionToRip;
	/*04c8*/ ULONGLONG LastExceptionFromRip;
	/*04d0*/
};

struct _CONTROL_AREA {
	/*0000*/ _SEGMENT * Segment;
	/*0008*/ _LIST_ENTRY ListHead;
	/*0018*/ ULONGLONG NumberOfSectionReferences;
	/*0020*/ ULONGLONG NumberOfPfnReferences;
	/*0028*/ ULONGLONG NumberOfMappedViews;
	/*0030*/ ULONGLONG NumberOfUserReferences;
	union {
		/*0038*/ ULONG LongFlags;
		/*0038*/ _MMSECTION_FLAGS Flags;
		/*003c*/
	} u;
	union {
		/*003c*/ ULONG LongFlags;
		/*003c*/ _MMSECTION_FLAGS2 Flags;
		/*0040*/
	} u1;
	/*0040*/ _EX_FAST_REF FilePointer;
	/*0048*/ LONG volatile ControlAreaLock;
	/*004c*/ ULONG ModifiedWriteCount;
	/*0050*/ _MI_CONTROL_AREA_WAIT_BLOCK * WaitList;
	union {
		struct {
			/*0058*/ ULONG NumberOfSystemCacheViews;
			/*0058*/ ULONG ImageRelocationStartBit;
			/*005c*/ LONG volatile WritableUserReferences;
			/*005c*/ ULONG ImageRelocationSizeIn64k : 16; // 0x0000ffff;
			/*005c*/ ULONG LargePage : 01; // 0x00010000;
			/*005c*/ ULONG SystemImage : 01; // 0x00020000;
			/*005c*/ ULONG StrongCode : 02; // 0x000c0000;
			/*005c*/ ULONG CantMove : 01; // 0x00100000;
			/*005c*/ ULONG BitMap : 02; // 0x00600000;
			/*005c*/ ULONG ImageActive : 01; // 0x00800000;
			/*0060*/ ULONG FlushInProgressCount;
			/*0060*/ ULONG NumberOfSubsections;
			/*0060*/ _MI_IMAGE_SECURITY_REFERENCE * SeImageStub;
			/*0068*/
		} e2;
		/*0068*/
	} u2;
	/*0068*/ _EX_PUSH_LOCK FileObjectLock;
	/*0070*/ ULONGLONG volatile LockedPages;
	union {
		/*0078*/ ULONGLONG IoAttributionContext : 61; // 0x1fffffffffffffff;
		/*0078*/ ULONGLONG Spare : 03; // 0xe000000000000000;
		/*0078*/ ULONGLONG ImageCrossPartitionCharge;
		/*0078*/ ULONGLONG CommittedPageCount : 36; // 0x0000000fffffffff;
		/*0080*/
	} u3;
	/*0080*/
};

struct _COUNTER_READING {
	/*0000*/ _HARDWARE_COUNTER_TYPE Type;
	/*0004*/ ULONG Index;
	/*0008*/ ULONGLONG Start;
	/*0010*/ ULONGLONG Total;
	/*0018*/
};

union _CPU_INFO {
	/*0000*/ UINT AsUINT32[0x4];
	/*0000*/ ULONG Eax;
	/*0004*/ ULONG Ebx;
	/*0008*/ ULONG Ecx;
	/*000c*/ ULONG Edx;
	/*0010*/
};

enum _CREATE_FILE_TYPE {
	CreateFileTypeNone = 0x0,
	CreateFileTypeNamedPipe = 0x1,
	CreateFileTypeMailslot = 0x2
};

struct _CRITICAL_PROCESS_EXCEPTION_DATA {
	/*0000*/ _GUID ReportId;
	/*0010*/ _UNICODE_STRING ModuleName;
	/*0020*/ ULONG ModuleTimestamp;
	/*0024*/ ULONG ModuleSize;
	/*0028*/ ULONGLONG Offset;
	/*0030*/
};

struct _CURDIR {
	/*0000*/ _UNICODE_STRING DosPath;
	/*0010*/ void * Handle;
	/*0018*/
};

union _CVDD {
	/*0000*/ ULONG Signature;
	/*0000*/ _NB10 NB10;
	/*0000*/ _RSDS RsDs;
	/*001c*/
};

enum _ConnectionResourceConsumerDesc {
	ConnectionResourceConsumerDescIsUndefined = 0x0,
	ConnectionResourceConsumerDescIsDevice = 0x1,
	ConnectionResourceConsumerDescIsOpregion = 0x2,
	ConnectionResourceConsumerDescMax = 0x3
};

struct _DBGKD_ANY_CONTROL_SET {
	/*0000*/ _X86_DBGKD_CONTROL_SET X86ControlSet;
	/*0000*/ ULONG AlphaControlSet;
	/*0000*/ _IA64_DBGKD_CONTROL_SET IA64ControlSet;
	/*0000*/ _AMD64_DBGKD_CONTROL_SET Amd64ControlSet;
	/*0000*/ _ARM_DBGKD_CONTROL_SET ArmControlSet;
	/*0000*/ _ARM64_DBGKD_CONTROL_SET Arm64ControlSet;
	/*0000*/ _ARMCE_DBGKD_CONTROL_SET ArmCeControlSet;
	/*0000*/ _PPC_DBGKD_CONTROL_SET PpcControlSet;
	/*001c*/
};

struct _DBGKD_BREAKPOINTEX {
	/*0000*/ ULONG BreakPointCount;
	/*0004*/ LONG ContinueStatus;
	/*0008*/
};

struct _DBGKD_CONTEXT_EX {
	/*0000*/ ULONG Offset;
	/*0004*/ ULONG ByteCount;
	/*0008*/ ULONG BytesCopied;
	/*000c*/
};

struct _DBGKD_CONTINUE {
	/*0000*/ LONG ContinueStatus;
	/*0004*/
};

struct _DBGKD_CONTINUE2 {
	/*0000*/ LONG ContinueStatus;
	/*0004*/ _AMD64_DBGKD_CONTROL_SET ControlSet;
	/*0004*/ _DBGKD_ANY_CONTROL_SET AnyControlSet;
	/*0020*/
};

struct _DBGKD_FILL_MEMORY {
	/*0000*/ ULONGLONG Address;
	/*0008*/ ULONG Length;
	/*000c*/ USHORT Flags;
	/*000e*/ USHORT PatternLength;
	/*0010*/
};

struct _DBGKD_GET_CONTEXT {
	/*0000*/ ULONG Unused;
	/*0004*/
};

struct _DBGKD_GET_INTERNAL_BREAKPOINT32 {
	/*0000*/ ULONG BreakpointAddress;
	/*0004*/ ULONG Flags;
	/*0008*/ ULONG Calls;
	/*000c*/ ULONG MaxCallsPerPeriod;
	/*0010*/ ULONG MinInstructions;
	/*0014*/ ULONG MaxInstructions;
	/*0018*/ ULONG TotalInstructions;
	/*001c*/
};

struct _DBGKD_GET_INTERNAL_BREAKPOINT64 {
	/*0000*/ ULONGLONG BreakpointAddress;
	/*0008*/ ULONG Flags;
	/*000c*/ ULONG Calls;
	/*0010*/ ULONG MaxCallsPerPeriod;
	/*0014*/ ULONG MinInstructions;
	/*0018*/ ULONG MaxInstructions;
	/*001c*/ ULONG TotalInstructions;
	/*0020*/
};

struct _DBGKD_GET_SET_BUS_DATA {
	/*0000*/ ULONG BusDataType;
	/*0004*/ ULONG BusNumber;
	/*0008*/ ULONG SlotNumber;
	/*000c*/ ULONG Offset;
	/*0010*/ ULONG Length;
	/*0014*/
};

struct _DBGKD_GET_VERSION32 {
	/*0000*/ USHORT MajorVersion;
	/*0002*/ USHORT MinorVersion;
	/*0004*/ USHORT ProtocolVersion;
	/*0006*/ USHORT Flags;
	/*0008*/ ULONG KernBase;
	/*000c*/ ULONG PsLoadedModuleList;
	/*0010*/ USHORT MachineType;
	/*0012*/ USHORT ThCallbackStack;
	/*0014*/ USHORT NextCallback;
	/*0016*/ USHORT FramePointer;
	/*0018*/ ULONG KiCallUserMode;
	/*001c*/ ULONG KeUserCallbackDispatcher;
	/*0020*/ ULONG BreakpointWithStatus;
	/*0024*/ ULONG DebuggerDataList;
	/*0028*/
};

struct _DBGKD_GET_VERSION64 {
	/*0000*/ USHORT MajorVersion;
	/*0002*/ USHORT MinorVersion;
	/*0004*/ UCHAR ProtocolVersion;
	/*0005*/ UCHAR KdSecondaryVersion;
	/*0006*/ USHORT Flags;
	/*0008*/ USHORT MachineType;
	/*000a*/ UCHAR MaxPacketType;
	/*000b*/ UCHAR MaxStateChange;
	/*000c*/ UCHAR MaxManipulate;
	/*000d*/ UCHAR Simulation;
	/*000e*/ USHORT Unused[0x1];
	/*0010*/ ULONGLONG KernBase;
	/*0018*/ ULONGLONG PsLoadedModuleList;
	/*0020*/ ULONGLONG DebuggerDataList;
	/*0028*/
};

struct _DBGKD_LOAD_SYMBOLS32 {
	/*0000*/ ULONG PathNameLength;
	/*0004*/ ULONG BaseOfDll;
	/*0008*/ ULONG ProcessId;
	/*000c*/ ULONG CheckSum;
	/*0010*/ ULONG SizeOfImage;
	/*0014*/ UCHAR UnloadSymbols;
	/*0018*/
};

struct _DBGKD_LOAD_SYMBOLS64 {
	/*0000*/ ULONG PathNameLength;
	/*0008*/ ULONGLONG BaseOfDll;
	/*0010*/ ULONGLONG ProcessId;
	/*0018*/ ULONG CheckSum;
	/*001c*/ ULONG SizeOfImage;
	/*0020*/ UCHAR UnloadSymbols;
	/*0028*/
};

struct _DBGKD_MANIPULATE_STATE32 {
	/*0000*/ ULONG ApiNumber;
	/*0004*/ USHORT ProcessorLevel;
	/*0006*/ USHORT Processor;
	/*0008*/ LONG ReturnStatus;
	union {
		/*000c*/ _DBGKD_READ_MEMORY32 ReadMemory;
		/*000c*/ _DBGKD_WRITE_MEMORY32 WriteMemory;
		/*000c*/ _DBGKD_READ_MEMORY64 ReadMemory64;
		/*000c*/ _DBGKD_WRITE_MEMORY64 WriteMemory64;
		/*000c*/ _DBGKD_GET_CONTEXT GetContext;
		/*000c*/ _DBGKD_SET_CONTEXT SetContext;
		/*000c*/ _DBGKD_WRITE_BREAKPOINT32 WriteBreakPoint;
		/*000c*/ _DBGKD_RESTORE_BREAKPOINT RestoreBreakPoint;
		/*000c*/ _DBGKD_CONTINUE Continue;
		/*000c*/ _DBGKD_CONTINUE2 Continue2;
		/*000c*/ _DBGKD_READ_WRITE_IO32 ReadWriteIo;
		/*000c*/ _DBGKD_READ_WRITE_IO_EXTENDED32 ReadWriteIoExtended;
		/*000c*/ _DBGKD_QUERY_SPECIAL_CALLS QuerySpecialCalls;
		/*000c*/ _DBGKD_SET_SPECIAL_CALL32 SetSpecialCall;
		/*000c*/ _DBGKD_SET_INTERNAL_BREAKPOINT32 SetInternalBreakpoint;
		/*000c*/ _DBGKD_GET_INTERNAL_BREAKPOINT32 GetInternalBreakpoint;
		/*000c*/ _DBGKD_GET_VERSION32 GetVersion32;
		/*000c*/ _DBGKD_BREAKPOINTEX BreakPointEx;
		/*000c*/ _DBGKD_READ_WRITE_MSR ReadWriteMsr;
		/*000c*/ _DBGKD_SEARCH_MEMORY SearchMemory;
		/*000c*/ _DBGKD_CONTEXT_EX GetContextEx;
		/*000c*/ _DBGKD_CONTEXT_EX SetContextEx;
		/*0034*/
	} u;
	/*0034*/
};

struct _DBGKD_MANIPULATE_STATE64 {
	/*0000*/ ULONG ApiNumber;
	/*0004*/ USHORT ProcessorLevel;
	/*0006*/ USHORT Processor;
	/*0008*/ LONG ReturnStatus;
	union {
		/*0010*/ _DBGKD_READ_MEMORY64 ReadMemory;
		/*0010*/ _DBGKD_WRITE_MEMORY64 WriteMemory;
		/*0010*/ _DBGKD_GET_CONTEXT GetContext;
		/*0010*/ _DBGKD_SET_CONTEXT SetContext;
		/*0010*/ _DBGKD_WRITE_BREAKPOINT64 WriteBreakPoint;
		/*0010*/ _DBGKD_RESTORE_BREAKPOINT RestoreBreakPoint;
		/*0010*/ _DBGKD_CONTINUE Continue;
		/*0010*/ _DBGKD_CONTINUE2 Continue2;
		/*0010*/ _DBGKD_READ_WRITE_IO64 ReadWriteIo;
		/*0010*/ _DBGKD_READ_WRITE_IO_EXTENDED64 ReadWriteIoExtended;
		/*0010*/ _DBGKD_QUERY_SPECIAL_CALLS QuerySpecialCalls;
		/*0010*/ _DBGKD_SET_SPECIAL_CALL64 SetSpecialCall;
		/*0010*/ _DBGKD_SET_INTERNAL_BREAKPOINT64 SetInternalBreakpoint;
		/*0010*/ _DBGKD_GET_INTERNAL_BREAKPOINT64 GetInternalBreakpoint;
		/*0010*/ _DBGKD_GET_VERSION64 GetVersion64;
		/*0010*/ _DBGKD_BREAKPOINTEX BreakPointEx;
		/*0010*/ _DBGKD_READ_WRITE_MSR ReadWriteMsr;
		/*0010*/ _DBGKD_SEARCH_MEMORY SearchMemory;
		/*0010*/ _DBGKD_GET_SET_BUS_DATA GetSetBusData;
		/*0010*/ _DBGKD_FILL_MEMORY FillMemory;
		/*0010*/ _DBGKD_QUERY_MEMORY QueryMemory;
		/*0010*/ _DBGKD_SWITCH_PARTITION SwitchPartition;
		/*0010*/ _DBGKD_CONTEXT_EX GetContextEx;
		/*0010*/ _DBGKD_CONTEXT_EX SetContextEx;
		/*0010*/ _DBGKD_WRITE_CUSTOM_BREAKPOINT WriteCustomBreakPoint;
		/*0038*/
	} u;
	/*0038*/
};

struct _DBGKD_QUERY_MEMORY {
	/*0000*/ ULONGLONG Address;
	/*0008*/ ULONGLONG Reserved;
	/*0010*/ ULONG AddressSpace;
	/*0014*/ ULONG Flags;
	/*0018*/
};

struct _DBGKD_QUERY_SPECIAL_CALLS {
	/*0000*/ ULONG NumberOfSpecialCalls;
	/*0004*/
};

struct _DBGKD_READ_MEMORY32 {
	/*0000*/ ULONG TargetBaseAddress;
	/*0004*/ ULONG TransferCount;
	/*0008*/ ULONG ActualBytesRead;
	/*000c*/
};

struct _DBGKD_READ_MEMORY64 {
	/*0000*/ ULONGLONG TargetBaseAddress;
	/*0008*/ ULONG TransferCount;
	/*000c*/ ULONG ActualBytesRead;
	/*0010*/
};

struct _DBGKD_READ_WRITE_IO32 {
	/*0000*/ ULONG DataSize;
	/*0004*/ ULONG IoAddress;
	/*0008*/ ULONG DataValue;
	/*000c*/
};

struct _DBGKD_READ_WRITE_IO64 {
	/*0000*/ ULONGLONG IoAddress;
	/*0008*/ ULONG DataSize;
	/*000c*/ ULONG DataValue;
	/*0010*/
};

struct _DBGKD_READ_WRITE_IO_EXTENDED32 {
	/*0000*/ ULONG DataSize;
	/*0004*/ ULONG InterfaceType;
	/*0008*/ ULONG BusNumber;
	/*000c*/ ULONG AddressSpace;
	/*0010*/ ULONG IoAddress;
	/*0014*/ ULONG DataValue;
	/*0018*/
};

struct _DBGKD_READ_WRITE_IO_EXTENDED64 {
	/*0000*/ ULONG DataSize;
	/*0004*/ ULONG InterfaceType;
	/*0008*/ ULONG BusNumber;
	/*000c*/ ULONG AddressSpace;
	/*0010*/ ULONGLONG IoAddress;
	/*0018*/ ULONG DataValue;
	/*0020*/
};

struct _DBGKD_READ_WRITE_MSR {
	/*0000*/ ULONG Msr;
	/*0004*/ ULONG DataValueLow;
	/*0008*/ ULONG DataValueHigh;
	/*000c*/
};

struct _DBGKD_RESTORE_BREAKPOINT {
	/*0000*/ ULONG BreakPointHandle;
	/*0004*/
};

struct _DBGKD_SEARCH_MEMORY {
	/*0000*/ ULONGLONG SearchAddress;
	/*0000*/ ULONGLONG FoundAddress;
	/*0008*/ ULONGLONG SearchLength;
	/*0010*/ ULONG PatternLength;
	/*0018*/
};

struct _DBGKD_SET_CONTEXT {
	/*0000*/ ULONG ContextFlags;
	/*0004*/
};

struct _DBGKD_SET_INTERNAL_BREAKPOINT32 {
	/*0000*/ ULONG BreakpointAddress;
	/*0004*/ ULONG Flags;
	/*0008*/
};

struct _DBGKD_SET_INTERNAL_BREAKPOINT64 {
	/*0000*/ ULONGLONG BreakpointAddress;
	/*0008*/ ULONG Flags;
	/*0010*/
};

struct _DBGKD_SET_SPECIAL_CALL32 {
	/*0000*/ ULONG SpecialCall;
	/*0004*/
};

struct _DBGKD_SET_SPECIAL_CALL64 {
	/*0000*/ ULONGLONG SpecialCall;
	/*0008*/
};

struct _DBGKD_SWITCH_PARTITION {
	/*0000*/ ULONG Partition;
	/*0004*/
};

struct _DBGKD_WRITE_BREAKPOINT32 {
	/*0000*/ ULONG BreakPointAddress;
	/*0004*/ ULONG BreakPointHandle;
	/*0008*/
};

struct _DBGKD_WRITE_BREAKPOINT64 {
	/*0000*/ ULONGLONG BreakPointAddress;
	/*0008*/ ULONG BreakPointHandle;
	/*0010*/
};

struct _DBGKD_WRITE_CUSTOM_BREAKPOINT {
	/*0000*/ ULONGLONG BreakPointAddress;
	/*0008*/ ULONGLONG BreakPointInstruction;
	/*0010*/ ULONG BreakPointHandle;
	/*0014*/ UCHAR BreakPointInstructionSize;
	/*0015*/ UCHAR BreakPointInstructionAlignment;
	/*0018*/
};

struct _DBGKD_WRITE_MEMORY32 {
	/*0000*/ ULONG TargetBaseAddress;
	/*0004*/ ULONG TransferCount;
	/*0008*/ ULONG ActualBytesWritten;
	/*000c*/
};

struct _DBGKD_WRITE_MEMORY64 {
	/*0000*/ ULONGLONG TargetBaseAddress;
	/*0008*/ ULONG TransferCount;
	/*000c*/ ULONG ActualBytesWritten;
	/*0010*/
};

struct _DBGKM_EXCEPTION32 {
	/*0000*/ _EXCEPTION_RECORD32 ExceptionRecord;
	/*0050*/ ULONG FirstChance;
	/*0054*/
};

struct _DBGKM_EXCEPTION64 {
	/*0000*/ _EXCEPTION_RECORD64 ExceptionRecord;
	/*0098*/ ULONG FirstChance;
	/*00a0*/
};

struct _DBGKP_ERROR_PORT;

struct _DBGK_SILOSTATE {
	/*0000*/ _EX_PUSH_LOCK ErrorPortLock;
	/*0008*/ _DBGKP_ERROR_PORT * ErrorPort;
	/*0010*/ _EPROCESS * ErrorProcess;
	/*0018*/ _KEVENT * ErrorPortRegisteredEvent;
	/*0020*/
};

struct _DEFERRED_WRITE {
	/*0000*/ SHORT NodeTypeCode;
	/*0002*/ SHORT NodeByteSize;
	/*0008*/ _FILE_OBJECT * FileObject;
	/*0010*/ ULONG BytesToWrite;
	/*0018*/ _LIST_ENTRY DeferredWriteLinks;
	/*0028*/ _KEVENT * Event;
	/*0030*/ void (* PostRoutine)( void * , void * );
	/*0038*/ void * Context1;
	/*0040*/ void * Context2;
	/*0048*/ _CC_PARTITION * Partition;
	/*0050*/
};

struct _DELAY_ACK_FO {
	/*0000*/ _LIST_ENTRY Links;
	/*0010*/ _FILE_OBJECT * OriginalFileObject;
	/*0018*/
};

struct _DEVICE_CAPABILITIES {
	/*0000*/ USHORT Size;
	/*0002*/ USHORT Version;
	/*0004*/ ULONG DeviceD1 : 01; // 0x00000001;
	/*0004*/ ULONG DeviceD2 : 01; // 0x00000002;
	/*0004*/ ULONG LockSupported : 01; // 0x00000004;
	/*0004*/ ULONG EjectSupported : 01; // 0x00000008;
	/*0004*/ ULONG Removable : 01; // 0x00000010;
	/*0004*/ ULONG DockDevice : 01; // 0x00000020;
	/*0004*/ ULONG UniqueID : 01; // 0x00000040;
	/*0004*/ ULONG SilentInstall : 01; // 0x00000080;
	/*0004*/ ULONG RawDeviceOK : 01; // 0x00000100;
	/*0004*/ ULONG SurpriseRemovalOK : 01; // 0x00000200;
	/*0004*/ ULONG WakeFromD0 : 01; // 0x00000400;
	/*0004*/ ULONG WakeFromD1 : 01; // 0x00000800;
	/*0004*/ ULONG WakeFromD2 : 01; // 0x00001000;
	/*0004*/ ULONG WakeFromD3 : 01; // 0x00002000;
	/*0004*/ ULONG HardwareDisabled : 01; // 0x00004000;
	/*0004*/ ULONG NonDynamic : 01; // 0x00008000;
	/*0004*/ ULONG WarmEjectSupported : 01; // 0x00010000;
	/*0004*/ ULONG NoDisplayInUI : 01; // 0x00020000;
	/*0004*/ ULONG Reserved1 : 01; // 0x00040000;
	/*0004*/ ULONG WakeFromInterrupt : 01; // 0x00080000;
	/*0004*/ ULONG SecureDevice : 01; // 0x00100000;
	/*0004*/ ULONG Reserved : 11; // 0xffe00000;
	/*0008*/ ULONG Address;
	/*000c*/ ULONG UINumber;
	/*0010*/ _DEVICE_POWER_STATE DeviceState[0x7];
	/*002c*/ _SYSTEM_POWER_STATE SystemWake;
	/*0030*/ _DEVICE_POWER_STATE DeviceWake;
	/*0034*/ ULONG D1Latency;
	/*0038*/ ULONG D2Latency;
	/*003c*/ ULONG D3Latency;
	/*0040*/
};

struct _DEVICE_DESCRIPTION {
	/*0000*/ ULONG Version;
	/*0004*/ UCHAR Master;
	/*0005*/ UCHAR ScatterGather;
	/*0006*/ UCHAR DemandMode;
	/*0007*/ UCHAR AutoInitialize;
	/*0008*/ UCHAR Dma32BitAddresses;
	/*0009*/ UCHAR IgnoreCount;
	/*000a*/ UCHAR Reserved1;
	/*000b*/ UCHAR Dma64BitAddresses;
	/*000c*/ ULONG BusNumber;
	/*0010*/ ULONG DmaChannel;
	/*0014*/ _INTERFACE_TYPE InterfaceType;
	/*0018*/ _DMA_WIDTH DmaWidth;
	/*001c*/ _DMA_SPEED DmaSpeed;
	/*0020*/ ULONG MaximumLength;
	/*0024*/ ULONG DmaPort;
	/*0028*/ ULONG DmaAddressWidth;
	/*002c*/ ULONG DmaControllerInstance;
	/*0030*/ ULONG DmaRequestLine;
	/*0038*/ _LARGE_INTEGER DeviceAddress;
	/*0040*/
};

struct _DEVICE_MAP {
	/*0000*/ _OBJECT_DIRECTORY * DosDevicesDirectory;
	/*0008*/ _OBJECT_DIRECTORY * GlobalDosDevicesDirectory;
	/*0010*/ void * DosDevicesDirectoryHandle;
	/*0018*/ LONG volatile ReferenceCount;
	/*001c*/ ULONG DriveMap;
	/*0020*/ UCHAR DriveType[0x20];
	/*0040*/ _EJOB * ServerSilo;
	/*0048*/
};

struct _DEVICE_NODE {
	/*0000*/ _DEVICE_NODE * Sibling;
	/*0008*/ _DEVICE_NODE * Child;
	/*0010*/ _DEVICE_NODE * Parent;
	/*0018*/ _DEVICE_NODE * LastChild;
	/*0020*/ _DEVICE_OBJECT * PhysicalDeviceObject;
	/*0028*/ _UNICODE_STRING InstancePath;
	/*0038*/ _UNICODE_STRING ServiceName;
	/*0048*/ _IRP * PendingIrp;
	/*0050*/ _POP_FX_DEVICE * FxDevice;
	/*0058*/ LONG volatile FxDeviceLock;
	/*0060*/ _KEVENT FxRemoveEvent;
	/*0078*/ LONG volatile FxActivationCount;
	/*007c*/ LONG volatile FxSleepCount;
	/*0080*/ _POP_FX_PLUGIN * Plugin;
	/*0088*/ ULONG Level;
	/*008c*/ _POWER_STATE CurrentPowerState;
	/*0090*/ _PO_DEVICE_NOTIFY Notify;
	/*00f8*/ _PO_IRP_MANAGER PoIrpManager;
	/*0118*/ _UNICODE_STRING UniqueId;
	/*0128*/ ULONG PowerFlags;
	/*012c*/ _PNP_DEVNODE_STATE State;
	/*0130*/ _PNP_DEVNODE_STATE PreviousState;
	/*0134*/ _PNP_DEVNODE_STATE StateHistory[0x14];
	/*0184*/ ULONG StateHistoryEntry;
	/*0188*/ LONG CompletionStatus;
	/*018c*/ ULONG Flags;
	/*0190*/ ULONG UserFlags;
	/*0194*/ ULONG Problem;
	/*0198*/ LONG ProblemStatus;
	/*01a0*/ _CM_RESOURCE_LIST * ResourceList;
	/*01a8*/ _CM_RESOURCE_LIST * ResourceListTranslated;
	/*01b0*/ _DEVICE_OBJECT * DuplicatePDO;
	/*01b8*/ _IO_RESOURCE_REQUIREMENTS_LIST * ResourceRequirements;
	/*01c0*/ _INTERFACE_TYPE InterfaceType;
	/*01c4*/ ULONG BusNumber;
	/*01c8*/ _INTERFACE_TYPE ChildInterfaceType;
	/*01cc*/ ULONG ChildBusNumber;
	/*01d0*/ USHORT ChildBusTypeIndex;
	/*01d2*/ UCHAR RemovalPolicy;
	/*01d3*/ UCHAR HardwareRemovalPolicy;
	/*01d8*/ _LIST_ENTRY TargetDeviceNotify;
	/*01e8*/ _LIST_ENTRY DeviceArbiterList;
	/*01f8*/ _LIST_ENTRY DeviceTranslatorList;
	/*0208*/ USHORT NoTranslatorMask;
	/*020a*/ USHORT QueryTranslatorMask;
	/*020c*/ USHORT NoArbiterMask;
	/*020e*/ USHORT QueryArbiterMask;
	union {
		/*0210*/ _DEVICE_NODE * LegacyDeviceNode;
		/*0210*/ _DEVICE_RELATIONS * PendingDeviceRelations;
		/*0210*/ void * Information;
		/*0218*/
	} OverUsed1;
	union {
		/*0218*/ _DEVICE_NODE * NextResourceDeviceNode;
		/*0220*/
	} OverUsed2;
	/*0220*/ _CM_RESOURCE_LIST * BootResources;
	/*0228*/ _CM_RESOURCE_LIST * BootResourcesTranslated;
	/*0230*/ ULONG CapabilityFlags;
	struct {
		/*0238*/ PROFILE_STATUS DockStatus;
		/*0240*/ _LIST_ENTRY ListEntry;
		/*0250*/ WCHAR * SerialNumber;
		/*0258*/
	} DockInfo;
	/*0258*/ ULONG DisableableDepends;
	/*0260*/ _LIST_ENTRY PendedSetInterfaceState;
	/*0270*/ _LIST_ENTRY LegacyBusListEntry;
	/*0280*/ ULONG DriverUnloadRetryCount;
	/*0288*/ _DEVICE_NODE * PreviousParent;
	/*0290*/ LONG DeletedChildren;
	/*0294*/ ULONG NumaNodeIndex;
	/*0298*/ _GUID ContainerID;
	/*02a8*/ UCHAR OverrideFlags;
	/*02ac*/ ULONG DeviceIdsHash;
	/*02b0*/ UCHAR RequiresUnloadedDriver;
	/*02b8*/ _PENDING_RELATIONS_LIST_ENTRY * PendingEjectRelations;
	/*02c0*/ ULONG StateFlags;
	/*02c8*/ _PNP_REBALANCE_TRACE_CONTEXT * RebalanceContext;
	/*02d0*/ _DEVICE_NODE_IOMMU_EXTENSION * IommuExtension;
	/*02d8*/
};

struct _DEVICE_NODE_IOMMU_EXTENSION;

struct _DEVICE_OBJECT {
	/*0000*/ SHORT Type;
	/*0002*/ USHORT Size;
	/*0004*/ LONG ReferenceCount;
	/*0008*/ _DRIVER_OBJECT * DriverObject;
	/*0010*/ _DEVICE_OBJECT * NextDevice;
	/*0018*/ _DEVICE_OBJECT * AttachedDevice;
	/*0020*/ _IRP * CurrentIrp;
	/*0028*/ _IO_TIMER * Timer;
	/*0030*/ ULONG Flags;
	/*0034*/ ULONG Characteristics;
	/*0038*/ _VPB * Vpb;
	/*0040*/ void * DeviceExtension;
	/*0048*/ ULONG DeviceType;
	/*004c*/ CHAR StackSize;
	union {
		/*0050*/ _LIST_ENTRY ListEntry;
		/*0050*/ _WAIT_CONTEXT_BLOCK Wcb;
		/*0098*/
	} Queue;
	/*0098*/ ULONG AlignmentRequirement;
	/*00a0*/ _KDEVICE_QUEUE DeviceQueue;
	/*00c8*/ _KDPC Dpc;
	/*0108*/ ULONG ActiveThreadCount;
	/*0110*/ void * SecurityDescriptor;
	/*0118*/ _KEVENT DeviceLock;
	/*0130*/ USHORT SectorSize;
	/*0132*/ USHORT Spare1;
	/*0138*/ _DEVOBJ_EXTENSION * DeviceObjectExtension;
	/*0140*/ void * Reserved;
	/*0150*/
};

struct _DEVICE_OBJECT_LIST {
	/*0000*/ ULONG Count;
	/*0004*/ ULONG MaxCount;
	/*0008*/ ULONG TagCount;
	/*000c*/ _PNP_DEVICE_DELETE_TYPE OperationCode;
	/*0010*/ _DEVICE_OBJECT_LIST_ENTRY Devices[0x1];
	/*0028*/
};

struct _DEVICE_OBJECT_LIST_ENTRY {
	/*0000*/ _DEVICE_OBJECT * DeviceObject;
	/*0008*/ _DEVICE_RELATION_LEVEL RelationLevel;
	/*000c*/ ULONG Ordinal;
	/*0010*/ ULONG Flags;
	/*0018*/
};

struct _DEVICE_OBJECT_POWER_EXTENSION {
	/*0000*/ ULONG volatile IdleCount;
	/*0004*/ ULONG volatile BusyCount;
	/*0008*/ ULONG volatile BusyReference;
	/*000c*/ ULONG TotalBusyCount;
	/*0010*/ ULONG ConservationIdleTime;
	/*0014*/ ULONG PerformanceIdleTime;
	/*0018*/ _DEVICE_OBJECT * DeviceObject;
	/*0020*/ _LIST_ENTRY IdleList;
	/*0030*/ _POP_DEVICE_IDLE_TYPE IdleType;
	/*0034*/ _DEVICE_POWER_STATE IdleState;
	/*0038*/ _DEVICE_POWER_STATE CurrentState;
	/*0040*/ _POP_COOLING_EXTENSION * CoolingExtension;
	/*0048*/ _LIST_ENTRY Volume;
	union {
		struct {
			/*0058*/ ULONG IdleTime;
			/*005c*/ ULONG NonIdleTime;
			/*0060*/
		} Disk;
		/*0060*/
	} Specific;
	/*0060*/
};

enum _DEVICE_POWER_STATE {
	PowerDeviceUnspecified = 0x0,
	PowerDeviceD0 = 0x1,
	PowerDeviceD1 = 0x2,
	PowerDeviceD2 = 0x3,
	PowerDeviceD3 = 0x4,
	PowerDeviceMaximum = 0x5
};

struct _DEVICE_RELATIONS {
	/*0000*/ ULONG Count;
	/*0008*/ _DEVICE_OBJECT * Objects[0x1];
	/*0010*/
};

enum _DEVICE_RELATION_LEVEL {
	RELATION_LEVEL_REMOVE_EJECT = 0x0,
	RELATION_LEVEL_DEPENDENT = 0x1,
	RELATION_LEVEL_DIRECT_DESCENDANT = 0x2
};

enum _DEVICE_RELATION_TYPE {
	BusRelations = 0x0,
	EjectionRelations = 0x1,
	PowerRelations = 0x2,
	RemovalRelations = 0x3,
	TargetDeviceRelation = 0x4,
	SingleBusRelations = 0x5,
	TransportRelations = 0x6
};

enum _DEVICE_USAGE_NOTIFICATION_TYPE {
	DeviceUsageTypeUndefined = 0x0,
	DeviceUsageTypePaging = 0x1,
	DeviceUsageTypeHibernation = 0x2,
	DeviceUsageTypeDumpFile = 0x3,
	DeviceUsageTypeBoot = 0x4,
	DeviceUsageTypePostDisplay = 0x5
};

enum _DEVICE_WAKE_DEPTH {
	DeviceWakeDepthNotWakeable = 0x0,
	DeviceWakeDepthD0 = 0x1,
	DeviceWakeDepthD1 = 0x2,
	DeviceWakeDepthD2 = 0x3,
	DeviceWakeDepthD3hot = 0x4,
	DeviceWakeDepthD3cold = 0x5,
	DeviceWakeDepthMaximum = 0x6
};

struct _DEVOBJ_EXTENSION {
	/*0000*/ SHORT Type;
	/*0002*/ USHORT Size;
	/*0008*/ _DEVICE_OBJECT * DeviceObject;
	/*0010*/ ULONG PowerFlags;
	/*0018*/ _DEVICE_OBJECT_POWER_EXTENSION * Dope;
	/*0020*/ ULONG ExtensionFlags;
	/*0028*/ void * DeviceNode;
	/*0030*/ _DEVICE_OBJECT * AttachedTo;
	/*0038*/ LONG StartIoCount;
	/*003c*/ LONG StartIoKey;
	/*0040*/ ULONG StartIoFlags;
	/*0048*/ _VPB * Vpb;
	/*0050*/ void * DependencyNode;
	/*0058*/ void * InterruptContext;
	/*0060*/ void * VerifierContext;
	/*0068*/
};

enum _DEVPROP_OPERATOR {
	DEVPROP_OPERATOR_MODIFIER_NOT = 0x10000,
	DEVPROP_OPERATOR_MODIFIER_IGNORE_CASE = 0x20000,
	DEVPROP_OPERATOR_NONE = 0x0,
	DEVPROP_OPERATOR_EXISTS = 0x1,
	DEVPROP_OPERATOR_NOT_EXISTS = 0x10001,
	DEVPROP_OPERATOR_EQUALS = 0x2,
	DEVPROP_OPERATOR_NOT_EQUALS = 0x10002,
	DEVPROP_OPERATOR_GREATER_THAN = 0x3,
	DEVPROP_OPERATOR_LESS_THAN = 0x4,
	DEVPROP_OPERATOR_GREATER_THAN_EQUALS = 0x5,
	DEVPROP_OPERATOR_LESS_THAN_EQUALS = 0x6,
	DEVPROP_OPERATOR_EQUALS_IGNORE_CASE = 0x20002,
	DEVPROP_OPERATOR_NOT_EQUALS_IGNORE_CASE = 0x30002,
	DEVPROP_OPERATOR_BITWISE_AND = 0x7,
	DEVPROP_OPERATOR_BITWISE_OR = 0x8,
	DEVPROP_OPERATOR_BEGINS_WITH = 0x9,
	DEVPROP_OPERATOR_ENDS_WITH = 0xa,
	DEVPROP_OPERATOR_CONTAINS = 0xb,
	DEVPROP_OPERATOR_BEGINS_WITH_IGNORE_CASE = 0x20009,
	DEVPROP_OPERATOR_ENDS_WITH_IGNORE_CASE = 0x2000a,
	DEVPROP_OPERATOR_CONTAINS_IGNORE_CASE = 0x2000b,
	DEVPROP_OPERATOR_LIST_CONTAINS = 0x1000,
	DEVPROP_OPERATOR_LIST_ELEMENT_BEGINS_WITH = 0x2000,
	DEVPROP_OPERATOR_LIST_ELEMENT_ENDS_WITH = 0x3000,
	DEVPROP_OPERATOR_LIST_ELEMENT_CONTAINS = 0x4000,
	DEVPROP_OPERATOR_LIST_CONTAINS_IGNORE_CASE = 0x21000,
	DEVPROP_OPERATOR_LIST_ELEMENT_BEGINS_WITH_IGNORE_CASE = 0x22000,
	DEVPROP_OPERATOR_LIST_ELEMENT_ENDS_WITH_IGNORE_CASE = 0x23000,
	DEVPROP_OPERATOR_LIST_ELEMENT_CONTAINS_IGNORE_CASE = 0x24000,
	DEVPROP_OPERATOR_AND_OPEN = 0x100000,
	DEVPROP_OPERATOR_AND_CLOSE = 0x200000,
	DEVPROP_OPERATOR_OR_OPEN = 0x300000,
	DEVPROP_OPERATOR_OR_CLOSE = 0x400000,
	DEVPROP_OPERATOR_NOT_OPEN = 0x500000,
	DEVPROP_OPERATOR_NOT_CLOSE = 0x600000,
	DEVPROP_OPERATOR_ARRAY_CONTAINS = 0x10000000,
	DEVPROP_OPERATOR_MASK_EVAL = 0xfff,
	DEVPROP_OPERATOR_MASK_LIST = 0xf000,
	DEVPROP_OPERATOR_MASK_MODIFIER = 0xf0000,
	DEVPROP_OPERATOR_MASK_NOT_LOGICAL = 0xf00fffff,
	DEVPROP_OPERATOR_MASK_LOGICAL = 0xff00000,
	DEVPROP_OPERATOR_MASK_ARRAY = 0xf0000000
};

struct _DIAGNOSTIC_BUFFER {
	/*0000*/ ULONGLONG Size;
	/*0008*/ _REQUESTER_TYPE CallerType;
	/*0010*/ ULONGLONG ProcessImageNameOffset;
	/*0018*/ ULONG ProcessId;
	/*001c*/ ULONG ServiceTag;
	/*0010*/ ULONGLONG DeviceDescriptionOffset;
	/*0018*/ ULONGLONG DevicePathOffset;
	/*0020*/ ULONGLONG ReasonOffset;
	/*0028*/
};

struct _DIAGNOSTIC_CONTEXT {
	/*0000*/ _REQUESTER_TYPE CallerType;
	/*0008*/ _EPROCESS * Process;
	/*0010*/ ULONG ServiceTag;
	/*0008*/ _DEVICE_OBJECT * DeviceObject;
	/*0018*/ ULONGLONG ReasonSize;
	/*0020*/
};

enum _DIRECTORY_NOTIFY_INFORMATION_CLASS {
	DirectoryNotifyInformation = 0x1,
	DirectoryNotifyExtendedInformation = 0x2
};

struct _DIRTY_PAGE_STATISTICS {
	/*0000*/ ULONGLONG DirtyPages;
	/*0008*/ ULONGLONG DirtyPagesLastScan;
	/*0010*/ ULONG DirtyPagesScheduledLastScan;
	/*0018*/
};

struct _DIRTY_PAGE_THRESHOLDS {
	/*0000*/ ULONGLONG DirtyPageThreshold;
	/*0008*/ ULONGLONG DirtyPageThresholdTop;
	/*0010*/ ULONGLONG DirtyPageThresholdBottom;
	/*0018*/ ULONG DirtyPageTarget;
	/*0020*/ ULONGLONG AggregateAvailablePages;
	/*0028*/ ULONGLONG AggregateDirtyPages;
	/*0030*/ ULONG AvailableHistory;
	/*0038*/
};

struct _DISALLOWED_GUIDS {
	/*0000*/ USHORT Count;
	/*0008*/ _GUID * Guids;
	/*0010*/
};

struct _DISPATCHER_HEADER {
	/*0000*/ LONG volatile Lock;
	/*0000*/ LONG LockNV;
	/*0000*/ UCHAR Type;
	/*0001*/ UCHAR Signalling;
	/*0002*/ UCHAR Size;
	/*0003*/ UCHAR Reserved1;
	/*0000*/ UCHAR TimerType;
	/*0001*/ UCHAR TimerControlFlags;
	/*0001*/ UCHAR Absolute : 01; // 0x01;
	/*0001*/ UCHAR Wake : 01; // 0x02;
	/*0001*/ UCHAR EncodedTolerableDelay : 06; // 0xfc;
	/*0002*/ UCHAR Hand;
	/*0003*/ UCHAR TimerMiscFlags;
	/*0003*/ UCHAR Index : 06; // 0x3f;
	/*0003*/ UCHAR Inserted : 01; // 0x40;
	/*0003*/ UCHAR volatile Expired : 01; // 0x80;
	/*0000*/ UCHAR Timer2Type;
	/*0001*/ UCHAR Timer2Flags;
	/*0001*/ UCHAR Timer2Inserted : 01; // 0x01;
	/*0001*/ UCHAR Timer2Expiring : 01; // 0x02;
	/*0001*/ UCHAR Timer2CancelPending : 01; // 0x04;
	/*0001*/ UCHAR Timer2SetPending : 01; // 0x08;
	/*0001*/ UCHAR Timer2Running : 01; // 0x10;
	/*0001*/ UCHAR Timer2Disabled : 01; // 0x20;
	/*0001*/ UCHAR Timer2ReservedFlags : 02; // 0xc0;
	/*0002*/ UCHAR Timer2ComponentId;
	/*0003*/ UCHAR Timer2RelativeId;
	/*0000*/ UCHAR QueueType;
	/*0001*/ UCHAR QueueControlFlags;
	/*0001*/ UCHAR Abandoned : 01; // 0x01;
	/*0001*/ UCHAR DisableIncrement : 01; // 0x02;
	/*0001*/ UCHAR QueueReservedControlFlags : 06; // 0xfc;
	/*0002*/ UCHAR QueueSize;
	/*0003*/ UCHAR QueueReserved;
	/*0000*/ UCHAR ThreadType;
	/*0001*/ UCHAR ThreadReserved;
	/*0002*/ UCHAR ThreadControlFlags;
	/*0002*/ UCHAR CycleProfiling : 01; // 0x01;
	/*0002*/ UCHAR CounterProfiling : 01; // 0x02;
	/*0002*/ UCHAR GroupScheduling : 01; // 0x04;
	/*0002*/ UCHAR AffinitySet : 01; // 0x08;
	/*0002*/ UCHAR Tagged : 01; // 0x10;
	/*0002*/ UCHAR EnergyProfiling : 01; // 0x20;
	/*0002*/ UCHAR ThreadReservedControlFlags : 02; // 0xc0;
	/*0003*/ UCHAR DebugActive;
	/*0003*/ UCHAR ActiveDR7 : 01; // 0x01;
	/*0003*/ UCHAR Instrumented : 01; // 0x02;
	/*0003*/ UCHAR Minimal : 01; // 0x04;
	/*0003*/ UCHAR Reserved4 : 03; // 0x38;
	/*0003*/ UCHAR UmsScheduled : 01; // 0x40;
	/*0003*/ UCHAR UmsPrimary : 01; // 0x80;
	/*0000*/ UCHAR MutantType;
	/*0001*/ UCHAR MutantSize;
	/*0002*/ UCHAR DpcActive;
	/*0003*/ UCHAR MutantReserved;
	/*0004*/ LONG SignalState;
	/*0008*/ _LIST_ENTRY WaitListHead;
	/*0018*/
};

enum _DMA_SPEED {
	Compatible = 0x0,
	TypeA = 0x1,
	TypeB = 0x2,
	TypeC = 0x3,
	TypeF = 0x4,
	MaximumDmaSpeed = 0x5
};

enum _DMA_WIDTH {
	Width8Bits = 0x0,
	Width16Bits = 0x1,
	Width32Bits = 0x2,
	Width64Bits = 0x3,
	WidthNoWrap = 0x4,
	MaximumDmaWidth = 0x5
};

struct _DRIVER_EXTENSION {
	/*0000*/ _DRIVER_OBJECT * DriverObject;
	/*0008*/ LONG (* AddDevice)( _DRIVER_OBJECT * , _DEVICE_OBJECT * );
	/*0010*/ ULONG Count;
	/*0018*/ _UNICODE_STRING ServiceKeyName;
	/*0028*/ _IO_CLIENT_EXTENSION * ClientDriverExtension;
	/*0030*/ _FS_FILTER_CALLBACKS * FsFilterCallbacks;
	/*0038*/ void * KseCallbacks;
	/*0040*/ void * DvCallbacks;
	/*0048*/ void * VerifierContext;
	/*0050*/
};

struct _DRIVER_OBJECT {
	/*0000*/ SHORT Type;
	/*0002*/ SHORT Size;
	/*0008*/ _DEVICE_OBJECT * DeviceObject;
	/*0010*/ ULONG Flags;
	/*0018*/ void * DriverStart;
	/*0020*/ ULONG DriverSize;
	/*0028*/ void * DriverSection;
	/*0030*/ _DRIVER_EXTENSION * DriverExtension;
	/*0038*/ _UNICODE_STRING DriverName;
	/*0048*/ _UNICODE_STRING * HardwareDatabase;
	/*0050*/ _FAST_IO_DISPATCH * FastIoDispatch;
	/*0058*/ LONG (* DriverInit)( _DRIVER_OBJECT * , _UNICODE_STRING * );
	/*0060*/ void (* DriverStartIo)( _DEVICE_OBJECT * , _IRP * );
	/*0068*/ void (* DriverUnload)( _DRIVER_OBJECT * );
	/*0070*/ LONG (* MajorFunction[0x1c])( _DEVICE_OBJECT * , _IRP * );
	/*0150*/
};

struct _DUAL {
	/*0000*/ ULONG Length;
	/*0008*/ _HMAP_DIRECTORY * Map;
	/*0010*/ _HMAP_TABLE * SmallDir;
	/*0018*/ ULONG Guard;
	/*0020*/ _FREE_DISPLAY FreeDisplay[0x18];
	/*0260*/ _LIST_ENTRY FreeBins;
	/*0270*/ ULONG FreeSummary;
	/*0278*/
};

struct _DUMMY_FILE_OBJECT {
	/*0000*/ _OBJECT_HEADER ObjectHeader;
	/*0038*/ CHAR FileObjectBody[0xd8];
	/*0110*/
};

enum _DUMP_EVENTS {
	DUMP_EVENT_NONE = 0x0,
	DUMP_EVENT_HIBER_RESUME = 0x1,
	DUMP_EVENT_HIBER_RESUME_END = 0x2
};

struct _DUMP_INITIALIZATION_CONTEXT {
	/*0000*/ ULONG Length;
	/*0004*/ ULONG Reserved;
	/*0008*/ void * MemoryBlock;
	/*0010*/ void * CommonBuffer[0x2];
	/*0020*/ _LARGE_INTEGER PhysicalAddress[0x2];
	/*0030*/ void (* StallRoutine)( ULONG );
	/*0038*/ UCHAR (* OpenRoutine)( _LARGE_INTEGER );
	/*0040*/ LONG (* WriteRoutine)( _LARGE_INTEGER * , _MDL * );
	/*0048*/ void (* FinishRoutine)();
	/*0050*/ _ADAPTER_OBJECT * AdapterObject;
	/*0058*/ void * MappedRegisterBase;
	/*0060*/ void * PortConfiguration;
	/*0068*/ UCHAR CrashDump;
	/*0069*/ UCHAR MarkMemoryOnly;
	/*006a*/ UCHAR HiberResume;
	/*006b*/ UCHAR Reserved1;
	/*006c*/ ULONG MaximumTransferSize;
	/*0070*/ ULONG CommonBufferSize;
	/*0078*/ void * TargetAddress;
	/*0080*/ LONG (* WritePendingRoutine)( LONG , _LARGE_INTEGER * , _MDL * , void * );
	/*0088*/ ULONG PartitionStyle;
	union {
		struct {
			/*008c*/ ULONG Signature;
			/*0090*/ ULONG CheckSum;
			/*0094*/
		} Mbr;
		struct {
			/*008c*/ _GUID DiskId;
			/*009c*/
		} Gpt;
		/*009c*/
	} DiskInfo;
	/*00a0*/ LONG (* ReadRoutine)( LONG , _LARGE_INTEGER * , _MDL * );
	/*00a8*/ LONG (* GetDriveTelemetryRoutine)( ULONG , ULONG , void * , ULONG );
	/*00b0*/ ULONG LogSectionTruncateSize;
	/*00b4*/ ULONG Parameters[0x10];
	/*00f8*/ void (* GetTransferSizesRoutine)( ULONG * , ULONG * );
	/*0100*/ void (* DumpNotifyRoutine)( _DUMP_EVENTS , void * , ULONG );
	/*0108*/
};

struct _DUMP_STACK_CONTEXT {
	/*0000*/ _DUMP_INITIALIZATION_CONTEXT Init;
	/*0108*/ _LARGE_INTEGER PartitionOffset;
	/*0110*/ void * DumpPointers;
	/*0110*/ void * StorageInfo;
	/*0118*/ UCHAR UseStorageInfo;
	/*011c*/ ULONG PointersLength;
	/*0120*/ WCHAR * ModulePrefix;
	/*0128*/ _LIST_ENTRY DriverList;
	/*0138*/ _STRING InitMsg;
	/*0148*/ _STRING ProgMsg;
	/*0158*/ _STRING DoneMsg;
	/*0168*/ void * FileObject;
	/*0170*/ _DEVICE_USAGE_NOTIFICATION_TYPE UsageType;
	/*0178*/
};

struct _DYNAMIC_FUNCTION_TABLE {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _IMAGE_RUNTIME_FUNCTION_ENTRY * FunctionTable;
	/*0018*/ _LARGE_INTEGER TimeStamp;
	/*0020*/ ULONGLONG MinimumAddress;
	/*0028*/ ULONGLONG MaximumAddress;
	/*0030*/ ULONGLONG BaseAddress;
	/*0038*/ _IMAGE_RUNTIME_FUNCTION_ENTRY * (* Callback)( ULONGLONG , void * );
	/*0040*/ void * Context;
	/*0048*/ WCHAR * OutOfProcessCallbackDll;
	/*0050*/ _FUNCTION_TABLE_TYPE Type;
	/*0054*/ ULONG EntryCount;
	/*0058*/ _RTL_BALANCED_NODE TreeNode;
	/*0070*/
};

struct _ECP_LIST {
	/*0000*/ ULONG Signature;
	/*0004*/ ULONG Flags;
	/*0008*/ _LIST_ENTRY EcpList;
	/*0018*/
};

struct _EJOB {
	/*0000*/ _KEVENT Event;
	/*0018*/ _LIST_ENTRY JobLinks;
	/*0028*/ _LIST_ENTRY ProcessListHead;
	/*0038*/ _ERESOURCE JobLock;
	/*00a0*/ _LARGE_INTEGER TotalUserTime;
	/*00a8*/ _LARGE_INTEGER TotalKernelTime;
	/*00b0*/ _LARGE_INTEGER TotalCycleTime;
	/*00b8*/ _LARGE_INTEGER ThisPeriodTotalUserTime;
	/*00c0*/ _LARGE_INTEGER ThisPeriodTotalKernelTime;
	/*00c8*/ ULONGLONG TotalContextSwitches;
	/*00d0*/ ULONG TotalPageFaultCount;
	/*00d4*/ ULONG TotalProcesses;
	/*00d8*/ ULONG ActiveProcesses;
	/*00dc*/ ULONG TotalTerminatedProcesses;
	/*00e0*/ _LARGE_INTEGER PerProcessUserTimeLimit;
	/*00e8*/ _LARGE_INTEGER PerJobUserTimeLimit;
	/*00f0*/ ULONGLONG MinimumWorkingSetSize;
	/*00f8*/ ULONGLONG MaximumWorkingSetSize;
	/*0100*/ ULONG LimitFlags;
	/*0104*/ ULONG ActiveProcessLimit;
	/*0108*/ _KAFFINITY_EX Affinity;
	/*01b0*/ _JOB_ACCESS_STATE * AccessState;
	/*01b8*/ void * AccessStateQuotaReference;
	/*01c0*/ ULONG UIRestrictionsClass;
	/*01c4*/ ULONG EndOfJobTimeAction;
	/*01c8*/ void * CompletionPort;
	/*01d0*/ void * CompletionKey;
	/*01d8*/ ULONGLONG CompletionCount;
	/*01e0*/ ULONG SessionId;
	/*01e4*/ ULONG SchedulingClass;
	/*01e8*/ ULONGLONG ReadOperationCount;
	/*01f0*/ ULONGLONG WriteOperationCount;
	/*01f8*/ ULONGLONG OtherOperationCount;
	/*0200*/ ULONGLONG ReadTransferCount;
	/*0208*/ ULONGLONG WriteTransferCount;
	/*0210*/ ULONGLONG OtherTransferCount;
	/*0218*/ _PROCESS_DISK_COUNTERS DiskIoInfo;
	/*0240*/ ULONGLONG ProcessMemoryLimit;
	/*0248*/ ULONGLONG JobMemoryLimit;
	/*0250*/ ULONGLONG JobTotalMemoryLimit;
	/*0258*/ ULONGLONG PeakProcessMemoryUsed;
	/*0260*/ ULONGLONG PeakJobMemoryUsed;
	/*0268*/ _KAFFINITY_EX EffectiveAffinity;
	/*0310*/ _LARGE_INTEGER EffectivePerProcessUserTimeLimit;
	/*0318*/ ULONGLONG EffectiveMinimumWorkingSetSize;
	/*0320*/ ULONGLONG EffectiveMaximumWorkingSetSize;
	/*0328*/ ULONGLONG EffectiveProcessMemoryLimit;
	/*0330*/ _EJOB * EffectiveProcessMemoryLimitJob;
	/*0338*/ _EJOB * EffectivePerProcessUserTimeLimitJob;
	/*0340*/ _EJOB * EffectiveNetIoRateLimitJob;
	/*0348*/ _EJOB * EffectiveHeapAttributionJob;
	/*0350*/ ULONG EffectiveLimitFlags;
	/*0354*/ ULONG EffectiveSchedulingClass;
	/*0358*/ ULONG EffectiveFreezeCount;
	/*035c*/ ULONG EffectiveBackgroundCount;
	/*0360*/ ULONG EffectiveSwapCount;
	/*0364*/ ULONG EffectiveNotificationLimitCount;
	/*0368*/ UCHAR EffectivePriorityClass;
	/*0369*/ UCHAR PriorityClass;
	/*036a*/ UCHAR NestingDepth;
	/*036b*/ UCHAR Reserved1[0x1];
	/*036c*/ ULONG CompletionFilter;
	/*0370*/ _WNF_STATE_NAME WakeChannel;
	/*0370*/ _PS_JOB_WAKE_INFORMATION WakeInfo;
	/*03b8*/ _JOBOBJECT_WAKE_FILTER WakeFilter;
	/*03c0*/ ULONG LowEdgeLatchFilter;
	/*03c8*/ _EJOB * NotificationLink;
	/*03d0*/ ULONGLONG CurrentJobMemoryUsed;
	/*03d8*/ _JOB_NOTIFICATION_INFORMATION * NotificationInfo;
	/*03e0*/ void * NotificationInfoQuotaReference;
	/*03e8*/ _IO_MINI_COMPLETION_PACKET_USER * NotificationPacket;
	/*03f0*/ _JOB_CPU_RATE_CONTROL * CpuRateControl;
	/*03f8*/ void * EffectiveSchedulingGroup;
	/*0400*/ ULONGLONG ReadyTime;
	/*0408*/ _EX_PUSH_LOCK MemoryLimitsLock;
	/*0410*/ _LIST_ENTRY SiblingJobLinks;
	/*0420*/ _LIST_ENTRY ChildJobListHead;
	/*0430*/ _EJOB * ParentJob;
	/*0438*/ _EJOB * volatile RootJob;
	/*0440*/ _LIST_ENTRY IteratorListHead;
	/*0450*/ ULONGLONG AncestorCount;
	/*0458*/ _EJOB * * Ancestors;
	/*0458*/ void * SessionObject;
	/*0460*/ _EPROCESS_VALUES Accounting;
	/*04b8*/ ULONG ShadowActiveProcessCount;
	/*04bc*/ ULONG ActiveAuxiliaryProcessCount;
	/*04c0*/ ULONG SequenceNumber;
	/*04c4*/ ULONG JobId;
	/*04c8*/ _GUID ContainerId;
	/*04d8*/ _GUID ContainerTelemetryId;
	/*04e8*/ _ESERVERSILO_GLOBALS * ServerSiloGlobals;
	/*04f0*/ _PS_PROPERTY_SET PropertySet;
	/*0508*/ _PSP_STORAGE * Storage;
	/*0510*/ _JOB_NET_RATE_CONTROL * NetRateControl;
	/*0518*/ ULONG JobFlags;
	/*0518*/ ULONG CloseDone : 01; // 0x00000001;
	/*0518*/ ULONG MultiGroup : 01; // 0x00000002;
	/*0518*/ ULONG OutstandingNotification : 01; // 0x00000004;
	/*0518*/ ULONG NotificationInProgress : 01; // 0x00000008;
	/*0518*/ ULONG UILimits : 01; // 0x00000010;
	/*0518*/ ULONG CpuRateControlActive : 01; // 0x00000020;
	/*0518*/ ULONG OwnCpuRateControl : 01; // 0x00000040;
	/*0518*/ ULONG Terminating : 01; // 0x00000080;
	/*0518*/ ULONG WorkingSetLock : 01; // 0x00000100;
	/*0518*/ ULONG JobFrozen : 01; // 0x00000200;
	/*0518*/ ULONG Background : 01; // 0x00000400;
	/*0518*/ ULONG WakeNotificationAllocated : 01; // 0x00000800;
	/*0518*/ ULONG WakeNotificationEnabled : 01; // 0x00001000;
	/*0518*/ ULONG WakeNotificationPending : 01; // 0x00002000;
	/*0518*/ ULONG LimitNotificationRequired : 01; // 0x00004000;
	/*0518*/ ULONG ZeroCountNotificationRequired : 01; // 0x00008000;
	/*0518*/ ULONG CycleTimeNotificationRequired : 01; // 0x00010000;
	/*0518*/ ULONG CycleTimeNotificationPending : 01; // 0x00020000;
	/*0518*/ ULONG TimersVirtualized : 01; // 0x00040000;
	/*0518*/ ULONG JobSwapped : 01; // 0x00080000;
	/*0518*/ ULONG ViolationDetected : 01; // 0x00100000;
	/*0518*/ ULONG EmptyJobNotified : 01; // 0x00200000;
	/*0518*/ ULONG NoSystemCharge : 01; // 0x00400000;
	/*0518*/ ULONG DropNoWakeCharges : 01; // 0x00800000;
	/*0518*/ ULONG NoWakeChargePolicyDecided : 01; // 0x01000000;
	/*0518*/ ULONG NetRateControlActive : 01; // 0x02000000;
	/*0518*/ ULONG OwnNetRateControl : 01; // 0x04000000;
	/*0518*/ ULONG IoRateControlActive : 01; // 0x08000000;
	/*0518*/ ULONG OwnIoRateControl : 01; // 0x10000000;
	/*0518*/ ULONG DisallowNewProcesses : 01; // 0x20000000;
	/*0518*/ ULONG Silo : 01; // 0x40000000;
	/*0518*/ ULONG ContainerTelemetryIdSet : 01; // 0x80000000;
	/*051c*/ ULONG JobFlags2;
	/*051c*/ ULONG ParentLocked : 01; // 0x00000001;
	/*051c*/ ULONG EnableUsermodeSiloThreadImpersonation : 01; // 0x00000002;
	/*051c*/ ULONG DisallowUsermodeSiloThreadImpersonation : 01; // 0x00000004;
	/*0520*/ _PROCESS_EXTENDED_ENERGY_VALUES * EnergyValues;
	/*0528*/ ULONGLONG volatile SharedCommitCharge;
	/*0530*/ ULONG DiskIoAttributionUserRefCount;
	/*0534*/ ULONG DiskIoAttributionRefCount;
	/*0538*/ void * DiskIoAttributionContext;
	/*0538*/ _EJOB * DiskIoAttributionOwnerJob;
	/*0540*/ _JOB_RATE_CONTROL_HEADER IoRateControlHeader;
	/*0568*/ _PS_IO_CONTROL_ENTRY GlobalIoControl;
	/*05a0*/ LONG volatile IoControlStateLock;
	/*05a8*/ _RTL_RB_TREE VolumeIoControlTree;
	/*05b8*/ ULONGLONG IoRateOverQuotaHistory;
	/*05c0*/ ULONG IoRateCurrentGeneration;
	/*05c4*/ ULONG IoRateLastQueryGeneration;
	/*05c8*/ ULONG IoRateGenerationLength;
	/*05cc*/ ULONG IoRateOverQuotaNotifySequenceId;
	/*05d0*/ ULONGLONG LastThrottledIoTime;
	/*05d8*/ _EX_PUSH_LOCK IoControlLock;
	/*05e0*/ ULONGLONG SiloHardReferenceCount;
	/*05e8*/ _WORK_QUEUE_ITEM RundownWorkItem;
	/*0608*/ void * PartitionObject;
	/*0610*/ _EJOB * PartitionOwnerJob;
	/*0618*/ _JOBOBJECT_ENERGY_TRACKING_STATE EnergyTrackingState;
	/*0620*/
};

union _ENERGY_STATE_DURATION {
	/*0000*/ ULONGLONG Value;
	/*0000*/ ULONG LastChangeTime;
	/*0004*/ ULONG Duration : 31; // 0x7fffffff;
	/*0004*/ ULONG IsInState : 01; // 0x80000000;
	/*0008*/
};

struct _ENODE {
	/*0000*/ _KNODE Ncb;
	/*0140*/ _WORK_QUEUE_ITEM HotAddProcessorWorkItem;
	/*0180*/
};

struct _EPARTITION {
	/*0000*/ void * MmPartition;
	/*0008*/ void * CcPartition;
	/*0010*/ void * ExPartition;
	/*0018*/ LONGLONG HardReferenceCount;
	/*0020*/ LONGLONG OpenHandleCount;
	/*0028*/ _LIST_ENTRY ActivePartitionLinks;
	/*0038*/ _EPARTITION * ParentPartition;
	/*0040*/ _WORK_QUEUE_ITEM TeardownWorkItem;
	/*0060*/ _EX_PUSH_LOCK TeardownLock;
	/*0068*/ _EPROCESS * SystemProcess;
	/*0070*/ void * SystemProcessHandle;
	/*0078*/ ULONG PartitionFlags;
	/*0078*/ ULONG PairedWithJob : 01; // 0x00000001;
	/*007c*/ ULONG Padding;
	/*0080*/
};

struct _EPROCESS {
	/*0000*/ _KPROCESS Pcb;
	/*02d8*/ _EX_PUSH_LOCK ProcessLock;
	/*02e0*/ void * UniqueProcessId;
	/*02e8*/ _LIST_ENTRY ActiveProcessLinks;
	/*02f8*/ _EX_RUNDOWN_REF RundownProtect;
	/*0300*/ ULONG Flags2;
	/*0300*/ ULONG JobNotReallyActive : 01; // 0x00000001;
	/*0300*/ ULONG AccountingFolded : 01; // 0x00000002;
	/*0300*/ ULONG NewProcessReported : 01; // 0x00000004;
	/*0300*/ ULONG ExitProcessReported : 01; // 0x00000008;
	/*0300*/ ULONG ReportCommitChanges : 01; // 0x00000010;
	/*0300*/ ULONG LastReportMemory : 01; // 0x00000020;
	/*0300*/ ULONG ForceWakeCharge : 01; // 0x00000040;
	/*0300*/ ULONG CrossSessionCreate : 01; // 0x00000080;
	/*0300*/ ULONG NeedsHandleRundown : 01; // 0x00000100;
	/*0300*/ ULONG RefTraceEnabled : 01; // 0x00000200;
	/*0300*/ ULONG PicoCreated : 01; // 0x00000400;
	/*0300*/ ULONG EmptyJobEvaluated : 01; // 0x00000800;
	/*0300*/ ULONG DefaultPagePriority : 03; // 0x00007000;
	/*0300*/ ULONG PrimaryTokenFrozen : 01; // 0x00008000;
	/*0300*/ ULONG ProcessVerifierTarget : 01; // 0x00010000;
	/*0300*/ ULONG RestrictSetThreadContext : 01; // 0x00020000;
	/*0300*/ ULONG AffinityPermanent : 01; // 0x00040000;
	/*0300*/ ULONG AffinityUpdateEnable : 01; // 0x00080000;
	/*0300*/ ULONG PropagateNode : 01; // 0x00100000;
	/*0300*/ ULONG ExplicitAffinity : 01; // 0x00200000;
	/*0300*/ ULONG ProcessExecutionState : 02; // 0x00c00000;
	/*0300*/ ULONG EnableReadVmLogging : 01; // 0x01000000;
	/*0300*/ ULONG EnableWriteVmLogging : 01; // 0x02000000;
	/*0300*/ ULONG FatalAccessTerminationRequested : 01; // 0x04000000;
	/*0300*/ ULONG DisableSystemAllowedCpuSet : 01; // 0x08000000;
	/*0300*/ ULONG ProcessStateChangeRequest : 02; // 0x30000000;
	/*0300*/ ULONG ProcessStateChangeInProgress : 01; // 0x40000000;
	/*0300*/ ULONG InPrivate : 01; // 0x80000000;
	/*0304*/ ULONG Flags;
	/*0304*/ ULONG CreateReported : 01; // 0x00000001;
	/*0304*/ ULONG NoDebugInherit : 01; // 0x00000002;
	/*0304*/ ULONG ProcessExiting : 01; // 0x00000004;
	/*0304*/ ULONG ProcessDelete : 01; // 0x00000008;
	/*0304*/ ULONG ManageExecutableMemoryWrites : 01; // 0x00000010;
	/*0304*/ ULONG VmDeleted : 01; // 0x00000020;
	/*0304*/ ULONG OutswapEnabled : 01; // 0x00000040;
	/*0304*/ ULONG Outswapped : 01; // 0x00000080;
	/*0304*/ ULONG FailFastOnCommitFail : 01; // 0x00000100;
	/*0304*/ ULONG Wow64VaSpace4Gb : 01; // 0x00000200;
	/*0304*/ ULONG AddressSpaceInitialized : 02; // 0x00000c00;
	/*0304*/ ULONG SetTimerResolution : 01; // 0x00001000;
	/*0304*/ ULONG BreakOnTermination : 01; // 0x00002000;
	/*0304*/ ULONG DeprioritizeViews : 01; // 0x00004000;
	/*0304*/ ULONG WriteWatch : 01; // 0x00008000;
	/*0304*/ ULONG ProcessInSession : 01; // 0x00010000;
	/*0304*/ ULONG OverrideAddressSpace : 01; // 0x00020000;
	/*0304*/ ULONG HasAddressSpace : 01; // 0x00040000;
	/*0304*/ ULONG LaunchPrefetched : 01; // 0x00080000;
	/*0304*/ ULONG Background : 01; // 0x00100000;
	/*0304*/ ULONG VmTopDown : 01; // 0x00200000;
	/*0304*/ ULONG ImageNotifyDone : 01; // 0x00400000;
	/*0304*/ ULONG PdeUpdateNeeded : 01; // 0x00800000;
	/*0304*/ ULONG VdmAllowed : 01; // 0x01000000;
	/*0304*/ ULONG ProcessRundown : 01; // 0x02000000;
	/*0304*/ ULONG ProcessInserted : 01; // 0x04000000;
	/*0304*/ ULONG DefaultIoPriority : 03; // 0x38000000;
	/*0304*/ ULONG ProcessSelfDelete : 01; // 0x40000000;
	/*0304*/ ULONG SetTimerResolutionLink : 01; // 0x80000000;
	/*0308*/ _LARGE_INTEGER CreateTime;
	/*0310*/ ULONGLONG ProcessQuotaUsage[0x2];
	/*0320*/ ULONGLONG ProcessQuotaPeak[0x2];
	/*0330*/ ULONGLONG PeakVirtualSize;
	/*0338*/ ULONGLONG VirtualSize;
	/*0340*/ _LIST_ENTRY SessionProcessLinks;
	/*0350*/ void * ExceptionPortData;
	/*0350*/ ULONGLONG ExceptionPortValue;
	/*0350*/ ULONGLONG ExceptionPortState : 03; // 0x0000000000000007;
	/*0358*/ _EX_FAST_REF Token;
	/*0360*/ ULONGLONG MmReserved;
	/*0368*/ _EX_PUSH_LOCK AddressCreationLock;
	/*0370*/ _EX_PUSH_LOCK PageTableCommitmentLock;
	/*0378*/ _ETHREAD * RotateInProgress;
	/*0380*/ _ETHREAD * ForkInProgress;
	/*0388*/ _EJOB * volatile CommitChargeJob;
	/*0390*/ _RTL_AVL_TREE CloneRoot;
	/*0398*/ ULONGLONG volatile NumberOfPrivatePages;
	/*03a0*/ ULONGLONG volatile NumberOfLockedPages;
	/*03a8*/ void * Win32Process;
	/*03b0*/ _EJOB * volatile Job;
	/*03b8*/ void * SectionObject;
	/*03c0*/ void * SectionBaseAddress;
	/*03c8*/ ULONG Cookie;
	/*03d0*/ _PAGEFAULT_HISTORY * WorkingSetWatch;
	/*03d8*/ void * Win32WindowStation;
	/*03e0*/ void * InheritedFromUniqueProcessId;
	/*03e8*/ void * LdtInformation;
	/*03f0*/ ULONGLONG volatile OwnerProcessId;
	/*03f8*/ _PEB * Peb;
	/*0400*/ _MM_SESSION_SPACE * Session;
	/*0408*/ void * AweInfo;
	/*0410*/ _EPROCESS_QUOTA_BLOCK * QuotaBlock;
	/*0418*/ _HANDLE_TABLE * ObjectTable;
	/*0420*/ void * DebugPort;
	/*0428*/ _EWOW64PROCESS * WoW64Process;
	/*0430*/ void * DeviceMap;
	/*0438*/ void * EtwDataSource;
	/*0440*/ ULONGLONG PageDirectoryPte;
	/*0448*/ _FILE_OBJECT * ImageFilePointer;
	/*0450*/ UCHAR ImageFileName[0xf];
	/*045f*/ UCHAR PriorityClass;
	/*0460*/ void * SecurityPort;
	/*0468*/ _SE_AUDIT_PROCESS_CREATION_INFO SeAuditProcessCreationInfo;
	/*0470*/ _LIST_ENTRY JobLinks;
	/*0480*/ void * HighestUserAddress;
	/*0488*/ _LIST_ENTRY ThreadListHead;
	/*0498*/ ULONG volatile ActiveThreads;
	/*049c*/ ULONG ImagePathHash;
	/*04a0*/ ULONG DefaultHardErrorProcessing;
	/*04a4*/ LONG LastThreadExitStatus;
	/*04a8*/ _EX_FAST_REF PrefetchTrace;
	/*04b0*/ void * LockedPagesList;
	/*04b8*/ _LARGE_INTEGER ReadOperationCount;
	/*04c0*/ _LARGE_INTEGER WriteOperationCount;
	/*04c8*/ _LARGE_INTEGER OtherOperationCount;
	/*04d0*/ _LARGE_INTEGER ReadTransferCount;
	/*04d8*/ _LARGE_INTEGER WriteTransferCount;
	/*04e0*/ _LARGE_INTEGER OtherTransferCount;
	/*04e8*/ ULONGLONG CommitChargeLimit;
	/*04f0*/ ULONGLONG volatile CommitCharge;
	/*04f8*/ ULONGLONG volatile CommitChargePeak;
	/*0500*/ _MMSUPPORT_FULL Vm;
	/*0610*/ _LIST_ENTRY MmProcessLinks;
	/*0620*/ ULONG ModifiedPageCount;
	/*0624*/ LONG ExitStatus;
	/*0628*/ _RTL_AVL_TREE VadRoot;
	/*0630*/ void * VadHint;
	/*0638*/ ULONGLONG VadCount;
	/*0640*/ ULONGLONG volatile VadPhysicalPages;
	/*0648*/ ULONGLONG VadPhysicalPagesLimit;
	/*0650*/ _ALPC_PROCESS_CONTEXT AlpcContext;
	/*0670*/ _LIST_ENTRY TimerResolutionLink;
	/*0680*/ _PO_DIAG_STACK_RECORD * TimerResolutionStackRecord;
	/*0688*/ ULONG RequestedTimerResolution;
	/*068c*/ ULONG SmallestTimerResolution;
	/*0690*/ _LARGE_INTEGER ExitTime;
	/*0698*/ _INVERTED_FUNCTION_TABLE * InvertedFunctionTable;
	/*06a0*/ _EX_PUSH_LOCK InvertedFunctionTableLock;
	/*06a8*/ ULONG ActiveThreadsHighWatermark;
	/*06ac*/ ULONG LargePrivateVadCount;
	/*06b0*/ _EX_PUSH_LOCK ThreadListLock;
	/*06b8*/ void * WnfContext;
	/*06c0*/ _EJOB * ServerSilo;
	/*06c8*/ UCHAR SignatureLevel;
	/*06c9*/ UCHAR SectionSignatureLevel;
	/*06ca*/ _PS_PROTECTION Protection;
	/*06cb*/ UCHAR HangCount : 04; // 0x0f;
	/*06cb*/ UCHAR GhostCount : 04; // 0xf0;
	/*06cc*/ ULONG Flags3;
	/*06cc*/ ULONG Minimal : 01; // 0x00000001;
	/*06cc*/ ULONG ReplacingPageRoot : 01; // 0x00000002;
	/*06cc*/ ULONG Crashed : 01; // 0x00000004;
	/*06cc*/ ULONG JobVadsAreTracked : 01; // 0x00000008;
	/*06cc*/ ULONG VadTrackingDisabled : 01; // 0x00000010;
	/*06cc*/ ULONG AuxiliaryProcess : 01; // 0x00000020;
	/*06cc*/ ULONG SubsystemProcess : 01; // 0x00000040;
	/*06cc*/ ULONG IndirectCpuSets : 01; // 0x00000080;
	/*06cc*/ ULONG RelinquishedCommit : 01; // 0x00000100;
	/*06cc*/ ULONG HighGraphicsPriority : 01; // 0x00000200;
	/*06cc*/ ULONG CommitFailLogged : 01; // 0x00000400;
	/*06cc*/ ULONG ReserveFailLogged : 01; // 0x00000800;
	/*06cc*/ ULONG SystemProcess : 01; // 0x00001000;
	/*06cc*/ ULONG HideImageBaseAddresses : 01; // 0x00002000;
	/*06d0*/ LONG DeviceAsid;
	/*06d8*/ void * SvmData;
	/*06e0*/ _EX_PUSH_LOCK SvmProcessLock;
	/*06e8*/ ULONGLONG SvmLock;
	/*06f0*/ _LIST_ENTRY SvmProcessDeviceListHead;
	/*0700*/ ULONGLONG LastFreezeInterruptTime;
	/*0708*/ _PROCESS_DISK_COUNTERS * DiskCounters;
	/*0710*/ void * PicoContext;
	/*0718*/ ULONGLONG TrustletIdentity;
	/*0720*/ void * EnclaveTable;
	/*0728*/ ULONGLONG EnclaveNumber;
	/*0730*/ _EX_PUSH_LOCK EnclaveLock;
	/*0738*/ ULONG HighPriorityFaultsAllowed;
	/*0740*/ _PO_PROCESS_ENERGY_CONTEXT * EnergyContext;
	/*0748*/ void * VmContext;
	/*0750*/ ULONGLONG SequenceNumber;
	/*0758*/ ULONGLONG CreateInterruptTime;
	/*0760*/ ULONGLONG CreateUnbiasedInterruptTime;
	/*0768*/ ULONGLONG TotalUnbiasedFrozenTime;
	/*0770*/ ULONGLONG LastAppStateUpdateTime;
	/*0778*/ ULONGLONG LastAppStateUptime : 61; // 0x1fffffffffffffff;
	/*0778*/ ULONGLONG LastAppState : 03; // 0xe000000000000000;
	/*0780*/ ULONGLONG volatile SharedCommitCharge;
	/*0788*/ _EX_PUSH_LOCK SharedCommitLock;
	/*0790*/ _LIST_ENTRY SharedCommitLinks;
	/*07a0*/ ULONGLONG AllowedCpuSets;
	/*07a8*/ ULONGLONG DefaultCpuSets;
	/*07a0*/ ULONGLONG * AllowedCpuSetsIndirect;
	/*07a8*/ ULONGLONG * DefaultCpuSetsIndirect;
	/*07b0*/ void * DiskIoAttribution;
	/*07b8*/ void * DxgProcess;
	/*07c0*/ ULONG Win32KFilterSet;
	/*07c8*/ _PS_INTERLOCKED_TIMER_DELAY_VALUES volatile ProcessTimerDelay;
	/*07d0*/ ULONG volatile KTimerSets;
	/*07d4*/ ULONG volatile KTimer2Sets;
	/*07d8*/ ULONG volatile ThreadTimerSets;
	/*07e0*/ ULONGLONG VirtualTimerListLock;
	/*07e8*/ _LIST_ENTRY VirtualTimerListHead;
	/*07f8*/ _WNF_STATE_NAME WakeChannel;
	/*07f8*/ _PS_PROCESS_WAKE_INFORMATION WakeInfo;
	/*0828*/ ULONG MitigationFlags;
	struct {
		/*0828*/ ULONG ControlFlowGuardEnabled : 01; // 0x00000001;
		/*0828*/ ULONG ControlFlowGuardExportSuppressionEnabled : 01; // 0x00000002;
		/*0828*/ ULONG ControlFlowGuardStrict : 01; // 0x00000004;
		/*0828*/ ULONG DisallowStrippedImages : 01; // 0x00000008;
		/*0828*/ ULONG ForceRelocateImages : 01; // 0x00000010;
		/*0828*/ ULONG HighEntropyASLREnabled : 01; // 0x00000020;
		/*0828*/ ULONG StackRandomizationDisabled : 01; // 0x00000040;
		/*0828*/ ULONG ExtensionPointDisable : 01; // 0x00000080;
		/*0828*/ ULONG DisableDynamicCode : 01; // 0x00000100;
		/*0828*/ ULONG DisableDynamicCodeAllowOptOut : 01; // 0x00000200;
		/*0828*/ ULONG DisableDynamicCodeAllowRemoteDowngrade : 01; // 0x00000400;
		/*0828*/ ULONG AuditDisableDynamicCode : 01; // 0x00000800;
		/*0828*/ ULONG DisallowWin32kSystemCalls : 01; // 0x00001000;
		/*0828*/ ULONG AuditDisallowWin32kSystemCalls : 01; // 0x00002000;
		/*0828*/ ULONG EnableFilteredWin32kAPIs : 01; // 0x00004000;
		/*0828*/ ULONG AuditFilteredWin32kAPIs : 01; // 0x00008000;
		/*0828*/ ULONG DisableNonSystemFonts : 01; // 0x00010000;
		/*0828*/ ULONG AuditNonSystemFontLoading : 01; // 0x00020000;
		/*0828*/ ULONG PreferSystem32Images : 01; // 0x00040000;
		/*0828*/ ULONG ProhibitRemoteImageMap : 01; // 0x00080000;
		/*0828*/ ULONG AuditProhibitRemoteImageMap : 01; // 0x00100000;
		/*0828*/ ULONG ProhibitLowILImageMap : 01; // 0x00200000;
		/*0828*/ ULONG AuditProhibitLowILImageMap : 01; // 0x00400000;
		/*0828*/ ULONG SignatureMitigationOptIn : 01; // 0x00800000;
		/*0828*/ ULONG AuditBlockNonMicrosoftBinaries : 01; // 0x01000000;
		/*0828*/ ULONG AuditBlockNonMicrosoftBinariesAllowStore : 01; // 0x02000000;
		/*0828*/ ULONG LoaderIntegrityContinuityEnabled : 01; // 0x04000000;
		/*0828*/ ULONG AuditLoaderIntegrityContinuity : 01; // 0x08000000;
		/*0828*/ ULONG EnableModuleTamperingProtection : 01; // 0x10000000;
		/*0828*/ ULONG EnableModuleTamperingProtectionNoInherit : 01; // 0x20000000;
		/*082c*/
	} MitigationFlagsValues;
	/*082c*/ ULONG MitigationFlags2;
	struct {
		/*082c*/ ULONG EnableExportAddressFilter : 01; // 0x00000001;
		/*082c*/ ULONG AuditExportAddressFilter : 01; // 0x00000002;
		/*082c*/ ULONG EnableExportAddressFilterPlus : 01; // 0x00000004;
		/*082c*/ ULONG AuditExportAddressFilterPlus : 01; // 0x00000008;
		/*082c*/ ULONG EnableRopStackPivot : 01; // 0x00000010;
		/*082c*/ ULONG AuditRopStackPivot : 01; // 0x00000020;
		/*082c*/ ULONG EnableRopCallerCheck : 01; // 0x00000040;
		/*082c*/ ULONG AuditRopCallerCheck : 01; // 0x00000080;
		/*082c*/ ULONG EnableRopSimExec : 01; // 0x00000100;
		/*082c*/ ULONG AuditRopSimExec : 01; // 0x00000200;
		/*082c*/ ULONG EnableImportAddressFilter : 01; // 0x00000400;
		/*082c*/ ULONG AuditImportAddressFilter : 01; // 0x00000800;
		/*0830*/
	} MitigationFlags2Values;
	/*0830*/ void * PartitionObject;
	/*0838*/
};

struct _EPROCESS_QUOTA_BLOCK;

struct _EPROCESS_VALUES {
	/*0000*/ ULONGLONG KernelTime;
	/*0008*/ ULONGLONG UserTime;
	/*0010*/ ULONGLONG ReadyTime;
	/*0018*/ ULONGLONG CycleTime;
	/*0020*/ ULONGLONG ContextSwitches;
	/*0028*/ LONGLONG ReadOperationCount;
	/*0030*/ LONGLONG WriteOperationCount;
	/*0038*/ LONGLONG OtherOperationCount;
	/*0040*/ LONGLONG ReadTransferCount;
	/*0048*/ LONGLONG WriteTransferCount;
	/*0050*/ LONGLONG OtherTransferCount;
	/*0058*/
};

struct _ERESOURCE {
	/*0000*/ _LIST_ENTRY SystemResourcesList;
	/*0010*/ _OWNER_ENTRY * OwnerTable;
	/*0018*/ SHORT ActiveCount;
	/*001a*/ USHORT Flag;
	/*001a*/ UCHAR ReservedLowFlags;
	/*001b*/ UCHAR WaiterPriority;
	/*0020*/ void * SharedWaiters;
	/*0028*/ void * ExclusiveWaiters;
	/*0030*/ _OWNER_ENTRY OwnerEntry;
	/*0040*/ ULONG ActiveEntries;
	/*0044*/ ULONG ContentionCount;
	/*0048*/ ULONG NumberOfSharedWaiters;
	/*004c*/ ULONG NumberOfExclusiveWaiters;
	/*0050*/ void * Reserved2;
	/*0058*/ void * Address;
	/*0058*/ ULONGLONG CreatorBackTraceIndex;
	/*0060*/ ULONGLONG SpinLock;
	/*0068*/
};

struct _ESERVERSILO_GLOBALS {
	/*0000*/ _OBP_SILODRIVERSTATE ObSiloState;
	/*02e0*/ _SEP_SILOSTATE SeSiloState;
	/*0310*/ _SEP_RM_LSA_CONNECTION_STATE SeRmSiloState;
	/*0360*/ _ETW_SILODRIVERSTATE * EtwSiloState;
	/*0368*/ _EPROCESS * MiSessionLeaderProcess;
	/*0370*/ _EPROCESS * ExpDefaultErrorPortProcess;
	/*0378*/ void * ExpDefaultErrorPort;
	/*0380*/ ULONG HardErrorState;
	/*0388*/ _WNF_SILODRIVERSTATE WnfSiloState;
	/*03c0*/ _DBGK_SILOSTATE DbgkSiloState;
	/*03e0*/ _UNICODE_STRING PsProtectedCurrentDirectory;
	/*03f0*/ _UNICODE_STRING PsProtectedEnvironment;
	/*0400*/ void * ApiSetSection;
	/*0408*/ void * ApiSetSchema;
	/*0410*/ UCHAR OneCoreForwardersEnabled;
	/*0418*/ _UNICODE_STRING NtSystemRoot;
	/*0428*/ _UNICODE_STRING SiloRootDirectoryName;
	/*0438*/ _PSP_STORAGE * Storage;
	/*0440*/ _SERVERSILO_STATE State;
	/*0444*/ LONG ExitStatus;
	/*0448*/ _KEVENT * DeleteEvent;
	/*0450*/ _SILO_USER_SHARED_DATA * UserSharedData;
	/*0458*/ void * UserSharedSection;
	/*0460*/ _WORK_QUEUE_ITEM TerminateWorkItem;
	/*0480*/
};

struct _ETHREAD {
	/*0000*/ _KTHREAD Tcb;
	/*05f0*/ _LARGE_INTEGER CreateTime;
	/*05f8*/ _LARGE_INTEGER ExitTime;
	/*05f8*/ _LIST_ENTRY KeyedWaitChain;
	/*0608*/ _LIST_ENTRY PostBlockList;
	/*0608*/ void * ForwardLinkShadow;
	/*0610*/ void * StartAddress;
	/*0618*/ _TERMINATION_PORT * TerminationPort;
	/*0618*/ _ETHREAD * ReaperLink;
	/*0618*/ void * KeyedWaitValue;
	/*0620*/ ULONGLONG ActiveTimerListLock;
	/*0628*/ _LIST_ENTRY ActiveTimerListHead;
	/*0638*/ _CLIENT_ID Cid;
	/*0648*/ _KSEMAPHORE KeyedWaitSemaphore;
	/*0648*/ _KSEMAPHORE AlpcWaitSemaphore;
	/*0668*/ _PS_CLIENT_SECURITY_CONTEXT ClientSecurity;
	/*0670*/ _LIST_ENTRY IrpList;
	/*0680*/ ULONGLONG TopLevelIrp;
	/*0688*/ _DEVICE_OBJECT * DeviceToVerify;
	/*0690*/ void * Win32StartAddress;
	/*0698*/ void * ChargeOnlySession;
	/*06a0*/ void * LegacyPowerObject;
	/*06a8*/ _LIST_ENTRY ThreadListEntry;
	/*06b8*/ _EX_RUNDOWN_REF RundownProtect;
	/*06c0*/ _EX_PUSH_LOCK ThreadLock;
	/*06c8*/ ULONG ReadClusterSize;
	/*06cc*/ LONG volatile MmLockOrdering;
	/*06d0*/ ULONG CrossThreadFlags;
	/*06d0*/ ULONG Terminated : 01; // 0x00000001;
	/*06d0*/ ULONG ThreadInserted : 01; // 0x00000002;
	/*06d0*/ ULONG HideFromDebugger : 01; // 0x00000004;
	/*06d0*/ ULONG ActiveImpersonationInfo : 01; // 0x00000008;
	/*06d0*/ ULONG HardErrorsAreDisabled : 01; // 0x00000010;
	/*06d0*/ ULONG BreakOnTermination : 01; // 0x00000020;
	/*06d0*/ ULONG SkipCreationMsg : 01; // 0x00000040;
	/*06d0*/ ULONG SkipTerminationMsg : 01; // 0x00000080;
	/*06d0*/ ULONG CopyTokenOnOpen : 01; // 0x00000100;
	/*06d0*/ ULONG ThreadIoPriority : 03; // 0x00000e00;
	/*06d0*/ ULONG ThreadPagePriority : 03; // 0x00007000;
	/*06d0*/ ULONG RundownFail : 01; // 0x00008000;
	/*06d0*/ ULONG UmsForceQueueTermination : 01; // 0x00010000;
	/*06d0*/ ULONG IndirectCpuSets : 01; // 0x00020000;
	/*06d0*/ ULONG DisableDynamicCodeOptOut : 01; // 0x00040000;
	/*06d0*/ ULONG ExplicitCaseSensitivity : 01; // 0x00080000;
	/*06d0*/ ULONG PicoNotifyExit : 01; // 0x00100000;
	/*06d0*/ ULONG DbgWerUserReportActive : 01; // 0x00200000;
	/*06d0*/ ULONG ForcedSelfTrimActive : 01; // 0x00400000;
	/*06d0*/ ULONG ReservedCrossThreadFlags : 09; // 0xff800000;
	/*06d4*/ ULONG SameThreadPassiveFlags;
	/*06d4*/ ULONG ActiveExWorker : 01; // 0x00000001;
	/*06d4*/ ULONG MemoryMaker : 01; // 0x00000002;
	/*06d4*/ ULONG StoreLockThread : 02; // 0x0000000c;
	/*06d4*/ ULONG ClonedThread : 01; // 0x00000010;
	/*06d4*/ ULONG KeyedEventInUse : 01; // 0x00000020;
	/*06d4*/ ULONG SelfTerminate : 01; // 0x00000040;
	/*06d4*/ ULONG RespectIoPriority : 01; // 0x00000080;
	/*06d4*/ ULONG ActivePageLists : 01; // 0x00000100;
	/*06d4*/ ULONG SecureContext : 01; // 0x00000200;
	/*06d4*/ ULONG ZeroPageThread : 01; // 0x00000400;
	/*06d4*/ ULONG ReservedSameThreadPassiveFlags : 21; // 0xfffff800;
	/*06d8*/ ULONG SameThreadApcFlags;
	/*06d8*/ UCHAR OwnsProcessAddressSpaceExclusive : 01; // 0x01;
	/*06d8*/ UCHAR OwnsProcessAddressSpaceShared : 01; // 0x02;
	/*06d8*/ UCHAR HardFaultBehavior : 01; // 0x04;
	/*06d8*/ UCHAR volatile StartAddressInvalid : 01; // 0x08;
	/*06d8*/ UCHAR EtwCalloutActive : 01; // 0x10;
	/*06d8*/ UCHAR SuppressSymbolLoad : 01; // 0x20;
	/*06d8*/ UCHAR Prefetching : 01; // 0x40;
	/*06d8*/ UCHAR OwnsVadExclusive : 01; // 0x80;
	/*06d9*/ UCHAR SystemPagePriorityActive : 01; // 0x01;
	/*06d9*/ UCHAR SystemPagePriority : 03; // 0x0e;
	/*06d9*/ UCHAR AllowWritesToExecutableMemory : 01; // 0x10;
	/*06dc*/ UCHAR CacheManagerActive;
	/*06dd*/ UCHAR DisablePageFaultClustering;
	/*06de*/ UCHAR ActiveFaultCount;
	/*06df*/ UCHAR LockOrderState;
	/*06e0*/ ULONGLONG AlpcMessageId;
	/*06e8*/ void * AlpcMessage;
	/*06e8*/ ULONG AlpcReceiveAttributeSet;
	/*06f0*/ _LIST_ENTRY AlpcWaitListEntry;
	/*0700*/ LONG ExitStatus;
	/*0704*/ ULONG CacheManagerCount;
	/*0708*/ ULONG IoBoostCount;
	/*070c*/ ULONG IoQoSBoostCount;
	/*0710*/ ULONG IoQoSThrottleCount;
	/*0718*/ _LIST_ENTRY BoostList;
	/*0728*/ _LIST_ENTRY DeboostList;
	/*0738*/ ULONGLONG BoostListLock;
	/*0740*/ ULONGLONG IrpListLock;
	/*0748*/ void * ReservedForSynchTracking;
	/*0750*/ _SINGLE_LIST_ENTRY CmCallbackListHead;
	/*0758*/ _GUID const * ActivityId;
	/*0760*/ _SINGLE_LIST_ENTRY SeLearningModeListHead;
	/*0768*/ void * VerifierContext;
	/*0770*/ ULONG KernelStackReference;
	/*0778*/ void * AdjustedClientToken;
	/*0780*/ void * WorkOnBehalfThread;
	/*0788*/ _PS_PROPERTY_SET PropertySet;
	/*07a0*/ void * PicoContext;
	/*07a8*/ ULONGLONG UserFsBase;
	/*07b0*/ ULONGLONG UserGsBase;
	/*07b8*/ _THREAD_ENERGY_VALUES * EnergyValues;
	/*07c0*/ void * CmDbgInfo;
	/*07c8*/ ULONGLONG SelectedCpuSets;
	/*07c8*/ ULONGLONG * SelectedCpuSetsIndirect;
	/*07d0*/ _EJOB * Silo;
	/*07d8*/ _UNICODE_STRING * ThreadName;
	/*07e0*/ _CONTEXT * SetContextState;
	/*07e8*/ ULONG LastExpectedRunTime;
	/*07f0*/ _LIST_ENTRY OwnerEntryListHead;
	/*0800*/ ULONGLONG DisownedOwnerEntryListLock;
	/*0808*/ _LIST_ENTRY DisownedOwnerEntryListHead;
	/*0818*/
};

struct _ETIMER {
	/*0000*/ _KTIMER KeTimer;
	/*0040*/ ULONGLONG Lock;
	/*0048*/ _KAPC TimerApc;
	/*00a0*/ _KDPC TimerDpc;
	/*00e0*/ _LIST_ENTRY ActiveTimerListEntry;
	/*00f0*/ ULONG Period;
	/*00f4*/ CHAR TimerFlags;
	/*00f4*/ UCHAR ApcAssociated : 01; // 0x01;
	/*00f4*/ UCHAR FlushDpcs : 01; // 0x02;
	/*00f4*/ UCHAR Paused : 01; // 0x04;
	/*00f4*/ UCHAR Spare1 : 05; // 0xf8;
	/*00f5*/ UCHAR DueTimeType;
	/*00f6*/ USHORT Spare2;
	/*00f8*/ _DIAGNOSTIC_CONTEXT * volatile WakeReason;
	/*0100*/ _LIST_ENTRY WakeTimerListEntry;
	/*0110*/ void * VirtualizedTimerCookie;
	/*0118*/ _LIST_ENTRY VirtualizedTimerLinks;
	/*0128*/ ULONGLONG DueTime;
	/*0130*/ ULONG CoalescingWindow;
	/*0138*/
};

struct _ETWP_NOTIFICATION_HEADER {
	/*0000*/ _ETW_NOTIFICATION_TYPE NotificationType;
	/*0004*/ ULONG NotificationSize;
	/*0008*/ LONG RefCount;
	/*000c*/ UCHAR ReplyRequested;
	/*0010*/ ULONG ReplyIndex;
	/*0010*/ ULONG Timeout;
	/*0014*/ ULONG ReplyCount;
	/*0014*/ ULONG NotifyeeCount;
	/*0018*/ ULONGLONG ReplyHandle;
	/*0018*/ void * ReplyObject;
	/*0018*/ ULONG RegIndex;
	/*0020*/ ULONG TargetPID;
	/*0024*/ ULONG SourcePID;
	/*0028*/ _GUID DestinationGuid;
	/*0038*/ _GUID SourceGuid;
	/*0048*/
};

struct _ETW_APC_ENTRY {
	/*0000*/ _SLIST_ENTRY SListEntry;
	/*0000*/ _KAPC Apc;
	/*0060*/
};

struct _ETW_BUFFER_CONTEXT {
	/*0000*/ UCHAR ProcessorNumber;
	/*0001*/ UCHAR Alignment;
	/*0000*/ USHORT ProcessorIndex;
	/*0002*/ USHORT LoggerId;
	/*0004*/
};

struct _ETW_BUFFER_QUEUE {
	/*0000*/ _SINGLE_LIST_ENTRY * QueueTail;
	/*0008*/ _SINGLE_LIST_ENTRY QueueEntry;
	/*0010*/
};

enum _ETW_BUFFER_STATE {
	EtwBufferStateFree = 0x0,
	EtwBufferStateGeneralLogging = 0x1,
	EtwBufferStateCSwitch = 0x2,
	EtwBufferStateFlush = 0x3,
	EtwBufferStatePendingCompression = 0x4,
	EtwBufferStateCompressed = 0x5,
	EtwBufferStatePlaceholder = 0x6,
	EtwBufferStateMaximum = 0x7
};

struct _ETW_COUNTERS {
	/*0000*/ LONG GuidCount;
	/*0004*/ LONG PoolUsage[0x2];
	/*000c*/ LONG SessionCount;
	/*0010*/
};

struct _ETW_DEBUGID_TRACKING_ENTRY {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ UCHAR ConsumersNotified;
	/*0011*/ UCHAR Spare[0x3];
	/*0014*/ ULONG DebugIdSize;
	/*0018*/ _CVDD DebugId;
	/*0038*/
};

struct _ETW_DECODE_CONTROL_ENTRY {
	/*0000*/ _ETW_DECODE_CONTROL_ENTRY * Next;
	/*0008*/ _GUID Decode;
	/*0018*/ _GUID Control;
	/*0028*/ UCHAR ConsumersNotified;
	/*0030*/
};

struct _ETW_FILTER_EVENT_NAME_DATA {
	/*0000*/ UCHAR FilterIn;
	/*0001*/ UCHAR Level;
	/*0008*/ ULONGLONG MatchAnyKeyword;
	/*0010*/ ULONGLONG MatchAllKeyword;
	/*0018*/ _RTL_HASH_TABLE NameTable;
	/*0028*/
};

struct _ETW_FILTER_HEADER {
	/*0000*/ LONG FilterFlags;
	/*0008*/ _ETW_FILTER_PID * PidFilter;
	/*0010*/ _ETW_FILTER_STRING_TOKEN * ExeFilter;
	/*0018*/ _ETW_FILTER_STRING_TOKEN * PkgIdFilter;
	/*0020*/ _ETW_FILTER_STRING_TOKEN * PkgAppIdFilter;
	/*0028*/ _ETW_PERFECT_HASH_FUNCTION * StackWalkIdFilter;
	/*0030*/ _ETW_FILTER_EVENT_NAME_DATA * StackWalkNameFilter;
	/*0038*/ _EVENT_FILTER_LEVEL_KW * StackWalkLevelKwFilter;
	/*0040*/ _ETW_PERFECT_HASH_FUNCTION * EventIdFilter;
	/*0048*/ _ETW_PAYLOAD_FILTER * PayloadFilter;
	/*0050*/ _EVENT_FILTER_HEADER * ProviderSideFilter;
	/*0058*/ _ETW_FILTER_EVENT_NAME_DATA * EventNameFilter;
	/*0060*/
};

struct _ETW_FILTER_PID {
	/*0000*/ ULONG Count;
	/*0004*/ ULONG Pids[0x8];
	/*0024*/
};

struct _ETW_FILTER_STRING_TOKEN {
	/*0000*/ USHORT Count;
	/*0008*/ _ETW_FILTER_STRING_TOKEN_ELEMENT Tokens[0x1];
	/*0018*/
};

struct _ETW_FILTER_STRING_TOKEN_ELEMENT {
	/*0000*/ USHORT Length;
	/*0008*/ WCHAR * String;
	/*0010*/
};

struct _ETW_GUID_ENTRY {
	/*0000*/ _LIST_ENTRY GuidList;
	/*0010*/ LONGLONG volatile RefCount;
	/*0018*/ _GUID Guid;
	/*0028*/ _LIST_ENTRY RegListHead;
	/*0038*/ void * SecurityDescriptor;
	/*0040*/ _ETW_LAST_ENABLE_INFO LastEnable;
	/*0040*/ ULONGLONG MatchId;
	/*0050*/ _TRACE_ENABLE_INFO ProviderEnableInfo;
	/*0070*/ _TRACE_ENABLE_INFO EnableInfo[0x8];
	/*0170*/ _ETW_FILTER_HEADER * FilterData;
	/*0178*/ _ETW_SILODRIVERSTATE * SiloState;
	/*0180*/ _EX_PUSH_LOCK Lock;
	/*0188*/ _ETHREAD * LockOwner;
	/*0190*/
};

enum _ETW_GUID_TYPE {
	EtwTraceGuidType = 0x0,
	EtwNotificationGuidType = 0x1,
	EtwGroupGuidType = 0x2,
	EtwGuidTypeMax = 0x3
};

struct _ETW_HASH_BUCKET {
	/*0000*/ _LIST_ENTRY ListHead[0x3];
	/*0030*/ _EX_PUSH_LOCK BucketLock;
	/*0038*/
};

enum _ETW_HEADER_TYPE {
	EtwHeaderTypeNative = 0x0,
	EtwHeaderTypeWow = 0x1,
	EtwHeaderTypeMax = 0x2
};

struct _ETW_LAST_ENABLE_INFO {
	/*0000*/ _LARGE_INTEGER EnableFlags;
	/*0008*/ USHORT LoggerId;
	/*000a*/ UCHAR Level;
	/*000b*/ UCHAR Enabled : 01; // 0x01;
	/*000b*/ UCHAR InternalFlag : 07; // 0xfe;
	/*0010*/
};

struct _ETW_LBR_SUPPORT {
	/*0000*/ ULONG LbrHandle;
	/*0004*/ ULONG LbrOptions;
	/*0008*/ ULONG volatile HookIdCount;
	/*000c*/ USHORT HookId[0x4];
	/*0014*/
};

struct _ETW_LOGGER_HANDLE {
	/*0000*/ UCHAR DereferenceAndLeave;
	/*0001*/
};

enum _ETW_NOTIFICATION_TYPE {
	EtwNotificationTypeNoReply = 0x1,
	EtwNotificationTypeLegacyEnable = 0x2,
	EtwNotificationTypeEnable = 0x3,
	EtwNotificationTypePrivateLogger = 0x4,
	EtwNotificationTypePerflib = 0x5,
	EtwNotificationTypeAudio = 0x6,
	EtwNotificationTypeSession = 0x7,
	EtwNotificationTypeReserved = 0x8,
	EtwNotificationTypeCredentialUI = 0x9,
	EtwNotificationTypeInProcSession = 0xa,
	EtwNotificationTypeFilteredPrivateLogger = 0xb,
	EtwNotificationTypeMax = 0xc
};

struct _ETW_PAYLOAD_FILTER {
	/*0000*/ LONG RefCount;
	/*0008*/ _AGGREGATED_PAYLOAD_FILTER PayloadFilter;
	/*0058*/
};

struct _ETW_PERFECT_HASH_FUNCTION;

enum _ETW_PERFECT_HASH_FUNCTION_TYPE {
	ETW_PHF_EVENT_ID = 0x0,
	ETW_PHF_STACK_WALK = 0x1,
	ETW_PHF_MAX_COUNT = 0x2
};

struct _ETW_PERF_COUNTERS {
	/*0000*/ LONG TotalActiveSessions;
	/*0004*/ LONG TotalBufferMemoryNonPagedPool;
	/*0008*/ LONG TotalBufferMemoryPagedPool;
	/*000c*/ LONG TotalGuidsEnabled;
	/*0010*/ LONG TotalGuidsNotEnabled;
	/*0014*/ LONG TotalGuidsPreEnabled;
	/*0018*/
};

enum _ETW_PERIODIC_TIMER_STATE {
	EtwpPeriodicTimerUnset = 0x0,
	EtwpPeriodicTimerSet = 0x1
};

struct _ETW_PMC_SUPPORT {
	/*0000*/ _KPROFILE_SOURCE Source[0x8];
	/*0020*/ ULONG volatile HookIdCount;
	/*0024*/ USHORT HookId[0x4];
	/*002c*/ ULONG volatile CountersCount;
	/*0030*/ _HAL_PMC_COUNTERS * ProcessorCtrs[0x1];
	/*0038*/
};

struct _ETW_PRIV_HANDLE_DEMUX_TABLE {
	/*0000*/ _RTL_RB_TREE Tree;
	/*0010*/ _EX_PUSH_LOCK Lock;
	/*0018*/ USHORT SequenceNumber;
	/*0020*/
};

struct _ETW_PROVIDER_TRAITS {
	/*0000*/ _RTL_BALANCED_NODE Node;
	/*0018*/ ULONG ReferenceCount;
	/*001c*/ UCHAR Traits[0x1];
	/*0020*/
};

struct _ETW_QUEUE_ENTRY {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _ETWP_NOTIFICATION_HEADER * DataBlock;
	/*0018*/ _ETW_REG_ENTRY * RegEntry;
	/*0020*/ _ETW_REG_ENTRY * ReplyObject;
	/*0028*/ void * WakeReference;
	/*0030*/ USHORT RegIndex;
	/*0032*/ USHORT ReplyIndex;
	/*0034*/ ULONG Flags;
	/*0038*/
};

struct _ETW_REALTIME_CONSUMER {
	/*0000*/ _LIST_ENTRY Links;
	/*0010*/ void * ProcessHandle;
	/*0018*/ _EPROCESS * ProcessObject;
	/*0020*/ void * NextNotDelivered;
	/*0028*/ void * RealtimeConnectContext;
	/*0030*/ _KEVENT * DisconnectEvent;
	/*0038*/ _KEVENT * DataAvailableEvent;
	/*0040*/ ULONG * UserBufferCount;
	/*0048*/ _SINGLE_LIST_ENTRY * UserBufferListHead;
	/*0050*/ ULONG BuffersLost;
	/*0054*/ ULONG EmptyBuffersCount;
	/*0058*/ USHORT LoggerId;
	/*005a*/ UCHAR Flags;
	/*005a*/ UCHAR ShutDownRequested : 01; // 0x01;
	/*005a*/ UCHAR NewBuffersLost : 01; // 0x02;
	/*005a*/ UCHAR Disconnected : 01; // 0x04;
	/*005a*/ UCHAR Notified : 01; // 0x08;
	/*005a*/ UCHAR Wow : 01; // 0x10;
	/*0060*/ _RTL_BITMAP ReservedBufferSpaceBitMap;
	/*0070*/ UCHAR * ReservedBufferSpace;
	/*0078*/ ULONG ReservedBufferSpaceSize;
	/*007c*/ ULONG UserPagesAllocated;
	/*0080*/ ULONG UserPagesReused;
	/*0088*/ ULONG * EventsLostCount;
	/*0090*/ ULONG * BuffersLostCount;
	/*0098*/ _ETW_SILODRIVERSTATE * SiloState;
	/*00a0*/
};

struct _ETW_REF_CLOCK {
	/*0000*/ _LARGE_INTEGER StartTime;
	/*0008*/ _LARGE_INTEGER StartPerfClock;
	/*0010*/
};

struct _ETW_REG_ENTRY {
	/*0000*/ _LIST_ENTRY RegList;
	/*0010*/ _LIST_ENTRY GroupRegList;
	/*0020*/ _ETW_GUID_ENTRY * GuidEntry;
	/*0028*/ _ETW_GUID_ENTRY * GroupEntry;
	/*0030*/ _ETW_REPLY_QUEUE * ReplyQueue;
	/*0030*/ _ETW_QUEUE_ENTRY * ReplySlot[0x4];
	/*0030*/ void * Caller;
	/*0038*/ ULONG SessionId;
	/*0050*/ _EPROCESS * Process;
	/*0050*/ void * CallbackContext;
	/*0058*/ void * Callback;
	/*0060*/ USHORT Index;
	/*0062*/ USHORT Flags;
	/*0062*/ USHORT DbgKernelRegistration : 01; // 0x0001;
	/*0062*/ USHORT DbgUserRegistration : 01; // 0x0002;
	/*0062*/ USHORT DbgReplyRegistration : 01; // 0x0004;
	/*0062*/ USHORT DbgClassicRegistration : 01; // 0x0008;
	/*0062*/ USHORT DbgSessionSpaceRegistration : 01; // 0x0010;
	/*0062*/ USHORT DbgModernRegistration : 01; // 0x0020;
	/*0062*/ USHORT DbgClosed : 01; // 0x0040;
	/*0062*/ USHORT DbgInserted : 01; // 0x0080;
	/*0062*/ USHORT DbgWow64 : 01; // 0x0100;
	/*0062*/ USHORT DbgUseDescriptorType : 01; // 0x0200;
	/*0062*/ USHORT DbgDropProviderTraits : 01; // 0x0400;
	/*0064*/ UCHAR EnableMask;
	/*0065*/ UCHAR GroupEnableMask;
	/*0068*/ _ETW_PROVIDER_TRAITS * Traits;
	/*0070*/
};

struct _ETW_REPLY_QUEUE {
	/*0000*/ _KQUEUE Queue;
	/*0040*/ LONG EventsLost;
	/*0048*/
};

enum _ETW_RT_EVENT_LOSS {
	EtwRtEventNoLoss = 0x0,
	EtwRtEventLost = 0x1,
	EtwRtBufferLost = 0x2,
	EtwRtBackupLost = 0x3,
	EtwRtEventLossMax = 0x4
};

struct _ETW_SESSION_PERF_COUNTERS {
	/*0000*/ LONG BufferMemoryPagedPool;
	/*0004*/ LONG BufferMemoryNonPagedPool;
	/*0008*/ ULONGLONG EventsLoggedCount;
	/*0010*/ LONG EventsLost;
	/*0014*/ LONG NumConsumers;
	/*0018*/
};

struct _ETW_SILODRIVERSTATE {
	/*0000*/ _ESERVERSILO_GLOBALS * SiloGlobals;
	/*0008*/ ULONG MaxLoggers;
	/*0010*/ _ETW_GUID_ENTRY EtwpSecurityProviderGuidEntry;
	/*01a0*/ _EX_RUNDOWN_REF_CACHE_AWARE * * EtwpLoggerRundown;
	/*01a8*/ _WMI_LOGGER_CONTEXT * * EtwpLoggerContext;
	/*01b0*/ _ETW_HASH_BUCKET EtwpGuidHashTable[0x40];
	/*0fb0*/ USHORT EtwpSecurityLoggers[0x8];
	/*0fc0*/ UCHAR EtwpSecurityProviderEnableMask;
	/*0fc4*/ LONG EtwpShutdownInProgress;
	/*0fc8*/ ULONG EtwpSecurityProviderPID;
	/*0fd0*/ _ETW_PRIV_HANDLE_DEMUX_TABLE PrivHandleDemuxTable;
	/*0ff0*/ _ETW_COUNTERS EtwpCounters;
	/*1000*/ _LARGE_INTEGER LogfileBytesWritten;
	/*1008*/ _ETW_SILO_TRACING_BLOCK * ProcessorBlocks;
	/*1010*/ _GUID PartitionId;
	/*1020*/ _GUID ParentId;
	/*1030*/ _LARGE_INTEGER QpcOffsetFromRoot;
	/*1038*/ ULONG PartitionType;
	/*103c*/ _ETW_SYSTEM_LOGGER_SETTINGS SystemLoggerSettings;
	/*1190*/
};

struct _ETW_SILO_TRACING_BLOCK {
	/*0000*/ _EX_FAST_REF * ProcessorBuffers;
	/*0008*/ ULONGLONG * EventsLoggedCount;
	/*0040*/
};

struct _ETW_SOFT_RESTART_CONTEXT;

struct _ETW_STACK_CACHE;

struct _ETW_STACK_TRACE_BLOCK {
	/*0000*/ LONG Flags;
	/*0008*/ _LARGE_INTEGER RelatedTimestamp;
	/*0010*/ _ETHREAD * Thread;
	/*0018*/ _KDPC StackWalkDpc;
	/*0060*/ _SLIST_HEADER ApcListHead;
	/*0070*/ _ETW_APC_ENTRY ApcEntry[0xc];
	/*04f0*/ LONG ApcCount;
	/*04f4*/ LONG MaxApcCount;
	/*0500*/
};

enum _ETW_STRING_TOKEN_TYPE {
	ETW_STRING_TOKEN_EXE = 0x0,
	ETW_STRING_TOKEN_PACKAGE_ID = 0x1,
	ETW_STRING_TOKEN_PKG_APP_ID = 0x2,
	ETW_STRING_TOKEN_MAX_COUNT = 0x3
};

struct _ETW_SYSTEMTIME {
	/*0000*/ USHORT Year;
	/*0002*/ USHORT Month;
	/*0004*/ USHORT DayOfWeek;
	/*0006*/ USHORT Day;
	/*0008*/ USHORT Hour;
	/*000a*/ USHORT Minute;
	/*000c*/ USHORT Second;
	/*000e*/ USHORT Milliseconds;
	/*0010*/
};

struct _ETW_SYSTEM_LOGGER {
	/*0000*/ UCHAR LoggerId;
	/*0001*/ UCHAR ClockType;
	/*0002*/
};

struct _ETW_SYSTEM_LOGGER_SETTINGS {
	/*0000*/ _ETW_SYSTEM_LOGGER EtwpSystemLogger[0x8];
	/*0010*/ ULONG volatile EtwpActiveSystemLoggers;
	/*0014*/ _PERFINFO_GROUPMASK SiloGlobalGroupMask;
	/*0034*/ _PERFINFO_GROUPMASK EtwpGroupMasks[0x9];
	/*0154*/
};

struct _ETW_WMITRACE_WORK {
	/*0000*/ ULONG LoggerId;
	/*0004*/ ULONG SiloSessionId;
	/*0008*/ CHAR LoggerName[0x41];
	/*0049*/ CHAR FileName[0x81];
	/*00cc*/ ULONG MaximumFileSize;
	/*00d0*/ ULONG MinBuffers;
	/*00d4*/ ULONG MaxBuffers;
	/*00d8*/ ULONG BufferSize;
	/*00dc*/ ULONG Mode;
	/*00e0*/ ULONG FlushTimer;
	/*0008*/ ULONGLONG MatchAny;
	/*0010*/ ULONGLONG MatchAll;
	/*0018*/ ULONG EnableProperty;
	/*001c*/ _GUID Guid;
	/*002c*/ UCHAR Level;
	/*00e8*/ LONG Status;
	/*00f0*/
};

struct _EVENT_DATA_DESCRIPTOR {
	/*0000*/ ULONGLONG Ptr;
	/*0008*/ ULONG Size;
	/*000c*/ ULONG Reserved;
	/*000c*/ UCHAR Type;
	/*000d*/ UCHAR Reserved1;
	/*000e*/ USHORT Reserved2;
	/*0010*/
};

struct _EVENT_DESCRIPTOR {
	/*0000*/ USHORT Id;
	/*0002*/ UCHAR Version;
	/*0003*/ UCHAR Channel;
	/*0004*/ UCHAR Level;
	/*0005*/ UCHAR Opcode;
	/*0006*/ USHORT Task;
	/*0008*/ ULONGLONG Keyword;
	/*0010*/
};

struct _EVENT_FILTER_DESCRIPTOR {
	/*0000*/ ULONGLONG Ptr;
	/*0008*/ ULONG Size;
	/*000c*/ ULONG Type;
	/*0010*/
};

struct _EVENT_FILTER_HEADER {
	/*0000*/ USHORT Id;
	/*0002*/ UCHAR Version;
	/*0003*/ UCHAR Reserved[0x5];
	/*0008*/ ULONGLONG InstanceId;
	/*0010*/ ULONG Size;
	/*0014*/ ULONG NextOffset;
	/*0018*/
};

struct _EVENT_FILTER_LEVEL_KW {
	/*0000*/ ULONGLONG MatchAnyKeyword;
	/*0008*/ ULONGLONG MatchAllKeyword;
	/*0010*/ UCHAR Level;
	/*0011*/ UCHAR FilterIn;
	/*0018*/
};

struct _EVENT_HEADER {
	/*0000*/ USHORT Size;
	/*0002*/ USHORT HeaderType;
	/*0004*/ USHORT Flags;
	/*0006*/ USHORT EventProperty;
	/*0008*/ ULONG ThreadId;
	/*000c*/ ULONG ProcessId;
	/*0010*/ _LARGE_INTEGER TimeStamp;
	/*0018*/ _GUID ProviderId;
	/*0028*/ _EVENT_DESCRIPTOR EventDescriptor;
	/*0038*/ ULONG KernelTime;
	/*003c*/ ULONG UserTime;
	/*0038*/ ULONGLONG ProcessorTime;
	/*0040*/ _GUID ActivityId;
	/*0050*/
};

struct _EVENT_HEADER_EXTENDED_DATA_ITEM {
	/*0000*/ USHORT Reserved1;
	/*0002*/ USHORT ExtType;
	/*0004*/ USHORT Linkage : 01; // 0x0001;
	/*0004*/ USHORT Reserved2 : 15; // 0xfffe;
	/*0006*/ USHORT DataSize;
	/*0008*/ ULONGLONG DataPtr;
	/*0010*/
};

enum _EVENT_INFO_CLASS {
	EventProviderBinaryTrackInfo = 0x0,
	EventProviderSetReserved1 = 0x1,
	EventProviderSetTraits = 0x2,
	EventProviderUseDescriptorType = 0x3,
	MaxEventInfo = 0x4
};

struct _EVENT_PAYLOAD_PREDICATE {
	/*0000*/ USHORT FieldIndex;
	/*0002*/ USHORT CompareOp;
	/*0008*/ ULONGLONG Value[0x2];
	/*0018*/
};

struct _EVENT_RECORD {
	/*0000*/ _EVENT_HEADER EventHeader;
	/*0050*/ _ETW_BUFFER_CONTEXT BufferContext;
	/*0054*/ USHORT ExtendedDataCount;
	/*0056*/ USHORT UserDataLength;
	/*0058*/ _EVENT_HEADER_EXTENDED_DATA_ITEM * ExtendedData;
	/*0060*/ void * UserData;
	/*0068*/ void * UserContext;
	/*0070*/
};

enum _EVENT_TYPE {
	NotificationEvent = 0x0,
	SynchronizationEvent = 0x1
};

struct _EWOW64PROCESS {
	/*0000*/ void * Peb;
	/*0008*/ USHORT Machine;
	/*000c*/ _SYSTEM_DLL_TYPE NtdllType;
	/*0010*/
};

enum _EXCEPTION_DISPOSITION {
	ExceptionContinueExecution = 0x0,
	ExceptionContinueSearch = 0x1,
	ExceptionNestedException = 0x2,
	ExceptionCollidedUnwind = 0x3
};

struct _EXCEPTION_POINTERS {
	/*0000*/ _EXCEPTION_RECORD * ExceptionRecord;
	/*0008*/ _CONTEXT * ContextRecord;
	/*0010*/
};

struct _EXCEPTION_RECORD {
	/*0000*/ LONG ExceptionCode;
	/*0004*/ ULONG ExceptionFlags;
	/*0008*/ _EXCEPTION_RECORD * ExceptionRecord;
	/*0010*/ void * ExceptionAddress;
	/*0018*/ ULONG NumberParameters;
	/*0020*/ ULONGLONG ExceptionInformation[0xf];
	/*0098*/
};

struct _EXCEPTION_RECORD32 {
	/*0000*/ LONG ExceptionCode;
	/*0004*/ ULONG ExceptionFlags;
	/*0008*/ ULONG ExceptionRecord;
	/*000c*/ ULONG ExceptionAddress;
	/*0010*/ ULONG NumberParameters;
	/*0014*/ ULONG ExceptionInformation[0xf];
	/*0050*/
};

struct _EXCEPTION_RECORD64 {
	/*0000*/ LONG ExceptionCode;
	/*0004*/ ULONG ExceptionFlags;
	/*0008*/ ULONGLONG ExceptionRecord;
	/*0010*/ ULONGLONG ExceptionAddress;
	/*0018*/ ULONG NumberParameters;
	/*001c*/ ULONG __unusedAlignment;
	/*0020*/ ULONGLONG ExceptionInformation[0xf];
	/*0098*/
};

struct _EXCEPTION_REGISTRATION_RECORD {
	/*0000*/ _EXCEPTION_REGISTRATION_RECORD * Next;
	/*0008*/ _EXCEPTION_DISPOSITION (* Handler)( _EXCEPTION_RECORD * , void * , _CONTEXT * , void * );
	/*0010*/
};

struct _EXHANDLE {
	/*0000*/ ULONG TagBits : 02; // 0x00000003;
	/*0000*/ ULONG Index : 30; // 0xfffffffc;
	/*0000*/ void * GenericHandleOverlay;
	/*0000*/ ULONGLONG Value;
	/*0008*/
};

enum _EXQUEUEINDEX {
	ExPoolUntrusted = 0x0,
	IoPoolUntrusted = 0x1,
	ExPoolMax = 0x8
};

struct _EXT_DELETE_PARAMETERS {
	/*0000*/ ULONG Version;
	/*0004*/ ULONG Reserved;
	/*0008*/ void (* DeleteCallback)( void * );
	/*0010*/ void * DeleteContext;
	/*0018*/
};

struct _EXT_SET_PARAMETERS_V0 {
	/*0000*/ ULONG Version;
	/*0004*/ ULONG Reserved;
	/*0008*/ LONGLONG NoWakeTolerance;
	/*0010*/
};

struct _EX_FAST_REF {
	/*0000*/ void * Object;
	/*0000*/ ULONGLONG RefCnt : 04; // 0x000000000000000f;
	/*0000*/ ULONGLONG Value;
	/*0008*/
};

enum _EX_GEN_RANDOM_DOMAIN {
	ExGenRandomDomainKernel = 0x0,
	ExGenRandomDomainFirst = 0x0,
	ExGenRandomDomainUserVisible = 0x1,
	ExGenRandomDomainMax = 0x2
};

struct _EX_PARTITION {
	/*0000*/ _EPARTITION * PartitionObject;
	/*0008*/ _EX_WORK_QUEUE * * volatile * WorkQueues;
	/*0010*/ _EX_WORK_QUEUE_MANAGER * * WorkQueueManagers;
	/*0018*/ LONG volatile QueueAllocationMask;
	/*0020*/
};

enum _EX_POOL_PRIORITY {
	LowPoolPriority = 0x0,
	LowPoolPrioritySpecialPoolOverrun = 0x8,
	LowPoolPrioritySpecialPoolUnderrun = 0x9,
	NormalPoolPriority = 0x10,
	NormalPoolPrioritySpecialPoolOverrun = 0x18,
	NormalPoolPrioritySpecialPoolUnderrun = 0x19,
	HighPoolPriority = 0x20,
	HighPoolPrioritySpecialPoolOverrun = 0x28,
	HighPoolPrioritySpecialPoolUnderrun = 0x29
};

struct _EX_PUSH_LOCK {
	/*0000*/ ULONGLONG Locked : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG Waiting : 01; // 0x0000000000000002;
	/*0000*/ ULONGLONG Waking : 01; // 0x0000000000000004;
	/*0000*/ ULONGLONG MultipleShared : 01; // 0x0000000000000008;
	/*0000*/ ULONGLONG Shared : 60; // 0xfffffffffffffff0;
	/*0000*/ ULONGLONG Value;
	/*0000*/ void * Ptr;
	/*0008*/
};

struct _EX_PUSH_LOCK_AUTO_EXPAND {
	/*0000*/ _EX_PUSH_LOCK LocalLock;
	/*0008*/ _EX_PUSH_LOCK_AUTO_EXPAND_STATE State;
	/*000c*/ ULONG Stats;
	/*0010*/
};

struct _EX_PUSH_LOCK_AUTO_EXPAND_STATE {
	/*0000*/ ULONG Expanded : 01; // 0x00000001;
	/*0000*/ ULONG Transitioning : 01; // 0x00000002;
	/*0000*/ ULONG Pageable : 01; // 0x00000004;
	/*0000*/ ULONG Value;
	/*0004*/
};

struct _EX_RUNDOWN_REF {
	/*0000*/ ULONGLONG Count;
	/*0000*/ void * Ptr;
	/*0008*/
};

struct _EX_RUNDOWN_REF_CACHE_AWARE {
	/*0000*/ _EX_RUNDOWN_REF * RunRefs;
	/*0008*/ void * PoolToFree;
	/*0010*/ ULONG RunRefSize;
	/*0014*/ ULONG Number;
	/*0018*/
};

struct _EX_TIMER;

struct _EX_WORK_QUEUE {
	/*0000*/ _KPRIQUEUE WorkPriQueue;
	/*02b0*/ _EX_PARTITION * Partition;
	/*02b8*/ _ENODE * Node;
	/*02c0*/ ULONG volatile WorkItemsProcessed;
	/*02c4*/ ULONG WorkItemsProcessedLastPass;
	/*02c8*/ LONG volatile ThreadCount;
	/*02cc*/ LONG MinThreads : 31; // 0x7fffffff;
	/*02cc*/ ULONG volatile TryFailed : 01; // 0x80000000;
	/*02d0*/ LONG MaxThreads;
	/*02d4*/ _EXQUEUEINDEX QueueIndex;
	/*02d8*/ _KEVENT * AllThreadsExitedEvent;
	/*02e0*/
};

struct _EX_WORK_QUEUE_MANAGER {
	/*0000*/ _EX_PARTITION * Partition;
	/*0008*/ _ENODE * Node;
	/*0010*/ _KEVENT Event;
	/*0028*/ _KTIMER DeadlockTimer;
	/*0068*/ _KEVENT ReaperEvent;
	/*0080*/ _KTIMER2 ReaperTimer;
	/*0108*/ void * ThreadHandle;
	/*0110*/ ULONG volatile ExitThread;
	/*0114*/ ULONG ThreadSeed;
	/*0118*/
};

struct _FAST_ERESOURCE {
	/*0000*/ void * Reserved1[0x3];
	/*0018*/ ULONG Reserved2;
	/*0020*/ void * Reserved3[0x4];
	/*0040*/ ULONG Reserved4[0x4];
	/*0050*/ void * Reserved5;
	/*0058*/ void * Reserved6[0x2];
	/*0068*/
};

struct _FAST_ERESOURCE_INTERNAL {
	/*0000*/ _LIST_ENTRY SystemResourcesList;
	/*0010*/ void * ReservedPointer;
	/*0018*/ SHORT ActiveCount;
	/*001a*/ USHORT Flag;
	/*0020*/ _KWAIT_CHAIN SharedWaiters;
	/*0028*/ _KWAIT_CHAIN ExclusiveWaiters;
	/*0030*/ _LIST_ENTRY OwnerEntryListHead;
	/*0040*/ ULONG ActiveEntries;
	/*0044*/ ULONG ContentionCount;
	/*0048*/ ULONG NumberOfSharedWaiters;
	/*004c*/ ULONG NumberOfExclusiveWaiters;
	/*0050*/ void * ReservedWin64OnlyPointer;
	/*0058*/ void * Address;
	/*0058*/ ULONGLONG CreatorBackTraceIndex;
	/*0060*/ ULONGLONG SpinLock;
	/*0068*/
};

struct _FAST_IO_DISPATCH {
	/*0000*/ ULONG SizeOfFastIoDispatch;
	/*0008*/ UCHAR (* FastIoCheckIfPossible)( _FILE_OBJECT * , _LARGE_INTEGER * , ULONG , UCHAR , ULONG , UCHAR , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0010*/ UCHAR (* FastIoRead)( _FILE_OBJECT * , _LARGE_INTEGER * , ULONG , UCHAR , ULONG , void * , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0018*/ UCHAR (* FastIoWrite)( _FILE_OBJECT * , _LARGE_INTEGER * , ULONG , UCHAR , ULONG , void * , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0020*/ UCHAR (* FastIoQueryBasicInfo)( _FILE_OBJECT * , UCHAR , _FILE_BASIC_INFORMATION * , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0028*/ UCHAR (* FastIoQueryStandardInfo)( _FILE_OBJECT * , UCHAR , _FILE_STANDARD_INFORMATION * , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0030*/ UCHAR (* FastIoLock)( _FILE_OBJECT * , _LARGE_INTEGER * , _LARGE_INTEGER * , _EPROCESS * , ULONG , UCHAR , UCHAR , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0038*/ UCHAR (* FastIoUnlockSingle)( _FILE_OBJECT * , _LARGE_INTEGER * , _LARGE_INTEGER * , _EPROCESS * , ULONG , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0040*/ UCHAR (* FastIoUnlockAll)( _FILE_OBJECT * , _EPROCESS * , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0048*/ UCHAR (* FastIoUnlockAllByKey)( _FILE_OBJECT * , void * , ULONG , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0050*/ UCHAR (* FastIoDeviceControl)( _FILE_OBJECT * , UCHAR , void * , ULONG , void * , ULONG , ULONG , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0058*/ void (* AcquireFileForNtCreateSection)( _FILE_OBJECT * );
	/*0060*/ void (* ReleaseFileForNtCreateSection)( _FILE_OBJECT * );
	/*0068*/ void (* FastIoDetachDevice)( _DEVICE_OBJECT * , _DEVICE_OBJECT * );
	/*0070*/ UCHAR (* FastIoQueryNetworkOpenInfo)( _FILE_OBJECT * , UCHAR , _FILE_NETWORK_OPEN_INFORMATION * , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0078*/ LONG (* AcquireForModWrite)( _FILE_OBJECT * , _LARGE_INTEGER * , _ERESOURCE * * , _DEVICE_OBJECT * );
	/*0080*/ UCHAR (* MdlRead)( _FILE_OBJECT * , _LARGE_INTEGER * , ULONG , ULONG , _MDL * * , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0088*/ UCHAR (* MdlReadComplete)( _FILE_OBJECT * , _MDL * , _DEVICE_OBJECT * );
	/*0090*/ UCHAR (* PrepareMdlWrite)( _FILE_OBJECT * , _LARGE_INTEGER * , ULONG , ULONG , _MDL * * , _IO_STATUS_BLOCK * , _DEVICE_OBJECT * );
	/*0098*/ UCHAR (* MdlWriteComplete)( _FILE_OBJECT * , _LARGE_INTEGER * , _MDL * , _DEVICE_OBJECT * );
	/*00a0*/ UCHAR (* FastIoReadCompressed)( _FILE_OBJECT * , _LARGE_INTEGER * , ULONG , ULONG , void * , _MDL * * , _IO_STATUS_BLOCK * , _COMPRESSED_DATA_INFO * , ULONG , _DEVICE_OBJECT * );
	/*00a8*/ UCHAR (* FastIoWriteCompressed)( _FILE_OBJECT * , _LARGE_INTEGER * , ULONG , ULONG , void * , _MDL * * , _IO_STATUS_BLOCK * , _COMPRESSED_DATA_INFO * , ULONG , _DEVICE_OBJECT * );
	/*00b0*/ UCHAR (* MdlReadCompleteCompressed)( _FILE_OBJECT * , _MDL * , _DEVICE_OBJECT * );
	/*00b8*/ UCHAR (* MdlWriteCompleteCompressed)( _FILE_OBJECT * , _LARGE_INTEGER * , _MDL * , _DEVICE_OBJECT * );
	/*00c0*/ UCHAR (* FastIoQueryOpen)( _IRP * , _FILE_NETWORK_OPEN_INFORMATION * , _DEVICE_OBJECT * );
	/*00c8*/ LONG (* ReleaseForModWrite)( _FILE_OBJECT * , _ERESOURCE * , _DEVICE_OBJECT * );
	/*00d0*/ LONG (* AcquireForCcFlush)( _FILE_OBJECT * , _DEVICE_OBJECT * );
	/*00d8*/ LONG (* ReleaseForCcFlush)( _FILE_OBJECT * , _DEVICE_OBJECT * );
	/*00e0*/
};

struct _FAST_MUTEX {
	/*0000*/ LONG Count;
	/*0008*/ void * Owner;
	/*0010*/ ULONG Contention;
	/*0018*/ _KEVENT Event;
	/*0030*/ ULONG OldIrql;
	/*0038*/
};

struct _FAST_OWNER_ENTRY {
	/*0000*/ void * Reserved[0x9];
	/*0048*/
};

struct _FAST_OWNER_ENTRY_INTERNAL {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ UCHAR AbLockHandle;
	/*0011*/ UCHAR Disowned : 01; // 0x01;
	/*0011*/ UCHAR DynamicallyAllocated : 01; // 0x02;
	/*0011*/ UCHAR CallerExclusive : 01; // 0x04;
	/*0012*/ UCHAR IsSublistHead;
	/*0013*/ UCHAR IsWaiting;
	/*0018*/ void * LockAddress;
	/*0020*/ void * ThreadAddress;
	/*0028*/ _LIST_ENTRY SublistHead;
	/*0038*/ _LIST_ENTRY LockListEntry;
	/*0048*/
};

struct _FILESYSTEM_DISK_COUNTERS {
	/*0000*/ ULONGLONG FsBytesRead;
	/*0008*/ ULONGLONG FsBytesWritten;
	/*0010*/
};

struct _FILE_BASIC_INFORMATION {
	/*0000*/ _LARGE_INTEGER CreationTime;
	/*0008*/ _LARGE_INTEGER LastAccessTime;
	/*0010*/ _LARGE_INTEGER LastWriteTime;
	/*0018*/ _LARGE_INTEGER ChangeTime;
	/*0020*/ ULONG FileAttributes;
	/*0028*/
};

struct _FILE_GET_QUOTA_INFORMATION {
	/*0000*/ ULONG NextEntryOffset;
	/*0004*/ ULONG SidLength;
	/*0008*/ _SID Sid;
	/*0014*/
};

enum _FILE_INFORMATION_CLASS {
	FileDirectoryInformation = 0x1,
	FileFullDirectoryInformation = 0x2,
	FileBothDirectoryInformation = 0x3,
	FileBasicInformation = 0x4,
	FileStandardInformation = 0x5,
	FileInternalInformation = 0x6,
	FileEaInformation = 0x7,
	FileAccessInformation = 0x8,
	FileNameInformation = 0x9,
	FileRenameInformation = 0xa,
	FileLinkInformation = 0xb,
	FileNamesInformation = 0xc,
	FileDispositionInformation = 0xd,
	FilePositionInformation = 0xe,
	FileFullEaInformation = 0xf,
	FileModeInformation = 0x10,
	FileAlignmentInformation = 0x11,
	FileAllInformation = 0x12,
	FileAllocationInformation = 0x13,
	FileEndOfFileInformation = 0x14,
	FileAlternateNameInformation = 0x15,
	FileStreamInformation = 0x16,
	FilePipeInformation = 0x17,
	FilePipeLocalInformation = 0x18,
	FilePipeRemoteInformation = 0x19,
	FileMailslotQueryInformation = 0x1a,
	FileMailslotSetInformation = 0x1b,
	FileCompressionInformation = 0x1c,
	FileObjectIdInformation = 0x1d,
	FileCompletionInformation = 0x1e,
	FileMoveClusterInformation = 0x1f,
	FileQuotaInformation = 0x20,
	FileReparsePointInformation = 0x21,
	FileNetworkOpenInformation = 0x22,
	FileAttributeTagInformation = 0x23,
	FileTrackingInformation = 0x24,
	FileIdBothDirectoryInformation = 0x25,
	FileIdFullDirectoryInformation = 0x26,
	FileValidDataLengthInformation = 0x27,
	FileShortNameInformation = 0x28,
	FileIoCompletionNotificationInformation = 0x29,
	FileIoStatusBlockRangeInformation = 0x2a,
	FileIoPriorityHintInformation = 0x2b,
	FileSfioReserveInformation = 0x2c,
	FileSfioVolumeInformation = 0x2d,
	FileHardLinkInformation = 0x2e,
	FileProcessIdsUsingFileInformation = 0x2f,
	FileNormalizedNameInformation = 0x30,
	FileNetworkPhysicalNameInformation = 0x31,
	FileIdGlobalTxDirectoryInformation = 0x32,
	FileIsRemoteDeviceInformation = 0x33,
	FileUnusedInformation = 0x34,
	FileNumaNodeInformation = 0x35,
	FileStandardLinkInformation = 0x36,
	FileRemoteProtocolInformation = 0x37,
	FileRenameInformationBypassAccessCheck = 0x38,
	FileLinkInformationBypassAccessCheck = 0x39,
	FileVolumeNameInformation = 0x3a,
	FileIdInformation = 0x3b,
	FileIdExtdDirectoryInformation = 0x3c,
	FileReplaceCompletionInformation = 0x3d,
	FileHardLinkFullIdInformation = 0x3e,
	FileIdExtdBothDirectoryInformation = 0x3f,
	FileDispositionInformationEx = 0x40,
	FileRenameInformationEx = 0x41,
	FileRenameInformationExBypassAccessCheck = 0x42,
	FileDesiredStorageClassInformation = 0x43,
	FileStatInformation = 0x44,
	FileMemoryPartitionInformation = 0x45,
	FileMaximumInformation = 0x46
};

struct _FILE_NETWORK_OPEN_INFORMATION {
	/*0000*/ _LARGE_INTEGER CreationTime;
	/*0008*/ _LARGE_INTEGER LastAccessTime;
	/*0010*/ _LARGE_INTEGER LastWriteTime;
	/*0018*/ _LARGE_INTEGER ChangeTime;
	/*0020*/ _LARGE_INTEGER AllocationSize;
	/*0028*/ _LARGE_INTEGER EndOfFile;
	/*0030*/ ULONG FileAttributes;
	/*0038*/
};

struct _FILE_OBJECT {
	/*0000*/ SHORT Type;
	/*0002*/ SHORT Size;
	/*0008*/ _DEVICE_OBJECT * DeviceObject;
	/*0010*/ _VPB * Vpb;
	/*0018*/ void * FsContext;
	/*0020*/ void * FsContext2;
	/*0028*/ _SECTION_OBJECT_POINTERS * SectionObjectPointer;
	/*0030*/ void * PrivateCacheMap;
	/*0038*/ LONG FinalStatus;
	/*0040*/ _FILE_OBJECT * RelatedFileObject;
	/*0048*/ UCHAR LockOperation;
	/*0049*/ UCHAR DeletePending;
	/*004a*/ UCHAR ReadAccess;
	/*004b*/ UCHAR WriteAccess;
	/*004c*/ UCHAR DeleteAccess;
	/*004d*/ UCHAR SharedRead;
	/*004e*/ UCHAR SharedWrite;
	/*004f*/ UCHAR SharedDelete;
	/*0050*/ ULONG Flags;
	/*0058*/ _UNICODE_STRING FileName;
	/*0068*/ _LARGE_INTEGER CurrentByteOffset;
	/*0070*/ ULONG Waiters;
	/*0074*/ ULONG Busy;
	/*0078*/ void * LastLock;
	/*0080*/ _KEVENT Lock;
	/*0098*/ _KEVENT Event;
	/*00b0*/ _IO_COMPLETION_CONTEXT * CompletionContext;
	/*00b8*/ ULONGLONG IrpListLock;
	/*00c0*/ _LIST_ENTRY IrpList;
	/*00d0*/ void * FileObjectExtension;
	/*00d8*/
};

enum _FILE_OBJECT_EXTENSION_TYPE {
	FoExtTypeTransactionParams = 0x0,
	FoExtTypeInternal = 0x1,
	FoExtTypeIosbRange = 0x2,
	FoExtTypeGeneric = 0x3,
	FoExtTypeSfio = 0x4,
	FoExtTypeSymlink = 0x5,
	FoExtTypeOplockKey = 0x6,
	FoExtTypeSilo = 0x7,
	FoExtTypeMemoryPartitionInfo = 0x8,
	MaxFoExtTypes = 0x9
};

union _FILE_SEGMENT_ELEMENT {
	/*0000*/ void * Buffer;
	/*0000*/ ULONGLONG Alignment;
	/*0008*/
};

struct _FILE_STANDARD_INFORMATION {
	/*0000*/ _LARGE_INTEGER AllocationSize;
	/*0008*/ _LARGE_INTEGER EndOfFile;
	/*0010*/ ULONG NumberOfLinks;
	/*0014*/ UCHAR DeletePending;
	/*0015*/ UCHAR Directory;
	/*0018*/
};

struct _FLS_CALLBACK_INFO;

struct _FREE_DISPLAY {
	/*0000*/ ULONG RealVectorSize;
	/*0004*/ ULONG Hint;
	/*0008*/ _RTL_BITMAP Display;
	/*0018*/
};

enum _FSINFOCLASS {
	FileFsVolumeInformation = 0x1,
	FileFsLabelInformation = 0x2,
	FileFsSizeInformation = 0x3,
	FileFsDeviceInformation = 0x4,
	FileFsAttributeInformation = 0x5,
	FileFsControlInformation = 0x6,
	FileFsFullSizeInformation = 0x7,
	FileFsObjectIdInformation = 0x8,
	FileFsDriverPathInformation = 0x9,
	FileFsVolumeFlagsInformation = 0xa,
	FileFsSectorSizeInformation = 0xb,
	FileFsDataCopyInformation = 0xc,
	FileFsMetadataSizeInformation = 0xd,
	FileFsMaximumInformation = 0xe
};

struct _FSRTL_ADVANCED_FCB_HEADER {
	/*0000*/ SHORT NodeTypeCode;
	/*0002*/ SHORT NodeByteSize;
	/*0004*/ UCHAR Flags;
	/*0005*/ UCHAR IsFastIoPossible;
	/*0006*/ UCHAR Flags2;
	/*0007*/ UCHAR Reserved : 04; // 0x0f;
	/*0007*/ UCHAR Version : 04; // 0xf0;
	/*0008*/ _ERESOURCE * Resource;
	/*0010*/ _ERESOURCE * PagingIoResource;
	/*0018*/ _LARGE_INTEGER AllocationSize;
	/*0020*/ _LARGE_INTEGER FileSize;
	/*0028*/ _LARGE_INTEGER ValidDataLength;
	/*0030*/ _FAST_MUTEX * FastMutex;
	/*0038*/ _LIST_ENTRY FilterContexts;
	/*0048*/ _EX_PUSH_LOCK PushLock;
	/*0050*/ void * * FileContextSupportPointer;
	/*0058*/ void * Oplock;
	/*0058*/ void * ReservedForRemote;
	/*0060*/ void * ReservedContext;
	/*0068*/
};

struct _FS_FILTER_CALLBACKS {
	/*0000*/ ULONG SizeOfFsFilterCallbacks;
	/*0004*/ ULONG Reserved;
	/*0008*/ LONG (* PreAcquireForSectionSynchronization)( _FS_FILTER_CALLBACK_DATA * , void * * );
	/*0010*/ void (* PostAcquireForSectionSynchronization)( _FS_FILTER_CALLBACK_DATA * , LONG , void * );
	/*0018*/ LONG (* PreReleaseForSectionSynchronization)( _FS_FILTER_CALLBACK_DATA * , void * * );
	/*0020*/ void (* PostReleaseForSectionSynchronization)( _FS_FILTER_CALLBACK_DATA * , LONG , void * );
	/*0028*/ LONG (* PreAcquireForCcFlush)( _FS_FILTER_CALLBACK_DATA * , void * * );
	/*0030*/ void (* PostAcquireForCcFlush)( _FS_FILTER_CALLBACK_DATA * , LONG , void * );
	/*0038*/ LONG (* PreReleaseForCcFlush)( _FS_FILTER_CALLBACK_DATA * , void * * );
	/*0040*/ void (* PostReleaseForCcFlush)( _FS_FILTER_CALLBACK_DATA * , LONG , void * );
	/*0048*/ LONG (* PreAcquireForModifiedPageWriter)( _FS_FILTER_CALLBACK_DATA * , void * * );
	/*0050*/ void (* PostAcquireForModifiedPageWriter)( _FS_FILTER_CALLBACK_DATA * , LONG , void * );
	/*0058*/ LONG (* PreReleaseForModifiedPageWriter)( _FS_FILTER_CALLBACK_DATA * , void * * );
	/*0060*/ void (* PostReleaseForModifiedPageWriter)( _FS_FILTER_CALLBACK_DATA * , LONG , void * );
	/*0068*/ LONG (* PreQueryOpen)( _FS_FILTER_CALLBACK_DATA * , void * * );
	/*0070*/ void (* PostQueryOpen)( _FS_FILTER_CALLBACK_DATA * , LONG , void * );
	/*0078*/
};

struct _FS_FILTER_CALLBACK_DATA {
	/*0000*/ ULONG SizeOfFsFilterCallbackData;
	/*0004*/ UCHAR Operation;
	/*0005*/ UCHAR Reserved;
	/*0008*/ _DEVICE_OBJECT * DeviceObject;
	/*0010*/ _FILE_OBJECT * FileObject;
	/*0018*/ _FS_FILTER_PARAMETERS Parameters;
	/*0040*/
};

union _FS_FILTER_PARAMETERS {
	struct {
		/*0000*/ _LARGE_INTEGER * EndingOffset;
		/*0008*/ _ERESOURCE * * ResourceToRelease;
		/*0010*/
	} AcquireForModifiedPageWriter;
	struct {
		/*0000*/ _ERESOURCE * ResourceToRelease;
		/*0008*/
	} ReleaseForModifiedPageWriter;
	struct {
		/*0000*/ _FS_FILTER_SECTION_SYNC_TYPE SyncType;
		/*0004*/ ULONG PageProtection;
		/*0008*/ _FS_FILTER_SECTION_SYNC_OUTPUT * OutputInformation;
		/*0010*/
	} AcquireForSectionSynchronization;
	struct {
		/*0000*/ _FS_FILTER_STREAM_FO_NOTIFICATION_TYPE NotificationType;
		/*0008*/ UCHAR SafeToRecurse;
		/*0010*/
	} NotifyStreamFileObject;
	struct {
		/*0000*/ _IRP * Irp;
		/*0008*/ void * FileInformation;
		/*0010*/ ULONG * Length;
		/*0018*/ _FILE_INFORMATION_CLASS FileInformationClass;
		/*001c*/ LONG CompletionStatus;
		/*0020*/
	} QueryOpen;
	struct {
		/*0000*/ void * Argument1;
		/*0008*/ void * Argument2;
		/*0010*/ void * Argument3;
		/*0018*/ void * Argument4;
		/*0020*/ void * Argument5;
		/*0028*/
	} Others;
	/*0028*/
};

struct _FS_FILTER_SECTION_SYNC_OUTPUT {
	/*0000*/ ULONG StructureSize;
	/*0004*/ ULONG SizeReturned;
	/*0008*/ ULONG Flags;
	/*000c*/ ULONG DesiredReadAlignment;
	/*0010*/
};

enum _FS_FILTER_SECTION_SYNC_TYPE {
	SyncTypeOther = 0x0,
	SyncTypeCreateSection = 0x1
};

enum _FS_FILTER_STREAM_FO_NOTIFICATION_TYPE {
	NotifyTypeCreate = 0x0,
	NotifyTypeRetired = 0x1
};

enum _FUNCTION_TABLE_TYPE {
	RF_SORTED = 0x0,
	RF_UNSORTED = 0x1,
	RF_CALLBACK = 0x2,
	RF_KERNEL_DYNAMIC = 0x3
};

struct _GDI_TEB_BATCH {
	/*0000*/ ULONG Offset : 31; // 0x7fffffff;
	/*0000*/ ULONG HasRenderingCommand : 01; // 0x80000000;
	/*0008*/ ULONGLONG HDC;
	/*0010*/ ULONG Buffer[0x136];
	/*04e8*/
};

struct _GDI_TEB_BATCH32 {
	/*0000*/ ULONG Offset : 31; // 0x7fffffff;
	/*0000*/ ULONG HasRenderingCommand : 01; // 0x80000000;
	/*0004*/ ULONG HDC;
	/*0008*/ ULONG Buffer[0x136];
	/*04e0*/
};

struct _GDI_TEB_BATCH64 {
	/*0000*/ ULONG Offset : 31; // 0x7fffffff;
	/*0000*/ ULONG HasRenderingCommand : 01; // 0x80000000;
	/*0008*/ ULONGLONG HDC;
	/*0010*/ ULONG Buffer[0x136];
	/*04e8*/
};

struct _GENERAL_LOOKASIDE {
	/*0000*/ _SLIST_HEADER ListHead;
	/*0000*/ _SINGLE_LIST_ENTRY SingleListHead;
	/*0010*/ USHORT Depth;
	/*0012*/ USHORT MaximumDepth;
	/*0014*/ ULONG TotalAllocates;
	/*0018*/ ULONG AllocateMisses;
	/*0018*/ ULONG AllocateHits;
	/*001c*/ ULONG TotalFrees;
	/*0020*/ ULONG FreeMisses;
	/*0020*/ ULONG FreeHits;
	/*0024*/ _POOL_TYPE Type;
	/*0028*/ ULONG Tag;
	/*002c*/ ULONG Size;
	/*0030*/ void * (* AllocateEx)( _POOL_TYPE , ULONGLONG , ULONG , _LOOKASIDE_LIST_EX * );
	/*0030*/ void * (* Allocate)( _POOL_TYPE , ULONGLONG , ULONG );
	/*0038*/ void (* FreeEx)( void * , _LOOKASIDE_LIST_EX * );
	/*0038*/ void (* Free)( void * );
	/*0040*/ _LIST_ENTRY ListEntry;
	/*0050*/ ULONG LastTotalAllocates;
	/*0054*/ ULONG LastAllocateMisses;
	/*0054*/ ULONG LastAllocateHits;
	/*0058*/ ULONG Future[0x2];
	/*0080*/
};

struct _GENERAL_LOOKASIDE_POOL {
	/*0000*/ _SLIST_HEADER ListHead;
	/*0000*/ _SINGLE_LIST_ENTRY SingleListHead;
	/*0010*/ USHORT Depth;
	/*0012*/ USHORT MaximumDepth;
	/*0014*/ ULONG TotalAllocates;
	/*0018*/ ULONG AllocateMisses;
	/*0018*/ ULONG AllocateHits;
	/*001c*/ ULONG TotalFrees;
	/*0020*/ ULONG FreeMisses;
	/*0020*/ ULONG FreeHits;
	/*0024*/ _POOL_TYPE Type;
	/*0028*/ ULONG Tag;
	/*002c*/ ULONG Size;
	/*0030*/ void * (* AllocateEx)( _POOL_TYPE , ULONGLONG , ULONG , _LOOKASIDE_LIST_EX * );
	/*0030*/ void * (* Allocate)( _POOL_TYPE , ULONGLONG , ULONG );
	/*0038*/ void (* FreeEx)( void * , _LOOKASIDE_LIST_EX * );
	/*0038*/ void (* Free)( void * );
	/*0040*/ _LIST_ENTRY ListEntry;
	/*0050*/ ULONG LastTotalAllocates;
	/*0054*/ ULONG LastAllocateMisses;
	/*0054*/ ULONG LastAllocateHits;
	/*0058*/ ULONG Future[0x2];
	/*0060*/
};

struct _GENERIC_MAPPING {
	/*0000*/ ULONG GenericRead;
	/*0004*/ ULONG GenericWrite;
	/*0008*/ ULONG GenericExecute;
	/*000c*/ ULONG GenericAll;
	/*0010*/
};

enum _GPIO_PIN_CONFIG_TYPE {
	PullDefault = 0x0,
	PullUp = 0x1,
	PullDown = 0x2,
	PullNone = 0x3
};

enum _GPIO_PIN_IORESTRICTION_TYPE {
	IoRestrictionNone = 0x0,
	IoRestrictionInputOnly = 0x1,
	IoRestrictionOutputOnly = 0x2,
	IoRestrictionNoneAndPreserve = 0x3
};

struct _GROUP_AFFINITY {
	/*0000*/ ULONGLONG Mask;
	/*0008*/ USHORT Group;
	/*000a*/ USHORT Reserved[0x3];
	/*0010*/
};

struct _GUID {
	/*0000*/ ULONG Data1;
	/*0004*/ USHORT Data2;
	/*0006*/ USHORT Data3;
	/*0008*/ UCHAR Data4[0x8];
	/*0010*/
};

struct _HAL_CHANNEL_MEMORY_RANGES {
	/*0000*/ ULONGLONG PageFrameIndex;
	/*0008*/ USHORT MpnId;
	/*000a*/ USHORT Node;
	/*000c*/ USHORT Channel;
	/*000e*/ UCHAR IsPowerManageable;
	/*000f*/ UCHAR DeepPowerState;
	/*0010*/
};

struct _HAL_NODE_RANGE {
	/*0000*/ ULONGLONG PageFrameIndex;
	/*0008*/ ULONG Node;
	/*0010*/
};

struct _HAL_PMC_COUNTERS;

struct _HANDLE_REVOCATION_INFO {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _OB_HANDLE_REVOCATION_BLOCK * RevocationBlock;
	/*0018*/ UCHAR AllowHandleRevocation;
	/*0019*/ UCHAR Padding1[0x3];
	/*001c*/ UCHAR Padding2[0x4];
	/*0020*/
};

struct _HANDLE_TABLE {
	/*0000*/ ULONG NextHandleNeedingPool;
	/*0004*/ LONG ExtraInfoPages;
	/*0008*/ ULONGLONG volatile TableCode;
	/*0010*/ _EPROCESS * QuotaProcess;
	/*0018*/ _LIST_ENTRY HandleTableList;
	/*0028*/ ULONG UniqueProcessId;
	/*002c*/ ULONG Flags;
	/*002c*/ UCHAR StrictFIFO : 01; // 0x01;
	/*002c*/ UCHAR EnableHandleExceptions : 01; // 0x02;
	/*002c*/ UCHAR Rundown : 01; // 0x04;
	/*002c*/ UCHAR Duplicated : 01; // 0x08;
	/*002c*/ UCHAR RaiseUMExceptionOnInvalidHandleClose : 01; // 0x10;
	/*0030*/ _EX_PUSH_LOCK HandleContentionEvent;
	/*0038*/ _EX_PUSH_LOCK HandleTableLock;
	/*0040*/ _HANDLE_TABLE_FREE_LIST FreeLists[0x1];
	/*0040*/ UCHAR ActualEntry[0x20];
	/*0060*/ _HANDLE_TRACE_DEBUG_INFO * DebugInfo;
	/*0080*/
};

union _HANDLE_TABLE_ENTRY {
	/*0000*/ LONGLONG volatile VolatileLowValue;
	/*0000*/ LONGLONG LowValue;
	/*0000*/ _HANDLE_TABLE_ENTRY_INFO * volatile InfoTable;
	/*0008*/ LONGLONG HighValue;
	/*0008*/ _HANDLE_TABLE_ENTRY * NextFreeHandleEntry;
	/*0008*/ _EXHANDLE LeafHandleValue;
	/*0000*/ LONGLONG RefCountField;
	/*0000*/ ULONGLONG Unlocked : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG RefCnt : 16; // 0x000000000001fffe;
	/*0000*/ ULONGLONG Attributes : 03; // 0x00000000000e0000;
	/*0000*/ ULONGLONG ObjectPointerBits : 44; // 0xfffffffffff00000;
	/*0008*/ ULONG GrantedAccessBits : 25; // 0x01ffffff;
	/*0008*/ ULONG NoRightsUpgrade : 01; // 0x02000000;
	/*0008*/ ULONG Spare1 : 06; // 0xfc000000;
	/*000c*/ ULONG Spare2;
	/*0010*/
};

struct _HANDLE_TABLE_ENTRY_INFO {
	/*0000*/ ULONG AuditMask;
	/*0004*/ ULONG MaxRelativeAccessMask;
	/*0008*/
};

struct _HANDLE_TABLE_FREE_LIST {
	/*0000*/ _EX_PUSH_LOCK FreeListLock;
	/*0008*/ _HANDLE_TABLE_ENTRY * FirstFreeHandleEntry;
	/*0010*/ _HANDLE_TABLE_ENTRY * LastFreeHandleEntry;
	/*0018*/ LONG HandleCount;
	/*001c*/ ULONG HighWaterMark;
	/*0040*/
};

struct _HANDLE_TRACE_DB_ENTRY {
	/*0000*/ _CLIENT_ID ClientId;
	/*0010*/ void * Handle;
	/*0018*/ ULONG Type;
	/*0020*/ void * StackTrace[0x10];
	/*00a0*/
};

struct _HANDLE_TRACE_DEBUG_INFO {
	/*0000*/ LONG RefCount;
	/*0004*/ ULONG TableSize;
	/*0008*/ ULONG BitMaskFlags;
	/*0010*/ _FAST_MUTEX CloseCompactionLock;
	/*0048*/ ULONG CurrentStackIndex;
	/*0050*/ _HANDLE_TRACE_DB_ENTRY TraceDb[0x1];
	/*00f0*/
};

enum _HARDWARE_COUNTER_TYPE {
	PMCCounter = 0x0,
	MaxHardwareCounterType = 0x1
};

struct _HARDWARE_PTE {
	/*0000*/ ULONGLONG Valid : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG Write : 01; // 0x0000000000000002;
	/*0000*/ ULONGLONG Owner : 01; // 0x0000000000000004;
	/*0000*/ ULONGLONG WriteThrough : 01; // 0x0000000000000008;
	/*0000*/ ULONGLONG CacheDisable : 01; // 0x0000000000000010;
	/*0000*/ ULONGLONG Accessed : 01; // 0x0000000000000020;
	/*0000*/ ULONGLONG Dirty : 01; // 0x0000000000000040;
	/*0000*/ ULONGLONG LargePage : 01; // 0x0000000000000080;
	/*0000*/ ULONGLONG Global : 01; // 0x0000000000000100;
	/*0000*/ ULONGLONG CopyOnWrite : 01; // 0x0000000000000200;
	/*0000*/ ULONGLONG Prototype : 01; // 0x0000000000000400;
	/*0000*/ ULONGLONG reserved0 : 01; // 0x0000000000000800;
	/*0000*/ ULONGLONG PageFrameNumber : 36; // 0x0000fffffffff000;
	/*0000*/ ULONGLONG reserved1 : 04; // 0x000f000000000000;
	/*0000*/ ULONGLONG SoftwareWsIndex : 11; // 0x7ff0000000000000;
	/*0000*/ ULONGLONG NoExecute : 01; // 0x8000000000000000;
	/*0008*/
};

struct _HBASE_BLOCK {
	/*0000*/ ULONG Signature;
	/*0004*/ ULONG Sequence1;
	/*0008*/ ULONG Sequence2;
	/*000c*/ _LARGE_INTEGER TimeStamp;
	/*0014*/ ULONG Major;
	/*0018*/ ULONG Minor;
	/*001c*/ ULONG Type;
	/*0020*/ ULONG Format;
	/*0024*/ ULONG RootCell;
	/*0028*/ ULONG Length;
	/*002c*/ ULONG Cluster;
	/*0030*/ UCHAR FileName[0x40];
	/*0070*/ _GUID RmId;
	/*0080*/ _GUID LogId;
	/*0090*/ ULONG Flags;
	/*0094*/ _GUID TmId;
	/*00a4*/ ULONG GuidSignature;
	/*00a8*/ ULONGLONG LastReorganizeTime;
	/*00b0*/ ULONG Reserved1[0x53];
	/*01fc*/ ULONG CheckSum;
	/*0200*/ ULONG Reserved2[0x372];
	/*0fc8*/ _GUID ThawTmId;
	/*0fd8*/ _GUID ThawRmId;
	/*0fe8*/ _GUID ThawLogId;
	/*0ff8*/ ULONG BootType;
	/*0ffc*/ ULONG BootRecover;
	/*1000*/
};

struct _HBIN {
	/*0000*/ ULONG Signature;
	/*0004*/ ULONG FileOffset;
	/*0008*/ ULONG Size;
	/*000c*/ ULONG Reserved1[0x2];
	/*0014*/ _LARGE_INTEGER TimeStamp;
	/*001c*/ ULONG Spare;
	/*0020*/
};

struct _HCELL {
	/*0000*/ LONG Size;
	union {
		struct {
			union {
				/*0004*/ ULONG UserData;
				/*0004*/ ULONG Next;
				/*0008*/
			} u;
			/*0008*/
		} NewCell;
		/*0008*/
	} u;
	/*0008*/
};

struct _HEAP {
	/*0000*/ _HEAP_SEGMENT Segment;
	/*0000*/ _HEAP_ENTRY Entry;
	/*0010*/ ULONG SegmentSignature;
	/*0014*/ ULONG SegmentFlags;
	/*0018*/ _LIST_ENTRY SegmentListEntry;
	/*0028*/ _HEAP * Heap;
	/*0030*/ void * BaseAddress;
	/*0038*/ ULONG NumberOfPages;
	/*0040*/ _HEAP_ENTRY * FirstEntry;
	/*0048*/ _HEAP_ENTRY * LastValidEntry;
	/*0050*/ ULONG NumberOfUnCommittedPages;
	/*0054*/ ULONG NumberOfUnCommittedRanges;
	/*0058*/ USHORT SegmentAllocatorBackTraceIndex;
	/*005a*/ USHORT Reserved;
	/*0060*/ _LIST_ENTRY UCRSegmentList;
	/*0070*/ ULONG Flags;
	/*0074*/ ULONG ForceFlags;
	/*0078*/ ULONG CompatibilityFlags;
	/*007c*/ ULONG EncodeFlagMask;
	/*0080*/ _HEAP_ENTRY Encoding;
	/*0090*/ ULONG Interceptor;
	/*0094*/ ULONG VirtualMemoryThreshold;
	/*0098*/ ULONG Signature;
	/*00a0*/ ULONGLONG SegmentReserve;
	/*00a8*/ ULONGLONG SegmentCommit;
	/*00b0*/ ULONGLONG DeCommitFreeBlockThreshold;
	/*00b8*/ ULONGLONG DeCommitTotalFreeThreshold;
	/*00c0*/ ULONGLONG TotalFreeSize;
	/*00c8*/ ULONGLONG MaximumAllocationSize;
	/*00d0*/ USHORT ProcessHeapsListIndex;
	/*00d2*/ USHORT HeaderValidateLength;
	/*00d8*/ void * HeaderValidateCopy;
	/*00e0*/ USHORT NextAvailableTagIndex;
	/*00e2*/ USHORT MaximumTagIndex;
	/*00e8*/ _HEAP_TAG_ENTRY * TagEntries;
	/*00f0*/ _LIST_ENTRY UCRList;
	/*0100*/ ULONGLONG AlignRound;
	/*0108*/ ULONGLONG AlignMask;
	/*0110*/ _LIST_ENTRY VirtualAllocdBlocks;
	/*0120*/ _LIST_ENTRY SegmentList;
	/*0130*/ USHORT AllocatorBackTraceIndex;
	/*0134*/ ULONG NonDedicatedListLength;
	/*0138*/ void * BlocksIndex;
	/*0140*/ void * UCRIndex;
	/*0148*/ _HEAP_PSEUDO_TAG_ENTRY * PseudoTagEntries;
	/*0150*/ _LIST_ENTRY FreeLists;
	/*0160*/ _HEAP_LOCK * LockVariable;
	/*0168*/ LONG (* CommitRoutine)( void * , void * * , ULONGLONG * );
	/*0170*/ _RTL_RUN_ONCE StackTraceInitVar;
	/*0178*/ void * FrontEndHeap;
	/*0180*/ USHORT FrontHeapLockCount;
	/*0182*/ UCHAR FrontEndHeapType;
	/*0183*/ UCHAR RequestedFrontEndHeapType;
	/*0188*/ USHORT * FrontEndHeapUsageData;
	/*0190*/ USHORT FrontEndHeapMaximumIndex;
	/*0192*/ UCHAR volatile FrontEndHeapStatusBitmap[0x81];
	/*0218*/ _HEAP_COUNTERS Counters;
	/*0290*/ _HEAP_TUNING_PARAMETERS TuningParameters;
	/*02a0*/
};

struct _HEAP_COUNTERS {
	/*0000*/ ULONGLONG TotalMemoryReserved;
	/*0008*/ ULONGLONG TotalMemoryCommitted;
	/*0010*/ ULONGLONG TotalMemoryLargeUCR;
	/*0018*/ ULONGLONG TotalSizeInVirtualBlocks;
	/*0020*/ ULONG TotalSegments;
	/*0024*/ ULONG TotalUCRs;
	/*0028*/ ULONG CommittOps;
	/*002c*/ ULONG DeCommitOps;
	/*0030*/ ULONG LockAcquires;
	/*0034*/ ULONG LockCollisions;
	/*0038*/ ULONG CommitRate;
	/*003c*/ ULONG DecommittRate;
	/*0040*/ ULONG CommitFailures;
	/*0044*/ ULONG InBlockCommitFailures;
	/*0048*/ ULONG PollIntervalCounter;
	/*004c*/ ULONG DecommitsSinceLastCheck;
	/*0050*/ ULONG HeapPollInterval;
	/*0054*/ ULONG AllocAndFreeOps;
	/*0058*/ ULONG AllocationIndicesActive;
	/*005c*/ ULONG InBlockDeccommits;
	/*0060*/ ULONGLONG InBlockDeccomitSize;
	/*0068*/ ULONGLONG HighWatermarkSize;
	/*0070*/ ULONGLONG LastPolledSize;
	/*0078*/
};

struct _HEAP_ENTRY {
	/*0000*/ _HEAP_UNPACKED_ENTRY UnpackedEntry;
	/*0000*/ void * PreviousBlockPrivateData;
	/*0008*/ USHORT Size;
	/*000a*/ UCHAR Flags;
	/*000b*/ UCHAR SmallTagIndex;
	/*0008*/ ULONG SubSegmentCode;
	/*000c*/ USHORT PreviousSize;
	/*000e*/ UCHAR SegmentOffset;
	/*000e*/ UCHAR LFHFlags;
	/*000f*/ UCHAR UnusedBytes;
	/*0008*/ ULONGLONG CompactHeader;
	/*0000*/ _HEAP_EXTENDED_ENTRY ExtendedEntry;
	/*0000*/ void * Reserved;
	/*0008*/ USHORT FunctionIndex;
	/*000a*/ USHORT ContextValue;
	/*0008*/ ULONG InterceptorValue;
	/*000c*/ USHORT UnusedBytesLength;
	/*000e*/ UCHAR EntryOffset;
	/*000f*/ UCHAR ExtendedBlockSignature;
	/*0000*/ void * ReservedForAlignment;
	/*0008*/ ULONG Code1;
	/*000c*/ USHORT Code2;
	/*000e*/ UCHAR Code3;
	/*000f*/ UCHAR Code4;
	/*000c*/ ULONG Code234;
	/*0008*/ ULONGLONG AgregateCode;
	/*0010*/
};

struct _HEAP_ENTRY_EXTRA {
	/*0000*/ USHORT AllocatorBackTraceIndex;
	/*0002*/ USHORT TagIndex;
	/*0008*/ ULONGLONG Settable;
	/*0000*/ ULONGLONG ZeroInit;
	/*0008*/ ULONGLONG ZeroInit1;
	/*0010*/
};

struct _HEAP_EXTENDED_ENTRY {
	/*0000*/ void * Reserved;
	/*0008*/ USHORT FunctionIndex;
	/*000a*/ USHORT ContextValue;
	/*0008*/ ULONG InterceptorValue;
	/*000c*/ USHORT UnusedBytesLength;
	/*000e*/ UCHAR EntryOffset;
	/*000f*/ UCHAR ExtendedBlockSignature;
	/*0010*/
};

enum _HEAP_FAILURE_TYPE {
	heap_failure_internal = 0x0,
	heap_failure_unknown = 0x1,
	heap_failure_generic = 0x2,
	heap_failure_entry_corruption = 0x3,
	heap_failure_multiple_entries_corruption = 0x4,
	heap_failure_virtual_block_corruption = 0x5,
	heap_failure_buffer_overrun = 0x6,
	heap_failure_buffer_underrun = 0x7,
	heap_failure_block_not_busy = 0x8,
	heap_failure_invalid_argument = 0x9,
	heap_failure_usage_after_free = 0xa,
	heap_failure_cross_heap_operation = 0xb,
	heap_failure_freelists_corruption = 0xc,
	heap_failure_listentry_corruption = 0xd,
	heap_failure_lfh_bitmap_mismatch = 0xe,
	heap_failure_segment_lfh_bitmap_corruption = 0xf,
	heap_failure_segment_lfh_double_free = 0x10,
	heap_failure_vs_subsegment_corruption = 0x11,
	heap_failure_null_heap = 0x12
};

struct _HEAP_FREE_ENTRY {
	/*0000*/ _HEAP_ENTRY HeapEntry;
	/*0000*/ _HEAP_UNPACKED_ENTRY UnpackedEntry;
	/*0000*/ void * PreviousBlockPrivateData;
	/*0008*/ USHORT Size;
	/*000a*/ UCHAR Flags;
	/*000b*/ UCHAR SmallTagIndex;
	/*0008*/ ULONG SubSegmentCode;
	/*000c*/ USHORT PreviousSize;
	/*000e*/ UCHAR SegmentOffset;
	/*000e*/ UCHAR LFHFlags;
	/*000f*/ UCHAR UnusedBytes;
	/*0008*/ ULONGLONG CompactHeader;
	/*0000*/ _HEAP_EXTENDED_ENTRY ExtendedEntry;
	/*0000*/ void * Reserved;
	/*0008*/ USHORT FunctionIndex;
	/*000a*/ USHORT ContextValue;
	/*0008*/ ULONG InterceptorValue;
	/*000c*/ USHORT UnusedBytesLength;
	/*000e*/ UCHAR EntryOffset;
	/*000f*/ UCHAR ExtendedBlockSignature;
	/*0000*/ void * ReservedForAlignment;
	/*0008*/ ULONG Code1;
	/*000c*/ USHORT Code2;
	/*000e*/ UCHAR Code3;
	/*000f*/ UCHAR Code4;
	/*000c*/ ULONG Code234;
	/*0008*/ ULONGLONG AgregateCode;
	/*0010*/ _LIST_ENTRY FreeList;
	/*0020*/
};

struct _HEAP_FREE_ENTRY_EXTRA {
	/*0000*/ USHORT TagIndex;
	/*0002*/ USHORT FreeBackTraceIndex;
	/*0004*/
};

struct _HEAP_LIST_LOOKUP {
	/*0000*/ _HEAP_LIST_LOOKUP * ExtendedLookup;
	/*0008*/ ULONG ArraySize;
	/*000c*/ ULONG ExtraItem;
	/*0010*/ ULONG ItemCount;
	/*0014*/ ULONG OutOfRangeItems;
	/*0018*/ ULONG BaseIndex;
	/*0020*/ _LIST_ENTRY * ListHead;
	/*0028*/ ULONG * ListsInUseUlong;
	/*0030*/ _LIST_ENTRY * * ListHints;
	/*0038*/
};

struct _HEAP_LOCK {
	union {
		/*0000*/ _RTL_CRITICAL_SECTION CriticalSection;
		/*0000*/ _ERESOURCE Resource;
		/*0068*/
	} Lock;
	/*0068*/
};

struct _HEAP_LOOKASIDE {
	/*0000*/ _SLIST_HEADER ListHead;
	/*0010*/ USHORT Depth;
	/*0012*/ USHORT MaximumDepth;
	/*0014*/ ULONG TotalAllocates;
	/*0018*/ ULONG AllocateMisses;
	/*001c*/ ULONG TotalFrees;
	/*0020*/ ULONG FreeMisses;
	/*0024*/ ULONG LastTotalAllocates;
	/*0028*/ ULONG LastAllocateMisses;
	/*002c*/ ULONG Counters[0x2];
	/*0040*/
};

struct _HEAP_PSEUDO_TAG_ENTRY {
	/*0000*/ ULONG Allocs;
	/*0004*/ ULONG Frees;
	/*0008*/ ULONGLONG Size;
	/*0010*/
};

struct _HEAP_SEGMENT {
	/*0000*/ _HEAP_ENTRY Entry;
	/*0010*/ ULONG SegmentSignature;
	/*0014*/ ULONG SegmentFlags;
	/*0018*/ _LIST_ENTRY SegmentListEntry;
	/*0028*/ _HEAP * Heap;
	/*0030*/ void * BaseAddress;
	/*0038*/ ULONG NumberOfPages;
	/*0040*/ _HEAP_ENTRY * FirstEntry;
	/*0048*/ _HEAP_ENTRY * LastValidEntry;
	/*0050*/ ULONG NumberOfUnCommittedPages;
	/*0054*/ ULONG NumberOfUnCommittedRanges;
	/*0058*/ USHORT SegmentAllocatorBackTraceIndex;
	/*005a*/ USHORT Reserved;
	/*0060*/ _LIST_ENTRY UCRSegmentList;
	/*0070*/
};

struct _HEAP_STOP_ON_TAG {
	/*0000*/ ULONG HeapAndTagIndex;
	/*0000*/ USHORT TagIndex;
	/*0002*/ USHORT HeapIndex;
	/*0004*/
};

struct _HEAP_STOP_ON_VALUES {
	/*0000*/ ULONGLONG AllocAddress;
	/*0008*/ _HEAP_STOP_ON_TAG AllocTag;
	/*0010*/ ULONGLONG ReAllocAddress;
	/*0018*/ _HEAP_STOP_ON_TAG ReAllocTag;
	/*0020*/ ULONGLONG FreeAddress;
	/*0028*/ _HEAP_STOP_ON_TAG FreeTag;
	/*0030*/
};

struct _HEAP_SUBALLOCATOR_CALLBACKS {
	/*0000*/ ULONGLONG Allocate;
	/*0008*/ ULONGLONG Free;
	/*0010*/ ULONGLONG Commit;
	/*0018*/ ULONGLONG Decommit;
	/*0020*/ ULONGLONG ExtendContext;
	/*0028*/
};

struct _HEAP_TAG_ENTRY {
	/*0000*/ ULONG Allocs;
	/*0004*/ ULONG Frees;
	/*0008*/ ULONGLONG Size;
	/*0010*/ USHORT TagIndex;
	/*0012*/ USHORT CreatorBackTraceIndex;
	/*0014*/ WCHAR TagName[0x18];
	/*0048*/
};

struct _HEAP_TUNING_PARAMETERS {
	/*0000*/ ULONG CommittThresholdShift;
	/*0008*/ ULONGLONG MaxPreCommittThreshold;
	/*0010*/
};

struct _HEAP_UCR_DESCRIPTOR {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _LIST_ENTRY SegmentEntry;
	/*0020*/ void * Address;
	/*0028*/ ULONGLONG Size;
	/*0030*/
};

struct _HEAP_UNPACKED_ENTRY {
	/*0000*/ void * PreviousBlockPrivateData;
	/*0008*/ USHORT Size;
	/*000a*/ UCHAR Flags;
	/*000b*/ UCHAR SmallTagIndex;
	/*0008*/ ULONG SubSegmentCode;
	/*000c*/ USHORT PreviousSize;
	/*000e*/ UCHAR SegmentOffset;
	/*000e*/ UCHAR LFHFlags;
	/*000f*/ UCHAR UnusedBytes;
	/*0008*/ ULONGLONG CompactHeader;
	/*0010*/
};

struct _HEAP_VIRTUAL_ALLOC_ENTRY {
	/*0000*/ _LIST_ENTRY Entry;
	/*0010*/ _HEAP_ENTRY_EXTRA ExtraStuff;
	/*0020*/ ULONGLONG CommitSize;
	/*0028*/ ULONGLONG ReserveSize;
	/*0030*/ _HEAP_ENTRY BusyBlock;
	/*0040*/
};

struct _HHIVE {
	/*0000*/ ULONG Signature;
	/*0008*/ _CELL_DATA * (* GetCellRoutine)( _HHIVE * , ULONG , _HV_GET_CELL_CONTEXT * );
	/*0010*/ void (* ReleaseCellRoutine)( _HHIVE * , _HV_GET_CELL_CONTEXT * );
	/*0018*/ void * (* Allocate)( ULONG , UCHAR , ULONG );
	/*0020*/ void (* Free)( void * , ULONG );
	/*0028*/ UCHAR (* FileWrite)( _HHIVE * , ULONG , CMP_OFFSET_ARRAY * , ULONG , ULONG * , ULONG );
	/*0030*/ UCHAR (* FileRead)( _HHIVE * , ULONG , ULONG * , void * , ULONG );
	/*0038*/ void * HiveLoadFailure;
	/*0040*/ _HBASE_BLOCK * BaseBlock;
	/*0048*/ _RTL_BITMAP DirtyVector;
	/*0058*/ ULONG DirtyCount;
	/*005c*/ ULONG DirtyAlloc;
	/*0060*/ _RTL_BITMAP UnreconciledVector;
	/*0070*/ ULONG UnreconciledCount;
	/*0074*/ ULONG BaseBlockAlloc;
	/*0078*/ ULONG Cluster;
	/*007c*/ UCHAR Flat : 01; // 0x01;
	/*007c*/ UCHAR ReadOnly : 01; // 0x02;
	/*007c*/ UCHAR SystemCacheBacked : 01; // 0x04;
	/*007c*/ UCHAR Reserved : 05; // 0xf8;
	/*007d*/ UCHAR DirtyFlag;
	/*0080*/ ULONG HvBinHeadersUse;
	/*0084*/ ULONG HvFreeCellsUse;
	/*0088*/ ULONG HvUsedCellsUse;
	/*008c*/ ULONG CmUsedCellsUse;
	/*0090*/ ULONG HiveFlags;
	/*0094*/ ULONG CurrentLog;
	/*0098*/ ULONG CurrentLogSequence;
	/*009c*/ ULONG CurrentLogMinimumSequence;
	/*00a0*/ ULONG CurrentLogOffset;
	/*00a4*/ ULONG MinimumLogSequence;
	/*00a8*/ ULONG LogFileSizeCap;
	/*00ac*/ UCHAR LogDataPresent[0x2];
	/*00ae*/ UCHAR PrimaryFileValid;
	/*00af*/ UCHAR BaseBlockDirty;
	/*00b0*/ _LARGE_INTEGER LastLogSwapTime;
	/*00b8*/ USHORT FirstLogFile : 03; // 0x0007;
	/*00b8*/ USHORT SecondLogFile : 03; // 0x0038;
	/*00b8*/ USHORT HeaderRecovered : 01; // 0x0040;
	/*00b8*/ USHORT LegacyRecoveryIndicated : 01; // 0x0080;
	/*00b8*/ USHORT RecoveryInformationReserved : 08; // 0xff00;
	/*00b8*/ USHORT RecoveryInformation;
	/*00ba*/ UCHAR LogEntriesRecovered[0x2];
	/*00bc*/ ULONG RefreshCount;
	/*00c0*/ ULONG StorageTypeCount;
	/*00c4*/ ULONG Version;
	/*00c8*/ _HVIEW_MAP ViewMap;
	/*0578*/ _DUAL Storage[0x2];
	/*0a68*/
};

struct _HIVE_LIST_ENTRY {
	/*0000*/ WCHAR * FileName;
	/*0008*/ WCHAR * BaseName;
	/*0010*/ WCHAR * RegRootName;
	/*0018*/ _CMHIVE * CmHive;
	/*0020*/ ULONG HHiveFlags;
	/*0024*/ ULONG CmHiveFlags;
	/*0028*/ ULONG CmKcbCacheSize;
	/*0030*/ _CMHIVE * CmHive2;
	/*0038*/ UCHAR HiveMounted;
	/*0039*/ UCHAR ThreadFinished;
	/*003a*/ UCHAR ThreadStarted;
	/*003b*/ UCHAR Allocate;
	/*003c*/ UCHAR WinPERequired;
	/*0040*/ _KEVENT StartEvent;
	/*0058*/ _KEVENT FinishedEvent;
	/*0070*/ _KEVENT MountLock;
	/*0088*/ _UNICODE_STRING FilePath;
	/*0098*/
};

struct _HIVE_LOAD_FAILURE {
	/*0000*/ _HHIVE * Hive;
	/*0008*/ USHORT Index;
	/*000a*/ USHORT RecoverableIndex;
	struct {
		/*0000*/ _CM_LOAD_FAILURE_TYPE Failure;
		/*0004*/ LONG Status;
		/*0008*/ ULONG Point;
		/*000c*/
	} Locations[0x8];
	struct {
		/*0000*/ _CM_LOAD_FAILURE_TYPE Failure;
		/*0004*/ LONG Status;
		/*0008*/ ULONG Point;
		/*000c*/
	} RecoverableLocations[0x8];
	struct {
		/*00d0*/ ULONG Action;
		/*00d8*/ void * Handle;
		/*00e0*/ LONG Status;
		/*00e8*/
	} RegistryIO;
	struct {
		/*00e8*/ void * CheckStack;
		/*00f0*/
	} CheckRegistry2;
	struct {
		/*00f0*/ ULONG Cell;
		/*00f8*/ _CELL_DATA * CellPoint;
		/*0100*/ void * RootPoint;
		/*0108*/ ULONG Index;
		/*0110*/
	} CheckKey;
	struct {
		/*0110*/ _CELL_DATA * List;
		/*0118*/ ULONG Index;
		/*011c*/ ULONG Cell;
		/*0120*/ _CELL_DATA * CellPoint;
		/*0128*/
	} CheckValueList;
	struct {
		/*0128*/ ULONG Space;
		/*012c*/ ULONG MapPoint;
		/*0130*/ _HBIN * BinPoint;
		/*0138*/
	} CheckHive;
	struct {
		/*0138*/ ULONG Space;
		/*013c*/ ULONG MapPoint;
		/*0140*/ _HBIN * BinPoint;
		/*0148*/
	} CheckHive1;
	struct {
		/*0148*/ _HBIN * Bin;
		/*0150*/ _HCELL * CellPoint;
		/*0158*/
	} CheckBin;
	struct {
		/*0158*/ ULONG FileOffset;
		/*015c*/
	} RecoverData;
	/*0160*/
};

struct _HIVE_WAIT_PACKET {
	/*0000*/ _KEVENT WakeEvent;
	/*0018*/ LONG Status;
	/*0020*/ _HIVE_WAIT_PACKET * Next;
	/*0028*/
};

struct _HIVE_WRITE_WAIT_QUEUE {
	/*0000*/ _ETHREAD * ActiveThread;
	/*0008*/ _HIVE_WAIT_PACKET * WaitList;
	/*0010*/ ULONG volatile OwnerBoosted;
	/*0018*/
};

struct _HMAP_DIRECTORY {
	/*0000*/ _HMAP_TABLE * Directory[0x400];
	/*2000*/
};

struct _HMAP_ENTRY {
	/*0000*/ ULONGLONG BlockOffset;
	/*0008*/ ULONGLONG PermanentBinAddress;
	/*0010*/ ULONGLONG TemporaryBinAddress;
	/*0018*/ _EX_RUNDOWN_REF TemporaryBinRundown;
	/*0020*/ ULONG MemAlloc;
	/*0028*/
};

struct _HMAP_TABLE {
	/*0000*/ _HMAP_ENTRY Table[0x200];
	/*5000*/
};

struct _HVIEW_MAP {
	/*0000*/ ULONG MappedLength;
	/*0008*/ _EX_PUSH_LOCK Lock;
	/*0010*/ _FILE_OBJECT * FileObject;
	/*0018*/ _HVIEW_MAP_DIRECTORY * Directory;
	/*0020*/ ULONG PagesCharged;
	/*0028*/ _HVIEW_MAP_PIN_LOG PinLog;
	/*04b0*/
};

struct _HVIEW_MAP_DIRECTORY {
	/*0000*/ _HVIEW_MAP_TABLE * Tables[0x80];
	/*0400*/
};

struct _HVIEW_MAP_ENTRY {
	/*0000*/ void * ViewStart;
	/*0000*/ ULONGLONG IsPinned : 01; // 0x0000000000000001;
	/*0008*/ void * Bcb;
	/*0010*/ ULONGLONG PinnedPages;
	/*0018*/ ULONG Size;
	/*0020*/
};

struct _HVIEW_MAP_PIN_LOG {
	/*0000*/ ULONG Next;
	/*0004*/ ULONG Size;
	/*0008*/ _HVIEW_MAP_PIN_LOG_ENTRY Entries[0x10];
	/*0488*/
};

struct _HVIEW_MAP_PIN_LOG_ENTRY {
	/*0000*/ ULONG ViewOffset;
	/*0004*/ UCHAR Pinned;
	/*0008*/ ULONGLONG PinMask;
	/*0010*/ _KTHREAD * Thread;
	/*0018*/ void * Stack[0x6];
	/*0048*/
};

struct _HVIEW_MAP_TABLE {
	/*0000*/ _HVIEW_MAP_ENTRY Entries[0x40];
	/*0800*/
};

enum _HV_EXT_EPF_MODE {
	HvExtEpfModeMin = 0x0,
	HvExtEpfModeNt = 0x0,
	HvExtEpfModeMax = 0x1
};

struct _HV_GET_BIN_CONTEXT {
	/*0000*/ USHORT OutstandingReference : 01; // 0x0001;
	/*0000*/ USHORT AcquiredRundown : 01; // 0x0002;
	/*0002*/
};

struct _HV_GET_CELL_CONTEXT {
	/*0000*/ ULONG Cell;
	/*0004*/ _HV_GET_BIN_CONTEXT BinContext;
	/*0008*/
};

union _HV_PARTITION_PRIVILEGE_MASK {
	/*0000*/ ULONGLONG AsUINT64;
	/*0000*/ ULONGLONG AccessVpRunTimeReg : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG AccessPartitionReferenceCounter : 01; // 0x0000000000000002;
	/*0000*/ ULONGLONG AccessSynicRegs : 01; // 0x0000000000000004;
	/*0000*/ ULONGLONG AccessSyntheticTimerRegs : 01; // 0x0000000000000008;
	/*0000*/ ULONGLONG AccessIntrCtrlRegs : 01; // 0x0000000000000010;
	/*0000*/ ULONGLONG AccessHypercallMsrs : 01; // 0x0000000000000020;
	/*0000*/ ULONGLONG AccessVpIndex : 01; // 0x0000000000000040;
	/*0000*/ ULONGLONG AccessResetReg : 01; // 0x0000000000000080;
	/*0000*/ ULONGLONG AccessStatsReg : 01; // 0x0000000000000100;
	/*0000*/ ULONGLONG AccessPartitionReferenceTsc : 01; // 0x0000000000000200;
	/*0000*/ ULONGLONG AccessGuestIdleReg : 01; // 0x0000000000000400;
	/*0000*/ ULONGLONG AccessFrequencyRegs : 01; // 0x0000000000000800;
	/*0000*/ ULONGLONG AccessDebugRegs : 01; // 0x0000000000001000;
	/*0000*/ ULONGLONG AccessReenlightenmentControls : 01; // 0x0000000000002000;
	/*0000*/ ULONGLONG AccessRootSchedulerReg : 01; // 0x0000000000004000;
	/*0000*/ ULONGLONG Reserved1 : 17; // 0x00000000ffff8000;
	/*0000*/ ULONGLONG CreatePartitions : 01; // 0x0000000100000000;
	/*0000*/ ULONGLONG AccessPartitionId : 01; // 0x0000000200000000;
	/*0000*/ ULONGLONG AccessMemoryPool : 01; // 0x0000000400000000;
	/*0000*/ ULONGLONG AdjustMessageBuffers : 01; // 0x0000000800000000;
	/*0000*/ ULONGLONG PostMessages : 01; // 0x0000001000000000;
	/*0000*/ ULONGLONG SignalEvents : 01; // 0x0000002000000000;
	/*0000*/ ULONGLONG CreatePort : 01; // 0x0000004000000000;
	/*0000*/ ULONGLONG ConnectPort : 01; // 0x0000008000000000;
	/*0000*/ ULONGLONG AccessStats : 01; // 0x0000010000000000;
	/*0000*/ ULONGLONG Reserved2 : 02; // 0x0000060000000000;
	/*0000*/ ULONGLONG Debugging : 01; // 0x0000080000000000;
	/*0000*/ ULONGLONG CpuManagement : 01; // 0x0000100000000000;
	/*0000*/ ULONGLONG ConfigureProfiler : 01; // 0x0000200000000000;
	/*0000*/ ULONGLONG AccessVpExitTracing : 01; // 0x0000400000000000;
	/*0000*/ ULONGLONG EnableExtendedGvaRangesForFlushVirtualAddressList : 01; // 0x0000800000000000;
	/*0000*/ ULONGLONG AccessVsm : 01; // 0x0001000000000000;
	/*0000*/ ULONGLONG AccessVpRegisters : 01; // 0x0002000000000000;
	/*0000*/ ULONGLONG UnusedBit : 01; // 0x0004000000000000;
	/*0000*/ ULONGLONG FastHypercallOutput : 01; // 0x0008000000000000;
	/*0000*/ ULONGLONG EnableExtendedHypercalls : 01; // 0x0010000000000000;
	/*0000*/ ULONGLONG StartVirtualProcessor : 01; // 0x0020000000000000;
	/*0000*/ ULONGLONG Reserved3 : 10; // 0xffc0000000000000;
	/*0008*/
};

struct _HV_X64_HYPERVISOR_FEATURES {
	/*0000*/ _HV_PARTITION_PRIVILEGE_MASK PartitionPrivileges;
	/*0008*/ UINT MaxSupportedCState : 04; // 0x0000000f;
	/*0008*/ UINT HpetNeededForC3PowerState_Deprecated : 01; // 0x00000010;
	/*0008*/ UINT Reserved : 27; // 0xffffffe0;
	/*000c*/ UINT MwaitAvailable_Deprecated : 01; // 0x00000001;
	/*000c*/ UINT GuestDebuggingAvailable : 01; // 0x00000002;
	/*000c*/ UINT PerformanceMonitorsAvailable : 01; // 0x00000004;
	/*000c*/ UINT CpuDynamicPartitioningAvailable : 01; // 0x00000008;
	/*000c*/ UINT XmmRegistersForFastHypercallAvailable : 01; // 0x00000010;
	/*000c*/ UINT GuestIdleAvailable : 01; // 0x00000020;
	/*000c*/ UINT HypervisorSleepStateSupportAvailable : 01; // 0x00000040;
	/*000c*/ UINT NumaDistanceQueryAvailable : 01; // 0x00000080;
	/*000c*/ UINT FrequencyRegsAvailable : 01; // 0x00000100;
	/*000c*/ UINT SyntheticMachineCheckAvailable : 01; // 0x00000200;
	/*000c*/ UINT GuestCrashRegsAvailable : 01; // 0x00000400;
	/*000c*/ UINT DebugRegsAvailable : 01; // 0x00000800;
	/*000c*/ UINT Npiep1Available : 01; // 0x00001000;
	/*000c*/ UINT DisableHypervisorAvailable : 01; // 0x00002000;
	/*000c*/ UINT ExtendedGvaRangesForFlushVirtualAddressListAvailable : 01; // 0x00004000;
	/*000c*/ UINT FastHypercallOutputAvailable : 01; // 0x00008000;
	/*000c*/ UINT SvmFeaturesAvailable : 01; // 0x00010000;
	/*000c*/ UINT SintPollingModeAvailable : 01; // 0x00020000;
	/*000c*/ UINT HypercallMsrLockAvailable : 01; // 0x00040000;
	/*000c*/ UINT DirectSyntheticTimers : 01; // 0x00080000;
	/*000c*/ UINT RegisterPatAvailable : 01; // 0x00100000;
	/*000c*/ UINT RegisterBndcfgsAvailable : 01; // 0x00200000;
	/*000c*/ UINT WatchdogTimerAvailable : 01; // 0x00400000;
	/*000c*/ UINT SyntheticTimeUnhaltedTimerAvailable : 01; // 0x00800000;
	/*000c*/ UINT DeviceDomainsAvailable : 01; // 0x01000000;
	/*000c*/ UINT Reserved1 : 07; // 0xfe000000;
	/*0010*/
};

struct _IA64_DBGKD_CONTROL_SET {
	/*0000*/ ULONG Continue;
	/*0004*/ ULONGLONG CurrentSymbolStart;
	/*000c*/ ULONGLONG CurrentSymbolEnd;
	/*0014*/
};

struct _IMAGE_DATA_DIRECTORY {
	/*0000*/ ULONG VirtualAddress;
	/*0004*/ ULONG Size;
	/*0008*/
};

struct _IMAGE_DEBUG_DIRECTORY {
	/*0000*/ ULONG Characteristics;
	/*0004*/ ULONG TimeDateStamp;
	/*0008*/ USHORT MajorVersion;
	/*000a*/ USHORT MinorVersion;
	/*000c*/ ULONG Type;
	/*0010*/ ULONG SizeOfData;
	/*0014*/ ULONG AddressOfRawData;
	/*0018*/ ULONG PointerToRawData;
	/*001c*/
};

struct _IMAGE_DOS_HEADER {
	/*0000*/ USHORT e_magic;
	/*0002*/ USHORT e_cblp;
	/*0004*/ USHORT e_cp;
	/*0006*/ USHORT e_crlc;
	/*0008*/ USHORT e_cparhdr;
	/*000a*/ USHORT e_minalloc;
	/*000c*/ USHORT e_maxalloc;
	/*000e*/ USHORT e_ss;
	/*0010*/ USHORT e_sp;
	/*0012*/ USHORT e_csum;
	/*0014*/ USHORT e_ip;
	/*0016*/ USHORT e_cs;
	/*0018*/ USHORT e_lfarlc;
	/*001a*/ USHORT e_ovno;
	/*001c*/ USHORT e_res[0x4];
	/*0024*/ USHORT e_oemid;
	/*0026*/ USHORT e_oeminfo;
	/*0028*/ USHORT e_res2[0xa];
	/*003c*/ LONG e_lfanew;
	/*0040*/
};

struct _IMAGE_FILE_HEADER {
	/*0000*/ USHORT Machine;
	/*0002*/ USHORT NumberOfSections;
	/*0004*/ ULONG TimeDateStamp;
	/*0008*/ ULONG PointerToSymbolTable;
	/*000c*/ ULONG NumberOfSymbols;
	/*0010*/ USHORT SizeOfOptionalHeader;
	/*0012*/ USHORT Characteristics;
	/*0014*/
};

struct _IMAGE_NT_HEADERS64 {
	/*0000*/ ULONG Signature;
	/*0004*/ _IMAGE_FILE_HEADER FileHeader;
	/*0018*/ _IMAGE_OPTIONAL_HEADER64 OptionalHeader;
	/*0108*/
};

struct _IMAGE_OPTIONAL_HEADER64 {
	/*0000*/ USHORT Magic;
	/*0002*/ UCHAR MajorLinkerVersion;
	/*0003*/ UCHAR MinorLinkerVersion;
	/*0004*/ ULONG SizeOfCode;
	/*0008*/ ULONG SizeOfInitializedData;
	/*000c*/ ULONG SizeOfUninitializedData;
	/*0010*/ ULONG AddressOfEntryPoint;
	/*0014*/ ULONG BaseOfCode;
	/*0018*/ ULONGLONG ImageBase;
	/*0020*/ ULONG SectionAlignment;
	/*0024*/ ULONG FileAlignment;
	/*0028*/ USHORT MajorOperatingSystemVersion;
	/*002a*/ USHORT MinorOperatingSystemVersion;
	/*002c*/ USHORT MajorImageVersion;
	/*002e*/ USHORT MinorImageVersion;
	/*0030*/ USHORT MajorSubsystemVersion;
	/*0032*/ USHORT MinorSubsystemVersion;
	/*0034*/ ULONG Win32VersionValue;
	/*0038*/ ULONG SizeOfImage;
	/*003c*/ ULONG SizeOfHeaders;
	/*0040*/ ULONG CheckSum;
	/*0044*/ USHORT Subsystem;
	/*0046*/ USHORT DllCharacteristics;
	/*0048*/ ULONGLONG SizeOfStackReserve;
	/*0050*/ ULONGLONG SizeOfStackCommit;
	/*0058*/ ULONGLONG SizeOfHeapReserve;
	/*0060*/ ULONGLONG SizeOfHeapCommit;
	/*0068*/ ULONG LoaderFlags;
	/*006c*/ ULONG NumberOfRvaAndSizes;
	/*0070*/ _IMAGE_DATA_DIRECTORY DataDirectory[0x10];
	/*00f0*/
};

struct _IMAGE_ROM_OPTIONAL_HEADER {
	/*0000*/ USHORT Magic;
	/*0002*/ UCHAR MajorLinkerVersion;
	/*0003*/ UCHAR MinorLinkerVersion;
	/*0004*/ ULONG SizeOfCode;
	/*0008*/ ULONG SizeOfInitializedData;
	/*000c*/ ULONG SizeOfUninitializedData;
	/*0010*/ ULONG AddressOfEntryPoint;
	/*0014*/ ULONG BaseOfCode;
	/*0018*/ ULONG BaseOfData;
	/*001c*/ ULONG BaseOfBss;
	/*0020*/ ULONG GprMask;
	/*0024*/ ULONG CprMask[0x4];
	/*0034*/ ULONG GpValue;
	/*0038*/
};

struct _IMAGE_RUNTIME_FUNCTION_ENTRY {
	/*0000*/ ULONG BeginAddress;
	/*0004*/ ULONG EndAddress;
	/*0008*/ ULONG UnwindInfoAddress;
	/*0008*/ ULONG UnwindData;
	/*000c*/
};

struct _IMAGE_SECTION_HEADER {
	/*0000*/ UCHAR Name[0x8];
	union {
		/*0008*/ ULONG PhysicalAddress;
		/*0008*/ ULONG VirtualSize;
		/*000c*/
	} Misc;
	/*000c*/ ULONG VirtualAddress;
	/*0010*/ ULONG SizeOfRawData;
	/*0014*/ ULONG PointerToRawData;
	/*0018*/ ULONG PointerToRelocations;
	/*001c*/ ULONG PointerToLinenumbers;
	/*0020*/ USHORT NumberOfRelocations;
	/*0022*/ USHORT NumberOfLinenumbers;
	/*0024*/ ULONG Characteristics;
	/*0028*/
};

struct _IMAGE_SECURITY_CONTEXT {
	/*0000*/ void * PageHashes;
	/*0000*/ ULONGLONG Value;
	/*0000*/ ULONGLONG SecurityBeingCreated : 02; // 0x0000000000000003;
	/*0000*/ ULONGLONG SecurityMandatory : 01; // 0x0000000000000004;
	/*0000*/ ULONGLONG PageHashPointer : 61; // 0xfffffffffffffff8;
	/*0008*/
};

struct _INITIAL_PRIVILEGE_SET {
	/*0000*/ ULONG PrivilegeCount;
	/*0004*/ ULONG Control;
	/*0008*/ _LUID_AND_ATTRIBUTES Privilege[0x3];
	/*002c*/
};

struct _INTERFACE {
	/*0000*/ USHORT Size;
	/*0002*/ USHORT Version;
	/*0008*/ void * Context;
	/*0010*/ void (* InterfaceReference)( void * );
	/*0018*/ void (* InterfaceDereference)( void * );
	/*0020*/
};

enum _INTERFACE_TYPE {
	InterfaceTypeUndefined = 0xffffffff,
	Internal = 0x0,
	Isa = 0x1,
	Eisa = 0x2,
	MicroChannel = 0x3,
	TurboChannel = 0x4,
	PCIBus = 0x5,
	VMEBus = 0x6,
	NuBus = 0x7,
	PCMCIABus = 0x8,
	CBus = 0x9,
	MPIBus = 0xa,
	MPSABus = 0xb,
	ProcessorInternal = 0xc,
	InternalPowerBus = 0xd,
	PNPISABus = 0xe,
	PNPBus = 0xf,
	Vmcs = 0x10,
	ACPIBus = 0x11,
	MaximumInterfaceType = 0x12
};

enum _INTERLOCKED_RESULT {
	ResultNegative = 0x1,
	ResultZero = 0x0,
	ResultPositive = 0x2
};

struct _INTERRUPT_CONNECTION_DATA {
	/*0000*/ ULONG Count;
	/*0008*/ _INTERRUPT_VECTOR_DATA Vectors[0x1];
	/*0060*/
};

struct _INTERRUPT_HT_INTR_INFO {
	union {
		struct {
			/*0000*/ ULONG Mask : 01; // 0x00000001;
			/*0000*/ ULONG Polarity : 01; // 0x00000002;
			/*0000*/ ULONG MessageType : 03; // 0x0000001c;
			/*0000*/ ULONG RequestEOI : 01; // 0x00000020;
			/*0000*/ ULONG DestinationMode : 01; // 0x00000040;
			/*0000*/ ULONG MessageType3 : 01; // 0x00000080;
			/*0000*/ ULONG Destination : 08; // 0x0000ff00;
			/*0000*/ ULONG Vector : 08; // 0x00ff0000;
			/*0000*/ ULONG ExtendedAddress : 08; // 0xff000000;
			/*0004*/
		} bits;
		/*0000*/ ULONG AsULONG;
		/*0004*/
	} LowPart;
	union {
		struct {
			/*0004*/ ULONG ExtendedDestination : 24; // 0x00ffffff;
			/*0004*/ ULONG Reserved : 06; // 0x3f000000;
			/*0004*/ ULONG PassPW : 01; // 0x40000000;
			/*0004*/ ULONG WaitingForEOI : 01; // 0x80000000;
			/*0008*/
		} bits;
		/*0004*/ ULONG AsULONG;
		/*0008*/
	} HighPart;
	/*0008*/
};

struct _INTERRUPT_REMAPPING_INFO {
	/*0000*/ ULONG IrtIndex : 30; // 0x3fffffff;
	/*0000*/ ULONG FlagHalInternal : 01; // 0x40000000;
	/*0000*/ ULONG FlagTranslated : 01; // 0x80000000;
	union {
		struct {
			/*0004*/ ULONG MessageAddressHigh;
			/*0008*/ ULONG MessageAddressLow;
			/*000c*/ USHORT MessageData;
			/*000e*/ USHORT Reserved;
			/*0010*/
		} Msi;
		/*0010*/
	} u;
	/*0010*/
};

struct _INTERRUPT_VECTOR_DATA {
	/*0000*/ INTERRUPT_CONNECTION_TYPE Type;
	/*0004*/ ULONG Vector;
	/*0008*/ UCHAR Irql;
	/*000c*/ _KINTERRUPT_POLARITY Polarity;
	/*0010*/ _KINTERRUPT_MODE Mode;
	/*0018*/ _GROUP_AFFINITY TargetProcessors;
	/*0028*/ _INTERRUPT_REMAPPING_INFO IntRemapInfo;
	struct {
		/*0038*/ ULONG Gsiv;
		/*003c*/ ULONG WakeInterrupt : 01; // 0x00000001;
		/*003c*/ ULONG ReservedFlags : 31; // 0xfffffffe;
		/*0040*/
	} ControllerInput;
	/*0040*/ ULONGLONG HvDeviceId;
	struct {
		/*0048*/ _LARGE_INTEGER Address;
		/*0050*/ ULONG DataPayload;
		/*0058*/
	} XapicMessage;
	struct {
		/*0048*/ _INTERRUPT_HT_INTR_INFO IntrInfo;
		/*0050*/
	} Hypertransport;
	struct {
		/*0048*/ _LARGE_INTEGER Address;
		/*0050*/ ULONG DataPayload;
		/*0058*/
	} GenericMessage;
	struct {
		/*0048*/ HAL_APIC_DESTINATION_MODE DestinationMode;
		/*004c*/
	} MessageRequest;
	/*0058*/
};

struct _INVERTED_FUNCTION_TABLE {
	/*0000*/ ULONG CurrentSize;
	/*0004*/ ULONG MaximumSize;
	/*0008*/ ULONG volatile Epoch;
	/*000c*/ UCHAR Overflow;
	/*0010*/ _INVERTED_FUNCTION_TABLE_ENTRY TableEntry[0x100];
	/*1810*/
};

struct _INVERTED_FUNCTION_TABLE_ENTRY {
	/*0000*/ _IMAGE_RUNTIME_FUNCTION_ENTRY * FunctionTable;
	/*0000*/ _DYNAMIC_FUNCTION_TABLE * DynamicTable;
	/*0008*/ void * ImageBase;
	/*0010*/ ULONG SizeOfImage;
	/*0014*/ ULONG SizeOfTable;
	/*0018*/
};

struct _IOP_FILE_OBJECT_EXTENSION {
	/*0000*/ ULONG FoExtFlags;
	/*0008*/ void * FoExtPerTypeExtension[0x9];
	/*0050*/ _IOP_PRIORITY_HINT FoIoPriorityHint;
	/*0058*/
};

struct _IOP_IRP_EXTENSION {
	/*0000*/ USHORT ExtensionFlags;
	/*0000*/ USHORT Allocated : 01; // 0x0001;
	/*0000*/ USHORT PropagateId : 01; // 0x0002;
	/*0000*/ USHORT SpareBits : 14; // 0xfffc;
	/*0002*/ USHORT TypesAllocated;
	/*0004*/ UCHAR GenericExtension[0x4];
	/*0008*/ void * VerifierContext;
	/*0010*/ ULONGLONG DiskIoAttributionHandle;
	/*0018*/ _GUID ActivityId;
	/*0028*/ _LARGE_INTEGER Timestamp;
	/*0028*/ ULONG ZeroingOffset;
	/*0028*/ _IO_IRP_EXT_TRACK_OFFSET_HEADER * FsTrackOffsetBlob;
	/*0030*/ LONGLONG FsTrackedOffset;
	/*0028*/ _IO_ADAPTER_CRYPTO_PARAMETERS AdapterCryptoParameters;
	/*0038*/
};

struct _IOP_IRP_EXTENSION_STATUS {
	/*0000*/ ULONG Flags;
	/*0004*/ ULONG ActivityId;
	/*0008*/ ULONG IoTracking;
	/*000c*/
};

struct _IOP_IRP_STACK_PROFILER {
	/*0000*/ ULONG Profile[0x14];
	/*0050*/ ULONG TotalIrps;
	/*0054*/
};

enum _IOP_PRIORITY_HINT {
	IopIoPriorityNotSet = 0x0,
	IopIoPriorityVeryLow = 0x1,
	IopIoPriorityLow = 0x2,
	IopIoPriorityNormal = 0x3,
	IopIoPriorityHigh = 0x4,
	IopIoPriorityCritical = 0x5,
	MaxIopIoPriorityTypes = 0x6
};

struct _IOV_FORCED_PENDING_TRACE {
	/*0000*/ _IRP * Irp;
	/*0008*/ _ETHREAD * Thread;
	/*0010*/ void * StackTrace[0x3e];
	/*0200*/
};

struct _IOV_IRP_TRACE {
	/*0000*/ _IRP * Irp;
	/*0008*/ _KTHREAD * Thread;
	/*0010*/ SHORT KernelApcDisable;
	/*0012*/ SHORT SpecialApcDisable;
	/*0010*/ ULONG CombinedApcDisable;
	/*0014*/ UCHAR Irql;
	/*0018*/ void * StackTrace[0xd];
	/*0080*/
};

struct _IO_ADAPTER_CRYPTO_KEY_DESCRIPTOR {
	/*0000*/ ULONG Version;
	/*0004*/ ULONG Size;
	/*0008*/ ULONG CryptoIndex;
	/*000c*/ ULONG AlgorithmId;
	/*0010*/ ULONG DataUnitSize;
	/*0014*/ ULONG KeySize;
	/*0018*/ UCHAR KeyHash[0x20];
	/*0038*/ void * KeyVirtualAddress;
	/*0040*/ _LARGE_INTEGER KeyPhysicalAddress;
	/*0048*/
};

struct _IO_ADAPTER_CRYPTO_PARAMETERS {
	/*0000*/ ULONGLONG Tweak;
	/*0008*/ _IO_ADAPTER_CRYPTO_KEY_DESCRIPTOR * KeyDescriptor;
	/*0010*/
};

enum _IO_ALLOCATION_ACTION {
	KeepObject = 0x1,
	DeallocateObject = 0x2,
	DeallocateObjectKeepRegisters = 0x3
};

struct _IO_CLIENT_EXTENSION {
	/*0000*/ _IO_CLIENT_EXTENSION * NextExtension;
	/*0008*/ void * ClientIdentificationAddress;
	/*0010*/
};

struct _IO_COMPLETION_CONTEXT {
	/*0000*/ void * Port;
	/*0008*/ void * Key;
	/*0010*/
};

struct _IO_DRIVER_CREATE_CONTEXT {
	/*0000*/ SHORT Size;
	/*0008*/ _ECP_LIST * ExtraCreateParameter;
	/*0010*/ void * DeviceObjectHint;
	/*0018*/ _TXN_PARAMETER_BLOCK * TxnParameters;
	/*0020*/ _EJOB * SiloContext;
	/*0028*/
};

struct _IO_IRP_EXT_TRACK_OFFSET_HEADER {
	/*0000*/ USHORT Validation;
	/*0002*/ USHORT Flags;
	/*0008*/ void (* TrackedOffsetCallback)( _IO_IRP_EXT_TRACK_OFFSET_HEADER * , _IO_IRP_EXT_TRACK_OFFSET_HEADER * , LONGLONG );
	/*0010*/
};

struct _IO_MINI_COMPLETION_PACKET_USER {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ ULONG PacketType;
	/*0018*/ void * KeyContext;
	/*0020*/ void * ApcContext;
	/*0028*/ LONG IoStatus;
	/*0030*/ ULONGLONG IoStatusInformation;
	/*0038*/ void (* MiniPacketCallback)( _IO_MINI_COMPLETION_PACKET_USER * , void * );
	/*0040*/ void * Context;
	/*0048*/ UCHAR Allocated;
	/*0050*/
};

enum _IO_PRIORITY_HINT {
	IoPriorityVeryLow = 0x0,
	IoPriorityLow = 0x1,
	IoPriorityNormal = 0x2,
	IoPriorityHigh = 0x3,
	IoPriorityCritical = 0x4,
	MaxIoPriorityTypes = 0x5
};

struct _IO_PRIORITY_INFO {
	/*0000*/ ULONG Size;
	/*0004*/ ULONG ThreadPriority;
	/*0008*/ ULONG PagePriority;
	/*000c*/ _IO_PRIORITY_HINT IoPriority;
	/*0010*/
};

enum _IO_RATE_CONTROL_TYPE {
	IoRateControlTypeCapMin = 0x0,
	IoRateControlTypeIopsCap = 0x0,
	IoRateControlTypeBandwidthCap = 0x1,
	IoRateControlTypeTimePercentCap = 0x2,
	IoRateControlTypeCapMax = 0x2,
	IoRateControlTypeReservationMin = 0x3,
	IoRateControlTypeIopsReservation = 0x3,
	IoRateControlTypeBandwidthReservation = 0x4,
	IoRateControlTypeTimePercentReservation = 0x5,
	IoRateControlTypeReservationMax = 0x5,
	IoRateControlTypeCriticalReservationMin = 0x6,
	IoRateControlTypeIopsCriticalReservation = 0x6,
	IoRateControlTypeBandwidthCriticalReservation = 0x7,
	IoRateControlTypeTimePercentCriticalReservation = 0x8,
	IoRateControlTypeCriticalReservationMax = 0x8,
	IoRateControlTypeSoftCapMin = 0x9,
	IoRateControlTypeIopsSoftCap = 0x9,
	IoRateControlTypeBandwidthSoftCap = 0xa,
	IoRateControlTypeTimePercentSoftCap = 0xb,
	IoRateControlTypeSoftCapMax = 0xb,
	IoRateControlTypeLimitExcessNotifyMin = 0xc,
	IoRateControlTypeIopsLimitExcessNotify = 0xc,
	IoRateControlTypeBandwidthLimitExcessNotify = 0xd,
	IoRateControlTypeTimePercentLimitExcessNotify = 0xe,
	IoRateControlTypeLimitExcessNotifyMax = 0xe,
	IoRateControlTypeMax = 0xf
};

struct _IO_REMOVE_LOCK {
	/*0000*/ _IO_REMOVE_LOCK_COMMON_BLOCK Common;
	/*0020*/
};

struct _IO_REMOVE_LOCK_COMMON_BLOCK {
	/*0000*/ UCHAR Removed;
	/*0001*/ UCHAR Reserved[0x3];
	/*0004*/ LONG IoCount;
	/*0008*/ _KEVENT RemoveEvent;
	/*0020*/
};

struct _IO_RESOURCE_DESCRIPTOR {
	/*0000*/ UCHAR Option;
	/*0001*/ UCHAR Type;
	/*0002*/ UCHAR ShareDisposition;
	/*0003*/ UCHAR Spare1;
	/*0004*/ USHORT Flags;
	/*0006*/ USHORT Spare2;
	union {
		struct {
			/*0008*/ ULONG Length;
			/*000c*/ ULONG Alignment;
			/*0010*/ _LARGE_INTEGER MinimumAddress;
			/*0018*/ _LARGE_INTEGER MaximumAddress;
			/*0020*/
		} Port;
		struct {
			/*0008*/ ULONG Length;
			/*000c*/ ULONG Alignment;
			/*0010*/ _LARGE_INTEGER MinimumAddress;
			/*0018*/ _LARGE_INTEGER MaximumAddress;
			/*0020*/
		} Memory;
		struct {
			/*0008*/ ULONG MinimumVector;
			/*000c*/ ULONG MaximumVector;
			/*0010*/ USHORT AffinityPolicy;
			/*0012*/ USHORT Group;
			/*0014*/ _IRQ_PRIORITY PriorityPolicy;
			/*0018*/ ULONGLONG TargetedProcessors;
			/*0020*/
		} Interrupt;
		struct {
			/*0008*/ ULONG MinimumChannel;
			/*000c*/ ULONG MaximumChannel;
			/*0010*/
		} Dma;
		struct {
			/*0008*/ ULONG RequestLine;
			/*000c*/ ULONG Reserved;
			/*0010*/ ULONG Channel;
			/*0014*/ ULONG TransferWidth;
			/*0018*/
		} DmaV3;
		struct {
			/*0008*/ ULONG Length;
			/*000c*/ ULONG Alignment;
			/*0010*/ _LARGE_INTEGER MinimumAddress;
			/*0018*/ _LARGE_INTEGER MaximumAddress;
			/*0020*/
		} Generic;
		struct {
			/*0008*/ ULONG Data[0x3];
			/*0014*/
		} DevicePrivate;
		struct {
			/*0008*/ ULONG Length;
			/*000c*/ ULONG MinBusNumber;
			/*0010*/ ULONG MaxBusNumber;
			/*0014*/ ULONG Reserved;
			/*0018*/
		} BusNumber;
		struct {
			/*0008*/ ULONG Priority;
			/*000c*/ ULONG Reserved1;
			/*0010*/ ULONG Reserved2;
			/*0014*/
		} ConfigData;
		struct {
			/*0008*/ ULONG Length40;
			/*000c*/ ULONG Alignment40;
			/*0010*/ _LARGE_INTEGER MinimumAddress;
			/*0018*/ _LARGE_INTEGER MaximumAddress;
			/*0020*/
		} Memory40;
		struct {
			/*0008*/ ULONG Length48;
			/*000c*/ ULONG Alignment48;
			/*0010*/ _LARGE_INTEGER MinimumAddress;
			/*0018*/ _LARGE_INTEGER MaximumAddress;
			/*0020*/
		} Memory48;
		struct {
			/*0008*/ ULONG Length64;
			/*000c*/ ULONG Alignment64;
			/*0010*/ _LARGE_INTEGER MinimumAddress;
			/*0018*/ _LARGE_INTEGER MaximumAddress;
			/*0020*/
		} Memory64;
		struct {
			/*0008*/ UCHAR Class;
			/*0009*/ UCHAR Type;
			/*000a*/ UCHAR Reserved1;
			/*000b*/ UCHAR Reserved2;
			/*000c*/ ULONG IdLowPart;
			/*0010*/ ULONG IdHighPart;
			/*0014*/
		} Connection;
		/*0020*/
	} u;
	/*0020*/
};

struct _IO_RESOURCE_LIST {
	/*0000*/ USHORT Version;
	/*0002*/ USHORT Revision;
	/*0004*/ ULONG Count;
	/*0008*/ _IO_RESOURCE_DESCRIPTOR Descriptors[0x1];
	/*0028*/
};

struct _IO_RESOURCE_REQUIREMENTS_LIST {
	/*0000*/ ULONG ListSize;
	/*0004*/ _INTERFACE_TYPE InterfaceType;
	/*0008*/ ULONG BusNumber;
	/*000c*/ ULONG SlotNumber;
	/*0010*/ ULONG Reserved[0x3];
	/*001c*/ ULONG AlternativeLists;
	/*0020*/ _IO_RESOURCE_LIST List[0x1];
	/*0048*/
};

struct _IO_SECURITY_CONTEXT {
	/*0000*/ _SECURITY_QUALITY_OF_SERVICE * SecurityQos;
	/*0008*/ _ACCESS_STATE * AccessState;
	/*0010*/ ULONG DesiredAccess;
	/*0014*/ ULONG FullCreateOptions;
	/*0018*/
};

enum _IO_SESSION_STATE {
	IoSessionStateCreated = 0x1,
	IoSessionStateInitialized = 0x2,
	IoSessionStateConnected = 0x3,
	IoSessionStateDisconnected = 0x4,
	IoSessionStateDisconnectedLoggedOn = 0x5,
	IoSessionStateLoggedOn = 0x6,
	IoSessionStateLoggedOff = 0x7,
	IoSessionStateTerminated = 0x8,
	IoSessionStateMax = 0x9
};

struct _IO_STACK_LOCATION {
	/*0000*/ UCHAR MajorFunction;
	/*0001*/ UCHAR MinorFunction;
	/*0002*/ UCHAR Flags;
	/*0003*/ UCHAR Control;
	union {
		struct {
			/*0008*/ _IO_SECURITY_CONTEXT * SecurityContext;
			/*0010*/ ULONG Options;
			/*0018*/ USHORT FileAttributes;
			/*001a*/ USHORT ShareAccess;
			/*0020*/ ULONG EaLength;
			/*0028*/
		} Create;
		struct {
			/*0008*/ _IO_SECURITY_CONTEXT * SecurityContext;
			/*0010*/ ULONG Options;
			/*0018*/ USHORT Reserved;
			/*001a*/ USHORT ShareAccess;
			/*0020*/ _NAMED_PIPE_CREATE_PARAMETERS * Parameters;
			/*0028*/
		} CreatePipe;
		struct {
			/*0008*/ _IO_SECURITY_CONTEXT * SecurityContext;
			/*0010*/ ULONG Options;
			/*0018*/ USHORT Reserved;
			/*001a*/ USHORT ShareAccess;
			/*0020*/ _MAILSLOT_CREATE_PARAMETERS * Parameters;
			/*0028*/
		} CreateMailslot;
		struct {
			/*0008*/ ULONG Length;
			/*0010*/ ULONG Key;
			/*0018*/ _LARGE_INTEGER ByteOffset;
			/*0020*/
		} Read;
		struct {
			/*0008*/ ULONG Length;
			/*0010*/ ULONG Key;
			/*0018*/ _LARGE_INTEGER ByteOffset;
			/*0020*/
		} Write;
		struct {
			/*0008*/ ULONG Length;
			/*0010*/ _UNICODE_STRING * FileName;
			/*0018*/ _FILE_INFORMATION_CLASS FileInformationClass;
			/*0020*/ ULONG FileIndex;
			/*0028*/
		} QueryDirectory;
		struct {
			/*0008*/ ULONG Length;
			/*0010*/ ULONG CompletionFilter;
			/*0018*/
		} NotifyDirectory;
		struct {
			/*0008*/ ULONG Length;
			/*0010*/ ULONG CompletionFilter;
			/*0018*/ _DIRECTORY_NOTIFY_INFORMATION_CLASS DirectoryNotifyInformationClass;
			/*0020*/
		} NotifyDirectoryEx;
		struct {
			/*0008*/ ULONG Length;
			/*0010*/ _FILE_INFORMATION_CLASS FileInformationClass;
			/*0018*/
		} QueryFile;
		struct {
			/*0008*/ ULONG Length;
			/*0010*/ _FILE_INFORMATION_CLASS FileInformationClass;
			/*0018*/ _FILE_OBJECT * FileObject;
			/*0020*/ UCHAR ReplaceIfExists;
			/*0021*/ UCHAR AdvanceOnly;
			/*0020*/ ULONG ClusterCount;
			/*0020*/ void * DeleteHandle;
			/*0028*/
		} SetFile;
		struct {
			/*0008*/ ULONG Length;
			/*0010*/ void * EaList;
			/*0018*/ ULONG EaListLength;
			/*0020*/ ULONG EaIndex;
			/*0028*/
		} QueryEa;
		struct {
			/*0008*/ ULONG Length;
			/*000c*/
		} SetEa;
		struct {
			/*0008*/ ULONG Length;
			/*0010*/ _FSINFOCLASS FsInformationClass;
			/*0018*/
		} QueryVolume;
		struct {
			/*0008*/ ULONG Length;
			/*0010*/ _FSINFOCLASS FsInformationClass;
			/*0018*/
		} SetVolume;
		struct {
			/*0008*/ ULONG OutputBufferLength;
			/*0010*/ ULONG InputBufferLength;
			/*0018*/ ULONG FsControlCode;
			/*0020*/ void * Type3InputBuffer;
			/*0028*/
		} FileSystemControl;
		struct {
			/*0008*/ _LARGE_INTEGER * Length;
			/*0010*/ ULONG Key;
			/*0018*/ _LARGE_INTEGER ByteOffset;
			/*0020*/
		} LockControl;
		struct {
			/*0008*/ ULONG OutputBufferLength;
			/*0010*/ ULONG InputBufferLength;
			/*0018*/ ULONG IoControlCode;
			/*0020*/ void * Type3InputBuffer;
			/*0028*/
		} DeviceIoControl;
		struct {
			/*0008*/ ULONG SecurityInformation;
			/*0010*/ ULONG Length;
			/*0018*/
		} QuerySecurity;
		struct {
			/*0008*/ ULONG SecurityInformation;
			/*0010*/ void * SecurityDescriptor;
			/*0018*/
		} SetSecurity;
		struct {
			/*0008*/ _VPB * Vpb;
			/*0010*/ _DEVICE_OBJECT * DeviceObject;
			/*0018*/
		} MountVolume;
		struct {
			/*0008*/ _VPB * Vpb;
			/*0010*/ _DEVICE_OBJECT * DeviceObject;
			/*0018*/
		} VerifyVolume;
		struct {
			/*0008*/ _SCSI_REQUEST_BLOCK * Srb;
			/*0010*/
		} Scsi;
		struct {
			/*0008*/ ULONG Length;
			/*0010*/ void * StartSid;
			/*0018*/ _FILE_GET_QUOTA_INFORMATION * SidList;
			/*0020*/ ULONG SidListLength;
			/*0028*/
		} QueryQuota;
		struct {
			/*0008*/ ULONG Length;
			/*000c*/
		} SetQuota;
		struct {
			/*0008*/ _DEVICE_RELATION_TYPE Type;
			/*000c*/
		} QueryDeviceRelations;
		struct {
			/*0008*/ _GUID const * InterfaceType;
			/*0010*/ USHORT Size;
			/*0012*/ USHORT Version;
			/*0018*/ _INTERFACE * Interface;
			/*0020*/ void * InterfaceSpecificData;
			/*0028*/
		} QueryInterface;
		struct {
			/*0008*/ _DEVICE_CAPABILITIES * Capabilities;
			/*0010*/
		} DeviceCapabilities;
		struct {
			/*0008*/ _IO_RESOURCE_REQUIREMENTS_LIST * IoResourceRequirementList;
			/*0010*/
		} FilterResourceRequirements;
		struct {
			/*0008*/ ULONG WhichSpace;
			/*0010*/ void * Buffer;
			/*0018*/ ULONG Offset;
			/*0020*/ ULONG Length;
			/*0028*/
		} ReadWriteConfig;
		struct {
			/*0008*/ UCHAR Lock;
			/*0009*/
		} SetLock;
		struct {
			/*0008*/ BUS_QUERY_ID_TYPE IdType;
			/*000c*/
		} QueryId;
		struct {
			/*0008*/ DEVICE_TEXT_TYPE DeviceTextType;
			/*0010*/ ULONG LocaleId;
			/*0018*/
		} QueryDeviceText;
		struct {
			/*0008*/ UCHAR InPath;
			/*0009*/ UCHAR Reserved[0x3];
			/*0010*/ _DEVICE_USAGE_NOTIFICATION_TYPE Type;
			/*0018*/
		} UsageNotification;
		struct {
			/*0008*/ _SYSTEM_POWER_STATE PowerState;
			/*000c*/
		} WaitWake;
		struct {
			/*0008*/ _POWER_SEQUENCE * PowerSequence;
			/*0010*/
		} PowerSequence;
		struct {
			/*0008*/ ULONG SystemContext;
			/*0008*/ _SYSTEM_POWER_STATE_CONTEXT SystemPowerStateContext;
			/*0010*/ _POWER_STATE_TYPE Type;
			/*0018*/ _POWER_STATE State;
			/*0020*/ POWER_ACTION ShutdownType;
			/*0028*/
		} Power;
		struct {
			/*0008*/ _CM_RESOURCE_LIST * AllocatedResources;
			/*0010*/ _CM_RESOURCE_LIST * AllocatedResourcesTranslated;
			/*0018*/
		} StartDevice;
		struct {
			/*0008*/ ULONGLONG ProviderId;
			/*0010*/ void * DataPath;
			/*0018*/ ULONG BufferSize;
			/*0020*/ void * Buffer;
			/*0028*/
		} WMI;
		struct {
			/*0008*/ void * Argument1;
			/*0010*/ void * Argument2;
			/*0018*/ void * Argument3;
			/*0020*/ void * Argument4;
			/*0028*/
		} Others;
		/*0028*/
	} Parameters;
	/*0028*/ _DEVICE_OBJECT * DeviceObject;
	/*0030*/ _FILE_OBJECT * FileObject;
	/*0038*/ LONG (* CompletionRoutine)( _DEVICE_OBJECT * , _IRP * , void * );
	/*0040*/ void * Context;
	/*0048*/
};

struct _IO_STATUS_BLOCK {
	/*0000*/ LONG Status;
	/*0000*/ void * Pointer;
	/*0008*/ ULONGLONG Information;
	/*0010*/
};

struct _IO_TIMER {
	/*0000*/ SHORT Type;
	/*0002*/ SHORT TimerFlag;
	/*0008*/ _LIST_ENTRY TimerList;
	/*0018*/ void (* TimerRoutine)( _DEVICE_OBJECT * , void * );
	/*0020*/ void * Context;
	/*0028*/ _DEVICE_OBJECT * DeviceObject;
	/*0030*/
};

struct _IO_WORKITEM {
	/*0000*/ _WORK_QUEUE_ITEM WorkItem;
	/*0020*/ void (* Routine)( void * , void * , _IO_WORKITEM * );
	/*0028*/ void * IoObject;
	/*0030*/ void * Context;
	/*0038*/ _ETHREAD * WorkOnBehalfThread;
	/*0040*/ ULONG Type;
	/*0044*/ _GUID ActivityId;
	/*0058*/
};

struct _IRP {
	/*0000*/ SHORT Type;
	/*0002*/ USHORT Size;
	/*0004*/ USHORT AllocationProcessorNumber;
	/*0006*/ USHORT Reserved;
	/*0008*/ _MDL * MdlAddress;
	/*0010*/ ULONG Flags;
	union {
		/*0018*/ _IRP * MasterIrp;
		/*0018*/ LONG IrpCount;
		/*0018*/ void * SystemBuffer;
		/*0020*/
	} AssociatedIrp;
	/*0020*/ _LIST_ENTRY ThreadListEntry;
	/*0030*/ _IO_STATUS_BLOCK IoStatus;
	/*0040*/ CHAR RequestorMode;
	/*0041*/ UCHAR PendingReturned;
	/*0042*/ CHAR StackCount;
	/*0043*/ CHAR CurrentLocation;
	/*0044*/ UCHAR Cancel;
	/*0045*/ UCHAR CancelIrql;
	/*0046*/ CHAR ApcEnvironment;
	/*0047*/ UCHAR AllocationFlags;
	/*0048*/ _IO_STATUS_BLOCK * UserIosb;
	/*0050*/ _KEVENT * UserEvent;
	union {
		struct {
			/*0058*/ void (* UserApcRoutine)( void * , _IO_STATUS_BLOCK * , ULONG );
			/*0058*/ void * IssuingProcess;
			/*0060*/ void * UserApcContext;
			/*0068*/
		} AsynchronousParameters;
		/*0058*/ _LARGE_INTEGER AllocationSize;
		/*0068*/
	} Overlay;
	/*0068*/ void (* CancelRoutine)( _DEVICE_OBJECT * , _IRP * );
	/*0070*/ void * UserBuffer;
	union {
		struct {
			/*0078*/ _KDEVICE_QUEUE_ENTRY DeviceQueueEntry;
			/*0078*/ void * DriverContext[0x4];
			/*0098*/ _ETHREAD * Thread;
			/*00a0*/ CHAR * AuxiliaryBuffer;
			/*00a8*/ _LIST_ENTRY ListEntry;
			/*00b8*/ _IO_STACK_LOCATION * CurrentStackLocation;
			/*00b8*/ ULONG PacketType;
			/*00c0*/ _FILE_OBJECT * OriginalFileObject;
			/*00c8*/ void * IrpExtension;
			/*00d0*/
		} Overlay;
		/*0078*/ _KAPC Apc;
		/*0078*/ void * CompletionKey;
		/*00d0*/
	} Tail;
	/*00d0*/
};

enum _IRQ_PRIORITY {
	IrqPriorityUndefined = 0x0,
	IrqPriorityLow = 0x1,
	IrqPriorityNormal = 0x2,
	IrqPriorityHigh = 0x3
};

struct _ISRDPCSTATS {
	/*0000*/ ULONGLONG IsrTime;
	/*0008*/ ULONGLONG IsrTimeStart;
	/*0010*/ ULONGLONG IsrCount;
	/*0018*/ ULONGLONG DpcTime;
	/*0020*/ ULONGLONG DpcTimeStart;
	/*0028*/ ULONGLONG DpcCount;
	/*0030*/ UCHAR IsrActive;
	/*0031*/ UCHAR Reserved[0xf];
	/*0040*/
};

struct _ISR_THUNK {
	/*0000*/ UCHAR PushImm;
	/*0001*/ UCHAR Vector;
	/*0002*/ UCHAR PushRbp;
	/*0003*/ UCHAR JmpOp;
	/*0004*/ LONG JmpOffset;
	/*0008*/
};

enum _JOBOBJECTINFOCLASS {
	JobObjectBasicAccountingInformation = 0x1,
	JobObjectBasicLimitInformation = 0x2,
	JobObjectBasicProcessIdList = 0x3,
	JobObjectBasicUIRestrictions = 0x4,
	JobObjectSecurityLimitInformation = 0x5,
	JobObjectEndOfJobTimeInformation = 0x6,
	JobObjectAssociateCompletionPortInformation = 0x7,
	JobObjectBasicAndIoAccountingInformation = 0x8,
	JobObjectExtendedLimitInformation = 0x9,
	JobObjectJobSetInformation = 0xa,
	JobObjectGroupInformation = 0xb,
	JobObjectNotificationLimitInformation = 0xc,
	JobObjectLimitViolationInformation = 0xd,
	JobObjectGroupInformationEx = 0xe,
	JobObjectCpuRateControlInformation = 0xf,
	JobObjectCompletionFilter = 0x10,
	JobObjectCompletionCounter = 0x11,
	JobObjectFreezeInformation = 0x12,
	JobObjectExtendedAccountingInformation = 0x13,
	JobObjectWakeInformation = 0x14,
	JobObjectBackgroundInformation = 0x15,
	JobObjectSchedulingRankBiasInformation = 0x16,
	JobObjectTimerVirtualizationInformation = 0x17,
	JobObjectCycleTimeNotification = 0x18,
	JobObjectClearEvent = 0x19,
	JobObjectInterferenceInformation = 0x1a,
	JobObjectClearPeakJobMemoryUsed = 0x1b,
	JobObjectMemoryUsageInformation = 0x1c,
	JobObjectSharedCommit = 0x1d,
	JobObjectContainerId = 0x1e,
	JobObjectIoRateControlInformation = 0x1f,
	JobObjectSiloRootDirectory = 0x25,
	JobObjectServerSiloBasicInformation = 0x26,
	JobObjectServerSiloUserSharedData = 0x27,
	JobObjectServerSiloInitialize = 0x28,
	JobObjectServerSiloRunningState = 0x29,
	JobObjectIoAttribution = 0x2a,
	JobObjectMemoryPartitionInformation = 0x2b,
	JobObjectContainerTelemetryId = 0x2c,
	JobObjectSiloSystemRoot = 0x2d,
	JobObjectEnergyTrackingState = 0x2e,
	JobObjectThreadImpersonationInformation = 0x2f,
	JobObjectReserved1Information = 0x12,
	JobObjectReserved2Information = 0x13,
	JobObjectReserved3Information = 0x14,
	JobObjectReserved4Information = 0x15,
	JobObjectReserved5Information = 0x16,
	JobObjectReserved6Information = 0x17,
	JobObjectReserved7Information = 0x18,
	JobObjectReserved8Information = 0x19,
	JobObjectReserved9Information = 0x1a,
	JobObjectReserved10Information = 0x1b,
	JobObjectReserved11Information = 0x1c,
	JobObjectReserved12Information = 0x1d,
	JobObjectReserved13Information = 0x1e,
	JobObjectReserved14Information = 0x1f,
	JobObjectNetRateControlInformation = 0x20,
	JobObjectNotificationLimitInformation2 = 0x21,
	JobObjectLimitViolationInformation2 = 0x22,
	JobObjectCreateSilo = 0x23,
	JobObjectSiloBasicInformation = 0x24,
	JobObjectReserved15Information = 0x25,
	JobObjectReserved16Information = 0x26,
	JobObjectReserved17Information = 0x27,
	JobObjectReserved18Information = 0x28,
	JobObjectReserved19Information = 0x29,
	JobObjectReserved20Information = 0x2a,
	JobObjectReserved21Information = 0x2b,
	JobObjectReserved22Information = 0x2c,
	JobObjectReserved23Information = 0x2d,
	JobObjectReserved24Information = 0x2e,
	JobObjectReserved25Information = 0x2f,
	MaxJobObjectInfoClass = 0x30
};

union _JOBOBJECT_ENERGY_TRACKING_STATE {
	/*0000*/ ULONGLONG Value;
	/*0000*/ ULONG UpdateMask;
	/*0004*/ ULONG DesiredState;
	/*0008*/
};

struct _JOBOBJECT_WAKE_FILTER {
	/*0000*/ ULONG HighEdgeFilter;
	/*0004*/ ULONG LowEdgeFilter;
	/*0008*/
};

struct _JOB_ACCESS_STATE;

struct _JOB_CPU_RATE_CONTROL;

struct _JOB_NET_RATE_CONTROL;

struct _JOB_NOTIFICATION_INFORMATION;

struct _JOB_RATE_CONTROL_HEADER {
	/*0000*/ void * RateControlQuotaReference;
	/*0008*/ _RTL_BITMAP OverQuotaHistory;
	/*0018*/ UCHAR * BitMapBuffer;
	/*0020*/ ULONGLONG BitMapBufferSize;
	/*0028*/
};

struct _KAFFINITY_EX {
	/*0000*/ USHORT Count;
	/*0002*/ USHORT Size;
	/*0004*/ ULONG Reserved;
	/*0008*/ ULONGLONG Bitmap[0x14];
	/*00a8*/
};

union _KALPC_DIRECT_EVENT {
	/*0000*/ ULONGLONG Event;
	/*0000*/ ULONGLONG Referenced : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG Reserved : 63; // 0xfffffffffffffffe;
	/*0008*/
};

struct _KALPC_HANDLE_DATA {
	/*0000*/ ULONG ObjectType;
	/*0004*/ ULONG Count;
	/*0008*/ _OB_DUPLICATE_OBJECT_STATE DuplicateContext;
	/*0030*/
};

struct _KALPC_MESSAGE {
	/*0000*/ _LIST_ENTRY Entry;
	/*0010*/ _ALPC_PORT * PortQueue;
	/*0018*/ _ALPC_PORT * OwnerPort;
	/*0020*/ _ETHREAD * WaitingThread;
	union {
		struct {
			/*0028*/ ULONG QueueType : 03; // 0x00000007;
			/*0028*/ ULONG QueuePortType : 04; // 0x00000078;
			/*0028*/ ULONG Canceled : 01; // 0x00000080;
			/*0028*/ ULONG Ready : 01; // 0x00000100;
			/*0028*/ ULONG ReleaseMessage : 01; // 0x00000200;
			/*0028*/ ULONG SharedQuota : 01; // 0x00000400;
			/*0028*/ ULONG ReplyWaitReply : 01; // 0x00000800;
			/*0028*/ ULONG OwnerPortReference : 01; // 0x00001000;
			/*0028*/ ULONG ReserveReference : 01; // 0x00002000;
			/*0028*/ ULONG ReceiverReference : 01; // 0x00004000;
			/*0028*/ ULONG ViewAttributeRetrieved : 01; // 0x00008000;
			/*0028*/ ULONG InDispatch : 01; // 0x00010000;
			/*002c*/
		} s1;
		/*0028*/ ULONG State;
		/*002c*/
	} u1;
	/*002c*/ LONG SequenceNo;
	/*0030*/ _EPROCESS * QuotaProcess;
	/*0030*/ void * QuotaBlock;
	/*0038*/ _ALPC_PORT * CancelSequencePort;
	/*0040*/ _ALPC_PORT * CancelQueuePort;
	/*0048*/ LONG CancelSequenceNo;
	/*0050*/ _LIST_ENTRY CancelListEntry;
	/*0060*/ _KALPC_RESERVE * Reserve;
	/*0068*/ _KALPC_MESSAGE_ATTRIBUTES MessageAttributes;
	/*00b0*/ void * DataUserVa;
	/*00b8*/ _ALPC_COMMUNICATION_INFO * CommunicationInfo;
	/*00c0*/ _ALPC_PORT * ConnectionPort;
	/*00c8*/ _ETHREAD * ServerThread;
	/*00d0*/ void * WakeReference;
	/*00d8*/ void * WakeReference2;
	/*00e0*/ void * ExtensionBuffer;
	/*00e8*/ ULONGLONG ExtensionBufferSize;
	/*00f0*/ _PORT_MESSAGE PortMessage;
	/*0118*/
};

struct _KALPC_MESSAGE_ATTRIBUTES {
	/*0000*/ void * ClientContext;
	/*0008*/ void * ServerContext;
	/*0010*/ void * PortContext;
	/*0018*/ void * CancelPortContext;
	/*0020*/ _KALPC_SECURITY_DATA * SecurityData;
	/*0028*/ _KALPC_VIEW * View;
	/*0030*/ _KALPC_HANDLE_DATA * HandleData;
	/*0038*/ _KALPC_DIRECT_EVENT DirectEvent;
	/*0040*/ _KALPC_WORK_ON_BEHALF_DATA WorkOnBehalfData;
	/*0048*/
};

struct _KALPC_REGION {
	/*0000*/ _LIST_ENTRY RegionListEntry;
	/*0010*/ _KALPC_SECTION * Section;
	/*0018*/ ULONGLONG Offset;
	/*0020*/ ULONGLONG Size;
	/*0028*/ ULONGLONG ViewSize;
	union {
		struct {
			/*0030*/ ULONG Secure : 01; // 0x00000001;
			/*0034*/
		} s1;
		/*0034*/
	} u1;
	/*0034*/ ULONG NumberOfViews;
	/*0038*/ _LIST_ENTRY ViewListHead;
	/*0048*/ _KALPC_VIEW * ReadOnlyView;
	/*0050*/ _KALPC_VIEW * ReadWriteView;
	/*0058*/
};

struct _KALPC_RESERVE {
	/*0000*/ _ALPC_PORT * OwnerPort;
	/*0008*/ _ALPC_HANDLE_TABLE * HandleTable;
	/*0010*/ void * Handle;
	/*0018*/ _KALPC_MESSAGE * Message;
	/*0020*/ LONG Active;
	/*0028*/
};

struct _KALPC_SECTION {
	/*0000*/ void * SectionObject;
	/*0008*/ ULONGLONG Size;
	/*0010*/ _ALPC_HANDLE_TABLE * HandleTable;
	/*0018*/ void * SectionHandle;
	/*0020*/ _EPROCESS * OwnerProcess;
	/*0028*/ _ALPC_PORT * OwnerPort;
	union {
		struct {
			/*0030*/ ULONG Internal : 01; // 0x00000001;
			/*0030*/ ULONG Secure : 01; // 0x00000002;
			/*0034*/
		} s1;
		/*0034*/
	} u1;
	/*0034*/ ULONG NumberOfRegions;
	/*0038*/ _LIST_ENTRY RegionListHead;
	/*0048*/
};

struct _KALPC_SECURITY_DATA {
	/*0000*/ _ALPC_HANDLE_TABLE * HandleTable;
	/*0008*/ void * ContextHandle;
	/*0010*/ _EPROCESS * OwningProcess;
	/*0018*/ _ALPC_PORT * OwnerPort;
	/*0020*/ _SECURITY_CLIENT_CONTEXT DynamicSecurity;
	union {
		struct {
			/*0068*/ ULONG Revoked : 01; // 0x00000001;
			/*0068*/ ULONG Impersonated : 01; // 0x00000002;
			/*006c*/
		} s1;
		/*006c*/
	} u1;
	/*0070*/
};

struct _KALPC_VIEW {
	/*0000*/ _LIST_ENTRY ViewListEntry;
	/*0010*/ _KALPC_REGION * Region;
	/*0018*/ _ALPC_PORT * OwnerPort;
	/*0020*/ _EPROCESS * OwnerProcess;
	/*0028*/ void * Address;
	/*0030*/ ULONGLONG Size;
	/*0038*/ void * SecureViewHandle;
	/*0040*/ void * WriteAccessHandle;
	union {
		struct {
			/*0048*/ ULONG WriteAccess : 01; // 0x00000001;
			/*0048*/ ULONG AutoRelease : 01; // 0x00000002;
			/*0048*/ ULONG ForceUnlink : 01; // 0x00000004;
			/*0048*/ ULONG SystemSpace : 01; // 0x00000008;
			/*004c*/
		} s1;
		/*004c*/
	} u1;
	/*004c*/ ULONG NumberOfOwnerMessages;
	/*0050*/ _LIST_ENTRY ProcessViewListEntry;
	/*0060*/
};

struct _KALPC_WORK_ON_BEHALF_DATA {
	/*0000*/ _ALPC_WORK_ON_BEHALF_TICKET Ticket;
	/*0008*/
};

struct _KAPC {
	/*0000*/ UCHAR Type;
	/*0001*/ UCHAR SpareByte0;
	/*0002*/ UCHAR Size;
	/*0003*/ UCHAR SpareByte1;
	/*0004*/ ULONG SpareLong0;
	/*0008*/ _KTHREAD * Thread;
	/*0010*/ _LIST_ENTRY ApcListEntry;
	/*0020*/ void (* KernelRoutine)( _KAPC * , void (* * )( void * , void * , void * ), void * * , void * * , void * * );
	/*0028*/ void (* RundownRoutine)( _KAPC * );
	/*0030*/ void (* NormalRoutine)( void * , void * , void * );
	/*0020*/ void * Reserved[0x3];
	/*0038*/ void * NormalContext;
	/*0040*/ void * SystemArgument1;
	/*0048*/ void * SystemArgument2;
	/*0050*/ CHAR ApcStateIndex;
	/*0051*/ CHAR ApcMode;
	/*0052*/ UCHAR Inserted;
	/*0058*/
};

struct _KAPC_STATE {
	/*0000*/ _LIST_ENTRY ApcListHead[0x2];
	/*0020*/ _KPROCESS * Process;
	/*0028*/ UCHAR InProgressFlags;
	/*0028*/ UCHAR KernelApcInProgress : 01; // 0x01;
	/*0028*/ UCHAR SpecialApcInProgress : 01; // 0x02;
	/*0029*/ UCHAR KernelApcPending;
	/*002a*/ UCHAR UserApcPending;
	/*0030*/
};

struct _KDESCRIPTOR {
	/*0000*/ USHORT Pad[0x3];
	/*0006*/ USHORT Limit;
	/*0008*/ void * Base;
	/*0010*/
};

struct _KDEVICE_QUEUE {
	/*0000*/ SHORT Type;
	/*0002*/ SHORT Size;
	/*0008*/ _LIST_ENTRY DeviceListHead;
	/*0018*/ ULONGLONG Lock;
	/*0020*/ UCHAR Busy;
	/*0020*/ LONGLONG Reserved : 08; // 0x00000000000000ff;
	/*0020*/ LONGLONG Hint : 56; // 0xffffffffffffff00;
	/*0028*/
};

struct _KDEVICE_QUEUE_ENTRY {
	/*0000*/ _LIST_ENTRY DeviceListEntry;
	/*0010*/ ULONG SortKey;
	/*0014*/ UCHAR Inserted;
	/*0018*/
};

struct _KDPC {
	/*0000*/ ULONG TargetInfoAsUlong;
	/*0000*/ UCHAR Type;
	/*0001*/ UCHAR Importance;
	/*0002*/ USHORT volatile Number;
	/*0008*/ _SINGLE_LIST_ENTRY DpcListEntry;
	/*0010*/ ULONGLONG ProcessorHistory;
	/*0018*/ void (* DeferredRoutine)( _KDPC * , void * , void * , void * );
	/*0020*/ void * DeferredContext;
	/*0028*/ void * SystemArgument1;
	/*0030*/ void * SystemArgument2;
	/*0038*/ void * DpcData;
	/*0040*/
};

struct _KDPC_DATA {
	/*0000*/ _KDPC_LIST DpcList;
	/*0010*/ ULONGLONG DpcLock;
	/*0018*/ LONG volatile DpcQueueDepth;
	/*001c*/ ULONG DpcCount;
	/*0020*/ _KDPC * volatile ActiveDpc;
	/*0028*/
};

struct _KDPC_LIST {
	/*0000*/ _SINGLE_LIST_ENTRY ListHead;
	/*0008*/ _SINGLE_LIST_ENTRY * LastEntry;
	/*0010*/
};

struct _KENLISTMENT {
	/*0000*/ ULONG cookie;
	/*0008*/ _KTMOBJECT_NAMESPACE_LINK NamespaceLink;
	/*0030*/ _GUID EnlistmentId;
	/*0040*/ _KMUTANT Mutex;
	/*0078*/ _LIST_ENTRY NextSameTx;
	/*0088*/ _LIST_ENTRY NextSameRm;
	/*0098*/ _KRESOURCEMANAGER * ResourceManager;
	/*00a0*/ _KTRANSACTION * Transaction;
	/*00a8*/ _KENLISTMENT_STATE State;
	/*00ac*/ ULONG Flags;
	/*00b0*/ ULONG NotificationMask;
	/*00b8*/ void * Key;
	/*00c0*/ ULONG KeyRefCount;
	/*00c8*/ void * RecoveryInformation;
	/*00d0*/ ULONG RecoveryInformationLength;
	/*00d8*/ void * DynamicNameInformation;
	/*00e0*/ ULONG DynamicNameInformationLength;
	/*00e8*/ _KTMNOTIFICATION_PACKET * FinalNotification;
	/*00f0*/ _KENLISTMENT * SupSubEnlistment;
	/*00f8*/ void * SupSubEnlHandle;
	/*0100*/ void * SubordinateTxHandle;
	/*0108*/ _GUID CrmEnlistmentEnId;
	/*0118*/ _GUID CrmEnlistmentTmId;
	/*0128*/ _GUID CrmEnlistmentRmId;
	/*0138*/ ULONG NextHistory;
	/*013c*/ _KENLISTMENT_HISTORY History[0x14];
	/*01e0*/
};

struct _KENLISTMENT_HISTORY {
	/*0000*/ ULONG Notification;
	/*0004*/ _KENLISTMENT_STATE NewState;
	/*0008*/
};

enum _KENLISTMENT_STATE {
	KEnlistmentUninitialized = 0x0,
	KEnlistmentActive = 0x100,
	KEnlistmentPreparing = 0x101,
	KEnlistmentPrepared = 0x102,
	KEnlistmentInDoubt = 0x103,
	KEnlistmentCommitted = 0x104,
	KEnlistmentCommittedNotify = 0x105,
	KEnlistmentCommitRequested = 0x106,
	KEnlistmentAborted = 0x107,
	KEnlistmentDelegated = 0x108,
	KEnlistmentDelegatedDisconnected = 0x109,
	KEnlistmentPrePreparing = 0x10a,
	KEnlistmentForgotten = 0x10b,
	KEnlistmentRecovering = 0x10c,
	KEnlistmentAborting = 0x10d,
	KEnlistmentReadOnly = 0x10e,
	KEnlistmentOutcomeUnavailable = 0x10f,
	KEnlistmentOffline = 0x110,
	KEnlistmentPrePrepared = 0x111,
	KEnlistmentInitialized = 0x112
};

struct _KENTROPY_TIMING_STATE {
	/*0000*/ ULONG EntropyCount;
	/*0004*/ ULONG Buffer[0x40];
	/*0108*/ _KDPC Dpc;
	/*0148*/ ULONG LastDeliveredBuffer;
	/*0150*/
};

enum _KERNEL_STACK_LIMITS {
	BugcheckStackLimits = 0x0,
	DPCStackLimits = 0x1,
	ExpandedStackLimits = 0x2,
	NormalStackLimits = 0x3,
	Win32kStackLimits = 0x4,
	SwapBusyStackLimits = 0x5,
	IsrStackLimits = 0x6,
	DebuggerStackLimits = 0x7,
	MaximumStackLimits = 0x8
};

struct _KERNEL_STACK_SEGMENT {
	/*0000*/ ULONGLONG StackBase;
	/*0008*/ ULONGLONG StackLimit;
	/*0010*/ ULONGLONG KernelStack;
	/*0018*/ ULONGLONG InitialStack;
	/*0020*/
};

struct _KEVENT {
	/*0000*/ _DISPATCHER_HEADER Header;
	/*0018*/
};

struct _KEXCEPTION_FRAME {
	/*0000*/ ULONGLONG P1Home;
	/*0008*/ ULONGLONG P2Home;
	/*0010*/ ULONGLONG P3Home;
	/*0018*/ ULONGLONG P4Home;
	/*0020*/ ULONGLONG P5;
	/*0028*/ ULONGLONG Spare1;
	/*0030*/ _M128A Xmm6;
	/*0040*/ _M128A Xmm7;
	/*0050*/ _M128A Xmm8;
	/*0060*/ _M128A Xmm9;
	/*0070*/ _M128A Xmm10;
	/*0080*/ _M128A Xmm11;
	/*0090*/ _M128A Xmm12;
	/*00a0*/ _M128A Xmm13;
	/*00b0*/ _M128A Xmm14;
	/*00c0*/ _M128A Xmm15;
	/*00d0*/ ULONGLONG TrapFrame;
	/*00d8*/ ULONGLONG OutputBuffer;
	/*00e0*/ ULONGLONG OutputLength;
	/*00e8*/ ULONGLONG Spare2;
	/*00f0*/ ULONGLONG MxCsr;
	/*00f8*/ ULONGLONG Rbp;
	/*0100*/ ULONGLONG Rbx;
	/*0108*/ ULONGLONG Rdi;
	/*0110*/ ULONGLONG Rsi;
	/*0118*/ ULONGLONG R12;
	/*0120*/ ULONGLONG R13;
	/*0128*/ ULONGLONG R14;
	/*0130*/ ULONGLONG R15;
	/*0138*/ ULONGLONG Return;
	/*0140*/
};

union _KEXECUTE_OPTIONS {
	/*0000*/ UCHAR ExecuteDisable : 01; // 0x01;
	/*0000*/ UCHAR ExecuteEnable : 01; // 0x02;
	/*0000*/ UCHAR DisableThunkEmulation : 01; // 0x04;
	/*0000*/ UCHAR Permanent : 01; // 0x08;
	/*0000*/ UCHAR ExecuteDispatchEnable : 01; // 0x10;
	/*0000*/ UCHAR ImageDispatchEnable : 01; // 0x20;
	/*0000*/ UCHAR DisableExceptionChainValidation : 01; // 0x40;
	/*0000*/ UCHAR Spare : 01; // 0x80;
	/*0000*/ UCHAR volatile ExecuteOptions;
	/*0000*/ UCHAR ExecuteOptionsNV;
	/*0001*/
};

struct _KFLOATING_SAVE {
	/*0000*/ ULONG Dummy;
	/*0004*/
};

struct _KGATE {
	/*0000*/ _DISPATCHER_HEADER Header;
	/*0018*/
};

union _KGDTENTRY64 {
	/*0000*/ USHORT LimitLow;
	/*0002*/ USHORT BaseLow;
	struct {
		/*0004*/ UCHAR BaseMiddle;
		/*0005*/ UCHAR Flags1;
		/*0006*/ UCHAR Flags2;
		/*0007*/ UCHAR BaseHigh;
		/*0008*/
	} Bytes;
	struct {
		/*0004*/ ULONG BaseMiddle : 08; // 0x000000ff;
		/*0004*/ ULONG Type : 05; // 0x00001f00;
		/*0004*/ ULONG Dpl : 02; // 0x00006000;
		/*0004*/ ULONG Present : 01; // 0x00008000;
		/*0004*/ ULONG LimitHigh : 04; // 0x000f0000;
		/*0004*/ ULONG System : 01; // 0x00100000;
		/*0004*/ ULONG LongMode : 01; // 0x00200000;
		/*0004*/ ULONG DefaultBig : 01; // 0x00400000;
		/*0004*/ ULONG Granularity : 01; // 0x00800000;
		/*0004*/ ULONG BaseHigh : 08; // 0xff000000;
		/*0008*/
	} Bits;
	/*0008*/ ULONG BaseUpper;
	/*000c*/ ULONG MustBeZero;
	/*0000*/ LONGLONG DataLow;
	/*0008*/ LONGLONG DataHigh;
	/*0010*/
};

enum _KHETERO_CPU_POLICY {
	KHeteroCpuPolicyAll = 0x0,
	KHeteroCpuPolicyLarge = 0x1,
	KHeteroCpuPolicyLargeOrIdle = 0x2,
	KHeteroCpuPolicySmall = 0x3,
	KHeteroCpuPolicySmallOrIdle = 0x4,
	KHeteroCpuPolicyDynamic = 0x5,
	KHeteroCpuPolicyStaticMax = 0x5,
	KHeteroCpuPolicyBiasedSmall = 0x6,
	KHeteroCpuPolicyBiasedLarge = 0x7,
	KHeteroCpuPolicyDefault = 0x8,
	KHeteroCpuPolicyMax = 0x9
};

enum _KHETERO_CPU_QOS {
	KHeteroCpuQosDefault = 0x0,
	KHeteroCpuQosHigh = 0x0,
	KHeteroCpuQosMedium = 0x1,
	KHeteroCpuQosLow = 0x2,
	KHeteroCpuQosDynamic = 0x3,
	KHeteroCpuQosMax = 0x3
};

struct _KHETERO_PROCESSOR_SET {
	/*0000*/ ULONGLONG IdealMask;
	/*0008*/ ULONGLONG PreferredMask;
	/*0010*/ ULONGLONG AvailableMask;
	/*0018*/
};

enum _KHETERO_RUNNING_TYPE {
	KHeteroShortRunning = 0x0,
	KHeteroLongRunning = 0x1,
	KHeteroRunningTypeMax = 0x2
};

union _KIDTENTRY64 {
	/*0000*/ USHORT OffsetLow;
	/*0002*/ USHORT Selector;
	/*0004*/ USHORT IstIndex : 03; // 0x0007;
	/*0004*/ USHORT Reserved0 : 05; // 0x00f8;
	/*0004*/ USHORT Type : 05; // 0x1f00;
	/*0004*/ USHORT Dpl : 02; // 0x6000;
	/*0004*/ USHORT Present : 01; // 0x8000;
	/*0006*/ USHORT OffsetMiddle;
	/*0008*/ ULONG OffsetHigh;
	/*000c*/ ULONG Reserved1;
	/*0000*/ ULONGLONG Alignment;
	/*0010*/
};

struct _KINTERRUPT {
	/*0000*/ SHORT Type;
	/*0002*/ SHORT Size;
	/*0008*/ _LIST_ENTRY InterruptListEntry;
	/*0018*/ UCHAR (* ServiceRoutine)( _KINTERRUPT * , void * );
	/*0020*/ UCHAR (* MessageServiceRoutine)( _KINTERRUPT * , void * , ULONG );
	/*0028*/ ULONG MessageIndex;
	/*0030*/ void * ServiceContext;
	/*0038*/ ULONGLONG SpinLock;
	/*0040*/ ULONG TickCount;
	/*0048*/ ULONGLONG * ActualLock;
	/*0050*/ void (* DispatchAddress)();
	/*0058*/ ULONG Vector;
	/*005c*/ UCHAR Irql;
	/*005d*/ UCHAR SynchronizeIrql;
	/*005e*/ UCHAR FloatingSave;
	/*005f*/ UCHAR Connected;
	/*0060*/ ULONG Number;
	/*0064*/ UCHAR ShareVector;
	/*0065*/ UCHAR EmulateActiveBoth;
	/*0066*/ USHORT ActiveCount;
	/*0068*/ LONG InternalState;
	/*006c*/ _KINTERRUPT_MODE Mode;
	/*0070*/ _KINTERRUPT_POLARITY Polarity;
	/*0074*/ ULONG ServiceCount;
	/*0078*/ ULONG DispatchCount;
	/*0080*/ _KEVENT * PassiveEvent;
	/*0088*/ _KTRAP_FRAME * TrapFrame;
	/*0090*/ void * DisconnectData;
	/*0098*/ _KTHREAD * volatile ServiceThread;
	/*00a0*/ _INTERRUPT_CONNECTION_DATA * ConnectionData;
	/*00a8*/ void * IntTrackEntry;
	/*00b0*/ _ISRDPCSTATS IsrDpcStats;
	/*00f0*/ void * RedirectObject;
	/*00f8*/ UCHAR Padding[0x8];
	/*0100*/
};

enum _KINTERRUPT_MODE {
	LevelSensitive = 0x0,
	Latched = 0x1
};

enum _KINTERRUPT_POLARITY {
	InterruptPolarityUnknown = 0x0,
	InterruptActiveHigh = 0x1,
	InterruptRisingEdge = 0x1,
	InterruptActiveLow = 0x2,
	InterruptFallingEdge = 0x2,
	InterruptActiveBoth = 0x3,
	InterruptActiveBothTriggerLow = 0x3,
	InterruptActiveBothTriggerHigh = 0x4
};

enum _KI_CALLBACK {
	KiCallbackNmi = 0x0,
	KiCallbackBound = 0x1,
	KiCallbackSx = 0x2,
	KiCallbackCount = 0x3,
	KiFirstCallback = 0x0
};

struct _KLDR_DATA_TABLE_ENTRY {
	/*0000*/ _LIST_ENTRY InLoadOrderLinks;
	/*0010*/ void * ExceptionTable;
	/*0018*/ ULONG ExceptionTableSize;
	/*0020*/ void * GpValue;
	/*0028*/ _NON_PAGED_DEBUG_INFO * NonPagedDebugInfo;
	/*0030*/ void * DllBase;
	/*0038*/ void * EntryPoint;
	/*0040*/ ULONG SizeOfImage;
	/*0048*/ _UNICODE_STRING FullDllName;
	/*0058*/ _UNICODE_STRING BaseDllName;
	/*0068*/ ULONG Flags;
	/*006c*/ USHORT LoadCount;
	union {
		/*006e*/ USHORT SignatureLevel : 04; // 0x000f;
		/*006e*/ USHORT SignatureType : 03; // 0x0070;
		/*006e*/ USHORT Unused : 09; // 0xff80;
		/*006e*/ USHORT EntireField;
		/*0070*/
	} u1;
	/*0070*/ void * SectionPointer;
	/*0078*/ ULONG CheckSum;
	/*007c*/ ULONG CoverageSectionSize;
	/*0080*/ void * CoverageSection;
	/*0088*/ void * LoadedImports;
	/*0090*/ void * Spare;
	/*0098*/ ULONG SizeOfImageNotRounded;
	/*009c*/ ULONG TimeDateStamp;
	/*00a0*/
};

struct _KLOCK_ENTRY {
	/*0000*/ _RTL_BALANCED_NODE TreeNode;
	/*0000*/ _SINGLE_LIST_ENTRY FreeListEntry;
	/*0018*/ ULONG EntryFlags;
	/*0018*/ UCHAR EntryOffset;
	/*0019*/ UCHAR ThreadLocalFlags;
	/*0019*/ UCHAR WaitingBit : 01; // 0x01;
	/*0019*/ UCHAR Spare0 : 07; // 0xfe;
	/*001a*/ UCHAR AcquiredByte;
	/*001a*/ UCHAR AcquiredBit : 01; // 0x01;
	/*001b*/ UCHAR CrossThreadFlags;
	/*001b*/ UCHAR HeadNodeBit : 01; // 0x01;
	/*001b*/ UCHAR IoPriorityBit : 01; // 0x02;
	/*001b*/ UCHAR IoQoSWaiter : 01; // 0x04;
	/*001b*/ UCHAR Spare1 : 05; // 0xf8;
	/*0018*/ ULONG StaticState : 08; // 0x000000ff;
	/*0018*/ ULONG AllFlags : 24; // 0xffffff00;
	/*001c*/ ULONG SpareFlags;
	/*0020*/ _KLOCK_ENTRY_LOCK_STATE LockState;
	/*0020*/ void * volatile LockUnsafe;
	/*0020*/ UCHAR volatile CrossThreadReleasableAndBusyByte;
	/*0021*/ UCHAR Reserved[0x6];
	/*0027*/ UCHAR volatile InTreeByte;
	/*0028*/ void * SessionState;
	/*0028*/ ULONG SessionId;
	/*002c*/ ULONG SessionPad;
	/*0030*/ _RTL_RB_TREE OwnerTree;
	/*0040*/ _RTL_RB_TREE WaiterTree;
	/*0030*/ CHAR CpuPriorityKey;
	/*0050*/ ULONGLONG EntryLock;
	/*0058*/ _KLOCK_ENTRY_BOOST_BITMAP BoostBitmap;
	/*005c*/ ULONG SparePad;
	/*0060*/
};

union _KLOCK_ENTRY_BOOST_BITMAP {
	/*0000*/ ULONG AllFields;
	/*0000*/ ULONG AllBoosts : 17; // 0x0001ffff;
	/*0000*/ ULONG Reserved : 15; // 0xfffe0000;
	/*0000*/ USHORT CpuBoostsBitmap : 15; // 0x7fff;
	/*0000*/ USHORT IoBoost : 01; // 0x8000;
	/*0002*/ USHORT IoQoSBoost : 01; // 0x0001;
	/*0002*/ USHORT IoNormalPriorityWaiterCount : 08; // 0x01fe;
	/*0002*/ USHORT IoQoSWaiterCount : 07; // 0xfe00;
	/*0004*/
};

struct _KLOCK_ENTRY_LOCK_STATE {
	/*0000*/ ULONGLONG CrossThreadReleasable : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG Busy : 01; // 0x0000000000000002;
	/*0000*/ ULONGLONG Reserved : 61; // 0x7ffffffffffffffc;
	/*0000*/ ULONGLONG InTree : 01; // 0x8000000000000000;
	/*0000*/ void * LockState;
	/*0008*/ void * SessionState;
	/*0008*/ ULONG SessionId;
	/*000c*/ ULONG SessionPad;
	/*0010*/
};

struct _KLOCK_QUEUE_HANDLE {
	/*0000*/ _KSPIN_LOCK_QUEUE LockQueue;
	/*0010*/ UCHAR OldIrql;
	/*0018*/
};

struct _KMUTANT {
	/*0000*/ _DISPATCHER_HEADER Header;
	/*0018*/ _LIST_ENTRY MutantListEntry;
	/*0028*/ _KTHREAD * OwnerThread;
	/*0030*/ UCHAR Abandoned;
	/*0031*/ UCHAR ApcDisable;
	/*0038*/
};

struct _KNODE {
	/*0000*/ ULONGLONG IdleNonParkedCpuSet;
	/*0008*/ ULONGLONG IdleSmtSet;
	/*0010*/ ULONGLONG IdleCpuSet;
	/*0040*/ ULONGLONG DeepIdleSet;
	/*0048*/ ULONGLONG IdleConstrainedSet;
	/*0050*/ ULONGLONG NonParkedSet;
	/*0058*/ LONG ParkLock;
	/*005c*/ ULONG Seed;
	/*0080*/ ULONG SiblingMask;
	/*0088*/ _GROUP_AFFINITY Affinity;
	/*0088*/ UCHAR AffinityFill[0xa];
	/*0092*/ USHORT NodeNumber;
	/*0094*/ USHORT PrimaryNodeNumber;
	/*0096*/ UCHAR Stride;
	/*0097*/ UCHAR Spare0;
	/*0098*/ ULONGLONG SharedReadyQueueLeaders;
	/*00a0*/ ULONG ProximityId;
	/*00a4*/ ULONG Lowest;
	/*00a8*/ ULONG Highest;
	/*00ac*/ UCHAR MaximumProcessors;
	/*00ad*/ _flags Flags;
	/*00ae*/ UCHAR Spare10;
	/*00b0*/ _KHETERO_PROCESSOR_SET HeteroSets[0x5];
	/*0128*/ ULONGLONG PpmConfiguredQosSets[0x3];
	/*0140*/
};

enum _KOBJECTS {
	EventNotificationObject = 0x0,
	EventSynchronizationObject = 0x1,
	MutantObject = 0x2,
	ProcessObject = 0x3,
	QueueObject = 0x4,
	SemaphoreObject = 0x5,
	ThreadObject = 0x6,
	GateObject = 0x7,
	TimerNotificationObject = 0x8,
	TimerSynchronizationObject = 0x9,
	Spare2Object = 0xa,
	Spare3Object = 0xb,
	Spare4Object = 0xc,
	Spare5Object = 0xd,
	Spare6Object = 0xe,
	Spare7Object = 0xf,
	Spare8Object = 0x10,
	ProfileCallbackObject = 0x11,
	ApcObject = 0x12,
	DpcObject = 0x13,
	DeviceQueueObject = 0x14,
	PriQueueObject = 0x15,
	InterruptObject = 0x16,
	ProfileObject = 0x17,
	Timer2NotificationObject = 0x18,
	Timer2SynchronizationObject = 0x19,
	ThreadedDpcObject = 0x1a,
	MaximumKernelObject = 0x1b
};

struct _KPCR {
	/*0000*/ _NT_TIB NtTib;
	/*0000*/ _KGDTENTRY64 * GdtBase;
	/*0008*/ _KTSS64 * TssBase;
	/*0010*/ ULONGLONG UserRsp;
	/*0018*/ _KPCR * Self;
	/*0020*/ _KPRCB * CurrentPrcb;
	/*0028*/ _KSPIN_LOCK_QUEUE * LockArray;
	/*0030*/ void * Used_Self;
	/*0038*/ _KIDTENTRY64 * IdtBase;
	/*0040*/ ULONGLONG Unused[0x2];
	/*0050*/ UCHAR Irql;
	/*0051*/ UCHAR SecondLevelCacheAssociativity;
	/*0052*/ UCHAR ObsoleteNumber;
	/*0053*/ UCHAR Fill0;
	/*0054*/ ULONG Unused0[0x3];
	/*0060*/ USHORT MajorVersion;
	/*0062*/ USHORT MinorVersion;
	/*0064*/ ULONG StallScaleFactor;
	/*0068*/ void * Unused1[0x3];
	/*0080*/ ULONG KernelReserved[0xf];
	/*00bc*/ ULONG SecondLevelCacheSize;
	/*00c0*/ ULONG HalReserved[0x10];
	/*0100*/ ULONG Unused2;
	/*0108*/ void * KdVersionBlock;
	/*0110*/ void * Unused3;
	/*0118*/ ULONG PcrAlign1[0x18];
	/*0180*/ _KPRCB Prcb;
	/*6b00*/
};

struct _KPRCB {
	/*0000*/ ULONG MxCsr;
	/*0004*/ UCHAR LegacyNumber;
	/*0005*/ UCHAR ReservedMustBeZero;
	/*0006*/ UCHAR InterruptRequest;
	/*0007*/ UCHAR IdleHalt;
	/*0008*/ _KTHREAD * CurrentThread;
	/*0010*/ _KTHREAD * NextThread;
	/*0018*/ _KTHREAD * IdleThread;
	/*0020*/ UCHAR NestingLevel;
	/*0021*/ UCHAR ClockOwner;
	/*0022*/ UCHAR PendingTickFlags;
	/*0022*/ UCHAR PendingTick : 01; // 0x01;
	/*0022*/ UCHAR PendingBackupTick : 01; // 0x02;
	/*0023*/ UCHAR IdleState;
	/*0024*/ ULONG Number;
	/*0028*/ ULONGLONG RspBase;
	/*0030*/ ULONGLONG PrcbLock;
	/*0038*/ CHAR * PriorityState;
	/*0040*/ CHAR CpuType;
	/*0041*/ CHAR CpuID;
	/*0042*/ USHORT CpuStep;
	/*0042*/ UCHAR CpuStepping;
	/*0043*/ UCHAR CpuModel;
	/*0044*/ ULONG MHz;
	/*0048*/ ULONGLONG HalReserved[0x8];
	/*0088*/ USHORT MinorVersion;
	/*008a*/ USHORT MajorVersion;
	/*008c*/ UCHAR BuildType;
	/*008d*/ UCHAR CpuVendor;
	/*008e*/ UCHAR CoresPerPhysicalProcessor;
	/*008f*/ UCHAR LogicalProcessorsPerCore;
	/*0090*/ ULONGLONG PrcbPad04[0x6];
	/*00c0*/ _KNODE * ParentNode;
	/*00c8*/ ULONGLONG GroupSetMember;
	/*00d0*/ UCHAR Group;
	/*00d1*/ UCHAR GroupIndex;
	/*00d2*/ UCHAR PrcbPad05[0x2];
	/*00d4*/ ULONG InitialApicId;
	/*00d8*/ ULONG ScbOffset;
	/*00dc*/ ULONG ApicMask;
	/*00e0*/ void * AcpiReserved;
	/*00e8*/ ULONG CFlushSize;
	/*00ec*/ LONG volatile BamFlags;
	/*00ec*/ ULONG BamQosLevel : 02; // 0x00000003;
	/*00ec*/ ULONG PendingQosUpdate : 02; // 0x0000000c;
	/*00ec*/ ULONG BamFlagsReserved : 28; // 0xfffffff0;
	/*00f0*/ ULONGLONG PrcbPad11[0x2];
	/*0100*/ _KPROCESSOR_STATE ProcessorState;
	/*06c0*/ ULONGLONG PrcbPad12[0x6];
	/*06f0*/ _KSPIN_LOCK_QUEUE LockQueue[0x11];
	/*0800*/ _PP_LOOKASIDE_LIST PPLookasideList[0x10];
	/*0900*/ _GENERAL_LOOKASIDE_POOL PPNxPagedLookasideList[0x20];
	/*1500*/ _GENERAL_LOOKASIDE_POOL PPNPagedLookasideList[0x20];
	/*2100*/ _GENERAL_LOOKASIDE_POOL PPPagedLookasideList[0x20];
	/*2d00*/ ULONGLONG PrcbPad20;
	/*2d08*/ _SINGLE_LIST_ENTRY DeferredReadyListHead;
	/*2d10*/ LONG volatile MmPageFaultCount;
	/*2d14*/ LONG volatile MmCopyOnWriteCount;
	/*2d18*/ LONG volatile MmTransitionCount;
	/*2d1c*/ LONG volatile MmDemandZeroCount;
	/*2d20*/ LONG volatile MmPageReadCount;
	/*2d24*/ LONG volatile MmPageReadIoCount;
	/*2d28*/ LONG volatile MmDirtyPagesWriteCount;
	/*2d2c*/ LONG volatile MmDirtyWriteIoCount;
	/*2d30*/ LONG volatile MmMappedPagesWriteCount;
	/*2d34*/ LONG volatile MmMappedWriteIoCount;
	/*2d38*/ ULONG KeSystemCalls;
	/*2d3c*/ ULONG KeContextSwitches;
	/*2d40*/ ULONG PrcbPad40;
	/*2d44*/ ULONG CcFastReadNoWait;
	/*2d48*/ ULONG CcFastReadWait;
	/*2d4c*/ ULONG CcFastReadNotPossible;
	/*2d50*/ ULONG CcCopyReadNoWait;
	/*2d54*/ ULONG CcCopyReadWait;
	/*2d58*/ ULONG CcCopyReadNoWaitMiss;
	/*2d5c*/ LONG volatile IoReadOperationCount;
	/*2d60*/ LONG volatile IoWriteOperationCount;
	/*2d64*/ LONG volatile IoOtherOperationCount;
	/*2d68*/ _LARGE_INTEGER IoReadTransferCount;
	/*2d70*/ _LARGE_INTEGER IoWriteTransferCount;
	/*2d78*/ _LARGE_INTEGER IoOtherTransferCount;
	/*2d80*/ LONG volatile PacketBarrier;
	/*2d84*/ LONG volatile TargetCount;
	/*2d88*/ ULONG volatile IpiFrozen;
	/*2d8c*/ ULONG PrcbPad30;
	/*2d90*/ void * IsrDpcStats;
	/*2d98*/ ULONG DeviceInterrupts;
	/*2d9c*/ LONG LookasideIrpFloat;
	/*2da0*/ ULONG InterruptLastCount;
	/*2da4*/ ULONG InterruptRate;
	/*2da8*/ ULONGLONG LastNonHrTimerExpiration;
	/*2db0*/ ULONGLONG PrcbPad35[0x2];
	/*2dc0*/ _SLIST_HEADER InterruptObjectPool;
	/*2dd0*/ ULONGLONG PrcbPad41[0x6];
	/*2e00*/ _KDPC_DATA DpcData[0x2];
	/*2e50*/ void * DpcStack;
	/*2e58*/ LONG MaximumDpcQueueDepth;
	/*2e5c*/ ULONG DpcRequestRate;
	/*2e60*/ ULONG MinimumDpcRate;
	/*2e64*/ ULONG DpcLastCount;
	/*2e68*/ UCHAR ThreadDpcEnable;
	/*2e69*/ UCHAR volatile QuantumEnd;
	/*2e6a*/ UCHAR volatile DpcRoutineActive;
	/*2e6b*/ UCHAR volatile IdleSchedule;
	/*2e6c*/ LONG volatile DpcRequestSummary;
	/*2e6c*/ SHORT DpcRequestSlot[0x2];
	/*2e6c*/ SHORT NormalDpcState;
	/*2e6e*/ SHORT ThreadDpcState;
	/*2e6c*/ ULONG DpcNormalProcessingActive : 01; // 0x00000001;
	/*2e6c*/ ULONG DpcNormalProcessingRequested : 01; // 0x00000002;
	/*2e6c*/ ULONG DpcNormalThreadSignal : 01; // 0x00000004;
	/*2e6c*/ ULONG DpcNormalTimerExpiration : 01; // 0x00000008;
	/*2e6c*/ ULONG DpcNormalDpcPresent : 01; // 0x00000010;
	/*2e6c*/ ULONG DpcNormalLocalInterrupt : 01; // 0x00000020;
	/*2e6c*/ ULONG DpcNormalSpare : 10; // 0x0000ffc0;
	/*2e6c*/ ULONG DpcThreadActive : 01; // 0x00010000;
	/*2e6c*/ ULONG DpcThreadRequested : 01; // 0x00020000;
	/*2e6c*/ ULONG DpcThreadSpare : 14; // 0xfffc0000;
	/*2e70*/ ULONG LastTimerHand;
	/*2e74*/ ULONG LastTick;
	/*2e78*/ ULONG ClockInterrupts;
	/*2e7c*/ ULONG ReadyScanTick;
	/*2e80*/ void * InterruptObject[0x100];
	/*3680*/ _KTIMER_TABLE TimerTable;
	/*5880*/ _KGATE DpcGate;
	/*5898*/ void * PrcbPad52;
	/*58a0*/ _KDPC CallDpc;
	/*58e0*/ LONG ClockKeepAlive;
	/*58e4*/ UCHAR PrcbPad60[0x2];
	/*58e6*/ USHORT NmiActive;
	/*58e8*/ LONG DpcWatchdogPeriod;
	/*58ec*/ LONG DpcWatchdogCount;
	/*58f0*/ LONG volatile KeSpinLockOrdering;
	/*58f4*/ ULONG DpcWatchdogProfileCumulativeDpcThreshold;
	/*58f8*/ void * CachedPtes;
	/*5900*/ _LIST_ENTRY WaitListHead;
	/*5910*/ ULONGLONG WaitLock;
	/*5918*/ ULONG ReadySummary;
	/*591c*/ LONG AffinitizedSelectionMask;
	/*5920*/ ULONG QueueIndex;
	/*5924*/ ULONG PrcbPad75[0x3];
	/*5930*/ _KDPC TimerExpirationDpc;
	/*5970*/ _RTL_RB_TREE ScbQueue;
	/*5980*/ _LIST_ENTRY DispatcherReadyListHead[0x20];
	/*5b80*/ ULONG InterruptCount;
	/*5b84*/ ULONG KernelTime;
	/*5b88*/ ULONG UserTime;
	/*5b8c*/ ULONG DpcTime;
	/*5b90*/ ULONG InterruptTime;
	/*5b94*/ ULONG AdjustDpcThreshold;
	/*5b98*/ UCHAR DebuggerSavedIRQL;
	/*5b99*/ UCHAR GroupSchedulingOverQuota;
	/*5b9a*/ UCHAR volatile DeepSleep;
	/*5b9b*/ UCHAR PrcbPad80;
	/*5b9c*/ ULONG DpcTimeCount;
	/*5ba0*/ ULONG DpcTimeLimit;
	/*5ba4*/ ULONG PeriodicCount;
	/*5ba8*/ ULONG PeriodicBias;
	/*5bac*/ ULONG AvailableTime;
	/*5bb0*/ ULONG KeExceptionDispatchCount;
	/*5bb4*/ ULONG ReadyThreadCount;
	/*5bb8*/ ULONGLONG ReadyQueueExpectedRunTime;
	/*5bc0*/ ULONGLONG StartCycles;
	/*5bc8*/ ULONGLONG TaggedCyclesStart;
	/*5bd0*/ ULONGLONG TaggedCycles[0x2];
	/*5be0*/ ULONGLONG GenerationTarget;
	/*5be8*/ ULONGLONG AffinitizedCycles;
	/*5bf0*/ ULONGLONG ImportantCycles;
	/*5bf8*/ ULONGLONG UnimportantCycles;
	/*5c00*/ ULONG DpcWatchdogProfileSingleDpcThreshold;
	/*5c04*/ LONG volatile MmSpinLockOrdering;
	/*5c08*/ void * volatile CachedStack;
	/*5c10*/ ULONG PageColor;
	/*5c14*/ ULONG NodeColor;
	/*5c18*/ ULONG NodeShiftedColor;
	/*5c1c*/ ULONG SecondaryColorMask;
	/*5c20*/ ULONGLONG PrcbPad81[0x3];
	/*5c38*/ ULONGLONG CycleTime;
	/*5c40*/ ULONGLONG Cycles[0x4][0x2];
	/*5c80*/ ULONG CcFastMdlReadNoWait;
	/*5c84*/ ULONG CcFastMdlReadWait;
	/*5c88*/ ULONG CcFastMdlReadNotPossible;
	/*5c8c*/ ULONG CcMapDataNoWait;
	/*5c90*/ ULONG CcMapDataWait;
	/*5c94*/ ULONG CcPinMappedDataCount;
	/*5c98*/ ULONG CcPinReadNoWait;
	/*5c9c*/ ULONG CcPinReadWait;
	/*5ca0*/ ULONG CcMdlReadNoWait;
	/*5ca4*/ ULONG CcMdlReadWait;
	/*5ca8*/ ULONG CcLazyWriteHotSpots;
	/*5cac*/ ULONG CcLazyWriteIos;
	/*5cb0*/ ULONG CcLazyWritePages;
	/*5cb4*/ ULONG CcDataFlushes;
	/*5cb8*/ ULONG CcDataPages;
	/*5cbc*/ ULONG CcLostDelayedWrites;
	/*5cc0*/ ULONG CcFastReadResourceMiss;
	/*5cc4*/ ULONG CcCopyReadWaitMiss;
	/*5cc8*/ ULONG CcFastMdlReadResourceMiss;
	/*5ccc*/ ULONG CcMapDataNoWaitMiss;
	/*5cd0*/ ULONG CcMapDataWaitMiss;
	/*5cd4*/ ULONG CcPinReadNoWaitMiss;
	/*5cd8*/ ULONG CcPinReadWaitMiss;
	/*5cdc*/ ULONG CcMdlReadNoWaitMiss;
	/*5ce0*/ ULONG CcMdlReadWaitMiss;
	/*5ce4*/ ULONG CcReadAheadIos;
	/*5ce8*/ LONG volatile MmCacheTransitionCount;
	/*5cec*/ LONG volatile MmCacheReadCount;
	/*5cf0*/ LONG volatile MmCacheIoCount;
	/*5cf4*/ ULONG PrcbPad91[0x3];
	/*5d00*/ _PROCESSOR_POWER_STATE PowerState;
	/*5f00*/ void * HyperPte;
	/*5f08*/ _LIST_ENTRY ScbList;
	/*5f18*/ _KDPC ForceIdleDpc;
	/*5f58*/ _KDPC DpcWatchdogDpc;
	/*5f98*/ _KTIMER DpcWatchdogTimer;
	/*5fd8*/ _CACHE_DESCRIPTOR Cache[0x5];
	/*6014*/ ULONG CacheCount;
	/*6018*/ ULONG volatile CachedCommit;
	/*601c*/ ULONG volatile CachedResidentAvailable;
	/*6020*/ void * WheaInfo;
	/*6028*/ void * EtwSupport;
	/*6030*/ void * ExSaPageArray;
	/*6038*/ ULONG KeAlignmentFixupCount;
	/*603c*/ ULONG PrcbPad95;
	/*6040*/ _SLIST_HEADER HypercallPageList;
	/*6050*/ ULONGLONG * StatisticsPage;
	/*6058*/ ULONGLONG PrcbPad85[0x5];
	/*6080*/ void * HypercallCachedPages;
	/*6088*/ void * VirtualApicAssist;
	/*6090*/ _KAFFINITY_EX PackageProcessorSet;
	/*6138*/ ULONGLONG PrcbPad86;
	/*6140*/ ULONGLONG SharedReadyQueueMask;
	/*6148*/ _KSHARED_READY_QUEUE * SharedReadyQueue;
	/*6150*/ ULONG SharedQueueScanOwner;
	/*6154*/ ULONG ScanSiblingIndex;
	/*6158*/ ULONGLONG CoreProcessorSet;
	/*6160*/ ULONGLONG ScanSiblingMask;
	/*6168*/ ULONGLONG LLCMask;
	/*6170*/ ULONGLONG CacheProcessorMask[0x5];
	/*6198*/ _PROCESSOR_PROFILE_CONTROL_AREA * ProcessorProfileControlArea;
	/*61a0*/ void * ProfileEventIndexAddress;
	/*61a8*/ void * * DpcWatchdogProfile;
	/*61b0*/ void * * DpcWatchdogProfileCurrentEmptyCapture;
	/*61b8*/ void * SchedulerAssist;
	/*61c0*/ _SYNCH_COUNTERS SynchCounters;
	/*6278*/ ULONGLONG PrcbPad94;
	/*6280*/ _FILESYSTEM_DISK_COUNTERS FsCounters;
	/*6290*/ UCHAR VendorString[0xd];
	/*629d*/ UCHAR PrcbPad100[0x3];
	/*62a0*/ ULONGLONG FeatureBits;
	/*62a8*/ _LARGE_INTEGER UpdateSignature;
	/*62b0*/ ULONGLONG PteBitCache;
	/*62b8*/ ULONG PteBitOffset;
	/*62bc*/ ULONG PrcbPad105;
	/*62c0*/ _CONTEXT * Context;
	/*62c8*/ ULONG ContextFlagsInit;
	/*62cc*/ ULONG PrcbPad115;
	/*62d0*/ _XSAVE_AREA * ExtendedState;
	/*62d8*/ void * IsrStack;
	/*62e0*/ _KENTROPY_TIMING_STATE EntropyTimingState;
	/*6430*/ _SINGLE_LIST_ENTRY AbSelfIoBoostsList;
	/*6438*/ _SINGLE_LIST_ENTRY AbPropagateBoostsList;
	/*6440*/ _KDPC AbDpc;
	/*6480*/ _IOP_IRP_STACK_PROFILER IoIrpStackProfilerCurrent;
	/*64d4*/ _IOP_IRP_STACK_PROFILER IoIrpStackProfilerPrevious;
	/*6528*/ _KSECURE_FAULT_INFORMATION SecureFault;
	/*6538*/ ULONGLONG PrcbPad120;
	/*6540*/ _KSHARED_READY_QUEUE LocalSharedReadyQueue;
	/*67b0*/ ULONGLONG PrcbPad125[0x2];
	/*67c0*/ ULONG TimerExpirationTraceCount;
	/*67c4*/ ULONG PrcbPad127;
	/*67c8*/ _KTIMER_EXPIRATION_TRACE TimerExpirationTrace[0x10];
	/*68c8*/ ULONGLONG PrcbPad128[0x7];
	/*6900*/ _REQUEST_MAILBOX * Mailbox;
	/*6908*/ ULONGLONG PrcbPad130[0x7];
	/*6940*/ _REQUEST_MAILBOX RequestMailbox[0x1];
	/*6980*/
};

struct _KPRIQUEUE {
	/*0000*/ _DISPATCHER_HEADER Header;
	/*0018*/ _LIST_ENTRY EntryListHead[0x20];
	/*0218*/ LONG volatile CurrentCount[0x20];
	/*0298*/ ULONG MaximumCount;
	/*02a0*/ _LIST_ENTRY ThreadListHead;
	/*02b0*/
};

struct _KPROCESS {
	/*0000*/ _DISPATCHER_HEADER Header;
	/*0018*/ _LIST_ENTRY ProfileListHead;
	/*0028*/ ULONGLONG DirectoryTableBase;
	/*0030*/ _LIST_ENTRY ThreadListHead;
	/*0040*/ ULONG ProcessLock;
	/*0044*/ ULONG ProcessTimerDelay;
	/*0048*/ ULONGLONG DeepFreezeStartTime;
	/*0050*/ _KAFFINITY_EX Affinity;
	/*00f8*/ _LIST_ENTRY ReadyListHead;
	/*0108*/ _SINGLE_LIST_ENTRY SwapListEntry;
	/*0110*/ _KAFFINITY_EX volatile ActiveProcessors;
	/*01b8*/ LONG AutoAlignment : 01; // 0x00000001;
	/*01b8*/ LONG DisableBoost : 01; // 0x00000002;
	/*01b8*/ LONG DisableQuantum : 01; // 0x00000004;
	/*01b8*/ ULONG DeepFreeze : 01; // 0x00000008;
	/*01b8*/ ULONG TimerVirtualization : 01; // 0x00000010;
	/*01b8*/ ULONG CheckStackExtents : 01; // 0x00000020;
	/*01b8*/ ULONG PpmPolicy : 03; // 0x000001c0;
	/*01b8*/ ULONG ActiveGroupsMask : 20; // 0x1ffffe00;
	/*01b8*/ LONG ReservedFlags : 03; // 0xe0000000;
	/*01b8*/ LONG volatile ProcessFlags;
	/*01bc*/ CHAR BasePriority;
	/*01bd*/ CHAR QuantumReset;
	/*01be*/ UCHAR Visited;
	/*01bf*/ _KEXECUTE_OPTIONS Flags;
	/*01c0*/ ULONG ThreadSeed[0x14];
	/*0210*/ USHORT IdealNode[0x14];
	/*0238*/ USHORT IdealGlobalNode;
	/*023a*/ USHORT Spare1;
	/*023c*/ _KSTACK_COUNT volatile StackCount;
	/*0240*/ _LIST_ENTRY ProcessListEntry;
	/*0250*/ ULONGLONG CycleTime;
	/*0258*/ ULONGLONG ContextSwitches;
	/*0260*/ _KSCHEDULING_GROUP * SchedulingGroup;
	/*0268*/ ULONG FreezeCount;
	/*026c*/ ULONG KernelTime;
	/*0270*/ ULONG UserTime;
	/*0274*/ ULONG ReadyTime;
	/*0278*/ UCHAR Spare2[0x50];
	/*02c8*/ void * InstrumentationCallback;
	union {
		/*02d0*/ ULONGLONG SecureHandle;
		struct {
			/*02d0*/ ULONGLONG SecureProcess : 01; // 0x0000000000000001;
			/*02d0*/ ULONGLONG Unused : 01; // 0x0000000000000002;
			/*02d8*/
		} Flags;
		/*02d8*/
	} SecureState;
	/*02d8*/
};

struct _KPROCESSOR_STATE {
	/*0000*/ _KSPECIAL_REGISTERS SpecialRegisters;
	/*00f0*/ _CONTEXT ContextFrame;
	/*05c0*/
};

enum _KPROCESS_PPM_POLICY {
	ProcessPpmDefault = 0x0,
	ProcessPpmThrottle = 0x1,
	ProcessPpmSemiThrottle = 0x2,
	ProcessPpmNoThrottle = 0x3,
	ProcessPpmWindowMinimized = 0x4,
	ProcessPpmWindowOccluded = 0x5,
	ProcessPpmWindowVisible = 0x6,
	ProcessPpmWindowInFocus = 0x7,
	MaxProcessPpmPolicy = 0x8
};

enum _KPROCESS_STATE {
	ProcessInMemory = 0x0,
	ProcessOutOfMemory = 0x1,
	ProcessInTransition = 0x2,
	ProcessOutTransition = 0x3,
	ProcessInSwap = 0x4,
	ProcessOutSwap = 0x5,
	ProcessRetryOutSwap = 0x6,
	ProcessAllSwapStates = 0x7
};

enum _KPROFILE_SOURCE {
	ProfileTime = 0x0,
	ProfileAlignmentFixup = 0x1,
	ProfileTotalIssues = 0x2,
	ProfilePipelineDry = 0x3,
	ProfileLoadInstructions = 0x4,
	ProfilePipelineFrozen = 0x5,
	ProfileBranchInstructions = 0x6,
	ProfileTotalNonissues = 0x7,
	ProfileDcacheMisses = 0x8,
	ProfileIcacheMisses = 0x9,
	ProfileCacheMisses = 0xa,
	ProfileBranchMispredictions = 0xb,
	ProfileStoreInstructions = 0xc,
	ProfileFpInstructions = 0xd,
	ProfileIntegerInstructions = 0xe,
	Profile2Issue = 0xf,
	Profile3Issue = 0x10,
	Profile4Issue = 0x11,
	ProfileSpecialInstructions = 0x12,
	ProfileTotalCycles = 0x13,
	ProfileIcacheIssues = 0x14,
	ProfileDcacheAccesses = 0x15,
	ProfileMemoryBarrierCycles = 0x16,
	ProfileLoadLinkedIssues = 0x17,
	ProfileMaximum = 0x18
};

struct _KQUEUE {
	/*0000*/ _DISPATCHER_HEADER Header;
	/*0018*/ _LIST_ENTRY EntryListHead;
	/*0028*/ ULONG volatile CurrentCount;
	/*002c*/ ULONG MaximumCount;
	/*0030*/ _LIST_ENTRY ThreadListHead;
	/*0040*/
};

struct _KREQUEST_PACKET {
	/*0000*/ void * CurrentPacket[0x3];
	/*0018*/ void (* WorkerRoutine)( void * , void * , void * , void * );
	/*0020*/
};

struct _KRESOURCEMANAGER {
	/*0000*/ _KEVENT NotificationAvailable;
	/*0018*/ ULONG cookie;
	/*001c*/ _KRESOURCEMANAGER_STATE State;
	/*0020*/ ULONG Flags;
	/*0028*/ _KMUTANT Mutex;
	/*0060*/ _KTMOBJECT_NAMESPACE_LINK NamespaceLink;
	/*0088*/ _GUID RmId;
	/*0098*/ _KQUEUE NotificationQueue;
	/*00d8*/ _KMUTANT NotificationMutex;
	/*0110*/ _LIST_ENTRY EnlistmentHead;
	/*0120*/ ULONG EnlistmentCount;
	/*0128*/ LONG (* NotificationRoutine)( _KENLISTMENT * , void * , void * , ULONG , _LARGE_INTEGER * , ULONG , void * );
	/*0130*/ void * Key;
	/*0138*/ _LIST_ENTRY ProtocolListHead;
	/*0148*/ _LIST_ENTRY PendingPropReqListHead;
	/*0158*/ _LIST_ENTRY CRMListEntry;
	/*0168*/ _KTM * Tm;
	/*0170*/ _UNICODE_STRING Description;
	/*0180*/ _KTMOBJECT_NAMESPACE Enlistments;
	/*0228*/ _KRESOURCEMANAGER_COMPLETION_BINDING CompletionBinding;
	/*0250*/
};

struct _KRESOURCEMANAGER_COMPLETION_BINDING {
	/*0000*/ _LIST_ENTRY NotificationListHead;
	/*0010*/ void * Port;
	/*0018*/ ULONGLONG Key;
	/*0020*/ _EPROCESS * BindingProcess;
	/*0028*/
};

enum _KRESOURCEMANAGER_STATE {
	KResourceManagerUninitialized = 0x0,
	KResourceManagerOffline = 0x1,
	KResourceManagerOnline = 0x2
};

struct _KSCB {
	/*0000*/ ULONGLONG GenerationCycles;
	/*0008*/ ULONGLONG MinQuotaCycleTarget;
	/*0010*/ ULONGLONG MaxQuotaCycleTarget;
	/*0018*/ ULONGLONG RankCycleTarget;
	/*0020*/ ULONGLONG LongTermCycles;
	/*0028*/ ULONGLONG LastReportedCycles;
	/*0030*/ ULONGLONG volatile OverQuotaHistory;
	/*0038*/ ULONGLONG ReadyTime;
	/*0040*/ ULONGLONG InsertTime;
	/*0048*/ _LIST_ENTRY PerProcessorList;
	/*0058*/ _RTL_BALANCED_NODE QueueNode;
	/*0070*/ UCHAR Inserted : 01; // 0x01;
	/*0070*/ UCHAR MaxOverQuota : 01; // 0x02;
	/*0070*/ UCHAR MinOverQuota : 01; // 0x04;
	/*0070*/ UCHAR RankBias : 01; // 0x08;
	/*0070*/ UCHAR SoftCap : 01; // 0x10;
	/*0070*/ UCHAR ShareRankOwner : 01; // 0x20;
	/*0070*/ UCHAR Spare1 : 02; // 0xc0;
	/*0071*/ UCHAR Depth;
	/*0072*/ USHORT ReadySummary;
	/*0074*/ ULONG Rank;
	/*0078*/ ULONG volatile * ShareRank;
	/*0080*/ ULONG volatile OwnerShareRank;
	/*0088*/ _LIST_ENTRY ReadyListHead[0x10];
	/*0188*/ _RTL_RB_TREE ChildScbQueue;
	/*0198*/ _KSCB * Parent;
	/*01a0*/ _KSCB * Root;
	/*01a8*/
};

struct _KSCHEDULING_GROUP {
	/*0000*/ _KSCHEDULING_GROUP_POLICY Policy;
	/*0008*/ ULONG RelativeWeight;
	/*000c*/ ULONG ChildMinRate;
	/*0010*/ ULONG ChildMinWeight;
	/*0014*/ ULONG ChildTotalWeight;
	/*0018*/ ULONGLONG QueryHistoryTimeStamp;
	/*0020*/ LONGLONG NotificationCycles;
	/*0028*/ LONGLONG MaxQuotaLimitCycles;
	/*0030*/ LONGLONG volatile MaxQuotaCyclesRemaining;
	/*0038*/ _LIST_ENTRY SchedulingGroupList;
	/*0038*/ _LIST_ENTRY Sibling;
	/*0048*/ _KDPC * NotificationDpc;
	/*0050*/ _LIST_ENTRY ChildList;
	/*0060*/ _KSCHEDULING_GROUP * Parent;
	/*0080*/ _KSCB PerProcessor[0x1];
	/*0240*/
};

struct _KSCHEDULING_GROUP_POLICY {
	/*0000*/ ULONG Value;
	/*0000*/ USHORT Weight;
	/*0000*/ USHORT MinRate;
	/*0002*/ USHORT MaxRate;
	/*0004*/ ULONG AllFlags;
	/*0004*/ ULONG Type : 01; // 0x00000001;
	/*0004*/ ULONG Disabled : 01; // 0x00000002;
	/*0004*/ ULONG RankBias : 01; // 0x00000004;
	/*0004*/ ULONG Spare1 : 29; // 0xfffffff8;
	/*0008*/
};

struct _KSECONDARY_IDT_ENTRY {
	/*0000*/ ULONGLONG SpinLock;
	/*0008*/ _KEVENT ConnectLock;
	/*0020*/ UCHAR LineMasked;
	/*0028*/ _KINTERRUPT * InterruptList;
	/*0030*/
};

struct _KSECURE_FAULT_INFORMATION {
	/*0000*/ ULONGLONG FaultCode;
	/*0008*/ ULONGLONG FaultVa;
	/*0010*/
};

struct _KSEMAPHORE {
	/*0000*/ _DISPATCHER_HEADER Header;
	/*0018*/ LONG Limit;
	/*0020*/
};

struct _KSHARED_READY_QUEUE {
	/*0000*/ ULONGLONG Lock;
	/*0008*/ ULONG ReadySummary;
	/*0010*/ _LIST_ENTRY ReadyListHead[0x20];
	/*0210*/ CHAR RunningSummary[0x40];
	/*0250*/ UCHAR Span;
	/*0251*/ UCHAR LowProcIndex;
	/*0252*/ UCHAR QueueIndex;
	/*0253*/ UCHAR ProcCount;
	/*0254*/ UCHAR ScanOwner;
	/*0255*/ UCHAR Spare[0x3];
	/*0258*/ ULONGLONG Affinity;
	/*0260*/ ULONG ReadyThreadCount;
	/*0268*/ ULONGLONG ReadyQueueExpectedRunTime;
	/*0270*/
};

struct _KSPECIAL_REGISTERS {
	/*0000*/ ULONGLONG Cr0;
	/*0008*/ ULONGLONG Cr2;
	/*0010*/ ULONGLONG Cr3;
	/*0018*/ ULONGLONG Cr4;
	/*0020*/ ULONGLONG KernelDr0;
	/*0028*/ ULONGLONG KernelDr1;
	/*0030*/ ULONGLONG KernelDr2;
	/*0038*/ ULONGLONG KernelDr3;
	/*0040*/ ULONGLONG KernelDr6;
	/*0048*/ ULONGLONG KernelDr7;
	/*0050*/ _KDESCRIPTOR Gdtr;
	/*0060*/ _KDESCRIPTOR Idtr;
	/*0070*/ USHORT Tr;
	/*0072*/ USHORT Ldtr;
	/*0074*/ ULONG MxCsr;
	/*0078*/ ULONGLONG DebugControl;
	/*0080*/ ULONGLONG LastBranchToRip;
	/*0088*/ ULONGLONG LastBranchFromRip;
	/*0090*/ ULONGLONG LastExceptionToRip;
	/*0098*/ ULONGLONG LastExceptionFromRip;
	/*00a0*/ ULONGLONG Cr8;
	/*00a8*/ ULONGLONG MsrGsBase;
	/*00b0*/ ULONGLONG MsrGsSwap;
	/*00b8*/ ULONGLONG MsrStar;
	/*00c0*/ ULONGLONG MsrLStar;
	/*00c8*/ ULONGLONG MsrCStar;
	/*00d0*/ ULONGLONG MsrSyscallMask;
	/*00d8*/ ULONGLONG Xcr0;
	/*00e0*/ ULONGLONG MsrFsBase;
	/*00e8*/ ULONGLONG SpecialPadding0;
	/*00f0*/
};

struct _KSPIN_LOCK_QUEUE {
	/*0000*/ _KSPIN_LOCK_QUEUE * volatile Next;
	/*0008*/ ULONGLONG * volatile Lock;
	/*0010*/
};

struct _KSTACK_CONTROL {
	/*0000*/ ULONGLONG StackBase;
	/*0008*/ ULONGLONG ActualLimit;
	/*0008*/ ULONGLONG StackExpansion : 01; // 0x0000000000000001;
	/*0010*/ _KERNEL_STACK_SEGMENT Previous;
	/*0030*/
};

union _KSTACK_COUNT {
	/*0000*/ LONG Value;
	/*0000*/ ULONG State : 03; // 0x00000007;
	/*0000*/ ULONG StackCount : 29; // 0xfffffff8;
	/*0004*/
};

struct _KSYSTEM_TIME {
	/*0000*/ ULONG LowPart;
	/*0004*/ LONG High1Time;
	/*0008*/ LONG High2Time;
	/*000c*/
};

struct _KTHREAD {
	/*0000*/ _DISPATCHER_HEADER Header;
	/*0018*/ void * SListFaultAddress;
	/*0020*/ ULONGLONG QuantumTarget;
	/*0028*/ void * InitialStack;
	/*0030*/ void * volatile StackLimit;
	/*0038*/ void * StackBase;
	/*0040*/ ULONGLONG ThreadLock;
	/*0048*/ ULONGLONG volatile CycleTime;
	/*0050*/ ULONG CurrentRunTime;
	/*0054*/ ULONG ExpectedRunTime;
	/*0058*/ void * KernelStack;
	/*0060*/ _XSAVE_FORMAT * StateSaveArea;
	/*0068*/ _KSCHEDULING_GROUP * volatile SchedulingGroup;
	/*0070*/ _KWAIT_STATUS_REGISTER WaitRegister;
	/*0071*/ UCHAR volatile Running;
	/*0072*/ UCHAR Alerted[0x2];
	/*0074*/ ULONG AutoBoostActive : 01; // 0x00000001;
	/*0074*/ ULONG ReadyTransition : 01; // 0x00000002;
	/*0074*/ ULONG WaitNext : 01; // 0x00000004;
	/*0074*/ ULONG SystemAffinityActive : 01; // 0x00000008;
	/*0074*/ ULONG Alertable : 01; // 0x00000010;
	/*0074*/ ULONG UserStackWalkActive : 01; // 0x00000020;
	/*0074*/ ULONG ApcInterruptRequest : 01; // 0x00000040;
	/*0074*/ ULONG QuantumEndMigrate : 01; // 0x00000080;
	/*0074*/ ULONG UmsDirectedSwitchEnable : 01; // 0x00000100;
	/*0074*/ ULONG TimerActive : 01; // 0x00000200;
	/*0074*/ ULONG SystemThread : 01; // 0x00000400;
	/*0074*/ ULONG ProcessDetachActive : 01; // 0x00000800;
	/*0074*/ ULONG CalloutActive : 01; // 0x00001000;
	/*0074*/ ULONG ScbReadyQueue : 01; // 0x00002000;
	/*0074*/ ULONG ApcQueueable : 01; // 0x00004000;
	/*0074*/ ULONG ReservedStackInUse : 01; // 0x00008000;
	/*0074*/ ULONG UmsPerformingSyscall : 01; // 0x00010000;
	/*0074*/ ULONG TimerSuspended : 01; // 0x00020000;
	/*0074*/ ULONG SuspendedWaitMode : 01; // 0x00040000;
	/*0074*/ ULONG SuspendSchedulerApcWait : 01; // 0x00080000;
	/*0074*/ ULONG Reserved : 12; // 0xfff00000;
	/*0074*/ LONG MiscFlags;
	/*0078*/ ULONG BamQosLevel : 02; // 0x00000003;
	/*0078*/ ULONG AutoAlignment : 01; // 0x00000004;
	/*0078*/ ULONG DisableBoost : 01; // 0x00000008;
	/*0078*/ ULONG AlertedByThreadId : 01; // 0x00000010;
	/*0078*/ ULONG QuantumDonation : 01; // 0x00000020;
	/*0078*/ ULONG EnableStackSwap : 01; // 0x00000040;
	/*0078*/ ULONG GuiThread : 01; // 0x00000080;
	/*0078*/ ULONG DisableQuantum : 01; // 0x00000100;
	/*0078*/ ULONG ChargeOnlySchedulingGroup : 01; // 0x00000200;
	/*0078*/ ULONG DeferPreemption : 01; // 0x00000400;
	/*0078*/ ULONG QueueDeferPreemption : 01; // 0x00000800;
	/*0078*/ ULONG ForceDeferSchedule : 01; // 0x00001000;
	/*0078*/ ULONG SharedReadyQueueAffinity : 01; // 0x00002000;
	/*0078*/ ULONG FreezeCount : 01; // 0x00004000;
	/*0078*/ ULONG TerminationApcRequest : 01; // 0x00008000;
	/*0078*/ ULONG AutoBoostEntriesExhausted : 01; // 0x00010000;
	/*0078*/ ULONG KernelStackResident : 01; // 0x00020000;
	/*0078*/ ULONG TerminateRequestReason : 02; // 0x000c0000;
	/*0078*/ ULONG ProcessStackCountDecremented : 01; // 0x00100000;
	/*0078*/ ULONG RestrictedGuiThread : 01; // 0x00200000;
	/*0078*/ ULONG VpBackingThread : 01; // 0x00400000;
	/*0078*/ ULONG ThreadFlagsSpare : 01; // 0x00800000;
	/*0078*/ ULONG EtwStackTraceApcInserted : 08; // 0xff000000;
	/*0078*/ LONG volatile ThreadFlags;
	/*007c*/ UCHAR volatile Tag;
	/*007d*/ UCHAR SystemHeteroCpuPolicy;
	/*007e*/ UCHAR UserHeteroCpuPolicy : 07; // 0x7f;
	/*007e*/ UCHAR ExplicitSystemHeteroCpuPolicy : 01; // 0x80;
	/*007f*/ UCHAR Spare0;
	/*0080*/ ULONG SystemCallNumber;
	/*0084*/ ULONG ReadyTime;
	/*0088*/ void * FirstArgument;
	/*0090*/ _KTRAP_FRAME * TrapFrame;
	/*0098*/ _KAPC_STATE ApcState;
	/*0098*/ UCHAR ApcStateFill[0x2b];
	/*00c3*/ CHAR Priority;
	/*00c4*/ ULONG UserIdealProcessor;
	/*00c8*/ LONGLONG volatile WaitStatus;
	/*00d0*/ _KWAIT_BLOCK * WaitBlockList;
	/*00d8*/ _LIST_ENTRY WaitListEntry;
	/*00d8*/ _SINGLE_LIST_ENTRY SwapListEntry;
	/*00e8*/ _DISPATCHER_HEADER * volatile Queue;
	/*00f0*/ void * Teb;
	/*00f8*/ ULONGLONG RelativeTimerBias;
	/*0100*/ _KTIMER Timer;
	/*0140*/ _KWAIT_BLOCK WaitBlock[0x4];
	/*0140*/ UCHAR WaitBlockFill4[0x14];
	/*0154*/ ULONG ContextSwitches;
	/*0140*/ UCHAR WaitBlockFill5[0x44];
	/*0184*/ UCHAR volatile State;
	/*0185*/ CHAR Spare13;
	/*0186*/ UCHAR WaitIrql;
	/*0187*/ CHAR WaitMode;
	/*0140*/ UCHAR WaitBlockFill6[0x74];
	/*01b4*/ ULONG WaitTime;
	/*0140*/ UCHAR WaitBlockFill7[0xa4];
	/*01e4*/ SHORT KernelApcDisable;
	/*01e6*/ SHORT SpecialApcDisable;
	/*01e4*/ ULONG CombinedApcDisable;
	/*0140*/ UCHAR WaitBlockFill8[0x28];
	/*0168*/ _KTHREAD_COUNTERS * ThreadCounters;
	/*0140*/ UCHAR WaitBlockFill9[0x58];
	/*0198*/ _XSTATE_SAVE * XStateSave;
	/*0140*/ UCHAR WaitBlockFill10[0x88];
	/*01c8*/ void * volatile Win32Thread;
	/*0140*/ UCHAR WaitBlockFill11[0xb0];
	/*01f0*/ _UMS_CONTROL_BLOCK * Ucb;
	/*01f8*/ _KUMS_CONTEXT_HEADER * volatile Uch;
	/*0200*/ void * Spare21;
	/*0208*/ _LIST_ENTRY QueueListEntry;
	/*0218*/ ULONG volatile NextProcessor;
	/*0218*/ ULONG NextProcessorNumber : 31; // 0x7fffffff;
	/*0218*/ ULONG SharedReadyQueue : 01; // 0x80000000;
	/*021c*/ LONG QueuePriority;
	/*0220*/ _KPROCESS * Process;
	/*0228*/ _GROUP_AFFINITY UserAffinity;
	/*0228*/ UCHAR UserAffinityFill[0xa];
	/*0232*/ CHAR PreviousMode;
	/*0233*/ CHAR BasePriority;
	/*0234*/ CHAR PriorityDecrement;
	/*0234*/ UCHAR ForegroundBoost : 04; // 0x0f;
	/*0234*/ UCHAR UnusualBoost : 04; // 0xf0;
	/*0235*/ UCHAR Preempted;
	/*0236*/ UCHAR AdjustReason;
	/*0237*/ CHAR AdjustIncrement;
	/*0238*/ ULONGLONG AffinityVersion;
	/*0240*/ _GROUP_AFFINITY Affinity;
	/*0240*/ UCHAR AffinityFill[0xa];
	/*024a*/ UCHAR ApcStateIndex;
	/*024b*/ UCHAR WaitBlockCount;
	/*024c*/ ULONG IdealProcessor;
	/*0250*/ ULONGLONG NpxState;
	/*0258*/ _KAPC_STATE SavedApcState;
	/*0258*/ UCHAR SavedApcStateFill[0x2b];
	/*0283*/ UCHAR WaitReason;
	/*0284*/ CHAR SuspendCount;
	/*0285*/ CHAR Saturation;
	/*0286*/ USHORT SListFaultCount;
	/*0288*/ _KAPC SchedulerApc;
	/*0288*/ UCHAR SchedulerApcFill0[0x1];
	/*0289*/ UCHAR ResourceIndex;
	/*0288*/ UCHAR SchedulerApcFill1[0x3];
	/*028b*/ UCHAR QuantumReset;
	/*0288*/ UCHAR SchedulerApcFill2[0x4];
	/*028c*/ ULONG KernelTime;
	/*0288*/ UCHAR SchedulerApcFill3[0x40];
	/*02c8*/ _KPRCB * volatile WaitPrcb;
	/*0288*/ UCHAR SchedulerApcFill4[0x48];
	/*02d0*/ void * LegoData;
	/*0288*/ UCHAR SchedulerApcFill5[0x53];
	/*02db*/ UCHAR CallbackNestingLevel;
	/*02dc*/ ULONG UserTime;
	/*02e0*/ _KEVENT SuspendEvent;
	/*02f8*/ _LIST_ENTRY ThreadListEntry;
	/*0308*/ _LIST_ENTRY MutantListHead;
	/*0318*/ UCHAR AbEntrySummary;
	/*0319*/ UCHAR AbWaitEntryCount;
	/*031a*/ UCHAR AbAllocationRegionCount;
	/*031b*/ UCHAR Spare20;
	/*031c*/ ULONG SecureThreadCookie;
	/*0320*/ _KLOCK_ENTRY LockEntries[0x6];
	/*0560*/ _SINGLE_LIST_ENTRY PropagateBoostsEntry;
	/*0568*/ _SINGLE_LIST_ENTRY IoSelfBoostsEntry;
	/*0570*/ UCHAR PriorityFloorCounts[0x10];
	/*0580*/ ULONG PriorityFloorSummary;
	/*0584*/ LONG volatile AbCompletedIoBoostCount;
	/*0588*/ LONG volatile AbCompletedIoQoSBoostCount;
	/*058c*/ SHORT volatile KeReferenceCount;
	/*058e*/ UCHAR AbOrphanedEntrySummary;
	/*058f*/ UCHAR AbOwnedEntryCount;
	/*0590*/ ULONG ForegroundLossTime;
	/*0598*/ _LIST_ENTRY GlobalForegroundListEntry;
	/*0598*/ _SINGLE_LIST_ENTRY ForegroundDpcStackListEntry;
	/*05a0*/ ULONGLONG InGlobalForegroundList;
	/*05a8*/ LONGLONG ReadOperationCount;
	/*05b0*/ LONGLONG WriteOperationCount;
	/*05b8*/ LONGLONG OtherOperationCount;
	/*05c0*/ LONGLONG ReadTransferCount;
	/*05c8*/ LONGLONG WriteTransferCount;
	/*05d0*/ LONGLONG OtherTransferCount;
	/*05d8*/ _KSCB * QueuedScb;
	/*05e0*/ ULONG volatile ThreadTimerDelay;
	/*05e4*/ LONG volatile ThreadFlags2;
	/*05e4*/ ULONG PpmPolicy : 02; // 0x00000003;
	/*05e4*/ ULONG ThreadFlags2Reserved : 30; // 0xfffffffc;
	/*05e8*/ void * SchedulerAssist;
	/*05f0*/
};

struct _KTHREAD_COUNTERS {
	/*0000*/ ULONGLONG WaitReasonBitMap;
	/*0008*/ _THREAD_PERFORMANCE_DATA * UserData;
	/*0010*/ ULONG Flags;
	/*0014*/ ULONG ContextSwitches;
	/*0018*/ ULONGLONG CycleTimeBias;
	/*0020*/ ULONGLONG HardwareCounters;
	/*0028*/ _COUNTER_READING HwCounter[0x10];
	/*01a8*/
};

enum _KTHREAD_PPM_POLICY {
	ThreadPpmDefault = 0x0,
	ThreadPpmThrottle = 0x1,
	ThreadPpmSemiThrottle = 0x2,
	ThreadPpmNoThrottle = 0x3,
	MaxThreadPpmPolicy = 0x4
};

enum _KTHREAD_STATE {
	Initialized = 0x0,
	Ready = 0x1,
	Running = 0x2,
	Standby = 0x3,
	Terminated = 0x4,
	Waiting = 0x5,
	Transition = 0x6,
	DeferredReady = 0x7,
	GateWaitObsolete = 0x8,
	WaitingForProcessInSwap = 0x9
};

enum _KTHREAD_TAG {
	KThreadTagNone = 0x0,
	KThreadTagMediaBuffering = 0x1,
	KThreadTagMax = 0x2
};

struct _KTIMER {
	/*0000*/ _DISPATCHER_HEADER Header;
	/*0018*/ _ULARGE_INTEGER DueTime;
	/*0020*/ _LIST_ENTRY TimerListEntry;
	/*0030*/ _KDPC * Dpc;
	/*0038*/ ULONG Processor;
	/*003c*/ ULONG Period;
	/*0040*/
};

struct _KTIMER2 {
	/*0000*/ _DISPATCHER_HEADER Header;
	/*0018*/ _RTL_BALANCED_NODE RbNodes[0x2];
	/*0018*/ _LIST_ENTRY ListEntry;
	/*0048*/ ULONGLONG DueTime[0x2];
	/*0058*/ LONGLONG Period;
	/*0060*/ void (* Callback)( _KTIMER2 * , void * );
	/*0068*/ void * CallbackContext;
	/*0070*/ void (* DisableCallback)( void * );
	/*0078*/ void * DisableContext;
	/*0080*/ UCHAR AbsoluteSystemTime;
	/*0081*/ UCHAR TypeFlags;
	/*0081*/ UCHAR Unused : 01; // 0x01;
	/*0081*/ UCHAR IdleResilient : 01; // 0x02;
	/*0081*/ UCHAR HighResolution : 01; // 0x04;
	/*0081*/ UCHAR NoWake : 01; // 0x08;
	/*0081*/ UCHAR Unused1 : 04; // 0xf0;
	/*0082*/ UCHAR CollectionIndex[0x2];
	/*0088*/
};

struct _KTIMER2_COLLECTION {
	/*0000*/ _RTL_RB_TREE Tree;
	/*0010*/ ULONGLONG NextDueTime;
	/*0018*/
};

enum _KTIMER2_COLLECTION_INDEX {
	KTimer2CollectionNoWake = 0x0,
	KTimer2CollectionHr = 0x1,
	KTimer2CollectionFinite = 0x2,
	KTimer2CollectionIr = 0x3,
	KTimer2CollectionNotInserted = 0x10,
	KTimer2CollectionInvalid = 0x14,
	KTimer2CollectionOptional = 0x20,
	KTimer2CollectionMin = 0x0,
	KTimer2CollectionMax = 0x4,
	KTimer2CollectionNode1 = 0x2
};

struct _KTIMER_EXPIRATION_TRACE {
	/*0000*/ ULONGLONG InterruptTime;
	/*0008*/ _LARGE_INTEGER PerformanceCounter;
	/*0010*/
};

struct _KTIMER_TABLE {
	/*0000*/ _KTIMER * TimerExpiry[0x40];
	/*0200*/ _KTIMER_TABLE_ENTRY TimerEntries[0x100];
	/*2200*/
};

struct _KTIMER_TABLE_ENTRY {
	/*0000*/ ULONGLONG Lock;
	/*0008*/ _LIST_ENTRY Entry;
	/*0018*/ _ULARGE_INTEGER Time;
	/*0020*/
};

struct _KTM {
	/*0000*/ ULONG cookie;
	/*0008*/ _KMUTANT Mutex;
	/*0040*/ KTM_STATE State;
	/*0048*/ _KTMOBJECT_NAMESPACE_LINK NamespaceLink;
	/*0070*/ _GUID TmIdentity;
	/*0080*/ ULONG Flags;
	/*0084*/ ULONG VolatileFlags;
	/*0088*/ _UNICODE_STRING LogFileName;
	/*0098*/ _FILE_OBJECT * LogFileObject;
	/*00a0*/ void * MarshallingContext;
	/*00a8*/ void * LogManagementContext;
	/*00b0*/ _KTMOBJECT_NAMESPACE Transactions;
	/*0158*/ _KTMOBJECT_NAMESPACE ResourceManagers;
	/*0200*/ _KMUTANT LsnOrderedMutex;
	/*0238*/ _LIST_ENTRY LsnOrderedList;
	/*0248*/ _LARGE_INTEGER CommitVirtualClock;
	/*0250*/ _FAST_MUTEX CommitVirtualClockMutex;
	/*0288*/ _CLS_LSN BaseLsn;
	/*0290*/ _CLS_LSN CurrentReadLsn;
	/*0298*/ _CLS_LSN LastRecoveredLsn;
	/*02a0*/ void * TmRmHandle;
	/*02a8*/ _KRESOURCEMANAGER * TmRm;
	/*02b0*/ _KEVENT LogFullNotifyEvent;
	/*02c8*/ _WORK_QUEUE_ITEM CheckpointWorkItem;
	/*02e8*/ _CLS_LSN CheckpointTargetLsn;
	/*02f0*/ _WORK_QUEUE_ITEM LogFullCompletedWorkItem;
	/*0310*/ _ERESOURCE LogWriteResource;
	/*0378*/ ULONG LogFlags;
	/*037c*/ LONG LogFullStatus;
	/*0380*/ LONG RecoveryStatus;
	/*0388*/ _CLS_LSN LastCheckBaseLsn;
	/*0390*/ _LIST_ENTRY RestartOrderedList;
	/*03a0*/ _WORK_QUEUE_ITEM OfflineWorkItem;
	/*03c0*/
};

struct _KTMNOTIFICATION_PACKET;

struct _KTMOBJECT_NAMESPACE {
	/*0000*/ _RTL_AVL_TABLE Table;
	/*0068*/ _KMUTANT Mutex;
	/*00a0*/ USHORT LinksOffset;
	/*00a2*/ USHORT GuidOffset;
	/*00a4*/ UCHAR Expired;
	/*00a8*/
};

struct _KTMOBJECT_NAMESPACE_LINK {
	/*0000*/ _RTL_BALANCED_LINKS Links;
	/*0020*/ UCHAR Expired;
	/*0028*/
};

struct _KTRANSACTION {
	/*0000*/ _KEVENT OutcomeEvent;
	/*0018*/ ULONG cookie;
	/*0020*/ _KMUTANT Mutex;
	/*0058*/ _KTRANSACTION * TreeTx;
	/*0060*/ _KTMOBJECT_NAMESPACE_LINK GlobalNamespaceLink;
	/*0088*/ _KTMOBJECT_NAMESPACE_LINK TmNamespaceLink;
	/*00b0*/ _GUID UOW;
	/*00c0*/ _KTRANSACTION_STATE State;
	/*00c4*/ ULONG Flags;
	/*00c8*/ _LIST_ENTRY EnlistmentHead;
	/*00d8*/ ULONG EnlistmentCount;
	/*00dc*/ ULONG RecoverableEnlistmentCount;
	/*00e0*/ ULONG PrePrepareRequiredEnlistmentCount;
	/*00e4*/ ULONG PrepareRequiredEnlistmentCount;
	/*00e8*/ ULONG OutcomeRequiredEnlistmentCount;
	/*00ec*/ ULONG PendingResponses;
	/*00f0*/ _KENLISTMENT * SuperiorEnlistment;
	/*00f8*/ _CLS_LSN LastLsn;
	/*0100*/ _LIST_ENTRY PromotedEntry;
	/*0110*/ _KTRANSACTION * PromoterTransaction;
	/*0118*/ void * PromotePropagation;
	/*0120*/ ULONG IsolationLevel;
	/*0124*/ ULONG IsolationFlags;
	/*0128*/ _LARGE_INTEGER Timeout;
	/*0130*/ _UNICODE_STRING Description;
	/*0140*/ _KTHREAD * RollbackThread;
	/*0148*/ _WORK_QUEUE_ITEM RollbackWorkItem;
	/*0168*/ _KDPC RollbackDpc;
	/*01a8*/ _KTIMER RollbackTimer;
	/*01e8*/ _LIST_ENTRY LsnOrderedEntry;
	/*01f8*/ _KTRANSACTION_OUTCOME Outcome;
	/*0200*/ _KTM * Tm;
	/*0208*/ LONGLONG CommitReservation;
	/*0210*/ _KTRANSACTION_HISTORY TransactionHistory[0xa];
	/*0260*/ ULONG TransactionHistoryCount;
	/*0268*/ void * DTCPrivateInformation;
	/*0270*/ ULONG DTCPrivateInformationLength;
	/*0278*/ _KMUTANT DTCPrivateInformationMutex;
	/*02b0*/ void * PromotedTxSelfHandle;
	/*02b8*/ ULONG PendingPromotionCount;
	/*02c0*/ _KEVENT PromotionCompletedEvent;
	/*02d8*/
};

struct _KTRANSACTION_HISTORY {
	/*0000*/ <unnamed-enum-KTMOH_CommitTransaction_Result> RecordType;
	/*0004*/ ULONG Payload;
	/*0008*/
};

enum _KTRANSACTION_OUTCOME {
	KTxOutcomeUninitialized = 0x0,
	KTxOutcomeUndetermined = 0x1,
	KTxOutcomeCommitted = 0x2,
	KTxOutcomeAborted = 0x3,
	KTxOutcomeUnavailable = 0x4
};

enum _KTRANSACTION_STATE {
	KTransactionUninitialized = 0x0,
	KTransactionActive = 0x1,
	KTransactionPreparing = 0x2,
	KTransactionPrepared = 0x3,
	KTransactionInDoubt = 0x4,
	KTransactionCommitted = 0x5,
	KTransactionAborted = 0x6,
	KTransactionDelegated = 0x7,
	KTransactionPrePreparing = 0x8,
	KTransactionForgotten = 0x9,
	KTransactionRecovering = 0xa,
	KTransactionPrePrepared = 0xb
};

struct _KTRAP_FRAME {
	/*0000*/ ULONGLONG P1Home;
	/*0008*/ ULONGLONG P2Home;
	/*0010*/ ULONGLONG P3Home;
	/*0018*/ ULONGLONG P4Home;
	/*0020*/ ULONGLONG P5;
	/*0028*/ CHAR PreviousMode;
	/*0029*/ UCHAR PreviousIrql;
	/*002a*/ UCHAR FaultIndicator;
	/*002b*/ UCHAR ExceptionActive;
	/*002c*/ ULONG MxCsr;
	/*0030*/ ULONGLONG Rax;
	/*0038*/ ULONGLONG Rcx;
	/*0040*/ ULONGLONG Rdx;
	/*0048*/ ULONGLONG R8;
	/*0050*/ ULONGLONG R9;
	/*0058*/ ULONGLONG R10;
	/*0060*/ ULONGLONG R11;
	/*0068*/ ULONGLONG GsBase;
	/*0068*/ ULONGLONG GsSwap;
	/*0070*/ _M128A Xmm0;
	/*0080*/ _M128A Xmm1;
	/*0090*/ _M128A Xmm2;
	/*00a0*/ _M128A Xmm3;
	/*00b0*/ _M128A Xmm4;
	/*00c0*/ _M128A Xmm5;
	/*00d0*/ ULONGLONG FaultAddress;
	/*00d0*/ ULONGLONG ContextRecord;
	/*00d8*/ ULONGLONG Dr0;
	/*00e0*/ ULONGLONG Dr1;
	/*00e8*/ ULONGLONG Dr2;
	/*00f0*/ ULONGLONG Dr3;
	/*00f8*/ ULONGLONG Dr6;
	/*0100*/ ULONGLONG Dr7;
	/*0108*/ ULONGLONG DebugControl;
	/*0110*/ ULONGLONG LastBranchToRip;
	/*0118*/ ULONGLONG LastBranchFromRip;
	/*0120*/ ULONGLONG LastExceptionToRip;
	/*0128*/ ULONGLONG LastExceptionFromRip;
	/*0130*/ USHORT SegDs;
	/*0132*/ USHORT SegEs;
	/*0134*/ USHORT SegFs;
	/*0136*/ USHORT SegGs;
	/*0138*/ ULONGLONG TrapFrame;
	/*0140*/ ULONGLONG Rbx;
	/*0148*/ ULONGLONG Rdi;
	/*0150*/ ULONGLONG Rsi;
	/*0158*/ ULONGLONG Rbp;
	/*0160*/ ULONGLONG ErrorCode;
	/*0160*/ ULONGLONG ExceptionFrame;
	/*0168*/ ULONGLONG Rip;
	/*0170*/ USHORT SegCs;
	/*0172*/ UCHAR Fill0;
	/*0173*/ UCHAR Logging;
	/*0174*/ USHORT Fill1[0x2];
	/*0178*/ ULONG EFlags;
	/*017c*/ ULONG Fill2;
	/*0180*/ ULONGLONG Rsp;
	/*0188*/ USHORT SegSs;
	/*018a*/ USHORT Fill3;
	/*018c*/ ULONG Fill4;
	/*0190*/
};

struct _KTSS64 {
	/*0000*/ ULONG Reserved0;
	/*0004*/ ULONGLONG Rsp0;
	/*000c*/ ULONGLONG Rsp1;
	/*0014*/ ULONGLONG Rsp2;
	/*001c*/ ULONGLONG Ist[0x8];
	/*005c*/ ULONGLONG Reserved1;
	/*0064*/ USHORT Reserved2;
	/*0066*/ USHORT IoMapBase;
	/*0068*/
};

struct _KUMS_CONTEXT_HEADER {
	/*0000*/ ULONGLONG P1Home;
	/*0008*/ ULONGLONG P2Home;
	/*0010*/ ULONGLONG P3Home;
	/*0018*/ ULONGLONG P4Home;
	/*0020*/ void * StackTop;
	/*0028*/ ULONGLONG StackSize;
	/*0030*/ ULONGLONG RspOffset;
	/*0038*/ ULONGLONG Rip;
	/*0040*/ _XSAVE_FORMAT * FltSave;
	/*0048*/ ULONGLONG Volatile : 01; // 0x0000000000000001;
	/*0048*/ ULONGLONG Reserved : 63; // 0xfffffffffffffffe;
	/*0048*/ ULONGLONG Flags;
	/*0050*/ _KTRAP_FRAME * TrapFrame;
	/*0058*/ _KEXCEPTION_FRAME * ExceptionFrame;
	/*0060*/ _KTHREAD * SourceThread;
	/*0068*/ ULONGLONG Return;
	/*0070*/
};

struct _KUSER_SHARED_DATA {
	/*0000*/ ULONG TickCountLowDeprecated;
	/*0004*/ ULONG TickCountMultiplier;
	/*0008*/ _KSYSTEM_TIME volatile InterruptTime;
	/*0014*/ _KSYSTEM_TIME volatile SystemTime;
	/*0020*/ _KSYSTEM_TIME volatile TimeZoneBias;
	/*002c*/ USHORT ImageNumberLow;
	/*002e*/ USHORT ImageNumberHigh;
	/*0030*/ WCHAR NtSystemRoot[0x104];
	/*0238*/ ULONG MaxStackTraceDepth;
	/*023c*/ ULONG CryptoExponent;
	/*0240*/ ULONG TimeZoneId;
	/*0244*/ ULONG LargePageMinimum;
	/*0248*/ ULONG AitSamplingValue;
	/*024c*/ ULONG AppCompatFlag;
	/*0250*/ ULONGLONG RNGSeedVersion;
	/*0258*/ ULONG GlobalValidationRunlevel;
	/*025c*/ LONG volatile TimeZoneBiasStamp;
	/*0260*/ ULONG NtBuildNumber;
	/*0264*/ _NT_PRODUCT_TYPE NtProductType;
	/*0268*/ UCHAR ProductTypeIsValid;
	/*0269*/ UCHAR Reserved0[0x1];
	/*026a*/ USHORT NativeProcessorArchitecture;
	/*026c*/ ULONG NtMajorVersion;
	/*0270*/ ULONG NtMinorVersion;
	/*0274*/ UCHAR ProcessorFeatures[0x40];
	/*02b4*/ ULONG Reserved1;
	/*02b8*/ ULONG Reserved3;
	/*02bc*/ ULONG volatile TimeSlip;
	/*02c0*/ _ALTERNATIVE_ARCHITECTURE_TYPE AlternativeArchitecture;
	/*02c4*/ ULONG BootId;
	/*02c8*/ _LARGE_INTEGER SystemExpirationDate;
	/*02d0*/ ULONG SuiteMask;
	/*02d4*/ UCHAR KdDebuggerEnabled;
	/*02d5*/ UCHAR MitigationPolicies;
	/*02d5*/ UCHAR NXSupportPolicy : 02; // 0x03;
	/*02d5*/ UCHAR SEHValidationPolicy : 02; // 0x0c;
	/*02d5*/ UCHAR CurDirDevicesSkippedForDlls : 02; // 0x30;
	/*02d5*/ UCHAR Reserved : 02; // 0xc0;
	/*02d6*/ UCHAR Reserved6[0x2];
	/*02d8*/ ULONG volatile ActiveConsoleId;
	/*02dc*/ ULONG volatile DismountCount;
	/*02e0*/ ULONG ComPlusPackage;
	/*02e4*/ ULONG LastSystemRITEventTickCount;
	/*02e8*/ ULONG NumberOfPhysicalPages;
	/*02ec*/ UCHAR SafeBootMode;
	/*02ed*/ UCHAR VirtualizationFlags;
	/*02ee*/ UCHAR Reserved12[0x2];
	/*02f0*/ ULONG SharedDataFlags;
	/*02f0*/ ULONG DbgErrorPortPresent : 01; // 0x00000001;
	/*02f0*/ ULONG DbgElevationEnabled : 01; // 0x00000002;
	/*02f0*/ ULONG DbgVirtEnabled : 01; // 0x00000004;
	/*02f0*/ ULONG DbgInstallerDetectEnabled : 01; // 0x00000008;
	/*02f0*/ ULONG DbgLkgEnabled : 01; // 0x00000010;
	/*02f0*/ ULONG DbgDynProcessorEnabled : 01; // 0x00000020;
	/*02f0*/ ULONG DbgConsoleBrokerEnabled : 01; // 0x00000040;
	/*02f0*/ ULONG DbgSecureBootEnabled : 01; // 0x00000080;
	/*02f0*/ ULONG DbgMultiSessionSku : 01; // 0x00000100;
	/*02f0*/ ULONG DbgMultiUsersInSessionSku : 01; // 0x00000200;
	/*02f0*/ ULONG DbgStateSeparationEnabled : 01; // 0x00000400;
	/*02f0*/ ULONG SpareBits : 21; // 0xfffff800;
	/*02f4*/ ULONG DataFlagsPad[0x1];
	/*02f8*/ ULONGLONG TestRetInstruction;
	/*0300*/ LONGLONG QpcFrequency;
	/*0308*/ ULONG SystemCall;
	/*030c*/ ULONG SystemCallPad0;
	/*0310*/ ULONGLONG SystemCallPad[0x2];
	/*0320*/ _KSYSTEM_TIME volatile TickCount;
	/*0320*/ ULONGLONG volatile TickCountQuad;
	/*0320*/ ULONG ReservedTickCountOverlay[0x3];
	/*032c*/ ULONG TickCountPad[0x1];
	/*0330*/ ULONG Cookie;
	/*0334*/ ULONG CookiePad[0x1];
	/*0338*/ LONGLONG ConsoleSessionForegroundProcessId;
	/*0340*/ ULONGLONG TimeUpdateLock;
	/*0348*/ ULONGLONG BaselineSystemTimeQpc;
	/*0350*/ ULONGLONG BaselineInterruptTimeQpc;
	/*0358*/ ULONGLONG QpcSystemTimeIncrement;
	/*0360*/ ULONGLONG QpcInterruptTimeIncrement;
	/*0368*/ UCHAR QpcSystemTimeIncrementShift;
	/*0369*/ UCHAR QpcInterruptTimeIncrementShift;
	/*036a*/ USHORT UnparkedProcessorCount;
	/*036c*/ ULONG EnclaveFeatureMask[0x4];
	/*037c*/ ULONG TelemetryCoverageRound;
	/*0380*/ USHORT UserModeGlobalLogger[0x10];
	/*03a0*/ ULONG ImageFileExecutionOptions;
	/*03a4*/ ULONG LangGenerationCount;
	/*03a8*/ ULONGLONG Reserved4;
	/*03b0*/ ULONGLONG volatile InterruptTimeBias;
	/*03b8*/ ULONGLONG volatile QpcBias;
	/*03c0*/ ULONG ActiveProcessorCount;
	/*03c4*/ UCHAR volatile ActiveGroupCount;
	/*03c5*/ UCHAR Reserved9;
	/*03c6*/ USHORT QpcData;
	/*03c6*/ UCHAR volatile QpcBypassEnabled;
	/*03c7*/ UCHAR QpcShift;
	/*03c8*/ _LARGE_INTEGER TimeZoneBiasEffectiveStart;
	/*03d0*/ _LARGE_INTEGER TimeZoneBiasEffectiveEnd;
	/*03d8*/ _XSTATE_CONFIGURATION XState;
	/*0708*/
};

struct _KWAIT_BLOCK {
	/*0000*/ _LIST_ENTRY WaitListEntry;
	/*0010*/ UCHAR WaitType;
	/*0011*/ UCHAR volatile BlockState;
	/*0012*/ USHORT WaitKey;
	/*0014*/ LONG SpareLong;
	/*0018*/ _KTHREAD * Thread;
	/*0018*/ _KQUEUE * NotificationQueue;
	/*0020*/ void * Object;
	/*0028*/ void * SparePtr;
	/*0030*/
};

enum _KWAIT_BLOCK_STATE {
	WaitBlockBypassStart = 0x0,
	WaitBlockBypassComplete = 0x1,
	WaitBlockSuspendBypassStart = 0x2,
	WaitBlockSuspendBypassComplete = 0x3,
	WaitBlockActive = 0x4,
	WaitBlockInactive = 0x5,
	WaitBlockSuspended = 0x6,
	WaitBlockAllStates = 0x7
};

struct _KWAIT_CHAIN {
	/*0000*/ void * Head;
	/*0008*/
};

struct _KWAIT_CHAIN_ENTRY {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _KEVENT Event;
	/*0028*/
};

enum _KWAIT_REASON {
	Executive = 0x0,
	FreePage = 0x1,
	PageIn = 0x2,
	PoolAllocation = 0x3,
	DelayExecution = 0x4,
	Suspended = 0x5,
	UserRequest = 0x6,
	WrExecutive = 0x7,
	WrFreePage = 0x8,
	WrPageIn = 0x9,
	WrPoolAllocation = 0xa,
	WrDelayExecution = 0xb,
	WrSuspended = 0xc,
	WrUserRequest = 0xd,
	WrSpare0 = 0xe,
	WrQueue = 0xf,
	WrLpcReceive = 0x10,
	WrLpcReply = 0x11,
	WrVirtualMemory = 0x12,
	WrPageOut = 0x13,
	WrRendezvous = 0x14,
	WrKeyedEvent = 0x15,
	WrTerminated = 0x16,
	WrProcessInSwap = 0x17,
	WrCpuRateControl = 0x18,
	WrCalloutStack = 0x19,
	WrKernel = 0x1a,
	WrResource = 0x1b,
	WrPushLock = 0x1c,
	WrMutex = 0x1d,
	WrQuantumEnd = 0x1e,
	WrDispatchInt = 0x1f,
	WrPreempted = 0x20,
	WrYieldExecution = 0x21,
	WrFastMutex = 0x22,
	WrGuardedMutex = 0x23,
	WrRundown = 0x24,
	WrAlertByThreadId = 0x25,
	WrDeferredPreempt = 0x26,
	WrPhysicalFault = 0x27,
	MaximumWaitReason = 0x28
};

enum _KWAIT_STATE {
	WaitInProgress = 0x0,
	WaitCommitted = 0x1,
	WaitAborted = 0x2,
	WaitSuspendInProgress = 0x3,
	WaitSuspended = 0x4,
	WaitResumeInProgress = 0x5,
	WaitResumeAborted = 0x6,
	WaitFirstSuspendState = 0x3,
	WaitLastSuspendState = 0x6,
	MaximumWaitState = 0x7
};

union _KWAIT_STATUS_REGISTER {
	/*0000*/ UCHAR Flags;
	/*0000*/ UCHAR State : 03; // 0x07;
	/*0000*/ UCHAR Affinity : 01; // 0x08;
	/*0000*/ UCHAR Priority : 01; // 0x10;
	/*0000*/ UCHAR Apc : 01; // 0x20;
	/*0000*/ UCHAR UserApc : 01; // 0x40;
	/*0000*/ UCHAR Alert : 01; // 0x80;
	/*0001*/
};

union _LARGE_INTEGER {
	/*0000*/ ULONG LowPart;
	/*0004*/ LONG HighPart;
	struct {
		/*0000*/ ULONG LowPart;
		/*0004*/ LONG HighPart;
		/*0008*/
	} u;
	/*0000*/ LONGLONG QuadPart;
	/*0008*/
};

struct _LAZY_WRITER {
	/*0000*/ _KDPC ScanDpc;
	/*0040*/ _KTIMER ScanTimer;
	/*0080*/ UCHAR ScanActive;
	/*0081*/ UCHAR OtherWork;
	/*0082*/ UCHAR PendingTeardownScan;
	/*0083*/ UCHAR PendingPeriodicScan;
	/*0084*/ UCHAR PendingLowMemoryScan;
	/*0085*/ UCHAR PendingPowerScan;
	/*0086*/ UCHAR PendingCoalescingFlushScan;
	/*0088*/
};

struct _LDRP_CSLIST {
	/*0000*/ _SINGLE_LIST_ENTRY * Tail;
	/*0008*/
};

struct _LDRP_LOAD_CONTEXT;

struct _LDR_DATA_TABLE_ENTRY {
	/*0000*/ _LIST_ENTRY InLoadOrderLinks;
	/*0010*/ _LIST_ENTRY InMemoryOrderLinks;
	/*0020*/ _LIST_ENTRY InInitializationOrderLinks;
	/*0030*/ void * DllBase;
	/*0038*/ void * EntryPoint;
	/*0040*/ ULONG SizeOfImage;
	/*0048*/ _UNICODE_STRING FullDllName;
	/*0058*/ _UNICODE_STRING BaseDllName;
	/*0068*/ UCHAR FlagGroup[0x4];
	/*0068*/ ULONG Flags;
	/*0068*/ ULONG PackagedBinary : 01; // 0x00000001;
	/*0068*/ ULONG MarkedForRemoval : 01; // 0x00000002;
	/*0068*/ ULONG ImageDll : 01; // 0x00000004;
	/*0068*/ ULONG LoadNotificationsSent : 01; // 0x00000008;
	/*0068*/ ULONG TelemetryEntryProcessed : 01; // 0x00000010;
	/*0068*/ ULONG ProcessStaticImport : 01; // 0x00000020;
	/*0068*/ ULONG InLegacyLists : 01; // 0x00000040;
	/*0068*/ ULONG InIndexes : 01; // 0x00000080;
	/*0068*/ ULONG ShimDll : 01; // 0x00000100;
	/*0068*/ ULONG InExceptionTable : 01; // 0x00000200;
	/*0068*/ ULONG ReservedFlags1 : 02; // 0x00000c00;
	/*0068*/ ULONG LoadInProgress : 01; // 0x00001000;
	/*0068*/ ULONG LoadConfigProcessed : 01; // 0x00002000;
	/*0068*/ ULONG EntryProcessed : 01; // 0x00004000;
	/*0068*/ ULONG ProtectDelayLoad : 01; // 0x00008000;
	/*0068*/ ULONG ReservedFlags3 : 02; // 0x00030000;
	/*0068*/ ULONG DontCallForThreads : 01; // 0x00040000;
	/*0068*/ ULONG ProcessAttachCalled : 01; // 0x00080000;
	/*0068*/ ULONG ProcessAttachFailed : 01; // 0x00100000;
	/*0068*/ ULONG CorDeferredValidate : 01; // 0x00200000;
	/*0068*/ ULONG CorImage : 01; // 0x00400000;
	/*0068*/ ULONG DontRelocate : 01; // 0x00800000;
	/*0068*/ ULONG CorILOnly : 01; // 0x01000000;
	/*0068*/ ULONG ReservedFlags5 : 03; // 0x0e000000;
	/*0068*/ ULONG Redirected : 01; // 0x10000000;
	/*0068*/ ULONG ReservedFlags6 : 02; // 0x60000000;
	/*0068*/ ULONG CompatDatabaseProcessed : 01; // 0x80000000;
	/*006c*/ USHORT ObsoleteLoadCount;
	/*006e*/ USHORT TlsIndex;
	/*0070*/ _LIST_ENTRY HashLinks;
	/*0080*/ ULONG TimeDateStamp;
	/*0088*/ _ACTIVATION_CONTEXT * EntryPointActivationContext;
	/*0090*/ void * Lock;
	/*0098*/ _LDR_DDAG_NODE * DdagNode;
	/*00a0*/ _LIST_ENTRY NodeModuleLink;
	/*00b0*/ _LDRP_LOAD_CONTEXT * LoadContext;
	/*00b8*/ void * ParentDllBase;
	/*00c0*/ void * SwitchBackContext;
	/*00c8*/ _RTL_BALANCED_NODE BaseAddressIndexNode;
	/*00e0*/ _RTL_BALANCED_NODE MappingInfoIndexNode;
	/*00f8*/ ULONGLONG OriginalBase;
	/*0100*/ _LARGE_INTEGER LoadTime;
	/*0108*/ ULONG BaseNameHashValue;
	/*010c*/ _LDR_DLL_LOAD_REASON LoadReason;
	/*0110*/ ULONG ImplicitPathOptions;
	/*0114*/ ULONG ReferenceCount;
	/*0118*/ ULONG DependentLoadFlags;
	/*011c*/ UCHAR SigningLevel;
	/*0120*/
};

struct _LDR_DDAG_NODE {
	/*0000*/ _LIST_ENTRY Modules;
	/*0010*/ _LDR_SERVICE_TAG_RECORD * ServiceTagList;
	/*0018*/ ULONG LoadCount;
	/*001c*/ ULONG LoadWhileUnloadingCount;
	/*0020*/ ULONG LowestLink;
	/*0028*/ _LDRP_CSLIST Dependencies;
	/*0030*/ _LDRP_CSLIST IncomingDependencies;
	/*0038*/ _LDR_DDAG_STATE State;
	/*0040*/ _SINGLE_LIST_ENTRY CondenseLink;
	/*0048*/ ULONG PreorderNumber;
	/*0050*/
};

enum _LDR_DDAG_STATE {
	LdrModulesMerged = 0xfffffffb,
	LdrModulesInitError = 0xfffffffc,
	LdrModulesSnapError = 0xfffffffd,
	LdrModulesUnloaded = 0xfffffffe,
	LdrModulesUnloading = 0xffffffff,
	LdrModulesPlaceHolder = 0x0,
	LdrModulesMapping = 0x1,
	LdrModulesMapped = 0x2,
	LdrModulesWaitingForDependencies = 0x3,
	LdrModulesSnapping = 0x4,
	LdrModulesSnapped = 0x5,
	LdrModulesCondensed = 0x6,
	LdrModulesReadyToInit = 0x7,
	LdrModulesInitializing = 0x8,
	LdrModulesReadyToRun = 0x9
};

enum _LDR_DLL_LOAD_REASON {
	LoadReasonStaticDependency = 0x0,
	LoadReasonStaticForwarderDependency = 0x1,
	LoadReasonDynamicForwarderDependency = 0x2,
	LoadReasonDelayloadDependency = 0x3,
	LoadReasonDynamicLoad = 0x4,
	LoadReasonAsImageLoad = 0x5,
	LoadReasonAsDataLoad = 0x6,
	LoadReasonEnclavePrimary = 0x7,
	LoadReasonEnclaveDependency = 0x8,
	LoadReasonUnknown = 0xffffffff
};

struct _LDR_SERVICE_TAG_RECORD {
	/*0000*/ _LDR_SERVICE_TAG_RECORD * Next;
	/*0008*/ ULONG ServiceTag;
	/*0010*/
};

struct _LEARNING_MODE_DATA {
	/*0000*/ ULONG Settings;
	/*0004*/ UCHAR Enabled;
	/*0005*/ UCHAR PermissiveModeEnabled;
	/*0008*/
};

struct _LIST_ENTRY {
	/*0000*/ _LIST_ENTRY * Flink;
	/*0008*/ _LIST_ENTRY * Blink;
	/*0010*/
};

struct _LOCK_HEADER {
	/*0000*/ _RTL_AVL_TREE LockTree;
	/*0008*/ _RTL_AVL_TREE LockMdlSwitchedTree;
	/*0010*/ ULONGLONG Count;
	/*0018*/ ULONGLONG Lock;
	/*0020*/ ULONG Valid;
	/*0028*/
};

enum _LOCK_OPERATION {
	IoReadAccess = 0x0,
	IoWriteAccess = 0x1,
	IoModifyAccess = 0x2
};

struct _LOCK_TRACKER {
	/*0000*/ _RTL_BALANCED_NODE LockTrackerNode;
	/*0018*/ _MDL * Mdl;
	/*0020*/ void * StartVa;
	/*0028*/ ULONGLONG Count;
	/*0030*/ ULONG Offset;
	/*0034*/ ULONG Length;
	/*0038*/ ULONG Who;
	/*003c*/ ULONG Hash;
	/*0040*/ ULONGLONG Page;
	/*0048*/ void * StackTrace[0x8];
	/*0088*/ _EPROCESS * Process;
	/*0090*/
};

struct _LOGGED_STREAM_CALLBACK_V1 {
	/*0000*/ void * LogHandle;
	/*0008*/ void (* FlushToLsnRoutine)( void * , _LARGE_INTEGER );
	/*0010*/
};

struct _LOGGED_STREAM_CALLBACK_V2 {
	/*0000*/ _LOG_HANDLE_CONTEXT * LogHandleContext;
	/*0008*/
};

struct _LOG_HANDLE_CONTEXT {
	/*0000*/ void * LogHandle;
	/*0008*/ void (* FlushToLsnRoutine)( void * , _LARGE_INTEGER );
	/*0010*/ void (* QueryLogHandleInfoRoutine)( void * , USHORT * );
	/*0018*/ _DIRTY_PAGE_STATISTICS DirtyPageStatistics;
	/*0030*/ _DIRTY_PAGE_THRESHOLDS DirtyPageThresholds;
	/*0068*/ ULONG AdditionalPagesToWrite;
	/*006c*/ ULONG CcLWScanDPThreshold;
	/*0070*/ _LARGE_INTEGER LargestLsnForCurrentLWScan;
	/*0078*/ _FILE_OBJECT * RelatedFileObject;
	/*0080*/ ULONGLONG LargestLsnFileObjectKey;
	/*0088*/ _LARGE_INTEGER LastLWTimeStamp;
	/*0090*/ ULONG Flags;
	/*0098*/
};

struct _LOOKASIDE_LIST_EX {
	/*0000*/ _GENERAL_LOOKASIDE_POOL L;
	/*0060*/
};

struct _LPCP_MESSAGE {
	/*0000*/ _LIST_ENTRY Entry;
	/*0000*/ _SINGLE_LIST_ENTRY FreeEntry;
	/*0008*/ ULONG Reserved0;
	/*0010*/ void * SenderPort;
	/*0018*/ _ETHREAD * RepliedToThread;
	/*0020*/ void * PortContext;
	/*0028*/ _PORT_MESSAGE Request;
	/*0050*/
};

struct _LPCP_NONPAGED_PORT_QUEUE {
	/*0000*/ _KSEMAPHORE Semaphore;
	/*0020*/ _LPCP_PORT_OBJECT * BackPointer;
	/*0028*/
};

struct _LPCP_PORT_OBJECT {
	/*0000*/ _LPCP_PORT_OBJECT * ConnectionPort;
	/*0008*/ _LPCP_PORT_OBJECT * ConnectedPort;
	/*0010*/ _LPCP_PORT_QUEUE MsgQueue;
	/*0030*/ _CLIENT_ID Creator;
	/*0040*/ void * ClientSectionBase;
	/*0048*/ void * ServerSectionBase;
	/*0050*/ void * PortContext;
	/*0058*/ _ETHREAD * ClientThread;
	/*0060*/ _SECURITY_QUALITY_OF_SERVICE SecurityQos;
	/*0070*/ _SECURITY_CLIENT_CONTEXT StaticSecurity;
	/*00b8*/ _LIST_ENTRY LpcReplyChainHead;
	/*00c8*/ _LIST_ENTRY LpcDataInfoChainHead;
	/*00d8*/ _EPROCESS * ServerProcess;
	/*00d8*/ _EPROCESS * MappingProcess;
	/*00e0*/ USHORT MaxMessageLength;
	/*00e2*/ USHORT MaxConnectionInfoLength;
	/*00e4*/ ULONG Flags;
	/*00e8*/ _KEVENT WaitEvent;
	/*0100*/
};

struct _LPCP_PORT_QUEUE {
	/*0000*/ _LPCP_NONPAGED_PORT_QUEUE * NonPagedPortQueue;
	/*0008*/ _KSEMAPHORE * Semaphore;
	/*0010*/ _LIST_ENTRY ReceiveHead;
	/*0020*/
};

struct _LUID {
	/*0000*/ ULONG LowPart;
	/*0004*/ LONG HighPart;
	/*0008*/
};

struct _LUID_AND_ATTRIBUTES {
	/*0000*/ _LUID Luid;
	/*0008*/ ULONG Attributes;
	/*000c*/
};

struct _M128A {
	/*0000*/ ULONGLONG Low;
	/*0008*/ LONGLONG High;
	/*0010*/
};

struct _MAILSLOT_CREATE_PARAMETERS {
	/*0000*/ ULONG MailslotQuota;
	/*0004*/ ULONG MaximumMessageSize;
	/*0008*/ _LARGE_INTEGER ReadTimeout;
	/*0010*/ UCHAR TimeoutSpecified;
	/*0018*/
};

struct _MAPPED_FILE_SEGMENT {
	/*0000*/ _CONTROL_AREA * ControlArea;
	/*0008*/ ULONG TotalNumberOfPtes;
	/*000c*/ _SEGMENT_FLAGS SegmentFlags;
	/*0010*/ ULONGLONG NumberOfCommittedPages;
	/*0018*/ ULONGLONG SizeOfSegment;
	/*0020*/ _MMEXTEND_INFO * ExtendInfo;
	/*0020*/ void * BasedAddress;
	/*0028*/ _EX_PUSH_LOCK SegmentLock;
	/*0030*/
};

struct _MBCB {
	/*0000*/ SHORT NodeTypeCode;
	/*0002*/ SHORT NodeIsInZone;
	/*0004*/ ULONG PagesToWrite;
	/*0008*/ ULONG DirtyPages;
	/*000c*/ ULONG Reserved;
	/*0010*/ _LIST_ENTRY BitmapRanges;
	/*0020*/ LONGLONG ResumeWritePage;
	/*0028*/ LONGLONG MostRecentlyDirtiedPage;
	/*0030*/ _BITMAP_RANGE BitmapRange1;
	/*0060*/ _BITMAP_RANGE BitmapRange2;
	/*0090*/ _BITMAP_RANGE BitmapRange3;
	/*00c0*/
};

struct _MCGEN_TRACE_CONTEXT {
	/*0000*/ ULONGLONG RegistrationHandle;
	/*0008*/ ULONGLONG Logger;
	/*0010*/ ULONGLONG MatchAnyKeyword;
	/*0018*/ ULONGLONG MatchAllKeyword;
	/*0020*/ ULONG Flags;
	/*0024*/ ULONG IsEnabled;
	/*0028*/ UCHAR Level;
	/*0029*/ UCHAR Reserve;
	/*002a*/ USHORT EnableBitsCount;
	/*0030*/ ULONG * EnableBitMask;
	/*0038*/ ULONGLONG const * EnableKeyWords;
	/*0040*/ UCHAR const * EnableLevel;
	/*0048*/
};

struct _MDL {
	/*0000*/ _MDL * Next;
	/*0008*/ SHORT Size;
	/*000a*/ SHORT MdlFlags;
	/*000c*/ USHORT AllocationProcessorNumber;
	/*000e*/ USHORT Reserved;
	/*0010*/ _EPROCESS * Process;
	/*0018*/ void * MappedSystemVa;
	/*0020*/ void * StartVa;
	/*0028*/ ULONG ByteCount;
	/*002c*/ ULONG ByteOffset;
	/*0030*/
};

struct _MEMORY_ALLOCATION_DESCRIPTOR {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _TYPE_OF_MEMORY MemoryType;
	/*0018*/ ULONGLONG BasePage;
	/*0020*/ ULONGLONG PageCount;
	/*0028*/
};

enum _MEMORY_CACHING_TYPE {
	MmNonCached = 0x0,
	MmCached = 0x1,
	MmWriteCombined = 0x2,
	MmHardwareCoherentCached = 0x3,
	MmNonCachedUnordered = 0x4,
	MmUSWCCached = 0x5,
	MmMaximumCacheType = 0x6,
	MmNotMapped = 0xffffffff
};

enum _MEMORY_CACHING_TYPE_ORIG {
	MmFrameBufferCached = 0x2
};

struct _MIPFNBLINK {
	/*0000*/ ULONGLONG Blink : 36; // 0x0000000fffffffff;
	/*0000*/ ULONGLONG NodeBlinkHigh : 20; // 0x00fffff000000000;
	/*0000*/ ULONGLONG TbFlushStamp : 04; // 0x0f00000000000000;
	/*0000*/ ULONGLONG Unused : 02; // 0x3000000000000000;
	/*0000*/ ULONGLONG PageBlinkDeleteBit : 01; // 0x4000000000000000;
	/*0000*/ ULONGLONG PageBlinkLockBit : 01; // 0x8000000000000000;
	/*0000*/ ULONGLONG ShareCount : 62; // 0x3fffffffffffffff;
	/*0000*/ ULONGLONG PageShareCountDeleteBit : 01; // 0x4000000000000000;
	/*0000*/ ULONGLONG PageShareCountLockBit : 01; // 0x8000000000000000;
	/*0000*/ ULONGLONG EntireField;
	/*0000*/ LONGLONG volatile Lock;
	/*0000*/ ULONGLONG LockNotUsed : 62; // 0x3fffffffffffffff;
	/*0000*/ ULONGLONG DeleteBit : 01; // 0x4000000000000000;
	/*0000*/ ULONGLONG LockBit : 01; // 0x8000000000000000;
	/*0008*/
};

struct _MI_ACCESS_LOG_STATE {
	/*0000*/ _MM_PAGE_ACCESS_INFO_HEADER * volatile CcAccessLog;
	/*0008*/ _WORK_QUEUE_ITEM DisableAccessLogging;
	/*0028*/ ULONG Enabled;
	/*002c*/ ULONG MinLoggingPriority;
	/*0040*/ ULONGLONG AccessLoggingLock;
	/*0080*/
};

struct _MI_ACTIVE_PFN {
	struct {
		/*0000*/ ULONGLONG Tradable : 01; // 0x0000000000000001;
		/*0000*/ ULONGLONG NonPagedBuddy : 43; // 0x00000ffffffffffe;
		/*0008*/
	} Leaf;
	struct {
		/*0000*/ ULONGLONG Tradable : 01; // 0x0000000000000001;
		/*0000*/ ULONGLONG WsleAge : 03; // 0x000000000000000e;
		/*0000*/ ULONGLONG OldestWsleLeafEntries : 10; // 0x0000000000003ff0;
		/*0000*/ ULONGLONG OldestWsleLeafAge : 03; // 0x000000000001c000;
		/*0000*/ ULONGLONG NonPagedBuddy : 43; // 0x0ffffffffffe0000;
		/*0008*/
	} PageTable;
	/*0000*/ ULONGLONG EntireActiveField;
	/*0008*/
};

struct _MI_ALIGNED_SLIST {
	/*0000*/ _SLIST_HEADER SList;
	/*0040*/
};

enum _MI_ASSIGNED_REGION_TYPES {
	AssignedRegionNonPagedPool = 0x0,
	AssignedRegionPagedPool = 0x1,
	AssignedRegionSystemCache = 0x2,
	AssignedRegionSystemPtes = 0x3,
	AssignedRegionUltraZero = 0x4,
	AssignedRegionPfnDatabase = 0x5,
	AssignedRegionCfg = 0x6,
	AssignedRegionHyperSpace = 0x7,
	AssignedRegionKernelStacks = 0x8,
	AssignedRegionPageTables = 0x9,
	AssignedRegionSpecialPoolPaged = 0xa,
	AssignedRegionSpecialPoolNonPaged = 0xb,
	AssignedRegionSession = 0xc,
	AssignedRegionSystemImages = 0xd,
	AssignedRegionMaximum = 0xe
};

struct _MI_AVAILABLE_PAGE_WAIT_STATES {
	/*0000*/ _KEVENT Event;
	/*0018*/ ULONG EventSets;
	/*0020*/
};

enum _MI_AVAILABLE_PAGE_WAIT_TYPES {
	AvailablePagesWaitLow = 0x0,
	AvailablePagesWaitHigh = 0x1,
	AvailablePagesWaitVeryHigh = 0x2,
	AvailablePagesWaitMaximum = 0x3
};

struct _MI_BAD_MEMORY_EVENT_ENTRY {
	/*0000*/ ULONG BugCheckCode;
	/*0004*/ LONG Active;
	/*0008*/ ULONG Data;
	/*0010*/ _LARGE_INTEGER PhysicalAddress;
	/*0018*/ _WORK_QUEUE_ITEM WorkItem;
	/*0038*/
};

struct _MI_CACHED_PTE {
	/*0000*/ ULONG GlobalTimeStamp;
	/*0004*/ ULONG PteIndex;
	/*0000*/ LONGLONG Long;
	/*0008*/
};

struct _MI_CACHED_PTES {
	/*0000*/ _MI_CACHED_PTE Bins[0x8];
	/*0040*/ LONG CachedPteCount;
	/*0048*/
};

enum _MI_CFG_BITMAP_TYPE {
	CfgBitMapNative = 0x0,
	CfgBitMapWow64 = 0x1,
	CfgBitMapMax = 0x2
};

struct _MI_CLONE_BLOCK_FLAGS {
	/*0000*/ ULONGLONG ActualCloneCommit : 59; // 0x07ffffffffffffff;
	/*0000*/ ULONGLONG CloneProtection : 05; // 0xf800000000000000;
	/*0008*/
};

struct _MI_COMBINE_PAGE_LISTHEAD {
	/*0000*/ _RTL_AVL_TREE Table;
	/*0008*/ LONG volatile Lock;
	/*0010*/
};

struct _MI_COMBINE_STATE {
	/*0000*/ LONG volatile ActiveSpinLock;
	/*0004*/ ULONG CombiningThreadCount;
	/*0008*/ _RTL_AVL_TREE ActiveThreadTree;
	/*0010*/ ULONGLONG ZeroPageHashValue;
	/*0018*/
};

struct _MI_COMBINE_WORKITEM {
	/*0000*/ void * NextEntry;
	/*0008*/ _WORK_QUEUE_ITEM WorkItem;
	/*0028*/
};

struct _MI_COMMON_PAGE_STATE {
	/*0000*/ _MMPFN * PageOfOnesPfn;
	/*0008*/ ULONGLONG PageOfOnes;
	/*0010*/ _MMPFN * DummyPagePfn;
	/*0018*/ ULONGLONG DummyPage;
	/*0020*/ ULONGLONG PageOfZeroes;
	/*0028*/ void * ZeroMapping;
	/*0030*/ void * OnesMapping;
	/*0038*/ ULONGLONG ZeroCrc;
	/*0040*/ ULONGLONG OnesCrc;
	/*0048*/ ULONGLONG BitmapGapFrames[0x4];
	/*0068*/ ULONGLONG PfnGapFrames[0x4];
	/*0088*/ ULONGLONG PageTableOfZeroes;
	/*0090*/ _MMPTE PdeOfZeroes;
	/*0098*/ ULONGLONG PageTableOfOnes;
	/*00a0*/ _MMPTE PdeOfOnes;
	/*00a8*/
};

struct _MI_CONTROL_AREA_WAIT_BLOCK {
	/*0000*/ _MI_CONTROL_AREA_WAIT_BLOCK * Next;
	/*0008*/ ULONG WaitReason;
	/*000c*/ ULONG WaitResponse;
	/*0010*/ _KGATE Gate;
	/*0028*/
};

struct _MI_CROSS_PARTITION_CHARGES {
	/*0000*/ ULONGLONG CurrentCharges;
	/*0008*/ ULONGLONG ChargeFailures;
	/*0010*/ ULONGLONG ChargePeak;
	/*0018*/ ULONGLONG ChargeMinimum;
	/*0020*/
};

enum _MI_CROSS_PARTITION_CHARGE_TYPE {
	MiCrossPartitionSectionResAvailCharge = 0x0,
	MiCrossPartitionSectionCommitCharge = 0x1,
	MiCrossPartitionPageCombineResAvailCharge = 0x2,
	MiCrossPartitionPageCombineCommitCharge = 0x3,
	MiCrossPartitionPageCloneResAvailCharge = 0x4,
	MiCrossPartitionMaximumCharge = 0x5
};

struct _MI_DEBUGGER_STATE {
	/*0000*/ UCHAR TransientWrite;
	/*0001*/ UCHAR CodePageEdited;
	/*0008*/ _MMPTE * DebugPte;
	/*0010*/ ULONG PoisonedTb;
	/*0014*/ LONG volatile InDebugger;
	/*0018*/ void * volatile Pfns[0x20];
	/*0118*/
};

struct _MI_DECAY_TIMER_LINK {
	union {
		/*0000*/ ULONGLONG Long;
		/*0000*/ _MI_DECAY_TIMER_LINKAGE e1;
		/*0008*/
	} u1;
	/*0008*/
};

struct _MI_DECAY_TIMER_LINKAGE {
	/*0000*/ ULONGLONG Spare0 : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG PreviousDecayPfn : 31; // 0x00000000fffffffe;
	/*0000*/ ULONGLONG Spare1 : 01; // 0x0000000100000000;
	/*0000*/ ULONGLONG NextDecayPfn : 31; // 0xfffffffe00000000;
	/*0008*/
};

struct _MI_DRIVER_VA {
	/*0000*/ _MI_DRIVER_VA * Next;
	/*0008*/ _MMPTE * PointerPte;
	/*0010*/ _RTL_BITMAP BitMap;
	/*0020*/ ULONG Hint;
	/*0028*/
};

enum _MI_DYNAMICBASE_BITMAP {
	DynamicBaseBitMap32 = 0x0,
	DynamicBaseBitMap64Low = 0x1,
	DynamicBaseBitMap64High = 0x2,
	DynamicBaseBitMapWow64Dll = 0x3,
	LastDynamicBaseBitMap = 0x4
};

struct _MI_DYNAMIC_BITMAP {
	/*0000*/ _RTL_BITMAP_EX Bitmap;
	/*0010*/ ULONGLONG MaximumSize;
	/*0018*/ ULONGLONG Hint;
	/*0020*/ void * BaseVa;
	/*0028*/ ULONGLONG SizeTopDown;
	/*0030*/ ULONGLONG HintTopDown;
	/*0038*/ void * BaseVaTopDown;
	/*0040*/ ULONGLONG SpinLock;
	/*0048*/
};

enum _MI_ENCLAVE_TYPE {
	MiEnclaveNone = 0x0,
	MiEnclaveHardware = 0x1,
	MiEnclaveVsm = 0x2,
	MiEnclaveMax = 0x3
};

struct _MI_ERROR_STATE {
	/*0000*/ _MI_BAD_MEMORY_EVENT_ENTRY BadMemoryEventEntry;
	/*0038*/ ULONGLONG PageOfInterest;
	/*0040*/ _MI_PROBE_RAISE_TRACKER ProbeRaises;
	/*0080*/ _MI_FORCED_COMMITS ForcedCommits;
	/*0088*/ ULONG WsleFailures[0x1];
	/*008c*/ ULONG PageHashErrors;
	/*0090*/ ULONG CheckZeroCount;
	/*0094*/ LONG volatile ZeroedPageSingleBitErrorsDetected;
	/*0098*/ LONG volatile BadPagesDetected;
	/*009c*/ LONG ScrubPasses;
	/*00a0*/ LONG ScrubBadPagesFound;
	/*00a4*/ ULONG UserViewFailures;
	/*00a8*/ ULONG UserViewCollisionFailures;
	/*00ac*/ _MI_RESAVAIL_FAILURES ResavailFailures;
	/*00b4*/ UCHAR PendingBadPages;
	/*00b5*/ UCHAR InitFailure;
	/*00b6*/ UCHAR StopBadMaps;
	/*00b8*/
};

struct _MI_EXTRA_IMAGE_INFORMATION {
	/*0000*/ ULONG SizeOfHeaders;
	/*0004*/ ULONG SizeOfImage;
	/*0008*/
};

union _MI_FLAGS {
	/*0000*/ LONG EntireFlags;
	/*0000*/ ULONG VerifierEnabled : 01; // 0x00000001;
	/*0000*/ ULONG KernelVerifierEnabled : 01; // 0x00000002;
	/*0000*/ ULONG LargePageKernel : 01; // 0x00000004;
	/*0000*/ ULONG StopOn4d : 01; // 0x00000008;
	/*0000*/ ULONG InitializationPhase : 02; // 0x00000030;
	/*0000*/ ULONG PageKernelStacks : 01; // 0x00000040;
	/*0000*/ ULONG CheckZeroPages : 01; // 0x00000080;
	/*0000*/ ULONG ProcessorPrewalks : 01; // 0x00000100;
	/*0000*/ ULONG ProcessorPostwalks : 01; // 0x00000200;
	/*0000*/ ULONG CoverageBuild : 01; // 0x00000400;
	/*0000*/ ULONG AccessBitReplacementDisabled : 01; // 0x00000800;
	/*0000*/ ULONG CheckExecute : 01; // 0x00001000;
	/*0000*/ ULONG ProtectedPagesEnabled : 01; // 0x00002000;
	/*0000*/ ULONG SecureRelocations : 01; // 0x00004000;
	/*0000*/ ULONG StrongPageIdentity : 01; // 0x00008000;
	/*0000*/ ULONG StrongCodeGuarantees : 01; // 0x00010000;
	/*0000*/ ULONG HardCodeGuarantees : 01; // 0x00020000;
	/*0000*/ ULONG ExecutePagePrivilegeRequired : 01; // 0x00040000;
	/*0000*/ ULONG SecureKernelCfgEnabled : 01; // 0x00080000;
	/*0000*/ ULONG FullHvci : 01; // 0x00100000;
	/*0000*/ ULONG SlatKernelCodeProtected : 01; // 0x00200000;
	/*0000*/ ULONG BootDebuggerActive : 01; // 0x00400000;
	/*0004*/
};

struct _MI_FORCED_COMMITS {
	/*0000*/ ULONG Regular;
	/*0004*/ ULONG Wrap;
	/*0008*/
};

struct _MI_HARDWARE_STATE {
	/*0000*/ ULONG NodeMask;
	/*0004*/ ULONG NumaLastRangeIndex;
	/*0008*/ UCHAR NumaTableCaptured;
	/*0009*/ UCHAR NodeShift;
	/*000a*/ UCHAR ChannelShift;
	/*0010*/ USHORT * NodeGraph;
	/*0018*/ _MI_SYSTEM_NODE_INFORMATION * SystemNodeInformation;
	/*0020*/ _HAL_NODE_RANGE * NumaMemoryRanges;
	/*0028*/ _HAL_CHANNEL_MEMORY_RANGES * ChannelMemoryRanges;
	/*0030*/ ULONG SecondLevelCacheSize;
	/*0034*/ ULONG FirstLevelCacheSize;
	/*0038*/ ULONG PhysicalAddressBits;
	/*0040*/ ULONGLONG TotalPagesAllowed;
	/*0048*/ ULONG SecondaryColorMask;
	/*004c*/ ULONG SecondaryColors;
	/*0050*/ ULONG MediumPageColors;
	/*0054*/ ULONG FlushTbForAttributeChange;
	/*0058*/ ULONG FlushCacheForAttributeChange;
	/*005c*/ ULONG FlushCacheForPageAttributeChange;
	/*0060*/ ULONG CacheFlushPromoteThreshold;
	/*0068*/ ULONGLONG FlushTbThreshold;
	/*0070*/ _MI_PFN_CACHE_ATTRIBUTE OptimalZeroingAttribute[0x4][0x4];
	/*00b0*/ UCHAR AttributeChangeRequiresReZero;
	/*00b8*/ _MI_ZERO_COST_COUNTS ZeroCostCounts[0x2];
	/*00d8*/ ULONGLONG PrimaryPfns;
	/*00e0*/ ULONGLONG HighestPossiblePhysicalPage;
	/*00e8*/ _RTL_AVL_TREE EnclaveRegions;
	/*00f0*/ ULONGLONG VsmKernelPageCount;
	/*00f8*/
};

struct _MI_HYPER_SPACE {
	/*0000*/ UCHAR VadBitmap[0x10000000];
	/*10000000*/ UCHAR PageDirectoryCommitmentBitmap[0x4000];
	/*10004000*/ UCHAR PageTableCommitmentBitmap[0x800000];
	/*10804000*/
};

struct _MI_IMAGE_SECURITY_REFERENCE {
	/*0000*/ void * DynamicRelocations;
	/*0008*/ _IMAGE_SECURITY_CONTEXT SecurityContext;
	/*0010*/ ULONGLONG StrongImageReference;
	/*0018*/
};

struct _MI_IO_CACHE_STATS {
	/*0000*/ ULONGLONG UnusedBlocks;
	/*0008*/ ULONG ActiveCacheMatch;
	/*000c*/ ULONG ActiveCacheOverride;
	/*0010*/ ULONG UnmappedCacheFlush;
	/*0014*/ ULONG UnmappedCacheMatch;
	/*0018*/ ULONG UnmappedCacheConflict;
	/*001c*/ ULONG PermanentIoAttributeConflict;
	/*0020*/ ULONG PermanentIoNodeConflict;
	/*0028*/
};

struct _MI_IO_PAGE_STATE {
	/*0000*/ ULONGLONG IoPfnLock;
	/*0008*/ _RTL_AVL_TREE IoPfnRoot[0x3];
	/*0020*/ _LIST_ENTRY UnusedCachedMaps;
	/*0030*/ ULONG OldestCacheFlushTimeStamp;
	/*0038*/ _MI_IO_CACHE_STATS IoCacheStats;
	/*0060*/ _RTL_AVL_TREE InvariantIoSpace;
	/*0068*/
};

enum _MI_IO_PFN_TYPE {
	MiIoPfnProbes = 0x0,
	MiIoPfnMaps = 0x1,
	MiIoPfnUnmapped = 0x2,
	MiMaximumIoPfnType = 0x3
};

enum _MI_KSTACK_TYPE {
	MiRegularKstack = 0x0,
	MiShortLivedKstack = 0x1,
	MiMaximumKstack = 0x2
};

struct _MI_LARGEPAGE_IMAGE_INFO {
	/*0000*/ UCHAR LargeImageBias;
	/*0001*/ UCHAR Spare[0x3];
	/*0008*/ ULONGLONG ActualImageViewSize;
	/*0010*/
};

struct _MI_LDW_WORK_CONTEXT {
	/*0000*/ _WORK_QUEUE_ITEM WorkItem;
	/*0020*/ _FILE_OBJECT * FileObject;
	/*0028*/ LONG ErrorStatus;
	/*002c*/ LONG volatile Active;
	/*0030*/ UCHAR FreeWhenDone;
	/*0038*/
};

enum _MI_MEMORY_EVENT_TYPES {
	LowPagedPoolEvent = 0x0,
	HighPagedPoolEvent = 0x1,
	LowNonPagedPoolEvent = 0x2,
	HighNonPagedPoolEvent = 0x3,
	LowAvailablePagesEvent = 0x4,
	HighAvailablePagesEvent = 0x5,
	LowCommitEvent = 0x6,
	HighCommitEvent = 0x7,
	MaximumCommitEvent = 0x8,
	BadMemoryDetectedEvent = 0x9,
	PhysicalMemoryChangeEvent = 0xa,
	TotalNumberOfMemoryEvents = 0xb
};

enum _MI_MEMORY_HIGHLOW {
	MiMemoryHigh = 0x0,
	MiMemoryLow = 0x1,
	MiMemoryHighLow = 0x2
};

enum _MI_MIRROR_BITMAP_TYPES {
	MirrorBitmapTypeNormal = 0x0,
	MirrorBitmapTypeInterlocked = 0x1,
	MirrorBitmapTypeMaximum = 0x2
};

struct _MI_MODWRITE_DATA {
	/*0000*/ LONGLONG PagesLoad;
	/*0008*/ ULONGLONG PagesAverage;
	/*0010*/ ULONGLONG AverageAvailablePages;
	/*0018*/ ULONGLONG PagesWritten;
	/*0020*/ ULONG WritesIssued;
	/*0024*/ ULONG IgnoredReservationsCount;
	/*0028*/ ULONG FreedReservationsCount;
	/*002c*/ ULONG WriteBurstCount;
	/*0030*/ ULONGLONG IgnoreReservationsStartTime;
	/*0038*/ _MI_RESERVATION_CLUSTER_INFO volatile ReservationClusterInfo;
	/*003c*/ USHORT IgnoreReservations : 01; // 0x0001;
	/*003c*/ USHORT Spare : 15; // 0xfffe;
	/*003e*/ USHORT Spare1;
	/*0040*/
};

struct _MI_NODE_INFORMATION {
	/*0000*/ ULONGLONG LargePageFreeCount[0x3][0x2];
	/*0030*/ ULONGLONG LargePagesCount[0x3][0x2][0x2][0x4];
	/*01b0*/ _LIST_ENTRY LargePages[0x2][0x2][0x2][0x4];
	/*03b0*/ _LIST_ENTRY MediumPages[0x2][0x2][0x4][0x10];
	/*13b0*/ ULONGLONG MediumPagesCount[0x2][0x2][0x4][0x10];
	/*1bb0*/ _MI_REBUILD_LARGE_PAGE_TIMER LargePageRebuildTimer;
	/*1bd8*/ _MMPFNLIST_SHORT StandbyPageList[0x4][0x8];
	/*1f00*/ _RTL_BITMAP FreePageListHeadsBitmap[0x2];
	/*1f20*/ ULONG FreePageListHeadsBitmapBuffer[0x10];
	/*1f60*/ ULONGLONG volatile FreeCount[0x2];
	/*1f70*/ ULONGLONG TotalPages[0x4];
	/*1f90*/ ULONGLONG TotalPagesEntireNode;
	/*1f98*/ ULONG MmShiftedColor;
	/*1f9c*/ ULONG Color;
	/*1fa0*/ ULONGLONG volatile ChannelFreeCount[0x4][0x2];
	struct {
		/*1fe0*/ ULONG ChannelsHotCold : 01; // 0x00000001;
		/*1fe0*/ ULONG Spare : 31; // 0xfffffffe;
		/*1fe4*/
	} Flags;
	/*1fe8*/ _EX_PUSH_LOCK NodeLock;
	/*1ff0*/ ULONGLONG ZeroThreadHugeMapLock;
	/*1ff8*/ UCHAR ChannelStatus;
	/*1ff9*/ UCHAR ChannelOrdering[0x4];
	/*1ffd*/ UCHAR LockedChannelOrdering[0x4];
	/*2001*/ UCHAR PowerAttribute[0x4];
	/*2008*/ ULONGLONG LargePageLock;
	/*2040*/
};

enum _MI_NODE_NONPAGED_POOL_BITMAP {
	NonPagedPoolLargePdeNx = 0x0,
	NonPagedPoolSmallPde = 0x1,
	NonPagedPoolPerPage = 0x2
};

struct _MI_PAGEFILE_BITMAPS_CACHE_ENTRY {
	/*0000*/ _RTL_BALANCED_NODE LengthTreeNode;
	/*0000*/ _LIST_ENTRY FreeListEntry;
	/*0018*/ _RTL_BALANCED_NODE LocationTreeNode;
	/*0030*/ ULONG StartingIndex;
	/*0034*/ ULONG Length;
	/*0038*/
};

struct _MI_PAGEFILE_TRACES {
	/*0000*/ LONG Status;
	/*0004*/ USHORT PartitionId;
	/*0006*/ UCHAR Priority;
	/*0007*/ UCHAR IrpPriority;
	/*0008*/ UCHAR ReservationWrite;
	/*0010*/ _LARGE_INTEGER CurrentTime;
	/*0018*/ ULONGLONG AvailablePages;
	/*0020*/ ULONGLONG ModifiedPagesTotal;
	/*0028*/ ULONGLONG ModifiedPagefilePages;
	/*0030*/ ULONGLONG ModifiedNoWritePages;
	/*0038*/ ULONGLONG ModifiedPagefileNoReservationPages;
	struct {
		/*0040*/ _MDL Mdl;
		/*0070*/ ULONGLONG Page[0x1];
		/*0078*/
	} MdlHack;
	/*0078*/
};

struct _MI_PAGELIST_STATE {
	/*0000*/ LONG volatile ActiveSpinLock;
	/*0008*/ _RTL_AVL_TREE ActiveThreadTree;
	/*0010*/
};

struct _MI_PAGE_COMBINE_STATISTICS {
	/*0000*/ ULONGLONG PagesScannedActive;
	/*0008*/ ULONGLONG PagesScannedStandby;
	/*0010*/ ULONGLONG PagesCombined;
	/*0018*/ ULONG CombineScanCount;
	/*001c*/ LONG CombinedBlocksInUse;
	/*0020*/ LONG SumCombinedBlocksReferenceCount;
	/*0028*/
};

struct _MI_PAGE_COMBINING_SUPPORT {
	/*0000*/ _MI_PARTITION * Partition;
	/*0008*/ _LIST_ENTRY ArbitraryPfnMapList;
	/*0018*/ _MI_COMBINE_WORKITEM FreeCombinePoolItem;
	/*0040*/ ULONG CombiningThreadCount;
	/*0048*/ _LIST_ENTRY CombinePageFreeList;
	/*0058*/ ULONGLONG CombineFreeListLock;
	/*0060*/ _MI_COMBINE_PAGE_LISTHEAD CombinePageListHeads[0x10];
	/*0160*/ _MI_PAGE_COMBINE_STATISTICS PageCombineStats;
	/*0188*/
};

struct _MI_PAGING_FILE_SPACE_BITMAPS {
	/*0000*/ ULONG RefCount;
	/*0000*/ _MI_PAGING_FILE_SPACE_BITMAPS * Anchor;
	/*0008*/ _RTL_BITMAP AllocationBitmap;
	/*0018*/ _RTL_BITMAP ReservationBitmap;
	/*0018*/ _RTL_BITMAP EvictedBitmap;
	/*0028*/
};

struct _MI_PAGING_IO_STATE {
	/*0000*/ _RTL_AVL_TREE PageFileHead;
	/*0008*/ LONG volatile PageFileHeadSpinLock;
	/*000c*/ LONG PrefetchSeekThreshold;
	/*0010*/ _SLIST_HEADER InPageSupportSListHead[0x2];
	/*0030*/ UCHAR InPageSupportSListMinimum[0x2];
	/*0034*/ ULONG InPageSinglePages;
	/*0038*/ LONG volatile DelayPageFaults;
	/*003c*/ ULONG FileCompressionBoundary;
	/*0040*/ UCHAR MdlsAdjusted;
	/*0050*/
};

struct _MI_PARTITION {
	/*0000*/ _MI_PARTITION_CORE Core;
	/*01a8*/ _MI_PARTITION_MODWRITES Modwriter;
	/*0470*/ _MI_PARTITION_STORES Store;
	/*0500*/ _MI_PARTITION_SEGMENTS Segments;
	/*0800*/ _MI_PARTITION_PAGE_LISTS PageLists;
	/*13c0*/ _MI_PARTITION_COMMIT Commit;
	/*1440*/ _MI_PARTITION_ZEROING Zeroing;
	/*14a8*/ _MI_PAGE_COMBINING_SUPPORT PageCombine;
	/*1630*/ void * WorkingSetControl;
	/*1638*/ _MMWORKING_SET_EXPANSION_HEAD WorkingSetExpansionHead;
	/*1680*/ _MI_VISIBLE_PARTITION Vp;
	/*2880*/
};

struct _MI_PARTITION_COMMIT {
	/*0000*/ ULONGLONG PeakCommitment;
	/*0008*/ ULONGLONG TotalCommitLimitMaximum;
	/*0010*/ LONG volatile Popups[0x2];
	/*0018*/ ULONGLONG LowCommitThreshold;
	/*0020*/ ULONGLONG HighCommitThreshold;
	/*0028*/ ULONGLONG EventLock;
	/*0030*/ ULONGLONG SystemCommitReserve;
	/*0040*/ ULONGLONG volatile OverCommit;
	/*0080*/
};

struct _MI_PARTITION_CORE {
	/*0000*/ USHORT PartitionId;
	union {
		/*0004*/ ULONG LongFlags;
		/*0004*/ _MI_PARTITION_FLAGS Flags;
		/*0008*/
	} u;
	/*0008*/ ULONG Signature;
	/*000c*/ UCHAR MemoryConfigurationChanged;
	/*0010*/ _MI_NODE_INFORMATION * NodeInformation;
	/*0018*/ _RTL_AVL_TREE PageRoot;
	/*0020*/ _PHYSICAL_MEMORY_DESCRIPTOR * MemoryNodeRuns;
	/*0028*/ ULONGLONG MemoryBlockReferences;
	/*0030*/ _WORK_QUEUE_ITEM PfnUnmapWorkItem;
	/*0050*/ ULONGLONG PfnUnmapCount;
	/*0058*/ void * PfnUnmapWaitList;
	/*0060*/ _PHYSICAL_MEMORY_DESCRIPTOR * MemoryRuns;
	/*0068*/ _KEVENT ExitEvent;
	/*0080*/ void * SystemThreadHandles[0x5];
	/*00a8*/ _EPARTITION * PartitionObject;
	/*00b0*/ _EX_PUSH_LOCK PartitionSystemThreadsLock;
	/*00b8*/ _EX_PUSH_LOCK DynamicMemoryPushLock;
	/*00c0*/ LONG volatile DynamicMemoryLock;
	/*00c4*/ UCHAR PfnUnmapActive;
	/*00c8*/ _KEVENT TemporaryMemoryEvent;
	/*00e0*/ void * RootDirectory;
	/*00e8*/ void * KernelObjectsDirectory;
	/*00f0*/ _KEVENT * MemoryEvents[0xb];
	/*0148*/ void * MemoryEventHandles[0xb];
	/*01a0*/ ULONGLONG NonChargedSecurePages;
	/*01a8*/
};

struct _MI_PARTITION_FLAGS {
	/*0000*/ ULONG BeingDeleted : 01; // 0x00000001;
	/*0000*/ ULONG PageListsInitialized : 01; // 0x00000002;
	/*0000*/ ULONG StoreReservedPagesCharged : 01; // 0x00000004;
	/*0000*/ ULONG PureHoldingPartition : 01; // 0x00000008;
	/*0004*/
};

struct _MI_PARTITION_MODWRITES {
	/*0000*/ _MMPAGE_FILE_EXPANSION AttemptForCantExtend;
	/*0058*/ _MMPAGE_FILE_EXPANSION PageFileContract;
	/*00b0*/ ULONGLONG NumberOfMappedMdls;
	/*00b8*/ LONG volatile NumberOfMappedMdlsInUse;
	/*00bc*/ ULONG NumberOfMappedMdlsInUsePeak;
	/*00c0*/ _MMMOD_WRITER_LISTHEAD MappedFileHeader;
	/*00e8*/ UCHAR NeedMappedMdl;
	/*00e9*/ UCHAR NeedPageFileMdl;
	/*00ea*/ UCHAR ModwriterActive;
	/*00eb*/ UCHAR TransitionInserted;
	/*00ec*/ LONG LastModifiedWriteError;
	/*00f0*/ LONG LastMappedWriteError;
	/*00f4*/ ULONG volatile MappedFileWriteSucceeded;
	/*00f8*/ ULONG MappedWriteBurstCount;
	/*00fc*/ ULONG LowPriorityModWritesOutstanding;
	/*0100*/ _KEVENT BoostModWriteIoPriorityEvent;
	/*0118*/ LONG ModifiedWriterThreadPriority;
	/*0120*/ ULONGLONG ModifiedPagesLowPriorityGoal;
	/*0128*/ _KEVENT ModifiedPageWriterEvent;
	/*0140*/ _KEVENT ModifiedWriterExitedEvent;
	/*0158*/ LONG volatile WriteAllPagefilePages;
	/*015c*/ LONG volatile WriteAllMappedPages;
	/*0160*/ _KEVENT MappedPageWriterEvent;
	/*0178*/ _MI_MODWRITE_DATA ModWriteData;
	/*01b8*/ _KEVENT RescanPageFilesEvent;
	/*01d0*/ _MMMOD_WRITER_LISTHEAD PagingFileHeader;
	/*01f8*/ _ETHREAD * ModifiedPageWriterThread;
	/*0200*/ _EX_RUNDOWN_REF ModifiedPageWriterRundown;
	/*0208*/ _WORK_QUEUE_ITEM PagefileScanWorkItem;
	/*0228*/ ULONG PagefileScanCount;
	/*022c*/ LONG volatile ClusterWritesDisabled[0x2];
	/*0238*/ _KEVENT NotifyStoreMemoryConditions;
	/*0250*/ UCHAR volatile DelayMappedWrite;
	/*0254*/ ULONG volatile PagefileReservationsEnabled;
	/*0258*/ _EX_PUSH_LOCK PageFileCreationLock;
	/*0260*/ _WORK_QUEUE_ITEM TrimPagefileWorkItem;
	/*0280*/ ULONGLONG LastTrimPagefileTime;
	/*0288*/ _WORK_QUEUE_ITEM WsSwapPagefileContractWorkItem;
	/*02a8*/ LONG volatile WsSwapPageFileContractionInProgress;
	/*02b0*/ _EX_PUSH_LOCK WorkingSetSwapLock;
	/*02b8*/ LONG volatile WorkingSetInswapLock;
	/*02c0*/
};

struct _MI_PARTITION_PAGE_LISTS {
	/*0000*/ _MMPFNLIST * FreePagesByColor[0x2];
	/*0040*/ _MMPFNLIST ZeroedPageListHead;
	/*0080*/ _MMPFNLIST FreePageListHead;
	/*00c0*/ _MMPFNLIST StandbyPageListHead;
	/*0100*/ _MMPFNLIST StandbyPageListByPriority[0x8];
	/*0240*/ _MMPFNLIST ModifiedPageListNoReservation;
	/*0280*/ _MMPFNLIST ModifiedPageListByReservation[0x10];
	/*0500*/ _MMPFNLIST MappedPageListHead[0x10];
	/*0780*/ _MMPFNLIST BadPageListHead;
	/*07c0*/ _MMPFNLIST EnclavePageListHead;
	/*07e8*/ _SLIST_HEADER * FreePageSlist[0x2];
	/*07f8*/ _MMPFNLIST * PageLocationList[0x8];
	/*0838*/ ULONG volatile StandbyRepurposedByPriority[0x8];
	/*0880*/ ULONGLONG volatile TransitionSharedPages;
	/*0888*/ ULONGLONG TransitionSharedPagesPeak[0x3];
	/*08a0*/ _KEVENT MappedPageListHeadEvent[0x10];
	/*0a20*/ _MI_DECAY_TIMER_LINK DecayClusterTimerHeads[0x4];
	/*0a40*/ ULONG DecayHand;
	/*0a44*/ UCHAR StandbyListDiscard;
	/*0a45*/ UCHAR FreeListDiscard;
	/*0a46*/ UCHAR LargePfnBitMapsReady;
	/*0a48*/ ULONGLONG LastDecayHandUpdateTime;
	/*0a50*/ _MI_LDW_WORK_CONTEXT LastChanceLdwContext;
	/*0ac0*/ ULONGLONG AvailableEventsLock;
	/*0ac8*/ _MI_AVAILABLE_PAGE_WAIT_STATES AvailablePageWaitStates[0x3];
	/*0b28*/ void * MirrorListLocks;
	/*0b40*/ ULONGLONG volatile TransitionPrivatePages;
	/*0b48*/ _RTL_BITMAP_EX LargePfnBitMap[0x2];
	/*0b68*/ ULONGLONG LowMemoryThreshold;
	/*0b70*/ ULONGLONG HighMemoryThreshold;
	/*0b80*/ ULONGLONG LargePfnBitMapLock;
	/*0bc0*/
};

struct _MI_PARTITION_SEGMENTS {
	/*0000*/ LONG volatile SegmentListLock;
	/*0004*/ ULONG DeleteOnCloseCount;
	/*0008*/ LONGLONG volatile FsControlAreaCount;
	/*0010*/ LONGLONG volatile PfControlAreaCount;
	/*0018*/ _KEVENT DeleteSubsectionCleanup;
	/*0030*/ _KEVENT UnusedSegmentCleanup;
	/*0048*/ ULONGLONG SubsectionDeletePtes;
	/*0050*/ _MMPAGE_FILE_EXPANSION AttemptForCantExtend;
	/*00a8*/ _MMDEREFERENCE_SEGMENT_HEADER DereferenceSegmentHeader;
	/*00f8*/ _LIST_ENTRY DeleteOnCloseList;
	/*0108*/ _KTIMER DeleteOnCloseTimer;
	/*0148*/ UCHAR DeleteOnCloseTimerActive;
	/*0149*/ UCHAR SegmentDereferenceThreadExists;
	/*0150*/ ULONGLONG UnusedSegmentPagedPool;
	/*0158*/ _LIST_ENTRY UnusedSegmentList;
	/*0168*/ _LIST_ENTRY UnusedSubsectionList;
	/*0178*/ _LIST_ENTRY DeleteSubsectionList;
	/*0188*/ _KEVENT ControlAreaDeleteEvent;
	/*01a0*/ _SINGLE_LIST_ENTRY ControlAreaDeleteList;
	/*01a8*/ _MI_PTE_CHAIN_HEAD FreeSystemCache;
	/*01c0*/ _KEVENT CloneDereferenceEvent;
	/*01e0*/ _SLIST_HEADER CloneProtosSListHead;
	/*01f0*/ _EX_PUSH_LOCK SystemCacheInitLock;
	/*01f8*/ ULONG PagefileExtensionWaiters;
	/*01fc*/ ULONG PagefileExtensionRequests;
	/*0200*/ _KEVENT PagefileExtensionWaitEvent;
	/*0218*/ _MI_CROSS_PARTITION_CHARGES SharedCharges[0x5];
	/*02b8*/ _KEVENT * SharedChargesDrainEvent;
	/*02c0*/ _KEVENT * PagefileControlAreasDrainEvent;
	/*0300*/
};

struct _MI_PARTITION_STATE {
	/*0000*/ ULONGLONG PartitionLock;
	/*0008*/ _EX_PUSH_LOCK PartitionIdLock;
	/*0010*/ ULONGLONG InitialPartitionIdBits;
	/*0018*/ _LIST_ENTRY PartitionList;
	/*0028*/ _RTL_BITMAP * PartitionIdBitmap;
	/*0030*/ _RTL_BITMAP InitialPartitionIdBitmap;
	/*0040*/ _MI_PARTITION * TempPartitionPointers[0x1];
	/*0048*/ _MI_PARTITION * * Partition;
	/*0050*/ ULONGLONG TotalPagesInChildPartitions;
	/*0058*/ ULONG CrossPartitionDenials;
	/*005c*/ UCHAR MultiplePartitionsExist;
	/*0060*/
};

struct _MI_PARTITION_STORES {
	union {
		/*0000*/ LONG FlushCompleting : 01; // 0x00000001;
		/*0000*/ LONG FlushInProgress : 31; // 0xfffffffe;
		/*0000*/ LONG volatile Long;
		/*0004*/
	} WriteAllStoreHintedPages;
	/*0004*/ ULONG VirtualPageFileNumber;
	/*0008*/ ULONG Registered;
	/*000c*/ ULONG ReadClusterSizeMax;
	/*0010*/ ULONG EvictFlushRequestCount;
	/*0014*/ ULONG ModifiedWriteDisableCount;
	/*0018*/ ULONG WriteIssueFailures;
	/*001c*/ ULONG WritesOutstanding;
	/*0020*/ LONG volatile EvictFlushLock;
	/*0028*/ _ETHREAD * EvictionThread;
	/*0030*/ _KEVENT EvictEvent;
	/*0050*/ _SLIST_HEADER WriteSupportSListHead;
	/*0060*/ _KEVENT EvictFlushCompleteEvent;
	/*0078*/ _RTL_BITMAP * ModifiedWriteFailedBitmap;
	/*0080*/ _EPROCESS * StoreProcess;
	/*0090*/
};

enum _MI_PARTITION_THREAD {
	MiZeroPageThreadSlot = 0x0,
	MiPartitionWorkingSetManagerSlot = 0x1,
	MiDereferenceSegmentThreadSlot = 0x2,
	MiModifiedPageWriterSlot = 0x3,
	MiMappedPageWriterSlot = 0x4,
	MiNumberOfPartitionThreads = 0x5
};

struct _MI_PARTITION_ZEROING {
	/*0000*/ _KEVENT PageEvent;
	/*0018*/ UCHAR ThreadActive;
	/*0019*/ UCHAR ThreadPriorityStatic;
	/*001c*/ LONG ZeroFreePageSlistMinimum;
	/*0020*/ _WORK_QUEUE_ITEM RebalanceZeroFreeWorkItem;
	/*0040*/ LONG volatile ThreadCount;
	/*0048*/ _KGATE Gate;
	/*0060*/ _MI_ZERO_THREAD_CONTEXT * ThreadContext;
	/*0068*/
};

struct _MI_PER_SESSION_PROTOS {
	/*0000*/ _RTL_BALANCED_NODE SessionProtoNode;
	/*0000*/ _SINGLE_LIST_ENTRY FreeList;
	/*0000*/ void * DriverAddress;
	/*0018*/ ULONG SessionId;
	/*0018*/ _SUBSECTION * Subsection;
	/*0020*/ _MMPTE * SubsectionBase;
	union {
		/*0028*/ ULONG ReferenceCount;
		/*0028*/ ULONG NumberOfPtesToFree;
		/*002c*/
	} u2;
	/*0030*/
};

enum _MI_PFN_CACHE_ATTRIBUTE {
	MiNonCached = 0x0,
	MiCached = 0x1,
	MiWriteCombined = 0x2,
	MiNotMapped = 0x3
};

struct _MI_POOL_FAILURE_REASONS {
	/*0000*/ ULONG NonPagedNoPtes;
	/*0004*/ ULONG PriorityTooLow;
	/*0008*/ ULONG NonPagedNoPagesAvailable;
	/*000c*/ ULONG PagedNoPtes;
	/*0010*/ ULONG SessionPagedNoPtes;
	/*0014*/ ULONG PagedNoPagesAvailable;
	/*0018*/ ULONG SessionPagedNoPagesAvailable;
	/*001c*/ ULONG PagedNoCommit;
	/*0020*/ ULONG SessionPagedNoCommit;
	/*0024*/ ULONG NonPagedNoResidentAvailable;
	/*0028*/ ULONG NonPagedNoCommit;
	/*002c*/
};

struct _MI_POOL_STATE {
	/*0000*/ ULONGLONG MaximumNonPagedPoolThreshold;
	/*0008*/ ULONG NonPagedPoolSListMaximum[0x3];
	/*0018*/ ULONGLONG volatile AllocatedNonPagedPool;
	/*0020*/ _SINGLE_LIST_ENTRY BadPoolHead;
	/*0028*/ ULONG HighEventSets;
	/*002c*/ UCHAR HighEventSetsValid;
	/*0030*/ ULONG PoolFailures[0x3][0x3];
	/*0054*/ _MI_POOL_FAILURE_REASONS PoolFailureReasons;
	/*0080*/ ULONGLONG LowPagedPoolThreshold;
	/*0088*/ ULONGLONG HighPagedPoolThreshold;
	/*0090*/ ULONG PagedPoolSListMaximum;
	/*0094*/ ULONG PreemptiveTrims[0x4];
	/*00a8*/ ULONGLONG SpecialPagesInUsePeak;
	/*00b0*/ ULONG SpecialPoolRejected[0x6];
	/*00c8*/ ULONGLONG volatile SpecialPagesNonPaged;
	/*00d0*/ LONG volatile SpecialPoolPdes;
	/*00d4*/ ULONG SessionSpecialPoolPdesMax;
	/*00d8*/ ULONGLONG TotalPagedPoolQuota;
	/*00e0*/ ULONGLONG TotalNonPagedPoolQuota;
	/*00e8*/
};

struct _MI_PROBE_RAISE_TRACKER {
	/*0000*/ ULONG UserRangeInKernel;
	/*0004*/ ULONG FaultFailed;
	/*0008*/ ULONG WriteFaultFailed;
	/*000c*/ ULONG LargePageFailed;
	/*0010*/ ULONG UserAccessToKernelPte;
	/*0014*/ ULONG BadPageLocation;
	/*0018*/ ULONG InsufficientCharge;
	/*001c*/ ULONG PageTableCharge;
	/*0020*/ ULONG NoPhysicalMapping;
	/*0024*/ ULONG NoIoReference;
	/*0028*/ ULONG ProbeFailed;
	/*002c*/ ULONG PteIsZero;
	/*0030*/ ULONG StrongCodeWrite;
	/*0034*/ ULONG ReducedCloneCommitChargeFailed;
	/*0038*/ ULONG CopyOnWriteAtDispatchNoPages;
	/*003c*/ ULONG EnclavePageFailed;
	/*0040*/
};

struct _MI_PROCESS_STATE {
	/*0000*/ void * SystemDllBase;
	/*0008*/ ULONG ColorSeed;
	/*000c*/ LONG RotatingUniprocessorNumber;
	/*0010*/ _LARGE_INTEGER CriticalSectionTimeout;
	/*0018*/ _LIST_ENTRY ProcessList;
	/*0028*/ _MMPTE * SharedUserDataPte;
	/*0030*/ ULONGLONG VadSecureCookie;
	/*0038*/
};

struct _MI_PTE_CHAIN_HEAD {
	/*0000*/ _MMPTE Flink;
	/*0008*/ _MMPTE Blink;
	/*0010*/ _MMPTE * PteBase;
	/*0018*/
};

struct _MI_REBUILD_LARGE_PAGE_TIMER {
	/*0000*/ _WORK_QUEUE_ITEM WorkItem;
	/*0020*/ UCHAR SecondsLeft;
	/*0021*/ UCHAR RebuildActive;
	/*0022*/ UCHAR NextPassDelta;
	/*0023*/ UCHAR LargeSubPagesActive;
	/*0028*/
};

struct _MI_RESAVAIL_FAILURES {
	/*0000*/ ULONG Wrap;
	/*0004*/ ULONG NoCharge;
	/*0008*/
};

union _MI_RESERVATION_CLUSTER_INFO {
	/*0000*/ ULONG ClusterSize : 10; // 0x000003ff;
	/*0000*/ ULONG SequenceNumber : 22; // 0xfffffc00;
	/*0000*/ LONG EntireInfo;
	/*0004*/
};

struct _MI_RESUME_WORKITEM {
	/*0000*/ _KEVENT ResumeCompleteEvent;
	/*0018*/ _WORK_QUEUE_ITEM WorkItem;
	/*0038*/
};

struct _MI_REVERSE_VIEW_MAP {
	/*0000*/ _LIST_ENTRY ViewLinks;
	/*0010*/ void * SystemCacheVa;
	/*0010*/ void * SessionViewVa;
	/*0010*/ _EPROCESS * VadsProcess;
	/*0010*/ ULONGLONG Type : 02; // 0x0000000000000003;
	/*0018*/ _SUBSECTION * Subsection;
	/*0018*/ ULONGLONG SubsectionType : 01; // 0x0000000000000001;
	/*0020*/ _MI_SYSTEM_CACHE_VIEW_ATTRIBUTES SystemCacheAttributes;
	/*0020*/ ULONGLONG SectionOffset;
	/*0030*/
};

struct _MI_RFG_PROTECTED_STACK {
	/*0000*/ void * ControlStackBase;
	/*0008*/ _MMVAD_SHORT * ControlStackVad;
	/*0010*/ void * OwnerThread;
	/*0018*/
};

struct _MI_SECTION_IMAGE_INFORMATION {
	/*0000*/ _SECTION_IMAGE_INFORMATION ExportedImageInformation;
	/*0040*/ _MI_EXTRA_IMAGE_INFORMATION InternalImageInformation;
	/*0048*/
};

struct _MI_SECTION_STATE {
	/*0000*/ LONG volatile SectionObjectPointersLock;
	/*0008*/ _RTL_AVL_TREE SectionBasedRoot;
	/*0010*/ _EX_PUSH_LOCK SectionBasedLock;
	/*0018*/ ULONGLONG volatile UnusedSegmentPagedPool;
	/*0020*/ ULONG DataSectionProtectionMask;
	/*0028*/ void * HighSectionBase;
	/*0030*/ _MSUBSECTION PhysicalSubsection;
	/*00a0*/ _CONTROL_AREA PhysicalControlArea;
	/*0120*/ _MMPFNLIST PurgingExtentPages;
	/*0148*/ _MMPFN * DanglingExtentPages;
	/*0150*/ _WORK_QUEUE_ITEM DanglingExtentsWorkItem;
	/*0170*/ UCHAR DanglingExtentsWorkerActive;
	/*0171*/ UCHAR PurgingExtentsNeedWatchdog;
	/*0178*/ _RTL_AVL_TREE PageFileSectionHead;
	/*0180*/ LONG volatile PageFileSectionListSpinLock;
	/*0184*/ ULONG ImageBias;
	/*0188*/ _EX_PUSH_LOCK RelocateBitmapsLock;
	/*0190*/ _RTL_BITMAP ImageBitMap;
	/*01a0*/ ULONG ImageBias64Low;
	/*01a4*/ ULONG ImageBias64High;
	/*01a8*/ _RTL_BITMAP ImageBitMap64Low;
	/*01b8*/ _RTL_BITMAP ImageBitMap64High;
	/*01c8*/ _RTL_BITMAP ImageBitMapWow64Dll;
	/*01d8*/ void * ApiSetSection;
	/*01e0*/ void * ApiSetSchema;
	/*01e8*/ ULONGLONG ApiSetSchemaSize;
	/*01f0*/ ULONG LostDataFiles;
	/*01f4*/ ULONG LostDataPages;
	/*01f8*/ ULONG ImageFailureReason;
	/*0200*/ _SECTION * CfgBitMapSection32;
	/*0208*/ _CONTROL_AREA * CfgBitMapControlArea32;
	/*0210*/ _SECTION * CfgBitMapSection64;
	/*0218*/ _CONTROL_AREA * CfgBitMapControlArea64;
	/*0220*/ _RTL_BITMAP_EX KernelCfgBitMap;
	/*0230*/ _EX_PUSH_LOCK KernelCfgBitMapLock;
	/*0238*/ ULONG ImageCfgFailure;
	/*023c*/ ULONG ImageChecksumBreakpoint;
	/*0240*/ ULONG ImageSizeBreakpoint;
	/*0244*/ LONG volatile ImageValidationFailed;
	/*0280*/
};

struct _MI_SESSION_DRIVER_UNLOAD {
	/*0000*/ void (* Function)( _DRIVER_OBJECT * );
	/*0000*/ ULONGLONG FunctionValue;
	/*0008*/
};

struct _MI_SESSION_STATE {
	/*0000*/ _MMSESSION SystemSession;
	/*0020*/ ULONG DetachTimeStamp;
	/*0024*/ UCHAR CodePageEdited;
	/*0028*/ ULONG * DynamicPoolBitBuffer;
	/*0030*/ ULONGLONG * DynamicVaBitBuffer;
	/*0038*/ ULONGLONG DynamicVaBitBufferPages;
	/*0040*/ void * DynamicVaStart;
	/*0048*/ void * ImageVaStart;
	/*0050*/ ULONG * DynamicPtesBitBuffer;
	/*0058*/ _EX_PUSH_LOCK IdLock;
	/*0060*/ _EPROCESS * LeaderProcess;
	/*0068*/ _EX_PUSH_LOCK InitializeLock;
	/*0070*/ _MMWSL_INSTANCE * WorkingSetList;
	/*0078*/ void * SessionBase;
	/*0080*/ void * SessionCore;
	/*0088*/
};

struct _MI_SHUTDOWN_STATE {
	/*0000*/ UCHAR CrashDumpInitialized;
	/*0001*/ UCHAR ConnectedStandbyActive;
	/*0002*/ UCHAR ZeroPageFileAtShutdown;
	/*0004*/ ULONG SystemShutdown;
	/*0008*/ LONG ShutdownFlushInProgress;
	/*000c*/ ULONG MirroringActive;
	/*0010*/ _MI_RESUME_WORKITEM ResumeItem;
	/*0048*/ _ETHREAD * MirrorHoldsPfn;
	/*0050*/ _RTL_BITMAP_EX MirrorBitMaps[0x2];
	/*0070*/ _MMPTE * CrashDumpPte;
	/*0078*/
};

struct _MI_SPECIAL_POOL {
	/*0000*/ ULONGLONG Lock;
	/*0008*/ _MI_PTE_CHAIN_HEAD Paged;
	/*0020*/ _MI_PTE_CHAIN_HEAD NonPaged;
	/*0038*/ ULONGLONG volatile PagesInUse;
	/*0040*/
};

struct _MI_STANDBY_STATE {
	/*0000*/ ULONGLONG FirstDecayPage;
	/*0010*/ _SLIST_HEADER PfnDecayFreeSList;
	/*0020*/ _MM_PAGE_ACCESS_INFO_HEADER * PfnRepurposeLog;
	/*0028*/ _KDPC AllocatePfnRepurposeDpc;
	/*0070*/
};

struct _MI_SUB64K_FREE_RANGES {
	/*0000*/ _RTL_BITMAP_EX BitMap;
	/*0010*/ _LIST_ENTRY ListEntry;
	/*0020*/ _MMVAD_SHORT * Vad;
	/*0028*/ ULONG SetBits;
	/*002c*/ ULONG FullSetBits;
	/*0030*/ ULONG SubListIndex : 02; // 0x00000003;
	/*0030*/ ULONG Hint : 30; // 0xfffffffc;
	/*0038*/
};

struct _MI_SUBSECTION_ENTRY1 {
	/*0000*/ ULONG CrossPartitionReferences : 30; // 0x3fffffff;
	/*0000*/ ULONG SubsectionMappedLarge : 02; // 0xc0000000;
	/*0004*/
};

enum _MI_SUBVAD_LISTS {
	MiSubVadPebTebAny = 0x0,
	MiSubVadPebTebBelow2gb = 0x1,
	MiSubVadPebTebBelow4gb = 0x2,
	MiSubVadRfg = 0x3,
	MiSubVadMaximum = 0x4
};

struct _MI_SYSTEM_CACHE_VIEW_ATTRIBUTES {
	/*0000*/ ULONGLONG NumberOfPtes : 06; // 0x000000000000003f;
	/*0000*/ ULONGLONG PartitionId : 10; // 0x000000000000ffc0;
	/*0000*/ ULONGLONG Spare : 02; // 0x0000000000030000;
	/*0008*/ ULONGLONG SectionOffset : 48; // 0x0000ffffffffffff;
	/*0010*/
};

struct _MI_SYSTEM_IMAGE_STATE {
	/*0000*/ _LIST_ENTRY FixupList;
	/*0010*/ _KMUTANT LoadLock;
	/*0048*/ LONG volatile FixupLock;
	/*004c*/ UCHAR FirstLoadEver;
	/*004d*/ UCHAR LargePageAll;
	/*0050*/ ULONGLONG LastPage;
	/*0058*/ _LIST_ENTRY LargePageList;
	/*0068*/ _LIST_ENTRY StrongCodeLoadFailureList;
	/*0078*/ _KLDR_DATA_TABLE_ENTRY * BeingDeleted;
	/*0080*/ _EX_PUSH_LOCK MappingRangesPushLock;
	/*0088*/ _MI_DRIVER_VA * MappingRanges[0x2];
	/*0098*/ ULONGLONG PageCount;
	/*00a0*/ _MM_SYSTEM_PAGE_COUNTS PageCounts;
	/*00b0*/ _EX_PUSH_LOCK CollidedLock;
	/*00b8*/
};

struct _MI_SYSTEM_INFORMATION {
	/*0000*/ _MI_POOL_STATE Pools;
	/*0100*/ _MI_SECTION_STATE Sections;
	/*0380*/ _MI_SYSTEM_IMAGE_STATE SystemImages;
	/*0438*/ _MI_SESSION_STATE Sessions;
	/*04c0*/ _MI_PROCESS_STATE Processes;
	/*04f8*/ _MI_HARDWARE_STATE Hardware;
	/*0600*/ _MI_SYSTEM_VA_STATE SystemVa;
	/*09c0*/ _MI_COMBINE_STATE PageCombines;
	/*09d8*/ _MI_PAGELIST_STATE PageLists;
	/*09e8*/ _MI_PARTITION_STATE Partitions;
	/*0a48*/ _MI_SHUTDOWN_STATE Shutdowns;
	/*0ac0*/ _MI_ERROR_STATE Errors;
	/*0b80*/ _MI_ACCESS_LOG_STATE AccessLog;
	/*0c00*/ _MI_DEBUGGER_STATE Debugger;
	/*0d20*/ _MI_STANDBY_STATE Standby;
	/*0dc0*/ _MI_SYSTEM_PTE_STATE SystemPtes;
	/*1000*/ _MI_IO_PAGE_STATE IoPages;
	/*1070*/ _MI_PAGING_IO_STATE PagingIo;
	/*10c0*/ _MI_COMMON_PAGE_STATE CommonPages;
	/*1180*/ _MI_SYSTEM_TRIM_STATE Trims;
	/*11c0*/ ULONGLONG Cookie;
	/*11c8*/ void * volatile * BootRegistryRuns;
	/*11d0*/ LONG volatile ZeroingDisabled;
	/*11d4*/ UCHAR FullyInitialized;
	/*11d5*/ UCHAR SafeBooted;
	/*11d8*/ _TlgProvider_t const * TraceLogging;
	/*1200*/ _MI_VISIBLE_STATE Vs;
	/*1b00*/
};

struct _MI_SYSTEM_NODE_INFORMATION {
	/*0000*/ _SLIST_HEADER PagedPoolSListHead;
	/*0010*/ _SLIST_HEADER NonPagedPoolSListHead[0x3];
	/*0040*/ _SLIST_HEADER NonPagedPoolSListHeadNx[0x3];
	/*0070*/ _CACHED_KSTACK_LIST CachedKernelStacks[0x2];
	/*00b0*/ ULONGLONG NonPagedBitMapMaximum;
	/*00b8*/ _MI_DYNAMIC_BITMAP DynamicBitMapNonPagedPool;
	/*0100*/ ULONGLONG NonPagedPoolLowestPage;
	/*0108*/ ULONGLONG NonPagedPoolHighestPage;
	/*0110*/ ULONGLONG AllocatedNonPagedPool;
	/*0118*/ ULONGLONG PartialLargePoolRegions;
	/*0120*/ ULONGLONG PagesInPartialLargePoolRegions;
	/*0128*/ ULONGLONG CachedNonPagedPoolCount;
	/*0130*/ ULONGLONG NonPagedPoolSpinLock;
	/*0138*/ _MMPFN * CachedNonPagedPool;
	/*0140*/ void * NonPagedPoolFirstVa;
	/*0148*/ void * NonPagedPoolLastVa;
	/*0150*/ _RTL_BITMAP_EX NonPagedBitMap[0x3];
	/*0180*/ ULONGLONG NonPagedHint[0x2];
	/*0190*/
};

struct _MI_SYSTEM_PTE_STATE {
	/*0000*/ _NPAGED_LOOKASIDE_LIST MdlTrackerLookaside;
	/*0080*/ _SLIST_HEADER DeadPteTrackerSListHead;
	/*0090*/ ULONGLONG PteTrackerLock;
	/*0098*/ _RTL_BITMAP_EX PteTrackingBitmap;
	/*00a8*/ _MI_CACHED_PTES volatile * CachedPteHeads;
	/*00b0*/ _MI_CACHED_PTES volatile * CachedKernelStackPteHeads;
	/*00b8*/ _MI_SYSTEM_PTE_TYPE SystemViewPteInfo;
	/*0120*/ _MI_SYSTEM_PTE_TYPE KernelStackPteInfo;
	/*0188*/ ULONG StackGrowthFailures;
	/*018c*/ UCHAR KernelStackPages;
	/*018d*/ UCHAR TrackPtesAborted;
	/*018e*/ UCHAR AdjustCounter;
	/*0190*/ LONG volatile ReservedMappingLock;
	/*0198*/ _RTL_AVL_TREE ReservedMappingTree;
	/*01a0*/ _MMPFN * ReservedMappingPageTablePfns;
	/*01a8*/ _RTL_AVL_TREE OutswappedKernelStackRoot;
	/*01b0*/ LONG volatile OutswappedKernelStackLock;
	/*01b8*/ _MI_ULTRA_VA_CONTEXT UltraSpaceContext;
	/*01f8*/ ULONG NumberOfUltraMdlMaps;
	/*0200*/ _MI_ULTRA_MDL_NODE * UltraMdlNodeMappings;
	/*0240*/
};

struct _MI_SYSTEM_PTE_TYPE {
	/*0000*/ _RTL_BITMAP_EX Bitmap;
	/*0010*/ _MMPTE * BasePte;
	/*0018*/ ULONG Flags;
	/*001c*/ _MI_SYSTEM_VA_TYPE VaType;
	/*0020*/ ULONG * FailureCount;
	/*0028*/ ULONG PteFailures;
	/*0030*/ ULONGLONG SpinLock;
	/*0030*/ _EX_PUSH_LOCK * GlobalPushLock;
	/*0038*/ _MMSUPPORT_INSTANCE * Vm;
	/*0040*/ ULONGLONG volatile TotalSystemPtes;
	/*0048*/ ULONGLONG Hint;
	/*0050*/ ULONGLONG LowestBitEverAllocated;
	/*0058*/ _MI_CACHED_PTES volatile * CachedPtes;
	/*0060*/ ULONGLONG volatile TotalFreeSystemPtes;
	/*0068*/
};

struct _MI_SYSTEM_TRIM_STATE {
	/*0000*/ ULONGLONG ExpansionLock;
	/*0008*/ LONG volatile TrimInProgressCount;
	/*0010*/ _KEVENT PeriodicWorkingSetEvent;
	/*0028*/ ULONG TrimAllPageFaultCount[0x3];
	/*0040*/
};

struct _MI_SYSTEM_VA_ASSIGNMENT {
	/*0000*/ void * BaseAddress;
	/*0008*/ ULONGLONG NumberOfBytes;
	/*0010*/
};

struct _MI_SYSTEM_VA_STATE {
	/*0000*/ ULONGLONG SystemTablesLock;
	/*0008*/ ULONGLONG AvailableSystemCacheVa;
	/*0010*/ _MI_DYNAMIC_BITMAP DynamicBitMapKernelStacks;
	/*0058*/ _MI_DYNAMIC_BITMAP DynamicBitMapSystemPtes;
	/*00a0*/ _MI_DYNAMIC_BITMAP DynamicBitMapDriverImages[0x2];
	/*0130*/ _MI_DYNAMIC_BITMAP DynamicBitMapPagedPool;
	/*0178*/ _MI_DYNAMIC_BITMAP DynamicBitMapSpecialPool[0x2];
	/*0208*/ _MI_DYNAMIC_BITMAP DynamicBitMapSystemCache;
	/*0250*/ void * HalPrivateVaStart;
	/*0258*/ ULONGLONG HalPrivateVaSize;
	/*0260*/ ULONG SystemVaAssignment[0x8];
	/*0280*/ ULONG SystemVaAssignmentHint;
	/*0284*/ LONG volatile DeleteKvaLock;
	/*0288*/ _MI_WSLE * WsleArrays[0x5];
	/*02b0*/ _MI_HYPER_SPACE * PagableHyperSpace;
	/*02b8*/ void * HyperSpaceEnd;
	/*02c0*/ _KEVENT FreeSystemCacheVa;
	/*02d8*/ ULONGLONG SystemVaLock;
	/*02e0*/ ULONGLONG SystemCacheViewLock;
	/*02e8*/ _MMWSL_INSTANCE SystemWorkingSetList[0x5];
	/*03c0*/
};

enum _MI_SYSTEM_VA_TYPE {
	MiVaUnused = 0x0,
	MiVaSessionSpace = 0x1,
	MiVaProcessSpace = 0x2,
	MiVaBootLoaded = 0x3,
	MiVaPfnDatabase = 0x4,
	MiVaNonPagedPool = 0x5,
	MiVaPagedPool = 0x6,
	MiVaSpecialPoolPaged = 0x7,
	MiVaSystemCache = 0x8,
	MiVaSystemPtes = 0x9,
	MiVaHal = 0xa,
	MiVaSessionGlobalSpace = 0xb,
	MiVaDriverImages = 0xc,
	MiVaSpecialPoolNonPaged = 0xd,
	MiVaSystemPtesLarge = 0xe,
	MiVaKernelStacks = 0xf,
	MiVaMaximumType = 0x10
};

struct _MI_TRIAGE_DUMP_DATA {
	/*0000*/ ULONGLONG BadPageCount;
	/*0008*/ LONG BadPagesDetected;
	/*000c*/ LONG ZeroedPageSingleBitErrorsDetected;
	/*0010*/ LONG ScrubPasses;
	/*0014*/ LONG ScrubBadPagesFound;
	/*0018*/ ULONG PageHashErrors;
	/*0020*/ ULONGLONG FeatureBits;
	/*0028*/ ULONG TimeZoneId;
	/*002c*/ _MI_FLAGS Flags;
	/*0030*/ void * VsmConnection;
	/*0038*/
};

struct _MI_ULTRA_MDL_NODE {
	/*0000*/ _MI_ALIGNED_SLIST UltraMdlMaps[0x8];
	/*0200*/
};

struct _MI_ULTRA_VA_CONTEXT {
	/*0000*/ ULONGLONG Lock;
	/*0008*/ void * ZeroMapping;
	/*0010*/ ULONGLONG AllocationHintBit;
	/*0018*/ _RTL_BITMAP_EX Bitmap[0x2];
	/*0038*/ LONG volatile ConcurrencyMaximum;
	/*003c*/ LONG volatile ConcurrencyCount;
	/*0040*/
};

enum _MI_VAD_64K_TYPES {
	MiVad64KPrivate = 0x0,
	MiVad64KShared = 0x1,
	MiVad64KTypes = 0x2
};

enum _MI_VAD_ALLOCATION_CELL_TYPE {
	MiVadBottomUp = 0x0,
	MiVadStackPebTeb = 0x1,
	MiVadAllocationCellMaximum = 0x2
};

struct _MI_VAD_EVENT_BLOCK {
	/*0000*/ _MI_VAD_EVENT_BLOCK * Next;
	/*0008*/ _KGATE Gate;
	/*0008*/ _MMADDRESS_LIST SecureInfo;
	/*0008*/ _RTL_BITMAP_EX BitMap;
	/*0008*/ _MMINPAGE_SUPPORT * InPageSupport;
	/*0008*/ _MI_LARGEPAGE_IMAGE_INFO LargePage;
	/*0008*/ _ETHREAD * CreatingThread;
	/*0008*/ _MI_SUB64K_FREE_RANGES PebTebRfg;
	/*0008*/ _MI_RFG_PROTECTED_STACK RfgProtectedStack;
	/*0040*/ ULONG WaitReason;
	/*0048*/
};

struct _MI_VAD_SEQUENTIAL_INFO {
	/*0000*/ ULONGLONG Length : 12; // 0x0000000000000fff;
	/*0000*/ ULONGLONG Vpn : 52; // 0xfffffffffffff000;
	/*0008*/
};

struct _MI_VERIFIER_POOL_HEADER {
	/*0000*/ _VI_POOL_ENTRY * VerifierPoolEntry;
	/*0008*/
};

struct _MI_VISIBLE_PARTITION {
	/*0000*/ ULONGLONG LowestPhysicalPage;
	/*0008*/ ULONGLONG HighestPhysicalPage;
	/*0010*/ ULONGLONG NumberOfPhysicalPages;
	/*0018*/ ULONG volatile NumberOfPagingFiles;
	/*001c*/ UCHAR SystemCacheInitialized;
	/*0020*/ _MMPAGING_FILE * PagingFile[0x10];
	/*00c0*/ ULONGLONG volatile AvailablePages;
	/*0100*/ ULONGLONG volatile ResidentAvailablePages;
	/*0140*/ _MMSUPPORT_INSTANCE PartitionWs[0x1];
	/*0208*/ _MMWSL_INSTANCE PartitionWorkingSetLists[0x1];
	/*0230*/ ULONGLONG volatile TotalCommittedPages;
	/*0240*/ _MMPFNLIST ModifiedPageListHead;
	/*0280*/ _MMPFNLIST ModifiedNoWritePageListHead;
	/*02a8*/ ULONGLONG TotalCommitLimit;
	/*02b0*/ ULONGLONG TotalPagesForPagingFile;
	/*02b8*/ ULONGLONG VadPhysicalPages;
	/*02c0*/ ULONGLONG ProcessLockedFilePages;
	/*02c8*/ ULONGLONG volatile SharedCommit;
	/*02d0*/ ULONG ChargeCommitmentFailures[0x4];
	/*02e0*/ LONG volatile PageFileTraceIndex;
	/*02e8*/ _MI_PAGEFILE_TRACES PageFileTraces[0x20];
	/*1200*/
};

struct _MI_VISIBLE_STATE {
	/*0000*/ _MI_SPECIAL_POOL SpecialPool;
	/*0040*/ _LIST_ENTRY SessionWsList;
	/*0050*/ _RTL_BITMAP * SessionIdBitmap;
	/*0058*/ _MM_PAGED_POOL_INFO PagedPoolInfo;
	/*0090*/ ULONGLONG MaximumNonPagedPoolInPages;
	/*0098*/ ULONGLONG SizeOfPagedPoolInPages;
	/*00a0*/ _MI_SYSTEM_PTE_TYPE SystemPteInfo;
	/*0108*/ ULONGLONG volatile NonPagedPoolCommit;
	/*0110*/ ULONGLONG volatile SmallNonPagedPtesCommit;
	/*0118*/ ULONGLONG volatile BootCommit;
	/*0120*/ ULONGLONG volatile MdlPagesAllocated;
	/*0128*/ ULONGLONG volatile SystemPageTableCommit;
	/*0130*/ ULONGLONG volatile SpecialPagesInUse;
	/*0138*/ ULONGLONG volatile ProcessCommit;
	/*0140*/ LONG volatile DriverCommit;
	/*0148*/ ULONGLONG PfnDatabaseCommit;
	/*0180*/ _MMSUPPORT_FULL SystemWs[0x3];
	/*04c0*/ _MMSUPPORT_SHARED SystemCacheShared;
	/*0540*/ _MMSUPPORT_AGGREGATION AggregateSystemWs[0x1];
	/*0560*/ ULONG MapCacheFailures;
	/*0568*/ ULONGLONG PagefileHashPages;
	/*0570*/ _SYSPTES_HEADER PteHeader;
	/*0688*/ _MI_SPECIAL_POOL * SessionSpecialPool;
	/*0690*/ ULONGLONG SystemVaTypeCount[0x10];
	/*0710*/ UCHAR SystemVaType[0x100];
	/*0810*/ _MI_SYSTEM_VA_ASSIGNMENT SystemVaRegions[0xe];
	/*0900*/
};

enum _MI_WORKING_SET_TYPE {
	MiWorkingSetTypeSystemCache = 0x0,
	MiWorkingSetTypeSystemPtes = 0x1,
	MiWorkingSetTypePartitionMaximum = 0x1,
	MiWorkingSetTypePagedPool = 0x2,
	MiWorkingSetTypeMaximum = 0x3
};

struct _MI_WSLE {
	union {
		struct {
			/*0000*/ UCHAR Age : 04; // 0x0f;
			/*0000*/ UCHAR Protection : 03; // 0x70;
			/*0000*/ UCHAR Reserved : 01; // 0x80;
			/*0001*/
		} e1;
		struct {
			/*0000*/ UCHAR EntireWsle;
			/*0001*/
		} e2;
		/*0001*/
	} u1;
	/*0001*/
};

struct _MI_ZERO_COST_COUNTS {
	/*0000*/ ULONGLONG NativeSum;
	/*0008*/ ULONGLONG CachedSum;
	/*0010*/
};

struct _MI_ZERO_THREAD_CONTEXT;

struct _MMADDRESS_LIST {
	union {
		/*0000*/ _MMSECURE_FLAGS Flags;
		/*0000*/ ULONG FlagsLong;
		/*0000*/ void * StartVa;
		/*0008*/
	} u1;
	/*0008*/ void * EndVa;
	/*0010*/
};

struct _MMCLONE_BLOCK {
	/*0000*/ _MMPTE ProtoPte;
	/*0008*/ ULONGLONG CrossPartitionReferences;
	/*0010*/ ULONGLONG volatile CloneCommitCount;
	/*0010*/ _MI_CLONE_BLOCK_FLAGS u1;
	/*0018*/ ULONGLONG volatile CloneRefCount;
	/*0020*/
};

struct _MMCLONE_DESCRIPTOR {
	/*0000*/ _RTL_BALANCED_NODE CloneNode;
	/*0000*/ _MMCLONE_DESCRIPTOR * Next;
	/*0018*/ _MMCLONE_BLOCK * StartingCloneBlock;
	/*0020*/ _MMCLONE_BLOCK * EndingCloneBlock;
	/*0028*/ ULONGLONG NumberOfPtes;
	/*0030*/ ULONGLONG volatile NumberOfReferences;
	/*0038*/ _MMCLONE_HEADER * CloneHeader;
	/*0040*/ ULONGLONG NonPagedPoolQuotaCharge;
	/*0048*/ ULONGLONG NestingLevel;
	/*0050*/
};

struct _MMCLONE_HEADER {
	/*0000*/ ULONGLONG NumberOfPtes;
	/*0008*/ ULONGLONG volatile NumberOfProcessReferences;
	/*0010*/ _MMCLONE_BLOCK * ClonePtes;
	/*0018*/ _MI_PARTITION * Partition;
	/*0020*/
};

struct _MMDEREFERENCE_SEGMENT_HEADER {
	/*0000*/ _KSEMAPHORE Semaphore;
	/*0020*/ _LIST_ENTRY ControlAreaDeleteListHead;
	/*0030*/ _LIST_ENTRY UnusedSegmentDeleteListHead;
	/*0040*/ _LIST_ENTRY PagefileExtensionListHead;
	/*0050*/
};

struct _MMEXTEND_INFO {
	/*0000*/ ULONGLONG CommittedSize;
	/*0008*/ ULONG ReferenceCount;
	/*0010*/
};

struct _MMINPAGE_FLAGS {
	/*0000*/ UCHAR InjectRetry : 01; // 0x01;
	/*0000*/ UCHAR GetExtents : 01; // 0x02;
	/*0000*/ UCHAR CrossThreadPadding : 06; // 0xfc;
	/*0001*/ UCHAR PrefetchSystemVmType : 02; // 0x03;
	/*0001*/ UCHAR VaPrefetchReadBlock : 01; // 0x04;
	/*0001*/ UCHAR CollidedFlowThrough : 01; // 0x08;
	/*0001*/ UCHAR ForceCollisions : 01; // 0x10;
	/*0001*/ UCHAR InPageExpanded : 01; // 0x20;
	/*0001*/ UCHAR IssuedAtLowPriority : 01; // 0x40;
	/*0001*/ UCHAR FaultFromStore : 01; // 0x80;
	/*0002*/ UCHAR PagePriority : 03; // 0x07;
	/*0002*/ UCHAR PerformRelocations : 01; // 0x08;
	/*0002*/ UCHAR ClusteredPagePriority : 03; // 0x70;
	/*0002*/ UCHAR MakeClusterValid : 01; // 0x80;
	/*0003*/ UCHAR ZeroLastPage : 01; // 0x01;
	/*0003*/ UCHAR UserFault : 01; // 0x02;
	/*0003*/ UCHAR StandbyProtectionNeeded : 01; // 0x04;
	/*0003*/ UCHAR PteChanged : 01; // 0x08;
	/*0003*/ UCHAR PageFileFault : 01; // 0x10;
	/*0003*/ UCHAR PageFilePageHashActive : 01; // 0x20;
	/*0003*/ UCHAR CoalescedIo : 01; // 0x40;
	/*0003*/ UCHAR VmLockNotNeeded : 01; // 0x80;
	/*0004*/
};

struct _MMINPAGE_SUPPORT {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _LIST_ENTRY ListHead;
	/*0020*/ _KEVENT Event;
	/*0038*/ _KEVENT CollidedEvent;
	/*0050*/ _IO_STATUS_BLOCK IoStatus;
	/*0060*/ _LARGE_INTEGER ReadOffset;
	/*0068*/ _KAPC_STATE ApcState;
	/*0098*/ _ETHREAD * Thread;
	/*00a0*/ _MMPFN * LockedProtoPfn;
	/*00a8*/ _MMPTE PteContents;
	/*00b0*/ LONG volatile WaitCount;
	/*00b4*/ ULONG ByteCount;
	union {
		/*00b8*/ ULONG ImagePteOffset;
		/*00b8*/ ULONG TossPage;
		/*00bc*/
	} u3;
	union {
		/*00bc*/ _MMINPAGE_FLAGS e1;
		/*00bc*/ ULONG LongFlags;
		/*00c0*/
	} u1;
	/*00c0*/ _FILE_OBJECT * FilePointer;
	/*00c8*/ _CONTROL_AREA * ControlArea;
	/*00c8*/ _SUBSECTION * Subsection;
	/*00d0*/ void * Autoboost;
	/*00d8*/ void * FaultingAddress;
	/*00e0*/ _MMPTE * PointerPte;
	/*00e8*/ _MMPTE * BasePte;
	/*00f0*/ _MMPFN * Pfn;
	/*00f8*/ _MDL * PrefetchMdl;
	/*0100*/ _MDL Mdl;
	/*0130*/ ULONGLONG Page[0x10];
	/*0130*/ _MMINPAGE_SUPPORT_FLOW_THROUGH FlowThrough;
	/*01b0*/
};

struct _MMINPAGE_SUPPORT_FLOW_THROUGH {
	/*0000*/ ULONGLONG Page[0x1];
	/*0008*/ _MMINPAGE_SUPPORT * InitialInPageSupport;
	/*0010*/ _MMPAGING_FILE * PagingFile;
	/*0018*/ ULONGLONG PageFileOffset;
	/*0020*/ _RTL_BALANCED_NODE Node;
	/*0038*/
};

enum _MMLISTS {
	ZeroedPageList = 0x0,
	FreePageList = 0x1,
	StandbyPageList = 0x2,
	ModifiedPageList = 0x3,
	ModifiedNoWritePageList = 0x4,
	BadPageList = 0x5,
	ActiveAndValid = 0x6,
	TransitionPage = 0x7
};

struct _MMMOD_WRITER_LISTHEAD {
	/*0000*/ _LIST_ENTRY ListHead;
	/*0010*/ _KGATE Gate;
	/*0010*/ _KEVENT Event;
	/*0028*/
};

struct _MMMOD_WRITER_MDL_ENTRY {
	/*0000*/ _LIST_ENTRY Links;
	union {
		/*0010*/ _IO_STATUS_BLOCK IoStatus;
		/*0020*/
	} u;
	/*0020*/ _IRP * Irp;
	/*0028*/ _MODWRITER_FLAGS u1;
	/*002c*/ ULONG StoreWriteRefCount;
	/*0030*/ _KAPC StoreWriteCompletionApc;
	/*0088*/ ULONG ByteCount;
	/*008c*/ ULONG ChargedPages;
	/*0090*/ _MMPAGING_FILE * PagingFile;
	/*0098*/ _FILE_OBJECT * File;
	/*00a0*/ _CONTROL_AREA * ControlArea;
	/*00a8*/ _ERESOURCE * FileResource;
	/*00b0*/ _LARGE_INTEGER WriteOffset;
	/*00b8*/ _LARGE_INTEGER IssueTime;
	/*00c0*/ _MI_PARTITION * Partition;
	/*00c8*/ _MDL * PointerMdl;
	/*00d0*/ _MDL Mdl;
	/*0100*/ ULONGLONG Page[0x1];
	/*0108*/
};

struct _MMPAGE_FILE_EXPANSION {
	/*0000*/ _SEGMENT * Segment;
	/*0008*/ _LIST_ENTRY DereferenceList;
	/*0018*/ _MI_PARTITION * Partition;
	/*0020*/ ULONGLONG RequestedExpansionSize;
	/*0028*/ ULONGLONG ActualExpansion;
	/*0030*/ _KEVENT Event;
	/*0048*/ LONG volatile InProgress;
	union {
		/*004c*/ ULONG LongFlags;
		/*004c*/ _MMPAGE_FILE_EXPANSION_FLAGS Flags;
		/*0050*/
	} u1;
	/*0050*/ void * * volatile ActiveEntry;
	/*0058*/
};

struct _MMPAGE_FILE_EXPANSION_FLAGS {
	/*0000*/ UCHAR PageFileNumber : 08; // 0xff;
	/*0001*/ UCHAR Spare1 : 08; // 0xff;
	/*0002*/ UCHAR Spare2 : 08; // 0xff;
	/*0003*/ UCHAR IgnoreCurrentCommit : 01; // 0x01;
	/*0003*/ UCHAR IncreaseMinimumSize : 01; // 0x02;
	/*0003*/ UCHAR AttemptForCantExtend : 01; // 0x04;
	/*0003*/ UCHAR UnusedSegmentDeletion : 01; // 0x08;
	/*0003*/ UCHAR PageFileContract : 01; // 0x10;
	/*0003*/ UCHAR Spare3 : 03; // 0xe0;
	/*0004*/
};

struct _MMPAGING_FILE {
	/*0000*/ ULONGLONG Size;
	/*0008*/ ULONGLONG MaximumSize;
	/*0010*/ ULONGLONG MinimumSize;
	/*0018*/ ULONGLONG FreeSpace;
	/*0020*/ ULONGLONG PeakUsage;
	/*0028*/ ULONGLONG HighestPage;
	/*0030*/ ULONGLONG FreeReservationSpace;
	/*0038*/ _FILE_OBJECT * File;
	/*0040*/ _MMMOD_WRITER_MDL_ENTRY * Entry[0x2];
	/*0050*/ _SLIST_HEADER PfnsToFree;
	/*0060*/ _UNICODE_STRING PageFileName;
	/*0070*/ _MI_PAGING_FILE_SPACE_BITMAPS * Bitmaps;
	/*0078*/ ULONG AllocationBitmapHint;
	/*007c*/ ULONG LargestAllocationCluster;
	/*0080*/ ULONG RefreshAllocationCluster;
	/*0084*/ ULONG LastRefreshAllocationCluster;
	/*0088*/ ULONG ReservedClusterSizeAggregate;
	/*008c*/ ULONG MaximumRunLengthInBitmaps;
	/*0090*/ _RTL_RB_TREE BitmapsCacheLengthTree;
	/*00a0*/ _RTL_RB_TREE BitmapsCacheLocationTree;
	/*00b0*/ _LIST_ENTRY BitmapsCacheFreeList;
	/*00c0*/ _MI_PAGEFILE_BITMAPS_CACHE_ENTRY * BitmapsCacheEntries;
	/*00c8*/ ULONG ToBeEvictedCount;
	/*00c8*/ ULONG HybridPriority;
	/*00cc*/ USHORT PageFileNumber : 04; // 0x000f;
	/*00cc*/ USHORT WsSwapPagefile : 01; // 0x0010;
	/*00cc*/ USHORT NoReservations : 01; // 0x0020;
	/*00cc*/ USHORT VirtualStorePagefile : 01; // 0x0040;
	/*00cc*/ USHORT SwapSupported : 01; // 0x0080;
	/*00cc*/ USHORT NodeInserted : 01; // 0x0100;
	/*00cc*/ USHORT StackNotified : 01; // 0x0200;
	/*00cc*/ USHORT BackedBySCM : 01; // 0x0400;
	/*00cc*/ USHORT Spare0 : 04; // 0x7800;
	/*00ce*/ UCHAR AdriftMdls : 01; // 0x01;
	/*00ce*/ UCHAR Spare1 : 07; // 0xfe;
	/*00cf*/ UCHAR IgnoreReservations : 01; // 0x01;
	/*00cf*/ UCHAR Spare2 : 07; // 0xfe;
	/*00d0*/ ULONG PageHashPages;
	/*00d4*/ ULONG PageHashPagesPeak;
	/*00d8*/ ULONG * PageHash;
	/*00e0*/ void * FileHandle;
	/*00e8*/ ULONGLONG Lock;
	/*00f0*/ _ETHREAD * LockOwner;
	/*00f8*/ _RTL_AVL_TREE FlowThroughReadRoot;
	/*0100*/ _MI_PARTITION * Partition;
	/*0108*/ _RTL_BALANCED_NODE FileObjectNode;
	/*0120*/
};

struct _MMPFN {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0000*/ _RTL_BALANCED_NODE TreeNode;
	union {
		/*0000*/ _SINGLE_LIST_ENTRY NextSlistPfn;
		/*0000*/ void * Next;
		/*0000*/ ULONGLONG Flink : 36; // 0x0000000fffffffff;
		/*0000*/ ULONGLONG NodeFlinkHigh : 28; // 0xfffffff000000000;
		/*0000*/ _MI_ACTIVE_PFN Active;
		/*0008*/
	} u1;
	/*0008*/ _MMPTE * PteAddress;
	/*0008*/ void * volatile VolatilePteAddress;
	/*0008*/ ULONGLONG PteLong;
	/*0010*/ _MMPTE OriginalPte;
	/*0018*/ _MIPFNBLINK u2;
	union {
		/*0020*/ USHORT ReferenceCount;
		/*0022*/ _MMPFNENTRY1 e1;
		/*0023*/ _MMPFNENTRY3 e3;
		struct {
			/*0020*/ USHORT ReferenceCount;
			/*0022*/
		} e2;
		struct {
			/*0020*/ ULONG EntireField;
			/*0024*/
		} e4;
		/*0024*/
	} u3;
	/*0024*/ USHORT NodeBlinkLow;
	/*0026*/ UCHAR Unused : 04; // 0x0f;
	/*0026*/ UCHAR Unused2 : 04; // 0xf0;
	/*0027*/ UCHAR ViewCount;
	/*0027*/ UCHAR NodeFlinkLow;
	union {
		/*0028*/ ULONGLONG PteFrame : 36; // 0x0000000fffffffff;
		/*0028*/ ULONGLONG Channel : 02; // 0x0000003000000000;
		/*0028*/ ULONGLONG Unused1 : 01; // 0x0000004000000000;
		/*0028*/ ULONGLONG Unused2 : 01; // 0x0000008000000000;
		/*0028*/ ULONGLONG Partition : 10; // 0x0003ff0000000000;
		/*0028*/ ULONGLONG Spare : 02; // 0x000c000000000000;
		/*0028*/ ULONGLONG FileOnly : 01; // 0x0010000000000000;
		/*0028*/ ULONGLONG PfnExists : 01; // 0x0020000000000000;
		/*0028*/ ULONGLONG PageIdentity : 03; // 0x01c0000000000000;
		/*0028*/ ULONGLONG PrototypePte : 01; // 0x0200000000000000;
		/*0028*/ ULONGLONG PageColor : 06; // 0xfc00000000000000;
		/*0028*/ ULONGLONG EntireField;
		/*0030*/
	} u4;
	/*0030*/
};

struct _MMPFNENTRY1 {
	/*0000*/ UCHAR PageLocation : 03; // 0x07;
	/*0000*/ UCHAR WriteInProgress : 01; // 0x08;
	/*0000*/ UCHAR Modified : 01; // 0x10;
	/*0000*/ UCHAR ReadInProgress : 01; // 0x20;
	/*0000*/ UCHAR CacheAttribute : 02; // 0xc0;
	/*0001*/
};

struct _MMPFNENTRY3 {
	/*0000*/ UCHAR Priority : 03; // 0x07;
	/*0000*/ UCHAR OnProtectedStandby : 01; // 0x08;
	/*0000*/ UCHAR InPageError : 01; // 0x10;
	/*0000*/ UCHAR SystemChargedPage : 01; // 0x20;
	/*0000*/ UCHAR RemovalRequested : 01; // 0x40;
	/*0000*/ UCHAR ParityError : 01; // 0x80;
	/*0001*/
};

struct _MMPFNLIST {
	/*0000*/ ULONGLONG Total;
	/*0008*/ _MMLISTS ListName;
	/*0010*/ ULONGLONG Flink;
	/*0018*/ ULONGLONG Blink;
	/*0020*/ ULONGLONG Lock;
	/*0028*/
};

struct _MMPFNLIST_SHORT {
	/*0000*/ ULONGLONG Total;
	/*0008*/ ULONGLONG Flink;
	/*0010*/ ULONGLONG Blink;
	/*0018*/
};

struct _MMPTE {
	union {
		/*0000*/ ULONGLONG Long;
		/*0000*/ ULONGLONG volatile VolatileLong;
		/*0000*/ _MMPTE_HARDWARE Hard;
		/*0000*/ _HARDWARE_PTE Flush;
		/*0000*/ _MMPTE_PROTOTYPE Proto;
		/*0000*/ _MMPTE_SOFTWARE Soft;
		/*0000*/ _MMPTE_TIMESTAMP TimeStamp;
		/*0000*/ _MMPTE_TRANSITION Trans;
		/*0000*/ _MMPTE_SUBSECTION Subsect;
		/*0000*/ _MMPTE_LIST List;
		/*0008*/
	} u;
	/*0008*/
};

struct _MMPTE_HARDWARE {
	/*0000*/ ULONGLONG Valid : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG Dirty1 : 01; // 0x0000000000000002;
	/*0000*/ ULONGLONG Owner : 01; // 0x0000000000000004;
	/*0000*/ ULONGLONG WriteThrough : 01; // 0x0000000000000008;
	/*0000*/ ULONGLONG CacheDisable : 01; // 0x0000000000000010;
	/*0000*/ ULONGLONG Accessed : 01; // 0x0000000000000020;
	/*0000*/ ULONGLONG Dirty : 01; // 0x0000000000000040;
	/*0000*/ ULONGLONG LargePage : 01; // 0x0000000000000080;
	/*0000*/ ULONGLONG Global : 01; // 0x0000000000000100;
	/*0000*/ ULONGLONG CopyOnWrite : 01; // 0x0000000000000200;
	/*0000*/ ULONGLONG Unused : 01; // 0x0000000000000400;
	/*0000*/ ULONGLONG Write : 01; // 0x0000000000000800;
	/*0000*/ ULONGLONG PageFrameNumber : 36; // 0x0000fffffffff000;
	/*0000*/ ULONGLONG ReservedForHardware : 04; // 0x000f000000000000;
	/*0000*/ ULONGLONG ReservedForSoftware : 04; // 0x00f0000000000000;
	/*0000*/ ULONGLONG WsleAge : 04; // 0x0f00000000000000;
	/*0000*/ ULONGLONG WsleProtection : 03; // 0x7000000000000000;
	/*0000*/ ULONGLONG NoExecute : 01; // 0x8000000000000000;
	/*0008*/
};

struct _MMPTE_LIST {
	/*0000*/ ULONGLONG Valid : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG OneEntry : 01; // 0x0000000000000002;
	/*0000*/ ULONGLONG filler0 : 03; // 0x000000000000001c;
	/*0000*/ ULONGLONG Protection : 05; // 0x00000000000003e0;
	/*0000*/ ULONGLONG Prototype : 01; // 0x0000000000000400;
	/*0000*/ ULONGLONG Transition : 01; // 0x0000000000000800;
	/*0000*/ ULONGLONG filler1 : 16; // 0x000000000ffff000;
	/*0000*/ ULONGLONG NextEntry : 36; // 0xfffffffff0000000;
	/*0008*/
};

struct _MMPTE_PROTOTYPE {
	/*0000*/ ULONGLONG Valid : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG DemandFillProto : 01; // 0x0000000000000002;
	/*0000*/ ULONGLONG HiberVerifyConverted : 01; // 0x0000000000000004;
	/*0000*/ ULONGLONG Unused1 : 05; // 0x00000000000000f8;
	/*0000*/ ULONGLONG ReadOnly : 01; // 0x0000000000000100;
	/*0000*/ ULONGLONG Combined : 01; // 0x0000000000000200;
	/*0000*/ ULONGLONG Prototype : 01; // 0x0000000000000400;
	/*0000*/ ULONGLONG Protection : 05; // 0x000000000000f800;
	/*0000*/ LONGLONG ProtoAddress : 48; // 0xffffffffffff0000;
	/*0008*/
};

struct _MMPTE_SOFTWARE {
	/*0000*/ ULONGLONG Valid : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG PageFileLow : 04; // 0x000000000000001e;
	/*0000*/ ULONGLONG Protection : 05; // 0x00000000000003e0;
	/*0000*/ ULONGLONG Prototype : 01; // 0x0000000000000400;
	/*0000*/ ULONGLONG Transition : 01; // 0x0000000000000800;
	/*0000*/ ULONGLONG PageFileReserved : 01; // 0x0000000000001000;
	/*0000*/ ULONGLONG PageFileAllocated : 01; // 0x0000000000002000;
	/*0000*/ ULONGLONG UsedPageTableEntries : 10; // 0x0000000000ffc000;
	/*0000*/ ULONGLONG Unused : 08; // 0x00000000ff000000;
	/*0000*/ ULONGLONG PageFileHigh : 32; // 0xffffffff00000000;
	/*0008*/
};

struct _MMPTE_SUBSECTION {
	/*0000*/ ULONGLONG Valid : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG Unused0 : 04; // 0x000000000000001e;
	/*0000*/ ULONGLONG Protection : 05; // 0x00000000000003e0;
	/*0000*/ ULONGLONG Prototype : 01; // 0x0000000000000400;
	/*0000*/ ULONGLONG Unused1 : 04; // 0x0000000000007800;
	/*0000*/ ULONGLONG ExecutePrivilege : 01; // 0x0000000000008000;
	/*0000*/ LONGLONG SubsectionAddress : 48; // 0xffffffffffff0000;
	/*0008*/
};

struct _MMPTE_TIMESTAMP {
	/*0000*/ ULONGLONG MustBeZero : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG PageFileLow : 04; // 0x000000000000001e;
	/*0000*/ ULONGLONG Protection : 05; // 0x00000000000003e0;
	/*0000*/ ULONGLONG Prototype : 01; // 0x0000000000000400;
	/*0000*/ ULONGLONG Transition : 01; // 0x0000000000000800;
	/*0000*/ ULONGLONG Reserved : 20; // 0x00000000fffff000;
	/*0000*/ ULONGLONG GlobalTimeStamp : 32; // 0xffffffff00000000;
	/*0008*/
};

struct _MMPTE_TRANSITION {
	/*0000*/ ULONGLONG Valid : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG Write : 01; // 0x0000000000000002;
	/*0000*/ ULONGLONG Spare : 02; // 0x000000000000000c;
	/*0000*/ ULONGLONG IoTracker : 01; // 0x0000000000000010;
	/*0000*/ ULONGLONG Protection : 05; // 0x00000000000003e0;
	/*0000*/ ULONGLONG Prototype : 01; // 0x0000000000000400;
	/*0000*/ ULONGLONG Transition : 01; // 0x0000000000000800;
	/*0000*/ ULONGLONG PageFrameNumber : 36; // 0x0000fffffffff000;
	/*0000*/ ULONGLONG Unused : 16; // 0xffff000000000000;
	/*0008*/
};

struct _MMSECTION_FLAGS {
	/*0000*/ UINT BeingDeleted : 01; // 0x00000001;
	/*0000*/ UINT BeingCreated : 01; // 0x00000002;
	/*0000*/ UINT BeingPurged : 01; // 0x00000004;
	/*0000*/ UINT NoModifiedWriting : 01; // 0x00000008;
	/*0000*/ UINT FailAllIo : 01; // 0x00000010;
	/*0000*/ UINT Image : 01; // 0x00000020;
	/*0000*/ UINT Based : 01; // 0x00000040;
	/*0000*/ UINT File : 01; // 0x00000080;
	/*0000*/ UINT AttemptingDelete : 01; // 0x00000100;
	/*0000*/ UINT PrefetchCreated : 01; // 0x00000200;
	/*0000*/ UINT PhysicalMemory : 01; // 0x00000400;
	/*0000*/ UINT ImageControlAreaOnRemovableMedia : 01; // 0x00000800;
	/*0000*/ UINT Reserve : 01; // 0x00001000;
	/*0000*/ UINT Commit : 01; // 0x00002000;
	/*0000*/ UINT NoChange : 01; // 0x00004000;
	/*0000*/ UINT WasPurged : 01; // 0x00008000;
	/*0000*/ UINT UserReference : 01; // 0x00010000;
	/*0000*/ UINT GlobalMemory : 01; // 0x00020000;
	/*0000*/ UINT DeleteOnClose : 01; // 0x00040000;
	/*0000*/ UINT FilePointerNull : 01; // 0x00080000;
	/*0000*/ UINT PreferredNode : 06; // 0x03f00000;
	/*0000*/ UINT GlobalOnlyPerSession : 01; // 0x04000000;
	/*0000*/ UINT UserWritable : 01; // 0x08000000;
	/*0000*/ UINT SystemVaAllocated : 01; // 0x10000000;
	/*0000*/ UINT PreferredFsCompressionBoundary : 01; // 0x20000000;
	/*0000*/ UINT UsingFileExtents : 01; // 0x40000000;
	/*0000*/ UINT PageSize64K : 01; // 0x80000000;
	/*0004*/
};

struct _MMSECTION_FLAGS2 {
	/*0000*/ USHORT PartitionId : 10; // 0x03ff;
	/*0002*/ UCHAR NoCrossPartitionAccess : 01; // 0x01;
	/*0002*/ UCHAR SubsectionCrossPartitionReferenceOverflow : 01; // 0x02;
	/*0004*/
};

struct _MMSECURE_FLAGS {
	/*0000*/ ULONG ReadOnly : 01; // 0x00000001;
	/*0000*/ ULONG ReadWrite : 01; // 0x00000002;
	/*0000*/ ULONG SecNoChange : 01; // 0x00000004;
	/*0000*/ ULONG NoDelete : 01; // 0x00000008;
	/*0000*/ ULONG RequiresPteReversal : 01; // 0x00000010;
	/*0000*/ ULONG ExclusiveSecure : 01; // 0x00000020;
	/*0000*/ ULONG Spare : 06; // 0x00000fc0;
	/*0004*/
};

struct _MMSESSION {
	/*0000*/ _EX_PUSH_LOCK SystemSpaceViewLock;
	/*0008*/ _EX_PUSH_LOCK * SystemSpaceViewLockPointer;
	/*0010*/ _RTL_AVL_TREE ViewRoot;
	/*0018*/ ULONG ViewCount;
	/*001c*/ ULONG BitmapFailures;
	/*0020*/
};

struct _MMSUBSECTION_FLAGS {
	/*0000*/ USHORT SubsectionAccessed : 01; // 0x0001;
	/*0000*/ USHORT Protection : 05; // 0x003e;
	/*0000*/ USHORT StartingSector4132 : 10; // 0xffc0;
	/*0002*/ USHORT SubsectionStatic : 01; // 0x0001;
	/*0002*/ USHORT GlobalMemory : 01; // 0x0002;
	/*0002*/ USHORT Spare : 01; // 0x0004;
	/*0002*/ USHORT OnDereferenceList : 01; // 0x0008;
	/*0002*/ USHORT SectorEndOffset : 12; // 0xfff0;
	/*0004*/
};

struct _MMSUPPORT_AGGREGATION {
	/*0000*/ ULONG PageFaultCount;
	/*0008*/ ULONGLONG WorkingSetSize;
	/*0010*/ ULONGLONG WorkingSetLeafSize;
	/*0018*/ ULONGLONG PeakWorkingSetSize;
	/*0020*/
};

struct _MMSUPPORT_FLAGS {
	/*0000*/ UCHAR WorkingSetType : 03; // 0x07;
	/*0000*/ UCHAR Reserved0 : 03; // 0x38;
	/*0000*/ UCHAR MaximumWorkingSetHard : 01; // 0x40;
	/*0000*/ UCHAR MinimumWorkingSetHard : 01; // 0x80;
	/*0001*/ UCHAR SessionMaster : 01; // 0x01;
	/*0001*/ UCHAR TrimmerState : 02; // 0x06;
	/*0001*/ UCHAR Reserved : 01; // 0x08;
	/*0001*/ UCHAR PageStealers : 04; // 0xf0;
	/*0000*/ USHORT u1;
	/*0002*/ UCHAR MemoryPriority;
	/*0003*/ UCHAR WsleDeleted : 01; // 0x01;
	/*0003*/ UCHAR SvmEnabled : 01; // 0x02;
	/*0003*/ UCHAR ForceAge : 01; // 0x04;
	/*0003*/ UCHAR ForceTrim : 01; // 0x08;
	/*0003*/ UCHAR NewMaximum : 01; // 0x10;
	/*0003*/ UCHAR CommitReleaseState : 02; // 0x60;
	/*0003*/ UCHAR u2;
	/*0004*/
};

struct _MMSUPPORT_FULL {
	/*0000*/ _MMSUPPORT_INSTANCE Instance;
	/*00c8*/ _MMSUPPORT_SHARED Shared;
	/*0110*/
};

struct _MMSUPPORT_INSTANCE {
	/*0000*/ USHORT NextPageColor;
	/*0002*/ USHORT LastTrimStamp;
	/*0004*/ ULONG PageFaultCount;
	/*0008*/ ULONGLONG TrimmedPageCount;
	/*0010*/ _MMWSL_INSTANCE * VmWorkingSetList;
	/*0018*/ _LIST_ENTRY WorkingSetExpansionLinks;
	/*0028*/ ULONGLONG AgeDistribution[0x8];
	/*0068*/ _KGATE * ExitOutswapGate;
	/*0070*/ ULONGLONG MinimumWorkingSetSize;
	/*0078*/ ULONGLONG WorkingSetLeafSize;
	/*0080*/ ULONGLONG WorkingSetLeafPrivateSize;
	/*0088*/ ULONGLONG WorkingSetSize;
	/*0090*/ ULONGLONG WorkingSetPrivateSize;
	/*0098*/ ULONGLONG MaximumWorkingSetSize;
	/*00a0*/ ULONGLONG PeakWorkingSetSize;
	/*00a8*/ ULONG HardFaultCount;
	/*00ac*/ USHORT PartitionId;
	/*00ae*/ USHORT Pad0;
	union {
		/*00b0*/ void * InstancedWorkingSet;
		/*00b8*/
	} u1;
	/*00b8*/ ULONGLONG Reserved0;
	/*00c0*/ _MMSUPPORT_FLAGS Flags;
	/*00c8*/
};

struct _MMSUPPORT_SHARED {
	/*0000*/ LONG volatile WorkingSetLock;
	/*0004*/ LONG GoodCitizenWaiting;
	/*0008*/ ULONGLONG ReleasedCommitDebt;
	/*0010*/ ULONGLONG ResetPagesRepurposedCount;
	/*0018*/ void * WsSwapSupport;
	/*0020*/ void * CommitReleaseContext;
	/*0028*/ void * AccessLog;
	/*0030*/ ULONGLONG volatile ChargedWslePages;
	/*0038*/ ULONGLONG ActualWslePages;
	/*0040*/ ULONGLONG Reserved0;
	/*0048*/
};

struct _MMVAD {
	/*0000*/ _MMVAD_SHORT Core;
	union {
		/*0040*/ ULONG LongFlags2;
		/*0040*/ _MMVAD_FLAGS2 VadFlags2;
		/*0044*/
	} u2;
	/*0048*/ _SUBSECTION * Subsection;
	/*0050*/ _MMPTE * FirstPrototypePte;
	/*0058*/ _MMPTE * LastContiguousPte;
	/*0060*/ _LIST_ENTRY ViewLinks;
	/*0070*/ _EPROCESS * VadsProcess;
	union {
		/*0078*/ _MI_VAD_SEQUENTIAL_INFO SequentialVa;
		/*0078*/ _MMEXTEND_INFO * ExtendedInfo;
		/*0080*/
	} u4;
	/*0080*/ _FILE_OBJECT * FileObject;
	/*0088*/
};

struct _MMVAD_FLAGS {
	/*0000*/ ULONG VadType : 03; // 0x00000007;
	/*0000*/ ULONG Protection : 05; // 0x000000f8;
	/*0000*/ ULONG PreferredNode : 06; // 0x00003f00;
	/*0000*/ ULONG NoChange : 01; // 0x00004000;
	/*0000*/ ULONG PrivateMemory : 01; // 0x00008000;
	/*0000*/ ULONG PrivateFixup : 01; // 0x00010000;
	/*0000*/ ULONG ManySubsections : 01; // 0x00020000;
	/*0000*/ ULONG Enclave : 01; // 0x00040000;
	/*0000*/ ULONG DeleteInProgress : 01; // 0x00080000;
	/*0000*/ ULONG PageSize64K : 01; // 0x00100000;
	/*0000*/ ULONG RfgControlStack : 01; // 0x00200000;
	/*0000*/ ULONG Spare : 10; // 0xffc00000;
	/*0004*/
};

struct _MMVAD_FLAGS1 {
	/*0000*/ ULONG CommitCharge : 31; // 0x7fffffff;
	/*0000*/ ULONG MemCommit : 01; // 0x80000000;
	/*0004*/
};

struct _MMVAD_FLAGS2 {
	/*0000*/ ULONG FileOffset : 24; // 0x00ffffff;
	/*0000*/ ULONG Large : 01; // 0x01000000;
	/*0000*/ ULONG TrimBehind : 01; // 0x02000000;
	/*0000*/ ULONG Inherit : 01; // 0x04000000;
	/*0000*/ ULONG NoValidationNeeded : 01; // 0x08000000;
	/*0000*/ ULONG PrivateDemandZero : 01; // 0x10000000;
	/*0000*/ ULONG Spare : 03; // 0xe0000000;
	/*0004*/
};

struct _MMVAD_SHORT {
	/*0000*/ _MMVAD_SHORT * NextVad;
	/*0008*/ void * ExtraCreateInfo;
	/*0000*/ _RTL_BALANCED_NODE VadNode;
	/*0018*/ ULONG StartingVpn;
	/*001c*/ ULONG EndingVpn;
	/*0020*/ UCHAR StartingVpnHigh;
	/*0021*/ UCHAR EndingVpnHigh;
	/*0022*/ UCHAR CommitChargeHigh;
	/*0023*/ UCHAR SpareNT64VadUChar;
	/*0024*/ LONG ReferenceCount;
	/*0028*/ _EX_PUSH_LOCK PushLock;
	union {
		/*0030*/ ULONG LongFlags;
		/*0030*/ _MMVAD_FLAGS VadFlags;
		/*0034*/
	} u;
	union {
		/*0034*/ ULONG LongFlags1;
		/*0034*/ _MMVAD_FLAGS1 VadFlags1;
		/*0038*/
	} u1;
	/*0038*/ _MI_VAD_EVENT_BLOCK * EventList;
	/*0040*/
};

struct _MMWORKING_SET_EXPANSION_HEAD {
	/*0000*/ _LIST_ENTRY ListHead;
	/*0010*/
};

struct _MMWSL_INSTANCE {
	/*0000*/ _MMPTE * NextPteToTrim;
	/*0008*/ _MMPTE * NextPteToAge;
	/*0010*/ _MMPTE * NextPteToAccessClear;
	/*0018*/ ULONG LastAccessClearingRemainder;
	/*001c*/ ULONG LastAgingRemainder;
	/*0020*/ ULONGLONG LockedEntries;
	/*0028*/
};

struct _MM_DRIVER_VERIFIER_DATA {
	/*0000*/ ULONG Level;
	/*0004*/ ULONG volatile RaiseIrqls;
	/*0008*/ ULONG volatile AcquireSpinLocks;
	/*000c*/ ULONG volatile SynchronizeExecutions;
	/*0010*/ ULONG volatile AllocationsAttempted;
	/*0014*/ ULONG volatile AllocationsSucceeded;
	/*0018*/ ULONG volatile AllocationsSucceededSpecialPool;
	/*001c*/ ULONG AllocationsWithNoTag;
	/*0020*/ ULONG TrimRequests;
	/*0024*/ ULONG Trims;
	/*0028*/ ULONG AllocationsFailed;
	/*002c*/ ULONG volatile AllocationsFailedDeliberately;
	/*0030*/ ULONG volatile Loads;
	/*0034*/ ULONG volatile Unloads;
	/*0038*/ ULONG UnTrackedPool;
	/*003c*/ ULONG UserTrims;
	/*0040*/ ULONG volatile CurrentPagedPoolAllocations;
	/*0044*/ ULONG volatile CurrentNonPagedPoolAllocations;
	/*0048*/ ULONG PeakPagedPoolAllocations;
	/*004c*/ ULONG PeakNonPagedPoolAllocations;
	/*0050*/ ULONGLONG volatile PagedBytes;
	/*0058*/ ULONGLONG volatile NonPagedBytes;
	/*0060*/ ULONGLONG PeakPagedBytes;
	/*0068*/ ULONGLONG PeakNonPagedBytes;
	/*0070*/ ULONG volatile BurstAllocationsFailedDeliberately;
	/*0074*/ ULONG SessionTrims;
	/*0078*/ ULONG volatile OptionChanges;
	/*007c*/ ULONG volatile VerifyMode;
	/*0080*/ _UNICODE_STRING PreviousBucketName;
	/*0090*/ ULONG volatile ExecutePoolTypes;
	/*0094*/ ULONG volatile ExecutePageProtections;
	/*0098*/ ULONG volatile ExecutePageMappings;
	/*009c*/ ULONG volatile ExecuteWriteSections;
	/*00a0*/ ULONG volatile SectionAlignmentFailures;
	/*00a4*/ ULONG volatile UnsupportedRelocs;
	/*00a8*/ ULONG volatile IATInExecutableSection;
	/*00b0*/
};

struct _MM_PAGED_POOL_INFO {
	/*0000*/ _EX_PUSH_LOCK Lock;
	/*0008*/ _RTL_BITMAP_EX PagedPoolAllocationMap;
	/*0018*/ _MMPTE * FirstPteForPagedPool;
	/*0020*/ ULONGLONG MaximumSize;
	/*0028*/ ULONGLONG PagedPoolHint;
	/*0030*/ ULONGLONG AllocatedPagedPool;
	/*0038*/
};

struct _MM_PAGE_ACCESS_INFO {
	/*0000*/ _MM_PAGE_ACCESS_INFO_FLAGS Flags;
	/*0000*/ ULONGLONG FileOffset;
	/*0000*/ void * VirtualAddress;
	/*0000*/ void * PointerProtoPte;
	/*0008*/
};

union _MM_PAGE_ACCESS_INFO_FLAGS {
	struct {
		/*0000*/ ULONG FilePointerIndex : 09; // 0x000001ff;
		/*0000*/ ULONG HardFault : 01; // 0x00000200;
		/*0000*/ ULONG Image : 01; // 0x00000400;
		/*0000*/ ULONG Spare0 : 01; // 0x00000800;
		/*0004*/
	} File;
	struct {
		/*0000*/ ULONG FilePointerIndex : 09; // 0x000001ff;
		/*0000*/ ULONG HardFault : 01; // 0x00000200;
		/*0000*/ ULONG Spare1 : 02; // 0x00000c00;
		/*0004*/
	} Private;
	/*0004*/
};

struct _MM_PAGE_ACCESS_INFO_HEADER {
	/*0000*/ _SINGLE_LIST_ENTRY Link;
	/*0008*/ _MM_PAGE_ACCESS_TYPE Type;
	/*000c*/ ULONG EmptySequenceNumber;
	/*000c*/ ULONG CurrentFileIndex;
	/*0010*/ ULONGLONG CreateTime;
	/*0018*/ ULONGLONG EmptyTime;
	/*0018*/ _MM_PAGE_ACCESS_INFO * TempEntry;
	/*0020*/ _MM_PAGE_ACCESS_INFO * PageEntry;
	/*0028*/ ULONGLONG * FileEntry;
	/*0030*/ ULONGLONG * FirstFileEntry;
	/*0038*/ _EPROCESS * Process;
	/*0040*/ ULONG SessionId;
	/*0020*/ ULONGLONG * PageFrameEntry;
	/*0028*/ ULONGLONG * LastPageFrameEntry;
	/*0048*/
};

enum _MM_PAGE_ACCESS_TYPE {
	MmPteAccessType = 0x0,
	MmCcReadAheadType = 0x1,
	MmPfnRepurposeType = 0x2,
	MmMaximumPageAccessType = 0x3
};

enum _MM_POOL_PRIORITIES {
	MmHighPriority = 0x0,
	MmNormalPriority = 0x1,
	MmLowPriority = 0x2,
	MmMaximumPoolPriority = 0x3
};

enum _MM_POOL_TYPES {
	MmNonPagedPool = 0x0,
	MmPagedPool = 0x1,
	MmSessionPagedPool = 0x2,
	MmMaximumPoolType = 0x3
};

enum _MM_PREEMPTIVE_TRIMS {
	MmPreemptForNonPaged = 0x0,
	MmPreemptForPaged = 0x1,
	MmPreemptForNonPagedPriority = 0x2,
	MmPreemptForPagedPriority = 0x3,
	MmMaximumPreempt = 0x4
};

struct _MM_SESSION_SPACE {
	/*0000*/ LONG volatile ReferenceCount;
	union {
		/*0004*/ ULONG LongFlags;
		/*0004*/ _MM_SESSION_SPACE_FLAGS Flags;
		/*0008*/
	} u;
	/*0008*/ ULONG SessionId;
	/*000c*/ LONG volatile ProcessReferenceToSession;
	/*0010*/ _LIST_ENTRY ProcessList;
	/*0020*/ ULONGLONG SessionPageDirectoryIndex;
	/*0028*/ ULONGLONG volatile NonPagablePages;
	/*0030*/ ULONGLONG volatile CommittedPages;
	/*0038*/ void * PagedPoolStart;
	/*0040*/ void * PagedPoolEnd;
	/*0048*/ void * SessionObject;
	/*0050*/ void * SessionObjectHandle;
	/*0058*/ ULONG SessionPoolAllocationFailures[0x4];
	/*0068*/ _RTL_AVL_TREE ImageTree;
	/*0070*/ ULONG LocaleId;
	/*0074*/ ULONG AttachCount;
	/*0078*/ _KGATE AttachGate;
	/*0090*/ _LIST_ENTRY WsListEntry;
	/*00a0*/ _MM_PAGED_POOL_INFO PagedPoolInfo;
	/*0100*/ _GENERAL_LOOKASIDE Lookaside[0x15];
	/*0b80*/ _MMSESSION Session;
	/*0bc0*/ _MMSUPPORT_FULL Vm;
	/*0d00*/ _MMWSL_INSTANCE WorkingSetList;
	/*0d40*/ _MMSUPPORT_AGGREGATION AggregateSessionWs;
	/*0d80*/ _POOL_DESCRIPTOR PagedPool;
	/*1ec0*/ _MI_SESSION_DRIVER_UNLOAD DriverUnload;
	/*1ec8*/ _MMPTE PageDirectory;
	/*1ed0*/ _EX_PUSH_LOCK SessionVaLock;
	/*1ed8*/ _RTL_BITMAP_EX DynamicVaBitMap;
	/*1ee8*/ ULONGLONG DynamicVaHint;
	/*1ef0*/ _MI_SPECIAL_POOL SpecialPool;
	/*1f30*/ _EX_PUSH_LOCK SessionPteLock;
	/*1f38*/ LONG PoolBigEntriesInUse;
	/*1f3c*/ ULONG PagedPoolPdeCount;
	/*1f40*/ ULONG SpecialPoolPdeCount;
	/*1f44*/ ULONG DynamicSessionPdeCount;
	/*1f48*/ _MI_SYSTEM_PTE_TYPE SystemPteInfo;
	/*1fb0*/ void * PoolTrackTableExpansion;
	/*1fb8*/ ULONGLONG PoolTrackTableExpansionSize;
	/*1fc0*/ void * PoolTrackBigPages;
	/*1fc8*/ ULONGLONG PoolTrackBigPagesSize;
	/*1fd0*/ _IO_SESSION_STATE IoState;
	/*1fd4*/ ULONG IoStateSequence;
	/*1fd8*/ _KEVENT IoNotificationEvent;
	/*1ff0*/ _EJOB * ServerSilo;
	/*1ff8*/ ULONGLONG CreateTime;
	/*2000*/ UCHAR PoolTags[0x2000];
	/*4000*/
};

struct _MM_SESSION_SPACE_FLAGS {
	/*0000*/ ULONG Initialized : 01; // 0x00000001;
	/*0000*/ ULONG DeletePending : 01; // 0x00000002;
	/*0000*/ ULONG PoolInitialized : 01; // 0x00000004;
	/*0000*/ ULONG DynamicVaInitialized : 01; // 0x00000008;
	/*0000*/ ULONG WsInitialized : 01; // 0x00000010;
	/*0000*/ ULONG PoolDestroyed : 01; // 0x00000020;
	/*0000*/ ULONG ObjectInitialized : 01; // 0x00000040;
	/*0000*/ ULONG LeakedPoolDeliberately : 01; // 0x00000080;
	/*0000*/ ULONG Filler : 24; // 0xffffff00;
	/*0004*/
};

union _MM_STORE_KEY {
	/*0000*/ ULONGLONG KeyLow : 60; // 0x0fffffffffffffff;
	/*0000*/ ULONGLONG KeyHigh : 04; // 0xf000000000000000;
	/*0000*/ ULONGLONG EntireKey;
	/*0008*/
};

struct _MM_SYSTEM_PAGE_COUNTS {
	/*0000*/ ULONG SystemCodePage;
	/*0004*/ ULONG SystemDriverPage;
	/*0008*/ LONG TotalSystemCodePages;
	/*000c*/ LONG TotalSystemDriverPages;
	/*0010*/
};

enum _MODE {
	KernelMode = 0x0,
	UserMode = 0x1,
	MaximumMode = 0x2
};

struct _MODWRITER_FLAGS {
	/*0000*/ ULONG KeepForever : 01; // 0x00000001;
	/*0000*/ ULONG Networked : 01; // 0x00000002;
	/*0000*/ ULONG IoPriority : 03; // 0x0000001c;
	/*0000*/ ULONG ModifiedStoreWrite : 01; // 0x00000020;
	/*0004*/
};

struct _MSUBSECTION {
	/*0000*/ _SUBSECTION Core;
	/*0038*/ _RTL_BALANCED_NODE SubsectionNode;
	/*0050*/ _LIST_ENTRY DereferenceList;
	/*0060*/ ULONGLONG NumberOfMappedViews;
	/*0068*/ ULONG NumberOfPfnReferences;
	/*006c*/ ULONG LargeViews;
	/*0070*/
};

struct _NAMED_PIPE_CREATE_PARAMETERS {
	/*0000*/ ULONG NamedPipeType;
	/*0004*/ ULONG ReadMode;
	/*0008*/ ULONG CompletionMode;
	/*000c*/ ULONG MaximumInstances;
	/*0010*/ ULONG InboundQuota;
	/*0014*/ ULONG OutboundQuota;
	/*0018*/ _LARGE_INTEGER DefaultTimeout;
	/*0020*/ UCHAR TimeoutSpecified;
	/*0028*/
};

struct _NB10 {
	/*0000*/ ULONG Signature;
	/*0004*/ ULONG Offset;
	/*0008*/ ULONG TimeStamp;
	/*000c*/ ULONG Age;
	/*0010*/ CHAR PdbName[0x1];
	/*0014*/
};

struct _NONOPAQUE_OPLOCK {
	/*0000*/ _IRP * IrpExclusiveOplock;
	/*0008*/ _FILE_OBJECT * FileObject;
	/*0010*/ _EPROCESS * ExclusiveOplockOwner;
	/*0018*/ _ETHREAD * ExclusiveOplockOwnerThread;
	/*0020*/ UCHAR WaiterPriority;
	/*0028*/ _LIST_ENTRY IrpOplocksR;
	/*0038*/ _LIST_ENTRY IrpOplocksRH;
	/*0048*/ _LIST_ENTRY RHBreakQueue;
	/*0058*/ _LIST_ENTRY WaitingIrps;
	/*0068*/ _LIST_ENTRY DelayAckFileObjectQueue;
	/*0078*/ _LIST_ENTRY AtomicQueue;
	/*0088*/ _GUID * DeleterParentKey;
	/*0090*/ ULONG OplockState;
	/*0098*/ _FAST_MUTEX * FastMutex;
	/*00a0*/
};

struct _NON_PAGED_DEBUG_INFO {
	/*0000*/ USHORT Signature;
	/*0002*/ USHORT Flags;
	/*0004*/ ULONG Size;
	/*0008*/ USHORT Machine;
	/*000a*/ USHORT Characteristics;
	/*000c*/ ULONG TimeDateStamp;
	/*0010*/ ULONG CheckSum;
	/*0014*/ ULONG SizeOfImage;
	/*0018*/ ULONGLONG ImageBase;
	/*0020*/
};

struct _NPAGED_LOOKASIDE_LIST {
	/*0000*/ _GENERAL_LOOKASIDE L;
	/*0080*/
};

enum _NT_PRODUCT_TYPE {
	NtProductWinNt = 0x1,
	NtProductLanManNt = 0x2,
	NtProductServer = 0x3
};

struct _NT_TIB {
	/*0000*/ _EXCEPTION_REGISTRATION_RECORD * ExceptionList;
	/*0008*/ void * StackBase;
	/*0010*/ void * StackLimit;
	/*0018*/ void * SubSystemTib;
	/*0020*/ void * FiberData;
	/*0020*/ ULONG Version;
	/*0028*/ void * ArbitraryUserPointer;
	/*0030*/ _NT_TIB * Self;
	/*0038*/
};

struct _NT_TIB32 {
	/*0000*/ ULONG ExceptionList;
	/*0004*/ ULONG StackBase;
	/*0008*/ ULONG StackLimit;
	/*000c*/ ULONG SubSystemTib;
	/*0010*/ ULONG FiberData;
	/*0010*/ ULONG Version;
	/*0014*/ ULONG ArbitraryUserPointer;
	/*0018*/ ULONG Self;
	/*001c*/
};

struct _NT_TIB64 {
	/*0000*/ ULONGLONG ExceptionList;
	/*0008*/ ULONGLONG StackBase;
	/*0010*/ ULONGLONG StackLimit;
	/*0018*/ ULONGLONG SubSystemTib;
	/*0020*/ ULONGLONG FiberData;
	/*0020*/ ULONG Version;
	/*0028*/ ULONGLONG ArbitraryUserPointer;
	/*0030*/ ULONGLONG Self;
	/*0038*/
};

struct _OBJECT_ATTRIBUTES {
	/*0000*/ ULONG Length;
	/*0008*/ void * RootDirectory;
	/*0010*/ _UNICODE_STRING * ObjectName;
	/*0018*/ ULONG Attributes;
	/*0020*/ void * SecurityDescriptor;
	/*0028*/ void * SecurityQualityOfService;
	/*0030*/
};

struct _OBJECT_CREATE_INFORMATION {
	/*0000*/ ULONG Attributes;
	/*0008*/ void * RootDirectory;
	/*0010*/ CHAR ProbeMode;
	/*0014*/ ULONG PagedPoolCharge;
	/*0018*/ ULONG NonPagedPoolCharge;
	/*001c*/ ULONG SecurityDescriptorCharge;
	/*0020*/ void * SecurityDescriptor;
	/*0028*/ _SECURITY_QUALITY_OF_SERVICE * SecurityQos;
	/*0030*/ _SECURITY_QUALITY_OF_SERVICE SecurityQualityOfService;
	/*0040*/
};

struct _OBJECT_DIRECTORY {
	/*0000*/ _OBJECT_DIRECTORY_ENTRY * HashBuckets[0x25];
	/*0128*/ _EX_PUSH_LOCK Lock;
	/*0130*/ _DEVICE_MAP * DeviceMap;
	/*0138*/ _OBJECT_DIRECTORY * ShadowDirectory;
	/*0140*/ void * NamespaceEntry;
	/*0148*/ void * SessionObject;
	/*0150*/ ULONG Flags;
	/*0154*/ ULONG SessionId;
	/*0158*/
};

struct _OBJECT_DIRECTORY_ENTRY {
	/*0000*/ _OBJECT_DIRECTORY_ENTRY * ChainLink;
	/*0008*/ void * Object;
	/*0010*/ ULONG HashValue;
	/*0018*/
};

struct _OBJECT_DUMP_CONTROL {
	/*0000*/ void * Stream;
	/*0008*/ ULONG Detail;
	/*0010*/
};

struct _OBJECT_FOOTER {
	/*0000*/ _HANDLE_REVOCATION_INFO HandleRevocationInfo;
	/*0020*/ _OB_EXTENDED_USER_INFO ExtendedUserInfo;
	/*0030*/
};

struct _OBJECT_HANDLE_COUNT_DATABASE {
	/*0000*/ ULONG CountEntries;
	/*0008*/ _OBJECT_HANDLE_COUNT_ENTRY HandleCountEntries[0x1];
	/*0018*/
};

struct _OBJECT_HANDLE_COUNT_ENTRY {
	/*0000*/ _EPROCESS * Process;
	/*0008*/ ULONG HandleCount : 24; // 0x00ffffff;
	/*0008*/ ULONG LockCount : 08; // 0xff000000;
	/*0010*/
};

struct _OBJECT_HANDLE_INFORMATION {
	/*0000*/ ULONG HandleAttributes;
	/*0004*/ ULONG GrantedAccess;
	/*0008*/
};

struct _OBJECT_HEADER {
	/*0000*/ LONGLONG PointerCount;
	/*0008*/ LONGLONG HandleCount;
	/*0008*/ void * NextToFree;
	/*0010*/ _EX_PUSH_LOCK Lock;
	/*0018*/ UCHAR TypeIndex;
	/*0019*/ UCHAR TraceFlags;
	/*0019*/ UCHAR DbgRefTrace : 01; // 0x01;
	/*0019*/ UCHAR DbgTracePermanent : 01; // 0x02;
	/*001a*/ UCHAR InfoMask;
	/*001b*/ UCHAR Flags;
	/*001b*/ UCHAR NewObject : 01; // 0x01;
	/*001b*/ UCHAR KernelObject : 01; // 0x02;
	/*001b*/ UCHAR KernelOnlyAccess : 01; // 0x04;
	/*001b*/ UCHAR ExclusiveObject : 01; // 0x08;
	/*001b*/ UCHAR PermanentObject : 01; // 0x10;
	/*001b*/ UCHAR DefaultSecurityQuota : 01; // 0x20;
	/*001b*/ UCHAR SingleHandleEntry : 01; // 0x40;
	/*001b*/ UCHAR DeletedInline : 01; // 0x80;
	/*001c*/ ULONG Reserved;
	/*0020*/ _OBJECT_CREATE_INFORMATION * ObjectCreateInfo;
	/*0020*/ void * QuotaBlockCharged;
	/*0028*/ void * SecurityDescriptor;
	/*0030*/ _QUAD Body;
	/*0038*/
};

struct _OBJECT_HEADER_AUDIT_INFO {
	/*0000*/ void * SecurityDescriptor;
	/*0008*/ ULONGLONG Reserved;
	/*0010*/
};

struct _OBJECT_HEADER_CREATOR_INFO {
	/*0000*/ _LIST_ENTRY TypeList;
	/*0010*/ void * CreatorUniqueProcess;
	/*0018*/ USHORT CreatorBackTraceIndex;
	/*001a*/ USHORT Reserved1;
	/*001c*/ ULONG Reserved2;
	/*0020*/
};

struct _OBJECT_HEADER_EXTENDED_INFO {
	/*0000*/ _OBJECT_FOOTER * Footer;
	/*0008*/ ULONGLONG Reserved;
	/*0010*/
};

struct _OBJECT_HEADER_HANDLE_INFO {
	/*0000*/ _OBJECT_HANDLE_COUNT_DATABASE * HandleCountDataBase;
	/*0000*/ _OBJECT_HANDLE_COUNT_ENTRY SingleEntry;
	/*0010*/
};

struct _OBJECT_HEADER_NAME_INFO {
	/*0000*/ _OBJECT_DIRECTORY * Directory;
	/*0008*/ _UNICODE_STRING Name;
	/*0018*/ LONG ReferenceCount;
	/*001c*/ ULONG Reserved;
	/*0020*/
};

struct _OBJECT_HEADER_PADDING_INFO {
	/*0000*/ ULONG PaddingAmount;
	/*0004*/
};

struct _OBJECT_HEADER_PROCESS_INFO {
	/*0000*/ _EPROCESS * ExclusiveProcess;
	/*0008*/ ULONGLONG Reserved;
	/*0010*/
};

struct _OBJECT_HEADER_QUOTA_INFO {
	/*0000*/ ULONG PagedPoolCharge;
	/*0004*/ ULONG NonPagedPoolCharge;
	/*0008*/ ULONG SecurityDescriptorCharge;
	/*000c*/ ULONG Reserved1;
	/*0010*/ void * SecurityDescriptorQuotaBlock;
	/*0018*/ ULONGLONG Reserved2;
	/*0020*/
};

enum _OBJECT_INFORMATION_CLASS {
	ObjectBasicInformation = 0x0,
	ObjectNameInformation = 0x1,
	ObjectTypeInformation = 0x2,
	ObjectTypesInformation = 0x3,
	ObjectHandleFlagInformation = 0x4,
	ObjectSessionInformation = 0x5,
	ObjectSessionObjectInformation = 0x6,
	MaxObjectInfoClass = 0x7
};

struct _OBJECT_NAMESPACE_LOOKUPTABLE {
	/*0000*/ _LIST_ENTRY HashBuckets[0x25];
	/*0250*/ _EX_PUSH_LOCK Lock;
	/*0258*/ ULONG NumberOfPrivateSpaces;
	/*0260*/
};

struct _OBJECT_NAME_INFORMATION {
	/*0000*/ _UNICODE_STRING Name;
	/*0010*/
};

struct _OBJECT_REF_INFO {
	/*0000*/ _OBJECT_HEADER * ObjectHeader;
	/*0008*/ void * NextRef;
	/*0010*/ UCHAR ImageFileName[0x10];
	/*0020*/ USHORT NextPos;
	/*0022*/ USHORT MaxStacks;
	/*0024*/ _OBJECT_REF_STACK_INFO StackInfo[];
	/*0028*/
};

struct _OBJECT_REF_STACK_INFO {
	/*0000*/ ULONG Sequence;
	/*0004*/ USHORT Index;
	/*0006*/ USHORT NumTraces;
	/*0008*/ ULONG Tag;
	/*000c*/
};

struct _OBJECT_REF_TRACE {
	/*0000*/ void * StackTrace[0x10];
	/*0080*/
};

struct _OBJECT_SYMBOLIC_LINK {
	/*0000*/ _LARGE_INTEGER CreationTime;
	/*0008*/ _UNICODE_STRING LinkTarget;
	/*0008*/ LONG (* Callback)( _OBJECT_SYMBOLIC_LINK * , void * , _UNICODE_STRING * , void * * );
	/*0010*/ void * CallbackContext;
	/*0018*/ ULONG DosDeviceDriveIndex;
	/*001c*/ ULONG Flags;
	/*0020*/ ULONG AccessMask;
	/*0028*/
};

struct _OBJECT_TYPE {
	/*0000*/ _LIST_ENTRY TypeList;
	/*0010*/ _UNICODE_STRING Name;
	/*0020*/ void * DefaultObject;
	/*0028*/ UCHAR Index;
	/*002c*/ ULONG TotalNumberOfObjects;
	/*0030*/ ULONG TotalNumberOfHandles;
	/*0034*/ ULONG HighWaterNumberOfObjects;
	/*0038*/ ULONG HighWaterNumberOfHandles;
	/*0040*/ _OBJECT_TYPE_INITIALIZER TypeInfo;
	/*00b8*/ _EX_PUSH_LOCK TypeLock;
	/*00c0*/ ULONG Key;
	/*00c8*/ _LIST_ENTRY CallbackList;
	/*00d8*/
};

struct _OBJECT_TYPE_INITIALIZER {
	/*0000*/ USHORT Length;
	/*0002*/ USHORT ObjectTypeFlags;
	/*0002*/ UCHAR CaseInsensitive : 01; // 0x01;
	/*0002*/ UCHAR UnnamedObjectsOnly : 01; // 0x02;
	/*0002*/ UCHAR UseDefaultObject : 01; // 0x04;
	/*0002*/ UCHAR SecurityRequired : 01; // 0x08;
	/*0002*/ UCHAR MaintainHandleCount : 01; // 0x10;
	/*0002*/ UCHAR MaintainTypeList : 01; // 0x20;
	/*0002*/ UCHAR SupportsObjectCallbacks : 01; // 0x40;
	/*0002*/ UCHAR CacheAligned : 01; // 0x80;
	/*0003*/ UCHAR UseExtendedParameters : 01; // 0x01;
	/*0003*/ UCHAR Reserved : 07; // 0xfe;
	/*0004*/ ULONG ObjectTypeCode;
	/*0008*/ ULONG InvalidAttributes;
	/*000c*/ _GENERIC_MAPPING GenericMapping;
	/*001c*/ ULONG ValidAccessMask;
	/*0020*/ ULONG RetainAccess;
	/*0024*/ _POOL_TYPE PoolType;
	/*0028*/ ULONG DefaultPagedPoolCharge;
	/*002c*/ ULONG DefaultNonPagedPoolCharge;
	/*0030*/ void (* DumpProcedure)( void * , _OBJECT_DUMP_CONTROL * );
	/*0038*/ LONG (* OpenProcedure)( _OB_OPEN_REASON , CHAR , _EPROCESS * , void * , ULONG * , ULONG );
	/*0040*/ void (* CloseProcedure)( _EPROCESS * , void * , ULONGLONG , ULONGLONG );
	/*0048*/ void (* DeleteProcedure)( void * );
	/*0050*/ LONG (* ParseProcedure)( void * , void * , _ACCESS_STATE * , CHAR , ULONG , _UNICODE_STRING * , _UNICODE_STRING * , void * , _SECURITY_QUALITY_OF_SERVICE * , void * * );
	/*0050*/ LONG (* ParseProcedureEx)( void * , void * , _ACCESS_STATE * , CHAR , ULONG , _UNICODE_STRING * , _UNICODE_STRING * , void * , _SECURITY_QUALITY_OF_SERVICE * , _OB_EXTENDED_PARSE_PARAMETERS * , void * * );
	/*0058*/ LONG (* SecurityProcedure)( void * , _SECURITY_OPERATION_CODE , ULONG * , void * , ULONG * , void * * , _POOL_TYPE , _GENERIC_MAPPING * , CHAR );
	/*0060*/ LONG (* QueryNameProcedure)( void * , UCHAR , _OBJECT_NAME_INFORMATION * , ULONG , ULONG * , CHAR );
	/*0068*/ UCHAR (* OkayToCloseProcedure)( _EPROCESS * , void * , void * , CHAR );
	/*0070*/ ULONG WaitObjectFlagMask;
	/*0074*/ USHORT WaitObjectFlagOffset;
	/*0076*/ USHORT WaitObjectPointerOffset;
	/*0078*/
};

struct _OBP_LOOKUP_CONTEXT {
	/*0000*/ _OBJECT_DIRECTORY * Directory;
	/*0008*/ void * Object;
	/*0010*/ _OBJECT_DIRECTORY_ENTRY * * EntryLink;
	/*0018*/ ULONG HashValue;
	/*001c*/ USHORT HashIndex;
	/*001e*/ UCHAR DirectoryLocked;
	/*001f*/ UCHAR LockedExclusive;
	/*0020*/ ULONG LockStateSignature;
	/*0028*/
};

struct _OBP_SILODRIVERSTATE {
	/*0000*/ _DEVICE_MAP * SystemDeviceMap;
	/*0008*/ _OBP_SYSTEM_DOS_DEVICE_STATE SystemDosDeviceState;
	/*0078*/ _EX_PUSH_LOCK DeviceMapLock;
	/*0080*/ _OBJECT_NAMESPACE_LOOKUPTABLE PrivateNamespaceLookupTable;
	/*02e0*/
};

struct _OBP_SYSTEM_DOS_DEVICE_STATE {
	/*0000*/ ULONG GlobalDeviceMap;
	/*0004*/ ULONG LocalDeviceCount[0x1a];
	/*006c*/
};

struct _OB_DUPLICATE_OBJECT_STATE {
	/*0000*/ _EPROCESS * SourceProcess;
	/*0008*/ void * SourceHandle;
	/*0010*/ void * Object;
	/*0018*/ ULONG TargetAccess;
	/*001c*/ _HANDLE_TABLE_ENTRY_INFO ObjectInfo;
	/*0024*/ ULONG HandleAttributes;
	/*0028*/
};

struct _OB_EXTENDED_PARSE_PARAMETERS {
	/*0000*/ USHORT Length;
	/*0004*/ ULONG RestrictedAccessMask;
	/*0008*/ _EJOB * Silo;
	/*0010*/
};

struct _OB_EXTENDED_USER_INFO {
	/*0000*/ void * Context1;
	/*0008*/ void * Context2;
	/*0010*/
};

struct _OB_HANDLE_REVOCATION_BLOCK {
	/*0000*/ _LIST_ENTRY RevocationInfos;
	/*0010*/ _EX_PUSH_LOCK Lock;
	/*0018*/ _EX_RUNDOWN_REF Rundown;
	/*0020*/
};

enum _OB_OPEN_REASON {
	ObCreateHandle = 0x0,
	ObOpenHandle = 0x1,
	ObDuplicateHandle = 0x2,
	ObInheritHandle = 0x3,
	ObMaxOpenReason = 0x4
};

struct _OPEN_PACKET {
	/*0000*/ SHORT Type;
	/*0002*/ SHORT Size;
	/*0008*/ _FILE_OBJECT * FileObject;
	/*0010*/ LONG FinalStatus;
	/*0018*/ ULONGLONG Information;
	/*0020*/ ULONG ParseCheck;
	/*0028*/ _FILE_OBJECT * RelatedFileObject;
	/*0028*/ _DEVICE_OBJECT * ReferencedDeviceObject;
	/*0030*/ _OBJECT_ATTRIBUTES * OriginalAttributes;
	/*0038*/ _LARGE_INTEGER AllocationSize;
	/*0040*/ ULONG CreateOptions;
	/*0044*/ USHORT FileAttributes;
	/*0046*/ USHORT ShareAccess;
	/*0048*/ void * EaBuffer;
	/*0050*/ ULONG EaLength;
	/*0054*/ ULONG Options;
	/*0058*/ ULONG Disposition;
	/*0060*/ _FILE_BASIC_INFORMATION * BasicInformation;
	/*0068*/ _FILE_NETWORK_OPEN_INFORMATION * NetworkInformation;
	/*0070*/ void * FileInformation;
	/*0078*/ _CREATE_FILE_TYPE CreateFileType;
	/*0080*/ void * MailslotOrPipeParameters;
	/*0088*/ UCHAR Override;
	/*0089*/ UCHAR QueryOnly;
	/*008a*/ UCHAR DeleteOnly;
	/*008b*/ UCHAR FullAttributes;
	/*0090*/ _DUMMY_FILE_OBJECT * LocalFileObject;
	/*0098*/ ULONG InternalFlags;
	/*009c*/ CHAR AccessMode;
	/*00a0*/ _IO_DRIVER_CREATE_CONTEXT DriverCreateContext;
	/*00c8*/ _FILE_INFORMATION_CLASS FileInformationClass;
	/*00cc*/ ULONG FileInformationLength;
	/*00d0*/ UCHAR FilterQuery;
	/*00d8*/
};

struct _OWNER_ENTRY {
	/*0000*/ ULONGLONG OwnerThread;
	/*0008*/ ULONG IoPriorityBoosted : 01; // 0x00000001;
	/*0008*/ ULONG OwnerReferenced : 01; // 0x00000002;
	/*0008*/ ULONG IoQoSPriorityBoosted : 01; // 0x00000004;
	/*0008*/ ULONG OwnerCount : 29; // 0xfffffff8;
	/*0008*/ ULONG TableSize;
	/*0010*/
};

struct _PAGED_LOOKASIDE_LIST {
	/*0000*/ _GENERAL_LOOKASIDE L;
	/*0080*/
};

struct _PAGEFAULT_HISTORY;

struct _PALPC_PORT_REFERENCE_WAIT_BLOCK {
	/*0000*/ _KEVENT DesiredReferenceNoEvent;
	/*0018*/ LONG DesiredReferenceNo;
	/*0020*/
};

struct _PCW_BUFFER;

union _PCW_CALLBACK_INFORMATION {
	/*0000*/ _PCW_COUNTER_INFORMATION AddCounter;
	/*0000*/ _PCW_COUNTER_INFORMATION RemoveCounter;
	/*0000*/ _PCW_MASK_INFORMATION EnumerateInstances;
	/*0000*/ _PCW_MASK_INFORMATION CollectData;
	/*0028*/
};

enum _PCW_CALLBACK_TYPE {
	PcwCallbackAddCounter = 0x0,
	PcwCallbackRemoveCounter = 0x1,
	PcwCallbackEnumerateInstances = 0x2,
	PcwCallbackCollectData = 0x3
};

struct _PCW_COUNTER_DESCRIPTOR {
	/*0000*/ USHORT Id;
	/*0002*/ USHORT StructIndex;
	/*0004*/ USHORT Offset;
	/*0006*/ USHORT Size;
	/*0008*/
};

struct _PCW_COUNTER_INFORMATION {
	/*0000*/ ULONGLONG CounterMask;
	/*0008*/ _UNICODE_STRING const * InstanceMask;
	/*0010*/
};

struct _PCW_DATA {
	/*0000*/ void const * Data;
	/*0008*/ ULONG Size;
	/*0010*/
};

struct _PCW_INSTANCE;

struct _PCW_MASK_INFORMATION {
	/*0000*/ ULONGLONG CounterMask;
	/*0008*/ _UNICODE_STRING const * InstanceMask;
	/*0010*/ ULONG InstanceId;
	/*0014*/ UCHAR CollectMultiple;
	/*0018*/ _PCW_BUFFER * Buffer;
	/*0020*/ _KEVENT * CancelEvent;
	/*0028*/
};

struct _PCW_PROCESSOR_INFO {
	/*0000*/ ULONGLONG IdleTime;
	/*0008*/ ULONGLONG AvailableTime;
	/*0010*/ ULONGLONG UserTime;
	/*0018*/ ULONGLONG KernelTime;
	/*0020*/ ULONG Interrupts;
	/*0028*/ ULONGLONG DpcTime;
	/*0030*/ ULONGLONG InterruptTime;
	/*0038*/ ULONG ClockInterrupts;
	/*003c*/ ULONG DpcCount;
	/*0040*/ ULONG DpcRate;
	/*0048*/ ULONGLONG C1Time;
	/*0050*/ ULONGLONG C2Time;
	/*0058*/ ULONGLONG C3Time;
	/*0060*/ ULONGLONG C1Transitions;
	/*0068*/ ULONGLONG C2Transitions;
	/*0070*/ ULONGLONG C3Transitions;
	/*0078*/ ULONGLONG StallTime;
	/*0080*/ ULONG ParkingStatus;
	/*0084*/ ULONG CurrentFrequency;
	/*0088*/ ULONG PercentMaxFrequency;
	/*008c*/ ULONG StateFlags;
	/*0090*/ ULONG NominalThroughput;
	/*0094*/ ULONG ActiveThroughput;
	/*0098*/ ULONGLONG ScaledThroughput;
	/*00a0*/ ULONGLONG ScaledKernelThroughput;
	/*00a8*/ ULONGLONG AverageIdleTime;
	/*00b0*/ ULONGLONG IdleBreakEvents;
	/*00b8*/ ULONG PerformanceLimit;
	/*00bc*/ ULONG PerformanceLimitFlags;
	/*00c0*/
};

struct _PCW_REGISTRATION;

struct _PCW_REGISTRATION_INFORMATION {
	/*0000*/ ULONG Version;
	/*0008*/ _UNICODE_STRING const * Name;
	/*0010*/ ULONG CounterCount;
	/*0018*/ _PCW_COUNTER_DESCRIPTOR * Counters;
	/*0020*/ LONG (* Callback)( _PCW_CALLBACK_TYPE , _PCW_CALLBACK_INFORMATION * , void * );
	/*0028*/ void * CallbackContext;
	/*0030*/
};

struct _PEB {
	/*0000*/ UCHAR InheritedAddressSpace;
	/*0001*/ UCHAR ReadImageFileExecOptions;
	/*0002*/ UCHAR BeingDebugged;
	/*0003*/ UCHAR BitField;
	/*0003*/ UCHAR ImageUsesLargePages : 01; // 0x01;
	/*0003*/ UCHAR IsProtectedProcess : 01; // 0x02;
	/*0003*/ UCHAR IsImageDynamicallyRelocated : 01; // 0x04;
	/*0003*/ UCHAR SkipPatchingUser32Forwarders : 01; // 0x08;
	/*0003*/ UCHAR IsPackagedProcess : 01; // 0x10;
	/*0003*/ UCHAR IsAppContainer : 01; // 0x20;
	/*0003*/ UCHAR IsProtectedProcessLight : 01; // 0x40;
	/*0003*/ UCHAR IsLongPathAwareProcess : 01; // 0x80;
	/*0004*/ UCHAR Padding0[0x4];
	/*0008*/ void * Mutant;
	/*0010*/ void * ImageBaseAddress;
	/*0018*/ _PEB_LDR_DATA * Ldr;
	/*0020*/ _RTL_USER_PROCESS_PARAMETERS * ProcessParameters;
	/*0028*/ void * SubSystemData;
	/*0030*/ void * ProcessHeap;
	/*0038*/ _RTL_CRITICAL_SECTION * FastPebLock;
	/*0040*/ _SLIST_HEADER * volatile AtlThunkSListPtr;
	/*0048*/ void * IFEOKey;
	/*0050*/ ULONG CrossProcessFlags;
	/*0050*/ ULONG ProcessInJob : 01; // 0x00000001;
	/*0050*/ ULONG ProcessInitializing : 01; // 0x00000002;
	/*0050*/ ULONG ProcessUsingVEH : 01; // 0x00000004;
	/*0050*/ ULONG ProcessUsingVCH : 01; // 0x00000008;
	/*0050*/ ULONG ProcessUsingFTH : 01; // 0x00000010;
	/*0050*/ ULONG ProcessPreviouslyThrottled : 01; // 0x00000020;
	/*0050*/ ULONG ProcessCurrentlyThrottled : 01; // 0x00000040;
	/*0050*/ ULONG ReservedBits0 : 25; // 0xffffff80;
	/*0054*/ UCHAR Padding1[0x4];
	/*0058*/ void * KernelCallbackTable;
	/*0058*/ void * UserSharedInfoPtr;
	/*0060*/ ULONG SystemReserved;
	/*0064*/ ULONG AtlThunkSListPtr32;
	/*0068*/ void * ApiSetMap;
	/*0070*/ ULONG TlsExpansionCounter;
	/*0074*/ UCHAR Padding2[0x4];
	/*0078*/ void * TlsBitmap;
	/*0080*/ ULONG TlsBitmapBits[0x2];
	/*0088*/ void * ReadOnlySharedMemoryBase;
	/*0090*/ void * SharedData;
	/*0098*/ void * * ReadOnlyStaticServerData;
	/*00a0*/ void * AnsiCodePageData;
	/*00a8*/ void * OemCodePageData;
	/*00b0*/ void * UnicodeCaseTableData;
	/*00b8*/ ULONG NumberOfProcessors;
	/*00bc*/ ULONG NtGlobalFlag;
	/*00c0*/ _LARGE_INTEGER CriticalSectionTimeout;
	/*00c8*/ ULONGLONG HeapSegmentReserve;
	/*00d0*/ ULONGLONG HeapSegmentCommit;
	/*00d8*/ ULONGLONG HeapDeCommitTotalFreeThreshold;
	/*00e0*/ ULONGLONG HeapDeCommitFreeBlockThreshold;
	/*00e8*/ ULONG NumberOfHeaps;
	/*00ec*/ ULONG MaximumNumberOfHeaps;
	/*00f0*/ void * * ProcessHeaps;
	/*00f8*/ void * GdiSharedHandleTable;
	/*0100*/ void * ProcessStarterHelper;
	/*0108*/ ULONG GdiDCAttributeList;
	/*010c*/ UCHAR Padding3[0x4];
	/*0110*/ _RTL_CRITICAL_SECTION * LoaderLock;
	/*0118*/ ULONG OSMajorVersion;
	/*011c*/ ULONG OSMinorVersion;
	/*0120*/ USHORT OSBuildNumber;
	/*0122*/ USHORT OSCSDVersion;
	/*0124*/ ULONG OSPlatformId;
	/*0128*/ ULONG ImageSubsystem;
	/*012c*/ ULONG ImageSubsystemMajorVersion;
	/*0130*/ ULONG ImageSubsystemMinorVersion;
	/*0134*/ UCHAR Padding4[0x4];
	/*0138*/ ULONGLONG ActiveProcessAffinityMask;
	/*0140*/ ULONG GdiHandleBuffer[0x3c];
	/*0230*/ void (* PostProcessInitRoutine)();
	/*0238*/ void * TlsExpansionBitmap;
	/*0240*/ ULONG TlsExpansionBitmapBits[0x20];
	/*02c0*/ ULONG SessionId;
	/*02c4*/ UCHAR Padding5[0x4];
	/*02c8*/ _ULARGE_INTEGER AppCompatFlags;
	/*02d0*/ _ULARGE_INTEGER AppCompatFlagsUser;
	/*02d8*/ void * pShimData;
	/*02e0*/ void * AppCompatInfo;
	/*02e8*/ _UNICODE_STRING CSDVersion;
	/*02f8*/ _ACTIVATION_CONTEXT_DATA const * ActivationContextData;
	/*0300*/ _ASSEMBLY_STORAGE_MAP * ProcessAssemblyStorageMap;
	/*0308*/ _ACTIVATION_CONTEXT_DATA const * SystemDefaultActivationContextData;
	/*0310*/ _ASSEMBLY_STORAGE_MAP * SystemAssemblyStorageMap;
	/*0318*/ ULONGLONG MinimumStackCommit;
	/*0320*/ _FLS_CALLBACK_INFO * FlsCallback;
	/*0328*/ _LIST_ENTRY FlsListHead;
	/*0338*/ void * FlsBitmap;
	/*0340*/ ULONG FlsBitmapBits[0x4];
	/*0350*/ ULONG FlsHighIndex;
	/*0358*/ void * WerRegistrationData;
	/*0360*/ void * WerShipAssertPtr;
	/*0368*/ void * pUnused;
	/*0370*/ void * pImageHeaderHash;
	/*0378*/ ULONG TracingFlags;
	/*0378*/ ULONG HeapTracingEnabled : 01; // 0x00000001;
	/*0378*/ ULONG CritSecTracingEnabled : 01; // 0x00000002;
	/*0378*/ ULONG LibLoaderTracingEnabled : 01; // 0x00000004;
	/*0378*/ ULONG SpareTracingBits : 29; // 0xfffffff8;
	/*037c*/ UCHAR Padding6[0x4];
	/*0380*/ ULONGLONG CsrServerReadOnlySharedMemoryBase;
	/*0388*/ ULONGLONG TppWorkerpListLock;
	/*0390*/ _LIST_ENTRY TppWorkerpList;
	/*03a0*/ void * WaitOnAddressHashTable[0x80];
	/*07a0*/ void * TelemetryCoverageHeader;
	/*07a8*/ ULONG CloudFileFlags;
	/*07b0*/
};

struct _PEB32 {
	/*0000*/ UCHAR InheritedAddressSpace;
	/*0001*/ UCHAR ReadImageFileExecOptions;
	/*0002*/ UCHAR BeingDebugged;
	/*0003*/ UCHAR BitField;
	/*0003*/ UCHAR ImageUsesLargePages : 01; // 0x01;
	/*0003*/ UCHAR IsProtectedProcess : 01; // 0x02;
	/*0003*/ UCHAR IsImageDynamicallyRelocated : 01; // 0x04;
	/*0003*/ UCHAR SkipPatchingUser32Forwarders : 01; // 0x08;
	/*0003*/ UCHAR IsPackagedProcess : 01; // 0x10;
	/*0003*/ UCHAR IsAppContainer : 01; // 0x20;
	/*0003*/ UCHAR IsProtectedProcessLight : 01; // 0x40;
	/*0003*/ UCHAR IsLongPathAwareProcess : 01; // 0x80;
	/*0004*/ ULONG Mutant;
	/*0008*/ ULONG ImageBaseAddress;
	/*000c*/ ULONG Ldr;
	/*0010*/ ULONG ProcessParameters;
	/*0014*/ ULONG SubSystemData;
	/*0018*/ ULONG ProcessHeap;
	/*001c*/ ULONG FastPebLock;
	/*0020*/ ULONG AtlThunkSListPtr;
	/*0024*/ ULONG IFEOKey;
	/*0028*/ ULONG CrossProcessFlags;
	/*0028*/ ULONG ProcessInJob : 01; // 0x00000001;
	/*0028*/ ULONG ProcessInitializing : 01; // 0x00000002;
	/*0028*/ ULONG ProcessUsingVEH : 01; // 0x00000004;
	/*0028*/ ULONG ProcessUsingVCH : 01; // 0x00000008;
	/*0028*/ ULONG ProcessUsingFTH : 01; // 0x00000010;
	/*0028*/ ULONG ProcessPreviouslyThrottled : 01; // 0x00000020;
	/*0028*/ ULONG ProcessCurrentlyThrottled : 01; // 0x00000040;
	/*0028*/ ULONG ReservedBits0 : 25; // 0xffffff80;
	/*002c*/ ULONG KernelCallbackTable;
	/*002c*/ ULONG UserSharedInfoPtr;
	/*0030*/ ULONG SystemReserved;
	/*0034*/ ULONG AtlThunkSListPtr32;
	/*0038*/ ULONG ApiSetMap;
	/*003c*/ ULONG TlsExpansionCounter;
	/*0040*/ ULONG TlsBitmap;
	/*0044*/ ULONG TlsBitmapBits[0x2];
	/*004c*/ ULONG ReadOnlySharedMemoryBase;
	/*0050*/ ULONG SharedData;
	/*0054*/ ULONG ReadOnlyStaticServerData;
	/*0058*/ ULONG AnsiCodePageData;
	/*005c*/ ULONG OemCodePageData;
	/*0060*/ ULONG UnicodeCaseTableData;
	/*0064*/ ULONG NumberOfProcessors;
	/*0068*/ ULONG NtGlobalFlag;
	/*0070*/ _LARGE_INTEGER CriticalSectionTimeout;
	/*0078*/ ULONG HeapSegmentReserve;
	/*007c*/ ULONG HeapSegmentCommit;
	/*0080*/ ULONG HeapDeCommitTotalFreeThreshold;
	/*0084*/ ULONG HeapDeCommitFreeBlockThreshold;
	/*0088*/ ULONG NumberOfHeaps;
	/*008c*/ ULONG MaximumNumberOfHeaps;
	/*0090*/ ULONG ProcessHeaps;
	/*0094*/ ULONG GdiSharedHandleTable;
	/*0098*/ ULONG ProcessStarterHelper;
	/*009c*/ ULONG GdiDCAttributeList;
	/*00a0*/ ULONG LoaderLock;
	/*00a4*/ ULONG OSMajorVersion;
	/*00a8*/ ULONG OSMinorVersion;
	/*00ac*/ USHORT OSBuildNumber;
	/*00ae*/ USHORT OSCSDVersion;
	/*00b0*/ ULONG OSPlatformId;
	/*00b4*/ ULONG ImageSubsystem;
	/*00b8*/ ULONG ImageSubsystemMajorVersion;
	/*00bc*/ ULONG ImageSubsystemMinorVersion;
	/*00c0*/ ULONG ActiveProcessAffinityMask;
	/*00c4*/ ULONG GdiHandleBuffer[0x22];
	/*014c*/ ULONG PostProcessInitRoutine;
	/*0150*/ ULONG TlsExpansionBitmap;
	/*0154*/ ULONG TlsExpansionBitmapBits[0x20];
	/*01d4*/ ULONG SessionId;
	/*01d8*/ _ULARGE_INTEGER AppCompatFlags;
	/*01e0*/ _ULARGE_INTEGER AppCompatFlagsUser;
	/*01e8*/ ULONG pShimData;
	/*01ec*/ ULONG AppCompatInfo;
	/*01f0*/ _STRING32 CSDVersion;
	/*01f8*/ ULONG ActivationContextData;
	/*01fc*/ ULONG ProcessAssemblyStorageMap;
	/*0200*/ ULONG SystemDefaultActivationContextData;
	/*0204*/ ULONG SystemAssemblyStorageMap;
	/*0208*/ ULONG MinimumStackCommit;
	/*020c*/ ULONG FlsCallback;
	/*0210*/ LIST_ENTRY32 FlsListHead;
	/*0218*/ ULONG FlsBitmap;
	/*021c*/ ULONG FlsBitmapBits[0x4];
	/*022c*/ ULONG FlsHighIndex;
	/*0230*/ ULONG WerRegistrationData;
	/*0234*/ ULONG WerShipAssertPtr;
	/*0238*/ ULONG pUnused;
	/*023c*/ ULONG pImageHeaderHash;
	/*0240*/ ULONG TracingFlags;
	/*0240*/ ULONG HeapTracingEnabled : 01; // 0x00000001;
	/*0240*/ ULONG CritSecTracingEnabled : 01; // 0x00000002;
	/*0240*/ ULONG LibLoaderTracingEnabled : 01; // 0x00000004;
	/*0240*/ ULONG SpareTracingBits : 29; // 0xfffffff8;
	/*0248*/ ULONGLONG CsrServerReadOnlySharedMemoryBase;
	/*0250*/ ULONG TppWorkerpListLock;
	/*0254*/ LIST_ENTRY32 TppWorkerpList;
	/*025c*/ ULONG WaitOnAddressHashTable[0x80];
	/*045c*/ ULONG TelemetryCoverageHeader;
	/*0460*/ ULONG CloudFileFlags;
	/*0468*/
};

struct _PEB64 {
	/*0000*/ UCHAR InheritedAddressSpace;
	/*0001*/ UCHAR ReadImageFileExecOptions;
	/*0002*/ UCHAR BeingDebugged;
	/*0003*/ UCHAR BitField;
	/*0003*/ UCHAR ImageUsesLargePages : 01; // 0x01;
	/*0003*/ UCHAR IsProtectedProcess : 01; // 0x02;
	/*0003*/ UCHAR IsImageDynamicallyRelocated : 01; // 0x04;
	/*0003*/ UCHAR SkipPatchingUser32Forwarders : 01; // 0x08;
	/*0003*/ UCHAR IsPackagedProcess : 01; // 0x10;
	/*0003*/ UCHAR IsAppContainer : 01; // 0x20;
	/*0003*/ UCHAR IsProtectedProcessLight : 01; // 0x40;
	/*0003*/ UCHAR IsLongPathAwareProcess : 01; // 0x80;
	/*0004*/ UCHAR Padding0[0x4];
	/*0008*/ ULONGLONG Mutant;
	/*0010*/ ULONGLONG ImageBaseAddress;
	/*0018*/ ULONGLONG Ldr;
	/*0020*/ ULONGLONG ProcessParameters;
	/*0028*/ ULONGLONG SubSystemData;
	/*0030*/ ULONGLONG ProcessHeap;
	/*0038*/ ULONGLONG FastPebLock;
	/*0040*/ ULONGLONG AtlThunkSListPtr;
	/*0048*/ ULONGLONG IFEOKey;
	/*0050*/ ULONG CrossProcessFlags;
	/*0050*/ ULONG ProcessInJob : 01; // 0x00000001;
	/*0050*/ ULONG ProcessInitializing : 01; // 0x00000002;
	/*0050*/ ULONG ProcessUsingVEH : 01; // 0x00000004;
	/*0050*/ ULONG ProcessUsingVCH : 01; // 0x00000008;
	/*0050*/ ULONG ProcessUsingFTH : 01; // 0x00000010;
	/*0050*/ ULONG ProcessPreviouslyThrottled : 01; // 0x00000020;
	/*0050*/ ULONG ProcessCurrentlyThrottled : 01; // 0x00000040;
	/*0050*/ ULONG ReservedBits0 : 25; // 0xffffff80;
	/*0054*/ UCHAR Padding1[0x4];
	/*0058*/ ULONGLONG KernelCallbackTable;
	/*0058*/ ULONGLONG UserSharedInfoPtr;
	/*0060*/ ULONG SystemReserved;
	/*0064*/ ULONG AtlThunkSListPtr32;
	/*0068*/ ULONGLONG ApiSetMap;
	/*0070*/ ULONG TlsExpansionCounter;
	/*0074*/ UCHAR Padding2[0x4];
	/*0078*/ ULONGLONG TlsBitmap;
	/*0080*/ ULONG TlsBitmapBits[0x2];
	/*0088*/ ULONGLONG ReadOnlySharedMemoryBase;
	/*0090*/ ULONGLONG SharedData;
	/*0098*/ ULONGLONG ReadOnlyStaticServerData;
	/*00a0*/ ULONGLONG AnsiCodePageData;
	/*00a8*/ ULONGLONG OemCodePageData;
	/*00b0*/ ULONGLONG UnicodeCaseTableData;
	/*00b8*/ ULONG NumberOfProcessors;
	/*00bc*/ ULONG NtGlobalFlag;
	/*00c0*/ _LARGE_INTEGER CriticalSectionTimeout;
	/*00c8*/ ULONGLONG HeapSegmentReserve;
	/*00d0*/ ULONGLONG HeapSegmentCommit;
	/*00d8*/ ULONGLONG HeapDeCommitTotalFreeThreshold;
	/*00e0*/ ULONGLONG HeapDeCommitFreeBlockThreshold;
	/*00e8*/ ULONG NumberOfHeaps;
	/*00ec*/ ULONG MaximumNumberOfHeaps;
	/*00f0*/ ULONGLONG ProcessHeaps;
	/*00f8*/ ULONGLONG GdiSharedHandleTable;
	/*0100*/ ULONGLONG ProcessStarterHelper;
	/*0108*/ ULONG GdiDCAttributeList;
	/*010c*/ UCHAR Padding3[0x4];
	/*0110*/ ULONGLONG LoaderLock;
	/*0118*/ ULONG OSMajorVersion;
	/*011c*/ ULONG OSMinorVersion;
	/*0120*/ USHORT OSBuildNumber;
	/*0122*/ USHORT OSCSDVersion;
	/*0124*/ ULONG OSPlatformId;
	/*0128*/ ULONG ImageSubsystem;
	/*012c*/ ULONG ImageSubsystemMajorVersion;
	/*0130*/ ULONG ImageSubsystemMinorVersion;
	/*0134*/ UCHAR Padding4[0x4];
	/*0138*/ ULONGLONG ActiveProcessAffinityMask;
	/*0140*/ ULONG GdiHandleBuffer[0x3c];
	/*0230*/ ULONGLONG PostProcessInitRoutine;
	/*0238*/ ULONGLONG TlsExpansionBitmap;
	/*0240*/ ULONG TlsExpansionBitmapBits[0x20];
	/*02c0*/ ULONG SessionId;
	/*02c4*/ UCHAR Padding5[0x4];
	/*02c8*/ _ULARGE_INTEGER AppCompatFlags;
	/*02d0*/ _ULARGE_INTEGER AppCompatFlagsUser;
	/*02d8*/ ULONGLONG pShimData;
	/*02e0*/ ULONGLONG AppCompatInfo;
	/*02e8*/ _STRING64 CSDVersion;
	/*02f8*/ ULONGLONG ActivationContextData;
	/*0300*/ ULONGLONG ProcessAssemblyStorageMap;
	/*0308*/ ULONGLONG SystemDefaultActivationContextData;
	/*0310*/ ULONGLONG SystemAssemblyStorageMap;
	/*0318*/ ULONGLONG MinimumStackCommit;
	/*0320*/ ULONGLONG FlsCallback;
	/*0328*/ LIST_ENTRY64 FlsListHead;
	/*0338*/ ULONGLONG FlsBitmap;
	/*0340*/ ULONG FlsBitmapBits[0x4];
	/*0350*/ ULONG FlsHighIndex;
	/*0358*/ ULONGLONG WerRegistrationData;
	/*0360*/ ULONGLONG WerShipAssertPtr;
	/*0368*/ ULONGLONG pUnused;
	/*0370*/ ULONGLONG pImageHeaderHash;
	/*0378*/ ULONG TracingFlags;
	/*0378*/ ULONG HeapTracingEnabled : 01; // 0x00000001;
	/*0378*/ ULONG CritSecTracingEnabled : 01; // 0x00000002;
	/*0378*/ ULONG LibLoaderTracingEnabled : 01; // 0x00000004;
	/*0378*/ ULONG SpareTracingBits : 29; // 0xfffffff8;
	/*037c*/ UCHAR Padding6[0x4];
	/*0380*/ ULONGLONG CsrServerReadOnlySharedMemoryBase;
	/*0388*/ ULONGLONG TppWorkerpListLock;
	/*0390*/ LIST_ENTRY64 TppWorkerpList;
	/*03a0*/ ULONGLONG WaitOnAddressHashTable[0x80];
	/*07a0*/ ULONGLONG TelemetryCoverageHeader;
	/*07a8*/ ULONG CloudFileFlags;
	/*07b0*/
};

struct _PEBS_DS_SAVE_AREA {
	/*0000*/ ULONGLONG BtsBufferBase;
	/*0008*/ ULONGLONG BtsIndex;
	/*0010*/ ULONGLONG BtsAbsoluteMaximum;
	/*0018*/ ULONGLONG BtsInterruptThreshold;
	/*0020*/ ULONGLONG PebsBufferBase;
	/*0028*/ ULONGLONG PebsIndex;
	/*0030*/ ULONGLONG PebsAbsoluteMaximum;
	/*0038*/ ULONGLONG PebsInterruptThreshold;
	/*0040*/ ULONGLONG PebsCounterReset0;
	/*0048*/ ULONGLONG PebsCounterReset1;
	/*0050*/ ULONGLONG PebsCounterReset2;
	/*0058*/ ULONGLONG PebsCounterReset3;
	/*0060*/
};

struct _PEB_LDR_DATA {
	/*0000*/ ULONG Length;
	/*0004*/ UCHAR Initialized;
	/*0008*/ void * SsHandle;
	/*0010*/ _LIST_ENTRY InLoadOrderModuleList;
	/*0020*/ _LIST_ENTRY InMemoryOrderModuleList;
	/*0030*/ _LIST_ENTRY InInitializationOrderModuleList;
	/*0040*/ void * EntryInProgress;
	/*0048*/ UCHAR ShutdownInProgress;
	/*0050*/ void * ShutdownThreadId;
	/*0058*/
};

struct _PENDING_RELATIONS_LIST_ENTRY {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ _WORK_QUEUE_ITEM WorkItem;
	/*0030*/ _PNP_DEVICE_EVENT_ENTRY * DeviceEvent;
	/*0038*/ _DEVICE_OBJECT * DeviceObject;
	/*0040*/ _RELATION_LIST * RelationsList;
	/*0048*/ _IRP * EjectIrp;
	/*0050*/ IRPLOCK Lock;
	/*0054*/ ULONG Problem;
	/*0058*/ UCHAR ProfileChangingEject;
	/*0059*/ UCHAR DisplaySafeRemovalDialog;
	/*005c*/ _SYSTEM_POWER_STATE LightestSleepState;
	/*0060*/ DOCK_INTERFACE * DockInterface;
	/*0068*/ UCHAR DequeuePending;
	/*006c*/ _PNP_DEVICE_DELETE_TYPE DeleteType;
	/*0070*/
};

struct _PEP_ACPI_EXTENDED_ADDRESS {
	/*0000*/ _PEP_ACPI_RESOURCE_TYPE Type;
	/*0004*/ _PEP_ACPI_RESOURCE_FLAGS Flags;
	/*0008*/ UCHAR ResourceFlags;
	/*0009*/ UCHAR GeneralFlags;
	/*000a*/ UCHAR TypeSpecificFlags;
	/*000b*/ UCHAR RevisionId;
	/*000c*/ UCHAR Reserved;
	/*0010*/ ULONGLONG Granularity;
	/*0018*/ ULONGLONG MinimumAddress;
	/*0020*/ ULONGLONG MaximumAddress;
	/*0028*/ ULONGLONG TranslationAddress;
	/*0030*/ ULONGLONG AddressLength;
	/*0038*/ ULONGLONG TypeAttribute;
	/*0040*/ _UNICODE_STRING * DescriptorName;
	/*0048*/
};

struct _PEP_ACPI_GPIO_RESOURCE {
	/*0000*/ _PEP_ACPI_RESOURCE_TYPE Type;
	/*0004*/ _PEP_ACPI_RESOURCE_FLAGS Flags;
	/*0008*/ _KINTERRUPT_MODE InterruptType;
	/*000c*/ _KINTERRUPT_POLARITY InterruptPolarity;
	/*0010*/ _GPIO_PIN_CONFIG_TYPE PinConfig;
	/*0014*/ _GPIO_PIN_IORESTRICTION_TYPE IoRestrictionType;
	/*0018*/ USHORT DriveStrength;
	/*001a*/ USHORT DebounceTimeout;
	/*0020*/ USHORT * PinTable;
	/*0028*/ USHORT PinCount;
	/*002a*/ UCHAR ResourceSourceIndex;
	/*0030*/ _UNICODE_STRING * ResourceSourceName;
	/*0038*/ UCHAR * VendorData;
	/*0040*/ USHORT VendorDataLength;
	/*0048*/
};

struct _PEP_ACPI_INTERRUPT_RESOURCE {
	/*0000*/ _PEP_ACPI_RESOURCE_TYPE Type;
	/*0004*/ _KINTERRUPT_MODE InterruptType;
	/*0008*/ _KINTERRUPT_POLARITY InterruptPolarity;
	/*000c*/ _PEP_ACPI_RESOURCE_FLAGS Flags;
	/*0010*/ UCHAR Count;
	/*0018*/ ULONG * Pins;
	/*0020*/
};

struct _PEP_ACPI_IO_MEMORY_RESOURCE {
	/*0000*/ _PEP_ACPI_RESOURCE_TYPE Type;
	/*0004*/ UCHAR Information;
	/*0008*/ _LARGE_INTEGER MinimumAddress;
	/*0010*/ _LARGE_INTEGER MaximumAddress;
	/*0018*/ ULONG Alignment;
	/*001c*/ ULONG Length;
	/*0020*/
};

union _PEP_ACPI_RESOURCE {
	/*0000*/ _PEP_ACPI_RESOURCE_TYPE Type;
	/*0000*/ _PEP_ACPI_IO_MEMORY_RESOURCE IoMemory;
	/*0000*/ _PEP_ACPI_INTERRUPT_RESOURCE Interrupt;
	/*0000*/ _PEP_ACPI_GPIO_RESOURCE Gpio;
	/*0000*/ _PEP_ACPI_SPB_I2C_RESOURCE SpbI2c;
	/*0000*/ _PEP_ACPI_SPB_SPI_RESOURCE SpbSpi;
	/*0000*/ _PEP_ACPI_SPB_UART_RESOURCE SpbUart;
	/*0000*/ _PEP_ACPI_EXTENDED_ADDRESS ExtendedAddress;
	/*0048*/
};

union _PEP_ACPI_RESOURCE_FLAGS {
	/*0000*/ ULONG AsULong;
	/*0000*/ ULONG Shared : 01; // 0x00000001;
	/*0000*/ ULONG Wake : 01; // 0x00000002;
	/*0000*/ ULONG ResourceUsage : 01; // 0x00000004;
	/*0000*/ ULONG SlaveMode : 01; // 0x00000008;
	/*0000*/ ULONG AddressingMode : 01; // 0x00000010;
	/*0000*/ ULONG SharedMode : 01; // 0x00000020;
	/*0000*/ ULONG Reserved : 26; // 0xffffffc0;
	/*0004*/
};

enum _PEP_ACPI_RESOURCE_TYPE {
	PepAcpiMemory = 0x0,
	PepAcpiIoPort = 0x1,
	PepAcpiInterrupt = 0x2,
	PepAcpiGpioIo = 0x3,
	PepAcpiGpioInt = 0x4,
	PepAcpiSpbI2c = 0x5,
	PepAcpiSpbSpi = 0x6,
	PepAcpiSpbUart = 0x7,
	PepAcpiExtendedMemory = 0x8,
	PepAcpiExtendedIo = 0x9
};

struct _PEP_ACPI_SPB_I2C_RESOURCE {
	/*0000*/ _PEP_ACPI_SPB_RESOURCE SpbCommon;
	/*0028*/ ULONG ConnectionSpeed;
	/*002c*/ USHORT SlaveAddress;
	/*0030*/
};

struct _PEP_ACPI_SPB_RESOURCE {
	/*0000*/ _PEP_ACPI_RESOURCE_TYPE Type;
	/*0004*/ _PEP_ACPI_RESOURCE_FLAGS Flags;
	/*0008*/ USHORT TypeSpecificFlags;
	/*000a*/ UCHAR ResourceSourceIndex;
	/*0010*/ _UNICODE_STRING * ResourceSourceName;
	/*0018*/ CHAR * VendorData;
	/*0020*/ USHORT VendorDataLength;
	/*0028*/
};

struct _PEP_ACPI_SPB_SPI_RESOURCE {
	/*0000*/ _PEP_ACPI_SPB_RESOURCE SpbCommon;
	/*0028*/ ULONG ConnectionSpeed;
	/*002c*/ UCHAR DataBitLength;
	/*002d*/ UCHAR Phase;
	/*002e*/ UCHAR Polarity;
	/*0030*/ USHORT DeviceSelection;
	/*0038*/
};

struct _PEP_ACPI_SPB_UART_RESOURCE {
	/*0000*/ _PEP_ACPI_SPB_RESOURCE SpbCommon;
	/*0028*/ ULONG BaudRate;
	/*002c*/ USHORT RxBufferSize;
	/*002e*/ USHORT TxBufferSize;
	/*0030*/ UCHAR Parity;
	/*0031*/ UCHAR LinesInUse;
	/*0038*/
};

struct _PEP_CRASHDUMP_INFORMATION {
	/*0000*/ PEPHANDLE__ * DeviceHandle;
	/*0008*/ void * DeviceContext;
	/*0010*/
};

struct _PERFINFO_GROUPMASK {
	/*0000*/ ULONG Masks[0x8];
	/*0020*/
};

enum _PERFINFO_KERNELMEMORY_USAGE_TYPE {
	PerfInfoMemUsagePfnMetadata = 0x0,
	PerfInfoMemUsageMax = 0x1
};

enum _PERFINFO_MM_STAT {
	PerfInfoMMStatNotUsed = 0x0,
	PerfInfoMMStatAggregatePageCombine = 0x1,
	PerfInfoMMStatIterationPageCombine = 0x2,
	PerfInfoMMStatMax = 0x3
};

struct _PERFINFO_PPM_STATE_SELECTION {
	/*0000*/ ULONG SelectedState;
	/*0004*/ ULONG VetoedStates;
	/*0008*/ ULONG VetoReason[0x1];
	/*000c*/
};

struct _PERF_CONTROL_STATE_SELECTION {
	/*0000*/ ULONGLONG SelectedState;
	/*0008*/ ULONG SelectedPercent;
	/*000c*/ ULONG SelectedFrequency;
	/*0010*/ ULONG MinPercent;
	/*0014*/ ULONG MaxPercent;
	/*0018*/ ULONG TolerancePercent;
	/*001c*/ ULONG EppPercent;
	/*0020*/ ULONG AutonomousActivityWindow;
	/*0024*/ UCHAR Autonomous;
	/*0025*/ UCHAR InheritFromDomain;
	/*0028*/
};

struct _PERIODIC_CAPTURE_STATE_GUIDS {
	/*0000*/ USHORT ProviderCount;
	/*0008*/ _GUID * Providers;
	/*0010*/
};

enum _PF_FILE_ACCESS_TYPE {
	PfFileAccessTypeRead = 0x0,
	PfFileAccessTypeWrite = 0x1,
	PfFileAccessTypeMax = 0x2
};

struct _PF_KERNEL_GLOBALS {
	/*0000*/ ULONGLONG AccessBufferAgeThreshold;
	/*0008*/ _EX_RUNDOWN_REF AccessBufferRef;
	/*0010*/ _KEVENT AccessBufferExistsEvent;
	/*0028*/ ULONG AccessBufferMax;
	/*0040*/ _SLIST_HEADER AccessBufferList;
	/*0050*/ LONG StreamSequenceNumber;
	/*0054*/ ULONG Flags;
	/*0058*/ LONG ScenarioPrefetchCount;
	/*0060*/
};

struct _PHYSICAL_MEMORY_DESCRIPTOR {
	/*0000*/ ULONG NumberOfRuns;
	/*0008*/ ULONGLONG NumberOfPages;
	/*0010*/ _PHYSICAL_MEMORY_RUN Run[0x1];
	/*0020*/
};

struct _PHYSICAL_MEMORY_RUN {
	/*0000*/ ULONGLONG BasePage;
	/*0008*/ ULONGLONG PageCount;
	/*0010*/
};

struct _PI_BUS_EXTENSION {
	/*0000*/ ULONG Flags;
	/*0004*/ UCHAR NumberCSNs;
	/*0008*/ UCHAR * ReadDataPort;
	/*0010*/ UCHAR DataPortMapped;
	/*0018*/ UCHAR * AddressPort;
	/*0020*/ UCHAR AddrPortMapped;
	/*0028*/ UCHAR * CommandPort;
	/*0030*/ UCHAR CmdPortMapped;
	/*0034*/ ULONG NextSlotNumber;
	/*0038*/ _SINGLE_LIST_ENTRY DeviceList;
	/*0040*/ _SINGLE_LIST_ENTRY CardList;
	/*0048*/ _DEVICE_OBJECT * PhysicalBusDevice;
	/*0050*/ _DEVICE_OBJECT * FunctionalBusDevice;
	/*0058*/ _DEVICE_OBJECT * AttachedDevice;
	/*0060*/ ULONG BusNumber;
	/*0064*/ _SYSTEM_POWER_STATE SystemPowerState;
	/*0068*/ _DEVICE_POWER_STATE DevicePowerState;
	/*0070*/
};

struct _PI_RESOURCE_ARBITER_ENTRY {
	/*0000*/ _LIST_ENTRY DeviceArbiterList;
	/*0010*/ UCHAR ResourceType;
	/*0018*/ _ARBITER_INTERFACE * ArbiterInterface;
	/*0020*/ _DEVICE_NODE * DeviceNode;
	/*0028*/ _LIST_ENTRY ResourceList;
	/*0038*/ _LIST_ENTRY BestResourceList;
	/*0048*/ _LIST_ENTRY BestConfig;
	/*0058*/ _LIST_ENTRY ActiveArbiterList;
	/*0068*/ UCHAR State;
	/*0069*/ UCHAR ResourcesChanged;
	/*0070*/
};

struct _PLATFORM_IDLE_ACCOUNTING {
	/*0000*/ ULONG ResetCount;
	/*0004*/ ULONG StateCount;
	/*0008*/ ULONG DeepSleepCount;
	/*000c*/ PPM_IDLE_BUCKET_TIME_TYPE TimeUnit;
	/*0010*/ ULONGLONG StartTime;
	/*0018*/ _PLATFORM_IDLE_STATE_ACCOUNTING State[0x1];
	/*0408*/
};

struct _PLATFORM_IDLE_STATE_ACCOUNTING {
	/*0000*/ ULONG CancelCount;
	/*0004*/ ULONG FailureCount;
	/*0008*/ ULONG SuccessCount;
	/*0010*/ ULONGLONG MaxTime;
	/*0018*/ ULONGLONG MinTime;
	/*0020*/ ULONGLONG TotalTime;
	/*0028*/ ULONG InvalidBucketIndex;
	/*0030*/ _PPM_SELECTION_STATISTICS SelectionStatistics;
	/*00b0*/ _PROC_IDLE_STATE_BUCKET IdleTimeBuckets[0x1a];
	/*03f0*/
};

struct _PLUGPLAY_EVENT_BLOCK {
	/*0000*/ _GUID EventGuid;
	/*0010*/ _PLUGPLAY_EVENT_CATEGORY EventCategory;
	/*0018*/ ULONG * Result;
	/*0020*/ ULONG Flags;
	/*0024*/ ULONG TotalSize;
	/*0028*/ void * DeviceObject;
	union {
		struct {
			/*0030*/ _GUID ClassGuid;
			/*0040*/ WCHAR SymbolicLinkName[0x1];
			/*0044*/
		} DeviceClass;
		struct {
			/*0030*/ WCHAR DeviceId[0x1];
			/*0032*/
		} TargetDevice;
		struct {
			/*0030*/ WCHAR DeviceId[0x1];
			/*0032*/
		} InstallDevice;
		struct {
			/*0030*/ void * NotificationStructure;
			/*0038*/ WCHAR DeviceId[0x1];
			/*0040*/
		} CustomNotification;
		struct {
			/*0030*/ void * Notification;
			/*0038*/
		} ProfileNotification;
		struct {
			/*0030*/ ULONG NotificationCode;
			/*0034*/ ULONG NotificationData;
			/*0038*/
		} PowerNotification;
		struct {
			/*0030*/ _PNP_VETO_TYPE VetoType;
			/*0034*/ WCHAR DeviceIdVetoNameBuffer[0x1];
			/*0038*/
		} VetoNotification;
		struct {
			/*0030*/ _GUID BlockedDriverGuid;
			/*0040*/
		} BlockedDriverNotification;
		struct {
			/*0030*/ WCHAR ParentId[0x1];
			/*0032*/
		} InvalidIDNotification;
		struct {
			/*0030*/ _GUID PowerSettingGuid;
			/*0040*/ ULONG Flags;
			/*0044*/ ULONG SessionId;
			/*0048*/ ULONG DataLength;
			/*004c*/ UCHAR Data[0x1];
			/*0050*/
		} PowerSettingNotification;
		struct {
			/*0030*/ WCHAR DeviceId[0x1];
			/*0032*/
		} PropertyChangeNotification;
		struct {
			/*0030*/ WCHAR DeviceId[0x1];
			/*0032*/
		} DeviceInstanceNotification;
		/*0050*/
	} u;
	/*0050*/
};

enum _PLUGPLAY_EVENT_CATEGORY {
	HardwareProfileChangeEvent = 0x0,
	TargetDeviceChangeEvent = 0x1,
	DeviceClassChangeEvent = 0x2,
	CustomDeviceEvent = 0x3,
	DeviceInstallEvent = 0x4,
	DeviceArrivalEvent = 0x5,
	VetoEvent = 0x6,
	BlockedDriverEvent = 0x7,
	InvalidIDEvent = 0x8,
	DevicePropertyChangeEvent = 0x9,
	DeviceInstanceRemovalEvent = 0xa,
	DeviceInstanceStartedEvent = 0xb,
	MaxPlugEventCategory = 0xc
};

struct _PNP_ASSIGN_RESOURCES_CONTEXT {
	/*0000*/ ULONG IncludeFailedDevices;
	/*0004*/ ULONG DeviceCount;
	/*0008*/ _DEVICE_OBJECT * DeviceList[0x1];
	/*0010*/
};

struct _PNP_DEVICE_ACTION_ENTRY {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _DEVICE_OBJECT * DeviceObject;
	/*0018*/ _PNP_DEVICE_ACTION_REQUEST RequestType;
	/*001c*/ UCHAR ReorderingBarrier;
	/*0020*/ ULONGLONG RequestArgument;
	/*0028*/ _KEVENT * CompletionEvent;
	/*0030*/ LONG * CompletionStatus;
	/*0038*/ _GUID ActivityId;
	/*0048*/ LONG RefCount;
	/*004c*/ UCHAR Dequeued;
	/*0050*/ _EX_PUSH_LOCK CancelLock;
	/*0058*/ UCHAR CancelRequested;
	/*0060*/
};

enum _PNP_DEVICE_ACTION_REQUEST {
	AssignResources = 0x0,
	ClearDeviceProblem = 0x1,
	ClearProblem = 0x2,
	ClearEjectProblem = 0x3,
	HaltDevice = 0x4,
	QueryPowerRelations = 0x5,
	Rebalance = 0x6,
	ReenumerateBootDevices = 0x7,
	ReenumerateDeviceOnly = 0x8,
	ReenumerateDeviceTree = 0x9,
	ReenumerateRootDevices = 0xa,
	RequeryDeviceState = 0xb,
	ResetDevice = 0xc,
	ResourceRequirementsChanged = 0xd,
	RestartEnumeration = 0xe,
	SetDeviceProblem = 0xf,
	StartDevice = 0x10,
	StartSystemDevicesPass0 = 0x11,
	StartSystemDevicesPass1 = 0x12,
	NotifyTransportRelationsChange = 0x13,
	NotifyEjectionRelationsChange = 0x14,
	ConfigureDevice = 0x15,
	ConfigureDeviceClass = 0x16,
	ConfigureDeviceExtensions = 0x17,
	ConfigureDeviceReset = 0x18,
	ClearDmaGuardProblem = 0x19
};

struct _PNP_DEVICE_COMPLETION_QUEUE {
	/*0000*/ _LIST_ENTRY DispatchedList;
	/*0010*/ ULONG DispatchedCount;
	/*0018*/ _LIST_ENTRY CompletedList;
	/*0028*/ _KSEMAPHORE CompletedSemaphore;
	/*0048*/ ULONGLONG SpinLock;
	/*0050*/
};

struct _PNP_DEVICE_COMPLETION_REQUEST {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _DEVICE_NODE * DeviceNode;
	/*0018*/ void * Context;
	/*0020*/ _PNP_DEVNODE_STATE CompletionState;
	/*0024*/ ULONG IrpPended;
	/*0028*/ LONG Status;
	/*0030*/ void * Information;
	/*0038*/ LONG ReferenceCount;
	/*0040*/
};

enum _PNP_DEVICE_DELETE_TYPE {
	QueryRemoveDevice = 0x0,
	CancelRemoveDevice = 0x1,
	RemoveDevice = 0x2,
	SurpriseRemoveDevice = 0x3,
	EjectDevice = 0x4,
	RemoveFailedDevice = 0x5,
	RemoveUnstartedFailedDevice = 0x6,
	MaxDeviceDeleteType = 0x7
};

struct _PNP_DEVICE_EVENT_ENTRY {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ ULONG Argument;
	/*0014*/ LONG ArgumentStatus;
	/*0018*/ _KEVENT * CallerEvent;
	/*0020*/ void (* Callback)( void * );
	/*0028*/ void * Context;
	/*0030*/ _PNP_VETO_TYPE * VetoType;
	/*0038*/ _UNICODE_STRING * VetoName;
	/*0040*/ ULONG RefCount;
	/*0044*/ ULONG Lock;
	/*0048*/ UCHAR Cancel;
	/*0050*/ _PNP_DEVICE_EVENT_ENTRY * Parent;
	/*0058*/ _GUID ActivityId;
	/*0068*/ _PLUGPLAY_EVENT_BLOCK Data;
	/*00b8*/
};

struct _PNP_DEVICE_EVENT_LIST {
	/*0000*/ LONG Status;
	/*0008*/ _KMUTANT EventQueueMutex;
	/*0040*/ _FAST_MUTEX Lock;
	/*0078*/ _LIST_ENTRY List;
	/*0088*/
};

enum _PNP_DEVNODE_QUERY_REBALANCE_VETO_REASON {
	DeviceQueryRebalanceSucceeded = 0x0,
	DeviceQueryStopFailed = 0x1,
	DeviceFailedGetNewResourceRequirement = 0x2,
	DeviceInUnexpectedState = 0x3,
	DeviceNotSupportQueryRebalance = 0x4
};

enum _PNP_DEVNODE_STATE {
	DeviceNodeUnspecified = 0x300,
	DeviceNodeUninitialized = 0x301,
	DeviceNodeInitialized = 0x302,
	DeviceNodeDriversAdded = 0x303,
	DeviceNodeResourcesAssigned = 0x304,
	DeviceNodeStartPending = 0x305,
	DeviceNodeStartCompletion = 0x306,
	DeviceNodeStartPostWork = 0x307,
	DeviceNodeStarted = 0x308,
	DeviceNodeQueryStopped = 0x309,
	DeviceNodeStopped = 0x30a,
	DeviceNodeRestartCompletion = 0x30b,
	DeviceNodeEnumeratePending = 0x30c,
	DeviceNodeEnumerateCompletion = 0x30d,
	DeviceNodeAwaitingQueuedDeletion = 0x30e,
	DeviceNodeAwaitingQueuedRemoval = 0x30f,
	DeviceNodeQueryRemoved = 0x310,
	DeviceNodeRemovePendingCloses = 0x311,
	DeviceNodeRemoved = 0x312,
	DeviceNodeDeletePendingCloses = 0x313,
	DeviceNodeDeleted = 0x314,
	MaxDeviceNodeState = 0x315
};

enum _PNP_REBALANCE_FAILURE {
	RebalanceFailureNone = 0x0,
	RebalanceFailureDisabled = 0x1,
	RebalanceFailureNoMemory = 0x2,
	RebalanceFailureQueryStopUnexpectedVeto = 0x3,
	RebalanceFailureNoRequirements = 0x4,
	RebalanceFailureNoCandidates = 0x5,
	RebalanceFailureNoConfiguration = 0x6
};

enum _PNP_REBALANCE_REASON {
	RebalanceReasonUnknown = 0x0,
	RebalanceReasonRequirementsChanged = 0x1,
	RebalanceReasonNewDevice = 0x2
};

struct _PNP_REBALANCE_TRACE_CONTEXT {
	/*0000*/ ULONG DeviceCount;
	/*0004*/ ULONG RebalancePhase;
	/*0008*/ _PNP_REBALANCE_REASON Reason[0x2];
	/*0010*/ _PNP_REBALANCE_FAILURE Failure[0x2];
	/*0018*/ _DEVICE_NODE * SubtreeRoot;
	/*0020*/ UCHAR SubtreeIncludesRoot;
	/*0028*/ _DEVICE_NODE * TriggerRoot;
	/*0030*/ UCHAR RebalanceDueToDynamicPartitioning;
	/*0038*/ ULONGLONG BeginTime;
	/*0040*/ _DEVICE_NODE * VetoNode[0x2];
	/*0050*/ _PNP_DEVNODE_QUERY_REBALANCE_VETO_REASON VetoQueryRebalanceReason[0x2];
	/*0058*/ _PNP_RESOURCE_CONFLICT_TRACE_CONTEXT ConflictContext;
	/*0070*/
};

struct _PNP_RESOURCE_CONFLICT_TRACE_CONTEXT {
	/*0000*/ UCHAR ResourceType;
	/*0004*/ ULONG AlternativeCount;
	/*0008*/ _IO_RESOURCE_DESCRIPTOR * ResourceRequests;
	/*0010*/ void * ArbiterInstance;
	/*0018*/
};

struct _PNP_RESOURCE_REQUEST {
	/*0000*/ _DEVICE_OBJECT * PhysicalDevice;
	/*0008*/ ULONG Flags;
	/*000c*/ _ARBITER_REQUEST_SOURCE AllocationType;
	/*0010*/ ULONG Priority;
	/*0014*/ ULONG Position;
	/*0018*/ _IO_RESOURCE_REQUIREMENTS_LIST * ResourceRequirements;
	/*0020*/ void * ReqList;
	/*0028*/ _CM_RESOURCE_LIST * ResourceAssignment;
	/*0030*/ _CM_RESOURCE_LIST * TranslatedResourceAssignment;
	/*0038*/ LONG Status;
	/*0040*/
};

enum _PNP_VETO_TYPE {
	PNP_VetoTypeUnknown = 0x0,
	PNP_VetoLegacyDevice = 0x1,
	PNP_VetoPendingClose = 0x2,
	PNP_VetoWindowsApp = 0x3,
	PNP_VetoWindowsService = 0x4,
	PNP_VetoOutstandingOpen = 0x5,
	PNP_VetoDevice = 0x6,
	PNP_VetoDriver = 0x7,
	PNP_VetoIllegalDeviceRequest = 0x8,
	PNP_VetoInsufficientPower = 0x9,
	PNP_VetoNonDisableable = 0xa,
	PNP_VetoLegacyDriver = 0xb,
	PNP_VetoInsufficientRights = 0xc
};

enum _POLICY_AUDIT_EVENT_TYPE {
	AuditCategorySystem = 0x0,
	AuditCategoryLogon = 0x1,
	AuditCategoryObjectAccess = 0x2,
	AuditCategoryPrivilegeUse = 0x3,
	AuditCategoryDetailedTracking = 0x4,
	AuditCategoryPolicyChange = 0x5,
	AuditCategoryAccountManagement = 0x6,
	AuditCategoryDirectoryServiceAccess = 0x7,
	AuditCategoryAccountLogon = 0x8
};

struct _POOL_DESCRIPTOR {
	/*0000*/ _POOL_TYPE PoolType;
	/*0008*/ _FAST_MUTEX PagedLock;
	/*0008*/ ULONGLONG NonPagedLock;
	/*0040*/ LONG volatile RunningAllocs;
	/*0048*/ ULONGLONG volatile PagesAllocated;
	/*0050*/ ULONGLONG volatile BigPagesAllocated;
	/*0058*/ ULONGLONG volatile BytesAllocated;
	/*0080*/ LONG volatile RunningDeallocs;
	/*0088*/ ULONGLONG volatile PagesDeallocated;
	/*0090*/ ULONGLONG volatile BigPagesDeallocated;
	/*0098*/ ULONGLONG volatile BytesDeallocated;
	/*00c0*/ ULONG PoolIndex;
	/*00c4*/ _POOL_TYPE PoolTypeCopy;
	/*0100*/ _SINGLE_LIST_ENTRY PendingFrees;
	/*0108*/ LONG volatile ThreadsProcessingDeferrals;
	/*010c*/ LONG volatile PendingFreeDepth;
	/*0140*/ _LIST_ENTRY ListHeads[0x100];
	/*1140*/
};

struct _POOL_HEADER {
	/*0000*/ USHORT PreviousSize : 08; // 0x00ff;
	/*0000*/ USHORT PoolIndex : 08; // 0xff00;
	/*0002*/ USHORT BlockSize : 08; // 0x00ff;
	/*0002*/ USHORT PoolType : 08; // 0xff00;
	/*0000*/ ULONG Ulong1;
	/*0004*/ ULONG PoolTag;
	/*0008*/ _EPROCESS * ProcessBilled;
	/*0008*/ USHORT AllocatorBackTraceIndex;
	/*000a*/ USHORT PoolTagHash;
	/*0010*/
};

struct _POOL_TRACKER_BIG_PAGES {
	/*0000*/ ULONGLONG volatile Va;
	/*0008*/ ULONG Key;
	/*000c*/ ULONG Pattern : 08; // 0x000000ff;
	/*000c*/ ULONG PoolType : 12; // 0x000fff00;
	/*000c*/ ULONG SlushSize : 12; // 0xfff00000;
	/*0010*/ ULONGLONG NumberOfBytes;
	/*0018*/
};

struct _POOL_TRACKER_TABLE {
	/*0000*/ LONG volatile Key;
	/*0008*/ ULONGLONG NonPagedBytes;
	/*0010*/ ULONGLONG NonPagedAllocs;
	/*0018*/ ULONGLONG NonPagedFrees;
	/*0020*/ ULONGLONG PagedBytes;
	/*0028*/ ULONGLONG PagedAllocs;
	/*0030*/ ULONGLONG PagedFrees;
	/*0038*/
};

enum _POOL_TYPE {
	NonPagedPool = 0x0,
	NonPagedPoolExecute = 0x0,
	PagedPool = 0x1,
	NonPagedPoolMustSucceed = 0x2,
	DontUseThisType = 0x3,
	NonPagedPoolCacheAligned = 0x4,
	PagedPoolCacheAligned = 0x5,
	NonPagedPoolCacheAlignedMustS = 0x6,
	MaxPoolType = 0x7,
	NonPagedPoolBase = 0x0,
	NonPagedPoolBaseMustSucceed = 0x2,
	NonPagedPoolBaseCacheAligned = 0x4,
	NonPagedPoolBaseCacheAlignedMustS = 0x6,
	NonPagedPoolSession = 0x20,
	PagedPoolSession = 0x21,
	NonPagedPoolMustSucceedSession = 0x22,
	DontUseThisTypeSession = 0x23,
	NonPagedPoolCacheAlignedSession = 0x24,
	PagedPoolCacheAlignedSession = 0x25,
	NonPagedPoolCacheAlignedMustSSession = 0x26,
	NonPagedPoolNx = 0x200,
	NonPagedPoolNxCacheAligned = 0x204,
	NonPagedPoolSessionNx = 0x220
};

struct _POP_ACTION_TRIGGER {
	/*0000*/ POWER_POLICY_DEVICE_TYPE Type;
	/*0004*/ ULONG Flags;
	/*0008*/ _POP_TRIGGER_WAIT * Wait;
	struct {
		/*0010*/ ULONG PercentLevel;
		/*0014*/
	} Battery;
	struct {
		/*0010*/ ULONG Type;
		/*0014*/
	} Button;
	/*0018*/
};

struct _POP_COOLING_EXTENSION {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ _LIST_ENTRY RequestListHead;
	/*0020*/ _POP_RW_LOCK Lock;
	/*0030*/ _DEVICE_OBJECT * DeviceObject;
	/*0038*/ void * NotificationEntry;
	/*0040*/ UCHAR Enabled;
	/*0041*/ UCHAR ActiveEngaged;
	/*0042*/ UCHAR ThrottleLimit;
	/*0043*/ UCHAR UpdatingToCurrent;
	/*0048*/ _KEVENT * RemovalFlushEvent;
	/*0050*/ _KEVENT * PnpFlushEvent;
	/*0058*/ _THERMAL_COOLING_INTERFACE Interface;
	/*0090*/
};

struct _POP_CURRENT_BROADCAST {
	/*0000*/ UCHAR InProgress;
	/*0004*/ _SYSTEM_POWER_STATE_CONTEXT SystemContext;
	/*0008*/ POWER_ACTION PowerAction;
	/*0010*/ _POP_DEVICE_SYS_STATE * DeviceState;
	/*0018*/
};

enum _POP_DEVICE_IDLE_TYPE {
	DeviceIdleNormal = 0x0,
	DeviceIdleDisk = 0x1
};

struct _POP_DEVICE_SYS_STATE {
	/*0000*/ UCHAR IrpMinor;
	/*0004*/ _SYSTEM_POWER_STATE SystemState;
	/*0008*/ ULONGLONG SpinLock;
	/*0010*/ _KTHREAD * Thread;
	/*0018*/ _KEVENT * AbortEvent;
	/*0020*/ _KSEMAPHORE * ReadySemaphore;
	/*0028*/ _KSEMAPHORE * FinishedSemaphore;
	/*0030*/ _PO_DEVICE_NOTIFY_ORDER Order;
	/*01a8*/ _LIST_ENTRY Pending;
	/*01b8*/ LONG Status;
	/*01c0*/ _DEVICE_OBJECT * FailedDevice;
	/*01c8*/ UCHAR Waking;
	/*01c9*/ UCHAR Cancelled;
	/*01ca*/ UCHAR IgnoreErrors;
	/*01cb*/ UCHAR IgnoreNotImplemented;
	/*01cc*/ UCHAR TimeRefreshLockAcquired;
	/*01d0*/
};

struct _POP_FX_ACCOUNTING {
	/*0000*/ ULONGLONG Lock;
	/*0008*/ UCHAR Active;
	/*000c*/ ULONG DripsRequiredState;
	/*0010*/ LONG Level;
	/*0018*/ LONGLONG ActiveStamp;
	/*0020*/ ULONGLONG CsActiveTime;
	/*0028*/ LONGLONG CriticalActiveTime;
	/*0030*/
};

struct _POP_FX_COMPONENT {
	/*0000*/ _GUID Id;
	/*0010*/ ULONG Index;
	/*0018*/ _POP_FX_WORK_ORDER WorkOrder;
	/*0050*/ _POP_FX_DEVICE * Device;
	/*0058*/ _POP_FX_COMPONENT_FLAGS volatile Flags;
	/*0060*/ LONG volatile Resident;
	/*0068*/ _KEVENT ActiveEvent;
	/*0080*/ ULONGLONG IdleLock;
	/*0088*/ LONG volatile IdleConditionComplete;
	/*008c*/ LONG volatile IdleStateComplete;
	/*0090*/ ULONGLONG IdleStamp;
	/*0098*/ ULONG volatile CurrentIdleState;
	/*009c*/ ULONG IdleStateCount;
	/*00a0*/ _POP_FX_IDLE_STATE * IdleStates;
	/*00a8*/ ULONG DeepestWakeableIdleState;
	/*00ac*/ ULONG ProviderCount;
	/*00b0*/ _POP_FX_PROVIDER * Providers;
	/*00b8*/ ULONG IdleProviderCount;
	/*00bc*/ ULONG DependentCount;
	/*00c0*/ _POP_FX_DEPENDENT * Dependents;
	/*00c8*/ _POP_FX_ACCOUNTING Accounting;
	/*00f8*/ _POP_FX_PERF_INFO * Performance;
	/*0100*/
};

union _POP_FX_COMPONENT_FLAGS {
	/*0000*/ LONG Value;
	/*0004*/ LONG Value2;
	/*0000*/ ULONG RefCount : 30; // 0x3fffffff;
	/*0000*/ ULONG Idling : 01; // 0x40000000;
	/*0000*/ ULONG Active : 01; // 0x80000000;
	/*0004*/ ULONG CriticalIdleOverride : 01; // 0x00000001;
	/*0004*/ ULONG ResidentOverride : 01; // 0x00000002;
	/*0004*/ ULONG Reserved : 30; // 0xfffffffc;
	/*0008*/
};

struct _POP_FX_DEPENDENT {
	/*0000*/ ULONG Index;
	/*0004*/ ULONG ProviderIndex;
	/*0008*/
};

struct _POP_FX_DEVICE {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ _IRP * Irp;
	/*0018*/ _POP_IRP_DATA * IrpData;
	/*0020*/ _POP_FX_DEVICE_STATUS volatile Status;
	/*0024*/ LONG volatile PowerReqCall;
	/*0028*/ LONG volatile PowerNotReqCall;
	/*0030*/ _DEVICE_NODE * DevNode;
	/*0038*/ PEPHANDLE__ * DpmContext;
	/*0040*/ _POP_FX_PLUGIN * Plugin;
	/*0048*/ PEPHANDLE__ * PluginHandle;
	/*0050*/ _POP_FX_PLUGIN * AcpiPlugin;
	/*0058*/ PEPHANDLE__ * AcpiPluginHandle;
	/*0060*/ _DEVICE_OBJECT * DeviceObject;
	/*0068*/ _DEVICE_OBJECT * TargetDevice;
	/*0070*/ _POP_FX_DRIVER_CALLBACKS Callbacks;
	/*00b0*/ void * DriverContext;
	/*00b8*/ _LIST_ENTRY AcpiLink;
	/*00c8*/ _UNICODE_STRING DeviceId;
	/*00d8*/ _IO_REMOVE_LOCK RemoveLock;
	/*00f8*/ _IO_REMOVE_LOCK AcpiRemoveLock;
	/*0118*/ _POP_FX_WORK_ORDER WorkOrder;
	/*0150*/ ULONGLONG IdleLock;
	/*0158*/ _KTIMER IdleTimer;
	/*0198*/ _KDPC IdleDpc;
	/*01d8*/ ULONGLONG IdleTimeout;
	/*01e0*/ ULONGLONG IdleStamp;
	/*01e8*/ _DEVICE_OBJECT * NextIrpDeviceObject[0x2];
	/*01f8*/ _POWER_STATE NextIrpPowerState[0x2];
	/*0200*/ void (* NextIrpCallerCompletion[0x2])( _DEVICE_OBJECT * , UCHAR , _POWER_STATE , void * , _IO_STATUS_BLOCK * );
	/*0210*/ void * NextIrpCallerContext[0x2];
	/*0220*/ _KEVENT IrpCompleteEvent;
	/*0238*/ UCHAR (* PowerOnDumpDeviceCallback)( _PEP_CRASHDUMP_INFORMATION * );
	/*0240*/ _POP_FX_ACCOUNTING Accounting;
	/*0270*/ ULONG volatile Flags;
	/*0274*/ ULONG ComponentCount;
	/*0278*/ _POP_FX_COMPONENT * * Components;
	/*0280*/ ULONG LogEntries;
	/*0288*/ _POP_FX_LOG_ENTRY * Log;
	/*0290*/ LONG volatile LogIndex;
	/*0298*/ _DRIVER_OBJECT * DripsWatchdogDriverObject;
	/*02a0*/
};

union _POP_FX_DEVICE_STATUS {
	/*0000*/ LONG Value;
	/*0000*/ ULONG SystemTransition : 01; // 0x00000001;
	/*0000*/ ULONG PepD0Notify : 01; // 0x00000002;
	/*0000*/ ULONG IdleTimerOn : 01; // 0x00000004;
	/*0000*/ ULONG IgnoreIdleTimeout : 01; // 0x00000008;
	/*0000*/ ULONG IrpInUse : 01; // 0x00000010;
	/*0000*/ ULONG IrpPending : 01; // 0x00000020;
	/*0000*/ ULONG DPNRDeviceNotified : 01; // 0x00000040;
	/*0000*/ ULONG DPNRReceivedFromPep : 01; // 0x00000080;
	/*0000*/ ULONG IrpFirstPendingIndex : 01; // 0x00000100;
	/*0000*/ ULONG IrpLastPendingIndex : 01; // 0x00000200;
	/*0000*/ ULONG SIrpBlocked : 01; // 0x00000400;
	/*0000*/ ULONG BlockFastResume : 01; // 0x00000800;
	/*0000*/ ULONG Reserved : 20; // 0xfffff000;
	/*0004*/
};

struct _POP_FX_DRIVER_CALLBACKS {
	/*0000*/ void (* ComponentActive)( void * , ULONG );
	/*0008*/ void (* ComponentIdle)( void * , ULONG );
	/*0010*/ void (* ComponentIdleState)( void * , ULONG , ULONG );
	/*0018*/ void (* DevicePowerRequired)( void * );
	/*0020*/ void (* DevicePowerNotRequired)( void * );
	/*0028*/ LONG (* PowerControl)( void * , _GUID const * , void * , ULONGLONG , void * , ULONGLONG , ULONGLONG * );
	/*0030*/ void (* ComponentCriticalTransition)( void * , ULONG , UCHAR );
	/*0038*/ void (* DripsWatchdogCallback)( void * , _DEVICE_OBJECT * , ULONG );
	/*0040*/
};

struct _POP_FX_IDLE_STATE {
	/*0000*/ ULONGLONG TransitionLatency;
	/*0008*/ ULONGLONG ResidencyRequirement;
	/*0010*/ ULONG NominalPower;
	/*0018*/
};

struct _POP_FX_LOG_ENTRY {
	/*0000*/ ULONGLONG Timestamp;
	/*0008*/ UCHAR Operation;
	/*0009*/ UCHAR Component;
	/*000a*/ USHORT Processor;
	/*000c*/ USHORT Process;
	/*000e*/ USHORT Thread;
	/*0010*/ ULONGLONG Information;
	/*0018*/
};

union _POP_FX_PERF_FLAGS {
	/*0000*/ LONG Value;
	/*0000*/ ULONG Progress : 03; // 0x00000007;
	/*0000*/ ULONG Reserved : 24; // 0x07fffff8;
	/*0000*/ ULONG Synchronicity : 02; // 0x18000000;
	/*0000*/ ULONG RequestPepCompleted : 01; // 0x20000000;
	/*0000*/ ULONG RequestSucceeded : 01; // 0x40000000;
	/*0000*/ ULONG NestedCallback : 01; // 0x80000000;
	/*0004*/
};

struct _POP_FX_PERF_INFO {
	/*0000*/ _POP_FX_COMPONENT * Component;
	/*0008*/ _KEVENT CompletedEvent;
	/*0020*/ void (* ComponentPerfState)( void * , ULONG , UCHAR , void * );
	/*0028*/ _POP_FX_PERF_FLAGS volatile Flags;
	/*0030*/ _PO_FX_PERF_STATE_CHANGE * LastChange;
	/*0038*/ ULONG LastChangeCount;
	/*0040*/ ULONGLONG LastChangeStamp;
	/*0048*/ UCHAR LastChangeNominal;
	/*0049*/ UCHAR PepRegistered;
	/*004a*/ UCHAR QueryOnIdleStates;
	/*0050*/ void * volatile RequestDriverContext;
	/*0058*/ _POP_FX_WORK_ORDER WorkOrder;
	/*0090*/ ULONG SetsCount;
	/*0098*/ _POP_FX_PERF_SET * Sets;
	/*00a0*/
};

struct _POP_FX_PERF_SET {
	/*0000*/ _PO_FX_COMPONENT_PERF_SET * PerfSet;
	/*0008*/ ULONGLONG CurrentPerf;
	/*0010*/ ULONGLONG CurrentPerfStamp;
	/*0018*/ UCHAR CurrentPerfNominal;
	/*0020*/
};

struct _POP_FX_PLUGIN {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ ULONG Version;
	/*0018*/ ULONGLONG Flags;
	/*0020*/ _KQUEUE WorkQueue;
	/*0060*/ UCHAR (* AcceptDeviceNotification)( ULONG , void * );
	/*0068*/ UCHAR (* AcceptProcessorNotification)( PEPHANDLE__ * , ULONG , void * );
	/*0070*/ UCHAR (* AcceptAcpiNotification)( ULONG , void * );
	/*0078*/ ULONG WorkOrderCount;
	/*0080*/ _POP_FX_WORK_ORDER WorkOrders[0x1];
	/*00b8*/
};

struct _POP_FX_PROVIDER {
	/*0000*/ ULONG Index;
	/*0004*/ UCHAR Activating;
	/*0008*/
};

struct _POP_FX_WORK_ORDER {
	/*0000*/ _WORK_QUEUE_ITEM WorkItem;
	/*0020*/ LONG WorkCount;
	/*0028*/ void * Context;
	/*0030*/ _POP_FX_WORK_ORDER_WATCHDOG_INFO * WatchdogTimerInfo;
	/*0038*/
};

struct _POP_FX_WORK_ORDER_WATCHDOG_INFO {
	/*0000*/ _KTIMER Timer;
	/*0040*/ _KDPC Dpc;
	/*0080*/ _POP_FX_WORK_ORDER * WorkOrder;
	/*0088*/
};

struct _POP_HIBER_CONTEXT {
	/*0000*/ UCHAR Reset;
	/*0001*/ UCHAR HiberFlags;
	/*0002*/ UCHAR WroteHiberFile;
	/*0003*/ UCHAR KernelPhaseVerificationActive;
	/*0004*/ UCHAR volatile InitializationFinished;
	/*0008*/ LONG volatile NextTableLockHeld;
	/*000c*/ LONG volatile BootPhaseFinishedBarrier;
	/*0010*/ LONG volatile KernelResumeFinishedBarrier;
	/*0014*/ LONG volatile HvCaptureReadyBarrier;
	/*0018*/ LONG volatile HvCaptureCompletedBarrier;
	/*001c*/ UCHAR MapFrozen;
	/*0020*/ _RTL_BITMAP DiscardMap;
	/*0020*/ _RTL_BITMAP KernelPhaseMap;
	/*0030*/ _RTL_BITMAP BootPhaseMap;
	/*0040*/ _LIST_ENTRY ClonedRanges;
	/*0050*/ ULONG ClonedRangeCount;
	/*0058*/ ULONGLONG ClonedPageCount;
	/*0060*/ _RTL_BITMAP * CurrentMap;
	/*0068*/ _LIST_ENTRY * NextCloneRange;
	/*0070*/ ULONGLONG NextPreserve;
	/*0078*/ _MDL * LoaderMdl;
	/*0080*/ _MDL * AllocatedMdl;
	/*0088*/ ULONGLONG PagesOut;
	/*0090*/ void * IoPages;
	/*0098*/ ULONG IoPagesCount;
	/*00a0*/ void * CurrentMcb;
	/*00a8*/ _DUMP_STACK_CONTEXT * DumpStack;
	/*00b0*/ _KPROCESSOR_STATE * WakeState;
	/*00b8*/ ULONG IoProgress;
	/*00bc*/ LONG Status;
	/*00c0*/ ULONG GraphicsProc;
	/*00c8*/ PO_MEMORY_IMAGE * MemoryImage;
	/*00d0*/ ULONG * PerformanceStats;
	/*00d8*/ _MDL * BootLoaderLogMdl;
	/*00e0*/ ULONG SiLogOffset;
	/*00e8*/ _MDL * FirmwareRuntimeInformationMdl;
	/*00f0*/ void * FirmwareRuntimeInformationVa;
	/*00f8*/ void * ResumeContext;
	/*0100*/ ULONG ResumeContextPages;
	/*0104*/ ULONG SecurePages;
	/*0108*/ ULONG ProcessorCount;
	/*0110*/ _POP_PER_PROCESSOR_CONTEXT * ProcessorContext;
	/*0118*/ CHAR * ProdConsBuffer;
	/*0120*/ ULONG ProdConsSize;
	/*0124*/ ULONG MaxDataPages;
	/*0128*/ void * ExtraBuffer;
	/*0130*/ ULONGLONG ExtraBufferSize;
	/*0138*/ void * ExtraMapVa;
	/*0140*/ ULONGLONG BitlockerKeyPFN;
	/*0148*/ _POP_IO_INFO IoInfo;
	/*01b8*/ USHORT * IoChecksums;
	/*01c0*/ ULONGLONG IoChecksumsSize;
	/*01c8*/ ULONG HardwareConfigurationSignature;
	/*01cc*/ UCHAR IumEnabled;
	/*01d0*/
};

struct _POP_IO_INFO {
	/*0000*/ _MDL * DumpMdl;
	/*0008*/ _POP_IO_STATUS IoStatus;
	/*0010*/ ULONGLONG IoStartCount;
	/*0018*/ ULONGLONG IoBytesCompleted;
	/*0020*/ ULONGLONG IoBytesInProgress;
	/*0028*/ ULONGLONG RequestSize;
	/*0030*/ _LARGE_INTEGER IoLocation;
	/*0038*/ ULONGLONG FileOffset;
	/*0040*/ void * Buffer;
	/*0048*/ UCHAR AsyncCapable;
	/*0050*/ ULONGLONG BytesToRead;
	/*0058*/ ULONG Pages;
	/*0060*/ ULONGLONG HighestChecksumIndex;
	/*0068*/ USHORT PreviousChecksum;
	/*0070*/
};

enum _POP_IO_STATUS {
	IoReady = 0x0,
	IoPending = 0x1,
	IoDone = 0x2
};

struct _POP_IRP_DATA {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ _IRP * Irp;
	/*0018*/ _DEVICE_OBJECT * Pdo;
	/*0020*/ _DEVICE_OBJECT * TargetDevice;
	/*0028*/ _DEVICE_OBJECT * CurrentDevice;
	/*0030*/ ULONGLONG WatchdogStart;
	/*0038*/ _KTIMER WatchdogTimer;
	/*0078*/ _KDPC WatchdogDpc;
	/*00b8*/ UCHAR MinorFunction;
	/*00bc*/ _POWER_STATE_TYPE PowerStateType;
	/*00c0*/ _POWER_STATE PowerState;
	/*00c4*/ UCHAR WatchdogEnabled;
	/*00c8*/ _POP_FX_DEVICE * FxDevice;
	/*00d0*/ UCHAR SystemTransition;
	/*00d1*/ UCHAR NotifyPEP;
	struct {
		/*00d8*/ void (* CallerCompletion)( _DEVICE_OBJECT * , UCHAR , _POWER_STATE , void * , _IO_STATUS_BLOCK * );
		/*00e0*/ void * CallerContext;
		/*00e8*/ _DEVICE_OBJECT * CallerDevice;
		/*00f0*/ UCHAR SystemWake;
		/*00f8*/
	} Device;
	struct {
		/*00d8*/ _PO_DEVICE_NOTIFY * NotifyDevice;
		/*00e0*/ UCHAR FxDeviceActivated;
		/*00e8*/
	} System;
	/*00f8*/
};

struct _POP_IRP_WORKER_ENTRY {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ _ETHREAD * Thread;
	/*0018*/ _IRP * Irp;
	/*0020*/ _DEVICE_OBJECT * Device;
	/*0028*/ UCHAR Static;
	/*0030*/
};

struct _POP_PER_PROCESSOR_CONTEXT {
	/*0000*/ UCHAR * UncompressedData;
	/*0008*/ void * MappingVa;
	/*0010*/ void * XpressEncodeWorkspace;
	/*0018*/ UCHAR * CompressedDataBuffer;
	/*0020*/ ULONGLONG CopyTicks;
	/*0028*/ ULONGLONG CompressTicks;
	/*0030*/ ULONGLONG BytesCopied;
	/*0038*/ ULONGLONG PagesProcessed;
	/*0040*/ ULONGLONG DecompressTicks;
	/*0048*/ ULONGLONG ResumeCopyTicks;
	/*0050*/ ULONGLONG SharedBufferTicks;
	/*0058*/ ULONGLONG DecompressTicksByMethod[0x2];
	/*0068*/ ULONGLONG DecompressSizeByMethod[0x2];
	/*0078*/ ULONG CompressCount;
	/*007c*/ ULONG HuffCompressCount;
	/*0080*/
};

struct _POP_POLICY_DEVICE {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ POWER_POLICY_DEVICE_TYPE DeviceType;
	/*0018*/ void * Notification;
	/*0020*/ _UNICODE_STRING Name;
	/*0030*/ _DEVICE_OBJECT * Device;
	/*0038*/ _IRP * Irp;
	/*0040*/
};

struct _POP_POWER_ACTION {
	/*0000*/ UCHAR Updates;
	/*0001*/ UCHAR State;
	/*0002*/ UCHAR Shutdown;
	/*0004*/ POWER_ACTION Action;
	/*0008*/ _SYSTEM_POWER_STATE LightestState;
	/*000c*/ ULONG Flags;
	/*0010*/ LONG Status;
	/*0014*/ POWER_POLICY_DEVICE_TYPE DeviceType;
	/*0018*/ ULONG DeviceTypeFlags;
	/*001c*/ UCHAR IrpMinor;
	/*001d*/ UCHAR Waking;
	/*0020*/ _SYSTEM_POWER_STATE SystemState;
	/*0024*/ _SYSTEM_POWER_STATE NextSystemState;
	/*0028*/ _SYSTEM_POWER_STATE EffectiveSystemState;
	/*002c*/ _SYSTEM_POWER_STATE CurrentSystemState;
	/*0030*/ _POP_SHUTDOWN_BUG_CHECK * ShutdownBugCode;
	/*0038*/ _POP_DEVICE_SYS_STATE * DevState;
	/*0040*/ _POP_HIBER_CONTEXT * HiberContext;
	/*0048*/ ULONGLONG WakeTime;
	/*0050*/ ULONGLONG SleepTime;
	/*0058*/ ULONGLONG WakeFirstUnattendedTime;
	/*0060*/ SYSTEM_POWER_CONDITION WakeAlarmSignaled;
	struct {
		/*0000*/ ULONGLONG RequestedTime;
		/*0008*/ ULONGLONG ProgrammedTime;
		/*0010*/ _DIAGNOSTIC_BUFFER * TimerInfo;
		/*0018*/
	} WakeAlarm[0x3];
	/*00b0*/ UCHAR WakeAlarmPaused;
	/*00b8*/ ULONGLONG WakeAlarmLastTime;
	/*00c0*/ ULONGLONG DozeDeferralStartTime;
	/*00c8*/ SYSTEM_POWER_CAPABILITIES FilteredCapabilities;
	/*0118*/
};

struct _POP_POWER_SETTING_VALUES {
	/*0000*/ ULONG StructureSize;
	/*0004*/ _SYSTEM_POWER_POLICY PopPolicy;
	/*00ec*/ SYSTEM_POWER_CONDITION CurrentAcDcPowerState;
	/*00f0*/ UCHAR AwayModeEnabled;
	/*00f1*/ UCHAR AwayModeEngaged;
	/*00f2*/ UCHAR AwayModePolicyAllowed;
	/*00f4*/ LONG volatile AwayModeIgnoreUserPresent;
	/*00f8*/ LONG volatile AwayModeIgnoreAction;
	/*00fc*/ UCHAR DisableFastS4;
	/*00fd*/ UCHAR DisableStandbyStates;
	/*0100*/ ULONG UnattendSleepTimeout;
	/*0104*/ ULONG volatile DiskIgnoreTime;
	/*0108*/ ULONG volatile DeviceIdlePolicy;
	/*010c*/ ULONG VideoDimTimeout;
	/*0110*/ ULONG VideoNormalBrightness;
	/*0114*/ ULONG VideoDimBrightness;
	/*0118*/ ULONG AlsOffset;
	/*011c*/ ULONG AlsEnabled;
	/*0120*/ ULONG EsBrightness;
	/*0124*/ UCHAR SwitchShutdownForced;
	/*0128*/ ULONG SystemCoolingPolicy;
	/*012c*/ UCHAR MediaBufferingEngaged;
	/*012d*/ UCHAR AudioActivity;
	/*012e*/ UCHAR FullscreenVideoPlayback;
	/*0130*/ ULONG EsBatteryThreshold;
	/*0134*/ UCHAR EsAggressive;
	/*0135*/ UCHAR EsUserAwaySetting;
	/*0138*/ ULONG ConnectivityInStandby;
	/*013c*/ ULONG DisconnectedStandbyMode;
	/*0140*/ ULONG UserPresencePredictionEnabled;
	/*0144*/
};

struct _POP_PPM_PROFILE {
	/*0000*/ WCHAR * Name;
	/*0008*/ UCHAR Id;
	/*000c*/ _GUID Guid;
	/*001c*/ ULONG Flags;
	/*0020*/ UCHAR Priority;
	/*0028*/ _PPM_ENGINE_SETTINGS Settings[0x2];
	/*1528*/ ULONGLONG StartTime;
	/*1530*/ ULONGLONG Count;
	/*1538*/ ULONGLONG MaxDuration;
	/*1540*/ ULONGLONG MinDuration;
	/*1548*/ ULONGLONG TotalDuration;
	/*1550*/
};

struct _POP_RW_LOCK {
	/*0000*/ _EX_PUSH_LOCK Lock;
	/*0008*/ _KTHREAD * Thread;
	/*0010*/
};

struct _POP_SHUTDOWN_BUG_CHECK {
	/*0000*/ _ETHREAD * InitiatingThread;
	/*0008*/ _EPROCESS * InitiatingProcess;
	/*0010*/ void * ThreadId;
	/*0018*/ void * ProcessId;
	/*0020*/ ULONG Code;
	/*0028*/ ULONGLONG Parameter1;
	/*0030*/ ULONGLONG Parameter2;
	/*0038*/ ULONGLONG Parameter3;
	/*0040*/ ULONGLONG Parameter4;
	/*0048*/
};

enum _POP_SLEEP_CHECKPOINT {
	PopSleepCheckpointInvalid = 0x0,
	PopSleepCheckpointPowerTransitionStart = 0x1,
	PopSleepCheckpointSuspendAppsBefore = 0x2,
	PopSleepCheckpointSuspendAppsAfter = 0x3,
	PopSleepCheckpointSuspendServicesBefore = 0x4,
	PopSleepCheckpointSuspendServicesAfter = 0x5,
	PopSleepCheckpointNotifySuperfetchBefore = 0x6,
	PopSleepCheckpointNotifySuperfetchAfter = 0x7,
	PopSleepCheckpointNotifyCallbacksBefore = 0x8,
	PopSleepCheckpointNotifyCallbacksAfter = 0x9,
	PopSleepCheckpointSleepTransactionCommitted = 0xa,
	PopSleepCheckpointQueryDriversBefore = 0xb,
	PopSleepCheckpointQueryDriversAfter = 0xc,
	PopSleepCheckpointAllocatingHiberContext = 0xd,
	PopSleepCheckpointSuspendDriversBefore = 0xe,
	PopSleepCheckpointPreSleepNotification = 0x10,
	PopSleepCheckpointInterruptsDisabledBegin = 0x11,
	PopSleepCheckpointInvokeHandlerBefore = 0x12,
	PopSleepCheckpointSaveHiberContextBegin = 0x13,
	PopSleepCheckpointInitializeDumpStackFailed = 0x14,
	PopSleepCheckpointHiberWriteFailed = 0x15,
	PopSleepCheckpointHiberFileTooSmall = 0x16,
	PopSleepCheckpointSaveHiberContextFailed = 0x17,
	PopSleepCheckpointSaveHiberContextEnd = 0x18,
	PopSleepCheckpointHiberKernelHandoff = 0x19,
	PopSleepCheckpointInvokeHandlerAfter = 0x1a,
	PopSleepCheckpointReadHiberfileBefore = 0x1b,
	PopSleepCheckpointInitializeDumpStackForReadFailed = 0x1c,
	PopSleepCheckpointHiberReadFailed = 0x1d,
	PopSleepCheckpointChecksumFailure = 0x1e,
	PopSleepCheckpointDecompressionFailed = 0x1f,
	PopSleepCheckpointReadHiberfileAfter = 0x20,
	PopSleepCheckpointInterruptsDisabledEnd = 0x21,
	PopSleepCheckpointWakeDriversAfter = 0x24,
	PopSleepCheckpointResumeAppsBefore = 0x25,
	PopSleepCheckpointResumeAppsAfter = 0x26,
	PopSleepCheckpointResumeServicesBefore = 0x27,
	PopSleepCheckpointResumeServicesAfter = 0x28,
	PopSleepCheckpointPowerTransitionEnd = 0x29,
	PopSleepCheckpointMax = 0x2a
};

enum _POP_SLEEP_CHECKPOINT_STATUS {
	PopSleepCheckpointStatusDisabled = 0x0,
	PopSleepCheckpointStatusEnabledDueToDirtyShutdown = 0x1,
	PopSleepCheckpointStatusEnabledManually = 0x4,
	PopSleepCheckpointStatusEnabledMax = 0x7,
	PopSleepCheckpointStatusFailedNotEfiSystem = 0x8,
	PopSleepCheckpointStatusFailedInsufficientSpace = 0x9,
	PopSleepCheckpointStatusFailedOtherError = 0xf,
	PopSleepCheckpointStatusMax = 0xf
};

struct _POP_THERMAL_TELEMETRY_TRACKER {
	/*0000*/ UCHAR AccountingDisabled;
	/*0008*/ ULONGLONG LastPassiveUpdateTime;
	/*0010*/ ULONGLONG TotalPassiveTime[0x15];
	/*00b8*/ ULONGLONG PassiveTimeSnap[0x15];
	/*0160*/
};

struct _POP_THERMAL_ZONE {
	/*0000*/ _POP_POLICY_DEVICE PolicyDevice;
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ POWER_POLICY_DEVICE_TYPE DeviceType;
	/*0018*/ void * Notification;
	/*0020*/ _UNICODE_STRING Name;
	/*0030*/ _DEVICE_OBJECT * Device;
	/*0038*/ _IRP * Irp;
	/*0040*/ UCHAR State;
	/*0041*/ UCHAR Flags;
	/*0042*/ UCHAR Removing;
	/*0043*/ UCHAR Mode;
	/*0044*/ UCHAR PendingMode;
	/*0045*/ UCHAR ActivePoint;
	/*0046*/ UCHAR PendingActivePoint;
	/*0047*/ UCHAR Critical;
	/*0048*/ UCHAR ThermalStandby;
	/*0049*/ UCHAR OverThrottled;
	/*004c*/ LONG HighPrecisionThrottle;
	/*0050*/ LONG Throttle;
	/*0054*/ LONG PendingThrottle;
	/*0058*/ ULONG ThrottleReasons;
	/*0060*/ ULONGLONG LastPassiveTime;
	/*0068*/ ULONG SampleRate;
	/*006c*/ ULONG LastTemp;
	/*0070*/ _THERMAL_INFORMATION_EX Info;
	/*00cc*/ _THERMAL_POLICY Policy;
	/*00e4*/ UCHAR PolicyDriver;
	/*00e8*/ ULONG PollingRate;
	/*00f0*/ ULONGLONG LastTemperatureTime;
	/*00f8*/ ULONGLONG LastActiveStartTime;
	/*0100*/ ULONGLONG LastPassiveStartTime;
	/*0108*/ _WORK_QUEUE_ITEM WorkItem;
	/*0128*/ _KTIMER2 ZoneUpdateTimer;
	/*01b0*/ _POP_RW_LOCK Lock;
	/*01c0*/ _KEVENT ZoneStopped;
	/*01d8*/ _KEVENT TemperatureUpdated;
	/*01f0*/ ULONG InstanceId;
	/*01f8*/ _POP_THERMAL_TELEMETRY_TRACKER TelemetryTracker;
	/*0358*/ _UNICODE_STRING Description;
	/*0368*/
};

struct _POP_TRIGGER_WAIT {
	/*0000*/ _KEVENT Event;
	/*0018*/ LONG Status;
	/*0020*/ _LIST_ENTRY Link;
	/*0030*/ _POP_ACTION_TRIGGER * Trigger;
	/*0038*/
};

struct _PORT_MESSAGE {
	union {
		struct {
			/*0000*/ SHORT DataLength;
			/*0002*/ SHORT TotalLength;
			/*0004*/
		} s1;
		/*0000*/ ULONG Length;
		/*0004*/
	} u1;
	union {
		struct {
			/*0004*/ SHORT Type;
			/*0006*/ SHORT DataInfoOffset;
			/*0008*/
		} s2;
		/*0004*/ ULONG ZeroInit;
		/*0008*/
	} u2;
	/*0008*/ _CLIENT_ID ClientId;
	/*0008*/ double DoNotUseThisField;
	/*0018*/ ULONG MessageId;
	/*0020*/ ULONGLONG ClientViewSize;
	/*0020*/ ULONG CallbackId;
	/*0028*/
};

struct _PORT_MESSAGE32 {
	union {
		struct {
			/*0000*/ SHORT DataLength;
			/*0002*/ SHORT TotalLength;
			/*0004*/
		} s1;
		/*0000*/ ULONG Length;
		/*0004*/
	} u1;
	union {
		struct {
			/*0004*/ SHORT Type;
			/*0006*/ SHORT DataInfoOffset;
			/*0008*/
		} s2;
		/*0004*/ ULONG ZeroInit;
		/*0008*/
	} u2;
	/*0008*/ _CLIENT_ID32 ClientId;
	/*0008*/ double DoNotUseThisField;
	/*0010*/ ULONG MessageId;
	/*0014*/ ULONG ClientViewSize;
	/*0014*/ ULONG CallbackId;
	/*0018*/
};

enum _POWER_INFORMATION_LEVEL_INTERNAL {
	PowerInternalAcpiInterfaceRegister = 0x0,
	PowerInternalS0LowPowerIdleInfo = 0x1,
	PowerInternalReapplyBrightnessSettings = 0x2,
	PowerInternalUserAbsencePrediction = 0x3,
	PowerInternalUserAbsencePredictionCapability = 0x4,
	PowerInternalPoProcessorLatencyHint = 0x5,
	PowerInternalStandbyNetworkRequest = 0x6,
	PowerInternalDirtyTransitionInformation = 0x7,
	PowerInternalSetBackgroundTaskState = 0x8,
	PowerInternalTtmOpenTerminal = 0x9,
	PowerInformationInternalTtmFirst = 0x9,
	PowerInternalTtmCreateTerminal = 0xa,
	PowerInternalTtmEvacuateDevices = 0xb,
	PowerInternalTtmCreateTerminalEventQueue = 0xc,
	PowerInternalTtmGetTerminalEvent = 0xd,
	PowerInternalTtmSetDefaultDeviceAssignment = 0xe,
	PowerInternalTtmAssignDevice = 0xf,
	PowerInternalTtmSetDisplayState = 0x10,
	PowerInternalTtmSetDisplayTimeouts = 0x11,
	PowerInformationInternalTtmLast = 0x11,
	PowerInternalBootSessionStandbyActivationInformation = 0x12,
	PowerInternalSessionPowerState = 0x13,
	PowerInternalSessionTerminalInput = 0x14,
	PowerInternalSetWatchdog = 0x15,
	PowerInternalPhysicalPowerButtonPressInfoAtBoot = 0x16,
	PowerInternalExternalMonitorConnected = 0x17,
	PowerInternalHighPrecisionBrightnessSettings = 0x18,
	PowerInternalWinrtScreenToggle = 0x19,
	PowerInternalPpmQosDisable = 0x1a,
	PowerInternalTransitionCheckpoint = 0x1b,
	PowerInternalInputControllerState = 0x1c,
	PowerInternalFirmwareResetReason = 0x1d,
	PowerInternalPpmSchedulerQosSupport = 0x1e,
	PowerInternalBootStatGet = 0x1f,
	PowerInternalBootStatSet = 0x20,
	PowerInternalCallHasNotReturnedWatchdog = 0x21,
	PowerInternalBootStatCheckIntegrity = 0x22,
	PowerInternalBootStatRestoreDefaults = 0x23,
	PowerInternalHostEsStateUpdate = 0x24,
	PowerInternalGetPowerActionState = 0x25,
	PowerInternalBootStatUnlock = 0x26,
	PowerInternalWakeOnVoiceState = 0x27,
	PowerInternalDeepSleepBlock = 0x28,
	PowerInformationInternalMaximum = 0x29
};

enum _POWER_REQUEST_TYPE {
	PowerRequestDisplayRequired = 0x0,
	PowerRequestSystemRequired = 0x1,
	PowerRequestAwayModeRequired = 0x2,
	PowerRequestExecutionRequired = 0x3
};

enum _POWER_REQUEST_TYPE_INTERNAL {
	PowerRequestDisplayRequiredInternal = 0x0,
	PowerRequestSystemRequiredInternal = 0x1,
	PowerRequestAwayModeRequiredInternal = 0x2,
	PowerRequestExecutionRequiredInternal = 0x3,
	PowerRequestPerfBoostRequiredInternal = 0x4,
	PowerRequestActiveLockScreenInternal = 0x5,
	PowerRequestInternalInvalid = 0x6
};

struct _POWER_SEQUENCE {
	/*0000*/ ULONG SequenceD1;
	/*0004*/ ULONG SequenceD2;
	/*0008*/ ULONG SequenceD3;
	/*000c*/
};

union _POWER_STATE {
	/*0000*/ _SYSTEM_POWER_STATE SystemState;
	/*0000*/ _DEVICE_POWER_STATE DeviceState;
	/*0004*/
};

enum _POWER_STATE_TYPE {
	SystemPowerState = 0x0,
	DevicePowerState = 0x1
};

enum _PO_CS_DEVICE_NOTIFICATION_TYPE {
	PoCsDeviceNotificationStorage = 0x0,
	PoCsDeviceNotificationWiFi = 0x1,
	PoCsDeviceNotificationMbn = 0x2,
	PoCsDeviceNotificationAudio = 0x3,
	PoCsDeviceNotificationEthernet = 0x4,
	PoCsDeviceNotificationMaximum = 0x5
};

struct _PO_DEVICE_NOTIFY {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ _LIST_ENTRY PowerChildren;
	/*0020*/ _LIST_ENTRY PowerParents;
	/*0030*/ _DEVICE_OBJECT * TargetDevice;
	/*0038*/ UCHAR OrderLevel;
	/*0040*/ _DEVICE_OBJECT * DeviceObject;
	/*0048*/ WCHAR * DeviceName;
	/*0050*/ WCHAR * DriverName;
	/*0058*/ ULONG ChildCount;
	/*005c*/ ULONG ActiveChild;
	/*0060*/ ULONG ParentCount;
	/*0064*/ ULONG ActiveParent;
	/*0068*/
};

struct _PO_DEVICE_NOTIFY_ORDER {
	/*0000*/ UCHAR Locked;
	/*0008*/ _DEVICE_OBJECT * * WarmEjectPdoPointer;
	/*0010*/ _PO_NOTIFY_ORDER_LEVEL OrderLevel[0x5];
	/*0178*/
};

struct _PO_DIAG_STACK_RECORD {
	/*0000*/ ULONG StackDepth;
	/*0008*/ void * Stack[0x1];
	/*0010*/
};

struct _PO_FX_COMPONENT_PERF_SET {
	/*0000*/ _UNICODE_STRING Name;
	/*0010*/ ULONGLONG Flags;
	/*0018*/ _PO_FX_PERF_STATE_UNIT Unit;
	/*001c*/ _PO_FX_PERF_STATE_TYPE Type;
	struct {
		/*0020*/ ULONG Count;
		/*0028*/ _PO_FX_PERF_STATE * States;
		/*0030*/
	} Discrete;
	struct {
		/*0020*/ ULONGLONG Minimum;
		/*0028*/ ULONGLONG Maximum;
		/*0030*/
	} Range;
	/*0030*/
};

struct _PO_FX_PERF_STATE {
	/*0000*/ ULONGLONG Value;
	/*0008*/ void * Context;
	/*0010*/
};

struct _PO_FX_PERF_STATE_CHANGE {
	/*0000*/ ULONG Set;
	/*0008*/ ULONG StateIndex;
	/*0008*/ ULONGLONG StateValue;
	/*0010*/
};

enum _PO_FX_PERF_STATE_TYPE {
	PoFxPerfStateTypeDiscrete = 0x0,
	PoFxPerfStateTypeRange = 0x1,
	PoFxPerfStateTypeMaximum = 0x2
};

enum _PO_FX_PERF_STATE_UNIT {
	PoFxPerfStateUnitOther = 0x0,
	PoFxPerfStateUnitFrequency = 0x1,
	PoFxPerfStateUnitBandwidth = 0x2,
	PoFxPerfStateUnitMaximum = 0x3
};

enum _PO_HIBER_FORCE_DISABLE_REASON {
	PoHiberForceDisableReasonPolicy = 0x0,
	PoHiberForceDisableReasonGuardedHost = 0x1,
	PoHiberForceDisableReasonMax = 0x2
};

struct _PO_HIBER_PERF {
	/*0000*/ ULONGLONG HiberIoTicks;
	/*0008*/ ULONGLONG HiberIoCpuTicks;
	/*0010*/ ULONGLONG HiberInitTicks;
	/*0018*/ ULONGLONG HiberHiberFileTicks;
	/*0020*/ ULONGLONG HiberCompressTicks;
	/*0028*/ ULONGLONG HiberSharedBufferTicks;
	/*0030*/ ULONGLONG HiberChecksumTicks;
	/*0038*/ ULONGLONG HiberChecksumIoTicks;
	/*0040*/ _LARGE_INTEGER TotalHibernateTime;
	/*0048*/ _LARGE_INTEGER HibernateCompleteTimestamp;
	/*0050*/ ULONG POSTTime;
	/*0054*/ ULONG ResumeBootMgrTime;
	/*0058*/ ULONG BootmgrUserInputTime;
	/*0060*/ ULONGLONG ResumeAppTicks;
	/*0068*/ ULONGLONG ResumeAppStartTimestamp;
	/*0070*/ ULONGLONG ResumeLibraryInitTicks;
	/*0078*/ ULONGLONG ResumeInitTicks;
	/*0080*/ ULONGLONG ResumeRestoreImageStartTimestamp;
	/*0088*/ ULONGLONG ResumeHiberFileTicks;
	/*0090*/ ULONGLONG ResumeIoTicks;
	/*0098*/ ULONGLONG ResumeDecompressTicks;
	/*00a0*/ ULONGLONG ResumeAllocateTicks;
	/*00a8*/ ULONGLONG ResumeUserInOutTicks;
	/*00b0*/ ULONGLONG ResumeMapTicks;
	/*00b8*/ ULONGLONG ResumeUnmapTicks;
	/*00c0*/ ULONGLONG ResumeChecksumTicks;
	/*00c8*/ ULONGLONG ResumeChecksumIoTicks;
	/*00d0*/ ULONGLONG ResumeKernelSwitchTimestamp;
	/*00d8*/ ULONGLONG CyclesPerMs;
	/*00e0*/ ULONGLONG WriteLogDataTimestamp;
	/*00e8*/ ULONGLONG KernelReturnFromHandler;
	/*00f0*/ ULONGLONG TimeStampCounterAtSwitchTime;
	/*00f8*/ ULONGLONG HalTscOffset;
	/*0100*/ ULONGLONG HvlTscOffset;
	/*0108*/ ULONGLONG SleeperThreadEnd;
	/*0110*/ ULONGLONG PostCmosUpdateTimestamp;
	/*0118*/ ULONGLONG KernelReturnSystemPowerStateTimestamp;
	/*0120*/ ULONGLONG IoBoundedness;
	/*0128*/ ULONGLONG KernelDecompressTicks;
	/*0130*/ ULONGLONG KernelIoTicks;
	/*0138*/ ULONGLONG KernelCopyTicks;
	/*0140*/ ULONGLONG ReadCheckCount;
	/*0148*/ ULONGLONG KernelInitTicks;
	/*0150*/ ULONGLONG KernelResumeHiberFileTicks;
	/*0158*/ ULONGLONG KernelIoCpuTicks;
	/*0160*/ ULONGLONG KernelSharedBufferTicks;
	/*0168*/ ULONGLONG KernelAnimationTicks;
	/*0170*/ ULONGLONG KernelChecksumTicks;
	/*0178*/ ULONGLONG KernelChecksumIoTicks;
	/*0180*/ _LARGE_INTEGER AnimationStart;
	/*0188*/ _LARGE_INTEGER AnimationStop;
	/*0190*/ ULONG DeviceResumeTime;
	/*0198*/ ULONGLONG SecurePagesProcessed;
	/*01a0*/ ULONGLONG BootPagesProcessed;
	/*01a8*/ ULONGLONG KernelPagesProcessed;
	/*01b0*/ ULONGLONG BootBytesWritten;
	/*01b8*/ ULONGLONG KernelBytesWritten;
	/*01c0*/ ULONGLONG BootPagesWritten;
	/*01c8*/ ULONGLONG KernelPagesWritten;
	/*01d0*/ ULONGLONG BytesWritten;
	/*01d8*/ ULONG PagesWritten;
	/*01dc*/ ULONG FileRuns;
	/*01e0*/ ULONG NoMultiStageResumeReason;
	/*01e4*/ ULONG MaxHuffRatio;
	/*01e8*/ ULONGLONG AdjustedTotalResumeTime;
	/*01f0*/ ULONGLONG ResumeCompleteTimestamp;
	/*01f8*/
};

struct _PO_IRP_MANAGER {
	/*0000*/ _PO_IRP_QUEUE DeviceIrpQueue;
	/*0010*/ _PO_IRP_QUEUE SystemIrpQueue;
	/*0020*/
};

struct _PO_IRP_QUEUE {
	/*0000*/ _IRP * CurrentIrp;
	/*0008*/ _IRP * PendingIrpList;
	/*0010*/
};

enum _PO_MODERN_SLEEP_ACTION {
	PoModernSleepActionGlobalActivatorsVeto = 0x0,
	PoModernSleepActionNonBlockingPhases = 0x1,
	PoModernSleepActionForceIdle = 0x2,
	PoModernSleepActionMinimalBlockingNotificationClients = 0x3,
	PoModernSleepActionMax = 0x4
};

struct _PO_NOTIFY_ORDER_LEVEL {
	/*0000*/ ULONG DeviceCount;
	/*0004*/ ULONG ActiveCount;
	/*0008*/ _LIST_ENTRY WaitSleep;
	/*0018*/ _LIST_ENTRY ReadySleep;
	/*0028*/ _LIST_ENTRY ReadyS0;
	/*0038*/ _LIST_ENTRY WaitS0;
	/*0048*/
};

struct _PO_PROCESS_ENERGY_CONTEXT;

struct _PPC_DBGKD_CONTROL_SET {
	/*0000*/ ULONG Continue;
	/*0004*/ ULONG CurrentSymbolStart;
	/*0008*/ ULONG CurrentSymbolEnd;
	/*000c*/
};

struct _PPM_CONCURRENCY_ACCOUNTING {
	/*0000*/ ULONGLONG Lock;
	/*0008*/ ULONG Processors;
	/*000c*/ ULONG ActiveProcessors;
	/*0010*/ ULONGLONG LastUpdateTime;
	/*0018*/ ULONGLONG TotalTime;
	/*0020*/ ULONGLONG AccumulatedTime[0x1];
	/*0028*/
};

struct _PPM_COORDINATED_SELECTION {
	/*0000*/ ULONG MaximumStates;
	/*0004*/ ULONG SelectedStates;
	/*0008*/ ULONG DefaultSelection;
	/*0010*/ ULONG * Selection;
	/*0018*/
};

union _PPM_COORDINATED_SYNCHRONIZATION {
	/*0000*/ LONG AsLong;
	/*0000*/ ULONG EnterProcessor : 12; // 0x00000fff;
	/*0000*/ ULONG ExitProcessor : 12; // 0x00fff000;
	/*0000*/ ULONG Transition : 02; // 0x03000000;
	/*0000*/ ULONG Entered : 01; // 0x04000000;
	/*0000*/ ULONG EntryPriority : 05; // 0xf8000000;
	/*0004*/
};

struct _PPM_ENGINE_SETTINGS {
	/*0000*/ _PPM_POLICY_SETTINGS_MASK ExplicitSetting[0x2];
	/*0010*/ UCHAR ThrottlingPolicy;
	/*0014*/ ULONG PerfTimeCheck;
	/*0018*/ UCHAR PerfHistoryCount[0x2];
	/*001a*/ UCHAR PerfMinPolicy[0x2];
	/*001c*/ UCHAR PerfMaxPolicy[0x2];
	/*001e*/ UCHAR PerfDecreaseTime[0x2];
	/*0020*/ UCHAR PerfIncreaseTime[0x2];
	/*0022*/ UCHAR PerfDecreasePolicy[0x2];
	/*0024*/ UCHAR PerfIncreasePolicy[0x2];
	/*0026*/ UCHAR PerfDecreaseThreshold[0x2];
	/*0028*/ UCHAR PerfIncreaseThreshold[0x2];
	/*002c*/ ULONG PerfFrequencyCap[0x2];
	/*0034*/ ULONG PerfBoostPolicy;
	/*0038*/ ULONG PerfBoostMode;
	/*003c*/ ULONG PerfReductionTolerance;
	/*0040*/ ULONG EnergyPerfPreference;
	/*0044*/ ULONG AutonomousActivityWindow;
	/*0048*/ UCHAR AutonomousPreference;
	/*0049*/ UCHAR LatencyHintPerf[0x2];
	/*004b*/ UCHAR LatencyHintUnpark[0x2];
	/*004d*/ UCHAR DutyCycling;
	/*004e*/ UCHAR ParkingPerfState[0x2];
	/*0050*/ UCHAR DistributeUtility;
	/*0051*/ UCHAR CoreParkingOverUtilizationThreshold;
	/*0052*/ UCHAR CoreParkingConcurrencyThreshold;
	/*0053*/ UCHAR CoreParkingHeadroomThreshold;
	/*0054*/ UCHAR CoreParkingDistributionThreshold;
	/*0055*/ UCHAR CoreParkingDecreasePolicy;
	/*0056*/ UCHAR CoreParkingIncreasePolicy;
	/*0058*/ ULONG CoreParkingDecreaseTime;
	/*005c*/ ULONG CoreParkingIncreaseTime;
	/*0060*/ UCHAR CoreParkingMinCores[0x2];
	/*0062*/ UCHAR CoreParkingMaxCores[0x2];
	/*0064*/ UCHAR AllowScaling;
	/*0065*/ UCHAR IdleDisabled;
	/*0068*/ ULONG IdleTimeCheck;
	/*006c*/ UCHAR IdleDemotePercent;
	/*006d*/ UCHAR IdlePromotePercent;
	/*006e*/ UCHAR HeteroDecreaseTime;
	/*006f*/ UCHAR HeteroIncreaseTime;
	/*0070*/ UCHAR HeteroDecreaseThreshold[0x500];
	/*0570*/ UCHAR HeteroIncreaseThreshold[0x500];
	/*0a70*/ UCHAR Class0FloorPerformance;
	/*0a71*/ UCHAR Class1InitialPerformance;
	/*0a74*/ _KHETERO_CPU_POLICY ThreadPolicies[0x2];
	/*0a80*/
};

struct _PPM_FFH_THROTTLE_STATE_INFO {
	/*0000*/ UCHAR EnableLogging;
	/*0004*/ ULONG MismatchCount;
	/*0008*/ UCHAR Initialized;
	/*0010*/ ULONGLONG LastValue;
	/*0018*/ _LARGE_INTEGER LastLogTickCount;
	/*0020*/
};

struct _PPM_IDLE_STATE {
	/*0000*/ _KAFFINITY_EX DomainMembers;
	/*00a8*/ _UNICODE_STRING Name;
	/*00b8*/ ULONG Latency;
	/*00bc*/ ULONG BreakEvenDuration;
	/*00c0*/ ULONG Power;
	/*00c4*/ ULONG StateFlags;
	/*00c8*/ _PPM_VETO_ACCOUNTING VetoAccounting;
	/*00f0*/ UCHAR StateType;
	/*00f1*/ UCHAR InterruptsEnabled;
	/*00f2*/ UCHAR Interruptible;
	/*00f3*/ UCHAR ContextRetained;
	/*00f4*/ UCHAR CacheCoherent;
	/*00f5*/ UCHAR WakesSpuriously;
	/*00f6*/ UCHAR PlatformOnly;
	/*00f7*/ UCHAR NoCState;
	/*00f8*/
};

struct _PPM_IDLE_STATES {
	/*0000*/ UCHAR InterfaceVersion;
	/*0001*/ UCHAR IdleOverride;
	/*0002*/ UCHAR EstimateIdleDuration;
	/*0003*/ UCHAR ExitLatencyTraceEnabled;
	/*0004*/ UCHAR NonInterruptibleTransition;
	/*0005*/ UCHAR UnaccountedTransition;
	/*0006*/ UCHAR IdleDurationLimited;
	/*0007*/ UCHAR IdleCheckLimited;
	/*0008*/ ULONG ExitLatencyCountdown;
	/*000c*/ ULONG TargetState;
	/*0010*/ ULONG ActualState;
	/*0014*/ ULONG OldState;
	/*0018*/ ULONG OverrideIndex;
	/*001c*/ ULONG ProcessorIdleCount;
	/*0020*/ ULONG Type;
	/*0028*/ ULONGLONG LevelId;
	/*0030*/ USHORT ReasonFlags;
	/*0038*/ ULONGLONG volatile InitiateWakeStamp;
	/*0040*/ LONG PreviousStatus;
	/*0044*/ ULONG PreviousCancelReason;
	/*0048*/ _KAFFINITY_EX PrimaryProcessorMask;
	/*00f0*/ _KAFFINITY_EX SecondaryProcessorMask;
	/*0198*/ void (* IdlePrepare)( _PROCESSOR_IDLE_PREPARE_INFO * );
	/*01a0*/ LONG (* IdlePreExecute)( void * , ULONG , ULONG , ULONG , ULONG * );
	/*01a8*/ LONG (* IdleExecute)( void * , ULONGLONG , ULONG , ULONG , ULONG , ULONG * );
	/*01b0*/ ULONG (* IdlePreselect)( void * , _PROCESSOR_IDLE_CONSTRAINTS * );
	/*01b8*/ ULONG (* IdleTest)( void * , ULONG , ULONG );
	/*01c0*/ ULONG (* IdleAvailabilityCheck)( void * , ULONG );
	/*01c8*/ void (* IdleComplete)( void * , ULONG , ULONG , ULONG , ULONG * );
	/*01d0*/ void (* IdleCancel)( void * , ULONG );
	/*01d8*/ UCHAR (* IdleIsHalted)( void * );
	/*01e0*/ UCHAR (* IdleInitiateWake)( void * );
	/*01e8*/ _PROCESSOR_IDLE_PREPARE_INFO PrepareInfo;
	/*0240*/ _KAFFINITY_EX DeepIdleSnapshot;
	/*02e8*/ _PERFINFO_PPM_STATE_SELECTION * Tracing;
	/*02f0*/ _PERFINFO_PPM_STATE_SELECTION * CoordinatedTracing;
	/*02f8*/ _PPM_SELECTION_MENU ProcessorMenu;
	/*0308*/ _PPM_SELECTION_MENU CoordinatedMenu;
	/*0318*/ _PPM_COORDINATED_SELECTION CoordinatedSelection;
	/*0330*/ _PPM_IDLE_STATE State[0x1];
	/*0428*/
};

union _PPM_IDLE_SYNCHRONIZATION_STATE {
	/*0000*/ LONG AsLong;
	/*0000*/ LONG RefCount : 24; // 0x00ffffff;
	/*0000*/ ULONG State : 08; // 0xff000000;
	/*0004*/
};

enum _PPM_PERF_QOS_DISABLE_REASON {
	PpmPerfQosDisableInternal = 0x0,
	PpmPerfQosDisableNoProfile = 0x1,
	PpmPerfQosDisableNoPolicy = 0x2,
	PpmPerfQosDisableInsufficientPolicy = 0x3,
	PpmPerfQosDisableMaxOverride = 0x4,
	PpmPerfQosDisableLowLatency = 0x5,
	PpmPerfQosDisableSmtScheduler = 0x6,
	PpmPerfQosDisableNoHardwareSupport = 0x7,
	PpmPerfQosDisableGroupPolicy = 0x8,
	PpmPerfQosDisableMax = 0x9
};

struct _PPM_PLATFORM_STATE {
	/*0000*/ ULONGLONG LevelId;
	/*0008*/ ULONG Latency;
	/*000c*/ ULONG BreakEvenDuration;
	/*0010*/ _PPM_VETO_ACCOUNTING VetoAccounting;
	/*0038*/ UCHAR TransitionDebugger;
	/*0039*/ UCHAR Platform;
	/*003c*/ ULONG DependencyListCount;
	/*0040*/ _KAFFINITY_EX Processors;
	/*00e8*/ _UNICODE_STRING Name;
	/*00f8*/ _PPM_SELECTION_DEPENDENCY * DependencyLists;
	/*0100*/ _PPM_COORDINATED_SYNCHRONIZATION volatile Synchronization;
	/*0108*/ ULONGLONG volatile EnterTime;
	/*0140*/ LONG volatile RefCount;
	/*0140*/ UCHAR CacheAlign0[0x40];
	/*0180*/
};

struct _PPM_PLATFORM_STATES {
	/*0000*/ ULONG StateCount;
	/*0004*/ ULONG InterfaceVersion;
	/*0008*/ ULONG ProcessorCount;
	/*000c*/ UCHAR CoordinatedInterface;
	/*0010*/ ULONG (* IdleTest)( void * , ULONG , ULONG );
	/*0018*/ LONG (* IdlePreExecute)( void * , ULONG , ULONG , ULONG , ULONG * );
	/*0020*/ void (* IdleComplete)( void * , ULONG , ULONG , ULONG , ULONG * );
	/*0028*/ LONG (* QueryPlatformStateResidency)( void * , _PROCESSOR_PLATFORM_STATE_RESIDENCIES * );
	/*0030*/ _PLATFORM_IDLE_ACCOUNTING * Accounting;
	/*0040*/ _PPM_PLATFORM_STATE State[0x1];
	/*01c0*/
};

union _PPM_POLICY_SETTINGS_MASK {
	/*0000*/ ULONGLONG Value;
	/*0000*/ ULONG PerfDecreaseTime : 01; // 0x00000001;
	/*0000*/ ULONG PerfIncreaseTime : 01; // 0x00000002;
	/*0000*/ ULONG PerfDecreasePolicy : 01; // 0x00000004;
	/*0000*/ ULONG PerfIncreasePolicy : 01; // 0x00000008;
	/*0000*/ ULONG PerfDecreaseThreshold : 01; // 0x00000010;
	/*0000*/ ULONG PerfIncreaseThreshold : 01; // 0x00000020;
	/*0000*/ ULONG PerfMinPolicy : 01; // 0x00000040;
	/*0000*/ ULONG PerfMaxPolicy : 01; // 0x00000080;
	/*0000*/ ULONG PerfTimeCheck : 01; // 0x00000100;
	/*0000*/ ULONG PerfBoostPolicy : 01; // 0x00000200;
	/*0000*/ ULONG PerfBoostMode : 01; // 0x00000400;
	/*0000*/ ULONG AllowThrottling : 01; // 0x00000800;
	/*0000*/ ULONG PerfHistoryCount : 01; // 0x00001000;
	/*0000*/ ULONG ParkingPerfState : 01; // 0x00002000;
	/*0000*/ ULONG LatencyHintPerf : 01; // 0x00004000;
	/*0000*/ ULONG LatencyHintUnpark : 01; // 0x00008000;
	/*0000*/ ULONG CoreParkingMinCores : 01; // 0x00010000;
	/*0000*/ ULONG CoreParkingMaxCores : 01; // 0x00020000;
	/*0000*/ ULONG CoreParkingDecreasePolicy : 01; // 0x00040000;
	/*0000*/ ULONG CoreParkingIncreasePolicy : 01; // 0x00080000;
	/*0000*/ ULONG CoreParkingDecreaseTime : 01; // 0x00100000;
	/*0000*/ ULONG CoreParkingIncreaseTime : 01; // 0x00200000;
	/*0000*/ ULONG CoreParkingOverUtilizationThreshold : 01; // 0x00400000;
	/*0000*/ ULONG CoreParkingDistributeUtility : 01; // 0x00800000;
	/*0000*/ ULONG CoreParkingConcurrencyThreshold : 01; // 0x01000000;
	/*0000*/ ULONG CoreParkingHeadroomThreshold : 01; // 0x02000000;
	/*0000*/ ULONG CoreParkingDistributionThreshold : 01; // 0x04000000;
	/*0000*/ ULONG IdleAllowScaling : 01; // 0x08000000;
	/*0000*/ ULONG IdleDisable : 01; // 0x10000000;
	/*0000*/ ULONG IdleTimeCheck : 01; // 0x20000000;
	/*0000*/ ULONG IdleDemoteThreshold : 01; // 0x40000000;
	/*0000*/ ULONG IdlePromoteThreshold : 01; // 0x80000000;
	/*0004*/ ULONG HeteroDecreaseTime : 01; // 0x00000001;
	/*0004*/ ULONG HeteroIncreaseTime : 01; // 0x00000002;
	/*0004*/ ULONG HeteroDecreaseThreshold : 01; // 0x00000004;
	/*0004*/ ULONG HeteroIncreaseThreshold : 01; // 0x00000008;
	/*0004*/ ULONG Class0FloorPerformance : 01; // 0x00000010;
	/*0004*/ ULONG Class1InitialPerformance : 01; // 0x00000020;
	/*0004*/ ULONG EnergyPerfPreference : 01; // 0x00000040;
	/*0004*/ ULONG AutonomousActivityWindow : 01; // 0x00000080;
	/*0004*/ ULONG AutonomousMode : 01; // 0x00000100;
	/*0004*/ ULONG DutyCycling : 01; // 0x00000200;
	/*0004*/ ULONG FrequencyCap : 01; // 0x00000400;
	/*0004*/ ULONG ThreadPolicy : 01; // 0x00000800;
	/*0004*/ ULONG ShortThreadPolicy : 01; // 0x00001000;
	/*0004*/ ULONG Spare : 19; // 0xffffe000;
	/*0008*/
};

struct _PPM_SELECTION_DEPENDENCY {
	/*0000*/ ULONG Processor;
	/*0008*/ _PPM_SELECTION_MENU Menu;
	/*0018*/
};

struct _PPM_SELECTION_MENU {
	/*0000*/ ULONG Count;
	/*0008*/ _PPM_SELECTION_MENU_ENTRY * Entries;
	/*0010*/
};

struct _PPM_SELECTION_MENU_ENTRY {
	/*0000*/ UCHAR StrictDependency;
	/*0001*/ UCHAR InitiatingState;
	/*0002*/ UCHAR DependentState;
	/*0004*/ ULONG StateIndex;
	/*0008*/ ULONG Dependencies;
	/*0010*/ _PPM_SELECTION_DEPENDENCY * DependencyList;
	/*0018*/
};

struct _PPM_SELECTION_STATISTICS {
	/*0000*/ ULONGLONG SelectedCount;
	/*0008*/ ULONGLONG VetoCount;
	/*0010*/ ULONGLONG PreVetoCount;
	/*0018*/ ULONGLONG WrongProcessorCount;
	/*0020*/ ULONGLONG LatencyCount;
	/*0028*/ ULONGLONG IdleDurationCount;
	/*0030*/ ULONGLONG DeviceDependencyCount;
	/*0038*/ ULONGLONG ProcessorDependencyCount;
	/*0040*/ ULONGLONG PlatformOnlyCount;
	/*0048*/ ULONGLONG InterruptibleCount;
	/*0050*/ ULONGLONG LegacyOverrideCount;
	/*0058*/ ULONGLONG CstateCheckCount;
	/*0060*/ ULONGLONG NoCStateCount;
	/*0068*/ ULONGLONG CoordinatedDependencyCount;
	/*0070*/ ULONGLONG NotClockOwnerCount;
	/*0078*/ _PPM_VETO_ACCOUNTING * PreVetoAccounting;
	/*0080*/
};

struct _PPM_VETO_ACCOUNTING {
	/*0000*/ LONG volatile VetoPresent;
	/*0008*/ _LIST_ENTRY VetoListHead;
	/*0018*/ UCHAR CsAccountingBlocks;
	/*0019*/ UCHAR BlocksDrips;
	/*001c*/ ULONG PreallocatedVetoCount;
	/*0020*/ _PPM_VETO_ENTRY * PreallocatedVetoList;
	/*0028*/
};

struct _PPM_VETO_ENTRY {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ ULONG VetoReason;
	/*0014*/ ULONG ReferenceCount;
	/*0018*/ ULONGLONG HitCount;
	/*0020*/ ULONGLONG LastActivationTime;
	/*0028*/ ULONGLONG TotalActiveTime;
	/*0030*/ ULONGLONG CsActivationTime;
	/*0038*/ ULONGLONG CsActiveTime;
	/*0040*/
};

struct _PP_LOOKASIDE_LIST {
	/*0000*/ _GENERAL_LOOKASIDE * P;
	/*0008*/ _GENERAL_LOOKASIDE * L;
	/*0010*/
};

enum _PP_NPAGED_LOOKASIDE_NUMBER {
	LookasideSmallIrpList = 0x0,
	LookasideMediumIrpList = 0x1,
	LookasideLargeIrpList = 0x2,
	LookasideMdlList = 0x3,
	LookasideCreateInfoList = 0x4,
	LookasideNameBufferList = 0x5,
	LookasideTwilightList = 0x6,
	LookasideCompletionList = 0x7,
	LookasideScratchBufferList = 0x8,
	LookasideMaximumList = 0x9
};

struct _PRIVATE_CACHE_MAP {
	/*0000*/ SHORT NodeTypeCode;
	/*0000*/ _PRIVATE_CACHE_MAP_FLAGS Flags;
	/*0004*/ ULONG ReadAheadMask;
	/*0008*/ _FILE_OBJECT * FileObject;
	/*0010*/ _LARGE_INTEGER FileOffset1;
	/*0018*/ _LARGE_INTEGER BeyondLastByte1;
	/*0020*/ _LARGE_INTEGER FileOffset2;
	/*0028*/ _LARGE_INTEGER BeyondLastByte2;
	/*0030*/ ULONG SequentialReadCount;
	/*0034*/ ULONG ReadAheadLength;
	/*0038*/ _LARGE_INTEGER ReadAheadOffset;
	/*0040*/ _LARGE_INTEGER ReadAheadBeyondLastByte;
	/*0048*/ ULONGLONG PrevReadAheadBeyondLastByte;
	/*0050*/ ULONGLONG ReadAheadSpinLock;
	/*0058*/ ULONG PipelinedReadAheadRequestSize;
	/*005c*/ ULONG ReadAheadGrowth;
	/*0060*/ _LIST_ENTRY PrivateLinks;
	/*0070*/ void * ReadAheadWorkItem;
	/*0078*/
};

struct _PRIVATE_CACHE_MAP_FLAGS {
	/*0000*/ ULONG DontUse : 16; // 0x0000ffff;
	/*0000*/ ULONG ReadAheadActive : 01; // 0x00010000;
	/*0000*/ ULONG ReadAheadEnabled : 01; // 0x00020000;
	/*0000*/ ULONG PagePriority : 03; // 0x001c0000;
	/*0000*/ ULONG PipelineReadAheads : 01; // 0x00200000;
	/*0000*/ ULONG Available : 10; // 0xffc00000;
	/*0004*/
};

struct _PRIVILEGE_SET {
	/*0000*/ ULONG PrivilegeCount;
	/*0004*/ ULONG Control;
	/*0008*/ _LUID_AND_ATTRIBUTES Privilege[0x1];
	/*0014*/
};

enum _PROCESSOR_CACHE_TYPE {
	CacheUnified = 0x0,
	CacheInstruction = 0x1,
	CacheData = 0x2,
	CacheTrace = 0x3
};

struct _PROCESSOR_IDLE_CONSTRAINTS {
	/*0000*/ ULONGLONG TotalTime;
	/*0008*/ ULONGLONG IdleTime;
	/*0010*/ ULONGLONG ExpectedIdleDuration;
	/*0018*/ ULONGLONG MaxIdleDuration;
	/*0020*/ ULONG OverrideState;
	/*0024*/ ULONG TimeCheck;
	/*0028*/ UCHAR PromotePercent;
	/*0029*/ UCHAR DemotePercent;
	/*002a*/ UCHAR Parked;
	/*002b*/ UCHAR Interruptible;
	/*002c*/ UCHAR PlatformIdle;
	/*002d*/ UCHAR ExpectedWakeReason;
	/*0030*/
};

struct _PROCESSOR_IDLE_DEPENDENCY {
	/*0000*/ ULONG ProcessorIndex;
	/*0004*/ UCHAR ExpectedState;
	/*0005*/ UCHAR AllowDeeperStates;
	/*0006*/ UCHAR LooseDependency;
	/*0008*/
};

struct _PROCESSOR_IDLE_PREPARE_INFO {
	/*0000*/ void * Context;
	/*0008*/ _PROCESSOR_IDLE_CONSTRAINTS Constraints;
	/*0038*/ ULONG DependencyCount;
	/*003c*/ ULONG DependencyUsed;
	/*0040*/ _PROCESSOR_IDLE_DEPENDENCY * DependencyArray;
	/*0048*/ ULONG PlatformIdleStateIndex;
	/*004c*/ ULONG ProcessorIdleStateIndex;
	/*0050*/ ULONG IdleSelectFailureMask;
	/*0058*/
};

struct _PROCESSOR_NUMBER {
	/*0000*/ USHORT Group;
	/*0002*/ UCHAR Number;
	/*0003*/ UCHAR Reserved;
	/*0004*/
};

struct _PROCESSOR_PLATFORM_STATE_RESIDENCIES {
	/*0000*/ ULONG Count;
	/*0008*/ _PROCESSOR_PLATFORM_STATE_RESIDENCY States[0x1];
	/*0018*/
};

struct _PROCESSOR_PLATFORM_STATE_RESIDENCY {
	/*0000*/ ULONGLONG Residency;
	/*0008*/ ULONGLONG TransitionCount;
	/*0010*/
};

struct _PROCESSOR_POWER_STATE {
	/*0000*/ _PPM_IDLE_STATES * IdleStates;
	/*0008*/ _PROC_IDLE_ACCOUNTING * IdleAccounting;
	/*0010*/ ULONGLONG IdleTimeLast;
	/*0018*/ ULONGLONG IdleTimeTotal;
	/*0020*/ ULONGLONG volatile IdleTimeEntry;
	/*0028*/ ULONGLONG IdleTimeExpiration;
	/*0030*/ UCHAR NonInterruptibleTransition;
	/*0031*/ UCHAR PepWokenTransition;
	/*0032*/ UCHAR EfficiencyClass;
	/*0033*/ UCHAR SchedulingClass;
	/*0034*/ ULONG TargetIdleState;
	/*0038*/ _PROC_IDLE_POLICY IdlePolicy;
	/*0040*/ _PPM_IDLE_SYNCHRONIZATION_STATE volatile Synchronization;
	/*0048*/ _PROC_FEEDBACK PerfFeedback;
	/*00d8*/ _PROC_HYPERVISOR_STATE Hypervisor;
	/*00dc*/ ULONG LastSysTime;
	/*00e0*/ ULONGLONG WmiDispatchPtr;
	/*00e8*/ LONG WmiInterfaceEnabled;
	/*00f0*/ _PPM_FFH_THROTTLE_STATE_INFO FFHThrottleStateInfo;
	/*0110*/ _KDPC PerfActionDpc;
	/*0150*/ LONG volatile PerfActionMask;
	/*0158*/ _PROC_IDLE_SNAP HvIdleCheck;
	/*0168*/ _PROC_PERF_CHECK * PerfCheck;
	/*0170*/ _PROC_PERF_DOMAIN * Domain;
	/*0178*/ _PROC_PERF_CONSTRAINT * PerfConstraint;
	/*0180*/ _PPM_CONCURRENCY_ACCOUNTING * Concurrency;
	/*0188*/ _PPM_CONCURRENCY_ACCOUNTING * ClassConcurrency;
	/*0190*/ _PROC_PERF_LOAD * Load;
	/*0198*/ _PROC_PERF_HISTORY * PerfHistory;
	/*01a0*/ UCHAR GuaranteedPerformancePercent;
	/*01a1*/ UCHAR HvTargetState;
	/*01a2*/ UCHAR Parked;
	/*01a3*/ UCHAR LongPriorQosPeriod;
	/*01a4*/ ULONG LatestPerformancePercent;
	/*01a8*/ ULONG AveragePerformancePercent;
	/*01ac*/ ULONG LatestAffinitizedPercent;
	/*01b0*/ ULONG RelativePerformance;
	/*01b4*/ ULONG Utility;
	/*01b8*/ ULONG AffinitizedUtility;
	/*01c0*/ ULONGLONG SnapTimeLast;
	/*01c0*/ ULONGLONG EnergyConsumed;
	/*01c8*/ ULONGLONG ActiveTime;
	/*01d0*/ ULONGLONG TotalTime;
	/*01d8*/ _POP_FX_DEVICE * FxDevice;
	/*01e0*/ ULONGLONG LastQosTranstionTsc;
	/*01e8*/ ULONGLONG QosTransitionHysteresis;
	/*01f0*/ _KHETERO_CPU_QOS RequestedQosClass;
	/*01f4*/ _KHETERO_CPU_QOS ResolvedQosClass;
	/*01f8*/ ULONG QosEquivalencyMask;
	/*0200*/
};

struct _PROCESSOR_PROFILE_CONTROL_AREA {
	/*0000*/ _PEBS_DS_SAVE_AREA PebsDsSaveArea;
	/*0060*/
};

struct _PROCESS_DISK_COUNTERS {
	/*0000*/ ULONGLONG BytesRead;
	/*0008*/ ULONGLONG BytesWritten;
	/*0010*/ ULONGLONG ReadOperationCount;
	/*0018*/ ULONGLONG WriteOperationCount;
	/*0020*/ ULONGLONG FlushOperationCount;
	/*0028*/
};

struct _PROCESS_ENERGY_VALUES {
	/*0000*/ ULONGLONG Cycles[0x4][0x2];
	/*0040*/ ULONGLONG DiskEnergy;
	/*0048*/ ULONGLONG NetworkTailEnergy;
	/*0050*/ ULONGLONG MBBTailEnergy;
	/*0058*/ ULONGLONG NetworkTxRxBytes;
	/*0060*/ ULONGLONG MBBTxRxBytes;
	/*0068*/ _ENERGY_STATE_DURATION Durations[0x3];
	/*0068*/ _ENERGY_STATE_DURATION ForegroundDuration;
	/*0070*/ _ENERGY_STATE_DURATION DesktopVisibleDuration;
	/*0078*/ _ENERGY_STATE_DURATION PSMForegroundDuration;
	/*0080*/ ULONG CompositionRendered;
	/*0084*/ ULONG CompositionDirtyGenerated;
	/*0088*/ ULONG CompositionDirtyPropagated;
	/*008c*/ ULONG Reserved1;
	/*0090*/ ULONGLONG AttributedCycles[0x4][0x2];
	/*00d0*/ ULONGLONG WorkOnBehalfCycles[0x4][0x2];
	/*0110*/
};

struct _PROCESS_ENERGY_VALUES_EXTENSION {
	/*0000*/ _TIMELINE_BITMAP Timelines[0xe];
	/*0000*/ _TIMELINE_BITMAP CpuTimeline;
	/*0008*/ _TIMELINE_BITMAP DiskTimeline;
	/*0010*/ _TIMELINE_BITMAP NetworkTimeline;
	/*0018*/ _TIMELINE_BITMAP MBBTimeline;
	/*0020*/ _TIMELINE_BITMAP ForegroundTimeline;
	/*0028*/ _TIMELINE_BITMAP DesktopVisibleTimeline;
	/*0030*/ _TIMELINE_BITMAP CompositionRenderedTimeline;
	/*0038*/ _TIMELINE_BITMAP CompositionDirtyGeneratedTimeline;
	/*0040*/ _TIMELINE_BITMAP CompositionDirtyPropagatedTimeline;
	/*0048*/ _TIMELINE_BITMAP InputTimeline;
	/*0050*/ _TIMELINE_BITMAP AudioInTimeline;
	/*0058*/ _TIMELINE_BITMAP AudioOutTimeline;
	/*0060*/ _TIMELINE_BITMAP DisplayRequiredTimeline;
	/*0068*/ _TIMELINE_BITMAP KeyboardInputTimeline;
	/*0070*/ _ENERGY_STATE_DURATION Durations[0x5];
	/*0070*/ _ENERGY_STATE_DURATION InputDuration;
	/*0078*/ _ENERGY_STATE_DURATION AudioInDuration;
	/*0080*/ _ENERGY_STATE_DURATION AudioOutDuration;
	/*0088*/ _ENERGY_STATE_DURATION DisplayRequiredDuration;
	/*0090*/ _ENERGY_STATE_DURATION PSMBackgroundDuration;
	/*0098*/ ULONG KeyboardInput;
	/*009c*/ ULONG MouseInput;
	/*00a0*/
};

struct _PROCESS_EXTENDED_ENERGY_VALUES {
	/*0000*/ _PROCESS_ENERGY_VALUES Base;
	/*0110*/ _PROCESS_ENERGY_VALUES_EXTENSION Extension;
	/*01b0*/
};

enum _PROCESS_SECTION_TYPE {
	ProcessSectionData = 0x0,
	ProcessSectionImage = 0x1,
	ProcessSectionImageNx = 0x2,
	ProcessSectionPagefileBacked = 0x3,
	ProcessSectionMax = 0x4
};

enum _PROCESS_TERMINATE_REQUEST_REASON {
	ProcessTerminateRequestReasonNone = 0x0,
	ProcessTerminateCommitFail = 0x1,
	ProcessTerminateWriteToExecuteMemory = 0x2,
	ProcessTerminateAttachedWriteToExecuteMemory = 0x3,
	ProcessTerminateRequestReasonMax = 0x4
};

enum _PROCESS_VA_TYPE {
	ProcessVAImage = 0x0,
	ProcessVASection = 0x1,
	ProcessVAPrivate = 0x2,
	ProcessVAMax = 0x3
};

struct _PROC_FEEDBACK {
	/*0000*/ ULONGLONG Lock;
	/*0008*/ ULONGLONG CyclesLast;
	/*0010*/ ULONGLONG CyclesActive;
	/*0018*/ _PROC_FEEDBACK_COUNTER * Counters[0x2];
	/*0028*/ ULONGLONG LastUpdateTime;
	/*0030*/ ULONGLONG UnscaledTime;
	/*0038*/ LONGLONG volatile UnaccountedTime;
	/*0040*/ ULONGLONG ScaledTime[0x2];
	/*0050*/ ULONGLONG UnaccountedKernelTime;
	/*0058*/ ULONGLONG PerformanceScaledKernelTime;
	/*0060*/ ULONG UserTimeLast;
	/*0064*/ ULONG KernelTimeLast;
	/*0068*/ ULONGLONG IdleGenerationNumberLast;
	/*0070*/ ULONGLONG HvActiveTimeLast;
	/*0078*/ ULONGLONG StallCyclesLast;
	/*0080*/ ULONGLONG StallTime;
	/*0088*/ UCHAR KernelTimesIndex;
	/*0089*/ UCHAR CounterDiscardsIdleTime;
	/*0090*/
};

struct _PROC_FEEDBACK_COUNTER {
	/*0000*/ void (* InstantaneousRead)( ULONGLONG , ULONG * );
	/*0000*/ void (* DifferentialRead)( ULONGLONG , UCHAR , ULONGLONG * , ULONGLONG * );
	/*0008*/ ULONGLONG LastActualCount;
	/*0010*/ ULONGLONG LastReferenceCount;
	/*0018*/ ULONG CachedValue;
	/*0020*/ UCHAR Affinitized;
	/*0021*/ UCHAR Differential;
	/*0022*/ UCHAR DiscardIdleTime;
	/*0023*/ UCHAR Scaling;
	/*0028*/ ULONGLONG Context;
	/*0030*/
};

enum _PROC_HYPERVISOR_STATE {
	ProcHypervisorNone = 0x0,
	ProcHypervisorPresent = 0x1,
	ProcHypervisorPower = 0x2,
	ProcHypervisorHvCounters = 0x3
};

struct _PROC_IDLE_ACCOUNTING {
	/*0000*/ ULONG StateCount;
	/*0004*/ ULONG TotalTransitions;
	/*0008*/ ULONG ResetCount;
	/*000c*/ ULONG AbortCount;
	/*0010*/ ULONGLONG StartTime;
	/*0018*/ ULONGLONG PriorIdleTime;
	/*0020*/ PPM_IDLE_BUCKET_TIME_TYPE TimeUnit;
	/*0028*/ _PROC_IDLE_STATE_ACCOUNTING State[0x1];
	/*0410*/
};

struct _PROC_IDLE_POLICY {
	/*0000*/ UCHAR PromotePercent;
	/*0001*/ UCHAR DemotePercent;
	/*0002*/ UCHAR PromotePercentBase;
	/*0003*/ UCHAR DemotePercentBase;
	/*0004*/ UCHAR AllowScaling;
	/*0005*/ UCHAR ForceLightIdle;
	/*0006*/
};

struct _PROC_IDLE_SNAP {
	/*0000*/ ULONGLONG Time;
	/*0008*/ ULONGLONG Idle;
	/*0010*/
};

struct _PROC_IDLE_STATE_ACCOUNTING {
	/*0000*/ ULONGLONG TotalTime;
	/*0008*/ ULONG CancelCount;
	/*000c*/ ULONG FailureCount;
	/*0010*/ ULONG SuccessCount;
	/*0014*/ ULONG InvalidBucketIndex;
	/*0018*/ ULONGLONG MinTime;
	/*0020*/ ULONGLONG MaxTime;
	/*0028*/ _PPM_SELECTION_STATISTICS SelectionStatistics;
	/*00a8*/ _PROC_IDLE_STATE_BUCKET IdleTimeBuckets[0x1a];
	/*03e8*/
};

struct _PROC_IDLE_STATE_BUCKET {
	/*0000*/ ULONGLONG TotalTime;
	/*0008*/ ULONGLONG MinTime;
	/*0010*/ ULONGLONG MaxTime;
	/*0018*/ ULONG Count;
	/*0020*/
};

struct _PROC_PERF_CHECK {
	/*0000*/ ULONGLONG LastActive;
	/*0008*/ ULONGLONG LastTime;
	/*0010*/ ULONGLONG LastStall;
	/*0018*/ _PROC_PERF_CHECK_SNAP LastPerfCheckSnap;
	/*0068*/ _PROC_PERF_CHECK_SNAP CurrentSnap;
	/*00b8*/ _PROC_PERF_CHECK_SNAP LastDeliveredSnap;
	/*0108*/ ULONG LastDeliveredPerformance;
	/*010c*/ ULONG LastDeliveredFrequency;
	/*0110*/ UCHAR TaggedThreadPercent[0x2];
	/*0112*/ UCHAR Class0FloorPerfSelection;
	/*0113*/ UCHAR Class1MinimumPerfSelection;
	/*0118*/
};

struct _PROC_PERF_CHECK_SNAP {
	/*0000*/ ULONGLONG Time;
	/*0008*/ ULONGLONG Active;
	/*0010*/ ULONGLONG Stall;
	/*0018*/ ULONGLONG FrequencyScaledActive;
	/*0020*/ ULONGLONG PerformanceScaledActive;
	/*0028*/ ULONGLONG PerformanceScaledKernelActive;
	/*0030*/ ULONGLONG CyclesActive;
	/*0038*/ ULONGLONG CyclesAffinitized;
	/*0040*/ ULONGLONG TaggedThreadCycles[0x2];
	/*0050*/
};

struct _PROC_PERF_CONSTRAINT {
	/*0000*/ _KPRCB * Prcb;
	/*0008*/ ULONGLONG PerfContext;
	/*0010*/ ULONG PlatformCap;
	/*0014*/ ULONG ThermalCap;
	/*0018*/ ULONG LimitReasons;
	/*0020*/ ULONGLONG PlatformCapStartTime;
	/*0028*/ ULONG ProcCap;
	/*002c*/ ULONG ProcFloor;
	/*0030*/ ULONG TargetPercent;
	/*0038*/ _PERF_CONTROL_STATE_SELECTION Selection;
	/*0060*/ ULONG DomainSelectionGeneration;
	/*0064*/ ULONG PreviousFrequency;
	/*0068*/ ULONG PreviousPercent;
	/*006c*/ ULONG LatestFrequencyPercent;
	/*0070*/ UCHAR Force;
	/*0078*/
};

struct _PROC_PERF_DOMAIN {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ _KPRCB * Master;
	/*0018*/ _KAFFINITY_EX Members;
	/*00c0*/ ULONGLONG DomainContext;
	/*00c8*/ ULONG ProcessorCount;
	/*00cc*/ UCHAR EfficiencyClass;
	/*00cd*/ UCHAR NominalPerformanceClass;
	/*00ce*/ UCHAR HighestPerformanceClass;
	/*00cf*/ UCHAR Spare;
	/*00d0*/ _PROC_PERF_CONSTRAINT * Processors;
	/*00d8*/ void (* GetFFHThrottleState)( ULONGLONG * );
	/*00e0*/ void (* TimeWindowHandler)( ULONGLONG , ULONG );
	/*00e8*/ void (* BoostPolicyHandler)( ULONGLONG , ULONG );
	/*00f0*/ void (* BoostModeHandler)( ULONGLONG , ULONG );
	/*00f8*/ void (* EnergyPerfPreferenceHandler)( ULONGLONG , ULONG );
	/*0100*/ void (* AutonomousActivityWindowHandler)( ULONGLONG , ULONG );
	/*0108*/ void (* AutonomousModeHandler)( ULONGLONG , ULONG );
	/*0110*/ void (* ReinitializeHandler)( ULONGLONG );
	/*0118*/ ULONG (* PerfSelectionHandler)( ULONGLONG , ULONG , ULONG , ULONG , ULONG , ULONG , ULONG , ULONG * , ULONGLONG * );
	/*0120*/ void (* PerfControlHandler)( ULONGLONG , _PERF_CONTROL_STATE_SELECTION * , UCHAR , UCHAR );
	/*0128*/ void (* DomainPerfControlHandler)( ULONGLONG , _PERF_CONTROL_STATE_SELECTION * , UCHAR , UCHAR );
	/*0130*/ ULONG MaxFrequency;
	/*0134*/ ULONG NominalFrequency;
	/*0138*/ ULONG MaxPercent;
	/*013c*/ ULONG MinPerfPercent;
	/*0140*/ ULONG MinThrottlePercent;
	/*0148*/ ULONGLONG MinimumRelativePerformance;
	/*0150*/ ULONGLONG NominalRelativePerformance;
	/*0158*/ UCHAR NominalRelativePerformancePercent;
	/*0159*/ UCHAR Coordination;
	/*015a*/ UCHAR HardPlatformCap;
	/*015b*/ UCHAR AffinitizeControl;
	/*015c*/ UCHAR EfficientThrottle;
	/*015d*/ UCHAR AllowSchedulerDirectedPerfStates;
	/*015e*/ UCHAR InitiateAllProcessors;
	/*015f*/ UCHAR AutonomousMode;
	/*0160*/ UCHAR ProvideGuidance;
	/*0164*/ ULONG DesiredPercent;
	/*0168*/ ULONG GuaranteedPercent;
	/*016c*/ _PROC_PERF_QOS_CLASS_POLICY QosPolicies[0x3];
	/*01b4*/ ULONG QosDisableReasons[0x3];
	/*01c0*/ ULONG QosEquivalencyMasks[0x3];
	/*01cc*/ UCHAR QosSupported;
	/*01d0*/ ULONG SelectionGeneration;
	/*01d8*/ _PERF_CONTROL_STATE_SELECTION QosSelection[0x3];
	/*0250*/ ULONGLONG PerfChangeTime;
	/*0258*/ ULONG PerfChangeIntervalCount;
	/*025c*/ UCHAR Force;
	/*0260*/
};

struct _PROC_PERF_HISTORY {
	/*0000*/ ULONG Count;
	/*0004*/ ULONG Slot;
	/*0008*/ ULONG UtilityTotal;
	/*000c*/ ULONG AffinitizedUtilityTotal;
	/*0010*/ ULONG FrequencyTotal;
	/*0014*/ ULONG TaggedPercentTotal[0x2];
	/*001c*/ _PROC_PERF_HISTORY_ENTRY HistoryList[0x1];
	/*0024*/
};

struct _PROC_PERF_HISTORY_ENTRY {
	/*0000*/ USHORT Utility;
	/*0002*/ USHORT AffinitizedUtility;
	/*0004*/ UCHAR Frequency;
	/*0005*/ UCHAR TaggedPercent[0x2];
	/*0008*/
};

struct _PROC_PERF_LOAD {
	/*0000*/ UCHAR BusyPercentage;
	/*0001*/ UCHAR FrequencyPercentage;
	/*0002*/
};

struct _PROC_PERF_QOS_CLASS_POLICY {
	/*0000*/ ULONG MaxPolicyPercent;
	/*0004*/ ULONG MaxEquivalentFrequencyPercent;
	/*0008*/ ULONG MinPolicyPercent;
	/*000c*/ ULONG AutonomousActivityWindow;
	/*0010*/ ULONG EnergyPerfPreference;
	/*0014*/ UCHAR ProvideGuidance;
	/*0015*/ UCHAR AllowThrottling;
	/*0016*/ UCHAR PerfBoostMode;
	/*0017*/ UCHAR LatencyHintPerf;
	/*0018*/
};

struct _PSP_STORAGE;

enum _PS_ATTRIBUTE_NUM {
	PsAttributeParentProcess = 0x0,
	PsAttributeDebugObject = 0x1,
	PsAttributeToken = 0x2,
	PsAttributeClientId = 0x3,
	PsAttributeTebAddress = 0x4,
	PsAttributeImageName = 0x5,
	PsAttributeImageInfo = 0x6,
	PsAttributeMemoryReserve = 0x7,
	PsAttributePriorityClass = 0x8,
	PsAttributeErrorMode = 0x9,
	PsAttributeStdHandleInfo = 0xa,
	PsAttributeHandleList = 0xb,
	PsAttributeGroupAffinity = 0xc,
	PsAttributePreferredNode = 0xd,
	PsAttributeIdealProcessor = 0xe,
	PsAttributeUmsThread = 0xf,
	PsAttributeMitigationOptions = 0x10,
	PsAttributeProtectionLevel = 0x11,
	PsAttributeSecureProcess = 0x12,
	PsAttributeJobList = 0x13,
	PsAttributeChildProcessPolicy = 0x14,
	PsAttributeAllApplicationPackagesPolicy = 0x15,
	PsAttributeWin32kFilter = 0x16,
	PsAttributeSafeOpenPromptOriginClaim = 0x17,
	PsAttributeBnoIsolation = 0x18,
	PsAttributeDesktopAppPolicy = 0x19,
	PsAttributeChpe = 0x1a,
	PsAttributeMax = 0x1b
};

union _PS_CLIENT_SECURITY_CONTEXT {
	/*0000*/ ULONGLONG ImpersonationData;
	/*0000*/ void * ImpersonationToken;
	/*0000*/ ULONGLONG ImpersonationLevel : 02; // 0x0000000000000003;
	/*0000*/ ULONGLONG EffectiveOnly : 01; // 0x0000000000000004;
	/*0008*/
};

union _PS_INTERLOCKED_TIMER_DELAY_VALUES {
	/*0000*/ ULONGLONG DelayMs : 30; // 0x000000003fffffff;
	/*0000*/ ULONGLONG CoalescingWindowMs : 30; // 0x0fffffffc0000000;
	/*0000*/ ULONGLONG Reserved : 01; // 0x1000000000000000;
	/*0000*/ ULONGLONG NewTimerWheel : 01; // 0x2000000000000000;
	/*0000*/ ULONGLONG Retry : 01; // 0x4000000000000000;
	/*0000*/ ULONGLONG Locked : 01; // 0x8000000000000000;
	/*0000*/ ULONGLONG All;
	/*0008*/
};

struct _PS_IO_CONTROL_ENTRY {
	/*0000*/ _RTL_BALANCED_NODE VolumeTreeNode;
	/*0000*/ _LIST_ENTRY FreeListEntry;
	/*0010*/ ULONGLONG ReservedForParentValue;
	/*0018*/ ULONGLONG VolumeKey;
	/*0020*/ _EX_RUNDOWN_REF Rundown;
	/*0028*/ void * IoControl;
	/*0030*/ void * VolumeIoAttribution;
	/*0038*/
};

struct _PS_JOB_WAKE_INFORMATION {
	/*0000*/ ULONGLONG NotificationChannel;
	/*0008*/ ULONGLONG WakeCounters[0x7];
	/*0040*/ ULONGLONG NoWakeCounter;
	/*0048*/
};

struct _PS_MITIGATION_AUDIT_OPTIONS_MAP {
	/*0000*/ ULONGLONG Map[0x2];
	/*0010*/
};

enum _PS_MITIGATION_OPTION {
	PS_MITIGATION_OPTION_NX = 0x0,
	PS_MITIGATION_OPTION_SEHOP = 0x1,
	PS_MITIGATION_OPTION_FORCE_RELOCATE_IMAGES = 0x2,
	PS_MITIGATION_OPTION_HEAP_TERMINATE = 0x3,
	PS_MITIGATION_OPTION_BOTTOM_UP_ASLR = 0x4,
	PS_MITIGATION_OPTION_HIGH_ENTROPY_ASLR = 0x5,
	PS_MITIGATION_OPTION_STRICT_HANDLE_CHECKS = 0x6,
	PS_MITIGATION_OPTION_WIN32K_SYSTEM_CALL_DISABLE = 0x7,
	PS_MITIGATION_OPTION_EXTENSION_POINT_DISABLE = 0x8,
	PS_MITIGATION_OPTION_PROHIBIT_DYNAMIC_CODE = 0x9,
	PS_MITIGATION_OPTION_CONTROL_FLOW_GUARD = 0xa,
	PS_MITIGATION_OPTION_BLOCK_NON_MICROSOFT_BINARIES = 0xb,
	PS_MITIGATION_OPTION_FONT_DISABLE = 0xc,
	PS_MITIGATION_OPTION_IMAGE_LOAD_NO_REMOTE = 0xd,
	PS_MITIGATION_OPTION_IMAGE_LOAD_NO_LOW_LABEL = 0xe,
	PS_MITIGATION_OPTION_IMAGE_LOAD_PREFER_SYSTEM32 = 0xf,
	PS_MITIGATION_OPTION_RETURN_FLOW_GUARD = 0x10,
	PS_MITIGATION_OPTION_LOADER_INTEGRITY_CONTINUITY = 0x11,
	PS_MITIGATION_OPTION_STRICT_CONTROL_FLOW_GUARD = 0x12,
	PS_MITIGATION_OPTION_RESTRICT_SET_THREAD_CONTEXT = 0x13,
	PS_MITIGATION_OPTION_ROP_STACKPIVOT = 0x14,
	PS_MITIGATION_OPTION_ROP_CALLER_CHECK = 0x15,
	PS_MITIGATION_OPTION_ROP_SIMEXEC = 0x16,
	PS_MITIGATION_OPTION_EXPORT_ADDRESS_FILTER = 0x17,
	PS_MITIGATION_OPTION_EXPORT_ADDRESS_FILTER_PLUS = 0x18,
	PS_MITIGATION_OPTION_RESTRICT_CHILD_PROCESS_CREATION = 0x19,
	PS_MITIGATION_OPTION_IMPORT_ADDRESS_FILTER = 0x1a,
	PS_MITIGATION_OPTION_MODULE_TAMPERING_PROTECTION = 0x1b
};

struct _PS_MITIGATION_OPTIONS_MAP {
	/*0000*/ ULONGLONG Map[0x2];
	/*0010*/
};

struct _PS_PROCESS_WAKE_INFORMATION {
	/*0000*/ ULONGLONG NotificationChannel;
	/*0008*/ ULONG WakeCounters[0x7];
	/*0024*/ _JOBOBJECT_WAKE_FILTER WakeFilter;
	/*002c*/ ULONG NoWakeCounter;
	/*0030*/
};

struct _PS_PROPERTY_SET {
	/*0000*/ _LIST_ENTRY ListHead;
	/*0010*/ ULONGLONG Lock;
	/*0018*/
};

enum _PS_PROTECTED_SIGNER {
	PsProtectedSignerNone = 0x0,
	PsProtectedSignerAuthenticode = 0x1,
	PsProtectedSignerCodeGen = 0x2,
	PsProtectedSignerAntimalware = 0x3,
	PsProtectedSignerLsa = 0x4,
	PsProtectedSignerWindows = 0x5,
	PsProtectedSignerWinTcb = 0x6,
	PsProtectedSignerWinSystem = 0x7,
	PsProtectedSignerApp = 0x8,
	PsProtectedSignerMax = 0x9
};

enum _PS_PROTECTED_TYPE {
	PsProtectedTypeNone = 0x0,
	PsProtectedTypeProtectedLight = 0x1,
	PsProtectedTypeProtected = 0x2,
	PsProtectedTypeMax = 0x3
};

struct _PS_PROTECTION {
	/*0000*/ UCHAR Level;
	/*0000*/ UCHAR Type : 03; // 0x07;
	/*0000*/ UCHAR Audit : 01; // 0x08;
	/*0000*/ UCHAR Signer : 04; // 0xf0;
	/*0001*/
};

enum _PS_RESOURCE_TYPE {
	PsResourceNonPagedPool = 0x0,
	PsResourcePagedPool = 0x1,
	PsResourcePageFile = 0x2,
	PsResourceWorkingSet = 0x3,
	PsResourceMax = 0x4
};

enum _PS_STD_HANDLE_STATE {
	PsNeverDuplicate = 0x0,
	PsRequestDuplicate = 0x1,
	PsAlwaysDuplicate = 0x2,
	PsMaxStdHandleStates = 0x3
};

union _PS_TRUSTLET_ATTRIBUTE_ACCESSRIGHTS {
	/*0000*/ UCHAR Trustlet : 01; // 0x01;
	/*0000*/ UCHAR Ntos : 01; // 0x02;
	/*0000*/ UCHAR WriteHandle : 01; // 0x04;
	/*0000*/ UCHAR ReadHandle : 01; // 0x08;
	/*0000*/ UCHAR Reserved : 04; // 0xf0;
	/*0000*/ UCHAR AccessRights;
	/*0001*/
};

struct _PS_TRUSTLET_ATTRIBUTE_DATA {
	/*0000*/ _PS_TRUSTLET_ATTRIBUTE_HEADER Header;
	/*0008*/ ULONGLONG Data[0x1];
	/*0010*/
};

struct _PS_TRUSTLET_ATTRIBUTE_HEADER {
	/*0000*/ _PS_TRUSTLET_ATTRIBUTE_TYPE AttributeType;
	/*0004*/ ULONG InstanceNumber : 08; // 0x000000ff;
	/*0004*/ ULONG Reserved : 24; // 0xffffff00;
	/*0008*/
};

struct _PS_TRUSTLET_ATTRIBUTE_TYPE {
	/*0000*/ UCHAR Version;
	/*0001*/ UCHAR DataCount;
	/*0002*/ UCHAR SemanticType;
	/*0003*/ _PS_TRUSTLET_ATTRIBUTE_ACCESSRIGHTS AccessRights;
	/*0000*/ ULONG AttributeType;
	/*0004*/
};

struct _PS_TRUSTLET_CREATE_ATTRIBUTES {
	/*0000*/ ULONGLONG TrustletIdentity;
	/*0008*/ _PS_TRUSTLET_ATTRIBUTE_DATA Attributes[0x1];
	/*0018*/
};

struct _PS_TRUSTLET_TKSESSION_ID {
	/*0000*/ ULONGLONG SessionId[0x4];
	/*0020*/
};

enum _PS_WAKE_REASON {
	PsWakeReasonUser = 0x0,
	PsWakeReasonExecutionRequired = 0x1,
	PsWakeReasonKernel = 0x2,
	PsWakeReasonInstrumentation = 0x3,
	PsWakeReasonPreserveProcess = 0x4,
	PsWakeReasonActivityReference = 0x5,
	PsWakeReasonWorkOnBehalf = 0x6,
	PsMaxWakeReasons = 0x7
};

struct _PTE_TRACKER {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _MDL * Mdl;
	/*0018*/ ULONGLONG Count;
	/*0020*/ void * SystemVa;
	/*0028*/ void * StartVa;
	/*0030*/ ULONG Offset;
	/*0034*/ ULONG Length;
	/*0038*/ ULONGLONG Page;
	/*0040*/ ULONG IoMapping : 01; // 0x00000001;
	/*0040*/ ULONG Matched : 01; // 0x00000002;
	/*0040*/ ULONG CacheAttribute : 02; // 0x0000000c;
	/*0040*/ ULONG GuardPte : 01; // 0x00000010;
	/*0040*/ ULONG Spare : 27; // 0xffffffe0;
	/*0048*/ void * StackTrace[0x7];
	/*0080*/
};

struct _QUAD {
	/*0000*/ LONGLONG UseThisFieldToCopy;
	/*0000*/ double DoNotUseThisField;
	/*0008*/
};

enum _REG_NOTIFY_CLASS {
	RegNtDeleteKey = 0x0,
	RegNtPreDeleteKey = 0x0,
	RegNtSetValueKey = 0x1,
	RegNtPreSetValueKey = 0x1,
	RegNtDeleteValueKey = 0x2,
	RegNtPreDeleteValueKey = 0x2,
	RegNtSetInformationKey = 0x3,
	RegNtPreSetInformationKey = 0x3,
	RegNtRenameKey = 0x4,
	RegNtPreRenameKey = 0x4,
	RegNtEnumerateKey = 0x5,
	RegNtPreEnumerateKey = 0x5,
	RegNtEnumerateValueKey = 0x6,
	RegNtPreEnumerateValueKey = 0x6,
	RegNtQueryKey = 0x7,
	RegNtPreQueryKey = 0x7,
	RegNtQueryValueKey = 0x8,
	RegNtPreQueryValueKey = 0x8,
	RegNtQueryMultipleValueKey = 0x9,
	RegNtPreQueryMultipleValueKey = 0x9,
	RegNtPreCreateKey = 0xa,
	RegNtPostCreateKey = 0xb,
	RegNtPreOpenKey = 0xc,
	RegNtPostOpenKey = 0xd,
	RegNtKeyHandleClose = 0xe,
	RegNtPreKeyHandleClose = 0xe,
	RegNtPostDeleteKey = 0xf,
	RegNtPostSetValueKey = 0x10,
	RegNtPostDeleteValueKey = 0x11,
	RegNtPostSetInformationKey = 0x12,
	RegNtPostRenameKey = 0x13,
	RegNtPostEnumerateKey = 0x14,
	RegNtPostEnumerateValueKey = 0x15,
	RegNtPostQueryKey = 0x16,
	RegNtPostQueryValueKey = 0x17,
	RegNtPostQueryMultipleValueKey = 0x18,
	RegNtPostKeyHandleClose = 0x19,
	RegNtPreCreateKeyEx = 0x1a,
	RegNtPostCreateKeyEx = 0x1b,
	RegNtPreOpenKeyEx = 0x1c,
	RegNtPostOpenKeyEx = 0x1d,
	RegNtPreFlushKey = 0x1e,
	RegNtPostFlushKey = 0x1f,
	RegNtPreLoadKey = 0x20,
	RegNtPostLoadKey = 0x21,
	RegNtPreUnLoadKey = 0x22,
	RegNtPostUnLoadKey = 0x23,
	RegNtPreQueryKeySecurity = 0x24,
	RegNtPostQueryKeySecurity = 0x25,
	RegNtPreSetKeySecurity = 0x26,
	RegNtPostSetKeySecurity = 0x27,
	RegNtCallbackObjectContextCleanup = 0x28,
	RegNtPreRestoreKey = 0x29,
	RegNtPostRestoreKey = 0x2a,
	RegNtPreSaveKey = 0x2b,
	RegNtPostSaveKey = 0x2c,
	RegNtPreReplaceKey = 0x2d,
	RegNtPostReplaceKey = 0x2e,
	RegNtPreQueryKeyName = 0x2f,
	RegNtPostQueryKeyName = 0x30,
	MaxRegNtNotifyClass = 0x31
};

struct _RELATION_LIST {
	/*0000*/ _DEVICE_OBJECT_LIST * DeviceObjectList;
	/*0008*/ UCHAR Sorted;
	/*0010*/
};

struct _RELATIVE_SYMLINK_INFO {
	/*0000*/ USHORT ExposedNamespaceLength;
	/*0002*/ USHORT Flags;
	/*0004*/ USHORT DeviceNameLength;
	/*0006*/ USHORT Reserved;
	/*0008*/ _RELATIVE_SYMLINK_INFO * InteriorMountPoint;
	/*0010*/ _UNICODE_STRING OpenedName;
	/*0020*/
};

struct _REMOTE_PORT_VIEW {
	/*0000*/ ULONG Length;
	/*0008*/ ULONGLONG ViewSize;
	/*0010*/ void * ViewBase;
	/*0018*/
};

enum _REQUESTER_TYPE {
	KernelRequester = 0x0,
	UserProcessRequester = 0x1,
	UserSharedServiceRequester = 0x2
};

struct _REQUEST_MAILBOX {
	/*0000*/ _REQUEST_MAILBOX * Next;
	/*0008*/ ULONGLONG RequestSummary;
	/*0010*/ _KREQUEST_PACKET RequestPacket;
	/*0030*/ LONG volatile * NodeTargetCountAddr;
	/*0038*/ LONG volatile NodeTargetCount;
	/*0040*/
};

struct _RH_OP_CONTEXT {
	/*0000*/ _LIST_ENTRY Links;
	/*0010*/ _IRP * OplockRequestIrp;
	/*0018*/ _FILE_OBJECT * OplockRequestFileObject;
	/*0020*/ _EPROCESS * OplockRequestProcess;
	/*0028*/ _ETHREAD * OplockOwnerThread;
	/*0030*/ ULONG Flags;
	/*0038*/ _LIST_ENTRY AtomicLinks;
	/*0048*/
};

struct _RSDS {
	/*0000*/ ULONG Signature;
	/*0004*/ _GUID Guid;
	/*0014*/ ULONG Age;
	/*0018*/ CHAR PdbName[0x1];
	/*001c*/
};

struct _RTLP_RANGE_LIST_ENTRY {
	/*0000*/ ULONGLONG Start;
	/*0008*/ ULONGLONG End;
	struct {
		/*0010*/ void * UserData;
		/*0018*/ void * Owner;
		/*0020*/
	} Allocated;
	struct {
		/*0010*/ _LIST_ENTRY ListHead;
		/*0020*/
	} Merged;
	/*0020*/ UCHAR Attributes;
	/*0021*/ UCHAR PublicFlags;
	/*0022*/ USHORT PrivateFlags;
	/*0028*/ _LIST_ENTRY ListEntry;
	/*0038*/
};

struct _RTL_ACTIVATION_CONTEXT_STACK_FRAME {
	/*0000*/ _RTL_ACTIVATION_CONTEXT_STACK_FRAME * Previous;
	/*0008*/ _ACTIVATION_CONTEXT * ActivationContext;
	/*0010*/ ULONG Flags;
	/*0018*/
};

struct _RTL_ATOM_TABLE {
	/*0000*/ ULONG Signature;
	/*0004*/ LONG volatile ReferenceCount;
	/*0008*/ _EX_PUSH_LOCK PushLock;
	/*0010*/ _HANDLE_TABLE * ExHandleTable;
	/*0018*/ ULONG Flags;
	/*001c*/ ULONG NumberOfBuckets;
	/*0020*/ _RTL_ATOM_TABLE_ENTRY * Buckets[0x1];
	/*0028*/
};

struct _RTL_ATOM_TABLE_ENTRY {
	/*0000*/ _RTL_ATOM_TABLE_ENTRY * HashLink;
	/*0008*/ USHORT HandleIndex;
	/*000a*/ USHORT Atom;
	/*0010*/ _RTL_ATOM_TABLE_REFERENCE Reference;
	/*0028*/ UCHAR NameLength;
	/*002a*/ WCHAR Name[0x1];
	/*0030*/
};

struct _RTL_ATOM_TABLE_REFERENCE {
	/*0000*/ _LIST_ENTRY LowBoxList;
	/*0010*/ ULONG LowBoxID;
	/*0014*/ USHORT ReferenceCount;
	/*0016*/ USHORT Flags;
	/*0018*/
};

struct _RTL_AVL_TABLE {
	/*0000*/ _RTL_BALANCED_LINKS BalancedRoot;
	/*0020*/ void * OrderedPointer;
	/*0028*/ ULONG WhichOrderedElement;
	/*002c*/ ULONG NumberGenericTableElements;
	/*0030*/ ULONG DepthOfTree;
	/*0038*/ _RTL_BALANCED_LINKS * RestartKey;
	/*0040*/ ULONG DeleteCount;
	/*0048*/ _RTL_GENERIC_COMPARE_RESULTS (* CompareRoutine)( _RTL_AVL_TABLE * , void * , void * );
	/*0050*/ void * (* AllocateRoutine)( _RTL_AVL_TABLE * , ULONG );
	/*0058*/ void (* FreeRoutine)( _RTL_AVL_TABLE * , void * );
	/*0060*/ void * TableContext;
	/*0068*/
};

struct _RTL_AVL_TREE {
	/*0000*/ _RTL_BALANCED_NODE * Root;
	/*0008*/
};

struct _RTL_BALANCED_LINKS {
	/*0000*/ _RTL_BALANCED_LINKS * Parent;
	/*0008*/ _RTL_BALANCED_LINKS * LeftChild;
	/*0010*/ _RTL_BALANCED_LINKS * RightChild;
	/*0018*/ CHAR Balance;
	/*0019*/ UCHAR Reserved[0x3];
	/*0020*/
};

struct _RTL_BALANCED_NODE {
	/*0000*/ _RTL_BALANCED_NODE * Children[0x2];
	/*0000*/ _RTL_BALANCED_NODE * Left;
	/*0008*/ _RTL_BALANCED_NODE * Right;
	/*0010*/ UCHAR Red : 01; // 0x01;
	/*0010*/ UCHAR Balance : 02; // 0x03;
	/*0010*/ ULONGLONG ParentValue;
	/*0018*/
};

struct _RTL_BITMAP {
	/*0000*/ ULONG SizeOfBitMap;
	/*0008*/ ULONG * Buffer;
	/*0010*/
};

struct _RTL_BITMAP_EX {
	/*0000*/ ULONGLONG SizeOfBitMap;
	/*0008*/ ULONGLONG * Buffer;
	/*0010*/
};

struct _RTL_CHASH_ENTRY {
	/*0000*/ ULONGLONG Key;
	/*0008*/
};

struct _RTL_CHASH_TABLE {
	/*0000*/ _RTL_CHASH_ENTRY * Table;
	/*0008*/ ULONG EntrySizeShift;
	/*000c*/ ULONG EntryMax;
	/*0010*/ ULONG EntryCount;
	/*0018*/
};

struct _RTL_CRITICAL_SECTION {
	/*0000*/ _RTL_CRITICAL_SECTION_DEBUG * DebugInfo;
	/*0008*/ LONG LockCount;
	/*000c*/ LONG RecursionCount;
	/*0010*/ void * OwningThread;
	/*0018*/ void * LockSemaphore;
	/*0020*/ ULONGLONG SpinCount;
	/*0028*/
};

struct _RTL_CRITICAL_SECTION_DEBUG {
	/*0000*/ USHORT Type;
	/*0002*/ USHORT CreatorBackTraceIndex;
	/*0008*/ _RTL_CRITICAL_SECTION * CriticalSection;
	/*0010*/ _LIST_ENTRY ProcessLocksList;
	/*0020*/ ULONG EntryCount;
	/*0024*/ ULONG ContentionCount;
	/*0028*/ ULONG Flags;
	/*002c*/ USHORT CreatorBackTraceIndexHigh;
	/*002e*/ USHORT SpareUSHORT;
	/*0030*/
};

struct _RTL_DRIVE_LETTER_CURDIR {
	/*0000*/ USHORT Flags;
	/*0002*/ USHORT Length;
	/*0004*/ ULONG TimeStamp;
	/*0008*/ _STRING DosPath;
	/*0018*/
};

struct _RTL_DYNAMIC_HASH_TABLE {
	/*0000*/ ULONG Flags;
	/*0004*/ ULONG Shift;
	/*0008*/ ULONG TableSize;
	/*000c*/ ULONG Pivot;
	/*0010*/ ULONG DivisorMask;
	/*0014*/ ULONG NumEntries;
	/*0018*/ ULONG NonEmptyBuckets;
	/*001c*/ ULONG NumEnumerators;
	/*0020*/ void * Directory;
	/*0028*/
};

struct _RTL_DYNAMIC_HASH_TABLE_CONTEXT {
	/*0000*/ _LIST_ENTRY * ChainHead;
	/*0008*/ _LIST_ENTRY * PrevLinkage;
	/*0010*/ ULONGLONG Signature;
	/*0018*/
};

struct _RTL_DYNAMIC_HASH_TABLE_ENTRY {
	/*0000*/ _LIST_ENTRY Linkage;
	/*0010*/ ULONGLONG Signature;
	/*0018*/
};

struct _RTL_DYNAMIC_HASH_TABLE_ENUMERATOR {
	/*0000*/ _RTL_DYNAMIC_HASH_TABLE_ENTRY HashEntry;
	/*0000*/ _LIST_ENTRY * CurEntry;
	/*0018*/ _LIST_ENTRY * ChainHead;
	/*0020*/ ULONG BucketIndex;
	/*0028*/
};

enum _RTL_GENERIC_COMPARE_RESULTS {
	GenericLessThan = 0x0,
	GenericGreaterThan = 0x1,
	GenericEqual = 0x2
};

struct _RTL_HASH_ENTRY {
	/*0000*/ _SINGLE_LIST_ENTRY BucketLink;
	/*0008*/ ULONGLONG Key;
	/*0010*/
};

struct _RTL_HASH_TABLE {
	/*0000*/ ULONG EntryCount;
	/*0004*/ ULONG MaskBitCount : 05; // 0x0000001f;
	/*0004*/ ULONG BucketCount : 27; // 0xffffffe0;
	/*0008*/ _SINGLE_LIST_ENTRY * Buckets;
	/*0010*/
};

struct _RTL_HASH_TABLE_ITERATOR {
	/*0000*/ _RTL_HASH_TABLE * Hash;
	/*0008*/ _RTL_HASH_ENTRY * HashEntry;
	/*0010*/ _SINGLE_LIST_ENTRY * Bucket;
	/*0018*/
};

struct _RTL_RANGE {
	/*0000*/ ULONGLONG Start;
	/*0008*/ ULONGLONG End;
	/*0010*/ void * UserData;
	/*0018*/ void * Owner;
	/*0020*/ UCHAR Attributes;
	/*0021*/ UCHAR Flags;
	/*0028*/
};

struct _RTL_RANGE_LIST {
	/*0000*/ _LIST_ENTRY ListHead;
	/*0010*/ ULONG Flags;
	/*0014*/ ULONG Count;
	/*0018*/ ULONG Stamp;
	/*0020*/
};

struct _RTL_RB_TREE {
	/*0000*/ _RTL_BALANCED_NODE * Root;
	/*0008*/ UCHAR Encoded : 01; // 0x01;
	/*0008*/ _RTL_BALANCED_NODE * Min;
	/*0010*/
};

union _RTL_RUN_ONCE {
	/*0000*/ void * Ptr;
	/*0000*/ ULONGLONG Value;
	/*0000*/ ULONGLONG State : 02; // 0x0000000000000003;
	/*0008*/
};

struct _RTL_SPLAY_LINKS {
	/*0000*/ _RTL_SPLAY_LINKS * Parent;
	/*0008*/ _RTL_SPLAY_LINKS * LeftChild;
	/*0010*/ _RTL_SPLAY_LINKS * RightChild;
	/*0018*/
};

struct _RTL_SRWLOCK {
	/*0000*/ ULONGLONG Locked : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG Waiting : 01; // 0x0000000000000002;
	/*0000*/ ULONGLONG Waking : 01; // 0x0000000000000004;
	/*0000*/ ULONGLONG MultipleShared : 01; // 0x0000000000000008;
	/*0000*/ ULONGLONG Shared : 60; // 0xfffffffffffffff0;
	/*0000*/ ULONGLONG Value;
	/*0000*/ void * Ptr;
	/*0008*/
};

struct _RTL_TIME_ZONE_INFORMATION {
	/*0000*/ LONG Bias;
	/*0004*/ WCHAR StandardName[0x20];
	/*0044*/ _TIME_FIELDS StandardStart;
	/*0054*/ LONG StandardBias;
	/*0058*/ WCHAR DaylightName[0x20];
	/*0098*/ _TIME_FIELDS DaylightStart;
	/*00a8*/ LONG DaylightBias;
	/*00ac*/
};

struct _RTL_UMS_CONTEXT {
	/*0000*/ _SINGLE_LIST_ENTRY Link;
	/*0010*/ _CONTEXT Context;
	/*04e0*/ void * Teb;
	/*04e8*/ void * UserContext;
	/*04f0*/ ULONG volatile ScheduledThread : 01; // 0x00000001;
	/*04f0*/ ULONG volatile Suspended : 01; // 0x00000002;
	/*04f0*/ ULONG volatile VolatileContext : 01; // 0x00000004;
	/*04f0*/ ULONG volatile Terminated : 01; // 0x00000008;
	/*04f0*/ ULONG volatile DebugActive : 01; // 0x00000010;
	/*04f0*/ ULONG volatile RunningOnSelfThread : 01; // 0x00000020;
	/*04f0*/ ULONG volatile DenyRunningOnSelfThread : 01; // 0x00000040;
	/*04f0*/ LONG volatile Flags;
	/*04f8*/ ULONGLONG volatile KernelUpdateLock : 02; // 0x0000000000000003;
	/*04f8*/ ULONGLONG volatile PrimaryClientID : 62; // 0xfffffffffffffffc;
	/*04f8*/ ULONGLONG volatile ContextLock;
	/*0500*/ _RTL_UMS_CONTEXT * PrimaryUmsContext;
	/*0508*/ ULONG SwitchCount;
	/*050c*/ ULONG KernelYieldCount;
	/*0510*/ ULONG MixedYieldCount;
	/*0514*/ ULONG YieldCount;
	/*0520*/
};

struct _RTL_USER_PROCESS_PARAMETERS {
	/*0000*/ ULONG MaximumLength;
	/*0004*/ ULONG Length;
	/*0008*/ ULONG Flags;
	/*000c*/ ULONG DebugFlags;
	/*0010*/ void * ConsoleHandle;
	/*0018*/ ULONG ConsoleFlags;
	/*0020*/ void * StandardInput;
	/*0028*/ void * StandardOutput;
	/*0030*/ void * StandardError;
	/*0038*/ _CURDIR CurrentDirectory;
	/*0050*/ _UNICODE_STRING DllPath;
	/*0060*/ _UNICODE_STRING ImagePathName;
	/*0070*/ _UNICODE_STRING CommandLine;
	/*0080*/ void * Environment;
	/*0088*/ ULONG StartingX;
	/*008c*/ ULONG StartingY;
	/*0090*/ ULONG CountX;
	/*0094*/ ULONG CountY;
	/*0098*/ ULONG CountCharsX;
	/*009c*/ ULONG CountCharsY;
	/*00a0*/ ULONG FillAttribute;
	/*00a4*/ ULONG WindowFlags;
	/*00a8*/ ULONG ShowWindowFlags;
	/*00b0*/ _UNICODE_STRING WindowTitle;
	/*00c0*/ _UNICODE_STRING DesktopInfo;
	/*00d0*/ _UNICODE_STRING ShellInfo;
	/*00e0*/ _UNICODE_STRING RuntimeData;
	/*00f0*/ _RTL_DRIVE_LETTER_CURDIR CurrentDirectores[0x20];
	/*03f0*/ ULONGLONG EnvironmentSize;
	/*03f8*/ ULONGLONG EnvironmentVersion;
	/*0400*/ void * PackageDependencyData;
	/*0408*/ ULONG ProcessGroupId;
	/*040c*/ ULONG LoaderThreads;
	/*0410*/
};

struct _SCSI_REQUEST_BLOCK;

struct _SECTION {
	/*0000*/ _RTL_BALANCED_NODE SectionNode;
	/*0018*/ ULONGLONG StartingVpn;
	/*0020*/ ULONGLONG EndingVpn;
	union {
		/*0028*/ _CONTROL_AREA * ControlArea;
		/*0028*/ _FILE_OBJECT * FileObject;
		/*0028*/ ULONGLONG RemoteImageFileObject : 01; // 0x0000000000000001;
		/*0028*/ ULONGLONG RemoteDataFileObject : 01; // 0x0000000000000002;
		/*0030*/
	} u1;
	/*0030*/ ULONGLONG SizeOfSection;
	union {
		/*0038*/ ULONG LongFlags;
		/*0038*/ _MMSECTION_FLAGS Flags;
		/*003c*/
	} u;
	/*003c*/ ULONG InitialPageProtection : 12; // 0x00000fff;
	/*003c*/ ULONG SessionId : 19; // 0x7ffff000;
	/*003c*/ ULONG NoValidationNeeded : 01; // 0x80000000;
	/*0040*/
};

struct _SECTION_IMAGE_INFORMATION {
	/*0000*/ void * TransferAddress;
	/*0008*/ ULONG ZeroBits;
	/*0010*/ ULONGLONG MaximumStackSize;
	/*0018*/ ULONGLONG CommittedStackSize;
	/*0020*/ ULONG SubSystemType;
	/*0024*/ USHORT SubSystemMinorVersion;
	/*0026*/ USHORT SubSystemMajorVersion;
	/*0024*/ ULONG SubSystemVersion;
	/*0028*/ USHORT MajorOperatingSystemVersion;
	/*002a*/ USHORT MinorOperatingSystemVersion;
	/*0028*/ ULONG OperatingSystemVersion;
	/*002c*/ USHORT ImageCharacteristics;
	/*002e*/ USHORT DllCharacteristics;
	/*0030*/ USHORT Machine;
	/*0032*/ UCHAR ImageContainsCode;
	/*0033*/ UCHAR ImageFlags;
	/*0033*/ UCHAR ComPlusNativeReady : 01; // 0x01;
	/*0033*/ UCHAR ComPlusILOnly : 01; // 0x02;
	/*0033*/ UCHAR ImageDynamicallyRelocated : 01; // 0x04;
	/*0033*/ UCHAR ImageMappedFlat : 01; // 0x08;
	/*0033*/ UCHAR BaseBelow4gb : 01; // 0x10;
	/*0033*/ UCHAR ComPlusPrefer32bit : 01; // 0x20;
	/*0033*/ UCHAR Reserved : 02; // 0xc0;
	/*0034*/ ULONG LoaderFlags;
	/*0038*/ ULONG ImageFileSize;
	/*003c*/ ULONG CheckSum;
	/*0040*/
};

struct _SECTION_OBJECT_POINTERS {
	/*0000*/ void * DataSectionObject;
	/*0008*/ void * SharedCacheMap;
	/*0010*/ void * ImageSectionObject;
	/*0018*/
};

struct _SECURITY_CLIENT_CONTEXT {
	/*0000*/ _SECURITY_QUALITY_OF_SERVICE SecurityQos;
	/*0010*/ void * ClientToken;
	/*0018*/ UCHAR DirectlyAccessClientToken;
	/*0019*/ UCHAR DirectAccessEffectiveOnly;
	/*001a*/ UCHAR ServerIsRemote;
	/*001c*/ _TOKEN_CONTROL ClientTokenControl;
	/*0048*/
};

struct _SECURITY_DESCRIPTOR {
	/*0000*/ UCHAR Revision;
	/*0001*/ UCHAR Sbz1;
	/*0002*/ USHORT Control;
	/*0008*/ void * Owner;
	/*0010*/ void * Group;
	/*0018*/ _ACL * Sacl;
	/*0020*/ _ACL * Dacl;
	/*0028*/
};

struct _SECURITY_DESCRIPTOR_RELATIVE {
	/*0000*/ UCHAR Revision;
	/*0001*/ UCHAR Sbz1;
	/*0002*/ USHORT Control;
	/*0004*/ ULONG Owner;
	/*0008*/ ULONG Group;
	/*000c*/ ULONG Sacl;
	/*0010*/ ULONG Dacl;
	/*0014*/
};

enum _SECURITY_IMPERSONATION_LEVEL {
	SecurityAnonymous = 0x0,
	SecurityIdentification = 0x1,
	SecurityImpersonation = 0x2,
	SecurityDelegation = 0x3
};

enum _SECURITY_OPERATION_CODE {
	SetSecurityDescriptor = 0x0,
	QuerySecurityDescriptor = 0x1,
	DeleteSecurityDescriptor = 0x2,
	AssignSecurityDescriptor = 0x3
};

struct _SECURITY_QUALITY_OF_SERVICE {
	/*0000*/ ULONG Length;
	/*0004*/ _SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
	/*0008*/ UCHAR ContextTrackingMode;
	/*0009*/ UCHAR EffectiveOnly;
	/*000c*/
};

struct _SECURITY_SUBJECT_CONTEXT {
	/*0000*/ void * ClientToken;
	/*0008*/ _SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
	/*0010*/ void * PrimaryToken;
	/*0018*/ void * ProcessAuditId;
	/*0020*/
};

struct _SEGMENT {
	/*0000*/ _CONTROL_AREA * ControlArea;
	/*0008*/ ULONG TotalNumberOfPtes;
	/*000c*/ _SEGMENT_FLAGS SegmentFlags;
	/*0010*/ ULONGLONG NumberOfCommittedPages;
	/*0018*/ ULONGLONG SizeOfSegment;
	/*0020*/ _MMEXTEND_INFO * ExtendInfo;
	/*0020*/ void * BasedAddress;
	/*0028*/ _EX_PUSH_LOCK SegmentLock;
	union {
		/*0030*/ ULONGLONG ImageCommitment;
		/*0030*/ ULONG CreatingProcessId;
		/*0038*/
	} u1;
	union {
		/*0038*/ _MI_SECTION_IMAGE_INFORMATION * ImageInformation;
		/*0038*/ void * FirstMappedVa;
		/*0040*/
	} u2;
	/*0040*/ _MMPTE * PrototypePte;
	/*0048*/
};

struct _SEGMENT_FLAGS {
	/*0000*/ USHORT TotalNumberOfPtes4132 : 10; // 0x03ff;
	/*0000*/ USHORT Spare0 : 02; // 0x0c00;
	/*0000*/ USHORT LargePages : 01; // 0x1000;
	/*0000*/ USHORT DebugSymbolsLoaded : 01; // 0x2000;
	/*0000*/ USHORT WriteCombined : 01; // 0x4000;
	/*0000*/ USHORT NoCache : 01; // 0x8000;
	/*0000*/ USHORT Short0;
	/*0002*/ UCHAR Unused : 01; // 0x01;
	/*0002*/ UCHAR DefaultProtectionMask : 05; // 0x3e;
	/*0002*/ UCHAR Binary32 : 01; // 0x40;
	/*0002*/ UCHAR ContainsDebug : 01; // 0x80;
	/*0002*/ UCHAR UChar1;
	/*0003*/ UCHAR ForceCollision : 01; // 0x01;
	/*0003*/ UCHAR ImageSigningType : 03; // 0x0e;
	/*0003*/ UCHAR ImageSigningLevel : 04; // 0xf0;
	/*0003*/ UCHAR UChar2;
	/*0004*/
};

struct _SEGMENT_HEAP_EXTRA {
	/*0000*/ USHORT AllocationTag;
	/*0002*/ UCHAR InterceptorIndex : 04; // 0x0f;
	/*0002*/ UCHAR UserFlags : 04; // 0xf0;
	/*0003*/ UCHAR ExtraSizeInUnits;
	/*0008*/ void * Settable;
	/*0010*/
};

struct _SEP_AUDIT_POLICY {
	/*0000*/ _TOKEN_AUDIT_POLICY AdtTokenPolicy;
	/*001e*/ UCHAR PolicySetStatus;
	/*001f*/
};

struct _SEP_CACHED_HANDLES_ENTRY {
	/*0000*/ _RTL_DYNAMIC_HASH_TABLE_ENTRY HashEntry;
	/*0018*/ LONGLONG ReferenceCount;
	/*0020*/ _SEP_CACHED_HANDLES_ENTRY_DESCRIPTOR EntryDescriptor;
	/*0038*/ ULONG HandleCount;
	/*0040*/ void * * Handles;
	/*0048*/
};

struct _SEP_CACHED_HANDLES_ENTRY_DESCRIPTOR {
	/*0000*/ _SEP_CACHED_HANDLES_ENTRY_TYPE DescriptorType;
	/*0008*/ void * PackageSid;
	/*0008*/ _UNICODE_STRING IsolationPrefix;
	/*0018*/
};

enum _SEP_CACHED_HANDLES_ENTRY_TYPE {
	SepCachedHandlesEntryLowbox = 0x0,
	SepCachedHandlesEntryBnoIsolation = 0x1
};

struct _SEP_CACHED_HANDLES_TABLE {
	/*0000*/ _EX_PUSH_LOCK Lock;
	/*0008*/ _RTL_DYNAMIC_HASH_TABLE * HashTable;
	/*0010*/
};

struct _SEP_LOGON_SESSION_REFERENCES {
	/*0000*/ _SEP_LOGON_SESSION_REFERENCES * Next;
	/*0008*/ _LUID LogonId;
	/*0010*/ _LUID BuddyLogonId;
	/*0018*/ LONGLONG ReferenceCount;
	/*0020*/ ULONG Flags;
	/*0028*/ _DEVICE_MAP * pDeviceMap;
	/*0030*/ void * Token;
	/*0038*/ _UNICODE_STRING AccountName;
	/*0048*/ _UNICODE_STRING AuthorityName;
	/*0058*/ _SEP_CACHED_HANDLES_TABLE CachedHandlesTable;
	/*0068*/ _EX_PUSH_LOCK SharedDataLock;
	/*0070*/ _AUTHZBASEP_CLAIM_ATTRIBUTES_COLLECTION * SharedClaimAttributes;
	/*0078*/ _SEP_SID_VALUES_BLOCK * SharedSidValues;
	/*0080*/ _OB_HANDLE_REVOCATION_BLOCK RevocationBlock;
	/*00a0*/ _EJOB * ServerSilo;
	/*00a8*/ _LUID SiblingAuthId;
	/*00b0*/ _LIST_ENTRY TokenList;
	/*00c0*/
};

struct _SEP_LOWBOX_NUMBER_ENTRY {
	/*0000*/ _RTL_DYNAMIC_HASH_TABLE_ENTRY HashEntry;
	/*0018*/ LONGLONG ReferenceCount;
	/*0020*/ void * PackageSid;
	/*0028*/ ULONG LowboxNumber;
	/*0030*/ void * AtomTable;
	/*0038*/
};

struct _SEP_LOWBOX_NUMBER_MAPPING {
	/*0000*/ _EX_PUSH_LOCK Lock;
	/*0008*/ _RTL_BITMAP Bitmap;
	/*0018*/ _RTL_DYNAMIC_HASH_TABLE * HashTable;
	/*0020*/ UCHAR Active;
	/*0028*/
};

struct _SEP_LUID_TO_INDEX_MAP_ENTRY {
	/*0000*/ _RTL_DYNAMIC_HASH_TABLE_ENTRY HashEntry;
	/*0018*/ LONGLONG ReferenceCount;
	/*0020*/ ULONGLONG Luid;
	/*0028*/ ULONGLONG IndexIntoGlobalSingletonTable;
	/*0030*/ UCHAR MarkedForDeletion;
	/*0038*/
};

struct _SEP_RM_LSA_CONNECTION_STATE {
	/*0000*/ void * LsaProcessHandle;
	/*0008*/ void * LsaCommandPortHandle;
	/*0010*/ void * SepRmThreadHandle;
	/*0018*/ void * RmCommandPortHandle;
	/*0020*/ void * RmCommandServerPortHandle;
	/*0028*/ void * LsaCommandPortSectionHandle;
	/*0030*/ _LARGE_INTEGER LsaCommandPortSectionSize;
	/*0038*/ void * LsaViewPortMemory;
	/*0040*/ void * RmViewPortMemory;
	/*0048*/ LONG LsaCommandPortMemoryDelta;
	/*004c*/ UCHAR LsaCommandPortActive;
	/*0050*/
};

struct _SEP_SID_VALUES_BLOCK {
	/*0000*/ ULONG BlockLength;
	/*0008*/ LONGLONG ReferenceCount;
	/*0010*/ ULONG SidCount;
	/*0018*/ ULONGLONG SidValuesStart;
	/*0020*/
};

struct _SEP_SILOSTATE {
	/*0000*/ _SEP_LOGON_SESSION_REFERENCES * SystemLogonSession;
	/*0008*/ _SEP_LOGON_SESSION_REFERENCES * AnonymousLogonSession;
	/*0010*/ void * AnonymousLogonToken;
	/*0018*/ void * AnonymousLogonTokenNoEveryone;
	/*0020*/ _UNICODE_STRING * UncSystemPaths;
	/*0028*/ _CI_NGEN_PATHS * NgenPaths;
	/*0030*/
};

struct _SEP_TOKEN_DIAG_TRACK_ENTRY {
	/*0000*/ void * ProcessCid;
	/*0008*/ void * ThreadCid;
	/*0010*/ UCHAR ImageFileName[0x10];
	/*0020*/ ULONG CreateMethod;
	/*0028*/ ULONGLONG CreateTrace[0x1e];
	/*0118*/ LONG Count;
	/*011c*/ LONG CaptureCount;
	/*0120*/
};

struct _SEP_TOKEN_PRIVILEGES {
	/*0000*/ ULONGLONG Present;
	/*0008*/ ULONGLONG Enabled;
	/*0010*/ ULONGLONG EnabledByDefault;
	/*0018*/
};

enum _SERVERSILO_STATE {
	SERVERSILO_INITING = 0x0,
	SERVERSILO_STARTED = 0x1,
	SERVERSILO_SHUTTING_DOWN = 0x2,
	SERVERSILO_TERMINATING = 0x3,
	SERVERSILO_TERMINATED = 0x4
};

struct _SESSION_LOWBOX_MAP {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ ULONG SessionId;
	/*0018*/ _SEP_LOWBOX_NUMBER_MAPPING LowboxMap;
	/*0040*/
};

struct _SE_AUDIT_PROCESS_CREATION_INFO {
	/*0000*/ _OBJECT_NAME_INFORMATION * ImageFileName;
	/*0008*/
};

struct _SHARED_CACHE_MAP {
	/*0000*/ SHORT NodeTypeCode;
	/*0002*/ SHORT NodeByteSize;
	/*0004*/ ULONG OpenCount;
	/*0008*/ _LARGE_INTEGER FileSize;
	/*0010*/ _LIST_ENTRY BcbList;
	/*0020*/ _LARGE_INTEGER SectionSize;
	/*0028*/ _LARGE_INTEGER ValidDataLength;
	/*0030*/ _LARGE_INTEGER ValidDataGoal;
	/*0038*/ _VACB * InitialVacbs[0x4];
	/*0058*/ _VACB * * Vacbs;
	/*0060*/ _EX_FAST_REF FileObjectFastRef;
	/*0068*/ _EX_PUSH_LOCK VacbLock;
	/*0070*/ ULONG DirtyPages;
	/*0078*/ _LIST_ENTRY LoggedStreamLinks;
	/*0088*/ _LIST_ENTRY SharedCacheMapLinks;
	/*0098*/ ULONG Flags;
	/*009c*/ LONG Status;
	/*00a0*/ _MBCB * Mbcb;
	/*00a8*/ void * Section;
	/*00b0*/ _KEVENT * CreateEvent;
	/*00b8*/ _KEVENT * WaitOnActiveCount;
	/*00c0*/ ULONG PagesToWrite;
	/*00c8*/ LONGLONG BeyondLastFlush;
	/*00d0*/ _CACHE_MANAGER_CALLBACKS * Callbacks;
	/*00d8*/ void * LazyWriteContext;
	/*00e0*/ _LIST_ENTRY PrivateList;
	/*00f0*/ _LOGGED_STREAM_CALLBACK_V1 V1;
	/*00f0*/ _LOGGED_STREAM_CALLBACK_V2 V2;
	/*0100*/ _LARGE_INTEGER LargestLSN;
	/*0108*/ ULONG DirtyPageThreshold;
	/*010c*/ ULONG LazyWritePassCount;
	/*0110*/ _CACHE_UNINITIALIZE_EVENT * UninitializeEvent;
	/*0118*/ _FAST_MUTEX BcbLock;
	/*0150*/ _LARGE_INTEGER LastUnmapBehindOffset;
	/*0158*/ _KEVENT Event;
	/*0170*/ _LARGE_INTEGER HighWaterMappingOffset;
	/*0178*/ _PRIVATE_CACHE_MAP PrivateCacheMap;
	/*01f0*/ void * WriteBehindWorkQueueEntry;
	/*01f8*/ _VOLUME_CACHE_MAP * VolumeCacheMap;
	/*0200*/ ULONG ProcImagePathHash;
	/*0204*/ ULONG WritesInProgress;
	/*0208*/ ULONG AsyncReadRequestCount;
	/*0210*/ _CC_PARTITION * Partition;
	/*0218*/
};

struct _SHARED_CACHE_MAP_LIST_CURSOR {
	/*0000*/ _LIST_ENTRY SharedCacheMapLinks;
	/*0010*/ ULONG Flags;
	/*0018*/
};

struct _SID {
	/*0000*/ UCHAR Revision;
	/*0001*/ UCHAR SubAuthorityCount;
	/*0002*/ _SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
	/*0008*/ ULONG SubAuthority[0x1];
	/*000c*/
};

struct _SID_AND_ATTRIBUTES {
	/*0000*/ void * Sid;
	/*0008*/ ULONG Attributes;
	/*0010*/
};

struct _SID_AND_ATTRIBUTES_HASH {
	/*0000*/ ULONG SidCount;
	/*0008*/ _SID_AND_ATTRIBUTES * SidAttr;
	/*0010*/ ULONGLONG Hash[0x20];
	/*0110*/
};

struct _SID_IDENTIFIER_AUTHORITY {
	/*0000*/ UCHAR Value[0x6];
	/*0006*/
};

struct _SILO_USER_SHARED_DATA {
	/*0000*/ ULONG ServiceSessionId;
	/*0004*/ ULONG ActiveConsoleId;
	/*0008*/ LONGLONG ConsoleSessionForegroundProcessId;
	/*0010*/ _NT_PRODUCT_TYPE NtProductType;
	/*0014*/ ULONG SuiteMask;
	/*0018*/ ULONG SharedUserSessionId;
	/*001c*/ UCHAR IsMultiSessionSku;
	/*001e*/ WCHAR NtSystemRoot[0x104];
	/*0226*/ USHORT UserModeGlobalLogger[0x10];
	/*0248*/
};

struct _SINGLE_LIST_ENTRY {
	/*0000*/ _SINGLE_LIST_ENTRY * Next;
	/*0008*/
};

struct _SINGLE_LIST_ENTRY32 {
	/*0000*/ ULONG Next;
	/*0004*/
};

enum _SKSERVICE {
	SECURESERVICE_NONE = 0x0,
	SECURESERVICE_PHASE4_INIT = 0x1,
	SECURESERVICE_START_PROCESSOR = 0x2,
	SECURESERVICE_REGISTER_SYSTEM_DLLS = 0x3,
	SECURESERVICE_REGISTER_SYSTEM_PROCESS = 0x4,
	SECURESERVICE_CREATE_PROCESS = 0x5,
	SECURESERVICE_INITIALIZE_PROCESS = 0x6,
	SECURESERVICE_CREATE_THREAD = 0x7,
	SECURESERVICE_REQUEST_THREAD_EXIT = 0x8,
	SECURESERVICE_TERMINATE_THREAD = 0x9,
	SECURESERVICE_RUNDOWN_PROCESS = 0xa,
	SECURESERVICE_DEBUG_PROCESS = 0xb,
	SECURESERVICE_GET_TEB_ADDRESS = 0xc,
	SECURESERVICE_GET_CONTEXT = 0xd,
	SECURESERVICE_SET_CONTEXT = 0xe,
	SECURESERVICE_SEND_ATTACH_NOTIFICATIONS = 0xf,
	SECURESERVICE_GET_ETW_DEBUG_ID = 0x10,
	SECURESERVICE_GET_ON_DEMAND_DEBUG_CHALLENGE = 0x11,
	SECURESERVICE_ENABLE_ON_DEMAND_DEBUG_WITH_RESPONSE = 0x12,
	SECURESERVICE_RETRIEVE_MAILBOX = 0x13,
	SECURESERVICE_IS_TRUSTLET_RUNNING = 0x14,
	SECURESERVICE_CREATE_SECURE_ALLOCATION = 0x15,
	SECURESERVICE_FILL_SECURE_ALLOCATION = 0x16,
	SECURESERVICE_MAKE_CODE_CATALOG = 0x17,
	SECURESERVICE_CREATE_SECURE_IMAGE = 0x18,
	SECURESERVICE_FINALIZE_SECURE_IMAGE_HASH = 0x19,
	SECURESERVICE_FINISH_SECURE_IMAGE_VALIDATION = 0x1a,
	SECURESERVICE_PREPARE_IMAGE_RELOCATIONS = 0x1b,
	SECURESERVICE_RELOCATE_IMAGE = 0x1c,
	SECURESERVICE_CLOSE_SECURE_HANDLE = 0x1d,
	SECURESERVICE_VALIDATE_DYNAMIC_CODE = 0x1e,
	SECURESERVICE_TRANSFER_IMAGE_VERSION_RESOURCE = 0x1f,
	SECURESERVICE_SET_CODE_INTEGRITY_POLICY = 0x20,
	SECURESERVICE_EXCHANGE_ENTROPY = 0x21,
	SECURESERVICE_ALLOCATE_HIBERNATE_RESOURCES = 0x22,
	SECURESERVICE_FREE_HIBERNATE_RESOURCES = 0x23,
	SECURESERVICE_CONFIGURE_DYNAMIC_MEMORY = 0x24,
	SECURESERVICE_DEBUG_PROTECT_MEMORY = 0x25,
	SECURESERVICE_DEBUG_READ_WRITE_MEMORY = 0x26,
	SECURESERVICE_QUERY_VIRTUAL_MEMORY = 0x27,
	SECURESERVICE_CREATE_ENCLAVE = 0x28,
	SECURESERVICE_LOAD_ENCLAVE_MODULE = 0x29,
	SECURESERVICE_INITIALIZE_ENCLAVE = 0x2a,
	SECURESERVICE_TERMINATE_ENCLAVE = 0x2b,
	SECURESERVICE_DELETE_ENCLAVE = 0x2c,
	SECURESERVICE_CONNECT_SW_INTERRUPT = 0x2d,
	SECURESERVICE_RELAX_HYPERGUARD_QUOTA = 0x2e,
	SECURESERVICE_LIVEDUMP_QUERY_SECONDARYDATA_SIZE = 0x2f,
	SECURESERVICE_LIVEDUMP_START = 0x30,
	SECURESERVICE_LIVEDUMP_ADD_BUFFER = 0x31,
	SECURESERVICE_LIVEDUMP_SETUP_BUFFER = 0x32,
	SECURESERVICE_LIVEDUMP_FINALIZE = 0x33,
	SECURESERVICE_LIVEDUMP_ABORT = 0x34,
	SECURESERVICE_LIVEDUMP_CAPTURE_PROCESS = 0x35,
	SECURESERVICE_NOTIFY_POWER_STATE = 0x36,
	SECURESERVICE_QUERY_PROFILE_INFORMATION = 0x37,
	SECURESERVICE_UPDATE_FREEZE_BIAS = 0x38,
	SECURESERVICE_CREATE_SECURE_SECTION = 0x39,
	SECURESERVICE_DELETE_SECURE_SECTION = 0x3a,
	SECURESERVICE_QUERY_SECURE_DEVICE = 0x3b,
	SECURESERVICE_UNPROTECT_SECURE_DEVICE = 0x3c,
	SECURESERVICE_FIND_HOT_PATCH_BASE = 0x3d,
	SECURESERVICE_APPLY_HOT_PATCH = 0x3e,
	SECURESERVICE_PROVISION_DUMP_KEYS = 0x3f,
	SECURESERVICE_NO_TRACING_FIRST = 0xbf,
	SECURESERVICE_GET_PEB_ADDRESS = 0xc0,
	SECURESERVICE_VALIDATE_SECURE_IMAGE_PAGES = 0xc1,
	SECURESERVICE_PRE_INIT_FIRST = 0xcf,
	SECURESERVICE_PHASE3_INIT = 0xd0,
	SECURESERVICE_PERIODIC = 0xd1,
	SECURESERVICE_RESERVE_PROTECTED_PAGES = 0xd2,
	SECURESERVICE_APPLY_DYNAMIC_RELOCATIONS = 0xd3,
	SECURESERVICE_ETW_ENABLE_CALLBACK = 0xd4,
	SECURESERVICE_INITIALIZE_KERNEL_CFG = 0xd5,
	SECURESERVICE_LOAD_DRIVER = 0xd6,
	SECURESERVICE_UNLOAD_DRIVER = 0xd7,
	SECURESERVICE_RELOCATE_BOOT_DRIVER = 0xd8,
	SECURESERVICE_ENABLE_CFG_TARGET = 0xd9,
	SECURESERVICE_DISPATCH_LEVEL_FIRST = 0xdf,
	SECURESERVICE_FLUSH_ADDRESS_SPACE = 0xe0,
	SECURESERVICE_FAST_FLUSH_RANGE_LIST = 0xe1,
	SECURESERVICE_SLOW_FLUSH_RANGE_LIST = 0xe2,
	SECURESERVICE_REMOVE_PROTECTED_PAGE = 0xe3,
	SECURESERVICE_COPY_PROTECTED_PAGE = 0xe4,
	SECURESERVICE_REGISTER_PROTECTED_PAGE = 0xe5,
	SECURESERVICE_MAKE_PROTECTED_PAGE_WRITABLE = 0xe6,
	SECURESERVICE_MAKE_PROTECTED_PAGE_EXECUTABLE = 0xe7,
	SECURESERVICE_QUERY_STRONG_CODE_FEATURES = 0xe8,
	SECURESERVICE_INVOKE_EFI_RUNTIME_SERVICE = 0xe9,
	SECURESERVICE_LIVEDUMP_COLLECT_LIVE_DUMP = 0xea,
	SECURESERVICE_REGISTER_LOG_PAGES = 0xeb,
	SECURESERVICE_RECLAIM_PARTITION_PAGES = 0xec,
	SECURESERVICE_VERIFY_PAGE = 0xed,
	SECURESERVICE_PREPARE_FOR_HIBERNATION = 0xee,
	SECURESERVICE_PREPARE_FOR_CRASHDUMP = 0xef,
	SECURESERVICE_REPORT_BUGCHECK_PROGRESS = 0xf0,
	SECURESERVICE_SHUTDOWN = 0xf1,
	SECURESERVICE_QUERY_SECURE_PCI_INFO = 0xf2,
	SECURESERVICE_ACCESS_PCI_DEVICE = 0xf3,
	SECURESERVICE_REINITIALIZE_DEBUGGER_TRANSPORT = 0xf4,
	SECURESERVICE_KSR_CALL = 0xf5,
	SECURESERVICE_BUGCHECK = 0x700,
	SECURESERVICE_LIMITED_MODE_SERVICE_START = 0x800
};

struct _SK_CRASH_MINIDUMP {
	/*0000*/ ULONG Size;
	/*0004*/ ULONG Version;
	/*0008*/ ULONG ModuleCount;
	/*000c*/ ULONG FrameCount;
	/*0010*/ _SK_CRASH_MODULE Modules[0x10];
	/*0490*/ _SK_CRASH_STACK_FRAME StackFrames[0x16e];
	/*1000*/
};

struct _SK_CRASH_MODULE {
	/*0000*/ WCHAR ImageName[0x20];
	/*0040*/ ULONG SizeOfImage;
	/*0044*/ ULONG TimeDateStamp;
	/*0048*/
};

struct _SK_CRASH_STACK_FRAME {
	/*0000*/ ULONG ModuleId;
	/*0004*/ ULONG Rva;
	/*0000*/ ULONGLONG Pc;
	/*0008*/
};

struct _SLIST_ENTRY {
	/*0000*/ _SLIST_ENTRY * Next;
	/*0010*/
};

union _SLIST_HEADER {
	/*0000*/ ULONGLONG Alignment;
	/*0008*/ ULONGLONG Region;
	struct {
		/*0000*/ ULONGLONG Depth : 16; // 0x000000000000ffff;
		/*0000*/ ULONGLONG Sequence : 48; // 0xffffffffffff0000;
		/*0008*/ ULONGLONG Reserved : 04; // 0x000000000000000f;
		/*0008*/ ULONGLONG NextEntry : 60; // 0xfffffffffffffff0;
		/*0010*/
	} HeaderX64;
	/*0010*/
};

struct _STACK_TABLE {
	/*0000*/ USHORT NumStackTraces;
	/*0002*/ USHORT TraceCapacity;
	/*0008*/ _OBJECT_REF_TRACE * StackTrace[0x10];
	/*0088*/ USHORT StackTableHash[0x3ffd];
	/*8088*/
};

struct _STRING {
	/*0000*/ USHORT Length;
	/*0002*/ USHORT MaximumLength;
	/*0008*/ CHAR * Buffer;
	/*0010*/
};

struct _STRING32 {
	/*0000*/ USHORT Length;
	/*0002*/ USHORT MaximumLength;
	/*0004*/ ULONG Buffer;
	/*0008*/
};

struct _STRING64 {
	/*0000*/ USHORT Length;
	/*0002*/ USHORT MaximumLength;
	/*0008*/ ULONGLONG Buffer;
	/*0010*/
};

struct _SUBSECTION {
	/*0000*/ _CONTROL_AREA * ControlArea;
	/*0008*/ _MMPTE * SubsectionBase;
	/*0010*/ _SUBSECTION * NextSubsection;
	/*0018*/ _RTL_AVL_TREE GlobalPerSessionHead;
	/*0018*/ _MI_CONTROL_AREA_WAIT_BLOCK * CreationWaitList;
	/*0018*/ _MI_PER_SESSION_PROTOS * SessionDriverProtos;
	union {
		/*0020*/ ULONG LongFlags;
		/*0020*/ _MMSUBSECTION_FLAGS SubsectionFlags;
		/*0024*/
	} u;
	/*0024*/ ULONG StartingSector;
	/*0028*/ ULONG NumberOfFullSectors;
	/*002c*/ ULONG PtesInSubsection;
	union {
		/*0030*/ _MI_SUBSECTION_ENTRY1 e1;
		/*0030*/ ULONG EntireField;
		/*0034*/
	} u1;
	/*0034*/ ULONG UnusedPtes : 30; // 0x3fffffff;
	/*0034*/ ULONG ExtentQueryNeeded : 01; // 0x40000000;
	/*0034*/ ULONG DirtyPages : 01; // 0x80000000;
	struct {
		/*0034*/ ULONG AlignmentNoAccessPtes : 31; // 0x7fffffff;
		/*0034*/ ULONG DirtyPages : 01; // 0x80000000;
		/*0038*/
	} u2;
	/*0038*/
};

struct _SYNCH_COUNTERS {
	/*0000*/ ULONG SpinLockAcquireCount;
	/*0004*/ ULONG SpinLockContentionCount;
	/*0008*/ ULONG SpinLockSpinCount;
	/*000c*/ ULONG IpiSendRequestBroadcastCount;
	/*0010*/ ULONG IpiSendRequestRoutineCount;
	/*0014*/ ULONG IpiSendSoftwareInterruptCount;
	/*0018*/ ULONG ExInitializeResourceCount;
	/*001c*/ ULONG ExReInitializeResourceCount;
	/*0020*/ ULONG ExDeleteResourceCount;
	/*0024*/ ULONG ExecutiveResourceAcquiresCount;
	/*0028*/ ULONG ExecutiveResourceContentionsCount;
	/*002c*/ ULONG ExecutiveResourceReleaseExclusiveCount;
	/*0030*/ ULONG ExecutiveResourceReleaseSharedCount;
	/*0034*/ ULONG ExecutiveResourceConvertsCount;
	/*0038*/ ULONG ExAcqResExclusiveAttempts;
	/*003c*/ ULONG ExAcqResExclusiveAcquiresExclusive;
	/*0040*/ ULONG ExAcqResExclusiveAcquiresExclusiveRecursive;
	/*0044*/ ULONG ExAcqResExclusiveWaits;
	/*0048*/ ULONG ExAcqResExclusiveNotAcquires;
	/*004c*/ ULONG ExAcqResSharedAttempts;
	/*0050*/ ULONG ExAcqResSharedAcquiresExclusive;
	/*0054*/ ULONG ExAcqResSharedAcquiresShared;
	/*0058*/ ULONG ExAcqResSharedAcquiresSharedRecursive;
	/*005c*/ ULONG ExAcqResSharedWaits;
	/*0060*/ ULONG ExAcqResSharedNotAcquires;
	/*0064*/ ULONG ExAcqResSharedStarveExclusiveAttempts;
	/*0068*/ ULONG ExAcqResSharedStarveExclusiveAcquiresExclusive;
	/*006c*/ ULONG ExAcqResSharedStarveExclusiveAcquiresShared;
	/*0070*/ ULONG ExAcqResSharedStarveExclusiveAcquiresSharedRecursive;
	/*0074*/ ULONG ExAcqResSharedStarveExclusiveWaits;
	/*0078*/ ULONG ExAcqResSharedStarveExclusiveNotAcquires;
	/*007c*/ ULONG ExAcqResSharedWaitForExclusiveAttempts;
	/*0080*/ ULONG ExAcqResSharedWaitForExclusiveAcquiresExclusive;
	/*0084*/ ULONG ExAcqResSharedWaitForExclusiveAcquiresShared;
	/*0088*/ ULONG ExAcqResSharedWaitForExclusiveAcquiresSharedRecursive;
	/*008c*/ ULONG ExAcqResSharedWaitForExclusiveWaits;
	/*0090*/ ULONG ExAcqResSharedWaitForExclusiveNotAcquires;
	/*0094*/ ULONG ExSetResOwnerPointerExclusive;
	/*0098*/ ULONG ExSetResOwnerPointerSharedNew;
	/*009c*/ ULONG ExSetResOwnerPointerSharedOld;
	/*00a0*/ ULONG ExTryToAcqExclusiveAttempts;
	/*00a4*/ ULONG ExTryToAcqExclusiveAcquires;
	/*00a8*/ ULONG ExBoostExclusiveOwner;
	/*00ac*/ ULONG ExBoostSharedOwners;
	/*00b0*/ ULONG ExEtwSynchTrackingNotificationsCount;
	/*00b4*/ ULONG ExEtwSynchTrackingNotificationsAccountedCount;
	/*00b8*/
};

struct _SYSPTES_HEADER {
	/*0000*/ _LIST_ENTRY ListHead[0x10];
	/*0100*/ ULONGLONG Count;
	/*0108*/ ULONGLONG NumberOfEntries;
	/*0110*/ ULONGLONG NumberOfEntriesPeak;
	/*0118*/
};

enum _SYSTEM_DLL_TYPE {
	PsNativeSystemDll = 0x0,
	PsWowX86SystemDll = 0x1,
	PsWowArm32SystemDll = 0x2,
	PsWowAmd64SystemDll = 0x3,
	PsWowChpeX86SystemDll = 0x4,
	PsVsmEnclaveRuntimeDll = 0x5,
	PsSystemDllTotalTypes = 0x6
};

struct _SYSTEM_POWER_POLICY {
	/*0000*/ ULONG Revision;
	/*0004*/ POWER_ACTION_POLICY PowerButton;
	/*0010*/ POWER_ACTION_POLICY SleepButton;
	/*001c*/ POWER_ACTION_POLICY LidClose;
	/*0028*/ _SYSTEM_POWER_STATE LidOpenWake;
	/*002c*/ ULONG Reserved;
	/*0030*/ POWER_ACTION_POLICY Idle;
	/*003c*/ ULONG IdleTimeout;
	/*0040*/ UCHAR IdleSensitivity;
	/*0041*/ UCHAR DynamicThrottle;
	/*0042*/ UCHAR Spare2[0x2];
	/*0044*/ _SYSTEM_POWER_STATE MinSleep;
	/*0048*/ _SYSTEM_POWER_STATE MaxSleep;
	/*004c*/ _SYSTEM_POWER_STATE ReducedLatencySleep;
	/*0050*/ ULONG WinLogonFlags;
	/*0054*/ ULONG Spare3;
	/*0058*/ ULONG DozeS4Timeout;
	/*005c*/ ULONG BroadcastCapacityResolution;
	/*0060*/ SYSTEM_POWER_LEVEL DischargePolicy[0x4];
	/*00c0*/ ULONG VideoTimeout;
	/*00c4*/ UCHAR VideoDimDisplay;
	/*00c8*/ ULONG VideoReserved[0x3];
	/*00d4*/ ULONG SpindownTimeout;
	/*00d8*/ UCHAR OptimizeForPower;
	/*00d9*/ UCHAR FanThrottleTolerance;
	/*00da*/ UCHAR ForcedThrottle;
	/*00db*/ UCHAR MinThrottle;
	/*00dc*/ POWER_ACTION_POLICY OverThrottled;
	/*00e8*/
};

enum _SYSTEM_POWER_STATE {
	PowerSystemUnspecified = 0x0,
	PowerSystemWorking = 0x1,
	PowerSystemSleeping1 = 0x2,
	PowerSystemSleeping2 = 0x3,
	PowerSystemSleeping3 = 0x4,
	PowerSystemHibernate = 0x5,
	PowerSystemShutdown = 0x6,
	PowerSystemMaximum = 0x7
};

struct _SYSTEM_POWER_STATE_CONTEXT {
	/*0000*/ ULONG Reserved1 : 08; // 0x000000ff;
	/*0000*/ ULONG TargetSystemState : 04; // 0x00000f00;
	/*0000*/ ULONG EffectiveSystemState : 04; // 0x0000f000;
	/*0000*/ ULONG CurrentSystemState : 04; // 0x000f0000;
	/*0000*/ ULONG IgnoreHibernationPath : 01; // 0x00100000;
	/*0000*/ ULONG PseudoTransition : 01; // 0x00200000;
	/*0000*/ ULONG KernelSoftReboot : 01; // 0x00400000;
	/*0000*/ ULONG Reserved2 : 09; // 0xff800000;
	/*0000*/ ULONG ContextAsUlong;
	/*0004*/
};

struct _TEB {
	/*0000*/ _NT_TIB NtTib;
	/*0038*/ void * EnvironmentPointer;
	/*0040*/ _CLIENT_ID ClientId;
	/*0050*/ void * ActiveRpcHandle;
	/*0058*/ void * ThreadLocalStoragePointer;
	/*0060*/ _PEB * ProcessEnvironmentBlock;
	/*0068*/ ULONG LastErrorValue;
	/*006c*/ ULONG CountOfOwnedCriticalSections;
	/*0070*/ void * CsrClientThread;
	/*0078*/ void * Win32ThreadInfo;
	/*0080*/ ULONG User32Reserved[0x1a];
	/*00e8*/ ULONG UserReserved[0x5];
	/*0100*/ void * WOW32Reserved;
	/*0108*/ ULONG CurrentLocale;
	/*010c*/ ULONG FpSoftwareStatusRegister;
	/*0110*/ void * ReservedForDebuggerInstrumentation[0x10];
	/*0190*/ void * SystemReserved1[0x1e];
	/*0280*/ CHAR PlaceholderCompatibilityMode;
	/*0281*/ CHAR PlaceholderReserved[0xb];
	/*028c*/ ULONG ProxiedProcessId;
	/*0290*/ _ACTIVATION_CONTEXT_STACK _ActivationStack;
	/*02b8*/ UCHAR WorkingOnBehalfTicket[0x8];
	/*02c0*/ LONG ExceptionCode;
	/*02c4*/ UCHAR Padding0[0x4];
	/*02c8*/ _ACTIVATION_CONTEXT_STACK * ActivationContextStackPointer;
	/*02d0*/ ULONGLONG InstrumentationCallbackSp;
	/*02d8*/ ULONGLONG InstrumentationCallbackPreviousPc;
	/*02e0*/ ULONGLONG InstrumentationCallbackPreviousSp;
	/*02e8*/ ULONG TxFsContext;
	/*02ec*/ UCHAR InstrumentationCallbackDisabled;
	/*02ed*/ UCHAR Padding1[0x3];
	/*02f0*/ _GDI_TEB_BATCH GdiTebBatch;
	/*07d8*/ _CLIENT_ID RealClientId;
	/*07e8*/ void * GdiCachedProcessHandle;
	/*07f0*/ ULONG GdiClientPID;
	/*07f4*/ ULONG GdiClientTID;
	/*07f8*/ void * GdiThreadLocalInfo;
	/*0800*/ ULONGLONG Win32ClientInfo[0x3e];
	/*09f0*/ void * glDispatchTable[0xe9];
	/*1138*/ ULONGLONG glReserved1[0x1d];
	/*1220*/ void * glReserved2;
	/*1228*/ void * glSectionInfo;
	/*1230*/ void * glSection;
	/*1238*/ void * glTable;
	/*1240*/ void * glCurrentRC;
	/*1248*/ void * glContext;
	/*1250*/ ULONG LastStatusValue;
	/*1254*/ UCHAR Padding2[0x4];
	/*1258*/ _UNICODE_STRING StaticUnicodeString;
	/*1268*/ WCHAR StaticUnicodeBuffer[0x105];
	/*1472*/ UCHAR Padding3[0x6];
	/*1478*/ void * DeallocationStack;
	/*1480*/ void * TlsSlots[0x40];
	/*1680*/ _LIST_ENTRY TlsLinks;
	/*1690*/ void * Vdm;
	/*1698*/ void * ReservedForNtRpc;
	/*16a0*/ void * DbgSsReserved[0x2];
	/*16b0*/ ULONG HardErrorMode;
	/*16b4*/ UCHAR Padding4[0x4];
	/*16b8*/ void * Instrumentation[0xb];
	/*1710*/ _GUID ActivityId;
	/*1720*/ void * SubProcessTag;
	/*1728*/ void * PerflibData;
	/*1730*/ void * EtwTraceData;
	/*1738*/ void * WinSockData;
	/*1740*/ ULONG GdiBatchCount;
	/*1744*/ _PROCESSOR_NUMBER CurrentIdealProcessor;
	/*1744*/ ULONG IdealProcessorValue;
	/*1744*/ UCHAR ReservedPad0;
	/*1745*/ UCHAR ReservedPad1;
	/*1746*/ UCHAR ReservedPad2;
	/*1747*/ UCHAR IdealProcessor;
	/*1748*/ ULONG GuaranteedStackBytes;
	/*174c*/ UCHAR Padding5[0x4];
	/*1750*/ void * ReservedForPerf;
	/*1758*/ void * ReservedForOle;
	/*1760*/ ULONG WaitingOnLoaderLock;
	/*1764*/ UCHAR Padding6[0x4];
	/*1768*/ void * SavedPriorityState;
	/*1770*/ ULONGLONG ReservedForCodeCoverage;
	/*1778*/ void * ThreadPoolData;
	/*1780*/ void * * TlsExpansionSlots;
	/*1788*/ void * DeallocationBStore;
	/*1790*/ void * BStoreLimit;
	/*1798*/ ULONG MuiGeneration;
	/*179c*/ ULONG IsImpersonating;
	/*17a0*/ void * NlsCache;
	/*17a8*/ void * pShimData;
	/*17b0*/ USHORT HeapVirtualAffinity;
	/*17b2*/ USHORT LowFragHeapDataSlot;
	/*17b4*/ UCHAR Padding7[0x4];
	/*17b8*/ void * CurrentTransactionHandle;
	/*17c0*/ _TEB_ACTIVE_FRAME * ActiveFrame;
	/*17c8*/ void * FlsData;
	/*17d0*/ void * PreferredLanguages;
	/*17d8*/ void * UserPrefLanguages;
	/*17e0*/ void * MergedPrefLanguages;
	/*17e8*/ ULONG MuiImpersonation;
	/*17ec*/ USHORT volatile CrossTebFlags;
	/*17ec*/ USHORT SpareCrossTebBits : 16; // 0xffff;
	/*17ee*/ USHORT SameTebFlags;
	/*17ee*/ USHORT SafeThunkCall : 01; // 0x0001;
	/*17ee*/ USHORT InDebugPrint : 01; // 0x0002;
	/*17ee*/ USHORT HasFiberData : 01; // 0x0004;
	/*17ee*/ USHORT SkipThreadAttach : 01; // 0x0008;
	/*17ee*/ USHORT WerInShipAssertCode : 01; // 0x0010;
	/*17ee*/ USHORT RanProcessInit : 01; // 0x0020;
	/*17ee*/ USHORT ClonedThread : 01; // 0x0040;
	/*17ee*/ USHORT SuppressDebugMsg : 01; // 0x0080;
	/*17ee*/ USHORT DisableUserStackWalk : 01; // 0x0100;
	/*17ee*/ USHORT RtlExceptionAttached : 01; // 0x0200;
	/*17ee*/ USHORT InitialThread : 01; // 0x0400;
	/*17ee*/ USHORT SessionAware : 01; // 0x0800;
	/*17ee*/ USHORT LoadOwner : 01; // 0x1000;
	/*17ee*/ USHORT LoaderWorker : 01; // 0x2000;
	/*17ee*/ USHORT SkipLoaderInit : 01; // 0x4000;
	/*17ee*/ USHORT SpareSameTebBits : 01; // 0x8000;
	/*17f0*/ void * TxnScopeEnterCallback;
	/*17f8*/ void * TxnScopeExitCallback;
	/*1800*/ void * TxnScopeContext;
	/*1808*/ ULONG LockCount;
	/*180c*/ LONG WowTebOffset;
	/*1810*/ void * ResourceRetValue;
	/*1818*/ void * ReservedForWdf;
	/*1820*/ ULONGLONG ReservedForCrt;
	/*1828*/ _GUID EffectiveContainerId;
	/*1838*/
};

struct _TEB32 {
	/*0000*/ _NT_TIB32 NtTib;
	/*001c*/ ULONG EnvironmentPointer;
	/*0020*/ _CLIENT_ID32 ClientId;
	/*0028*/ ULONG ActiveRpcHandle;
	/*002c*/ ULONG ThreadLocalStoragePointer;
	/*0030*/ ULONG ProcessEnvironmentBlock;
	/*0034*/ ULONG LastErrorValue;
	/*0038*/ ULONG CountOfOwnedCriticalSections;
	/*003c*/ ULONG CsrClientThread;
	/*0040*/ ULONG Win32ThreadInfo;
	/*0044*/ ULONG User32Reserved[0x1a];
	/*00ac*/ ULONG UserReserved[0x5];
	/*00c0*/ ULONG WOW32Reserved;
	/*00c4*/ ULONG CurrentLocale;
	/*00c8*/ ULONG FpSoftwareStatusRegister;
	/*00cc*/ ULONG ReservedForDebuggerInstrumentation[0x10];
	/*010c*/ ULONG SystemReserved1[0x1a];
	/*0174*/ CHAR PlaceholderCompatibilityMode;
	/*0175*/ CHAR PlaceholderReserved[0xb];
	/*0180*/ ULONG ProxiedProcessId;
	/*0184*/ _ACTIVATION_CONTEXT_STACK32 _ActivationStack;
	/*019c*/ UCHAR WorkingOnBehalfTicket[0x8];
	/*01a4*/ LONG ExceptionCode;
	/*01a8*/ ULONG ActivationContextStackPointer;
	/*01ac*/ ULONG InstrumentationCallbackSp;
	/*01b0*/ ULONG InstrumentationCallbackPreviousPc;
	/*01b4*/ ULONG InstrumentationCallbackPreviousSp;
	/*01b8*/ UCHAR InstrumentationCallbackDisabled;
	/*01b9*/ UCHAR SpareBytes[0x17];
	/*01d0*/ ULONG TxFsContext;
	/*01d4*/ _GDI_TEB_BATCH32 GdiTebBatch;
	/*06b4*/ _CLIENT_ID32 RealClientId;
	/*06bc*/ ULONG GdiCachedProcessHandle;
	/*06c0*/ ULONG GdiClientPID;
	/*06c4*/ ULONG GdiClientTID;
	/*06c8*/ ULONG GdiThreadLocalInfo;
	/*06cc*/ ULONG Win32ClientInfo[0x3e];
	/*07c4*/ ULONG glDispatchTable[0xe9];
	/*0b68*/ ULONG glReserved1[0x1d];
	/*0bdc*/ ULONG glReserved2;
	/*0be0*/ ULONG glSectionInfo;
	/*0be4*/ ULONG glSection;
	/*0be8*/ ULONG glTable;
	/*0bec*/ ULONG glCurrentRC;
	/*0bf0*/ ULONG glContext;
	/*0bf4*/ ULONG LastStatusValue;
	/*0bf8*/ _STRING32 StaticUnicodeString;
	/*0c00*/ WCHAR StaticUnicodeBuffer[0x105];
	/*0e0c*/ ULONG DeallocationStack;
	/*0e10*/ ULONG TlsSlots[0x40];
	/*0f10*/ LIST_ENTRY32 TlsLinks;
	/*0f18*/ ULONG Vdm;
	/*0f1c*/ ULONG ReservedForNtRpc;
	/*0f20*/ ULONG DbgSsReserved[0x2];
	/*0f28*/ ULONG HardErrorMode;
	/*0f2c*/ ULONG Instrumentation[0x9];
	/*0f50*/ _GUID ActivityId;
	/*0f60*/ ULONG SubProcessTag;
	/*0f64*/ ULONG PerflibData;
	/*0f68*/ ULONG EtwTraceData;
	/*0f6c*/ ULONG WinSockData;
	/*0f70*/ ULONG GdiBatchCount;
	/*0f74*/ _PROCESSOR_NUMBER CurrentIdealProcessor;
	/*0f74*/ ULONG IdealProcessorValue;
	/*0f74*/ UCHAR ReservedPad0;
	/*0f75*/ UCHAR ReservedPad1;
	/*0f76*/ UCHAR ReservedPad2;
	/*0f77*/ UCHAR IdealProcessor;
	/*0f78*/ ULONG GuaranteedStackBytes;
	/*0f7c*/ ULONG ReservedForPerf;
	/*0f80*/ ULONG ReservedForOle;
	/*0f84*/ ULONG WaitingOnLoaderLock;
	/*0f88*/ ULONG SavedPriorityState;
	/*0f8c*/ ULONG ReservedForCodeCoverage;
	/*0f90*/ ULONG ThreadPoolData;
	/*0f94*/ ULONG TlsExpansionSlots;
	/*0f98*/ ULONG MuiGeneration;
	/*0f9c*/ ULONG IsImpersonating;
	/*0fa0*/ ULONG NlsCache;
	/*0fa4*/ ULONG pShimData;
	/*0fa8*/ USHORT HeapVirtualAffinity;
	/*0faa*/ USHORT LowFragHeapDataSlot;
	/*0fac*/ ULONG CurrentTransactionHandle;
	/*0fb0*/ ULONG ActiveFrame;
	/*0fb4*/ ULONG FlsData;
	/*0fb8*/ ULONG PreferredLanguages;
	/*0fbc*/ ULONG UserPrefLanguages;
	/*0fc0*/ ULONG MergedPrefLanguages;
	/*0fc4*/ ULONG MuiImpersonation;
	/*0fc8*/ USHORT volatile CrossTebFlags;
	/*0fc8*/ USHORT SpareCrossTebBits : 16; // 0xffff;
	/*0fca*/ USHORT SameTebFlags;
	/*0fca*/ USHORT SafeThunkCall : 01; // 0x0001;
	/*0fca*/ USHORT InDebugPrint : 01; // 0x0002;
	/*0fca*/ USHORT HasFiberData : 01; // 0x0004;
	/*0fca*/ USHORT SkipThreadAttach : 01; // 0x0008;
	/*0fca*/ USHORT WerInShipAssertCode : 01; // 0x0010;
	/*0fca*/ USHORT RanProcessInit : 01; // 0x0020;
	/*0fca*/ USHORT ClonedThread : 01; // 0x0040;
	/*0fca*/ USHORT SuppressDebugMsg : 01; // 0x0080;
	/*0fca*/ USHORT DisableUserStackWalk : 01; // 0x0100;
	/*0fca*/ USHORT RtlExceptionAttached : 01; // 0x0200;
	/*0fca*/ USHORT InitialThread : 01; // 0x0400;
	/*0fca*/ USHORT SessionAware : 01; // 0x0800;
	/*0fca*/ USHORT LoadOwner : 01; // 0x1000;
	/*0fca*/ USHORT LoaderWorker : 01; // 0x2000;
	/*0fca*/ USHORT SkipLoaderInit : 01; // 0x4000;
	/*0fca*/ USHORT SpareSameTebBits : 01; // 0x8000;
	/*0fcc*/ ULONG TxnScopeEnterCallback;
	/*0fd0*/ ULONG TxnScopeExitCallback;
	/*0fd4*/ ULONG TxnScopeContext;
	/*0fd8*/ ULONG LockCount;
	/*0fdc*/ LONG WowTebOffset;
	/*0fe0*/ ULONG ResourceRetValue;
	/*0fe4*/ ULONG ReservedForWdf;
	/*0fe8*/ ULONGLONG ReservedForCrt;
	/*0ff0*/ _GUID EffectiveContainerId;
	/*1000*/
};

struct _TEB64 {
	/*0000*/ _NT_TIB64 NtTib;
	/*0038*/ ULONGLONG EnvironmentPointer;
	/*0040*/ _CLIENT_ID64 ClientId;
	/*0050*/ ULONGLONG ActiveRpcHandle;
	/*0058*/ ULONGLONG ThreadLocalStoragePointer;
	/*0060*/ ULONGLONG ProcessEnvironmentBlock;
	/*0068*/ ULONG LastErrorValue;
	/*006c*/ ULONG CountOfOwnedCriticalSections;
	/*0070*/ ULONGLONG CsrClientThread;
	/*0078*/ ULONGLONG Win32ThreadInfo;
	/*0080*/ ULONG User32Reserved[0x1a];
	/*00e8*/ ULONG UserReserved[0x5];
	/*0100*/ ULONGLONG WOW32Reserved;
	/*0108*/ ULONG CurrentLocale;
	/*010c*/ ULONG FpSoftwareStatusRegister;
	/*0110*/ ULONGLONG ReservedForDebuggerInstrumentation[0x10];
	/*0190*/ ULONGLONG SystemReserved1[0x1e];
	/*0280*/ CHAR PlaceholderCompatibilityMode;
	/*0281*/ CHAR PlaceholderReserved[0xb];
	/*028c*/ ULONG ProxiedProcessId;
	/*0290*/ _ACTIVATION_CONTEXT_STACK64 _ActivationStack;
	/*02b8*/ UCHAR WorkingOnBehalfTicket[0x8];
	/*02c0*/ LONG ExceptionCode;
	/*02c4*/ UCHAR Padding0[0x4];
	/*02c8*/ ULONGLONG ActivationContextStackPointer;
	/*02d0*/ ULONGLONG InstrumentationCallbackSp;
	/*02d8*/ ULONGLONG InstrumentationCallbackPreviousPc;
	/*02e0*/ ULONGLONG InstrumentationCallbackPreviousSp;
	/*02e8*/ ULONG TxFsContext;
	/*02ec*/ UCHAR InstrumentationCallbackDisabled;
	/*02ed*/ UCHAR Padding1[0x3];
	/*02f0*/ _GDI_TEB_BATCH64 GdiTebBatch;
	/*07d8*/ _CLIENT_ID64 RealClientId;
	/*07e8*/ ULONGLONG GdiCachedProcessHandle;
	/*07f0*/ ULONG GdiClientPID;
	/*07f4*/ ULONG GdiClientTID;
	/*07f8*/ ULONGLONG GdiThreadLocalInfo;
	/*0800*/ ULONGLONG Win32ClientInfo[0x3e];
	/*09f0*/ ULONGLONG glDispatchTable[0xe9];
	/*1138*/ ULONGLONG glReserved1[0x1d];
	/*1220*/ ULONGLONG glReserved2;
	/*1228*/ ULONGLONG glSectionInfo;
	/*1230*/ ULONGLONG glSection;
	/*1238*/ ULONGLONG glTable;
	/*1240*/ ULONGLONG glCurrentRC;
	/*1248*/ ULONGLONG glContext;
	/*1250*/ ULONG LastStatusValue;
	/*1254*/ UCHAR Padding2[0x4];
	/*1258*/ _STRING64 StaticUnicodeString;
	/*1268*/ WCHAR StaticUnicodeBuffer[0x105];
	/*1472*/ UCHAR Padding3[0x6];
	/*1478*/ ULONGLONG DeallocationStack;
	/*1480*/ ULONGLONG TlsSlots[0x40];
	/*1680*/ LIST_ENTRY64 TlsLinks;
	/*1690*/ ULONGLONG Vdm;
	/*1698*/ ULONGLONG ReservedForNtRpc;
	/*16a0*/ ULONGLONG DbgSsReserved[0x2];
	/*16b0*/ ULONG HardErrorMode;
	/*16b4*/ UCHAR Padding4[0x4];
	/*16b8*/ ULONGLONG Instrumentation[0xb];
	/*1710*/ _GUID ActivityId;
	/*1720*/ ULONGLONG SubProcessTag;
	/*1728*/ ULONGLONG PerflibData;
	/*1730*/ ULONGLONG EtwTraceData;
	/*1738*/ ULONGLONG WinSockData;
	/*1740*/ ULONG GdiBatchCount;
	/*1744*/ _PROCESSOR_NUMBER CurrentIdealProcessor;
	/*1744*/ ULONG IdealProcessorValue;
	/*1744*/ UCHAR ReservedPad0;
	/*1745*/ UCHAR ReservedPad1;
	/*1746*/ UCHAR ReservedPad2;
	/*1747*/ UCHAR IdealProcessor;
	/*1748*/ ULONG GuaranteedStackBytes;
	/*174c*/ UCHAR Padding5[0x4];
	/*1750*/ ULONGLONG ReservedForPerf;
	/*1758*/ ULONGLONG ReservedForOle;
	/*1760*/ ULONG WaitingOnLoaderLock;
	/*1764*/ UCHAR Padding6[0x4];
	/*1768*/ ULONGLONG SavedPriorityState;
	/*1770*/ ULONGLONG ReservedForCodeCoverage;
	/*1778*/ ULONGLONG ThreadPoolData;
	/*1780*/ ULONGLONG TlsExpansionSlots;
	/*1788*/ ULONGLONG DeallocationBStore;
	/*1790*/ ULONGLONG BStoreLimit;
	/*1798*/ ULONG MuiGeneration;
	/*179c*/ ULONG IsImpersonating;
	/*17a0*/ ULONGLONG NlsCache;
	/*17a8*/ ULONGLONG pShimData;
	/*17b0*/ USHORT HeapVirtualAffinity;
	/*17b2*/ USHORT LowFragHeapDataSlot;
	/*17b4*/ UCHAR Padding7[0x4];
	/*17b8*/ ULONGLONG CurrentTransactionHandle;
	/*17c0*/ ULONGLONG ActiveFrame;
	/*17c8*/ ULONGLONG FlsData;
	/*17d0*/ ULONGLONG PreferredLanguages;
	/*17d8*/ ULONGLONG UserPrefLanguages;
	/*17e0*/ ULONGLONG MergedPrefLanguages;
	/*17e8*/ ULONG MuiImpersonation;
	/*17ec*/ USHORT volatile CrossTebFlags;
	/*17ec*/ USHORT SpareCrossTebBits : 16; // 0xffff;
	/*17ee*/ USHORT SameTebFlags;
	/*17ee*/ USHORT SafeThunkCall : 01; // 0x0001;
	/*17ee*/ USHORT InDebugPrint : 01; // 0x0002;
	/*17ee*/ USHORT HasFiberData : 01; // 0x0004;
	/*17ee*/ USHORT SkipThreadAttach : 01; // 0x0008;
	/*17ee*/ USHORT WerInShipAssertCode : 01; // 0x0010;
	/*17ee*/ USHORT RanProcessInit : 01; // 0x0020;
	/*17ee*/ USHORT ClonedThread : 01; // 0x0040;
	/*17ee*/ USHORT SuppressDebugMsg : 01; // 0x0080;
	/*17ee*/ USHORT DisableUserStackWalk : 01; // 0x0100;
	/*17ee*/ USHORT RtlExceptionAttached : 01; // 0x0200;
	/*17ee*/ USHORT InitialThread : 01; // 0x0400;
	/*17ee*/ USHORT SessionAware : 01; // 0x0800;
	/*17ee*/ USHORT LoadOwner : 01; // 0x1000;
	/*17ee*/ USHORT LoaderWorker : 01; // 0x2000;
	/*17ee*/ USHORT SkipLoaderInit : 01; // 0x4000;
	/*17ee*/ USHORT SpareSameTebBits : 01; // 0x8000;
	/*17f0*/ ULONGLONG TxnScopeEnterCallback;
	/*17f8*/ ULONGLONG TxnScopeExitCallback;
	/*1800*/ ULONGLONG TxnScopeContext;
	/*1808*/ ULONG LockCount;
	/*180c*/ LONG WowTebOffset;
	/*1810*/ ULONGLONG ResourceRetValue;
	/*1818*/ ULONGLONG ReservedForWdf;
	/*1820*/ ULONGLONG ReservedForCrt;
	/*1828*/ _GUID EffectiveContainerId;
	/*1838*/
};

struct _TEB_ACTIVE_FRAME {
	/*0000*/ ULONG Flags;
	/*0008*/ _TEB_ACTIVE_FRAME * Previous;
	/*0010*/ _TEB_ACTIVE_FRAME_CONTEXT const * Context;
	/*0018*/
};

struct _TEB_ACTIVE_FRAME_CONTEXT {
	/*0000*/ ULONG Flags;
	/*0008*/ CHAR const * FrameName;
	/*0010*/
};

struct _TERMINATION_PORT {
	/*0000*/ _TERMINATION_PORT * Next;
	/*0008*/ void * Port;
	/*0010*/
};

struct _THERMAL_COOLING_INTERFACE {
	/*0000*/ USHORT Size;
	/*0002*/ USHORT Version;
	/*0008*/ void * Context;
	/*0010*/ void (* InterfaceReference)( void * );
	/*0018*/ void (* InterfaceDereference)( void * );
	/*0020*/ ULONG Flags;
	/*0028*/ void (* ActiveCooling)( void * , UCHAR );
	/*0030*/ void (* PassiveCooling)( void * , ULONG );
	/*0038*/
};

struct _THERMAL_INFORMATION {
	/*0000*/ ULONG ThermalStamp;
	/*0004*/ ULONG ThermalConstant1;
	/*0008*/ ULONG ThermalConstant2;
	/*0010*/ ULONGLONG Processors;
	/*0018*/ ULONG SamplingPeriod;
	/*001c*/ ULONG CurrentTemperature;
	/*0020*/ ULONG PassiveTripPoint;
	/*0024*/ ULONG CriticalTripPoint;
	/*0028*/ UCHAR ActiveTripPointCount;
	/*002c*/ ULONG ActiveTripPoint[0xa];
	/*0058*/
};

struct _THERMAL_INFORMATION_EX {
	/*0000*/ ULONG ThermalStamp;
	/*0004*/ ULONG ThermalConstant1;
	/*0008*/ ULONG ThermalConstant2;
	/*000c*/ ULONG SamplingPeriod;
	/*0010*/ ULONG CurrentTemperature;
	/*0014*/ ULONG PassiveTripPoint;
	/*0018*/ ULONG ThermalStandbyTripPoint;
	/*001c*/ ULONG CriticalTripPoint;
	/*0020*/ UCHAR ActiveTripPointCount;
	/*0024*/ ULONG ActiveTripPoint[0xa];
	/*004c*/ ULONG S4TransitionTripPoint;
	/*0050*/ ULONG MinimumThrottle;
	/*0054*/ ULONG OverThrottleThreshold;
	/*0058*/ ULONG PollingPeriod;
	/*005c*/
};

struct _THERMAL_POLICY {
	/*0000*/ ULONG Version;
	/*0004*/ UCHAR WaitForUpdate;
	/*0005*/ UCHAR Hibernate;
	/*0006*/ UCHAR Critical;
	/*0007*/ UCHAR ThermalStandby;
	/*0008*/ ULONG ActivationReasons;
	/*000c*/ ULONG PassiveLimit;
	/*0010*/ ULONG ActiveLevel;
	/*0014*/ UCHAR OverThrottled;
	/*0018*/
};

struct _THERMAL_ZONE_COUNTERS {
	/*0000*/ ULONG Temperature;
	/*0004*/ ULONG ThrottleLimit;
	/*0008*/ ULONG ThrottleReasons;
	/*000c*/ ULONG TemperatureHighPrecision;
	/*0010*/
};

struct _THREAD_ENERGY_VALUES {
	/*0000*/ ULONGLONG Cycles[0x4][0x2];
	/*0040*/ ULONGLONG AttributedCycles[0x4][0x2];
	/*0080*/ ULONGLONG WorkOnBehalfCycles[0x4][0x2];
	/*00c0*/ _TIMELINE_BITMAP CpuTimeline;
	/*00c8*/
};

struct _THREAD_PERFORMANCE_DATA {
	/*0000*/ USHORT Size;
	/*0002*/ USHORT Version;
	/*0004*/ _PROCESSOR_NUMBER ProcessorNumber;
	/*0008*/ ULONG ContextSwitches;
	/*000c*/ ULONG HwCountersCount;
	/*0010*/ ULONGLONG volatile UpdateCount;
	/*0018*/ ULONGLONG WaitReasonBitMap;
	/*0020*/ ULONGLONG HardwareCounters;
	/*0028*/ _COUNTER_READING CycleTime;
	/*0040*/ _COUNTER_READING HwCounters[0x10];
	/*01c0*/
};

union _TIMELINE_BITMAP {
	/*0000*/ ULONGLONG Value;
	/*0000*/ ULONG EndTime;
	/*0004*/ ULONG Bitmap;
	/*0008*/
};

struct _TIME_FIELDS {
	/*0000*/ SHORT Year;
	/*0002*/ SHORT Month;
	/*0004*/ SHORT Day;
	/*0006*/ SHORT Hour;
	/*0008*/ SHORT Minute;
	/*000a*/ SHORT Second;
	/*000c*/ SHORT Milliseconds;
	/*000e*/ SHORT Weekday;
	/*0010*/
};

struct _TOKEN {
	/*0000*/ _TOKEN_SOURCE TokenSource;
	/*0010*/ _LUID TokenId;
	/*0018*/ _LUID AuthenticationId;
	/*0020*/ _LUID ParentTokenId;
	/*0028*/ _LARGE_INTEGER ExpirationTime;
	/*0030*/ _ERESOURCE * TokenLock;
	/*0038*/ _LUID ModifiedId;
	/*0040*/ _SEP_TOKEN_PRIVILEGES Privileges;
	/*0058*/ _SEP_AUDIT_POLICY AuditPolicy;
	/*0078*/ ULONG SessionId;
	/*007c*/ ULONG UserAndGroupCount;
	/*0080*/ ULONG RestrictedSidCount;
	/*0084*/ ULONG VariableLength;
	/*0088*/ ULONG DynamicCharged;
	/*008c*/ ULONG DynamicAvailable;
	/*0090*/ ULONG DefaultOwnerIndex;
	/*0098*/ _SID_AND_ATTRIBUTES * UserAndGroups;
	/*00a0*/ _SID_AND_ATTRIBUTES * RestrictedSids;
	/*00a8*/ void * PrimaryGroup;
	/*00b0*/ ULONG * DynamicPart;
	/*00b8*/ _ACL * DefaultDacl;
	/*00c0*/ _TOKEN_TYPE TokenType;
	/*00c4*/ _SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
	/*00c8*/ ULONG TokenFlags;
	/*00cc*/ UCHAR TokenInUse;
	/*00d0*/ ULONG IntegrityLevelIndex;
	/*00d4*/ ULONG MandatoryPolicy;
	/*00d8*/ _SEP_LOGON_SESSION_REFERENCES * LogonSession;
	/*00e0*/ _LUID OriginatingLogonSession;
	/*00e8*/ _SID_AND_ATTRIBUTES_HASH SidHash;
	/*01f8*/ _SID_AND_ATTRIBUTES_HASH RestrictedSidHash;
	/*0308*/ _AUTHZBASEP_SECURITY_ATTRIBUTES_INFORMATION * pSecurityAttributes;
	/*0310*/ void * Package;
	/*0318*/ _SID_AND_ATTRIBUTES * Capabilities;
	/*0320*/ ULONG CapabilityCount;
	/*0328*/ _SID_AND_ATTRIBUTES_HASH CapabilitiesHash;
	/*0438*/ _SEP_LOWBOX_NUMBER_ENTRY * LowboxNumberEntry;
	/*0440*/ _SEP_CACHED_HANDLES_ENTRY * LowboxHandlesEntry;
	/*0448*/ _AUTHZBASEP_CLAIM_ATTRIBUTES_COLLECTION * pClaimAttributes;
	/*0450*/ void * TrustLevelSid;
	/*0458*/ _TOKEN * TrustLinkedToken;
	/*0460*/ void * IntegrityLevelSidValue;
	/*0468*/ _SEP_SID_VALUES_BLOCK * TokenSidValues;
	/*0470*/ _SEP_LUID_TO_INDEX_MAP_ENTRY * IndexEntry;
	/*0478*/ _SEP_TOKEN_DIAG_TRACK_ENTRY * DiagnosticInfo;
	/*0480*/ _SEP_CACHED_HANDLES_ENTRY * BnoIsolationHandlesEntry;
	/*0488*/ void * SessionObject;
	/*0490*/ ULONGLONG VariablePart;
	/*0498*/
};

struct _TOKEN_ACCESS_INFORMATION {
	/*0000*/ _SID_AND_ATTRIBUTES_HASH * SidHash;
	/*0008*/ _SID_AND_ATTRIBUTES_HASH * RestrictedSidHash;
	/*0010*/ _TOKEN_PRIVILEGES * Privileges;
	/*0018*/ _LUID AuthenticationId;
	/*0020*/ _TOKEN_TYPE TokenType;
	/*0024*/ _SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
	/*0028*/ _TOKEN_MANDATORY_POLICY MandatoryPolicy;
	/*002c*/ ULONG Flags;
	/*0030*/ ULONG AppContainerNumber;
	/*0038*/ void * PackageSid;
	/*0040*/ _SID_AND_ATTRIBUTES_HASH * CapabilitiesHash;
	/*0048*/ void * TrustLevelSid;
	/*0050*/ void * SecurityAttributes;
	/*0058*/
};

struct _TOKEN_AUDIT_POLICY {
	/*0000*/ UCHAR PerUserPolicy[0x1e];
	/*001e*/
};

struct _TOKEN_CONTROL {
	/*0000*/ _LUID TokenId;
	/*0008*/ _LUID AuthenticationId;
	/*0010*/ _LUID ModifiedId;
	/*0018*/ _TOKEN_SOURCE TokenSource;
	/*0028*/
};

enum _TOKEN_INFORMATION_CLASS {
	TokenUser = 0x1,
	TokenGroups = 0x2,
	TokenPrivileges = 0x3,
	TokenOwner = 0x4,
	TokenPrimaryGroup = 0x5,
	TokenDefaultDacl = 0x6,
	TokenSource = 0x7,
	TokenType = 0x8,
	TokenImpersonationLevel = 0x9,
	TokenStatistics = 0xa,
	TokenRestrictedSids = 0xb,
	TokenSessionId = 0xc,
	TokenGroupsAndPrivileges = 0xd,
	TokenSessionReference = 0xe,
	TokenSandBoxInert = 0xf,
	TokenAuditPolicy = 0x10,
	TokenOrigin = 0x11,
	TokenElevationType = 0x12,
	TokenLinkedToken = 0x13,
	TokenElevation = 0x14,
	TokenHasRestrictions = 0x15,
	TokenAccessInformation = 0x16,
	TokenVirtualizationAllowed = 0x17,
	TokenVirtualizationEnabled = 0x18,
	TokenIntegrityLevel = 0x19,
	TokenUIAccess = 0x1a,
	TokenMandatoryPolicy = 0x1b,
	TokenLogonSid = 0x1c,
	TokenIsAppContainer = 0x1d,
	TokenCapabilities = 0x1e,
	TokenAppContainerSid = 0x1f,
	TokenAppContainerNumber = 0x20,
	TokenUserClaimAttributes = 0x21,
	TokenDeviceClaimAttributes = 0x22,
	TokenRestrictedUserClaimAttributes = 0x23,
	TokenRestrictedDeviceClaimAttributes = 0x24,
	TokenDeviceGroups = 0x25,
	TokenRestrictedDeviceGroups = 0x26,
	TokenSecurityAttributes = 0x27,
	TokenIsRestricted = 0x28,
	TokenProcessTrustLevel = 0x29,
	TokenPrivateNameSpace = 0x2a,
	TokenSingletonAttributes = 0x2b,
	TokenBnoIsolation = 0x2c,
	TokenChildProcessFlags = 0x2d,
	MaxTokenInfoClass = 0x2e
};

struct _TOKEN_MANDATORY_POLICY {
	/*0000*/ ULONG Policy;
	/*0004*/
};

struct _TOKEN_PRIVILEGES {
	/*0000*/ ULONG PrivilegeCount;
	/*0004*/ _LUID_AND_ATTRIBUTES Privileges[0x1];
	/*0010*/
};

struct _TOKEN_SOURCE {
	/*0000*/ CHAR SourceName[0x8];
	/*0008*/ _LUID SourceIdentifier;
	/*0010*/
};

enum _TOKEN_TYPE {
	TokenPrimary = 0x1,
	TokenImpersonation = 0x2
};

struct _TP_CALLBACK_ENVIRON_V3 {
	/*0000*/ ULONG Version;
	/*0008*/ _TP_POOL * Pool;
	/*0010*/ _TP_CLEANUP_GROUP * CleanupGroup;
	/*0018*/ void (* CleanupGroupCancelCallback)( void * , void * );
	/*0020*/ void * RaceDll;
	/*0028*/ _ACTIVATION_CONTEXT * ActivationContext;
	/*0030*/ void (* FinalizationCallback)( _TP_CALLBACK_INSTANCE * , void * );
	union {
		/*0038*/ ULONG Flags;
		struct {
			/*0038*/ ULONG LongFunction : 01; // 0x00000001;
			/*0038*/ ULONG Persistent : 01; // 0x00000002;
			/*0038*/ ULONG Private : 30; // 0xfffffffc;
			/*003c*/
		} s;
		/*003c*/
	} u;
	/*003c*/ _TP_CALLBACK_PRIORITY CallbackPriority;
	/*0040*/ ULONG Size;
	/*0048*/
};

struct _TP_CALLBACK_INSTANCE;

enum _TP_CALLBACK_PRIORITY {
	TP_CALLBACK_PRIORITY_HIGH = 0x0,
	TP_CALLBACK_PRIORITY_NORMAL = 0x1,
	TP_CALLBACK_PRIORITY_LOW = 0x2,
	TP_CALLBACK_PRIORITY_INVALID = 0x3,
	TP_CALLBACK_PRIORITY_COUNT = 0x3
};

struct _TP_CLEANUP_GROUP;

struct _TP_POOL;

struct _TRACE_ENABLE_INFO {
	/*0000*/ ULONG IsEnabled;
	/*0004*/ UCHAR Level;
	/*0005*/ UCHAR Reserved1;
	/*0006*/ USHORT LoggerId;
	/*0008*/ ULONG EnableProperty;
	/*000c*/ ULONG Reserved2;
	/*0010*/ ULONGLONG MatchAnyKeyword;
	/*0018*/ ULONGLONG MatchAllKeyword;
	/*0020*/
};

enum _TRACE_INFORMATION_CLASS {
	TraceIdClass = 0x0,
	TraceHandleClass = 0x1,
	TraceEnableFlagsClass = 0x2,
	TraceEnableLevelClass = 0x3,
	GlobalLoggerHandleClass = 0x4,
	EventLoggerHandleClass = 0x5,
	AllLoggerHandlesClass = 0x6,
	TraceHandleByNameClass = 0x7,
	LoggerEventsLostClass = 0x8,
	TraceSessionSettingsClass = 0x9,
	LoggerEventsLoggedClass = 0xa,
	DiskIoNotifyRoutinesClass = 0xb,
	TraceInformationClassReserved1 = 0xc,
	AllPossibleNotifyRoutinesClass = 0xc,
	FltIoNotifyRoutinesClass = 0xd,
	TraceInformationClassReserved2 = 0xe,
	WdfNotifyRoutinesClass = 0xf,
	MaxTraceInformationClass = 0x10
};

struct _TRACE_LOGFILE_HEADER {
	/*0000*/ ULONG BufferSize;
	/*0004*/ ULONG Version;
	struct {
		/*0004*/ UCHAR MajorVersion;
		/*0005*/ UCHAR MinorVersion;
		/*0006*/ UCHAR SubVersion;
		/*0007*/ UCHAR SubMinorVersion;
		/*0008*/
	} VersionDetail;
	/*0008*/ ULONG ProviderVersion;
	/*000c*/ ULONG NumberOfProcessors;
	/*0010*/ _LARGE_INTEGER EndTime;
	/*0018*/ ULONG TimerResolution;
	/*001c*/ ULONG MaximumFileSize;
	/*0020*/ ULONG LogFileMode;
	/*0024*/ ULONG BuffersWritten;
	/*0028*/ _GUID LogInstanceGuid;
	/*0028*/ ULONG StartBuffers;
	/*002c*/ ULONG PointerSize;
	/*0030*/ ULONG EventsLost;
	/*0034*/ ULONG CpuSpeedInMHz;
	/*0038*/ WCHAR * LoggerName;
	/*0040*/ WCHAR * LogFileName;
	/*0048*/ _RTL_TIME_ZONE_INFORMATION TimeZone;
	/*00f8*/ _LARGE_INTEGER BootTime;
	/*0100*/ _LARGE_INTEGER PerfFreq;
	/*0108*/ _LARGE_INTEGER StartTime;
	/*0110*/ ULONG ReservedFlags;
	/*0114*/ ULONG BuffersLost;
	/*0118*/
};

enum _TRANSFER_TYPE {
	ReadTransfer = 0x0,
	WriteTransfer = 0x1,
	OtherTransfer = 0x2
};

struct _TRIAGE_9F_PNP {
	/*0000*/ USHORT Signature;
	/*0002*/ USHORT Revision;
	/*0008*/ _TRIAGE_PNP_DEVICE_COMPLETION_QUEUE * CompletionQueue;
	/*0010*/ _TRIAGE_EX_WORK_QUEUE * DelayedWorkQueue;
	/*0018*/
};

struct _TRIAGE_9F_POWER {
	/*0000*/ USHORT Signature;
	/*0002*/ USHORT Revision;
	/*0008*/ _LIST_ENTRY * IrpList;
	/*0010*/ _LIST_ENTRY * ThreadList;
	/*0018*/ _TRIAGE_EX_WORK_QUEUE * DelayedWorkQueue;
	/*0020*/
};

struct _TRIAGE_DEVICE_NODE {
	/*0000*/ _TRIAGE_DEVICE_NODE * Sibling;
	/*0008*/ _TRIAGE_DEVICE_NODE * Child;
	/*0010*/ _TRIAGE_DEVICE_NODE * Parent;
	/*0018*/ _TRIAGE_DEVICE_NODE * LastChild;
	/*0020*/ _DEVICE_OBJECT * PhysicalDeviceObject;
	/*0028*/ _UNICODE_STRING InstancePath;
	/*0038*/ _UNICODE_STRING ServiceName;
	/*0048*/ _IRP * PendingIrp;
	/*0050*/ _TRIAGE_POP_FX_DEVICE * FxDevice;
	/*0058*/
};

struct _TRIAGE_EX_WORK_QUEUE {
	/*0000*/ _KPRIQUEUE WorkPriQueue;
	/*02b0*/
};

struct _TRIAGE_PNP_DEVICE_COMPLETION_QUEUE {
	/*0000*/ _LIST_ENTRY DispatchedList;
	/*0010*/
};

struct _TRIAGE_PNP_DEVICE_COMPLETION_REQUEST {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _TRIAGE_DEVICE_NODE * DeviceNode;
	/*0018*/
};

struct _TRIAGE_POP_FX_DEVICE {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ _IRP * Irp;
	/*0018*/ _TRIAGE_POP_IRP_DATA * IrpData;
	/*0020*/ LONG Status;
	/*0024*/ LONG PowerReqCall;
	/*0028*/ LONG PowerNotReqCall;
	/*0030*/ _TRIAGE_DEVICE_NODE * DeviceNode;
	/*0038*/
};

struct _TRIAGE_POP_IRP_DATA {
	/*0000*/ _LIST_ENTRY Link;
	/*0010*/ _IRP * Irp;
	/*0018*/ _DEVICE_OBJECT * Pdo;
	/*0020*/
};

struct _TRUSTLET_COLLABORATION_ID {
	/*0000*/ ULONGLONG Value[0x2];
	/*0010*/
};

struct _TRUSTLET_MAILBOX_KEY {
	/*0000*/ ULONGLONG SecretValue[0x2];
	/*0010*/
};

struct _TXN_PARAMETER_BLOCK {
	/*0000*/ USHORT Length;
	/*0002*/ USHORT TxFsContext;
	/*0008*/ void * TransactionObject;
	/*0010*/
};

enum _TYPE_OF_MEMORY {
	LoaderExceptionBlock = 0x0,
	LoaderSystemBlock = 0x1,
	LoaderFree = 0x2,
	LoaderBad = 0x3,
	LoaderLoadedProgram = 0x4,
	LoaderFirmwareTemporary = 0x5,
	LoaderFirmwarePermanent = 0x6,
	LoaderOsloaderHeap = 0x7,
	LoaderOsloaderStack = 0x8,
	LoaderSystemCode = 0x9,
	LoaderHalCode = 0xa,
	LoaderBootDriver = 0xb,
	LoaderConsoleInDriver = 0xc,
	LoaderConsoleOutDriver = 0xd,
	LoaderStartupDpcStack = 0xe,
	LoaderStartupKernelStack = 0xf,
	LoaderStartupPanicStack = 0x10,
	LoaderStartupPcrPage = 0x11,
	LoaderStartupPdrPage = 0x12,
	LoaderRegistryData = 0x13,
	LoaderMemoryData = 0x14,
	LoaderNlsData = 0x15,
	LoaderSpecialMemory = 0x16,
	LoaderBBTMemory = 0x17,
	LoaderZero = 0x18,
	LoaderXIPRom = 0x19,
	LoaderHALCachedMemory = 0x1a,
	LoaderLargePageFiller = 0x1b,
	LoaderErrorLogMemory = 0x1c,
	LoaderVsmMemory = 0x1d,
	LoaderFirmwareCode = 0x1e,
	LoaderFirmwareData = 0x1f,
	LoaderFirmwareReserved = 0x20,
	LoaderEnclaveMemory = 0x21,
	LoaderFirmwareKsr = 0x22,
	LoaderEnclaveKsr = 0x23,
	LoaderMaximum = 0x24
};

enum _TlgBlob_t {
	_TlgBlobNone = 0x0,
	_TlgBlobEnd = 0x1,
	_TlgBlobProvider = 0x2,
	_TlgBlobEvent3 = 0x3,
	_TlgBlobProvider3 = 0x4,
	_TlgBlobEvent2 = 0x5,
	_TlgBlobMax = 0x6
};

struct _TlgProviderMetadata_t {
	/*0000*/ UCHAR Type;
	/*0001*/ _GUID ProviderId;
	/*0011*/ USHORT RemainingSize;
	/*0013*/
};

struct _TlgProvider_t {
	/*0000*/ UINT LevelPlus1;
	/*0008*/ USHORT const __unaligned * ProviderMetadataPtr;
	/*0010*/ ULONGLONG KeywordAny;
	/*0018*/ ULONGLONG KeywordAll;
	/*0020*/ ULONGLONG RegHandle;
	/*0028*/ void (* EnableCallback)( _GUID const * , ULONG , UCHAR , ULONGLONG , ULONGLONG , _EVENT_FILTER_DESCRIPTOR * , void * );
	/*0030*/ void * CallbackContext;
	/*0038*/ void (* AnnotationFunc)();
	/*0040*/
};

struct _TraceLoggingMetadata_t {
	/*0000*/ UINT Signature;
	/*0004*/ USHORT Size;
	/*0006*/ UCHAR Version;
	/*0007*/ UCHAR Flags;
	/*0008*/ ULONGLONG Magic;
	/*0010*/
};

union _ULARGE_INTEGER {
	/*0000*/ ULONG LowPart;
	/*0004*/ ULONG HighPart;
	struct {
		/*0000*/ ULONG LowPart;
		/*0004*/ ULONG HighPart;
		/*0008*/
	} u;
	/*0000*/ ULONGLONG QuadPart;
	/*0008*/
};

struct _UMS_CONTROL_BLOCK {
	/*0000*/ _RTL_UMS_CONTEXT * UmsContext;
	/*0008*/ _SINGLE_LIST_ENTRY * CompletionListEntry;
	/*0010*/ _KEVENT * CompletionListEvent;
	/*0018*/ ULONG ServiceSequenceNumber;
	/*0020*/ _KQUEUE UmsQueue;
	/*0060*/ _LIST_ENTRY QueueEntry;
	/*0070*/ _RTL_UMS_CONTEXT * YieldingUmsContext;
	/*0078*/ void * YieldingParam;
	/*0080*/ void * UmsTeb;
	/*0020*/ _KQUEUE * UmsAssociatedQueue;
	/*0028*/ _LIST_ENTRY * UmsQueueListEntry;
	/*0030*/ _KEVENT UmsWaitEvent;
	/*0048*/ void * StagingArea;
	/*0050*/ ULONG UmsPrimaryDeliveredContext : 01; // 0x00000001;
	/*0050*/ ULONG UmsAssociatedQueueUsed : 01; // 0x00000002;
	/*0050*/ ULONG UmsThreadParked : 01; // 0x00000004;
	/*0050*/ ULONG UmsFlags;
	/*0088*/
};

struct _UNEXPECTED_INTERRUPT {
	/*0000*/ UCHAR PushImm;
	/*0001*/ UCHAR Vector;
	/*0002*/ UCHAR PushRbp;
	/*0003*/ UCHAR JmpOp;
	/*0004*/ LONG JmpOffset;
	/*0008*/
};

struct _UNICODE_STRING {
	/*0000*/ USHORT Length;
	/*0002*/ USHORT MaximumLength;
	/*0008*/ WCHAR * Buffer;
	/*0010*/
};

enum _USER_ACTIVITY_PRESENCE {
	PowerUserPresent = 0x0,
	PowerUserNotPresent = 0x1,
	PowerUserInactive = 0x2,
	PowerUserMaximum = 0x3,
	PowerUserInvalid = 0x3
};

struct _VACB {
	/*0000*/ void * BaseAddress;
	/*0008*/ _SHARED_CACHE_MAP * SharedCacheMap;
	union {
		/*0010*/ _LARGE_INTEGER FileOffset;
		/*0010*/ USHORT ActiveCount;
		/*0010*/ _LIST_ENTRY Links;
		/*0020*/
	} Overlay;
	/*0020*/ _VACB_ARRAY_HEADER * ArrayHead;
	/*0028*/
};

struct _VACB_ARRAY_HEADER {
	/*0000*/ ULONG VacbArrayIndex;
	/*0004*/ ULONG MappingCount;
	/*0008*/ ULONG HighestMappedIndex;
	/*000c*/ ULONG Reserved;
	/*0010*/
};

struct _VACB_LEVEL_REFERENCE {
	/*0000*/ LONG Reference;
	/*0004*/ LONG SpecialReference;
	/*0008*/
};

struct _VERIFIER_SHARED_EXPORT_THUNK;

struct _VF_ADDRESS_RANGE {
	/*0000*/ UCHAR * Start;
	/*0008*/ UCHAR * End;
	/*0010*/
};

struct _VF_AVL_TABLE {
	/*0000*/ _RTL_AVL_TABLE RtlTable;
	/*0068*/ _VF_AVL_TREE_NODE * ReservedNode;
	/*0070*/ void * NodeToFree;
	/*0080*/ LONG volatile Lock;
	/*00c0*/
};

struct _VF_AVL_TREE {
	/*0000*/ ULONGLONG NodeRangeSize;
	/*0008*/ ULONGLONG volatile NodeCount;
	/*0010*/ _VF_AVL_TABLE * Tables;
	/*0018*/ ULONG TablesNo;
	/*001c*/ UCHAR UseSessionId;
	union {
		/*0020*/ ULONG NodeSize;
		/*0020*/ ULONG UseLookaside;
		/*0024*/
	} u1;
	/*0028*/
};

struct _VF_AVL_TREE_NODE {
	/*0000*/ void * p;
	/*0008*/ ULONGLONG RangeSize;
	/*0010*/
};

struct _VF_AVL_TREE_NODE_EX {
	/*0000*/ _VF_AVL_TREE_NODE Base;
	/*0010*/ ULONG SessionId;
	/*0018*/
};

struct _VF_DRIVER_IO_CALLBACKS {
	/*0000*/ LONG (* DriverInit)( _DRIVER_OBJECT * , _UNICODE_STRING * );
	/*0008*/ void (* DriverStartIo)( _DEVICE_OBJECT * , _IRP * );
	/*0010*/ void (* DriverUnload)( _DRIVER_OBJECT * );
	/*0018*/ LONG (* AddDevice)( _DRIVER_OBJECT * , _DEVICE_OBJECT * );
	/*0020*/ LONG (* MajorFunction[0x1c])( _DEVICE_OBJECT * , _IRP * );
	/*0100*/
};

struct _VF_KE_CRITICAL_REGION_TRACE {
	/*0000*/ _ETHREAD * Thread;
	/*0008*/ void * StackTrace[0x7];
	/*0040*/
};

struct _VF_POOL_TRACE {
	/*0000*/ void * Address;
	/*0008*/ ULONGLONG Size;
	/*0010*/ _ETHREAD * Thread;
	/*0018*/ void * StackTrace[0xd];
	/*0080*/
};

struct _VF_SUSPECT_DRIVER_ENTRY {
	/*0000*/ _LIST_ENTRY Links;
	/*0010*/ ULONG Loads;
	/*0014*/ ULONG Unloads;
	/*0018*/ _UNICODE_STRING BaseName;
	/*0028*/
};

struct _VF_TARGET_ALL_SHARED_EXPORT_THUNKS {
	/*0000*/ _VERIFIER_SHARED_EXPORT_THUNK * SharedExportThunks;
	/*0008*/ _VERIFIER_SHARED_EXPORT_THUNK * PoolSharedExportThunks;
	/*0010*/ _VERIFIER_SHARED_EXPORT_THUNK * OrderDependentSharedExportThunks;
	/*0018*/ _VERIFIER_SHARED_EXPORT_THUNK * XdvSharedExportThunks;
	/*0020*/
};

struct _VF_TARGET_DRIVER {
	/*0000*/ _VF_AVL_TREE_NODE_EX TreeNode;
	union {
		/*0018*/ _VF_TARGET_ALL_SHARED_EXPORT_THUNKS AllSharedExportThunks;
		struct {
			/*0018*/ ULONG SnapSharedExportsFailed : 01; // 0x00000001;
			/*0018*/ ULONG Spare : 31; // 0xfffffffe;
			/*001c*/
		} Flags;
		/*0038*/
	} u1;
	/*0038*/ _VF_TARGET_VERIFIED_DRIVER_DATA * VerifiedData;
	/*0040*/
};

struct _VF_TARGET_VERIFIED_DRIVER_DATA {
	/*0000*/ _VF_SUSPECT_DRIVER_ENTRY * SuspectDriverEntry;
	/*0008*/ void * WMICallback;
	/*0010*/ _LIST_ENTRY EtwHandlesListHead;
	union {
		struct {
			/*0020*/ ULONG MissedEtwRegistration : 01; // 0x00000001;
			/*0020*/ ULONG Spare : 31; // 0xfffffffe;
			/*0024*/
		} Flags;
		/*0020*/ ULONG Whole;
		/*0024*/
	} u1;
	/*0028*/ ULONGLONG Signature;
	/*0030*/ _SLIST_HEADER PoolPageHeaders;
	/*0040*/ _SLIST_HEADER PoolTrackers;
	/*0050*/ ULONG volatile CurrentPagedPoolAllocations;
	/*0054*/ ULONG volatile CurrentNonPagedPoolAllocations;
	/*0058*/ ULONG PeakPagedPoolAllocations;
	/*005c*/ ULONG PeakNonPagedPoolAllocations;
	/*0060*/ ULONGLONG volatile PagedBytes;
	/*0068*/ ULONGLONG volatile NonPagedBytes;
	/*0070*/ ULONGLONG PeakPagedBytes;
	/*0078*/ ULONGLONG PeakNonPagedBytes;
	/*0080*/ ULONG RaiseIrqls;
	/*0084*/ ULONG AcquireSpinLocks;
	/*0088*/ ULONG SynchronizeExecutions;
	/*008c*/ ULONG AllocationsWithNoTag;
	/*0090*/ ULONG AllocationsFailed;
	/*0094*/ ULONG AllocationsFailedDeliberately;
	/*0098*/ ULONGLONG LockedBytes;
	/*00a0*/ ULONGLONG PeakLockedBytes;
	/*00a8*/ ULONGLONG MappedLockedBytes;
	/*00b0*/ ULONGLONG PeakMappedLockedBytes;
	/*00b8*/ ULONGLONG MappedIoSpaceBytes;
	/*00c0*/ ULONGLONG PeakMappedIoSpaceBytes;
	/*00c8*/ ULONGLONG PagesForMdlBytes;
	/*00d0*/ ULONGLONG PeakPagesForMdlBytes;
	/*00d8*/ ULONGLONG ContiguousMemoryBytes;
	/*00e0*/ ULONGLONG PeakContiguousMemoryBytes;
	/*00e8*/ _LIST_ENTRY ContiguousMemoryListHead;
	/*00f8*/ ULONG volatile ExecutePoolTypes;
	/*00fc*/ ULONG volatile ExecutePageProtections;
	/*0100*/ ULONG volatile ExecutePageMappings;
	/*0104*/ ULONG volatile ExecuteWriteSections;
	/*0108*/ ULONG volatile SectionAlignmentFailures;
	/*010c*/ ULONG volatile UnsupportedRelocs;
	/*0110*/ ULONG volatile IATInExecutableSection;
	/*0120*/
};

struct _VF_TRACKER {
	/*0000*/ ULONG TrackerFlags;
	/*0004*/ ULONG TrackerSize;
	/*0008*/ ULONG TrackerIndex;
	/*000c*/ ULONG TraceDepth;
	/*0010*/
};

struct _VF_TRACKER_STAMP {
	/*0000*/ void * Thread;
	/*0008*/ UCHAR Flags : 08; // 0xff;
	/*0009*/ UCHAR OldIrql : 08; // 0xff;
	/*000a*/ UCHAR NewIrql : 08; // 0xff;
	/*000b*/ UCHAR Processor : 08; // 0xff;
	/*0010*/
};

struct _VF_WATCHDOG_IRP {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ _IRP * Irp;
	/*0018*/ ULONG DueTickCount;
	/*001c*/ UCHAR volatile Inserted;
	/*001d*/ CHAR TrackedStackLocation;
	/*001e*/ USHORT CancelTimeoutTicks;
	/*0020*/
};

struct _VI_DEADLOCK_GLOBALS {
	/*0000*/ LONGLONG TimeAcquire;
	/*0008*/ LONGLONG TimeRelease;
	/*0010*/ _LIST_ENTRY * ResourceDatabase;
	/*0018*/ ULONGLONG ResourceDatabaseCount;
	/*0020*/ _VF_ADDRESS_RANGE ResourceAddressRange[0x3ff];
	/*4010*/ _LIST_ENTRY * ThreadDatabase;
	/*4018*/ ULONGLONG ThreadDatabaseCount;
	/*4020*/ _VF_ADDRESS_RANGE ThreadAddressRange[0x3ff];
	/*8010*/ ULONG volatile AllocationFailures;
	/*8014*/ ULONG NodesTrimmedBasedOnAge;
	/*8018*/ ULONG NodesTrimmedBasedOnCount;
	/*801c*/ ULONG NodesSearched;
	/*8020*/ ULONG MaxNodesSearched;
	/*8024*/ ULONG SequenceNumber;
	/*8028*/ ULONG RecursionDepthLimit;
	/*802c*/ ULONG SearchedNodesLimit;
	/*8030*/ ULONG DepthLimitHits;
	/*8034*/ ULONG SearchLimitHits;
	/*8038*/ ULONG StackLimitHits;
	/*803c*/ ULONG ABC_ACB_Skipped;
	/*8040*/ ULONG OutOfOrderReleases;
	/*8044*/ ULONG NodesReleasedOutOfOrder;
	/*8048*/ ULONG TotalReleases;
	/*804c*/ ULONG RootNodesDeleted;
	/*8050*/ ULONG ForgetHistoryCounter;
	/*8058*/ void * Instigator;
	/*8060*/ ULONG NumberOfParticipants;
	/*8068*/ _VI_DEADLOCK_NODE * Participant[0x20];
	/*8168*/ LONG ChildrenCountWatermark;
	/*816c*/ _KERNEL_STACK_LIMITS StackType;
	/*8170*/ ULONGLONG StackLowLimit;
	/*8178*/ ULONGLONG StackHighLimit;
	/*8180*/
};

struct _VI_DEADLOCK_NODE {
	/*0000*/ _VI_DEADLOCK_NODE * Parent;
	/*0008*/ _LIST_ENTRY ChildrenList;
	/*0018*/ _LIST_ENTRY SiblingsList;
	/*0028*/ _LIST_ENTRY ResourceList;
	/*0028*/ _LIST_ENTRY FreeListEntry;
	/*0038*/ _VI_DEADLOCK_RESOURCE * Root;
	/*0040*/ _VI_DEADLOCK_THREAD * ThreadEntry;
	union {
		/*0048*/ ULONG Active : 01; // 0x00000001;
		/*0048*/ ULONG OnlyTryAcquireUsed : 01; // 0x00000002;
		/*0048*/ ULONG ReleasedOutOfOrder : 01; // 0x00000004;
		/*0048*/ ULONG SequenceNumber : 29; // 0xfffffff8;
		/*0048*/ ULONG Whole;
		/*004c*/
	} u1;
	/*004c*/ LONG ChildrenCount;
	/*0050*/ void * StackTrace[0x8];
	/*0090*/ void * ParentStackTrace[0x8];
	/*00d0*/
};

struct _VI_DEADLOCK_RESOURCE {
	/*0000*/ _VI_DEADLOCK_RESOURCE_TYPE Type;
	/*0004*/ ULONG NodeCount : 16; // 0x0000ffff;
	/*0004*/ ULONG RecursionCount : 16; // 0xffff0000;
	/*0008*/ void * ResourceAddress;
	/*0010*/ _VI_DEADLOCK_THREAD * ThreadOwner;
	/*0018*/ _LIST_ENTRY ResourceList;
	/*0028*/ _LIST_ENTRY HashChainList;
	/*0028*/ _LIST_ENTRY FreeListEntry;
	/*0038*/ void * StackTrace[0x8];
	/*0078*/ void * LastAcquireTrace[0x8];
	/*00b8*/ void * LastReleaseTrace[0x8];
	/*00f8*/
};

enum _VI_DEADLOCK_RESOURCE_TYPE {
	VfDeadlockUnknown = 0x0,
	VfDeadlockMutex = 0x1,
	VfDeadlockMutexAbandoned = 0x2,
	VfDeadlockFastMutex = 0x3,
	VfDeadlockFastMutexUnsafe = 0x4,
	VfDeadlockSpinLock = 0x5,
	VfDeadlockInStackQueuedSpinLock = 0x6,
	VfDeadlockUnusedSpinLock = 0x7,
	VfDeadlockEresource = 0x8,
	VfDeadlockTypeMaximum = 0x9
};

struct _VI_DEADLOCK_THREAD {
	/*0000*/ _KTHREAD * Thread;
	/*0008*/ _VI_DEADLOCK_NODE * CurrentSpinNode;
	/*0010*/ _VI_DEADLOCK_NODE * CurrentOtherNode;
	/*0018*/ _LIST_ENTRY ListEntry;
	/*0018*/ _LIST_ENTRY FreeListEntry;
	/*0028*/ ULONG NodeCount;
	/*002c*/ ULONG volatile PagingCount;
	/*0030*/ UCHAR ThreadUsesEresources;
	/*0038*/
};

struct _VI_FAULT_TRACE {
	/*0000*/ _ETHREAD * Thread;
	/*0008*/ void * StackTrace[0x8];
	/*0048*/
};

struct _VI_POOL_ENTRY {
	/*0000*/ _VI_POOL_PAGE_HEADER PageHeader;
	/*0000*/ _VI_POOL_ENTRY_INUSE InUse;
	/*0000*/ _SLIST_ENTRY * NextFree;
	/*0020*/
};

struct _VI_POOL_ENTRY_INUSE {
	/*0000*/ void * VirtualAddress;
	/*0008*/ void * CallingAddress;
	/*0010*/ ULONGLONG NumberOfBytes;
	/*0018*/ ULONGLONG Tag;
	/*0020*/
};

struct _VI_POOL_PAGE_HEADER {
	/*0000*/ _SLIST_ENTRY * NextPage;
	/*0008*/ void * VerifierEntry;
	/*0010*/ ULONGLONG Signature;
	/*0018*/
};

struct _VI_TRACK_IRQL {
	/*0000*/ void * Thread;
	/*0008*/ UCHAR OldIrql;
	/*0009*/ UCHAR NewIrql;
	/*000a*/ USHORT Processor;
	/*000c*/ ULONG TickCount;
	/*0010*/ void * StackTrace[0x5];
	/*0038*/
};

struct _VI_VERIFIER_ISSUE {
	/*0000*/ ULONGLONG IssueType;
	/*0008*/ void * Address;
	/*0010*/ ULONGLONG Parameters[0x2];
	/*0020*/
};

struct _VOLUME_CACHE_MAP {
	/*0000*/ SHORT NodeTypeCode;
	/*0002*/ SHORT NodeByteCode;
	/*0004*/ ULONG UseCount;
	/*0008*/ _DEVICE_OBJECT * DeviceObject;
	/*0010*/ _LIST_ENTRY VolumeCacheMapLinks;
	/*0020*/ ULONGLONG DirtyPages;
	/*0028*/ _LOG_HANDLE_CONTEXT LogHandleContext;
	/*00c0*/ ULONG Flags;
	/*00c4*/ ULONG PagesQueuedToDisk;
	/*00c8*/ ULONG LoggedPagesQueuedToDisk;
	/*00d0*/
};

struct _VPB {
	/*0000*/ SHORT Type;
	/*0002*/ SHORT Size;
	/*0004*/ USHORT Flags;
	/*0006*/ USHORT VolumeLabelLength;
	/*0008*/ _DEVICE_OBJECT * DeviceObject;
	/*0010*/ _DEVICE_OBJECT * RealDevice;
	/*0018*/ ULONG SerialNumber;
	/*001c*/ ULONG ReferenceCount;
	/*0020*/ WCHAR VolumeLabel[0x20];
	/*0060*/
};

struct _WAITING_IRP {
	/*0000*/ _LIST_ENTRY Links;
	/*0010*/ _IRP * Irp;
	/*0018*/ void (* CompletionRoutine)( void * , _IRP * );
	/*0020*/ void * Context;
	/*0028*/ _KEVENT * Event;
	/*0030*/ ULONG Information;
	/*0034*/ UCHAR BreakAllRH;
	/*0035*/ UCHAR OplockBreakNotify;
	/*0038*/ _FILE_OBJECT * FileObject;
	/*0040*/
};

struct _WAIT_CONTEXT_BLOCK {
	/*0000*/ _KDEVICE_QUEUE_ENTRY WaitQueueEntry;
	/*0000*/ _LIST_ENTRY DmaWaitEntry;
	/*0010*/ ULONG NumberOfChannels;
	/*0014*/ ULONG SyncCallback : 01; // 0x00000001;
	/*0014*/ ULONG DmaContext : 01; // 0x00000002;
	/*0014*/ ULONG ZeroMapRegisters : 01; // 0x00000004;
	/*0014*/ ULONG Reserved : 29; // 0xfffffff8;
	/*0018*/ _IO_ALLOCATION_ACTION (* DeviceRoutine)( _DEVICE_OBJECT * , _IRP * , void * , void * );
	/*0020*/ void * DeviceContext;
	/*0028*/ ULONG NumberOfMapRegisters;
	/*0030*/ void * DeviceObject;
	/*0038*/ void * CurrentIrp;
	/*0040*/ _KDPC * BufferChainingDpc;
	/*0048*/
};

struct _WHEAP_ERROR_RECORD_WRAPPER {
	/*0000*/ _LIST_ENTRY WorkEntry;
	/*0010*/ ULONG Length;
	/*0014*/ ULONG ProcessorNumber;
	/*0018*/ _WHEAP_ERROR_RECORD_WRAPPER_FLAGS Flags;
	/*001c*/ LONG volatile InUse;
	/*0020*/ _WHEAP_ERROR_SOURCE * ErrorSource;
	/*0028*/ _WHEA_ERROR_RECORD ErrorRecord;
	/*00f0*/
};

union _WHEAP_ERROR_RECORD_WRAPPER_FLAGS {
	/*0000*/ ULONG Preallocated : 01; // 0x00000001;
	/*0000*/ ULONG FromPersistentStore : 01; // 0x00000002;
	/*0000*/ ULONG PlatformPfaControl : 01; // 0x00000004;
	/*0000*/ ULONG PlatformDirectedOffline : 01; // 0x00000008;
	/*0000*/ ULONG Reserved : 28; // 0xfffffff0;
	/*0000*/ ULONG AsULONG;
	/*0004*/
};

struct _WHEAP_ERROR_SOURCE {
	/*0000*/ _LIST_ENTRY ListEntry;
	/*0010*/ ULONG FailedAllocations;
	/*0014*/ ULONG PlatformErrorSourceId;
	/*0018*/ LONG ErrorCount;
	/*001c*/ ULONG RecordCount;
	/*0020*/ ULONG RecordLength;
	/*0024*/ ULONG PoolTag;
	/*0028*/ _WHEA_ERROR_SOURCE_TYPE Type;
	/*0030*/ _WHEAP_ERROR_RECORD_WRAPPER * Records;
	/*0038*/ void * Context;
	/*0040*/ ULONG SectionCount;
	/*0044*/ ULONG SectionLength;
	/*0048*/ _LARGE_INTEGER TickCountAtLastError;
	/*0050*/ ULONG AccumulatedErrors;
	/*0054*/ ULONG TotalErrors;
	/*0058*/ UCHAR Deferred;
	/*0059*/ _WHEA_ERROR_SOURCE_DESCRIPTOR Descriptor;
	/*0428*/
};

struct _WHEAP_ERROR_SOURCE_TABLE {
	/*0000*/ ULONG Signature;
	/*0004*/ LONG Count;
	/*0008*/ _LIST_ENTRY Items;
	/*0018*/ _KEVENT InsertLock;
	/*0030*/
};

struct _WHEAP_INFO_BLOCK {
	/*0000*/ ULONG ErrorSourceCount;
	/*0008*/ _WHEAP_ERROR_SOURCE_TABLE * ErrorSourceTable;
	/*0010*/ _WHEAP_WORK_QUEUE * WorkQueue;
	/*0018*/
};

struct _WHEAP_WORK_QUEUE {
	/*0000*/ _LIST_ENTRY ListHead;
	/*0010*/ ULONGLONG ListLock;
	/*0018*/ LONG volatile ItemCount;
	/*0020*/ _KDPC Dpc;
	/*0060*/ _WORK_QUEUE_ITEM WorkItem;
	/*0080*/ void (* WorkRoutine)( _WHEAP_WORK_QUEUE * , _LIST_ENTRY * );
	/*0088*/
};

struct _WHEA_AER_BRIDGE_DESCRIPTOR {
	/*0000*/ USHORT Type;
	/*0002*/ UCHAR Enabled;
	/*0003*/ UCHAR Reserved;
	/*0004*/ ULONG BusNumber;
	/*0008*/ _WHEA_PCI_SLOT_NUMBER Slot;
	/*000c*/ USHORT DeviceControl;
	/*000e*/ _AER_BRIDGE_DESCRIPTOR_FLAGS Flags;
	/*0010*/ ULONG UncorrectableErrorMask;
	/*0014*/ ULONG UncorrectableErrorSeverity;
	/*0018*/ ULONG CorrectableErrorMask;
	/*001c*/ ULONG AdvancedCapsAndControl;
	/*0020*/ ULONG SecondaryUncorrectableErrorMask;
	/*0024*/ ULONG SecondaryUncorrectableErrorSev;
	/*0028*/ ULONG SecondaryCapsAndControl;
	/*002c*/
};

struct _WHEA_AER_ENDPOINT_DESCRIPTOR {
	/*0000*/ USHORT Type;
	/*0002*/ UCHAR Enabled;
	/*0003*/ UCHAR Reserved;
	/*0004*/ ULONG BusNumber;
	/*0008*/ _WHEA_PCI_SLOT_NUMBER Slot;
	/*000c*/ USHORT DeviceControl;
	/*000e*/ _AER_ENDPOINT_DESCRIPTOR_FLAGS Flags;
	/*0010*/ ULONG UncorrectableErrorMask;
	/*0014*/ ULONG UncorrectableErrorSeverity;
	/*0018*/ ULONG CorrectableErrorMask;
	/*001c*/ ULONG AdvancedCapsAndControl;
	/*0020*/
};

struct _WHEA_AER_ROOTPORT_DESCRIPTOR {
	/*0000*/ USHORT Type;
	/*0002*/ UCHAR Enabled;
	/*0003*/ UCHAR Reserved;
	/*0004*/ ULONG BusNumber;
	/*0008*/ _WHEA_PCI_SLOT_NUMBER Slot;
	/*000c*/ USHORT DeviceControl;
	/*000e*/ _AER_ROOTPORT_DESCRIPTOR_FLAGS Flags;
	/*0010*/ ULONG UncorrectableErrorMask;
	/*0014*/ ULONG UncorrectableErrorSeverity;
	/*0018*/ ULONG CorrectableErrorMask;
	/*001c*/ ULONG AdvancedCapsAndControl;
	/*0020*/ ULONG RootErrorCommand;
	/*0024*/
};

enum _WHEA_ERROR_PACKET_DATA_FORMAT {
	WheaDataFormatIPFSalRecord = 0x0,
	WheaDataFormatXPFMCA = 0x1,
	WheaDataFormatMemory = 0x2,
	WheaDataFormatPCIExpress = 0x3,
	WheaDataFormatNMIPort = 0x4,
	WheaDataFormatPCIXBus = 0x5,
	WheaDataFormatPCIXDevice = 0x6,
	WheaDataFormatGeneric = 0x7,
	WheaDataFormatMax = 0x8
};

union _WHEA_ERROR_PACKET_FLAGS {
	/*0000*/ ULONG PreviousError : 01; // 0x00000001;
	/*0000*/ ULONG Reserved1 : 01; // 0x00000002;
	/*0000*/ ULONG HypervisorError : 01; // 0x00000004;
	/*0000*/ ULONG Simulated : 01; // 0x00000008;
	/*0000*/ ULONG PlatformPfaControl : 01; // 0x00000010;
	/*0000*/ ULONG PlatformDirectedOffline : 01; // 0x00000020;
	/*0000*/ ULONG Reserved2 : 26; // 0xffffffc0;
	/*0000*/ ULONG AsULONG;
	/*0004*/
};

struct _WHEA_ERROR_PACKET_V2 {
	/*0000*/ ULONG Signature;
	/*0004*/ ULONG Version;
	/*0008*/ ULONG Length;
	/*000c*/ _WHEA_ERROR_PACKET_FLAGS Flags;
	/*0010*/ _WHEA_ERROR_TYPE ErrorType;
	/*0014*/ _WHEA_ERROR_SEVERITY ErrorSeverity;
	/*0018*/ ULONG ErrorSourceId;
	/*001c*/ _WHEA_ERROR_SOURCE_TYPE ErrorSourceType;
	/*0020*/ _GUID NotifyType;
	/*0030*/ ULONGLONG Context;
	/*0038*/ _WHEA_ERROR_PACKET_DATA_FORMAT DataFormat;
	/*003c*/ ULONG Reserved1;
	/*0040*/ ULONG DataOffset;
	/*0044*/ ULONG DataLength;
	/*0048*/ ULONG PshedDataOffset;
	/*004c*/ ULONG PshedDataLength;
	/*0050*/
};

struct _WHEA_ERROR_RECORD {
	/*0000*/ _WHEA_ERROR_RECORD_HEADER Header;
	/*0080*/ _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR SectionDescriptor[0x1];
	/*00c8*/
};

struct _WHEA_ERROR_RECORD_HEADER {
	/*0000*/ ULONG Signature;
	/*0004*/ _WHEA_REVISION Revision;
	/*0006*/ ULONG SignatureEnd;
	/*000a*/ USHORT SectionCount;
	/*000c*/ _WHEA_ERROR_SEVERITY Severity;
	/*0010*/ _WHEA_ERROR_RECORD_HEADER_VALIDBITS ValidBits;
	/*0014*/ ULONG Length;
	/*0018*/ _WHEA_TIMESTAMP Timestamp;
	/*0020*/ _GUID PlatformId;
	/*0030*/ _GUID PartitionId;
	/*0040*/ _GUID CreatorId;
	/*0050*/ _GUID NotifyType;
	/*0060*/ ULONGLONG RecordId;
	/*0068*/ _WHEA_ERROR_RECORD_HEADER_FLAGS Flags;
	/*006c*/ _WHEA_PERSISTENCE_INFO PersistenceInfo;
	/*0074*/ UCHAR Reserved[0xc];
	/*0080*/
};

union _WHEA_ERROR_RECORD_HEADER_FLAGS {
	/*0000*/ ULONG Recovered : 01; // 0x00000001;
	/*0000*/ ULONG PreviousError : 01; // 0x00000002;
	/*0000*/ ULONG Simulated : 01; // 0x00000004;
	/*0000*/ ULONG Reserved : 29; // 0xfffffff8;
	/*0000*/ ULONG AsULONG;
	/*0004*/
};

union _WHEA_ERROR_RECORD_HEADER_VALIDBITS {
	/*0000*/ ULONG PlatformId : 01; // 0x00000001;
	/*0000*/ ULONG Timestamp : 01; // 0x00000002;
	/*0000*/ ULONG PartitionId : 01; // 0x00000004;
	/*0000*/ ULONG Reserved : 29; // 0xfffffff8;
	/*0000*/ ULONG AsULONG;
	/*0004*/
};

struct _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR {
	/*0000*/ ULONG SectionOffset;
	/*0004*/ ULONG SectionLength;
	/*0008*/ _WHEA_REVISION Revision;
	/*000a*/ _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS ValidBits;
	/*000b*/ UCHAR Reserved;
	/*000c*/ _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS Flags;
	/*0010*/ _GUID SectionType;
	/*0020*/ _GUID FRUId;
	/*0030*/ _WHEA_ERROR_SEVERITY SectionSeverity;
	/*0034*/ CHAR FRUText[0x14];
	/*0048*/
};

union _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS {
	/*0000*/ ULONG Primary : 01; // 0x00000001;
	/*0000*/ ULONG ContainmentWarning : 01; // 0x00000002;
	/*0000*/ ULONG Reset : 01; // 0x00000004;
	/*0000*/ ULONG ThresholdExceeded : 01; // 0x00000008;
	/*0000*/ ULONG ResourceNotAvailable : 01; // 0x00000010;
	/*0000*/ ULONG LatentError : 01; // 0x00000020;
	/*0000*/ ULONG Propagated : 01; // 0x00000040;
	/*0000*/ ULONG Reserved : 25; // 0xffffff80;
	/*0000*/ ULONG AsULONG;
	/*0004*/
};

union _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_VALIDBITS {
	/*0000*/ UCHAR FRUId : 01; // 0x01;
	/*0000*/ UCHAR FRUText : 01; // 0x02;
	/*0000*/ UCHAR Reserved : 06; // 0xfc;
	/*0000*/ UCHAR AsUCHAR;
	/*0001*/
};

enum _WHEA_ERROR_SEVERITY {
	WheaErrSevRecoverable = 0x0,
	WheaErrSevFatal = 0x1,
	WheaErrSevCorrected = 0x2,
	WheaErrSevInformational = 0x3
};

struct _WHEA_ERROR_SOURCE_DESCRIPTOR {
	/*0000*/ ULONG Length;
	/*0004*/ ULONG Version;
	/*0008*/ _WHEA_ERROR_SOURCE_TYPE Type;
	/*000c*/ _WHEA_ERROR_SOURCE_STATE State;
	/*0010*/ ULONG MaxRawDataLength;
	/*0014*/ ULONG NumRecordsToPreallocate;
	/*0018*/ ULONG MaxSectionsPerRecord;
	/*001c*/ ULONG ErrorSourceId;
	/*0020*/ ULONG PlatformErrorSourceId;
	/*0024*/ ULONG Flags;
	union {
		/*0028*/ _WHEA_XPF_MCE_DESCRIPTOR XpfMceDescriptor;
		/*0028*/ _WHEA_XPF_CMC_DESCRIPTOR XpfCmcDescriptor;
		/*0028*/ _WHEA_XPF_NMI_DESCRIPTOR XpfNmiDescriptor;
		/*0028*/ _WHEA_IPF_MCA_DESCRIPTOR IpfMcaDescriptor;
		/*0028*/ _WHEA_IPF_CMC_DESCRIPTOR IpfCmcDescriptor;
		/*0028*/ _WHEA_IPF_CPE_DESCRIPTOR IpfCpeDescriptor;
		/*0028*/ _WHEA_AER_ROOTPORT_DESCRIPTOR AerRootportDescriptor;
		/*0028*/ _WHEA_AER_ENDPOINT_DESCRIPTOR AerEndpointDescriptor;
		/*0028*/ _WHEA_AER_BRIDGE_DESCRIPTOR AerBridgeDescriptor;
		/*0028*/ _WHEA_GENERIC_ERROR_DESCRIPTOR GenErrDescriptor;
		/*0028*/ _WHEA_GENERIC_ERROR_DESCRIPTOR_V2 GenErrDescriptorV2;
		/*03cc*/
	} Info;
	/*03cc*/
};

enum _WHEA_ERROR_SOURCE_STATE {
	WheaErrSrcStateStopped = 0x1,
	WheaErrSrcStateStarted = 0x2
};

enum _WHEA_ERROR_SOURCE_TYPE {
	WheaErrSrcTypeMCE = 0x0,
	WheaErrSrcTypeCMC = 0x1,
	WheaErrSrcTypeCPE = 0x2,
	WheaErrSrcTypeNMI = 0x3,
	WheaErrSrcTypePCIe = 0x4,
	WheaErrSrcTypeGeneric = 0x5,
	WheaErrSrcTypeINIT = 0x6,
	WheaErrSrcTypeBOOT = 0x7,
	WheaErrSrcTypeSCIGeneric = 0x8,
	WheaErrSrcTypeIPFMCA = 0x9,
	WheaErrSrcTypeIPFCMC = 0xa,
	WheaErrSrcTypeIPFCPE = 0xb,
	WheaErrSrcTypeGenericV2 = 0xc,
	WheaErrSrcTypeSCIGenericV2 = 0xd,
	WheaErrSrcTypeMax = 0xe
};

union _WHEA_ERROR_STATUS {
	/*0000*/ ULONGLONG ErrorStatus;
	/*0000*/ ULONGLONG Reserved1 : 08; // 0x00000000000000ff;
	/*0000*/ ULONGLONG ErrorType : 08; // 0x000000000000ff00;
	/*0000*/ ULONGLONG Address : 01; // 0x0000000000010000;
	/*0000*/ ULONGLONG Control : 01; // 0x0000000000020000;
	/*0000*/ ULONGLONG Data : 01; // 0x0000000000040000;
	/*0000*/ ULONGLONG Responder : 01; // 0x0000000000080000;
	/*0000*/ ULONGLONG Requester : 01; // 0x0000000000100000;
	/*0000*/ ULONGLONG FirstError : 01; // 0x0000000000200000;
	/*0000*/ ULONGLONG Overflow : 01; // 0x0000000000400000;
	/*0000*/ ULONGLONG Reserved2 : 41; // 0xffffffffff800000;
	/*0008*/
};

enum _WHEA_ERROR_TYPE {
	WheaErrTypeProcessor = 0x0,
	WheaErrTypeMemory = 0x1,
	WheaErrTypePCIExpress = 0x2,
	WheaErrTypeNMI = 0x3,
	WheaErrTypePCIXBus = 0x4,
	WheaErrTypePCIXDevice = 0x5,
	WheaErrTypeGeneric = 0x6
};

struct _WHEA_GENERIC_ERROR_DESCRIPTOR {
	/*0000*/ USHORT Type;
	/*0002*/ UCHAR Reserved;
	/*0003*/ UCHAR Enabled;
	/*0004*/ ULONG ErrStatusBlockLength;
	/*0008*/ ULONG RelatedErrorSourceId;
	/*000c*/ UCHAR ErrStatusAddressSpaceID;
	/*000d*/ UCHAR ErrStatusAddressBitWidth;
	/*000e*/ UCHAR ErrStatusAddressBitOffset;
	/*000f*/ UCHAR ErrStatusAddressAccessSize;
	/*0010*/ _LARGE_INTEGER ErrStatusAddress;
	/*0018*/ _WHEA_NOTIFICATION_DESCRIPTOR Notify;
	/*0034*/
};

struct _WHEA_GENERIC_ERROR_DESCRIPTOR_V2 {
	/*0000*/ USHORT Type;
	/*0002*/ UCHAR Reserved;
	/*0003*/ UCHAR Enabled;
	/*0004*/ ULONG ErrStatusBlockLength;
	/*0008*/ ULONG RelatedErrorSourceId;
	/*000c*/ UCHAR ErrStatusAddressSpaceID;
	/*000d*/ UCHAR ErrStatusAddressBitWidth;
	/*000e*/ UCHAR ErrStatusAddressBitOffset;
	/*000f*/ UCHAR ErrStatusAddressAccessSize;
	/*0010*/ _LARGE_INTEGER ErrStatusAddress;
	/*0018*/ _WHEA_NOTIFICATION_DESCRIPTOR Notify;
	/*0034*/ UCHAR ReadAckAddressSpaceID;
	/*0035*/ UCHAR ReadAckAddressBitWidth;
	/*0036*/ UCHAR ReadAckAddressBitOffset;
	/*0037*/ UCHAR ReadAckAddressAccessSize;
	/*0038*/ _LARGE_INTEGER ReadAckAddress;
	/*0040*/ ULONGLONG ReadAckPreserveMask;
	/*0048*/ ULONGLONG ReadAckWriteMask;
	/*0050*/
};

struct _WHEA_IPF_CMC_DESCRIPTOR {
	/*0000*/ USHORT Type;
	/*0002*/ UCHAR Enabled;
	/*0003*/ UCHAR Reserved;
	/*0004*/
};

struct _WHEA_IPF_CPE_DESCRIPTOR {
	/*0000*/ USHORT Type;
	/*0002*/ UCHAR Enabled;
	/*0003*/ UCHAR Reserved;
	/*0004*/
};

struct _WHEA_IPF_MCA_DESCRIPTOR {
	/*0000*/ USHORT Type;
	/*0002*/ UCHAR Enabled;
	/*0003*/ UCHAR Reserved;
	/*0004*/
};

struct _WHEA_MEMORY_ERROR_SECTION {
	/*0000*/ _WHEA_MEMORY_ERROR_SECTION_VALIDBITS ValidBits;
	/*0008*/ _WHEA_ERROR_STATUS ErrorStatus;
	/*0010*/ ULONGLONG PhysicalAddress;
	/*0018*/ ULONGLONG PhysicalAddressMask;
	/*0020*/ USHORT Node;
	/*0022*/ USHORT Card;
	/*0024*/ USHORT Module;
	/*0026*/ USHORT Bank;
	/*0028*/ USHORT Device;
	/*002a*/ USHORT Row;
	/*002c*/ USHORT Column;
	/*002e*/ USHORT BitPosition;
	/*0030*/ ULONGLONG RequesterId;
	/*0038*/ ULONGLONG ResponderId;
	/*0040*/ ULONGLONG TargetId;
	/*0048*/ UCHAR ErrorType;
	/*0049*/
};

union _WHEA_MEMORY_ERROR_SECTION_VALIDBITS {
	/*0000*/ ULONGLONG ErrorStatus : 01; // 0x0000000000000001;
	/*0000*/ ULONGLONG PhysicalAddress : 01; // 0x0000000000000002;
	/*0000*/ ULONGLONG PhysicalAddressMask : 01; // 0x0000000000000004;
	/*0000*/ ULONGLONG Node : 01; // 0x0000000000000008;
	/*0000*/ ULONGLONG Card : 01; // 0x0000000000000010;
	/*0000*/ ULONGLONG Module : 01; // 0x0000000000000020;
	/*0000*/ ULONGLONG Bank : 01; // 0x0000000000000040;
	/*0000*/ ULONGLONG Device : 01; // 0x0000000000000080;
	/*0000*/ ULONGLONG Row : 01; // 0x0000000000000100;
	/*0000*/ ULONGLONG Column : 01; // 0x0000000000000200;
	/*0000*/ ULONGLONG BitPosition : 01; // 0x0000000000000400;
	/*0000*/ ULONGLONG RequesterId : 01; // 0x0000000000000800;
	/*0000*/ ULONGLONG ResponderId : 01; // 0x0000000000001000;
	/*0000*/ ULONGLONG TargetId : 01; // 0x0000000000002000;
	/*0000*/ ULONGLONG ErrorType : 01; // 0x0000000000004000;
	/*0000*/ ULONGLONG Reserved : 49; // 0xffffffffffff8000;
	/*0000*/ ULONGLONG ValidBits;
	/*0008*/
};

struct _WHEA_NOTIFICATION_DESCRIPTOR {
	/*0000*/ UCHAR Type;
	/*0001*/ UCHAR Length;
	/*0002*/ _WHEA_NOTIFICATION_FLAGS Flags;
	union {
		struct {
			/*0004*/ ULONG PollInterval;
			/*0008*/
		} Polled;
		struct {
			/*0004*/ ULONG PollInterval;
			/*0008*/ ULONG Vector;
			/*000c*/ ULONG SwitchToPollingThreshold;
			/*0010*/ ULONG SwitchToPollingWindow;
			/*0014*/ ULONG ErrorThreshold;
			/*0018*/ ULONG ErrorThresholdWindow;
			/*001c*/
		} Interrupt;
		struct {
			/*0004*/ ULONG PollInterval;
			/*0008*/ ULONG Vector;
			/*000c*/ ULONG SwitchToPollingThreshold;
			/*0010*/ ULONG SwitchToPollingWindow;
			/*0014*/ ULONG ErrorThreshold;
			/*0018*/ ULONG ErrorThresholdWindow;
			/*001c*/
		} LocalInterrupt;
		struct {
			/*0004*/ ULONG PollInterval;
			/*0008*/ ULONG Vector;
			/*000c*/ ULONG SwitchToPollingThreshold;
			/*0010*/ ULONG SwitchToPollingWindow;
			/*0014*/ ULONG ErrorThreshold;
			/*0018*/ ULONG ErrorThresholdWindow;
			/*001c*/
		} Sci;
		struct {
			/*0004*/ ULONG PollInterval;
			/*0008*/ ULONG Vector;
			/*000c*/ ULONG SwitchToPollingThreshold;
			/*0010*/ ULONG SwitchToPollingWindow;
			/*0014*/ ULONG ErrorThreshold;
			/*0018*/ ULONG ErrorThresholdWindow;
			/*001c*/
		} Nmi;
		struct {
			/*0004*/ ULONG PollInterval;
			/*0008*/ ULONG Vector;
			/*000c*/ ULONG SwitchToPollingThreshold;
			/*0010*/ ULONG SwitchToPollingWindow;
			/*0014*/ ULONG ErrorThreshold;
			/*0018*/ ULONG ErrorThresholdWindow;
			/*001c*/
		} Sea;
		struct {
			/*0004*/ ULONG PollInterval;
			/*0008*/ ULONG Vector;
			/*000c*/ ULONG SwitchToPollingThreshold;
			/*0010*/ ULONG SwitchToPollingWindow;
			/*0014*/ ULONG ErrorThreshold;
			/*0018*/ ULONG ErrorThresholdWindow;
			/*001c*/
		} Sei;
		struct {
			/*0004*/ ULONG PollInterval;
			/*0008*/ ULONG Vector;
			/*000c*/ ULONG SwitchToPollingThreshold;
			/*0010*/ ULONG SwitchToPollingWindow;
			/*0014*/ ULONG ErrorThreshold;
			/*0018*/ ULONG ErrorThresholdWindow;
			/*001c*/
		} Gsiv;
		/*001c*/
	} u;
	/*001c*/
};

union _WHEA_NOTIFICATION_FLAGS {
	/*0000*/ USHORT PollIntervalRW : 01; // 0x0001;
	/*0000*/ USHORT SwitchToPollingThresholdRW : 01; // 0x0002;
	/*0000*/ USHORT SwitchToPollingWindowRW : 01; // 0x0004;
	/*0000*/ USHORT ErrorThresholdRW : 01; // 0x0008;
	/*0000*/ USHORT ErrorThresholdWindowRW : 01; // 0x0010;
	/*0000*/ USHORT Reserved : 11; // 0xffe0;
	/*0000*/ USHORT AsUSHORT;
	/*0002*/
};

struct _WHEA_PCI_SLOT_NUMBER {
	union {
		struct {
			/*0000*/ ULONG DeviceNumber : 05; // 0x0000001f;
			/*0000*/ ULONG FunctionNumber : 03; // 0x000000e0;
			/*0000*/ ULONG Reserved : 24; // 0xffffff00;
			/*0004*/
		} bits;
		/*0000*/ ULONG AsULONG;
		/*0004*/
	} u;
	/*0004*/
};

union _WHEA_PERSISTENCE_INFO {
	/*0000*/ ULONGLONG Signature : 16; // 0x000000000000ffff;
	/*0000*/ ULONGLONG Length : 24; // 0x000000ffffff0000;
	/*0000*/ ULONGLONG Identifier : 16; // 0x00ffff0000000000;
	/*0000*/ ULONGLONG Attributes : 02; // 0x0300000000000000;
	/*0000*/ ULONGLONG DoNotLog : 01; // 0x0400000000000000;
	/*0000*/ ULONGLONG Reserved : 05; // 0xf800000000000000;
	/*0000*/ ULONGLONG AsULONGLONG;
	/*0008*/
};

union _WHEA_REVISION {
	/*0000*/ UCHAR MinorRevision;
	/*0001*/ UCHAR MajorRevision;
	/*0000*/ USHORT AsUSHORT;
	/*0002*/
};

union _WHEA_TIMESTAMP {
	/*0000*/ ULONGLONG Seconds : 08; // 0x00000000000000ff;
	/*0000*/ ULONGLONG Minutes : 08; // 0x000000000000ff00;
	/*0000*/ ULONGLONG Hours : 08; // 0x0000000000ff0000;
	/*0000*/ ULONGLONG Precise : 01; // 0x0000000001000000;
	/*0000*/ ULONGLONG Reserved : 07; // 0x00000000fe000000;
	/*0000*/ ULONGLONG Day : 08; // 0x000000ff00000000;
	/*0000*/ ULONGLONG Month : 08; // 0x0000ff0000000000;
	/*0000*/ ULONGLONG Year : 08; // 0x00ff000000000000;
	/*0000*/ ULONGLONG Century : 08; // 0xff00000000000000;
	/*0000*/ _LARGE_INTEGER AsLARGE_INTEGER;
	/*0008*/
};

struct _WHEA_XPF_CMC_DESCRIPTOR {
	/*0000*/ USHORT Type;
	/*0002*/ UCHAR Enabled;
	/*0003*/ UCHAR NumberOfBanks;
	/*0004*/ ULONG Reserved;
	/*0008*/ _WHEA_NOTIFICATION_DESCRIPTOR Notify;
	/*0024*/ _WHEA_XPF_MC_BANK_DESCRIPTOR Banks[0x20];
	/*03a4*/
};

struct _WHEA_XPF_MCE_DESCRIPTOR {
	/*0000*/ USHORT Type;
	/*0002*/ UCHAR Enabled;
	/*0003*/ UCHAR NumberOfBanks;
	/*0004*/ _XPF_MCE_FLAGS Flags;
	/*0008*/ ULONGLONG MCG_Capability;
	/*0010*/ ULONGLONG MCG_GlobalControl;
	/*0018*/ _WHEA_XPF_MC_BANK_DESCRIPTOR Banks[0x20];
	/*0398*/
};

struct _WHEA_XPF_MC_BANK_DESCRIPTOR {
	/*0000*/ UCHAR BankNumber;
	/*0001*/ UCHAR ClearOnInitialization;
	/*0002*/ UCHAR StatusDataFormat;
	/*0003*/ _XPF_MC_BANK_FLAGS Flags;
	/*0004*/ ULONG ControlMsr;
	/*0008*/ ULONG StatusMsr;
	/*000c*/ ULONG AddressMsr;
	/*0010*/ ULONG MiscMsr;
	/*0014*/ ULONGLONG ControlData;
	/*001c*/
};

struct _WHEA_XPF_NMI_DESCRIPTOR {
	/*0000*/ USHORT Type;
	/*0002*/ UCHAR Enabled;
	/*0003*/
};

struct _WMI_BUFFER_HEADER {
	/*0000*/ ULONG BufferSize;
	/*0004*/ ULONG SavedOffset;
	/*0008*/ ULONG volatile CurrentOffset;
	/*000c*/ LONG volatile ReferenceCount;
	/*0010*/ _LARGE_INTEGER TimeStamp;
	/*0018*/ LONGLONG SequenceNumber;
	/*0020*/ ULONGLONG ClockType : 03; // 0x0000000000000007;
	/*0020*/ ULONGLONG Frequency : 61; // 0xfffffffffffffff8;
	/*0020*/ _SINGLE_LIST_ENTRY SlistEntry;
	/*0020*/ _WMI_BUFFER_HEADER * NextBuffer;
	/*0028*/ _ETW_BUFFER_CONTEXT ClientContext;
	/*002c*/ _ETW_BUFFER_STATE State;
	/*0030*/ ULONG Offset;
	/*0034*/ USHORT BufferFlag;
	/*0036*/ USHORT BufferType;
	/*0038*/ ULONG Padding1[0x4];
	/*0038*/ _ETW_REF_CLOCK ReferenceTime;
	/*0038*/ _LIST_ENTRY GlobalEntry;
	/*0038*/ void * Pointer0;
	/*0040*/ void * Pointer1;
	/*0048*/
};

struct _WMI_LOGGER_CONTEXT {
	/*0000*/ ULONG LoggerId;
	/*0004*/ ULONG BufferSize;
	/*0008*/ ULONG MaximumEventSize;
	/*000c*/ ULONG LoggerMode;
	/*0010*/ LONG AcceptNewEvents;
	/*0014*/ ULONG EventMarker[0x2];
	/*001c*/ ULONG ErrorMarker;
	/*0020*/ ULONG SizeMask;
	/*0028*/ LONGLONG (* GetCpuClock)();
	/*0030*/ _ETHREAD * LoggerThread;
	/*0038*/ LONG LoggerStatus;
	/*003c*/ ULONG FailureReason;
	/*0040*/ _ETW_BUFFER_QUEUE BufferQueue;
	/*0050*/ _ETW_BUFFER_QUEUE OverflowQueue;
	/*0060*/ _LIST_ENTRY GlobalList;
	/*0070*/ _LIST_ENTRY DebugIdTrackingList;
	/*0080*/ _ETW_DECODE_CONTROL_ENTRY * DecodeControlList;
	/*0088*/ ULONG DecodeControlCount;
	/*0090*/ _WMI_BUFFER_HEADER * BatchedBufferList;
	/*0090*/ _EX_FAST_REF CurrentBuffer;
	/*0098*/ _UNICODE_STRING LoggerName;
	/*00a8*/ _UNICODE_STRING LogFileName;
	/*00b8*/ _UNICODE_STRING LogFilePattern;
	/*00c8*/ _UNICODE_STRING NewLogFileName;
	/*00d8*/ ULONG ClockType;
	/*00dc*/ ULONG LastFlushedBuffer;
	/*00e0*/ ULONG FlushTimer;
	/*00e4*/ ULONG FlushThreshold;
	/*00e8*/ _LARGE_INTEGER ByteOffset;
	/*00f0*/ ULONG MinimumBuffers;
	/*00f4*/ LONG volatile BuffersAvailable;
	/*00f8*/ LONG volatile NumberOfBuffers;
	/*00fc*/ ULONG MaximumBuffers;
	/*0100*/ ULONG volatile EventsLost;
	/*0104*/ LONG volatile PeakBuffersCount;
	/*0108*/ ULONG BuffersWritten;
	/*010c*/ ULONG LogBuffersLost;
	/*0110*/ ULONG RealTimeBuffersDelivered;
	/*0114*/ ULONG RealTimeBuffersLost;
	/*0118*/ LONG * SequencePtr;
	/*0120*/ ULONG LocalSequence;
	/*0124*/ _GUID InstanceGuid;
	/*0134*/ ULONG MaximumFileSize;
	/*0138*/ LONG FileCounter;
	/*013c*/ _POOL_TYPE PoolType;
	/*0140*/ _ETW_REF_CLOCK ReferenceTime;
	/*0150*/ LONG CollectionOn;
	/*0154*/ ULONG ProviderInfoSize;
	/*0158*/ _LIST_ENTRY Consumers;
	/*0168*/ ULONG NumConsumers;
	/*0170*/ _ETW_REALTIME_CONSUMER * TransitionConsumer;
	/*0178*/ void * RealtimeLogfileHandle;
	/*0180*/ _UNICODE_STRING RealtimeLogfileName;
	/*0190*/ _LARGE_INTEGER RealtimeWriteOffset;
	/*0198*/ _LARGE_INTEGER RealtimeReadOffset;
	/*01a0*/ _LARGE_INTEGER RealtimeLogfileSize;
	/*01a8*/ ULONGLONG RealtimeLogfileUsage;
	/*01b0*/ ULONGLONG RealtimeMaximumFileSize;
	/*01b8*/ ULONG RealtimeBuffersSaved;
	/*01c0*/ _ETW_REF_CLOCK RealtimeReferenceTime;
	/*01d0*/ _ETW_RT_EVENT_LOSS NewRTEventsLost;
	/*01d8*/ _KEVENT LoggerEvent;
	/*01f0*/ _KEVENT FlushEvent;
	/*0208*/ _KTIMER FlushTimeOutTimer;
	/*0248*/ _KDPC LoggerDpc;
	/*0288*/ _KMUTANT LoggerMutex;
	/*02c0*/ _EX_PUSH_LOCK LoggerLock;
	/*02c8*/ ULONGLONG BufferListSpinLock;
	/*02c8*/ _EX_PUSH_LOCK BufferListPushLock;
	/*02d0*/ _SECURITY_CLIENT_CONTEXT ClientSecurityContext;
	/*0318*/ _TOKEN_ACCESS_INFORMATION * TokenAccessInformation;
	/*0320*/ _EX_FAST_REF SecurityDescriptor;
	/*0328*/ _LARGE_INTEGER StartTime;
	/*0330*/ void * LogFileHandle;
	/*0338*/ LONGLONG BufferSequenceNumber;
	/*0340*/ ULONG Flags;
	/*0340*/ ULONG Persistent : 01; // 0x00000001;
	/*0340*/ ULONG AutoLogger : 01; // 0x00000002;
	/*0340*/ ULONG FsReady : 01; // 0x00000004;
	/*0340*/ ULONG RealTime : 01; // 0x00000008;
	/*0340*/ ULONG Wow : 01; // 0x00000010;
	/*0340*/ ULONG KernelTrace : 01; // 0x00000020;
	/*0340*/ ULONG NoMoreEnable : 01; // 0x00000040;
	/*0340*/ ULONG StackTracing : 01; // 0x00000080;
	/*0340*/ ULONG ErrorLogged : 01; // 0x00000100;
	/*0340*/ ULONG RealtimeLoggerContextFreed : 01; // 0x00000200;
	/*0340*/ ULONG PebsTracing : 01; // 0x00000400;
	/*0340*/ ULONG PmcCounters : 01; // 0x00000800;
	/*0340*/ ULONG PageAlignBuffers : 01; // 0x00001000;
	/*0340*/ ULONG StackLookasideListAllocated : 01; // 0x00002000;
	/*0340*/ ULONG SecurityTrace : 01; // 0x00004000;
	/*0340*/ ULONG LastBranchTracing : 01; // 0x00008000;
	/*0340*/ ULONG SystemLoggerIndex : 08; // 0x00ff0000;
	/*0340*/ ULONG StackCaching : 01; // 0x01000000;
	/*0340*/ ULONG SpareFlags2 : 07; // 0xfe000000;
	/*0344*/ ULONG volatile RequestFlag;
	/*0344*/ ULONG DbgRequestNewFile : 01; // 0x00000001;
	/*0344*/ ULONG DbgRequestUpdateFile : 01; // 0x00000002;
	/*0344*/ ULONG DbgRequestFlush : 01; // 0x00000004;
	/*0344*/ ULONG DbgRequestDisableRealtime : 01; // 0x00000008;
	/*0344*/ ULONG DbgRequestDisconnectConsumer : 01; // 0x00000010;
	/*0344*/ ULONG DbgRequestConnectConsumer : 01; // 0x00000020;
	/*0344*/ ULONG DbgRequestNotifyConsumer : 01; // 0x00000040;
	/*0344*/ ULONG DbgRequestUpdateHeader : 01; // 0x00000080;
	/*0344*/ ULONG DbgRequestDeferredFlush : 01; // 0x00000100;
	/*0344*/ ULONG DbgRequestDeferredFlushTimer : 01; // 0x00000200;
	/*0344*/ ULONG DbgRequestFlushTimer : 01; // 0x00000400;
	/*0344*/ ULONG DbgRequestUpdateDebugger : 01; // 0x00000800;
	/*0344*/ ULONG DbgSpareRequestFlags : 20; // 0xfffff000;
	/*0350*/ _ETW_STACK_TRACE_BLOCK StackTraceBlock;
	/*0850*/ _RTL_BITMAP HookIdMap;
	/*0860*/ _ETW_STACK_CACHE * StackCache;
	/*0868*/ _ETW_PMC_SUPPORT * PmcData;
	/*0870*/ _ETW_LBR_SUPPORT * LbrData;
	/*0878*/ _LIST_ENTRY BinaryTrackingList;
	/*0888*/ _WMI_BUFFER_HEADER * * ScratchArray;
	/*0890*/ _DISALLOWED_GUIDS DisallowedGuids;
	/*08a0*/ LONGLONG RelativeTimerDueTime;
	/*08a8*/ _PERIODIC_CAPTURE_STATE_GUIDS PeriodicCaptureStateGuids;
	/*08b8*/ _EX_TIMER * PeriodicCaptureStateTimer;
	/*08c0*/ _ETW_PERIODIC_TIMER_STATE PeriodicCaptureStateTimerState;
	/*08c8*/ _ETW_SOFT_RESTART_CONTEXT * SoftRestartContext;
	/*08d0*/ _ETW_SILODRIVERSTATE * SiloState;
	/*08d8*/ _WORK_QUEUE_ITEM CompressionWorkItem;
	/*08f8*/ LONG CompressionWorkItemState;
	/*0900*/ _EX_PUSH_LOCK CompressionLock;
	/*0908*/ _WMI_BUFFER_HEADER * CompressionTarget;
	/*0910*/ void * CompressionWorkspace;
	/*0918*/ LONG CompressionOn;
	/*091c*/ ULONG CompressionRatioGuess;
	/*0920*/ ULONG PartialBufferCompressionLevel;
	/*0924*/ ETW_COMPRESSION_RESUMPTION_MODE CompressionResumptionMode;
	/*0928*/ _SINGLE_LIST_ENTRY PlaceholderList;
	/*0930*/ _KDPC CompressionDpc;
	/*0970*/ _LARGE_INTEGER LastBufferSwitchTime;
	/*0978*/ _LARGE_INTEGER BufferWriteDuration;
	/*0980*/ _LARGE_INTEGER BufferCompressDuration;
	/*0990*/
};

struct _WNF_LOCK {
	/*0000*/ _EX_PUSH_LOCK PushLock;
	/*0008*/
};

struct _WNF_SCOPE_MAP;

struct _WNF_SILODRIVERSTATE {
	/*0000*/ _WNF_SCOPE_MAP * ScopeMap;
	/*0008*/ void * volatile PermanentNameStoreRootKey;
	/*0010*/ void * volatile PersistentNameStoreRootKey;
	/*0018*/ LONGLONG volatile PermanentNameSequenceNumber;
	/*0020*/ _WNF_LOCK PermanentNameSequenceNumberLock;
	/*0028*/ LONGLONG volatile PermanentNameSequenceNumberPool;
	/*0030*/ LONGLONG volatile RuntimeNameSequenceNumber;
	/*0038*/
};

struct _WNF_STATE_NAME {
	/*0000*/ ULONG Data[0x2];
	/*0008*/
};

enum _WORKING_SET_TYPE {
	WorkingSetTypeUser = 0x0,
	WorkingSetTypeSession = 0x1,
	WorkingSetTypeSystemTypes = 0x2,
	WorkingSetTypeSystemCache = 0x2,
	WorkingSetTypePagedPool = 0x3,
	WorkingSetTypeSystemPtes = 0x4,
	WorkingSetTypeMaximum = 0x5
};

struct _WORK_QUEUE_ENTRY {
	/*0000*/ _LIST_ENTRY WorkQueueLinks;
	union {
		struct {
			/*0010*/ _FILE_OBJECT * FileObject;
			/*0018*/ void * DiskIoAttribution;
			/*0020*/
		} Read;
		struct {
			/*0010*/ _SHARED_CACHE_MAP * SharedCacheMap;
			/*0018*/
		} Write;
		struct {
			/*0010*/ _KEVENT * Event;
			/*0018*/
		} Event;
		struct {
			/*0010*/ ULONG Reason;
			/*0014*/
		} Notification;
		struct {
			/*0010*/ _SHARED_CACHE_MAP * SharedCacheMap;
			/*0018*/ _IO_STATUS_BLOCK * IoStatus;
			/*0020*/ _KEVENT CallerWaitEvent;
			/*0038*/ UCHAR IsLowPriWriteBehind;
			/*0040*/
		} LowPriWrite;
		struct {
			/*0010*/ _SHARED_CACHE_MAP * SharedCacheMap;
			/*0018*/ _LARGE_INTEGER FileOffset;
			/*0020*/ _FILE_OBJECT * FileObject;
			/*0028*/ ULONG Length;
			/*0030*/ _SINGLE_LIST_ENTRY * PrefetchList;
			/*0038*/ ULONG PrefetchPagePriority;
			/*0040*/ _MDL * Mdl;
			/*0048*/ _IO_STATUS_BLOCK * IoStatusBlock;
			/*0050*/ _CC_ASYNC_READ_CONTEXT * CallbackContext;
			/*0058*/ _EPROCESS * OriginatingProcess;
			/*0060*/ _ETHREAD * IoIssuerThread;
			/*0068*/ void * DiskIoAttribution;
			/*0070*/ CHAR RequestorMode;
			/*0074*/ ULONG NestingLevel;
			/*0078*/
		} AsyncRead;
		/*0078*/
	} Parameters;
	/*0078*/ UCHAR Function;
	/*0080*/ _CC_PARTITION * Partition;
	/*0088*/
};

struct _WORK_QUEUE_ITEM {
	/*0000*/ _LIST_ENTRY List;
	/*0010*/ void (* WorkerRoutine)( void * );
	/*0018*/ void * Parameter;
	/*0020*/
};

enum _WOW64_SHARED_INFORMATION {
	SharedNtdll32LdrInitializeThunk = 0x0,
	SharedNtdll32KiUserExceptionDispatcher = 0x1,
	SharedNtdll32KiUserApcDispatcher = 0x2,
	SharedNtdll32KiUserCallbackDispatcher = 0x3,
	SharedNtdll32RtlUserThreadStart = 0x4,
	SharedNtdll32pQueryProcessDebugInformationRemote = 0x5,
	SharedNtdll32BaseAddress = 0x6,
	SharedNtdll32LdrSystemDllInitBlock = 0x7,
	SharedNtdll32RtlpFreezeTimeBias = 0x8,
	Wow64SharedPageEntriesCount = 0x9
};

struct _WRITE_BEHIND_THROUGHPUT {
	/*0000*/ ULONG PagesYetToWrite;
	/*0004*/ ULONG Throughput;
	/*0008*/
};

struct _X86_DBGKD_CONTROL_SET {
	/*0000*/ ULONG TraceFlag;
	/*0004*/ ULONG Dr7;
	/*0008*/ ULONG CurrentSymbolStart;
	/*000c*/ ULONG CurrentSymbolEnd;
	/*0010*/
};

struct _X86_KTRAP_FRAME {
	/*0000*/ ULONG DbgEbp;
	/*0004*/ ULONG DbgEip;
	/*0008*/ ULONG DbgArgMark;
	/*000c*/ ULONG DbgArgPointer;
	/*0010*/ ULONG TempSegCs;
	/*0014*/ ULONG TempEsp;
	/*0018*/ ULONG Dr0;
	/*001c*/ ULONG Dr1;
	/*0020*/ ULONG Dr2;
	/*0024*/ ULONG Dr3;
	/*0028*/ ULONG Dr6;
	/*002c*/ ULONG Dr7;
	/*0030*/ ULONG SegGs;
	/*0034*/ ULONG SegEs;
	/*0038*/ ULONG SegDs;
	/*003c*/ ULONG Edx;
	/*0040*/ ULONG Ecx;
	/*0044*/ ULONG Eax;
	/*0048*/ UCHAR PreviousPreviousMode;
	/*0049*/ UCHAR EntropyQueueDpc;
	/*004a*/ UCHAR Reserved[0x2];
	/*004c*/ ULONG ExceptionList;
	/*0050*/ ULONG SegFs;
	/*0054*/ ULONG Edi;
	/*0058*/ ULONG Esi;
	/*005c*/ ULONG Ebx;
	/*0060*/ ULONG Ebp;
	/*0064*/ ULONG ErrCode;
	/*0068*/ ULONG Eip;
	/*006c*/ ULONG SegCs;
	/*0070*/ ULONG EFlags;
	/*0074*/ ULONG HardwareEsp;
	/*0078*/ ULONG HardwareSegSs;
	/*007c*/ ULONG V86Es;
	/*0080*/ ULONG V86Ds;
	/*0084*/ ULONG V86Fs;
	/*0088*/ ULONG V86Gs;
	/*008c*/
};

struct _X86_KTRAP_FRAME_BLUE {
	/*0000*/ ULONG DbgEbp;
	/*0004*/ ULONG DbgEip;
	/*0008*/ ULONG DbgArgMark;
	/*000c*/ USHORT TempSegCs;
	/*000e*/ UCHAR Logging;
	/*000f*/ UCHAR FrameType;
	/*0010*/ ULONG TempEsp;
	/*0014*/ ULONG Dr0;
	/*0018*/ ULONG Dr1;
	/*001c*/ ULONG Dr2;
	/*0020*/ ULONG Dr3;
	/*0024*/ ULONG Dr6;
	/*0028*/ ULONG Dr7;
	/*002c*/ ULONG SegGs;
	/*0030*/ ULONG SegEs;
	/*0034*/ ULONG SegDs;
	/*0038*/ ULONG Edx;
	/*003c*/ ULONG Ecx;
	/*0040*/ ULONG Eax;
	/*0044*/ UCHAR PreviousPreviousMode;
	/*0045*/ UCHAR EntropyQueueDpc;
	/*0046*/ UCHAR Reserved[0x2];
	/*0048*/ ULONG MxCsr;
	/*004c*/ ULONG ExceptionList;
	/*0050*/ ULONG SegFs;
	/*0054*/ ULONG Edi;
	/*0058*/ ULONG Esi;
	/*005c*/ ULONG Ebx;
	/*0060*/ ULONG Ebp;
	/*0064*/ ULONG ErrCode;
	/*0068*/ ULONG Eip;
	/*006c*/ ULONG SegCs;
	/*0070*/ ULONG EFlags;
	/*0074*/ ULONG HardwareEsp;
	/*0078*/ ULONG HardwareSegSs;
	/*007c*/ ULONG V86Es;
	/*0080*/ ULONG V86Ds;
	/*0084*/ ULONG V86Fs;
	/*0088*/ ULONG V86Gs;
	/*008c*/
};

union _XPF_MCE_FLAGS {
	/*0000*/ ULONG MCG_CapabilityRW : 01; // 0x00000001;
	/*0000*/ ULONG MCG_GlobalControlRW : 01; // 0x00000002;
	/*0000*/ ULONG Reserved : 30; // 0xfffffffc;
	/*0000*/ ULONG AsULONG;
	/*0004*/
};

union _XPF_MC_BANK_FLAGS {
	/*0000*/ UCHAR ClearOnInitializationRW : 01; // 0x01;
	/*0000*/ UCHAR ControlDataRW : 01; // 0x02;
	/*0000*/ UCHAR Reserved : 06; // 0xfc;
	/*0000*/ UCHAR AsUCHAR;
	/*0001*/
};

struct _XSAVE_AREA {
	/*0000*/ _XSAVE_FORMAT LegacyState;
	/*0200*/ _XSAVE_AREA_HEADER Header;
	/*0240*/
};

struct _XSAVE_AREA_HEADER {
	/*0000*/ ULONGLONG Mask;
	/*0008*/ ULONGLONG CompactionMask;
	/*0010*/ ULONGLONG Reserved2[0x6];
	/*0040*/
};

struct _XSAVE_FORMAT {
	/*0000*/ USHORT ControlWord;
	/*0002*/ USHORT StatusWord;
	/*0004*/ UCHAR TagWord;
	/*0005*/ UCHAR Reserved1;
	/*0006*/ USHORT ErrorOpcode;
	/*0008*/ ULONG ErrorOffset;
	/*000c*/ USHORT ErrorSelector;
	/*000e*/ USHORT Reserved2;
	/*0010*/ ULONG DataOffset;
	/*0014*/ USHORT DataSelector;
	/*0016*/ USHORT Reserved3;
	/*0018*/ ULONG MxCsr;
	/*001c*/ ULONG MxCsr_Mask;
	/*0020*/ _M128A FloatRegisters[0x8];
	/*00a0*/ _M128A XmmRegisters[0x10];
	/*01a0*/ UCHAR Reserved4[0x60];
	/*0200*/
};

struct _XSTATE_CONFIGURATION {
	/*0000*/ ULONGLONG EnabledFeatures;
	/*0008*/ ULONGLONG EnabledVolatileFeatures;
	/*0010*/ ULONG Size;
	/*0014*/ ULONG ControlFlags;
	/*0014*/ ULONG OptimizedSave : 01; // 0x00000001;
	/*0014*/ ULONG CompactionEnabled : 01; // 0x00000002;
	/*0018*/ _XSTATE_FEATURE Features[0x40];
	/*0218*/ ULONGLONG EnabledSupervisorFeatures;
	/*0220*/ ULONGLONG AlignedFeatures;
	/*0228*/ ULONG AllFeatureSize;
	/*022c*/ ULONG AllFeatures[0x40];
	/*0330*/
};

struct _XSTATE_CONTEXT {
	/*0000*/ ULONGLONG Mask;
	/*0008*/ ULONG Length;
	/*000c*/ ULONG Reserved1;
	/*0010*/ _XSAVE_AREA * Area;
	/*0018*/ void * Buffer;
	/*0020*/
};

struct _XSTATE_FEATURE {
	/*0000*/ ULONG Offset;
	/*0004*/ ULONG Size;
	/*0008*/
};

struct _XSTATE_SAVE {
	/*0000*/ _XSTATE_SAVE * Prev;
	/*0008*/ _KTHREAD * Thread;
	/*0010*/ UCHAR Level;
	/*0018*/ _XSTATE_CONTEXT XStateContext;
	/*0038*/
};

struct _flags {
	/*0000*/ UCHAR Removable : 01; // 0x01;
	/*0000*/ UCHAR GroupAssigned : 01; // 0x02;
	/*0000*/ UCHAR GroupCommitted : 01; // 0x04;
	/*0000*/ UCHAR GroupAssignmentFixed : 01; // 0x08;
	/*0000*/ UCHAR Fill : 04; // 0xf0;
	/*0001*/
};

struct _iobuf {
	/*0000*/ CHAR * _ptr;
	/*0008*/ INT _cnt;
	/*0010*/ CHAR * _base;
	/*0018*/ INT _flag;
	/*001c*/ INT _file;
	/*0020*/ INT _charbuf;
	/*0024*/ INT _bufsiz;
	/*0028*/ CHAR * _tmpfname;
	/*0030*/
};

union _u {
	/*0000*/ _CM_KEY_NODE KeyNode;
	/*0000*/ _CM_KEY_VALUE KeyValue;
	/*0000*/ _CM_KEY_SECURITY KeySecurity;
	/*0000*/ _CM_KEY_INDEX KeyIndex;
	/*0000*/ _CM_BIG_DATA ValueData;
	/*0000*/ ULONG KeyList[0x1];
	/*0000*/ WCHAR KeyString[0x1];
	/*0050*/
};

struct tagSWITCH_CONTEXT {
	/*0000*/ tagSWITCH_CONTEXT_ATTRIBUTE Attribute;
	/*0018*/ tagSWITCH_CONTEXT_DATA Data;
	/*0358*/
};

struct tagSWITCH_CONTEXT_ATTRIBUTE {
	/*0000*/ ULONGLONG ulContextUpdateCounter;
	/*0008*/ INT fAllowContextUpdate;
	/*000c*/ INT fEnableTrace;
	/*0010*/ ULONGLONG EtwHandle;
	/*0018*/
};

struct tagSWITCH_CONTEXT_DATA {
	/*0000*/ ULONGLONG ullOsMaxVersionTested;
	/*0008*/ ULONG ulTargetPlatform;
	/*0010*/ ULONGLONG ullContextMinimum;
	/*0018*/ _GUID guPlatform;
	/*0028*/ _GUID guMinPlatform;
	/*0038*/ ULONG ulContextSource;
	/*003c*/ ULONG ulElementCount;
	/*0040*/ _GUID guElements[0x30];
	/*0340*/
};
