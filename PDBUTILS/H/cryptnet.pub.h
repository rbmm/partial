class CCryptBlobArray
{
	int GrowArray();
public:
	CCryptBlobArray(unsigned long,unsigned long,int &);
	int AddBlob(unsigned long,unsigned char *,int);
	int GetArrayInSingleBufferEncodedForm(_CRYPT_BLOB_ARRAY * *,unsigned long *);
	void FreeArray(int);
};

class CCryptUrlArray
{
	int GrowArray();
public:
	CCryptUrlArray(unsigned long,unsigned long,int &);
	int AddUrl(unsigned short *,int);
	int GetArrayInSingleBufferEncodedForm(_CRYPT_URL_ARRAY * *,unsigned long *);
	void FreeArray(int);
};

struct CFileSynchronousRetriever
{
	virtual int RetrieveObjectByUrl(unsigned short const *,char const *,unsigned long,unsigned long,_CRYPT_BLOB_ARRAY *,void (**)(char const *,_CRYPT_BLOB_ARRAY *,void *),void * *,void *,_CRYPT_CREDENTIALS *,_CRYPT_RETRIEVE_AUX_INFO *);
	virtual void AddRef();
	virtual void Release();
};

struct CInetSynchronousRetriever
{
	virtual int RetrieveObjectByUrl(unsigned short const *,char const *,unsigned long,unsigned long,_CRYPT_BLOB_ARRAY *,void (**)(char const *,_CRYPT_BLOB_ARRAY *,void *),void * *,void *,_CRYPT_CREDENTIALS *,_CRYPT_RETRIEVE_AUX_INFO *);
	virtual void AddRef();
	virtual void Release();
};

class CLdapStore
{
	int FillCacheStore(int);
	int InternalCommit(unsigned long);
	int WriteCheckSetDirtyWithLock(char const *,void *,unsigned long);
public:
	CLdapStore(int &);
	int OpenStore(char const *,unsigned long,unsigned __int64,unsigned long,void const *,void *,_CERT_STORE_PROV_INFO *);
	void CloseStore(unsigned long);
};

struct CLdapSynchronousRetriever
{
	virtual int RetrieveObjectByUrl(unsigned short const *,char const *,unsigned long,unsigned long,_CRYPT_BLOB_ARRAY *,void (**)(char const *,_CRYPT_BLOB_ARRAY *,void *),void * *,void *,_CRYPT_CREDENTIALS *,_CRYPT_RETRIEVE_AUX_INFO *);
	virtual void AddRef();
	virtual void Release();
};

class CObjectRetrievalManager
{
	int LoadProviders(unsigned short const *,char const *);
public:
	int OnRetrievalCompletion(unsigned long,unsigned short const *,char const *,unsigned long,_CRYPT_BLOB_ARRAY *,void (*)(char const *,_CRYPT_BLOB_ARRAY *,void *),void *,void *,void * *,_CRYPT_RETRIEVE_AUX_INFO *);
	int RetrieveObjectByUrl(unsigned short const *,char const *,unsigned long,unsigned long,void * *,void *,_CRYPT_CREDENTIALS *,void *,_CRYPT_RETRIEVE_AUX_INFO *);
	virtual void AddRef();
	virtual void Release();
};

struct CTVOAgent
{
	int FlushTimeValidObject(char const *,void *,char const *,_CERT_CONTEXT const *,unsigned long,void *);
	int FlushTimeValidOriginIdentifier(void *,char const *,_CERT_CONTEXT const *,unsigned char * const);
	int FlushTimeValidUrlCacheEntry(void *,char const *,_CERT_CONTEXT const *,unsigned short const *);
	int GetTimeValidObject(char const *,void *,char const *,_CERT_CONTEXT const *,_FILETIME *,unsigned long,unsigned long,void * *,_CRYPT_CREDENTIALS *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *);
	int GetTimeValidObjectByUrl(unsigned long,_CRYPT_URL_ARRAY *,unsigned long,char const *,_CERT_CONTEXT const *,void *,unsigned char * const,_FILETIME *,unsigned long,unsigned long,void * *,_CRYPT_CREDENTIALS *,int *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *,_TVO_ACTIVE_ENTRY *);
	long StartActiveRetrieval(char const *,char const *,void *,_FILETIME *,unsigned long,void * *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *,unsigned char * const,unsigned char * const,_TVO_ACTIVE_ENTRY * *);
	void CompleteActiveRetrieval(_TVO_ACTIVE_ENTRY *,unsigned long,int,void *);
	void PreFetchCrl(_CRL_PRE_FETCH_ENTRY *);
};

struct CTVOCache
{
	_TVO_CACHE_ENTRY * FindCacheEntry(unsigned char * const,char const *,void *);
	void RemoveAllCacheEntries();
	void RemoveCacheEntry(_TVO_CACHE_ENTRY *,int);
};

CTVOAgent * g_pProcessTVOAgent;
HINSTANCE__ * g_hModule;
HINSTANCE__ * hCrobuModule;
_CERT_CONTEXT const * FindIssuerCertInStores(_CERT_CONTEXT const *,unsigned long,void * * const);
_CRL_CONTEXT const * OcspConvertResponseToCrl(unsigned char const *,unsigned long,_OCSP_CERT_ID const *,_OCSP_BASIC_RESPONSE_INFO *,_CERT_CONTEXT const *,_CERT_CONTEXT const *,_OCSP_STRONG_SIGN_PROP_INFO *,unsigned long);
_CRL_PRE_FETCH_ENTRY * CreateCrlPreFetchEntry(_TVO_CACHE_ENTRY *,_CERT_CONTEXT const *,_CERT_CONTEXT const *);
_CROBU_ENTRY * pCrobuPendingHead;
_CRYPTNET_URL_CACHE_RESPONSE_INFO * InetCreateResponseInfo(void *);
_OCSP_CERT_ID * OcspCreateCertId(_CERT_CONTEXT const *,_CERT_CONTEXT const *);
_OFFLINE_URL_CACHE_ENTRY * CreateAndAddOfflineUrlCacheEntry(_CRYPTOAPI_BLOB *,_CRYPTOAPI_BLOB *,char const *,unsigned long);
_OFFLINE_URL_CACHE_ENTRY * FindOfflineUrlCacheEntry(_CRYPTOAPI_BLOB *,_CRYPTOAPI_BLOB *,char const *,unsigned long);
_OFFLINE_URL_CACHE_ENTRY * pOfflineUrlCacheHead;
_RTL_CRITICAL_SECTION CrobuCriticalSection;
_RTL_CRITICAL_SECTION MSCtlDefaultStoresCriticalSection;
_RTL_CRITICAL_SECTION OfflineUrlCacheCriticalSection;
char * g_rgszLdapServerError;
char const * * rgpszSupportedCrlExtensionOID;
int AddUrlsFromCDPDirectoryName(_CRYPTOAPI_BLOB *,CCryptUrlArray *);
int CertDllVerifyCTLUsage(unsigned long,unsigned long,void *,_CTL_USAGE *,unsigned long,_CTL_VERIFY_USAGE_PARA *,_CTL_VERIFY_USAGE_STATUS *);
int CertDllVerifyRevocation(unsigned long,unsigned long,unsigned long,void * * const,unsigned long,_CERT_REVOCATION_PARA *,_CERT_REVOCATION_STATUS *);
int CertGetOriginIdentifier(_CERT_CONTEXT const *,_CERT_CONTEXT const *,unsigned long,unsigned char * const);
int CertificateGetRevocationUrl(char const *,void *,unsigned short *,unsigned long,_CRYPT_URL_ARRAY * *,unsigned long *,unsigned long *);
int CreateProcessTVOAgent(CTVOAgent * *);
int CrlFlushTimeValidObject(char const *,void *,_CERT_CONTEXT const *,unsigned long,void *);
int CrlFromCertFlushTimeValidObject(char const *,void *,_CERT_CONTEXT const *,unsigned long,void *);
int CrlFromCertGetTimeValidObject(char const *,void *,_CERT_CONTEXT const *,_FILETIME *,unsigned long,unsigned long,void * *,_CRYPT_CREDENTIALS *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *);
int CrlGetOriginIdentifier(_CRL_CONTEXT const *,_CERT_CONTEXT const *,unsigned long,unsigned char * const);
int CrlGetOriginIdentifierFromCrlIssuer(_CERT_CONTEXT const *,_CRYPTOAPI_BLOB *,int,unsigned char * const);
int CrlGetTimeValidObject(char const *,void *,_CERT_CONTEXT const *,_FILETIME *,unsigned long,unsigned long,void * *,_CRYPT_CREDENTIALS *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *);
int CryptRetrieveObjectByUrlWithTimeout(unsigned short const *,char const *,unsigned long,unsigned long,void * *,_CRYPT_RETRIEVE_AUX_INFO *,void *);
int CtlFlushTimeValidObject(char const *,void *,_CERT_CONTEXT const *,unsigned long,void *);
int CtlGetOriginIdentifier(_CTL_CONTEXT const *,_CERT_CONTEXT const *,unsigned long,unsigned char * const);
int CtlGetTimeValidObject(char const *,void *,_CERT_CONTEXT const *,_FILETIME *,unsigned long,unsigned long,void * *,_CRYPT_CREDENTIALS *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *);
int DemandLoadDllMain(HINSTANCE__ *,unsigned long,void *);
int FreshestCrlFromCertFlushTimeValidObject(char const *,void *,_CERT_CONTEXT const *,unsigned long,void *);
int FreshestCrlFromCertGetTimeValidObject(char const *,void *,_CERT_CONTEXT const *,_FILETIME *,unsigned long,unsigned long,void * *,_CRYPT_CREDENTIALS *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *);
int FreshestCrlFromCrlFlushTimeValidObject(char const *,void *,_CERT_CONTEXT const *,unsigned long,void *);
int FreshestCrlFromCrlGetTimeValidObject(char const *,void *,_CERT_CONTEXT const *,_FILETIME *,unsigned long,unsigned long,void * *,_CRYPT_CREDENTIALS *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *);
int GetBaseCrl(_CERT_CONTEXT const *,_CERT_CONTEXT const *,_CERT_REVOCATION_PARA *,int,unsigned long,_FILETIME *,_CRL_CONTEXT const * *,int *,int *);
int GetDeltaCrl(_CERT_CONTEXT const *,_CERT_CONTEXT const *,_CERT_REVOCATION_PARA *,unsigned long,int,_FILETIME *,_CRL_CONTEXT const * *,int *,_CRL_CONTEXT const * *,unsigned long *);
int GetTimeValidCrl(char const *,void *,_CERT_CONTEXT const *,_CERT_CONTEXT const *,_CERT_REVOCATION_PARA *,int,unsigned long,unsigned long,_FILETIME *,_CRL_CONTEXT const * *,int *);
int GetTimeValidCrlFromOcspResponseProperty(_CERT_CONTEXT const *,_CERT_CONTEXT const *,int,_FILETIME *,_CERT_REVOCATION_CHAIN_PARA *,_CRL_CONTEXT const * *);
int GetUrlArrayAndInfoFromCrossCertDistPoint(unsigned long,_CRYPT_RAW_URL_DATA *,_CRYPT_URL_ARRAY *,unsigned long *,_CRYPT_URL_INFO *,unsigned long *);
int HasUnsupportedCrlCriticalExtension(_CRL_CONTEXT const *);
int I_CountCachedOcspCallback(_CRYPTNET_URL_CACHE_ENTRY const *,unsigned long,void *,void *);
int I_CryptConvertIriToAsciiOrUnicode(int,unsigned short const *,unsigned long *,unsigned short *);
int I_CryptConvertIriToAsciiOrUnicodeWithFlags(unsigned long,unsigned short const *,unsigned long *,unsigned short *);
int I_CryptNetIsDebugTracePrintEnabled();
int I_CryptnetIsProcessDetachFreeLibrary(void *);
int I_EncodeSignedOcspRequest(_OCSP_CERT_ID const *,unsigned char * *,unsigned long *);
int I_IsOcspIndependentSignerCert(_CERT_CONTEXT const *,void *,_CERT_REVOCATION_CHAIN_PARA *,unsigned long,_OCSP_STRONG_SIGN_PROP_INFO *);
int I_UrlEscapeBase64W(unsigned short const *,unsigned short *,unsigned long *);
int InetParseSpecialPostUrl(unsigned short const *,unsigned short * *,unsigned short * *,unsigned char * *,unsigned long *);
int IsOcspUrl(unsigned short const *,char const *,void *);
int IsPendingCryptRetrieveObjectByUrl(unsigned short const *);
int IsValidCreateOrExpireTime(int,_FILETIME *,_FILETIME *,_FILETIME *);
int IsValidCrlIssuerKeyUsage(_CERT_CONTEXT const *);
int LdapProvDeleteCert(void *,_CERT_CONTEXT const *,unsigned long);
int LdapProvDeleteCrl(void *,_CRL_CONTEXT const *,unsigned long);
int LdapProvDeleteCtl(void *,_CTL_CONTEXT const *,unsigned long);
int LdapProvOpenStore(char const *,unsigned long,unsigned __int64,unsigned long,void const *,void *,_CERT_STORE_PROV_INFO *);
int LdapProvSetCertProperty(void *,_CERT_CONTEXT const *,unsigned long,unsigned long,void const *);
int LdapProvSetCrlProperty(void *,_CRL_CONTEXT const *,unsigned long,unsigned long,void const *);
int LdapProvSetCtlProperty(void *,_CTL_CONTEXT const *,unsigned long,unsigned long,void const *);
int LdapProvStoreControl(void *,unsigned long,unsigned long,void *);
int LdapProvWriteCert(void *,_CERT_CONTEXT const *,unsigned long);
int LdapProvWriteCrl(void *,_CRL_CONTEXT const *,unsigned long);
int LdapProvWriteCtl(void *,_CTL_CONTEXT const *,unsigned long);
int MicrosoftCertDllVerifyRevocation(unsigned long,unsigned long,unsigned long,void * * const,unsigned long,_CERT_REVOCATION_PARA *,_CERT_REVOCATION_STATUS *);
int ObjectContextDeleteAllObjectsFromStore(void *);
int ObjectContextGetAttribute(char const *,void *,unsigned long,unsigned long,char const *,_CRYPT_ATTRIBUTE *,unsigned long *);
int ObjectContextGetCreateAndExpireTimes(char const *,void *,_FILETIME *,_FILETIME *);
int ObjectContextGetNextUpdateUrl(char const *,void *,_CERT_CONTEXT const *,unsigned short *,_CRYPT_URL_ARRAY * *,unsigned long *,unsigned long *);
int ObjectContextGetOriginIdentifier(char const *,void *,_CERT_CONTEXT const *,unsigned long,unsigned char * const);
int ObjectContextGetProperty(char const *,void *,unsigned long,void *,unsigned long *);
int ObjectContextIsValidForSubject(char const *,void *,void *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *);
int ObjectContextVerifySignature(char const *,void *,_CERT_CONTEXT const *);
int OcspGetOriginIdentifier(_CERT_CONTEXT const *,unsigned char * const);
int OcspGetStrongCNGAlgidProperty(_CERT_CONTEXT const *,unsigned long,unsigned short *,unsigned __int64 *);
int OcspVerifyResponse(unsigned char const *,unsigned long,_CERT_CONTEXT const *,_CERT_CONTEXT const *,_CERT_REVOCATION_CHAIN_PARA *,unsigned long,_OCSP_BASIC_RESPONSE_INFO * *,_CERT_CONTEXT const * *,_OCSP_STRONG_SIGN_PROP_INFO *,unsigned long);
int RPORDllMain(HINSTANCE__ *,unsigned long,void *);
int RetrieveObjectByOcspUrlValidForSubject(_OCSP_CERT_ID const *,unsigned short const *,int,_FILETIME *,unsigned long,unsigned long,_CRYPT_CREDENTIALS *,_CERT_CONTEXT const *,void *,void * *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *);
int RetrieveObjectByUrlValidForSubject(int,int,unsigned short *,char const *,int,_FILETIME *,unsigned long,unsigned long,_CRYPT_CREDENTIALS *,_CERT_CONTEXT const *,void *,unsigned char * const,void * *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *);
int RetrieveTimeValidObjectByUrl(int,int,int,unsigned short *,char const *,_FILETIME *,unsigned long,unsigned long,_CRYPT_CREDENTIALS *,_CERT_CONTEXT const *,void *,unsigned char * const,void * *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *);
int g_fTVOAgentProcessExit;
long GetOfflineUrlTimeStatus(_OFFLINE_URL_TIME_INFO *);
long GetOriginUrlStatusW(unsigned char * const,unsigned short const *,char const *,unsigned long,_FILETIME *);
long GetUrlStatusW(unsigned short const *,char const *,unsigned long,_FILETIME *);
long I_RetrieveObjectByOcspUrlValidForSubject(_OCSP_CERT_ID const *,unsigned short const *,int,_FILETIME *,unsigned long,unsigned long,_CERT_CONTEXT const *,_CERT_CONTEXT const *,void * *,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *,unsigned short *);
long InetSendAuthenticatedRequestAndReceiveResponse(void *,void *,unsigned short const *,unsigned short const *,unsigned char const *,unsigned long,unsigned long,_CRYPT_CREDENTIALS *,_CRYPT_RETRIEVE_AUX_INFO *);
long RPORDllRegUnregServer(HINSTANCE__ *,int);
long StringCbVPrintfA(char *,unsigned __int64,char const *,char *);
long StringCchCatA(char *,unsigned __int64,char const *);
long StringCchCatNW(unsigned short *,unsigned __int64,unsigned short const *,unsigned __int64);
long StringCchCatW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchCopyA(char *,unsigned __int64,char const *);
long StringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchPrintfA(char *,unsigned __int64,char const *,...);
long StringCchPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long WrapUrlUnescapeW(unsigned short const *,int,unsigned short * *,unsigned long *);
unsigned long CertificateGetOcspCrlUrlOrder(_CERT_CONTEXT const *,unsigned long);
unsigned long CryptRetrieveObjectByUrlWithTimeoutThreadProc(void *);
unsigned long GetCrlReason(_CRL_ENTRY *);
unsigned long GetCryptNetDebugFlags();
unsigned long I_GetOcspValiditySeconds();
unsigned long I_GetRegDwordValue(unsigned short const *,unsigned long *);
unsigned long InetGetMaxAgeFromCacheControlHeader(unsigned short const *);
unsigned long ReadRegDwordValue(unsigned short const *,unsigned short const *,int,unsigned long *);
unsigned long TVOCacheHashOriginIdentifier(_CRYPTOAPI_BLOB *);
unsigned short * CertificateGetOcspCacheFileNamePrefix(_CERT_CONTEXT const *);
unsigned short * GetCDPOIDFunctionValue(unsigned short const *);
unsigned short * GetCrlPreFetchUrlList();
unsigned short * I_SchemeGetCryptnetFlushCacheDir();
unsigned short * I_SchemeGetCryptnetUrlCacheDir();
unsigned short * InetCreateRequestHeaders(unsigned short const *,int,_CRYPT_RETRIEVE_AUX_INFO *,int *,_FILETIME *);
unsigned short * InetHttpQueryAndAllocateStringHeader(void *,unsigned long);
unsigned short * OcspFormatGetRequest(unsigned short const *,_OCSP_CERT_ID const *);
unsigned short * OcspFormatPostRequest(unsigned short const *);
unsigned short * OcspGetChainStrongCNGAlgidPropertyList(_CERT_CHAIN_CONTEXT const *,unsigned long);
void * I_SchemeGetToken();
void * I_ValidateObjectForSubject(int,int,unsigned short *,char const *,int,_FILETIME *,unsigned long,_CERT_CONTEXT const *,void *,unsigned char * const,_CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO *,void *,_CRYPT_RETRIEVE_AUX_INFO *);
void * ObjectContextDuplicate(char const *,void *);
void * ObjectContextEnumObjectsInStore(void *,char const *,void *,char const * *);
void * ObjectContextFindCorrespondingObject(void *,char const *,void *);
void * hFlushTimeValidObjectFuncSet;
void * hGetTimeValidObjectFuncSet;
void * operator new(unsigned __int64);
void AiaUrlRedirectCallBack(void *,unsigned __int64,unsigned long,void *,unsigned long);
void CryptRetrieveGetAuxInfo(_CROBU_ENTRY *,_CRYPT_RETRIEVE_AUX_INFO *);
void CryptRetrieveSetAuxInfo(_CRYPT_RETRIEVE_AUX_INFO *,unsigned short *,_CROBU_ENTRY *);
void DeleteOfflineUrlCache();
void FreeCrlPreFetchEntry(_CRL_PRE_FETCH_ENTRY *);
void GetMaxAgeTime(_CRYPTNET_URL_CACHE_RESPONSE_INFO *,_FILETIME *);
void I_CryptNetDebugErrorPrintfA(char const *,...);
void I_CryptNetDebugPrintfA(char const *,...);
void I_CryptNetDebugTracePrintfA(char const *,...);
void I_GetCachedOcspCountParameters(unsigned long *,unsigned long *);
void I_GetMaxAgeParameters(unsigned long *,unsigned long *);
void I_OcspDebugErrorPrintfA(char const *,_CERT_CONTEXT const *);
void LdapProvCloseStore(void *,unsigned long);
void MSCtlCloseDefaultStores();
void ObjectContextFree(char const *,void *);
void ObjectContextFreeTVOCacheEntry(_TVO_CACHE_ENTRY *);
void OcspFreeStrongSignPropInfo(_OCSP_STRONG_SIGN_PROP_INFO *);
void RemoveAndFreeOfflineUrlCacheEntry(_OFFLINE_URL_CACHE_ENTRY *);
void RemoveCrlPreFetchEntry(_TVO_CACHE_ENTRY *);
void ScheduleNextCrlPreFetch(_CRL_PRE_FETCH_ENTRY *);
void SetOfflineOriginUrlW(unsigned char * const,unsigned short const *,char const *,unsigned long,_FILETIME *);
void SetOfflineUrlTime(_OFFLINE_URL_TIME_INFO *,_FILETIME *);
void SetOfflineUrlW(unsigned short const *,char const *,unsigned long);
void SetOnlineOriginUrlW(unsigned char * const,unsigned short const *,char const *,unsigned long);
void SetOnlineUrlW(unsigned short const *,char const *,unsigned long);
void TVOCacheOnRemoval(void *,void *);
