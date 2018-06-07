struct AutoStubBias<Windows::Foundation::IAsyncAction,Windows::Foundation::IAsyncActionCompletedHandler>
{
	~AutoStubBias<Windows::Foundation::IAsyncAction,Windows::Foundation::IAsyncActionCompletedHandler>();
};

struct AutoStubBias<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream *>,Windows::Foundation::IAsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStream *> >
{
	~AutoStubBias<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream *>,Windows::Foundation::IAsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStream *> >();
};

struct CVaultAutoPtr<SC_HANDLE__ *,int,SC_HANDLE__ *,0>
{
	void Delete();
	~CVaultAutoPtr<SC_HANDLE__ *,int,SC_HANDLE__ *,0>();
};

struct CVaultAutoPtr<_VAULT_ITEM *,void,_VAULT_ITEM *,0>
{
	~CVaultAutoPtr<_VAULT_ITEM *,void,_VAULT_ITEM *,0>();
};

struct CVaultAutoPtr<unsigned short *,void,unsigned short *,0>
{
	void Delete();
	~CVaultAutoPtr<unsigned short *,void,unsigned short *,0>();
};

namespace CallerIdentity
{
	long GetCallingProcessHandle(unsigned long,RUNTIMEBROKER_CALLERIDENTITY_CHECK,void * *);
	long IsProcessAppContainer(void *,bool *);
};

namespace Microsoft
{
	namespace WRL
	{
		struct ActivationFactory<Details::Nil,Details::Nil,Details::Nil,0>
		{
			ActivationFactory<Details::Nil,Details::Nil,Details::Nil,0>();
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ActivationFactory<Windows::Internal::Security::Credentials::IWebAccountInternalFactory,Details::Nil,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ActivationFactory<Windows::Internal::Security::Credentials::IWebAccountProviderInternalFactory,Details::Nil,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ActivationFactory<Windows::Security::Credentials::ICredentialFactory,Details::Nil,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ActivationFactory<Windows::Security::Credentials::IWebAccountFactory,Details::Nil,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ActivationFactory<Windows::Security::Credentials::IWebAccountProviderFactory,Details::Nil,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
		};

		struct ClassFactory<Details::Nil,Details::Nil,Details::Nil,0>
		{
			virtual long LockServer(int);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
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
			long As<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream *> >(Details::ComPtrRef<ComPtr<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream *> > >);
			~ComPtr<IAsyncInfo>();
		};

		class ComPtr<ICallingProcessInfo>
		{
		protected:
			unsigned long InternalRelease();
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

		class ComPtr<IProxyServerIdentity>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IProxyServerIdentity>();
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
			~ComPtr<IUnknown>();
		};

		class ComPtr<IXProcByValueMarshalHelper>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IXProcByValueMarshalHelper>();
		};

		class ComPtr<Windows::Foundation::Collections::Detail::IPropertySetSerializer>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *> >
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		};

		class ComPtr<Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IPropertySet>
		{
		protected:
			unsigned long InternalRelease();
		public:
			long As<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *> >(Details::ComPtrRef<ComPtr<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *> > >);
			~ComPtr<Windows::Foundation::Collections::IPropertySet>();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::AgileHashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0> >
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::AgileVector<Windows::Security::Credentials::PasswordCredential *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *>,0> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::AgileVector<Windows::Security::Credentials::PasswordCredential *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *>,0> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > >
		{
		protected:
			unsigned long InternalRelease();
		public:
			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > > & operator=(ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > > const &);
			void Attach(Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > *);
			~ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::Chunk>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::Chunk>();
		};

		struct ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::ChunkView>
		{
			~ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::ChunkView>();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Credentials::PasswordCredential *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Credentials::PasswordCredential *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Credentials::PasswordCredential *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *>,XWinRT::IntVersionTag,1> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Credentials::PasswordCredential *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Credentials::PasswordCredential *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Credentials::PasswordCredential *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *>,XWinRT::IntVersionTag,1> >();
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

		class ComPtr<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream *> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStream *> >
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStream *> >();
		};

		class ComPtr<Windows::Foundation::IPropertyValueStatics>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::IPropertyValueStatics>();
		};

		class ComPtr<Windows::Foundation::IUriRuntimeClass>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			ComPtr<Windows::Foundation::IUriRuntimeClass> & operator=(Windows::Foundation::IUriRuntimeClass *);
			~ComPtr<Windows::Foundation::IUriRuntimeClass>();
		};

		class ComPtr<Windows::Foundation::IUriRuntimeClassFactory>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Internal::Security::Authentication::Web::ITokenBrokerInternalStatics>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Internal::Security::Authentication::Web::ITokenBrokerInternalStatics>();
		};

		class ComPtr<Windows::Internal::Security::Credentials::CWebAccountInternal>
		{
		protected:
			unsigned long InternalRelease();
		public:
			void Attach(Windows::Internal::Security::Credentials::CWebAccountInternal *);
			~ComPtr<Windows::Internal::Security::Credentials::CWebAccountInternal>();
		};

		class ComPtr<Windows::Internal::Security::Credentials::CWebAccountProviderInternal>
		{
		protected:
			unsigned long InternalRelease();
		public:
			void Attach(Windows::Internal::Security::Credentials::CWebAccountProviderInternal *);
			~ComPtr<Windows::Internal::Security::Credentials::CWebAccountProviderInternal>();
		};

		class ComPtr<Windows::Internal::Security::Credentials::IWebAccountProviderUserContext>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Internal::Security::Credentials::IWebAccountProviderUserContext>();
		};

		class ComPtr<Windows::Security::Credentials::CGetPictureOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Credentials::CGetPictureOperation>();
		};

		class ComPtr<Windows::Security::Credentials::CPasswordCredential>
		{
		protected:
			unsigned long InternalRelease();
		public:
			long As<Windows::Security::Credentials::IPasswordCredential>(Details::ComPtrRef<ComPtr<Windows::Security::Credentials::IPasswordCredential> >);
			~ComPtr<Windows::Security::Credentials::CPasswordCredential>();
		};

		class ComPtr<Windows::Security::Credentials::CSignOutAction>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Credentials::CSignOutAction>();
		};

		class ComPtr<Windows::Security::Credentials::CWebAccount>
		{
		protected:
			unsigned long InternalRelease();
		public:
			void Attach(Windows::Security::Credentials::CWebAccount *);
			~ComPtr<Windows::Security::Credentials::CWebAccount>();
		};

		class ComPtr<Windows::Security::Credentials::CWebAccountProvider>
		{
		protected:
			unsigned long InternalRelease();
		public:
			void Attach(Windows::Security::Credentials::CWebAccountProvider *);
			~ComPtr<Windows::Security::Credentials::CWebAccountProvider>();
		};

		class ComPtr<Windows::Security::Credentials::IWebAccount>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			void Attach(Windows::Security::Credentials::IWebAccount *);
		};

		class ComPtr<Windows::Security::Credentials::IWebAccountProvider>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			ComPtr<Windows::Security::Credentials::IWebAccountProvider> & operator=(Windows::Security::Credentials::IWebAccountProvider *);
			void Attach(Windows::Security::Credentials::IWebAccountProvider *);
			~ComPtr<Windows::Security::Credentials::IWebAccountProvider>();
		};

		class ComPtr<Windows::Storage::Streams::IBuffer>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Storage::Streams::IRandomAccessStream>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::System::IUser>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::System::Internal::ISignInStateManager>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::System::Internal::IUserManagerStatics>
		{
		protected:
			unsigned long InternalRelease();
		};

		namespace Details
		{
			class ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,FtmBase>
			{
			protected:
				long CanCastToHelper<0>(_GUID const &,void * *,bool *);
			};

			class ImplementsHelper<RuntimeClassFlags<3>,1,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountProviderSystemInformation>,CloakedIid<IXProcByValueMarshalHelper>,Windows::Internal::Security::CXProcByValueMarshal,Windows::Security::Credentials::IWebAccountProvider3,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountProviderUserContext> >
			{
			protected:
				long CanCastTo(_GUID const &,void * *,bool *);
			};

			class ImplementsHelper<RuntimeClassFlags<3>,1,Windows::Internal::Security::CXProcByValueMarshal,Windows::Security::Credentials::IWebAccountProvider3,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountProviderUserContext> >
			{
			protected:
				long CanCastToHelper<1>(_GUID const &,void * *,bool *);
			};

			class ImplementsHelper<RuntimeClassFlags<3>,1,Windows::Security::Credentials::IWebAccount2,CloakedIid<IXProcByValueMarshalHelper>,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountSystemInformation>,Windows::Internal::Security::CXProcByValueMarshal>
			{
			protected:
				long CanCastToHelper<0>(_GUID const &,void * *,bool *);
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Credentials::CPasswordVault,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Credentials::CPasswordVault,0> >();
			};

			struct MakeAllocator<Windows::Internal::Security::Credentials::CWebAccountInternal>
			{
				~MakeAllocator<Windows::Internal::Security::Credentials::CWebAccountInternal>();
			};

			struct MakeAllocator<Windows::Internal::Security::Credentials::CWebAccountProviderInternal>
			{
				~MakeAllocator<Windows::Internal::Security::Credentials::CWebAccountProviderInternal>();
			};

			struct MakeAllocator<Windows::Security::Credentials::CGetPictureOperation>
			{
				~MakeAllocator<Windows::Security::Credentials::CGetPictureOperation>();
			};

			struct MakeAllocator<Windows::Security::Credentials::CPasswordVault>
			{
				~MakeAllocator<Windows::Security::Credentials::CPasswordVault>();
			};

			struct MakeAllocator<Windows::Security::Credentials::CSignOutAction>
			{
				~MakeAllocator<Windows::Security::Credentials::CSignOutAction>();
			};

			struct MakeAllocator<Windows::Security::Credentials::CWebAccount>
			{
				~MakeAllocator<Windows::Security::Credentials::CWebAccount>();
			};

			struct MakeAllocator<Windows::Security::Credentials::CWebAccountProvider>
			{
				~MakeAllocator<Windows::Security::Credentials::CWebAccountProvider>();
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
				static long AsIID<ActivationFactory<Windows::Security::Credentials::IWebAccountFactory,Nil,Nil,0> >(ActivationFactory<Windows::Security::Credentials::IWebAccountFactory,Nil,Nil,0> *,_GUID const &,void * *);
				static long AsIID<ActivationFactory<Windows::Security::Credentials::IWebAccountProviderFactory,Nil,Nil,0> >(ActivationFactory<Windows::Security::Credentials::IWebAccountProviderFactory,Nil,Nil,0> *,_GUID const &,void * *);
			};

			class RuntimeClassBaseT<1>
			{
			protected:
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Credentials::PasswordCredential *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Credentials::PasswordCredential *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Credentials::IPasswordCredential,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Credentials::IPasswordCredential,IInspectable,FtmBase> *,_GUID const &,void * *);
			};

			class RuntimeClassBaseT<3>
			{
			protected:
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Internal::Security::Credentials::IWebAccountInternal,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Internal::Security::Credentials::IWebAccountInternal,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Internal::Security::Credentials::IWebAccountProviderInternal,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Internal::Security::Credentials::IWebAccountProviderInternal,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Security::Credentials::IWebAccount,Windows::Security::Credentials::IWebAccount2,CloakedIid<IXProcByValueMarshalHelper>,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountSystemInformation>,Windows::Internal::Security::CXProcByValueMarshal> >(RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Security::Credentials::IWebAccount,Windows::Security::Credentials::IWebAccount2,CloakedIid<IXProcByValueMarshalHelper>,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountSystemInformation>,Windows::Internal::Security::CXProcByValueMarshal> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Security::Credentials::IWebAccountProvider,Windows::Security::Credentials::IWebAccountProvider2,Windows::Internal::Security::Credentials::IWebAccountProviderWithMrtResourceIcon,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountProviderSystemInformation>,CloakedIid<IXProcByValueMarshalHelper>,Windows::Internal::Security::CXProcByValueMarshal,Windows::Security::Credentials::IWebAccountProvider3,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountProviderUserContext> > >(RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Security::Credentials::IWebAccountProvider,Windows::Security::Credentials::IWebAccountProvider2,Windows::Internal::Security::Credentials::IWebAccountProviderWithMrtResourceIcon,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountProviderSystemInformation>,CloakedIid<IXProcByValueMarshalHelper>,Windows::Internal::Security::CXProcByValueMarshal,Windows::Security::Credentials::IWebAccountProvider3,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountProviderUserContext> > *,_GUID const &,void * *);
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Credentials::PasswordCredential *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Credentials::PasswordCredential *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMap<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>();
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

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Credentials::IPasswordCredential,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Credentials::IPasswordCredential,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Credentials::IPasswordVault,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Credentials::IPasswordVault,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IWeakReference>
			{
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Internal::Security::Credentials::IWebAccountInternal,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Internal::Security::Credentials::IWebAccountInternal,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Internal::Security::Credentials::IWebAccountProviderInternal,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Internal::Security::Credentials::IWebAccountProviderInternal,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Security::Credentials::IWebAccount,Windows::Security::Credentials::IWebAccount2,CloakedIid<IXProcByValueMarshalHelper>,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountSystemInformation>,Windows::Internal::Security::CXProcByValueMarshal>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Security::Credentials::IWebAccount,Windows::Security::Credentials::IWebAccount2,CloakedIid<IXProcByValueMarshalHelper>,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountSystemInformation>,Windows::Internal::Security::CXProcByValueMarshal>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Security::Credentials::IWebAccountProvider,Windows::Security::Credentials::IWebAccountProvider2,Windows::Internal::Security::Credentials::IWebAccountProviderWithMrtResourceIcon,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountProviderSystemInformation>,CloakedIid<IXProcByValueMarshalHelper>,Windows::Internal::Security::CXProcByValueMarshal,Windows::Security::Credentials::IWebAccountProvider3,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountProviderUserContext> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<3>,1,1,0,Windows::Security::Credentials::IWebAccountProvider,Windows::Security::Credentials::IWebAccountProvider2,Windows::Internal::Security::Credentials::IWebAccountProviderWithMrtResourceIcon,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountProviderSystemInformation>,CloakedIid<IXProcByValueMarshalHelper>,Windows::Internal::Security::CXProcByValueMarshal,Windows::Security::Credentials::IWebAccountProvider3,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountProviderUserContext> >();
			};

			struct WeakReferenceImpl
			{
				WeakReferenceImpl(IUnknown *);
				virtual long Resolve(_GUID const &,IInspectable * *);
			};

			ComPtr<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::ChunkView> Make<Windows::Foundation::Collections::Internal::NaiveSplitView<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::ChunkView,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &>(Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *> &);
			Details::WeakReferenceImpl * CreateWeakReference(IUnknown *);
			bool TerminateMap(Details::ModuleBase *,unsigned short const *,bool);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Credentials::CPasswordVault,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Internal::Security::Credentials::CWebAccountInternalFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Internal::Security::Credentials::CWebAccountProviderInternalFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Credentials::CCredentialFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Credentials::CWebAccountFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Credentials::CWebAccountProviderFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Credentials::PasswordCredentialPropertyStoreActivationFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateClassFactory<SimpleClassFactory<Windows::Security::Credentials::CWebAccount,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateClassFactory<SimpleClassFactory<Windows::Security::Credentials::CWebAccountProvider,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long GetActivationFactory<1>(Details::ModuleBase *,unsigned short const *,HSTRING__ *,IActivationFactory * *);
			long GetCacheEntry(Details::ModuleBase *,unsigned int *,_GUID const &,Details::CreatorMap const *,IUnknown * *);
			long MakeAndInitialize<Windows::Internal::Security::Credentials::CWebAccountInternal,Windows::Internal::Security::Credentials::CWebAccountInternal,unsigned int &,unsigned char * &>(Windows::Internal::Security::Credentials::CWebAccountInternal * *,unsigned int &,unsigned char * &);
			long MakeAndInitialize<Windows::Internal::Security::Credentials::CWebAccountProviderInternal,Windows::Internal::Security::Credentials::CWebAccountProviderInternal,HSTRING__ * &,HSTRING__ * &,HSTRING__ * &,HSTRING__ * &,Windows::Foundation::IUriRuntimeClass * &,unsigned __int64 &>(Windows::Internal::Security::Credentials::CWebAccountProviderInternal * *,HSTRING__ * &,HSTRING__ * &,HSTRING__ * &,HSTRING__ * &,Windows::Foundation::IUriRuntimeClass * &,unsigned __int64 &);
			long MakeAndInitialize<Windows::Internal::Security::Credentials::CWebAccountProviderInternal,Windows::Internal::Security::Credentials::CWebAccountProviderInternal,unsigned int &,unsigned char * &>(Windows::Internal::Security::Credentials::CWebAccountProviderInternal * *,unsigned int &,unsigned char * &);
			long MakeAndInitialize<Windows::Security::Credentials::CWebAccountProvider,Windows::Security::Credentials::CWebAccountProvider,HSTRING__ * &,HSTRING__ * &,HSTRING__ * &,HSTRING__ * &,Windows::Foundation::IUriRuntimeClass * &,unsigned __int64 &>(Windows::Security::Credentials::CWebAccountProvider * *,HSTRING__ * &,HSTRING__ * &,HSTRING__ * &,HSTRING__ * &,Windows::Foundation::IUriRuntimeClass * &,unsigned __int64 &);
			long MakeAndInitialize<Windows::Security::Credentials::CWebAccountProvider,Windows::Security::Credentials::IWebAccountProvider,HSTRING__ * &,HSTRING__ * &,Windows::Foundation::IUriRuntimeClass * &>(Windows::Security::Credentials::IWebAccountProvider * *,HSTRING__ * &,HSTRING__ * &,Windows::Foundation::IUriRuntimeClass * &);
		};

		struct ErrorPropagationPolicyTraits<-1>
		{
			static long FireCompletionErrorPropagationPolicyFilter(long,IUnknown *,void *);
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

		struct RuntimeClass<RuntimeClassFlags<3>,Windows::Security::Credentials::IWebAccount,Windows::Security::Credentials::IWebAccount2,CloakedIid<IXProcByValueMarshalHelper>,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountSystemInformation>,Windows::Internal::Security::CXProcByValueMarshal>
		{
			RuntimeClass<RuntimeClassFlags<3>,Windows::Security::Credentials::IWebAccount,Windows::Security::Credentials::IWebAccount2,CloakedIid<IXProcByValueMarshalHelper>,CloakedIid<Windows::Internal::Security::Credentials::IWebAccountSystemInformation>,Windows::Internal::Security::CXProcByValueMarshal>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,FtmBase>();
			virtual ~RuntimeClass<Windows::Foundation::Collections::IMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *>,Windows::Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *>,Windows::Foundation::Collections::IPropertySet,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>
		{
			RuntimeClass<Windows::Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *>,Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<HSTRING__ *,HSTRING__ *> *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IVector<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IVector<Windows::Security::Credentials::PasswordCredential *>,Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::PasswordCredential *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Credentials::IPasswordCredential,IInspectable,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Security::Credentials::IPasswordCredential,IInspectable,FtmBase>();
		};

		struct SimpleActivationFactory<Windows::Security::Credentials::CPasswordVault,0>
		{
			virtual long ActivateInstance(IInspectable * *);
		};

		struct SimpleClassFactory<Windows::Security::Credentials::CWebAccount,0>
		{
			virtual long CreateInstance(IUnknown *,_GUID const &,void * *);
		};

		struct SimpleClassFactory<Windows::Security::Credentials::CWebAccountProvider,0>
		{
			virtual long CreateInstance(IUnknown *,_GUID const &,void * *);
		};

		namespace Wrappers
		{
			namespace Details
			{
				struct SyncLockExclusive
				{
					~SyncLockExclusive();
				};

				struct SyncLockShared
				{
					~SyncLockShared();
				};

			};

			struct HString
			{
				~HString();
			};

			class HStringReference
			{
				void CreateReference(unsigned short const *,unsigned int,unsigned int);
			public:
				HStringReference<unsigned short const *>(unsigned short const * const &,Details::Dummy);
				~HStringReference();
			};

		};

		Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics * gCausality;
		_RTL_RUN_ONCE gCausalityInitOnce;
	};

};

struct RoVariant
{
	struct Accessor
	{
		long GetGuid(_GUID *);
		long GetString(HSTRING__ * *);
	};

	struct OutRef
	{
		~OutRef();
	};

	RoVariant(IInspectable *,bool);
	RoVariant::OutRef operator&();
	void Attach(IInspectable *);
	~RoVariant();
};

namespace Windows
{
	namespace Foundation
	{
		namespace Collections
		{
			namespace Detail
			{
				long _IteratorGetMany<IIterator_impl<IKeyValuePair<HSTRING__ *,HSTRING__ *> *,1>,IKeyValuePair<HSTRING__ *,HSTRING__ *> *>(IIterator_impl<IKeyValuePair<HSTRING__ *,HSTRING__ *> *,1> *,unsigned int,IKeyValuePair<HSTRING__ *,HSTRING__ *> * *,unsigned int *);
				long _IteratorGetMany<IIterator_impl<Internal::AggregateType<Security::Credentials::PasswordCredential *,Security::Credentials::IPasswordCredential *>,1>,Security::Credentials::IPasswordCredential *>(IIterator_impl<Internal::AggregateType<Security::Credentials::PasswordCredential *,Security::Credentials::IPasswordCredential *>,1> *,unsigned int,Security::Credentials::IPasswordCredential * *,unsigned int *);
				long _VectorGetMany<IVectorView_impl<Internal::AggregateType<Security::Credentials::PasswordCredential *,Security::Credentials::IPasswordCredential *>,1>,Security::Credentials::IPasswordCredential *>(IVectorView_impl<Internal::AggregateType<Security::Credentials::PasswordCredential *,Security::Credentials::IPasswordCredential *>,1> *,unsigned int,unsigned int,Security::Credentials::IPasswordCredential * *,unsigned int *);
				long _VectorGetMany<IVector_impl<Internal::AggregateType<Security::Credentials::PasswordCredential *,Security::Credentials::IPasswordCredential *>,1>,Security::Credentials::IPasswordCredential *>(IVector_impl<Internal::AggregateType<Security::Credentials::PasswordCredential *,Security::Credentials::IPasswordCredential *>,1> *,unsigned int,unsigned int,Security::Credentials::IPasswordCredential * *,unsigned int *);
				long _VectorReplaceAll<IVector_impl<Internal::AggregateType<Security::Credentials::PasswordCredential *,Security::Credentials::IPasswordCredential *>,1>,Security::Credentials::IPasswordCredential *>(IVector_impl<Internal::AggregateType<Security::Credentials::PasswordCredential *,Security::Credentials::IPasswordCredential *>,1> *,unsigned int,Security::Credentials::IPasswordCredential * *);
				void _Cleanup<Security::Credentials::IPasswordCredential,unsigned int>(Security::Credentials::IPasswordCredential * * const,unsigned int);
			};

			struct IIterator_impl<IKeyValuePair<HSTRING__ *,HSTRING__ *> *,1>
			{
				virtual long GetMany(unsigned int,IKeyValuePair<HSTRING__ *,HSTRING__ *> * *,unsigned int *);
			};

			struct IIterator_impl<Internal::AggregateType<Security::Credentials::PasswordCredential *,Security::Credentials::IPasswordCredential *>,1>
			{
				virtual long GetMany(unsigned int,Security::Credentials::IPasswordCredential * *,unsigned int *);
			};

			struct IVectorView_impl<Internal::AggregateType<Security::Credentials::PasswordCredential *,Security::Credentials::IPasswordCredential *>,1>
			{
				virtual long GetMany(unsigned int,unsigned int,Security::Credentials::IPasswordCredential * *,unsigned int *);
			};

			struct IVector_impl<Internal::AggregateType<Security::Credentials::PasswordCredential *,Security::Credentials::IPasswordCredential *>,1>
			{
				virtual long GetMany(unsigned int,unsigned int,Security::Credentials::IPasswordCredential * *,unsigned int *);
				virtual long ReplaceAll(unsigned int,Security::Credentials::IPasswordCredential * *);
			};

			namespace Internal
			{
				class HashMap<HSTRING__ *,HSTRING__ *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >
				{
					class Iterator
					{
						long EnsureVersionMatches();
					public:
						Iterator(HashMap<HSTRING__ *,HSTRING__ *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetMany(unsigned int,IKeyValuePair<HSTRING__ *,HSTRING__ *> * * const,unsigned int *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,HSTRING__ *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class View
					{
						long EnsureVersionMatches();
					public:
						virtual long First(IIterator<IKeyValuePair<HSTRING__ *,HSTRING__ *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(HSTRING__ *,unsigned char *);
						virtual long Lookup(HSTRING__ *,HSTRING__ * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<HSTRING__ *,HSTRING__ *> * *,IMapView<HSTRING__ *,HSTRING__ *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					long Initialize();
					static void _Free(XWinRT::XHashMap<HSTRING__ *,HSTRING__ *,HashMap<HSTRING__ *,HSTRING__ *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,XWinRT::CElementTraits<HSTRING__ *> > *);
					void _EraseAll(XWinRT::XHashMap<HSTRING__ *,HSTRING__ *,HashMap<HSTRING__ *,HSTRING__ *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,XWinRT::CElementTraits<HSTRING__ *> > *);
				public:
					HashMap<HSTRING__ *,HSTRING__ *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >(DefaultHash<HSTRING__ *> const &,DefaultEqualityPredicate<HSTRING__ *> const &,HashMap<HSTRING__ *,HSTRING__ *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::permission);
					static long Make(DefaultHash<HSTRING__ *> const &,DefaultEqualityPredicate<HSTRING__ *> const &,HashMap<HSTRING__ *,HSTRING__ *,DefaultHash<HSTRING__ *>,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > * *);
					virtual long Clear();
					virtual long First(IIterator<IKeyValuePair<HSTRING__ *,HSTRING__ *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IMapView<HSTRING__ *,HSTRING__ *> * *);
					virtual long HasKey(HSTRING__ *,unsigned char *);
					virtual long Insert(HSTRING__ *,HSTRING__ *,unsigned char *);
					virtual long Lookup(HSTRING__ *,HSTRING__ * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Remove(HSTRING__ *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0>
				{
					static long RaiseEvent(...);
				};

				class NaiveSplitView<HSTRING__ *,HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >
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
						virtual long get_Current(IKeyValuePair<HSTRING__ *,HSTRING__ *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					struct ChunkView
					{
						long Initialize(IIterator<IKeyValuePair<HSTRING__ *,HSTRING__ *> *> *);
						virtual long First(IIterator<IKeyValuePair<HSTRING__ *,HSTRING__ *> *> * *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long HasKey(HSTRING__ *,unsigned char *);
						virtual long Lookup(HSTRING__ *,HSTRING__ * *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long Split(IMapView<HSTRING__ *,HSTRING__ *> * *,IMapView<HSTRING__ *,HSTRING__ *> * *);
						virtual long get_Size(unsigned int *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					class SplitIterator
					{
						long EnsureForced();
					public:
						SplitIterator(NaiveSplitView<HSTRING__ *,HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> > *);
						virtual long GetIids(unsigned long *,_GUID * *);
						virtual long GetRuntimeClassName(HSTRING__ * *);
						virtual long GetTrustLevel(TrustLevel *);
						virtual long MoveNext(unsigned char *);
						virtual long QueryInterface(_GUID const &,void * *);
						virtual long get_Current(IKeyValuePair<HSTRING__ *,HSTRING__ *> * *);
						virtual long get_HasCurrent(unsigned char *);
						virtual unsigned long AddRef();
						virtual unsigned long Release();
					};

					long EnsureInitialized();
					long Force();
					long Initialize(IMapView<HSTRING__ *,HSTRING__ *> *);
				public:
					NaiveSplitView<HSTRING__ *,HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >(DefaultEqualityPredicate<HSTRING__ *> const &,NaiveSplitView<HSTRING__ *,HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,HashMapOptions<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::permission);
					static long Split(IMapView<HSTRING__ *,HSTRING__ *> *,IMapView<HSTRING__ *,HSTRING__ *> * *,IMapView<HSTRING__ *,HSTRING__ *> * *,DefaultEqualityPredicate<HSTRING__ *> const &);
					virtual long First(IIterator<IKeyValuePair<HSTRING__ *,HSTRING__ *> *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long HasKey(HSTRING__ *,unsigned char *);
					virtual long Lookup(HSTRING__ *,HSTRING__ * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Split(IMapView<HSTRING__ *,HSTRING__ *> * *,IMapView<HSTRING__ *,HSTRING__ *> * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class SimpleKeyValuePair<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,1>
				{
					long Initialize(HSTRING__ * const &,HSTRING__ * const &);
				public:
					SimpleKeyValuePair<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,1>(SimpleKeyValuePair<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,1>::permission);
					static long Make(HSTRING__ * const &,HSTRING__ * const &,SimpleKeyValuePair<HSTRING__ *,HSTRING__ *,DefaultLifetimeTraits<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,1> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Key(HSTRING__ * *);
					virtual long get_Value(HSTRING__ * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct SimpleVectorIterator<Security::Credentials::PasswordCredential *,Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> >,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,XWinRT::IntVersionTag,1>
				{
					SimpleVectorIterator<Security::Credentials::PasswordCredential *,Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> >,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,XWinRT::IntVersionTag,1>(Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> > *,SimpleVectorIterator<Security::Credentials::PasswordCredential *,Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> >,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,XWinRT::IntVersionTag,1>::permission);
					static long Make(Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> > *,SimpleVectorIterator<Security::Credentials::PasswordCredential *,Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> >,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,XWinRT::IntVersionTag,1> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,Security::Credentials::IPasswordCredential * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long MoveNext(unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Current(Security::Credentials::IPasswordCredential * *);
					virtual long get_HasCurrent(unsigned char *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct SimpleVectorView<Security::Credentials::PasswordCredential *,Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> >,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,XWinRT::IntVersionTag,1>
				{
					SimpleVectorView<Security::Credentials::PasswordCredential *,Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> >,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,XWinRT::IntVersionTag,1>(Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> > *,SimpleVectorView<Security::Credentials::PasswordCredential *,Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> >,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,XWinRT::IntVersionTag,1>::permission);
					virtual long First(IIterator<Security::Credentials::PasswordCredential *> * *);
					virtual long GetAt(unsigned int,Security::Credentials::IPasswordCredential * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,unsigned int,Security::Credentials::IPasswordCredential * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long IndexOf(Security::Credentials::IPasswordCredential *,unsigned int *,unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> >
				{
					long IndexOfInternal(XWinRT::detail::GitStorageType<Security::Credentials::IPasswordCredential> *,unsigned int,Security::Credentials::IPasswordCredential *,unsigned int *,unsigned char *);
					long InsertAtInternal(unsigned int,Security::Credentials::IPasswordCredential *,bool);
					long RemoveAtInternal(unsigned int,bool);
					long ResizeStorage(unsigned int);
					static void _Free(XWinRT::detail::GitStorageType<Security::Credentials::IPasswordCredential> *,unsigned int);
					void _EraseAll(XWinRT::detail::GitStorageType<Security::Credentials::IPasswordCredential> * *,unsigned int *);
				public:
					Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> >(DefaultEqualityPredicate<Security::Credentials::PasswordCredential *> const &,Vector<Security::Credentials::PasswordCredential *,DefaultEqualityPredicate<Security::Credentials::PasswordCredential *>,DefaultLifetimeTraits<Security::Credentials::PasswordCredential *>,VectorOptions<Security::Credentials::PasswordCredential *,0,1,0> >::permission);
					virtual long Append(Security::Credentials::IPasswordCredential *);
					virtual long Clear();
					virtual long First(IIterator<Security::Credentials::PasswordCredential *> * *);
					virtual long GetAt(unsigned int,Security::Credentials::IPasswordCredential * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,unsigned int,Security::Credentials::IPasswordCredential * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IVectorView<Security::Credentials::PasswordCredential *> * *);
					virtual long IndexOf(Security::Credentials::IPasswordCredential *,unsigned int *,unsigned char *);
					virtual long InsertAt(unsigned int,Security::Credentials::IPasswordCredential *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long RemoveAt(unsigned int);
					virtual long RemoveAtEnd();
					virtual long ReplaceAll(unsigned int,Security::Credentials::IPasswordCredential * *);
					virtual long SetAt(unsigned int,Security::Credentials::IPasswordCredential *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct VectorOptions<Security::Credentials::PasswordCredential *,0,1,0>
				{
					static long RaiseEvent(...);
				};

			};

		};

		long ActivateInstance<Collections::IPropertySet>(HSTRING__ *,Foundation::Collections::IPropertySet * *);
		long GetActivationFactory<Microsoft::WRL::ComPtr<Internal::Security::Authentication::Web::ITokenBrokerInternalStatics> >(HSTRING__ *,Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<Internal::Security::Authentication::Web::ITokenBrokerInternalStatics> >);
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

			Details::Git _git;
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
			long CopyLocal<Foundation::Collections::IMap<HSTRING__ *,IInspectable *> >(Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<Foundation::Collections::IMap<HSTRING__ *,IInspectable *> > >);
			long CopyLocal<Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> >(Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<Foundation::Collections::IObservableMap<HSTRING__ *,IInspectable *> > >);
			long Initialize<Foundation::Collections::IPropertySet>(Microsoft::WRL::ComPtr<Foundation::Collections::IPropertySet> const &);
			long Revoke();
			virtual bool IsInitialized();
		};

		struct GitPtrSupportsAgile<Foundation::IAsyncActionCompletedHandler>
		{
			long CopyLocal(_GUID const &,void * *);
			long Initialize<Foundation::IAsyncActionCompletedHandler>(Foundation::IAsyncActionCompletedHandler *);
		};

		struct GitPtrSupportsAgile<Foundation::IAsyncOperationCompletedHandler<Storage::Streams::IRandomAccessStream *> >
		{
			long CopyLocal(_GUID const &,void * *);
			long Initialize<Foundation::IAsyncOperationCompletedHandler<Storage::Streams::IRandomAccessStream *> >(Foundation::IAsyncOperationCompletedHandler<Storage::Streams::IRandomAccessStream *> *);
		};

		namespace Security
		{
			namespace Authentication
			{
				namespace TokenBroker
				{
					long CreateTokenBrokerInternalStatics(Web::ITokenBrokerInternalStatics * *);
					long DuplicateCurrentProcessHandleForServerProcess(IUnknown *,unsigned long,void * *);
					long GetServerProcessHandle(IUnknown *,void * *);
				};

			};

			struct CPropertiesSerializer
			{
				long AddBytesProperty(HSTRING__ *,unsigned char *,unsigned long);
				long AddHStringPropertyBagProperty(HSTRING__ *,Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *> *);
				long AddInt64Property(HSTRING__ *,__int64);
				long AddStringProperty(HSTRING__ *,HSTRING__ *);
				long AddUInt32Property(HSTRING__ *,unsigned int);
				long AddUInt64Property(HSTRING__ *,unsigned __int64);
				long AddUriProperty(HSTRING__ *,Foundation::IUriRuntimeClass *);
				long Initialize();
				static long BufferToBytes(Storage::Streams::IBuffer *,unsigned char * *,unsigned long *);
				static long HStringPropertyBagToPropertySet(Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *> *,Foundation::Collections::IPropertySet * *);
				static long PropertySetToBuffer(Foundation::Collections::IPropertySet *,Storage::Streams::IBuffer * *);
				static long PropertySetToHStringPropertyBag(Foundation::Collections::IPropertySet *,Foundation::Collections::IMap<HSTRING__ *,HSTRING__ *> * *);
				void Swap(CPropertiesSerializer &);
				~CPropertiesSerializer();
			};

			struct CXProcByValueMarshal
			{
				virtual long DisconnectObject(unsigned long);
				virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
				virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
				virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
				virtual long ReleaseMarshalData(IStream *);
				virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
			};

			namespace Credentials
			{
				struct CWebAccountInternal
				{
					CWebAccountInternal();
					long RuntimeClassInitialize(IWebAccountProvider *,HSTRING__ *,WebAccountState,HSTRING__ *,Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *> *,Authentication::Web::Provider::WebAccountScope,HSTRING__ *,HSTRING__ *);
					long RuntimeClassInitialize(unsigned int,unsigned char *);
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_WebAccount(IWebAccount * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CWebAccountInternalFactory
				{
					CWebAccountInternalFactory();
					virtual long ActivateInstance(IInspectable * *);
					virtual long CreateWebAccountInternal(IWebAccountProvider *,HSTRING__ *,WebAccountState,HSTRING__ *,Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *> *,IWebAccountInternal * *);
					virtual long CreateWebAccountInternalFromBytes(unsigned int,unsigned char *,IWebAccountInternal * *);
					virtual long CreateWebAccountInternalWithMapAndRevisionNumber(IWebAccountProvider *,HSTRING__ *,WebAccountState,HSTRING__ *,Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *> *,Authentication::Web::Provider::WebAccountScope,HSTRING__ *,HSTRING__ *,IWebAccountInternal * *);
					virtual long CreateWebAccountInternalWithScope(IWebAccountProvider *,HSTRING__ *,WebAccountState,HSTRING__ *,Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *> *,Authentication::Web::Provider::WebAccountScope,IWebAccountInternal * *);
				};

				struct CWebAccountProviderInternal
				{
					CWebAccountProviderInternal();
					long RuntimeClassInitialize(unsigned int,unsigned char *);
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_WebAccountProvider(IWebAccountProvider * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CWebAccountProviderInternalFactory
				{
					CWebAccountProviderInternalFactory();
					virtual long ActivateInstance(IInspectable * *);
					virtual long CreateWebAccountProviderInternal(HSTRING__ *,HSTRING__ *,HSTRING__ *,HSTRING__ *,Foundation::IUriRuntimeClass *,unsigned __int64,IWebAccountProviderInternal * *);
					virtual long CreateWebAccountProviderInternalFromBytes(unsigned int,unsigned char *,IWebAccountProviderInternal * *);
				};

				Microsoft::WRL::Details::CreatorMap const __object_CWebAccountInternal;
				Microsoft::WRL::Details::CreatorMap const __object_CWebAccountProviderInternal;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CWebAccountInternal;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CWebAccountProviderInternal;
			};

		};

		class String
		{
			long _InitializeHelper(unsigned short const *);
		public:
			long GetLpcwstr(unsigned short const * *);
			long Initialize(HSTRING__ * const &);
			long Initialize(unsigned short const *,unsigned int);
			void Release();
			~String();
		};

		class StringReference
		{
			void _ConstructorHelper(unsigned short const *);
		public:
			StringReference<11>(unsigned short const (&)[11]);
			StringReference<12>(unsigned short const (&)[12]);
			StringReference<13>(unsigned short const (&)[13]);
			StringReference<14>(unsigned short const (&)[14]);
			StringReference<16>(unsigned short const (&)[16]);
			StringReference<18>(unsigned short const (&)[18]);
			StringReference<21>(unsigned short const (&)[21]);
			StringReference<23>(unsigned short const (&)[23]);
			StringReference<26>(unsigned short const (&)[26]);
			StringReference<27>(unsigned short const (&)[27]);
			StringReference<29>(unsigned short const (&)[29]);
			StringReference<33>(unsigned short const (&)[33]);
			StringReference<40>(unsigned short const (&)[40]);
			StringReference<43>(unsigned short const (&)[43]);
			StringReference<65>(unsigned short const (&)[65]);
			StringReference<6>(unsigned short const (&)[6]);
			StringReference<7>(unsigned short const (&)[7]);
			StringReference<9>(unsigned short const (&)[9]);
		};

		_RTL_RUN_ONCE s_bIsEnvironmentCheckDone;
	};

	namespace Security
	{
		namespace Credentials
		{
			struct CCredentialFactory
			{
				CCredentialFactory();
				virtual long ActivateInstance(IInspectable * *);
				virtual long CreatePasswordCredential(HSTRING__ *,HSTRING__ *,HSTRING__ *,IPasswordCredential * *);
			};

			class CGetPictureOperation
			{
				virtual long DoWork();
				virtual long GetResultsImpl(Storage::Streams::IRandomAccessStream * *);
				virtual long InitializeOperationData(GetPictureParams *);
			public:
				CGetPictureOperation();
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class CPasswordCredential
			{
				long PutProperties(Foundation::Collections::IPropertySet *);
			public:
				CPasswordCredential();
				long Initialize(HSTRING__ *,HSTRING__ *,HSTRING__ *);
				static TrustLevel InternalGetTrustLevel();
				static long ItemToCredential(_VAULT_ITEM *,CPasswordCredential * *);
				static unsigned short const * InternalGetRuntimeClassName();
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual long RetrievePassword();
				virtual long get_Password(HSTRING__ * *);
				virtual long get_Properties(Foundation::Collections::IPropertySet * *);
				virtual long get_Resource(HSTRING__ * *);
				virtual long get_UserName(HSTRING__ * *);
				virtual long put_Password(HSTRING__ *);
				virtual long put_Resource(HSTRING__ *);
				virtual long put_UserName(HSTRING__ *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class CPasswordVault
			{
				long GetCredentialProperties(CPasswordCredential *,Internal::String &,_GUID *,unsigned char *);
			public:
				CPasswordVault();
				static TrustLevel InternalGetTrustLevel();
				static unsigned short const * InternalGetRuntimeClassName();
				virtual long Add(IPasswordCredential *);
				virtual long FindAllByResource(HSTRING__ *,Foundation::Collections::IVectorView<PasswordCredential *> * *);
				virtual long FindAllByUserName(HSTRING__ *,Foundation::Collections::IVectorView<PasswordCredential *> * *);
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual long Remove(IPasswordCredential *);
				virtual long Retrieve(HSTRING__ *,HSTRING__ *,IPasswordCredential * *);
				virtual long RetrieveAll(Foundation::Collections::IVectorView<PasswordCredential *> * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class CSignOutAction
			{
				virtual long DoWork();
				virtual long InitializeOperationData(SignOutParams *);
			public:
				CSignOutAction();
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class CWebAccount
			{
				long SerializeObject();
				virtual bool IsInterfaceSupported(_GUID const &);
				virtual long GetObjectByteCount(unsigned long *);
				virtual long GetUnmarshalClassId(_GUID *);
			public:
				CWebAccount();
				long RuntimeClassInitialize(IWebAccountProvider *,HSTRING__ *,WebAccountState);
				long RuntimeClassInitialize(IWebAccountProvider *,HSTRING__ *,WebAccountState,HSTRING__ *,Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *> *,Authentication::Web::Provider::WebAccountScope,HSTRING__ *,HSTRING__ *);
				static TrustLevel InternalGetTrustLevel();
				static unsigned short const * InternalGetRuntimeClassName();
				virtual long FreeObjectBytes(unsigned char *);
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetObjectBytes(unsigned char * *,unsigned long *);
				virtual long GetPictureAsync(WebAccountPictureSize,Foundation::IAsyncOperation<Storage::Streams::IRandomAccessStream *> * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long InitializeObjectFromBytes(unsigned char *,unsigned long);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual long SignOutAsync(Foundation::IAsyncAction * *);
				virtual long SignOutWithClientIdAsync(HSTRING__ *,Foundation::IAsyncAction * *);
				virtual long get_Id(HSTRING__ * *);
				virtual long get_PerUserId(HSTRING__ * *);
				virtual long get_Properties(Foundation::Collections::IMapView<HSTRING__ *,HSTRING__ *> * *);
				virtual long get_RevisionNumber(HSTRING__ * *);
				virtual long get_Scope(Authentication::Web::Provider::WebAccountScope *);
				virtual long get_State(WebAccountState *);
				virtual long get_UserName(HSTRING__ * *);
				virtual long get_WebAccountProvider(IWebAccountProvider * *);
				virtual long put_PerUserId(HSTRING__ *);
				virtual long put_Scope(Authentication::Web::Provider::WebAccountScope);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct CWebAccountFactory
			{
				CWebAccountFactory();
				virtual long ActivateInstance(IInspectable * *);
				virtual long CreateWebAccount(IWebAccountProvider *,HSTRING__ *,WebAccountState,IWebAccount * *);
			};

			class CWebAccountProvider
			{
				long SerializeObject();
				virtual bool IsInterfaceSupported(_GUID const &);
				virtual long GetObjectByteCount(unsigned long *);
				virtual long GetUnmarshalClassId(_GUID *);
			public:
				CWebAccountProvider();
				long RuntimeClassInitialize(HSTRING__ *,HSTRING__ *,Foundation::IUriRuntimeClass *);
				long RuntimeClassInitialize(HSTRING__ *,HSTRING__ *,HSTRING__ *,HSTRING__ *,Foundation::IUriRuntimeClass *,unsigned __int64);
				static TrustLevel InternalGetTrustLevel();
				static unsigned short const * InternalGetRuntimeClassName();
				virtual long FreeObjectBytes(unsigned char *);
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetObjectBytes(unsigned char * *,unsigned long *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long InitializeObjectFromBytes(unsigned char *,unsigned long);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual long UpdateProviderId(HSTRING__ *);
				virtual long get_AddNewAccountRequested(unsigned char *);
				virtual long get_ApplicationUserModelId(HSTRING__ * *);
				virtual long get_Authority(HSTRING__ * *);
				virtual long get_DisplayName(HSTRING__ * *);
				virtual long get_DisplayPurpose(HSTRING__ * *);
				virtual long get_IconMrtResourceString(HSTRING__ * *);
				virtual long get_IconUri(Foundation::IUriRuntimeClass * *);
				virtual long get_Id(HSTRING__ * *);
				virtual long get_LastSelectedAccountId(HSTRING__ * *);
				virtual long get_User(System::IUser * *);
				virtual long get_UserContextToken(unsigned __int64 *);
				virtual long put_AddNewAccountRequested(unsigned char);
				virtual long put_ApplicationUserModelId(HSTRING__ *);
				virtual long put_IconMrtResourceString(HSTRING__ *);
				virtual long put_LastSelectedAccountId(HSTRING__ *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct CWebAccountProviderFactory
			{
				CWebAccountProviderFactory();
				virtual long ActivateInstance(IInspectable * *);
				virtual long CreateWebAccountProvider(HSTRING__ *,HSTRING__ *,Foundation::IUriRuntimeClass *,IWebAccountProvider * *);
			};

			class PasswordCredentialPropertyStore
			{
				static PasswordCredentialPropertyStore::PropertyInfo const * const x_PropertyInfo;
				static long ValidateProperty(HSTRING__ *,IInspectable *);
			public:
				PasswordCredentialPropertyStore();
				long Initialize();
				static TrustLevel InternalGetTrustLevel();
				static long CreatePropertySet(unsigned short const *,_GUID const *,int,Foundation::Collections::IPropertySet * *);
				static unsigned short const * GetPropertyName(PasswordCredentialPropertyStore::EPropertyType);
				static unsigned short const * InternalGetRuntimeClassName();
				virtual long Clear();
				virtual long First(Foundation::Collections::IIterator<Foundation::Collections::IKeyValuePair<HSTRING__ *,IInspectable *> *> * *);
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetView(Foundation::Collections::IMapView<HSTRING__ *,IInspectable *> * *);
				virtual long HasKey(HSTRING__ *,unsigned char *);
				virtual long Insert(HSTRING__ *,IInspectable *,unsigned char *);
				virtual long Lookup(HSTRING__ *,IInspectable * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual long Remove(HSTRING__ *);
				virtual long add_MapChanged(Foundation::Collections::MapChangedEventHandler<HSTRING__ *,IInspectable *> *,EventRegistrationToken *);
				virtual long get_Size(unsigned int *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct PasswordCredentialPropertyStoreActivationFactory
			{
				virtual long ActivateInstance(IInspectable * *);
			};

			Microsoft::WRL::Details::CreatorMap const __object_CPasswordCredential;
			Microsoft::WRL::Details::CreatorMap const __object_CPasswordVault;
			Microsoft::WRL::Details::CreatorMap const __object_CWebAccount;
			Microsoft::WRL::Details::CreatorMap const __object_CWebAccountProvider;
			Microsoft::WRL::Details::CreatorMap const __object_CWebAccountProvider_COM;
			Microsoft::WRL::Details::CreatorMap const __object_CWebAccount_COM;
			Microsoft::WRL::Details::FactoryCache __objectFactory__CPasswordCredential;
			Microsoft::WRL::Details::FactoryCache __objectFactory__CPasswordVault;
			Microsoft::WRL::Details::FactoryCache __objectFactory__CWebAccount;
			Microsoft::WRL::Details::FactoryCache __objectFactory__CWebAccountProvider;
			Microsoft::WRL::Details::FactoryCache __objectFactory__CWebAccountProvider_COM;
			Microsoft::WRL::Details::FactoryCache __objectFactory__CWebAccount_COM;
			unsigned short const * const SignOutAccountAsyncActionName;
		};

	};

};

namespace XWinRT
{
	struct AutoValue<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> >
	{
		AutoValue<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> ><HSTRING__ *>(HSTRING__ * const &,long *);
	};

	struct AutoValue<Windows::Security::Credentials::IPasswordCredential *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *> >
	{
		~AutoValue<Windows::Security::Credentials::IPasswordCredential *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *> >();
	};

	struct AutoValue<detail::GitStorageType<Windows::Security::Credentials::IPasswordCredential>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *> >
	{
		AutoValue<detail::GitStorageType<Windows::Security::Credentials::IPasswordCredential>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *> ><Windows::Security::Credentials::IPasswordCredential *>(Windows::Security::Credentials::IPasswordCredential * const &,long *);
		~AutoValue<detail::GitStorageType<Windows::Security::Credentials::IPasswordCredential>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *> >();
	};

	struct ComLock
	{
		ComLock(bool);
	};

	namespace FakeStl
	{
		void swap<XHashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> > >(XHashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> > &,XHashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> > &);
	};

	struct InterfaceEquals
	{
		long operator()<Windows::Security::Credentials::IPasswordCredential>(Windows::Security::Credentials::IPasswordCredential *,Windows::Security::Credentials::IPasswordCredential *,bool *);
	};

	struct InterfaceLifetimeTraits
	{
		static long Construct<Windows::Security::Credentials::IPasswordCredential>(detail::GitStorageType<Windows::Security::Credentials::IPasswordCredential> *,detail::GitStorageType<Windows::Security::Credentials::IPasswordCredential>);
		static void Destroy<Windows::Security::Credentials::IPasswordCredential>(Windows::Security::Credentials::IPasswordCredential * *);
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

	class XHashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >
	{
		long FreeNode(XHashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode *);
		long GetNode(HSTRING__ * const &,unsigned int &,unsigned int &,XHashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode * &,XHashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CNode * *);
		unsigned int PickSize(unsigned __int64);
		void FreePlexes();
		void UpdateRehashThresholds();
	public:
		TXPOSITION * GetStartPosition();
		XHashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >(void *,unsigned int,float,float,float,unsigned int);
		long InitHashTable(unsigned int,bool,bool *);
		long Lookup(HSTRING__ * const &,XHashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::HashMap<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultHash<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::HashMapOptions<HSTRING__ *,HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0,1,0> >::KeyTraits,CElementTraits<HSTRING__ *> >::CPair * *);
		long Rehash(unsigned int);
		long RemoveAll();
		long RemoveAtPos(TXPOSITION *);
	};

	namespace detail
	{
		struct AbiReference<Windows::Security::Credentials::IPasswordCredential *,GitStorageType<Windows::Security::Credentials::IPasswordCredential>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *> >
		{
			~AbiReference<Windows::Security::Credentials::IPasswordCredential *,GitStorageType<Windows::Security::Credentials::IPasswordCredential>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *> >();
		};

		struct GitStorageType<Windows::Security::Credentials::IPasswordCredential>
		{
			struct ReferencedGitCookie
			{
				long Localize(Windows::Security::Credentials::IPasswordCredential * *);
				unsigned long Release();
			};

			GitStorageType<Windows::Security::Credentials::IPasswordCredential>();
			long Initialize(Windows::Security::Credentials::IPasswordCredential *);
		};

		struct LockHolder<ComLock,AcquireRead>
		{
			~LockHolder<ComLock,AcquireRead>();
		};

		struct LockHolder<ComLock,AcquireWrite>
		{
			~LockHolder<ComLock,AcquireWrite>();
		};

		struct LockHolder<SRWLock,AcquireWrite>
		{
			~LockHolder<SRWLock,AcquireWrite>();
		};

		struct PresentationReference<GitStorageType<Windows::Security::Credentials::IPasswordCredential>,Windows::Security::Credentials::IPasswordCredential *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *> >
		{
			PresentationReference<GitStorageType<Windows::Security::Credentials::IPasswordCredential>,Windows::Security::Credentials::IPasswordCredential *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Credentials::PasswordCredential *> >(GitStorageType<Windows::Security::Credentials::IPasswordCredential> const &,long *);
		};

		struct ReentrancyGuard<0>
		{
			ReentrancyGuard<0>(...);
		};

	};

};

struct exception
{
	exception(char const * const &);
	exception(char const * const &,int);
	exception(exception const &);
	virtual char const * what();
	virtual ~exception();
};

namespace std
{
	struct _Error_objects<int>
	{
		static _Generic_error_category _Generic_object;
		static _Iostream_error_category _Iostream_object;
		static _System_error_category _System_object;
	};

	struct _Generic_error_category
	{
		virtual basic_string<char,char_traits<char>,allocator<char> > message(int);
		virtual char const * name();
	};

	struct _Iostream_error_category
	{
		virtual basic_string<char,char_traits<char>,allocator<char> > message(int);
		virtual char const * name();
	};

	struct _System_error_category
	{
		virtual basic_string<char,char_traits<char>,allocator<char> > message(int);
		virtual char const * name();
		virtual error_condition default_error_condition(int);
	};

	struct bad_alloc
	{
		bad_alloc();
		bad_alloc(bad_alloc const &);
		virtual ~bad_alloc();
	};

	struct basic_string<char,char_traits<char>,allocator<char> >
	{
		basic_string<char,char_traits<char>,allocator<char> > & assign(basic_string<char,char_traits<char>,allocator<char> > const &,unsigned __int64,unsigned __int64);
		basic_string<char,char_traits<char>,allocator<char> > & assign(char const *,unsigned __int64);
		basic_string<char,char_traits<char>,allocator<char> > & erase(unsigned __int64,unsigned __int64);
		void _Copy(unsigned __int64,unsigned __int64);
		void _Tidy(bool,unsigned __int64);
		void _Xlen();
		void _Xran();
	};

	struct error_category
	{
		virtual bool equivalent(error_code const &,int);
		virtual bool equivalent(int,error_condition const &);
		virtual error_condition default_error_condition(int);
	};

	struct length_error
	{
		length_error(char const *);
		length_error(length_error const &);
		virtual ~length_error();
	};

	struct logic_error
	{
		logic_error(logic_error const &);
	};

	struct num_put<char,back_insert_iterator<basic_string<char,char_traits<char>,allocator<char> > > >
	{
		static locale::id id;
	};

	struct num_put<wchar_t,back_insert_iterator<basic_string<wchar_t,char_traits<wchar_t>,allocator<wchar_t> > > >
	{
		static locale::id id;
	};

	struct numpunct<char>
	{
		static locale::id id;
	};

	struct numpunct<wchar_t>
	{
		static locale::id id;
	};

	struct out_of_range
	{
		out_of_range(char const *);
		out_of_range(out_of_range const &);
		virtual ~out_of_range();
	};

	char const * _Syserror_map(int);
	char const * _Winerror_map(int);
	nothrow_t const std::nothrow;
	void _Xbad_alloc();
	void _Xlength_error(char const *);
	void _Xout_of_range(char const *);
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
		namespace in1diag3
		{
			void Return_Hr(void *,unsigned int,char const *,long);
			void Return_Hr_NoOriginate(void *,unsigned int,char const *,long);
			void _FailFastImmediate_Unexpected();
		};

		class shared_buffer
		{
			void assign(long *,unsigned __int64);
		public:
			bool create(void const *,unsigned __int64);
			void reset();
		};

		bool GetModuleInformation(void *,unsigned int *,char *,unsigned __int64);
		bool g_resultMessageCallbackSet;
		char const * (* g_pfnGetModuleName)();
		char const * GetCurrentModuleName();
		int RecordException(long);
		int RecordFailFast(long);
		int RecordLog(long);
		int RecordReturn(long);
		long StringCchPrintfA(char *,unsigned __int64,char const *,...);
		unsigned __int64 ResultStringSize(char const *);
		unsigned __int64 ResultStringSize(unsigned short const *);
		unsigned char * WriteResultString<char const *>(unsigned char *,unsigned char *,char const *,char const * *);
		unsigned char * WriteResultString<unsigned short const *>(unsigned char *,unsigned char *,unsigned short const *,unsigned short const * *);
		unsigned short * LogStringPrintf(unsigned short *,unsigned short const *,unsigned short const *,...);
		void (* g_pfnDebugBreak)();
		void (* g_pfnGetContextAndNotifyFailure)(FailureInfo *,char *,unsigned __int64);
		void (* g_pfnLoggingCallback)(FailureInfo const &);
		void (* g_pfnOriginateCallback)(FailureType,long);
		void (* g_pfnRethrow)();
		void (* g_pfnThrowResultException)(FailureInfo const &);
		void DebugBreak();
		void LogFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,unsigned short const *,bool,unsigned short *,unsigned __int64,char *,unsigned __int64,FailureInfo *);
		void ReportFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,unsigned short const *,details::ReportFailureOptions);
		void ReportFailure_Hr(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long);
		void Rethrow();
		void ThrowResultExceptionInternal(FailureInfo const &);
	};

	bool (* g_pfnIsDebuggerPresent)();
	bool g_fBreakOnFailure;
	bool g_fIsDebuggerPresent;
	long GetFailureLogString(unsigned short *,unsigned __int64,wil::FailureInfo const &);
};

HINSTANCE__ * g_hModuleHandle;
Microsoft::WRL::Details::CreatorMap const __object_PasswordCredentialPropertyStore;
Microsoft::WRL::Details::FactoryCache __objectFactory__PasswordCredentialPropertyStore;
_GUID const GUID_CAUSALITY_WINDOWS_PLATFORM_ID;
_MIDL_STUBLESS_PROXY_INFO const Vault_ProxyInfo;
_MIDL_STUB_DESC const Vault_StubDesc;
_NDR64_CONFORMANT_STRING_FORMAT const __midl_frag196;
_NDR64_CONTEXT_HANDLE_FORMAT const __midl_frag122;
_NDR64_CONTEXT_HANDLE_FORMAT const __midl_frag127;
_NDR64_CONTEXT_HANDLE_FORMAT const __midl_frag131;
_NDR64_POINTER_FORMAT const __midl_frag100;
_NDR64_POINTER_FORMAT const __midl_frag107;
_NDR64_POINTER_FORMAT const __midl_frag108;
_NDR64_POINTER_FORMAT const __midl_frag169;
_NDR64_POINTER_FORMAT const __midl_frag170;
_NDR64_POINTER_FORMAT const __midl_frag174;
_NDR64_POINTER_FORMAT const __midl_frag194;
_NDR64_POINTER_FORMAT const __midl_frag195;
_NDR64_POINTER_FORMAT const __midl_frag32;
_NDR64_POINTER_FORMAT const __midl_frag51;
_NDR64_POINTER_FORMAT const __midl_frag57;
_NDR64_POINTER_FORMAT const __midl_frag99;
_NDR64_TYPE_STRICT_CONTEXT_HANDLE const __midl_frag123;
_NDR64_TYPE_STRICT_CONTEXT_HANDLE const __midl_frag128;
_NDR64_TYPE_STRICT_CONTEXT_HANDLE const __midl_frag132;
_Vault_MIDL_PROC_FORMAT_STRING const Vault__MIDL_ProcFormatString;
_Vault_MIDL_TYPE_FORMAT_STRING const Vault__MIDL_TypeFormatString;
__midl_frag102_t const __midl_frag102;
__midl_frag10_t const __midl_frag10;
__midl_frag111_t const __midl_frag111;
__midl_frag118_t const __midl_frag118;
__midl_frag11_t const __midl_frag11;
__midl_frag125_t const __midl_frag125;
__midl_frag12_t const __midl_frag12;
__midl_frag130_t const __midl_frag130;
__midl_frag135_t const __midl_frag135;
__midl_frag136_t const __midl_frag136;
__midl_frag137_t const __midl_frag137;
__midl_frag143_t const __midl_frag143;
__midl_frag146_t const __midl_frag146;
__midl_frag147_t const __midl_frag147;
__midl_frag149_t const __midl_frag149;
__midl_frag151_t const __midl_frag151;
__midl_frag154_t const __midl_frag154;
__midl_frag155_t const __midl_frag155;
__midl_frag156_t const __midl_frag156;
__midl_frag157_t const __midl_frag157;
__midl_frag159_t const __midl_frag159;
__midl_frag15_t const __midl_frag15;
__midl_frag160_t const __midl_frag160;
__midl_frag162_t const __midl_frag162;
__midl_frag163_t const __midl_frag163;
__midl_frag165_t const __midl_frag165;
__midl_frag172_t const __midl_frag172;
__midl_frag176_t const __midl_frag176;
__midl_frag181_t const __midl_frag181;
__midl_frag184_t const __midl_frag184;
__midl_frag20_t const __midl_frag20;
__midl_frag24_t const __midl_frag24;
__midl_frag25_t const __midl_frag25;
__midl_frag27_t const __midl_frag27;
__midl_frag29_t const __midl_frag29;
__midl_frag2_t const __midl_frag2;
__midl_frag33_t const __midl_frag33;
__midl_frag35_t const __midl_frag35;
__midl_frag36_t const __midl_frag36;
__midl_frag37_t const __midl_frag37;
__midl_frag46_t const __midl_frag46;
__midl_frag47_t const __midl_frag47;
__midl_frag50_t const __midl_frag50;
__midl_frag52_t const __midl_frag52;
__midl_frag54_t const __midl_frag54;
__midl_frag55_t const __midl_frag55;
__midl_frag56_t const __midl_frag56;
__midl_frag58_t const __midl_frag58;
__midl_frag59_t const __midl_frag59;
__midl_frag60_t const __midl_frag60;
__midl_frag68_t const __midl_frag68;
__midl_frag6_t const __midl_frag6;
__midl_frag76_t const __midl_frag76;
__midl_frag77_t const __midl_frag77;
__midl_frag80_t const __midl_frag80;
__midl_frag81_t const __midl_frag81;
__midl_frag82_t const __midl_frag82;
__midl_frag84_t const __midl_frag84;
__midl_frag8_t const __midl_frag8;
__midl_frag90_t const __midl_frag90;
__midl_frag9_t const __midl_frag9;
int InlineIsEqualGUID(_GUID const &,_GUID const &);
long StringCchCopyA(char *,unsigned __int64,char const *);
long StringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long VaultBind(void * *);
unsigned char const __midl_frag161;
unsigned char const __midl_frag198;
unsigned char const __midl_frag40;
unsigned char const __midl_frag43;
unsigned char const __midl_frag97;
unsigned long ApplySettingUnit(unsigned short const *,_SETTING_UNIT *);
unsigned long DuplicateString(unsigned short const *,unsigned short * *);
unsigned long GetSettingUnit(unsigned short const *,unsigned short const *,_SETTING_UNIT * *);
unsigned long GetSettingUnitInfo(unsigned short const *,unsigned short * *,unsigned short * *,unsigned short * *,_GUID *);
unsigned long GetSettingUnits(unsigned short const *,unsigned long *,_SETTING_UNIT * *);
unsigned long RemoveSettingUnit(unsigned short const *,unsigned short const *);
unsigned long TriggerSync(unsigned short const *);
unsigned long VaultLoadResource(HINSTANCE__ *,unsigned long,unsigned short * *,unsigned long *);
unsigned long VaultStartService();
unsigned short const * const InterfaceName_Windows_Foundation_IAsyncAction;
unsigned short const * const RuntimeClass_Windows_Foundation_Collections_PropertySet;
unsigned short const * const RuntimeClass_Windows_Foundation_Collections_ValueSet;
unsigned short const * const RuntimeClass_Windows_Foundation_Diagnostics_AsyncCausalityTracer;
unsigned short const * const RuntimeClass_Windows_Foundation_PropertyValue;
unsigned short const * const RuntimeClass_Windows_Foundation_Uri;
unsigned short const * const RuntimeClass_Windows_Internal_Security_Authentication_Web_TokenBrokerInternal;
unsigned short const * const RuntimeClass_Windows_Internal_Security_Credentials_WebAccountInternal;
unsigned short const * const RuntimeClass_Windows_Internal_Security_Credentials_WebAccountProviderInternal;
unsigned short const * const RuntimeClass_Windows_Security_Credentials_PasswordCredential;
unsigned short const * const RuntimeClass_Windows_Security_Credentials_PasswordCredentialPropertyStore;
unsigned short const * const RuntimeClass_Windows_Security_Credentials_PasswordVault;
unsigned short const * const RuntimeClass_Windows_Security_Credentials_WebAccount;
unsigned short const * const RuntimeClass_Windows_Security_Credentials_WebAccountProvider;
unsigned short const * const RuntimeClass_Windows_Storage_Streams_DataReader;
unsigned short const * const RuntimeClass_Windows_Storage_Streams_DataWriter;
unsigned short const * const RuntimeClass_Windows_System_Internal_UserManager;
void * _DuplicateMyProcessHandleForTokenBroker(Windows::Internal::Security::Authentication::Web::ITokenBrokerInternalStatics *);
void * operator new(unsigned __int64);
void * operator new(unsigned __int64,std::nothrow_t const &);
void * operator new[](unsigned __int64,std::nothrow_t const &);
void FreeSettingUnits(unsigned long,_SETTING_UNIT *);
void VaultFree<_VAULT_ITEM>(_VAULT_ITEM *);
void VaultFreeInternal(unsigned char *);
void VaultUnbind(void * *);
void VaultWinRTOriginateError(long,int);
void operator delete(void *);
void operator delete[](void *);
void operator delete[](void *,std::nothrow_t const &);
