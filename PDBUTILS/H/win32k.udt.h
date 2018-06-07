
namespace __vc_attributes {

	namespace helper_attributes {

		struct usageAttribute {
		
			enum usage_e {
				eAnyUsage = 0x0,
				eCoClassUsage = 0x1,
				eCOMInterfaceUsage = 0x2,
				eInterfaceUsage = 0x6,
				eMemberUsage = 0x8,
				eMethodUsage = 0x10,
				eInterfaceMethodUsage = 0x20,
				eInterfaceMemberUsage = 0x40,
				eCoClassMemberUsage = 0x80,
				eCoClassMethodUsage = 0x100,
				eGlobalMethodUsage = 0x300,
				eGlobalDataUsage = 0x400,
				eClassUsage = 0x800,
				eInterfaceParameterUsage = 0x1000,
				eMethodParameterUsage = 0x3000,
				eIDLModuleUsage = 0x4000,
				eAnonymousUsage = 0x8000,
				eTypedefUsage = 0x10000,
				eUnionUsage = 0x20000,
				eEnumUsage = 0x40000,
				eDefineTagUsage = 0x80000,
				eStructUsage = 0x100000,
				eLocalUsage = 0x200000,
				ePropertyUsage = 0x400000,
				eEventUsage = 0x800000,
				eTemplateUsage = 0x1000000,
				eModuleUsage = 0x1000000,
				eIllegalUsage = 0x2000000,
				eAsynchronousUsage = 0x4000000,
				eAnyIDLUsage = 0x3f7fff
			};

			void usageAttribute( UINT );
			/*0000*/ UINT value;
			/*0004*/
		};

		struct v1_alttypeAttribute {
		
			enum type_e {
				eBoolean = 0x0,
				eInteger = 0x1,
				eFloat = 0x2,
				eDouble = 0x3
			};

			void v1_alttypeAttribute( type_e );
			/*0000*/ type_e type;
			/*0004*/
		};

	}

	struct aggregatableAttribute {
	
		enum type_e {
			never = 0x0,
			allowed = 0x1,
			always = 0x2
		};

		void aggregatableAttribute( type_e );
		void aggregatableAttribute();
		/*0000*/ type_e type;
		/*0004*/
	};

	struct event_receiverAttribute {
	
		enum type_e {
			native = 0x0,
			com = 0x1,
			managed = 0x2
		};

		void event_receiverAttribute( type_e , BOOLEAN );
		void event_receiverAttribute( type_e );
		void event_receiverAttribute();
		/*0000*/ type_e type;
		/*0004*/ BOOLEAN layout_dependent;
		/*0008*/
	};

	struct event_sourceAttribute {
	
		enum type_e {
			native = 0x0,
			com = 0x1,
			managed = 0x2
		};

	
		enum optimize_e {
			speed = 0x0,
			size = 0x1
		};

		void event_sourceAttribute( type_e );
		void event_sourceAttribute();
		/*0000*/ type_e type;
		/*0004*/ optimize_e optimize;
		/*0008*/ BOOLEAN decorate;
		/*000c*/
	};

	struct moduleAttribute {
	
		enum type_e {
			dll = 0x1,
			exe = 0x2,
			service = 0x3,
			unspecified = 0x4,
			EXE = 0x2,
			SERVICE = 0x3
		};

		void moduleAttribute( type_e , CHAR const * , CHAR const * , CHAR const * , INT , BOOLEAN , CHAR const * , INT , CHAR const * , CHAR const * , INT , BOOLEAN , BOOLEAN , CHAR const * , CHAR const * );
		void moduleAttribute( type_e );
		void moduleAttribute();
		/*0000*/ type_e type;
		/*0008*/ CHAR const * name;
		/*0010*/ CHAR const * version;
		/*0018*/ CHAR const * uuid;
		/*0020*/ INT lcid;
		/*0024*/ BOOLEAN control;
		/*0028*/ CHAR const * helpstring;
		/*0030*/ INT helpstringcontext;
		/*0038*/ CHAR const * helpstringdll;
		/*0040*/ CHAR const * helpfile;
		/*0048*/ INT helpcontext;
		/*004c*/ BOOLEAN hidden;
		/*004d*/ BOOLEAN restricted;
		/*0050*/ CHAR const * custom;
		/*0058*/ CHAR const * resource_name;
		/*0060*/
	};

	struct threadingAttribute {
	
		enum threading_e {
			apartment = 0x1,
			single = 0x2,
			free = 0x3,
			neutral = 0x4,
			both = 0x5
		};

		void threadingAttribute( threading_e );
		void threadingAttribute();
		/*0000*/ threading_e value;
		/*0004*/
	};

}

enum {
	DMM_DIAG_INFO_VISTA_BETA2_VERSION = 0x1001,
	DMM_DIAG_INFO_VISTA_RC1_VERSION = 0x1002,
	DMM_DIAG_INFO_VISTA_RTM_VERSION = 0x1003,
	DMM_DIAG_INFO_WIN7_MQ_VERSION = 0x2000,
	DMM_DIAG_INFO_WIN7_M3_VERSION = 0x2001,
	DMM_DIAG_INFO_WIN8_M1_VERSION = 0x3000,
	DMM_DIAG_INFO_BLUE_M1_VERSION = 0x4000,
	DMM_DIAG_INFO_BLUE_MP_VERSION = 0x5000,
	DMM_DIAG_INFO_VERSION = 0x5000
};

enum {
	GDEV_DEVNAMELEN = 0x20
};

struct {
	/*0000*/ ULONG DesktopScaleFactor;
	/*0004*/ _MODERN_SCALE_FACTOR ModernScaleFactor;
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

struct D3DDDI_DXGI_RGB {
	/*0000*/ float Red;
	/*0004*/ float Green;
	/*0008*/ float Blue;
	/*000c*/
};

enum DEVICE_TEXT_TYPE {
	DeviceTextDescription = 0x0,
	DeviceTextLocationInformation = 0x1
};

enum DISPLAYCONFIG_SCANLINE_ORDERING {
	DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED = 0x0,
	DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE = 0x1,
	DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED = 0x2,
	DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST = 0x2,
	DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST = 0x3,
	DISPLAYCONFIG_SCANLINE_ORDERING_FORCE_UINT32 = 0xffffffff
};

enum DIT_HITTESTATTRIBUTES {
	DIT_HITTESTATTRIBUTES_NONE = 0x0,
	DIT_HITTESTATTRIBUTES_MOUSEWHEEL = 0x1,
	DIT_HITTESTATTRIBUTES_MOUSEBUTTONDOWN = 0x2,
	DIT_HITTESTATTRIBUTES_VALID = 0x3
};

enum DMA_COMPLETION_STATUS {
	DmaComplete = 0x0,
	DmaAborted = 0x1,
	DmaError = 0x2,
	DmaCancelled = 0x3
};

enum DPI_AWARENESS {
	DPI_AWARENESS_INVALID = 0xffffffff,
	DPI_AWARENESS_UNAWARE = 0x0,
	DPI_AWARENESS_SYSTEM_AWARE = 0x1,
	DPI_AWARENESS_PER_MONITOR_AWARE = 0x2
};

struct GDIHandleBitFields {
	/*0000*/ ULONGLONG Index : 16; // 0x000000000000ffff;
	/*0000*/ ULONGLONG Type : 05; // 0x00000000001f0000;
	/*0000*/ ULONGLONG AltType : 02; // 0x0000000000600000;
	/*0000*/ ULONGLONG Stock : 01; // 0x0000000000800000;
	/*0000*/ ULONGLONG Unique : 08; // 0x00000000ff000000;
	/*0008*/
};

enum GDILoObjType {
	GDILoObjType_LO_BRUSH_TYPE = 0x100000,
	GDILoObjType_LO_DC_TYPE = 0x10000,
	GDILoObjType_LO_BITMAP_TYPE = 0x50000,
	GDILoObjType_LO_PALETTE_TYPE = 0x80000,
	GDILoObjType_LO_FONT_TYPE = 0xa0000,
	GDILoObjType_LO_REGION_TYPE = 0x40000,
	GDILoObjType_LO_ICMLCS_TYPE = 0x90000,
	GDILoObjType_LO_CLIENTOBJ_TYPE = 0x60000,
	GDILoObjType_LO_ALTDC_TYPE = 0x210000,
	GDILoObjType_LO_PEN_TYPE = 0x300000,
	GDILoObjType_LO_EXTPEN_TYPE = 0x500000,
	GDILoObjType_LO_DIBSECTION_TYPE = 0x250000,
	GDILoObjType_LO_METAFILE16_TYPE = 0x260000,
	GDILoObjType_LO_METAFILE_TYPE = 0x460000,
	GDILoObjType_LO_METADC16_TYPE = 0x660000
};

enum GDIObjType {
	GDIObjType_DEF_TYPE = 0x0,
	GDIObjType_DC_TYPE = 0x1,
	GDIObjType_UNUSED2_TYPE = 0x2,
	GDIObjType_UNUSED3_TYPE = 0x3,
	GDIObjType_RGN_TYPE = 0x4,
	GDIObjType_SURF_TYPE = 0x5,
	GDIObjType_CLIENTOBJ_TYPE = 0x6,
	GDIObjType_PATH_TYPE = 0x7,
	GDIObjType_PAL_TYPE = 0x8,
	GDIObjType_ICMLCS_TYPE = 0x9,
	GDIObjType_LFONT_TYPE = 0xa,
	GDIObjType_RFONT_TYPE = 0xb,
	GDIObjType_UNUSED12_TYPE = 0xc,
	GDIObjType_UNUSED13_TYPE = 0xd,
	GDIObjType_ICMCXF_TYPE = 0xe,
	GDIObjType_SPRITE_TYPE = 0xf,
	GDIObjType_BRUSH_TYPE = 0x10,
	GDIObjType_UMPD_TYPE = 0x11,
	GDIObjType_HLSURF_TYPE = 0x12,
	GDIObjType_UNUSED19_TYPE = 0x13,
	GDIObjType_UNUSED20_TYPE = 0x14,
	GDIObjType_META_TYPE = 0x15,
	GDIObjType_UNUSED22_TYPE = 0x16,
	GDIObjType_UNUSED23_TYPE = 0x17,
	GDIObjType_UNUSED24_TYPE = 0x18,
	GDIObjType_UNUSED25_TYPE = 0x19,
	GDIObjType_UNUSED26_TYPE = 0x1a,
	GDIObjType_UNUSED27_TYPE = 0x1b,
	GDIObjType_DRVOBJ_TYPE = 0x1c,
	GDIObjType_UNUSED29_TYPE = 0x1d,
	GDIObjType_UNUSED30_TYPE = 0x1e,
	GDIObjType_MAX_TYPE = 0x1e,
	GDIObjTypeTotal = 0x1f
};

struct HOBJ__ {
	/*0000*/ INT unused;
	/*0004*/
};

struct HSEMAPHORE__ {
	/*0000*/ INT unused;
	/*0004*/
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

enum MONITOR_DPI_TYPE {
	MDT_EFFECTIVE_DPI = 0x0,
	MDT_ANGULAR_DPI = 0x1,
	MDT_RAW_DPI = 0x2,
	MDT_DEFAULT = 0x0
};

enum ORIENTATION_PREFERENCE {
	ORIENTATION_PREFERENCE_NONE = 0x0,
	ORIENTATION_PREFERENCE_LANDSCAPE = 0x1,
	ORIENTATION_PREFERENCE_PORTRAIT = 0x2,
	ORIENTATION_PREFERENCE_LANDSCAPE_FLIPPED = 0x4,
	ORIENTATION_PREFERENCE_PORTRAIT_FLIPPED = 0x8
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

enum PROCESS_UI_FLAGS {
	PROCESS_UIF_NONE = 0x0,
	PROCESS_UIF_AUTHORING_MODE = 0x1,
	PROCESS_UIF_RESTRICTIONS_DISABLED = 0x2
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

enum WINDOWCOMPOSITIONATTRIB {
	WCA_UNDEFINED = 0x0,
	WCA_NCRENDERING_ENABLED = 0x1,
	WCA_NCRENDERING_POLICY = 0x2,
	WCA_TRANSITIONS_FORCEDISABLED = 0x3,
	WCA_ALLOW_NCPAINT = 0x4,
	WCA_CAPTION_BUTTON_BOUNDS = 0x5,
	WCA_NONCLIENT_RTL_LAYOUT = 0x6,
	WCA_FORCE_ICONIC_REPRESENTATION = 0x7,
	WCA_EXTENDED_FRAME_BOUNDS = 0x8,
	WCA_HAS_ICONIC_BITMAP = 0x9,
	WCA_THEME_ATTRIBUTES = 0xa,
	WCA_NCRENDERING_EXILED = 0xb,
	WCA_NCADORNMENTINFO = 0xc,
	WCA_EXCLUDED_FROM_LIVEPREVIEW = 0xd,
	WCA_VIDEO_OVERLAY_ACTIVE = 0xe,
	WCA_FORCE_ACTIVEWINDOW_APPEARANCE = 0xf,
	WCA_DISALLOW_PEEK = 0x10,
	WCA_CLOAK = 0x11,
	WCA_CLOAKED = 0x12,
	WCA_ACCENT_POLICY = 0x13,
	WCA_FREEZE_REPRESENTATION = 0x14,
	WCA_EVER_UNCLOAKED = 0x15,
	WCA_VISUAL_OWNER = 0x16,
	WCA_LAST = 0x17
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

enum _ALTERNATIVE_ARCHITECTURE_TYPE {
	StandardDesign = 0x0,
	NEC98x86 = 0x1,
	EndAlternatives = 0x2
};

struct _ASSEMBLY_STORAGE_MAP;

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

struct _CLIENT_ID {
	/*0000*/ void * UniqueProcess;
	/*0008*/ void * UniqueThread;
	/*0010*/
};

struct _CM_FULL_RESOURCE_DESCRIPTOR {
	/*0000*/ _INTERFACE_TYPE InterfaceType;
	/*0004*/ ULONG BusNumber;
	/*0008*/ _CM_PARTIAL_RESOURCE_LIST PartialResourceList;
	/*0024*/
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

struct _CM_RESOURCE_LIST {
	/*0000*/ ULONG Count;
	/*0004*/ _CM_FULL_RESOURCE_DESCRIPTOR List[0x1];
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

struct _CURDIR {
	/*0000*/ _UNICODE_STRING DosPath;
	/*0010*/ void * Handle;
	/*0018*/
};

enum _D3DDDIFORMAT {
	D3DDDIFMT_UNKNOWN = 0x0,
	D3DDDIFMT_R8G8B8 = 0x14,
	D3DDDIFMT_A8R8G8B8 = 0x15,
	D3DDDIFMT_X8R8G8B8 = 0x16,
	D3DDDIFMT_R5G6B5 = 0x17,
	D3DDDIFMT_X1R5G5B5 = 0x18,
	D3DDDIFMT_A1R5G5B5 = 0x19,
	D3DDDIFMT_A4R4G4B4 = 0x1a,
	D3DDDIFMT_R3G3B2 = 0x1b,
	D3DDDIFMT_A8 = 0x1c,
	D3DDDIFMT_A8R3G3B2 = 0x1d,
	D3DDDIFMT_X4R4G4B4 = 0x1e,
	D3DDDIFMT_A2B10G10R10 = 0x1f,
	D3DDDIFMT_A8B8G8R8 = 0x20,
	D3DDDIFMT_X8B8G8R8 = 0x21,
	D3DDDIFMT_G16R16 = 0x22,
	D3DDDIFMT_A2R10G10B10 = 0x23,
	D3DDDIFMT_A16B16G16R16 = 0x24,
	D3DDDIFMT_A8P8 = 0x28,
	D3DDDIFMT_P8 = 0x29,
	D3DDDIFMT_L8 = 0x32,
	D3DDDIFMT_A8L8 = 0x33,
	D3DDDIFMT_A4L4 = 0x34,
	D3DDDIFMT_V8U8 = 0x3c,
	D3DDDIFMT_L6V5U5 = 0x3d,
	D3DDDIFMT_X8L8V8U8 = 0x3e,
	D3DDDIFMT_Q8W8V8U8 = 0x3f,
	D3DDDIFMT_V16U16 = 0x40,
	D3DDDIFMT_W11V11U10 = 0x41,
	D3DDDIFMT_A2W10V10U10 = 0x43,
	D3DDDIFMT_UYVY = 0x59565955,
	D3DDDIFMT_R8G8_B8G8 = 0x47424752,
	D3DDDIFMT_YUY2 = 0x32595559,
	D3DDDIFMT_G8R8_G8B8 = 0x42475247,
	D3DDDIFMT_DXT1 = 0x31545844,
	D3DDDIFMT_DXT2 = 0x32545844,
	D3DDDIFMT_DXT3 = 0x33545844,
	D3DDDIFMT_DXT4 = 0x34545844,
	D3DDDIFMT_DXT5 = 0x35545844,
	D3DDDIFMT_D16_LOCKABLE = 0x46,
	D3DDDIFMT_D32 = 0x47,
	D3DDDIFMT_D15S1 = 0x49,
	D3DDDIFMT_D24S8 = 0x4b,
	D3DDDIFMT_D24X8 = 0x4d,
	D3DDDIFMT_D24X4S4 = 0x4f,
	D3DDDIFMT_D16 = 0x50,
	D3DDDIFMT_D32F_LOCKABLE = 0x52,
	D3DDDIFMT_D24FS8 = 0x53,
	D3DDDIFMT_D32_LOCKABLE = 0x54,
	D3DDDIFMT_S8_LOCKABLE = 0x55,
	D3DDDIFMT_S1D15 = 0x48,
	D3DDDIFMT_S8D24 = 0x4a,
	D3DDDIFMT_X8D24 = 0x4c,
	D3DDDIFMT_X4S4D24 = 0x4e,
	D3DDDIFMT_L16 = 0x51,
	D3DDDIFMT_G8R8 = 0x5b,
	D3DDDIFMT_R8 = 0x5c,
	D3DDDIFMT_VERTEXDATA = 0x64,
	D3DDDIFMT_INDEX16 = 0x65,
	D3DDDIFMT_INDEX32 = 0x66,
	D3DDDIFMT_Q16W16V16U16 = 0x6e,
	D3DDDIFMT_MULTI2_ARGB8 = 0x3154454d,
	D3DDDIFMT_R16F = 0x6f,
	D3DDDIFMT_G16R16F = 0x70,
	D3DDDIFMT_A16B16G16R16F = 0x71,
	D3DDDIFMT_R32F = 0x72,
	D3DDDIFMT_G32R32F = 0x73,
	D3DDDIFMT_A32B32G32R32F = 0x74,
	D3DDDIFMT_CxV8U8 = 0x75,
	D3DDDIFMT_A1 = 0x76,
	D3DDDIFMT_A2B10G10R10_XR_BIAS = 0x77,
	D3DDDIFMT_DXVACOMPBUFFER_BASE = 0x96,
	D3DDDIFMT_PICTUREPARAMSDATA = 0x96,
	D3DDDIFMT_MACROBLOCKDATA = 0x97,
	D3DDDIFMT_RESIDUALDIFFERENCEDATA = 0x98,
	D3DDDIFMT_DEBLOCKINGDATA = 0x99,
	D3DDDIFMT_INVERSEQUANTIZATIONDATA = 0x9a,
	D3DDDIFMT_SLICECONTROLDATA = 0x9b,
	D3DDDIFMT_BITSTREAMDATA = 0x9c,
	D3DDDIFMT_MOTIONVECTORBUFFER = 0x9d,
	D3DDDIFMT_FILMGRAINBUFFER = 0x9e,
	D3DDDIFMT_DXVA_RESERVED9 = 0x9f,
	D3DDDIFMT_DXVA_RESERVED10 = 0xa0,
	D3DDDIFMT_DXVA_RESERVED11 = 0xa1,
	D3DDDIFMT_DXVA_RESERVED12 = 0xa2,
	D3DDDIFMT_DXVA_RESERVED13 = 0xa3,
	D3DDDIFMT_DXVA_RESERVED14 = 0xa4,
	D3DDDIFMT_DXVA_RESERVED15 = 0xa5,
	D3DDDIFMT_DXVA_RESERVED16 = 0xa6,
	D3DDDIFMT_DXVA_RESERVED17 = 0xa7,
	D3DDDIFMT_DXVA_RESERVED18 = 0xa8,
	D3DDDIFMT_DXVA_RESERVED19 = 0xa9,
	D3DDDIFMT_DXVA_RESERVED20 = 0xaa,
	D3DDDIFMT_DXVA_RESERVED21 = 0xab,
	D3DDDIFMT_DXVA_RESERVED22 = 0xac,
	D3DDDIFMT_DXVA_RESERVED23 = 0xad,
	D3DDDIFMT_DXVA_RESERVED24 = 0xae,
	D3DDDIFMT_DXVA_RESERVED25 = 0xaf,
	D3DDDIFMT_DXVA_RESERVED26 = 0xb0,
	D3DDDIFMT_DXVA_RESERVED27 = 0xb1,
	D3DDDIFMT_DXVA_RESERVED28 = 0xb2,
	D3DDDIFMT_DXVA_RESERVED29 = 0xb3,
	D3DDDIFMT_DXVA_RESERVED30 = 0xb4,
	D3DDDIFMT_DXVA_RESERVED31 = 0xb5,
	D3DDDIFMT_DXVACOMPBUFFER_MAX = 0xb5,
	D3DDDIFMT_BINARYBUFFER = 0xc7,
	D3DDDIFMT_FORCE_UINT = 0x7fffffff
};

enum _D3DDDI_GAMMARAMP_TYPE {
	D3DDDI_GAMMARAMP_UNINITIALIZED = 0x0,
	D3DDDI_GAMMARAMP_DEFAULT = 0x1,
	D3DDDI_GAMMARAMP_RGB256x3x16 = 0x2,
	D3DDDI_GAMMARAMP_DXGI_1 = 0x3
};

struct _D3DDDI_GAMMA_RAMP_DXGI_1 {
	/*0000*/ D3DDDI_DXGI_RGB Scale;
	/*000c*/ D3DDDI_DXGI_RGB Offset;
	/*0018*/ D3DDDI_DXGI_RGB GammaCurve[0x401];
	/*3024*/
};

struct _D3DDDI_GAMMA_RAMP_RGB256x3x16 {
	/*0000*/ USHORT Red[0x100];
	/*0200*/ USHORT Green[0x100];
	/*0400*/ USHORT Blue[0x100];
	/*0600*/
};

struct _D3DDDI_RATIONAL {
	/*0000*/ UINT Numerator;
	/*0004*/ UINT Denominator;
	/*0008*/
};

enum _D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING {
	D3DDDI_VSSLO_UNINITIALIZED = 0x0,
	D3DDDI_VSSLO_PROGRESSIVE = 0x1,
	D3DDDI_VSSLO_INTERLACED_UPPERFIELDFIRST = 0x2,
	D3DDDI_VSSLO_INTERLACED_LOWERFIELDFIRST = 0x3,
	D3DDDI_VSSLO_OTHER = 0xff
};

struct _D3DKMDT_2DREGION {
	/*0000*/ UINT cx;
	/*0004*/ UINT cy;
	/*0008*/
};

enum _D3DKMDT_COLOR_BASIS {
	D3DKMDT_CB_UNINITIALIZED = 0x0,
	D3DKMDT_CB_INTENSITY = 0x1,
	D3DKMDT_CB_SRGB = 0x2,
	D3DKMDT_CB_SCRGB = 0x3,
	D3DKMDT_CB_YCBCR = 0x4,
	D3DKMDT_CB_YPBPR = 0x5
};

struct _D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES {
	/*0000*/ UINT FirstChannel;
	/*0004*/ UINT SecondChannel;
	/*0008*/ UINT ThirdChannel;
	/*000c*/ UINT FourthChannel;
	/*0010*/
};

struct _D3DKMDT_FREQUENCY_RANGE {
	/*0000*/ _D3DDDI_RATIONAL MinVSyncFreq;
	/*0008*/ _D3DDDI_RATIONAL MaxVSyncFreq;
	/*0010*/ _D3DDDI_RATIONAL MinHSyncFreq;
	/*0018*/ _D3DDDI_RATIONAL MaxHSyncFreq;
	/*0020*/
};

struct _D3DKMDT_GAMMA_RAMP {
	
	/*0000*/ _D3DDDI_GAMMARAMP_TYPE Type;
	/*0008*/ ULONGLONG DataSize;
	union {
		/*0010*/ _D3DDDI_GAMMA_RAMP_RGB256x3x16 * pRgb256x3x16;
		/*0010*/ _D3DDDI_GAMMA_RAMP_DXGI_1 * pDxgi1;
		/*0010*/ void * pRaw;
		/*0018*/
	} Data;
	/*0018*/
};

struct _D3DKMDT_GRAPHICS_RENDERING_FORMAT {
	/*0000*/ _D3DKMDT_2DREGION PrimSurfSize;
	/*0008*/ _D3DKMDT_2DREGION VisibleRegionSize;
	/*0010*/ ULONG Stride;
	/*0014*/ _D3DDDIFORMAT PixelFormat;
	/*0018*/ _D3DKMDT_COLOR_BASIS ColorBasis;
	/*001c*/ _D3DKMDT_PIXEL_VALUE_ACCESS_MODE PixelValueAccessMode;
	/*0020*/
};

enum _D3DKMDT_MODE_PREFERENCE {
	D3DKMDT_MP_UNINITIALIZED = 0x0,
	D3DKMDT_MP_PREFERRED = 0x1,
	D3DKMDT_MP_NOTPREFERRED = 0x2
};

enum _D3DKMDT_MONITOR_CAPABILITIES_ORIGIN {
	D3DKMDT_MCO_UNINITIALIZED = 0x0,
	D3DKMDT_MCO_DEFAULTMONITORPROFILE = 0x1,
	D3DKMDT_MCO_MONITORDESCRIPTOR = 0x2,
	D3DKMDT_MCO_MONITORDESCRIPTOR_REGISTRYOVERRIDE = 0x3,
	D3DKMDT_MCO_SPECIFICCAP_REGISTRYOVERRIDE = 0x4,
	D3DKMDT_MCO_DRIVER = 0x5
};

enum _D3DKMDT_MONITOR_DESCRIPTOR_TYPE {
	D3DKMDT_MDT_UNINITIALIZED = 0x0,
	D3DKMDT_MDT_VESA_EDID_V1_BASEBLOCK = 0x1,
	D3DKMDT_MDT_VESA_EDID_V1_BLOCKMAP = 0x2,
	D3DKMDT_MDT_OTHER = 0xff
};

struct _D3DKMDT_MONITOR_FREQUENCY_RANGE {
	
	/*0000*/ _D3DKMDT_MONITOR_CAPABILITIES_ORIGIN Origin;
	/*0004*/ _D3DKMDT_FREQUENCY_RANGE RangeLimits;
	/*0024*/ _D3DKMDT_MONITOR_FREQUENCY_RANGE_CONSTRAINT ConstraintType;
	union {
		/*0028*/ _D3DKMDT_2DREGION ActiveSize;
		/*0028*/ ULONGLONG MaxPixelRate;
		/*0030*/
	} Constraint;
	/*0030*/
};

enum _D3DKMDT_MONITOR_FREQUENCY_RANGE_CONSTRAINT {
	D3DKMDT_MFRC_UNINITIALIZED = 0x0,
	D3DKMDT_MFRC_ACTIVESIZE = 0x1,
	D3DKMDT_MFRC_MAXPIXELRATE = 0x2
};

enum _D3DKMDT_MONITOR_ORIENTATION {
	D3DKMDT_MO_UNINITIALIZED = 0x0,
	D3DKMDT_MO_0DEG = 0x1,
	D3DKMDT_MO_90DEG = 0x2,
	D3DKMDT_MO_180DEG = 0x3,
	D3DKMDT_MO_270DEG = 0x4
};

struct _D3DKMDT_MONITOR_SOURCE_MODE {
	/*0000*/ UINT Id;
	/*0008*/ _D3DKMDT_VIDEO_SIGNAL_INFO VideoSignalInfo;
	/*0040*/ _D3DKMDT_COLOR_BASIS ColorBasis;
	/*0044*/ _D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES ColorCoeffDynamicRanges;
	/*0054*/ _D3DKMDT_MONITOR_CAPABILITIES_ORIGIN Origin;
	/*0058*/ _D3DKMDT_MODE_PREFERENCE Preference;
	/*0060*/
};

enum _D3DKMDT_MONITOR_TIMING_TYPE {
	D3DKMDT_MTT_UNINITIALIZED = 0x0,
	D3DKMDT_MTT_ESTABLISHED = 0x1,
	D3DKMDT_MTT_STANDARD = 0x2,
	D3DKMDT_MTT_EXTRASTANDARD = 0x3,
	D3DKMDT_MTT_DETAILED = 0x4,
	D3DKMDT_MTT_DEFAULTMONITORPROFILE = 0x5,
	D3DKMDT_MTT_DRIVER = 0x6
};

enum _D3DKMDT_PIXEL_VALUE_ACCESS_MODE {
	D3DKMDT_PVAM_UNINITIALIZED = 0x0,
	D3DKMDT_PVAM_DIRECT = 0x1,
	D3DKMDT_PVAM_PRESETPALETTE = 0x2,
	D3DKMDT_PVAM_SETTABLEPALETTE = 0x3
};

enum _D3DKMDT_TEXT_RENDERING_FORMAT {
	D3DKMDT_TRF_UNINITIALIZED = 0x0
};

enum _D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY {
	D3DKMDT_VOT_UNINITIALIZED = 0xfffffffe,
	D3DKMDT_VOT_OTHER = 0xffffffff,
	D3DKMDT_VOT_HD15 = 0x0,
	D3DKMDT_VOT_SVIDEO = 0x1,
	D3DKMDT_VOT_COMPOSITE_VIDEO = 0x2,
	D3DKMDT_VOT_COMPONENT_VIDEO = 0x3,
	D3DKMDT_VOT_DVI = 0x4,
	D3DKMDT_VOT_HDMI = 0x5,
	D3DKMDT_VOT_LVDS = 0x6,
	D3DKMDT_VOT_D_JPN = 0x8,
	D3DKMDT_VOT_SDI = 0x9,
	D3DKMDT_VOT_DISPLAYPORT_EXTERNAL = 0xa,
	D3DKMDT_VOT_DISPLAYPORT_EMBEDDED = 0xb,
	D3DKMDT_VOT_UDI_EXTERNAL = 0xc,
	D3DKMDT_VOT_UDI_EMBEDDED = 0xd,
	D3DKMDT_VOT_SDTVDONGLE = 0xe,
	D3DKMDT_VOT_MIRACAST = 0xf,
	D3DKMDT_VOT_INDIRECT_WIRED = 0x10,
	D3DKMDT_VOT_INTERNAL = 0x80000000,
	D3DKMDT_VOT_SVIDEO_4PIN = 0x1,
	D3DKMDT_VOT_SVIDEO_7PIN = 0x1,
	D3DKMDT_VOT_RF = 0x2,
	D3DKMDT_VOT_RCA_3COMPONENT = 0x3,
	D3DKMDT_VOT_BNC = 0x3
};

struct _D3DKMDT_VIDEO_SIGNAL_INFO {
	
	/*0000*/ _D3DKMDT_VIDEO_SIGNAL_STANDARD VideoStandard;
	/*0004*/ _D3DKMDT_2DREGION TotalSize;
	/*000c*/ _D3DKMDT_2DREGION ActiveSize;
	/*0014*/ _D3DDDI_RATIONAL VSyncFreq;
	/*001c*/ _D3DDDI_RATIONAL HSyncFreq;
	/*0028*/ ULONGLONG PixelRate;
	struct {
		/*0030*/ _D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING ScanLineOrdering : 03; // 0x00000007;
		/*0030*/ UINT VSyncFreqDivider : 06; // 0x000001f8;
		/*0030*/ UINT Reserved : 23; // 0xfffffe00;
		/*0034*/
	} AdditionalSignalInfo;
	/*0030*/ _D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING ScanLineOrdering;
	/*0038*/
};

enum _D3DKMDT_VIDEO_SIGNAL_STANDARD {
	D3DKMDT_VSS_UNINITIALIZED = 0x0,
	D3DKMDT_VSS_VESA_DMT = 0x1,
	D3DKMDT_VSS_VESA_GTF = 0x2,
	D3DKMDT_VSS_VESA_CVT = 0x3,
	D3DKMDT_VSS_IBM = 0x4,
	D3DKMDT_VSS_APPLE = 0x5,
	D3DKMDT_VSS_NTSC_M = 0x6,
	D3DKMDT_VSS_NTSC_J = 0x7,
	D3DKMDT_VSS_NTSC_443 = 0x8,
	D3DKMDT_VSS_PAL_B = 0x9,
	D3DKMDT_VSS_PAL_B1 = 0xa,
	D3DKMDT_VSS_PAL_G = 0xb,
	D3DKMDT_VSS_PAL_H = 0xc,
	D3DKMDT_VSS_PAL_I = 0xd,
	D3DKMDT_VSS_PAL_D = 0xe,
	D3DKMDT_VSS_PAL_N = 0xf,
	D3DKMDT_VSS_PAL_NC = 0x10,
	D3DKMDT_VSS_SECAM_B = 0x11,
	D3DKMDT_VSS_SECAM_D = 0x12,
	D3DKMDT_VSS_SECAM_G = 0x13,
	D3DKMDT_VSS_SECAM_H = 0x14,
	D3DKMDT_VSS_SECAM_K = 0x15,
	D3DKMDT_VSS_SECAM_K1 = 0x16,
	D3DKMDT_VSS_SECAM_L = 0x17,
	D3DKMDT_VSS_SECAM_L1 = 0x18,
	D3DKMDT_VSS_EIA_861 = 0x19,
	D3DKMDT_VSS_EIA_861A = 0x1a,
	D3DKMDT_VSS_EIA_861B = 0x1b,
	D3DKMDT_VSS_PAL_K = 0x1c,
	D3DKMDT_VSS_PAL_K1 = 0x1d,
	D3DKMDT_VSS_PAL_L = 0x1e,
	D3DKMDT_VSS_PAL_M = 0x1f,
	D3DKMDT_VSS_OTHER = 0xff
};

struct _D3DKMDT_VIDPN_PRESENT_PATH {
	/*0000*/ UINT VidPnSourceId;
	/*0004*/ UINT VidPnTargetId;
	/*0008*/ _D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE ImportanceOrdinal;
	/*000c*/ _D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION ContentTransformation;
	/*001c*/ _D3DKMDT_2DREGION VisibleFromActiveTLOffset;
	/*0024*/ _D3DKMDT_2DREGION VisibleFromActiveBROffset;
	/*002c*/ _D3DKMDT_COLOR_BASIS VidPnTargetColorBasis;
	/*0030*/ _D3DKMDT_COLOR_COEFF_DYNAMIC_RANGES VidPnTargetColorCoeffDynamicRanges;
	/*0040*/ _D3DKMDT_VIDPN_PRESENT_PATH_CONTENT Content;
	/*0044*/ _D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION CopyProtection;
	/*0150*/ _D3DKMDT_GAMMA_RAMP GammaRamp;
	/*0168*/
};

enum _D3DKMDT_VIDPN_PRESENT_PATH_CONTENT {
	D3DKMDT_VPPC_UNINITIALIZED = 0x0,
	D3DKMDT_VPPC_GRAPHICS = 0x1,
	D3DKMDT_VPPC_VIDEO = 0x2,
	D3DKMDT_VPPC_NOTSPECIFIED = 0xff
};

struct _D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION {
	/*0000*/ _D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_TYPE CopyProtectionType;
	/*0004*/ UINT APSTriggerBits;
	/*0008*/ UCHAR OEMCopyProtection[0x100];
	/*0108*/ _D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_SUPPORT CopyProtectionSupport;
	/*010c*/
};

struct _D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_SUPPORT {
	/*0000*/ UINT NoProtection : 01; // 0x00000001;
	/*0000*/ UINT MacroVisionApsTrigger : 01; // 0x00000002;
	/*0000*/ UINT MacroVisionFull : 01; // 0x00000004;
	/*0000*/ UINT Reserved : 29; // 0xfffffff8;
	/*0004*/
};

enum _D3DKMDT_VIDPN_PRESENT_PATH_COPYPROTECTION_TYPE {
	D3DKMDT_VPPMT_UNINITIALIZED = 0x0,
	D3DKMDT_VPPMT_NOPROTECTION = 0x1,
	D3DKMDT_VPPMT_MACROVISION_APSTRIGGER = 0x2,
	D3DKMDT_VPPMT_MACROVISION_FULLSUPPORT = 0x3
};

enum _D3DKMDT_VIDPN_PRESENT_PATH_IMPORTANCE {
	D3DKMDT_VPPI_UNINITIALIZED = 0x0,
	D3DKMDT_VPPI_PRIMARY = 0x1,
	D3DKMDT_VPPI_SECONDARY = 0x2,
	D3DKMDT_VPPI_TERTIARY = 0x3,
	D3DKMDT_VPPI_QUATERNARY = 0x4,
	D3DKMDT_VPPI_QUINARY = 0x5,
	D3DKMDT_VPPI_SENARY = 0x6,
	D3DKMDT_VPPI_SEPTENARY = 0x7,
	D3DKMDT_VPPI_OCTONARY = 0x8,
	D3DKMDT_VPPI_NONARY = 0x9,
	D3DKMDT_VPPI_DENARY = 0xa
};

enum _D3DKMDT_VIDPN_PRESENT_PATH_ROTATION {
	D3DKMDT_VPPR_UNINITIALIZED = 0x0,
	D3DKMDT_VPPR_IDENTITY = 0x1,
	D3DKMDT_VPPR_ROTATE90 = 0x2,
	D3DKMDT_VPPR_ROTATE180 = 0x3,
	D3DKMDT_VPPR_ROTATE270 = 0x4,
	D3DKMDT_VPPR_IDENTITY_OFFSET90 = 0x5,
	D3DKMDT_VPPR_ROTATE90_OFFSET90 = 0x6,
	D3DKMDT_VPPR_ROTATE180_OFFSET90 = 0x7,
	D3DKMDT_VPPR_ROTATE270_OFFSET90 = 0x8,
	D3DKMDT_VPPR_IDENTITY_OFFSET180 = 0x9,
	D3DKMDT_VPPR_ROTATE90_OFFSET180 = 0xa,
	D3DKMDT_VPPR_ROTATE180_OFFSET180 = 0xb,
	D3DKMDT_VPPR_ROTATE270_OFFSET180 = 0xc,
	D3DKMDT_VPPR_IDENTITY_OFFSET270 = 0xd,
	D3DKMDT_VPPR_ROTATE90_OFFSET270 = 0xe,
	D3DKMDT_VPPR_ROTATE180_OFFSET270 = 0xf,
	D3DKMDT_VPPR_ROTATE270_OFFSET270 = 0x10,
	D3DKMDT_VPPR_UNPINNED = 0xfe,
	D3DKMDT_VPPR_NOTSPECIFIED = 0xff
};

struct _D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT {
	/*0000*/ UINT Identity : 01; // 0x00000001;
	/*0000*/ UINT Rotate90 : 01; // 0x00000002;
	/*0000*/ UINT Rotate180 : 01; // 0x00000004;
	/*0000*/ UINT Rotate270 : 01; // 0x00000008;
	/*0000*/ UINT Offset0 : 01; // 0x00000010;
	/*0000*/ UINT Offset90 : 01; // 0x00000020;
	/*0000*/ UINT Offset180 : 01; // 0x00000040;
	/*0000*/ UINT Offset270 : 01; // 0x00000080;
	/*0004*/
};

enum _D3DKMDT_VIDPN_PRESENT_PATH_SCALING {
	D3DKMDT_VPPS_UNINITIALIZED = 0x0,
	D3DKMDT_VPPS_IDENTITY = 0x1,
	D3DKMDT_VPPS_CENTERED = 0x2,
	D3DKMDT_VPPS_STRETCHED = 0x3,
	D3DKMDT_VPPS_ASPECTRATIOCENTEREDMAX = 0x4,
	D3DKMDT_VPPS_CUSTOM = 0x5,
	D3DKMDT_VPPS_RESERVED1 = 0xfd,
	D3DKMDT_VPPS_UNPINNED = 0xfe,
	D3DKMDT_VPPS_NOTSPECIFIED = 0xff
};

struct _D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT {
	/*0000*/ UINT Identity : 01; // 0x00000001;
	/*0000*/ UINT Centered : 01; // 0x00000002;
	/*0000*/ UINT Stretched : 01; // 0x00000004;
	/*0000*/ UINT AspectRatioCenteredMax : 01; // 0x00000008;
	/*0000*/ UINT Custom : 01; // 0x00000010;
	/*0004*/
};

struct _D3DKMDT_VIDPN_PRESENT_PATH_TRANSFORMATION {
	/*0000*/ _D3DKMDT_VIDPN_PRESENT_PATH_SCALING Scaling;
	/*0004*/ _D3DKMDT_VIDPN_PRESENT_PATH_SCALING_SUPPORT ScalingSupport;
	/*0008*/ _D3DKMDT_VIDPN_PRESENT_PATH_ROTATION Rotation;
	/*000c*/ _D3DKMDT_VIDPN_PRESENT_PATH_ROTATION_SUPPORT RotationSupport;
	/*0010*/
};

struct _D3DKMDT_VIDPN_SOURCE_MODE {
	
	/*0000*/ UINT Id;
	/*0004*/ _D3DKMDT_VIDPN_SOURCE_MODE_TYPE Type;
	union {
		/*0008*/ _D3DKMDT_GRAPHICS_RENDERING_FORMAT Graphics;
		/*0008*/ _D3DKMDT_TEXT_RENDERING_FORMAT Text;
		/*0028*/
	} Format;
	/*0028*/
};

enum _D3DKMDT_VIDPN_SOURCE_MODE_TYPE {
	D3DKMDT_RMT_UNINITIALIZED = 0x0,
	D3DKMDT_RMT_GRAPHICS = 0x1,
	D3DKMDT_RMT_TEXT = 0x2,
	D3DKMDT_RMT_GRAPHICS_STEREO = 0x3,
	D3DKMDT_RMT_GRAPHICS_STEREO_ADVANCED_SCAN = 0x4
};

struct _D3DKMDT_VIDPN_TARGET_MODE {
	/*0000*/ UINT Id;
	/*0008*/ _D3DKMDT_VIDEO_SIGNAL_INFO VideoSignalInfo;
	/*0040*/ _D3DKMDT_MODE_PREFERENCE Preference;
	/*0048*/
};

enum _D3DKMT_QUERYRESULT_PREEMPTION_ATTEMPT_RESULT {
	D3DKMT_PreemptionAttempt = 0x0,
	D3DKMT_PreemptionAttemptSuccess = 0x1,
	D3DKMT_PreemptionAttemptMissNoCommand = 0x2,
	D3DKMT_PreemptionAttemptMissNotEnabled = 0x3,
	D3DKMT_PreemptionAttemptMissNextFence = 0x4,
	D3DKMT_PreemptionAttemptMissPagingCommand = 0x5,
	D3DKMT_PreemptionAttemptMissSplittedCommand = 0x6,
	D3DKMT_PreemptionAttemptMissFenceCommand = 0x7,
	D3DKMT_PreemptionAttemptMissRenderPendingFlip = 0x8,
	D3DKMT_PreemptionAttemptMissNotMakingProgress = 0x9,
	D3DKMT_PreemptionAttemptMissLessPriority = 0xa,
	D3DKMT_PreemptionAttemptMissRemainingQuantum = 0xb,
	D3DKMT_PreemptionAttemptMissRemainingPreemptionQuantum = 0xc,
	D3DKMT_PreemptionAttemptMissAlreadyPreempting = 0xd,
	D3DKMT_PreemptionAttemptMissGlobalBlock = 0xe,
	D3DKMT_PreemptionAttemptMissAlreadyRunning = 0xf,
	D3DKMT_PreemptionAttemptStatisticsMax = 0x10
};

enum _D3DKMT_QUERYSTATISTICS_ALLOCATION_PRIORITY_CLASS {
	D3DKMT_AllocationPriorityClassMinimum = 0x0,
	D3DKMT_AllocationPriorityClassLow = 0x1,
	D3DKMT_AllocationPriorityClassNormal = 0x2,
	D3DKMT_AllocationPriorityClassHigh = 0x3,
	D3DKMT_AllocationPriorityClassMaximum = 0x4,
	D3DKMT_MaxAllocationPriorityClass = 0x5
};

enum _D3DKMT_QUERYSTATISTICS_DMA_PACKET_TYPE {
	D3DKMT_ClientRenderBuffer = 0x0,
	D3DKMT_ClientPagingBuffer = 0x1,
	D3DKMT_SystemPagingBuffer = 0x2,
	D3DKMT_SystemPreemptionBuffer = 0x3,
	D3DKMT_DmaPacketTypeMax = 0x4
};

enum _D3DKMT_QUERYSTATISTICS_QUEUE_PACKET_TYPE {
	D3DKMT_RenderCommandBuffer = 0x0,
	D3DKMT_DeferredCommandBuffer = 0x1,
	D3DKMT_SystemCommandBuffer = 0x2,
	D3DKMT_MmIoFlipCommandBuffer = 0x3,
	D3DKMT_WaitCommandBuffer = 0x4,
	D3DKMT_SignalCommandBuffer = 0x5,
	D3DKMT_DeviceCommandBuffer = 0x6,
	D3DKMT_SoftwareCommandBuffer = 0x7,
	D3DKMT_QueuePacketTypeMax = 0x8
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
	/*0004*/ ULONG Reserved : 12; // 0xfff00000;
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
	void _DEVICE_OBJECT( _DEVICE_OBJECT && );
	void _DEVICE_OBJECT( _DEVICE_OBJECT const & );
	_DEVICE_OBJECT & operator=( _DEVICE_OBJECT && );
	_DEVICE_OBJECT & operator=( _DEVICE_OBJECT const & );
	/*0150*/
};

struct _DEVICE_OBJECT_POWER_EXTENSION;

enum _DEVICE_POWER_STATE {
	PowerDeviceUnspecified = 0x0,
	PowerDeviceD0 = 0x1,
	PowerDeviceD1 = 0x2,
	PowerDeviceD2 = 0x3,
	PowerDeviceD3 = 0x4,
	PowerDeviceMaximum = 0x5
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

struct _DEVPROPCOMPKEY {
	/*0000*/ _DEVPROPKEY Key;
	/*0014*/ _DEVPROPSTORE Store;
	/*0018*/ WCHAR const * LocaleName;
	/*0020*/
};

struct _DEVPROPKEY {
	/*0000*/ _GUID fmtid;
	/*0010*/ ULONG pid;
	/*0014*/
};

enum _DEVPROPSTORE {
	DEVPROP_STORE_SYSTEM = 0x0,
	DEVPROP_STORE_USER = 0x1
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
	/*0002*/ UCHAR Timer2Reserved1;
	/*0003*/ UCHAR Timer2Reserved2;
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
	void _DISPATCHER_HEADER( _DISPATCHER_HEADER && );
	void _DISPATCHER_HEADER( _DISPATCHER_HEADER const & );
	_DISPATCHER_HEADER & operator=( _DISPATCHER_HEADER && );
	_DISPATCHER_HEADER & operator=( _DISPATCHER_HEADER const & );
	/*0018*/
};

struct _DMA_ADAPTER {
	/*0000*/ USHORT Version;
	/*0002*/ USHORT Size;
	/*0008*/ _DMA_OPERATIONS * DmaOperations;
	/*0010*/
};

struct _DMA_ADAPTER_INFO {
	/*0000*/ ULONG Version;
	/*0004*/ _DMA_ADAPTER_INFO_V1 V1;
	/*0018*/
};

struct _DMA_ADAPTER_INFO_V1 {
	/*0000*/ ULONG ReadDmaCounterAvailable;
	/*0004*/ ULONG ScatterGatherLimit;
	/*0008*/ ULONG DmaAddressWidth;
	/*000c*/ ULONG Flags;
	/*0010*/ ULONG MinimumTransferUnit;
	/*0014*/
};

struct _DMA_OPERATIONS {
	/*0000*/ ULONG Size;
	/*0008*/ void (* PutDmaAdapter)( _DMA_ADAPTER * );
	/*0010*/ void * (* AllocateCommonBuffer)( _DMA_ADAPTER * , ULONG , _LARGE_INTEGER * , UCHAR );
	/*0018*/ void (* FreeCommonBuffer)( _DMA_ADAPTER * , ULONG , _LARGE_INTEGER , void * , UCHAR );
	/*0020*/ LONG (* AllocateAdapterChannel)( _DMA_ADAPTER * , _DEVICE_OBJECT * , ULONG , _IO_ALLOCATION_ACTION (* )( _DEVICE_OBJECT * , _IRP * , void * , void * ), void * );
	/*0028*/ UCHAR (* FlushAdapterBuffers)( _DMA_ADAPTER * , _MDL * , void * , void * , ULONG , UCHAR );
	/*0030*/ void (* FreeAdapterChannel)( _DMA_ADAPTER * );
	/*0038*/ void (* FreeMapRegisters)( _DMA_ADAPTER * , void * , ULONG );
	/*0040*/ _LARGE_INTEGER (* MapTransfer)( _DMA_ADAPTER * , _MDL * , void * , void * , ULONG * , UCHAR );
	/*0048*/ ULONG (* GetDmaAlignment)( _DMA_ADAPTER * );
	/*0050*/ ULONG (* ReadDmaCounter)( _DMA_ADAPTER * );
	/*0058*/ LONG (* GetScatterGatherList)( _DMA_ADAPTER * , _DEVICE_OBJECT * , _MDL * , void * , ULONG , void (* )( _DEVICE_OBJECT * , _IRP * , _SCATTER_GATHER_LIST * , void * ), void * , UCHAR );
	/*0060*/ void (* PutScatterGatherList)( _DMA_ADAPTER * , _SCATTER_GATHER_LIST * , UCHAR );
	/*0068*/ LONG (* CalculateScatterGatherList)( _DMA_ADAPTER * , _MDL * , void * , ULONG , ULONG * , ULONG * );
	/*0070*/ LONG (* BuildScatterGatherList)( _DMA_ADAPTER * , _DEVICE_OBJECT * , _MDL * , void * , ULONG , void (* )( _DEVICE_OBJECT * , _IRP * , _SCATTER_GATHER_LIST * , void * ), void * , UCHAR , void * , ULONG );
	/*0078*/ LONG (* BuildMdlFromScatterGatherList)( _DMA_ADAPTER * , _SCATTER_GATHER_LIST * , _MDL * , _MDL * * );
	/*0080*/ LONG (* GetDmaAdapterInfo)( _DMA_ADAPTER * , _DMA_ADAPTER_INFO * );
	/*0088*/ LONG (* GetDmaTransferInfo)( _DMA_ADAPTER * , _MDL * , ULONGLONG , ULONG , UCHAR , _DMA_TRANSFER_INFO * );
	/*0090*/ LONG (* InitializeDmaTransferContext)( _DMA_ADAPTER * , void * );
	/*0098*/ void * (* AllocateCommonBufferEx)( _DMA_ADAPTER * , _LARGE_INTEGER * , ULONG , _LARGE_INTEGER * , UCHAR , ULONG );
	/*00a0*/ LONG (* AllocateAdapterChannelEx)( _DMA_ADAPTER * , _DEVICE_OBJECT * , void * , ULONG , ULONG , _IO_ALLOCATION_ACTION (* )( _DEVICE_OBJECT * , _IRP * , void * , void * ), void * , void * * );
	/*00a8*/ LONG (* ConfigureAdapterChannel)( _DMA_ADAPTER * , ULONG , void * );
	/*00b0*/ UCHAR (* CancelAdapterChannel)( _DMA_ADAPTER * , _DEVICE_OBJECT * , void * );
	/*00b8*/ LONG (* MapTransferEx)( _DMA_ADAPTER * , _MDL * , void * , ULONGLONG , ULONG , ULONG * , UCHAR , _SCATTER_GATHER_LIST * , ULONG , void (* )( _DMA_ADAPTER * , _DEVICE_OBJECT * , void * , DMA_COMPLETION_STATUS ), void * );
	/*00c0*/ LONG (* GetScatterGatherListEx)( _DMA_ADAPTER * , _DEVICE_OBJECT * , void * , _MDL * , ULONGLONG , ULONG , ULONG , void (* )( _DEVICE_OBJECT * , _IRP * , _SCATTER_GATHER_LIST * , void * ), void * , UCHAR , void (* )( _DMA_ADAPTER * , _DEVICE_OBJECT * , void * , DMA_COMPLETION_STATUS ), void * , _SCATTER_GATHER_LIST * * );
	/*00c8*/ LONG (* BuildScatterGatherListEx)( _DMA_ADAPTER * , _DEVICE_OBJECT * , void * , _MDL * , ULONGLONG , ULONG , ULONG , void (* )( _DEVICE_OBJECT * , _IRP * , _SCATTER_GATHER_LIST * , void * ), void * , UCHAR , void * , ULONG , void (* )( _DMA_ADAPTER * , _DEVICE_OBJECT * , void * , DMA_COMPLETION_STATUS ), void * , void * );
	/*00d0*/ LONG (* FlushAdapterBuffersEx)( _DMA_ADAPTER * , _MDL * , void * , ULONGLONG , ULONG , UCHAR );
	/*00d8*/ void (* FreeAdapterObject)( _DMA_ADAPTER * , _IO_ALLOCATION_ACTION );
	/*00e0*/ LONG (* CancelMappedTransfer)( _DMA_ADAPTER * , void * );
	/*00e8*/ LONG (* AllocateDomainCommonBuffer)( _DMA_ADAPTER * , void * , _LARGE_INTEGER * , ULONG , ULONG , _MEMORY_CACHING_TYPE * , ULONG , _LARGE_INTEGER * , void * * );
	/*00f0*/ LONG (* FlushDmaBuffer)( _DMA_ADAPTER * , _MDL * , UCHAR );
	/*00f8*/ LONG (* JoinDmaDomain)( _DMA_ADAPTER * , void * );
	/*0100*/ LONG (* LeaveDmaDomain)( _DMA_ADAPTER * );
	/*0108*/ void * (* GetDmaDomain)( _DMA_ADAPTER * );
	/*0110*/
};

struct _DMA_TRANSFER_INFO {
	/*0000*/ ULONG Version;
	/*0004*/ _DMA_TRANSFER_INFO_V1 V1;
	/*0010*/
};

struct _DMA_TRANSFER_INFO_V1 {
	/*0000*/ ULONG MapRegisterCount;
	/*0004*/ ULONG ScatterGatherElementCount;
	/*0008*/ ULONG ScatterGatherListSize;
	/*000c*/
};

enum _DMM_CLIENT_TYPE {
	DMM_CT_UNINITIALIZED = 0x0,
	DMM_CT_CDD_NOPATHDATA = 0x1,
	DMM_CT_USERMODE = 0x2,
	DMM_CT_CDD_PATHDATA = 0x3,
	DMM_CT_DXGPORT = 0x4,
	DMM_CT_DISPLAY_ONOFF = 0x5
};

struct _DMM_COFUNCPATHSMODALITY_SERIALIZATION {
	/*0000*/ UCHAR NumPathsFromSource;
	/*0004*/ ULONG PathAndTargetModeSetOffset[0x1];
	/*0008*/
};

struct _DMM_COMMITVIDPNREQUESTSET_SERIALIZATION {
	/*0000*/ UCHAR NumCommitVidPnRequests;
	/*0004*/ ULONG CommitVidPnRequestOffset[0x1];
	/*0008*/
};

struct _DMM_COMMITVIDPNREQUEST_DIAGINFO {
	/*0000*/ _DMM_CLIENT_TYPE ClientType : 04; // 0x0000000f;
	/*0000*/ _DMM_VIDPNCHANGE_TYPE VidPnChange : 04; // 0x000000f0;
	/*0004*/ UCHAR ReclaimClonedTarget : 01; // 0x01;
	/*0004*/ UCHAR CleanupAfterFailedCommitVidPn : 01; // 0x02;
	/*0004*/ UCHAR ForceAllActiveVidPnModeListInvalidation : 01; // 0x04;
	/*0004*/ UCHAR SkipCommitVidPn : 01; // 0x08;
	/*0008*/ ULONG ModeChangeRequestId;
	/*000c*/
};

struct _DMM_COMMITVIDPNREQUEST_SERIALIZATION {
	/*0000*/ UINT AffectedVidPnSourceId;
	/*0004*/ _DMM_COMMITVIDPNREQUEST_DIAGINFO RequestDiagInfo;
	/*0010*/ _DMM_VIDPN_SERIALIZATION VidPnSerialization;
	/*001c*/
};

enum _DMM_MODE_PRUNING_ALGORITHM {
	DMM_MPA_UNINITIALIZED = 0x0,
	DMM_MPA_GDI = 0x1,
	DMM_MPA_VISTA = 0x2,
	DMM_MPA_GDI_VISTA_UNION = 0x3,
	DMM_MPA_MAXVALID = 0x3
};

struct _DMM_MONITORDESCRIPTORSET_SERIALIZATION {
	/*0000*/ UCHAR NumDescriptors;
	/*0004*/ _DMM_MONITORDESCRIPTOR_SERIALIZATION DescriptorSerialization[0x1];
	/*0090*/
};

struct _DMM_MONITORDESCRIPTOR_SERIALIZATION {
	/*0000*/ UINT Id;
	/*0004*/ _D3DKMDT_MONITOR_DESCRIPTOR_TYPE Type;
	/*0008*/ _D3DKMDT_MONITOR_CAPABILITIES_ORIGIN Origin;
	/*000c*/ UCHAR Data[0x80];
	/*008c*/
};

struct _DMM_MONITORFREQUENCYRANGESET_SERIALIZATION {
	/*0000*/ UCHAR NumFrequencyRanges;
	/*0008*/ _D3DKMDT_MONITOR_FREQUENCY_RANGE FrequencyRangeSerialization[0x1];
	/*0038*/
};

struct _DMM_MONITORSOURCEMODESET_SERIALIZATION {
	/*0000*/ UINT NumModes;
	/*0008*/ _DMM_MONITOR_SOURCE_MODE_SERIALIZATION ModeSerialization[0x1];
	/*0070*/
};

enum _DMM_MONITOR_PRESENCE_EVENT_TYPE {
	DMM_MPET_UNINITIALIZED = 0x0,
	DMM_MPET_ADDMONITOR = 0x1,
	DMM_MPET_REMOVEMONITOR = 0x2,
	DMM_MPET_DRIVERARRIVAL = 0x3,
	DMM_MPET_DRIVERQUERYREMOVE = 0x4,
	DMM_MPET_DRIVERREMOVECANCELLED = 0x5,
	DMM_MPET_DRIVERREMOVECOMPLETE = 0x6,
	DMM_MPET_DEVICENODEREADY = 0x7,
	DMM_MPET_EDIDCHANGE = 0x8,
	DMM_MPET_MONITORDISABLE = 0x9,
	DMM_MPET_MONITORENABLE = 0xa,
	DMM_MPET_ADAPTERADD = 0xb,
	DMM_MPET_ADAPTERREMOVAL = 0xc,
	DMM_MPET_INVALIDATION = 0xd,
	DMM_MPET_MONITORPOWERCTL = 0xe,
	DMM_MPET_ADDSIMULATEDMONITOR = 0x40000001,
	DMM_MPET_REMOVESIMULATEDMONITOR = 0x40000002,
	DMM_MPET_MAXVALID = 0x40000002
};

struct _DMM_MONITOR_SERIALIZATION {
	/*0000*/ ULONG Size;
	/*0004*/ UINT VideoPresentTargetId;
	/*0008*/ _D3DKMDT_MONITOR_ORIENTATION Orientation;
	/*000c*/ UCHAR IsSimulatedMonitor;
	/*000d*/ UCHAR IsUsingDefaultProfile;
	/*0010*/ _DMM_MODE_PRUNING_ALGORITHM ModePruningAlgorithm;
	/*0014*/ _DEVICE_POWER_STATE MonitorPowerState;
	/*0018*/ ULONG SourceModeSetOffset;
	/*001c*/ ULONG FrequencyRangeSetOffset;
	/*0020*/ ULONG DescriptorSetOffset;
	/*0024*/ _DMM_VIDPN_MONITOR_TYPE MonitorType;
	/*0028*/
};

struct _DMM_MONITOR_SOURCE_MODE_SERIALIZATION {
	/*0000*/ _D3DKMDT_MONITOR_SOURCE_MODE Info;
	/*0060*/ _D3DKMDT_MONITOR_TIMING_TYPE TimingType;
	/*0068*/
};

enum _DMM_VIDPNCHANGE_TYPE {
	DMM_CVR_UNINITIALIZED = 0x0,
	DMM_CVR_UPDATEMODALITY = 0x1,
	DMM_CVR_ADDPATH = 0x2,
	DMM_CVR_ADDPATHS = 0x3,
	DMM_CVR_REMOVEPATH = 0x4,
	DMM_CVR_REMOVEALLPATHS = 0x5
};

struct _DMM_VIDPNPATHANDTARGETMODESET_SERIALIZATION {
	/*0000*/ _D3DKMDT_VIDPN_PRESENT_PATH PathInfo;
	/*0168*/ _DMM_VIDPNTARGETMODESET_SERIALIZATION TargetModeSet;
	/*01b8*/
};

struct _DMM_VIDPNPATHANDTARGETMODE_SERIALIZATION {
	/*0000*/ _D3DKMDT_VIDPN_PRESENT_PATH PathInfo;
	/*0168*/ _D3DKMDT_VIDPN_TARGET_MODE TargetMode;
	/*01b0*/
};

struct _DMM_VIDPNPATHSFROMSOURCE_SERIALIZATION {
	/*0000*/ _D3DKMDT_VIDPN_SOURCE_MODE SourceMode;
	/*0028*/ UCHAR NumPathsFromSource;
	/*0030*/ _DMM_VIDPNPATHANDTARGETMODE_SERIALIZATION PathAndTargetModeSerialization[0x1];
	/*01e0*/
};

struct _DMM_VIDPNSET_SERIALIZATION {
	/*0000*/ UCHAR NumVidPns;
	/*0004*/ ULONG VidPnOffset[0x1];
	/*0008*/
};

struct _DMM_VIDPNTARGETMODESET_SERIALIZATION {
	/*0000*/ UCHAR NumModes;
	/*0008*/ _D3DKMDT_VIDPN_TARGET_MODE ModeSerialization[0x1];
	/*0050*/
};

enum _DMM_VIDPN_MONITOR_TYPE {
	DMM_VMT_UNINITIALIZED = 0x0,
	DMM_VMT_PHYSICAL_MONITOR = 0x1,
	DMM_VMT_BOOT_PERSISTENT_MONITOR = 0x2,
	DMM_VMT_PERSISTENT_MONITOR = 0x3,
	DMM_VMT_TEMPORARY_MONITOR = 0x4,
	DMM_VMT_SIMULATED_MONITOR = 0x5
};

struct _DMM_VIDPN_SERIALIZATION {
	/*0000*/ ULONG Size;
	/*0004*/ UCHAR NumActiveSources;
	/*0008*/ ULONG PathsFromSourceSerializationOffsets[0x1];
	/*000c*/
};

struct _DRIVER_EXTENSION {
	/*0000*/ _DRIVER_OBJECT * DriverObject;
	/*0008*/ LONG (* AddDevice)( _DRIVER_OBJECT * , _DEVICE_OBJECT * );
	/*0010*/ ULONG Count;
	/*0018*/ _UNICODE_STRING ServiceKeyName;
	/*0028*/
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

enum _DXGKMDT_OPM_HDCP_PROTECTION_LEVEL {
	DXGKMDT_OPM_HDCP_OFF = 0x0,
	DXGKMDT_OPM_HDCP_ON = 0x1,
	DXGKMDT_OPM_HDCP_FORCE_ULONG = 0x7fffffff
};

struct _DXGK_DIAG_CODE_POINT_PACKET {
	/*0000*/ _DXGK_DIAG_HEADER Header;
	/*0030*/ _DXGK_DIAG_CODE_POINT_TYPE CodePointType;
	/*0034*/ UINT Param1;
	/*0038*/ UINT Param2;
	/*003c*/ UINT Param3;
	/*0040*/
};

enum _DXGK_DIAG_CODE_POINT_TYPE {
	DXGK_DIAG_CODE_POINT_TYPE_NONE = 0x0,
	DXGK_DIAG_CODE_POINT_TYPE_RECOMMEND_FUNC_VIDPN = 0x1,
	DXGK_DIAG_CODE_POINT_TYPE_OS_RECOMMENDED_VIDPN = 0x2,
	DXGK_DIAG_CODE_POINT_TYPE_SDC_LOG_FAILURE = 0x3,
	DXGK_DIAG_CODE_POINT_TYPE_SDC_INVALIDATE_ERROR = 0x4,
	DXGK_DIAG_CODE_POINT_TYPE_CDS_LOG_FAILURE = 0x5,
	DXGK_DIAG_CODE_POINT_TYPE_CDS_FAILURE_DB = 0x7,
	DXGK_DIAG_CODE_POINT_TYPE_RETRIEVE_BTL = 0x8,
	DXGK_DIAG_CODE_POINT_TYPE_RETRIEVE_DB = 0x9,
	DXGK_DIAG_CODE_POINT_TYPE_QDC_LOG_FAILURE = 0xa,
	DXGK_DIAG_CODE_POINT_TYPE_POWER_ON_GDI = 0xb,
	DXGK_DIAG_CODE_POINT_TYPE_POWER_OFF_GDI = 0xc,
	DXGK_DIAG_CODE_POINT_TYPE_POWER_ON_MONITOR = 0xd,
	DXGK_DIAG_CODE_POINT_TYPE_POWER_OFF_MONITOR = 0xe,
	DXGK_DIAG_CODE_POINT_TYPE_POWER_DIM_MONITOR = 0xf,
	DXGK_DIAG_CODE_POINT_TYPE_POWER_UNDIM_MONITOR = 0x10,
	DXGK_DIAG_CODE_POINT_TYPE_BML_BACKTRACK = 0x11,
	DXGK_DIAG_CODE_POINT_TYPE_BML_CLOSEST_TARGET_MODE = 0x12,
	DXGK_DIAG_CODE_POINT_TYPE_BML_NO_EXACT_SOURCE_MODE = 0x13,
	DXGK_DIAG_CODE_POINT_TYPE_BML_NO_EXACT_TARGET_MODE = 0x14,
	DXGK_DIAG_CODE_POINT_TYPE_BML_SOURCE_MODE_NOT_PINNED = 0x15,
	DXGK_DIAG_CODE_POINT_TYPE_BML_TARGET_MODE_NOT_PINNED = 0x16,
	DXGK_DIAG_CODE_POINT_TYPE_BML_RESTARTED = 0x17,
	DXGK_DIAG_CODE_POINT_TYPE_TDR = 0x18,
	DXGK_DIAG_CODE_POINT_TYPE_ACPI_EVENT_NOTIFICATION = 0x19,
	DXGK_DIAG_CODE_POINT_TYPE_CREATEMDEV_USE_DEFAULT_MODE = 0x1a,
	DXGK_DIAG_CODE_POINT_TYPE_CONNECTED_SET_LOG_FAILURE = 0x1b,
	DXGK_DIAG_CODE_POINT_TYPE_INVALIDATE_DXGK_MODE_CACHE = 0x1c,
	DXGK_DIAG_CODE_POINT_TYPE_REBUILD_DXGK_MODE_CACHE = 0x1d,
	DXGK_DIAG_CODE_POINT_TYPE_CREATEFUNVIDPN_RELAX_REFRESH_MATCH = 0x1e,
	DXGK_DIAG_CODE_POINT_TYPE_CREATEFUNVIDPN_CCDBML_FAIL_VISTABML_SUCCESSED = 0x1f,
	DXGK_DIAG_CODE_POINT_TYPE_BML_BEST_SOURCE_MODE = 0x20,
	DXGK_DIAG_CODE_POINT_TYPE_BML_BEST_TARGET_MODE = 0x21,
	DXGK_DIAG_CODE_POINT_TYPE_ADD_DEVICE = 0x22,
	DXGK_DIAG_CODE_POINT_TYPE_START_ADAPTER = 0x23,
	DXGK_DIAG_CODE_POINT_TYPE_STOP_ADAPTER = 0x24,
	DXGK_DIAG_CODE_POINT_TYPE_CHILD_POLLING = 0x25,
	DXGK_DIAG_CODE_POINT_TYPE_CHILD_POLLING_TARGET = 0x26,
	DXGK_DIAG_CODE_POINT_TYPE_INDICATE_CHILD_STATUS = 0x27,
	DXGK_DIAG_CODE_POINT_TYPE_HANDLE_IRP = 0x28,
	DXGK_DIAG_CODE_POINT_TYPE_CHANGE_UNSUPPORTED_MONITOR_MODE_FLAG = 0x29,
	DXGK_DIAG_CODE_POINT_TYPE_ACPI_NOTIFY_CALLBACK = 0x2a,
	DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_EXCLUDE_EVICTALL_DISABLEGDI = 0x2b,
	DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_EXCLUDE_EVICTALL_ENABLEGDI = 0x2c,
	DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_EXCLUDE_MODESWITCH = 0x2d,
	DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_SYNC_MONITOR_EVENT = 0x2e,
	DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_PNP_NOTIFY_GDI = 0x2f,
	DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_PNP_ENABLE_VGA = 0x30,
	DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_TDR_SWITCH_GDI = 0x31,
	DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_CDD_CREATE_DEVICE_FAILED = 0x32,
	DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_CDD_DEVICE_REMOVED = 0x33,
	DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_CDD_DRVASSERTMODE_TRUE_FAILED = 0x34,
	DXGK_DIAG_CODE_POINT_TYPE_VIDEOPORTCALLOUT_CDD_RECREATE_DEVICE_FAILED = 0x35,
	DXGK_DIAG_CODE_POINT_TYPE_CDD_MAPSHADOWBUFFER_FAILED = 0x36,
	DXGK_DIAG_CODE_POINT_TYPE_COMMIT_VIDPN_LOG_FAILURE = 0x37,
	DXGK_DIAG_CODE_POINT_TYPE_DRIVER_RECOMMEND_LOG_FAILURE = 0x38,
	DXGK_DIAG_CODE_POINT_TYPE_SDC_ENFORCED_CLONE_PATH_INVALID_SOURCE_IDX = 0x39,
	DXGK_DIAG_CODE_POINT_TYPE_DRVPROBEANDCAPTURE_FAILED = 0x3a,
	DXGK_DIAG_CODE_POINT_TYPE_DXGKCDDENABLE_OPTIMIZED_MODE_CHANGE = 0x3b,
	DXGK_DIAG_CODE_POINT_TYPE_DXGKSETDISPLAYMODE_OPTIMIZED_MODE_CHANGE = 0x3c,
	DXGK_DIAG_CODE_POINT_TYPE_MON_DEPART_GETRECENTTOP_FAIL = 0x3d,
	DXGK_DIAG_CODE_POINT_TYPE_MON_ARRIVE_INC_ADD_FAIL = 0x3e,
	DXGK_DIAG_CODE_POINT_TYPE_CCD_DATABASE_PERSIST = 0x3f,
	DXGK_DIAG_CODE_POINT_TYPE_CCD_DATABASE_PERSIST_NO_CONNECTIVITY_HASH = 0x40,
	DXGK_DIAG_CODE_POINT_TYPE_CDD_DISABLE_FAILED = 0x41,
	DXGK_DIAG_CODE_POINT_TYPE_SET_BACKLIGHT_OPTIMIZATION = 0x42,
	DXGK_DIAG_CODE_POINT_TYPE_SET_BRIGHTNESS = 0x43,
	DXGK_DIAG_CODE_POINT_TYPE_SET_VIDPN_SOURCE_VISIBILITY = 0x44,
	DXGK_DIAG_CODE_POINT_TYPE_MIRACAST_SYNC_START = 0x45,
	DXGK_DIAG_CODE_POINT_TYPE_MIRACAST_BML_RAW_TARGET_MODE_BACKTRACK = 0x46,
	DXGK_DIAG_CODE_POINT_TYPE_MIRACAST_STOP = 0x47,
	DXGK_DIAG_CODE_POINT_TYPE_MIRACAST_TEARDOWN = 0x48,
	DXGK_DIAG_CODE_POINT_TYPE_MIRACAST_CONNECTED_STANDBY = 0x49,
	DXGK_DIAG_CODE_POINT_TYPE_MIRACAST_UMDF_TIMEOUT = 0x4a,
	DXGK_DIAG_CODE_POINT_TYPE_SDC_RETRY = 0x4b,
	DXGK_DIAG_CODE_POINT_TYPE_BDD_FALLBACK = 0x4c,
	DXGK_DIAG_CODE_POINT_TYPE_QDC_PROCESS_STAT = 0x4d,
	DXGK_DIAG_CODE_POINT_TYPE_DPI_LEGACY_SETTINGS = 0x4e,
	DXGK_DIAG_CODE_POINT_TYPE_DPI_SETTINGS_UPDATE = 0x4f,
	DXGK_DIAG_CODE_POINT_TYPE_DDICOMMITVIDPN = 0x50,
	DXGK_DIAG_CODE_POINT_TYPE_CCD_DATABASE_LOAD = 0x51,
	DXGK_DIAG_CODE_POINT_TYPE_MON_MULTIPLE_PENDING_HPDS = 0x52,
	DXGK_DIAG_CODE_POINT_TYPE_ENABLE_HIGH_PRECISION_BRIGHTNESS = 0x53,
	DXGK_DIAG_CODE_POINT_TYPE_SETGAMMARAMP_FAILED = 0x54,
	DXGK_DIAG_CODE_POINT_TYPE_ID_BUGCHECK = 0x55,
	DXGK_DIAG_CODE_POINT_TYPE_MAX = 0x55,
	DXGK_DIAG_CODE_POINT_TYPE_FORCE_UINT32 = 0xffffffff
};

struct _DXGK_DIAG_HEADER {
	/*0000*/ _DXGK_DIAG_TYPE Type;
	/*0004*/ UINT Size;
	/*0008*/ ULONGLONG LogTimestamp;
	/*0010*/ UCHAR ProcessName[0x10];
	/*0020*/ ULONGLONG ThreadId;
	/*0028*/ UINT Index;
	/*002c*/ UINT WdLogIdx;
	/*0030*/
};

enum _DXGK_DIAG_MIRACAST_START_STAGE {
	DXGK_DIAG_MIRACAST_START_KM_SYNC_SUCCESS = 0x0,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_EVENT_HANDLE_INVALID = 0x1,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_MIRACAST_DEVICE_NOT_FOUND = 0x2,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_ADAPTER_NOT_STARTED = 0x3,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_ADAPTER_STOPPED_OR_POWERED_DOWN = 0x4,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_ADAPTER_NO_MIRACAST_SUPPORT = 0x5,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_SESSION_IN_PROGRESS = 0x6,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_CREATECONTEXT_DDI_GPU_RESOURCE_IN_USE = 0x7,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_CREATECONTEXT_DDI_CALL = 0x8,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_CREATECONTEXT_DDI_INVALID_TARGET_ID = 0x9,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_ALLOCATE_CHUNK_LIST = 0xa,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_ALLOCATE_CHUNKS = 0xb,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_ALLOCATE_START_SESSION_CONTEXT = 0xc,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_START_IOCTL = 0xd,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_CREATE_GUID = 0xe,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_LAUNCH_START_ADAPTER_THREAD = 0xf,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_START_ADAPTER_THREAD_TIMEOUT = 0x10,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_FAIL_WAIT_START_ADAPTER_THREAD = 0x11,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_SUCCESS = 0x100,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_INVALID_UMD_DLL_NAME = 0x101,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_SESSION_IN_PROGRESS = 0x102,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_CREATE_RTSP_EVENT = 0x103,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_LOAD_UMD = 0x104,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_FIND_UMD_ENTRY_POINT = 0x105,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_QUERYINTERFACE_DDI_CALL = 0x106,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_QUERYINTERFACE_DDI_INVALID_INTERFACE = 0x107,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_CREATECONTEXT_DDI_CALL = 0x108,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_FIND_SYSTEM_IP_ADDRESS = 0x109,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_FIND_AF_INET_SYSTEM_IP_ADDRESS = 0x10a,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_OPEN_MIRACAST_SESSION_CALL = 0x10b,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_CREATE_RTSP_LISTEN_SOCKET = 0x10c,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_CREATE_RTSP_SOCKET = 0x10d,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_BIND_RTSP_SOCKET = 0x10e,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_LISTEN_ON_RTSP_SOCKET = 0x10f,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_ACCEPT_RTSP_SOCKET = 0x110,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_RECEIVE_RTSP_CONNECTION_FROM_SINK = 0x111,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_SET_SOCKET_OPTIONS = 0x112,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_STARTSESSION_DDI_CALL = 0x113,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_STARTSESSION_DDI_INSUFFICIENT_BANDWIDTH = 0x114,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_START_WATCHDOG = 0x115,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_OPEN_DXGK_ADAPTER = 0x116,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_CREATE_DXGK_DEVICE = 0x117,
	DXGK_DIAG_MIRACAST_START_UM_ASYNC_FAIL_CANCELLED = 0x118,
	DXGK_DIAG_MIRACAST_START_KM_SYNC_UNINITALIZED = 0xffffffff
};

enum _DXGK_DIAG_MIRACAST_STOP_SESSION_REASON {
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_UNKNOWN = 0x0,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_UMD_CRITICAL_ERROR = 0x1,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_UMD_MISSING_PACKAGE = 0x2,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_UMD_SINK_DISCONNECT_REQUEST = 0x3,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_UMD_INSUFFICIENT_BANDWIDTH = 0x4,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_UMD_SINK_FAILED_STANDARD_MODE_CHANGE = 0x5,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_UMD_NETWORK_L2_DISCONNECTED = 0x6,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_UMD_POWER_DWON_MIRACAST_DEVICE = 0x7,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_UMD_WATCHDOG_TIMEOUT = 0x8,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_UMD_COMPANION_DRIVER_REQUEST = 0x9,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_KMD_USER_REQUEST = 0x80,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_KMD_USER_SESSION_SWITCH = 0x81,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_KMD_STOP_GRAPHICS_DEVICE = 0x82,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_KMD_POWER_DOWN_GRAPHICS_DEVICE = 0x83,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_KMD_STOP_MIRACAST_DEVICE = 0x84,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_KMD_ISR_INVALID_DATA = 0x85,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_KMD_NO_ACTIVE_PATHS = 0x86,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_KMD_REMOVE_MIRACAST_DEVICE = 0x87,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_KMD_ENTERING_CONNECTED_STANDBY = 0x88,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_KMD_CONNECTED_STANDBY_BACKUP = 0x89,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_KMD_INDIRECT_SWAPCHAIN_TIMEOUT = 0x90,
	DXGK_DIAG_MIRACAST_STOP_SESSION_REASON_FORCE_UINT32 = 0xffffffff
};

enum _DXGK_DIAG_TYPE {
	DXGK_DIAG_TYPE_NONE = 0x0,
	DXGK_DIAG_TYPE_SDC = 0x1,
	DXGK_DIAG_TYPE_HPD = 0x2,
	DXGK_DIAG_TYPE_DC_ORIGIN = 0x3,
	DXGK_DIAG_TYPE_USER_CDS = 0x4,
	DXGK_DIAG_TYPE_DRV_CDS = 0x5,
	DXGK_DIAG_TYPE_CODE_POINT = 0x6,
	DXGK_DIAG_TYPE_QDC = 0x7,
	DXGK_DIAG_TYPE_MONITOR_MGR = 0x8,
	DXGK_DIAG_TYPE_CONNECTEDSET_NOT_FOUND = 0x9,
	DXGK_DIAG_TYPE_DISPDIAG_COLLECTED = 0xa,
	DXGK_DIAG_TYPE_BML_PACKET = 0xb,
	DXGK_DIAG_TYPE_BML_PACKET_EX = 0xc,
	DXGK_DIAG_TYPE_COMMIT_VIDPN_FAILED = 0xd,
	DXGK_DIAG_TYPE_DRIVER_RECOMMEND_VIDPN = 0xe,
	DXGK_DIAG_TYPE_OUTPUTDUPL = 0xf,
	DXGK_DIAG_TYPE_MONITOR_BRIGHTNESS = 0x10,
	DXGK_DIAG_TYPE_CCD_DATABASE_ACCESS = 0x11,
	DXGK_DIAG_TYPE_MIRACAST_SESSION_START_DONE = 0x12,
	DXGK_DIAG_TYPE_MIRACAST_SESSION_START = 0x13,
	DXGK_DIAG_TYPE_MIRACAST_SESSION_START_DONE_EX = 0x14,
	DXGK_DIAG_TYPE_SDC2 = 0x15,
	DXGK_DIAG_TYPE_QDC2 = 0x16,
	DXGK_DIAG_TYPE_FUNCTIONALIZE_PACKET = 0x17,
	DXGK_DIAG_TYPE_MIRACAST_SESSION_START_DONE_EX2 = 0x18,
	DXGK_DIAG_TYPE_MONITOR_BRIGHTNESS_EX = 0x19,
	DXGK_DIAG_TYPE_ADAPTER_START = 0x1a,
	DXGK_DIAG_TYPE_PADDING = 0x1b,
	DXGK_DIAG_TYPE_PERSISTENT_DUP = 0x1c,
	DXGK_DIAG_TYPE_MAX = 0x1c,
	DXGK_DIAG_TYPE_FORCE_UINT32 = 0xffffffff
};

enum _DXGK_RECOMMENDFUNCTIONALVIDPN_REASON {
	DXGK_RFVR_UNINITIALIZED = 0x0,
	DXGK_RFVR_HOTKEY = 0x1,
	DXGK_RFVR_USERMODE = 0x2
};

struct _ECP_LIST;

union _EINFO {
	
	struct {
		/*0000*/ ULONGLONG entryIndex : 24; // 0x0000000000ffffff;
		/*0000*/ ULONGLONG compatibilityBits : 40; // 0xffffffffff000000;
		/*0008*/
	} s;
	/*0000*/ HOBJ__ * hFree;
	/*0008*/
};

struct _EJOB;

struct _ENTRY {
	/*0000*/ _EINFO einfo;
	/*0008*/ _OBJECTOWNER ObjectOwner;
	/*000c*/ _UPPER_HANDLE_BITS UpperHandleBits;
	/*000e*/ UCHAR Objt;
	/*000f*/ UCHAR Flags;
	/*0010*/ void * pUser;
	/*0018*/
};

struct _EPROCESS;

struct _ERESOURCE {
	
	/*0000*/ _LIST_ENTRY SystemResourcesList;
	/*0010*/ _OWNER_ENTRY * OwnerTable;
	/*0018*/ SHORT ActiveCount;
	/*001a*/ USHORT Flag;
	/*001a*/ UCHAR ReservedLowFlags;
	/*001b*/ UCHAR WaiterPriority;
	/*0020*/ _KWAIT_CHAIN SharedWaiters;
	/*0028*/ _KEVENT * ExclusiveWaiters;
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

struct _ETHREAD;

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

enum _EVENT_TYPE {
	NotificationEvent = 0x0,
	SynchronizationEvent = 0x1
};

enum _EXCEPTION_DISPOSITION {
	ExceptionContinueExecution = 0x0,
	ExceptionContinueSearch = 0x1,
	ExceptionNestedException = 0x2,
	ExceptionCollidedUnwind = 0x3
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

struct _EXCEPTION_REGISTRATION_RECORD {
	/*0000*/ _EXCEPTION_REGISTRATION_RECORD * Next;
	/*0008*/ _EXCEPTION_DISPOSITION (* Handler)( _EXCEPTION_RECORD * , void * , _CONTEXT * , void * );
	/*0010*/
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
	void _FAST_MUTEX( _FAST_MUTEX && );
	void _FAST_MUTEX( _FAST_MUTEX const & );
	_FAST_MUTEX & operator=( _FAST_MUTEX && );
	_FAST_MUTEX & operator=( _FAST_MUTEX const & );
	/*0038*/
};

struct _FILE_BASIC_INFORMATION {
	/*0000*/ _LARGE_INTEGER CreationTime;
	/*0008*/ _LARGE_INTEGER LastAccessTime;
	/*0010*/ _LARGE_INTEGER LastWriteTime;
	/*0018*/ _LARGE_INTEGER ChangeTime;
	/*0020*/ ULONG FileAttributes;
	/*0028*/
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
	FileMaximumInformation = 0x43
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
	void _FILE_OBJECT( _FILE_OBJECT && );
	void _FILE_OBJECT( _FILE_OBJECT const & );
	_FILE_OBJECT & operator=( _FILE_OBJECT && );
	_FILE_OBJECT & operator=( _FILE_OBJECT const & );
	/*00d8*/
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

struct _GDI_TEB_BATCH {
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

struct _GUID {
	/*0000*/ ULONG Data1;
	/*0004*/ USHORT Data2;
	/*0006*/ USHORT Data3;
	/*0008*/ UCHAR Data4[0x8];
	/*0010*/
};

struct _IMAGE_DATA_DIRECTORY {
	/*0000*/ ULONG VirtualAddress;
	/*0004*/ ULONG Size;
	/*0008*/
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

enum _IO_ALLOCATION_ACTION {
	KeepObject = 0x1,
	DeallocateObject = 0x2,
	DeallocateObjectKeepRegisters = 0x3
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
			/*0010*/ _FSINFOCLASS FsInformationClass;
			/*0018*/
		} QueryVolume;
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

struct _IO_TIMER;

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
	MaxJobObjectInfoClass = 0x2b
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
	void _KDPC( _KDPC && );
	void _KDPC( _KDPC const & );
	_KDPC & operator=( _KDPC && );
	_KDPC & operator=( _KDPC const & );
	/*0040*/
};

struct _KEVENT {
	/*0000*/ _DISPATCHER_HEADER Header;
	void _KEVENT( _KEVENT && );
	void _KEVENT( _KEVENT const & );
	_KEVENT & operator=( _KEVENT && );
	_KEVENT & operator=( _KEVENT const & );
	/*0018*/
};

struct _KFLOATING_SAVE {
	/*0000*/ ULONG Dummy;
	/*0004*/
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

struct _KNODE;

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
	/*07f0*/
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
	/*0040*/ _KPROCESSOR_STATE ProcessorState;
	/*05f0*/ CHAR CpuType;
	/*05f1*/ CHAR CpuID;
	/*05f2*/ USHORT CpuStep;
	/*05f2*/ UCHAR CpuStepping;
	/*05f3*/ UCHAR CpuModel;
	/*05f4*/ ULONG MHz;
	/*05f8*/ ULONGLONG HalReserved[0x8];
	/*0638*/ USHORT MinorVersion;
	/*063a*/ USHORT MajorVersion;
	/*063c*/ UCHAR BuildType;
	/*063d*/ UCHAR CpuVendor;
	/*063e*/ UCHAR CoresPerPhysicalProcessor;
	/*063f*/ UCHAR LogicalProcessorsPerCore;
	/*0640*/ _KNODE * ParentNode;
	/*0648*/ ULONGLONG GroupSetMember;
	/*0650*/ UCHAR Group;
	/*0651*/ UCHAR GroupIndex;
	/*0652*/ UCHAR PrcbPad05[0x2];
	/*0654*/ ULONG InitialApicId;
	/*0658*/ ULONG ScbOffset;
	/*065c*/ ULONG ApicMask;
	/*0660*/ void * AcpiReserved;
	/*0668*/ ULONG CFlushSize;
	/*066c*/ ULONG PrcbPad10;
	/*0670*/
};

struct _KPROCESS;

struct _KPROCESSOR_STATE {
	/*0000*/ _KSPECIAL_REGISTERS SpecialRegisters;
	/*00e0*/ _CONTEXT ContextFrame;
	/*05b0*/
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
	/*00e0*/
};

struct _KSPIN_LOCK_QUEUE {
	/*0000*/ _KSPIN_LOCK_QUEUE * volatile Next;
	/*0008*/ ULONGLONG * volatile Lock;
	void _KSPIN_LOCK_QUEUE( _KSPIN_LOCK_QUEUE && );
	void _KSPIN_LOCK_QUEUE( _KSPIN_LOCK_QUEUE const & );
	_KSPIN_LOCK_QUEUE & operator=( _KSPIN_LOCK_QUEUE && );
	_KSPIN_LOCK_QUEUE & operator=( _KSPIN_LOCK_QUEUE const & );
	/*0010*/
};

struct _KSYSTEM_TIME {
	/*0000*/ ULONG LowPart;
	/*0004*/ LONG High1Time;
	/*0008*/ LONG High2Time;
	/*000c*/
};

struct _KTHREAD;

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
	/*02f0*/ ULONG SpareBits : 22; // 0xfffffc00;
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
	/*037c*/ ULONG Reserved8;
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

struct _KWAIT_CHAIN {
	/*0000*/ _SINGLE_LIST_ENTRY Head;
	/*0008*/
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

struct _LIST_ENTRY {
	/*0000*/ _LIST_ENTRY * Flink;
	/*0008*/ _LIST_ENTRY * Blink;
	/*0010*/
};

struct _LOOKASIDE_LIST_EX {
	/*0000*/ _GENERAL_LOOKASIDE_POOL L;
	/*0060*/
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

enum _MIRACAST_WATCHDOG_STEP {
	MiracastWatchdogStep_CreateDriverContext = 0x0,
	MiracastWatchdogStep_StartMiracastSession = 0x1,
	MiracastWatchdogStep_StopMiracastSession = 0x2,
	MiracastWatchdogStep_DestroyDriverContext = 0x3,
	MiracastWatchdogStep_Maximum_Value = 0x4
};

enum _MODE {
	KernelMode = 0x0,
	UserMode = 0x1,
	MaximumMode = 0x2
};

enum _MODERN_SCALE_FACTOR {
	MODERN_SCALE_INVALID = 0x0,
	MODERN_SCALE_100_PERCENT = 0x64,
	MODERN_SCALE_140_PERCENT = 0x8c,
	MODERN_SCALE_180_PERCENT = 0xb4
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

union _OBJECTOWNER {
	/*0000*/ _OBJECTOWNER_S Share;
	/*0000*/ ULONG ulObj;
	/*0004*/
};

struct _OBJECTOWNER_S {
	/*0000*/ ULONG Lock : 01; // 0x00000001;
	/*0000*/ ULONG Pid_Shifted : 31; // 0xfffffffe;
	/*0004*/
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

struct _OBJECT_DUMP_CONTROL {
	/*0000*/ void * Stream;
	/*0008*/ ULONG Detail;
	/*0010*/
};

struct _OBJECT_HANDLE_INFORMATION {
	/*0000*/ ULONG HandleAttributes;
	/*0004*/ ULONG GrantedAccess;
	/*0008*/
};

struct _OBJECT_NAME_INFORMATION {
	/*0000*/ _UNICODE_STRING Name;
	/*0010*/
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
	/*0002*/ UCHAR ObjectTypeFlags;
	/*0002*/ UCHAR CaseInsensitive : 01; // 0x01;
	/*0002*/ UCHAR UnnamedObjectsOnly : 01; // 0x02;
	/*0002*/ UCHAR UseDefaultObject : 01; // 0x04;
	/*0002*/ UCHAR SecurityRequired : 01; // 0x08;
	/*0002*/ UCHAR MaintainHandleCount : 01; // 0x10;
	/*0002*/ UCHAR MaintainTypeList : 01; // 0x20;
	/*0002*/ UCHAR SupportsObjectCallbacks : 01; // 0x40;
	/*0002*/ UCHAR CacheAligned : 01; // 0x80;
	/*0003*/ UCHAR ObjectTypeFlags2;
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

struct _OB_EXTENDED_PARSE_PARAMETERS {
	/*0000*/ USHORT Length;
	/*0004*/ ULONG RestrictedAccessMask;
	/*0008*/ _EJOB * Silo;
	/*0010*/
};

enum _OB_OPEN_REASON {
	ObCreateHandle = 0x0,
	ObOpenHandle = 0x1,
	ObDuplicateHandle = 0x2,
	ObInheritHandle = 0x3,
	ObMaxOpenReason = 0x4
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
	/*0050*/ ULONG ReservedBits0 : 27; // 0xffffffe0;
	/*0054*/ UCHAR Padding1[0x4];
	/*0058*/ void * KernelCallbackTable;
	/*0058*/ void * UserSharedInfoPtr;
	/*0060*/ ULONG SystemReserved[0x1];
	/*0064*/ ULONG AtlThunkSListPtr32;
	/*0068*/ void * ApiSetMap;
	/*0070*/ ULONG TlsExpansionCounter;
	/*0074*/ UCHAR Padding2[0x4];
	/*0078*/ void * TlsBitmap;
	/*0080*/ ULONG TlsBitmapBits[0x2];
	/*0088*/ void * ReadOnlySharedMemoryBase;
	/*0090*/ void * SparePvoid0;
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
	void _PEB( _PEB && );
	void _PEB( _PEB const & );
	_PEB & operator=( _PEB && );
	_PEB & operator=( _PEB const & );
	/*07a0*/
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

struct _PRIVILEGE_SET {
	/*0000*/ ULONG PrivilegeCount;
	/*0004*/ ULONG Control;
	/*0008*/ _LUID_AND_ATTRIBUTES Privilege[0x1];
	/*0014*/
};

struct _PROCESSOR_NUMBER {
	/*0000*/ USHORT Group;
	/*0002*/ UCHAR Number;
	/*0003*/ UCHAR Reserved;
	/*0004*/
};

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
	PsAttributeMax = 0x18
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
	PsProtectedSignerMax = 0x8
};

enum _PS_PROTECTED_TYPE {
	PsProtectedTypeNone = 0x0,
	PsProtectedTypeProtectedLight = 0x1,
	PsProtectedTypeProtected = 0x2,
	PsProtectedTypeMax = 0x3
};

enum _PS_STD_HANDLE_STATE {
	PsNeverDuplicate = 0x0,
	PsRequestDuplicate = 0x1,
	PsAlwaysDuplicate = 0x2,
	PsMaxStdHandleStates = 0x3
};

enum _PS_WAKE_REASON {
	PsWakeReasonUser = 0x0,
	PsWakeReasonExecutionRequired = 0x1,
	PsWakeReasonKernel = 0x2,
	PsWakeReasonInstrumentation = 0x3,
	PsWakeReasonPreserveProcess = 0x4,
	PsMaxWakeReasons = 0x5
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

struct _RTL_ACTIVATION_CONTEXT_STACK_FRAME;

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

struct _RTL_CRITICAL_SECTION;

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

struct _RTL_RB_TREE {
	/*0000*/ _RTL_BALANCED_NODE * Root;
	/*0008*/ _RTL_BALANCED_NODE * Min;
	/*0010*/
};

enum _RTL_RESOURCE_POLICY_FLAGS {
	RTL_RESOURCE_POLICY_FLAGS_NONE = 0x0
};

struct _RTL_SPLAY_LINKS {
	/*0000*/ _RTL_SPLAY_LINKS * Parent;
	/*0008*/ _RTL_SPLAY_LINKS * LeftChild;
	/*0010*/ _RTL_SPLAY_LINKS * RightChild;
	/*0018*/
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

struct _SCATTER_GATHER_ELEMENT {
	/*0000*/ _LARGE_INTEGER Address;
	/*0008*/ ULONG Length;
	/*0010*/ ULONGLONG Reserved;
	/*0018*/
};

struct _SCATTER_GATHER_LIST {
	/*0000*/ ULONG NumberOfElements;
	/*0008*/ ULONGLONG Reserved;
	/*0010*/ _SCATTER_GATHER_ELEMENT Elements[];
	/*0010*/
};

struct _SCSI_REQUEST_BLOCK;

struct _SECTION_OBJECT_POINTERS {
	/*0000*/ void * DataSectionObject;
	/*0008*/ void * SharedCacheMap;
	/*0010*/ void * ImageSectionObject;
	/*0018*/
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

struct _SINGLE_LIST_ENTRY {
	/*0000*/ _SINGLE_LIST_ENTRY * Next;
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

struct _STRING {
	/*0000*/ USHORT Length;
	/*0002*/ USHORT MaximumLength;
	/*0008*/ CHAR * Buffer;
	/*0010*/
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
	/*0000*/ ULONG Reserved2 : 10; // 0xffc00000;
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
	/*0190*/ void * SystemReserved1[0x25];
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
	/*17ee*/ USHORT SpareSameTebBits : 02; // 0xc000;
	/*17f0*/ void * TxnScopeEnterCallback;
	/*17f8*/ void * TxnScopeExitCallback;
	/*1800*/ void * TxnScopeContext;
	/*1808*/ ULONG LockCount;
	/*180c*/ LONG WowTebOffset;
	/*1810*/ void * ResourceRetValue;
	/*1818*/ void * ReservedForWdf;
	/*1820*/ ULONGLONG ReservedForCrt;
	/*1828*/ _GUID EffectiveContainerId;
	void _TEB( _TEB && );
	void _TEB( _TEB const & );
	_TEB & operator=( _TEB && );
	_TEB & operator=( _TEB const & );
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

struct _TL {
	/*0000*/ _TL * next;
	/*0008*/ void * pobj;
	/*0010*/ void (* pfnFree)( void * );
	/*0018*/
};

struct _TLSPRITESTATE {
	/*0000*/ UCHAR bInsideDriverCall;
	/*0004*/ ULONG flOriginalSurfFlags;
	/*0008*/ ULONG iOriginalType;
	/*000c*/ ULONG flSpriteSurfFlags;
	/*0010*/ ULONG iSpriteType;
	/*0014*/ ULONG flags;
	/*0018*/ ULONG iType;
	/*0020*/ void * pState;
	/*0028*/ void * pfnStrokeAndFillPath;
	/*0030*/ void * pfnStrokePath;
	/*0038*/ void * pfnFillPath;
	/*0040*/ void * pfnPaint;
	/*0048*/ void * pfnBitBlt;
	/*0050*/ void * pfnCopyBits;
	/*0058*/ void * pfnStretchBlt;
	/*0060*/ void * pfnTextOut;
	/*0068*/ void * pfnLineTo;
	/*0070*/ void * pfnTransparentBlt;
	/*0078*/ void * pfnAlphaBlend;
	/*0080*/ void * pfnPlgBlt;
	/*0088*/ void * pfnGradientFill;
	/*0090*/ void * pfnSaveScreenBits;
	/*0098*/ void * pfnStretchBltROP;
	/*00a0*/ void * pfnDrawStream;
	/*00a8*/
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

struct _TXN_PARAMETER_BLOCK {
	/*0000*/ USHORT Length;
	/*0002*/ USHORT TxFsContext;
	/*0008*/ void * TransactionObject;
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

struct _UNICODE_STRING {
	/*0000*/ USHORT Length;
	/*0002*/ USHORT MaximumLength;
	/*0008*/ WCHAR * Buffer;
	/*0010*/
};

union _UPPER_HANDLE_BITS {
	
	struct {
		
		/*0000*/ UCHAR fullType;
		union {
			/*0001*/ UCHAR unique;
			/*0001*/ UCHAR index;
			/*0002*/
		} u;
		/*0002*/
	} s;
	/*0000*/ USHORT full;
	/*0002*/
};

enum _USER_ACTIVITY_PRESENCE {
	PowerUserPresent = 0x0,
	PowerUserNotPresent = 0x1,
	PowerUserInactive = 0x2,
	PowerUserMaximum = 0x3,
	PowerUserInvalid = 0x3
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

struct _W32PROCESS {
	/*0000*/ _EPROCESS * Process;
	/*0008*/ ULONG RefCount;
	/*000c*/ ULONG W32PF_Flags;
	/*0010*/ _KEVENT * InputIdleEvent;
	/*0018*/ ULONG StartCursorHideTime;
	/*0020*/ _W32PROCESS * NextStart;
	/*0028*/ void * pDCAttrList;
	/*0030*/ void * pBrushAttrList;
	/*0038*/ ULONG W32Pid;
	/*003c*/ LONG GDIHandleCount;
	/*0040*/ ULONG GDIHandleCountPeak;
	/*0044*/ LONG UserHandleCount;
	/*0048*/ ULONG UserHandleCountPeak;
	/*0050*/ _EX_PUSH_LOCK GDIPushLock;
	/*0058*/ _RTL_AVL_TABLE GDIEngUserMemAllocTable;
	/*00c0*/ _LIST_ENTRY GDIDcAttrFreeList;
	/*00d0*/ _LIST_ENTRY GDIBrushAttrFreeList;
	/*00e0*/ _LIST_ENTRY GDIW32PIDLockedBitmaps;
	/*00f0*/ void * hSecureGdiSharedHandleTable;
	/*00f8*/ void * DxProcess;
	/*0100*/ void * DCompositionProcess;
	/*0108*/ ULONG UMPDSandboxingEnabled;
	/*0110*/ void * pWakeReference;
	/*0118*/ ULONG defaultDpiContext;
	/*0120*/
};

struct _W32THREAD {
	/*0000*/ _ETHREAD * pEThread;
	/*0008*/ ULONG RefCount;
	/*0010*/ _TL * ptlW32;
	/*0018*/ void * pgdiDcattr;
	/*0020*/ void * pgdiBrushAttr;
	/*0028*/ _LIST_ENTRY UMPDOBJList;
	/*0038*/ void * pUMPDHeap;
	/*0040*/ void * pProxyPort;
	/*0048*/ void * pClientID;
	/*0050*/ void * DxThread;
	/*0058*/ _LIST_ENTRY GdiTmpTgoList;
	/*0068*/ ULONG pRBRecursionCount;
	/*006c*/ ULONG pNonRBRecursionCount;
	/*0070*/ _TLSPRITESTATE tlSpriteState;
	/*0118*/ void * pSpriteState;
	/*0120*/ void * pDevHTInfo;
	/*0128*/ ULONG ulDevHTInfoUniqueness;
	/*0130*/ void * pdcoAA;
	/*0138*/ void * pdcoRender;
	/*0140*/ void * pdcoSrc;
	/*0148*/ UCHAR bEnableEngUpdateDeviceSurface;
	/*0149*/ UCHAR bIncludeSprites;
	/*014a*/ UCHAR bEnableAppContainerRendering;
	/*014c*/ ULONG ulWindowSystemRendering;
	/*0150*/ ULONG iVisRgnUniqueness;
	/*0154*/ ULONG dpiContext;
	/*0158*/ void * pUmfdTls;
	/*0160*/ tagDPICONTEXTINFO * pdci;
	/*0168*/
};

struct _W32THREADNONPAGED {
	/*0000*/ _W32THREAD * pW32Thread;
	/*0008*/ LONGLONG llQPCUserCritAcquire;
	/*0010*/ ULONGLONG ullUserCritAcquireToken;
	/*0018*/
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

enum _WD_DIAG_NOTIFY_USER_MESSAGE {
	WD_DIAG_NOTIFY_USER_MESSAGE_DBG_REPORT = 0x0,
	WD_DIAG_NOTIFY_USER_MESSAGE_TDR_RECOVERY = 0x1,
	WD_DIAG_NOTIFY_USER_MESSAGE_FORCED_TDR_IGNORED = 0x2,
	WD_DIAG_NOTIFY_SDC_FORCE_MODE_ENUMERATION_USED = 0x3,
	WD_DIAG_NOTIFY_USER_MESSAGE_TDR_APPLICATION_BLOCKED = 0x4,
	WD_DIAG_NOTIFY_FORCE_REINSTALL_DRIVER = 0x5,
	WD_DIAG_NOTIFY_USER_MESSAGE_DOD_TDR_RECOVERY = 0x6,
	WD_DIAG_NOTIFY_USER_MESSAGE_DWMINIT_TIMEOUT = 0x7,
	WD_DIAG_NOTIFY_USER_MESSAGE_OOBE_COMPLETE_NO_DRIVER = 0x8,
	WD_DIAG_NOTIFY_USER_MESSAGE_ALL = 0x9,
	WD_DIAG_NOTIFY_USER_MESSAGE_FIRST = 0x0
};

enum _WD_LOGEVENT_LEVEL {
	WdCriticalError = 0x0,
	WdAssertion = 0x1,
	WdError = 0x2,
	WdWarning = 0x3,
	WdEvent = 0x4,
	WdTrace = 0x5,
	WdLowResource = 0x6,
	WdDmmEvent = 0x7,
	WdPresentTokenEvent = 0x8,
	WdPower = 0x9,
	WdDebug = 0xa,
	WdLogLevelAll = 0xb,
	WdLogLevelFirst = 0x0
};

enum _WD_LOGEVENT_SOURCE {
	WdLogSrcUnknown = 0x0,
	WdVideoDxgPort = 0x1,
	WdVideoDxgkrnl = 0x2,
	WdVideoMemoryManager = 0x3,
	WdVideoScheduler = 0x4,
	WdVideoTdr = 0x5,
	WdVideoDisplayModeManager = 0x6,
	WdVideoCdd = 0x7,
	WdGdi = 0x8,
	WdNtUser = 0x9,
	WdLogSrcAll = 0xa,
	WdLogSrcFirst = 0x1
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

enum _WHEA_ERROR_TYPE {
	WheaErrTypeProcessor = 0x0,
	WheaErrTypeMemory = 0x1,
	WheaErrTypePCIExpress = 0x2,
	WheaErrTypeNMI = 0x3,
	WheaErrTypePCIXBus = 0x4,
	WheaErrTypePCIXDevice = 0x5,
	WheaErrTypeGeneric = 0x6
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

struct _WNF_STATE_NAME {
	/*0000*/ ULONG Data[0x2];
	/*0008*/
};

struct _WORK_QUEUE_ITEM {
	/*0000*/ _LIST_ENTRY List;
	/*0010*/ void (* WorkerRoutine)( void * );
	/*0018*/ void * Parameter;
	/*0020*/
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

struct _XSTATE_FEATURE {
	/*0000*/ ULONG Offset;
	/*0004*/ ULONG Size;
	/*0008*/
};

enum tagAR_STATE {
	AR_ENABLED = 0x0,
	AR_DISABLED = 0x1,
	AR_SUPPRESSED = 0x2,
	AR_REMOTESESSION = 0x4,
	AR_MULTIMON = 0x8,
	AR_NOSENSOR = 0x10,
	AR_NOT_SUPPORTED = 0x20,
	AR_DOCKED = 0x40,
	AR_LAPTOP = 0x80
};

struct tagDPICONTEXTINFO {
	/*0000*/ ULONG dpiContext;
	/*0004*/ ULONG fDirty;
	/*0008*/
};

struct tagVERIFIERTRACKHDR {
	/*0000*/ _LIST_ENTRY list;
	/*0010*/ ULONGLONG ulSize;
	/*0018*/ ULONG ulTag;
	/*0020*/
};

struct tagVSTATE {
	/*0000*/ ULONG fl;
	/*0004*/ INT bSystemStable;
	/*0008*/ ULONG ulRandomSeed;
	/*000c*/ ULONG ulFailureMask;
	/*0010*/ ULONG ulDebugLevel;
	/*0018*/ HSEMAPHORE__ * hsemPoolTracker;
	/*0020*/ _LIST_ENTRY lePoolTrackerHead;
	/*0030*/
};
