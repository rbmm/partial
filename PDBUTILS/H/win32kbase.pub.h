class AUTO_STATUS_CHANGE_NOTIFY<2,3>
{
	void NotifyStatusChange(D3DKMT_STATE_NOTIFICATION_TYPE);
};

class AUTO_STATUS_CHANGE_NOTIFY<4,5>
{
	void NotifyStatusChange(D3DKMT_STATE_NOTIFICATION_TYPE);
};

class AUTO_TGO
{
	static void _DisposeThis(void *);
protected:
	AUTO_TGO();
	virtual ~AUTO_TGO();
};

struct ApiSetEditionCrit
{
	ApiSetEditionCrit(int,int);
	~ApiSetEditionCrit();
};

struct BEZIER32
{
	int bInit(_POINTFIX *,_RECTFX *);
	int bNext(_POINTFIX *);
};

struct BEZIER64
{
	int bNext(_POINTFIX *);
	void vInit(_POINTFIX *,_RECTFX *,__int64 *);
};

struct BRUSH
{
	HBITMAP__ * hFindIcmDIB(void *);
	int bAddIcmDIB(void *,HBITMAP__ *);
	static unsigned long _ulGlobalBrushUnique;
	void vDeleteIcmDIBs();
};

class BRUSHMEMOBJ
{
	BRUSH * pbrAllocBrush(int);
public:
	BRUSHMEMOBJ(HBITMAP__ *,HBITMAP__ *,int,unsigned long,unsigned long,int);
	BRUSHMEMOBJ(unsigned long,unsigned long,int,int);
	void vGlobal();
	~BRUSHMEMOBJ();
};

struct BRUSHSELOBJ
{
	BRUSHSELOBJ(HBRUSH__ *);
	~BRUSHSELOBJ();
};

struct CAutoMutex
{
	CAutoMutex(CMutex *);
	~CAutoMutex();
};

class CBufferRealization
{
protected:
	long Initialize();
	virtual ~CBufferRealization();
public:
	long OpenDxSurfaceHandle(bool,bool,void * *);
	long OpenLifetimeDirtyRegion(HRGN__ * *);
	static long Create(CSM_REALIZATION_INFO const &,CBufferRealization * *);
};

class CCompositionBuffer
{
	long Initialize(CSM_BUFFER_ATTRIBUTES const &,CSM_REALIZATION_INFO const &);
protected:
	CBufferRealization * GetRealizationAt(unsigned int);
	CCompositionBuffer();
	virtual long AddRealization(CBufferRealization *);
	virtual long GetCurrentRealization(CBufferRealization * *);
	virtual long RemoveRealization(CSM_REALIZATION_INFO const &,CBufferRealization * *);
	void AddScrollAsDirty(ScrollOptimization const &);
	void RemoveAllRealizations();
public:
	long FindRealization(CSM_REALIZATION_INFO const &,CBufferRealization * *);
	static CCompositionBuffer::TransformComparison CalcTransformChange(float const *,float const *);
	static long Create(CSM_BUFFER_ATTRIBUTES const &,CSM_SINGLE_BUFFER_INFO const &,CCompositionBuffer * *);
	virtual CompositionBufferType GetType();
	virtual DXGI_HDR_METADATA_TYPE GetHDRMetaDataType();
	virtual HWND__ * GetWindow();
	virtual IndependentFlipState GetIndependentFlipState();
	virtual _LUID GetAdapterLuid();
	virtual bool GetIndependentFlipNotifyDwm();
	virtual bool HasRecievedUpdates();
	virtual bool StartCompositionEarly();
	virtual long GetHDR10MetaData(DXGI_HDR_METADATA_HDR10 *);
	virtual long GetInfo(CSM_BUFFER_INFO *);
	virtual long NotifyTokenInFrame(CToken const &,bool *);
	virtual long OpenSwapChainHandles(CSM_SWAPCHAIN_HANDLE_INFO *);
	virtual long SetHDR10MetaData(DXGI_HDR_METADATA_HDR10 const &);
	virtual long SetIndependentFlip(bool,bool,unsigned int,unsigned int,int *);
	virtual void * GetGpuFence();
	virtual void ClearHDRMetaData();
	virtual void ConfirmIndependentFlipEntry(unsigned __int64,unsigned __int64,unsigned int,unsigned int,unsigned __int64);
	virtual void ImmediateSignalGpuFence(unsigned __int64);
	virtual void NotifyOfDwmTermination();
	virtual void NotifyPendingFlipPresent(_D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN const &,bool,bool *,bool *);
	virtual void SetDirectFlip(bool);
	virtual void SignalPresentLimitSemaphore();
	virtual ~CCompositionBuffer();
	void NotifyDirty(CRegion const &,ScrollOptimization const *);
};

class CCompositionSurface
{
protected:
	CCompositionBuffer * GetActiveBuffer();
	CCompositionBuffer * GetRenderingBuffer();
	bool ReleaseAllBuffers();
	bool ReleaseOlderInactiveBuffers(CCompositionBuffer *);
	long FindBuffer(unsigned __int64,CCompositionBuffer * *);
	long GetAdapterLuidAndGpuSync(unsigned __int64,_LUID *,void * *);
	long GetBufferAttributes(unsigned __int64,CSM_BUFFER_ATTRIBUTES *);
	long NotifyTokenInFrame(CToken const &,bool *);
	long UpdateBufferDirtyRegion(unsigned __int64,CRegion const &,DXGI_ALPHA_MODE);
	long UpdateStats(unsigned __int64,DXGI_FRAME_STATISTICS const &);
	long UpdateStatsAndCustomPresentDuration(unsigned __int64,DXGI_FRAME_STATISTICS const &,unsigned int,BufferFlipMode);
	virtual CompositionObjectType GetType();
	virtual bool IsLockValid();
	virtual bool IsValid();
	virtual long Close(_WIN32_CLOSEMETHOD_PARAMETERS *);
	virtual long Delete(_WIN32_DELETEMETHOD_PARAMETERS *);
	virtual long OkToClose(_WIN32_OKAYTOCLOSEMETHOD_PARAMETERS *);
	virtual long Open(_WIN32_OPENMETHOD_PARAMETERS *);
	virtual void MarkInvalid();
	void NotifyBuffersOfDwmTermination();
public:
	bool CheckBinding(unsigned __int64,CompositionBufferType *,HWND__ * *);
	bool UnlockAndRelease();
	long Bind(CCompositionBuffer *,bool);
	long ConfirmIndependentFlipEntry(unsigned __int64,unsigned __int64,unsigned __int64,unsigned int,unsigned int,unsigned __int64);
	long GetRenderingRealizationInfo(CSM_SURFACE_UPDATE *);
	long GetSurfaceUpdate(unsigned __int64,CSM_SURFACE_UPDATE *);
	long NotifyPendingFlipPresent(unsigned __int64,_D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN const &,bool,bool *,bool *);
	long OpenSectionInfo(unsigned __int64,CSM_SYSMEM_REALIZATION const &,CSM_SYSMEM_SECTION_INFO *);
	long OpenSwapChainHandles(unsigned __int64,CSM_SWAPCHAIN_HANDLE_INFO *);
	long QueryBinding(unsigned __int64,CSM_BUFFER_INFO *);
	long QueryStats(CSM_BUFFER_STATISTICS *);
	long SetSurfaceStats(unsigned __int64,DXGI_FRAME_STATISTICS const &);
	long UnBind(bool);
};

class CCompositionToken
{
protected:
	long Initialize(CompositionTokenInitInfo const &);
	long InitializeUpdates(CompositionTokenInitInfo const &);
public:
	long UpdateDirtyRegions();
	virtual CTokenBase::TokenModel GetModel();
	virtual CompositionObjectType GetType();
	virtual bool IsLockValid();
	virtual bool IsValid();
	virtual long Delete(_WIN32_DELETEMETHOD_PARAMETERS *);
	virtual long InFrame(DirectComposition::CCompositionFrame *,bool *);
	virtual void Discard();
	virtual void MarkInvalid();
};

class CDiscardInputQueue
{
	virtual CompositionInputQueueType GetType();
	virtual long AddRef();
	virtual long GetArgs(COMPOSITION_INPUT_QUEUE *);
	virtual long GetWindow(HWND__ * *);
	virtual long GetWindow(tagWND * *);
	virtual long Release();
	virtual void MarkInvalid();
};

class CDynamicArray<CInputManager::PointerCaptureInfo *,2003858261>
{
protected:
	long Grow(unsigned int);
public:
	void Reset(bool);
};

class CDynamicArray<DirectComposition::CInteractionConfigurationGroup::ContactRangeConfiguration *,2003858261>
{
protected:
	long Grow(unsigned int);
public:
	void Reset(bool);
};

class CDynamicArray<DirectComposition::CInteractionMarshaler::ManipulationCaptureInfo *,2003858261>
{
protected:
	long Grow(unsigned int);
public:
	void Reset(bool);
};

class CDynamicArray<unsigned int,2003858261>
{
protected:
	long Grow(unsigned int);
public:
	void Reset(bool);
};

class CFlipExBuffer
{
	long Initialize(CSM_BUFFER_ATTRIBUTES const &,CSM_SWAPCHAIN_BUFFER_INFO const &);
protected:
	CFlipExBuffer();
	bool CheckIndependentFlipAttributes(_D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN const &,bool *);
	bool UpdateAttributes(CFlipToken const &);
	long DisableDxgkrnlIndependentFlipMode(int *);
	long EnableDxgkrnlIndependentFlipMode(unsigned int,unsigned int,int *);
	virtual ~CFlipExBuffer();
	void ReleaseHDR10MetaData();
	void ReleasePendingPresentLimits();
	void SignalMaxGpuFence();
public:
	static long Create(CSM_BUFFER_ATTRIBUTES const &,CSM_SWAPCHAIN_BUFFER_INFO const &,CFlipExBuffer * *);
	virtual CompositionBufferType GetType();
	virtual DXGI_HDR_METADATA_TYPE GetHDRMetaDataType();
	virtual HWND__ * GetWindow();
	virtual IndependentFlipState GetIndependentFlipState();
	virtual _LUID GetAdapterLuid();
	virtual bool GetIndependentFlipNotifyDwm();
	virtual bool HasRecievedUpdates();
	virtual bool StartCompositionEarly();
	virtual long AddRealization(CBufferRealization *);
	virtual long GetCurrentRealization(CBufferRealization * *);
	virtual long GetHDR10MetaData(DXGI_HDR_METADATA_HDR10 *);
	virtual long GetInfo(CSM_BUFFER_INFO *);
	virtual long NotifyTokenInFrame(CToken const &,bool *);
	virtual long OpenSwapChainHandles(CSM_SWAPCHAIN_HANDLE_INFO *);
	virtual long RemoveRealization(CSM_REALIZATION_INFO const *,CBufferRealization * *);
	virtual long SetHDR10MetaData(DXGI_HDR_METADATA_HDR10 const &);
	virtual long SetIndependentFlip(bool,bool,unsigned int,unsigned int,int *);
	virtual void * GetGpuFence();
	virtual void ClearHDR10MetaData();
	virtual void ConfirmIndependentFlipEntry(unsigned __int64,unsigned __int64,unsigned int,unsigned int,unsigned __int64);
	virtual void ImmediateSignalGpuFence(unsigned __int64);
	virtual void NotifyOfDwmTermination();
	virtual void NotifyPendingFlipPresent(_D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN const &,bool,bool *,bool *);
	virtual void SetDirectFlip(bool);
	virtual void SignalPresentLimitSemaphore();
};

class CFlipToken
{
	void TraceStateChanged();
protected:
	CFlipToken(unsigned __int64,CompositionSurfaceObject *);
	long CanReleaseToFrame(unsigned int,bool *);
	long Initialize(_D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN const &,bool,bool,CTokenBase::TokenState);
	virtual ~CFlipToken();
	void ConfirmIndependentFlipEntry();
	void SignalGpuFenceAndPresentLimitSemaphore(bool);
public:
	static CFlipToken const * FromToken(CToken const *);
	static long CreateCompleted(unsigned __int64,CompositionSurfaceObject *,_D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN const &,CFlipToken * *);
	virtual CTokenBase::TokenModel GetModel();
	virtual bool GetEarlyTokenSync();
	virtual bool IsIndependentFlip();
	virtual bool IsRestart();
	virtual bool IsSignaled();
	virtual bool NeedsSurfaceUpdate();
	virtual bool NotifyDwm();
	virtual long CanReleaseAnalogToken(unsigned int,bool *);
	virtual long InFrame(DirectComposition::CCompositionFrame *,bool *);
	virtual unsigned int CalcSurfaceSyncRefresh(unsigned int);
	virtual unsigned int GetPresentCount();
	virtual unsigned int GetPresentInterval();
	virtual void Confirm();
	virtual void Discard();
	virtual void Retire(DXGI_FRAME_STATISTICS const &);
	virtual void SignalFlipImmediate();
};

struct CHwndTargetProp
{
	int ClearSystemVisual(int);
	long SetSystemVisual(int,CompositionObject *);
	static unsigned short s_atom;
	virtual void Delete();
};

struct CIT_DATA_READER
{
	bool Read(void *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int *);
	bool ValidateRange(unsigned int,unsigned int,unsigned int);
	bool ValidateRange<_CIT_PERSISTED_BITMAP const >(_CIT_PERSISTED_BITMAP const * *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int *);
	bool ValidateString(unsigned short const * *,unsigned int,unsigned int);
	void ReadBaseUseData<_CIT_SYSTEM_DATA>(_CIT_SYSTEM_DATA *,_CIT_PERSISTED_BASE_DATA const *);
	void ReadBaseUseData<_CIT_USE_DATA>(_CIT_USE_DATA *,_CIT_PERSISTED_BASE_DATA const *);
	void ReadOverflowUseData(_CIT_USE_DATA *);
	void ReadProgramEntry(unsigned int,_CIT_PERSISTED_PROGRAM_ENTRY *);
	void ReadProgramId(unsigned int,_CIT_PROGRAM_ID *);
	void ReadProgramUseData(unsigned int,_CIT_USE_DATA *);
	void ReadSystemData(_CIT_SYSTEM_DATA *);
};

struct CIT_DESKTOP_ACTIVE_TRACKER
{
	void CalculateUpToTime(unsigned int);
	void UpdateActive(unsigned char,unsigned int);
};

struct CIT_PERSISTED_SECTION<CIT_PERSISTED_USE_DATA>
{
	void AdvanceToNext();
};

struct CIT_PERSISTED_SECTION<_CIT_PERSISTED_BITMAP>
{
	void AdvanceToNext();
};

struct CIT_USER_ACTIVE_TRACKER
{
	void CalculateUpToTime(unsigned int);
	void OnDisplayRequiredChange(unsigned int,unsigned int);
	void OnUserActiveEvent(unsigned int);
};

struct CIT_USER_ACTIVITY_STAT
{
	CIT_USER_ACTIVITY_STAT CalculateDeltaFrom(CIT_USER_ACTIVITY_STAT const &);
	void SetActive(unsigned int);
};

class CIgnoreInputQueue
{
	virtual CompositionInputQueueType GetType();
	virtual long AddRef();
	virtual long GetArgs(COMPOSITION_INPUT_QUEUE *);
	virtual long GetWindow(HWND__ * *);
	virtual long GetWindow(tagWND * *);
	virtual long Release();
	virtual void MarkInvalid();
};

class CInputManager
{
	static long ValidateUserEvent(void *,void * *);
protected:
	long DwmInputThread(void *,void *,int (*)(tagDITCALLBACKSTRUCT *),int);
	void CleanupDwmInputThread();
public:
	static bool IsDwmInputThread(_ETHREAD *);
	static bool OwnsPointerId(unsigned int,unsigned int);
	static long CreateSessionGlobal();
	static long UpdatePointerCapture(unsigned int,unsigned int);
	static void DestroySessionGlobal();
	static void NotifyDwmInputThreadShutdown(_ETHREAD *);
};

class CInputQueue
{
protected:
	long Initialize(HWND__ *,tagMsgRoutingInfo);
public:
	static long Create(CompositionInputQueueType,HWND__ *,tagMsgRoutingInfo,CInputQueue * *);
	virtual CompositionInputQueueType GetType();
	virtual long AddRef();
	virtual long GetArgs(COMPOSITION_INPUT_QUEUE *);
	virtual long GetWindow(HWND__ * *);
	virtual long GetWindow(tagWND * *);
	virtual long Release();
	virtual void MarkInvalid();
};

class CInputSink
{
	static long CreateInputQueue(COMPOSITION_INPUT_QUEUE const &,IInputQueue * *);
protected:
	long Initialize(COMPOSITION_INPUT_SINK_V2 const &);
	void InvalidateAndReleaseQueues();
public:
	CInputSink();
	bool UnlockAndRelease();
	long QueryInputQueueForInputType(CompositionInputType,COMPOSITION_INPUT_QUEUE *);
	long QueryInputQueueTypes(COMPOSITION_INPUT_SINK_QUERY_V2 *);
	long SetDropTarget(COMPOSITION_INPUT_QUEUE const &);
	virtual CompositionObjectType GetType();
	virtual bool IsLockValid();
	virtual bool IsValid();
	virtual long Delete(_WIN32_DELETEMETHOD_PARAMETERS *);
	virtual long Open(_WIN32_OPENMETHOD_PARAMETERS *);
	virtual void MarkInvalid();
};

class CLegacyTokenBuffer
{
protected:
	long Grow();
	static long Create(CLegacyTokenBuffer * *);
	void Reset();
public:
	long GetCurrentBufferPointer(unsigned char * *,unsigned int *,unsigned int);
};

struct CList<COPMProtectedOutput>
{
	long AddElement(COPMProtectedOutput *,unsigned long *);
	long GetElement(unsigned long,COPMProtectedOutput * *);
	unsigned char GetFirstElementIndex(unsigned long *);
	unsigned char GetNextElementIndex(unsigned long,unsigned long *);
};

class CMonitorHandleTable<COPMProtectedOutput,void *>
{
	long DestroyHandleInternal(COPMProtectedOutput *,unsigned long);
public:
	long AddHandleToTable(COPMProtectedOutput *,void * *);
	long GetHandleObject(void *,COPMProtectedOutput * *);
	void DestroyAllHandlesFromAdapter(_LUID *);
};

class CMonitorPDO
{
	long MonitorInterfaceCallbackInternal(_DEVICE_INTERFACE_CHANGE_NOTIFICATION const *);
	static long MonitorInterfaceCallback(void *,void *);
	static long MonitorPDORemovalCallback(void *,void *);
public:
	CMonitorPDO(_LUID &,unsigned long,long *);
	unsigned char DoesCurrentProcessOwnProtectedOutput();
	unsigned char DoesProcessOwnProtectedOutput(void *);
	virtual long Destroy();
	virtual unsigned char IsDestroyed();
	virtual ~CMonitorPDO();
};

struct CMutex
{
	CMutex(long *);
	void Lock();
	void Unlock();
	~CMutex();
};

struct COPM
{
	long ConfigureProtectedOutput(void *,_DXGKMDT_OPM_CONFIGURE_PARAMETERS * const,unsigned long,unsigned char const *);
	long CreateProtectedOutput(_DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS,_LUID &,unsigned long,void * *,int *);
	long GetCOPPCompatibleInformation(void *,_DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS * const,_DXGKMDT_OPM_REQUESTED_INFORMATION *);
	long GetCertificate(void *,_DXGKMDT_CERTIFICATE_TYPE,unsigned char *,unsigned long);
	long GetCertificateSize(void *,_DXGKMDT_CERTIFICATE_TYPE,unsigned long *);
	long GetInformation(void *,_DXGKMDT_OPM_GET_INFO_PARAMETERS * const,_DXGKMDT_OPM_REQUESTED_INFORMATION * const);
	long GetRandomNumber(void *,_DXGKMDT_OPM_RANDOM_NUMBER *);
	long SetSigningKeyAndSequenceNumbers(void *,_DXGKMDT_OPM_ENCRYPTED_PARAMETERS * const);
	void DestroyProtectedOutputsOwnedByProcess(void *);
};

struct COPMProtectedOutput
{
	COPMProtectedOutput(_DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS,_LUID &,unsigned long,long *);
	long Configure(_DXGKMDT_OPM_CONFIGURE_PARAMETERS * const,unsigned long,unsigned char const *);
	long GetCOPPCompatibleInformation(_DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS * const,_DXGKMDT_OPM_REQUESTED_INFORMATION *);
	long GetCertificate(_DXGKMDT_CERTIFICATE_TYPE,unsigned char *,unsigned long);
	long GetCertificateSize(_DXGKMDT_CERTIFICATE_TYPE,unsigned long *);
	long GetInformation(_DXGKMDT_OPM_GET_INFO_PARAMETERS * const,_DXGKMDT_OPM_REQUESTED_INFORMATION *);
	long GetRandomNumber(_DXGKMDT_OPM_RANDOM_NUMBER *);
	long SetSigningKeyAndSequenceNumbers(_DXGKMDT_OPM_ENCRYPTED_PARAMETERS * const);
	virtual long Destroy();
	virtual unsigned char IsDestroyed();
};

struct CPushLock
{
	long AcquireLockExclusive();
	long AcquireLockShared();
	virtual bool IsLockValid();
	void ReleaseLock();
};

class CRegion
{
protected:
	long InitializeFromRect(tagRECT const &);
	static tagRECT const sc_rcEmpty;
public:
	long AddRect(tagRECT const &);
	long Combine(CRegion const &,CRegion::CombineMode);
	long GetRegionHandleAndReset(HRGN__ * *);
	long Release();
	static long Create(CRegion * *);
	static long Create(tagRECT const &,CRegion * *);
	void SetEmpty();
	void SetFullRegion();
};

struct CStructDynamicArray<CInputManager::PointerCaptureInfo>
{
	long InsertAt(CInputManager::PointerCaptureInfo const &,unsigned int);
	void RemoveAt(unsigned int);
};

struct CStructDynamicArray<DirectComposition::CInteractionConfigurationGroup::ContactRangeConfiguration>
{
	long InsertAt(DirectComposition::CInteractionConfigurationGroup::ContactRangeConfiguration const &,unsigned int);
	void RemoveAt(unsigned int);
	void Reset(bool);
	~CStructDynamicArray<DirectComposition::CInteractionConfigurationGroup::ContactRangeConfiguration>();
};

struct CStructDynamicArray<DirectComposition::CInteractionMarshaler::ManipulationCaptureInfo>
{
	void Reset(bool);
};

class CToken
{
	static long CreateFlipToken(unsigned __int64,CompositionSurfaceObject *,_D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN const &,CToken * *);
protected:
	CToken(unsigned __int64,CompositionSurfaceObject *);
	virtual long Initialize(CTokenBase::TokenState);
public:
	static long CreateFromCompletedFlipToken(unsigned __int64,_D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN const &,CToken * *);
	static long CreateUnBindToken(CompositionSurfaceObject *,CToken * *);
	virtual bool GetEarlyTokenSync();
	virtual bool IsIndependentFlip();
	virtual bool IsRestart();
	virtual bool IsSignaled();
	virtual bool NotifyDwm();
	virtual long CanReleaseAnalogToken(unsigned int,bool *);
	virtual unsigned int CalcSurfaceSyncRefresh(unsigned int);
	virtual unsigned int GetPresentCount();
	virtual unsigned int GetPresentInterval();
	virtual void SignalFlipImmediate();
	virtual ~CToken();
};

class CTokenBase
{
protected:
	virtual long Initialize(CTokenBase::TokenState);
public:
	virtual CTokenBase::TokenModel GetModel();
	virtual bool NeedsSurfaceUpdate();
	virtual long InFrame(DirectComposition::CCompositionFrame *,bool *);
	virtual void Complete();
	virtual void Confirm();
	virtual void Discard();
	virtual void Pending();
	virtual void Retire(DXGI_FRAME_STATISTICS const &);
	virtual ~CTokenBase();
};

class CTokenManager
{
	struct TokenQueueTableEntry
	{
		bool IsValid();
		static _RTL_GENERIC_COMPARE_RESULTS Compare(_RTL_GENERIC_TABLE *,void *,void *);
		static void * Allocate(_RTL_GENERIC_TABLE *,unsigned long);
		static void Free(_RTL_GENERIC_TABLE *,void *);
	};

	CTokenManager();
	long Initialize();
	static long OpenEventForSynchonize(void *,void * *);
	static long ValidateUserEvent(void *,void * *);
	void AcquireTokenManagerLock();
	~CTokenManager();
protected:
	bool ReleaseCompositionHandleTokensToFrame(DirectComposition::CCompositionFrame *);
	int GetAnalogSurfaceUpdatesInternal(unsigned int,unsigned int,CSM_SURFACE_UPDATE *,unsigned int *);
	long AddTokenToQueue(CToken *);
	long AddUnBindTokenInternal(CompositionSurfaceObject *);
	long CompleteIndendentFlipToken(unsigned __int64,_D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN const &,unsigned int);
	long CreateFlipExToken(unsigned __int64,_D3DKMT_FLIPMODEL_PRESENTHISTORYTOKEN const &,bool *);
	long EnsureCurrentLegacyTokenBuffer();
	long EnsureRenderFenceWait(CSM_TOKEN_ADAPTER_INFO *);
	long EnsureTokenQueue(CompositionSurfaceObject *,CTokenManager::TokenQueueTableEntry * *);
	long GetAnalogExclusiveTokenEventInternal(void * *);
	long ProcessDxgkAdapterTokens(unsigned int);
	long ProcessGdiSysmemTokens();
	long ProcessTokens(void *,void *,CSM_TOKEN_ADAPTER_INFO *,void * *,unsigned int);
	long ResolveCompositionHandleToken(_D3DKMT_COMPOSITION_PRESENTHISTORYTOKEN const &);
	long SignalGpuFenceInternal(_LUID,void *,unsigned __int64);
	void ConfirmOutstandingAnalogTokenInternal();
	void DeleteAllCompositionTokens();
	void DeleteAllLegacyTokenBuffers();
	void DeleteAllTokenQueues();
	void DeleteAllTokensInternal();
	void DeleteOutstandingAnalogTokenInternal();
	void NotifyCompositionTokensOfRedirectionStop();
	void NotifyQueuesOfRedirectionStop();
	void ReleaseToFrameInternal(DirectComposition::CCompositionFrame *);
	void RemoveIndependentFlipSkipTokenFromList(unsigned __int64,_LUID,CToken * *);
	void RemoveTokenQueueTableEntry(CTokenManager::TokenQueueTableEntry *);
	void ReturnLegacyTokenBufferInternal(CLegacyTokenBuffer *);
	void SetAdapterInfo(CSM_TOKEN_ADAPTER_INFO *,unsigned int);
public:
	static long EnsureTokenQueueForPresent(CompositionSurfaceObject *);
	static long OpenSectionAndEvents(void * *,unsigned __int64 *,void * *,void * *);
	static long TokenThread(void *,CSM_TOKEN_ADAPTER_INFO *,unsigned int);
};

struct CTokenQueue
{
	bool ReleaseAnalogTokensAndGetUpdates(unsigned int,CSM_SURFACE_UPDATE *,unsigned int,bool *,unsigned int *,CToken * *);
	bool ReleaseTokensToFrame(DirectComposition::CCompositionFrame *);
	static long Create(CompositionSurfaceObject const *,CTokenQueue * *);
	void AddToken(CToken *);
};

class CompositionInputObject
{
protected:
	static long ObjectInit(CompositionObject *,void *,ICompositionObject * *);
	static long ResolveHandle(void *,unsigned long,char,CompositionInputObject * *);
public:
	int IsImplicit();
	long AssociateWithVisual(void *);
	long GetWindowForInputType(CompositionInputType,HWND__ * *);
	long GetWindowForInputType(CompositionInputType,tagWND * *);
	long LockForRead(CInputSink const * *);
	long LockForWrite(CInputSink * *);
	long QueryInputQueueTypes(COMPOSITION_INPUT_SINK_QUERY_V2 *);
	long QueryTransform(tagINPUT_TRANSFORM *);
	long SetDropTarget(COMPOSITION_INPUT_QUEUE const &);
	long UpdateTransform(tagINPUT_TRANSFORM const &);
	static long KernelCreateCompositionInputSink(COMPOSITION_INPUT_SINK_V2 const *,int,void * *);
};

class CompositionObject
{
protected:
	static long Create(char,_OBJECT_ATTRIBUTES *,unsigned long,char,CompositionObjectType,unsigned long,long (*)(CompositionObject *,void *,ICompositionObject * *),void *,void * *);
public:
	__int64 Release();
	long AddRef();
	long CreateHandle(unsigned long,bool,char,void * *);
	long OpenDwmHandle(void * *);
	static long OkToClose(_WIN32_OKAYTOCLOSEMETHOD_PARAMETERS *);
	static long Open(_WIN32_OPENMETHOD_PARAMETERS *);
	static long ResolveHandle(void *,unsigned long,char,CompositionObjectType,CompositionObject * *);
};

class CompositionSurfaceObject
{
protected:
	static long ObjectInit(CompositionObject *,void *,ICompositionObject * *);
	static long ResolveHandle(void *,unsigned long,char,CompositionSurfaceObject * *);
public:
	bool GetAnalogExclusive();
	bool StartCompositionEarly(unsigned __int64);
	long ConfirmIndependentFlipEntry(unsigned __int64,unsigned __int64,unsigned __int64,unsigned int,unsigned int,unsigned __int64);
	long GetAdapterLuidAndGpuSync(unsigned __int64,_LUID *,void * *);
	long GetIndependentFlipNotifyDwm(unsigned __int64,bool *);
	long GetSurfaceUpdate(unsigned __int64,CSM_SURFACE_UPDATE *);
	long HasActiveBinding(bool *);
	long LockForRead(CCompositionSurface const * *);
	long LockForWrite(CCompositionSurface * *);
	long NotifyTokenInFrame(CToken const &,bool *);
	long SyncIntervalSatisfied(unsigned int,bool *);
	void ImmediateSignalGpuFence(unsigned __int64,unsigned __int64);
	void NotifyOfRedirectionStop();
	void SetSyncRefreshCount(unsigned int);
	void SignalPresentLimitSemaphore(unsigned __int64);
	void UpdateStatsAndCustomPresentDuration(unsigned __int64,DXGI_FRAME_STATISTICS const &,unsigned int,BufferFlipMode);
};

class CompositionTokenObject
{
protected:
	static long ObjectInit(CompositionObject *,void *,ICompositionObject * *);
public:
	long MarkCompleted();
	long MarkPending();
};

namespace CoreMessaging
{
	namespace Calling
	{
		struct FailFast
		{
			static void Error(char const *,unsigned int);
		};

		struct ReceiveProcessor
		{
			long UnmarshalReceive(IMessageCallReceiveHost *,MsgCallTypeDefinition const *,unsigned char const *,unsigned int,void const *,unsigned int);
		};

		class SendProcessor
		{
			long PrepareMessageWorker(IMessageCallSendHost *,unsigned short,unsigned short,unsigned char const *,char *,int,unsigned int,unsigned int,unsigned int);
		public:
			long ComputeMaximumMessageSize(IMessageCallSendHost *,unsigned char const * *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int *);
		};

	};

};

namespace CoreMessagingK
{
	class BufferCache
	{
		static BufferCache::BufferHeader * s_FreeList;
		static long AllocUninitialized(unsigned short,void * *);
		static void Remove(BufferCache::BufferHeader *,BufferCache::BufferHeader *);
	public:
		static long AllocUninitialized<AlpcBufferK>(unsigned short,AlpcBufferK * *);
		static void Free(void *);
	};

	class CoreMsgObject
	{
		static long Open(_WIN32_OPENMETHOD_PARAMETERS *);
	};

	class EntryLock
	{
		static unsigned char s_Initialized;
	public:
		static long Initialize();
	};

	namespace HResultUtil
	{
		long HRESULTFromNTStatus(long);
	};

	class ReceiveHost
	{
		static IMessageCallReceiveHostVtbl const s_Vtbl;
	public:
		static long NotifyInvalid(IMessageCallReceiveHost *,MsgCallState *);
		static long NotifyProtocolViolation(IMessageCallReceiveHost *,MsgCallState *);
		static long QueryInterface(IMessageCallReceiveHost *,_GUID const &,void * *);
		static unsigned long AddRef(IMessageCallReceiveHost *);
		static unsigned long Release(IMessageCallReceiveHost *);
	};

	class RegistrarClient
	{
		static unsigned short s_MaxReceiveMessagePayloadSize;
		static unsigned short s_MaxSendMessagePayloadSize;
		static void * s_Port;
	public:
		static void Initialize();
	};

	struct Runtime
	{
		static void BugCheck(BugCheckCodes,unsigned __int64,unsigned __int64,unsigned __int64);
	};

	class SendHost
	{
		static IMessageCallSendHostVtbl const s_Vtbl;
		static void ValidateReceiveBuffer(AlpcBufferK *,unsigned __int64);
	public:
		static long AllocateBuffer(IMessageCallSendHost *,void * *,unsigned int,unsigned int,void * *);
		static long CancelBuffer(IMessageCallSendHost *,void * *,unsigned int,void *,unsigned int);
		static long NotifyInvalid(IMessageCallSendHost *,MsgCallState *);
		static long QueryInterface(IMessageCallSendHost *,_GUID const &,void * *);
		static long SubmitBuffer(IMessageCallSendHost *,void * *,unsigned int,void *,unsigned int);
		static unsigned long AddRef(IMessageCallSendHost *);
		static unsigned long Release(IMessageCallSendHost *);
	};

	class ServerPorts
	{
		static _CALLBACK_OBJECT * s_CallbackObject;
		static void * s_CallbackRegistration;
	};

};

struct DC
{
	EPOINTL & eptlOrigin();
	HPATH__ * hpath(HPATH__ *);
	int bCompute();
	int bMakeInfoDC(int);
	int bOldPenNominal(EXFORMOBJ &,long);
	int bSetDefaultRegion();
	long iCombine(EXFORMOBJ *,_RECTL *,long);
	long iCombine(_RECTL *,long);
	unsigned long dwSetLayout(long,unsigned long);
	void MirrorWindowOrg();
	void vCalcFillOrigin();
	void vCopyTo(XDCOBJ &);
	void vMakeIso();
	void vRealizeLineAttrs(EXFORMOBJ &);
	void vReleaseRao();
	void vReleaseVis();
	void vSetRendering();
	void vUpdateWtoDXform();
	void vUpdate_VisRect(REGION *);
};

struct DCMEMOBJ
{
	DCMEMOBJ(DCOBJ &);
	DCMEMOBJ(unsigned long,int,int);
	~DCMEMOBJ();
};

struct DCOBJ
{
	DCOBJ();
	DCOBJ(HDC__ *);
	~DCOBJ();
};

struct DCOBJA
{
	DCOBJA(HDC__ *);
};

struct DEVLOCKOBJ
{
	DEVLOCKOBJ();
	DEVLOCKOBJ(PDEVOBJ &);
	int bLock(XDCOBJ &,int);
	int bPrepareTrgDco(XDCOBJ *);
	void vDestructor();
	void vInit();
	void vLock(PDEVOBJ &);
	void vLockNoDrawing(XDCOBJ &);
};

struct DYNAMICMODECHANGESHARELOCK
{
	DYNAMICMODECHANGESHARELOCK();
	~DYNAMICMODECHANGESHARELOCK();
};

class DeadzonePalmTelemetry
{
	void _UploadTelemetryData(int);
public:
	void ClearSession();
	void UpdateTelemetryBuffer(unsigned long,unsigned long,int);
};

namespace DirectComposition
{
	class CAffineTransform2DEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual unsigned int GetMaxInputs();
		void SetMatrixHelper(CApplicationChannel *,D2D_MATRIX_3X2_F const *,bool *);
	};

	class CAnalogCompositorMarshaler
	{
	protected:
		virtual bool EmitActiveExclusiveView(CBatch * *);
		virtual bool EmitCreate(CBatch * *);
		virtual bool EmitExclusiveOpacity(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CAnalogExclusiveViewMarshaler
	{
	protected:
		virtual bool EmitCreate(CBatch * *);
		virtual bool EmitSwapChain(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual long Initialize();
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CAnalogTextureTargetMarshaler
	{
	protected:
		virtual bool EmitCreate(CBatch * *);
		virtual bool EmitRoot(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual long Initialize();
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	struct CAnimationBinding
	{
		static long Create(CResourceMarshaler *,unsigned int,CBaseAnimation *,CAnimationBinding * *);
		void DetachAndDelete(CApplicationChannel *);
		void Initialize(CResourceMarshaler *,unsigned int,CBaseAnimation *);
		void Reassign(CBaseAnimation *,CApplicationChannel *);
		void SetTargetProperty(float,bool *);
	};

	class CAnimationMarshaler
	{
	protected:
		bool EmitAddTimeEvents(CBatch * *);
		bool EmitBeginTime(CBatch * *);
		bool EmitClearTimeEvents(CBatch * *);
		bool EmitSetHandoff(CBatch * *);
		bool EmitSetInstance(CBatch * *);
		bool EmitSetPaused(CBatch * *);
		bool EmitSetPrimitives(CBatch * *);
		bool EmitSetSeek(CBatch * *);
		long EnsureTimeListEntry();
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual long Initialize();
		virtual long SetCallbackId(unsigned int,bool *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
		void CalculateAnimationTimeState(CAnimationTimeList *,unsigned __int64,unsigned __int64 *,bool *,__int64 *,unsigned __int64 *);
		void GetAnimationTime(unsigned __int64,__int64 *);
		void GetAnimationTimeState(bool *,__int64 *,unsigned __int64 *);
		void UpdateAnimationTimeState(unsigned __int64);
	public:
		bool HasEnded(unsigned __int64,float *);
		virtual DCOMPOSITION_EXPRESSION_TYPE GetExpressionType();
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
		virtual ~CAnimationMarshaler();
	};

	struct CAnimationTimeList
	{
		unsigned long Release();
	};

	class CAnimationTriggerMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
	};

	class CApplicationChannel
	{
	protected:
		CApplicationChannel(CConnection *,bool,unsigned int);
		bool BuildBatch(CBatch * *,CBatch * *,bool);
		bool EmitBindingAddCommands(CBatch * *);
		bool EmitBindingRemovalCommands(CBatch * *);
		bool EmitCallbackIDCommand(CBatch * *);
		bool EmitCallbackIDCommand(CBatch * *,bool);
		bool EmitCreationCommands(CBatch * *);
		bool EmitDeletionCommands(CBatch * *);
		bool EmitSharedSectionUpdateCommands(CBatch * *);
		bool EmitUpdateCommands(CBatch * *);
		bool ProcessReturnedBatches();
		bool UnbindAnimation(CResourceMarshaler *,unsigned int);
		long BindAnimation(CResourceMarshaler *,unsigned int,CBaseAnimation *);
		long CheckAndAddHandoff(CResourceMarshaler *,unsigned int,CBaseAnimation *,CAnimationBinding *);
		long GetWeakReferenceBase(CResourceMarshaler *,CWeakReferenceBase * *);
		long Initialize(unsigned int *,void * *);
		long ProcessCommandBufferIterator(void *,unsigned int,bool,unsigned long *);
		long RegisterResource(CResourceMarshaler *);
		static void FindAndDequeue(CResourceMarshaler *,CResourceMarshaler * *);
		static void ReleaseCrossChannelVisuals(CConnection *,CrossChannelVisualData *);
		virtual unsigned __int64 GetBatchMinimumPayloadSize();
		virtual void CompleteDisconnection(bool);
		virtual void CompleteReconnection();
		virtual void Shutdown();
		virtual ~CApplicationChannel();
		void ClearAnimationTimeList();
		void DeleteAddingBinding(CAnimationBinding *);
		void DiscardRemovingBinding(CAnimationBinding *);
		void NewRemovingBinding(CAnimationBinding *);
		void PreallocateNextBatch();
		void RemoveExpiredAnimations();
		void RemoveFromBatchList(CAnimationBinding *,CAnimationBinding * *);
		void SubmitBatch(CBatch *,CBatch *,bool);
	public:
		CBatch * GetBatchFragment(bool,bool);
		bool WaitForPendingAndProcessReturnedBatches(bool);
		long AddVisualChild(unsigned int,unsigned int,int,unsigned int);
		long CapturePointer(unsigned int,CapturePointerType,unsigned int,unsigned int,unsigned __int64);
		long Commit(bool *,bool);
		long CompleteAddCrossChannelVisualChild(unsigned int,unsigned int,unsigned int,ResourceHandle,int,unsigned int,ResourceHandle);
		long CompleteRemoveCrossChannelVisualChild(unsigned int,unsigned int,ResourceHandle);
		long CreateAndBindSharedSection(unsigned int,unsigned __int64,void * *);
		long CreateBatch(CBatch * *);
		long CreateInternalResource(unsigned int,CResourceMarshaler * *);
		long CreateInternalSharedResource(unsigned int,CResourceMarshaler * *);
		long CreateResource(unsigned int,unsigned int,bool);
		long CreateSystemVisualForCrossChannelVisualChild(unsigned int,ResourceHandle *);
		long GetAnimationTime(unsigned int,unsigned __int64,__int64 *);
		long GetChannelRDPHeaders(UCE_RDP_HEADER * *,UCE_RDP_HEADER * *);
		long GetSystemVisualFromCrossChannelVisualChild(unsigned int,ResourceHandle *);
		long OpenInternalSharedResource(void *,unsigned int,bool,CResourceMarshaler * *);
		long OpenSharedResource(unsigned int,void *,unsigned int,bool);
		long OpenSharedResourceHandle(unsigned int,void * *);
		long RedirectMouseToHwnd(unsigned int,HWND__ *,tagMsgRoutingInfo const *,unsigned long,unsigned long);
		long ReleaseResource(unsigned int);
		long RemoveVisualChild(unsigned int,unsigned int);
		long SetCallbackId(bool,unsigned int,unsigned int);
		long SetCommitCompletionEvent(void *);
		long SetResourceAnimationProperty(unsigned int,unsigned int,unsigned int);
		long SetResourceBufferProperty(CResourceMarshaler *,unsigned int,void const *,unsigned __int64);
		long SetResourceCallbackId(unsigned int,unsigned int);
		long SetResourceDeletedNotificationTag(unsigned int,unsigned __int64);
		long SetResourceFloatProperty(unsigned int,unsigned int,float);
		long SetResourceHandleProperty(unsigned int,unsigned int,void *);
		long SetResourceReferenceArrayProperty(unsigned int,unsigned int,unsigned int const *,unsigned __int64);
		long SetVisualInputSink(unsigned int,void *);
		long VisualCaptureBits(unsigned int,int,int,unsigned int,unsigned int,DXGI_FORMAT,void *,void *);
		static long AddCrossChannelVisualChild(unsigned int,unsigned int,unsigned int,unsigned int,int,unsigned int,unsigned int);
		static long Create(unsigned int *,unsigned int *,void * *);
		static long ReferenceHandleAndLock(unsigned int,CApplicationChannel * *);
		static long RemoveCrossChannelVisualChild(unsigned int,unsigned int,unsigned int,unsigned int);
		unsigned long ReleaseResource(CResourceMarshaler *);
		virtual CChannel::Type GetType();
		virtual void ConfirmFrame();
		virtual void UnlockAndUnreference();
		void AddAnimationTimeListEntry(CAnimationTimeList *);
		void NotifyBatchProcessed(CBatch *);
		void PutResourceOnUpdatedList(CResourceMarshaler *);
		void ReleaseAllResources(bool *);
		void ReleaseCrossChannelVisualChild(ResourceHandle);
		void ReleaseWeakReference(CWeakReferenceBase *);
		void ReturnProcessedBatch(CBatch *);
		void UnbindAllAnimations(CResourceMarshaler *);
	};

	class CArithmeticCompositeEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual unsigned int GetMaxInputs();
	};

	class CBackdropBrushMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool SetRemarshalingFlags();
	};

	struct CBaseAnimationMarshaler<CNotifiedDeletionResource>
	{
		virtual CBaseAnimation * GetBaseAnimation();
		virtual CResourceMarshaler * GetResourceMarshaler();
	};

	struct CBaseAnimationMarshaler<CResourceMarshaler>
	{
		virtual CBaseAnimation * GetBaseAnimation();
		virtual CResourceMarshaler * GetResourceMarshaler();
	};

	class CBaseClipMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
	};

	class CBaseExpressionMarshaler
	{
		bool EmitSetBindingBroken(CBatch * *);
		bool EmitSetTarget(CBatch * *);
		bool EmitSetTracingCookie(CBatch * *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
		virtual ~CBaseExpressionMarshaler();
	};

	struct CBaseTransformMarshaler
	{
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
	};

	struct CBatch
	{
		bool GetPayloadWritePointer(unsigned __int64,void * *);
		bool ShouldDefer(__int64,CEvent *);
		long AddSystemResourceRef(ResourceHandle);
		static bool AllocateNewFragment(CBatch * *,unsigned __int64 *);
		static bool EnsureBatchBuffer(CBatch * *,unsigned __int64,void * *);
		void Clear();
		void ReturnToApplication(bool);
	};

	struct CBatchSharedMemoryPool
	{
		bool BeginDynamicAllocation(unsigned __int64,unsigned __int64 *);
		long GetUserModeViewAtOffset(unsigned __int64,void * *);
		static long Create(CBatchSharedMemoryPoolSet *,bool,CBatchSharedMemoryPool * *);
		void * UseSpace(unsigned __int64);
		void Reset();
		void UnmapUserModeView();
	};

	struct CBatchSharedMemoryPoolSet
	{
		long BeginDynamicAllocation(unsigned __int64,CBatchSharedMemoryPool * *,unsigned __int64 *);
		long ReservePools(unsigned __int64);
		long StaticAllocate(unsigned __int64,CBatchSharedMemoryPool * *,unsigned __int64 *);
		void FreeAllPools();
		void SetRetrievingProcess(_EPROCESS *);
	};

	class CBlendEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long Initialize();
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual unsigned int GetMaxInputs();
	};

	class CBrightnessEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CChannel
	{
	protected:
		virtual long Initialize();
		virtual void CompleteDisconnection(bool);
		virtual void CompleteReconnection();
		virtual ~CChannel();
	public:
		static long DestroyHandle(unsigned int);
		static long OnProcessCreation(CProcessData *);
		static long ReferenceHandleAndLock(unsigned int,CChannel * *);
		static void OnProcessDestruction(CProcessData *);
		unsigned long Release();
		virtual CChannel::Type GetType();
		virtual void UnlockAndUnreference();
		void Unlock();
	};

	class CClipGroupMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetReferenceArrayProperty(CApplicationChannel *,unsigned int,CResourceMarshaler * *,unsigned __int64,bool *);
	};

	class CColorBrushMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool SetRemarshalingFlags();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
	};

	class CColorMatrixEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CCompiledEffectTemplateMarshaler
	{
		bool EmitUpdate(CBatch * *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool SetRemarshalingFlags();
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	};

	class CComponentTransform2DMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CComponentTransform3DMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CCompositeEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long Initialize();
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual unsigned int GetMaxInputs();
	};

	class CCompositionAmbientLightMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
	};

	class CCompositionDistantLightMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CCompositionFrame
	{
		static unsigned __int64 s_frameIdCounter;
	protected:
		CCompositionFrame(COMPOSITION_FRAME_INFO const &);
		void ReturnLegacyTokenBuffer();
	public:
		int GetSurfaceUpdates(CSM_SURFACE_UPDATE *,unsigned int,unsigned int *);
		long Release();
		void Discard();
		void Retire(DXGI_FRAME_STATISTICS const &);
	};

	class CCompositionLightMarshaler
	{
		bool EmitAddTargets(CBatch * *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
		void ReleaseResourceMarshalers(CApplicationChannel *,CResourceMarshaler * *,unsigned int &);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetReferenceArrayProperty(CApplicationChannel *,unsigned int,CResourceMarshaler * *,unsigned __int64,bool *);
	};

	class CCompositionPointLightMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CCompositionSpotLightMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CCompositionSurfaceBitmapMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CConditionalExpressionMarshaler
	{
		bool EmitAddConditionAnimationResources(CBatch * *);
		bool EmitSetDefaultAnimation(CBatch * *);
		bool EmitSetSelection(CBatch * *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceArrayProperty(CApplicationChannel *,unsigned int,CResourceMarshaler * *,unsigned __int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CConnection
	{
		CConnection();
		long Initialize();
		long RetrieveBatches(unsigned __int64,UCE_RDP_HEADER const * *);
		static CConnection * s_pSessionConnection;
		static CCriticalSection * s_pSessionConnectionLock;
		void DiscardAllCompositionFrames();
		void KeepOrDeferBatches(unsigned __int64,CBatch * *);
	public:
		bool IsConnected();
		long BeginFrame(COMPOSITION_FRAME_INFO const &,unsigned __int64 *);
		long Connect(void *);
		long CreateSystemResource(unsigned int,ResourceHandle *);
		long DesktopCaptureBits(HMONITOR__ *,int,int,unsigned int,unsigned int,DXGI_FORMAT,void *,void *);
		long EnableMMCSS(int);
		long FindCompositionFrame(unsigned __int64,CCompositionFrame * *);
		long ForceRender(bool,bool,DwmHardwareTeardown::Enum);
		long GetBatches(UCE_RDP_HEADER const * *);
		long GetFrameStatistics(DCOMPOSITION_FRAME_STATISTICS *);
		long GetReadyBatches(unsigned __int64,CBatch * *);
		long RegisterChannel(CChannel *,unsigned int *);
		long RemoveCompositionFrame(unsigned __int64);
		long RenderBlack(bool);
		long Synchronize(void *,bool);
		static CConnection * GetDefaultConnection();
		static D3D_FEATURE_LEVEL s_maxHardwareFeatureLevel;
		static D3D_FEATURE_LEVEL s_minSafeFeatureLevel;
		static _ETHREAD * s_pDwmRenderThread;
		static long Create(void *,HDCOMPOSITIONCONNECTION__ * *);
		static long DestroyHandle(HDCOMPOSITIONCONNECTION__ *);
		static long OnSessionCreation(int);
		static long ReclaimSessionGlobalConnection(CConnection * *);
		static long ReferenceHandle(HDCOMPOSITIONCONNECTION__ *,CConnection * *);
		static unsigned __int64 s_qpcFrequency;
		static void OnDwmRenderThreadExit();
		unsigned long Release();
		void AppendRetrievingBatches(CBatch *);
		void ConfirmFrame();
		void DiscardPreviousFrames(unsigned __int64);
		void Disconnect();
		void GetNewBatches(CBatch * *);
		void PostBatch(CBatch *,CBatch *);
		void ReferenceSystemResource(ResourceHandle);
		void ReleaseSystemResource(ResourceHandle);
		void UnregisterChannel(CBatch *,bool);
	};

	struct CCriticalSection
	{
		bool TryAcquireExclusive();
		void AcquireExclusive();
		void AcquireShared();
	};

	class CCrossChannelChildVisualMarshaler
	{
	protected:
		virtual bool EmitCreationCommand(CBatch * *);
		virtual bool EmitDeletionCommand(CBatch * *);
	public:
		virtual bool IsAssociatedWithSystemVisual(ResourceHandle);
		virtual bool IsCrossChannelChildVisual();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	};

	class CCrossChannelParentVisualMarshaler
	{
	protected:
		virtual bool DetachFromParent(CApplicationChannel *);
		virtual bool EmitCreationCommand(CBatch * *);
		virtual bool IsAssociatedWithSystemVisual(ResourceHandle);
	public:
		long Initialize(CApplicationChannel *,ResourceHandle,unsigned int);
		virtual bool IsCrossChannelParentVisual();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	};

	class CDCompDynamicArrayBase
	{
	protected:
		virtual ~CDCompDynamicArrayBase();
	public:
		long Grow(unsigned __int64,unsigned long);
		long SetCount(unsigned __int64,unsigned long);
		long Shrink(unsigned __int64);
	};

	class CDesktopTargetMarshaler
	{
	protected:
		virtual bool EmitCreate(CBatch * *);
		virtual bool EmitDcompTargetGroup(CBatch * *);
		virtual bool EmitRoot(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CDropShadowMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool SetRemarshalingFlags();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CDwmChannel
	{
	protected:
		virtual unsigned __int64 GetBatchMinimumPayloadSize();
	public:
		static long Create(unsigned int *);
		static long ReferenceHandleAndLock(unsigned int,CDwmChannel * *);
		virtual CChannel::Type GetType();
		void SubmitDwmBatch(unsigned __int64);
	};

	class CEffectBrushMarshaler
	{
		bool EmitSetInputs(CBatch * *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool SetRemarshalingFlags();
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CEffectGroupMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	};

	struct CEffectInputSet
	{
		bool EmitUpdateCommands(MILCMD,unsigned int,CBatch * *);
		long Initialize(unsigned int);
		long SetInput(CApplicationChannel *,unsigned int,CResourceMarshaler *);
	};

	class CEvent
	{
		long Initialize(void *,bool);
	public:
		static long Create(_EVENT_TYPE,CEvent * *);
		static long Create(void *,CEvent * *);
	};

	class CExpressionMarshaler
	{
		bool EmitSetNodesInfo(CBatch * *);
		bool EmitSetReferenceInfo(CBatch * *);
		bool EmitSetSources(CBatch * *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceArrayProperty(CApplicationChannel *,unsigned int,CResourceMarshaler * *,unsigned __int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CFilterEffectMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual long Initialize();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsEarlyDestroyNotificationSupported();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
		virtual unsigned int GetMaxInputs();
		virtual ~CFilterEffectMarshaler();
	};

	class CFloodEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual unsigned int GetMaxInputs();
	};

	class CGaussianBlurEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CGenericTable<CResourceMarshaler *,CWeakReferenceBase,1953973060,1>
	{
		static _RTL_GENERIC_COMPARE_RESULTS CompareTableEntries(_RTL_GENERIC_TABLE *,void *,void *);
		static void * AllocateTableEntry(_RTL_GENERIC_TABLE *,unsigned long);
		static void FreeTableEntry(_RTL_GENERIC_TABLE *,void *);
	public:
		CWeakReferenceBase * RemoveObject(CResourceMarshaler *);
	};

	class CGenericTable<unsigned __int64,CBatch,1702052676,0>
	{
		static _RTL_GENERIC_COMPARE_RESULTS CompareTableEntries(_RTL_GENERIC_TABLE *,void *,void *);
		static void * AllocateTableEntry(_RTL_GENERIC_TABLE *,unsigned long);
		static void FreeTableEntry(_RTL_GENERIC_TABLE *,void *);
	public:
		CBatch * FindObject(unsigned __int64);
	};

	class CGenericTable<unsigned int,CChannel,1952662340,1>
	{
		static _RTL_GENERIC_COMPARE_RESULTS CompareTableEntries(_RTL_GENERIC_TABLE *,void *,void *);
		static void * AllocateTableEntry(_RTL_GENERIC_TABLE *,unsigned long);
		static void FreeTableEntry(_RTL_GENERIC_TABLE *,void *);
	public:
		long InsertObject(unsigned int,CChannel *);
	};

	class CHostVisualMarshaler
	{
	protected:
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		static long Create(CSharedSystemResource const *,CHostVisualMarshaler * *);
		virtual bool EmitCreationCommand(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual long AddChild(CApplicationChannel *,CVisualMarshaler *,int,CVisualMarshaler *,bool *);
		virtual long OpenSharedHandle(void * *);
		virtual long RemoveAllChildren(CApplicationChannel *,bool *);
		virtual long RemoveChild(CApplicationChannel *,CVisualMarshaler *,bool *);
		virtual long SetHandleProperty(unsigned int,void *,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CHueRotationEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CHwndBitmapMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CInkMarshaler
	{
		bool EmitBasicStateUpdate(CBatch * *);
		bool EmitSegmentCountUpdate(CBatch * *);
		bool EmitSegmentUpdate(CBatch * *);
		bool EmitStartPointUpdate(CBatch * *);
		long AddSegments(D2D1_INK_BEZIER_SEGMENT const *,unsigned int,bool *);
		long RemoveSegmentsAtEnd(unsigned int,bool *);
		long SetSegments(unsigned int,D2D1_INK_BEZIER_SEGMENT const *,unsigned int,bool *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool SetRemarshalingFlags();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CInteractionConfigurationGroup
	{
		bool EmitUpdateMouseConfiguration(CBatch * *);
		bool EmitUpdatePenConfiguration(CBatch * *);
		bool EmitUpdateTouchConfiguration(CBatch * *);
		bool EmitUpdateTouchpadConfiguration(CBatch * *);
		long ProcessUpdateTouchConfigurationList(DwmInteractionConfiguration const *,InteractionProperty::Enum,bool *);
		long ProcessUpdateTouchpadConfiguration(DwmInteractionConfiguration const *,InteractionProperty::Enum,bool *);
		long UpdateContactCountConfigurationArray(InteractionProperty::Enum,CInteractionConfigurationGroup::ContactRangeConfiguration,CStructDynamicArray<CInteractionConfigurationGroup::ContactRangeConfiguration> *,bool *);
		static unsigned int ApplyConfigOperation(unsigned int,unsigned int,InteractionProperty::Enum,bool *);
	public:
		bool EmitUpdateCommands(CBatch * *);
		long ProcessUpdateConfiguration(DwmInteractionConfiguration const *,InteractionProperty::Enum,bool *);
		long SetConfigurationAll(InteractionInputType::Enum);
		void ReleaseAllReferences();
		~CInteractionConfigurationGroup();
	};

	class CInteractionMarshaler
	{
		long CheckInputSinkTypes();
	protected:
		bool EmitInputSink(CBatch * *);
		bool EmitUpdateFlags(CBatch * *);
		bool EmitUpdateRails(CBatch * *);
		virtual bool EmitCreationCommand(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
		void ReleaseCompositionInputObject();
	public:
		CInteractionMarshaler(unsigned int);
		long SetInputSinkHelper(void *,bool *);
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long CaptureManipulationToCompositor(CApplicationChannel *,unsigned int,unsigned int,unsigned __int64);
		virtual long CapturePointer(CApplicationChannel *,unsigned int);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetDefaultConfiguration();
		virtual long SetHandleProperty(unsigned int,void *,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
		virtual ~CInteractionMarshaler();
	};

	class CInteractionTrackerMarshaler
	{
		CInteractionTrackerMarshaler::InteractionTrackerMarshalerFlag GetInertiaModifierMarshalerFlag(ScrollAxis);
		bool EmitApplyPositionImpulse(CBatch * *);
		bool EmitApplyPositionShift(CBatch * *);
		bool EmitApplyScaleImpulse(CBatch * *);
		bool EmitConfigureInternalProperties(CBatch * *);
		bool EmitDwmStarted(CBatch * *);
		bool EmitSetCallbackPropertyIdSet(CBatch * *);
		bool EmitSetInertiaDecayRates(CBatch * *);
		bool EmitSetInertiaModifierAnimations(CBatch * *);
		bool EmitSetManipulations(CBatch * *);
		bool EmitSetMaxPosition(CBatch * *);
		bool EmitSetMaxScale(CBatch * *);
		bool EmitSetMinPosition(CBatch * *);
		bool EmitSetMinScale(CBatch * *);
		bool EmitSetRequestedPosition(CBatch * *);
		bool EmitSetRequestedPositionAnimation(CBatch * *);
		bool EmitSetRequestedPositionDelta(CBatch * *);
		bool EmitSetRequestedScale(CBatch * *);
		bool EmitSetRequestedScaleAnimation(CBatch * *);
		long SetRequestedPositionAnimation(CApplicationChannel *,CBaseExpressionMarshaler *,bool *);
		long SetRequestedScaleAnimation(CApplicationChannel *,CBaseExpressionMarshaler *,bool *);
		void ReleaseManipulationReferences(CApplicationChannel *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		CInteractionTrackerMarshaler();
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CKeyframeAnimationMarshaler
	{
		bool EmitAddExpressionResources(CBatch * *);
		bool EmitSetKeyframeData(CBatch * *);
		bool EmitSetSeekState(CBatch * *);
		bool EmitUpdatePlaybackState(CBatch * *);
	protected:
		long UpdatePlaybackState(KeyframeAnimationPlaybackState::Enum);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceArrayProperty(CApplicationChannel *,unsigned int,CResourceMarshaler * *,unsigned __int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CLinearGradientBrushMarshaler
	{
		bool EmitUpdateTransformCommand(CBatch * *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool SetRemarshalingFlags();
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	struct CLinearObjectTableBase
	{
		long InsertObject(void *,unsigned int *);
		long InsertObject(void *,unsigned int);
		void * EnumerateObjects(unsigned __int64 *);
		void ReleaseHandle(unsigned int);
	};

	class CLinearTransferEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CManipulationMarshaler
	{
	protected:
		bool EmitSettings(CBatch * *);
		long SetBoolProperty(CApplicationChannel *,unsigned int,bool,bool *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CManipulationTransformMarshaler
	{
		bool EmitSetComponents(CBatch * *);
		bool EmitSetTracingCookie(CBatch * *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CMaskBrushMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool SetRemarshalingFlags();
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CMatrixTransform3DMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CMatrixTransformMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		void SetMatrixHelper(CApplicationChannel *,D2D_MATRIX_3X2_F const *,bool *);
	};

	class CNineGridBrushMarshaler
	{
		bool EmitUpdateInsetPropertyCommand(CBatch * *,CNineGridBrushMarshaler::NineGridBrushMarshalerFlag,unsigned long,float);
		bool EmitUpdateIsCenterHollowCommand(CBatch * *);
		bool EmitUpdateSourceCommand(CBatch * *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool SetRemarshalingFlags();
		virtual long Initialize();
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CNotificationResourceMarshaler
	{
	protected:
		virtual bool SetRemarshalingFlags();
		virtual long SetCallbackId(unsigned int,bool *);
	};

	class CNotifiedDeletionResource
	{
	protected:
		virtual long Initialize();
	public:
		virtual long Initialize(CDeletedNotificationList *);
		virtual long SetResourceLifetimeTag(unsigned __int64);
		virtual void ReturnResourceLifetimeTag(CDeletedNotificationList *);
	};

	class CPencilMarshaler
	{
		bool EmitBasicStateUpdate(CBatch * *);
		bool EmitSegmentCountUpdate(CBatch * *);
		bool EmitSegmentUpdate(CBatch * *);
		bool EmitStartPointUpdate(CBatch * *);
		long AddSegments(D2D1_PENCIL_SEGMENT const *,unsigned int,bool *);
		long RemoveSegmentsAtEnd(unsigned int,bool *);
		long SetSegments(unsigned int,D2D1_PENCIL_SEGMENT const *,unsigned int,bool *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool SetRemarshalingFlags();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CPrimitiveColorMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	struct CPrimitiveGroupLayerClipMarshaler
	{
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
	};

	class CPrimitiveGroupMarshaler
	{
		void ReleaseResourceMarshalers(CApplicationChannel *,CResourceMarshaler * *,unsigned int &);
	protected:
		virtual bool EmitAddPrimitivesCommand(CBatch * *);
		virtual bool EmitAppendColorResources(CBatch * *);
		virtual bool EmitAppendSurfaceResources(CBatch * *);
		virtual bool EmitClearColorResourcesCommand(CBatch * *);
		virtual bool EmitClearSurfaceResourcesCommand(CBatch * *);
		virtual bool EmitSetDirtyAndBoundsRectCommand(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsEarlyDestroyNotificationSupported();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceArrayProperty(CApplicationChannel *,unsigned int,CResourceMarshaler * *,unsigned __int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CProcessData
	{
		long Initialize();
	public:
		static CProcessData * Current();
		static long OnProcessCreation(_W32PROCESS *);
	};

	class CPropertyBagMarshaler
	{
		bool EmitSetBooleanProperty(CBatch * *,PropertyUpdate &);
		bool EmitSetColorProperty(CBatch * *,PropertyUpdate &);
		bool EmitSetMatrix3x2Property(CBatch * *,PropertyUpdate &);
		bool EmitSetMatrix4x4Property(CBatch * *,PropertyUpdate &);
		bool EmitSetProperties(CBatch * *);
		bool EmitSetQuaternionProperty(CBatch * *,PropertyUpdate &);
		bool EmitSetScalarProperty(CBatch * *,PropertyUpdate &);
		bool EmitSetVector2Property(CBatch * *,PropertyUpdate &);
		bool EmitSetVector3Property(CBatch * *,PropertyUpdate &);
		bool EmitSetVector4Property(CBatch * *,PropertyUpdate &);
		long AddPropertyUpdate(PropertyUpdate const *);
		long UpdatePropertyValue(PropertyUpdate const *,unsigned __int64);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CPropertyChangeResourceMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CRectangleClipMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual void SetRectangleHelper(CApplicationChannel *,D2D_RECT_F const *,bool *);
	};

	class CRenderTargetGroupMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetReferenceArrayProperty(CApplicationChannel *,unsigned int,CResourceMarshaler * *,unsigned __int64,bool *);
	};

	class CRenderTargetTargetMarshaler
	{
	protected:
		virtual bool EmitCreate(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool EmitUpdateTransform(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetHandleProperty(unsigned int,void *,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
	};

	class CResourceMarshaler
	{
	protected:
		bool EmitDeletionHelper(unsigned int,CBatch * *);
		bool EmitDuplicateHelper(CBatch * *,ResourceHandle);
		static bool EmitUpdateCommand<MILCMD_COLORBRUSH_SETCOLOR,<lambda_e67c0f3693897c6396872a06df71240e> >(CBatch * *,<lambda_e67c0f3693897c6396872a06df71240e> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM2D_SETANCHORPOINT,<lambda_07f550606503c46a5ddadc30f3af38e5> >(CBatch * *,<lambda_07f550606503c46a5ddadc30f3af38e5> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM2D_SETCENTERPOINT,<lambda_4216ace2a3a9ce7a95c5444156fe5754> >(CBatch * *,<lambda_4216ace2a3a9ce7a95c5444156fe5754> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM2D_SETOFFSET,<lambda_cdb35c6cdab0467f092d1c5f3e41d906> >(CBatch * *,<lambda_cdb35c6cdab0467f092d1c5f3e41d906> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM2D_SETROTATIONANGLE,<lambda_69ec054dab31664297bc4004e316ccaa> >(CBatch * *,<lambda_69ec054dab31664297bc4004e316ccaa> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM2D_SETSCALE,<lambda_6048ccecba1615198592d45635461d84> >(CBatch * *,<lambda_6048ccecba1615198592d45635461d84> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM2D_SETTRANSFORMMATRIX,<lambda_8e27e368b213886017cbcce0d374cdc4> >(CBatch * *,<lambda_8e27e368b213886017cbcce0d374cdc4> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM3D_SETANCHORPOINT,<lambda_ae326120eec07a33cfa3124b4300c4b1> >(CBatch * *,<lambda_ae326120eec07a33cfa3124b4300c4b1> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM3D_SETCENTERPOINT,<lambda_32f87ddeda71ec7c51647be65d6a8b51> >(CBatch * *,<lambda_32f87ddeda71ec7c51647be65d6a8b51> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM3D_SETORIENTATION,<lambda_0da63ec28eaf95972bb33284f20f15c0> >(CBatch * *,<lambda_0da63ec28eaf95972bb33284f20f15c0> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM3D_SETROTATIONANGLE,<lambda_1e56685df1004fc9203520070e26a5fd> >(CBatch * *,<lambda_1e56685df1004fc9203520070e26a5fd> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM3D_SETROTATIONAXIS,<lambda_a17fe493a9a3d244ffd1b2531b500889> >(CBatch * *,<lambda_a17fe493a9a3d244ffd1b2531b500889> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM3D_SETSCALE,<lambda_a2b9f137e6bd54fb770976a3249b25b0> >(CBatch * *,<lambda_a2b9f137e6bd54fb770976a3249b25b0> const &);
		static bool EmitUpdateCommand<MILCMD_COMPONENTTRANSFORM3D_SETTRANSFORMMATRIX,<lambda_952b6b000c999d04aa5713e06a78ee9c> >(CBatch * *,<lambda_952b6b000c999d04aa5713e06a78ee9c> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONAMBIENTLIGHT_SETCOLOR,<lambda_3a7d53e24e2750ef77c3f5162b86a6f4> >(CBatch * *,<lambda_3a7d53e24e2750ef77c3f5162b86a6f4> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONDISTANTLIGHT_SETCOLOR,<lambda_4699fdc5a14f149076d9c69ea67dcfaa> >(CBatch * *,<lambda_4699fdc5a14f149076d9c69ea67dcfaa> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONDISTANTLIGHT_SETCOORDINATESPACE,<lambda_6c97bdd75333e172b3f4469c63192950> >(CBatch * *,<lambda_6c97bdd75333e172b3f4469c63192950> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONDISTANTLIGHT_SETDIRECTION,<lambda_7beb449fb807bf00c7ae12db90743067> >(CBatch * *,<lambda_7beb449fb807bf00c7ae12db90743067> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONPOINTLIGHT_SETATTENUATION0,<lambda_a08c5b50be745393b97c31162c89a0e1> >(CBatch * *,<lambda_a08c5b50be745393b97c31162c89a0e1> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONPOINTLIGHT_SETATTENUATION1,<lambda_a4198d3d1e9f4798873a68f15acbfc3e> >(CBatch * *,<lambda_a4198d3d1e9f4798873a68f15acbfc3e> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONPOINTLIGHT_SETATTENUATION2,<lambda_f3eceb702d3bb95f35e8572466a46398> >(CBatch * *,<lambda_f3eceb702d3bb95f35e8572466a46398> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONPOINTLIGHT_SETCOLOR,<lambda_f7cd886f5d9d790c7912a5ea05224ba2> >(CBatch * *,<lambda_f7cd886f5d9d790c7912a5ea05224ba2> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONPOINTLIGHT_SETCOORDINATESPACE,<lambda_2f459d7b1de51fe0f6c48d211e4120f0> >(CBatch * *,<lambda_2f459d7b1de51fe0f6c48d211e4120f0> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONPOINTLIGHT_SETOFFSET,<lambda_0e3be02f44656b4d080e4e3876d13855> >(CBatch * *,<lambda_0e3be02f44656b4d080e4e3876d13855> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONSPOTLIGHT_SETATTENUATION0,<lambda_8cd7f403f38b7898ae24184497cca95e> >(CBatch * *,<lambda_8cd7f403f38b7898ae24184497cca95e> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONSPOTLIGHT_SETATTENUATION1,<lambda_2091914c1cf1803762948c2c2eb666c0> >(CBatch * *,<lambda_2091914c1cf1803762948c2c2eb666c0> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONSPOTLIGHT_SETATTENUATION2,<lambda_37d68d00375d3b30b1619e8b713d57c3> >(CBatch * *,<lambda_37d68d00375d3b30b1619e8b713d57c3> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONSPOTLIGHT_SETCOORDINATESPACE,<lambda_85ef3985c37784968b274c944d4fdc70> >(CBatch * *,<lambda_85ef3985c37784968b274c944d4fdc70> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONSPOTLIGHT_SETDIRECTION,<lambda_168d3da3d0f2960b32fb69d934910f4b> >(CBatch * *,<lambda_168d3da3d0f2960b32fb69d934910f4b> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONSPOTLIGHT_SETINNERCONEANGLE,<lambda_6b73664f286d64caf8bc4722c4f296c7> >(CBatch * *,<lambda_6b73664f286d64caf8bc4722c4f296c7> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONSPOTLIGHT_SETINNERCONECOLOR,<lambda_a54f22532ec0465d6c2327584066914c> >(CBatch * *,<lambda_a54f22532ec0465d6c2327584066914c> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONSPOTLIGHT_SETOFFSET,<lambda_4d51ba2affa0090bf5bed167bc03e4a4> >(CBatch * *,<lambda_4d51ba2affa0090bf5bed167bc03e4a4> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONSPOTLIGHT_SETOUTERCONEANGLE,<lambda_49ff8c4316bd9bc1691633b4f529c7cf> >(CBatch * *,<lambda_49ff8c4316bd9bc1691633b4f529c7cf> const &);
		static bool EmitUpdateCommand<MILCMD_COMPOSITIONSPOTLIGHT_SETOUTERCONECOLOR,<lambda_7a1338af5eb8b672e116a5a836624782> >(CBatch * *,<lambda_7a1338af5eb8b672e116a5a836624782> const &);
		static bool EmitUpdateCommand<MILCMD_DROPSHADOW_SETBLURRADIUS,<lambda_ca5ee11a4e4eac5ebce3be67c7f79afd> >(CBatch * *,<lambda_ca5ee11a4e4eac5ebce3be67c7f79afd> const &);
		static bool EmitUpdateCommand<MILCMD_DROPSHADOW_SETCOLOR,<lambda_0f65ccd11010066f3bf13d4ccdcefdb6> >(CBatch * *,<lambda_0f65ccd11010066f3bf13d4ccdcefdb6> const &);
		static bool EmitUpdateCommand<MILCMD_DROPSHADOW_SETMASK,<lambda_c3736e7ec6bdc5e1298df4c29b81c382> >(CBatch * *,<lambda_c3736e7ec6bdc5e1298df4c29b81c382> const &);
		static bool EmitUpdateCommand<MILCMD_DROPSHADOW_SETOFFSET,<lambda_3d0c5b44ea74fc7ebfe1dabea39653cd> >(CBatch * *,<lambda_3d0c5b44ea74fc7ebfe1dabea39653cd> const &);
		static bool EmitUpdateCommand<MILCMD_DROPSHADOW_SETOPACITY,<lambda_c6072fc4d5e24a2293318db97d0ceb0b> >(CBatch * *,<lambda_c6072fc4d5e24a2293318db97d0ceb0b> const &);
		static bool EmitUpdateCommand<MILCMD_EFFECTBRUSH_SETPROPERTYBAG,<lambda_9895c6ebf346605641fcd25f1dfabd39> >(CBatch * *,<lambda_9895c6ebf346605641fcd25f1dfabd39> const &);
		static bool EmitUpdateCommand<MILCMD_EFFECTBRUSH_SETTEMPLATE,<lambda_9f8ff668831ae9ab7eb87b24e54bd6e1> >(CBatch * *,<lambda_9f8ff668831ae9ab7eb87b24e54bd6e1> const &);
		static bool EmitUpdateCommand<MILCMD_LINEARGRADIENTBRUSH_SETENDPOINT,<lambda_0b89941aaa52e53b5580e8bdc4ffe38d> >(CBatch * *,<lambda_0b89941aaa52e53b5580e8bdc4ffe38d> const &);
		static bool EmitUpdateCommand<MILCMD_LINEARGRADIENTBRUSH_SETSTARTPOINT,<lambda_0b012e1993d2f99c17b34fc9d65df89a> >(CBatch * *,<lambda_0b012e1993d2f99c17b34fc9d65df89a> const &);
		static bool EmitUpdateCommand<MILCMD_LINEARGRADIENTBRUSH_SETSURFACE,<lambda_86f38ab5196f88825790a945019bd5ee> >(CBatch * *,<lambda_86f38ab5196f88825790a945019bd5ee> const &);
		static bool EmitUpdateCommand<MILCMD_MASKBRUSH_SETMASK,<lambda_b547dab8fd8be34540294d316fb3ac32> >(CBatch * *,<lambda_b547dab8fd8be34540294d316fb3ac32> const &);
		static bool EmitUpdateCommand<MILCMD_MASKBRUSH_SETSOURCE,<lambda_5fe80d6ba38c4e3de7e7f8dfe4d269b4> >(CBatch * *,<lambda_5fe80d6ba38c4e3de7e7f8dfe4d269b4> const &);
		static bool EmitUpdateCommand<MILCMD_NINEGRIDBRUSH_SETINSETPROPERTY,<lambda_4752416bf0de7d01d977e47fd81afe55> >(CBatch * *,<lambda_4752416bf0de7d01d977e47fd81afe55> const &);
		static bool EmitUpdateCommand<MILCMD_NINEGRIDBRUSH_SETISCENTERHOLLOW,<lambda_a9009d9e366029060374bab62bcea2b6> >(CBatch * *,<lambda_a9009d9e366029060374bab62bcea2b6> const &);
		static bool EmitUpdateCommand<MILCMD_NINEGRIDBRUSH_SETSOURCE,<lambda_bbbbfaf5e425b5858bd5aa190ce74ce9> >(CBatch * *,<lambda_bbbbfaf5e425b5858bd5aa190ce74ce9> const &);
		static bool EmitUpdateCommand<MILCMD_RECTANGLEGEOMETRY_SETBOTTOMINSET,<lambda_c9bfe3e300f4f487d2cc0aec257d29f7> >(CBatch * *,<lambda_c9bfe3e300f4f487d2cc0aec257d29f7> const &);
		static bool EmitUpdateCommand<MILCMD_RECTANGLEGEOMETRY_SETLEFTINSET,<lambda_5ed9830f15740f35f4074d41a83c2e4b> >(CBatch * *,<lambda_5ed9830f15740f35f4074d41a83c2e4b> const &);
		static bool EmitUpdateCommand<MILCMD_RECTANGLEGEOMETRY_SETRECTANGLE,<lambda_b077b7130a3859aa8305c9b673db2541> >(CBatch * *,<lambda_b077b7130a3859aa8305c9b673db2541> const &);
		static bool EmitUpdateCommand<MILCMD_RECTANGLEGEOMETRY_SETRIGHTINSET,<lambda_906b35406400a961726b3a3948cff082> >(CBatch * *,<lambda_906b35406400a961726b3a3948cff082> const &);
		static bool EmitUpdateCommand<MILCMD_RECTANGLEGEOMETRY_SETTOPINSET,<lambda_48736720202e4a1a68181a1e244f7701> >(CBatch * *,<lambda_48736720202e4a1a68181a1e244f7701> const &);
		static bool EmitUpdateCommand<MILCMD_SPRITEVISUAL_SETBRUSH,<lambda_2a2af4fb1cc3ff444cc7fd25e57813e8> >(CBatch * *,<lambda_2a2af4fb1cc3ff444cc7fd25e57813e8> const &);
		static bool EmitUpdateCommand<MILCMD_SPRITEVISUAL_SETSHADOW,<lambda_c0319cdccaf42ab5f4bab8df748e24c2> >(CBatch * *,<lambda_c0319cdccaf42ab5f4bab8df748e24c2> const &);
		static bool EmitUpdateCommand<MILCMD_SURFACEBRUSH_SETHORIZONTALALIGNMENT,<lambda_925acf38849121064d17ffe99330a147> >(CBatch * *,<lambda_925acf38849121064d17ffe99330a147> const &);
		static bool EmitUpdateCommand<MILCMD_SURFACEBRUSH_SETINTERPOLATIONMODE,<lambda_6e268feab3d7cd9521baed44fbcd0ae3> >(CBatch * *,<lambda_6e268feab3d7cd9521baed44fbcd0ae3> const &);
		static bool EmitUpdateCommand<MILCMD_SURFACEBRUSH_SETSTRETCH,<lambda_f9b8937c2670049a63a1d2fca267779f> >(CBatch * *,<lambda_f9b8937c2670049a63a1d2fca267779f> const &);
		static bool EmitUpdateCommand<MILCMD_SURFACEBRUSH_SETSURFACE,<lambda_7528276a618854590caf46d859c36d6d> >(CBatch * *,<lambda_7528276a618854590caf46d859c36d6d> const &);
		static bool EmitUpdateCommand<MILCMD_SURFACEBRUSH_SETTRANSFORM,<lambda_7d595d6cdb408b31b8835e05089e20ee> >(CBatch * *,<lambda_7d595d6cdb408b31b8835e05089e20ee> const &);
		static bool EmitUpdateCommand<MILCMD_SURFACEBRUSH_SETVERTICALALIGNMENT,<lambda_908be733ad79dc73949ff07cf103df35> >(CBatch * *,<lambda_908be733ad79dc73949ff07cf103df35> const &);
		static bool EmitUpdateCommand<MILCMD_VISUAL_SETTREEEFFECT,<lambda_a544e32b2e06f76f338d0d414fc3b7bd> >(CBatch * *,<lambda_a544e32b2e06f76f338d0d414fc3b7bd> const &);
		virtual long Initialize();
	public:
		bool HasAnimations(unsigned int);
		virtual CBaseAnimation * GetBaseAnimation();
		virtual bool EmitCreationCommand(CBatch * *);
		virtual bool EmitDeletionCommand(CBatch * *);
		virtual bool IsCrossChannelChildVisual();
		virtual bool IsCrossChannelParentVisual();
		virtual bool IsEarlyDestroyNotificationSupported();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize(CDeletedNotificationList *);
		virtual long OpenSharedHandle(void * *);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetCallbackId(unsigned int,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetHandleProperty(unsigned int,void *,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceArrayProperty(CApplicationChannel *,unsigned int,CResourceMarshaler * *,unsigned __int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
		virtual long SetResourceLifetimeTag(unsigned __int64);
		virtual void Disconnect(CApplicationChannel *);
		virtual void LinkVisualChild(CApplicationChannel *,CVisualMarshaler *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
		virtual void ReturnResourceLifetimeTag(CDeletedNotificationList *);
		virtual void UnlinkVisualChild(CApplicationChannel *,CVisualMarshaler *);
		void FindAnimationBindings(unsigned int,CAnimationBinding * *,CAnimationBinding * *,CAnimationBinding * *);
	};

	class CRotateTransform3DMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CRotateTransformMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CSaturationEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CScalarMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual DCOMPOSITION_EXPRESSION_TYPE GetExpressionType();
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CScaleTransform3DMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CScaleTransformMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CShadowEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CSharedInteractionMarshaler
	{
	protected:
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		static long Create(CSharedSystemResource const *,CSharedInteractionMarshaler * *);
		virtual bool EmitCreationCommand(CBatch * *);
		virtual long OpenSharedHandle(void * *);
	};

	class CSharedManipulationTransformMarshaler
	{
	protected:
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		static long Create(CSharedSystemResource const *,CSharedManipulationTransformMarshaler * *);
		virtual bool EmitCreationCommand(CBatch * *);
		virtual long OpenSharedHandle(void * *);
	};

	class CSharedMatrixTransform3DMarshaler
	{
	protected:
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		static long Create(CSharedSystemResource const *,CSharedMatrixTransform3DMarshaler * *);
		virtual bool EmitCreationCommand(CBatch * *);
		virtual long OpenSharedHandle(void * *);
	};

	class CSharedMatrixTransformMarshaler
	{
	protected:
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		static long Create(CSharedSystemResource const *,CSharedMatrixTransformMarshaler * *);
		virtual bool EmitCreationCommand(CBatch * *);
		virtual long OpenSharedHandle(void * *);
	};

	struct CSharedReadAnimationTriggerMarshaler
	{
		static long Create(CSharedSystemResource const *,CSharedReadAnimationTriggerMarshaler * *);
		virtual long InitializeFromSharedResource(CSharedSystemResource const *);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
	};

	struct CSharedReadBaseAnimationMarshaler
	{
		virtual CBaseAnimation * GetBaseAnimation();
		virtual CResourceMarshaler * GetResourceMarshaler();
		virtual DCOMPOSITION_EXPRESSION_TYPE GetExpressionType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
	};

	struct CSharedReadDesktopTargetMarshaler
	{
		static long Create(CSharedSystemResource const *,CSharedReadDesktopTargetMarshaler * *);
		virtual long InitializeFromSharedResource(CSharedSystemResource const *);
	};

	struct CSharedReadInteractionMarshaler
	{
		static long Create(CSharedSystemResource const *,CSharedReadInteractionMarshaler * *);
		virtual long InitializeFromSharedResource(CSharedSystemResource const *);
	};

	class CSharedReadMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool EmitCreationCommand(CBatch * *);
		virtual bool EmitDeletionCommand(CBatch * *);
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long InitializeFromSharedResource(CSharedSystemResource const *);
	};

	struct CSharedReadPrimitiveColorMarshaler
	{
		static long Create(CSharedSystemResource const *,CSharedReadPrimitiveColorMarshaler * *);
		virtual long InitializeFromSharedResource(CSharedSystemResource const *);
	};

	struct CSharedReadScalarMarshaler
	{
		static long Create(CSharedSystemResource const *,CSharedReadScalarMarshaler * *);
		virtual long InitializeFromSharedResource(CSharedSystemResource const *);
	};

	struct CSharedReadTransformMarshaler
	{
		static long Create(CSharedSystemResource const *,CSharedReadTransformMarshaler * *);
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long InitializeFromSharedResource(CSharedSystemResource const *);
	};

	class CSharedSectionMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		long InitializeSection(unsigned __int64,void * *);
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		void * CreateDwmHandle();
	};

	class CSharedSystemResource
	{
	protected:
		long Initialize(unsigned int);
		virtual CompositionObjectType GetType();
		virtual bool IsValid();
		virtual long Delete(_WIN32_DELETEMETHOD_PARAMETERS *);
		virtual void MarkInvalid();
	public:
		long OpenSharedHandle(void * *);
	};

	class CSharedWriteAnimationTriggerMarshaler
	{
	protected:
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		static long Create(CSharedSystemResource const *,CSharedWriteAnimationTriggerMarshaler * *);
		virtual bool EmitCreationCommand(CBatch * *);
		virtual long OpenSharedHandle(void * *);
	};

	class CSharedWriteDesktopTargetMarshaler
	{
	protected:
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		static long Create(CSharedSystemResource const *,CSharedWriteDesktopTargetMarshaler * *);
		virtual bool EmitCreationCommand(CBatch * *);
		virtual long OpenSharedHandle(void * *);
	};

	class CSharedWritePrimitiveColorMarshaler
	{
	protected:
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		static long Create(CSharedSystemResource const *,CSharedWritePrimitiveColorMarshaler * *);
		virtual bool EmitCreationCommand(CBatch * *);
		virtual long OpenSharedHandle(void * *);
	};

	class CSharedWriteScalarMarshaler
	{
	protected:
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		static long Create(CSharedSystemResource const *,CSharedWriteScalarMarshaler * *);
		virtual bool EmitCreationCommand(CBatch * *);
		virtual long OpenSharedHandle(void * *);
	};

	class CSkewTransformMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CSnapshotMarshaler
	{
	protected:
		virtual bool EmitTransform(CBatch * *);
		virtual bool EmitUpdate(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	};

	class CSpriteVisualMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual int GetDefaultBorderMode();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CSurfaceBrushMarshaler
	{
		bool EmitUpdateTransformCommand(CBatch * *);
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool SetRemarshalingFlags();
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class CSynchronizationManager
	{
	protected:
		static CCriticalSection * s_pSyncTableLock;
		static CGenericTable<unsigned __int64,CBatch,1702052676,0> * s_pSyncTable;
		static unsigned __int64 s_syncIdCounter;
	public:
		static long OnSessionCreation();
		static long Synchronize(CBatch *);
		static void NotifyPresent(unsigned __int64,bool);
		static void RemoveFromSynchronizationTable(CBatch *);
	};

	class CSystemChannel
	{
	protected:
		virtual CChannel::Type GetType();
	public:
		long DesktopCaptureBits(HMONITOR__ *,int,int,unsigned int,unsigned int,DXGI_FORMAT,void *,void *);
		long EnableMMCSS(int);
		long ForceRender(bool,bool,DwmHardwareTeardown::Enum);
		static long Create(CConnection *,CSystemChannel * *);
		void ReleaseSystemResource(ResourceHandle);
	};

	class CTableTransferEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		bool EmitTable(CBatch * *,unsigned int);
		long PropertyIdToColorChannelAndIndex(unsigned int,unsigned int *,unsigned int *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual ~CTableTransferEffectMarshaler();
	};

	class CTargetVisualMarshaler
	{
	protected:
		bool EmitRoot(CBatch * *);
		long UpdateRootVisual(CApplicationChannel *,CVisualMarshaler *,bool *);
		virtual bool EmitDeletionCommand(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		static long Create(CSharedSystemResource const *,CTargetVisualMarshaler * *);
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long InitializeFromSharedResource(CSharedSystemResource const *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
		virtual void LinkVisualChild(CApplicationChannel *,CVisualMarshaler *);
		virtual void UnlinkVisualChild(CApplicationChannel *,CVisualMarshaler *);
	};

	class CTelemetryInfo
	{
		bool EmitAnimationCommands(CBatch * *);
		bool EmitBeginInteractionCommands(CBatch * *);
		bool EmitEndInteractionCommands(CBatch * *);
		bool EmitUpdateInteractionCommands(CBatch * *);
	public:
		long AddInteractionBeginInfo(unsigned __int64,void const *);
		long AnimationScenarioBegin(unsigned __int64,void const *);
		long AnimationScenarioReference(_GUID const *,unsigned __int64 *);
		long AnimationScenarioUnreference(_GUID const *,unsigned __int64 *);
		long SetApplicationId(unsigned __int64,void const *);
	};

	class CTransform3DGroupMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetReferenceArrayProperty(CApplicationChannel *,unsigned int,CResourceMarshaler * *,unsigned __int64,bool *);
	};

	class CTransformGroupMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
		virtual void ReleaseAllReferences(CApplicationChannel *);
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetReferenceArrayProperty(CApplicationChannel *,unsigned int,CResourceMarshaler * *,unsigned __int64,bool *);
	};

	class CTranslateTransform3DMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CTranslateTransformMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
	};

	class CTurbulenceEffectMarshaler
	{
	protected:
		bool EmitData(CBatch * *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long Initialize();
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual unsigned int GetMaxInputs();
	};

	class CVisualMarshaler
	{
	protected:
		bool EmitClip(CBatch * *);
		bool EmitContent(CBatch * *);
		bool EmitEffect(CBatch * *);
		bool EmitInsertChildren(CBatch * *);
		bool EmitInteraction(CBatch * *);
		bool EmitOffset(CBatch * *);
		bool EmitOpacity(CBatch * *);
		bool EmitOptions(CBatch * *);
		bool EmitPendingRemoves(CBatch * *);
		bool EmitRelativeOffset(CBatch * *);
		bool EmitRelativeSize(CBatch * *);
		bool EmitRemoveAllChildren(CBatch * *);
		bool EmitRenderOptions(CBatch * *);
		bool EmitSize(CBatch * *);
		bool EmitTransform(CBatch * *);
		bool EmitTransformParent(CBatch * *);
		long SetTransformParent(CApplicationChannel *,CVisualMarshaler *,bool,bool *);
		virtual bool DetachFromParent(CApplicationChannel *);
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool IsAssociatedWithSystemVisual(ResourceHandle);
		virtual bool SetRemarshalingFlags();
		virtual int GetDefaultBorderMode();
		virtual void LinkVisualChild(CApplicationChannel *,CVisualMarshaler *);
		virtual void ReleaseAllReferences(CApplicationChannel *);
		virtual void UnlinkVisualChild(CApplicationChannel *,CVisualMarshaler *);
		void DiscardPendingChildRemoves(CApplicationChannel *);
		void ProcessFirstPendingRemove(CApplicationChannel *,void *);
		void SetVisible(CApplicationChannel *,bool);
		void UnlinkVisualChildInternal(CApplicationChannel *,CVisualMarshaler *);
	public:
		CCrossChannelParentVisualMarshaler * GetCrossChannelVisualChildNoRef(ResourceHandle);
		long RedirectMouseToHwnd(CApplicationChannel *,HWND__ *,tagMsgRoutingInfo const *,unsigned long,unsigned long);
		long SetClipRectangleHelper(CApplicationChannel *,void const *,unsigned __int64,bool *);
		long SetTransformMatrixHelper(CApplicationChannel *,void const *,unsigned __int64,bool *);
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual bool IsPropertyAnimatable(unsigned int,DCOMPOSITION_EXPRESSION_TYPE);
		virtual long AddChild(CApplicationChannel *,CVisualMarshaler *,int,CVisualMarshaler *,bool *);
		virtual long EnsureInteraction(CApplicationChannel *,bool,CInteractionMarshaler * *);
		virtual long GetFloatAnimatableProperty(unsigned int,float *);
		virtual long Initialize();
		virtual long RemoveAllChildren(CApplicationChannel *,bool *);
		virtual long RemoveChild(CApplicationChannel *,CVisualMarshaler *,bool *);
		virtual long SetBufferProperty(CApplicationChannel *,unsigned int,void const *,unsigned __int64,bool *);
		virtual long SetFloatProperty(unsigned int,float,bool *);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
		virtual void Disconnect(CApplicationChannel *);
	};

	class CYCbCrSurfaceMarshaler
	{
	protected:
		virtual bool EmitUpdateCommands(CBatch * *);
		virtual bool SetRemarshalingFlags();
	public:
		virtual MIL_RESOURCE_TYPE GetType();
		virtual bool IsOfType(MIL_RESOURCE_TYPE);
		virtual long SetIntegerProperty(CApplicationChannel *,unsigned int,__int64,bool *);
		virtual long SetReferenceProperty(CApplicationChannel *,unsigned int,CResourceMarshaler *,bool *);
	};

	class ResourceObject
	{
	protected:
		static long ObjectInit(CompositionObject *,void *,ICompositionObject * *);
		static long ResolveHandle(void *,unsigned long,char,ResourceObject * *);
	};

};

namespace DpiInternal
{
	bool operator>=(tagSIZE const &,tagSIZE const &);
	tagSIZE CalcDpi(tagSIZE const &,tagSIZE const &);
	tagSIZE CalcDpiOverride(tagSIZE const &,tagSIZE const &);
	unsigned int CalcDpi(unsigned int,unsigned int);
	unsigned long AdjustDesktopScaleFactorForOverride(unsigned long,tagSIZE,_DPI_SCALE_FACTOR_COLLECTION const *,int);
	unsigned long SatisfyMinResolutionBarForScaleIdx(int,int,tagSIZE,_DPI_SCALE_FACTOR_COLLECTION const * const);
	void ScaleOverrideTestHookCore(unsigned short const * const,unsigned long *);
};

struct DwmHitTestLeaveEnterCrit
{
	DwmHitTestLeaveEnterCrit();
	~DwmHitTestLeaveEnterCrit();
};

struct EBRUSHOBJ
{
	void vDelete();
	void vInitBrush(DC *,BRUSH *,XEPALOBJ,XEPALOBJ,SURFACE *,int);
};

struct EFLOAT
{
	EFLOAT eqCross(POINTFL const &,POINTFL const &);
	EFLOAT eqLength(POINTFL const &);
	int bIs1();
	int bIs16();
	int bIs1Over16();
	int bIsZero();
	void vSqrt();
};

struct ENTRYOBJ
{
	int bOwnedBy(unsigned long);
	static HOBJ__ * hSetup(OBJECT *,unsigned char,unsigned short,unsigned int);
};

struct EPALOBJ
{
	EPALOBJ(HPALETTE__ *);
	~EPALOBJ();
};

class EPATHOBJ
{
protected:
	_PATHRECORD * pprFlattenRec(_PATHRECORD *);
	int addpoints(EXFORMOBJ *,_PATHDATAL *);
	int createrec(EXFORMOBJ *,_PATHDATAL *,_POINTFIX *);
	int newpathrec(_PATHRECORD * *,unsigned long *,unsigned long);
	void growlastrec(EXFORMOBJ *,_PATHDATAL *,_POINTFIX *);
	void reinit();
public:
	int bAllClosed();
	int bAppend(EPATHOBJ *,_POINTFIX *);
	int bClone(EPATHOBJ &);
	int bCloseFigure();
	int bEnum(_PATHDATA *);
	int bFlatten();
	int bMoveTo(EXFORMOBJ *,_POINTL *);
	int bPolyBezierTo(EXFORMOBJ *,_POINTL *,unsigned long);
	int bPolyLineTo(EXFORMOBJ *,_POINTL *,unsigned long);
	unsigned long cTotalCurves();
	unsigned long cTotalPts();
	unsigned long cjSize();
	void vCloseAllFigures();
	void vFreeBlocks();
	void vOffset(EPOINTL &);
	void vUnlock();
};

struct ERECTFX
{
	void vInclude(_POINTFIX &);
};

struct ERECTL
{
	int bEmpty();
	int bEqual(ERECTL &);
	int bWrapped();
	void vOrder();
};

struct EXFORMOBJ
{
	EXFORMOBJ(unsigned long,unsigned long);
	int bComputeUnits(long,POINTFL *,EFLOAT *,EFLOAT *);
	int bEqualExceptTranslations(MATRIX *);
	int bInverse(MATRIX &);
	int bMultiply(MATRIX *,MATRIX *,unsigned long);
	int bXform(ERECTL &);
	int bXform(VECTORFL *,VECTORFL *,unsigned __int64);
	int bXform(_POINTFIX *,_POINTL *,unsigned __int64);
	int bXform(_POINTL *,_POINTFIX *,unsigned __int64);
	int bXform(_POINTL *,_POINTL *,unsigned __int64);
	int bXform(_VECTORFX *,_VECTORL *,unsigned __int64);
	int bXform(_VECTORL *,_VECTORFX *,unsigned __int64);
	int bXform(_VECTORL *,_VECTORL *,unsigned __int64);
	int bXformRound(_POINTL *,_POINTFIX *,unsigned __int64);
	void vComputeAccelFlags(unsigned long);
	void vGetCoefficient(_FD_XFORM *);
	void vGetCoefficient(_XFORML *);
	void vGetCoefficient(tagFLOATOBJ_XFORM *);
	void vInit(XDCOBJ &,unsigned long,int);
	void vOrder(_RECTL &);
	void vRemoveTranslation();
};

struct EnterLeaveCrit
{
	EnterLeaveCrit();
	~EnterLeaveCrit();
};

class GdiHandleEntryDirectory
{
	bool _RetrieveTableAndTableEntryIndex(unsigned int,GdiHandleEntryTable * *,unsigned int *);
public:
	_ENTRY * GetEntry(unsigned int,bool);
	bool AcquireEntryLock(unsigned int,bool);
	static GdiHandleEntryDirectory * Create(_ENTRY *,unsigned int);
	static void Destroy(GdiHandleEntryDirectory *);
	void ReleaseLockAndEntry(unsigned int,bool);
};

class GdiHandleEntryTable
{
	struct EntryDataLookupTable
	{
		bool Initialize(unsigned int);
		static EntryDataLookupTable * Create(unsigned int);
	};

	bool _IsEntryInUse(unsigned int);
	static GdiHandleEntryTable * _Create(unsigned int,bool);
public:
	OBJECT * GetEntryObject(unsigned int);
	bool AcquireEntryIndex(unsigned int *);
	bool AcquireEntryLock(unsigned int,bool);
	void ReleaseLockAndEntry(unsigned int,bool);
	void SetEntryObject(unsigned int,OBJECT *);
};

class GdiHandleManager
{
	void _IncrementOrDecrementUniqueness(OBJECT *,bool);
public:
	OBJECT * GetEntryObject(unsigned int);
	_ENTRY * GetEntryFromObject(OBJECT *);
	bool AcquireEntryIndex(unsigned int *);
	static GdiHandleManager * Create(unsigned int,_ENTRY *,unsigned int);
	static void Destroy(GdiHandleManager *);
	unsigned int DecodeIndex(unsigned int);
	unsigned int GetNextEntryIndex(unsigned int,_ENTRY * *);
	void SetEntryObject(unsigned int,OBJECT *);
};

class HANDLELOCK
{
	void vLockHandle(unsigned int,int,int);
public:
	HANDLELOCK(OBJECT *,int,int);
	int bLockHobj(HOBJ__ *,unsigned char);
	void Pid(unsigned long);
	void vUnlock();
	void vUnlockAndRelease();
};

struct HFDBASIS32
{
	long lError();
	long lParentErrorDividedBy4();
};

struct HFDBASIS64
{
	void vError(__int64 *);
	void vInit(long,long,long,long);
	void vParentError(__int64 *);
	void vUntransform(long *);
};

struct ICompositionObject
{
	virtual long Close(_WIN32_CLOSEMETHOD_PARAMETERS *);
	virtual long OkToClose(_WIN32_OKAYTOCLOSEMETHOD_PARAMETERS *);
	virtual long Open(_WIN32_OPENMETHOD_PARAMETERS *);
};

class IRegistrarClient_MsgCallInfo
{
	static unsigned char const * * MethodInstructions;
};

struct IRegistrarClient_Receive<CoreMessagingK::RegistrarClientThunk>
{
	static MsgCallInterfaceTableEntry const * const Interfaces;
	static MsgCallMethodDefinition const * const Methods;
	static MsgCallTypeDefinition const Type;
	static long Thunk_OnConversationServerReconnected_38(void *,void * *);
	static long Thunk_OnPendingConnectionTermination_3(void *,void * *);
	static long Thunk_OnProtocolException_0(void *,void * *);
	static long Thunk_Reply_AllocateWindowID_70(void *,void * *);
	static long Thunk_Reply_ClearWindowIDProperties_0(void *,void * *);
	static long Thunk_Reply_CloseConnection_18(void *,void * *);
	static long Thunk_Reply_CompleteCrossProcConnection_0(void *,void * *);
	static long Thunk_Reply_CompleteLocalConnection_0(void *,void * *);
	static long Thunk_Reply_ConnectPendingConversationClient_0(void *,void * *);
	static long Thunk_Reply_CrossProcClientDisconnected_18(void *,void * *);
	static long Thunk_Reply_FindConversationClient_61(void *,void * *);
	static long Thunk_Reply_FindCrossProcConnection_33(void *,void * *);
	static long Thunk_Reply_FindMessageObject_27(void *,void * *);
	static long Thunk_Reply_FindObject_20(void *,void * *);
	static long Thunk_Reply_FreeWindowID_0(void *,void * *);
	static long Thunk_Reply_GetWindowIDInfo_76(void *,void * *);
	static long Thunk_Reply_GetWindowIDProperties_82(void *,void * *);
	static long Thunk_Reply_LocalClientDisconnected_18(void *,void * *);
	static long Thunk_Reply_PrepareConnection_11(void *,void * *);
	static long Thunk_Reply_RegisterAlpcPort_18(void *,void * *);
	static long Thunk_Reply_RegisterConversation_3(void *,void * *);
	static long Thunk_Reply_RegisterObject_0(void *,void * *);
	static long Thunk_Reply_RegisterPendingConversationClient_51(void *,void * *);
	static long Thunk_Reply_RegisterReverseConnectionPort_18(void *,void * *);
	static long Thunk_Reply_RegisterThread_7(void *,void * *);
	static long Thunk_Reply_ReleaseConversationClient_0(void *,void * *);
	static long Thunk_Reply_SetWindowIDProperties_0(void *,void * *);
	static long Thunk_Reply_UnregisterAlpcPort_18(void *,void * *);
	static long Thunk_Reply_UnregisterConversation_0(void *,void * *);
	static long Thunk_Reply_UnregisterObject_0(void *,void * *);
	static long Thunk_Reply_UnregisterReverseConnectionPort_18(void *,void * *);
};

class IRegistrarServer_MsgCallInfo
{
	static unsigned char const * * MethodInstructions;
};

struct MALLOCOBJ
{
	MALLOCOBJ(unsigned long);
};

struct MDCOBJA
{
	MDCOBJA(HDC__ *);
};

struct MULTIDEVLOCKOBJ
{
	void vInit(_MDEV *);
	void vLock();
	void vUnlock();
};

struct NEEDGRELOCK
{
	void vLock(PDEVOBJ &);
	void vLock(XDCOBJ &);
	void vUnlock();
};

struct PALMEMOBJ
{
	int bCreatePalette(unsigned long,unsigned long,unsigned long *,unsigned long,unsigned long,unsigned long,unsigned long);
	~PALMEMOBJ();
};

class PATHALLOC
{
	static HSEMAPHORE__ * hsemFreelist;
	static PATHALLOC * freelist;
	static unsigned long cAllocated;
	static unsigned long cFree;
};

struct PATHMEMOBJ
{
	PATHMEMOBJ();
	~PATHMEMOBJ();
};

struct PDEVOBJ
{
	DHPDEV__ * EnablePDEV(_devicemodeW *,unsigned short *,unsigned long,HSURF__ * *,unsigned long,_GDIINFO *,unsigned long,tagDEVINFO *,HDEV__ *,unsigned short *,void *);
	PDEVOBJ(HDEV__ *,unsigned long);
	PDEVOBJ(_LDEV *,_devicemodeW *,unsigned short *,unsigned short *,unsigned short *,void *,tagREMOTETYPEONENODE *,_GDIINFO *,tagDEVINFO *,int,unsigned long,unsigned long);
	_LUID * pAdapterLuid();
	_LUID * pRenderAdapterLuid();
	int UpdateDisplayMode(_devicemodeW *);
	int bAllowShareAccess();
	int bDisabled(int);
	int bLddmDriver();
	int bMakeSurface(HSURF__ *);
	int bRenderLddmDriver();
	int bValid();
	tagSIZE sizl();
	unsigned long cFonts();
	unsigned long ulLogPixelsX();
	unsigned long ulLogPixelsY();
	void * pRenderAdapter();
	void CompletePDEV(DHPDEV__ *,HDEV__ *);
	void vClearSurface();
	void vDeleteHTPATSIZEUSERAllocations();
	void vDisableSurface(_CLEANUPTYPE,unsigned char);
	void vFilterDriverHooks();
	void vReferencePdev();
	void vSync(_SURFOBJ *,_RECTL *,unsigned long);
	void vUnreferencePdev(_CLEANUPTYPE);
};

class PalmTelemetry
{
	void _BufferPenPacket(tagHPD_CONTACT *,tagHPD_TYPE);
	void _DiscardOldTouchPackets(unsigned long);
	void _ProcessPenPacket(tagHID_POINTER_DEVICE_INFO *,tagHPD_CONTACT *,unsigned long,int);
	void _Report(unsigned long);
	void _ResetTelemetryData();
	void _TryBuffer(tagHPD_CONTACT *,tagHPD_TYPE);
public:
	void Update(tagHID_POINTER_DEVICE_INFO *,tagHPD_CONTACT *,int);
};

struct RBRUSH
{
	void vFreeOrCacheRBrush(RBTYPE);
};

class REGION
{
	static unsigned long ulUniqueREGION;
public:
	void vDeleteREGION();
};

struct RFONTOBJ
{
	void vReleaseCache();
	~RFONTOBJ();
};

class RGNMEMOBJ
{
	int bAddNullScan(long,long);
	int bAddScans(long,EDGE *,unsigned long);
	int bFastFill(EPATHOBJ &,long,_POINTFIX *);
	int bFastFillWrapper(EPATHOBJ &);
public:
	RGNMEMOBJ();
	RGNMEMOBJ(RGNMEMOBJ::DestructorDisposition);
	RGNMEMOBJ(int,int);
	RGNMEMOBJ(unsigned long);
	long iReduce(RGNOBJ &);
	void vCreate(EPATHOBJ &,unsigned long,_RECTL *);
	void vInitialize(unsigned long);
	void vPopThreadGuardedObject();
	void vPushThreadGuardedObject();
	~RGNMEMOBJ();
};

struct RGNMEMOBJTMP
{
	RGNMEMOBJTMP();
	RGNMEMOBJTMP(unsigned long);
	~RGNMEMOBJTMP();
};

class RGNOBJ
{
protected:
	int bIsResizeRequiredBeforeCopyingRegion(RGNOBJ &,unsigned long *);
public:
	int bContain(RGNOBJ &);
	int bCopy(RGNOBJ &);
	int bCreate(EPATHOBJ &,EXFORMOBJ *);
	int bDeleteRGNOBJ();
	int bEqual(RGNOBJ &);
	int bExpand(unsigned long);
	int bInside(_POINTL *);
	int bInside(_RECTL *);
	int bMerge(RGNOBJ &,RGNOBJ &,unsigned char);
	int bOffset(_POINTL *);
	int bOutline(EPATHOBJ &,EXFORMOBJ *);
	int bSet(unsigned long,_RECTL *);
	long iCombine(RGNOBJ &,RGNOBJ &,long);
	long iComplexity();
	unsigned long sizeSave();
	void UpdateUserRgn();
	void vCopy(RGNOBJ &);
	void vDeleteRGNOBJ();
	void vDownload(void *);
	void vGetSubRect(_RECTL *);
	void vSet();
	void vSet(_RECTL *);
	void vSwap(RGNOBJ *);
	void vTighten();
};

struct RGNOBJAPI
{
	RGNOBJAPI(HRGN__ *,int);
	int bCopy(RGNOBJ &);
	int bDeleteHandle();
	int bDeleteRGNOBJAPI();
	int bSwap(RGNOBJ *);
	long iCombine(RGNOBJ &,RGNOBJ &,long);
	~RGNOBJAPI();
};

class RIMDeadzone
{
	long _InitializeLeftHandedDeadzone();
	long _InitializeRightHandedDeadzone();
	static int _IsAngleWithinRange(unsigned long,tagRIMDEADZONE_RANGE);
	static unsigned long _GetAngle(tagPOINT,tagPOINT);
	static unsigned long const * const s_adwTangentLookup;
	void _ClearDeadzoneAreas();
public:
	int IsInDeadzone(tagHPD_CONTACT *);
	int IsInDeadzone(tagRECT,tagPOINT,tagPOINT,tagHANDEDNESS);
	long Initialize();
	long Initialize(tagRIMDEADZONE const *);
	long SetDeadzonePalmTelemetry();
	static RIMDeadzone * s_pRimDeadzoneInstance;
	void ActivateTelemetrySession(int);
	void Release();
};

struct RIMLOCKExclusiveIfNeeded
{
	RIMLOCKExclusiveIfNeeded(RIMLOCK *);
	~RIMLOCKExclusiveIfNeeded();
};

struct RawInputManagerObject
{
	static int bTouchInputAllowed;
	static tagHID_REQUEST_TABLE gHidRequestTable;
};

struct ReEnterLeaveCrit
{
	ReEnterLeaveCrit();
};

struct SEMOBJ
{
	void vUnlock();
	~SEMOBJ();
};

struct SEMOBJEX
{
	SEMOBJEX(HSEMAPHORE__ *,unsigned long,HSEMAPHORE__ *,unsigned long,HSEMAPHORE__ *,unsigned long,HSEMAPHORE__ *,unsigned long,HSEMAPHORE__ *,unsigned long,HSEMAPHORE__ *,unsigned long,HSEMAPHORE__ *,unsigned long,HSEMAPHORE__ *,unsigned long);
	~SEMOBJEX();
};

struct SEMOBJSHARED
{
	SEMOBJSHARED(HSEMAPHORE__ *);
	~SEMOBJSHARED();
};

class SFMLOGICALSURFACEREF
{
	void LockLogicalSurfaceObj(HLSURF__ *);
public:
	~SFMLOGICALSURFACEREF();
};

struct SPRITELOCK
{
	SPRITELOCK(PDEVOBJ &);
	~SPRITELOCK();
};

class SURFACE
{
	static unsigned __int64 tSize;
public:
	SFMLOGICALSURFACE * GetFirstLSurf();
	SURFACE::SurfaceMapStatus Map(void *,DC *);
	int bDIBSection();
	int bDeleteSurface(_CLEANUPTYPE,int);
	int bIncludeSprites();
	int bRedirectionBitmap();
	int bStockSurface();
	int bUnMap(void *,DC *);
	int bUnMapImmediate(void *,DC *);
	int bUndoStockSurfaceDelayed();
	static SURFACE * pdibDefault;
	void AddLSurf(SFMLOGICALSURFACE *);
	void RemoveLSurf(SFMLOGICALSURFACE *);
	void vAppContainerOwner(_EPROCESS *);
	void vClearIncludeSprites();
	void vDec_cRef();
	void vSetIncludeSprites();
};

struct SURFMEM
{
	int bCreateDIB(_DEVBITMAPINFO *,void *,void *,unsigned long,void *,unsigned __int64,int,int,int,int);
	~SURFMEM();
};

struct SURFREF
{
	int bDeleteSurface(_CLEANUPTYPE);
	~SURFREF();
};

struct SURFREFVIEW
{
	int bMap(_SURFOBJ *);
	int bUnMap();
	int bUnMapImmediate();
	~SURFREFVIEW();
};

struct SfmState
{
	int Initialize();
};

class SfmTokenArray
{
	long EnsureTokenBufferSize(unsigned int);
public:
	long AddNotificationToken(_D3DKMT_PRESENTHISTORYTOKEN *);
	long AddNotificationTokens(_D3DKMT_PRESENTHISTORYTOKEN *,unsigned int);
	long GetNotificationTokens(unsigned int,unsigned int *,_D3DKMT_PRESENTHISTORYTOKEN *);
	long TransferTokens(SfmTokenArray *);
	void DeInitialize();
	void Initialize();
};

class THREAD_GUARDED_EPATHOBJ
{
	static void vThreadCleanup(EPATHOBJ *);
};

struct UMPDOBJ
{
	static void vRelease(UMPDOBJ *,int);
};

class UserAtomicCheck
{
	void RegisterStack();
	void UnregisterStack();
public:
	UserAtomicCheck();
	~UserAtomicCheck();
};

struct W32PIDLOCK
{
	int bIsLocked();
	void vCleanUp();
	void vInit();
	void vLockSimple(unsigned long);
	void vLockSingleThread();
	void vUnlockSimple();
	void vUnlockSingleThread();
};

struct XCLIPOBJ
{
	void vSetup(REGION *,ERECTL &,int);
};

class XDCOBJ
{
	int bSaveAttributes();
	void RestoreAttributes();
public:
	int bCleanDC(int);
	int bDeleteDC(int);
	int bValid();
	void vAltUnlockFast();
	void vAltUnlockNoNullSet();
	void vFixPublicDCWithPrivateReferences(unsigned long);
	void vLock(HDC__ *);
	void vUnlock();
	void vUnlockFast();
	void vUnlockNoNullSet();
};

class XEBRUSHOBJ
{
protected:
	int bSaveAttributes();
	void RestoreAttributes();
};

struct XEPALOBJ
{
	int bDeletePalette(int,_CLEANUPTYPE);
	int bIsMonochrome();
	unsigned long ulDispatchGFPEFunction(GFPE_FUNCTION_ID,unsigned long);
	unsigned long ulGetMatchFromPalentry(tagPALETTEENTRY);
	unsigned long ulGetNearestFromPalentry(tagPALETTEENTRY,unsigned long);
	unsigned long ulGetNearestFromPalentryNoExactMatchFirst(tagPALETTEENTRY);
	unsigned long ulIndexToRGB(unsigned long);
	unsigned long ulTime();
	void apalResetColorTable();
	void vAddToList(XDCOBJ &);
	void vComputeCallTables();
	void vMakeNoXlate();
	void vRemoveFromList(XDCOBJ &);
	void vUnrefPalette(long);
	void vUpdateTime();
};

struct XEPATHOBJ
{
	XEPATHOBJ(HPATH__ *);
	~XEPATHOBJ();
};

struct tagLIST_TABLE_ITERATOR
{
	bool operator!=(tagLIST_TABLE_ITERATOR const &);
};

BRUSH * gpbrBackground;
BRUSH * gpbrDCBrush;
BRUSH * gpbrDCPen;
BRUSH * gpbrNull;
BRUSH * gpbrText;
CInputManager * g_pInputManager;
COLORSPACE * gpStockColorSpace;
CTokenManager * g_pTokenManager;
DCLEVEL dclevelDefault;
DHPDEV__ * MulEnablePDEV(_devicemodeW *,unsigned short *,unsigned long,HSURF__ * *,unsigned long,_GDIINFO *,unsigned long,tagDEVINFO *,HDEV__ *,unsigned short *,void *);
DwmState * g_pDwmState;
EDGE * AddEdgeToGET(EDGE *,EDGE *,_POINTFIX *,_POINTFIX *,_RECTL *);
EFLOAT ef16;
GdiHandleManager * gpHandleManager;
HBITMAP__ * hbmCreateClone(SURFACE *,unsigned long,unsigned long);
HBITMAP__ * hbmCreateDriverSurface(unsigned long,DHSURF__ *,tagSIZE,long,unsigned long,unsigned long,void *);
HCOLORSPACE__ * GreCreateColorSpace(_LOGCOLORSPACEEXW *);
HCOLORSPACE__ * ghStockColorSpace;
HDC__ * DxgkEngGetDCApiExt(HWND__ *,HDC__ * *);
HDEV__ * * DrvDisableDirectDrawForModeChange(_MDEV *,_MDEV *,HDEV__ * *,unsigned long);
HDEV__ * DrvCreateCloneHDEV(HDEV__ *,unsigned long);
HDEV__ * DrvSetSharedPalette(_MDEV *);
HDEV__ * DxgkEngLockVisRgnApiExt(HDC__ *);
HDEV__ * hCreateHDEV(tagGRAPHICS_DEVICE *,_DRV_NAMES *,_devicemodeW *,void *,unsigned long,unsigned long,int,int,unsigned long,HDEV__ * *);
HPALETTE__ * SelectPaletteWorker(XDCOBJ *,HPALETTE__ *,int);
HPALETTE__ * hForePalette;
HPALETTE__ * hpalMono;
HRGN__ * hrgnDefault;
HSEMAPHORE__ * GreEngLoadModuleAllocListLock;
HSEMAPHORE__ * MultiUserEngAllocListLock;
HSURF__ * MulEnableSurface(DHPDEV__ *);
MATRIX gmxIdentity_FxToL;
MATRIX gmxIdentity_LToFx;
MATRIX gmxIdentity_LToL;
PALETTE * gppalRGB;
PALETTE * ppalDefault;
PALETTE * ppalDefaultSurface8bpp;
PALETTE * ppalMono;
PDEV * gppdevATMFD;
PDEV * gppdevList;
PDEV * gppdevTrueType;
PEN * gpPenNull;
PFT * gpPFTPrivate;
POWER_MONITOR_REQUEST_REASON gWakeInProgressReason;
RBRUSH * gpCachedDbrush;
RBRUSH * gpCachedEngbrush;
REGION * prgnDefault;
RIMAB_TYPE gDeviceArbitrationType;
SURFACE * SURFOBJ_TO_SURFACE_NOT_NULL(void *);
SfmState * gpSfmState;
SfmState gSfmState;
UMPDSecurityLevel UMPDInitializeSecurityLevel();
UMPDSecurityLevel gUMPDSecurityLevel;
XLATE256 xloIdent;
_CIT_GLOBALS * g_CompatImpact;
_CIT_INTERACTION_SUMMARY * CitpInteractionSummaryEnsure(_CIT_IMPACT_CONTEXT *,_CIT_PROCESS *);
_CIT_PROG_DATA * CitpProcessEnsureProgData(tagPROCESSINFO *);
_CIT_PROG_DATA * CitpProcessGetProgData(tagPROCESSINFO *);
_CIT_PROG_DATA * CitpProgDataEnsure(_CIT_IMPACT_CONTEXT *,_CIT_PROGRAM_ID const *);
_CIT_PROG_DATA * CitpProgDataFind(_CIT_IMPACT_CONTEXT const *,_CIT_PROGRAM_ID const *);
_CIT_USE_DATA * CitpProcessGetUseData(tagPROCESSINFO *);
_CST_THREADS * gCSTParam;
_D3DKMT_ESCAPE_WIN32K_DDA_TEST gOutputDuplicationTestControl;
_D3DKMT_GETPATHSMODALITY * AllocPathsModality(unsigned short);
_DC_ATTR DcAttrDefault;
_DEVICE_OBJECT * gpDxgkDeviceObject;
_DRVFN * gadrvfnMulti;
_DUALVIEW_STATE CheckAndNotifyDualView(_UNICODE_STRING *,_MDEV *);
_DXGKWIN32KENG_INTERFACE gDxgkWin32kEngInterface;
_DXGKWIN32K_INTERFACE gDxgkInterface;
_ENTRY * gpentHmgr;
_EPROCESS * g_pepDwm;
_ETHREAD * gpPowerThread;
_FAST_MUTEX * gpPowerRequestMutex;
_FILE_OBJECT * gpDxgkFileObject;
_GUID CitpProcessGetAppSessionId(tagPROCESSINFO *);
_GUID const CitControlGuid;
_HANDLEPAGE gHandlePages;
_KEVENT * gpEventPowerRequest;
_KWAIT_BLOCK * gWaitBlockArray;
_LDEV * gpldevDrivers;
_LIST_ENTRY GreEngLoadModuleAllocList;
_LIST_ENTRY MultiUserGreEngAllocList;
_LIST_ENTRY gPowerRequestList;
_LUID * gpAdapterLuids;
_LUID luidPrevious;
_MDEV * DrvCreateMDEV(_UNICODE_STRING *,_devicemodeW *,void *,unsigned long,_MDEV *,unsigned long,int,int,_devicemodeW *,_D3DKMT_GETPATHSMODALITY *);
_MDEV * gbDeferredOrgMdev;
_PAL_LOGPALETTE logDefaultPal;
_PAL_ULONG * aPalDefaultVGA;
_POWER_WATCHDOG_TIMEOUT * gPowerWatchdogTimeouts;
_RECTL rclEmpty;
_RTL_GENERIC_COMPARE_RESULTS GDIEngUserMemAllocNodeCompare(_RTL_AVL_TABLE *,void *,void *);
_RTL_RUN_ONCE gMulEnableDriverInit;
_SYSTEM_GDI_DRIVER_INFORMATION gHidParseImageInfo;
_TERMINAL_DEVICE_FUNCTIONS gTTMDevCallbacks;
_UNICODE_STRING DefaultUserString;
_UNICODE_STRING PreviousUserString;
_W32PROCESS * hForePID;
_XLATETABLE * xlateTable;
__int64 * gpeqErrorLow;
__int64 W32kEtwUserCritAcquireDelayTimeoutQPC;
__int64 geqErrorHigh;
__int64 geqErrorLow;
_devicemodeW * GetClosestMode(tagGRAPHICS_DEVICE *,_devicemodeW *,int,int);
bool CitBaseUseDataValidate<CIT_PERSISTED_SYSTEM_DATA>(CIT_DATA_READER *,_CIT_PERSISTED_HEADER const *,CIT_PERSISTED_SYSTEM_DATA *,unsigned int,unsigned int *);
bool CitBaseUseDataValidate<CIT_PERSISTED_USE_DATA>(CIT_DATA_READER *,_CIT_PERSISTED_HEADER const *,CIT_PERSISTED_USE_DATA *,unsigned int,unsigned int *);
bool CitPersistedDataValidate(void const *,unsigned int,unsigned int *);
bool DevmodeAutoRotateCompatible(_devicemodeW const *,_devicemodeW const *);
bool IsAllowedToCallMiracast();
bool operator==(_LUID const &,_LUID const &);
int * pgbFinishDefGUIFontInit;
int AllowInteractiveServices();
int AreEquivalentDevModes(_devicemodeW const * const,_devicemodeW const * const);
int BuildDeviceHeader(unsigned char *,unsigned long,unsigned long *,unsigned short,unsigned short);
int BuildMainItem(unsigned char *,unsigned long,unsigned long *,tagUSAGE_PROPERTIES,tagUSAGE_PROPERTIES *,_HIDP_REPORT_TYPE,int *,unsigned long *);
int BuildReportDescriptor(unsigned short,unsigned short,tagUSAGE_PROPERTIES *,unsigned long,unsigned long,_HIDP_DEVICE_DESC *);
int BuildValueDeviceUsages(unsigned long,tagINPUT_INJECTION_VALUE * *,unsigned long *);
int BuildVendorDefinedCL(unsigned char *,unsigned long,unsigned long *);
int CSTPop(unsigned int *,void * *);
int CalculateDefaultPreferredModeFromEdid(_DEVICE_OBJECT *,tagModeCap *,unsigned char);
int CalculatePreferredModeFromEdid1(unsigned char *,_DEVICE_OBJECT *,tagModeCap *,unsigned char);
int CalculatePreferredModeFromEdid2(_EDID2 *,_DEVICE_OBJECT *,tagModeCap *,unsigned char);
int CitpAllowForegroundProcess(_CIT_IMPACT_CONTEXT const *);
int CitpGetForegroundWindowInfo(_CIT_WINDOW_INFO *,tagPROCESSINFO *,tagWND *);
int CitpProcessForegroundChange(tagPROCESSINFO *,tagWND *,tagPROCESSINFO *,tagMONITOR *,tagSHELL_INPUT_USAGE_DATA_INFO *);
int CitpSetForegroundProcess(_CIT_IMPACT_CONTEXT *,unsigned int,tagPROCESSINFO *,tagWND *,tagMONITOR *,tagSHELL_INPUT_USAGE_DATA_INFO *);
int ConvertDCPixelFormatToD3DDI(DISPLAYCONFIG_PIXELFORMAT,_D3DDDIFORMAT *);
int CreateSurfacePal(XEPALOBJ,unsigned long,unsigned long,unsigned long);
int DevmodeEqualEx(_devicemodeW const *,_devicemodeW const *);
int DisplayConfigModeSortSdcv1(void const *,void const *);
int DrvAddMirrorDriversToRemoteList();
int DrvCheckGraphicsDeviceForSmoothRotation(tagGRAPHICS_DEVICE *);
int DrvDisableDisplay(HDEV__ *,int);
int DrvDisableMDEVChildren(_MDEV *,int,unsigned long);
int DrvEnableDisplay(HDEV__ *);
int DrvGetPruneFlag(tagGRAPHICS_DEVICE *);
int DrvIsPermanentSettingChangesDisabled();
int DrvIsTemporarySettingChangeDisabled();
int DrvSetDisconnectedGraphicsDevice(int);
int DrvUpdateDisplayModeInMdev(_MDEV *,_D3DKMT_GETPATHSMODALITY *);
int DrvUpdateDisplayModeInPdev(HDEV__ *,_D3DKMT_GETPATHSMODALITY *);
int DxgkEngAdjustMonitorPosition(tagRECT *,unsigned int,unsigned int);
int DxgkEngAssertGdiOutput(void const * const,unsigned char const *,unsigned int,unsigned char *);
int DxgkEngBltViaGDIApiExt(_D3DKMT_PRESENT const *,HDC__ *,tagRECT const *,tagRECT const *,void * const,unsigned int,unsigned int,unsigned int,unsigned char,unsigned char,unsigned int,void (*)(tagRECT const *,tagRECT const *,tagRECT *,tagRECT const *,unsigned int,unsigned int),int (*)(tagRECT *,tagRECT *,tagRECT const *,tagRECT const *));
int DxgkEngDetectGDIPathApiExt(void const *,HDEV__ *,HWND__ *,HRGN__ *);
int DxgkEngFindViewDesktopPosition(_LUID const * const,unsigned int,_POINTL *);
int DxgkEngGetClientRectApiExt(HDC__ *,tagRECT * const);
int DxgkEngGetWindowRectApiExt(HWND__ *,tagRECT * const);
int DxgkEngIsDwmComposing(int *);
int DxgkEngIsDwmProcessApiExt();
int DxgkEngIsRedirectionDCApiExt(HDC__ *);
int DxgkEngIsRemoteConnection(int *);
int DxgkEngRefPresentHistoryToken(_D3DKMT_PRESENTHISTORYTOKEN *);
int DxgkEngReleaseDCApiExt(HDC__ *,HDC__ *);
int FLastGuiThread(tagTHREADINFO *);
int FilteredBitBlt(_SURFOBJ *,_SURFOBJ *,_SURFOBJ *,_CLIPOBJ *,_XLATEOBJ *,_RECTL *,_POINTL *,_POINTL *,_BRUSHOBJ *,_POINTL *,unsigned long);
int G_fConsole;
int G_fDoubleDpi;
int GetConfigUlong(unsigned short const *,unsigned short const *,unsigned long *);
int GetPreferredModeFromEdid(_DEVICE_OBJECT *,tagModeCap *,unsigned char);
int GetPrimaryAttachFlags(tagGRAPHICS_DEVICE *,unsigned short,unsigned long *,unsigned long *);
int GetValuesFromInf(_DEVICE_OBJECT *,unsigned long,tagModeCap *);
int GreEqualRgn(RGNOBJAPI &,RGNOBJAPI &);
int GreGetRandomRgnApiExt(HDC__ *,HRGN__ *,int);
int GreSelectVisRgnInternal(DCOBJA &,HRGN__ *,_VIS_REGION_SELECT);
int GreSetSolidBrushInternal(HBRUSH__ *,unsigned long,int,int);
int HMGrowHandleTable();
int HmgInitializeLookAsideList(unsigned long,unsigned long,unsigned long,unsigned short);
int IsCurrentProcessDwm();
int IsExtendedWinSqmHandle(_GUID *);
int IsHandleEntryAccessibleForIL(_HANDLEENTRY *);
int IsHandleEntrySecure(void *,_HANDLEENTRY *);
int IsRectEmptyInl(tagRECT const *);
int IsSessionDisabled(_GUID const *,unsigned long);
int MulEnableDriver(unsigned long,unsigned long,tagDRVENABLEDATA *);
int MulSetPalette(DHPDEV__ *,_PALOBJ *,unsigned long,unsigned long,unsigned long);
int NtGdiCloseProcess(unsigned long,_CLEANUPTYPE);
int OpenCollection(unsigned char *,unsigned long,tagHID_IDE_COL_TYPE,unsigned long *);
int ParseModeCap(unsigned short *,tagModeCap *,int);
int PruneMode(_devicemodeW *,tagModeCap *,int,_FREQUENCY_RAGE *,unsigned long);
int RIMIDEInjectionIndexToLinkIndex(RIMDEV *,unsigned long,unsigned short *,int);
int RIMShouldQuirkOnDeviceTargetingInformation(unsigned short const *,unsigned short const *);
int SetCollectionLabel(unsigned char *,unsigned long,unsigned long *);
int SetMultiByteValue(unsigned char *,unsigned long,unsigned long *,int *,unsigned long,unsigned long *);
int TransformOffscreenAdjacentRect(tagRECT *,tagRECT *,tagRECT *,unsigned long,unsigned long);
int TransformRectBetweenCoordinateSpacesPerMonitor(tagRECT *,tagRECT *,unsigned long,unsigned long,tagMONITOR *);
int UpdateUserScreen(int);
int UserGetRedirectedWindowOriginApiExt(HDC__ * const,tagPOINT *);
int ValidateMonFlags(unsigned long *);
int W32kCddClipRegionApiExt(void * const,void * const,_CLIPOBJ const *);
int W32kCddDisableGdiHwAccelerationApiExt();
int W32kCddIsNullBrushApiExt(_BRUSHOBJ *);
int W32kCddLineToApiExt(_SURFOBJ *,_CLIPOBJ *,_BRUSHOBJ *,long,long,long,long,_RECTL *,unsigned long,_W32KCDD_ENG_CALLBACKS *);
int W32kCddStrokePathApiExt(_SURFOBJ *,_PATHOBJ *,_CLIPOBJ *,_XFORMOBJ *,_BRUSHOBJ *,_POINTL *,_LINEATTRS *,unsigned long,_W32KCDD_ENG_CALLBACKS *);
int W32kGenerateMoveDataApiExt();
int Win32kNtUserCleanup();
int _DestroyMenuIfSupported(tagMENU *);
int bDeleteColorSpace(HCOLORSPACE__ *);
int bDeleteDCInternalWorker(XDCOBJ *,int,int,int);
int bDynamicIntersectVisRect(SURFACE *,tagSIZE);
int bDynamicMatchEnoughForModeChange(HDEV__ *,HDEV__ *);
int bFillFunctionTable(_DRVFN *,unsigned long,__int64 (**)());
int bIntersect(_RECTFX *,_RECTFX *);
int bIntersect(_RECTL const *,_RECTL const *,_RECTL *);
int bPEBCacheHandle(void *,_HANDLECACHETYPE,_OBJECTATTR *,_ENTRY *,HANDLELOCK *,_BASEOBJECT * *);
int bSetMagicColor(PDEVOBJ &,XEPALOBJ,unsigned long,_PAL_ULONG);
int bSetStockObject(void *,int,int);
int compModeCap(tagModeCap *,tagModeCap *);
int dumpLeaks(_LIST_ENTRY *,char *);
int dumpRimDevLeaksAndCleanup(_LIST_ENTRY *,char *);
int gAllowAppLiteRotationModeChange;
int gDebugPhoneInitRace;
int gDrvDpiAdjusted;
int gDrvDpiAdjustedForLoggedOnUser;
int gDrvDpiWin8Style;
int gForceDisconnect;
int gOldModeChange;
int g_bDwmIsShuttingDown;
int g_bLockUpdatesForDwm;
int gbBaseVideo;
int gbBuiltinPanelOn;
int gbBypassPresenterViewProcessCheck;
int gbDeferredInvalidateDualView;
int gbDisableCddRemoteSessionFiltering;
int gbDisableLddmSpriteTearDown;
int gbForceCddRemoteSessionBitmapSupport;
int gbGdiHmgrAltStacks;
int gbGdiHmgrStacks;
int gbInvalidateDualView;
int gbMultiMonMismatchColor;
int gbSetupDPIInitialized;
int gbTestModeOn;
int gbTouchOnUnmap;
int gbUpdateMonitor;
int gbUserInitialized;
int gfDwmDesktopOverlaysEnabled;
int gfDwmOverlayTestMode;
int ldevFillTable(_LDEV *,tagDRVENABLEDATA *,_LDEVTYPE);
int xxxDestroyWindowIfSupported(tagWND *);
long (* gpfnHidP_GetCaps)(_HIDP_PREPARSED_DATA *,_HIDP_CAPS *);
long (* gpfnHidP_GetCollectionDescription)(unsigned char *,unsigned long,_POOL_TYPE,_HIDP_DEVICE_DESC *);
long (* gpfnHidP_GetLinkCollectionNodes)(_HIDP_LINK_COLLECTION_NODE *,unsigned long *,_HIDP_PREPARSED_DATA *);
long (* gpfnHidP_GetScaledUsageValue)(_HIDP_REPORT_TYPE,unsigned short,unsigned short,unsigned short,long *,_HIDP_PREPARSED_DATA *,char *,unsigned long);
long (* gpfnHidP_GetSpecificButtonCaps)(_HIDP_REPORT_TYPE,unsigned short,unsigned short,unsigned short,_HIDP_BUTTON_CAPS *,unsigned short *,_HIDP_PREPARSED_DATA *);
long (* gpfnHidP_GetSpecificValueCaps)(_HIDP_REPORT_TYPE,unsigned short,unsigned short,unsigned short,_HIDP_VALUE_CAPS *,unsigned short *,_HIDP_PREPARSED_DATA *);
long (* gpfnHidP_GetUsageValue)(_HIDP_REPORT_TYPE,unsigned short,unsigned short,unsigned short,unsigned long *,_HIDP_PREPARSED_DATA *,char *,unsigned long);
long (* gpfnHidP_GetUsageValueArray)(_HIDP_REPORT_TYPE,unsigned short,unsigned short,unsigned short,char *,unsigned short,_HIDP_PREPARSED_DATA *,char *,unsigned long);
long (* gpfnHidP_GetUsages)(_HIDP_REPORT_TYPE,unsigned short,unsigned short,unsigned short *,unsigned long *,_HIDP_PREPARSED_DATA *,char *,unsigned long);
long (* gpfnHidP_SetUsageValue)(_HIDP_REPORT_TYPE,unsigned short,unsigned short,unsigned short,unsigned long,_HIDP_PREPARSED_DATA *,char *,unsigned long);
long (* gpfnHidP_SetUsages)(_HIDP_REPORT_TYPE,unsigned short,unsigned short,unsigned short *,unsigned long *,_HIDP_PREPARSED_DATA *,char *,unsigned long);
long (* gpfnHidP_UnsetUsages)(_HIDP_REPORT_TYPE,unsigned short,unsigned short,unsigned short *,unsigned long *,_HIDP_PREPARSED_DATA *,char *,unsigned long);
long (* gpfnHidP_UsageListDifference)(unsigned short *,unsigned short *,unsigned short *,unsigned short *,unsigned long);
long AllocateKernelSection(unsigned long,unsigned long,void * *);
long AllocateLocalSystemSid(void * *);
long AllocatePathModalityForDisplayConfig(unsigned int,DISPLAYCONFIG_PATH_INFO *,_D3DKMT_GETPATHSMODALITY * *);
long AllocateSharedSection(unsigned long,unsigned long,void * *,void * *,void * *);
long CheckInitialSessions();
long CheckProcessAndSessionState(_W32PROCESS *);
long CitpContextFlush(_CIT_IMPACT_CONTEXT *,unsigned int,int,void *);
long CitpContextStart(_CIT_IMPACT_CONTEXT *);
long CitpContextTrackingDataStart(_CIT_IMPACT_CONTEXT *);
long CitpContextUserLogon(_CIT_IMPACT_CONTEXT *,_LUID const *);
long CitpEnsureDataKey(void * *);
long CitpEnsureKey(void * *,unsigned short const *,bool);
long CitpInitialize(unsigned short const *);
long CitpParameterGetString(void *,unsigned short const *,unsigned short const * *);
long CitpPostUpdateUseInfoGetUpdateKey(unsigned int *);
long CitpPostUpdateUseInfoLoad(_CIT_IMPACT_CONTEXT *);
long CitpPostUpdateUseInfoOpenKey(_CIT_IMPACT_CONTEXT *,void * *);
long CitpPostUpdateUseInfoSave(_CIT_IMPACT_CONTEXT *,_CIT_POST_UPDATE_USE_INFO const *);
long CitpProcessEnsureContext(tagPROCESSINFO *);
long CitpProcessGetProgramId(tagPROCESSINFO *,_CIT_PROGRAM_ID *);
long CitpProgramIdCopy(_CIT_PROGRAM_ID *,_CIT_PROGRAM_ID const *);
long CitpRegistryGetValue(void *,unsigned short const *,_KEY_VALUE_PARTIAL_INFORMATION * *);
long CitpResetTracking();
long CitpSavedDataCompress(void const *,unsigned int,void * *,unsigned int *);
long CitpSavedDataDecompress(void const *,unsigned int,void * *,unsigned int *,_CIT_COMPRESSION_CALLBACKS const *);
long CitpSavedDataLoad(_CIT_IMPACT_CONTEXT *,void *,_CIT_SAVE_KEY const *);
long CitpSavedDataPrepare(_CIT_IMPACT_CONTEXT const *,_CIT_PERSISTED_HEADER * *,unsigned int *);
long CitpSavedDataPrune(void *);
long CitpSavedDataRead(void *,_CIT_SAVE_KEY const *,_KEY_VALUE_PARTIAL_INFORMATION * *);
long CitpShellTrackingGetEnabledForUser(unsigned char *);
long CitpStart();
long CitpStringDuplicate(unsigned short * *,unsigned short const *,unsigned __int64);
long CitpUpdateActiveBootId(unsigned int,unsigned char,unsigned short *,unsigned short *,void *);
long ComputeAdjacencyOverlap(tagRECT const *,tagRECT const *);
long ConvertDisplayConfigPathIntoExistingPathModalityAtIdx(DISPLAYCONFIG_PATH_INFO *,unsigned int,unsigned int,unsigned int,DISPLAYCONFIG_MODE_INFO *,unsigned int,int,_D3DKMT_GETPATHSMODALITY *,int *);
long ConvertDisplayConfigScalingToPathModalityForPath(DISPLAYCONFIG_PATH_INFO *,_D3DKMT_PATHMODALITY_DESCRIPTOR *,int *);
long ConvertDisplayConfigToPathModality(unsigned int,DISPLAYCONFIG_PATH_INFO *,unsigned int,DISPLAYCONFIG_MODE_INFO *,unsigned int,_D3DKMT_GETPATHSMODALITY *,int *);
long CoreMsgInitialize();
long CoreMsgObjectCallout(_WIN32_CALLOUTS_OPERATION,void *);
long CountInit;
long CreatePathPersistentMonitorsIfNeeded(unsigned int,_D3DKMT_GETPATHSMODALITY *,unsigned short *);
long DrvAddAdapterLuid(_LUID);
long DrvChangeDisplayFallback(void *,unsigned char,unsigned char,_MDEV *,_MDEV * *,_DXGK_DIAG_SDC_STAGE *,unsigned char *,long *);
long DrvChangeDisplaySettingsInternal(tagGRAPHICS_DEVICE *,_devicemodeW *,_D3DKMT_GETPATHSMODALITY *,void *,int,int,_MDEV *,_MDEV * *,unsigned long,int,int,int,_CDS_INTERNAL_FLAGS,_devicemodeW *,_devicemodeW * *);
long DrvCreatePathModalityFromAllPaths(_D3DKMT_GETPATHSMODALITY * *,unsigned int,_D3DKMT_GETPATHSMODALITY * *);
long DrvDriverExtraCallback(unsigned short *,unsigned long,void *,unsigned long,void *,void *);
long DrvDriverExtraSizeCallback(unsigned short *,unsigned long,void *,unsigned long,void *,void *);
long DrvDriverFailure();
long DrvForceChildDeviceReenumeration(_DEVICE_OBJECT *,_DEVICE_RELATIONS * *);
long DrvFunctionalizeBaseVidMode(_RETRY_MODE const &,_D3DKMT_GETPATHSMODALITY *);
long DrvGetCurrentDpiInfoFromHDC(HDC__ *,_DPI_INFORMATION * const);
long DrvGetDeviceFromNameAndValidateDevice(_UNICODE_STRING *,_MODE,tagGRAPHICS_DEVICE * *);
long DrvGetNumberOfPhysicalMonitors(tagGRAPHICS_DEVICE *,unsigned long *);
long DrvGetPreferredMode(_devicemodeW *,tagGRAPHICS_DEVICE *);
long DrvProbeAndCaptureDevmode(tagGRAPHICS_DEVICE *,_devicemodeW * *,int *,int *,_devicemodeW *,int,int,int,int,int,_devicemodeW *);
long DrvProcessWin32kEscape(_D3DKMT_ESCAPE *);
long DrvRemoveAdapterLuid(_LUID);
long DrvUpdateRemoteAdapterInfo(tagGRAPHICS_DEVICE *);
long DrvValidateAndApplyDevMode(_DISPLAYCONFIG_CDS_REQUEST *,_D3DKMT_GETPATHSMODALITY * *);
long DrvWriteAttachedSettings(unsigned long,unsigned short const *,_devicemodeW * const,int,unsigned long *);
long DrvWriteDisplayDriverParameters(tagGRAPHICS_DEVICE *,unsigned long,unsigned short const *,_devicemodeW * const,int,int);
long DxgkEngQueryWin32Info(_DXGK_QUERY_WIN32_INFO *);
long EtwpGetClassName(tagWND * const,_UNICODE_STRING *);
long GetTargetVirtualization(_LUID,unsigned int,unsigned char *,unsigned char *,_D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY *,_D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY *);
long InitializeRemoteSessionOcclusionEvent();
long MapKernelSectionForUserMapping(void *,_EPROCESS *,unsigned __int64,void * *);
long NotifyPendingCompositionBuffersPresent(int,_D3DKMT_PRESENTHISTORYTOKEN *);
long NotifyPendingFlipPresent(int,_D3DKMT_PRESENTHISTORYTOKEN *);
long NotifySurfaceOfSkippedToken(_D3DKMT_PRESENTHISTORYTOKEN const *);
long OPMCreateProtectedOutput(_DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS,_LUID &,unsigned long,void * *,int *);
long OPMDestroyProtectedOutput(void *);
long PnpNotifyForRemoteSession(void *,_DXGK_DISPLAY_SCENARIO_CONTEXT *);
long RIMOnTTMDeviceAssignedToTerminal(unsigned __int64,unsigned long);
long RIMOnTTMDeviceSetInputMode(unsigned __int64,_WIN32K_INPUT_MODE);
long ReadUlongFromKey(void *,unsigned short const *,unsigned long *);
long ReplacePreferredScaling(_D3DKMT_GETPATHSMODALITY const *,_D3DKMT_GETPATHSMODALITY *);
long ReserveUserSessionViewsWorker(void * *,void * *);
long RtlStringCbCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long RtlStringCbPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long RtlStringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long RtlStringCchPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long SetDPIinSetup(_DXGK_DISPLAY_SCENARIO_CONTEXT *);
long SignalPresentLimitSemaphore(_KSEMAPHORE *,long);
long StringCbCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCbLengthW(unsigned short const *,unsigned __int64,unsigned __int64 *);
long StringCchCopyNW(unsigned short *,unsigned __int64,unsigned short const *,unsigned __int64);
long StringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long UserInitialize();
long UserProcessImmersiveType(_WIN32_PROCESS_CALLOUT_PARAMETERS *,void *,_PROCESS_IMMERSIVE_TYPE *,unsigned long *,int *);
long UserSessionSwitchBlock_Start();
long ValidateBufferAttributes(CSM_BUFFER_ATTRIBUTES const &);
long ValidateSDCv1ModeInfoArray(_DISPLAYCONFIG_MODE_INFO_SUMMARY *,unsigned int,bool,unsigned int);
long W32kCddInitPdev(HDEV__ * const,void * const,unsigned int *,_devicemodeW * *,void * *);
long Win32kPnPDriverEntry(_DRIVER_OBJECT *,_UNICODE_STRING *);
long Win32kPnpNotify(_VIDEO_WIN32K_CALLBACKS_PARAMS *,_DXGK_DISPLAY_SCENARIO_CONTEXT *);
long _AddWin32TriageDataToDump(tagWIN32_TRIAGE_DATA *);
long _CreateCompositionInputSink(COMPOSITION_INPUT_SINK const *,int,void * *);
long __DisplayDriverQueryRoutine(unsigned short *,unsigned long,void *,unsigned long,void *,void *);
long __EnumDisplayQueryRoutine(unsigned short *,unsigned long,void *,unsigned long,void *,void *);
long gLastResumeResult;
long gProcessHandleQuota;
long gStockBitmapFree;
long volatile * DxgkEngGetAdapterUniquenessPointer();
long xxxDwmProcessShutdown(int);
long xxxDwmProcessStartup(void *);
long xxxUserChangeDisplaySettingsInternal(_UNICODE_STRING *,_devicemodeW *,tagDESKTOP *,unsigned long,void *,_MODE,int,_DXGK_DISPLAY_SCENARIO_CONTEXT *);
long xxxUserPowerEventCalloutWorker(_WIN32_POWEREVENT_PARAMETERS *);
long xxxUserPowerStateCalloutWorker();
tagAltStackTraceEntry * * gpentHmgrAltStacks;
tagGRAPHICS_DEVICE * GetGraphicsDeviceFromDevObjHandle(void * const);
tagGRAPHICS_DEVICE * gpGraphicsDeviceList;
tagGRAPHICS_DEVICE * gpGraphicsDeviceListLast;
tagGRAPHICS_DEVICE * gpLocalDiscGraphicsDevice;
tagGRAPHICS_DEVICE * gpLocalGraphicsDeviceList;
tagGRAPHICS_DEVICE * gpLocalGraphicsDeviceListLast;
tagGRAPHICS_DEVICE * gpRemoteDiscGraphicsDevice;
tagGRAPHICS_DEVICE * gpRemoteGraphicsDeviceList;
tagGRAPHICS_DEVICE * gpRemoteGraphicsDeviceListLast;
tagGRAPHICS_DEVICE * gpRemoteMirrorGraphicsDevice;
tagHPD_NORMALIZED_LIMITS_MAP * gNormalizedLimitMap;
tagLOGCOLORSPACEW gcsStockColorSpace;
tagMONITOR * AdjustDisplayMonitor(tagMONITOR *,tagRECT *);
tagMONITOR * CreateCachedMonitor();
tagMONITOR * CreateMonitor();
tagMONITOR * FindAdjacentMonitor(tagRECT const *,unsigned long);
tagMONITOR * SetMonitorData(tagMONITOR *,unsigned long);
tagPNP_NOTIFICATION_RECORD * gpPnpNotificationRecord;
tagPOINT ExpandMonitorSpaceVertex(int,unsigned short,tagPOINT);
tagPOWERREQUEST * UnqueuePowerRequest();
tagPOWERREQUEST * gpPowerRequestCurrent;
tagRECT ExpandedMonitorRect(tagMONITOR *,unsigned long);
tagREMOTE_CONTEXT gRemoteContext;
tagStackTraceEntry * * gpentHmgrStacks;
tagUSAGE_PROPERTIES * commonUsages;
tagUSAGE_PROPERTIES * penUsages;
tagUSAGE_PROPERTIES * touchUsages;
unsigned __int64 CitpProgramIdCalculateHash(_CIT_PROGRAM_ID const *);
unsigned __int64 gProximityLastPowerPressTime;
unsigned char * g_HIDCodes;
unsigned char * gafjRgnOp;
unsigned char * gpDevicesPerLuid;
unsigned char * gpRGBXlate;
unsigned char CitIsBufferSmallStatus(long);
unsigned char CitpIsInteractiveSession();
unsigned char CitpIsOnDefaultDesktop();
unsigned char CitpIsUserDesktopActive(_CIT_IMPACT_CONTEXT const *);
unsigned char CitpParametersCheckHostingProcess(_CIT_PARAMETERS *,unsigned short const *);
unsigned char CitpProgramIdIsEqual(_CIT_PROGRAM_ID const *,_CIT_PROGRAM_ID const *);
unsigned char IsMobileCore();
unsigned char IsPrimaryPathInCloneGroup(_D3DKMT_GETPATHSMODALITY const *,unsigned int);
unsigned char ShouldEscapeProximity();
unsigned char _AddMemoryBlockToList(tagWIN32_TRIAGE_DATA *,void *);
unsigned char _AddMemoryBlockToLiveTriageDump(tagWIN32_TRIAGE_DATA *,void *,unsigned long);
unsigned char const * const g_parameters_mCwZY_echToYaLbsOgJV5zVb_jw_IRegistrar;
unsigned char const NOT_ALERTABLE;
unsigned char gPowerWatchdogTest;
unsigned char gSystemIsAoAc;
unsigned char gWakeInProgress;
unsigned char gbRIMInitialized;
unsigned int * aArrayOfSquares;
unsigned int * pArrayOfSquares;
unsigned int CitPersistedDataComputeCrc(void const *,unsigned int);
unsigned int CitpUTCToMS(unsigned __int64,unsigned int);
unsigned int Convert16bitSdcModeInfoIdxTo32bit(unsigned short);
unsigned int DxgkEngGetRgnDataApiExt(HRGN__ *,unsigned int,_RGNDATA *);
unsigned int DxgkEngVisRgnUniq();
unsigned int GetCcdRawmodeFlag();
unsigned int W32kCddGetWin32kCommand(HDEV__ * const);
unsigned int giIcmGammaRange;
unsigned int giPnpSeq;
unsigned long (* dwOrientationDiffTable)[4];
unsigned long * gCacheHandleOffsets;
unsigned long * gaulMono;
unsigned long * laSize;
unsigned long DpiAwarenessContextFromMonitorFlags(unsigned long);
unsigned long DrvGetDriverAccelerationsLevel(tagGRAPHICS_DEVICE *);
unsigned long DrvGetDriverCapableOverRide(tagGRAPHICS_DEVICE *);
unsigned long EtwpGetThreadInfoFlags(tagTHREADINFO * const);
unsigned long EtwpGetWaitCursorType(tagCURSOR * const);
unsigned long GetMonitorCapability(_DEVICE_OBJECT *,tagModeCap *,_FREQUENCY_RAGE *,unsigned char);
unsigned long GetMonitorCapability1(unsigned char *,tagModeCap *,_FREQUENCY_RAGE *,unsigned char);
unsigned long GetMonitorCapability2(_EDID2 *,tagModeCap *,_FREQUENCY_RAGE *,unsigned char);
unsigned long GetMonitorCapabilityFromInf(_DEVICE_OBJECT *,tagModeCap *,unsigned char);
unsigned long GrepGetRegionPtrData(REGION *,unsigned long,_RGNDATA *);
unsigned long InsertModecapList(tagModeCap *,tagModeCap *,unsigned long);
unsigned long ParseReserved(unsigned short const *,unsigned short const *);
unsigned long PruneModesByDisplayDeviceCaps(tagGRAPHICS_DEVICE *,unsigned long,tagDEVMODEMARK *);
unsigned long RegisterWinSqmProvider();
unsigned long UnregisterWinSqmProvider();
unsigned long W32kEtwInputProcessDelayTimeoutMs;
unsigned long W32kEtwMessageCheckDelayTimeoutMs;
unsigned long W32kEtwUserActiveLastEventLogMs;
unsigned long W32kEtwUserCritAcquireDelayTimeoutMs;
unsigned long W32kEtwWaitCursorActiveType;
unsigned long W32kEtwWaitCursorProcessId;
unsigned long W32kEtwWaitCursorStartMs;
unsigned long W32kEtwWaitCursorThreadId;
unsigned long _ulGlobalSurfaceUnique;
unsigned long gPowerOnRequestCount;
unsigned long gProximityEscapeCount;
unsigned long gProximityPowerPressCount;
unsigned long gProximityScenarioCount;
unsigned long gcFailedModeChanges;
unsigned long gcLocalNextGlobalPhysicalOutputNumber;
unsigned long gcLocalNextGlobalVirtualOutputNumber;
unsigned long gcMaxHmgr;
unsigned long gcMaximumAdapterCount;
unsigned long gcModeChanges;
unsigned long gcNextGlobalPhysicalOutputNumber;
unsigned long gcNextGlobalVirtualOutputNumber;
unsigned long gcRemoteNextGlobalDeviceNumber;
unsigned long gcRemoteNextGlobalPhysicalOutputNumber;
unsigned long gcRemoteNextGlobalVirtualOutputNumber;
unsigned long gcdrvfnMulti;
unsigned long gdwDirectDrawContext;
unsigned long gdwPoolFlags;
unsigned long giSpriteUniqueness;
unsigned long giVisRgnUniqueness;
unsigned long giVisRgnUniquenessStable;
unsigned long gulCollectionOffset;
unsigned long gulGdiHmgrTraceObjectType;
unsigned long ldevGetDriverModes(tagGRAPHICS_DEVICE *,unsigned short const *,void *,_devicemodeW * *);
unsigned long ulGetMatchingIndexFromColorref(XEPALOBJ,XEPALOBJ,unsigned long);
unsigned long ulIndexedGetMatchFromPalentry(PALETTE *,unsigned long);
unsigned long ulTableIndex;
unsigned long ulXlatePalUnique;
unsigned long volatile gdwPnpNotificationRecSize;
unsigned long xwtol(unsigned short const *);
unsigned short * PreviousUserStringBuf;
unsigned short GetLanguageID();
unsigned short LogicalDpiFromMonFlags(unsigned long);
unsigned short gPreviousProtocolType;
unsigned short gdmLogPixels;
unsigned short gdmLogPixelsOfPrimary;
void (* gpfnHidP_FreeCollectionDescription)(_HIDP_DEVICE_DESC *);
void * * apObjects;
void * * gahStockObjects;
void * * gahStockObjects96;
void * * gpTmpGlobalFree;
void * * pHmgLookAsideList;
void * CitAllocRoutine(unsigned __int64);
void * CitAllocZero(unsigned __int64);
void * DrvGetRegistryHandleFromDeviceMap(tagGRAPHICS_DEVICE *,_DISP_DRIVER_REGISTRY_TYPE,unsigned long *,unsigned short *,unsigned long,long *,unsigned short);
void * GDIEngUserMemAllocNodeAlloc(_RTL_AVL_TABLE *,unsigned long);
void * HmgAllocateSecureUserMemory(void * *);
void * INVALID_MONITOR_HANDLE;
void * OPMAllocateMemory(unsigned __int64,_POOL_TYPE);
void * QLookaside;
void * gWinLogonRpcHandle;
void * g_pDwmApiPort;
void * ghModHidParse;
void * gpCountTable;
void * gpRequestQueueWatchdog;
void * gpRequestWorkerWatchdog;
void * gpTmpGlobal;
void ArmPowerWatchdog(void *,_POWER_WATCHDOG_TYPE);
void CancelPowerRequest(tagPOWERREQUEST *);
void CheckAppStarting(tagWND *,unsigned int,unsigned __int64,__int64);
void CitEtwEnableCallback(_GUID const *,unsigned int,unsigned __int64);
void CitFreeRoutine(void *);
void CitpBaseDataOutput<CIT_PERSISTED_SYSTEM_DATA,_CIT_SYSTEM_DATA>(_CIT_BASE_DATA_SAVE_CONTEXT *,CIT_PERSISTED_SYSTEM_DATA *,_CIT_SYSTEM_DATA const *);
void CitpBaseDataOutput<CIT_PERSISTED_USE_DATA,_CIT_USE_DATA>(_CIT_BASE_DATA_SAVE_CONTEXT *,CIT_PERSISTED_USE_DATA *,_CIT_USE_DATA const *);
void CitpBaseUseDataInitializeBitmaps<_CIT_USE_DATA>(_CIT_USE_DATA *,_CIT_BITMAP *);
void CitpBaseUseDataMerge<_CIT_SYSTEM_DATA>(_CIT_SYSTEM_DATA *,_CIT_SYSTEM_DATA const *);
void CitpBaseUseDataMerge<_CIT_USE_DATA>(_CIT_USE_DATA *,_CIT_USE_DATA const *);
void CitpBitmapInitialize(_CIT_BITMAP *,_CIT_BITMAP *,unsigned int);
void CitpBitmapMerge(_CIT_BITMAP *,_CIT_BITMAP const *);
void CitpBitmapUpdateBit(_CIT_BITMAP *,_CIT_TIME_CONTEXT const *);
void CitpBitmapUpdateBits(_CIT_BITMAP *,unsigned int,unsigned int);
void CitpBitmapUpdateForTimeRange(_CIT_BITMAP *,unsigned int,unsigned int);
void CitpBitmapUpdateForTimeRange(_CIT_BITMAP *,unsigned int,unsigned int,unsigned int,unsigned int);
void CitpBytesToString(void const *,unsigned int,unsigned short *);
void CitpCleanup();
void CitpCleanupGlobalImpactContext(_CIT_IMPACT_CONTEXT * *);
void CitpContextCleanup(_CIT_IMPACT_CONTEXT *);
void CitpContextInitialize(_CIT_IMPACT_CONTEXT *);
void CitpContextReinitialize(_CIT_IMPACT_CONTEXT *,unsigned int);
void CitpContextResetTrackingValues(_CIT_IMPACT_CONTEXT *,unsigned int);
void CitpContextTrackingDataCleanup(_CIT_IMPACT_CONTEXT *);
void CitpInputTimesAddTo(_CIT_INPUT_TIMES *,_CIT_INPUT_TIMES const *);
void CitpInteractionSummariesFlush(_CIT_IMPACT_CONTEXT *);
void CitpInteractionSummaryAllocate(_CIT_INTERACTION_SUMMARY * *);
void CitpInteractionSummaryDelete(_CIT_INTERACTION_SUMMARY * *);
void CitpInteractionSummaryStartTracking(_CIT_IMPACT_CONTEXT *,_CIT_INTERACTION_SUMMARY *);
void CitpInteractionSummaryStopTracking(_CIT_INTERACTION_SUMMARY *,unsigned int);
void CitpInvalidateAllWeakReferences();
void CitpLastInputUpdate(unsigned char,unsigned short,unsigned int);
void CitpLogFailureWorker(long,char const *,unsigned int);
void CitpLogoff(_CIT_IMPACT_CONTEXT *);
void CitpParameterGetInt32(void *,unsigned short const *,unsigned int *);
void CitpParametersCleanup(_CIT_PARAMETERS *);
void CitpParametersCompute(_CIT_PARAMETERS *);
void CitpParametersInitialize(_CIT_PARAMETERS *);
void CitpParametersLoad(_CIT_PARAMETERS *,unsigned short const *);
void CitpPostUpdateUseInfoCalculate(_CIT_IMPACT_CONTEXT *,_CIT_POST_UPDATE_USE_INFO *);
void CitpPostUpdateUseInfoLog(_CIT_IMPACT_CONTEXT *,unsigned int);
void CitpProgDataCleanup(_CIT_PROG_DATA *);
void CitpProgDataNotifyUseUpdate(_CIT_IMPACT_CONTEXT *,_CIT_PROG_DATA *);
void CitpProgDataReinitialize(_CIT_PROG_DATA *);
void CitpProgramIdCleanup(_CIT_PROGRAM_ID *);
void CitpSaveKeyFromString(_CIT_SAVE_KEY *,unsigned short *);
void CitpSaveKeyGet(_CIT_SAVE_KEY *,void *);
void CitpStatIncrement(unsigned short *,unsigned short);
void CitpTimeUpdate(unsigned int);
void CitpUpdateBootStats(_CIT_IMPACT_CONTEXT *);
void CleanUpRegion(REGION *);
void CleanupPowerWatchdog(void * *);
void ConvertPreferredScalingToAdapterDefault(_D3DKMT_GETPATHSMODALITY *);
void CoreMsgUninitialize();
void DbgPrintGDI(char *,...);
void DestroyBitmap(HBITMAP__ * *);
void DestroyBrush(HBRUSH__ * *);
void DestroyDC(HDC__ * *);
void DestroyEventHookIfSupported(tagEVENTHOOK *);
void DestroyFont(HFONT__ * *);
void DestroyHandleFirstPass(_HANDLEENTRY *);
void DestroyHandleSecondPass(_HANDLEENTRY *);
void DestroyKFIfSupported(tagKBDFILE *);
void DestroyKLIfSupported(tagKL *);
void DestroyProcessesObjects(tagPROCESSINFO *);
void DestroyRegion(HRGN__ * *);
void DestroySMWPIfSupported(tagSMWP *);
void DestroyUnlockedCursorIfSupported(void *);
void DisarmPowerWatchdog(void *);
void DisplayDiagRecordActiveTopology(USER_DETECTED_BLACK_SCREEN_REPORT *);
void DrvAcquireChangeDisplaySettingLocks();
void DrvAddEntryToGraphicsDeviceList(tagGRAPHICS_DEVICE *);
void DrvBackoutMDEV(_MDEV *,unsigned long);
void DrvCleanupGraphicsDeviceList(tagGRAPHICS_DEVICE *);
void DrvEnableDirectDrawForModeChange(HDEV__ * *,int);
void DrvGetDeviceConfigurationInformation(tagGRAPHICS_DEVICE *,void *,int);
void DrvLogDisplayDriverEvent(_DISP_DRIVER_LOG);
void DrvMoveGraphicsDevice(tagGRAPHICS_DEVICE *,tagGRAPHICS_DEVICE *,tagGRAPHICS_DEVICE *);
void DrvReleaseChangeDisplaySettingLocks();
void DrvSetSharedDevLock(_MDEV *);
void DrvSortGraphicsDeviceList();
void DrvTransferGdiObjects(HDEV__ *,HDEV__ *,unsigned long);
void DrvUpdateAttachFlag(tagGRAPHICS_DEVICE *,unsigned long);
void DrvUpdatePDevForWDDMDevice(PDEVOBJ);
void DrvUpdatePDevForWDDMVidPnSource(_LUID *,unsigned int);
void DxLddmCleanupAtProcessDestroy(unsigned long);
void DxLddmLogProcessPrimaryLockCount(unsigned long);
void DxLddmPrimaryLockCleanUpSinglePDev(PDEVOBJ *);
void DxgkEngAccumD3DPresentBoundsApiExt(HDC__ *,tagRECT const *);
void DxgkEngAcquireStableSpriteApiExt(void *,int);
void DxgkEngAcquireStableVisRgnApiExt(HDC__ *);
void DxgkEngAcquireWin32kAndPDEVLocks(void const * const,unsigned int);
void DxgkEngAddRedirBitmapD3DDirtyRgnApiExt(HDC__ *,tagCDDDXGK_REDIRBITMAPPRESENTINFO const *);
void DxgkEngEnterUserCrit(int);
void DxgkEngGetRedirBitmapSharedHandleApiExt(HDC__ *,void * *);
void DxgkEngReleaseStableSpriteApiExt(void *,int);
void DxgkEngReleaseStableVisRgnApiExt();
void DxgkEngReleaseWin32kAndPDEVLocks(void const * const,unsigned int);
void DxgkEngResetPointer();
void DxgkEngUnlockVisRgnApiExt(HDEV__ *);
void DxgkEngWatchVisRgnChangeApiExt(HDC__ *,int);
void EnforceSDCCloneSourceIndexCoherency(unsigned int,DISPLAYCONFIG_PATH_INFO *,unsigned int *);
void EnsureRequiredApiSetExtensions();
void EtwCaptureStateCallback();
void EtwpGetLastInputProcessTime(tagQ * const,unsigned long,unsigned long *,unsigned long *);
void EtwpSetTraceHeader(tagUIPI_TRACE_HEADER *,unsigned long,tagTHREADINFO *,tagPROCESSINFO *,tagTHREADINFO *,tagPROCESSINFO *);
void EtwpSetUIPIProcessInfo(tagUIPI_PROCESS_INFO *,tagTHREADINFO *,tagPROCESSINFO *);
void EtwpTraceUIPIError(_EVENT_DESCRIPTOR const *,void * const,unsigned long);
void FillDpiInfo(tagSIZE const &,tagSIZE const &,_DPI_SCALE_FACTOR_COLLECTION const *,unsigned int,unsigned int,unsigned int,int,_DPI_INFORMATION *);
void FillPhysicalDpiOnly(tagSIZE const &,tagSIZE const &,_DPI_INFORMATION *);
void FillSimpleDevModeField(_devicemodeW * const,_DXGK_DIAG_SIMPLE_DEVMODE *);
void FreeDdeXactIfSupported(tagXSTATE *);
void FreeDeviceInfoIfSupported(DEVICEINFO *);
void FreeHidDataIfSupported(tagHIDDATA *);
void FreeHookIfSupported(tagHOOK *);
void FreeInputContextIfSupported(tagIMC *);
void FreePathsModality(_D3DKMT_GETPATHSMODALITY *);
void FreePointerDeviceIfSupported(tagHID_POINTER_DEVICE_INFO *);
void GDIEngUserMemAllocNodeFree(_RTL_AVL_TABLE *,void *);
void GetRemoteScaleOverrideTestHook(unsigned short const *,unsigned __int64,_DPI_INFORMATION *);
void GreCleanupRemoteAdapterContext(tagREMOTE_CONTEXT *);
void GreSfmCleanupDxgAdapter(unsigned int);
void GreValidateRgnInDCSurfBounds(DC *,SURFACE *,REGION *,_VALIDATE_REGION_CALLER);
void GrepValidateVisRgn(DC *,REGION *);
void HMDoubleFree(void *);
void HMNullFnDestroy(void *);
void HmgFreeAllocateSecureUserMemory(void *,void *);
void HmgrStacksInit();
void InitPreviousUserString();
void InitUIPI();
void InitializeMonitorBrightnessDiagnosticsPacket(_DXGK_DIAG_MONITOR_BRIGHTNESS_PACKET_EX *,int);
void InitializeMonitorDpiRectsAndTransforms(tagMONITOR *,unsigned short);
void LogCodePointPacket(_DXGK_DIAG_CODE_POINT_TYPE,unsigned int,unsigned int,unsigned int);
void LogDiagCDS(_UNICODE_STRING *,_devicemodeW *,tagGRAPHICS_DEVICE *,void *,_MODE,int,int,unsigned long,int,int,unsigned __int64,long,long,_DXGK_DIAG_CDS_STAGE,unsigned int,_devicemodeW *);
void MarkImmersiveProcess(tagPROCESSINFO *,void *,_PROCESS_IMMERSIVE_TYPE);
void MulCompletePDEV(DHPDEV__ *,HDEV__ *);
void MulDisablePDEV(DHPDEV__ *);
void MulDisableSurface(DHPDEV__ *);
void MultiUserGreCleanupDrivers();
void MultiUserGreCleanupEngResources();
void MultiUserGreCleanupHmgOwnRemoveAllLocks(unsigned char);
void MultiUserGreCleanupHmgRemoveAllLocks(unsigned char);
void OPMFreeMemory(void *);
void ParseBits(unsigned long,unsigned long *,unsigned long *,unsigned long *,unsigned long);
void PowerDisplayBurst(POWER_MONITOR_REQUEST_REASON);
void PowerOffSession(POWER_MONITOR_REQUEST_REASON,_DXGK_DISPLAY_SCENARIO_CONTEXT *);
void PowerOnSession(POWER_MONITOR_REQUEST_REASON,_DXGK_DISPLAY_SCENARIO_CONTEXT *,_POWERON_LOC);
void ProcessKeyboardInputApiExt(DEVICEINFO *);
void ProcessMouseInputApiExt(DEVICEINFO *);
void QueryAllowAppLiteRotationModeChangeOverride();
void RECALTLOCKSTACKBACKTRACE(unsigned int,_BASEOBJECT *);
void RECALTUNLOCK(HOBJ__ *,_BASEOBJECT *);
void RECALTUNLOCKSTACKBACKTRACE(unsigned int);
void RECHMGRCREATE(HOBJ__ *,_BASEOBJECT *);
void RECSTACKBACKTRACE(unsigned int);
void RIMOnTTMDeviceClose(unsigned __int64);
void ResetOrg(HRGN__ *,tagDCE *,int);
void ResetSystemColors();
void SETFLAG(int,unsigned long volatile &,unsigned long);
void ScrubDelegatedWindows(tagTHREADINFO *);
void SetDwmApiPort(void *);
void SetInputMode(_WIN32K_INPUT_MODE);
void SetMonitorRegion(tagMONITOR *,HRGN__ *,HRGN__ *);
void SetProximityBlocking();
void TrackFullscreenMode(int);
void UpdateDisplayState(_MONITOR_DISPLAY_STATE,POWER_MONITOR_REQUEST_REASON,int,int);
void UpdateSessionPowerState(int,POWER_MONITOR_REQUEST_REASON);
void UpdateWindowTreeDpiAwareness(tagPROCESSINFO *,tagWND *);
void UserSessionSwitchBlock_End();
void W32kAcquireDynamicModeChangeLockShared();
void W32kCddIncPresentUniq();
void W32kReleaseDynamicModeChangeLockShared();
void W32kTraceLoggingEnableCallback(_GUID const *,unsigned long,unsigned char,unsigned __int64,unsigned __int64,_EVENT_FILTER_DESCRIPTOR *,void *);
void Win32KDriverUnload(_DRIVER_OBJECT *);
void Win32kNtUserCleanupInternal();
void _AddMListToLiveTriageDump(tagWIN32_TRIAGE_DATA *,tagMLIST *);
void _AddQToLiveTriageDump(tagWIN32_TRIAGE_DATA *,tagQ *);
void _AddThreadInfoToLiveTriageDump(tagWIN32_TRIAGE_DATA *,tagTHREADINFO *);
void _WinSqmDWORDEvent(_EVENT_DESCRIPTOR const *,_GUID *,unsigned long,unsigned long);
void rimInvalidateInputs(RIMDEV *);
void vBoundBox(_POINTFIX *,_RECTFX *);
void vChangeWndObjs(SURFACE *,HDEV__ *,SURFACE *,HDEV__ *);
void vCheckIsSetupRunning();
void vCleanupDCs(unsigned long);
void vCleanupRegions(unsigned long);
void vCleanupSurfaces(unsigned long,_CLEANUPTYPE);
void vDynamicSwitchPalettes(SURFACE *,PDEV *,PDEV *);
void vFreeKernelSection(void *);
void vGetDeviceCaps(PDEVOBJ &,_DEVCAPS *);
void vOffsetPoints(_POINTFIX *,_POINTFIX *,unsigned int,long,long);
void vReleaseCurrentpMapProcForSurfaces(_CLEANUPTYPE);
void vRemoveRefPalettes(unsigned long);
void vResetSurfacePalette(HDEV__ *);
void vTransferWndObjs(SURFACE *,HDEV__ *,HDEV__ *);
void vUMPDThreadCleanup(_W32THREAD *);
void vUnreferencePdevWorker(tagUNREFDATA *);
void xxxCleanupAndFreeDdeConvIfSupported(tagDDECONV *);
void xxxDisplayDiagBlackScreenDetected(unsigned int);
void xxxProcessHidInputApiExt(DEVICEINFO *);
void xxxWaitForVideoPortCalloutReady(unsigned char,unsigned char,_DXGK_DISPLAY_SCENARIO_CONTEXT *);
