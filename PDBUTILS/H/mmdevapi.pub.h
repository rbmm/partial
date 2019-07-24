namespace ATL
{
	class CAtlArray<CKsDeviceTopology::HARDWARE_EVENT_DATA,CElementTraits<CKsDeviceTopology::HARDWARE_EVENT_DATA> >
	{
		bool GrowBuffer(unsigned __int64);
	public:
		CKsDeviceTopology::HARDWARE_EVENT_DATA & operator[](unsigned __int64);
		unsigned __int64 Add(CKsDeviceTopology::HARDWARE_EVENT_DATA const &);
		void RemoveAt(unsigned __int64,unsigned __int64);
	};

	class CAtlArray<FAKE_COM_REGISTRATION,CElementTraits<FAKE_COM_REGISTRATION> >
	{
		bool GrowBuffer(unsigned __int64);
	public:
		FAKE_COM_REGISTRATION & operator[](unsigned __int64);
		unsigned __int64 Add(FAKE_COM_REGISTRATION const &);
	};

	class CAtlArray<MediaNotification,CElementTraits<MediaNotification> >
	{
		bool GrowBuffer(unsigned __int64);
	public:
		unsigned __int64 Add(MediaNotification const &);
		~CAtlArray<MediaNotification,CElementTraits<MediaNotification> >();
	};

	struct CAtlBaseModule
	{
		CAtlBaseModule();
		static bool m_bInitFailed;
		~CAtlBaseModule();
	};

	struct CAtlComModule
	{
		CAtlComModule();
		void ExecuteObjectMain(bool);
		~CAtlComModule();
	};

	struct CAtlDllModuleT<CMMDeviceModule>
	{
		long DllUnregisterServer(int);
	};

	class CAtlList<IMMNotificationClient *,CElementTraits<IMMNotificationClient *> >
	{
		void FreeNode(CAtlList<IMMNotificationClient *,CElementTraits<IMMNotificationClient *> >::CNode *);
	public:
		IMMNotificationClient * & GetNext(__POSITION * &);
		void RemoveAll();
		void RemoveAt(__POSITION *);
		~CAtlList<IMMNotificationClient *,CElementTraits<IMMNotificationClient *> >();
	};

	class CAtlList<IMMNotificationClientInternal *,CElementTraits<IMMNotificationClientInternal *> >
	{
		CAtlList<IMMNotificationClientInternal *,CElementTraits<IMMNotificationClientInternal *> >::CNode * NewNode(IMMNotificationClientInternal * const &,CAtlList<IMMNotificationClientInternal *,CElementTraits<IMMNotificationClientInternal *> >::CNode *,CAtlList<IMMNotificationClientInternal *,CElementTraits<IMMNotificationClientInternal *> >::CNode *);
		void FreeNode(CAtlList<IMMNotificationClientInternal *,CElementTraits<IMMNotificationClientInternal *> >::CNode *);
	public:
		IMMNotificationClientInternal * & GetNext(__POSITION * &);
		void RemoveAll();
		void RemoveAt(__POSITION *);
		~CAtlList<IMMNotificationClientInternal *,CElementTraits<IMMNotificationClientInternal *> >();
	};

	class CAtlList<MEDIA_NOTIFICATION_BLOCK *,CElementTraits<MEDIA_NOTIFICATION_BLOCK *> >
	{
		void FreeNode(CAtlList<MEDIA_NOTIFICATION_BLOCK *,CElementTraits<MEDIA_NOTIFICATION_BLOCK *> >::CNode *);
		void GetFreeNode();
	public:
		void RemoveAll();
	};

	class CAtlList<MMDEVICE_ASYNC_NOTIFICATION_BLOCK *,CElementTraits<MMDEVICE_ASYNC_NOTIFICATION_BLOCK *> >
	{
		CAtlList<MMDEVICE_ASYNC_NOTIFICATION_BLOCK *,CElementTraits<MMDEVICE_ASYNC_NOTIFICATION_BLOCK *> >::CNode * NewNode(MMDEVICE_ASYNC_NOTIFICATION_BLOCK * const &,CAtlList<MMDEVICE_ASYNC_NOTIFICATION_BLOCK *,CElementTraits<MMDEVICE_ASYNC_NOTIFICATION_BLOCK *> >::CNode *,CAtlList<MMDEVICE_ASYNC_NOTIFICATION_BLOCK *,CElementTraits<MMDEVICE_ASYNC_NOTIFICATION_BLOCK *> >::CNode *);
		void FreeNode(CAtlList<MMDEVICE_ASYNC_NOTIFICATION_BLOCK *,CElementTraits<MMDEVICE_ASYNC_NOTIFICATION_BLOCK *> >::CNode *);
	public:
		__POSITION * AddTail(MMDEVICE_ASYNC_NOTIFICATION_BLOCK * const &);
		void RemoveAll();
	};

	struct CAtlModule
	{
		long UpdateRegistryFromResourceS(unsigned int,int,_ATL_REGMAP_ENTRY *);
		virtual long GetGITPtr(IGlobalInterfaceTable * *);
		virtual long GetLockCount();
		virtual long Lock();
		virtual long Unlock();
	};

	struct CAtlModuleT<CMMDeviceModule>
	{
		long RegisterServer(int,_GUID const *);
		virtual long AddCommonRGSReplacements(IRegistrarBase *);
	};

	struct CAtlPlex
	{
		static CAtlPlex * Create(CAtlPlex * &,unsigned __int64,unsigned __int64);
		void FreeDataChain();
	};

	struct CAtlStringMgr
	{
		CAtlStringMgr(IAtlMemMgr *);
		virtual CStringData * Allocate(int,int);
		virtual CStringData * GetNilString();
		virtual CStringData * Reallocate(CStringData *,int,int);
		virtual IAtlStringMgr * Clone();
		virtual void Free(CStringData *);
	};

	struct CAtlWinModule
	{
		CAtlWinModule();
		~CAtlWinModule();
	};

	struct CAutoVectorPtr<unsigned short>
	{
		~CAutoVectorPtr<unsigned short>();
	};

	struct CComAggObject<ActivateAudioInterfaceWorker>
	{
		CComAggObject<ActivateAudioInterfaceWorker>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComAggObject<ActivateAudioInterfaceWorker>();
	};

	struct CComClassFactory
	{
		virtual long CreateInstance(IUnknown *,_GUID const &,void * *);
		virtual long LockServer(int);
	};

	struct CComClassFactorySingleton<CDeviceEnumerator>
	{
		virtual long CreateInstance(IUnknown *,_GUID const &,void * *);
	};

	struct CComContainedObject<ActivateAudioInterfaceWorker>
	{
		virtual IUnknown * GetControllingUnknown();
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CComContainedObject<ActivateAudioInterfaceWorker>();
	};

	struct CComCreator2<CComCreator<CComObject<ActivateAudioInterfaceWorker> >,CComCreator<CComAggObject<ActivateAudioInterfaceWorker> > >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CDeviceEnumerator> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CEndpointManager> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComAggObject<ActivateAudioInterfaceWorker> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<ActivateAudioInterfaceWorker> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CDeviceEnumerator> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CEndpointManager> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObjectCached<CComClassFactory> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObjectCached<CComClassFactorySingleton<CDeviceEnumerator> > >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCritSecLock<CComAutoCriticalSection>
	{
		CComCritSecLock<CComAutoCriticalSection>(CComAutoCriticalSection &,bool);
		~CComCritSecLock<CComAutoCriticalSection>();
	};

	struct CComCriticalSection
	{
		long Init();
		~CComCriticalSection();
	};

	struct CComHeapPtr<unsigned short>
	{
		~CComHeapPtr<unsigned short>();
	};

	struct CComObject<ActivateAudioInterfaceWorker>
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<ActivateAudioInterfaceWorker>();
	};

	struct CComObject<CDeviceEnumerator>
	{
		CComObject<CDeviceEnumerator>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CDeviceEnumerator>();
	};

	struct CComObject<CEndpointManager>
	{
		CComObject<CEndpointManager>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CEndpointManager>();
	};

	struct CComObject<CMidiPortDeviceIoControl>
	{
		static long CreateInstance(CComObject<CMidiPortDeviceIoControl> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CMidiPortDeviceIoControl>();
	};

	struct CComObjectCached<CComClassFactory>
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
	};

	struct CComObjectCached<CComClassFactorySingleton<CDeviceEnumerator> >
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
	};

	struct CComObjectCached<CDeviceEnumerator>
	{
		static long CreateInstance(CComObjectCached<CDeviceEnumerator> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
	};

	struct CComObjectRootBase
	{
		static _ATL_CATMAP_ENTRY const * GetCategoryMap();
		static long _Delegate(void *,_GUID const &,void * *,unsigned __int64);
		static void ObjectMain(bool);
	};

	struct CComObjectRootEx<CComMultiThreadModel>
	{
		~CComObjectRootEx<CComMultiThreadModel>();
	};

	struct CComObjectRootEx<CComMultiThreadModelNoCS>
	{
		~CComObjectRootEx<CComMultiThreadModelNoCS>();
	};

	struct CComPtr<CComObject<CDeviceEnumerator> >
	{
		~CComPtr<CComObject<CDeviceEnumerator> >();
	};

	struct CComPtr<CTSEnumeratorDll>
	{
		~CComPtr<CTSEnumeratorDll>();
	};

	struct CComPtr<CTSEnumeratorWrapper>
	{
		~CComPtr<CTSEnumeratorWrapper>();
	};

	struct CComPtr<IActivateAudioInterfaceAsyncOperation>
	{
		~CComPtr<IActivateAudioInterfaceAsyncOperation>();
	};

	struct CComPtr<IAudioInputSelector>
	{
		~CComPtr<IAudioInputSelector>();
	};

	struct CComPtr<IAudioMute>
	{
		~CComPtr<IAudioMute>();
	};

	struct CComPtr<IAudioOutputSelector>
	{
		~CComPtr<IAudioOutputSelector>();
	};

	struct CComPtr<IConnector>
	{
		~CComPtr<IConnector>();
	};

	struct CComPtr<IControlChangeDelegate>
	{
		~CComPtr<IControlChangeDelegate>();
	};

	struct CComPtr<IControlInterface>
	{
		~CComPtr<IControlInterface>();
	};

	struct CComPtr<IDeviceTopology>
	{
		~CComPtr<IDeviceTopology>();
	};

	struct CComPtr<IHardwareAudioEngineControl>
	{
		~CComPtr<IHardwareAudioEngineControl>();
	};

	struct CComPtr<IKsFormatSupport>
	{
		~CComPtr<IKsFormatSupport>();
	};

	struct CComPtr<IMMDevice>
	{
		~CComPtr<IMMDevice>();
	};

	struct CComPtr<IMMDeviceCollection>
	{
		~CComPtr<IMMDeviceCollection>();
	};

	struct CComPtr<IMMDeviceEnumerator>
	{
		~CComPtr<IMMDeviceEnumerator>();
	};

	struct CComPtr<IMMEndpointInternal>
	{
		~CComPtr<IMMEndpointInternal>();
	};

	struct CComPtr<IPart>
	{
		IPart * operator=<IConnector>(CComPtr<IConnector> const &);
		~CComPtr<IPart>();
	};

	struct CComPtr<IPartsList>
	{
		~CComPtr<IPartsList>();
	};

	struct CComPtr<IPnpDeviceEnumerator>
	{
		~CComPtr<IPnpDeviceEnumerator>();
	};

	struct CComPtr<IPnpNotificationClient>
	{
		~CComPtr<IPnpNotificationClient>();
	};

	struct CComPtr<IPropertyStore>
	{
		CComPtr<IPropertyStore>();
		~CComPtr<IPropertyStore>();
	};

	struct CComPtr<ITestPnpNotificationClient>
	{
		~CComPtr<ITestPnpNotificationClient>();
	};

	struct CComPtrBase<IMMDeviceEnumerator>
	{
		long CopyTo(IMMDeviceEnumerator * *);
		~CComPtrBase<IMMDeviceEnumerator>();
	};

	class CComPtrBase<IPnpNotificationClient>
	{
	protected:
		CComPtrBase<IPnpNotificationClient>(IPnpNotificationClient *);
	};

	struct CComPtrBase<IUnknown>
	{
		void Release();
	};

	struct CCritSecLock
	{
		void Lock();
		~CCritSecLock();
	};

	struct CCriticalSection
	{
		CCriticalSection();
		~CCriticalSection();
	};

	struct CExpansionVector
	{
		int Add(unsigned short const *,unsigned short const *);
		long ClearReplacements();
	};

	struct CRegKey
	{
		long Close();
		long Create(HKEY__ *,unsigned short const *,unsigned short *,unsigned long,unsigned long,_SECURITY_ATTRIBUTES *,unsigned long *);
		long DeleteSubKey(unsigned short const *);
		long Open(HKEY__ *,unsigned short const *,unsigned long);
		long RecurseDeleteKey(unsigned short const *);
		long SetMultiStringValue(unsigned short const *,unsigned short const *);
		~CRegKey();
	};

	class CRegObject
	{
	protected:
		long RegisterFromResource(unsigned short const *,unsigned short const *,unsigned short const *,int);
	public:
		unsigned short const * StrFromMap(unsigned short *);
		virtual long AddReplacement(unsigned short const *,unsigned short const *);
		virtual long ClearReplacements();
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CRegObject();
	};

	class CRegParser
	{
		struct CParseBuffer
		{
			CParseBuffer(int);
			int Append(unsigned short const *,int);
			~CParseBuffer();
		};

	protected:
		int CanForceRemoveKey(unsigned short const *);
		int HasSubKeys(HKEY__ *);
		long AddValue(CRegKey &,unsigned short const *,unsigned short *);
		long NextToken(unsigned short *);
		long RegisterSubkeys(unsigned short *,HKEY__ *,int,int);
		long SkipAssignment(unsigned short *);
		static int VTFromRegType(unsigned short const *,unsigned short &);
		static unsigned short * StrChrW(unsigned short *,unsigned short);
		static unsigned short const * const * const rgszNeverDelete;
		void SkipWhiteSpace();
	public:
		long PreProcessBuffer(unsigned short *,unsigned short * *);
		long RegisterBuffer(unsigned short *,int);
	};

	struct CSimpleArray<unsigned short,CSimpleArrayEqualHelper<unsigned short> >
	{
		void RemoveAll();
	};

	struct CSimpleMap<unsigned short *,unsigned short *,CExpansionVectorEqualHelper>
	{
		int Add(unsigned short * const &,unsigned short * const &);
		unsigned short * & GetValueAt(int);
		void RemoveAll();
	};

	class CSimpleStringT<unsigned short,0>
	{
		void Fork(int);
		void PrepareWrite2(int);
		void Reallocate(int);
		void SetLength(int);
	protected:
		static void ThrowMemoryException();
	public:
		void Empty();
		void SetString(unsigned short const *,int);
	};

	struct CStringData
	{
		void Release();
	};

	struct CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > >
	{
		~CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > >();
	};

	class CTempBuffer<unsigned char,256,CCRTAllocator>
	{
		void AllocateHeap(unsigned __int64);
		void FreeHeap();
	public:
		~CTempBuffer<unsigned char,256,CCRTAllocator>();
	};

	class CTempBuffer<unsigned short,1024,CCRTAllocator>
	{
		void AllocateHeap(unsigned __int64);
		void FreeHeap();
	public:
		~CTempBuffer<unsigned short,1024,CCRTAllocator>();
	};

	class CTempBuffer<unsigned short,256,CCRTAllocator>
	{
		void AllocateHeap(unsigned __int64);
		void FreeHeap();
	public:
		~CTempBuffer<unsigned short,256,CCRTAllocator>();
	};

	struct CWin32Heap
	{
		virtual unsigned __int64 GetSize(void *);
		virtual void * Allocate(unsigned __int64);
		virtual void * Reallocate(void *,unsigned __int64);
		virtual void Free(void *);
		virtual ~CWin32Heap();
	};

	namespace _ATL_SAFE_ALLOCA_IMPL
	{
		struct CAtlSafeAllocBufferManager<CCRTAllocator>
		{
			~CAtlSafeAllocBufferManager<CCRTAllocator>();
		};

	};

	ATL::CAtlBaseModule _AtlBaseModule;
	ATL::CAtlComModule _AtlComModule;
	ATL::CAtlModule * _pAtlModule;
	ATL::CAtlStringMgr g_strmgr;
	ATL::CAtlWinModule _AtlWinModule;
	ATL::CWin32Heap g_strheap;
	IUnknown * AtlComPtrAssign(IUnknown * *,IUnknown *);
	IUnknown * AtlComQIPtrAssign(IUnknown * *,IUnknown *,_GUID const &);
	int InlineIsEqualUnknown(_GUID const &);
	long (* _pPerfRegFunc)(HINSTANCE__ *);
	long (* _pPerfUnRegFunc)();
	long AtlComModuleGetClassObject(ATL::_ATL_COM_MODULE70 *,_GUID const &,_GUID const &,void * *);
	long AtlHresultFromLastError();
	long AtlHresultFromWin32(unsigned long);
	long AtlMultiply<unsigned __int64>(unsigned __int64 *,unsigned __int64,unsigned __int64);
	long AtlMultiply<unsigned long>(unsigned long *,unsigned long,unsigned long);
	long AtlRegisterClassCategoriesHelper(_GUID const &,ATL::_ATL_CATMAP_ENTRY const *,int);
	unsigned __int64 AtlMultiplyThrow<unsigned __int64>(unsigned __int64,unsigned __int64);
	void AtlCallTermFunc(ATL::_ATL_MODULE70 *);
	void AtlThrowImpl(long);
};

struct AXB
{
	int WaitForOperations(unsigned long);
	void EndOperation();
	~AXB();
};

struct ActivateAudioInterfaceWorker
{
	ActivateAudioInterfaceWorker();
	long FinalConstruct();
	static long UpdateRegistry(int);
	static void WorkCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_WORK *);
	virtual IUnknown * GetControllingUnknown();
	virtual long GetActivateResult(long *,IUnknown * *);
	virtual long Initialize(unsigned short const *,_GUID const &,tagPROPVARIANT *,IActivateAudioInterfaceCompletionHandler *,unsigned long);
	void FinalRelease();
	~ActivateAudioInterfaceWorker();
};

struct CAudioAutoGainControl
{
	virtual IUnknown * GetIUnknown();
	virtual long GetEnabled(int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetEnabled(int,_GUID const *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioBass
{
	virtual IUnknown * GetIUnknown();
	virtual long GetChannelCount(unsigned int *);
	virtual long GetLevel(unsigned int,float *);
	virtual long GetLevelRange(unsigned int,float *,float *,float *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetLevel(unsigned int,float,_GUID const *);
	virtual long SetLevelAllChannels(float * const,unsigned long,_GUID const *);
	virtual long SetLevelUniform(float,_GUID const *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioChannelConfig
{
	virtual IUnknown * GetIUnknown();
	virtual long GetChannelConfig(unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetChannelConfig(unsigned long,_GUID const *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioChannelProperty
{
	CAudioChannelProperty(IControlChangeDelegate *,unsigned long);
	virtual long DecodeActivationParameter(tagPROPVARIANT const *);
	virtual ~CAudioChannelProperty();
};

class CAudioFormatSupport
{
	long GetDataRanges(KSMULTIPLE_ITEM * *);
	long GetIntersection(KS_INTERSECTION *,unsigned long,KSDATAFORMAT * *,unsigned long *);
	long InferSupportFromDataRanges(unsigned long,KSDATAFORMAT *,CAudioFormatSupport::EMatchType,int *);
	long SetProposedFormat(KSDATAFORMAT *,unsigned long);
public:
	virtual long GetDevicePreferredFormat(KSDATAFORMAT * *);
	virtual long GetProposedFormat(KSDATAFORMAT * *);
	virtual long GetProposedFormatForMode(_GUID,KSDATAFORMAT * *);
	virtual long GetSupportedNonPCMFormats(KSMULTIPLE_ITEM * *);
	virtual long IsFormatSupported(KSDATAFORMAT *,unsigned long,int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioInputSelector
{
	CAudioInputSelector(IControlChangeDelegate *,unsigned long);
	virtual IUnknown * GetIUnknown();
	virtual long GetSelection(unsigned int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetSelection(unsigned int,_GUID const *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioLoudness
{
	virtual IUnknown * GetIUnknown();
	virtual long GetEnabled(int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetEnabled(int,_GUID const *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioMidrange
{
	virtual IUnknown * GetIUnknown();
	virtual long GetChannelCount(unsigned int *);
	virtual long GetLevel(unsigned int,float *);
	virtual long GetLevelRange(unsigned int,float *,float *,float *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetLevel(unsigned int,float,_GUID const *);
	virtual long SetLevelAllChannels(float * const,unsigned long,_GUID const *);
	virtual long SetLevelUniform(float,_GUID const *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioMute
{
	virtual IUnknown * GetIUnknown();
	virtual long GetMute(int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetMute(int,_GUID const *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioNodeProperty
{
	CAudioNodeProperty(IControlChangeDelegate *,unsigned long);
};

struct CAudioOutputSelector
{
	CAudioOutputSelector(IControlChangeDelegate *,unsigned long);
	virtual IUnknown * GetIUnknown();
	virtual long GetSelection(unsigned int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetSelection(unsigned int,_GUID const *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioPartPrivate
{
	virtual long Initialize(IPart *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetNotificationEventRegistrationInfo(_tagCONNECTOR_EVENT_INFO *,unsigned int);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioPeakMeter
{
	virtual IUnknown * GetIUnknown();
	virtual long GetChannelCount(unsigned int *);
	virtual long GetLevel(unsigned int,float *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioSignalProcessingModes
{
	virtual long GetModes(_GUID * *,unsigned long *);
	virtual long Initialize(IPart *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioThreadPool
{
	long Initialize();
	virtual _TP_TIMER * CreateTimer(void (*)(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *),void *);
	virtual _TP_WAIT * CreateWait(void (*)(_TP_CALLBACK_INSTANCE *,void *,_TP_WAIT *,long),void *);
	virtual _TP_WORK * CreateWork(void (*)(_TP_CALLBACK_INSTANCE *,void *,_TP_WORK *),void *);
	virtual void CloseTimer(_TP_TIMER *);
	virtual void CloseWait(_TP_WAIT *);
	virtual void CloseWork(_TP_WORK *);
	virtual void SetTimer(_TP_TIMER *,_FILETIME *,unsigned long,unsigned long);
	virtual void SetWait(_TP_WAIT *,void *,_FILETIME *);
	virtual void SubmitWork(_TP_WORK *);
	virtual void WaitForTimerCallbacks(_TP_TIMER *,int);
	virtual void WaitForWaitCallbacks(_TP_WAIT *,int);
	virtual void WaitForWorkCallbacks(_TP_WORK *,int);
};

struct CAudioTreble
{
	virtual IUnknown * GetIUnknown();
	virtual long GetChannelCount(unsigned int *);
	virtual long GetLevel(unsigned int,float *);
	virtual long GetLevelRange(unsigned int,float *,float *,float *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetLevel(unsigned int,float,_GUID const *);
	virtual long SetLevelAllChannels(float * const,unsigned long,_GUID const *);
	virtual long SetLevelUniform(float,_GUID const *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAudioVolumeLevel
{
	virtual IUnknown * GetIUnknown();
	virtual long GetChannelCount(unsigned int *);
	virtual long GetLevel(unsigned int,float *);
	virtual long GetLevelRange(unsigned int,float *,float *,float *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetLevel(unsigned int,float,_GUID const *);
	virtual long SetLevelAllChannels(float * const,unsigned long,_GUID const *);
	virtual long SetLevelUniform(float,_GUID const *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CConnection
{
	virtual long GetLocalConnector(IConnector * *);
	virtual long GetRemoteConnectorId(unsigned short * *);
	virtual long Initialize(CConnector *,unsigned short const *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CConnector
{
	CConnector(CDeviceTopology *,unsigned long);
	virtual long ConnectTo(IConnector *);
	virtual long Disconnect();
	virtual long GetConnectedTo(IConnector * *);
	virtual long GetConnectorIdConnectedTo(unsigned short * *);
	virtual long GetDataFlow(__MIDL___MIDL_itf_devicetopology_0000_0000_0011 *);
	virtual long GetDeviceIdConnectedTo(unsigned short * *);
	virtual long GetType(__MIDL___MIDL_itf_devicetopology_0000_0000_0013 *);
	virtual long IsConnected(int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CControlInterface
{
	virtual long GetActivationParameter(tagPROPVARIANT *);
	virtual long GetIID(_GUID *);
	virtual long GetName(unsigned short * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CDefaultDeviceManager
{
	long GetDefaultEndpoint(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,IMMDevice * *);
	long SetDefaultEndpoint(unsigned short const *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001);
};

struct CDeviceActivator
{
	virtual long Activate(_GUID const &,IMMDevice *,tagPROPVARIANT *,void * *);
};

class CDeviceCollection
{
	~CDeviceCollection();
public:
	virtual long Add(IMMDevice *);
	virtual long GetCount(unsigned int *);
	virtual long Item(unsigned int,IMMDevice * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CDeviceCollection<CEndpointDevice>
{
	virtual long Add(CEndpointDevice *);
	virtual long GetCount(unsigned int *);
	virtual long Item(unsigned int,IMMDevice * *);
	virtual long ItemC(unsigned int,CEndpointDevice * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CDeviceCollection<CSubEndpointDevice>
{
	virtual long Add(CSubEndpointDevice *);
	virtual long GetCount(unsigned int *);
	virtual long Item(unsigned int,IMMDevice * *);
	virtual long ItemC(unsigned int,CSubEndpointDevice * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CDeviceEnumerator
{
	long AddRefInternalCallbacks();
	long GenerateAudioProtocolNotificationInproc(unsigned int);
	long GenerateDeviceNotificationInproc(ENotificationType,unsigned short const *,unsigned long);
	long GenerateNotificationSequence(IMMDevice *,int);
	long GetPnpDevnode(unsigned short const *,IMMDevice * *);
	long GetPnpInterface(unsigned short const *,IMMDevice * *);
	long GetSubEnumerator(IMMDeviceEnumerator * *,unsigned int *);
	long OnAudioProtocolNotification(unsigned int);
	long OnMainEnumeratorNotification(MMDEVICE_NOTIFICATION_BLOCK *);
	long RefreshSubEnumerator(IMMDeviceEnumerator * *);
	long RegisterInternalCallbacks();
	long RegisterPnpHandleNotificationCallbackHelper(unsigned short const *,IPnpNotificationClient *);
	long ReleaseInternalCallbacks();
	long SubEnumeratorRegisterEndpointNotificationCallback();
	long SubEnumeratorUnregisterEndpointNotificationCallback();
	long UnregisterPnpHandleNotificationCallbackHelper(unsigned short const *,IPnpNotificationClient *);
	static unsigned long CMEventCallback(HCMNOTIFICATION__ *,void *,_CM_NOTIFY_ACTION,_CM_NOTIFY_EVENT_DATA *,unsigned long);
	static void AsyncNotificationCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_WORK *);
	static void AudiosrvNotifyCallback(unsigned long,void *);
	static void RecalcTsAudioProtocol(unsigned long,unsigned int *,unsigned long *);
	unsigned long OnCMEvent(HCMNOTIFICATION__ *,_CM_NOTIFY_ACTION,_CM_NOTIFY_EVENT_DATA *,unsigned long);
	void GenerateNotificationSequenceAll(IMMDeviceEnumerator *,unsigned int,unsigned long,int);
	void OnAsyncNotification();
	void OnSubEnumeratorChange(IMMDeviceEnumerator *,unsigned int,unsigned long);
	void UnregisterInternalCallbacks();
protected:
	CDeviceEnumerator();
	~CDeviceEnumerator();
public:
	long FinalConstruct();
	long RefreshDeviceList(_GUID const &,int);
	static long ParseDeviceId(unsigned short const *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0002 *,EDeviceCategory *,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 *,unsigned long *,unsigned short const * *);
	static long UpdateRegistry(int);
	virtual IUnknown * GetControllingUnknown();
	virtual long EnumAudioEndpoints(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,unsigned long,IMMDeviceCollection * *);
	virtual long EnumDeviceInterfaces(_GUID const &,IMMDeviceCollection * *);
	virtual long EnumDeviceInterfaces2(unsigned long,_GUID const &,IMMDeviceCollection * *);
	virtual long EnumDevnodes(_GUID const &,IMMDeviceCollection * *);
	virtual long GetDefaultAudioEndpoint(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0002,IMMDevice * *);
	virtual long GetDefaultAudioEndpointForPolicy(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,IMMDevice * *);
	virtual long GetDevice(unsigned short const *,IMMDevice * *);
	virtual long GetDeviceInterfaceFromPnpId(unsigned short const *,IPnpInterface * *);
	virtual long GetDevnodeFromDeviceInstanceId(unsigned short const *,IPnpDevnode * *);
	virtual long OnDefaultDeviceChanged(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0002,unsigned short const *);
	virtual long OnDefaultDeviceChangedForPolicy(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,unsigned short const *);
	virtual long OnDeviceAdded(unsigned short const *);
	virtual long OnDeviceRemoved(unsigned short const *);
	virtual long OnDeviceStateChanged(unsigned short const *,unsigned long);
	virtual long OnMediaNotification(MEDIA_NOTIFICATION_BLOCK *);
	virtual long OnPropertyValueChanged(unsigned short const *,_tagpropertykey);
	virtual long RegisterEndpointNotificationCallback(IMMNotificationClient *);
	virtual long RegisterInternalEndpointNotificationCallback(IMMNotificationClientInternal *);
	virtual long RegisterPnpHandleNotificationCallback(unsigned short const *,IPnpNotificationClient *);
	virtual long UnregisterEndpointNotificationCallback(IMMNotificationClient *);
	virtual long UnregisterInternalEndpointNotificationCallback(IMMNotificationClientInternal *);
	virtual long UnregisterPnpHandleNotificationCallback(unsigned short const *,IPnpNotificationClient *);
	void FinalRelease();
};

struct CDeviceSpecificProperty
{
	CDeviceSpecificProperty(IControlChangeDelegate *,unsigned long);
	virtual IUnknown * GetIUnknown();
	virtual long DecodeActivationParameter(tagPROPVARIANT const *);
	virtual long Get4BRange(long *,long *,long *);
	virtual long GetType(unsigned short *);
	virtual long GetValue(void *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetValue(void *,unsigned long,_GUID const *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CDeviceTopology
{
	virtual long GetRemoteConnector(CConnection *,IConnector * *);
	virtual long GetRemoteConnector(unsigned short const *,IConnector * *);
	virtual long GetSignalPathRecurse(CPart *,CPart *,__MIDL___MIDL_itf_devicetopology_0000_0000_0011,CPartsList *,int);
	virtual long LoadRWConnections();
	virtual long PersistRWConnections();
	virtual long ResetRWConnections();
protected:
	virtual ~CDeviceTopology();
public:
	CConnection * GetConnectionWithConnector(CConnector *);
	CDeviceTopology(IMMDevice *,unsigned short *);
	virtual int IsPresent();
	virtual long CreateRWConnection(CConnector *,IConnector *);
	virtual long DisconnectConnector(CConnector *);
	virtual long EnumPartsLinked(CPart *,IPartsList * *,Direction);
	virtual long FindPart(unsigned int,CPart * *);
	virtual long GetConnectedConnector(CConnector *,IConnector * *);
	virtual long GetConnection(unsigned int,IConnection * *);
	virtual long GetConnectionCount(unsigned int *);
	virtual long GetConnector(unsigned int,IConnector * *);
	virtual long GetConnectorCount(unsigned int *);
	virtual long GetDeviceId(unsigned short * *);
	virtual long GetLink(unsigned int,ILink * *);
	virtual long GetLinkCount(unsigned int *);
	virtual long GetPartById(unsigned int,IPart * *);
	virtual long GetRefCount(unsigned long *);
	virtual long GetSignalPath(IPart *,IPart *,int,IPartsList * *);
	virtual long GetSubunit(unsigned int,ISubunit * *);
	virtual long GetSubunitCount(unsigned int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CEndpointDevice
{
	long GetDeviceInterfaceIdFromPropertyStore(unsigned short * *);
	long GetDeviceInterfaceIdUsingDevquery(unsigned short * *);
public:
	CEndpointDevice(IMMDevice *,unsigned int,unsigned long);
	static long LookupActivator(_GUID const &,_GUID *,unsigned short const * *,long (**)(IMMDeviceActivator * *));
	virtual __MIDL___MIDL_itf_mmdeviceapip_0000_0000_0002 GetClass();
	virtual long Activate(_GUID const &,unsigned long,tagPROPVARIANT *,void * *);
	virtual long DeleteRegValue(unsigned short const *);
	virtual long GetActivatingThreadId(unsigned long *);
	virtual long GetDataFlow(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 *);
	virtual long GetDeviceInterfacePath(unsigned short * *);
	virtual long GetId(unsigned short * *);
	virtual long GetInternalState(unsigned long *);
	virtual long GetIsDefault(int *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001 *);
	virtual long GetLocalId(unsigned short * *);
	virtual long GetProtocol(unsigned int *);
	virtual long GetRank(__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,unsigned int *);
	virtual long GetState(unsigned long *);
	virtual long IsEnabled(int *);
	virtual long IsHardwareAudioEngineEnabled(int *);
	virtual long OpenFXPropertyStore(unsigned long,IPropertyStore * *);
	virtual long OpenPropertyStore(unsigned long,IPropertyStore * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long QueryRegValue(unsigned short const *,unsigned long,unsigned char *,unsigned long *);
	virtual long SetActivatingThreadId(unsigned long);
	virtual long SetIsDefault(__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001);
	virtual long SetRegValue(unsigned short const *,unsigned long,unsigned char const *,unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CEndpointManager
{
	long MarkEndpointCreatingState(IMMDevice *,int);
protected:
	~CEndpointManager();
public:
	static long GetEndpointDefaultPolicy(IMMDeviceEnumeratorInternal *,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,unsigned short * *,unsigned int);
	static long SetEndpointInternalState(IMMDevice *,unsigned long,unsigned long,int);
	static long UpdateRegistry(int);
	virtual IUnknown * GetControllingUnknown();
	virtual long BeginAudioEndpointCreation(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,int,IMMDevice * *);
	virtual long BreakDeviceConnection(IMMDevice *);
	virtual long EnableEndpoint(IMMDevice *,int);
	virtual long EndAudioEndpointCreation(IMMDevice *);
	virtual long GetRankFromHeuristics(HKEY__ *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,_tagRANK_HEURISTICS_PARAM_VARIANT *,unsigned int *);
	virtual long IsPrerelease(int *);
	virtual long MarkEndpointMigrationState(IMMDevice *,int);
	virtual long PublishLocalEndpointChange(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,unsigned short const *,unsigned int);
	virtual long RemoveEndpoint(IMMDevice *);
	virtual long SendNotifyDefaultDeviceChanged(IMMDevice *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,unsigned int);
	virtual long SetDefaultEndpoint(unsigned short const *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001);
	virtual long SetEndpointState(IMMDevice *,unsigned long);
};

struct CEndpointNotificationBranch
{
	CEndpointNotificationBranch(unsigned short const *,long &);
	long AddNotificationClient(IPnpNotificationClient *);
};

class CEndpointPropertyStore
{
	long GetFriendlyName(tagPROPVARIANT *);
	long GetGuid(tagPROPVARIANT *);
	long GetUniqueAdapterName(tagPROPVARIANT *);
public:
	virtual long GetAt(unsigned long,_tagpropertykey *);
	virtual long GetCount(unsigned long *);
	virtual long GetValue(_tagpropertykey const &,tagPROPVARIANT *);
	virtual long SetValue(_tagpropertykey const &,tagPROPVARIANT const &);
};

struct CEndpointTopologyActivator
{
	virtual long BuildFromMMDevice(IMMDevice *,CDeviceTopology * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CEndpointUtility
{
	long FindNearestPartWithInterface(IPartsList *,unsigned int,_GUID const &,IPart * *,unsigned int *);
	long FindNearestPartWithSubtype(IPartsList *,_GUID const &,IPart * *,unsigned int *);
	long IsAudioEngineSubunit(IPart *,int *);
	long MuteAllUpstreamParts(IPart *,IPart *);
	long Search(IPart *,__MIDL___MIDL_itf_devicetopology_0000_0000_0011,IExaminer *,CPartsList *,unsigned int,int,int,_GUID *,unsigned long);
	long SearchForAudioEngineUnit(IConnector *,ISubunit * *);
	long UnblockCaptureSignalPath(IPartsList *);
	long UnblockRenderSignalPath(IPartsList *);
public:
	virtual long ActivateHardwareAudioEngineControl(IHardwareAudioEngineControl * *);
	virtual long FindHostConnector(KSDATAFORMAT *,unsigned long,int,IPartsList * *);
	virtual long FindHostConnector2(KSDATAFORMAT *,unsigned long,int,int,IPartsList * *);
	virtual long FindHostConnector3(KSDATAFORMAT *,unsigned long,int,int,_GUID *,unsigned long,IPartsList * *);
	virtual long FindKeywordConnector(KSDATAFORMAT *,unsigned long,int,IPartsList * *);
	virtual long FindNearestPartWithInterface(IPartsList *,_GUID const &,IPart * *);
	virtual long FindNearestPartWithSubtype(IPartsList *,_GUID const &,IPart * *);
	virtual long FindPartWithInterfaceAndSubtype(IPartsList *,_GUID const *,_GUID const &,IPart * *);
	virtual long GetHostConnectorDeviceCollection(KSDATAFORMAT *,unsigned long,int,IMMDeviceCollection * *);
	virtual long GetHostConnectorDeviceCollection2(KSDATAFORMAT *,unsigned long,int,__MIDL___MIDL_itf_audioengineendpoint_0000_0000_0001,IMMDeviceCollection * *,unsigned int *,unsigned int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long UnblockSignalPath(IPartsList *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CFormatExaminer
{
	CFormatExaminer(KSDATAFORMAT *,unsigned long);
	virtual int IsSatisfied();
	virtual long Examine(IPartsList *);
	virtual long ExaminePart(IPart *);
};

class CHardwareAudioEngineControl
{
	long GetEngineFormatUtility(unsigned long,KSDATAFORMAT * *);
public:
	CHardwareAudioEngineControl(IControlChangeDelegate *,unsigned long);
	virtual IUnknown * GetIUnknown();
	virtual long GetBufferSizeLimits(KSDATAFORMAT *,__int64 *,__int64 *);
	virtual long GetEngineConnectorIDs(unsigned int *,unsigned int *,unsigned int *);
	virtual long GetEngineDeviceFormat(KSDATAFORMAT * *);
	virtual long GetEngineMixFormat(KSDATAFORMAT * *);
	virtual long GetGlobalEffectsState(int *);
	virtual long GetPartLocalId(unsigned int *);
	virtual long GetSupportedDeviceFormats(KSMULTIPLE_ITEM * *);
	virtual long GetTopologyDeviceId(unsigned short * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetEngineDeviceFormat(KSDATAFORMAT *);
	virtual long SetGlobalEffectsState(int);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CHardwareEventItem
{
protected:
	virtual ~CHardwareEventItem();
public:
	static long m_cInstances;
	static void EventSignalCallback(void *,unsigned char);
	virtual long OnDefaultDeviceChanged(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0002,unsigned short const *);
	virtual long OnDeviceAdded(unsigned short const *);
	virtual long OnDeviceRemoved(unsigned short const *);
	virtual long OnDeviceStateChanged(unsigned short const *,unsigned long);
	virtual long OnPropertyValueChanged(unsigned short const *,_tagpropertykey);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void StartWatchingHwEvent();
	void StopWatchingHwEvent();
};

struct CJackContainerId
{
	virtual long GetJackContainerId(_GUID *);
	virtual long Initialize(IPart *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CJackDescription
{
	virtual long GetJackCount(unsigned int *);
	virtual long GetJackDescription(unsigned int,KSJACK_DESCRIPTION *);
	virtual long Initialize(IPart *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CJackDescription2
{
	virtual long GetJackCount(unsigned int *);
	virtual long GetJackDescription2(unsigned int,_tagKSJACK_DESCRIPTION2 *);
	virtual long Initialize(IPart *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CJackSinkInformation
{
	virtual long GetJackSinkInformation(_tagKSJACK_SINK_INFORMATION *);
	virtual long Initialize(IPart *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CKeywordFormatExaminer
{
protected:
	virtual long ExaminePart(IPart *);
};

struct CKsConnector
{
	virtual long InitializeHardwareEventSupport();
	virtual long UninitializeHardwareEventSupport();
};

class CKsDeviceTopology
{
	long ValidateEventCombination(int,_GUID,unsigned long);
	virtual ~CKsDeviceTopology();
public:
	CKsDeviceTopology(IMMDevice *,unsigned short *);
	long DisableHardwareEvent(KSEVENTDATA *);
	long EnableHardwareEvent(unsigned int,_GUID,unsigned long,KSEVENTDATA *);
	long GetHardwareEventSupport(unsigned int,_GUID,unsigned long);
	long GetNodePropertyDesc(_GUID const &,unsigned long,unsigned long,KSPROPERTY_DESCRIPTION * *);
	long GetNodePropertySimple(unsigned long,_GUID const &,unsigned long,void *,unsigned long);
	long GetPropertyMulti(_GUID const &,unsigned long,KSMULTIPLE_ITEM * *);
	long GetPropertyMulti(unsigned long,_GUID const &,unsigned long,KSMULTIPLE_ITEM * *);
	long GetPropertySimple(unsigned long,_GUID const &,unsigned long,void *,unsigned long);
	long GetPropertySizeUnknown(unsigned long,_GUID const &,unsigned long,void * *,unsigned long *);
	long HrIoctl(unsigned long,void *,unsigned long,void *,unsigned long,unsigned long *);
	long Initialize();
	long OnDeviceAdded(unsigned short const *);
	long OnDeviceQueryRemove();
	long OnDeviceQueryRemoveFailed();
	long OnDeviceRemovePending();
	long OnDeviceRemoved(unsigned short const *);
	virtual int IsPresent();
};

struct CKsDeviceTopologyNotificationWrapper
{
	virtual long OnDefaultDeviceChanged(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0002,unsigned short const *);
	virtual long OnDeviceAdded(unsigned short const *);
	virtual long OnDeviceQueryRemove();
	virtual long OnDeviceQueryRemoveFailed();
	virtual long OnDeviceRemovePending();
	virtual long OnDeviceRemoved(unsigned short const *);
	virtual long OnDeviceStateChanged(unsigned short const *,unsigned long);
	virtual long OnPropertyValueChanged(unsigned short const *,_tagpropertykey);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CKsFilterProperty
{
	~CKsFilterProperty();
public:
	CKsFilterProperty(IMMDevice *);
	long Initialize();
	virtual long GetKsComponentId(KSCOMPONENTID *);
	virtual long KsEvent(KSIDENTIFIER *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long KsMethod(KSIDENTIFIER *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long KsProperty(KSIDENTIFIER *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long OnDefaultDeviceChanged(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0002,unsigned short const *);
	virtual long OnDeviceAdded(unsigned short const *);
	virtual long OnDeviceQueryRemove();
	virtual long OnDeviceQueryRemoveFailed();
	virtual long OnDeviceRemovePending();
	virtual long OnDeviceRemoved(unsigned short const *);
	virtual long OnDeviceStateChanged(unsigned short const *,unsigned long);
	virtual long OnPropertyValueChanged(unsigned short const *,_tagpropertykey);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CKsHardwareEventItem
{
	virtual ~CKsHardwareEventItem();
public:
	CKsHardwareEventItem(CKsDeviceTopology *);
	long Initialize(CPart *);
};

struct CKsPartActivator
{
	static long ActivateControl(IPart *,IControlChangeDelegate *,_GUID const &,tagPROPVARIANT const *,void * *);
};

class CKsPinInfoProperty
{
protected:
	virtual ~CKsPinInfoProperty();
public:
	virtual long Initialize(IPart *);
};

struct CKsSubunit
{
	virtual long InitializeHardwareEventSupport();
	virtual long UninitializeHardwareEventSupport();
};

class CKsTopologyActivator
{
	long BuildControlInterfaceList(_GUID const &,unsigned long,CSubunit *);
	long CreateConnection(CConnector *,KSPIN_PHYSICALCONNECTION *);
	long CreateConnector(unsigned long);
	long CreateControlInterface(_GUID const &,unsigned long,CPart *,KSPROPERTY_DESCRIPTION * *);
	long CreateLinks();
	long CreateSelectionArray(unsigned long,_GUID const &,unsigned int * *,unsigned int *);
	long CreateSelectionTable(unsigned long,_GUID const &,CControlInterface *);
	long CreateSubunit(unsigned long,_GUID const &);
	long CreateSubunits();
	long CursoryPropertyTest(unsigned long,unsigned long,int,unsigned long);
	long ParseKsTopology();
public:
	virtual long BuildFromMMDevice(IMMDevice *,CDeviceTopology * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CLink
{
	virtual long GetPartFrom(IPart * *);
	virtual long GetPartTo(IPart * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CLocalEndpointDevice
{
	CLocalEndpointDevice(unsigned short const *,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001);
	virtual __MIDL___MIDL_itf_mmdeviceapip_0000_0000_0002 GetClass();
	virtual long DeleteRegValue(unsigned short const *);
	virtual long GetActivatingThreadId(unsigned long *);
	virtual long GetDeviceInterfacePath(unsigned short * *);
	virtual long GetInternalState(unsigned long *);
	virtual long GetIsDefault(int *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001 *);
	virtual long GetLocalId(unsigned short * *);
	virtual long GetProtocol(unsigned int *);
	virtual long GetRank(__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,unsigned int *);
	virtual long IsEnabled(int *);
	virtual long IsHardwareAudioEngineEnabled(int *);
	virtual long OpenFXPropertyStore(unsigned long,IPropertyStore * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long QueryRegValue(unsigned short const *,unsigned long,unsigned char *,unsigned long *);
	virtual long SetActivatingThreadId(unsigned long);
	virtual long SetRegValue(unsigned short const *,unsigned long,unsigned char const *,unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CLocalEndpointEnumerator
{
	int NotifiedSessionIsValid(unsigned short const *);
	virtual long EnumCEndpoints(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,unsigned long,CDeviceCollection<CSubEndpointDevice> *);
	virtual long EnumCEndpointsAllocCollection(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,unsigned long,CDeviceCollection<CSubEndpointDevice> * *);
public:
	virtual long EnumAudioEndpoints(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,unsigned long,IMMDeviceCollection * *);
	virtual long GetDefaultAudioEndpoint(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0002,IMMDevice * *);
	virtual long GetDefaultAudioEndpointForPolicy(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,IMMDevice * *);
	virtual long GetDevice(unsigned short const *,IMMDevice * *);
	virtual long OnMediaNotification(MEDIA_NOTIFICATION_BLOCK *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RegisterEndpointNotificationCallback(IMMNotificationClient *);
	virtual long RegisterInternalEndpointNotificationCallback(IMMNotificationClientInternal *);
	virtual long UnregisterEndpointNotificationCallback(IMMNotificationClient *);
	virtual long UnregisterInternalEndpointNotificationCallback(IMMNotificationClientInternal *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CMMDeviceModule
{
	CMMDeviceModule();
	static long UpdateRegistryAppId(int);
	virtual ~CMMDeviceModule();
};

class CMediaNotifications
{
	~CMediaNotifications();
public:
	CMediaNotifications();
	long Initialize();
	long RegisterForMediaCallback(unsigned long,IMediaNotificationCallback *);
	long UnregisterMediaCallback(IMediaNotificationCallback *);
	static long GenerateMediaEvent(MEDIA_NOTIFICATION_BLOCK *,unsigned long);
	static unsigned long MediaNotification(_ETW_NOTIFICATION_HEADER *,void *);
	static void MediaNotificationWorkerHandler(_TP_CALLBACK_INSTANCE *,void *);
	unsigned long OnMediaNotification(void *);
	void CleanupMediaNotifications();
	void OnMediaNotificationWorkerHandler(_TP_CALLBACK_INSTANCE *);
	void Release();
};

class CMidiPortDeviceIoControl
{
	long BindToDeviceInterfacePath(unsigned short const *,unsigned long);
	long RegisterForDeviceRemoval(void *);
	long RevokeDeviceAccess();
	long SetupMidiPortHandleRevocation(void *);
	long Start();
	static unsigned long CMEventCallback(HCMNOTIFICATION__ *,void *,_CM_NOTIFY_ACTION,_CM_NOTIFY_EVENT_DATA *,unsigned long);
	static void AppStateChangeNotificationCallback(unsigned char,void *);
	static void DesktopAppStateChangeNotificationCallback(void *,unsigned long,void *);
	static void DeviceAccessBindCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_WORK *);
	void ChangeState(CMidiPortDeviceIoControl::AsyncState);
public:
	CMidiPortDeviceIoControl();
	long RuntimeClassInitialize(unsigned short const *,unsigned long);
	virtual IUnknown * GetControllingUnknown();
	virtual long Cancel();
	virtual long CancelOperation(unsigned __int64);
	virtual long Close();
	virtual long DeviceIoControlAsync(unsigned long,unsigned char *,unsigned long,unsigned char *,unsigned long,IDeviceRequestCompletionCallback *,unsigned __int64 *);
	virtual long DeviceIoControlSync(unsigned long,unsigned char *,unsigned long,unsigned char *,unsigned long,unsigned long *);
	virtual long GetResult(_GUID const &,void * *);
	virtual long Wait(unsigned long);
	~CMidiPortDeviceIoControl();
};

struct CNotificationClient
{
	long Release();
};

struct CNotificationDelegator
{
	CNotificationDelegator();
	long AddHardwareEventItem(CHardwareEventItem *);
	long RemoveHardwareEventItem(CHardwareEventItem *);
	static long m_cInstances;
	virtual long GenerateNotificationEvent(unsigned short const *,_GUID const &,_GUID const *);
	virtual long OnMediaNotification(MEDIA_NOTIFICATION_BLOCK *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RegisterNotificationSink(CPart *);
	virtual long UnregisterNotificationSink(CPart *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void MakeInProcNotifications(unsigned short const *,unsigned __int64,_GUID const &,unsigned __int64,_GUID const *);
};

class CPart
{
protected:
	virtual long InitializeHardwareEventSupport();
	virtual long UninitializeHardwareEventSupport();
	virtual ~CPart();
public:
	CPart(CDeviceTopology *,unsigned long);
	unsigned short const * GetGlobalIdPtr();
	virtual long Activate(unsigned long,_GUID const &,void * *);
	virtual long EnumPartsIncoming(IPartsList * *);
	virtual long EnumPartsOutgoing(IPartsList * *);
	virtual long GetControlInterface(unsigned int,IControlInterface * *);
	virtual long GetControlInterfaceCount(unsigned int *);
	virtual long GetGlobalId(unsigned short * *);
	virtual long GetLocalId(unsigned int *);
	virtual long GetName(unsigned short * *);
	virtual long GetPartType(__MIDL___MIDL_itf_devicetopology_0000_0000_0012 *);
	virtual long GetSubType(_GUID *);
	virtual long GetTopologyObject(IDeviceTopology * *);
	virtual long RegisterControlChangeCallback(_GUID const &,IControlChangeNotify *);
	virtual long UnregisterControlChangeCallback(IControlChangeNotify *);
	void NotifyClients(_GUID const *,unsigned __int64,_GUID const *);
};

struct CPartsList
{
	CPartsList();
	virtual long AddPart(IPart *);
	virtual long AddParts(IPartsList *);
	virtual long GetCount(unsigned int *);
	virtual long GetPart(unsigned int,IPart * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CPerChannelDbLevel
{
protected:
	virtual long GetChannelCount(unsigned int *);
	virtual long GetLevel(unsigned int,float *);
	virtual long GetLevelRange(unsigned int,float *,float *,float *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetLevel(unsigned int,float,_GUID const *);
	virtual long SetLevelAllChannels(float * const,unsigned long,_GUID const *);
	virtual long SetLevelUniform(float,_GUID const *);
};

class CPnpDevNode
{
	~CPnpDevNode();
public:
	CPnpDevNode(IUnknown *,unsigned short const *,CDeviceEnumerator *,_DO_DEVINFO_DATA *);
	CPnpInterface * FindPnpInterface(unsigned short const *,_GUID const *);
	CPnpInterfaceCollection * GetInterfaceList(_GUID const &,int);
	virtual long Activate(_GUID const &,unsigned long,tagPROPVARIANT *,void * *);
	virtual long EnumDeviceInterfaces(_GUID const &,CPnpInterfaceCollection *);
	virtual long EnumDeviceInterfaces(_GUID const &,IMMDeviceCollection * *);
	virtual long GetId(unsigned short * *);
	virtual long GetInstanceId(unsigned short * *);
	virtual long GetState(unsigned long *);
	virtual long OpenPropertyStore(unsigned long,IPropertyStore * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Refresh(_GUID const &);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CPnpDevNodeCollection
{
	~CPnpDevNodeCollection();
public:
	CPnpDevNode * FindPnpDevNode(unsigned short const *);
	CPnpDevNodeCollection(IUnknown *);
	CPnpInterface * FindPnpInterface(unsigned short const *,_GUID const *);
	virtual long AddOrRefresh(unsigned short const *,CDeviceEnumerator *,_DO_DEVINFO_DATA *,_GUID const *);
	virtual long EnumDeviceInterfaces(_GUID const &,CPnpInterfaceCollection *);
	virtual long EnumDevnodes(_GUID const &,CPnpDevNodeCollection *);
	virtual long GetCount(unsigned int *);
	virtual long Item(unsigned int,IMMDevice * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void RefreshEnd(_GUID const &);
	void RefreshStart(_GUID const &);
};

struct CPnpDevNodePropertyStore
{
	virtual long Commit();
	virtual long GetAt(unsigned long,_tagpropertykey *);
	virtual long GetCount(unsigned long *);
	virtual long GetValue(_tagpropertykey const &,tagPROPVARIANT *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetValue(_tagpropertykey const &,tagPROPVARIANT const &);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CPnpInterface
{
	long LookupCLSID(_GUID const &,_GUID *);
	long OpenEndpointPropertyStoreInternal(unsigned int,unsigned long,int,IPropertyStore * *);
	long OpenFXPropertyStoreInternal(unsigned int,unsigned long,int,IPropertyStore * *);
	long OpenIndexedPropertyStore(unsigned short const *,unsigned long,IPropertyStore * *);
public:
	CPnpInterface(IUnknown *,unsigned short const *,void *,_DO_DEVICE_INTERFACE_DATA *,CPnpDevNode *);
	virtual long Activate(_GUID const &,unsigned long,tagPROPVARIANT *,void * *);
	virtual long GetDeviceInterfaceDataFlags(unsigned long *);
	virtual long GetDevicePath(unsigned short * *);
	virtual long GetDevnode(IPnpDevnode * *);
	virtual long GetId(unsigned short * *);
	virtual long GetInterfaceAlias(_GUID const &,IPnpInterface * *);
	virtual long GetState(unsigned long *);
	virtual long OpenDeviceInterfaceRegKey(unsigned long,HKEY__ * *);
	virtual long OpenEndpointPropertyStore(unsigned int,unsigned long,IPropertyStore * *);
	virtual long OpenFXPropertyStore(unsigned int,unsigned long,IPropertyStore * *);
	virtual long OpenMsEndpointPropertyStore(unsigned int,unsigned long,IPropertyStore * *);
	virtual long OpenMsFXPropertyStore(unsigned int,unsigned long,IPropertyStore * *);
	virtual long OpenPropertyStore(unsigned long,IPropertyStore * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CPnpInterfaceCollection
{
	~CPnpInterfaceCollection();
public:
	CPnpInterface * FindPnpInterface(unsigned short const *);
	CPnpInterfaceCollection(IUnknown *,_GUID const &);
	virtual long AddOrRefresh(unsigned short const *,void *,_DO_DEVICE_INTERFACE_DATA *,CPnpDevNode *);
	virtual long EnumInterfaces(_GUID const &,CPnpInterfaceCollection *);
	virtual long GetCount(unsigned int *);
	virtual long Item(unsigned int,IMMDevice * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void RefreshEnd();
	void RefreshStart();
};

struct CPnpInterfacePropertyStore
{
	virtual long Commit();
	virtual long GetAt(unsigned long,_tagpropertykey *);
	virtual long GetCount(unsigned long *);
	virtual long GetValue(_tagpropertykey const &,tagPROPVARIANT *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetValue(_tagpropertykey const &,tagPROPVARIANT const &);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CProperty
{
protected:
	static long m_refCountAll;
	virtual ~CProperty();
public:
	CProperty(IControlChangeDelegate *,unsigned int);
	long Base_QueryInterface(_GUID const &,void * *);
	long Get(void *,unsigned long,unsigned long *);
	long Initialize(IPart *,tagPROPVARIANT const *);
	long Set(void *,unsigned long,_GUID const *,int);
	unsigned long Base_Release();
	virtual long DecodeActivationParameter(tagPROPVARIANT const *);
};

class CRegistryPropertyStore
{
protected:
	long SetValue_Internal(_tagpropertykey const &,tagPROPVARIANT const &,NotificationPolicy);
	virtual long OpenPropertyStoreRegKey();
	virtual void ClosePropertyStoreRegKey();
	virtual ~CRegistryPropertyStore();
public:
	CRegistryPropertyStore(unsigned short const *,unsigned long,unsigned short const *);
	virtual long Commit();
	virtual long GetAt(unsigned long,_tagpropertykey *);
	virtual long GetCount(unsigned long *);
	virtual long GetValue(_tagpropertykey const &,tagPROPVARIANT *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetValue(_tagpropertykey const &,tagPROPVARIANT const &);
	virtual long SetValue_NoRedundantNotifications(_tagpropertykey const &,tagPROPVARIANT const &);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CSelectionProperty
{
protected:
	virtual long DecodeActivationParameter(tagPROPVARIANT const *);
	virtual long GetPartIdFromValue(unsigned int,unsigned int *);
	virtual long GetValueFromPartId(unsigned int,unsigned int *);
public:
	virtual ~CSelectionProperty();
};

struct CSimpleActivator
{
	virtual long Activate(_GUID const &,IMMDevice *,tagPROPVARIANT *,void * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CSubEndpointDevice
{
protected:
	long OpenXPropertyStore(int,unsigned long,IPropertyStore * *);
public:
	CSubEndpointDevice(unsigned short const *,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,unsigned int,unsigned long);
	static long DeleteRegValue(unsigned short const *,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,unsigned short const *);
	static long QueryRegValue(unsigned short const *,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,unsigned short const *,unsigned long,unsigned char *,unsigned long *);
	static long SetRegValue(unsigned short const *,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,unsigned short const *,unsigned long,unsigned char const *,unsigned long);
	virtual long Activate(_GUID const &,unsigned long,tagPROPVARIANT *,void * *);
	virtual long DeleteRegValue(unsigned short const *);
	virtual long GetDataFlow(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 *);
	virtual long GetId(unsigned short * *);
	virtual long GetState(unsigned long *);
	virtual long OpenPropertyStore(unsigned long,IPropertyStore * *);
	virtual long QueryRegValue(unsigned short const *,unsigned long,unsigned char *,unsigned long *);
	virtual long SetRegValue(unsigned short const *,unsigned long,unsigned char const *,unsigned long);
};

struct CSubunit
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CTCoAllocPolicy
{
	static unsigned __int64 _CoTaskMemSize(void *);
public:
	static long Alloc(void *,unsigned long,unsigned __int64,void * *);
};

struct CTSDeviceWrapper
{
	CTSDeviceWrapper(IMMDevice *,CTSEnumeratorDll *);
	virtual long Activate(_GUID const &,unsigned long,tagPROPVARIANT *,void * *);
	virtual long GetDataFlow(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001 *);
	virtual long GetId(unsigned short * *);
	virtual long GetState(unsigned long *);
	virtual long OpenPropertyStore(unsigned long,IPropertyStore * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~CTSDeviceWrapper();
};

struct CTSEndpointDeviceCollection
{
	CTSEndpointDeviceCollection();
	virtual long Add(IMMDevice *);
	virtual long GetCount(unsigned int *);
	virtual long Item(unsigned int,IMMDevice * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~CTSEndpointDeviceCollection();
};

struct CTSEnumRefCount
{
	virtual ~CTSEnumRefCount();
};

class CTSEnumeratorDll
{
	long Initialize(unsigned short const *);
public:
	static long CreateInstance(unsigned short const *,CTSEnumeratorDll * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CTSEnumeratorWrapper
{
	long Initialize(CTSEnumeratorDll *,unsigned long);
public:
	static long CreateInstance(CTSEnumeratorDll *,unsigned long,IMMDeviceEnumerator * *);
	virtual long EnumAudioEndpoints(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,unsigned long,IMMDeviceCollection * *);
	virtual long GetDefaultAudioEndpoint(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0002,IMMDevice * *);
	virtual long GetDevice(unsigned short const *,IMMDevice * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RegisterEndpointNotificationCallback(IMMNotificationClient *);
	virtual long UnregisterEndpointNotificationCallback(IMMNotificationClient *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~CTSEnumeratorWrapper();
};

struct CTSPropertyStoreWrapper
{
	CTSPropertyStoreWrapper(IPropertyStore *,CTSEnumeratorDll *);
	virtual long Commit();
	virtual long GetAt(unsigned long,_tagpropertykey *);
	virtual long GetCount(unsigned long *);
	virtual long GetValue(_tagpropertykey const &,tagPROPVARIANT *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetValue(_tagpropertykey const &,tagPROPVARIANT const &);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~CTSPropertyStoreWrapper();
};

class CTopologyCache
{
	int LockDeviceAPIDLL();
public:
	int CanUnloadNow();
	int CreateTimerQueue();
	long Add(CDeviceTopology *,unsigned short *);
	long FindTopologyObjectForDevice(unsigned short *,CDeviceTopology * *);
	long RemoveObjectsFromCacheList();
	static ATL::CCriticalSection * m_pCritSec;
	static void OnDisposalTimer(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *);
};

struct SPINLOCK
{
	void Acquire();
};

struct TList<CConnection>
{
	int GetAt(long,CConnection * *);
	int GetNext(void * &,CConnection * *);
	void * AddTail(CConnection *);
	~TList<CConnection>();
};

struct TList<CConnector>
{
	int GetAt(long,CConnector * *);
	void * AddTail(CConnector *);
	~TList<CConnector>();
};

struct TList<CControlInterface>
{
	int GetAt(long,CControlInterface * *);
	int GetNext(void * &,CControlInterface * *);
	void * AddTail(CControlInterface *);
	~TList<CControlInterface>();
};

struct TList<CControlProvider>
{
	~TList<CControlProvider>();
};

struct TList<CEndpointNotificationBranch>
{
	int GetNext(void * &,CEndpointNotificationBranch * *);
	void * AddTail(CEndpointNotificationBranch *);
	~TList<CEndpointNotificationBranch>();
};

struct TList<CHardwareEventItem>
{
	~TList<CHardwareEventItem>();
};

struct TList<CLink>
{
	int GetAt(long,CLink * *);
	int GetNext(void * &,CLink * *);
	void * AddTail(CLink *);
	~TList<CLink>();
};

struct TList<CNotificationClient>
{
	int GetNext(void * &,CNotificationClient * *);
	int RemoveHead(CNotificationClient * *);
	void * AddTail(CNotificationClient *);
};

struct TList<CPart>
{
	int GetNext(void * &,CPart * *);
	void * AddTail(CPart *);
	~TList<CPart>();
};

struct TList<CPnpDevNode>
{
	int GetAt(long,CPnpDevNode * *);
	void * AddTail(CPnpDevNode *);
	~TList<CPnpDevNode>();
};

struct TList<CPnpInterface>
{
	int GetAt(long,CPnpInterface * *);
	void * AddTail(CPnpInterface *);
	~TList<CPnpInterface>();
};

struct TList<CPnpInterfaceCollection>
{
	int GetAt(long,CPnpInterfaceCollection * *);
	~TList<CPnpInterfaceCollection>();
};

struct TList<CSubunit>
{
	int GetAt(long,CSubunit * *);
	int GetNext(void * &,CSubunit * *);
	void * AddTail(CSubunit *);
	~TList<CSubunit>();
};

struct TList<CacheItem>
{
	int GetNext(void * &,CacheItem * *);
	int RemoveHead(CacheItem * *);
	int RemoveTail(CacheItem * *);
	void * AddTail(CacheItem *);
};

struct TList<IConnector>
{
	int GetNext(void * &,IConnector * *);
	int RemoveHead(IConnector * *);
	void * AddTail(IConnector *);
};

struct TList<IMMDevice>
{
	int GetAt(long,IMMDevice * *);
};

struct TList<IMMNotificationClientInternal>
{
	void * AddTail(IMMNotificationClientInternal *);
};

struct TList<IPart>
{
	void * AddTail(IPart *);
	~TList<IPart>();
};

struct exception
{
	exception(exception const &);
};

namespace wil
{
	struct ResultException
	{
		ResultException(ResultException const &);
		virtual char const * what();
		virtual ~ResultException();
	};

	struct StoredFailureInfo
	{
		void SetFailureInfo(FailureInfo const &);
	};

	namespace details
	{
		class ThreadFailureCallbackHolder
		{
			static long volatile s_telemetryId;
		public:
			static bool GetThreadContext(FailureInfo *,ThreadFailureCallbackHolder *,char *,unsigned __int64);
			static void GetContextAndNotifyFailure(FailureInfo *,char *,unsigned __int64);
		};

		namespace in1diag3
		{
			long Return_GetLastError(void *,unsigned int,char const *);
			void FailFast_Unexpected(void *,unsigned int,char const *);
			void Return_Hr(void *,unsigned int,char const *,long);
			void Return_Hr_NoOriginate(void *,unsigned int,char const *,long);
			void _FailFastImmediate_Unexpected();
			void _FailFast_GetLastError(void *,unsigned int,char const *);
		};

		class shared_buffer
		{
			void assign(long *,unsigned __int64);
		public:
			bool create(void const *,unsigned __int64);
			void reset();
		};

		bool GetModuleInformation(void *,unsigned int *,char *,unsigned __int64);
		bool g_processShutdownInProgress;
		bool g_resultMessageCallbackSet;
		char const * (* g_pfnGetModuleName)();
		char const * GetCurrentModuleName();
		details_abi::ProcessLocalStorage<details_abi::ProcessLocalData> g_processLocalData;
		details_abi::ThreadLocalStorage<details::ThreadFailureCallbackHolder *> * g_pThreadFailureCallbacks;
		details_abi::ThreadLocalStorage<details::ThreadFailureCallbackHolder *> g_threadFailureCallbacks;
		int RecordException(long);
		int RecordFailFast(long);
		int RecordLog(long);
		int RecordReturn(long);
		long GetLastErrorFailHr();
		long ReportFailure_GetLastErrorHr(void *,unsigned int,char const *,char const *,char const *,void *,FailureType);
		long StringCchPrintfA(char *,unsigned __int64,char const *,...);
		unsigned __int64 ResultStringSize(char const *);
		unsigned __int64 ResultStringSize(unsigned short const *);
		unsigned char (* g_pfnRtlDllShutdownInProgress)();
		unsigned char * WriteResultString<char const *>(unsigned char *,unsigned char *,char const *,char const * *);
		unsigned char * WriteResultString<unsigned short const *>(unsigned char *,unsigned char *,unsigned short const *,unsigned short const * *);
		unsigned char RtlDllShutdownInProgress();
		unsigned long GetLastErrorFail(void *,unsigned int,char const *,char const *,char const *,void *);
		unsigned long ReportFailure_GetLastError(void *,unsigned int,char const *,char const *,char const *,void *,FailureType);
		unsigned short * LogStringPrintf(unsigned short *,unsigned short const *,unsigned short const *,...);
		void (* g_pfnDebugBreak)();
		void (* g_pfnGetContextAndNotifyFailure)(FailureInfo *,char *,unsigned __int64);
		void (* g_pfnLoggingCallback)(FailureInfo const &);
		void (* g_pfnOriginateCallback)(FailureType,long);
		void (* g_pfnRethrow)();
		void (* g_pfnTelemetryCallback)(bool,FailureInfo const &);
		void (* g_pfnThrowResultException)(FailureInfo const &);
		void CloseHandle(void *);
		void DebugBreak();
		void FreeProcessHeap(void *);
		void GetContextAndNotifyFailure(FailureInfo *,char *,unsigned __int64);
		void LogFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,unsigned short const *,bool,unsigned short *,unsigned __int64,char *,unsigned __int64,FailureInfo *);
		void ReleaseMutex(void *);
		void ReportFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,unsigned short const *,details::ReportFailureOptions);
		void ReportFailure_Hr(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long);
		void Rethrow();
		void ThrowResultExceptionInternal(FailureInfo const &);
	};

	namespace details_abi
	{
		struct ProcessLocalStorage<ProcessLocalData>
		{
			ProcessLocalData * GetShared();
			~ProcessLocalStorage<ProcessLocalData>();
		};

		struct ProcessLocalStorageData<ProcessLocalData>
		{
			static long Acquire(char const *,ProcessLocalStorageData<ProcessLocalData> * *);
			void Release();
			~ProcessLocalStorageData<ProcessLocalData>();
		};

		class SemaphoreValue
		{
			long CreateFromValueInternal(unsigned short const *,bool,unsigned __int64);
			static long GetValueFromSemaphore(void *,long *);
			static long TryGetValueInternal(unsigned short const *,bool,unsigned __int64 *,bool *);
		};

		struct ThreadLocalData
		{
			void SetLastError(FailureInfo const &);
		};

		struct ThreadLocalFailureInfo
		{
			void Set(FailureInfo const &,unsigned int);
		};

		struct ThreadLocalStorage<details::ThreadFailureCallbackHolder *>
		{
			~ThreadLocalStorage<details::ThreadFailureCallbackHolder *>();
		};

		details_abi::ProcessLocalStorage<details_abi::ProcessLocalData> * g_pProcessLocalData;
		details_abi::ThreadLocalData * GetThreadLocalDataCache(bool);
	};

	bool (* g_pfnIsDebuggerPresent)();
	bool g_fBreakOnFailure;
	bool g_fIsDebuggerPresent;
	long GetFailureLogString(unsigned short *,unsigned __int64,wil::FailureInfo const &);
};

ATL::CAtlArray<FAKE_COM_REGISTRATION,ATL::CElementTraits<FAKE_COM_REGISTRATION> > * rgFakeComRegistration;
ATL::CCriticalSection MediaNotificationLock;
ATL::_ATL_OBJMAP_ENTRY30 __objMap_ActivateAudioInterfaceWorker;
ATL::_ATL_OBJMAP_ENTRY30 __objMap_CDeviceEnumerator;
ATL::_ATL_OBJMAP_ENTRY30 __objMap_CEndpointManager;
CAudioThreadPool * ThreadPool;
CLSID_LOOKUP_ITEM * g_rgCommonEndpointClsidLookup;
CLSID_LOOKUP_ITEM * g_rgLocalEndpointClsidLookup;
CLSID_LOOKUP_ITEM * g_rgPnpInterfaceClsidLookup;
CMMDeviceModule _AtlModule;
CMediaNotifications * MediaNotifications;
CNotificationDelegator * g_pTheNotificationDelegator;
CTopologyCache * g_pTopologyCache;
DPTTOVT_ITEM * _rgDptToVt;
HINSTANCE__ * g_hinstDLL;
HINSTANCE__ * g_wil_details_ntdllModuleHandle;
HINSTANCE__ * wil_details_GetNtDllModuleHandle();
KSPROPERTY_DESCRIPTION * AllocDefaultPropertyDesc();
MMDEVICE_ASYNC_NOTIFICATION_BLOCK * CreateAsyncDeviceNotificationContext(ENotificationType,unsigned short const *,unsigned long);
MMDEVICE_NOTIFICATION_BLOCK * CreateNotificationBlock(unsigned long,unsigned short const *);
PROPMAP_DESCRIPTOR * map_KSPROPERTY_AUDIO;
_GUID * aExternalInputTypes;
_GUID * aExternalOutputTypes;
_RTL_RUN_ONCE g_InitAudiosrvOnce;
_RTL_SRWLOCK critsComRegistration;
_tagpropertykey PKEY_Test;
int AeWmiInitialize(_GUID const *);
int AudiosrvNotificationBlockIsValid(MEDIA_NOTIFICATION_BLOCK *);
int CheckServicePid(unsigned short const *,unsigned __int64);
int CreateDeviceTopologyCache();
int InlineIsEqualGUID(_GUID const &,_GUID const &);
int IsNeverSetAsDefault(IMMDevice *,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001);
int IsPtrType(unsigned long);
int IsValidKSPropertyDescriptor(KSPROPERTY_DESCRIPTION *);
int MediaNotificationsCanUnloadNow();
int MmdeviceNotificationBlockIsValid(MEDIA_NOTIFICATION_BLOCK *);
int NotificationBlockIsValid(unsigned long,MEDIA_NOTIFICATION_BLOCK *);
int g_fEventTracingEnabled;
int g_fInProcessShutdown;
int ocslen(unsigned short const *);
long AllocCoMemCopy(unsigned char *,unsigned __int64,unsigned char * *);
long AllocCoMemString(unsigned short const *,unsigned short * *);
long AppModelPolicy_GetPolicy_Internal(void *,AppModelPolicy_Type,AppModelPolicy_PolicyValue *,_PS_PKG_CLAIM *,unsigned __int64 *);
long AudiosrvBinding(void * *);
long AudiosrvGetDefaultAudioEndpoint(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,unsigned short * *,int *);
long AudiosrvMidiPortKsCreatePin(unsigned short const *,void * *);
long AudiosrvNotifyDefaultDeviceChanged(__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,unsigned short const *);
long AudiosrvNotifyDeviceAdded(unsigned short const *);
long AudiosrvNotifyDeviceRemoved(unsigned short const *);
long AudiosrvNotifyDeviceStateChanged(unsigned short const *,unsigned long);
long AudiosrvTsRegisterAudioProtocolNotification(void * *);
long AudiosrvTsUnregisterAudioProtocolNotification(void * *);
long CleanupMediaNotifications();
long ConvertDevPropTypeToVT(unsigned long,unsigned short *);
long CrackPartGlobalId(unsigned short const *,unsigned __int64,unsigned short * *,unsigned int *);
long CreateDeviceTopologyActivator(IMMDeviceActivator * *);
long CreateEndpointEnumerator(unsigned int,unsigned long,IMMDeviceEnumerator * *);
long CreateEndpointUtilityActivator(IMMDeviceActivator * *);
long DeserializePropVariant(unsigned long,unsigned char *,unsigned __int64,tagPROPVARIANT *);
long EnableHardwareEvent(void *,_GUID const &,unsigned long,unsigned long,int,KSEVENTDATA *);
long EnumeratorInstance(ATL::CComObject<CDeviceEnumerator> * *);
long ExtractExceptionRuleInfo(HKEY__ *,_tagExceptionRule *);
long GetCategoryPath(unsigned short *,unsigned __int64,EDeviceCategory,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001);
long GetConnectorTypeFromPin(PIN_DESCRIPTOR *,__MIDL___MIDL_itf_devicetopology_0000_0000_0013 *);
long GetDeviceInterfaceClassForMmDevice(IMMDevice *,_GUID *);
long GetDeviceInterfaceIdFromMMDevicePropertyStore(IMMDevice *,unsigned short * *);
long GetDeviceInterfaceIdUsingDevQuery(IMMDevice *,unsigned short * *);
long GetDevicePath(unsigned short *,unsigned __int64,unsigned short const *,EDeviceCategory,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001);
long GetEndpointCreationTime(IMMDevice *,_FILETIME *);
long GetEndpointLevel(IMMDevice *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,__int64 *);
long GetEnumeratorDllName(unsigned long,__PROPERTY_VALUE * *);
long GetHardwareEventSupport(void *,_GUID const &,unsigned long,unsigned long,int);
long GetHeuristicData(HKEY__ *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0003,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,_tagRANK_HEURISTICS_PARAM_VARIANT *,_tagHEURISTICDATA *);
long GetIUnknownFromDll(unsigned short const *,_GUID const &,_GUID const &,void * *);
long GetLocalAudioEnumerator(IMMDeviceEnumerator * *);
long GetMediaNotifications(CMediaNotifications * *);
long GetNodePropertyDesc(void *,_GUID const &,unsigned long,unsigned long,KSPROPERTY_DESCRIPTION * *);
long GetNodePropertySimple(void *,unsigned long,_GUID const &,unsigned long,void *,unsigned long);
long GetPinPropertyMulti(void *,unsigned long,_GUID const &,unsigned long,KSMULTIPLE_ITEM * *);
long GetPinPropertySimple(void *,unsigned long,_GUID const &,unsigned long,void *,unsigned long);
long GetPinPropertySizeUnknown(void *,unsigned long,_GUID const &,unsigned long,void * *,unsigned long *);
long GetPropertyMulti(void *,_GUID const &,unsigned long,KSMULTIPLE_ITEM * *);
long GetPropertySimple(void *,_GUID const &,unsigned long,void *,unsigned long);
long GetRankFromExceptionRules(HKEY__ *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,_tagRANK_HEURISTICS_PARAM_VARIANT *,_tagHEURISTICDATA *,int *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0008 *);
long GetRegPathForEndpoint(IMMDevice *,unsigned short *,unsigned __int64);
long GetTargetEntry(__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0003,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,unsigned short *,unsigned long *,unsigned short *,unsigned long *,_tagRANK_HEURISTICS_PARAM_VARIANT *);
long GetTsRemoteAudioEnumerator(unsigned long,void * *);
long GuidRep(_GUID const &,unsigned short *,unsigned __int64);
long HrIoctl(void *,unsigned long,void *,unsigned long,void *,unsigned long,unsigned long *);
long InitPropVariantFromStringAsVector(unsigned short *,unsigned int,tagPROPVARIANT *);
long InitializeAudioThreadpool();
long InitializeHardwareEventSupport(CKsDeviceTopology *,CPart *,CHardwareEventItem * *);
long KeyRep(_tagpropertykey const &,unsigned short *,unsigned __int64);
long NotifyDefaultDeviceChanged(unsigned long,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,unsigned short const *,unsigned long);
long NotifyDeviceAdded(unsigned long,unsigned short const *,unsigned long);
long NotifyDeviceRemoved(unsigned long,unsigned short const *,unsigned long);
long NotifyDeviceStateChanged(unsigned long,unsigned short const *,unsigned long,unsigned long);
long NotifyPropertyValueChanged(unsigned long,unsigned short const *,_tagpropertykey,unsigned long);
long PublishChangeNotification(unsigned short const *,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001);
long SearchMatchedRule(_tagExceptionRule *,unsigned int,_tagRANK_HEURISTICS_PARAM_VARIANT *,_tagHEURISTICDATA *,int *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0008 *);
long SerializePropVariant(tagPROPVARIANT const *,unsigned long *,unsigned char * *,unsigned __int64 *);
long SetEndpointLevel(IMMEndpointInternal *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,unsigned __int64);
long SetEndpointLevels(IMMDevice *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,unsigned __int64);
long SortExceptionRules(_tagExceptionRule *,unsigned int);
long StringCbCopyExW(unsigned short *,unsigned __int64,unsigned short const *,unsigned short * *,unsigned __int64 *,unsigned long);
long StringCbCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCbLengthW(unsigned short const *,unsigned __int64,unsigned __int64 *);
long StringCbPrintfExA(char *,unsigned __int64,char * *,unsigned __int64 *,unsigned long,char const *,...);
long StringCbPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long StringCbVPrintfExA(char *,unsigned __int64,char * *,unsigned __int64 *,unsigned long,char const *,char *);
long StringCchCatW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchCopyA(char *,unsigned __int64,char const *);
long StringCchCopyExW(unsigned short *,unsigned __int64,unsigned short const *,unsigned short * *,unsigned __int64 *,unsigned long);
long StringCchCopyNExW(unsigned short *,unsigned __int64,unsigned short const *,unsigned __int64,unsigned short * *,unsigned __int64 *,unsigned long);
long StringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchLengthW(unsigned short const *,unsigned __int64,unsigned __int64 *);
long StringCchPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long TestPropertyStoreAccess(IPropertyStore *,unsigned long);
long _AllocStringWorker<CTCoAllocPolicy>(void *,unsigned long,unsigned short const *,unsigned __int64,unsigned __int64,unsigned short * *);
long g_cRefNonCoCreatedObjects;
long getRankFromHeuristics(HKEY__ *,__MIDL___MIDL_itf_mmdeviceapip_0000_0000_0001,__MIDL___MIDL_itf_mmdeviceapi_0000_0000_0001,_tagRANK_HEURISTICS_PARAM_VARIANT *,unsigned int *);
unsigned __int64 g_hAEWMITraceHandle;
unsigned int g_u32AEWMILogFlags;
unsigned int g_u32AEWMILogLevel;
unsigned long AeWmiCallback(WMIDPREQUESTCODE,void *,unsigned long *,void *);
unsigned long GetPublicState(unsigned long);
unsigned long GetVtDataSize(unsigned short);
unsigned long STGM_to_REGSAM(unsigned long);
unsigned short * * g_Categories;
unsigned short * * g_DataFlows;
unsigned short * * gwszBusTypeNames;
unsigned short * * gwszFormFactorNames;
unsigned short * * gwszGenLocNames;
unsigned short * * gwszGeoLocNames;
unsigned short * * gwszTelephonyCapableNames;
void * operator new(unsigned __int64);
void * operator new[](unsigned __int64);
void AEWMILOG_VOLUMESET(unsigned long,void *,unsigned char,unsigned char,unsigned int,unsigned int);
void AeWmiShutdown();
void DataIntersectionForAudioFormat(KSDATAFORMAT *,KS_INTERSECTION_AUDIO *);
void ReleaseDeviceTopologyCache();
void WaitForMediaNotifications();
void __ArrayUnwind(void *,unsigned __int64,int,void (*)(void *));
void operator delete(void *);
void operator delete[](void *);
