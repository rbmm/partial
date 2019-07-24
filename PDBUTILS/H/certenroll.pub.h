namespace ARI
{
	namespace ProcessToken
	{
		struct AutoSysAppId
		{
			long Close();
		};

		namespace SysAppId
		{
			long GetAppUserModelId(_TOKEN_SECURITY_ATTRIBUTE_V1 const *,unsigned int,unsigned int *,unsigned short *);
			long GetPackageFamilyName(_TOKEN_SECURITY_ATTRIBUTE_V1 const *,unsigned int,unsigned int *,unsigned short *);
			long GetPackageRelativeApplicationId(_TOKEN_SECURITY_ATTRIBUTE_V1 const *,unsigned int,unsigned int *,unsigned short *);
			long Open(void *,_TOKEN_SECURITY_ATTRIBUTES_INFORMATION * *,_TOKEN_SECURITY_ATTRIBUTE_V1 const * *,bool *);
			long OpenTokenForProcess(void *,void * *);
		};

	};

	void Free(void *);
};

namespace ATL
{
	struct CAtlBaseModule
	{
		CAtlBaseModule();
		~CAtlBaseModule();
	};

	struct CAtlComModule
	{
		CAtlComModule();
		~CAtlComModule();
	};

	struct CAtlModule
	{
		long UpdateRegistryFromResourceS(unsigned int,int,_ATL_REGMAP_ENTRY *);
		long UpdateRegistryFromResourceS(unsigned short const *,int,_ATL_REGMAP_ENTRY *);
		static _GUID m_libid;
		static void EscapeSingleQuote(unsigned short *,unsigned __int64,unsigned short const *);
		virtual long GetGITPtr(IGlobalInterfaceTable * *);
		virtual long GetLockCount();
		virtual long Lock();
		virtual long Unlock();
		virtual ~CAtlModule();
		void Term();
	};

	struct CAtlModuleT<CComModule>
	{
		long RegisterServer(int,_GUID const *);
		virtual long AddCommonRGSReplacements(IRegistrarBase *);
		virtual ~CAtlModuleT<CComModule>();
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

	struct CComAutoDeleteCriticalSection
	{
		~CComAutoDeleteCriticalSection();
	};

	struct CComBSTR
	{
		CComBSTR(CComBSTR const &);
		CComBSTR(unsigned short const *);
		long Append(unsigned short const *);
		long Append(unsigned short const *,int);
		void Attach(unsigned short *);
		~CComBSTR();
	};

	struct CComClassFactory
	{
		virtual long CreateInstance(IUnknown *,_GUID const &,void * *);
		virtual long LockServer(int);
		~CComClassFactory();
	};

	struct CComCreator2<CComCreator<CComObject<CX509EnrollmentPolicyWebService> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CX509PolicyServerListManager> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CX509PolicyServerUrl> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CAlternativeName> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CAlternativeNames> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CBinaryConverter> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCAStatus> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCAStatuses> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertProperties> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertProperty> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertyArchived> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertyArchivedKeyHash> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertyAutoEnroll> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertyBackedUp> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertyDescription> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertyEnrollment> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertyEnrollmentPolicyServer> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertyFriendlyName> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertyKeyProvInfo> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertyRenewal> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertyRequestOriginator> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertPropertySHA1Hash> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertificateAttestationChallenge> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertificatePolicies> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCertificatePolicy> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCryptAttribute> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCryptAttributes> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCspInformation> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCspInformations> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CCspStatus> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CObjectId> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CObjectIds> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CPkcs10> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CPolicyQualifier> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CPolicyQualifiers> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CSignerCertificate> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CSmimeCapabilities> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CSmimeCapability> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX500DistinguishedName> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509Attribute> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509AttributeArchiveKey> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509AttributeArchiveKeyHash> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509AttributeClientId> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509AttributeCspProvider> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509AttributeExtensions> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509AttributeOSVersion> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509AttributeRenewalCertificate> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509Attributes> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509CertificateRequestCertificate> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509CertificateRequestCmc> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509CertificateRequestPkcs10> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509CertificateRequestPkcs7> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509CertificateRevocationList> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509CertificateRevocationListEntries> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509CertificateRevocationListEntry> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509CertificateTemplateADWritable> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509EndorsementKey> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509Enrollment> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509EnrollmentHelper> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509EnrollmentManager> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509EnrollmentPolicyActiveDirectory> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509EnrollmentWebClassFactory> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509Enrollments> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509Extension> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509ExtensionAlternativeNames> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509ExtensionAuthorityKeyIdentifier> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509ExtensionBasicConstraints> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509ExtensionCertificatePolicies> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509ExtensionEnhancedKeyUsage> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509ExtensionKeyUsage> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509ExtensionMSApplicationPolicies> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509ExtensionSmimeCapabilities> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509ExtensionSubjectKeyIdentifier> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509ExtensionTemplate> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509ExtensionTemplateName> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509Extensions> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509MachineEnrollmentFactory> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509NameValuePair> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509PrivateKey> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509PublicKey> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509SCEPEnrollment> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator2<CComCreator<CComObject<CertEnroll::CX509SCEPEnrollmentHelper> >,CComFailCreator<-2147221232> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CX509EnrollmentPolicyWebService> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CX509PolicyServerListManager> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CX509PolicyServerUrl> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CAlternativeName> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CAlternativeNames> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CBinaryConverter> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCAStatus> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCAStatuses> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertProperties> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertProperty> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertyArchived> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertyArchivedKeyHash> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertyAutoEnroll> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertyBackedUp> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertyDescription> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertyEnrollment> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertyEnrollmentPolicyServer> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertyFriendlyName> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertyKeyProvInfo> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertyRenewal> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertyRequestOriginator> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertPropertySHA1Hash> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertificateAttestationChallenge> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertificatePolicies> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCertificatePolicy> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCryptAttribute> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCryptAttributes> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCspInformation> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCspInformations> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CCspStatus> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CObjectId> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CObjectIds> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CPkcs10> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CPolicyQualifier> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CPolicyQualifiers> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CSignerCertificate> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CSmimeCapabilities> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CSmimeCapability> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX500DistinguishedName> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509Attribute> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509AttributeArchiveKey> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509AttributeArchiveKeyHash> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509AttributeClientId> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509AttributeCspProvider> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509AttributeExtensions> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509AttributeOSVersion> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509AttributeRenewalCertificate> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509Attributes> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509CertificateRequestCertificate> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509CertificateRequestCmc> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509CertificateRequestPkcs10> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509CertificateRequestPkcs7> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509CertificateRevocationList> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509CertificateRevocationListEntries> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509CertificateRevocationListEntry> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509CertificateTemplateADWritable> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509EndorsementKey> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509Enrollment> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509EnrollmentHelper> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509EnrollmentManager> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509EnrollmentPolicyActiveDirectory> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509EnrollmentWebClassFactory> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509Enrollments> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509Extension> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509ExtensionAlternativeNames> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509ExtensionAuthorityKeyIdentifier> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509ExtensionBasicConstraints> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509ExtensionCertificatePolicies> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509ExtensionEnhancedKeyUsage> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509ExtensionKeyUsage> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509ExtensionMSApplicationPolicies> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509ExtensionSmimeCapabilities> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509ExtensionSubjectKeyIdentifier> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509ExtensionTemplate> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509ExtensionTemplateName> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509Extensions> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509MachineEnrollmentFactory> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509NameValuePair> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509PrivateKey> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509PublicKey> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509SCEPEnrollment> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObject<CertEnroll::CX509SCEPEnrollmentHelper> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCreator<CComObjectCached<CComClassFactory> >
	{
		static long CreateInstance(void *,_GUID const &,void * *);
	};

	struct CComCritSecLock<CComCriticalSection>
	{
		~CComCritSecLock<CComCriticalSection>();
	};

	struct CComCriticalSection
	{
		long Init();
		~CComCriticalSection();
	};

	struct CComModule
	{
		CComModule();
		long GetClassObject(_GUID const &,_GUID const &,void * *);
		long Init(_ATL_OBJMAP_ENTRY30 *,HINSTANCE__ *,_GUID const *);
		long RegisterClassHelper(_GUID const &,unsigned short const *,unsigned short const *,unsigned short const *,unsigned long);
		long UnregisterClassHelper(_GUID const &,unsigned short const *,unsigned short const *);
		long UnregisterServer(int,_GUID const *);
		long UpdateRegistryClass(_GUID const &,unsigned short const *,unsigned short const *,unsigned int,unsigned long,int);
		static long RegisterProgID(unsigned short const *,unsigned short const *,unsigned short const *);
		virtual long UpdateRegistryFromResourceD(unsigned int,int,_ATL_REGMAP_ENTRY *);
		virtual long UpdateRegistryFromResourceD(unsigned short const *,int,_ATL_REGMAP_ENTRY *);
		virtual long UpdateRegistryFromResourceS(unsigned int,int,_ATL_REGMAP_ENTRY *);
		virtual long UpdateRegistryFromResourceS(unsigned short const *,int,_ATL_REGMAP_ENTRY *);
		virtual ~CComModule();
		void Term();
	};

	struct CComObject<CCertificationWebService>
	{
		CComObject<CCertificationWebService>(void *);
		static long CreateInstance(CComObject<CCertificationWebService> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CCertificationWebService>();
	};

	struct CComObject<CX509EnrollmentPolicyWebService>
	{
		CComObject<CX509EnrollmentPolicyWebService>(void *);
		static long CreateInstance(CComObject<CX509EnrollmentPolicyWebService> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CX509EnrollmentPolicyWebService>();
	};

	struct CComObject<CX509PolicyServerListManager>
	{
		CComObject<CX509PolicyServerListManager>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CX509PolicyServerListManager>();
	};

	struct CComObject<CX509PolicyServerUrl>
	{
		CComObject<CX509PolicyServerUrl>(void *);
		static long CreateInstance(CComObject<CX509PolicyServerUrl> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CX509PolicyServerUrl>();
	};

	struct CComObject<CertEnroll::CAlternativeName>
	{
		CComObject<CertEnroll::CAlternativeName>(void *);
		static long CreateInstance(CComObject<CertEnroll::CAlternativeName> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CAlternativeName>();
	};

	struct CComObject<CertEnroll::CAlternativeNames>
	{
		CComObject<CertEnroll::CAlternativeNames>(void *);
		static long CreateInstance(CComObject<CertEnroll::CAlternativeNames> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CAlternativeNames>();
	};

	struct CComObject<CertEnroll::CBinaryConverter>
	{
		CComObject<CertEnroll::CBinaryConverter>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CBinaryConverter>();
	};

	struct CComObject<CertEnroll::CCAStatus>
	{
		CComObject<CertEnroll::CCAStatus>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCAStatus> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCAStatus>();
	};

	struct CComObject<CertEnroll::CCAStatuses>
	{
		CComObject<CertEnroll::CCAStatuses>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCAStatuses> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCAStatuses>();
	};

	struct CComObject<CertEnroll::CCertProperties>
	{
		CComObject<CertEnroll::CCertProperties>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertProperties> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertProperties>();
	};

	struct CComObject<CertEnroll::CCertProperty>
	{
		CComObject<CertEnroll::CCertProperty>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertProperty> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertProperty>();
	};

	struct CComObject<CertEnroll::CCertPropertyArchived>
	{
		CComObject<CertEnroll::CCertPropertyArchived>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertPropertyArchived> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertyArchived>();
	};

	struct CComObject<CertEnroll::CCertPropertyArchivedKeyHash>
	{
		CComObject<CertEnroll::CCertPropertyArchivedKeyHash>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertPropertyArchivedKeyHash> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertyArchivedKeyHash>();
	};

	struct CComObject<CertEnroll::CCertPropertyAutoEnroll>
	{
		CComObject<CertEnroll::CCertPropertyAutoEnroll>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertyAutoEnroll>();
	};

	struct CComObject<CertEnroll::CCertPropertyBackedUp>
	{
		CComObject<CertEnroll::CCertPropertyBackedUp>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertyBackedUp>();
	};

	struct CComObject<CertEnroll::CCertPropertyDescription>
	{
		CComObject<CertEnroll::CCertPropertyDescription>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertPropertyDescription> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertyDescription>();
	};

	struct CComObject<CertEnroll::CCertPropertyEnrollment>
	{
		CComObject<CertEnroll::CCertPropertyEnrollment>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertPropertyEnrollment> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertyEnrollment>();
	};

	struct CComObject<CertEnroll::CCertPropertyEnrollmentPolicyServer>
	{
		CComObject<CertEnroll::CCertPropertyEnrollmentPolicyServer>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertPropertyEnrollmentPolicyServer> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertyEnrollmentPolicyServer>();
	};

	struct CComObject<CertEnroll::CCertPropertyFriendlyName>
	{
		CComObject<CertEnroll::CCertPropertyFriendlyName>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertPropertyFriendlyName> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertyFriendlyName>();
	};

	struct CComObject<CertEnroll::CCertPropertyKeyProvInfo>
	{
		CComObject<CertEnroll::CCertPropertyKeyProvInfo>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertPropertyKeyProvInfo> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertyKeyProvInfo>();
	};

	struct CComObject<CertEnroll::CCertPropertyRenewal>
	{
		CComObject<CertEnroll::CCertPropertyRenewal>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertPropertyRenewal> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertyRenewal>();
	};

	struct CComObject<CertEnroll::CCertPropertyRequestOriginator>
	{
		CComObject<CertEnroll::CCertPropertyRequestOriginator>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertPropertyRequestOriginator> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertyRequestOriginator>();
	};

	struct CComObject<CertEnroll::CCertPropertySHA1Hash>
	{
		CComObject<CertEnroll::CCertPropertySHA1Hash>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertPropertySHA1Hash>();
	};

	struct CComObject<CertEnroll::CCertificateAttestationChallenge>
	{
		CComObject<CertEnroll::CCertificateAttestationChallenge>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertificateAttestationChallenge>();
	};

	struct CComObject<CertEnroll::CCertificatePolicies>
	{
		CComObject<CertEnroll::CCertificatePolicies>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertificatePolicies> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertificatePolicies>();
	};

	struct CComObject<CertEnroll::CCertificatePolicy>
	{
		CComObject<CertEnroll::CCertificatePolicy>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertificatePolicy> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertificatePolicy>();
	};

	struct CComObject<CertEnroll::CCertificationAuthorities>
	{
		CComObject<CertEnroll::CCertificationAuthorities>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertificationAuthorities> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertificationAuthorities>();
	};

	struct CComObject<CertEnroll::CCertificationAuthority>
	{
		CComObject<CertEnroll::CCertificationAuthority>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCertificationAuthority> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCertificationAuthority>();
	};

	struct CComObject<CertEnroll::CCryptAttribute>
	{
		CComObject<CertEnroll::CCryptAttribute>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCryptAttribute> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCryptAttribute>();
	};

	struct CComObject<CertEnroll::CCryptAttributes>
	{
		CComObject<CertEnroll::CCryptAttributes>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCryptAttributes> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCryptAttributes>();
	};

	struct CComObject<CertEnroll::CCspAlgorithm>
	{
		CComObject<CertEnroll::CCspAlgorithm>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCspAlgorithm> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCspAlgorithm>();
	};

	struct CComObject<CertEnroll::CCspAlgorithms>
	{
		CComObject<CertEnroll::CCspAlgorithms>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCspAlgorithms> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCspAlgorithms>();
	};

	struct CComObject<CertEnroll::CCspInformation>
	{
		CComObject<CertEnroll::CCspInformation>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCspInformation> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCspInformation>();
	};

	struct CComObject<CertEnroll::CCspInformations>
	{
		CComObject<CertEnroll::CCspInformations>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCspInformations> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCspInformations>();
	};

	struct CComObject<CertEnroll::CCspStatus>
	{
		CComObject<CertEnroll::CCspStatus>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCspStatus> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCspStatus>();
	};

	struct CComObject<CertEnroll::CCspStatuses>
	{
		CComObject<CertEnroll::CCspStatuses>(void *);
		static long CreateInstance(CComObject<CertEnroll::CCspStatuses> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CCspStatuses>();
	};

	struct CComObject<CertEnroll::CObjectId>
	{
		CComObject<CertEnroll::CObjectId>(void *);
		static long CreateInstance(CComObject<CertEnroll::CObjectId> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CObjectId>();
	};

	struct CComObject<CertEnroll::CObjectIds>
	{
		CComObject<CertEnroll::CObjectIds>(void *);
		static long CreateInstance(CComObject<CertEnroll::CObjectIds> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CObjectIds>();
	};

	struct CComObject<CertEnroll::CPkcs10>
	{
		CComObject<CertEnroll::CPkcs10>(void *);
		static long CreateInstance(CComObject<CertEnroll::CPkcs10> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CPkcs10>();
	};

	struct CComObject<CertEnroll::CPolicyQualifier>
	{
		CComObject<CertEnroll::CPolicyQualifier>(void *);
		static long CreateInstance(CComObject<CertEnroll::CPolicyQualifier> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CPolicyQualifier>();
	};

	struct CComObject<CertEnroll::CPolicyQualifiers>
	{
		CComObject<CertEnroll::CPolicyQualifiers>(void *);
		static long CreateInstance(CComObject<CertEnroll::CPolicyQualifiers> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CPolicyQualifiers>();
	};

	struct CComObject<CertEnroll::CSignerCertificate>
	{
		CComObject<CertEnroll::CSignerCertificate>(void *);
		static long CreateInstance(CComObject<CertEnroll::CSignerCertificate> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CSignerCertificate>();
	};

	struct CComObject<CertEnroll::CSignerCertificates>
	{
		CComObject<CertEnroll::CSignerCertificates>(void *);
		static long CreateInstance(CComObject<CertEnroll::CSignerCertificates> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CSignerCertificates>();
	};

	struct CComObject<CertEnroll::CSmimeCapabilities>
	{
		CComObject<CertEnroll::CSmimeCapabilities>(void *);
		static long CreateInstance(CComObject<CertEnroll::CSmimeCapabilities> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CSmimeCapabilities>();
	};

	struct CComObject<CertEnroll::CSmimeCapability>
	{
		CComObject<CertEnroll::CSmimeCapability>(void *);
		static long CreateInstance(CComObject<CertEnroll::CSmimeCapability> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CSmimeCapability>();
	};

	struct CComObject<CertEnroll::CX500DistinguishedName>
	{
		CComObject<CertEnroll::CX500DistinguishedName>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX500DistinguishedName> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX500DistinguishedName>();
	};

	struct CComObject<CertEnroll::CX509Attribute>
	{
		CComObject<CertEnroll::CX509Attribute>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509Attribute> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509Attribute>();
	};

	struct CComObject<CertEnroll::CX509AttributeArchiveKey>
	{
		CComObject<CertEnroll::CX509AttributeArchiveKey>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509AttributeArchiveKey> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509AttributeArchiveKey>();
	};

	struct CComObject<CertEnroll::CX509AttributeArchiveKeyHash>
	{
		CComObject<CertEnroll::CX509AttributeArchiveKeyHash>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509AttributeArchiveKeyHash> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509AttributeArchiveKeyHash>();
	};

	struct CComObject<CertEnroll::CX509AttributeClientId>
	{
		CComObject<CertEnroll::CX509AttributeClientId>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509AttributeClientId> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509AttributeClientId>();
	};

	struct CComObject<CertEnroll::CX509AttributeCspProvider>
	{
		CComObject<CertEnroll::CX509AttributeCspProvider>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509AttributeCspProvider> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509AttributeCspProvider>();
	};

	struct CComObject<CertEnroll::CX509AttributeExtensions>
	{
		CComObject<CertEnroll::CX509AttributeExtensions>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509AttributeExtensions> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509AttributeExtensions>();
	};

	struct CComObject<CertEnroll::CX509AttributeOSVersion>
	{
		CComObject<CertEnroll::CX509AttributeOSVersion>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509AttributeOSVersion> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509AttributeOSVersion>();
	};

	struct CComObject<CertEnroll::CX509AttributeRenewalCertificate>
	{
		CComObject<CertEnroll::CX509AttributeRenewalCertificate>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509AttributeRenewalCertificate> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509AttributeRenewalCertificate>();
	};

	struct CComObject<CertEnroll::CX509Attributes>
	{
		CComObject<CertEnroll::CX509Attributes>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509Attributes> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509Attributes>();
	};

	struct CComObject<CertEnroll::CX509CertificateRequestCertificate>
	{
		CComObject<CertEnroll::CX509CertificateRequestCertificate>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509CertificateRequestCertificate> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509CertificateRequestCertificate>();
	};

	struct CComObject<CertEnroll::CX509CertificateRequestCmc>
	{
		CComObject<CertEnroll::CX509CertificateRequestCmc>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509CertificateRequestCmc> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509CertificateRequestCmc>();
	};

	struct CComObject<CertEnroll::CX509CertificateRequestPkcs10>
	{
		CComObject<CertEnroll::CX509CertificateRequestPkcs10>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509CertificateRequestPkcs10> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509CertificateRequestPkcs10>();
	};

	struct CComObject<CertEnroll::CX509CertificateRequestPkcs7>
	{
		CComObject<CertEnroll::CX509CertificateRequestPkcs7>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509CertificateRequestPkcs7> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509CertificateRequestPkcs7>();
	};

	struct CComObject<CertEnroll::CX509CertificateRevocationList>
	{
		CComObject<CertEnroll::CX509CertificateRevocationList>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509CertificateRevocationList>();
	};

	struct CComObject<CertEnroll::CX509CertificateRevocationListEntries>
	{
		CComObject<CertEnroll::CX509CertificateRevocationListEntries>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509CertificateRevocationListEntries> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509CertificateRevocationListEntries>();
	};

	struct CComObject<CertEnroll::CX509CertificateRevocationListEntry>
	{
		CComObject<CertEnroll::CX509CertificateRevocationListEntry>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509CertificateRevocationListEntry> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509CertificateRevocationListEntry>();
	};

	struct CComObject<CertEnroll::CX509CertificateTemplate>
	{
		CComObject<CertEnroll::CX509CertificateTemplate>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509CertificateTemplate> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509CertificateTemplate>();
	};

	struct CComObject<CertEnroll::CX509CertificateTemplateADWritable>
	{
		CComObject<CertEnroll::CX509CertificateTemplateADWritable>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509CertificateTemplateADWritable>();
	};

	struct CComObject<CertEnroll::CX509CertificateTemplates>
	{
		CComObject<CertEnroll::CX509CertificateTemplates>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509CertificateTemplates> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509CertificateTemplates>();
	};

	struct CComObject<CertEnroll::CX509EndorsementKey>
	{
		CComObject<CertEnroll::CX509EndorsementKey>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509EndorsementKey>();
	};

	struct CComObject<CertEnroll::CX509Enrollment>
	{
		CComObject<CertEnroll::CX509Enrollment>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509Enrollment> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509Enrollment>();
	};

	struct CComObject<CertEnroll::CX509EnrollmentHelper>
	{
		CComObject<CertEnroll::CX509EnrollmentHelper>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509EnrollmentHelper> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509EnrollmentHelper>();
	};

	struct CComObject<CertEnroll::CX509EnrollmentManager>
	{
		CComObject<CertEnroll::CX509EnrollmentManager>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509EnrollmentManager> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509EnrollmentManager>();
	};

	struct CComObject<CertEnroll::CX509EnrollmentPolicyActiveDirectory>
	{
		CComObject<CertEnroll::CX509EnrollmentPolicyActiveDirectory>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509EnrollmentPolicyActiveDirectory> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509EnrollmentPolicyActiveDirectory>();
	};

	struct CComObject<CertEnroll::CX509EnrollmentStatus>
	{
		CComObject<CertEnroll::CX509EnrollmentStatus>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509EnrollmentStatus> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509EnrollmentStatus>();
	};

	struct CComObject<CertEnroll::CX509EnrollmentWebClassFactory>
	{
		CComObject<CertEnroll::CX509EnrollmentWebClassFactory>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509EnrollmentWebClassFactory>();
	};

	struct CComObject<CertEnroll::CX509Enrollments>
	{
		CComObject<CertEnroll::CX509Enrollments>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509Enrollments> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509Enrollments>();
	};

	struct CComObject<CertEnroll::CX509Extension>
	{
		CComObject<CertEnroll::CX509Extension>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509Extension> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509Extension>();
	};

	struct CComObject<CertEnroll::CX509ExtensionAlternativeNames>
	{
		CComObject<CertEnroll::CX509ExtensionAlternativeNames>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509ExtensionAlternativeNames>();
	};

	struct CComObject<CertEnroll::CX509ExtensionAuthorityKeyIdentifier>
	{
		CComObject<CertEnroll::CX509ExtensionAuthorityKeyIdentifier>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509ExtensionAuthorityKeyIdentifier>();
	};

	struct CComObject<CertEnroll::CX509ExtensionBasicConstraints>
	{
		CComObject<CertEnroll::CX509ExtensionBasicConstraints>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509ExtensionBasicConstraints> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509ExtensionBasicConstraints>();
	};

	struct CComObject<CertEnroll::CX509ExtensionCertificatePolicies>
	{
		CComObject<CertEnroll::CX509ExtensionCertificatePolicies>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509ExtensionCertificatePolicies> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509ExtensionCertificatePolicies>();
	};

	struct CComObject<CertEnroll::CX509ExtensionEnhancedKeyUsage>
	{
		CComObject<CertEnroll::CX509ExtensionEnhancedKeyUsage>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509ExtensionEnhancedKeyUsage> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509ExtensionEnhancedKeyUsage>();
	};

	struct CComObject<CertEnroll::CX509ExtensionKeyUsage>
	{
		CComObject<CertEnroll::CX509ExtensionKeyUsage>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509ExtensionKeyUsage> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509ExtensionKeyUsage>();
	};

	struct CComObject<CertEnroll::CX509ExtensionMSApplicationPolicies>
	{
		CComObject<CertEnroll::CX509ExtensionMSApplicationPolicies>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509ExtensionMSApplicationPolicies> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509ExtensionMSApplicationPolicies>();
	};

	struct CComObject<CertEnroll::CX509ExtensionSmimeCapabilities>
	{
		CComObject<CertEnroll::CX509ExtensionSmimeCapabilities>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509ExtensionSmimeCapabilities> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509ExtensionSmimeCapabilities>();
	};

	struct CComObject<CertEnroll::CX509ExtensionSubjectKeyIdentifier>
	{
		CComObject<CertEnroll::CX509ExtensionSubjectKeyIdentifier>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509ExtensionSubjectKeyIdentifier> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509ExtensionSubjectKeyIdentifier>();
	};

	struct CComObject<CertEnroll::CX509ExtensionTemplate>
	{
		CComObject<CertEnroll::CX509ExtensionTemplate>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509ExtensionTemplate> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509ExtensionTemplate>();
	};

	struct CComObject<CertEnroll::CX509ExtensionTemplateName>
	{
		CComObject<CertEnroll::CX509ExtensionTemplateName>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509ExtensionTemplateName> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509ExtensionTemplateName>();
	};

	struct CComObject<CertEnroll::CX509Extensions>
	{
		CComObject<CertEnroll::CX509Extensions>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509Extensions> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509Extensions>();
	};

	struct CComObject<CertEnroll::CX509MachineEnrollmentFactory>
	{
		CComObject<CertEnroll::CX509MachineEnrollmentFactory>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509MachineEnrollmentFactory>();
	};

	struct CComObject<CertEnroll::CX509NameValuePair>
	{
		CComObject<CertEnroll::CX509NameValuePair>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509NameValuePair> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509NameValuePair>();
	};

	struct CComObject<CertEnroll::CX509NameValuePairs>
	{
		CComObject<CertEnroll::CX509NameValuePairs>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509NameValuePairs> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509NameValuePairs>();
	};

	struct CComObject<CertEnroll::CX509PrivateKey>
	{
		CComObject<CertEnroll::CX509PrivateKey>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509PrivateKey> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509PrivateKey>();
	};

	struct CComObject<CertEnroll::CX509PublicKey>
	{
		CComObject<CertEnroll::CX509PublicKey>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509PublicKey> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509PublicKey>();
	};

	struct CComObject<CertEnroll::CX509SCEPEnrollment>
	{
		CComObject<CertEnroll::CX509SCEPEnrollment>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509SCEPEnrollment>();
	};

	struct CComObject<CertEnroll::CX509SCEPEnrollmentHelper>
	{
		CComObject<CertEnroll::CX509SCEPEnrollmentHelper>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509SCEPEnrollmentHelper>();
	};

	struct CComObject<CertEnroll::CX509SignatureInformation>
	{
		CComObject<CertEnroll::CX509SignatureInformation>(void *);
		static long CreateInstance(CComObject<CertEnroll::CX509SignatureInformation> * *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObject<CertEnroll::CX509SignatureInformation>();
	};

	struct CComObjectCached<CComClassFactory>
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
	};

	struct CComObjectRootBase
	{
		static _ATL_CATMAP_ENTRY const * GetCategoryMap();
		static void ObjectMain(bool);
		~CComObjectRootBase();
	};

	struct CComObjectRootEx<CComMultiThreadModel>
	{
		~CComObjectRootEx<CComMultiThreadModel>();
	};

	struct CComObjectStack<CX509PolicyServerListManager>
	{
		CComObjectStack<CX509PolicyServerListManager>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObjectStack<CX509PolicyServerListManager>();
	};

	struct CComObjectStack<CertEnroll::CCertPropertyEnrollmentPolicyServer>
	{
		CComObjectStack<CertEnroll::CCertPropertyEnrollmentPolicyServer>(void *);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		virtual ~CComObjectStack<CertEnroll::CCertPropertyEnrollmentPolicyServer>();
	};

	struct CComPtr<IAlternativeName>
	{
		CComPtr<IAlternativeName>(CComPtr<IAlternativeName> const &);
		~CComPtr<IAlternativeName>();
	};

	struct CComPtr<IAlternativeNameInternal>
	{
		~CComPtr<IAlternativeNameInternal>();
	};

	struct CComPtr<IAlternativeNames>
	{
		~CComPtr<IAlternativeNames>();
	};

	struct CComPtr<IAlternativeNamesInternal>
	{
		~CComPtr<IAlternativeNamesInternal>();
	};

	struct CComPtr<ICAStatus>
	{
		CComPtr<ICAStatus>(CComPtr<ICAStatus> const &);
		~CComPtr<ICAStatus>();
	};

	struct CComPtr<ICAStatuses>
	{
		~CComPtr<ICAStatuses>();
	};

	struct CComPtr<ICatRegister>
	{
		~CComPtr<ICatRegister>();
	};

	struct CComPtr<ICertProperties>
	{
		~CComPtr<ICertProperties>();
	};

	struct CComPtr<ICertProperty>
	{
		CComPtr<ICertProperty>(CComPtr<ICertProperty> const &);
		~CComPtr<ICertProperty>();
	};

	struct CComPtr<ICertPropertyArchived>
	{
		~CComPtr<ICertPropertyArchived>();
	};

	struct CComPtr<ICertPropertyArchivedKeyHash>
	{
		~CComPtr<ICertPropertyArchivedKeyHash>();
	};

	struct CComPtr<ICertPropertyDescription>
	{
		~CComPtr<ICertPropertyDescription>();
	};

	struct CComPtr<ICertPropertyEnrollmentPolicyServer>
	{
		~CComPtr<ICertPropertyEnrollmentPolicyServer>();
	};

	struct CComPtr<ICertPropertyFriendlyName>
	{
		~CComPtr<ICertPropertyFriendlyName>();
	};

	struct CComPtr<ICertPropertyInternal>
	{
		~CComPtr<ICertPropertyInternal>();
	};

	struct CComPtr<ICertPropertyKeyProvInfo>
	{
		~CComPtr<ICertPropertyKeyProvInfo>();
	};

	struct CComPtr<ICertPropertyRenewal>
	{
		~CComPtr<ICertPropertyRenewal>();
	};

	struct CComPtr<ICertRequest2>
	{
		~CComPtr<ICertRequest2>();
	};

	struct CComPtr<ICertRequest3>
	{
		~CComPtr<ICertRequest3>();
	};

	struct CComPtr<ICertificateAttestationChallenge2>
	{
		~CComPtr<ICertificateAttestationChallenge2>();
	};

	struct CComPtr<ICertificateAttestationChallenge>
	{
		~CComPtr<ICertificateAttestationChallenge>();
	};

	struct CComPtr<ICertificatePolicies>
	{
		~CComPtr<ICertificatePolicies>();
	};

	struct CComPtr<ICertificatePoliciesInternal>
	{
		~CComPtr<ICertificatePoliciesInternal>();
	};

	struct CComPtr<ICertificatePolicy>
	{
		CComPtr<ICertificatePolicy>(CComPtr<ICertificatePolicy> const &);
		~CComPtr<ICertificatePolicy>();
	};

	struct CComPtr<ICertificatePolicyInternal>
	{
		~CComPtr<ICertificatePolicyInternal>();
	};

	struct CComPtr<ICertificationAuthorities>
	{
		~CComPtr<ICertificationAuthorities>();
	};

	struct CComPtr<ICertificationAuthority>
	{
		CComPtr<ICertificationAuthority>(CComPtr<ICertificationAuthority> const &);
		~CComPtr<ICertificationAuthority>();
	};

	struct CComPtr<ICertificationAuthorityInternal>
	{
		~CComPtr<ICertificationAuthorityInternal>();
	};

	struct CComPtr<ICryptAttribute>
	{
		CComPtr<ICryptAttribute>(CComPtr<ICryptAttribute> const &);
		~CComPtr<ICryptAttribute>();
	};

	struct CComPtr<ICryptAttributeInternal>
	{
		~CComPtr<ICryptAttributeInternal>();
	};

	struct CComPtr<ICryptAttributes>
	{
		~CComPtr<ICryptAttributes>();
	};

	struct CComPtr<ICryptAttributesInternal>
	{
		~CComPtr<ICryptAttributesInternal>();
	};

	struct CComPtr<ICspAlgorithm>
	{
		CComPtr<ICspAlgorithm>(CComPtr<ICspAlgorithm> const &);
		~CComPtr<ICspAlgorithm>();
	};

	struct CComPtr<ICspAlgorithmInternal>
	{
		~CComPtr<ICspAlgorithmInternal>();
	};

	struct CComPtr<ICspAlgorithms>
	{
		~CComPtr<ICspAlgorithms>();
	};

	struct CComPtr<ICspAlgorithmsInternal>
	{
		~CComPtr<ICspAlgorithmsInternal>();
	};

	struct CComPtr<ICspInformation>
	{
		CComPtr<ICspInformation>(CComPtr<ICspInformation> const &);
		~CComPtr<ICspInformation>();
	};

	struct CComPtr<ICspInformationInternal>
	{
		~CComPtr<ICspInformationInternal>();
	};

	struct CComPtr<ICspInformations>
	{
		~CComPtr<ICspInformations>();
	};

	struct CComPtr<ICspStatus>
	{
		CComPtr<ICspStatus>(CComPtr<ICspStatus> const &);
		~CComPtr<ICspStatus>();
	};

	struct CComPtr<ICspStatuses>
	{
		CComPtr<ICspStatuses>();
		~CComPtr<ICspStatuses>();
	};

	struct CComPtr<IHTMLDocument2>
	{
		~CComPtr<IHTMLDocument2>();
	};

	struct CComPtr<IInternetSecurityManager>
	{
		~CComPtr<IInternetSecurityManager>();
	};

	struct CComPtr<IObjectId>
	{
		CComPtr<IObjectId>();
		CComPtr<IObjectId>(CComPtr<IObjectId> const &);
		~CComPtr<IObjectId>();
	};

	struct CComPtr<IObjectIdInternal>
	{
		~CComPtr<IObjectIdInternal>();
	};

	struct CComPtr<IObjectIds>
	{
		~CComPtr<IObjectIds>();
	};

	struct CComPtr<IOleClientSite>
	{
		~CComPtr<IOleClientSite>();
	};

	struct CComPtr<IOleContainer>
	{
		~CComPtr<IOleContainer>();
	};

	struct CComPtr<IPkcs10>
	{
		~CComPtr<IPkcs10>();
	};

	struct CComPtr<IPolicyQualifier>
	{
		CComPtr<IPolicyQualifier>(CComPtr<IPolicyQualifier> const &);
		~CComPtr<IPolicyQualifier>();
	};

	struct CComPtr<IPolicyQualifierInternal>
	{
		~CComPtr<IPolicyQualifierInternal>();
	};

	struct CComPtr<IPolicyQualifiers>
	{
		~CComPtr<IPolicyQualifiers>();
	};

	struct CComPtr<IServiceProvider>
	{
		~CComPtr<IServiceProvider>();
	};

	struct CComPtr<ISignerCertificate>
	{
		CComPtr<ISignerCertificate>(CComPtr<ISignerCertificate> const &);
		~CComPtr<ISignerCertificate>();
	};

	struct CComPtr<ISignerCertificateInternal>
	{
		~CComPtr<ISignerCertificateInternal>();
	};

	struct CComPtr<ISignerCertificates>
	{
		~CComPtr<ISignerCertificates>();
	};

	struct CComPtr<ISmimeCapabilities>
	{
		~CComPtr<ISmimeCapabilities>();
	};

	struct CComPtr<ISmimeCapabilitiesInternal>
	{
		~CComPtr<ISmimeCapabilitiesInternal>();
	};

	struct CComPtr<ISmimeCapability>
	{
		CComPtr<ISmimeCapability>(CComPtr<ISmimeCapability> const &);
		~CComPtr<ISmimeCapability>();
	};

	struct CComPtr<ISmimeCapabilityInternal>
	{
		~CComPtr<ISmimeCapabilityInternal>();
	};

	struct CComPtr<ITypeInfo2>
	{
		~CComPtr<ITypeInfo2>();
	};

	struct CComPtr<ITypeInfo>
	{
		~CComPtr<ITypeInfo>();
	};

	struct CComPtr<ITypeLib>
	{
		~CComPtr<ITypeLib>();
	};

	struct CComPtr<IUnknown>
	{
		~CComPtr<IUnknown>();
	};

	struct CComPtr<IWebBrowser2>
	{
		~CComPtr<IWebBrowser2>();
	};

	struct CComPtr<IX500DistinguishedName>
	{
		~CComPtr<IX500DistinguishedName>();
	};

	struct CComPtr<IX509Attribute>
	{
		CComPtr<IX509Attribute>(CComPtr<IX509Attribute> const &);
		~CComPtr<IX509Attribute>();
	};

	struct CComPtr<IX509AttributeArchiveKey>
	{
		~CComPtr<IX509AttributeArchiveKey>();
	};

	struct CComPtr<IX509AttributeArchiveKeyHash>
	{
		~CComPtr<IX509AttributeArchiveKeyHash>();
	};

	struct CComPtr<IX509Attributes>
	{
		~CComPtr<IX509Attributes>();
	};

	struct CComPtr<IX509CertificateRequest>
	{
		~CComPtr<IX509CertificateRequest>();
	};

	struct CComPtr<IX509CertificateRequestCmc2>
	{
		~CComPtr<IX509CertificateRequestCmc2>();
	};

	struct CComPtr<IX509CertificateRequestCmc>
	{
		~CComPtr<IX509CertificateRequestCmc>();
	};

	struct CComPtr<IX509CertificateRequestInternal>
	{
		~CComPtr<IX509CertificateRequestInternal>();
	};

	struct CComPtr<IX509CertificateRequestPkcs10>
	{
		~CComPtr<IX509CertificateRequestPkcs10>();
	};

	struct CComPtr<IX509CertificateRequestPkcs10Internal>
	{
		~CComPtr<IX509CertificateRequestPkcs10Internal>();
	};

	struct CComPtr<IX509CertificateRequestPkcs10V3>
	{
		~CComPtr<IX509CertificateRequestPkcs10V3>();
	};

	struct CComPtr<IX509CertificateRequestPkcs10V4>
	{
		~CComPtr<IX509CertificateRequestPkcs10V4>();
	};

	struct CComPtr<IX509CertificateRequestPkcs7>
	{
		~CComPtr<IX509CertificateRequestPkcs7>();
	};

	struct CComPtr<IX509CertificateRequestPkcs7Internal>
	{
		~CComPtr<IX509CertificateRequestPkcs7Internal>();
	};

	struct CComPtr<IX509CertificateRevocationListEntries>
	{
		~CComPtr<IX509CertificateRevocationListEntries>();
	};

	struct CComPtr<IX509CertificateRevocationListEntry>
	{
		CComPtr<IX509CertificateRevocationListEntry>(CComPtr<IX509CertificateRevocationListEntry> const &);
		~CComPtr<IX509CertificateRevocationListEntry>();
	};

	struct CComPtr<IX509CertificateTemplate>
	{
		CComPtr<IX509CertificateTemplate>(CComPtr<IX509CertificateTemplate> const &);
		~CComPtr<IX509CertificateTemplate>();
	};

	struct CComPtr<IX509CertificateTemplateInternal>
	{
		CComPtr<IX509CertificateTemplateInternal>(CComPtr<IX509CertificateTemplateInternal> const &);
		~CComPtr<IX509CertificateTemplateInternal>();
	};

	struct CComPtr<IX509CertificateTemplates>
	{
		~CComPtr<IX509CertificateTemplates>();
	};

	struct CComPtr<IX509Enrollment2>
	{
		~CComPtr<IX509Enrollment2>();
	};

	struct CComPtr<IX509Enrollment>
	{
		CComPtr<IX509Enrollment>(CComPtr<IX509Enrollment> const &);
		~CComPtr<IX509Enrollment>();
	};

	struct CComPtr<IX509EnrollmentInternal>
	{
		~CComPtr<IX509EnrollmentInternal>();
	};

	struct CComPtr<IX509EnrollmentPolicyServer>
	{
		CComPtr<IX509EnrollmentPolicyServer>(CComPtr<IX509EnrollmentPolicyServer> const &);
		~CComPtr<IX509EnrollmentPolicyServer>();
	};

	struct CComPtr<IX509EnrollmentPolicyServerInternal>
	{
		~CComPtr<IX509EnrollmentPolicyServerInternal>();
	};

	struct CComPtr<IX509EnrollmentStatus>
	{
		~CComPtr<IX509EnrollmentStatus>();
	};

	struct CComPtr<IX509Enrollments>
	{
		~CComPtr<IX509Enrollments>();
	};

	struct CComPtr<IX509Extension>
	{
		CComPtr<IX509Extension>(CComPtr<IX509Extension> const &);
		~CComPtr<IX509Extension>();
	};

	struct CComPtr<IX509ExtensionAlternativeNames>
	{
		~CComPtr<IX509ExtensionAlternativeNames>();
	};

	struct CComPtr<IX509ExtensionAuthorityKeyIdentifier>
	{
		~CComPtr<IX509ExtensionAuthorityKeyIdentifier>();
	};

	struct CComPtr<IX509ExtensionInternal>
	{
		~CComPtr<IX509ExtensionInternal>();
	};

	struct CComPtr<IX509Extensions>
	{
		~CComPtr<IX509Extensions>();
	};

	struct CComPtr<IX509ExtensionsInternal>
	{
		~CComPtr<IX509ExtensionsInternal>();
	};

	struct CComPtr<IX509NameValuePair>
	{
		CComPtr<IX509NameValuePair>(CComPtr<IX509NameValuePair> const &);
		~CComPtr<IX509NameValuePair>();
	};

	struct CComPtr<IX509NameValuePairs>
	{
		~CComPtr<IX509NameValuePairs>();
	};

	struct CComPtr<IX509PolicyServerUrl>
	{
		CComPtr<IX509PolicyServerUrl>(CComPtr<IX509PolicyServerUrl> const &);
		~CComPtr<IX509PolicyServerUrl>();
	};

	struct CComPtr<IX509PolicyServerUrlInternal>
	{
		~CComPtr<IX509PolicyServerUrlInternal>();
	};

	struct CComPtr<IX509PrivateKey2>
	{
		~CComPtr<IX509PrivateKey2>();
	};

	struct CComPtr<IX509PrivateKey>
	{
		~CComPtr<IX509PrivateKey>();
	};

	struct CComPtr<IX509PrivateKeyInternal>
	{
		~CComPtr<IX509PrivateKeyInternal>();
	};

	struct CComPtr<IX509PublicKey>
	{
		~CComPtr<IX509PublicKey>();
	};

	struct CComPtr<IX509SCEPEnrollment2>
	{
		~CComPtr<IX509SCEPEnrollment2>();
	};

	struct CComPtr<IX509SCEPEnrollment>
	{
		~CComPtr<IX509SCEPEnrollment>();
	};

	struct CComPtr<IX509SCEPEnrollmentHelper>
	{
		~CComPtr<IX509SCEPEnrollmentHelper>();
	};

	struct CComPtr<IX509SCEPEnrollmentHelperInternal>
	{
		~CComPtr<IX509SCEPEnrollmentHelperInternal>();
	};

	struct CComPtr<IX509SCEPEnrollmentInternal>
	{
		~CComPtr<IX509SCEPEnrollmentInternal>();
	};

	struct CComPtr<IX509SignatureInformation>
	{
		~CComPtr<IX509SignatureInformation>();
	};

	struct CComPtrBase<IAlternativeName>
	{
		~CComPtrBase<IAlternativeName>();
	};

	struct CComPtrBase<IAlternativeNameInternal>
	{
		~CComPtrBase<IAlternativeNameInternal>();
	};

	struct CComPtrBase<IAlternativeNames>
	{
		~CComPtrBase<IAlternativeNames>();
	};

	struct CComPtrBase<IAlternativeNamesInternal>
	{
		~CComPtrBase<IAlternativeNamesInternal>();
	};

	struct CComPtrBase<ICAStatus>
	{
		~CComPtrBase<ICAStatus>();
	};

	struct CComPtrBase<ICAStatuses>
	{
		~CComPtrBase<ICAStatuses>();
	};

	struct CComPtrBase<ICatRegister>
	{
		~CComPtrBase<ICatRegister>();
	};

	struct CComPtrBase<ICertProperties>
	{
		~CComPtrBase<ICertProperties>();
	};

	struct CComPtrBase<ICertProperty>
	{
		~CComPtrBase<ICertProperty>();
	};

	struct CComPtrBase<ICertPropertyArchived>
	{
		~CComPtrBase<ICertPropertyArchived>();
	};

	struct CComPtrBase<ICertPropertyArchivedKeyHash>
	{
		~CComPtrBase<ICertPropertyArchivedKeyHash>();
	};

	struct CComPtrBase<ICertPropertyDescription>
	{
		~CComPtrBase<ICertPropertyDescription>();
	};

	struct CComPtrBase<ICertPropertyEnrollmentPolicyServer>
	{
		~CComPtrBase<ICertPropertyEnrollmentPolicyServer>();
	};

	struct CComPtrBase<ICertPropertyFriendlyName>
	{
		~CComPtrBase<ICertPropertyFriendlyName>();
	};

	struct CComPtrBase<ICertPropertyInternal>
	{
		~CComPtrBase<ICertPropertyInternal>();
	};

	struct CComPtrBase<ICertPropertyKeyProvInfo>
	{
		~CComPtrBase<ICertPropertyKeyProvInfo>();
	};

	struct CComPtrBase<ICertPropertyRenewal>
	{
		~CComPtrBase<ICertPropertyRenewal>();
	};

	struct CComPtrBase<ICertRequest2>
	{
		~CComPtrBase<ICertRequest2>();
	};

	struct CComPtrBase<ICertRequest3>
	{
		~CComPtrBase<ICertRequest3>();
	};

	struct CComPtrBase<ICertificateAttestationChallenge2>
	{
		~CComPtrBase<ICertificateAttestationChallenge2>();
	};

	struct CComPtrBase<ICertificateAttestationChallenge>
	{
		~CComPtrBase<ICertificateAttestationChallenge>();
	};

	struct CComPtrBase<ICertificatePolicies>
	{
		~CComPtrBase<ICertificatePolicies>();
	};

	struct CComPtrBase<ICertificatePoliciesInternal>
	{
		~CComPtrBase<ICertificatePoliciesInternal>();
	};

	struct CComPtrBase<ICertificatePolicy>
	{
		~CComPtrBase<ICertificatePolicy>();
	};

	struct CComPtrBase<ICertificatePolicyInternal>
	{
		~CComPtrBase<ICertificatePolicyInternal>();
	};

	struct CComPtrBase<ICertificationAuthorities>
	{
		~CComPtrBase<ICertificationAuthorities>();
	};

	struct CComPtrBase<ICertificationAuthority>
	{
		~CComPtrBase<ICertificationAuthority>();
	};

	class CComPtrBase<ICertificationAuthorityInternal>
	{
	protected:
		CComPtrBase<ICertificationAuthorityInternal>(ICertificationAuthorityInternal *);
	public:
		~CComPtrBase<ICertificationAuthorityInternal>();
	};

	struct CComPtrBase<ICryptAttribute>
	{
		~CComPtrBase<ICryptAttribute>();
	};

	struct CComPtrBase<ICryptAttributeInternal>
	{
		~CComPtrBase<ICryptAttributeInternal>();
	};

	struct CComPtrBase<ICryptAttributes>
	{
		~CComPtrBase<ICryptAttributes>();
	};

	struct CComPtrBase<ICryptAttributesInternal>
	{
		~CComPtrBase<ICryptAttributesInternal>();
	};

	struct CComPtrBase<ICspAlgorithm>
	{
		~CComPtrBase<ICspAlgorithm>();
	};

	struct CComPtrBase<ICspAlgorithmInternal>
	{
		~CComPtrBase<ICspAlgorithmInternal>();
	};

	struct CComPtrBase<ICspAlgorithms>
	{
		~CComPtrBase<ICspAlgorithms>();
	};

	struct CComPtrBase<ICspAlgorithmsInternal>
	{
		~CComPtrBase<ICspAlgorithmsInternal>();
	};

	struct CComPtrBase<ICspInformation>
	{
		~CComPtrBase<ICspInformation>();
	};

	struct CComPtrBase<ICspInformationInternal>
	{
		~CComPtrBase<ICspInformationInternal>();
	};

	struct CComPtrBase<ICspInformations>
	{
		~CComPtrBase<ICspInformations>();
	};

	struct CComPtrBase<ICspStatus>
	{
		~CComPtrBase<ICspStatus>();
	};

	struct CComPtrBase<ICspStatuses>
	{
		~CComPtrBase<ICspStatuses>();
	};

	struct CComPtrBase<IHTMLDocument2>
	{
		~CComPtrBase<IHTMLDocument2>();
	};

	struct CComPtrBase<IInternetSecurityManager>
	{
		~CComPtrBase<IInternetSecurityManager>();
	};

	struct CComPtrBase<IObjectId>
	{
		~CComPtrBase<IObjectId>();
	};

	struct CComPtrBase<IObjectIdInternal>
	{
		~CComPtrBase<IObjectIdInternal>();
	};

	struct CComPtrBase<IObjectIds>
	{
		~CComPtrBase<IObjectIds>();
	};

	struct CComPtrBase<IOleClientSite>
	{
		~CComPtrBase<IOleClientSite>();
	};

	struct CComPtrBase<IOleContainer>
	{
		~CComPtrBase<IOleContainer>();
	};

	struct CComPtrBase<IPkcs10>
	{
		~CComPtrBase<IPkcs10>();
	};

	struct CComPtrBase<IPolicyQualifier>
	{
		~CComPtrBase<IPolicyQualifier>();
	};

	struct CComPtrBase<IPolicyQualifierInternal>
	{
		~CComPtrBase<IPolicyQualifierInternal>();
	};

	struct CComPtrBase<IPolicyQualifiers>
	{
		~CComPtrBase<IPolicyQualifiers>();
	};

	struct CComPtrBase<IServiceProvider>
	{
		~CComPtrBase<IServiceProvider>();
	};

	struct CComPtrBase<ISignerCertificate>
	{
		~CComPtrBase<ISignerCertificate>();
	};

	struct CComPtrBase<ISignerCertificateInternal>
	{
		~CComPtrBase<ISignerCertificateInternal>();
	};

	struct CComPtrBase<ISignerCertificates>
	{
		~CComPtrBase<ISignerCertificates>();
	};

	struct CComPtrBase<ISmimeCapabilities>
	{
		~CComPtrBase<ISmimeCapabilities>();
	};

	struct CComPtrBase<ISmimeCapabilitiesInternal>
	{
		~CComPtrBase<ISmimeCapabilitiesInternal>();
	};

	struct CComPtrBase<ISmimeCapability>
	{
		~CComPtrBase<ISmimeCapability>();
	};

	struct CComPtrBase<ISmimeCapabilityInternal>
	{
		~CComPtrBase<ISmimeCapabilityInternal>();
	};

	struct CComPtrBase<ITypeInfo2>
	{
		~CComPtrBase<ITypeInfo2>();
	};

	struct CComPtrBase<ITypeInfo>
	{
		bool IsEqualObject(IUnknown *);
		~CComPtrBase<ITypeInfo>();
	};

	struct CComPtrBase<ITypeLib>
	{
		~CComPtrBase<ITypeLib>();
	};

	struct CComPtrBase<IUnknown>
	{
		~CComPtrBase<IUnknown>();
	};

	struct CComPtrBase<IWebBrowser2>
	{
		~CComPtrBase<IWebBrowser2>();
	};

	struct CComPtrBase<IX500DistinguishedName>
	{
		~CComPtrBase<IX500DistinguishedName>();
	};

	struct CComPtrBase<IX509Attribute>
	{
		~CComPtrBase<IX509Attribute>();
	};

	struct CComPtrBase<IX509AttributeArchiveKey>
	{
		~CComPtrBase<IX509AttributeArchiveKey>();
	};

	struct CComPtrBase<IX509AttributeArchiveKeyHash>
	{
		~CComPtrBase<IX509AttributeArchiveKeyHash>();
	};

	struct CComPtrBase<IX509Attributes>
	{
		~CComPtrBase<IX509Attributes>();
	};

	struct CComPtrBase<IX509CertificateRequest>
	{
		~CComPtrBase<IX509CertificateRequest>();
	};

	struct CComPtrBase<IX509CertificateRequestCmc2>
	{
		~CComPtrBase<IX509CertificateRequestCmc2>();
	};

	struct CComPtrBase<IX509CertificateRequestCmc>
	{
		~CComPtrBase<IX509CertificateRequestCmc>();
	};

	struct CComPtrBase<IX509CertificateRequestInternal>
	{
		~CComPtrBase<IX509CertificateRequestInternal>();
	};

	struct CComPtrBase<IX509CertificateRequestPkcs10>
	{
		bool IsEqualObject(IUnknown *);
		~CComPtrBase<IX509CertificateRequestPkcs10>();
	};

	struct CComPtrBase<IX509CertificateRequestPkcs10Internal>
	{
		~CComPtrBase<IX509CertificateRequestPkcs10Internal>();
	};

	struct CComPtrBase<IX509CertificateRequestPkcs10V3>
	{
		~CComPtrBase<IX509CertificateRequestPkcs10V3>();
	};

	struct CComPtrBase<IX509CertificateRequestPkcs10V4>
	{
		~CComPtrBase<IX509CertificateRequestPkcs10V4>();
	};

	struct CComPtrBase<IX509CertificateRequestPkcs7>
	{
		~CComPtrBase<IX509CertificateRequestPkcs7>();
	};

	struct CComPtrBase<IX509CertificateRequestPkcs7Internal>
	{
		~CComPtrBase<IX509CertificateRequestPkcs7Internal>();
	};

	struct CComPtrBase<IX509CertificateRevocationListEntries>
	{
		~CComPtrBase<IX509CertificateRevocationListEntries>();
	};

	struct CComPtrBase<IX509CertificateRevocationListEntry>
	{
		~CComPtrBase<IX509CertificateRevocationListEntry>();
	};

	class CComPtrBase<IX509CertificateTemplate>
	{
	protected:
		CComPtrBase<IX509CertificateTemplate>(IX509CertificateTemplate *);
	public:
		~CComPtrBase<IX509CertificateTemplate>();
	};

	struct CComPtrBase<IX509CertificateTemplateInternal>
	{
		~CComPtrBase<IX509CertificateTemplateInternal>();
	};

	struct CComPtrBase<IX509CertificateTemplates>
	{
		~CComPtrBase<IX509CertificateTemplates>();
	};

	struct CComPtrBase<IX509Enrollment2>
	{
		~CComPtrBase<IX509Enrollment2>();
	};

	struct CComPtrBase<IX509Enrollment>
	{
		void Attach(IX509Enrollment *);
		~CComPtrBase<IX509Enrollment>();
	};

	struct CComPtrBase<IX509EnrollmentInternal>
	{
		~CComPtrBase<IX509EnrollmentInternal>();
	};

	class CComPtrBase<IX509EnrollmentPolicyServer>
	{
	protected:
		CComPtrBase<IX509EnrollmentPolicyServer>(IX509EnrollmentPolicyServer *);
	public:
		~CComPtrBase<IX509EnrollmentPolicyServer>();
	};

	struct CComPtrBase<IX509EnrollmentPolicyServerInternal>
	{
		~CComPtrBase<IX509EnrollmentPolicyServerInternal>();
	};

	struct CComPtrBase<IX509EnrollmentStatus>
	{
		~CComPtrBase<IX509EnrollmentStatus>();
	};

	struct CComPtrBase<IX509Enrollments>
	{
		~CComPtrBase<IX509Enrollments>();
	};

	struct CComPtrBase<IX509Extension>
	{
		~CComPtrBase<IX509Extension>();
	};

	struct CComPtrBase<IX509ExtensionAlternativeNames>
	{
		~CComPtrBase<IX509ExtensionAlternativeNames>();
	};

	struct CComPtrBase<IX509ExtensionAuthorityKeyIdentifier>
	{
		~CComPtrBase<IX509ExtensionAuthorityKeyIdentifier>();
	};

	struct CComPtrBase<IX509ExtensionInternal>
	{
		~CComPtrBase<IX509ExtensionInternal>();
	};

	struct CComPtrBase<IX509Extensions>
	{
		~CComPtrBase<IX509Extensions>();
	};

	struct CComPtrBase<IX509ExtensionsInternal>
	{
		~CComPtrBase<IX509ExtensionsInternal>();
	};

	struct CComPtrBase<IX509NameValuePair>
	{
		~CComPtrBase<IX509NameValuePair>();
	};

	struct CComPtrBase<IX509NameValuePairs>
	{
		~CComPtrBase<IX509NameValuePairs>();
	};

	class CComPtrBase<IX509PolicyServerUrl>
	{
	protected:
		CComPtrBase<IX509PolicyServerUrl>(IX509PolicyServerUrl *);
	public:
		~CComPtrBase<IX509PolicyServerUrl>();
	};

	struct CComPtrBase<IX509PolicyServerUrlInternal>
	{
		~CComPtrBase<IX509PolicyServerUrlInternal>();
	};

	struct CComPtrBase<IX509PrivateKey2>
	{
		~CComPtrBase<IX509PrivateKey2>();
	};

	struct CComPtrBase<IX509PrivateKey>
	{
		~CComPtrBase<IX509PrivateKey>();
	};

	struct CComPtrBase<IX509PrivateKeyInternal>
	{
		~CComPtrBase<IX509PrivateKeyInternal>();
	};

	struct CComPtrBase<IX509PublicKey>
	{
		~CComPtrBase<IX509PublicKey>();
	};

	struct CComPtrBase<IX509SCEPEnrollment2>
	{
		~CComPtrBase<IX509SCEPEnrollment2>();
	};

	struct CComPtrBase<IX509SCEPEnrollment>
	{
		~CComPtrBase<IX509SCEPEnrollment>();
	};

	struct CComPtrBase<IX509SCEPEnrollmentHelper>
	{
		~CComPtrBase<IX509SCEPEnrollmentHelper>();
	};

	struct CComPtrBase<IX509SCEPEnrollmentHelperInternal>
	{
		~CComPtrBase<IX509SCEPEnrollmentHelperInternal>();
	};

	struct CComPtrBase<IX509SCEPEnrollmentInternal>
	{
		~CComPtrBase<IX509SCEPEnrollmentInternal>();
	};

	struct CComPtrBase<IX509SignatureInformation>
	{
		~CComPtrBase<IX509SignatureInformation>();
	};

	struct CComSafeDeleteCriticalSection
	{
		~CComSafeDeleteCriticalSection();
	};

	struct CComTypeInfoHolder
	{
		struct stringdispid
		{
			stringdispid();
			~stringdispid();
		};

		long GetIDsOfNames(_GUID const &,unsigned short * *,unsigned int,unsigned long,long *);
		long GetTI(unsigned long);
		long GetTI(unsigned long,ITypeInfo * *);
		long Invoke(IDispatch *,long,_GUID const &,unsigned long,unsigned short,tagDISPPARAMS *,tagVARIANT *,tagEXCEPINFO *,unsigned int *);
		long LoadNameCache(ITypeInfo *);
		static void Cleanup(unsigned __int64);
	};

	struct CComVariant
	{
		CComVariant(IDispatch *);
		long Detach(tagVARIANT *);
		~CComVariant();
	};

	struct CExpansionVector
	{
		int Add(unsigned short const *,unsigned short const *);
		long ClearReplacements();
		~CExpansionVector();
	};

	struct CRegKey
	{
		long Close();
		long Create(HKEY__ *,unsigned short const *,unsigned short *,unsigned long,unsigned long,_SECURITY_ATTRIBUTES *,unsigned long *);
		long DeleteSubKey(unsigned short const *);
		long Open(HKEY__ *,unsigned short const *,unsigned long);
		long QueryDWORDValue(unsigned short const *,unsigned long &);
		long QueryStringValue(unsigned short const *,unsigned short *,unsigned long *);
		long RecurseDeleteKey(unsigned short const *);
		long SetKeyValue(unsigned short const *,unsigned short const *,unsigned short const *);
		long SetMultiStringValue(unsigned short const *,unsigned short const *);
		long SetStringValue(unsigned short const *,unsigned short const *,unsigned long);
		~CRegKey();
	};

	class CRegObject
	{
	protected:
		long RegisterFromResource(unsigned short const *,unsigned short const *,unsigned short const *,int);
	public:
		CRegObject();
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

	struct CSimpleArray<CComBSTR,CSimpleArrayEqualHelper<CComBSTR> >
	{
		struct Wrapper
		{
			static void operator delete<CComBSTR>(void *,CComBSTR *);
		};

		int Add(CComBSTR const &);
		~CSimpleArray<CComBSTR,CSimpleArrayEqualHelper<CComBSTR> >();
	};

	struct CSimpleArray<CComPtr<ICertificationAuthorityInternal>,CSimpleArrayEqualHelper<CComPtr<ICertificationAuthorityInternal> > >
	{
		struct Wrapper
		{
			static void operator delete<CComPtr<ICertificationAuthorityInternal> >(void *,CComPtr<ICertificationAuthorityInternal> *);
		};

		int Add(CComPtr<ICertificationAuthorityInternal> const &);
		void RemoveAll();
		~CSimpleArray<CComPtr<ICertificationAuthorityInternal>,CSimpleArrayEqualHelper<CComPtr<ICertificationAuthorityInternal> > >();
	};

	struct CSimpleArray<CComPtr<IX509CertificateTemplateInternal>,CSimpleArrayEqualHelper<CComPtr<IX509CertificateTemplateInternal> > >
	{
		struct Wrapper
		{
			static void operator delete<CComPtr<IX509CertificateTemplateInternal> >(void *,CComPtr<IX509CertificateTemplateInternal> *);
		};

		CComPtr<IX509CertificateTemplateInternal> & operator[](int);
		int Add(CComPtr<IX509CertificateTemplateInternal> const &);
		void RemoveAll();
		~CSimpleArray<CComPtr<IX509CertificateTemplateInternal>,CSimpleArrayEqualHelper<CComPtr<IX509CertificateTemplateInternal> > >();
	};

	struct CSimpleArray<CComPtr<IX509EnrollmentPolicyServer>,CSimpleArrayEqualHelper<CComPtr<IX509EnrollmentPolicyServer> > >
	{
		struct Wrapper
		{
			static void operator delete<CComPtr<IX509EnrollmentPolicyServer> >(void *,CComPtr<IX509EnrollmentPolicyServer> *);
		};

		CComPtr<IX509EnrollmentPolicyServer> & operator[](int);
		int Add(CComPtr<IX509EnrollmentPolicyServer> const &);
		~CSimpleArray<CComPtr<IX509EnrollmentPolicyServer>,CSimpleArrayEqualHelper<CComPtr<IX509EnrollmentPolicyServer> > >();
	};

	struct CSimpleArray<CComPtr<IX509PolicyServerUrl>,CSimpleArrayEqualHelper<CComPtr<IX509PolicyServerUrl> > >
	{
		struct Wrapper
		{
			static void operator delete<CComPtr<IX509PolicyServerUrl> >(void *,CComPtr<IX509PolicyServerUrl> *);
		};

		CComPtr<IX509PolicyServerUrl> & operator[](int);
		CComPtr<IX509PolicyServerUrl> const & operator[](int);
		int Add(CComPtr<IX509PolicyServerUrl> const &);
		~CSimpleArray<CComPtr<IX509PolicyServerUrl>,CSimpleArrayEqualHelper<CComPtr<IX509PolicyServerUrl> > >();
	};

	struct CSimpleArray<CEPTemplate,CSimpleArrayEqualHelper<CEPTemplate> >
	{
		struct Wrapper
		{
			static void operator delete<CEPTemplate>(void *,CEPTemplate *);
		};

		CEPTemplate & operator[](int);
		int Add(CEPTemplate const &);
		~CSimpleArray<CEPTemplate,CSimpleArrayEqualHelper<CEPTemplate> >();
	};

	struct CSimpleArray<CX509PolicyServerListManager::PolicyServerConfig,CSimpleArrayEqualHelper<CX509PolicyServerListManager::PolicyServerConfig> >
	{
		struct Wrapper
		{
			static void operator delete<CX509PolicyServerListManager::PolicyServerConfig>(void *,CX509PolicyServerListManager::PolicyServerConfig *);
		};

		CX509PolicyServerListManager::PolicyServerConfig & operator[](int);
		CX509PolicyServerListManager::PolicyServerConfig const & operator[](int);
		int Add(CX509PolicyServerListManager::PolicyServerConfig const &);
		int RemoveAt(int);
		~CSimpleArray<CX509PolicyServerListManager::PolicyServerConfig,CSimpleArrayEqualHelper<CX509PolicyServerListManager::PolicyServerConfig> >();
	};

	struct CSimpleArray<CertEnroll::CKeyIdCert *,CSimpleArrayEqualHelper<CertEnroll::CKeyIdCert *> >
	{
		struct Wrapper
		{
			static void operator delete<CertEnroll::CKeyIdCert *>(void *,CertEnroll::CKeyIdCert * *);
		};

		CertEnroll::CKeyIdCert * & operator[](int);
		int Add(CertEnroll::CKeyIdCert * const &);
		~CSimpleArray<CertEnroll::CKeyIdCert *,CSimpleArrayEqualHelper<CertEnroll::CKeyIdCert *> >();
	};

	struct CSimpleArray<CertEnroll::CKeyIdCertList *,CSimpleArrayEqualHelper<CertEnroll::CKeyIdCertList *> >
	{
		struct Wrapper
		{
			static void operator delete<CertEnroll::CKeyIdCertList *>(void *,CertEnroll::CKeyIdCertList * *);
		};

		CertEnroll::CKeyIdCertList * & operator[](int);
		int Add(CertEnroll::CKeyIdCertList * const &);
		~CSimpleArray<CertEnroll::CKeyIdCertList *,CSimpleArrayEqualHelper<CertEnroll::CKeyIdCertList *> >();
	};

	struct CSimpleArray<CertEnroll::FAILED_POLICY_SERVER,CSimpleArrayEqualHelper<CertEnroll::FAILED_POLICY_SERVER> >
	{
		struct Wrapper
		{
			static void operator delete<CertEnroll::FAILED_POLICY_SERVER>(void *,CertEnroll::FAILED_POLICY_SERVER *);
		};

		CertEnroll::FAILED_POLICY_SERVER & operator[](int);
		~CSimpleArray<CertEnroll::FAILED_POLICY_SERVER,CSimpleArrayEqualHelper<CertEnroll::FAILED_POLICY_SERVER> >();
	};

	struct CSimpleArray<CertEnroll::POLICY_SERVER_GROUP,CSimpleArrayEqualHelper<CertEnroll::POLICY_SERVER_GROUP> >
	{
		struct Wrapper
		{
			static void operator delete<CertEnroll::POLICY_SERVER_GROUP>(void *,CertEnroll::POLICY_SERVER_GROUP *);
		};

		CertEnroll::POLICY_SERVER_GROUP & operator[](int);
		int Add(CertEnroll::POLICY_SERVER_GROUP const &);
		void RemoveAll();
		~CSimpleArray<CertEnroll::POLICY_SERVER_GROUP,CSimpleArrayEqualHelper<CertEnroll::POLICY_SERVER_GROUP> >();
	};

	struct CSimpleArray<CredCertificate,CSimpleArrayEqualHelper<CredCertificate> >
	{
		struct Wrapper
		{
			static void operator delete<CredCertificate>(void *,CredCertificate *);
		};

		CredCertificate & operator[](int);
		int Add(CredCertificate const &);
		~CSimpleArray<CredCertificate,CSimpleArrayEqualHelper<CredCertificate> >();
	};

	struct CSimpleArray<CredUserName,CSimpleArrayEqualHelper<CredUserName> >
	{
		struct Wrapper
		{
			static void operator delete<CredUserName>(void *,CredUserName *);
		};

		CredUserName & operator[](int);
		int Add(CredUserName const &);
		void InternalSetAtIndex(int,CredUserName const &);
		~CSimpleArray<CredUserName,CSimpleArrayEqualHelper<CredUserName> >();
	};

	struct CSimpleArray<WebServiceEndPoint,CSimpleArrayEqualHelper<WebServiceEndPoint> >
	{
		struct Wrapper
		{
			static void operator delete<WebServiceEndPoint>(void *,WebServiceEndPoint *);
		};

		WebServiceEndPoint & operator[](int);
		int Add(WebServiceEndPoint const &);
		~CSimpleArray<WebServiceEndPoint,CSimpleArrayEqualHelper<WebServiceEndPoint> >();
	};

	struct CSimpleArray<_CRYPT_OID_INFO const *,CSimpleArrayEqualHelper<_CRYPT_OID_INFO const *> >
	{
		struct Wrapper
		{
			static void operator delete<_CRYPT_OID_INFO const *>(void *,_CRYPT_OID_INFO const * *);
		};

		_CRYPT_OID_INFO const * & operator[](int);
		int Add(_CRYPT_OID_INFO const * const &);
		~CSimpleArray<_CRYPT_OID_INFO const *,CSimpleArrayEqualHelper<_CRYPT_OID_INFO const *> >();
	};

	struct CSimpleArray<unsigned short *,CSimpleArrayEqualHelper<unsigned short *> >
	{
		struct Wrapper
		{
			static void operator delete<unsigned short *>(void *,unsigned short * *);
		};

		int Add(unsigned short * const &);
		unsigned short * & operator[](int);
		unsigned short * const & operator[](int);
		void RemoveAll();
		~CSimpleArray<unsigned short *,CSimpleArrayEqualHelper<unsigned short *> >();
	};

	struct CSimpleArray<void *,CSimpleArrayEqualHelper<void *> >
	{
		struct Wrapper
		{
			static void operator delete<void *>(void *,void * *);
		};

		void * & operator[](int);
		~CSimpleArray<void *,CSimpleArrayEqualHelper<void *> >();
	};

	struct CSimpleMap<unsigned short *,unsigned short *,CExpansionVectorEqualHelper>
	{
		struct Wrapper<unsigned short *>
		{
			static void operator delete<unsigned short *>(void *,unsigned short * *);
		};

		int Add(unsigned short * const &,unsigned short * const &);
		unsigned short * & GetValueAt(int);
		void RemoveAll();
		~CSimpleMap<unsigned short *,unsigned short *,CExpansionVectorEqualHelper>();
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

	struct IObjectWithSiteImpl<CertEnroll::CX509EnrollmentHelper>
	{
		virtual long GetSite(_GUID const &,void * *);
		virtual long SetSite(IUnknown *);
		virtual ~IObjectWithSiteImpl<CertEnroll::CX509EnrollmentHelper>();
	};

	struct IObjectWithSiteImpl<CertEnroll::CX509EnrollmentWebClassFactory>
	{
		virtual long GetSite(_GUID const &,void * *);
		virtual long SetSite(IUnknown *);
		virtual ~IObjectWithSiteImpl<CertEnroll::CX509EnrollmentWebClassFactory>();
	};

	struct IObjectWithSiteImpl<CertEnroll::CX509MachineEnrollmentFactory>
	{
		virtual long GetSite(_GUID const &,void * *);
		virtual long SetSite(IUnknown *);
		virtual ~IObjectWithSiteImpl<CertEnroll::CX509MachineEnrollmentFactory>();
	};

	struct ModuleLockHelper
	{
		~ModuleLockHelper();
	};

	struct _ATL_MODULE70
	{
		~_ATL_MODULE70();
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
	ATL::CAtlWinModule _AtlWinModule;
	IUnknown * AtlComPtrAssign(IUnknown * *,IUnknown *);
	IUnknown * AtlComQIPtrAssign(IUnknown * *,IUnknown *,_GUID const &);
	int AtlCrtErrorCheck(int);
	int InlineIsEqualUnknown(_GUID const &);
	long (* _pPerfRegFunc)(HINSTANCE__ *);
	long (* _pPerfUnRegFunc)();
	long AtlComModuleGetClassObject(ATL::_ATL_COM_MODULE70 *,_GUID const &,_GUID const &,void * *);
	long AtlHresultFromLastError();
	long AtlHresultFromWin32(unsigned long);
	long AtlLoadTypeLib(HINSTANCE__ *,unsigned short const *,unsigned short * *,ITypeLib * *);
	long AtlModuleAddTermFunc(ATL::_ATL_MODULE70 *,void (*)(unsigned __int64),unsigned __int64);
	long AtlRegisterClassCategoriesHelper(_GUID const &,ATL::_ATL_CATMAP_ENTRY const *,int);
	long AtlRegisterTypeLib(HINSTANCE__ *,unsigned short const *);
	unsigned __int64 AtlMultiplyThrow<unsigned __int64>(unsigned __int64,unsigned __int64);
	void AtlCallTermFunc(ATL::_ATL_MODULE70 *);
	void AtlThrowImpl(long);
};

struct CAnonymousCred
{
	virtual _WS_SECURITY_BINDING * GetAuthBinding(SecurityBindingBuffer *);
	virtual bool NeedImpersonation();
	virtual long Initialize(HWND__ *,unsigned short *,unsigned short *);
	virtual void Release();
};

struct CCSEventTimer
{
	void Init(unsigned short const *,unsigned long);
	~CCSEventTimer();
};

class CCertCred
{
	long FindCertInStore(unsigned long,_CRYPTOAPI_BLOB *);
public:
	virtual _WS_SECURITY_BINDING * GetAuthBinding(SecurityBindingBuffer *);
	virtual bool NeedImpersonation();
	virtual long Initialize(HWND__ *,unsigned short *,unsigned short *);
	virtual void Release();
};

class CCertificationWebService
{
	long p_GetStringProperty(unsigned short const *,unsigned short * *);
	virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	void VerifyCACertificate();
public:
	long Initialize(unsigned short *,X509EnrollmentAuthFlags,X509CertificateEnrollmentContext,int,int,unsigned char *,unsigned long);
	static long UpdateRegistry(int);
	virtual long _CheckTrusted(long *);
	virtual long _ComputeSiteCost();
	virtual long _GetAuthentication(X509EnrollmentAuthFlags *);
	virtual long _GetCertificate(_CERT_CONTEXT const * *);
	virtual long _GetCommonName(unsigned short * *);
	virtual long _GetConfigString(unsigned short * *);
	virtual long _GetContext(X509CertificateEnrollmentContext *);
	virtual long _GetDescription(unsigned short * *);
	virtual long _GetDistinguishedName(IX500DistinguishedName * *);
	virtual long _GetDnsName(unsigned short * *);
	virtual long _GetIsRenewalOnly(short *);
	virtual long _GetProtocol(X509CertificateProtocol *);
	virtual long _GetRegisteredInDirectoryService(short *);
	virtual long _GetSanitizedName(unsigned short * *);
	virtual long _GetSanitizedShortName(unsigned short * *);
	virtual long _GetSecurity(unsigned short * *);
	virtual long _GetSiteCost(long *);
	virtual long _GetSiteName(unsigned short * *);
	virtual long _GetTemplateNames(tagVARIANT *);
	virtual long _GetTrusted(short *);
	virtual long _GetType(X509CertificationAuthorityType *);
	virtual long _GetValid(short *);
	virtual long _GetVersion2TemplatesSupported(short *);
	virtual long _GetWebURLs(tagVARIANT *);
	virtual long _InitializeFromInvalidName(unsigned short *);
	virtual long _InitializeFromName(X509CertificateEnrollmentContext,unsigned short *);
	virtual long _IsTemplateSupported(IX509CertificateTemplateInternal *,short *);
	virtual long _MatchCAName(CANameType,unsigned short *,unsigned short *,unsigned short *,unsigned short *,short *);
	virtual long _Ping();
	virtual long _PutSiteCost(long);
	virtual long _RetrieveEnrollmentAccess(X509CertificateEnrollmentContext,X509CertificateEnrollmentAccessFlag *);
	virtual long get_Property(EnrollmentCAProperty,tagVARIANT *);
	~CCertificationWebService();
};

class CCredManager
{
	long GetCertificateFromMemory(unsigned short const *);
	long GetCertificateFromVault(HWND__ *,unsigned short const *);
	long GetUsernameFromMemory(unsigned short const *);
	long GetUsernameFromVault(HWND__ *,unsigned short const *);
	static long PromptForWindowsCredential(HWND__ *,unsigned short const *,CCredManager::CREDENTIAL_PROMPT_CAPTION_TYPE,unsigned short const *,unsigned long,void const *,unsigned long,void * *,unsigned long *,int *);
	void Cleanup();
public:
	long GetCredFromMemory(unsigned short const *,X509EnrollmentAuthFlags);
	long GetCredFromVault(HWND__ *,unsigned short const *,X509EnrollmentAuthFlags);
	long Prompt(HWND__ *,unsigned short const *,CCredManager::CREDENTIAL_PROMPT_CAPTION_TYPE,unsigned long,int *);
	long SaveCredToMemory(unsigned short const *);
	long SaveCredToVault(HWND__ *,unsigned short const *);
	long SearchCredFromMyStore(unsigned short *,unsigned short *);
	long SetCred(X509EnrollmentAuthFlags,unsigned short *,unsigned short *);
	static long PromptForClientAuthCert(HWND__ *,unsigned short const *,CCredManager::CREDENTIAL_PROMPT_CAPTION_TYPE,int,unsigned short * *,int *);
	static long PromptForUsername(HWND__ *,unsigned short const *,CCredManager::CREDENTIAL_PROMPT_CAPTION_TYPE,unsigned short * *,unsigned short * *,int *);
	static long s_StoreCredential(HWND__ *,X509CertificateEnrollmentContext,unsigned short *,X509EnrollmentAuthFlags,unsigned short *,unsigned short *);
	~CCredManager();
};

struct CDecryptCredentialOperation
{
	CDecryptCredentialOperation();
	long RuntimeClassInitialize(unsigned int,HSTRING__ *,HSTRING__ *);
	virtual long DoWork();
	virtual long GetIids(unsigned long *,_GUID * *);
	virtual long GetResults(HSTRING__ * *);
	virtual long GetRuntimeClassName(HSTRING__ * *);
	virtual long GetTrustLevel(TrustLevel *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CEPTemplate
{
	~CEPTemplate();
};

struct CERTFILTERSTRING
{
	CERTFILTERSTRING();
	long Initialize(unsigned short const *,bool);
	void Cleanup();
	~CERTFILTERSTRING();
};

struct CKerberosCred
{
	CKerberosCred();
	virtual _WS_SECURITY_BINDING * GetAuthBinding(SecurityBindingBuffer *);
	virtual bool NeedImpersonation();
	virtual long Initialize(HWND__ *,unsigned short *,unsigned short *);
	virtual void Release();
};

struct CLoadPolicy
{
	long GetPolicyId(unsigned short * *);
	virtual long Execute(int,X509EnrollmentAuthFlags,unsigned short *,unsigned short *,unsigned int *,bool *);
	virtual long LogAuthFailureEvent(X509CertificateEnrollmentContext,long,unsigned short *,unsigned short *,unsigned short *,X509EnrollmentAuthFlags);
	~CLoadPolicy();
};

struct CMemVault
{
	CMemVault();
	static long AddCertificate(unsigned short const *,unsigned char *,unsigned long,X509CertificateEnrollmentContext);
	static long AddUsernamePassword(unsigned short const *,unsigned short const *,unsigned short const *,X509CertificateEnrollmentContext);
	static long FindCertificate(unsigned short const *,X509CertificateEnrollmentContext,unsigned short * *);
	static long FindUsername(unsigned short const *,X509CertificateEnrollmentContext,unsigned short * *,unsigned short * *);
	static void FreeCredUserName(CredUserName *);
	~CMemVault();
};

struct CNameValueError
{
	unsigned short * GetError();
	void SetError(unsigned short const *,unsigned short const *);
	~CNameValueError();
};

struct CPolicyUrlProperties
{
	~CPolicyUrlProperties();
};

class CPrivateKeyVerify
{
protected:
	long p_AcquireContext(HWND__ *,unsigned long,unsigned short const *,bool *,unsigned __int64 *,unsigned long *);
	long p_ExportedProviderPublicKey(_CERT_PUBLIC_KEY_INFO const * *);
	long p_OpenCipher(microsoft::fs::cryptography::ICipher * *);
	long p_PublicKeyMatchesCert(int *);
	long p_SigningKey(int *,unsigned long *);
	long p_VerifyPublicKeyMatchesPrivateKey(PrivateKeyMatchType,long *);
public:
	long Verify(HWND__ *,unsigned short const *);
	~CPrivateKeyVerify();
};

class CQBitMap
{
	void p_GetSerializedWChar(unsigned long,unsigned short *);
public:
	long Serialize(unsigned short *,unsigned long);
	long SetRange(unsigned long,unsigned long);
	static bool s_IsSerializedBitSet(unsigned short const *,unsigned long);
	~CQBitMap();
};

struct CQMatch
{
	CQMatch(bool);
	bool p_MatchExpression(unsigned short const *,unsigned short const *);
	long AddExpression(unsigned short const *);
	long FindMatch(unsigned short const *,unsigned short const * *);
	long p_ParseClass(unsigned short const * *,unsigned short *,unsigned long);
	long p_ParseExpression(unsigned short const *,unsigned short * *);
	long p_ParseExpressionBuf(unsigned short const *,unsigned short *,unsigned long);
	unsigned short const * p_SkipPrefix(unsigned short const *,unsigned short const * *);
};

class CSiteLock<CertEnroll::CX509EnrollmentHelper>
{
	bool FApprovedDomain(unsigned short const *,unsigned long,IObjectSafetySiteLock::SiteList const *,int);
	bool MatchDomains(unsigned short const *,unsigned short const *);
	long GetDomainAndScheme(unsigned short const *,unsigned short *,unsigned long,unsigned short *,unsigned long);
	long NormalizeDomain(unsigned short *,int);
public:
	bool GetOurUrl(ATL::CComBSTR &,unsigned long &);
	bool InApprovedDomain(IObjectSafetySiteLock::SiteList const *,int);
};

class CSiteLock<CertEnroll::CX509EnrollmentWebClassFactory>
{
	bool FApprovedDomain(unsigned short const *,unsigned long,IObjectSafetySiteLock::SiteList const *,int);
	bool MatchDomains(unsigned short const *,unsigned short const *);
	long GetDomainAndScheme(unsigned short const *,unsigned short *,unsigned long,unsigned short *,unsigned long);
	long NormalizeDomain(unsigned short *,int);
public:
	bool GetOurUrl(ATL::CComBSTR &,unsigned long &);
	bool InApprovedDomain(IObjectSafetySiteLock::SiteList const *,int);
};

class CSiteLock<CertEnroll::CX509MachineEnrollmentFactory>
{
	bool FApprovedDomain(unsigned short const *,unsigned long,IObjectSafetySiteLock::SiteList const *,int);
	bool MatchDomains(unsigned short const *,unsigned short const *);
	long GetDomainAndScheme(unsigned short const *,unsigned short *,unsigned long,unsigned short *,unsigned long);
	long NormalizeDomain(unsigned short *,int);
public:
	bool GetOurUrl(ATL::CComBSTR &,unsigned long &);
	bool InApprovedDomain(IObjectSafetySiteLock::SiteList const *,int);
};

struct CSiteLockImpl<CertEnroll::CX509EnrollmentHelper>
{
	static IObjectSafetySiteLock::SiteList const * const rgslTrustedSites;
	virtual long SetInterfaceSafetyOptions(_GUID const &,unsigned long,unsigned long);
};

struct CSiteLockImpl<CertEnroll::CX509EnrollmentWebClassFactory>
{
	long ConfirmWebCall();
	long GetUrlAndWindow(unsigned short * *,HWND__ * *);
	static IObjectSafetySiteLock::SiteList const * const rgslTrustedSites;
	virtual long SetInterfaceSafetyOptions(_GUID const &,unsigned long,unsigned long);
};

struct CSiteLockImpl<CertEnroll::CX509MachineEnrollmentFactory>
{
	long ConfirmWebCall();
	long GetUrlAndWindow(unsigned short * *,HWND__ * *);
	static IObjectSafetySiteLock::SiteList const * const rgslTrustedSites;
	virtual long SetInterfaceSafetyOptions(_GUID const &,unsigned long,unsigned long);
};

struct CUserNameCred
{
	virtual _WS_SECURITY_BINDING * GetAuthBinding(SecurityBindingBuffer *);
	virtual bool NeedImpersonation();
	virtual long Initialize(HWND__ *,unsigned short *,unsigned short *);
	virtual void Release();
};

class CVault
{
	static long ClearUrl(void *,unsigned short const *);
public:
	static long AddCertificate(HWND__ *,unsigned short const *,unsigned char *,unsigned long);
	static long AddUsernamePassword(HWND__ *,unsigned short const *,unsigned short const *,unsigned short const *);
	static long GetCred(HWND__ *,unsigned short const *,_GUID const *,_VAULT_ITEM * *);
	static unsigned long CreateCertSchema(void *);
	static unsigned long CreateUsernameSchema(void *);
};

struct CWaitCursor
{
	~CWaitCursor();
};

struct CWsServiceProxy
{
	long OpenServiceProxy(IClientCred *,unsigned short const *,_WS_ERROR *);
	static long CreateClientCred(HWND__ *,X509EnrollmentAuthFlags,unsigned short *,unsigned short *,IClientCred * *);
	static void operator delete(void *);
};

class CX509EnrollmentPolicyWebService
{
	long p_AddSupportedTemplates(CCertificationWebService *,CA *);
	long p_CreateCAObjects(CA *,unsigned long);
	long p_FetchPolicy(bool,_LARGE_INTEGER,_WS_ERROR *,unsigned int *,CA * *);
	long p_LoadPolicy(bool,X509EnrollmentPolicyLoadOption);
	long p_ReadPolicyCache(unsigned int *,CA * *,_FILETIME *);
	long p_UpdateRegistry(unsigned short *,unsigned short *,unsigned short *,X509CertificateEnrollmentContext);
	long p_ValidateAndCacheCepID(bool);
	long p_WritePolicyCache(_GetPoliciesResponse *,unsigned long *,unsigned char * *);
	virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
public:
	CX509EnrollmentPolicyWebService();
	static long GetCEPIdFromCache(unsigned short *,unsigned short * *);
	static long UpdateRegistry(int);
	virtual long Export(X509EnrollmentPolicyExportFlags,tagVARIANT *);
	virtual long GetAllowUnTrustedCA(short *);
	virtual long GetAuthFlags(X509EnrollmentAuthFlags *);
	virtual long GetCAs(ICertificationAuthorities * *);
	virtual long GetCAsForTemplate(IX509CertificateTemplate *,ICertificationAuthorities * *);
	virtual long GetCacheDir(unsigned short * *);
	virtual long GetCachePath(unsigned short * *);
	virtual long GetCustomOids(IObjectIds * *);
	virtual long GetFriendlyName(unsigned short * *);
	virtual long GetIsDefaultCEP(short *);
	virtual long GetLastUpdateTime(double *);
	virtual long GetNextUpdateTime(double *);
	virtual long GetPolicyServerId(unsigned short * *);
	virtual long GetPolicyServerUrl(unsigned short * *);
	virtual long GetTemplates(IX509CertificateTemplates * *);
	virtual long GetUseClientId(short *);
	virtual long Initialize(unsigned short *,unsigned short *,X509EnrollmentAuthFlags,short,X509CertificateEnrollmentContext);
	virtual long InitializeImport(tagVARIANT);
	virtual long LoadPolicy(X509EnrollmentPolicyLoadOption);
	virtual long QueryChanges(short *);
	virtual long SetCredential(long,X509EnrollmentAuthFlags,unsigned short *,unsigned short *);
	virtual long Validate();
	virtual long _Initialize(unsigned short *,unsigned short *,X509EnrollmentAuthFlags,short,PolicyServerUrlFlags,X509CertificateEnrollmentContext);
	virtual long _InitializeFromPolicyServerUrl(X509CertificateEnrollmentContext,IX509PolicyServerUrl *);
	virtual long get_Cost(unsigned long *);
	virtual long put_Cost(unsigned long);
	~CX509EnrollmentPolicyWebService();
};

class CX509PolicyServerListManager
{
	long AddUrlsIntoCollection(ATL::CSimpleArray<CX509PolicyServerListManager::PolicyServerConfig,ATL::CSimpleArrayEqualHelper<CX509PolicyServerListManager::PolicyServerConfig> > const &,PolicyServerUrlFlags);
	long p_EnumUrls(PolicyServerUrlFlags);
	long p_NeedExplicitLdap(bool *);
	long p_RetrieveDefaultCepID();
	static long s_AddUrlIntoList(ATL::CSimpleArray<CX509PolicyServerListManager::PolicyServerConfig,ATL::CSimpleArrayEqualHelper<CX509PolicyServerListManager::PolicyServerConfig> > *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned long,unsigned long,unsigned long);
	static void FreeServerConfigArray(ATL::CSimpleArray<CX509PolicyServerListManager::PolicyServerConfig,ATL::CSimpleArrayEqualHelper<CX509PolicyServerListManager::PolicyServerConfig> > &);
	static void FreeServerGroupStruct(CX509PolicyServerListManager::PolicyServerConfig *);
	static void s_RemoveUrlsAndIDsWhichExistInGroupPolicy(ATL::CSimpleArray<CX509PolicyServerListManager::PolicyServerConfig,ATL::CSimpleArrayEqualHelper<CX509PolicyServerListManager::PolicyServerConfig> > *,ATL::CSimpleArray<CX509PolicyServerListManager::PolicyServerConfig,ATL::CSimpleArrayEqualHelper<CX509PolicyServerListManager::PolicyServerConfig> > *);
	static void s_RemoveUrlsWithSameID(ATL::CSimpleArray<CX509PolicyServerListManager::PolicyServerConfig,ATL::CSimpleArrayEqualHelper<CX509PolicyServerListManager::PolicyServerConfig> > *);
public:
	CX509PolicyServerListManager();
	static long AddUrl(HKEY__ *,_PolicyUrlProperties const *);
	static long EnumeratePolicyUrl(HKEY__ *,unsigned long,_PolicyUrlProperties *,SupportedCapabilitiesFlags *);
	static long RemoveUrl(HKEY__ *,X509CertificateEnrollmentContext,unsigned short *);
	static long SetFlags(HKEY__ *,unsigned short *,unsigned long);
	static long UpdateRegistry(int);
	static long s_GetFriendlyName(X509CertificateEnrollmentContext,PolicyServerUrlFlags,unsigned short *,unsigned short * *);
	virtual long Add(IX509PolicyServerUrl *);
	virtual long AddRange(CX509PolicyServerListManager *);
	virtual long Initialize(X509CertificateEnrollmentContext,PolicyServerUrlFlags);
	virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	~CX509PolicyServerListManager();
};

struct CX509PolicyServerUrl
{
	static long UpdateRegistry(int);
	virtual long GetStringProperty(PolicyServerUrlPropertyID,unsigned short * *);
	virtual long Initialize(X509CertificateEnrollmentContext);
	virtual long RemoveFromRegistry(X509CertificateEnrollmentContext);
	virtual long SetStringProperty(PolicyServerUrlPropertyID,unsigned short *);
	virtual long UpdateRegistry(X509CertificateEnrollmentContext);
	virtual long _GetStringProperty(PolicyServerUrlPropertyID,unsigned short * *);
	virtual long get_AuthFlags(X509EnrollmentAuthFlags *);
	virtual long get_Cost(unsigned long *);
	virtual long get_Default(short *);
	virtual long get_Flags(PolicyServerUrlFlags *);
	virtual long get_Url(unsigned short * *);
	virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	virtual long put_AuthFlags(X509EnrollmentAuthFlags);
	virtual long put_Cost(unsigned long);
	virtual long put_Default(short);
	virtual long put_Flags(PolicyServerUrlFlags);
	virtual long put_Url(unsigned short *);
	~CX509PolicyServerUrl();
};

namespace CallerIdentity
{
	long CheckCallerCapability(unsigned short const *,bool *);
	long CheckCapabilityFromProcessHandle(void *,unsigned short const *,bool *);
	long GetCallingProcessHandle(unsigned long,RUNTIMEBROKER_CALLERIDENTITY_CHECK,void * *);
	long GetCallingProcessHandle(unsigned long,void * *);
	long GetCoreApplicationForCallingProcess(_GUID const &,void * *);
	long GetCoreWindowForCallingThread(_GUID const &,void * *);
	long GetCoreWindowHandleForCallingThread(HWND__ * *);
	long GetImmersiveAppIdFromWindow(HWND__ *,unsigned short * *);
	long GetImpersonationTokenFromProcess(void *,unsigned long,void * *);
	long GetPackageFullNameFromProcess(void *,unsigned short * *);
	long GetPackageSidFromProcess(unsigned long,void * *);
	long GetPackageSidFromProcessHandle(void *,void * *);
	long GetPackageSidFromProcessToken(void *,void * *);
	long GetProcessAppId(void *,unsigned short * *);
	long IsProcessAppContainer(void *,bool *);
	long VerifyWindowIsInCallingProcessAppContainer(HWND__ *);
	long VerifyWindowIsInProcessByAppContainerSid(HWND__ *,void *);
	long VerifyWindowIsInSpecifiedApplication(HWND__ *,unsigned short const *,IUnknown *);
};

namespace CertEnroll
{
	struct CADTemplateBuilder
	{
		long CreateTemplate(X509CertificateEnrollmentContext,IX509CertificateTemplateInternal * *);
		long _InitializeFromHandle(ldap *,void *);
		long get_ApplicationPolicies(IObjectIds * *);
		long get_CriticalExtensions(IObjectIds * *);
		long get_CryptoServiceProviders(tagVARIANT *);
		long get_EnhancedKeyUsage(IObjectIds * *);
		long get_EnrollmentAccessWithContext(X509CertificateEnrollmentContext,X509CertificateEnrollmentAccessFlag *);
		long get_Oid(IObjectId * *);
		long get_Policies(IObjectIds * *);
		long get_PolicyId(unsigned short * *);
		long get_PrivateKeyUsage(X509PrivateKeyUsageFlags *);
		long get_RAApplicationPolicies(IObjectIds * *);
		long get_RAPolicies(IObjectIds * *);
		long get_RenewalPeriod(_FILETIME *);
		long get_SecurityDescriptor(unsigned short * *);
		long get_SupersedeTemplates(tagVARIANT *);
		long get_ValidityPeriod(_FILETIME *);
		long get_X509Extensions(IX509Extensions * *);
		long p_RetrieveOidCollectionProperty(void *,unsigned short const *,ObjectIdGroupId,IObjectIds * *);
		long p_RetrieveOidProperty(void *,unsigned short const *,IObjectId * *);
		long p_RetrieveStringProperty(void *,unsigned short const *,unsigned short * *);
		long p_VerifyOidProperty(void *,unsigned short const *);
		~CADTemplateBuilder();
	};

	struct CAName
	{
		long Initialize(unsigned short *);
		~CAName();
	};

	struct CAdvancedAutoEnrollment
	{
		virtual EnrollmentUIFlags GetUIFlags();
		virtual long InitEnrollment(CX509EnrollmentManager *);
	};

	struct CAlternativeName
	{
		CAlternativeName();
		static long UpdateRegistry(int);
		virtual long InitializeFromOtherName(IObjectId *,EncodingType,unsigned short *,short);
		virtual long InitializeFromRawData(AlternativeNameType,EncodingType,unsigned short *);
		virtual long InitializeFromString(AlternativeNameType,unsigned short *);
		virtual long _Initialize(_CERT_ALT_NAME_ENTRY *);
		virtual long _Marshal(_CERT_ALT_NAME_ENTRY *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_StrValue(unsigned short * *);
		virtual long get_Type(AlternativeNameType *);
		~CAlternativeName();
	};

	class CAlternativeNames
	{
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long _Marshal(_CERT_ALT_NAME_INFO *);
		~CAlternativeNames();
	};

	class CBinaryConverter
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long StringArrayToVariantArray(tagVARIANT *,tagVARIANT *);
		virtual long StringToString(unsigned short *,EncodingType,EncodingType,unsigned short * *);
		virtual long StringToVariantByteArray(unsigned short *,EncodingType,tagVARIANT *);
		virtual long VariantArrayToStringArray(tagVARIANT *,tagVARIANT *);
		virtual long VariantByteArrayToString(tagVARIANT *,EncodingType,unsigned short * *);
		~CBinaryConverter();
	};

	class CByteArray
	{
		long _Set(unsigned char const *,unsigned long,bool);
	public:
		long Attach(_CRYPTOAPI_BLOB const *);
		long Attach(unsigned char const *,unsigned long);
		long Copy(CByteArray *);
		long Get(EncodingType,unsigned short * *);
		long GetBinary(EncodingType,unsigned short * *);
		long GetBuffer(unsigned char const * *,unsigned long *);
		long Set(_CRYPTOAPI_BLOB const *);
		long Set(_CRYPT_BIT_BLOB const *);
		long Set(unsigned char const *,unsigned long);
		long Set(unsigned short *);
		void Clear();
		~CByteArray();
	};

	struct CCAStatus
	{
		CCAStatus();
		static long UpdateRegistry(int);
		virtual long InitializeFromCA(ICertificationAuthorityInternal *);
		virtual long get_CA(ICertificationAuthorityInternal * *);
		virtual long get_EnrollmentStatus(IX509EnrollmentStatus * *);
		~CCAStatus();
	};

	class CCAStatuses
	{
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long get_ItemByName(unsigned short *,ICAStatus * *);
		~CCAStatuses();
	};

	class CCertProperties
	{
		static long s_CreatePropertyInternal(CERTENROLL_PROPERTYID,ICertPropertyInternal * *);
		virtual long p_CopyCertificateContextByProperties(_CERT_CONTEXT const *);
		virtual long p_CopyCertificateContextByWellKnownProperties(_CERT_CONTEXT const *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long Add(ICertProperty *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		~CCertProperties();
	};

	class CCertProperty
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertProperty();
	};

	struct CCertPropertyArchived
	{
		static long UpdateRegistry(int);
		virtual long Initialize(short);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_Archived(short *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertyArchived();
	};

	struct CCertPropertyArchivedImpl
	{
		static unsigned short const sm_SingleChar;
		virtual long Initialize(short);
		virtual long get_Archived(short *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual ~CCertPropertyArchivedImpl();
	};

	struct CCertPropertyArchivedKeyHash
	{
		static long UpdateRegistry(int);
		virtual long Initialize(EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_ArchivedKeyHash(EncodingType,unsigned short * *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertyArchivedKeyHash();
	};

	struct CCertPropertyArchivedKeyHashImpl
	{
		virtual long Initialize(EncodingType,unsigned short *);
		virtual long get_ArchivedKeyHash(EncodingType,unsigned short * *);
		virtual ~CCertPropertyArchivedKeyHashImpl();
	};

	struct CCertPropertyAutoEnroll
	{
		static long UpdateRegistry(int);
		virtual long Initialize(unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_TemplateName(unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertyAutoEnroll();
	};

	struct CCertPropertyAutoEnrollImpl
	{
		virtual long Initialize(unsigned short *);
		virtual long get_TemplateName(unsigned short * *);
		virtual ~CCertPropertyAutoEnrollImpl();
	};

	struct CCertPropertyBackedUp
	{
		static long UpdateRegistry(int);
		virtual long Initialize(short,double);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long InitializeFromCurrentTime(short);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_BackedUpTime(double *);
		virtual long get_BackedUpValue(short *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertyBackedUp();
	};

	class CCertPropertyBackedUpImpl
	{
		virtual long p_DecodeFromRawData();
		virtual long p_EncodeToRawData(short,_FILETIME const &);
	public:
		virtual long Initialize(short);
		virtual long Initialize(short,double);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long get_BackedUpTime(double *);
		virtual long get_BackedUpValue(short *);
		virtual ~CCertPropertyBackedUpImpl();
	};

	class CCertPropertyDescription
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long Initialize(unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_Description(unsigned short * *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertyDescription();
	};

	class CCertPropertyDescriptionImpl
	{
		virtual long p_InitializeFromDescriptionExtension(_CERT_CONTEXT const *);
	public:
		virtual long Initialize(unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long get_Description(unsigned short * *);
		virtual ~CCertPropertyDescriptionImpl();
	};

	struct CCertPropertyEnrollment
	{
		CCertPropertyEnrollment();
		static long UpdateRegistry(int);
		virtual long Initialize(long,unsigned short *,unsigned short *,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_CADnsName(unsigned short * *);
		virtual long get_CAName(unsigned short * *);
		virtual long get_FriendlyName(unsigned short * *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_RequestId(long *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertyEnrollment();
	};

	class CCertPropertyEnrollmentImpl
	{
		virtual long p_DecodeFromRawData();
		virtual long p_EncodeToRawData(long,unsigned short *,unsigned short *,unsigned short *);
		virtual long p_InitializeFromEnrollmentExtension(_CERT_CONTEXT const *);
	public:
		virtual long Initialize(long,unsigned short *,unsigned short *,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long get_CADnsName(unsigned short * *);
		virtual long get_CAName(unsigned short * *);
		virtual long get_FriendlyName(unsigned short * *);
		virtual long get_RequestId(long *);
		virtual ~CCertPropertyEnrollmentImpl();
	};

	struct CCertPropertyEnrollmentPolicyServer
	{
		CCertPropertyEnrollmentPolicyServer();
		static long UpdateRegistry(int);
		virtual long GetAuthentication(X509EnrollmentAuthFlags *);
		virtual long GetEnrollmentServerAuthentication(X509EnrollmentAuthFlags *);
		virtual long GetEnrollmentServerUrl(unsigned short * *);
		virtual long GetPolicyServerId(unsigned short * *);
		virtual long GetPolicyServerUrl(unsigned short * *);
		virtual long GetPropertyFlags(EnrollmentPolicyServerPropertyFlags *);
		virtual long GetRequestIdString(unsigned short * *);
		virtual long GetUrlFlags(PolicyServerUrlFlags *);
		virtual long Initialize(EnrollmentPolicyServerPropertyFlags,X509EnrollmentAuthFlags,X509EnrollmentAuthFlags,PolicyServerUrlFlags,unsigned short *,unsigned short *,unsigned short *,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertyEnrollmentPolicyServer();
	};

	class CCertPropertyEnrollmentPolicyServerImpl
	{
		virtual long p_AttachName(unsigned short *,unsigned short *,unsigned short *,unsigned short *,unsigned short * *);
		virtual long p_DecodeFromRawData();
		virtual long p_DumpBlob(unsigned char const *,unsigned long);
		virtual long p_InitializeFromCEPExtension(_CERT_CONTEXT const *);
	public:
		virtual long GetAuthentication(X509EnrollmentAuthFlags *);
		virtual long GetEnrollmentServerAuthentication(X509EnrollmentAuthFlags *);
		virtual long GetEnrollmentServerUrl(unsigned short * *);
		virtual long GetPolicyServerId(unsigned short * *);
		virtual long GetPolicyServerUrl(unsigned short * *);
		virtual long GetPropertyFlags(EnrollmentPolicyServerPropertyFlags *);
		virtual long GetRequestIdString(unsigned short * *);
		virtual long GetUrlFlags(PolicyServerUrlFlags *);
		virtual long Initialize(EnrollmentPolicyServerPropertyFlags,X509EnrollmentAuthFlags,X509EnrollmentAuthFlags,PolicyServerUrlFlags,unsigned short *,unsigned short *,unsigned short *,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual ~CCertPropertyEnrollmentPolicyServerImpl();
	};

	class CCertPropertyFriendlyName
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long Initialize(unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_FriendlyName(unsigned short * *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertyFriendlyName();
	};

	class CCertPropertyFriendlyNameImpl
	{
		virtual long p_InitializeFromFriendlyNameExtension(_CERT_CONTEXT const *);
	public:
		virtual long Initialize(unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long get_FriendlyName(unsigned short * *);
		virtual ~CCertPropertyFriendlyNameImpl();
	};

	struct CCertPropertyImpl
	{
		CCertPropertyImpl();
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _PostInitString(unsigned short * *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		virtual ~CCertPropertyImpl();
	};

	struct CCertPropertyKeyProvInfo
	{
		CCertPropertyKeyProvInfo();
		static long UpdateRegistry(int);
		virtual long Initialize(IX509PrivateKey *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_PrivateKey(IX509PrivateKey * *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertyKeyProvInfo();
	};

	struct CCertPropertyKeyProvInfoImpl
	{
		virtual long Initialize(IX509PrivateKey *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long get_PrivateKey(IX509PrivateKey * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual ~CCertPropertyKeyProvInfoImpl();
	};

	struct CCertPropertyRenewal
	{
		static long UpdateRegistry(int);
		virtual long Initialize(EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long InitializeFromCertificateHash(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_Renewal(EncodingType,unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertyRenewal();
	};

	struct CCertPropertyRenewalImpl
	{
		virtual long Initialize(EncodingType,unsigned short *);
		virtual long InitializeFromCertificateHash(short,EncodingType,unsigned short *);
		virtual long get_Renewal(EncodingType,unsigned short * *);
		virtual ~CCertPropertyRenewalImpl();
	};

	struct CCertPropertyRequestOriginator
	{
		static long UpdateRegistry(int);
		virtual long Initialize(unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long InitializeFromLocalRequestOriginator();
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_RequestOriginator(unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertyRequestOriginator();
	};

	class CCertPropertyRequestOriginatorImpl
	{
		virtual long myGetHostName(unsigned short * *);
	public:
		virtual long Initialize();
		virtual long Initialize(unsigned short *);
		virtual long get_RequestOriginator(unsigned short * *);
		virtual ~CCertPropertyRequestOriginatorImpl();
	};

	struct CCertPropertySHA1Hash
	{
		static long UpdateRegistry(int);
		virtual long Initialize(EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeFromCertificate(short,EncodingType,unsigned short *);
		virtual long RemoveFromCertificate(short,EncodingType,unsigned short *);
		virtual long SetValueOnCertificate(short,EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _RemoveFromCertificateContext(_CERT_CONTEXT const *);
		virtual long _SetValueOnCertificateContext(_CERT_CONTEXT const *);
		virtual long get_PropertyId(CERTENROLL_PROPERTYID *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_SHA1Hash(EncodingType,unsigned short * *);
		virtual long put_PropertyId(CERTENROLL_PROPERTYID);
		~CCertPropertySHA1Hash();
	};

	struct CCertPropertySHA1HashImpl
	{
		CCertPropertySHA1HashImpl();
		virtual long Initialize(EncodingType,unsigned short *);
		virtual long get_SHA1Hash(EncodingType,unsigned short * *);
		virtual ~CCertPropertySHA1HashImpl();
	};

	struct CCertPropertyStringImpl
	{
		CCertPropertyStringImpl();
		virtual long Initialize(unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long _InitializeFromCertificateContext(_CERT_CONTEXT const *);
		virtual long get_StringValue(unsigned short * *);
		virtual ~CCertPropertyStringImpl();
	};

	class CCertificateAttestationChallenge
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long DecryptChallenge(EncodingType,unsigned short * *);
		virtual long Initialize(EncodingType,unsigned short *);
		virtual long get_RequestID(unsigned short * *);
		virtual long put_KeyBlob(EncodingType,unsigned short *);
		virtual long put_KeyContainerName(unsigned short *);
		~CCertificateAttestationChallenge();
	};

	class CCertificatePolicies
	{
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static void s_FreeMarshaledMemory(_CERT_POLICIES_INFO *);
		virtual long _Marshal(_CERT_POLICIES_INFO *);
		~CCertificatePolicies();
	};

	struct CCertificatePolicy
	{
		CCertificatePolicy();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *);
		virtual long _Marshal(_CERT_POLICY_INFO *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_PolicyQualifiers(IPolicyQualifiers * *);
		virtual ~CCertificatePolicy();
	};

	class CCertificationAuthorities
	{
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Add(ICertificationAuthorities *,ICertificationAuthorityInternal *);
		static long s_ComputeSiteCosts(ICertificationAuthorityInternal * *,long);
		static long s_GetItemByIndex(ICertificationAuthorities *,long,ICertificationAuthorityInternal * *);
		static long s_GetItemByName(ICertificationAuthorities *,unsigned short const *,ICertificationAuthorityInternal * *);
		virtual long ComputeSiteCosts();
		virtual long get_ItemByName(unsigned short *,ICertificationAuthority * *);
		~CCertificationAuthorities();
	};

	class CCertificationAuthority
	{
		long p_Clone(CCertificationAuthority *);
		long p_DeriveNames();
		long p_GetCASecurity(void *,unsigned short * *);
		long p_GetTypeFromHCAInfo(void *,X509CertificationAuthorityType *);
		long p_RetrieveMultiValuedProperty(void *,unsigned short const *,ATL::CComVariant *);
		long p_RetrieveStringProperty(void *,unsigned short const *,unsigned short * *);
		long p_Sanitize(unsigned short *,unsigned short * *);
		long p_SetEnrollmentAccessFromHCAInfo(void *,X509CertificateEnrollmentContext);
		long p_ShortenSanitized(unsigned short *,unsigned short * *);
		long p_TryContactCADirectly(unsigned short *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CCertificationAuthority();
		long _InitializeFromHCAInfo(void *,X509CertificateEnrollmentContext);
		long _InitializeFromICertConfig(ICertConfig2 *,X509CertificateEnrollmentContext);
		static long UpdateRegistry(int);
		static long _GetIField(ICertConfig2 *,unsigned short const *,unsigned short * *);
		virtual long _CheckTrusted(long *);
		virtual long _ComputeSiteCost();
		virtual long _GetAuthentication(X509EnrollmentAuthFlags *);
		virtual long _GetCertificate(_CERT_CONTEXT const * *);
		virtual long _GetCommonName(unsigned short * *);
		virtual long _GetConfigString(unsigned short * *);
		virtual long _GetContext(X509CertificateEnrollmentContext *);
		virtual long _GetDescription(unsigned short * *);
		virtual long _GetDistinguishedName(IX500DistinguishedName * *);
		virtual long _GetDnsName(unsigned short * *);
		virtual long _GetIsRenewalOnly(short *);
		virtual long _GetProtocol(X509CertificateProtocol *);
		virtual long _GetRegisteredInDirectoryService(short *);
		virtual long _GetSanitizedName(unsigned short * *);
		virtual long _GetSanitizedShortName(unsigned short * *);
		virtual long _GetSecurity(unsigned short * *);
		virtual long _GetSiteCost(long *);
		virtual long _GetSiteName(unsigned short * *);
		virtual long _GetTemplateNames(tagVARIANT *);
		virtual long _GetTrusted(short *);
		virtual long _GetType(X509CertificationAuthorityType *);
		virtual long _GetValid(short *);
		virtual long _GetVersion2TemplatesSupported(short *);
		virtual long _GetWebURLs(tagVARIANT *);
		virtual long _InitializeFromInvalidName(unsigned short *);
		virtual long _InitializeFromName(X509CertificateEnrollmentContext,unsigned short *);
		virtual long _IsTemplateSupported(IX509CertificateTemplateInternal *,short *);
		virtual long _MatchCAName(CANameType,unsigned short *,unsigned short *,unsigned short *,unsigned short *,short *);
		virtual long _Ping();
		virtual long _PutSiteCost(long);
		virtual long _RetrieveEnrollmentAccess(X509CertificateEnrollmentContext,X509CertificateEnrollmentAccessFlag *);
		virtual long get_Property(EnrollmentCAProperty,tagVARIANT *);
		~CCertificationAuthority();
	};

	class CCryptAttribute
	{
		long p_GetObjectIdFromValues(IX509Attributes *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CCryptAttribute();
		static long UpdateRegistry(int);
		static long s_Create(ICryptAttribute * *);
		static long s_CreateArchivedKey(IX509PrivateKey *,_CERT_CONTEXT const *,IObjectId *,long,IObjectId * *,long *,unsigned short * *,ICryptAttribute * *);
		static long s_CreateArchivedKeyHash(unsigned short *,IObjectId *,unsigned short * *,ICryptAttribute * *);
		static long s_CreateClientId(RequestClientInfoClientId,ICryptAttribute * *);
		static long s_CreateCspProvider(IX509PrivateKey *,ICryptAttribute * *);
		static long s_CreateFromAttributeBlob(char const *,unsigned char const *,unsigned long,ICryptAttribute * *);
		static long s_CreateFromAttributeValue(IX509Attribute *,ICryptAttribute * *);
		static long s_CreateRenewal(_CERT_CONTEXT const *,ICryptAttribute * *);
		virtual long InitializeFromObjectId(IObjectId *);
		virtual long InitializeFromValues(IX509Attributes *);
		virtual long _Initialize(_CRYPT_ATTRIBUTE *);
		virtual long _Marshal(_CRYPT_ATTRIBUTE *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_Values(IX509Attributes * *);
		~CCryptAttribute();
	};

	class CCryptAttributes
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Create(ICryptAttributes * *);
		static long s_Marshal(ICryptAttributes *,_CRYPT_ATTRIBUTES *);
		virtual long AddRange(ICryptAttributes *);
		virtual long _Initialize(_CRYPT_ATTRIBUTES *);
		virtual long _Marshal(_CRYPT_ATTRIBUTES *);
		virtual long get_IndexByObjectId(IObjectId *,long *);
		~CCryptAttributes();
	};

	class CCspAlgorithm
	{
		long p_GetAsymmetricLengthProperties(unsigned __int64,__NCRYPT_SUPPORTED_LENGTHS *,unsigned short const * *);
		static long s_GetSimpleName(unsigned short const *,AlgorithmType,long,long,long,unsigned short * *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void p_TraceAlgorithm(long,unsigned short const *,_PROV_ENUMALGS_EX const *);
	public:
		static long UpdateRegistry(int);
		static long s_InitializeFromAlgorithmInfo(ICspAlgorithm *,unsigned __int64,unsigned short const *,_NCryptAlgorithmName const *,unsigned short const *,unsigned short const * *);
		static long s_InitializeFromCommonAlgorithmInfo(ICspAlgorithm *,_BCRYPT_ALGORITHM_IDENTIFIER const *,unsigned short const * *);
		static long s_InitializeFromLegacyAlgorithmInfo(ICspAlgorithm *,unsigned short const *,_PROV_ENUMALGS_EX const *,unsigned short const * *);
		virtual long GetAlgorithmOid(long,AlgorithmFlags,IObjectId * *);
		virtual long InitializeFromInvalidName(unsigned short *);
		virtual long _GetLegacyName(unsigned short * *);
		virtual long _InitializeFromAlgorithmInfo(unsigned __int64,unsigned short const *,_NCryptAlgorithmName const *,unsigned short const *,unsigned short * *);
		virtual long _InitializeFromCommonAlgorithmInfo(_BCRYPT_ALGORITHM_IDENTIFIER const *,unsigned short * *);
		virtual long _InitializeFromLegacyAlgorithmInfo(unsigned short const *,_PROV_ENUMALGS_EX const *,unsigned short * *);
		virtual long _MergeAlgorithms(unsigned short const *,long,long);
		virtual long get_DefaultLength(long *);
		virtual long get_IncrementLength(long *);
		virtual long get_LongName(unsigned short * *);
		virtual long get_MaxLength(long *);
		virtual long get_MinLength(long *);
		virtual long get_Name(unsigned short * *);
		virtual long get_Operations(AlgorithmOperationFlags *);
		virtual long get_Type(AlgorithmType *);
		virtual long get_Valid(short *);
		~CCspAlgorithm();
	};

	class CCspAlgorithms
	{
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static AlgorithmOperationsMatch s_OperationsMatch(AlgorithmOperationFlags,AlgorithmOperationFlags,ICspAlgorithm *);
		static long UpdateRegistry(int);
		static long s_AddAlgorithm(ICspAlgorithms *,unsigned __int64,unsigned short const *,_NCryptAlgorithmName *,unsigned short const *,unsigned short * *);
		static long s_AddAvailableAlgorithms(ICspAlgorithms *,unsigned short const *,unsigned __int64,unsigned short const * *);
		static long s_AddAvailableLegacyAlgorithms(ICspAlgorithms *,unsigned short const *,unsigned __int64,ICspAlgorithm * *,ICspAlgorithm * *,unsigned short const * *);
		static long s_CreateFromCommonAlgorithms(ICspAlgorithms * *);
		static long s_DecodeOperations(AlgorithmOperationFlags *,AlgorithmOperationFlags *);
		static long s_LogAlgorithmLoadError(ICspAlgorithm *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned long,unsigned short const *,long);
		virtual long _GetItemByOperations(AlgorithmOperationFlags,unsigned short *,ICspAlgorithm * *);
		virtual long get_IndexByObjectId(IObjectId *,long *);
		virtual long get_ItemByName(unsigned short *,ICspAlgorithm * *);
		~CCspAlgorithms();
	};

	class CCspInformation
	{
		long p_GetDefaultCommonAlgorithm(AlgorithmOperationFlags,ICspAlgorithm *,unsigned short *,long,short,ICspAlgorithm * *);
		long p_GetDefaultProvider(X509ProviderType,IObjectId *,bool,unsigned short * *,unsigned short * *);
		long p_GetDword(long,long *);
		long p_GetMaxKeyContainerNameLength();
		long p_Initialize();
		long p_InitializeFromName();
		long p_LegacyInitialize(unsigned short const * *);
		long p_NCGetDword(unsigned short const *,long *);
		long p_NCInitialize(unsigned long *,unsigned short const * *);
		long p_VerifyInitialized();
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CCspInformation();
		static long UpdateRegistry(int);
		static long s_Create(unsigned short *,X509ProviderType,ICspInformation * *);
		static long s_CreateFromType(X509ProviderType,IObjectId *,short,unsigned short * *,ICspInformation * *);
		static long s_GetDefaultEncryptionAlgorithm(ICspInformation *,long *,IObjectId * *);
		static long s_GetDefaultHashAlgorithm(ICspInformation *,unsigned short *,long,short,IObjectId * *);
		static long s_GetDefaultPublicKeyAlgorithm(ICspInformation *,AlgorithmOperationFlags,IObjectId * *);
		static long s_PutCommonAlgorithms(ICspInformation *,ICspAlgorithms *);
		virtual long GetCspStatusFromOperations(IObjectId *,AlgorithmOperationFlags,ICspStatus * *);
		virtual long GetDefaultSecurityDescriptor(short,unsigned short * *);
		virtual long InitializeFromInvalidName(unsigned short *);
		virtual long InitializeFromName(unsigned short *);
		virtual long InitializeFromType(X509ProviderType,IObjectId *,short);
		virtual long _AddCspStatusesFromOperations(AlgorithmOperationFlags,ICspStatuses *);
		virtual long _GetDefaultEncryptionAlgorithm(ICspAlgorithm * *);
		virtual long _GetDefaultHashAlgorithm(unsigned short *,long,short,ICspAlgorithm * *);
		virtual long _GetDefaultPublicKeyAlgorithm(AlgorithmOperationFlags,ICspAlgorithm * *);
		virtual long _Initialize(unsigned short *,X509ProviderType);
		virtual long _InitializeFromType(X509ProviderType,IObjectId *,short,unsigned short * *);
		virtual long _PutCommonAlgorithms(ICspAlgorithms *);
		virtual long get_CspAlgorithms(ICspAlgorithms * *);
		virtual long get_HasHardwareRandomNumberGenerator(short *);
		virtual long get_IsHardwareDevice(short *);
		virtual long get_IsRemovable(short *);
		virtual long get_IsSmartCard(short *);
		virtual long get_IsSoftwareDevice(short *);
		virtual long get_KeySpec(X509KeySpec *);
		virtual long get_LegacyCsp(short *);
		virtual long get_MaxKeyContainerNameLength(long *);
		virtual long get_Name(unsigned short * *);
		virtual long get_Type(X509ProviderType *);
		virtual long get_Valid(short *);
		virtual long get_Version(long *);
		~CCspInformation();
	};

	class CCspInformations
	{
		long p_AddCNGCsps();
		long p_AddLegacyCsps();
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CCspInformations();
		static long UpdateRegistry(int);
		static long s_CreateFromAvailableCsps(ICspInformations * *);
		virtual long AddAvailableCsps();
		virtual long GetCspStatusFromProviderName(unsigned short *,X509KeySpec,ICspStatus * *);
		virtual long GetCspStatusesFromOperations(AlgorithmOperationFlags,ICspInformation *,ICspStatuses * *);
		virtual long GetEncryptionCspAlgorithms(ICspInformation *,ICspAlgorithms * *);
		virtual long GetHashAlgorithms(ICspInformation *,IObjectIds * *);
		virtual long get_ItemByName(unsigned short *,ICspInformation * *);
		~CCspInformations();
	};

	struct CCspList
	{
		static long s_CreateKey(IX509PrivateKey *,ICspStatuses *);
		static long s_CreateOrderedCspStatusList(ICspInformations *,bool,IX509CertificateTemplateInternal *,IX509PrivateKey *,bool,X509KeySpec,ICspStatuses * *);
	};

	class CCspStatus
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CCspStatus();
		static long UpdateRegistry(int);
		static long s_Create(ICspInformation *,ICspAlgorithm *,ICspStatus * *);
		static long s_GetOrdinal(ICspStatus *,long *);
		static long s_PutOrdinal(ICspStatus *,long);
		virtual long Initialize(ICspInformation *,ICspAlgorithm *);
		virtual long get_CspAlgorithm(ICspAlgorithm * *);
		virtual long get_CspInformation(ICspInformation * *);
		virtual long get_DisplayName(unsigned short * *);
		virtual long get_EnrollmentStatus(IX509EnrollmentStatus * *);
		virtual long get_Ordinal(long *);
		virtual long put_CspAlgorithm(ICspAlgorithm *);
		virtual long put_Ordinal(long);
		~CCspStatus();
	};

	class CCspStatuses
	{
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long get_ItemByName(unsigned short *,unsigned short *,ICspStatus * *);
		virtual long get_ItemByOperations(unsigned short *,unsigned short *,AlgorithmOperationFlags,ICspStatus * *);
		virtual long get_ItemByOrdinal(long,ICspStatus * *);
		virtual long get_ItemByProvider(ICspStatus *,ICspStatus * *);
		~CCspStatuses();
	};

	struct CCustomRequestUI
	{
		virtual EnrollmentUIFlags GetUIFlags();
		virtual long InitEnrollment(CX509EnrollmentManager *);
		virtual void Enroll();
	};

	struct CESecurity
	{
		static long CheckSafetyCaller(WebSecurityLevel,unsigned short const *);
		static long FindSecurityLevelFromTypeInfo(ITypeInfo *,unsigned short const *,long,unsigned short,WebSecurityLevel *,unsigned short * *);
		static long GetExceptionInfoFromErrorInfo(long,unsigned short const *,unsigned short const *,tagEXCEPINFO *);
	};

	class CEncodedData
	{
	protected:
		virtual long _Initialize(unsigned short const *,bool,CByteArray *);
		virtual long _Initialize(unsigned short const *,bool,EncodingType,unsigned short *);
	public:
		CEncodedData();
		virtual long Initialize(IObjectId *,bool,EncodingType,unsigned short *,bool *,unsigned short * *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual ~CEncodedData();
	};

	class CEoboEnrollment
	{
		virtual EnrollmentUIFlags GetUIFlags();
		virtual long InitEnrollment(CX509EnrollmentManager *);
	};

	class CEoboUserSelection
	{
		long BackupOrRestoreCspSelection(ICspStatuses *,bool);
		static long FindSelectedItem(IX509Enrollments *,IX509Enrollment * *);
		static long GetCspName(ICspStatus *,unsigned short * *);
		static long GetCspStatuses(IX509Enrollment *,ICspStatuses * *);
		static long RemoveKeyProvInfo(IX509Enrollment *);
	public:
		long Backup(IX509Enrollments *);
		long Restore(IX509Enrollments *);
		~CEoboUserSelection();
	};

	class CEventData
	{
		long AddCertHash(_CERT_CONTEXT const *);
		long AddEnhancedKeyUsage(char *);
		long AddEnhancedKeyUsages(_CERT_CONTEXT const *);
		long AddExpirationDate(_FILETIME *);
		long AddSubjectNames(_CERT_CONTEXT const *);
		long AddTemplateInfo(_CERT_CONTEXT const *);
		long WriteEndElement();
		long WriteOidAttributes(unsigned short const *,unsigned short const *);
		long WriteStartElement(_WS_XML_STRING *);
		long WriteStringAttribute(_WS_XML_STRING *,unsigned short const *);
		long WriteStringValue(_WS_XML_STRING *,unsigned short const *);
	public:
		long AddAction(unsigned short *);
		long AddCertDetails(_WS_XML_STRING *,_CERT_CONTEXT const *);
		long AddKeyInfo(_CERT_CONTEXT const *);
		long Close();
		long GetBytes(_WS_BYTES *);
		long Open(bool);
		~CEventData();
	};

	class CHttpTemplateBuilder
	{
		long BuildExtensions(CertificateEnrollmentPolicy const *,CX509CertificateTemplate *);
		long BuildOidCollection(int const *,unsigned int,ObjectIdGroupId,IObjectIds * *);
		long BuildOidCollectionFromExtensionValue(char const *,ObjectIdGroupId,unsigned char const *,unsigned long,IObjectIds * *);
		long BuildOidObject(OID const *,ObjectIdGroupId,IObjectId * *);
		long BuildOidObject(int,ObjectIdGroupId,IObjectId * *);
		long ConstructTemplate(unsigned short *,CertificateEnrollmentPolicy const *,CX509CertificateTemplate *);
	public:
		long CreateTemplateFromPolicy(unsigned short *,CertificateEnrollmentPolicy const *,IX509CertificateTemplateInternal * *);
	};

	struct CKeyIdCert
	{
		long Initialize(bool,bool,_CERT_CONTEXT const *,_KEYREPAIRSTATS *);
		long RepairCert(bool,_CRYPT_KEY_PROV_INFO const *,_FILETIME const *);
	};

	struct CKeyIdCertList
	{
		long AddCert(_CERT_CONTEXT const *,bool);
		long GetKeyState(bool *,bool *);
		long RepairKeys(_FILETIME const *);
		long VerifyAndSaveKeyProvInfo(CKeyIdCert *,_CERT_CONTEXT const *);
		void Dump(unsigned long);
		~CKeyIdCertList();
	};

	class CKeyRepair
	{
		long p_AddCert(_CERT_CONTEXT const *,bool);
		long p_AddCertsFromStore(void *,bool);
		long p_CheckKeyIdAndSaveKeyProvInfo(_CRYPT_KEY_PROV_INFO const *);
		long p_FindKeyIdCertList(bool,unsigned long,unsigned char const *,CKeyIdCertList * *);
		long p_GetKeyState(unsigned long *,unsigned long *);
		long p_RepairKeys();
		long p_SearchKeys(bool);
		void p_DumpKeyId(unsigned short const *,unsigned long,unsigned long,unsigned char const *);
	public:
		long InitializeFromCertStores(bool);
		long RepairKeys();
		void Dump();
		~CKeyRepair();
	};

	struct CManualEnrollment
	{
		virtual EnrollmentUIFlags GetUIFlags();
		virtual long InitEnrollment(CX509EnrollmentManager *);
	};

	class CObjectId
	{
		long p_Initialize(CERTENROLL_OBJECTID,ObjectIdGroupId,ObjectIdPublicKeyFlags,AlgorithmFlags,unsigned short *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static bool s_PreferCNGValid();
		static int s_fnEnumFirstOID(_CRYPT_OID_INFO const *,void *);
		static long UpdateRegistry(int);
		static long s_Create(unsigned short const *,unsigned short const *,ObjectIdGroupId,IObjectId * *);
		static long s_CreateFromAlgorithmName(unsigned short *,long,ObjectIdGroupId,AlgorithmFlags,KeyAlgorithmType,KeyAlgorithmType *,IObjectId * *);
		static long s_CreateFromObjIdA(char const *,ObjectIdGroupId,IObjectId * *);
		static long s_CreateFromObjectId(IObjectId *,ObjectIdGroupId,IObjectId * *);
		static long s_FindOIDInfo(ObjectIdGroupId,ObjectIdPublicKeyFlags,unsigned long,unsigned short const *,_CRYPT_OID_INFO const * *);
		static long s_GetKeyAlgorithmNames(IObjectId *,KeyAlgorithmType,KeyAlgorithmType *,unsigned short * *,unsigned short * *,unsigned short * *);
		static long s_GetLength(IObjectId *,long *);
		static long s_MarshalObjIdA(IObjectId *,char * *);
		static long s_ValidateGroupId(IObjectId *,ObjectIdGroupId,ObjectIdPublicKeyFlags,short *);
		static long s_ValidateGroupIdFromObjId(unsigned short const *,ObjectIdGroupId,ObjectIdPublicKeyFlags,short *);
		virtual long GetAlgorithmName(ObjectIdGroupId,ObjectIdPublicKeyFlags,unsigned short * *);
		virtual long InitializeFromAlgorithmName(ObjectIdGroupId,ObjectIdPublicKeyFlags,AlgorithmFlags,unsigned short *);
		virtual long InitializeFromName(CERTENROLL_OBJECTID);
		virtual long InitializeFromValue(unsigned short *);
		virtual long _GetAlgorithmType(KeyAlgorithmType *);
		virtual long _GetGroupId(ObjectIdGroupId *);
		virtual long _GetLength(long *);
		virtual long _GetOidInfo(_CRYPT_OID_INFO const * *);
		virtual long _MarshalObjIdA(char * *);
		virtual long _RegisterOidInfo();
		virtual long get_FriendlyName(unsigned short * *);
		virtual long get_Name(CERTENROLL_OBJECTID *);
		virtual long get_Value(unsigned short * *);
		virtual long put_FriendlyName(unsigned short *);
		~CObjectId();
	};

	class CObjectIds
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Create(IObjectIds * *);
		static long s_GetIndexByObjId(IObjectIds *,unsigned short const *,long *);
		static long s_GetIndexByObjectId(IObjectIds *,IObjectId *,long *);
		virtual long Add(IObjectId *);
		virtual long AddRange(IObjectIds *);
		~CObjectIds();
	};

	class COrderedCAStatuses
	{
		static int fnSortCAStatusSiteCost(void const *,void const *);
		static long p_RandomSort(_FILETIME,long,COrderedCAStatuses::_CAStatusEntry *);
		void p_Cleanup();
	public:
		long GetCAStatus(long,ICAStatus * *);
		long Initialize(X509CertificateEnrollmentContext,ICAStatuses *);
	};

	class CPkcs10
	{
		long p_ComputeSignature();
		long p_DecodeAttributes(_CRYPT_ATTRIBUTE const *,unsigned long);
		long p_DecodeContent(unsigned char const *,unsigned long);
		long p_DetermineNullSigned();
		long p_EncodeToBeSigned();
		long p_SetKey(IX509PublicKey *,IX509PrivateKey *);
		long p_VerifyEncodingMode();
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CPkcs10();
		static long UpdateRegistry(int);
		static long s_Create(IPkcs10 * *);
		virtual long CheckSignature(Pkcs10AllowedSignatureTypes);
		virtual long Encode();
		virtual long EncodeContent();
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long ResetForEncode();
		virtual long get_CryptAttributes(ICryptAttributes * *);
		virtual long get_Encoding(short *);
		virtual long get_NullSigned(short *);
		virtual long get_PrivateKey(IX509PrivateKey * *);
		virtual long get_PublicKey(IX509PublicKey * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_RawDataToBeSigned(EncodingType,unsigned short * *);
		virtual long get_Signature(EncodingType,unsigned short * *);
		virtual long get_SignatureInformation(IX509SignatureInformation * *);
		virtual long get_Signed(short *);
		virtual long get_Subject(IX500DistinguishedName * *);
		virtual long get_Version(long *);
		virtual long put_PrivateKey(IX509PrivateKey *);
		virtual long put_PublicKey(IX509PublicKey *);
		virtual long put_Subject(IX500DistinguishedName *);
		virtual long put_Version(long);
		~CPkcs10();
	};

	class CPolicyDownloader
	{
		long AddServerTemplatePairs(IX509EnrollmentPolicyServer *);
		long BuildEndPointArray(ATL::CSimpleArray<WebServiceEndPoint,ATL::CSimpleArrayEqualHelper<WebServiceEndPoint> > &);
		long SortCEPs(_FILETIME);
		long TryLoadFromCache(_FILETIME);
		static long s_GetCacheCost(unsigned short *,IX509EnrollmentPolicyServer *,X509CertificateEnrollmentContext,long *);
	public:
		long GetTemplatesFromCEPGroup(HWND__ *,X509CertificateEnrollmentContext);
		long RegisterOidInfo(IX509EnrollmentPolicyServer *);
		virtual long Execute(int,X509EnrollmentAuthFlags,unsigned short *,unsigned short *,unsigned int *,bool *);
		virtual long LogAuthFailureEvent(X509CertificateEnrollmentContext,long,unsigned short *,unsigned short *,unsigned short *,X509EnrollmentAuthFlags);
		~CPolicyDownloader();
	};

	class CPolicyQualifier
	{
		long _DecodeFlags();
		long _DecodeUrl();
		long _DecodeUserNotice();
		long _EncodeFlags();
		long _EncodeUrl();
		long _EncodeUserNotice();
	public:
		long _InitializeDecode(_CERT_POLICY_QUALIFIER_INFO *);
		static long UpdateRegistry(int);
		virtual long InitializeEncode(unsigned short *,PolicyQualifierType);
		virtual long _Marshal(_CERT_POLICY_QUALIFIER_INFO *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_Qualifier(unsigned short * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_Type(PolicyQualifierType *);
		virtual ~CPolicyQualifier();
	};

	class CPolicyQualifiers
	{
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		~CPolicyQualifiers();
	};

	struct CRequestParameters
	{
		~CRequestParameters();
	};

	struct CRetrievePendingHttp
	{
		long Retrieve(X509CertificateEnrollmentContext,X509EnrollmentAuthFlags,unsigned short *,unsigned short *,long *);
		virtual long Execute(int,X509EnrollmentAuthFlags,unsigned short *,unsigned short *,unsigned int *,bool *);
		virtual long LogAuthFailureEvent(X509CertificateEnrollmentContext,long,unsigned short *,unsigned short *,unsigned short *,X509EnrollmentAuthFlags);
	};

	class CSignerCertificate
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void p_SetDefaultContextString(_CERT_CONTEXT const *);
	public:
		static long UpdateRegistry(int);
		static long s_BuildCertContext(CertUpdateFlags,bool,long,unsigned short *,_CRYPTOAPI_BLOB const *,_CERT_CONTEXT const * *);
		static long s_CreateFromCertificateContext(bool,X509PrivateKeyVerify,bool,long,unsigned short *,_CERT_CONTEXT const *,ISignerCertificate * *);
		static long s_CreateFromCertificateContextNoKey(bool,_CERT_CONTEXT const *,ISignerCertificate * *);
		static long s_CreateFromCertificateContextPrivateKey(_CERT_CONTEXT const *,IX509PrivateKey *,ISignerCertificate * *);
		static long s_GetCertificateContext(ISignerCertificate *,_CERT_CONTEXT const * *);
		static long s_InitializeFromCertificateContext(ISignerCertificate *,bool,X509PrivateKeyVerify,_CERT_CONTEXT const *);
		static long s_PutCertProperty(CertUpdateFlags,bool,long,unsigned short *,unsigned short *,EncodingType,_CERT_CONTEXT const * *);
		virtual long Initialize(short,X509PrivateKeyVerify,EncodingType,unsigned short *);
		virtual long _GetCertificateContext(_CERT_CONTEXT const * *);
		virtual long _InitializeFromCertificateContext(short,X509PrivateKeyVerify,_CERT_CONTEXT const *);
		virtual long _InitializeFromCertificateContextNoKey(short,_CERT_CONTEXT const *);
		virtual long _InitializeFromCertificateContextPrivateKey(_CERT_CONTEXT const *,IX509PrivateKey *);
		virtual long _InitializeNoKey(short,EncodingType,unsigned short *);
		virtual long get_Certificate(EncodingType,unsigned short * *);
		virtual long get_ParentWindow(long *);
		virtual long get_PrivateKey(IX509PrivateKey * *);
		virtual long get_SignatureInformation(IX509SignatureInformation * *);
		virtual long get_Silent(short *);
		virtual long get_UIContextMessage(unsigned short * *);
		virtual long put_ParentWindow(long);
		virtual long put_Pin(unsigned short *);
		virtual long put_Silent(short);
		virtual long put_UIContextMessage(unsigned short *);
		~CSignerCertificate();
	};

	class CSignerCertificates
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Create(ISignerCertificates * *);
		virtual long Find(ISignerCertificate *,long *);
		~CSignerCertificates();
	};

	struct CSingleEnrollment
	{
		CSingleEnrollment(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplate *,_CERT_CONTEXT const *,bool,bool,_CERT_CONTEXT const * *);
		virtual EnrollmentUIFlags GetUIFlags();
		virtual bool NeedNewEnrollmentCollection();
		virtual long InitEnrollment(CX509EnrollmentManager *);
		virtual long PostEnrollment(CX509EnrollmentManager *);
	};

	class CSmimeCapabilities
	{
		long p_AddFromCspAlgorithm(ICspAlgorithm *);
		long p_AddIfMissing(IObjectId *,long);
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long AddAvailableSmimeCapabilities(short);
		virtual long AddFromCsp(ICspInformation *);
		virtual long _Marshal(_CRYPT_SMIME_CAPABILITIES *);
		~CSmimeCapabilities();
	};

	struct CSmimeCapability
	{
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,long);
		virtual long _Marshal(_CRYPT_SMIME_CAPABILITY *);
		virtual long get_BitCount(long *);
		virtual long get_ObjectId(IObjectId * *);
		virtual ~CSmimeCapability();
	};

	struct CUIEnrollment
	{
		long RunWizard(HWND__ *);
		static unsigned long s_EnrollmentThreadProc(void *);
		virtual bool NeedNewEnrollmentCollection();
		virtual long PostEnrollment(CX509EnrollmentManager *);
		virtual void Enroll();
		virtual ~CUIEnrollment();
		void Release();
	};

	struct CUnknown2<CCertPropertyImpl>
	{
		~CUnknown2<CCertPropertyImpl>();
	};

	struct CUnknown2<CEncodedData>
	{
		~CUnknown2<CEncodedData>();
	};

	struct CUnknown2<CmcTaggedInfo>
	{
		~CUnknown2<CmcTaggedInfo>();
	};

	struct CUnknown2<X509CertificateResponse>
	{
		~CUnknown2<X509CertificateResponse>();
	};

	struct CUnknown<CByteArray>
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CUnknown<CByteArray>();
	};

	struct CUnknown<CCertPropertyImpl>
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CUnknown<CCertPropertyImpl>();
	};

	struct CUnknown<CEncodedData>
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CUnknown<CEncodedData>();
	};

	struct CUnknown<CmcTaggedInfo>
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CUnknown<CmcTaggedInfo>();
	};

	struct CUnknown<X509CertificateResponse>
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CUnknown<X509CertificateResponse>();
	};

	struct CUnknown<XCNSimpleCollection<CByteArray *> >
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CUnknown<XCNSimpleCollection<CByteArray *> >();
	};

	struct CUnknown<XCNSimpleCollection<CmcAttribute *> >
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CUnknown<XCNSimpleCollection<CmcAttribute *> >();
	};

	struct CUnknown<XCNSimpleCollection<CmcStatusInfo *> >
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CUnknown<XCNSimpleCollection<CmcStatusInfo *> >();
	};

	struct CUnknown<XCNSimpleCollection<CmcTaggedAttribute *> >
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CUnknown<XCNSimpleCollection<CmcTaggedAttribute *> >();
	};

	struct CUnknown<XCNSimpleCollection<CmcTaggedContentInfo *> >
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CUnknown<XCNSimpleCollection<CmcTaggedContentInfo *> >();
	};

	struct CUnknown<XCNSimpleCollection<CmcTaggedRequest *> >
	{
		virtual long QueryInterface(_GUID const &,void * *);
		virtual unsigned long AddRef();
		virtual unsigned long Release();
		~CUnknown<XCNSimpleCollection<CmcTaggedRequest *> >();
	};

	struct CWindowsEvents
	{
		long LogXmlEvent(bool,_EVENT_DESCRIPTOR const *,unsigned char *,unsigned long);
		long Register();
		long Unregister();
	};

	class CX500DistinguishedName
	{
		long p_Initialize(_CRYPTOAPI_BLOB const *,unsigned short const *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Create(IX500DistinguishedName * *);
		static long s_CreateFromNameBlob(_CRYPTOAPI_BLOB const *,IX500DistinguishedName * *);
		virtual long Decode(unsigned short *,EncodingType,X500NameFlags);
		virtual long Encode(unsigned short *,X500NameFlags);
		virtual long get_EncodedName(EncodingType,unsigned short * *);
		virtual long get_Name(unsigned short * *);
		~CX500DistinguishedName();
	};

	class CX509Attribute
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Create(IX509Attribute * *);
		static long s_CreateFromAttributeBlob(char const *,unsigned char const *,unsigned long,IX509Attribute * *);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		~CX509Attribute();
	};

	struct CX509AttributeArchiveKey
	{
		CX509AttributeArchiveKey();
		static long UpdateRegistry(int);
		static long s_CreateDecode(unsigned char const *,unsigned long,IX509AttributeArchiveKey * *);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(IX509PrivateKey *,EncodingType,unsigned short *,IObjectId *,long);
		virtual long get_EncryptedKeyBlob(EncodingType,unsigned short * *);
		virtual long get_EncryptionAlgorithm(IObjectId * *);
		virtual long get_EncryptionStrength(long *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		~CX509AttributeArchiveKey();
	};

	struct CX509AttributeArchiveKeyHash
	{
		CX509AttributeArchiveKeyHash();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncodeFromEncryptedKeyBlob(EncodingType,unsigned short *);
		virtual long _GetHashAlgorithm(IObjectId * *);
		virtual long _PutHashAlgorithm(IObjectId *);
		virtual long get_EncryptedKeyHashBlob(EncodingType,unsigned short * *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		~CX509AttributeArchiveKeyHash();
	};

	class CX509AttributeArchiveKeyHashImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncodeFromEncryptedKeyBlob(EncodingType,unsigned short *);
		virtual long _GetHashAlgorithm(IObjectId * *);
		virtual long _PutHashAlgorithm(IObjectId *);
		virtual long get_EncryptedKeyHashBlob(EncodingType,unsigned short * *);
		virtual ~CX509AttributeArchiveKeyHashImpl();
	};

	class CX509AttributeArchiveKeyImpl
	{
		long _CertGetNameString(_CERT_CONTEXT const *,int,unsigned short * *);
		long _Decode();
		long _Encode();
		long _GetEncryptedKeyBlob(IX509PrivateKey *,EncodingType,unsigned short *,IObjectId *,long);
		long _VerifyPrivateKeyArchiveCertificate(_CERT_CONTEXT const *);
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(IX509PrivateKey *,EncodingType,unsigned short *,IObjectId *,long);
		virtual long get_EncryptedKeyBlob(EncodingType,unsigned short * *);
		virtual long get_EncryptionAlgorithm(IObjectId * *);
		virtual long get_EncryptionStrength(long *);
		virtual ~CX509AttributeArchiveKeyImpl();
	};

	struct CX509AttributeClientId
	{
		CX509AttributeClientId();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(RequestClientInfoClientId,unsigned short *,unsigned short *,unsigned short *);
		virtual long get_ClientId(RequestClientInfoClientId *);
		virtual long get_MachineDnsName(unsigned short * *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_ProcessName(unsigned short * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_UserSamName(unsigned short * *);
		~CX509AttributeClientId();
	};

	class CX509AttributeClientIdImpl
	{
		long _Decode();
		long _Encode();
		long _GetMachineDnsName();
		long _GetProcessName();
		long _GetUserName();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(RequestClientInfoClientId,unsigned short *,unsigned short *,unsigned short *);
		virtual long get_ClientId(RequestClientInfoClientId *);
		virtual long get_MachineDnsName(unsigned short * *);
		virtual long get_ProcessName(unsigned short * *);
		virtual long get_UserSamName(unsigned short * *);
		virtual ~CX509AttributeClientIdImpl();
	};

	struct CX509AttributeCspProvider
	{
		CX509AttributeCspProvider();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(X509KeySpec,unsigned short *,EncodingType,unsigned short *);
		virtual long get_KeySpec(X509KeySpec *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_ProviderName(unsigned short * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_Signature(EncodingType,unsigned short * *);
		~CX509AttributeCspProvider();
	};

	class CX509AttributeCspProviderImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(X509KeySpec,unsigned short *,EncodingType,unsigned short *);
		virtual long get_KeySpec(X509KeySpec *);
		virtual long get_ProviderName(unsigned short * *);
		virtual long get_Signature(EncodingType,unsigned short * *);
		virtual ~CX509AttributeCspProviderImpl();
	};

	struct CX509AttributeExtensions
	{
		CX509AttributeExtensions();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(IX509Extensions *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_X509Extensions(IX509Extensions * *);
		~CX509AttributeExtensions();
	};

	class CX509AttributeExtensionsImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(IX509Extensions *);
		virtual long get_X509Extensions(IX509Extensions * *);
		virtual ~CX509AttributeExtensionsImpl();
	};

	struct CX509AttributeOSVersion
	{
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(unsigned short *);
		virtual long get_OSVersion(unsigned short * *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		~CX509AttributeOSVersion();
	};

	class CX509AttributeOSVersionImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(unsigned short *);
		virtual long get_OSVersion(unsigned short * *);
		virtual ~CX509AttributeOSVersionImpl();
	};

	struct CX509AttributeRenewalCertificate
	{
		CX509AttributeRenewalCertificate();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(EncodingType,unsigned short *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_RenewalCertificate(EncodingType,unsigned short * *);
		~CX509AttributeRenewalCertificate();
	};

	class CX509AttributeRenewalCertificateImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(EncodingType,unsigned short *);
		virtual long get_RenewalCertificate(EncodingType,unsigned short * *);
		virtual ~CX509AttributeRenewalCertificateImpl();
	};

	class CX509Attributes
	{
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Create(IX509Attributes * *);
		virtual long Add(IX509Attribute *);
		virtual long get_IndexByObjectId(IObjectId *,long *);
		~CX509Attributes();
	};

	class CX509CertificateEncode
	{
		static long _EncodeCertificateToBeSigned(IX500DistinguishedName *,IX500DistinguishedName *,CByteArray *,IX509PublicKey *,_FILETIME,_FILETIME,IX509Extensions *,IX509SignatureInformation *,X509KeySpec,unsigned char * *,unsigned long *);
	public:
		static long CheckPublicKeySignature(CByteArray *,IX509PublicKey *);
		static long ComputeSignature(unsigned char const *,unsigned long,IX509PrivateKey *,IX509SignatureInformation *,unsigned char * *,unsigned long *);
		static long CreateCertificate(IX500DistinguishedName *,IX500DistinguishedName *,CByteArray *,IX509PublicKey *,_FILETIME,_FILETIME,IX509Extensions *,IX509PrivateKey *,IX509SignatureInformation *,CByteArray *,CByteArray *,CByteArray *);
		static long DecodeContent(X509CertificateEnrollmentContext,IX509SignatureInformation *,CByteArray *,IX500DistinguishedName * *,CByteArray *,double *,double *,IX509CertificateRequestPkcs10V3 * *);
		static long DecodeToBeSigned(unsigned char const *,unsigned long,IX509SignatureInformation *,CByteArray *,CByteArray *,CByteArray *);
		static long EncodeToBeSigned(unsigned char const *,unsigned long,unsigned char const *,unsigned long,IX509SignatureInformation *,X509KeySpec,unsigned char * *,unsigned long *);
		static long MarshalExtensions(IX509Extensions *,unsigned long *,_CERT_EXTENSION * *);
		static void FreeMarshaledExtensions(unsigned long,_CERT_EXTENSION *);
	};

	struct CX509CertificateRequest
	{
		static long s_AddAttribute(ICryptAttributes *,ICryptAttribute *,OpAddCollection);
		static long s_AddExtension(IX509Extensions *,IX509Extension *,OpAddCollection);
		static long s_AttributeValueFromAttributes(ICryptAttributes *,unsigned short const *,unsigned short * *);
		static long s_BuildContextString(X509CertificateEnrollmentContext,unsigned short * *);
		static long s_ClientIdFromAttributes(ICryptAttributes *,RequestClientInfoClientId *);
		static long s_CopyAttributes(ICryptAttributes *,ICryptAttributes *);
		static long s_CopyExtensions(IX509Extensions *,IX509Extensions *);
		static long s_CreateCriticalExtensions(IObjectIds * *);
		static long s_GetTemplate(IX509CertificateRequest *,IX509CertificateTemplateInternal * *);
		static long s_ParseContextString(unsigned short *,EncodingType,X509CertificateEnrollmentContext *);
		static long s_PutRequestParameters(IX509CertificateRequest *,CRequestParameters const *);
		static long s_RemoveNonCriticalExtensions(IX509Extensions *,unsigned short const *,IObjectIds *);
		static long s_UpdateAttributes(ICryptAttributes *,IX509Extensions *,IObjectIds *);
		static long s_UpdateExtensions(IX509Extensions *,IObjectIds *,IObjectIds *);
	};

	class CX509CertificateRequestCertificate
	{
		long p_AddDefaultExtensions(IX509Extensions *);
		long p_GetDateTimeValue(double,double *);
		long p_PutDateTimeValue(double,double *);
		long p_VerifyEncoding();
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509CertificateRequestCertificate();
		static long UpdateRegistry(int);
		virtual long CheckPublicKeySignature(IX509PublicKey *);
		virtual long CheckSignature(Pkcs10AllowedSignatureTypes);
		virtual long Encode();
		virtual long GetCspStatuses(X509KeySpec,ICspStatuses * *);
		virtual long GetInnerRequest(InnerRequestLevel,IX509CertificateRequest * *);
		virtual long Initialize(X509CertificateEnrollmentContext);
		virtual long InitializeDecode(unsigned short *,EncodingType);
		virtual long InitializeFromCertificate(X509CertificateEnrollmentContext,unsigned short *,EncodingType,X509RequestInheritOptions);
		virtual long InitializeFromPrivateKey(X509CertificateEnrollmentContext,IX509PrivateKey *,unsigned short *);
		virtual long InitializeFromPrivateKeyTemplate(X509CertificateEnrollmentContext,IX509PrivateKey *,IX509EnrollmentPolicyServer *,IX509CertificateTemplate *);
		virtual long InitializeFromPublicKey(X509CertificateEnrollmentContext,IX509PublicKey *,unsigned short *);
		virtual long InitializeFromTemplate(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplate *);
		virtual long InitializeFromTemplateName(X509CertificateEnrollmentContext,unsigned short *);
		virtual long IsSmartCard(short *);
		virtual long ResetForEncode();
		virtual long _AddAttributeFromBlob(char const *,int,unsigned char const *,unsigned long);
		virtual long _AddDefaultExtensions();
		virtual long _DecodeExtensions();
		virtual long _FreeAdditionalCertificates(_CERT_CONTEXT const * *,unsigned long);
		virtual long _GetAdditionalCertificates(_CERT_CONTEXT const * * *,unsigned long *);
		virtual long _GetIsClientInformationSuppressionAllowed(short *);
		virtual long _GetPrivateKey(IX509PrivateKey * *);
		virtual long _GetRenewalCertificateContext(_CERT_CONTEXT const * *);
		virtual long _GetTemplate(IX509CertificateTemplateInternal * *);
		virtual long _InitializeFromCertificateContext(X509CertificateEnrollmentContext,_CERT_CONTEXT const *,X509RequestInheritOptions);
		virtual long _InitializeFromTemplate(X509CertificateEnrollmentContext,IX509CertificateTemplateInternal *);
		virtual long _OpenKey();
		virtual long _PutClientIdWithClientInformationSuppressionAllowed(RequestClientInfoClientId);
		virtual long _PutRenew(short);
		virtual long _PutTemplate(IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *);
		virtual long _SuppressClientInformation();
		virtual long get_AlternateSignatureAlgorithm(short *);
		virtual long get_ClientId(RequestClientInfoClientId *);
		virtual long get_CriticalExtensions(IObjectIds * *);
		virtual long get_CryptAttributes(ICryptAttributes * *);
		virtual long get_CspInformations(ICspInformations * *);
		virtual long get_CspStatuses(ICspStatuses * *);
		virtual long get_EnrollmentContext(X509CertificateEnrollmentContext *);
		virtual long get_HashAlgorithm(IObjectId * *);
		virtual long get_Issuer(IX500DistinguishedName * *);
		virtual long get_KeyContainerNamePrefix(unsigned short * *);
		virtual long get_NotAfter(double *);
		virtual long get_NotBefore(double *);
		virtual long get_NullSigned(short *);
		virtual long get_OldCertificate(EncodingType,unsigned short * *);
		virtual long get_ParentWindow(long *);
		virtual long get_PolicyServer(IX509EnrollmentPolicyServer * *);
		virtual long get_PrivateKey(IX509PrivateKey * *);
		virtual long get_PublicKey(IX509PublicKey * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_RawDataToBeSigned(EncodingType,unsigned short * *);
		virtual long get_RenewalCertificate(EncodingType,unsigned short * *);
		virtual long get_ReuseKey(short *);
		virtual long get_SerialNumber(EncodingType,unsigned short * *);
		virtual long get_Signature(EncodingType,unsigned short * *);
		virtual long get_SignatureInformation(IX509SignatureInformation * *);
		virtual long get_SignerCertificate(ISignerCertificate * *);
		virtual long get_Silent(short *);
		virtual long get_SmimeCapabilities(short *);
		virtual long get_Subject(IX500DistinguishedName * *);
		virtual long get_SuppressDefaults(short *);
		virtual long get_SuppressOids(IObjectIds * *);
		virtual long get_Template(IX509CertificateTemplate * *);
		virtual long get_TemplateObjectId(IObjectId * *);
		virtual long get_Type(X509RequestType *);
		virtual long get_UIContextMessage(unsigned short * *);
		virtual long get_X509Extensions(IX509Extensions * *);
		virtual long put_AlternateSignatureAlgorithm(short);
		virtual long put_ClientId(RequestClientInfoClientId);
		virtual long put_CspInformations(ICspInformations *);
		virtual long put_HashAlgorithm(IObjectId *);
		virtual long put_Issuer(IX500DistinguishedName *);
		virtual long put_KeyContainerNamePrefix(unsigned short *);
		virtual long put_NotAfter(double);
		virtual long put_NotBefore(double);
		virtual long put_ParentWindow(long);
		virtual long put_RenewalCertificate(EncodingType,unsigned short *);
		virtual long put_SerialNumber(EncodingType,unsigned short *);
		virtual long put_SignerCertificate(ISignerCertificate *);
		virtual long put_Silent(short);
		virtual long put_SmimeCapabilities(short);
		virtual long put_Subject(IX500DistinguishedName *);
		virtual long put_SuppressDefaults(short);
		virtual long put_UIContextMessage(unsigned short *);
		~CX509CertificateRequestCertificate();
	};

	class CX509CertificateRequestCmc
	{
		long p_AddDefaultAttributes();
		long p_CheckSignature(ISignerCertificate *,short,Pkcs10AllowedSignatureTypes);
		long p_CreateMemberObjects(bool);
		long p_DecodeContent(unsigned short *);
		long p_DecodeSignature(unsigned long,_CERT_CONTEXT const *,short *,IX509SignatureInformation *,short *);
		long p_EncodeContent(unsigned short *,bool,ICryptAttribute *,unsigned short * *);
		long p_EncodeInnerRequest(bool *,unsigned short * *);
		long p_EncodePkcs7(ICryptAttribute *,unsigned short *);
		long p_GetPrivateKeyForArchival(IX509PrivateKey * *);
		long p_Initialize(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *,IX509CertificateRequest *,short,_CERT_CONTEXT const *,X509RequestInheritOptions);
		long p_VerifyEncoding();
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void p_Cleanup();
	public:
		CX509CertificateRequestCmc();
		static long UpdateRegistry(int);
		static long s_CreateDecode(X509CertificateEnrollmentContext,unsigned short *,EncodingType,IX509CertificateRequestCmc * *);
		static long s_InitializeFromCertificateContext(IX509CertificateRequestCmc *,X509CertificateEnrollmentContext,_CERT_CONTEXT const *,X509RequestInheritOptions,bool);
		virtual long CheckCertificateSignature(ISignerCertificate *,short);
		virtual long CheckSignature(Pkcs10AllowedSignatureTypes);
		virtual long Encode();
		virtual long GetInnerRequest(InnerRequestLevel,IX509CertificateRequest * *);
		virtual long Initialize(X509CertificateEnrollmentContext);
		virtual long InitializeDecode(unsigned short *,EncodingType);
		virtual long InitializeFromCertificate(X509CertificateEnrollmentContext,short,unsigned short *,EncodingType,X509RequestInheritOptions);
		virtual long InitializeFromInnerRequest(IX509CertificateRequest *);
		virtual long InitializeFromInnerRequestTemplate(IX509CertificateRequest *,IX509EnrollmentPolicyServer *,IX509CertificateTemplate *);
		virtual long InitializeFromInnerRequestTemplateName(IX509CertificateRequest *,unsigned short *);
		virtual long InitializeFromTemplate(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplate *);
		virtual long InitializeFromTemplateName(X509CertificateEnrollmentContext,unsigned short *);
		virtual long ResetForEncode();
		virtual long _CheckSignature(ISignerCertificate *,short,Pkcs10AllowedSignatureTypes);
		virtual long _DecodePkcs7(unsigned short *,EncodingType,short,unsigned long *,unsigned short * *);
		virtual long _DecodeSignature(unsigned long,_CERT_CONTEXT const *,short *,IX509SignatureInformation *,short *,_CMSG_CMS_SIGNER_INFO * *,ISignerCertificate * *);
		virtual long _EncodePkcs7(IX509CertificateRequest *,IX509SignatureInformation *,unsigned short *,EncodingType,ISignerCertificates *,ICryptAttributes *,ICryptAttributes *);
		virtual long _GetIsClientInformationSuppressionAllowed(short *);
		virtual long _GetTemplate(IX509CertificateTemplateInternal * *);
		virtual long _InitializeCreateInnerRequestPkcs10(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *,short,_CERT_CONTEXT const *,X509RequestInheritOptions);
		virtual long _InitializeFromCertificateContext(X509CertificateEnrollmentContext,_CERT_CONTEXT const *,X509RequestInheritOptions,short);
		virtual long _InitializeFromInnerRequestCmc(IX509CertificateRequest *);
		virtual long _PutInnerRequest(IX509CertificateRequest *);
		virtual long _PutRenewalCertificate(EncodingType,unsigned short *,ISignerCertificate * *);
		virtual long _PutRenewalCertificateContext(_CERT_CONTEXT const *);
		virtual long _PutTemplate(IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *);
		virtual long _SuppressClientInformation();
		virtual long get_AlternateSignatureAlgorithm(short *);
		virtual long get_ArchivePrivateKey(short *);
		virtual long get_ClientId(RequestClientInfoClientId *);
		virtual long get_CriticalExtensions(IObjectIds * *);
		virtual long get_CryptAttributes(ICryptAttributes * *);
		virtual long get_CspInformations(ICspInformations * *);
		virtual long get_EncryptedKeyHash(EncodingType,unsigned short * *);
		virtual long get_EncryptionAlgorithm(IObjectId * *);
		virtual long get_EncryptionStrength(long *);
		virtual long get_EnrollmentContext(X509CertificateEnrollmentContext *);
		virtual long get_HashAlgorithm(IObjectId * *);
		virtual long get_KeyArchivalCertificate(EncodingType,unsigned short * *);
		virtual long get_NameValuePairs(IX509NameValuePairs * *);
		virtual long get_NullSigned(short *);
		virtual long get_ParentWindow(long *);
		virtual long get_PolicyServer(IX509EnrollmentPolicyServer * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_RenewalCertificate(EncodingType,unsigned short * *);
		virtual long get_RequesterName(unsigned short * *);
		virtual long get_SenderNonce(EncodingType,unsigned short * *);
		virtual long get_SignatureInformation(IX509SignatureInformation * *);
		virtual long get_SignerCertificate(ISignerCertificate * *);
		virtual long get_SignerCertificates(ISignerCertificates * *);
		virtual long get_Silent(short *);
		virtual long get_SuppressDefaults(short *);
		virtual long get_SuppressOids(IObjectIds * *);
		virtual long get_Template(IX509CertificateTemplate * *);
		virtual long get_TemplateObjectId(IObjectId * *);
		virtual long get_TransactionId(long *);
		virtual long get_Type(X509RequestType *);
		virtual long get_UIContextMessage(unsigned short * *);
		virtual long get_X509Extensions(IX509Extensions * *);
		virtual long put_AlternateSignatureAlgorithm(short);
		virtual long put_ArchivePrivateKey(short);
		virtual long put_ClientId(RequestClientInfoClientId);
		virtual long put_CspInformations(ICspInformations *);
		virtual long put_EncryptionAlgorithm(IObjectId *);
		virtual long put_EncryptionStrength(long);
		virtual long put_HashAlgorithm(IObjectId *);
		virtual long put_KeyArchivalCertificate(EncodingType,unsigned short *);
		virtual long put_ParentWindow(long);
		virtual long put_RenewalCertificate(EncodingType,unsigned short *);
		virtual long put_RequesterName(unsigned short *);
		virtual long put_SenderNonce(EncodingType,unsigned short *);
		virtual long put_SignerCertificate(ISignerCertificate *);
		virtual long put_Silent(short);
		virtual long put_SuppressDefaults(short);
		virtual long put_TransactionId(long);
		virtual long put_UIContextMessage(unsigned short *);
		~CX509CertificateRequestCmc();
	};

	class CX509CertificateRequestPkcs10
	{
		long p_AddAttestationAttributes();
		long p_AddAttributeFromBlob(char const *,int,unsigned char const *,unsigned long);
		long p_AddChallengePasswordAttribute(unsigned short *);
		long p_AddDefaultAttributes();
		long p_AddDefaultExtensions();
		long p_AddNameValuePairsAttribute();
		long p_ComputeKeyUsageExtension(bool,X509KeyUsageFlags *);
		long p_FinalizeKeyProperties();
		long p_GenerateNewKey(IX509PrivateKey *);
		long p_GetAttestationStatement(IX509PrivateKey *,unsigned __int64,unsigned char * *,unsigned long *);
		long p_GetCspStatuses(bool,X509KeySpec,ICspStatuses * *);
		long p_GetDeviceInfo(IX509PrivateKey *,unsigned __int64,unsigned char * *,unsigned long *,CByteArray *);
		long p_Initialize(X509CertificateEnrollmentContext,IX509PrivateKey *,IX509PublicKey *,IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *,_CERT_CONTEXT const *,X509RequestInheritOptions);
		long p_InitializeKey(IX509PrivateKey *,IX509PublicKey *,_CERT_CONTEXT const *,X509RequestInheritOptions,IObjectId * *);
		long p_InitializePrivateKeyFromTemplate(IX509PrivateKey *,bool,IObjectId * *);
		long p_InitializeTemplateName(X509CertificateEnrollmentContext,IX509PrivateKey *,IX509PublicKey *,unsigned short *);
		long p_SetKeyContainerNamePrefix(IX509PrivateKey *);
		long p_VerifyEncoding();
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void p_Cleanup(bool);
		void p_Init(bool);
	public:
		CX509CertificateRequestPkcs10();
		static long UpdateRegistry(int);
		static long s_CopyPrivateKeyRenewalProperties(X509RequestInheritOptions,IX509CertificateRequestPkcs10 *,ISignerCertificate *);
		static long s_Create(X509CertificateEnrollmentContext,CRequestParameters const *,IX509CertificateRequestPkcs10V3 * *);
		static long s_CreateDecode(X509CertificateEnrollmentContext,unsigned short *,EncodingType,IX509CertificateRequestPkcs10 * *);
		static long s_CreateFromCertificate(X509CertificateEnrollmentContext,unsigned short *,EncodingType,X509RequestInheritOptions,CRequestParameters const *,IX509CertificateRequestPkcs10V3 * *);
		static long s_CreateFromPrivateKey(X509CertificateEnrollmentContext,IX509PrivateKey *,unsigned short *,CRequestParameters const *,IX509CertificateRequestPkcs10V3 * *);
		static long s_CreateFromPublicKey(X509CertificateEnrollmentContext,IX509PublicKey *,unsigned short *,CRequestParameters const *,IX509CertificateRequestPkcs10V3 * *);
		static long s_CreateFromTemplate(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *,CRequestParameters const *,IX509CertificateRequestPkcs10V3 * *);
		static long s_CreateFromTemplateName(X509CertificateEnrollmentContext,unsigned short *,CRequestParameters const *,IX509CertificateRequestPkcs10V3 * *);
		static long s_InitializeFromCertificateContext(IX509CertificateRequestPkcs10 *,X509CertificateEnrollmentContext,_CERT_CONTEXT const *,X509RequestInheritOptions);
		static long s_OpenKey(IX509CertificateRequestPkcs10 *);
		static long s_PutRequestParameters(IX509CertificateRequestPkcs10V3 *,CRequestParameters const *);
		virtual long CheckSignature(Pkcs10AllowedSignatureTypes);
		virtual long Encode();
		virtual long GetCspStatuses(X509KeySpec,ICspStatuses * *);
		virtual long GetInnerRequest(InnerRequestLevel,IX509CertificateRequest * *);
		virtual long Initialize(X509CertificateEnrollmentContext);
		virtual long InitializeDecode(unsigned short *,EncodingType);
		virtual long InitializeFromCertificate(X509CertificateEnrollmentContext,unsigned short *,EncodingType,X509RequestInheritOptions);
		virtual long InitializeFromPrivateKey(X509CertificateEnrollmentContext,IX509PrivateKey *,unsigned short *);
		virtual long InitializeFromPrivateKeyTemplate(X509CertificateEnrollmentContext,IX509PrivateKey *,IX509EnrollmentPolicyServer *,IX509CertificateTemplate *);
		virtual long InitializeFromPublicKey(X509CertificateEnrollmentContext,IX509PublicKey *,unsigned short *);
		virtual long InitializeFromPublicKeyTemplate(X509CertificateEnrollmentContext,IX509PublicKey *,IX509EnrollmentPolicyServer *,IX509CertificateTemplate *);
		virtual long InitializeFromTemplate(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplate *);
		virtual long InitializeFromTemplateName(X509CertificateEnrollmentContext,unsigned short *);
		virtual long IsSmartCard(short *);
		virtual long ResetForEncode();
		virtual long _AddAttributeFromBlob(char const *,int,unsigned char const *,unsigned long);
		virtual long _AddDefaultExtensions();
		virtual long _DecodeExtensions();
		virtual long _FreeAdditionalCertificates(_CERT_CONTEXT const * *,unsigned long);
		virtual long _GetAdditionalCertificates(_CERT_CONTEXT const * * *,unsigned long *);
		virtual long _GetIsClientInformationSuppressionAllowed(short *);
		virtual long _GetPrivateKey(IX509PrivateKey * *);
		virtual long _GetRenewalCertificateContext(_CERT_CONTEXT const * *);
		virtual long _GetTemplate(IX509CertificateTemplateInternal * *);
		virtual long _InitializeFromCertificateContext(X509CertificateEnrollmentContext,_CERT_CONTEXT const *,X509RequestInheritOptions);
		virtual long _OpenKey();
		virtual long _PutClientIdWithClientInformationSuppressionAllowed(RequestClientInfoClientId);
		virtual long _PutRenew(short);
		virtual long _PutTemplate(IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *);
		virtual long _SuppressClientInformation();
		virtual long get_AlternateSignatureAlgorithm(short *);
		virtual long get_AttestPrivateKey(short *);
		virtual long get_AttestPrivateKeyPreferred(short *);
		virtual long get_AttestationEncryptionCertificate(EncodingType,unsigned short * *);
		virtual long get_ChallengePassword(unsigned short * *);
		virtual long get_ClaimType(KeyAttestationClaimType *);
		virtual long get_ClientId(RequestClientInfoClientId *);
		virtual long get_CriticalExtensions(IObjectIds * *);
		virtual long get_CryptAttributes(ICryptAttributes * *);
		virtual long get_CspInformations(ICspInformations * *);
		virtual long get_CspStatuses(ICspStatuses * *);
		virtual long get_EncryptionAlgorithm(IObjectId * *);
		virtual long get_EncryptionStrength(long *);
		virtual long get_EnrollmentContext(X509CertificateEnrollmentContext *);
		virtual long get_HashAlgorithm(IObjectId * *);
		virtual long get_KeyContainerNamePrefix(unsigned short * *);
		virtual long get_NameValuePairs(IX509NameValuePairs * *);
		virtual long get_NullSigned(short *);
		virtual long get_OldCertificate(EncodingType,unsigned short * *);
		virtual long get_ParentWindow(long *);
		virtual long get_PolicyServer(IX509EnrollmentPolicyServer * *);
		virtual long get_PrivateKey(IX509PrivateKey * *);
		virtual long get_PublicKey(IX509PublicKey * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_RawDataToBeSigned(EncodingType,unsigned short * *);
		virtual long get_RenewalCertificate(EncodingType,unsigned short * *);
		virtual long get_ReuseKey(short *);
		virtual long get_Signature(EncodingType,unsigned short * *);
		virtual long get_SignatureInformation(IX509SignatureInformation * *);
		virtual long get_Silent(short *);
		virtual long get_SmimeCapabilities(short *);
		virtual long get_Subject(IX500DistinguishedName * *);
		virtual long get_SuppressDefaults(short *);
		virtual long get_SuppressOids(IObjectIds * *);
		virtual long get_Template(IX509CertificateTemplate * *);
		virtual long get_TemplateObjectId(IObjectId * *);
		virtual long get_Type(X509RequestType *);
		virtual long get_UIContextMessage(unsigned short * *);
		virtual long get_X509Extensions(IX509Extensions * *);
		virtual long put_AlternateSignatureAlgorithm(short);
		virtual long put_AttestPrivateKey(short);
		virtual long put_AttestPrivateKeyPreferred(short);
		virtual long put_AttestationEncryptionCertificate(EncodingType,unsigned short *);
		virtual long put_ChallengePassword(unsigned short *);
		virtual long put_ClaimType(KeyAttestationClaimType);
		virtual long put_ClientId(RequestClientInfoClientId);
		virtual long put_CspInformations(ICspInformations *);
		virtual long put_EncryptionAlgorithm(IObjectId *);
		virtual long put_EncryptionStrength(long);
		virtual long put_HashAlgorithm(IObjectId *);
		virtual long put_KeyContainerNamePrefix(unsigned short *);
		virtual long put_ParentWindow(long);
		virtual long put_RenewalCertificate(EncodingType,unsigned short *);
		virtual long put_Silent(short);
		virtual long put_SmimeCapabilities(short);
		virtual long put_Subject(IX500DistinguishedName *);
		virtual long put_SuppressDefaults(short);
		virtual long put_UIContextMessage(unsigned short *);
		~CX509CertificateRequestPkcs10();
	};

	class CX509CertificateRequestPkcs7
	{
		long p_AddCmcPrimarySignature(IX509SignatureInformation *,long,_CMSG_SIGNER_ENCODE_INFO *,CX509CertificateRequestPkcs7::_SIGALLOC *);
		long p_DecodeSignature(IX509CertificateRequestPkcs10 *);
		long p_EncodePkcs7(unsigned short *);
		long p_Initialize(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *,short,_CERT_CONTEXT const *,X509RequestInheritOptions);
		long p_InitializeFromInnerRequest(IX509CertificateRequest *,bool);
		long p_VerifyEncoding();
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void p_Cleanup();
		void p_FreePrimarySignature(CX509CertificateRequestPkcs7::_SIGALLOC const *);
	public:
		CX509CertificateRequestPkcs7();
		static long UpdateRegistry(int);
		static long s_Create(CRequestParameters const *,IX509CertificateRequestPkcs7 * *);
		static long s_DecodePkcs7(IX509CertificateRequestPkcs7 *,unsigned short *,EncodingType,short,unsigned long *,unsigned short * *);
		static long s_EncodePkcs7(IX509CertificateRequestPkcs7 *,IX509CertificateRequest *,IX509SignatureInformation *,unsigned short *,EncodingType,ISignerCertificates *,ICryptAttributes *,ICryptAttributes *);
		static long s_GetCertificate(X509CertificateEnrollmentContext,bool,long,unsigned short *,unsigned short *,EncodingType,X509RequestInheritOptions,_CERT_CONTEXT const * *);
		static long s_GetTemplateByContext(HWND__ *,X509CertificateEnrollmentContext,X509RequestInheritOptions,_CERT_CONTEXT const *,IX509EnrollmentPolicyServer * *,IX509CertificateTemplateInternal * *);
		static long s_InitializeCreateInnerRequestPkcs10(IX509CertificateRequestPkcs7 *,X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *,short,_CERT_CONTEXT const *,X509RequestInheritOptions);
		static long s_InitializeFromCertificateContext(IX509CertificateRequestPkcs7 *,X509CertificateEnrollmentContext,_CERT_CONTEXT const *,X509RequestInheritOptions,bool);
		static long s_InitializeFromInnerRequestCmc(IX509CertificateRequestPkcs7 *,IX509CertificateRequest *);
		static long s_PutRequestParameters(IX509CertificateRequestPkcs7 *,CRequestParameters const *);
		static long s_ValidateInheritOptions(_CERT_CONTEXT const *,short,X509RequestInheritOptions,X509RequestInheritOptions *);
		static long s_ValidateInheritOptionsFromCertificate(unsigned short *,EncodingType,short,X509RequestInheritOptions,X509RequestInheritOptions *);
		virtual long CheckCertificateSignature(short);
		virtual long Encode();
		virtual long GetInnerRequest(InnerRequestLevel,IX509CertificateRequest * *);
		virtual long Initialize(X509CertificateEnrollmentContext);
		virtual long InitializeDecode(unsigned short *,EncodingType);
		virtual long InitializeFromCertificate(X509CertificateEnrollmentContext,short,unsigned short *,EncodingType,X509RequestInheritOptions);
		virtual long InitializeFromInnerRequest(IX509CertificateRequest *);
		virtual long InitializeFromTemplate(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplate *);
		virtual long InitializeFromTemplateName(X509CertificateEnrollmentContext,unsigned short *);
		virtual long ResetForEncode();
		virtual long _CheckSignature(ISignerCertificate *,short,Pkcs10AllowedSignatureTypes);
		virtual long _DecodePkcs7(unsigned short *,EncodingType,short,unsigned long *,unsigned short * *);
		virtual long _DecodeSignature(unsigned long,_CERT_CONTEXT const *,short *,IX509SignatureInformation *,short *,_CMSG_CMS_SIGNER_INFO * *,ISignerCertificate * *);
		virtual long _EncodePkcs7(IX509CertificateRequest *,IX509SignatureInformation *,unsigned short *,EncodingType,ISignerCertificates *,ICryptAttributes *,ICryptAttributes *);
		virtual long _GetIsClientInformationSuppressionAllowed(short *);
		virtual long _GetTemplate(IX509CertificateTemplateInternal * *);
		virtual long _InitializeCreateInnerRequestPkcs10(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *,short,_CERT_CONTEXT const *,X509RequestInheritOptions);
		virtual long _InitializeFromCertificateContext(X509CertificateEnrollmentContext,_CERT_CONTEXT const *,X509RequestInheritOptions,short);
		virtual long _InitializeFromInnerRequestCmc(IX509CertificateRequest *);
		virtual long _PutInnerRequest(IX509CertificateRequest *);
		virtual long _PutRenewalCertificate(EncodingType,unsigned short *,ISignerCertificate * *);
		virtual long _PutRenewalCertificateContext(_CERT_CONTEXT const *);
		virtual long _PutTemplate(IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *);
		virtual long _SuppressClientInformation();
		virtual long get_AlternateSignatureAlgorithm(short *);
		virtual long get_ClientId(RequestClientInfoClientId *);
		virtual long get_CspInformations(ICspInformations * *);
		virtual long get_EnrollmentContext(X509CertificateEnrollmentContext *);
		virtual long get_HashAlgorithm(IObjectId * *);
		virtual long get_ParentWindow(long *);
		virtual long get_PolicyServer(IX509EnrollmentPolicyServer * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_RenewalCertificate(EncodingType,unsigned short * *);
		virtual long get_RequesterName(unsigned short * *);
		virtual long get_SignerCertificate(ISignerCertificate * *);
		virtual long get_Silent(short *);
		virtual long get_SuppressDefaults(short *);
		virtual long get_Template(IX509CertificateTemplate * *);
		virtual long get_Type(X509RequestType *);
		virtual long get_UIContextMessage(unsigned short * *);
		virtual long put_AlternateSignatureAlgorithm(short);
		virtual long put_ClientId(RequestClientInfoClientId);
		virtual long put_CspInformations(ICspInformations *);
		virtual long put_HashAlgorithm(IObjectId *);
		virtual long put_ParentWindow(long);
		virtual long put_RenewalCertificate(EncodingType,unsigned short *);
		virtual long put_RequesterName(unsigned short *);
		virtual long put_SignerCertificate(ISignerCertificate *);
		virtual long put_Silent(short);
		virtual long put_SuppressDefaults(short);
		virtual long put_UIContextMessage(unsigned short *);
		~CX509CertificateRequestPkcs7();
	};

	class CX509CertificateRevocationList
	{
		long p_DecodeContent(unsigned char *,unsigned long);
		long p_DetermineNullSigned();
		long p_FindSignerCertificate();
		long p_GetDateTimeValue(double,double *);
		long p_PutDateTimeValue(double,double *);
		long p_SetAKIAndIssuerFromSignerCert(_CERT_CONTEXT const *);
		long p_SetExtension(char const *,_CRYPTOAPI_BLOB const *,OpAddCollection);
		long p_VerifyEncoding();
		static long s_EncodeCRLToBeSigned(IX500DistinguishedName *,_FILETIME,_FILETIME,IX509CertificateRevocationListEntries *,IX509Extensions *,IX509SignatureInformation *,unsigned long,unsigned char * *,unsigned long *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509CertificateRevocationList();
		static long UpdateRegistry(int);
		virtual long CheckPublicKeySignature(IX509PublicKey *);
		virtual long CheckSignature();
		virtual long Encode();
		virtual long Initialize();
		virtual long InitializeDecode(unsigned short *,EncodingType);
		virtual long ResetForEncode();
		virtual long get_AlternateSignatureAlgorithm(short *);
		virtual long get_BaseCRL(short *);
		virtual long get_CAVersion(long *);
		virtual long get_CRLNumber(EncodingType,unsigned short * *);
		virtual long get_CriticalExtensions(IObjectIds * *);
		virtual long get_HashAlgorithm(IObjectId * *);
		virtual long get_Issuer(IX500DistinguishedName * *);
		virtual long get_NextUpdate(double *);
		virtual long get_NullSigned(short *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_RawDataToBeSigned(EncodingType,unsigned short * *);
		virtual long get_Signature(EncodingType,unsigned short * *);
		virtual long get_SignatureInformation(IX509SignatureInformation * *);
		virtual long get_SignerCertificate(ISignerCertificate * *);
		virtual long get_ThisUpdate(double *);
		virtual long get_X509CRLEntries(IX509CertificateRevocationListEntries * *);
		virtual long get_X509Extensions(IX509Extensions * *);
		virtual long put_AlternateSignatureAlgorithm(short);
		virtual long put_CAVersion(long);
		virtual long put_CRLNumber(EncodingType,unsigned short *);
		virtual long put_HashAlgorithm(IObjectId *);
		virtual long put_Issuer(IX500DistinguishedName *);
		virtual long put_NextUpdate(double);
		virtual long put_SignerCertificate(ISignerCertificate *);
		virtual long put_ThisUpdate(double);
		~CX509CertificateRevocationList();
	};

	class CX509CertificateRevocationListEntries
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Create(IX509CertificateRevocationListEntries * *);
		virtual long Add(IX509CertificateRevocationListEntry *);
		virtual long AddRange(IX509CertificateRevocationListEntries *);
		virtual long get_IndexBySerialNumber(EncodingType,unsigned short *,long *);
		~CX509CertificateRevocationListEntries();
	};

	class CX509CertificateRevocationListEntry
	{
		long p_SetExtension(char const *,_CRYPTOAPI_BLOB const *,OpAddCollection);
		long p_VerifyInitialized();
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_CreateFromCRLEntry(_CRL_ENTRY const *,IX509CertificateRevocationListEntry * *);
		static long s_FindExtension(IX509Extensions *,char const *,IX509Extension * *);
		static long s_MarshalCRLEntries(IX509CertificateRevocationListEntries *,unsigned long *,_CRL_ENTRY * *);
		virtual long Initialize(EncodingType,unsigned short *,double);
		virtual long get_CriticalExtensions(IObjectIds * *);
		virtual long get_RevocationDate(double *);
		virtual long get_RevocationReason(CRLRevocationReason *);
		virtual long get_SerialNumber(EncodingType,unsigned short * *);
		virtual long get_X509Extensions(IX509Extensions * *);
		virtual long put_RevocationReason(CRLRevocationReason);
		~CX509CertificateRevocationListEntry();
	};

	class CX509CertificateTemplate
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void p_UnInitialize();
	public:
		CX509CertificateTemplate();
		static long UpdateRegistry(int);
		virtual long _GetApplicationPolicies(IObjectIds * *);
		virtual long _GetAsymmetricAlgorithm(unsigned short * *);
		virtual long _GetCommonName(unsigned short * *);
		virtual long _GetCriticalExtensions(IObjectIds * *);
		virtual long _GetCryptoServiceProviders(tagVARIANT *);
		virtual long _GetDescription(unsigned short * *);
		virtual long _GetDistinguishedName(unsigned short * *);
		virtual long _GetEncryptionAlgorithm(unsigned short * *);
		virtual long _GetEncryptionStrength(long *);
		virtual long _GetEnhancedKeyUsage(IObjectIds * *);
		virtual long _GetEnrollmentFlags(X509CertificateTemplateEnrollmentFlag *);
		virtual long _GetFriendlyName(unsigned short * *);
		virtual long _GetGeneralFlags(X509CertificateTemplateGeneralFlag *);
		virtual long _GetHashAlgorithm(unsigned short * *);
		virtual long _GetIsSmartCardOnly(ICspInformations *,short *);
		virtual long _GetKeySecurityDescriptor(unsigned short * *);
		virtual long _GetKeySpec(X509KeySpec *);
		virtual long _GetMajorVersion(long *);
		virtual long _GetMinKeySize(long *);
		virtual long _GetMinorVersion(long *);
		virtual long _GetNonLogonRASignatureCount(long *);
		virtual long _GetNonLogonSubjectNameRequired(short *);
		virtual long _GetOid(IObjectId * *);
		virtual long _GetPolicies(IObjectIds * *);
		virtual long _GetPolicyId(unsigned short * *);
		virtual long _GetPrivateKeyFlags(X509CertificateTemplatePrivateKeyFlag *);
		virtual long _GetPrivateKeyUsage(X509PrivateKeyUsageFlags *);
		virtual long _GetRAApplicationPolicies(IObjectIds * *);
		virtual long _GetRAPolicies(IObjectIds * *);
		virtual long _GetRASignatureCount(long *);
		virtual long _GetRenewalPeriod(_FILETIME *);
		virtual long _GetSchemaVersion(long *);
		virtual long _GetSecurityDescriptor(unsigned short * *);
		virtual long _GetSubjectNameFlags(X509CertificateTemplateSubjectNameFlag *);
		virtual long _GetSupersedeTemplates(tagVARIANT *);
		virtual long _GetValid(short *);
		virtual long _GetValidityPeriod(_FILETIME *);
		virtual long _GetX509Extensions(IX509Extensions * *);
		virtual long _InitializeFromInvalidName(unsigned short const *);
		virtual long _MatchTemplateName(unsigned short const *,short *);
		virtual long _RetrieveEnrollmentAccess(X509CertificateEnrollmentAccessFlag *);
		virtual long _SameTemplate(IX509CertificateTemplateInternal *,short *);
		virtual long get_Property(EnrollmentTemplateProperty,tagVARIANT *);
		~CX509CertificateTemplate();
	};

	class CX509CertificateTemplateADWritable
	{
		long _DeleteTemplate(ldap *,unsigned short *,void *);
		long _DoesTemplateOrOIDExistInDS(ldap *,bool *);
		long _FindMatchingTemplateInDS(ldap *,void * *);
		long _FindPropertyName(EnrollmentTemplateProperty,unsigned short const * *);
		long _GetStringArrayPropValue(tagVARIANT *,unsigned short * * *);
		long _SaveExtensions(void *,ldap *,tagVARIANT *);
		long _SaveTemplate(unsigned short *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509CertificateTemplateADWritable();
		static long UpdateRegistry(int);
		virtual long Commit(CommitTemplateFlags,unsigned short *);
		virtual long Initialize(IX509CertificateTemplate *);
		virtual long get_Property(EnrollmentTemplateProperty,tagVARIANT *);
		virtual long get_Template(IX509CertificateTemplate * *);
		virtual long put_Property(EnrollmentTemplateProperty,tagVARIANT);
		~CX509CertificateTemplateADWritable();
	};

	class CX509CertificateTemplates
	{
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Add(IX509CertificateTemplates *,IX509CertificateTemplateInternal *);
		static long s_GetItemByIndex(IX509CertificateTemplates *,long,IX509CertificateTemplateInternal * *);
		virtual long get_ItemByName(unsigned short *,IX509CertificateTemplate * *);
		virtual long get_ItemByOid(IObjectId *,IX509CertificateTemplate * *);
		~CX509CertificateTemplates();
	};

	class CX509EndorsementKey
	{
		long p_ExportPublicKey(_BCRYPT_RSAKEY_BLOB *,unsigned long,IX509PublicKey * *);
		long p_GetCertificateStore(unsigned __int64,void * *,void * *);
		long p_VerifyCertificateInStore(_CERT_CONTEXT const *,void *);
		long p_VerifyCertificatePublicKey(_CERT_CONTEXT const *,IX509PublicKey *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long AddCertificate(EncodingType,unsigned short *);
		virtual long Close();
		virtual long ExportPublicKey(IX509PublicKey * *);
		virtual long GetCertificateByIndex(short,long,EncodingType,unsigned short * *);
		virtual long GetCertificateCount(short,long *);
		virtual long Open();
		virtual long RemoveCertificate(EncodingType,unsigned short *);
		virtual long get_Length(long *);
		virtual long get_Opened(short *);
		virtual long get_ProviderName(unsigned short * *);
		virtual long put_ProviderName(unsigned short *);
		~CX509EndorsementKey();
	};

	class CX509Enrollment
	{
		bool p_GetOldCertHash(unsigned short * *);
		bool p_IsDisAllowRefresh();
		long p_AddCEPProperty(unsigned short *,unsigned short *,PolicyServerUrlFlags,X509EnrollmentAuthFlags,X509EnrollmentAuthFlags,unsigned short *,unsigned short *);
		long p_AddDCInfoAndRequesterMachineDnsName();
		long p_AddOriginatorProperty(_CERT_CONTEXT const *);
		long p_AddProperties(long,unsigned short *,ICertificationAuthorityInternal *,bool);
		long p_AddPropertyFromCert(EncodingType,unsigned short *,ICertProperty *);
		long p_AllowUntrustedCA(ISignerCertificates *,InstallResponseRestrictionFlags,bool,bool,unsigned short const *,bool *);
		long p_AppendRequestId(unsigned short * *);
		long p_BuildCAEndPointArray(ATL::CSimpleArray<WebServiceEndPoint,ATL::CSimpleArrayEqualHelper<WebServiceEndPoint> > &);
		long p_CheckCmcResponse(_CERT_CONTEXT const *);
		long p_CreateRequestForDefaultCep(unsigned short *,short,EncodingType,unsigned short * *);
		long p_CreateRequestObject(X509CertificateEnrollmentContext,short,long,IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *,bool,_CERT_CONTEXT const *,_CERT_CONTEXT const *,bool,IX509CertificateRequest * *);
		long p_DeleteCache(unsigned short *,unsigned short *);
		long p_EnrollCertificateFromCA();
		long p_EnrollNGCLogonCertificate();
		long p_EraseProperty(_tagPropertyInfo *);
		long p_GetAllowTrustedCA(InstallResponseRestrictionFlags,ISignerCertificates *,bool,unsigned short const *,bool *);
		long p_GetNameValuePair(unsigned short * *);
		long p_GetProperty(_tagPropertyInfo *);
		long p_GetTemplateName(X509CertificateEnrollmentContext,_CERT_CONTEXT const *,unsigned short * *);
		long p_InitializeCAs(ICertificationAuthorities *);
		long p_InitializeValues();
		long p_InstallCACertificate(_CERT_CONTEXT const *,void *);
		long p_InstallCertificates(bool,bool,ISignerCertificates *,unsigned short *,void *,unsigned short *,unsigned short *,unsigned short *,PolicyServerUrlFlags,X509EnrollmentAuthFlags,InstallResponseFlags,_CERT_CONTEXT const * *);
		long p_InstallEECertificate(bool,bool,_CERT_CONTEXT const *,void *,unsigned short *,unsigned short *,unsigned short *,PolicyServerUrlFlags,X509EnrollmentAuthFlags,InstallResponseFlags,_CERT_CONTEXT const * *);
		long p_InstallResponse(InstallResponseRestrictionFlags,unsigned short *,EncodingType,unsigned short *,unsigned short *,void *,InstallResponseFlags,unsigned short *,unsigned short *,PolicyServerUrlFlags,X509EnrollmentAuthFlags,bool,bool,_CERT_CONTEXT const * *,X509ResponseType *);
		long p_IsRAEnrollment(IX509CertificateRequestPkcs10V3 *,bool *);
		long p_IsSelfSigned(ISignerCertificates *,bool *);
		long p_LogAttestationFailureIfNeeded(long);
		long p_ObtainPendingInfo(long *,unsigned short * *,unsigned short * *,short *,bool *,X509EnrollmentAuthFlags *);
		long p_PutRenewal(bool);
		long p_PutStringProperty<ICertPropertyDescription,CCertPropertyDescription,13>(unsigned short *);
		long p_PutStringProperty<ICertPropertyFriendlyName,CCertPropertyFriendlyName,116>(unsigned short *);
		long p_PutStringProperty<ICertPropertyFriendlyName,CCertPropertyFriendlyName,11>(unsigned short *);
		long p_RemoveDummyCert(_CERT_CONTEXT const *);
		long p_RemoveDummyCertFromSmartCard(_CERT_CONTEXT const *);
		long p_RemoveProperty(CERTENROLL_PROPERTYID);
		long p_SaveError(unsigned short const *,long,unsigned long,EnrollmentEnrollStatus,long,bool);
		long p_SetCAExchangeCertificate(unsigned short *);
		long p_SetFriendlyNameForKey(_CERT_CONTEXT const *);
		long p_SetKeyContainerPrefix();
		long p_SetUIContextString(X509CertificateEnrollmentContext,IX509CertificateRequest *,bool,IX509CertificateTemplateInternal *,ISignerCertificate *);
		long p_UpdateFriendlyNameAndDescription(unsigned short *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void p_Initialize();
		void p_UnInitialize();
	public:
		CX509Enrollment();
		static long UpdateRegistry(int);
		static long s_AddCertToSmartCard(IX509PrivateKey *,unsigned short *);
		static long s_BuildRequestObject(IX509Enrollment *,short,short,RequestClientInfoClientId,short);
		static long s_CreateLogonCertificateRequest(unsigned short const *,EncodingType,unsigned short * *,EncodingType,unsigned short * *);
		static long s_DeleteLogonCertificateRequest(EncodingType,unsigned short *);
		static long s_Enroll(IX509Enrollment *);
		static long s_FindLogonCertificateTemplate(IX509Enrollment * *,LogonTemplateState *);
		static long s_GetCertThumbprint(_CERT_CONTEXT const *,EncodingType,unsigned short * *);
		static long s_GetCertificate(IX509Enrollment *,_CERT_CONTEXT const * *);
		static long s_GetCertificate(_CERT_CONTEXT const *,_CERT_CONTEXT const * *);
		static long s_GetCertificateToRenew(IX509Enrollment *,_CERT_CONTEXT const * *);
		static long s_GetDisplayName(_CERT_CONTEXT const *,unsigned short * *);
		static long s_GetDisplayString(_CERT_CONTEXT const *,unsigned short * *);
		static long s_GetFriendlyName(_CERT_CONTEXT const *,unsigned short * *);
		static long s_GetMatchCertificates(IX509Enrollment *,void * *);
		static long s_GetObsoleteCertificates(IX509Enrollment *,void * *);
		static long s_GetPkcs10Request(IX509CertificateRequest *,IX509CertificateRequestPkcs10V3 * *);
		static long s_GetRenewal(IX509Enrollment *,short *);
		static long s_GetSigningCertificate(IX509Enrollment *,_CERT_CONTEXT const * *);
		static long s_GetTemplate(IX509Enrollment *,IX509CertificateTemplateInternal * *);
		static long s_GetUIRequiredForAutoEnrollment(IX509Enrollment *,short *,EnrollmentQuerySubStatus);
		static long s_Initialize(IX509Enrollment *,X509CertificateEnrollmentContext);
		static long s_InstallLogonCertificateResponse(EncodingType,unsigned short *,EncodingType,unsigned short *,EncodingType,unsigned short * *);
		static long s_LoadDummyCert(void *,_CERT_CONTEXT const *,unsigned short const *,_CERT_CONTEXT const * *);
		static long s_LoadDummyCertFromFindType(void *,unsigned long,void const *,unsigned short const *,_CERT_CONTEXT const * *);
		static long s_ProcessPendingRequest(IX509Enrollment *);
		static long s_PutCAs(IX509Enrollment *);
		static long s_PutCertRequestConnection(IX509Enrollment *,ICertRequest3 *);
		static long s_PutCertificate(_CERT_CONTEXT const *,_CERT_CONTEXT const * *);
		static long s_PutCspInformations(IX509Enrollment *,ICspInformations *);
		static long s_PutSigningCertificate(IX509Enrollment *,_CERT_CONTEXT const *);
		static long s_RemovePendingLogonRequests();
		static long s_SelectCAs(IX509Enrollment *,unsigned short * *);
		static long s_VerifyLogonTemplate(IX509CertificateTemplateInternal *,unsigned short *,LogonTemplateState *);
		static long s_VerifyNGCLogonKey(_CERT_CONTEXT const * *,_CERT_PUBLIC_KEY_INFO * *);
		static void s_DumpEnrollments(unsigned short const *,IX509Enrollments *,ICertRequest3 *);
		static void s_LogPendingLogonCertRemoval(long,unsigned short *);
		virtual long CreatePFX(unsigned short *,PFXExportOptions,EncodingType,unsigned short * *);
		virtual long CreateRequest(EncodingType,unsigned short * *);
		virtual long Enroll();
		virtual long Execute(int,X509EnrollmentAuthFlags,unsigned short *,unsigned short *,unsigned int *,bool *);
		virtual long Initialize(X509CertificateEnrollmentContext);
		virtual long InitializeFromRequest(IX509CertificateRequest *);
		virtual long InitializeFromTemplate(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplate *);
		virtual long InitializeFromTemplateName(X509CertificateEnrollmentContext,unsigned short *);
		virtual long InstallResponse(InstallResponseRestrictionFlags,unsigned short *,EncodingType,unsigned short *);
		virtual long InstallResponse2(InstallResponseRestrictionFlags,unsigned short *,EncodingType,unsigned short *,unsigned short *,unsigned short *,PolicyServerUrlFlags,X509EnrollmentAuthFlags);
		virtual long LogAuthFailureEvent(X509CertificateEnrollmentContext,long,unsigned short *,unsigned short *,unsigned short *,X509EnrollmentAuthFlags);
		virtual long _BuildRequestObject(short,short,RequestClientInfoClientId,short);
		virtual long _CleanUpKey();
		virtual long _CreateDummyCert(short);
		virtual long _CreateRequest(unsigned short *,short,EncodingType,unsigned short * *);
		virtual long _DebugTrace(unsigned short const *,unsigned long,ICertRequest3 *);
		virtual long _Enroll();
		virtual long _EnrollWizard(short);
		virtual long _GetCAStatuses(ICAStatuses * *);
		virtual long _GetCertificate(_CERT_CONTEXT const * *);
		virtual long _GetCertificateProperties(ICertProperties * *);
		virtual long _GetCertificateToRenew(_CERT_CONTEXT const * *);
		virtual long _GetFullErrorMessageText(unsigned short * *);
		virtual long _GetIsInitializedFromRequest(short *);
		virtual long _GetMatchCertificates(void * *);
		virtual long _GetObsoleteCertificates(void * *);
		virtual long _GetPendingCertificate(_CERT_CONTEXT const * *);
		virtual long _GetPolicyServer(IX509EnrollmentPolicyServer * *);
		virtual long _GetQueryStatus(EnrollmentQueryStatus *);
		virtual long _GetQuerySubStatus(EnrollmentQuerySubStatus *);
		virtual long _GetRAApplicationPolicies(IObjectIds * *);
		virtual long _GetRAIssuancePolicies(IObjectIds * *);
		virtual long _GetRASignatureCount(long *);
		virtual long _GetRenewal(short *);
		virtual long _GetSigningCertificate(_CERT_CONTEXT const * *);
		virtual long _GetTemplate(IX509CertificateTemplateInternal * *);
		virtual long _GetUIRequiredForAutoEnrollment(EnrollmentQuerySubStatus,short *);
		virtual long _Initialize(X509CertificateEnrollmentContext);
		virtual long _InitializeFromCertificate(HWND__ *,X509CertificateEnrollmentContext,_CERT_CONTEXT const *,short,short,short);
		virtual long _InitializeFromTemplate(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *,short);
		virtual long _InstallResponse(InstallResponseRestrictionFlags,unsigned short *,EncodingType,unsigned short *,unsigned short *,void *,InstallResponseFlags,unsigned short *,unsigned short *,PolicyServerUrlFlags,X509EnrollmentAuthFlags);
		virtual long _ProcessPendingRequest();
		virtual long _PutActivityId(unsigned short *);
		virtual long _PutCAs();
		virtual long _PutCertRequestConnection(ICertRequest3 *);
		virtual long _PutCertificateToRenew(_CERT_CONTEXT const *);
		virtual long _PutCopySubjectCertificate(_CERT_CONTEXT const *);
		virtual long _PutCspInformations(ICspInformations *);
		virtual long _PutFixedEnrollmentServerCredential(X509EnrollmentAuthFlags,unsigned short *,unsigned short *);
		virtual long _PutMatchCertificates(void *);
		virtual long _PutObsoleteCertificates(void *);
		virtual long _PutPendingCertificate(_CERT_CONTEXT const *);
		virtual long _PutPolicyServer(IX509EnrollmentPolicyServer *);
		virtual long _PutQueryStatus(EnrollmentQueryStatus);
		virtual long _PutQuerySubStatus(EnrollmentQuerySubStatus);
		virtual long _PutSigningCertificate(_CERT_CONTEXT const *);
		virtual long _SelectCAs(LogonTemplateState *,unsigned short * *);
		virtual long get_CAConfigString(unsigned short * *);
		virtual long get_Certificate(EncodingType,unsigned short * *);
		virtual long get_CertificateDescription(unsigned short * *);
		virtual long get_CertificateFriendlyName(unsigned short * *);
		virtual long get_EnrollmentContext(X509CertificateEnrollmentContext *);
		virtual long get_NameValuePairs(IX509NameValuePairs * *);
		virtual long get_ParentWindow(long *);
		virtual long get_PolicyServer(IX509EnrollmentPolicyServer * *);
		virtual long get_Request(IX509CertificateRequest * *);
		virtual long get_RequestId(long *);
		virtual long get_RequestIdString(unsigned short * *);
		virtual long get_Response(EncodingType,unsigned short * *);
		virtual long get_Silent(short *);
		virtual long get_Status(IX509EnrollmentStatus * *);
		virtual long get_Template(IX509CertificateTemplate * *);
		virtual long put_CertificateDescription(unsigned short *);
		virtual long put_CertificateFriendlyName(unsigned short *);
		virtual long put_ParentWindow(long);
		virtual long put_Silent(short);
		~CX509Enrollment();
	};

	class CX509EnrollmentHelper
	{
		long p_AddToRegistry(unsigned short *,PolicyServerUrlFlags,X509EnrollmentAuthFlags,unsigned short *,unsigned short *);
		long p_DoAddPolicyServer(unsigned short *,unsigned short *,PolicyServerUrlFlags,X509EnrollmentAuthFlags,unsigned short *,unsigned short *);
		long p_StoreCredential(unsigned short *,X509EnrollmentAuthFlags,unsigned short *,unsigned short *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long AddEnrollmentServer(unsigned short *,X509EnrollmentAuthFlags,unsigned short *,unsigned short *);
		virtual long AddPolicyServer(unsigned short *,unsigned short *,PolicyServerUrlFlags,X509EnrollmentAuthFlags,unsigned short *,unsigned short *);
		virtual long Enroll(unsigned short *,unsigned short *,EncodingType,WebEnrollmentFlags,unsigned short * *);
		virtual long Initialize(X509CertificateEnrollmentContext);
		virtual ~CX509EnrollmentHelper();
	};

	class CX509EnrollmentManager
	{
		long p_ArchiveCertificates();
		long p_Enroll(short);
		long p_EnrollX509Enrollments(unsigned long,unsigned short *);
		long p_ExamX509Enrollments();
		long p_ProcessX509Enrollments();
		long p_QueryX509Enrollments(ATL::CSimpleArray<CEPTemplate,ATL::CSimpleArrayEqualHelper<CEPTemplate> > &);
		long p_ResetErrorInfo();
		long p_SetErrorElement(long,unsigned long,EnrollmentEnrollStatus);
		long p_SetReaderNameForScard(IX509Enrollment *,IX509CertificateRequest *,UserAction *);
		void p_SelectCEPs(ATL::CSimpleArray<POLICY_SERVER_GROUP,ATL::CSimpleArrayEqualHelper<POLICY_SERVER_GROUP> > &);
		void p_UnInitialize();
	public:
		static long UpdateRegistry(int);
		static long _SetErrorInfo(IX509Enrollment *,long,unsigned long,EnrollmentEnrollStatus);
		static long _SetErrorMessageInfo(IX509Enrollment *,long,unsigned short *,EnrollmentEnrollStatus);
		static long _SetSelectionInfo(IX509Enrollment *,EnrollmentSelectionStatus,EnrollmentDisplayStatus);
		static long s_AddCEPToGroup(IX509PolicyServerUrl *,bool,ATL::CSimpleArray<POLICY_SERVER_GROUP,ATL::CSimpleArrayEqualHelper<POLICY_SERVER_GROUP> > &);
		static long s_BuildPolicyUrlArray(X509CertificateEnrollmentContext,X509EnrollmentType,ATL::CSimpleArray<POLICY_SERVER_GROUP,ATL::CSimpleArrayEqualHelper<POLICY_SERVER_GROUP> > &);
		static long s_CreatePolicyServer(IX509PolicyServerUrl *,X509CertificateEnrollmentContext,ATL::CSimpleArray<ATL::CComPtr<IX509EnrollmentPolicyServer>,ATL::CSimpleArrayEqualHelper<ATL::CComPtr<IX509EnrollmentPolicyServer> > > &);
		static long s_GetTemplatesFromCEPGroups(HWND__ *,X509CertificateEnrollmentContext,ATL::CSimpleArray<POLICY_SERVER_GROUP,ATL::CSimpleArrayEqualHelper<POLICY_SERVER_GROUP> > &,ATL::CSimpleArray<CEPTemplate,ATL::CSimpleArrayEqualHelper<CEPTemplate> > &,ATL::CSimpleArray<FAILED_POLICY_SERVER,ATL::CSimpleArrayEqualHelper<FAILED_POLICY_SERVER> > *);
		static long s_ShowErrorPage(ICertificateEnrollmentUI *,long);
		static long s_VerifyEACert(short,_CERT_CONTEXT const *);
		virtual long AutoEnroll(X509CertificateEnrollmentContext,X509AutoEnrollOption,short *);
		virtual long _Enroll(short,IX509Enrollment *);
		virtual long _EnrollThreadProc(short);
		virtual long _PutEACert(_CERT_CONTEXT const *);
		virtual long get_EnrollmentContext(X509CertificateEnrollmentContext *);
		virtual long get_EnrollmentResult(IX509Enrollments * *);
		virtual long get_ParentWindow(long *);
		virtual long put_ParentWindow(long);
		~CX509EnrollmentManager();
	};

	class CX509EnrollmentPolicyActiveDirectory
	{
		long EnsureCAs();
		long EnsureTemplates();
		long EnumerateCAs();
		long EnumerateTemplates();
		long PopulateCAsFromDC(ldap *);
		long UpdateSequenceNos(int);
		static long EnumerateCertificateTypes(ldap *,unsigned long,ATL::CSimpleArray<void *,ATL::CSimpleArrayEqualHelper<void *> > *);
		static long SortCertificateTypesByName(ATL::CSimpleArray<void *,ATL::CSimpleArrayEqualHelper<void *> > &);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void Cleanup();
	public:
		CX509EnrollmentPolicyActiveDirectory();
		static long UpdateRegistry(int);
		virtual long Export(X509EnrollmentPolicyExportFlags,tagVARIANT *);
		virtual long GetAllowUnTrustedCA(short *);
		virtual long GetAuthFlags(X509EnrollmentAuthFlags *);
		virtual long GetCAs(ICertificationAuthorities * *);
		virtual long GetCAsForTemplate(IX509CertificateTemplate *,ICertificationAuthorities * *);
		virtual long GetCacheDir(unsigned short * *);
		virtual long GetCachePath(unsigned short * *);
		virtual long GetCustomOids(IObjectIds * *);
		virtual long GetFriendlyName(unsigned short * *);
		virtual long GetIsDefaultCEP(short *);
		virtual long GetLastUpdateTime(double *);
		virtual long GetNextUpdateTime(double *);
		virtual long GetPolicyServerId(unsigned short * *);
		virtual long GetPolicyServerUrl(unsigned short * *);
		virtual long GetTemplates(IX509CertificateTemplates * *);
		virtual long GetUseClientId(short *);
		virtual long Initialize(unsigned short *,unsigned short *,X509EnrollmentAuthFlags,short,X509CertificateEnrollmentContext);
		virtual long InitializeImport(tagVARIANT);
		virtual long LoadPolicy(X509EnrollmentPolicyLoadOption);
		virtual long QueryChanges(short *);
		virtual long SetCredential(long,X509EnrollmentAuthFlags,unsigned short *,unsigned short *);
		virtual long Validate();
		virtual long _Initialize(unsigned short *,unsigned short *,X509EnrollmentAuthFlags,short,PolicyServerUrlFlags,X509CertificateEnrollmentContext);
		virtual long _InitializeFromPolicyServerUrl(X509CertificateEnrollmentContext,IX509PolicyServerUrl *);
		virtual long get_Cost(unsigned long *);
		virtual long put_Cost(unsigned long);
		~CX509EnrollmentPolicyActiveDirectory();
	};

	class CX509EnrollmentStatus
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_PutDisposition(IX509EnrollmentStatus *,long);
		virtual long AppendText(unsigned short *);
		virtual long _PutDisposition(long);
		virtual long get_Display(EnrollmentDisplayStatus *);
		virtual long get_Error(long *);
		virtual long get_ErrorText(unsigned short * *);
		virtual long get_Selected(EnrollmentSelectionStatus *);
		virtual long get_Status(EnrollmentEnrollStatus *);
		virtual long get_Text(unsigned short * *);
		virtual long put_Display(EnrollmentDisplayStatus);
		virtual long put_Error(long);
		virtual long put_Selected(EnrollmentSelectionStatus);
		virtual long put_Status(EnrollmentEnrollStatus);
		virtual long put_Text(unsigned short *);
		~CX509EnrollmentStatus();
	};

	class CX509EnrollmentWebClassFactory
	{
		long CertEnrollWebClassFactoryCreateComObject<ICertProperties,CCertProperties>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<ICertPropertyDescription,CCertPropertyDescription>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<ICertPropertyFriendlyName,CCertPropertyFriendlyName>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<ICspInformation,CCspInformation>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<ICspInformations,CCspInformations>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<ICspStatus,CCspStatus>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IObjectId,CObjectId>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IObjectIds,CObjectIds>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<ISignerCertificate,CSignerCertificate>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX500DistinguishedName,CX500DistinguishedName>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509CertificateRequestCmc,CX509CertificateRequestCmc>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509CertificateRequestPkcs10,CX509CertificateRequestPkcs10>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509CertificateRequestPkcs7,CX509CertificateRequestPkcs7>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509Enrollment,CX509Enrollment>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509EnrollmentHelper,CX509EnrollmentHelper>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509Extension,CX509Extension>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509ExtensionEnhancedKeyUsage,CX509ExtensionEnhancedKeyUsage>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509ExtensionKeyUsage,CX509ExtensionKeyUsage>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509ExtensionTemplate,CX509ExtensionTemplate>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509ExtensionTemplateName,CX509ExtensionTemplateName>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509Extensions,CX509Extensions>(IUnknown * *);
		long CertEnrollWebClassFactoryCreateComObject<IX509PrivateKey,CX509PrivateKey>(IUnknown * *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long CreateObject(unsigned short *,IUnknown * *);
		virtual ~CX509EnrollmentWebClassFactory();
	};

	class CX509Enrollments
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long get_ItemByTemplateName(unsigned short *,IX509Enrollment * *);
		~CX509Enrollments();
	};

	class CX509Extension
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_CreateFromExt(_CERT_EXTENSION const *,IX509Extension * *);
		static long s_CreateFromExtension(IX509Extension *,IX509Extension * *);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_Critical(short *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_Critical(short);
		~CX509Extension();
	};

	class CX509ExtensionAlternativeNames
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509ExtensionAlternativeNames();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(IAlternativeNames *);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_AlternativeNames(IAlternativeNames * *);
		virtual long get_Critical(short *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_Critical(short);
		~CX509ExtensionAlternativeNames();
	};

	class CX509ExtensionAlternativeNamesImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeDecode(EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeEncode(IAlternativeNames *);
		virtual long get_AlternativeNames(IAlternativeNames * *);
		virtual ~CX509ExtensionAlternativeNamesImpl();
	};

	class CX509ExtensionAuthorityKeyIdentifier
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509ExtensionAuthorityKeyIdentifier();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(EncodingType,unsigned short *);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_AuthorityKeyIdentifier(EncodingType,unsigned short * *);
		virtual long get_Critical(short *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_Critical(short);
		~CX509ExtensionAuthorityKeyIdentifier();
	};

	class CX509ExtensionAuthorityKeyIdentifierImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(EncodingType,unsigned short *);
		virtual long get_AuthorityKeyIdentifier(EncodingType,unsigned short * *);
		virtual ~CX509ExtensionAuthorityKeyIdentifierImpl();
	};

	class CX509ExtensionBasicConstraints
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(short,long);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_Critical(short *);
		virtual long get_IsCA(short *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_PathLenConstraint(long *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_Critical(short);
		~CX509ExtensionBasicConstraints();
	};

	class CX509ExtensionBasicConstraintsImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeDecode(EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeEncode(short,long);
		virtual long get_IsCA(short *);
		virtual long get_PathLenConstraint(long *);
		virtual ~CX509ExtensionBasicConstraintsImpl();
	};

	class CX509ExtensionCertificatePolicies
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509ExtensionCertificatePolicies();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(ICertificatePolicies *);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_Critical(short *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_Policies(ICertificatePolicies * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_Critical(short);
		~CX509ExtensionCertificatePolicies();
	};

	struct CX509ExtensionCertificatePoliciesImpl
	{
		virtual long InitializeDecode(EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeEncode(ICertificatePolicies *);
		virtual ~CX509ExtensionCertificatePoliciesImpl();
	};

	class CX509ExtensionEnhancedKeyUsage
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509ExtensionEnhancedKeyUsage();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(IObjectIds *);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_Critical(short *);
		virtual long get_EnhancedKeyUsage(IObjectIds * *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_Critical(short);
		~CX509ExtensionEnhancedKeyUsage();
	};

	class CX509ExtensionEnhancedKeyUsageImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeDecode(EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeEncode(IObjectIds *);
		virtual long get_EnhancedKeyUsage(IObjectIds * *);
		virtual ~CX509ExtensionEnhancedKeyUsageImpl();
	};

	struct CX509ExtensionImpl
	{
		CX509ExtensionImpl();
		long _InitializeFromString(unsigned short const *,unsigned short *,unsigned short * *);
		long _Marshal(_CERT_EXTENSION *);
		virtual long get_Critical(short *);
		virtual long put_Critical(short);
		virtual ~CX509ExtensionImpl();
	};

	class CX509ExtensionKeyUsage
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(X509KeyUsageFlags);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_Critical(short *);
		virtual long get_KeyUsage(X509KeyUsageFlags *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_Critical(short);
		~CX509ExtensionKeyUsage();
	};

	class CX509ExtensionKeyUsageImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeDecode(EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeEncode(X509KeyUsageFlags);
		virtual long get_KeyUsage(X509KeyUsageFlags *);
		virtual ~CX509ExtensionKeyUsageImpl();
	};

	class CX509ExtensionMSApplicationPolicies
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509ExtensionMSApplicationPolicies();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(ICertificatePolicies *);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_Critical(short *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_Policies(ICertificatePolicies * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long put_Critical(short);
		~CX509ExtensionMSApplicationPolicies();
	};

	struct CX509ExtensionMSApplicationPoliciesImpl
	{
		virtual long InitializeDecode(EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeEncode(ICertificatePolicies *);
		virtual ~CX509ExtensionMSApplicationPoliciesImpl();
	};

	class CX509ExtensionPoliciesImpl
	{
		long _Decode();
		long _Encode();
	public:
		CX509ExtensionPoliciesImpl();
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeDecode(unsigned short *,EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeEncode(unsigned short *,ICertificatePolicies *);
		virtual long get_Policies(ICertificatePolicies * *);
		virtual ~CX509ExtensionPoliciesImpl();
	};

	class CX509ExtensionSmimeCapabilities
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509ExtensionSmimeCapabilities();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(ISmimeCapabilities *);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_Critical(short *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_SmimeCapabilities(ISmimeCapabilities * *);
		virtual long put_Critical(short);
		~CX509ExtensionSmimeCapabilities();
	};

	class CX509ExtensionSmimeCapabilitiesImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(ISmimeCapabilities *);
		virtual long get_SmimeCapabilities(ISmimeCapabilities * *);
		virtual ~CX509ExtensionSmimeCapabilitiesImpl();
	};

	class CX509ExtensionSubjectKeyIdentifier
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509ExtensionSubjectKeyIdentifier();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(EncodingType,unsigned short *);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_Critical(short *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_SubjectKeyIdentifier(EncodingType,unsigned short * *);
		virtual long put_Critical(short);
		~CX509ExtensionSubjectKeyIdentifier();
	};

	class CX509ExtensionSubjectKeyIdentifierImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(EncodingType,unsigned short *);
		virtual long get_SubjectKeyIdentifier(EncodingType,unsigned short * *);
		virtual ~CX509ExtensionSubjectKeyIdentifierImpl();
	};

	class CX509ExtensionTemplate
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509ExtensionTemplate();
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(IObjectId *,long,long);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_Critical(short *);
		virtual long get_MajorVersion(long *);
		virtual long get_MinorVersion(long *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_TemplateOid(IObjectId * *);
		virtual long put_Critical(short);
		~CX509ExtensionTemplate();
	};

	class CX509ExtensionTemplateImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeDecode(EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeEncode(IObjectId *,long,long);
		virtual long get_MajorVersion(long *);
		virtual long get_MinorVersion(long *);
		virtual long get_TemplateOid(IObjectId * *);
		virtual ~CX509ExtensionTemplateImpl();
	};

	class CX509ExtensionTemplateName
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *);
		virtual long InitializeDecode(EncodingType,unsigned short *);
		virtual long InitializeEncode(unsigned short *);
		virtual long _InitializeFromString(unsigned short *);
		virtual long _Marshal(_CERT_EXTENSION *);
		virtual long get_Critical(short *);
		virtual long get_ObjectId(IObjectId * *);
		virtual long get_RawData(EncodingType,unsigned short * *);
		virtual long get_TemplateName(unsigned short * *);
		virtual long put_Critical(short);
		~CX509ExtensionTemplateName();
	};

	class CX509ExtensionTemplateNameImpl
	{
		long _Decode();
		long _Encode();
	public:
		virtual long Initialize(IObjectId *,EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeDecode(EncodingType,unsigned short *,unsigned short * *);
		virtual long InitializeEncode(unsigned short *);
		virtual long get_TemplateName(unsigned short * *);
		virtual ~CX509ExtensionTemplateNameImpl();
	};

	class CX509Extensions
	{
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Create(IX509Extensions * *);
		static long s_CreateFromExts(_CERT_EXTENSIONS const *,IX509Extensions * *);
		static long s_FindByObjId(IX509Extensions *,unsigned short const *,IX509Extension * *);
		static long s_FreeMarshaled(_CERT_EXTENSIONS *);
		virtual long Add(IX509Extension *);
		virtual long AddRange(IX509Extensions *);
		virtual long _Marshal(_CERT_EXTENSIONS *);
		virtual long get_IndexByObjectId(IObjectId *,long *);
		~CX509Extensions();
	};

	class CX509MachineEnrollmentFactory
	{
		long CertEnrollWebAsAdminCreateComObject(HWND__ *,_GUID const &,_GUID const &,void * *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		virtual long CreateObject(unsigned short *,IX509EnrollmentHelper * *);
		virtual ~CX509MachineEnrollmentFactory();
	};

	class CX509NameValuePair
	{
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Create(IX509NameValuePair * *);
		virtual long Initialize(unsigned short *,unsigned short *);
		virtual long get_Name(unsigned short * *);
		virtual long get_Value(unsigned short * *);
		~CX509NameValuePair();
	};

	class CX509NameValuePairs
	{
	protected:
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		static long UpdateRegistry(int);
		static long s_Create(IX509NameValuePairs * *);
		~CX509NameValuePairs();
	};

	class CX509PrivateKey
	{
		long p_CleanupCNGKey(bool);
		long p_CleanupLegacyKey(bool,unsigned short *,X509ProviderType,unsigned short *);
		long p_CopySecurityDescriptor(IX509PrivateKey *);
		long p_CopySmartCardProvider(IX509PrivateKey *);
		long p_CopySmartCardReaderName(IX509PrivateKey *);
		long p_FormatContextMessage(unsigned short const *,unsigned short const *,unsigned int,short,unsigned short * *);
		long p_GetCertificate();
		long p_GetCsp(ICspInformation * *);
		long p_GetFullContainerName(unsigned short *,unsigned short * *);
		long p_GetLength(bool,long *);
		long p_OpenCNGKey(CX509PrivateKey::OpenType,bool,short,unsigned short *,ICspInformation *,IObjectId *,unsigned short *,unsigned short *,_CRYPTOAPI_BLOB const *,unsigned __int64,bool *);
		long p_OpenKey(CX509PrivateKey::OpenType,X509PrivateKeyVerify,unsigned short *,_CRYPTOAPI_BLOB *,unsigned __int64,X509PrivateKeyVerify *);
		long p_OpenLegacyKey(CX509PrivateKey::OpenType,bool,short,unsigned short *,X509ProviderType,unsigned short *,unsigned short *,_CRYPTOAPI_BLOB const *,unsigned __int64,bool *);
		long p_SaveSecurityDescriptor(void *);
		long p_SetCNGPropertiesFromKey(unsigned short *,X509ProviderType,short);
		long p_SetCertificate(_CERT_CONTEXT const *);
		long p_SetContainerName(ICspInformation *);
		long p_SetCspStatus(ICspStatus *);
		long p_SetCspStatusFromCsp(ICspInformation *,IObjectId *);
		long p_SetLegacyCsp(bool);
		long p_SetLegacyPin(unsigned __int64,char const *);
		long p_SetLegacyPropertiesFromKey(unsigned short *,X509ProviderType,short);
		long p_SetLength(bool,long);
		long p_SetSecurityDescriptor(void *);
		long p_SetSecurityDescriptorOnOpen(CX509PrivateKey::OpenType);
		long p_UpdateKeyUsageProperty(ICspInformation *,unsigned short *);
		long p_UpdateStringProperty(unsigned short const *,bool,unsigned short * *);
		unsigned long p_GetLegacyFlagsFromProperties(bool);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void p_SetLegacyUIContextString(unsigned __int64,unsigned short *,unsigned short const *,X509ProviderType,short);
	public:
		CX509PrivateKey();
		static bool s_fCspTrace;
		static long UpdateRegistry(int);
		static long s_CopyInheritProperties(bool,IX509PrivateKey *,IX509PrivateKey *);
		static long s_Create(bool,IX509PrivateKey * *);
		static long s_CreateFromCertificate(bool,bool,long,unsigned short *,unsigned short *,X509RequestInheritOptions,bool,ICspInformations *,_CERT_CONTEXT const *,_CERT_KEY_CONTEXT const *,IX509PrivateKey * *,IX509PrivateKey * *);
		static long s_CreateFromKeyContext(bool,bool,long,unsigned short *,unsigned short *,_CERT_KEY_CONTEXT const *,IX509PrivateKey * *);
		static long s_CreateFromKeyProvInfo(bool,bool,long,unsigned short *,unsigned short *,bool,bool,_CRYPT_KEY_PROV_INFO *,IX509PrivateKey * *);
		static long s_GetAlgorithmAndName(IX509PrivateKey *,unsigned short *,IObjectId * *,unsigned short * *,unsigned short * *,unsigned short * *);
		static long s_GetCapableOfAttestation(IX509PrivateKey *,TestKeyAttResult *);
		static long s_GetCspInformation(IX509PrivateKey *,ICspStatus * *,ICspInformation * *);
		static long s_GetDefaultEncryptionAlgorithm(IX509PrivateKey *,long *,IObjectId * *);
		static long s_GetDefaultHashAlgorithm(IX509PrivateKey *,short,IObjectId * *);
		static long s_GetIsSmartCard(IX509PrivateKey *,short *);
		static long s_GetLegacyExportType(unsigned short *,unsigned long *);
		static long s_GetProviderHandle(IX509PrivateKey *,unsigned __int64 *,X509KeySpec *);
		static long s_GetPublicKeyAlgorithm(IX509PrivateKey *,IObjectId * *);
		static long s_LoadCNG();
		static long s_PutExtensionKeyUsageFlags(IX509PrivateKey *,X509KeyUsageFlags);
		static long s_VerifyPrivateKey(bool,bool,long,unsigned short *,unsigned short *,_CERT_CONTEXT const *);
		static unsigned long s_dwCspTrace;
		virtual long Close();
		virtual long Create();
		virtual long Delete();
		virtual long Export(unsigned short *,EncodingType,unsigned short * *);
		virtual long ExportPublicKey(IX509PublicKey * *);
		virtual long Import(unsigned short *,unsigned short *,EncodingType);
		virtual long Open();
		virtual long Verify(X509PrivateKeyVerify);
		virtual long _CopyInheritProperties(IX509PrivateKey *);
		virtual long _CopyRenewalProperties(IX509PrivateKey *);
		virtual long _GetAlgorithmAndName(IObjectId *,unsigned short *,IObjectId * *,unsigned short * *,unsigned short * *,unsigned short * *);
		virtual long _GetCapableOfAttestation(short *);
		virtual long _GetCsp(ICspInformation * *);
		virtual long _GetExclusionKey(IX509PrivateKey * *);
		virtual long _GetExtensionKeyUsageFlags(X509KeyUsageFlags *);
		virtual long _GetPropertiesSet(PrivateKeyPropertiesSet *);
		virtual long _GetProviderHandle(unsigned __int64 *,X509KeySpec *);
		virtual long _GetTemplateKeyLength(long *);
		virtual long _InitializeFromKeyHandle(unsigned __int64,X509KeySpec);
		virtual long _PutExclusionKey(IX509PrivateKey *);
		virtual long _PutExtensionKeyUsageFlags(X509KeyUsageFlags);
		virtual long _PutTemplateKeyLength(long);
		virtual long get_Algorithm(IObjectId * *);
		virtual long get_AlgorithmName(unsigned short * *);
		virtual long get_AlgorithmParameters(EncodingType,unsigned short * *);
		virtual long get_AlternateStorageLocation(unsigned short * *);
		virtual long get_Certificate(EncodingType,unsigned short * *);
		virtual long get_ContainerName(unsigned short * *);
		virtual long get_ContainerNamePrefix(unsigned short * *);
		virtual long get_CspInformations(ICspInformations * *);
		virtual long get_CspStatus(ICspStatus * *);
		virtual long get_DefaultContainer(short *);
		virtual long get_Description(unsigned short * *);
		virtual long get_Existing(short *);
		virtual long get_ExportPolicy(X509PrivateKeyExportFlags *);
		virtual long get_FriendlyName(unsigned short * *);
		virtual long get_HardwareKeyUsage(X509HardwareKeyUsageFlags *);
		virtual long get_KeyProtection(X509PrivateKeyProtection *);
		virtual long get_KeySpec(X509KeySpec *);
		virtual long get_KeyUsage(X509PrivateKeyUsageFlags *);
		virtual long get_LegacyCsp(short *);
		virtual long get_Length(long *);
		virtual long get_MachineContext(short *);
		virtual long get_Opened(short *);
		virtual long get_ParametersExportType(X509KeyParametersExportType *);
		virtual long get_ParentWindow(long *);
		virtual long get_ProviderName(unsigned short * *);
		virtual long get_ProviderType(X509ProviderType *);
		virtual long get_ReaderName(unsigned short * *);
		virtual long get_SecurityDescriptor(unsigned short * *);
		virtual long get_Silent(short *);
		virtual long get_UIContextMessage(unsigned short * *);
		virtual long get_UniqueContainerName(unsigned short * *);
		virtual long put_Algorithm(IObjectId *);
		virtual long put_AlgorithmName(unsigned short *);
		virtual long put_AlgorithmParameters(EncodingType,unsigned short *);
		virtual long put_AlternateStorageLocation(unsigned short *);
		virtual long put_Certificate(EncodingType,unsigned short *);
		virtual long put_ContainerName(unsigned short *);
		virtual long put_ContainerNamePrefix(unsigned short *);
		virtual long put_CspInformations(ICspInformations *);
		virtual long put_CspStatus(ICspStatus *);
		virtual long put_Description(unsigned short *);
		virtual long put_Existing(short);
		virtual long put_ExportPolicy(X509PrivateKeyExportFlags);
		virtual long put_FriendlyName(unsigned short *);
		virtual long put_HardwareKeyUsage(X509HardwareKeyUsageFlags);
		virtual long put_KeyProtection(X509PrivateKeyProtection);
		virtual long put_KeySpec(X509KeySpec);
		virtual long put_KeyUsage(X509PrivateKeyUsageFlags);
		virtual long put_LegacyCsp(short);
		virtual long put_Length(long);
		virtual long put_MachineContext(short);
		virtual long put_ParametersExportType(X509KeyParametersExportType);
		virtual long put_ParentWindow(long);
		virtual long put_Pin(unsigned short *);
		virtual long put_ProviderName(unsigned short *);
		virtual long put_ProviderType(X509ProviderType);
		virtual long put_ReaderName(unsigned short *);
		virtual long put_SecurityDescriptor(unsigned short *);
		virtual long put_Silent(short);
		virtual long put_UIContextMessage(unsigned short *);
		~CX509PrivateKey();
	};

	class CX509PublicKey
	{
		long p_Initialize(IObjectId *,char const *,_CRYPTOAPI_BLOB const *,_CRYPTOAPI_BLOB const *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
	public:
		CX509PublicKey();
		static long UpdateRegistry(int);
		static long s_CreateFromPublicKeyInfo(_CERT_PUBLIC_KEY_INFO const *,IX509PublicKey * *);
		static long s_MarshalPublicKeyInfo(IX509PublicKey *,_CERT_PUBLIC_KEY_INFO * *);
		virtual long ComputeKeyIdentifier(KeyIdentifierHashAlgorithm,EncodingType,unsigned short * *);
		virtual long Initialize(IObjectId *,unsigned short *,unsigned short *,EncodingType);
		virtual long InitializeFromEncodedPublicKeyInfo(unsigned short *,EncodingType);
		virtual long _InitializeFromPublicKeyInfo(_CERT_PUBLIC_KEY_INFO const *);
		virtual long _MarshalPublicKeyInfo(_CERT_PUBLIC_KEY_INFO * *);
		virtual long get_Algorithm(IObjectId * *);
		virtual long get_EncodedKey(EncodingType,unsigned short * *);
		virtual long get_EncodedParameters(EncodingType,unsigned short * *);
		virtual long get_Length(long *);
		~CX509PublicKey();
	};

	class CX509SCEPEnrollment
	{
		long p_BuildNDESResult(X509SCEPDisposition);
		long p_CreateEnrollRequest(IX509Enrollment *,unsigned short * *);
		long p_CreateEnrollmentObject(X509CertificateEnrollmentContext,IX509CertificateRequestPkcs10 *,IX509Enrollment * *);
		long p_CreateProtocolCertificate(X509CertificateEnrollmentContext,_CRYPTOAPI_BLOB const *,_CRYPTOAPI_BLOB const *);
		long p_CreateSignerFromDummyCert();
		long p_DecodeEnvelopedPkcs7(_CRYPTOAPI_BLOB *,_CRYPTOAPI_BLOB *);
		long p_DecodeSignedPkcs7(_CRYPTOAPI_BLOB *,X509SCEPDisposition *,_CRYPTOAPI_BLOB *);
		long p_DecodeTransactionId(_CRYPTOAPI_BLOB *);
		long p_DeleteDummyCert(bool);
		long p_DeleteRequestCertAndKey(IX509CertificateRequestPkcs10 *,bool,bool,unsigned long);
		long p_EncryptAndSignMessage(X509SCEPMessageType,unsigned char const *,unsigned long,EncodingType,_CERT_CONTEXT const * *,unsigned long,unsigned short * *);
		long p_EncryptMessage(unsigned char const *,unsigned long,unsigned char * *,unsigned long *);
		long p_InstallCertificate(X509SCEPProcessMessageFlags,_CRYPTOAPI_BLOB *);
		long p_LoadCertFromDummyCertProperty(CERTENROLL_PROPERTYID,_CERT_CONTEXT const * *);
		long p_LoadDummyCertAndPropertiesFromTransactionId(_CRYPTOAPI_BLOB const *);
		long p_LoadDummyCertBlobProperty(CERTENROLL_PROPERTYID,CByteArray *);
		long p_LoadDummyCertFromRequest();
		long p_LoadDummyCertFromRequestSub(bool,_CERT_CONTEXT const * *,void * *);
		long p_LoadDummyCertProperties();
		long p_LoadDummyCertSignerCert(CERTENROLL_PROPERTYID,ISignerCertificate * *);
		long p_PatchKeyAssociation();
		long p_SaveAlgorithm(bool,unsigned short const *);
		long p_SetDummyCertBlobProperty(CERTENROLL_PROPERTYID,CByteArray const *);
		long p_SetDummyCertHashAttribute();
		long p_SetDummyCertProperties();
		long p_SetDummyCertThumbprintProperty(CERTENROLL_PROPERTYID,_CERT_CONTEXT const *);
		long p_SetEnrollDummyCertProperties();
		long p_SetMessageAlgorithms();
		long p_SetRequestAlgorithms(IX509CertificateRequestPkcs10V3 *);
		long p_SignMessage(X509SCEPMessageType,unsigned char const *,unsigned long,_CERT_CONTEXT const * *,unsigned long,unsigned char * *,unsigned long *);
		long p_UseSeparateProtocolCertificate(bool *);
		long p_VerifyEncoding();
		long p_VerifyMode(CX509SCEPEnrollment::EncodingState);
		static long s_CompareBlobs(CByteArray const *,CByteArray const *);
		static long s_ComputeTransactionId(_CERT_CONTEXT const *,CByteArray *);
		static long s_DecodeBinaryStringAttribute(_CMSG_CMS_SIGNER_INFO const *,char const *,CByteArray *);
		static long s_DecodeIntegerStringAttribute(_CMSG_CMS_SIGNER_INFO const *,char const *,unsigned long *);
		static long s_DecodeOctetStringAttribute(_CMSG_CMS_SIGNER_INFO const *,char const *,CByteArray *);
		static long s_DecodeStringAttribute(_CMSG_CMS_SIGNER_INFO const *,char const *,unsigned short * *);
		static long s_EncodeBinaryStringAttribute(CByteArray const *,_CRYPTOAPI_BLOB *);
		static long s_EncodeDateTimeAttribute(_CRYPTOAPI_BLOB *);
		static long s_EncodeIntegerStringAttribute(unsigned long,_CRYPTOAPI_BLOB *);
		static long s_EncodeIssuerSerial(_CRYPTOAPI_BLOB const *,_CRYPTOAPI_BLOB const *,unsigned char * *,unsigned long *);
		static long s_EncodeOctetStringAttribute(CByteArray const *,_CRYPTOAPI_BLOB *);
		static long s_EncodeSequence(_CRYPTOAPI_BLOB const *,_CRYPTOAPI_BLOB const *,unsigned char * *,unsigned long *);
		static long s_FindAttributeValue(_CMSG_CMS_SIGNER_INFO const *,char const *,_CRYPTOAPI_BLOB * *);
		static long s_FindCACert(void *,_CERT_CONTEXT const *,_CERT_CONTEXT const *,_CERT_CONTEXT const *,_CRYPTOAPI_BLOB const *,char const *,_CERT_CONTEXT const * *);
		static long s_FindRACerts(void *,_CERT_CONTEXT const * *,_CERT_CONTEXT const * *,_CERT_CONTEXT const * *);
		static long s_GetDisallowedAlgorithms(unsigned short const *,unsigned short * * *);
		static long s_LoadCertContext(X509CertificateEnrollmentContext,unsigned short const *,_CERT_CONTEXT const *,_CERT_CONTEXT const * *,void * *);
		static long s_LoadRequestCertFromHash(X509CertificateEnrollmentContext,unsigned long,unsigned char const *,unsigned long,unsigned short const *,_CERT_CONTEXT const * *,void * *);
		static long s_LookupAlgorithm(bool,unsigned short const *,_CRYPT_OID_INFO const * *);
		static long s_SetOidInfoFromAlgorithm(IObjectId *,unsigned long,_CRYPT_OID_INFO const * *);
		static long s_SetOidInfoFromAlgorithmList(ATL::CSimpleArray<_CRYPT_OID_INFO const *,ATL::CSimpleArrayEqualHelper<_CRYPT_OID_INFO const *> > &,unsigned short * *,ICspAlgorithms *,long *,_CRYPT_OID_INFO const * *);
		static long s_VerifyCertAgainstIssuer(_CERT_CONTEXT const *,_CERT_CONTEXT const *);
		static long s_VerifyThumbprint(_CERT_CONTEXT const *,_CRYPTOAPI_BLOB const *,char const *,bool *);
		static void s_DbgTraceThumbprint(_CRYPTOAPI_BLOB const *,char const *,unsigned long);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void p_PutEnrollStatus(EnrollmentEnrollStatus);
	public:
		CX509SCEPEnrollment();
		static long UpdateRegistry(int);
		static long s_EncodeStringAttribute(unsigned short const *,_CRYPTOAPI_BLOB *);
		static long s_GetAlgorithmsString(IX509CertificateRequestPkcs10 *,_CRYPT_OID_INFO const *,_CRYPT_OID_INFO const *,unsigned short * *);
		static long s_LoadDummyCertStringProperty(_CERT_CONTEXT const *,CERTENROLL_PROPERTYID,unsigned short * *);
		static long s_SetDummyCertStringProperty(_CERT_CONTEXT const *,CERTENROLL_PROPERTYID,unsigned short const *);
		virtual long CreateChallengeAnswerMessage(EncodingType,unsigned short * *);
		virtual long CreateRequestMessage(EncodingType,unsigned short * *);
		virtual long CreateRetrieveCertificateMessage(X509CertificateEnrollmentContext,unsigned short *,EncodingType,unsigned short *,EncodingType,EncodingType,unsigned short * *);
		virtual long CreateRetrievePendingMessage(EncodingType,unsigned short * *);
		virtual long DeleteRequest();
		virtual long Initialize(IX509CertificateRequestPkcs10 *,unsigned short *,EncodingType,unsigned short *,EncodingType);
		virtual long InitializeForPending(X509CertificateEnrollmentContext);
		virtual long ProcessResponseMessage(unsigned short *,EncodingType,X509SCEPDisposition *);
		virtual long ProcessResponseMessage2(X509SCEPProcessMessageFlags,unsigned short *,EncodingType,X509SCEPDisposition *);
		virtual long _DeleteRequest();
		virtual long get_ActivityId(unsigned short * *);
		virtual long get_Certificate(EncodingType,unsigned short * *);
		virtual long get_CertificateFriendlyName(unsigned short * *);
		virtual long get_DelayRetry(DelayRetryAction *);
		virtual long get_FailInfo(X509SCEPFailInfo *);
		virtual long get_OldCertificate(ISignerCertificate * *);
		virtual long get_Request(IX509CertificateRequestPkcs10 * *);
		virtual long get_ResultMessageText(unsigned short * *);
		virtual long get_SignerCertificate(ISignerCertificate * *);
		virtual long get_Silent(short *);
		virtual long get_Status(IX509EnrollmentStatus * *);
		virtual long get_TransactionId(EncodingType,unsigned short * *);
		virtual long put_ActivityId(unsigned short *);
		virtual long put_CertificateFriendlyName(unsigned short *);
		virtual long put_OldCertificate(ISignerCertificate *);
		virtual long put_ServerCapabilities(unsigned short *);
		virtual long put_SignerCertificate(ISignerCertificate *);
		virtual long put_Silent(short);
		virtual long put_TransactionId(EncodingType,unsigned short *);
		~CX509SCEPEnrollment();
	};

	class CX509SCEPEnrollmentHelper
	{
		long p_Enroll(X509SCEPProcessMessageFlags,X509SCEPDisposition *);
		long p_GetServerCapabilities(ICertRequest3 *,unsigned short * *);
		long p_GetServerCertificates(ICertRequest3 *,unsigned short * *);
		long p_Init(unsigned short *,unsigned short *,IX509CertificateRequestPkcs10 *,unsigned short *,X509CertificateEnrollmentContext,unsigned short *);
		long p_LogTelemetry(long,X509CertificateEnrollmentContext,X509SCEPDisposition,bool);
		long p_SaveRequestHeaders(unsigned short *,unsigned short const *);
		long p_SubmitRequest(unsigned short *,unsigned short * *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void p_SaveRequestMessageText(ICertRequest3 *);
	public:
		CX509SCEPEnrollmentHelper();
		static long UpdateRegistry(int);
		static long s_CreateActivityId(unsigned short * *);
		virtual long Enroll(X509SCEPProcessMessageFlags,X509SCEPDisposition *);
		virtual long FetchPending(X509SCEPProcessMessageFlags,X509SCEPDisposition *);
		virtual long Initialize(unsigned short *,unsigned short *,IX509CertificateRequestPkcs10 *,unsigned short *);
		virtual long InitializeForPending(unsigned short *,unsigned short *,X509CertificateEnrollmentContext,unsigned short *);
		virtual long _GetTraceData(SCEPTraceData *);
		virtual long _PutAuthToken(void *);
		virtual long _PutDisableTelemetry(int);
		virtual long _PutTPMInfo(unsigned long,unsigned long,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *);
		virtual long get_ResultMessageText(unsigned short * *);
		virtual long get_X509SCEPEnrollment(IX509SCEPEnrollment * *);
		~CX509SCEPEnrollmentHelper();
	};

	class CX509SignatureInformation
	{
		long p_EncodeAlternateSignatureParameters(char const *,char const *);
		virtual long p_SetErrorInfo(long,unsigned short const *,unsigned short const *);
		void p_ClearCache();
		void p_LogErrorSub(CX509SignatureInformation::SigErrorState,unsigned short,unsigned short * *,long);
		void p_LogSigError(CX509SignatureInformation::SigErrorState,short,short,unsigned short const *,unsigned short const *,unsigned long,unsigned long,char const *,long);
	public:
		CX509SignatureInformation();
		static long UpdateRegistry(int);
		static long s_CloneValues(IX509SignatureInformation *,IX509SignatureInformation *);
		static long s_InitializeFromSignatureAlgorithm(IX509SignatureInformation *,IObjectId *,IObjectId *,_CRYPTOAPI_BLOB *);
		static long s_SetDefaultHashAlgorithm(IX509SignatureInformation *,IX509PrivateKey *);
		virtual long GetSignatureAlgorithm(short,short,IObjectId * *);
		virtual long SetDefaultValues();
		virtual long get_AlternateSignatureAlgorithm(short *);
		virtual long get_AlternateSignatureAlgorithmSet(short *);
		virtual long get_HashAlgorithm(IObjectId * *);
		virtual long get_NullSigned(short *);
		virtual long get_Parameters(EncodingType,unsigned short * *);
		virtual long get_PublicKeyAlgorithm(IObjectId * *);
		virtual long put_AlternateSignatureAlgorithm(short);
		virtual long put_HashAlgorithm(IObjectId *);
		virtual long put_NullSigned(short);
		virtual long put_Parameters(EncodingType,unsigned short *);
		virtual long put_PublicKeyAlgorithm(IObjectId *);
		~CX509SignatureInformation();
	};

	struct CertEnrollSafeHandle<_CERT_CONTEXT const *,CertContextReleaser>
	{
		~CertEnrollSafeHandle<_CERT_CONTEXT const *,CertContextReleaser>();
	};

	struct CertEnrollSafeHandle<void *,CAHandleReleaser>
	{
		~CertEnrollSafeHandle<void *,CAHandleReleaser>();
	};

	class CipherAlgList
	{
		long p_AddEntry(CipherAlgList::AlgList *,long,ICspAlgorithm *);
		long p_FindOrCreateList(unsigned short const *,CipherAlgList::AlgList * *);
		void p_Cleanup();
	public:
		long AddAlgorithm(ICspAlgorithm *);
		long MergeAlgorithms(ICspAlgorithms *,unsigned short const * *);
		~CipherAlgList();
	};

	class CmcAddAttributesInfo
	{
		long _Initialize(_CMC_ADD_ATTRIBUTES_INFO *);
		long _Marshal(_CMC_ADD_ATTRIBUTES_INFO *);
		static long s_FreeMarshaled(_CMC_ADD_ATTRIBUTES_INFO *);
	public:
		CmcAddAttributesInfo();
		long get_Attributes(ICryptAttributes * *);
		virtual long InitializeDecode(CByteArray *);
		virtual long InitializeEncode(ICryptAttributes *,bool);
		virtual long _InternalDecode(CByteArray *);
		virtual long _InternalEncode();
		virtual ~CmcAddAttributesInfo();
	};

	class CmcAddExtensionsInfo
	{
		long _Initialize(_CMC_ADD_EXTENSIONS_INFO *);
		long _Marshal(_CMC_ADD_EXTENSIONS_INFO *);
	public:
		CmcAddExtensionsInfo();
		virtual long InitializeDecode(CByteArray *);
		virtual long InitializeEncode(IX509Extensions *,bool);
		virtual long _InternalDecode(CByteArray *);
		virtual long _InternalEncode();
		virtual ~CmcAddExtensionsInfo();
	};

	class CmcAssociatedInfo
	{
	protected:
		long _InitializeEncoding(unsigned short *,bool);
	public:
		CmcAssociatedInfo();
		long Associate(CmcTaggedContentInfo *);
		long Associate(CmcTaggedRequest *);
		long SetReferences(long,long,long *);
		long _FixReferences();
		long get_CertReferences(long *,long * *);
		virtual ~CmcAssociatedInfo();
	};

	struct CmcAttribute
	{
		CmcAttribute();
		virtual long InitializeDecode(IObjectId *,CByteArray *);
		virtual ~CmcAttribute();
	};

	class CmcAttributeRegistrationInformation
	{
		long p_CanonicalizeURLParm(unsigned short const *,unsigned short * *);
		virtual long _InternalDecode(CByteArray *);
		virtual long _InternalEncode();
	public:
		CmcAttributeRegistrationInformation();
		long get_NameValuePairs(IX509NameValuePairs * *);
		virtual long InitializeDecode(CByteArray *);
		virtual long InitializeEncode(IX509NameValuePairs *);
		virtual ~CmcAttributeRegistrationInformation();
	};

	struct CmcAttributeSenderNonce
	{
		CmcAttributeSenderNonce();
		virtual long InitializeDecode(CByteArray *);
		virtual long InitializeEncode(CByteArray *);
		virtual ~CmcAttributeSenderNonce();
	};

	struct CmcAttributeTransactionId
	{
		CmcAttributeTransactionId();
		virtual long InitializeDecode(CByteArray *);
		virtual long InitializeEncode(long);
		virtual ~CmcAttributeTransactionId();
	};

	struct CmcAttributes
	{
		long Add(CmcAttribute *);
		long _Initialize(_CRYPT_ATTRIBUTE *);
		long _Marshal(_CRYPT_ATTRIBUTE *);
		static long s_FreeMarshaled(_CRYPT_ATTRIBUTE *);
	};

	class CmcRequest
	{
		long _Marshal(_CMC_DATA_INFO *);
	protected:
		virtual long _InternalDecode(CByteArray *);
		virtual long _InternalEncode();
	public:
		CmcRequest();
		virtual long InitializeDecode(CByteArray *);
		virtual long InitializeEncode(CmcTaggedContentInfos *,CmcTaggedRequests *);
		virtual long get_TaggedRequests(CmcTaggedRequests * *);
		virtual ~CmcRequest();
	};

	class CmcResponse
	{
		long _Marshal(_CMC_RESPONSE_INFO *);
		long _ValidateReferences(CmcAssociatedInfo *);
		long _ValidateReferences(CmcTaggedAttribute *);
	protected:
		long Initialize();
		long _AssignBodyPartIds();
		virtual long _InternalDecode(CByteArray *);
		virtual long _InternalEncode();
	public:
		CmcResponse();
		long Add(CmcTaggedAttribute *);
		virtual long InitializeDecode(CByteArray *);
		virtual long InitializeEncode(CmcTaggedContentInfos *);
		virtual long get_TaggedAttributes(CmcTaggedAttributes * *);
		virtual long get_TaggedContentInfos(CmcTaggedContentInfos * *);
		virtual ~CmcResponse();
	};

	class CmcStatusInfo
	{
		long _Initialize(_CMC_STATUS_INFO *);
		long _Marshal(_CMC_STATUS_INFO *);
	public:
		virtual long InitializeDecode(CByteArray *);
		virtual long InitializeEncode(CmcStatus,unsigned short *,bool);
		virtual long InitializeEncodeFailureReason(unsigned short *,CmcFailInfo,bool);
		virtual long InitializeEncodePending(unsigned short *,CByteArray *,_FILETIME,bool);
		virtual long _InternalDecode(CByteArray *);
		virtual long _InternalEncode();
		virtual ~CmcStatusInfo();
	};

	struct CmcTaggedAttribute
	{
		bool _ContainsCmcAssociatedInfo();
		long _Initialize(_CMC_TAGGED_ATTRIBUTE *);
		virtual long InitializeEncode(CmcAttribute *);
		virtual long get_Attributes(CmcAttributes * *);
		virtual ~CmcTaggedAttribute();
	};

	class CmcTaggedAttributes
	{
		bool p_HasRequesterRegInfo(CmcTaggedAttribute *,_CMC_TAGGED_ATTRIBUTE *);
	public:
		long _Initialize(unsigned long,_CMC_TAGGED_ATTRIBUTE *);
		long _Marshal(unsigned long *,_CMC_TAGGED_ATTRIBUTE * *);
		static long s_FreeMarshaled(unsigned long,_CMC_TAGGED_ATTRIBUTE *);
	};

	struct CmcTaggedCertificationRequest
	{
		long _Initialize(_CMC_TAGGED_CERT_REQUEST *);
		virtual long Initialize(CByteArray *);
		virtual long get_CertificationRequest(CByteArray * *);
		virtual ~CmcTaggedCertificationRequest();
	};

	struct CmcTaggedContentInfo
	{
		long _Initialize(_CMC_TAGGED_CONTENT_INFO *);
		virtual long Initialize(CByteArray *);
		virtual long get_ContentInfo(CByteArray * *);
		virtual ~CmcTaggedContentInfo();
	};

	struct CmcTaggedContentInfos
	{
		long _Initialize(unsigned long,_CMC_TAGGED_CONTENT_INFO *);
		long _Marshal(unsigned long *,_CMC_TAGGED_CONTENT_INFO * *);
		static long s_FreeMarshaled(unsigned long,_CMC_TAGGED_CONTENT_INFO *);
	};

	struct CmcTaggedInfo
	{
		virtual ~CmcTaggedInfo();
	};

	struct CmcTaggedRequest
	{
		CmcTaggedRequest();
		long _Initialize(_CMC_TAGGED_REQUEST *);
		long _Marshal(_CMC_TAGGED_REQUEST *);
		virtual long Initialize(CmcTaggedCertificationRequest *);
		virtual long InitializeFromByteArray(CByteArray *);
		virtual long get_CmcTaggedCertificationRequest(CmcTaggedCertificationRequest * *);
		virtual ~CmcTaggedRequest();
	};

	struct CmcTaggedRequests
	{
		long _Initialize(unsigned long,_CMC_TAGGED_REQUEST *);
		long _Marshal(unsigned long *,_CMC_TAGGED_REQUEST * *);
	};

	class CustomRequest
	{
		long p_BuildTemplateNameArray();
	public:
		long CreateDummyCert();
		long CreateOffLineRequest();
		long FailedToCreateRequest(long);
		long SaveRequest();
		long SelectCustomRequestTemplate();
		long SelectPolicyServer();
		long ShowWelcomePage();
		~CustomRequest();
	};

	struct POLICY_SERVER_GROUP
	{
		POLICY_SERVER_GROUP(POLICY_SERVER_GROUP const &);
		~POLICY_SERVER_GROUP();
	};

	class X509CertificateResponse
	{
		long p_BreakCmc(CByteArray *);
		long p_BreakPkcs7(_CRYPTOAPI_BLOB *);
		long p_BuildChain(_CERT_CONTEXT const *,void *);
		long p_CheckSignature(void *,_CERT_INFO *,void *);
		long p_CheckSignatures(void *,void *);
		long p_Classify(void *);
		long p_Contains(ISignerCertificates *,ISignerCertificate *,bool *);
		long p_ExtractAttributes(CmcAttribute *);
		long p_ImportFromStore(void *);
		long p_Initialize();
		long p_MatchHash(_CERT_CONTEXT const *,bool *);
		long p_StripPrivateKeyAndAdd(ISignerCertificates *,ISignerCertificate *,bool,long);
	public:
		X509CertificateResponse();
		long DecryptPfx(unsigned short *,bool *,bool,InstallResponseFlags);
		long InitializeDecode(bool,unsigned short *,EncodingType,InstallResponseFlags,unsigned short *,bool);
		long get_Type(X509ResponseType *);
		virtual ~X509CertificateResponse();
	};

	struct XCNSimpleCollection<CByteArray *>
	{
		long Add(CByteArray *);
		long Item(long,CByteArray * *);
		virtual long AddRange(XCNSimpleCollection<CByteArray *> *);
		~XCNSimpleCollection<CByteArray *>();
	};

	struct XCNSimpleCollection<CmcAttribute *>
	{
		long Add(CmcAttribute *);
		long Item(long,CmcAttribute * *);
		virtual long AddRange(XCNSimpleCollection<CmcAttribute *> *);
		~XCNSimpleCollection<CmcAttribute *>();
	};

	struct XCNSimpleCollection<CmcStatusInfo *>
	{
		long Add(CmcStatusInfo *);
		long Item(long,CmcStatusInfo * *);
		virtual long AddRange(XCNSimpleCollection<CmcStatusInfo *> *);
		~XCNSimpleCollection<CmcStatusInfo *>();
	};

	struct XCNSimpleCollection<CmcTaggedAttribute *>
	{
		long Add(CmcTaggedAttribute *);
		long Item(long,CmcTaggedAttribute * *);
		virtual long AddRange(XCNSimpleCollection<CmcTaggedAttribute *> *);
		~XCNSimpleCollection<CmcTaggedAttribute *>();
	};

	struct XCNSimpleCollection<CmcTaggedContentInfo *>
	{
		long Add(CmcTaggedContentInfo *);
		long Item(long,CmcTaggedContentInfo * *);
		virtual long AddRange(XCNSimpleCollection<CmcTaggedContentInfo *> *);
		~XCNSimpleCollection<CmcTaggedContentInfo *>();
	};

	struct XCNSimpleCollection<CmcTaggedRequest *>
	{
		bool Contains(CmcTaggedRequest *);
		long Add(CmcTaggedRequest *);
		long Item(long,CmcTaggedRequest * *);
		virtual long AddRange(XCNSimpleCollection<CmcTaggedRequest *> *);
		~XCNSimpleCollection<CmcTaggedRequest *>();
	};

	struct _CopyVectorItem<IAlternativeName>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<IAlternativeName> const *);
	};

	struct _CopyVectorItem<ICAStatus>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<ICAStatus> const *);
	};

	struct _CopyVectorItem<ICertProperty>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<ICertProperty> const *);
	};

	struct _CopyVectorItem<ICertificatePolicy>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<ICertificatePolicy> const *);
	};

	struct _CopyVectorItem<ICertificationAuthority>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<ICertificationAuthority> const *);
	};

	struct _CopyVectorItem<ICryptAttribute>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<ICryptAttribute> const *);
	};

	struct _CopyVectorItem<ICspAlgorithm>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<ICspAlgorithm> const *);
	};

	struct _CopyVectorItem<ICspInformation>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<ICspInformation> const *);
	};

	struct _CopyVectorItem<ICspStatus>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<ICspStatus> const *);
	};

	struct _CopyVectorItem<IObjectId>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<IObjectId> const *);
	};

	struct _CopyVectorItem<IPolicyQualifier>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<IPolicyQualifier> const *);
	};

	struct _CopyVectorItem<ISignerCertificate>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<ISignerCertificate> const *);
	};

	struct _CopyVectorItem<ISmimeCapability>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<ISmimeCapability> const *);
	};

	struct _CopyVectorItem<IX509Attribute>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<IX509Attribute> const *);
	};

	struct _CopyVectorItem<IX509CertificateRevocationListEntry>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<IX509CertificateRevocationListEntry> const *);
	};

	struct _CopyVectorItem<IX509CertificateTemplate>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<IX509CertificateTemplate> const *);
	};

	struct _CopyVectorItem<IX509Enrollment>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<IX509Enrollment> const *);
	};

	struct _CopyVectorItem<IX509Extension>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<IX509Extension> const *);
	};

	struct _CopyVectorItem<IX509NameValuePair>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<IX509NameValuePair> const *);
	};

	struct _CopyVectorItem<IX509PolicyServerUrl>
	{
		static long copy(tagVARIANT *,ATL::CComPtr<IX509PolicyServerUrl> const *);
	};

	AlgorithmOperationFlags GetOperationsFromType(AlgorithmType);
	AlgorithmType GetTypeFromLegacyAlgid(unsigned long);
	CertEnroll::CWindowsEvents g_WindowsEvents;
	CertEnroll::TemplatePropertyDetails * g_tmplProp;
	CertEnroll::_CTXMAP * g_ctxMap;
	CertEnroll::_DECODEATTESTATTRIBMAP * s_AttestAttribMap;
	CertEnroll::_KEYUSAGEMAP * s_aKeyUsageMap;
	CertEnroll::_KEYUSAGEMAP * s_aOperationMap;
	X509PrivateKeyUsageFlags KeyUsagePropFromKeySpec(X509KeySpec);
	X509PrivateKeyUsageFlags s_MapKeyUsage(unsigned long,CertEnroll::_KEYUSAGEMAP const *,unsigned long);
	_CERT_CONTEXT const * scFindCertInStore(void *,_CERT_CONTEXT const *,_CRYPTOAPI_BLOB const *);
	_CRYPT_OID_INFO const * sigFindSigOidInfo(unsigned short const *,unsigned short const *,unsigned long *,unsigned long *);
	bool BstrEqualI(unsigned short *,unsigned short *);
	bool IsDisallowedAlgorithm(unsigned short const *,unsigned short * *);
	bool IsIgnoreGetSDError(long);
	bool LogActive();
	bool _UseMachinePolicy(unsigned short const *);
	bool krKeyRepairEnabled(bool);
	bool myFormatEnrollStatus(EnrollmentEnrollStatus,unsigned short *,unsigned __int64);
	bool operator<(double,_FILETIME);
	bool x500NeedsQuotes(unsigned short const *,unsigned long);
	char const * * s_LogonTemplateStateMap;
	int CompareDisplayName(unsigned short *,unsigned short *);
	int ComparePolicyServerGroup(void const *,void const *);
	long AddAlgorithmWorker(ICspAlgorithm *,long,void *);
	long AddAttributeValueExtensionWorker(IX509Attribute *,long,void *);
	long AddCAIfNotExisting(X509CertificateEnrollmentContext,ICertificationAuthorities *,ICertConfig2 *);
	long AddCAsFromICertConfig(X509CertificateEnrollmentContext,ICertificationAuthorities *);
	long AddCriticalExtensionWorker(IX509Extension *,long,void *);
	long AddCryptAttributeWorker(ICryptAttribute *,long,void *);
	long AddExtensionWorker(IX509Extension *,long,void *);
	long AddFilteredExtensionWorker(IX509Extension *,long,void *);
	long AddNameValuePairWorker(IX509NameValuePair *,long,void *);
	long AddOpExtensionWorker(IX509Extension *,long,void *);
	long AddPropertyExtensionWorker(ICertProperty *,long,void *);
	long AddRefCertContext(_CERT_CONTEXT const *,_CERT_CONTEXT const * *);
	long AddSelectPropertyWorker(ICertProperty *,long,void *);
	long AddSignerWorker(ISignerCertificate *,long,void *);
	long AllowAddNewCEP(X509CertificateEnrollmentContext,bool *);
	long BStrAppend(unsigned short * *,unsigned short const *,unsigned short const *);
	long CRLEntryMarshalWorker(IX509CertificateRevocationListEntry *,long,void *);
	long CertEnrollCreateComObject<IAlternativeNames,CAlternativeNames>(IAlternativeNames * *);
	long CertEnrollCreateComObject<ICAStatus,CCAStatus>(ICAStatus * *);
	long CertEnrollCreateComObject<ICAStatuses,CCAStatuses>(ICAStatuses * *);
	long CertEnrollCreateComObject<ICertProperties,CCertProperties>(ICertProperties * *);
	long CertEnrollCreateComObject<ICertProperty,CCertProperty>(ICertProperty * *);
	long CertEnrollCreateComObject<ICertPropertyArchived,CCertPropertyArchived>(ICertPropertyArchived * *);
	long CertEnrollCreateComObject<ICertPropertyArchivedKeyHash,CCertPropertyArchivedKeyHash>(ICertPropertyArchivedKeyHash * *);
	long CertEnrollCreateComObject<ICertPropertyDescription,CCertPropertyDescription>(ICertPropertyDescription * *);
	long CertEnrollCreateComObject<ICertPropertyFriendlyName,CCertPropertyFriendlyName>(ICertPropertyFriendlyName * *);
	long CertEnrollCreateComObject<ICertPropertyKeyProvInfo,CCertPropertyKeyProvInfo>(ICertPropertyKeyProvInfo * *);
	long CertEnrollCreateComObject<ICertPropertyRenewal,CCertPropertyRenewal>(ICertPropertyRenewal * *);
	long CertEnrollCreateComObject<ICertificatePolicies,CCertificatePolicies>(ICertificatePolicies * *);
	long CertEnrollCreateComObject<ICertificatePolicy,CCertificatePolicy>(ICertificatePolicy * *);
	long CertEnrollCreateComObject<ICryptAttributes,CCryptAttributes>(ICryptAttributes * *);
	long CertEnrollCreateComObject<ICspAlgorithms,CCspAlgorithms>(ICspAlgorithms * *);
	long CertEnrollCreateComObject<ICspInformations,CCspInformations>(ICspInformations * *);
	long CertEnrollCreateComObject<IObjectId,CObjectId>(IObjectId * *);
	long CertEnrollCreateComObject<IObjectIds,CObjectIds>(IObjectIds * *);
	long CertEnrollCreateComObject<IPolicyQualifiers,CPolicyQualifiers>(IPolicyQualifiers * *);
	long CertEnrollCreateComObject<ISignerCertificate,CSignerCertificate>(ISignerCertificate * *);
	long CertEnrollCreateComObject<ISignerCertificates,CSignerCertificates>(ISignerCertificates * *);
	long CertEnrollCreateComObject<ISmimeCapabilities,CSmimeCapabilities>(ISmimeCapabilities * *);
	long CertEnrollCreateComObject<ISmimeCapability,CSmimeCapability>(ISmimeCapability * *);
	long CertEnrollCreateComObject<IX509Attributes,CX509Attributes>(IX509Attributes * *);
	long CertEnrollCreateComObject<IX509CertificateRequestCmc2,CX509CertificateRequestCmc>(IX509CertificateRequestCmc2 * *);
	long CertEnrollCreateComObject<IX509CertificateRequestPkcs10,CX509CertificateRequestPkcs10>(IX509CertificateRequestPkcs10 * *);
	long CertEnrollCreateComObject<IX509CertificateRequestPkcs10V3,CX509CertificateRequestPkcs10>(IX509CertificateRequestPkcs10V3 * *);
	long CertEnrollCreateComObject<IX509CertificateTemplates,CX509CertificateTemplates>(IX509CertificateTemplates * *);
	long CertEnrollCreateComObject<IX509Enrollment,CX509Enrollment>(IX509Enrollment * *);
	long CertEnrollCreateComObject<IX509EnrollmentPolicyServer,CX509EnrollmentPolicyActiveDirectory>(IX509EnrollmentPolicyServer * *);
	long CertEnrollCreateComObject<IX509EnrollmentPolicyServer,CX509EnrollmentPolicyWebService>(IX509EnrollmentPolicyServer * *);
	long CertEnrollCreateComObject<IX509EnrollmentStatus,CX509EnrollmentStatus>(IX509EnrollmentStatus * *);
	long CertEnrollCreateComObject<IX509Enrollments,CX509Enrollments>(IX509Enrollments * *);
	long CertEnrollCreateComObject<IX509Extension,CX509Extension>(IX509Extension * *);
	long CertEnrollCreateComObject<IX509NameValuePair,CX509NameValuePair>(IX509NameValuePair * *);
	long CertEnrollCreateComObject<IX509NameValuePairs,CX509NameValuePairs>(IX509NameValuePairs * *);
	long CertEnrollCreateComObject<IX509PolicyServerUrl,CX509PolicyServerUrl>(IX509PolicyServerUrl * *);
	long CertEnrollCreateComObject<IX509PrivateKey,CX509PrivateKey>(IX509PrivateKey * *);
	long CertEnrollCreateComObject<IX509SignatureInformation,CX509SignatureInformation>(IX509SignatureInformation * *);
	long CheckCspListWorker(unsigned short *,long,void *);
	long CheckSmartCardCsp(unsigned short *,unsigned long,bool *);
	long CompareVariantStringWorker(unsigned short *,long,void *);
	long CreateCCertificatePolicies(_CERT_POLICIES_INFO *,ICertificatePolicies * *);
	long CreateCCertificatePolicy(_CERT_POLICY_INFO *,ICertificatePolicy * *);
	long CreateCPolicyQualifier(_CERT_POLICY_QUALIFIER_INFO *,IPolicyQualifier * *);
	long CreateCSmimeCapabilities(_CRYPT_SMIME_CAPABILITIES *,ISmimeCapabilities * *);
	long CreateCSmimeCapability(_CRYPT_SMIME_CAPABILITY *,ISmimeCapability * *);
	long CreateSmimeCapability(IObjectId *,long,ISmimeCapability * *);
	long CreateTemplateFromCertificate(HWND__ *,X509CertificateEnrollmentContext,_CERT_CONTEXT const *,IX509CertificateTemplateInternal * *,IX509EnrollmentPolicyServer * *);
	long CreateTemplateFromDefaultPolicyServer(HWND__ *,X509CertificateEnrollmentContext,bool,unsigned short const *,IX509EnrollmentPolicyServer * *,IX509CertificateTemplateInternal * *);
	long CreateTemplateFromPolicyServer(IX509EnrollmentPolicyServer *,unsigned short const *,IX509CertificateTemplateInternal * *);
	long CspCreateCspStatusWorker(ICspInformation *,long,void *);
	long CspNameSetStatusWorker(unsigned short *,long,void *);
	long CspStatusCreateKeyWorker(ICspStatus *,long,void *);
	long CspStatusDumpWorker(ICspStatus *,long,void *);
	long CspStatusEnabledNamedCspWorker(ICspStatus *,long,void *);
	long CspStatusIsSmartCardWorker(ICspStatus *,long,void *);
	long CspStatusSetDisplayOrdinalWorker(ICspStatus *,long,void *);
	long CspStatusSetExcludedErrorWorker(ICspStatus *,long,void *);
	long DecodeAttributeWorker(ICryptAttribute *,long,void *);
	long DecodeCmcAttributeWorker(CertEnroll::CmcAttribute *,long,void *);
	long DecodeCmcTaggedAttributeWorker(CertEnroll::CmcTaggedAttribute *,long,void *);
	long DecodeExtensionWorker(IX509Extension *,long,void *);
	long EnrollAppendStatus(unsigned short * *,unsigned short const *,unsigned short const *,long);
	long EnrollClearAndCopyCertStore(void *,void * *);
	long EnrollCopyCertStore(void *,void *);
	long EnrollCreateAndCopyCertStore(void *,void * *);
	long EnrollOpenStore(X509CertificateEnrollmentContext,unsigned short const *,void * *);
	long EnumCmcAttributes(CertEnroll::CmcAttributes *,long (*)(CertEnroll::CmcAttribute *,long,void *),void *);
	long EnumCmcTaggedAttributes(CertEnroll::CmcTaggedAttributes *,long (*)(CertEnroll::CmcTaggedAttribute *,long,void *),void *);
	long ExtensionMarshalWorker(IX509Extension *,long,void *);
	long ExtractNameValueWorker(IX509NameValuePair *,long,void *);
	long FillRequestParameters(X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *,_CERT_CONTEXT const *,X509RequestInheritOptions,CertEnroll::CRequestParameters *);
	long FindCertWorker(ISignerCertificate *,long,void *);
	long FindCertificateFromTemplateAndLatestNotAfterDate(HWND__ *,X509CertificateEnrollmentContext,void *,IX509CertificateTemplateInternal *,_CERT_CONTEXT * *);
	long FindObjectIdWorker(IObjectId *,long,void *);
	long FindPolicyServerFromCert(HWND__ *,_CERT_CONTEXT const *,X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer * *);
	long FindPropertyWorker(ICertProperty *,long,void *);
	long FindTemplateByName(IX509EnrollmentPolicyServer *,unsigned short *,IX509CertificateTemplateInternal * *);
	long FormatPendingRetrievalContextMessage(IX509CertificateTemplateInternal *,unsigned short * *);
	long GetAuthorityHandle(IX509PrivateKey *,unsigned __int64 *,unsigned __int64 *);
	long GetBooleanProperty(bool,short *);
	long GetCertProperty(_CERT_CONTEXT const *,EncodingType,unsigned short * *);
	long GetDisplayName(CertEnroll::POLICY_SERVER_GROUP const *,unsigned short * *);
	long GetICertConfigCAs(X509CertificateEnrollmentContext,ICertificationAuthorities * *);
	long GetInterfaceProperty<CByteArray>(CertEnroll::CByteArray *,CertEnroll::CByteArray * *);
	long GetInterfaceProperty<CmcTaggedRequests>(CertEnroll::CmcTaggedRequests *,CertEnroll::CmcTaggedRequests * *);
	long GetInterfaceProperty<IAlternativeNames>(IAlternativeNames *,IAlternativeNames * *);
	long GetInterfaceProperty<ICAStatuses>(ICAStatuses *,ICAStatuses * *);
	long GetInterfaceProperty<ICertProperties>(ICertProperties *,ICertProperties * *);
	long GetInterfaceProperty<ICertificatePolicies>(ICertificatePolicies *,ICertificatePolicies * *);
	long GetInterfaceProperty<ICertificationAuthorityInternal>(ICertificationAuthorityInternal *,ICertificationAuthorityInternal * *);
	long GetInterfaceProperty<ICryptAttributes>(ICryptAttributes *,ICryptAttributes * *);
	long GetInterfaceProperty<ICspAlgorithm>(ICspAlgorithm *,ICspAlgorithm * *);
	long GetInterfaceProperty<ICspAlgorithms>(ICspAlgorithms *,ICspAlgorithms * *);
	long GetInterfaceProperty<ICspInformation>(ICspInformation *,ICspInformation * *);
	long GetInterfaceProperty<ICspInformations>(ICspInformations *,ICspInformations * *);
	long GetInterfaceProperty<ICspStatus>(ICspStatus *,ICspStatus * *);
	long GetInterfaceProperty<ICspStatuses>(ICspStatuses *,ICspStatuses * *);
	long GetInterfaceProperty<IObjectId>(IObjectId *,IObjectId * *);
	long GetInterfaceProperty<IObjectIds>(IObjectIds *,IObjectIds * *);
	long GetInterfaceProperty<IPolicyQualifiers>(IPolicyQualifiers *,IPolicyQualifiers * *);
	long GetInterfaceProperty<ISignerCertificate>(ISignerCertificate *,ISignerCertificate * *);
	long GetInterfaceProperty<ISignerCertificates>(ISignerCertificates *,ISignerCertificates * *);
	long GetInterfaceProperty<ISmimeCapabilities>(ISmimeCapabilities *,ISmimeCapabilities * *);
	long GetInterfaceProperty<IX500DistinguishedName>(IX500DistinguishedName *,IX500DistinguishedName * *);
	long GetInterfaceProperty<IX509Attributes>(IX509Attributes *,IX509Attributes * *);
	long GetInterfaceProperty<IX509CertificateRequest>(IX509CertificateRequest *,IX509CertificateRequest * *);
	long GetInterfaceProperty<IX509CertificateRevocationListEntries>(IX509CertificateRevocationListEntries *,IX509CertificateRevocationListEntries * *);
	long GetInterfaceProperty<IX509CertificateTemplateInternal>(IX509CertificateTemplateInternal *,IX509CertificateTemplateInternal * *);
	long GetInterfaceProperty<IX509EnrollmentStatus>(IX509EnrollmentStatus *,IX509EnrollmentStatus * *);
	long GetInterfaceProperty<IX509Extensions>(IX509Extensions *,IX509Extensions * *);
	long GetInterfaceProperty<IX509NameValuePairs>(IX509NameValuePairs *,IX509NameValuePairs * *);
	long GetInterfaceProperty<IX509PrivateKey>(IX509PrivateKey *,IX509PrivateKey * *);
	long GetInterfaceProperty<IX509SignatureInformation>(IX509SignatureInformation *,IX509SignatureInformation * *);
	long GetPolicyServerObject(HWND__ *,unsigned short *,unsigned short *,X509CertificateEnrollmentContext,IX509EnrollmentPolicyServer * *);
	long GetPolicyServerObjectsNoLoad(unsigned short *,unsigned short *,X509CertificateEnrollmentContext,ATL::CSimpleArray<ATL::CComPtr<IX509EnrollmentPolicyServer>,ATL::CSimpleArrayEqualHelper<ATL::CComPtr<IX509EnrollmentPolicyServer> > > &);
	long GetStringArrayProperty(ATL::CSimpleArray<unsigned short *,ATL::CSimpleArrayEqualHelper<unsigned short *> > const &,tagVARIANT *);
	long GetStringProperty(unsigned short const *,unsigned short * *);
	long GetUnicodePropertyString(unsigned char const *,unsigned long,unsigned long *,unsigned short * *);
	long GetValidLongProperty(long,long *);
	long GetValueProperty<_FILETIME>(_FILETIME,_FILETIME *);
	long GetValueProperty<bool>(bool,bool *);
	long GetValueProperty<long>(long,long *);
	long GetValueProperty<short>(short,short *);
	long KRRepairKeys(bool);
	long MarkExtensionCriticalByObjectIdWorker(IObjectId *,long,void *);
	long MatchPolicyIdFromPolicyServer(IX509EnrollmentPolicyServer *,IX509EnrollmentPolicyServer *,bool *);
	long MatchPolicyIdFromTemplate(IX509EnrollmentPolicyServer *,IX509CertificateTemplateInternal *,bool *);
	long PKGetProviderFromName(unsigned short *,ICspInformations *,ICspInformation * *);
	long PKGetProviderProperties(unsigned short const *,ICspInformations *,bool *,bool *);
	long PKRemapSmartCardProviderToCNG(unsigned short const *,unsigned short * *);
	long PutBooleanProperty(bool,short,bool *);
	long PutStringProperty(bool,bool,unsigned short *,unsigned short * *);
	long RemoveAttributeByObjectIdWorker(IObjectId *,long,void *);
	long RemoveExtensionByObjectIdWorker(IObjectId *,long,void *);
	long RemoveNonCriticalExtensionWorker(IX509Extension *,long,void *);
	long SetCspStatusError(ICspStatus *,long,unsigned int,unsigned long);
	long SetCspStatusNoMatch(ICspStatus *,unsigned long);
	long SetCspStatusOrdinal(ICspStatus *,long *,bool);
	long SetPropertyWorker(ICertProperty *,long,void *);
	long SetSelectPropertyWorker(ICertProperty *,long,void *);
	long SetTemplateQueryInfoWorker(IX509CertificateTemplateInternal *,unsigned long,ICertRequest3 *,CertEnroll::_TEMPLATE_QUERY_INFO *);
	long TGetIndexByObjectId<ICryptAttributes,ICryptAttribute>(ICryptAttributes *,IObjectId *,long *);
	long TGetIndexByObjectId<IX509Attributes,IX509Attribute>(IX509Attributes *,IObjectId *,long *);
	long TGetIndexByObjectId<IX509Extensions,IX509Extension>(IX509Extensions *,IObjectId *,long *);
	long UpdateError(long,long *);
	long UpdateMachinePolicyForTemplate(unsigned short const *);
	long UpdateSignerCertWorker(ISignerCertificate *,long,void *);
	long VariantToSimpleArray(tagVARIANT const *,ATL::CSimpleArray<unsigned short *,ATL::CSimpleArrayEqualHelper<unsigned short *> > *);
	long VerifyBStrBYTE(unsigned long,unsigned short *);
	long WSStringsToBstrSimpleArray(_WS_STRING *,unsigned int,ATL::CSimpleArray<unsigned short *,ATL::CSimpleArrayEqualHelper<unsigned short *> > *);
	long _ConvertArrayToArray<tagVARIANT,unsigned short *>(tagVARIANT *,tagVARIANT *);
	long _ConvertArrayToArray<unsigned short *,tagVARIANT>(tagVARIANT *,tagVARIANT *);
	long _ConvertDataElement<tagVARIANT,unsigned short *>(tagVARIANT,unsigned short * *);
	long _ConvertDataElement<unsigned short *,tagVARIANT>(unsigned short *,tagVARIANT *);
	long _CopyArrayElement<tagVARIANT,unsigned short *>(tagSAFEARRAY *,long,tagSAFEARRAY *);
	long _CopyArrayElement<unsigned short *,tagVARIANT>(tagSAFEARRAY *,long,tagSAFEARRAY *);
	long _SetMachinePolicy(unsigned short const *,bool);
	long devAppendStatusText(IX509EnrollmentStatus *,unsigned short const *);
	long devGenRandom(unsigned char *,unsigned long);
	long devGetAIKCAURL(unsigned short const *,unsigned short const *,unsigned short * *);
	long devGetOpaqueAIK(IX509CertificateRequestPkcs10 *,unsigned short * *);
	long devIsEKEncryptCert(_CERT_CONTEXT const *,bool *);
	long devTrimContainer(unsigned short const *,unsigned short * *);
	long krGetKeyIdFromCert(_CERT_CONTEXT const *,unsigned long,unsigned char *);
	long krGetPublicKeyHash(_CERT_PUBLIC_KEY_INFO const *,unsigned long,unsigned char *);
	long krOpenStore(unsigned long,unsigned short const *,void * *);
	long myNCCreateClaim(unsigned __int64,unsigned __int64,KeyAttestationClaimType,unsigned char const *,unsigned long,unsigned short const *,unsigned char * *,unsigned long *);
	long s_CopyNameValuePairs(IX509NameValuePairs *,IX509NameValuePairs *);
	long s_PreInvoke(unsigned short const *,long,unsigned short *,tagDISPPARAMS * *,tagDISPPARAMS *);
	long scCopyCertProperties(_CERT_CONTEXT const *,_CERT_CONTEXT const *);
	long scSerializeCertContext(_CERT_CONTEXT const *,unsigned short * *);
	long sigCombineStrings(unsigned short const *,unsigned short const *,unsigned short * *);
	long signLoadSerializedCertificate(unsigned char const *,unsigned long,_CERT_CONTEXT const * *);
	long x500QuoteEscapedRDNs(unsigned short const *,unsigned short * *);
	unsigned short const * const g_CAlternativeName__wszClass;
	unsigned short const * const g_CAlternativeNames__wszClass;
	unsigned short const * const g_CBinaryConverter__wszClass;
	unsigned short const * const g_CCAStatus__wszClass;
	unsigned short const * const g_CCAStatuses__wszClass;
	unsigned short const * const g_CCertProperties__wszClass;
	unsigned short const * const g_CCertPropertyArchivedKeyHash__wszClass;
	unsigned short const * const g_CCertPropertyArchived__wszClass;
	unsigned short const * const g_CCertPropertyAutoEnroll__wszClass;
	unsigned short const * const g_CCertPropertyBackedUp__wszClass;
	unsigned short const * const g_CCertPropertyDescription__wszClass;
	unsigned short const * const g_CCertPropertyEnrollmentPolicyServer__wszClass;
	unsigned short const * const g_CCertPropertyEnrollment__wszClass;
	unsigned short const * const g_CCertPropertyFriendlyName__wszClass;
	unsigned short const * const g_CCertPropertyKeyProvInfo__wszClass;
	unsigned short const * const g_CCertPropertyRenewal__wszClass;
	unsigned short const * const g_CCertPropertyRequestOriginator__wszClass;
	unsigned short const * const g_CCertPropertySHA1Hash__wszClass;
	unsigned short const * const g_CCertProperty__wszClass;
	unsigned short const * const g_CCertificateAttestationChallenge__wszClass;
	unsigned short const * const g_CCertificatePolicies__wszClass;
	unsigned short const * const g_CCertificatePolicy__wszClass;
	unsigned short const * const g_CCertificationAuthorities__wszClass;
	unsigned short const * const g_CCertificationAuthority__wszClass;
	unsigned short const * const g_CCryptAttribute__wszClass;
	unsigned short const * const g_CCryptAttributes__wszClass;
	unsigned short const * const g_CCspAlgorithm__wszClass;
	unsigned short const * const g_CCspAlgorithms__wszClass;
	unsigned short const * const g_CCspInformation__wszClass;
	unsigned short const * const g_CCspInformations__wszClass;
	unsigned short const * const g_CCspStatus__wszClass;
	unsigned short const * const g_CCspStatuses__wszClass;
	unsigned short const * const g_CObjectId__wszClass;
	unsigned short const * const g_CObjectIds__wszClass;
	unsigned short const * const g_CPkcs10__wszClass;
	unsigned short const * const g_CPolicyQualifier__wszClass;
	unsigned short const * const g_CPolicyQualifiers__wszClass;
	unsigned short const * const g_CSignerCertificate__wszClass;
	unsigned short const * const g_CSignerCertificates__wszClass;
	unsigned short const * const g_CSmimeCapabilities__wszClass;
	unsigned short const * const g_CSmimeCapability__wszClass;
	unsigned short const * const g_CX500DistinguishedName__wszClass;
	unsigned short const * const g_CX509AttributeArchiveKeyHash__wszClass;
	unsigned short const * const g_CX509AttributeArchiveKey__wszClass;
	unsigned short const * const g_CX509AttributeClientId__wszClass;
	unsigned short const * const g_CX509AttributeCspProvider__wszClass;
	unsigned short const * const g_CX509AttributeExtensions__wszClass;
	unsigned short const * const g_CX509AttributeOSVersion__wszClass;
	unsigned short const * const g_CX509AttributeRenewalCertificate__wszClass;
	unsigned short const * const g_CX509Attribute__wszClass;
	unsigned short const * const g_CX509Attributes__wszClass;
	unsigned short const * const g_CX509CertificateRequestCertificate__wszClass;
	unsigned short const * const g_CX509CertificateRequestCmc__wszClass;
	unsigned short const * const g_CX509CertificateRequestPkcs10__wszClass;
	unsigned short const * const g_CX509CertificateRequestPkcs7__wszClass;
	unsigned short const * const g_CX509CertificateRevocationListEntries__wszClass;
	unsigned short const * const g_CX509CertificateRevocationListEntry__wszClass;
	unsigned short const * const g_CX509CertificateRevocationList__wszClass;
	unsigned short const * const g_CX509CertificateTemplateADWritable__wszClass;
	unsigned short const * const g_CX509CertificateTemplate__wszClass;
	unsigned short const * const g_CX509CertificateTemplates__wszClass;
	unsigned short const * const g_CX509EndorsementKey__wszClass;
	unsigned short const * const g_CX509EnrollmentHelper__wszClass;
	unsigned short const * const g_CX509EnrollmentManager__wszClass;
	unsigned short const * const g_CX509EnrollmentPolicyActiveDirectory__wszClass;
	unsigned short const * const g_CX509EnrollmentStatus__wszClass;
	unsigned short const * const g_CX509EnrollmentWebClassFactory__wszClass;
	unsigned short const * const g_CX509Enrollment__wszClass;
	unsigned short const * const g_CX509Enrollments__wszClass;
	unsigned short const * const g_CX509ExtensionAlternativeNames__wszClass;
	unsigned short const * const g_CX509ExtensionAuthorityKeyIdentifier__wszClass;
	unsigned short const * const g_CX509ExtensionBasicConstraints__wszClass;
	unsigned short const * const g_CX509ExtensionCertificatePolicies__wszClass;
	unsigned short const * const g_CX509ExtensionEnhancedKeyUsage__wszClass;
	unsigned short const * const g_CX509ExtensionKeyUsage__wszClass;
	unsigned short const * const g_CX509ExtensionMSApplicationPolicies__wszClass;
	unsigned short const * const g_CX509ExtensionSmimeCapabilities__wszClass;
	unsigned short const * const g_CX509ExtensionSubjectKeyIdentifier__wszClass;
	unsigned short const * const g_CX509ExtensionTemplateName__wszClass;
	unsigned short const * const g_CX509ExtensionTemplate__wszClass;
	unsigned short const * const g_CX509Extension__wszClass;
	unsigned short const * const g_CX509Extensions__wszClass;
	unsigned short const * const g_CX509MachineEnrollmentFactory__wszClass;
	unsigned short const * const g_CX509NameValuePair__wszClass;
	unsigned short const * const g_CX509NameValuePairs__wszClass;
	unsigned short const * const g_CX509PrivateKey__wszClass;
	unsigned short const * const g_CX509PublicKey__wszClass;
	unsigned short const * const g_CX509SCEPEnrollmentHelper__wszClass;
	unsigned short const * const g_CX509SCEPEnrollment__wszClass;
	unsigned short const * const g_CX509SignatureInformation__wszClass;
	unsigned short const * mywszSCEPFailInfo(X509SCEPFailInfo);
	unsigned short const * mywszSCEPPkiStatus(X509SCEPDisposition);
	unsigned short const * wszAERequestStatus(CertEnroll::AERequestStatus);
	unsigned short const * wszEnrollStatus(EnrollmentEnrollStatus);
	unsigned short const * wszQueryStatus(EnrollmentQueryStatus);
	unsigned short const * wszQuerySubStatus(EnrollmentQuerySubStatus);
	void DerefCertContext(_CERT_CONTEXT const *);
	void DumpBlob(unsigned short const *,unsigned char const *,unsigned long);
	void DumpByteArray(unsigned short const *,CertEnroll::CByteArray const *);
	void DumpStore(void *,X509CertificateEnrollmentContext);
	void FreeBstrArray(ATL::CSimpleArray<unsigned short *,ATL::CSimpleArrayEqualHelper<unsigned short *> > *);
	void FreeCEPGroup(ATL::CSimpleArray<CertEnroll::POLICY_SERVER_GROUP,ATL::CSimpleArrayEqualHelper<CertEnroll::POLICY_SERVER_GROUP> > &);
	void LogClose();
	void LogOpen();
	void Swap<ATL::CComPtr<IX509EnrollmentPolicyServer> >(ATL::CComPtr<IX509EnrollmentPolicyServer> &,ATL::CComPtr<IX509EnrollmentPolicyServer> &);
	void devDumpBStr(unsigned short const *,unsigned short *);
	void devDumpBlob(unsigned short const *,unsigned char const *,unsigned long);
	void devGetAIKRetryType(long,DelayRetryAction *);
	void devGetErrorSymbol(ICertRequest3 *,unsigned long,unsigned short * *);
	void devSaveBStr(unsigned short const *,unsigned short *);
	void devSaveBlob(unsigned short const *,unsigned char const *,unsigned long);
	void enrollDumpCert(unsigned short const *,X509CertificateEnrollmentContext,unsigned short const *,char const *,unsigned long,_CERT_CONTEXT const *);
	void enrollDumpStore(unsigned short const *,X509CertificateEnrollmentContext,unsigned short const *,char const *,void *);
	void sigGetAlgLookupString(unsigned short const *,unsigned long,unsigned short * *);
	void sigGetAlgString(IObjectId *,ObjectIdGroupId,unsigned short * *);
};

namespace CertEnrollHttp
{
	long CreateComObject<CertEnroll::CObjectIds,IObjectIds>(IObjectIds * *);
	long CreateComObject<CertEnroll::CX509CertificateTemplates,IX509CertificateTemplates>(IX509CertificateTemplates * *);
	long ProtectString(unsigned short const *,_CRYPTOAPI_BLOB *);
	long UnprotectString(_CRYPTOAPI_BLOB *,unsigned short * *);
	long WSStringToBstr(_WS_STRING *,unsigned short * *);
	void FreeProtectedBlob(_CRYPTOAPI_BLOB *);
	void FreeUnprotectedBStr(unsigned short *);
};

namespace CertSrv
{
	class CEventLog
	{
		int LogThrottleEvent(unsigned long);
		long GetUserToken(_TOKEN_USER * *);
	public:
		long LogEvent(unsigned long,unsigned long,unsigned short,unsigned short const * const *,unsigned long,unsigned char *);
		long LogEventStringArrayHResult(unsigned long,unsigned long,unsigned long,unsigned short const * const *,long);
	};

};

class CertificateUtil
{
	static long GuidStringFromByteArray(unsigned char * const,unsigned long,unsigned short * *);
public:
	static _CERT_EXTENSION * FindExtensionByOid(char const *,_CERT_CONTEXT const *);
	static long DoesExtensionWithValueExist(char const *,unsigned short const *,_CERT_CONTEXT const *,int *);
	static long FindAllCertificatesByOidValue(_CERTFICATE_LOCATION,char const *,unsigned short const *,_CERT_CONTEXT const * * const,unsigned long *);
	static long FindExtensionGuidValueByOid(char const *,_CERT_CONTEXT const *,unsigned short * *);
	static long FindExtensionStrValueByOid(char const *,_CERT_CONTEXT const *,unsigned short * *);
	static void FreeCertificates(_CERT_CONTEXT const * * const,unsigned long);
};

struct DeviceRegistrationStateApi
{
	static long CompareTenantId(_CERT_CONTEXT const *,unsigned short const *,int *);
	static long GetDeviceJoinInfo(unsigned short const *,INFO_KIND,_DSREG_JOIN_INFO_1 * *);
	static long GetJoinCertificate(unsigned short const *,_JOIN_TYPE,INFO_KIND,_CERT_CONTEXT const * *);
	static long GetTenantId(_CERT_CONTEXT const *,unsigned short * *,_DSR_INSTANCE *);
	static long GetWorkplaceJoinInfo(unsigned short const *,INFO_KIND,_DSREG_JOIN_INFO_1 * *);
	static long PopulateJoinInfo(_JOIN_TYPE,_CERT_CONTEXT const *,_DSREG_JOIN_INFO_1 * *);
};

struct IObjectSafetySiteLockImpl<CertEnroll::CX509EnrollmentHelper,1>
{
	virtual long GetApprovedSites(IObjectSafetySiteLock::SiteList const * *,unsigned long *);
	virtual long GetCapabilities(unsigned long *);
	virtual long GetExpiryDate(unsigned long *,_FILETIME *);
	virtual long GetInterfaceSafetyOptions(_GUID const &,unsigned long *,unsigned long *);
	virtual long SetInterfaceSafetyOptions(_GUID const &,unsigned long,unsigned long);
};

struct IObjectSafetySiteLockImpl<CertEnroll::CX509EnrollmentWebClassFactory,1>
{
	virtual long GetApprovedSites(IObjectSafetySiteLock::SiteList const * *,unsigned long *);
	virtual long GetCapabilities(unsigned long *);
	virtual long GetExpiryDate(unsigned long *,_FILETIME *);
	virtual long GetInterfaceSafetyOptions(_GUID const &,unsigned long *,unsigned long *);
	virtual long SetInterfaceSafetyOptions(_GUID const &,unsigned long,unsigned long);
};

struct IObjectSafetySiteLockImpl<CertEnroll::CX509MachineEnrollmentFactory,1>
{
	virtual long GetApprovedSites(IObjectSafetySiteLock::SiteList const * *,unsigned long *);
	virtual long GetCapabilities(unsigned long *);
	virtual long GetExpiryDate(unsigned long *,_FILETIME *);
	virtual long GetInterfaceSafetyOptions(_GUID const &,unsigned long *,unsigned long *);
	virtual long SetInterfaceSafetyOptions(_GUID const &,unsigned long,unsigned long);
};

class JoinStatusStorage
{
	static JoinStatusStorage::struct_join_status_reg_key_info DeviceJoinStatusRegKeyInfo;
	static JoinStatusStorage::struct_join_status_reg_key_info WorkplaceJoinStatusRegKeyInfo;
	static long ReadDeviceKey(struct_join_status *,HKEY__ *,unsigned short const *,unsigned short const *,int);
	static long ReadJoinStatus(unsigned short const *,unsigned short const *,int,struct_join_status *,HKEY__ *,JoinStatusStorage::struct_join_status_reg_key_info const *);
	static long ReadTenantKey(struct_join_status *,HKEY__ *,unsigned short const *,unsigned short const *);
	static long SaveTenantKey(struct_join_status *,HKEY__ *,unsigned short const *,unsigned short const *);
	static long SetDefaultDiscoveryMetadata(struct_join_status *,HKEY__ *,unsigned short const *,unsigned short const *);
public:
	static long ReadDeviceJoinStatus(unsigned short const *,unsigned short const *,int,struct_join_status *);
	static long ReadWorkplaceJoinStatus(unsigned short const *,unsigned short const *,int,struct_join_status *);
};

class Logger
{
	static long FormatString(unsigned short * &,unsigned short const *,char *);
	static long Trace(_TRACE_LEVEL,unsigned short const *,char *);
public:
	static long TraceCritical(unsigned short const *,...);
	static long TraceError(unsigned short const *,...);
	static long TraceInformation(unsigned short const *,...);
	static long TraceVerbose(unsigned short const *,...);
	static long TraceWarning(unsigned short const *,...);
	static long WriteNullOrEmptyParameterFailureEvent(unsigned short const *,unsigned short const *);
	static long WriteRegistryFailureEvent(unsigned long);
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
			virtual ~ActivationFactory<Details::Nil,Details::Nil,Details::Nil,0>();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,0>
		{
			ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,0>();
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual ~ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,0>();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Details::Nil,Details::Nil,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual ~ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Details::Nil,Details::Nil,0>();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Details::Nil,0>
		{
			ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Details::Nil,0>();
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual ~ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Details::Nil,0>();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Details::Nil,0>
		{
			ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Details::Nil,0>();
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual ~ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Details::Nil,0>();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Details::Nil,0>
		{
			ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Details::Nil,0>();
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual ~ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Details::Nil,0>();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Details::Nil,0>
		{
			ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Details::Nil,0>();
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual ~ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Details::Nil,0>();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Details::Nil,0>
		{
			ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Details::Nil,0>();
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual ~ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Details::Nil,0>();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Details::Nil,0>
		{
			ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Details::Nil,0>();
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual ~ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Details::Nil,0>();
		};

		struct ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Details::Nil,Details::Nil,0>
		{
			ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Details::Nil,Details::Nil,0>();
			virtual long ActivateInstance(IInspectable * *);
			virtual long GetIids(unsigned long *,_GUID * *);
			virtual long GetRuntimeClassName(HSTRING__ * *);
			virtual long GetTrustLevel(TrustLevel *);
			virtual long QueryInterface(_GUID const &,void * *);
			virtual unsigned long AddRef();
			virtual unsigned long Release();
			virtual ~ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Details::Nil,Details::Nil,0>();
		};

		struct AgileActivationFactory<Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,0>
		{
			virtual ~AgileActivationFactory<Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,0>();
		};

		struct AgileActivationFactory<Windows::Security::Cryptography::Certificates::ICertificateFactory,Details::Nil,Details::Nil,0>
		{
			virtual ~AgileActivationFactory<Windows::Security::Cryptography::Certificates::ICertificateFactory,Details::Nil,Details::Nil,0>();
		};

		struct AgileActivationFactory<Windows::Security::Cryptography::Certificates::ICertificateStoresStatics,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Details::Nil,0>
		{
			virtual ~AgileActivationFactory<Windows::Security::Cryptography::Certificates::ICertificateStoresStatics,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Details::Nil,0>();
		};

		struct AgileActivationFactory<Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Details::Nil,0>
		{
			virtual ~AgileActivationFactory<Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Details::Nil,0>();
		};

		struct AgileActivationFactory<Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Details::Nil,0>
		{
			virtual ~AgileActivationFactory<Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Details::Nil,0>();
		};

		struct AgileActivationFactory<Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Details::Nil,0>
		{
			virtual ~AgileActivationFactory<Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Details::Nil,0>();
		};

		struct AgileActivationFactory<Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Details::Nil,0>
		{
			virtual ~AgileActivationFactory<Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Details::Nil,0>();
		};

		struct AgileActivationFactory<Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Details::Nil,0>
		{
			virtual ~AgileActivationFactory<Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Details::Nil,0>();
		};

		struct AgileActivationFactory<Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics,Details::Nil,Details::Nil,0>
		{
			virtual ~AgileActivationFactory<Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics,Details::Nil,Details::Nil,0>();
		};

		class ComPtr<CDecryptCredentialOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<CDecryptCredentialOperation>();
		};

		struct ComPtr<Details::WeakReferenceImpl>
		{
			~ComPtr<Details::WeakReferenceImpl>();
		};

		class ComPtr<IAgileObject>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IAgileObject>();
		};

		class ComPtr<IApplicationResolver>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<IAsyncInfo>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			long As<Windows::Foundation::IAsyncAction>(Details::ComPtrRef<ComPtr<Windows::Foundation::IAsyncAction> >);
			~ComPtr<IAsyncInfo>();
		};

		class ComPtr<ICallingProcessInfo>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<ICoreWindowInterop>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<ICoreWindowInterop>();
		};

		class ComPtr<IGlobalInterfaceTable>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IGlobalInterfaceTable>();
		};

		class ComPtr<IInitializeWithPopupPersonality>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IInitializeWithPopupPersonality>();
		};

		class ComPtr<IInitializeWithWindow>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IInitializeWithWindow>();
		};

		class ComPtr<IMarshal>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IMarshal>();
		};

		class ComPtr<IRestrictedErrorInfo>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IRestrictedErrorInfo>();
		};

		class ComPtr<IUnknown>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IUnknown>();
		};

		class ComPtr<IX509PrivateKey2>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<IX509PrivateKey2>();
		};

		struct ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateExtension,0> >
		{
			~ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateExtension,0> >();
		};

		struct ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateKeyUsages,0> >
		{
			~ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateKeyUsages,0> >();
		};

		struct ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateQuery,0> >
		{
			~ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateQuery,0> >();
		};

		struct ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateRequestProperties,0> >
		{
			~ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateRequestProperties,0> >();
		};

		struct ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CChainBuildingParameters,0> >
		{
			~ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CChainBuildingParameters,0> >();
		};

		struct ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CChainValidationParameters,0> >
		{
			~ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CChainValidationParameters,0> >();
		};

		struct ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCmsSignerInfo,0> >
		{
			~ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCmsSignerInfo,0> >();
		};

		struct ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CPfxImportParameters,0> >
		{
			~ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CPfxImportParameters,0> >();
		};

		struct ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo,0> >
		{
			~ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo,0> >();
		};

		struct ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateEnrollmentManager,0> >
		{
			~ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateEnrollmentManager,0> >();
		};

		struct ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateStore,0> >
		{
			~ComPtr<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateStore,0> >();
		};

		class ComPtr<UserDeviceRegistration::Ngc::INgcRegManagerStatics>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<UserDeviceRegistration::Ngc::INgcRegManagerStatics>();
		};

		class ComPtr<Windows::ApplicationModel::Core::ICoreApplicationPrivate>
		{
		protected:
			unsigned long InternalRelease();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<HSTRING__ *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IIterable<HSTRING__ *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IIterator<HSTRING__ *> >
		{
		protected:
			void InternalAddRef();
		public:
			~ComPtr<Windows::Foundation::Collections::IIterator<HSTRING__ *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *> >();
		};

		struct ComPtr<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *> >
		{
			~ComPtr<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IVector<HSTRING__ *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand *> >();
		};

		class ComPtr<Windows::Foundation::Collections::IVectorView<HSTRING__ *> >
		{
		protected:
			void InternalAddRef();
		public:
			~ComPtr<Windows::Foundation::Collections::IVectorView<HSTRING__ *> >();
		};

		struct ComPtr<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *> >
		{
			~ComPtr<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *> >();
		};

		struct ComPtr<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *> >
		{
			~ComPtr<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *> >();
		};

		struct ComPtr<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >
		{
			~ComPtr<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >();
		};

		struct ComPtr<Windows::Foundation::Collections::Internal::AgileVector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0> >
		{
			~ComPtr<Windows::Foundation::Collections::Internal::AgileVector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::AgileVector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,0> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::AgileVector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,0> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::AgileVector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,0> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::AgileVector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,0> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::AgileVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,0> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::AgileVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,0> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorView<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorView<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorView<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorView<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1> >();
		};

		class ComPtr<Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> > >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> > >();
		};

		struct ComPtr<Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> > >
		{
			~ComPtr<Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> > >();
		};

		struct ComPtr<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> > >
		{
			~ComPtr<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> > >();
		};

		struct ComPtr<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> > >
		{
			~ComPtr<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> > >();
		};

		struct ComPtr<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> > >
		{
			~ComPtr<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> > >();
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
			ComPtr<Windows::Foundation::IAsyncActionCompletedHandler> & operator=(Windows::Foundation::IAsyncActionCompletedHandler *);
			~ComPtr<Windows::Foundation::IAsyncActionCompletedHandler>();
		};

		class ComPtr<Windows::Foundation::IAsyncOperation<HSTRING__ *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperation<HSTRING__ *> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *> *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *> *> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain *> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer *> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand *> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand *> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperation<bool> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperation<bool> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING__ *> >
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING__ *> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *> *> >
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *> *> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<Windows::Security::Cryptography::Certificates::CertificateChain *> >
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<Windows::Security::Cryptography::Certificates::CertificateChain *> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer *> >
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer *> >();
		};

		struct ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<Windows::UI::Popups::IUICommand *> >
		{
			~ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<Windows::UI::Popups::IUICommand *> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<bool> >
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperationCompletedHandler<bool> >();
		};

		class ComPtr<Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer *,unsigned int> >
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer *,unsigned int> >();
		};

		struct ComPtr<Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<Windows::Storage::Streams::IBuffer *,unsigned int> >
		{
			~ComPtr<Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<Windows::Storage::Streams::IBuffer *,unsigned int> >();
		};

		class ComPtr<Windows::Networking::IHostName>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			~ComPtr<Windows::Networking::IHostName>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CAddOrDeleteCertInUserStoreOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CAddOrDeleteCertInUserStoreOperation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CBuildChainDefaultOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CBuildChainDefaultOperation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CBuildChainWithParaOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CBuildChainWithParaOperation>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCertificate>
		{
			long As<Windows::Security::Cryptography::Certificates::ICertificate>(Details::ComPtrRef<ComPtr<Windows::Security::Cryptography::Certificates::ICertificate> >);
			~ComPtr<Windows::Security::Cryptography::Certificates::CCertificate>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCertificateChain>
		{
			long As<Windows::Security::Cryptography::Certificates::ICertificateChain>(Details::ComPtrRef<ComPtr<Windows::Security::Cryptography::Certificates::ICertificateChain> >);
			~ComPtr<Windows::Security::Cryptography::Certificates::CCertificateChain>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCertificateEnrollmentManagerFactory>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CCertificateEnrollmentManagerFactory>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCertificateExtension>
		{
			void Attach(Windows::Security::Cryptography::Certificates::CCertificateExtension *);
			~ComPtr<Windows::Security::Cryptography::Certificates::CCertificateExtension>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCertificateFactory>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CCertificateFactory>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCertificateKeyUsages>
		{
			void Attach(Windows::Security::Cryptography::Certificates::CCertificateKeyUsages *);
			~ComPtr<Windows::Security::Cryptography::Certificates::CCertificateKeyUsages>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCertificateQuery>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CCertificateQuery>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCertificateRequestProperties>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CCertificateRequestProperties>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCertificateStore>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CCertificateStore>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCertificateStoresFactory>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CCertificateStoresFactory>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CChainBuildingParameters>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CChainBuildingParameters>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CChainValidationParameters>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CChainValidationParameters>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCmsAttachedSignature>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CCmsAttachedSignature>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCmsAttachedSignatureFactory>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CCmsAttachedSignatureFactory>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCmsDetachedSignature>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CCmsDetachedSignature>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCmsDetachedSignatureFactory>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CCmsDetachedSignatureFactory>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCmsSignerInfo>
		{
			void Attach(Windows::Security::Cryptography::Certificates::CCmsSignerInfo *);
			~ComPtr<Windows::Security::Cryptography::Certificates::CCmsSignerInfo>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CCmsTimestampInfo>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CCmsTimestampInfo>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CCreateRequest2Operation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CCreateRequest2Operation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CCreateRequestOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CCreateRequestOperation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CFindAllOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CFindAllOperation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CFindAllWithQueryOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CFindAllWithQueryOperation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CImportPfxData2Operation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CImportPfxData2Operation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CImportPfxDataOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CImportPfxDataOperation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CImportPfxDataToKsp2Operation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CImportPfxDataToKsp2Operation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CImportPfxDataToKspOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CImportPfxDataToKspOperation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CInstallCertificate2Operation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CInstallCertificate2Operation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CInstallCertificateOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CInstallCertificateOperation>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CKeyAlgorithmNamesFactory>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CKeyAlgorithmNamesFactory>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CKeyAttestationHelperFactory>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CKeyAttestationHelperFactory>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CKeyStorageProviderNamesFactory>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CKeyStorageProviderNamesFactory>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CPfxImportParameters>
		{
			void Attach(Windows::Security::Cryptography::Certificates::CPfxImportParameters *);
			~ComPtr<Windows::Security::Cryptography::Certificates::CPfxImportParameters>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CSignMessageOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CSignMessageOperation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CSignStreamMessageOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CSignStreamMessageOperation>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CStandardCertificateStoreNamesFactory>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CStandardCertificateStoreNamesFactory>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo>
		{
			void Attach(Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo *);
			~ComPtr<Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CUserCertificateEnrollmentManager>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CUserCertificateEnrollmentManager>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::CUserCertificateStore>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::CUserCertificateStore>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::CVerifyStreamMessageOperation>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::CVerifyStreamMessageOperation>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICertificate>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			ComPtr<Windows::Security::Cryptography::Certificates::ICertificate> & operator=(Windows::Security::Cryptography::Certificates::ICertificate *);
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificate>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICertificateChain>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateChain>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICertificateExtension>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateExtension>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICertificateInternal2>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateInternal2>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICertificateInternal>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateInternal>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICertificateQuery2>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateQuery2>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::ICertificateQuery>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateQuery>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>
		{
			ComPtr<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties> & operator=(Windows::Security::Cryptography::Certificates::ICertificateRequestProperties *);
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICertificateStore>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICertificateStore>();
		};

		struct ComPtr<Windows::Security::Cryptography::Certificates::IChainBuildingParameters>
		{
			~ComPtr<Windows::Security::Cryptography::Certificates::IChainBuildingParameters>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICmsAttachedSignature>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICmsAttachedSignature>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICmsDetachedSignature>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICmsDetachedSignature>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ICmsTimestampInfo>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ICmsTimestampInfo>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::IPfxImportParameters>
		{
		protected:
			void InternalAddRef();
		public:
			ComPtr<Windows::Security::Cryptography::Certificates::IPfxImportParameters> & operator=(Windows::Security::Cryptography::Certificates::IPfxImportParameters *);
			~ComPtr<Windows::Security::Cryptography::Certificates::IPfxImportParameters>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::IUserCertificateStore>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::IUserCertificateStore>();
		};

		class ComPtr<Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal>();
		};

		struct ComPtr<Windows::Storage::Streams::CBuffer<Windows::Storage::Streams::CBuffer_StandardCleanup,Windows::Storage::Streams::DefaultMarshaler> >
		{
			~ComPtr<Windows::Storage::Streams::CBuffer<Windows::Storage::Streams::CBuffer_StandardCleanup,Windows::Storage::Streams::DefaultMarshaler> >();
		};

		struct ComPtr<Windows::Storage::Streams::CBuffer<void (*)(void *),Windows::Storage::Streams::DefaultMarshaler> >
		{
			~ComPtr<Windows::Storage::Streams::CBuffer<void (*)(void *),Windows::Storage::Streams::DefaultMarshaler> >();
		};

		class ComPtr<Windows::Storage::Streams::IBuffer>
		{
		protected:
			unsigned long InternalRelease();
			void InternalAddRef();
		public:
			ComPtr<Windows::Storage::Streams::IBuffer> & operator=(Windows::Storage::Streams::IBuffer *);
			~ComPtr<Windows::Storage::Streams::IBuffer>();
		};

		class ComPtr<Windows::Storage::Streams::IBufferByteAccess>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::Storage::Streams::IBufferByteAccess>();
		};

		struct ComPtr<Windows::Storage::Streams::IInputStream>
		{
			ComPtr<Windows::Storage::Streams::IInputStream> & operator=(Windows::Storage::Streams::IInputStream *);
			~ComPtr<Windows::Storage::Streams::IInputStream>();
		};

		class ComPtr<Windows::UI::Core::ICoreWindow>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::UI::Core::ICoreWindow>();
		};

		class ComPtr<Windows::UI::Core::ICoreWindowStatic>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::UI::Core::ICoreWindowStatic>();
		};

		class ComPtr<Windows::UI::Internal::Popups::IMessageDialogFactoryWithOwnerWindow>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::UI::Internal::Popups::IMessageDialogFactoryWithOwnerWindow>();
		};

		class ComPtr<Windows::UI::Popups::IMessageDialog>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::UI::Popups::IMessageDialog>();
		};

		class ComPtr<Windows::UI::Popups::IUICommand>
		{
		protected:
			unsigned long InternalRelease();
		public:
			~ComPtr<Windows::UI::Popups::IUICommand>();
		};

		struct ComPtr<Windows::UI::Popups::IUICommandInvokedHandler>
		{
			~ComPtr<Windows::UI::Popups::IUICommandInvokedHandler>();
		};

		namespace Details
		{
			struct DefaultModule<1>
			{
				virtual ~DefaultModule<1>();
			};

			class ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,Nil>
			{
			protected:
				long CanCastToHelper<0>(_GUID const &,void * *,bool *);
			public:
				~ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,0,Nil,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil>
			{
				~ImplementsHelper<RuntimeClassFlags<13>,1,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil>();
			};

			struct ImplementsHelper<RuntimeClassFlags<19>,0,Nil,Windows::Storage::Streams::IBuffer,IWeakReferenceSource,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<19>,0,Nil,Windows::Storage::Streams::IBuffer,IWeakReferenceSource,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<19>,0,Windows::Storage::Streams::IBuffer,IWeakReferenceSource,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<19>,0,Windows::Storage::Streams::IBuffer,IWeakReferenceSource,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<19>,1,CloakedIid<IMarshal>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<19>,1,CloakedIid<IMarshal>,FtmBase>();
			};

			class ImplementsHelper<RuntimeClassFlags<19>,1,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>
			{
			protected:
				long CanCastTo(_GUID const &,void * *,bool *);
			public:
				~ImplementsHelper<RuntimeClassFlags<19>,1,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<19>,1,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<19>,1,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<19>,1,IWeakReferenceSource,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<19>,1,IWeakReferenceSource,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IIterator<HSTRING__ *>,IWeakReferenceSource,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IIterator<HSTRING__ *>,IWeakReferenceSource,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVector<HSTRING__ *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVector<HSTRING__ *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificate,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificate,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateChain,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateChain,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateExtension,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateExtension,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateKeyUsages,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateKeyUsages,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateQuery,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateQuery,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateStore,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICertificateStore,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::IChainBuildingParameters,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::IChainBuildingParameters,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::IChainValidationParameters,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::IChainValidationParameters,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICmsAttachedSignature,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICmsAttachedSignature,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICmsDetachedSignature,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICmsDetachedSignature,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICmsSignerInfo,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICmsSignerInfo,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICmsTimestampInfo,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ICmsTimestampInfo,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::IPfxImportParameters,IWeakReferenceSource,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::IPfxImportParameters,IWeakReferenceSource,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::IUserCertificateStore,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Nil,Windows::Security::Cryptography::Certificates::IUserCertificateStore,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IIterator<HSTRING__ *>,IWeakReferenceSource,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IIterator<HSTRING__ *>,IWeakReferenceSource,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificate,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificate,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateChain,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateChain,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateExtension,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateExtension,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateKeyUsages,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateKeyUsages,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateQuery,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateQuery,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateStore,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICertificateStore,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::IChainBuildingParameters,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::IChainBuildingParameters,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::IChainValidationParameters,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::IChainValidationParameters,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICmsAttachedSignature,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICmsAttachedSignature,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICmsDetachedSignature,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICmsDetachedSignature,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICmsSignerInfo,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICmsSignerInfo,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICmsTimestampInfo,IWeakReferenceSource,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ICmsTimestampInfo,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::IPfxImportParameters,IWeakReferenceSource,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::IPfxImportParameters,IWeakReferenceSource,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::IUserCertificateStore,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,0,Windows::Security::Cryptography::Certificates::IUserCertificateStore,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncAction>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncAction>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncOperation<HSTRING__ *> >
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncOperation<HSTRING__ *> >();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *> *> >
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *> *> >();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain *> >
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain *> >();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer *> >
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer *> >();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncOperation<bool> >
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Foundation::IAsyncOperation<bool> >();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase>
			{
				ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase>();
				~ImplementsHelper<RuntimeClassFlags<1>,1,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IInspectable,FtmBase>
			{
				ImplementsHelper<RuntimeClassFlags<1>,1,IInspectable,FtmBase>();
				~ImplementsHelper<RuntimeClassFlags<1>,1,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncAction>
			{
				ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncAction>();
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncAction>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncOperation<HSTRING__ *> >
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncOperation<HSTRING__ *> >();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *> *> >
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *> *> >();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain *> >
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain *> >();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer *> >
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer *> >();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncOperation<bool> >
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase,Windows::Foundation::IAsyncOperation<bool> >();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase>
			{
				ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase>();
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,IInspectable,FtmBase>
			{
				ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,IInspectable,FtmBase>();
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>
			{
				ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>();
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
			{
				ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
			{
				ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
			{
				ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
			};

			class ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>
			{
			protected:
				long CanCastToHelper<0>(_GUID const &,void * *,bool *);
			public:
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>();
			};

			class ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>
			{
			protected:
				long CanCastToHelper<0>(_GUID const &,void * *,bool *);
			public:
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,IWeakReferenceSource,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>();
			};

			struct ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>
			{
				~ImplementsHelper<RuntimeClassFlags<1>,1,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>();
			};

			struct MakeAllocator<CDecryptCredentialOperation>
			{
				~MakeAllocator<CDecryptCredentialOperation>();
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateExtension,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateExtension,0> >();
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateKeyUsages,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateKeyUsages,0> >();
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateQuery,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateQuery,0> >();
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateRequestProperties,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateRequestProperties,0> >();
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CChainBuildingParameters,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CChainBuildingParameters,0> >();
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CChainValidationParameters,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CChainValidationParameters,0> >();
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCmsSignerInfo,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCmsSignerInfo,0> >();
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CPfxImportParameters,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CPfxImportParameters,0> >();
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo,0> >();
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateEnrollmentManager,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateEnrollmentManager,0> >();
			};

			struct MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateStore,0> >
			{
				~MakeAllocator<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateStore,0> >();
			};

			struct MakeAllocator<WeakReferenceImpl>
			{
				~MakeAllocator<WeakReferenceImpl>();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorIterator<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0> >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorIterator<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0> >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorIterator<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1> >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorIterator<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1> >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1> >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1> >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1> >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1> >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1> >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1> >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorView<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0> >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorView<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0> >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorView<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1> >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorView<HSTRING__ *,Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,1> >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1> >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1> >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1> >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1> >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1> >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::SimpleVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1> >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> > >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultVectorOptions<HSTRING__ *> > >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> > >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::Vector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,Windows::Foundation::Collections::Internal::VectorOptions<HSTRING__ *,0,1,0> > >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> > >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::Certificate *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::Certificate *,0,1,0> > >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> > >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CertificateExtension *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CertificateExtension *,0,1,0> > >();
			};

			struct MakeAllocator<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> > >
			{
				~MakeAllocator<Windows::Foundation::Collections::Internal::Vector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::Internal::VectorOptions<Windows::Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> > >();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CAddOrDeleteCertInUserStoreOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CAddOrDeleteCertInUserStoreOperation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CBuildChainDefaultOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CBuildChainDefaultOperation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CBuildChainWithParaOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CBuildChainWithParaOperation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificate>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificate>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateChain>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateChain>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateEnrollmentManagerFactory>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateEnrollmentManagerFactory>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateExtension>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateExtension>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateFactory>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateFactory>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateKeyUsages>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateKeyUsages>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateQuery>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateQuery>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateRequestProperties>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateRequestProperties>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateStore>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateStore>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateStoresFactory>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCertificateStoresFactory>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CChainBuildingParameters>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CChainBuildingParameters>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CChainValidationParameters>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CChainValidationParameters>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsAttachedSignature>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsAttachedSignature>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsAttachedSignatureFactory>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsAttachedSignatureFactory>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsDetachedSignature>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsDetachedSignature>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsDetachedSignatureFactory>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsDetachedSignatureFactory>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsSignerInfo>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsSignerInfo>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsTimestampInfo>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCmsTimestampInfo>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCreateRequest2Operation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCreateRequest2Operation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CCreateRequestOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CCreateRequestOperation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CFindAllOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CFindAllOperation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CFindAllWithQueryOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CFindAllWithQueryOperation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CImportPfxData2Operation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CImportPfxData2Operation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CImportPfxDataOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CImportPfxDataOperation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CImportPfxDataToKsp2Operation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CImportPfxDataToKsp2Operation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CImportPfxDataToKspOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CImportPfxDataToKspOperation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CInstallCertificate2Operation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CInstallCertificate2Operation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CInstallCertificateOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CInstallCertificateOperation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CKeyAlgorithmNamesFactory>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CKeyAlgorithmNamesFactory>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CKeyAttestationHelperFactory>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CKeyAttestationHelperFactory>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CKeyStorageProviderNamesFactory>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CKeyStorageProviderNamesFactory>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CPfxImportParameters>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CPfxImportParameters>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CSignMessageOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CSignMessageOperation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CSignStreamMessageOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CSignStreamMessageOperation>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CStandardCertificateStoreNamesFactory>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CStandardCertificateStoreNamesFactory>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CUserCertificateEnrollmentManager>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CUserCertificateEnrollmentManager>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CUserCertificateStore>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CUserCertificateStore>();
			};

			struct MakeAllocator<Windows::Security::Cryptography::Certificates::CVerifyStreamMessageOperation>
			{
				~MakeAllocator<Windows::Security::Cryptography::Certificates::CVerifyStreamMessageOperation>();
			};

			struct MakeAllocator<Windows::Storage::Streams::CBuffer<Windows::Storage::Streams::CBuffer_StandardCleanup,Windows::Storage::Streams::DefaultMarshaler> >
			{
				~MakeAllocator<Windows::Storage::Streams::CBuffer<Windows::Storage::Streams::CBuffer_StandardCleanup,Windows::Storage::Streams::DefaultMarshaler> >();
			};

			struct MakeAllocator<Windows::Storage::Streams::CBuffer<void (*)(void *),Windows::Storage::Streams::DefaultMarshaler> >
			{
				~MakeAllocator<Windows::Storage::Streams::CBuffer<void (*)(void *),Windows::Storage::Streams::DefaultMarshaler> >();
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
				virtual ~ModuleBase();
			};

			struct RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,Nil>,RuntimeClassFlags<13>,0,1,0>
			{
				virtual ~RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,Nil>,RuntimeClassFlags<13>,0,1,0>();
			};

			struct RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>
			{
				virtual ~RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>();
			};

			struct RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>
			{
				virtual ~RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>();
			};

			struct RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>
			{
				virtual ~RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>();
			};

			struct RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>
			{
				virtual ~RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>();
			};

			struct RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>
			{
				virtual ~RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>();
			};

			struct RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>
			{
				virtual ~RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>();
			};

			struct RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>
			{
				virtual ~RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>();
			};

			struct RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>
			{
				virtual ~RuntimeClass<InterfaceListHelper<IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>();
			};

			struct RuntimeClass<InterfaceListHelper<IActivationFactory,Nil,Nil,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>
			{
				virtual ~RuntimeClass<InterfaceListHelper<IActivationFactory,Nil,Nil,Nil,Nil>,RuntimeClassFlags<13>,0,1,0>();
			};

			class RuntimeClassBaseT<13>
			{
			protected:
				static long AsIID<ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,0> >(ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,0> *,_GUID const &,void * *);
				static long AsIID<ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,0> >(ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,0> *,_GUID const &,void * *);
				static long AsIID<ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,0> >(ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,0> *,_GUID const &,void * *);
				static long AsIID<ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,0> >(ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,0> *,_GUID const &,void * *);
				static long AsIID<ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,0> >(ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,0> *,_GUID const &,void * *);
				static long AsIID<ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,0> >(ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,0> *,_GUID const &,void * *);
				static long AsIID<ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,0> >(ActivationFactory<Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,0> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil> >(RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil> >(RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil> >(RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil> >(RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil> >(RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil> >(RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil> >(RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil> >(RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil> *,_GUID const &,void * *);
			};

			class RuntimeClassBaseT<19>
			{
			protected:
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<19>,1,1,0,Windows::Storage::Streams::IBuffer,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<19>,1,1,0,Windows::Storage::Streams::IBuffer,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase> *,_GUID const &,void * *);
			};

			class RuntimeClassBaseT<1>
			{
			protected:
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<HSTRING__ *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<HSTRING__ *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<HSTRING__ *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<HSTRING__ *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> > >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> > *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateChain,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateChain,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateExtension,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateExtension,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateKeyUsages,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateKeyUsages,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateQuery,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateQuery,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateStore,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateStore,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IChainBuildingParameters,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IChainBuildingParameters,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IChainValidationParameters,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IChainValidationParameters,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsAttachedSignature,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsAttachedSignature,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsDetachedSignature,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsDetachedSignature,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsSignerInfo,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsSignerInfo,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsTimestampInfo,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsTimestampInfo,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IPfxImportParameters,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IPfxImportParameters,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long AsIID<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IUserCertificateStore,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IUserCertificateStore,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase> *,_GUID const &,void * *);
				static long GetImplementedIIDS<RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificate,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase> >(RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificate,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase> *,unsigned long *,_GUID * *);
			};

			class RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,Nil>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3,Nil>();
			public:
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>,Nil,Nil,Nil>();
			public:
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2,Nil,Nil>();
			public:
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics,Nil,Nil>();
			public:
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics,Nil,Nil>();
			public:
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2,Nil,Nil>();
			public:
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2,Nil,Nil>();
			public:
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2,Nil,Nil>();
			public:
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>,Nil,Nil,Nil>();
			public:
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Nil,Nil,Nil,Nil>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<13>,0,1,0,IActivationFactory,Nil,Nil,Nil,Nil>();
			public:
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<19>,1,1,0,Windows::Storage::Streams::IBuffer,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<19>,1,1,0,Windows::Storage::Streams::IBuffer,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<HSTRING__ *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<HSTRING__ *> >();
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

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> >();
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

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> >
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> >();
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

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificate,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificate,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateChain,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateChain,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateExtension,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateExtension,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateKeyUsages,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateKeyUsages,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateQuery,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateQuery,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateStore,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICertificateStore,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IChainBuildingParameters,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IChainBuildingParameters,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IChainValidationParameters,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IChainValidationParameters,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsAttachedSignature,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsAttachedSignature,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsDetachedSignature,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsDetachedSignature,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsSignerInfo,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsSignerInfo,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsTimestampInfo,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ICmsTimestampInfo,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IPfxImportParameters,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IPfxImportParameters,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>();
			};

			struct RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IUserCertificateStore,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>
			{
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long GetWeakReference(IWeakReference * *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
				virtual ~RuntimeClassImpl<RuntimeClassFlags<1>,1,1,0,Windows::Security::Cryptography::Certificates::IUserCertificateStore,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>();
			};

			class RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IWeakReference>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,IWeakReference>();
			public:
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,Windows::Foundation::IAsyncOperationCompletedHandler<Windows::UI::Popups::IUICommand *> >
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,Windows::Foundation::IAsyncOperationCompletedHandler<Windows::UI::Popups::IUICommand *> >();
			public:
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<Windows::Storage::Streams::IBuffer *,unsigned int> >
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<Windows::Storage::Streams::IBuffer *,unsigned int> >();
			public:
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,Windows::UI::Popups::IUICommandInvokedHandler>
			{
			protected:
				virtual ~RuntimeClassImpl<RuntimeClassFlags<2>,1,0,0,Windows::UI::Popups::IUICommandInvokedHandler>();
			public:
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct StrongReference
			{
				~StrongReference();
			};

			struct WeakReferenceImpl
			{
				WeakReferenceImpl(IUnknown *);
				virtual long Resolve(_GUID const &,IInspectable * *);
			};

			ComPtr<Details::WeakReferenceImpl> Make<WeakReferenceImpl,IUnknown * &>(IUnknown * &);
			ComPtr<Windows::Storage::Streams::CBuffer<Windows::Storage::Streams::CBuffer_StandardCleanup,Windows::Storage::Streams::DefaultMarshaler> > Make<Windows::Storage::Streams::CBuffer<Windows::Storage::Streams::CBuffer_StandardCleanup,Windows::Storage::Streams::DefaultMarshaler>,unsigned int &,unsigned int &,unsigned char * &,Windows::Storage::Streams::CBuffer_StandardCleanup &>(unsigned int &,unsigned int &,unsigned char * &,Windows::Storage::Streams::CBuffer_StandardCleanup &);
			ComPtr<Windows::Storage::Streams::CBuffer<void (*)(void *),Windows::Storage::Streams::DefaultMarshaler> > Make<Windows::Storage::Streams::CBuffer<void (*)(void *),Windows::Storage::Streams::DefaultMarshaler>,unsigned int &,unsigned int &,unsigned char * &,void (*&)(void *)>(unsigned int &,unsigned int &,unsigned char * &,void (*&)(void *));
			Details::WeakReferenceImpl * CreateWeakReference(IUnknown *);
			bool TerminateMap(Details::ModuleBase *,unsigned short const *,bool);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateExtension,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateKeyUsages,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateQuery,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateRequestProperties,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CChainBuildingParameters,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CChainValidationParameters,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CCmsSignerInfo,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CPfxImportParameters,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateEnrollmentManager,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<SimpleSealedActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateStore,0> >(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateEnrollmentManagerFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateStoresFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Cryptography::Certificates::CCmsAttachedSignatureFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Cryptography::Certificates::CCmsDetachedSignatureFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Cryptography::Certificates::CKeyAlgorithmNamesFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Cryptography::Certificates::CKeyAttestationHelperFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Cryptography::Certificates::CKeyStorageProviderNamesFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long CreateActivationFactory<Windows::Security::Cryptography::Certificates::CStandardCertificateStoreNamesFactory>(unsigned int *,Details::CreatorMap const *,_GUID const &,IUnknown * *);
			long GetActivationFactory<1>(Details::ModuleBase *,unsigned short const *,HSTRING__ *,IActivationFactory * *);
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
			~FtmBase();
		};

		struct Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>
		{
			~Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>();
		};

		struct Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>
		{
			~Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateFactory>();
		};

		struct Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>
		{
			~Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>();
		};

		struct Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>
		{
			~Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>();
		};

		struct Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>
		{
			~Implements<FtmBase,Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>();
		};

		struct Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>
		{
			~Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>();
		};

		struct Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>
		{
			~Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>();
		};

		struct Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>
		{
			~Implements<FtmBase,Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>();
		};

		struct Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>
		{
			~Implements<FtmBase,Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>();
		};

		class Module<1,Details::DefaultModule<1> >
		{
			static bool StaticInitialize();
			static bool isInitialized;
		public:
			virtual long RegisterCOMObject(unsigned short const *,_GUID *,IClassFactory * *,unsigned long *,unsigned int);
			virtual long RegisterWinRTObject(unsigned short const *,unsigned short const * *,<unnamed-type-RO_REGISTRATION_COOKIE> * *,unsigned int);
			virtual long UnregisterCOMObject(unsigned short const *,unsigned long *,unsigned int);
			virtual long UnregisterWinRTObject(unsigned short const *,<unnamed-type-RO_REGISTRATION_COOKIE> *);
			virtual unsigned long DecrementObjectCount();
			virtual unsigned long IncrementObjectCount();
			virtual ~Module<1,Details::DefaultModule<1> >();
		};

		struct RuntimeClass<RuntimeClassFlags<19>,Windows::Storage::Streams::IBuffer,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>
		{
			RuntimeClass<RuntimeClassFlags<19>,Windows::Storage::Streams::IBuffer,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>();
			virtual ~RuntimeClass<RuntimeClassFlags<19>,Windows::Storage::Streams::IBuffer,CloakedIid<Windows::Storage::Streams::IBufferByteAccess>,CloakedIid<IMarshal>,FtmBase>();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,IWeakReference>
		{
			virtual ~RuntimeClass<RuntimeClassFlags<2>,IWeakReference>();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,Windows::Foundation::IAsyncOperationCompletedHandler<Windows::UI::Popups::IUICommand *> >
		{
			virtual ~RuntimeClass<RuntimeClassFlags<2>,Windows::Foundation::IAsyncOperationCompletedHandler<Windows::UI::Popups::IUICommand *> >();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<Windows::Storage::Streams::IBuffer *,unsigned int> >
		{
			virtual ~RuntimeClass<RuntimeClassFlags<2>,Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<Windows::Storage::Streams::IBuffer *,unsigned int> >();
		};

		struct RuntimeClass<RuntimeClassFlags<2>,Windows::UI::Popups::IUICommandInvokedHandler>
		{
			RuntimeClass<RuntimeClassFlags<2>,Windows::UI::Popups::IUICommandInvokedHandler>();
			virtual ~RuntimeClass<RuntimeClassFlags<2>,Windows::UI::Popups::IUICommandInvokedHandler>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<HSTRING__ *> >
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IIterator<HSTRING__ *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<HSTRING__ *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IIterator<HSTRING__ *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IIterator<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> >
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IVector<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> >
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *> >();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IVectorView<HSTRING__ *>,Windows::Foundation::Collections::IIterable<HSTRING__ *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CertificateExtension *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CertificateExtension *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo *>,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificate,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>
		{
			RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificate,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>();
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificate,Windows::Security::Cryptography::Certificates::ICertificate2,Windows::Security::Cryptography::Certificates::ICertificate3,Windows::Security::Cryptography::Certificates::ICertificateInternal,Windows::Security::Cryptography::Certificates::ICertificateInternal2,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateChain,IInspectable,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateChain,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateExtension,IInspectable,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateExtension,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateKeyUsages,IInspectable,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateKeyUsages,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateQuery,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>
		{
			RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateQuery,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>();
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateQuery,Windows::Security::Cryptography::Certificates::ICertificateQuery2,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>
		{
			RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>();
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3,Windows::Security::Cryptography::Certificates::ICertificateRequestProperties4,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateStore,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>
		{
			RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateStore,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>();
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ICertificateStore,Windows::Security::Cryptography::Certificates::ICertificateStore2,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::IChainBuildingParameters,IInspectable,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::IChainBuildingParameters,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::IChainValidationParameters,IInspectable,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::IChainValidationParameters,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ICmsAttachedSignature,IInspectable,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ICmsAttachedSignature,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ICmsDetachedSignature,IInspectable,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ICmsDetachedSignature,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ICmsSignerInfo,IInspectable,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ICmsSignerInfo,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ICmsTimestampInfo,IInspectable,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ICmsTimestampInfo,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::IPfxImportParameters,FtmBase>
		{
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::IPfxImportParameters,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>
		{
			RuntimeClass<Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>();
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo,Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo2,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>
		{
			RuntimeClass<Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>();
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2,IInspectable,FtmBase>();
		};

		struct RuntimeClass<Windows::Security::Cryptography::Certificates::IUserCertificateStore,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>
		{
			RuntimeClass<Windows::Security::Cryptography::Certificates::IUserCertificateStore,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>();
			virtual ~RuntimeClass<Windows::Security::Cryptography::Certificates::IUserCertificateStore,Windows::Security::Cryptography::Certificates::IUserCertificateStoreInternal,IInspectable,FtmBase>();
		};

		struct SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateExtension,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual ~SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateExtension,0>();
		};

		struct SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateKeyUsages,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual ~SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateKeyUsages,0>();
		};

		struct SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateQuery,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual ~SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateQuery,0>();
		};

		struct SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateRequestProperties,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual ~SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CCertificateRequestProperties,0>();
		};

		struct SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CChainBuildingParameters,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual ~SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CChainBuildingParameters,0>();
		};

		struct SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CChainValidationParameters,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual ~SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CChainValidationParameters,0>();
		};

		struct SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CCmsSignerInfo,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual ~SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CCmsSignerInfo,0>();
		};

		struct SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CPfxImportParameters,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual ~SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CPfxImportParameters,0>();
		};

		struct SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual ~SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CSubjectAlternativeNameInfo,0>();
		};

		struct SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateEnrollmentManager,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual ~SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateEnrollmentManager,0>();
		};

		struct SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateStore,0>
		{
			virtual long ActivateInstance(IInspectable * *);
			virtual ~SimpleActivationFactory<Windows::Security::Cryptography::Certificates::CUserCertificateStore,0>();
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

			class HStringReference
			{
				void CreateReference(unsigned short const *,unsigned int,unsigned int);
			public:
				HStringReference<unsigned short const *>(unsigned short const * const &,Details::Dummy);
				~HStringReference();
			};

			struct SRWLock
			{
				Details::SyncLockExclusive LockExclusive();
				static Details::SyncLockExclusive LockExclusive(_RTL_SRWLOCK *);
				static Details::SyncLockShared LockShared(_RTL_SRWLOCK *);
				~SRWLock();
			};

		};

		Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics * gCausality;
		_RTL_RUN_ONCE gCausalityInitOnce;
	};

};

class NgcStatusStorage
{
	static unsigned long ReadKey(HKEY__ *,unsigned short const *,_GUID,STRUCT_NGC_REG_KEY *);
public:
	STRUCT_NGC_REG_KEY GetKey();
	long Load();
	long Load(HKEY__ *,unsigned short const *);
	static int IsKeyIdEmpty(_GUID const *);
	void Cleanup();
};

class RegistrationCertStatus
{
	static long GetCertificate(_CERTFICATE_LOCATION,char const *,unsigned short const *,INFO_KIND,_CERT_CONTEXT const * *);
public:
	static long GetDeviceCertificate(INFO_KIND,_CERT_CONTEXT const * *);
	static long GetDeviceId(_CERT_CONTEXT const *,unsigned short * *);
	static long GetTenantId(_CERT_CONTEXT const *,unsigned short * *);
	static long GetWorkplaceCertificate(INFO_KIND,_CERT_CONTEXT const * *);
};

struct SP<unsigned char,SP_HLOCAL<unsigned char> >
{
	void Attach(unsigned char *);
	void Reset();
};

class StructuredException
{
	void copyExceptionPointers(_EXCEPTION_POINTERS const *);
public:
	StructuredException(StructuredException const &);
	~StructuredException();
};

namespace WARBIRD
{
	WARBIRD::_MODULE_INFO * g_arModuleInfo;
};

struct WebServiceEndPointResult
{
	~WebServiceEndPointResult();
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
				long _IteratorGetMany<IIterator_impl<Internal::AggregateType<Security::Cryptography::Certificates::Certificate *,Security::Cryptography::Certificates::ICertificate *>,1>,Security::Cryptography::Certificates::ICertificate *>(IIterator_impl<Internal::AggregateType<Security::Cryptography::Certificates::Certificate *,Security::Cryptography::Certificates::ICertificate *>,1> *,unsigned int,Security::Cryptography::Certificates::ICertificate * *,unsigned int *);
				long _IteratorGetMany<IIterator_impl<Internal::AggregateType<Security::Cryptography::Certificates::CertificateExtension *,Security::Cryptography::Certificates::ICertificateExtension *>,1>,Security::Cryptography::Certificates::ICertificateExtension *>(IIterator_impl<Internal::AggregateType<Security::Cryptography::Certificates::CertificateExtension *,Security::Cryptography::Certificates::ICertificateExtension *>,1> *,unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *,unsigned int *);
				long _IteratorGetMany<IIterator_impl<Internal::AggregateType<Security::Cryptography::Certificates::CmsSignerInfo *,Security::Cryptography::Certificates::ICmsSignerInfo *>,1>,Security::Cryptography::Certificates::ICmsSignerInfo *>(IIterator_impl<Internal::AggregateType<Security::Cryptography::Certificates::CmsSignerInfo *,Security::Cryptography::Certificates::ICmsSignerInfo *>,1> *,unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *,unsigned int *);
				long _VectorGetMany<IVectorView_impl<HSTRING__ *,1>,HSTRING__ *>(IVectorView_impl<HSTRING__ *,1> *,unsigned int,unsigned int,HSTRING__ * *,unsigned int *);
				long _VectorGetMany<IVectorView_impl<Internal::AggregateType<Security::Cryptography::Certificates::Certificate *,Security::Cryptography::Certificates::ICertificate *>,1>,Security::Cryptography::Certificates::ICertificate *>(IVectorView_impl<Internal::AggregateType<Security::Cryptography::Certificates::Certificate *,Security::Cryptography::Certificates::ICertificate *>,1> *,unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificate * *,unsigned int *);
				long _VectorGetMany<IVectorView_impl<Internal::AggregateType<Security::Cryptography::Certificates::CertificateExtension *,Security::Cryptography::Certificates::ICertificateExtension *>,1>,Security::Cryptography::Certificates::ICertificateExtension *>(IVectorView_impl<Internal::AggregateType<Security::Cryptography::Certificates::CertificateExtension *,Security::Cryptography::Certificates::ICertificateExtension *>,1> *,unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *,unsigned int *);
				long _VectorGetMany<IVectorView_impl<Internal::AggregateType<Security::Cryptography::Certificates::CmsSignerInfo *,Security::Cryptography::Certificates::ICmsSignerInfo *>,1>,Security::Cryptography::Certificates::ICmsSignerInfo *>(IVectorView_impl<Internal::AggregateType<Security::Cryptography::Certificates::CmsSignerInfo *,Security::Cryptography::Certificates::ICmsSignerInfo *>,1> *,unsigned int,unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *,unsigned int *);
				long _VectorGetMany<IVector_impl<HSTRING__ *,1>,HSTRING__ *>(IVector_impl<HSTRING__ *,1> *,unsigned int,unsigned int,HSTRING__ * *,unsigned int *);
				long _VectorGetMany<IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::Certificate *,Security::Cryptography::Certificates::ICertificate *>,1>,Security::Cryptography::Certificates::ICertificate *>(IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::Certificate *,Security::Cryptography::Certificates::ICertificate *>,1> *,unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificate * *,unsigned int *);
				long _VectorGetMany<IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::CertificateExtension *,Security::Cryptography::Certificates::ICertificateExtension *>,1>,Security::Cryptography::Certificates::ICertificateExtension *>(IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::CertificateExtension *,Security::Cryptography::Certificates::ICertificateExtension *>,1> *,unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *,unsigned int *);
				long _VectorGetMany<IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::CmsSignerInfo *,Security::Cryptography::Certificates::ICmsSignerInfo *>,1>,Security::Cryptography::Certificates::ICmsSignerInfo *>(IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::CmsSignerInfo *,Security::Cryptography::Certificates::ICmsSignerInfo *>,1> *,unsigned int,unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *,unsigned int *);
				long _VectorReplaceAll<IVector_impl<HSTRING__ *,1>,HSTRING__ *>(IVector_impl<HSTRING__ *,1> *,unsigned int,HSTRING__ * *);
				long _VectorReplaceAll<IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::Certificate *,Security::Cryptography::Certificates::ICertificate *>,1>,Security::Cryptography::Certificates::ICertificate *>(IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::Certificate *,Security::Cryptography::Certificates::ICertificate *>,1> *,unsigned int,Security::Cryptography::Certificates::ICertificate * *);
				long _VectorReplaceAll<IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::CertificateExtension *,Security::Cryptography::Certificates::ICertificateExtension *>,1>,Security::Cryptography::Certificates::ICertificateExtension *>(IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::CertificateExtension *,Security::Cryptography::Certificates::ICertificateExtension *>,1> *,unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *);
				long _VectorReplaceAll<IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::CmsSignerInfo *,Security::Cryptography::Certificates::ICmsSignerInfo *>,1>,Security::Cryptography::Certificates::ICmsSignerInfo *>(IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::CmsSignerInfo *,Security::Cryptography::Certificates::ICmsSignerInfo *>,1> *,unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *);
				void _Cleanup<Security::Cryptography::Certificates::ICertificate,unsigned int>(Security::Cryptography::Certificates::ICertificate * * const,unsigned int);
				void _Cleanup<Security::Cryptography::Certificates::ICertificateExtension,unsigned int>(Security::Cryptography::Certificates::ICertificateExtension * * const,unsigned int);
				void _Cleanup<Security::Cryptography::Certificates::ICmsSignerInfo,unsigned int>(Security::Cryptography::Certificates::ICmsSignerInfo * * const,unsigned int);
				void _Cleanup<unsigned int>(HSTRING__ * *,unsigned int);
			};

			struct IIterator_impl<HSTRING__ *,1>
			{
				virtual long GetMany(unsigned int,HSTRING__ * *,unsigned int *);
			};

			struct IIterator_impl<Internal::AggregateType<Security::Cryptography::Certificates::Certificate *,Security::Cryptography::Certificates::ICertificate *>,1>
			{
				virtual long GetMany(unsigned int,Security::Cryptography::Certificates::ICertificate * *,unsigned int *);
			};

			struct IIterator_impl<Internal::AggregateType<Security::Cryptography::Certificates::CertificateExtension *,Security::Cryptography::Certificates::ICertificateExtension *>,1>
			{
				virtual long GetMany(unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *,unsigned int *);
			};

			struct IIterator_impl<Internal::AggregateType<Security::Cryptography::Certificates::CmsSignerInfo *,Security::Cryptography::Certificates::ICmsSignerInfo *>,1>
			{
				virtual long GetMany(unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *,unsigned int *);
			};

			struct IVectorView_impl<HSTRING__ *,1>
			{
				virtual long GetMany(unsigned int,unsigned int,HSTRING__ * *,unsigned int *);
			};

			struct IVectorView_impl<Internal::AggregateType<Security::Cryptography::Certificates::Certificate *,Security::Cryptography::Certificates::ICertificate *>,1>
			{
				virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificate * *,unsigned int *);
			};

			struct IVectorView_impl<Internal::AggregateType<Security::Cryptography::Certificates::CertificateExtension *,Security::Cryptography::Certificates::ICertificateExtension *>,1>
			{
				virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *,unsigned int *);
			};

			struct IVectorView_impl<Internal::AggregateType<Security::Cryptography::Certificates::CmsSignerInfo *,Security::Cryptography::Certificates::ICmsSignerInfo *>,1>
			{
				virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *,unsigned int *);
			};

			struct IVector_impl<HSTRING__ *,1>
			{
				virtual long GetMany(unsigned int,unsigned int,HSTRING__ * *,unsigned int *);
				virtual long ReplaceAll(unsigned int,HSTRING__ * *);
			};

			struct IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::Certificate *,Security::Cryptography::Certificates::ICertificate *>,1>
			{
				virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificate * *,unsigned int *);
				virtual long ReplaceAll(unsigned int,Security::Cryptography::Certificates::ICertificate * *);
			};

			struct IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::CertificateExtension *,Security::Cryptography::Certificates::ICertificateExtension *>,1>
			{
				virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *,unsigned int *);
				virtual long ReplaceAll(unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *);
			};

			struct IVector_impl<Internal::AggregateType<Security::Cryptography::Certificates::CmsSignerInfo *,Security::Cryptography::Certificates::ICmsSignerInfo *>,1>
			{
				virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *,unsigned int *);
				virtual long ReplaceAll(unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *);
			};

			namespace Internal
			{
				struct SimpleVectorIterator<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0>
				{
					SimpleVectorIterator<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0>(Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> > *,SimpleVectorIterator<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0>::permission);
					static long Make(Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> > *,SimpleVectorIterator<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0> * *);
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

				struct SimpleVectorIterator<Security::Cryptography::Certificates::Certificate *,Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1>
				{
					SimpleVectorIterator<Security::Cryptography::Certificates::Certificate *,Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1>(Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> > *,SimpleVectorIterator<Security::Cryptography::Certificates::Certificate *,Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1>::permission);
					static long Make(Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> > *,SimpleVectorIterator<Security::Cryptography::Certificates::Certificate *,Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,Security::Cryptography::Certificates::ICertificate * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long MoveNext(unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Current(Security::Cryptography::Certificates::ICertificate * *);
					virtual long get_HasCurrent(unsigned char *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct SimpleVectorIterator<Security::Cryptography::Certificates::CertificateExtension *,Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1>
				{
					SimpleVectorIterator<Security::Cryptography::Certificates::CertificateExtension *,Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1>(Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> > *,SimpleVectorIterator<Security::Cryptography::Certificates::CertificateExtension *,Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1>::permission);
					static long Make(Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> > *,SimpleVectorIterator<Security::Cryptography::Certificates::CertificateExtension *,Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long MoveNext(unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Current(Security::Cryptography::Certificates::ICertificateExtension * *);
					virtual long get_HasCurrent(unsigned char *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct SimpleVectorIterator<Security::Cryptography::Certificates::CmsSignerInfo *,Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1>
				{
					SimpleVectorIterator<Security::Cryptography::Certificates::CmsSignerInfo *,Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1>(Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> > *,SimpleVectorIterator<Security::Cryptography::Certificates::CmsSignerInfo *,Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1>::permission);
					static long Make(Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> > *,SimpleVectorIterator<Security::Cryptography::Certificates::CmsSignerInfo *,Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long MoveNext(unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Current(Security::Cryptography::Certificates::ICmsSignerInfo * *);
					virtual long get_HasCurrent(unsigned char *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct SimpleVectorView<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0>
				{
					SimpleVectorView<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0>(Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> > *,SimpleVectorView<HSTRING__ *,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> >,DefaultLifetimeTraits<HSTRING__ *>,XWinRT::IntVersionTag,0>::permission);
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

				struct SimpleVectorView<Security::Cryptography::Certificates::Certificate *,Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1>
				{
					SimpleVectorView<Security::Cryptography::Certificates::Certificate *,Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1>(Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> > *,SimpleVectorView<Security::Cryptography::Certificates::Certificate *,Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,XWinRT::IntVersionTag,1>::permission);
					virtual long First(IIterator<Security::Cryptography::Certificates::Certificate *> * *);
					virtual long GetAt(unsigned int,Security::Cryptography::Certificates::ICertificate * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificate * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long IndexOf(Security::Cryptography::Certificates::ICertificate *,unsigned int *,unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct SimpleVectorView<Security::Cryptography::Certificates::CertificateExtension *,Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1>
				{
					SimpleVectorView<Security::Cryptography::Certificates::CertificateExtension *,Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1>(Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> > *,SimpleVectorView<Security::Cryptography::Certificates::CertificateExtension *,Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,XWinRT::IntVersionTag,1>::permission);
					virtual long First(IIterator<Security::Cryptography::Certificates::CertificateExtension *> * *);
					virtual long GetAt(unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long IndexOf(Security::Cryptography::Certificates::ICertificateExtension *,unsigned int *,unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct SimpleVectorView<Security::Cryptography::Certificates::CmsSignerInfo *,Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1>
				{
					SimpleVectorView<Security::Cryptography::Certificates::CmsSignerInfo *,Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1>(Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> > *,SimpleVectorView<Security::Cryptography::Certificates::CmsSignerInfo *,Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,XWinRT::IntVersionTag,1>::permission);
					virtual long First(IIterator<Security::Cryptography::Certificates::CmsSignerInfo *> * *);
					virtual long GetAt(unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long IndexOf(Security::Cryptography::Certificates::ICmsSignerInfo *,unsigned int *,unsigned char *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> >
				{
					long IndexOfInternal(HSTRING__ * *,unsigned int,HSTRING__ *,unsigned int *,unsigned char *);
					long InsertAtInternal(unsigned int,HSTRING__ *,bool);
					long RemoveAtInternal(unsigned int,bool);
					long ResizeStorage(unsigned int);
					static void _Free(HSTRING__ * *,unsigned int);
					void _EraseAll(HSTRING__ * * *,unsigned int *);
				public:
					Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> >(DefaultEqualityPredicate<HSTRING__ *> const &,Vector<HSTRING__ *,DefaultEqualityPredicate<HSTRING__ *>,DefaultLifetimeTraits<HSTRING__ *>,DefaultVectorOptions<HSTRING__ *> >::permission);
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

				class Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> >
				{
					long IndexOfInternal(XWinRT::detail::GitStorageType<Security::Cryptography::Certificates::ICertificate> *,unsigned int,Security::Cryptography::Certificates::ICertificate *,unsigned int *,unsigned char *);
					long InsertAtInternal(unsigned int,Security::Cryptography::Certificates::ICertificate *,bool);
					long RemoveAtInternal(unsigned int,bool);
					long ResizeStorage(unsigned int);
					static void _Free(XWinRT::detail::GitStorageType<Security::Cryptography::Certificates::ICertificate> *,unsigned int);
					void _EraseAll(XWinRT::detail::GitStorageType<Security::Cryptography::Certificates::ICertificate> * *,unsigned int *);
				public:
					Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> >(DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *> const &,Vector<Security::Cryptography::Certificates::Certificate *,DefaultEqualityPredicate<Security::Cryptography::Certificates::Certificate *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::Certificate *>,VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0> >::permission);
					virtual long Append(Security::Cryptography::Certificates::ICertificate *);
					virtual long Clear();
					virtual long First(IIterator<Security::Cryptography::Certificates::Certificate *> * *);
					virtual long GetAt(unsigned int,Security::Cryptography::Certificates::ICertificate * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificate * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IVectorView<Security::Cryptography::Certificates::Certificate *> * *);
					virtual long IndexOf(Security::Cryptography::Certificates::ICertificate *,unsigned int *,unsigned char *);
					virtual long InsertAt(unsigned int,Security::Cryptography::Certificates::ICertificate *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long RemoveAt(unsigned int);
					virtual long RemoveAtEnd();
					virtual long ReplaceAll(unsigned int,Security::Cryptography::Certificates::ICertificate * *);
					virtual long SetAt(unsigned int,Security::Cryptography::Certificates::ICertificate *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >
				{
					long IndexOfInternal(XWinRT::detail::GitStorageType<Security::Cryptography::Certificates::ICertificateExtension> *,unsigned int,Security::Cryptography::Certificates::ICertificateExtension *,unsigned int *,unsigned char *);
					long InsertAtInternal(unsigned int,Security::Cryptography::Certificates::ICertificateExtension *,bool);
					long RemoveAtInternal(unsigned int,bool);
					long ResizeStorage(unsigned int);
					static void _Free(XWinRT::detail::GitStorageType<Security::Cryptography::Certificates::ICertificateExtension> *,unsigned int);
					void _EraseAll(XWinRT::detail::GitStorageType<Security::Cryptography::Certificates::ICertificateExtension> * *,unsigned int *);
				public:
					Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >(DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *> const &,Vector<Security::Cryptography::Certificates::CertificateExtension *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CertificateExtension *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CertificateExtension *>,VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0> >::permission);
					virtual long Append(Security::Cryptography::Certificates::ICertificateExtension *);
					virtual long Clear();
					virtual long First(IIterator<Security::Cryptography::Certificates::CertificateExtension *> * *);
					virtual long GetAt(unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IVectorView<Security::Cryptography::Certificates::CertificateExtension *> * *);
					virtual long IndexOf(Security::Cryptography::Certificates::ICertificateExtension *,unsigned int *,unsigned char *);
					virtual long InsertAt(unsigned int,Security::Cryptography::Certificates::ICertificateExtension *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long RemoveAt(unsigned int);
					virtual long RemoveAtEnd();
					virtual long ReplaceAll(unsigned int,Security::Cryptography::Certificates::ICertificateExtension * *);
					virtual long SetAt(unsigned int,Security::Cryptography::Certificates::ICertificateExtension *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >
				{
					long IndexOfInternal(XWinRT::detail::GitStorageType<Security::Cryptography::Certificates::ICmsSignerInfo> *,unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo *,unsigned int *,unsigned char *);
					long InsertAtInternal(unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo *,bool);
					long RemoveAtInternal(unsigned int,bool);
					long ResizeStorage(unsigned int);
					static void _Free(XWinRT::detail::GitStorageType<Security::Cryptography::Certificates::ICmsSignerInfo> *,unsigned int);
					void _EraseAll(XWinRT::detail::GitStorageType<Security::Cryptography::Certificates::ICmsSignerInfo> * *,unsigned int *);
				public:
					Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >(DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *> const &,Vector<Security::Cryptography::Certificates::CmsSignerInfo *,DefaultEqualityPredicate<Security::Cryptography::Certificates::CmsSignerInfo *>,DefaultLifetimeTraits<Security::Cryptography::Certificates::CmsSignerInfo *>,VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0> >::permission);
					virtual long Append(Security::Cryptography::Certificates::ICmsSignerInfo *);
					virtual long Clear();
					virtual long First(IIterator<Security::Cryptography::Certificates::CmsSignerInfo *> * *);
					virtual long GetAt(unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetMany(unsigned int,unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *,unsigned int *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long GetView(IVectorView<Security::Cryptography::Certificates::CmsSignerInfo *> * *);
					virtual long IndexOf(Security::Cryptography::Certificates::ICmsSignerInfo *,unsigned int *,unsigned char *);
					virtual long InsertAt(unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long RemoveAt(unsigned int);
					virtual long RemoveAtEnd();
					virtual long ReplaceAll(unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo * *);
					virtual long SetAt(unsigned int,Security::Cryptography::Certificates::ICmsSignerInfo *);
					virtual long get_Size(unsigned int *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct VectorOptions<HSTRING__ *,0,0,0>
				{
					static long RaiseEvent(...);
				};

				struct VectorOptions<HSTRING__ *,0,1,0>
				{
					static long RaiseEvent(...);
				};

				struct VectorOptions<Security::Cryptography::Certificates::Certificate *,0,1,0>
				{
					static long RaiseEvent(...);
				};

				struct VectorOptions<Security::Cryptography::Certificates::CertificateExtension *,0,1,0>
				{
					static long RaiseEvent(...);
				};

				struct VectorOptions<Security::Cryptography::Certificates::CmsSignerInfo *,0,1,0>
				{
					static long RaiseEvent(...);
				};

			};

		};

		long ActivateInstance<Microsoft::WRL::ComPtr<Security::Cryptography::Certificates::IUserCertificateEnrollmentManager> >(HSTRING__ *,Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<Security::Cryptography::Certificates::IUserCertificateEnrollmentManager> >);
		long ActivateInstance<Microsoft::WRL::ComPtr<Security::Cryptography::Certificates::IUserCertificateStore> >(HSTRING__ *,Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<Security::Cryptography::Certificates::IUserCertificateStore> >);
		long ActivateInstance<Microsoft::WRL::ComPtr<UI::Popups::IUICommand> >(HSTRING__ *,Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<UI::Popups::IUICommand> >);
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
			virtual ~GitPtr();
		};

		class GitPtrImpl<GitPtr>
		{
		protected:
			long Localize(_GUID const &,void * *);
		public:
			long CopyLocal<Foundation::Collections::IIterable<Security::Cryptography::Certificates::Certificate *> >(Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<Foundation::Collections::IIterable<Security::Cryptography::Certificates::Certificate *> > >);
			long CopyLocal<Foundation::Collections::IIterable<Security::Cryptography::Certificates::CmsSignerInfo *> >(Microsoft::WRL::Details::ComPtrRef<Microsoft::WRL::ComPtr<Foundation::Collections::IIterable<Security::Cryptography::Certificates::CmsSignerInfo *> > >);
			long Initialize<Foundation::Collections::IIterable<Security::Cryptography::Certificates::Certificate *> >(Foundation::Collections::IIterable<Security::Cryptography::Certificates::Certificate *> *);
			long Initialize<Foundation::Collections::IIterable<Security::Cryptography::Certificates::CmsSignerInfo *> >(Foundation::Collections::IIterable<Security::Cryptography::Certificates::CmsSignerInfo *> *);
			long Revoke();
			virtual bool IsInitialized();
			virtual ~GitPtrImpl<GitPtr>();
		};

		class String
		{
			long _InitializeHelper(unsigned short const *);
		public:
			long Duplicate(String const &);
			long Initialize(HSTRING__ * const &);
			long Initialize(unsigned short const *,unsigned int);
			~String();
		};

		class StringReference
		{
			void _ConstructorHelper(unsigned short const *);
		public:
			StringReference<10>(unsigned short const (&)[10]);
			StringReference<11>(unsigned short const (&)[11]);
			StringReference<12>(unsigned short const (&)[12]);
			StringReference<13>(unsigned short const (&)[13]);
			StringReference<14>(unsigned short const (&)[14]);
			StringReference<15>(unsigned short const (&)[15]);
			StringReference<16>(unsigned short const (&)[16]);
			StringReference<17>(unsigned short const (&)[17]);
			StringReference<18>(unsigned short const (&)[18]);
			StringReference<19>(unsigned short const (&)[19]);
			StringReference<20>(unsigned short const (&)[20]);
			StringReference<21>(unsigned short const (&)[21]);
			StringReference<22>(unsigned short const (&)[22]);
			StringReference<23>(unsigned short const (&)[23]);
			StringReference<24>(unsigned short const (&)[24]);
			StringReference<25>(unsigned short const (&)[25]);
			StringReference<26>(unsigned short const (&)[26]);
			StringReference<27>(unsigned short const (&)[27]);
			StringReference<28>(unsigned short const (&)[28]);
			StringReference<32>(unsigned short const (&)[32]);
			StringReference<33>(unsigned short const (&)[33]);
			StringReference<3>(unsigned short const (&)[3]);
			StringReference<5>(unsigned short const (&)[5]);
			StringReference<7>(unsigned short const (&)[7]);
			StringReference<80>(unsigned short const (&)[80]);
			StringReference<81>(unsigned short const (&)[81]);
			StringReference<82>(unsigned short const (&)[82]);
			StringReference<83>(unsigned short const (&)[83]);
			StringReference<84>(unsigned short const (&)[84]);
			StringReference<85>(unsigned short const (&)[85]);
			StringReference<87>(unsigned short const (&)[87]);
			StringReference<88>(unsigned short const (&)[88]);
			StringReference<90>(unsigned short const (&)[90]);
			StringReference<93>(unsigned short const (&)[93]);
			StringReference<94>(unsigned short const (&)[94]);
			StringReference<98>(unsigned short const (&)[98]);
		};

	};

	namespace Security
	{
		namespace Cryptography
		{
			namespace Certificates
			{
				struct CAddOrDeleteCertInUserStoreOperation
				{
					CAddOrDeleteCertInUserStoreOperation();
					long RuntimeClassInitialize(unsigned int,HWND__ *,_CERT_CONTEXT const *,unsigned short *,unsigned short *,unsigned short *,int,void *,int);
					virtual long DoWork();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults(unsigned char *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
					virtual ~CAddOrDeleteCertInUserStoreOperation();
				};

				struct CBuildChainDefaultOperation
				{
					CBuildChainDefaultOperation();
					virtual long DoWork();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults(ICertificateChain * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CBuildChainWithParaOperation
				{
					CBuildChainWithParaOperation();
					long RuntimeClassInitialize(unsigned int,Foundation::Collections::IIterable<Certificate *> *,IChainBuildingParameters *,_CERT_CONTEXT const *);
					virtual long DoWork();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults(ICertificateChain * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CCertificate
				{
					CCertificate();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long BuildChainAsync(Foundation::Collections::IIterable<Certificate *> *,Foundation::IAsyncOperation<CertificateChain *> * *);
					virtual long BuildChainWithParametersAsync(Foundation::Collections::IIterable<Certificate *> *,IChainBuildingParameters *,Foundation::IAsyncOperation<CertificateChain *> * *);
					virtual long GetCertContext(_CERT_CONTEXT const * *);
					virtual long GetCertificateBlob(Storage::Streams::IBuffer * *);
					virtual long GetHashValue(unsigned int *,unsigned char * *);
					virtual long GetHashValueWithAlgorithm(HSTRING__ *,unsigned int *,unsigned char * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetSerializedCertContext(unsigned int *,unsigned char * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_EnhancedKeyUsages(Foundation::Collections::IVectorView<HSTRING__ *> * *);
					virtual long get_FriendlyName(HSTRING__ * *);
					virtual long get_HasPrivateKey(unsigned char *);
					virtual long get_IsPerUser(unsigned char *);
					virtual long get_IsSecurityDeviceBound(unsigned char *);
					virtual long get_IsStronglyProtected(unsigned char *);
					virtual long get_Issuer(HSTRING__ * *);
					virtual long get_KeyAlgorithmName(HSTRING__ * *);
					virtual long get_KeyStorageProviderName(HSTRING__ * *);
					virtual long get_KeyUsages(ICertificateKeyUsages * *);
					virtual long get_SerialNumber(unsigned int *,unsigned char * *);
					virtual long get_SignatureAlgorithmName(HSTRING__ * *);
					virtual long get_SignatureHashAlgorithmName(HSTRING__ * *);
					virtual long get_StoreName(HSTRING__ * *);
					virtual long get_Subject(HSTRING__ * *);
					virtual long get_SubjectAlternativeName(ISubjectAlternativeNameInfo * *);
					virtual long get_ValidFrom(Foundation::DateTime *);
					virtual long get_ValidTo(Foundation::DateTime *);
					virtual long put_FriendlyName(HSTRING__ *);
					virtual long set_IsPerUser(unsigned char);
					virtual long set_StoreName(unsigned short *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CCertificateChain
				{
					CCertificateChain();
					virtual long GetCertificates(unsigned char,Foundation::Collections::IVectorView<Certificate *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long Validate(ChainValidationResult *);
					virtual long ValidateWithParameters(IChainValidationParameters *,ChainValidationResult *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CCertificateEnrollmentManager
				{
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
				};

				struct CCertificateEnrollmentManagerFactory
				{
					CCertificateEnrollmentManagerFactory();
					virtual long ActivateInstance(IInspectable * *);
					virtual long CreateRequestAsync(ICertificateRequestProperties *,Foundation::IAsyncOperation<HSTRING__ *> * *);
					virtual long ImportPfxDataAsync(HSTRING__ *,HSTRING__ *,ExportOption,KeyProtectionLevel,InstallOptions,HSTRING__ *,Foundation::IAsyncAction * *);
					virtual long ImportPfxDataToKspAsync(HSTRING__ *,HSTRING__ *,ExportOption,KeyProtectionLevel,InstallOptions,HSTRING__ *,HSTRING__ *,Foundation::IAsyncAction * *);
					virtual long ImportPfxDataToKspWithParametersAsync(HSTRING__ *,HSTRING__ *,IPfxImportParameters *,Foundation::IAsyncAction * *);
					virtual long InstallCertificateAsync(HSTRING__ *,InstallOptions,Foundation::IAsyncAction * *);
					virtual long get_UserCertificateEnrollmentManager(IUserCertificateEnrollmentManager * *);
				};

				struct CCertificateExtension
				{
					CCertificateExtension();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long EncodeValue(HSTRING__ *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long UpdateValue(unsigned int,unsigned char const *);
					virtual long get_IsCritical(unsigned char *);
					virtual long get_ObjectId(HSTRING__ * *);
					virtual long get_Value(unsigned int *,unsigned char * *);
					virtual long put_IsCritical(unsigned char);
					virtual long put_ObjectId(HSTRING__ *);
					virtual long put_Value(unsigned int,unsigned char const *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CCertificateFactory
				{
					virtual long ActivateInstance(IInspectable * *);
					virtual long CreateCertificate(Storage::Streams::IBuffer *,ICertificate * *);
				};

				struct CCertificateKeyUsages
				{
					CCertificateKeyUsages();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_CrlSign(unsigned char *);
					virtual long get_DataEncipherment(unsigned char *);
					virtual long get_DigitalSignature(unsigned char *);
					virtual long get_EncipherOnly(unsigned char *);
					virtual long get_KeyAgreement(unsigned char *);
					virtual long get_KeyCertificateSign(unsigned char *);
					virtual long get_KeyEncipherment(unsigned char *);
					virtual long get_NonRepudiation(unsigned char *);
					virtual long put_CrlSign(unsigned char);
					virtual long put_DataEncipherment(unsigned char);
					virtual long put_DigitalSignature(unsigned char);
					virtual long put_EncipherOnly(unsigned char);
					virtual long put_KeyAgreement(unsigned char);
					virtual long put_KeyCertificateSign(unsigned char);
					virtual long put_KeyEncipherment(unsigned char);
					virtual long put_NonRepudiation(unsigned char);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CCertificateQuery
				{
					CCertificateQuery();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_EnhancedKeyUsages(Foundation::Collections::IVector<HSTRING__ *> * *);
					virtual long get_FriendlyName(HSTRING__ * *);
					virtual long get_HardwareOnly(unsigned char *);
					virtual long get_IncludeDuplicates(unsigned char *);
					virtual long get_IncludeExpiredCertificates(unsigned char *);
					virtual long get_IssuerName(HSTRING__ * *);
					virtual long get_StoreName(HSTRING__ * *);
					virtual long get_Thumbprint(unsigned int *,unsigned char * *);
					virtual long put_FriendlyName(HSTRING__ *);
					virtual long put_HardwareOnly(unsigned char);
					virtual long put_IncludeDuplicates(unsigned char);
					virtual long put_IncludeExpiredCertificates(unsigned char);
					virtual long put_IssuerName(HSTRING__ *);
					virtual long put_StoreName(HSTRING__ *);
					virtual long put_Thumbprint(unsigned int,unsigned char *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
					virtual ~CCertificateQuery();
				};

				struct CCertificateRequestProperties
				{
					CCertificateRequestProperties();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_AttestationCredentialCertificate(ICertificate * *);
					virtual long get_ContainerName(HSTRING__ * *);
					virtual long get_ContainerNamePrefix(HSTRING__ * *);
					virtual long get_CurveName(HSTRING__ * *);
					virtual long get_CurveParameters(unsigned int *,unsigned char * *);
					virtual long get_Exportable(ExportOption *);
					virtual long get_Extensions(Foundation::Collections::IVector<CertificateExtension *> * *);
					virtual long get_FriendlyName(HSTRING__ * *);
					virtual long get_HashAlgorithmName(HSTRING__ * *);
					virtual long get_KeyAlgorithmName(HSTRING__ * *);
					virtual long get_KeyProtectionLevel(KeyProtectionLevel *);
					virtual long get_KeySize(unsigned int *);
					virtual long get_KeyStorageProviderName(HSTRING__ * *);
					virtual long get_KeyUsages(EnrollKeyUsages *);
					virtual long get_SigningCertificate(ICertificate * *);
					virtual long get_SmartcardReaderName(HSTRING__ * *);
					virtual long get_Subject(HSTRING__ * *);
					virtual long get_SubjectAlternativeName(ISubjectAlternativeNameInfo * *);
					virtual long get_SuppressedDefaults(Foundation::Collections::IVector<HSTRING__ *> * *);
					virtual long get_UseExistingKey(unsigned char *);
					virtual long put_AttestationCredentialCertificate(ICertificate *);
					virtual long put_ContainerName(HSTRING__ *);
					virtual long put_ContainerNamePrefix(HSTRING__ *);
					virtual long put_CurveName(HSTRING__ *);
					virtual long put_CurveParameters(unsigned int,unsigned char *);
					virtual long put_Exportable(ExportOption);
					virtual long put_FriendlyName(HSTRING__ *);
					virtual long put_HashAlgorithmName(HSTRING__ *);
					virtual long put_KeyAlgorithmName(HSTRING__ *);
					virtual long put_KeyProtectionLevel(KeyProtectionLevel);
					virtual long put_KeySize(unsigned int);
					virtual long put_KeyStorageProviderName(HSTRING__ *);
					virtual long put_KeyUsages(EnrollKeyUsages);
					virtual long put_SigningCertificate(ICertificate *);
					virtual long put_SmartcardReaderName(HSTRING__ *);
					virtual long put_Subject(HSTRING__ *);
					virtual long put_UseExistingKey(unsigned char);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
					virtual ~CCertificateRequestProperties();
				};

				struct CCertificateStore
				{
					CCertificateStore();
					virtual long Add(ICertificate *);
					virtual long AddOrDeleteCert(ICertificate *,unsigned char);
					virtual long Delete(ICertificate *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Name(HSTRING__ * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CCertificateStores
				{
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
				};

				struct CCertificateStoresFactory
				{
					CCertificateStoresFactory();
					virtual long ActivateInstance(IInspectable * *);
					virtual long FindAllAsync(Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Certificate *> *> * *);
					virtual long FindAllWithQueryAsync(ICertificateQuery *,Foundation::IAsyncOperation<Foundation::Collections::IVectorView<Certificate *> *> * *);
					virtual long GetStoreByName(HSTRING__ *,ICertificateStore * *);
					virtual long GetUserStoreByName(HSTRING__ *,IUserCertificateStore * *);
					virtual long get_IntermediateCertificationAuthorities(ICertificateStore * *);
					virtual long get_TrustedRootCertificationAuthorities(ICertificateStore * *);
				};

				struct CChainBuildingParameters
				{
					CChainBuildingParameters();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_AuthorityInformationAccessEnabled(unsigned char *);
					virtual long get_CurrentTimeValidationEnabled(unsigned char *);
					virtual long get_EnhancedKeyUsages(Foundation::Collections::IVector<HSTRING__ *> * *);
					virtual long get_ExclusiveTrustRoots(Foundation::Collections::IVector<Certificate *> * *);
					virtual long get_NetworkRetrievalEnabled(unsigned char *);
					virtual long get_RevocationCheckEnabled(unsigned char *);
					virtual long get_ValidationTimestamp(Foundation::DateTime *);
					virtual long put_AuthorityInformationAccessEnabled(unsigned char);
					virtual long put_CurrentTimeValidationEnabled(unsigned char);
					virtual long put_NetworkRetrievalEnabled(unsigned char);
					virtual long put_RevocationCheckEnabled(unsigned char);
					virtual long put_ValidationTimestamp(Foundation::DateTime);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CChainValidationParameters
				{
					CChainValidationParameters();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_CertificateChainPolicy(CertificateChainPolicy *);
					virtual long get_ServerDnsName(Networking::IHostName * *);
					virtual long put_CertificateChainPolicy(CertificateChainPolicy);
					virtual long put_ServerDnsName(Networking::IHostName *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CCmsAttachedSignature
				{
					CCmsAttachedSignature();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long VerifySignature(SignatureValidationResult *);
					virtual long get_Certificates(Foundation::Collections::IVectorView<Certificate *> * *);
					virtual long get_Content(unsigned int *,unsigned char * *);
					virtual long get_Signers(Foundation::Collections::IVectorView<CmsSignerInfo *> * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CCmsAttachedSignatureFactory
				{
					CCmsAttachedSignatureFactory();
					virtual long ActivateInstance(IInspectable * *);
					virtual long CreateCmsAttachedSignature(Storage::Streams::IBuffer *,ICmsAttachedSignature * *);
					virtual long GenerateSignatureAsync(Storage::Streams::IBuffer *,Foundation::Collections::IIterable<CmsSignerInfo *> *,Foundation::Collections::IIterable<Certificate *> *,Foundation::IAsyncOperation<Storage::Streams::IBuffer *> * *);
				};

				struct CCmsDetachedSignature
				{
					CCmsDetachedSignature();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long VerifySignatureAsync(Storage::Streams::IInputStream *,Foundation::IAsyncOperation<SignatureValidationResult> * *);
					virtual long get_Certificates(Foundation::Collections::IVectorView<Certificate *> * *);
					virtual long get_Signers(Foundation::Collections::IVectorView<CmsSignerInfo *> * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CCmsDetachedSignatureFactory
				{
					CCmsDetachedSignatureFactory();
					virtual long ActivateInstance(IInspectable * *);
					virtual long CreateCmsDetachedSignature(Storage::Streams::IBuffer *,ICmsDetachedSignature * *);
					virtual long GenerateSignatureAsync(Storage::Streams::IInputStream *,Foundation::Collections::IIterable<CmsSignerInfo *> *,Foundation::Collections::IIterable<Certificate *> *,Foundation::IAsyncOperation<Storage::Streams::IBuffer *> * *);
				};

				struct CCmsSignerInfo
				{
					CCmsSignerInfo();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Certificate(ICertificate * *);
					virtual long get_HashAlgorithmName(HSTRING__ * *);
					virtual long get_TimestampInfo(ICmsTimestampInfo * *);
					virtual long put_Certificate(ICertificate *);
					virtual long put_HashAlgorithmName(HSTRING__ *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
					virtual ~CCmsSignerInfo();
				};

				struct CCmsTimestampInfo
				{
					CCmsTimestampInfo();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_Certificates(Foundation::Collections::IVectorView<Certificate *> * *);
					virtual long get_SigningCertificate(ICertificate * *);
					virtual long get_Timestamp(Foundation::DateTime *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CCreateRequest2Operation
				{
					CCreateRequest2Operation();
					long RuntimeClassInitialize(unsigned int,ICertificateRequestProperties *,HWND__ *,unsigned short *,unsigned short *,unsigned short *,int);
					virtual long DoWork();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults(HSTRING__ * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
					virtual ~CCreateRequest2Operation();
				};

				struct CCreateRequestOperation
				{
					CCreateRequestOperation();
					virtual long DoWork();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults(HSTRING__ * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CFindAllOperation
				{
					CFindAllOperation();
					long RuntimeClassInitialize(unsigned int);
					virtual long DoWork();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults(Foundation::Collections::IVectorView<Certificate *> * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CFindAllWithQueryOperation
				{
					CFindAllWithQueryOperation();
					long RuntimeClassInitialize(unsigned int,ICertificateQuery *);
					virtual long DoWork();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults(Foundation::Collections::IVectorView<Certificate *> * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class CImportPfxData2Operation
				{
				protected:
					virtual long DoWork();
				public:
					CImportPfxData2Operation();
					long RuntimeClassInitialize(unsigned int,HSTRING__ *,HSTRING__ *,_IMPORTPFXOPTION,HSTRING__ *,HWND__ *,unsigned short *,unsigned short *,unsigned short *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults();
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
					virtual ~CImportPfxData2Operation();
				};

				class CImportPfxDataOperation
				{
				protected:
					virtual long DoWork();
				public:
					CImportPfxDataOperation();
					long RuntimeClassInitialize(unsigned int,HSTRING__ *,HSTRING__ *,ExportOption,KeyProtectionLevel,InstallOptions,HSTRING__ *,HWND__ *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults();
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class CImportPfxDataToKsp2Operation
				{
				protected:
					virtual long DoWork();
				public:
					CImportPfxDataToKsp2Operation();
					long RuntimeClassInitialize(unsigned int,HSTRING__ *,HSTRING__ *,IPfxImportParameters *,int,HWND__ *,unsigned short *,unsigned short *,unsigned short *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults();
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
					virtual ~CImportPfxDataToKsp2Operation();
				};

				class CImportPfxDataToKspOperation
				{
				protected:
					virtual long DoWork();
				public:
					CImportPfxDataToKspOperation();
					long RuntimeClassInitialize(unsigned int,HSTRING__ *,HSTRING__ *,IPfxImportParameters *,HWND__ *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults();
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class CInstallCertificate2Operation
				{
				protected:
					virtual long DoWork();
				public:
					CInstallCertificate2Operation();
					long RuntimeClassInitialize(unsigned int,HSTRING__ *,InstallOptions,HWND__ *,unsigned short *,unsigned short *,unsigned short *,int);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults();
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				class CInstallCertificateOperation
				{
				protected:
					virtual long DoWork();
				public:
					CInstallCertificateOperation();
					long RuntimeClassInitialize(unsigned int,HSTRING__ *,InstallOptions,HWND__ *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults();
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CKeyAlgorithmNames
				{
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
				};

				struct CKeyAlgorithmNamesFactory
				{
					CKeyAlgorithmNamesFactory();
					virtual long ActivateInstance(IInspectable * *);
					virtual long get_Dsa(HSTRING__ * *);
					virtual long get_Ecdh(HSTRING__ * *);
					virtual long get_Ecdh256(HSTRING__ * *);
					virtual long get_Ecdh384(HSTRING__ * *);
					virtual long get_Ecdh521(HSTRING__ * *);
					virtual long get_Ecdsa(HSTRING__ * *);
					virtual long get_Ecdsa256(HSTRING__ * *);
					virtual long get_Ecdsa384(HSTRING__ * *);
					virtual long get_Ecdsa521(HSTRING__ * *);
					virtual long get_Rsa(HSTRING__ * *);
				};

				struct CKeyAttestationHelper
				{
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
				};

				struct CKeyAttestationHelperFactory
				{
					CKeyAttestationHelperFactory();
					virtual long ActivateInstance(IInspectable * *);
					virtual long DecryptTpmAttestationCredentialAsync(HSTRING__ *,Foundation::IAsyncOperation<HSTRING__ *> * *);
					virtual long DecryptTpmAttestationCredentialWithContainerNameAsync(HSTRING__ *,HSTRING__ *,Foundation::IAsyncOperation<HSTRING__ *> * *);
					virtual long GetTpmAttestationCredentialId(HSTRING__ *,HSTRING__ * *);
				};

				struct CKeyStorageProviderNames
				{
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
				};

				struct CKeyStorageProviderNamesFactory
				{
					CKeyStorageProviderNamesFactory();
					virtual long ActivateInstance(IInspectable * *);
					virtual long get_PassportKeyStorageProvider(HSTRING__ * *);
					virtual long get_PlatformKeyStorageProvider(HSTRING__ * *);
					virtual long get_SmartcardKeyStorageProvider(HSTRING__ * *);
					virtual long get_SoftwareKeyStorageProvider(HSTRING__ * *);
				};

				struct CPfxImportParameters
				{
					CPfxImportParameters();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long get_ContainerNamePrefix(HSTRING__ * *);
					virtual long get_Exportable(ExportOption *);
					virtual long get_FriendlyName(HSTRING__ * *);
					virtual long get_InstallOptions(InstallOptions *);
					virtual long get_KeyProtectionLevel(KeyProtectionLevel *);
					virtual long get_KeyStorageProviderName(HSTRING__ * *);
					virtual long get_ReaderName(HSTRING__ * *);
					virtual long put_ContainerNamePrefix(HSTRING__ *);
					virtual long put_Exportable(ExportOption);
					virtual long put_FriendlyName(HSTRING__ *);
					virtual long put_InstallOptions(InstallOptions);
					virtual long put_KeyProtectionLevel(KeyProtectionLevel);
					virtual long put_KeyStorageProviderName(HSTRING__ *);
					virtual long put_ReaderName(HSTRING__ *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CSignMessageOperation
				{
					CSignMessageOperation();
					long RuntimeClassInitialize(unsigned int,Storage::Streams::IBuffer *,Foundation::Collections::IIterable<CmsSignerInfo *> *,Foundation::Collections::IIterable<Certificate *> *,HWND__ *);
					virtual long DoWork();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults(Storage::Streams::IBuffer * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CSignStreamMessageOperation
				{
					CSignStreamMessageOperation();
					long RuntimeClassInitialize(unsigned int,Storage::Streams::IInputStream *,Foundation::Collections::IIterable<CmsSignerInfo *> *,Foundation::Collections::IIterable<Certificate *> *,HWND__ *);
					virtual long DoWork();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults(Storage::Streams::IBuffer * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
					virtual ~CSignStreamMessageOperation();
				};

				struct CStandardCertificateStoreNames
				{
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
				};

				struct CStandardCertificateStoreNamesFactory
				{
					CStandardCertificateStoreNamesFactory();
					virtual long ActivateInstance(IInspectable * *);
					virtual long get_IntermediateCertificationAuthorities(HSTRING__ * *);
					virtual long get_Personal(HSTRING__ * *);
					virtual long get_TrustedRootCertificationAuthorities(HSTRING__ * *);
				};

				struct CSubjectAlternativeNameInfo
				{
					CSubjectAlternativeNameInfo();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long appendDistinguishedName(HSTRING__ *);
					virtual long appendDnsName(HSTRING__ *);
					virtual long appendEmailName(HSTRING__ *);
					virtual long appendIPAddress(HSTRING__ *);
					virtual long appendPrincipalName(HSTRING__ *);
					virtual long appendUrl(HSTRING__ *);
					virtual long get_DistinguishedName(Foundation::Collections::IVectorView<HSTRING__ *> * *);
					virtual long get_DistinguishedNames(Foundation::Collections::IVector<HSTRING__ *> * *);
					virtual long get_DnsName(Foundation::Collections::IVectorView<HSTRING__ *> * *);
					virtual long get_DnsNames(Foundation::Collections::IVector<HSTRING__ *> * *);
					virtual long get_EmailName(Foundation::Collections::IVectorView<HSTRING__ *> * *);
					virtual long get_EmailNames(Foundation::Collections::IVector<HSTRING__ *> * *);
					virtual long get_Extension(ICertificateExtension * *);
					virtual long get_IPAddress(Foundation::Collections::IVectorView<HSTRING__ *> * *);
					virtual long get_IPAddresses(Foundation::Collections::IVector<HSTRING__ *> * *);
					virtual long get_PrincipalName(Foundation::Collections::IVectorView<HSTRING__ *> * *);
					virtual long get_PrincipalNames(Foundation::Collections::IVector<HSTRING__ *> * *);
					virtual long get_Url(Foundation::Collections::IVectorView<HSTRING__ *> * *);
					virtual long get_Urls(Foundation::Collections::IVector<HSTRING__ *> * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
					virtual ~CSubjectAlternativeNameInfo();
				};

				struct CUserCertificateEnrollmentManager
				{
					CUserCertificateEnrollmentManager();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long CreateRequestAsync(ICertificateRequestProperties *,Foundation::IAsyncOperation<HSTRING__ *> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long ImportPfxDataAsync(HSTRING__ *,HSTRING__ *,ExportOption,KeyProtectionLevel,InstallOptions,HSTRING__ *,Foundation::IAsyncAction * *);
					virtual long ImportPfxDataToKspAsync(HSTRING__ *,HSTRING__ *,ExportOption,KeyProtectionLevel,InstallOptions,HSTRING__ *,HSTRING__ *,Foundation::IAsyncAction * *);
					virtual long ImportPfxDataToKspWithParametersAsync(HSTRING__ *,HSTRING__ *,IPfxImportParameters *,Foundation::IAsyncAction * *);
					virtual long InstallCertificateAsync(HSTRING__ *,InstallOptions,Foundation::IAsyncAction * *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct CUserCertificateStore
				{
					CUserCertificateStore();
					static TrustLevel InternalGetTrustLevel();
					static unsigned short const * InternalGetRuntimeClassName();
					virtual long AddOrDeleteCert(ICertificate *,unsigned char,Foundation::IAsyncOperation<bool> * *);
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long OpenStore(HSTRING__ *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual long RequestAddAsync(ICertificate *,Foundation::IAsyncOperation<bool> * *);
					virtual long RequestDeleteAsync(ICertificate *,Foundation::IAsyncOperation<bool> * *);
					virtual long get_Name(HSTRING__ * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
					virtual ~CUserCertificateStore();
				};

				struct CVerifyStreamMessageOperation
				{
					CVerifyStreamMessageOperation();
					long RuntimeClassInitialize(unsigned int,Storage::Streams::IInputStream *,void *);
					virtual long DoWork();
					virtual long GetIids(unsigned long *,_GUID * *);
					virtual long GetResults(SignatureValidationResult *);
					virtual long GetRuntimeClassName(HSTRING__ * *);
					virtual long GetTrustLevel(TrustLevel *);
					virtual long QueryInterface(_GUID const &,void * *);
					virtual unsigned long AddRef();
					virtual unsigned long Release();
				};

				struct ConsentMessageDialog
				{
					long Show(HWND__ *,unsigned short const *);
				};

				Microsoft::WRL::Details::CreatorMap const __object_CCertificate;
				Microsoft::WRL::Details::CreatorMap const __object_CCertificateEnrollmentManager;
				Microsoft::WRL::Details::CreatorMap const __object_CCertificateExtension;
				Microsoft::WRL::Details::CreatorMap const __object_CCertificateKeyUsages;
				Microsoft::WRL::Details::CreatorMap const __object_CCertificateQuery;
				Microsoft::WRL::Details::CreatorMap const __object_CCertificateRequestProperties;
				Microsoft::WRL::Details::CreatorMap const __object_CCertificateStores;
				Microsoft::WRL::Details::CreatorMap const __object_CChainBuildingParameters;
				Microsoft::WRL::Details::CreatorMap const __object_CChainValidationParameters;
				Microsoft::WRL::Details::CreatorMap const __object_CCmsAttachedSignature;
				Microsoft::WRL::Details::CreatorMap const __object_CCmsDetachedSignature;
				Microsoft::WRL::Details::CreatorMap const __object_CCmsSignerInfo;
				Microsoft::WRL::Details::CreatorMap const __object_CKeyAlgorithmNames;
				Microsoft::WRL::Details::CreatorMap const __object_CKeyAttestationHelper;
				Microsoft::WRL::Details::CreatorMap const __object_CKeyStorageProviderNames;
				Microsoft::WRL::Details::CreatorMap const __object_CPfxImportParameters;
				Microsoft::WRL::Details::CreatorMap const __object_CStandardCertificateStoreNames;
				Microsoft::WRL::Details::CreatorMap const __object_CSubjectAlternativeNameInfo;
				Microsoft::WRL::Details::CreatorMap const __object_CUserCertificateEnrollmentManager;
				Microsoft::WRL::Details::CreatorMap const __object_CUserCertificateStore;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CCertificate;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CCertificateEnrollmentManager;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CCertificateExtension;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CCertificateKeyUsages;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CCertificateQuery;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CCertificateRequestProperties;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CCertificateStores;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CChainBuildingParameters;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CChainValidationParameters;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CCmsAttachedSignature;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CCmsDetachedSignature;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CCmsSignerInfo;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CKeyAlgorithmNames;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CKeyAttestationHelper;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CKeyStorageProviderNames;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CPfxImportParameters;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CStandardCertificateStoreNames;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CSubjectAlternativeNameInfo;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CUserCertificateEnrollmentManager;
				Microsoft::WRL::Details::FactoryCache __objectFactory__CUserCertificateStore;
				char const * GetHashOID(unsigned short const *);
				long AddDialogCommand(Foundation::Collections::IVector<UI::Popups::IUICommand *> *,unsigned short const *,UI::Popups::IUICommandInvokedHandler *);
				long CheckConsent(HWND__ *,HSTRING__ *,HSTRING__ *,HSTRING__ *,int,unsigned long,int,bool *);
				long ObtainStoreFromName(unsigned short const *,Certificates::ICertificateStore * *);
				long ShowDialogAndGetUserConsent(HWND__ *,unsigned short const *,unsigned short const *,unsigned short const *,bool &);
				long ShowDialogAndGetUserConsent_Worker(HWND__ *,unsigned short const *,unsigned short const *,unsigned short const *,bool &);
				long SkipConsentUiforScOrNgc(HSTRING__ *,HSTRING__ *,bool *);
				long WaitForCompletion<Foundation::IAsyncOperationCompletedHandler<UI::Popups::IUICommand *>,Foundation::IAsyncOperation<UI::Popups::IUICommand *> >(Foundation::IAsyncOperation<UI::Popups::IUICommand *> *);
				long WaitForCompletion<Foundation::IAsyncOperationWithProgressCompletedHandler<Storage::Streams::IBuffer *,unsigned int>,Foundation::IAsyncOperationWithProgress<Storage::Streams::IBuffer *,unsigned int> >(Foundation::IAsyncOperationWithProgress<Storage::Streams::IBuffer *,unsigned int> *);
				unsigned short const * const CertificateEnrollmentManagerImportPfxDataToKspOperationName;
				unsigned short const * const ImportPfxDataAsyncOperationName;
				unsigned short const * const InstallCertificateAsyncOperationName;
				unsigned short const * const UserCertificateEnrollmentManagerImportPfxDataOperationName;
				unsigned short const * const UserCertificateEnrollmentManagerImportPfxDataToKspOperationName;
				unsigned short const * const UserCertificateEnrollmentManagerInstallCertificateAsyncOperationName;
				void ShowDialogAndGetUserConsent_Thunk(_TP_CALLBACK_INSTANCE *,void *);
			};

		};

	};

	namespace Storage
	{
		namespace Streams
		{
			struct CBuffer<CBuffer_StandardCleanup,DefaultMarshaler>
			{
				CBuffer<CBuffer_StandardCleanup,DefaultMarshaler>(unsigned int,unsigned int,unsigned char *,CBuffer_StandardCleanup);
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			struct CBuffer<void (*)(void *),DefaultMarshaler>
			{
				CBuffer<void (*)(void *),DefaultMarshaler>(unsigned int,unsigned int,unsigned char *,void (*)(void *));
				virtual long GetIids(unsigned long *,_GUID * *);
				virtual long GetRuntimeClassName(HSTRING__ * *);
				virtual long GetTrustLevel(TrustLevel *);
				virtual long QueryInterface(_GUID const &,void * *);
				virtual unsigned long AddRef();
				virtual unsigned long Release();
			};

			class CBuffer_Impl<CBuffer_StandardCleanup,DefaultMarshaler>
			{
			protected:
				virtual ~CBuffer_Impl<CBuffer_StandardCleanup,DefaultMarshaler>();
			public:
				virtual long Buffer(unsigned char * *);
				virtual long DisconnectObject(unsigned long);
				virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
				virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
				virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
				virtual long ReleaseMarshalData(IStream *);
				virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
				virtual long get_Capacity(unsigned int *);
				virtual long get_Length(unsigned int *);
				virtual long put_Length(unsigned int);
			};

			class CBuffer_Impl<void (*)(void *),DefaultMarshaler>
			{
			protected:
				virtual ~CBuffer_Impl<void (*)(void *),DefaultMarshaler>();
			public:
				CBuffer_Impl<void (*)(void *),DefaultMarshaler>(unsigned int,unsigned int,unsigned char *,void (*)(void *));
				virtual long Buffer(unsigned char * *);
				virtual long DisconnectObject(unsigned long);
				virtual long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
				virtual long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
				virtual long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
				virtual long ReleaseMarshalData(IStream *);
				virtual long UnmarshalInterface(IStream *,_GUID const &,void * *);
				virtual long get_Capacity(unsigned int *);
				virtual long get_Length(unsigned int *);
				virtual long put_Length(unsigned int);
			};

			class DefaultMarshaler
			{
				long _EnsureInit();
			public:
				long GetMarshalSizeMax(_GUID const &,void *,unsigned long,void *,unsigned long,unsigned long *);
				long GetUnmarshalClass(_GUID const &,void *,unsigned long,void *,unsigned long,_GUID *);
				long MarshalInterface(IStream *,_GUID const &,void *,unsigned long,void *,unsigned long);
				~DefaultMarshaler();
			};

			long CBuffer_Allocate(unsigned int,Streams::IBuffer * *);
			long MakeCBuffer<CBuffer_StandardCleanup>(unsigned int,unsigned int,unsigned char *,Streams::CBuffer_StandardCleanup,Streams::IBuffer * *);
			long MakeCBuffer<void (*)(void *)>(unsigned int,unsigned int,unsigned char *,void (*)(void *),Streams::IBuffer * *);
		};

	};

};

namespace XWinRT
{
	struct AutoValue<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> >
	{
		AutoValue<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> ><HSTRING__ *>(HSTRING__ * const &,long *);
		~AutoValue<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *> >();
	};

	struct AutoValue<Windows::Security::Cryptography::Certificates::ICertificate *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *> >
	{
		~AutoValue<Windows::Security::Cryptography::Certificates::ICertificate *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *> >();
	};

	struct AutoValue<Windows::Security::Cryptography::Certificates::ICertificateExtension *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *> >
	{
		~AutoValue<Windows::Security::Cryptography::Certificates::ICertificateExtension *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *> >();
	};

	struct AutoValue<Windows::Security::Cryptography::Certificates::ICmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >
	{
		~AutoValue<Windows::Security::Cryptography::Certificates::ICmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >();
	};

	struct AutoValue<detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *> >
	{
		AutoValue<detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *> ><Windows::Security::Cryptography::Certificates::ICertificate *>(Windows::Security::Cryptography::Certificates::ICertificate * const &,long *);
		~AutoValue<detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *> >();
	};

	struct AutoValue<detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *> >
	{
		AutoValue<detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *> ><Windows::Security::Cryptography::Certificates::ICertificateExtension *>(Windows::Security::Cryptography::Certificates::ICertificateExtension * const &,long *);
		~AutoValue<detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *> >();
	};

	struct AutoValue<detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >
	{
		AutoValue<detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> ><Windows::Security::Cryptography::Certificates::ICmsSignerInfo *>(Windows::Security::Cryptography::Certificates::ICmsSignerInfo * const &,long *);
		~AutoValue<detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >();
	};

	struct ComLock
	{
		ComLock(bool);
		~ComLock();
	};

	struct InterfaceEquals
	{
		long operator()<Windows::Security::Cryptography::Certificates::ICertificate>(Windows::Security::Cryptography::Certificates::ICertificate *,Windows::Security::Cryptography::Certificates::ICertificate *,bool *);
		long operator()<Windows::Security::Cryptography::Certificates::ICertificateExtension>(Windows::Security::Cryptography::Certificates::ICertificateExtension *,Windows::Security::Cryptography::Certificates::ICertificateExtension *,bool *);
		long operator()<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>(Windows::Security::Cryptography::Certificates::ICmsSignerInfo *,Windows::Security::Cryptography::Certificates::ICmsSignerInfo *,bool *);
	};

	struct InterfaceLifetimeTraits
	{
		static long Construct<Windows::Security::Cryptography::Certificates::ICertificate>(detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate> *,Windows::Security::Cryptography::Certificates::ICertificate *);
		static long Construct<Windows::Security::Cryptography::Certificates::ICertificateExtension>(detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension> *,Windows::Security::Cryptography::Certificates::ICertificateExtension *);
		static long Construct<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>(detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo> *,Windows::Security::Cryptography::Certificates::ICmsSignerInfo *);
		static void Construct<Windows::Security::Cryptography::Certificates::ICertificate>(detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate> *);
		static void Construct<Windows::Security::Cryptography::Certificates::ICertificateExtension>(detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension> *);
		static void Construct<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>(detail::GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo> *);
		static void Destroy<Windows::Security::Cryptography::Certificates::ICertificate>(Windows::Security::Cryptography::Certificates::ICertificate * *);
		static void Destroy<Windows::Security::Cryptography::Certificates::ICertificateExtension>(Windows::Security::Cryptography::Certificates::ICertificateExtension * *);
		static void Destroy<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>(Windows::Security::Cryptography::Certificates::ICmsSignerInfo * *);
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

	namespace detail
	{
		struct AbiReference<Windows::Security::Cryptography::Certificates::ICertificate *,GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *> >
		{
			~AbiReference<Windows::Security::Cryptography::Certificates::ICertificate *,GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *> >();
		};

		struct AbiReference<Windows::Security::Cryptography::Certificates::ICertificateExtension *,GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *> >
		{
			~AbiReference<Windows::Security::Cryptography::Certificates::ICertificateExtension *,GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *> >();
		};

		struct AbiReference<Windows::Security::Cryptography::Certificates::ICmsSignerInfo *,GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >
		{
			~AbiReference<Windows::Security::Cryptography::Certificates::ICmsSignerInfo *,GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >();
		};

		struct GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate>
		{
			struct ReferencedGitCookie
			{
				long Localize(Windows::Security::Cryptography::Certificates::ICertificate * *);
				unsigned long Release();
			};

			GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate>();
			long Initialize(Windows::Security::Cryptography::Certificates::ICertificate *);
		};

		struct GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension>
		{
			struct ReferencedGitCookie
			{
				long Localize(Windows::Security::Cryptography::Certificates::ICertificateExtension * *);
				unsigned long Release();
			};

			GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension>();
			long Initialize(Windows::Security::Cryptography::Certificates::ICertificateExtension *);
		};

		struct GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>
		{
			struct ReferencedGitCookie
			{
				long Localize(Windows::Security::Cryptography::Certificates::ICmsSignerInfo * *);
				unsigned long Release();
			};

			GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>();
			long Initialize(Windows::Security::Cryptography::Certificates::ICmsSignerInfo *);
		};

		struct LockHolder<ComLock,AcquireRead>
		{
			~LockHolder<ComLock,AcquireRead>();
		};

		struct LockHolder<ComLock,AcquireWrite>
		{
			~LockHolder<ComLock,AcquireWrite>();
		};

		struct PresentationReference<GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate>,Windows::Security::Cryptography::Certificates::ICertificate *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *> >
		{
			PresentationReference<GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate>,Windows::Security::Cryptography::Certificates::ICertificate *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *> >(GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate> const &,long *);
			~PresentationReference<GitStorageType<Windows::Security::Cryptography::Certificates::ICertificate>,Windows::Security::Cryptography::Certificates::ICertificate *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::Certificate *> >();
		};

		struct PresentationReference<GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension>,Windows::Security::Cryptography::Certificates::ICertificateExtension *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *> >
		{
			PresentationReference<GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension>,Windows::Security::Cryptography::Certificates::ICertificateExtension *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *> >(GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension> const &,long *);
			~PresentationReference<GitStorageType<Windows::Security::Cryptography::Certificates::ICertificateExtension>,Windows::Security::Cryptography::Certificates::ICertificateExtension *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CertificateExtension *> >();
		};

		struct PresentationReference<GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>,Windows::Security::Cryptography::Certificates::ICmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >
		{
			PresentationReference<GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>,Windows::Security::Cryptography::Certificates::ICmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >(GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo> const &,long *);
			~PresentationReference<GitStorageType<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>,Windows::Security::Cryptography::Certificates::ICmsSignerInfo *,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<Windows::Security::Cryptography::Certificates::CmsSignerInfo *> >();
		};

		struct ReentrancyGuard<0>
		{
			ReentrancyGuard<0>(...);
		};

	};

};

struct _CERTFILTERCALLBACKDATA
{
	~_CERTFILTERCALLBACKDATA();
};

struct _CERTFILTERDATA
{
	~_CERTFILTERDATA();
};

struct _com_error
{
	_com_error(_com_error const &);
	virtual ~_com_error();
};

struct _variant_t
{
	_variant_t & operator=(IDispatch *);
	_variant_t & operator=(IUnknown *);
	~_variant_t();
};

struct auto_se_translator
{
	~auto_se_translator();
};

struct exception
{
	exception();
	exception(char const * const &,int);
	exception(exception const &);
	virtual char const * what();
	virtual ~exception();
};

namespace microsoft
{
	namespace fs
	{
		namespace common
		{
			class FsException
			{
				static void initBuffer(unsigned short * &,unsigned __int64);
				void assign(FsException const &);
				void initBuffers();
				void setDetailedMessage();
			public:
				FsException();
				FsException(FsException const &);
				FsException(unsigned short const *,unsigned long,unsigned short const *,long);
				FsException(unsigned short const *,unsigned long,unsigned short const *,long,unsigned short const *,...);
				virtual long GetHResult();
				virtual unsigned long GetLine();
				virtual unsigned short const * GetDetailedMessage();
				virtual unsigned short const * GetExpression();
				virtual unsigned short const * GetFile();
				virtual unsigned short const * GetMessageW();
				virtual void Clear();
				virtual ~FsException();
			};

			struct IConfigurable
			{
				virtual ~IConfigurable();
			};

			class auto_array<unsigned char>
			{
				void assign(unsigned char *);
			public:
				~auto_array<unsigned char>();
			};

			struct auto_array<unsigned short>
			{
				~auto_array<unsigned short>();
			};

			class auto_handle_t<unsigned __int64,0,cryptography::CloseCapiHashFunctor>
			{
				void close();
			public:
				void reset(unsigned __int64);
				~auto_handle_t<unsigned __int64,0,cryptography::CloseCapiHashFunctor>();
			};

			class auto_handle_t<unsigned __int64,0,cryptography::CloseCapiKeyFunctor>
			{
				void close();
			public:
				void reset(unsigned __int64);
				~auto_handle_t<unsigned __int64,0,cryptography::CloseCapiKeyFunctor>();
			};

			class auto_handle_t<unsigned __int64,0,cryptography::CloseCapiProviderFunctor>
			{
				void close();
			public:
				auto_handle_t<unsigned __int64,0,cryptography::CloseCapiProviderFunctor>(unsigned __int64,bool);
				void reset(unsigned __int64);
				~auto_handle_t<unsigned __int64,0,cryptography::CloseCapiProviderFunctor>();
			};

			class auto_handle_t<unsigned __int64,0,cryptography::CloseCngNCryptKeyFunctor>
			{
				void close();
			public:
				void reset(unsigned __int64);
				~auto_handle_t<unsigned __int64,0,cryptography::CloseCngNCryptKeyFunctor>();
			};

			class auto_handle_t<unsigned __int64,0,cryptography::CloseCngNCryptProviderFunctor>
			{
				void close();
			public:
				void reset(unsigned __int64);
				~auto_handle_t<unsigned __int64,0,cryptography::CloseCngNCryptProviderFunctor>();
			};

			class auto_handle_t<unsigned __int64,0,cryptography::CloseCngNCryptSecretFunctor>
			{
				void close();
			public:
				void reset(unsigned __int64);
				~auto_handle_t<unsigned __int64,0,cryptography::CloseCngNCryptSecretFunctor>();
			};

			class auto_handle_t<void *,0,cryptography::CloseCngBCryptHashFunctor>
			{
				void close();
			public:
				~auto_handle_t<void *,0,cryptography::CloseCngBCryptHashFunctor>();
			};

			class auto_handle_t<void *,0,cryptography::CloseCngBCryptKeyFunctor>
			{
				void close();
			public:
				~auto_handle_t<void *,0,cryptography::CloseCngBCryptKeyFunctor>();
			};

			class auto_handle_t<void *,0,cryptography::CloseCngBCryptProviderFunctor>
			{
				void close();
			public:
				void reset(void *);
				~auto_handle_t<void *,0,cryptography::CloseCngBCryptProviderFunctor>();
			};

			class auto_pointer<cryptography::ICipher>
			{
				void close();
			public:
				void reset(cryptography::ICipher *);
				~auto_pointer<cryptography::ICipher>();
			};

			class auto_pointer<cryptography::IHash>
			{
				void close();
			public:
				auto_pointer<cryptography::IHash>(cryptography::IHash *);
				void reset(cryptography::IHash *);
				~auto_pointer<cryptography::IHash>();
			};

			struct auto_pointer_t<csp_hash_tag,0,cryptography::CloseHashInfoListFunctor>
			{
				~auto_pointer_t<csp_hash_tag,0,cryptography::CloseHashInfoListFunctor>();
			};

			struct str_w
			{
				str_w(char const *,unsigned __int64);
				str_w(unsigned short const *,unsigned __int64);
				~str_w();
			};

		};

		namespace cryptography
		{
			struct BaseCipher
			{
				BaseCipher();
				virtual void * ReleaseHCryptProvOrNCryptKeyHandle();
				virtual void Decrypt(unsigned char const *,unsigned long,unsigned char *,unsigned long *,bool);
				virtual void DeriveKey(unsigned char *,unsigned long *);
				virtual void Encrypt(unsigned char const *,unsigned long,unsigned char *,unsigned long *,bool);
				virtual void ExportKey(ICipher *,unsigned short const *,unsigned char *,unsigned long *);
				virtual void GenerateSecretAgreement(ICipher *);
				virtual void GetProperty(unsigned short const *,unsigned char *,unsigned long *,unsigned long);
				virtual void SetProperty(unsigned short const *,unsigned char const *,unsigned long,unsigned long);
				virtual void Sign(unsigned char *,unsigned long *,unsigned char const *,unsigned long,void const *,unsigned long);
				virtual void Verify(unsigned char const *,unsigned long,unsigned char const *,unsigned long,void const *,unsigned long,long *);
				virtual ~BaseCipher();
			};

			struct BaseHash
			{
				virtual void Finalize(unsigned char *,unsigned long);
				virtual void GetProperty(unsigned short const *,unsigned char *,unsigned long *,unsigned long);
				virtual void Hash(unsigned char const *,unsigned long);
				virtual void SetProperty(unsigned short const *,unsigned char const *,unsigned long,unsigned long);
				virtual ~BaseHash();
			};

			struct CapiCipher
			{
				CapiCipher(unsigned __int64,unsigned __int64,unsigned long,bool,bool);
				virtual void * GetHCryptProvOrNCryptKeyHandle();
				virtual void * GetHandle();
				virtual void * GetProviderHandle();
				virtual void * ReleaseHCryptProvOrNCryptKeyHandle(common::FsException *);
				virtual void Decrypt(unsigned char const *,unsigned long,unsigned char *,unsigned long *,bool,common::FsException *);
				virtual void DeriveKey(unsigned char *,unsigned long *,common::FsException *);
				virtual void Encrypt(unsigned char const *,unsigned long,unsigned char *,unsigned long *,bool,common::FsException *);
				virtual void ExportKey(ICipher *,unsigned short const *,unsigned char *,unsigned long *,common::FsException *);
				virtual void GenerateSecretAgreement(ICipher *,common::FsException *);
				virtual void GetProperty(unsigned short const *,unsigned char *,unsigned long *,unsigned long,common::FsException *);
				virtual void SetProperty(unsigned short const *,unsigned char const *,unsigned long,unsigned long,common::FsException *);
				virtual void Sign(unsigned char *,unsigned long *,unsigned char const *,unsigned long,void const *,unsigned long,common::FsException *);
				virtual void Verify(unsigned char const *,unsigned long,unsigned char const *,unsigned long,void const *,unsigned long,long *,common::FsException *);
				virtual void const * GetHCryptProvOrNCryptKeyHandle();
				virtual void const * GetHandle();
				virtual void const * GetProviderHandle();
				virtual ~CapiCipher();
			};

			struct CapiCryptoFactory
			{
				static ICipher * ImportCipher(unsigned short const *,unsigned long,unsigned short const *,unsigned long,ICipher *,unsigned char const *,unsigned long,unsigned long,unsigned long,bool,common::FsException *,unsigned short const *,HWND__ *,unsigned short const *,unsigned short const *);
				static ICipher * OpenCipher(unsigned short const *,unsigned long,unsigned short const *,unsigned long,unsigned long,common::FsException *,unsigned short const *);
				static ICipher * OpenCipherFromHandle(unsigned __int64,unsigned __int64,unsigned long,bool,bool,common::FsException *);
				static IHash * CreateHash(unsigned short const *,unsigned long,unsigned long,common::FsException *);
				static IHash * CreateHashForProvider(unsigned __int64,void const *,unsigned long,bool,common::FsException *);
				static void DeleteCipher(unsigned short const *,unsigned long,unsigned short const *,unsigned long,common::FsException *,unsigned short const *);
			};

			struct CapiHash
			{
				CapiHash(unsigned __int64,unsigned __int64,bool,bool);
				virtual void * GetHandle();
				virtual void Finalize(unsigned char *,unsigned long,common::FsException *);
				virtual void GetProperty(unsigned short const *,unsigned char *,unsigned long *,unsigned long,common::FsException *);
				virtual void Hash(unsigned char const *,unsigned long,common::FsException *);
				virtual void SetProperty(unsigned short const *,unsigned char const *,unsigned long,unsigned long,common::FsException *);
				virtual ~CapiHash();
			};

			class CngBCryptCipher
			{
				unsigned long getEncryptDecryptFlag(bool);
			public:
				CngBCryptCipher(void *,void *,unsigned char *,unsigned long,bool,bool);
				virtual void * GetHCryptProvOrNCryptKeyHandle();
				virtual void * GetHandle();
				virtual void * GetProviderHandle();
				virtual void * ReleaseHCryptProvOrNCryptKeyHandle(common::FsException *);
				virtual void Decrypt(unsigned char const *,unsigned long,unsigned char *,unsigned long *,bool,common::FsException *);
				virtual void DeriveKey(unsigned char *,unsigned long *,common::FsException *);
				virtual void Encrypt(unsigned char const *,unsigned long,unsigned char *,unsigned long *,bool,common::FsException *);
				virtual void ExportKey(ICipher *,unsigned short const *,unsigned char *,unsigned long *,common::FsException *);
				virtual void GenerateSecretAgreement(ICipher *,common::FsException *);
				virtual void GetProperty(unsigned short const *,unsigned char *,unsigned long *,unsigned long,common::FsException *);
				virtual void SetProperty(unsigned short const *,unsigned char const *,unsigned long,unsigned long,common::FsException *);
				virtual void Sign(unsigned char *,unsigned long *,unsigned char const *,unsigned long,void const *,unsigned long,common::FsException *);
				virtual void Verify(unsigned char const *,unsigned long,unsigned char const *,unsigned long,void const *,unsigned long,long *,common::FsException *);
				virtual void const * GetHCryptProvOrNCryptKeyHandle();
				virtual void const * GetHandle();
				virtual void const * GetProviderHandle();
				virtual ~CngBCryptCipher();
			};

			struct CngBCryptHash
			{
				CngBCryptHash(void *,void *,unsigned char *,unsigned long);
				virtual void * GetHandle();
				virtual void Finalize(unsigned char *,unsigned long,common::FsException *);
				virtual void GetProperty(unsigned short const *,unsigned char *,unsigned long *,unsigned long,common::FsException *);
				virtual void Hash(unsigned char const *,unsigned long,common::FsException *);
				virtual void SetProperty(unsigned short const *,unsigned char const *,unsigned long,unsigned long,common::FsException *);
				virtual ~CngBCryptHash();
			};

			struct CngCryptoFactory
			{
				static ICipher * CreateAsymmetricCipher(unsigned short const *,unsigned short const *,unsigned short const *,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,bool,bool,common::FsException *,unsigned short const *);
				static ICipher * ImportCipher(unsigned short const *,unsigned short const *,unsigned short const *,unsigned long,unsigned char const *,unsigned long,unsigned long,unsigned long,bool,common::FsException *,unsigned short const *,HWND__ *,unsigned short const *,unsigned short const *);
				static ICipher * OpenCipher(unsigned short const *,unsigned short const *,unsigned long,unsigned long,common::FsException *,unsigned short const *,unsigned short const *);
				static ICipher * OpenCipherFromHandle(unsigned __int64,unsigned __int64,bool,bool,common::FsException *);
				static IHash * CreateHash(unsigned short const *,unsigned short const *,common::FsException *);
				static void DeleteCipher(unsigned short const *,unsigned short const *,unsigned long,common::FsException *,unsigned short const *);
			};

			class CngNCryptCipher
			{
				unsigned long getEncryptDecryptFlag();
			public:
				CngNCryptCipher(unsigned __int64,unsigned __int64,bool,bool);
				virtual void * GetHCryptProvOrNCryptKeyHandle();
				virtual void * GetHandle();
				virtual void * GetProviderHandle();
				virtual void * ReleaseHCryptProvOrNCryptKeyHandle(common::FsException *);
				virtual void Decrypt(unsigned char const *,unsigned long,unsigned char *,unsigned long *,bool,common::FsException *);
				virtual void DeriveKey(unsigned char *,unsigned long *,common::FsException *);
				virtual void Encrypt(unsigned char const *,unsigned long,unsigned char *,unsigned long *,bool,common::FsException *);
				virtual void ExportKey(ICipher *,unsigned short const *,unsigned char *,unsigned long *,common::FsException *);
				virtual void GenerateSecretAgreement(ICipher *,common::FsException *);
				virtual void GetProperty(unsigned short const *,unsigned char *,unsigned long *,unsigned long,common::FsException *);
				virtual void SetProperty(unsigned short const *,unsigned char const *,unsigned long,unsigned long,common::FsException *);
				virtual void Sign(unsigned char *,unsigned long *,unsigned char const *,unsigned long,void const *,unsigned long,common::FsException *);
				virtual void Verify(unsigned char const *,unsigned long,unsigned char const *,unsigned long,void const *,unsigned long,long *,common::FsException *);
				virtual void const * GetHCryptProvOrNCryptKeyHandle();
				virtual void const * GetHandle();
				virtual void const * GetProviderHandle();
				virtual ~CngNCryptCipher();
			};

			struct CryptoFactory
			{
				static ICipher * ImportCipher(_CRYPT_KEY_PROV_INFO const *,unsigned short const *,unsigned char const *,unsigned long,unsigned long,bool,common::FsException *,unsigned short const *,HWND__ *,unsigned short const *,unsigned short const *);
				static ICipher * OpenCipher(_CRYPT_KEY_PROV_INFO const *,common::FsException *,unsigned short const *);
				static void DeleteCipher(_CRYPT_KEY_PROV_INFO const *,common::FsException *,unsigned short const *);
			};

			struct CryptoUtil
			{
				static CryptoUtil::BlobLookupEntry const * GetBlobLookupEntry(unsigned short const *,common::FsException *);
				static CryptoUtil::PropertyLookupEntry const * GetPropertyLookupEntry(unsigned short const *,common::FsException *);
				static _CRYPT_OID_INFO const * GetCapiHashLookupEntry(void const *,unsigned long,common::FsException *);
				static bool IsPaddingRequired(ICipher *);
				static long FreeHCryptProvOrNCryptKeyHandle(unsigned __int64);
				static void CheckAcquireFlags(unsigned long,common::FsException *);
				static void CheckGenKeyFlags(unsigned long,bool,common::FsException *);
				static void CheckSignaturePaddingInfo(void const *,unsigned long,common::FsException *);
				static void ExportCapiKey(unsigned __int64,ICipher *,unsigned short const *,unsigned char *,unsigned long *,common::FsException *);
				static void ExportCngBCryptKey(void *,ICipher *,unsigned short const *,unsigned char *,unsigned long *,common::FsException *);
				static void ExportCngNCryptKey(unsigned __int64,ICipher *,unsigned short const *,unsigned char *,unsigned long *,common::FsException *);
				static void IToOs(unsigned char *,unsigned long,common::FsException *);
				static void OsToI(unsigned char *,unsigned long,common::FsException *);
				static void Reverse(unsigned char *,unsigned long,common::FsException *);
				static void Swap(unsigned char *,unsigned long,unsigned long,common::FsException *);
				static void VerifyECDHPublicKeyInfoMatchesCipherForEncryption(unsigned long,_CERT_PUBLIC_KEY_INFO const *,ICipher *,long *);
				static void VerifyPublicKeyInfoMatchesCipherForEncryption(unsigned long,_CERT_PUBLIC_KEY_INFO const *,ICipher *,long *,common::FsException *);
				static void VerifyPublicKeyInfoMatchesCipherForSigning(unsigned long,_CERT_PUBLIC_KEY_INFO const *,ICipher *,long *,unsigned short const *,unsigned int,common::FsException *);
			};

			struct ICipher
			{
				virtual ~ICipher();
			};

			struct IExportableKey
			{
				virtual ~IExportableKey();
			};

			struct IHash
			{
				virtual ~IHash();
			};

			struct auto_bcrypt_handle_t<void *,0,CloseCngBCryptHashFunctor>
			{
				void reset(void *,unsigned char *,unsigned long);
				~auto_bcrypt_handle_t<void *,0,CloseCngBCryptHashFunctor>();
			};

			struct auto_bcrypt_handle_t<void *,0,CloseCngBCryptKeyFunctor>
			{
				void * release(unsigned char * *,unsigned long *);
				void reset(void *,unsigned char *,unsigned long);
				~auto_bcrypt_handle_t<void *,0,CloseCngBCryptKeyFunctor>();
			};

			long SetCapiPinCache(unsigned short const *,unsigned short const *,unsigned long,unsigned long,unsigned short const *);
		};

	};

};

namespace std
{
	struct _String_base
	{
		static void _Xlen();
		static void _Xran();
	};

	class bad_alloc
	{
	protected:
		virtual void _Doraise();
	public:
		bad_alloc();
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

	class out_of_range
	{
	protected:
		virtual void _Doraise();
	public:
		out_of_range(basic_string<char,char_traits<char>,allocator<char>,_STL70> const &,_STL70 *);
		out_of_range(out_of_range const &);
		virtual ~out_of_range();
	};

	class vector<ATL::CComPtr<IAlternativeName>,allocator<ATL::CComPtr<IAlternativeName> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<IAlternativeName> *,ATL::CComPtr<IAlternativeName> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<IAlternativeName>,allocator<ATL::CComPtr<IAlternativeName> > >,unsigned __int64,ATL::CComPtr<IAlternativeName> const &);
	public:
		_Vector_iterator<ATL::CComPtr<IAlternativeName>,allocator<ATL::CComPtr<IAlternativeName> > > erase(_Vector_iterator<ATL::CComPtr<IAlternativeName>,allocator<ATL::CComPtr<IAlternativeName> > >);
		_Vector_iterator<ATL::CComPtr<IAlternativeName>,allocator<ATL::CComPtr<IAlternativeName> > > erase(_Vector_iterator<ATL::CComPtr<IAlternativeName>,allocator<ATL::CComPtr<IAlternativeName> > >,_Vector_iterator<ATL::CComPtr<IAlternativeName>,allocator<ATL::CComPtr<IAlternativeName> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<IAlternativeName> const &);
		~vector<ATL::CComPtr<IAlternativeName>,allocator<ATL::CComPtr<IAlternativeName> > >();
	};

	class vector<ATL::CComPtr<ICAStatus>,allocator<ATL::CComPtr<ICAStatus> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<ICAStatus> *,ATL::CComPtr<ICAStatus> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<ICAStatus>,allocator<ATL::CComPtr<ICAStatus> > >,unsigned __int64,ATL::CComPtr<ICAStatus> const &);
	public:
		_Vector_iterator<ATL::CComPtr<ICAStatus>,allocator<ATL::CComPtr<ICAStatus> > > erase(_Vector_iterator<ATL::CComPtr<ICAStatus>,allocator<ATL::CComPtr<ICAStatus> > >);
		_Vector_iterator<ATL::CComPtr<ICAStatus>,allocator<ATL::CComPtr<ICAStatus> > > erase(_Vector_iterator<ATL::CComPtr<ICAStatus>,allocator<ATL::CComPtr<ICAStatus> > >,_Vector_iterator<ATL::CComPtr<ICAStatus>,allocator<ATL::CComPtr<ICAStatus> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<ICAStatus> const &);
		~vector<ATL::CComPtr<ICAStatus>,allocator<ATL::CComPtr<ICAStatus> > >();
	};

	class vector<ATL::CComPtr<ICertProperty>,allocator<ATL::CComPtr<ICertProperty> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<ICertProperty> *,ATL::CComPtr<ICertProperty> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<ICertProperty>,allocator<ATL::CComPtr<ICertProperty> > >,unsigned __int64,ATL::CComPtr<ICertProperty> const &);
	public:
		_Vector_iterator<ATL::CComPtr<ICertProperty>,allocator<ATL::CComPtr<ICertProperty> > > erase(_Vector_iterator<ATL::CComPtr<ICertProperty>,allocator<ATL::CComPtr<ICertProperty> > >);
		_Vector_iterator<ATL::CComPtr<ICertProperty>,allocator<ATL::CComPtr<ICertProperty> > > erase(_Vector_iterator<ATL::CComPtr<ICertProperty>,allocator<ATL::CComPtr<ICertProperty> > >,_Vector_iterator<ATL::CComPtr<ICertProperty>,allocator<ATL::CComPtr<ICertProperty> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<ICertProperty> const &);
		~vector<ATL::CComPtr<ICertProperty>,allocator<ATL::CComPtr<ICertProperty> > >();
	};

	class vector<ATL::CComPtr<ICertificatePolicy>,allocator<ATL::CComPtr<ICertificatePolicy> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<ICertificatePolicy> *,ATL::CComPtr<ICertificatePolicy> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<ICertificatePolicy>,allocator<ATL::CComPtr<ICertificatePolicy> > >,unsigned __int64,ATL::CComPtr<ICertificatePolicy> const &);
	public:
		_Vector_iterator<ATL::CComPtr<ICertificatePolicy>,allocator<ATL::CComPtr<ICertificatePolicy> > > erase(_Vector_iterator<ATL::CComPtr<ICertificatePolicy>,allocator<ATL::CComPtr<ICertificatePolicy> > >);
		_Vector_iterator<ATL::CComPtr<ICertificatePolicy>,allocator<ATL::CComPtr<ICertificatePolicy> > > erase(_Vector_iterator<ATL::CComPtr<ICertificatePolicy>,allocator<ATL::CComPtr<ICertificatePolicy> > >,_Vector_iterator<ATL::CComPtr<ICertificatePolicy>,allocator<ATL::CComPtr<ICertificatePolicy> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<ICertificatePolicy> const &);
		~vector<ATL::CComPtr<ICertificatePolicy>,allocator<ATL::CComPtr<ICertificatePolicy> > >();
	};

	class vector<ATL::CComPtr<ICertificationAuthority>,allocator<ATL::CComPtr<ICertificationAuthority> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<ICertificationAuthority> *,ATL::CComPtr<ICertificationAuthority> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<ICertificationAuthority>,allocator<ATL::CComPtr<ICertificationAuthority> > >,unsigned __int64,ATL::CComPtr<ICertificationAuthority> const &);
	public:
		_Vector_iterator<ATL::CComPtr<ICertificationAuthority>,allocator<ATL::CComPtr<ICertificationAuthority> > > erase(_Vector_iterator<ATL::CComPtr<ICertificationAuthority>,allocator<ATL::CComPtr<ICertificationAuthority> > >);
		_Vector_iterator<ATL::CComPtr<ICertificationAuthority>,allocator<ATL::CComPtr<ICertificationAuthority> > > erase(_Vector_iterator<ATL::CComPtr<ICertificationAuthority>,allocator<ATL::CComPtr<ICertificationAuthority> > >,_Vector_iterator<ATL::CComPtr<ICertificationAuthority>,allocator<ATL::CComPtr<ICertificationAuthority> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<ICertificationAuthority> const &);
		~vector<ATL::CComPtr<ICertificationAuthority>,allocator<ATL::CComPtr<ICertificationAuthority> > >();
	};

	class vector<ATL::CComPtr<ICryptAttribute>,allocator<ATL::CComPtr<ICryptAttribute> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<ICryptAttribute> *,ATL::CComPtr<ICryptAttribute> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<ICryptAttribute>,allocator<ATL::CComPtr<ICryptAttribute> > >,unsigned __int64,ATL::CComPtr<ICryptAttribute> const &);
	public:
		_Vector_iterator<ATL::CComPtr<ICryptAttribute>,allocator<ATL::CComPtr<ICryptAttribute> > > erase(_Vector_iterator<ATL::CComPtr<ICryptAttribute>,allocator<ATL::CComPtr<ICryptAttribute> > >);
		_Vector_iterator<ATL::CComPtr<ICryptAttribute>,allocator<ATL::CComPtr<ICryptAttribute> > > erase(_Vector_iterator<ATL::CComPtr<ICryptAttribute>,allocator<ATL::CComPtr<ICryptAttribute> > >,_Vector_iterator<ATL::CComPtr<ICryptAttribute>,allocator<ATL::CComPtr<ICryptAttribute> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<ICryptAttribute> const &);
		~vector<ATL::CComPtr<ICryptAttribute>,allocator<ATL::CComPtr<ICryptAttribute> > >();
	};

	class vector<ATL::CComPtr<ICspAlgorithm>,allocator<ATL::CComPtr<ICspAlgorithm> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<ICspAlgorithm> *,ATL::CComPtr<ICspAlgorithm> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<ICspAlgorithm>,allocator<ATL::CComPtr<ICspAlgorithm> > >,unsigned __int64,ATL::CComPtr<ICspAlgorithm> const &);
	public:
		_Vector_iterator<ATL::CComPtr<ICspAlgorithm>,allocator<ATL::CComPtr<ICspAlgorithm> > > erase(_Vector_iterator<ATL::CComPtr<ICspAlgorithm>,allocator<ATL::CComPtr<ICspAlgorithm> > >);
		_Vector_iterator<ATL::CComPtr<ICspAlgorithm>,allocator<ATL::CComPtr<ICspAlgorithm> > > erase(_Vector_iterator<ATL::CComPtr<ICspAlgorithm>,allocator<ATL::CComPtr<ICspAlgorithm> > >,_Vector_iterator<ATL::CComPtr<ICspAlgorithm>,allocator<ATL::CComPtr<ICspAlgorithm> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<ICspAlgorithm> const &);
		~vector<ATL::CComPtr<ICspAlgorithm>,allocator<ATL::CComPtr<ICspAlgorithm> > >();
	};

	class vector<ATL::CComPtr<ICspInformation>,allocator<ATL::CComPtr<ICspInformation> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<ICspInformation> *,ATL::CComPtr<ICspInformation> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<ICspInformation>,allocator<ATL::CComPtr<ICspInformation> > >,unsigned __int64,ATL::CComPtr<ICspInformation> const &);
	public:
		_Vector_iterator<ATL::CComPtr<ICspInformation>,allocator<ATL::CComPtr<ICspInformation> > > erase(_Vector_iterator<ATL::CComPtr<ICspInformation>,allocator<ATL::CComPtr<ICspInformation> > >);
		_Vector_iterator<ATL::CComPtr<ICspInformation>,allocator<ATL::CComPtr<ICspInformation> > > erase(_Vector_iterator<ATL::CComPtr<ICspInformation>,allocator<ATL::CComPtr<ICspInformation> > >,_Vector_iterator<ATL::CComPtr<ICspInformation>,allocator<ATL::CComPtr<ICspInformation> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<ICspInformation> const &);
		~vector<ATL::CComPtr<ICspInformation>,allocator<ATL::CComPtr<ICspInformation> > >();
	};

	class vector<ATL::CComPtr<ICspStatus>,allocator<ATL::CComPtr<ICspStatus> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<ICspStatus> *,ATL::CComPtr<ICspStatus> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<ICspStatus>,allocator<ATL::CComPtr<ICspStatus> > >,unsigned __int64,ATL::CComPtr<ICspStatus> const &);
	public:
		_Vector_iterator<ATL::CComPtr<ICspStatus>,allocator<ATL::CComPtr<ICspStatus> > > erase(_Vector_iterator<ATL::CComPtr<ICspStatus>,allocator<ATL::CComPtr<ICspStatus> > >);
		_Vector_iterator<ATL::CComPtr<ICspStatus>,allocator<ATL::CComPtr<ICspStatus> > > erase(_Vector_iterator<ATL::CComPtr<ICspStatus>,allocator<ATL::CComPtr<ICspStatus> > >,_Vector_iterator<ATL::CComPtr<ICspStatus>,allocator<ATL::CComPtr<ICspStatus> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<ICspStatus> const &);
		~vector<ATL::CComPtr<ICspStatus>,allocator<ATL::CComPtr<ICspStatus> > >();
	};

	class vector<ATL::CComPtr<IObjectId>,allocator<ATL::CComPtr<IObjectId> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<IObjectId> *,ATL::CComPtr<IObjectId> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<IObjectId>,allocator<ATL::CComPtr<IObjectId> > >,unsigned __int64,ATL::CComPtr<IObjectId> const &);
	public:
		_Vector_iterator<ATL::CComPtr<IObjectId>,allocator<ATL::CComPtr<IObjectId> > > erase(_Vector_iterator<ATL::CComPtr<IObjectId>,allocator<ATL::CComPtr<IObjectId> > >);
		_Vector_iterator<ATL::CComPtr<IObjectId>,allocator<ATL::CComPtr<IObjectId> > > erase(_Vector_iterator<ATL::CComPtr<IObjectId>,allocator<ATL::CComPtr<IObjectId> > >,_Vector_iterator<ATL::CComPtr<IObjectId>,allocator<ATL::CComPtr<IObjectId> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<IObjectId> const &);
		~vector<ATL::CComPtr<IObjectId>,allocator<ATL::CComPtr<IObjectId> > >();
	};

	class vector<ATL::CComPtr<IPolicyQualifier>,allocator<ATL::CComPtr<IPolicyQualifier> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<IPolicyQualifier> *,ATL::CComPtr<IPolicyQualifier> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<IPolicyQualifier>,allocator<ATL::CComPtr<IPolicyQualifier> > >,unsigned __int64,ATL::CComPtr<IPolicyQualifier> const &);
	public:
		_Vector_iterator<ATL::CComPtr<IPolicyQualifier>,allocator<ATL::CComPtr<IPolicyQualifier> > > erase(_Vector_iterator<ATL::CComPtr<IPolicyQualifier>,allocator<ATL::CComPtr<IPolicyQualifier> > >);
		_Vector_iterator<ATL::CComPtr<IPolicyQualifier>,allocator<ATL::CComPtr<IPolicyQualifier> > > erase(_Vector_iterator<ATL::CComPtr<IPolicyQualifier>,allocator<ATL::CComPtr<IPolicyQualifier> > >,_Vector_iterator<ATL::CComPtr<IPolicyQualifier>,allocator<ATL::CComPtr<IPolicyQualifier> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<IPolicyQualifier> const &);
		~vector<ATL::CComPtr<IPolicyQualifier>,allocator<ATL::CComPtr<IPolicyQualifier> > >();
	};

	class vector<ATL::CComPtr<ISignerCertificate>,allocator<ATL::CComPtr<ISignerCertificate> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<ISignerCertificate> *,ATL::CComPtr<ISignerCertificate> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<ISignerCertificate>,allocator<ATL::CComPtr<ISignerCertificate> > >,unsigned __int64,ATL::CComPtr<ISignerCertificate> const &);
	public:
		_Vector_iterator<ATL::CComPtr<ISignerCertificate>,allocator<ATL::CComPtr<ISignerCertificate> > > erase(_Vector_iterator<ATL::CComPtr<ISignerCertificate>,allocator<ATL::CComPtr<ISignerCertificate> > >);
		_Vector_iterator<ATL::CComPtr<ISignerCertificate>,allocator<ATL::CComPtr<ISignerCertificate> > > erase(_Vector_iterator<ATL::CComPtr<ISignerCertificate>,allocator<ATL::CComPtr<ISignerCertificate> > >,_Vector_iterator<ATL::CComPtr<ISignerCertificate>,allocator<ATL::CComPtr<ISignerCertificate> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<ISignerCertificate> const &);
		~vector<ATL::CComPtr<ISignerCertificate>,allocator<ATL::CComPtr<ISignerCertificate> > >();
	};

	class vector<ATL::CComPtr<ISmimeCapability>,allocator<ATL::CComPtr<ISmimeCapability> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<ISmimeCapability> *,ATL::CComPtr<ISmimeCapability> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<ISmimeCapability>,allocator<ATL::CComPtr<ISmimeCapability> > >,unsigned __int64,ATL::CComPtr<ISmimeCapability> const &);
	public:
		_Vector_iterator<ATL::CComPtr<ISmimeCapability>,allocator<ATL::CComPtr<ISmimeCapability> > > erase(_Vector_iterator<ATL::CComPtr<ISmimeCapability>,allocator<ATL::CComPtr<ISmimeCapability> > >);
		_Vector_iterator<ATL::CComPtr<ISmimeCapability>,allocator<ATL::CComPtr<ISmimeCapability> > > erase(_Vector_iterator<ATL::CComPtr<ISmimeCapability>,allocator<ATL::CComPtr<ISmimeCapability> > >,_Vector_iterator<ATL::CComPtr<ISmimeCapability>,allocator<ATL::CComPtr<ISmimeCapability> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<ISmimeCapability> const &);
		~vector<ATL::CComPtr<ISmimeCapability>,allocator<ATL::CComPtr<ISmimeCapability> > >();
	};

	class vector<ATL::CComPtr<IX509Attribute>,allocator<ATL::CComPtr<IX509Attribute> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<IX509Attribute> *,ATL::CComPtr<IX509Attribute> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<IX509Attribute>,allocator<ATL::CComPtr<IX509Attribute> > >,unsigned __int64,ATL::CComPtr<IX509Attribute> const &);
	public:
		_Vector_iterator<ATL::CComPtr<IX509Attribute>,allocator<ATL::CComPtr<IX509Attribute> > > erase(_Vector_iterator<ATL::CComPtr<IX509Attribute>,allocator<ATL::CComPtr<IX509Attribute> > >);
		_Vector_iterator<ATL::CComPtr<IX509Attribute>,allocator<ATL::CComPtr<IX509Attribute> > > erase(_Vector_iterator<ATL::CComPtr<IX509Attribute>,allocator<ATL::CComPtr<IX509Attribute> > >,_Vector_iterator<ATL::CComPtr<IX509Attribute>,allocator<ATL::CComPtr<IX509Attribute> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<IX509Attribute> const &);
		~vector<ATL::CComPtr<IX509Attribute>,allocator<ATL::CComPtr<IX509Attribute> > >();
	};

	class vector<ATL::CComPtr<IX509CertificateRevocationListEntry>,allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<IX509CertificateRevocationListEntry> *,ATL::CComPtr<IX509CertificateRevocationListEntry> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<IX509CertificateRevocationListEntry>,allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > >,unsigned __int64,ATL::CComPtr<IX509CertificateRevocationListEntry> const &);
	public:
		_Vector_iterator<ATL::CComPtr<IX509CertificateRevocationListEntry>,allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > > erase(_Vector_iterator<ATL::CComPtr<IX509CertificateRevocationListEntry>,allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > >);
		_Vector_iterator<ATL::CComPtr<IX509CertificateRevocationListEntry>,allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > > erase(_Vector_iterator<ATL::CComPtr<IX509CertificateRevocationListEntry>,allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > >,_Vector_iterator<ATL::CComPtr<IX509CertificateRevocationListEntry>,allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<IX509CertificateRevocationListEntry> const &);
		~vector<ATL::CComPtr<IX509CertificateRevocationListEntry>,allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > >();
	};

	class vector<ATL::CComPtr<IX509CertificateTemplate>,allocator<ATL::CComPtr<IX509CertificateTemplate> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<IX509CertificateTemplate> *,ATL::CComPtr<IX509CertificateTemplate> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<IX509CertificateTemplate>,allocator<ATL::CComPtr<IX509CertificateTemplate> > >,unsigned __int64,ATL::CComPtr<IX509CertificateTemplate> const &);
	public:
		_Vector_iterator<ATL::CComPtr<IX509CertificateTemplate>,allocator<ATL::CComPtr<IX509CertificateTemplate> > > erase(_Vector_iterator<ATL::CComPtr<IX509CertificateTemplate>,allocator<ATL::CComPtr<IX509CertificateTemplate> > >);
		_Vector_iterator<ATL::CComPtr<IX509CertificateTemplate>,allocator<ATL::CComPtr<IX509CertificateTemplate> > > erase(_Vector_iterator<ATL::CComPtr<IX509CertificateTemplate>,allocator<ATL::CComPtr<IX509CertificateTemplate> > >,_Vector_iterator<ATL::CComPtr<IX509CertificateTemplate>,allocator<ATL::CComPtr<IX509CertificateTemplate> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<IX509CertificateTemplate> const &);
		~vector<ATL::CComPtr<IX509CertificateTemplate>,allocator<ATL::CComPtr<IX509CertificateTemplate> > >();
	};

	class vector<ATL::CComPtr<IX509Enrollment>,allocator<ATL::CComPtr<IX509Enrollment> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<IX509Enrollment> *,ATL::CComPtr<IX509Enrollment> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<IX509Enrollment>,allocator<ATL::CComPtr<IX509Enrollment> > >,unsigned __int64,ATL::CComPtr<IX509Enrollment> const &);
	public:
		_Vector_iterator<ATL::CComPtr<IX509Enrollment>,allocator<ATL::CComPtr<IX509Enrollment> > > erase(_Vector_iterator<ATL::CComPtr<IX509Enrollment>,allocator<ATL::CComPtr<IX509Enrollment> > >);
		_Vector_iterator<ATL::CComPtr<IX509Enrollment>,allocator<ATL::CComPtr<IX509Enrollment> > > erase(_Vector_iterator<ATL::CComPtr<IX509Enrollment>,allocator<ATL::CComPtr<IX509Enrollment> > >,_Vector_iterator<ATL::CComPtr<IX509Enrollment>,allocator<ATL::CComPtr<IX509Enrollment> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<IX509Enrollment> const &);
		~vector<ATL::CComPtr<IX509Enrollment>,allocator<ATL::CComPtr<IX509Enrollment> > >();
	};

	class vector<ATL::CComPtr<IX509Extension>,allocator<ATL::CComPtr<IX509Extension> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<IX509Extension> *,ATL::CComPtr<IX509Extension> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<IX509Extension>,allocator<ATL::CComPtr<IX509Extension> > >,unsigned __int64,ATL::CComPtr<IX509Extension> const &);
	public:
		_Vector_iterator<ATL::CComPtr<IX509Extension>,allocator<ATL::CComPtr<IX509Extension> > > erase(_Vector_iterator<ATL::CComPtr<IX509Extension>,allocator<ATL::CComPtr<IX509Extension> > >);
		_Vector_iterator<ATL::CComPtr<IX509Extension>,allocator<ATL::CComPtr<IX509Extension> > > erase(_Vector_iterator<ATL::CComPtr<IX509Extension>,allocator<ATL::CComPtr<IX509Extension> > >,_Vector_iterator<ATL::CComPtr<IX509Extension>,allocator<ATL::CComPtr<IX509Extension> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<IX509Extension> const &);
		~vector<ATL::CComPtr<IX509Extension>,allocator<ATL::CComPtr<IX509Extension> > >();
	};

	class vector<ATL::CComPtr<IX509NameValuePair>,allocator<ATL::CComPtr<IX509NameValuePair> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<IX509NameValuePair> *,ATL::CComPtr<IX509NameValuePair> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<IX509NameValuePair>,allocator<ATL::CComPtr<IX509NameValuePair> > >,unsigned __int64,ATL::CComPtr<IX509NameValuePair> const &);
	public:
		_Vector_iterator<ATL::CComPtr<IX509NameValuePair>,allocator<ATL::CComPtr<IX509NameValuePair> > > erase(_Vector_iterator<ATL::CComPtr<IX509NameValuePair>,allocator<ATL::CComPtr<IX509NameValuePair> > >);
		_Vector_iterator<ATL::CComPtr<IX509NameValuePair>,allocator<ATL::CComPtr<IX509NameValuePair> > > erase(_Vector_iterator<ATL::CComPtr<IX509NameValuePair>,allocator<ATL::CComPtr<IX509NameValuePair> > >,_Vector_iterator<ATL::CComPtr<IX509NameValuePair>,allocator<ATL::CComPtr<IX509NameValuePair> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<IX509NameValuePair> const &);
		~vector<ATL::CComPtr<IX509NameValuePair>,allocator<ATL::CComPtr<IX509NameValuePair> > >();
	};

	class vector<ATL::CComPtr<IX509PolicyServerUrl>,allocator<ATL::CComPtr<IX509PolicyServerUrl> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(ATL::CComPtr<IX509PolicyServerUrl> *,ATL::CComPtr<IX509PolicyServerUrl> *);
		void _Insert_n(_Vector_iterator<ATL::CComPtr<IX509PolicyServerUrl>,allocator<ATL::CComPtr<IX509PolicyServerUrl> > >,unsigned __int64,ATL::CComPtr<IX509PolicyServerUrl> const &);
	public:
		_Vector_iterator<ATL::CComPtr<IX509PolicyServerUrl>,allocator<ATL::CComPtr<IX509PolicyServerUrl> > > erase(_Vector_iterator<ATL::CComPtr<IX509PolicyServerUrl>,allocator<ATL::CComPtr<IX509PolicyServerUrl> > >);
		unsigned __int64 size();
		void push_back(ATL::CComPtr<IX509PolicyServerUrl> const &);
		~vector<ATL::CComPtr<IX509PolicyServerUrl>,allocator<ATL::CComPtr<IX509PolicyServerUrl> > >();
	};

	class vector<CertEnroll::CByteArray *,allocator<CertEnroll::CByteArray *> >
	{
	protected:
		static void _Xlen();
		void _Insert_n(_Vector_iterator<CertEnroll::CByteArray *,allocator<CertEnroll::CByteArray *> >,unsigned __int64,CertEnroll::CByteArray * const &);
	public:
		unsigned __int64 size();
		void push_back(CertEnroll::CByteArray * const &);
		~vector<CertEnroll::CByteArray *,allocator<CertEnroll::CByteArray *> >();
	};

	class vector<CertEnroll::CmcAttribute *,allocator<CertEnroll::CmcAttribute *> >
	{
	protected:
		static void _Xlen();
		void _Insert_n(_Vector_iterator<CertEnroll::CmcAttribute *,allocator<CertEnroll::CmcAttribute *> >,unsigned __int64,CertEnroll::CmcAttribute * const &);
	public:
		unsigned __int64 size();
		void push_back(CertEnroll::CmcAttribute * const &);
		~vector<CertEnroll::CmcAttribute *,allocator<CertEnroll::CmcAttribute *> >();
	};

	class vector<CertEnroll::CmcStatusInfo *,allocator<CertEnroll::CmcStatusInfo *> >
	{
	protected:
		static void _Xlen();
		void _Insert_n(_Vector_iterator<CertEnroll::CmcStatusInfo *,allocator<CertEnroll::CmcStatusInfo *> >,unsigned __int64,CertEnroll::CmcStatusInfo * const &);
	public:
		unsigned __int64 size();
		void push_back(CertEnroll::CmcStatusInfo * const &);
		~vector<CertEnroll::CmcStatusInfo *,allocator<CertEnroll::CmcStatusInfo *> >();
	};

	class vector<CertEnroll::CmcTaggedAttribute *,allocator<CertEnroll::CmcTaggedAttribute *> >
	{
	protected:
		static void _Xlen();
		void _Insert_n(_Vector_iterator<CertEnroll::CmcTaggedAttribute *,allocator<CertEnroll::CmcTaggedAttribute *> >,unsigned __int64,CertEnroll::CmcTaggedAttribute * const &);
	public:
		unsigned __int64 size();
		void push_back(CertEnroll::CmcTaggedAttribute * const &);
		~vector<CertEnroll::CmcTaggedAttribute *,allocator<CertEnroll::CmcTaggedAttribute *> >();
	};

	class vector<CertEnroll::CmcTaggedContentInfo *,allocator<CertEnroll::CmcTaggedContentInfo *> >
	{
	protected:
		static void _Xlen();
		void _Insert_n(_Vector_iterator<CertEnroll::CmcTaggedContentInfo *,allocator<CertEnroll::CmcTaggedContentInfo *> >,unsigned __int64,CertEnroll::CmcTaggedContentInfo * const &);
	public:
		unsigned __int64 size();
		void push_back(CertEnroll::CmcTaggedContentInfo * const &);
		~vector<CertEnroll::CmcTaggedContentInfo *,allocator<CertEnroll::CmcTaggedContentInfo *> >();
	};

	class vector<CertEnroll::CmcTaggedRequest *,allocator<CertEnroll::CmcTaggedRequest *> >
	{
	protected:
		static void _Xlen();
		void _Insert_n(_Vector_iterator<CertEnroll::CmcTaggedRequest *,allocator<CertEnroll::CmcTaggedRequest *> >,unsigned __int64,CertEnroll::CmcTaggedRequest * const &);
	public:
		unsigned __int64 size();
		void push_back(CertEnroll::CmcTaggedRequest * const &);
		~vector<CertEnroll::CmcTaggedRequest *,allocator<CertEnroll::CmcTaggedRequest *> >();
	};

	ATL::CComPtr<IAlternativeName> * _Uninit_copy<ATL::CComPtr<IAlternativeName> *,ATL::CComPtr<IAlternativeName> *,allocator<ATL::CComPtr<IAlternativeName> > >(ATL::CComPtr<IAlternativeName> *,ATL::CComPtr<IAlternativeName> *,ATL::CComPtr<IAlternativeName> *,std::allocator<ATL::CComPtr<IAlternativeName> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<ICAStatus> * _Uninit_copy<ATL::CComPtr<ICAStatus> *,ATL::CComPtr<ICAStatus> *,allocator<ATL::CComPtr<ICAStatus> > >(ATL::CComPtr<ICAStatus> *,ATL::CComPtr<ICAStatus> *,ATL::CComPtr<ICAStatus> *,std::allocator<ATL::CComPtr<ICAStatus> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<ICertProperty> * _Uninit_copy<ATL::CComPtr<ICertProperty> *,ATL::CComPtr<ICertProperty> *,allocator<ATL::CComPtr<ICertProperty> > >(ATL::CComPtr<ICertProperty> *,ATL::CComPtr<ICertProperty> *,ATL::CComPtr<ICertProperty> *,std::allocator<ATL::CComPtr<ICertProperty> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<ICertificatePolicy> * _Uninit_copy<ATL::CComPtr<ICertificatePolicy> *,ATL::CComPtr<ICertificatePolicy> *,allocator<ATL::CComPtr<ICertificatePolicy> > >(ATL::CComPtr<ICertificatePolicy> *,ATL::CComPtr<ICertificatePolicy> *,ATL::CComPtr<ICertificatePolicy> *,std::allocator<ATL::CComPtr<ICertificatePolicy> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<ICertificationAuthority> * _Uninit_copy<ATL::CComPtr<ICertificationAuthority> *,ATL::CComPtr<ICertificationAuthority> *,allocator<ATL::CComPtr<ICertificationAuthority> > >(ATL::CComPtr<ICertificationAuthority> *,ATL::CComPtr<ICertificationAuthority> *,ATL::CComPtr<ICertificationAuthority> *,std::allocator<ATL::CComPtr<ICertificationAuthority> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<ICryptAttribute> * _Uninit_copy<ATL::CComPtr<ICryptAttribute> *,ATL::CComPtr<ICryptAttribute> *,allocator<ATL::CComPtr<ICryptAttribute> > >(ATL::CComPtr<ICryptAttribute> *,ATL::CComPtr<ICryptAttribute> *,ATL::CComPtr<ICryptAttribute> *,std::allocator<ATL::CComPtr<ICryptAttribute> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<ICspAlgorithm> * _Uninit_copy<ATL::CComPtr<ICspAlgorithm> *,ATL::CComPtr<ICspAlgorithm> *,allocator<ATL::CComPtr<ICspAlgorithm> > >(ATL::CComPtr<ICspAlgorithm> *,ATL::CComPtr<ICspAlgorithm> *,ATL::CComPtr<ICspAlgorithm> *,std::allocator<ATL::CComPtr<ICspAlgorithm> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<ICspInformation> * _Uninit_copy<ATL::CComPtr<ICspInformation> *,ATL::CComPtr<ICspInformation> *,allocator<ATL::CComPtr<ICspInformation> > >(ATL::CComPtr<ICspInformation> *,ATL::CComPtr<ICspInformation> *,ATL::CComPtr<ICspInformation> *,std::allocator<ATL::CComPtr<ICspInformation> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<ICspStatus> * _Uninit_copy<ATL::CComPtr<ICspStatus> *,ATL::CComPtr<ICspStatus> *,allocator<ATL::CComPtr<ICspStatus> > >(ATL::CComPtr<ICspStatus> *,ATL::CComPtr<ICspStatus> *,ATL::CComPtr<ICspStatus> *,std::allocator<ATL::CComPtr<ICspStatus> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<IObjectId> * _Uninit_copy<ATL::CComPtr<IObjectId> *,ATL::CComPtr<IObjectId> *,allocator<ATL::CComPtr<IObjectId> > >(ATL::CComPtr<IObjectId> *,ATL::CComPtr<IObjectId> *,ATL::CComPtr<IObjectId> *,std::allocator<ATL::CComPtr<IObjectId> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<IPolicyQualifier> * _Uninit_copy<ATL::CComPtr<IPolicyQualifier> *,ATL::CComPtr<IPolicyQualifier> *,allocator<ATL::CComPtr<IPolicyQualifier> > >(ATL::CComPtr<IPolicyQualifier> *,ATL::CComPtr<IPolicyQualifier> *,ATL::CComPtr<IPolicyQualifier> *,std::allocator<ATL::CComPtr<IPolicyQualifier> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<ISignerCertificate> * _Uninit_copy<ATL::CComPtr<ISignerCertificate> *,ATL::CComPtr<ISignerCertificate> *,allocator<ATL::CComPtr<ISignerCertificate> > >(ATL::CComPtr<ISignerCertificate> *,ATL::CComPtr<ISignerCertificate> *,ATL::CComPtr<ISignerCertificate> *,std::allocator<ATL::CComPtr<ISignerCertificate> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<ISmimeCapability> * _Uninit_copy<ATL::CComPtr<ISmimeCapability> *,ATL::CComPtr<ISmimeCapability> *,allocator<ATL::CComPtr<ISmimeCapability> > >(ATL::CComPtr<ISmimeCapability> *,ATL::CComPtr<ISmimeCapability> *,ATL::CComPtr<ISmimeCapability> *,std::allocator<ATL::CComPtr<ISmimeCapability> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<IX509Attribute> * _Uninit_copy<ATL::CComPtr<IX509Attribute> *,ATL::CComPtr<IX509Attribute> *,allocator<ATL::CComPtr<IX509Attribute> > >(ATL::CComPtr<IX509Attribute> *,ATL::CComPtr<IX509Attribute> *,ATL::CComPtr<IX509Attribute> *,std::allocator<ATL::CComPtr<IX509Attribute> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<IX509CertificateRevocationListEntry> * _Uninit_copy<ATL::CComPtr<IX509CertificateRevocationListEntry> *,ATL::CComPtr<IX509CertificateRevocationListEntry> *,allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > >(ATL::CComPtr<IX509CertificateRevocationListEntry> *,ATL::CComPtr<IX509CertificateRevocationListEntry> *,ATL::CComPtr<IX509CertificateRevocationListEntry> *,std::allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<IX509CertificateTemplate> * _Uninit_copy<ATL::CComPtr<IX509CertificateTemplate> *,ATL::CComPtr<IX509CertificateTemplate> *,allocator<ATL::CComPtr<IX509CertificateTemplate> > >(ATL::CComPtr<IX509CertificateTemplate> *,ATL::CComPtr<IX509CertificateTemplate> *,ATL::CComPtr<IX509CertificateTemplate> *,std::allocator<ATL::CComPtr<IX509CertificateTemplate> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<IX509Enrollment> * _Uninit_copy<ATL::CComPtr<IX509Enrollment> *,ATL::CComPtr<IX509Enrollment> *,allocator<ATL::CComPtr<IX509Enrollment> > >(ATL::CComPtr<IX509Enrollment> *,ATL::CComPtr<IX509Enrollment> *,ATL::CComPtr<IX509Enrollment> *,std::allocator<ATL::CComPtr<IX509Enrollment> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<IX509Extension> * _Uninit_copy<ATL::CComPtr<IX509Extension> *,ATL::CComPtr<IX509Extension> *,allocator<ATL::CComPtr<IX509Extension> > >(ATL::CComPtr<IX509Extension> *,ATL::CComPtr<IX509Extension> *,ATL::CComPtr<IX509Extension> *,std::allocator<ATL::CComPtr<IX509Extension> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<IX509NameValuePair> * _Uninit_copy<ATL::CComPtr<IX509NameValuePair> *,ATL::CComPtr<IX509NameValuePair> *,allocator<ATL::CComPtr<IX509NameValuePair> > >(ATL::CComPtr<IX509NameValuePair> *,ATL::CComPtr<IX509NameValuePair> *,ATL::CComPtr<IX509NameValuePair> *,std::allocator<ATL::CComPtr<IX509NameValuePair> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	ATL::CComPtr<IX509PolicyServerUrl> * _Uninit_copy<ATL::CComPtr<IX509PolicyServerUrl> *,ATL::CComPtr<IX509PolicyServerUrl> *,allocator<ATL::CComPtr<IX509PolicyServerUrl> > >(ATL::CComPtr<IX509PolicyServerUrl> *,ATL::CComPtr<IX509PolicyServerUrl> *,ATL::CComPtr<IX509PolicyServerUrl> *,std::allocator<ATL::CComPtr<IX509PolicyServerUrl> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	char * _Allocate<char>(unsigned __int64,char *);
	char const * const _bad_alloc_Message;
	nothrow_t const std::nothrow;
	void _Uninit_fill_n<ATL::CComPtr<IAlternativeName> *,unsigned __int64,ATL::CComPtr<IAlternativeName>,allocator<ATL::CComPtr<IAlternativeName> > >(ATL::CComPtr<IAlternativeName> *,unsigned __int64,ATL::CComPtr<IAlternativeName> const &,std::allocator<ATL::CComPtr<IAlternativeName> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<ICAStatus> *,unsigned __int64,ATL::CComPtr<ICAStatus>,allocator<ATL::CComPtr<ICAStatus> > >(ATL::CComPtr<ICAStatus> *,unsigned __int64,ATL::CComPtr<ICAStatus> const &,std::allocator<ATL::CComPtr<ICAStatus> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<ICertProperty> *,unsigned __int64,ATL::CComPtr<ICertProperty>,allocator<ATL::CComPtr<ICertProperty> > >(ATL::CComPtr<ICertProperty> *,unsigned __int64,ATL::CComPtr<ICertProperty> const &,std::allocator<ATL::CComPtr<ICertProperty> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<ICertificatePolicy> *,unsigned __int64,ATL::CComPtr<ICertificatePolicy>,allocator<ATL::CComPtr<ICertificatePolicy> > >(ATL::CComPtr<ICertificatePolicy> *,unsigned __int64,ATL::CComPtr<ICertificatePolicy> const &,std::allocator<ATL::CComPtr<ICertificatePolicy> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<ICertificationAuthority> *,unsigned __int64,ATL::CComPtr<ICertificationAuthority>,allocator<ATL::CComPtr<ICertificationAuthority> > >(ATL::CComPtr<ICertificationAuthority> *,unsigned __int64,ATL::CComPtr<ICertificationAuthority> const &,std::allocator<ATL::CComPtr<ICertificationAuthority> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<ICryptAttribute> *,unsigned __int64,ATL::CComPtr<ICryptAttribute>,allocator<ATL::CComPtr<ICryptAttribute> > >(ATL::CComPtr<ICryptAttribute> *,unsigned __int64,ATL::CComPtr<ICryptAttribute> const &,std::allocator<ATL::CComPtr<ICryptAttribute> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<ICspAlgorithm> *,unsigned __int64,ATL::CComPtr<ICspAlgorithm>,allocator<ATL::CComPtr<ICspAlgorithm> > >(ATL::CComPtr<ICspAlgorithm> *,unsigned __int64,ATL::CComPtr<ICspAlgorithm> const &,std::allocator<ATL::CComPtr<ICspAlgorithm> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<ICspInformation> *,unsigned __int64,ATL::CComPtr<ICspInformation>,allocator<ATL::CComPtr<ICspInformation> > >(ATL::CComPtr<ICspInformation> *,unsigned __int64,ATL::CComPtr<ICspInformation> const &,std::allocator<ATL::CComPtr<ICspInformation> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<ICspStatus> *,unsigned __int64,ATL::CComPtr<ICspStatus>,allocator<ATL::CComPtr<ICspStatus> > >(ATL::CComPtr<ICspStatus> *,unsigned __int64,ATL::CComPtr<ICspStatus> const &,std::allocator<ATL::CComPtr<ICspStatus> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<IObjectId> *,unsigned __int64,ATL::CComPtr<IObjectId>,allocator<ATL::CComPtr<IObjectId> > >(ATL::CComPtr<IObjectId> *,unsigned __int64,ATL::CComPtr<IObjectId> const &,std::allocator<ATL::CComPtr<IObjectId> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<IPolicyQualifier> *,unsigned __int64,ATL::CComPtr<IPolicyQualifier>,allocator<ATL::CComPtr<IPolicyQualifier> > >(ATL::CComPtr<IPolicyQualifier> *,unsigned __int64,ATL::CComPtr<IPolicyQualifier> const &,std::allocator<ATL::CComPtr<IPolicyQualifier> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<ISignerCertificate> *,unsigned __int64,ATL::CComPtr<ISignerCertificate>,allocator<ATL::CComPtr<ISignerCertificate> > >(ATL::CComPtr<ISignerCertificate> *,unsigned __int64,ATL::CComPtr<ISignerCertificate> const &,std::allocator<ATL::CComPtr<ISignerCertificate> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<ISmimeCapability> *,unsigned __int64,ATL::CComPtr<ISmimeCapability>,allocator<ATL::CComPtr<ISmimeCapability> > >(ATL::CComPtr<ISmimeCapability> *,unsigned __int64,ATL::CComPtr<ISmimeCapability> const &,std::allocator<ATL::CComPtr<ISmimeCapability> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<IX509Attribute> *,unsigned __int64,ATL::CComPtr<IX509Attribute>,allocator<ATL::CComPtr<IX509Attribute> > >(ATL::CComPtr<IX509Attribute> *,unsigned __int64,ATL::CComPtr<IX509Attribute> const &,std::allocator<ATL::CComPtr<IX509Attribute> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<IX509CertificateRevocationListEntry> *,unsigned __int64,ATL::CComPtr<IX509CertificateRevocationListEntry>,allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > >(ATL::CComPtr<IX509CertificateRevocationListEntry> *,unsigned __int64,ATL::CComPtr<IX509CertificateRevocationListEntry> const &,std::allocator<ATL::CComPtr<IX509CertificateRevocationListEntry> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<IX509CertificateTemplate> *,unsigned __int64,ATL::CComPtr<IX509CertificateTemplate>,allocator<ATL::CComPtr<IX509CertificateTemplate> > >(ATL::CComPtr<IX509CertificateTemplate> *,unsigned __int64,ATL::CComPtr<IX509CertificateTemplate> const &,std::allocator<ATL::CComPtr<IX509CertificateTemplate> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<IX509Enrollment> *,unsigned __int64,ATL::CComPtr<IX509Enrollment>,allocator<ATL::CComPtr<IX509Enrollment> > >(ATL::CComPtr<IX509Enrollment> *,unsigned __int64,ATL::CComPtr<IX509Enrollment> const &,std::allocator<ATL::CComPtr<IX509Enrollment> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<IX509Extension> *,unsigned __int64,ATL::CComPtr<IX509Extension>,allocator<ATL::CComPtr<IX509Extension> > >(ATL::CComPtr<IX509Extension> *,unsigned __int64,ATL::CComPtr<IX509Extension> const &,std::allocator<ATL::CComPtr<IX509Extension> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<IX509NameValuePair> *,unsigned __int64,ATL::CComPtr<IX509NameValuePair>,allocator<ATL::CComPtr<IX509NameValuePair> > >(ATL::CComPtr<IX509NameValuePair> *,unsigned __int64,ATL::CComPtr<IX509NameValuePair> const &,std::allocator<ATL::CComPtr<IX509NameValuePair> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<ATL::CComPtr<IX509PolicyServerUrl> *,unsigned __int64,ATL::CComPtr<IX509PolicyServerUrl>,allocator<ATL::CComPtr<IX509PolicyServerUrl> > >(ATL::CComPtr<IX509PolicyServerUrl> *,unsigned __int64,ATL::CComPtr<IX509PolicyServerUrl> const &,std::allocator<ATL::CComPtr<IX509PolicyServerUrl> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void fill<ATL::CComPtr<IAlternativeName> *,ATL::CComPtr<IAlternativeName> >(ATL::CComPtr<IAlternativeName> *,ATL::CComPtr<IAlternativeName> *,ATL::CComPtr<IAlternativeName> const &);
	void fill<ATL::CComPtr<ICAStatus> *,ATL::CComPtr<ICAStatus> >(ATL::CComPtr<ICAStatus> *,ATL::CComPtr<ICAStatus> *,ATL::CComPtr<ICAStatus> const &);
	void fill<ATL::CComPtr<ICertProperty> *,ATL::CComPtr<ICertProperty> >(ATL::CComPtr<ICertProperty> *,ATL::CComPtr<ICertProperty> *,ATL::CComPtr<ICertProperty> const &);
	void fill<ATL::CComPtr<ICertificatePolicy> *,ATL::CComPtr<ICertificatePolicy> >(ATL::CComPtr<ICertificatePolicy> *,ATL::CComPtr<ICertificatePolicy> *,ATL::CComPtr<ICertificatePolicy> const &);
	void fill<ATL::CComPtr<ICertificationAuthority> *,ATL::CComPtr<ICertificationAuthority> >(ATL::CComPtr<ICertificationAuthority> *,ATL::CComPtr<ICertificationAuthority> *,ATL::CComPtr<ICertificationAuthority> const &);
	void fill<ATL::CComPtr<ICryptAttribute> *,ATL::CComPtr<ICryptAttribute> >(ATL::CComPtr<ICryptAttribute> *,ATL::CComPtr<ICryptAttribute> *,ATL::CComPtr<ICryptAttribute> const &);
	void fill<ATL::CComPtr<ICspAlgorithm> *,ATL::CComPtr<ICspAlgorithm> >(ATL::CComPtr<ICspAlgorithm> *,ATL::CComPtr<ICspAlgorithm> *,ATL::CComPtr<ICspAlgorithm> const &);
	void fill<ATL::CComPtr<ICspInformation> *,ATL::CComPtr<ICspInformation> >(ATL::CComPtr<ICspInformation> *,ATL::CComPtr<ICspInformation> *,ATL::CComPtr<ICspInformation> const &);
	void fill<ATL::CComPtr<ICspStatus> *,ATL::CComPtr<ICspStatus> >(ATL::CComPtr<ICspStatus> *,ATL::CComPtr<ICspStatus> *,ATL::CComPtr<ICspStatus> const &);
	void fill<ATL::CComPtr<IObjectId> *,ATL::CComPtr<IObjectId> >(ATL::CComPtr<IObjectId> *,ATL::CComPtr<IObjectId> *,ATL::CComPtr<IObjectId> const &);
	void fill<ATL::CComPtr<IPolicyQualifier> *,ATL::CComPtr<IPolicyQualifier> >(ATL::CComPtr<IPolicyQualifier> *,ATL::CComPtr<IPolicyQualifier> *,ATL::CComPtr<IPolicyQualifier> const &);
	void fill<ATL::CComPtr<ISignerCertificate> *,ATL::CComPtr<ISignerCertificate> >(ATL::CComPtr<ISignerCertificate> *,ATL::CComPtr<ISignerCertificate> *,ATL::CComPtr<ISignerCertificate> const &);
	void fill<ATL::CComPtr<ISmimeCapability> *,ATL::CComPtr<ISmimeCapability> >(ATL::CComPtr<ISmimeCapability> *,ATL::CComPtr<ISmimeCapability> *,ATL::CComPtr<ISmimeCapability> const &);
	void fill<ATL::CComPtr<IX509Attribute> *,ATL::CComPtr<IX509Attribute> >(ATL::CComPtr<IX509Attribute> *,ATL::CComPtr<IX509Attribute> *,ATL::CComPtr<IX509Attribute> const &);
	void fill<ATL::CComPtr<IX509CertificateRevocationListEntry> *,ATL::CComPtr<IX509CertificateRevocationListEntry> >(ATL::CComPtr<IX509CertificateRevocationListEntry> *,ATL::CComPtr<IX509CertificateRevocationListEntry> *,ATL::CComPtr<IX509CertificateRevocationListEntry> const &);
	void fill<ATL::CComPtr<IX509CertificateTemplate> *,ATL::CComPtr<IX509CertificateTemplate> >(ATL::CComPtr<IX509CertificateTemplate> *,ATL::CComPtr<IX509CertificateTemplate> *,ATL::CComPtr<IX509CertificateTemplate> const &);
	void fill<ATL::CComPtr<IX509Enrollment> *,ATL::CComPtr<IX509Enrollment> >(ATL::CComPtr<IX509Enrollment> *,ATL::CComPtr<IX509Enrollment> *,ATL::CComPtr<IX509Enrollment> const &);
	void fill<ATL::CComPtr<IX509Extension> *,ATL::CComPtr<IX509Extension> >(ATL::CComPtr<IX509Extension> *,ATL::CComPtr<IX509Extension> *,ATL::CComPtr<IX509Extension> const &);
	void fill<ATL::CComPtr<IX509NameValuePair> *,ATL::CComPtr<IX509NameValuePair> >(ATL::CComPtr<IX509NameValuePair> *,ATL::CComPtr<IX509NameValuePair> *,ATL::CComPtr<IX509NameValuePair> const &);
	void fill<ATL::CComPtr<IX509PolicyServerUrl> *,ATL::CComPtr<IX509PolicyServerUrl> >(ATL::CComPtr<IX509PolicyServerUrl> *,ATL::CComPtr<IX509PolicyServerUrl> *,ATL::CComPtr<IX509PolicyServerUrl> const &);
};

struct struct_join_status
{
	struct_join_status();
	~struct_join_status();
};

namespace wil
{
	namespace details
	{
		namespace in1diag3
		{
			long Return_NtStatus(void *,unsigned int,char const *,long);
			long Return_Win32(void *,unsigned int,char const *,unsigned long);
			void Return_Hr(void *,unsigned int,char const *,long);
			void Return_Hr_NoOriginate(void *,unsigned int,char const *,long);
			void _FailFastImmediate_Unexpected();
		};

		bool GetModuleInformation(void *,unsigned int *,char *,unsigned __int64);
		bool g_resultMessageCallbackSet;
		char const * (* g_pfnGetModuleName)();
		char const * GetCurrentModuleName();
		int RecordException(long);
		int RecordFailFast(long);
		int RecordLog(long);
		int RecordReturn(long);
		long NtStatusToHr(long);
		long ReportFailure_NtStatus(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long);
		long ReportFailure_Win32(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,unsigned long);
		unsigned long (* g_pfnRtlNtStatusToDosErrorNoTeb)(long);
		unsigned long RtlNtStatusToDosErrorNoTeb(long);
		unsigned short * LogStringPrintf(unsigned short *,unsigned short const *,unsigned short const *,...);
		void (* g_pfnDebugBreak)();
		void (* g_pfnGetContextAndNotifyFailure)(FailureInfo *,char *,unsigned __int64);
		void (* g_pfnLoggingCallback)(FailureInfo const &);
		void (* g_pfnOriginateCallback)(FailureType,long);
		void (* g_pfnThrowResultException)(FailureInfo const &);
		void DebugBreak();
		void LogFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,unsigned short const *,bool,unsigned short *,unsigned __int64,char *,unsigned __int64,FailureInfo *);
		void OriginateError(FailureType,long);
		void ReportFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,unsigned short const *,details::ReportFailureOptions);
		void ReportFailure_Hr(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long);
	};

	bool (* g_pfnIsDebuggerPresent)();
	bool g_fBreakOnFailure;
	bool g_fIsDebuggerPresent;
	long GetFailureLogString(unsigned short *,unsigned __int64,wil::FailureInfo const &);
};

ATL::CComModule _Module;
ATL::CSimpleArray<unsigned short *,ATL::CSimpleArrayEqualHelper<unsigned short *> > g_arrStrAppName;
CAnonymousCred g_AnonymousCred;
CMemVault g_MemVault;
CertSrv::CEventLog g_Event;
HINSTANCE__ * g_hInstance;
HINSTANCE__ * g_wil_details_ntdllModuleHandle;
HINSTANCE__ * myLoadSystem32LibraryEx(unsigned short const *,void *,unsigned long);
HINSTANCE__ * s_hMuiInstance;
HINSTANCE__ * wil_details_GetNtDllModuleHandle();
OID * FindOid(OID *,unsigned int,int);
WS_SECURITY_TIMESTAMP_USAGE TimeStampUsage;
_AE_CERTTYPE_INFO_ * AEFindTemplateInRequestTreeByCepId(_AE_TEMPLATE_INFO_ const *,_AE_GENERAL_INFO_ const *,unsigned short *);
_AE_CERTTYPE_INFO_ * AEFindTemplateInRequestTreeByCert(_AE_TEMPLATE_INFO_ *,_AE_GENERAL_INFO_ *,_CERT_CONTEXT const *);
_AE_GENERAL_INFO_ * CertRetrieveGeneralInfo(X509CertificateEnrollmentContext,bool,bool,ATL::CSimpleArray<CEPTemplate,ATL::CSimpleArrayEqualHelper<CEPTemplate> > &,_CERT_TEMPLATE_STATUS *);
_CERT_CONTEXT const * FindCertificateInOtherStore(void *,_CERT_CONTEXT const *);
_CERT_CONTEXT const * myDuplicateNewestCert(_CERT_CONTEXT const *,_CERT_CONTEXT const *);
_CERT_CONTEXT const * mySelectCertificate(unsigned long,tagCRYPTUI_SELECTCERTIFICATE_STRUCTW *);
_CRYPT_OID_INFO const * fsCryptFindOIDInfo(unsigned long,void *,unsigned long);
_CSLDAPERROR * s_LdapTable;
_CSREGKEY * g_rgRegKey;
_CSREGKEY g_RegKeyConfig;
_DUMPFLAGS * g_adfChainFlags;
_DUMPFLAGS * g_adfErrorStatus;
_DUMPFLAGS * g_adfInfoStatus;
_DUMPFLAGS * g_adfVerifyFlags;
_DUMPPROP * s_apwszPropIds;
_GUID CLSID_IsolatedMessageDialogFactory;
_GUID const GUID_CAUSALITY_WINDOWS_PLATFORM_ID;
_IAMETHOD * g_rgIAMethods;
_OIDENCODEMAP * s_aEncode;
_OIDNAME * s_aOIDName;
_RESOURCESTRING * g_rgrs;
_RTL_CRITICAL_SECTION g_InitLogCriticalSection;
_STOREMAP * s_aStoreMap;
_UNITSTABLE * g_aut;
_WS_CHANNEL_PROPERTY * channelPropertiesArray;
_WS_SECURITY_PROPERTY * securityProperties;
_iobuf * g_pfLog;
bool AEArchiveObsoleteCertificates(_AE_GENERAL_INFO_ *);
bool AECheckPendingRequests(_AE_GENERAL_INFO_ *);
bool AECheckSupersedeRequest(_AE_CERTTYPE_INFO_ *,_AE_CERTTYPE_INFO_ *,_AE_GENERAL_INFO_ *);
bool AECheckUserDSStore(_AE_GENERAL_INFO_ *);
bool AEGetPolicyFlag(bool,bool *,unsigned long *);
bool AEIsDeletableCert(_CERT_CONTEXT const *,_AE_GENERAL_INFO_ *);
bool AEIsFromGroupPolicyCEP(_CERT_CONTEXT const *,bool);
bool AEIsGPConfiguredAndTrusted(unsigned short *,bool);
bool AEIsSameTemplate(_CERT_CONTEXT const *,_AE_CERTTYPE_INFO_ *,bool);
bool AEIsSupersedeTemplate(_CERT_CONTEXT const *,_AE_CERTTYPE_INFO_ *,_AE_GENERAL_INFO_ *);
bool AEManageActiveTemplates(_AE_GENERAL_INFO_ *);
bool AEManageAndMarkMyStore(_AE_GENERAL_INFO_ *);
bool AEManageSupersedeRequests(_AE_GENERAL_INFO_ *);
bool AEMarkACRS(_AE_GENERAL_INFO_ *);
bool AEMarkAutoenrollment(_AE_GENERAL_INFO_ *);
bool AESameOID(unsigned short *,char *);
bool AEUpdateRetryProperty(_AE_GENERAL_INFO_ *,_CERT_CONTEXT const *,_CERT_CONTEXT const *);
bool AEValidRAPolicy(_CERT_CONTEXT const *,_AE_CERTTYPE_INFO_ *);
bool AEValidRAPolicyWithProperty(_CERT_CONTEXT const *,IObjectIds *,IObjectIds *);
bool AEValidateCertificateInfo(_AE_GENERAL_INFO_ *,_AE_CERTTYPE_INFO_ *,bool,_CERT_CONTEXT const *,_AE_CERT_INFO_ *,bool *);
bool AEVerifyCertMatchesLogonKey(_CERT_CONTEXT const *);
bool AEVerifyDNSName(_AE_GENERAL_INFO_ *,_CERT_CONTEXT const *);
bool AEVerifyDNSNameWithRetry(_AE_GENERAL_INFO_ *,_CERT_CONTEXT const *);
bool DM_IsKeyRoamingEnabled();
bool DM_IsOriginalEnroller(_CERT_CONTEXT const *,_AE_GENERAL_INFO_ const *);
bool FindASNIndefiniteEndRecord(unsigned char const *,unsigned long,unsigned long *);
bool HasCepPropertyCepId(_CERT_CONTEXT const *);
bool HasExeSuffix(unsigned short const *);
bool InvertCase(unsigned short,unsigned short *);
bool IsAES();
bool IsEnvDirWriteable(unsigned short const *);
bool IsHttp(unsigned short const *);
bool IsHttps(unsigned short const *);
bool IsLdapUri(unsigned short const *);
bool IsWebServer(unsigned short const *);
bool UnicodeEnabled();
bool ceSkipEventLog(unsigned long,X509CertificateEnrollmentContext);
bool cpNameMatchFilterEKUObjIdA(char const *,CERTFILTERSTRING const *);
bool g_fWebCaller;
bool myIsSigningKeySpec(X509KeySpec);
bool myIsSmartCardProvider(unsigned long,unsigned long);
bool myRegPeriodExpired(_FILETIME *);
bool ocscpy_s(unsigned short *,unsigned __int64,unsigned short const *);
bool s_fMuiLoaded;
char const * * s_rgpszRDNObjectId;
csp_hash_tag * newHashInfoFromCryptOidInfo(bool,_CRYPT_OID_INFO const *);
int CertificateFilterProc(_CERT_CONTEXT const *,int *,void *);
int CompareLangIDs(void const *,void const *);
int CompareLangName(void const *,void const *);
int ConvertWszToMultiByte(char * *,unsigned int,unsigned short const *,long);
int CryptConvertIriToAsciiOrUnicode(unsigned long,unsigned short const *,unsigned short * *);
int FindTPMRDNIndex(_CERT_RDN const *);
int InlineIsEqualGUID(_GUID const &,_GUID const &);
int IsConsentCacheNotExist(unsigned short *);
int IsDomainMachine();
int IsPrefix(unsigned short const *,unsigned short const *,unsigned long);
int IsWinPEHost();
int SafeFree(void *);
int crOIDEnumWorker(_CRYPT_OID_INFO const *,void *);
int fnTPMRDNSort(void const *,void const *);
int fsCryptAcquireContext(unsigned __int64 *,unsigned short const *,unsigned short const *,unsigned long,unsigned long);
int fsCryptCreateHash(unsigned __int64,unsigned int,unsigned __int64,unsigned long,unsigned __int64 *);
int fsCryptDecrypt(unsigned __int64,unsigned __int64,int,unsigned long,unsigned char *,unsigned long *);
int fsCryptDestroyHash(unsigned __int64);
int fsCryptDestroyKey(unsigned __int64);
int fsCryptEncrypt(unsigned __int64,unsigned __int64,int,unsigned long,unsigned char *,unsigned long *,unsigned long);
int fsCryptExportKey(unsigned __int64,unsigned __int64,unsigned long,unsigned long,unsigned char *,unsigned long *);
int fsCryptGetHashParam(unsigned __int64,unsigned long,unsigned char *,unsigned long *,unsigned long);
int fsCryptGetKeyParam(unsigned __int64,unsigned long,unsigned char *,unsigned long *,unsigned long);
int fsCryptGetProvParam(unsigned __int64,unsigned long,unsigned char *,unsigned long *,unsigned long);
int fsCryptGetUserKey(unsigned __int64,unsigned long,unsigned __int64 *);
int fsCryptHashData(unsigned __int64,unsigned char const *,unsigned long,unsigned long);
int fsCryptImportKey(unsigned __int64,unsigned char const *,unsigned long,unsigned __int64,unsigned long,unsigned __int64 *);
int fsCryptImportPublicKeyInfo(unsigned __int64,unsigned long,_CERT_PUBLIC_KEY_INFO *,unsigned __int64 *);
int fsCryptImportPublicKeyInfoEx2(unsigned long,_CERT_PUBLIC_KEY_INFO *,unsigned long,void *,void * *);
int fsCryptReleaseContext(unsigned __int64,unsigned long);
int fsCryptSetHashParam(unsigned __int64,unsigned long,unsigned char const *,unsigned long);
int fsCryptSetKeyParam(unsigned __int64,unsigned long,unsigned char const *,unsigned long);
int fsCryptSetProvParam(unsigned __int64,unsigned long,unsigned char const *,unsigned long);
int fsCryptSignHash(unsigned __int64,unsigned long,unsigned short const *,unsigned long,unsigned char *,unsigned long *);
int fsCryptVerifySignature(unsigned __int64,unsigned char const *,unsigned long,unsigned __int64,unsigned short const *,unsigned long);
int g_fErrLogInitialized;
int g_fInitLogCritSecEnabled;
int g_fLogClosed;
int g_fLogErrorsToDebugger;
int g_fLogErrorsToFile;
int g_fLogWarnings;
int myAreBlobsSame(unsigned char const *,unsigned long,unsigned char const *,unsigned long);
int myAreSerialNumberBlobsSame(_CRYPTOAPI_BLOB const *,_CRYPTOAPI_BLOB const *);
int myCertComparePublicKeyInfo(unsigned long,int,_CERT_PUBLIC_KEY_INFO const *,_CERT_PUBLIC_KEY_INFO const *);
int myCertGetCertificateContextProperty(_CERT_CONTEXT const *,unsigned long,CERTLIB_ALLOCATOR,unsigned char * *,unsigned long *);
int myCertSrvCryptAcquireContext(unsigned __int64 *,unsigned short const *,unsigned short const *,unsigned long,unsigned long,int);
int myConsolePrintf(unsigned short const *,...);
int myConvertMultiByteToWsz(unsigned short * *,unsigned int,char const *,long);
int myConvertSzToBstr(unsigned short * *,char const *,long);
int myConvertSzToWsz(unsigned short * *,char const *,long);
int myConvertWszToBstr(unsigned short * *,unsigned short const *,long);
int myConvertWszToSz(char * *,unsigned short const *,long);
int myCryptExportPublicKeyInfo2(unsigned __int64,unsigned long,unsigned long,CERTLIB_ALLOCATOR,_CERT_PUBLIC_KEY_INFO * *,unsigned long *);
int myCryptHashCertificate(unsigned __int64,unsigned int,unsigned long,unsigned char const *,unsigned long,unsigned char * *,unsigned long *);
int myCryptHashCertificate2(unsigned short const *,unsigned long,void *,unsigned char const *,unsigned long,unsigned char * *,unsigned long *);
int myCryptSignCertificate(unsigned __int64,unsigned long,unsigned long,unsigned char const *,unsigned long,_CRYPT_ALGORITHM_IDENTIFIER const *,CERTLIB_ALLOCATOR,unsigned char * *,unsigned long *);
int myCryptSignMessage(_CRYPT_SIGN_MESSAGE_PARA const *,unsigned char const *,unsigned long,CERTLIB_ALLOCATOR,unsigned char * *,unsigned long *);
int myDecodeObjectEx(unsigned long,char const *,unsigned char const *,unsigned long,unsigned long,CERTLIB_ALLOCATOR,void * *,unsigned long *);
int myEncodeObject(unsigned long,char const *,void const *,unsigned long,CERTLIB_ALLOCATOR,unsigned char * *,unsigned long *);
int myEncodeUrl(unsigned short const *,unsigned long,CERTLIB_ALLOCATOR,unsigned char * *,unsigned long *);
int myEnumProcesses(unsigned long *,unsigned long,unsigned long *);
int myIsCharSanitized(unsigned short);
int myWtoI(unsigned short const *,int *);
int mylstrcmpNL(unsigned short const *,unsigned short const *,int);
int mylstrcmpNLSub(unsigned short const *,unsigned short const *,int,bool);
int mylstrcmpiNL(unsigned short const *,unsigned short const *,int);
int ocslen(unsigned short const *);
key_list_tag * newKey(unsigned short const *,unsigned long);
key_list_tag * newKeyA(char const *);
long AECanEnrollCertType(_AE_CERTTYPE_INFO_ *,_AE_GENERAL_INFO_ *);
long AECertificateChain(void *,_CERT_CONTEXT const *,_FILETIME *,bool,bool,long *);
long AddCertToStore(_CERT_CONTEXT const *,void *);
long AddConsent(unsigned short *);
long AddPkcs10Extension(Windows::Security::Cryptography::Certificates::ICertificateExtension *,IX509CertificateRequestPkcs10 *);
long AllocateStringBuffer(unsigned short *,unsigned long *,unsigned short * *);
long CEEventLogAuthentication(unsigned long,unsigned long,X509CertificateEnrollmentContext,unsigned short const *,unsigned short const *,unsigned short const *,X509EnrollmentAuthFlags,long);
long CEEventLogFailGroupAuthentication(unsigned long,unsigned long,X509CertificateEnrollmentContext,unsigned short const *,IX509CertificateTemplateInternal *,long);
long CEGetUserName(bool,unsigned short * *);
long CanonicalizeDN(_CERT_NAME_INFO const *,_CERT_RDN_ATTR *,_CERT_RDN *,unsigned long,_CERT_NAME_INFO *);
long CertRemovePendingRequest(bool,void *);
long ChaseRenewal(void *,_CERT_CONTEXT const *,_CERT_CONTEXT const * *);
long CheckForDeletion(_CERT_CONTEXT const *,void *,_CRYPT_KEY_PROV_INFO *,bool *);
long CheckReference(void *,_CRYPT_KEY_PROV_INFO *,bool *);
long CompareStringW(unsigned short const *,unsigned short const *,unsigned long,int *);
long ConvertBinaryToHex(unsigned short *,unsigned short * *);
long CopyKeyFlagsFromImportFlags(ImportPFXFlags,unsigned long *);
long CopyString(unsigned short const *,unsigned short * *);
long CopyStringNullSafeW(unsigned short const *,unsigned short * *);
long CopyStringSafeW(unsigned short const *,unsigned short * *);
long CopyStringW(unsigned short const *,unsigned __int64,unsigned short * *);
long CreatePrivateKey(Windows::Security::Cryptography::Certificates::ICertificateRequestProperties *,HWND__ *,unsigned short *,IX509PrivateKey * *);
long CreateRequest(Windows::Security::Cryptography::Certificates::ICertificateRequestProperties *,HWND__ *,unsigned short * *);
long CreateRequestObject(Windows::Security::Cryptography::Certificates::ICertificateRequestProperties *,IX509PrivateKey *,IX509PublicKey *,unsigned short *,unsigned char const *,unsigned long,Windows::Security::Cryptography::Certificates::ICertificate *,Windows::Security::Cryptography::Certificates::ICertificate *,HWND__ *,IX509CertificateRequest * *);
long DecodeCertString(unsigned short * const,unsigned long,unsigned char * *,unsigned long *);
long DeleteCertFromStore(_CERT_CONTEXT const *,void *);
long DeleteExpiredCertsAndKeys();
long DispatchSetErrorInfoStr(long,unsigned short const *,unsigned short const *,unsigned short const *,_GUID const *);
long DispatchSetErrorInfoSub(long,unsigned short const *,unsigned short const *,unsigned short const *,_GUID const *,unsigned short const *,unsigned long);
long DoDeletion(_CERT_CONTEXT const *,_CRYPT_KEY_PROV_INFO *);
long DumpChainAddHash(unsigned __int64,unsigned char const *,unsigned long);
long DumpChainCRL(bool,int,_CRL_CONTEXT const *,unsigned __int64);
long DumpChainHash(bool,unsigned short const *,unsigned char const *,unsigned long);
long DumpChainHashResult(bool,unsigned __int64,char const *);
long DumpChainOpenHash(unsigned __int64 *,unsigned __int64 *);
long DumpChainSerial(bool,char const *,_CRYPTOAPI_BLOB const *);
long DumpSubjectAltName(bool,_CERT_INFO const *);
long DumpVariantStringWorker(unsigned short *,long,void *);
long DuplicateForStringOut(Windows::Internal::String &,HSTRING__ * *);
long EncodeCDPFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long EncodeCEPFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long EncodeCertPoliciesFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long EncodeCertString(unsigned char const *,unsigned long,unsigned long,unsigned short * *);
long EncodeEnrollmentPropertyFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long EncodeInformationAccessFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long EncodeKeyProvInfoFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long EncodeNameConstraintsFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long EncodePolicyConstraintsFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long EncodePolicyMappingsFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long EncodePropertyString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long EncodeSubjectDirectoryAttributesFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long EnumAlgorithms(ICspAlgorithms *,long (*)(ICspAlgorithm *,long,void *),void *);
long EnumAttributeValues(IX509Attributes *,long (*)(IX509Attribute *,long,void *),void *);
long EnumCRLEntries(IX509CertificateRevocationListEntries *,long (*)(IX509CertificateRevocationListEntry *,long,void *),void *);
long EnumCryptAttributes(ICryptAttributes *,long (*)(ICryptAttribute *,long,void *),void *);
long EnumCspStatuses(ICspStatuses *,long (*)(ICspStatus *,long,void *),void *);
long EnumCspStatusesByOrdinal(ICspStatuses *,long (*)(ICspStatus *,long,void *),void *);
long EnumCsps(ICspInformations *,long (*)(ICspInformation *,long,void *),void *);
long EnumExtensions(IX509Extensions *,long (*)(IX509Extension *,long,void *),void *);
long EnumNameValuePairs(IX509NameValuePairs *,long (*)(IX509NameValuePair *,long,void *),void *);
long EnumObjectIds(IObjectIds *,long (*)(IObjectId *,long,void *),void *);
long EnumProperties(ICertProperties *,long (*)(ICertProperty *,long,void *),void *);
long EnumSignerCerts(ISignerCertificates *,long (*)(ISignerCertificate *,long,void *),void *);
long EnumVariantStringArray(tagVARIANT const *,long (*)(unsigned short *,long,void *),void *);
long EnumerateNameValuePairs(unsigned short const *,long (*)(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *),CNameValueError *,void *);
long FindCertInMyStore(unsigned long,_CRYPTOAPI_BLOB *,void * *,_CERT_CONTEXT const * *);
long FindClientAuthCertificatesInMyStore(int,void * *);
long GetAppContainerInfo(int *,int *);
long GetAppContexInfo(int *,int *,HWND__ * *,unsigned short * *,unsigned short * *,unsigned short * *);
long GetByteFromIBuffer(Windows::Storage::Streams::IBuffer *,unsigned int *,unsigned char * *);
long GetCNGImpType(unsigned short const *,unsigned long *);
long GetCNGKeyList(unsigned short const *,unsigned short const *,unsigned short const *,int,int,key_list_tag * *);
long GetCallerAppNames(unsigned short * *,unsigned short * *,unsigned short * *);
long GetCallingWindowHandle(HWND__ * *);
long GetCallingWindowHandleFromBroker(HWND__ * *);
long GetCapiSimpleAndUniqueContainerName(_CRYPT_KEY_PROV_INFO *,unsigned short * *,unsigned short * *);
long GetCertificateBSTR(Windows::Security::Cryptography::Certificates::ICertificate *,unsigned short * *);
long GetCertificateHash(_CERT_CONTEXT const *,unsigned short * *);
long GetChainValidationResult(unsigned long,Windows::Security::Cryptography::Certificates::ChainValidationResult *);
long GetCngSimpleAndUniqueContainerName(_CRYPT_KEY_PROV_INFO *,unsigned short * *,unsigned short * *);
long GetCspKeyList(unsigned long,unsigned short const *,unsigned short const *,int,int,key_list_tag * *);
long GetDetailedVersionString(unsigned short const *,unsigned short * *);
long GetDllImport(unsigned short const *,unsigned long,__int64 (**)());
long GetDomainFromEmail(unsigned short const *,unsigned short * *,unsigned __int64 *);
long GetEkInfo(IX509CertificateRequestPkcs10V4 *,unsigned short *,unsigned short *,unsigned char * *,unsigned long *,unsigned char * *,unsigned long *);
long GetEnhancedKeyUsage(_CERT_CONTEXT const *,Windows::Foundation::Collections::IVectorView<HSTRING__ *> * *);
long GetHashList(unsigned long,unsigned short *,csp_hash_tag * *);
long GetHostName(unsigned short const *,unsigned short * *);
long GetLegacyImpType(unsigned short const *,unsigned long,unsigned long *);
long GetWSErrorString(long *,_WS_ERROR *,unsigned short * *);
long HR_FROM_WIN32(unsigned long);
long HttpCallEndPoints(HWND__ *,WebServiceEndPoint *,int,X509CertificateEnrollmentContext,IClientCommand *,WebServiceEndPointResult *);
long HttpCallEndPointsWithCredential(WebServiceEndPoint *,int,X509CertificateEnrollmentContext,X509EnrollmentAuthFlags,unsigned short *,unsigned short *,IClientCommand *,WebServiceEndPointResult *);
long ImportPfxData(HSTRING__ *,HSTRING__ *,Windows::Security::Cryptography::Certificates::ExportOption,Windows::Security::Cryptography::Certificates::KeyProtectionLevel,HSTRING__ *,HWND__ *,unsigned char);
long ImportPfxDataToKsp(HSTRING__ *,HSTRING__ *,Microsoft::WRL::ComPtr<Windows::Security::Cryptography::Certificates::IPfxImportParameters>,HWND__ *,unsigned char);
long InstallCertificate(HSTRING__ *,HWND__ *,unsigned char);
long IsAsymmetricAlgorithmSupported(unsigned short const *,unsigned short const *);
long IsSignatureOnly(_CRYPT_KEY_PROV_INFO *,bool *);
long IsSmartCard(_CRYPT_KEY_PROV_INFO *,bool *);
long MakeWebServiceEndPointResult(X509CertificateEnrollmentContext,X509EnrollmentAuthFlags,unsigned short *,unsigned short *,WebServiceEndPointResult *);
long MultiByteIntegerToBstr(unsigned long,unsigned long,unsigned char const *,unsigned short * *);
long MultiByteIntegerToWszBuf(unsigned long,unsigned long,unsigned char const *,unsigned long *,unsigned short *);
long NDESParseServerCapabilities(unsigned short const *,unsigned short * * *);
long OpenPrivateKey(HWND__ *,unsigned short *,unsigned short *,IX509PrivateKey * *);
long OpenPublicKey(unsigned short *,unsigned short *,unsigned char * *,unsigned long *,IX509PublicKey * *);
long ReadGroupPolicyFlags(X509CertificateEnrollmentContext,unsigned long *,bool *);
long RegLoadKeyWinPE(HKEY__ *,unsigned short const *,unsigned short const *,unsigned short const *);
long RegSaveStringValue(HKEY__ *,unsigned short const *,unsigned short const *,unsigned short const *);
long ResultFromKnownLastError();
long SelectClientAuthCert(void *,_WS_ENDPOINT_ADDRESS const *,_WS_STRING const *,_CERT_CONTEXT const * *,_WS_ERROR *);
long SetAlgOperations(unsigned long,_NCryptAlgorithmName *);
long SetAlgOperationsFromClass(unsigned long,_NCryptAlgorithmName *,bool *);
long SetAlgOperationsFromProvider(unsigned short const *,unsigned long,_NCryptAlgorithmName *,bool *);
long SetImportPFXFlags(Microsoft::WRL::ComPtr<Windows::Security::Cryptography::Certificates::IPfxImportParameters>,unsigned long *);
long SetKeyAttestationParameters(ATL::CComPtr<IX509CertificateRequestPkcs10>,unsigned short *,Windows::Security::Cryptography::Certificates::ICertificate *,unsigned char const *,unsigned long,bool);
long SetPfxImportParameters(Microsoft::WRL::ComPtr<Windows::Security::Cryptography::Certificates::IPfxImportParameters>,Windows::Security::Cryptography::Certificates::ExportOption,Windows::Security::Cryptography::Certificates::KeyProtectionLevel,Windows::Security::Cryptography::Certificates::InstallOptions,HSTRING__ *,HSTRING__ *);
long SetPkcs10Extensions(Windows::Security::Cryptography::Certificates::ICertificateRequestProperties *,IX509CertificateRequestPkcs10 *);
long SetSuppressedOids(Windows::Security::Cryptography::Certificates::ICertificateRequestProperties *,IX509CertificateRequestCmc *,IX509CertificateRequestPkcs10 *,IX509CertificateRequest *);
long ShowErrorMessage(HWND__ *,bool,unsigned short *,bool,long,unsigned int,int *);
long StringCat(unsigned short const *,unsigned short const *,unsigned short * *);
long StringCchCatA(char *,unsigned __int64,char const *);
long StringCchCatNW(unsigned short *,unsigned __int64,unsigned short const *,unsigned __int64);
long StringCchCatW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchCopyA(char *,unsigned __int64,char const *);
long StringCchCopyNExW(unsigned short *,unsigned __int64,unsigned short const *,unsigned __int64,unsigned short * *,unsigned __int64 *,unsigned long);
long StringCchCopyNW(unsigned short *,unsigned __int64,unsigned short const *,unsigned __int64);
long StringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchLengthA(char const *,unsigned __int64,unsigned __int64 *);
long StringCchLengthW(unsigned short const *,unsigned __int64,unsigned __int64 *);
long StringCchPrintfA(char *,unsigned __int64,char const *,...);
long StringCchPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long StringCchVPrintfW(unsigned short *,unsigned __int64,unsigned short const *,char *);
long StringDup(unsigned short const *,unsigned short * *,int);
long TAddRange<CX509PolicyServerListManager,IX509PolicyServerUrl>(CX509PolicyServerListManager *,CX509PolicyServerListManager *);
long TAddRange<ICryptAttributes,ICryptAttribute>(ICryptAttributes *,ICryptAttributes *);
long TAddRange<IObjectIds,IObjectId>(IObjectIds *,IObjectIds *);
long TAddRange<IX509CertificateRevocationListEntries,IX509CertificateRevocationListEntry>(IX509CertificateRevocationListEntries *,IX509CertificateRevocationListEntries *);
long TAddRange<IX509Extensions,IX509Extension>(IX509Extensions *,IX509Extensions *);
long ULongLongMult(unsigned __int64,unsigned __int64,unsigned __int64 *);
long UnlockPrivateKey(HWND__ *,_CERT_CONTEXT const *);
long UseExistingKeyForRequest(Windows::Security::Cryptography::Certificates::ICertificateRequestProperties *,unsigned char *);
long VerifyMediumStoreAccessCapability(bool *);
long WriteBlob(_iobuf *,unsigned char const *,unsigned long,unsigned long);
long _AllocStringWorker<CTCoAllocPolicy>(void *,unsigned long,unsigned short const *,unsigned __int64,unsigned __int64,unsigned short * *);
long _FindRegKey(unsigned short const *,_CSREGKEY const * *);
long _GetCertRegValueEx(HKEY__ *,unsigned short const *,unsigned short const *,unsigned short const *,CSRegPathType,unsigned short const *,unsigned char * *,unsigned long *,unsigned long *);
long _GetRootKey(unsigned short const *,unsigned long,HKEY__ * *);
long _LoadMuiString(HINSTANCE__ *,unsigned long,unsigned short * *);
long _LoadMuiStringEx(HINSTANCE__ *,unsigned long,bool,unsigned short const *,HINSTANCE__ * *,bool *,bool *,unsigned short * *);
long _LoadResourceOrMessageString(HINSTANCE__ *,unsigned long,bool,bool,unsigned short * *);
long _OpenDComConnection2(unsigned short const *,_GUID const *,_GUID const *,_GUID const *,unsigned short const * *,unsigned short * *,int *,unsigned long *,IUnknown * *);
long _RegOpenRelativeKey(HKEY__ *,unsigned short const *,unsigned long,unsigned short * *,unsigned short * *,HKEY__ * *,bool *);
long addAltNames(Microsoft::WRL::ComPtr<Windows::Foundation::Collections::Internal::AgileVector<HSTRING__ *,Windows::Foundation::Collections::Internal::DefaultEqualityPredicate<HSTRING__ *>,Windows::Foundation::Collections::Internal::DefaultLifetimeTraits<HSTRING__ *>,0> > &,AlternativeNameType,IAlternativeNames *,unsigned int *);
long ceEventLogSub(unsigned long,unsigned long,X509CertificateEnrollmentContext,IX509CertificateTemplateInternal *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,long);
long cpAddCertIdFilters(unsigned short const *,_CERTFILTERDATA *);
long cpAddEKUANDFilter(unsigned short const *,_CERTFILTERDATA *);
long cpAddExpiringInDaysFilter(unsigned short const *,_CERTFILTERDATA *);
long cpAddFilter(unsigned long,unsigned short const *,unsigned short const *,_CERTFILTERDATA *);
long cpAddKeyNameFilter(unsigned short const *,_CERTFILTERDATA *);
long cpAddNameFilter(unsigned short const *,bool,CERTFILTERSTRING *);
long cpCertMatchEKUOrApplicationPolicies(_CERT_CONTEXT const *,unsigned long,char const * const *,unsigned long,CERTFILTERSTRING *,int,int,int *);
long cpCertMatchExpiringInDays(_CERT_CONTEXT const *,_CERTFILTERDATA *,int *);
long cpCertMatchFilter(_CERT_CONTEXT const *,_CERTFILTERDATA *,bool *);
long cpExtensionMatch(_CERT_CONTEXT const *,unsigned short const *,_CERTFILTERDATA *,int *,int *);
long cpIPAddressToWsz(unsigned char const *,unsigned long,unsigned short * *);
long cpKeyProvInfoMatch(_CERT_CONTEXT const *,CERTFILTERSTRING const *,CERTFILTERSTRING const *,unsigned long,int *,int *);
long cpNameBlobMatch2(_CRYPTOAPI_BLOB const *,unsigned short const *,CERTFILTERSTRING const *,CERTFILTERSTRING const *,int,int *,int *);
long cpOtherNameToWsz(_CERT_OTHER_NAME const *,unsigned short * *);
long cpSerialNumberMatch(_CRYPTOAPI_BLOB const *,unsigned short const *,int *);
long cpSubjectAltNameMatch(_CERT_CONTEXT const *,_CERTFILTERDATA *,int *,int *);
long cpTemplateMatch(unsigned long,_CERT_EXTENSION const *,_CERTFILTERDATA *,int *);
long cpTemplateMatch2(bool,unsigned short const *,_CERTFILTERDATA *,int *);
long csiGetKeyList2(unsigned long,unsigned short const *,unsigned short const *,unsigned short const *,int,int,key_list_tag * *);
long extEncodeAttribute(char const *,_CRYPTOAPI_BLOB const *,unsigned long,_CRYPTOAPI_BLOB *);
long extEncodeBasicConstraintsEntryWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodeBool(unsigned char,int,_CRYPTOAPI_BLOB *);
long extEncodeCCM(unsigned char,SDATPMSECASSERT const *,unsigned long,_CRYPTOAPI_BLOB *);
long extEncodeCDPEntryWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodeCEPWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodeCertPoliciesEntryWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodeEnrollmentPropertyWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodeEnum(unsigned char,unsigned long,_CRYPTOAPI_BLOB *);
long extEncodeFIPS(unsigned char,SDATPMSECASSERT const *,_CRYPTOAPI_BLOB *);
long extEncodeIA5String(unsigned short const *,_CRYPTOAPI_BLOB *);
long extEncodeInformationAccessEntryWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodeKeyProvInfoEntryWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodeNameConstraintsEntryWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodePolicyConstraintsEntryWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodePolicyMappingsEntryWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodeSubjectAltNameEntryWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodeSubjectDirectoryAttributesWorker(void *,unsigned long,unsigned long,CNameValueError *,unsigned short const *,unsigned short const *);
long extEncodeSupportedAlgorithms(_CERT_SUPPORTED_ALGORITHM_INFO const *,unsigned long,_CRYPTOAPI_BLOB *);
long extEncodeTPMSecurityAssertions(SDATPMSECASSERT const *,unsigned long,_CRYPTOAPI_BLOB *);
long extEncodeTPMSpecification(_CERT_TPM_SPECIFICATION_INFO const *,_CRYPTOAPI_BLOB *);
long extParseAltNameAndOtherName(unsigned short const *,unsigned short const *,bool,_CERT_ALT_NAME_ENTRY *);
long extParseBitString(unsigned short const *,long *,_CRYPT_BIT_BLOB *);
long extParseIPAddressAndMask(unsigned short const *,unsigned short const *,bool *,unsigned char * *,unsigned long *);
long extReencodeBinary(unsigned short * *);
long extReencodeDN(unsigned short * *);
long extReencodeGUID(unsigned short * *);
long extReencodeUTF8(unsigned short * *);
long extSetAltNameEntry(ICertEncodeAltName *,unsigned long,unsigned short const *,unsigned short const *);
long fsBCryptCloseAlgorithmProvider(void *,unsigned long);
long fsBCryptCreateHash(void *,void * *,unsigned char *,unsigned long,unsigned char *,unsigned long,unsigned long);
long fsBCryptDecrypt(void *,unsigned char *,unsigned long,void *,unsigned char *,unsigned long,unsigned char *,unsigned long,unsigned long *,unsigned long);
long fsBCryptDestroyHash(void *);
long fsBCryptDestroyKey(void *);
long fsBCryptEncrypt(void *,unsigned char *,unsigned long,void *,unsigned char *,unsigned long,unsigned char *,unsigned long,unsigned long *,unsigned long);
long fsBCryptExportKey(void *,void *,unsigned short const *,unsigned char *,unsigned long,unsigned long *,unsigned long);
long fsBCryptGetProperty(void *,unsigned short const *,unsigned char *,unsigned long,unsigned long *,unsigned long);
long fsBCryptSetProperty(void *,unsigned short const *,unsigned char *,unsigned long,unsigned long);
long fsBCryptSignHash(void *,void *,unsigned char *,unsigned long,unsigned char *,unsigned long,unsigned long *,unsigned long);
long fsBCryptVerifySignature(void *,void *,unsigned char *,unsigned long,unsigned char *,unsigned long,unsigned long);
long fsNCryptCreatePersistedKey(unsigned __int64,unsigned __int64 *,unsigned short const *,unsigned short const *,unsigned long,unsigned long);
long fsNCryptDecrypt(unsigned __int64,unsigned char *,unsigned long,void *,unsigned char *,unsigned long,unsigned long *,unsigned long);
long fsNCryptDeleteKey(unsigned __int64,unsigned long);
long fsNCryptDeriveKey(unsigned __int64,unsigned short const *,_BCryptBufferDesc *,unsigned char *,unsigned long,unsigned long *,unsigned long);
long fsNCryptEncrypt(unsigned __int64,unsigned char *,unsigned long,void *,unsigned char *,unsigned long,unsigned long *,unsigned long);
long fsNCryptExportKey(unsigned __int64,unsigned __int64,unsigned short const *,_BCryptBufferDesc *,unsigned char *,unsigned long,unsigned long *,unsigned long);
long fsNCryptFinalizeKey(unsigned __int64,unsigned long);
long fsNCryptFreeObject(unsigned __int64);
long fsNCryptGetProperty(unsigned __int64,unsigned short const *,unsigned char *,unsigned long,unsigned long *,unsigned long);
long fsNCryptImportKey(unsigned __int64,unsigned __int64,unsigned short const *,_BCryptBufferDesc *,unsigned __int64 *,unsigned char *,unsigned long,unsigned long);
long fsNCryptOpenKey(unsigned __int64,unsigned __int64 *,unsigned short const *,unsigned long,unsigned long);
long fsNCryptOpenStorageProvider(unsigned __int64 *,unsigned short const *,unsigned long);
long fsNCryptSetProperty(unsigned __int64,unsigned short const *,unsigned char *,unsigned long,unsigned long);
long fsNCryptSignHash(unsigned __int64,void *,unsigned char *,unsigned long,unsigned char *,unsigned long,unsigned long *,unsigned long);
long fsNCryptVerifySignature(unsigned __int64,void *,unsigned char *,unsigned long,unsigned char *,unsigned long,unsigned long);
long getBlobProperty(unsigned int,unsigned char const *,unsigned int *,unsigned char * *);
long growArray(unsigned long,unsigned __int64,void * *);
long infParseIPV4Address(unsigned short *,unsigned char *,unsigned long *);
long infParseIPV6Address(unsigned short *,unsigned char *,unsigned long *);
long infParseIPV6AddressSub(unsigned short *,unsigned char *,unsigned long *);
long myAddCertToStore(void *,_CERT_CONTEXT const *,_CRYPT_KEY_PROV_INFO const *,bool,_CERT_CONTEXT const * *);
long myAddNameSuffix(unsigned short const *,unsigned short const *,unsigned long,unsigned short * *);
long myBCCloseAlgorithmProvider(void *,unsigned long);
long myBCEnumAlgorithms(unsigned long,unsigned long *,_BCRYPT_ALGORITHM_IDENTIFIER * *,unsigned long);
long myBCGetProperty(void *,unsigned short const *,unsigned char *,unsigned long,unsigned long *,unsigned long);
long myBCOpenAlgorithmProvider(void * *,unsigned short const *,unsigned short const *,unsigned long);
long myBlobToHashString(_CRYPTOAPI_BLOB const *,unsigned short * *);
long myBstrSimpleArrayToVariant(ATL::CSimpleArray<unsigned short *,ATL::CSimpleArrayEqualHelper<unsigned short *> > &,tagVARIANT *);
long myBuildFilterContent(unsigned short const *,bool,_CERTFILTERDATA *);
long myBuildPathAndExt(unsigned short const *,unsigned short const *,unsigned short const *,unsigned short * *);
long myBuildReaderContainerName(unsigned short const *,unsigned short const *,unsigned short * *);
long myCLSIDToWsz(_GUID const *,unsigned short * *);
long myCertGetEnhancedKeyUsage(_CERT_CONTEXT const *,unsigned long,_CTL_USAGE * *);
long myCertGetKeyProviderInfo(_CERT_CONTEXT const *,_CRYPT_KEY_PROV_INFO * *);
long myCertGetNameString(_CERT_CONTEXT const *,unsigned long,unsigned short * *);
long myCertHashMatch(_CERT_CONTEXT const *,unsigned long,unsigned char const *,int *);
long myCertNameToStr(unsigned long,_CRYPTOAPI_BLOB const *,unsigned long,unsigned short * *);
long myCertStrToName(unsigned long,unsigned short const *,unsigned long,void *,unsigned char * *,unsigned long *,unsigned short const * *);
long myCertStrToName(unsigned short const *,_CRYPTOAPI_BLOB *);
long myCngConfigEnumAlgorithms(unsigned long,unsigned long *,_NCryptAlgorithmName * *);
long myCngConfigFreeBuffer(void *);
long myCombineStringArray(unsigned long,unsigned short const * *,unsigned short * *);
long myCombineStrings(unsigned short const *,unsigned short const *,unsigned short const *,unsigned short * *);
long myConvertMultiSzToSz(unsigned short const *,unsigned short,unsigned short * *);
long myCopyKeys(HWND__ *,unsigned long,_CRYPT_KEY_PROV_INFO const *,unsigned short const *,unsigned __int64,unsigned short const *,unsigned short const *,unsigned short const *,_CERT_CONTEXT const *,unsigned short const *,unsigned short const *,unsigned short const *,int *);
long myCopyKeysUsingPKCS8(HWND__ *,unsigned long,unsigned __int64,unsigned long,unsigned short const *,_CRYPT_KEY_PROV_INFO const *,unsigned short const *,unsigned short const *,unsigned __int64 *);
long myCopyPropertiesFromCertificate(_CERT_CONTEXT const *,ICertProperties *);
long myCopyPropertiesFromCollection(ICertProperties *,_CERT_CONTEXT const *);
long myCryptDecryptMessage(void *,unsigned char const *,unsigned long,bool,CERTLIB_ALLOCATOR,unsigned char * *,unsigned long *);
long myCryptEncryptMessage(unsigned int,unsigned short const *,unsigned long,unsigned long,_CERT_CONTEXT const * *,unsigned char const *,unsigned long,unsigned char * *,unsigned long *);
long myCryptExportKey(unsigned __int64,unsigned __int64,unsigned long,unsigned char * *,unsigned long *);
long myCryptExportPrivateKey(unsigned __int64,unsigned short const *,unsigned char * *,unsigned long *);
long myCryptExportPublicKeyInformation2(unsigned __int64,unsigned long,unsigned long,CERTLIB_ALLOCATOR,_CERT_PUBLIC_KEY_INFO * *,unsigned long *);
long myCryptFormatObject(unsigned long,unsigned long,char const *,unsigned char const *,unsigned long,unsigned short * *);
long myCryptGetDefaultProvider(unsigned long,unsigned short const *,unsigned short const *,unsigned long,unsigned short * *,unsigned short * *);
long myCryptGetProvParamToUnicode(unsigned __int64,unsigned long,unsigned short * *,unsigned long);
long myCryptHashByteArray(char const *,unsigned char const *,unsigned long,unsigned char * *,unsigned long *);
long myCryptMsgGetParam(void *,unsigned long,unsigned long,CERTLIB_ALLOCATOR,void * *,unsigned long *);
long myCryptReleaseHandle(unsigned __int64);
long myDateToFileTime(double const *,_FILETIME *);
long myDecodeCMCRegInfo(unsigned char const *,unsigned long,unsigned short * *);
long myDecodePKCS7Ex(unsigned char const *,unsigned long,unsigned char const *,unsigned long,unsigned char * *,unsigned long *,unsigned long *,char * *,unsigned long *,unsigned long *,void * *,void * *);
long myDecodeRequestClientAttribute(unsigned char const *,unsigned long,_CRYPT_REQUEST_CLIENT_INFO * *);
long myDecodeUTF8String(unsigned char const *,unsigned long,unsigned short * *);
long myDecodeUnicodeName(_CRYPTOAPI_BLOB const *,unsigned short * *);
long myDoCertAndKeyExist(unsigned long,unsigned short const *,unsigned short const *,_CERT_CONTEXT const *,unsigned short const *,unsigned long,unsigned short const *,bool *);
long myDoCertAndKeyMatch(_CERT_CONTEXT const *,_CERT_CONTEXT const *,_CRYPT_KEY_PROV_INFO const *,unsigned short const *,bool,bool *);
long myDomainFromDn(unsigned short const *,unsigned short * *);
long myDumpCert(_CERT_CONTEXT const *,bool,bool);
long myDupMemory(unsigned char const *,unsigned long,unsigned char * *,unsigned long *);
long myDupString(unsigned short const *,unsigned short * *);
long myDupStringA(char const *,char * *);
long myEncodeBasicConstraintsFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long myEncodeEnhancedKeyUsageFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long myEncodeExtensionFromString(char const *,unsigned short const *,unsigned long,CNameValueError *,bool *,unsigned char * *,unsigned long *);
long myEncodeOtherNameBinary(unsigned short const *,unsigned char * *,unsigned long *);
long myEncodeRequestClientAttribute(_CRYPT_REQUEST_CLIENT_INFO const *,unsigned char * *,unsigned long *);
long myEncodeSubjectAltNameFromString(char const *,unsigned short const *,CNameValueError *,unsigned char * *,unsigned long *);
long myEncodeUTF8(unsigned short const *,unsigned char * *,unsigned long *);
long myEncodeUTF8String(unsigned short const *,unsigned char * *,unsigned long *);
long myEnumProviders(unsigned long,unsigned long *,unsigned long,unsigned long *,unsigned short * *);
long myExportCNGKey(unsigned __int64,unsigned short const *,_BCryptBufferDesc *,unsigned char * *,unsigned long *,unsigned long);
long myExtParseAltName(unsigned short const *,unsigned short const *,unsigned short const *,bool *,_CERT_ALT_NAME_ENTRY *);
long myExtVerifyAltName(_CERT_ALT_NAME_ENTRY const *);
long myExtVerifySubTreeElement(_CERT_GENERAL_SUBTREE const *);
long myFileTimePeriodToWszTimePeriodLocalized(_FILETIME const *,int,int,unsigned short const * const *,unsigned long,unsigned short * *);
long myFileTimeToDate(_FILETIME const *,double *);
long myFileTimeToWszTime(_FILETIME const *,int,unsigned short * *);
long myFileTimeToWszUniversalSortableString(_FILETIME const *,unsigned short * *);
long myFindSingleLdapObjectExtendedDnWithGuid(ldap *,unsigned short *,_GUID *);
long myFormCertRegPath(unsigned short const *,unsigned short const *,unsigned short const *,CSRegPathType,unsigned short * *);
long myFormConfigString(unsigned short const *,unsigned short const *,unsigned short * *);
long myFormatFromResourceString(HINSTANCE__ *,unsigned int,unsigned short * *,...);
long myFormatMessageFromSource(unsigned short const *,HINSTANCE__ *,unsigned long,unsigned short const * *,unsigned long,char * *,unsigned short * *);
long myFormatMessageFromString(unsigned short const *,unsigned short const * *,unsigned long,unsigned short * *);
long myGMTFileTimeToWszLocalTime(_FILETIME const *,int,unsigned short * *);
long myGenerateGuidString(unsigned short * *);
long myGenerateKeyContainerName(_CERT_CONTEXT const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short * *,unsigned short * *);
long myGeneratePassword(unsigned long,unsigned short *,unsigned long);
long myGetAKIExtFromCertificate(_CERT_CONTEXT const *,IX509ExtensionAuthorityKeyIdentifier * *);
long myGetAccountNameFromSID(void *,unsigned short * *,unsigned short * *);
long myGetActiveDirectoryEnrollmentPolicyId(ldap *,unsigned short *,unsigned long);
long myGetAlgorithmNameFromNCryptKey(unsigned __int64,unsigned short * *,unsigned short * *);
long myGetAuthoritativeDomainDnEx(ldap *,bool,unsigned short * *,unsigned short * *);
long myGetCNGBlobProperty(unsigned __int64,unsigned short const *,unsigned long *,unsigned char * *);
long myGetCNGStringProperty(unsigned __int64,unsigned short const *,unsigned short * *);
long myGetCertFromKeyHandle(unsigned __int64,_CERT_CONTEXT const * *);
long myGetCertIdString(_CERT_CONTEXT const *,unsigned short * *);
long myGetCertNameList(_CERT_CONTEXT const *,unsigned long,unsigned long,unsigned long *,unsigned short * * *);
long myGetCertRegMultiStrValue2(unsigned short const *,unsigned short const *,unsigned short const *,CSRegPathType,unsigned short const *,unsigned short * *);
long myGetCertSubjectField(_CERT_CONTEXT const *,char const *,unsigned short * *);
long myGetCertType(_CERT_INFO const *,int,int,unsigned short * *,unsigned short * *,unsigned short * *,unsigned short * *,unsigned short * *);
long myGetCertificateFromPicker(HINSTANCE__ *,HWND__ *,int,int,unsigned long,unsigned short const *,unsigned long,void * *,unsigned short const * *,unsigned long,char const * const *,_CERT_CONTEXT const * *);
long myGetChainArrayFromStore(void *,int,int,unsigned short * *,unsigned long *,_RESTORECHAIN *);
long myGetCommonName(_CRYPTOAPI_BLOB const *,int,unsigned short * *);
long myGetComputerNameEx(_COMPUTER_NAME_FORMAT,unsigned short * *);
long myGetCurveList(unsigned __int64,_NCryptAlgorithmName const *,_BCRYPT_ECC_CURVE_NAMES * *);
long myGetDetailedVersionString(HINSTANCE__ *,unsigned short * *);
long myGetEnrollRegDWValue(bool,unsigned short const *,unsigned long *);
long myGetEnrollRegStrValue(bool,unsigned short const *,unsigned short * *);
long myGetForestGuid(ldap *,_GUID * *);
long myGetForestGuidEx(ldap *,_GUID * *);
long myGetHashFromBStr(unsigned short *,unsigned char *,unsigned long);
long myGetIdString(_CRYPTOAPI_BLOB const *,unsigned long,unsigned char const *,unsigned short * *);
long myGetIsSigningCertificate(_CERT_CONTEXT const *,unsigned long,unsigned __int64,bool *);
long myGetKeyProvInfoBlob(IX509PrivateKey *,_CRYPTOAPI_BLOB *);
long myGetKeyUsage(_CERT_CONTEXT const *,unsigned long *);
long myGetKeyUsageFlagFromNCryptKey(unsigned __int64,unsigned long *);
long myGetLegacyKeySpecs(unsigned short const *,unsigned long,unsigned long *);
long myGetLogFileNameA(char const *,char *,unsigned long);
long myGetLong(unsigned short const *,long *);
long myGetLongLong(unsigned short const *,__int64 *);
long myGetMachineDnsName(unsigned short * *);
long myGetOIDInfoForAlgorithm(unsigned short const *,unsigned long,_CRYPT_OID_INFO const * *);
long myGetPrivateKeySecurityDescriptor(unsigned __int64,void * *);
long myGetProcessName(unsigned short * *);
long myGetPropertyIdFromOID(char const *,unsigned long *);
long myGetProviderImpType(unsigned short const *,unsigned long,unsigned long *);
long myGetProviderNameAndTypeFromHandle(unsigned __int64,unsigned long *,unsigned short * *);
long myGetProviderTypeFromProviderName(unsigned short const *,unsigned long *);
long myGetPublicKeyHash(_CERT_INFO const *,_CERT_PUBLIC_KEY_INFO const *,unsigned char * *,unsigned long *);
long myGetRDNAttributeFromNameBlob(_CRYPTOAPI_BLOB const *,char const *,unsigned short * *);
long myGetRootProgramPolicies(_CERT_CONTEXT const *,_CERT_POLICIES_INFO * *);
long myGetSidFromRid(WELL_KNOWN_SID_TYPE,void * *);
long myGetSignedLong(unsigned short const *,long *);
long myGetTemplateNames(unsigned short const *,int,int,unsigned short * *,unsigned short * *);
long myGetUserNameEx(EXTENDED_NAME_FORMAT,unsigned short * *);
long myGetVersionString(HINSTANCE__ *,bool,unsigned short const * *);
long myHError(long);
long myHLastError();
long myHLdapError3(ldap *,unsigned long,unsigned long,unsigned long,unsigned short * *);
long myHLdapLastError(ldap *,unsigned short * *);
long myHashString(unsigned short const *,unsigned short * *);
long myIPAddressToWszBuf(unsigned char const *,unsigned long,unsigned short *,unsigned long);
long myImpersonateSid(void *,unsigned short const *);
long myImportChainAndKeys(HWND__ *,unsigned long,_CERT_CHAIN_CONTEXT const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,bool *,bool *,_CERT_CONTEXT const * *);
long myImportPFX(HWND__ *,unsigned char const *,unsigned long,ImportPFXFlags,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned long *,_CERT_CONTEXT const * * *);
long myInternetCanonicalizeUrl(unsigned short const *,unsigned short * *);
long myInternetUncanonicalizeURL(unsigned short const *,unsigned short * *);
long myIsCACert(_CERT_CONTEXT const *,bool *);
long myIsCertSelfSigned(_CERT_CONTEXT const *,bool *);
long myIsDSAvailable(bool *,void * *);
long myIsDirWriteable(unsigned short const *,int);
long myJoinStrings(unsigned short const *,int,unsigned short const *,unsigned short * *);
long myLdapBind(unsigned long,bool,unsigned short const *,ldap * *);
long myLoadBinaryResource(HINSTANCE__ *,unsigned short const *,unsigned short const *,unsigned char * *,unsigned long *);
long myLoadResourceBStr(unsigned long,unsigned short * *);
long myLoadResourceStringDirect(HINSTANCE__ *,unsigned long,bool,unsigned short * *);
long myLoadTemplateInfo(unsigned short const *,unsigned short * *,unsigned short * *,char * *);
long myLocalRegOpenRelativeKey(unsigned short const *,unsigned long,unsigned short * *,unsigned short * *,HKEY__ * *,bool *);
long myMakeSerialBstr(unsigned short const *,unsigned short * *);
long myNCCreatePersistedKey(unsigned __int64,unsigned __int64 *,unsigned short const *,unsigned short const *,unsigned long,unsigned long);
long myNCDeleteKey(unsigned __int64,unsigned long);
long myNCEnumAlgorithms(unsigned __int64,unsigned long,unsigned long *,_NCryptAlgorithmName * *,unsigned long);
long myNCEnumStorageProviders(unsigned long *,NCryptProviderName * *,unsigned long);
long myNCExportKey(unsigned __int64,unsigned __int64,unsigned short const *,_BCryptBufferDesc *,unsigned char *,unsigned long,unsigned long *,unsigned long);
long myNCFinalizeKey(unsigned __int64,unsigned long);
long myNCFreeBuffer(void *);
long myNCFreeObject(unsigned __int64);
long myNCGetProperty(unsigned __int64,unsigned short const *,unsigned char *,unsigned long,unsigned long *,unsigned long);
long myNCImportKey(unsigned __int64,unsigned __int64,unsigned short const *,_BCryptBufferDesc *,unsigned __int64 *,unsigned char *,unsigned long,unsigned long);
long myNCOpenKey(unsigned __int64,unsigned __int64 *,unsigned short const *,unsigned long,unsigned long);
long myNCOpenStorageProvider(unsigned __int64 *,unsigned short const *,unsigned long);
long myNCSetProperty(unsigned __int64,unsigned short const *,unsigned char *,unsigned long,unsigned long);
long myOpenCertStores(unsigned long,unsigned long *,void * * *,unsigned short const * * *);
long myParseBooleanValue(unsigned short const *,int *);
long myParseExtensionString(unsigned short const *,unsigned short * *,unsigned short * *,bool *,unsigned short * *);
long myParseIPAddress(unsigned short const *,unsigned char *,unsigned long *);
long myParseMultiSz(unsigned short const *,unsigned short * * *);
long myParseNextAttribute(unsigned short * *,unsigned long,unsigned short const * *,unsigned short const * *);
long myParseOIDList(unsigned short const *,unsigned long *,char * * *,unsigned long *,unsigned short * * *);
long myParseStringsWithPrefix(unsigned short const *,bool,bool,unsigned short const *,unsigned short const * *,unsigned short * * *,bool *);
long myParseToken(unsigned short *,unsigned long,bool,bool,unsigned short const *,unsigned short const * *,bool *,unsigned short const * *,unsigned short const * *);
long myPingCertSrv(unsigned short const *,unsigned short const *,unsigned short * *,unsigned short * *,_CAINFO * *,unsigned long *,unsigned short * *);
long myPolicyCacheGetPath(unsigned short const *,bool,unsigned short * *,unsigned short * *);
long myPolicyCacheReadFile(unsigned short const *,unsigned short * *,unsigned char * *,unsigned long *,_FILETIME *);
long myPolicyCacheWriteFile(unsigned short const *,unsigned short const *,unsigned char const *,unsigned long,unsigned long);
long myReencodeIPAddress(unsigned short * *);
long myRegQueryValueEx(HKEY__ *,unsigned short const *,unsigned long *,unsigned char * *,unsigned long *);
long myRegValueToVariant(unsigned long,unsigned long,unsigned char const *,tagVARIANT *);
long myRepairCertKeyProviderInfo(_CERT_CONTEXT const *,int,_CRYPT_KEY_PROV_INFO * *);
long myRepairKeyProviderInfo(_CERT_CONTEXT const *,int,_CRYPT_KEY_PROV_INFO *);
long myRetrieveKeySpec(unsigned short const *,unsigned long,unsigned short const *,bool,unsigned long *);
long mySanitizeName(unsigned short const *,unsigned short * *);
long mySanitizedNameToDSName(unsigned short const *,unsigned short * *);
long mySanitizedNameToShortName(unsigned short const *,int,unsigned short * *);
long mySaveChainAndKeyProvInfo(unsigned long,_CERT_SIMPLE_CHAIN const *,unsigned short const *,unsigned short const *,unsigned long,_CRYPT_KEY_PROV_INFO const *,int,_CERT_CONTEXT const * *);
long mySelectCertificateFromStore(unsigned long,tagCRYPTUI_SELECTCERTIFICATE_STRUCTW *,void *,unsigned short const *,_CERT_CONTEXT const * *);
long mySetCNGStringProperty2(unsigned __int64,unsigned short const *,unsigned short const *,unsigned long);
long mySetControlFlagsOnSDDL(unsigned short const *,unsigned short,unsigned short * *);
long mySetKeyHandlePin(unsigned __int64,unsigned long,unsigned short const *);
long mySplitConfigString(unsigned short const *,unsigned short * *,unsigned short * *);
long mySqueezePublicKey(unsigned char const *,unsigned long,unsigned char * *,unsigned long *);
long myTpmAttTestCapability(TestKeyAttResult *);
long myTpmGetEKCertInfo(unsigned short * *,unsigned short * *,unsigned short * *,unsigned char * *,unsigned long *);
long myTpmGetPlatformType(unsigned long *,unsigned short * *);
long myTpmGetPlatformTypeValue(unsigned short const *,unsigned short const *,unsigned short * *);
long myUncanonicalizeURLParm(unsigned short const *,unsigned short * *);
long myVariantToRegValueEx(tagVARIANT const *,unsigned long,unsigned long *,unsigned long *,unsigned char * *);
long myVerifyCertContext(_CERT_CONTEXT const *,unsigned long,unsigned long,char const * const *,void *,void *,unsigned short * *);
long myVerifyCertContextEx(_CERT_CONTEXT const *,unsigned long,unsigned long,unsigned long,char const * const *,unsigned long,char const * const *,void *,_FILETIME const *,void *,CSimpleChainCallback *,unsigned short const *,unsigned short * *,unsigned short * *,unsigned short * *,unsigned short * *,unsigned short * *,_CERT_TRUST_STATUS *,CSVerifyResult *);
long myVerifyObjId(unsigned short const *);
long myVerifyObjIdA(char const *);
long myVerifyPublicKey(_CERT_CONTEXT const *,int,unsigned long,_CRYPT_KEY_PROV_INFO const *,_CERT_PUBLIC_KEY_INFO const *,int *);
long myVerifyPublicKeyFromHProv(unsigned __int64,unsigned long,_CERT_CONTEXT const *,int,_CERT_PUBLIC_KEY_INFO const *,int *);
long putBlobProperty(unsigned int,unsigned char const *,unsigned int *,unsigned char * *);
long regHashURLPath(unsigned short const *,unsigned short * *);
unsigned long * g_rgdwSupersedeOrder;
unsigned long CertGetMaxPendingDays(bool);
unsigned long GetAllowedObjectsPerPrompt();
unsigned long GetWindowsDirectoryWinPE(unsigned short * *);
unsigned long RegOpenCurrentUserKey(unsigned long,HKEY__ * *);
unsigned long RegReadDwordValue(HKEY__ *,unsigned short const *,unsigned short const *,unsigned long *);
unsigned long RegReadStringValue(HKEY__ *,unsigned short const *,unsigned short const *,unsigned short * *);
unsigned long _SSSetupRPCConnection(void * *);
unsigned long dwTimeOut;
unsigned long g_cStringAlloc;
unsigned long g_cStringUsed;
unsigned long g_crs;
unsigned long g_crsMax;
unsigned long myASNGetDataIndex(unsigned char,unsigned long,unsigned char const *,unsigned long,unsigned long *,unsigned long *);
unsigned long myASNStoreLength(unsigned long,unsigned char *,unsigned long);
unsigned long myGetCertNameProperty(int,_CERT_NAME_INFO const *,char const *,unsigned short const * *);
unsigned long mySiteLockStrLen(unsigned short const *);
unsigned long myWCSZZLength(unsigned short const *);
unsigned long myatolx(unsigned short const *);
unsigned short * AEGetComputerName(_COMPUTER_NAME_FORMAT);
unsigned short * DispatchGetErrorInfo();
unsigned short * myCRLNumber(char const *,_CRL_CONTEXT const *);
unsigned short * myGetVolatileCertIdString(_CERT_CONTEXT const *);
unsigned short * myGetVolatileCertIdStringDbg(_CERT_CONTEXT const *);
unsigned short * myLoadResourceStringNoCache(HINSTANCE__ *,unsigned long);
unsigned short * s_pwszMuiModuleName;
unsigned short const * const InterfaceName_Windows_Foundation_IAsyncAction;
unsigned short const * const RuntimeClass_Windows_Foundation_Diagnostics_AsyncCausalityTracer;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_Certificate;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CertificateChain;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CertificateEnrollmentManager;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CertificateExtension;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CertificateKeyUsages;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CertificateQuery;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CertificateRequestProperties;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CertificateStore;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CertificateStores;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_ChainBuildingParameters;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_ChainValidationParameters;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CmsAttachedSignature;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CmsDetachedSignature;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CmsSignerInfo;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_CmsTimestampInfo;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_KeyAlgorithmNames;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_KeyAttestationHelper;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_KeyStorageProviderNames;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_PfxImportParameters;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_StandardCertificateStoreNames;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_SubjectAlternativeNameInfo;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_UserCertificateEnrollmentManager;
unsigned short const * const RuntimeClass_Windows_Security_Cryptography_Certificates_UserCertificateStore;
unsigned short const * const RuntimeClass_Windows_UI_Core_CoreWindow;
unsigned short const * const RuntimeClass_Windows_UI_Popups_UICommand;
unsigned short const * const g_CCertificationWebService__wszClass;
unsigned short const * const g_CX509EnrollmentPolicyWebService__wszClass;
unsigned short const * const g_CX509PolicyServerListManager__wszClass;
unsigned short const * const g_CX509PolicyServerUrl__wszClass;
unsigned short const * myGetOIDNameA(KeyPreference,char const *);
unsigned short const * myHResultToStringIndirect(unsigned short *,unsigned __int64,long,unsigned long,unsigned long,unsigned short const * (**)(unsigned short *,unsigned __int64,long),unsigned short const * (**)(unsigned short *,long));
unsigned short const * myLoadResourceString(unsigned long);
unsigned short const * wszPropertyName(PolicyServerUrlPropertyID);
void * AEOpenUserDSStore(unsigned long);
void * GetProcessTokenIfSidMatch(unsigned long,void *);
void * MemoryAlloc(unsigned __int64);
void * SafeAlloc(unsigned __int64);
void * myAlloc(unsigned __int64,CERTLIB_ALLOCATOR);
void * myCryptAlloc_LocalAlloc(unsigned __int64);
void * myPFXImportCertStore(_CRYPTOAPI_BLOB *,unsigned short const *,unsigned long);
void * operator new(unsigned __int64);
void * operator new(unsigned __int64,std::nothrow_t const &);
void * operator new[](unsigned __int64);
void * operator new[](unsigned __int64,std::nothrow_t const &);
void CERetrieveLogLevel(bool,unsigned long *);
void CertFreeGeneralInfo(_AE_GENERAL_INFO_ *);
void DM_AddPropertiesToMyStoreCerts(_AE_GENERAL_INFO_ const *);
void DM_ArchiveDuplicatedCerts(_AE_GENERAL_INFO_ const *);
void DispatchClearErrorInfo();
void DumpChainDate(bool,char const *,_FILETIME const *);
void DumpChainName(bool,char const *,_CRYPTOAPI_BLOB const *);
void DumpChainSeconds(bool,unsigned short const *,unsigned long);
void DumpChainTemplate(bool,_CERT_INFO const *);
void DumpHex(unsigned long,unsigned char const *,unsigned long);
void DumpPolicies(bool,unsigned short const *,_CERT_POLICIES_INFO const *);
void ErrLog_Initialize();
void ErrLog_LogError(unsigned short *,unsigned long,unsigned long,unsigned long,int,int);
void GetSignatureValidationResult(long,Windows::Security::Cryptography::Certificates::SignatureValidationResult *);
void MemoryFree(void *);
void MultiByteStringSize(unsigned long,unsigned char const *,unsigned long *,unsigned long *);
void SeTranslator(unsigned int,_EXCEPTION_POINTERS *);
void SecureZeroAndSysFreeString(unsigned short *);
void WriteChain(_CERT_SIMPLE_CHAIN const *,unsigned long,unsigned long);
void _WriteErrorOut(unsigned short *,char *,int);
void __ArrayUnwind(void *,unsigned __int64,int,void (*)(void *));
void addKeyList(key_list_tag * *,key_list_tag *);
void csiFreeKeyList(key_list_tag *);
void csiLog(unsigned long,unsigned long,long,unsigned int,int,unsigned short const *,unsigned short const *,unsigned long const *);
void csiLogFileVersion(unsigned long,unsigned long,unsigned int,unsigned short const *,HINSTANCE__ *);
void csiLogOpen(char const *,LogPriority);
void csiLogString(char const *);
void csiLogTime(unsigned long,unsigned long,unsigned int);
void fputsStripCRA(char const *,_iobuf *);
void fputsStripCRW(unsigned short const *,_iobuf *);
void freeHashInfoList(csp_hash_tag *);
void freeKey(key_list_tag *);
void myCloseCertStores(unsigned long,void * *,unsigned short const * *);
void myCloseDComConnection(IUnknown * *,unsigned short * *);
void myCryptAlloc_LocalFree(void *);
void myDumpChain(long,unsigned long,int,_CERT_CONTEXT const *,CSimpleChainCallback *,unsigned short const *,_CERT_CHAIN_CONTEXT const *);
void myExtFreeAltName(_CERT_ALT_NAME_ENTRY *);
void myExtFreeAltNameEntries(_CERT_ALT_NAME_INFO *);
void myExtFreeCertPolicyArray(unsigned long,_CERT_POLICY_INFO *);
void myExtFreeGeneralSubTree(unsigned long,_CERT_GENERAL_SUBTREE *);
void myFree(void *,CERTLIB_ALLOCATOR);
void myFreeFilterContent(_CERTFILTERDATA *);
void myFreeResourceStrings(char const *);
void myFreeStringArray(unsigned short * *);
void myFreeStringArrayA(char * *);
void myGenerateGuidSerialNumber(_GUID *);
void myGetBStrBuffer(unsigned short *,unsigned long *,unsigned char * *);
void myGetGMTLocalTimeDiff(int *,float *);
void myLdapClose(ldap *,unsigned short *,unsigned short *);
void myLoadResourceStringInit(unsigned short const *);
void myMakeExprDateTime(_FILETIME *,long,ENUM_PERIOD);
void myReportLogFile(bool,char const *,char const *);
void myReverseBytes(unsigned char *,unsigned long);
void myUuidCreate(_GUID *);
void myZeroBStr(unsigned short *);
void myZeroDataString(unsigned short *);
void operator delete(void *);
void operator delete(void *,std::nothrow_t const &);
void operator delete(void *,void *);
void operator delete[](void *);
void operator delete[](void *,std::nothrow_t const &);
