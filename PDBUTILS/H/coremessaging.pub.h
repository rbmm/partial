struct AlpcBuffer
{
	void PrepareToSend(unsigned long,unsigned short,unsigned short,unsigned long);
};

class AlpcClientConnection
{
	long CreateClientPort(_OBJECT_ATTRIBUTES *,_OBJECT_ATTRIBUTES *,_ALPC_PORT_ATTRIBUTES *,void *,bool,unsigned long,void *,void * *);
protected:
	virtual ~AlpcClientConnection();
public:
	static long ConnectToServer(AlpcConnectionConfig const *,void *,bool,unsigned long,void *,IAlpcClientConnection * *);
	virtual bool EvaluateSlurp(bool);
	virtual bool HasPendingBatches();
	virtual bool PendingPortCheck();
	virtual long Close();
	virtual long GetServerProcessID(unsigned long *);
	virtual long HandleSynchronousReply(IAlpcClientConnectionHost *,AlpcBuffer *);
	virtual long PingAndWait(void *,unsigned int,bool *);
	virtual long PostBuffers(AlpcBuffer * *,unsigned short,unsigned long,bool);
	virtual long SendBufferWithReply(IAlpcClientConnectionHost *,AlpcBuffer *,unsigned long);
	virtual long SetPendingPingResult(void *,unsigned int,bool *);
	virtual void * GetWaitHandle();
	virtual void AddRef();
	virtual void Callback_ProcessIncoming(IAlpcClientConnectionHost *,bool *);
	virtual void Release();
	void OnConnectionComplete(IAlpcClientConnectionHost *,bool,_PORT_MESSAGE *);
	void OnServerDisconnected(IAlpcClientConnectionHost *);
};

class AlpcConnection
{
	static unsigned __int64 MessageAttributesBufferSize();
	unsigned short ChunkCountForBuffer(AlpcBuffer *);
	void PostChunkedBuffer(void *,AlpcBuffer *,PendingBatch *,unsigned long,unsigned short,unsigned short,bool *);
	void PostSingleBuffer(void *,AlpcBuffer *,PendingBatch *,bool *);
protected:
	long Callback_DeliverBatchedBuffers(IAlpcConnectionHost *,PortInfo *,AlpcBuffer *);
	long Callback_HandleFirstBufferInBatch(IAlpcConnectionHost *,bool *);
	long Callback_HandleReceivedBuffer(IAlpcConnectionHost *,bool,bool *);
	long HandleSubsequentBufferInBatch(IAlpcConnectionHost *,bool *);
	long LinkChunkedBufferInBatch(AlpcBuffer *,AccumulatedBatch *);
	long NotifyBatchComplete(IAlpcConnectionHost *,PortInfo *);
	long PingAndWait(PortInfo *,void *,unsigned int,bool *);
	long PostBuffers(PortInfo *,AlpcBuffer * *,unsigned short,unsigned long,bool);
	long SetPendingPingResult(void *,unsigned int,bool *);
	long ValidateBufferHeader(AlpcBuffer *);
	static bool IsPortDisconnected(long,AlpcBufferType);
	static long SetDefaultProperties(unsigned short,void *,_OBJECT_ATTRIBUTES *,_ALPC_PORT_ATTRIBUTES *);
	static unsigned __int64 s_messageAttributesSize;
	static void * operator new(unsigned __int64);
	static void InitializeMessageAttributes(HeapBuffer<_ALPC_MESSAGE_ATTRIBUTES> *);
	virtual ~AlpcConnection();
	void Callback_ProcessIncoming(IAlpcConnectionHost *,bool *);
	void CleanupAccumulatedBatch(AccumulatedBatch *,AccumulatedBatch *,bool);
	void ConfigureForSend(unsigned long,_ALPC_MESSAGE_ATTRIBUTES *,unsigned long *,_LARGE_INTEGER * *);
	void DoReply(_PORT_MESSAGE *,_ALPC_MESSAGE_ATTRIBUTES *,_PORT_MESSAGE *,bool,unsigned short);
	void HandlePingRequest(PortInfo *,bool);
	void InitializeFromSettings(AlpcConnectionConfig const *);
public:
	long Close();
	void Release();
};

class AlpcServerConnection
{
	long GetClientToken(void * *);
	void CleanupConnectedClient(PortInfo *,bool);
	void HandleIncomingConnection(IAlpcServerConnectionHost *,_PORT_MESSAGE *);
public:
	static long CreateServer(AlpcConnectionConfig const *,IAlpcServerConnection * *);
	virtual bool EvaluateSlurp(bool);
	virtual bool HasPendingBatches(void *);
	virtual bool PendingPortCheck();
	virtual long Close();
	virtual long DisconnectClient(IAlpcServerConnectionHost *,unsigned long);
	virtual long DisconnectClient(IAlpcServerConnectionHost *,void *);
	virtual long DoCapabilityCheck(wchar_t const *,bool *);
	virtual long PingClientAndWait(void *,void *,unsigned int,bool *);
	virtual long PostBuffersToClient(void *,AlpcBuffer * *,unsigned short,unsigned long,bool);
	virtual long QuerySessionID(unsigned int &);
	virtual long SetPendingPingResult(void *,unsigned int,bool *);
	virtual void * GetWaitHandle();
	virtual void AddRef();
	virtual void Callback_ProcessIncoming(IAlpcServerConnectionHost *,bool *);
	virtual void PostSynchronousCallResponse(AlpcBuffer *);
	virtual void Release();
	void OnClientDisconnected(IAlpcServerConnectionHost *,PortInfo *);
};

struct AssembledChunk
{
	long AddChunkComponent(ChunkComponent *);
	long ChunkPayload(void * *);
	long GetPortMessageForReply(unsigned short,_PORT_MESSAGE * *,_ALPC_MESSAGE_ATTRIBUTES * *);
	static long AddMessageHeaderSize(unsigned short,unsigned __int64,unsigned __int64 *);
	static long Initialize(ChunkComponent *,unsigned __int64,AssembledChunk * *);
};

struct AutoStubBias<Windows::Foundation::IAsyncAction,Windows::Foundation::IAsyncActionCompletedHandler>
{
	~AutoStubBias<Windows::Foundation::IAsyncAction,Windows::Foundation::IAsyncActionCompletedHandler>();
};

namespace Cn
{
	namespace Com
	{
		struct CallbackAdapter
		{
			static CallbackAdapter * CreateAndPassOwnership(Context *,IUnknown * *,TypeDefinition const *);
			virtual bool Equals(System::Object *);
			virtual int GetHashCode();
			virtual void Finalize();
			void InternalDisconnect(Context *);
		};

		struct CallbackAdapter$R
		{
			static MethodDefinition const * const s_rgMethodEntries;
			static TypeDefinition_82 const s_defType;
			static unsigned short const * const s_rgParameterEntries;
			static void InitializeCppInstance(void *);
			static void Reflection__Equals(void *,void * *,void * *);
			static void Reflection__Finalize(void *,void * *,void * *);
			static void Reflection__GetHashCode(void *,void * *,void * *);
			static void Reflection__SuppressOrphanAtShutdown(void *,void * *,void * *);
			static void Reflection___Construct(void *,void * *,void * *);
		};

		class DeferredRelease
		{
			static unsigned int s_tlsStorage;
			static void NoContext_CommonCreate(IUnknown *,void (*)(),DeferredRelease::DeferredAction);
		public:
			static void Callback_ProcessItems();
			static void NoContext_Callback_ProcessItems();
			static void NoContext_CreateAndPassOwnership(IUnknown * *);
		};

		class ExportAdapter
		{
			static ExportAdapter * Create(Context *,System::Object *,Engine::GCHandleGlobalEntry *,TypeDefinition const *);
			static Guid const s_IID_ExportAdapter;
			static void volatile * volatile s_pfnQueryInterface;
			void Destroy();
		public:
			static ExportAdapter * NoContext_EnterUsageBlock(IUnknown *);
			static ExportAdapter * ToExport(Context *,System::Object *,TypeDefinition const *,void * *);
			static System::Object * ValidateAndPassOwnership(Context *,IUnknown * *,TypeDefinition const *);
			static System::Object * ValidateExport(Context *,IUnknown *,ExportAdapter *,TypeDefinition const *);
			static void NoContext_ExitUsageBlock(ExportAdapter * *,int);
			static void ValidateOut(void * *);
			virtual long QueryInterface(IID const *,void * *);
			virtual unsigned int AddRef();
			virtual unsigned int Release();
			void OrphanChain(System::Object *);
		};

		struct NativeEntry
		{
			bool NoContext_Prologue(Engine::GCHandleGlobalEntry *,void *);
			bool NoContext_Prologue(NativeEntry::Flags,void *,Context *);
			static long UnhandledExceptionWorker(System::Exception *);
			void Exit();
		};

		struct NativeExit
		{
			void NoContext_EndCall();
			void Prologue(Context *);
			void Validate(IUnknown *,int);
			void Validate(void const *);
		};

	};

	struct ComPtr<Context>
	{
		~ComPtr<Context>();
	};

	struct ComPtr<Engine::Event>
	{
		~ComPtr<Engine::Event>();
	};

	struct ComPtr<Engine::Lock>
	{
		~ComPtr<Engine::Lock>();
	};

	struct ComPtr<Microsoft::CoreUI::Identity::IdentityGroupManager>
	{
		~ComPtr<Microsoft::CoreUI::Identity::IdentityGroupManager>();
	};

	struct ComPtr<Microsoft::CoreUI::Registrar::EndpointEntry>
	{
		~ComPtr<Microsoft::CoreUI::Registrar::EndpointEntry>();
	};

	class ComPtr<Microsoft::CoreUI::Registrar::RegisteredObjectList::ListEntry>
	{
	protected:
		Microsoft::CoreUI::Registrar::RegisteredObjectList::ListEntry * Assign(Microsoft::CoreUI::Registrar::RegisteredObjectList::ListEntry *);
	public:
		~ComPtr<Microsoft::CoreUI::Registrar::RegisteredObjectList::ListEntry>();
	};

	struct ComPtr<Microsoft::CoreUI::Registrar::RegisteredObjectList>
	{
		~ComPtr<Microsoft::CoreUI::Registrar::RegisteredObjectList>();
	};

	class ComPtr<Threading::InterconnectQueue>
	{
	protected:
		Threading::InterconnectQueue * Assign(Threading::InterconnectQueue *);
	public:
		~ComPtr<Threading::InterconnectQueue>();
	};

	class Context
	{
		static ComPtr<Engine::Lock> s_lockType;
		static Context * Allocate();
		static Context * InitializeContext(bool,bool);
		static Context * s_pctxHead;
		static Context volatile * volatile s_pctxDefault;
		static bool s_fEverCreated;
		static int s_cNextAuxAvailable;
		static long s_cContexts;
		static long s_idNextContext;
		static unsigned int s_tlsStorage;
		static void * s_hSharedHeap;
		static void AddContextNL(Context *);
		static void SetCurrentContext(Context *);
		virtual void NotifyDestroy();
		void CreateStage1(bool);
		void CreateStage2(bool);
		void Dispose();
		void FreeThreadParameter();
	public:
		System::String * * GetEnumNameCacheForType(TypeExtra_Enum const *);
		static Context * NoContext_GetThreadContextOrNullAndLock();
		static int AuxAllocateNL();
		static void UninitializeContext(Context *);
		static void UninitializeType(Process::ShutdownKind);
		void Callback_AdapterShutdown(bool);
		void FreeEnumNameCacheForType(TypeExtra_Enum const *);
		void NotifyCallout(bool,void * *);
		void NotifyUnhandledExternalExceptionNL(_EXCEPTION_POINTERS const *);
	};

	struct DeletePtr<Microsoft::CoreUI::Identity::IdentityGroup>
	{
		~DeletePtr<Microsoft::CoreUI::Identity::IdentityGroup>();
	};

	class DllName
	{
		static DllName * s_pFirst;
		void Load();
	public:
		void Import(char const *,void * *);
	};

	namespace Engine
	{
		struct Direct
		{
			static unsigned int CurrentProcessId;
		};

		class Event
		{
			static void Create(bool,Event * *);
			static void PoolCreateAutomatic(ProcessItem * *);
			static void PoolCreateManual(ProcessItem * *);
		public:
			static InstancePool<Event> AutomaticPool;
			static InstancePool<Event> ManualPool;
			virtual ~Event();
		};

		class GCHandleTable
		{
			GCHandleGlobalEntry * GlobalGetEntry(GCHandleEntryID);
			static GCHandleTable::GlobalGroup * * s_rgpGlobalGroups;
			static Lock * s_pGlobalLock;
			static int s_cUsedGlobalGroups;
			static int s_idxFreeGlobalSlot;
			static void GroupFindWithFreeSpace(GCHandleTable::Group * *,int,int *,GCHandleTable::Group * *);
			static void GroupInitialize(GCHandleTable::Group *,int,int);
			void GlobalAllocateGroup();
			void GlobalFreeEntry(GCHandleEntryID);
			void LocalAllocateGroup();
			void LocalValidateValue(unsigned int,GCHandleLocalEntry * *,GCHandleEntryID *);
			void StorageAddGroup(GCHandleTable::Group * * *,int *,bool,GCHandleTable::Group *);
		public:
			unsigned int LocalHandleAllocate(System::Object *,GCHandleEntryID);
			void Destroy();
			void GlobalHandlesShutdown();
			void LocalHandleFree(unsigned int);
			void NotifyObjectDelete(System::Object *);
		};

		class GlobalVectorF<Microsoft::CoreUI::Dispatch::WatchdogEntry>
		{
		protected:
			void Resize(int);
		public:
			void RemoveAll();
		};

		class GlobalVectorF<Microsoft::CoreUI::Registrar::ConnectionMapping>
		{
		protected:
			void Resize(int);
		public:
			void RemoveAll();
		};

		class GlobalVectorF<PortInfo *>
		{
		protected:
			void Resize(int);
		public:
			void RemoveAll();
			void RemoveAt(int);
		};

		class GlobalVectorF<Threading::InterconnectQueue *>
		{
		protected:
			void Resize(int);
		public:
			void RemoveAll();
		};

		class GlobalVectorF<int>
		{
		protected:
			void Resize(int);
		};

		class GlobalVectorF<unsigned int>
		{
		protected:
			void Resize(int);
		public:
			int Find(unsigned int const &);
			void RemoveAll();
		};

		class GlobalVectorF<unsigned short>
		{
		protected:
			void Resize(int);
		};

		class Heap
		{
			class ObjectSet
			{
				void Grow();
			public:
				void CollectWorker(int,HeapEntry *,char const *,bool);
				void Destroy();
			};

			static void * _AlignedAllocate(AllocType,unsigned __int64,unsigned __int64,unsigned __int64,bool);
			static void * _ProcessAllocate(AllocType,unsigned __int64,bool,bool);
			void * _AllocateMisc(AllocType,unsigned __int64,bool);
			void _EvaluateAndCollect(bool,Heap::HeapEntry *,Heap::HeapEntry *,int,char const *,bool);
			void _FullCollect();
		public:
			static void * ProcessReallocate(AllocType,void *,unsigned __int64);
			static void NoContext_ProcessFree(void *);
			void * AllocateObject(unsigned __int64);
			void * AllocateObjectNoZero(unsigned __int64);
			void FreeMisc(void *);
			void Leave(Heap::HeapEntry *,bool,bool);
			void NotifyCollectable(System::Object *);
		};

		struct InstancePool<Event>
		{
			~InstancePool<Event>();
		};

		struct InstancePoolBase
		{
			void Dispose();
		};

		struct LocaleData
		{
			unsigned int GetNLSGrouping();
			void LoadNumberFormat();
		};

		class Lock
		{
			static bool * s_fInitialized;
			static void Create(LockPriority,bool,Lock * *);
			void CreateResource();
		public:
			virtual ~Lock();
			void Dispose();
			void Leave();
		};

		class Number
		{
			static Number::ParseState ParseIntegralWorker(System::String *,System::Globalization::NumberStyles,System::IFormatProvider *,bool,bool,unsigned __int64,unsigned __int64,unsigned __int64 *,bool *);
		public:
			static Number::ParseState ParseI32(System::String *,System::Globalization::NumberStyles,System::IFormatProvider *,bool,int *);
		};

		class ProcessItem
		{
		protected:
			virtual void NotifyDestroy();
			virtual ~ProcessItem();
		public:
			void Release();
		};

		struct ReferenceIterator
		{
			ReferenceIterator(System::Object *,bool);
			ReferenceIterator(void *,TypeDefinition const *,bool,int);
			bool MoveNext();
		};

		class StackMemory
		{
			void * AllocateImpl(unsigned __int64,bool);
			void FreeHeap();
		public:
			~StackMemory();
		};

		struct UsingLock
		{
			UsingLock(Lock *);
			~UsingLock();
		};

		struct VectorF<unsigned int>
		{
			~VectorF<unsigned int>();
		};

		_numberfmtW * GetCurrentWin32NumberFormat();
	};

	struct FailFast
	{
		static int SehToFailFastFilter(_EXCEPTION_POINTERS const *,bool,Context *);
		static void Do(_EXCEPTION_RECORD *);
		static void Do(_EXCEPTION_RECORD *,_CONTEXT *);
		static void ForHR(int,void const *);
		static void ForHR(int,void const *,int);
		static void ForNtStatus(long);
		static void ForWin32();
		static void IndexOutOfRange();
		static void InvalidArgument();
		static void InvalidOperation();
		static void OutOfMemory();
		static void Unexpected();
	};

	struct IExportInstance
	{
		void OnFinalRelease(bool);
	};

	struct IExportInstance$R
	{
		static TypeDefinition_66 const s_defType;
		static void const * const * const s_rgLookup;
	};

	struct InsufficientResourcesException$R
	{
		static TypeDefinition_65 const s_defType;
		static void InitializeCppInstance(void *);
	};

	class ObjectRef<Map>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__Entry_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__Microsoft_CoreUI_Messaging_ConnectedClient__object>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__Microsoft_CoreUI_Messaging_ConnectedClient__object__Entry_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__Microsoft_CoreUI_Messaging_ConnectionID__Microsoft_CoreUI_Messaging_Connection>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__Microsoft_CoreUI_Messaging_ConnectionID__Microsoft_CoreUI_Messaging_Connection__Entry_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait__Entry_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort__Entry_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort__Entry_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__System_Guid__object>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__System_Guid__object__Entry_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__System_IntPtr__object>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__System_IntPtr__object__Entry_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__uint__object>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__uint__object__Entry_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__uint__uint>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Map__uint__uint__Entry_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::BufferAllocationPolicy>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::BufferHeapBlock>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::BufferManager>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::BufferMemoryRange>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::BufferPolicyEntry_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::BufferSet>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::BufferStream>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::IBufferAllocator>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::LargeBlockAllocator>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::ProcessHeapAllocator>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::SharedPoolAllocator>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::SmallBlockAllocator>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Buffering::SmallBlockAllocator__GroupDescriptor_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::CoalescerHandler>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::ConversationItemEnumProc>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Conversations::Conversation>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Conversations::ConversationControlEndpoint>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Conversations::ConversationPeer>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Conversations::EndpointStuff>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Conversations::IDLRUAllocator>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Conversations::ItemMessageDispatcher>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Conversations::ItemTable>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::DesignPatterns::ChainLink_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::DesignPatterns::TimerCoalescer>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::DeferredCall>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::DeferredCallDispatcher>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::DeferredCall__DeferredCallCache>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::DispatchCallback>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::DispatchItem>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::DispatchWatchdogCallback>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::Dispatcher>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::EventLoop>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::OffThreadReceiver>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::OffThreadSource>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::RegisteredWait>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::ThreadContext>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::ThreadContext__Error>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::Timeout>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::TimeoutHandler>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::TimeoutManager>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::UserAdapter>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::WaitArray>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::WaitCallback>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::WaitController>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::WakeRecord>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Dispatch::WakeRecordHandler>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::DispatchGroupBatchEnableHandler>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::DispatchGroupHandler>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::ExportEndpointHandler>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::ICallbackMessageConversationHost>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::IExportClientWindowIDManager>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::IExportMessageConversation>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::IExportMessageGroup>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::IExportMessageInfo>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::IExportMessageLoopExtensions>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::IExportMessagePort>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::IExportMessageRegistrar>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::IExportMessageSessionPrivate>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::IExportMessageTimer>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::IExportMessageTimerCoalescer>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::IExportSystemWindowIDManager>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Identity::IdentityTableView>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Identity::IdentityTableView__EnumerateHandlesCallback>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::AlpcClientState>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::AlpcSendMessageAdapter>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::Connection>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::Connection_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::CrossProcessReceivePort>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::CrossProcessReceivePortBase>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::CrossProcessReceivePort__AlpcReceiveSource>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::DeferredMessagePool>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::InterconnectMessageAdapter>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::LocalMessageAdapter>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::LocalMessageAdapter__LocalDispatchItem>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::LocalMessageEnumerator>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::LocalMessageEnumerator_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::MessageAdapter>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::MessageBatchFlusher_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::MessageEndpoint>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::MessageEndpoint__MessageHandler>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::MessageInfo>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::MessageSession>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::MessageSessionPrivateWrapper>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::MessageStream>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::MessageStream_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Messaging::ReverseConnectionReceivePort>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::AlpcClientAdapter>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::AlpcServerAdapter>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::ClientWindowIDManager>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::CuiRegistrar>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::GetWindowIDPropertiesResponse>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::IAlpcClientHost>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::IAlpcServerHost>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RegisteredConversation>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RegistrarClient>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RegistrarClient__OnPendingConnectionTerminationHandler>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RegistrarData>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RegistrarDiagnostics>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RegistrarProcessContext>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RegistrarSessionContext>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RegistrarThreadContext>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RegistrationNameMaps>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RegistrationNameMaps__Ticket_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RemoteRegistrarClient>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::RemoteRegistrarServer>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::SystemWindowIDManager>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::SystemWindowIDManager_Client>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::SystemWindowIDManager_Server>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Registrar::WindowIDManager>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Resources::ResourceTracker>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Services::ExternalThreadEndpoint>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Services::ThreadEndpoint>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Support::DoubleListItem>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Support::DoubleListItem__Chain>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Support::DoubleListItem__FIFO>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Support::DoubleListItem__FIFO_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Support::SkipList>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Support::SystemTime>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Support::Win32Handle_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::Threading::InterconnectReceiver>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::WindowIDPropertyValue_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<Microsoft::CoreUI::WindowIDPropertyValue_1D_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Action>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Action__Microsoft_CoreUI_Support_BufferInfo>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Action__bool>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Action__object>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Action__object__bool>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Action__uint>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Action__uint__uint>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Array>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Byte_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Collections::ArrayList>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Collections::Generic::List__Microsoft_CoreUI_DesignPatterns_ChainLink>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Collections::Generic::List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Collections::Generic::List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Collections::IComparer>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Collections::Queue>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Collections::Stack>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Delegate>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Delegate_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Diagnostics::Process>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::EventArgs>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Exception>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Globalization::CultureInfo>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Globalization::NumberFormatInfo>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Int32_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Object>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Object_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Random>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Reflection::Assembly>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Reflection::MethodInfo>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Reflection::ParameterInfo_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::String>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Text::Encoding>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Threading::Thread>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ObjectRef<System::Type_1D>
	{
	protected:
		System::Object * AssignWorker(System::Object *);
	};

	class ParamRef<System::Object_1D>
	{
		System::Object_1D * AssignWorker(System::Object *);
	};

	class Process
	{
		static Process::ModuleData * s_pModuleData;
		static int s_cModules;
	public:
		static ICnHost * Host;
		static IConsoleLogger * ConsoleLogger;
		static bool FailFastDebug;
		static bool UsePerContextHeap;
		static int HeapSetGrowthLargeRate;
		static int HeapSetGrowthSmallRate;
		static int HeapSetInitialSize;
		static int ModuleRegister(int);
		static void (* InitModule)(bool);
		static void (* OutOfMemoryHandler)(unsigned __int64);
		static void (* UninitModule)(bool);
		static void * DllInstance;
		static void Initialize(int,int);
		static void NotifyCallbackError(int,void const *);
		static void NotifyOutOfMemory(unsigned __int64);
		static void OnPreDllMain(void *,unsigned long);
		static void Uninitialize(Process::ShutdownKind);
	};

	struct StrongRef<Map>
	{
		~StrongRef<Map>();
	};

	struct StrongRef<Map__Microsoft_CoreUI_Messaging_ConnectedClient__object>
	{
		~StrongRef<Map__Microsoft_CoreUI_Messaging_ConnectedClient__object>();
	};

	struct StrongRef<Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait>
	{
		~StrongRef<Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait>();
	};

	struct StrongRef<Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort>
	{
		~StrongRef<Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort>();
	};

	struct StrongRef<Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort>
	{
		~StrongRef<Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort>();
	};

	struct StrongRef<Map__uint__object>
	{
		~StrongRef<Map__uint__object>();
	};

	struct StrongRef<Microsoft::CoreUI::Buffering::BufferSet>
	{
		~StrongRef<Microsoft::CoreUI::Buffering::BufferSet>();
	};

	struct StrongRef<Microsoft::CoreUI::CoalescerHandler>
	{
		~StrongRef<Microsoft::CoreUI::CoalescerHandler>();
	};

	struct StrongRef<Microsoft::CoreUI::ConversationItemEnumProc>
	{
		~StrongRef<Microsoft::CoreUI::ConversationItemEnumProc>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::DispatchCallback>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::DispatchCallback>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::DispatchItem>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::DispatchItem>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::DispatchWatchdogCallback>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::DispatchWatchdogCallback>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::Dispatcher>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::Dispatcher>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::EventLoop>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::EventLoop>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::OffThreadReceiver>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::OffThreadReceiver>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::OffThreadSource>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::OffThreadSource>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::TimeoutHandler>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::TimeoutHandler>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::UserAdapter>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::UserAdapter>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::WaitCallback>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::WaitCallback>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::WaitController>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::WaitController>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::WakeRecord>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::WakeRecord>();
	};

	struct StrongRef<Microsoft::CoreUI::Dispatch::WakeRecordHandler>
	{
		~StrongRef<Microsoft::CoreUI::Dispatch::WakeRecordHandler>();
	};

	struct StrongRef<Microsoft::CoreUI::DispatchGroupBatchEnableHandler>
	{
		~StrongRef<Microsoft::CoreUI::DispatchGroupBatchEnableHandler>();
	};

	struct StrongRef<Microsoft::CoreUI::DispatchGroupHandler>
	{
		~StrongRef<Microsoft::CoreUI::DispatchGroupHandler>();
	};

	struct StrongRef<Microsoft::CoreUI::ExportEndpointHandler>
	{
		~StrongRef<Microsoft::CoreUI::ExportEndpointHandler>();
	};

	struct StrongRef<Microsoft::CoreUI::ICallbackMessageConversationHost>
	{
		~StrongRef<Microsoft::CoreUI::ICallbackMessageConversationHost>();
	};

	struct StrongRef<Microsoft::CoreUI::ICallbackMessageSessionListener>
	{
		~StrongRef<Microsoft::CoreUI::ICallbackMessageSessionListener>();
	};

	struct StrongRef<Microsoft::CoreUI::IExportClientWindowIDManager>
	{
		~StrongRef<Microsoft::CoreUI::IExportClientWindowIDManager>();
	};

	struct StrongRef<Microsoft::CoreUI::IExportMessageConversation>
	{
		~StrongRef<Microsoft::CoreUI::IExportMessageConversation>();
	};

	struct StrongRef<Microsoft::CoreUI::IExportMessageGroup>
	{
		~StrongRef<Microsoft::CoreUI::IExportMessageGroup>();
	};

	struct StrongRef<Microsoft::CoreUI::IExportMessageInfo>
	{
		~StrongRef<Microsoft::CoreUI::IExportMessageInfo>();
	};

	struct StrongRef<Microsoft::CoreUI::IExportMessageLoopExtensions>
	{
		~StrongRef<Microsoft::CoreUI::IExportMessageLoopExtensions>();
	};

	struct StrongRef<Microsoft::CoreUI::IExportMessagePort>
	{
		~StrongRef<Microsoft::CoreUI::IExportMessagePort>();
	};

	struct StrongRef<Microsoft::CoreUI::IExportMessageRegistrar>
	{
		~StrongRef<Microsoft::CoreUI::IExportMessageRegistrar>();
	};

	struct StrongRef<Microsoft::CoreUI::IExportMessageSessionPrivate>
	{
		~StrongRef<Microsoft::CoreUI::IExportMessageSessionPrivate>();
	};

	struct StrongRef<Microsoft::CoreUI::IExportMessageTimer>
	{
		~StrongRef<Microsoft::CoreUI::IExportMessageTimer>();
	};

	struct StrongRef<Microsoft::CoreUI::IExportMessageTimerCoalescer>
	{
		~StrongRef<Microsoft::CoreUI::IExportMessageTimerCoalescer>();
	};

	struct StrongRef<Microsoft::CoreUI::IExportSystemWindowIDManager>
	{
		~StrongRef<Microsoft::CoreUI::IExportSystemWindowIDManager>();
	};

	struct StrongRef<Microsoft::CoreUI::Messaging::AlpcClientSender>
	{
		~StrongRef<Microsoft::CoreUI::Messaging::AlpcClientSender>();
	};

	struct StrongRef<Microsoft::CoreUI::Messaging::AlpcClientState>
	{
		~StrongRef<Microsoft::CoreUI::Messaging::AlpcClientState>();
	};

	struct StrongRef<Microsoft::CoreUI::Messaging::CrossProcessReceivePortBase>
	{
		~StrongRef<Microsoft::CoreUI::Messaging::CrossProcessReceivePortBase>();
	};

	struct StrongRef<Microsoft::CoreUI::Messaging::CrossProcessReceivePort__AlpcReceiveSource>
	{
		~StrongRef<Microsoft::CoreUI::Messaging::CrossProcessReceivePort__AlpcReceiveSource>();
	};

	struct StrongRef<Microsoft::CoreUI::Messaging::DeferredMessagePool>
	{
		~StrongRef<Microsoft::CoreUI::Messaging::DeferredMessagePool>();
	};

	struct StrongRef<Microsoft::CoreUI::Messaging::InterconnectMessageAdapter>
	{
		~StrongRef<Microsoft::CoreUI::Messaging::InterconnectMessageAdapter>();
	};

	struct StrongRef<Microsoft::CoreUI::Messaging::LocalMessageAdapter>
	{
		~StrongRef<Microsoft::CoreUI::Messaging::LocalMessageAdapter>();
	};

	struct StrongRef<Microsoft::CoreUI::Messaging::LocalMessageAdapter__LocalDispatchItem>
	{
		~StrongRef<Microsoft::CoreUI::Messaging::LocalMessageAdapter__LocalDispatchItem>();
	};

	struct StrongRef<Microsoft::CoreUI::Messaging::LocalMessageEnumerator>
	{
		~StrongRef<Microsoft::CoreUI::Messaging::LocalMessageEnumerator>();
	};

	struct StrongRef<Microsoft::CoreUI::Messaging::MessageEndpoint>
	{
		~StrongRef<Microsoft::CoreUI::Messaging::MessageEndpoint>();
	};

	struct StrongRef<Microsoft::CoreUI::Messaging::MessageSession>
	{
		~StrongRef<Microsoft::CoreUI::Messaging::MessageSession>();
	};

	struct StrongRef<Microsoft::CoreUI::Registrar::CuiRegistrar>
	{
		~StrongRef<Microsoft::CoreUI::Registrar::CuiRegistrar>();
	};

	struct StrongRef<Microsoft::CoreUI::Registrar::RegistrationNameMaps>
	{
		~StrongRef<Microsoft::CoreUI::Registrar::RegistrationNameMaps>();
	};

	struct StrongRef<Microsoft::CoreUI::Support::SkipList>
	{
		~StrongRef<Microsoft::CoreUI::Support::SkipList>();
	};

	struct StrongRef<Microsoft::CoreUI::ValidationException>
	{
		~StrongRef<Microsoft::CoreUI::ValidationException>();
	};

	struct StrongRef<Microsoft::CoreUI::WindowIDPropertyValue_1D_1D>
	{
		~StrongRef<Microsoft::CoreUI::WindowIDPropertyValue_1D_1D>();
	};

	struct StrongRef<System::Action>
	{
		~StrongRef<System::Action>();
	};

	struct StrongRef<System::Array>
	{
		~StrongRef<System::Array>();
	};

	struct StrongRef<System::Collections::Generic::List__Microsoft_CoreUI_DesignPatterns_ChainLink>
	{
		~StrongRef<System::Collections::Generic::List__Microsoft_CoreUI_DesignPatterns_ChainLink>();
	};

	struct StrongRef<System::Collections::Generic::List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket>
	{
		~StrongRef<System::Collections::Generic::List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket>();
	};

	struct StrongRef<System::Object>
	{
		~StrongRef<System::Object>();
	};

	struct StrongRef<System::String>
	{
		~StrongRef<System::String>();
	};

	namespace Threading
	{
		struct IInterconnectBufferHandler$R
		{
			static TypeDefinition_66 const s_defType;
		};

		class InterconnectQueue
		{
			static Engine::GlobalVectorF<InterconnectQueue *> s_arKeyToQueue;
			static GlobalComPtr<InterconnectQueue> s_pqueueVisible;
			static InterconnectQueue * s_pqueueAll;
			static SlimLock s_lockType;
			static _SLIST_HEADER s_poolLookaside;
			static void * AllocateNoZero(int);
			static void ChangeEnabled(InterconnectQueue *,UsingExclusiveLock *,bool);
			static void Create(InterconnectQueue * *);
			static void Free(void *,int);
			static void FreeEntries(InterconnectQueue::QueueEntry *);
			static void PostReplyNL(InterconnectQueue *,unsigned int,unsigned int,unsigned int);
			void Dispose();
			void DrainInterconnect();
		public:
			InterconnectQueue();
			bool Callback_ProcessNextItem(IInterconnectBufferHandler *,DrainMode);
			bool CheckForItems(DrainMode);
			static bool PostItem_LockedByCaller(InterconnectQueue *,unsigned int,InterconnectItem *,int,unsigned int,unsigned int,unsigned int,InterconnectBufferFlags,InterconnectBufferFlags *);
			static void AddUserKey(Context *,unsigned int);
			static void Disable(Context *);
			static void Enable(Context *);
			static void FindByKeyNL(unsigned int,InterconnectQueue * *,UsingSharedLock *);
			static void FindByThreadNL(unsigned int,InterconnectQueue * *,void * *,unsigned int *);
			static void InitializeClass(bool);
			static void RemoveUserKey(unsigned int);
			virtual ~InterconnectQueue();
		};

		struct UsingExclusiveLock
		{
			~UsingExclusiveLock();
		};

		struct UsingSharedLock
		{
			~UsingSharedLock();
		};

	};

	class Throw
	{
		static Throw::Pair const * FindPair(int);
		static Throw::Pair const * const s_rgPairs;
	public:
		static bool FilterException2(XH,TypeDefinition const *);
		static bool IsHROutOfMemory(int);
		static int HRForWin32(unsigned long *);
		static void ArgumentException();
		static void ArgumentNullException();
		static void ArgumentOutOfRangeException();
		static void COMException(int);
		static void DivideByZeroException();
		static void DllNotFoundException(System::String *);
		static void EntryPointNotFoundException(System::String *,System::String *);
		static void ExceptionForHR(int);
		static void FormatException(wchar_t const *);
		static void IndexOutOfRangeException();
		static void InvalidCastException();
		static void InvalidOperationException(wchar_t const *);
		static void NotSupportedException();
		static void Now(System::Exception *);
		static void Now(System::Exception *,char const *,unsigned int);
		static void Now(System::Exception *,char const *,unsigned int,void *);
		static void NullReferenceException();
		static void OutOfMemoryException(unsigned __int64);
		static void OverflowException();
		static void SetWin32LastErrorForHR(int);
		static void TargetException();
		static void TypeLoadException(System::String *);
	};

	struct ToAnsi
	{
		ToAnsi(System::String *);
	};

	struct ToUnicode
	{
		ToUnicode(System::String *);
	};

	struct TypeDefinition
	{
		PredefinedTypeKind GetPredefinedType();
		void const * GetSection(TypeExtraSection);
	};

	class TypeSystem
	{
		struct TypeSet
		{
			void SingleContextDestroy_LkReq();
			void Uninitialize();
		};

		static ComPtr<Engine::Lock> s_lock;
		static TypeDataProcess * BuildNames_LkReq(TypeDefinition const *);
		static TypeDataProcess * s_rgDynamicTypeDataProcess_LkReq;
		static TypeDefinition * * s_rgpDynamicTypeDef_LkReq;
		static TypeDefinition * AllocateDynamicType_LkReq(int,TypeFlags,void (*)(void *));
		static TypeDefinition const * FindDynamicDerivativeType_LkReq(unsigned short,TypeFlags,unsigned char);
		static TypeDefinition const * FindStaticDerivativeType(unsigned short,TypeFlags,unsigned char);
		static TypeSystem::TypeSet s_setDynamicTypes;
		static TypeSystem::TypeSet s_setStaticTypes;
	public:
		static TypeDefinition const * FindType(char const *);
		static TypeDefinition const * GetDefinition(unsigned short);
		static TypeDefinition const * MakeArrayType(TypeDefinition const *,unsigned char);
		static TypeSystem::ExtraSection7 const * const ExtraLayouts0;
		static TypeSystem::ExtraSection8 const ExtraLayouts194;
		static TypeSystem::ExtraSection8 const ExtraLayouts195;
		static TypeSystem::ExtraSection8 const ExtraLayouts209;
		static TypeSystem::ExtraSection8 const ExtraLayouts210;
		static TypeSystem::ExtraSection8 const ExtraLayouts211;
		static TypeSystem::ExtraSection8 const ExtraLayouts242;
		static bool IsDescendentOf(TypeDefinition const *,TypeDefinition const *,bool);
		static char const * GetFullName(TypeDefinition const *);
		static char const * GetShortName(TypeDefinition const *);
		static void RegisterTypes(int);
		static void SingleContextDestroy();
		static void UninitializeType();
	};

	Cn::DllName g_dllOleAut32;
	Cn::ModuleDefinition const * const g_rgModules;
	Cn::TypeDataProcess * g_rgStaticTypeDataProcess_LkNone;
	Cn::TypeDefinition const * const * const g_rgpStaticTypeDef_LkNone;
	char const * const * const g_rgszNamespaces;
	int const g_cEnumNameCaches;
	unsigned int (* g_pfnSysStringLen)(wchar_t *);
	unsigned short * g_rgModulesIDs;
	void (* g_pfnSysFreeString)(wchar_t *);
	wchar_t * (* g_pfnSysAllocStringLen)(wchar_t const *,unsigned int);
};

struct CnRuntime__Statics
{
	static int s_idxContextLocal;
};

namespace CoreMessaging
{
	namespace Calling
	{
		struct FailFast
		{
			static void Error(char const *,unsigned int);
		};

		class MessageCallHostBase
		{
		protected:
			virtual long NotifyInvalid(MsgCallState *);
			virtual long NotifyProtocolViolation(MsgCallState *);
		public:
			static void * operator new(unsigned __int64);
			static void operator delete(void *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual ~MessageCallHostBase();
		};

		class MessageConversationHost
		{
			void RetireBuffer(void *);
		protected:
			virtual long AllocateBuffer(unsigned __int64 *,unsigned int,unsigned int,void * *);
			virtual long CancelBuffer(unsigned __int64 *,unsigned int,void *,unsigned int);
			virtual long SubmitBuffer(unsigned __int64 *,unsigned int,void *,unsigned int);
		};

		class MessageSessionHost
		{
		protected:
			virtual long AllocateBuffer(unsigned __int64 *,unsigned int,unsigned int,void * *);
			virtual long CancelBuffer(unsigned __int64 *,unsigned int,void *,unsigned int);
			virtual long SubmitBuffer(unsigned __int64 *,unsigned int,void *,unsigned int);
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
			long MarshalSend(void *,unsigned int,char *);
		};

	};

};

struct CoreMessaging__Statics
{
	static int s_idxContextLocal;
};

class CoreUIBaseService
{
protected:
	static unsigned long ServiceHandler(unsigned long,unsigned long,void *,void *);
	static void StopService(void *,unsigned char);
	virtual ~CoreUIBaseService();
	void InitializeServiceInternal(Microsoft::CoreUI::Registrar::ServiceRunMode,_GUID const &,unsigned long (*)(CoreUIBaseService *));
	void UpdateServiceStatus(unsigned long,unsigned long,unsigned long);
public:
	virtual void ServiceMain(unsigned long,wchar_t * * const);
	void UninitializeService();
};

struct CoreUIHost
{
	virtual void OnCallbackError(long,void const *);
	virtual void OnEnterInvalidContext();
	virtual void OnEnterUninitializedContext(long *);
	virtual void OnInvalidCallback(void const *);
	virtual void OnProcessShutdownLeak();
	virtual void OnThrowException(System::Exception *);
	virtual void OnUnhandledException(System::Exception *,long,long *);
};

class CoreUIRegistrarService
{
	static CoreUIRegistrarService * s_pCoreUIRegistrarService;
	static unsigned long RegistrarServerThread(CoreUIBaseService *);
	static wchar_t const * const s_szServiceName;
	virtual wchar_t const * GetServiceName();
protected:
	CoreUIRegistrarService();
public:
	static CoreUIRegistrarService * GetCreateInstance();
	virtual void InitializeService(Microsoft::CoreUI::Registrar::ServiceRunMode,_GUID const &);
};

struct CuiShellCore__Statics
{
	static int s_idxContextLocal;
};

struct CuiSystem__Statics
{
	static int s_idxContextLocal;
};

struct HeapBuffer<AccumulatedBatch>
{
	void Free();
	~HeapBuffer<AccumulatedBatch>();
};

struct HeapBuffer<AlpcBuffer>
{
	void Free();
	void Resize(unsigned __int64);
	~HeapBuffer<AlpcBuffer>();
};

struct HeapBuffer<AssembledChunk>
{
	void Free();
	~HeapBuffer<AssembledChunk>();
};

struct HeapBuffer<ChunkComponent>
{
	void Free();
	~HeapBuffer<ChunkComponent>();
};

struct HeapBuffer<PendingBatch>
{
	void Free();
	~HeapBuffer<PendingBatch>();
};

struct HeapBuffer<PingReply>
{
	void Free();
	~HeapBuffer<PingReply>();
};

struct HeapBuffer<PortInfo>
{
	void Free();
	~HeapBuffer<PortInfo>();
};

struct HeapBuffer<_ALPC_MESSAGE_ATTRIBUTES>
{
	void Free();
	void Resize(unsigned __int64);
	~HeapBuffer<_ALPC_MESSAGE_ATTRIBUTES>();
};

struct HeapBuffer<unsigned char>
{
	void Free();
};

class IConversationClient_MsgCallInfo
{
	static unsigned char const * * MethodInstructions;
};

struct IConversationClient_Receive<Microsoft::CoreUI::Conversations::ConversationClientReceiveThunk>
{
	static MsgCallInterfaceTableEntry const * const Interfaces;
	static MsgCallMethodDefinition const * const Methods;
	static MsgCallTypeDefinition const Type;
	static long Thunk_ConnectionAccepted_11(void *,void * *);
	static long Thunk_FreeItem_5(void *,void * *);
	static long Thunk_ItemFreed_0(void *,void * *);
	static long Thunk_PeerDisconnected_11(void *,void * *);
	static long Thunk_ReserveItem_0(void *,void * *);
};

class IConversationServer_MsgCallInfo
{
	static unsigned char const * * MethodInstructions;
};

struct IConversationServer_Receive<Microsoft::CoreUI::Conversations::ConversationServerReceiveThunk>
{
	static MsgCallInterfaceTableEntry const * const Interfaces;
	static MsgCallMethodDefinition const * const Methods;
	static MsgCallTypeDefinition const Type;
	static long Thunk_ClientConnectionRequested_14(void *,void * *);
	static long Thunk_FreeItem_5(void *,void * *);
	static long Thunk_ItemFreed_0(void *,void * *);
	static long Thunk_PeerDisconnected_11(void *,void * *);
	static long Thunk_ReserveItem_0(void *,void * *);
};

class IIDManagerClient_MsgCallInfo
{
	static unsigned char const * * MethodInstructions;
};

struct IIDManagerClient_Receive<Microsoft::CoreUI::Registrar::IDManagerClientReceiveThunk>
{
	static MsgCallInterfaceTableEntry const * const Interfaces;
	static MsgCallMethodDefinition const * const Methods;
	static MsgCallTypeDefinition const Type;
	static long Thunk_Reply_AllocateWindowID_26(void *,void * *);
	static long Thunk_Reply_FreeWindowID_11(void *,void * *);
	static long Thunk_Reply_GetWindowIDInfo_32(void *,void * *);
	static long Thunk_Reply_GetWindowIDProperties_38(void *,void * *);
};

class IIDManagerServer_MsgCallInfo
{
	static unsigned char const * * MethodInstructions;
};

struct IIDManagerServer_Receive<Microsoft::CoreUI::Registrar::IDManagerServerReceiveThunk>
{
	static MsgCallInterfaceTableEntry const * const Interfaces;
	static MsgCallMethodDefinition const * const Methods;
	static MsgCallTypeDefinition const Type;
	static long Thunk_AllocateWindowID_45(void *,void * *);
	static long Thunk_FreeWindowID_52(void *,void * *);
	static long Thunk_GetWindowIDInfo_52(void *,void * *);
	static long Thunk_GetWindowIDProperties_57(void *,void * *);
};

class IRegistrarClient_MsgCallInfo
{
	static unsigned char const * * MethodInstructions;
};

struct IRegistrarClient_Receive<Microsoft::CoreUI::Registrar::RemoteRegistrarClientReceiveThunk>
{
	static MsgCallInterfaceTableEntry const * const Interfaces;
	static MsgCallMethodDefinition const * const Methods;
	static MsgCallTypeDefinition const Type;
	static long Thunk_OnConversationServerJoined_50(void *,void * *);
	static long Thunk_OnPendingConnectionTermination_14(void *,void * *);
	static long Thunk_OnProtocolExceptionWithDiagnostics_3(void *,void * *);
	static long Thunk_OnProtocolException_0(void *,void * *);
	static long Thunk_Reply_AllocateWindowID_77(void *,void * *);
	static long Thunk_Reply_ClearWindowIDProperties_0(void *,void * *);
	static long Thunk_Reply_CloseConnection_25(void *,void * *);
	static long Thunk_Reply_CompleteCrossProcConnection_0(void *,void * *);
	static long Thunk_Reply_CompleteLocalConnection_0(void *,void * *);
	static long Thunk_Reply_ConnectPendingConversationClient_0(void *,void * *);
	static long Thunk_Reply_CrossProcClientDisconnected_25(void *,void * *);
	static long Thunk_Reply_FindCrossProcConnection_45(void *,void * *);
	static long Thunk_Reply_FindMessageObject_34(void *,void * *);
	static long Thunk_Reply_FindObject_27(void *,void * *);
	static long Thunk_Reply_FindPendingConversationClient_68(void *,void * *);
	static long Thunk_Reply_FreeWindowID_0(void *,void * *);
	static long Thunk_Reply_GetOrCreateReverseConnectionPortID_40(void *,void * *);
	static long Thunk_Reply_GetWindowIDInfo_83(void *,void * *);
	static long Thunk_Reply_GetWindowIDProperties_89(void *,void * *);
	static long Thunk_Reply_LocalClientDisconnected_25(void *,void * *);
	static long Thunk_Reply_PrepareConnection_18(void *,void * *);
	static long Thunk_Reply_RegisterAlpcPort_25(void *,void * *);
	static long Thunk_Reply_RegisterConversationClient_58(void *,void * *);
	static long Thunk_Reply_RegisterConversation_45(void *,void * *);
	static long Thunk_Reply_RegisterObject_0(void *,void * *);
	static long Thunk_Reply_RegisterPendingConversationClientForServer_0(void *,void * *);
	static long Thunk_Reply_RegisterThread_14(void *,void * *);
	static long Thunk_Reply_ReleaseConversationClientConnection_0(void *,void * *);
	static long Thunk_Reply_ReleaseConversationClient_25(void *,void * *);
	static long Thunk_Reply_ReleaseConversationServer_25(void *,void * *);
	static long Thunk_Reply_SetWindowIDProperties_0(void *,void * *);
	static long Thunk_Reply_UnregisterAlpcPort_25(void *,void * *);
	static long Thunk_Reply_UnregisterObject_0(void *,void * *);
	static long Thunk_Reply_UnregisterReverseConnectionPort_25(void *,void * *);
};

class IRegistrarServer_MsgCallInfo
{
	static unsigned char const * * MethodInstructions;
};

struct IRegistrarServer_Receive<Microsoft::CoreUI::Registrar::RemoteRegistrarServerReceiveThunk>
{
	static MsgCallInterfaceTableEntry const * const Interfaces;
	static MsgCallMethodDefinition const * const Methods;
	static MsgCallTypeDefinition const Type;
	static long Thunk_AllocateWindowID_189(void *,void * *);
	static long Thunk_ClearWindowIDProperties_199(void *,void * *);
	static long Thunk_CloseConnection_96(void *,void * *);
	static long Thunk_CompleteCrossProcConnection_101(void *,void * *);
	static long Thunk_CompleteLocalConnection_14(void *,void * *);
	static long Thunk_ConnectPendingConversationClient_180(void *,void * *);
	static long Thunk_CrossProcClientDisconnected_0(void *,void * *);
	static long Thunk_FindCrossProcConnection_148(void *,void * *);
	static long Thunk_FindMessageObject_136(void *,void * *);
	static long Thunk_FindObject_119(void *,void * *);
	static long Thunk_FindPendingConversationClient_180(void *,void * *);
	static long Thunk_FreeWindowID_194(void *,void * *);
	static long Thunk_GetOrCreateReverseConnectionPortID_40(void *,void * *);
	static long Thunk_GetWindowIDInfo_194(void *,void * *);
	static long Thunk_GetWindowIDProperties_199(void *,void * *);
	static long Thunk_LocalClientDisconnected_0(void *,void * *);
	static long Thunk_PrepareConnection_96(void *,void * *);
	static long Thunk_RegisterAlpcPort_142(void *,void * *);
	static long Thunk_RegisterConversationClient_119(void *,void * *);
	static long Thunk_RegisterConversation_154(void *,void * *);
	static long Thunk_RegisterMessageObject_126(void *,void * *);
	static long Thunk_RegisterObject_106(void *,void * *);
	static long Thunk_RegisterPendingConversationClientForServer_170(void *,void * *);
	static long Thunk_RegisterThread_25(void *,void * *);
	static long Thunk_ReleaseConversationClientConnection_180(void *,void * *);
	static long Thunk_ReleaseConversationClient_119(void *,void * *);
	static long Thunk_ReleaseConversationServer_119(void *,void * *);
	static long Thunk_SetWindowIDProperties_199(void *,void * *);
	static long Thunk_UnregisterAlpcPort_40(void *,void * *);
	static long Thunk_UnregisterMessageObject_136(void *,void * *);
	static long Thunk_UnregisterObject_119(void *,void * *);
	static long Thunk_UnregisterReverseConnectionPort_40(void *,void * *);
};

class IThreadEndpoint_MsgCallInfo
{
	static unsigned char const * * MethodInstructions;
};

struct IThreadEndpoint_Receive<Microsoft::CoreUI::Services::ThreadEndpointReceiveThunk>
{
	static MsgCallInterfaceTableEntry const * const Interfaces;
	static MsgCallMethodDefinition const * const Methods;
	static MsgCallTypeDefinition const Type;
	static long Thunk_Callback_RequestResourceView_65(void *,void * *);
	static long Thunk_FreeHIDENTITY_76(void *,void * *);
	static long Thunk_LocalPingAndWait_81(void *,void * *);
	static long Thunk_NotifyHIDENTITYFreed_92(void *,void * *);
	static long Thunk_NotifyLocalConnectionCreated_97(void *,void * *);
	static long Thunk_NotifyLocalConnectionDisposed_102(void *,void * *);
	static long Thunk_ReleaseResourceMapping_11(void *,void * *);
	static long Thunk_ReserveHIDENTITY_76(void *,void * *);
};

struct KeyValueEntry__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait
{
	~KeyValueEntry__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait();
};

struct KeyValueEntry__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait$R
{
	static KeyValueEntry__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait New(Microsoft::CoreUI::Support::Win32Handle,Microsoft::CoreUI::Dispatch::RegisteredWait *);
};

struct Map
{
	bool Insert(System::Object *,System::Object *,bool);
	bool Remove(System::Object *);
	bool Remove(System::Object *,Cn::ParamRef<System::Object>);
	bool TryGetValue(System::Object *,Cn::ParamRef<System::Object>);
	int FindEntry(System::Object *);
	void Initialize(int);
	void Resize();
};

struct Map$R
{
	static Cn::TypeDefinition_67 const s_defType;
	static Map * New();
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map_1D
{
	Map * _SetElement(int,Map *);
};

struct Map_1D$R
{
	static Cn::TypeDefinition_4 const s_defType;
	static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	static void InitializeCppInstance(void *);
};

struct Map__Entry$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__Entry_1D$R
{
	static Cn::TypeDefinition_4 const s_defType;
	static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	static void InitializeCppInstance(void *);
};

struct Map__KeyCollection
{
	~Map__KeyCollection();
};

struct Map__KeyCollection__Enumerator
{
	bool MoveNext();
	~Map__KeyCollection__Enumerator();
};

struct Map__Microsoft_CoreUI_Messaging_ConnectedClient__object
{
	System::Object * get_Item(Microsoft::CoreUI::Messaging::ConnectedClient);
	bool Insert(Microsoft::CoreUI::Messaging::ConnectedClient,System::Object *,bool);
	bool KeyEquals(Microsoft::CoreUI::Messaging::ConnectedClient,Microsoft::CoreUI::Messaging::ConnectedClient);
	bool Remove(Microsoft::CoreUI::Messaging::ConnectedClient);
	bool Remove(Microsoft::CoreUI::Messaging::ConnectedClient,Cn::ParamRef<System::Object>);
	int FindEntry(Microsoft::CoreUI::Messaging::ConnectedClient);
	void Clear();
	void Initialize(int);
	void Resize();
};

struct Map__Microsoft_CoreUI_Messaging_ConnectedClient__object$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static Map__Microsoft_CoreUI_Messaging_ConnectedClient__object * New();
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__Microsoft_CoreUI_Messaging_ConnectedClient__object__Entry$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__Microsoft_CoreUI_Messaging_ConnectedClient__object__Entry_1D$R
{
	static Cn::TypeDefinition_4 const s_defType;
	static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	static void InitializeCppInstance(void *);
};

struct Map__Microsoft_CoreUI_Messaging_ConnectedClient__object__KeyCollection
{
	~Map__Microsoft_CoreUI_Messaging_ConnectedClient__object__KeyCollection();
};

struct Map__Microsoft_CoreUI_Messaging_ConnectedClient__object__KeyCollection__Enumerator
{
	bool MoveNext();
	~Map__Microsoft_CoreUI_Messaging_ConnectedClient__object__KeyCollection__Enumerator();
};

struct Map__Microsoft_CoreUI_Messaging_ConnectedClient__object__ValueCollection
{
	~Map__Microsoft_CoreUI_Messaging_ConnectedClient__object__ValueCollection();
};

struct Map__Microsoft_CoreUI_Messaging_ConnectedClient__object__ValueCollection__Enumerator
{
	bool MoveNext();
	~Map__Microsoft_CoreUI_Messaging_ConnectedClient__object__ValueCollection__Enumerator();
};

struct Map__Microsoft_CoreUI_Messaging_ConnectionID__Microsoft_CoreUI_Messaging_Connection
{
	Microsoft::CoreUI::Messaging::Connection * get_Item(Microsoft::CoreUI::Messaging::ConnectionID);
	bool Insert(Microsoft::CoreUI::Messaging::ConnectionID,Microsoft::CoreUI::Messaging::Connection *,bool);
	bool Remove(Microsoft::CoreUI::Messaging::ConnectionID);
	bool TryGetValue(Microsoft::CoreUI::Messaging::ConnectionID,Cn::ParamRef<Microsoft::CoreUI::Messaging::Connection>);
	int FindEntry(Microsoft::CoreUI::Messaging::ConnectionID);
	void Initialize(int);
	void Resize();
};

struct Map__Microsoft_CoreUI_Messaging_ConnectionID__Microsoft_CoreUI_Messaging_Connection$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__Microsoft_CoreUI_Messaging_ConnectionID__Microsoft_CoreUI_Messaging_Connection__Entry$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__Microsoft_CoreUI_Messaging_ConnectionID__Microsoft_CoreUI_Messaging_Connection__Entry_1D$R
{
	static Cn::TypeDefinition_4 const s_defType;
	static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	static void InitializeCppInstance(void *);
};

struct Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait
{
	bool Insert(Microsoft::CoreUI::Support::Win32Handle,Microsoft::CoreUI::Dispatch::RegisteredWait *,bool);
	bool KeyEquals(Microsoft::CoreUI::Support::Win32Handle,Microsoft::CoreUI::Support::Win32Handle);
	bool Remove(Microsoft::CoreUI::Support::Win32Handle,Cn::ParamRef<Microsoft::CoreUI::Dispatch::RegisteredWait>);
	int FindEntry(Microsoft::CoreUI::Support::Win32Handle);
	void Clear();
	void Initialize(int);
	void Resize();
};

struct Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait__Entry$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait__Entry_1D$R
{
	static Cn::TypeDefinition_4 const s_defType;
	static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	static void InitializeCppInstance(void *);
};

struct Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait__Enumerator
{
	bool MoveNext();
	~Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait__Enumerator();
};

struct Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait__Enumerator$R
{
	static Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait__Enumerator New(Map__Microsoft_CoreUI_Support_Win32Handle__Microsoft_CoreUI_Dispatch_RegisteredWait *);
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort
{
	bool Insert(System::Guid,Microsoft::CoreUI::Messaging::CrossProcessReceivePort *,bool);
	bool KeyEquals(System::Guid,System::Guid);
	bool Remove(System::Guid);
	bool TryGetValue(System::Guid,Cn::ParamRef<Microsoft::CoreUI::Messaging::CrossProcessReceivePort>);
	int FindEntry(System::Guid);
	void Initialize(int);
	void Resize();
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort__Entry$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort__Entry_1D$R
{
	static Cn::TypeDefinition_4 const s_defType;
	static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	static void InitializeCppInstance(void *);
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort__ValueCollection
{
	~Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort__ValueCollection();
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort__ValueCollection__Enumerator
{
	bool MoveNext();
	~Map__System_Guid__Microsoft_CoreUI_Messaging_CrossProcessReceivePort__ValueCollection__Enumerator();
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort
{
	bool Insert(System::Guid,Microsoft::CoreUI::Messaging::ReverseConnectionReceivePort *,bool);
	bool KeyEquals(System::Guid,System::Guid);
	bool Remove(System::Guid);
	bool TryGetValue(System::Guid,Cn::ParamRef<Microsoft::CoreUI::Messaging::ReverseConnectionReceivePort>);
	int FindEntry(System::Guid);
	void Initialize(int);
	void Resize();
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort__Entry$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort__Entry_1D$R
{
	static Cn::TypeDefinition_4 const s_defType;
	static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	static void InitializeCppInstance(void *);
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort__ValueCollection
{
	~Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort__ValueCollection();
};

struct Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort__ValueCollection__Enumerator
{
	~Map__System_Guid__Microsoft_CoreUI_Messaging_ReverseConnectionReceivePort__ValueCollection__Enumerator();
};

struct Map__System_Guid__object
{
	bool Insert(System::Guid,System::Object *,bool);
	bool KeyEquals(System::Guid,System::Guid);
	int FindEntry(System::Guid);
	void Clear();
	void Initialize(int);
	void Resize();
};

struct Map__System_Guid__object$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__System_Guid__object__Entry$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__System_Guid__object__Entry_1D$R
{
	static Cn::TypeDefinition_4 const s_defType;
	static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	static void InitializeCppInstance(void *);
};

struct Map__System_IntPtr__object
{
	bool Insert(System::IntPtr,System::Object *,bool);
	bool Remove(System::IntPtr);
	bool TryGetValue(System::IntPtr,Cn::ParamRef<System::Object>);
	int FindEntry(System::IntPtr);
	void Initialize(int);
	void Resize();
};

struct Map__System_IntPtr__object$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__System_IntPtr__object__Entry$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__System_IntPtr__object__Entry_1D$R
{
	static Cn::TypeDefinition_4 const s_defType;
	static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	static void InitializeCppInstance(void *);
};

struct Map__uint__object
{
	System::Object * get_Item(unsigned int);
	bool Insert(unsigned int,System::Object *,bool);
	bool Remove(unsigned int);
	bool Remove(unsigned int,Cn::ParamRef<System::Object>);
	bool TryGetValue(unsigned int,Cn::ParamRef<System::Object>);
	int FindEntry(unsigned int);
	void Add(unsigned int,System::Object *);
	void Clear();
	void Initialize(int);
	void Resize();
};

struct Map__uint__object$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static Map__uint__object * New();
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__uint__object__Entry$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__uint__object__Entry_1D$R
{
	static Cn::TypeDefinition_4 const s_defType;
	static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	static void InitializeCppInstance(void *);
};

struct Map__uint__object__KeyCollection
{
	~Map__uint__object__KeyCollection();
};

struct Map__uint__object__KeyCollection__Enumerator
{
	bool MoveNext();
	~Map__uint__object__KeyCollection__Enumerator();
};

struct Map__uint__object__ValueCollection
{
	~Map__uint__object__ValueCollection();
};

struct Map__uint__object__ValueCollection__Enumerator
{
	bool MoveNext();
	~Map__uint__object__ValueCollection__Enumerator();
};

struct Map__uint__uint
{
	bool Insert(unsigned int,unsigned int,bool);
	bool Remove(unsigned int);
	bool TryGetValue(unsigned int,unsigned int &);
	int FindEntry(unsigned int);
	unsigned int get_Item(unsigned int);
	void Initialize(int);
	void Resize();
};

struct Map__uint__uint$R
{
	static Cn::TypeDefinition_65 const s_defType;
	static Map__uint__uint * New();
	static short const * const s_rgReferenceFields;
	static void InitializeCppInstance(void *);
};

struct Map__uint__uint__Entry$R
{
	static Cn::TypeDefinition_64 const s_defType;
	static void InitializeCppInstance(void *);
};

struct Map__uint__uint__Entry_1D$R
{
	static Cn::TypeDefinition_4 const s_defType;
	static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	static void InitializeCppInstance(void *);
};

namespace Microsoft
{
	namespace CoreUI
	{
		struct BaseDisposableObject
		{
			virtual System::String * ToString();
			virtual void OnDispose();
			void DisposeWorker();
		};

		struct BaseDisposableObject$R
		{
			static Cn::TypeDefinition_66 const s_defType;
		};

		struct BatchAgnosticDispatchGroup
		{
			virtual void Callback_OnDispatch();
		};

		struct BatchAgnosticDispatchGroup$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static short const * const s_rgReferenceFields;
			static void InitializeCppInstance(void *);
		};

		struct BatchEnabledDispatchGroup
		{
			virtual void Callback_OnDispatch();
			virtual void OnDispose();
		};

		struct BatchEnabledDispatchGroup$R
		{
			static BatchEnabledDispatchGroup * New(Dispatch::Dispatcher *,DispatchGroupBatchEnableHandler *,DispatchGroupHandler *);
			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static short const * const s_rgReferenceFields;
			static void Delegate0(System::Delegate *);
			static void InitializeCppInstance(void *);
		};

		namespace Buffering
		{
			struct BufferAllocationPolicy
			{
				unsigned char * AllocateForStream(BufferStream *,unsigned int &,Cn::ParamRef<IBufferAllocator>);
			};

			struct BufferAllocationPolicy$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct BufferHeapBlock
			{
				BufferMemoryRange * ReserveRange(unsigned int,unsigned int);
				virtual void OnDispose();
				void Initialize(BufferStream *,unsigned int);
			};

			struct BufferHeapBlock$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct BufferManager
			{
				BufferAllocationPolicy * CreateStockAllocationPolicy(unsigned int,bool,unsigned int);
				BufferHeapBlock * AllocHeapBlockInstance(BufferStream *,unsigned int);
				BufferMemoryRange * AllocMemoryRangeInstance(BufferHeapBlock *,unsigned char *,unsigned int,unsigned int);
				BufferPolicyEntry_1D * BuildDefaultPolicyEntries();
				BufferStream * AllocBufferStreamInstance(BufferAllocationPolicy *,unsigned int);
				ProcessHeapAllocator * get_ProcessHeapAllocator();
				SharedPoolAllocator * get_SharedPoolAllocator();
				SmallBlockAllocator * get_SmallBlockAllocator();
				virtual void OnDispose();
				void RecycleBufferStreamInstance(BufferStream *);
				void _Construct(Dispatch::EventLoop *);
			};

			struct BufferManager$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct BufferMemoryRange
			{
				unsigned char * AllocEntry(unsigned int);
				virtual void OnDispose();
			};

			struct BufferMemoryRange$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct BufferPolicyEntry
			{
				~BufferPolicyEntry();
			};

			struct BufferPolicyEntry$R
			{
				static BufferPolicyEntry New(IBufferAllocator *);
				static BufferPolicyEntry New(IBufferAllocator *,unsigned int);
				static Cn::TypeDefinition_65 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct BufferPolicyEntry_1D
			{
				BufferPolicyEntry_1D * InitializeItems(int,...);
			};

			struct BufferPolicyEntry_1D$R
			{
				static Cn::TypeDefinition_4 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct BufferSet
			{
				BufferMemoryRange * AddMemoryRange(unsigned int);
				Support::BufferInfo get_FirstBuffer();
				virtual void OnDispose();
				void * AllocEntry(unsigned int);
				void AllocationCompleted();
				void CancelEntry(void *);
				void NotifyFirstBufferConsumed();
			};

			struct BufferSet$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct BufferSet__Enumerator
			{
				Support::BufferInfo get_Current();
				bool MoveNext();
				~BufferSet__Enumerator();
			};

			struct BufferStream
			{
				BufferHeapBlock * AddHeapBlock(unsigned int);
				BufferMemoryRange * ReserveRange(unsigned int);
				BufferSet * CreateBufferSet();
				virtual void OnDispose();
			};

			struct BufferStream$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct IBufferAllocator
			{
				unsigned char * Allocate(unsigned int &);
				void Free(unsigned char *,unsigned int);
			};

			struct IBufferAllocator$R
			{
				static Cn::TypeDefinition_64 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void const * const * const s_rgLookup;
			};

			struct LargeBlockAllocator
			{
				static void InitClass(bool);
				unsigned char * Allocate(unsigned int &);
			};

			struct LargeBlockAllocator$R
			{
				struct Microsoft__CoreUI__Buffering__IBufferAllocator_Impl
				{
					virtual unsigned char * Allocate(System::Object *,unsigned int &);
					virtual void Free(System::Object *,unsigned char *,unsigned int);
				};

				struct System__IDisposable_Impl
				{
					virtual void Dispose(System::Object *);
				};

				static Cn::TypeDefinition_64 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static LargeBlockAllocator$R::Microsoft__CoreUI__Buffering__IBufferAllocator_Impl const s_Microsoft__CoreUI__Buffering__IBufferAllocator_Impl;
				static LargeBlockAllocator$R::System__IDisposable_Impl const s_System__IDisposable_Impl;
				static void InitializeCppInstance(void *);
			};

			struct LargeBlockPool
			{
				bool AcquireBlock(void *,unsigned char * *,unsigned int *);
				bool OwnsMemory(unsigned char *);
				void Initialize(bool);
				void ReleaseBlock(unsigned char *,unsigned int);
			};

			class MediumBlockPool
			{
				static unsigned long FindFreeBlocks(unsigned long,unsigned int,unsigned int *);
				void AcquireMemory(ChunkInfo *);
				void WaitForMemory(ChunkInfo *);
			public:
				unsigned char * Allocate(unsigned int *);
				void Free(unsigned char *,unsigned int);
				void Initialize();
			};

			struct ProcessHeapAllocator$R
			{
				struct Microsoft__CoreUI__Buffering__IBufferAllocator_Impl
				{
					virtual unsigned char * Allocate(System::Object *,unsigned int &);
					virtual void Free(System::Object *,unsigned char *,unsigned int);
				};

				struct System__IDisposable_Impl
				{
					virtual void Dispose(System::Object *);
				};

				static Cn::TypeDefinition_64 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ProcessHeapAllocator$R::Microsoft__CoreUI__Buffering__IBufferAllocator_Impl const s_Microsoft__CoreUI__Buffering__IBufferAllocator_Impl;
				static ProcessHeapAllocator$R::System__IDisposable_Impl const s_System__IDisposable_Impl;
				static void InitializeCppInstance(void *);
			};

			struct SharedPoolAllocator
			{
				static void InitClass(bool);
			};

			struct SharedPoolAllocator$R
			{
				struct Microsoft__CoreUI__Buffering__IBufferAllocator_Impl
				{
					virtual unsigned char * Allocate(System::Object *,unsigned int &);
					virtual void Free(System::Object *,unsigned char *,unsigned int);
				};

				struct System__IDisposable_Impl
				{
					virtual void Dispose(System::Object *);
				};

				static Cn::TypeDefinition_64 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static SharedPoolAllocator$R::Microsoft__CoreUI__Buffering__IBufferAllocator_Impl const s_Microsoft__CoreUI__Buffering__IBufferAllocator_Impl;
				static SharedPoolAllocator$R::System__IDisposable_Impl const s_System__IDisposable_Impl;
				static void InitializeCppInstance(void *);
			};

			struct SmallBlockAllocator
			{
				bool GetBackingMemory(unsigned int,unsigned char * &);
				static unsigned int FindFreeRun(unsigned int,unsigned int,unsigned int &);
				virtual void OnDispose();
				void ReleaseBackingMemory();
				void _Construct(BufferManager *,SharedPoolAllocator *);
			};

			struct SmallBlockAllocator$R
			{
				struct Microsoft__CoreUI__Buffering__IBufferAllocator_Impl
				{
					virtual unsigned char * Allocate(System::Object *,unsigned int &);
					virtual void Free(System::Object *,unsigned char *,unsigned int);
				};

				struct System__IDisposable_Impl
				{
					virtual void Dispose(System::Object *);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static SmallBlockAllocator * New(BufferManager *,SharedPoolAllocator *);
				static SmallBlockAllocator$R::Microsoft__CoreUI__Buffering__IBufferAllocator_Impl const s_Microsoft__CoreUI__Buffering__IBufferAllocator_Impl;
				static SmallBlockAllocator$R::System__IDisposable_Impl const s_System__IDisposable_Impl;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *);
				static void InitializeCppInstance(void *);
			};

			struct SmallBlockAllocator__GroupDescriptor$R
			{
				static Cn::TypeDefinition_64 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct SmallBlockAllocator__GroupDescriptor_1D$R
			{
				static Cn::TypeDefinition_4 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			Buffering::LargeBlockPool g_LargeBlockPool;
			Buffering::MediumBlockPool g_MediumBlockPool;
		};

		struct CoalescerHandler
		{
			void Invoke(__int64);
		};

		struct CoalescerHandler$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct ConversationItemEnumProc
		{
			void Invoke(unsigned int,unsigned int,void *);
		};

		struct ConversationItemEnumProc$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		namespace Conversations
		{
			struct Conversation
			{
				Messaging::MessageStream * StreamFromPeer(ConversationPeer *);
				System::IntPtr Microsoft__CoreUI__IExportMessageConversation__RemoveItem(unsigned int,unsigned int,bool);
				bool EnqueueRemoteFreeItem(ConversationPeer *,ItemID,bool);
				bool get_IsSinglePersistentManualServer();
				unsigned int Microsoft__CoreUI__IExportMessageConversation__AllocateItemForPeer(unsigned int,void *);
				virtual void CleanupEndpoints();
				virtual void OnDispose();
				void * Microsoft__CoreUI__IExportMessageConversation__GetItem(unsigned int,unsigned int);
				void AttachPeer(ConversationPeer *);
				void Callback_FlushItemDeletion(ItemID,unsigned int,bool);
				void Callback_OnItemMessage(Support::BufferInfo);
				void CleanUpAfterDepartedPeer(ConversationPeer *,bool,bool,bool);
				void EnqueueReserveItem(ConversationPeer *,ItemID);
				void InitializeItemTable(unsigned int,unsigned int);
				void InsertPeerAtHead(ConversationPeer *);
				void Microsoft__CoreUI__IExportMessageConversation__EnumerateItems(unsigned int,bool,bool,ConversationItemEnumProc *);
				void Microsoft__CoreUI__IExportMessageConversation__FlushItemDeletion(unsigned int,unsigned int,bool);
				void Microsoft__CoreUI__IExportMessageConversation__Send(unsigned int,unsigned int,void *,unsigned int);
				void Microsoft__CoreUI__IExportMessageConversation__SetItemData(unsigned int,unsigned int,void *);
				void NotifyAllIDsFreed(unsigned int,ConversationItemOwner,bool);
				void Remote_FreeItem(ItemID,bool);
				void Remote_ItemFreed(ItemID);
				void Remote_PeerDisconnected(unsigned int);
				void Remote_ReserveItem(ItemID);
				void _Construct(System::String *,Registrar::ScopeID,Dispatch::ThreadContext *,ConversationItemOwner,ICallbackMessageConversationHost *);
			};

			struct Conversation$R
			{
				struct Microsoft__CoreUI__IExportMessageConversation_Impl
				{
					virtual System::IntPtr RemoveItem(System::Object *,unsigned int,unsigned int,bool);
					virtual bool get_DeferMessageDelivery(System::Object *);
					virtual unsigned int AllocateItemForPeer(System::Object *,unsigned int,void *);
					virtual void * GetItem(System::Object *,unsigned int,unsigned int);
					virtual void EnumerateItems(System::Object *,unsigned int,bool,bool,ConversationItemEnumProc *);
					virtual void FlushItemDeletion(System::Object *,unsigned int,unsigned int,bool);
					virtual void Send(System::Object *,unsigned int,unsigned int,void *,unsigned int);
					virtual void SetItemData(System::Object *,unsigned int,unsigned int,void *);
					virtual void set_DeferMessageDelivery(System::Object *,bool);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static Conversation$R::Microsoft__CoreUI__IExportMessageConversation_Impl const s_Microsoft__CoreUI__IExportMessageConversation_Impl;
				static short const * const s_rgReferenceFields;
			};

			struct ConversationClient
			{
				EndpointStuff * ProcureEndpointStuff(Messaging::Connection *);
				static void AddPersistentClient(ConversationClient *);
				static void OnServerJoinedStatic(System::String *,unsigned int,unsigned int,ConversationPeerInfo);
				static void RemovePersistentClient(ConversationClient *);
				virtual bool GetIsMessageDeliveryDeferred();
				virtual void OnConnectionBroken(ConversationPeer *);
				virtual void OnDispose();
				virtual void OnPeerDeparted(ConversationPeer *,bool);
				virtual void SetIsMessageDeliveryDeferred(Messaging::MessageSession *,bool);
				void ConnectWithRegistrar();
				void DeferredConnectToNewServer(System::Object *);
				void OnEndpointsAvailable(ConversationPeerInfo);
				void OnServerJoined(ConversationPeerInfo);
			};

			struct ConversationClient$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ConversationClient * New(Dispatch::ThreadContext *,System::String *,Registrar::ScopeID,ICallbackMessageConversationHost *);
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,System::Object *);
				static void InitializeCppInstance(void *);
			};

			struct ConversationClientCaller
			{
				static void ConnectionAccepted(Messaging::MessageStream *,HIDENTITY,unsigned int);
				static void FreeItem(Messaging::MessageStream *,HIDENTITY,ItemID,bool);
				static void ItemFreed(Messaging::MessageStream *,HIDENTITY,ItemID);
				static void ReserveItem(Messaging::MessageStream *,HIDENTITY,ItemID);
			};

			struct ConversationClient__ClientConversationPeer
			{
				virtual void OnDispose();
			};

			struct ConversationClient__ClientConversationPeer$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ConversationClient__ClientConversationPeer * New(Conversation *,Messaging::Connection *,ConversationPeerInfo,EndpointStuff *);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ConversationControlEndpoint
			{
				virtual void Callback_OnMessageCore(Support::BufferInfo);
			};

			struct ConversationControlEndpoint$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ConversationInfo
			{
				static ConversationInfo Invalid;
			};

			struct ConversationInfo$R
			{
				static Cn::TypeDefinition_66 const s_defType;
				static void InitializeCppInstance(void *);
			};

			class ConversationMessageCallSendHost
			{
				virtual long AllocateBuffer(unsigned __int64 *,unsigned int,unsigned int,void * *);
				virtual long SubmitBuffer(unsigned __int64 *,unsigned int,void *,unsigned int);
			};

			struct ConversationPeer
			{
				virtual void OnDispose();
				void _Construct(Conversation *,Messaging::Connection *,ConversationPeerInfo);
			};

			struct ConversationPeer$R
			{
				struct Microsoft__CoreUI__Resources__ITrackableResource_Impl
				{
					virtual System::Object * get_TrackerData(System::Object *);
					virtual void OnResourceRetired(System::Object *);
					virtual void set_TrackerData(System::Object *,System::Object *);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ConversationPeer * New(Conversation *,Messaging::Connection *,ConversationPeerInfo);
				static ConversationPeer$R::Microsoft__CoreUI__Resources__ITrackableResource_Impl const s_Microsoft__CoreUI__Resources__ITrackableResource_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ConversationPeerInfo
			{
				static ConversationPeerInfo Invalid;
			};

			struct ConversationPeerInfo$R
			{
				static Cn::TypeDefinition_66 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct ConversationServer
			{
				virtual bool GetIsMessageDeliveryDeferred();
				virtual void CleanupEndpoints();
				virtual void OnConnectionBroken(ConversationPeer *);
				virtual void OnDispose();
				virtual void OnPeerDeparted(ConversationPeer *,bool);
				virtual void SetIsMessageDeliveryDeferred(Messaging::MessageSession *,bool);
				void CompleteClientConnection(unsigned int,RoutingInfo,RoutingInfo);
				void Microsoft__CoreUI__IExportMessageConversationServer__AttachClient(unsigned int,unsigned int);
				void Register(System::String *);
				void Remote_ClientConnectionRequested(HIDENTITY,HIDENTITY,System::Guid,unsigned int);
				void _Construct(Dispatch::ThreadContext *,System::String *,System::String *,Registrar::ScopeID,Messaging::CrossProcessReceivePortBase *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *);
			};

			struct ConversationServer$R
			{
				struct Microsoft__CoreUI__IExportMessageConversationServer_Impl
				{
					virtual void AttachClient(System::Object *,unsigned int,unsigned int);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ConversationServer * New(Dispatch::ThreadContext *,System::String *,System::String *,Registrar::ScopeID,Messaging::CrossProcessReceivePortBase *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *);
				static ConversationServer$R::Microsoft__CoreUI__IExportMessageConversationServer_Impl const s_Microsoft__CoreUI__IExportMessageConversationServer_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ConversationServerCaller
			{
				static void ClientConnectionRequested(Messaging::MessageStream *,HIDENTITY,HIDENTITY,HIDENTITY,System::Guid,unsigned int);
				static void FreeItem(Messaging::MessageStream *,HIDENTITY,ItemID,bool);
				static void ItemFreed(Messaging::MessageStream *,HIDENTITY,ItemID);
				static void ReserveItem(Messaging::MessageStream *,HIDENTITY,ItemID);
			};

			struct EndpointStuff
			{
				ConversationPeerInfo ToPeerInfo(unsigned int);
				virtual void OnDispose();
				void RebindPorts(Messaging::CrossProcessReceivePortBase *);
				void SetDeferMessageDelivery(Messaging::MessageSession *,bool);
				void _Construct(Dispatch::ThreadContext *,Conversation *,Messaging::CrossProcessReceivePortBase *,bool);
			};

			struct EndpointStuff$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static EndpointStuff * New(Dispatch::ThreadContext *,Conversation *,Messaging::CrossProcessReceivePortBase *,bool);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct GroupEnumerator
			{
				GroupItem get_Current();
				bool MoveNext();
			};

			struct IDAllocator
			{
				static System::Int32_1D * get_EmptyArray();
				virtual bool AllocateID(unsigned int &);
				virtual bool AllocateKnownID(unsigned int);
				virtual bool FreeID(unsigned int);
				virtual bool IsValidID(unsigned int);
				void Clear();
				void GrowStorage(int);
			};

			struct IDAllocator$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct IDLRUAllocator
			{
				bool AddToLRU(unsigned int,unsigned int &);
				bool FindInLRU(unsigned int);
				virtual bool FreeID(unsigned int);
			};

			struct IDLRUAllocator$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static IDLRUAllocator * New(int,int);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ItemGroup
			{
				bool IsValidPID(unsigned int);
				bool RemoveItem(unsigned int,unsigned int,ItemGroupOwner,System::IntPtr &,bool &);
				bool RemoveItemAcknowledged(unsigned int,unsigned int);
				bool ReserveItem(unsigned int,unsigned int,bool);
				virtual void OnDispose();
			};

			struct ItemGroup$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ItemGroup * New(ItemGroupOwner,ConversationPeer *,bool);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ItemID
			{
				static ItemID FromExternalID(unsigned int,unsigned int,unsigned int);
			};

			struct ItemMessageDispatcher
			{
				virtual void Callback_OnMessageCore(Support::BufferInfo);
			};

			struct ItemMessageDispatcher$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ItemMessageDispatcher * New(Dispatch::ThreadContext *,Conversation *,System::Object *,Messaging::CrossProcessReceivePortBase *);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ItemTable
			{
				ItemGroup * GetGroup(unsigned int,ConversationItemOwner,bool);
				ItemGroup * TryGetLocalHubGroup();
				bool DeleteItemAcknowledged(ItemID,unsigned int);
				bool DeleteItemRemote(ItemID,unsigned int,Cn::ParamRef<ConversationPeer>,System::IntPtr &,bool &);
				bool GetItem(ItemID,System::IntPtr &);
				bool GroupForGroupIndex(unsigned int,Cn::ParamRef<ItemGroup>);
				bool GroupForItem(ItemID,Cn::ParamRef<ItemGroup>);
				bool PeerForID(unsigned int,unsigned int,Cn::ParamRef<ConversationPeer>);
				bool ReserveItem(ItemID,unsigned int);
				bool SetItemData(ItemID,System::IntPtr);
				bool TryGetGroup(unsigned int,ConversationItemOwner,bool,Cn::ParamRef<ItemGroup>);
				bool ValidateItem(ItemID,Cn::ParamRef<ConversationPeer>);
				unsigned int PeerIDToGroupIndex(unsigned int,ConversationItemOwner,bool);
				virtual void OnDispose();
				void AddGroup(ItemGroup *,unsigned int,ConversationItemOwner,bool);
				void AllocateGroupsForPeer(ConversationPeer *);
				void FreeGroup(unsigned int,bool);
				void FreeGroupsForPeer(ConversationPeer *);
			};

			struct ItemTable$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ItemTable * New(Conversation *,unsigned int);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			class SparseItemTable
			{
				struct CountsHolder<unsigned char>
				{
					bool IsEmpty();
					void Transition(CountCategory,CountCategory);
				};

				class InternalEnumerator
				{
					bool TryResyncWithTable();
				public:
					bool MoveNext();
					void CurrentSlot(unsigned int *,StorageLevel * *,unsigned int *);
				};

				struct StorageLevel
				{
					StorageLevel * DrillDownToFirstLeaf();
					StorageLevel * GetNextLeaf();
					StorageLevel * MakeAndLinkNewChild(unsigned short,unsigned short,bool);
					bool LeafTransition(CountCategory,CountCategory,SparseItemTable *);
					bool RemoveItem(SparseItemTable *,bool,unsigned int,unsigned int,CountsHolder<unsigned int> &,void * *,bool *);
					bool StoreData(unsigned short,unsigned int,void *,SparseItemTable *);
					static StorageLevel * Allocate(unsigned short,bool);
					unsigned int MarkInUse(unsigned int,SparseItemTable *);
					void AddTierOfIndirection(unsigned short,bool);
					void ClearSlot(SparseItemTable *,StorageLevel::SlotMetadata &,unsigned int);
					void Destroy();
					void RecursiveDestroy(int);
				};

				bool FindNextSuitableFreeSlot(unsigned int *,SparseItemTable::StorageLevel * *,unsigned int *);
				bool ResolveIndex<0>(unsigned int,unsigned short *,SparseItemTable::StorageLevel * *);
				bool ResolveIndex<1>(unsigned int,unsigned short *,SparseItemTable::StorageLevel * *);
				unsigned int ChooseIndexToAllocate();
				unsigned int ChooseIndexToAllocateWorker(unsigned int,unsigned int);
				void IncreaseTierLevel();
			public:
				bool ReserveId(unsigned int);
				static SparseItemTable * Create(bool);
				void Destroy();
			};

			Conversations::ConversationMessageCallSendHost g_conversationSendHost;
		};

		struct CoreUISession
		{
			static void Initialize(bool,bool);
			static void Release();
		};

		namespace DesignPatterns
		{
			struct ChainLink
			{
				ChainLink(ChainLink const &);
				static unsigned int s_IDSeed;
				~ChainLink();
			};

			struct ChainLink$R
			{
				static ChainLink Unbox(System::Object *);
				static Cn::TypeDefinition_67 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ChainLink_1D
			{
				ChainLink & _SetElement(int,ChainLink);
			};

			struct ChainLink_1D$R
			{
				static Cn::TypeDefinition_4 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct TimerChain
			{
				void Dispose();
				void OnFire();
				void Remove(unsigned int);
				void _Construct(unsigned int,Messaging::MessageSession *,TimerCoalescer *);
			};

			struct TimerChain$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static TimerChain * New(unsigned int,Messaging::MessageSession *,TimerCoalescer *);
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *);
				static void InitializeCppInstance(void *);
			};

			struct TimerCoalescer
			{
				__int64 Microsoft__CoreUI__IExportMessageTimerCoalescer__Register(unsigned int,CoalescerHandler *);
				virtual void OnDispose();
				void Microsoft__CoreUI__IExportMessageTimerCoalescer__Cancel(__int64);
			};

			struct TimerCoalescer$R
			{
				struct Microsoft__CoreUI__IExportMessageTimerCoalescer_Impl
				{
					virtual __int64 Register(System::Object *,unsigned int,CoalescerHandler *);
					virtual void Cancel(System::Object *,__int64);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static TimerCoalescer * New();
				static TimerCoalescer$R::Microsoft__CoreUI__IExportMessageTimerCoalescer_Impl const s_Microsoft__CoreUI__IExportMessageTimerCoalescer_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

		};

		namespace Dispatch
		{
			struct DeferredCall
			{
				void Callback_Dispatch();
			};

			struct DeferredCall$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct DeferredCallDispatcher
			{
				virtual void Callback_OnDispatch();
				virtual void OnDispose();
				void Post(ExternalPriority,System::Action *);
				void Post(ExternalPriority,System::Action__object *,System::Object *);
				void Post(ExternalPriority,System::Action__object__bool *,System::Object *,bool);
				void Post(InternalPriority,System::Action__Microsoft_CoreUI_Support_Win32Handle *,Support::Win32Handle);
				void Post(InternalPriority,WaitController *,WakeRecord *);
				void PostItem(ExternalPriority,DeferredCall *);
				void PostItem(InternalPriority,DeferredCall *);
				void Reset();
			};

			struct DeferredCallDispatcher$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static DeferredCallDispatcher * New(Dispatcher *);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct DeferredCall__DeferredCallCache
			{
				DeferredCall * AllocateFromCache();
				DeferredCall * Create(System::Action__object *,System::Object *);
				virtual void OnDispose();
			};

			struct DeferredCall__DeferredCallCache$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct DispatchCallback
			{
				void Invoke(bool,FILETIME &);
			};

			struct DispatchCallback$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct DispatchEntryCallback$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct DispatchItem
			{
				bool CheckYield();
				bool ForceWakeLevel(InternalPriority);
				virtual void OnCancelled();
				virtual void OnDispose();
				virtual void OnEnabledChanged(bool);
				void HandleEnabledChanged(bool);
			};

			struct DispatchItem$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
			};

			struct DispatchWatchdogCallback$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct Dispatcher
			{
				DispatchItem * PeekNextItem(bool);
				System::TimeSpan CallDispatchCallback(bool,bool);
				bool CheckYield(DispatchItem *);
				bool QueryPendingItems();
				static InternalPriority MapPriority(ExternalPriority);
				static int MapPriorityMask(RunnablePriorityMask);
				static void ValidatePriority(ExternalPriority);
				static void ValidatePriority(InternalPriority);
				virtual void OnDispose();
				void CancelCurrentItem();
				void OnChildAttach(DispatchItem *,bool);
				void OnChildWakeChanged(DispatchItem *,InternalPriority,InternalPriority);
				void RegisterDispatchCallback(DispatchCallback *);
				void UnregisterDispatchCallback(DispatchCallback *,bool);
				void UpdateWakeLevel();
				void _Construct(EventLoop *);
			};

			struct Dispatcher$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct Dispatcher__ExternalYieldCheckHandler$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct EventLoop
			{
				DeferredCallDispatcher * get_DeferredCallDispatcher();
				Dispatcher__LoopExitState Callback_RunCoreLoop(RunMode,bool,bool &);
				OffThreadReceiver * get_HighPriorityOffThreadReceiver();
				OffThreadReceiver * get_OffThreadDeferredReceiver();
				WaitStatus Callback_Wait(unsigned int,Support::Win32Handle *,unsigned int,WaitFlags,bool);
				WaitStatus Microsoft__CoreUI__IExportMessageLoopExtensions__Wait(unsigned int,Support::Win32Handle *,unsigned int,WaitFlags);
				bool get_IgnoringWindowMessages();
				bool get_IsActive();
				bool get_IsActiveAndNotStopping();
				bool get_IsIntegratingWithUser();
				static void SignalWakeObject(void *,void *);
				virtual void OnDispose();
				void CallExternalYieldCheckHandler(InternalPriority,int);
				void CallYieldCheckHandler(InternalPriority);
				void Callback_Run(RunMode);
				void CheckForUserIntegration(bool);
				void Exit();
				void IgnoreWindowMessages(bool);
				void InstallYieldCheckHandler(System::Action *);
				void Microsoft__CoreUI__IExportMessageLoopExtensions__RegisterDispatchWatchdog(DispatchWatchdogCallback *,__int64);
				void Microsoft__CoreUI__IExportMessageLoopExtensions__Run(RunMode);
				void Microsoft__CoreUI__IExportMessageLoopExtensions__SetMitIocp(Support::Win32Handle);
				void Microsoft__CoreUI__IExportMessageLoopExtensions__UnregisterDispatchWatchdog(DispatchWatchdogCallback *);
				void Microsoft__CoreUI__IExportMessageLoopExtensions__UrgentExit();
				void Reset();
				void StartupUserIntegration(bool);
				void UninstallYieldCheckHandler(System::Action *);
				void _Construct(ThreadContext *);
			};

			struct EventLoop$R
			{
				struct Microsoft__CoreUI__IExportMessageLoopExtensions_Impl
				{
					virtual WaitStatus Wait(System::Object *,unsigned int,Support::Win32Handle *,unsigned int,WaitFlags);
					virtual bool CheckForNewWork(System::Object *);
					virtual bool get_IsRunning(System::Object *);
					virtual void AssumeLoopActive(System::Object *);
					virtual void IgnoreWindowMessages(System::Object *);
					virtual void RegisterDispatchWatchdog(System::Object *,DispatchWatchdogCallback *,__int64);
					virtual void Run(System::Object *,RunMode);
					virtual void SetMitIocp(System::Object *,Support::Win32Handle);
					virtual void UnregisterDispatchWatchdog(System::Object *,DispatchWatchdogCallback *);
					virtual void UrgentExit(System::Object *);
				};

				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static EventLoop$R::Microsoft__CoreUI__IExportMessageLoopExtensions_Impl const s_Microsoft__CoreUI__IExportMessageLoopExtensions_Impl;
				static bool Delegate0(System::Delegate *,WakeRecord *);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct LoopTracker
			{
				bool IsRunning(UserAdapter *);
			};

			struct OffThreadReceiver
			{
				bool UpdateReceiveMode();
				virtual void Callback_OnDispatch();
				virtual void OnCancelled();
				virtual void OnDispose();
				void OnSourceHasEvents(OffThreadSource *,bool);
			};

			struct OffThreadReceiver$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static OffThreadReceiver * New(EventLoop *,InternalPriority);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct OffThreadSource
			{
				virtual void OnDispose();
				virtual void OnReceive();
				void SetReceiver(OffThreadReceiver *);
				void set_HasEvents(bool);
			};

			struct OffThreadSource$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static OffThreadSource * New(OffThreadReceiver *,System::Action *);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegisteredWait
			{
				bool ProcessWakeCompletion(WaitController *);
				bool TryCancel(bool &);
				static bool UnlinkUnstarted(RegisteredWait *,Cn::ParamRef<RegisteredWait>,Cn::ParamRef<RegisteredWait>);
				static void ProcessUnstarted(WaitController *,Cn::ParamRef<RegisteredWait>,Cn::ParamRef<RegisteredWait>,bool &);
				void Dispose();
				void QueueWakeCompletion(WaitController *,WakeRecord *);
				void ReleaseHandle();
				void _Construct(Support::Win32Handle,WaitCallback *,bool,bool);
			};

			struct RegisteredWait$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ThreadContext
			{
				HIDENTITY AllocateEndpointIdentity(Messaging::MessageEndpoint *,Messaging::CrossProcessReceivePortBase *);
				Messaging::MessagingResults AllocateThunkIdentity(unsigned __int64,HIDENTITY &);
				Services::ExternalThreadEndpoint * InitializeExternalThreadEndpoint(ExportEndpointHandler *);
				bool get_IsDispatchThread();
				static Identity::IdentityTable s_identityTable;
				static void InitializeClass(bool);
				static void ModuleInitialize(bool);
				void FreeHandle(HIDENTITY);
				void FreeHandle(HRESOURCE);
				void InternalDispose();
				void PrepareKeepAlive(void *);
				void SetHandleData(HIDENTITY,Messaging::MessageEndpoint *,Messaging::CrossProcessReceivePortBase *);
				void ThrowExceptionForIdentityTableResult(Messaging::MessagingResults);
				void TrackError(System::String *,System::Object *);
				void TrackError(System::String *,System::Object *,System::Object *);
				void TrackErrorWorker(System::Object *);
				void _Construct(bool,bool);
			};

			struct ThreadContext$R
			{
				struct Microsoft__CoreUI__ICustomDispose_Impl
				{
					virtual CustomDisposeFlags get_Flags(System::Object *);
				};

				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ThreadContext * New(bool,bool);
				static ThreadContext$R::Microsoft__CoreUI__ICustomDispose_Impl const s_Microsoft__CoreUI__ICustomDispose_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ThreadContext__Error
			{
				virtual System::String * ToString();
				void Track(System::Object *);
			};

			struct ThreadContext__Error$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct Timeout
			{
				bool CheckRepeat();
				virtual void OnFinalRelease(bool);
				void Microsoft__CoreUI__IExportMessageTimer__SetAbsolute(FILETIME *,__int64);
				void Microsoft__CoreUI__IExportMessageTimer__SetRelative(__int64,__int64);
				void Microsoft__CoreUI__IExportMessageTimer__set_RelativeDelayTicks(__int64);
				void Microsoft__CoreUI__IExportMessageTimer__set_RepeatingTicks(__int64);
				void SetRelative(__int64,__int64);
				void VerifyEditable();
			};

			struct Timeout$R
			{
				struct Microsoft__CoreUI__IExportMessageTimer_Impl
				{
					virtual __int64 get_RelativeDelayTicks(System::Object *);
					virtual __int64 get_RepeatingTicks(System::Object *);
					virtual bool get_IsActive(System::Object *);
					virtual bool get_IsRepeating(System::Object *);
					virtual void Cancel(System::Object *);
					virtual void SetAbsolute(System::Object *,FILETIME *,__int64);
					virtual void SetRelative(System::Object *,__int64,__int64);
					virtual void set_IsRepeating(System::Object *,bool);
					virtual void set_RelativeDelayTicks(System::Object *,__int64);
					virtual void set_RepeatingTicks(System::Object *,__int64);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static Timeout * New(TimeoutManager *);
				static Timeout$R::Microsoft__CoreUI__IExportMessageTimer_Impl const s_Microsoft__CoreUI__IExportMessageTimer_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct TimeoutHandler
			{
				void Invoke();
			};

			struct TimeoutHandler$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct TimeoutManager
			{
				Support::Win32Handle CreateTimer();
				bool ProcessListExpirationsWorker(Timeout *,Support::SkipList *);
				int System__Collections__IComparer__Compare(System::Object *,System::Object *);
				unsigned int BeginScheduleChange(Timeout *,bool);
				virtual void Callback_OnDispatch();
				virtual void OnDispose();
				void Cancel(Timeout *);
				void DisableTimer(bool);
				void PrepareForNewSessionAdapter();
				void ProcessCurrentExpirations(bool);
				void Schedule(Timeout *,bool);
				void ScheduleTimerForFutureExpiry(bool);
				void SetTimerDelay(bool,__int64);
				void TrackSystemTimeChanges(System::DateTime);
				void _Construct(EventLoop *);
			};

			struct TimeoutManager$R
			{
				struct System__Collections__IComparer_Impl
				{
					virtual int Compare(System::Object *,System::Object *,System::Object *);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static TimeoutManager$R::System__Collections__IComparer_Impl const s_System__Collections__IComparer_Impl;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,WaitStatus,Support::Win32Handle);
				static void Delegate1(System::Delegate *,WaitStatus,Support::Win32Handle);
				static void InitializeCppInstance(void *);
			};

			struct UserAdapter
			{
				WaitStatus Callback_WaitWorker(unsigned int,Support::Win32Handle *,unsigned int,WaitFlags,unsigned int &);
				bool DispatchNextUserQueueItem();
				bool ProcessPendingWaits();
				bool TestAndAgeUserQueueStatus();
				bool TryDeferYieldCheck();
				bool UserQueueStatusYieldCheck(InternalPriority,int);
				static bool IsCurrentThreadUserInitialized();
				static bool s_disabled;
				static bool s_userLoaded;
				static void EnsureSharedTebInitialized();
				static void OnScheduleUserDispatchFailure(void *,bool);
				static void ScheduleDispatch(InternalPriority,void *,void *,bool,bool);
				static void ScheduleInputPriorityUserDispatch(void *,bool);
				static void SchedulePostPriorityUserDispatch(void *);
				static void UninitializeSharedTeb();
				void Callback_HostModeRun(RunMode,bool);
				void Dispose();
				void DrainCoreMessagingQueue(UserAdapter__UserPriority,bool,System::IntPtr &);
				void EnsureUserDispatchScheduled();
				void EnsureUserDispatchScheduled(InternalPriority);
				void InitializeWindow(bool);
				void OnUserDispatch(bool,UserAdapter__UserPriority,System::IntPtr &);
				void ReschedulePendingDispatches(bool);
				void RunIntegratedLoop();
				void SetInterconnectSignaledNotification(bool);
				void UninitializeWindow();
				void UserYieldCheck(InternalPriority,int);
				void YieldToUser(InternalPriority);
			};

			struct UserAdapter$R
			{
				struct System__IDisposable_Impl
				{
					virtual void Dispose(System::Object *);
				};

				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static UserAdapter * New(bool,EventLoop *);
				static UserAdapter$R::System__IDisposable_Impl const s_System__IDisposable_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct WaitArray
			{
				Messaging::MessagingResults Callback_DoWait(unsigned int,Support::Win32Handle *,unsigned int,WaitFlags,bool,WakeRecord *);
				Messaging::MessagingResults Poll(WakeRecord *);
				WaitStatus Callback_WaitAny(Support::Win32Handle *,unsigned int,unsigned int,WaitFlags,bool,unsigned int &,System::IntPtr &);
				bool DoTargetedWaitWithContextLock(WaitController *,Support::Win32Handle,unsigned int);
				bool ProcessUnstartedWaits(WaitController *);
				bool Start(WaitController *,RegisteredWait *,Support::IoCompletionPort);
				static WaitStatus ConvertWaitResult(unsigned int,unsigned int,unsigned int &);
				void CleanUpRemovedWait(RegisteredWait *);
				void DrainMitWaits(WaitController *);
				void EnableBlockCloseHandle(bool);
				void EnqueueUnstartedWait(WaitController *,RegisteredWait *);
				void EnsureIocpInitialized(WaitController *);
				void Grow(unsigned int);
				void RegisterWait(WaitController *,Support::Win32Handle,WaitCallback *,bool);
				void Reset();
				void TransferWaitsToIocp(WaitController *,Support::IoCompletionPort,bool);
			};

			struct WaitArray$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct WaitCallback
			{
				void Invoke(WaitStatus,Support::Win32Handle);
			};

			struct WaitCallback$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct WaitController
			{
				bool DeliverCompletion(WakeRecord *);
				bool PeekForNewEvents(WakeRecord *,WakeRecordHandler *);
				bool get_ShouldBlockCloseHandle();
				static void InitClass(bool);
				virtual void Callback_OnDispatch();
				virtual void OnDispose();
				void Callback_DoGeneralWait(unsigned int,Support::Win32Handle *,unsigned int,WaitFlags,Cn::StrongRef<WakeRecord>,Cn::StrongRef<WakeRecordHandler>,bool);
				void DestroyWatchdogTimer();
				void OnEnterDispatchLoop(RunnablePriorityMask);
				void OnExitDispatchLoop();
				void PrepareWakeInfo(Cn::ParamRef<WakeRecord>,Cn::ParamRef<WakeRecordHandler>);
				void RegisterDispatchWatchdog(DispatchWatchdogCallback *,__int64);
				void RegisterWait(Support::Win32Handle,WaitCallback *,bool);
				void RegisterWatchdogTimer(DispatchWatchdogCallback *);
				void Reset();
				void RevokePriorityBoost();
				void SetWatchdogTimer(bool);
				void UnregisterDispatchWatchdog(DispatchWatchdogCallback *);
				void UnregisterWait(Support::Win32Handle,bool);
				void _Construct(EventLoop *);
				void set_PriorityBoost(ThreadPriority);
			};

			struct WaitController$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static bool Delegate1(System::Delegate *,WakeRecord *);
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *);
				static void InitializeCppInstance(void *);
			};

			struct WakeRecord
			{
				ThreadWakeReason get_Reason();
				void Clear();
				void InitFromStatus(RegisteredWait *,WaitStatus,Support::Win32Handle,unsigned int,unsigned int);
			};

			struct WakeRecord$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct WakeRecordHandler
			{
				bool Invoke(WakeRecord *);
			};

			struct WakeRecordHandler$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			__int64 UserAdapter_WindowProc(HWND__ *,unsigned int,unsigned __int64,__int64);
			int IndexOfWatchdogCallback(_TP_TIMER *);
			void AsyncSendMessage(HWND__ *,unsigned int,unsigned __int64,__int64);
			void ThreadContext_ThreadSignaledOrInterconnectAck(_TP_CALLBACK_INSTANCE *,void *,_TP_WAIT *,long);
			void TimerCallbackThunk(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *);
			void UserAdapter_DeferredGuiThreadInitCallback();
			void UserAdapter_DoWork(Dispatch::UserData *,Dispatch::UserAdapter__UserPriority,bool);
			void UserAdapter_InitializeClass(HINSTANCE__ *);
			void UserAdapter_OnGuiThreadInitCallback(tagCoreMessagingNotification,unsigned int,void *);
			void UserAdapter_ScheduleBackupTimer(HWND__ *,unsigned int);
		};

		struct DispatchGroup
		{
			virtual void OnCancelled();
			virtual void OnFinalRelease(bool);
		};

		struct DispatchGroup$R
		{
			struct Microsoft__CoreUI__IExportMessageGroup_Impl
			{
				virtual Dispatch::ExternalPriority get_Priority(System::Object *);
				virtual bool get_Enabled(System::Object *);
				virtual void set_Enabled(System::Object *,bool);
				virtual void set_Priority(System::Object *,Dispatch::ExternalPriority);
			};

			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static DispatchGroup$R::Microsoft__CoreUI__IExportMessageGroup_Impl const s_Microsoft__CoreUI__IExportMessageGroup_Impl;
			static short const * const s_rgReferenceFields;
		};

		struct DispatchGroupBatchEnableHandler
		{
			void Invoke(bool &);
		};

		struct DispatchGroupBatchEnableHandler$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct DispatchGroupHandler
		{
			void Invoke();
		};

		struct DispatchGroupHandler$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct DisposableObject
		{
			virtual void OnFinalRelease(bool);
			virtual void OnInitialExport();
			virtual ~DisposableObject();
			void Dispose();
		};

		struct DisposableObject$R
		{
			struct Cn__IExportInstance_Impl
			{
				virtual void OnFinalRelease(System::Object *,bool);
				virtual void OnInitialExport(System::Object *);
			};

			struct System__IDisposable_Impl
			{
				virtual void Dispose(System::Object *);
			};

			static Cn::TypeDefinition_66 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static DisposableObject$R::Cn__IExportInstance_Impl const s_Cn__IExportInstance_Impl;
			static DisposableObject$R::System__IDisposable_Impl const s_System__IDisposable_Impl;
		};

		namespace ETW
		{
			struct ETWTrace
			{
				static void InitializeClass(bool);
			};

		};

		struct ExportEndpointHandler
		{
			void Invoke(void *,int);
		};

		struct ExportEndpointHandler$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct ExternalEndpoint
		{
			virtual void Callback_OnMessageCore(Support::BufferInfo);
			virtual void OnDispose();
		};

		struct ExternalEndpoint$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static short const * const s_rgReferenceFields;
			static void InitializeCppInstance(void *);
		};

		struct ForeignException
		{
			void BackupFrames();
		};

		struct ForeignException$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct HENDPOINT
		{
			static HENDPOINT Invalid;
		};

		struct HIDENTITY$R
		{
			static Cn::TypeDefinition_66 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct ICallbackMessageConversationHost$R
		{
			static Cn::TypeDefinition_194 const s_defType;
		};

		struct ICallbackMessageConversationHost$X__CallbackAdapter
		{
			void OnIDFreed(unsigned int,unsigned int,void *);
			void OnItemMessage(unsigned int,unsigned int,void *,void *,unsigned int);
			void OnPeerConnected(unsigned int,unsigned int,unsigned int,void * *);
			void OnPeerDisconnected(unsigned int,void *,bool);
		};

		struct ICallbackMessageConversationHost$X__CallbackAdapter$R
		{
			struct Microsoft__CoreUI__ICallbackMessageConversationHost_Impl
			{
				virtual void OnIDFreed(System::Object *,unsigned int,unsigned int,void *);
				virtual void OnItemMessage(System::Object *,unsigned int,unsigned int,void *,void *,unsigned int);
				virtual void OnPeerConnected(System::Object *,unsigned int,unsigned int,unsigned int,void * *);
				virtual void OnPeerDisconnected(System::Object *,unsigned int,void *,bool);
			};

			static Cn::TypeDefinition_64 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static ICallbackMessageConversationHost$X__CallbackAdapter$R::Microsoft__CoreUI__ICallbackMessageConversationHost_Impl const s_Microsoft__CoreUI__ICallbackMessageConversationHost_Impl;
			static void InitializeCppInstance(void *);
		};

		struct ICallbackMessageSessionListener$R
		{
			static Cn::TypeDefinition_194 const s_defType;
		};

		struct ICallbackMessageSessionListener$X__CallbackAdapter
		{
			void ConnectionClosed(RoutingInfo &);
			void ConnectionCreated(RoutingInfo &);
		};

		struct ICallbackMessageSessionListener$X__CallbackAdapter$R
		{
			struct Microsoft__CoreUI__ICallbackMessageSessionListener_Impl
			{
				virtual void ConnectionClosed(System::Object *,RoutingInfo &);
				virtual void ConnectionCreated(System::Object *,RoutingInfo &);
			};

			static Cn::TypeDefinition_64 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static ICallbackMessageSessionListener$X__CallbackAdapter$R::Microsoft__CoreUI__ICallbackMessageSessionListener_Impl const s_Microsoft__CoreUI__ICallbackMessageSessionListener_Impl;
			static void InitializeCppInstance(void *);
		};

		struct ICallbackMessageSessionListener_1D$R
		{
			static Cn::TypeDefinition_4 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct ICustomDispose$R
		{
			static Cn::TypeDefinition_66 const s_defType;
		};

		struct IExportClientWindowIDManager$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportClientWindowIDManager$X__ExportAdapter
		{
			virtual long AllocateWindowID(int,WindowIDPropertyValue *,WindowID *);
			virtual long ClearWindowIDProperties(WindowID,int,WindowIDPropertyValue *);
			virtual long FreeWindowID(WindowID);
			virtual long GetWindowIDInfo(WindowID,WindowIDInfo *);
			virtual long GetWindowIDProperties(WindowID,int,WindowIDPropertyValue *,unsigned int *);
			virtual long SetWindowIDProperties(WindowID,int,WindowIDPropertyValue *);
		};

		struct IExportDispatcherQueueInterop$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportDispatcherQueueInterop$X__ExportAdapter
		{
			virtual long GetDispatcherQueue(System::IntPtr *);
			virtual long SetDispatcherQueue(System::IntPtr,bool);
			virtual long TryDeferInvoke(long (*)(void *),void *,Dispatch::ExternalPriority$C::Values,bool,bool *);
		};

		struct IExportMessageConversation$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportMessageConversation$X__ExportAdapter
		{
			virtual long AllocateItemForPeer(unsigned int,void *,unsigned int *);
			virtual long EnumerateItems(unsigned int,bool,bool,long (*)(void *,unsigned int,unsigned int,void *),void *);
			virtual long FlushItemDeletion(unsigned int,unsigned int,bool);
			virtual long GetDeferMessageDelivery(bool *);
			virtual long GetItem(unsigned int,unsigned int,void * *);
			virtual long RemoveItem(unsigned int,unsigned int,bool,System::IntPtr *);
			virtual long Send(unsigned int,unsigned int,void *,unsigned int);
			virtual long SetDeferMessageDelivery(bool);
			virtual long SetItemData(unsigned int,unsigned int,void *);
		};

		struct IExportMessageConversationServer$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportMessageConversationServer$X__ExportAdapter
		{
			virtual long AttachClient(unsigned int,unsigned int);
		};

		struct IExportMessageGroup$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportMessageGroup$X__ExportAdapter
		{
			virtual long GetEnabled(bool *);
			virtual long GetPriority(Dispatch::ExternalPriority$C::Values *);
			virtual long SetEnabled(bool);
			virtual long SetPriority(Dispatch::ExternalPriority$C::Values);
		};

		struct IExportMessageInfo$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportMessageInfo$X__ExportAdapter
		{
			virtual long GetCurrentSenderInfo(Messaging::SenderInfo *);
		};

		struct IExportMessageLoopExtensions$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportMessageLoopExtensions$X__ExportAdapter
		{
			virtual long AssumeLoopActive();
			virtual long CheckForNewWork(bool *);
			virtual long GetIsRunning(bool *);
			virtual long IgnoreWindowMessages();
			virtual long RegisterDispatchWatchdog(long (*)(void *,unsigned int),void *,__int64);
			virtual long Run(Dispatch::RunMode$C::Values);
			virtual long SetMitIocp(Support::Win32Handle);
			virtual long UnregisterDispatchWatchdog(long (*)(void *,unsigned int),void *);
			virtual long UrgentExit();
			virtual long Wait(unsigned int,Support::Win32Handle *,unsigned int,WaitFlags$C::Values,Dispatch::WaitStatus$C::Values *);
		};

		struct IExportMessagePort$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportMessagePort$X__ExportAdapter
		{
			virtual long GetReceivesHighPriorityMessages(bool *);
			virtual long SetReceivesHighPriorityMessages(bool);
		};

		struct IExportMessageRegistrar$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportMessageRegistrar$X__ExportAdapter
		{
			virtual long FindEndpoint(wchar_t const *,ExternalRegistrarScope$C::Values,HENDPOINT *);
			virtual long FindEndpointInfo(wchar_t const *,ExternalRegistrarScope$C::Values,RoutingInfo *);
			virtual long FindProcessEndpoint(wchar_t const *,unsigned int,HENDPOINT *);
			virtual long FindProcessEndpointTimeout(wchar_t const *,unsigned int,unsigned int,HENDPOINT *);
			virtual long PublishEndpoint(wchar_t const *,HENDPOINT,ExternalRegistrarScope$C::Values);
			virtual long RevokeEndpoint(wchar_t const *,ExternalRegistrarScope$C::Values);
		};

		struct IExportMessageSession
		{
			HENDPOINT CreateEndpoint(ExportEndpointHandler *);
			HENDPOINT CreateEndpoint(ExportEndpointHandler *,IExportMessagePort *);
			HENDPOINT OpenEndpoint(RoutingInfo &);
			HRESOURCE SendResource(HENDPOINT,void *,unsigned int,System::Action *);
			IExportMessageConversation * JoinConversationAsClient(System::String *,ICallbackMessageConversationHost *,unsigned int &);
			IExportMessageConversation * JoinConversationAsServer(System::String *,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
			IExportMessageConversation * JoinConversationAsServer(System::String *,System::String *,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
			IExportMessageGroup * CreateBatchAwareGroup(DispatchGroupBatchEnableHandler *,DispatchGroupHandler *);
			IExportMessageGroup * CreateGroup(DispatchGroupHandler *,DispatchGroupHandler *);
			IExportMessageInfo * get_MessageInfo();
			IExportMessageLoopExtensions * get_MessageLoopExtensions();
			IExportMessagePort * CreatePort(PSECURITY_DESCRIPTOR);
			IExportMessagePort * CreatePort(PSECURITY_DESCRIPTOR,System::String *);
			IExportMessagePort * GetMessagePort(HENDPOINT);
			IExportMessagePort * OpenPort(System::String *);
			IExportMessageRegistrar * get_MessageRegistrar();
			IExportMessageTimer * CreateTimer(Dispatch::TimeoutHandler *);
			IExportMessageTimerCoalescer * CreateTimerCoalescer();
			RoutingInfo GetEndpointInfo(HENDPOINT);
			void * SendInPlace(HENDPOINT,Dispatch::ExternalPriority,unsigned int);
			void * SendInPlace(HENDPOINT,unsigned int);
			void CancelSendInPlace(void *);
			void CloseEndpoint(HENDPOINT);
			void CloseEndpoint(HENDPOINT,CloseEndpointFlags);
			void CloseResource(HRESOURCE);
			void DeferInvoke(System::Action *,Dispatch::ExternalPriority);
			void DisconnectClient(unsigned int,unsigned int);
			void Exit();
			void OpenResource(HRESOURCE,void * &,unsigned int &);
			void RegisterDispatchCallback(Dispatch::DispatchCallback *);
			void RegisterDispatchCallback(Dispatch::DispatchCallback *,Dispatch::ThreadPriority);
			void RegisterWait(Support::Win32Handle,Dispatch::WaitCallback *);
			void RegisterWait(WaitRegistration,Support::Win32Handle,Dispatch::WaitCallback *);
			void Run();
			void Send(HENDPOINT,Dispatch::ExternalPriority,void *,unsigned int);
			void Send(HENDPOINT,void *,unsigned int);
			void UnregisterDispatchCallback(Dispatch::DispatchCallback *);
			void UnregisterWait(Support::Win32Handle);
			void UnregisterWait(WaitRegistration,Support::Win32Handle);
		};

		struct IExportMessageSession$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
			static void const * const * const s_rgLookup;
		};

		struct IExportMessageSession$X__ExportAdapter
		{
			virtual long CancelSendInPlace(void *);
			virtual long CloseEndpoint(HENDPOINT);
			virtual long CloseEndpoint(HENDPOINT,CloseEndpointFlags$C::Values);
			virtual long CloseResource(HRESOURCE$C::Values);
			virtual long CreateBatchAwareGroup(long (*)(void *,bool *),void *,long (*)(void *),void *,IExportMessageGroup$X__ExportAdapter * *);
			virtual long CreateEndpoint(long (*)(void *,void *,int),void *,HENDPOINT *);
			virtual long CreateEndpoint(long (*)(void *,void *,int),void *,IExportMessagePort$X__ExportAdapter *,HENDPOINT *);
			virtual long CreateGroup(long (*)(void *),void *,long (*)(void *),void *,IExportMessageGroup$X__ExportAdapter * *);
			virtual long CreatePort(PSECURITY_DESCRIPTOR,IExportMessagePort$X__ExportAdapter * *);
			virtual long CreatePort(PSECURITY_DESCRIPTOR,wchar_t const *,IExportMessagePort$X__ExportAdapter * *);
			virtual long CreateTimer(long (*)(void *),void *,IExportMessageTimer$X__ExportAdapter * *);
			virtual long CreateTimerCoalescer(IExportMessageTimerCoalescer$X__ExportAdapter * *);
			virtual long DeferInvoke(long (*)(void *),void *,Dispatch::ExternalPriority$C::Values);
			virtual long DisconnectClient(unsigned int,unsigned int);
			virtual long Exit();
			virtual long GetEndpointInfo(HENDPOINT,RoutingInfo *);
			virtual long GetMessageInfo(IExportMessageInfo$X__ExportAdapter * *);
			virtual long GetMessageLoopExtensions(IExportMessageLoopExtensions$X__ExportAdapter * *);
			virtual long GetMessagePort(HENDPOINT,IExportMessagePort$X__ExportAdapter * *);
			virtual long GetMessageRegistrar(IExportMessageRegistrar$X__ExportAdapter * *);
			virtual long GetPrivateInterfaceForCoreUIComponents(IExportMessageSessionPrivate$X__ExportAdapter * *);
			virtual long JoinConversationAsClient(wchar_t const *,ICallbackMessageConversationHost$X__ComVTable *,unsigned int *,IExportMessageConversation$X__ExportAdapter * *);
			virtual long JoinConversationAsServer(wchar_t const *,IExportMessagePort$X__ExportAdapter *,ConversationItemOwner$C::Values,ConversationServerStyle$C::Values,ConversationConnectionMode$C::Values,ICallbackMessageConversationHost$X__ComVTable *,unsigned int *,IExportMessageConversation$X__ExportAdapter * *);
			virtual long JoinConversationAsServer(wchar_t const *,wchar_t const *,IExportMessagePort$X__ExportAdapter *,ConversationItemOwner$C::Values,ConversationServerStyle$C::Values,ConversationConnectionMode$C::Values,ICallbackMessageConversationHost$X__ComVTable *,unsigned int *,IExportMessageConversation$X__ExportAdapter * *);
			virtual long OpenEndpoint(RoutingInfo *,HENDPOINT *);
			virtual long OpenPort(wchar_t const *,IExportMessagePort$X__ExportAdapter * *);
			virtual long OpenResource(HRESOURCE$C::Values,void * *,unsigned int *);
			virtual long RegisterDispatchCallback(long (*)(void *,bool,Dispatch::FILETIME *),void *);
			virtual long RegisterDispatchCallback(long (*)(void *,bool,Dispatch::FILETIME *),void *,Dispatch::ThreadPriority$C::Values);
			virtual long RegisterWait(Support::Win32Handle,long (*)(void *,Dispatch::WaitStatus$C::Values,Support::Win32Handle),void *);
			virtual long RegisterWait(WaitRegistration$C::Values,Support::Win32Handle,long (*)(void *,Dispatch::WaitStatus$C::Values,Support::Win32Handle),void *);
			virtual long Run();
			virtual long Send(HENDPOINT,Dispatch::ExternalPriority$C::Values,void *,unsigned int);
			virtual long Send(HENDPOINT,void *,unsigned int);
			virtual long SendInPlace(HENDPOINT,Dispatch::ExternalPriority$C::Values,unsigned int,void * *);
			virtual long SendInPlace(HENDPOINT,unsigned int,void * *);
			virtual long SendResource(HENDPOINT,void *,unsigned int,long (*)(void *),void *,HRESOURCE$C::Values *);
			virtual long UnregisterDispatchCallback(long (*)(void *,bool,Dispatch::FILETIME *),void *);
			virtual long UnregisterWait(Support::Win32Handle);
			virtual long UnregisterWait(WaitRegistration$C::Values,Support::Win32Handle);
		};

		struct IExportMessageSessionPrivate
		{
			HENDPOINT GetEndpoint(System::IntPtr);
			HENDPOINT GetTargetEndpoint(RoutingInfo &);
			IExportMessageConversation * JoinConversationAsClient(System::String *,MsgScopeID,ICallbackMessageConversationHost *,unsigned int &);
			IExportMessageConversation * JoinConversationAsServer(System::String *,MsgScopeID,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
			IExportMessageConversation * JoinConversationAsServer(System::String *,System::String *,MsgScopeID,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
			IExportMessagePort * GetMessagePort(HENDPOINT);
			RawHRESULT GetConnectionStatus(HENDPOINT);
			System::IntPtr RegisterCoreUIComponents(void *,ExportEndpointHandler *);
			bool IsReversePort(IExportMessagePort *);
			void * AllocateMessage(HENDPOINT,Dispatch::ExternalPriority,unsigned int,bool &);
			void AddListener(ICallbackMessageSessionListener *);
			void CloseEndpoint(System::IntPtr);
			void FlushImmediately(HENDPOINT);
			void FlushMessage(void *);
			void NotifyRemoteEndpointFreed(HENDPOINT,RoutingInfo &);
			void PingAndWait(HENDPOINT,void *,unsigned int);
			void QueryEndpointCounts(int &,int &);
			void RemoveListener(ICallbackMessageSessionListener *);
			void SetPendingPingResult(void *,unsigned int);
		};

		struct IExportMessageSessionPrivate$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
			static void const * const * const s_rgLookup;
		};

		struct IExportMessageSessionPrivate$X__ExportAdapter
		{
			virtual RawHRESULT$C::Values AllocateRemoteEndpoint(RoutingInfo *,RoutingInfo *,HENDPOINT *,HENDPOINT *);
			virtual RawHRESULT$C::Values EstablishConnection(RoutingInfo *,HENDPOINT *);
			virtual long AddListener(ICallbackMessageSessionListener$X__ComVTable *);
			virtual long AllocateMessage(HENDPOINT,Dispatch::ExternalPriority$C::Values,unsigned int,bool *,void * *);
			virtual long ClaimRemoteEndpoint(RoutingInfo *,RoutingInfo *,long (*)(void *,void *,int),void *,System::IntPtr *);
			virtual long CloseEndpoint(System::IntPtr);
			virtual long CreateEndpoint(long (*)(void *,void *,int),void *,IExportMessagePort$X__ExportAdapter *,System::IntPtr *);
			virtual long FlushImmediately(HENDPOINT);
			virtual long FlushMessage(void *);
			virtual long GetConnectionStatus(HENDPOINT,RawHRESULT$C::Values *);
			virtual long GetEndpoint(System::IntPtr,HENDPOINT *);
			virtual long GetEndpointData(HIDENTITY,System::IntPtr *);
			virtual long GetEndpointInfo(HENDPOINT,RoutingInfo *);
			virtual long GetMessagePort(HENDPOINT,IExportMessagePort$X__ExportAdapter * *);
			virtual long GetRoutingInfo(System::IntPtr,RoutingInfo *);
			virtual long GetTargetEndpoint(RoutingInfo *,HENDPOINT *);
			virtual long IsReversePort(IExportMessagePort$X__ExportAdapter *,bool *);
			virtual long JoinConversationAsClient(wchar_t const *,MsgScopeID,ICallbackMessageConversationHost$X__ComVTable *,unsigned int *,IExportMessageConversation$X__ExportAdapter * *);
			virtual long JoinConversationAsServer(wchar_t const *,MsgScopeID,IExportMessagePort$X__ExportAdapter *,ConversationItemOwner$C::Values,ConversationServerStyle$C::Values,ConversationConnectionMode$C::Values,ICallbackMessageConversationHost$X__ComVTable *,unsigned int *,IExportMessageConversation$X__ExportAdapter * *);
			virtual long JoinConversationAsServer(wchar_t const *,wchar_t const *,MsgScopeID,IExportMessagePort$X__ExportAdapter *,ConversationItemOwner$C::Values,ConversationServerStyle$C::Values,ConversationConnectionMode$C::Values,ICallbackMessageConversationHost$X__ComVTable *,unsigned int *,IExportMessageConversation$X__ExportAdapter * *);
			virtual long NotifyRemoteEndpointFreed(HENDPOINT,RoutingInfo *);
			virtual long PingAndWait(HENDPOINT,void *,unsigned int);
			virtual long QueryEndpointCounts(int *,int *);
			virtual long RegisterCoreUIComponents(void *,long (*)(void *,void *,int),void *,System::IntPtr *);
			virtual long RemoveListener(ICallbackMessageSessionListener$X__ComVTable *);
			virtual long Send(HENDPOINT,Dispatch::ExternalPriority$C::Values,void *,unsigned int);
			virtual long SetPendingPingResult(void *,unsigned int);
		};

		struct IExportMessageStream$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportMessageStream$X__CallbackAdapter
		{
			void Send(HENDPOINT,void *,unsigned int);
		};

		struct IExportMessageStream$X__CallbackAdapter$R
		{
			struct Microsoft__CoreUI__IExportMessageStream_Impl
			{
				virtual void Send(System::Object *,HENDPOINT,void *,unsigned int);
			};

			static Cn::TypeDefinition_64 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static IExportMessageStream$X__CallbackAdapter$R::Microsoft__CoreUI__IExportMessageStream_Impl const s_Microsoft__CoreUI__IExportMessageStream_Impl;
			static void InitializeCppInstance(void *);
		};

		struct IExportMessageStream$X__ExportAdapter
		{
			virtual long Send(HENDPOINT,void *,unsigned int);
		};

		struct IExportMessageTimer$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportMessageTimer$X__ExportAdapter
		{
			virtual long Cancel();
			virtual long GetIsActive(bool *);
			virtual long GetIsRepeating(bool *);
			virtual long GetRelativeDelayTicks(__int64 *);
			virtual long GetRepeatingTicks(__int64 *);
			virtual long SetAbsolute(Dispatch::FILETIME *,__int64);
			virtual long SetIsRepeating(bool);
			virtual long SetRelative(__int64,__int64);
			virtual long SetRelativeDelayTicks(__int64);
			virtual long SetRepeatingTicks(__int64);
		};

		struct IExportMessageTimerCoalescer$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportMessageTimerCoalescer$X__ExportAdapter
		{
			virtual long Cancel(__int64);
			virtual long Register(unsigned int,long (*)(void *,__int64),void *,__int64 *);
		};

		struct IExportSystemWindowIDManager$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportSystemWindowIDManager$X__ExportAdapter
		{
			virtual long AllocateWindowID(ProcessID$C::Values,ThreadID$C::Values,int,WindowIDPropertyValue *,WindowID *);
			virtual long FreeWindowID(WindowID);
			virtual long GetWindowIDInfo(WindowID,WindowIDInfo *);
			virtual long GetWindowIDProperties(WindowID,int,WindowIDPropertyValue *,unsigned int *);
		};

		struct IExportWindowValidator$R
		{
			static Cn::TypeDefinition_194 const s_defType;
			static void InitializeCppExport(void *);
		};

		struct IExportWindowValidator$X__CallbackAdapter
		{
			void ValidateWindowId(WindowID);
			void ValidateWindowIdAndOwner(WindowID,unsigned int);
		};

		struct IExportWindowValidator$X__CallbackAdapter$R
		{
			struct Microsoft__CoreUI__IExportWindowValidator_Impl
			{
				virtual void ValidateWindowId(System::Object *,WindowID);
				virtual void ValidateWindowIdAndOwner(System::Object *,WindowID,unsigned int);
			};

			static Cn::TypeDefinition_64 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static IExportWindowValidator$X__CallbackAdapter$R::Microsoft__CoreUI__IExportWindowValidator_Impl const s_Microsoft__CoreUI__IExportWindowValidator_Impl;
			static void InitializeCppInstance(void *);
		};

		struct IExportWindowValidator$X__ExportAdapter
		{
			virtual long ValidateWindowId(WindowID);
			virtual long ValidateWindowIdAndOwner(WindowID,unsigned int);
		};

		namespace Identity
		{
			struct HIDENTITYAllocator
			{
				Messaging::MessagingResults AllocateHIDENTITY(unsigned int,HIDENTITY &);
				void FreeHIDENTITY(unsigned int);
				void Initialize(IdentityTable__Configuration);
				~HIDENTITYAllocator();
			};

			struct IIdentityObject
			{
				void HandleFreed(HandleFreeReason);
			};

			struct IIdentityObject$R
			{
				static Cn::TypeDefinition_64 const s_defType;
				static void const * const * const s_rgLookup;
			};

			struct IdentityEntry
			{
				IIdentityObject * get_HandleObject();
				void set_HandleObject(IIdentityObject *);
			};

			class IdentityGroup
			{
				Messaging::MessagingResults AllocateThunkHandle(unsigned int,unsigned int,unsigned __int64);
				Messaging::MessagingResults IdentityEntryFromHandle(HIDENTITY,IdentityEntry * *);
				Messaging::MessagingResults IdentityEntryFromHandle(unsigned int,unsigned int,IdentityEntry * *);
				static void EnumHandlesHandler(void *,unsigned int,IdentityEntry *);
				static void NotifyGroupFreedForItem(void *,unsigned int,IdentityEntry *);
			public:
				Messaging::MessagingResults FreeHandle(unsigned int,unsigned int);
				static void Create(IdentityGroup * *);
				unsigned __int64 GetTargetNL(HIDENTITY,unsigned int *,bool *,bool *);
				unsigned __int64 GetTargetNL(unsigned __int64,unsigned int,unsigned int,bool *,bool *);
			};

			struct IdentityGroupEntry
			{
				IdentityGroupEntry();
				~IdentityGroupEntry();
			};

			class IdentityGroupManager
			{
				struct FreezeValidHandleMemory
				{
					FreezeValidHandleMemory(IdentityGroupManager *);
					~FreezeValidHandleMemory();
				};

				IdentityGroupManager();
				static void NotifyTableDestroyedForEntry(void *,unsigned int,IdentityGroupEntry *);
				static void operator delete(void *);
				void FreeDeletedGroups(IdentityGroup *);
				void RemoveGroupWorker(IdentityGroupEntry *);
				void ResumeMemoryDeallocationNL();
			protected:
				virtual void NotifyDestroy();
			public:
				Messaging::MessagingResults GroupForID(IdentityTableView *,unsigned int,bool,IdentityGroup * *);
			};

			struct IdentityTable
			{
				unsigned __int64 GetTargetNL(unsigned int,HIDENTITY,bool &,bool &);
				unsigned __int64 GetTargetNL(unsigned int,HIDENTITY,unsigned int &,bool &,bool &);
				unsigned __int64 GetTargetNL(unsigned int,WindowID,bool &,bool &);
				unsigned __int64 GetTargetNLWorker(unsigned int,unsigned __int64,unsigned int,unsigned int,unsigned int,bool &,bool &);
				void Initialize(IdentityTable__Configuration);
				void Uninitialize();
			};

			struct IdentityTableView
			{
				IIdentityObject * GetHandleData(HIDENTITY);
				IIdentityObject * GetHandleData(HIDENTITY,bool &);
				Messaging::MessagingResults AllocateHandle(HIDENTITY);
				Messaging::MessagingResults AllocateThunkHandle(HIDENTITY,unsigned __int64);
				Messaging::MessagingResults AllocateThunkHandle(WindowID,unsigned __int64);
				Messaging::MessagingResults ClearThunkTarget(HIDENTITY);
				Messaging::MessagingResults FreeHandle(HIDENTITY);
				Messaging::MessagingResults FreeHandleWorker(unsigned int,unsigned int,unsigned int);
				Messaging::MessagingResults SetHandleData(HIDENTITY,IIdentityObject *,unsigned int);
				virtual void OnDispose();
				void EnumerateHandles(unsigned int,IdentityTableView__EnumerateHandlesCallback *);
				void FreeGroup(unsigned int);
				void OnDisposeWorker();
				void ReserveGroup(unsigned int);
			};

			struct IdentityTableView$R
			{
				static Cn::TypeDefinition_66 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static IdentityTableView * New(IdentityTable);
				static void InitializeCppInstance(void *);
			};

			struct IdentityTableView__EnumerateHandlesCallback
			{
				void Invoke(unsigned __int64,IIdentityObject *,unsigned __int64,bool);
			};

			struct IdentityTableView__EnumerateHandlesCallback$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

		};

		namespace Messaging
		{
			struct AlpcClientSender
			{
				MessagingResults WaitForConnection(unsigned int);
				Support::Win32Handle get_WaitHandle();
				bool Callback_ProcessIncoming();
				static MessagingResults Connect(Connection *,AlpcSendMessageAdapter *,unsigned int,Cn::ParamRef<AlpcClientSender>);
				static void Callback_CleanupDisconnectedClient(System::Object *);
				static void Callback_OnConnectionCompleted(System::Object *,bool);
				virtual MessagingResults PingAndWaitWorker(void *,unsigned int);
				virtual MessagingResults WaitForPendingConnection(unsigned int,bool);
				virtual bool get_HasPendingBatches();
				virtual void OnDispose();
				virtual void PostBuffersWorker(Buffering::BufferSet *,bool);
				void Callback_ProcessBuffer(void *,int,unsigned int);
				void CloseAlpcPort();
				void InstallYieldCheckHandler(Dispatch::ThreadContext *);
				void OnConnectionCompleted(bool);
				void OnServerDisconnected();
			};

			struct AlpcClientSender$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,Dispatch::WaitStatus,Support::Win32Handle);
				static void Delegate1(System::Delegate *);
				static void Delegate2(System::Delegate *);
				static void Delegate3(System::Delegate *,System::Object *,bool);
				static void Delegate4(System::Delegate *,System::Object *);
				static void InitializeCppInstance(void *);
				static void UninitializeType();
			};

			struct AlpcClientState
			{
				static AlpcClientState * FromHandle(System::IntPtr);
				virtual MessagingResults PingAndWaitWorker(void *,unsigned int);
				virtual MessagingResults WaitForPendingConnection(unsigned int,bool);
				virtual bool get_HasPendingBatches();
				virtual void OnDispose();
				virtual void PostBuffersWorker(Buffering::BufferSet *,bool);
				void OnConnectionCompleted(CrossProcessReceivePort__AlpcReceiveSource *,System::IntPtr);
			};

			struct AlpcClientState$R
			{
				static AlpcClientState * New(CrossProcessReceivePort__AlpcReceiveSource *,bool,unsigned int,unsigned int,unsigned int);
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,System::Object *);
				static void InitializeCppInstance(void *);
			};

			struct AlpcClientThunk
			{
				virtual long BatchProcessed(unsigned long);
				virtual long Callback_ProcessAsynchronousBuffer(IAlpcConnection *,void *,unsigned long,void const *,int);
				virtual long InvalidBufferReceived(void *,unsigned long);
				virtual long OnConnectionCompleted(IAlpcClientConnection *,bool);
				virtual long OnServerDisconnected(IAlpcClientConnection *);
				virtual long ProcessReply(IAlpcClientConnection *,void const *,int);
			};

			struct AlpcSendMessageAdapter
			{
				virtual Buffering::IBufferAllocator * GetResourceAllocator(Connection *);
				virtual MessageStream * GetStream(Connection *,FlushPolicy,Dispatch::ExternalPriority);
				virtual MessagingResults AttachConnection(Connection *,unsigned int &,unsigned int,Cn::ParamRef<System::Object>);
				virtual MessagingResults PingAndWait(Connection *,void *,unsigned int);
				virtual void BatchedFlush(MessageBatchFlusher *,MessageStream *);
				virtual void DetachConnection(Connection *,Cn::ParamRef<System::Object>);
				virtual void PrepareToDetachConnection(Connection *,Cn::ParamRef<System::Object>);
				virtual void ReleaseStream(MessageStream *);
				virtual void UnbatchedFlush(Connection *,MessageStream *);
				void FlushStream(Connection *,MessageStream *);
			};

			struct AlpcSendMessageAdapter$R
			{
				static AlpcSendMessageAdapter * New(MessageSession *);
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct AlpcSender
			{
				bool PostBuffers(Buffering::BufferSet *,bool);
				static void ReverseBufferSetList(Cn::ParamRef<Buffering::BufferSet>);
				virtual void OnDispose();
				void PostPendingBuffers();
				void RetirePendingBufferSets();
			};

			struct AlpcSender$R
			{
				struct Microsoft__CoreUI__Resources__ITrackableResource_Impl
				{
					virtual System::Object * get_TrackerData(System::Object *);
					virtual void OnResourceRetired(System::Object *);
					virtual void set_TrackerData(System::Object *,System::Object *);
				};

				static AlpcSender$R::Microsoft__CoreUI__Resources__ITrackableResource_Impl const s_Microsoft__CoreUI__Resources__ITrackableResource_Impl;
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
			};

			struct AlpcServerThunk
			{
				virtual long AcceptConnection(bool,unsigned long,unsigned long,void *,void *,void * *,bool *);
				virtual long BatchProcessed(unsigned long);
				virtual long Callback_ProcessAsynchronousBuffer(IAlpcConnection *,void *,unsigned long,void const *,int);
				virtual long InvalidBufferReceived(void *,unsigned long);
				virtual long OnClientDisconnected(void *,unsigned long,void *);
				virtual long ProcessSynchronousCall(bool,IAlpcServerConnection *,void *,unsigned long,void *,void const *,int);
			};

			struct AnonymousStream
			{
				virtual long QueryInterface(Cn::Com::IID const *,void * *);
				virtual long Send(HENDPOINT,void *,unsigned int);
				virtual unsigned int AddRef();
				virtual unsigned int Release();
			};

			struct ConnectedClient$R
			{
				static Cn::TypeDefinition_64 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct ConnectedClient__Boxed
			{
				virtual int GetHashCode();
			};

			struct Connection
			{
				Buffering::IBufferAllocator * get_ResourceAllocator();
				CrossProcessReceivePortBase * get_LocalPort();
				HIDENTITY EndpointToIdentity(HENDPOINT);
				MessageStream * GetStream(Dispatch::ExternalPriority,bool);
				MessagingResults AllocateRemoteHandle(HIDENTITY &);
				Resources::ResourceTracker * get_ResourceTracker();
				Resources::ResourceTracker * get_SharedMappingTracker();
				bool CompleteInitialization(MessageSession *,unsigned int,unsigned int,bool,HIDENTITY,HIDENTITY,unsigned int,System::Guid,System::Guid);
				bool Initialize(MessageSession *,MessageAdapter *,unsigned int,unsigned int,bool,unsigned int,System::Guid);
				virtual void OnDispose();
				void CancelQueuedMessages();
				void CreateReverseConnectionPort();
				void FlushNow();
				void FreeRemoteHandle(HIDENTITY,bool);
				void InitializeZombieConnection(MessageSession *,MessageAdapter *,unsigned int,unsigned int,bool,unsigned int,System::Guid);
			};

			struct Connection$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,bool);
				static void Delegate1(System::Delegate *,unsigned __int64,Identity::IIdentityObject *,unsigned __int64,bool);
				static void InitializeCppInstance(void *);
			};

			struct ConnectionID
			{
				bool Equals(ConnectionID);
			};

			struct ConnectionID$R
			{
				static Cn::TypeDefinition_64 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct ConnectionID__Boxed
			{
				virtual bool Equals(System::Object *);
				virtual int GetHashCode();
			};

			struct Connection_1D
			{
				Connection * _SetElement(int,Connection *);
			};

			struct Connection_1D$R
			{
				static Cn::TypeDefinition_4 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct CrossProcessReceivePort
			{
				MessagingResults Publish(Dispatch::ThreadContext *,System::String *);
				virtual System::Guid get_ID();
				virtual System::IntPtr get_AlpcConnection();
				virtual bool get_ReceivesHighPriorityMessages();
				virtual void OnDispose();
				virtual void OnFinalUsage();
				virtual void ValidateIdentityGroup(unsigned int,unsigned int,unsigned int);
				virtual void set_ReceivesHighPriorityMessages(bool);
				void _Construct(System::Guid,System::IntPtr,MessageSession *,Dispatch::EventLoop *);
			};

			struct CrossProcessReceivePort$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *);
				static void InitializeCppInstance(void *);
			};

			struct CrossProcessReceivePortBase
			{
				static void SetPendingPingResult(void *,unsigned int);
				virtual void OnDispose();
				void EndMessageDispatch();
				void Initialize(Dispatch::ThreadContext *,System::Guid &);
			};

			struct CrossProcessReceivePortBase$R
			{
				struct Microsoft__CoreUI__IExportMessagePort_Impl
				{
					virtual bool get_ReceivesHighPriorityMessages(System::Object *);
					virtual void set_ReceivesHighPriorityMessages(System::Object *,bool);
				};

				static Cn::TypeDefinition_64 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static CrossProcessReceivePortBase$R::Microsoft__CoreUI__IExportMessagePort_Impl const s_Microsoft__CoreUI__IExportMessagePort_Impl;
			};

			struct CrossProcessReceivePort__AlpcReceiveSource
			{
				AlpcClientState * CreateClientState(unsigned int,unsigned int,bool);
				AlpcClientState * FindConnectedClient(unsigned int,unsigned int);
				AlpcClientState * GetClientStateForReverseConnection(unsigned int,unsigned int);
				Support::Win32Handle get_WaitHandle();
				bool AcceptConnection(unsigned int,unsigned int,System::UIntPtr,System::IntPtr,System::IntPtr &);
				virtual void OnDispose();
				virtual void OnReceive();
				void Callback_ProcessBuffer(void *,int,System::IntPtr,unsigned int);
				void DisconnectClient(System::IntPtr);
				void DisconnectClient(unsigned int,unsigned int);
				void _Construct(CrossProcessReceivePort *,System::Guid,System::IntPtr,MessageSession *,Dispatch::EventLoop *);
			};

			struct CrossProcessReceivePort__AlpcReceiveSource$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,Dispatch::WaitStatus,Support::Win32Handle);
				static void Delegate1(System::Delegate *);
				static void Delegate2(System::Delegate *,unsigned int,unsigned int);
				static void InitializeCppInstance(void *);
			};

			struct DeferredMessagePool
			{
				CrossProcessReceivePortBase * get_Port();
				DeferredMessagePool__MessageInfoRun * AdvanceOutgoingInfos();
				bool CompleteIncomingBufferSet();
				bool MoveNext();
				bool get_IsEmpty();
				static Dispatch::OffThreadReceiver * GetOffThreadReceiver(MessageSession *,CrossProcessReceivePortBase *);
				virtual void OnDispose();
				virtual void OnReceive();
				void AttachEndpoint(MessageEndpoint *);
				void Callback_OnMessage(System::Action__Microsoft_CoreUI_Support_BufferInfo *,Support::BufferInfo);
				void _Construct(MessageSession *);
				void set_DeferMessageDelivery(bool);
			};

			struct DeferredMessagePool$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,System::Action__Microsoft_CoreUI_Support_BufferInfo *,Support::BufferInfo);
				static void Delegate1(System::Delegate *);
				static void InitializeCppInstance(void *);
			};

			struct DeferredMessagePool__MessageInfoRunEnumerator
			{
				Support::BufferInfo get_Current();
			};

			struct EndpointValidationOptions
			{
				void RaiseError();
			};

			struct InterconnectMessageAdapter
			{
				virtual Buffering::IBufferAllocator * GetResourceAllocator(Connection *);
				virtual MessageStream * GetStream(Connection *,FlushPolicy,Dispatch::ExternalPriority);
				virtual MessagingResults AttachConnection(Connection *,unsigned int &,unsigned int,Cn::ParamRef<System::Object>);
				virtual MessagingResults PingAndWait(Connection *,void *,unsigned int);
				virtual void AllSharedMappingsReleased(System::Object *);
				virtual void BatchedFlush(MessageBatchFlusher *,MessageStream *);
				virtual void CompleteConnection(Connection *,System::Object *);
				virtual void DetachConnection(Connection *,Cn::ParamRef<System::Object>);
				virtual void OnDispose();
				virtual void PrepareToDetachConnection(Connection *,Cn::ParamRef<System::Object>);
				virtual void ReleaseStream(MessageStream *);
				virtual void UnbatchedFlush(Connection *,MessageStream *);
				void Cn__Threading__IInterconnectBufferHandler__Callback_ReceiveBuffer(void *,int,Cn::Threading::InterconnectBufferFlags,unsigned int,unsigned int,unsigned int);
				void FlushStream(Connection *,MessageStream *);
				void GetPingReply(unsigned int,unsigned int,System::IntPtr,unsigned int,Support::Win32Handle);
				void ScheduleReceiveIfNeeded();
				void SetPendingPingResult(void *,unsigned int);
			};

			struct InterconnectMessageAdapter$R
			{
				struct Cn__Threading__IInterconnectBufferHandler_Impl
				{
					virtual void BufferMemoryCommitted(System::Object *,unsigned int);
					virtual void Callback_ReceiveBuffer(System::Object *,void *,int,Cn::Threading::InterconnectBufferFlags,unsigned int,unsigned int,unsigned int);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static InterconnectMessageAdapter * New(MessageSession *);
				static InterconnectMessageAdapter$R::Cn__Threading__IInterconnectBufferHandler_Impl const s_Cn__Threading__IInterconnectBufferHandler_Impl;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *);
				static void Delegate1(System::Delegate *);
				static void InitializeCppInstance(void *);
			};

			struct InterconnectMessageAdapter__ClientState$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct LocalMessageAdapter
			{
				virtual Buffering::IBufferAllocator * GetResourceAllocator(Connection *);
				virtual MessageStream * GetStream(Connection *,FlushPolicy,Dispatch::ExternalPriority);
				virtual MessagingResults PingAndWait(Connection *,void *,unsigned int);
				virtual void BatchedFlush(MessageBatchFlusher *,MessageStream *);
				virtual void Callback_ProjectResourceView(Connection *,HRESOURCE,Support::BufferInfo,Resources::ResourceType,unsigned int);
				virtual void CompleteConnection(Connection *,System::Object *);
				virtual void DetachConnection(Connection *,Cn::ParamRef<System::Object>);
				virtual void NotifyPendingSends(MessageStream *);
				virtual void NotifyResourceViewRetired(Connection *,unsigned int);
				virtual void OnDispose();
				virtual void OutOfBandFlush(Connection *,MessageStream *);
				virtual void UnbatchedFlush(Connection *,MessageStream *);
				void Callback_OnDispatch();
				void Reset();
			};

			struct LocalMessageAdapter$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static LocalMessageAdapter * New(MessageSession *);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct LocalMessageAdapter__LocalDispatchItem
			{
				virtual void Callback_OnDispatch();
			};

			struct LocalMessageAdapter__LocalDispatchItem$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct LocalMessageEnumerator
			{
				bool MoveNext();
				virtual void OnDispose();
			};

			struct LocalMessageEnumerator$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct LocalMessageEnumerator_1D
			{
				LocalMessageEnumerator * _SetElement(int,LocalMessageEnumerator *);
			};

			struct LocalMessageEnumerator_1D$R
			{
				static Cn::TypeDefinition_4 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct MessageAdapter
			{
				virtual MessagingResults AttachConnection(Connection *,unsigned int &,unsigned int,Cn::ParamRef<System::Object>);
				virtual void AllSharedMappingsReleased(System::Object *);
				virtual void Callback_ProjectResourceView(Connection *,HRESOURCE,Support::BufferInfo,Resources::ResourceType,unsigned int);
				virtual void CompleteConnection(Connection *,System::Object *);
				virtual void NotifyPendingSends(MessageStream *);
				virtual void NotifyResourceViewRetired(Connection *,unsigned int);
				virtual void NotifyStreamDisposed(MessageStream *);
				virtual void OutOfBandFlush(Connection *,MessageStream *);
				virtual void PrepareToDetachConnection(Connection *,Cn::ParamRef<System::Object>);
				virtual void ReleaseStream(MessageStream *);
			};

			struct MessageAdapter$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
			};

			struct MessageBatchFlusher
			{
				virtual void Callback_OnDispatch();
				void FlushPendingStreams();
				void RevokeFlush(MessageStream *);
			};

			struct MessageBatchFlusher$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static MessageBatchFlusher * New(Dispatch::Dispatcher *,Dispatch::InternalPriority);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct MessageBatchFlusher_1D$R
			{
				static Cn::TypeDefinition_4 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct MessageBufferEnumerator
			{
				Support::BufferInfo get_Current();
				bool MoveNext();
			};

			struct MessageEndpoint
			{
				RoutingInfo GetRoutingInfo();
				System::Guid GetBoundConnectionID();
				virtual void OnDispose();
				void InitializeEndpoint(System::Object *,Dispatch::ThreadContext *,CrossProcessReceivePortBase *);
				void InitializeEndpoint(System::Object *,Dispatch::ThreadContext *,HIDENTITY,CrossProcessReceivePortBase *);
				void RebindPort(CrossProcessReceivePortBase *);
				void ReleasePort();
				void SetMessageHandler(MessageEndpoint__MessageHandler *);
			};

			struct MessageEndpoint$R
			{
				struct Microsoft__CoreUI__Identity__IIdentityObject_Impl
				{
					virtual void HandleFreed(System::Object *,Identity::HandleFreeReason);
				};

				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static MessageEndpoint$R::Microsoft__CoreUI__Identity__IIdentityObject_Impl const s_Microsoft__CoreUI__Identity__IIdentityObject_Impl;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,Support::BufferInfo);
			};

			struct MessageEndpoint__MessageHandler
			{
				void Invoke(System::Action__Microsoft_CoreUI_Support_BufferInfo *,Support::BufferInfo);
			};

			struct MessageEndpoint__MessageHandler$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct MessageInfo
			{
				SenderInfo Microsoft__CoreUI__IExportMessageInfo__get_CurrentSenderInfo();
			};

			struct MessageInfo$R
			{
				struct Microsoft__CoreUI__IExportMessageInfo_Impl
				{
					virtual SenderInfo get_CurrentSenderInfo(System::Object *);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static MessageInfo$R::Microsoft__CoreUI__IExportMessageInfo_Impl const s_Microsoft__CoreUI__IExportMessageInfo_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct MessageSession
			{
				Connection * CreateConnection(bool,unsigned int,RoutingInfo &);
				Connection * GetConnection(HENDPOINT,EndpointValidationOptions,bool,HIDENTITY &);
				Connection * GetOrCreateConnection(bool,unsigned int,RoutingInfo &);
				Connection * TryGetConnection(RoutingInfo &);
				CrossProcessReceivePort * CreateCrossProcessReceivePortWorker(System::IntPtr,System::String *);
				CrossProcessReceivePort * FindCrossProcessReceivePort(System::Guid &);
				ExternalEndpoint * CreateEndpoint(ExportEndpointHandler *,IExportMessagePort *);
				HENDPOINT GetTargetEndpoint(RoutingInfo &);
				HRESOURCE Callback_SendResource(HENDPOINT,Support::BufferInfo,System::Action *);
				HRESOURCE Microsoft__CoreUI__IExportMessageSession__SendResource(HENDPOINT,void *,unsigned int,System::Action *);
				IExportMessageConversation * JoinConversationAsClientWorker(System::String *,Registrar::ScopeID,ICallbackMessageConversationHost *,unsigned int &);
				IExportMessageConversation * JoinConversationAsServerWorker(System::String *,System::String *,Registrar::ScopeID,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
				IExportMessageConversation * Microsoft__CoreUI__IExportMessageSessionPrivate__JoinConversationAsServer(System::String *,MsgScopeID,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
				IExportMessageConversation * Microsoft__CoreUI__IExportMessageSessionPrivate__JoinConversationAsServer(System::String *,System::String *,MsgScopeID,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
				IExportMessageConversation * Microsoft__CoreUI__IExportMessageSession__JoinConversationAsServer(System::String *,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
				IExportMessageConversation * Microsoft__CoreUI__IExportMessageSession__JoinConversationAsServer(System::String *,System::String *,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
				IExportMessagePort * GetMessagePortWorker(HENDPOINT,EndpointValidationOptions);
				IExportMessagePort * Microsoft__CoreUI__IExportMessageSession__OpenPort(System::String *);
				MessageBatchFlusher * GetBatchFlusherForStream(MessageStream *,bool);
				MessagingResults CancelMessage(void *);
				MessagingResults EnsureConnection(RoutingInfo &,unsigned int,HENDPOINT &);
				MessagingResults OpenEndpoint(RoutingInfo &,unsigned int,HENDPOINT &);
				MessagingResults OpenResource(HRESOURCE,Support::BufferInfo &);
				RawHRESULT Microsoft__CoreUI__IExportMessageSessionPrivate__AllocateRemoteEndpoint(RoutingInfo &,RoutingInfo &,HENDPOINT &,HENDPOINT &);
				RoutingInfo GetEndpointInfoWorker(HENDPOINT,EndpointValidationOptions,bool &);
				RoutingInfo RoutingInfoFromConnectionID(unsigned int,EndpointValidationOptions);
				System::IntPtr Microsoft__CoreUI__IExportMessageSessionPrivate__ClaimRemoteEndpoint(RoutingInfo &,RoutingInfo &,ExportEndpointHandler *);
				static System::String * GenerateFullNtObjectName(System::Guid);
				static void WaitOnHandleCollection(Support::Win32Handle *,unsigned int);
				unsigned int Callback_DeliverMessageBatch(MessageBufferEnumerator,unsigned int,unsigned int,bool,Cn::StrongRef<CrossProcessReceivePortBase>);
				virtual void OnDispose();
				virtual void OnFinalRelease(bool);
				virtual void OnInitialExport();
				void * AllocateMessage(HENDPOINT,bool,Dispatch::ExternalPriority,unsigned int,Dispatch::FlushMode,bool &);
				void * AllocateMessageOnStream(HIDENTITY,unsigned int,MessageStream *);
				void * Microsoft__CoreUI__IExportMessageSession__SendInPlace(HENDPOINT,unsigned int);
				void BatchCompleted();
				void Callback_CloseConnection(Connection *,bool);
				void Callback_DeliverMessage(Support::BufferInfo,unsigned int,unsigned int,bool,Cn::StrongRef<CrossProcessReceivePortBase>);
				void Callback_DisconnectClientWorker();
				void Callback_ShutdownCoreUIComponents();
				void Callback_StoreCoreUIComponents(void *);
				void CheckHighPriorityPorts();
				void CheckShuttingDown();
				void CloseConnections();
				void CloseEndpointWorker(HENDPOINT,CloseEndpointFlags);
				void DeferInvokeInternal(System::Action *,Dispatch::ExternalPriority);
				void DisconnectClient(unsigned int,unsigned int);
				void EnsurePendingAlpcMessagesReceived();
				void FlushMessage(void *);
				void FlushPendingStreams(bool);
				void Microsoft__CoreUI__IExportDispatcherQueueInterop__TryDeferInvoke(System::Action *,Dispatch::ExternalPriority,bool,bool &);
				void Microsoft__CoreUI__IExportMessageSessionPrivate__CloseEndpoint(System::IntPtr);
				void Microsoft__CoreUI__IExportMessageSessionPrivate__RemoveListener(ICallbackMessageSessionListener *);
				void ProcessPendingAlpcConnections();
				void RegisterDispatchCallbackCommon(Dispatch::DispatchCallback *,Dispatch::ThreadPriority);
				void RevokeAutoFlush(MessageStream *);
				void SendCommon(HENDPOINT,Dispatch::ExternalPriority,void *,unsigned int,Dispatch::FlushMode,bool);
				void ValidateCreateGroup(System::Delegate *,DispatchGroupHandler *);
				void ValidateCurrentMessageIsInProc();
				void ValidateIdentityGroupForCurrentMessage(unsigned int);
				void ValidateRegistrationFlags(WaitRegistration);
				void WaitForAcksAndDisableInterconnect();
				void _Construct(System::Object *,Dispatch::ThreadContext *,bool);
			};

			struct MessageSession$R
			{
				struct Microsoft__CoreUI__IExportDispatcherQueueInterop_Impl
				{
					virtual void GetDispatcherQueue(System::Object *,System::IntPtr &);
					virtual void SetDispatcherQueue(System::Object *,System::IntPtr,bool);
					virtual void TryDeferInvoke(System::Object *,System::Action *,Dispatch::ExternalPriority,bool,bool &);
				};

				struct Microsoft__CoreUI__IExportMessageSessionPrivate_Impl
				{
					virtual HENDPOINT GetEndpoint(System::Object *,System::IntPtr);
					virtual HENDPOINT GetTargetEndpoint(System::Object *,RoutingInfo &);
					virtual IExportMessageConversation * JoinConversationAsClient(System::Object *,System::String *,MsgScopeID,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessageConversation * JoinConversationAsServer(System::Object *,System::String *,MsgScopeID,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessageConversation * JoinConversationAsServer(System::Object *,System::String *,System::String *,MsgScopeID,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessagePort * GetMessagePort(System::Object *,HENDPOINT);
					virtual RawHRESULT AllocateRemoteEndpoint(System::Object *,RoutingInfo &,RoutingInfo &,HENDPOINT &,HENDPOINT &);
					virtual RawHRESULT EstablishConnection(System::Object *,RoutingInfo &,HENDPOINT &);
					virtual RawHRESULT GetConnectionStatus(System::Object *,HENDPOINT);
					virtual RoutingInfo GetEndpointInfo(System::Object *,HENDPOINT);
					virtual RoutingInfo GetRoutingInfo(System::Object *,System::IntPtr);
					virtual System::IntPtr ClaimRemoteEndpoint(System::Object *,RoutingInfo &,RoutingInfo &,ExportEndpointHandler *);
					virtual System::IntPtr CreateEndpoint(System::Object *,ExportEndpointHandler *,IExportMessagePort *);
					virtual System::IntPtr GetEndpointData(System::Object *,HIDENTITY);
					virtual System::IntPtr RegisterCoreUIComponents(System::Object *,void *,ExportEndpointHandler *);
					virtual bool IsReversePort(System::Object *,IExportMessagePort *);
					virtual void * AllocateMessage(System::Object *,HENDPOINT,Dispatch::ExternalPriority,unsigned int,bool &);
					virtual void AddListener(System::Object *,ICallbackMessageSessionListener *);
					virtual void CloseEndpoint(System::Object *,System::IntPtr);
					virtual void FlushImmediately(System::Object *,HENDPOINT);
					virtual void FlushMessage(System::Object *,void *);
					virtual void NotifyRemoteEndpointFreed(System::Object *,HENDPOINT,RoutingInfo &);
					virtual void PingAndWait(System::Object *,HENDPOINT,void *,unsigned int);
					virtual void QueryEndpointCounts(System::Object *,int &,int &);
					virtual void RemoveListener(System::Object *,ICallbackMessageSessionListener *);
					virtual void Send(System::Object *,HENDPOINT,Dispatch::ExternalPriority,void *,unsigned int);
					virtual void SetPendingPingResult(System::Object *,void *,unsigned int);
				};

				struct Microsoft__CoreUI__IExportMessageSession_Impl
				{
					virtual HENDPOINT CreateEndpoint(System::Object *,ExportEndpointHandler *);
					virtual HENDPOINT CreateEndpoint(System::Object *,ExportEndpointHandler *,IExportMessagePort *);
					virtual HENDPOINT OpenEndpoint(System::Object *,RoutingInfo &);
					virtual HRESOURCE SendResource(System::Object *,HENDPOINT,void *,unsigned int,System::Action *);
					virtual IExportMessageConversation * JoinConversationAsClient(System::Object *,System::String *,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessageConversation * JoinConversationAsServer(System::Object *,System::String *,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessageConversation * JoinConversationAsServer(System::Object *,System::String *,System::String *,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessageGroup * CreateBatchAwareGroup(System::Object *,DispatchGroupBatchEnableHandler *,DispatchGroupHandler *);
					virtual IExportMessageGroup * CreateGroup(System::Object *,DispatchGroupHandler *,DispatchGroupHandler *);
					virtual IExportMessageInfo * get_MessageInfo(System::Object *);
					virtual IExportMessageLoopExtensions * get_MessageLoopExtensions(System::Object *);
					virtual IExportMessagePort * CreatePort(System::Object *,PSECURITY_DESCRIPTOR);
					virtual IExportMessagePort * CreatePort(System::Object *,PSECURITY_DESCRIPTOR,System::String *);
					virtual IExportMessagePort * GetMessagePort(System::Object *,HENDPOINT);
					virtual IExportMessagePort * OpenPort(System::Object *,System::String *);
					virtual IExportMessageRegistrar * get_MessageRegistrar(System::Object *);
					virtual IExportMessageSessionPrivate * get_PrivateInterfaceForCoreUIComponents(System::Object *);
					virtual IExportMessageTimer * CreateTimer(System::Object *,Dispatch::TimeoutHandler *);
					virtual IExportMessageTimerCoalescer * CreateTimerCoalescer(System::Object *);
					virtual RoutingInfo GetEndpointInfo(System::Object *,HENDPOINT);
					virtual void * SendInPlace(System::Object *,HENDPOINT,Dispatch::ExternalPriority,unsigned int);
					virtual void * SendInPlace(System::Object *,HENDPOINT,unsigned int);
					virtual void CancelSendInPlace(System::Object *,void *);
					virtual void CloseEndpoint(System::Object *,HENDPOINT);
					virtual void CloseEndpoint(System::Object *,HENDPOINT,CloseEndpointFlags);
					virtual void CloseResource(System::Object *,HRESOURCE);
					virtual void DeferInvoke(System::Object *,System::Action *,Dispatch::ExternalPriority);
					virtual void DisconnectClient(System::Object *,unsigned int,unsigned int);
					virtual void Exit(System::Object *);
					virtual void OpenResource(System::Object *,HRESOURCE,void * &,unsigned int &);
					virtual void RegisterDispatchCallback(System::Object *,Dispatch::DispatchCallback *);
					virtual void RegisterDispatchCallback(System::Object *,Dispatch::DispatchCallback *,Dispatch::ThreadPriority);
					virtual void RegisterWait(System::Object *,Support::Win32Handle,Dispatch::WaitCallback *);
					virtual void RegisterWait(System::Object *,WaitRegistration,Support::Win32Handle,Dispatch::WaitCallback *);
					virtual void Run(System::Object *);
					virtual void Send(System::Object *,HENDPOINT,Dispatch::ExternalPriority,void *,unsigned int);
					virtual void Send(System::Object *,HENDPOINT,void *,unsigned int);
					virtual void UnregisterDispatchCallback(System::Object *,Dispatch::DispatchCallback *);
					virtual void UnregisterWait(System::Object *,Support::Win32Handle);
					virtual void UnregisterWait(System::Object *,WaitRegistration,Support::Win32Handle);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static MessageSession$R::Microsoft__CoreUI__IExportDispatcherQueueInterop_Impl const s_Microsoft__CoreUI__IExportDispatcherQueueInterop_Impl;
				static MessageSession$R::Microsoft__CoreUI__IExportMessageSessionPrivate_Impl const s_Microsoft__CoreUI__IExportMessageSessionPrivate_Impl;
				static MessageSession$R::Microsoft__CoreUI__IExportMessageSession_Impl const s_Microsoft__CoreUI__IExportMessageSession_Impl;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,unsigned __int64,Identity::IIdentityObject *,unsigned __int64,bool);
				static void Delegate1(System::Delegate *,Support::Win32Handle);
				static void Delegate2(System::Delegate *);
				static void Delegate3(System::Delegate *,System::Object *);
				static void InitializeCppInstance(void *);
			};

			struct MessageSessionPrivateWrapper$R
			{
				struct Microsoft__CoreUI__IExportMessageSessionPrivate_Impl
				{
					virtual HENDPOINT GetEndpoint(System::Object *,System::IntPtr);
					virtual HENDPOINT GetTargetEndpoint(System::Object *,RoutingInfo &);
					virtual IExportMessageConversation * JoinConversationAsClient(System::Object *,System::String *,MsgScopeID,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessageConversation * JoinConversationAsServer(System::Object *,System::String *,MsgScopeID,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessageConversation * JoinConversationAsServer(System::Object *,System::String *,System::String *,MsgScopeID,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessagePort * GetMessagePort(System::Object *,HENDPOINT);
					virtual RawHRESULT AllocateRemoteEndpoint(System::Object *,RoutingInfo &,RoutingInfo &,HENDPOINT &,HENDPOINT &);
					virtual RawHRESULT EstablishConnection(System::Object *,RoutingInfo &,HENDPOINT &);
					virtual RawHRESULT GetConnectionStatus(System::Object *,HENDPOINT);
					virtual RoutingInfo GetEndpointInfo(System::Object *,HENDPOINT);
					virtual RoutingInfo GetRoutingInfo(System::Object *,System::IntPtr);
					virtual System::IntPtr ClaimRemoteEndpoint(System::Object *,RoutingInfo &,RoutingInfo &,ExportEndpointHandler *);
					virtual System::IntPtr CreateEndpoint(System::Object *,ExportEndpointHandler *,IExportMessagePort *);
					virtual System::IntPtr GetEndpointData(System::Object *,HIDENTITY);
					virtual System::IntPtr RegisterCoreUIComponents(System::Object *,void *,ExportEndpointHandler *);
					virtual bool IsReversePort(System::Object *,IExportMessagePort *);
					virtual void * AllocateMessage(System::Object *,HENDPOINT,Dispatch::ExternalPriority,unsigned int,bool &);
					virtual void AddListener(System::Object *,ICallbackMessageSessionListener *);
					virtual void CloseEndpoint(System::Object *,System::IntPtr);
					virtual void FlushImmediately(System::Object *,HENDPOINT);
					virtual void FlushMessage(System::Object *,void *);
					virtual void NotifyRemoteEndpointFreed(System::Object *,HENDPOINT,RoutingInfo &);
					virtual void PingAndWait(System::Object *,HENDPOINT,void *,unsigned int);
					virtual void QueryEndpointCounts(System::Object *,int &,int &);
					virtual void RemoveListener(System::Object *,ICallbackMessageSessionListener *);
					virtual void Send(System::Object *,HENDPOINT,Dispatch::ExternalPriority,void *,unsigned int);
					virtual void SetPendingPingResult(System::Object *,void *,unsigned int);
				};

				struct Microsoft__CoreUI__IExportMessageSession_Impl
				{
					virtual HENDPOINT CreateEndpoint(System::Object *,ExportEndpointHandler *);
					virtual HENDPOINT CreateEndpoint(System::Object *,ExportEndpointHandler *,IExportMessagePort *);
					virtual HENDPOINT OpenEndpoint(System::Object *,RoutingInfo &);
					virtual HRESOURCE SendResource(System::Object *,HENDPOINT,void *,unsigned int,System::Action *);
					virtual IExportMessageConversation * JoinConversationAsClient(System::Object *,System::String *,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessageConversation * JoinConversationAsServer(System::Object *,System::String *,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessageConversation * JoinConversationAsServer(System::Object *,System::String *,System::String *,IExportMessagePort *,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ICallbackMessageConversationHost *,unsigned int &);
					virtual IExportMessageGroup * CreateBatchAwareGroup(System::Object *,DispatchGroupBatchEnableHandler *,DispatchGroupHandler *);
					virtual IExportMessageGroup * CreateGroup(System::Object *,DispatchGroupHandler *,DispatchGroupHandler *);
					virtual IExportMessageInfo * get_MessageInfo(System::Object *);
					virtual IExportMessageLoopExtensions * get_MessageLoopExtensions(System::Object *);
					virtual IExportMessagePort * CreatePort(System::Object *,PSECURITY_DESCRIPTOR);
					virtual IExportMessagePort * CreatePort(System::Object *,PSECURITY_DESCRIPTOR,System::String *);
					virtual IExportMessagePort * GetMessagePort(System::Object *,HENDPOINT);
					virtual IExportMessagePort * OpenPort(System::Object *,System::String *);
					virtual IExportMessageRegistrar * get_MessageRegistrar(System::Object *);
					virtual IExportMessageSessionPrivate * get_PrivateInterfaceForCoreUIComponents(System::Object *);
					virtual IExportMessageTimer * CreateTimer(System::Object *,Dispatch::TimeoutHandler *);
					virtual IExportMessageTimerCoalescer * CreateTimerCoalescer(System::Object *);
					virtual RoutingInfo GetEndpointInfo(System::Object *,HENDPOINT);
					virtual void * SendInPlace(System::Object *,HENDPOINT,Dispatch::ExternalPriority,unsigned int);
					virtual void * SendInPlace(System::Object *,HENDPOINT,unsigned int);
					virtual void CancelSendInPlace(System::Object *,void *);
					virtual void CloseEndpoint(System::Object *,HENDPOINT);
					virtual void CloseEndpoint(System::Object *,HENDPOINT,CloseEndpointFlags);
					virtual void CloseResource(System::Object *,HRESOURCE);
					virtual void DeferInvoke(System::Object *,System::Action *,Dispatch::ExternalPriority);
					virtual void DisconnectClient(System::Object *,unsigned int,unsigned int);
					virtual void Exit(System::Object *);
					virtual void OpenResource(System::Object *,HRESOURCE,void * &,unsigned int &);
					virtual void RegisterDispatchCallback(System::Object *,Dispatch::DispatchCallback *);
					virtual void RegisterDispatchCallback(System::Object *,Dispatch::DispatchCallback *,Dispatch::ThreadPriority);
					virtual void RegisterWait(System::Object *,Support::Win32Handle,Dispatch::WaitCallback *);
					virtual void RegisterWait(System::Object *,WaitRegistration,Support::Win32Handle,Dispatch::WaitCallback *);
					virtual void Run(System::Object *);
					virtual void Send(System::Object *,HENDPOINT,Dispatch::ExternalPriority,void *,unsigned int);
					virtual void Send(System::Object *,HENDPOINT,void *,unsigned int);
					virtual void UnregisterDispatchCallback(System::Object *,Dispatch::DispatchCallback *);
					virtual void UnregisterWait(System::Object *,Support::Win32Handle);
					virtual void UnregisterWait(System::Object *,WaitRegistration,Support::Win32Handle);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static MessageSessionPrivateWrapper$R::Microsoft__CoreUI__IExportMessageSessionPrivate_Impl const s_Microsoft__CoreUI__IExportMessageSessionPrivate_Impl;
				static MessageSessionPrivateWrapper$R::Microsoft__CoreUI__IExportMessageSession_Impl const s_Microsoft__CoreUI__IExportMessageSession_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct MessageStream
			{
				Buffering::BufferSet * RelinquishBuffersForTransport();
				virtual void OnDispose();
				void * AllocateRawMessage(unsigned int);
				void _Construct(MessageSession *,Connection *,FlushPolicy,Dispatch::ExternalPriority,Buffering::BufferAllocationPolicy *,unsigned int);
			};

			struct MessageStream$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static MessageStream * New(MessageSession *,Connection *,FlushPolicy,Dispatch::ExternalPriority);
				static MessageStream * New(MessageSession *,Connection *,FlushPolicy,Dispatch::ExternalPriority,Buffering::BufferAllocationPolicy *,unsigned int);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct MessageStream_1D
			{
				MessageStream * _SetElement(int,MessageStream *);
			};

			struct MessageStream_1D$R
			{
				static Cn::TypeDefinition_4 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct MessagingResults$R
			{
				static Cn::TypeDefinition_74 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static char const * const s_EnumNames;
				static unsigned short const * const s_rgEnumNameOffsets;
				static void InitializeCppInstance(void *);
			};

			struct MessagingValidationException
			{
				static System::Exception * FromResult(MessagingResults);
				static System::Exception * get_AlreadyInDispatchLoop();
				static System::Exception * get_InvalidDestination();
				static System::Exception * get_InvalidHandle();
				static System::Exception * get_NotInDispatchLoop();
			};

			struct MessagingValidationException$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static MessagingValidationException * New(MessagingResults);
				static void InitializeCppInstance(void *);
			};

			struct NTSecurity
			{
				static MessagingResults GetAppContainerNamedObjectPath(bool,Cn::ParamRef<System::String>);
			};

			struct ReverseConnectionReceivePort
			{
				virtual System::Guid get_ID();
				virtual System::IntPtr get_AlpcConnection();
				virtual bool get_ReceivesHighPriorityMessages();
				virtual void OnDispose();
				virtual void ValidateIdentityGroup(unsigned int,unsigned int,unsigned int);
				virtual void set_ReceivesHighPriorityMessages(bool);
				void _Construct(Connection *,System::Guid &);
			};

			struct ReverseConnectionReceivePort$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ReverseConnectionReceivePort * New(Connection *,System::Guid &);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct SenderInfo
			{
				static bool op_Inequality(SenderInfo,SenderInfo);
			};

		};

		struct MsgScopeID
		{
			Registrar::ScopeID ToInternal(bool &);
		};

		struct ProtocolError$R
		{
			static Cn::TypeDefinition_72 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static char const * const s_EnumNames;
			static unsigned short const * const s_rgEnumNameOffsets;
			static void InitializeCppInstance(void *);
		};

		struct ProtocolException
		{
			void _Construct(ProtocolError);
		};

		struct ProtocolException$R
		{
			static Cn::TypeDefinition_65 const s_defType;
			static ProtocolException * New(ProtocolError);
			static ProtocolException * New(ProtocolError,System::String *);
			static void InitializeCppInstance(void *);
		};

		struct ProtocolExceptionWithDiagnostics
		{
			void _Construct(ProtocolError,Registrar::RegistrarDiagnostics *);
		};

		struct ProtocolExceptionWithDiagnostics$R
		{
			static Cn::TypeDefinition_65 const s_defType;
			static short const * const s_rgReferenceFields;
			static void InitializeCppInstance(void *);
		};

		namespace Registrar
		{
			struct AlpcAdapter
			{
				Support::Win32Handle get_WaitHandle();
				static void ValidateString(System::String *);
				virtual void OnDispose();
			};

			struct AlpcAdapter$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct AlpcClientAdapter
			{
				int CreatePort(System::String *,unsigned short);
				static int Connect(System::String *,IAlpcClientHost *,unsigned short,Cn::ParamRef<AlpcClientAdapter>);
				virtual void OnDispose();
				void EnsureWaitRegistered();
			};

			struct AlpcClientAdapter$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,Dispatch::WaitStatus,Support::Win32Handle);
				static void InitializeCppInstance(void *);
			};

			struct AlpcClientThunk
			{
				virtual long BatchProcessed(unsigned long);
				virtual long Callback_ProcessAsynchronousBuffer(IAlpcConnection *,void *,unsigned long,void const *,int);
				virtual long InvalidBufferReceived(void *,unsigned long);
				virtual long OnConnectionCompleted(IAlpcClientConnection *,bool);
				virtual long OnServerDisconnected(IAlpcClientConnection *);
				virtual long ProcessReply(IAlpcClientConnection *,void const *,int);
			};

			struct AlpcServerAdapter
			{
				bool DoCapabilityCheck(System::String *);
				static ServiceRunMode s_runMode;
				static System::Guid s_portNameTestSuffix;
				static System::String * GeneratePortName(System::String *);
				static void GetPortSecurityDescriptor(System::String *,System::IntPtr &);
				virtual void OnDispose();
				void DisconnectClient(unsigned int);
				void ReplyWithProtocolExceptionAndDiagnostics(ProtocolExceptionWithDiagnostics *);
				void _Construct(System::String *,System::IntPtr,IAlpcServerHost *,unsigned short);
			};

			struct AlpcServerAdapter$R
			{
				static AlpcServerAdapter * New(System::String *,System::IntPtr,IAlpcServerHost *,unsigned short);
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,Dispatch::WaitStatus,Support::Win32Handle);
				static void InitializeCppInstance(void *);
			};

			struct AlpcServerThunk
			{
				virtual long AcceptConnection(bool,unsigned long,unsigned long,void *,void *,void * *,bool *);
				virtual long BatchProcessed(unsigned long);
				virtual long Callback_ProcessAsynchronousBuffer(IAlpcConnection *,void *,unsigned long,void const *,int);
				virtual long InvalidBufferReceived(void *,unsigned long);
				virtual long OnClientDisconnected(void *,unsigned long,void *);
				virtual long ProcessSynchronousCall(bool,IAlpcServerConnection *,void *,unsigned long,void *,void const *,int);
			};

			class ClientMessageCallSendHost
			{
				virtual long SubmitBuffer(unsigned __int64 *,unsigned int,void *,unsigned int);
			};

			struct ClientWindowIDManager
			{
				WindowID Microsoft__CoreUI__IExportClientWindowIDManager__AllocateWindowID(int,WindowIDPropertyValue *);
				static IExportClientWindowIDManager * Create();
				void Microsoft__CoreUI__IExportClientWindowIDManager__ClearWindowIDProperties(WindowID,int,WindowIDPropertyValue *);
				void Microsoft__CoreUI__IExportClientWindowIDManager__FreeWindowID(WindowID);
				void Microsoft__CoreUI__IExportClientWindowIDManager__GetWindowIDInfo(WindowID,WindowIDInfo *);
				void Microsoft__CoreUI__IExportClientWindowIDManager__GetWindowIDProperties(WindowID,int,WindowIDPropertyValue *,unsigned int &);
				void Microsoft__CoreUI__IExportClientWindowIDManager__SetWindowIDProperties(WindowID,int,WindowIDPropertyValue *);
			};

			struct ClientWindowIDManager$R
			{
				struct Microsoft__CoreUI__IExportClientWindowIDManager_Impl
				{
					virtual WindowID AllocateWindowID(System::Object *,int,WindowIDPropertyValue *);
					virtual void ClearWindowIDProperties(System::Object *,WindowID,int,WindowIDPropertyValue *);
					virtual void FreeWindowID(System::Object *,WindowID);
					virtual void GetWindowIDInfo(System::Object *,WindowID,WindowIDInfo *);
					virtual void GetWindowIDProperties(System::Object *,WindowID,int,WindowIDPropertyValue *,unsigned int &);
					virtual void SetWindowIDProperties(System::Object *,WindowID,int,WindowIDPropertyValue *);
				};

				static ClientWindowIDManager$R::Microsoft__CoreUI__IExportClientWindowIDManager_Impl const s_Microsoft__CoreUI__IExportClientWindowIDManager_Impl;
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ConversationClientConnectionInfo
			{
				void Dispose();
			};

			struct ConversationClientConnectionInfo$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct CuiRegistrar
			{
				static void Run(Support::Win32Handle,Support::Win32Handle,ServiceRunMode,System::Guid);
				virtual void OnDispose();
				void _Construct();
			};

			struct CuiRegistrar$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,Dispatch::WaitStatus,Support::Win32Handle);
				static void InitializeCppInstance(void *);
			};

			struct EndpointEntry
			{
				static void Create(wchar_t const *,RoutingInfo,EndpointEntry * *);
				virtual bool NotifyThreadExited(unsigned int);
			};

			struct GetWindowIDPropertiesResponse$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct HIDENTITYAllocatorWrapper$R
			{
				static Cn::TypeDefinition_64 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct IAlpcClientHost
			{
				void UnformatAndInvokeMethod(void *,unsigned int);
			};

			struct IAlpcClientHost$R
			{
				static Cn::TypeDefinition_64 const s_defType;
				static void const * const * const s_rgLookup;
			};

			struct IAlpcServerHost
			{
				void InvalidateConnection();
				void SetConnectionContext(System::IntPtr);
			};

			struct IAlpcServerHost$R
			{
				static Cn::TypeDefinition_64 const s_defType;
				static void const * const * const s_rgLookup;
			};

			struct IDManagerClientCaller
			{
				static unsigned int ComputeMaximumMessageSize();
				static void Reply_AllocateWindowID(AlpcServerAdapter *,Messaging::MessagingResults,WindowID);
				static void Reply_FreeWindowID(AlpcServerAdapter *,Messaging::MessagingResults);
				static void Reply_GetWindowIDInfo(AlpcServerAdapter *,Messaging::MessagingResults,WindowIDInfo);
				static void Reply_GetWindowIDProperties_MessageCall(AlpcServerAdapter *,Messaging::MessagingResults,WindowIDPropertyValue,unsigned int);
			};

			struct IDManagerServerCaller
			{
				static Messaging::MessagingResults AllocateWindowID(AlpcClientAdapter *,unsigned int,unsigned int,WindowIDPropertyValue *,int,WindowID &);
				static Messaging::MessagingResults GetWindowIDInfo(AlpcClientAdapter *,WindowID,WindowIDInfo &);
				static Messaging::MessagingResults GetWindowIDProperties(AlpcClientAdapter *,WindowID,WindowIDPropertyValue *,int,Cn::ParamRef<GetWindowIDPropertiesResponse>);
				static int AllocateWindowID_MessageCall(AlpcClientAdapter *,unsigned int,unsigned int,WindowIDPropertyValue);
				static int FreeWindowID_MessageCall(AlpcClientAdapter *,WindowID);
				static int GetWindowIDInfo_MessageCall(AlpcClientAdapter *,WindowID);
				static int GetWindowIDProperties_MessageCall(AlpcClientAdapter *,WindowID,WindowIDPropertyValue);
				static unsigned int ComputeMaximumMessageSize();
				static void Reply_GetWindowIDProperties(AlpcClientAdapter *,WindowIDPropertyMarshalHelper,Messaging::MessagingResults,WindowIDPropertyValue,unsigned int);
			};

			struct PendingConnection$R
			{
				static Cn::TypeDefinition_64 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct RegisteredConversation
			{
				ConversationClientConnectionInfo * CreatePendingClient(RegistrarThreadContext *,RegisteredConversationServer *,Conversations::ConversationPeerInfo);
				Messaging::MessagingResults CreateClient(System::IntPtr,RegistrarThreadContext *,unsigned int,Cn::ParamRef<RegisteredConversationClient>);
				bool TryGetClient(unsigned int,RegistrarThreadContext *,Cn::ParamRef<RegisteredConversationClient>);
				bool TryGetServer(unsigned int,RegistrarThreadContext *,Cn::ParamRef<RegisteredConversationServer>);
				bool get_IsSinglePersistentManualServer();
				static bool IsTrustedConversation(System::String *,ConversationItemOwner &,ConversationConnectionMode &);
				static unsigned int s_lastHint;
				static unsigned int s_testConversationCount;
				unsigned int AllocatePeerID();
				void DisconnectServer(RegistrarData *,RegisteredConversationServer *,bool);
				void Dispose();
				void ReleaseListOfClientConnections(Map__uint__object__ValueCollection);
				void ReleasePeerID(unsigned int);
				void RemoveClient(RegisteredConversationClient *,bool);
				void _Construct(System::String *,System::String *,unsigned int,bool,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ScopeID,RegistrarData *);
			};

			struct RegisteredConversation$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static RegisteredConversation * New(System::String *,System::String *,unsigned int,bool,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,ScopeID,RegistrarData *);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegisteredConversationClient$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static RegisteredConversationClient * New(RegisteredConversation *,RegistrarThreadContext *,System::IntPtr,unsigned int,unsigned int);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegisteredConversationPeer
			{
				void _Construct(RegisteredConversation *,RegistrarThreadContext *,Conversations::ConversationPeerInfo);
			};

			struct RegisteredConversationPeer$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegisteredConversationServer
			{
				ConversationClientConnectionInfo * FindClientConnection(unsigned int);
				bool ConnectPendingClient(unsigned int);
				static Messaging::MessagingResults Create(RegisteredConversation *,RegistrarThreadContext *,RoutingInfo,HIDENTITY,Cn::ParamRef<RegisteredConversationServer>);
				void Dispose();
				void RemoveAndDisposeClientConnection(ConversationClientConnectionInfo *);
			};

			struct RegisteredConversationServer$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static RegisteredConversationServer * New(RegisteredConversation *,RegistrarThreadContext *,Conversations::ConversationPeerInfo);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegisteredMessageObject$R
			{
				static Cn::TypeDefinition_66 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct RegisteredObjectList
			{
				class ListEntry
				{
				protected:
					virtual ~ListEntry();
				};

				RegisteredObjectList::ListEntry * Find(wchar_t const *);
				static void Create(RegisteredObjectList * *);
				void Add(RegisteredObjectList::ListEntry *);
				void Remove(RegisteredObjectList::ListEntry *);
			};

			struct RegisteredObjectValidator
			{
				static RegistrationNameMaps * RegistrationMapsForScope(RegistrarData *,ScopeID,bool);
				static System::Object * ValidateRegisteredObjectParamsAndLookup(System::String *,ScopeID,RegisteredObjectType,RegisteredObjectValidationLevel,RegistrarData *,Cn::ParamRef<RegistrationNameMaps>);
				static void ValidateRegisteredObjectParams(System::String *,ScopeID,RegisteredObjectValidationLevel,RegistrarData *,Cn::ParamRef<RegistrationNameMaps>);
				static void ValidateSystemCapability(System::String *,AlpcServerAdapter *);
			};

			struct RegistrarClient
			{
				HENDPOINT Microsoft__CoreUI__IExportMessageRegistrar__FindEndpoint(System::String *,ExternalRegistrarScope);
				HENDPOINT Microsoft__CoreUI__IExportMessageRegistrar__FindProcessEndpoint(System::String *,unsigned int);
				HENDPOINT Microsoft__CoreUI__IExportMessageRegistrar__FindProcessEndpointTimeout(System::String *,unsigned int,unsigned int);
				HENDPOINT OpenEndpointAPIWorker(unsigned int,RoutingInfo &);
				Messaging::MessagingResults CompleteCrossProcConnection(unsigned int,unsigned int,System::Guid,unsigned int);
				Messaging::MessagingResults CompleteLocalConnection(unsigned int,unsigned int);
				Messaging::MessagingResults FindCrossProcessReceivePort(System::String *,bool &,RoutingInfo &);
				Messaging::MessagingResults FindEndpoint(System::String *,RegistrarScope,unsigned int,RoutingInfo &);
				Messaging::MessagingResults GetSystemWindowIDManager(Cn::ParamRef<IExportSystemWindowIDManager>);
				Messaging::MessagingResults PrepareConnection(unsigned int,unsigned int,System::Guid,Cn::ParamRef<System::String>,bool &,System::Guid &,HIDENTITY &,HIDENTITY &,unsigned int &,unsigned int &);
				Messaging::MessagingResults RegisterCrossProcessReceivePort(System::String *,Messaging::CrossProcessReceivePort *);
				Messaging::MessagingResults RegisterEndpoint(System::String *,Messaging::MessageEndpoint *,RegistrarScope);
				Messaging::MessagingResults UnregisterCrossProcessReceivePort(System::String *);
				Messaging::MessagingResults UnregisterEndpoint(System::String *,RegistrarScope);
				RegistrarScope TranslateBareScope(ExternalRegistrarScope);
				RoutingInfo FindEndpointAPIWorker(System::String *,RegistrarScope,unsigned int);
				RoutingInfo Microsoft__CoreUI__IExportMessageRegistrar__FindEndpointInfo(System::String *,ExternalRegistrarScope);
				static Messaging::MessagingResults FindEndpointLocal(System::String *,RoutingInfo &);
				static Messaging::MessagingResults RegisterEndpointLocal(System::String *,RoutingInfo);
				static Messaging::MessagingResults UnregisterEndpointLocal(System::String *,RoutingInfo);
				static bool FindConnection(unsigned int,RoutingInfo &);
				static unsigned int RegisterConnection(RoutingInfo &,bool);
				static unsigned int s_serverPID;
				static void InitializeClass(bool);
				static void RemoveLocalEndpointRegistrations(unsigned int);
				static void UnregisterConnection(unsigned int);
				virtual void OnDispose();
				void ConnectToRegistrarServer();
				void CrossProcClientDisconnected(unsigned int);
				void EnqueuePendingConnectionTerminated(unsigned int,unsigned int);
				void Initialize(Identity::IdentityTableView *,Dispatch::ThreadContext *,HIDENTITY &,HIDENTITY &);
				void LocalClientDisconnected(unsigned int);
				void Microsoft__CoreUI__IExportMessageRegistrar__PublishEndpoint(System::String *,HENDPOINT,ExternalRegistrarScope);
				void Microsoft__CoreUI__IExportMessageRegistrar__RevokeEndpoint(System::String *,ExternalRegistrarScope);
			};

			struct RegistrarClient$R
			{
				struct Microsoft__CoreUI__IExportMessageRegistrar_Impl
				{
					virtual HENDPOINT FindEndpoint(System::Object *,System::String *,ExternalRegistrarScope);
					virtual HENDPOINT FindProcessEndpoint(System::Object *,System::String *,unsigned int);
					virtual HENDPOINT FindProcessEndpointTimeout(System::Object *,System::String *,unsigned int,unsigned int);
					virtual RoutingInfo FindEndpointInfo(System::Object *,System::String *,ExternalRegistrarScope);
					virtual void PublishEndpoint(System::Object *,System::String *,HENDPOINT,ExternalRegistrarScope);
					virtual void RevokeEndpoint(System::Object *,System::String *,ExternalRegistrarScope);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static RegistrarClient$R::Microsoft__CoreUI__IExportMessageRegistrar_Impl const s_Microsoft__CoreUI__IExportMessageRegistrar_Impl;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,unsigned int,unsigned int);
				static void InitializeCppInstance(void *);
			};

			struct RegistrarClientCaller
			{
				static unsigned int ComputeMaximumMessageSize();
				static void OnConversationServerJoined(AlpcServerAdapter *,System::IntPtr,System::String *,unsigned int,unsigned int,Conversations::ConversationPeerInfo);
				static void OnPendingConnectionTermination(AlpcServerAdapter *,System::IntPtr,unsigned int,unsigned int);
				static void OnProtocolException(AlpcServerAdapter *,ProtocolError);
				static void OnProtocolExceptionWithDiagnostics(AlpcServerAdapter *,ProtocolError,System::String *,System::String *,System::String *,System::String *,System::String *,System::String *,System::String *,System::String *);
				static void Reply_AllocateWindowID(AlpcServerAdapter *,Messaging::MessagingResults,WindowID);
				static void Reply_ClearWindowIDProperties(AlpcServerAdapter *,Messaging::MessagingResults);
				static void Reply_CloseConnection(AlpcServerAdapter *);
				static void Reply_CompleteCrossProcConnection(AlpcServerAdapter *,Messaging::MessagingResults);
				static void Reply_CompleteLocalConnection(AlpcServerAdapter *,Messaging::MessagingResults);
				static void Reply_ConnectPendingConversationClient(AlpcServerAdapter *,Messaging::MessagingResults);
				static void Reply_CrossProcClientDisconnected(AlpcServerAdapter *);
				static void Reply_FindCrossProcConnection(AlpcServerAdapter *,Messaging::MessagingResults,unsigned int,unsigned int);
				static void Reply_FindMessageObject(AlpcServerAdapter *,Messaging::MessagingResults,RegisteredMessageObject);
				static void Reply_FindObject(AlpcServerAdapter *,Messaging::MessagingResults,bool,RoutingInfo);
				static void Reply_FindPendingConversationClient(AlpcServerAdapter *,Messaging::MessagingResults,RoutingInfo,HIDENTITY);
				static void Reply_FreeWindowID(AlpcServerAdapter *,Messaging::MessagingResults);
				static void Reply_GetOrCreateReverseConnectionPortID(AlpcServerAdapter *,System::Guid);
				static void Reply_GetWindowIDInfo(AlpcServerAdapter *,Messaging::MessagingResults,WindowIDInfo);
				static void Reply_GetWindowIDProperties_MessageCall(AlpcServerAdapter *,Messaging::MessagingResults,WindowIDPropertyValue,unsigned int);
				static void Reply_LocalClientDisconnected(AlpcServerAdapter *);
				static void Reply_PrepareConnection(AlpcServerAdapter *,Messaging::MessagingResults,System::String *,PendingConnection);
				static void Reply_RegisterAlpcPort(AlpcServerAdapter *);
				static void Reply_RegisterConversation(AlpcServerAdapter *,Messaging::MessagingResults,unsigned int,unsigned int);
				static void Reply_RegisterConversationClient(AlpcServerAdapter *,Messaging::MessagingResults,unsigned int,Conversations::ConversationInfo,Conversations::ConversationPeerInfo);
				static void Reply_RegisterObject(AlpcServerAdapter *,Messaging::MessagingResults);
				static void Reply_RegisterPendingConversationClientForServer(AlpcServerAdapter *,Messaging::MessagingResults);
				static void Reply_RegisterThread(AlpcServerAdapter *,Messaging::MessagingResults,unsigned int);
				static void Reply_ReleaseConversationClient(AlpcServerAdapter *);
				static void Reply_ReleaseConversationClientConnection(AlpcServerAdapter *,Messaging::MessagingResults);
				static void Reply_ReleaseConversationServer(AlpcServerAdapter *);
				static void Reply_SetWindowIDProperties(AlpcServerAdapter *,Messaging::MessagingResults);
				static void Reply_UnregisterAlpcPort(AlpcServerAdapter *);
				static void Reply_UnregisterObject(AlpcServerAdapter *,Messaging::MessagingResults);
				static void Reply_UnregisterReverseConnectionPort(AlpcServerAdapter *);
			};

			struct RegistrarClient__OnPendingConnectionTerminationHandler
			{
				void Invoke(unsigned int,unsigned int);
			};

			struct RegistrarClient__OnPendingConnectionTerminationHandler$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct RegistrarData
			{
				void Dispose();
			};

			struct RegistrarData$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static RegistrarData * New(AlpcServerAdapter *);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegistrarDiagnostics
			{
				System::String * RemoveString();
				void Log(System::String *);
			};

			struct RegistrarDiagnostics$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct RegistrarDiagnostics__StringListItem$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegistrarMessageCallSendHost
			{
				virtual long AllocateBuffer(unsigned __int64 *,unsigned int,unsigned int,void * *);
			};

			struct RegistrarProcessContext
			{
				Messaging::MessagingResults ReserveGroup(unsigned int &);
				void ReclaimGroup(unsigned int);
			};

			struct RegistrarProcessContext$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static RegistrarProcessContext * New();
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegistrarServerCaller
			{
				static Messaging::MessagingResults AllocateWindowID(AlpcClientAdapter *,WindowIDPropertyValue *,int,WindowID &);
				static Messaging::MessagingResults ConnectPendingConversationClient(AlpcClientAdapter *,System::String *,ScopeID,unsigned int,unsigned int,unsigned int);
				static Messaging::MessagingResults FindCrossProcConnection(AlpcClientAdapter *,bool,RoutingInfo,unsigned int &,unsigned int &);
				static Messaging::MessagingResults FindObject(AlpcClientAdapter *,System::String *,ScopeID,RegisteredObjectType,bool &,RoutingInfo &);
				static Messaging::MessagingResults FindPendingConversationClient(AlpcClientAdapter *,System::String *,ScopeID,unsigned int,unsigned int,unsigned int,RoutingInfo &,HIDENTITY &);
				static Messaging::MessagingResults GetWindowIDInfo(AlpcClientAdapter *,WindowID,WindowIDInfo &);
				static Messaging::MessagingResults GetWindowIDProperties(AlpcClientAdapter *,WindowID,WindowIDPropertyValue *,int,Cn::ParamRef<GetWindowIDPropertiesResponse>);
				static Messaging::MessagingResults PrepareConnection(AlpcClientAdapter *,PendingConnection,Cn::ParamRef<System::String>,PendingConnection &);
				static Messaging::MessagingResults RegisterConversation(AlpcClientAdapter *,System::String *,System::String *,ScopeID,Conversations::ConversationInfo,RoutingInfo,HIDENTITY,unsigned int &,unsigned int &);
				static Messaging::MessagingResults RegisterConversationClient(AlpcClientAdapter *,System::String *,ScopeID,unsigned int,unsigned int &,Conversations::ConversationInfo &,Conversations::ConversationPeerInfo &);
				static Messaging::MessagingResults RegisterObject(AlpcClientAdapter *,System::String *,ScopeID,HIDENTITY,System::Guid,RegisteredObjectType);
				static Messaging::MessagingResults RegisterPendingConversationClientForServer(AlpcClientAdapter *,System::String *,ScopeID,unsigned int,Conversations::ConversationPeerInfo);
				static Messaging::MessagingResults ReleaseConversationClientConnection(AlpcClientAdapter *,System::String *,ScopeID,unsigned int,unsigned int,unsigned int);
				static int AllocateWindowID_MessageCall(AlpcClientAdapter *,WindowIDPropertyValue);
				static int ClearWindowIDProperties_MessageCall(AlpcClientAdapter *,WindowID,WindowIDPropertyValue);
				static int CloseConnection_MessageCall(AlpcClientAdapter *,PendingConnection);
				static int CompleteCrossProcConnection_MessageCall(AlpcClientAdapter *,RoutingInfo);
				static int CompleteLocalConnection_MessageCall(AlpcClientAdapter *,unsigned int,unsigned int);
				static int ConnectPendingConversationClient_MessageCall(AlpcClientAdapter *,System::String *,ScopeID,unsigned int,unsigned int,unsigned int);
				static int CrossProcClientDisconnected_MessageCall(AlpcClientAdapter *,unsigned int);
				static int FindCrossProcConnection_MessageCall(AlpcClientAdapter *,bool,RoutingInfo);
				static int FindObject_MessageCall(AlpcClientAdapter *,System::String *,ScopeID,RegisteredObjectType);
				static int FindPendingConversationClient_MessageCall(AlpcClientAdapter *,System::String *,ScopeID,unsigned int,unsigned int,unsigned int);
				static int FreeWindowID_MessageCall(AlpcClientAdapter *,WindowID);
				static int GetOrCreateReverseConnectionPortID_MessageCall(AlpcClientAdapter *,System::Guid);
				static int GetWindowIDInfo_MessageCall(AlpcClientAdapter *,WindowID);
				static int GetWindowIDProperties_MessageCall(AlpcClientAdapter *,WindowID,WindowIDPropertyValue);
				static int LocalClientDisconnected_MessageCall(AlpcClientAdapter *,unsigned int);
				static int PrepareConnection_MessageCall(AlpcClientAdapter *,PendingConnection);
				static int RegisterAlpcPort_MessageCall(AlpcClientAdapter *,System::Guid,System::String *);
				static int RegisterConversationClient_MessageCall(AlpcClientAdapter *,System::String *,ScopeID,unsigned int);
				static int RegisterConversation_MessageCall(AlpcClientAdapter *,System::String *,System::String *,ScopeID,Conversations::ConversationInfo,RoutingInfo,HIDENTITY);
				static int RegisterObject_MessageCall(AlpcClientAdapter *,System::String *,ScopeID,HIDENTITY,System::Guid,RegisteredObjectType);
				static int RegisterPendingConversationClientForServer_MessageCall(AlpcClientAdapter *,System::String *,ScopeID,unsigned int,Conversations::ConversationPeerInfo);
				static int RegisterThread_MessageCall(AlpcClientAdapter *);
				static int ReleaseConversationClientConnection_MessageCall(AlpcClientAdapter *,System::String *,ScopeID,unsigned int,unsigned int,unsigned int);
				static int ReleaseConversationClient_MessageCall(AlpcClientAdapter *,System::String *,ScopeID,unsigned int);
				static int ReleaseConversationServer_MessageCall(AlpcClientAdapter *,System::String *,ScopeID,unsigned int);
				static int SetWindowIDProperties_MessageCall(AlpcClientAdapter *,WindowID,WindowIDPropertyValue);
				static int UnregisterAlpcPort_MessageCall(AlpcClientAdapter *,System::Guid);
				static int UnregisterObject_MessageCall(AlpcClientAdapter *,System::String *,ScopeID,RegisteredObjectType);
				static int UnregisterReverseConnectionPort_MessageCall(AlpcClientAdapter *,System::Guid);
				static unsigned int ComputeMaximumMessageSize();
				static void Reply_FindObject(AlpcClientAdapter *,Messaging::MessagingResults,bool,RoutingInfo);
				static void Reply_FindPendingConversationClient(AlpcClientAdapter *,Messaging::MessagingResults,RoutingInfo,HIDENTITY);
				static void Reply_GetWindowIDProperties(AlpcClientAdapter *,WindowIDPropertyMarshalHelper,Messaging::MessagingResults,WindowIDPropertyValue,unsigned int);
				static void Reply_RegisterConversationClient(AlpcClientAdapter *,Messaging::MessagingResults,unsigned int,Conversations::ConversationInfo,Conversations::ConversationPeerInfo);
			};

			struct RegistrarSessionContext$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static RegistrarSessionContext * New(unsigned int);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegistrarThreadContext$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegistrationNameMaps
			{
				Messaging::MessagingResults CleanupRegistrationCommon(RegistrarThreadContext *,RegisteredObjectType,System::String *,bool,bool,bool);
				Messaging::MessagingResults RegisterObject(RegistrarThreadContext *,RegisteredObjectType,System::String *,System::Object *);
				Messaging::MessagingResults UnregisterObject(RegistrarThreadContext *,RegisteredObjectType,System::String *);
				System::Object * FindObject(RegisteredObjectType,System::String *);
				void AddToThreadListOnly(RegistrarThreadContext *,RegisteredObjectType,System::String *);
				void RemoveFromMap(RegisteredObjectType,System::String *);
				void Rundown(RegistrarThreadContext *);
			};

			struct RegistrationNameMaps$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static RegistrationNameMaps * New(RegistrarScope);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegistrationNameMaps__Ticket
			{
				RegistrationNameMaps__Ticket(RegistrationNameMaps__Ticket const &);
				void Cleanup(RegistrarThreadContext *);
				~RegistrationNameMaps__Ticket();
			};

			struct RegistrationNameMaps__Ticket$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static RegistrationNameMaps__Ticket New(RegistrationNameMaps *,RegisteredObjectType,System::String *);
				static RegistrationNameMaps__Ticket Unbox(System::Object *);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RegistrationNameMaps__Ticket_1D
			{
				RegistrationNameMaps__Ticket & _SetElement(int,RegistrationNameMaps__Ticket);
			};

			struct RegistrationNameMaps__Ticket_1D$R
			{
				static Cn::TypeDefinition_4 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct RegistrationNameMaps__Ticket__Boxed
			{
				virtual bool Equals(System::Object *);
			};

			struct RemoteRegistrarClient
			{
				Messaging::MessagingResults CompleteCrossProcConnection(unsigned int,unsigned int,System::Guid);
				Messaging::MessagingResults ConnectPendingConversationClient(System::String *,ScopeID,unsigned int,unsigned int,unsigned int);
				Messaging::MessagingResults FindCrossProcConnection(unsigned int,unsigned int,System::Guid,bool,unsigned int &,unsigned int &);
				Messaging::MessagingResults FindObject(System::String *,ScopeID,RegisteredObjectType,bool &,RoutingInfo &);
				Messaging::MessagingResults FindPendingConversationClient(System::String *,ScopeID,unsigned int,unsigned int,unsigned int,RoutingInfo &,HIDENTITY &);
				Messaging::MessagingResults PrepareConnection(unsigned int,unsigned int,System::Guid,Cn::ParamRef<System::String>,bool &,System::Guid &,HIDENTITY &,HIDENTITY &,unsigned int &,unsigned int &);
				Messaging::MessagingResults RegisterConversation(System::String *,System::String *,ScopeID,ConversationItemOwner,ConversationServerStyle,ConversationConnectionMode,RoutingInfo,RoutingInfo,unsigned int &,unsigned int &);
				Messaging::MessagingResults RegisterConversationClient(Conversations::ConversationClient *,unsigned int &,Conversations::ConversationInfo &,Conversations::ConversationPeerInfo &);
				Messaging::MessagingResults RegisterObject(System::String *,ScopeID,HIDENTITY,System::Guid,RegisteredObjectType);
				Messaging::MessagingResults RegisterPendingConversationClientForServer(Conversations::ConversationClient *,unsigned int,Conversations::ConversationPeerInfo);
				Messaging::MessagingResults ReleaseConversationClientConnection(System::String *,ScopeID,unsigned int,unsigned int,unsigned int);
				Messaging::MessagingResults UnregisterObject(System::String *,ScopeID,RegisteredObjectType);
				static bool WaitForServiceStartup();
				static int DoConnect(RemoteRegistrarClient *);
				static void Connect(RegistrarClient *,Cn::ParamRef<RemoteRegistrarClient>,unsigned int &);
				virtual void OnDispose();
				void CloseConnection(unsigned int,unsigned int,System::Guid,unsigned int,unsigned int);
				void GetOrCreateReverseConnectionPortID(System::Guid,System::Guid &);
				void OnConversationServerJoined(System::String *,unsigned int,unsigned int,Conversations::ConversationPeerInfo);
				void RegisterThread(unsigned int &);
				void ReleaseConversationClient(System::String *,ScopeID,unsigned int);
				void ReleaseConversationServer(System::String *,ScopeID,unsigned int);
			};

			struct RemoteRegistrarClient$R
			{
				struct Microsoft__CoreUI__Registrar__IAlpcClientHost_Impl
				{
					virtual void OnServerDisconnected(System::Object *);
					virtual void UnformatAndInvokeMethod(System::Object *,void *,unsigned int);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static RemoteRegistrarClient$R::Microsoft__CoreUI__Registrar__IAlpcClientHost_Impl const s_Microsoft__CoreUI__Registrar__IAlpcClientHost_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct RemoteRegistrarClientReceiveThunk
			{
				long Reply_PrepareConnection(Messaging::MessagingResults,wchar_t const *,PendingConnection *);
			};

			struct RemoteRegistrarServer
			{
				PendingConnection RetrievePendingConnection(bool,RegistrarSessionContext *,RoutingInfo &,RoutingInfo &,bool &);
				RegistrarProcessContext * EnsureProcessContextForNewMessageSession(bool,RegistrarSessionContext *);
				RegistrarThreadContext * CreateContextForNewMessageSession(bool,unsigned int);
				RegistrarThreadContext * GetContextForThread(RegistrarSessionContext *,unsigned int);
				bool Microsoft__CoreUI__Registrar__IAlpcServerHost__AcceptConnection(bool,unsigned int,unsigned int,System::IntPtr);
				int FindPendingConnection(System::Collections::ArrayList *,RoutingInfo &);
				static Messaging::MessagingResults ReserveGroupsForNewConnection(PendingConnection &,RegistrarThreadContext *,RegistrarThreadContext *,PendingConnection &);
				static System::Guid GetOrCreateReverseConnectionPortIDImpl(RegistrarThreadContext *,RegistrarThreadContext *,RoutingInfo,System::Guid);
				static System::String * get_RegistrarPortName();
				static void AddToList(Cn::ParamRef<System::Collections::ArrayList>,System::Object *);
				virtual void OnDispose();
				void AllocateWindowID(WindowIDPropertyValue_1D *);
				void CleanUpForDepartedThread(System::IntPtr);
				void CloseConnection(PendingConnection);
				void CompleteCrossProcConnection(RoutingInfo);
				void CompleteLocalConnection(unsigned int,unsigned int);
				void FindCrossProcConnection(bool,RoutingInfo);
				void FindMessageObject(System::String *,ScopeID);
				void FindObject(System::String *,ScopeID,RegisteredObjectType);
				void GetOrCreateReverseConnectionPortID(System::Guid);
				void GetWindowIDProperties(WindowID,WindowIDPropertyValue);
				void PrepareConnection(PendingConnection);
				void QueueDisconnectClient(unsigned int);
				void RegisterAlpcPort(System::Guid,System::String *);
				void RegisterMessageObject(System::String *,ScopeID,System::Guid,unsigned int);
				void RegisterObject(System::String *,ScopeID,HIDENTITY,System::Guid,RegisteredObjectType);
				void RegisterThread();
				void RemoveDisconnectNotification(RegistrarThreadContext *,RegistrarThreadContext *);
				void UnregisterAlpcPort(System::Guid);
				void UnregisterMessageObject(System::String *,ScopeID);
				void UnregisterObject(System::String *,ScopeID,RegisteredObjectType);
				void UnregisterReverseConnectionPort(System::Guid);
				void _Construct(WindowIDManager *);
			};

			struct RemoteRegistrarServer$R
			{
				struct Microsoft__CoreUI__Registrar__IAlpcServerHost_Impl
				{
					virtual bool AcceptConnection(System::Object *,bool,unsigned int,unsigned int,System::IntPtr);
					virtual bool IsConnectionValid(System::Object *);
					virtual void InvalidateConnection(System::Object *);
					virtual void OnClientDisconnected(System::Object *,System::IntPtr);
					virtual void OnInvalidBuffer(System::Object *,unsigned int);
					virtual void SetConnectionContext(System::Object *,System::IntPtr);
					virtual void UnformatAndInvokeMethod(System::Object *,void *,unsigned int);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static RemoteRegistrarServer$R::Microsoft__CoreUI__Registrar__IAlpcServerHost_Impl const s_Microsoft__CoreUI__Registrar__IAlpcServerHost_Impl;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,unsigned int);
				static void InitializeCppInstance(void *);
			};

			struct RemoteRegistrarServerReceiveThunk
			{
				long RegisterConversation(wchar_t const *,wchar_t const *,ScopeID *,Conversations::ConversationInfo *,RoutingInfo *,HIDENTITY *);
				long RegisterPendingConversationClientForServer(wchar_t const *,ScopeID *,unsigned int,Conversations::ConversationPeerInfo *);
			};

			struct ScopeID
			{
				static ScopeID get_CurrentProcess();
				static ScopeID get_Local();
				static ScopeID get_System();
			};

			struct ServerConversationOperations
			{
				static ConversationClientConnectionInfo * ConjurePendingConversationClient(RegisteredConversation *,unsigned int,unsigned int,RegisteredConversationServer *);
				static void CleanupForDepartedThread(RegistrarData *,RegistrarThreadContext *);
				static void ConnectPendingConversationClient(RegistrarData *,System::String *,ScopeID,unsigned int,unsigned int,unsigned int);
				static void FindPendingConversationClient(RegistrarData *,System::String *,ScopeID,unsigned int,unsigned int,unsigned int);
				static void RegisterConversation(RegistrarData *,System::String *,System::String *,ScopeID,Conversations::ConversationInfo,RoutingInfo,HIDENTITY);
				static void RegisterConversationClient(RegistrarData *,System::String *,ScopeID,unsigned int);
				static void RegisterPendingConversationClientForServer(RegistrarData *,System::String *,ScopeID,unsigned int,Conversations::ConversationPeerInfo);
				static void ReleaseConversationClient(RegistrarData *,System::String *,ScopeID,unsigned int);
				static void ReleaseConversationClientConnection(RegistrarData *,System::String *,ScopeID,unsigned int,unsigned int,unsigned int);
				static void ReleaseConversationServer(RegistrarData *,System::String *,ScopeID,unsigned int);
				static void TellClientAboutNewServer(RegistrarData *,RegisteredConversationClient *,RegisteredConversationServer *);
				static void TellClientsAboutNewServer(RegistrarData *,RegisteredConversation *,RegisteredConversationServer *);
				static void UnregisterConversation(RegistrarData *,System::String *,ScopeID);
			};

			class ServerMessageCallSendHost
			{
				virtual long SubmitBuffer(unsigned __int64 *,unsigned int,void *,unsigned int);
			};

			struct SystemWindowIDManager
			{
				WindowID Microsoft__CoreUI__IExportSystemWindowIDManager__AllocateWindowID(ProcessID,ThreadID,int,WindowIDPropertyValue *);
				static IExportSystemWindowIDManager * Create();
				virtual void OnDispose();
				void Microsoft__CoreUI__IExportSystemWindowIDManager__FreeWindowID(WindowID);
				void Microsoft__CoreUI__IExportSystemWindowIDManager__GetWindowIDInfo(WindowID,WindowIDInfo *);
				void Microsoft__CoreUI__IExportSystemWindowIDManager__GetWindowIDProperties(WindowID,int,WindowIDPropertyValue *,unsigned int &);
			};

			struct SystemWindowIDManager$R
			{
				struct Microsoft__CoreUI__IExportSystemWindowIDManager_Impl
				{
					virtual WindowID AllocateWindowID(System::Object *,ProcessID,ThreadID,int,WindowIDPropertyValue *);
					virtual void FreeWindowID(System::Object *,WindowID);
					virtual void GetWindowIDInfo(System::Object *,WindowID,WindowIDInfo *);
					virtual void GetWindowIDProperties(System::Object *,WindowID,int,WindowIDPropertyValue *,unsigned int &);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static SystemWindowIDManager$R::Microsoft__CoreUI__IExportSystemWindowIDManager_Impl const s_Microsoft__CoreUI__IExportSystemWindowIDManager_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct SystemWindowIDManager_Client
			{
				Messaging::MessagingResults GetWindowIDProperties(WindowID,int,WindowIDPropertyValue *,unsigned int &);
				static bool Connect(Cn::ParamRef<SystemWindowIDManager_Client>);
				void Dispose();
			};

			struct SystemWindowIDManager_Client$R
			{
				struct Microsoft__CoreUI__Registrar__IAlpcClientHost_Impl
				{
					virtual void OnServerDisconnected(System::Object *);
					virtual void UnformatAndInvokeMethod(System::Object *,void *,unsigned int);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static SystemWindowIDManager_Client$R::Microsoft__CoreUI__Registrar__IAlpcClientHost_Impl const s_Microsoft__CoreUI__Registrar__IAlpcClientHost_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct SystemWindowIDManager_Server
			{
				void AllocateWindowID(unsigned int,unsigned int,WindowIDPropertyValue);
				void AllocateWindowID(unsigned int,unsigned int,WindowIDPropertyValue_1D *);
				void GetWindowIDProperties(WindowID,WindowIDPropertyValue);
				void _Construct(WindowIDManager *);
			};

			struct SystemWindowIDManager_Server$R
			{
				struct Microsoft__CoreUI__Registrar__IAlpcServerHost_Impl
				{
					virtual bool AcceptConnection(System::Object *,bool,unsigned int,unsigned int,System::IntPtr);
					virtual bool IsConnectionValid(System::Object *);
					virtual void InvalidateConnection(System::Object *);
					virtual void OnClientDisconnected(System::Object *,System::IntPtr);
					virtual void OnInvalidBuffer(System::Object *,unsigned int);
					virtual void SetConnectionContext(System::Object *,System::IntPtr);
					virtual void UnformatAndInvokeMethod(System::Object *,void *,unsigned int);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static SystemWindowIDManager_Server$R::Microsoft__CoreUI__Registrar__IAlpcServerHost_Impl const s_Microsoft__CoreUI__Registrar__IAlpcServerHost_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct WindowIDManager
			{
				Messaging::MessagingResults AllocateWindowID(unsigned int,unsigned int,WindowIDPropertyValue_1D *,WindowID &);
				Messaging::MessagingResults ClearWindowIDProperties(WindowID,unsigned int,WindowIDPropertyValue_1D *);
				Messaging::MessagingResults ClearWindowIDProperties(WindowID,unsigned int,int,WindowIDPropertyValue *);
				Messaging::MessagingResults ComputeIdentity(WindowID &);
				Messaging::MessagingResults FreeWindowIDWorker(WindowID,unsigned int,bool);
				Messaging::MessagingResults FreeWindowInstanceEntry(WindowID,unsigned int,bool,unsigned int &);
				Messaging::MessagingResults GetWindowIDInfo(WindowID,WindowIDInfo &);
				Messaging::MessagingResults GetWindowIDProperties(WindowID,WindowIDPropertyValue_1D *,unsigned int &);
				Messaging::MessagingResults GetWindowIDProperties(WindowID,int,WindowIDPropertyValue *,unsigned int &);
				Messaging::MessagingResults SetWindowIDProperties(WindowID,unsigned int,WindowIDPropertyValue_1D *);
				Messaging::MessagingResults SetWindowIDProperties(WindowID,unsigned int,int,WindowIDPropertyValue *);
				bool ReserveUnusedGroup(unsigned int &,Cn::ParamRef<HIDENTITYAllocatorWrapper>);
				static Identity::IdentityTable s_identityTable;
				static bool GetWindowEntry_Locked(WindowID,System::UIntPtr &);
				void AllocateWindowInstanceEntry(WindowID,unsigned int,unsigned int,int,WindowIDPropertyValue *);
				void CleanUpForDepartedThread(unsigned int,unsigned int);
				void ReclaimGroup(unsigned int);
				void RegisterRpcInterface();
				void UnregisterRpcInterface();
				void _Construct(bool);
			};

			struct WindowIDManager$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,unsigned __int64,Identity::IIdentityObject *,unsigned __int64,bool);
				static void InitializeCppInstance(void *);
			};

			struct WindowIDPropertyMarshalHelper
			{
				GetWindowIDPropertiesResponse * WrapGetIDPropertiesResponse(WindowIDPropertyValue_1D *,unsigned int);
				WindowIDPropertyMarshalHelper(WindowIDPropertyMarshalHelper const &);
				WindowIDPropertyValue_1D * GetArray(int);
				WindowIDPropertyValue_1D * PointerToArray(int,WindowIDPropertyValue *);
				void UnpackGetIDsResponse(GetWindowIDPropertiesResponse *,WindowIDPropertyValue *,unsigned int &);
				~WindowIDPropertyMarshalHelper();
			};

			struct WindowValidator
			{
				virtual long QueryInterface(Cn::Com::IID const *,void * *);
				virtual long ValidateWindowId(WindowID);
				virtual long ValidateWindowIdAndOwner(WindowID,unsigned int);
				virtual unsigned int AddRef();
				virtual unsigned int Release();
			};

			Cn::DllName g_dllServicePrivate;
			Registrar::ClientMessageCallSendHost g_clientSendHost;
			Registrar::ServerMessageCallSendHost g_serverSendHost;
			_RPC_BINDING_VECTOR * g_pBindings;
			unsigned long (* g_pfnWaitServiceState)(SC_HANDLE__ *,unsigned long,unsigned long,void *);
		};

		namespace Resources
		{
			struct ITrackableResource
			{
				System::Object * get_TrackerData();
				void set_TrackerData(System::Object *);
			};

			struct ITrackableResource$R
			{
				static Cn::TypeDefinition_66 const s_defType;
				static void const * const * const s_rgLookup;
			};

			struct ResourceMapping
			{
				static ResourceMapping * CreateCopy(Support::BufferInfo,Buffering::IBufferAllocator *);
				static unsigned int TryCreate(Messaging::MessageSession *,Messaging::Connection *,Support::BufferInfo &,Cn::ParamRef<System::Action>);
				virtual void OnDispose();
			};

			struct ResourceMapping$R
			{
				struct Microsoft__CoreUI__Resources__ITrackableResource_Impl
				{
					virtual System::Object * get_TrackerData(System::Object *);
					virtual void OnResourceRetired(System::Object *);
					virtual void set_TrackerData(System::Object *,System::Object *);
				};

				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ResourceMapping * New(Support::BufferInfo,System::Object *);
				static ResourceMapping$R::Microsoft__CoreUI__Resources__ITrackableResource_Impl const s_Microsoft__CoreUI__Resources__ITrackableResource_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ResourceTracker
			{
				ResourceTracker__Entry * TrackWorker(System::Object *);
				bool get_IsEmpty();
				static void CancelTracking(ITrackableResource *);
				static void Release(unsigned int);
				static void ScheduleRelease(ResourceTracker__Entry *);
				virtual void OnDispose();
				void CancelEntry(ResourceTracker__Entry *);
				void RetireEntry(ResourceTracker__Entry *);
				void _Construct(System::Action__bool *);
			};

			struct ResourceTracker$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ResourceTracker * New();
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,System::Object *);
				static void InitializeCppInstance(void *);
			};

			struct ResourceTracker__Entry
			{
				static ResourceTracker__Entry * FromID(unsigned int);
				virtual void OnDispose();
				void Release();
			};

			struct ResourceTracker__Entry$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct ResourceView
			{
				static Messaging::MessagingResults LookUpHandle(Dispatch::ThreadContext *,HRESOURCE,Cn::ParamRef<ResourceView>);
				static ResourceView * Callback_Create(Dispatch::ThreadContext *,HRESOURCE,Support::BufferInfo,ResourceType,RoutingInfo,unsigned int);
				void Dispose(bool);
				void ScheduleOrphanCheck();
			};

			struct ResourceView$R
			{
				struct Microsoft__CoreUI__Identity__IIdentityObject_Impl
				{
					virtual void HandleFreed(System::Object *,Identity::HandleFreeReason);
				};

				struct Microsoft__CoreUI__Resources__ITrackableResource_Impl
				{
					virtual System::Object * get_TrackerData(System::Object *);
					virtual void OnResourceRetired(System::Object *);
					virtual void set_TrackerData(System::Object *,System::Object *);
				};

				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ResourceView$R::Microsoft__CoreUI__Identity__IIdentityObject_Impl const s_Microsoft__CoreUI__Identity__IIdentityObject_Impl;
				static ResourceView$R::Microsoft__CoreUI__Resources__ITrackableResource_Impl const s_Microsoft__CoreUI__Resources__ITrackableResource_Impl;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,System::Object *);
				static void InitializeCppInstance(void *);
			};

		};

		struct RoutingInfo
		{
			System::String * ToString();
			bool get_HasValidConnectionID();
			static RoutingInfo Invalid;
			static bool op_Equality(RoutingInfo,RoutingInfo);
			static bool op_Inequality(RoutingInfo,RoutingInfo);
			void _Construct(HIDENTITY,System::Guid);
		};

		struct RoutingInfo$R
		{
			static Cn::TypeDefinition_66 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct RoutingInfo__Boxed
		{
			virtual System::String * ToString();
		};

		namespace Services
		{
			struct ExternalThreadEndpoint
			{
				virtual void OnDispose();
			};

			struct ExternalThreadEndpoint$R
			{
				static Cn::MethodDefinition const * const s_rgMethodEntries;
				static Cn::TypeDefinition_83 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static unsigned short const * const s_rgParameterEntries;
				static void InitializeCppInstance(void *);
				static void Reflection__OnDispose(void *,void * *,void * *);
				static void Reflection___Construct(void *,void * *,void * *);
			};

			struct ThreadEndpoint
			{
				virtual void Callback_OnMessageCore(Support::BufferInfo);
				void NotifyLocalConnectionCreated(unsigned int,unsigned int,unsigned int);
				void NotifyLocalConnectionDisposed(unsigned int,unsigned int);
			};

			struct ThreadEndpoint$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static ThreadEndpoint * New(System::Object *,Dispatch::ThreadContext *,HIDENTITY);
				static void InitializeCppInstance(void *);
			};

			struct ThreadEndpointCaller
			{
				static void Callback_RequestResourceView(Messaging::MessageSession *,HENDPOINT,HRESOURCE,Support::BufferInfo,Resources::ResourceType,RoutingInfo,unsigned int);
				static void FreeHIDENTITY(Messaging::MessageSession *,HENDPOINT,HIDENTITY);
				static void LocalPingAndWait(Messaging::MessageSession *,HENDPOINT,unsigned int,unsigned int,System::IntPtr,unsigned int,Support::Win32Handle);
				static void NotifyHIDENTITYFreed(Messaging::MessageSession *,HENDPOINT,RoutingInfo);
				static void NotifyLocalConnectionCreated(Messaging::MessageSession *,HENDPOINT,unsigned int,unsigned int,unsigned int);
				static void NotifyLocalConnectionDisposed(Messaging::MessageSession *,HENDPOINT,unsigned int,unsigned int);
				static void ReleaseResourceMapping(Messaging::MessageSession *,HENDPOINT,unsigned int);
				static void ReserveHIDENTITY(Messaging::MessageSession *,HENDPOINT,HIDENTITY);
			};

			struct ThreadEndpointMessageCallSendHost
			{
				virtual long AllocateBuffer(unsigned __int64 *,unsigned int,unsigned int,void * *);
				virtual long SubmitBuffer(unsigned __int64 *,unsigned int,void *,unsigned int);
			};

		};

		struct SharedDisposableObject
		{
			static System::Object * get_ExternalObjectOwner();
			virtual void OnDispose();
			virtual void OnFinalRelease(bool);
			virtual void OnFinalUsage();
			virtual void OnInitialExport();
		};

		struct SharedDisposableObject$R
		{
			struct Cn__IExportInstance_Impl
			{
				virtual void OnFinalRelease(System::Object *,bool);
				virtual void OnInitialExport(System::Object *);
			};

			static Cn::TypeDefinition_66 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static SharedDisposableObject$R::Cn__IExportInstance_Impl const s_Cn__IExportInstance_Impl;
		};

		namespace Support
		{
			struct Bits
			{
				static bool ClearBitIndex(int *,int,int);
				static bool SetBitIndex(int *,int,int);
				static int FindFirstUnsetBit(int *,int,int,bool);
				static int FindHighestBit(unsigned char);
				static int FindLowestBit(int *,int,int);
				static int FindLowestBit(int);
			};

			struct DoubleListItem
			{
				virtual System::String * ToString();
				virtual void OnDispose();
			};

			struct DoubleListItem$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct DoubleListItem__Chain$R
			{
				static Cn::TypeDefinition_66 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct DoubleListItem__FIFO
			{
				DoubleListItem * get_Head();
				bool Append(DoubleListItem *);
				virtual void OnDispose();
				void Advance();
				void Remove(DoubleListItem *);
			};

			struct DoubleListItem__FIFO$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct DoubleListItem__FIFO_1D
			{
				DoubleListItem__FIFO * _SetElement(int,DoubleListItem__FIFO *);
			};

			struct DoubleListItem__FIFO_1D$R
			{
				static Cn::TypeDefinition_4 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct IoCompletionPort
			{
				bool RemoveCompletion(System::IntPtr &);
				static IoCompletionPort Create();
				void ReportAssociationError(WaitCompletionPacket,Win32Handle,System::IntPtr,unsigned int);
			};

			struct Memory
			{
				static void * AllocateCopy(void *,unsigned int);
				static void Copy(void *,void *,int);
				static void Free(void *);
				static void InitClass(bool);
			};

			struct MessageCallReceiveHost<1>
			{
				virtual long NotifyInvalid(MsgCallState *);
				virtual long NotifyProtocolViolation(MsgCallState *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct MessageCallReceiveHost<28>
			{
				virtual long NotifyInvalid(MsgCallState *);
				virtual long NotifyProtocolViolation(MsgCallState *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct MessageCallReceiveHost<90>
			{
				virtual long NotifyInvalid(MsgCallState *);
				virtual long NotifyProtocolViolation(MsgCallState *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct MessageCallReceiveHost<91>
			{
				virtual long NotifyInvalid(MsgCallState *);
				virtual long NotifyProtocolViolation(MsgCallState *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct MessageCallReceiveHost<93>
			{
				virtual long NotifyInvalid(MsgCallState *);
				virtual long NotifyProtocolViolation(MsgCallState *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct MessageCallReceiveHost<94>
			{
				virtual long NotifyInvalid(MsgCallState *);
				virtual long NotifyProtocolViolation(MsgCallState *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct MessageCallSendHost
			{
				virtual long CancelBuffer(unsigned __int64 *,unsigned int,void *,unsigned int);
				virtual long NotifyInvalid(MsgCallState *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RentalWait
			{
				static void DoWaitWithThread(unsigned int,Win32Handle);
				static void ForDispatchThread(Win32Event);
			};

			struct ReserveCompletionPacket
			{
				static ReserveCompletionPacket Create();
			};

			struct SkipList
			{
				System::Object * get_FirstItem();
				bool MergeTrailingEdge(System::Object_1D *,int,System::Object *,System::Object_1D *);
				bool Remove(System::Object *);
				bool get_IsEmpty();
				int MergeLeadingEdge(System::Object_1D *,int,System::Object *,System::Object_1D *);
				int PrepareSearchUpdateVector(System::Object *,SkipList__SearchMode);
				static System::Random * GetDefaultRandomNumberGenerator();
				virtual void OnDispose();
				void FinalizeSplit(SkipList *);
				void FullMerge(System::Object_1D *,int);
				void GrowListHeight(int);
				void MergeFinalSegment(System::Object_1D *,int,System::Object_1D *);
				void MergeSwap(Cn::ParamRef<System::Object_1D>,int &,Cn::ParamRef<System::Object_1D>,int &);
				void PrepareSplit(System::Object *,SkipList__SearchMode);
				void ResizeArrays(int);
				void SplitLeft(System::Object *,bool,SkipList *);
				void TrimListHeight();
			};

			struct SkipList$R
			{
				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static SkipList * New(System::Collections::IComparer *);
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct SkipList__Enumerator
			{
				System::Object * get_Current();
				bool MoveNext();
				~SkipList__Enumerator();
			};

			struct SystemTime
			{
				static __int64 get_TickCount();
			};

			struct SystemTime$R
			{
				static Cn::TypeDefinition_64 const s_defType;
				static SystemTime * New();
				static void InitializeCppInstance(void *);
			};

			struct ThreadPoolWait
			{
				bool RegisterWait(Win32Handle,void (*)(_TP_CALLBACK_INSTANCE *,void *,_TP_WAIT *,long),void *);
			};

			struct Utils
			{
				static unsigned int ComputeDivideShift(unsigned int);
			};

			struct WaitCompletionPacket
			{
				bool TryCancel(bool &);
			};

			struct Win32Event
			{
				static void Set(Win32Handle);
				void Reset();
			};

			struct Win32Event$R
			{
				struct System__IDisposable_Impl
				{
					virtual void Dispose(System::Object *);
				};

				static Win32Event$R::System__IDisposable_Impl const s_System__IDisposable_Impl;
			};

			struct Win32Handle
			{
				static void SafeClose(Win32Handle &);
			};

			struct Win32Handle$R
			{
				static Cn::TypeDefinition_66 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct Win32Handle_1D
			{
				Win32Handle_1D * InitializeItems(int,...);
			};

			struct Win32Handle_1D$R
			{
				static Cn::TypeDefinition_4 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct Win32Handle__Boxed
			{
				virtual int GetHashCode();
			};

			unsigned int g_uSharedDataGranularity;
		};

		namespace Threading
		{
			struct InterconnectReceiver
			{
				virtual void OnDispose();
				void Initialize(unsigned int,Support::Win32Handle);
			};

			struct InterconnectReceiver$R
			{
				static Cn::TypeDefinition_66 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct InterconnectSender
			{
				bool MonitorTargetQueue();
				static bool Connect(Messaging::Connection *,Cn::ParamRef<InterconnectSender>);
				virtual void Finalize();
				virtual void OnDispose();
				void DisposeWorker(bool);
				void Send(Buffering::BufferSet *,unsigned int,Cn::Threading::InterconnectBufferFlags,Cn::Threading::InterconnectBufferFlags &);
				void TryDeferCloseConnection();
				void UnmonitorTargetQueue();
			};

			struct InterconnectSender$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static short const * const s_rgReferenceFields;
				static void Delegate0(System::Delegate *,Dispatch::WaitStatus,Support::Win32Handle);
				static void Delegate1(System::Delegate *,System::Object *);
				static void InitializeCppInstance(void *);
			};

		};

		struct ValidationException
		{
			static ValidationException * get_ArgumentInvalid();
			static ValidationException * get_ArgumentNull();
			static ValidationException * get_InvalidOperation();
			static int GetHResult(ErrorSubsystems,unsigned short);
		};

		struct ValidationException$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static ValidationException * New(ValidationException__GeneralErrors);
			static void InitializeCppInstance(void *);
		};

		struct Win32Exception$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct WindowID$R
		{
			static Cn::TypeDefinition_66 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct WindowIDInfo$R
		{
			static Cn::TypeDefinition_66 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct WindowIDPropertyValue
		{
			static void ServerValidateWorker(WindowIDPropertyValue_1D *,bool,int);
			static void ThrowValidationError(bool,ProtocolError);
			static void ValidateWorker(int,WindowIDPropertyValue *,bool,int,bool);
		};

		struct WindowIDPropertyValue$R
		{
			static Cn::TypeDefinition_66 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct WindowIDPropertyValue_1D
		{
			WindowIDPropertyValue_1D * InitializeItems(int,...);
		};

		struct WindowIDPropertyValue_1D$R
		{
			static Cn::TypeDefinition_4 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct WindowIDPropertyValue_1D_1D$R
		{
			static Cn::TypeDefinition_4 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

	};

	namespace WRL
	{
		struct ActivationFactory<Implements<FtmBase,Windows::System::IDispatcherQueueControllerStatics>,Details::Nil,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::System::IDispatcherQueueStatics>,Details::Nil,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AgileActivationFactory<Windows::System::IDispatcherQueueControllerStatics,Details::Nil,Details::Nil,0>
		{
			AgileActivationFactory<Windows::System::IDispatcherQueueControllerStatics,Details::Nil,Details::Nil,0>();
		};

		struct AgileActivationFactory<Windows::System::IDispatcherQueueStatics,Details::Nil,Details::Nil,0>
		{
			AgileActivationFactory<Windows::System::IDispatcherQueueStatics,Details::Nil,Details::Nil,0>();
		};

		struct AgileEventSource<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,IInspectable *>,InvokeModeOptions<2> >
		{
			~AgileEventSource<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,IInspectable *>,InvokeModeOptions<2> >();
		};

		struct AgileEventSource<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,Windows::System::DispatcherQueueShutdownStartingEventArgs *>,InvokeModeOptions<2> >
		{
			~AgileEventSource<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,Windows::System::DispatcherQueueShutdownStartingEventArgs *>,InvokeModeOptions<2> >();
		};

		struct AgileEventSource<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueueTimer *,IInspectable *>,InvokeModeOptions<2> >
		{
			long Add(Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueueTimer *,IInspectable *> *,EventRegistrationToken *);
		};

		class ComPtr<DeferrableEventArgs<Windows::System::IDispatcherQueueShutdownStartingEventArgs,Windows::System::ShutdownStartingEventArgsImpl> >
		{
		protected:
			void InternalAddRef();
		};

		struct ComPtr<Details::EventTargetArray>
		{
			ComPtr<Details::EventTargetArray> & operator=(Details::EventTargetArray *);
			void Attach(Details::EventTargetArray *);
			~ComPtr<Details::EventTargetArray>();
		};

		class ComPtr<IAgileObject>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IAgileObject>();
		};

		class ComPtr<IAgileReference>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IAgileReference>();
		};

		class ComPtr<IAsyncInfo>
		{
		protected:
			void InternalAddRef();
		public:
			long As<Windows::Foundation::IAsyncAction>(Details::ComPtrRef<ComPtr<Windows::Foundation::IAsyncAction> >);
			~ComPtr<IAsyncInfo>();
		};

		class ComPtr<IExportDispatcherQueueInterop>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IExportDispatcherQueueInterop>();
		};

		struct ComPtr<IGlobalOptions>
		{
			~ComPtr<IGlobalOptions>();
		};

		class ComPtr<IMarshal>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IMessageSession>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			long As<IExportDispatcherQueueInterop>(Details::ComPtrRef<ComPtr<IExportDispatcherQueueInterop> >);
			~ComPtr<IMessageSession>();
		};

		class ComPtr<IMessageTimer>
		{
		protected:
			unsigned long InternalRelease();
		};

		struct ComPtr<IRestrictedErrorInfo>
		{
			~ComPtr<IRestrictedErrorInfo>();
		};

		struct ComPtr<IRpcOptions>
		{
			~ComPtr<IRpcOptions>();
		};

		struct ComPtr<IStream>
		{
			~ComPtr<IStream>();
		};

		class ComPtr<IUnknown>
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<IUnknown>();
			~ComPtr<IUnknown>();
		};

		class ComPtr<Windows::Foundation::IAsyncAction>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::IAsyncAction>();
		};

		class ComPtr<Windows::Foundation::IAsyncActionCompletedHandler>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			~ComPtr<Windows::Foundation::IAsyncActionCompletedHandler>();
		};

		class ComPtr<Windows::Foundation::IDeferral>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::IDeferralFactory>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,IInspectable *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,Windows::System::DispatcherQueueShutdownStartingEventArgs *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueueTimer *,IInspectable *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::System::DispatcherQueue>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			long As<Windows::System::IDispatcherQueue>(Details::ComPtrRef<ComPtr<Windows::System::IDispatcherQueue> >);
			void Attach(Windows::System::DispatcherQueue *);
			~ComPtr<Windows::System::DispatcherQueue>();
		};

		class ComPtr<Windows::System::DispatcherQueueAsyncHelper>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::System::DispatcherQueueAsyncHelper>();
		};

		class ComPtr<Windows::System::DispatcherQueueController>
		{
		protected:
			unsigned long InternalRelease();
		public:
			void Attach(Windows::System::DispatcherQueueController *);
			~ComPtr<Windows::System::DispatcherQueueController>();
		};

		struct ComPtr<Windows::System::DispatcherQueueTimer>
		{
			~ComPtr<Windows::System::DispatcherQueueTimer>();
		};

		class ComPtr<Windows::System::IDispatcherQueueController>
		{
		protected:
			void InternalAddRef();
		};

		struct ComPtr<Windows::System::IDispatcherQueueHandler>
		{
			~ComPtr<Windows::System::IDispatcherQueueHandler>();
		};

		class ComPtr<Windows::System::ShutdownStartingEventArgsImpl>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::System::ShutdownStartingEventArgsImpl>();
		};

		class DeferrableEventArgs<Windows::System::IDispatcherQueueShutdownStartingEventArgs,Windows::System::ShutdownStartingEventArgsImpl>
		{
			long Complete();
		public:
			virtual long GetDeferral(Windows::Foundation::IDeferral * *);
			void InvokeAllFinished();
		};

		namespace Details
		{
			struct ComPtrRef<AgileRef>
			{
				operator AgileRef *();
			};

			struct EventTargetArray
			{
				EventTargetArray();
				long RuntimeClassInitialize(unsigned __int64);
				void AddTail(IUnknown *,void *);
			};

			struct MakeAllocator<Windows::System::DispatcherQueue>
			{
				~MakeAllocator<Windows::System::DispatcherQueue>();
			};

			struct MakeAllocator<Windows::System::DispatcherQueueAsyncHelper>
			{
				~MakeAllocator<Windows::System::DispatcherQueueAsyncHelper>();
			};

			struct MakeAllocator<Windows::System::DispatcherQueueController>
			{
				~MakeAllocator<Windows::System::DispatcherQueueController>();
			};

			struct MakeAllocator<Windows::System::DispatcherQueueTimer>
			{
				~MakeAllocator<Windows::System::DispatcherQueueTimer>();
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
				static long AsIID<ActivationFactory<Implements<FtmBase,Windows::System::IDispatcherQueueControllerStatics>,Nil,Nil,0> >(ActivationFactory<Implements<FtmBase,Windows::System::IDispatcherQueueControllerStatics>,Nil,Nil,0> *,_GUID const &,void * *);
				static long AsIID<ActivationFactory<Implements<FtmBase,Windows::System::IDispatcherQueueStatics>,Nil,Nil,0> >(ActivationFactory<Implements<FtmBase,Windows::System::IDispatcherQueueStatics>,Nil,Nil,0> *,_GUID const &,void * *);
			};

			class RuntimeClassBaseT<1>
			{
			protected:
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,DeferrableEventArgs<Windows::System::IDispatcherQueueShutdownStartingEventArgs,Windows::System::ShutdownStartingEventArgsImpl>,FtmBase,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,DeferrableEventArgs<Windows::System::IDispatcherQueueShutdownStartingEventArgs,Windows::System::ShutdownStartingEventArgsImpl>,FtmBase,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::System::IDispatcherQueueTimer,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::System::IDispatcherQueueTimer,FtmBase> *,_GUID const &,void * *);
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,DeferrableEventArgs<Windows::System::IDispatcherQueueShutdownStartingEventArgs,Windows::System::ShutdownStartingEventArgsImpl>,FtmBase,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,DeferrableEventArgs<Windows::System::IDispatcherQueueShutdownStartingEventArgs,Windows::System::ShutdownStartingEventArgsImpl>,FtmBase,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::System::IDispatcherQueue,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::System::IDispatcherQueue,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::System::IDispatcherQueueController,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::System::IDispatcherQueueController,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::System::IDispatcherQueueTimer,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::System::IDispatcherQueueTimer,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,1,IUnknown>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,1,IWeakReference>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,1,Implements<RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,IInspectable *>,FtmBase> >
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,1,Implements<RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,Windows::System::DispatcherQueueShutdownStartingEventArgs *>,FtmBase> >
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,1,Implements<RuntimeClassFlags<2>,Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueueTimer *,IInspectable *>,FtmBase> >
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,1,Windows::Foundation::IDeferralCompletedHandler>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct WeakReferenceImpl
			{
				WeakReferenceImpl(IUnknown *);
				virtual long Resolve(_GUID const &,IInspectable * *);
			};

			Details::WeakReferenceImpl * CreateWeakReference(IUnknown *);
			bool TerminateMap(Details::ModuleBase *,wchar_t const *,bool);
			long CreateActivationFactory<Windows::System::DispatcherQueueControllerStatic>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::System::DispatcherQueueStatic>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateAgileHelper<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,IInspectable *> >(Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,IInspectable *> *,Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,IInspectable *> * *);
			long CreateAgileHelper<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,Windows::System::DispatcherQueueShutdownStartingEventArgs *> >(Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,Windows::System::DispatcherQueueShutdownStartingEventArgs *> *,Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,Windows::System::DispatcherQueueShutdownStartingEventArgs *> * *);
			long CreateAgileHelper<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueueTimer *,IInspectable *> >(Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueueTimer *,IInspectable *> *,Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueueTimer *,IInspectable *> * *);
			long GetActivationFactory<1>(Details::ModuleBase *,wchar_t const *,HSTRING__ *,IActivationFactory * *);
			long GetCacheEntry(Details::ModuleBase *,unsigned int *,_GUID const &,Details::CreatorMap const *,IUnknown * *);
			long GetClassObject<1>(Details::ModuleBase *,wchar_t const *,_GUID const &,_GUID const &,void * *);
			long MakeAndInitialize<EventTargetArray,EventTargetArray,unsigned __int64 &>(Details::EventTargetArray * *,unsigned __int64 &);
			long MakeAndInitialize<Windows::System::DispatcherQueue,Windows::System::DispatcherQueue,bool &,bool &>(Windows::System::DispatcherQueue * *,bool &,bool &);
			long MakeAndInitialize<Windows::System::ShutdownStartingEventArgsImpl,Windows::System::ShutdownStartingEventArgsImpl,Windows::System::DispatcherQueue * &>(Windows::System::ShutdownStartingEventArgsImpl * *,Windows::System::DispatcherQueue * &);
		};

		class EventSource<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,IInspectable *>,InvokeModeOptions<2> >
		{
			long AddInternal(Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,IInspectable *> *,void *,EventRegistrationToken *);
		public:
			long Remove(EventRegistrationToken);
		};

		class EventSource<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,Windows::System::DispatcherQueueShutdownStartingEventArgs *>,InvokeModeOptions<2> >
		{
			long AddInternal(Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueue *,Windows::System::DispatcherQueueShutdownStartingEventArgs *> *,void *,EventRegistrationToken *);
		public:
			long Remove(EventRegistrationToken);
		};

		class EventSource<Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueueTimer *,IInspectable *>,InvokeModeOptions<2> >
		{
			long AddInternal(Windows::Foundation::ITypedEventHandler<Windows::System::DispatcherQueueTimer *,IInspectable *> *,void *,EventRegistrationToken *);
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
			virtual long RegisterCOMObject(wchar_t const *,_GUID *,IClassFactory * *,unsigned long *,unsigned int);
			virtual long RegisterWinRTObject(wchar_t const *,wchar_t const * *,<unnamed-type-RO_REGISTRATION_COOKIE> * *,unsigned int);
			virtual long UnregisterCOMObject(wchar_t const *,unsigned long *,unsigned int);
			virtual long UnregisterWinRTObject(wchar_t const *,<unnamed-type-RO_REGISTRATION_COOKIE> *);
			virtual unsigned long DecrementObjectCount();
			virtual unsigned long IncrementObjectCount();
			virtual ~Module<1,Details::DefaultModule<1> >();
		};

		struct RuntimeClass<DeferrableEventArgs<Windows::System::IDispatcherQueueShutdownStartingEventArgs,Windows::System::ShutdownStartingEventArgsImpl>,FtmBase>
		{
			RuntimeClass<DeferrableEventArgs<Windows::System::IDispatcherQueueShutdownStartingEventArgs,Windows::System::ShutdownStartingEventArgsImpl>,FtmBase>();
		};

		struct RuntimeClass<Windows::System::IDispatcherQueue>
		{
			virtual ~RuntimeClass<Windows::System::IDispatcherQueue>();
		};

		namespace Wrappers
		{
			class HStringReference
			{
				void CreateReference(wchar_t const *,unsigned int,unsigned int);
			public:
				HStringReference<wchar_t const *>(wchar_t const * const &,Details::Dummy);
				~HStringReference();
			};

		};

		Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics * gCausality;
		_RTL_RUN_ONCE gCausalityInitOnce;
	};

};

struct PendingBatch
{
	static void CleanupList(PendingBatch * *,PendingBatch * *);
};

namespace System
{
	struct AccessViolationException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct Action
	{
		void Invoke();
	};

	struct Action$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Action__Microsoft_CoreUI_Support_BufferInfo
	{
		void Invoke(Microsoft::CoreUI::Support::BufferInfo);
	};

	struct Action__Microsoft_CoreUI_Support_BufferInfo$R
	{
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Action__Microsoft_CoreUI_Support_Win32Handle
	{
		void Invoke(Microsoft::CoreUI::Support::Win32Handle);
	};

	struct Action__Microsoft_CoreUI_Support_Win32Handle$R
	{
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Action__bool
	{
		void Invoke(bool);
	};

	struct Action__bool$R
	{
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Action__object
	{
		void Invoke(Object *);
	};

	struct Action__object$R
	{
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Action__object__Microsoft_CoreUI_Support_BufferInfo$R
	{
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Action__object__Microsoft_CoreUI_Support_Win32Handle$R
	{
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Action__object__bool
	{
		void Invoke(Object *,bool);
	};

	struct Action__object__bool$R
	{
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Action__object__object
	{
		void Invoke(Object *,Object *);
	};

	struct Action__object__object$R
	{
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Action__object__uint
	{
		void Invoke(Object *,unsigned int);
	};

	struct Action__object__uint$R
	{
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Action__uint
	{
		void Invoke(unsigned int);
	};

	struct Action__uint$R
	{
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Action__uint__uint
	{
		void Invoke(unsigned int,unsigned int);
	};

	struct Action__uint__uint$R
	{
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct ApplicationException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct ArgumentException$R
	{
		static ArgumentException * New();
		static ArgumentException * New(String *);
		static ArgumentException * New(String *,String *);
		static Cn::TypeDefinition_67 const s_defType;
		static short const * const s_rgReferenceFields;
		static void InitializeCppInstance(void *);
	};

	struct ArgumentNullException$R
	{
		static ArgumentNullException * New();
		static ArgumentNullException * New(String *);
		static ArgumentNullException * New(String *,String *);
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct ArgumentOutOfRangeException$R
	{
		static ArgumentOutOfRangeException * New();
		static ArgumentOutOfRangeException * New(String *);
		static ArgumentOutOfRangeException * New(String *,String *);
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct ArithmeticException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	class Array
	{
		static Array * InternalAllocate(Cn::Context *,Cn::TypeDefinition const *,int,bool);
		static void ValidateElementType(Cn::TypeDefinition const *);
	protected:
		virtual ~Array();
		void _InitializeObjects(int,char *);
		void _SetItem(int,Object *);
	public:
		Array * InternalClone();
		Object * InternalGetValue(int);
		int _GetElementSize();
		static Array * InternalNew(Cn::TypeDefinition const *,int);
		static int IndexOf(Array *,Object *,int,int);
		static int InternalIndexOfPrimitive(Array *,int,int,void *);
		static void Clear(Array *,int,int);
		static void Copy(Array *,int,Array *,int,int);
		static void InternalClear(Array *,int,int);
		static void InternalCopy(Array *,int,Array *,int,int);
		void InternalSetValue(int,Object *);
		void SetValue(Object *,int);
	};

	struct Array$R
	{
		struct System__Collections__ICollection_Impl
		{
			virtual Object * get_SyncRoot(Object *);
			virtual bool get_IsSynchronized(Object *);
			virtual int get_Count(Object *);
			virtual void CopyTo(Object *,Array *,int);
		};

		struct System__Collections__IEnumerable_Impl
		{
			virtual Collections::IEnumerator * GetEnumerator(Object *);
		};

		struct System__Collections__IList_Impl
		{
			virtual Object * get_Item(Object *,int);
			virtual bool Contains(Object *,Object *);
			virtual bool get_IsFixedSize(Object *);
			virtual bool get_IsReadOnly(Object *);
			virtual int Add(Object *,Object *);
			virtual int IndexOf(Object *,Object *);
			virtual void Clear(Object *);
			virtual void Insert(Object *,int,Object *);
			virtual void Remove(Object *,Object *);
			virtual void RemoveAt(Object *,int);
			virtual void set_Item(Object *,int,Object *);
		};

		struct System__ICloneable_Impl
		{
			virtual Object * Clone(Object *);
		};

		static Array$R::System__Collections__ICollection_Impl const s_System__Collections__ICollection_Impl;
		static Array$R::System__Collections__IEnumerable_Impl const s_System__Collections__IEnumerable_Impl;
		static Array$R::System__Collections__IList_Impl const s_System__Collections__IList_Impl;
		static Array$R::System__ICloneable_Impl const s_System__ICloneable_Impl;
		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
	};

	struct ArrayTypeMismatchException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct Array__ArrayEnumerator$R
	{
		struct System__Collections__IEnumerator_Impl
		{
			virtual Object * get_Current(Object *);
			virtual bool MoveNext(Object *);
			virtual void Reset(Object *);
		};

		static Array__ArrayEnumerator$R::System__Collections__IEnumerator_Impl const s_System__Collections__IEnumerator_Impl;
		static Cn::TypeDefinition_65 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static short const * const s_rgReferenceFields;
		static void InitializeCppInstance(void *);
	};

	struct BadImageFormatException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct Boolean
	{
		bool Equals(Object *);
		int CompareTo(Object *);
		int CompareTo(bool);
		static String * get_FalseString();
		static String * get_TrueString();
		static bool TryParse(String *,bool &);
	};

	struct Boolean$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		static Boolean$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static Cn::MethodDefinition const * const s_rgMethodEntries;
		static Cn::PropertyDefinition const * const s_rgPropertyEntries;
		static Cn::TypeDefinition_114 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static unsigned short const * const s_rgParameterEntries;
		static void InitializeCppInstance(void *);
		static void Reflection__CompareTo__1(void *,void * *,void * *);
		static void Reflection__CompareTo__2(void *,void * *,void * *);
		static void Reflection__Equals__3(void *,void * *,void * *);
		static void Reflection__Equals__4(void *,void * *,void * *);
		static void Reflection__GetHashCode(void *,void * *,void * *);
		static void Reflection__ToString__10(void *,void * *,void * *);
		static void Reflection__ToString__9(void *,void * *,void * *);
		static void Reflection__TryParse(void *,void * *,void * *);
		static void Reflection__get_FalseString(void *,void * *,void * *);
		static void Reflection__get_TrueString(void *,void * *,void * *);
	};

	struct Boolean_ByRef$R
	{
		static Cn::TypeDefinition_4 const s_defType;
	};

	struct Boolean__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct Boolean__Statics$R
	{
		static void UninitializeType();
	};

	struct Byte$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		struct System__IFormattable_Impl
		{
			virtual String * ToString(Object *,String *,IFormatProvider *);
		};

		static Byte$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static Byte$R::System__IFormattable_Impl const s_System__IFormattable_Impl;
		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Byte_1D$R
	{
		static Cn::TypeDefinition_4 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Byte__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct Char$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		static Char$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Char_1D$R
	{
		static Cn::TypeDefinition_4 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Char__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	namespace Collections
	{
		struct ArrayList
		{
			Array * ToArray(Type);
			Object * get_Item(int);
			bool Contains(Object *);
			int Add(Object *);
			void CheckIndex(int);
			void EnsureCapacity(int);
			void Insert(int,Object *);
			void Remove(Object *);
			void RemoveAt(int);
		};

		struct ArrayList$R
		{
			struct System__Collections__ICollection_Impl
			{
				virtual Object * get_SyncRoot(Object *);
				virtual bool get_IsSynchronized(Object *);
				virtual int get_Count(Object *);
				virtual void CopyTo(Object *,Array *,int);
			};

			struct System__Collections__IEnumerable_Impl
			{
				virtual IEnumerator * GetEnumerator(Object *);
			};

			struct System__Collections__IList_Impl
			{
				virtual Object * get_Item(Object *,int);
				virtual bool Contains(Object *,Object *);
				virtual bool get_IsFixedSize(Object *);
				virtual bool get_IsReadOnly(Object *);
				virtual int Add(Object *,Object *);
				virtual int IndexOf(Object *,Object *);
				virtual void Clear(Object *);
				virtual void Insert(Object *,int,Object *);
				virtual void Remove(Object *,Object *);
				virtual void RemoveAt(Object *,int);
				virtual void set_Item(Object *,int,Object *);
			};

			static ArrayList * New();
			static ArrayList$R::System__Collections__ICollection_Impl const s_System__Collections__ICollection_Impl;
			static ArrayList$R::System__Collections__IEnumerable_Impl const s_System__Collections__IEnumerable_Impl;
			static ArrayList$R::System__Collections__IList_Impl const s_System__Collections__IList_Impl;
			static Cn::TypeDefinition_65 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static short const * const s_rgReferenceFields;
			static void InitializeCppInstance(void *);
			static void InitializeType();
		};

		struct ArrayList__ArrayListEnumeratorSimple
		{
			bool MoveNext();
		};

		struct ArrayList__ArrayListEnumeratorSimple$R
		{
			struct System__Collections__IEnumerator_Impl
			{
				virtual Object * get_Current(Object *);
				virtual bool MoveNext(Object *);
				virtual void Reset(Object *);
			};

			static ArrayList__ArrayListEnumeratorSimple$R::System__Collections__IEnumerator_Impl const s_System__Collections__IEnumerator_Impl;
			static Cn::TypeDefinition_65 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static short const * const s_rgReferenceFields;
			static void InitializeCppInstance(void *);
			static void InitializeType();
		};

		namespace Generic
		{
			struct HashHelpers
			{
				static int GetPrime(int);
			};

			struct HashHelpers$R
			{
				static void InitializeType();
			};

			struct List__Microsoft_CoreUI_DesignPatterns_ChainLink
			{
				Microsoft::CoreUI::DesignPatterns::ChainLink get_Item(int);
				bool Contains(Microsoft::CoreUI::DesignPatterns::ChainLink);
				bool Remove(Microsoft::CoreUI::DesignPatterns::ChainLink);
				int IndexOf(Microsoft::CoreUI::DesignPatterns::ChainLink);
				static void VerifyValueType(Object *);
				void Add(Microsoft::CoreUI::DesignPatterns::ChainLink);
				void CopyTo(Array *,int);
				void EnsureCapacity(int);
				void Insert(int,Microsoft::CoreUI::DesignPatterns::ChainLink);
				void RemoveAt(int);
				void System__Collections__IList__set_Item(int,Object *);
				void set_Capacity(int);
			};

			struct List__Microsoft_CoreUI_DesignPatterns_ChainLink$R
			{
				struct System__Collections__ICollection_Impl
				{
					virtual Object * get_SyncRoot(Object *);
					virtual bool get_IsSynchronized(Object *);
					virtual int get_Count(Object *);
					virtual void CopyTo(Object *,Array *,int);
				};

				struct System__Collections__IEnumerable_Impl
				{
					virtual IEnumerator * GetEnumerator(Object *);
				};

				struct System__Collections__IList_Impl
				{
					virtual Object * get_Item(Object *,int);
					virtual bool Contains(Object *,Object *);
					virtual bool get_IsFixedSize(Object *);
					virtual bool get_IsReadOnly(Object *);
					virtual int Add(Object *,Object *);
					virtual int IndexOf(Object *,Object *);
					virtual void Clear(Object *);
					virtual void Insert(Object *,int,Object *);
					virtual void Remove(Object *,Object *);
					virtual void RemoveAt(Object *,int);
					virtual void set_Item(Object *,int,Object *);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static List__Microsoft_CoreUI_DesignPatterns_ChainLink * New();
				static List__Microsoft_CoreUI_DesignPatterns_ChainLink$R::System__Collections__ICollection_Impl const s_System__Collections__ICollection_Impl;
				static List__Microsoft_CoreUI_DesignPatterns_ChainLink$R::System__Collections__IEnumerable_Impl const s_System__Collections__IEnumerable_Impl;
				static List__Microsoft_CoreUI_DesignPatterns_ChainLink$R::System__Collections__IList_Impl const s_System__Collections__IList_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
				static void InitializeType();
			};

			struct List__Microsoft_CoreUI_DesignPatterns_ChainLink__Enumerator
			{
				bool MoveNext();
				~List__Microsoft_CoreUI_DesignPatterns_ChainLink__Enumerator();
			};

			struct List__Microsoft_CoreUI_DesignPatterns_ChainLink__Enumerator$R
			{
				struct System__Collections__IEnumerator_Impl
				{
					virtual Object * get_Current(Object *);
					virtual bool MoveNext(Object *);
					virtual void Reset(Object *);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static List__Microsoft_CoreUI_DesignPatterns_ChainLink__Enumerator New(List__Microsoft_CoreUI_DesignPatterns_ChainLink *);
				static List__Microsoft_CoreUI_DesignPatterns_ChainLink__Enumerator$R::System__Collections__IEnumerator_Impl const s_System__Collections__IEnumerator_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

			struct List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket
			{
				Microsoft::CoreUI::Registrar::RegistrationNameMaps__Ticket get_Item(int);
				bool Contains(Microsoft::CoreUI::Registrar::RegistrationNameMaps__Ticket);
				bool Remove(Microsoft::CoreUI::Registrar::RegistrationNameMaps__Ticket);
				int IndexOf(Microsoft::CoreUI::Registrar::RegistrationNameMaps__Ticket);
				static void VerifyValueType(Object *);
				void Add(Microsoft::CoreUI::Registrar::RegistrationNameMaps__Ticket);
				void CopyTo(Array *,int);
				void EnsureCapacity(int);
				void Insert(int,Microsoft::CoreUI::Registrar::RegistrationNameMaps__Ticket);
				void RemoveAt(int);
				void set_Capacity(int);
			};

			struct List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket$R
			{
				struct System__Collections__ICollection_Impl
				{
					virtual Object * get_SyncRoot(Object *);
					virtual bool get_IsSynchronized(Object *);
					virtual int get_Count(Object *);
					virtual void CopyTo(Object *,Array *,int);
				};

				struct System__Collections__IEnumerable_Impl
				{
					virtual IEnumerator * GetEnumerator(Object *);
				};

				struct System__Collections__IList_Impl
				{
					virtual Object * get_Item(Object *,int);
					virtual bool Contains(Object *,Object *);
					virtual bool get_IsFixedSize(Object *);
					virtual bool get_IsReadOnly(Object *);
					virtual int Add(Object *,Object *);
					virtual int IndexOf(Object *,Object *);
					virtual void Clear(Object *);
					virtual void Insert(Object *,int,Object *);
					virtual void Remove(Object *,Object *);
					virtual void RemoveAt(Object *,int);
					virtual void set_Item(Object *,int,Object *);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket * New();
				static List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket$R::System__Collections__ICollection_Impl const s_System__Collections__ICollection_Impl;
				static List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket$R::System__Collections__IEnumerable_Impl const s_System__Collections__IEnumerable_Impl;
				static List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket$R::System__Collections__IList_Impl const s_System__Collections__IList_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
				static void InitializeType();
			};

			struct List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket_1D$R
			{
				static Cn::TypeDefinition_4 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static void InitializeCppInstance(void *);
			};

			struct List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket__Enumerator
			{
				bool MoveNext();
				~List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket__Enumerator();
			};

			struct List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket__Enumerator$R
			{
				struct System__Collections__IEnumerator_Impl
				{
					virtual Object * get_Current(Object *);
					virtual bool MoveNext(Object *);
					virtual void Reset(Object *);
				};

				static Cn::TypeDefinition_65 const s_defType;
				static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
				static List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket__Enumerator New(List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket *);
				static List__Microsoft_CoreUI_Registrar_RegistrationNameMaps_Ticket__Enumerator$R::System__Collections__IEnumerator_Impl const s_System__Collections__IEnumerator_Impl;
				static short const * const s_rgReferenceFields;
				static void InitializeCppInstance(void *);
			};

		};

		struct ICollection$R
		{
			static Cn::TypeDefinition_64 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		};

		struct IComparer$R
		{
			static Cn::TypeDefinition_64 const s_defType;
		};

		struct IEnumerable$R
		{
			static Cn::TypeDefinition_96 const s_defType;
		};

		struct IEnumerator
		{
			Object * get_Current();
			bool MoveNext();
		};

		struct IEnumerator$R
		{
			static Cn::TypeDefinition_96 const s_defType;
			static void const * const * const s_rgLookup;
		};

		struct IList$R
		{
			static Cn::TypeDefinition_64 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		};

		struct Queue
		{
			Object * GetElement(int);
			virtual Object * Dequeue();
			virtual Object * Peek();
			virtual Object_1D * ToArray();
			virtual bool Contains(Object *);
			virtual void Clear();
			virtual void Enqueue(Object *);
			virtual void TrimToSize();
			void CopyTo(Array *,int);
			void SetCapacity(int);
		};

		struct Queue$R
		{
			struct System__Collections__ICollection_Impl
			{
				virtual Object * get_SyncRoot(Object *);
				virtual bool get_IsSynchronized(Object *);
				virtual int get_Count(Object *);
				virtual void CopyTo(Object *,Array *,int);
			};

			struct System__Collections__IEnumerable_Impl
			{
				virtual IEnumerator * GetEnumerator(Object *);
			};

			static Cn::TypeDefinition_65 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static Queue$R::System__Collections__ICollection_Impl const s_System__Collections__ICollection_Impl;
			static Queue$R::System__Collections__IEnumerable_Impl const s_System__Collections__IEnumerable_Impl;
			static short const * const s_rgReferenceFields;
			static void InitializeCppInstance(void *);
		};

		struct Queue__QueueEnumerator$R
		{
			struct System__Collections__IEnumerator_Impl
			{
				virtual Object * get_Current(Object *);
				virtual bool MoveNext(Object *);
				virtual void Reset(Object *);
			};

			static Cn::TypeDefinition_65 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static Queue__QueueEnumerator$R::System__Collections__IEnumerator_Impl const s_System__Collections__IEnumerator_Impl;
			static short const * const s_rgReferenceFields;
			static void InitializeCppInstance(void *);
		};

		namespace Specialized
		{
			struct BitVector32
			{
				static String * ToString(BitVector32);
			};

			struct BitVector32$R
			{
				static Cn::TypeDefinition_66 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct BitVector32__Boxed
			{
				virtual String * ToString();
				virtual bool Equals(Object *);
				virtual int GetHashCode();
			};

			struct BitVector32__Section
			{
				static String * ToString(BitVector32__Section);
			};

			struct BitVector32__Section$R
			{
				static Cn::TypeDefinition_66 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct BitVector32__Section__Boxed
			{
				virtual String * ToString();
				virtual bool Equals(Object *);
				virtual int GetHashCode();
			};

		};

		struct Stack
		{
			virtual void Clear();
			void CopyTo(Array *,int);
		};

		struct Stack$R
		{
			struct System__Collections__ICollection_Impl
			{
				virtual Object * get_SyncRoot(Object *);
				virtual bool get_IsSynchronized(Object *);
				virtual int get_Count(Object *);
				virtual void CopyTo(Object *,Array *,int);
			};

			struct System__Collections__IEnumerable_Impl
			{
				virtual IEnumerator * GetEnumerator(Object *);
			};

			static Cn::TypeDefinition_65 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static Stack$R::System__Collections__ICollection_Impl const s_System__Collections__ICollection_Impl;
			static Stack$R::System__Collections__IEnumerable_Impl const s_System__Collections__IEnumerable_Impl;
			static short const * const s_rgReferenceFields;
			static void InitializeCppInstance(void *);
		};

		struct Stack__StackEnumerator
		{
			bool MoveNext();
		};

		struct Stack__StackEnumerator$R
		{
			struct System__Collections__IEnumerator_Impl
			{
				virtual Object * get_Current(Object *);
				virtual bool MoveNext(Object *);
				virtual void Reset(Object *);
			};

			static Cn::TypeDefinition_65 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static Stack__StackEnumerator$R::System__Collections__IEnumerator_Impl const s_System__Collections__IEnumerator_Impl;
			static short const * const s_rgReferenceFields;
			static void InitializeCppInstance(void *);
		};

	};

	namespace ComponentModel
	{
		struct PropertyChangedEventHandler$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

	};

	class Console
	{
		static Cn::ComPtr<Cn::Engine::Lock> s_lock;
		static bool s_fShuttingDown;
		static char * s_rgbBufferConverted;
		static int s_cchBufferWritten;
		static void * s_hStdOut;
		static void FlushBuffer();
		static void HandleConsoleError();
		static wchar_t * s_rgchBufferWritten;
		static wchar_t const * const s_rgLineFeed;
	public:
		static void UninitializeType();
	};

	struct DateTime
	{
		__int64 ToFileTimeUtc();
		static DateTime get_UtcNow();
		static DateTime op_Addition(DateTime,TimeSpan);
	};

	struct DateTime$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		static Cn::TypeDefinition_66 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static DateTime$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static void InitializeCppInstance(void *);
		static void InitializeType();
		static void UninitializeType();
	};

	struct DateTime__Boxed
	{
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct Delegate
	{
		bool InternalSimpleEquals(Delegate *);
		static Delegate * Combine(Delegate *,Delegate *);
		static Delegate * Remove(Delegate *,Delegate *);
		static bool op_Equality(Delegate *,Delegate *);
		static bool op_Inequality(Delegate *,Delegate *);
		virtual Delegate_1D * GetInvocationList();
		virtual bool Equals(Object *);
		virtual ~Delegate();
	};

	struct Delegate$R
	{
		struct System__ICloneable_Impl
		{
			virtual Object * Clone(Object *);
		};

		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static Delegate$R::System__ICloneable_Impl const s_System__ICloneable_Impl;
	};

	struct Delegate_1D
	{
		Delegate * _SetElement(int,Delegate *);
		Delegate_1D * InitializeItems(int,...);
	};

	struct Delegate_1D$R
	{
		static Cn::TypeDefinition_4 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	namespace Diagnostics
	{
		struct Process$R
		{
			static Cn::TypeDefinition_66 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct Stopwatch
		{
			static __int64 s_frequency;
			static double s_tickFrequency;
			static void _ClassConstruct();
		};

		struct Stopwatch$R
		{
			static Cn::TypeDefinition_66 const s_defType;
			static void InitializeCppInstance(void *);
		};

	};

	struct DivideByZeroException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct DllNotFoundException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	class Double
	{
		static void _ApplyNumberFormat(wchar_t * const,int *,int);
	public:
		int CompareTo(double);
		static String * _ToStringFormatter(String *,double,bool);
		static bool IsNaN(double);
		static void _FixupExponent(wchar_t * const,int *);
	};

	struct Double$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		struct System__IFormattable_Impl
		{
			virtual String * ToString(Object *,String *,IFormatProvider *);
		};

		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static Double$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static Double$R::System__IFormattable_Impl const s_System__IFormattable_Impl;
		static void InitializeCppInstance(void *);
	};

	struct Double__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct EntryPointNotFoundException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	class Enum
	{
		String * _ToString_FlagsMode(Cn::TypeDefinition const *,unsigned __int64,bool);
		String * _ToString_RegularMode(Cn::TypeDefinition const *,unsigned __int64,bool);
		static String * _GetNameStringByOrdinal(Cn::TypeExtra_Enum const *,int);
	public:
		static int InternalCompare(Enum *,Object *);
		virtual String * ToString();
		virtual int GetHashCode();
	};

	struct Enum$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static Enum$R::System__IComparable_Impl const s_System__IComparable_Impl;
	};

	struct EventArgs
	{
		static void _ClassConstruct();
	};

	struct EventArgs$R
	{
		static Cn::TypeDefinition_66 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct EventHandler
	{
		void Invoke(Object *,EventArgs *);
	};

	struct EventHandler$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Exception$R
	{
		static Cn::TypeDefinition_99 const s_defType;
		static Exception * New();
		static short const * const s_rgReferenceFields;
		static void InitializeCppInstance(void *);
	};

	struct FormatException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static FormatException * New();
		static void InitializeCppInstance(void *);
	};

	struct GC
	{
		static void Collect();
	};

	namespace Globalization
	{
		struct CultureInfo
		{
			virtual Object * GetFormat(Type);
		};

		struct CultureInfo$R
		{
			struct System__IFormatProvider_Impl
			{
				virtual Object * GetFormat(Object *,Type);
			};

			static Cn::TypeDefinition_66 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static CultureInfo$R::System__IFormatProvider_Impl const s_System__IFormatProvider_Impl;
			static void InitializeCppInstance(void *);
			static void InitializeType();
		};

		struct NumberFormatInfo
		{
			virtual Object * GetFormat(Type);
		};

		struct NumberFormatInfo$R
		{
			struct System__IFormatProvider_Impl
			{
				virtual Object * GetFormat(Object *,Type);
			};

			static Cn::TypeDefinition_66 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static NumberFormatInfo$R::System__IFormatProvider_Impl const s_System__IFormatProvider_Impl;
			static void InitializeCppInstance(void *);
			static void InitializeType();
		};

		struct NumberStyles$R
		{
			static Cn::TypeDefinition_74 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static char const * const s_EnumNames;
			static unsigned int const * const s_rgEnumValues;
			static unsigned short const * const s_rgEnumNameOffsets;
			static void InitializeCppInstance(void *);
		};

	};

	struct Guid
	{
		String * ToString();
		String * ToString(String *,IFormatProvider *);
		static Guid Empty;
		static bool op_Equality(Guid,Guid);
		static int HexsToChars(Char_1D *,int,int,int);
	};

	struct Guid$R
	{
		static Cn::TypeDefinition_66 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct Guid__Boxed
	{
		virtual String * ToString();
		virtual int GetHashCode();
	};

	struct ICloneable$R
	{
		static Cn::TypeDefinition_66 const s_defType;
	};

	struct IComparable$R
	{
		static Cn::TypeDefinition_64 const s_defType;
	};

	struct IDisposable
	{
		void Dispose();
	};

	struct IDisposable$R
	{
		static Cn::TypeDefinition_96 const s_defType;
		static void const * const * const s_rgLookup;
	};

	struct IFormatProvider$R
	{
		static Cn::TypeDefinition_64 const s_defType;
	};

	struct IFormattable$R
	{
		static Cn::TypeDefinition_64 const s_defType;
		static void const * const * const s_rgLookup;
	};

	namespace IO
	{
		struct FileLoadException$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct FileNotFoundException$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct IOException$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static void InitializeCppInstance(void *);
		};

	};

	struct IndexOutOfRangeException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static IndexOutOfRangeException * New();
		static void InitializeCppInstance(void *);
	};

	struct Int16$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		struct System__IFormattable_Impl
		{
			virtual String * ToString(Object *,String *,IFormatProvider *);
		};

		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static Int16$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static Int16$R::System__IFormattable_Impl const s_System__IFormattable_Impl;
		static void InitializeCppInstance(void *);
	};

	struct Int16__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct Int32
	{
		ValueType * _Box();
		bool Equals(Object *);
		int CompareTo(Object *);
		static String * _ToStringFormatter(String *,__int64,int,bool);
	};

	struct Int32$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		struct System__IFormattable_Impl
		{
			virtual String * ToString(Object *,String *,IFormatProvider *);
		};

		static Cn::MethodDefinition const * const s_rgMethodEntries;
		static Cn::TypeDefinition_114 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static Int32$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static Int32$R::System__IFormattable_Impl const s_System__IFormattable_Impl;
		static unsigned short const * const s_rgParameterEntries;
		static void InitializeCppInstance(void *);
		static void Reflection__CompareTo__1(void *,void * *,void * *);
		static void Reflection__CompareTo__2(void *,void * *,void * *);
		static void Reflection__Equals__3(void *,void * *,void * *);
		static void Reflection__Equals__4(void *,void * *,void * *);
		static void Reflection__GetHashCode(void *,void * *,void * *);
		static void Reflection__Parse__7(void *,void * *,void * *);
		static void Reflection__Parse__8(void *,void * *,void * *);
		static void Reflection__ToString__10(void *,void * *,void * *);
		static void Reflection__ToString__11(void *,void * *,void * *);
		static void Reflection__ToString__12(void *,void * *,void * *);
		static void Reflection__ToString__9(void *,void * *,void * *);
		static void Reflection__TryParse(void *,void * *,void * *);
	};

	struct Int32_1D$R
	{
		static Cn::TypeDefinition_4 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Int32_ByRef$R
	{
		static Cn::TypeDefinition_4 const s_defType;
	};

	struct Int32__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct Int64$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		struct System__IFormattable_Impl
		{
			virtual String * ToString(Object *,String *,IFormatProvider *);
		};

		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static Int64$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static Int64$R::System__IFormattable_Impl const s_System__IFormattable_Impl;
		static void InitializeCppInstance(void *);
	};

	struct Int64__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct IntPtr
	{
		bool Equals(Object *);
		int ToInt32();
		static IntPtr Zero;
	};

	struct IntPtr$R
	{
		static Cn::TypeDefinition_98 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct IntPtr__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct InvalidCastException$R
	{
		static Cn::TypeDefinition_99 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct InvalidOperationException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static InvalidOperationException * New();
		static InvalidOperationException * New(String *);
		static InvalidOperationException * New(String *,Exception *);
		static void InitializeCppInstance(void *);
	};

	struct MemberAccessException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct MissingMemberException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct MissingMethodException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	class MulticastDelegate
	{
	protected:
		static MulticastDelegate * InternalNew(Cn::TypeDefinition const *,Object *,void *);
		virtual ~MulticastDelegate();
	public:
		MulticastDelegate * InternalNewInstance(Delegate_1D *);
		static Delegate * InternalRemove(MulticastDelegate *,MulticastDelegate *);
		static MulticastDelegate * InternalCombine(MulticastDelegate *,MulticastDelegate *);
		virtual Delegate_1D * GetInvocationList();
		virtual Object * InternalGetTarget();
		virtual bool InternalEquals(Delegate *);
	};

	struct MulticastDelegate$R
	{
		static Cn::TypeDefinition_99 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static short const * const s_rgReferenceFields;
	};

	struct NotImplementedException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct NotSupportedException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static NotSupportedException * New();
		static void InitializeCppInstance(void *);
	};

	struct NullReferenceException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static NullReferenceException * New();
		static void InitializeCppInstance(void *);
	};

	class Object
	{
		void _Heap_CheckFinalizerWorker(bool);
	protected:
		virtual void Finalize();
		virtual ~Object();
		void _ReleaseReferences(bool);
	public:
		Object * MemberwiseClone();
		static Object * InternalNew(Cn::TypeDefinition const *);
		static Object * _AsClass(Object *,Cn::TypeDefinition const *);
		static Object * _AsInterface(Object *,Cn::TypeDefinition const *);
		static Object * _CastClass(Object *,Cn::TypeDefinition const *);
		static Object * _CastInterface(Object *,Cn::TypeDefinition const *);
		static void * _Unbox(Object *,Cn::TypeDefinition const *);
		static void * _UnboxWithEnumConversions(Object *,Cn::TypeDefinition const *);
		static void _LockRange(void const *,Cn::TypeDefinition const *,int);
		static void _PreconstructClone(Cn::Engine::Heap *,Object *,Object *);
		static void _UnlockRange(Object * * const,int);
		static void _UnlockRange(void const *,Cn::TypeDefinition const *,int);
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
		void _Preconstruct(Cn::Engine::Heap *,Cn::TypeDefinition const *);
		void _Unlock();
		void _Unlock(Cn::Engine::Heap * *);
	};

	struct Object$R
	{
		static Cn::MethodDefinition const * const s_rgMethodEntries;
		static Cn::TypeDefinition_242 const s_defType;
		static unsigned short const * const s_rgParameterEntries;
		static void InitializeCppExport(void *);
		static void InitializeCppInstance(void *);
		static void Reflection__CnGetUserFlag1(void *,void * *,void * *);
		static void Reflection__CnGetUserFlag2(void *,void * *,void * *);
		static void Reflection__CnSetUserFlag1(void *,void * *,void * *);
		static void Reflection__CnSetUserFlag2(void *,void * *,void * *);
		static void Reflection__Equals__3(void *,void * *,void * *);
		static void Reflection__Equals__4(void *,void * *,void * *);
		static void Reflection__Finalize(void *,void * *,void * *);
		static void Reflection__GetHashCode(void *,void * *,void * *);
		static void Reflection__GetType(void *,void * *,void * *);
		static void Reflection__MemberwiseClone(void *,void * *,void * *);
		static void Reflection__ReferenceEquals(void *,void * *,void * *);
		static void Reflection__ToString(void *,void * *,void * *);
		static void Reflection___Construct(void *,void * *,void * *);
	};

	struct ObjectDisposedException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct Object_1D
	{
		Object * _SetElement(int,Object *);
		Object_1D * InitializeItems(int,...);
	};

	struct Object_1D$R
	{
		static Cn::TypeDefinition_4 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct OutOfMemoryException$R
	{
		static Cn::TypeDefinition_99 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct OverflowException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static OverflowException * New();
		static void InitializeCppInstance(void *);
	};

	struct Random
	{
		double GetSampleForLargeRange();
		int InternalSample();
		virtual double NextDouble();
		virtual double Sample();
		virtual int Next();
		virtual int Next(int);
		virtual int Next(int,int);
		virtual void NextBytes(Byte_1D *);
		void _Construct(int);
	};

	struct Random$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static short const * const s_rgReferenceFields;
		static void InitializeCppInstance(void *);
	};

	struct RankException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static RankException * New();
		static void InitializeCppInstance(void *);
	};

	namespace Reflection
	{
		struct AmbiguousMatchException$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct Assembly
		{
			Type GetType(String *,bool);
			void _Construct();
		};

		struct Assembly$R
		{
			static Cn::MethodDefinition const * const s_rgMethodEntries;
			static Cn::PropertyDefinition const * const s_rgPropertyEntries;
			static Cn::TypeDefinition_83 const s_defType;
			static short const * const s_rgReferenceFields;
			static unsigned short const * const s_rgParameterEntries;
			static void InitializeCppInstance(void *);
			static void InitializeType();
			static void Reflection__GetType(void *,void * *,void * *);
			static void Reflection__Load(void *,void * *,void * *);
			static void Reflection__get_FullName(void *,void * *,void * *);
		};

		struct AssemblyName
		{
			virtual String * ToString();
		};

		struct AssemblyName$R
		{
			static Cn::MethodDefinition const * const s_rgMethodEntries;
			static Cn::PropertyDefinition const * const s_rgPropertyEntries;
			static Cn::TypeDefinition_83 const s_defType;
			static short const * const s_rgReferenceFields;
			static unsigned short const * const s_rgParameterEntries;
			static void InitializeCppInstance(void *);
			static void Reflection__ToString(void *,void * *,void * *);
			static void Reflection___Construct__1(void *,void * *,void * *);
			static void Reflection___Construct__2(void *,void * *,void * *);
			static void Reflection__get_CodeBase(void *,void * *,void * *);
			static void Reflection__get_FullName(void *,void * *,void * *);
			static void Reflection__get_Name(void *,void * *,void * *);
			static void Reflection__set_CodeBase(void *,void * *,void * *);
			static void Reflection__set_Name(void *,void * *,void * *);
		};

		struct BindingFlags$R
		{
			static Cn::TypeDefinition_74 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static char const * const s_EnumNames;
			static unsigned int const * const s_rgEnumValues;
			static unsigned short const * const s_rgEnumNameOffsets;
			static void InitializeCppInstance(void *);
		};

		struct ConstructorInfo$R
		{
			static Cn::MethodDefinition const * const s_rgMethodEntries;
			static Cn::TypeDefinition_83 const s_defType;
			static unsigned short const * const s_rgParameterEntries;
			static void InitializeCppInstance(void *);
			static void Reflection__Invoke(void *,void * *,void * *);
			static void Reflection___Construct(void *,void * *,void * *);
		};

		struct ConstructorInfo_1D$R
		{
			static Cn::TypeDefinition_4 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct EventInfo
		{
			virtual String * _GetNameWorker();
			virtual bool Equals(Object *);
		};

		struct EventInfo$R
		{
			static Cn::MethodDefinition const * const s_rgMethodEntries;
			static Cn::PropertyDefinition const * const s_rgPropertyEntries;
			static Cn::TypeDefinition_83 const s_defType;
			static unsigned short const * const s_rgParameterEntries;
			static void InitializeCppInstance(void *);
			static void Reflection__Equals(void *,void * *,void * *);
			static void Reflection___Construct(void *,void * *,void * *);
			static void Reflection___GetNameWorker(void *,void * *,void * *);
			static void Reflection__get_EventHandlerType(void *,void * *,void * *);
		};

		struct EventInfo_1D$R
		{
			static Cn::TypeDefinition_4 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		class MemberInfo
		{
		protected:
			MethodInfo * _CreateAccessor(unsigned short,bool);
			ParameterInfo_1D * _BuildParameters(void const *,int,int);
		};

		struct MemberInfo$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static short const * const s_rgReferenceFields;
		};

		struct MethodBase
		{
			static Object * InternalInvoke(Cn::TypeDefinition const *,Cn::MethodDefinition const *,Object *,Object_1D *);
			virtual String * _GetNameWorker();
			virtual bool Equals(Object *);
		};

		struct MethodBase$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static short const * const s_rgReferenceFields;
		};

		struct MethodInfo$R
		{
			static Cn::MethodDefinition const * const s_rgMethodEntries;
			static Cn::PropertyDefinition const * const s_rgPropertyEntries;
			static Cn::TypeDefinition_83 const s_defType;
			static void InitializeCppInstance(void *);
			static void Reflection___Construct(void *,void * *,void * *);
			static void Reflection__get_ReturnType(void *,void * *,void * *);
		};

		struct MethodInfo_1D$R
		{
			static Cn::TypeDefinition_4 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct ParameterInfo
		{
			virtual bool Equals(Object *);
		};

		struct ParameterInfo$R
		{
			static Cn::TypeDefinition_66 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct ParameterInfo_1D$R
		{
			static Cn::TypeDefinition_4 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct PropertyInfo
		{
			MethodInfo * GetGetMethod(bool);
			MethodInfo * GetSetMethod(bool);
			virtual String * _GetNameWorker();
			virtual bool Equals(Object *);
			void SetValue(Object *,Object *,Object_1D *);
		};

		struct PropertyInfo$R
		{
			static Cn::MethodDefinition const * const s_rgMethodEntries;
			static Cn::PropertyDefinition const * const s_rgPropertyEntries;
			static Cn::TypeDefinition_83 const s_defType;
			static short const * const s_rgReferenceFields;
			static unsigned short const * const s_rgParameterEntries;
			static void InitializeCppInstance(void *);
			static void Reflection__Equals(void *,void * *,void * *);
			static void Reflection__GetGetMethod__6(void *,void * *,void * *);
			static void Reflection__GetGetMethod__7(void *,void * *,void * *);
			static void Reflection__GetIndexParameters(void *,void * *,void * *);
			static void Reflection__GetSetMethod__10(void *,void * *,void * *);
			static void Reflection__GetSetMethod__9(void *,void * *,void * *);
			static void Reflection__GetValue(void *,void * *,void * *);
			static void Reflection__SetValue(void *,void * *,void * *);
			static void Reflection___Construct(void *,void * *,void * *);
			static void Reflection___GetNameWorker(void *,void * *,void * *);
			static void Reflection__get_CanRead(void *,void * *,void * *);
			static void Reflection__get_CanWrite(void *,void * *,void * *);
			static void Reflection__get_PropertyType(void *,void * *,void * *);
		};

		struct PropertyInfo_1D$R
		{
			static Cn::TypeDefinition_4 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct TargetException$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static void InitializeCppInstance(void *);
		};

	};

	namespace Runtime
	{
		namespace InteropServices
		{
			struct COMException$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct ExternalException$R
			{
				static Cn::TypeDefinition_67 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct GCHandle
			{
				Object * get_Target();
				static GCHandle Alloc(Object *);
				static GCHandle FromIntPtr(IntPtr);
				static IntPtr InternalAlloc(Object *,GCHandleType);
				void Free();
			};

			struct GCHandle$R
			{
				static Cn::TypeDefinition_66 const s_defType;
				static void InitializeCppInstance(void *);
			};

			struct GCHandle__Boxed
			{
				virtual bool Equals(Object *);
				virtual int GetHashCode();
			};

			struct Marshal
			{
				static String * InternalNewAnsiString(IntPtr,int);
			};

		};

	};

	struct SByte$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		struct System__IFormattable_Impl
		{
			virtual String * ToString(Object *,String *,IFormatProvider *);
		};

		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static SByte$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static SByte$R::System__IFormattable_Impl const s_System__IFormattable_Impl;
		static void InitializeCppInstance(void *);
	};

	struct SByte__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct Single
	{
		static bool IsNaN(float);
	};

	struct Single$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		struct System__IFormattable_Impl
		{
			virtual String * ToString(Object *,String *,IFormatProvider *);
		};

		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static Single$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static Single$R::System__IFormattable_Impl const s_System__IFormattable_Impl;
		static void InitializeCppInstance(void *);
	};

	struct Single__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	class String
	{
		String * InternalDoCaseMapping(bool,bool);
		static String * BuildBuffer(int,int);
		static String * ConcatHelper(String * *,int);
		static int ComputeHashCode(wchar_t const *,int);
		static int InternalCompareOrdinals(wchar_t const *,int,wchar_t const *,int,bool);
		static void InternalDoCaseMapping(wchar_t const *,int,wchar_t *,bool,bool);
		static wchar_t const * InternalStrStr(wchar_t const *,unsigned __int64,wchar_t const *,unsigned __int64);
	public:
		Char_1D * ToCharArray(int,int);
		String * PadHelper(int,wchar_t,bool);
		String * Remove(int,int);
		String * Replace(String *,String *);
		String * Replace(wchar_t,wchar_t);
		String * Substring(int,int);
		String * Trim();
		String_1D * InternalSimpleSplit(wchar_t);
		bool StartsWith(String *,StringComparison);
		int CnGetInvariantIgnoreCaseHashCode();
		int CompareTo(Object *);
		int IndexOf(String *,StringComparison);
		int IndexOf(wchar_t,int,int);
		static String * Concat(Object *,Object *);
		static String * Concat(Object *,Object *,Object *);
		static String * Concat(Object *,Object *,Object *,Object *);
		static String * CreateEmpty();
		static String * Format(IFormatProvider *,String *,Object * *,int);
		static String * Format(IFormatProvider *,String *,Object *,Object *,Object *,Object *,Object *,Object *);
		static String * Format(IFormatProvider *,String *,Object *,Object *,Object *,Object *,Object *,Object *,Object *);
		static String * Format(IFormatProvider *,String *,Object_1D *);
		static String * Format(String *,Object *);
		static String * Format(String *,Object *,Object *);
		static String * Format(String *,Object *,Object *,Object *);
		static String * InternalCreateFromUnicodeBytes(Byte_1D *,int,int,bool);
		static String * _New(wchar_t const *,int,int);
		static String * _NewFromAscii(char const *,int);
		static bool Equals(String *,String *);
		static bool InternalIsTrimWhitespaceChar(wchar_t);
		static bool _StartsWith(char const *,char const *,unsigned __int64 *);
		static int Compare(String *,String *,StringComparison);
		static int InternalCompare(String *,String *,StringComparison);
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
		wchar_t get_Item(int);
	};

	struct String$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		static Cn::FieldDefinition const * const s_rgFieldEntries;
		static Cn::MethodDefinition const * const s_rgMethodEntries;
		static Cn::PropertyDefinition const * const s_rgPropertyEntries;
		static Cn::TypeDefinition_114 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static String$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static unsigned short const * const s_rgParameterEntries;
		static void InitializeCppInstance(void *);
		static void Reflection__CnGetInvariantIgnoreCaseHashCode(void *,void * *,void * *);
		static void Reflection__CompareTo__14(void *,void * *,void * *);
		static void Reflection__CompareTo__15(void *,void * *,void * *);
		static void Reflection__Compare__11(void *,void * *,void * *);
		static void Reflection__Compare__12(void *,void * *,void * *);
		static void Reflection__Compare__13(void *,void * *,void * *);
		static void Reflection__Concat__18(void *,void * *,void * *);
		static void Reflection__Concat__19(void *,void * *,void * *);
		static void Reflection__Concat__20(void *,void * *,void * *);
		static void Reflection__Concat__21(void *,void * *,void * *);
		static void Reflection__Concat__22(void *,void * *,void * *);
		static void Reflection__Concat__23(void *,void * *,void * *);
		static void Reflection__Concat__24(void *,void * *,void * *);
		static void Reflection__Contains(void *,void * *,void * *);
		static void Reflection__EndsWith(void *,void * *,void * *);
		static void Reflection__Equals__27(void *,void * *,void * *);
		static void Reflection__Equals__28(void *,void * *,void * *);
		static void Reflection__Equals__29(void *,void * *,void * *);
		static void Reflection__Equals__30(void *,void * *,void * *);
		static void Reflection__Format__31(void *,void * *,void * *);
		static void Reflection__Format__32(void *,void * *,void * *);
		static void Reflection__Format__33(void *,void * *,void * *);
		static void Reflection__Format__34(void *,void * *,void * *);
		static void Reflection__Format__35(void *,void * *,void * *);
		static void Reflection__Format__36(void *,void * *,void * *);
		static void Reflection__Format__37(void *,void * *,void * *);
		static void Reflection__Format__38(void *,void * *,void * *);
		static void Reflection__Format__39(void *,void * *,void * *);
		static void Reflection__Format__40(void *,void * *,void * *);
		static void Reflection__Format__41(void *,void * *,void * *);
		static void Reflection__Format__42(void *,void * *,void * *);
		static void Reflection__Format__43(void *,void * *,void * *);
		static void Reflection__Format__44(void *,void * *,void * *);
		static void Reflection__Format__45(void *,void * *,void * *);
		static void Reflection__Format__46(void *,void * *,void * *);
		static void Reflection__Format__47(void *,void * *,void * *);
		static void Reflection__Format__48(void *,void * *,void * *);
		static void Reflection__Format__49(void *,void * *,void * *);
		static void Reflection__Format__50(void *,void * *,void * *);
		static void Reflection__GetEnumerator(void *,void * *,void * *);
		static void Reflection__GetHashCode(void *,void * *,void * *);
		static void Reflection__IndexOf__5(void *,void * *,void * *);
		static void Reflection__IndexOf__6(void *,void * *,void * *);
		static void Reflection__IndexOf__7(void *,void * *,void * *);
		static void Reflection__IndexOf__8(void *,void * *,void * *);
		static void Reflection__IsNullOrEmpty(void *,void * *,void * *);
		static void Reflection__LastIndexOf(void *,void * *,void * *);
		static void Reflection__PadLeft__66(void *,void * *,void * *);
		static void Reflection__PadLeft__67(void *,void * *,void * *);
		static void Reflection__PadRight__68(void *,void * *,void * *);
		static void Reflection__PadRight__69(void *,void * *,void * *);
		static void Reflection__Remove__55(void *,void * *,void * *);
		static void Reflection__Remove__56(void *,void * *,void * *);
		static void Reflection__Replace__57(void *,void * *,void * *);
		static void Reflection__Replace__58(void *,void * *,void * *);
		static void Reflection__Split(void *,void * *,void * *);
		static void Reflection__StartsWith(void *,void * *,void * *);
		static void Reflection__Substring__53(void *,void * *,void * *);
		static void Reflection__Substring__54(void *,void * *,void * *);
		static void Reflection__ToCharArray__59(void *,void * *,void * *);
		static void Reflection__ToCharArray__60(void *,void * *,void * *);
		static void Reflection__ToLower(void *,void * *,void * *);
		static void Reflection__ToLowerInvariant(void *,void * *,void * *);
		static void Reflection__ToString(void *,void * *,void * *);
		static void Reflection__ToUpper(void *,void * *,void * *);
		static void Reflection__ToUpperInvariant(void *,void * *,void * *);
		static void Reflection__Trim(void *,void * *,void * *);
		static void Reflection__get_Item(void *,void * *,void * *);
		static void Reflection__get_Length(void *,void * *,void * *);
		static void Reflection__op_Equality(void *,void * *,void * *);
		static void Reflection__op_Inequality(void *,void * *,void * *);
	};

	struct StringComparison$R
	{
		static Cn::TypeDefinition_74 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static char const * const s_EnumNames;
		static unsigned short const * const s_rgEnumNameOffsets;
		static void InitializeCppInstance(void *);
	};

	struct String_1D
	{
		String * _SetElement(int,String *);
	};

	struct String_1D$R
	{
		static Cn::TypeDefinition_4 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct String__StringEnumerator
	{
		~String__StringEnumerator();
	};

	struct String__StringEnumerator$R
	{
		static Cn::MethodDefinition const * const s_rgMethodEntries;
		static Cn::PropertyDefinition const * const s_rgPropertyEntries;
		static Cn::TypeDefinition_83 const s_defType;
		static short const * const s_rgReferenceFields;
		static unsigned short const * const s_rgParameterEntries;
		static void InitializeCppInstance(void *);
		static void Reflection__MoveNext(void *,void * *,void * *);
		static void Reflection___Construct__1(void *,void * *,void * *);
		static void Reflection___Construct__4(void *,void * *,void * *);
		static void Reflection__get_Current(void *,void * *,void * *);
	};

	struct SystemException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	namespace Text
	{
		struct Encoding$R
		{
			static Cn::TypeDefinition_66 const s_defType;
			static void UninitializeType();
		};

		struct StringBuilder
		{
			StringBuilder * Append(String *);
			virtual String * ToString();
			void GetNewString(int);
			void InternalAppend(wchar_t const *,int);
		};

		struct StringBuilder$R
		{
			static Cn::TypeDefinition_99 const s_defType;
			static short const * const s_rgReferenceFields;
			static void InitializeCppInstance(void *);
		};

		struct UnicodeEncoding
		{
			virtual String * GetString(Byte_1D *,int,int);
			virtual int GetByteCount(String *);
			virtual void GetBytes(String *,int,int,Byte_1D *,int);
		};

		struct UnicodeEncoding$R
		{
			static Cn::TypeDefinition_66 const s_defType;
			static void InitializeCppInstance(void *);
		};

	};

	namespace Threading
	{
		struct ParameterizedThreadStart$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct Thread
		{
			virtual void Finalize();
		};

		struct Thread$R
		{
			static Cn::TypeDefinition_66 const s_defType;
			static void InitializeCppInstance(void *);
		};

		struct ThreadStart$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
			static void InitializeCppInstance(void *);
		};

		struct ThreadStateException$R
		{
			static Cn::TypeDefinition_67 const s_defType;
			static void InitializeCppInstance(void *);
		};

	};

	struct TimeSpan
	{
		static TimeSpan Zero;
	};

	struct TimeSpan$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		static Cn::TypeDefinition_66 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static TimeSpan$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static void InitializeCppInstance(void *);
		static void InitializeType();
	};

	struct TimeSpan__Boxed
	{
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct Type$R
	{
		static Cn::MethodDefinition const * const s_rgMethodEntries;
		static Cn::PropertyDefinition const * const s_rgPropertyEntries;
		static Cn::TypeDefinition_114 const s_defType;
		static unsigned short const * const s_rgParameterEntries;
	};

	struct TypeLoadException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct Type_1D$R
	{
		static Cn::TypeDefinition_4 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct Type__Statics$R
	{
		static void InitializeType();
	};

	struct UInt16$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		struct System__IFormattable_Impl
		{
			virtual String * ToString(Object *,String *,IFormatProvider *);
		};

		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static UInt16$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static UInt16$R::System__IFormattable_Impl const s_System__IFormattable_Impl;
		static void InitializeCppInstance(void *);
	};

	struct UInt16__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct UInt32$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		struct System__IFormattable_Impl
		{
			virtual String * ToString(Object *,String *,IFormatProvider *);
		};

		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static UInt32$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static UInt32$R::System__IFormattable_Impl const s_System__IFormattable_Impl;
		static void InitializeCppInstance(void *);
	};

	struct UInt32_1D
	{
		UInt32_1D * InitializeItems(int,...);
	};

	struct UInt32_1D$R
	{
		static Cn::TypeDefinition_4 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static void InitializeCppInstance(void *);
	};

	struct UInt32__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct UInt64$R
	{
		struct System__IComparable_Impl
		{
			virtual int CompareTo(Object *,Object *);
		};

		struct System__IFormattable_Impl
		{
			virtual String * ToString(Object *,String *,IFormatProvider *);
		};

		static Cn::TypeDefinition_98 const s_defType;
		static Cn::TypeInterfaceEntry const * const s_rgInterfaceEntries;
		static UInt64$R::System__IComparable_Impl const s_System__IComparable_Impl;
		static UInt64$R::System__IFormattable_Impl const s_System__IFormattable_Impl;
		static void InitializeCppInstance(void *);
	};

	struct UInt64__Boxed
	{
		virtual String * ToString();
		virtual bool Equals(Object *);
		virtual int GetHashCode();
	};

	struct UIntPtr
	{
		static UIntPtr Zero;
		unsigned int ToUInt32();
	};

	struct UnauthorizedAccessException$R
	{
		static Cn::TypeDefinition_67 const s_defType;
		static void InitializeCppInstance(void *);
	};

	struct ValueType
	{
		static ValueType * InternalNew(Cn::TypeDefinition const *);
		static ValueType * _New(Cn::TypeDefinition const *,void const *);
		static void _CopyInstance(void const *,void *,Cn::TypeDefinition const *,int);
		virtual bool Equals(Object *);
	};

	struct ValueType$R
	{
		static Cn::TypeDefinition_98 const s_defType;
	};

	struct Void$R
	{
		static Cn::TypeDefinition_98 const s_defType;
	};

};

struct TripartiteArray<Microsoft::CoreUI::Identity::IdentityEntry,8,7,6>
{
	Microsoft::CoreUI::Identity::IdentityEntry * GetItemAt(unsigned int,bool);
	void EnumerateItems(void *,void (*)(void *,unsigned int,Microsoft::CoreUI::Identity::IdentityEntry *));
};

struct TripartiteArray<Microsoft::CoreUI::Identity::IdentityGroupEntry,6,6,6>
{
	Microsoft::CoreUI::Identity::IdentityGroupEntry * GetItemAt(unsigned int,bool);
	void EnumerateItems(void *,void (*)(void *,unsigned int,Microsoft::CoreUI::Identity::IdentityGroupEntry *));
	~TripartiteArray<Microsoft::CoreUI::Identity::IdentityGroupEntry,6,6,6>();
};

namespace Windows
{
	namespace Internal
	{
		struct GitPtrSupportsAgile<Foundation::IAsyncActionCompletedHandler>
		{
			long CopyLocal(_GUID const &,void * *);
			long Initialize<Foundation::IAsyncActionCompletedHandler>(Foundation::IAsyncActionCompletedHandler *);
		};

		_RTL_RUN_ONCE s_bIsEnvironmentCheckDone;
	};

	namespace System
	{
		class DispatcherQueue
		{
			long DispatcherPriorityToMsgPriority(DispatcherQueuePriority,MsgPriority *);
			long RunLoop();
			long TryEnqueueWorker(DispatcherQueuePriority,IDispatcherQueueHandler *,unsigned char *);
			static long DeferInvokeCallback(void *);
			static long QueueDrainedCallback(void *);
			static long ShutdownStartingCallback(void *);
			virtual ~DispatcherQueue();
			void CompleteShutdown();
		public:
			DispatcherQueue();
			static TrustLevel InternalGetTrustLevel();
			static bool GetDispatcherQueueForThread(DispatcherQueue * *);
			static long GetOrCreateForCurrentThread(IDispatcherQueue * *);
			static wchar_t const * InternalGetRuntimeClassName();
			virtual long CreateTimer(IDispatcherQueueTimer * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual long RuntimeClassInitialize(bool,bool);
			virtual long TryEnqueue(IDispatcherQueueHandler *,unsigned char *);
			virtual long TryEnqueueWithPriority(DispatcherQueuePriority,IDispatcherQueueHandler *,unsigned char *);
			virtual long add_ShutdownCompleted(Foundation::ITypedEventHandler<DispatcherQueue *,IInspectable *> *,EventRegistrationToken *);
			virtual long add_ShutdownStarting(Foundation::ITypedEventHandler<DispatcherQueue *,DispatcherQueueShutdownStartingEventArgs *> *,EventRegistrationToken *);
			virtual long remove_ShutdownCompleted(EventRegistrationToken);
			virtual long remove_ShutdownStarting(EventRegistrationToken);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		class DispatcherQueueAsyncHelper
		{
			static long s_uid;
			virtual long GetResults();
			virtual long OnStart();
			virtual long get_Completed(Foundation::IAsyncActionCompletedHandler * *);
			virtual long put_Completed(Foundation::IAsyncActionCompletedHandler *);
			virtual void OnCancel();
			virtual void OnClose();
		public:
			DispatcherQueueAsyncHelper();
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual long RuntimeClassInitialize(bool);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			void FinishAndFire(long);
		};

		class DispatcherQueueController
		{
			static unsigned long DispatcherQueueThreadProc(void *);
			void ShutdownQueueCompleted(long);
		public:
			DispatcherQueueController();
			static TrustLevel InternalGetTrustLevel();
			static long CreateOnNewThread(DISPATCHERQUEUE_THREAD_APARTMENTTYPE,IDispatcherQueueController * *);
			static wchar_t const * InternalGetRuntimeClassName();
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual long RuntimeClassInitialize(bool,bool);
			virtual long ShutdownQueueAsync(Foundation::IAsyncAction * *);
			virtual long get_DispatcherQueue(IDispatcherQueue * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct DispatcherQueueControllerStatic
		{
			virtual long CreateOnDedicatedThread(IDispatcherQueueController * *);
		};

		struct DispatcherQueueStatic
		{
			virtual long GetForCurrentThread(IDispatcherQueue * *);
		};

		class DispatcherQueueTimer
		{
			Foundation::TimeSpan GetInterval();
			bool GetIsRepeating();
			static long TimerCallback(void *);
		public:
			DispatcherQueueTimer();
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual long RuntimeClassInitialize(IMessageSession *);
			virtual long Start();
			virtual long Stop();
			virtual long add_Tick(Foundation::ITypedEventHandler<DispatcherQueueTimer *,IInspectable *> *,EventRegistrationToken *);
			virtual long get_Interval(Foundation::TimeSpan *);
			virtual long get_IsRepeating(unsigned char *);
			virtual long get_IsRunning(unsigned char *);
			virtual long put_Interval(Foundation::TimeSpan);
			virtual long put_IsRepeating(unsigned char);
			virtual long remove_Tick(EventRegistrationToken);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ShutdownStartingEventArgsImpl
		{
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual long RuntimeClassInitialize(DispatcherQueue *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		Microsoft::WRL::Details::CreatorMap const __object_DispatcherQueue;
		Microsoft::WRL::Details::CreatorMap const __object_DispatcherQueueController;
		Microsoft::WRL::Details::FactoryCache __objectFactory__DispatcherQueue;
		Microsoft::WRL::Details::FactoryCache __objectFactory__DispatcherQueueController;
		wchar_t const * const DispatcherQueueAsyncHelperName;
	};

};

struct exception
{
	exception(exception const &);
};

namespace std
{
	nothrow_t const std::nothrow;
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
		unsigned __int64 ResultStringSize(wchar_t const *);
		unsigned char (* g_pfnRtlDllShutdownInProgress)();
		unsigned char * WriteResultString<char const *>(unsigned char *,unsigned char *,char const *,char const * *);
		unsigned char * WriteResultString<wchar_t const *>(unsigned char *,unsigned char *,wchar_t const *,wchar_t const * *);
		unsigned char RtlDllShutdownInProgress();
		unsigned long GetLastErrorFail(void *,unsigned int,char const *,char const *,char const *,void *);
		unsigned long ReportFailure_GetLastError(void *,unsigned int,char const *,char const *,char const *,void *,FailureType);
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
		void LogFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,wchar_t const *,bool,wchar_t *,unsigned __int64,char *,unsigned __int64,FailureInfo *);
		void ReleaseMutex(void *);
		void ReportFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,wchar_t const *,details::ReportFailureOptions);
		void ReportFailure_Hr(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long);
		void Rethrow();
		void ThrowResultExceptionInternal(FailureInfo const &);
		wchar_t * LogStringPrintf(wchar_t *,wchar_t const *,wchar_t const *,...);
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
			long CreateFromValueInternal(wchar_t const *,bool,unsigned __int64);
			static long GetValueFromSemaphore(void *,long *);
			static long TryGetValueInternal(wchar_t const *,bool,unsigned __int64 *,bool *);
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
	long GetFailureLogString(wchar_t *,unsigned __int64,wil::FailureInfo const &);
};

CoreUIHost g_cnHost;
HINSTANCE__ * g_wil_details_ntdllModuleHandle;
HINSTANCE__ * wil_details_GetNtDllModuleHandle();
Microsoft::CoreUI::Messaging::AnonymousStream g_AnonymousStream;
System::String * AllocateStringOrNull(wchar_t const *);
System::String * CnRuntime__GetAscii(int);
System::String * CuiSystem__GetAscii(int);
_SVCHOST_GLOBAL_DATA * g_ServiceHostGlobalData;
bool g_runningAsService;
char const * const * const CnRuntime_Ascii_Literal;
char const * const * const CuiSystem_Ascii_Literal;
int InlineIsEqualGUID(_GUID const &,_GUID const &);
int const * const g_rgData_CnRuntime_0;
int const * const g_rgData_CnRuntime_1;
int const * const g_rgData_CuiSystem_1;
int s_CnRuntime_strings_index;
int s_CuiSystem_strings_index;
long CoreUIRunRegistrarServer(void *,void *,Microsoft::CoreUI::Registrar::ServiceRunMode,_GUID const &);
long CoreUISessionCreate(bool,Microsoft::CoreUI::CreateFlags$C::Values,Microsoft::CoreUI::IExportMessageSession$X__ExportAdapter * *);
long CreateWindowManagerRPCBinding(void * *);
long StringCchCopyA(char *,unsigned __int64,char const *);
long StringCchCopyW(wchar_t *,unsigned __int64,wchar_t const *);
long StringCchLengthW(wchar_t const *,unsigned __int64,unsigned __int64 *);
long StringCchPrintfW(wchar_t *,unsigned __int64,wchar_t const *,...);
long ULongLongMult(unsigned __int64,unsigned __int64,unsigned __int64 *);
long ValidateWindowWorker(unsigned int,unsigned long *);
unsigned __int64 PointerAlignOrRip(unsigned __int64);
unsigned char const * const g_parameters_YN_D8UjnmOPj6YPD_lLbjjI6$UU;
unsigned char const * const g_parameters_xoyG4x0VC_Rm_2IsfE2yl0M7q8s_IRegistrar;
void * operator new(unsigned __int64);
void * operator new(unsigned __int64,std::nothrow_t const &);
void * operator new[](unsigned __int64,std::nothrow_t const &);
void BlockCloseHandle(void *);
void InitializeGlobals__CoreMessaging(bool);
void Microsoft__CoreUI__CoalescerHandler$CallbackThunk(System::Delegate *,__int64);
void Microsoft__CoreUI__ConversationItemEnumProc$CallbackThunk(System::Delegate *,unsigned int,unsigned int,void *);
void Microsoft__CoreUI__DispatchGroupBatchEnableHandler$CallbackThunk(System::Delegate *,bool &);
void Microsoft__CoreUI__DispatchGroupHandler$CallbackThunk(System::Delegate *);
void Microsoft__CoreUI__Dispatch__DispatchCallback$CallbackThunk(System::Delegate *,bool,Microsoft::CoreUI::Dispatch::FILETIME &);
void Microsoft__CoreUI__Dispatch__DispatchWatchdogCallback$CallbackThunk(System::Delegate *,unsigned int);
void Microsoft__CoreUI__Dispatch__TimeoutHandler$CallbackThunk(System::Delegate *);
void Microsoft__CoreUI__Dispatch__WaitCallback$CallbackThunk(System::Delegate *,Microsoft::CoreUI::Dispatch::WaitStatus,Microsoft::CoreUI::Support::Win32Handle);
void Microsoft__CoreUI__ExportEndpointHandler$CallbackThunk(System::Delegate *,void *,int);
void OutOfMemoryHandler(unsigned __int64);
void System__Action$CallbackThunk(System::Delegate *);
void UninitializeGlobals__CnRuntime(bool);
void UninitializeGlobals__CoreMessaging(bool);
void UninitializeGlobals__CuiSystem(bool);
void __ArrayUnwind(void *,unsigned __int64,int,void (*)(void *));
void operator delete(void *);
wchar_t const * const InterfaceName_Windows_Foundation_IAsyncAction;
wchar_t const * const RuntimeClass_Windows_Foundation_Deferral;
wchar_t const * const RuntimeClass_Windows_Foundation_Diagnostics_AsyncCausalityTracer;
wchar_t const * const RuntimeClass_Windows_System_DispatcherQueue;
wchar_t const * const RuntimeClass_Windows_System_DispatcherQueueController;
wchar_t const * const RuntimeClass_Windows_System_DispatcherQueueShutdownStartingEventArgs;
wchar_t const * const RuntimeClass_Windows_System_DispatcherQueueTimer;
