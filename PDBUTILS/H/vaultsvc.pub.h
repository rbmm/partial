namespace Appx
{
	namespace Internal
	{
		long GetAcquisitionInfoGUIDValue(Common::RegistryKey *,unsigned short const *,_GUID *);
		long GetAcquisitionInfoStringValue(Common::RegistryKey *,unsigned short const *,unsigned short *,unsigned __int64 *);
	};

	long GetPackageAcquisitionInfoByFamilyName(unsigned short const *,unsigned short *,unsigned __int64 *,unsigned short *,unsigned __int64 *,unsigned short *,unsigned __int64 *,_GUID *);
};

struct CSqmCredentialsLogger
{
	void AddCredentialSize(_GUID *,unsigned long);
	void SubmitDatapoint();
};

class CUserVault
{
	unsigned long PersistUnlockState(unsigned char);
public:
	CUserVault(CUserVaultMgr *,IVaultStore *,efVaultFlags);
	static CUserVault * InstantiateUserVaultObject(CUserVaultMgr *,IVaultStore *,efVaultFlags);
	unsigned char IsBuiltinVault(_GUID *);
	unsigned char IsCredmanVault(_GUID *);
	unsigned long DecryptData(eVaultEncrypt,unsigned char *,unsigned long,unsigned char * *,unsigned long *);
	unsigned long EncryptData(eVaultEncrypt,unsigned char *,unsigned long,unsigned char,unsigned char * *,unsigned long *);
	unsigned long GetDefaultProtectionMethod(_GUID *);
	unsigned long GetVaultStore(IVaultStore * *,unsigned char);
	unsigned long InitVaultKey(CVaultKey *,CVaultKey *,IVaultKeyManager *);
	unsigned long UnlockVault(IVaultCall *,_GUID const *,_LUID *);
	virtual long Dereference();
	virtual long Reference();
	void RaiseRoamingNotification(unsigned char);
};

class CUserVaultMgr
{
	unsigned char IsRoamingProfilePath(unsigned short const *);
	unsigned long CreateBuiltinVault();
	unsigned long CreateOrReinitBuiltinVault(void *);
	unsigned long InitUserVault(IVaultStore *,CUserVault * *);
	unsigned long InitializeProfilePath(void *);
	unsigned long InsertVaultToStore(CUserVault *);
	unsigned long ReinitBuiltinVault();
public:
	CUserVaultMgr();
	unsigned long AddLoginSession(_LUID *,unsigned char);
	unsigned long CreateNewVault(_GUID const *,_GUID const *,unsigned short const *,unsigned short const *,eVaultType,efVaultFlags,VaultPolicy *,IVaultCall *,CUserVault * *);
	unsigned long EnumerateVaults(CUserVault * * *,unsigned long *);
	unsigned long GetCredmanVault(CUserVault * *);
	unsigned long GetDefaultVault(CUserVault * *);
	unsigned long GetVault(_GUID const *,CUserVault * *);
	unsigned long Initialize(void *,void *,_LUID *,unsigned char);
	unsigned long InitializeMgr();
	unsigned long LoadVaults(unsigned short const *,unsigned long);
	virtual long Dereference();
	virtual long Reference();
	void Delete();
	void DropLoginSession(_LUID *,unsigned char &);
	void RaiseRoamingNotification(unsigned char);
	~CUserVaultMgr();
};

class CVaultAPISqmLogger
{
	CVaultAPISqmLogger();
	virtual ~CVaultAPISqmLogger();
public:
	unsigned char Initialize();
	void LogDataPointToSqm(unsigned long,unsigned long);
	void ResetAllPoints();
};

struct CVaultAlgProvider
{
	unsigned long Initialize(unsigned char);
	virtual long Dereference();
	virtual long Reference();
	~CVaultAlgProvider();
};

struct CVaultAutoDecr
{
	~CVaultAutoDecr();
};

struct CVaultAutoPtr2<_SETTING_UNIT *,void>
{
	void Delete();
	~CVaultAutoPtr2<_SETTING_UNIT *,void>();
};

struct CVaultAutoPtr2<_VAULT_ITEM *,void>
{
	void Delete();
	~CVaultAutoPtr2<_VAULT_ITEM *,void>();
};

struct CVaultAutoPtr2<_VAULT_ITEM_ELEMENT *,void>
{
	void Delete();
	~CVaultAutoPtr2<_VAULT_ITEM_ELEMENT *,void>();
};

struct CVaultAutoPtr2<_VAULT_ITEM_SCHEMA *,void>
{
	void Delete();
	~CVaultAutoPtr2<_VAULT_ITEM_SCHEMA *,void>();
};

struct CVaultAutoPtr2<unsigned char *,void>
{
	void Delete();
	~CVaultAutoPtr2<unsigned char *,void>();
};

struct CVaultAutoPtr2<unsigned short *,void>
{
	~CVaultAutoPtr2<unsigned short *,void>();
};

struct CVaultAutoPtr<CUserVault *,void,CUserVault *,0>
{
	void Delete();
	~CVaultAutoPtr<CUserVault *,void,CUserVault *,0>();
};

struct CVaultAutoPtr<CUserVaultMgr *,void,CUserVaultMgr *,0>
{
	void Delete();
	~CVaultAutoPtr<CUserVaultMgr *,void,CUserVaultMgr *,0>();
};

struct CVaultAutoPtr<CVaultCredential *,void,CVaultCredential *,0>
{
	~CVaultAutoPtr<CVaultCredential *,void,CVaultCredential *,0>();
};

struct CVaultAutoPtr<CVaultFileStore *,void,CVaultFileStore *,0>
{
	void Delete();
	~CVaultAutoPtr<CVaultFileStore *,void,CVaultFileStore *,0>();
};

struct CVaultAutoPtr<CVaultRoamingCredential *,void,CVaultRoamingCredential *,0>
{
	void Delete();
	~CVaultAutoPtr<CVaultRoamingCredential *,void,CVaultRoamingCredential *,0>();
};

struct CVaultAutoPtr<CVaultRoamingNotification *,void,CVaultRoamingNotification *,0>
{
	void Delete();
	~CVaultAutoPtr<CVaultRoamingNotification *,void,CVaultRoamingNotification *,0>();
};

struct CVaultAutoPtr<CVaultSchema *,void,CVaultSchema *,0>
{
	~CVaultAutoPtr<CVaultSchema *,void,CVaultSchema *,0>();
};

struct CVaultAutoPtr<CVaultSecurable *,void,CVaultSecurable *,0>
{
	void Delete();
	~CVaultAutoPtr<CVaultSecurable *,void,CVaultSecurable *,0>();
};

struct CVaultAutoPtr<IVaultCredential * *,void,IVaultCredential * *,0>
{
	void Delete();
	~CVaultAutoPtr<IVaultCredential * *,void,IVaultCredential * *,0>();
};

struct CVaultAutoPtr<IVaultCredential *,void,IVaultCredential *,0>
{
	void Delete();
	~CVaultAutoPtr<IVaultCredential *,void,IVaultCredential *,0>();
};

struct CVaultAutoPtr<IVaultCredentialElement * *,void,IVaultCredentialElement * *,0>
{
	~CVaultAutoPtr<IVaultCredentialElement * *,void,IVaultCredentialElement * *,0>();
};

struct CVaultAutoPtr<IVaultFileSystem *,void,IVaultFileSystem *,0>
{
	~CVaultAutoPtr<IVaultFileSystem *,void,IVaultFileSystem *,0>();
};

struct CVaultAutoPtr<IVaultKeyManager *,void,IVaultKeyManager *,0>
{
	~CVaultAutoPtr<IVaultKeyManager *,void,IVaultKeyManager *,0>();
};

struct CVaultAutoPtr<IVaultRoamingCredential *,void,IVaultRoamingCredential *,0>
{
	~CVaultAutoPtr<IVaultRoamingCredential *,void,IVaultRoamingCredential *,0>();
};

struct CVaultAutoPtr<IVaultSchema *,void,IVaultSchema *,0>
{
	void Delete();
	~CVaultAutoPtr<IVaultSchema *,void,IVaultSchema *,0>();
};

struct CVaultAutoPtr<IVaultSchemaElement * *,void,IVaultSchemaElement * *,0>
{
	~CVaultAutoPtr<IVaultSchemaElement * *,void,IVaultSchemaElement * *,0>();
};

struct CVaultAutoPtr<IVaultSecurable *,void,IVaultSecurable *,0>
{
	~CVaultAutoPtr<IVaultSecurable *,void,IVaultSecurable *,0>();
};

struct CVaultAutoPtr<IVaultStore *,void,IVaultStore *,0>
{
	void Delete();
	~CVaultAutoPtr<IVaultStore *,void,IVaultStore *,0>();
};

struct CVaultAutoPtr<_CREDENTIALW * *,void,void *,0>
{
	~CVaultAutoPtr<_CREDENTIALW * *,void,void *,0>();
};

struct CVaultAutoPtr<_CREDENTIALW *,void,_CREDENTIALW *,0>
{
	void Delete();
	~CVaultAutoPtr<_CREDENTIALW *,void,_CREDENTIALW *,0>();
};

struct CVaultAutoPtr<_CREDENTIALW *,void,void *,0>
{
	~CVaultAutoPtr<_CREDENTIALW *,void,void *,0>();
};

struct CVaultAutoPtr<_GUID *,void,_GUID *,0>
{
	void Delete();
};

struct CVaultAutoPtr<_SidToVaultMapping *,void,_SidToVaultMapping *,0>
{
	~CVaultAutoPtr<_SidToVaultMapping *,void,_SidToVaultMapping *,0>();
};

struct CVaultAutoPtr<_VAULT_ITEM_ELEMENT *,void,_VAULT_ITEM_ELEMENT *,0>
{
	~CVaultAutoPtr<_VAULT_ITEM_ELEMENT *,void,_VAULT_ITEM_ELEMENT *,0>();
};

struct CVaultAutoPtr<_VAULT_ITEM_SCHEMA *,void,_VAULT_ITEM_SCHEMA *,0>
{
	void Delete();
};

struct CVaultAutoPtr<unsigned char *,void,unsigned char *,0>
{
	~CVaultAutoPtr<unsigned char *,void,unsigned char *,0>();
};

struct CVaultAutoPtr<unsigned short *,void,unsigned short *,0>
{
	void Delete();
	~CVaultAutoPtr<unsigned short *,void,unsigned short *,0>();
};

struct CVaultAutoPtr<void *,int,void *,0>
{
	void Delete();
	~CVaultAutoPtr<void *,int,void *,0>();
};

struct CVaultAutoSecureFree<unsigned char *,void>
{
	~CVaultAutoSecureFree<unsigned char *,void>();
};

struct CVaultCall
{
	virtual HWND__ * GetOwnerWindow();
	virtual eConfirmActionType GetConfirmActionType();
	virtual unsigned char IsUIAllowed();
	virtual void SetConfirmActionType(eConfirmActionType);
	virtual ~CVaultCall();
};

class CVaultConfiguration
{
	static CVaultConfiguration m_vaultConfig;
	static CVaultConfiguration::_DWORDCfgValue const * const x_cfgValues;
public:
	static void ReadConfiguration(VaultConfigType);
};

struct CVaultCredDataMap
{
	CVaultCredDataMap();
	CVaultCredDataMap(unsigned long);
	unsigned long DeserializeData(unsigned char *,unsigned long);
	unsigned long LookupDataForId(VAULT_SCHEMA_ELEMENT_ID,_VAULT_CAUB *);
	unsigned long SerializeData(unsigned char * *,unsigned long *);
	unsigned long SetCredData(VAULT_SCHEMA_ELEMENT_ID,_VAULT_CAUB *);
	~CVaultCredDataMap();
};

struct CVaultCredElement
{
	static unsigned long ComputeCredProperties(IVaultSchemaElement *,VAULT_ELEMENT_TYPE,eCredProperties *);
	static unsigned long CreateCredElement(CVaultCredElement * *);
	static unsigned long CreateCredElement(IVaultSchemaElement *,CVaultCredDataMap *,IVaultCredentialElement *,CVaultCredElement * *);
	static unsigned long ValidateCredentialElement(IVaultSchemaElement *,IVaultCredentialElement *);
	static void FreeCredElement(CVaultCredElement *);
	unsigned long ConstructCredentialElement(IVaultSchemaElement *,CVaultCredDataMap *,IVaultCredentialElement *);
	unsigned long ConstructCredentialElement(IVaultSchemaElement *,_VAULT_VARIANT *);
	unsigned long DeserializeCredentialElement(unsigned char *,unsigned long,unsigned long *);
	unsigned long SerializeCredentialElement(unsigned char *,unsigned long,unsigned long *);
	virtual VAULT_ELEMENT_TYPE GetElementType();
	virtual VAULT_ELEMENT_TYPE GetIElementItemType();
	virtual eCredProperties GetProtectionType();
	virtual unsigned long GetCredentialElementId(VAULT_SCHEMA_ELEMENT_ID *);
	virtual unsigned long GetRawData(unsigned char * *,unsigned long *,VAULT_ELEMENT_TYPE *);
};

class CVaultCredential
{
	static unsigned long VaultDeserializeCredElement(unsigned char * &,unsigned long &,IVaultSchema *,CVaultCredElement &);
	unsigned long DeserializeCredential(unsigned char *,unsigned long);
public:
	static unsigned long CreateNewCredential(IVaultSchema *,unsigned long,EVaultCredentialOrigin,CVaultCredential * *);
	static unsigned long Deserialize(IVaultSchema *,unsigned char *,unsigned long,CVaultCredential * *);
	static unsigned long InitializeInternalProperties(CVaultGenericPropertyCollection<ECredPropertyId,5> * *);
	unsigned long SerializeCredential(unsigned char * *,unsigned long *);
	unsigned long SetAndTakeOwnershipInternalProperties(void *);
	virtual IVaultCredentialElement * GetAuthenticatorCredentialElement();
	virtual IVaultCredentialElement * GetCredentialElement(VAULT_SCHEMA_ELEMENT_ID);
	virtual IVaultCredentialElement * GetIdentityCredentialElement();
	virtual IVaultCredentialElement * GetPropertyElement(VAULT_SCHEMA_ELEMENT_ID);
	virtual IVaultCredentialElement * GetResourceCredentialElement();
	virtual IVaultSecurable * GetVaultSecurable();
	virtual _FILETIME GetLastModifiedTime();
	virtual efCredFlags GetCredFlags();
	virtual long Dereference();
	virtual long Reference();
	virtual unsigned long EnumeratePropertyElements(IVaultCredentialElement * * *,unsigned long *);
	virtual unsigned long GetAccountId(IVaultAllocator *,unsigned short * *);
	virtual unsigned long GetAuthorityId(IVaultAllocator *,unsigned short * *);
	virtual unsigned long GetCredentialIdLenCb();
	virtual unsigned long GetIntegrityLevel();
	virtual unsigned long GetProtectedBlob(unsigned char * *,unsigned long *);
	virtual unsigned long GetProviderGuid(_GUID *);
	virtual unsigned long GetProviderId(IVaultAllocator *,unsigned short * *);
	virtual unsigned long GetRoamingVersion();
	virtual unsigned long GetSchemaId(_GUID *);
	virtual unsigned long IsRoaming(int *);
	virtual unsigned long SetAccountId(unsigned short const *);
	virtual unsigned long SetAuthenticatorElement(IVaultSchemaElement *,_VAULT_VARIANT *);
	virtual unsigned long SetAuthorityId(unsigned short const *);
	virtual unsigned long SetCredentialElement(IVaultSchemaElement *,_VAULT_VARIANT *);
	virtual unsigned long SetCredentialId(unsigned short const *,unsigned long);
	virtual unsigned long SetFriendlyName(unsigned short *);
	virtual unsigned long SetIdentityElement(IVaultSchemaElement *,_VAULT_VARIANT *);
	virtual unsigned long SetPropertyElement(IVaultSchemaElement *,_VAULT_VARIANT *);
	virtual unsigned long SetProtectedBlob(unsigned char *,unsigned long);
	virtual unsigned long SetProviderGuid(_GUID const *);
	virtual unsigned long SetProviderId(unsigned short const *);
	virtual unsigned long SetResourceElement(IVaultSchemaElement *,_VAULT_VARIANT *);
	virtual unsigned long SetVaultSecurable(IVaultSecurable *);
	virtual unsigned short const * GetCredentialId();
	virtual unsigned short const * GetFriendlyName();
	virtual void SetCredFlags(efCredFlags);
	virtual void SetIntegrityLevel(unsigned long);
	virtual void SetLastModifiedTime(_FILETIME);
};

class CVaultCredmanStore
{
	unsigned long ConvertCredmanToVaultCredential(_CREDENTIALW *,IVaultCredential * *);
	unsigned long ConvertVaultToCredmanCredential(IVaultCredential *,_CREDENTIALW * *);
	unsigned long CreateSspCredSchema(_GUID const *,unsigned short *);
	unsigned long InitializePolicy();
	unsigned long InternalSubmitSchemaToStore(IVaultSchema *);
public:
	static unsigned long ConstructCredmanStore(unsigned short const *,IVaultStore * *);
	unsigned long Initialize();
	virtual IVaultSecurable * GetVaultSecurable();
	virtual long Dereference();
	virtual long Reference();
	virtual unsigned long DeleteCredential(_GUID const *,_VAULT_ITEM_ELEMENT *,_VAULT_ITEM_ELEMENT *,_VAULT_ITEM_ELEMENT *);
	virtual unsigned long DeleteCredential(unsigned short const *);
	virtual unsigned long DeleteSchema(_GUID const *);
	virtual unsigned long EnumerateCredentials(unsigned long,int,IVaultCredential * * *,unsigned long *);
	virtual unsigned long GetCredFromUniqueId(unsigned short const *,IVaultCredential * *);
	virtual unsigned long GetFriendlyName(unsigned short * *);
	virtual unsigned long GetVaultId(_GUID *);
	virtual unsigned long GetVaultProtectedKeyData(unsigned char * *,unsigned long *);
	virtual unsigned long QueryCredentials(VAULT_SCHEMA_ELEMENT_ID,unsigned char *,unsigned long,unsigned long,IVaultCredential * * *,unsigned long *);
	virtual unsigned long SetVaultProtectedKeyData(unsigned char *,unsigned long);
	virtual unsigned long SubmitCredentialToStore(IVaultCredential *,unsigned short *,int);
	virtual unsigned long SubmitSchemaToStore(IVaultSchema *);
	virtual unsigned long UpdateVaultPolicy(eVaultPolicyType,unsigned char);
	virtual unsigned short * GetVaultLocation();
	virtual ~CVaultCredmanStore();
};

class CVaultCryptoProvider
{
	void Delete();
public:
	unsigned long ExportKey(void *,unsigned char *,unsigned long *);
	unsigned long GenerateKeyMaterial(unsigned char *,unsigned long,void * *,unsigned char * *,unsigned long *);
	unsigned long GenerateRandom(unsigned char *,unsigned long);
	unsigned long ImportKey(unsigned char *,unsigned long,unsigned char * *,unsigned long *,void * *);
	unsigned long Initialize();
	virtual long Dereference();
	virtual long Reference();
};

struct CVaultDpapiKeyManager
{
	virtual _GUID GetProtectionId();
	virtual long Dereference();
	virtual long Reference();
	virtual unsigned long ProtectData(unsigned char *,unsigned long,unsigned char * *,unsigned long *);
	virtual unsigned long UnprotectData(unsigned char *,unsigned long,unsigned char * *,unsigned long *,_VAULT_VARIANT *,_VAULT_VARIANT *);
	virtual unsigned long UpdateProtectData(IVaultCall *,_GUID const *,unsigned short const *,unsigned char *,unsigned long,unsigned char * *,unsigned long *);
};

class CVaultFactory
{
	unsigned long ConstructStoreArrayAndFreeList(std::list<IVaultStore *,std::allocator<IVaultStore *> > *,unsigned char,IVaultStore * * *,unsigned long *);
public:
	unsigned long CreateVaultFileSystem(eFileSystemType,IVaultFileSystem * *);
	virtual unsigned long CreateNewCredential(IVaultSchema *,unsigned long,EVaultCredentialOrigin,IVaultCredential * *);
	virtual unsigned long CreateNewSchema(_GUID const *,efSchemaProperties,unsigned long,IVaultSchema * *);
	virtual unsigned long CreateNewVault(_GUID const *,unsigned char *,unsigned long,unsigned short const *,unsigned char,unsigned short const *,eVaultType,VaultPolicy *,IVaultStore * *);
	virtual unsigned long CreateVaultKeyManager(_GUID const *,IVaultKeyManager * *);
	virtual unsigned long EnumerateVaultStore(unsigned short const *,unsigned char,IVaultStore * * *,unsigned long *);
};

class CVaultFileStore
{
	CVaultFileStore();
	unsigned long InitializeOrDeleteSchema(unsigned char,IVaultFileSystem *);
	unsigned long InitializePolicy();
	unsigned long InitializeVaultStorePath(unsigned short const *);
	unsigned long LoadCredentialFile(unsigned short const *,CSqmCredentialsLogger *);
	unsigned long LoadCredentials();
	unsigned long LoadSchemaFile(unsigned short const *);
	unsigned long SubmitPolicyToStore(IVaultFileSystem *);
public:
	static unsigned long ConstructFileStore(unsigned short const *,unsigned char,IVaultStore * *);
	static unsigned long CreateNewVault(_GUID const *,unsigned char *,unsigned long,unsigned short const *,unsigned char,unsigned short const *,eVaultType,VaultPolicy *,CVaultFileStore * *);
	unsigned long Initialize();
	virtual long Dereference();
	virtual long Reference();
	virtual unsigned long DeleteCredential(unsigned short const *);
	virtual unsigned long DeleteSchema(_GUID const *);
	virtual unsigned long GetFriendlyName(unsigned short * *);
	virtual unsigned long SetVaultInformation(VaultPolicy *);
	virtual unsigned long SetVaultProtectedKeyData(unsigned char *,unsigned long);
	virtual unsigned long SubmitCredentialToStore(IVaultCredential *,unsigned short *,int);
	virtual unsigned long SubmitSchemaToStore(IVaultSchema *);
	virtual unsigned long UpdateVaultPolicy(eVaultPolicyType,unsigned char);
	virtual unsigned short * GetVaultLocation();
};

class CVaultGlobalSchemaMgr
{
	unsigned long CreateGlobalSchemaVault(unsigned short const *);
	unsigned long CreateGlobalSchemas();
	unsigned long CreateSecureNoteSchema(IVaultStore *,IVaultFactory *);
	unsigned long CreateWebPasswordSchema(IVaultStore *,IVaultFactory *);
	unsigned long CreateWebProtectorSchema(IVaultStore *,IVaultFactory *);
public:
	unsigned long LoadGlobalSchemaVault();
	void UnloadGlobalSchemaVault();
};

struct CVaultHeapAllocator
{
	CVaultHeapAllocator();
	virtual unsigned char * Alloc(unsigned __int64);
	virtual void Free(void *);
};

struct CVaultIntegrityLevel
{
	unsigned long Elevate();
	~CVaultIntegrityLevel();
};

class CVaultKey
{
	unsigned long AssociateCryptoProviderWithAlg(eVaultProtectionAlg);
public:
	CVaultKey(eVaultProtectionAlg,void *);
	unsigned long DecryptData(unsigned char *,unsigned long,unsigned char *,unsigned long *);
	unsigned long DeserializeKeyBlob(unsigned char *,unsigned long);
	unsigned long EncryptData(unsigned char *,unsigned long,unsigned char,unsigned char *,unsigned long *);
	unsigned long GenerateVaultKeyMaterial();
	unsigned long SerializeKeyBlob(unsigned char *,unsigned long *);
	void Delete();
	~CVaultKey();
};

class CVaultKeyStoreMgr
{
	unsigned long SerializeVaultKeyMaterial(CVaultKey *,CVaultKey *,unsigned char * *,unsigned long *);
public:
	CVaultKeyStoreMgr(IVaultStore *);
	unsigned long DeserializeAndGetProtectedKeyMaterial(_GUID const *,unsigned char * *,unsigned long *,_GUID *);
	unsigned long DeserializeVaultKeyMaterial(unsigned char *,unsigned long,CVaultKey *,CVaultKey *);
	unsigned long GetDefaultProtectionMethod(_GUID *);
	unsigned long SerializeAndProtectKeyMaterial(CUserVault *,IVaultKeyManager *,CVaultKey *,CVaultKey *,unsigned char * *,unsigned long *);
	~CVaultKeyStoreMgr();
};

class CVaultMemoryStore
{
	static CVaultFactory sm_VaultFactory;
protected:
	CVaultMemoryStore();
	unsigned long CreatePolicy(_GUID const *,unsigned char *,unsigned long,unsigned short const *,eVaultType,VaultPolicy *);
	unsigned long InitializeStore();
	unsigned long IsSchemaReferenced(_GUID const *,EVaultSecurableAction,unsigned char *);
	unsigned long SubmitCredentialToStoreNoAlloc(IVaultCredential *,unsigned short *);
	unsigned long UpdateCredCountPerAppContainer(void *,int);
	void Delete(unsigned char);
public:
	virtual IVaultSecurable * GetVaultSecurable();
	virtual long Dereference();
	virtual long Reference();
	virtual unsigned long DeleteCredential(_GUID const *,_VAULT_ITEM_ELEMENT *,_VAULT_ITEM_ELEMENT *,_VAULT_ITEM_ELEMENT *);
	virtual unsigned long DeleteCredential(unsigned short const *);
	virtual unsigned long DeleteSchema(_GUID const *);
	virtual unsigned long EnumerateCredentials(unsigned long,int,IVaultCredential * * *,unsigned long *);
	virtual unsigned long EnumerateSchema(int,IVaultSchema * * *,unsigned long *);
	virtual unsigned long GetCredFromUniqueId(unsigned short const *,IVaultCredential * *);
	virtual unsigned long GetCredentialCount(int);
	virtual unsigned long GetCredentialCountForAppContainer(void *);
	virtual unsigned long GetFriendlyName(unsigned short * *);
	virtual unsigned long GetSchemaCount();
	virtual unsigned long GetVaultId(_GUID *);
	virtual unsigned long GetVaultInformation(eVaultType *,VaultPolicy *);
	virtual unsigned long GetVaultProtectedKeyData(unsigned char * *,unsigned long *);
	virtual unsigned long GetVaultSchema(_GUID const *,IVaultSchema * *);
	virtual unsigned long QueryCredentials(VAULT_SCHEMA_ELEMENT_ID,unsigned char *,unsigned long,unsigned long,IVaultCredential * * *,unsigned long *);
	virtual unsigned long SetVaultInformation(VaultPolicy *);
	virtual unsigned long SetVaultProtectedKeyData(unsigned char *,unsigned long);
	virtual unsigned long SubmitCredentialToStore(IVaultCredential *,unsigned short *,int);
	virtual unsigned long SubmitSchemaToStore(IVaultSchema *);
	virtual unsigned long UpdateVaultPolicy(eVaultPolicyType,unsigned char);
	virtual unsigned short * GetVaultLocation();
	virtual void GetVaultFactory(IVaultFactory * *);
	virtual void LockStore(unsigned char);
	virtual void UnlockStore();
	virtual ~CVaultMemoryStore();
};

class CVaultMgr
{
	unsigned long GetSidHashId(void *,unsigned long *);
	void DeleteAllEntries();
public:
	CVaultMgr();
	unsigned long CreateUserVaultManager(void *,_LUID *,CUserVaultMgr * *);
	unsigned long DeleteUserVaultManager(void *);
	unsigned long GetUserVaultManager(unsigned char,CUserVaultMgr * *,unsigned char * const,_LUID *,unsigned long *,void * *);
	unsigned long Initialize();
	void Uninitialize();
	~CVaultMgr();
};

struct CVaultNonTransacted
{
	virtual long Dereference();
	virtual long Reference();
	virtual unsigned long FileOperationsCreateDirectory(unsigned short const *);
	virtual unsigned long FileOperationsCreateFile(unsigned short const *,unsigned long,eWriteMode,void * *);
	virtual unsigned long FileOperationsDeleteAllFiles(unsigned short const *);
	virtual unsigned long FileOperationsDeleteDirectory(unsigned short const *);
	virtual unsigned long FileOperationsDeleteFile(unsigned short const *);
	virtual unsigned long FileOperationsMoveFile(unsigned short *,unsigned short *);
	virtual unsigned long FileOperationsStart();
	virtual unsigned long FileOperationsSubmit();
};

struct CVaultPackageId
{
	CVaultPackageId(void * const);
	unsigned long ComposeSid(CVaultSid * *);
};

class CVaultPolicy
{
	unsigned long ComputeSerializeLen();
public:
	unsigned long DeserializePolicy(unsigned char *,unsigned long);
	unsigned long GetVaultName(unsigned short * *);
	unsigned long SerializePolicy(unsigned char * *,unsigned long *);
	unsigned long SetProtectionBuffer(unsigned char *,unsigned long);
	unsigned long SetVaultName(unsigned short const *);
	virtual ~CVaultPolicy();
};

class CVaultRoamingCredential
{
	static unsigned long CheckRoamingUnitElementsCount(unsigned long,unsigned long,unsigned long,int);
	static unsigned long DeserializeCredElement(unsigned char * &,unsigned long &,IVaultSchema *,CVaultCredElement * *);
	unsigned long DeserializeCredProperties(unsigned char * &,unsigned long &,IVaultSchema *);
	unsigned long DeserializeNumberOfElements(unsigned long,unsigned char * &,unsigned long &);
	unsigned long DeserializeRoamingCredential(CUserVault *,unsigned char *,unsigned long);
	unsigned long DeserializeRoamingUnitFlags(unsigned char * &,unsigned long &);
	unsigned long DeserializeRoamingUnitSchema(unsigned char * &,unsigned long &);
	unsigned long SerializeRoamingCredential(IVaultAllocator *,unsigned char * *,unsigned long *);
	unsigned long ValidateSettingUnitHeader(_SETTING_UNIT *);
public:
	CVaultRoamingCredential();
	static void FreeRoamingCredential(CVaultRoamingCredential *);
	unsigned long InitializeFromSettingUnit(CUserVault *,_SETTING_UNIT *);
	unsigned long InitializeFromVaultCredential(CUserVault *,IVaultCredential *,unsigned char *,unsigned long);
	virtual _FILETIME GetLastModifiedTime();
	virtual _GUID * GetSchemaId();
	virtual _VAULT_ITEM_ELEMENT * GetAuthenticatorElement();
	virtual _VAULT_ITEM_ELEMENT * GetIdentityElement();
	virtual _VAULT_ITEM_ELEMENT * GetPropertyElementAt(unsigned long);
	virtual _VAULT_ITEM_ELEMENT * GetResourceElement();
	virtual efCredFlags GetCredFlags();
	virtual unsigned long GetCredentialIdLenCb();
	virtual unsigned long GetNumberOfElements();
	virtual unsigned long GetPropertiesCount();
	virtual unsigned long TransferInternalProperties(IVaultCredential *);
	virtual unsigned short const * GetCredentialId();
	virtual unsigned short const * GetFriendlyName();
	virtual ~CVaultRoamingCredential();
};

struct CVaultRoamingNotification
{
	static void FreeRoamingNotification(CVaultRoamingNotification *);
	unsigned long InitRoamingNotification(unsigned short const *);
	virtual void RaiseNotification(unsigned char);
	virtual void RaiseNotification2(unsigned char,unsigned char);
	virtual void RaisePendingNotifications();
};

struct CVaultRpcAllocator
{
	CVaultRpcAllocator();
	virtual unsigned char * Alloc(unsigned __int64);
	virtual void Free(void *);
};

struct CVaultRpcImpersonate
{
	unsigned long Impersonate(int);
	void UnImpersonate();
	~CVaultRpcImpersonate();
};

struct CVaultRtlLock
{
	CVaultRtlLock(_RTL_RESOURCE *,eVaultLock);
	~CVaultRtlLock();
};

class CVaultSchema
{
	unsigned long ComputeSerializeLen();
	unsigned long DeserializeSchema(unsigned char *,unsigned long);
public:
	CVaultSchema(_GUID const *,efSchemaProperties,unsigned long,unsigned char *);
	static unsigned long CreateNewSchemaInternal(_GUID const *,efSchemaProperties,unsigned long,int,CVaultSchema * *);
	static unsigned long Deserialize(unsigned char *,unsigned long,CVaultSchema * *);
	unsigned long SerializeSchema(unsigned char * *,unsigned long *);
	virtual IVaultSchemaElement * GetAuthenticatorSchemaElement();
	virtual IVaultSchemaElement * GetIdentitySchemaElement();
	virtual IVaultSchemaElement * GetPropertyElement(VAULT_SCHEMA_ELEMENT_ID);
	virtual IVaultSchemaElement * GetResourceSchemaElement();
	virtual IVaultSchemaElement * GetSchemaElement(VAULT_SCHEMA_ELEMENT_ID);
	virtual IVaultSecurable * GetVaultSecurable();
	virtual _GUID GetSchemaId();
	virtual efSchemaProperties GetSchemaProperties();
	virtual long Dereference();
	virtual long Reference();
	virtual unsigned long EnumeratePropertyElements(IVaultSchemaElement * * *,unsigned long *);
	virtual unsigned long GetNumberOfElements();
	virtual unsigned long GetPropertyElementCount();
	virtual unsigned long SetAuthenticatorElement(VAULT_ELEMENT_TYPE,VAULT_ELEMENT_PROTECTION);
	virtual unsigned long SetFriendlyName(unsigned short const *);
	virtual unsigned long SetIdentityElement(VAULT_ELEMENT_TYPE,VAULT_ELEMENT_PROTECTION,unsigned long);
	virtual unsigned long SetPropertyElement(VAULT_SCHEMA_ELEMENT_ID,VAULT_ELEMENT_TYPE,VAULT_ELEMENT_PROTECTION,unsigned long);
	virtual unsigned long SetResourceElement(VAULT_ELEMENT_TYPE,VAULT_ELEMENT_PROTECTION,unsigned long);
	virtual unsigned long SetSchemaElement(IVaultSchemaElement *);
	virtual unsigned short const * GetFriendlyName();
	virtual ~CVaultSchema();
};

struct CVaultSchemaElement
{
	unsigned long ConstructSchemaElement(VAULT_ELEMENT_TYPE,VAULT_ELEMENT_PROTECTION,unsigned long,VAULT_SCHEMA_ELEMENT_ID);
	virtual VAULT_ELEMENT_PROTECTION GetProtectionType();
	virtual VAULT_ELEMENT_TYPE GetElementType();
	virtual VAULT_SCHEMA_ELEMENT_ID GetSchemaElementId();
	virtual unsigned long GetElementFlags();
};

struct CVaultSecurable
{
	static void FreeVaultSecurable(CVaultSecurable *);
	unsigned long CreateSecurityDescriptor(CVaultSid *);
	virtual CVaultSid * GetPackageSid();
	virtual EVaultSecurableType GetSecurableType();
	virtual _GUID GetSecurableId();
	virtual void * GetSecurityDescriptor();
	virtual ~CVaultSecurable();
};

struct CVaultSid
{
	static unsigned long CreateVaultSid(void * const,CVaultSid * *);
	unsigned long InitializeVaultSid(void * const);
	virtual long Dereference();
	virtual long Reference();
};

struct CVaultStoreLock
{
	CVaultStoreLock(IVaultStore *,eVaultLock);
	void LockExclusive();
	void ReleaseLock();
	~CVaultStoreLock();
};

class CVaultSystemSecurable
{
	CVaultSystemSecurable();
	static CVaultSystemSecurable m_VaultSystem;
};

struct CVaultTransacted
{
	static unsigned long CreateNewFileSystem(IVaultFileSystem * *);
	virtual long Dereference();
	virtual long Reference();
	virtual unsigned long FileOperationsCreateDirectory(unsigned short const *);
	virtual unsigned long FileOperationsCreateFile(unsigned short const *,unsigned long,eWriteMode,void * *);
	virtual unsigned long FileOperationsDeleteAllFiles(unsigned short const *);
	virtual unsigned long FileOperationsDeleteDirectory(unsigned short const *);
	virtual unsigned long FileOperationsDeleteFile(unsigned short const *);
	virtual unsigned long FileOperationsMoveFile(unsigned short *,unsigned short *);
	virtual unsigned long FileOperationsStart();
	virtual unsigned long FileOperationsSubmit();
};

struct CaubCmp
{
	bool operator()(_VAULT_CAUB,_VAULT_CAUB);
};

namespace Common
{
	class Guid
	{
		static unsigned long GetHexByte(unsigned char const *);
		static unsigned short const * const char2valHi;
		static unsigned short const * const char2valLo;
	public:
		static long Decode(unsigned char const *,unsigned long,_GUID *);
		static long Decode(unsigned short const *,unsigned long,_GUID *);
	};

	struct RegistryKey
	{
		long GetStringValue(unsigned short const *,unsigned long,unsigned long *,unsigned short *,unsigned long *);
		~RegistryKey();
	};

};

struct FnTracer
{
	FnTracer(char *,unsigned long *);
	~FnTracer();
};

struct GuidCmp
{
	bool operator()(_GUID,_GUID);
};

struct IVaultCredential
{
	virtual ~IVaultCredential();
};

struct IVaultRoamingCredential
{
	static unsigned long CreateRoamingCredential(CUserVault *,_SETTING_UNIT *,IVaultRoamingCredential * *);
	static void FreeRoamingCredential(IVaultRoamingCredential *);
	virtual ~IVaultRoamingCredential();
};

struct IVaultRoamingNotification
{
	static unsigned long CreateRoamingNotification(unsigned short const *,IVaultRoamingNotification * *);
	static void FreeRoamingNotification(IVaultRoamingNotification *);
	virtual ~IVaultRoamingNotification();
};

struct IVaultSchema
{
	virtual ~IVaultSchema();
};

struct IVaultSecurable
{
	static void FreeVaultSecurable(IVaultSecurable *);
	virtual ~IVaultSecurable();
};

struct IVaultStore
{
	virtual ~IVaultStore();
};

namespace ReservedForLocalUse
{
	void * heap;
};

namespace Sharp
{
	namespace Util
	{
		class CClassLevelLockable<CVaultAPISqmLogger>
		{
			struct CLock
			{
				~CLock();
			};

			static CCriticalSection gm_criticalSection;
		};

		struct CCriticalSection
		{
			struct CLock
			{
				CLock(CCriticalSection &);
				~CLock();
			};

			CCriticalSection();
			~CCriticalSection();
		};

		struct CDefaultLifetime
		{
			static void OnDeadReference();
		};

		class CSingletonHolder<CVaultAPISqmLogger,CDefaultLifetime,CClassLevelLockable>
		{
			static CVaultAPISqmLogger * gm_pTheInstance;
			static bool gm_fDestroyed;
			static void CreateInstance();
			static void DestroySingleton();
		public:
			static CVaultAPISqmLogger & Instance();
		};

	};

};

namespace VaultCryptoGlobals
{
	CVaultAlgProvider g_VaultAesAlg;
	CVaultAlgProvider g_VaultRandAlg;
	CVaultCryptoProvider g_VaultAes128Provider;
	CVaultCryptoProvider g_VaultAes256Provider;
	unsigned long InitializeCrypto();
};

namespace VaultGlobals
{
	CVaultFactory g_VaultFactory;
	CVaultGlobalSchemaMgr g_GlobalSchemaMgr;
	CVaultHeapAllocator g_HeapAlloc;
	CVaultMgr g_VaultMgr;
	CVaultRpcAllocator g_RpcAlloc;
	HINSTANCE__ * g_hModuleHandle;
	eVaultEngineState g_eEngineState;
	int g_fDomainJoined;
	int g_fIsDC;
	unsigned char g_fRegisteredLogonSessCallback;
	unsigned short const * const g_pszDefaultVaultName;
	void * g_DomainSID;
	void * g_PrivAppSID;
};

struct exception
{
	exception(exception const &);
	virtual char const * what();
};

namespace std
{
	struct _String_base
	{
		static void _Xlen();
		static void _Xran();
	};

	class _Tree<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >
	{
	protected:
		_Tree<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::iterator _Insert(bool,_Tree_nod<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::_Node *,pair<_GUID const ,CUserVault *> const &);
		_Tree_nod<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::_Node * _Buynode();
		_Tree_nod<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::_Node * _Buynode(_Tree_nod<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::_Node *,_Tree_nod<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::_Node *,_Tree_nod<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::_Node *,pair<_GUID const ,CUserVault *> const &,char);
		void _Erase(_Tree_nod<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::_Node *);
		void _Lrotate(_Tree_nod<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::_Node *);
		void _Rrotate(_Tree_nod<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::_Node *);
	public:
		_Tree<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::iterator erase(_Tree<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::iterator);
		_Tree<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::iterator erase(_Tree<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::iterator,_Tree<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::iterator);
		_Tree<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::iterator find(_GUID const &);
		pair<_Tree<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::iterator,bool> insert(pair<_GUID const ,CUserVault *> const &);
		void clear();
		~_Tree<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >();
	};

	class _Tree<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >
	{
	protected:
		_Tree<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::iterator _Insert(bool,_Tree_nod<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::_Node *,pair<_GUID const ,IVaultSchema *> const &);
		_Tree_nod<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::_Node * _Buynode();
		_Tree_nod<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::_Node * _Buynode(_Tree_nod<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::_Node *,_Tree_nod<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::_Node *,_Tree_nod<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::_Node *,pair<_GUID const ,IVaultSchema *> const &,char);
		void _Erase(_Tree_nod<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::_Node *);
		void _Lrotate(_Tree_nod<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::_Node *);
		void _Rrotate(_Tree_nod<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::_Node *);
	public:
		_Tree<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::iterator erase(_Tree<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::iterator);
		_Tree<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::iterator erase(_Tree<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::iterator,_Tree<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::iterator);
		_Tree<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::iterator find(_GUID const &);
		pair<_Tree<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::iterator,bool> insert(pair<_GUID const ,IVaultSchema *> const &);
		void clear();
		~_Tree<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >();
	};

	class _Tree<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >
	{
	protected:
		_Tree_nod<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::_Node * _Buynode();
		_Tree_nod<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::_Node * _Buynode(_Tree_nod<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::_Node *,_Tree_nod<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::_Node *,_Tree_nod<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::_Node *,pair<_VAULT_CAUB const ,IVaultCredential *> const &,char);
		void _Erase(_Tree_nod<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::_Node *);
		void _Lrotate(_Tree_nod<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::_Node *);
		void _Rrotate(_Tree_nod<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::_Node *);
	public:
		_Tree<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::iterator erase(_Tree<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::iterator);
		_Tree<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::iterator erase(_Tree<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::iterator,_Tree<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::iterator);
		_Tree<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::iterator find(_VAULT_CAUB const &);
		pair<_Tree<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::iterator,bool> insert(pair<_VAULT_CAUB const ,IVaultCredential *> const &);
		~_Tree<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >();
	};

	class _Tree<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >
	{
	protected:
		_Tree<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::iterator _Insert(bool,_Tree_nod<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::_Node *,pair<_tagSIDArray const ,unsigned long> const &);
		_Tree_nod<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::_Node * _Buynode();
		_Tree_nod<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::_Node * _Buynode(_Tree_nod<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::_Node *,_Tree_nod<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::_Node *,_Tree_nod<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::_Node *,pair<_tagSIDArray const ,unsigned long> const &,char);
		void _Erase(_Tree_nod<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::_Node *);
		void _Lrotate(_Tree_nod<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::_Node *);
		void _Rrotate(_Tree_nod<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::_Node *);
	public:
		_Tree<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::iterator erase(_Tree<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::iterator);
		_Tree<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::iterator erase(_Tree<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::iterator,_Tree<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::iterator);
		pair<_Tree<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::iterator,bool> insert(pair<_tagSIDArray const ,unsigned long> const &);
		void clear();
		~_Tree<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >();
	};

	class _Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >
	{
	protected:
		_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator _Insert(bool,_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *,pair<unsigned long const ,SE> const &);
		_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node * _Buynode();
		_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node * _Buynode(_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *,_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *,_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *,pair<unsigned long const ,SE> const &,char);
		void _Erase(_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *);
		void _Lrotate(_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *);
		void _Rrotate(_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *);
	public:
		_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator erase(_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator);
		_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator erase(_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator,_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator);
		_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator insert(_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator,pair<unsigned long const ,SE> const &);
		pair<_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator,bool> insert(pair<unsigned long const ,SE> const &);
		~_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >();
	};

	struct allocator<_List_nod<IVaultCredential *,allocator<IVaultCredential *> >::_Node>
	{
		void deallocate(_List_nod<IVaultCredential *,allocator<IVaultCredential *> >::_Node *,unsigned __int64);
	};

	struct allocator<_List_nod<IVaultStore *,allocator<IVaultStore *> >::_Node>
	{
		void deallocate(_List_nod<IVaultStore *,allocator<IVaultStore *> >::_Node *,unsigned __int64);
	};

	struct allocator<_List_nod<_VAULT_ITEM,allocator<_VAULT_ITEM> >::_Node>
	{
		void deallocate(_List_nod<_VAULT_ITEM,allocator<_VAULT_ITEM> >::_Node *,unsigned __int64);
	};

	struct allocator<_Tree_nod<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::_Node>
	{
		void deallocate(_Tree_nod<_Tmap_traits<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> >,0> >::_Node *,unsigned __int64);
	};

	struct allocator<_Tree_nod<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::_Node>
	{
		void deallocate(_Tree_nod<_Tmap_traits<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> >,0> >::_Node *,unsigned __int64);
	};

	struct allocator<_Tree_nod<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::_Node>
	{
		void deallocate(_Tree_nod<_Tmap_traits<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> >,1> >::_Node *,unsigned __int64);
	};

	struct allocator<_Tree_nod<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::_Node>
	{
		void deallocate(_Tree_nod<_Tmap_traits<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> >,0> >::_Node *,unsigned __int64);
	};

	struct allocator<_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node>
	{
		void deallocate(_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *,unsigned __int64);
	};

	class bad_alloc
	{
	protected:
		virtual void _Doraise();
	public:
		bad_alloc(bad_alloc const &);
		bad_alloc(char const *);
		virtual ~bad_alloc();
	};

	class basic_string<char,char_traits<char>,allocator<char>,_STL70>
	{
	protected:
		bool _Grow(unsigned __int64,bool);
		bool _Inside(char const *);
		void _Copy(unsigned __int64,unsigned __int64);
		void _Tidy(bool,unsigned __int64);
	public:
		basic_string<char,char_traits<char>,allocator<char>,_STL70> & assign(basic_string<char,char_traits<char>,allocator<char>,_STL70> const &,unsigned __int64,unsigned __int64);
		basic_string<char,char_traits<char>,allocator<char>,_STL70> & assign(char const *,unsigned __int64);
		basic_string<char,char_traits<char>,allocator<char>,_STL70> & erase(unsigned __int64,unsigned __int64);
		basic_string<char,char_traits<char>,allocator<char>,_STL70>(basic_string<char,char_traits<char>,allocator<char>,_STL70> const &);
		basic_string<char,char_traits<char>,allocator<char>,_STL70>(char const *);
		~basic_string<char,char_traits<char>,allocator<char>,_STL70>();
	};

	class length_error
	{
	protected:
		virtual void _Doraise();
	public:
		length_error(basic_string<char,char_traits<char>,allocator<char>,_STL70> const &);
		length_error(length_error const &);
		virtual ~length_error();
	};

	class list<IVaultCredential *,allocator<IVaultCredential *> >
	{
	protected:
		_List_nod<IVaultCredential *,allocator<IVaultCredential *> >::_Node * _Buynode();
		_List_nod<IVaultCredential *,allocator<IVaultCredential *> >::_Node * _Buynode(_List_nod<IVaultCredential *,allocator<IVaultCredential *> >::_Node *,_List_nod<IVaultCredential *,allocator<IVaultCredential *> >::_Node *,IVaultCredential * const &);
	};

	class list<IVaultStore *,allocator<IVaultStore *> >
	{
	protected:
		_List_nod<IVaultStore *,allocator<IVaultStore *> >::_Node * _Buynode();
		_List_nod<IVaultStore *,allocator<IVaultStore *> >::_Node * _Buynode(_List_nod<IVaultStore *,allocator<IVaultStore *> >::_Node *,_List_nod<IVaultStore *,allocator<IVaultStore *> >::_Node *,IVaultStore * const &);
		void _Incsize(unsigned __int64);
	public:
		void clear();
	};

	class list<_VAULT_ITEM,allocator<_VAULT_ITEM> >
	{
	protected:
		_List_nod<_VAULT_ITEM,allocator<_VAULT_ITEM> >::_Node * _Buynode();
		_List_nod<_VAULT_ITEM,allocator<_VAULT_ITEM> >::_Node * _Buynode(_List_nod<_VAULT_ITEM,allocator<_VAULT_ITEM> >::_Node *,_List_nod<_VAULT_ITEM,allocator<_VAULT_ITEM> >::_Node *,_VAULT_ITEM const &);
		void _Incsize(unsigned __int64);
	public:
		void clear();
	};

	class logic_error
	{
	protected:
		virtual void _Doraise();
	public:
		logic_error(basic_string<char,char_traits<char>,allocator<char>,_STL70> const &);
		logic_error(logic_error const &);
		virtual char const * what();
		virtual ~logic_error();
	};

	struct map<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> > >
	{
		~map<_GUID,CUserVault *,GuidCmp,allocator<pair<_GUID const ,CUserVault *> > >();
	};

	struct map<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> > >
	{
		~map<_GUID,IVaultSchema *,GuidCmp,allocator<pair<_GUID const ,IVaultSchema *> > >();
	};

	struct map<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> > >
	{
		~map<_tagSIDArray,unsigned long,SidCmp,allocator<pair<_tagSIDArray const ,unsigned long> > >();
	};

	struct map<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> > >
	{
		SE & operator[](unsigned long const &);
		~map<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> > >();
	};

	struct multimap<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> > >
	{
		~multimap<_VAULT_CAUB,IVaultCredential *,CaubCmp,allocator<pair<_VAULT_CAUB const ,IVaultCredential *> > >();
	};

	class out_of_range
	{
	protected:
		virtual void _Doraise();
	public:
		out_of_range(basic_string<char,char_traits<char>,allocator<char>,_STL70> const &,_STL70 *);
		out_of_range(out_of_range const &);
		virtual ~out_of_range();
	};

	char * _Allocate<char>(unsigned __int64,char *);
	char const * const _bad_alloc_Message;
};

namespace wil
{
	namespace details
	{
		namespace in1diag3
		{
			void _FailFastImmediate_Unexpected();
			void _Log_Hr(void *,unsigned int,char const *,long);
		};

		bool g_resultMessageCallbackSet;
		char const * (* g_pfnGetModuleName)();
		int RecordException(long);
		int RecordFailFast(long);
		int RecordLog(long);
		int RecordReturn(long);
		unsigned short * LogStringPrintf(unsigned short *,unsigned short const *,unsigned short const *,...);
		void (* g_pfnDebugBreak)();
		void (* g_pfnGetContextAndNotifyFailure)(FailureInfo *,char *,unsigned __int64);
		void (* g_pfnLoggingCallback)(FailureInfo const &);
		void (* g_pfnThrowResultException)(FailureInfo const &);
		void LogFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,unsigned short const *,bool,unsigned short *,unsigned __int64,char *,unsigned __int64,FailureInfo *);
		void ReportFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,unsigned short const *,details::ReportFailureOptions);
		void ReportFailure_Hr(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long);
	};

	bool (* g_pfnIsDebuggerPresent)();
	bool g_fBreakOnFailure;
	bool g_fIsDebuggerPresent;
	long GetFailureLogString(unsigned short *,unsigned __int64,wil::FailureInfo const &);
};

IVaultSecurable * GetVaultSystemSecurable();
RPC_DISPATCH_TABLE const Vault_v1_0_DispatchTable;
_MIDL_SERVER_INFO_ const Vault_ServerInfo;
_MIDL_STUB_DESC const Vault_StubDesc;
_NDR64_CONFORMANT_STRING_FORMAT const __midl_frag196;
_NDR64_CONTEXT_HANDLE_FORMAT const __midl_frag122;
_NDR64_CONTEXT_HANDLE_FORMAT const __midl_frag127;
_NDR64_CONTEXT_HANDLE_FORMAT const __midl_frag131;
_NDR64_POINTER_FORMAT const __midl_frag100;
_NDR64_POINTER_FORMAT const __midl_frag108;
_NDR64_POINTER_FORMAT const __midl_frag169;
_NDR64_POINTER_FORMAT const __midl_frag170;
_NDR64_POINTER_FORMAT const __midl_frag194;
_NDR64_POINTER_FORMAT const __midl_frag195;
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
int IsMediumSid(void * const);
int VaultAccessCheck(EVaultSecurableAction,IVaultSecurable *,int *);
long GetDomainSID(int *,int *,void * *);
long InitializeDomainStatus();
long ServiceMain(unsigned long,unsigned short * *,_LSAP_SERVICE_STOP_CALLBACK_CONTEXT *);
long StartVaultRpcServer();
long StringCchCatW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long VaultRpcSecurityCallback(void *,void *);
long VaultSvcStopCallback(void *);
unsigned char IsSchemaDeletable(_GUID const *);
unsigned char VaultVariantCompare(_VAULT_VARIANT *,_VAULT_VARIANT *,unsigned char);
unsigned char const __midl_frag161;
unsigned char const __midl_frag198;
unsigned char const __midl_frag40;
unsigned char const __midl_frag43;
unsigned char const __midl_frag97;
unsigned long BuildVaultPath(unsigned short const *,_GUID const *,unsigned short * *);
unsigned long CalculateCredmanCredSize(IVaultCredential *,efCredFlags,unsigned long *);
unsigned long ComputeItemDigest(_GUID *,_VAULT_ITEM_ELEMENT *,IVaultSchemaElement *,_VAULT_ITEM_ELEMENT *,IVaultSchemaElement *,_VAULT_VARIANT,unsigned short *);
unsigned long ConstructVaultVariantFromRawData(IVaultAllocator *,VAULT_ELEMENT_TYPE,unsigned char *,unsigned long,_VAULT_VARIANT *);
unsigned long ConvertCredentialElementWorker(IVaultAllocator *,unsigned char,IVaultSchemaElement *,CVaultCredDataMap *,IVaultCredentialElement *,_VAULT_ITEM_ELEMENT *);
unsigned long ConvertCredentials(IVaultAllocator *,VaultContext *,eApiAction,IVaultCredential * *,IVaultSchema *,unsigned long,_VAULT_ITEM * *,unsigned long *);
unsigned long ConvertGuidToString(_GUID const *,unsigned short *,unsigned long);
unsigned long ConvertPackageSidWorker(IVaultAllocator *,void * const,_VAULT_ITEM_ELEMENT * *);
unsigned long ConvertSchemaElement(IVaultAllocator *,IVaultSchemaElement *,_VAULT_SCHEMA_ELEMENT * *);
unsigned long ConvertVaultAttributeToCredmanAttribute(_CREDENTIAL_ATTRIBUTEW *,_ATTRIBUTE *,unsigned char *,unsigned long,unsigned long *);
unsigned long CreateCredmanVault(CUserVaultMgr *,unsigned short const *,CUserVault * *);
unsigned long CreateNewVaultInternal(CUserVaultMgr *,unsigned short const *,unsigned char,_GUID const *,_GUID const *,unsigned short const *,eVaultType,efVaultFlags,VaultPolicy *,IVaultCall *,CUserVault * *);
unsigned long DuplicateAttribute(IVaultAllocator *,_ATTRIBUTE *,unsigned long *,_ATTRIBUTE * *);
unsigned long DuplicateBuffer(unsigned char *,unsigned long,unsigned char * *);
unsigned long DuplicateString(IVaultAllocator *,unsigned short const *,unsigned short * *);
unsigned long DuplicateString(unsigned short const *,unsigned short * *);
unsigned long GenerateBuiltinVaultName(unsigned short * *);
unsigned long GetCredElement(IVaultCredentialElement *,VAULT_ELEMENT_TYPE,void *,unsigned long,unsigned long *,unsigned char);
unsigned long GetCredElementSize(IVaultCredentialElement *,VAULT_ELEMENT_TYPE,unsigned long *,unsigned char);
unsigned long GetFailsafeBuiltinVaultName(unsigned short * *);
unsigned long PathCombine(unsigned short const *,unsigned short const *,unsigned short * *);
unsigned long PathCombineExt(unsigned short const *,unsigned short const *,unsigned short const *,unsigned short * *);
unsigned long PopulateCallerAccountInfo(void *,IVaultCredential *,unsigned short *,unsigned long);
unsigned long ReadBlobFromFile(unsigned short const *,unsigned long,unsigned char * *,unsigned long *);
unsigned long ValidateAndGetItemPackageSid(_VAULT_ITEM_ELEMENT *,IVaultCredential *,CVaultSid * *);
unsigned long ValidateAndSetCredentialElement(CUserVault *,_VAULT_ITEM_ELEMENT *,IVaultSchemaElement *,IVaultCredential *,unsigned long ( IVaultCredential::*)(IVaultSchemaElement *,_VAULT_VARIANT *),unsigned char,unsigned char *,_VAULT_CAUB *);
unsigned long VaultConvertCredential(IVaultAllocator *,eApiAction,CUserVault *,void * const,IVaultCredential *,_VAULT_ITEM *);
unsigned long VaultConvertCredentialElement(IVaultAllocator *,CUserVault *,IVaultCredential *,IVaultSchemaElement *,_VAULT_ITEM_ELEMENT *);
unsigned long VaultConvertSchema(IVaultAllocator *,IVaultSchema *,_VAULT_ITEM_SCHEMA *);
unsigned long VaultCreateCredential(IVaultAllocator *,VaultContext *,_VAULT_ITEM *,IVaultCall *,unsigned long,unsigned long);
unsigned long VaultCreateCredentialFromSettingUnit(_SETTING_UNIT *);
unsigned long VaultCreateSchema(CUserVault *,_VAULT_ITEM_SCHEMA *,unsigned long,unsigned char);
unsigned long VaultCreateVaultSecurable(EVaultSecurableType,_GUID const &,CVaultSid *,IVaultSecurable * *);
unsigned long VaultCreateVaultSecurableFromPackageId(EVaultSecurableType,_GUID const &,_VAULT_VARIANT &,IVaultSecurable * *);
unsigned long VaultDeleteCredential(VaultContext *,_GUID *,_VAULT_ITEM_ELEMENT *,_VAULT_ITEM_ELEMENT *,_VAULT_ITEM_ELEMENT *);
unsigned long VaultDeleteRoamingCredential(unsigned short const *,unsigned long);
unsigned long VaultDeleteSchema(CUserVault *,_GUID const *,unsigned long);
unsigned long VaultDeserialize(unsigned char * &,unsigned long &,unsigned short * &);
unsigned long VaultDeserialize<CVaultSchemaElement>(unsigned char * &,unsigned long &,CVaultSchemaElement &);
unsigned long VaultDeserialize<_GUID>(unsigned char * &,unsigned long &,_GUID &);
unsigned long VaultDeserialize<_VAULT_CAUB>(unsigned char * &,unsigned long &,_VAULT_CAUB &);
unsigned long VaultDeserialize<_VAULT_VARIANT>(unsigned char * &,unsigned long &,_VAULT_VARIANT &);
unsigned long VaultDeserialize<unsigned char>(unsigned char * &,unsigned long &,unsigned char &);
unsigned long VaultDeserialize<unsigned long>(unsigned char * &,unsigned long &,unsigned long &);
unsigned long VaultDeserializeString(unsigned char * &,unsigned long &,unsigned short * &);
unsigned long VaultEnableSinglePrivilege(long);
unsigned long VaultEnumerateCredentials(IVaultAllocator *,VaultContext *,unsigned long,_VAULT_ITEM * *,unsigned long *);
unsigned long VaultEnumerateSettingUnits(IVaultAllocator *,unsigned long,_SETTING_UNIT * *,unsigned long *);
unsigned long VaultFindCredential(IVaultAllocator *,VaultContext *,_GUID const *,_VAULT_ITEM_ELEMENT *,unsigned long,IVaultCall *,_VAULT_ITEM * *,unsigned long *);
unsigned long VaultGetCallerPackageSid(CVaultSid * *);
unsigned long VaultGetCredentialSlow(IVaultAllocator *,VaultContext *,_VAULT_ITEM_ELEMENT *,IVaultSchema *,unsigned long,_VAULT_ITEM * *,unsigned long *);
unsigned long VaultGetRoamingCredential(IVaultAllocator *,unsigned short const *,unsigned long,_SETTING_UNIT * *);
unsigned long VaultGetSchema(CUserVault *,_GUID const *,IVaultSchema * *,unsigned char);
unsigned long VaultGetSerializeLength<unsigned short const *>(unsigned short const * &);
unsigned long VaultGetSettingUnitInfo(IVaultAllocator *,unsigned short const *,unsigned short * *,unsigned short * *,unsigned short * *,_GUID *);
unsigned long VaultGetTokenInfo(void *,unsigned char * const,_LUID *);
unsigned long VaultGetUniqueCredential(IVaultAllocator *,VaultContext *,_GUID *,_VAULT_ITEM_ELEMENT *,_VAULT_ITEM_ELEMENT *,_VAULT_ITEM_ELEMENT *,_VAULT_ITEM *);
unsigned long VaultInitialize(HINSTANCE__ *,unsigned short const *);
unsigned long VaultIsDominantCaller(int *);
unsigned long VaultLoadResource(HINSTANCE__ *,unsigned long,unsigned short * *,unsigned long *);
unsigned long VaultLoadResourceWithFormat(HINSTANCE__ *,unsigned long,unsigned short *,unsigned long *,...);
unsigned long VaultLogonSessionNotification(_LSAP_LOGON_SESSION_NOTIFICATION *);
unsigned long VaultProtectAuthenticator(_VAULT_ITEM_ELEMENT *,_VAULT_ITEM_ELEMENT * *);
unsigned long VaultSerialize(unsigned char * &,unsigned long &,CVaultCredElement &);
unsigned long VaultSerialize<CVaultSchemaElement>(unsigned char * &,unsigned long &,CVaultSchemaElement &);
unsigned long VaultSerialize<CredElementLookupInfo>(unsigned char * &,unsigned long &,CredElementLookupInfo &);
unsigned long VaultSerialize<_GUID>(unsigned char * &,unsigned long &,_GUID &);
unsigned long VaultSerialize<_VAULT_CAUB>(unsigned char * &,unsigned long &,_VAULT_CAUB &);
unsigned long VaultSerialize<_VAULT_VARIANT>(unsigned char * &,unsigned long &,_VAULT_VARIANT &);
unsigned long VaultSerialize<unsigned char>(unsigned char * &,unsigned long &,unsigned char &);
unsigned long VaultSerialize<unsigned long const >(unsigned char * &,unsigned long &,unsigned long const &);
unsigned long VaultSerialize<unsigned long>(unsigned char * &,unsigned long &,unsigned long &);
unsigned long VaultSerialize<unsigned short const *>(unsigned char * &,unsigned long &,unsigned short const * &);
unsigned long VaultSvcCtrlHandlerEx(unsigned long,unsigned long,void *,void *);
unsigned long VaultTriggerSyncSession(unsigned long);
unsigned long VaultUnprotectAuthenticator(_VAULT_ITEM_ELEMENT *,_VAULT_ITEM_ELEMENT * *);
unsigned long VaultValidatePackageSid(void * const);
unsigned long VaultValidatePackageSidElement(_VAULT_ITEM_ELEMENT *);
unsigned long VaultVariantDeserialize(unsigned char *,unsigned long *,_VAULT_VARIANT *);
unsigned long VaultVariantDuplicate(IVaultAllocator *,_VAULT_VARIANT *,_VAULT_VARIANT *);
unsigned long VaultVariantGetRawData(_VAULT_VARIANT *,unsigned char * *,unsigned long *);
unsigned long VaultVariantGetSerializedLen(_VAULT_VARIANT *,unsigned long *);
unsigned long VaultVariantSerialize(unsigned char *,unsigned long *,_VAULT_VARIANT *);
unsigned long WriteBlobToFile(IVaultFileSystem *,unsigned short const *,unsigned char *,unsigned long,eWriteMode);
unsigned short const * GetAccountTypeString(_LSA_USER_ACCOUNT_TYPE);
void (*const * const RundownRoutines)(void *);
void * RpcAlloc(unsigned __int64);
void ApiLogDataPointToSqm(unsigned long,unsigned long);
void AutoDereference<CUserVault>(CUserVault *);
void AutoDereference<CUserVaultMgr>(CUserVaultMgr *);
void AutoDereference<CVaultCredential>(CVaultCredential *);
void AutoDereference<CVaultFileStore>(CVaultFileStore *);
void AutoDereference<CVaultSchema>(CVaultSchema *);
void AutoDereference<CVaultSid>(CVaultSid *);
void AutoDereference<IVaultCredential>(IVaultCredential *);
void AutoDereference<IVaultFileSystem>(IVaultFileSystem *);
void AutoDereference<IVaultKeyManager>(IVaultKeyManager *);
void AutoDereference<IVaultSchema>(IVaultSchema *);
void AutoDereference<IVaultStore>(IVaultStore *);
void ConvertByteArrayToString(unsigned char *,unsigned long,unsigned short *,unsigned long);
void DeleteCredentialElement(_VAULT_ITEM_ELEMENT *);
void DumpSchema(_VAULT_ITEM_SCHEMA *);
void DumpSchemaElement(_VAULT_SCHEMA_ELEMENT *);
void DumpVaultItem(_VAULT_ITEM *);
void DumpVaultItemElement(_VAULT_ITEM_ELEMENT *);
void GetFileSystemType(unsigned short const *,eFileSystemType *);
void PrintVaultSidInBuffer(void * const,unsigned short *,unsigned long);
void PrintVaultVariantInBuffer(_VAULT_VARIANT *,unsigned short *,unsigned long);
void RaisePendingNotificationsCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *);
void RpcFree<_GUID>(_GUID *);
void RpcFree<_VAULT_ITEM_SCHEMA>(_VAULT_ITEM_SCHEMA *);
void ShutdownService(unsigned long,unsigned char);
void SqmTimerCallback(_TP_CALLBACK_INSTANCE *,void *,_TP_TIMER *);
void VaultFree<IVaultCredential *>(IVaultCredential * *);
void VaultFree<IVaultSchema *>(IVaultSchema * *);
void VaultFreeInternal(unsigned char *);
void VaultFreeVariant(IVaultAllocator *,_VAULT_VARIANT *);
void VaultFreeVaultCred(IVaultAllocator *,_VAULT_ITEM *);
void VaultFreeVaultCredAll(IVaultAllocator *,_VAULT_ITEM *);
void VaultFreeVaultSchema(IVaultAllocator *,_VAULT_ITEM_SCHEMA *);
void VaultFreeVaultSettingUnit(IVaultAllocator *,_SETTING_UNIT *);
void VaultFreeVaultSettingUnitAll(IVaultAllocator *,_SETTING_UNIT *);
void VaultUninitialize();
void operator delete(void *);
void operator delete(void *,void *);
