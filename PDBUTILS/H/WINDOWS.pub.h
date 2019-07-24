struct AgileGitPtr
{
	long CopyLocal(_GUID const &,void * *);
};

class CMarshaledInterface
{
	struct CMarshalStream
	{
		long RuntimeClassInitialize(_GUID const &,IUnknown *,MARSHAL_KIND);
		virtual ~CMarshalStream();
	};

	long _Unmarshal(_GUID const &,void * *,bool);
};

struct CThreadRefTaker
{
	virtual ~CThreadRefTaker();
};

namespace Common
{
	struct AutoHandleHKEY
	{
		~AutoHandleHKEY();
	};

	class DirectoryTreeWalker
	{
		bool IsDirAndShouldBeWalked(_WIN32_FIND_DATAW const &);
		long AppendNameToDirPath(unsigned short const *);
		long GetFirstFindHandle(void * *,_WIN32_FIND_DATAW * *);
		long InitializePath(unsigned short const *);
		long Visit(unsigned __int64,unsigned short *,_WIN32_FIND_DATAW const *,long *);
		static long DefaultFindCloseCallback(void *,void *);
		static long DefaultFindFirstCallback(void *,unsigned short *,void * *,_WIN32_FIND_DATAW *);
		static long DefaultFindNextCallback(void *,void *,_WIN32_FIND_DATAW *);
		static long IsRootValidToWalk(unsigned short const *,unsigned __int64 *,bool *,bool *,bool *);
	public:
		long Walk(unsigned short const *,unsigned int);
	};

	class StaticLock
	{
		static StaticLock * head;
	public:
		static void StaticUninitialize();
		void EnsureInitialized();
	};

	_RTL_CRITICAL_SECTION mainLock;
	_RTL_CRITICAL_SECTION_DEBUG mainLock_DEBUG;
	bool IsDirectoryReparsePointOpaque(_WIN32_FIND_DATAW const &);
	long FileExists(unsigned short const *,bool *);
	long WalkDirectoryTree(unsigned short const *,unsigned int,long (*)(void *,unsigned short const *,_WIN32_FIND_DATAW const *),void *,long (*)(void *,unsigned short *,void * *,_WIN32_FIND_DATAW *),long (*)(void *,void *,_WIN32_FIND_DATAW *),long (*)(void *,void *));
	void AutoHandleCloseHKEY<HKEY__ *>(HKEY__ *);
};

struct ConstrainedImpersonateLoggedOnUser
{
	ConstrainedImpersonateLoggedOnUser(Windows::System::IUser *);
	long Impersonate();
	~ConstrainedImpersonateLoggedOnUser();
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

		struct ActivationFactory<Implements<FtmBase,Windows::Management::Core::IApplicationDataManagerStatics>,Windows::Management::Core::Internal::IApplicationDataManagerStaticsInternal,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::Storage::IApplicationDataStatics>,Windows::Storage::IApplicationDataStatics2,Details::Nil,0>
		{
			ActivationFactory<Implements<FtmBase,Windows::Storage::IApplicationDataStatics>,Windows::Storage::IApplicationDataStatics2,Details::Nil,0>();
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct AgileActivationFactory<Windows::Management::Core::IApplicationDataManagerStatics,Windows::Management::Core::Internal::IApplicationDataManagerStaticsInternal,Details::Nil,0>
		{
			AgileActivationFactory<Windows::Management::Core::IApplicationDataManagerStatics,Windows::Management::Core::Internal::IApplicationDataManagerStaticsInternal,Details::Nil,0>();
		};

		class ComPtr<CMarshaledInterface::CMarshalStream>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			void Attach(CMarshaledInterface::CMarshalStream *);
		};

		struct ComPtr<Details::EventTargetArray>
		{
			ComPtr<Details::EventTargetArray> & operator=(ComPtr<Details::EventTargetArray> const &);
			ComPtr<Details::EventTargetArray> & operator=(Details::EventTargetArray *);
			void Attach(Details::EventTargetArray *);
		};

		class ComPtr<IActivationFactory>
		{
		protected:
			unsigned long InternalRelease();
		public:
			long As<Windows::Internal::Storage::IKnownFoldersUserModelStaticsPriv>(Details::ComPtrRef<ComPtr<Windows::Internal::Storage::IKnownFoldersUserModelStaticsPriv> >);
			long As<Windows::Storage::IKnownFoldersStaticsPriv>(Details::ComPtrRef<ComPtr<Windows::Storage::IKnownFoldersStaticsPriv> >);
		};

		class ComPtr<IAgileReference>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IAsyncInfo>
		{
		protected:
			void InternalAddRef();
		public:
			long As<Windows::Foundation::IAsyncAction>(Details::ComPtrRef<ComPtr<Windows::Foundation::IAsyncAction> >);
			long As<Windows::Foundation::IAsyncOperation<Windows::Storage::ApplicationData *> >(Details::ComPtrRef<ComPtr<Windows::Foundation::IAsyncOperation<Windows::Storage::ApplicationData *> > >);
		};

		class ComPtr<IMarshal>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IRestrictedErrorInfo>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IRpcOptions>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IShellItem>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IStream>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IThreadRefWithEvent>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IUnknown>
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<IUnknown> & operator=(IUnknown *);
		};

		class ComPtr<Windows::ApplicationModel::Core::ICoreApplicationPrivate>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> >
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

		class ComPtr<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> >
		{
		protected:
			void InternalAddRef();
		};

		class ComPtr<Windows::Foundation::Collections::IMapView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> >
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		};

		class ComPtr<Windows::Foundation::Collections::IPropertySet>
		{
		protected:
			unsigned long InternalRelease();
		public:
			long As<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *> >(Details::ComPtrRef<ComPtr<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *> > >);
		};

		class ComPtr<Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > >
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > > & operator=(ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > > const &);
			void Attach(Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > *);
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::Chunk>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > >
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > > & operator=(ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > > const &);
			void Attach(Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > > *);
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::Chunk>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::IAsyncAction>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::IAsyncActionCompletedHandler>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			ComPtr<Windows::Foundation::IAsyncActionCompletedHandler> & operator=(Windows::Foundation::IAsyncActionCompletedHandler *);
		};

		class ComPtr<Windows::Foundation::IAsyncOperation<Windows::Storage::ApplicationData *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<Windows::Storage::ApplicationData *> >
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

		class ComPtr<Windows::Foundation::ITypedEventHandler<Windows::Storage::ApplicationData *,IInspectable *> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Internal::ComTaskPool::CRemoteReleaseStub>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Internal::ComTaskPool::CRemoteTask>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Internal::ComTaskPool::CThread>
		{
		protected:
			unsigned long InternalRelease();
		public:
			void Attach(Windows::Internal::ComTaskPool::CThread *);
		};

		class ComPtr<Windows::Internal::IAsyncFireCompletion>
		{
		protected:
			void InternalAddRef();
		};

		class ComPtr<Windows::Internal::IComPoolTask>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Internal::INilDelegate>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Internal::Storage::IKnownFoldersUserModelStaticsPriv>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Management::Deployment::Internal::IPackageManagerStateCreationInternal>
		{
		protected:
			unsigned long InternalRelease();
		};

		struct ComPtr<Windows::Storage::ApplicationDataCompositeValueServer>
		{
			ComPtr<Windows::Storage::ApplicationDataCompositeValueServer> & operator=(Windows::Storage::ApplicationDataCompositeValueServer *);
			void Attach(Windows::Storage::ApplicationDataCompositeValueServer *);
		};

		struct ComPtr<Windows::Storage::ApplicationDataContainerServer>
		{
			long As<Windows::Storage::IApplicationDataContainer>(Details::ComPtrRef<ComPtr<Windows::Storage::IApplicationDataContainer> >);
			~ComPtr<Windows::Storage::ApplicationDataContainerServer>();
		};

		struct ComPtr<Windows::Storage::IApplicationDataContainer>
		{
			~ComPtr<Windows::Storage::IApplicationDataContainer>();
		};

		class ComPtr<Windows::Storage::IApplicationDataStatics2>
		{
		protected:
			void InternalAddRef();
		};

		class ComPtr<Windows::Storage::IKnownFoldersStaticsPriv>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Storage::ISetVersionDeferral>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Storage::IStorageItem>
		{
		protected:
			unsigned long InternalRelease();
		};

		struct ComPtr<Windows::Storage::StateABIImplementation::ClearOperation>
		{
			long As<Windows::Foundation::IAsyncAction>(Details::ComPtrRef<ComPtr<Windows::Foundation::IAsyncAction> >);
			void Attach(Windows::Storage::StateABIImplementation::ClearOperation *);
		};

		class ComPtr<Windows::Storage::StateABIImplementation::GetForUserOperation>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		};

		class ComPtr<Windows::Storage::StateABIImplementation::SetVersionOperation>
		{
		protected:
			unsigned long InternalRelease();
		};

		struct ComPtr<Windows::System::IUser>
		{
			ComPtr<Windows::System::IUser> & operator=(Windows::System::IUser *);
		};

		class ComPtr<Windows::System::Internal::ISignInStateManager>
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

			class ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,FtmBase>
			{
			protected:
				long CanCastToHelper<0>(_GUID const &,void * *,bool *);
			};

			class ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,Windows::Storage::Private::IApplicationDataCompositeValueInternal,FtmBase>
			{
			protected:
				long CanCastToHelper<0>(_GUID const &,void * *,bool *);
			};

			class ImplementsHelper<RuntimeClassFlags<3>,1,CloakedIid<Windows::Internal::IAsyncDeferral>,CloakedIid<Windows::Internal::IComPoolTask>,CloakedIid<Windows::Internal::IAsyncFireCompletion> >
			{
			protected:
				long CanCastTo(_GUID const &,void * *,bool *);
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
				static long AsIID<ActivationFactory<Implements<FtmBase,Windows::Management::Core::IApplicationDataManagerStatics>,Windows::Management::Core::Internal::IApplicationDataManagerStaticsInternal,Nil,0> >(ActivationFactory<Implements<FtmBase,Windows::Management::Core::IApplicationDataManagerStatics>,Windows::Management::Core::Internal::IApplicationDataManagerStaticsInternal,Nil,0> *,_GUID const &,void * *);
				static long AsIID<ActivationFactory<Nil,Nil,Nil,0> >(ActivationFactory<Nil,Nil,Nil,0> *,_GUID const &,void * *);
			};

			class RuntimeClassBaseT<1>
			{
			protected:
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,Windows::Storage::Private::IApplicationDataCompositeValueInternal,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,Windows::Storage::Private::IApplicationDataCompositeValueInternal,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapChangedEventArgs<HSTRING__ *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapChangedEventArgs<HSTRING__ *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::IApplicationData,Windows::Storage::IApplicationData2,Windows::Storage::IApplicationData3,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::IApplicationData,Windows::Storage::IApplicationData2,Windows::Storage::IApplicationData3,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::IApplicationDataContainer,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::IApplicationDataContainer,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::ISetVersionDeferral,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::ISetVersionDeferral,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::ISetVersionRequest,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::ISetVersionRequest,FtmBase> *,_GUID const &,void * *);
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,FtmBase>();
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

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> >();
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

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,Windows::Storage::Private::IApplicationDataCompositeValueInternal,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,Windows::Storage::Private::IApplicationDataCompositeValueInternal,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapChangedEventArgs<HSTRING__ *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapChangedEventArgs<HSTRING__ *> >();
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

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> >();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::IApplicationData,Windows::Storage::IApplicationData2,Windows::Storage::IApplicationData3,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::IApplicationData,Windows::Storage::IApplicationData2,Windows::Storage::IApplicationData3,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::IApplicationDataContainer,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::IApplicationDataContainer,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::ISetVersionDeferral,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::ISetVersionDeferral,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::ISetVersionRequest,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Storage::ISetVersionRequest,FtmBase>();
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

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,Windows::Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *>,FtmBase>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,Windows::Foundation::ITypedEventHandler<Windows::Storage::ApplicationData *,IInspectable *>,FtmBase>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,Windows::Internal::IComPoolTask>
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

			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::ChunkView> Make<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::ChunkView,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &>(Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &);
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::ChunkView> Make<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::ChunkView,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &>(Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &);
			ComPtr<Windows::Storage::SetVersionRequest> Make<Windows::Storage::SetVersionRequest,unsigned int &,unsigned int &>(unsigned int &,unsigned int &);
			Details::WeakReferenceImpl * CreateWeakReference(IUnknown *);
			bool TerminateMap(Details::ModuleBase *,unsigned short const *,bool);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Storage::ApplicationDataCompositeValueServer,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Management::Core::ApplicationDataManagerFactoryServer>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Storage::ApplicationDataFactoryServer>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long GetActivationFactory<1>(Details::ModuleBase *,unsigned short const *,HSTRING__ *,IActivationFactory * *);
			long GetCacheEntry(Details::ModuleBase *,unsigned int *,_GUID const &,Details::CreatorMap const *,IUnknown * *);
			long GetClassObject<1>(Details::ModuleBase *,unsigned short const *,_GUID const &,_GUID const &,void * *);
			long MakeAndInitialize<EventTargetArray,EventTargetArray,unsigned __int64 &>(Details::EventTargetArray * *,unsigned __int64 &);
			long MakeAndInitialize<Windows::Internal::ComTaskPool::CRemoteTask,Windows::Internal::ComTaskPool::CRemoteTask,Windows::Internal::IComPoolTask * &>(Windows::Internal::ComTaskPool::CRemoteTask * *,Windows::Internal::IComPoolTask * &);
		};

		struct ErrorPropagationPolicyTraits<-1>
		{
			static long FireCompletionErrorPropagationPolicyFilter(long,IUnknown *,void *);
			static long FireProgressErrorPropagationPolicyFilter(long,IUnknown *,void *);
		};

		class EventSource<Windows::Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *>,InvokeModeOptions<-2> >
		{
			long AddInternal(Windows::Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *> *,void *,EventRegistrationToken *);
		public:
			EventSource<Windows::Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *>,InvokeModeOptions<-2> >();
			long InvokeAll<Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> *,Windows::Foundation::Collections::Internal::MapChangedEventArgs<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > *>(Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> *,Windows::Foundation::Collections::Internal::MapChangedEventArgs<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > *);
			long Remove(EventRegistrationToken);
		};

		class EventSource<Windows::Foundation::ITypedEventHandler<Windows::Storage::ApplicationData *,IInspectable *>,InvokeModeOptions<-2> >
		{
			long AddInternal(Windows::Foundation::ITypedEventHandler<Windows::Storage::ApplicationData *,IInspectable *> *,void *,EventRegistrationToken *);
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

		struct RuntimeClass<RuntimeClassFlags<2>,IUnknown>
		{
			RuntimeClass<RuntimeClassFlags<2>,IUnknown>();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,Windows::Internal::IComPoolTask>
		{
			RuntimeClass<RuntimeClassFlags<2>,Windows::Internal::IComPoolTask>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,Windows::Storage::Private::IApplicationDataCompositeValueInternal,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,Windows::Storage::Private::IApplicationDataCompositeValueInternal,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> >
		{
			RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,Windows::Storage::ApplicationDataContainer *> *> >();
		};

		struct RuntimeClass<Windows::Storage::IApplicationData,Windows::Storage::IApplicationData2,Windows::Storage::IApplicationData3,FtmBase>
		{
			RuntimeClass<Windows::Storage::IApplicationData,Windows::Storage::IApplicationData2,Windows::Storage::IApplicationData3,FtmBase>();
		};

		struct SimpleActivationFactory<Windows::Storage::ApplicationDataCompositeValueServer,0>
		{
			virtual long ActivateInstance(IInspectable * *);
		};

		namespace Wrappers
		{
			class HStringReference
			{
				void CreateReference(unsigned short const *,unsigned int,unsigned int);
			public:
				HStringReference<unsigned short const *>(unsigned short const * const &,Details::Dummy);
			};

		};

		Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics * gCausality;
		_RTL_RUN_ONCE gCausalityInitOnce;
	};

};

class RoVariant
{
	RoVariant(IInspectable *,bool,bool);
public:
	~RoVariant();
};

struct RpcOptionsHelper
{
	static long GetRpcOptions(IUnknown *,bool,IRpcOptions * *);
};

class StateRoamingRpcClient
{
	static long PrepareBindingHandle();
	static long SetupMutualAuthentication(void *,unsigned short *);
public:
	static long SendSignalHighPrioritySettingChange(int,unsigned int,unsigned short const *,unsigned long,unsigned char const *,unsigned long,_FILETIME const *);
	static long SendSignalRoamingDataChange(SIGNAL_DATA_OPERATION);
};

namespace StateSchema
{
	long GetOrCreateSchemaContext(void *,bool,StateSchema::SCHEMA_CONTEXT *);
	long GetPackageFullName(StateSchema::SCHEMA_CONTEXT *,unsigned short * *);
	long GetSchemasRootKeyAndPath(void *,HKEY__ * *,unsigned short * *);
	long GetStateSchema(StateSchema::SCHEMA_CONTEXT *,unsigned int *);
};

namespace Windows
{
	namespace Foundation
	{
		namespace Collections
		{
			namespace Detail
			{
				long _IteratorGetMany<IIterator_impl<IKeyValuePair<HSTRING__ *,IInspectable *> *,1>,IKeyValuePair<HSTRING__ *,IInspectable *> *>(IIterator_impl<IKeyValuePair<HSTRING__ *,IInspectable *> *,1> *,unsigned int,IKeyValuePair<HSTRING__ *,IInspectable *> * *,unsigned int *);
				long _IteratorGetMany<IIterator_impl<IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> *,1>,IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> *>(IIterator_impl<IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> *,1> *,unsigned int,IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> * *,unsigned int *);
			};

			struct IIterator_impl<IKeyValuePair<HSTRING__ *,IInspectable *> *,1>
			{
				virtual long GetMany(unsigned int,IKeyValuePair<HSTRING__ *,IInspectable *> * *,unsigned int *);
			};

			struct IIterator_impl<IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> *,1>
			{
				virtual long GetMany(unsigned int,IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> * *,unsigned int *);
			};

			namespace Internal
			{
				class HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >
				{
					class Iterator
					{
						long EnsureVersionMatches();
					public:
						Iterator(HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > *);
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
						View(HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > *,DefaultEqualityPredicate<HSTRING__ *>);
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
					static void _Free(XWinRT::XHashMap<HSTRING__ *,IInspectable *,HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::KeyTraits,XWinRT::CElementTraits<IInspectable *> > *);
					void _EraseAll(XWinRT::XHashMap<HSTRING__ *,IInspectable *,HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::KeyTraits,XWinRT::CElementTraits<IInspectable *> > *);
				protected:
					virtual ~HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >();
				public:
					HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >(DefaultHash<HSTRING__ *> const &,DefaultEqualityPredicate<HSTRING__ *> const &,HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::permission);
					static long Make(DefaultHash<HSTRING__ *> const &,DefaultEqualityPredicate<HSTRING__ *> const &,HashMap<HSTRING__ *,IInspectable *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > * *);
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
					virtual long add_MapChanged(MapChangedEventHandler<HSTRING__ *,IInspectable *> *,EventRegistrationToken *);
					virtual long get_Size(unsigned int *);
					virtual long remove_MapChanged(EventRegistrationToken);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class HashMap<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<Storage::ApplicationDataContainer *>,DefaultHashMapOptions<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultLifetimeTraits<HSTRING__ *> > >
				{
					class Iterator
					{
						long EnsureVersionMatches();
					public:
						Iterator(HashMap<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<Storage::ApplicationDataContainer *>,DefaultHashMapOptions<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultLifetimeTraits<HSTRING__ *> > > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetMany(unsigned int,IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> * * const,unsigned int *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class View
					{
						long EnsureVersionMatches();
					public:
						virtual long First(IIterator<IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(HSTRING__ *,unsigned char *);
						virtual long Lookup(HSTRING__ *,Storage::IApplicationDataContainer * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<HSTRING__ *,Storage::ApplicationDataContainer *> * *,IMapView<HSTRING__ *,Storage::ApplicationDataContainer *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					static void _Free(XWinRT::XHashMap<HSTRING__ *,Storage::IApplicationDataContainer *,HashMap<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<Storage::ApplicationDataContainer *>,DefaultHashMapOptions<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,XWinRT::CElementTraits<Storage::IApplicationDataContainer *> > *);
					void _EraseAll(XWinRT::XHashMap<HSTRING__ *,Storage::IApplicationDataContainer *,HashMap<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<Storage::ApplicationDataContainer *>,DefaultHashMapOptions<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,XWinRT::CElementTraits<Storage::IApplicationDataContainer *> > *);
				public:
					virtual long Clear();
					virtual long First(IIterator<IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IMapView<HSTRING__ *,Storage::ApplicationDataContainer *> * *);
					virtual long HasKey(HSTRING__ *,unsigned char *);
					virtual long Insert(HSTRING__ *,Storage::IApplicationDataContainer *,unsigned char *);
					virtual long Lookup(HSTRING__ *,Storage::IApplicationDataContainer * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Remove(HSTRING__ *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0>
				{
					static long RaiseEvent(XWinRT::detail::ReentrancyGuard<1> &,Microsoft::WRL::EventSource<MapChangedEventHandler<HSTRING__ *,IInspectable *>,Microsoft::WRL::InvokeModeOptions<-2> > &,IObservableMap<HSTRING__ *,IInspectable *> *,CollectionChange,HSTRING__ *);
				};

				struct HashMapOptions<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultLifetimeTraits<HSTRING__ *>,0,0,0>
				{
					static long RaiseEvent(...);
				};

				struct MapChangedEventArgs<HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *> >
				{
					MapChangedEventArgs<HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *> >(CollectionChange);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_CollectionChange(CollectionChange *);
					virtual long get_Key(HSTRING__ * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >
				{
					class Chunk
					{
						virtual void dummy();
					public:
						long Release();
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
						SplitIterator(NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > *);
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
					NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >(DefaultEqualityPredicate<HSTRING__ *> const &,NaiveSplitView<HSTRING__ *,IInspectable *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<IInspectable *>,HashMapOptions<HSTRING__ *,IInspectable *,DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::permission);
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

				class NaiveSplitView<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<Storage::ApplicationDataContainer *>,DefaultHashMapOptions<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultLifetimeTraits<HSTRING__ *> > >
				{
					class Chunk
					{
						virtual void dummy();
					public:
						long Release();
					};

					struct ChunkElementIterator
					{
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					struct ChunkView
					{
						long Initialize(IIterator<IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> *> *);
						virtual long First(IIterator<IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(HSTRING__ *,unsigned char *);
						virtual long Lookup(HSTRING__ *,Storage::IApplicationDataContainer * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<HSTRING__ *,Storage::ApplicationDataContainer *> * *,IMapView<HSTRING__ *,Storage::ApplicationDataContainer *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class SplitIterator
					{
						long EnsureForced();
					public:
						SplitIterator(NaiveSplitView<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<Storage::ApplicationDataContainer *>,DefaultHashMapOptions<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultLifetimeTraits<HSTRING__ *> > > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					long Force();
					long Initialize(IMapView<HSTRING__ *,Storage::ApplicationDataContainer *> *);
				public:
					NaiveSplitView<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<Storage::ApplicationDataContainer *>,DefaultHashMapOptions<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultLifetimeTraits<HSTRING__ *> > >(DefaultEqualityPredicate<HSTRING__ *> const &,NaiveSplitView<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<Storage::ApplicationDataContainer *>,DefaultHashMapOptions<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultLifetimeTraits<HSTRING__ *> > >::permission);
					static long Split(IMapView<HSTRING__ *,Storage::ApplicationDataContainer *> *,IMapView<HSTRING__ *,Storage::ApplicationDataContainer *> * *,IMapView<HSTRING__ *,Storage::ApplicationDataContainer *> * *,DefaultEqualityPredicate<HSTRING__ *> const &);
					virtual long First(IIterator<IKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long HasKey(HSTRING__ *,unsigned char *);
					virtual long Lookup(HSTRING__ *,Storage::IApplicationDataContainer * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Split(IMapView<HSTRING__ *,Storage::ApplicationDataContainer *> * *,IMapView<HSTRING__ *,Storage::ApplicationDataContainer *> * *);
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

				class SimpleKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<Storage::ApplicationDataContainer *>,0>
				{
					long Initialize(HSTRING__ * const &,Storage::IApplicationDataContainer * const &);
				public:
					static long Make(HSTRING__ * const &,Storage::IApplicationDataContainer * const &,SimpleKeyValuePair<HSTRING__ *,Storage::ApplicationDataContainer *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<Storage::ApplicationDataContainer *>,0> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Key(HSTRING__ * *);
					virtual long get_Value(Storage::IApplicationDataContainer * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

			};

		};

		long ActivateInstance<Microsoft::WRL::ComPtr<Management::Deployment::Internal::IPackageManagerStateCreationInternal> >(HSTRING__ *,Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<Management::Deployment::Internal::IPackageManagerStateCreationInternal> >);
		long GetActivationFactory<Microsoft::WRL::ComPtr<ApplicationModel::Core::ICoreApplication> >(HSTRING__ *,Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<ApplicationModel::Core::ICoreApplication> >);
		long GetActivationFactory<Microsoft::WRL::ComPtr<IActivationFactory> >(HSTRING__ *,Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<IActivationFactory> >);
		long GetActivationFactory<Microsoft::WRL::ComPtr<System::Internal::ISignInStateManager> >(HSTRING__ *,Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<System::Internal::ISignInStateManager> >);
	};

	namespace Internal
	{
		struct CMarshaledInterfaceResult<Storage::IApplicationData>
		{
			long Get(Storage::IApplicationData * *);
		};

		class ComTaskPool
		{
			struct CRemoteReleaseStub
			{
				CRemoteReleaseStub(IComPoolTask *);
			};

			struct CRemoteTask
			{
				long RuntimeClassInitialize(IComPoolTask *);
				virtual void Run();
			};

			class CThread
			{
				long _CreateThreadRef(long *,IUnknown * *);
				long _WaitForThreadUpdate(unsigned long);
				static HINSTANCE__ * s_ExecuteThreadProc(void *);
				static unsigned long s_ThreadProc(void *);
				static void s_CheckForDeadlockTimerCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *);
				static void s_ThreadPoolCallback(_TP_CALLBACK_INSTANCE *,void *);
				void _DispatchMessage(tagMSG *);
				void _ThreadProc();
			public:
				CThread(TaskApartment,TaskOptions);
				bool Eligible(TaskApartment,TaskOptions);
				long StartThread();
				long StartThreadWithFallback();
				long WaitForThreadStart();
				long _StartThreadCommon();
				void CheckForDeadlock();
			};

			struct TaskData
			{
				TaskData(TaskApartment,TaskOptions,unsigned long,IComPoolTask *);
			};

			struct TaskList
			{
				TaskData * PopFront();
				void Clear();
			};

			static ComTaskPool::CThread * s_pThreadList;
			static ComTaskPool::SThreadData tls_threadData;
			static ComTaskPool::TaskList s_taskFloodingList;
			static _RTL_SRWLOCK s_rwLock;
			static bool s_RunNested(TaskApartment,TaskOptions);
			static bool s_TryRemoveThread(ComTaskPool::CThread *,bool);
			static bool volatile s_fCanReuseThreads;
			static bool volatile s_fWaitForMoreTasks;
			static long s_AddThreadAffineWrapper(IComPoolTask *,IComPoolTask * *);
			static long s_GetTaskPoolTlsSlot(unsigned long *);
			static long s_QueuePoolTask(TaskApartment,TaskOptions,unsigned long,IComPoolTask *);
			static long s_QueuePoolTaskUnderLock(void *,TaskApartment,TaskOptions,unsigned long,IComPoolTask *,ComTaskPool::TaskList *,ComTaskPool::CThread * *);
			static unsigned long volatile s_cThreadsStarting;
			static unsigned long volatile s_dwThreadIdReuse;
			static void * s_hEventCache;
			static void s_AttachAndRecoverTask(ComTaskPool::TaskData *);
			static void s_ClearOrGetNextTask(ComTaskPool::CThread *);
		public:
			static long RunTask(TaskApartment,TaskOptions,unsigned long,unsigned long,IComPoolTask *,IUnknown * *);
		};

		struct ComTaskPoolHandler
		{
			static long _FireCompletion(IAsyncFireCompletion *);
		};

		namespace Details
		{
			struct Git
			{
				Git();
				long Acquire();
				~Git();
			};

			struct GitInvokeHelper<Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *>,GitPtr,2>
			{
				GitInvokeHelper<Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *>,GitPtr,2>();
				virtual long Invoke(Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> *,Foundation::Collections::IMapChangedEventArgs<HSTRING__ *> *);
			};

			struct GitInvokeHelper<Foundation::ITypedEventHandler<Storage::ApplicationData *,IInspectable *>,GitPtr,2>
			{
				GitInvokeHelper<Foundation::ITypedEventHandler<Storage::ApplicationData *,IInspectable *>,GitPtr,2>();
				virtual long Invoke(Storage::IApplicationData *,IInspectable *);
			};

			Details::Git _git;
			long CreateGitHelper<Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *>,GitPtr>(Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *> *,Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *> * *);
			long CreateGitHelper<Foundation::ITypedEventHandler<Storage::ApplicationData *,IInspectable *>,GitPtr>(Foundation::ITypedEventHandler<Storage::ApplicationData *,IInspectable *> *,Foundation::ITypedEventHandler<Storage::ApplicationData *,IInspectable *> * *);
		};

		struct GitEventSource<Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *>,Microsoft::WRL::InvokeModeOptions<-2> >
		{
			long Add(Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *> *,EventRegistrationToken *);
		};

		struct GitEventSource<Foundation::ITypedEventHandler<Storage::ApplicationData *,IInspectable *>,Microsoft::WRL::InvokeModeOptions<-2> >
		{
			long Add(Foundation::ITypedEventHandler<Storage::ApplicationData *,IInspectable *> *,EventRegistrationToken *);
		};

		struct GitPtr
		{
			GitPtr();
		};

		class GitPtrImpl<GitPtr>
		{
		protected:
			long Localize(_GUID const &,void * *);
		public:
			long Revoke();
			virtual bool IsInitialized();
		};

		struct GitPtrSupportsAgile<Foundation::IAsyncOperationCompletedHandler<Storage::ApplicationData *> >
		{
			long CopyLocal(_GUID const &,void * *);
			long Initialize<Foundation::IAsyncOperationCompletedHandler<Storage::ApplicationData *> >(Foundation::IAsyncOperationCompletedHandler<Storage::ApplicationData *> *);
		};

		struct GitPtrSupportsAgile<INilDelegate>
		{
			long CopyLocal(_GUID const &,void * *);
			long Initialize<INilDelegate>(INilDelegate *);
		};

		class StaticLifetimeStore
		{
			static long GetPropertyBagForThread(ApplicationModel::Core::ICoreApplication *,unsigned char,Foundation::Collections::IPropertySet * *);
		public:
			static long Write(ApplicationModel::Core::ICoreApplication *,unsigned short const *,IInspectable *,unsigned char);
		};

		struct String
		{
			long Initialize(HSTRING__ * const &);
			void Release();
		};

		class StringReference
		{
			void _ConstructorHelper(unsigned short const *);
		public:
			StringReference<29>(unsigned short const (&)[29]);
			StringReference<36>(unsigned short const (&)[36]);
			StringReference<46>(unsigned short const (&)[46]);
			StringReference<75>(unsigned short const (&)[75]);
		};

		_RTL_RUN_ONCE s_bIsEnvironmentCheckDone;
	};

	namespace Management
	{
		namespace Core
		{
			class ApplicationDataManagerFactoryServer
			{
				long InternalCreateForPackageFamily(HSTRING__ *,void *,Storage::IApplicationData * *);
			public:
				virtual long ActivateInstance(IInspectable * *);
				virtual long CreateForPackageFamily(HSTRING__ *,Storage::IApplicationData * *);
				virtual long CreateForPackageFamilyWithUserImpersonation(HSTRING__ *,Storage::IApplicationData * *);
			};

			struct ApplicationDataManagerServer
			{
				static TrustLevel InternalGetTrustLevel();
				static unsigned short const * InternalGetRuntimeClassName();
			};

			Microsoft::WRL::Details::CreatorMap const __object_ApplicationDataManagerServer;
			Microsoft::WRL::Details::FactoryCache __objectFactory__ApplicationDataManagerServer;
		};

	};

	namespace Storage
	{
		class ApplicationDataCompositeValueServer
		{
			class Iterator
			{
			protected:
				virtual long RuntimeClassInitialize(void *,ApplicationDataCompositeValueServer *);
			public:
				Iterator();
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long MoveNext(unsigned char *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual long get_Current(Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> * *);
				virtual long get_HasCurrent(unsigned char *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~Iterator();
			};

			virtual long InternalCreateCompositeSettingsHashMapSnapshot(Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > * *);
		protected:
			virtual long SignalDataChanged();
		public:
			ApplicationDataCompositeValueServer();
			static TrustLevel InternalGetTrustLevel();
			static unsigned short const * InternalGetRuntimeClassName();
			virtual long Clear();
			virtual long Commit(IInspectable *,HSTRING__ *);
			virtual long First(Foundation::Collections::IIterator<Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long GetView(Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
			virtual long HasKey(HSTRING__ *,unsigned char *);
			virtual long Initialize(void *,HSTRING__ *);
			virtual long Insert(HSTRING__ *,IInspectable *,unsigned char *);
			virtual long Lookup(HSTRING__ *,IInspectable * *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual long Remove(HSTRING__ *);
			virtual long RuntimeClassInitialize();
			virtual long Serialize(unsigned char * *,unsigned int *);
			virtual long add_MapChanged(Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *> *,EventRegistrationToken *);
			virtual long get_Size(unsigned int *);
			virtual long remove_MapChanged(EventRegistrationToken);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ApplicationDataContainerServer
		{
			ApplicationDataContainerServer();
			virtual long CreateContainer(HSTRING__ *,ApplicationDataCreateDisposition,IApplicationDataContainer * *);
			virtual long DeleteContainer(HSTRING__ *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long Initialize(void * const,ApplicationDataLocality,HSTRING__ *,ApplicationDataCreateDisposition,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> const &,bool *);
			virtual long Initialize(void * const,ApplicationDataLocality,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> const &,System::IUser *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual long get_Containers(Foundation::Collections::IMapView<HSTRING__ *,ApplicationDataContainer *> * *);
			virtual long get_Locality(ApplicationDataLocality *);
			virtual long get_Name(HSTRING__ * *);
			virtual long get_Values(Foundation::Collections::IPropertySet * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		class ApplicationDataContainerSettingsServer
		{
			virtual long InternalCreateContainerSettingsHashMapSnapshot(Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > * *);
			virtual long InternalCreatePropertyValue(HSTRING__ * const &,unsigned char const *,unsigned int,tag_STATE_VALUE_TYPE,IInspectable * *);
			virtual long InternalInsertValue(HSTRING__ * const &,StateABIHelpers::SettingPropertyToApiSetValueConverter &,_FILETIME const *);
			virtual long InternalLookupCompositeValue(HSTRING__ * const &,IInspectable * *);
		protected:
			long SignalDataChanged();
		public:
			virtual long Clear();
			virtual long First(Foundation::Collections::IIterator<Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long GetView(Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
			virtual long HasKey(HSTRING__ *,unsigned char *);
			virtual long Initialize(void *,ApplicationDataLocality,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> const &);
			virtual long Insert(HSTRING__ *,IInspectable *,unsigned char *);
			virtual long Lookup(HSTRING__ *,IInspectable * *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual long Remove(HSTRING__ *);
			virtual long add_MapChanged(Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *> *,EventRegistrationToken *);
			virtual long get_Size(unsigned int *);
			virtual long remove_MapChanged(EventRegistrationToken);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		class ApplicationDataFactoryServer
		{
			static long BuildPropertyKeyByUserSid(HSTRING__ *,HSTRING__ * *);
			static long GetApplicationDataInstance(HSTRING__ *,IApplicationData * *);
		public:
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetForUserAsync(System::IUser *,Foundation::IAsyncOperation<ApplicationData *> * *);
			virtual long get_Current(IApplicationData * *);
		};

		class ApplicationDataServer
		{
			long InitializeDataChangedSignaler();
			long InternalClearAsync(Microsoft::WRL::ComPtr<StateABIImplementation::ClearOperation>,Foundation::IAsyncAction * *);
			long InternalClearPublisherFolderAsync(Microsoft::WRL::ComPtr<StateABIImplementation::ClearOperation>,Foundation::IAsyncAction * *);
			long InternalGetPublisherFolder(HSTRING__ * const,IStorageFolder * *);
			long InternalGetPublisherFolderFullTrustCaller(HSTRING__ * const,IStorageFolder * *);
			long InternalGetPublisherFolderPartialTrustCaller(HSTRING__ * const,IStorageFolder * *);
			long InternalGetRootContainer(ApplicationDataLocality,IApplicationDataContainer * *);
			long InternalGetRootStorageFolder(ApplicationDataLocality,IStorageFolder * *);
			long InternalGetRootStorageFolderFullTrustCaller(tag_STATE_PERSIST_ATTRIB,IStorageFolder * *);
			long InternalGetRootStorageFolderPartialTrustCaller(tag_STATE_PERSIST_ATTRIB,IStorageFolder * *);
			long InternalGetSharedLocalFolder(IStorageFolder * *);
			long InternalGetSharedLocalFolderFullTrustCaller(IStorageFolder * *);
			long InternalGetSharedLocalFolderPartialTrustCaller(IStorageFolder * *);
			void SqmGetPublisherFolderError(long,unsigned short const *,unsigned short const *);
			void SqmGetRootStorageFolderError(long,tag_STATE_PERSIST_ATTRIB,unsigned short const *);
			void SqmGetSharedLocalFolderError(long,unsigned short const *);
		public:
			ApplicationDataServer();
			static TrustLevel InternalGetTrustLevel();
			static unsigned short const * InternalGetRuntimeClassName();
			virtual long ClearAllAsync(Foundation::IAsyncAction * *);
			virtual long ClearAsync(ApplicationDataLocality,Foundation::IAsyncAction * *);
			virtual long ClearPublisherCacheFolderAsync(HSTRING__ * const,Foundation::IAsyncAction * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetPublisherCacheFolder(HSTRING__ * const,IStorageFolder * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long Initialize();
			virtual long Initialize(HSTRING__ *,void *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual long SetVersionAsync(unsigned int,IApplicationDataSetVersionHandler *,Foundation::IAsyncAction * *);
			virtual long SignalDataChanged();
			virtual long add_DataChanged(Foundation::ITypedEventHandler<ApplicationData *,IInspectable *> *,EventRegistrationToken *);
			virtual long get_LocalCacheFolder(IStorageFolder * *);
			virtual long get_LocalFolder(IStorageFolder * *);
			virtual long get_LocalSettings(IApplicationDataContainer * *);
			virtual long get_RoamingFolder(IStorageFolder * *);
			virtual long get_RoamingSettings(IApplicationDataContainer * *);
			virtual long get_RoamingStorageQuota(unsigned __int64 *);
			virtual long get_SharedLocalFolder(IStorageFolder * *);
			virtual long get_TemporaryFolder(IStorageFolder * *);
			virtual long get_Version(unsigned int *);
			virtual long remove_DataChanged(EventRegistrationToken);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual ~ApplicationDataServer();
		};

		class RestrictedApplicationDataServer
		{
			long InternalClearAsync(Microsoft::WRL::ComPtr<StateABIImplementation::ClearOperation>,Foundation::IAsyncAction * *);
			long InternalGetRootStorageFolder(ApplicationDataLocality,IStorageFolder * *);
			long InternalGetRootStorageFolderPartialTrustCaller(tag_STATE_PERSIST_ATTRIB,IStorageFolder * *);
		public:
			RestrictedApplicationDataServer();
			virtual long ClearAllAsync(Foundation::IAsyncAction * *);
			virtual long ClearAsync(ApplicationDataLocality,Foundation::IAsyncAction * *);
			virtual long ClearPublisherCacheFolderAsync(HSTRING__ * const,Foundation::IAsyncAction * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetPublisherCacheFolder(HSTRING__ * const,IStorageFolder * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long Initialize();
			virtual long Initialize(HSTRING__ *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual long SetVersionAsync(unsigned int,IApplicationDataSetVersionHandler *,Foundation::IAsyncAction * *);
			virtual long SignalDataChanged();
			virtual long add_DataChanged(Foundation::ITypedEventHandler<ApplicationData *,IInspectable *> *,EventRegistrationToken *);
			virtual long get_LocalCacheFolder(IStorageFolder * *);
			virtual long get_LocalFolder(IStorageFolder * *);
			virtual long get_LocalSettings(IApplicationDataContainer * *);
			virtual long get_RoamingFolder(IStorageFolder * *);
			virtual long get_RoamingSettings(IApplicationDataContainer * *);
			virtual long get_RoamingStorageQuota(unsigned __int64 *);
			virtual long get_SharedLocalFolder(IStorageFolder * *);
			virtual long get_TemporaryFolder(IStorageFolder * *);
			virtual long get_Version(unsigned int *);
			virtual long remove_DataChanged(EventRegistrationToken);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct SetVersionDeferral
		{
			SetVersionDeferral();
			long RuntimeClassInitialize();
			virtual long Complete();
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual void WaitForOutstandingDeferral();
		};

		struct SetVersionRequest
		{
			SetVersionRequest(unsigned int,unsigned int);
			virtual long GetDeferral(ISetVersionDeferral * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual long get_CurrentVersion(unsigned int *);
			virtual long get_DesiredVersion(unsigned int *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual void WaitForOutstandingDeferral();
		};

		namespace StateABIHelpers
		{
			class DataChangedSignaler
			{
				static void SignalRoamingDataChangeIfEnabled(SIGNAL_DATA_OPERATION);
			public:
				static SIGNAL_DATA_OPERATION LocalityToSignalDataOperation(ApplicationDataLocality);
				static void SignalRoamingDataChanged(SIGNAL_DATA_OPERATION);
			};

			struct FixedWidthArrayDeserializer<1026>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1027>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1028>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1030>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1032>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1033>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1034>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1038>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1039>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1040>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1041>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1042>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArrayDeserializer<1043>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthArraySerializer<1025>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1026>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1027>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1028>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1029>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1030>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1031>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1032>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1033>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1034>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1035>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1038>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1039>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1040>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1041>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1042>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthArraySerializer<1043>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthSingleValueDeserializer<15>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthSingleValueDeserializer<17>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthSingleValueDeserializer<18>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthSingleValueDeserializer<19>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthSingleValueDeserializer<1>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthSingleValueDeserializer<2>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthSingleValueDeserializer<3>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthSingleValueDeserializer<8>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct FixedWidthSingleValueSerializer<10>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthSingleValueSerializer<15>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthSingleValueSerializer<17>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthSingleValueSerializer<18>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthSingleValueSerializer<19>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthSingleValueSerializer<1>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthSingleValueSerializer<2>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthSingleValueSerializer<3>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			struct FixedWidthSingleValueSerializer<8>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			class Logging
			{
				static _RTL_SRWLOCK lock;
				static long AcquireLockAndInitLogging();
				static long GetPackageFamilyName(unsigned int,unsigned short *);
				static long Initialize();
				static long LogEvent(_EVENT_DESCRIPTOR const *);
				static long LogEvent(_EVENT_DESCRIPTOR const *,unsigned short const *);
				static long LogEvent(_EVENT_DESCRIPTOR const *,unsigned short const *,long);
				static long LogEvent(_EVENT_DESCRIPTOR const *,unsigned short const *,unsigned short const *,long);
				static long LogEvent(_EVENT_DESCRIPTOR const *,unsigned short const *,unsigned short const *,long,long);
				static unsigned __int64 eventRegisteredHandle;
			public:
				static long LogAppRegistrationRepairResult(unsigned short const *,long,long);
				static long LogFixStateLocationsAccessFailed(long);
				static long LogFixStateLocationsAccessSucceeded();
				static long LogPublisherStorageFolderInstantiationError(unsigned short const *,void * const,long);
				static long LogSharedLocalFolderInstantiationError(void * const,long);
				static long LogStateUpdateRequired(_EVENT_DESCRIPTOR const *,unsigned short const *,unsigned short const *,long);
				static long LogStorageFolderInstantiationError(tag_STATE_PERSIST_ATTRIB,void * const,long);
				static long SetPerformanceMarker(_EVENT_DESCRIPTOR const *);
				static long Unregister();
			};

			struct PropertyValueTraits<1025>
			{
				static long CreatePropertyValue(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct PropertyValueTraits<1026>
			{
				static long CreatePropertyValue(short const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,short * *);
			};

			struct PropertyValueTraits<1027>
			{
				static long CreatePropertyValue(unsigned short const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,unsigned short * *);
			};

			struct PropertyValueTraits<1028>
			{
				static long CreatePropertyValue(int const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,int * *);
			};

			struct PropertyValueTraits<1029>
			{
				static long CreatePropertyValue(unsigned int const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct PropertyValueTraits<1030>
			{
				static long CreatePropertyValue(__int64 const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,__int64 * *);
			};

			struct PropertyValueTraits<1031>
			{
				static long CreatePropertyValue(unsigned __int64 const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct PropertyValueTraits<1032>
			{
				static long CreatePropertyValue(float const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,float * *);
			};

			struct PropertyValueTraits<1033>
			{
				static long CreatePropertyValue(double const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,double * *);
			};

			struct PropertyValueTraits<1034>
			{
				static long CreatePropertyValue(unsigned short const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,unsigned short * *);
			};

			struct PropertyValueTraits<1035>
			{
				static long CreatePropertyValue(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,unsigned char * *);
			};

			struct PropertyValueTraits<1036>
			{
				static long CreatePropertyValue(HSTRING__ * const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,HSTRING__ * * *);
			};

			struct PropertyValueTraits<1038>
			{
				static long CreatePropertyValue(Foundation::DateTime const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,Foundation::DateTime * *);
			};

			struct PropertyValueTraits<1039>
			{
				static long CreatePropertyValue(Foundation::TimeSpan const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,Foundation::TimeSpan * *);
			};

			struct PropertyValueTraits<1040>
			{
				static long CreatePropertyValue(_GUID const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,_GUID * *);
			};

			struct PropertyValueTraits<1041>
			{
				static long CreatePropertyValue(Foundation::Point const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,Foundation::Point * *);
			};

			struct PropertyValueTraits<1042>
			{
				static long CreatePropertyValue(Foundation::Size const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,Foundation::Size * *);
			};

			struct PropertyValueTraits<1043>
			{
				static long CreatePropertyValue(Foundation::Rect const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long GetPropertyValueArrayBase(IInspectable *,unsigned int *,Foundation::Rect * *);
			};

			struct PropertyValueTraits<10>
			{
				static long CreatePropertyValue(unsigned short const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<11>
			{
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<12>
			{
				static long ExtractPropertyValue(IInspectable *,unsigned int *,unsigned char * *);
			};

			struct PropertyValueTraits<14>
			{
				static long CreatePropertyValue(Foundation::DateTime const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<15>
			{
				static long CreatePropertyValue(Foundation::TimeSpan const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<16>
			{
				static long CreatePropertyValue(_GUID const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<17>
			{
				static long CreatePropertyValue(Foundation::Point const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<18>
			{
				static long CreatePropertyValue(Foundation::Size const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<19>
			{
				static long CreatePropertyValue(Foundation::Rect const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<1>
			{
				static long CreatePropertyValue(unsigned char const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<2>
			{
				static long CreatePropertyValue(short const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<3>
			{
				static long CreatePropertyValue(unsigned short const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<4>
			{
				static long CreatePropertyValue(int const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<5>
			{
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<6>
			{
				static long CreatePropertyValue(__int64 const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<7>
			{
				static long CreatePropertyValue(unsigned __int64 const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<8>
			{
				static long CreatePropertyValue(float const *,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct PropertyValueTraits<9>
			{
				static long ExtractPropertyValue(IInspectable *,unsigned char *);
			};

			struct SettingPropertyToApiSetValueConverter
			{
				long Initialize(IInspectable *);
			};

			struct VariableWidthArrayDeserializer<1036>
			{
				static long Deserialize(unsigned char const *,unsigned int,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			};

			struct VariableWidthArraySerializer<1036>
			{
				static long Serialize(IInspectable *,tag_STATE_VALUE_TYPE *,unsigned int *,unsigned char * *);
			};

			long ApiSetEnumerateAtom(void *,tag_ENUMERATE_ITEM_TYPE,tag_STATE_ENUM_ITEM *,unsigned int *);
			long ApiSetEnumerateContainer(void *,tag_ENUMERATE_ITEM_TYPE,tag_STATE_ENUM_ITEM *,unsigned int *);
			long CreatePropertySetHashMap<ApplicationDataCompositeValueServer>(tag_STATE_ENUM_ITEM const *,ApplicationDataCompositeValueServer &,Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > * *);
			long CreatePropertySetHashMap<ApplicationDataContainerSettingsServer>(tag_STATE_ENUM_ITEM const *,ApplicationDataContainerSettingsServer &,Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> > * *);
			long CreatePropertyValueFromSettingData(unsigned char const *,unsigned int,tag_STATE_VALUE_TYPE,Microsoft::WRL::ComPtr<Foundation::IPropertyValueStatics> &,IInspectable * *);
			long EnsureFolderAccessible(Microsoft::WRL::ComPtr<IStorageFolder>,System::IUser *);
			long EnumerateApiSetItems(void *,long (*)(void *,tag_ENUMERATE_ITEM_TYPE,tag_STATE_ENUM_ITEM *,unsigned int *),tag_ENUMERATE_ITEM_TYPE,tag_STATE_ENUM_ITEM * *);
			long FixStateLocationsAccess(System::IUser *);
			long GetAppContainerSid(void *,_APPCONTAINER_SID_TYPE *,unsigned long,void *);
			long GetPropertyValueStaticInterface(Foundation::IPropertyValueStatics * *);
			long GetStateApiSetPersistAttrib(ApplicationDataLocality,tag_STATE_PERSIST_ATTRIB *);
			long IsAppContainerProcess(bool *);
			long RepairAppRegistration(unsigned short const *,long,System::IUser *);
			void ReportError(long,unsigned short);
			void TriggerRepairIfNeeded(unsigned short const *,long,System::IUser *);
		};

		namespace StateABIImplementation
		{
			class ClearOperation
			{
				long EnumerateAndDeleteContainerItems(void *,tag_ENUMERATE_ITEM_TYPE);
				long InternalClear(tag_STATE_PERSIST_ATTRIB);
				long InternalClear(unsigned short const *);
				long InternalClearSharedLocal();
				long InternalClearStructured(tag_STATE_PERSIST_ATTRIB);
				long InternalClearUnstructured(tag_STATE_PERSIST_ATTRIB);
				static long RemoveDirectoryTreeCallback(unsigned short const *,ActionType,long,void *);
			protected:
				virtual long DoWork();
			public:
				ClearOperation(unsigned int,void *);
				ClearOperation(unsigned int,void *,ApplicationDataLocality);
				ClearOperation(unsigned int,void *,ApplicationDataLocality,int);
				ClearOperation(unsigned int,void *,int);
				ClearOperation(unsigned int,void *,unsigned short const *);
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class DataChangedSignaler<Foundation::ITypedEventHandler<ApplicationData *,IInspectable *>,IApplicationData>
			{
				long StartWorkerThread();
				static void StateChangeNotificationCallback(void *);
				static void WorkerThreadProcedure(_TP_CALLBACK_INSTANCE *,void *,_TP_WAIT *,long);
				void ListenForEvent();
			public:
				~DataChangedSignaler<Foundation::ITypedEventHandler<ApplicationData *,IInspectable *>,IApplicationData>();
			};

			class GetForUserOperation
			{
				static long GetSidFromUser(System::IUser *,HSTRING__ * *,void * *,unsigned __int64 *);
				static long IsUpdateRequired(unsigned short const *,unsigned short const *,bool *);
			public:
				GetForUserOperation();
				long DoWork(IApplicationData * *);
				long RuntimeClassInitialize(System::IUser *);
				long UpdateStateLocationsIfRequired(HSTRING__ *,unsigned __int64);
			};

			class SetVersionOperation
			{
			protected:
				long AcquireLock();
				virtual long DoWork();
				virtual void WorkCompleted();
			public:
				SetVersionOperation();
				long RuntimeClassInitialize(unsigned int,void *,unsigned int,System::IUser *,IApplicationDataSetVersionHandler *);
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~SetVersionOperation();
			};

			unsigned short const * const ClearOperationDefaultName;
			unsigned short const * const SetVersionAsyncOperationName;
		};

		IGlobalInterfaceTable * g_pGIT;
		Microsoft::WRL::Details::CreatorMap const __object_ApplicationDataCompositeValueServer;
		Microsoft::WRL::Details::CreatorMap const __object_ApplicationDataServer;
		Microsoft::WRL::Details::FactoryCache __objectFactory__ApplicationDataCompositeValueServer;
		Microsoft::WRL::Details::FactoryCache __objectFactory__ApplicationDataServer;
	};

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

	struct ComLock
	{
		ComLock(bool);
	};

	namespace FakeStl
	{
		void swap<XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::KeyTraits,CElementTraits<IInspectable *> > >(XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::KeyTraits,CElementTraits<IInspectable *> > &,XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::KeyTraits,CElementTraits<IInspectable *> > &);
		void swap<XHashMap<HSTRING__ *,Windows::Storage::IApplicationDataContainer *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<Windows::Storage::IApplicationDataContainer *> > >(XHashMap<HSTRING__ *,Windows::Storage::IApplicationDataContainer *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<Windows::Storage::IApplicationDataContainer *> > &,XHashMap<HSTRING__ *,Windows::Storage::IApplicationDataContainer *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<Windows::Storage::IApplicationDataContainer *> > &);
	};

	struct InterfaceLifetimeTraits
	{
		static long Construct<IInspectable>(IInspectable * *,IInspectable *);
		static long Construct<Windows::Storage::IApplicationDataContainer>(Windows::Storage::IApplicationDataContainer * *,Windows::Storage::IApplicationDataContainer *);
		static void Destroy<IInspectable>(IInspectable * *);
		static void Destroy<Windows::Storage::IApplicationDataContainer>(Windows::Storage::IApplicationDataContainer * *);
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

	class XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::KeyTraits,CElementTraits<IInspectable *> >
	{
		long FreeNode(XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::KeyTraits,CElementTraits<IInspectable *> >::CNode *);
		long GetNode(HSTRING__ * const &,unsigned int &,unsigned int &,XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::KeyTraits,CElementTraits<IInspectable *> >::CNode * &,XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::KeyTraits,CElementTraits<IInspectable *> >::CNode * *);
		unsigned int PickSize(unsigned __int64);
		void FreePlexes();
		void UpdateRehashThresholds();
	public:
		TXPOSITION * GetStartPosition();
		XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::KeyTraits,CElementTraits<IInspectable *> >(void *,unsigned int,float,float,float,unsigned int);
		long InitHashTable(unsigned int,bool,bool *);
		long Lookup(HSTRING__ * const &,XHashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<IInspectable *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,IInspectable *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,1,0,0> >::KeyTraits,CElementTraits<IInspectable *> >::CPair * *);
		long Rehash(unsigned int);
		long RemoveAll();
		long RemoveAtPos(TXPOSITION *);
	};

	class XHashMap<HSTRING__ *,Windows::Storage::IApplicationDataContainer *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<Windows::Storage::IApplicationDataContainer *> >
	{
		long FreeNode(XHashMap<HSTRING__ *,Windows::Storage::IApplicationDataContainer *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<Windows::Storage::IApplicationDataContainer *> >::CNode *);
		long GetNode(HSTRING__ * const &,unsigned int &,unsigned int &,XHashMap<HSTRING__ *,Windows::Storage::IApplicationDataContainer *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<Windows::Storage::IApplicationDataContainer *> >::CNode * &,XHashMap<HSTRING__ *,Windows::Storage::IApplicationDataContainer *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<Windows::Storage::IApplicationDataContainer *> >::CNode * *);
		unsigned int PickSize(unsigned __int64);
		void FreePlexes();
		void UpdateRehashThresholds();
	public:
		TXPOSITION * GetStartPosition();
		XHashMap<HSTRING__ *,Windows::Storage::IApplicationDataContainer *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<Windows::Storage::IApplicationDataContainer *> >(void *,unsigned int,float,float,float,unsigned int);
		long InitHashTable(unsigned int,bool,bool *);
		long Lookup(HSTRING__ * const &,XHashMap<HSTRING__ *,Windows::Storage::IApplicationDataContainer *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Storage::ApplicationDataContainer *>,Windows::Foundation::Collections::Internal::DefaultHashMapOptions<HSTRING__ *,Windows::Storage::ApplicationDataContainer *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> > >::KeyTraits,CElementTraits<Windows::Storage::IApplicationDataContainer *> >::CPair * *);
		long Rehash(unsigned int);
		long RemoveAll();
		long RemoveAtPos(TXPOSITION *);
	};

	struct XPlex
	{
		void FreeDataChain();
	};

	namespace detail
	{
		struct ReentrancyGuard<0>
		{
			ReentrancyGuard<0>(...);
		};

		struct ReentrancyGuard<1>
		{
			ReentrancyGuard<1> & operator=(ReentrancyGuard<1>);
			ReentrancyGuard<1>(long,long volatile *);
			long const hr();
		};

	};

};

namespace std
{
	nothrow_t const std::nothrow;
};

namespace wil
{
	namespace details
	{
		class ThreadFailureCallbackHolder
		{
			static long volatile s_telemetryId;
		public:
			static bool GetThreadContext(FailureInfo *,ThreadFailureCallbackHolder *,char *,unsigned __int64);
		};

		namespace in1diag3
		{
			long Log_Hr(void *,unsigned int,char const *,long);
			long Return_GetLastError(void *,unsigned int,char const *);
			long Return_NtStatus(void *,unsigned int,char const *,long);
			long Return_Win32(void *,unsigned int,char const *,unsigned long);
			void FailFast_Unexpected(void *,unsigned int,char const *);
			void Return_Hr(void *,unsigned int,char const *,long);
			void Return_Hr_NoOriginate(void *,unsigned int,char const *,long);
			void _FailFastImmediate_Unexpected();
			void _FailFast_GetLastError(void *,unsigned int,char const *);
			void _Log_Hr(void *,unsigned int,char const *,long);
			void _Log_Win32(void *,unsigned int,char const *,unsigned long);
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
		long NtStatusToHr(long);
		long ReportFailure_GetLastErrorHr(void *,unsigned int,char const *,char const *,char const *,void *,FailureType);
		long ReportFailure_NtStatus(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long);
		long ReportFailure_Win32(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,unsigned long);
		unsigned __int64 ResultStringSize(char const *);
		unsigned __int64 ResultStringSize(unsigned short const *);
		unsigned char (* g_pfnRtlDllShutdownInProgress)();
		unsigned char * WriteResultString<char const *>(unsigned char *,unsigned char *,char const *,char const * *);
		unsigned char * WriteResultString<unsigned short const *>(unsigned char *,unsigned char *,unsigned short const *,unsigned short const * *);
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
		void ResetEvent(void *);
		void SetEvent(void *);
	};

	namespace details_abi
	{
		struct ProcessLocalStorage<ProcessLocalData>
		{
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

Common::StaticLock rpcInitializationLock;
HINSTANCE__ * g_wil_details_ntdllModuleHandle;
HINSTANCE__ * wil_details_GetNtDllModuleHandle();
MicrosoftTelemetryAssertTriggeredNode * g_MicrosoftTelemetryAssertsTriggeredList;
_GUID const GUID_CAUSALITY_WINDOWS_PLATFORM_ID;
_RTL_SRWLOCK g_MicrosoftTelemetryAssertLock;
int InlineIsEqualGUID(_GUID const &,_GUID const &);
long GetUserSidStringByToken(void * const,HSTRING__ * *);
long ResultFromKnownLastError();
long RtlStringCchCatW(unsigned short *,unsigned __int64,unsigned short const *);
long RtlStringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long RtlStringCchLengthW(unsigned short const *,unsigned __int64,unsigned __int64 *);
long RtlStringCchPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long StringCchCatW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchCopyA(char *,unsigned __int64,char const *);
long StringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
unsigned short const * const InterfaceName_Windows_Foundation_IAsyncAction;
unsigned short const * const RuntimeClass_Windows_ApplicationModel_Core_CoreApplication;
unsigned short const * const RuntimeClass_Windows_Foundation_Diagnostics_AsyncCausalityTracer;
unsigned short const * const RuntimeClass_Windows_Foundation_PropertyValue;
unsigned short const * const RuntimeClass_Windows_Management_Core_ApplicationDataManager;
unsigned short const * const RuntimeClass_Windows_Management_Deployment_Internal_PackageManagerStateCreationInternal;
unsigned short const * const RuntimeClass_Windows_Storage_ApplicationData;
unsigned short const * const RuntimeClass_Windows_Storage_ApplicationDataCompositeValue;
unsigned short const * const RuntimeClass_Windows_Storage_ApplicationDataContainer;
unsigned short const * const RuntimeClass_Windows_Storage_ApplicationDataContainerSettings;
unsigned short const * const RuntimeClass_Windows_Storage_KnownFolders;
unsigned short const * const RuntimeClass_Windows_Storage_SetVersionDeferral;
unsigned short const * const RuntimeClass_Windows_Storage_SetVersionRequest;
unsigned short const * const RuntimeClass_Windows_System_Internal_UserManager;
void * operator new(unsigned __int64);
void * operator new(unsigned __int64,std::nothrow_t const &);
void * operator new[](unsigned __int64);
void * operator new[](unsigned __int64,std::nothrow_t const &);
void SqmPackageFamilyname();
void operator delete(void *);
