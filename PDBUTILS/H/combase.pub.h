struct ASTAIncomingCallList
{
	void MergeFrom(ASTAIncomingCallList &);
};

struct ASTAState
{
	ASTAState();
};

class ASTAWaitContext
{
	struct ReleaseLockForCallout
	{
		ReleaseLockForCallout(ASTAWaitContext &);
	};

	struct SwitchIntoThreadDefaultContext
	{
		SwitchIntoThreadDefaultContext();
		~SwitchIntoThreadDefaultContext();
	};

	unsigned long CalculateNextQueuedCallTimeout();
	unsigned long KernelWait(unsigned int,void * const *,unsigned long,bool,ASTAWaitContext::ProcessEventsMsgWaitParams *,bool,unsigned long *);
	void AccountForReentryFromAlertableWait();
	void AdjustDispatchableCallsOnEnterOrExit();
	void DispatchAllSentMessages();
	void DispatchCallsOnExitNonBlockingProcessEventsIfAppropriate();
	void FlushAccumulatedWaitTimeToQueuedCalls(bool,unsigned long *,unsigned long,unsigned __int64);
	void HandleQueuedCallTimeouts();
	void NoteDroppedKeyboardMessage();
	void NoteDroppedMouseMessage();
	void NoteDroppedQueueSyncMessage();
	void PumpMessages();
	void RemoveAllInputMessagesAndDispatchAllSentMessages();
public:
	ASTAWaitContext(tagSOleTlsData *,BlockingReason,unsigned long,bool,bool,ASTAWaitWindowMessageDispatch);
	ObjectLibrary::ReferencedPtr<IMessageParam> RemoveOneDispatchableCall();
	ObjectLibrary::ReferencedPtr<IMessageParam> RemoveOneDispatchableCallOrWinrtAsyncMessage();
	bool CurrentQueueAttachmentConditionsRequireInputMessageSpecialHandling();
	bool HandlePriorityEvents();
	bool QueueAttachmentConditionsPossiblyRequireInputMessageSpecialHandling();
	unsigned long Wait(unsigned int,void * const *,unsigned long,ASTAWaitContext::ProcessEventsMsgWaitParams *,unsigned long *);
	void HandlePriorityEventsFromMessagePump();
	void RevertToNormalPointerInputMode();
	void SetOrClearDispatchableCallPendingAsAppropriate();
	void SetPointerInputModeAsAppropriateForQueueAttachmentConditions();
	~ASTAWaitContext();
};

struct ActivatableClassRegistrationEntryProperties
{
	~ActivatableClassRegistrationEntryProperties();
};

struct ActivationContext
{
	ActivationContext();
	long RuntimeClassInitialize(unsigned __int64,unsigned __int64,_GUID,unsigned __int64,unsigned long,unsigned char *);
	static TrustLevel InternalGetTrustLevel();
	static unsigned short const * InternalGetRuntimeClassName();
	virtual long GetIids(unsigned long *,_GUID * *);
	virtual long GetLpacAttributes(unsigned long *,unsigned char *);
	virtual long GetRuntimeClassName(HSTRING__ * *);
	virtual long GetTrustLevel(TrustLevel *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long get_ComponentProcessId(_GUID *);
	virtual long get_HostId(unsigned __int64 *);
	virtual long get_RacActivationTokenId(unsigned __int64 *);
	virtual long get_UserContext(unsigned __int64 *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct ActivationContextFactory
{
	virtual long ActivateInstance(IInspectable * *);
	virtual long CreateActivationContext(unsigned __int64,unsigned __int64,_GUID,unsigned __int64,unsigned long,unsigned char *,Windows::Foundation::IActivationContext * *);
	virtual long GetIids(unsigned long *,_GUID * *);
	virtual long GetRuntimeClassName(HSTRING__ * *);
	virtual long GetTrustLevel(TrustLevel *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class ActivationProperties
{
protected:
	long IsValidIID(_GUID const &);
public:
	ActivationProperties();
	long AddSerializableIfs(SerializableProperty *);
	long ReturnClass(_GUID const &,SerializableProperty *);
	long SetupForUnserializing(Serializer *);
	long UnSerializeCallBack(_GUID const &,SerializableProperty * *);
	virtual long DisconnectObject(unsigned long);
	virtual long GetCatalogObject(_GUID const &,void * *);
	virtual long GetLocalBlob(void * *);
	virtual long GetMarshalFlags(unsigned long *);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
	virtual long GetUnserialized(_GUID const &,void * *,unsigned long *,unsigned long *);
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long ReleaseMarshalData(IStream *);
	virtual long SetDestCtx(unsigned long);
	virtual long SetLocalBlob(void *);
	virtual long SetMarshalFlags(unsigned long);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~ActivationProperties();
	void SetSerializableIfs(unsigned long,SerializableProperty *);
};

struct ActivationPropertiesIn
{
	ActivationPropertiesIn(int);
	long GetContextInfo(ContextInfo * *);
	long GetExtensionActivationContextProperties(ExtensionActivationContextProperties * *);
	long GetInstantiationInfo(InstantiationInfo * *);
	long GetPersistInfo(InstanceInfo * *);
	long GetSecurityInfo(SecurityInfo * *);
	long GetServerLocationInfo(ServerLocationInfo * *);
	long GetSpecialProperties(SpecialProperties * *);
	long GetUserContextProperties(UserContextProperties * *);
	long GetWinRTActivationProperties(WinRTActivationProperties * *);
	virtual long AddRequestedIIDs(unsigned long,_GUID *);
	virtual long DelegateCIAndGetCF(IUnknown *,IActivationPropertiesOut * *,IClassFactory * *);
	virtual long DelegateCreateInstance(IUnknown *,IActivationPropertiesOut * *);
	virtual long DelegateGetClassObject(IActivationPropertiesOut * *);
	virtual long GetActivationFlags(unsigned long *);
	virtual long GetActivationID(_GUID *);
	virtual long GetCOMVersion(tagCOMVERSION *);
	virtual long GetClass(_GUID const &,SerializableProperty * *,int,int *);
	virtual long GetClassInfoW(_GUID const &,void * *);
	virtual long GetClientToken(void * *);
	virtual long GetClsctx(unsigned long *);
	virtual long GetClsid(_GUID *);
	virtual long GetDestCtx(unsigned long *);
	virtual long GetIndex(int *);
	virtual long GetRequestedIIDs(unsigned long *,_GUID * *);
	virtual long GetReturnActivationProperties(ActivationPropertiesOut * *);
	virtual long GetReturnActivationProperties(IUnknown *,IActivationPropertiesOut * *);
	virtual long GetStage(tagACTIVATION_STAGE *);
	virtual long PrivGetReturnActivationProperties(IPrivActivationPropertiesOut * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetActivationFlags(unsigned long);
	virtual long SetClassInfo(IUnknown *);
	virtual long SetClsctx(unsigned long);
	virtual long SetConstructFromFile(unsigned short *,unsigned long);
	virtual long SetContextInfo(IContext *,IContext *);
	virtual long SetStageAndIndex(tagACTIVATION_STAGE,int);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~ActivationPropertiesIn();
};

struct ActivationPropertiesOut
{
	struct OutSerializer
	{
		long ClearOutSerializer();
		virtual long GetCLSID(_GUID *);
		virtual long GetSize(void *,unsigned long *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual long SerializableQueryInterface(_GUID const &,void * *);
		virtual long Serialize(void *);
		virtual long UnSerialize(void *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		void ClearObject();
		void SetObject(IUnknown *,unsigned long);
		void UnmarshalAtIndex(unsigned long,bool);
	};

	ActivationPropertiesOut(int);
	virtual long Clear();
	virtual long GetActivationID(_GUID *);
	virtual long GetClass(_GUID const &,SerializableProperty * *,int,int *);
	virtual long GetMarshalledResults(unsigned long *,_GUID * *,long * *,tagMInterfacePointer * * *);
	virtual long GetObjectInterface(_GUID const &,unsigned long,void * *);
	virtual long GetObjectInterfaces(unsigned long,unsigned long,tagMULTI_QI *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RemoveRequestedIIDs(unsigned long,_GUID *);
	virtual long SetMarshalledResults(unsigned long,_GUID *,long *,tagMInterfacePointer * *);
	virtual long SetObjectInterfaces(unsigned long,_GUID *,IUnknown *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~ActivationPropertiesOut();
};

struct ApartmentShutdownNode
{
	ApartmentShutdownNode();
};

namespace ApiTelemetryLogger
{
	CArrayFValue gApiList;
	Microsoft::WRL::Wrappers::SRWLock gApiListLock;
	long FireEvent(bool);
	long LogApiCall(unsigned short const *);
	unsigned __int64 gLastEventTickCount;
	unsigned int SearchForIndexAndIncrementIfFound(unsigned __int64,int,int,bool *);
	unsigned int gDebuggedWinRTAppExponentialBackoffTimer;
	unsigned int gDesktopAppExponentialBackoffTimer;
	unsigned int gNumConsecutiveTimerEvents;
	unsigned int gNumForcedFireEvents;
};

struct ArrayOfGuids
{
	static ObjectLibrary::ReferencedPtr<ArrayOfGuids> Create(unsigned __int64,_GUID const *);
};

struct AstaTimedOutCallInfo
{
	AstaTimedOutCallInfo & operator=(AstaTimedOutCallInfo const &);
	AstaTimedOutCallInfo();
	~AstaTimedOutCallInfo();
};

struct AsyncActionCompletedHandlerFacade
{
	AsyncActionCompletedHandlerFacade(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,ObjectLibrary::ReferencedPtr<IWinrtAsyncChannelOperation> const &);
	virtual long Invoke(Windows::Foundation::IAsyncAction *,ABI::Windows::Foundation::AsyncStatus);
};

struct AsyncActionFacade
{
	virtual long GetResults();
	virtual long get_Completed(Windows::Foundation::IAsyncActionCompletedHandler * *);
	virtual long put_Completed(Windows::Foundation::IAsyncActionCompletedHandler *);
};

class AsyncClientCallRetryContext
{
	long CopyRequestMessageFromAutoRetryResponse(IAsyncClientTransport *,CAsyncCall *,_GUID const &,CStdIdentity *);
	long GetBuffer(CAsyncCall *,_GUID const &,CStdIdentity *);
	static void RetrySendOnTimerExpiration(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *);
public:
	AsyncClientCallRetryContext();
	long CancelRetry(IAsyncClientTransport *,unsigned long);
	long ReceiveWithRetry(IAsyncClientTransport *,ObjectLibrary::IComReferenceCounting *,CAsyncCall *,_GUID const &,CStdIdentity *);
	~AsyncClientCallRetryContext();
};

class AsyncComClientCall
{
protected:
	virtual bool UseAsyncTransportCall();
public:
	long TestCancel();
	virtual bool IsClientAsync();
	virtual bool IsClientAsyncAbiModel();
	virtual long CancelTransportCall(unsigned long);
	virtual long CreateTransportCallObject(tagRPCOLEMESSAGE const *,tagCALLCATEGORY,CChannelHandle *,unsigned long,tagCOMVERSION,CAsyncCall * *);
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
	virtual long Receive2(tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
	virtual long RegisterAsync(tagRPCOLEMESSAGE *,CChannelObject *);
	virtual long Send(tagRPCOLEMESSAGE *,CChannelObject *,unsigned long *);
	virtual long Send(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long Send2(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SendReceive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SendReceive2(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long TransportReceive(unsigned long *);
	virtual long TransportSend();
	virtual void OnCancelRequestRequiringAcknowledgment();
	virtual void OnClientEventSignalRequiringReset();
	virtual void OnCompletedCallWithUnknownClientEventSignalStatus();
	virtual void OnRetryCanceled();
	virtual void OnRetryFailed(long);
	virtual void OnSyncCallCompletedWithOutstandingRpcCancel();
	virtual void OnTransportCallCompletionReceived();
	virtual void OnWaitSatisifiedByClientEventSignal();
};

class AsyncComServerCall
{
	long Send2(tagRPCOLEMESSAGE *,unsigned long *);
public:
	virtual bool IsServerAsyncAbiModel();
	virtual long RegisterAsync(tagRPCOLEMESSAGE *);
	virtual long Send(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long StubInvoke(IRpcChannelBuffer *,IRpcStubBuffer *,unsigned long *);
	virtual void Finalize();
	virtual void RelockServerIfNeeded();
	virtual void ReportServerFault(unsigned long);
	virtual void ReportStubInvokeFailure(long);
	virtual void TraceServerCallStart(ServerCallTracingInfo const &);
	virtual void TraceServerCallStop(unsigned long);
	void DeleteServerCtxCall();
};

struct AsyncDelegateStorage
{
	AsyncDelegateStorage & operator=(AsyncDelegateStorage const &);
	long ResolveDelegate(_GUID const &,void * *);
	~AsyncDelegateStorage();
};

struct AsyncOperationStorage
{
	AsyncOperationStorage & operator=(AsyncOperationStorage const &);
	AsyncOperationStorage(IAgileReference *,CObjectContext *,WinrtAsyncServerContinuationMessage *,bool);
	void ClearContinuationMessage();
	~AsyncOperationStorage();
};

struct AutoBlob
{
	long Initialize(tagBLOB const &);
	~AutoBlob();
};

struct BaseAsyncHandlerFacade<IGenericAsyncCompletedHandler,0>
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~BaseAsyncHandlerFacade<IGenericAsyncCompletedHandler,0>();
};

struct BaseAsyncHandlerFacade<Windows::Foundation::IAsyncActionCompletedHandler,0>
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~BaseAsyncHandlerFacade<Windows::Foundation::IAsyncActionCompletedHandler,0>();
};

class BaseAsyncOperationFacade<IGenericAsyncActionWithProgress>
{
protected:
	BaseAsyncOperationFacade<IGenericAsyncActionWithProgress>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,ObjectLibrary::ReferencedPtr<IWinrtAsyncChannelOperation> const &,unsigned long);
	virtual ~BaseAsyncOperationFacade<IGenericAsyncActionWithProgress>();
public:
	virtual long Cancel();
	virtual long Close();
	virtual long GetIids(unsigned long *,_GUID * *);
	virtual long GetRuntimeClassName(HSTRING__ * *);
	virtual long GetTrustLevel(TrustLevel *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long get_ErrorCode(long *);
	virtual long get_Id(unsigned int *);
	virtual long get_Status(ABI::Windows::Foundation::AsyncStatus *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class BaseAsyncOperationFacade<IGenericAsyncOperation>
{
protected:
	BaseAsyncOperationFacade<IGenericAsyncOperation>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,ObjectLibrary::ReferencedPtr<IWinrtAsyncChannelOperation> const &,unsigned long);
	virtual ~BaseAsyncOperationFacade<IGenericAsyncOperation>();
public:
	virtual long Cancel();
	virtual long Close();
	virtual long GetIids(unsigned long *,_GUID * *);
	virtual long GetRuntimeClassName(HSTRING__ * *);
	virtual long GetTrustLevel(TrustLevel *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long get_ErrorCode(long *);
	virtual long get_Id(unsigned int *);
	virtual long get_Status(ABI::Windows::Foundation::AsyncStatus *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class BaseAsyncOperationFacade<IGenericAsyncOperationWithProgress>
{
protected:
	BaseAsyncOperationFacade<IGenericAsyncOperationWithProgress>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,ObjectLibrary::ReferencedPtr<IWinrtAsyncChannelOperation> const &,unsigned long);
	virtual ~BaseAsyncOperationFacade<IGenericAsyncOperationWithProgress>();
public:
	virtual long Cancel();
	virtual long Close();
	virtual long GetIids(unsigned long *,_GUID * *);
	virtual long GetRuntimeClassName(HSTRING__ * *);
	virtual long GetTrustLevel(TrustLevel *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long get_ErrorCode(long *);
	virtual long get_Id(unsigned int *);
	virtual long get_Status(ABI::Windows::Foundation::AsyncStatus *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class BaseAsyncOperationFacade<Windows::Foundation::IAsyncAction>
{
protected:
	BaseAsyncOperationFacade<Windows::Foundation::IAsyncAction>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,ObjectLibrary::ReferencedPtr<IWinrtAsyncChannelOperation> const &,unsigned long);
	virtual ~BaseAsyncOperationFacade<Windows::Foundation::IAsyncAction>();
public:
	virtual long Cancel();
	virtual long Close();
	virtual long GetIids(unsigned long *,_GUID * *);
	virtual long GetRuntimeClassName(HSTRING__ * *);
	virtual long GetTrustLevel(TrustLevel *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long get_ErrorCode(long *);
	virtual long get_Id(unsigned int *);
	virtual long get_Status(ABI::Windows::Foundation::AsyncStatus *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class BuiltInClassCache
{
	static void DeleteTree(_RTL_SPLAY_LINKS *);
};

struct CAbstractMarshalingStream
{
	virtual long QueryInterface(_GUID const &,void * *);
};

class CAbstractStream
{
protected:
	virtual long Clone(IStream * *);
	virtual long Commit(unsigned long);
	virtual long CopyTo(IStream *,_ULARGE_INTEGER,_ULARGE_INTEGER *,_ULARGE_INTEGER *);
	virtual long GetMarshalingContextAttribute(CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long LockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Revert();
	virtual long Stat(tagSTATSTG *,unsigned long);
	virtual long UnlockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CActivatableClassIdHashTable
{
	unsigned long Hash(unsigned short const *);
	virtual int Compare(void const *,SHashChain *,unsigned long);
};

struct CActivatableClassRegistration
{
	virtual long Activate(Windows::Foundation::IActivationContext *,IInspectable * *);
	virtual long FinalConstruct(IWinRTRuntimeClassInfo *);
	virtual long get_ActivatableClassId(HSTRING__ * *);
	virtual long get_Attributes(Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
	virtual long get_RegisteredTrustLevel(TrustLevel *);
	virtual long get_RegistrationScope(Windows::Foundation::RegistrationScope *);
	virtual ~CActivatableClassRegistration();
};

struct CActivationStore
{
	virtual long GetActivatableClassRegistration(HSTRING__ *,HSTRING__ *,Windows::Foundation::IActivatableClassRegistration * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAddrControl
{
	virtual long DisableCOMDynamicAddrTracking();
	virtual long EnableCOMDynamicAddrTracking();
	virtual long GetCurrentAddrExclusionList(_GUID const &,void * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long UpdateAddrExclusionList(IUnknown *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CAddrExclusionList
{
	void FreeCurrentBuffers();
public:
	long AddrExclListInitialize2(IEnumString *,unsigned long);
	virtual long Clone(IEnumString * *);
	virtual long Next(unsigned long,unsigned short * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CAggId
{
	long CreateHandler(_GUID const &);
	long IsImplementedInterface(_GUID const &,void * *);
public:
	CAggId(_GUID const &,EffectiveUnmarshalingPolicy,unsigned long,long &);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long QueryMultipleInterfaces(unsigned long,tagMULTI_QI *);
	virtual long SetHandler(IUnknown *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CAgileReferenceMarshaled
{
	CAgileReferenceMarshaled(tagOBJREF *,tagOBJREF *,CComApartment *,CObjectContext *);
	virtual long Resolve(_GUID const &,void * *);
	virtual ~CAgileReferenceMarshaled();
};

struct CAgileReferenceToAgileObject
{
	virtual long Resolve(_GUID const &,void * *);
};

struct CAgileReferenceViaGit
{
	virtual long Resolve(_GUID const &,void * *);
};

class CApartmentActivator
{
	virtual long ContextCallHelper(IActivationPropertiesIn *,IActivationPropertiesOut * *,long (*)(void *),CObjectContext *);
	virtual long ContextSelector(IActivationPropertiesIn *,int &,CObjectContext * &);
public:
	virtual long CreateInstance(IUnknown *,IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long GetClassObject(IActivationPropertiesIn *,IActivationPropertiesOut * *);
};

class CApartmentHashTable
{
	long GetOrCreateApartmentEntry(unsigned long,bool,ApartmentEntry * &);
	static COleStaticMutexSem _mxsAptTblLock;
public:
	long GetOrCreateCOMActivatorForCurrentApartment(bool,unsigned long &);
	long GetOrCreateWinRTActivatorForCurrentApartment(bool,unsigned long &);
	void RevokeActivatorsForCurrentApartment();
};

struct CAptCallCtrl
{
	CAptCallCtrl();
};

struct CArrayFValue
{
	int InsertAt(int,void *,int);
	int SetAtGrow(int,void *);
	int SetSize(int,int);
	~CArrayFValue();
};

class CAsyncCall
{
	static bool s_bInitialized;
	virtual ~CAsyncCall();
public:
	bool TryClientAddRefRpcFreeDeferral();
	long CallI_RpcAsyncAbortCall(unsigned long);
	long CallI_RpcAsyncSetHandle(_GUID const &);
	long CallI_RpcAsyncSetHandle(_RPC_MESSAGE *);
	long CallI_RpcReceive(_GUID const &);
	long CallI_RpcSend(_GUID const *);
	long CallSent();
	long CancelClientAsyncCall(unsigned long);
	long CancelClientSyncCall(int,unsigned long);
	long IdempotentCallI_RpcReceiveAndByteSwapReplyHeader(_GUID const &,WireThat * *);
	long Receive(_GUID const &,unsigned long *);
	long Send(ServerCall *,_GUID const &,CStdIdentity *);
	long ServerSubscribeForCancelationNotification();
	static void ServerCancelationCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_WAIT *,long);
	virtual bool IsCallCanceled();
	virtual bool UseRpcNotificationEvent();
	virtual int HasWOWMsgArrived();
	virtual int IsCallCompleted();
	virtual int IsCallDispatched();
	virtual int IsCancelIssued();
	virtual int IsClientWaiting();
	virtual long AdvCancel();
	virtual long CallI_RpcFreeBuffer();
	virtual long CanDispatch();
	virtual long Cancel(int,unsigned long);
	virtual long GetState(unsigned long *);
	virtual long OutofprocServerGetResponseBuffer(_GUID const &);
	virtual long TestCancel();
	virtual void * GetRpcNotificationEvent();
	virtual void AckCancel();
	virtual void AsyncServerMarkCallCompletedAndSignal();
	virtual void CallFinished();
	virtual void MarkCallCompletedWithResult(long);
	virtual void ServerReply();
	void ServerUnsubscribeForCancelationNotification();
};

class CAsyncStateMachine
{
	long InitObject(IUnknown *);
public:
	long AbortBegin(IUnknown *,long);
	long EnterBegin(IUnknown *);
	long EnterFinish(IUnknown *);
};

class CAsyncUnknownMgr
{
	struct CPrivUnknown
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
	};

	virtual long IBegin_QueryMultipleInterfaces(unsigned long,tagMULTI_QI *);
	virtual long IFinish_QueryMultipleInterfaces(tagMULTI_QI *);
	virtual long QueryInterfaceImpl(_GUID const &,void * *);
public:
	CAsyncUnknownMgr(IUnknown *,_GUID const &,_GUID const &,CStdIdentity *,CClientCallMgr *,long &,IUnknown * *);
	virtual long Begin_AddRef();
	virtual long Begin_QueryInterface(_GUID const &);
	virtual long Begin_QueryMultipleInterfaces(unsigned long,tagMULTI_QI *);
	virtual long Begin_Release();
	virtual long Finish_QueryInterface(void * *);
	virtual long Finish_QueryMultipleInterfaces(tagMULTI_QI *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long ResetStateForCall();
	virtual unsigned long AddRef();
	virtual unsigned long Finish_AddRef();
	virtual unsigned long Finish_Release();
	virtual unsigned long Release();
	~CAsyncUnknownMgr();
};

class CAuthInfo
{
	static int _fNeedSSL;
	static tagSOLE_AUTHENTICATION_LIST * _sList;
public:
	static long Copy(tagSOLE_AUTHENTICATION_LIST *,tagSOLE_AUTHENTICATION_LIST * *,unsigned long);
	static void * Find(tagSECURITYBINDING *);
};

class CBaseCall
{
	static unsigned int s_uCurrentCallTraceId;
public:
	static ClientCall * RetrieveCallObjectFromMessageAs<ClientCall>(tagRPCOLEMESSAGE const *);
	static ServerCall * RetrieveCallObjectFromMessageAs<ServerCall>(tagRPCOLEMESSAGE const *);
};

class CBaseMInterfacePointerMarshalingStream
{
protected:
	CBaseMInterfacePointerMarshalingStream(tagMInterfacePointer *);
	virtual unsigned __int64 get_Size();
	virtual ~CBaseMInterfacePointerMarshalingStream();
public:
	virtual long Read(void *,unsigned long,unsigned long *);
	virtual long Seek(_LARGE_INTEGER,unsigned long,_ULARGE_INTEGER *);
	virtual long SetSize(_ULARGE_INTEGER);
	virtual long Write(void const *,unsigned long,unsigned long *);
};

class CBaseMarshalingStreamOnBuffer
{
protected:
	virtual unsigned __int64 get_Size();
public:
	virtual long Read(void *,unsigned long,unsigned long *);
	virtual long Seek(_LARGE_INTEGER,unsigned long,_ULARGE_INTEGER *);
	virtual long SetSize(_ULARGE_INTEGER);
	virtual long Write(void const *,unsigned long,unsigned long *);
};

class CCOMSurrogate
{
	static ISurrogate * _pSurrogate;
	static int _fNewStyleSurrogate;
public:
	static long FreeSurrogate();
	static long InitializeISurrogate(ISurrogate *);
	static long LoadDllServer(_GUID const &);
};

struct CCache
{
	long AddElement(unsigned long,unsigned char *,unsigned short,unsigned short *,IUnknown *,IUnknown * *);
	long AddElement(unsigned long,unsigned short,unsigned char * *,unsigned short const *,unsigned short *,IUnknown *,IUnknown * *);
	long Flush(unsigned short);
	long GetElement(unsigned long,unsigned char *,unsigned short,unsigned short *,IUnknown * *);
	long GetElement(unsigned long,unsigned short,unsigned char * *,unsigned short const *,unsigned short *,IUnknown * *);
};

class CCallTable
{
	long SetEntry(ICancelMethodCalls *,bool);
public:
	std::pair<Microsoft::WRL::ComPtr<ICancelMethodCalls>,bool> GetEntry(unsigned long);
	void PopCallObject(ICancelMethodCalls *);
};

class CChannelHandle
{
	long InitializeBindingHandle(OXIDEntry const *);
public:
	CChannelHandle(CChannelHandle const *,OXIDEntry const *,bool,long *);
	CChannelHandle(unsigned long,unsigned long,unsigned long,OXIDEntry *,long *);
	long AdjustToken(unsigned long,int *,void * *);
	long SetDoNotDisturb(unsigned __int64);
	long SetSuppressWake(unsigned __int64);
	void RestoreToken(int,void *);
};

class CChannelObject
{
	void AutoComplete();
public:
	CChannelObject(CClientCallMgr *,CClientChannel *);
	virtual long Cancel(unsigned long);
	virtual long CopyProxy(IUnknown *,IUnknown * *);
	virtual long FreeBuffer(tagRPCOLEMESSAGE *);
	virtual long GetBuffer(tagRPCOLEMESSAGE *,_GUID const &);
	virtual long GetDestCtx(unsigned long *,void * *);
	virtual long GetDestCtxEx(tagRPCOLEMESSAGE *,unsigned long *,void * *);
	virtual long GetProtocolVersion(unsigned long *);
	virtual long IsConnected();
	virtual long NegotiateSyntax(tagRPCOLEMESSAGE *);
	virtual long QueryBlanket(IUnknown *,unsigned long *,unsigned long *,unsigned short * *,unsigned long *,unsigned long *,void * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long Send(tagRPCOLEMESSAGE *,ISynchronize *,unsigned long *);
	virtual long SendReceive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SetBlanket(IUnknown *,unsigned long,unsigned long,unsigned short *,unsigned long,unsigned long,void *,unsigned long);
	virtual long TestCancel();
	void Signal();
};

struct CClassCache
{
	struct CCEHashTable
	{
		CClassEntry * LookupCE(unsigned long,_GUID const &,_GUID const &);
		unsigned long Hash(_GUID const &,_GUID const &);
	};

	struct CClassEntry
	{
		CDllClassEntry * SearchForDCE(unsigned short *,unsigned long);
		int HasBCEs();
		long Complete(int *);
		long CreateDllClassEntry(unsigned long,ACTIVATION_PROPERTIES const &,CDllClassEntry * &);
		long CreateLSvrClassEntry_rl(IUnknown *,unsigned long,unsigned long,unsigned long *);
		long SearchBaseClassEntry(unsigned long,CBaseClassEntry * &,unsigned long,int *);
		long SearchBaseClassEntryHelp(unsigned long,CBaseClassEntry * &,unsigned long);
		static long Create(_GUID const &,unsigned long,IComClassInfo *,CClassEntry * &);
		static long CreateIncomplete(_GUID const &,unsigned long,IComClassInfo *,CClassEntry * &,unsigned long);
		static unsigned long _dwSxSHashCount;
		static unsigned long _dwSxSMaxHashCount;
		static unsigned long const CLASS_ENTRY_SIG;
		static unsigned long const INCOMPLETE_ENTRY_SIG;
		static unsigned long const TREAT_AS_SIG;
		unsigned long ReleaseMemoryLock(int *);
		virtual int NoLongerNeeded();
		virtual void Release();
		void RemoveBaseClassEntry(CBaseClassEntry *);
	};

	struct CCollectable
	{
		static CCollectable * NOT_COLLECTED;
		void MakeCollectable();
	};

	struct CDPEHashTable
	{
		unsigned long Hash(unsigned short const *);
		virtual int Compare(void const *,SHashChain *,unsigned long);
		virtual unsigned long HashNode(SHashChain *);
	};

	struct CDllAptEntry
	{
		long Release(CDllPathEntry::CFinishObject *,int &);
		static unsigned long const SIG;
	};

	struct CDllClassEntry
	{
		static unsigned long const SIG;
		virtual long GetClassInterface(IMiniMoniker * *);
		virtual long GetClassObject(_GUID const &,_GUID const &,IUnknown * *,unsigned long);
		virtual void Lock();
		virtual void Unlock();
	};

	struct CDllFnPtrMoniker
	{
		virtual long BindToObject(_GUID const &,void * *);
		virtual long BindToObjectNoSwitch(_GUID const &,void * *);
		virtual long CheckApt();
		virtual long CheckNotComPlus();
		virtual long GetDCE(CDllClassEntry * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
	};

	struct CDllPathEntry
	{
		struct CFinishObject
		{
			virtual long Finish();
		};

		CDllPathEntry(DLL_INSTANTIATION_PROPERTIES const &,HINSTANCE__ *,long (*)(_GUID const &,_GUID const &,void * *),long (*)(HSTRING__ *,IActivationFactory * *),long (*)());
		int IsValidInApartment(unsigned long);
		long CanUnload_rl(unsigned long);
		long DllGetClassObject(_GUID const &,_GUID const &,IUnknown * *,int);
		long GetClassObject(_GUID const &,_GUID const &,void * *);
		long MakeValidInApartment_rl16(DLL_INSTANTIATION_PROPERTIES *,_GUID const *,HINSTANCE__ *,long (*)(_GUID const &,_GUID const &,void * *),long (*)(HSTRING__ *,IActivationFactory * *),long (*)());
		long Release(CDllPathEntry::CFinishObject *);
		static char const * const DLL_CAN_UNLOAD_EP;
		static char const * const DLL_GET_ACTIVATION_FACTORY_EP;
		static char const * const DLL_GET_CLASS_OBJECT_EP;
		static long Create(DLL_INSTANTIATION_PROPERTIES &,bool,CDllPathEntry * &);
		static long LoadDll(DLL_INSTANTIATION_PROPERTIES &,long (*&)(_GUID const &,_GUID const &,void * *),long (*&)(HSTRING__ *,IActivationFactory * *),long (*&)(),HINSTANCE__ * &);
		static long NegotiateDllInstantiationProperties2(unsigned long,_GUID const &,DLL_INSTANTIATION_PROPERTIES &,IComClassInfo *,ActivationPropertiesIn *,int);
		static unsigned long const SIG;
	};

	struct CFinishComposite
	{
		long Finish();
		~CFinishComposite();
	};

	struct CLSvrClassEntry
	{
		struct CFinishObject
		{
			virtual long Finish();
		};

		long AddToApartmentChain();
		long GetDDEInfo(_tagDdeClassInfo *,IMiniMoniker * *);
		long Release(CLSvrClassEntry::CFinishObject *);
		static CPageAllocator _palloc;
		static long SafeCastFromDWORD(unsigned long,CLSvrClassEntry * &);
		static unsigned long _cOutstandingObjects;
		static unsigned long _dwNextCookieCount;
		static unsigned long const DUMMY_SIG;
		static unsigned long const SIG;
		virtual long GetClassInterface(IMiniMoniker * *);
		virtual long GetClassObject(_GUID const &,_GUID const &,IUnknown * *,unsigned long);
		virtual void Lock();
		virtual void Unlock();
	};

	struct CServiceRefEntry
	{
		CServiceRefEntry(unsigned long);
		static CServiceRefEntry * SearchServiceRefEntry(unsigned long);
	};

	struct CWinRTDllClassEntry
	{
		static unsigned long const SIG;
		virtual int NoLongerNeeded();
		virtual void Release();
	};

	struct CWinRTLocalSvrClassEntry
	{
		CWinRTLocalSvrClassEntry(unsigned long,long (*)(HSTRING__ *,IActivationFactory * *),unsigned long,HSTRING__ *,HSTRING__ *,unsigned long);
		static CPageAllocator _palloc;
		static unsigned long _dwNextCookieCount;
		static unsigned long const DUMMY_SIG;
		static unsigned long const SIG;
		void Unlock();
	};

	struct CpUnkMoniker
	{
		virtual long BindToObject(_GUID const &,void * *);
		virtual long BindToObjectNoSwitch(_GUID const &,void * *);
		virtual long CheckApt();
		virtual long CheckNotComPlus();
		virtual long GetDCE(CDllClassEntry * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
	};

	static CActivatableClassIdHashTable _InprocActivatableClassEntries;
	static CActivatableClassIdHashTable _LSvrActivatableClassEntries;
	static CClassCache::CCEHashTable _ClassEntries;
	static CClassCache::CCollectable * _ObjectsForCollection;
	static CClassCache::CDPEHashTable _DllPathEntries;
	static CClassCache::CLSvrClassEntry * GetApartmentChain(int);
	static CClassCache::CLSvrClassEntry * _MTALSvrsFront;
	static CClassCache::CLSvrClassEntry * _NTALSvrsFront;
	static CClassCache::CServiceRefEntry * _ServiceRefsFront;
	static CRWLock _mxs;
	static SHashChain * _CEBuckets;
	static SHashChain * _DPEBuckets;
	static SHashChain * _InprocActivatableClassEBuckets;
	static SHashChain * _LSvrActivatableClassEBuckets;
	static _TP_TIMER * _ShutdownDelayTimer;
	static int GetClassInformationForDde(_GUID const &,_tagDdeClassInfo *);
	static int GetClassInformationFromKey(_tagDdeClassInfo *);
	static int Init();
	static int SetDdeServerWindow(unsigned long,HWND__ *);
	static int _bCanceledTimer;
	static long CleanUpDllsForApartment();
	static long CleanUpDllsForProcess();
	static long CleanUpLocalServersForApartment();
	static long CreateWinRTLocalSvrClassEntry(long (*)(HSTRING__ *,IActivationFactory * *),HSTRING__ *,HSTRING__ *,CClassCache::CWinRTLocalSvrClassEntry * &);
	static long FreeUnused(unsigned long,bool);
	static long GetActivatorFromDllHost(int,int,unsigned long,unsigned long *);
	static long GetClassObject(ACTIVATION_PROPERTIES const &);
	static long GetClassObjectActivator(unsigned long,ACTIVATION_PROPERTIES const &,CClassCache::IMiniMoniker * *);
	static long GetOrLoadClass(ACTIVATION_PROPERTIES const &);
	static long GetOrLoadClassByContext_rl(unsigned long,ACTIVATION_PROPERTIES const &,IComClassInfo *,unsigned long,CClassCache::IMiniMoniker * &);
	static long GetOrLoadWinRTInprocClass(IWinRTRuntimeClassInfo *,IActivationFactory * *);
	static long GetServiceId(unsigned long *);
	static long GetWinRTInprocClassCrossApartmentCallback(unsigned short const *,tagInterfaceData * *);
	static long GetWinRTRegisteredActivationFactory(_GUID const &,HSTRING__ *,IActivationFactory * *);
	static long LockServerForActivation();
	static long RegisterServer(_GUID const &,IUnknown *,unsigned long,unsigned long,unsigned long *);
	static long RegisterServerShutdownDelay(void *,unsigned long);
	static long RegisterWinRTLocalServers(IWinRTRuntimeClassInfo * *,long (**)(HSTRING__ *,IActivationFactory * *),unsigned int,<unnamed-type-RO_REGISTRATION_COOKIE> * *);
	static long ResumeProcessClassObjects();
	static long Revoke(unsigned long);
	static long RevokeWinRTLocalServers(<unnamed-type-RO_REGISTRATION_COOKIE> *);
	static long SearchDPEHash(unsigned short *,CClassCache::CDllPathEntry * &,unsigned long,unsigned long);
	static long SearchForLoadedClass(ACTIVATION_PROPERTIES const &,<unnamed-type-DLL_CLASS_HANDLE> * *);
	static long SuspendProcessClassObjectsHelp(unsigned long);
	static unsigned long AddRefSharedService(unsigned long);
	static unsigned long ReleaseServerProcess();
	static unsigned long ReleaseSharedService(unsigned long);
	static unsigned long _LastCollectionTickCount;
	static unsigned long _LastObjectCount;
	static unsigned long _cRefsServerProcess;
	static unsigned long _dwDelayMilliseconds;
	static unsigned long _dwFlags;
	static void * _hSuspended;
	static void CollectAsNeeded(unsigned long);
	static void CollectUnconditionally(bool);
	static void ReleaseCatalogObjects();
	static void ShutdownDelayTimerCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *);
	static void UnlockServerForActivation();
};

class CCliModalLoop
{
	int FindMessage(unsigned long);
	int PeekRPCAndDDEMessage();
	virtual long HandleRejectedCall(bool);
	virtual unsigned long NoTimerTicksToWait();
	virtual void WaitBeforeRetry(tagRPCOLEMESSAGE const *);
	void HandlePendingMessage();
	void HandleWakeForMsg();
	void RevertToNormalPointerInputMode();
	void SetPointerInputModeAsAppropriateForQueueAttachmentConditions();
public:
	CCliModalLoop(unsigned long,unsigned long,unsigned long,int);
	int IsAttachedQueuePointerMessageReorderingAllowed();
	int MyPeekMessage(tagMSG *,HWND__ *,unsigned int,unsigned int,unsigned short);
	long BlockFn(void * *,unsigned long,unsigned long *);
	unsigned long GetElapsedTime();
	~CCliModalLoop();
};

class CClientCall
{
	static bool s_bInitialized;
	virtual ~CClientCall();
	void OnFieldChanged_m_dwFlags(unsigned long const &,unsigned long const &);
public:
	virtual bool IsCallCanceled();
	virtual int HasWOWMsgArrived();
	virtual int IsCallCompleted();
	virtual int IsCallDispatched();
	virtual int IsCancelIssued();
	virtual int IsClientWaiting();
	virtual long AdvCancel();
	virtual long CanDispatch();
	virtual long Cancel(int,unsigned long);
	virtual long GetState(unsigned long *);
	virtual long TestCancel();
	virtual void AckCancel();
	virtual void AsyncServerMarkCallCompletedAndSignal();
	virtual void CallFinished();
	virtual void MarkCallCompletedWithResult(long);
};

class CClientCallMgr
{
	struct CPrivUnknown
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
	};

	virtual long QueryInterfaceImpl(_GUID const &,void * *);
public:
	CClientCallMgr(IUnknown *,_GUID const &,_GUID const &,CStdIdentity *,CClientCallMgr *,long &,IUnknown * *);
	long VerifyInterface(IUnknown *);
	virtual long Cancel(unsigned long);
	virtual long CopyProxy(IUnknown *,IUnknown * *);
	virtual long GetHandle(void * *);
	virtual long QueryBlanket(IUnknown *,unsigned long *,unsigned long *,unsigned short * *,unsigned long *,unsigned long *,void * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long SetBlanket(IUnknown *,unsigned long,unsigned long,unsigned short *,unsigned long,unsigned long,void *,unsigned long);
	virtual long Signal();
	virtual long TestCancel();
	virtual long Wait(unsigned long,unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	~CClientCallMgr();
};

class CClientChannel
{
	bool ShouldUseThreadLocalCallDispatch();
	bool ShouldUseWinrtAsyncChannel();
	long CheckForAndHandleAstaToAstaCallChain(_GUID const &,unsigned long);
	long InitCallObject(tagRPCOLEMESSAGE *,_GUID const &,unsigned long);
	unsigned long GetStateFlagsForCallObject();
	virtual ~CClientChannel();
	void CleanUpBufferAndCallObject(tagRPCOLEMESSAGE *);
public:
	CClientChannel * Copy(OXIDEntry *,_GUID const &,_GUID const &);
	CClientChannel(CStdIdentity *,OXIDEntry *,bool);
	long GetHandle(CChannelHandle * *,int);
	long NegotiateSyntaxWithProxyIID(tagRPCOLEMESSAGE *,_GUID const &);
	long Send(tagRPCOLEMESSAGE *,CChannelObject *,unsigned long *);
	virtual long Cancel(tagRPCOLEMESSAGE *);
	virtual long CheckSystemHandleLeak(tagRPCOLEMESSAGE const *);
	virtual long CleanupAllSystemHandles(tagRPCOLEMESSAGE const *);
	virtual long FreeBuffer(tagRPCOLEMESSAGE *);
	virtual long FreeSystemHandle(unsigned char,void *);
	virtual long GetBuffer(tagRPCOLEMESSAGE *,_GUID const &);
	virtual long GetCallContext(tagRPCOLEMESSAGE *,_GUID const &,void * *);
	virtual long GetDestCtx(unsigned long *,void * *);
	virtual long GetDestCtxEx(tagRPCOLEMESSAGE *,unsigned long *,void * *);
	virtual long GetInMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetMarshalingLocality(tagRPCOLEMESSAGE const *,ComCallMarshalingLocality *);
	virtual long GetOutMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetProtocolVersion(unsigned long *);
	virtual long GetState(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long GetSystemHandle(tagRPCOLEMESSAGE const *,unsigned long,unsigned char,unsigned long,void * *);
	virtual long IsConnected();
	virtual long NegotiateSyntax(tagRPCOLEMESSAGE *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
	virtual long RegisterAsync(tagRPCOLEMESSAGE *,IAsyncManager *);
	virtual long Send(tagRPCOLEMESSAGE *,ISynchronize *,unsigned long *);
	virtual long Send(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SendReceive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SetSystemHandle(tagRPCOLEMESSAGE const *,void *,unsigned char,unsigned long,unsigned long *);
	void ReplaceHandle(CChannelHandle *);
};

class CClientContextActivator
{
	virtual long CheckInprocClass(IActivationPropertiesIn *,DLL_INSTANTIATION_PROPERTIES *,int &,ILocalSystemActivator * *);
public:
	virtual long CreateInstance(IUnknown *,IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long GetClassObject(IActivationPropertiesIn *,IActivationPropertiesOut * *);
};

struct CClientSecurity
{
	virtual long CopyProxy(IUnknown *,IUnknown * *);
	virtual long QueryBlanket(IUnknown *,unsigned long *,unsigned long *,unsigned short * *,unsigned long *,unsigned long *,void * *,unsigned long *);
	virtual long SetBlanket(IUnknown *,unsigned long,unsigned long,unsigned short *,unsigned long,unsigned long,void *,unsigned long);
};

class CComActivator
{
	long InitializeActivation(ActivationPropertiesIn *);
	void ReleaseData();
public:
	static long DoCreateInstance(_GUID const &,IUnknown *,unsigned long,_COSERVERINFO *,unsigned long,tagMULTI_QI *,ActivationPropertiesIn *);
	static long DoGetClassObject(_GUID const &,unsigned long,_COSERVERINFO *,_GUID const &,void * *,ActivationPropertiesIn *);
	static long DoGetInstanceFromFile(_COSERVERINFO *,_GUID *,IUnknown *,unsigned long,unsigned long,unsigned short *,unsigned long,tagMULTI_QI *,ActivationPropertiesIn *);
	static long DoGetInstanceFromStorage(_COSERVERINFO *,_GUID *,IUnknown *,unsigned long,IStorage *,unsigned long,tagMULTI_QI *,ActivationPropertiesIn *);
	static unsigned long GetActvFlags(unsigned long);
	virtual long AddOpaqueData(tagOpaqueData *);
	virtual long DeleteOpaqueData(_GUID const &);
	virtual long FlagClear(unsigned long);
	virtual long FlagQuery(unsigned long);
	virtual long FlagSet(unsigned long);
	virtual long GetAllOpaqueData(tagOpaqueData * *);
	virtual long GetClientImpersonating(int *);
	virtual long GetDefaultAuthenticationLevel(unsigned long *);
	virtual long GetLUARunLevel(unsigned long *,unsigned __int64 *);
	virtual long GetOpaqueData(_GUID const &,tagOpaqueData * *);
	virtual long GetOpaqueDataCount(unsigned long *);
	virtual long GetOrigClsctx(unsigned long *);
	virtual long GetPartitionId(_GUID *);
	virtual long GetProcessRequestType(unsigned long *);
	virtual long GetServiceId(unsigned long *);
	virtual long GetSessionId(unsigned long *,int *);
	virtual long GetSessionId2(unsigned long *,int *,int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long SetClientImpersonating(int);
	virtual long SetDefaultAuthenticationLevel(unsigned long);
	virtual long SetLUARunLevel(unsigned long,unsigned __int64);
	virtual long SetOrigClsctx(unsigned long);
	virtual long SetPartitionId(_GUID const &);
	virtual long SetProcessRequestType(unsigned long);
	virtual long SetServiceId(unsigned long);
	virtual long SetSessionId(unsigned long,int,int);
	virtual long StandardCreateInstance(_GUID const &,IUnknown *,unsigned long,_COSERVERINFO *,unsigned long,tagMULTI_QI *);
	virtual long StandardGetClassObject(_GUID const &,unsigned long,_COSERVERINFO *,_GUID const &,void * *);
	virtual long StandardGetInstanceFromFile(_COSERVERINFO *,_GUID *,IUnknown *,unsigned long,unsigned long,unsigned short *,unsigned long,tagMULTI_QI *);
	virtual long StandardGetInstanceFromIStorage(_COSERVERINFO *,_GUID *,IUnknown *,unsigned long,IStorage *,unsigned long,tagMULTI_QI *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CComApartment
{
	int IsInitializedAndNotUninitializing();
	long CallTheResolver();
	long WaitForAccess();
	static COleStaticMutexSem s_ShutdownRegLock;
	static unsigned __int64 ui64ApartmentIdentifierForApartmentKind(APTKIND);
	static unsigned long ApartmentIdForApartmentKind(APTKIND);
	static unsigned long volatile s_ulApartmentIdentifierCounter;
	void CheckForWaiters();
	void ClassicSTAQueueMessage(unsigned int,IMessageParam *);
	~CComApartment();
public:
	ASTAIncomingCallList ASTAGetDispatchableCallsNowQueued();
	ASTAIncomingCallList ASTAGetQueuedCallsNowDispatchable();
	CComApartment(APTKIND);
	bool ClassicSTARemoveMessage(unsigned int,IMessageParam *);
	long ASTAPostCall(ServerCall *);
	long ClassicSTAPostMessage(unsigned int,IMessageParam *);
	long ClassicSTASendMessage(unsigned int,IMessageParam *);
	long CleanupRemoting();
	long FinalConstruct();
	long FreePreRegMOID(_GUID const &);
	long GetOXIDEntryInitializeIfNeeded(OXIDEntry * *);
	long GetPreRegMOID(_GUID *);
	long GetRemUnk(IRemUnknownN * *);
	long InitRemoting();
	long RegisterShutdownCallback(Microsoft::WRL::ComPtr<IApartmentShutdown>,APARTMENT_SHUTDOWN_REGISTRATION_COOKIE__ * *);
	long STAPostGipRevoke(CGIPMessageParam *);
	long STAPostWinrtAsyncResponse(IMessageParam *);
	long STAPostWinrtAsyncServerContinuationMessage(IMessageParam *);
	long StartServer();
	long StartServerExternal();
	long StopServer();
	long UnregisterShutdownCallback(APARTMENT_SHUTDOWN_REGISTRATION_COOKIE__ *);
	static bool ASTAIsAlwaysDispatchableMethod(_GUID const &,unsigned long);
	void ASTAFlushPendingWork();
	void ASTAHandleMessage(IMessageParam *);
	void ASTAHandleQueuedCallTimeoutsAndRelease(ASTAIncomingCallList &);
	void ASTAPostGipRevoke(CGIPMessageParam *);
	void ASTAPostReleaseRifRef(IMessageParam *);
	void ASTAPostWinrtAsyncResponse(IMessageParam *);
	void ASTAPostWinrtAsyncServerContinuationMessage(IMessageParam *);
	void ASTASetMessageDispatcher(IMessageDispatcher *);
	void CanRundownOIDs(unsigned long,unsigned __int64 * const,tagRUNDOWN_RESULT * const);
	void DeleteApartmentShutdownCallbacks();
	void NotifyApartmentShutdownCallbacks();
};

class CComCatalog
{
	long GetClassInfoInternal(unsigned long,IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	long GetProcessInfoInternal(unsigned long,IUserToken *,_GUID const &,_GUID const &,void * *);
	long GetProxyStubCLSIDFromPackageScopedCatalog(unsigned long,_GUID const &,IComCatalogInternal *,_GUID *);
	long GetProxyStubClassInfoFromPackageScopedCatalog(unsigned long,_GUID const &,IComCatalogInternal *,CCache *,_GUID const &,void * *);
	long GetRuntimeClassInfoFromPackageScopedCatalog(unsigned long,IUserToken *,unsigned short const *,unsigned short const *,KnownClsidAndScope const *,int,IComCatalogInternal *,CCache *,_GUID const &,void * *,IComCatalogSCM *);
	long GetServerInfoFromPackageScopedCatalog(unsigned long,IUserToken *,unsigned short const *,unsigned short const *,IComCatalogInternal *,CCache *,_GUID const &,void * *,IComCatalogSCM *);
	long TryToLoadCLB();
	static bool MatchServerArchitectureAndExclusiveRegViewFlag(IUnknown *,unsigned long);
	static int ComPlusEnabled();
	static long CheckForRefresh(IUserToken *,IUnknown *,CCache *);
	static long CreateNoClassInfo(IUserToken *,_GUID const &,_GUID const &,void * *);
	static long HashAndSizeString(unsigned short const *,unsigned long *,unsigned short *);
	static long InitializeReadCache();
	static std::atomic<int> ms_fComPlusCatalogsResolved;
	static std::atomic<int> ms_fComPlusEnabled;
	static std::atomic<int> ms_fComPlusEnabledInitialized;
	static std::atomic<int> ms_fInitialized;
	static unsigned long FlagsForCacheKey(unsigned long);
public:
	CComCatalog();
	long DeInit();
	long InitializeCatalogIfNeccessary();
	long ReadProcessPackageGraph();
	virtual HKEY__ * GetHKCR();
	virtual bool IsTypeLibRegistered(_GUID const &,HSTRING__ *,unsigned long);
	virtual long FlushCache();
	virtual long FlushIdleEntries();
	virtual long GetApplicationInfo(IUserToken *,_GUID const &,_GUID const &,void * *);
	virtual long GetApplicationInfo(IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetApplicationInfo(_GUID const &,_GUID const &,void * *);
	virtual long GetApplicationInfoForExe(IUserToken *,unsigned short *,_GUID const &,void * *);
	virtual long GetApplicationInfoForExe(unsigned short *,_GUID const &,void * *);
	virtual long GetAutoConvertTo(_GUID const &,_GUID *);
	virtual long GetClassInfoByApplication(_GUID const &,_GUID const &,_GUID const &,_GUID const &,void * *);
	virtual long GetClassInfoByApplication(unsigned long,IUserToken *,_GUID const &,_GUID const &,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetClassInfoByPartition(_GUID const &,_GUID const &,_GUID const &,void * *);
	virtual long GetClassInfoByPartition(unsigned long,IUserToken *,_GUID const &,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetClassInfoFromProgId(IUserToken *,unsigned short *,_GUID const &,void * *);
	virtual long GetClassInfoFromProgId(IUserToken *,unsigned short *,_GUID const &,void * *,void *);
	virtual long GetClassInfoFromProgId(unsigned short *,_GUID const &,void * *);
	virtual long GetClassInfoW(_GUID const &,_GUID const &,void * *);
	virtual long GetClassInfoW(unsigned long,IUserToken *,_GUID const &,_GUID const &,void * *);
	virtual long GetClassInfoW(unsigned long,IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetCounterpartIid(_GUID const &,bool,_GUID *);
	virtual long GetHelpDirectory(_GUID const &,unsigned long,unsigned long,unsigned long,HSTRING__ * *);
	virtual long GetIidProxyStubRegistrationInfo(_GUID const &,HSTRING__ * *,UniversalMarshalerType *,_GUID *);
	virtual long GetIidTypeLibRegistrationInfo(_GUID const &,HSTRING__ * *);
	virtual long GetInterfaceInfo(IUserToken *,_GUID const &,_GUID const &,void * *);
	virtual long GetInterfaceInfo(IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetInterfaceInfo(_GUID const &,_GUID const &,void * *);
	virtual long GetNativeRegistryCatalog(_GUID const &,void * *);
	virtual long GetNonNativeRegistryCatalog(_GUID const &,void * *);
	virtual long GetPackagedComClassIdIterator(IPackagedComClassIdIterator * *);
	virtual long GetPackagedComProgIdIterator(IPackagedComProgIdIterator * *);
	virtual long GetPackagedProxyStubClassInfo(_GUID const &,HSTRING__ *,IComClassInfo * *);
	virtual long GetProcessInfo(IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetProcessInfo(_GUID const &,_GUID const &,void * *);
	virtual long GetProcessInfo(unsigned long,IUserToken *,_GUID const &,_GUID const &,void * *);
	virtual long GetProxyStubCLSIDForInterface(unsigned long,_GUID const &,unsigned short const *,_GUID *);
	virtual long GetRetQueueInfo(IUserToken *,unsigned short *,_GUID const &,void * *);
	virtual long GetRetQueueInfo(unsigned short *,_GUID const &,void * *);
	virtual long GetRuntimeClassInfo(unsigned long,IUserToken *,unsigned short const *,unsigned short const *,KnownClsidAndScope const *,int,_GUID const &,void * *,IComCatalogSCM *);
	virtual long GetServerGroupInfo(IUserToken *,_GUID const &,_GUID const &,void * *);
	virtual long GetServerGroupInfo(_GUID const &,_GUID const &,void * *);
	virtual long GetServerInfo(unsigned long,IUserToken *,unsigned short const *,unsigned short const *,_GUID const &,void * *,IComCatalogSCM *);
	virtual long GetTreatAsClass(_GUID const &,_GUID *);
	virtual long GetTypeLibPath(_GUID const &,unsigned long,unsigned long,bool,unsigned long,HSTRING__ * *,unsigned long *,unsigned long *);
	virtual long GetTypeLibRegistrationIterator(ITypeLibRegistrationIterator * *);
	virtual long GetTypeLibrary(IUserToken *,_GUID const &,_GUID const &,void * *);
	virtual long GetTypeLibrary(_GUID const &,_GUID const &,void * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RefreshComPlusEnabled();
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void FlushProviderCaches();
	~CComCatalog();
};

class CComClassInfo
{
	long GetDarwinIdentifier(int,HKEY__ *,unsigned short const *,unsigned short * *);
	long GetExeArchitectureFromRegString(unsigned short const *,unsigned long *);
	long GetPathFromDarwinDescriptor(int,unsigned short *,unsigned short * *);
	long Initialize(HKEY__ *,HKEY__ *,IUserToken *,int,HKEY__ *,unsigned long,int,IComCatalogSCM *,bool,bool,bool,bool,bool,unsigned long);
	long InitializeForInprocActivations(int,HKEY__ *,bool,bool);
	long InitializeForOutOfProcActivations(int,IUserToken *,HKEY__ *,unsigned long,IComCatalogSCM *,bool,bool,bool,bool,unsigned long);
	long InitializeInprocHandlers(HKEY__ *,bool);
	long InitializeLUAAndDisplaySettings(HKEY__ *);
	long InitializeLocalServer(int,HKEY__ *,bool,unsigned long);
	long InitializeSurrogateInfo(HKEY__ *,tagProcessType,bool,bool,unsigned long);
	long InitializeThreadingModel(HKEY__ *);
public:
	CComClassInfo(RegistrationSource);
	virtual long CanBeCached(int *);
	virtual long GetBinaryName(unsigned short * *);
	virtual long GetClassContext(tagCLSCTX,tagCLSCTX *);
	virtual long GetClassNameW(unsigned short const * *);
	virtual long GetConfiguredClsid(_GUID * *);
	virtual long GetDeployingPackageName(unsigned short const * *);
	virtual long GetDisplayName(unsigned short * *);
	virtual long GetExecutionPackageName(unsigned short const * *);
	virtual long GetIconReference(unsigned short * *);
	virtual long GetImplementedClsid(_GUID * *);
	virtual long GetLUAEnabledSetting(int *);
	virtual long GetLocalServerType(tagLocalServerType *);
	virtual long GetModulePath(tagCLSCTX,unsigned short * *);
	virtual long GetOutofprocServerBinaryArchitecture(unsigned long *);
	virtual long GetPreferredServerBitness(unsigned long *);
	virtual long GetProcess(_GUID const &,void * *);
	virtual long GetProgId(unsigned short * *);
	virtual long GetRemoteServerName(unsigned short * *);
	virtual long GetServerExecutable(unsigned short * *);
	virtual long GetSource(RegistrationSource *);
	virtual long GetSurrogateCommandLine(unsigned short * *);
	virtual long GetThreadingModel(ThreadingModel *);
	virtual long GetUserSettings(int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RefreshNeeded(IUserToken *,int *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	~CComClassInfo();
};

class CComNoClassInfo
{
	void InitializeChangeDetection(IUserToken *);
public:
	CComNoClassInfo(IUserToken *,_GUID const &);
	CComNoClassInfo(IUserToken *,_GUID const &,unsigned short *);
	CComNoClassInfo(IUserToken *,unsigned short *);
	virtual long CanBeCached(int *);
	virtual long GetClassContext(tagCLSCTX,tagCLSCTX *);
	virtual long GetConfiguredClsid(_GUID * *);
	virtual long GetImplementedClsid(_GUID * *);
	virtual long GetModulePath(tagCLSCTX,unsigned short * *);
	virtual long GetProgId(unsigned short * *);
	virtual long GetThreadingModel(ThreadingModel *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RefreshNeeded(IUserToken *,int *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CComProcessInfo
{
	static int m_fGotLegacyLevels;
	static unsigned long m_dwLegacyAuthenticationLevel;
	static unsigned long m_dwLegacyImpersonationLevel;
public:
	CComProcessInfo(RegistrationSource);
	long FinalConstruct(IUserToken *,_GUID const &,unsigned short *,HKEY__ *,HKEY__ *,int,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool);
	virtual int IsFromMachineHive();
	virtual long CanBeCached(int *);
	virtual long GetAccessPermission(void * *,unsigned long *);
	virtual long GetActivateAtStorage(int *);
	virtual long GetAppIDFlags(unsigned long *);
	virtual long GetApplicationId(unsigned short const * *);
	virtual long GetAuthenticationLevel(unsigned long *);
	virtual long GetCommandPathAndDebug(int *,unsigned short * *);
	virtual long GetDeployingPackageName(unsigned short const * *);
	virtual long GetExecutionPackageName(unsigned short const * *);
	virtual long GetImpersonationLevel(unsigned long *);
	virtual long GetLaunchPermission(void * *,unsigned long *);
	virtual long GetMGOTFlags(unsigned long *);
	virtual long GetPreferredServerBitness(unsigned long *);
	virtual long GetProcessId(_GUID * *);
	virtual long GetProcessMitigationPolicy(tagBLOB *);
	virtual long GetProcessName(unsigned short * *);
	virtual long GetProcessType(tagProcessType *);
	virtual long GetROTFlags(unsigned long *);
	virtual long GetRemoteServerName(unsigned short * *);
	virtual long GetRunAsType(tagRunAsType *);
	virtual long GetRunAsUser(unsigned short * *);
	virtual long GetSaferTrustLevel(unsigned long *);
	virtual long GetServiceName(unsigned short * *);
	virtual long GetServiceParameters(unsigned short * *);
	virtual long GetSource(RegistrationSource *);
	virtual long GetSurrogatePath(unsigned short * *);
	virtual long GetSurrogateServerExecutable(unsigned short * *);
	virtual long GetUserSettings(int *);
	virtual long IsUserService(int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RefreshNeeded(IUserToken *,int *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	~CComProcessInfo();
};

class CComRegCatalog
{
	long CheckForceHKLMForAppID(HKEY__ *,int *);
	long CheckForceHKLMForCLSID(HKEY__ *,HKEY__ *,int *);
protected:
	static long OpenKeyInViewHelper(HKEY__ *,unsigned short const *,unsigned long,unsigned long,unsigned short,HKEY__ * *);
public:
	virtual HKEY__ * GetHKCR();
	virtual long GetClassInfoFromProgId(IUserToken *,unsigned short *,_GUID const &,void * *,void *);
	virtual long GetClassInfoW(unsigned long,IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetProcessInfo(IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetProcessInfoInternal(unsigned long,IUserToken *,_GUID const &,_GUID const &,void * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CComSxSCatalog
{
	virtual long GetClassInfoFromProgId(IUserToken *,unsigned short *,_GUID const &,void * *,void *);
	virtual long GetClassInfoW(unsigned long,IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CComSxSClassInfo
{
	CComSxSClassInfo(void *,_GUID const &,_ACTIVATION_CONTEXT_DATA_COM_SERVER_REDIRECTION const *,unsigned long,void *,unsigned long);
	virtual long GetClassContext(tagCLSCTX,tagCLSCTX *);
	virtual long GetConfiguredClsid(_GUID * *);
	virtual long GetImplementedClsid(_GUID * *);
	virtual long GetModulePath(tagCLSCTX,unsigned short * *);
	virtual long GetProgId(unsigned short * *);
	virtual long GetThreadingModel(ThreadingModel *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CContextLife
{
	void Release();
};

class CContextPropList
{
	int Grow();
public:
	int Add(_GUID const &,unsigned long,IUnknown *);
	tagContextProperty * Get(_GUID const &);
	void Remove(_GUID const &);
	void SerializeToVector(tagContextProperty * &);
};

struct CContextSwitcher
{
	virtual long ContextCallback(long (*)(tagComCallData *),tagComCallData *,_GUID const &,int,IUnknown *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CContinue
{
	virtual long FContinue();
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CCtxCall
{
	long EnsureInitMarshaledHandleStorage(MessageDirection);
	void TraceClientSyncCallStart(unsigned long,_GUID const &,ClientCallTracingInfo const &);
	void TraceClientSyncCallStop();
protected:
	long EnableInParameterMarshalingMitigation();
	long EnableInprocOutParameterMarshalingMitigation();
public:
	CCtxCall(CCtxCall *);
	CCtxCall(unsigned long,unsigned long,bool,unsigned long,unsigned long,unsigned short,_GUID const *,ClientCallTracingInfo const *,_GUID const *,ComCallTraceActivity *,tagRPCOLEMESSAGE *,CStdWrapper *,IFaceEntry *);
	long GetOrCreateInBiasContainer(unsigned __int64 *);
	long GetOrCreateOutBiasContainer(unsigned __int64 *);
	long GetSystemHandle(unsigned long,unsigned char,unsigned long,void * *);
	long SetSystemHandle(void *,unsigned char,unsigned long,unsigned long *);
	static COleStaticMutexSem _mxsCtxCallLock;
	static int s_iAvailable;
	static void * * s_pAllocList;
	static void * operator new(unsigned __int64);
	static void Cleanup();
	static void operator delete(void *);
	virtual _GUID GetPassthroughTraceActivity();
	virtual _GUID GetTargetInterface();
	virtual bool EnableCallTracing();
	virtual bool NeedsUnmarshalingTlsMitigation();
	virtual long CompleteCurrentTlsRundownMitigation();
	virtual long ErrorHandler(_GUID const &,void * *,int,int);
	virtual long IncrementCallCount();
	virtual long MarshalItfPtrs(_GUID const &,void * *,int,int);
	virtual long OnWalkInterface(_GUID const &,void * *,int,int);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long UnmarshalItfPtrs(_GUID const &,void * *,int,int);
	virtual tagRPCOLEMESSAGE * GetMessageW();
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual unsigned short GetProcNum();
	virtual void * GetServerInterface();
	virtual void * GetServerObject();
	virtual void * GetServerVtable();
	virtual void AbortCurrentTlsRundownMitigation();
	virtual void DecrementCallCount();
	virtual void RelockServerIfNeeded();
	virtual void ReportServerFault(unsigned long);
	virtual void ReportStubInvokeFailure(long);
	virtual void TraceServerCallStart(ServerCallTracingInfo const &);
	virtual void TraceServerCallStop(unsigned long);
	void * AllocBuffer();
	void CleanupMarshaledHandleStorage(MessageDirection);
	void FreeBuffer();
	~CCtxCall();
};

class CCtxChnl
{
	long GetBuffer2(tagRPCOLEMESSAGE *,_GUID const &,CCtxCall *,int,int,bool,unsigned long *,ClientCallTracingInfo *);
	long SendReceive2(tagRPCOLEMESSAGE *,long *,unsigned long,CCtxCall *,CCtxCall *,ICallFrame *,ICallFrame *,__MIDL_ICallFrame_0001 const *);
	long SyncInvoke2(tagRPCOLEMESSAGE *,unsigned long *,CCtxCall *,CCtxCall *,ICallFrame *,ICallFrame *,__MIDL_ICallFrame_0001 const *,long *);
public:
	CCtxChnl(CStdWrapper *);
	virtual long CheckSystemHandleLeak(tagRPCOLEMESSAGE const *);
	virtual long CleanupAllSystemHandles(tagRPCOLEMESSAGE const *);
	virtual long FreeBuffer(tagRPCOLEMESSAGE *);
	virtual long FreeSystemHandle(unsigned char,void *);
	virtual long GetBuffer(tagRPCOLEMESSAGE *,_GUID const &);
	virtual long GetDestCtx(unsigned long *,void * *);
	virtual long GetInMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetMarshalingLocality(tagRPCOLEMESSAGE const *,ComCallMarshalingLocality *);
	virtual long GetOutMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetProtocolVersion(unsigned long *);
	virtual long GetSystemHandle(tagRPCOLEMESSAGE const *,unsigned long,unsigned char,unsigned long,void * *);
	virtual long IsConnected();
	virtual long NegotiateSyntax(tagRPCOLEMESSAGE *);
	virtual long OnCall(ICallFrame *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SendReceive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SetSystemHandle(tagRPCOLEMESSAGE const *,void *,unsigned char,unsigned long,unsigned long *);
};

class CCtxComChnl
{
protected:
	CCtxComChnl(CStdIdentity *,OXIDEntry *,bool);
public:
	virtual long QueryInterface(_GUID const &,void * *);
};

struct CCtxConnectionManager
{
	CCtxConnectionManager(long *);
	long AddpUnk(IUnknown *);
	long DisconnectAllObjects();
	unsigned long Release();
	void DecrementCount();
	void IncrementCount();
	void SetEventIfNeccessary();
};

struct CCtxHook
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual void ClientFillBuffer(_GUID const &,_GUID const &,unsigned long *,void *);
	virtual void ClientGetSize(_GUID const &,_GUID const &,unsigned long *);
	virtual void ClientNotify(_GUID const &,_GUID const &,unsigned long,void *,unsigned long,long);
	virtual void ServerFillBuffer(_GUID const &,_GUID const &,unsigned long *,void *,long);
	virtual void ServerGetSize(_GUID const &,_GUID const &,long,unsigned long *);
	virtual void ServerNotify(_GUID const &,_GUID const &,unsigned long,void *,unsigned long);
};

struct CCtxPropHashTable
{
	CObjectContext * Lookup(CObjectContext *,int);
	virtual int Compare(void const *,SHashChain *,int);
	virtual int Compare(void const *,SHashChain *,unsigned long);
	virtual unsigned long HashNode(SHashChain *);
};

class CCtxTable
{
	static int s_fInitialized;
public:
	static CCtxPropHashTable s_CtxPropHashTable;
	static CCtxUUIDHashTable s_CtxUUIDHashTable;
	static SHashChain * s_CtxPropBuckets;
	static SHashChain * s_CtxUUIDBuckets;
	static long AddContext(CObjectContext *);
	static void Cleanup();
	static void Initialize();
};

struct CCtxUUIDHashTable
{
	virtual int Compare(void const *,SHashChain *,unsigned long);
	virtual unsigned long HashNode(SHashChain *);
};

class CCustomAttributeEnumerator
{
protected:
	virtual long _Enumerate(void * *,unsigned int *,unsigned long,unsigned long *);
};

class CCustomProperties
{
	struct CIterator
	{
		CIterator(CCustomProperties *);
		virtual long MoveNext(unsigned char *);
		virtual long get_Current(Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> * *);
		virtual long get_HasCurrent(unsigned char *);
	};

	long GetCustomProperty(HSTRING__ *,IInspectable * *);
	long GetCustomPropertyType(HSTRING__ *,Windows::Foundation::PropertyType *);
	long GetNextValidProperty(unsigned long,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> * *,unsigned long *);
	long InitializePropertyValueFactoryIfNecessary();
public:
	virtual long First(Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
	virtual long HasKey(HSTRING__ *,unsigned char *);
	virtual long Lookup(HSTRING__ *,IInspectable * *);
	virtual long Split(Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
	virtual long get_Size(unsigned int *);
};

struct CDWORDHashTable
{
	virtual int Compare(void const *,SHashChain *,unsigned long);
};

struct CDebugChannelHook
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual void ClientFillBuffer(_GUID const &,_GUID const &,unsigned long *,void *);
	virtual void ClientGetSize(_GUID const &,_GUID const &,unsigned long *);
	virtual void ClientNotify(_GUID const &,_GUID const &,unsigned long,void *,unsigned long,long);
	virtual void ServerFillBuffer(_GUID const &,_GUID const &,unsigned long *,void *,long);
	virtual void ServerGetSize(_GUID const &,_GUID const &,long,unsigned long *);
	virtual void ServerNotify(_GUID const &,_GUID const &,unsigned long,void *,unsigned long);
};

struct CDebugEventFire
{
	long GetEventLogger(ISystemDebugEventFire * *);
	long Initialize();
	virtual long BeginSession(_GUID const &,unsigned short const *);
	virtual long EndSession();
	virtual long FireEvent(_GUID const &,int,unsigned __int64 *,unsigned __int64 *,unsigned long *,unsigned long,long,eVSAEventFlags);
	virtual long IsActive();
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual void _CreateLogger();
	virtual void _DestroyLogger();
	void Cleanup();
};

struct CDebugEventFireCF
{
	virtual long CreateInstance(IUnknown *,_GUID const &,void * *);
	virtual long LockServer(int);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CDestObject
{
	virtual long GetComVersion(tagCOMVERSION *);
	virtual long GetDestCtx(unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CDestObjectWrapper
{
	virtual long GetComVersion(tagCOMVERSION *);
	virtual long GetDestCtx(unsigned long *);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual void GetIDestInfo(void * *);
};

class CDllHost
{
	IDLLHost * GetHostProxy();
	int EnterNTAIfNecessary(COleTls &,CObjectContext * *);
	long CreateBothApartmentActivators();
	long GetApartmentActivators(unsigned long &,unsigned long &);
	long Initialize(unsigned long);
	long MTAInitializeActivators();
	long MTAInitializeApartmentOnlyImpl(bool *);
	long Marshal();
	long Unmarshal();
	long WorkerThread();
	static void MTADllUnloadCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *);
	static void MTAInitializeActivatorsInMTA(_TP_CALLBACK_INSTANCE *,void *,_TP_WORK *);
	void * ClientCleanupStart(_TP_TIMER * *);
	void ClientCleanupFinish(void *,_TP_TIMER *);
	void MTAInitializeActivatorsInMTAImpl();
	void MTASetDllUnloadTimer();
	void MTAUninitializeApartmentOnly();
	void STAWorkerLoop();
	void ServerCleanup(unsigned long);
public:
	CDllHost();
	long GetClassObject(unsigned __int64,_GUID const &,_GUID const &,IUnknown * *,unsigned long);
	long MTAInitializeApartmentOnly();
	virtual long DllGetClassObject(unsigned __int64,_GUID,_GUID const &,_GUID const &,IUnknown * *,unsigned long);
	virtual long GetCOMApartmentActivator(unsigned long &);
	virtual long GetWinRTApartmentActivator(unsigned long &);
	virtual long QueryInterface(_GUID const &,void * *);
	~CDllHost();
};

struct CDualStringArray
{
	unsigned long Release();
};

class CEffPermsCacheLUID
{
	unsigned long Hash(_LUID);
public:
	int LookUpEntry(_LUID,unsigned long *);
	int WriteEntry(_LUID,unsigned long);
	void FlushCache();
};

struct CEndpointEntry
{
	CEndpointEntry(unsigned short,unsigned short *,unsigned short *,unsigned long);
};

struct CEndpointsTable
{
	CEndpointEntry * AddEntry(unsigned short,unsigned short *,unsigned short *,unsigned long);
	CEndpointEntry * FindEntry(unsigned short);
	void Cleanup();
	void Initialize();
};

struct CEnumContextProps
{
	virtual long Clone(IEnumContextProps * *);
	virtual long Count(unsigned long *);
	virtual long Next(unsigned long,tagContextProperty *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void CleanupProperties();
	~CEnumContextProps();
};

struct CErrorChannelHook
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual void ClientFillBuffer(_GUID const &,_GUID const &,unsigned long *,void *);
	virtual void ClientGetSize(_GUID const &,_GUID const &,unsigned long *);
	virtual void ClientNotify(_GUID const &,_GUID const &,unsigned long,void *,unsigned long,long);
	virtual void ServerFillBuffer(_GUID const &,_GUID const &,unsigned long *,void *,long);
	virtual void ServerGetSize(_GUID const &,_GUID const &,long,unsigned long *);
	virtual void ServerNotify(_GUID const &,_GUID const &,unsigned long,void *,unsigned long);
};

struct CErrorObject
{
	virtual long DisconnectObject(unsigned long);
	virtual long GetDescription(unsigned short * *);
	virtual long GetGUID(_GUID *);
	virtual long GetHelpContext(unsigned long *);
	virtual long GetHelpFile(unsigned short * *);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long GetSource(unsigned short * *);
	virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long ReleaseMarshalData(IStream *);
	virtual long SetDescription(unsigned short *);
	virtual long SetGUID(_GUID const &);
	virtual long SetHelpContext(unsigned long);
	virtual long SetHelpFile(unsigned short *);
	virtual long SetSource(unsigned short *);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CEventCache
{
	static COleStaticMutexSem _mxsEventCache;
	static unsigned long _ifree;
	static void * * _list;
public:
	long Get(void * *);
	static bool s_bPreventRundownBiasCleanupInProcess;
	void Cleanup();
	void Free(void *);
};

struct CExeServerRegistration
{
	virtual long FinalConstruct(IWinRTServerInfo *);
	virtual long get_ActivatableClasses(HSTRING__ * *);
	virtual long get_AppUserModelId(HSTRING__ * *);
	virtual long get_Attributes(Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
	virtual long get_CommandLine(HSTRING__ * *);
	virtual long get_ExePath(HSTRING__ * *);
	virtual long get_Identity(HSTRING__ * *);
	virtual long get_IdentityType(Windows::Foundation::IdentityType *);
	virtual long get_Instancing(Windows::Foundation::InstancingType *);
	virtual long get_Permissions(HSTRING__ * *);
	virtual long get_ServerName(HSTRING__ * *);
};

class CExtensionAllPackagesIterator
{
	long CompleteCurrentPackageInformation(bool *);
	long GetPackageForCurrentIndex();
public:
	virtual long MoveToNextPackage();
};

class CExtensionCatalog
{
	struct CFactory
	{
		virtual long ActivateInstance(IInspectable * *);
	};

	long InitializePackageStaticsIfNecessary();
	long QueryCatalogInternal(OpaqueString const &,OpaqueString &,Windows::Foundation::Collections::IIterator<Windows::Foundation::IExtensionRegistration *> * *);
	static long CreateAllPackagesIterator(OpaqueString,Microsoft::WRL::ComPtr<CActivationStore> const &,Microsoft::WRL::ComPtr<Windows::Internal::StateRepository::IPackageStatics> const &,IExtensionPackagesIterator * *);
	static long CreateMainAndOptionalPackagesIterator(OpaqueString const &,OpaqueString const &,Microsoft::WRL::ComPtr<CActivationStore> const &,IExtensionPackagesIterator * *);
	static long CreateNoExtensionRegistrationsIterator(Windows::Foundation::Collections::IIterator<Windows::Foundation::IExtensionRegistration *> * *);
	static long GetExtensionRegistrationWithVerifiedMainPackageFullName(OpaqueString const &,OpaqueString const &,OpaqueString const &,Windows::Foundation::IExtensionRegistration * *);
	static long VerifyIsValidPackageTypeByPackageFamilyName(unsigned short const *,unsigned short const *);
	static long VerifyIsValidPackageTypeByPackageFullName(unsigned short const *,unsigned short const *);
	static long VerifyPackageTypeAndGetFullNameFromPackageFamilyName(unsigned short const *,unsigned short const *,OpaqueString &);
public:
	static TrustLevel InternalGetTrustLevel();
	static long GetExtensionRegistration(OpaqueString const &,OpaqueString const &,unsigned short const *,OpaqueString const &,Windows::Foundation::IExtensionRegistration * *);
	static long GetExtensionRegistrationByExtensionId(OpaqueString const &,OpaqueString const &,Windows::Foundation::IExtensionRegistration * *);
	static unsigned short const * InternalGetRuntimeClassName();
	virtual long GetIids(unsigned long *,_GUID * *);
	virtual long GetRuntimeClassName(HSTRING__ * *);
	virtual long GetTrustLevel(TrustLevel *);
	virtual long QueryCatalog(HSTRING__ *,Windows::Foundation::Collections::IIterator<Windows::Foundation::IExtensionRegistration *> * *);
	virtual long QueryCatalogByPackageFamilyName(HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::IIterator<Windows::Foundation::IExtensionRegistration *> * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CExtensionMainAndOptionalPackagesIterator
{
	long FindFirstPackageFromCurrentIndex();
	long MoveToNextPackageIndex();
public:
	CExtensionMainAndOptionalPackagesIterator(OpaqueString const &,Microsoft::WRL::ComPtr<CActivationStore> const &,OpaqueString const &);
	virtual long MoveToNextPackage();
};

class CExtensionPackagesIterator
{
	struct Transaction
	{
		Transaction(CExtensionPackagesIterator &);
		~Transaction();
	};

protected:
	long InitializeForCurrentStore();
	long InitializeRegistrationStoreAndContractHandle();
	long SwitchToUserApps();
	void ReleaseContractHandle();
	void ReleaseCurrentPackageHandle();
public:
	CExtensionPackagesIterator(OpaqueString const &,Microsoft::WRL::ComPtr<CActivationStore> const &);
	virtual bool HasCurrentPackage();
	virtual bool IsUserAppPackage();
	virtual long GetExtensionRegistrationForCurrentPackageByAcid(OpaqueString const &,Windows::Foundation::IExtensionRegistration * *);
	virtual long GetExtensionRegistrationForCurrentPackageByClassIndex(unsigned int,Windows::Foundation::IExtensionRegistration * *);
	virtual ~CExtensionPackagesIterator();
};

class CExtensionRegistration
{
	long InternalGetActivatableClassRegistration();
protected:
	virtual ~CExtensionRegistration();
public:
	CExtensionRegistration(OpaqueString const &,OpaqueString const &,OpaqueString const &,OpaqueString const &,ExtensionRegistrationEntryProperties const &,Windows::Foundation::RegistrationScope,Microsoft::WRL::ComPtr<CActivationStore> const &);
	virtual long Activate(IInspectable * *);
	virtual long HasKey(HSTRING__ *,unsigned char *);
	virtual long Lookup(HSTRING__ *,IInspectable * *);
	virtual long Split(Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
	virtual long get_ActivatableClassId(HSTRING__ * *);
	virtual long get_ActivatableClassRegistration(Windows::Foundation::IActivatableClassRegistration * *);
	virtual long get_Attributes(Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
	virtual long get_ComponentProcessId(_GUID *);
	virtual long get_ConsoleHandlesId(unsigned __int64 *);
	virtual long get_ContractId(HSTRING__ * *);
	virtual long get_Description(HSTRING__ * *);
	virtual long get_DisplayName(HSTRING__ * *);
	virtual long get_ExtensionId(HSTRING__ * *);
	virtual long get_HostId(unsigned __int64 *);
	virtual long get_Icon(HSTRING__ * *);
	virtual long get_LpacAttributes(tagBLOB * *);
	virtual long get_OutOfProcActivationFlags(unsigned long *);
	virtual long get_PackageId(HSTRING__ * *);
	virtual long get_RacActivationTokenId(unsigned __int64 *);
	virtual long get_RegistrationScope(Windows::Foundation::RegistrationScope *);
	virtual long get_Size(unsigned int *);
	virtual long get_UserContext(unsigned __int64 *);
	virtual long get_Vendor(HSTRING__ * *);
	virtual long put_ComponentProcessId(_GUID);
	virtual long put_ConsoleHandlesId(unsigned __int64);
	virtual long put_HostId(unsigned __int64);
	virtual long put_LpacAttributes(tagBLOB *);
	virtual long put_OutOfProcActivationFlags(unsigned long);
	virtual long put_RacActivationTokenId(unsigned __int64);
	virtual long put_UserContext(unsigned __int64);
};

class CExtensionRegistrationsIterator
{
protected:
	long FindNextValidRegistration();
public:
	virtual long MoveNext(unsigned char *);
	virtual long get_Current(Windows::Foundation::IExtensionRegistration * *);
	virtual long get_HasCurrent(unsigned char *);
};

class CFastBH
{
	long CreateFromBindingHandle(void *,_RPC_BINDING_HANDLE_SECURITY_V1_W *,_GUID *);
	long CreateFromBindingString(unsigned short const *,_RPC_BINDING_HANDLE_SECURITY_V1_W *,_GUID *);
public:
	long GetOrCreate(void *,_RPC_BINDING_HANDLE_SECURITY_V1_W *,_GUID *,void * *);
};

class CFmCtrlUnknown
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CFreeMarshaler
{
	virtual long DisconnectObject(unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CGIPMessageParam
{
	CGIPMessageParam(unsigned long,_GUID);
};

class CGIPTable
{
	long AllocEntry(GIPEntry * *,unsigned long *);
	long ChangeUsageCount(GIPEntry *,long);
	long GetEntryPtr(unsigned long,GIPEntry * *);
	long GetRequestedInterface(IUnknown *,_GUID const &,void *,void * *);
	long LazyMarshalGIPEntry(unsigned long);
	long RevokeInterfaceInCurrentApartment(GIPEntry *);
	static CListBase<0> _InUseList;
	static COleStaticMutexSem _mxs;
	static int _fInNAUninit;
	static int _fInRevokeAll;
	void ContextOrApartmentCleanup(int);
	void FreeEntry(GIPEntry *);
public:
	long RegisterInterfaceInGlobalHlp(IUnknown *,_GUID const &,unsigned long,unsigned long *);
	long _RevokeInterfaceFromGlobal(unsigned long,bool);
	virtual long GetInterfaceFromGlobal(unsigned long,_GUID const &,void * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RegisterInterfaceInGlobal(IUnknown *,_GUID const &,unsigned long *);
	virtual long RevokeInterfaceFromGlobal(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void Cleanup();
	void Initialize();
	void RevokeAllEntries();
};

struct CGlobalOptions
{
	virtual long IsMethodInvocationAllowed(void *,int,unsigned long,int *,int *,unsigned long *);
	virtual long IsObjectCreationAllowed(void *,_GUID *,unsigned long,int,unsigned long,int *,int *,unsigned long *);
	virtual long Query(tagGLOBALOPT_PROPERTIES,unsigned __int64 *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Set(tagGLOBALOPT_PROPERTIES,unsigned __int64);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CGuidStr
{
	CGuidStr(_GUID const *);
};

class CHSTRINGUtil
{
	long ReplaceInTwoPasses(unsigned short const *,unsigned int,unsigned short const *,unsigned int,STRING_OPAQUE * *);
	long ReplaceWithSameLength(unsigned short const *,unsigned int,unsigned short const *,STRING_OPAQUE * *);
	static void ExpandInto(unsigned short *,unsigned short const *,unsigned int,unsigned short const *,unsigned int,unsigned short const *,unsigned int);
public:
	long Duplicate(STRING_OPAQUE * *);
};

class CHashTable
{
protected:
	SHashChain * Lookup(unsigned long,void const *);
	void Add(unsigned long,SHashChain *);
public:
	virtual int EnumAndRemove(int (*)(SHashChain *,void *),void *,unsigned long *,void * *);
	virtual void Cleanup(void (*)(SHashChain *));
	virtual void Initialize(SHashChain *,COleStaticMutexSem *);
	virtual void Initialize(SHashChain *,CRWLock *);
};

class CIDObject
{
	void SetZombie(unsigned long);
public:
	CIDObject(IUnknown *,unsigned long,unsigned long);
	int RemoveStdID(unsigned long);
	int RemoveWrapper();
	long CreateState(CObjectContext *);
	long Deactivate();
	long GetOrCreateStdID(unsigned long,CStdIdentity * *);
	long GetOrCreateWrapper(int,unsigned long,CStdWrapper * *);
	long Reactivate(IUnknown *);
	virtual int IsDeactivated();
	virtual int IsServer();
	virtual long GetIdentity(IUnknown * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void NotifyOIDIsPinned();
	void NotifyOIDIsUnpinned();
};

class CIPIDTable
{
	static CPageAllocator _palloc;
	static DiagnosticBuffer<_GUID,50> _lastRundownIPIDsBuffer;
	static tagIPIDEntry _oidListHead;
public:
	long LookupFromIPIDTables(_GUID const &,tagIPIDEntry * *,OXIDEntry * *);
	static bool IsIPIDRunDown(_GUID const &,tagIPIDEntry *);
	tagIPIDEntry * LookupConnectedServerIPID(_GUID const &,bool *);
	void Cleanup();
	void Initialize();
};

struct CInProcActivatableClassRegistration
{
	CInProcActivatableClassRegistration();
	virtual long FinalConstruct(IWinRTRuntimeClassInfo *);
	virtual long get_ActivationType(Windows::Foundation::ActivationType *);
	virtual long get_DllPath(HSTRING__ * *);
	virtual long get_ThreadingType(Windows::Foundation::ThreadingType *);
};

struct CInprocSystemActivator
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CInterfaceImplEnumerator
{
protected:
	virtual long _Enumerate(void * *,unsigned int *,unsigned long,unsigned long *);
};

class CInternalPageAllocator
{
	tagPageEntry * Grow();
public:
	tagPageEntry * GetEntryPtr(unsigned long);
	unsigned long GetEntryIndex(tagPageEntry const *);
	void Cleanup();
	void ReleaseEntryList(tagPageEntry *,tagPageEntry *);
};

struct CListBase<0>
{
	CListBase<0>();
	CListElement * Remove(CListElement *);
	void Insert(CListElement *);
	~CListBase<0>();
};

struct CListElement
{
	CListElement();
};

class CLocalMachineNames
{
	long GetNewDataIfNeeded();
public:
	virtual long Clone(IEnumString * *);
	virtual long Next(unsigned long,unsigned short * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RefreshNames();
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CMIDTable
{
	long AddMIDEntry(unsigned __int64 const &,unsigned long,tagDUALSTRINGARRAY *,MIDEntry * *);
	static CStringHashTable _HashTbl;
	static MIDEntry * _pLocalMIDEntry;
public:
	MIDEntry * LookupMID(tagDUALSTRINGARRAY *,unsigned long *);
	long FindOrCreateMIDEntry(unsigned __int64 const &,tagDUALSTRINGARRAY *,MIDEntry * *);
	long GetLocalMIDEntry(MIDEntry * *);
	long ReplaceLocalEntry(tagDUALSTRINGARRAY *);
	void Cleanup();
	void Initialize();
	void ReleaseMIDEntry(MIDEntry *);
};

struct CMREInnerUnknown
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CMachineGlobalObjectTable
{
	long VerifyApartmentCleanedUp(unsigned long);
	static long Create();
	virtual long EnumerateObjectIdentifiers(_GUID const &,Windows::Foundation::Collections::IVectorView<HSTRING__ *> * *);
	virtual long GetObject(_GUID const &,HSTRING__ *,_GUID const &,void * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RegisterObject(MGOTFLAGS,_GUID const &,HSTRING__ *,IUnknown *,<unnamed-type-MachineGlobalObjectTableRegistrationToken> * *);
	virtual long RevokeObject(<unnamed-type-MachineGlobalObjectTableRegistrationToken> *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CMachineNamesHelper
{
	static int QSortCompare(void const *,void const *);
	static void ParseStringArrayForUniques(unsigned long,unsigned short * *,void (*)(unsigned short *,void *),void *);
	static void ParseStringBindingsFromDSA(tagDUALSTRINGARRAY *,void (*)(void *,tagSTRINGBINDING *,unsigned long),void *);
	static void SBCallback(void *,tagSTRINGBINDING *,unsigned long);
	static void SBCallback2(void *,tagSTRINGBINDING *,unsigned long);
	static void UniqueStringCB(unsigned short *,void *);
	static void UniqueStringCB2(unsigned short *,void *);
public:
	static long Create(CDualStringArray *,CMachineNamesHelper * *);
	void DecRefCount();
};

struct CManualResetEvent
{
	CManualResetEvent(IUnknown *,long *);
	virtual long GetHandle(void * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Signal();
	virtual long Wait(unsigned long,unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CMarshalingStreamOnUserMarshalCallback
{
	virtual long GetMarshalingContextAttribute(CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
};

struct CMemStm
{
	static CMemStm * Create(void *,CRefMutexSem *);
	virtual long Clone(IStream * *);
	virtual long Commit(unsigned long);
	virtual long CopyTo(IStream *,_ULARGE_INTEGER,_ULARGE_INTEGER *,_ULARGE_INTEGER *);
	virtual long LockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Read(void *,unsigned long,unsigned long *);
	virtual long Revert();
	virtual long Seek(_LARGE_INTEGER,unsigned long,_ULARGE_INTEGER *);
	virtual long SetSize(_ULARGE_INTEGER);
	virtual long Stat(tagSTATSTG *,unsigned long);
	virtual long UnlockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long Write(void const *,unsigned long,unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CMessageCall
{
protected:
	CMessageCall(tagCALLCATEGORY,tagRPCOLEMESSAGE const *,unsigned long,_GUID const &,unsigned long,tagCOMVERSION,CChannelHandle *,bool,OXIDEntry *,_GUID const &,ComCallTraceActivity *,_GUID const *);
	ObjectLibrary::ReferencedPtr<IClientTransportCallEvents> GetClientTransportCallEvents();
	long CheckConditionsForOutofprocOutParameterMitigation();
	long EnableInParameterMarshalingMitigation();
	long EnableInprocOutParameterMarshalingMitigation();
	long EnableOutofprocOutParameterMarshalingMitigation();
	long EnsureInitMarshaledHandleStorage(MessageDirection);
	virtual ~CMessageCall();
	void CleanupMonitorLock();
	void NotifyClientCancelRequestRequiringAcknowledgment();
	void NotifyClientTransportCallCanceled();
	void NotifyClientTransportCallFailed(long);
public:
	CCtxCall * ObsoleteGetClientCtxCall();
	ObjectLibrary::ReferencedPtr<FtmMarshaledObjectContainer> GetFtmContainer(MessageDirection);
	long CallI_RpcGetBufferWithObject(_GUID const &);
	long CallI_RpcNegotiateTransferSyntax(_GUID const &);
	long CheckSuspend();
	long CleanupAllSystemHandles(MessageDirection);
	long ClientGetBuffer(tagRPCOLEMESSAGE *,_GUID const &,bool,bool,bool,_GUID const &,SourceOfClientHResult *,bool *);
	long GetOrCreateInBiasContainer(unsigned __int64 *);
	long GetOrCreateOutBiasContainer(unsigned __int64 *);
	long GetSystemHandle(MessageDirection,unsigned long,unsigned char,unsigned long,void * *);
	long IsClientAppContainer(bool *);
	long IsClientRpcss(bool *);
	long IsClientSuspendableByAnyLifecycleManager(bool *);
	long RslvCancel(unsigned long &,long,int,CCliModalLoop *);
	long ServerGetBuffer(tagRPCOLEMESSAGE *,_GUID const &,bool,unsigned long,_GUID const &,bool,_GUID const *);
	long SetSystemHandle(MessageDirection,void *,unsigned char,unsigned long,unsigned long *);
	long SetSystemHandlesOnRpcForRetry();
	static bool IsSpecialOldStyleAsyncInterface(_GUID const &);
	unsigned long GetTimeout();
	virtual bool UseRpcNotificationEvent();
	virtual long CallI_RpcFreeBuffer();
	virtual long OutofprocServerGetResponseBuffer(_GUID const &);
	virtual void * GetRpcNotificationEvent();
	virtual void Abort();
	virtual void ServerCompleteCall(long);
	virtual void ServerReply();
	void CleanupMarshaledHandleStorage(MessageDirection);
	void CleanupOnFreeBuffer();
	void HandleSuccessfulServerSend();
	void NotifyClientSourceOfClientHResultIdentified(SourceOfClientHResult);
	void NotifyClientTransportCallCompletionReceived();
	void NotifyServerAsyncCallCanceled();
	void ReleaseServerInterfaceIfNeeded();
	void RemoveParameterMitigationBiases();
	void SetSxsActCtx(void *);
	void SubscribeClientTransportCallEvents(IClientTransportCallEvents *);
	void SubscribeServerTransportCallEvents(IServerTransportCallEvents *);
	void UnsubscribeClientTransportCallEvents(IClientTransportCallEvents *);
	void UnsubscribeServerTransportCallEvents(IServerTransportCallEvents *);
};

class CMetadataEnumeratorT<unsigned int,IMetaDataImport2>
{
	struct Iterator
	{
		Iterator & operator++();
	};

protected:
	bool Enumerate(void * *,unsigned int *,unsigned long,unsigned long *);
public:
	CMetadataEnumeratorT<unsigned int,IMetaDataImport2>::Iterator begin();
	virtual ~CMetadataEnumeratorT<unsigned int,IMetaDataImport2>();
};

class CMethodEnumerator
{
protected:
	virtual long _Enumerate(void * *,unsigned int *,unsigned long,unsigned long *);
};

class CMethodParameterEnumerator
{
protected:
	virtual long _Enumerate(void * *,unsigned int *,unsigned long,unsigned long *);
};

struct CMultiGUIDHashTable
{
	virtual int Compare(void const *,SHashChain *,unsigned long);
};

struct CMutexSem2
{
	int FInit();
};

struct CNameHashTable
{
	long IncRef(unsigned long,_GUID const &,tagSECURITYBINDING *);
	unsigned long DecRef(unsigned long,_GUID const &,tagSECURITYBINDING *);
	unsigned long Hash(_GUID const &,tagSECURITYBINDING *);
	virtual int Compare(void const *,SHashChain *,unsigned long);
	void Cleanup();
};

struct CNdrStream
{
	virtual long Clone(IStream * *);
	virtual long Commit(unsigned long);
	virtual long CopyTo(IStream *,_ULARGE_INTEGER,_ULARGE_INTEGER *,_ULARGE_INTEGER *);
	virtual long GetMarshalingContextAttribute(CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetMarshalingDirectionAndLocality(ComCallMarshalingDirection *,ComCallMarshalingLocality *);
	virtual long LockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Read(void *,unsigned long,unsigned long *);
	virtual long Revert();
	virtual long Seek(_LARGE_INTEGER,unsigned long,_ULARGE_INTEGER *);
	virtual long SetSize(_ULARGE_INTEGER);
	virtual long Stat(tagSTATSTG *,unsigned long);
	virtual long UnlockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long Write(void const *,unsigned long,unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CNoEnum
{
	virtual long Clone(IEnumUnknown * *);
	virtual long Next(unsigned long,IUnknown * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CNoExtensionRegistrationsIterator
{
	virtual long MoveNext(unsigned char *);
	virtual long get_Current(Windows::Foundation::IExtensionRegistration * *);
	virtual long get_HasCurrent(unsigned char *);
};

struct CNullWalker
{
	virtual long OnWalkInterface(_GUID const &,void * *,int,int);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct COAccessControl
{
	class CImpAccessControl
	{
		long AddAccessList(tagSTREAM_ACE *,void *,unsigned long,unsigned long,unsigned long);
		long GetEffAccRights(_TRUSTEE_W *,unsigned long *);
		void CleanupAccessList(int,tagSTREAM_ACE *,void *,unsigned long,unsigned long);
	public:
		CImpAccessControl(IUnknown *,IUnknown *,long *);
		virtual long GetAllAccessRights(unsigned short *,_ACTRL_ALISTW * *,_TRUSTEE_W * *,_TRUSTEE_W * *);
		virtual long GetClassID(_GUID *);
		virtual long GetSizeMax(_ULARGE_INTEGER *);
		virtual long GrantAccessRights(_ACTRL_ALISTW *);
		virtual long IsAccessAllowed(_TRUSTEE_W *,unsigned short *,unsigned long,int *);
		virtual long IsDirty();
		virtual long Load(IStream *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual long RevokeAccessRights(unsigned short *,unsigned long,_TRUSTEE_W * const);
		virtual long Save(IStream *,int);
		virtual long SetAccessRights(_ACTRL_ALISTW *);
		virtual long SetOwner(_TRUSTEE_W *,_TRUSTEE_W *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
	};

	long Init(IUnknown *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct COIDHashTable
{
	virtual int Compare(void const *,SHashChain *,unsigned long);
	virtual unsigned long HashNode(SHashChain *);
};

class COIDTable
{
	static COIDHashTable s_OIDHashTbl;
	static SHashChain * s_OIDBuckets;
	static SHashChain s_OIDUnpinRequests;
	static int s_fInitialized;
	static unsigned long s_UnpinReqsPending;
public:
	static void SpecialCleanup(CIDObject *);
	static void ThreadCleanup();
	void Add(CIDObject *);
	void AddOIDUnpinRequest(CIDObject *);
	void GetServerOidsToUnpin(unsigned __int64 *,unsigned long *);
	void NotifyUnpinOutcome(int);
	void Remove(CIDObject *);
};

struct COLEDragDropHelper
{
	virtual long IsDragDropActive(int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetForcedDropTarget(HWND__ *,int);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class COXIDTable
{
	OXIDEntry * LookupOXID(unsigned __int64 const &,unsigned __int64 const &);
	OXIDEntry * SearchList(_GUID const &,CListElement *);
	long AddOXIDEntry(unsigned __int64 const &,tagOXID_INFO const *,MIDEntry *,unsigned long,std::unique_ptr<unsigned char [0],DeleteMarshaledTargetInfo>,unsigned long,OXIDEntry * *);
	static CListBase<0> _CleanupList;
	static CListBase<0> _ExpireList;
	static CListBase<0> _InUseList;
	static unsigned long _cExpired;
	void FreeCleanupEntries();
public:
	long ClientResolveMachineLocalOXID(unsigned __int64 const &,OXIDEntry * *);
	long ClientResolveOXID(unsigned __int64 const &,tagDUALSTRINGARRAY *,OXIDEntry * *);
	long FindOrCreateMachineLocalOXIDEntry(unsigned __int64 const &,tagOXID_INFO const &,tagFOCOXID,unsigned long,std::unique_ptr<unsigned char [0],DeleteMarshaledTargetInfo>,unsigned long,OXIDEntry * *);
	long FindOrCreateOXIDEntry(unsigned __int64 const &,tagOXID_INFO const &,tagFOCOXID,tagDUALSTRINGARRAY *,unsigned __int64 const &,MIDEntry *,unsigned long,std::unique_ptr<unsigned char [0],DeleteMarshaledTargetInfo>,unsigned long,OXIDEntry * *);
	long MakeSCMEntry(unsigned __int64 const &,tagOXID_INFO const *,OXIDEntry * *);
	long MakeServerEntry(unsigned long,OXIDEntry * *);
	long UpdateCachedLocalMIDEntries();
	void Cleanup();
	void FreeExpiredEntries(unsigned long);
	void Initialize();
	void ReleaseOXIDEntry(OXIDEntry *);
};

struct CObjServer
{
	CObjServer(long &);
	virtual long CreateInstance(IUnknown *,IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long CreateWinRTInstance(IUnknown *,_GUID,HSTRING__ *,unsigned long,IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long GetClassObject(IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long GetPersistentInstance(_GUID *,unsigned long,unsigned short *,tagMInterfacePointer *,unsigned long,_GUID *,tagMInterfacePointer *,tagMInterfacePointer * *,long *,CDestObject *);
	virtual long GetWinRTActivationFactory(_GUID,HSTRING__ *,unsigned long,IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long ObjectServerLoadDll(_GUID *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void ReleaseStdID();
};

class CObjectContext
{
	CObjectContext(unsigned long,_GUID const &);
	static CPageAllocator s_CXAllocator;
	static int s_fInitialized;
	static unsigned long s_cInstances;
	~CObjectContext();
public:
	CContextLife * GetLife();
	int PadStream(IStream * &);
	long GetEnvoyData(tagDATAELEMENT * *);
	long GetPropertiesSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long,int,unsigned long &);
	long MarshalEnvoyProperties(unsigned long &,tagContextProperty * &,IStream *,unsigned long);
	long MarshalProperties(unsigned long &,tagContextProperty * &,IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	long MarshalPropertyHeader(IStream * &,_GUID const &,tagContextProperty *,_ULARGE_INTEGER &,_ULARGE_INTEGER &);
	long QIHelper(_GUID const &,void * *,int);
	long ReadStreamHdrAndProcessExtents(IStream *,tagCONTEXTHEADER &);
	long Reset(void * *);
	long SetEnvoyData(tagDATAELEMENT *);
	static CObjectContext * CreateAndFreezeDefaultObjectContext(CComApartment *);
	static CObjectContext * CreateObjectContext(unsigned long);
	static long CreateEnvoyObjectContext(tagDATAELEMENT *,CObjectContext * &);
	static long CreatePrototypeContext(CObjectContext *,CObjectContext * *);
	static void * operator new(unsigned __int64);
	static void Initialize();
	static void operator delete(void *);
	tagContextProperty * GetNextProperty(void * *);
	unsigned long CommonRelease();
	unsigned long InternalRelease();
	virtual long Aggregate(IUnknown *);
	virtual long ClearContextFlags(unsigned long);
	virtual long ContextCallback(long (*)(tagComCallData *),tagComCallData *,_GUID const &,int,IUnknown *);
	virtual long DisconnectObject(unsigned long);
	virtual long DoCallback(long (*)(void *),void *,_GUID const &,unsigned int);
	virtual long EnumContextProps(IEnumContextProps * *);
	virtual long Freeze();
	virtual long FreezeWithApartmentSet();
	virtual long GetContextFlags(unsigned long *);
	virtual long GetContextId(_GUID *);
	virtual long GetContextMarshaler(IContextMarshaler * *);
	virtual long GetCurrentApartmentType(_APTTYPE *);
	virtual long GetCurrentLogicalThreadId(_GUID *);
	virtual long GetCurrentThreadType(_THDTYPE *);
	virtual long GetEnvoySizeMax(unsigned long,unsigned long *);
	virtual long GetEnvoyUnmarshalClass(unsigned long,_GUID *);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long GetProperty(_GUID const &,unsigned long *,IUnknown * *);
	virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
	virtual long InternalContextCallback(long (*)(void *),void *,_GUID const &,int,IUnknown *);
	virtual long MarshalEnvoy(IStream *,unsigned long);
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long ReleaseMarshalData(IStream *);
	virtual long RemoveProperty(_GUID const &);
	virtual long SetContextFlags(unsigned long);
	virtual long SetContextMarshaler(IContextMarshaler *);
	virtual long SetCurrentLogicalThreadId(_GUID const &);
	virtual long SetProperty(_GUID const &,unsigned long,IUnknown *);
	virtual long UnmarshalEnvoy(IStream *,_GUID const &,void * *);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void CleanupTables();
	void NotifyContextAbandonment();
	void NotifyServerException(_EXCEPTION_POINTERS *);
};

struct COle32DebugEventFire
{
	virtual void _CreateLogger();
	virtual void _DestroyLogger();
};

struct COleStaticMutexSem
{
	int YieldUntilWoken(char const *,unsigned long,COleConditionVariable *,unsigned long);
	long Init();
	void Release();
	void Request(char const *,unsigned long,char const *);
	~COleStaticMutexSem();
};

struct COleTls
{
	long TLSAllocData();
	void SetFromPrealloc(tagSOleTlsData *);
};

struct COutOfProcActivatableClassRegistration
{
	virtual long FinalConstruct(IWinRTRuntimeClassInfo *,IWinRTServerInfo *);
	virtual long get_ActivationType(Windows::Foundation::ActivationType *);
	virtual long get_ServerRegistration(Windows::Foundation::IExeServerRegistration * *);
};

struct CPIDHashTable
{
	virtual int Compare(void const *,SHashChain *,unsigned long);
	virtual unsigned long HashNode(SHashChain *);
};

class CPIDTable
{
	static CPIDHashTable s_PIDHashTbl;
	static SHashChain * s_PIDBuckets;
	static int s_fInitialized;
public:
	CIDObject * Lookup(IUnknown *,CObjectContext *,int);
	long Add(CIDObject *);
	long FindOrCreateIDObject(IUnknown *,CObjectContext *,bool,unsigned long,bool,CIDObject * *);
	static void ThreadCleanup();
};

struct CPSHashTable
{
	virtual int Compare(void const *,SHashChain *,unsigned long);
	virtual unsigned long HashNode(SHashChain *);
};

class CPSTable
{
	static CPSHashTable s_PSHashTbl;
	static SHashChain * s_PSBuckets;
	static int s_fInitialized;
public:
	long Lookup(CObjectContext *,CObjectContext *,CPolicySet * *);
	static void Initialize();
	void Add(CPolicySet *);
};

class CPackagedComCatalog
{
	struct CClassRegistration
	{
		virtual long CanBeCached(int *);
		virtual long GetApplicationName(HSTRING__ * *);
		virtual long GetClassContext(tagCLSCTX,tagCLSCTX *);
		virtual long GetClassNameW(unsigned short const * *);
		virtual long GetConfiguredClsid(_GUID * *);
		virtual long GetConversionReadWritable(HSTRING__ * *);
		virtual long GetConversionReadable(HSTRING__ * *);
		virtual long GetDataFormats(HSTRING__ * *);
		virtual long GetDefaultFormatName(HSTRING__ * *);
		virtual long GetDefaultIcon(HSTRING__ * *);
		virtual long GetDeployingPackageName(unsigned short const * *);
		virtual long GetDisplayName(HSTRING__ * *);
		virtual long GetExecutionPackageName(unsigned short const * *);
		virtual long GetImplementedCategories(Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
		virtual long GetImplementedClsid(_GUID * *);
		virtual long GetLocalServerType(tagLocalServerType *);
		virtual long GetMiscStatusAspects(Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
		virtual long GetMiscStatusDefault(HSTRING__ * *);
		virtual long GetModulePath(tagCLSCTX,unsigned short * *);
		virtual long GetProcess(_GUID const &,void * *);
		virtual long GetProgId(unsigned short * *);
		virtual long GetServerExecutable(unsigned short * *);
		virtual long GetShortDisplayName(HSTRING__ * *);
		virtual long GetSource(RegistrationSource *);
		virtual long GetSurrogateCommandLine(unsigned short * *);
		virtual long GetThreadingModel(ThreadingModel *);
		virtual long GetToolboxBitmap32(HSTRING__ * *);
		virtual long GetVerbs(Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
		virtual long IsInsertable(bool *);
		virtual long RefreshNeeded(IUserToken *,int *);
		virtual ~CClassRegistration();
	};

	struct CPackagedComClassIdIterator
	{
		CPackagedComClassIdIterator();
		long RuntimeClassInitialize();
		long RuntimeClassInitialize(CPackagedComClassIdIterator const &);
		virtual long Clone(IPackagedComClassIdIterator * *);
		virtual long Next(_GUID *);
		virtual long Reset();
	};

	struct CPackagedComProgIdIterator
	{
		CPackagedComProgIdIterator();
		long RuntimeClassInitialize();
		virtual long Next(HSTRING__ * *,_GUID *);
	};

	struct CPackagedComProxyStubClassInfo
	{
		CPackagedComProxyStubClassInfo(_GUID const &,OpaqueString &);
		virtual long GetClassContext(tagCLSCTX,tagCLSCTX *);
		virtual long GetConfiguredClsid(_GUID * *);
		virtual long GetImplementedClsid(_GUID * *);
		virtual long GetModulePath(tagCLSCTX,unsigned short * *);
		virtual long GetThreadingModel(ThreadingModel *);
	};

	class CPackagedComTypeLibRegistration
	{
		long GetPackagedFilePathAsBStr(OpaqueString const &,unsigned short * *);
		long OpaqueStringToBStr(OpaqueString const &,unsigned short * *);
	public:
		virtual long GetDisplayName(unsigned short * *);
		virtual long GetFlags(unsigned long *);
		virtual long GetGuid(_GUID *);
		virtual long GetHelpDir(unsigned short * *);
		virtual long GetLcid(unsigned long *);
		virtual long GetVersion(unsigned short * *);
		virtual long GetWin32Path(unsigned short * *);
		virtual long GetWin64Path(unsigned short * *);
	};

	class CPackagedComTypeLibRegistrationIterator
	{
		long NextTypeLibHandle();
		long NextTypeLibId();
	public:
		CPackagedComTypeLibRegistrationIterator();
		long RuntimeClassInitialize();
		long RuntimeClassInitialize(CPackagedComTypeLibRegistrationIterator const &);
		virtual long Clone(ITypeLibRegistrationIterator * *);
		virtual long Next(ITypeLibRegistration * *);
		virtual long Reset();
		virtual ~CPackagedComTypeLibRegistrationIterator();
	};

	struct CServerRegistration
	{
		OpaqueString GetCommandLineW();
		OpaqueString GetExecutableAbsolutePath();
		bool HasSystemSurrogate();
		virtual long CanBeCached(int *);
		virtual long GetAccessPermission(void * *,unsigned long *);
		virtual long GetApplicationId(unsigned short const * *);
		virtual long GetDeployingPackageName(unsigned short const * *);
		virtual long GetExecutionPackageName(unsigned short const * *);
		virtual long GetLaunchPermission(void * *,unsigned long *);
		virtual long GetProcessId(_GUID * *);
		virtual long GetProcessName(unsigned short * *);
		virtual long GetProcessType(tagProcessType *);
		virtual long GetRunAsType(tagRunAsType *);
		virtual long GetSource(RegistrationSource *);
		virtual long GetSurrogatePath(unsigned short * *);
		virtual long RefreshNeeded(IUserToken *,int *);
	};

	struct TypeLibVersionLocaleIdPairLifetimeTraits
	{
		static long Construct(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair *,PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair const &);
	};

	struct TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate
	{
		long operator()(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair const &,PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair const &,bool *);
	};

	static long CalculateClassBinaryAndCommandLineProperties(IUserTokenInternal *,OpaqueString const &,_GUID const &,ComClassRegistrationEntryProperties const &,CPackagedComCatalog::CServerRegistration const *,OpaqueString &,CPackagedComCatalog::ExecutablePathAndCommandLine &);
	static long CalculateServerBinaryAndCommandLineProperties(IUserTokenInternal *,OpaqueString const &,ComServerRegistrationEntryProperties const &,CPackagedComCatalog::ExecutablePathAndCommandLine &);
	static long CalculateServerExecutionPackage(IUserTokenInternal *,OpaqueString const &,ComServerRegistrationEntryProperties const &,OpaqueString &);
	static long ConstructCommandLine(OpaqueString const &,OpaqueString const &,OpaqueString &);
	static long GetClassInfoFromProgIdWorker(IPackagedComCatalogContext *,unsigned short const *,_GUID const &,void * *);
	static long GetClassInfoWorker(tagCLSCTX,IUserTokenInternal *,IPackagedComCatalogContext *,OpaqueString const &,bool,_GUID const &,_GUID const &,void * *);
	static long GetInstalledPackagesContainingEntry<ComClassRegistrationEntryProperties>(PackageListBuffer &,IUserTokenInternal *,IPackagedComCatalogContext *,_GUID const &,unsigned __int64,PACKAGE_INFO const *);
	static long GetInstalledPackagesContainingEntry<ComInterfaceRegistrationEntryProperties>(PackageListBuffer &,IUserTokenInternal *,IPackagedComCatalogContext *,_GUID const &,unsigned __int64,PACKAGE_INFO const *);
	static long GetInstalledPackagesContainingEntry<ComTypeLibVersionRegistrationEntryProperties>(PackageListBuffer &,IUserTokenInternal *,IPackagedComCatalogContext *,_GUID const &,unsigned __int64,PACKAGE_INFO const *);
	static long GetPackagedFilePath(OpaqueString const &,OpaqueString const &,OpaqueString &);
	static long GetPackagedSystemMetadataFilePath(OpaqueString const &,OpaqueString const &,OpaqueString &);
	static long GetProcessInfoWorker(IUserTokenInternal *,IPackagedComCatalogContext *,OpaqueString const &,_GUID const &,_GUID const &,void * *);
	static long GetServerRegistration(IUserTokenInternal *,IPackagedComCatalogContext *,OpaqueString const &,unsigned int,CPackagedComCatalog::CServerRegistration * *);
	static long GetSystemFilePath(unsigned long,HSTRING__ *,OpaqueString &);
	static long GetTreatAsClassWorker(IUserTokenInternal *,IPackagedComCatalogContext *,OpaqueString const &,bool,_GUID const &,_GUID *,HSTRING__ * *);
	static long GetTypeLibPathFromProperties(ComTypeLibVersionRegistrationEntryProperties const &,OpaqueString const &,HSTRING__ * *);
	static long ParseTypeLibVersionString(HSTRING__ *,CPackagedComCatalog::TypeLibVersion *);
	static long ReadHighestTypeLibVersionEntry(ComTypeLibVersionRegistrationEntryProperties &,IPackagedComCatalogContext *,OpaqueString const &,_GUID const &,CPackagedComCatalog::TypeLibVersion,bool,CPackagedComCatalog::TypeLibVersion *);
	static long ReadTypeLibVersionEntry(ComTypeLibVersionRegistrationEntryProperties &,IPackagedComCatalogContext *,OpaqueString const &,_GUID const &,OpaqueString const &);
	static long ResolveAndReadEntry<ComClassRegistrationEntryProperties,long (*)(OpaqueString const &,ComClassRegistrationEntryProperties const &,bool *)>(ComClassRegistrationEntryProperties &,HSTRING__ * *,IUserTokenInternal *,IPackagedComCatalogContext *,_GUID const &,unsigned short const *,long (*)(OpaqueString const &,ComClassRegistrationEntryProperties const &,bool *));
	static long ResolveAndReadEntry<ComInterfaceRegistrationEntryProperties,long (*)(OpaqueString const &,ComInterfaceRegistrationEntryProperties const &,bool *)>(ComInterfaceRegistrationEntryProperties &,HSTRING__ * *,IUserTokenInternal *,IPackagedComCatalogContext *,_GUID const &,unsigned short const *,long (*)(OpaqueString const &,ComInterfaceRegistrationEntryProperties const &,bool *));
	static long ResolveAndReadEntry<ComProgIdRegistrationEntryProperties,long (*)(OpaqueString const &,ComProgIdRegistrationEntryProperties const &,bool *)>(ComProgIdRegistrationEntryProperties &,HSTRING__ * *,IUserTokenInternal *,IPackagedComCatalogContext *,HSTRING__ *,unsigned short const *,long (*)(OpaqueString const &,ComProgIdRegistrationEntryProperties const &,bool *));
	static long ResolveAndReadEntry<ComTreatAsClassRegistrationEntryProperties,long (*)(OpaqueString const &,ComTreatAsClassRegistrationEntryProperties const &,bool *)>(ComTreatAsClassRegistrationEntryProperties &,HSTRING__ * *,IUserTokenInternal *,IPackagedComCatalogContext *,_GUID const &,unsigned short const *,long (*)(OpaqueString const &,ComTreatAsClassRegistrationEntryProperties const &,bool *));
	static long ResolveAndReadTypeLibVersionEntry(ComTypeLibVersionRegistrationEntryProperties &,HSTRING__ * *,_GUID const &,CPackagedComCatalog::TypeLibVersion,unsigned long,bool,CPackagedComCatalog::TypeLibVersion *);
	static long ValidateClassRegistrationProperties(OpaqueString const &,_GUID const &,ComClassRegistrationEntryProperties const &,CPackagedComCatalog::CServerRegistration *);
	static long ValidateInterfaceRegistrationProperties(OpaqueString const &,_GUID const &,ComInterfaceRegistrationEntryProperties const &);
	static long ValidateServerRegistrationProperties(OpaqueString const &,unsigned int,ComServerRegistrationEntryProperties const &);
	static long ValidateTypeLibVersionRegistrationProperties(OpaqueString const &,_GUID const &,OpaqueString const &,ComTypeLibVersionRegistrationEntryProperties const &);
	static void LogReadEntryResult(long,ComClassRegistrationEntryProperties const &,OpaqueString const &,_GUID const &,ComClassRegistrationEntryPropertyFlags,ComClassRegistrationEntryPropertyFlags);
	static void LogReadEntryResult(long,ComInterfaceRegistrationEntryProperties const &,OpaqueString const &,_GUID const &,ComInterfaceRegistrationEntryPropertyFlags,ComInterfaceRegistrationEntryPropertyFlags);
	static void LogReadEntryResult(long,ComProgIdRegistrationEntryProperties const &,OpaqueString const &,HSTRING__ *,ComProgIdRegistrationEntryPropertyFlags,ComProgIdRegistrationEntryPropertyFlags);
	static void LogReadEntryResult(long,ComProxyStubRegistrationEntryProperties const &,OpaqueString const &,_GUID const &,ComProxyStubRegistrationEntryPropertyFlags,ComProxyStubRegistrationEntryPropertyFlags);
	static void LogReadEntryResult(long,ComServerRegistrationEntryProperties const &,OpaqueString const &,unsigned int,ComServerRegistrationEntryPropertyFlags,ComServerRegistrationEntryPropertyFlags);
	static void LogReadEntryResult(long,ComTreatAsClassRegistrationEntryProperties const &,OpaqueString const &,_GUID const &,ComTreatAsClassRegistrationEntryPropertyFlags,ComTreatAsClassRegistrationEntryPropertyFlags);
	static void LogReadEntryResult(long,ComTypeLibVersionRegistrationEntryProperties const &,OpaqueString const &,_GUID const &,OpaqueString const &,ComTypeLibVersionRegistrationEntryPropertyFlags,ComTypeLibVersionRegistrationEntryPropertyFlags);
public:
	CPackagedComCatalog(bool);
	long GetProxyStubDllPath(IPackagedComCatalogContext *,_GUID const &,OpaqueString const &,OpaqueString &);
	long GetTypeLibPathForInterface(ComInterfaceRegistrationEntryProperties const &,IPackagedComCatalogContext *,OpaqueString const &,HSTRING__ * *);
	virtual bool IsTypeLibRegistered(_GUID const &,HSTRING__ *,unsigned long);
	virtual long GetAutoConvertTo(_GUID const &,_GUID *);
	virtual long GetClassInfoFromProgId(IUserToken *,unsigned short *,_GUID const &,void * *,void *);
	virtual long GetClassInfoW(unsigned long,IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetCounterpartIid(_GUID const &,bool,_GUID *);
	virtual long GetHelpDirectory(_GUID const &,unsigned long,unsigned long,unsigned long,HSTRING__ * *);
	virtual long GetIidProxyStubRegistrationInfo(_GUID const &,HSTRING__ * *,UniversalMarshalerType *,_GUID *);
	virtual long GetIidTypeLibRegistrationInfo(_GUID const &,HSTRING__ * *);
	virtual long GetPackagedComClassIdIterator(IPackagedComClassIdIterator * *);
	virtual long GetPackagedComProgIdIterator(IPackagedComProgIdIterator * *);
	virtual long GetPackagedProxyStubClassInfo(_GUID const &,HSTRING__ *,IComClassInfo * *);
	virtual long GetProcessInfo(IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetTreatAsClass(_GUID const &,_GUID *);
	virtual long GetTypeLibPath(_GUID const &,unsigned long,unsigned long,bool,unsigned long,HSTRING__ * *,unsigned long *,unsigned long *);
	virtual long GetTypeLibRegistrationIterator(ITypeLibRegistrationIterator * *);
};

class CPageAllocator
{
	int InitializeHeap(COleStaticMutexSem *);
public:
	long VerifyEntry(void const *);
	tagPageEntry * AllocEntry(int);
	tagPageEntry * GetEntryPtr(unsigned long);
	void Cleanup();
	void Initialize(unsigned __int64,unsigned short,COleStaticMutexSem *,unsigned long);
	void ReleaseEntry(tagPageEntry *);
};

struct CPerInterfacePSFactory
{
	virtual long CreateProxy(IUnknown *,_GUID const &,IRpcProxyBuffer * *,void * *);
	virtual long CreateStub(_GUID const &,IUnknown *,IRpcStubBuffer * *);
	virtual long GetMethodProperty(unsigned short,unsigned long,unsigned __int64 *);
};

struct CPipePSFactory
{
	virtual long CreateProxy(IUnknown *,_GUID const &,IRpcProxyBuffer * *,void * *);
	virtual long CreateStub(_GUID const &,IUnknown *,IRpcStubBuffer * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CPipeProxyImp
{
	virtual long Connect(IRpcChannelBuffer *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual void Disconnect();
	virtual ~CPipeProxyImp();
};

struct CPolicySet
{
	long DeliverEvents(CRpcCall *,tagCallType,CCtxCall *);
	long FillBuffer(CRpcCall *,tagCallType,CCtxCall *);
	long GetSize(CRpcCall *,tagCallType,CCtxCall *);
	long Notify(CRpcCall *,tagCallType,CCtxCall *);
	virtual long AddPolicy(unsigned long,_GUID const &,IPolicy *);
	virtual long QueryInterface(_GUID const &,void * *);
};

class CPrivateHiveCatalog
{
protected:
	virtual bool IgnoreRunAsInteractiveUser();
	virtual bool RegistrationsArePackaged();
	virtual bool SelectDllHostBitnessBasedOnDllBitness();
	virtual bool Supports16BitRegistrations();
	virtual bool SupportsActivateAtStorage();
	virtual bool SupportsApplicationId();
	virtual bool SupportsDarwinId();
	virtual bool SupportsForceHKLM();
	virtual bool SupportsGetProgId();
	virtual bool SupportsLUAAndDisplaySettings();
	virtual bool SupportsLoadUserSettings();
	virtual bool SupportsPreferredServerBitness();
	virtual bool SupportsProcessMitigationPolicy();
	virtual bool SupportsROTAppIDAndMGOTFlags();
	virtual bool SupportsRemoteServerName();
	virtual bool SupportsSRPTrustLevel();
	virtual long GetComRootKeyForUserToken(IUserToken *,HKEY__ * *);
	virtual long OpenKeyInOtherView(HKEY__ *,unsigned short const *,unsigned long,HKEY__ * *);
	virtual unsigned long CatalogFlagsForAppID();
	virtual unsigned long ExpectedOutofprocServerBinaryArchitecture();
	virtual unsigned long GetViewFlagFor(CComRegCatalog::WhichView);
	virtual unsigned short GetWowArchitectureFor(CComRegCatalog::WhichView);
	virtual void ReleaseComRootKeyForUserToken(IUserToken *);
};

class CProcGen
{
	bool IsHomogeneous(unsigned char const *,FORMAT_CHARACTER);
	long CalcSize(unsigned short,unsigned long,unsigned long);
	long GenParamDescriptor(PARAMINFO *,unsigned char *);
	long SetShort(unsigned short,unsigned short);
	void AnalyzeFloatTypes(unsigned short,unsigned short);
public:
	long GetProcFormat(CTypeGen *,ITypeInfo *,tagFUNCDESC *,unsigned short,unsigned char const *,unsigned short *);
};

class CProcessActivator
{
	virtual long ActivateByContext(ActivationPropertiesIn *,IUnknown *,IActivationPropertiesIn *,IActivationPropertiesOut * *,long ( CProcessActivator::*)(unsigned long,IUnknown *,ActivationPropertiesIn *,IActivationPropertiesIn *,IActivationPropertiesOut * *));
	virtual long AttemptActivation(ActivationPropertiesIn *,IUnknown *,IActivationPropertiesIn *,IActivationPropertiesOut * *,long ( CProcessActivator::*)(unsigned long,IUnknown *,ActivationPropertiesIn *,IActivationPropertiesIn *,IActivationPropertiesOut * *),unsigned long);
	virtual long CCICallback(unsigned long,IUnknown *,ActivationPropertiesIn *,IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long GCOCallback(unsigned long,IUnknown *,ActivationPropertiesIn *,IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long GetApartmentActivator(ActivationPropertiesIn *,ISystemActivator * *);
public:
	virtual long CreateInstance(IUnknown *,IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long GetClassObject(IActivationPropertiesIn *,IActivationPropertiesOut * *);
};

class CProcessSecret
{
	static COleStaticMutexSem s_SecretLock;
	static _GUID s_guidOle32Secret;
	static int s_fSecretInit;
public:
	long GetProcessSecret(_GUID *);
	long VerifyMatchingSecret(_GUID);
};

struct CPunkForRelease
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CRGTypeSizes
{
	static unsigned char const * const m_ucTypeSizesA;
	static unsigned char const * const m_ucTypeSizesB;
};

class CRIFTable
{
	struct tagRIFEntry
	{
		tagRIFEntry();
	};

	CRIFTable::tagRIFEntry * PreFillKnownIIDs(_GUID const &);
	long AddEntry(_GUID const &,_GUID const &,unsigned long,CRIFTable::tagRIFEntry * *,bool,UniversalMarshalerType,ObjectLibrary::OpaqueString);
	long GetPSClsidHelper(_GUID const &,bool,_GUID *,CRIFTable::tagRIFEntry * *);
	long InterfaceMapHelper(_GUID const &,_GUID *,int);
	long RegisterClientInterfaceHelper(CRIFTable::tagRIFEntry *,IRpcProxyBuffer *);
	long RegisterInterfaceMapping(_GUID const &,_GUID const &,unsigned long,CRIFTable::tagRIFEntry *);
	static COleStaticMutexSem _mxs;
	static CUUIDHashTable _HashTbl;
	static bool IsRifEntryProxyStubInfoStale(CRIFTable::tagRIFEntry *,_GUID const &,bool,UniversalMarshalerType,ObjectLibrary::OpaqueString &);
	static int FreeUnusedCachedFactoriesHelper(SHashChain *,void *);
	static int UnregisterUnusedHelper(SHashChain *,void *);
	static int _fPreFilled;
	static void CleanupRIFEntry(SHashChain *);
	void AddRefRegisteredClientInterfaceHelper(CRIFTable::tagRIFEntry *);
	void AddRefRegisteredServerInterfaceHelper(CRIFTable::tagRIFEntry *);
	void ReleaseClientInterfaceHelper(CRIFTable::tagRIFEntry *);
	void UnregisterClientInterface(CRIFTable::tagRIFEntry *);
	void UnregisterServerInterface(CRIFTable::tagRIFEntry *);
public:
	bool IsRegisteredInterfaceIInspectableOrDerived(_GUID const &);
	long AttemptFreeUnusedCachedFactories();
	long GetMethodProperties(_GUID const &,unsigned short,unsigned long,unsigned long const *,unsigned __int64 *);
	long GetPSClsidAndObject(_GUID const &,bool,_GUID *,bool *,UniversalMarshalerType *,ObjectLibrary::OpaqueString *,bool *,IPerInterfacePSFactory * *);
	long RegisterPSClsid(_GUID const &,_GUID const &);
	long RegisterServerInterface(_GUID const &,IRpcStubBuffer *);
	long TryAddRefServerInterface(_GUID const &);
	void AddRefClientInterface(_GUID const &);
	void CachePSFactory(_GUID const &,IPerInterfacePSFactory *);
	void Cleanup();
	void FlushCachedProxyStubInfoIfNotStale(_GUID const &,_GUID const &,bool,UniversalMarshalerType,ObjectLibrary::OpaqueString &);
	void Initialize();
	void MarkProxyStubSuccessfullyActivatedIfNotStale(_GUID const &,_GUID const &,bool,UniversalMarshalerType,ObjectLibrary::OpaqueString &);
	void ReleaseClientInterface(_GUID const &);
	void ReleaseServerInterface(_GUID const &);
	void UnregisterUnused();
};

class CROIDTable
{
	long EnsureWorkerThread();
	static CUUIDHashTable _ClientRegisteredOIDs;
	static SOIDRegistration _ClientOIDRegList;
	static int _fWorker;
	static long ClientBulkUpdateOIDWithPingServer(unsigned long,unsigned long);
	static unsigned long WorkerThreadLoop(void *);
	static unsigned long _cOidsToAdd;
	static unsigned long _cOidsToRemove;
	static unsigned long _dwSleepPeriod;
	static unsigned long _ulWorkerThreadSequence;
public:
	SOIDRegistration * LookupSOID(_GUID const &,unsigned long *);
	long ClientDeRegisterOIDFromPingServer(CRefCache *,int);
	long ForceImmediateBulkUpdateWithPingServerForAdds();
	void ChangeBulkUpdateRate();
	void Cleanup();
	void IncOIDRefCnt(SOIDRegistration *);
	void Initialize();
	void NotifyWorkWaiting();
};

class CRWLock
{
	EventPoolEntry * GetPoolEntry();
	int AttemptToPoolEntry();
	int ReleasePoolEntry();
	unsigned long RWWaitForReaderSignal(unsigned long,int &);
	unsigned long RWWaitForWriterSignal(unsigned long,int &);
	void RWResetReaderSignal();
	void RWSetReaderSignal();
	void RWSetWriterSignal();
public:
	int HeldExclusive();
	static int ProcessInit();
	static void ProcessCleanup();
	static void RWLockFailfast();
	unsigned long AcquireReaderLock(unsigned long);
	unsigned long AcquireWriterLock(unsigned long);
	unsigned long DowngradeFromWriterLock(LockCookie *);
	unsigned long ReleaseLock(LockCookie *);
	unsigned long ReleaseReaderLock();
	unsigned long ReleaseWriterLock();
	unsigned long RestoreLock(LockCookie *,int *);
	unsigned long UpgradeToWriterLock(LockCookie *,int *,unsigned long);
	void Cleanup();
};

struct CRandomNumberGenerator
{
	long GenerateRandomNumber(unsigned char *,unsigned long);
};

struct CReadInterfaceDataFromInternalSourceMarshalingStream
{
	virtual long GetMarshalingContextAttribute(CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
};

struct CReadInterfaceDataWithSourceAttributesMarshalingStream
{
	virtual long GetMarshalingContextAttribute(CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
};

struct CReadMInterfacePointerWithSourceAttributesMarshalingStream
{
	virtual long GetMarshalingContextAttribute(CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
};

struct CReadWithSourceAttributesMarshalingStreamOnBuffer
{
	virtual long GetMarshalingContextAttribute(CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long Write(void const *,unsigned long,unsigned long *);
};

class CRefCache
{
	void CleanupStrong(bool,unsigned short,unsigned short *,tagREMINTERFACEREF *);
	void CleanupWeak(RifRefBuffer &);
	void CleanupWeak(unsigned short,unsigned short *,tagREMINTERFACEREF *);
public:
	long GetSharedRefs(tagIPIDEntry *,unsigned long);
	unsigned long DecRefCnt();
	unsigned long DecTableStrongCnt(int,unsigned short,unsigned short *,tagREMINTERFACEREF *);
	void ChangeRef(tagIPIDEntry *,int,RifRefBuffer &,RifRefBuffer &);
	void ChangeRef(tagIPIDEntry *,int,unsigned short,unsigned short *,tagREMINTERFACEREF *,unsigned short,unsigned short *,tagREMINTERFACEREF *);
	void GiveUpRefs(tagIPIDEntry *);
};

struct CRefMutexSem
{
	static CRefMutexSem * CreateInstance();
};

class CRemoteUnknown
{
	long GetSecBinding(tagSECURITYBINDING * *);
public:
	CRemoteUnknown(long &,_GUID *);
	long RemAddRefWorker(unsigned short,tagREMINTERFACEREF * const,long *,int);
	long RemReleaseWorker(unsigned short,tagREMINTERFACEREF * const,int);
	virtual long AcknowledgeMarshalingSets(unsigned short,unsigned __int64 *);
	virtual long DoCallback(tagXAptCallback *);
	virtual long DoNonreentrantCallback(tagXAptCallback *);
	virtual long GetInterfaceNameFromIPID(_GUID const &,HSTRING__ * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RemAddRef(unsigned short,tagREMINTERFACEREF * const,long *);
	virtual long RemChangeRef(unsigned long,unsigned short,tagREMINTERFACEREF * const);
	virtual long RemQueryInterface(_GUID const &,unsigned long,unsigned short,_GUID *,tagREMQIRESULT * *);
	virtual long RemQueryInterface2(_GUID const &,unsigned short,_GUID *,long *,tagMInterfacePointer * *);
	virtual long RemRelease(unsigned short,tagREMINTERFACEREF * const);
	virtual long RundownOid(unsigned long,unsigned __int64 * const,unsigned char * const);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CRestrictedError
{
	class CDebugHelper
	{
		static long TryReadBackTrace(unsigned __int64,unsigned short,long (*)(void *,unsigned __int64,unsigned int,unsigned char *),void *,unsigned int *,unsigned __int64 *);
	public:
		static long InspectCapturedStackBackTrace(unsigned __int64,unsigned short,long (*)(void *,unsigned __int64,unsigned int,unsigned char *),void *,unsigned int *,unsigned __int64 *);
	};

	bool IsInterfaceSupported(_GUID const &);
	long AllocateAndCopyString(unsigned short * *,unsigned __int64,unsigned short const *);
	long AllocateBstr(unsigned short * *,unsigned short const *);
	long CheckClient(bool *);
	long CheckClientAccess(bool *,void *);
	long CheckClientPrivilege(bool *,void *);
	long CloseLocalClientHandle(void *);
	long CreateSharedMemorySection();
	long Deserialize(unsigned char const *,unsigned __int64,unsigned __int64 *);
	long DeserializeBytes(unsigned char *,unsigned __int64,unsigned char const * *,unsigned __int64 *,unsigned __int64 *);
	long DeserializeString(unsigned short *,unsigned __int64,unsigned char const *,unsigned __int64,unsigned __int64 *);
	long DuplicateHandleForInproc(void * *);
	long DuplicateSectionHandleToClient(void *,void * *);
	long DuplicateSnapshotHandle(HPSS__ *,void *,bool,HPSS__ * *);
	long GetSectionName(unsigned short *,unsigned __int64);
	long MarshalAllocString(unsigned short * *,unsigned __int64);
	long MarshalCopyString(unsigned short const *,unsigned short *,unsigned __int64);
	long MarshalNestedInformation(IStream *,unsigned long,bool,void *,unsigned long);
	long MarshalSnapshotInformation(IStream *,unsigned long,bool,void *,unsigned long);
	long MarshalStowedExceptionInformation(IStream *,unsigned long,bool,void *,unsigned long);
	long OpenAndDeseralizeFromSharedMemorySection();
	long PopulateSharedMemorySection();
	long ReadHandleFromStream<void *>(void * *,IStream *);
	long ReadStringFromStream(unsigned short *,unsigned int,IStream *);
	long Serialize(unsigned char *,unsigned __int64,unsigned __int64 *);
	long SerializeBytes(unsigned char const *,unsigned __int64,unsigned char * *,unsigned __int64 *,unsigned __int64 *);
	long SerializeString(unsigned short *,unsigned __int64,unsigned char *,unsigned __int64,unsigned __int64 *);
	long UnmarshalNestedInformation(IStream *,bool);
	long UnmarshalSnapshotInformation(IStream *);
	long UnmarshalStowedExceptionInformation(IStream *);
	long ValidateHandle(void *,unsigned short const *,unsigned __int64);
	long WriteStringToStream(unsigned short const *,unsigned int,IStream *);
	static unsigned short const * const _szPrefix;
	unsigned __int64 GetPersistMaxSize(unsigned long,void *,unsigned long);
	void FillStowedException();
	void LogSnapshotPerformanceCounters();
	void SetSnapshotTimer();
	void UnsetSnapshotTimer();
protected:
	virtual long CheckMarshalingContext();
	virtual long CheckMarshalingParameters(_GUID const &,unsigned long,void *);
	virtual long CheckTargetAccessAndGetHandle(unsigned long,bool *,void * *);
	virtual long GetTargetProcessHandle(unsigned long,void * *);
	virtual long SerializeMarshalingData(unsigned long,IStream *,bool,void *);
public:
	CRestrictedError();
	virtual long CaptureContext(unsigned short);
	virtual long CapturePropagationContext(IUnknown *);
	virtual long CaptureSnapshot();
	virtual long CreateFromReference(unsigned short const *);
	virtual long DisconnectObject(unsigned long);
	virtual long FreeSnapshot();
	virtual long GenerateCrashReportFromSnapshot(unsigned __int64,unsigned long);
	virtual long GetContext(unsigned __int64 *);
	virtual long GetCorrelationId(_GUID *);
	virtual long GetDescription(unsigned short * *);
	virtual long GetErrorCode(long *);
	virtual long GetErrorDetails(unsigned short * *,long *,unsigned short * *,unsigned short * *);
	virtual long GetGUID(_GUID *);
	virtual long GetHelpContext(unsigned long *);
	virtual long GetHelpFile(unsigned short * *);
	virtual long GetLanguageException(IUnknown * *);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long GetPreviousLanguageExceptionErrorInfo(ILanguageExceptionErrorInfo2 * *);
	virtual long GetPropagationContextHead(ILanguageExceptionErrorInfo2 * *);
	virtual long GetReference(unsigned short * *);
	virtual long GetSignature(unsigned short * *);
	virtual long GetSource(unsigned short * *);
	virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
	virtual long HasSnapshot(int *);
	virtual long MarkRestrictedErrorAsUnhandled();
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long ReleaseMarshalData(IStream *);
	virtual long SetDestinationProcessId(unsigned long);
	virtual long SetErrorDetails(unsigned short const *,long,unsigned short const *,unsigned short const *);
	virtual long SetLanguageExceptionErrorInfo(IUnknown *);
	virtual long SetPreviousRestrictedErrorInfo(IRestrictedErrorInfo *);
	virtual long SetTransformed(int);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
	virtual ~CRestrictedError();
};

class CRestrictedErrorWrapper
{
protected:
	virtual long CheckMarshalingContext();
	virtual long CheckTargetAccessAndGetHandle(unsigned long,bool *,void * *);
public:
	long Initialize(void *);
	virtual ~CRestrictedErrorWrapper();
};

struct CRpcCall
{
	virtual long GetCallInfo(void const * *,_GUID *,unsigned long *,long *);
	virtual long GetCallSource(_CALLSOURCE *);
	virtual long GetRpcOleMessage(tagRPCOLEMESSAGE * *);
	virtual long GetServerHR(long *);
	virtual long Nullify(long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CRpcHelper
{
	virtual long GetDCOMProtocolVersion(unsigned long *);
	virtual long GetIIDFromOBJREF(void *,_GUID * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CRpcOptions
{
	long ProxyToBindingHandle(void *,CChannelHandle * *,int,int);
	long ProxyToChannel(void *,CClientChannel * *,int);
public:
	virtual long Query(IUnknown *,tagRPCOPT_PROPERTIES,unsigned __int64 *);
	virtual long Set(IUnknown *,tagRPCOPT_PROPERTIES,unsigned __int64);
};

class CRpcResolver
{
	long BindToSCMProxy(int);
	long InitializeSystemSecurityDescriptors(unsigned long *,unsigned long,unsigned char *);
	long RegisterWithPsmIfNecessary();
	long SetImpersonatingFlag(IActivationPropertiesIn *);
	static CDualStringArray * _pdsaLocalResolver;
	static CMachineNamesHelper * _pMNHelper;
	static COleStaticMutexSem _mxsResolver;
	static ISCMLocalActivator * _pCloakedSCMProxy;
	static ISCMLocalActivator * _pSCMProxy;
	static _GUID _GuidRPCSSProcessIdentifier;
	static int RetryRPC(long);
	static int _developerLicenseInstalled;
	static long CheckStatus(long);
	static unsigned __int64 * _OidsReserved;
	static unsigned __int64 _ProcessSignature;
	static unsigned __int64 _dwCurrentBindingsID;
	static unsigned long _cReservedOidsAvail;
	static unsigned long _dwFlags;
	static unsigned long _dwNoRegAccessPermissionsSDSize;
	static unsigned long _dwOutstandingResolverCallCount;
	static unsigned short * _pwszFQDN;
	static unsigned short * _pwszWinstaDesktop;
	static void * _pDefaultAccessRestrictionsSD;
	static void * _pNoRegAccessPermissionsSD;
	static void * _pNoRegAccessRestrictionsSD;
	static void * _pNoRegLaunchPermissionsSD;
	static void * _pNoRegLaunchRestrictionsSD;
	static void * _pSelfSid;
	static void * _ph;
	static void PsmStateChangeNotificationRoutine(unsigned char,void *,void *);
public:
	_SECURITY_DESCRIPTOR * GetDefaultAccessRestrictionsSD();
	long ClientResolveMachineLocalOXID(unsigned __int64 const &,tagOXID_INFO *,unsigned long *,std::unique_ptr<unsigned char [0],DeleteMarshaledTargetInfo> &,unsigned short *);
	long ClientResolveOXID(unsigned __int64 const &,tagOXID_INFO *,unsigned __int64 *,tagDUALSTRINGARRAY *,unsigned long *,std::unique_ptr<unsigned char [0],DeleteMarshaledTargetInfo> &,unsigned short *);
	long ControlTracingForProcess(unsigned long,int);
	long CreateInstance(IActivationPropertiesIn *,IActivationPropertiesOut * *);
	long CreateInstance(_COSERVERINFO *,_GUID *,unsigned long,unsigned long,_GUID *,unsigned long *,unsigned short * *,tagMInterfacePointer * *,long *);
	long DecodeProxy(unsigned long,unsigned __int64,tagServerInformation *);
	long EnableDisableDynamicIPTracking(int);
	long FlushSCMBindings(unsigned short *);
	long GetClassObject(IActivationPropertiesIn *,IActivationPropertiesOut * *);
	long GetConnection();
	long GetCurrentAddrExclusionList(unsigned long *,unsigned short * * *);
	long GetCurrentMachineNames(CMachineNamesHelper * *);
	long GetDefaultSecurityPermissions(unsigned long * const,unsigned long *,unsigned char * *);
	long GetFQDN(unsigned short * *);
	long GetLocalResolverBindings(CDualStringArray * *);
	long GetPersistentInstance(IActivationPropertiesIn *,IActivationPropertiesOut * *,int *);
	long GetSystemSecurityDescriptors(tagCOMSD,void * *);
	long GetWindowPropInterface(HWND__ *,unsigned __int64,int,tagSTDOBJREF *,tagOXID_INFO *);
	long IMgotEnumRunning(_GUID const &,_MgotNameList * *);
	long IMgotGetObject(_GUID const &,_MnkEqBuf *,tagInterfaceData * *,int *);
	long IMgotRegister(_GUID const &,_MnkEqBuf *,tagInterfaceData *,unsigned long,_MgotScmToken *);
	long IMgotRevoke(_MgotScmToken *,tagInterfaceData * *,int *);
	long IrotEnumRunning(_MkInterfaceList * *,int);
	long IrotGetObject(unsigned long,_MnkEqBuf *,_SCMREGKEY *,tagInterfaceData * *,int *,int);
	long IrotGetTimeOfLastChange(_MnkEqBuf *,_FILETIME *,int);
	long IrotIsRunning(_MnkEqBuf *,int);
	long IrotNoteChangeTime(_SCMREGKEY *,_FILETIME *);
	long IrotRegister(_MnkEqBuf *,tagInterfaceData *,tagInterfaceData *,_FILETIME *,unsigned long,unsigned long,_SCMREGKEY *);
	long IrotRevoke(_SCMREGKEY *,tagInterfaceData * *,tagInterfaceData * *,int *);
	long IsObjectCreationAllowed(_GUID *,unsigned long,int,int *,int *,unsigned long *);
	long NotifyActivatableClassStarted(ActivatableClassRegInput const *,_RegOutput * *);
	long NotifyComClassChangesFromDeployment();
	long NotifyDDStartOrStop(int);
	long NotifyPsmResume();
	long NotifyStarted(_RegInput *,_RegOutput * *);
	long NotifySurrogatePaused();
	long NotifySurrogateReady();
	long NotifySurrogateResumed();
	long NotifySurrogateStarted(_ProcessActivatorToken *);
	long NotifySurrogateStopped();
	long NotifySurrogateUserInitializing();
	long NotifyWinRTActivationStoreChanged();
	long QueryDragDropActive(int *);
	long QueryPIDForActivation(_GUID,unsigned long,unsigned long *);
	long QueryServerProcessHandleHeld(_GUID *,int *);
	long RegisterConsoleHandles(void *,void *,void *,unsigned __int64 *);
	long RegisterRacActivationToken(void *,unsigned __int64 *);
	long RegisterWindowPropInterface(HWND__ *,tagSTDOBJREF const *,tagOXID_INFO const *,int,unsigned __int64 *);
	long RetireServer(_GUID *);
	long RevokeConsoleHandles(unsigned __int64);
	long RevokeRacActivationToken(unsigned __int64);
	long ServerFreeOXIDAndOIDs(unsigned __int64 &,unsigned long,unsigned __int64 *);
	long ServerGetReservedID(unsigned __int64 *);
	long ServerRegisterOXID(tagOXID_INFO const &,unsigned __int64 *,unsigned long *,unsigned __int64 * const);
	long SetAddrExclusionList(unsigned long,unsigned short * *);
	long SetAppID(_GUID);
	long SetLocalResolverBindings(unsigned __int64,CDualStringArray *);
	long SetOrRevokeForcedDropTarget(int,HWND__ *);
	long SetServerOIDFlags(unsigned __int64,unsigned long);
	unsigned long GetThreadWinstaDesktop();
	unsigned long ResolveProcessDesktopNoUser();
	void Cleanup();
	void GetThreadID(unsigned long *);
	void NotifyActivatableClassStopped(unsigned short const *,unsigned short const *,unsigned long);
	void NotifyStopped(_GUID const &,unsigned long);
	void ReleaseSCMProxy();
	void UpdateActivationSettings();
};

struct CRpcThread
{
	void WorkerLoop();
};

class CRpcThreadCache
{
	static COleStaticMutexSem _mxs;
	static CRpcThread * _pFreeList;
	static unsigned long RpcWorkerThreadEntry(void *);
public:
	void ClearFreeList();
	void RemoveFromFreeList(CRpcThread *);
};

struct CSCInnerUnknown
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CSSL
{
	static _CERT_CONTEXT const * const _pCert;
	static long _hr;
	static void * _hMyStore;
public:
	static long DefaultCert(_CERT_CONTEXT const * *);
	static long PrincipalName(_CERT_CONTEXT const *,unsigned short * *);
	static void Cleanup();
};

struct CSTInnerUnknown
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CServerChannel
{
	struct CServerCallMgr
	{
		CServerCallMgr(tagRPCOLEMESSAGE *,IUnknown *,IUnknown *,long &);
		unsigned long MarkError(long,unsigned long);
		virtual IRpcStubBuffer * IsIIDSupported(_GUID const &);
		virtual int IsImpersonating();
		virtual long Cancel(unsigned long);
		virtual long Connect(IUnknown *);
		virtual long DebugServerQueryInterface(void * *);
		virtual long ImpersonateClient();
		virtual long Invoke(tagRPCOLEMESSAGE *,IRpcChannelBuffer *);
		virtual long QueryBlanket(unsigned long *,unsigned long *,unsigned short * *,unsigned long *,unsigned long *,void * *,unsigned long *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual long Reset();
		virtual long RevertToSelf();
		virtual long Signal();
		virtual long TestCancel();
		virtual long Wait(unsigned long,unsigned long);
		virtual unsigned long CountRefs();
		virtual void DebugServerRelease(void *);
		virtual void Disconnect();
	};

	CServerChannel(CStdIdentity *,OXIDEntry *,bool,CObjectContext *);
	long ContextInvoke(tagRPCOLEMESSAGE *,IRpcStubBuffer *,tagIPIDEntry *,unsigned long *);
	long CopyMsgForRetry(tagRPCOLEMESSAGE *,long);
	long RegisterAsync(tagRPCOLEMESSAGE *);
	virtual long Cancel(tagRPCOLEMESSAGE *);
	virtual long CheckSystemHandleLeak(tagRPCOLEMESSAGE const *);
	virtual long CleanupAllSystemHandles(tagRPCOLEMESSAGE const *);
	virtual long FreeBuffer(tagRPCOLEMESSAGE *);
	virtual long FreeSystemHandle(unsigned char,void *);
	virtual long GetBuffer(tagRPCOLEMESSAGE *,_GUID const &);
	virtual long GetCallContext(tagRPCOLEMESSAGE *,_GUID const &,void * *);
	virtual long GetDestCtx(unsigned long *,void * *);
	virtual long GetDestCtxEx(tagRPCOLEMESSAGE *,unsigned long *,void * *);
	virtual long GetInMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetMarshalingLocality(tagRPCOLEMESSAGE const *,ComCallMarshalingLocality *);
	virtual long GetOutMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetProtocolVersion(unsigned long *);
	virtual long GetState(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long GetSystemHandle(tagRPCOLEMESSAGE const *,unsigned long,unsigned char,unsigned long,void * *);
	virtual long IsConnected();
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
	virtual long RegisterAsync(tagRPCOLEMESSAGE *,IAsyncManager *);
	virtual long Send(tagRPCOLEMESSAGE *,ISynchronize *,unsigned long *);
	virtual long Send(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SendReceive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SetSystemHandle(tagRPCOLEMESSAGE const *,void *,unsigned char,unsigned long,unsigned long *);
};

class CServerContextActivator
{
	virtual long CheckCrossContextAggregation(ActivationPropertiesIn *,IUnknown *);
public:
	virtual long CreateInstance(IUnknown *,IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long GetClassObject(IActivationPropertiesIn *,IActivationPropertiesOut * *);
};

class CServerSecurity
{
	static COleStaticMutexSem _mxs;
	static CPageAllocator _palloc;
public:
	long SetupSecurity();
	static void Cleanup();
	static void Initialize();
	virtual int IsImpersonating();
	virtual long Cancel(unsigned long);
	virtual long DisableComInits(void *);
	virtual long EnableComInits(void * *);
	virtual long ImpersonateClient();
	virtual long OpenCallerProcessHandle(unsigned long,void * *);
	virtual long QueryBlanket(unsigned long *,unsigned long *,unsigned short * *,unsigned long *,unsigned long *,void * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RevertToSelf();
	virtual long TestCancel();
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void RestoreSecurity(int);
};

struct CSplit_QI
{
	CSplit_QI(long &,unsigned long,tagMULTI_QI *);
	~CSplit_QI();
};

class CSpyTable
{
	int Expand();
public:
	CSpyTable(int *);
	int Add(void *);
	int Find(void *,unsigned long *);
	int Remove(void *);
};

class CStaticMarshaler
{
	static COleStaticMutexSem _SecretLock;
	static int _fSecretInit;
	static unsigned char * _SecretBlock;
protected:
	long InitSecret();
public:
	static CStaticMarshaler s_Instance;
	virtual long DisconnectObject(unsigned long);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long ReleaseMarshalData(IStream *);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CStaticWrapper
{
	long ValidateXCtxMarshalData(tagXCtxMarshalData const &);
public:
	virtual long DisconnectObject(unsigned long);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long ReleaseMarshalData(IStream *);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CStdClassFactory
{
	virtual long CreateInstance(IUnknown *,_GUID const &,void * *);
	virtual long LockServer(int);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CStdEvent
{
	virtual long GetHandle(void * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long SetEventHandle(void * *);
	virtual long Signal();
	virtual long Wait(unsigned long,unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	~CStdEvent();
};

struct CStdIdentity
{
	struct CInternalUnk
	{
		unsigned short QueryMultipleInterfacesLocal(unsigned long,tagMULTI_QI *,tagMULTI_QI * *,_GUID *,unsigned long *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual long QueryInternalInterface(_GUID const &,void * *);
		virtual long QueryMultipleInterfaces(unsigned long,tagMULTI_QI *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
	};

	CStdIdentity(unsigned long,unsigned long,IUnknown *,IUnknown *,IUnknown * *,int *);
	IUnknown * GetServer();
	bool IsCallableFromCurrentApartment(bool,bool);
	long LockObjectExternal(int,int);
	long SetOID(_GUID const &);
	unsigned long UnlockAndRelease();
	virtual IObjContext * GetServerObjectContext();
	virtual int IsConnected();
	virtual long AllowForegroundTransfer(void *);
	virtual long CreateCall(_GUID const &,IUnknown *,_GUID const &,IUnknown * *);
	virtual long CreateServer(_GUID const &,unsigned long,void *);
	virtual long GetConnectionStatus();
	virtual long GetServerProcessHandle(unsigned long,int,void * *);
	virtual long GetServerProcessId(unsigned long *);
	virtual long GetWrapperForContext(CObjectContext *,_GUID const &,void * *);
	virtual long LockConnection(int,int);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual void * GetMapping();
	virtual void Disconnect();
	virtual void SetMapping(void *);
	virtual ~CStdIdentity();
	void DecStrongCnt(int);
	void DecWeakCnt(int);
	void IncStrongCnt();
	void IncrementDisconnectableContextObjectCount();
	void NotifySmuggledProxy(_GUID const &,unsigned short);
	void RevokeOID();
};

class CStdMarshal
{
	long AllocateClientIPIDEntry(_GUID const &,_GUID const &,IUnknown *,void *,tagIPIDEntry * *);
	long AllocateServerIPIDEntry(_GUID const &,tagIPIDEntry * *);
	long ConnectCliIPIDEntry(tagSTDOBJREF *,OXIDEntry *,tagIPIDEntry *);
	long ConnectProxyToChannel(tagIPIDEntry *,OXIDEntry *,_GUID const &);
	long ConnectSrvIPIDEntry(tagIPIDEntry *,IUnknown *);
	long CreateProxy(_GUID const &,_GUID const &,OXIDEntry *,IRpcProxyBuffer * *,void * *,int *);
	long CreateStub(tagIPIDEntry *,IRpcStubBuffer * *,void * *,int *,IUnknown *);
	long Finish_RemQIAndUnmarshal1(tagSQIResult *,tagQICONTEXT *);
	long Finish_RemQIAndUnmarshal2(tagSQIResult *,tagQICONTEXT *);
	long FixIidMismatchInUnmarshalInterface(_GUID const &,IUnknown *,_GUID const &,void * *);
	long GetPSFactory(_GUID const &,IUnknown *,IPSFactoryBuffer * *,int *);
	long MakeCliIPIDEntry(_GUID const &,tagSTDOBJREF *,OXIDEntry *,tagIPIDEntry * *);
	long MarshalClientIPID(_GUID const &,unsigned long,unsigned long,tagIPIDEntry * *,PreventRundownBiasContainer *,bool);
	long MarshalServerIPID(_GUID const &,unsigned long,unsigned long,tagIPIDEntry * *,IUnknown *,PreventRundownBiasContainer *,bool);
	long ReleaseClientTableStrong(OXIDEntry *);
	long RemQIAndUnmarshal(unsigned short,_GUID *,tagSQIResult *);
	long RemoteAddRef(tagIPIDEntry *,OXIDEntry *,unsigned long,unsigned long,int);
	unsigned long GetPendingDisconnectType();
	void AddSuppliedRefs(tagSTDOBJREF *,tagIPIDEntry *);
	void Begin_RemQIAndUnmarshal1(unsigned short,_GUID *,tagQICONTEXT *);
	void Begin_RemQIAndUnmarshal2(unsigned short,_GUID *,tagQICONTEXT *);
	void CleanUpDuplicateNewCliIPIDEntry(tagIPIDEntry *);
	void DecStrongAndNotifyAct(tagIPIDEntry *,unsigned long);
	void DisconnectAndFreeSrvIPID(tagIPIDEntry *);
	void DisconnectCliIPIDs();
	void DisconnectProxyFromChannel(tagIPIDEntry *);
	void DisconnectSrvIPIDs(unsigned long);
	void IncStrongAndNotifyAct(tagIPIDEntry *,unsigned long);
	void ReleaseAllClientIPIDEntries();
	void ReleaseAllServerIPIDEntries();
	void ReleaseProxy(tagIPIDEntry *);
protected:
	long FindIPIDEntryByIPID(_GUID const &,tagIPIDEntry * *);
public:
	CObjectContext * ServerObjectCallable();
	CPolicySet * GetClientPolicySet();
	int InstantiatedProxy(_GUID const &,void * *,long *);
	long AllowForegroundTransfer(void *);
	long FindIPIDEntryByIID(_GUID const &,tagIPIDEntry * *);
	long FindIPIDEntryByInterface(void *,tagIPIDEntry * *);
	long Finish_QueryRemoteInterfaces(tagSQIResult *,tagQICONTEXT *);
	long GetAsyncRemUnknown(IUnknown *,AsyncIRemUnknown2 * *,IUnknown * *);
	long GetRemUnk(IRemUnknown * *,OXIDEntry *);
	long GetSecureRemUnk(IRemUnknown * *,OXIDEntry *);
	long GetServerProcessHandle(unsigned long,int,void * *);
	long HandlePendingDisconnect(long);
	long IncSrvIPIDCnt(tagIPIDEntry *,unsigned long,unsigned long,tagSECURITYBINDING *,unsigned long);
	long MarshalObjRef(tagOBJREF &,_GUID const &,unsigned long,unsigned long,void *,IUnknown *,PreventRundownBiasContainer *,bool);
	long PreventDisconnect();
	long PrivateCopyProxy(IUnknown *,IUnknown * *);
	long QueryRemoteInterfaces(unsigned short,_GUID *,tagSQIResult *);
	long RegisterForDisconnect(IDisconnectSink *,void *,void * *);
	long ReleaseMarshalObjRef(tagOBJREF &);
	long RemoteChangeRef(int,int);
	long SetClientPolicySet(CPolicySet *);
	long UnmarshalIPID(_GUID const &,tagSTDOBJREF *,OXIDEntry *,void * *);
	long UnmarshalObjRef(tagOBJREF &,void * *);
	static long UnregisterForDisconnect(void *);
	unsigned char CanRunDown(unsigned long);
	virtual long DisconnectObject(unsigned long);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long ReleaseMarshalData(IStream *);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
	void Begin_QueryRemoteInterfaces(unsigned short,_GUID *,tagQICONTEXT *);
	void Deactivate();
	void DecSrvIPIDCnt(tagIPIDEntry *,unsigned long,unsigned long,tagSECURITYBINDING *,unsigned long);
	void DecTableCnt();
	void Disconnect(unsigned long);
	void DisconnectAndRelease(unsigned long);
	void FillSTD(tagSTDOBJREF *,unsigned long,unsigned long,unsigned long,tagIPIDEntry const *);
	void NullOXIDReferencesInIPIDEntries();
	void Reactivate(IUnknown *);
	void ReconnectProxies();
	void ReleaseIDObject(CIDObject *);
	void ReleaseRemUnkCopy(IRemUnknown *);
	void TraceOID(unsigned short const *);
	void UnlockServer();
	~CStdMarshal();
};

class CStdWrapper
{
	IFaceEntry * CreateLightPS(_GUID const &,void *,long &);
	long CrossCtxQI(CPolicySet *,_GUID const &,IFaceEntry * *);
	long HandlePendingDisconnect(long);
	long InternalQI(_GUID const &,void * *,int,int,CtxEntry *);
	long PreventDisconnect();
	static CPageAllocator s_allocator;
	static int s_fInitialized;
	static unsigned long s_cObjects;
	static void PrivateCleanup();
	virtual long GetStaticInfo(ICallInterceptor *);
public:
	CPolicySet * ReleaseCtxEntry(CtxEntry *);
	CStdWrapper(IUnknown *,unsigned long,CIDObject *);
	CtxEntry * AddCtxEntry(CPolicySet *);
	IFaceEntry * GetIFaceEntry(_GUID const &);
	int CanWrapperMarshal(unsigned long,unsigned long);
	int IsNAWrapper();
	long CreateIFaceEntry(_GUID const &,void *,IFaceEntry * *);
	long Disconnect(CPolicySet *);
	long GetOrCreateIFaceEntry(_GUID const &,IUnknown *,CObjectContext *,CPolicySet *,void * *);
	long MarshalServer(CPolicySet *,IStream *,_GUID const &,unsigned long,void *,unsigned long);
	long ValidateContext(CObjectContext *,IFaceEntry *,CtxEntry * *);
	long WrapInterfaceForContext(CObjectContext *,IUnknown *,_GUID const &,void * *);
	static int IsNotImplInterface(_GUID const &);
	static void Cleanup();
	static void Initialize();
	unsigned long InternalRelease(CPolicySet *);
	virtual long DisconnectObject(unsigned long);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long ReleaseMarshalData(IStream *);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void * GetImplInterface(_GUID const &);
	void Deactivate();
	void IncrementDisconnectableContextObjectCount();
	void PrepareForDestruction(CPolicySet *);
	void Reactivate(IUnknown *);
	void Unlock(CPolicySet *);
};

struct CStreamOnBuffer
{
	virtual long Clone(IStream * *);
	virtual long Commit(unsigned long);
	virtual long CopyTo(IStream *,_ULARGE_INTEGER,_ULARGE_INTEGER *,_ULARGE_INTEGER *);
	virtual long LockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Read(void *,unsigned long,unsigned long *);
	virtual long Revert();
	virtual long Seek(_LARGE_INTEGER,unsigned long,_ULARGE_INTEGER *);
	virtual long SetSize(_ULARGE_INTEGER);
	virtual long Stat(tagSTATSTG *,unsigned long);
	virtual long UnlockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long Write(void const *,unsigned long,unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CStringHashTable
{
	unsigned long Hash(tagDUALSTRINGARRAY *);
	virtual int Compare(void const *,SHashChain *,unsigned long);
};

class CSurrogateActivator
{
protected:
	static CSurrogateActivator * s_pCSA;
};

class CSurrogateProcessActivator
{
	static unsigned long PingSCM(void *);
	static unsigned long StartNTService(void *);
	virtual long ActivationBegins();
	virtual long ActivationFails();
	virtual long ActivationSucceeds();
	virtual long BeginSurrogateTimeout();
	virtual long StartSendingSCMPings();
	virtual long StopSendingSCMPings();
public:
	CSurrogateProcessActivator();
	long Initialize();
	static void NTServiceCtrlHandler(unsigned long);
	static void NTServiceMain(unsigned long,unsigned short * *);
	virtual long AreServicesRequired();
	virtual long CallInitializers(_GUID const &);
	virtual long CleanupServices();
	virtual long CloseCatalog();
	virtual long CreateInstance(IUnknown *,IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long ForcedShutdown();
	virtual long FreeSurrogate();
	virtual long GetClassObject(IActivationPropertiesIn *,IActivationPropertiesOut * *);
	virtual long InitializeServices(_GUID const &);
	virtual long LoadDllServer(_GUID const &);
	virtual long ObjectServerLoadDll(_GUID *,unsigned long *);
	virtual long OpenCatalog(_GUID const &);
	virtual long PendingApplication(_GUID const &);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RemoveISurrogate();
	virtual long ResetInitializerTimeout(unsigned long);
	virtual long ResumeAll();
	virtual long ResumeApplication(_GUID const &);
	virtual long SetIdleTimeoutToZero();
	virtual long SetObjectCountAtIdleTime(unsigned long);
	virtual long SetupFusionContext();
	virtual long SetupSecurity();
	virtual long SetupSurrogateTimeout();
	virtual long StartNTServiceIfNecessary();
	virtual long StoreISurrogate(ISurrogate *);
	virtual long SuspendAll();
	virtual long SuspendApplication(_GUID const &);
	virtual long TellNtSCMWeAreReady();
	virtual long TellRpcSCMWeAreReady();
	virtual long TellSCMWeAreDone();
	virtual long TellSCMWeAreInitializing();
	virtual long TellSCMWeAreStarted(_GUID const &);
	virtual long WaitForInitCompleted(unsigned long,unsigned long);
	virtual long WaitForNTServiceIfNecessary();
	virtual long WaitForSurrogateTimeout();
	virtual unsigned long AddRef();
	virtual unsigned long AddRefOnProcess();
	virtual unsigned long Release();
	virtual unsigned long ReleaseRefOnProcess();
	virtual void PendingInit();
	virtual void ServicesReady();
	~CSurrogateProcessActivator();
};

class CSuspendMonitor
{
	struct CRegistration
	{
		CRegistration(ISuspendNotify *);
		static CRegistration * CopyList(CRegistration);
		static void OnSuspend(CRegistration *);
		~CRegistration();
	};

	long Start();
	static void SuspendResiliencyCallback(_SUSPEND_RESILIENCY_TYPE,_SUSPEND_RESILIENCY_STATE,void *);
	void OnResume(unsigned long);
	void OnSuspend(unsigned long);
public:
	CSuspendMonitor();
	long Enter();
	virtual long IsTargetActive(IUnknown *,int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Register(ISuspendNotify *,void * *);
	virtual long Revoke(void *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void Exit();
	~CSuspendMonitor();
};

class CSyncClientCall
{
	long CopyMsgForRetry(tagRPCOLEMESSAGE *);
	long CopyRequestMessageFromAutoRetryResponse(tagRPCOLEMESSAGE *);
protected:
	virtual bool UseAsyncTransportCall();
public:
	long DispatchThreadLocalCall(tagRPCOLEMESSAGE *);
	long SendReceiveInRetryContext(SyncClientCallRetryContext *,tagRPCOLEMESSAGE *,unsigned long *);
	long TransmitCall(tagRPCOLEMESSAGE *);
	virtual bool IsClientAsync();
	virtual bool IsWinrtAsyncMethodSyncCall();
	virtual bool UsesThreadLocalDispatch();
	virtual long Cancel(unsigned long);
	virtual long Initialize(tagRPCOLEMESSAGE const *,tagCALLCATEGORY,CChannelHandle *,unsigned long,tagCOMVERSION,_GUID const &,ClientCallTracingInfo const &);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
	virtual long Receive2(tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
	virtual long RegisterAsync(tagRPCOLEMESSAGE *,CChannelObject *);
	virtual long Send(tagRPCOLEMESSAGE *,CChannelObject *,unsigned long *);
	virtual long Send(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long Send2(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SendReceive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SendReceive2(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long TestCancel();
	virtual void Finalize(tagRPCOLEMESSAGE *);
	virtual void OnCancelRequestRequiringAcknowledgment();
	virtual void OnClientEventSignalRequiringReset();
	virtual void OnCompletedCallWithUnknownClientEventSignalStatus();
	virtual void OnSyncCallCompletedWithOutstandingRpcCancel();
	virtual void OnTransportCallCompletionReceived();
	virtual void OnWaitSatisifiedByClientEventSignal();
};

struct CSynchronizeContainer
{
	virtual long AddSynchronize(ISynchronize *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long WaitMultiple(unsigned long,unsigned long,ISynchronize * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CSystemRegistryCatalog
{
protected:
	virtual bool IgnoreRunAsInteractiveUser();
	virtual bool RegistrationsArePackaged();
	virtual bool SelectDllHostBitnessBasedOnDllBitness();
	virtual bool Supports16BitRegistrations();
	virtual bool SupportsActivateAtStorage();
	virtual bool SupportsApplicationId();
	virtual bool SupportsDarwinId();
	virtual bool SupportsForceHKLM();
	virtual bool SupportsGetProgId();
	virtual bool SupportsLUAAndDisplaySettings();
	virtual bool SupportsLoadUserSettings();
	virtual bool SupportsPreferredServerBitness();
	virtual bool SupportsProcessMitigationPolicy();
	virtual bool SupportsROTAppIDAndMGOTFlags();
	virtual bool SupportsRemoteServerName();
	virtual bool SupportsSRPTrustLevel();
	virtual long GetComRootKeyForUserToken(IUserToken *,HKEY__ * *);
	virtual long OpenKeyInOtherView(HKEY__ *,unsigned short const *,unsigned long,HKEY__ * *);
	virtual unsigned long CatalogFlagsForAppID();
	virtual unsigned long ExpectedOutofprocServerBinaryArchitecture();
	virtual unsigned long GetViewFlagFor(CComRegCatalog::WhichView);
	virtual unsigned short GetWowArchitectureFor(CComRegCatalog::WhichView);
	virtual void ReleaseComRootKeyForUserToken(IUserToken *);
};

class CThreadStack
{
	int GetCurrentProcessDefaultStackCommit();
public:
	unsigned __int64 GetNewThreadStackCommitSize(unsigned long);
};

struct CTypeFactory
{
	virtual long CreateFromTypeInfo(ITypeInfo *,_GUID const &,IUnknown * *);
	virtual long CreateInstance(IUnknown *,_GUID const &,void * *);
	virtual long LockServer(int);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CTypeFieldEnumerator
{
protected:
	virtual long _Enumerate(void * *,unsigned int *,unsigned long,unsigned long *);
};

class CTypeGen
{
	long GenStructSimpleTypesFormatString(PARAMINFO *,tagVARDESC *,unsigned short *);
	long GetByte(unsigned short,unsigned char *);
	long GrowTypeFormat(unsigned short);
	long ParseStructMembers(PARAMINFO *,FORMAT_CHARACTER *,tagVARDESC * *,unsigned short *,_MemoryInfo *,unsigned short,_MemoryInfo *,unsigned char *);
	long PushByte(unsigned char);
	long PushIID(_GUID);
	long PushLong(unsigned long);
	long PushOffset(unsigned short);
	long PushShort(unsigned short);
	long PushStruct(PARAMINFO *,FORMAT_CHARACTER,tagVARDESC * *,unsigned short *,_MemoryInfo *,unsigned short,unsigned short *,_MemoryInfo *);
	long RegisterInterfacePointer(PARAMINFO *,unsigned short *);
	long RegisterSafeArray(PARAMINFO *,unsigned short *);
	long RegisterStruct(PARAMINFO *,unsigned short *,_MemoryInfo *);
	long RegisterUDT(PARAMINFO *,unsigned short *,_MemoryInfo *);
	long SetByte(unsigned short,unsigned char);
	unsigned short Alignment(unsigned long,unsigned long);
public:
	long GetOffset(unsigned short,unsigned short *);
	long RegisterCArray(PARAMINFO *,unsigned short *,_MemoryInfo *);
	long RegisterType(PARAMINFO *,unsigned short *,_MemoryInfo *);
	void UpdateStructInfo(_MemoryInfo *,unsigned short,long,unsigned short);
};

class CTypeMarshal
{
	void AdjustMidlStubMessageForCallMarshaling(_MIDL_STUB_MESSAGE *);
public:
	CTypeMarshal(unsigned char const *,unsigned long,unsigned long);
	virtual long DisconnectObject(unsigned long);
	virtual long Free(void *);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
	virtual long Marshal(void *,unsigned long,void *,unsigned long,unsigned char *,unsigned long *);
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long ReleaseMarshalData(IStream *);
	virtual long Size(void *,unsigned long,void *,unsigned long *);
	virtual long Unmarshal(void *,unsigned long,unsigned long,unsigned char *,unsigned long *);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CUUIDHashTable
{
	virtual int Compare(void const *,SHashChain *,unsigned long);
};

struct CUserMarshalInfo
{
	CUserMarshalInfo(unsigned long *,unsigned char *,unsigned long);
	unsigned __int64 GetBufferSize();
	unsigned __int64 ValidateGetBufferSize();
};

class CVerifierStackData
{
	static unsigned long s_cProcessCapturedStacks;
public:
	long Add(void * *);
	~CVerifierStackData();
};

struct CWinRTActivationStoreCatalog
{
	struct CActivatableClassPropertiesHelper
	{
		CActivatableClassPropertiesHelper(Windows::Foundation::RegistrationScope);
		long GetActivationType(Windows::Foundation::ActivationType &);
		long GetAttributes(EntryPropertyStore &);
		long GetDllPath(ExpandableString &);
		long GetServerName(OpaqueString &);
		long GetThreadingModel(Windows::Foundation::ThreadingType &);
		long ReadActivatableClassRegistrationEntry(IActivationCatalogContext *,RegistrationStoreContext::ActivatableClassHandleDetail *);
	};

	struct CDebugInformationPropertiesHelper
	{
		long GetDebugEnvironment(MultiString &);
		long GetDebuggerCommandLine(ExpandableString &);
	};

	struct CProxyStubClassInfo
	{
		CProxyStubClassInfo();
		long FinalConstruct(unsigned long,_GUID const &,unsigned short const *,IActivationCatalogContext *,RegistrationStoreContext::ProxyStubHandleDetail *);
		virtual long CanBeCached(int *);
		virtual long GetApplication(_GUID const &,void * *);
		virtual long GetClassContext(tagCLSCTX,tagCLSCTX *);
		virtual long GetClassNameW(unsigned short const * *);
		virtual long GetConfiguredClsid(_GUID * *);
		virtual long GetCustomActivatorClsids(tagACTIVATION_STAGE,_GUID * *);
		virtual long GetCustomActivatorCount(tagACTIVATION_STAGE,unsigned long *);
		virtual long GetCustomActivators(tagACTIVATION_STAGE,ISystemActivator * * *);
		virtual long GetImplementedClsid(_GUID * *);
		virtual long GetLocalServerType(tagLocalServerType *);
		virtual long GetModulePath(tagCLSCTX,unsigned short * *);
		virtual long GetProcess(_GUID const &,void * *);
		virtual long GetProgId(unsigned short * *);
		virtual long GetRemoteServerName(unsigned short * *);
		virtual long GetSurrogateCommandLine(unsigned short * *);
		virtual long GetThreadingModel(ThreadingModel *);
		virtual long GetTypeInfo(_GUID const &,void * *);
		virtual long GetVersionNumber(unsigned long *,unsigned long *);
		virtual long IsComPlusConfiguredClass(int *);
		virtual long Lock();
		virtual long MustRunInClientContext(int *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual long RefreshNeeded(IUserToken *,int *);
		virtual long Unlock();
		virtual unsigned long AddRef();
		virtual unsigned long Release();
	};

	struct CRuntimeClassInfo
	{
		CRuntimeClassInfo();
		long FinalConstruct(unsigned long,IUserToken *,unsigned short const *,unsigned short const *,_GUID const &,IWinRTCatalogInternal *,IActivationCatalogContext *,RegistrationStoreContext::ActivatableClassHandleDetail *,bool);
		virtual long CanBeCached(int *);
		virtual long GetActivatableClassId(HSTRING__ * *);
		virtual long GetActivateAsUser(unsigned long *);
		virtual long GetActivateInSharedBroker(int *);
		virtual long GetActivationType(unsigned long *);
		virtual long GetAttributes(_GUID const &,void * *);
		virtual long GetClassContext(tagCLSCTX,tagCLSCTX *);
		virtual long GetClassNameW(unsigned short const * *);
		virtual long GetClsid(_GUID *);
		virtual long GetConfiguredClsid(_GUID * *);
		virtual long GetDeployingPackageName(unsigned short const * *);
		virtual long GetDllPath(unsigned short * *);
		virtual long GetExecutionPackageName(HSTRING__ * *);
		virtual long GetImplementedClsid(_GUID * *);
		virtual long GetImplementedInterfaces(unsigned long *,_GUID * *);
		virtual long GetLocalServerType(tagLocalServerType *);
		virtual long GetModulePath(tagCLSCTX,unsigned short * *);
		virtual long GetPermissions(void * *);
		virtual long GetPreferredServerBitness(unsigned long *);
		virtual long GetProcess(_GUID const &,void * *);
		virtual long GetRegistrationScope(unsigned long *);
		virtual long GetRemoteServerName(unsigned short * *);
		virtual long GetServerExecutable(unsigned short * *);
		virtual long GetServerInfo(IWinRTServerInfo * *);
		virtual long GetServerName(unsigned short * *);
		virtual long GetSource(RegistrationSource *);
		virtual long GetThreadingModel(ThreadingModel *);
		virtual long GetThreadingModel(unsigned long *);
		virtual long GetTrustLevel(unsigned long *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual long RefreshNeeded(IUserToken *,int *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CRuntimeClassInfo();
	};

	class CServerInfo
	{
		static _GUID s_guidProcessId;
	public:
		CServerInfo();
		long FinalConstruct(unsigned long,IUserToken *,unsigned short const *,unsigned short const *,IComCatalogSCM *,IActivationCatalogContext *,RegistrationStoreContext::ServerHandleDetail *,RegistrationStoreContext::DebugInformationHandleDetail *,bool);
		virtual long CanBeCached(int *);
		virtual long GetAccessPermission(void * *,unsigned long *);
		virtual long GetActivatableClasses(unsigned short * *,unsigned long *);
		virtual long GetAppIDFlags(unsigned long *);
		virtual long GetAppIdMapping(_GUID * *);
		virtual long GetAppUserModelID(unsigned short * *);
		virtual long GetApplicationId(unsigned short const * *);
		virtual long GetAttributes(_GUID const &,void * *);
		virtual long GetAuthenticationLevel(unsigned long *);
		virtual long GetCommandLineW(unsigned short * *,int *);
		virtual long GetDebugEnvironment(unsigned short * *,unsigned long *);
		virtual long GetDebuggerCommandLine(unsigned short * *);
		virtual long GetDeployingPackageName(unsigned short const * *);
		virtual long GetExePath(unsigned short * *);
		virtual long GetExecutionPackageName(unsigned short const * *);
		virtual long GetExplicitPsmActivationType(unsigned long *);
		virtual long GetIdentity(unsigned short * *);
		virtual long GetIdentityType(unsigned long *);
		virtual long GetImpersonationLevel(unsigned long *);
		virtual long GetInstancing(unsigned long *);
		virtual long GetLaunchPermission(void * *,unsigned long *);
		virtual long GetMGOTFlags(unsigned long *);
		virtual long GetModuleType(tagCoModuleType *);
		virtual long GetPermissions(void * *);
		virtual long GetProcessId(_GUID * *);
		virtual long GetProcessName(unsigned short * *);
		virtual long GetProcessType(tagProcessType *);
		virtual long GetQuotedExePath(unsigned short * *);
		virtual long GetROTFlags(unsigned long *);
		virtual long GetRegistrationScope(unsigned long *);
		virtual long GetRunAsType(tagRunAsType *);
		virtual long GetRunAsUser(unsigned short * *);
		virtual long GetRunFullTrust(int *);
		virtual long GetSaferTrustLevel(unsigned long *);
		virtual long GetServerName(unsigned short * *);
		virtual long GetServerType(unsigned long *);
		virtual long GetServiceName(unsigned short * *);
		virtual long GetServiceParameters(unsigned short * *);
		virtual long GetSource(RegistrationSource *);
		virtual long IsUserService(int *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual long RefreshNeeded(IUserToken *,int *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CServerInfo();
	};

	struct CServerInfoPropertiesHelper
	{
		CServerInfoPropertiesHelper(Windows::Foundation::RegistrationScope);
		long GetActivatableClasses(MultiString &);
		long GetAttributes(EntryPropertyStore &);
		long GetCommandLineW(ExpandableString &);
		long GetExePath(ExpandableString &);
		long GetIdentityType(Windows::Foundation::IdentityType &);
		long GetPermissions(SecurityDescriptor * *);
		long ReadServerRegistrationEntry(IActivationCatalogContext *,RegistrationStoreContext::ServerHandleDetail *);
	};

	virtual long GetClassInfoW(unsigned long,IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetProxyStubCLSIDForInterface(unsigned long,_GUID const &,unsigned short const *,_GUID *);
	virtual long GetProxyStubClassInfo(unsigned long,_GUID const &,unsigned short const *,_GUID const &,void * *);
	virtual long GetRuntimeClassInfo(unsigned long,IUserToken *,unsigned short const *,unsigned short const *,KnownClsidAndScope const *,int,_GUID const &,void * *,IComCatalogSCM *);
	virtual long GetServerInfo(unsigned long,IUserToken *,unsigned short const *,unsigned short const *,_GUID const &,void * *,IComCatalogSCM *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CWinRTApartmentActivator
{
	virtual long GetActivationFactory(unsigned short const *,tagInterfaceData * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CWinrtAsyncClientCallChannel
{
	virtual bool IsInproc();
	virtual long CreateWinrtAsyncClientCall(WinrtAsyncOperationInfo const &,IWinrtAsyncClientRpcOleMessageCallProxyCallbacks *,IWinrtAsyncProxyCall *,IStubCall *,_GUID const &,bool,IWinrtAsyncClientCall * *);
	virtual long GetMethodProperties(unsigned long,unsigned long const *,unsigned __int64 *);
};

struct CWinrtAsyncServerCallChannel
{
	virtual bool IsInproc();
	virtual long CreateWinrtAsyncServerCall(WinrtAsyncOperationInfo const &,_RPC_MESSAGE *,IWinrtAsyncProxyCall *,IStubCall *,_GUID const &,bool,ComCallTraceActivity *,IWinrtAsyncServerCall * *);
	virtual long GetMethodProperties(unsigned long,unsigned long const *,unsigned __int64 *);
};

struct CWorldSecurityDescriptor
{
	CWorldSecurityDescriptor();
};

struct CWriteInterfaceDataMarshalingStream
{
	virtual long GetMarshalingContextAttribute(CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
};

struct CWriteMarshalingStreamOnBuffer
{
	virtual long GetMarshalingContextAttribute(CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
};

struct CachedCallEvent
{
	static CachedCallEvent GetOne();
};

struct CachedEvent
{
	static CachedEvent GetOne();
	~CachedEvent();
};

struct CallbackWrapper<unsigned __int64,long (*)(void *,unsigned __int64,unsigned int,unsigned char *)>
{
	virtual long operator()(unsigned int,unsigned char *);
};

struct CarefulBufferReader
{
	__int64 ReadHYPER();
	void Align(int);
};

class CausalityControlCallback
{
	static CausalityControlCallback * _head;
	static Microsoft::WRL::Wrappers::SRWLock _lock;
public:
	static long RegisterCallback(void (*)(unsigned char,Windows::Foundation::Diagnostics::CausalityTraceLevel),<unnamed-type-CausalityControlCookie> * *);
	static void InvokeAllCallbacks(unsigned char,Windows::Foundation::Diagnostics::CausalityTraceLevel);
};

struct ClassicSTAState
{
	static bool s_bASTACallReentrancyGuardEnabledByDefault;
};

class ClientCall
{
protected:
	ClientCall(unsigned int,_GUID const &,bool,ComCallTraceActivity *,unsigned long,ObjectLibrary::ReferencedPtr<CComApartment> const &,OXIDEntry *,CStdIdentity *,tagIPIDEntry *);
	long CreateTransportCallObject(TransportAndServerCalls &,bool,IClientTransportCallEvents *,tagRPCOLEMESSAGE const *,tagCALLCATEGORY,CChannelHandle *,unsigned long,tagCOMVERSION,_GUID const &);
	long NegotiateSyntaxWithTransportCall(tagRPCOLEMESSAGE *,CMessageCall *);
	virtual _GUID GetDcomCausalityId();
	virtual bool NeedsUnmarshalingTlsMitigation();
	virtual ~ClientCall();
	void TraceClientAsyncCallStart(_GUID const &,ClientCallTracingInfo const &);
	void TraceClientAsyncCallStop();
	void TraceClientSyncCallStart(ClientCallTracingInfo const &);
public:
	virtual bool IsClientAsyncAbiModel();
	virtual bool IsWinrtAsyncCall();
	virtual bool IsWinrtAsyncMethodSyncCall();
	virtual bool UsesThreadLocalDispatch();
	virtual long GetInMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetOutMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual void SetClientHResult(long,int);
};

class ClientCallRetryContext
{
	static bool RandomlyChoose();
	static unsigned int RandomFractionOf(unsigned int);
protected:
	unsigned long NextAutoRetry();
public:
	static long CalculateRetryStatus(bool,WireThat const *,unsigned long *);
};

namespace ComBlob
{
	long DuplicateBlob(tagBLOB *,tagBLOB * *);
	void DeleteBlob(tagBLOB *);
};

class ComCallTraceActivity
{
	static bool StopActivity(_GUID const &);
public:
	bool CorrelateWithAdditionalCallerActivity();
	static ObjectLibrary::ReferencedPtr<ComCallTraceActivity> CreateNew();
};

struct ComClassRegistrationEntryProperties
{
	ComClassRegistrationEntryProperties();
	~ComClassRegistrationEntryProperties();
};

struct ComProxyStubRegistrationEntryProperties
{
	~ComProxyStubRegistrationEntryProperties();
};

struct ComServerRegistrationEntryProperties
{
	~ComServerRegistrationEntryProperties();
};

struct ComTrace
{
	void Error_(long,unsigned short const *,wil::DiagnosticsInfo const &);
	void Failure_(wil::FailureInfo const &);
	void Warning_(long,unsigned short const *,wil::DiagnosticsInfo const &);
};

struct ComTypeLibVersionRegistrationEntryProperties
{
	ComTypeLibVersionRegistrationEntryProperties & operator=(ComTypeLibVersionRegistrationEntryProperties const &);
	~ComTypeLibVersionRegistrationEntryProperties();
};

class ComVerifierSettings
{
	ComVerifierSettings();
	bool ReadAvrfProperties();
	static ComVerifierSettings s_singleton;
	static bool ReadBooleanFromImageOptionsKey(unsigned short const *,bool);
	static bool ReadBooleanFromOleKey(unsigned short const *,bool);
	static bool s_fPgAllocHeapIsPrivate;
	static bool s_fPgAllocUseSystemHeap;
	static unsigned long ReadULongFromImageOptionsKey(unsigned short const *,unsigned long);
	static unsigned long ReadULongFromOleKey(unsigned short const *,unsigned long);
	static unsigned long s_dwAggressiveMTATesting;
public:
	static bool AggressiveDllUnloadEnabled();
	static bool ObjectTrackingEnabled();
	static bool VTBLTrackingEnabled();
	static bool VerifyThreadStateEnabled();
	static bool WinrtAsyncPatternContractChecksEnabled();
	static unsigned long GetAggressiveDllUnloadPeriod();
	static void InitializeObjectTracking();
	static void UninitializeObjectTracking();
};

namespace Common
{
	class DirectoryTreeWalker
	{
		bool IsDirAndShouldBeWalked(_WIN32_FIND_DATAW const &);
		long AppendNameToDirPath(unsigned short const *);
		long GetFirstFindHandle(void * *,_WIN32_FIND_DATAW * *);
		long InitializePath(unsigned short const *);
		long Visit(unsigned __int64,unsigned short *,_WIN32_FIND_DATAW const *,long *);
		static long DefaultFindCloseCallback(void *,void *);
		static long DefaultFindNextCallback(void *,void *,_WIN32_FIND_DATAW *);
	public:
		long Walk(unsigned short const *,unsigned int);
		~DirectoryTreeWalker();
	};

	bool IsDirectoryReparsePointOpaque(_WIN32_FIND_DATAW const &);
	long WalkDirectoryTree(unsigned short const *,unsigned int,long (*)(void *,unsigned short const *,_WIN32_FIND_DATAW const *),void *,long (*)(void *,unsigned short *,void * *,_WIN32_FIND_DATAW *),long (*)(void *,void *,_WIN32_FIND_DATAW *),long (*)(void *,void *));
};

class ContainerIdHelper
{
	static long GetEthreadContainerId(_GUID *);
	void TestHookBeginPush(int);
	void TestHookBeginRestore();
	void TestHookEndPush();
	void TestHookEndRestore();
public:
	long PushToTeb(_GUID const *);
	long Restore();
	virtual ~ContainerIdHelper();
};

namespace Containers
{
	namespace Intrusive
	{
		namespace Details
		{
			class HashTableBase<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::AllocationEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::AllocationEntry,HashMemberHook<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::AllocationEntry>,0>,Key<ObjectLibrary::OpaqueString> >
			{
			protected:
				void ResizeInternalCache();
			public:
				long Find(ObjectLibrary::OpaqueString const &,WinRT::Metadata::Marshaling::AllocationEntry * *);
				long Initialize();
				virtual ~HashTableBase<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::AllocationEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::AllocationEntry,HashMemberHook<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::AllocationEntry>,0>,Key<ObjectLibrary::OpaqueString> >();
				void Insert(ObjectLibrary::OpaqueString const &,WinRT::Metadata::Marshaling::AllocationEntry *);
			};

			class HashTableBase<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::TypeResolver::TypeEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeResolver::TypeEntry,HashMemberHook<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::TypeResolver::TypeEntry>,8>,Key<ObjectLibrary::OpaqueString> >
			{
			protected:
				void ResizeInternalCache();
			public:
				long Find(ObjectLibrary::OpaqueString const &,WinRT::Metadata::Marshaling::TypeResolver::TypeEntry * *);
				long Initialize();
				virtual ~HashTableBase<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::TypeResolver::TypeEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeResolver::TypeEntry,HashMemberHook<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::TypeResolver::TypeEntry>,8>,Key<ObjectLibrary::OpaqueString> >();
				void Insert(ObjectLibrary::OpaqueString const &,WinRT::Metadata::Marshaling::TypeResolver::TypeEntry *);
			};

			class HashTableBase<_GUID,WinRT::Metadata::Marshaling::TypeInformation,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeInformation,HashMemberHook<_GUID,WinRT::Metadata::Marshaling::TypeInformation>,32>,Key<_GUID> >
			{
			protected:
				void ResizeInternalCache();
			public:
				long Initialize();
				virtual ~HashTableBase<_GUID,WinRT::Metadata::Marshaling::TypeInformation,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeInformation,HashMemberHook<_GUID,WinRT::Metadata::Marshaling::TypeInformation>,32>,Key<_GUID> >();
				void Insert(_GUID const &,WinRT::Metadata::Marshaling::TypeInformation *);
			};

			struct Key<ObjectLibrary::OpaqueString>
			{
				static unsigned int Hash(ObjectLibrary::OpaqueString const &);
			};

			struct ListBase<WinRT::Metadata::Marshaling::AllocationEntry,CacheListHookAccessor<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::AllocationEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::AllocationEntry,HashMemberHook<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::AllocationEntry>,0> > >
			{
				ListBase<WinRT::Metadata::Marshaling::AllocationEntry,CacheListHookAccessor<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::AllocationEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::AllocationEntry,HashMemberHook<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::AllocationEntry>,0> > >();
			};

			struct ListBase<WinRT::Metadata::Marshaling::ParameterListEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::ParameterListEntry,ListMemberHook<WinRT::Metadata::Marshaling::ParameterListEntry>,0> >
			{
				struct Iterator
				{
					ListBase<WinRT::Metadata::Marshaling::ParameterListEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::ParameterListEntry,ListMemberHook<WinRT::Metadata::Marshaling::ParameterListEntry>,0> >::Iterator & operator++();
				};

				long At(unsigned __int64,WinRT::Metadata::Marshaling::ParameterListEntry * *);
				void Append(WinRT::Metadata::Marshaling::ParameterListEntry *);
			};

			struct ListBase<WinRT::Metadata::Marshaling::TypeInformation,CacheListHookAccessor<_GUID,WinRT::Metadata::Marshaling::TypeInformation,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeInformation,HashMemberHook<_GUID,WinRT::Metadata::Marshaling::TypeInformation>,32> > >
			{
				ListBase<WinRT::Metadata::Marshaling::TypeInformation,CacheListHookAccessor<_GUID,WinRT::Metadata::Marshaling::TypeInformation,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeInformation,HashMemberHook<_GUID,WinRT::Metadata::Marshaling::TypeInformation>,32> > >();
			};

			namespace ListBase<WinRT::Metadata::Marshaling::TypeInformation,ListHookThroughHashHookAccessor<_GUID,WinRT::Metadata::Marshaling::TypeInformation,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeInformation,HashMemberHook<_GUID,WinRT::Metadata::Marshaling::TypeInformation>,32> > >
			{
				struct Iterator
				{
					ListBase<WinRT::Metadata::Marshaling::TypeInformation,ListHookThroughHashHookAccessor<_GUID,WinRT::Metadata::Marshaling::TypeInformation,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeInformation,HashMemberHook<_GUID,WinRT::Metadata::Marshaling::TypeInformation>,32> > >::Iterator & operator++();
				};

			};

			struct ListBase<WinRT::Metadata::Marshaling::TypeListEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeListEntry,ListMemberHook<WinRT::Metadata::Marshaling::TypeListEntry>,8> >
			{
				struct Iterator
				{
					ListBase<WinRT::Metadata::Marshaling::TypeListEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeListEntry,ListMemberHook<WinRT::Metadata::Marshaling::TypeListEntry>,8> >::Iterator & operator++();
				};

				long At(unsigned __int64,WinRT::Metadata::Marshaling::TypeListEntry * *);
				void Append(WinRT::Metadata::Marshaling::TypeListEntry *);
			};

			struct ListBase<WinRT::Metadata::Marshaling::TypeResolver::TypeEntry,CacheListHookAccessor<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::TypeResolver::TypeEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeResolver::TypeEntry,HashMemberHook<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::TypeResolver::TypeEntry>,8> > >
			{
				ListBase<WinRT::Metadata::Marshaling::TypeResolver::TypeEntry,CacheListHookAccessor<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::TypeResolver::TypeEntry,MemberPtrAccessor<WinRT::Metadata::Marshaling::TypeResolver::TypeEntry,HashMemberHook<ObjectLibrary::OpaqueString,WinRT::Metadata::Marshaling::TypeResolver::TypeEntry>,8> > >();
			};

		};

	};

};

struct ContextInfo
{
	long GetInternalClientContext(CObjectContext * *);
	long GetInternalPrototypeContext(CObjectContext * *);
	virtual long GetCLSID(_GUID *);
	virtual long GetClientContext(IContext * *);
	virtual long GetPrototypeContext(IContext * *);
	virtual long GetSize(void *,unsigned long *);
	virtual long IsClientContextOK(int *);
	virtual long OverrideTargetContext(_GUID const &);
	virtual long PrototypeExists(int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long SetClientContext(IContext *);
	virtual long SetClientContextNotOK();
	virtual long SetPrototypeContext(IContext *);
	virtual long UnSerialize(void *);
	virtual long UnSerializeCallBack(_GUID const &,ISerializable * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~ContextInfo();
};

struct CpUnkList
{
	IUnknown * RemoveHead();
	long Add(IUnknown *);
	void Remove(IUnknown *);
};

struct CtxEntry
{
	static CtxEntry * LookupEntry(CtxEntry *,CObjectContext *,CtxEntry * *,unsigned long);
	static void DeleteCtxEntries(CtxEntry * &,unsigned long);
	static void PrepareCtxEntries(CtxEntry *,unsigned long);
	void AddToFreeList(CtxEntry * *,unsigned long);
};

struct DLL_INSTANTIATION_PROPERTIES
{
	long Init(unsigned short const *,unsigned long,unsigned long,_GUID const &,int);
};

namespace Dcomrem
{
	namespace Async
	{
		class AsyncBaseStateMachine<WinrtAsyncChannelOperation,2,AsyncDelegateStorage,Details::Nil>
		{
		protected:
			bool TransitionToState(Details::AsyncStatusInternal);
			bool TryTransitionToCompleted(CancelTransitionPolicy);
			bool TryTransitionToError(long,CancelTransitionPolicy,void *);
			long Cancel();
			long CheckValidStateForAsyncInfoCall();
			long CheckValidStateForDelegateCall();
			long CheckValidStateForResultsCall();
			long FireCompletion();
			long GetStatus(ABI::Windows::Foundation::AsyncStatus *);
			long PutCompleteDelegate(AsyncDelegateStorage const &);
			long Start();
			void ErrorCode(long *);
			void TraceOperationComplete();
		};

		struct ErrorPropagationPolicyTraits<-1>
		{
			static long FireCompletionErrorPropagationPolicyFilter(long,IUnknown *,void *);
		};

	};

};

struct DefaultSyncClientCallRetryContext
{
	virtual long HandleRejectedCall(bool);
	virtual void WaitBeforeRetry(tagRPCOLEMESSAGE const *);
};

struct DiagnosticBuffer<AstaTimedOutCallInfo,10>
{
	DiagnosticBuffer<AstaTimedOutCallInfo,10>();
	void Add(AstaTimedOutCallInfo const &);
	~DiagnosticBuffer<AstaTimedOutCallInfo,10>();
};

struct DiagnosticBuffer<_GUID,50>
{
	DiagnosticBuffer<_GUID,50>();
	void Add(_GUID const &);
	~DiagnosticBuffer<_GUID,50>();
};

struct EnsureInValidComThreadAndApartmentInScope
{
	EnsureInValidComThreadAndApartmentInScope(long &);
	~EnsureInValidComThreadAndApartmentInScope();
};

struct EntryPropertyStore
{
	long ForceToMemory();
	long GetIsEmpty(bool *);
};

class EventPoolEntry
{
	static EventPoolEntry::InitState s_initState;
	static _SLIST_HEADER s_eventPool;
public:
	static EventPoolEntry * CreatePoolEntry(int);
	static int LockInit();
	static int PrimeEventPool();
	static int ThreadInit();
	static int UpdateWriterEventState(unsigned long volatile *,int);
	static unsigned long UpdateReaderEventState(unsigned long volatile *,unsigned long,int &);
	static void DeletePoolEntry(EventPoolEntry *);
	static void LockCleanup(EventPoolEntry *);
	static void ThreadCleanup();
	unsigned long PerformReaderSignaling();
	unsigned long WaitForReaderEvent(unsigned long,int &,CRWLock *);
	unsigned long WaitForWriterEvent(unsigned long,int &,CRWLock *);
	void SetWriterEvent();
};

struct ExtensionActivationContextProperties
{
	virtual long GetCLSID(_GUID *);
	virtual long GetComponentProcessId(_GUID *);
	virtual long GetConsoleHandlesId(unsigned __int64 *);
	virtual long GetHostId(unsigned __int64 *);
	virtual long GetLpacAttributes(tagBLOB * *);
	virtual long GetRacActivationTokenId(unsigned __int64 *);
	virtual long GetSize(void *,unsigned long *);
	virtual long GetUserContext(unsigned __int64 *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long SetComponentProcessId(_GUID const &);
	virtual long SetConsoleHandlesId(unsigned __int64);
	virtual long SetHostId(unsigned __int64);
	virtual long SetLpacAttributes(tagBLOB *);
	virtual long SetRacActivationTokenId(unsigned __int64);
	virtual long SetUserContext(unsigned __int64);
	virtual long UnSerialize(void *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct ExtensionRegistrationEntryProperties
{
	ExtensionRegistrationEntryProperties(ExtensionRegistrationEntryProperties const &);
	~ExtensionRegistrationEntryProperties();
};

namespace FeatureDevelopmentProperties
{
	struct PropertyScopeState
	{
		PropertyScopeState();
		~PropertyScopeState();
	};

	struct PropertyState<bool>
	{
		PropertyState<bool>();
	};

	struct PropertyState<unsigned int>
	{
		PropertyState<unsigned int>();
	};

	FeatureDevelopmentProperties::BoolPropertyDescriptor const * const g_aBoolPropertyDescriptors;
	FeatureDevelopmentProperties::ReadFromRegistryResult ReadUInt32FromRegistry(unsigned short const *,FeatureDevelopmentProperties::PropertyDescriptorFlags,unsigned short &,unsigned int *);
	FeatureDevelopmentProperties::UInt32PropertyDescriptor const * const g_aUInt32PropertyDescriptors;
	bool IsDefinitiveKeyPresenceResult(long);
	bool Query(FeatureDevelopmentProperties::BoolProperty,bool *);
	long OpenPerApplicationUserModelIdSubkey(RegistryKey const &,RegistryKey &);
	long OpenPerExeSubkey(RegistryKey const &,RegistryKey &);
	long OpenPerPackageFamilySubkey(RegistryKey const &,RegistryKey &);
	long OpenSelfKey(RegistryKey const &,RegistryKey &);
	unsigned int Query(FeatureDevelopmentProperties::UInt32Property,bool *);
	void InitializeTopLevelKeyInHKCU();
	void InitializeTopLevelKeyInHKLM();
};

struct FindDataStack
{
	long Push(void *,_WIN32_FIND_DATAW *);
};

struct FtmMarshaledObjectContainer
{
	long GetObject(unsigned int,IUnknown * *);
	long InsertObject(IUnknown *,unsigned int *);
	long RemoveObject(unsigned int);
};

class GIPEntry
{
	GIPEntry();
	static COleStaticMutexSem _pallocLock;
	static CPageAllocator _palloc;
	static unsigned long _dwCurrSeqNo;
};

struct GenericAsyncActionWithProgressFacade
{
	virtual long GetResults();
	virtual long get_Completed(void * *);
	virtual long get_Progress(void * *);
	virtual long put_Completed(IUnknown *);
	virtual long put_Progress(IUnknown *);
};

struct GenericAsyncCompletedHandlerFacade
{
	GenericAsyncCompletedHandlerFacade(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,ObjectLibrary::ReferencedPtr<IWinrtAsyncChannelOperation> const &);
	virtual long Invoke(IInspectable *,ABI::Windows::Foundation::AsyncStatus);
};

struct GenericAsyncOperationFacade
{
	virtual long GetResults(void *);
	virtual long get_Completed(void * *);
	virtual long put_Completed(IUnknown *);
};

struct GenericAsyncOperationWithProgressFacade
{
	virtual long GetResults(void *);
	virtual long get_Completed(void * *);
	virtual long get_Progress(void * *);
	virtual long put_Completed(IUnknown *);
	virtual long put_Progress(IUnknown *);
};

struct GenericCoTaskMemStream
{
	GenericCoTaskMemStream(unsigned long);
	virtual IStream * Clone();
};

struct GenericStream
{
	GenericStream();
	GenericStream(unsigned long);
	virtual IStream * Clone();
};

struct GenericStreamBase<IMarshalingStream,AllocationWrapper>
{
	virtual long Clone(IStream * *);
	virtual long Commit(unsigned long);
	virtual long CopyTo(IStream *,_ULARGE_INTEGER,_ULARGE_INTEGER *,_ULARGE_INTEGER *);
	virtual long GetBuffer(unsigned long *,unsigned char * *);
	virtual long GetCopy(unsigned char *);
	virtual long GetLength(unsigned long *);
	virtual long GetOrCreateBuffer(unsigned long,unsigned long *,unsigned char * *);
	virtual long LockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Read(void *,unsigned long,unsigned long *);
	virtual long Revert();
	virtual long Seek(_LARGE_INTEGER,unsigned long,_ULARGE_INTEGER *);
	virtual long SetBuffer(unsigned long,unsigned char *);
	virtual long SetCopyAlignment(unsigned long);
	virtual long SetPosition(unsigned long,unsigned long);
	virtual long SetSize(_ULARGE_INTEGER);
	virtual long Stat(tagSTATSTG *,unsigned long);
	virtual long UnlockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long Write(void const *,unsigned long,unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~GenericStreamBase<IMarshalingStream,AllocationWrapper>();
};

struct GenericStreamBase<IStream,AllocationWrapper>
{
	virtual long Clone(IStream * *);
	virtual long Commit(unsigned long);
	virtual long CopyTo(IStream *,_ULARGE_INTEGER,_ULARGE_INTEGER *,_ULARGE_INTEGER *);
	virtual long GetBuffer(unsigned long *,unsigned char * *);
	virtual long GetCopy(unsigned char *);
	virtual long GetLength(unsigned long *);
	virtual long GetOrCreateBuffer(unsigned long,unsigned long *,unsigned char * *);
	virtual long LockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Read(void *,unsigned long,unsigned long *);
	virtual long Revert();
	virtual long Seek(_LARGE_INTEGER,unsigned long,_ULARGE_INTEGER *);
	virtual long SetBuffer(unsigned long,unsigned char *);
	virtual long SetCopyAlignment(unsigned long);
	virtual long SetPosition(unsigned long,unsigned long);
	virtual long SetSize(_ULARGE_INTEGER);
	virtual long Stat(tagSTATSTG *,unsigned long);
	virtual long UnlockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long Write(void const *,unsigned long,unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~GenericStreamBase<IStream,AllocationWrapper>();
	void AssignSerializedInterface(tagInterfaceData * *);
};

struct GenericStreamBase<IStream,CoTaskMemAllocAllocator>
{
	GenericStreamBase<IStream,CoTaskMemAllocAllocator>(tagInterfaceData *);
	virtual long Clone(IStream * *);
	virtual long Commit(unsigned long);
	virtual long CopyTo(IStream *,_ULARGE_INTEGER,_ULARGE_INTEGER *,_ULARGE_INTEGER *);
	virtual long GetBuffer(unsigned long *,unsigned char * *);
	virtual long GetCopy(unsigned char *);
	virtual long GetLength(unsigned long *);
	virtual long GetOrCreateBuffer(unsigned long,unsigned long *,unsigned char * *);
	virtual long LockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Read(void *,unsigned long,unsigned long *);
	virtual long Revert();
	virtual long Seek(_LARGE_INTEGER,unsigned long,_ULARGE_INTEGER *);
	virtual long SetBuffer(unsigned long,unsigned char *);
	virtual long SetCopyAlignment(unsigned long);
	virtual long SetPosition(unsigned long,unsigned long);
	virtual long SetSize(_ULARGE_INTEGER);
	virtual long Stat(tagSTATSTG *,unsigned long);
	virtual long UnlockRegion(_ULARGE_INTEGER,_ULARGE_INTEGER,unsigned long);
	virtual long Write(void const *,unsigned long,unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~GenericStreamBase<IStream,CoTaskMemAllocAllocator>();
};

struct IClassClassicInfo2Impl
{
	virtual long GetServerExecutable(unsigned short * *);
};

struct IClassClassicInfo3Impl
{
	virtual long GetBinaryName(unsigned short * *);
	virtual long GetDisplayName(unsigned short * *);
	virtual long GetExecutionPackageName(unsigned short const * *);
	virtual long GetIconReference(unsigned short * *);
	virtual long GetLUAEnabledSetting(int *);
	virtual long GetOutofprocServerBinaryArchitecture(unsigned long *);
	virtual long GetPreferredServerBitness(unsigned long *);
	virtual long GetUserSettings(int *);
};

struct IClassClassicInfoImpl
{
	virtual long GetLocalServerType(tagLocalServerType *);
	virtual long GetProcess(_GUID const &,void * *);
	virtual long GetRemoteServerName(unsigned short * *);
	virtual long GetSurrogateCommandLine(unsigned short * *);
};

struct IComCatalogInternalImpl
{
	virtual long FlushCache();
	virtual long GetApplicationInfo(IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetApplicationInfoForExe(IUserToken *,unsigned short *,_GUID const &,void * *,void *);
	virtual long GetClassInfoFromProgId(IUserToken *,unsigned short *,_GUID const &,void * *,void *);
	virtual long GetClassInfoW(unsigned long,IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetInterfaceInfo(IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetProcessInfo(IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetRetQueueInfo(IUserToken *,unsigned short *,_GUID const &,void * *,void *);
	virtual long GetServerGroupInfo(IUserToken *,_GUID const &,_GUID const &,void * *,void *);
	virtual long GetTypeLibrary(IUserToken *,_GUID const &,_GUID const &,void * *,void *);
};

struct IComClassInfoImpl
{
	virtual long GetApplication(_GUID const &,void * *);
	virtual long GetClassNameW(unsigned short const * *);
	virtual long GetCustomActivatorClsids(tagACTIVATION_STAGE,_GUID * *);
	virtual long GetCustomActivatorCount(tagACTIVATION_STAGE,unsigned long *);
	virtual long GetCustomActivators(tagACTIVATION_STAGE,ISystemActivator * * *);
	virtual long GetProgId(unsigned short * *);
	virtual long GetTypeInfo(_GUID const &,void * *);
	virtual long GetVersionNumber(unsigned long *,unsigned long *);
	virtual long IsComPlusConfiguredClass(int *);
	virtual long Lock();
	virtual long MustRunInClientContext(int *);
	virtual long Unlock();
};

struct IComProcessInfoImplBase<IComProcessInfo3>
{
	virtual long GetActivateAtStorage(int *);
	virtual long GetAppIDFlags(unsigned long *);
	virtual long GetApplicationId(unsigned short const * *);
	virtual long GetAuthenticationCapabilities(unsigned long *);
	virtual long GetAuthenticationLevel(unsigned long *);
	virtual long GetCommandPathAndDebug(int *,unsigned short * *);
	virtual long GetEndpoints(unsigned long *,tagDCOM_ENDPOINT * *);
	virtual long GetExecutionPackageName(unsigned short const * *);
	virtual long GetImpersonationLevel(unsigned long *);
	virtual long GetLaunchPermission(void * *,unsigned long *);
	virtual long GetMGOTFlags(unsigned long *);
	virtual long GetManifestLocation(unsigned short * *);
	virtual long GetPreferredServerBitness(unsigned long *);
	virtual long GetProcessMitigationPolicy(tagBLOB *);
	virtual long GetProcessName(unsigned short * *);
	virtual long GetROTFlags(unsigned long *);
	virtual long GetRemoteServerName(unsigned short * *);
	virtual long GetRunAsUser(unsigned short * *);
	virtual long GetSaferTrustLevel(unsigned long *);
	virtual long GetServiceName(unsigned short * *);
	virtual long GetServiceParameters(unsigned short * *);
	virtual long GetSurrogatePath(unsigned short * *);
	virtual long GetSurrogateServerExecutable(unsigned short * *);
	virtual long GetUserSettings(int *);
	virtual long IsUserService(int *);
	virtual long SendsProcessEvents(int *);
};

struct IFaceEntry
{
	CtxEntry * AddCtxEntry(CPolicySet *);
	CtxEntry * LookupCtxEntry(CObjectContext *);
	CtxEntry * ValidateContext(CObjectContext *,CPolicySet *);
	static CPageAllocator s_allocator;
	void PrepareForDestruction();
};

struct IMessageParamList
{
	ObjectLibrary::ReferencedPtr<IMessageParam> Remove(IMessageParamList::Iterator &);
	ObjectLibrary::ReferencedPtr<IMessageParam> RemoveFirst();
	void InsertLast(IMessageParam *);
	~IMessageParamList();
};

struct IProcessServerInfoImpl
{
	virtual long EnumApplications(IEnumUnknown * *);
	virtual long EnumRetQueues(IEnumUnknown * *);
	virtual long GetCrmLogFileName(unsigned short * *);
	virtual long GetShutdownIdleTime(unsigned long *);
};

class InprocActpropsUnmarshaller
{
	static InprocActpropsUnmarshaller _InprocActUnmarshaller;
public:
	virtual long DisconnectObject(unsigned long);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long ReleaseMarshalData(IStream *);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct InstanceInfo
{
	virtual long GetCLSID(_GUID *);
	virtual long GetFile(unsigned short * *,unsigned long *);
	virtual long GetIfdROT(tagMInterfacePointer * *);
	virtual long GetSize(void *,unsigned long *);
	virtual long GetStorage(IStorage * *);
	virtual long GetStorageIFD(tagMInterfacePointer * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long SetFile(unsigned short *,unsigned long);
	virtual long SetIfdROT(tagMInterfacePointer *);
	virtual long SetStorage(IStorage *);
	virtual long SetStorageIFD(tagMInterfacePointer *);
	virtual long UnSerialize(void *);
	virtual long UnSerializeCallBack(_GUID const &,ISerializable * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~InstanceInfo();
};

struct InstantiationInfo
{
	long AddRequestedIIDs(unsigned long,_GUID *);
	virtual long GetCLSID(_GUID *);
	virtual long GetSize(void *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long UnSerialize(void *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~InstantiationInfo();
};

struct KeyRefreshInfo
{
	KeyRefreshInfo();
	void Clear();
	~KeyRefreshInfo();
};

struct LegacyFreeSyncClientCall
{
	virtual long Cancel(tagRPCOLEMESSAGE *);
	virtual long GetState(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
	virtual long Receive2(tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
	virtual long RegisterAsync(tagRPCOLEMESSAGE *,CChannelObject *);
	virtual long Send(tagRPCOLEMESSAGE *,CChannelObject *,unsigned long *);
	virtual long Send(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long Send2(tagRPCOLEMESSAGE *,unsigned long *);
};

class LegacyFreeSyncServerCall
{
protected:
	LegacyFreeSyncServerCall(_GUID const &,bool,ComCallTraceActivity *,unsigned int,unsigned long,unsigned long);
public:
	virtual long GetCallContext(tagRPCOLEMESSAGE *,_GUID const &,void * *);
	virtual long GetState(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long RegisterAsync(tagRPCOLEMESSAGE *);
	virtual long Send(tagRPCOLEMESSAGE *,unsigned long *);
};

class LockEntry
{
	static LockEntry * SlowGetOrCreateLockEntry(Thread *,CRWLock * const);
public:
	static LockEntry * FastGetOrCreateLockEntry(CRWLock * const);
	static LockEntry * GetLockEntry(CRWLock * const);
	static int ThreadCleanup(void *);
	static void * ThreadInit(unsigned long);
	void RecycleLockEntry();
};

struct MIDEntry
{
	unsigned long DecRefCnt();
};

struct MarshaledHandleStorage
{
	bool HasUnretrievedHandles();
	long AttachHandle(void *,unsigned char,unsigned long,unsigned long,unsigned long *);
	long GetHandle(unsigned long,unsigned char,unsigned long,void * *);
};

namespace Microsoft
{
	namespace WRL
	{
		struct ActivationFactory<Details::Nil,Details::Nil,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::Foundation::IActivationContextFactory>,Details::Nil,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ActivationFactory<Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics,FtmBase,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AgileActivationFactory<Windows::Foundation::IActivationContextFactory,Details::Nil,Details::Nil,0>
		{
			AgileActivationFactory<Windows::Foundation::IActivationContextFactory,Details::Nil,Details::Nil,0>();
		};

		class ComPtr<ApartmentShutdownNode>
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<ApartmentShutdownNode> & operator=(ComPtr<ApartmentShutdownNode> const &);
		};

		class ComPtr<CComApartment>
		{
		protected:
			unsigned long InternalRelease();
		};

		struct ComPtr<CExtensionRegistration>
		{
			void Attach(CExtensionRegistration *);
		};

		struct ComPtr<CObjectContext>
		{
			ComPtr<CObjectContext> & operator=(CObjectContext *);
		};

		struct ComPtr<CPackagedComCatalog::CPackagedComClassIdIterator>
		{
			void Attach(CPackagedComCatalog::CPackagedComClassIdIterator *);
		};

		struct ComPtr<CPackagedComCatalog::CPackagedComTypeLibRegistrationIterator>
		{
			void Attach(CPackagedComCatalog::CPackagedComTypeLibRegistrationIterator *);
		};

		class ComPtr<CStdMarshal>
		{
		protected:
			unsigned long InternalRelease();
		};

		struct ComPtr<Details::EventTargetArray>
		{
			void Attach(Details::EventTargetArray *);
		};

		class ComPtr<IActivationCatalogContext>
		{
		protected:
			unsigned long InternalRelease();
		public:
			long As<IDebugInformationContext>(Details::ComPtrRef<ComPtr<IDebugInformationContext> >);
		};

		class ComPtr<IAgileObject>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IAgileReference>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		};

		class ComPtr<IApartmentShutdown>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		};

		class ComPtr<IAsyncInfo>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ICacheRefresh>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ICallingProcessInfo>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ICancelMethodCalls>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		};

		class ComPtr<IClassClassicInfo3>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IClassClassicInfo>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IComCatalogInternal>
		{
		protected:
			unsigned long InternalRelease();
		public:
			long As<IPackagedComClassCatalogInternal>(Details::ComPtrRef<ComPtr<IPackagedComClassCatalogInternal> >);
			long As<IPackagedComProxyStubCatalogInternal>(Details::ComPtrRef<ComPtr<IPackagedComProxyStubCatalogInternal> >);
			long As<ITypeLibCatalogInternal>(Details::ComPtrRef<ComPtr<ITypeLibCatalogInternal> >);
		};

		class ComPtr<IComCatalogSCM>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IComCatalogTreatAsClass>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IComClassInfo>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ICreateRestrictedErrorInfo>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IDebugInformationContext>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IErrorInfo>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			long As<IRestrictedErrorInfo>(Details::ComPtrRef<ComPtr<IRestrictedErrorInfo> >);
		};

		class ComPtr<IExtensionActivationContext>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IExtensionCatalogContext>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IExtensionPackagesIterator>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IGlobalInterfaceTable>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IInspectable>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IInternalUnknown>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ILanguageExceptionErrorInfo2>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ILanguageExceptionErrorInfo>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ILanguageExceptionTransform>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IMarshal>
		{
		protected:
			unsigned long InternalRelease();
		};

		struct ComPtr<IMarshalingDirectionAndLocality>
		{
			~ComPtr<IMarshalingDirectionAndLocality>();
		};

		class ComPtr<IMarshalingStream>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IMetaDataImport2>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		};

		struct ComPtr<INotARealInterface>
		{
			~ComPtr<INotARealInterface>();
		};

		class ComPtr<IPSFactoryBuffer>
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<IPSFactoryBuffer> & operator=<IPerInterfacePSFactory>(ComPtr<IPerInterfacePSFactory> const &);
		};

		class ComPtr<IPackagedComCatalogContext>
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<IPackagedComCatalogContext> & operator=(ComPtr<IPackagedComCatalogContext> const &);
		};

		class ComPtr<IPackagedComClassCatalogInternal>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IPackagedComProxyStubCatalogInternal>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IPerInterfacePSFactory>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IProxyServerIdentity>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IRegistration>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IRegistrationStoreContext>
		{
		protected:
			unsigned long InternalRelease();
		public:
			long As<IActivationCatalogContext>(Details::ComPtrRef<ComPtr<IActivationCatalogContext> >);
			long As<IExtensionCatalogContext>(Details::ComPtrRef<ComPtr<IExtensionCatalogContext> >);
		};

		class ComPtr<IRestrictedErrorInfo>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			ComPtr<IRestrictedErrorInfo> & operator=(IRestrictedErrorInfo *);
			long As<IErrorInfo>(Details::ComPtrRef<ComPtr<IErrorInfo> >);
			long As<IRestrictedErrorInfoInternal>(Details::ComPtrRef<ComPtr<IRestrictedErrorInfoInternal> >);
		};

		class ComPtr<IRestrictedErrorInfoContext>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IRestrictedErrorInfoInternal>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IRestrictedErrorInfoTelemetry>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IRpcChannelBuffer2>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IRpcChannelBuffer3>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IRpcChannelBuffer>
		{
		protected:
			unsigned long InternalRelease();
		public:
			long As<IRpcChannelBuffer3>(Details::ComPtrRef<ComPtr<IRpcChannelBuffer3> >);
			long As<IRpcChannelBufferMarshalingContext>(Details::ComPtrRef<ComPtr<IRpcChannelBufferMarshalingContext> >);
		};

		class ComPtr<IRpcChannelBufferMarshalingContext>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IRpcOptions>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IRpcProxyBuffer>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IStorage>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IStubManagerDisconnect>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ISynchronize>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ITypeInfo>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ITypeLib>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ITypeLibCatalogInternal>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IUnhandledErrorForwarder>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IUnknown>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			ComPtr<IUnknown> & operator=(ComPtr<IUnknown> const &);
			ComPtr<IUnknown> & operator=(IUnknown *);
			ComPtr<IUnknown>();
			long As<IClassClassicInfo3>(Details::ComPtrRef<ComPtr<IClassClassicInfo3> >);
			long As<IComClassInfo>(Details::ComPtrRef<ComPtr<IComClassInfo> >);
			~ComPtr<IUnknown>();
		};

		class ComPtr<IWeakReference>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IWinRTClassActivator>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IWinRTDesktopBroker>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IWinRTInterfaceInformation>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IWinRTRuntimeClassInfo>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IWinRTServerInfo>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IWinrtTypeSerializer>
		{
		protected:
			void InternalAddRef();
		};

		struct ComPtr<OutParameterMarshalingClient>
		{
			void Attach(OutParameterMarshalingClient *);
		};

		struct ComPtr<RegistrationStore::Context>
		{
			~ComPtr<RegistrationStore::Context>();
		};

		struct ComPtr<RegistrationStoreData::PackageData>
		{
			void Attach(RegistrationStoreData::PackageData *);
		};

		class ComPtr<RegistrationStoreData::RegistryKeyData>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<RegistrationStoreData::RegistryKeyData>();
		};

		class ComPtr<RegistrationStoreTypes::IData>
		{
		protected:
			unsigned long InternalRelease();
		};

		struct ComPtr<RegistrationStoreTypes::IDataFactory>
		{
			~ComPtr<RegistrationStoreTypes::IDataFactory>();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<HSTRING__ *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> > & operator=(Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> *);
		};

		class ComPtr<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> >
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		};

		class ComPtr<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> >
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		};

		class ComPtr<Windows::Foundation::Collections::IMapView<HSTRING__ *,unsigned char> >
		{
		protected:
			void InternalAddRef();
		};

		class ComPtr<Windows::Foundation::Collections::IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> >
		{
		protected:
			void InternalAddRef();
		};

		class ComPtr<Windows::Foundation::Collections::IMapView<_GUID,HSTRING__ *> >
		{
		protected:
			void InternalAddRef();
		};

		class ComPtr<Windows::Foundation::Collections::IMapView<_GUID,bool> >
		{
		protected:
			void InternalAddRef();
		};

		class ComPtr<Windows::Foundation::Collections::IMapView<unsigned int,HSTRING__ *> >
		{
		protected:
			void InternalAddRef();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::AgileHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> > >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > >
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > > & operator=(ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > > const &);
			void Attach(Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > *);
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::Chunk>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > >
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > > & operator=(ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > > const &);
			void Attach(Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > *);
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::Chunk>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > >
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > > & operator=(ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > > const &);
			void Attach(Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > *);
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::Chunk>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> > >
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> > > & operator=(ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> > > const &);
			void Attach(Windows::Foundation::Collections::Internal::NaiveSplitView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> > *);
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::Chunk>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> > >
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> > > & operator=(ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> > > const &);
			void Attach(Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> > *);
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::Chunk>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> > >
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> > > & operator=(ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> > > const &);
			void Attach(Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> > *);
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::Chunk>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> > >
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> > > & operator=(ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> > > const &);
			void Attach(Windows::Foundation::Collections::Internal::NaiveSplitView<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> > *);
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::Chunk>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleKeyValuePair<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,1> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleKeyValuePair<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,0> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleKeyValuePair<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleKeyValuePair<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,1> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleKeyValuePair<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorView<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Diagnostics::CausalityTraceState>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics>
		{
		protected:
			unsigned long InternalRelease();
		};

		struct ComPtr<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs>
		{
			void Attach(Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs *);
		};

		class ComPtr<Windows::Foundation::IActivatableClassRegistration>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			long As<Windows::Foundation::IExeServerActivatableClassRegistration>(Details::ComPtrRef<ComPtr<Windows::Foundation::IExeServerActivatableClassRegistration> >);
		};

		class ComPtr<Windows::Foundation::IEventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::IExeServerActivatableClassRegistration>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::IExeServerAttributes>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::IExeServerRegistration>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::IExtensionRegistration>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		};

		class ComPtr<Windows::Foundation::IPropertyValueStatics>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Internal::StateRepository::IPackage>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Internal::StateRepository::IPackageStatics>
		{
		protected:
			unsigned long InternalRelease();
		};

		namespace Details
		{
			struct EventTargetArray
			{
				EventTargetArray();
				long RuntimeClassInitialize(unsigned __int64);
				void AddTail(IUnknown *,void *);
			};

			class ImplementsHelper<RuntimeClassFlags<2>,1,IClassClassicInfo2Impl,IClassClassicInfo3Impl,IComClassCategoryInfo,IOleClassInfo,ICacheRefresh,IRegistration>
			{
			protected:
				long CanCastToHelper<0>(_GUID const &,void * *,bool *);
			};

			class ImplementsHelper<RuntimeClassFlags<2>,1,IErrorInfo,IRestrictedErrorInfoContext,ChainInterfaces<ILanguageExceptionErrorInfo2,ILanguageExceptionErrorInfo,Nil,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,IRestrictedErrorInfoTelemetry,IRestrictedErrorInfoInternal,IMarshal>
			{
			protected:
				long CanCastToHelper<0>(_GUID const &,void * *,bool *);
			};

			class ModuleBase
			{
				static void * moduleLock_;
			protected:
				static unsigned long volatile objectCount_;
			public:
				static ModuleBase * module_;
				virtual CreatorMap const * * GetFirstEntryPointer();
				virtual CreatorMap const * * GetLastEntryPointer();
				virtual CreatorMap const * * GetMidEntryPointer();
				virtual _RTL_SRWLOCK * GetLock();
				virtual unsigned long GetObjectCount();
			};

			class RuntimeClassBaseT<13>
			{
			protected:
				static long AsIID<ActivationFactory<Implements<FtmBase,Windows::Foundation::IActivationContextFactory>,Nil,Nil,0> >(ActivationFactory<Implements<FtmBase,Windows::Foundation::IActivationContextFactory>,Nil,Nil,0> *,_GUID const &,void * *);
				static long AsIID<ActivationFactory<Nil,Nil,Nil,0> >(ActivationFactory<Nil,Nil,Nil,0> *,_GUID const &,void * *);
				static long AsIID<ActivationFactory<Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics,FtmBase,Nil,0> >(ActivationFactory<Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics,FtmBase,Nil,0> *,_GUID const &,void * *);
			};

			class RuntimeClassBaseT<1>
			{
			protected:
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,CActivatableClassRegistration,Windows::Foundation::IDllServerActivatableClassRegistration> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,CActivatableClassRegistration,Windows::Foundation::IDllServerActivatableClassRegistration> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<HSTRING__ *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<HSTRING__ *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::IExtensionRegistration *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::IExtensionRegistration *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<_GUID,bool>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<_GUID,bool>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,IInspectable> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,IInspectable> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Diagnostics::ITracingStatusChangedEventArgs,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Diagnostics::ITracingStatusChangedEventArgs,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::IActivationContext,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::IActivationContext,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::IExtensionCatalog,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::IExtensionCatalog,FtmBase> *,_GUID const &,void * *);
			};

			class RuntimeClassBaseT<2>
			{
			protected:
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,ChainInterfaces<IComProcessInfoImpl<IComProcessInfo3>,IComProcessInfo2,IComProcessInfo,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,IProcessServerInfoImpl,ICacheRefresh,IRegistration> >(RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,ChainInterfaces<IComProcessInfoImpl<IComProcessInfo3>,IComProcessInfo2,IComProcessInfo,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,IProcessServerInfoImpl,ICacheRefresh,IRegistration> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,ChainInterfaces<IRpcChannelBuffer3,IRpcChannelBuffer2,IRpcChannelBuffer,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,IRpcChannelBufferMarshalingContext> >(RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,ChainInterfaces<IRpcChannelBuffer3,IRpcChannelBuffer2,IRpcChannelBuffer,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,IRpcChannelBufferMarshalingContext> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IComCatalogInternalImpl,IComCatalogTreatAsClass,IPackagedComProxyStubCatalogInternal,IPackagedComClassCatalogInternal,ITypeLibCatalogInternal> >(RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IComCatalogInternalImpl,IComCatalogTreatAsClass,IPackagedComProxyStubCatalogInternal,IPackagedComClassCatalogInternal,ITypeLibCatalogInternal> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IComClassInfoImpl,IClassClassicInfoImpl,IClassClassicInfo2Impl,IClassClassicInfo3Impl,IComClassCategoryInfo,IOleClassInfo,ICacheRefresh,IRegistration> >(RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IComClassInfoImpl,IClassClassicInfoImpl,IClassClassicInfo2Impl,IClassClassicInfo3Impl,IComClassCategoryInfo,IOleClassInfo,ICacheRefresh,IRegistration> *,_GUID const &,void * *);
			};

			class RuntimeClassBaseT<3>
			{
			protected:
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,IAsyncInfo,IWinrtAsyncPatternFacade,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,IAsyncInfo,IWinrtAsyncPatternFacade,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Foundation::IExtensionRegistration,IExtensionActivationContext,FtmBase,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> > >(RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Foundation::IExtensionRegistration,IExtensionActivationContext,FtmBase,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> > *,_GUID const &,void * *);
			};

			struct RuntimeClassImpl<RuntimeClassFlags<14>,0,0,0,IUnknown>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,CActivatableClassRegistration,Windows::Foundation::IDllServerActivatableClassRegistration>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,CActivatableClassRegistration,Windows::Foundation::IDllServerActivatableClassRegistration>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,CActivatableClassRegistration,Windows::Foundation::IExeServerActivatableClassRegistration>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,CActivatableClassRegistration,Windows::Foundation::IExeServerActivatableClassRegistration>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<HSTRING__ *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<HSTRING__ *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::IExtensionRegistration *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::IExtensionRegistration *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<_GUID,bool>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<_GUID,bool>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,IInspectable>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,IInspectable>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Diagnostics::ITracingStatusChangedEventArgs,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Diagnostics::ITracingStatusChangedEventArgs,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::IActivationContext,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::IActivationContext,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::IExeServerRegistration,Windows::Foundation::IExeServerAttributes>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::IExeServerRegistration,Windows::Foundation::IExeServerAttributes>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::IExtensionCatalog,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::IExtensionCatalog,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,ChainInterfaces<IActivationCatalogContext,IRegistrationStoreContext,Nil,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,ChainInterfaces<IExtensionCatalogContext,IRegistrationStoreContext,Nil,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,ChainInterfaces<IDebugInformationContext,IRegistrationStoreContext,Nil,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,ChainInterfaces<IPackagedComCatalogContext,IRegistrationStoreContext,Nil,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,FtmBase>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,ChainInterfaces<IComProcessInfoImpl<IComProcessInfo3>,IComProcessInfo2,IComProcessInfo,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,IProcessServerInfoImpl,ICacheRefresh,IRegistration>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,ChainInterfaces<ICreateRestrictedErrorInfo3,ICreateRestrictedErrorInfo2,ICreateRestrictedErrorInfo,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,IRestrictedErrorInfo,IErrorInfo,IRestrictedErrorInfoContext,ChainInterfaces<ILanguageExceptionErrorInfo2,ILanguageExceptionErrorInfo,Nil,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,IRestrictedErrorInfoTelemetry,IRestrictedErrorInfoInternal,IMarshal>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,ChainInterfaces<IPerInterfacePSFactory,IPSFactoryBuffer,Nil,Nil,Nil,Nil,Nil,Nil,Nil,Nil> >
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,ChainInterfaces<IRpcChannelBuffer3,IRpcChannelBuffer2,IRpcChannelBuffer,Nil,Nil,Nil,Nil,Nil,Nil,Nil>,IRpcChannelBufferMarshalingContext>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IAgileReference,FtmBase>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IComCatalogInternalImpl,IComCatalogTreatAsClass,IPackagedComProxyStubCatalogInternal,IPackagedComClassCatalogInternal,ITypeLibCatalogInternal>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IComClassInfoImpl,IClassClassicInfoImpl,IClassClassicInfo2Impl,IClassClassicInfo3Impl,IComClassCategoryInfo,IOleClassInfo,ICacheRefresh,IRegistration>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IComClassInfoImpl,IClassClassicInfoImpl>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IExtensionPackagesIterator>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IPSFactoryBuffer,IWinRTInterfaceInformation>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IPackagedComClassIdIterator>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IPackagedComProgIdIterator>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IRpcChannelBuffer,IRpcChannelBufferMarshalingContext>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IRpcProxyBuffer>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IRpcStubBuffer>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,ITypeLibRegistration,FtmBase>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,ITypeLibRegistrationIterator>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IUnknown>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IWeakReference>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IWinrtAsyncPatternFacade,FtmBase>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IWinrtTypeSerializer,FtmBase>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,RegistrationStoreData::RegistryKeyData>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,RegistrationStoreTypes::IData>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,RegistrationStoreTypes::IDataFactory>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,Windows::Foundation::IEventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs *>,FtmBase>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,IAsyncInfo,IWinrtAsyncPatternFacade,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,IAsyncInfo,IWinrtAsyncPatternFacade,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Foundation::IExtensionRegistration,IExtensionActivationContext,FtmBase,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Foundation::IExtensionRegistration,IExtensionActivationContext,FtmBase,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> >();
			};

			struct WeakReferenceImpl
			{
				WeakReferenceImpl(IUnknown *);
				virtual long Resolve(_GUID const &,IInspectable * *);
			};

			ComPtr<AsyncActionCompletedHandlerFacade> Make<AsyncActionCompletedHandlerFacade,ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &);
			ComPtr<AsyncActionFacade> Make<AsyncActionFacade,ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &,unsigned long &>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &,unsigned long &);
			ComPtr<CAgileReferenceViaGit> Make<CAgileReferenceViaGit,unsigned long &>(unsigned long &);
			ComPtr<CExtensionAllPackagesIterator> Make<CExtensionAllPackagesIterator,OpaqueString const &,ComPtr<CActivationStore> const &,ComPtr<Windows::Internal::StateRepository::IPackageStatics> const &>(OpaqueString const &,ComPtr<CActivationStore> const &,ComPtr<Windows::Internal::StateRepository::IPackageStatics> const &);
			ComPtr<CPackagedComCatalog::CPackagedComProxyStubClassInfo> Make<CPackagedComCatalog::CPackagedComProxyStubClassInfo,_GUID const &,OpaqueString &>(_GUID const &,OpaqueString &);
			ComPtr<CPerInterfacePSFactory> Make<CPerInterfacePSFactory,ICreatePerInterfacePSFactory * &,_GUID const &,tagProxyFileInfo const * &,long &>(ICreatePerInterfacePSFactory * &,_GUID const &,tagProxyFileInfo const * &,long &);
			ComPtr<GenericAsyncActionWithProgressFacade> Make<GenericAsyncActionWithProgressFacade,ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &,unsigned long &>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &,unsigned long &);
			ComPtr<GenericAsyncCompletedHandlerFacade> Make<GenericAsyncCompletedHandlerFacade,ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &);
			ComPtr<GenericAsyncOperationFacade> Make<GenericAsyncOperationFacade,ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &,unsigned long &>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &,unsigned long &);
			ComPtr<GenericAsyncOperationWithProgressFacade> Make<GenericAsyncOperationWithProgressFacade,ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &,unsigned long &>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> const &,IWinrtAsyncChannelOperation * &,unsigned long &);
			ComPtr<OutParameterMarshalingClient> Make<OutParameterMarshalingClient,unsigned long &,CachedEvent &>(unsigned long &,CachedEvent &);
			ComPtr<OutParameterMarshalingSet> Make<OutParameterMarshalingSet,ComPtr<OutParameterMarshalingClient> &>(ComPtr<OutParameterMarshalingClient> &);
			ComPtr<RegistrationStoreData::DataFactory::UserDeploymentDataFactory> Make<RegistrationStoreData::DataFactory::UserDeploymentDataFactory,void * &>(void * &);
			ComPtr<RegistrationStoreData::PrivateHiveReaderRegistryKeyData> Make<RegistrationStoreData::PrivateHiveReaderRegistryKeyData,OpaqueString &>(OpaqueString &);
			ComPtr<RegistrationStoreData::PrivateHiveRegistryKeyData> Make<RegistrationStoreData::PrivateHiveRegistryKeyData,OpaqueString &,OpaqueString &,bool &>(OpaqueString &,OpaqueString &,bool &);
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::ChunkView> Make<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::ChunkView,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &>(Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &);
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::ChunkView> Make<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::ChunkView,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &>(Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &);
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::ChunkView> Make<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::ChunkView,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &>(Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &);
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::ChunkView> Make<Windows::Foundation::Collections::Internal::NaiveSplitView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::ChunkView,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate &>(CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate &);
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::ChunkView> Make<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::ChunkView,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID> &>(Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID> &);
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::ChunkView> Make<Windows::Foundation::Collections::Internal::NaiveSplitView<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::ChunkView,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID> &>(Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID> &);
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::ChunkView> Make<Windows::Foundation::Collections::Internal::NaiveSplitView<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::ChunkView,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int> &>(Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int> &);
			Details::WeakReferenceImpl * CreateWeakReference(IUnknown *);
			bool TerminateMap(Details::ModuleBase *,unsigned short const *,bool);
			long CreateActivationFactory<ActivationContextFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<CExtensionCatalog::CFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Foundation::Diagnostics::AsyncCausalityTracerFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long GetActivationFactory<1>(Details::ModuleBase *,unsigned short const *,HSTRING__ *,IActivationFactory * *);
			long GetCacheEntry(Details::ModuleBase *,unsigned int *,_GUID const &,Details::CreatorMap const *,IUnknown * *);
			long MakeAndInitialize<ActivationContext,Windows::Foundation::IActivationContext,unsigned __int64 &,unsigned __int64 &,_GUID &,unsigned __int64 &,unsigned long &,unsigned char * &>(Windows::Foundation::IActivationContext * *,unsigned __int64 &,unsigned __int64 &,_GUID &,unsigned __int64 &,unsigned long &,unsigned char * &);
			long MakeAndInitialize<CPackagedComCatalog::CPackagedComClassIdIterator,IPackagedComClassIdIterator,CPackagedComCatalog::CPackagedComClassIdIterator &>(IPackagedComClassIdIterator * *,CPackagedComCatalog::CPackagedComClassIdIterator &);
			long MakeAndInitialize<CPackagedComCatalog::CPackagedComTypeLibRegistrationIterator,ITypeLibRegistrationIterator,CPackagedComCatalog::CPackagedComTypeLibRegistrationIterator &>(ITypeLibRegistrationIterator * *,CPackagedComCatalog::CPackagedComTypeLibRegistrationIterator &);
			long MakeAndInitialize<EventTargetArray,EventTargetArray,unsigned __int64 &>(Details::EventTargetArray * *,unsigned __int64 &);
			long MakeAndInitialize<WinRT::Metadata::Marshaling::CMetadataProxyStubFactory<WinRT::Metadata::Marshaling::MetadataFormatStringDataSource<WinRT::Metadata::Marshaling::DefaultMetadataFormatStringSourceHelper> >,IPSFactoryBuffer,ObjectLibrary::ReferencedPtr<WinRT::Metadata::Marshaling::TypeCache> &>(IPSFactoryBuffer * *,ObjectLibrary::ReferencedPtr<WinRT::Metadata::Marshaling::TypeCache> &);
			long MakeAndInitialize<WinrtTypeSerializer,WinrtTypeSerializer,_MIDL_WINRT_TYPE_SERIALIZATION_INFO const * &>(WinrtTypeSerializer * *,_MIDL_WINRT_TYPE_SERIALIZATION_INFO const * &);
			void RaiseException(long,unsigned long);
		};

		class EventSource<Windows::Foundation::IEventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs *>,InvokeModeOptions<-2> >
		{
			long AddInternal(Windows::Foundation::IEventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs *> *,void *,EventRegistrationToken *);
		public:
			long Remove(EventRegistrationToken);
		};

		class FtmBase
		{
		protected:
			long CanCastTo(_GUID const &,void * *);
		public:
			FtmBase();
			virtual long DisconnectObject(unsigned long);
			virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
			virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
			virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
			virtual long ReleaseMarshalData(IStream *);
			virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
		};

		class Module<1,Details::DefaultModule<1> >
		{
			static bool StaticInitialize();
			static bool isInitialized;
		public:
			static Details::DefaultModule<1> & Create();
			virtual long RegisterCOMObject(unsigned short const *,_GUID *,IClassFactory * *,unsigned long *,unsigned int);
			virtual long RegisterWinRTObject(unsigned short const *,unsigned short const * *,<unnamed-type-RO_REGISTRATION_COOKIE> * *,unsigned int);
			virtual long UnregisterCOMObject(unsigned short const *,unsigned long *,unsigned int);
			virtual long UnregisterWinRTObject(unsigned short const *,<unnamed-type-RO_REGISTRATION_COOKIE> *);
			virtual unsigned long DecrementObjectCount();
			virtual unsigned long IncrementObjectCount();
			virtual ~Module<1,Details::DefaultModule<1> >();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,ChainInterfaces<ICreateRestrictedErrorInfo3,ICreateRestrictedErrorInfo2,ICreateRestrictedErrorInfo,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil>,IRestrictedErrorInfo,IErrorInfo,IRestrictedErrorInfoContext,ChainInterfaces<ILanguageExceptionErrorInfo2,ILanguageExceptionErrorInfo,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil>,IRestrictedErrorInfoTelemetry,IRestrictedErrorInfoInternal,IMarshal>
		{
			RuntimeClass<RuntimeClassFlags<2>,ChainInterfaces<ICreateRestrictedErrorInfo3,ICreateRestrictedErrorInfo2,ICreateRestrictedErrorInfo,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil>,IRestrictedErrorInfo,IErrorInfo,IRestrictedErrorInfoContext,ChainInterfaces<ILanguageExceptionErrorInfo2,ILanguageExceptionErrorInfo,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil,Details::Nil>,IRestrictedErrorInfoTelemetry,IRestrictedErrorInfoInternal,IMarshal>();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,IAgileReference,FtmBase>
		{
			RuntimeClass<RuntimeClassFlags<2>,IAgileReference,FtmBase>();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,IComClassInfoImpl,IClassClassicInfoImpl,IClassClassicInfo2Impl,IClassClassicInfo3Impl,IComClassCategoryInfo,IOleClassInfo,ICacheRefresh,IRegistration>
		{
			RuntimeClass<RuntimeClassFlags<2>,IComClassInfoImpl,IClassClassicInfoImpl,IClassClassicInfo2Impl,IClassClassicInfo3Impl,IComClassCategoryInfo,IOleClassInfo,ICacheRefresh,IRegistration>();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,IUnknown>
		{
			RuntimeClass<RuntimeClassFlags<2>,IUnknown>();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,IWinrtAsyncPatternFacade,FtmBase>
		{
			RuntimeClass<RuntimeClassFlags<2>,IWinrtAsyncPatternFacade,FtmBase>();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,RegistrationStoreData::RegistryKeyData>
		{
			RuntimeClass<RuntimeClassFlags<2>,RegistrationStoreData::RegistryKeyData>();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,RegistrationStoreTypes::IDataFactory>
		{
			RuntimeClass<RuntimeClassFlags<2>,RegistrationStoreTypes::IDataFactory>();
		};

		struct RuntimeClass<RuntimeClassFlags<3>,IAsyncInfo,IWinrtAsyncPatternFacade,FtmBase>
		{
			RuntimeClass<RuntimeClassFlags<3>,IAsyncInfo,IWinrtAsyncPatternFacade,FtmBase>();
		};

		struct RuntimeClass<RuntimeClassFlags<3>,Windows::Foundation::IExtensionRegistration,IExtensionActivationContext,FtmBase,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> >
		{
			RuntimeClass<RuntimeClassFlags<3>,Windows::Foundation::IExtensionRegistration,IExtensionActivationContext,FtmBase,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::IExtensionRegistration *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::IExtensionRegistration *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMap<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IMap<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMap<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IMap<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMap<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IMap<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,unsigned char>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,unsigned char> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMapView<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IMapView<_GUID,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,HSTRING__ *> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMapView<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IMapView<_GUID,bool>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<_GUID,bool> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMapView<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IMapView<unsigned int,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<unsigned int,HSTRING__ *> *>,FtmBase>();
		};

		namespace Wrappers
		{
			namespace Details
			{
				class SyncLockExclusive
				{
					void InternalUnlock();
				};

				int CompareStringOrdinal(HSTRING__ *,HSTRING__ *);
			};

			struct HString
			{
				long Set(HSTRING__ * const &);
				long Set(unsigned short const *,unsigned int);
				long Set(wchar_t const *,unsigned int);
				long Set<256>(wchar_t (&)[256]);
				long Set<39>(unsigned short (&)[39]);
				long Set<unsigned short *>(unsigned short * const &,Details::Dummy);
				long Set<unsigned short const *>(unsigned short const * const &,Details::Dummy);
			};

			class HStringReference
			{
				static unsigned int AddOne(unsigned int);
				void CreateReference(unsigned short const *,unsigned int,unsigned int);
				void CreateReference(wchar_t const *,unsigned int,unsigned int);
			public:
				HStringReference(unsigned short const *,unsigned int);
				HStringReference<20>(wchar_t (&)[20]);
				HStringReference<39>(unsigned short (&)[39]);
				HStringReference<39>(wchar_t (&)[39]);
				HStringReference<512>(wchar_t (&)[512]);
				HStringReference<unsigned short *>(unsigned short * const &,Details::Dummy);
				HStringReference<unsigned short const *>(unsigned short const * const &,Details::Dummy);
				HStringReference<wchar_t const *>(wchar_t const * const &,Details::Dummy);
			};

			class HandleT<CachedCallEventHandleTraits>
			{
			protected:
				virtual bool InternalClose();
			public:
				void Close();
			};

			class HandleT<CachedEventHandleTraits>
			{
			protected:
				virtual bool InternalClose();
			public:
				void Close();
			};

			class HandleT<HandleTraits::EventTraits>
			{
			protected:
				virtual bool InternalClose();
			public:
				void Close();
			};

			class HandleT<HandleTraits::HANDLENullTraits>
			{
			protected:
				virtual bool InternalClose();
			};

		};

		long AsWeak<IAsyncInfo>(IAsyncInfo *,WRL::WeakRef *);
	};

};

class OXIDEntry
{
	OXIDEntry(unsigned __int64 const &,MIDEntry *,tagOXID_INFO const *,unsigned long,std::unique_ptr<unsigned char [0],DeleteMarshaledTargetInfo>,unsigned long,long &);
	long CreateDefaultHandle(CChannelHandle * *);
	long MakeRemUnk();
	long UnmarshalRemUnk(_GUID const &,void * *);
	static CPageAllocator _palloc;
	static void operator delete(void *);
	void ExpireEntry();
public:
	MIDEntry * GetMIDEntry();
	bool IsInLocalProcess();
	long CleanupRemoting();
	long FreeOXIDAndOIDs(unsigned long,unsigned __int64 *);
	long GetDefaultHandle(CChannelHandle * *);
	long GetRemUnk(IRemUnknown * *);
	long GetRpcBindingHandle(void * *);
	long GetTargetName(unsigned short const *,unsigned short * *);
	long InitRemoting(CComApartment *);
	long PostCall(ServerCall *,unsigned long *);
	long RegisterOXIDAndOIDs(unsigned long *,unsigned __int64 *);
	long StartServer();
	long StopServer();
	unsigned long DecRefCnt();
	unsigned long IncRefCnt();
	void FillOXID_INFO(tagOXID_INFO *);
	void WaitForApartmentShutdown();
};

namespace ObjectLibrary
{
	class AddAllocation<AllocationOptions<PrivMemAllocator,368,Details::Nil>,ServerCall,AddComReferenceCounting<ComReferenceCountingOptions<4>,ServerCall,ForwardedBases<CBaseCall,IMessageParam,IServerCall> > >
	{
	protected:
		AddAllocation<AllocationOptions<PrivMemAllocator,368,Details::Nil>,ServerCall,AddComReferenceCounting<ComReferenceCountingOptions<4>,ServerCall,ForwardedBases<CBaseCall,IMessageParam,IServerCall> > >();
	};

	class AddComReferenceCounting<ComReferenceCountingOptions<1>,CChannelObject,ForwardedBases<IAsyncRpcChannelBuffer,IRpcSyntaxNegotiate,ICancelMethodCalls,IClientSecurity,IMessageParam> >
	{
	protected:
		AddComReferenceCounting<ComReferenceCountingOptions<1>,CChannelObject,ForwardedBases<IAsyncRpcChannelBuffer,IRpcSyntaxNegotiate,ICancelMethodCalls,IClientSecurity,IMessageParam> >();
	};

	class AddDebugging<DebuggingOptions<0>,CMessageCall,PolymorphicType<OneOf<CAsyncCall,CClientCall>,CMessageCall,AddAllocation<AllocationOptions<PrivMemAllocator,368,Details::Nil>,CMessageCall,AddComReferenceCounting<ComReferenceCountingOptions<4>,CMessageCall,Details::Nil> > > >
	{
	protected:
		static void CleanUpAllocationHeader(void *,unsigned __int64);
	};

	namespace Details
	{
		struct AddComReferenceCounting_ForwardingLayer<AddComReferenceCounting_WeaklyReferenceableReferenceCountingLayer<WinrtAsyncChannelOperationEntry,AddComReferenceCounting_WeakReferenceCountLayer<WinrtAsyncChannelOperationEntry,AddComReferenceCounting_ReferenceCountLayer<WinrtAsyncChannelOperationEntry,Allocation_StandardDeleteSelfLayer<WinrtAsyncChannelOperationEntry,ContainedBy<ContainmentSpecification<WinrtAsyncChannelOperationMap,WinrtAsyncChannelOperationEntry,ContainerKind::OrderedMap,1>,WinrtAsyncChannelOperationEntry,Nil> > > > >,WinrtAsyncChannelOperation,MixinBase<WinrtAsyncChannelOperation,Mixins_BaseForwarderLayer<ForwardedBases<WinrtAsyncChannelOperationEntry,Dcomrem::Async::AsyncBaseStateMachine<WinrtAsyncChannelOperation,2,AsyncDelegateStorage,AsyncDelegateStorage>,IWinrtAsyncChannelOperation,IAsyncClientTransport,IClientTransportCallEvents,IServerTransportCallEvents> > > >
		{
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AddComReferenceCounting_NullReferenceCountingLayer<CDllHost,MixinBase<CDllHost,Mixins_BaseForwarderLayer<ForwardedBases<IDLLHost,IMessageParam> > > >
		{
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<ArrayOfGuids,AddComReferenceCounting_ReferenceCountLayer<ArrayOfGuids,Allocation_SealedClassDeleteSelfLayer<ArrayOfGuids,MixinBase<ArrayOfGuids,Mixins_NilBaseForwarderLayer> > > >
		{
			unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<AsyncComClientCall,AddComReferenceCounting_ReferenceCountLayer<AsyncComClientCall,Allocation_SealedClassDeleteSelfLayer<AsyncComClientCall,MixinBase<AsyncComClientCall,Mixins_BaseForwarderLayer<ForwardedBases<StandardComClientCall,IAsyncClientTransport> > > > > >
		{
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<CChannelObject,AddComReferenceCounting_ReferenceCountLayer<CChannelObject,Allocation_SealedClassDeleteSelfLayer<CChannelObject,MixinBase<CChannelObject,Mixins_BaseForwarderLayer<ForwardedBases<IAsyncRpcChannelBuffer,IRpcSyntaxNegotiate,ICancelMethodCalls,IClientSecurity,IMessageParam> > > > > >
		{
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<CClientChannel,AddComReferenceCounting_ReferenceCountLayer<CClientChannel,Allocation_SealedClassDeleteSelfLayer<CClientChannel,MixinBase<CClientChannel,Mixins_BaseForwarderLayer<ForwardedBases<CCtxComChnl,IRpcSyntaxNegotiate> > > > > >
		{
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<CComApartment,AddComReferenceCounting_ReferenceCountLayer<CComApartment,Allocation_SealedClassDeleteSelfLayer<CComApartment,MixinBase<CComApartment,Mixins_NilBaseForwarderLayer> > > >
		{
			unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<CCtxChnl,AddComReferenceCounting_ReferenceCountLayer<CCtxChnl,Allocation_SealedClassDeleteSelfLayer<CCtxChnl,MixinBase<CCtxChnl,Mixins_BaseForwarderLayer<ForwardedBases<IRpcChannelBuffer2,ICallFrameEvents,IRpcSyntaxNegotiate,IRpcChannelBufferMarshalingContext,IChannelHandleMarshal> > > > > >
		{
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<CServerChannel::CServerCallMgr,AddComReferenceCounting_ReferenceCountLayer<CServerChannel::CServerCallMgr,Allocation_SealedClassDeleteSelfLayer<CServerChannel::CServerCallMgr,MixinBase<CServerChannel::CServerCallMgr,Mixins_BaseForwarderLayer<ForwardedBases<ISynchronize,IServerSecurity,IRpcStubBuffer,ICancelMethodCalls> > > > > >
		{
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<CSyncClientCall,AddComReferenceCounting_ReferenceCountLayer<CSyncClientCall,Allocation_StandardDeleteSelfLayer<CSyncClientCall,MixinBase<CSyncClientCall,Mixins_BaseForwarderLayer<ForwardedBases<StandardComClientCall,ICancelMethodCalls> > > > > >
		{
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<ComCallTraceActivity,AddComReferenceCounting_ReferenceCountLayer<ComCallTraceActivity,Allocation_SealedClassDeleteSelfLayer<ComCallTraceActivity,MixinBase<ComCallTraceActivity,Mixins_NilBaseForwarderLayer> > > >
		{
			unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<FtmMarshaledObjectContainer,AddComReferenceCounting_ReferenceCountLayer<FtmMarshaledObjectContainer,Allocation_SealedClassDeleteSelfLayer<FtmMarshaledObjectContainer,MixinBase<FtmMarshaledObjectContainer,Mixins_NilBaseForwarderLayer> > > >
		{
			unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<Nil,AddComReferenceCounting_ReferenceCountLayer<Nil,Allocation_StandardDeleteSelfLayer<Nil,MixinBase<Nil,Mixins_NilBaseForwarderLayer> > > >
		{
			unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<OutParameterMarshalingServer,AddComReferenceCounting_ReferenceCountLayer<OutParameterMarshalingServer,Allocation_SealedClassDeleteSelfLayer<OutParameterMarshalingServer,MixinBase<OutParameterMarshalingServer,Mixins_NilBaseForwarderLayer> > > >
		{
			unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<RegistrationStoreData::PackageDataCacheEntry,AddComReferenceCounting_ReferenceCountLayer<RegistrationStoreData::PackageDataCacheEntry,Allocation_SealedClassDeleteSelfLayer<RegistrationStoreData::PackageDataCacheEntry,ContainedBy<ContainmentSpecification<RegistrationStoreData::PackageDataCache,RegistrationStoreData::PackageDataCacheEntry,ContainerKind::OrderedMap,0>,RegistrationStoreData::PackageDataCacheEntry,Nil> > > >
		{
			unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<WinRT::Metadata::Marshaling::MetadataType,AddComReferenceCounting_ReferenceCountLayer<WinRT::Metadata::Marshaling::MetadataType,Allocation_StandardDeleteSelfLayer<WinRT::Metadata::Marshaling::MetadataType,MixinBase<WinRT::Metadata::Marshaling::MetadataType,Mixins_NilBaseForwarderLayer> > > >
		{
			unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<WinrtAsyncClientCall,AddComReferenceCounting_ReferenceCountLayer<WinrtAsyncClientCall,Allocation_StandardDeleteSelfLayer<WinrtAsyncClientCall,MixinBase<WinrtAsyncClientCall,Mixins_BaseForwarderLayer<ForwardedBases<LegacyFreeSyncClientCall,IWinrtAsyncClientCall> > > > > >
		{
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AddComReferenceCounting_StandardReferenceCountingLayer<WinrtAsyncServerCall,AddComReferenceCounting_ReferenceCountLayer<WinrtAsyncServerCall,Allocation_StandardDeleteSelfLayer<WinrtAsyncServerCall,MixinBase<WinrtAsyncServerCall,Mixins_BaseForwarderLayer<ForwardedBases<LegacyFreeSyncServerCall,IWinrtAsyncServerCall> > > > > >
		{
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AddComReferenceCounting_WeaklyReferenceableReferenceCountingLayer<StackTrace,AddComReferenceCounting_WeakReferenceCountLayer<StackTrace,AddComReferenceCounting_ReferenceCountLayer<StackTrace,Allocation_SealedClassDeleteSelfLayer<StackTrace,ContainedBy<ContainmentSpecification<StackTraceDetails::GlobalStackTraceMap,StackTrace,ContainerKind::OrderedMap,1>,StackTrace,Nil> > > > >
		{
			unsigned long Release();
		};

		struct AddComReferenceCounting_WeaklyReferenceableReferenceCountingLayer<WinrtAsyncChannelOperationEntry,AddComReferenceCounting_WeakReferenceCountLayer<WinrtAsyncChannelOperationEntry,AddComReferenceCounting_ReferenceCountLayer<WinrtAsyncChannelOperationEntry,Allocation_StandardDeleteSelfLayer<WinrtAsyncChannelOperationEntry,ContainedBy<ContainmentSpecification<WinrtAsyncChannelOperationMap,WinrtAsyncChannelOperationEntry,ContainerKind::OrderedMap,1>,WinrtAsyncChannelOperationEntry,Nil> > > > >
		{
			unsigned long Release();
		};

		class AddGeneralTypeIdentityHelper<AsyncComClientCall,AddTypeIdentityLayersBuilder<AsyncComClientCall,AddComReferenceCounting<ComReferenceCountingOptions<1>,AsyncComClientCall,ForwardedBases<StandardComClientCall,IAsyncClientTransport> >,ForwardedBases<StandardComClientCall,IAsyncClientTransport> >::AddTypeIdLayerHelper<AddComReferenceCounting<ComReferenceCountingOptions<1>,AsyncComClientCall,ForwardedBases<StandardComClientCall,IAsyncClientTransport> >,PolymorphicType<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,Nil> >,1>
		{
			static GeneralTypeIdentity const s_generalTypeIdentity;
		protected:
			virtual GeneralTypeIdentity const & GetGeneralTypeIdentity();
		};

		class AddGeneralTypeIdentityHelper<CCtxCall,AddTypeIdentityLayersBuilder<CCtxCall,MixinBase<CCtxCall,Mixins_BaseForwarderLayer<ForwardedBases<CBaseCall,ICallFrameWalker,IServerCall> > >,ForwardedBases<CBaseCall,ICallFrameWalker,IServerCall> >::AddTypeIdLayerHelper<MixinBase<CCtxCall,Mixins_BaseForwarderLayer<ForwardedBases<CBaseCall,ICallFrameWalker,IServerCall> > >,PolymorphicType<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,Nil> >,0>
		{
			static GeneralTypeIdentity const s_generalTypeIdentity;
		protected:
			virtual GeneralTypeIdentity const & GetGeneralTypeIdentity();
		};

		class AddGeneralTypeIdentityHelper<CSyncClientCall,AddTypeIdentityLayersBuilder<CSyncClientCall,AddAllocation<AllocationOptions<InheritBaseAllocator,12,Nil>,CSyncClientCall,AddComReferenceCounting<ComReferenceCountingOptions<0>,CSyncClientCall,ForwardedBases<StandardComClientCall,ICancelMethodCalls> > >,ForwardedBases<StandardComClientCall,ICancelMethodCalls> >::AddTypeIdLayerHelper<AddAllocation<AllocationOptions<InheritBaseAllocator,12,Nil>,CSyncClientCall,AddComReferenceCounting<ComReferenceCountingOptions<0>,CSyncClientCall,ForwardedBases<StandardComClientCall,ICancelMethodCalls> > >,PolymorphicType<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,Nil> >,1>
		{
			static GeneralTypeIdentity const s_generalTypeIdentity;
		protected:
			virtual GeneralTypeIdentity const & GetGeneralTypeIdentity();
		};

		class AddGeneralTypeIdentityHelper<StandardComClientCall,AddComReferenceCounting<ComReferenceCountingOptions<4>,StandardComClientCall,ForwardedBases<ClientCall,IClientTransportCallEvents> >,1>
		{
			static GeneralTypeIdentity const s_generalTypeIdentity;
		protected:
			virtual GeneralTypeIdentity const & GetGeneralTypeIdentity();
		};

		class AddGeneralTypeIdentityHelper<StandardComServerCall,AddComReferenceCounting<ComReferenceCountingOptions<4>,StandardComServerCall,ForwardedBases<ServerCall,IServerTransportCallEvents> >,1>
		{
			static GeneralTypeIdentity const s_generalTypeIdentity;
		protected:
			virtual GeneralTypeIdentity const & GetGeneralTypeIdentity();
		};

		class AddGeneralTypeIdentityHelper<WinrtAsyncChannelOperation,AddTypeIdentityLayersBuilder<WinrtAsyncChannelOperation,AddAllocation<AllocationOptions<InheritBaseAllocator,0,Nil>,WinrtAsyncChannelOperation,AddComReferenceCounting<ComReferenceCountingOptions<17>,WinrtAsyncChannelOperation,ForwardedBases<WinrtAsyncChannelOperationEntry,Dcomrem::Async::AsyncBaseStateMachine<WinrtAsyncChannelOperation,2,AsyncDelegateStorage,AsyncDelegateStorage>,IWinrtAsyncChannelOperation,IAsyncClientTransport,IClientTransportCallEvents,IServerTransportCallEvents> > >,ForwardedBases<WinrtAsyncChannelOperationEntry,Dcomrem::Async::AsyncBaseStateMachine<WinrtAsyncChannelOperation,2,AsyncDelegateStorage,AsyncDelegateStorage>,IWinrtAsyncChannelOperation,IAsyncClientTransport,IClientTransportCallEvents,IServerTransportCallEvents> >::AddTypeIdLayerHelper<AddAllocation<AllocationOptions<InheritBaseAllocator,0,Nil>,WinrtAsyncChannelOperation,AddComReferenceCounting<ComReferenceCountingOptions<17>,WinrtAsyncChannelOperation,ForwardedBases<WinrtAsyncChannelOperationEntry,Dcomrem::Async::AsyncBaseStateMachine<WinrtAsyncChannelOperation,2,AsyncDelegateStorage,AsyncDelegateStorage>,IWinrtAsyncChannelOperation,IAsyncClientTransport,IClientTransportCallEvents,IServerTransportCallEvents> > >,PolymorphicType<OneOf<WinrtAsyncChannelOperationPlaceholder,WinrtAsyncChannelOperation>,WinrtAsyncChannelOperationEntry,AddAllocation<AllocationOptions<PrivMemAllocator,0,Nil>,WinrtAsyncChannelOperationEntry,AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncChannelOperationEntry,ContainedBy<ContainmentSpecification<WinrtAsyncChannelOperationMap,WinrtAsyncChannelOperationEntry,ContainerKind::OrderedMap,1>,WinrtAsyncChannelOperationEntry,Nil> > > > >,0>
		{
			static GeneralTypeIdentity const s_generalTypeIdentity;
		protected:
			virtual GeneralTypeIdentity const & GetGeneralTypeIdentity();
		};

		class AddGeneralTypeIdentityHelper<WinrtAsyncClientCall,AddTypeIdentityLayersBuilder<WinrtAsyncClientCall,AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncClientCall,ForwardedBases<LegacyFreeSyncClientCall,IWinrtAsyncClientCall> >,ForwardedBases<LegacyFreeSyncClientCall,IWinrtAsyncClientCall> >::AddTypeIdLayerHelper<AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncClientCall,ForwardedBases<LegacyFreeSyncClientCall,IWinrtAsyncClientCall> >,PolymorphicType<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,Nil> >,1>
		{
			static GeneralTypeIdentity const s_generalTypeIdentity;
		protected:
			virtual GeneralTypeIdentity const & GetGeneralTypeIdentity();
		};

		class AddGeneralTypeIdentityHelper<WinrtAsyncServerCall,AddTypeIdentityLayersBuilder<WinrtAsyncServerCall,AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncServerCall,ForwardedBases<LegacyFreeSyncServerCall,IWinrtAsyncServerCall> >,ForwardedBases<LegacyFreeSyncServerCall,IWinrtAsyncServerCall> >::AddTypeIdLayerHelper<AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncServerCall,ForwardedBases<LegacyFreeSyncServerCall,IWinrtAsyncServerCall> >,PolymorphicType<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,Nil> >,1>
		{
			static GeneralTypeIdentity const s_generalTypeIdentity;
		protected:
			virtual GeneralTypeIdentity const & GetGeneralTypeIdentity();
		};

		namespace AddTypeIdentityLayersBuilder<AsyncComClientCall,AddComReferenceCounting<ComReferenceCountingOptions<1>,AsyncComClientCall,ForwardedBases<StandardComClientCall,IAsyncClientTransport> >,ForwardedBases<StandardComClientCall,IAsyncClientTransport> >
		{
			struct AddTypeIdLayerHelper<AddComReferenceCounting<ComReferenceCountingOptions<1>,AsyncComClientCall,ForwardedBases<StandardComClientCall,IAsyncClientTransport> >,PolymorphicType<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,Nil> >
			{
				virtual PolymorphicTypeIdHelper<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,MixinBase<CBaseCall,Mixins_NilBaseForwarderLayer> >::WhichType GetTypeId(PolymorphicTypeIdHelper<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,MixinBase<CBaseCall,Mixins_NilBaseForwarderLayer> > const *);
			};

		};

		namespace AddTypeIdentityLayersBuilder<CCtxCall,MixinBase<CCtxCall,Mixins_BaseForwarderLayer<ForwardedBases<CBaseCall,ICallFrameWalker,IServerCall> > >,ForwardedBases<CBaseCall,ICallFrameWalker,IServerCall> >
		{
			struct AddTypeIdLayerHelper<MixinBase<CCtxCall,Mixins_BaseForwarderLayer<ForwardedBases<CBaseCall,ICallFrameWalker,IServerCall> > >,PolymorphicType<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,Nil> >
			{
				virtual PolymorphicTypeIdHelper<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,MixinBase<CBaseCall,Mixins_NilBaseForwarderLayer> >::WhichType GetTypeId(PolymorphicTypeIdHelper<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,MixinBase<CBaseCall,Mixins_NilBaseForwarderLayer> > const *);
			};

		};

		namespace AddTypeIdentityLayersBuilder<CSyncClientCall,AddAllocation<AllocationOptions<InheritBaseAllocator,12,Nil>,CSyncClientCall,AddComReferenceCounting<ComReferenceCountingOptions<0>,CSyncClientCall,ForwardedBases<StandardComClientCall,ICancelMethodCalls> > >,ForwardedBases<StandardComClientCall,ICancelMethodCalls> >
		{
			struct AddTypeIdLayerHelper<AddAllocation<AllocationOptions<InheritBaseAllocator,12,Nil>,CSyncClientCall,AddComReferenceCounting<ComReferenceCountingOptions<0>,CSyncClientCall,ForwardedBases<StandardComClientCall,ICancelMethodCalls> > >,PolymorphicType<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,Nil> >
			{
				virtual PolymorphicTypeIdHelper<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,MixinBase<CBaseCall,Mixins_NilBaseForwarderLayer> >::WhichType GetTypeId(PolymorphicTypeIdHelper<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,MixinBase<CBaseCall,Mixins_NilBaseForwarderLayer> > const *);
			};

		};

		namespace AddTypeIdentityLayersBuilder<WinrtAsyncChannelOperation,AddAllocation<AllocationOptions<InheritBaseAllocator,0,Nil>,WinrtAsyncChannelOperation,AddComReferenceCounting<ComReferenceCountingOptions<17>,WinrtAsyncChannelOperation,ForwardedBases<WinrtAsyncChannelOperationEntry,Dcomrem::Async::AsyncBaseStateMachine<WinrtAsyncChannelOperation,2,AsyncDelegateStorage,AsyncDelegateStorage>,IWinrtAsyncChannelOperation,IAsyncClientTransport,IClientTransportCallEvents,IServerTransportCallEvents> > >,ForwardedBases<WinrtAsyncChannelOperationEntry,Dcomrem::Async::AsyncBaseStateMachine<WinrtAsyncChannelOperation,2,AsyncDelegateStorage,AsyncDelegateStorage>,IWinrtAsyncChannelOperation,IAsyncClientTransport,IClientTransportCallEvents,IServerTransportCallEvents> >
		{
			struct AddTypeIdLayerHelper<AddAllocation<AllocationOptions<InheritBaseAllocator,0,Nil>,WinrtAsyncChannelOperation,AddComReferenceCounting<ComReferenceCountingOptions<17>,WinrtAsyncChannelOperation,ForwardedBases<WinrtAsyncChannelOperationEntry,Dcomrem::Async::AsyncBaseStateMachine<WinrtAsyncChannelOperation,2,AsyncDelegateStorage,AsyncDelegateStorage>,IWinrtAsyncChannelOperation,IAsyncClientTransport,IClientTransportCallEvents,IServerTransportCallEvents> > >,PolymorphicType<OneOf<WinrtAsyncChannelOperationPlaceholder,WinrtAsyncChannelOperation>,WinrtAsyncChannelOperationEntry,AddAllocation<AllocationOptions<PrivMemAllocator,0,Nil>,WinrtAsyncChannelOperationEntry,AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncChannelOperationEntry,ContainedBy<ContainmentSpecification<WinrtAsyncChannelOperationMap,WinrtAsyncChannelOperationEntry,ContainerKind::OrderedMap,1>,WinrtAsyncChannelOperationEntry,Nil> > > > >
			{
				virtual PolymorphicTypeIdHelper<OneOf<WinrtAsyncChannelOperationPlaceholder,WinrtAsyncChannelOperation>,WinrtAsyncChannelOperationEntry,AddAllocation<AllocationOptions<PrivMemAllocator,0,Nil>,WinrtAsyncChannelOperationEntry,AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncChannelOperationEntry,ContainedBy<ContainmentSpecification<WinrtAsyncChannelOperationMap,WinrtAsyncChannelOperationEntry,ContainerKind::OrderedMap,1>,WinrtAsyncChannelOperationEntry,Nil> > > >::WhichType GetTypeId(PolymorphicTypeIdHelper<OneOf<WinrtAsyncChannelOperationPlaceholder,WinrtAsyncChannelOperation>,WinrtAsyncChannelOperationEntry,AddAllocation<AllocationOptions<PrivMemAllocator,0,Nil>,WinrtAsyncChannelOperationEntry,AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncChannelOperationEntry,ContainedBy<ContainmentSpecification<WinrtAsyncChannelOperationMap,WinrtAsyncChannelOperationEntry,ContainerKind::OrderedMap,1>,WinrtAsyncChannelOperationEntry,Nil> > > > const *);
			};

		};

		namespace AddTypeIdentityLayersBuilder<WinrtAsyncClientCall,AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncClientCall,ForwardedBases<LegacyFreeSyncClientCall,IWinrtAsyncClientCall> >,ForwardedBases<LegacyFreeSyncClientCall,IWinrtAsyncClientCall> >
		{
			struct AddTypeIdLayerHelper<AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncClientCall,ForwardedBases<LegacyFreeSyncClientCall,IWinrtAsyncClientCall> >,PolymorphicType<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,Nil> >
			{
				virtual PolymorphicTypeIdHelper<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,MixinBase<CBaseCall,Mixins_NilBaseForwarderLayer> >::WhichType GetTypeId(PolymorphicTypeIdHelper<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,MixinBase<CBaseCall,Mixins_NilBaseForwarderLayer> > const *);
			};

		};

		namespace AddTypeIdentityLayersBuilder<WinrtAsyncServerCall,AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncServerCall,ForwardedBases<LegacyFreeSyncServerCall,IWinrtAsyncServerCall> >,ForwardedBases<LegacyFreeSyncServerCall,IWinrtAsyncServerCall> >
		{
			struct AddTypeIdLayerHelper<AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncServerCall,ForwardedBases<LegacyFreeSyncServerCall,IWinrtAsyncServerCall> >,PolymorphicType<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,Nil> >
			{
				virtual PolymorphicTypeIdHelper<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,MixinBase<CBaseCall,Mixins_NilBaseForwarderLayer> >::WhichType GetTypeId(PolymorphicTypeIdHelper<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,MixinBase<CBaseCall,Mixins_NilBaseForwarderLayer> > const *);
			};

		};

		class Allocation_StandardDeleteSelfLayer<Nil,MixinBase<Nil,Mixins_NilBaseForwarderLayer> >
		{
		protected:
			void DeleteSelf();
		};

		class ContainerOf_MruCacheImplementationLayer<MruCacheImplementationOptions<RegistrationChangeDetection::PerUserCacheInformation,5>,RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_LockingLayer<RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<RegistrationChangeDetection::PerUserCacheInformation,0>,RegistrationChangeDetection::PerUserCacheInformationCache,MixinBase<RegistrationChangeDetection::PerUserCacheInformationCache,Mixins_NilBaseForwarderLayer> > > >
		{
			ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation> AddEntry(ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation>);
		public:
			ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation> Find<LockableHelper<RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_MruCacheImplementationLayer<MruCacheImplementationOptions<RegistrationChangeDetection::PerUserCacheInformation,5>,RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_LockingLayer<RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<RegistrationChangeDetection::PerUserCacheInformation,0>,RegistrationChangeDetection::PerUserCacheInformationCache,MixinBase<RegistrationChangeDetection::PerUserCacheInformationCache,Mixins_NilBaseForwarderLayer> > > > >::LockWrapper,RegistrationChangeDetection::ComparableSid>(LockableHelper<RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_MruCacheImplementationLayer<MruCacheImplementationOptions<RegistrationChangeDetection::PerUserCacheInformation,5>,RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_LockingLayer<RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<RegistrationChangeDetection::PerUserCacheInformation,0>,RegistrationChangeDetection::PerUserCacheInformationCache,MixinBase<RegistrationChangeDetection::PerUserCacheInformationCache,Mixins_NilBaseForwarderLayer> > > > >::LockWrapper const &,RegistrationChangeDetection::ComparableSid const &,void *);
			ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation> Find<RegistrationChangeDetection::ComparableSid>(RegistrationChangeDetection::ComparableSid const &,void *);
			void Remove<LockableHelper<RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_MruCacheImplementationLayer<MruCacheImplementationOptions<RegistrationChangeDetection::PerUserCacheInformation,5>,RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_LockingLayer<RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<RegistrationChangeDetection::PerUserCacheInformation,0>,RegistrationChangeDetection::PerUserCacheInformationCache,MixinBase<RegistrationChangeDetection::PerUserCacheInformationCache,Mixins_NilBaseForwarderLayer> > > > >::LockWrapper>(LockableHelper<RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_MruCacheImplementationLayer<MruCacheImplementationOptions<RegistrationChangeDetection::PerUserCacheInformation,5>,RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_LockingLayer<RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<RegistrationChangeDetection::PerUserCacheInformation,0>,RegistrationChangeDetection::PerUserCacheInformationCache,MixinBase<RegistrationChangeDetection::PerUserCacheInformationCache,Mixins_NilBaseForwarderLayer> > > > >::LockWrapper const &,RegistrationChangeDetection::PerUserCacheInformation &,void *);
			void Remove<RegistrationChangeDetection::PerUserCacheInformation>(RegistrationChangeDetection::PerUserCacheInformation &,void *);
		};

		class ContainerOf_MruCacheImplementationLayer<MruCacheImplementationOptions<WinrtAsyncProxyMethodInfo,10>,WinrtAsyncProxyMethodInfoCache,ContainerOf_LockingLayer<WinrtAsyncProxyMethodInfoCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<WinrtAsyncProxyMethodInfo,0>,WinrtAsyncProxyMethodInfoCache,MixinBase<WinrtAsyncProxyMethodInfoCache,Mixins_NilBaseForwarderLayer> > > >
		{
			ReferencedPtr<WinrtAsyncProxyMethodInfo> AddEntry(ReferencedPtr<WinrtAsyncProxyMethodInfo>);
		public:
			ReferencedPtr<WinrtAsyncProxyMethodInfo> Find<LockableHelper<WinrtAsyncProxyMethodInfoCache,ContainerOf_MruCacheImplementationLayer<MruCacheImplementationOptions<WinrtAsyncProxyMethodInfo,10>,WinrtAsyncProxyMethodInfoCache,ContainerOf_LockingLayer<WinrtAsyncProxyMethodInfoCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<WinrtAsyncProxyMethodInfo,0>,WinrtAsyncProxyMethodInfoCache,MixinBase<WinrtAsyncProxyMethodInfoCache,Mixins_NilBaseForwarderLayer> > > > >::LockWrapper,std::pair<_GUID,unsigned short> >(LockableHelper<WinrtAsyncProxyMethodInfoCache,ContainerOf_MruCacheImplementationLayer<MruCacheImplementationOptions<WinrtAsyncProxyMethodInfo,10>,WinrtAsyncProxyMethodInfoCache,ContainerOf_LockingLayer<WinrtAsyncProxyMethodInfoCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<WinrtAsyncProxyMethodInfo,0>,WinrtAsyncProxyMethodInfoCache,MixinBase<WinrtAsyncProxyMethodInfoCache,Mixins_NilBaseForwarderLayer> > > > >::LockWrapper const &,std::pair<_GUID,unsigned short> const &,void *);
			ReferencedPtr<WinrtAsyncProxyMethodInfo> Find<std::pair<_GUID,unsigned short> >(std::pair<_GUID,unsigned short> const &,void *);
		};

		class ContainerOf_SplayTreeImplementationLayer<RegistrationStoreData::PackageDataCacheEntry,RegistrationStoreData::PackageDataCache,ContainerOf_LockingLayer<RegistrationStoreData::PackageDataCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<RegistrationStoreData::PackageDataCacheEntry,0>,RegistrationStoreData::PackageDataCache,MixinBase<RegistrationStoreData::PackageDataCache,Mixins_NilBaseForwarderLayer> > > >
		{
			ContainerOf_SplayTreeImplementationLayer<RegistrationStoreData::PackageDataCacheEntry,RegistrationStoreData::PackageDataCache,ContainerOf_LockingLayer<RegistrationStoreData::PackageDataCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<RegistrationStoreData::PackageDataCacheEntry,0>,RegistrationStoreData::PackageDataCache,MixinBase<RegistrationStoreData::PackageDataCache,Mixins_NilBaseForwarderLayer> > > >::Position FindPosition<OpaqueString>(OpaqueString const &,void *);
			void InsertAtPosition(ReferencedPtr<RegistrationStoreData::PackageDataCacheEntry> const &,ContainerOf_SplayTreeImplementationLayer<RegistrationStoreData::PackageDataCacheEntry,RegistrationStoreData::PackageDataCache,ContainerOf_LockingLayer<RegistrationStoreData::PackageDataCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<RegistrationStoreData::PackageDataCacheEntry,0>,RegistrationStoreData::PackageDataCache,MixinBase<RegistrationStoreData::PackageDataCache,Mixins_NilBaseForwarderLayer> > > >::Position const &);
		};

		class ContainerOf_SplayTreeImplementationLayer<StackTrace,StackTraceDetails::GlobalStackTraceMap,ContainerOf_LockingLayer<StackTraceDetails::GlobalStackTraceMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<StackTrace,1>,StackTraceDetails::GlobalStackTraceMap,MixinBase<StackTraceDetails::GlobalStackTraceMap,Mixins_NilBaseForwarderLayer> > > >
		{
			ContainerOf_SplayTreeImplementationLayer<StackTrace,StackTraceDetails::GlobalStackTraceMap,ContainerOf_LockingLayer<StackTraceDetails::GlobalStackTraceMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<StackTrace,1>,StackTraceDetails::GlobalStackTraceMap,MixinBase<StackTraceDetails::GlobalStackTraceMap,Mixins_NilBaseForwarderLayer> > > >::Position FindPosition<StackTrace::ComparisonData>(StackTrace::ComparisonData const &,void *);
			void InsertAtPosition(ReferencedPtr<StackTrace> const &,ContainerOf_SplayTreeImplementationLayer<StackTrace,StackTraceDetails::GlobalStackTraceMap,ContainerOf_LockingLayer<StackTraceDetails::GlobalStackTraceMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<StackTrace,1>,StackTraceDetails::GlobalStackTraceMap,MixinBase<StackTraceDetails::GlobalStackTraceMap,Mixins_NilBaseForwarderLayer> > > >::Position const &);
		};

		class ContainerOf_SplayTreeImplementationLayer<WinrtAsyncChannelOperationEntry,WinrtAsyncChannelOperationMap,ContainerOf_LockingLayer<WinrtAsyncChannelOperationMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<WinrtAsyncChannelOperationEntry,1>,WinrtAsyncChannelOperationMap,MixinBase<WinrtAsyncChannelOperationMap,Mixins_NilBaseForwarderLayer> > > >
		{
			ContainerOf_SplayTreeImplementationLayer<WinrtAsyncChannelOperationEntry,WinrtAsyncChannelOperationMap,ContainerOf_LockingLayer<WinrtAsyncChannelOperationMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<WinrtAsyncChannelOperationEntry,1>,WinrtAsyncChannelOperationMap,MixinBase<WinrtAsyncChannelOperationMap,Mixins_NilBaseForwarderLayer> > > >::Position FindPosition<Guid>(Guid const &,void *);
			void InsertAtPosition(ReferencedPtr<WinrtAsyncChannelOperationEntry> const &,ContainerOf_SplayTreeImplementationLayer<WinrtAsyncChannelOperationEntry,WinrtAsyncChannelOperationMap,ContainerOf_LockingLayer<WinrtAsyncChannelOperationMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<WinrtAsyncChannelOperationEntry,1>,WinrtAsyncChannelOperationMap,MixinBase<WinrtAsyncChannelOperationMap,Mixins_NilBaseForwarderLayer> > > >::Position const &);
		public:
			ReferencedPtr<WinrtAsyncChannelOperationEntry> Find<_GUID>(_GUID const &,void *);
			void Remove<LockableHelper<WinrtAsyncChannelOperationMap,ContainerOf_SplayTreeImplementationLayer<WinrtAsyncChannelOperationEntry,WinrtAsyncChannelOperationMap,ContainerOf_LockingLayer<WinrtAsyncChannelOperationMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<WinrtAsyncChannelOperationEntry,1>,WinrtAsyncChannelOperationMap,MixinBase<WinrtAsyncChannelOperationMap,Mixins_NilBaseForwarderLayer> > > > >::LockWrapper>(LockableHelper<WinrtAsyncChannelOperationMap,ContainerOf_SplayTreeImplementationLayer<WinrtAsyncChannelOperationEntry,WinrtAsyncChannelOperationMap,ContainerOf_LockingLayer<WinrtAsyncChannelOperationMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<WinrtAsyncChannelOperationEntry,1>,WinrtAsyncChannelOperationMap,MixinBase<WinrtAsyncChannelOperationMap,Mixins_NilBaseForwarderLayer> > > > >::LockWrapper const &,WinrtAsyncChannelOperationEntry &,void *);
		};

		struct LockableHelper<Nil,AddAllocation<AllocationOptions<PrivMemAllocator,0,Nil>,Nil,Nil> >
		{
			struct LockWrapper
			{
				~LockWrapper();
			};

			LockWrapper LockableHelper<Nil,AddAllocation<AllocationOptions<PrivMemAllocator,0,Nil>,Nil,Nil> >::Lock();
		};

		namespace LockableHelper<RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_MruCacheImplementationLayer<MruCacheImplementationOptions<RegistrationChangeDetection::PerUserCacheInformation,5>,RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_LockingLayer<RegistrationChangeDetection::PerUserCacheInformationCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<RegistrationChangeDetection::PerUserCacheInformation,0>,RegistrationChangeDetection::PerUserCacheInformationCache,MixinBase<RegistrationChangeDetection::PerUserCacheInformationCache,Mixins_NilBaseForwarderLayer> > > > >
		{
			struct LockWrapper
			{
				~LockWrapper();
			};

		};

		namespace LockableHelper<RegistrationStoreData::PackageDataCache,ContainerOf_SplayTreeImplementationLayer<RegistrationStoreData::PackageDataCacheEntry,RegistrationStoreData::PackageDataCache,ContainerOf_LockingLayer<RegistrationStoreData::PackageDataCache,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<RegistrationStoreData::PackageDataCacheEntry,0>,RegistrationStoreData::PackageDataCache,MixinBase<RegistrationStoreData::PackageDataCache,Mixins_NilBaseForwarderLayer> > > > >
		{
			struct LockWrapper
			{
				~LockWrapper();
			};

		};

		struct LockableHelper<StackTraceDetails::GlobalStackTraceMap,ContainerOf_SplayTreeImplementationLayer<StackTrace,StackTraceDetails::GlobalStackTraceMap,ContainerOf_LockingLayer<StackTraceDetails::GlobalStackTraceMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<StackTrace,1>,StackTraceDetails::GlobalStackTraceMap,MixinBase<StackTraceDetails::GlobalStackTraceMap,Mixins_NilBaseForwarderLayer> > > > >
		{
			struct LockWrapper
			{
				~LockWrapper();
			};

			LockWrapper LockableHelper<StackTraceDetails::GlobalStackTraceMap,ContainerOf_SplayTreeImplementationLayer<StackTrace,StackTraceDetails::GlobalStackTraceMap,ContainerOf_LockingLayer<StackTraceDetails::GlobalStackTraceMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<StackTrace,1>,StackTraceDetails::GlobalStackTraceMap,MixinBase<StackTraceDetails::GlobalStackTraceMap,Mixins_NilBaseForwarderLayer> > > > >::Lock();
		};

		struct LockableHelper<WinrtAsyncChannelOperationMap,ContainerOf_SplayTreeImplementationLayer<WinrtAsyncChannelOperationEntry,WinrtAsyncChannelOperationMap,ContainerOf_LockingLayer<WinrtAsyncChannelOperationMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<WinrtAsyncChannelOperationEntry,1>,WinrtAsyncChannelOperationMap,MixinBase<WinrtAsyncChannelOperationMap,Mixins_NilBaseForwarderLayer> > > > >
		{
			struct LockWrapper
			{
				~LockWrapper();
			};

			LockWrapper LockableHelper<WinrtAsyncChannelOperationMap,ContainerOf_SplayTreeImplementationLayer<WinrtAsyncChannelOperationEntry,WinrtAsyncChannelOperationMap,ContainerOf_LockingLayer<WinrtAsyncChannelOperationMap,ContainerOf_ReferencesToElementsLayer<ReferencesToElementsOptions<WinrtAsyncChannelOperationEntry,1>,WinrtAsyncChannelOperationMap,MixinBase<WinrtAsyncChannelOperationMap,Mixins_NilBaseForwarderLayer> > > > >::Lock();
		};

		struct LockableHelper<WinrtAsyncProxyCall,MixinBase<WinrtAsyncProxyCall,Mixins_BaseForwarderLayer<ForwardedBases<Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<2>,Microsoft::WRL::ChainInterfaces<IRpcChannelBuffer3,IRpcChannelBuffer2,IRpcChannelBuffer,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil>,IRpcChannelBufferMarshalingContext>,IWinrtAsyncClientRpcOleMessageCallProxyCallbacks,IWinrtAsyncProxyCall,IReturnObjectContainer,IStubCall> > > >
		{
			LockWrapper LockableHelper<WinrtAsyncProxyCall,MixinBase<WinrtAsyncProxyCall,Mixins_BaseForwarderLayer<ForwardedBases<Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<2>,Microsoft::WRL::ChainInterfaces<IRpcChannelBuffer3,IRpcChannelBuffer2,IRpcChannelBuffer,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil>,IRpcChannelBufferMarshalingContext>,IWinrtAsyncClientRpcOleMessageCallProxyCallbacks,IWinrtAsyncProxyCall,IReturnObjectContainer,IStubCall> > > >::Lock();
		};

		class Mixins_BaseForwarderLayer<ForwardedBases<Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<2>,Microsoft::WRL::ChainInterfaces<IRpcChannelBuffer3,IRpcChannelBuffer2,IRpcChannelBuffer,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil>,IRpcChannelBufferMarshalingContext>,IWinrtAsyncClientRpcOleMessageCallProxyCallbacks,IWinrtAsyncProxyCall,IReturnObjectContainer,IStubCall> >
		{
		protected:
			Mixins_BaseForwarderLayer<ForwardedBases<Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<2>,Microsoft::WRL::ChainInterfaces<IRpcChannelBuffer3,IRpcChannelBuffer2,IRpcChannelBuffer,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil,Microsoft::WRL::Details::Nil>,IRpcChannelBufferMarshalingContext>,IWinrtAsyncClientRpcOleMessageCallProxyCallbacks,IWinrtAsyncProxyCall,IReturnObjectContainer,IStubCall> >();
		};

		struct ReferencedPtrRef<ReferencedPtr<WinRT::Metadata::Marshaling::TypeInformation> >
		{
			operator ReferencedPtr<WinRT::Metadata::Marshaling::TypeInformation> *();
		};

		void LogicalError(long,void const *);
	};

	class IComReferenceCounting
	{
		virtual void Dummy();
	};

	class Object<ObjectOptions<ComReferenceCountingOptions<4>,AllocationOptions<PrivMemAllocator,368,Details::Nil>,ObjectNoPolymorphism,DebuggingOptions<0>,ObjectNoAssociations>,ServerCall,ForwardedBases<CBaseCall,IMessageParam,IServerCall> >
	{
	protected:
		Object<ObjectOptions<ComReferenceCountingOptions<4>,AllocationOptions<PrivMemAllocator,368,Details::Nil>,ObjectNoPolymorphism,DebuggingOptions<0>,ObjectNoAssociations>,ServerCall,ForwardedBases<CBaseCall,IMessageParam,IServerCall> >();
	};

	class Object<ObjectOptions<ComReferenceCountingOptions<8>,AllocationOptions<NoAllocator,2,Details::Nil>,ObjectNoPolymorphism,ObjectNoDebugging,ObjectNoAssociations>,CDllHost,ForwardedBases<IDLLHost,IMessageParam> >
	{
	protected:
		Object<ObjectOptions<ComReferenceCountingOptions<8>,AllocationOptions<NoAllocator,2,Details::Nil>,ObjectNoPolymorphism,ObjectNoDebugging,ObjectNoAssociations>,CDllHost,ForwardedBases<IDLLHost,IMessageParam> >();
	};

	class Object<ObjectOptions<ObjectNoComReferenceCounting,ObjectNoAllocation,ObjectNoPolymorphism,ObjectNoDebugging,ObjectNoAssociations>,CCtxCall,ForwardedBases<CBaseCall,ICallFrameWalker,IServerCall> >
	{
	protected:
		Object<ObjectOptions<ObjectNoComReferenceCounting,ObjectNoAllocation,ObjectNoPolymorphism,ObjectNoDebugging,ObjectNoAssociations>,CCtxCall,ForwardedBases<CBaseCall,ICallFrameWalker,IServerCall> >();
	};

	struct OpaqueString
	{
		OpaqueString & operator=(OpaqueString const &);
		OpaqueString(OpaqueString const &);
		long Append(HSTRING__ *);
	};

	struct PolymorphicType<OneOf<CAsyncCall,CClientCall>,CMessageCall,AddAllocation<AllocationOptions<PrivMemAllocator,368,Details::Nil>,CMessageCall,AddComReferenceCounting<ComReferenceCountingOptions<4>,CMessageCall,Details::Nil> > >
	{
		CAsyncCall * CheckedAs<CAsyncCall>();
		bool Is<CAsyncCall>();
	};

	struct PolymorphicType<OneOf<CCtxCall,CSyncClientCall,AsyncComClientCall,WinrtAsyncClientCall,SyncServerCall,AsyncComServerCall,WinrtAsyncServerCall>,CBaseCall,Details::Nil>
	{
		CCtxCall * CheckedAs<CCtxCall>();
		bool Is<ClientCall>();
		bool Is<ServerCall>();
	};

	struct PolymorphicType<OneOf<WinRT::Metadata::Marshaling::MetadataUnknown,WinRT::Metadata::Marshaling::MetadataBaseType,WinRT::Metadata::Marshaling::MetadataRange,WinRT::Metadata::Marshaling::MetadataInterface,WinRT::Metadata::Marshaling::MetadataStruct,WinRT::Metadata::Marshaling::MetadataGuid,WinRT::Metadata::Marshaling::MetadataEnum,WinRT::Metadata::Marshaling::MetadataClass,WinRT::Metadata::Marshaling::MetadataDelegate,WinRT::Metadata::Marshaling::MetadataPInterface,WinRT::Metadata::Marshaling::MetadataPInterfaceInstance,WinRT::Metadata::Marshaling::MetadataPointer,WinRT::Metadata::Marshaling::MetadataArray>,WinRT::Metadata::Marshaling::MetadataType,AddAllocation<AllocationOptions<WinRT::Metadata::Marshaling::MetadataTypeAllocator,0,Details::Nil>,WinRT::Metadata::Marshaling::MetadataType,AddComReferenceCounting<ComReferenceCountingOptions<0>,WinRT::Metadata::Marshaling::MetadataType,Details::Nil> > >
	{
		WinRT::Metadata::Marshaling::MetadataArray * CheckedAs<WinRT::Metadata::Marshaling::MetadataArray>();
		WinRT::Metadata::Marshaling::MetadataBaseType * CheckedAs<WinRT::Metadata::Marshaling::MetadataBaseType>();
		WinRT::Metadata::Marshaling::MetadataClass * CheckedAs<WinRT::Metadata::Marshaling::MetadataClass>();
		WinRT::Metadata::Marshaling::MetadataInterfaceBase * CheckedAs<WinRT::Metadata::Marshaling::MetadataInterfaceBase>();
		WinRT::Metadata::Marshaling::MetadataPInterface * As<WinRT::Metadata::Marshaling::MetadataPInterface>();
		WinRT::Metadata::Marshaling::MetadataPInterfaceInstance * CheckedAs<WinRT::Metadata::Marshaling::MetadataPInterfaceInstance>();
		WinRT::Metadata::Marshaling::MetadataPointer * CheckedAs<WinRT::Metadata::Marshaling::MetadataPointer>();
		WinRT::Metadata::Marshaling::MetadataRange * CheckedAs<WinRT::Metadata::Marshaling::MetadataRange>();
		bool Is<WinRT::Metadata::Marshaling::MetadataArray>();
		bool Is<WinRT::Metadata::Marshaling::MetadataInterfaceBase>();
		bool Is<WinRT::Metadata::Marshaling::MetadataPInterface>();
	};

	struct PolymorphicType<OneOf<WinrtAsyncChannelOperationPlaceholder,WinrtAsyncChannelOperation>,WinrtAsyncChannelOperationEntry,AddAllocation<AllocationOptions<PrivMemAllocator,0,Details::Nil>,WinrtAsyncChannelOperationEntry,AddComReferenceCounting<ComReferenceCountingOptions<0>,WinrtAsyncChannelOperationEntry,ContainedBy<ContainmentSpecification<WinrtAsyncChannelOperationMap,WinrtAsyncChannelOperationEntry,ContainerKind::OrderedMap,1>,WinrtAsyncChannelOperationEntry,Details::Nil> > > >
	{
		bool Is<WinrtAsyncChannelOperation>();
	};

	struct ReferencedPtr<ArrayOfGuids>
	{
		ReferencedPtr<ArrayOfGuids>(ReferencedPtr<ArrayOfGuids> const &);
	};

	class ReferencedPtr<CAsyncCall>
	{
		void InternalRelease();
	public:
		void Attach(CAsyncCall *);
	};

	class ReferencedPtr<CChannelHandle>
	{
		void InternalRelease();
	};

	class ReferencedPtr<CComApartment>
	{
		void InternalRelease();
	};

	class ReferencedPtr<CMessageCall>
	{
		void InternalAddRef();
		void InternalRelease();
	public:
		ReferencedPtr<CMessageCall> & operator=(ReferencedPtr<CMessageCall> const &);
	};

	class ReferencedPtr<CObjectContext>
	{
		void InternalAddRef();
	public:
		ReferencedPtr<CObjectContext> & operator=(ReferencedPtr<CObjectContext> const &);
		ReferencedPtr<CObjectContext>(ReferencedPtr<CObjectContext> const &);
	};

	struct ReferencedPtr<ClientCall>
	{
		ReferencedPtr<ClientCall><ClientCall>(ClientCall *);
		void Attach(ClientCall *);
	};

	struct ReferencedPtr<ComCallTraceActivity>
	{
		void Attach(ComCallTraceActivity *);
	};

	class ReferencedPtr<IAgileReference>
	{
		void InternalAddRef();
	};

	struct ReferencedPtr<IMessageParam>
	{
		void Attach(IMessageParam *);
	};

	class ReferencedPtr<IWinrtAsyncChannelOperation>
	{
		void InternalAddRef();
	public:
		ReferencedPtr<IWinrtAsyncChannelOperation>(ReferencedPtr<IWinrtAsyncChannelOperation> const &);
	};

	struct ReferencedPtr<OutParameterMarshalingServer>
	{
		void Attach(OutParameterMarshalingServer *);
	};

	class ReferencedPtr<PreventRundownBiasContainer>
	{
		void InternalRelease();
	public:
		ReferencedPtr<PreventRundownBiasContainer>(ReferencedPtr<PreventRundownBiasContainer> const &);
	};

	struct ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation>
	{
		ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation>();
		~ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation>();
	};

	class ReferencedPtr<ServerCall>
	{
		void InternalAddRef();
		void InternalRelease();
	public:
		ReferencedPtr<ServerCall> & operator=(ReferencedPtr<ServerCall> const &);
		void Attach(ServerCall *);
	};

	struct ReferencedPtr<WinRT::Metadata::Marshaling::MetadataPInterfaceInstance>
	{
		void Attach(WinRT::Metadata::Marshaling::MetadataPInterfaceInstance *);
	};

	struct ReferencedPtr<WinRT::Metadata::Marshaling::MetadataType>
	{
		ReferencedPtr<WinRT::Metadata::Marshaling::MetadataType> & operator=(ReferencedPtr<WinRT::Metadata::Marshaling::MetadataType> const &);
		void Attach(WinRT::Metadata::Marshaling::MetadataType *);
	};

	class ReferencedPtr<WinRT::Metadata::Marshaling::TypeCache>
	{
		void InternalRelease();
	};

	struct ReferencedPtr<WinRT::Metadata::Marshaling::TypeResolver>
	{
		~ReferencedPtr<WinRT::Metadata::Marshaling::TypeResolver>();
	};

	struct ReferencedPtr<WinrtAsyncChannelMessage>
	{
		ReferencedPtr<WinrtAsyncChannelMessage><WinrtAsyncChannelMessage>(WinrtAsyncChannelMessage *);
	};

	struct ReferencedPtr<WinrtAsyncProxyMethodInfo>
	{
		ReferencedPtr<WinrtAsyncProxyMethodInfo>();
		~ReferencedPtr<WinrtAsyncProxyMethodInfo>();
	};

	class ReferencedPtr<WinrtAsyncResponse>
	{
		void InternalAddRef();
		void InternalRelease();
	};

	struct ReferencedPtr<WinrtAsyncServerContinuationMessage>
	{
		void Attach(WinrtAsyncServerContinuationMessage *);
	};

	struct SplayLinks
	{
		void DeleteNoSplay(SplayLinks * *);
	};

};

struct OpaqueDataInfo
{
	long CopyOpaqueData(tagOpaqueData *,tagOpaqueData *,unsigned long,int);
	virtual long AddOpaqueData(tagOpaqueData *);
	virtual long DeleteOpaqueData(_GUID const &);
	virtual long GetAllOpaqueData(tagOpaqueData * *);
	virtual long GetCLSID(_GUID *);
	virtual long GetOpaqueData(_GUID const &,tagOpaqueData * *);
	virtual long GetOpaqueDataCount(unsigned long *);
	virtual long GetSize(void *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long SetParent(ISerializableParent *);
	virtual long UnSerialize(void *);
	virtual long UnSerializeCallBack(_GUID const &,ISerializable * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct OpaqueString
{
	OpaqueString & operator=(OpaqueString const &);
	OpaqueString(OpaqueString const &);
	~OpaqueString();
};

struct Optional<OpaqueString>
{
	OpaqueString GetValueOrDefault(OpaqueString const &);
};

class OutParameterMarshalingClient
{
	long Initialize();
	static Microsoft::WRL::ComPtr<OutParameterMarshalingClient> FindInTable(unsigned long);
	static Microsoft::WRL::ComPtr<OutParameterMarshalingClient> GetTableRoot();
	static Microsoft::WRL::Wrappers::SRWLock s_lockTable;
	static _RTL_SPLAY_LINKS * s_pTableRoot;
	static void ClientDisconnectedWaitCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_WAIT *,long);
	static void InsertInTable(OutParameterMarshalingClient *);
	static void RemoveFromTable(OutParameterMarshalingClient *);
	void CancelOutstandingWaitCallback();
	void RemoveAllSets();
	void RunDown();
public:
	OutParameterMarshalingClient(unsigned long,CachedEvent &);
	bool AddSetToList(OutParameterMarshalingSet *);
	long ReceiveAcknowledgmentOfSets(void *,unsigned short,unsigned __int64 *);
	static long FindExisting(void *,OutParameterMarshalingClient * *);
	static long FindOrCreate(void *,OutParameterMarshalingClient * *);
};

class OutParameterMarshalingServer
{
	OutParameterMarshalingServer(OXIDEntry *);
	bool GrowSetsArray(unsigned __int64);
	static Microsoft::WRL::Wrappers::SRWLock s_lockTable;
	static ObjectLibrary::ReferencedPtr<OutParameterMarshalingServer> GetTableRoot();
	static WaitableCount s_cExecutingCallbacks;
	static _RTL_SPLAY_LINKS * s_pTableRoot;
	static void AcknowledgeMarshalingSetsTimerCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *);
	static void AcknowledgeMarshalingSetsWorkCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_WORK *);
	static void RemoveFromTable(OutParameterMarshalingServer *);
	void CancelOutstandingTimerCallback();
	void TryAcknowledgmentCall(OutParameterMarshalingServer::AcknowledgmentCallPath);
	void TryToScheduleAcknowledgment(unsigned __int64);
public:
	static ObjectLibrary::ReferencedPtr<OutParameterMarshalingServer> FindOrCreate(OXIDEntry *);
	static void CleanupAll();
	void TryToAddSetAndScheduleAcknowledgment(unsigned __int64);
};

class OutParameterMarshalingSet
{
	static unsigned __int64 volatile s_lastId;
public:
	OutParameterMarshalingSet(Microsoft::WRL::ComPtr<OutParameterMarshalingClient> const &);
	virtual void HandleSuccessfulSend();
};

struct PARAMINFO
{
	PARAMINFO();
	~PARAMINFO();
};

struct POSTRELRIFREF
{
	POSTRELRIFREF();
};

struct PackageIdAndInstallOrder
{
	PackageIdAndInstallOrder();
	~PackageIdAndInstallOrder();
};

class PackageListBuffer
{
	long GrowDynamicBuffer();
public:
	PackageIdAndInstallOrder * RemoveAt(PackageIdAndInstallOrder *);
	PackageListBuffer();
	long AddPackage(OpaqueString const &,unsigned int);
	long Clone(PackageListBuffer &);
	void Reset();
	~PackageListBuffer();
};

struct PreventRundownBiasContainer
{
	PreventRundownBiasContainer();
	long AddStubBias(CStdIdentity *);
	virtual void HandleSuccessfulSend();
	virtual ~PreventRundownBiasContainer();
	void RemoveAllBiases();
};

struct PrivHiveHKEYCache
{
	PrivHiveHKEYCache();
	void CleanUp();
	~PrivHiveHKEYCache();
};

struct ProcessIdentity
{
	ProcessIdentity();
	long GetApplicationUserModelId(unsigned int,unsigned short *);
	long GetPackageFamilyName(unsigned int,unsigned short *);
	~ProcessIdentity();
};

struct ProcessToken
{
	AppModelPolicy_PolicyValue GetAppModelPolicyValue(AppModelPolicy_Type);
	ProcessToken();
	bool CanProcessBeSuspendedByAnyLifecycleManager();
	bool IsAppContainer();
	bool IsILLessThanMedium();
	bool IsNoAllApplicationPackagesAttributePresent();
	bool IsSysAppIdAttributePresent();
	bool IsUserHiveOk();
	long ComputeDesignModeState();
	long GetPackageMoniker(unsigned short * *);
	long GetPackageSid(void * *);
	long GetProcessToken(void * *,unsigned long);
	long GetSelfSid(void * *);
	long GetStringPackageSid(unsigned short * *);
	long GetStringSelfSid(unsigned short * *);
	long IsInDesignModeV2(bool *);
	~ProcessToken();
};

struct PushComCallTraceActivity
{
	PushComCallTraceActivity(ComCallTraceActivity *);
};

struct PushComCalloutTraceActivity
{
	PushComCalloutTraceActivity(_GUID const &);
};

struct PushLogicalThreadId
{
	PushLogicalThreadId(_GUID const &,bool);
	~PushLogicalThreadId();
};

struct PushTlsPreventRundownMitigation
{
	long Complete();
	void Push(OLETLS_PREVENT_RUNDOWN_MITIGATION);
};

class Quirks
{
	static Quirks::QuirkStatus s_allowAstaToAstaCalls;
	static Quirks::QuirkStatus s_disableThresholdAppLaunchPerfFeature;
	static Quirks::QuirkStatus s_disableWinrtAsyncChannel;
	static Quirks::QuirkStatus s_dropOrReorderInputInAsta;
	static bool IsQuirkEnabled(Quirks::QuirkStatus *,unsigned long);
};

namespace RegistrationChangeDetection
{
	struct NotificationChecker
	{
		long RegisterNotification(ObjectLibrary::Details::LockableHelper<ObjectLibrary::Details::Nil,ObjectLibrary::AddAllocation<ObjectLibrary::AllocationOptions<PrivMemAllocator,0,ObjectLibrary::Details::Nil>,ObjectLibrary::Details::Nil,ObjectLibrary::Details::Nil> >::LockWrapper const &);
	};

	class PerUserCacheInformation
	{
		long CheckForNoHive(IUserTokenInternal *);
		long CheckForRefresh(IUserToken *,bool *);
	public:
		PerUserCacheInformation(void *);
		long EnsurePopulated(IUserToken *,bool *);
		virtual bool RefreshNeeded(IUserToken *,unsigned __int64);
	};

	bool RefreshNeeded(unsigned __int64);
	long GetPerUserCacheInformation(IUserToken *,unsigned __int64 *,RegistrationChangeDetection::IPerUserCacheInformation * *);
	long InitializeForCombaseIfNecessary();
	long InitializeForRpcssIfNecessary();
	unsigned __int64 GetSequence();
};

namespace RegistrationStore
{
	class ActivatableClassesForMachineTopLevelNode
	{
	protected:
		virtual long ConstructChildByName(HSTRING__ *,Node * *);
	public:
		long GetClassIds(StronglyTypedCollectionNode<&public: static NodeSpec::ClassIdsForMachine const NodeSpec::ClassIdsForMachine,StronglyTypedEntryNode<&public: static NodeSpec::ClassIdMachineRegistration const NodeSpec::ClassIdMachineRegistration,ClassIdMachineRegistrationEntryProperties,ClassIdMachineRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
		long GetDebugInformation(StronglyTypedCollectionNode<&public: static NodeSpec::DebugInformationForMachine const NodeSpec::DebugInformationForMachine,StronglyTypedEntryNode<&public: static NodeSpec::DebugInformationMachineRegistration const NodeSpec::DebugInformationMachineRegistration,DebugInformationMachineRegistrationEntryProperties,DebugInformationMachineRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
		long GetServers(StronglyTypedCollectionNode<&public: static NodeSpec::ServersForMachine const NodeSpec::ServersForMachine,StronglyTypedEntryNode<&public: static NodeSpec::ServerMachineRegistration const NodeSpec::ServerMachineRegistration,ServerMachineRegistrationEntryProperties,ServerMachineRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
		static long Construct(Context &,ActivatableClassesForMachineTopLevelNode * *);
	};

	class ActivatableClassesTopLevelNode
	{
	protected:
		virtual long ConstructChildByName(HSTRING__ *,Node * *);
	public:
		long GetClassIds(StronglyTypedCollectionNode<&public: static NodeSpec::ClassIds const NodeSpec::ClassIds,StronglyTypedEntryNode<&public: static NodeSpec::ClassIdRegistration const NodeSpec::ClassIdRegistration,ClassIdRegistrationEntryProperties,ClassIdRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
		long GetPackages(StronglyTypedCollectionNode<&public: static NodeSpec::Packages const NodeSpec::Packages,PackageNode,HSTRING__ *> * *);
		static long Construct(Context &,ActivatableClassesTopLevelNode * *);
	};

	struct CollectionNode
	{
		virtual long GetExistingChildCount(unsigned int *);
		virtual long GetExistingChildNameByIndex(unsigned int,HSTRING__ * *);
	};

	struct CollectionSpec
	{
		static CollectionSpec const ActivatableClassesForMachine;
		static CollectionSpec const ActivatableClassesForPackage;
		static CollectionSpec const ClassIds;
		static CollectionSpec const ClassIdsForMachine;
		static CollectionSpec const ComClasses;
		static CollectionSpec const ComGuidIndex;
		static CollectionSpec const ComGuidIndexEntry;
		static CollectionSpec const ComInterfaces;
		static CollectionSpec const ComPackages;
		static CollectionSpec const ComPackagesForUser;
		static CollectionSpec const ComProgIds;
		static CollectionSpec const ComProxyStubs;
		static CollectionSpec const ComServers;
		static CollectionSpec const ComStringIndex;
		static CollectionSpec const ComStringIndexEntry;
		static CollectionSpec const ComTreatAsClasses;
		static CollectionSpec const ComTypeLib;
		static CollectionSpec const ComTypeLibs;
		static CollectionSpec const Contracts;
		static CollectionSpec const DebugInformationForMachine;
		static CollectionSpec const DebugInformationForPackage;
		static CollectionSpec const ExtensionRegistrationsForContractAndPackage;
		static CollectionSpec const InterfacesForPackage;
		static CollectionSpec const Packages;
		static CollectionSpec const PackagesForContract;
		static CollectionSpec const ProxyStubsForPackage;
		static CollectionSpec const ServersForMachine;
		static CollectionSpec const ServersForPackage;
		static CollectionSpec const ShadowServersForPackage;
	};

	class ComPackageNode
	{
	protected:
		virtual long ConstructChildByName(HSTRING__ *,Node * *);
	public:
		long GetRegistrationCollection(StronglyTypedCollectionNode<&public: static NodeSpec::ComClasses const NodeSpec::ComClasses,StronglyTypedEntryNode<&public: static NodeSpec::ComClassRegistration const NodeSpec::ComClassRegistration,ComClassRegistrationEntryProperties,ComClassRegistrationEntryPropertyFlags>,_GUID> * *);
		long GetRegistrationCollection(StronglyTypedCollectionNode<&public: static NodeSpec::ComInterfaces const NodeSpec::ComInterfaces,StronglyTypedEntryNode<&public: static NodeSpec::ComInterfaceRegistration const NodeSpec::ComInterfaceRegistration,ComInterfaceRegistrationEntryProperties,ComInterfaceRegistrationEntryPropertyFlags>,_GUID> * *);
		long GetRegistrationCollection(StronglyTypedCollectionNode<&public: static NodeSpec::ComProgIds const NodeSpec::ComProgIds,StronglyTypedEntryNode<&public: static NodeSpec::ComProgIdRegistration const NodeSpec::ComProgIdRegistration,ComProgIdRegistrationEntryProperties,ComProgIdRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
		long GetRegistrationCollection(StronglyTypedCollectionNode<&public: static NodeSpec::ComProxyStubs const NodeSpec::ComProxyStubs,StronglyTypedEntryNode<&public: static NodeSpec::ComProxyStubRegistration const NodeSpec::ComProxyStubRegistration,ComProxyStubRegistrationEntryProperties,ComProxyStubRegistrationEntryPropertyFlags>,_GUID> * *);
		long GetRegistrationCollection(StronglyTypedCollectionNode<&public: static NodeSpec::ComServers const NodeSpec::ComServers,StronglyTypedEntryNode<&public: static NodeSpec::ComServerRegistration const NodeSpec::ComServerRegistration,ComServerRegistrationEntryProperties,ComServerRegistrationEntryPropertyFlags>,unsigned int> * *);
		long GetRegistrationCollection(StronglyTypedCollectionNode<&public: static NodeSpec::ComTreatAsClasses const NodeSpec::ComTreatAsClasses,StronglyTypedEntryNode<&public: static NodeSpec::ComTreatAsClassRegistration const NodeSpec::ComTreatAsClassRegistration,ComTreatAsClassRegistrationEntryProperties,ComTreatAsClassRegistrationEntryPropertyFlags>,_GUID> * *);
		long GetRegistrationCollection(StronglyTypedCollectionNode<&public: static NodeSpec::ComTypeLibs const NodeSpec::ComTypeLibs,StronglyTypedCollectionNode<&public: static NodeSpec::ComTypeLib const NodeSpec::ComTypeLib,StronglyTypedEntryNode<&public: static NodeSpec::ComTypeLibVersionRegistration const NodeSpec::ComTypeLibVersionRegistration,ComTypeLibVersionRegistrationEntryProperties,ComTypeLibVersionRegistrationEntryPropertyFlags>,HSTRING__ *>,_GUID> * *);
	};

	class Context
	{
		long CreateComPackageEntryForIndex<HSTRING__ *>(PackagedComTopLevelNode::IndexType,HSTRING__ *,HSTRING__ *);
		long CreateComPackageEntryForIndex<_GUID>(PackagedComTopLevelNode::IndexType,_GUID,HSTRING__ *);
		long GetActivatableClassRegistrationEntryNode(HSTRING__ *,HSTRING__ *,StronglyTypedEntryNode<&public: static NodeSpec::ActivatableClassRegistration const NodeSpec::ActivatableClassRegistration,ActivatableClassRegistrationEntryProperties,ActivatableClassRegistrationEntryPropertyFlags> * *);
		long GetComPackageForUserEntryNode(HSTRING__ *,StronglyTypedEntryNode<&public: static NodeSpec::ComPackageForUser const NodeSpec::ComPackageForUser,ComPackageForUserEntryProperties,unsigned int> * *);
		long GetComPackageNode(HSTRING__ *,ComPackageNode * *);
		long GetDebugInformationRegistrationEntryNode(HSTRING__ *,HSTRING__ *,StronglyTypedEntryNode<&public: static NodeSpec::DebugInformationRegistration const NodeSpec::DebugInformationRegistration,DebugInformationRegistrationEntryProperties,DebugInformationRegistrationEntryPropertyFlags> * *);
		long GetExtensionRegistrationEntryNode(HSTRING__ *,HSTRING__ *,HSTRING__ *,StronglyTypedEntryNode<&public: static NodeSpec::ExtensionRegistration const NodeSpec::ExtensionRegistration,ExtensionRegistrationEntryProperties,ExtensionRegistrationEntryPropertyFlags> * *);
		long GetProxyStubRegistrationEntryNode(HSTRING__ *,HSTRING__ *,StronglyTypedEntryNode<&public: static NodeSpec::ProxyStubRegistration const NodeSpec::ProxyStubRegistration,ProxyStubRegistrationEntryProperties,ProxyStubRegistrationEntryPropertyFlags> * *);
		long GetServerRegistrationEntryNode(HSTRING__ *,HSTRING__ *,StronglyTypedEntryNode<&public: static NodeSpec::ServerRegistration const NodeSpec::ServerRegistration,ServerRegistrationEntryProperties,ServerRegistrationEntryPropertyFlags> * *);
		long GetShadowServerRegistrationEntryNode(HSTRING__ *,HSTRING__ *,StronglyTypedEntryNode<&public: static NodeSpec::ShadowServerRegistration const NodeSpec::ShadowServerRegistration,ServerRegistrationEntryProperties,ServerRegistrationEntryPropertyFlags> * *);
		long RemoveActivatableClassEntriesForPackage(PackageNode *,RegistrationStoreContext::RemoveDeploymentOperationType);
		long RemoveActivatableClassRegistrationsForPackage(HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType,bool);
		long RemoveClassIdEntryForActivatableClass(StronglyTypedEntryNode<&public: static NodeSpec::ActivatableClassRegistration const NodeSpec::ActivatableClassRegistration,ActivatableClassRegistrationEntryProperties,ActivatableClassRegistrationEntryPropertyFlags> *,RegistrationStoreContext::RemoveDeploymentOperationType);
		long RemoveDebugInformationForPackageHelper(HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType);
		long RemoveExtensionRegistrationsForContractAndPackage(ContractNode *,HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType);
		long RemoveInterfaceRegistrationsForPackage(HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType,bool);
		long RemoveProxyStubRegistrationsForPackage(HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType,bool);
		long RemoveServerEntriesForPackage(PackageNode *,RegistrationStoreContext::RemoveDeploymentOperationType);
		long RemoveShadowServersForPackageHelper(HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType);
		static long RemoveComPackageEntryForIndex<HSTRING__ *>(Context &,PackagedComTopLevelNode::IndexType,HSTRING__ *,HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType);
		static long RemoveComPackageEntryForIndex<_GUID>(Context &,PackagedComTopLevelNode::IndexType,_GUID,HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType);
		static long RemoveComTypeLibVersionEntries(StronglyTypedCollectionNode<&public: static NodeSpec::ComTypeLib const NodeSpec::ComTypeLib,StronglyTypedEntryNode<&public: static NodeSpec::ComTypeLibVersionRegistration const NodeSpec::ComTypeLibVersionRegistration,ComTypeLibVersionRegistrationEntryProperties,ComTypeLibVersionRegistrationEntryPropertyFlags>,HSTRING__ *> &,RegistrationStoreContext::RemoveDeploymentOperationType);
	public:
		long GetUserSid(unsigned short const * *);
		virtual RegistrationStoreContext::HandleDetail * DuplicateHandle(RegistrationStoreContext::HandleDetail *);
		virtual Windows::Foundation::RegistrationScope GetRegistrationStoreScope();
		virtual long CheckComPackageExists(HSTRING__ *,bool *);
		virtual long CommitChanges(bool);
		virtual long CreateActivatableClassEntry(HSTRING__ *,HSTRING__ *,ActivatableClassRegistrationEntryProperties const &);
		virtual long CreateClassIdEntry(HSTRING__ *,ClassIdRegistrationEntryProperties const &);
		virtual long CreateComClassEntry(HSTRING__ *,_GUID const &,ComClassRegistrationEntryProperties const &);
		virtual long CreateComInterfaceEntry(HSTRING__ *,_GUID const &,ComInterfaceRegistrationEntryProperties const &);
		virtual long CreateComPackageInstallOrderEntry(HSTRING__ *,ComPackageForUserEntryProperties const &);
		virtual long CreateComProgIdEntry(HSTRING__ *,HSTRING__ *,ComProgIdRegistrationEntryProperties const &);
		virtual long CreateComProxyStubEntry(HSTRING__ *,_GUID const &,ComProxyStubRegistrationEntryProperties const &);
		virtual long CreateComServerEntry(HSTRING__ *,unsigned int,ComServerRegistrationEntryProperties const &);
		virtual long CreateComTreatAsClassEntry(HSTRING__ *,_GUID const &,ComTreatAsClassRegistrationEntryProperties const &);
		virtual long CreateComTypeLibEntry(HSTRING__ *,_GUID const &,HSTRING__ *,ComTypeLibVersionRegistrationEntryProperties const &);
		virtual long CreateDebugInformationEntriesForPackage(HSTRING__ *,DebugInformationRegistrationEntryProperties const &);
		virtual long CreateExtensionEntry(HSTRING__ *,HSTRING__ *,HSTRING__ *,ExtensionRegistrationEntryProperties const &);
		virtual long CreateInterfaceEntry(HSTRING__ *,HSTRING__ *,InterfaceRegistrationEntryProperties const &);
		virtual long CreatePackage(HSTRING__ *,bool);
		virtual long CreateProxyStubEntry(HSTRING__ *,HSTRING__ *,ProxyStubRegistrationEntryProperties const &);
		virtual long CreateServerEntry(HSTRING__ *,HSTRING__ *,ServerRegistrationEntryProperties const &);
		virtual long CreateShadowServerEntry(HSTRING__ *,HSTRING__ *,ServerRegistrationEntryProperties const &);
		virtual long GetComClassIdByIndex(RegistrationStoreContext::ComClassIndexHandleDetail *,unsigned int,_GUID *);
		virtual long GetComClassIndex(RegistrationStoreContext::ComClassIndexHandleDetail * *);
		virtual long GetComClassIndexEntry(_GUID const &,RegistrationStoreContext::ComClassIndexEntryHandleDetail * *);
		virtual long GetComInterfaceIndexEntry(_GUID const &,RegistrationStoreContext::ComInterfaceIndexEntryHandleDetail * *);
		virtual long GetComPackageIdForClassByIndex(RegistrationStoreContext::ComClassIndexEntryHandleDetail *,unsigned int,HSTRING__ * *);
		virtual long GetComPackageIdForInterfaceByIndex(RegistrationStoreContext::ComInterfaceIndexEntryHandleDetail *,unsigned int,HSTRING__ * *);
		virtual long GetComPackageIdForProgIdByIndex(RegistrationStoreContext::ComProgIdIndexEntryHandleDetail *,unsigned int,HSTRING__ * *);
		virtual long GetComPackageIdForTreatAsClassByIndex(RegistrationStoreContext::ComTreatAsClassIndexEntryHandleDetail *,unsigned int,HSTRING__ * *);
		virtual long GetComPackageIdForTypeLibByIndex(RegistrationStoreContext::ComTypeLibIndexEntryHandleDetail *,unsigned int,HSTRING__ * *);
		virtual long GetComPackageInstallOrder(HSTRING__ *,unsigned int *);
		virtual long GetComProgIdByIndex(RegistrationStoreContext::ComProgIdIndexHandleDetail *,unsigned int,HSTRING__ * *);
		virtual long GetComProgIdIndex(RegistrationStoreContext::ComProgIdIndexHandleDetail * *);
		virtual long GetComProgIdIndexEntry(HSTRING__ *,RegistrationStoreContext::ComProgIdIndexEntryHandleDetail * *);
		virtual long GetComTreatAsClassIndexEntry(_GUID const &,RegistrationStoreContext::ComTreatAsClassIndexEntryHandleDetail * *);
		virtual long GetComTypeLib(HSTRING__ *,_GUID const &,RegistrationStoreContext::ComTypeLibHandleDetail * *);
		virtual long GetComTypeLibIdByIndex(RegistrationStoreContext::ComTypeLibIndexHandleDetail *,unsigned int,_GUID *);
		virtual long GetComTypeLibIndex(RegistrationStoreContext::ComTypeLibIndexHandleDetail * *);
		virtual long GetComTypeLibIndexEntry(_GUID const &,RegistrationStoreContext::ComTypeLibIndexEntryHandleDetail * *);
		virtual long GetComTypeLibVersionIdByIndex(RegistrationStoreContext::ComTypeLibHandleDetail *,unsigned int,HSTRING__ * *);
		virtual long GetContract(HSTRING__ *,RegistrationStoreContext::ContractHandleDetail * *);
		virtual long GetContractByIndex(unsigned int,HSTRING__ * *,RegistrationStoreContext::ContractHandleDetail * *);
		virtual long GetLastWriteTimeForActivatableClassEntry(HSTRING__ *,HSTRING__ *,RegistrationRefreshPolicy,__int64 *);
		virtual long GetLastWriteTimeForActivatableClassEntry(RegistrationStoreContext::ActivatableClassHandleDetail *,__int64 *);
		virtual long GetLastWriteTimeForDebugInformationEntry(HSTRING__ *,HSTRING__ *,RegistrationRefreshPolicy,__int64 *);
		virtual long GetLastWriteTimeForDebugInformationEntry(RegistrationStoreContext::DebugInformationHandleDetail *,__int64 *);
		virtual long GetLastWriteTimeForProxyStubEntry(HSTRING__ *,HSTRING__ *,RegistrationRefreshPolicy,__int64 *);
		virtual long GetLastWriteTimeForProxyStubEntry(RegistrationStoreContext::ProxyStubHandleDetail *,__int64 *);
		virtual long GetLastWriteTimeForServerEntry(HSTRING__ *,HSTRING__ *,RegistrationRefreshPolicy,__int64 *);
		virtual long GetLastWriteTimeForServerEntry(RegistrationStoreContext::ServerHandleDetail *,__int64 *);
		virtual long GetMachineActivatableClass(HSTRING__ *,RegistrationStoreContext::ActivatableClassHandleDetail * *);
		virtual long GetMachineDebugInformation(HSTRING__ *,RegistrationStoreContext::DebugInformationHandleDetail * *);
		virtual long GetMachineServer(HSTRING__ *,RegistrationStoreContext::ServerHandleDetail * *);
		virtual long GetPackage(HSTRING__ *,RegistrationStoreContext::PackageHandleDetail * *);
		virtual long GetPackageActivatableClass(HSTRING__ *,HSTRING__ *,RegistrationStoreContext::ActivatableClassHandleDetail * *);
		virtual long GetPackageDebugInformation(HSTRING__ *,HSTRING__ *,RegistrationStoreContext::DebugInformationHandleDetail * *);
		virtual long GetPackageForContract(HSTRING__ *,HSTRING__ *,RegistrationStoreContext::PackageForContractHandleDetail * *);
		virtual long GetPackageForContractByIndex(RegistrationStoreContext::ContractHandleDetail *,unsigned int,HSTRING__ * *,RegistrationStoreContext::PackageForContractHandleDetail * *);
		virtual long GetPackageProxyStub(HSTRING__ *,HSTRING__ *,RegistrationStoreContext::ProxyStubHandleDetail * *);
		virtual long GetPackageServer(HSTRING__ *,HSTRING__ *,RegistrationStoreContext::ServerHandleDetail * *);
		virtual long GetRefreshPolicyForActivatableClassEntry(RegistrationStoreContext::ActivatableClassHandleDetail *,RegistrationRefreshPolicy *);
		virtual long GetRefreshPolicyForDebugInformationEntry(RegistrationStoreContext::DebugInformationHandleDetail *,RegistrationRefreshPolicy *);
		virtual long GetRefreshPolicyForProxyStubEntry(RegistrationStoreContext::ProxyStubHandleDetail *,RegistrationRefreshPolicy *);
		virtual long GetRefreshPolicyForServerEntry(RegistrationStoreContext::ServerHandleDetail *,RegistrationRefreshPolicy *);
		virtual long ReadComClassEntry(HSTRING__ *,_GUID const &,ComClassRegistrationEntryProperties &,ComClassRegistrationEntryPropertyFlags *,ComClassRegistrationEntryPropertyFlags *);
		virtual long ReadComInterfaceEntry(HSTRING__ *,_GUID const &,ComInterfaceRegistrationEntryProperties &,ComInterfaceRegistrationEntryPropertyFlags *,ComInterfaceRegistrationEntryPropertyFlags *);
		virtual long ReadComProgIdEntry(HSTRING__ *,HSTRING__ *,ComProgIdRegistrationEntryProperties &,ComProgIdRegistrationEntryPropertyFlags *,ComProgIdRegistrationEntryPropertyFlags *);
		virtual long ReadComProxyStubEntry(HSTRING__ *,_GUID const &,ComProxyStubRegistrationEntryProperties &,ComProxyStubRegistrationEntryPropertyFlags *,ComProxyStubRegistrationEntryPropertyFlags *);
		virtual long ReadComServerEntry(HSTRING__ *,unsigned int,ComServerRegistrationEntryProperties &,ComServerRegistrationEntryPropertyFlags *,ComServerRegistrationEntryPropertyFlags *);
		virtual long ReadComTreatAsClassEntry(HSTRING__ *,_GUID const &,ComTreatAsClassRegistrationEntryProperties &,ComTreatAsClassRegistrationEntryPropertyFlags *,ComTreatAsClassRegistrationEntryPropertyFlags *);
		virtual long ReadComTypeLibEntry(HSTRING__ *,_GUID const &,HSTRING__ *,ComTypeLibVersionRegistrationEntryProperties &,ComTypeLibVersionRegistrationEntryPropertyFlags *,ComTypeLibVersionRegistrationEntryPropertyFlags *);
		virtual long ReadExtensionEntry(HSTRING__ *,HSTRING__ *,HSTRING__ *,ExtensionRegistrationEntryProperties &,ExtensionRegistrationEntryPropertyFlags *,ExtensionRegistrationEntryPropertyFlags *);
		virtual long ReadExtensionEntryByIndex(RegistrationStoreContext::PackageForContractHandleDetail *,unsigned int,HSTRING__ * *,ExtensionRegistrationEntryProperties &,ExtensionRegistrationEntryPropertyFlags *,ExtensionRegistrationEntryPropertyFlags *);
		virtual long ReadMachineActivatableClassClsidEntry(RegistrationStoreContext::ActivatableClassHandleDetail *,Optional<OpaqueString> &);
		virtual long ReadMachineActivatableClassEntry(RegistrationStoreContext::ActivatableClassHandleDetail *,ActivatableClassMachineRegistrationEntryProperties &,ActivatableClassMachineRegistrationEntryPropertyFlags *,ActivatableClassMachineRegistrationEntryPropertyFlags *);
		virtual long ReadMachineClassIdEntry(HSTRING__ *,ClassIdMachineRegistrationEntryProperties &,ClassIdMachineRegistrationEntryPropertyFlags *,ClassIdMachineRegistrationEntryPropertyFlags *);
		virtual long ReadMachineDebugInformationEntry(RegistrationStoreContext::DebugInformationHandleDetail *,DebugInformationMachineRegistrationEntryProperties &,DebugInformationMachineRegistrationEntryPropertyFlags *,DebugInformationMachineRegistrationEntryPropertyFlags *);
		virtual long ReadMachineServerEntry(RegistrationStoreContext::ServerHandleDetail *,ServerMachineRegistrationEntryProperties &,ServerMachineRegistrationEntryPropertyFlags *,ServerMachineRegistrationEntryPropertyFlags *);
		virtual long ReadPackageActivatableClassClsidEntry(RegistrationStoreContext::ActivatableClassHandleDetail *,Optional<OpaqueString> &);
		virtual long ReadPackageActivatableClassEntry(RegistrationStoreContext::ActivatableClassHandleDetail *,ActivatableClassRegistrationEntryProperties &,ActivatableClassRegistrationEntryPropertyFlags *,ActivatableClassRegistrationEntryPropertyFlags *);
		virtual long ReadPackageClassIdEntry(HSTRING__ *,ClassIdRegistrationEntryProperties &,ClassIdRegistrationEntryPropertyFlags *,ClassIdRegistrationEntryPropertyFlags *);
		virtual long ReadPackageDebugInformationEntry(RegistrationStoreContext::DebugInformationHandleDetail *,DebugInformationRegistrationEntryProperties &,DebugInformationRegistrationEntryPropertyFlags *,DebugInformationRegistrationEntryPropertyFlags *);
		virtual long ReadPackageInterfaceEntry(HSTRING__ *,HSTRING__ *,InterfaceRegistrationEntryProperties &,InterfaceRegistrationEntryPropertyFlags *,InterfaceRegistrationEntryPropertyFlags *);
		virtual long ReadPackageProxyStubEntry(RegistrationStoreContext::ProxyStubHandleDetail *,ProxyStubRegistrationEntryProperties &,ProxyStubRegistrationEntryPropertyFlags *,ProxyStubRegistrationEntryPropertyFlags *);
		virtual long ReadPackageServerEntry(RegistrationStoreContext::ServerHandleDetail *,ServerRegistrationEntryProperties &,ServerRegistrationEntryPropertyFlags *,ServerRegistrationEntryPropertyFlags *);
		virtual long ReadPackageServerEntryByIndex(RegistrationStoreContext::PackageHandleDetail *,unsigned int,HSTRING__ * *,ServerRegistrationEntryProperties &,ServerRegistrationEntryPropertyFlags *,ServerRegistrationEntryPropertyFlags *);
		virtual long RemoveActivationEntriesForPackage(HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType,bool);
		virtual long RemoveComEntriesForPackage(HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType);
		virtual long RemoveComPackageInstallOrderEntry(HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType);
		virtual long RemoveDebugInformationForPackage(HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType);
		virtual long RemoveExtensionEntriesForPackage(HSTRING__ *,RegistrationStoreContext::RemoveDeploymentOperationType);
		virtual void ReleaseHandle(RegistrationStoreContext::HandleDetail *);
		virtual void RevertChanges();
	};

	class ContractNode
	{
	protected:
		virtual long ConstructChildByName(HSTRING__ *,Node * *);
	public:
		long GetPackages(StronglyTypedCollectionNode<&public: static NodeSpec::PackagesForContract const NodeSpec::PackagesForContract,PackageForContractNode,HSTRING__ *> * *);
	};

	class EntryNode
	{
		long DeletePropertyStoreSubKeys();
		long ForcePropertyStorePropertiesToMemory(void *);
		long WriteOptionalGuidProperty(unsigned int,Optional<_GUID> const &);
		long WriteProperties(bool);
		long WritePropertyStoreProperty(unsigned int,EntryPropertyStore const &);
		long WriteRequiredGuidProperty(unsigned int,_GUID const &);
	protected:
		EntryNode(Nodes &,NodeSpec const &,Node *,OpaqueString const &);
		long Create(void const *);
		long ReadOptionalBoolProperty(unsigned int,Optional<bool> *);
		long ReadOptionalExpandableStringProperty(unsigned int,Optional<ExpandableString> &);
		long ReadOptionalGuidProperty(unsigned int,Optional<_GUID> &);
		long ReadOptionalMultiStringProperty(unsigned int,Optional<MultiString> &);
		long ReadOptionalSecurityDescriptorProperty(unsigned int,Optional<SecurityDescriptor> &);
		long ReadOptionalUInt32Property(unsigned int,Optional<unsigned int> *);
		long ReadOptionalUInt32RangeProperty(unsigned int,Optional<unsigned int> *);
		long ReadProperties(void *,unsigned int *,unsigned int *);
		long ReadRequiredBoolProperty(unsigned int,bool *);
		long ReadRequiredExpandableStringProperty(unsigned int,ExpandableString &);
		long ReadRequiredMultiStringProperty(unsigned int,MultiString &);
		long ReadRequiredSecurityDescriptorProperty(unsigned int,SecurityDescriptor &);
		long ReadRequiredUInt32Property(unsigned int,unsigned int *);
		long ReadRequiredUInt32RangeProperty(unsigned int,unsigned int *);
		long ReadRequiredUInt64Property(unsigned int,unsigned __int64 *);
		virtual long Calculate(_LIST_ENTRY &);
		virtual long Commit();
		virtual long ConstructChildByName(HSTRING__ *,Node * *);
		virtual long GetExistingChildNameByIndex(unsigned int,HSTRING__ * *);
		virtual void Revert();
		virtual ~EntryNode();
	public:
		long ReadOptionalStringProperty(unsigned int,Optional<OpaqueString> &);
		long ReadRequiredGuidProperty(unsigned int,_GUID &);
		long Remove(RegistrationStoreContext::RemoveDeploymentOperationType);
		virtual long GetExistingChildCount(unsigned int *);
		virtual long PrepareData();
		virtual void NotifyChildCreated();
		virtual void NotifyChildRemoved();
	};

	class EntrySpec
	{
		static EntrySpec::PropertySpec const * const s_ActivatableClassMachineRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ActivatableClassRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ClassIdMachineRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ClassIdRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ComClassRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ComInterfaceRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ComPackageForGuidIndexPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ComPackageForStringIndexPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ComPackageForUserPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ComProgIdRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ComProxyStubRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ComServerRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ComTreatAsClassRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ComTypeLibVersionRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_DebugInformationMachineRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_DebugInformationRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ExtensionRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_InterfaceRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ProxyStubRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ServerMachineRegistrationPropertySpecs;
		static EntrySpec::PropertySpec const * const s_ServerRegistrationPropertySpecs;
	public:
		static EntrySpec const ActivatableClassMachineRegistration;
		static EntrySpec const ActivatableClassRegistration;
		static EntrySpec const ClassIdMachineRegistration;
		static EntrySpec const ClassIdRegistration;
		static EntrySpec const ComClassRegistration;
		static EntrySpec const ComInterfaceRegistration;
		static EntrySpec const ComPackageForGuidIndex;
		static EntrySpec const ComPackageForStringIndex;
		static EntrySpec const ComPackageForUser;
		static EntrySpec const ComProgIdRegistration;
		static EntrySpec const ComProxyStubRegistration;
		static EntrySpec const ComServerRegistration;
		static EntrySpec const ComTreatAsClassRegistration;
		static EntrySpec const ComTypeLibVersionRegistration;
		static EntrySpec const DebugInformationMachineRegistration;
		static EntrySpec const DebugInformationRegistration;
		static EntrySpec const ExtensionRegistration;
		static EntrySpec const InterfaceRegistration;
		static EntrySpec const ProxyStubRegistration;
		static EntrySpec const ServerMachineRegistration;
		static EntrySpec const ServerRegistration;
		static EntrySpec const ShadowServerRegistration;
		void ClearProperties(void *);
	};

	class ExtensionsTopLevelNode
	{
	protected:
		virtual long ConstructChildByName(HSTRING__ *,Node * *);
	public:
		long GetContracts(StronglyTypedCollectionNode<&public: static NodeSpec::Contracts const NodeSpec::Contracts,ContractNode,HSTRING__ *> * *);
		static long Construct(Context &,ExtensionsTopLevelNode * *);
	};

	class JunctionNode
	{
	protected:
		virtual long GetExistingChildNameByIndex(unsigned int,HSTRING__ * *);
	public:
		virtual long GetExistingChildCount(unsigned int *);
	};

	struct JunctionSpec
	{
		RegistrationStoreTypes::NodeType ChildTypeByName(HSTRING__ *);
		static JunctionSpec const ComPackage;
		static JunctionSpec const Contract;
		static JunctionSpec const Package;
		static JunctionSpec const PackageForContract;
		static JunctionSpec::ChildSpec const * const s_ActivatableClassesForMachineTopLevelChildSpecs;
		static JunctionSpec::ChildSpec const * const s_ActivatableClassesTopLevelChildSpecs;
		static JunctionSpec::ChildSpec const * const s_ComPackageChildSpecs;
		static JunctionSpec::ChildSpec const * const s_ContractChildSpecs;
		static JunctionSpec::ChildSpec const * const s_ExtensionsTopLevelChildSpecs;
		static JunctionSpec::ChildSpec const * const s_PackageChildSpecs;
		static JunctionSpec::ChildSpec const * const s_PackageForContractChildSpecs;
		static JunctionSpec::ChildSpec const * const s_PackagedComForUserTopLevelChildSpecs;
		static JunctionSpec::ChildSpec const * const s_PackagedComTopLevelChildSpecs;
	};

	class Node
	{
		static int CompareNodes(Node *,HSTRING__ *,Node *,HSTRING__ *);
		void InsertIntoContext();
	protected:
		Node(Nodes &,NodeSpec const &,Node *,OpaqueString const &);
		long GetChildByName(HSTRING__ *,Node * *);
		long GetExistingChildByIndex(unsigned int,Node * *);
		virtual long Calculate(_LIST_ENTRY &);
		virtual long Commit();
		virtual void Revert();
		virtual ~Node();
	public:
		long GetExists(bool *);
		static long CommitChanges(_LIST_ENTRY const &,bool);
		virtual Windows::Foundation::RegistrationScope GetScope();
		virtual bool DoesContextSupportCaching();
		virtual long GetLastWriteTimeWithRefreshPolicy(RegistrationRefreshPolicy,__int64 *);
		virtual long GetRefreshPolicy(RegistrationRefreshPolicy *);
		virtual long PrepareData();
		virtual long PrepareForRead();
		virtual void NotifyChildCreated();
		virtual void NotifyChildRemoved();
	};

	struct NodeSpec
	{
		static NodeSpec const ActivatableClassMachineRegistration;
		static NodeSpec const ActivatableClassRegistration;
		static NodeSpec const ActivatableClassesForMachine;
		static NodeSpec const ActivatableClassesForMachineTopLevel;
		static NodeSpec const ActivatableClassesForPackage;
		static NodeSpec const ActivatableClassesTopLevel;
		static NodeSpec const ClassIdMachineRegistration;
		static NodeSpec const ClassIdRegistration;
		static NodeSpec const ClassIds;
		static NodeSpec const ClassIdsForMachine;
		static NodeSpec const ComClassRegistration;
		static NodeSpec const ComClasses;
		static NodeSpec const ComGuidIndex;
		static NodeSpec const ComGuidIndexEntry;
		static NodeSpec const ComInterfaceRegistration;
		static NodeSpec const ComInterfaces;
		static NodeSpec const ComPackage;
		static NodeSpec const ComPackageForGuidIndex;
		static NodeSpec const ComPackageForStringIndex;
		static NodeSpec const ComPackageForUser;
		static NodeSpec const ComPackages;
		static NodeSpec const ComPackagesForUser;
		static NodeSpec const ComProgIdRegistration;
		static NodeSpec const ComProgIds;
		static NodeSpec const ComProxyStubRegistration;
		static NodeSpec const ComProxyStubs;
		static NodeSpec const ComServerRegistration;
		static NodeSpec const ComServers;
		static NodeSpec const ComStringIndex;
		static NodeSpec const ComStringIndexEntry;
		static NodeSpec const ComTreatAsClassRegistration;
		static NodeSpec const ComTreatAsClasses;
		static NodeSpec const ComTypeLib;
		static NodeSpec const ComTypeLibVersionRegistration;
		static NodeSpec const ComTypeLibs;
		static NodeSpec const Contract;
		static NodeSpec const Contracts;
		static NodeSpec const DebugInformationForMachine;
		static NodeSpec const DebugInformationForPackage;
		static NodeSpec const DebugInformationMachineRegistration;
		static NodeSpec const DebugInformationRegistration;
		static NodeSpec const ExtensionRegistration;
		static NodeSpec const ExtensionRegistrationsForContractAndPackage;
		static NodeSpec const ExtensionsTopLevel;
		static NodeSpec const InterfaceRegistration;
		static NodeSpec const InterfacesForPackage;
		static NodeSpec const Package;
		static NodeSpec const PackageForContract;
		static NodeSpec const PackagedComForUserTopLevel;
		static NodeSpec const PackagedComTopLevel;
		static NodeSpec const Packages;
		static NodeSpec const PackagesForContract;
		static NodeSpec const ProxyStubRegistration;
		static NodeSpec const ProxyStubsForPackage;
		static NodeSpec const ServerMachineRegistration;
		static NodeSpec const ServerRegistration;
		static NodeSpec const ServersForMachine;
		static NodeSpec const ServersForPackage;
		static NodeSpec const ShadowServerRegistration;
		static NodeSpec const ShadowServersForPackage;
	};

	class PackageForContractNode
	{
	protected:
		virtual long ConstructChildByName(HSTRING__ *,Node * *);
	public:
		long GetExtensionRegistrations(StronglyTypedCollectionNode<&public: static NodeSpec::ExtensionRegistrationsForContractAndPackage const NodeSpec::ExtensionRegistrationsForContractAndPackage,StronglyTypedEntryNode<&public: static NodeSpec::ExtensionRegistration const NodeSpec::ExtensionRegistration,ExtensionRegistrationEntryProperties,ExtensionRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
	};

	class PackageNode
	{
	protected:
		virtual long Calculate(_LIST_ENTRY &);
		virtual long ConstructChildByName(HSTRING__ *,Node * *);
	public:
		long CheckAndSetPerAppHiveUsage(PackageContext const &);
		long GetActivatableClasses(StronglyTypedCollectionNode<&public: static NodeSpec::ActivatableClassesForPackage const NodeSpec::ActivatableClassesForPackage,StronglyTypedEntryNode<&public: static NodeSpec::ActivatableClassRegistration const NodeSpec::ActivatableClassRegistration,ActivatableClassRegistrationEntryProperties,ActivatableClassRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
		long GetDebugInformation(StronglyTypedCollectionNode<&public: static NodeSpec::DebugInformationForPackage const NodeSpec::DebugInformationForPackage,StronglyTypedEntryNode<&public: static NodeSpec::DebugInformationRegistration const NodeSpec::DebugInformationRegistration,DebugInformationRegistrationEntryProperties,DebugInformationRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
		long GetInterfaces(StronglyTypedCollectionNode<&public: static NodeSpec::InterfacesForPackage const NodeSpec::InterfacesForPackage,StronglyTypedEntryNode<&public: static NodeSpec::InterfaceRegistration const NodeSpec::InterfaceRegistration,InterfaceRegistrationEntryProperties,InterfaceRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
		long GetProxyStubs(StronglyTypedCollectionNode<&public: static NodeSpec::ProxyStubsForPackage const NodeSpec::ProxyStubsForPackage,StronglyTypedEntryNode<&public: static NodeSpec::ProxyStubRegistration const NodeSpec::ProxyStubRegistration,ProxyStubRegistrationEntryProperties,ProxyStubRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
		long GetServers(StronglyTypedCollectionNode<&public: static NodeSpec::ServersForPackage const NodeSpec::ServersForPackage,StronglyTypedEntryNode<&public: static NodeSpec::ServerRegistration const NodeSpec::ServerRegistration,ServerRegistrationEntryProperties,ServerRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
		long GetShadowServers(StronglyTypedCollectionNode<&public: static NodeSpec::ShadowServersForPackage const NodeSpec::ShadowServersForPackage,StronglyTypedEntryNode<&public: static NodeSpec::ShadowServerRegistration const NodeSpec::ShadowServerRegistration,ServerRegistrationEntryProperties,ServerRegistrationEntryPropertyFlags>,HSTRING__ *> * *);
		virtual long GetLastWriteTimeWithRefreshPolicy(RegistrationRefreshPolicy,__int64 *);
		virtual long GetRefreshPolicy(RegistrationRefreshPolicy *);
	};

	class PackagedComForUserTopLevelNode
	{
	protected:
		virtual long ConstructChildByName(HSTRING__ *,Node * *);
	public:
		long GetPackages(StronglyTypedCollectionNode<&public: static NodeSpec::ComPackagesForUser const NodeSpec::ComPackagesForUser,StronglyTypedEntryNode<&public: static NodeSpec::ComPackageForUser const NodeSpec::ComPackageForUser,ComPackageForUserEntryProperties,unsigned int>,HSTRING__ *> * *);
		static long Construct(Context &,PackagedComForUserTopLevelNode * *);
	};

	class PackagedComTopLevelNode
	{
	protected:
		virtual long ConstructChildByName(HSTRING__ *,Node * *);
	public:
		long GetIndex(PackagedComTopLevelNode::IndexType,StronglyTypedCollectionNode<&public: static NodeSpec::ComGuidIndex const NodeSpec::ComGuidIndex,StronglyTypedCollectionNode<&public: static NodeSpec::ComGuidIndexEntry const NodeSpec::ComGuidIndexEntry,StronglyTypedEntryNode<&public: static NodeSpec::ComPackageForGuidIndex const NodeSpec::ComPackageForGuidIndex,EmptyEntryProperties,unsigned int>,HSTRING__ *>,_GUID> * *);
		long GetIndex(PackagedComTopLevelNode::IndexType,StronglyTypedCollectionNode<&public: static NodeSpec::ComStringIndex const NodeSpec::ComStringIndex,StronglyTypedCollectionNode<&public: static NodeSpec::ComStringIndexEntry const NodeSpec::ComStringIndexEntry,StronglyTypedEntryNode<&public: static NodeSpec::ComPackageForStringIndex const NodeSpec::ComPackageForStringIndex,EmptyEntryProperties,unsigned int>,HSTRING__ *>,HSTRING__ *> * *);
		long GetPackages(StronglyTypedCollectionNode<&public: static NodeSpec::ComPackages const NodeSpec::ComPackages,ComPackageNode,HSTRING__ *> * *);
		static long Construct(Context &,PackagedComTopLevelNode * *);
	};

	class TopLevelNode
	{
	protected:
		TopLevelNode(Nodes &,NodeSpec const &,OpaqueString const &,bool,Windows::Foundation::RegistrationScope);
		static long GetInboxPath(TopLevelSpec const &,HSTRING__ * *);
		static long GetPerUserPath(Context &,TopLevelSpec const &,HSTRING__ * *);
		virtual long Commit();
		virtual void Revert();
	public:
		virtual Windows::Foundation::RegistrationScope GetScope();
		virtual bool DoesContextSupportCaching();
	};

	struct TopLevelSpec
	{
		static TopLevelSpec const ActivatableClassesForMachineTopLevel;
		static TopLevelSpec const ActivatableClassesTopLevel;
		static TopLevelSpec const ExtensionsTopLevel;
		static TopLevelSpec const PackagedComForUserTopLevel;
		static TopLevelSpec const PackagedComTopLevel;
	};

};

namespace RegistrationStoreData
{
	struct AbsolutePathedRegistryKeyData
	{
		AbsolutePathedRegistryKeyData(OpaqueString const &);
		virtual long Create();
		virtual long Delete();
		virtual long PrepareForRead();
	};

	class AncestralRelativePathedRegistryKeyData
	{
		long BuildPathToAncestor(RegistryKeyData * &,unsigned short * &,unsigned __int64 &);
		long ValidateName(RegistryKey &,unsigned __int64);
		long ValidatePathToAncestor(RegistryKeyData *,unsigned short const *,unsigned __int64);
	public:
		virtual long PrepareForRead();
	};

	struct CacheAwareRegistryKeyData<AbsolutePathedRegistryKeyData>
	{
		virtual HKEY__ * Key();
		virtual HSTRING__ * Name();
		virtual RegistryKeyData * Parent();
		virtual long Create();
		virtual long Delete();
		virtual long GetChildCount(unsigned int *);
		virtual long GetChildNameByIndex(unsigned int,HSTRING__ * *);
		virtual long GetLastWriteTime(__int64 *);
		virtual long PrepareForRead();
	};

	struct CacheAwareRegistryKeyData<RelativePathedRegistryKeyData>
	{
		virtual HKEY__ * Key();
		virtual HSTRING__ * Name();
		virtual RegistryKeyData * Parent();
		virtual long Create();
		virtual long Delete();
		virtual long GetChildCount(unsigned int *);
		virtual long GetChildNameByIndex(unsigned int,HSTRING__ * *);
		virtual long GetLastWriteTime(__int64 *);
		virtual long PrepareForRead();
	};

	struct CachedRegistryKeyData
	{
		virtual long Create();
		virtual long Delete();
		virtual long PrepareForRead();
		virtual long QueryInterface(_GUID const &,void * *);
	};

	struct CompositeData
	{
		CompositeData(RegistrationStoreTypes::IData *,RegistrationStoreTypes::IData *);
		virtual long Create();
		virtual long Delete();
		virtual long GetChildCount(unsigned int *);
		virtual long GetChildNameByIndex(unsigned int,HSTRING__ * *);
		virtual long GetLastWriteTime(__int64 *);
		virtual long PrepareForRead();
		virtual ~CompositeData();
	};

	namespace DataFactory
	{
		struct ActivationDataFactory
		{
			virtual long Construct(void *,RegistrationStoreTypes::IData * *);
			virtual long QueryInterface(_GUID const &,void * *);
		};

		struct MachineDeploymentDataFactory
		{
			virtual long Construct(void *,RegistrationStoreTypes::IData * *);
		};

		struct RefreshPolicyDataFactory
		{
			virtual long Construct(void *,RegistrationStoreTypes::IData * *);
		};

		struct UserDeploymentDataFactory
		{
			virtual long Construct(void *,RegistrationStoreTypes::IData * *);
		};

		DataFactory::ActivationDataFactory g_ActivationDataFactory;
		DataFactory::RefreshPolicyDataFactory g_RefreshPolicyDataFactory;
		long Construct(void *,RegistrationStoreTypes::IData * *);
	};

	struct NullData
	{
		virtual long Create();
		virtual long Delete();
		virtual long GetChildCount(unsigned int *);
		virtual long GetChildNameByIndex(unsigned int,HSTRING__ * *);
		virtual long GetLastWriteTime(__int64 *);
		virtual long PrepareForRead();
		virtual long QueryInterface(_GUID const &,void * *);
	};

	struct PackageData
	{
		PackageData(RegistryKeyData *,RegistryKeyData *);
		virtual long Create();
		virtual long Delete();
		virtual long GetLastWriteTime(__int64 *);
	};

	struct PackageDataCache
	{
		PackageDataCache();
		static long EnabledForPackageId(Windows::Foundation::RegistrationScope,OpaqueString const &);
	};

	struct PackageDataCacheEntry
	{
		PackageDataCacheEntry(OpaqueString const &,RegistrationStoreTypes::IData *);
	};

	struct PrivateHive
	{
		static bool PackageUsesPrivateHive(Windows::Foundation::RegistrationScope,HSTRING__ *);
		static long Delete(HSTRING__ *,HSTRING__ *,RegistryKey &,bool);
		static long GetMachineHivePath(HSTRING__ *,HSTRING__ * *);
		static long GetUserHivePath(void *,HSTRING__ *,HSTRING__ * *);
		static long LoadAppKey(HSTRING__ *,unsigned long,RegistryKey &);
		static long RemoveUserHivePath(void *,HSTRING__ *);
	};

	struct PrivateHiveReaderRegistryKeyData
	{
		virtual long Create();
		virtual long Delete();
		virtual long PrepareForRead();
	};

	struct PrivateHiveRegistryKeyData
	{
		PrivateHiveRegistryKeyData(OpaqueString const &,OpaqueString const &,bool);
		virtual long Create();
		virtual long Delete();
		virtual long PrepareForRead();
	};

	struct RegistryKeyData
	{
		bool Initialized();
		virtual HKEY__ * Key();
		virtual HSTRING__ * Name();
		virtual RegistryKeyData * Parent();
		virtual RegistryKeyOptions Options();
		virtual long GetChildCount(unsigned int *);
		virtual long GetChildNameByIndex(unsigned int,HSTRING__ * *);
		virtual long GetLastWriteTime(__int64 *);
		virtual long ReadBinaryValue(unsigned short const *,void *,unsigned int *);
		virtual long ReadExpandableStringValue(unsigned short const *,HSTRING__ * *,bool *);
		virtual long ReadMultiStringValue(unsigned short const *,HSTRING__ * *);
		virtual long ReadPropertyStore(unsigned short const *,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
		virtual long ReadStringValue(unsigned short const *,HSTRING__ * *);
		virtual long ReadUInt32Value(unsigned short const *,unsigned int *);
		virtual long ReadUInt64Value(unsigned short const *,unsigned __int64 *);
		virtual long WriteBinaryValue(unsigned short const *,void const *,unsigned int);
		virtual long WriteExpandableStringValue(unsigned short const *,HSTRING__ *,bool);
		virtual long WriteMultiStringValue(unsigned short const *,HSTRING__ *);
		virtual long WritePropertyStore(unsigned short const *,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> *);
		virtual long WriteStringValue(unsigned short const *,HSTRING__ *);
		virtual long WriteUInt32Value(unsigned short const *,unsigned int);
		virtual long WriteUInt64Value(unsigned short const *,unsigned __int64);
	};

	struct RegistryKeyDataCache
	{
		RegistryKeyDataCache();
		~RegistryKeyDataCache();
	};

	struct RelativePathedRegistryKeyData
	{
		RelativePathedRegistryKeyData(RegistryKeyData *,OpaqueString const &,RegistryKeyOptions);
		virtual HSTRING__ * Name();
		virtual RegistryKeyData * Parent();
		virtual RegistryKeyOptions Options();
		virtual long Create();
		virtual long Delete();
		virtual long PrepareForRead();
		virtual ~RelativePathedRegistryKeyData();
	};

	struct UserPackageData
	{
		virtual long Create();
		virtual long Delete();
	};

	RegistrationStoreData::NullData g_NullData;
	RegistrationStoreData::PackageDataCache g_packageDataCache;
	RegistrationStoreData::RegistryKeyOptions GetRegistryKeyOptions(RegistrationStoreData::Node &);
	int CreateUniqueMountPath(unsigned short const *,_UNICODE_STRING &);
	long CreateAbsolutePathedRegistryKeyData(RegistrationStoreData::Node &,RegistrationStoreTypes::IData * *);
	long CreateAncestralRegistryKeyData(RegistrationStoreData::Node &,RegistrationStoreTypes::IData * *);
	long CreateCachedPackageData(RegistrationStoreData::Node &,RegistrationStoreTypes::IData * *);
	long CreateCachedRegistryKeyData(RegistrationStoreData::RegistryKeyDataCache &,RegistrationStoreData::Node &,RegistrationStoreTypes::IData * *);
	long CreateFactory(Windows::Foundation::RegistrationScope,void *,unsigned long,RegistrationStoreTypes::IDataFactory * *);
	long CreatePackageData(RegistrationStoreData::Node &,RegistrationStoreTypes::IData * *);
	long CreatePackageDataForMachineDeployment(bool,RegistrationStoreData::Node &,RegistrationStoreTypes::IData * *);
	long CreatePackageDataForUserDeployment(void *,RegistrationStoreData::Node &,RegistrationStoreTypes::IData * *);
	long CreateRegistryKeyData(RegistrationStoreData::Node &,RegistrationStoreTypes::IData * *);
	long CreateRegistryKeyData(RegistrationStoreData::RegistryKeyData *,RegistrationStoreData::Node &,RegistrationStoreTypes::IData * *);
	long LoadKey(HSTRING__ *,_UNICODE_STRING &,unsigned long,unsigned long,RegistryKey &);
};

struct RegistrationStoreHelper
{
	long CreateDebugInformationEntriesForPackage(unsigned short const *,unsigned short const *,unsigned short *);
	long Initialize();
	long RemoveDebugInformationForPackage(unsigned short const *);
};

class RegistryKey
{
	long ReadStringValueWorker<0>(unsigned short const *,unsigned long,HSTRING__ * *,bool *);
	long ReadStringValueWorker<256>(unsigned short const *,unsigned long,HSTRING__ * *,bool *);
	long WriteStringValueWorker(unsigned short const *,unsigned long,unsigned short const *,unsigned __int64);
	static long StaticNtCreate(HKEY__ *,_UNICODE_STRING const &,unsigned long,_SECURITY_ATTRIBUTES *,unsigned long,unsigned long *,HKEY__ * *);
	static long StaticNtOpen(HKEY__ *,_UNICODE_STRING const &,unsigned long,HKEY__ * *);
	static long StaticNtOpenCaseSensitive(HKEY__ *,_UNICODE_STRING const &,unsigned long,HKEY__ * *);
	static long StaticNtQuery<_KEY_BASIC_INFORMATION>(HKEY__ *,_KEY_BASIC_INFORMATION *,unsigned long *);
	static long StaticOpen(HKEY__ *,unsigned short const *,unsigned long,HKEY__ * *);
public:
	long EnumValue(unsigned long,unsigned short *,unsigned long *,unsigned long *,void *,unsigned long *);
	long GetValue(unsigned short const *,unsigned short const *,unsigned long,unsigned long *,void *,unsigned long *);
	long GetValue(wchar_t const *,wchar_t const *,unsigned long,unsigned long *,void *,unsigned long *);
	long NtCreate(HKEY__ *,HSTRING__ *,unsigned long,_SECURITY_ATTRIBUTES *,unsigned long,unsigned long *);
	long NtCreate(HKEY__ *,unsigned short const *,unsigned long,_SECURITY_ATTRIBUTES *,unsigned long,unsigned long *);
	long NtCreateCaseSensitive(HKEY__ *,HSTRING__ *,unsigned long,_SECURITY_ATTRIBUTES *,unsigned long,unsigned long *);
	long NtDelete();
	long NtOpen(HKEY__ *,HSTRING__ *,unsigned long);
	long NtOpen(HKEY__ *,unsigned short const *,unsigned long);
	long NtQueryValueCaseSensitive<_KEY_VALUE_BASIC_INFORMATION>(_UNICODE_STRING const &,_KEY_VALUE_BASIC_INFORMATION *,unsigned long *);
	long QueryInfo(unsigned long *,unsigned long *,unsigned long *,unsigned long *,unsigned long *,unsigned long *,_FILETIME *);
	long QueryValue(unsigned short const *,unsigned long *,void *,unsigned long *);
	long ReadDWORDValue(unsigned short const *,unsigned long *);
	long ReadUInt64Value(unsigned short const *,unsigned __int64 *);
	long SetValue(unsigned short const *,unsigned long,void const *,unsigned long);
	long WriteStringValue(unsigned short const *,bool,HSTRING__ *);
	static long DeleteKey(HKEY__ *,unsigned short const *,unsigned long,bool);
	void Close();
};

class RegistryPathWatcher
{
	long OpenDeepestExistingDecendent(RegistryKey &,unsigned short *);
	static long OpenKeyIfExists(RegistryKey &,RegistryKey const &,unsigned short const *);
public:
	bool MayHaveChanged();
	long RegisterNotification(int,unsigned long);
};

class ResourceStrings
{
	struct ResourceStringStorage
	{
		~ResourceStringStorage();
	};

	static Microsoft::WRL::Wrappers::SRWLock s_initializationLock;
	static std::unique_ptr<ResourceStrings::ResourceStringStorage,std::default_delete<ResourceStrings::ResourceStringStorage> > s_spResourceStrings;
	static unsigned short const * const s_defaultRCAccess;
	static unsigned short const * const s_defaultRCApplicationSpecific;
	static unsigned short const * const s_defaultRCDefault;
	static unsigned short const * const s_defaultRCLRPCAddress;
	static unsigned short const * const s_defaultRCLaunch;
	static unsigned short const * const s_defaultRCLaunchAndActivate;
	static unsigned short const * const s_defaultRCLimits;
	static unsigned short const * const s_defaultRCLocal;
	static unsigned short const * const s_defaultRCMachineDefault;
	static unsigned short const * const s_defaultRCRemote;
	static unsigned short const * const s_defaultRCUnavailable;
	static void LoadResourceStringAndCopyIntoHeapMemory(HINSTANCE__ *,unsigned short,std::unique_ptr<unsigned short [0],std::default_delete<unsigned short [0]> > &);
	static void LoadResourceStrings();
public:
	static unsigned short const * Access();
	static unsigned short const * ApplicationSpecific();
	static unsigned short const * Launch();
	static unsigned short const * LaunchAndActivate();
	static unsigned short const * Local();
	static unsigned short const * MachineDefault();
	static unsigned short const * Remote();
	static unsigned short const * Unavailable();
};

struct RestrictedErrorChainEnumerator
{
	RestrictedErrorChainEnumerator(IRestrictedErrorInfo *);
	void Previous(IRestrictedErrorInfo * *);
};

class RifRefBuffer
{
	void OnExceededCapacity();
public:
	tagREMINTERFACEREF * GetCursor();
	void AdvanceCursor(unsigned short);
	void Append(tagREMINTERFACEREF const &);
};

namespace Ro
{
	namespace detail
	{
		struct Sha1
		{
			long Initialize();
		};

		struct SimpleMetaDataBuffer
		{
			SimpleMetaDataBuffer();
			bool ExistsCycle(unsigned short const *);
		};

		class SimpleMetaDataBuilder
		{
			long _CommonInterfaceGroupSimple(unsigned short const *,unsigned short const *,_GUID const *);
			long _OnSet();
			long _WriteGuid(_GUID const &);
			long _WriteString(char const *);
			long _WriteType(unsigned short const * const);
			long _WriteWideString(unsigned short const *);
		public:
			long SendArguments(unsigned int,unsigned short const * const *);
			virtual long SetDelegate(_GUID);
			virtual long SetEnum(unsigned short const *,unsigned short const *);
			virtual long SetInterfaceGroupParameterizedDefault(unsigned short const *,unsigned int,unsigned short const * *);
			virtual long SetInterfaceGroupSimpleDefault(unsigned short const *,unsigned short const *,_GUID const *);
			virtual long SetParameterizedDelegate(_GUID,unsigned int);
			virtual long SetParameterizedInterface(_GUID,unsigned int);
			virtual long SetRuntimeClassParameterizedDefault(unsigned short const *,unsigned int,unsigned short const * const *);
			virtual long SetRuntimeClassSimpleDefault(unsigned short const *,unsigned short const *,_GUID const *);
			virtual long SetStruct(unsigned short const *,unsigned int,unsigned short const * const *);
			virtual long SetWinRtInterface(_GUID);
		};

		class Vec<char,256>
		{
			long _Grow(unsigned __int64);
		public:
			long Append(char);
			long Resize(unsigned __int64);
		};

		class Vec<unsigned __int64,0>
		{
			long _Grow(unsigned __int64);
		public:
			long Append(unsigned __int64);
			long Pop();
		};

		long GuidFromName(_GUID const &,void const *,unsigned long,_GUID *);
	};

};

struct RoVariant
{
	struct Accessor
	{
		long GetString(HSTRING__ * *);
		long GetUInt32(unsigned int *);
		long get_Type(Windows::Foundation::PropertyType *);
	};

	RoVariant(IInspectable *,bool);
	~RoVariant();
};

class RttiParser
{
	struct TypeNameBuffer
	{
		ObjectLibrary::OpaqueString AsString();
	};

	static bool GetRttiProperty(WinrtRtti const *,unsigned long,unsigned __int64 *);
	static bool IsWindowsFoundationType(RttiParser::TypeNameBuffer const &);
	static bool ParseOutRetvalParameter(WinrtRttiInterface_V1 const *,WinrtAsyncOperationType *,_GUID *,_GUID *,_GUID const * *,_MIDL_WINRT_TYPE_SERIALIZATION_INFO const * *,_MIDL_WINRT_TYPE_SERIALIZATION_INFO const * *,_MIDL_INTERCEPTION_INFO const * *,RttiParser::TypeNameBuffer *);
	static bool ParseOutRetvalParameter(WinrtRttiParameterizedInterfaceInstance_V1 const *,WinrtAsyncOperationType *,_GUID *,_GUID *,_GUID const * *,_MIDL_WINRT_TYPE_SERIALIZATION_INFO const * *,_MIDL_WINRT_TYPE_SERIALIZATION_INFO const * *,_MIDL_INTERCEPTION_INFO const * *,RttiParser::TypeNameBuffer *);
	static void FailFast();
	static void GetTypeName(WinrtRtti const *,RttiParser::TypeNameBuffer *);
	static void ParseDelegateInfoFromPinterfaceInstance(WinrtRttiParameterizedInterfaceInstance_V1 const *,unsigned long,unsigned short const *,_GUID const * *,_MIDL_WINRT_TYPE_SERIALIZATION_INFO const * *,_MIDL_INTERCEPTION_INFO const * *);
public:
	static bool ParseOutRetvalParameter(WinrtRtti const *,WinrtAsyncOperationType *,_GUID *,_GUID *,_GUID const * *,_MIDL_WINRT_TYPE_SERIALIZATION_INFO const * *,_MIDL_WINRT_TYPE_SERIALIZATION_INFO const * *,_MIDL_INTERCEPTION_INFO const * *,RttiParser::TypeNameBuffer *,bool);
};

struct STRING_OPAQUE
{
	static long Create(unsigned short const *,unsigned int,STRING_OPAQUE * *);
	static long s_totalStringCount;
};

struct ScmReplyInfo
{
	virtual long GetCLSID(_GUID *);
	virtual long GetRemoteReplyInfo(_REMOTE_REPLY_SCM_INFO * *);
	virtual long GetResolverInfo(_PRIV_RESOLVER_INFO * *);
	virtual long GetSize(void *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long SetRemoteReplyInfo(_REMOTE_REPLY_SCM_INFO *);
	virtual long SetResolverInfo(_PRIV_RESOLVER_INFO *);
	virtual long UnSerialize(void *);
	virtual long UnSerializeCallBack(_GUID const &,ISerializable * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~ScmReplyInfo();
	void freeRemoteReplyInfo();
	void freeResolverInfo();
};

struct ScmRequestInfo
{
	virtual long GetCLSID(_GUID *);
	virtual long GetRemoteRequestInfo(_REMOTE_REQUEST_SCM_INFO * *);
	virtual long GetScmInfo(_PRIV_SCM_INFO * *);
	virtual long GetSize(void *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long SetRemoteRequestInfo(_REMOTE_REQUEST_SCM_INFO *);
	virtual long SetScmInfo(_PRIV_SCM_INFO *);
	virtual long UnSerialize(void *);
	virtual long UnSerializeCallBack(_GUID const &,ISerializable * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~ScmRequestInfo();
	void freeRemoteRequest(_REMOTE_REQUEST_SCM_INFO *);
	void freeScmInfo(_PRIV_SCM_INFO *);
};

struct SecurityDescriptor
{
	void * Allocate(unsigned short);
	void Release();
};

class SecurityInfo
{
	long DoCoAuthIdentityFixup();
	long DoPostUnserializeCoAuthFixup();
	static void SecureStringFree(unsigned short *,unsigned __int64);
public:
	static void freeCOAUTHIDENTITY(_COAUTHIDENTITY *);
	static void freeCOSERVERINFO(_COSERVERINFO *);
	virtual long GetAuthIdentity(_COAUTHIDENTITY * *);
	virtual long GetAuthnFlags(unsigned long *);
	virtual long GetAuthnLevel(unsigned long *);
	virtual long GetAuthnSvc(unsigned long *);
	virtual long GetAuthzSvc(unsigned long *);
	virtual long GetCLSID(_GUID *);
	virtual long GetCOSERVERINFO(_COSERVERINFO * *);
	virtual long GetCapabilities(unsigned long *);
	virtual long GetImpLevel(unsigned long *);
	virtual long GetServerPrincipalName(unsigned short * *);
	virtual long GetSize(void *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long SetAuthIdentity(_COAUTHIDENTITY *);
	virtual long SetAuthnFlags(unsigned long);
	virtual long SetAuthnLevel(unsigned long);
	virtual long SetAuthnSvc(unsigned long);
	virtual long SetAuthzSvc(unsigned long);
	virtual long SetCOAUTHINFO(_COAUTHINFO *);
	virtual long SetCOSERVERINFO(_COSERVERINFO *);
	virtual long SetCapabilities(unsigned long);
	virtual long SetImpLevel(unsigned long);
	virtual long SetServerPrincipalName(unsigned short *);
	virtual long UnSerialize(void *);
	virtual long UnSerializeCallBack(_GUID const &,ISerializable * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~SecurityInfo();
};

struct SerializableProperty
{
	virtual long SetParent(ISerializableParent *);
};

struct Serializer
{
	long Commit();
	long CopyTo(Serializer *,unsigned long,unsigned long);
	long GetCopy(Serializer * *);
	long GetSizingHandle(void *);
	long InitStream(IStream *,unsigned long &,unsigned long,void * &);
	long SetPosition(unsigned long);
	long SetStream(IStream *,unsigned long,unsigned long);
	unsigned long Release();
	~Serializer();
};

class ServerCall
{
protected:
	ServerCall(ServerCall *);
	ServerCall(_GUID const &,bool,ComCallTraceActivity *,unsigned int,unsigned long,unsigned long);
	virtual ~ServerCall();
	void EnableTlsRundownMitigationIfNecessary();
	void TraceServerAsyncCallStart(_GUID const &,ServerCallTracingInfo const &);
	void TraceServerAsyncCallStop(unsigned long);
	void TraceServerSyncCallStart(ServerCallTracingInfo const &);
	void TraceServerSyncCallStop(unsigned long);
public:
	_GUID GetServerIpid();
	virtual _GUID GetDcomCausalityId();
	virtual _GUID GetPassthroughTraceActivity();
	virtual bool EnableCallTracing();
	virtual bool IsServerAsyncAbiModel();
	virtual bool IsStandardComImplementation();
	virtual bool IsWinrtAsyncCall();
	virtual bool IsWinrtAsyncMethodSyncCall();
	virtual bool NeedsUnmarshalingTlsMitigation();
	virtual bool ServerShouldUseCancelationNotification();
	virtual bool UsesThreadLocalDispatch();
	virtual long CompleteCurrentTlsRundownMitigation();
	virtual long ContextInvoke(tagRPCOLEMESSAGE *,IRpcStubBuffer *,CServerChannel *,tagIPIDEntry *,unsigned long *);
	virtual long GetInMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetOutMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long IncrementCallCount();
	virtual tagCALLCATEGORY GetCallCategory();
	virtual void * GetServerInterface();
	virtual void * GetServerObject();
	virtual void * GetServerVtable();
	virtual void AbortCurrentTlsRundownMitigation();
	virtual void DecrementCallCount();
	virtual void Finalize();
	virtual void Initialize(CStdIdentity *,bool,CObjectContext *,tagIPIDEntry *);
	virtual void OnSendingAutoRetryResponse();
	virtual void RelockServerIfNeeded();
	virtual void ReportServerFault(unsigned long);
	virtual void ReportStubInvokeFailure(long);
};

struct ServerLocationInfo
{
	virtual long GetApartment(unsigned long *);
	virtual long GetCLSID(_GUID *);
	virtual long GetContext(IObjContext * *);
	virtual long GetProcess(unsigned long *,unsigned long *);
	virtual long GetRemoteServerName(unsigned short * *);
	virtual long GetSize(void *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long SetApartment(unsigned long);
	virtual long SetContext(IObjContext *);
	virtual long SetProcess(unsigned long,unsigned long);
	virtual long SetRemoteServerName(unsigned short *);
	virtual long UnSerialize(void *);
	virtual long UnSerializeCallBack(_GUID const &,ISerializable * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~ServerLocationInfo();
};

struct ServerRegistrationEntryProperties
{
	~ServerRegistrationEntryProperties();
};

class SnapshotReport
{
	long GenerateDump(void *);
	long GenerateReport(unsigned short *);
public:
	SnapshotReport(HPSS__ *,_CONTEXT *,unsigned long,void *,_STOWED_EXCEPTION_INFORMATION_V2 * *,unsigned long,IRestrictedErrorInfo *);
	long GenerateAndSubmit();
};

struct SpecialProperties
{
	virtual long FlagClear(unsigned long);
	virtual long FlagQuery(unsigned long);
	virtual long FlagSet(unsigned long);
	virtual long GetCLSID(_GUID *);
	virtual long GetClientImpersonating(int *);
	virtual long GetDefaultAuthenticationLevel(unsigned long *);
	virtual long GetLUARunLevel(unsigned long *,unsigned __int64 *);
	virtual long GetOrigClsctx(unsigned long *);
	virtual long GetPartitionId(_GUID *);
	virtual long GetProcessRequestType(unsigned long *);
	virtual long GetServerPid(unsigned long *);
	virtual long GetServiceId(unsigned long *);
	virtual long GetSessionId(unsigned long *,int *);
	virtual long GetSessionId2(unsigned long *,int *,int *);
	virtual long GetSize(void *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long SetClientImpersonating(int);
	virtual long SetDefaultAuthenticationLevel(unsigned long);
	virtual long SetLUARunLevel(unsigned long,unsigned __int64);
	virtual long SetOrigClsctx(unsigned long);
	virtual long SetPartitionId(_GUID const &);
	virtual long SetProcessRequestType(unsigned long);
	virtual long SetServerPid(unsigned long);
	virtual long SetServiceId(unsigned long);
	virtual long SetSessionId(unsigned long,int,int);
	virtual long UnSerialize(void *);
	virtual long UnSerializeCallBack(_GUID const &,ISerializable * *);
	virtual long UnsetServerPid();
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct StackTrace
{
	static ObjectLibrary::ReferencedPtr<StackTrace> Capture(unsigned short,unsigned short);
};

namespace StackTraceDetails
{
	struct GlobalStackTraceMap
	{
		GlobalStackTraceMap();
	};

};

class StandardComClientCall
{
protected:
	long BaseGetBuffer(tagRPCOLEMESSAGE *,_GUID const &);
	long CreateTransportCallObject(tagRPCOLEMESSAGE const *,tagCALLCATEGORY,CChannelHandle *,unsigned long,tagCOMVERSION);
	static bool IsSyncVersionOfSpecialOldStyleAsyncInterface(_GUID const &);
	virtual _GUID GetDcomCausalityId();
	virtual _GUID GetTargetInterface();
	virtual bool NeedsUnmarshalingTlsMitigation();
	virtual unsigned short GetProcNum();
	virtual ~StandardComClientCall();
public:
	virtual CCtxCall * ObsoleteGetClientCtxCall();
	virtual long Cancel(tagRPCOLEMESSAGE *);
	virtual long CheckSystemHandleLeak();
	virtual long CleanupAllSystemHandles();
	virtual long GetBuffer(tagRPCOLEMESSAGE *,_GUID const &);
	virtual long GetDestCtxEx(tagRPCOLEMESSAGE const *,unsigned long *,void * *);
	virtual long GetInMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetOutMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetState(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long GetSystemHandle(unsigned long,unsigned char,unsigned long,void * *);
	virtual long Initialize(tagRPCOLEMESSAGE const *,tagCALLCATEGORY,CChannelHandle *,unsigned long,tagCOMVERSION,_GUID const &,ClientCallTracingInfo const &);
	virtual long NegotiateSyntax(tagRPCOLEMESSAGE *);
	virtual long SetSystemHandle(void *,unsigned char,unsigned long,unsigned long *);
	virtual void Finalize(tagRPCOLEMESSAGE *);
	virtual void OnSourceOfClientHResultIdentified(SourceOfClientHResult);
	virtual void OnTransportCallCanceled();
	virtual void OnTransportCallFailed(long);
};

class StandardComServerCall
{
	static void (* ServerCancelationCallbackTestHook)();
protected:
	StandardComServerCall(StandardComServerCall *);
	virtual _GUID GetServerIpidFromTransport();
	virtual ~StandardComServerCall();
	void SubscribeServerTransportCallEvents();
	void UnsubscribeServerTransportCallEventsIfNeeded();
public:
	virtual CMessageCall * GetTransportCall();
	virtual _GUID GetDcomCausalityId();
	virtual _GUID GetTargetInterface();
	virtual bool IsMachineLocal();
	virtual bool IsProcessLocal();
	virtual bool IsStandardComImplementation();
	virtual bool NeedsUnmarshalingTlsMitigation();
	virtual bool ServerShouldUseCancelationNotification();
	virtual long CanDispatch();
	virtual long CheckSystemHandleLeak();
	virtual long CleanupAllSystemHandles();
	virtual long GetBuffer(tagRPCOLEMESSAGE *,_GUID const &);
	virtual long GetBuffer2(tagRPCOLEMESSAGE *);
	virtual long GetCallContext(tagRPCOLEMESSAGE *,_GUID const &,void * *);
	virtual long GetDestCtxEx(tagRPCOLEMESSAGE const *,unsigned long *,void * *);
	virtual long GetInMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetOutMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetState(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long GetSystemHandle(unsigned long,unsigned char,unsigned long,void * *);
	virtual long IsFromRpcss(bool *);
	virtual long SetSystemHandle(void *,unsigned char,unsigned long,unsigned long *);
	virtual tagCALLCATEGORY GetCallCategory();
	virtual unsigned short GetProcNum();
	virtual void Finalize();
	virtual void Initialize(CStdIdentity *,bool,CObjectContext *,tagIPIDEntry *);
	virtual void OnServerAsyncCallCanceled();
	virtual void SetContainerId(_GUID const *);
};

struct StringCache
{
	void TryPutValue(unsigned __int64,unsigned short const *);
};

struct SyncClientCallRetryContext
{
	int IsTimerAtZero();
	long SendReceiveWithRetry(tagRPCOLEMESSAGE *,unsigned long *,ClientCall *,bool *);
	unsigned long TicksToWait();
	virtual unsigned long NoTimerTicksToWait();
};

struct SyncServerCall
{
	virtual bool IsWinrtAsyncMethodSyncCall();
	virtual bool UsesThreadLocalDispatch();
	virtual long RegisterAsync(tagRPCOLEMESSAGE *);
	virtual long Send(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long StubInvoke(IRpcChannelBuffer *,IRpcStubBuffer *,unsigned long *);
	virtual void TraceServerCallStart(ServerCallTracingInfo const &);
	virtual void TraceServerCallStop(unsigned long);
};

struct ThreadCallObjectCache
{
	ThreadCallObjectCache();
	static ThreadCallObjectCache * GetOrCreate();
	~ThreadCallObjectCache();
};

struct TickCountTimer
{
	unsigned long GetRemainingTicks();
};

class UnmarshalerCLSIDInfo
{
	void LogPolicyCheckFailed(UnmarshalingPolicyCheckReason);
public:
	long CheckAllowedByPolicy(EffectiveUnmarshalingPolicy,UnmarshalingPolicyCheckReason);
	long Lookup(bool,bool);
	void Memoize();
};

class UnmarshalersTable
{
	UnmarshalersTable::Entry * FindOrCreateEntry(_GUID const &,bool);
public:
	UnmarshalersTable();
	long AddPerProcessAllowedEntry(_GUID const &);
	void LookupEntry(_GUID const &,bool *,bool *,bool *,bool *,bool *);
	void MemoizeEntry(_GUID const &,bool,bool,bool,bool);
};

struct UnusedCachedFactories
{
	long ReleaseAll();
};

struct UserContextProperties
{
	virtual long GetCLSID(_GUID *);
	virtual long GetSize(void *,unsigned long *);
	virtual long GetUserContext(unsigned __int64 *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long SetUserContext(unsigned __int64);
	virtual long UnSerialize(void *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct WaitableCount
{
	void WaitForValue(unsigned long);
};

namespace WinRT
{
	namespace Metadata
	{
		namespace Marshaling
		{
			class AllocationTracker
			{
				static Microsoft::WRL::Wrappers::CriticalSection allocationLock;
				static ObjectLibrary::ReferencedPtr<AllocationTracker> allocationTracker;
			public:
				long TrackAllocation(ObjectLibrary::OpaqueString const &);
				static long TrackAllocation(unsigned short const *);
				static long TrackFree(unsigned short const *);
			};

			struct CMetadataProxy<MetadataFormatStringDataSource<DefaultMetadataFormatStringSourceHelper> >
			{
				CMetadataProxy<MetadataFormatStringDataSource<DefaultMetadataFormatStringSourceHelper> >();
				long RuntimeClassInitialize(_GUID const &,ObjectLibrary::OpaqueString const &,IUnknown *,TypeCache *);
				virtual long Connect(IRpcChannelBuffer *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual void Disconnect();
				virtual ~CMetadataProxy<MetadataFormatStringDataSource<DefaultMetadataFormatStringSourceHelper> >();
			};

			class CMetadataProxyStubFactory<MetadataFormatStringDataSource<DefaultMetadataFormatStringSourceHelper> >
			{
				long CreateProxyStubHelper<ProxyAccessor<MetadataFormatStringDataSource<DefaultMetadataFormatStringSourceHelper> > >(_GUID const &,IUnknown *,IRpcProxyBuffer * *);
				long CreateProxyStubHelper<StubAccessor<MetadataFormatStringDataSource<DefaultMetadataFormatStringSourceHelper> > >(_GUID const &,IUnknown *,IRpcStubBuffer * *);
			public:
				CMetadataProxyStubFactory<MetadataFormatStringDataSource<DefaultMetadataFormatStringSourceHelper> >();
				virtual long CreateProxy(IUnknown *,_GUID const &,IRpcProxyBuffer * *,void * *);
				virtual long CreateStub(_GUID const &,IUnknown *,IRpcStubBuffer * *);
				virtual long GetInterfaceName(_GUID const &,HSTRING__ * *);
				virtual long SetFactoryClassName(HSTRING__ *);
				virtual long SetInterfaceName(_GUID const &,HSTRING__ *);
			};

			struct CMetadataStub<MetadataFormatStringDataSource<DefaultMetadataFormatStringSourceHelper> >
			{
				CMetadataStub<MetadataFormatStringDataSource<DefaultMetadataFormatStringSourceHelper> >();
				long RuntimeClassInitialize(_GUID const &,ObjectLibrary::OpaqueString const &,IUnknown *,TypeCache *);
				virtual IRpcStubBuffer * IsIIDSupported(_GUID const &);
				virtual long Connect(IUnknown *);
				virtual long DebugServerQueryInterface(void * *);
				virtual long Invoke(tagRPCOLEMESSAGE *,IRpcChannelBuffer *);
				virtual unsigned long CountRefs();
				virtual void DebugServerRelease(void *);
				virtual void Disconnect();
			};

			class DefaultMetadataFormatStringSourceHelper
			{
				static long GetInterfaceName(ObjectLibrary::ReferencedElsewherePtr<TypeResolver>,_GUID const &,HSTRING__ * *);
				static long GetTypeNameFromRegistry(ObjectLibrary::ReferencedElsewherePtr<TypeResolver>,_GUID const *,ObjectLibrary::OpaqueString &);
				static long SetInterfaceName(ObjectLibrary::ReferencedElsewherePtr<TypeResolver>,_GUID const &,HSTRING__ *);
			public:
				static long GetTypeNameFromIID<1>(ObjectLibrary::ReferencedElsewherePtr<TypeResolver>,_GUID const *,ObjectLibrary::OpaqueString const &,IUnknown *,ObjectLibrary::OpaqueString &);
				static long GetTypeResolver(ObjectLibrary::ReferencedPtr<TypeResolver> &);
				static long SetInterfaceName(_GUID const &,HSTRING__ *);
				static long UnmangleIdlName(long,wchar_t *);
			};

			namespace MbmTelemetry
			{
				class CreateProxy
				{
				protected:
					virtual bool WasAlreadyReportedToTelemetry(long);
					virtual void StopActivity();
				public:
					void StartActivity(_GUID);
					~CreateProxy();
				};

				class CreateStub
				{
				protected:
					virtual bool WasAlreadyReportedToTelemetry(long);
					virtual void StopActivity();
				public:
					void StartActivity(_GUID);
					~CreateStub();
				};

				class GetTypeInformation
				{
					GetTypeInformation<_GUID const &>(wistd::integral_constant<char,0>,_GUID const &);
				protected:
					virtual bool WasAlreadyReportedToTelemetry(long);
					virtual void StopActivity();
				public:
					static void GenerateNdrStrings();
					static void ReturnFormatStrings();
					void StartActivity(_GUID);
					~GetTypeInformation();
				};

			};

			struct MetadataArray
			{
				MetadataArray(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataType> const &);
				long SetLengthParameterIndex(unsigned long);
				long SetLengthParameterType(ObjectLibrary::ReferencedElsewherePtr<MetadataType> const &);
				long SetRangeParameter(unsigned long,unsigned long);
				long SetSizeParameterIndex(unsigned long);
				static long CategorizeArray(ObjectLibrary::ReferencedElsewherePtr<MetadataType> const &,MethodParameterInfo,MetadataArray::ArrayCategory &);
				static long NameFromToken(ObjectLibrary::OpaqueString const &,ObjectLibrary::OpaqueString &);
				virtual bool IsArrayType();
				virtual bool IsComplex();
				virtual bool IsForcedComplex(TypeRegistry *);
				virtual bool MustSize();
				virtual bool NeedsCorrCheck();
				virtual long CreateTypeFormatString(TypeRegistry *,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
				virtual long GenerateNdrProcEntry(ParameterListEntry const * const,TypeRegistry &,NDRFormatString<ProcFormatString> &);
				virtual long Initialize();
				virtual unsigned long Alignment();
				virtual unsigned long BufferSize();
				virtual unsigned long Size();
				virtual unsigned long WireAlignment();
				virtual wchar_t const * WinRTName();
			};

			struct MetadataBaseType
			{
				MetadataBaseType(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,unsigned char);
				virtual bool IsComplex();
				virtual bool IsForcedComplex(TypeRegistry *);
				virtual bool IsStringType();
				virtual bool MustSize();
				virtual bool NeedsCorrCheck();
				virtual long CreateTypeFormatString(TypeRegistry *,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
				virtual long GenerateNdrProcEntry(ParameterListEntry const * const,TypeRegistry &,NDRFormatString<ProcFormatString> &);
				virtual long Initialize();
				virtual unsigned long Alignment();
				virtual unsigned long BufferSize();
				virtual unsigned long Size();
				virtual unsigned long WireAlignment();
				virtual wchar_t const * WinRTName();
			};

			class MetadataClass
			{
				long DecodeSerString(unsigned char const *,unsigned long,ObjectLibrary::OpaqueString &);
			public:
				MetadataClass(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope>,unsigned int);
				virtual bool IsComplex();
				virtual bool IsForcedComplex(TypeRegistry *);
				virtual bool MustSize();
				virtual bool NeedsCorrCheck();
				virtual long CreateTypeFormatString(TypeRegistry *,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
				virtual long GenerateNdrProcEntry(ParameterListEntry const * const,TypeRegistry &,NDRFormatString<ProcFormatString> &);
				virtual long GetTypeNameForIid(_GUID const *,ObjectLibrary::OpaqueString &);
				virtual long Initialize();
				virtual unsigned long Alignment();
				virtual unsigned long BufferSize();
				virtual unsigned long Size();
				virtual unsigned long WireAlignment();
				virtual void UpdatePInterfaceBuilder(IRoSimpleMetaDataBuilder &);
				virtual wchar_t const * WinRTName();
			};

			class MetadataConverter
			{
				bool HasRangeAttribute(ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,unsigned int,std::tuple<unsigned long,unsigned long> *);
				long AddArraySizeParameter(ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,MetadataArray::ArrayCategory,bool,std::tuple<unsigned long,unsigned long> const &,Containers::Intrusive::List<ParameterListEntry,0> &);
				long AddMethodParametersToFormatString(Containers::Intrusive::List<ParameterListEntry,0> const &);
				long CacheParamTypeName(ObjectLibrary::ReferencedElsewherePtr<MetadataType>);
				long ProcessArrayParameter(ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,unsigned int,std::unique_ptr<ParameterListEntry,std::default_delete<ParameterListEntry> > const &);
				long ProcessMethodParameter(ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,unsigned int,unsigned long,unsigned long &,unsigned char const *,unsigned long,unsigned long *,Containers::Intrusive::List<ParameterListEntry,0> &);
				long ProcessReturnValueParameter(ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,unsigned int,unsigned char const *,unsigned long,unsigned long *,bool *,std::tuple<unsigned long,unsigned long> *,std::unique_ptr<ParameterListEntry,std::default_delete<ParameterListEntry> > &);
				unsigned short GetFloatArgMask(Containers::Intrusive::List<ParameterListEntry,0> const &);
				void CalculateMethodSizeInfoForMethod(Containers::Intrusive::List<ParameterListEntry,0> const &,MetadataConverter::MethodSizeInfo *);
			protected:
				long ConvertMetadataMethod(unsigned int,unsigned short);
				long GenerateMethodParameters(ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,unsigned int,Containers::Intrusive::List<ParameterListEntry,0> &);
			public:
				MetadataConverter(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::OpaqueString const &);
				long GenerateNdrStringsForInterface();
				long Initialize();
				~MetadataConverter();
			};

			struct MetadataDelegate
			{
				MetadataDelegate(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope>,unsigned int);
				virtual bool IsDelegate();
				virtual long GetTypeNameForIid(_GUID const *,ObjectLibrary::OpaqueString &);
				virtual long Initialize();
				virtual long ShouldIncludeMethod(unsigned int,bool *);
				virtual void UpdatePInterfaceBuilder(IRoSimpleMetaDataBuilder &);
				virtual wchar_t const * WinRTName();
			};

			struct MetadataEnum
			{
				MetadataEnum(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,unsigned int);
				virtual bool IsComplex();
				virtual bool IsForcedComplex(TypeRegistry *);
				virtual bool NeedsCorrCheck();
				virtual long CreateTypeFormatString(TypeRegistry *,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
				virtual long GenerateNdrProcEntry(ParameterListEntry const * const,TypeRegistry &,NDRFormatString<ProcFormatString> &);
				virtual long Initialize();
				virtual unsigned long Alignment();
				virtual unsigned long BufferSize();
				virtual unsigned long Size();
				virtual unsigned long WireAlignment();
				virtual void UpdatePInterfaceBuilder(IRoSimpleMetaDataBuilder &);
				virtual wchar_t const * WinRTName();
			};

			struct MetadataFormatStringDataSource<DefaultMetadataFormatStringSourceHelper>
			{
				static long GetTypeInformation(_GUID const *,ObjectLibrary::OpaqueString const &,IUnknown *,TypeInformation *);
			};

			struct MetadataGuid
			{
				MetadataGuid(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &);
				long AppendField(unsigned char);
				virtual bool IsComplex();
				virtual bool IsForcedComplex(TypeRegistry *);
				virtual bool IsHomogeneous(unsigned char);
				virtual long CreateTypeFormatString(TypeRegistry *,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
				virtual long Initialize();
				virtual unsigned long Alignment();
				virtual unsigned long BufferSize();
				virtual unsigned long Size();
				virtual unsigned long WireAlignment();
				virtual wchar_t const * WinRTName();
			};

			struct MetadataInterface
			{
				MetadataInterface(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope>,unsigned int);
				MetadataInterface(_GUID const &);
				virtual long GetTypeNameForIid(_GUID const *,ObjectLibrary::OpaqueString &);
				virtual long ShouldIncludeMethod(unsigned int,bool *);
			};

			struct MetadataInterfaceBase
			{
				virtual _GUID * GetInterfaceId();
				virtual bool IsComplex();
				virtual bool IsDelegate();
				virtual bool IsForcedComplex(TypeRegistry *);
				virtual bool IsPInterface();
				virtual bool MustSize();
				virtual bool NeedsCorrCheck();
				virtual long CreateTypeFormatString(TypeRegistry *,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
				virtual long GenerateNdrProcEntry(ParameterListEntry const * const,TypeRegistry &,NDRFormatString<ProcFormatString> &);
				virtual long GetNumberOfMethods(unsigned long *);
				virtual unsigned long Alignment();
				virtual unsigned long BufferSize();
				virtual unsigned long Size();
				virtual unsigned long WireAlignment();
				virtual void UpdatePInterfaceBuilder(IRoSimpleMetaDataBuilder &);
				virtual wchar_t const * WinRTName();
			};

			struct MetadataLocator
			{
				virtual long Locate(wchar_t const *,IRoSimpleMetaDataBuilder &);
			};

			struct MetadataPInterface
			{
				MetadataPInterface(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope>,unsigned int);
				virtual bool IsDelegate();
				virtual long Initialize();
				virtual long ShouldIncludeMethod(unsigned int,bool *);
				virtual void UpdatePInterfaceBuilder(IRoSimpleMetaDataBuilder &);
			};

			struct MetadataPInterfaceInstance
			{
				MetadataPInterfaceInstance(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope>,unsigned int);
				long SetParameters(Containers::Intrusive::List<TypeListEntry,8> const &);
				virtual ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const Scope();
				virtual _GUID * GetInterfaceId();
				virtual bool IsDelegate();
				virtual bool IsPInterface();
				virtual long GetNumberOfMethods(unsigned long *);
				virtual long GetTypeNameForIid(_GUID const *,ObjectLibrary::OpaqueString &);
				virtual long Initialize();
				virtual long ShouldIncludeMethod(unsigned int,bool *);
				virtual unsigned int const Token();
				virtual void UpdatePInterfaceBuilder(IRoSimpleMetaDataBuilder &);
				virtual wchar_t const * WinRTName();
				void SetGenericType(ObjectLibrary::ReferencedElsewherePtr<MetadataType> const &);
			};

			struct MetadataPointer
			{
				MetadataPointer(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedPtr<MetadataType> const &);
				static long NameFromToken(ObjectLibrary::OpaqueString const &,ObjectLibrary::OpaqueString &);
				virtual bool IsArrayType();
				virtual bool IsComplex();
				virtual bool IsForcedComplex(TypeRegistry *);
				virtual bool MustSize();
				virtual bool NeedsCorrCheck();
				virtual long CreateTypeFormatString(TypeRegistry *,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
				virtual long GenerateNdrProcEntry(ParameterListEntry const * const,TypeRegistry &,NDRFormatString<ProcFormatString> &);
				virtual long Initialize();
				virtual unsigned long Alignment();
				virtual unsigned long BufferSize();
				virtual unsigned long Size();
				virtual unsigned long WireAlignment();
				virtual wchar_t const * WinRTName();
			};

			struct MetadataRange
			{
				MetadataRange(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedPtr<MetadataType> const &,unsigned long,unsigned long);
				virtual bool IsComplex();
				virtual bool IsForcedComplex(TypeRegistry *);
				virtual bool IsStringType();
				virtual bool MustSize();
				virtual bool NeedsCorrCheck();
				virtual long CreateTypeFormatString(TypeRegistry *,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
				virtual long GenerateNdrProcEntry(ParameterListEntry const * const,TypeRegistry &,NDRFormatString<ProcFormatString> &);
				virtual long Initialize();
				virtual unsigned long Alignment();
				virtual unsigned long BufferSize();
				virtual unsigned long Size();
				virtual unsigned long WireAlignment();
				virtual wchar_t const * WinRTName();
			};

			class MetadataScope
			{
				long ResolveTypeSpec(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,unsigned int,ObjectLibrary::OpaqueString &);
			public:
				CInterfaceImplEnumerator EnumInterfaceImpls(unsigned int);
				CMethodEnumerator EnumMethods(unsigned int);
				CTypeFieldEnumerator EnumTypeFields(unsigned int);
				long GetMethodProps(unsigned int,unsigned int *,wchar_t *,unsigned long,unsigned long *,unsigned long *,unsigned char const * *,unsigned long *,unsigned long *,unsigned long *);
				long GetTypeDefProps(unsigned int,wchar_t *,unsigned long,unsigned long *,unsigned long *,unsigned int *);
				long NameFromToken(ObjectLibrary::ReferencedElsewherePtr<TypeResolver>,unsigned int,ObjectLibrary::OpaqueString &);
				static long CreateScope(Microsoft::WRL::ComPtr<IMetaDataImport2>,ObjectLibrary::ReferencedPtr<MetadataScope> &);
			};

			struct MetadataStruct
			{
				MetadataStruct(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope>,unsigned int);
				virtual long Initialize();
			};

			class MetadataStructBase
			{
				long PadStructFieldToAlign(TypeRegistry *,unsigned long);
				long RegisterStructEmbeddedFields(TypeRegistry *);
				long RegisterStructField(ObjectLibrary::ReferencedElsewherePtr<MetadataType> const &,TypeRegistry *,unsigned long &);
			public:
				MetadataStructBase(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope>,unsigned int);
				virtual bool IsComplex();
				virtual bool IsForcedComplex(TypeRegistry *);
				virtual bool IsHomogeneous(unsigned char);
				virtual bool IsStruct();
				virtual bool MustSize();
				virtual bool NeedsCorrCheck();
				virtual long CreateTypeFormatString(TypeRegistry *,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
				virtual long GenerateNdrProcEntry(ParameterListEntry const * const,TypeRegistry &,NDRFormatString<ProcFormatString> &);
				virtual long Initialize();
				virtual unsigned long Alignment();
				virtual unsigned long BufferSize();
				virtual unsigned long Size();
				virtual unsigned long WireAlignment();
				virtual void UpdatePInterfaceBuilder(IRoSimpleMetaDataBuilder &);
				virtual wchar_t const * WinRTName();
			};

			class MetadataType
			{
			protected:
				static long CreateParameterizedInterface(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,HSTRING__ * const *,unsigned long,ObjectLibrary::ReferencedPtr<MetadataType> &,unsigned long *);
				static long CreateType(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,MetadataConverter const * const,ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,unsigned char const *,unsigned long,unsigned long *,ObjectLibrary::ReferencedPtr<MetadataType> &);
				static long CreateType(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,unsigned int,ObjectLibrary::ReferencedPtr<MetadataType> &);
				static long NameFromSignature(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,MetadataConverter const * const,ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,unsigned char const *,unsigned long,unsigned long *,ObjectLibrary::OpaqueString &);
			public:
				MetadataType(MetadataType::ObjectType,ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,unsigned int);
				PARAM_ATTRIBUTES GetParamAttributes(ParameterListEntry const * const);
				static ObjectLibrary::ReferencedPtr<MetadataType> CreateObjectType();
				virtual ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const Scope();
				virtual bool IsArrayType();
				virtual bool IsStringType();
				virtual bool IsStruct();
				virtual bool MustSize();
				virtual long GetTypeNameForIid(_GUID const *,ObjectLibrary::OpaqueString &);
				virtual long Initialize();
				virtual unsigned int const Token();
				virtual void UpdatePInterfaceBuilder(IRoSimpleMetaDataBuilder &);
				virtual ~MetadataType();
			};

			struct MetadataUnknown
			{
				MetadataUnknown(ObjectLibrary::ReferencedElsewherePtr<TypeResolver> const &,ObjectLibrary::ReferencedElsewherePtr<MetadataScope>,unsigned int);
				virtual bool IsComplex();
				virtual bool IsForcedComplex(TypeRegistry *);
				virtual bool NeedsCorrCheck();
				virtual long CreateTypeFormatString(TypeRegistry *,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
				virtual long GenerateNdrProcEntry(ParameterListEntry const * const,TypeRegistry &,NDRFormatString<ProcFormatString> &);
				virtual unsigned long Alignment();
				virtual unsigned long BufferSize();
				virtual unsigned long Size();
				virtual unsigned long WireAlignment();
				virtual void UpdatePInterfaceBuilder(IRoSimpleMetaDataBuilder &);
				virtual wchar_t const * WinRTName();
			};

			class NDRFormatString<ProcFormatString>
			{
				struct Cursor
				{
					Cursor();
				};

				long _GrowBuffer();
			public:
				long Initialize();
				long add_byte(unsigned char);
				long add_short(unsigned short);
			};

			class NDRFormatString<TypeFormatString>
			{
				struct Cursor
				{
					void SetReservedCursorPosition(Cursor const &);
				};

				long _GrowBuffer();
			public:
				long add_byte(unsigned char);
				long add_long(unsigned long);
				long add_short(unsigned short);
			};

			struct ParameterListEntry
			{
				ParameterListEntry(ObjectLibrary::ReferencedElsewherePtr<MetadataType> const &,MethodParameterInfo);
				long SetSizeParameter(unsigned long);
				unsigned short StackSize();
			};

			class ProxyStubBuilder
			{
				static long BuildMetadataVtbl(TypeInformation const *,wistd::unique_ptr<MetadataVtbl,RpcDeleter> &);
				static long BuildProxyVtbl(TypeInformation const *,MetadataVtbl *);
			public:
				static long BuildProxy(TypeInformation const *,IUnknown *,IRpcProxyBuffer * *,void * *);
				static long BuildStub(TypeInformation const *,IUnknown *,IRpcStubBuffer * *);
			};

			struct TypeCache
			{
				TypeCache();
				bool IsKnownFailedIID(_GUID const &);
				long AddFailedIID(_GUID const &);
				long Find(_GUID const *,ObjectLibrary::ReferencedPtr<TypeInformation> *);
				virtual ~TypeCache();
			};

			struct TypeListEntry
			{
				static void Deallocate(TypeListEntry *);
			};

			class TypeRegistry
			{
				long RegisterType(ObjectLibrary::OpaqueString const &,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
			public:
				long Initialize();
				long RegisterType(ObjectLibrary::ReferencedElsewherePtr<MetadataType> const &,MethodParameterInfo,NDRFormatString<TypeFormatString>::Cursor *);
			};

			struct TypeResolver
			{
				TypeResolver();
				bool FindType(ObjectLibrary::OpaqueString const &,ObjectLibrary::ReferencedPtr<MetadataType> &);
				long AddInterface(_GUID const &,ObjectLibrary::OpaqueString &);
				long HasInterface(_GUID const &,bool &);
				long InsertType(ObjectLibrary::OpaqueString const &,ObjectLibrary::ReferencedElsewherePtr<MetadataType> const &);
				long LookupInterface(_GUID const &,ObjectLibrary::OpaqueString &);
				long ResolveType(MetadataConverter const * const,ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,unsigned char const *,unsigned long,unsigned long *,ObjectLibrary::ReferencedPtr<MetadataType> &);
				virtual long Initialize();
				virtual long ResolveType(ObjectLibrary::OpaqueString const &,ObjectLibrary::ReferencedPtr<MetadataType> &);
				virtual long ResolveType(unsigned int,ObjectLibrary::ReferencedElsewherePtr<MetadataScope> const &,ObjectLibrary::ReferencedPtr<MetadataType> &);
			};

			Marshaling::Element_Map const * const ElementMap;
			Microsoft::WRL::Wrappers::CriticalSection getTypeNameFromIIDLock;
			Microsoft::WRL::Wrappers::CriticalSection typeInformationLock;
			Microsoft::WRL::Wrappers::CriticalSection typeResolverLock;
			ObjectLibrary::ReferencedPtr<Marshaling::TypeResolver> spTypeResolver;
			int OpenInterfaceRegistryKey(_GUID const &,RegistryKey &);
			long GetTypeNameFromRegistrationStore(_GUID const *,unsigned __int64,wchar_t *);
			long UnmangleNormalTypeName(unsigned __int64 &,wchar_t * &,unsigned __int64 &,wchar_t * &);
			unsigned long ReleaseProxyBuffer(IRpcProxyBuffer *);
			unsigned long ReleaseStubBuffer(IRpcStubBuffer *);
			wchar_t const * const ArrayEpilogString;
			wchar_t const * const ArrayPreambleString;
			wchar_t const * const PointerEpilogString;
			wchar_t const * const PointerPreambleString;
		};

	};

};

struct WinRTActivationProperties
{
	virtual long GetActivatableClassId(HSTRING__ * *);
	virtual long GetCLSID(_GUID *);
	virtual long GetPackageFullName(HSTRING__ * *);
	virtual long GetSize(void *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SerializableQueryInterface(_GUID const &,void * *);
	virtual long Serialize(void *);
	virtual long SetActivatableClassId(HSTRING__ *);
	virtual long SetPackageFullName(HSTRING__ *);
	virtual long UnSerialize(void *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

namespace Windows
{
	namespace Foundation
	{
		namespace Collections
		{
			namespace Detail
			{
				long _IteratorGetMany<IIterator_impl<HSTRING__ *,1>,HSTRING__ *>(IIterator_impl<HSTRING__ *,1> *,unsigned int,HSTRING__ * *,unsigned int *);
				long _IteratorGetMany<IIterator_impl<IExtensionRegistration *,1>,IExtensionRegistration *>(IIterator_impl<IExtensionRegistration *,1> *,unsigned int,IExtensionRegistration * *,unsigned int *);
				long _IteratorGetMany<IIterator_impl<IKeyValuePair<HSTRING__ *,IInspectable *> *,1>,IKeyValuePair<HSTRING__ *,IInspectable *> *>(IIterator_impl<IKeyValuePair<HSTRING__ *,IInspectable *> *,1> *,unsigned int,IKeyValuePair<HSTRING__ *,IInspectable *> * *,unsigned int *);
				long _IteratorGetMany<IIterator_impl<IKeyValuePair<HSTRING__ *,unsigned char> *,1>,IKeyValuePair<HSTRING__ *,unsigned char> *>(IIterator_impl<IKeyValuePair<HSTRING__ *,unsigned char> *,1> *,unsigned int,IKeyValuePair<HSTRING__ *,unsigned char> * *,unsigned int *);
				long _IteratorGetMany<IIterator_impl<IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *,1>,IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *>(IIterator_impl<IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *,1> *,unsigned int,IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *,unsigned int *);
				long _IteratorGetMany<IIterator_impl<IKeyValuePair<_GUID,HSTRING__ *> *,1>,IKeyValuePair<_GUID,HSTRING__ *> *>(IIterator_impl<IKeyValuePair<_GUID,HSTRING__ *> *,1> *,unsigned int,IKeyValuePair<_GUID,HSTRING__ *> * *,unsigned int *);
				long _IteratorGetMany<IIterator_impl<IKeyValuePair<_GUID,bool> *,1>,IKeyValuePair<_GUID,bool> *>(IIterator_impl<IKeyValuePair<_GUID,bool> *,1> *,unsigned int,IKeyValuePair<_GUID,bool> * *,unsigned int *);
				long _IteratorGetMany<IIterator_impl<IKeyValuePair<unsigned int,HSTRING__ *> *,1>,IKeyValuePair<unsigned int,HSTRING__ *> *>(IIterator_impl<IKeyValuePair<unsigned int,HSTRING__ *> *,1> *,unsigned int,IKeyValuePair<unsigned int,HSTRING__ *> * *,unsigned int *);
				long _VectorGetMany<IVectorView_impl<HSTRING__ *,1>,HSTRING__ *>(IVectorView_impl<HSTRING__ *,1> *,unsigned int,unsigned int,HSTRING__ * *,unsigned int *);
				long _VectorGetMany<IVector_impl<HSTRING__ *,1>,HSTRING__ *>(IVector_impl<HSTRING__ *,1> *,unsigned int,unsigned int,HSTRING__ * *,unsigned int *);
				long _VectorReplaceAll<IVector_impl<HSTRING__ *,1>,HSTRING__ *>(IVector_impl<HSTRING__ *,1> *,unsigned int,HSTRING__ * *);
				void _Cleanup<unsigned int>(HSTRING__ * *,unsigned int);
			};

			struct IIterator_impl<HSTRING__ *,1>
			{
				virtual long GetMany(unsigned int,HSTRING__ * *,unsigned int *);
			};

			struct IIterator_impl<IExtensionRegistration *,1>
			{
				virtual long GetMany(unsigned int,IExtensionRegistration * *,unsigned int *);
			};

			struct IIterator_impl<IKeyValuePair<HSTRING__ *,IInspectable *> *,1>
			{
				virtual long GetMany(unsigned int,IKeyValuePair<HSTRING__ *,IInspectable *> * *,unsigned int *);
			};

			struct IIterator_impl<IKeyValuePair<HSTRING__ *,unsigned char> *,1>
			{
				virtual long GetMany(unsigned int,IKeyValuePair<HSTRING__ *,unsigned char> * *,unsigned int *);
			};

			struct IIterator_impl<IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *,1>
			{
				virtual long GetMany(unsigned int,IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *,unsigned int *);
			};

			struct IIterator_impl<IKeyValuePair<_GUID,HSTRING__ *> *,1>
			{
				virtual long GetMany(unsigned int,IKeyValuePair<_GUID,HSTRING__ *> * *,unsigned int *);
			};

			struct IIterator_impl<IKeyValuePair<_GUID,bool> *,1>
			{
				virtual long GetMany(unsigned int,IKeyValuePair<_GUID,bool> * *,unsigned int *);
			};

			struct IIterator_impl<IKeyValuePair<unsigned int,HSTRING__ *> *,1>
			{
				virtual long GetMany(unsigned int,IKeyValuePair<unsigned int,HSTRING__ *> * *,unsigned int *);
			};

			struct IVectorView_impl<HSTRING__ *,1>
			{
				virtual long GetMany(unsigned int,unsigned int,HSTRING__ * *,unsigned int *);
			};

			struct IVector_impl<HSTRING__ *,1>
			{
				virtual long GetMany(unsigned int,unsigned int,HSTRING__ * *,unsigned int *);
				virtual long ReplaceAll(unsigned int,HSTRING__ * *);
			};

			namespace Internal
			{
				class HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > >
				{
					class Iterator
					{
						long EnsureVersionMatches();
					public:
						Iterator(HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetMany(unsigned int,IKeyValuePair<HSTRING__ *,IInspectable *> * * const,unsigned int *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,IInspectable *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class View
					{
						long EnsureVersionMatches();
					public:
						View(HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > > *,DefaultEqualityPredicate<HSTRING__ *>);
						virtual long First(IIterator<IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(HSTRING__ *,unsigned char *);
						virtual long Lookup(HSTRING__ *,IInspectable * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<HSTRING__ *,IInspectable *> * *,IMapView<HSTRING__ *,IInspectable *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					static void _Free(XWinRT::XHashMap<HSTRING__ *,IInspectable *,HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,XWinRT::CElementTraits<IInspectable *> > *);
					void _EraseAll(XWinRT::XHashMap<HSTRING__ *,IInspectable *,HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,XWinRT::CElementTraits<IInspectable *> > *);
				public:
					HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > >(DefaultHash<HSTRING__ *> const &,DefaultEqualityPredicate<HSTRING__ *> const &,HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > >::permission);
					static long Make(DefaultHash<HSTRING__ *> const &,DefaultEqualityPredicate<HSTRING__ *> const &,HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > > * *);
					virtual long Clear();
					virtual long First(IIterator<IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IMapView<HSTRING__ *,IInspectable *> * *);
					virtual long HasKey(HSTRING__ *,unsigned char *);
					virtual long Insert(HSTRING__ *,IInspectable *,unsigned char *);
					virtual long Lookup(HSTRING__ *,IInspectable * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Remove(HSTRING__ *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >
				{
					class Iterator
					{
						long EnsureVersionMatches();
					public:
						Iterator(HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetMany(unsigned int,IKeyValuePair<HSTRING__ *,IInspectable *> * * const,unsigned int *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,IInspectable *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class View
					{
						long EnsureVersionMatches();
					public:
						virtual long First(IIterator<IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(HSTRING__ *,unsigned char *);
						virtual long Lookup(HSTRING__ *,IInspectable * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<HSTRING__ *,IInspectable *> * *,IMapView<HSTRING__ *,IInspectable *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					static void _Free(XWinRT::XHashMap<HSTRING__ *,XWinRT::detail::GitStorageType<IInspectable>,HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,XWinRT::CElementTraits<XWinRT::detail::GitStorageType<IInspectable> > > *);
					void _EraseAll(XWinRT::XHashMap<HSTRING__ *,XWinRT::detail::GitStorageType<IInspectable>,HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,XWinRT::CElementTraits<XWinRT::detail::GitStorageType<IInspectable> > > *);
				public:
					virtual long Clear();
					virtual long First(IIterator<IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IMapView<HSTRING__ *,IInspectable *> * *);
					virtual long HasKey(HSTRING__ *,unsigned char *);
					virtual long Insert(HSTRING__ *,IInspectable *,unsigned char *);
					virtual long Lookup(HSTRING__ *,IInspectable * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Remove(HSTRING__ *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class HashMap<HSTRING__ *,unsigned char,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > >
				{
					class Iterator
					{
						long EnsureVersionMatches();
					public:
						Iterator(HashMap<HSTRING__ *,unsigned char,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetMany(unsigned int,IKeyValuePair<HSTRING__ *,unsigned char> * * const,unsigned int *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,unsigned char> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class View
					{
						long EnsureVersionMatches();
					public:
						View(HashMap<HSTRING__ *,unsigned char,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > > *,DefaultEqualityPredicate<HSTRING__ *>);
						virtual long First(IIterator<IKeyValuePair<HSTRING__ *,unsigned char> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(HSTRING__ *,unsigned char *);
						virtual long Lookup(HSTRING__ *,unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<HSTRING__ *,unsigned char> * *,IMapView<HSTRING__ *,unsigned char> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					static void _Free(XWinRT::XHashMap<HSTRING__ *,unsigned char,HashMap<HSTRING__ *,unsigned char,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,XWinRT::CElementTraits<unsigned char> > *);
					void _EraseAll(XWinRT::XHashMap<HSTRING__ *,unsigned char,HashMap<HSTRING__ *,unsigned char,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,XWinRT::CElementTraits<unsigned char> > *);
				public:
					HashMap<HSTRING__ *,unsigned char,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > >(DefaultHash<HSTRING__ *> const &,DefaultEqualityPredicate<HSTRING__ *> const &,HashMap<HSTRING__ *,unsigned char,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > >::permission);
					static long Make(DefaultHash<HSTRING__ *> const &,DefaultEqualityPredicate<HSTRING__ *> const &,HashMap<HSTRING__ *,unsigned char,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > > * *);
					virtual long Clear();
					virtual long First(IIterator<IKeyValuePair<HSTRING__ *,unsigned char> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IMapView<HSTRING__ *,unsigned char> * *);
					virtual long HasKey(HSTRING__ *,unsigned char *);
					virtual long Insert(HSTRING__ *,unsigned char,unsigned char *);
					virtual long Lookup(HSTRING__ *,unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Remove(HSTRING__ *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >
				{
					class Iterator
					{
						long EnsureVersionMatches();
					public:
						Iterator(HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetMany(unsigned int,IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * * const,unsigned int *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class View
					{
						long EnsureVersionMatches();
					public:
						View(HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> > *,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate);
						virtual long First(IIterator<IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned char *);
						virtual long Lookup(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *,IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					static void _Free(XWinRT::XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,XWinRT::CElementTraits<unsigned int> > *);
					void _EraseAll(XWinRT::XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,XWinRT::CElementTraits<unsigned int> > *);
				public:
					HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >(CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction const &,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate const &,HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::permission);
					static long Make(CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction const &,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate const &,HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> > * *);
					virtual long Clear();
					virtual long First(IIterator<IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *);
					virtual long HasKey(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned char *);
					virtual long Insert(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,unsigned char *);
					virtual long Lookup(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Remove(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class HashMap<_GUID,HSTRING__ *,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> >
				{
					class Iterator
					{
						long EnsureVersionMatches();
					public:
						Iterator(HashMap<_GUID,HSTRING__ *,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetMany(unsigned int,IKeyValuePair<_GUID,HSTRING__ *> * * const,unsigned int *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<_GUID,HSTRING__ *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class View
					{
						long EnsureVersionMatches();
					public:
						View(HashMap<_GUID,HSTRING__ *,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> > *,DefaultEqualityPredicate<_GUID>);
						virtual long First(IIterator<IKeyValuePair<_GUID,HSTRING__ *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(_GUID,unsigned char *);
						virtual long Lookup(_GUID,HSTRING__ * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<_GUID,HSTRING__ *> * *,IMapView<_GUID,HSTRING__ *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					static void _Free(XWinRT::XHashMap<_GUID,HSTRING__ *,HashMap<_GUID,HSTRING__ *,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,XWinRT::CElementTraits<HSTRING__ *> > *);
					void _EraseAll(XWinRT::XHashMap<_GUID,HSTRING__ *,HashMap<_GUID,HSTRING__ *,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,XWinRT::CElementTraits<HSTRING__ *> > *);
				public:
					HashMap<_GUID,HSTRING__ *,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> >(DefaultHash<_GUID> const &,DefaultEqualityPredicate<_GUID> const &,HashMap<_GUID,HSTRING__ *,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> >::permission);
					static long Make(DefaultHash<_GUID> const &,DefaultEqualityPredicate<_GUID> const &,HashMap<_GUID,HSTRING__ *,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> > * *);
					virtual long Clear();
					virtual long First(IIterator<IKeyValuePair<_GUID,HSTRING__ *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IMapView<_GUID,HSTRING__ *> * *);
					virtual long HasKey(_GUID,unsigned char *);
					virtual long Insert(_GUID,HSTRING__ *,unsigned char *);
					virtual long Lookup(_GUID,HSTRING__ * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Remove(_GUID);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class HashMap<_GUID,bool,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> >
				{
					class Iterator
					{
						long EnsureVersionMatches();
					public:
						Iterator(HashMap<_GUID,bool,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetMany(unsigned int,IKeyValuePair<_GUID,bool> * * const,unsigned int *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<_GUID,bool> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class View
					{
						long EnsureVersionMatches();
					public:
						View(HashMap<_GUID,bool,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> > *,DefaultEqualityPredicate<_GUID>);
						virtual long First(IIterator<IKeyValuePair<_GUID,bool> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(_GUID,unsigned char *);
						virtual long Lookup(_GUID,unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<_GUID,bool> * *,IMapView<_GUID,bool> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					static void _Free(XWinRT::XHashMap<_GUID,unsigned char,HashMap<_GUID,bool,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,XWinRT::CElementTraits<unsigned char> > *);
					void _EraseAll(XWinRT::XHashMap<_GUID,unsigned char,HashMap<_GUID,bool,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,XWinRT::CElementTraits<unsigned char> > *);
				public:
					HashMap<_GUID,bool,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> >(DefaultHash<_GUID> const &,DefaultEqualityPredicate<_GUID> const &,HashMap<_GUID,bool,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> >::permission);
					static long Make(DefaultHash<_GUID> const &,DefaultEqualityPredicate<_GUID> const &,HashMap<_GUID,bool,DefaultHash<_GUID>,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> > * *);
					virtual long Clear();
					virtual long First(IIterator<IKeyValuePair<_GUID,bool> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IMapView<_GUID,bool> * *);
					virtual long HasKey(_GUID,unsigned char *);
					virtual long Insert(_GUID,unsigned char,unsigned char *);
					virtual long Lookup(_GUID,unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Remove(_GUID);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class HashMap<unsigned int,HSTRING__ *,DefaultHash<unsigned int>,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> >
				{
					class Iterator
					{
						long EnsureVersionMatches();
					public:
						Iterator(HashMap<unsigned int,HSTRING__ *,DefaultHash<unsigned int>,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetMany(unsigned int,IKeyValuePair<unsigned int,HSTRING__ *> * * const,unsigned int *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<unsigned int,HSTRING__ *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class View
					{
						long EnsureVersionMatches();
					public:
						View(HashMap<unsigned int,HSTRING__ *,DefaultHash<unsigned int>,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> > *,DefaultEqualityPredicate<unsigned int>);
						virtual long First(IIterator<IKeyValuePair<unsigned int,HSTRING__ *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(unsigned int,unsigned char *);
						virtual long Lookup(unsigned int,HSTRING__ * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<unsigned int,HSTRING__ *> * *,IMapView<unsigned int,HSTRING__ *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					static void _Free(XWinRT::XHashMap<unsigned int,HSTRING__ *,HashMap<unsigned int,HSTRING__ *,DefaultHash<unsigned int>,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,XWinRT::CElementTraits<HSTRING__ *> > *);
					void _EraseAll(XWinRT::XHashMap<unsigned int,HSTRING__ *,HashMap<unsigned int,HSTRING__ *,DefaultHash<unsigned int>,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,XWinRT::CElementTraits<HSTRING__ *> > *);
				public:
					HashMap<unsigned int,HSTRING__ *,DefaultHash<unsigned int>,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> >(DefaultHash<unsigned int> const &,DefaultEqualityPredicate<unsigned int> const &,HashMap<unsigned int,HSTRING__ *,DefaultHash<unsigned int>,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> >::permission);
					static long Make(DefaultHash<unsigned int> const &,DefaultEqualityPredicate<unsigned int> const &,HashMap<unsigned int,HSTRING__ *,DefaultHash<unsigned int>,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> > * *);
					virtual long Clear();
					virtual long First(IIterator<IKeyValuePair<unsigned int,HSTRING__ *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IMapView<unsigned int,HSTRING__ *> * *);
					virtual long HasKey(unsigned int,unsigned char *);
					virtual long Insert(unsigned int,HSTRING__ *,unsigned char *);
					virtual long Lookup(unsigned int,HSTRING__ * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Remove(unsigned int);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,0,0,0>
				{
					static long RaiseEvent(...);
				};

				struct HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0>
				{
					static long RaiseEvent(...);
				};

				struct HashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *>,0,0,0>
				{
					static long RaiseEvent(...);
				};

				struct HashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,0,0,0>
				{
					static long RaiseEvent(...);
				};

				struct HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0>
				{
					static long RaiseEvent(...);
				};

				struct HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0>
				{
					static long RaiseEvent(...);
				};

				struct HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0>
				{
					static long RaiseEvent(...);
				};

				class NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > >
				{
					class Chunk
					{
						virtual void dummy();
					};

					struct ChunkElementIterator
					{
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,IInspectable *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					struct ChunkView
					{
						long Initialize(IIterator<IKeyValuePair<HSTRING__ *,IInspectable *> *> *);
						virtual long First(IIterator<IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(HSTRING__ *,unsigned char *);
						virtual long Lookup(HSTRING__ *,IInspectable * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<HSTRING__ *,IInspectable *> * *,IMapView<HSTRING__ *,IInspectable *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class SplitIterator
					{
						long EnsureForced();
					public:
						SplitIterator(NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,IInspectable *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					long Force();
					long Initialize(IMapView<HSTRING__ *,IInspectable *> *);
				public:
					NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > >(DefaultEqualityPredicate<HSTRING__ *> const &,NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,DefaultHashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *> > >::permission);
					static long Split(IMapView<HSTRING__ *,IInspectable *> *,IMapView<HSTRING__ *,IInspectable *> * *,IMapView<HSTRING__ *,IInspectable *> * *,DefaultEqualityPredicate<HSTRING__ *> const &);
					virtual long First(IIterator<IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long HasKey(HSTRING__ *,unsigned char *);
					virtual long Lookup(HSTRING__ *,IInspectable * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Split(IMapView<HSTRING__ *,IInspectable *> * *,IMapView<HSTRING__ *,IInspectable *> * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >
				{
					class Chunk
					{
						virtual void dummy();
					};

					struct ChunkElementIterator
					{
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,IInspectable *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					struct ChunkView
					{
						long Initialize(IIterator<IKeyValuePair<HSTRING__ *,IInspectable *> *> *);
						virtual long First(IIterator<IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(HSTRING__ *,unsigned char *);
						virtual long Lookup(HSTRING__ *,IInspectable * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<HSTRING__ *,IInspectable *> * *,IMapView<HSTRING__ *,IInspectable *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class SplitIterator
					{
						long EnsureForced();
					public:
						SplitIterator(NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,IInspectable *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					long Force();
					long Initialize(IMapView<HSTRING__ *,IInspectable *> *);
				public:
					NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >(DefaultEqualityPredicate<HSTRING__ *> const &,NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::permission);
					static long Split(IMapView<HSTRING__ *,IInspectable *> *,IMapView<HSTRING__ *,IInspectable *> * *,IMapView<HSTRING__ *,IInspectable *> * *,DefaultEqualityPredicate<HSTRING__ *> const &);
					virtual long First(IIterator<IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long HasKey(HSTRING__ *,unsigned char *);
					virtual long Lookup(HSTRING__ *,IInspectable * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Split(IMapView<HSTRING__ *,IInspectable *> * *,IMapView<HSTRING__ *,IInspectable *> * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class NaiveSplitView<HSTRING__ *,unsigned char,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > >
				{
					class Chunk
					{
						virtual void dummy();
					};

					struct ChunkElementIterator
					{
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,unsigned char> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					struct ChunkView
					{
						long Initialize(IIterator<IKeyValuePair<HSTRING__ *,unsigned char> *> *);
						virtual long First(IIterator<IKeyValuePair<HSTRING__ *,unsigned char> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(HSTRING__ *,unsigned char *);
						virtual long Lookup(HSTRING__ *,unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<HSTRING__ *,unsigned char> * *,IMapView<HSTRING__ *,unsigned char> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class SplitIterator
					{
						long EnsureForced();
					public:
						SplitIterator(NaiveSplitView<HSTRING__ *,unsigned char,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,unsigned char> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					long Force();
					long Initialize(IMapView<HSTRING__ *,unsigned char> *);
				public:
					NaiveSplitView<HSTRING__ *,unsigned char,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > >(DefaultEqualityPredicate<HSTRING__ *> const &,NaiveSplitView<HSTRING__ *,unsigned char,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,DefaultHashMapOptions<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *> > >::permission);
					static long Split(IMapView<HSTRING__ *,unsigned char> *,IMapView<HSTRING__ *,unsigned char> * *,IMapView<HSTRING__ *,unsigned char> * *,DefaultEqualityPredicate<HSTRING__ *> const &);
					virtual long First(IIterator<IKeyValuePair<HSTRING__ *,unsigned char> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long HasKey(HSTRING__ *,unsigned char *);
					virtual long Lookup(HSTRING__ *,unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Split(IMapView<HSTRING__ *,unsigned char> * *,IMapView<HSTRING__ *,unsigned char> * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class NaiveSplitView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >
				{
					class Chunk
					{
						virtual void dummy();
					};

					struct ChunkElementIterator
					{
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					struct ChunkView
					{
						long Initialize(IIterator<IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> *);
						virtual long First(IIterator<IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned char *);
						virtual long Lookup(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *,IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class SplitIterator
					{
						long EnsureForced();
					public:
						SplitIterator(NaiveSplitView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					long Force();
					long Initialize(IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *);
				public:
					NaiveSplitView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >(CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate const &,NaiveSplitView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::permission);
					static long Split(IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *,IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *,IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate const &);
					virtual long First(IIterator<IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long HasKey(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned char *);
					virtual long Lookup(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Split(IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *,IMapView<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class NaiveSplitView<_GUID,HSTRING__ *,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> >
				{
					class Chunk
					{
						virtual void dummy();
					};

					struct ChunkElementIterator
					{
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<_GUID,HSTRING__ *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					struct ChunkView
					{
						long Initialize(IIterator<IKeyValuePair<_GUID,HSTRING__ *> *> *);
						virtual long First(IIterator<IKeyValuePair<_GUID,HSTRING__ *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(_GUID,unsigned char *);
						virtual long Lookup(_GUID,HSTRING__ * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<_GUID,HSTRING__ *> * *,IMapView<_GUID,HSTRING__ *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class SplitIterator
					{
						long EnsureForced();
					public:
						SplitIterator(NaiveSplitView<_GUID,HSTRING__ *,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<_GUID,HSTRING__ *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					long Force();
					long Initialize(IMapView<_GUID,HSTRING__ *> *);
				public:
					NaiveSplitView<_GUID,HSTRING__ *,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> >(DefaultEqualityPredicate<_GUID> const &,NaiveSplitView<_GUID,HSTRING__ *,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,0,1,0> >::permission);
					static long Split(IMapView<_GUID,HSTRING__ *> *,IMapView<_GUID,HSTRING__ *> * *,IMapView<_GUID,HSTRING__ *> * *,DefaultEqualityPredicate<_GUID> const &);
					virtual long First(IIterator<IKeyValuePair<_GUID,HSTRING__ *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long HasKey(_GUID,unsigned char *);
					virtual long Lookup(_GUID,HSTRING__ * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Split(IMapView<_GUID,HSTRING__ *> * *,IMapView<_GUID,HSTRING__ *> * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class NaiveSplitView<_GUID,bool,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> >
				{
					class Chunk
					{
						virtual void dummy();
					};

					struct ChunkElementIterator
					{
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<_GUID,bool> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					struct ChunkView
					{
						long Initialize(IIterator<IKeyValuePair<_GUID,bool> *> *);
						virtual long First(IIterator<IKeyValuePair<_GUID,bool> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(_GUID,unsigned char *);
						virtual long Lookup(_GUID,unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<_GUID,bool> * *,IMapView<_GUID,bool> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class SplitIterator
					{
						long EnsureForced();
					public:
						SplitIterator(NaiveSplitView<_GUID,bool,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<_GUID,bool> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					long Force();
					long Initialize(IMapView<_GUID,bool> *);
				public:
					NaiveSplitView<_GUID,bool,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> >(DefaultEqualityPredicate<_GUID> const &,NaiveSplitView<_GUID,bool,DefaultEqualityPredicate<_GUID>,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,HashMapOptions<_GUID,bool,DefaultLifetimeTraits<_GUID>,0,1,0> >::permission);
					static long Split(IMapView<_GUID,bool> *,IMapView<_GUID,bool> * *,IMapView<_GUID,bool> * *,DefaultEqualityPredicate<_GUID> const &);
					virtual long First(IIterator<IKeyValuePair<_GUID,bool> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long HasKey(_GUID,unsigned char *);
					virtual long Lookup(_GUID,unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Split(IMapView<_GUID,bool> * *,IMapView<_GUID,bool> * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class NaiveSplitView<unsigned int,HSTRING__ *,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> >
				{
					class Chunk
					{
						virtual void dummy();
					};

					struct ChunkElementIterator
					{
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<unsigned int,HSTRING__ *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					struct ChunkView
					{
						long Initialize(IIterator<IKeyValuePair<unsigned int,HSTRING__ *> *> *);
						virtual long First(IIterator<IKeyValuePair<unsigned int,HSTRING__ *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(unsigned int,unsigned char *);
						virtual long Lookup(unsigned int,HSTRING__ * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<unsigned int,HSTRING__ *> * *,IMapView<unsigned int,HSTRING__ *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class SplitIterator
					{
						long EnsureForced();
					public:
						SplitIterator(NaiveSplitView<unsigned int,HSTRING__ *,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<unsigned int,HSTRING__ *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					long Force();
					long Initialize(IMapView<unsigned int,HSTRING__ *> *);
				public:
					NaiveSplitView<unsigned int,HSTRING__ *,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> >(DefaultEqualityPredicate<unsigned int> const &,NaiveSplitView<unsigned int,HSTRING__ *,DefaultEqualityPredicate<unsigned int>,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,0,1,0> >::permission);
					static long Split(IMapView<unsigned int,HSTRING__ *> *,IMapView<unsigned int,HSTRING__ *> * *,IMapView<unsigned int,HSTRING__ *> * *,DefaultEqualityPredicate<unsigned int> const &);
					virtual long First(IIterator<IKeyValuePair<unsigned int,HSTRING__ *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long HasKey(unsigned int,unsigned char *);
					virtual long Lookup(unsigned int,HSTRING__ * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Split(IMapView<unsigned int,HSTRING__ *> * *,IMapView<unsigned int,HSTRING__ *> * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class SimpleKeyValuePair<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,0>
				{
					long Initialize(HSTRING__ * const &,IInspectable * const &);
				public:
					SimpleKeyValuePair<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,0>(SimpleKeyValuePair<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,0>::permission);
					static long Make(HSTRING__ * const &,IInspectable * const &,SimpleKeyValuePair<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,0> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Key(HSTRING__ * *);
					virtual long get_Value(IInspectable * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class SimpleKeyValuePair<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,1>
				{
					long Initialize(HSTRING__ * const &,XWinRT::detail::GitStorageType<IInspectable> const &);
				public:
					SimpleKeyValuePair<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,1>(SimpleKeyValuePair<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,1>::permission);
					static long Make(HSTRING__ * const &,XWinRT::detail::GitStorageType<IInspectable> const &,SimpleKeyValuePair<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,1> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Key(HSTRING__ * *);
					virtual long get_Value(IInspectable * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class SimpleKeyValuePair<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,0>
				{
					long Initialize(HSTRING__ * const &,unsigned char const &);
				public:
					SimpleKeyValuePair<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,0>(SimpleKeyValuePair<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,0>::permission);
					static long Make(HSTRING__ * const &,unsigned char const &,SimpleKeyValuePair<HSTRING__ *,unsigned char,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<unsigned char>,0> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Key(HSTRING__ * *);
					virtual long get_Value(unsigned char *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class SimpleKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,0>
				{
					long Initialize(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair const &,unsigned int const &);
				public:
					SimpleKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,0>(SimpleKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,0>::permission);
					static long Make(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair const &,unsigned int const &,SimpleKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,DefaultLifetimeTraits<unsigned int>,0> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Key(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair *);
					virtual long get_Value(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class SimpleKeyValuePair<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,1>
				{
					long Initialize(_GUID const &,HSTRING__ * const &);
				public:
					SimpleKeyValuePair<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,1>(SimpleKeyValuePair<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,1>::permission);
					static long Make(_GUID const &,HSTRING__ * const &,SimpleKeyValuePair<_GUID,HSTRING__ *,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<HSTRING__ *>,1> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Key(_GUID *);
					virtual long get_Value(HSTRING__ * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct SimpleKeyValuePair<_GUID,bool,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,1>
				{
					SimpleKeyValuePair<_GUID,bool,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,1>(SimpleKeyValuePair<_GUID,bool,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,1>::permission);
					static long Make(_GUID const &,unsigned char const &,SimpleKeyValuePair<_GUID,bool,DefaultLifetimeTraits<_GUID>,DefaultLifetimeTraits<bool>,1> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Key(_GUID *);
					virtual long get_Value(unsigned char *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class SimpleKeyValuePair<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,1>
				{
					long Initialize(unsigned int const &,HSTRING__ * const &);
				public:
					SimpleKeyValuePair<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,1>(SimpleKeyValuePair<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,1>::permission);
					static long Make(unsigned int const &,HSTRING__ * const &,SimpleKeyValuePair<unsigned int,HSTRING__ *,DefaultLifetimeTraits<unsigned int>,DefaultLifetimeTraits<HSTRING__ *>,1> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Key(unsigned int *);
					virtual long get_Value(HSTRING__ * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct SimpleVectorIterator<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1>
				{
					SimpleVectorIterator<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1>(Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> > *,SimpleVectorIterator<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1>::permission);
					static long Make(Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> > *,SimpleVectorIterator<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,HSTRING__ * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long MoveNext(unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Current(HSTRING__ * *);
					virtual long get_HasCurrent(unsigned char *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct SimpleVectorView<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1>
				{
					SimpleVectorView<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1>(Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> > *,SimpleVectorView<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1>::permission);
					virtual long First(IIterator<HSTRING__ *> * *);
					virtual long GetAt(unsigned int,HSTRING__ * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,unsigned int,HSTRING__ * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long IndexOf(HSTRING__ *,unsigned int *,unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> >
				{
					long IndexOfInternal(HSTRING__ * *,unsigned int,HSTRING__ *,unsigned int *,unsigned char *);
					long InsertAtInternal(unsigned int,HSTRING__ *,bool);
					long RemoveAtInternal(unsigned int,bool);
					long ResizeStorage(unsigned int);
					static void _Free(HSTRING__ * *,unsigned int);
					void _EraseAll(HSTRING__ * * *,unsigned int *);
				public:
					Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> >(DefaultEqualityPredicate<HSTRING__ *> const &,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,VectorOptions<HSTRING__ *,0,1,0> >::permission);
					virtual long Append(HSTRING__ *);
					virtual long Clear();
					virtual long First(IIterator<HSTRING__ *> * *);
					virtual long GetAt(unsigned int,HSTRING__ * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,unsigned int,HSTRING__ * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IVectorView<HSTRING__ *> * *);
					virtual long IndexOf(HSTRING__ *,unsigned int *,unsigned char *);
					virtual long InsertAt(unsigned int,HSTRING__ *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long RemoveAt(unsigned int);
					virtual long RemoveAtEnd();
					virtual long ReplaceAll(unsigned int,HSTRING__ * *);
					virtual long SetAt(unsigned int,HSTRING__ *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct VectorOptions<HSTRING__ *,0,1,0>
				{
					static long RaiseEvent(...);
				};

			};

		};

		namespace Diagnostics
		{
			struct AsyncCausalityTracerFactory
			{
				AsyncCausalityTracerFactory();
				static TrustLevel InternalGetTrustLevelStatic();
				static unsigned short const * InternalGetRuntimeClassNameStatic();
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual long TraceOperationCompletion(CausalityTraceLevel,CausalitySource,_GUID,unsigned __int64,ABI::Windows::Foundation::AsyncStatus);
				virtual long TraceOperationCreation(CausalityTraceLevel,CausalitySource,_GUID,unsigned __int64,HSTRING__ *,unsigned __int64);
				virtual long TraceOperationRelation(CausalityTraceLevel,CausalitySource,_GUID,unsigned __int64,CausalityRelation);
				virtual long TraceSynchronousWorkCompletion(CausalityTraceLevel,CausalitySource,CausalitySynchronousWork);
				virtual long TraceSynchronousWorkStart(CausalityTraceLevel,CausalitySource,_GUID,unsigned __int64,CausalitySynchronousWork);
				virtual long add_TracingStatusChanged(IEventHandler<TracingStatusChangedEventArgs *> *,EventRegistrationToken *);
				virtual long remove_TracingStatusChanged(EventRegistrationToken);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class CausalityTraceState
			{
				static CausalityTraceState * gCausality;
				static _RTL_RUN_ONCE _initOnce;
				static int InitOnceRoutine(_RTL_RUN_ONCE *,void *,void * *);
				static void ControlCallback(unsigned char,CausalityTraceLevel);
			public:
				CausalityTraceState();
				long add_TracingStatusChanged(IEventHandler<TracingStatusChangedEventArgs *> *,EventRegistrationToken *);
				static long get_Instance(CausalityTraceState * *);
			};

			struct TracingStatusChangedEventArgs
			{
				TracingStatusChangedEventArgs(unsigned char,CausalityTraceLevel);
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual long get_Enabled(unsigned char *);
				virtual long get_TraceLevel(CausalityTraceLevel *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			Microsoft::WRL::Details::CreatorMap const __object_AsyncCausalityTracerFactory;
			Microsoft::WRL::Details::FactoryCache __objectFactory__AsyncCausalityTracerFactory;
		};

		long ActivateInstance<Collections::IMap<HSTRING__ *,IInspectable *> >(HSTRING__ *,Foundation::Collections::IMap<HSTRING__ *,IInspectable *> * *);
	};

	namespace Internal
	{
		namespace Details
		{
			struct Git
			{
				Git();
				long Acquire();
				~Git();
			};

			struct GitInvokeHelper<Foundation::IEventHandler<Foundation::Diagnostics::TracingStatusChangedEventArgs *>,GitPtr,2>
			{
				GitInvokeHelper<Foundation::IEventHandler<Foundation::Diagnostics::TracingStatusChangedEventArgs *>,GitPtr,2>();
				virtual long Invoke(IInspectable *,Foundation::Diagnostics::ITracingStatusChangedEventArgs *);
			};

			Details::Git _git;
			long CreateGitHelper<Foundation::IEventHandler<Foundation::Diagnostics::TracingStatusChangedEventArgs *>,GitPtr>(Foundation::IEventHandler<Foundation::Diagnostics::TracingStatusChangedEventArgs *> *,Foundation::IEventHandler<Foundation::Diagnostics::TracingStatusChangedEventArgs *> * *);
		};

		struct GitPtrImpl<GitPtr>
		{
			long Revoke();
			virtual bool IsInitialized();
		};

		class String
		{
			long _InitializeHelper(unsigned short const *);
		public:
			long Initialize(unsigned short const *,unsigned int);
		};

		struct StringReference
		{
			StringReference(unsigned short const *,unsigned int);
		};

	};

};

class WinrtAsyncChannelMessage
{
protected:
	WinrtAsyncChannelMessage(WinrtAsyncChannelOperation *,CObjectContext *);
public:
	APTKIND GetMessageDeliveryApartmentKind();
	virtual ~WinrtAsyncChannelMessage();
};

class WinrtAsyncChannelOperation
{
	bool ShouldSerializeResults(ABI::Windows::Foundation::AsyncStatus);
	long EnableInParameterMarshalingMitigation();
	long EnableOutResultMarshalingMitigation();
	long FilterCompletionError(long,AsyncDelegateStorage const &);
	long FilterCompletionErrorWithDelegatePointer(long,IUnknown *,void *);
	long FireCompletionInThisContext(ObjectLibrary::ReferencedPtr<IAgileReference> const &,ABI::Windows::Foundation::AsyncStatus,void *,bool);
	long FireCompletionOnThisThread(ObjectLibrary::ReferencedPtr<CObjectContext> const &,ObjectLibrary::ReferencedPtr<IAgileReference> const &,ABI::Windows::Foundation::AsyncStatus,void *,bool);
	long GetRealOperation(_GUID const &,void * *);
	long GetRpcChannelBufferForTypeSerializer(IRpcChannelBuffer * *);
	long GetSerializedResultsFromRealOperation();
	long GetWinrtAsyncResponseBlockSize(unsigned long *);
	long ReadAsyncCompletedResponseFromWireLocalThat(unsigned long,WireLocalThat const *);
	long ReallyFireCompletion(ABI::Windows::Foundation::AsyncStatus,AsyncDelegateStorage const &);
	long UnmarshalRealOperation(unsigned char const *,unsigned long,_GUID const &,void * *);
	long ValidateAndUnmarshalStubData(unsigned long,void const *,bool *,long *);
	static IMessageParamList s_backgroundThreadMessageList;
	static Microsoft::WRL::Wrappers::SRWLock s_lockBackgroundThreadMessageList;
	static WaitableCount s_initializedChannelOperationCount;
	static WaitableCount s_outstandingClientOutofprocOperationCount;
	static _GUID GenerateGuid();
	static long InitializeBackgroundThreadMessageDelivery();
	static std::atomic<_TP_WORK *> s_messageDeliveryWork;
	static unsigned int volatile s_currentAsyncInfoId;
	static void DeliverBackgroundThreadMessageWorkCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_WORK *);
	static void DeliverMessageInThisThread(ObjectLibrary::ReferencedPtr<WinrtAsyncChannelMessage> const &);
	static void StaticTraceOperationStart(unsigned __int64,unsigned int,unsigned short const *);
	virtual ~WinrtAsyncChannelOperation();
	void AbortClientAsyncCall();
	void AcknowledgeMarshalingSet();
	void AllowAstaToAstaCallsIfProxy(IUnknown *);
	void ChannelOperationFinalize();
	void ClearRealOperationReference();
	void ClientSideFinalize(bool);
	void DeliverCancelInThisContext(ObjectLibrary::ReferencedPtr<IAgileReference> const &);
	void DeliverCancelOnThisThread(ObjectLibrary::ReferencedPtr<CObjectContext> const &,ObjectLibrary::ReferencedPtr<IAgileReference> const &);
	void DeliverCrossThreadCancelToASTA(ObjectLibrary::ReferencedPtr<WinrtAsyncServerContinuationMessage> const &);
	void DeliverCrossThreadCancelToMTA(ObjectLibrary::ReferencedPtr<WinrtAsyncServerContinuationMessage> const &);
	void DeliverCrossThreadCancelToSTA(ObjectLibrary::ReferencedPtr<WinrtAsyncServerContinuationMessage> const &);
	void DeliverCrossThreadResponse(ObjectLibrary::ReferencedPtr<WinrtAsyncResponse> const &);
	void DeliverCrossThreadResponseToSTA(ObjectLibrary::ReferencedPtr<WinrtAsyncResponse> const &);
	void DeliverMessageOnBackgroundThread(WinrtAsyncChannelMessage *);
	void FillAsyncResponseBlock(WireWinrtAsyncCallResponseBlockPart1 *);
	void OnCancel();
	void OnMalformedResponseMessage();
	void OnReceiveFailure(long);
	void OnReceivedCompletedResponse(unsigned long,WireLocalThat const *,unsigned long,void const *);
	void OnReceivedErrorResponse(unsigned long,WireLocalThat const *,unsigned long,void const *);
	void ReleaseRealOperationReferenceInStubDataWithoutUnmarshaling(unsigned long,unsigned char const *);
	void SendOutofprocCompletedResponse(ObjectLibrary::ReferencedPtr<CAsyncCall> const &,ABI::Windows::Foundation::AsyncStatus);
public:
	ObjectLibrary::ReferencedPtr<CAsyncCall> GetTransportCall();
	ObjectLibrary::ReferencedPtr<ServerCall> GetAndClearServerCall();
	bool AcquireMarshaledResultData(void * *);
	long ClientGetBuffer(WhichTransferSyntax,_RPC_SYNTAX_IDENTIFIER *,unsigned long,unsigned long,unsigned long *,void * *,void * *);
	long ClientSend(CStdIdentity *,unsigned long,void *,bool *);
	long GetDestCtxEx(unsigned long *,void * *);
	long GetFtmContainer(MessageDirection,unsigned __int64 *);
	long GetOperationFacade(_GUID const &,void * *,unsigned long *);
	long GetOrCreateInBiasContainer(unsigned __int64 *);
	long GetOrCreateOutResultBiasContainer(unsigned __int64 *);
	long RegisterTransportCallAsRpcAsync();
	long UnmarshalResultData(void *,void *);
	static long Create(WinrtAsyncChannelOperation::WhichSide,WinrtAsyncOperationInfo const &,_GUID const &,IWinrtAsyncProxyCall *,IStubCall *,unsigned long,_GUID const &,bool,ComCallTraceActivity *,OXIDEntry *,_GUID const &,_GUID const &,_GUID const &,WinrtAsyncChannelOperation * *);
	virtual CCtxCall * ObsoleteGetClientCtxCall();
	virtual long BindCompletedHandlerFacadeToCompletedHandler(IUnknown *,IUnknown * *);
	virtual long BindOperationFacadeToOperation(IUnknown *,IUnknown * *);
	virtual long BindProgressHandlerFacadeToProgressHandler(IUnknown *,IUnknown * *);
	virtual long Cancel();
	virtual long CancelTransportCall(unsigned long);
	virtual long Close(void *);
	virtual long CreateTransportCallObject(tagRPCOLEMESSAGE const *,tagCALLCATEGORY,CChannelHandle *,unsigned long,tagCOMVERSION,CAsyncCall * *);
	virtual long GetResults();
	virtual long GetResults(void *);
	virtual long PutOperationObject(IAgileReference *,bool,unsigned long,std::unique_ptr<unsigned char [0],std::default_delete<unsigned char [0]> >);
	virtual long TransportReceive(unsigned long *);
	virtual long TransportSend();
	virtual long get_Completed(void * *,void *);
	virtual long get_ErrorCode(long *,void *);
	virtual long get_Id(unsigned int *,void *);
	virtual long get_Progress(void * *,void *);
	virtual long get_Status(ABI::Windows::Foundation::AsyncStatus *,void *);
	virtual long put_Completed(IUnknown *,void *);
	virtual long put_Progress(IUnknown *,void *);
	virtual void AbortOperation();
	virtual void FinalizeOperation();
	virtual void OnCancelRequestRequiringAcknowledgment();
	virtual void OnClientEventSignalRequiringReset();
	virtual void OnCompletedCallWithUnknownClientEventSignalStatus();
	virtual void OnCompletedHandlerFacadeFinalRelease();
	virtual void OnCompletedHandlerFacadeMarshaledOutofproc(IUnknown *,unsigned long);
	virtual void OnCompletedNotification(IInspectable *,ABI::Windows::Foundation::AsyncStatus);
	virtual void OnFailureToCreateOperationObject(long);
	virtual void OnForwardedProgressNotification(IInspectable *,void *,IWinrtTypeSerializer *);
	virtual void OnOperationFacadeFinalRelease(void *,unsigned long);
	virtual void OnOperationFacadeMarshaledOutofproc(IUnknown *,unsigned long);
	virtual void OnProgressHandlerFacadeFinalRelease();
	virtual void OnProgressHandlerFacadeMarshaledOutofproc(IUnknown *,unsigned long);
	virtual void OnProgressHandlerThunkDestroyed();
	virtual void OnProgressNotification(IInspectable *,void *,IWinrtTypeSerializer *);
	virtual void OnRetryCanceled();
	virtual void OnRetryFailed(long);
	virtual void OnServerAsyncCallCanceled();
	virtual void OnSourceOfClientHResultIdentified(SourceOfClientHResult);
	virtual void OnSyncCallCompletedWithOutstandingRpcCancel();
	virtual void OnTransportCallCanceled();
	virtual void OnTransportCallCompletionReceived();
	virtual void OnTransportCallFailed(long);
	virtual void OnWaitSatisifiedByClientEventSignal();
	void CheckForFailureToCallGetResults(void *);
	void ClientCallFinalize();
	void DeliverResponseOnThisThread(ObjectLibrary::ReferencedPtr<WinrtAsyncResponse> const &);
	void DeliverServerContinuationMessageOnThisThread();
	void ReleaseMarshaledResultData();
	void ReleaseTransportCall();
	void SetTransportCall(CAsyncCall *);
	void SubscribeServerTransportCallEventsIfNeeded();
};

struct WinrtAsyncChannelOperationInfo
{
	WinrtAsyncChannelOperationInfo(WinrtAsyncOperationInfo const &);
};

struct WinrtAsyncChannelOperationMap
{
	WinrtAsyncChannelOperationMap();
};

struct WinrtAsyncChannelUnmarshaler
{
	virtual long DisconnectObject(unsigned long);
	virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
	virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
	virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long ReleaseMarshalData(IStream *);
	virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
};

class WinrtAsyncClientCall
{
protected:
	virtual _GUID GetDcomCausalityId();
	virtual _GUID GetTargetInterface();
	virtual unsigned short GetProcNum();
public:
	virtual IWinrtAsyncChannelOperation * GetOperation();
	virtual bool IsClientAsync();
	virtual bool IsWinrtAsyncCall();
	virtual long CheckSystemHandleLeak();
	virtual long CleanupAllSystemHandles();
	virtual long GetBuffer(WhichTransferSyntax,_RPC_SYNTAX_IDENTIFIER *,unsigned long,unsigned long,unsigned long *,void * *,void * *);
	virtual long GetBuffer(tagRPCOLEMESSAGE *,_GUID const &);
	virtual long GetCustomUnmarshalerClsidAndSize(_GUID *,unsigned long *);
	virtual long GetDestCtxEx(tagRPCOLEMESSAGE const *,unsigned long *,void * *);
	virtual long GetInMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetOutMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetSystemHandle(unsigned long,unsigned char,unsigned long,void * *);
	virtual long Initialize(tagRPCOLEMESSAGE const *,tagCALLCATEGORY,CChannelHandle *,unsigned long,tagCOMVERSION,_GUID const &,ClientCallTracingInfo const &);
	virtual long NegotiateSyntax(_RPC_MESSAGE *);
	virtual long NegotiateSyntax(tagRPCOLEMESSAGE *);
	virtual long Send(unsigned long,void *,bool *);
	virtual long SendReceive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SendReceive2(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SetSystemHandle(void *,unsigned char,unsigned long,unsigned long *);
	virtual long WriteCustomUnmarshalerData(unsigned long,void *);
	virtual void Finalize();
	virtual void Finalize(tagRPCOLEMESSAGE *);
	virtual void SetClientHResult(long,int);
	virtual void StoreInRpcOleMessage(tagRPCOLEMESSAGE *);
};

struct WinrtAsyncOperationInfo
{
	WinrtAsyncOperationInfo(_GUID const &,unsigned short,unsigned short const *,WinrtAsyncOperationType,_GUID const &,_GUID const &,_GUID const *,unsigned short const *,IWinrtTypeSerializer *,IWinrtTypeSerializer *);
};

class WinrtAsyncProxyCall
{
	long CreateCompletedHandlerFacade(IWinrtAsyncChannelOperation *,_GUID const &,void * *);
	long CreateOperationFacade(IWinrtAsyncChannelOperation *,_GUID const &,void * *,unsigned long *);
public:
	WinrtAsyncProxyCall(WinrtAsyncProxyMethodInfo *,bool);
	virtual long Cancel(tagRPCOLEMESSAGE *);
	virtual long CreateProgressHandlerFacade(IWinrtAsyncChannelOperation *,_GUID const &,void * *);
	virtual long CreateProgressHandlerThunk(IWinrtAsyncChannelOperation *,bool,_GUID const &,void * *);
	virtual long FreeBuffer(tagRPCOLEMESSAGE *);
	virtual long GetBuffer(IWinrtAsyncClientCall *,tagRPCOLEMESSAGE *,_GUID const &);
	virtual long GetBuffer(tagRPCOLEMESSAGE *,_GUID const &);
	virtual long GetCallContext(tagRPCOLEMESSAGE *,_GUID const &,void * *);
	virtual long GetCompletedHandlerFacade(IWinrtAsyncChannelOperation *,_GUID const &,void * *);
	virtual long GetDestCtx(unsigned long *,void * *);
	virtual long GetDestCtxEx(tagRPCOLEMESSAGE *,unsigned long *,void * *);
	virtual long GetInMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetMarshalingLocality(tagRPCOLEMESSAGE const *,ComCallMarshalingLocality *);
	virtual long GetOperationFacade(IWinrtAsyncChannelOperation *,_GUID const &,void * *,unsigned long *);
	virtual long GetOutMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetProtocolVersion(unsigned long *);
	virtual long GetState(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long Invoke(IServerCall *,IRpcChannelBuffer *,IRpcStubBuffer *,unsigned long *);
	virtual long InvokeCompletedDelegate(IUnknown *,IInspectable *,ABI::Windows::Foundation::AsyncStatus);
	virtual long InvokeGetResults(IInspectable *);
	virtual long InvokeGetResults(IInspectable *,void *);
	virtual long InvokeGetResultsAndMarshal(IInspectable *,IRpcChannelBuffer *,unsigned long *,void * *);
	virtual long InvokeProgressDelegate(IUnknown *,IInspectable *,void *);
	virtual long InvokeProgressDelegateWithMarshaledData(IUnknown *,IInspectable *,unsigned long,void *);
	virtual long InvokePutCompleted(IInspectable *,IUnknown *);
	virtual long InvokePutProgress(IInspectable *,IUnknown *);
	virtual long IsConnected();
	virtual long NegotiateSyntax(IWinrtAsyncClientCall *,tagRPCOLEMESSAGE *);
	virtual long PutReturnObject(_GUID const &,IUnknown *);
	virtual long Receive(tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
	virtual long RegisterAsync(tagRPCOLEMESSAGE *,IAsyncManager *);
	virtual long Send(tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SendReceive(IWinrtAsyncClientCall *,tagRPCOLEMESSAGE *,unsigned long *);
	virtual long SendReceive(tagRPCOLEMESSAGE *,unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual void Finalize(IWinrtAsyncClientCall *,tagRPCOLEMESSAGE *);
	virtual void SetClientHResult(IWinrtAsyncClientCall *,long,bool);
};

struct WinrtAsyncProxyMethodInfo
{
	~WinrtAsyncProxyMethodInfo();
};

struct WinrtAsyncProxyMethodInfoCache
{
	WinrtAsyncProxyMethodInfoCache();
	~WinrtAsyncProxyMethodInfoCache();
};

struct WinrtAsyncResponse
{
	WinrtAsyncResponse(WinrtAsyncChannelOperation *,CObjectContext *,IAgileReference *,void *);
};

struct WinrtAsyncRpcChannelBufferForTypeSerializer
{
	WinrtAsyncRpcChannelBufferForTypeSerializer(WinrtAsyncChannelOperation *);
	virtual long FreeBuffer(tagRPCOLEMESSAGE *);
	virtual long GetBuffer(tagRPCOLEMESSAGE *,_GUID const &);
	virtual long GetDestCtx(unsigned long *,void * *);
	virtual long GetInMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetMarshalingLocality(tagRPCOLEMESSAGE const *,ComCallMarshalingLocality *);
	virtual long GetOutMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long IsConnected();
	virtual long SendReceive(tagRPCOLEMESSAGE *,unsigned long *);
};

class WinrtAsyncServerCall
{
protected:
	virtual _GUID GetServerIpidFromTransport();
public:
	virtual CMessageCall * GetTransportCall();
	virtual IWinrtAsyncChannelOperation * GetOperation();
	virtual _GUID GetDcomCausalityId();
	virtual _GUID GetPassthroughTraceActivity();
	virtual _GUID GetTargetInterface();
	virtual bool EnableCallTracing();
	virtual bool IsMachineLocal();
	virtual bool IsProcessLocal();
	virtual bool IsWinrtAsyncCall();
	virtual bool NeedsUnmarshalingTlsMitigation();
	virtual bool ServerShouldUseCancelationNotification();
	virtual long CanDispatch();
	virtual long CheckSystemHandleLeak();
	virtual long CleanupAllSystemHandles();
	virtual long CompleteCurrentTlsRundownMitigation();
	virtual long ContextInvoke(tagRPCOLEMESSAGE *,IRpcStubBuffer *,CServerChannel *,tagIPIDEntry *,unsigned long *);
	virtual long GetBuffer(tagRPCOLEMESSAGE *,_GUID const &);
	virtual long GetBuffer2(tagRPCOLEMESSAGE *);
	virtual long GetDestCtxEx(tagRPCOLEMESSAGE const *,unsigned long *,void * *);
	virtual long GetInMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetOutMarshalingContextAttribute(tagRPCOLEMESSAGE const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
	virtual long GetSystemHandle(unsigned long,unsigned char,unsigned long,void * *);
	virtual long IncrementCallCount();
	virtual long IsFromRpcss(bool *);
	virtual long SetSystemHandle(void *,unsigned char,unsigned long,unsigned long *);
	virtual long StubInvoke(IRpcChannelBuffer *,IRpcStubBuffer *,unsigned long *);
	virtual tagRPCOLEMESSAGE * GetMessageW();
	virtual unsigned short GetProcNum();
	virtual void * GetServerInterface();
	virtual void * GetServerObject();
	virtual void * GetServerVtable();
	virtual void AbortCurrentTlsRundownMitigation();
	virtual void DecrementCallCount();
	virtual void Finalize();
	virtual void Initialize(CStdIdentity *,bool,CObjectContext *,tagIPIDEntry *);
	virtual void OnSendingAutoRetryResponse();
	virtual void RelockServerIfNeeded();
	virtual void ReportServerFault(unsigned long);
	virtual void ReportStubInvokeFailure(long);
	virtual void SetContainerId(_GUID const *);
	virtual void TraceServerCallStart(ServerCallTracingInfo const &);
	virtual void TraceServerCallStop(unsigned long);
};

struct WinrtAsyncServerContinuationMessage
{
	WinrtAsyncServerContinuationMessage(WinrtAsyncChannelOperation *,CObjectContext *);
};

struct WinrtTypeSerializer
{
	WinrtTypeSerializer();
	virtual long ClearInMemoryType(void *,IRpcChannelBuffer *,ComCallMarshalingDirection);
	virtual long GetMarshalSizeMax(void *,unsigned long,void *,IRpcChannelBuffer *,ComCallMarshalingDirection,unsigned long *);
	virtual long GetMemorySize(unsigned long *);
	virtual long Marshal(void *,unsigned long,void *,IRpcChannelBuffer *,ComCallMarshalingDirection,unsigned long,unsigned char *,unsigned long *);
	virtual long Unmarshal(void *,unsigned long,IRpcChannelBuffer *,ComCallMarshalingDirection,unsigned long,unsigned char *,unsigned long *);
};

class WinrtTypeSerializerNdrHelper
{
	static unsigned char IsClient(WinrtTypeSerializerNdrHelper::WhichRoutine,ComCallMarshalingDirection);
public:
	long ClearInMemoryType(void *,IRpcChannelBuffer *,ComCallMarshalingDirection);
	long GetMarshalSizeMax(void *,unsigned long,void *,IRpcChannelBuffer *,ComCallMarshalingDirection,unsigned long *);
	long GetMemorySize(unsigned long *);
	long Initialize(_MIDL_WINRT_TYPE_SERIALIZATION_INFO const *);
	long Marshal(void *,unsigned long,void *,IRpcChannelBuffer *,ComCallMarshalingDirection,unsigned long,unsigned char *,unsigned long *);
	long Unmarshal(void *,unsigned long,IRpcChannelBuffer *,ComCallMarshalingDirection,unsigned long,unsigned char *,unsigned long *);
};

struct XIPersistFile
{
	~XIPersistFile();
};

struct XIPersistStorage
{
	~XIPersistStorage();
};

struct XIUnknown
{
	~XIUnknown();
};

namespace XWinRT
{
	struct AutoValue<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> >
	{
		AutoValue<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> ><HSTRING__ *>(HSTRING__ * const &,long *);
	};

	struct AutoValue<IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *> >
	{
		AutoValue<IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *> ><IInspectable *>(IInspectable * const &,long *);
	};

	struct AutoValue<detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *> >
	{
		AutoValue<detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *> ><detail::GitStorageType<IInspectable> >(detail::GitStorageType<IInspectable> const &,long *);
	};

	struct ComLock
	{
		ComLock(bool);
	};

	namespace FakeStl
	{
		void swap<XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<IInspectable *> > >(XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<IInspectable *> > &,XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<IInspectable *> > &);
		void swap<XHashMap<HSTRING__ *,detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<detail::GitStorageType<IInspectable> > > >(XHashMap<HSTRING__ *,detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<detail::GitStorageType<IInspectable> > > &,XHashMap<HSTRING__ *,detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<detail::GitStorageType<IInspectable> > > &);
		void swap<XHashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<unsigned char> > >(XHashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<unsigned char> > &,XHashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<unsigned char> > &);
		void swap<XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,CElementTraits<unsigned int> > >(XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,CElementTraits<unsigned int> > &,XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,CElementTraits<unsigned int> > &);
		void swap<XHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> > >(XHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> > &,XHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> > &);
		void swap<XHashMap<_GUID,unsigned char,Windows::Foundation::Collections::Internal::HashMap<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<unsigned char> > >(XHashMap<_GUID,unsigned char,Windows::Foundation::Collections::Internal::HashMap<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<unsigned char> > &,XHashMap<_GUID,unsigned char,Windows::Foundation::Collections::Internal::HashMap<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<unsigned char> > &);
		void swap<XHashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<unsigned int>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> > >(XHashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<unsigned int>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> > &,XHashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<unsigned int>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> > &);
	};

	struct InterfaceLifetimeTraits
	{
		static long Construct<IInspectable>(IInspectable * *,IInspectable *);
		static void Destroy<IInspectable>(IInspectable * *);
	};

	namespace SecureVersionTag
	{
		struct Tag
		{
			long Release();
		};

		struct TagManager
		{
			long ChangeVersion();
			long Initialize();
		};

	};

	struct SerializingLockPolicy
	{
		static detail::LockHolder<ComLock,detail::AcquireRead> Read(ComLock &,long *);
		static detail::LockHolder<ComLock,detail::AcquireWrite> Write(ComLock &,long *);
	};

	struct StringEquals
	{
		long operator()(HSTRING__ *,HSTRING__ *,bool *);
	};

	struct StringHash
	{
		long operator()(HSTRING__ *,unsigned int *);
	};

	class XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<IInspectable *> >
	{
		long CreateNode(HSTRING__ * const &,unsigned int,unsigned int,XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<IInspectable *> >::CNode * *);
		long FreeNode(XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<IInspectable *> >::CNode *);
		long GetNode(HSTRING__ * const &,unsigned int &,unsigned int &,XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<IInspectable *> >::CNode * &,XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<IInspectable *> >::CNode * *);
		long NewNode(HSTRING__ * const &,unsigned int,unsigned int,XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<IInspectable *> >::CNode * *);
		unsigned int PickSize(unsigned __int64);
		void FreePlexes();
		void UpdateRehashThresholds();
	public:
		TXPOSITION * GetStartPosition();
		XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<IInspectable *> >(void *,unsigned int,float,float,float,unsigned int);
		long InitHashTable(unsigned int,bool,bool *);
		long Lookup(HSTRING__ * const &,XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<IInspectable *> >::CPair * *);
		long Rehash(unsigned int);
		long RemoveAll();
		long RemoveAtPos(TXPOSITION *);
		long SetAt(HSTRING__ * const &,IInspectable * const &,TXPOSITION * *);
	};

	class XHashMap<HSTRING__ *,detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<detail::GitStorageType<IInspectable> > >
	{
		long CreateNode(HSTRING__ * const &,unsigned int,unsigned int,XHashMap<HSTRING__ *,detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<detail::GitStorageType<IInspectable> > >::CNode * *);
		long FreeNode(XHashMap<HSTRING__ *,detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<detail::GitStorageType<IInspectable> > >::CNode *);
		long GetNode(HSTRING__ * const &,unsigned int &,unsigned int &,XHashMap<HSTRING__ *,detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<detail::GitStorageType<IInspectable> > >::CNode * &,XHashMap<HSTRING__ *,detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<detail::GitStorageType<IInspectable> > >::CNode * *);
		long NewNode(HSTRING__ * const &,unsigned int,unsigned int,XHashMap<HSTRING__ *,detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<detail::GitStorageType<IInspectable> > >::CNode * *);
		unsigned int PickSize(unsigned __int64);
		void FreePlexes();
		void UpdateRehashThresholds();
	public:
		TXPOSITION * GetStartPosition();
		XHashMap<HSTRING__ *,detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<detail::GitStorageType<IInspectable> > >(void *,unsigned int,float,float,float,unsigned int);
		long InitHashTable(unsigned int,bool,bool *);
		long Lookup(HSTRING__ * const &,XHashMap<HSTRING__ *,detail::GitStorageType<IInspectable>,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<detail::GitStorageType<IInspectable> > >::CPair * *);
		long Rehash(unsigned int);
		long RemoveAll();
		long RemoveAtPos(TXPOSITION *);
		long SetAt(HSTRING__ * const &,detail::GitStorageType<IInspectable> const &,TXPOSITION * *);
	};

	class XHashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<unsigned char> >
	{
		long CreateNode(HSTRING__ * const &,unsigned int,unsigned int,XHashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<unsigned char> >::CNode * *);
		long FreeNode(XHashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<unsigned char> >::CNode *);
		long GetNode(HSTRING__ * const &,unsigned int &,unsigned int &,XHashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<unsigned char> >::CNode * &,XHashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<unsigned char> >::CNode * *);
		long NewNode(HSTRING__ * const &,unsigned int,unsigned int,XHashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<unsigned char> >::CNode * *);
		unsigned int PickSize(unsigned __int64);
		void FreePlexes();
		void UpdateRehashThresholds();
	public:
		TXPOSITION * GetStartPosition();
		XHashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<unsigned char> >(void *,unsigned int,float,float,float,unsigned int);
		long InitHashTable(unsigned int,bool,bool *);
		long Lookup(HSTRING__ * const &,XHashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned char>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,unsigned char,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<unsigned char> >::CPair * *);
		long Rehash(unsigned int);
		long RemoveAll();
		long RemoveAtPos(TXPOSITION *);
		long SetAt(HSTRING__ * const &,unsigned char,TXPOSITION * *);
	};

	class XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,CElementTraits<unsigned int> >
	{
		long CreateNode(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair const &,unsigned int,unsigned int,XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,CElementTraits<unsigned int> >::CNode * *);
		long FreeNode(XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,CElementTraits<unsigned int> >::CNode *);
		long GetNode(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair const &,unsigned int &,unsigned int &,XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,CElementTraits<unsigned int> >::CNode * &,XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,CElementTraits<unsigned int> >::CNode * *);
		long NewNode(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair const &,unsigned int,unsigned int,XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,CElementTraits<unsigned int> >::CNode * *);
		unsigned int PickSize(unsigned __int64);
		void FreePlexes();
		void UpdateRehashThresholds();
	public:
		TXPOSITION * GetStartPosition();
		XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,CElementTraits<unsigned int> >(void *,unsigned int,float,float,float,unsigned int);
		long InitHashTable(unsigned int,bool,bool *);
		long Lookup(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair const &,XHashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,Windows::Foundation::Collections::Internal::HashMap<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameHashFunction,CPackagedComCatalog::TypeLibVersionLocaleIdPairRegistryNameEqualityPredicate,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int,CPackagedComCatalog::TypeLibVersionLocaleIdPairLifetimeTraits> >::KeyTraits,CElementTraits<unsigned int> >::CPair * *);
		long Rehash(unsigned int);
		long RemoveAll();
		long RemoveAtPos(TXPOSITION *);
		long SetAt(PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair const &,unsigned int,TXPOSITION * *);
	};

	class XHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >
	{
		long CreateNode(_GUID const &,unsigned int,unsigned int,XHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode * *);
		long FreeNode(XHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode *);
		long GetNode(_GUID const &,unsigned int &,unsigned int &,XHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode * &,XHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode * *);
		long NewNode(_GUID const &,unsigned int,unsigned int,XHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode * *);
		unsigned int PickSize(unsigned __int64);
		void FreePlexes();
		void UpdateRehashThresholds();
	public:
		TXPOSITION * GetStartPosition();
		XHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >(void *,unsigned int,float,float,float,unsigned int);
		long InitHashTable(unsigned int,bool,bool *);
		long Lookup(_GUID const &,XHashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CPair * *);
		long Rehash(unsigned int);
		long RemoveAll();
		long RemoveAtPos(TXPOSITION *);
		long SetAt(_GUID const &,HSTRING__ * const &,TXPOSITION * *);
	};

	class XHashMap<_GUID,unsigned char,Windows::Foundation::Collections::Internal::HashMap<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<unsigned char> >
	{
		long CreateNode(_GUID const &,unsigned int,unsigned int,XHashMap<_GUID,unsigned char,Windows::Foundation::Collections::Internal::HashMap<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<unsigned char> >::CNode * *);
		long FreeNode(XHashMap<_GUID,unsigned char,Windows::Foundation::Collections::Internal::HashMap<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<unsigned char> >::CNode *);
		long GetNode(_GUID const &,unsigned int &,unsigned int &,XHashMap<_GUID,unsigned char,Windows::Foundation::Collections::Internal::HashMap<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<unsigned char> >::CNode * &,XHashMap<_GUID,unsigned char,Windows::Foundation::Collections::Internal::HashMap<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<unsigned char> >::CNode * *);
		long NewNode(_GUID const &,unsigned int,unsigned int,XHashMap<_GUID,unsigned char,Windows::Foundation::Collections::Internal::HashMap<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<unsigned char> >::CNode * *);
		unsigned int PickSize(unsigned __int64);
		void FreePlexes();
		void UpdateRehashThresholds();
	public:
		TXPOSITION * GetStartPosition();
		XHashMap<_GUID,unsigned char,Windows::Foundation::Collections::Internal::HashMap<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<unsigned char> >(void *,unsigned int,float,float,float,unsigned int);
		long InitHashTable(unsigned int,bool,bool *);
		long Lookup(_GUID const &,XHashMap<_GUID,unsigned char,Windows::Foundation::Collections::Internal::HashMap<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultHash<_GUID>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<bool>,Windows::Foundation::Collections::Internal::HashMapOptions<_GUID,bool,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<_GUID>,0,1,0> >::KeyTraits,CElementTraits<unsigned char> >::CPair * *);
		long Rehash(unsigned int);
		long RemoveAll();
		long RemoveAtPos(TXPOSITION *);
		long SetAt(_GUID const &,unsigned char,TXPOSITION * *);
	};

	class XHashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<unsigned int>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >
	{
		long CreateNode(unsigned int,unsigned int,unsigned int,XHashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<unsigned int>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode * *);
		long FreeNode(XHashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<unsigned int>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode *);
		long GetNode(unsigned int,unsigned int &,unsigned int &,XHashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<unsigned int>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode * &,XHashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<unsigned int>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode * *);
		long NewNode(unsigned int,unsigned int,unsigned int,XHashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<unsigned int>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode * *);
		unsigned int PickSize(unsigned __int64);
		void FreePlexes();
		void UpdateRehashThresholds();
	public:
		TXPOSITION * GetStartPosition();
		XHashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<unsigned int>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >(void *,unsigned int,float,float,float,unsigned int);
		long InitHashTable(unsigned int,bool,bool *);
		long Lookup(unsigned int,XHashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<unsigned int>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<unsigned int,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<unsigned int>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CPair * *);
		long Rehash(unsigned int);
		long RemoveAll();
		long RemoveAtPos(TXPOSITION *);
		long SetAt(unsigned int,HSTRING__ * const &,TXPOSITION * *);
	};

	struct XPlex
	{
		static XPlex * Create(XPlex * &,unsigned __int64,unsigned __int64);
		void FreeDataChain();
	};

	namespace detail
	{
		struct GitStorageType<IInspectable>
		{
			struct ReferencedGitCookie
			{
				long Localize(IInspectable * *);
				unsigned long Release();
			};

			long Initialize(IInspectable *);
		};

		struct ReentrancyGuard<0>
		{
			ReentrancyGuard<0>(...);
		};

	};

	unsigned int Fnv1a(unsigned char const *,unsigned __int64);
};

namespace std
{
	struct default_delete<ResourceStrings::ResourceStringStorage>
	{
		void operator()(ResourceStrings::ResourceStringStorage *);
	};

	struct exception
	{
		exception(exception const &);
		virtual char const * what();
	};

	struct unique_ptr<RegistryPathWatcher,default_delete<RegistryPathWatcher> >
	{
		~unique_ptr<RegistryPathWatcher,default_delete<RegistryPathWatcher> >();
	};

	struct unique_ptr<unsigned char,PrivMemDeleter>
	{
		~unique_ptr<unsigned char,PrivMemDeleter>();
	};

	std::pair<PackageIdAndInstallOrder *,PackageIdAndInstallOrder *> _Partition_by_median_guess_unchecked<PackageIdAndInstallOrder *,bool (*)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &)>(PackageIdAndInstallOrder *,PackageIdAndInstallOrder *,bool (*&)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &));
	void _Atomic_store_8(unsigned __int64 volatile *,unsigned __int64,std::memory_order);
	void _Guess_median_unchecked<PackageIdAndInstallOrder *,bool (*)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &)>(PackageIdAndInstallOrder *,PackageIdAndInstallOrder *,PackageIdAndInstallOrder *,bool (*&)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &));
	void _Insertion_sort_unchecked<PackageIdAndInstallOrder *,bool (*)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &)>(PackageIdAndInstallOrder *,PackageIdAndInstallOrder *,bool (*&)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &));
	void _Make_heap_unchecked<PackageIdAndInstallOrder *,bool (*)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &)>(PackageIdAndInstallOrder *,PackageIdAndInstallOrder *,bool (*&)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &));
	void _Med3_unchecked<PackageIdAndInstallOrder *,bool (*)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &)>(PackageIdAndInstallOrder *,PackageIdAndInstallOrder *,PackageIdAndInstallOrder *,bool (*&)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &));
	void _Reverse_unchecked<ObjectLibrary::ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation> *>(ObjectLibrary::ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation> *,ObjectLibrary::ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation> *);
	void _Reverse_unchecked<ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> *>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> *,ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> *);
	void _Sort_heap_unchecked<PackageIdAndInstallOrder *,bool (*)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &)>(PackageIdAndInstallOrder *,PackageIdAndInstallOrder *,bool (*&)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &));
	void _Sort_unchecked1<PackageIdAndInstallOrder *,__int64,bool (*)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &)>(PackageIdAndInstallOrder *,PackageIdAndInstallOrder *,__int64,bool (*&)(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &));
	void swap<Microsoft::WRL::ComPtr<IRestrictedErrorInfo>,void>(Microsoft::WRL::ComPtr<IRestrictedErrorInfo> &,Microsoft::WRL::ComPtr<IRestrictedErrorInfo> &);
	void swap<ObjectLibrary::ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation>,void>(ObjectLibrary::ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation> &,ObjectLibrary::ReferencedPtr<RegistrationChangeDetection::PerUserCacheInformation> &);
	void swap<ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo>,void>(ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> &,ObjectLibrary::ReferencedPtr<WinrtAsyncProxyMethodInfo> &);
};

namespace wil
{
	class ActivityBase<WinRT::Metadata::Marshaling::MbmTelemetry,0,0,5,_TlgReflectorTag_Param0IsProviderType>
	{
		struct ActivityData<WinRT::Metadata::Marshaling::MbmTelemetry,_TlgReflectorTag_Param0IsProviderType>
		{
			bool SetStopResult(long,long *);
			~ActivityData<WinRT::Metadata::Marshaling::MbmTelemetry,_TlgReflectorTag_Param0IsProviderType>();
		};

	protected:
		void Destroy();
	public:
		ActivityBase<WinRT::Metadata::Marshaling::MbmTelemetry,0,0,5,_TlgReflectorTag_Param0IsProviderType>(char const *,bool);
		_GUID const * zInternalRelatedId();
		virtual bool NotifyFailure(FailureInfo const &);
		void Stop(long);
		void zInternalStart();
		void zInternalStop();
		~ActivityBase<WinRT::Metadata::Marshaling::MbmTelemetry,0,0,5,_TlgReflectorTag_Param0IsProviderType>();
	};

	struct ActivityBase<WinRT::Metadata::Marshaling::MbmTelemetry,1,35184372088832,5,_TlgReflectorTag_Param0IsProviderType>
	{
		struct ActivityData<WinRT::Metadata::Marshaling::MbmTelemetry,_TlgReflectorTag_Param0IsProviderType>
		{
			bool SetStopResult(long,long *);
			~ActivityData<WinRT::Metadata::Marshaling::MbmTelemetry,_TlgReflectorTag_Param0IsProviderType>();
		};

		_GUID const * zInternalRelatedId();
		virtual bool NotifyFailure(FailureInfo const &);
		void Stop(long);
		void zInternalStop();
	};

	class Feature<__WilFeatureTraits_Feature_PerAppRuntimeBroker>
	{
		static wil_details_CachedFeatureEnabledState GetCachedFeatureEnabledState(bool);
	};

	class Feature<__WilFeatureTraits_Feature_Registration_Free_MBM>
	{
		static wil_details_CachedFeatureEnabledState GetCachedFeatureEnabledState(bool);
	};

	struct IterableRangeNoThrow<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>
	{
		struct IterableIteratorNoThrow
		{
			IterableRangeNoThrow<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>::IterableIteratorNoThrow & operator++();
		};

		IterableRangeNoThrow<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>(Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> *,long *);
	};

	struct IterableRangeNoThrow<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *>
	{
		struct IterableIteratorNoThrow
		{
			IterableRangeNoThrow<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *>::IterableIteratorNoThrow & operator++();
		};

		IterableRangeNoThrow<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *>(Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<PackagedComCatalog::Internal::TypeLibVersionLocaleIdPair,unsigned int> *> *,long *);
	};

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

	class TraceLoggingProvider
	{
		virtual bool NotifyFailure(FailureInfo const &);
	protected:
		virtual void Initialize();
		virtual void OnErrorReported(bool,FailureInfo const &);
		virtual ~TraceLoggingProvider();
		void Register(_TlgProvider_t const * const);
		void ReportTelemetryFailure(FailureInfo const &);
		void ReportTraceLoggingFailure(FailureInfo const &);
	};

	namespace details
	{
		struct DestroyThreadPoolTimer<0>
		{
			static void Destroy(_TP_TIMER *);
		};

		class EnabledStateManager
		{
			void EnsureSubscribedToStateChangesUnderLock();
			void RecordCachedUsageUnderLock();
		public:
			void EnsureSubscribedToUsageFlush(void (*)(void *));
			void OnStateChange();
			void OnTimer();
			void QueueBackgroundUsageReporting(unsigned int,wil_details_FeaturePropertyCache &);
			void SubscribeFeaturePropertyCacheToEnabledStateChanges(wil_details_FeaturePropertyCache *,wil_FeatureChangeTime);
		};

		class FeatureStateManager
		{
			bool EnsureStateData();
			void EnsureSubscribedToProcessWideUsageFlushUnderLock();
		public:
			FeatureStateManager();
			void RecordFeatureUsage(unsigned int,wil_details_ServiceReportingKind,unsigned __int64);
			void SubscribeToEnabledStateChanges(FEATURE_STATE_CHANGE_SUBSCRIPTION__ * *,void (*)(void *),void *);
			void SubscribeToUsageFlush(FEATURE_STATE_CHANGE_SUBSCRIPTION__ * *,void (*)(void *));
			~FeatureStateManager();
		};

		class ThreadFailureCallbackHolder
		{
			static long volatile s_telemetryId;
		public:
			static bool GetThreadContext(FailureInfo *,ThreadFailureCallbackHolder *,char *,unsigned __int64);
			void StartWatching();
			void StopWatching();
		};

		namespace in1diag3
		{
			long Log_Hr(void *,unsigned int,char const *,long);
			long Return_GetLastError(void *,unsigned int,char const *);
			long Return_GetLastErrorMsg(void *,unsigned int,char const *,char const *,...);
			long Return_NtStatus(void *,unsigned int,char const *,long);
			long Return_Win32(void *,unsigned int,char const *,unsigned long);
			void FailFast_Unexpected(void *,unsigned int,char const *);
			void FailFast_UnexpectedMsg(void *,unsigned int,char const *,char const *,...);
			void Return_Hr(void *,unsigned int,char const *,long);
			void Return_HrMsg(void *,unsigned int,char const *,long,char const *,...);
			void Return_HrMsg_NoOriginate(void *,unsigned int,char const *,long,char const *,...);
			void Return_Hr_NoOriginate(void *,unsigned int,char const *,long);
			void _FailFastImmediate_Unexpected();
			void _FailFast_GetLastError(void *,unsigned int,char const *);
			void _FailFast_Unexpected(void *,unsigned int,char const *);
			void _Log_Hr(void *,unsigned int,char const *,long);
		};

		class shared_buffer
		{
			void assign(long *,unsigned __int64);
		public:
			bool create(void const *,unsigned __int64);
			void reset();
		};

		struct shared_object<ActivityBase<WinRT::Metadata::Marshaling::MbmTelemetry,0,0,5,_TlgReflectorTag_Param0IsProviderType>::ActivityData<WinRT::Metadata::Marshaling::MbmTelemetry,_TlgReflectorTag_Param0IsProviderType> >
		{
			void reset();
		};

		struct shared_object<ActivityBase<WinRT::Metadata::Marshaling::MbmTelemetry,1,35184372088832,5,_TlgReflectorTag_Param0IsProviderType>::ActivityData<WinRT::Metadata::Marshaling::MbmTelemetry,_TlgReflectorTag_Param0IsProviderType> >
		{
			void reset();
		};

		struct static_lazy<ComTrace>
		{
			ComTrace * get(void (*)());
			void cleanup();
		};

		struct static_lazy<WinRT::Metadata::Marshaling::MbmTelemetry>
		{
			WinRT::Metadata::Marshaling::MbmTelemetry * get(void (*)());
			void cleanup();
		};

		FEATURE_ENABLED_STATE WilApiImpl_GetFeatureEnabledState(unsigned int,FEATURE_CHANGE_TIME);
		FEATURE_ENABLED_STATE WilApi_GetFeatureEnabledState(unsigned int,FEATURE_CHANGE_TIME);
		bool GetModuleInformation(void *,unsigned int *,char *,unsigned __int64);
		bool IsFeatureConfigured(wil_FeatureState *,unsigned int,bool,wil_FeatureStore);
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
		long NtStatusToHr(long);
		long ReportFailure_GetLastErrorHr(void *,unsigned int,char const *,char const *,char const *,void *,FailureType);
		long ReportFailure_GetLastErrorHrMsg(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,char const *,char *);
		long ReportFailure_NtStatus(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long);
		long ReportFailure_Win32(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,unsigned long);
		long StringCchPrintfA(char *,unsigned __int64,char const *,...);
		shutdown_aware_object<details::EnabledStateManager> g_enabledStateManager;
		shutdown_aware_object<details::FeatureStateManager> g_featureStateManager;
		unsigned __int64 ResultStringSize(char const *);
		unsigned __int64 ResultStringSize(unsigned short const *);
		unsigned __int64 ResultStringSize(wchar_t const *);
		unsigned char (* g_pfnRtlDllShutdownInProgress)();
		unsigned char * WriteResultString<char const *>(unsigned char *,unsigned char *,char const *,char const * *);
		unsigned char * WriteResultString<unsigned short const *>(unsigned char *,unsigned char *,unsigned short const *,unsigned short const * *);
		unsigned char * WriteResultString<wchar_t const *>(unsigned char *,unsigned char *,wchar_t const *,wchar_t const * *);
		unsigned char RtlDllShutdownInProgress();
		unsigned long (* g_pfnRtlNtStatusToDosErrorNoTeb)(long);
		unsigned long GetLastErrorFail(void *,unsigned int,char const *,char const *,char const *,void *);
		unsigned long ReportFailure_GetLastError(void *,unsigned int,char const *,char const *,char const *,void *,FailureType);
		unsigned long RtlNtStatusToDosErrorNoTeb(long);
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
		void RecordFeatureUsageCallback(unsigned int,wil_details_FeaturePropertyCache *,wil_details_RecordUsageResult *);
		void ReleaseMutex(void *);
		void ReportFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,unsigned short const *,details::ReportFailureOptions);
		void ReportFailure_Hr(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long);
		void ReportFailure_HrMsg(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,char const *,char *);
		void ReportFailure_Msg(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,char const *,char *);
		void Rethrow();
		void ThrowResultExceptionInternal(FailureInfo const &);
		void WilApiImpl_RecordFeatureUsage(unsigned int,unsigned int,unsigned int,char const *);
		void WilApiImpl_SubscribeFeatureStateChangeNotification(FEATURE_STATE_CHANGE_SUBSCRIPTION__ * *,void (*)(void *),void *);
		void WilApiImpl_UnsubscribeFeatureStateChangeNotification(FEATURE_STATE_CHANGE_SUBSCRIPTION__ *);
		void WilApi_RecordFeatureUsage(unsigned int,unsigned int,unsigned int,char const *);
		void WilApi_SubscribeFeatureStateChangeNotification(FEATURE_STATE_CHANGE_SUBSCRIPTION__ * *,void (*)(void *),void *);
		void WilApi_UnsubscribeFeatureStateChangeNotification(FEATURE_STATE_CHANGE_SUBSCRIPTION__ *);
	};

	namespace details_abi
	{
		class FeatureStateData
		{
			void RetrieveUsageUnderLock(UsageIndexes &);
		public:
			bool RecordFeatureUsage(unsigned int,wil_details_ServiceReportingKind,unsigned __int64);
			void ProcessShutdown();
			void RecordUsage();
		};

		struct ProcessLocalStorage<ProcessLocalData>
		{
			ProcessLocalData * GetShared();
			~ProcessLocalStorage<ProcessLocalData>();
		};

		struct ProcessLocalStorageData<FeatureStateData>
		{
			static long Acquire(char const *,ProcessLocalStorageData<FeatureStateData> * *);
			void Release();
		};

		struct ProcessLocalStorageData<ProcessLocalData>
		{
			static long Acquire(char const *,ProcessLocalStorageData<ProcessLocalData> * *);
			void Release();
			~ProcessLocalStorageData<ProcessLocalData>();
		};

		class RawUsageIndex
		{
			bool RecordUsageInternal(void *,unsigned __int64,void *,unsigned __int64,unsigned int);
			unsigned char * FindInsertionPointOrIncrement(UsageIndexProperty &,unsigned char *,void *,unsigned __int64,unsigned int);
			unsigned char * LowerBound(unsigned char *,unsigned __int64,void *,unsigned __int64);
		public:
			RawUsageIndex(unsigned short,unsigned short,CountSize,unsigned short,CountSize);
			bool Iterate(wistd::function<bool (void *,unsigned __int64,void *,unsigned __int64,unsigned int)>);
			bool RecordUsage(void *,unsigned __int64,void *,unsigned __int64,unsigned int);
			void SetBuffer(void *,unsigned __int64,unsigned __int64);
			void Swap(RawUsageIndex &);
		};

		class SemaphoreValue
		{
			long CreateFromValueInternal(unsigned short const *,bool,unsigned __int64);
			static long GetValueFromSemaphore(void *,long *);
			static long TryGetValueInternal(unsigned short const *,bool,unsigned __int64 *,bool *);
		public:
			static long TryGetPointer(unsigned short const *,void * *);
			void Destroy();
		};

		struct SubscriptionList
		{
			SubscriptionList();
			void OnSignaled(srwlock &);
			void SubscribeUnderLock(FEATURE_STATE_CHANGE_SUBSCRIPTION__ * *,void (*)(void *),void *);
			void Unsubscribe(srwlock &,FEATURE_STATE_CHANGE_SUBSCRIPTION__ *);
		};

		struct ThreadLocalData
		{
			void SetLastError(FailureInfo const &);
		};

		struct ThreadLocalFailureInfo
		{
			void Set(FailureInfo const &,unsigned int);
		};

		struct ThreadLocalStorage<ThreadLocalData>
		{
			ThreadLocalData * GetLocal(bool);
		};

		struct ThreadLocalStorage<details::ThreadFailureCallbackHolder *>
		{
			details::ThreadFailureCallbackHolder * * GetLocal(bool);
			~ThreadLocalStorage<details::ThreadFailureCallbackHolder *>();
		};

		struct UsageIndexProperty
		{
			bool AddToCount(unsigned int);
			bool Read(unsigned char * &,unsigned char *);
			bool Write(unsigned char * &,unsigned char *);
			int Compare(void *,unsigned __int64);
			unsigned __int64 GetSize();
			void UpdateCount(unsigned int);
		};

		struct UsageIndexes
		{
			UsageIndexes();
			void Record();
			~UsageIndexes();
		};

		struct heap_buffer
		{
			bool ensure(unsigned __int64);
			bool push_back(void const *,unsigned __int64);
			bool reserve(unsigned __int64);
		};

		details_abi::ProcessLocalStorage<details_abi::ProcessLocalData> * g_pProcessLocalData;
		details_abi::ThreadLocalData * GetThreadLocalDataCache(bool);
		void RecordWnfUsageIndex(__WIL__WNF_STATE_NAME const *,unsigned __int64,details_abi::RawUsageIndex const &);
	};

	struct shutdown_aware_object<details::EnabledStateManager>
	{
		shutdown_aware_object<details::EnabledStateManager>();
		~shutdown_aware_object<details::EnabledStateManager>();
	};

	struct shutdown_aware_object<details::FeatureStateManager>
	{
		shutdown_aware_object<details::FeatureStateManager>();
		~shutdown_aware_object<details::FeatureStateManager>();
	};

	struct unique_any_array_ptr<PACKAGE_INFO,PrivMemDeleter,empty_deleter>
	{
		void reset();
	};

	bool (* g_pfnIsDebuggerPresent)();
	bool ProcessShutdownInProgress();
	bool g_fBreakOnFailure;
	bool g_fIsDebuggerPresent;
	long GetFailureLogString(unsigned short *,unsigned __int64,wil::FailureInfo const &);
	wistd::unique_ptr<unsigned short [0],wistd::default_delete<unsigned short [0]> > make_unique_nothrow<unsigned short [0]>(unsigned __int64);
};

namespace wistd
{
	class _Func_class<bool,void *,unsigned __int64,void *,unsigned __int64,unsigned int,_Nil,_Nil>
	{
	protected:
		void _Tidy();
	};

};

;
<unnamed-type-MTAPendingCallList> MTAPendingCallList;
?CreateRestrictedErrorWrapper@@YAJPEAX$$QEAVCRestrictedError@@PEAPEAUIRestrictedErrorInfo@@@Z;
APTKIND GetCurrentApartmentKind(COleTls &);
ASTAWaitSatisfiedReason ASTAWaitInExistingContext(BlockingReason,unsigned int,void * const *,unsigned long,unsigned int *,unsigned long *);
ASTAWaitSatisfiedReason ASTAWaitInNewContext(BlockingReason,unsigned int,void * const *,unsigned long,bool,bool,ASTAWaitWindowMessageDispatch,unsigned long,unsigned int *,unsigned long *);
ASTAWaitSatisfiedReason ASTAWaitReturnValueToSatisfiedReasonAndIndex(BlockingReason,unsigned int,unsigned long,unsigned int *);
ASTA_TEST_MODE_FLAGS g_astaTestModeFlags;
BuiltInClassCache * s_pCacheBuiltInClassInfo;
BuiltInClassCache * s_pCacheInboxAppClassInfo;
C2Security gC2Security;
CAddrControl gAddrControl;
CApartmentActivator gApartmentActivator;
CApartmentHashTable gApartmentTbl;
CCache * s_pCacheApplicationInfo;
CCache * s_pCacheClassInfo;
CCache * s_pCacheInboxAppProxyStubClassInfo;
CCache * s_pCacheInboxAppRuntimeClassInfo;
CCache * s_pCacheInboxAppServerInfo;
CCache * s_pCachePerUserProxyStubClassInfo;
CCache * s_pCachePerUserRuntimeClassInfo;
CCache * s_pCachePerUserServerInfo;
CCache * s_pCacheProcessInfo;
CCache * s_pCacheProgID;
CCache * s_pCacheWinRTRuntimeClassInfo;
CCache * s_pCacheWinRTServerInfo;
CCallTable gCallTbl;
CClientContextActivator gComClientCtxActivator;
CComApartment * gpMTAApartment;
CComApartment * gpNTAApartment;
CComSxSCatalog * g_pSxSCatalogObject;
CCtxHook gCtxHook;
CDebugChannelHook gDebugHook;
CDebugEventFireCF g_EventFireCF;
CDllHost gATHost;
CDllHost gMTHost;
CDllHost gNTHost;
CDllHost gSTHost;
CDllHost gSTMTHost;
CEndpointsTable gEndpointsTable;
CErrorChannelHook gErrorHook;
CEventCache gEventCache;
CGIPTable gGIPTbl;
CIPIDTable gIPIDTbl;
CMIDTable gMIDTbl;
CMachineGlobalObjectTable * g_pMgot;
CMalloc g_CMalloc;
CNameHashTable gSRFTbl;
COIDTable gOIDTable;
COM_CATALOG_CACHE_SECTION * s_pReadCatalogCache;
COXIDTable gOXIDTbl;
CObjServer * GetObjServer();
CObjServer * gpMTAObjServer;
CObjServer * gpNTAObjServer;
CObjectContext * EnterNTA(CObjectContext *);
CObjectContext * GetCurrentContext();
CObjectContext * GetEmptyContext();
CObjectContext * GetThreadDefaultContext();
CObjectContext * LeaveNTA(CObjectContext *);
CObjectContext * SwitchContext(CObjectContext *);
CObjectContext * g_pMTAEmptyCtx;
CObjectContext * g_pNTAEmptyCtx;
COleStaticMutexSem gCallLock;
COleStaticMutexSem gChannelInitLock;
COleStaticMutexSem gChnlCallLock;
COleStaticMutexSem gComLock;
COleStaticMutexSem gContextLock;
COleStaticMutexSem gIPIDLock;
COleStaticMutexSem gOXIDLock;
COleStaticMutexSem gObjectTrackingLock;
COleStaticMutexSem gSecurityLockPermissions;
COleStaticMutexSem gSecurityLockRestrictions;
COleStaticMutexSem gTlsLock;
COleStaticMutexSem g_MTAInitLock;
COleStaticMutexSem g_SpySem;
COleStaticMutexSem g_mxsSingleThreadOle;
COleStaticMutexSem g_serverMonLock;
CPIDTable gPIDTable;
CPSTable gPSTable;
CProcessActivator gComProcessActivator;
CProcessSecret gProcessSecret;
CRGTypeSizes g_TypeSizes;
CRIFTable gRIFTbl;
CROIDTable gROIDTbl;
CRWLock gPSRWLock;
CRandomNumberGenerator gRNG;
CRpcResolver gResolver;
CRpcThreadCache gRpcThreadCache;
CServerContextActivator gComServerCtxActivator;
CSpyTable * g_pAllocTbl;
CStaticWrapper * gpStaticWrapper;
CStdIdentity * GetStdIdFromIPID(_GUID const &,bool,bool *);
CStdWrapper * ObtainWrapper(IUnknown *,int,unsigned long);
CSurrogateProcessActivator * s_pCSPA;
CSuspendMonitor gSuspendMonitor;
CThreadStack gThrdStack;
CVerifierTlsData * AllocVerifierTlsData();
CWinRTApartmentActivator gWinRTApartmentActivator;
CWorldSecurityDescriptor * gLrpcSecurityDescriptor;
DiagnosticBuffer<AstaTimedOutCallInfo,10> g_lastAstaTimedOutCalls;
EffectiveUnmarshalingPolicy EffectiveUnmarshalingPolicyForInternalSource();
EffectiveUnmarshalingPolicy EffectiveUnmarshalingPolicyForSourceAppContainerStatus(bool);
EffectiveUnmarshalingPolicy EffectiveUnmarshalingPolicyForUnknownSource();
FEATURE_ENABLED_STATE (* g_wil_details_apiGetFeatureEnabledState)(unsigned int,FEATURE_CHANGE_TIME);
FEATURE_ENABLED_STATE (* g_wil_details_internalGetFeatureEnabledState)(unsigned int,FEATURE_CHANGE_TIME);
HINSTANCE__ * HkLoadInProcServer(_GUID const &);
HINSTANCE__ * g_hComSvcs;
HINSTANCE__ * g_hinst;
HINSTANCE__ * g_wil_details_ntdllModuleHandle;
HINSTANCE__ * glhHookDll;
HINSTANCE__ * hOle32;
HINSTANCE__ * hOleAut32;
HINSTANCE__ * wil_details_GetNtDllModuleHandle();
HKEY__ * cachedHKCR;
HWND__ * GetOrCreateSTAWindow();
HWND__ * ghwndOleMainThread;
IAccessControl * gAccessControl;
IActivationFilter * g_ActivationFilter;
IAsyncCallCancelListenerTestHook * gpAsyncCallCancelListenerTestHook;
IAsyncRpcChannelBufferVtbl const AsyncChannelWrapperVtbl;
ICallFactoryVtbl const CStdProxyBuffer2_CallFactoryVtbl;
ICallFactoryVtbl const CStdProxyBuffer_CallFactoryVtbl;
ICallFactoryVtbl const CStdStubBuffer2_CallFactoryVtbl;
ICallFactoryVtbl const CStdStubBuffer_CallFactoryVtbl;
IComCatalog * gpCatalog;
IContainerIdListenerTestHook * g_pContainerIdListenerTestHook;
ICreatePerInterfacePSFactoryVtbl const CStdPSFactoryBufferVtbl;
IMalloc * g_pIMalloc;
IMallocSpy * g_pMallocSpy;
IMarshal * gpStdMarshal;
IReleaseMarshalBuffersVtbl const CStdAsyncProxyBuffer_ReleaseMarshalBuffersVtbl;
IReleaseMarshalBuffersVtbl const CStdAsyncStubBuffer_ReleaseMarshalBuffersVtbl;
IReleaseMarshalBuffersVtbl const CStdProxyBuffer_ReleaseMarshalBuffersVtbl;
IReleaseMarshalBuffersVtbl const CStdStubBuffer_ReleaseMarshalBuffersVtbl;
IRpcChannelBuffer3Vtbl const ChannelWrapperVtbl;
IRpcProxyBufferVtbl const CStdProxyBuffer2Vtbl;
IRpcProxyBufferVtbl const CStdProxyBuffer3Vtbl;
IRpcProxyBufferVtbl const CStdProxyBufferVtbl;
IRpcStubBufferVtbl const CStdStubBuffer2Vtbl;
IRpcStubBufferVtbl const CStdStubBufferVtbl;
IRuntimeBroker * GetCachedRuntimeBroker(bool);
ISynchronizeVtbl const CStdAsyncStubBuffer_ISynchronizeVtbl;
ISystemActivator * GetComActivatorForStage(tagACTIVATION_STAGE);
MTA_HOST_USAGE_FLAGS g_fMTAHostUsageFlags;
Microsoft::WRL::Details::CreatorMap const __object_ActivationContext;
Microsoft::WRL::Details::CreatorMap const __object_CExtensionCatalog;
Microsoft::WRL::Details::FactoryCache __objectFactory__ActivationContext;
Microsoft::WRL::Details::FactoryCache __objectFactory__CExtensionCatalog;
Microsoft::WRL::Wrappers::CriticalSection typeCacheLock;
Microsoft::WRL::Wrappers::SRWLock gSuspendLock;
Microsoft::WRL::Wrappers::SRWLock g_ContainerIdListenerTestHookLock;
Microsoft::WRL::Wrappers::SRWLock g_lastAstaTimedOutCallsLock;
OXIDEntry * GetOXIDFromObjRef(tagOBJREF const &);
ObjectLibrary::ReferencedPtr<ArrayOfGuids> GetDynamicInterfacesOfInterest();
ObjectLibrary::ReferencedPtr<CComApartment> GetCurrentApartmentNoFail();
ObjectLibrary::ReferencedPtr<StackTrace> g_coInitializeSecurityStackTrace;
ObjectLibrary::ReferencedPtr<WinRT::Metadata::Marshaling::TypeCache> spTypeCache;
ObjectLibrary::UnreferencedPtr<OXIDEntry> g_pMTAOXIDEntry;
ObjectSplayNode * gpObjectRoot;
PACKAGE_INFO * g_packageInfo;
PointOfRandomDelay g_pointOfRandomDelay;
PrivHiveHKEYCache g_PrivUserHiveCache;
ProcessIdentity g_processIdentity;
ProcessToken g_processToken;
ReportedExceptions * gReportedExceptions;
SAccessCache * gPermissionsCache;
SAccessCache * gRestrictionsCache;
SHashChain * ApartmentBuckets;
SHashChain * MIDBuckets;
SHashChain * OIDBuckets;
SHashChain * RIFBuckets;
SHashChain * SRFBuckets;
SHookList gHookList;
SPendingCall * GetPendingCallList();
ThreadTypeSpecificRoutines const & ThreadTypeSpecific();
UnmarshalersTable g_unmarshalersTable;
VtblSplayNode * gpVtblRoot;
WhichSCMServiceProcess WhichSCMServiceProcessIsThisProcess();
WinRT::Metadata::Marshaling::IReleaseMarshalBuffersVtbl const CStdProxyBuffer_ReleaseMarshalBuffersVtbl;
WinRT::Metadata::Marshaling::IReleaseMarshalBuffersVtbl const CStdStubBuffer_ReleaseMarshalBuffersVtbl;
WinRT::Metadata::Marshaling::IRpcProxyBufferVtbl const CStdProxyBuffer2VtblMbm;
WinRT::Metadata::Marshaling::IRpcStubBufferVtbl const CStdStubBuffer2VtblMbm;
WinrtAsyncChannelOperationMap g_winrtAsyncOperationMap;
WinrtAsyncChannelUnmarshaler g_winrtAsyncUnmarshaler;
WinrtAsyncProxyMethodInfoCache g_methodInfoCache;
_CERT_CONTEXT const * const gSchannelContext;
_CLIENT_CALL_RETURN Ndr64pDcomAsyncClientCall(_MIDL_STUBLESS_PROXY_INFO *,unsigned long,void *,unsigned char *);
_CLIENT_CALL_RETURN NdrpDcomAsyncClientCall(_MIDL_STUB_DESC const *,unsigned char const *,unsigned char *,unsigned char);
_EVENT_DESCRIPTOR const * (* CompleteAsynchronousOperationEventDescriptors)[3];
_EVENT_DESCRIPTOR const * (* CompleteSynchronousOperationWorkItemEventDescriptors)[3];
_EVENT_DESCRIPTOR const * (* CompleteSynchronousWorkItemEventDescriptors)[3];
_EVENT_DESCRIPTOR const * (* CreateAsynchronousOperationEventDescriptors)[3];
_EVENT_DESCRIPTOR const * (* RelateAsynchronousOperationEventDescriptors)[3];
_EVENT_DESCRIPTOR const * (* StartSynchronousOperationWorkItemEventDescriptors)[3];
_EVENT_DESCRIPTOR const * (* StartSynchronousWorkItemEventDescriptors)[3];
_GENERIC_MAPPING gMap;
_GUID * gaChannelHook;
_GUID const * GetPartitionIDForClassInfo(IComClassInfo *);
_GUID const * TLSGetLogicalThread();
_GUID const CLSID_VSA_IEC;
_GUID const CLSID_VSA_IEC_TREATAS;
_GUID const DEBUG_EXTENSION;
_GUID const GUID_CAUSALITY_WINDOWS_PLATFORM_ID;
_GUID g_AppId;
_RPC_SERVER_INTERFACE const gRemUnknownIf;
_RPC_SERVER_INTERFACE const gRemUnknownIf2;
_RPC_SERVER_INTERFACE const gServerIf;
_RTL_CRITICAL_SECTION g_OleMutexCreationSem;
_RTL_CRITICAL_SECTION g_ServerLock;
_RTL_CRITICAL_SECTION g_catLock;
_SCHANNEL_CRED gSchannelCred;
_SECURITY_DESCRIPTOR * gSecDesc;
_SECURITY_DESCRIPTOR * gSecDescRestrictions;
_TP_TIMER * g_AggressiveDllTimer;
_TP_WORK * gpWorkChannelProcessInitialize;
_ULARGE_INTEGER gNextContextId;
_UNICODE_STRING const uszDefaultDesktopName;
_UNINITMTAWORKERCONTEXT * g_pUninitMTAWorkerContext;
_USER_MARSHAL_ROUTINE_QUADRUPLE * UserMarshalRoutines;
__MIDL_ILocalObjectExporter_0002 * gClientSvcList;
__WIL_RTL_SRWLOCK g_wil_details_testFeatureStateLock;
__int64 GetWinRTActivationStoreSequence();
__int64 OleMainThreadWndProc(HWND__ *,unsigned int,unsigned __int64,__int64);
__int64 ThreadWndProc(HWND__ *,unsigned int,unsigned __int64,__int64);
__int64 const * const SIZING_HANDLE_COMMON_BUFFER;
__type_info_node __type_info_root_node;
_tRpcVerifierSettings * pRpcVerifierSettings;
bool ASTAInSendMessage();
bool ASTAThreadCanMakeOutRemReleaseCall();
bool CallSetErrorInfo();
bool ClassicSTAThreadCanMakeOutRemReleaseCall();
bool CorrelateTraceActivities(_GUID const &,_GUID const &);
bool CurlyStringToGUID(unsigned short const *,_GUID *);
bool DecrementProcessInitializeCount();
bool DisableThresholdAppLaunchPerfFeatureViaRegistry();
bool EnableExtendedApartmentLifetime();
bool FailureLikelyToIndicateBrokerAbnormalTermination(long);
bool FindMarshalingContextAttribute(unsigned __int64,MarshalingContextAttributeValue const *,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
bool GetCurrentTraceActivity(_GUID *);
bool GetCurrentTraceActivityForPropagation(_GUID *);
bool IsCallTracingEnabled();
bool IsCombaseCallAsOrCustomProxyFrame(void *);
bool IsCurrentThreadUserInitialized();
bool IsCurrentThreadUserInitializedWorker();
bool IsDesktopWinRTBrokerToSideLoadedAppBinding(unsigned short const *);
bool IsInParameterMitigationEnabledAlways();
bool IsInprocDirectMarshalingMitigationEnabled();
bool IsInprocOutParameterMitigationEnabled();
bool IsInputNonInterferenceForASTAEnabled();
bool IsMarshalingStreamForComCall(IStream *);
bool IsNdrFrame(void *);
bool IsPackagedProcess();
bool IsProcessLocalStdId(IUnknown *);
bool IsRetryResult(long,bool *);
bool IsThresholdAppLaunchPerfFeatureEnabled();
bool IsTokenILMediumOrGreater(void *);
bool IsValidActivatableClassForExtensionRegistration(HSTRING__ *,Windows::Foundation::RegistrationScope,Microsoft::WRL::ComPtr<Windows::Foundation::IActivatableClassRegistration> const &);
bool IsValidMultiSz(tagBLOB const &);
bool LooksLikeDllhost(unsigned short const *);
bool LooksLikeSvchost(unsigned short const *);
bool MTAThreadCanMakeOutRemReleaseCall();
bool MarshalingCanTreatObjectAsAgile(IUnknown *);
bool MoreRecentlyInstalled(PackageIdAndInstallOrder const &,PackageIdAndInstallOrder const &);
bool PackageNamesMatch(unsigned short const *,unsigned short const *);
bool ReplaceCachedRuntimeBroker(bool,IRuntimeBroker *,IRuntimeBroker *);
bool ReportError();
bool SetCachedRuntimeBroker(bool,IRuntimeBroker *);
bool SetCurrentTraceActivity(_GUID const &);
bool StringHasEmbeddedNull(HSTRING__ *);
bool StringToGUID(unsigned short const *,_GUID *);
bool UninitializedThreadCanMakeOutRemReleaseCall();
bool UseNewCatalogCacheBehavior();
bool _TlgGuidIsZero(_GUID const &);
bool g_detectedWindowExtensionApisetHostIsLoaded;
bool g_testSuppressExceptionReporting;
bool gfEnableAgileOopProxies;
bool gfEnableExtendedApartmentLifetime;
bool volatile languageExceptionAlreadyIncluded;
int AllowServerORPCDebugging(CMessageCall *);
int ApartmentUninitialize(int);
int CRetailMalloc_DidAlloc(IMalloc *,void *);
int CSpyMalloc_DidAlloc(IMalloc *,void *);
int CallAccessCheck(void *,_SECURITY_DESCRIPTOR *,unsigned long,int *);
int CatalogDllMain(HINSTANCE__ *,unsigned long,void *);
int CheckContextAfterCall(COleTls &,CObjectContext *);
int ChkIfLocalOID(tagOBJREF &,CStdIdentity * *,int);
int CoVrfBreakOnCallBackException(_EXCEPTION_POINTERS *,void *);
int CoVrfBreakOnException(_EXCEPTION_POINTERS *,void *,_GUID const *,unsigned long);
int CoVrfBreakOnExceptionWithMethodAddress(_EXCEPTION_POINTERS *,void *,_GUID const *,unsigned long,char const *);
int CoVrfInDllMain();
int CrossAptRefToNA(tagOBJREF &);
int DeleteACEFromStreamACL(_TRUSTEE_W *,unsigned long,tagACL_DESCRIPTOR *,tagPCB *);
int DoCheckForPerAppHiveFeature(_RTL_RUN_ONCE *,void *,void * *);
int DoPackagedProcessCheck(_RTL_RUN_ONCE *,void *,void * *);
int DoPerAppBrokerInstancingDefaultForActivationConfigurationCheck(_RTL_RUN_ONCE *,void *,void * *);
int DsaValid(tagDUALSTRINGARRAY const *);
int EnsureLegacySupport(IUnknown *,unsigned long &,void * &);
int GetEnvBlock(_PRIV_SCM_INFO *);
int GetMessageParameters(long,unsigned int,unsigned short const *,unsigned int,unsigned short *,unsigned __int64 &,unsigned short const * *);
int GetTextualSid(void *,unsigned short *,unsigned long *);
int GipBypassEnabled();
int InlineIsEqualGUID(_GUID const &,_GUID const &);
int InterlockedDecRefCnt(unsigned long *,unsigned long *);
int InterlockedRestoreRefCnt(unsigned long *,unsigned long *);
int IsAllowableProtseq(unsigned short,unsigned short,unsigned short * const);
int IsAllowedDCOMProtocol(void *);
int IsApartmentInitialized();
int IsBrokenRefCount(_GUID *);
int IsComsvcsCLSID(_GUID const &);
int IsCurrentBinaryEnabledForTracing();
int IsEqualGUID(_GUID const &,_GUID const &);
int IsInternalCLSID(_GUID const &,bool,long (**)(_GUID const &,_GUID const &,void * *),_GUID *);
int IsOKToDeleteClientObject(CStdIdentity *,unsigned long *);
int IsPathSeparator(unsigned short);
int IsProcessILGreaterThanOrEqual(unsigned long);
int IsRunningInDCOMLAUNCH();
int IsRunningInRPCSS();
int IsTableStrongObjRef(tagSTDOBJREF *);
int IsThreadInNTA();
int IsValidCOMSecurityDescriptor(_SECURITY_DESCRIPTOR_RELATIVE const *,int *);
int IsValidPtrOut(void *,unsigned __int64);
int LogEventIsActive();
int MarshaledByThisProcess(tagCONTEXTHEADER const &);
int NotifyActivation(int,IUnknown *);
int OnMainThread();
int RemoveOID(SHashChain *,void *);
int RemovePID(SHashChain *,void *);
int RoTransformErrorImpl(long,long,unsigned int,unsigned short const *);
int SendReport(long,unsigned int,unsigned short const *,unsigned short,void *,IUnknown *);
int SnapshotMiniDumpCallback(void *,_MINIDUMP_CALLBACK_INPUT * const,_MINIDUMP_CALLBACK_OUTPUT *);
int TLSAddToMap(tagSOleTlsData *,unsigned long);
int TLSGrowMap();
int UDTAlignmentPolicy;
int UDTAlignmentRegistry;
int bAllocateIfNeccessary;
int fLrpcSDInitialized;
int gAccessRestrictionsViaPolicy;
int gAnonymousAccessAllowed;
int gAuthnLevelFromRegistry;
int gAutoInputSync;
int gDefaultService;
int gDisableDCOM;
int gEnableAgileProxies;
int gEnableOldModalLoop;
int gGotSecurityData;
int gImplicitClientSecurityBlanket;
int g_bInitialized;
int g_bServerLockInitialized;
int g_fDisableConditionVariableTimeouts;
int g_fInitCrit;
int g_fRevokePending;
int g_wil_details_preventOnDemandStagingConfigReads;
int gfAccessDeniedFromImpersonateAnonymousTokenExpected;
int gfBreakOnSilencedExceptions;
int gfChannelProcessInitialized;
int gfDestroyingMainWindow;
int gfEnableTracing;
int gfIsProcessExeSubSytemWin8OrAbove;
int gfListening;
int gfLogCallFailure;
int gfLogInvalidSecurityDescriptor;
int gfLrpc;
int gfOleMutexCreationSemOkay;
int gfRPCUsesDefaultThreadPool;
int gfRPCVerifierEnabled;
int gfRaiseAuthnLevel;
int wCoIsOle1Class(_GUID const &);
int wCompareDllName(unsigned short const *,unsigned short const *,unsigned long);
int wGUIDFromString(unsigned short const *,_GUID *);
int wStringFromGUID2(_GUID const &,unsigned short *,int);
int wUUIDFromString(unsigned short const *,_GUID *);
int wil_HasFeatureTestState(unsigned int,wil_FeatureEnabledState *);
int wil_QueryFeatureState(wil_FeatureState *,unsigned int,int,wil_FeatureStore,int *);
int wil_details_FeaturePropertyCache_ReportUsageToServiceDirect(wil_details_FeaturePropertyCache *,unsigned int,wil_details_ServiceReportingKind,unsigned int,unsigned __int64);
int wil_details_HasTestState(unsigned int,wil_details_FeatureTestStateKind,wil_details_FeatureTestState *);
int wil_details_ModifyFeatureData(wil_details_FeaturePropertyCache *,int (*)(wil_details_FeaturePropertyCache *,void *),void *);
int wil_details_SetEnabledAndHasNotificationStateCallback(wil_details_FeaturePropertyCache *,void *);
int wil_details_SetHasNotificationStateCallback(wil_details_FeaturePropertyCache *,void *);
int wil_details_SetPropertyCacheOpportunityCallback(wil_details_FeaturePropertyCache *,void *);
int wil_details_SetPropertyCacheUsageCallback(wil_details_FeaturePropertyCache *,void *);
int wil_details_SetPropertyFlagCallback(wil_details_FeaturePropertyCache *,void *);
int wil_details_StagingConfigFeature_HasUniqueState(wil_details_StagingConfigFeature const *);
int wil_details_StagingConfig_AreAnyFeaturesConfigured(wil_details_StagingConfig *);
int wil_details_StagingConfig_QueryFeatureState(wil_details_StagingConfig *,wil_FeatureState *,unsigned int,int);
long (* g_wil_details_pfnNtQueryWnfStateData)(__WIL__WNF_STATE_NAME const *,__WIL__WNF_TYPE_ID const *,void const *,unsigned long *,void *,unsigned long *);
long (* g_wil_details_pfnNtUpdateWnfStateData)(__WIL__WNF_STATE_NAME const *,void const *,unsigned long,__WIL__WNF_TYPE_ID const *,void const *,unsigned long,unsigned long);
long (* g_wil_details_pfnRtlSubscribeWnfStateChangeNotification)(__WIL__WNF_USER_SUBSCRIPTION * *,__WIL__WNF_STATE_NAME,unsigned long,long (*)(__WIL__WNF_STATE_NAME,unsigned long,__WIL__WNF_TYPE_ID *,void *,void const *,unsigned long),void *,__WIL__WNF_TYPE_ID *,unsigned long,unsigned long);
long (* g_wil_details_pfnRtlUnsubscribeWnfNotificationWaitForCompletion)(__WIL__WNF_USER_SUBSCRIPTION *);
long (* pfnCLSIDFromOle1Class)(unsigned short const *,_GUID *,int);
long (* pfnCoGetMarshalSizeMax)(unsigned long *,_GUID const &,IUnknown *,unsigned long,void *,unsigned long);
long (* pfnCoMarshalInterface)(IStream *,_GUID const &,IUnknown *,unsigned long,void *,unsigned long);
long (* pfnCoReleaseMarshalData)(IStream *);
long (* pfnCoUnmarshalInterface)(IStream *,_GUID const &,void * *);
long (* pfnEnableHookObject)(int,int *);
long (* pfnGetHookInterface)(IHookOleObject * *);
long (* pfnHkOleRegisterObject)(_GUID const &,_GUID const &,void *,int);
long (* pfnInitHookOle)();
long (* pfnUninitHookOle)();
long ASTAInvokeInApartment(tagRPCOLEMESSAGE *,unsigned long,bool,IRpcStubBuffer *,CServerChannel *,tagIPIDEntry *,unsigned long *);
long ASTAThreadCanMakeOutCall(unsigned long,_GUID const &,tagRPCOLEMESSAGE *);
long ASTAThreadCheckAndAdjustRpcFlagsInClientGetBuffer(tagRPCOLEMESSAGE *,_GUID const &,bool);
long ASTAThreadDispatchCrossApartmentCall(tagRPCOLEMESSAGE *,OXIDEntry *,CSyncClientCall *);
long ASTAThreadSendMessageToClassicSTA(unsigned long,SendMessageToClassicSTAReason,HWND__ *,unsigned int,unsigned __int64,__int64);
long ASTAThreadSendReceive(CSyncClientCall *,tagRPCOLEMESSAGE *,unsigned long *);
long ASTAThreadWaitForCall(CSyncClientCall *,WaitForCallReason,unsigned long);
long ASTAThreadWaitForHandles(unsigned long,unsigned long,unsigned long,void * *,unsigned long *);
long ATHostActivatorGetClassObject(_GUID const &,_GUID const &,void * *);
long ActivateWinRTDesktopBroker(IWinRTDesktopBroker * *);
long AddAceToSecurityDescriptor(void *,_ACE_HEADER *,void * *);
long AddAceToSecurityDescriptorViaStringManipulation(_SECURITY_DESCRIPTOR *,unsigned short const *,_SECURITY_DESCRIPTOR * *);
long AddAceToSelfRelativeSecurityDescriptor(_SECURITY_DESCRIPTOR_RELATIVE *,unsigned long,_ACE_HEADER *,_SECURITY_DESCRIPTOR_RELATIVE * *,unsigned long *);
long AddAcesToSecurityDescriptorViaApi(void *,_ACE_HEADER * *,unsigned __int64,void * *);
long AppInvoke(ServerCall *,CServerChannel *,IRpcStubBuffer *,void *,void *,tagIPIDEntry *,WireLocalThis *);
long AppInvokeExceptionFilterWithMethodAddress(_EXCEPTION_POINTERS *,void *,_GUID const &,unsigned long,void *,char const *);
long AppModelPolicy_GetPolicy_Internal(void *,AppModelPolicy_Type,AppModelPolicy_PolicyValue *,_PS_PKG_CLAIM *,unsigned __int64 *);
long AsyncChannelWrapper_FreeBuffer(IAsyncRpcChannelBuffer *,tagRPCOLEMESSAGE *);
long AsyncChannelWrapper_GetBuffer(IAsyncRpcChannelBuffer *,tagRPCOLEMESSAGE *,_GUID const &);
long AsyncChannelWrapper_GetDestCtx(IAsyncRpcChannelBuffer *,unsigned long *,void * *);
long AsyncChannelWrapper_GetDestCtxEx(IAsyncRpcChannelBuffer *,tagRPCOLEMESSAGE *,unsigned long *,void * *);
long AsyncChannelWrapper_GetProtocolVersion(IAsyncRpcChannelBuffer *,unsigned long *);
long AsyncChannelWrapper_IsConnected(IAsyncRpcChannelBuffer *);
long AsyncChannelWrapper_QueryInterface(IAsyncRpcChannelBuffer *,_GUID const &,void * *);
long AsyncChannelWrapper_Receive(IAsyncRpcChannelBuffer *,tagRPCOLEMESSAGE *,unsigned long *);
long AsyncChannelWrapper_Send(IAsyncRpcChannelBuffer *,tagRPCOLEMESSAGE *,ISynchronize *,unsigned long *);
long AsyncChannelWrapper_SendReceive(IAsyncRpcChannelBuffer *,tagRPCOLEMESSAGE *,unsigned long *);
long BlockAstaToAstaCallChain(_GUID const &,unsigned long,unsigned long,unsigned long);
long BrokeredActivateInstance(HSTRING__ *,unsigned __int64,bool,IInspectable * *);
long BrokeredGetActivationFactory(HSTRING__ *,unsigned __int64,_GUID const &,bool,void * *);
long CAccessControlCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CActivationPropertiesInCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CActivationPropertiesOutCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CActivationStoreCF_CreateInstance(CActivationStore * *);
long CAddrControlCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CCFreeUnused(unsigned long,bool);
long CCGetClassObject(ACTIVATION_PROPERTIES const &);
long CCGetOrLoadClass(ACTIVATION_PROPERTIES const &);
long CCGetTreatAs(_GUID const &,_GUID &);
long CCGetWinRTRegisteredActivationFactory(_GUID const &,HSTRING__ *,IActivationFactory * *);
long CCLockServerForActivation();
long CCRegisterServer(_GUID const &,IUnknown *,unsigned long,unsigned long,unsigned long *);
long CCRegisterWinRTLocalServers(IWinRTRuntimeClassInfo * *,long (**)(HSTRING__ *,IActivationFactory * *),unsigned int,<unnamed-type-RO_REGISTRATION_COOKIE> * *);
long CCSearchForLoadedDllClass(ACTIVATION_PROPERTIES const &,<unnamed-type-DLL_CLASS_HANDLE> * *);
long CComActivatorCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CComCatalogCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CContextSwitcherCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CErrorObjectCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CFreeThreadedMarshalerCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CGIPTableCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CGlobalOptionsCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CInprocActpropsUnmarshallerCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CLSIDFromStringA(char *,_GUID *);
long CLocalMachineNamesCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CMalloc_QueryInterface(IMalloc *,_GUID const &,void * *);
long CManualResetEventCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CMetadataProxyStubFactory_GetClassObject(_GUID const &,void * *);
long COLEDragDropHelperCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CObjectContextCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CRestrictedErrorObjectCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CRpcHelperCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CStdEventCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CStdPSFactoryBuffer_CreatePerInterfacePSFactory(ICreatePerInterfacePSFactory *,_GUID const &,IPerInterfacePSFactory * *);
long CStdPSFactoryBuffer_CreateProxy(ICreatePerInterfacePSFactory *,IUnknown *,_GUID const &,IRpcProxyBuffer * *,void * *);
long CStdPSFactoryBuffer_CreateStub(ICreatePerInterfacePSFactory *,_GUID const &,IUnknown *,IRpcStubBuffer * *);
long CStdPSFactoryBuffer_QueryInterface(ICreatePerInterfacePSFactory *,_GUID const &,void * *);
long CSuspendMonitorCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CSynchronizeContainerCF_CreateInstance(IUnknown *,_GUID const &,void * *);
long CacheCreateThread(unsigned long (*)(void *),void *,unsigned long *);
long CacheLookup(_GUID const &,TypeInfoVtbl * *);
long CacheRegister(_GUID const &,TypeInfoVtbl * *);
long CalcSASize(unsigned long,unsigned long *);
long CalculateSizeNeededForLocalThis(unsigned long,unsigned long *);
long CallBackExceptionFilter(_EXCEPTION_POINTERS *,void *);
long CallErrorForwarder(void *,int,IRestrictedErrorInfo *);
long CallerIsAppContainer(int *);
long CarefullyQueryNewInterface(IUnknown *,_GUID const &,void * *);
long ChannelWrapper_Cancel(IRpcChannelBuffer3 *,tagRPCOLEMESSAGE *);
long ChannelWrapper_FreeBuffer(IRpcChannelBuffer3 *,tagRPCOLEMESSAGE *);
long ChannelWrapper_GetBuffer(IRpcChannelBuffer3 *,tagRPCOLEMESSAGE *,_GUID const &);
long ChannelWrapper_GetCallContext(IRpcChannelBuffer3 *,tagRPCOLEMESSAGE *,_GUID const &,void * *);
long ChannelWrapper_GetDestCtx(IRpcChannelBuffer3 *,unsigned long *,void * *);
long ChannelWrapper_GetDestCtxEx(IRpcChannelBuffer3 *,tagRPCOLEMESSAGE *,unsigned long *,void * *);
long ChannelWrapper_GetProtocolVersion(IRpcChannelBuffer3 *,unsigned long *);
long ChannelWrapper_GetState(IRpcChannelBuffer3 *,tagRPCOLEMESSAGE *,unsigned long *);
long ChannelWrapper_IsConnected(IRpcChannelBuffer3 *);
long ChannelWrapper_QueryInterface(IRpcChannelBuffer3 *,_GUID const &,void * *);
long ChannelWrapper_Receive(IRpcChannelBuffer3 *,tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
long ChannelWrapper_RegisterAsync(IRpcChannelBuffer3 *,tagRPCOLEMESSAGE *,IAsyncManager *);
long ChannelWrapper_Send(IRpcChannelBuffer3 *,tagRPCOLEMESSAGE *,unsigned long *);
long ChannelWrapper_SendReceive(IRpcChannelBuffer3 *,tagRPCOLEMESSAGE *,unsigned long *);
long CheckAccess(void *,unsigned long,int,int,void *);
long CheckAccessControl();
long CheckCATID_MARSHALERKey(_GUID const &,bool *);
long CheckChannelProcessInitForAgileReference(unsigned long,IAgileReference *);
long CheckForClsid(IUserToken *,_GUID const *,int *);
long CheckForProgID(IUserToken *,unsigned short const *,int *);
long CheckInprocServer32(HKEY__ *,char const *);
long CheckLrpc();
long CheckMemoryGate(IUnknown *,tagResourceGateId);
long CheckProxyStubClsid32(HKEY__ *,char const *);
long CheckRefresh(IUserToken *,int,KeyRefreshInfo const &,int *);
long CheckSystemTrustedUnmarshalerKey(_GUID const &,bool *);
long CheckTypeInfo(ITypeInfo *,ITypeInfo * *,unsigned short *,int *);
long ClassicSTAThreadCanMakeOutCall(unsigned long,_GUID const &,tagRPCOLEMESSAGE *);
long ClassicSTAThreadCheckAndAdjustRpcFlagsInClientGetBuffer(tagRPCOLEMESSAGE *,_GUID const &,bool);
long ClassicSTAThreadDispatchCrossApartmentCall(tagRPCOLEMESSAGE *,OXIDEntry *,CSyncClientCall *);
long ClassicSTAThreadReceive(ClientCall *,tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
long ClassicSTAThreadSend(ClientCall *,tagRPCOLEMESSAGE *,unsigned long *);
long ClassicSTAThreadSendReceive(CSyncClientCall *,tagRPCOLEMESSAGE *,unsigned long *);
long ClassicSTAThreadWaitForCall(CSyncClientCall *,WaitForCallReason,unsigned long);
long ClassicSTAThreadWaitForHandles(unsigned long,unsigned long,unsigned long,void * *,unsigned long *);
long CleanupLeakedDomainStack(COleTls &,CObjectContext *);
long ClearDefaultBrowser();
long ClientNotify<0>(WireThat *,unsigned long,unsigned long *,unsigned long,long,CMessageCall *,_GUID const *);
long ClientNotify<1>(WireThat const *,unsigned long,unsigned long *,unsigned long,long,CMessageCall *,_GUID const *);
long CoGetSystemSecurityPermissionsTestHook(unsigned long * const,unsigned long *,unsigned char * *);
long CoRegisterDisconnectCallback(IUnknown *,unsigned long,IDisconnectSink *,void *,void * *);
long CoVrfFreeMemoryChecks(void *,unsigned __int64,void *);
long ComInvoke(ServerCall *,bool *);
long ComInvokeWithLockAndIPID(ServerCall *,tagIPIDEntry *,bool *);
long CompleteObjRef(tagOBJREF &,tagOXID_INFO const &,_GUID const &,int *);
long ComputeEffectiveAccess(tagACL_DESCRIPTOR *,tagSTREAM_ACL *,void *,unsigned long *);
long CopyDualStringArray(tagDUALSTRINGARRAY *,tagDUALSTRINGARRAY * *);
long CopyMsgForRetry(tagRPCOLEMESSAGE *,IInternalChannelBuffer *,long);
long CopySecDesc(_SECURITY_DESCRIPTOR *,_SECURITY_DESCRIPTOR * *);
long CopySelfRelativeSd(_SECURITY_DESCRIPTOR_RELATIVE *,unsigned long,_SECURITY_DESCRIPTOR_RELATIVE * *);
long CopyStringArray(tagDUALSTRINGARRAY *,tagDUALSTRINGARRAY *,tagDUALSTRINGARRAY * *);
long CorSigUncompressData(unsigned char const *,unsigned long,unsigned long *,unsigned long *);
long CreateApartmentAndEmptyContext(APTKIND,CComApartment * *,CObjectContext * *);
long CreateAsyncChannelWrapper(_GUID const *,IRpcChannelBuffer *,IRpcChannelBuffer * *);
long CreateClientHandler(_GUID const &,EffectiveUnmarshalingPolicy,_GUID const &,unsigned long,unsigned long,CStdIdentity * *);
long CreateForwardProcBuffer(unsigned long,void * * *);
long CreateHandler(_GUID const &,EffectiveUnmarshalingPolicy,IUnknown *,IUnknown * *);
long CreateOutParameterMarshalingSet(void *,unsigned __int64 *,PreventRundownBiasContainer * *);
long CreateSecurityIdentifierAccessAllowedAce(_SID_IDENTIFIER_AUTHORITY *,unsigned char,unsigned long *,unsigned long,_ACCESS_ALLOWED_ACE * *);
long CreateStublessProcBuffer(unsigned long,void * * *);
long CreateVtblFromTypeInfo(_GUID const &,int,unsigned short,tagMethodInfo *,TypeInfoVtbl * *);
long CreateWellKnownAccessAllowedAce(WELL_KNOWN_SID_TYPE,unsigned long,_ACCESS_ALLOWED_ACE * *);
long CreateWrapper(void *);
long CrossAptAddRefFn(void *);
long CrossAptQIFn(void *);
long CrossAptReleaseFn(void *);
long CrossCtxDisconnectFn(void *);
long CrossCtxMarshalFn(void *);
long CrossCtxQIFn(void *);
long CustomReleaseMarshalData(_GUID const &,IStream *);
long CustomUnmarshalEnvoy(_GUID const &,IStream *,_GUID const &,void * *);
long DDEInvokeInApartment(tagRPCOLEMESSAGE *,unsigned long,IRpcStubBuffer *,IInternalChannelBuffer *,unsigned long *);
long DDEStubInvoke(tagRPCOLEMESSAGE *,IRpcChannelBuffer *,IRpcStubBuffer *,unsigned long *);
long DecrementMTAUsageHelper(_MTA_USAGE_INCREMENTOR *,bool);
long DefaultAuthnServices();
long DefaultBlanket(unsigned long,OXIDEntry *,SBlanket *);
long DefaultReceive(ClientCall *,tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
long DefaultSend(ClientCall *,tagRPCOLEMESSAGE *,unsigned long *);
long DefaultSendMessageToClassicSTA(unsigned long,SendMessageToClassicSTAReason,HWND__ *,unsigned int,unsigned __int64,__int64);
long DefaultSendReceive(CSyncClientCall *,tagRPCOLEMESSAGE *,unsigned long *);
long DefaultStringBindings();
long DefaultStringBindingsInternal(_UNICODE_STRING *);
long DefaultStubInvoke(bool,IServerCall *,IRpcChannelBuffer *,IRpcStubBuffer *,unsigned long *);
long DefaultWaitForHandles(unsigned long,unsigned long,unsigned long,void * *,unsigned long *);
long DesktopBrokeredActivateInstance(HSTRING__ *,HSTRING__ *,IInspectable * *);
long DesktopBrokeredGetActivationFactory(HSTRING__ *,HSTRING__ *,_GUID const &,void * *);
long DetermineApplicabilityOfStubRundownMitigations(IStream *,unsigned long,unsigned long,PreventRundownBiasContainer * *,bool *);
long DetermineEffectiveUnmarshalingPolicyForStream(IStream *,EffectiveUnmarshalingPolicy *);
long DeterminePolicySet(CObjectContext *,CObjectContext *,unsigned long,CPolicySet * *);
long DisconnectSwitch(void *);
long DllHostProcessInitialize();
long DoNormalListen(unsigned short);
long DoSTClassCreate(CClassCache::CDllPathEntry *,_GUID const &,_GUID const &,IUnknown * *);
long DoSTMTClassCreate(CClassCache::CDllPathEntry *,_GUID const &,_GUID const &,IUnknown * *);
long DoServerContextCCI(void *);
long DoServerContextGCO(void *);
long DoesTokenHaveApplicationIdAttribute(void *,bool *);
long DownloadClass(_GUID,unsigned long);
long DownloadClass(unsigned short *,unsigned long);
long DuplicatePWSTR(unsigned short const *,unsigned short * &);
long DuplicateQuotedPWSTR(unsigned short const *,unsigned short * &);
long DuplicateSystemHandleCommon(void *,unsigned char,unsigned long,bool,void * *);
long EnlargeStreamACL(tagPCB *,unsigned long);
long EnsureObjServerCreated();
long EnsureRestrictedCodePresent(_SECURITY_DESCRIPTOR *,_SECURITY_DESCRIPTOR * *);
long EnterAfterCallback(tagRPCOLEMESSAGE *,CPolicySet *,long *,long,CRpcCall &,CObjectContext *,CObjectContext *,CCtxCall *,int,int);
long EnterForCallback(tagRPCOLEMESSAGE *,CPolicySet *,long (*)(void *),void *,_GUID const &,unsigned long,IUnknown *,long *,CObjectContext * *);
long ExpandPWSTR(unsigned short const *,unsigned short * &);
long FillLocalOXIDInfo(tagOBJREF const &,tagOXID_INFO &);
long FilterActivation(_GUID const &,_GUID *);
long FindAggStdMarshal(IStream *,IMarshal * *);
long FindLocalThisInMachineLocalRequestHeader(unsigned long,WireThis const *,WireLocalThis const * *);
long FindOrCreateApartment(_GUID const &,unsigned long,DLL_INSTANTIATION_PROPERTIES *,unsigned long *);
long FindOrCreateMethodInfo(ICallChannel *,tagRPCOLEMESSAGE const *,bool *,WinrtAsyncProxyMethodInfo * *);
long FindOrCreateWrapper(IUnknown *,CObjectContext *,int,unsigned long,CStdWrapper * *);
long FindStdMarshal(tagOBJREF &,EffectiveUnmarshalingPolicy,int,CStdMarshal * *,int);
long FixupAccessControl(_SECURITY_DESCRIPTOR * *,unsigned long);
long FixupSecurityDescriptor(_SECURITY_DESCRIPTOR_RELATIVE *,unsigned long);
long ForceImmediateBulkUpdateWithPingServerForAdds();
long FormatStringResourceWorker(unsigned short,unsigned short const *,unsigned long,char * *,unsigned short * *);
long FreePreRegMOID(_GUID const &);
long GenerateDefaultAccessPermissionsSecurityDescriptor(_SECURITY_DESCRIPTOR_RELATIVE *,unsigned long,_SECURITY_DESCRIPTOR_RELATIVE * *);
long GetActivateInstanceHelperMulti(IActivationFactory *,unsigned long,_GUID,HSTRING__ *,_GUID *,tagMInterfacePointer * *,long *,IUnknown * *,CDestObject *);
long GetApartmentByID(unsigned long,CComApartment * *);
long GetAppContainerServerSecurityDescriptor(unsigned short const *,unsigned short const *,void * *);
long GetAsyncCallObject(IUnknown *,IUnknown *,_GUID const &,_GUID const &,IUnknown * *,void * *);
long GetAsyncIIDFromSyncIID(_GUID const &,_GUID *);
long GetClassInfoFromClsid(_GUID const &,IComClassInfo * *,unsigned long);
long GetClassInfoWithInprocOrLocalServer(_GUID const &,IComCatalogSCM *,_GUID const &,void * *);
long GetCurrentComApartment(CComApartment * *);
long GetCurrentToken(void * *);
long GetDesktopApplicationPathIfPresentInClassRegistration(HSTRING__ *,HSTRING__ * *);
long GetExtensionRegistration(IExtensionCatalogContext *,Microsoft::WRL::ComPtr<CActivationStore> const &,OpaqueString const &,OpaqueString const &,OpaqueString const &,OpaqueString const &,Windows::Foundation::IExtensionRegistration * *);
long GetExtensionRegistrationByIndex(IExtensionCatalogContext *,Microsoft::WRL::ComPtr<CActivationStore> const &,OpaqueString const &,OpaqueString const &,OpaqueString const &,RegistrationStoreContext::PackageForContractHandleDetail *,unsigned int,Windows::Foundation::IExtensionRegistration * *);
long GetGEHFile(unsigned short *,unsigned short *,int);
long GetIFDFromInterface(IUnknown *,_GUID const &,unsigned long,unsigned long,tagMInterfacePointer * *);
long GetIIDFromObjRef(tagOBJREF &,_GUID * *);
long GetInstalledPackageFullNameFromMainPackageFamilyName(IUserTokenInternal *,unsigned short const *,HSTRING__ * *,PackageFamilyErrorDetails *);
long GetInstalledPackageFullNameFromPackageFamilyName(IUserTokenInternal *,unsigned short const *,unsigned int,HSTRING__ * *,PackageFamilyErrorDetails *);
long GetInstanceHelper(_COSERVERINFO *,_GUID *,IUnknown *,unsigned long,unsigned long,unsigned short *,IStorage *,unsigned long,tagMULTI_QI *,ActivationPropertiesIn *);
long GetInstanceHelperMulti(IClassFactory *,unsigned long,_GUID *,tagMInterfacePointer * *,long *,IUnknown * *,CDestObject *);
long GetInternalSourceMarshalingContextAttribute(CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
long GetKeyRefreshInfo(HKEY__ *,KeyRefreshInfo *);
long GetLegacyBlanket(_GUID *,_SECURITY_DESCRIPTOR_RELATIVE * *,unsigned long *,unsigned long *);
long GetLifecycleManagerInfo(void *,int *,int *);
long GetLocalOXIDEntry(OXIDEntry * *);
long GetMessageForHr(long,unsigned short *,unsigned long);
long GetNameFromSID(unsigned short * *,void *,_TRUSTEE_TYPE *);
long GetObjectHelperMulti(IClassFactory *,unsigned long,IUnknown *,unsigned short *,IStorage *,unsigned long,_GUID *,tagMInterfacePointer * *,long *,tagMULTI_QI *,CDestObject *);
long GetOptionalPackagesForMainPackage(IUserTokenInternal *,unsigned short const *,unsigned __int64 *,PACKAGE_INFO * *);
long GetOptionalPackagesFromPackageInfo(_PACKAGE_INFO_REFERENCE *,unsigned __int64 *,PACKAGE_INFO * *);
long GetPSFactoryInternal(unsigned long,_GUID const &,IPSFactoryBuffer * *);
long GetPackageNameFromToken(void *,unsigned short * *);
long GetPackageSidFromToken(void *,void * *);
long GetPackageVersion(PACKAGE_VERSION *);
long GetPackagedComCatalogObject(bool,_GUID const &,void * *);
long GetPreRegMOID(_GUID *);
long GetPrimaryInterface(ITypeInfo *,ITypeInfo * *);
long GetPrivateHiveCatalogObject(_GUID const &,void * *);
long GetRegCatalogObject(_GUID const &,void * *,unsigned long,unsigned short);
long GetRegistrySecDesc(HKEY__ *,unsigned short *,_SECURITY_DESCRIPTOR_RELATIVE * *,unsigned long *,unsigned long *,int *);
long GetRegistrySecurityDescriptor(HKEY__ *,unsigned short const *,_SECURITY_DESCRIPTOR * *,unsigned long *);
long GetRegistryStringValue(HKEY__ *,unsigned short const *,unsigned short const *,unsigned long,unsigned short * *);
long GetSIDFromName(void * *,unsigned short *,_TRUSTEE_TYPE *);
long GetSpecialUnmarshaler(_GUID const &,IStream *,IMarshal * *);
long GetStaticContextUnmarshal(IMarshal * *);
long GetStaticUnMarshaler(IMarshal * *);
long GetStaticWrapper(IMarshal * *);
long GetStdId(IUnknown *,IUnknown * *);
long GetSxSCatalogObject(_GUID const &,void * *);
long GetSyncIIDFromAsyncIID(_GUID const &,_GUID *);
long GetTokenSecurityAttributeValue<unsigned __int64>(void *,unsigned short const *,unsigned __int64 *);
long GetUnquotedPath(IClassClassicInfo *,tagCLSCTX,unsigned short * *,unsigned short *,unsigned __int64);
long GetVtbl(ITypeInfo *,_GUID const &,TypeInfoVtbl * *);
long GetWinRTActivationPropertiesIn(ActivationPropertiesIn *,Windows::Foundation::IExtensionRegistration *,unsigned long,_GUID const *,unsigned long,Windows::Foundation::IActivationContext *,IWinRTRuntimeClassInfo *);
long GetWinRTActivationStoreCatalogObject(Windows::Foundation::RegistrationScope,_GUID const &,void * *);
long GitRegisterHlp(_GUID const &,Microsoft::WRL::ComPtr<IUnknown>,unsigned long,int,unsigned long *,tagOBJREF * *,tagInterfaceData * *);
long GrowCacheIfNecessary();
long HandleAutoRetryResponse(CMessageCall *);
long HandleIncomingCall(_GUID const &,unsigned short,unsigned long,void *);
long HandleInternalCallResult(long,CMessageCall *);
long HandlePostReleaseRifRef(IMessageParam *);
long HelperGetImplementedClsid(IComClassInfo *,_GUID *,_GUID *);
long HstringToMnkEqBuf(HSTRING__ *,CTmpMkEqBuf &);
long ICoCreateInstanceEx(_GUID const &,IUnknown *,unsigned long,_COSERVERINFO *,unsigned long,unsigned long,tagMULTI_QI *,ActivationPropertiesIn *);
long ICoGetClassObject(_GUID const &,unsigned long,_COSERVERINFO *,_GUID const &,unsigned long,void * *,ActivationPropertiesIn *);
long IUpdateResolverBindings(unsigned __int64,tagDUALSTRINGARRAY *,tagDUALSTRINGARRAY * *,tagDUALSTRINGARRAY * *);
long IncrementMTAUsageHelper(bool,_MTA_USAGE_INCREMENTOR * *);
long IncrementProcessInitializeCount();
long InitChannelIfNecessary();
long InitGlobals();
long InitMainThreadWnd();
long InitSecDescInACLDesc(tagACL_DESCRIPTOR *);
long InitializeCausalityTracing();
long InitializeSecurity();
long InquireStringBindings(unsigned short,int *);
long InternalDisconnectContext(unsigned long,CObjectContext *);
long InvokeCallFrameWithExceptionPolicyAndTracing(ICallFrame *,void *,long *,IServerCall *,ServerCallTracingInfo const *,ObjectMethodExceptionHandlingInfo *,ExceptionHandlingResult *);
long InvokeStubWithExceptionPolicyAndTracing(IRpcStubBuffer *,tagRPCOLEMESSAGE *,IRpcChannelBuffer *,bool,IServerCall *,ServerCallTracingInfo const *,ObjectMethodExceptionHandlingInfo *,ExceptionHandlingResult *);
long IsAllowListedCLSID(_GUID const &,bool *);
long IsClaimOrAttributePresentInToken(void *,unsigned short const *,bool *);
long IsCrossProcessTargetActive(IUnknown *,int *);
long IsCurrentProcessFullTrust(bool *);
long IsDesignModePropertyPresentInExtensionRegistration(Windows::Foundation::IExtensionRegistration *,HSTRING__ *,bool &);
long IsDynamicCodeProhibited(int *);
long IsFromMachineHive(HKEY__ *,int *);
long IsLrpcClientRpcss(void *,bool *);
long IsRpcClientTokenAppContainer(void *,bool *);
long IsRpcServerCallOnLocalTransport(void *,bool *);
long IsStringPropertyValuePresentInServerRegistration(HSTRING__ *,Windows::Foundation::IExtensionRegistration *,Windows::Internal::StringReference &,Windows::Internal::StringReference &,bool &);
long IsTokenAppContainer(void *,int *);
long IsTokenChildAppContainer(void *,int *);
long IsUIAccessToken(void *,int *);
long IsUserHiveOK(void *,int *);
long LazyMarshalGIPEntryCallback(void *);
long LeaveServiceDomain(IObjContext * *);
long LoadLibraryWithLogging(LoadOrFreeWhy,unsigned short const *,unsigned long,HINSTANCE__ * *);
long LoadPersistentObject(IUnknown *,IInstanceInfo *);
long LogEventGetClassObject(_GUID const &,_GUID const &,void * *);
long LookForConfiguredClsid(_GUID const &,_GUID &,unsigned long,IComClassInfo * *,bool *);
long LookupPrincName(unsigned short,unsigned short * *);
long MTAThreadCanMakeOutCall(unsigned long,_GUID const &,tagRPCOLEMESSAGE *);
long MTAThreadCheckAndAdjustRpcFlagsInClientGetBuffer(tagRPCOLEMESSAGE *,_GUID const &,bool);
long MTAThreadDispatchCrossApartmentCall(tagRPCOLEMESSAGE *,OXIDEntry *,CSyncClientCall *);
long MTAThreadWaitForCall(CSyncClientCall *,WaitForCallReason,unsigned long);
long MTHostActivatorGetClassObject(_GUID const &,_GUID const &,void * *);
long MakeCloakedSCMProxy(void *,void * *);
long MakeFakeObjRef(tagOBJREF &,OXIDEntry *,_GUID const &,_GUID const &);
long MakeProxyHelper(tagDUALSTRINGARRAY const *,_GUID const &,unsigned long,unsigned long,void * *);
long MakeSCMProxy(tagDUALSTRINGARRAY const *,_GUID const &,void * *);
long MallocInitialize();
long MapStreamACLToAccessList(tagPCB *,_ACTRL_ALISTW * *);
long MarshalHelperMulti(IUnknown *,unsigned long,_GUID *,tagMInterfacePointer * *,long *,CDestObject *);
long MarshalInterfacePointerForTransferSyntax<0>(unsigned long,unsigned char const *,unsigned long,unsigned char *);
long MarshalInterfacePointerForTransferSyntax<1>(unsigned long,unsigned char const *,unsigned long,unsigned char *);
long MarshalInternalObjRef(tagOBJREF &,_GUID const &,void *,unsigned long,void * *);
long MarshalObjRef(tagOBJREF &,_GUID const &,void *,unsigned long,unsigned long,void *);
long MarshalSizeHelper(unsigned long,void *,unsigned long,CObjectContext *,int,unsigned long *);
long MatchWinRTTrustLevels(IWinRTRuntimeClassInfo *,IInspectable *);
long ModalLoop(CSyncClientCall *);
long MulNdrpSetupBeginClientCall(tagCStdAsyncProxyBuffer *,void *,_NDR_PROC_CONTEXT *,_GUID const &);
long MulNdrpSetupFinishClientCall(tagCStdAsyncProxyBuffer *,void *,_GUID const &,unsigned long,_NDR_PROC_CONTEXT *);
long NTHostActivatorGetClassObject(_GUID const &,_GUID const &,void * *);
long Ndr64pCompleteDcomAsyncStubCall(tagCStdAsyncStubBuffer *);
long Ndr64pSetupBeginStubCall(tagCStdAsyncStubBuffer *,_NDR_PROC_CONTEXT *,_GUID const &);
long NdrCoGetMarshalSizeMax(unsigned long *,_GUID const &,IUnknown *,unsigned long,void *,unsigned long);
long NdrCoMarshalInterface(IStream *,_GUID const &,IUnknown *,unsigned long,void *,unsigned long);
long NdrCoUnmarshalInterface(IStream *,_GUID const &,void * *);
long NdrExtGetComProtocolVersion(_MIDL_STUB_MESSAGE *,_RPC_VERSION *);
long NdrExtNegotiateTransferSyntax(void *,_MIDL_STUB_MESSAGE *,_MIDL_STUBLESS_PROXY_INFO *,_NDR_PROC_CONTEXT *);
long NdrExtSetupClientInterface(void *,_MIDL_STUB_MESSAGE *,_MIDL_STUBLESS_PROXY_INFO *);
long NdrGetBaseInterfaceFromStub(IRpcStubBuffer *,IRpcStubBuffer * *,_GUID *);
long NdrLoadOleAutomationRoutines();
long NdrNewGetDcomProtocolVersion(_MIDL_STUB_MESSAGE *,_RPC_VERSION *);
long NdrOleCreateProxyFromFileInfo(IPSFactoryBuffer *,IUnknown *,tagProxyFileInfo const *,long,IRpcProxyBuffer * *,void * *);
long NdrOleCreateStubFromFileInfo(IPSFactoryBuffer *,_GUID const &,tagProxyFileInfo const *,long,IUnknown *,IRpcStubBuffer * *);
long NdrOleCreateWinrtTypeSerializer(_MIDL_WINRT_TYPE_SERIALIZATION_INFO const *,_GUID const &,void * *);
long NdrOleDllCanUnloadNow(tagCStdPSFactoryBuffer *);
long NdrOleDllRegisterProxy(HINSTANCE__ *,tagProxyFileInfo const * *,_GUID const *);
long NdrOleDllUnregisterProxy(HINSTANCE__ *,tagProxyFileInfo const * *,_GUID const *);
long NdrOleInitializeExtension(_NDROLE_EXTENSION_ROUTINES_TABLE const * *,_NDR_FWD_ROUTINES const * *);
long NdrOleInitializeImports();
long NdrOleMakePerInterfacePSFactory(ICreatePerInterfacePSFactory *,_GUID const &,tagProxyFileInfo const *,long,IPerInterfacePSFactory * *);
long NdrOleMulNdrpInitializeContextFromProc(SYNTAX_TYPE,unsigned char const *,_NDR_PROC_CONTEXT *,unsigned char *,unsigned char);
long NdrStringRead(IStream *,unsigned short * *);
long NdrStringWrite(IStream *,unsigned short const *);
long NdrpBeginDcomAsyncClientCall(_MIDL_STUB_DESC const *,unsigned char const *,unsigned char *,unsigned char);
long NdrpCheckClass(char const *,char const *);
long NdrpCompleteDcomAsyncStubCall(tagCStdAsyncStubBuffer *);
long NdrpCreateDelegatedAsyncProxy(IRpcProxyBuffer *,_GUID const &,IUnknown *,tagCStdAsyncProxyBuffer * *);
long NdrpCreateDelegatedAsyncStub(IRpcStubBuffer *,_GUID const &,IUnknown *,IRpcStubBuffer * *);
long NdrpCreateNonDelegatedAsyncProxy(IRpcProxyBuffer *,_GUID const &,IUnknown *,tagCStdAsyncProxyBuffer * *);
long NdrpCreateNonDelegatedAsyncStub(IRpcStubBuffer *,_GUID const &,IUnknown *,IRpcStubBuffer * *);
long NdrpFinishDcomAsyncClientCall(_MIDL_STUB_DESC const *,unsigned char const *,unsigned char *,unsigned char);
long NdrpGetClassID(char *,_GUID const *,tagProxyFileInfo const * *);
long NdrpGetMarshalingContextAttributeFromChannel(_MIDL_STUB_MESSAGE *,ComCallMarshalingDirection,CO_MARSHALING_CONTEXT_ATTRIBUTES,unsigned __int64 *);
long NdrpGetMarshalingLocalityFromChannel(_MIDL_STUB_MESSAGE *,ComCallMarshalingLocality *);
long NdrpInitializeProxyDll(tagProxyFileInfo const * *,tagCStdPSFactoryBuffer *);
long NdrpInitializeStublessVtbl(unsigned long);
long NdrpRegisterAsyncInterface(HKEY__ *,_GUID const &,char const *,long,_GUID const &);
long NdrpRegisterClass(char const *,char const *,char const *,char const *);
long NdrpRegisterInterface(HKEY__ *,_GUID const &,char const *,char const *,long,_GUID const *);
long NdrpReleaseMarshalBuffer(_RPC_MESSAGE *,unsigned char const *,_MIDL_STUB_DESC const *,unsigned long,unsigned char);
long NdrpSetupBeginClientCall(tagCStdAsyncProxyBuffer *,void *,unsigned short,_GUID const &);
long NdrpSetupBeginStubCall(tagCStdAsyncStubBuffer *,unsigned short,_GUID const &);
long NdrpSetupFinishClientCall(tagCStdAsyncProxyBuffer *,void *,unsigned short,_GUID const &,unsigned long);
long NdrpSetupFinishStubCall(tagCStdAsyncStubBuffer *,unsigned short,_GUID const &);
long NdrpUnregisterClass(char const *,char const *);
long NdrpUnregisterInterface(HKEY__ *,_GUID const &,char const *,_GUID const *);
long NdrpValidateAsyncProxyCall(tagCStdAsyncProxyBuffer *);
long NdrpValidateAsyncStubCall(tagCStdAsyncStubBuffer *);
long NdrpValidateDcomAsyncMsg(_NDR_DCOM_ASYNC_MESSAGE *);
long NotifyInitializeSpies(int,int,unsigned long,long);
long ORPCInterfaceSecCallback(void *,void *);
long ObtainPolicySet(CObjectContext *,CObjectContext *,unsigned long,int *,CPolicySet * *);
long ObtainStdIDFromOID(_GUID const &,unsigned long,int,CStdIdentity * *);
long ObtainStdIDFromUnk(IUnknown *,unsigned long,CObjectContext *,unsigned long,CStdIdentity * *);
long Ole10_CLSIDFromString(unsigned short const *,_GUID *,int);
long OleStringFromIID(_GUID const &,unsigned short * *);
long OpenThreadTokenAtLevel(unsigned long,void * *);
long PackagedComProxyStubGetClassObject(_GUID const &,HSTRING__ *,unsigned long,_GUID const &,void * *);
long PeekMessageExceptionFilter(_EXCEPTION_POINTERS *);
long PerformCallback(CObjectContext *,long (*)(void *),void *,_GUID const &,unsigned long,IUnknown *);
long PopServiceDomainContext(tagContextStackNode *);
long PostReleaseRifRef(IRemUnknown *,int,OXIDEntry *,unsigned short,tagREMINTERFACEREF *,IUnknown *);
long PrepareWrapperForDestruction(void *);
long PrivGetObjectContext(_GUID const &,void * *);
long PrivSetClientHResult(tagRPCOLEMESSAGE *,long,int);
long PrivSetServerHResult(tagRPCOLEMESSAGE *,void *,long);
long ProcessCustomEPIfNecessary(unsigned short,int *);
long ProcessInitialize();
long PushServiceDomainContext(tagContextStackNode const &);
long PutStreamACLIntoSecDesc(tagSTREAM_ACL *,tagACL_DESCRIPTOR *);
long QueryBlanketFromChannel(CClientChannel *,unsigned long *,unsigned long *,unsigned short * *,unsigned long *,unsigned long *,void * *,unsigned long *);
long RPCSStoOLE32SecurityCallback(void *,void *);
long ReadACLFromStream(IStream *,tagPCB *,tagACL_DESCRIPTOR *);
long ReadActivationTypeAndRemoteEndpoint(IWinRTRuntimeClassInfo *,Windows::Foundation::ActivationType &,_COSERVERINFO *);
long ReadObjRef(IStream *,tagOBJREF &);
long ReadObjRefExtension(IStream *,tagOBJREF &);
long ReceiveAcknowledgmentOfOutParameterMarshalingSets(void *,unsigned short,unsigned __int64 *);
long RegHelpSuspendImpersonate(void * *);
long RegOpenCurrentUserLocalSettings(unsigned long,HKEY__ * *);
long RegisterAuthnServices(unsigned long,tagSOLE_AUTHENTICATION_SERVICE *);
long RegisterDcomInterfaces();
long RegisterLrpc();
long RegisterOleWndClass();
long ReleaseCallback(void *);
long ReleaseIFD(tagMInterfacePointer *);
long ReleaseMarshalBuffer(tagRPCOLEMESSAGE *,IUnknown *,int);
long ReleaseMarshalObjRef(tagOBJREF &,EffectiveUnmarshalingPolicy);
long ReleaseMtaUnmarshaledProxyCallback(void *);
long ReleaseObjRefSwitch(void *);
long ReleaseObjrefCallback(void *);
long ReleaseTypeFormatString(unsigned char const *);
long ReleaseVtbl(TypeInfoVtbl *);
long RemUnkAccessCheck(int *,unsigned long *);
long RemoteReleaseRifRef(CStdMarshal *,OXIDEntry *,unsigned short,tagREMINTERFACEREF *);
long RemoteReleaseRifRefHelper(IRemUnknown *,int,int,OXIDEntry *,unsigned short,tagREMINTERFACEREF *,IUnknown *);
long RemoteReleaseStdObjRef(tagSTDOBJREF *,OXIDEntry *);
long ReplaceSyncServerCallWithAsync(tagRPCOLEMESSAGE *,_GUID const &,CServerChannel::CServerCallMgr *,AsyncComServerCall * *);
long ResetObject(IUnknown *);
long ResizePicklingBuff(tagPCB *,unsigned long);
long RoCausalityTraceAsyncOperationCompletion(Windows::Foundation::Diagnostics::CausalityTraceLevel,Windows::Foundation::Diagnostics::CausalitySource,_GUID,unsigned __int64,ABI::Windows::Foundation::AsyncStatus);
long RoCausalityTraceAsyncOperationCreation(Windows::Foundation::Diagnostics::CausalityTraceLevel,Windows::Foundation::Diagnostics::CausalitySource,_GUID,unsigned __int64,unsigned short const *,unsigned __int64);
long RoCausalityTraceAsyncOperationRelation(Windows::Foundation::Diagnostics::CausalityTraceLevel,Windows::Foundation::Diagnostics::CausalitySource,_GUID,unsigned __int64,Windows::Foundation::Diagnostics::CausalityRelation);
long RoCausalityTraceSynchronousWorkItemCompletion(Windows::Foundation::Diagnostics::CausalityTraceLevel,Windows::Foundation::Diagnostics::CausalitySource,Windows::Foundation::Diagnostics::CausalitySynchronousWork);
long RoCausalityTraceSynchronousWorkItemStart(Windows::Foundation::Diagnostics::CausalityTraceLevel,Windows::Foundation::Diagnostics::CausalitySource,_GUID,unsigned __int64,Windows::Foundation::Diagnostics::CausalitySynchronousWork);
long RpcETooLate();
long RtlStringCchCatW(unsigned short *,unsigned __int64,unsigned short const *);
long RtlStringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long RtlStringCchLengthW(unsigned short const *,unsigned __int64,unsigned __int64 *);
long SendAutoRetryResponse(ServerCall *,bool *);
long ServerNotify<0>(WireThis *,unsigned long,unsigned long *,unsigned long,CMessageCall *);
long SetBlanketOnChannel(CClientChannel *,unsigned long,unsigned long,unsigned short *,unsigned long,unsigned long,void *,unsigned long);
long SetConditionalDefaultGlobalOptions();
long SetDefaultBrowser(HSTRING__ *,HSTRING__ *,HSTRING__ *,HSTRING__ *,HSTRING__ *,HSTRING__ *);
long SetExplicitWinstaDesktopString(unsigned __int64);
long ShouldUsePrivateHiveFile(HSTRING__ *,PackageContext const &,bool *);
long SignalObject(IUnknown *);
long SizeInterfacePointerForTransferSyntax<0>(unsigned long,unsigned long *);
long SizeInterfacePointerForTransferSyntax<1>(unsigned long,unsigned long *);
long StRead(IStream *,void *,unsigned long);
long StdMarshalObject(IStream *,_GUID const &,IUnknown *,CObjectContext *,unsigned long,void *,unsigned long);
long StringCbCopyExW(unsigned short *,unsigned __int64,unsigned short const *,unsigned short * *,unsigned __int64 *,unsigned long);
long StringCbCopyNW(unsigned short *,unsigned __int64,unsigned short const *,unsigned __int64);
long StringCbCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCbLengthW(unsigned short const *,unsigned __int64,unsigned __int64 *);
long StringCbPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long StringCchCatExW(unsigned short *,unsigned __int64,unsigned short const *,unsigned short * *,unsigned __int64 *,unsigned long);
long StringCchCatW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchCopyA(char *,unsigned __int64,char const *);
long StringCchCopyExA(char *,unsigned __int64,char const *,char * *,unsigned __int64 *,unsigned long);
long StringCchCopyExW(unsigned short *,unsigned __int64,unsigned short const *,unsigned short * *,unsigned __int64 *,unsigned long);
long StringCchCopyNExW(unsigned short *,unsigned __int64,unsigned short const *,unsigned __int64,unsigned short * *,unsigned __int64 *,unsigned long);
long StringCchCopyNW(unsigned short *,unsigned __int64,unsigned short const *,unsigned __int64);
long StringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchCopyW(wchar_t *,unsigned __int64,wchar_t const *);
long StringCchLengthA(char const *,unsigned __int64,unsigned __int64 *);
long StringCchLengthW(unsigned short const *,unsigned __int64,unsigned __int64 *);
long StringCchPrintfA(char *,unsigned __int64,char const *,...);
long StringCchPrintfExW(unsigned short *,unsigned __int64,unsigned short * *,unsigned __int64 *,unsigned long,unsigned short const *,...);
long StringCchPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long StringCchVPrintfW(unsigned short *,unsigned __int64,unsigned short const *,char *);
long SuspendImpersonate(void * *);
long SwitchAfterCallback(CPolicySet *,CRpcCall &,CCtxCall *,CCtxCall *);
long SwitchForCallback(CPolicySet *,long (*)(void *),void *,_GUID const &,unsigned long,IUnknown *);
long ThreadFirstInitialize(COleTls &,unsigned long);
long ThreadSendReceive(tagRPCOLEMESSAGE *,CSyncClientCall *,_GUID const &);
long UninitializedThreadCanMakeOutCall(unsigned long,_GUID const &,tagRPCOLEMESSAGE *);
long UninitializedThreadCheckAndAdjustRpcFlagsInClientGetBuffer(tagRPCOLEMESSAGE *,_GUID const &,bool);
long UninitializedThreadDispatchCrossApartmentCall(tagRPCOLEMESSAGE *,OXIDEntry *,CSyncClientCall *);
long UninitializedThreadReceive(ClientCall *,tagRPCOLEMESSAGE *,unsigned long,unsigned long *);
long UninitializedThreadSend(ClientCall *,tagRPCOLEMESSAGE *,unsigned long *);
long UninitializedThreadSendMessageToClassicSTA(unsigned long,SendMessageToClassicSTAReason,HWND__ *,unsigned int,unsigned __int64,__int64);
long UninitializedThreadSendReceive(CSyncClientCall *,tagRPCOLEMESSAGE *,unsigned long *);
long UninitializedThreadWaitForCall(CSyncClientCall *,WaitForCallReason,unsigned long);
long UnmarshalInternalObjRef(tagOBJREF &,void * *);
long UnmarshalObjRef(tagOBJREF &,EffectiveUnmarshalingPolicy,void * *,int,CStdMarshal * *);
long UnmarshalSwitch(void *);
long UnregisterDcomInterfaces();
long UpdateProcessTracing(unsigned long,int);
long UpdateResultsArray(long,unsigned long,tagMULTI_QI *);
long UseSetErrorInfo(long,unsigned short const *,void *,unsigned short,IUnknown *,IRestrictedErrorInfo *,int,IRestrictedErrorInfo * *);
long ValidateAccessCheckClient(_TRUSTEE_W *);
long ValidateAndCalculateSizeOfIncomingLocalThat(unsigned long,WireLocalThat const *,unsigned long *);
long ValidateAndCalculateSizeOfMarshaledInterfacePointer<0>(unsigned long,unsigned char const *,bool *,unsigned long *,unsigned long *,unsigned char const * *);
long ValidateAndCalculateSizeOfMarshaledInterfacePointer<1>(unsigned long,unsigned char const *,bool *,unsigned long *,unsigned long *,unsigned char const * *);
long ValidateAndFixStreamACL(tagSTREAM_ACL *,unsigned long *,unsigned long *);
long ValidateAndRemapParams(_GUID const &,unsigned long &,_COSERVERINFO *,unsigned long,tagMULTI_QI *);
long ValidateAndTransformAccReqList(_ACTRL_ALISTW *,tagSTREAM_ACE * *,void * *,unsigned long *,unsigned long *,unsigned long *);
long ValidateCatalogSecurityDescriptor(unsigned long,_SECURITY_DESCRIPTOR_RELATIVE const *,bool,unsigned short const *);
long ValidateMarshalFlags(unsigned long,void *,unsigned long);
long ValidateObjRef(tagInterfaceData *,unsigned long,_GUID const *);
long ValidateObjRefExtension(tagInterfaceData *,unsigned long,unsigned long,tagOBJREF &);
long ValidateTrustee(_TRUSTEE_W *);
long ValidateTrusteeString(unsigned short *);
long VarVtOfIface(ITypeInfo *,tagTYPEATTR *,PARAMINFO *);
long VarVtOfTypeDesc(ITypeInfo *,tagTYPEDESC *,PARAMINFO *);
long VarVtOfUDT(ITypeInfo *,tagTYPEDESC *,PARAMINFO *);
long VerifyAuthIdentity(_COAUTHIDENTITY *);
long WaitCoalesced(void *,unsigned int,void * const *,unsigned long,unsigned long,int,unsigned long *);
long WinRTCreateInstanceOfOutofprocClass(IWinRTRuntimeClassInfo *,Windows::Foundation::IExtensionRegistration *,unsigned long,unsigned long,unsigned __int64,Windows::Foundation::IActivationContext *,tagMULTI_QI *);
long WinRTGetActivationFactoryOfOutofprocClass(IWinRTRuntimeClassInfo *,unsigned long,unsigned long,unsigned __int64,tagMULTI_QI *);
long WinRTGetProxyStubCLSIDForInterface(_GUID const &,_GUID *);
long WinRTGetRuntimeClassInfo(HSTRING__ *,HSTRING__ *,IWinRTRuntimeClassInfo * *,unsigned long,bool);
long WinRTGetServerInfo(HSTRING__ *,HSTRING__ *,IWinRTServerInfo * *);
long WindowsInspectStringImpl(unsigned __int64,unsigned short,ICallbackWrapper const &,void *,unsigned int *,unsigned __int64 *);
long WinrtAsyncChannelCreateClientCall(WinrtAsyncOperationInfo const &,IWinrtAsyncClientRpcOleMessageCallProxyCallbacks *,IWinrtAsyncProxyCall *,IStubCall *,_GUID const &,bool,unsigned long,OXIDEntry *,tagIPIDEntry *,_GUID const &,CStdIdentity *,IWinrtAsyncClientCall * *);
long WinrtAsyncChannelCreateServerCall(WinrtAsyncOperationInfo const &,_RPC_MESSAGE *,IWinrtAsyncProxyCall *,IStubCall *,_GUID const &,bool,ComCallTraceActivity *,IWinrtAsyncServerCall * *);
long WinrtAsyncProxyCreateClientCall(IClientCallChannel *,tagRPCOLEMESSAGE *,_GUID const &,bool,bool *);
long WinrtAsyncProxyCreateServerCall(IServerCallChannel *,_RPC_MESSAGE *,_GUID const &,bool,ComCallTraceActivity *,IServerCall * *);
long WrapperMarshalObject(IStream *,_GUID const &,IUnknown *,unsigned long,void *,unsigned long);
long WriteCustomObjrefHeaderToStream(_GUID const &,_GUID const &,unsigned long,IStream *);
long WriteObjRef(IStream *,tagOBJREF &,unsigned long);
long _CoUnmarshalInterface(IStream *,bool,_GUID const &,void * *);
long gServerOIDCount;
long g_bInSCM;
long gcChannelHook;
long giTlsNextFreeEntry;
long utGetAppIdForModule(unsigned short *,unsigned long);
long utGetModuleName(unsigned short *,unsigned long);
long utInitModuleNameCache();
long wCLSIDFromOle1Class(unsigned short const *,_GUID *,int,int);
long wCLSIDFromString(unsigned short const *,_GUID *);
long wCoGetInterfaceAndReleaseStream(IStream *,_GUID const &,void * *);
long wCoGetTreatAsClass(_GUID const &,_GUID *);
long wCoIncrementMTAUsage();
long wCoMarshalInterThreadInterfaceInStream(_GUID const &,IUnknown *,IStream * *);
long wCoRegisterComBinding(unsigned short *,unsigned short *,unsigned long);
long wGetEndpointsForApp(_GUID *);
long wGetRpcProtSeqMaxCallsValueForAppID();
long wRegOpenClassKey(_GUID const &,unsigned long,HKEY__ * *);
long wRegOpenInterfaceKey(_GUID const &,HKEY__ * *);
long wRegQueryAsyncIIDFromSyncIID(_GUID const &,_GUID *);
long wRegQueryClassValue(_GUID const &,unsigned short const *,unsigned short *,int);
long wRegQueryPSClsid(_GUID const &,bool,_GUID *);
long wRegQuerySyncIIDFromAsyncIID(_GUID const &,_GUID *);
long wStringFromCLSID(_GUID const &,unsigned short * *);
long wStringFromIID(_GUID const &,unsigned short * *);
long wStringFromUUID(_GUID const &,unsigned short *);
long wil_details_NtQueryWnfStateData(__WIL__WNF_STATE_NAME const *,__WIL__WNF_TYPE_ID const *,void const *,unsigned long *,void *,unsigned long *);
long wil_details_NtUpdateWnfStateData(__WIL__WNF_STATE_NAME const *,void const *,unsigned long,__WIL__WNF_TYPE_ID const *,void const *,unsigned long,unsigned long);
long wil_details_RtlSubscribeWnfStateChangeNotification(__WIL__WNF_USER_SUBSCRIPTION * *,__WIL__WNF_STATE_NAME,unsigned long,long (*)(__WIL__WNF_STATE_NAME,unsigned long,__WIL__WNF_TYPE_ID *,void *,void const *,unsigned long),void *,__WIL__WNF_TYPE_ID *,unsigned long,unsigned long);
long wil_details_StagingConfig_FireNotification(wil_details_StagingConfig *,unsigned int,unsigned short);
long wil_details_StagingConfig_Load(wil_details_StagingConfig *,wil_FeatureStore,unsigned __int64,void *,int);
long wkProgIDFromCLSID(_GUID const &,unsigned short * *);
std::atomic<bool> g_tracedActivityControlFailure;
tagCOMVERSION const CurrentComVersion;
tagDUALSTRINGARRAY * gpsaCurrentProcess;
tagDUALSTRINGARRAY * gpsaSecurity;
tagEventLogSD genumAccessSD;
tagGLOBALOPT_EH_VALUES g_GLBOPT_EHValue;
tagGLOBALOPT_UNMARSHALING_POLICY_VALUES g_GLBOPT_UnmarshalingPolicy;
tagSECURITYBINDING * gLegacySecurity;
tagSOleTlsData * TLSLookupThreadId(unsigned long);
tagSOleTlsData * TLSPreallocateData(unsigned long);
tagTLSMapEntry * gpTlsMap;
unsigned __int64 CRetailMalloc_GetSize(IMalloc *,void *);
unsigned __int64 CSpyMalloc_GetSize(IMalloc *,void *);
unsigned __int64 NdrStringSize(unsigned short const *);
unsigned __int64 gLocalMid;
unsigned __int64 gTimerId;
unsigned char (* gCausalityShouldLog)[3];
unsigned char * (* pfnLPSAFEARRAY_Marshal)(unsigned long *,unsigned char *,tagSAFEARRAY * *,_GUID const *);
unsigned char * (* pfnLPSAFEARRAY_Unmarshal)(unsigned long *,unsigned char *,tagSAFEARRAY * *,_GUID const *);
unsigned char * (* pfnLPSAFEARRAY_UserMarshal)(unsigned long *,unsigned char *,void *);
unsigned char * (* pfnLPSAFEARRAY_UserUnmarshal)(unsigned long *,unsigned char *,void *);
unsigned char * HBITMAP_UserUnmarshalWorker(unsigned long *,unsigned char *,HBITMAP__ * *,unsigned __int64);
unsigned char * HBITMAP_UserUnmarshalWorker64(unsigned long *,unsigned char *,HBITMAP__ * *,unsigned __int64);
unsigned char * HENHMETAFILE_UserUnmarshalWorker(unsigned long *,unsigned char *,HENHMETAFILE__ * *,unsigned __int64);
unsigned char * HENHMETAFILE_UserUnmarshalWorker64(unsigned long *,unsigned char *,HENHMETAFILE__ * *,unsigned __int64);
unsigned char * HMETAFILEPICT_UserUnmarshalWorker(unsigned long *,unsigned char *,void * *,unsigned __int64);
unsigned char * HMETAFILEPICT_UserUnmarshalWorker64(unsigned long *,unsigned char *,void * *,unsigned __int64);
unsigned char * HPALETTE_UserUnmarshalWorker(unsigned long *,unsigned char *,HPALETTE__ * *,unsigned __int64);
unsigned char * HPALETTE_UserUnmarshalWorker64(unsigned long *,unsigned char *,HPALETTE__ * *,unsigned __int64);
unsigned char * HRGN_UserMarshal(unsigned long *,unsigned char *,HRGN__ * *);
unsigned char * HRGN_UserMarshal64(unsigned long *,unsigned char *,HRGN__ * *);
unsigned char * HRGN_UserUnmarshal(unsigned long *,unsigned char *,HRGN__ * *);
unsigned char * HRGN_UserUnmarshal64(unsigned long *,unsigned char *,HRGN__ * *);
unsigned char * HSTRING_Helper_MarshalNative(unsigned long,unsigned char *,bool,HSTRING__ * *);
unsigned char * LPSAFEARRAY_Marshal(unsigned long *,unsigned char *,tagSAFEARRAY * *,_GUID const *);
unsigned char * LPSAFEARRAY_Unmarshal(unsigned long *,unsigned char *,tagSAFEARRAY * *,_GUID const *);
unsigned char * Ndr64ExtInterfacePointerUnmarshall(_MIDL_STUB_MESSAGE *,void const *);
unsigned char * NdrExtInterfacePointerMarshall(_MIDL_STUB_MESSAGE *,unsigned char *,unsigned char const *);
unsigned char * STGMEDIUM_UserUnmarshalWorker(unsigned long *,unsigned char *,tagSTGMEDIUM *,unsigned __int64);
unsigned char * STGMEDIUM_UserUnmarshalWorker64(unsigned long *,unsigned char *,tagSTGMEDIUM *,unsigned __int64);
unsigned char * SafeArrayMarshal(unsigned long *,unsigned char *,tagSAFEARRAY * *);
unsigned char * SafeArrayUnmarshal(unsigned long *,unsigned char *,tagSAFEARRAY * *);
unsigned char * WdtpGlobalUnmarshal(unsigned long *,unsigned char *,void * *,int,unsigned __int64);
unsigned char * WdtpGlobalUnmarshal64(unsigned long *,unsigned char *,void * *,int,unsigned __int64);
unsigned char * WdtpInterfacePointer_UserUnmarshalWorker(_USER_MARSHAL_CB *,unsigned char *,IUnknown * *,_GUID const &,unsigned __int64,int);
unsigned char * WdtpRemotableHandle_UserMarshal(unsigned long *,unsigned char *,__int64 *);
unsigned char * WdtpRemotableHandle_UserUnmarshal(unsigned long *,unsigned char *,__int64 *);
unsigned int FnvHash(unsigned char const *,unsigned __int64);
unsigned int Ndr64pConvertTo2GB(unsigned __int64);
unsigned int const * const g_tkCorEncodeToken;
unsigned int g_packageInfoCount;
unsigned long (* pfnLPSAFEARRAY_Size)(unsigned long *,unsigned long,tagSAFEARRAY * *,_GUID const *);
unsigned long (* pfnLPSAFEARRAY_UserSize)(unsigned long *,unsigned long,void *);
unsigned long ActErrorPriority(long);
unsigned long AsyncChannelWrapper_AddRef(IAsyncRpcChannelBuffer *);
unsigned long AsyncChannelWrapper_Release(IAsyncRpcChannelBuffer *);
unsigned long CMalloc_AddRef(IMalloc *);
unsigned long CMalloc_Release(IMalloc *);
unsigned long CStdPSFactoryBuffer_AddRef(ICreatePerInterfacePSFactory *);
unsigned long CStdPSFactoryBuffer_Release(ICreatePerInterfacePSFactory *);
unsigned long CStdProxyBuffer3_Release(IRpcProxyBuffer *);
unsigned long CStdProxyBuffer_Release(IRpcProxyBuffer *);
unsigned long CStdStubBuffer3_Release(IRpcStubBuffer *);
unsigned long CalculateSpinCount();
unsigned long ChannelWrapper_AddRef(IRpcChannelBuffer3 *);
unsigned long ChannelWrapper_Release(IRpcChannelBuffer3 *);
unsigned long CheckDownloadRegistrySettings();
unsigned long ComSignal(void *);
unsigned long ComSignalNA(void *);
unsigned long DLLHostThreadEntry(void *);
unsigned long DefaultAuthnSvc(OXIDEntry *);
unsigned long EtwEx_tidActivityInfo(unsigned __int64,_EVENT_DESCRIPTOR const *,_GUID const *,_GUID const *,unsigned long);
unsigned long EtwEx_tidActivityInfoTransfer(unsigned __int64,_EVENT_DESCRIPTOR const *,_GUID const *,_GUID const *,unsigned char,_GUID const *,unsigned long);
unsigned long FindExtentId(SHookList const *,unsigned long,_GUID);
unsigned long GetArchitecturePointerSizeInBytes(unsigned long);
unsigned long GetAuthnSvcIndexForBinding(unsigned long,tagDUALSTRINGARRAY *);
unsigned long GetBulkUpdateRate();
unsigned long GetCatalogExclusiveRegViewFlagFromActivationFlags(unsigned long);
unsigned long GetCurrentApartmentId();
unsigned long GetLoadLibraryAlteredSearchPathFlag();
unsigned long GetMsgQInputFlag(tagRPCOLEMESSAGE *);
unsigned long GetNativeArchitecture();
unsigned long GetRPCIfFlagForSystemIID(_GUID const *);
unsigned long HRGN_UserSize(unsigned long *,unsigned long,HRGN__ * *);
unsigned long HRGN_UserSize64(unsigned long *,unsigned long,HRGN__ * *);
unsigned long LPSAFEARRAY_Size(unsigned long *,unsigned long,tagSAFEARRAY * *,_GUID const *);
unsigned long NetTraceRegisterCorrelationProviderEx(_GUID const *,unsigned __int64 *);
unsigned long ReleasedCachedMTAProxyAsync(void *);
unsigned long RevokeFromMTAAsync(void *);
unsigned long RevokeFromMTASync(void *);
unsigned long SafeArraySize(unsigned long *,unsigned long,tagSAFEARRAY * *);
unsigned long ThreadDispatchThreadProc(void *);
unsigned long WdtpRemotableHandle_UserSize(unsigned long *,unsigned long,__int64 *);
unsigned long const * const gMsgQInputFlagTbl;
unsigned long const * const gRpcFlagToCallCatMap;
unsigned long gAuthnLevel;
unsigned long gCapabilities;
unsigned long gChannelProcessInitializedCounter;
unsigned long gClientSvcListLen;
unsigned long gImpLevel;
unsigned long gMostRecentPermissionsIndex;
unsigned long gMostRecentRestrictionsIndex;
unsigned long gNumExtent;
unsigned long gServerSvcListLen;
unsigned long g_GLBOPT_RoFlags;
unsigned long g_Ole32SQM;
unsigned long g_dwComSpinCount;
unsigned long g_dwForwardVtblSize;
unsigned long g_dwVtblSize;
unsigned long g_maximumRandomDelayInMs;
unsigned long g_ulHeaderSize;
unsigned long gcActivationHostThreadInits;
unsigned long gcImagePath;
unsigned long gcInitingMTA;
unsigned long gcNAHosts;
unsigned long gcSCMProtSeqs;
unsigned long gcTlsTotalEntries;
unsigned long gcTlsUsedEntries;
unsigned long gdwCacheableFlags;
unsigned long gdwMainThreadId;
unsigned long gdwPsaMaxSize;
unsigned long gdwRpcProtSeqMaxCalls;
unsigned long gdwScmProcessID;
unsigned long gdwTCPEndpoint;
unsigned long giPingPeriod;
unsigned long s_dwFastRundownTimeout;
unsigned short * CharPrevStub(unsigned short const *,unsigned short const *);
unsigned short * DuplicateStringPrivMem(unsigned short const *);
unsigned short * GetClientNetworkAddress(void *);
unsigned short * gKeyName;
unsigned short * gOleWindowClass;
unsigned short * gServerSvcList;
unsigned short * g_explicitWinstaDesktopString;
unsigned short * gaSCMProtSeqs;
unsigned short * gpwszImagePath;
unsigned short * gwszLRPCEndPoint;
unsigned short const * const RttiTypeName_Foundation_NamespaceName;
unsigned short const * const RttiTypeName_Windows_Foundation_AsyncActionProgressHandler;
unsigned short const * const RttiTypeName_Windows_Foundation_AsyncActionWithProgressCompletedHandler;
unsigned short const * const RttiTypeName_Windows_Foundation_AsyncOperationCompletedHandler;
unsigned short const * const RttiTypeName_Windows_Foundation_AsyncOperationProgressHandler;
unsigned short const * const RttiTypeName_Windows_Foundation_AsyncOperationWithProgressCompletedHandler;
unsigned short const * const RttiTypeName_Windows_Foundation_IAsyncActionWithProgress;
unsigned short const * const RttiTypeName_Windows_Foundation_IAsyncOperation;
unsigned short const * const RttiTypeName_Windows_Foundation_IAsyncOperationWithProgress;
unsigned short const * const RttiTypeName_Windows_NamespaceName;
unsigned short const * const RuntimeClass_Windows_Foundation_ActivationContext;
unsigned short const * const RuntimeClass_Windows_Foundation_Collections_PropertySet;
unsigned short const * const RuntimeClass_Windows_Foundation_Diagnostics_AsyncCausalityTracer;
unsigned short const * const RuntimeClass_Windows_Foundation_Diagnostics_TracingStatusChangedEventArgs;
unsigned short const * const RuntimeClass_Windows_Foundation_ExtensionCatalog;
unsigned short const * const RuntimeClass_Windows_Foundation_PropertyValue;
unsigned short const * const RuntimeClass_Windows_Internal_StateRepository_Package;
unsigned short const * const g_WindowsEmptyStringInternal;
unsigned short const * const g_wszClsidTemplate;
unsigned short const * const g_wszDllHost;
unsigned short const * const g_wszDllHostSlashProcessId;
unsigned short const * const g_wszEmbedding;
unsigned short const * const g_wszEmptyString;
unsigned short const * const g_wszInteractive_User;
unsigned short const * const g_wszLocalService;
unsigned short const * const g_wszProcessId;
unsigned short const * const g_wszRunAs;
unsigned short const * const g_wszSlashProcessId;
unsigned short const * const g_wszThreadingModel;
unsigned short const * const wszTreatAs;
unsigned short const * utGetProtseqFromTowerId(unsigned short);
unsigned short utGetTowerId(unsigned short const *);
void (* gMockApplicationVerifierStop)(unsigned __int64,char *,unsigned __int64,char *,unsigned __int64,char *,unsigned __int64,char *,unsigned __int64,char *);
void (* g_wil_details_apiRecordFeatureUsage)(unsigned int,unsigned int,unsigned int,char const *);
void (* g_wil_details_apiSubscribeFeatureStateChangeNotification)(FEATURE_STATE_CHANGE_SUBSCRIPTION__ * *,void (*)(void *),void *);
void (* g_wil_details_apiUnsubscribeFeatureStateChangeNotification)(FEATURE_STATE_CHANGE_SUBSCRIPTION__ *);
void (* g_wil_details_internalRecordFeatureUsage)(unsigned int,unsigned int,unsigned int,char const *);
void (* g_wil_details_internalSubscribeFeatureStateChangeNotification)(FEATURE_STATE_CHANGE_SUBSCRIPTION__ * *,void (*)(void *),void *);
void (* g_wil_details_internalUnsubscribeFeatureStateChangeNotification)(FEATURE_STATE_CHANGE_SUBSCRIPTION__ *);
void (* g_wil_details_pfnFeatureLoggingHook)(unsigned int,FEATURE_LOGGED_TRAITS const *,FEATURE_ERROR const *,int,wil_ReportingKind const *,wil_VariantReportingKind const *,unsigned char,unsigned __int64);
void (* g_wil_details_recordFeatureUsage)(unsigned int,wil_details_FeaturePropertyCache *,wil_details_RecordUsageResult *);
void * * ProxyForwardVtbl;
void * * StublessClientVtbl;
void * AllocAndCopy(unsigned long,void *,long *);
void * CRetailMalloc_Alloc(IMalloc *,unsigned __int64);
void * CRetailMalloc_Realloc(IMalloc *,void *,unsigned __int64);
void * CSpyMalloc_Alloc(IMalloc *,unsigned __int64);
void * CSpyMalloc_Realloc(IMalloc *,void *,unsigned __int64);
void * CoVrfTrackObject(void *);
void * CoVrfTrackVtbl(void *,VtblSplayNode *);
void * FillBuffer(WireExtentArray *,unsigned long,unsigned long,int,CMessageCall const *,_GUID const *);
void * GetObjectStubless();
void * GetObjectStublessEnd();
void * GetServerMethodAddressForTracing(void *,unsigned long,bool,void *,_GUID const &,void *);
void * GetTokenForRpcClient(void *,int);
void * GetUserSid(void *);
void * NdrCoTaskMemAlloc(unsigned __int64);
void * NdrExtGetServerObject(void *);
void * PrivMemAlloc8(unsigned __int64);
void * ValidateAndParseExtentArray<0>(SHookList const *,WireExtentArray *,unsigned long,unsigned long,WireExtent * *,bool);
void * const * const g_ForwardingVtbl;
void * gSidAnonymous;
void * g_hHeap;
void * g_hMTARundownEvent;
void * s_hReadCatalogCache;
void ASTAThreadBlockForAsyncCancel(unsigned long);
void ATHostActivatorEnsureCreatedBestEffort();
void AddACEToStreamACL(tagSTREAM_ACE *,tagPCB *);
void AddHydraSessionID(ActivationPropertiesIn *);
void AddOrigClsCtx(ActivationPropertiesIn *,unsigned long);
void AddPartitionID(ActivationPropertiesIn *);
void AggressiveDllUnloadRoutine(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *);
void ApphelpHookCOM(_GUID const &,unsigned long,tagMULTI_QI *);
void BreakOnCoInitializeSecurityRuntimeFailureIfRequested(long);
void BreakOnUnexpectedResolveErrors(long);
void CCGetClassInfoFromDllClass(<unnamed-type-DLL_CLASS_HANDLE> *,IComClassInfo * *);
void CRetailMalloc_Free(IMalloc *,void *);
void CRetailMalloc_HeapMinimize(IMalloc *);
void CSpyMalloc_Free(IMalloc *,void *);
void CSpyMalloc_HeapMinimize(IMalloc *);
void CacheAccess(_LUID,int,SAccessCache *,unsigned long *,COleStaticMutexSem *);
void CalculateAnonymousGrantedRemoteAccessInRestrictions();
void CalculateSegmentRange(void *,void * *,void * *);
void CancelPendingCalls(HWND__ *);
void CheckMTAStillPending();
void ClassicSTAThreadBlockForAsyncCancel(unsigned long);
void CleanAllMemoryResources(tagACL_DESCRIPTOR *,tagPCB *);
void CleanUpStreamACL(tagSTREAM_ACL *);
void CleanupCOMOLEInitsOnThread(COleTls &,int);
void CleanupChannelHooks();
void CleanupCtxTableEntry(SHashChain *);
void CleanupIdentity(SHashChain *);
void CleanupMIDEntry(SHashChain *);
void CleanupPolicySets(SHashChain *);
void CleanupRegOIDs(SHashChain *);
void CleanupThreadCallObjects(tagSOleTlsData *);
void CleanupTlsMap(int);
void CleanupTlsState(tagSOleTlsData *,int);
void ClearTlsApartmentAndEmptyContext(COleTls &);
void CoVrfAggressiveDllUnloadInSTA();
void CoVrfCheckClientSecurityBlanket(long,unsigned long,IUnknown *);
void CoVrfCheckServerSecurityBlanket();
void CoVrfDllMainCheck();
void CoVrfFormatInitUninitMessagesWithStacks(char const *,CVerifierStackData &,char const *,CVerifierStackData &,unsigned __int64 *,char *,unsigned __int64 *,char *);
void CoVrfFreeMemObjectChecks(void *,unsigned __int64,void *);
void CoVrfFreeMemVtblChecks(void *,unsigned __int64,void *);
void CoVrfIndicateDisposeMTA(void *);
void CoVrfNotifyCFSuccessWithNULL(IClassFactory *,_GUID const &,_GUID const &,long);
void CoVrfNotifyCoInit();
void CoVrfNotifyEnterServiceDomain();
void CoVrfNotifyExtraLeaveServiceDomain();
void CoVrfNotifyExtraOleUninit();
void CoVrfNotifyExtraUninit();
void CoVrfNotifyGCOSuccessWithNULL(unsigned short const *,_GUID const &,_GUID const &,long);
void CoVrfNotifyIllegalUseOfComObjectAfterFinalCoUninitialize(IUnknown *);
void CoVrfNotifyLeakedInits();
void CoVrfNotifyLeakedOleInits();
void CoVrfNotifyLeakedServiceDomain();
void CoVrfNotifyLeaveServiceDomain();
void CoVrfNotifyOleInit();
void CoVrfNotifyOleUninit();
void CoVrfNotifyPrematureStubRundown(_GUID const &,unsigned long,_GUID const &,WhichTypeOfRundown);
void CoVrfNotifySmuggledProxy(_GUID const &,unsigned long,unsigned long);
void CoVrfNotifySmuggledWrapper(_GUID const &,unsigned long,CStdWrapper *);
void CoVrfNotifyUnexpectedQIOnServerSideStandardMarshaler(_GUID const &,IMarshal *,IUnknown *);
void CoVrfShouldCallOleInit(char const *);
void CoVrfStopTrackingObject(void *);
void ComTraceHr(long,char const *,char const *,int,unsigned short const *,...);
void ComTraceHr(long,char const *,char const *,int,wchar_t const *,...);
void ComTraceMessage(long,char const *,char const *,int,TraceLevel,unsigned short const *,...);
void ComTraceMessage(long,char const *,char const *,int,TraceLevel,wchar_t const *,...);
void ComTraceMessageT<CComApartment *,unsigned int,IMessageParam *>(char const *,char const *,int,TraceLevel,unsigned short const *,CComApartment *,unsigned int,IMessageParam *);
void ComTraceMessageT<CListBase<0> *,CListElement *>(char const *,char const *,int,TraceLevel,unsigned short const *,CListBase<0> *,CListElement *);
void ComTraceMessageT<CMachineGlobalObjectTable *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,CMachineGlobalObjectTable *,long);
void ComTraceMessageT<HWND__ *,unsigned int,unsigned __int64,__int64>(char const *,char const *,int,TraceLevel,unsigned short const *,HWND__ *,unsigned int,unsigned __int64,__int64);
void ComTraceMessageT<HWND__ *,unsigned int,unsigned __int64>(char const *,char const *,int,TraceLevel,unsigned short const *,HWND__ *,unsigned int,unsigned __int64);
void ComTraceMessageT<HWND__ *,unsigned long,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,HWND__ *,unsigned long,unsigned long);
void ComTraceMessageT<OXIDEntry *,_GUID *,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,OXIDEntry *,_GUID *,unsigned long);
void ComTraceMessageT<_GUID *,_GUID *,unsigned long,long>(char const *,char const *,int,TraceLevel,unsigned short const *,_GUID *,_GUID *,unsigned long,long);
void ComTraceMessageT<_GUID *,_GUID *>(char const *,char const *,int,TraceLevel,unsigned short const *,_GUID *,_GUID *);
void ComTraceMessageT<_GUID *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,_GUID *,long);
void ComTraceMessageT<_GUID *,unsigned long,unsigned __int64,long>(char const *,char const *,int,TraceLevel,unsigned short const *,_GUID *,unsigned long,unsigned __int64,long);
void ComTraceMessageT<_GUID *,unsigned long,unsigned long,unsigned short const *,unsigned short *>(char const *,char const *,int,TraceLevel,unsigned short const *,_GUID *,unsigned long,unsigned long,unsigned short const *,unsigned short *);
void ComTraceMessageT<_GUID const *,_GUID *,unsigned long,long>(char const *,char const *,int,TraceLevel,unsigned short const *,_GUID const *,_GUID *,unsigned long,long);
void ComTraceMessageT<_GUID const *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,_GUID const *,long);
void ComTraceMessageT<_GUID const *,unsigned long,unsigned short const *>(char const *,char const *,int,TraceLevel,unsigned short const *,_GUID const *,unsigned long,unsigned short const *);
void ComTraceMessageT<_GUID const *,unsigned short const *,int>(char const *,char const *,int,TraceLevel,unsigned short const *,_GUID const *,unsigned short const *,int);
void ComTraceMessageT<_GUID const *,unsigned short const *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,_GUID const *,unsigned short const *,long);
void ComTraceMessageT<_GUID const *,unsigned short,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,_GUID const *,unsigned short,unsigned long);
void ComTraceMessageT<int,long>(char const *,char const *,int,TraceLevel,unsigned short const *,int,long);
void ComTraceMessageT<long,long>(char const *,char const *,int,TraceLevel,unsigned short const *,long,long);
void ComTraceMessageT<long,unsigned short const *>(char const *,char const *,int,TraceLevel,unsigned short const *,long,unsigned short const *);
void ComTraceMessageT<long>(char const *,char const *,int,TraceLevel,unsigned short const *,long);
void ComTraceMessageT<unsigned __int64,_GUID *,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned __int64,_GUID *,unsigned long);
void ComTraceMessageT<unsigned __int64,_GUID *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned __int64,_GUID *);
void ComTraceMessageT<unsigned __int64,_GUID const *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned __int64,_GUID const *,long);
void ComTraceMessageT<unsigned __int64,_GUID const *,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned __int64,_GUID const *,unsigned long);
void ComTraceMessageT<unsigned __int64,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned __int64,long);
void ComTraceMessageT<unsigned __int64,unsigned __int64,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned __int64,unsigned __int64,long);
void ComTraceMessageT<unsigned __int64,unsigned __int64>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned __int64,unsigned __int64);
void ComTraceMessageT<unsigned __int64,unsigned long,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned __int64,unsigned long,long);
void ComTraceMessageT<unsigned __int64,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned __int64,unsigned long);
void ComTraceMessageT<unsigned __int64,unsigned short *,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned __int64,unsigned short *,unsigned short *,long);
void ComTraceMessageT<unsigned int,int,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned int,int,long);
void ComTraceMessageT<unsigned int,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned int,long);
void ComTraceMessageT<unsigned int,void * const *,int,unsigned long,bool>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned int,void * const *,int,unsigned long,bool);
void ComTraceMessageT<unsigned int,void * const *,unsigned long,int,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned int,void * const *,unsigned long,int,unsigned long);
void ComTraceMessageT<unsigned int,void * const *,unsigned long,unsigned long,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned int,void * const *,unsigned long,unsigned long,unsigned long);
void ComTraceMessageT<unsigned long,IUnknown *,_GUID const *,IAgileReference * *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,IUnknown *,_GUID const *,IAgileReference * *);
void ComTraceMessageT<unsigned long,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,long);
void ComTraceMessageT<unsigned long,unsigned long,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,unsigned long,long);
void ComTraceMessageT<unsigned long,unsigned long,unsigned __int64,unsigned __int64,_GUID *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,unsigned long,unsigned __int64,unsigned __int64,_GUID *);
void ComTraceMessageT<unsigned long,unsigned long,unsigned long,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,unsigned long,unsigned long,unsigned short *,long);
void ComTraceMessageT<unsigned long,unsigned long,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,unsigned long,unsigned short *,long);
void ComTraceMessageT<unsigned long,unsigned long,unsigned short *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,unsigned long,unsigned short *);
void ComTraceMessageT<unsigned long,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,unsigned long);
void ComTraceMessageT<unsigned long,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,unsigned short *,long);
void ComTraceMessageT<unsigned long,unsigned short *,unsigned long,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,unsigned short *,unsigned long,unsigned short *,long);
void ComTraceMessageT<unsigned long,unsigned short *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,unsigned short *);
void ComTraceMessageT<unsigned long,unsigned short const *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned long,unsigned short const *);
void ComTraceMessageT<unsigned short *,int,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,int,long);
void ComTraceMessageT<unsigned short *,int,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,int,unsigned short *,long);
void ComTraceMessageT<unsigned short *,int,unsigned short *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,int,unsigned short *);
void ComTraceMessageT<unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,long);
void ComTraceMessageT<unsigned short *,unsigned long,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned long,long);
void ComTraceMessageT<unsigned short *,unsigned long,unsigned long,int,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned long,unsigned long,int,long);
void ComTraceMessageT<unsigned short *,unsigned long,unsigned long,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned long,unsigned long,long);
void ComTraceMessageT<unsigned short *,unsigned long,unsigned long,unsigned long,unsigned long,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned long,unsigned long,unsigned long,unsigned long,long);
void ComTraceMessageT<unsigned short *,unsigned long,unsigned long,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned long,unsigned long,unsigned long);
void ComTraceMessageT<unsigned short *,unsigned long,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned long,unsigned long);
void ComTraceMessageT<unsigned short *,unsigned long,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned long,unsigned short *,long);
void ComTraceMessageT<unsigned short *,unsigned long,unsigned short *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned long,unsigned short *);
void ComTraceMessageT<unsigned short *,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned long);
void ComTraceMessageT<unsigned short *,unsigned short *,long,int>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,long,int);
void ComTraceMessageT<unsigned short *,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,long);
void ComTraceMessageT<unsigned short *,unsigned short *,unsigned long,unsigned long,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,unsigned long,unsigned long,long);
void ComTraceMessageT<unsigned short *,unsigned short *,unsigned long,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,unsigned long,unsigned long);
void ComTraceMessageT<unsigned short *,unsigned short *,unsigned long,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,unsigned long,unsigned short *,long);
void ComTraceMessageT<unsigned short *,unsigned short *,unsigned long,unsigned short *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,unsigned long,unsigned short *);
void ComTraceMessageT<unsigned short *,unsigned short *,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,unsigned short *,long);
void ComTraceMessageT<unsigned short *,unsigned short *,unsigned short *,unsigned long,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,unsigned short *,unsigned long,unsigned short *,long);
void ComTraceMessageT<unsigned short *,unsigned short *,unsigned short *,unsigned long,unsigned short *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,unsigned short *,unsigned long,unsigned short *);
void ComTraceMessageT<unsigned short *,unsigned short *,unsigned short *,unsigned short *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,unsigned short *,unsigned short *);
void ComTraceMessageT<unsigned short *,unsigned short *,unsigned short *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,unsigned short *);
void ComTraceMessageT<unsigned short *,unsigned short *,unsigned short const *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short *,unsigned short const *,long);
void ComTraceMessageT<unsigned short *,unsigned short const *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short const *,long);
void ComTraceMessageT<unsigned short *,unsigned short const *,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short const *,unsigned short *,long);
void ComTraceMessageT<unsigned short *,unsigned short const *,unsigned short const *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short const *,unsigned short const *,long);
void ComTraceMessageT<unsigned short *,unsigned short,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short *,unsigned short,long);
void ComTraceMessageT<unsigned short const *,_GUID const *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,_GUID const *,long);
void ComTraceMessageT<unsigned short const *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,long);
void ComTraceMessageT<unsigned short const *,unsigned int,unsigned int,unsigned int>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned int,unsigned int,unsigned int);
void ComTraceMessageT<unsigned short const *,unsigned int,unsigned short const *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned int,unsigned short const *);
void ComTraceMessageT<unsigned short const *,unsigned int>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned int);
void ComTraceMessageT<unsigned short const *,unsigned long,unsigned long,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned long,unsigned long,long);
void ComTraceMessageT<unsigned short const *,unsigned long,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned long,unsigned long);
void ComTraceMessageT<unsigned short const *,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned long);
void ComTraceMessageT<unsigned short const *,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short *,long);
void ComTraceMessageT<unsigned short const *,unsigned short *,unsigned int,unsigned int>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short *,unsigned int,unsigned int);
void ComTraceMessageT<unsigned short const *,unsigned short *,unsigned long,int,unsigned short *,unsigned short *,unsigned short *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short *,unsigned long,int,unsigned short *,unsigned short *,unsigned short *,long);
void ComTraceMessageT<unsigned short const *,unsigned short *,unsigned short const *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short *,unsigned short const *,long);
void ComTraceMessageT<unsigned short const *,unsigned short *,unsigned short const *,unsigned int,unsigned int>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short *,unsigned short const *,unsigned int,unsigned int);
void ComTraceMessageT<unsigned short const *,unsigned short *,unsigned short const *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short *,unsigned short const *);
void ComTraceMessageT<unsigned short const *,unsigned short *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short *);
void ComTraceMessageT<unsigned short const *,unsigned short const *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short const *,long);
void ComTraceMessageT<unsigned short const *,unsigned short const *,unsigned int,unsigned int>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short const *,unsigned int,unsigned int);
void ComTraceMessageT<unsigned short const *,unsigned short const *,unsigned long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short const *,unsigned long);
void ComTraceMessageT<unsigned short const *,unsigned short const *,unsigned short *,unsigned short const *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short *,unsigned short const *);
void ComTraceMessageT<unsigned short const *,unsigned short const *,unsigned short *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short *);
void ComTraceMessageT<unsigned short const *,unsigned short const *,unsigned short const *,long>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,long);
void ComTraceMessageT<unsigned short const *,unsigned short const *,unsigned short const *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *);
void ComTraceMessageT<unsigned short const *,unsigned short const *>(char const *,char const *,int,TraceLevel,unsigned short const *,unsigned short const *,unsigned short const *);
void ComTraceWinError(long,char const *,char const *,int,unsigned short const *,...);
void CopyToMQI(unsigned long,tagSQIResult *,tagMULTI_QI * *,unsigned long *);
void CrashProcessWithWERReport();
void DefaultSignalNAClient(CChannelObject *);
void DeliverWinrtAsyncResponseInClientApartment(IMessageParam *);
void DllHostProcessUninitialize();
void DoThreadSpecificCleanup();
void DummyCleanup(SHashChain *);
void EagerlyInitializeProcessChannel(_TP_CALLBACK_INSTANCE *,void *,_TP_WORK *);
void ExplicitMTAThreadSignalMTAClient(CChannelObject *);
void FindEntrysToShrink(unsigned long *,unsigned long *,unsigned long);
void FinishShutdown();
void FlsThreadCleanupCallback(void *);
void FormatTraceMessage(unsigned short *,unsigned __int64,unsigned short const *,char *);
void FreeExplicitWinstaDesktopString();
void FreeLibraryWithLogging(LoadOrFreeWhy,HINSTANCE__ *,unsigned short const *);
void FreeMTARundownEventIfPossible(void *);
void FreeObjRef(tagOBJREF &);
void FreeSurrogateIfNecessary();
void GUIDToString(_GUID const *,unsigned short *);
void GetCallerInfoForICallFrameEvents(CallerInfo *);
void GetCallerInfoForIRpcChannelBuffer(CallerInfo *);
void GetClassInfoFlags(ActivationPropertiesIn *,int *,int *,int *);
void GetRegistryAuthnLevel(HKEY__ *,unsigned long *);
void GetSingleThreadedHost(__int64);
void GetTemplateForwardVtbl(void * * *);
void GetTemplateVtbl(void * * *);
void HRGN_UserFree(unsigned long *,HRGN__ * *);
void HRGN_UserFree64(unsigned long *,HRGN__ * *);
void HandlePossibleBadComBaseDllLoad(HINSTANCE__ *);
void HkFindAndLoadDll();
void InitHookOle();
void InitMarshalling();
void InitializeEventDescriptors<_GUID,unsigned __int64,unsigned __int64>(_EVENT_DATA_DESCRIPTOR *,_GUID *,unsigned __int64 *,unsigned __int64 *,unsigned short const *);
void InitializeLrpcSecurity();
void InitializeTlsApartmentAndEmptyContext(COleTls &,CComApartment *,CObjectContext *);
void InitializeTracing(unsigned short const *);
void InstrumentPrematureStubRundownFailure(_GUID const &,unsigned long,_GUID const &,long);
void LogAccessFailed(void *,IUserToken *,HSTRING__ *,_GUID *,_GUID *,unsigned long,void *,int,tagEventLogModes,tagEventLogSD);
void LogApartmentInitialize();
void LogApartmentUninitialize();
void LogEventClassRegistration(long,_RegInput *,_RegOutput *);
void LogEventClassRevokation(_GUID const &,unsigned long);
void LogEventClientCall(unsigned __int64 *);
void LogEventClientReturn(unsigned __int64 *);
void LogEventDisconnect(_GUID const *,MIDEntry *,int);
void LogEventInitialize();
void LogEventMarshal(tagOBJREF &);
void LogEventStubEnter(unsigned __int64 *);
void LogEventStubException(unsigned __int64 *);
void LogEventStubLeave(unsigned __int64 *);
void LogEventUnmarshal(tagOBJREF &);
void LogInvalidSecurityDescriptor(_GUID *,unsigned long,tagEventLogSD);
void LogLoadOrFree(LoadOrFreeWhat,LoadOrFreeWhy,HINSTANCE__ *,unsigned short const *,unsigned long);
void LogMTAIssue(unsigned long,char *);
void LogWinRTActivation(HSTRING__ *);
void MTAThreadBlockForAsyncCancel(unsigned long);
void MTHostActivatorEnsureCreatedBestEffort();
void MergeFpArguments(__int64 *,__int64 *,unsigned long);
void NAUninitialize();
void NTHostActivatorEnsureCreatedBestEffort();
void Ndr64ExtInterfacePointerBufferSize(_MIDL_STUB_MESSAGE *,unsigned char *,void const *);
void Ndr64ExtInterfacePointerMarshall(_MIDL_STUB_MESSAGE *,unsigned char *,void const *);
void Ndr64ExtInterfacePointerMemorySize(_MIDL_STUB_MESSAGE *,void const *);
void Ndr64pAsyncDCOMFreeParams(_NDR_DCOM_ASYNC_MESSAGE *);
void Ndr64pCloneInOnlyCorrArgs(_NDR_DCOM_ASYNC_MESSAGE *,unsigned char const *);
void Ndr64pCloneInOutStubArgs(_NDR_DCOM_ASYNC_MESSAGE *);
void Ndr64pDcomClientExceptionHandling(_MIDL_STUB_MESSAGE *,unsigned long,long,_CLIENT_CALL_RETURN *);
void NdrCoTaskMemFree(void *);
void NdrDcomAsyncReceive(_MIDL_STUB_MESSAGE *);
void NdrExtChkSystemHandleLeak(_MIDL_STUB_MESSAGE *);
void NdrExtCleanupAllSystemHandles(_MIDL_STUB_MESSAGE *);
void NdrExtFreeInterfacePointer(unsigned char *);
void NdrExtFreeSystemHandle(_MIDL_STUB_MESSAGE *,unsigned char,void *);
void NdrExtGetCallMethod(void *,_MIDL_SERVER_INFO_ * *,long (*const * *)());
void NdrExtGetUDTFormat(_MIDL_STUB_MESSAGE *,unsigned char const *,void *);
void NdrExtInterfacePointerBufferSize(_MIDL_STUB_MESSAGE *,unsigned char *,unsigned char const *);
void NdrExtInterfacePointerMemorySize(_MIDL_STUB_MESSAGE *,unsigned char const *);
void NdrExtInterfacePointerUnmarshall(_MIDL_STUB_MESSAGE *,unsigned char * *,unsigned char const *);
void NdrExtStubGetBuffer(void *,void *,_MIDL_STUB_MESSAGE *);
void NdrExtSystemHandleMarshal(_MIDL_STUB_MESSAGE *,void *,unsigned char,unsigned long,unsigned long *);
void NdrExtSystemHandleUnmarshal(_MIDL_STUB_MESSAGE *,unsigned long,unsigned char,unsigned long,void * *);
void NdrExtpFreeBuffer(void *,_MIDL_STUB_MESSAGE *);
void NdrExtpProxyGetBuffer(void *,_MIDL_STUB_MESSAGE *);
void NdrExtpProxyInitialize(void *,_RPC_MESSAGE *,_MIDL_STUB_MESSAGE *,_MIDL_STUB_DESC const *,unsigned int);
void NdrExtpProxySendReceive(void *,_MIDL_STUB_MESSAGE *);
void NdrpAsyncDCOMFreeParams(_NDR_DCOM_ASYNC_MESSAGE *);
void NdrpCheckFirstElementForUDT(_MIDL_STUB_MESSAGE *,unsigned char const *);
void NdrpCloneInOnlyCorrArgs(_NDR_DCOM_ASYNC_MESSAGE *,unsigned char const *);
void NdrpCloneInOutStubArgs(_NDR_DCOM_ASYNC_MESSAGE *);
void NdrpDcomAsyncClientSend(_MIDL_STUB_MESSAGE *,IUnknown *,int *);
void NdrpDcomAsyncSend(_MIDL_STUB_MESSAGE *,ISynchronize *,int *);
void NdrpFreeDcomAsyncMsg(_NDR_DCOM_ASYNC_MESSAGE *);
void NdrpInitializeUDTPolicy();
void OriginateErrorForAstaCallTimeout(_GUID const &,unsigned short,unsigned long);
void OriginateErrorForStaWithReentrancyGuardTimeout(_GUID const &,unsigned short,unsigned long);
void PCAFireClassNotRegEvent(_GUID);
void PeekTillDone(HWND__ *);
void PrintFriendlyDebugMessage(_EXCEPTION_POINTERS *,void *,int,char const *);
void ProcessUninitTlsCleanup();
void ProcessUninitialize();
void RPCOrSTAThreadSignalMTAClient(CChannelObject *);
void RPCThreadSignalNAClient(CChannelObject *);
void RaiseFailFastExceptionForLeakedMgotRegstration(CMgotItem *);
void RegHelpResumeImpersonate(void *);
void RegisterThreadCleanupCallback();
void ReleaseCachedRuntimeBroker(bool);
void ReleaseMarshalingData(IStream *);
void ReleaseObjectContextReferenceInExtendedObjref(tagOBJREF &,bool);
void ReleaseTemplateForwardVtbl(void * *);
void ReleaseTemplateVtbl(void * *);
void ResumeImpersonate(void *);
void RoFailFastWithErrorContextInternal(long,unsigned long,_STOWED_EXCEPTION_INFORMATION_V1 * * const);
void RoFailFastWithErrorContextInternal2(long,unsigned long,_STOWED_EXCEPTION_INFORMATION_V2 * * const);
void RoVrfNotifyAsyncObjectMarshaledOutofproc(IUnknown *);
void RoVrfNotifyAsyncOperationClosedAfterCancel(IInspectable *);
void RoVrfNotifyAsyncOperationCompletedDelegateDuplicateSetAttempt(IInspectable *,IUnknown *);
void RoVrfNotifyAsyncOperationCompletedDelegateSetToNull(IInspectable *);
void RoVrfNotifyAsyncOperationReleasedBeforeGettingAvailableResults(IInspectable *,IUnknown *);
void RoVrfNotifyAsyncOperationReleasedBeforeSettingCompletedDelegate(IInspectable *);
void RoVrfNotifyAsyncStateMachineInClosedState(IInspectable *);
void RoVrfNotifyAsyncStateMachineNotInTerminalState(IInspectable *);
void STAHandlePostedGipRevoke(CGIPMessageParam *);
void STAHostTimerProc(HWND__ *,unsigned int,unsigned __int64,unsigned long);
void SendMessageToClassicSTAWorkItem(_TP_CALLBACK_INSTANCE *,void *,_TP_WORK *);
void SetContextFlagsForAsyncCall(unsigned long *,tagSTGMEDIUM *);
void SetObjServer(CObjServer *);
void SetThreadPointerInputBlocked(bool);
void SetWakeIfNecessary(OXIDEntry const *,void *);
void SignalClassicSTAClient(CAsyncCall *,CChannelObject *);
void SignalTheClient(CAsyncCall *);
void SilentlyReportExceptions(_EXCEPTION_POINTERS *);
void SnapshotCleanupCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *);
void TLSExplicitSetLogicalThreadId(COleTls &,_GUID const &);
void ThreadDispatch(ServerCall *);
void ThreadInvoke(_RPC_MESSAGE *);
void ThreadSignal(_RPC_ASYNC_STATE *,void *,_RPC_ASYNC_EVENT);
void TraceClientAsyncCallStart(unsigned int,unsigned long,unsigned long,_GUID const &,unsigned int,_GUID const &,_GUID const &,void *,void *,_GUID const &,unsigned __int64,_GUID const &,void *);
void TraceClientSyncCallStart(unsigned int,unsigned long,unsigned long,_GUID const &,unsigned int,_GUID const &,void *,void *,_GUID const &,unsigned __int64,_GUID const &,void *,WinrtAsyncPatternMethodIndicator);
void TraceClientSyncCallStop(unsigned int,long,SourceOfClientHResult);
void TraceServerSyncCallStop(unsigned int,long,unsigned int);
void TryToScheduleAcknowledgmentOfOutParameterMarshalingSet(OXIDEntry *,unsigned __int64,unsigned __int64);
void UnRegisterOleWndClass();
void UninitHookOle();
void UninitMTAWorker(_TP_CALLBACK_INSTANCE *,void *,_TP_WORK *);
void UninitMainThreadWnd();
void UninitializeSecurity();
void UninitializeTracing(unsigned short const *);
void UninitializedThreadBlockForAsyncCancel(unsigned long);
void UnlinkSpyNode(tagInitializeSpyNode *);
void WinrtAsyncChannelAbortPendingCalls();
void _TlgWriteActivityAutoStop<0,5>(_TlgProvider_t const *,_GUID const *);
void _TlgWriteActivityAutoStop<35184372088832,5>(_TlgProvider_t const *,_GUID const *);
void __empty_global_delete(void *,unsigned __int64);
void __global_delete(void *,unsigned __int64);
void __scrt_initialize_type_info();
void __scrt_uninitialize_type_info();
void const * ValidateAndParseExtentArray<1>(SHookList const *,WireExtentArray const *,unsigned long,unsigned long,WireExtent const * *,bool);
void operator delete(void *);
void operator delete(void *,unsigned __int64);
void operator delete[](void *);
void operator delete[](void *,unsigned __int64);
void swap(unsigned long *,unsigned long *,unsigned long,unsigned long);
void swapCache(unsigned long,unsigned long);
void wCoDecrementMTAUsage();
void wil_details_FeaturePropertyCache_ReportUsageToService(wil_details_FeaturePropertyCache *,unsigned int,FEATURE_LOGGED_TRAITS const *,int,wil_ReportingKind,unsigned __int64);
wil_StagingConfig * g_wil_details_stagingConfigForMachine;
wil_StagingConfig * g_wil_details_stagingConfigForUser;
wil_details_FeatureTestState * g_wil_details_testStates;
wil_details_RecordUsageResult wil_details_RecordUsageInPropertyCache(wil_details_FeaturePropertyCache *,wil_details_ServiceReportingKind,unsigned int,unsigned int);
