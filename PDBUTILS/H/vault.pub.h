namespace ATL
{
	struct CAtlException
	{
		CAtlException(long);
	};

	struct CComBSTR
	{
		~CComBSTR();
	};

	struct CComPtr<CControlPanelNavLinks>
	{
		~CComPtr<CControlPanelNavLinks>();
	};

	struct CComPtr<DirectUI::Value>
	{
		~CComPtr<DirectUI::Value>();
	};

	struct CComPtr<IPageInputParams>
	{
		~CComPtr<IPageInputParams>();
	};

	struct CComPtr<IPropertyBag>
	{
		~CComPtr<IPropertyBag>();
	};

	struct CComPtr<IShellBrowserService>
	{
		~CComPtr<IShellBrowserService>();
	};

	struct CComPtr<ITravelEntry>
	{
		~CComPtr<ITravelEntry>();
	};

	struct CComPtr<ITravelLog>
	{
		~CComPtr<ITravelLog>();
	};

	struct CComPtr<ITravelLogEx>
	{
		~CComPtr<ITravelLogEx>();
	};

	struct CComPtr<IUnknown>
	{
		~CComPtr<IUnknown>();
	};

	struct CComPtrBase<CControlPanelNavLinks>
	{
		~CComPtrBase<CControlPanelNavLinks>();
	};

	struct CComPtrBase<DirectUI::Value>
	{
		~CComPtrBase<DirectUI::Value>();
	};

	struct CComPtrBase<IPageInputParams>
	{
		~CComPtrBase<IPageInputParams>();
	};

	struct CComPtrBase<IPropertyBag>
	{
		~CComPtrBase<IPropertyBag>();
	};

	struct CComPtrBase<IShellBrowserService>
	{
		~CComPtrBase<IShellBrowserService>();
	};

	struct CComPtrBase<ITravelEntry>
	{
		~CComPtrBase<ITravelEntry>();
	};

	struct CComPtrBase<ITravelLog>
	{
		~CComPtrBase<ITravelLog>();
	};

	struct CComPtrBase<ITravelLogEx>
	{
		~CComPtrBase<ITravelLogEx>();
	};

	struct CComPtrBase<IUnknown>
	{
		~CComPtrBase<IUnknown>();
	};

	void AtlThrowImpl(long);
};

class CCertificatePage
{
	Sharp::Util::CSharedPtr<DuiHelper::CEventHandler> CreateEventHandler(void ( CCertificatePage::*)(DirectUI::Event *));
	bool GetUserConsentForOverwrite();
	bool PerformCertificateSaveAction();
	std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> NormalizeTarget(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
	virtual std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetErrorMessage(long,UserOperation);
	void InitializePageComponents();
	void LaunchCertMgr();
	void OnButtonCancelClicked(DirectUI::Event *);
	void OnButtonLaunchCertMgrClicked(DirectUI::Event *);
	void OnButtonOkClicked(DirectUI::Event *);
	void OnButtonSelectCertificateClicked(DirectUI::Event *);
	void OnTextBoxTargetChanged(DirectUI::Event *);
	void PerformCertificateSelect();
	void UpdateOkButton();
protected:
	virtual void InitializePage();
public:
	CCertificatePage();
};

class CCertificatePicker
{
	long DoesClientAuthCertificateExist(int *,void * *,unsigned long *);
public:
	bool Show(Sharp::Util::CSharedPtr<KeyRingDataModel::CCertificateContext> &);
	unsigned long IsClientAuthOnlyCert(_CERT_CONTEXT const *,int *);
};

struct CClassFactory
{
	long CreateInstance(IUnknown *,_GUID const &,void * *);
	long LockServer(int);
	long QueryInterface(_GUID const &,void * *);
	unsigned long AddRef();
	unsigned long Release();
};

struct CControlPanelNavLink
{
	long SetName(HINSTANCE__ *,unsigned int);
};

struct CControlPanelNavLinkCommand
{
	long SetAppletOrCommand(unsigned short const *,unsigned short const *);
	~CControlPanelNavLinkCommand();
};

class CControlPanelNavLinks
{
protected:
	virtual ~CControlPanelNavLinks();
public:
	long Add(CControlPanelNavLink *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CControlPanelPage
{
protected:
	virtual long v_GetSearchTargetServices(_GUID const &,void * *);
public:
	virtual long LayoutInitialized();
	virtual long Notify(unsigned short const *);
	virtual long OnInnerElementDestroyed();
	virtual long OnNavigateAway();
	virtual void LogCPLPerfTrackStopEvent();
	virtual ~CControlPanelPage();
};

struct CElementWithIUnknown
{
	static DirectUI::IClassInfo * Class;
	static long Register();
	virtual DirectUI::IClassInfo * GetClassInfoW();
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual ~CElementWithIUnknown();
};

class CElementWithSite
{
protected:
	virtual ~CElementWithSite();
public:
	static DirectUI::IClassInfo * Class;
	virtual DirectUI::IClassInfo * GetClassInfoW();
	virtual long GetSite(_GUID const &,void * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetSite(IUnknown *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CErrorDialog
{
	void ShowErrorDialog(HWND__ *,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70>,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70>,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70>);
public:
	CErrorDialog(IErrorMessageFormatter &,long,UserOperation);
	void Show(HWND__ *);
};

struct CFocusIndicator
{
	static DirectUI::IClassInfo * Class;
	static long Register();
	virtual DirectUI::IClassInfo * GetClassInfoW();
};

class CGenericCredentialPage
{
	Sharp::Util::CSharedPtr<DuiHelper::CEventHandler> CreateEventHandler(void ( CGenericCredentialPage::*)(DirectUI::Event *));
	bool GetUserConsentForOverwrite();
	bool IsAcceptableUserName();
	bool PerformGenericCredentialSaveAction();
	std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> NormalizeTarget(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
	void InitializePageComponents();
	void OnButtonCancelClicked(DirectUI::Event *);
	void OnButtonOkClicked(DirectUI::Event *);
	void OnTextBoxPasswordChanged(DirectUI::Event *);
	void OnTextBoxTargetChanged(DirectUI::Event *);
	void OnTextBoxUserNameChanged(DirectUI::Event *);
	void SetDefaultValuesOnPage();
	void UpdateOkButton();
protected:
	virtual void InitializePage();
public:
	CGenericCredentialPage();
};

struct CGenericDataHandle
{
	virtual ~CGenericDataHandle();
};

class CHubPage
{
	DirectUI::Element * FindElementOfKeyRing(_GUID const &);
	_GUID GetReqestedKeyRingIdFromPageParameters();
	bool GetUserConsentForDeleteCertificate(KeyRingDataModel::CCertificateCredential *);
	bool GetUserConsentForDeleteGenericCredential(KeyRingDataModel::CGenericCredential *);
	bool GetUserConsentForDeleteOtherCredential(KeyRingDataModel::COtherCredential *);
	bool GetUserConsentForDeleteWebCredential(KeyRingDataModel::CWebCredential *);
	bool GetUserConsentForDeleteWindowsCredential(KeyRingDataModel::CWindowsCredential *);
	bool ShowDeleteTaskDialog(unsigned int,unsigned int,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
	long LoadKeyRingsFromSystem();
	void ClearCredentialDetails();
	void LaunchBackupRestoreApplication(bool);
	void OnBackupKeyRingClicked(DirectUI::Event *);
	void OnDeleteCredentialClicked(DirectUI::Event *);
	void OnEditCredentialClicked(DirectUI::Event *);
	void OnExpandoArrowClicked(DirectUI::Event *);
	void OnHelpLinkClicked(DirectUI::Event *);
	void OnKeyRingClicked(DirectUI::Event *);
	void OnNewCertificateClicked(DirectUI::Event *);
	void OnNewGenericCredentialClicked(DirectUI::Event *);
	void OnNewWindowsCredentialClicked(DirectUI::Event *);
	void OnRestoreKeyRingClicked(DirectUI::Event *);
	void OnShowHideCredentialPasswordClicked(DirectUI::Event *);
	void PerformCredentialDelete(DirectUI::IDataEntry *);
	void PerformCredentialEdit(DirectUI::IDataEntry *);
	void PerformPageRefresh();
	void ProcessKeyRingSelectionChanged(DirectUI::Element *);
	void SetCredentialDetails();
	void SetCredmanKeyRingButtons();
	void SetInitialKeyRingSelection(_GUID const &);
	void SetUserKeyRingButtons();
	void ShowOrHideSecretField(Sharp::Util::CSharedPtr<DuiHelper::CButton>,DirectUI::Element *,KeyRingDataModel::CWebCredential *);
	void UpdateAccessibleNamesForCredentialRepeater(Sharp::Util::CSharedPtr<DuiHelper::CRepeater>,unsigned short * const);
	void UpdateApplicationNamesForCredentialRepeater(Sharp::Util::CSharedPtr<DuiHelper::CRepeater>,unsigned short * const);
	void UpdateKeyRingInformation();
	void UpdateKeyRingTileIcons();
protected:
	virtual void InitializePage();
public:
	CHubPage();
	virtual void OnInvoke(unsigned int,void *);
	virtual void OnPageRefreshed();
	virtual ~CHubPage();
};

class CHubPageInitializer
{
	Sharp::Util::CSharedPtr<DuiHelper::CEventHandler> CreateEventHandler(void ( CHubPage::*)(DirectUI::Event *));
public:
	CHubPageInitializer(CHubPage &);
	void InitializeCredentialDetailsSection();
	void InitializeNavigationPane();
	void InitializePageComponents();
};

class CKeyRingCore
{
	HWND__ * GetParentWindow();
	void InitializePageInternal(DirectUI::Element *);
public:
	CKeyRingCore();
	KeyRingDataModel::CKeyRing * GetSourceKeyRing();
	long InitializePage(DirectUI::Element *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void OnInvoke(unsigned int,void *);
	void SetSourceGenericCredential(KeyRingDataModel::CGenericCredential *);
	void SetSourceKeyRing(KeyRingDataModel::CKeyRing *);
	void SetSourceWebCredential(KeyRingDataModel::CWebCredential *);
	void SetSourceWindowsCredential(KeyRingDataModel::CWindowsCredential *);
	~CKeyRingCore();
};

class CKeyRingInitializer
{
	long CreateAndStoreCodeBehind();
public:
	static long GetExistingCodeBehind(IUnknown *,IUnknown * *);
	virtual long Initialize(IUnknown *,unsigned short *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CKeyRingPage
{
	long EnsureCodeBehind();
public:
	CKeyRingPage();
	static DirectUI::IClassInfo * Class;
	static long Register();
	virtual DirectUI::IClassInfo * GetClassInfoW();
	virtual long LayoutInitialized();
	virtual long Notify(unsigned short const *);
	virtual long OnContentsChanged();
	virtual long OnFolderChanged();
	virtual long OnInnerElementDestroyed();
	virtual long OnSelectedItemChanged();
	virtual long OnSelectionChanged();
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual void OnEvent(DirectUI::Event *);
	virtual void OnInvoke(unsigned int,void *);
	virtual ~CKeyRingPage();
};

class CNavigateButton
{
	static long GetCplRoot(IShellBrowser *,_ITEMIDLIST * *);
	void _Execute();
	void _Navigate();
public:
	static DirectUI::IClassInfo * Class;
	static long Register();
	static void Navigate(unsigned short const *,unsigned short const *,IUnknown *,bool);
	virtual DirectUI::IClassInfo * GetClassInfoW();
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	virtual void OnEvent(DirectUI::Event *);
};

class CPageBase
{
protected:
	virtual void InitializePage();
	void ClearBrowserNavigation(int);
public:
	CPageBase();
	DirectUI::Element * FindChildElement(unsigned short const *);
	virtual std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetErrorMessage(long,UserOperation);
	virtual void Initialize(HWND__ *,DirectUI::Element *,IUnknown *,KeyRingDataModel::CKeyRingData *,CKeyRingCore *);
	virtual void OnEvent(DirectUI::Event *);
	virtual void OnInvoke(unsigned int,void *);
	virtual void OnPageRefreshed();
	virtual ~CPageBase();
};

struct CSecureComDataHandle
{
	~CSecureComDataHandle();
};

struct CVaultAutoPtr<_CREDENTIALW * *,void,void *,0>
{
	~CVaultAutoPtr<_CREDENTIALW * *,void,void *,0>();
};

struct CVaultAutoPtr<_CREDENTIALW *,void,_CREDENTIALW *,0>
{
	~CVaultAutoPtr<_CREDENTIALW *,void,_CREDENTIALW *,0>();
};

struct CVaultAutoPtr<_VAULT_ITEM * *,void,_VAULT_ITEM * *,0>
{
	~CVaultAutoPtr<_VAULT_ITEM * *,void,_VAULT_ITEM * *,0>();
};

struct CVaultAutoPtr<_VAULT_ITEM *,void,_VAULT_ITEM *,0>
{
	~CVaultAutoPtr<_VAULT_ITEM *,void,_VAULT_ITEM *,0>();
};

struct CVaultAutoPtr<_VAULT_ITEM_ELEMENT *,void,_VAULT_ITEM_ELEMENT *,0>
{
	~CVaultAutoPtr<_VAULT_ITEM_ELEMENT *,void,_VAULT_ITEM_ELEMENT *,0>();
};

struct CVaultHeapAllocator
{
	virtual unsigned char * Alloc(unsigned __int64);
	virtual void Free(void *);
};

struct CVaultSecurable
{
	virtual CVaultSid * GetPackageSid();
	virtual EVaultSecurableType GetSecurableType();
	virtual _GUID GetSecurableId();
	virtual void * GetSecurityDescriptor();
};

class CVaultSystemSecurable
{
	static CVaultSystemSecurable m_VaultSystem;
};

class CVaultUXSqmLogger
{
	CVaultUXSqmLogger();
	virtual ~CVaultUXSqmLogger();
public:
	void IncrementDataPointInSqm(unsigned long);
};

class CWindowsCredentialPage
{
	Sharp::Util::CSharedPtr<DuiHelper::CEventHandler> CreateEventHandler(void ( CWindowsCredentialPage::*)(DirectUI::Event *));
	bool GetUserConsentForOverwrite();
	bool IsAcceptableUserName();
	bool PerformWindowsCredentialSaveAction();
	std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> NormalizeTarget(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
	virtual std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetErrorMessage(long,UserOperation);
	void InitializePageComponents();
	void OnButtonCancelClicked(DirectUI::Event *);
	void OnButtonOkClicked(DirectUI::Event *);
	void OnTextBoxPasswordChanged(DirectUI::Event *);
	void OnTextBoxTargetChanged(DirectUI::Event *);
	void OnTextBoxUserNameChanged(DirectUI::Event *);
	void SetDefaultValuesOnPage();
	void UpdateOkButton();
protected:
	virtual void InitializePage();
public:
	CWindowsCredentialPage();
};

struct CertificateDataEngine
{
	virtual DirectUI::IDataEntry * GetEntry(unsigned int);
	virtual unsigned int GetSize();
	virtual ~CertificateDataEngine();
};

struct ComboBoxEx
{
	static DirectUI::IClassInfo * Class;
	static UID ComboBoxExpanded;
	static long Register();
	virtual DirectUI::IClassInfo * GetClassInfoW();
	virtual bool OnNotify(unsigned int,unsigned __int64,__int64,__int64 *);
};

namespace DirectUI
{
	struct ClassInfo<CElementWithIUnknown,Element,StandardCreator<CElementWithIUnknown> >
	{
		virtual IClassInfo * GetBaseClass();
		virtual long CreateInstance(Element *,unsigned long *,Element * *);
		virtual void Destroy();
	};

	struct ClassInfo<CElementWithSite,CElementWithIUnknown,StandardCreator<CElementWithSite> >
	{
		static long Register(unsigned short const *,PropertyInfo const * const *,unsigned int);
		virtual IClassInfo * GetBaseClass();
		virtual long CreateInstance(Element *,unsigned long *,Element * *);
		virtual void Destroy();
	};

	struct ClassInfo<CFocusIndicator,Element,StandardCreator<CFocusIndicator> >
	{
		virtual IClassInfo * GetBaseClass();
		virtual long CreateInstance(Element *,unsigned long *,Element * *);
		virtual void Destroy();
	};

	struct ClassInfo<CFrameModule,CElementWithSite,StandardCreator<CFrameModule> >
	{
		static long Register(unsigned short const *,PropertyInfo const * const *,unsigned int);
		virtual IClassInfo * GetBaseClass();
		virtual long CreateInstance(Element *,unsigned long *,Element * *);
		virtual void Destroy();
	};

	struct ClassInfo<CKeyRingPage,CElementWithSite,StandardCreator<CKeyRingPage> >
	{
		virtual IClassInfo * GetBaseClass();
		virtual long CreateInstance(Element *,unsigned long *,Element * *);
		virtual void Destroy();
	};

	struct ClassInfo<CNavigateButton,CElementWithSite,StandardCreator<CNavigateButton> >
	{
		virtual IClassInfo * GetBaseClass();
		virtual long CreateInstance(Element *,unsigned long *,Element * *);
		virtual void Destroy();
	};

	struct ClassInfo<ComboBoxEx,Combobox,StandardCreator<ComboBoxEx> >
	{
		virtual IClassInfo * GetBaseClass();
		virtual long CreateInstance(Element *,unsigned long *,Element * *);
		virtual void Destroy();
	};

	struct ClassInfo<ElementEx,Element,StandardCreator<ElementEx> >
	{
		virtual IClassInfo * GetBaseClass();
		virtual long CreateInstance(Element *,unsigned long *,Element * *);
		virtual void Destroy();
	};

	struct ClassInfoBase
	{
		virtual HINSTANCE__ * GetModule();
		virtual PropertyInfo const * EnumPropertyInfo(unsigned int);
		virtual PropertyInfo const * GetByClassIndex(unsigned int);
		virtual bool IsGlobal();
		virtual bool IsSubclassOf(IClassInfo *);
		virtual bool IsValidProperty(PropertyInfo const *);
		virtual int GetChildren();
		virtual int Release();
		virtual unsigned int GetGlobalIndex();
		virtual unsigned int GetPICount();
		virtual unsigned short const * GetName();
		virtual void AddChild();
		virtual void AddRef();
		virtual void AssertPIZeroRef();
		virtual void RemoveChild();
	};

	struct Combobox
	{
		virtual HWND__ * CreateHWND(HWND__ *);
		virtual int OnAdjustWindowSize(int,int,unsigned int);
		virtual tagSIZE GetContentSize(int,int,Surface *);
		virtual void OnHosted(Element *);
		virtual void OnInput(InputEvent *);
		virtual void OnPropertyChanged(PropertyInfo const *,int,Value *,Value *);
	};

	class Element
	{
	protected:
		virtual tagSIZE _SelfLayoutUpdateDesiredSize(int,int,Surface *);
		virtual void ActivateTooltip(Element *,unsigned long);
		virtual void OnHosted(Element *);
		virtual void OnUnHosted(Element *);
		virtual void RemoveTooltip(Element *);
		virtual void UpdateTooltip(Element *);
		virtual void _SelfLayoutDoLayout(int,int);
	public:
		virtual Element * GetAdjacent(Element *,int,NavReference const *,unsigned long);
		virtual Element * GetUiaFocusDelegate();
		virtual bool EnsureVisible(int,int,int,int);
		virtual bool GetKeyFocused();
		virtual bool IsContentProtected();
		virtual bool IsRTLReading();
		virtual bool OnPropertyChanging(PropertyInfo *,int,Value *,Value *);
		virtual bool OnPropertyChanging(PropertyInfo const *,int,Value *,Value *);
		virtual long Add(Element * *,unsigned int);
		virtual long AddBehavior(IDuiBehavior *);
		virtual long DefaultAction();
		virtual long GetAccessibleImpl(IAccessible * *);
		virtual long GetElementProviderImpl(InvokeHelper *,ElementProvider * *);
		virtual long GetUIAElementProvider(_GUID const &,void * *);
		virtual long Insert(Element * *,unsigned int,unsigned int);
		virtual long QueryInterface(_GUID const &,void * *);
		virtual long Remove(Element * *,unsigned int);
		virtual long RemoveBehavior(IDuiBehavior *);
		virtual tagSIZE GetContentSize(int,int,Surface *);
		virtual unsigned int MessageCallback(tagGMSG *);
		virtual unsigned short const * GetContentStringAsDisplayed(Value * *);
		virtual void GetImmersiveFocusRectOffsets(tagRECT *);
		virtual void HandleUiaDestroyListener();
		virtual void HandleUiaEventListener(Event *);
		virtual void HandleUiaPropertyChangingListener(PropertyInfo const *);
		virtual void HandleUiaPropertyListener(PropertyInfo const *,int,Value *,Value *);
		virtual void OnDestroy();
		virtual void OnEvent(Event *);
		virtual void OnGroupChanged(int,bool);
		virtual void OnInput(InputEvent *);
		virtual void OnKeyFocusMoved(Element *,Element *);
		virtual void OnMouseFocusMoved(Element *,Element *);
		virtual void OnPropertyChanged(PropertyInfo *,int,Value *,Value *);
		virtual void OnPropertyChanged(PropertyInfo const *,int,Value *,Value *);
		virtual void Paint(HDC__ *,tagRECT const *,tagRECT const *,tagRECT *,tagRECT *);
		virtual void SetKeyFocus();
	};

	class HWNDHost
	{
	protected:
		virtual bool EraseBkgnd(HDC__ *,__int64 *);
		virtual void OnUnHosted(Element *);
	public:
		virtual HWND__ * GetHWND();
		virtual bool GetKeyFocused();
		virtual bool OnCtrlThemeChanged(unsigned int,unsigned __int64,__int64,__int64 *);
		virtual bool OnMessage(unsigned int,unsigned __int64,__int64,__int64 *);
		virtual bool OnSinkThemeChanged(unsigned int,unsigned __int64,__int64,__int64 *);
		virtual bool OnSysChar(unsigned short);
		virtual long GetAccessibleImpl(IAccessible * *);
		virtual unsigned int MessageCallback(tagGMSG *);
		virtual void OnDestroy();
		virtual void OnEvent(Event *);
		virtual void OnWindowStyleChanged(unsigned __int64,tagSTYLESTRUCT const *);
		virtual void Paint(HDC__ *,tagRECT const *,tagRECT const *,tagRECT *,tagRECT *);
		virtual void SetKeyFocus();
		virtual void SetWindowDirection(HWND__ *);
	};

	struct Value
	{
		static Value * GetAtomZero();
		static Value * GetStringNull();
	};

	struct XProvider
	{
		virtual int ClickDefaultButton();
		virtual int FindElementWithShortcutAndDoDefaultAction(unsigned short,int);
		virtual long CanSetFocus(bool *);
		virtual long CreateXBaby(IXElementCP *,HWND__ *,Element *,unsigned long *,IXBaby * *);
		virtual long ForceThemeChange(unsigned __int64,__int64);
		virtual long GetDesiredSize(int,int,tagSIZE *);
		virtual long GetHostedElementID(unsigned short *);
		virtual long IsDescendent(Element *,bool *);
		virtual long Navigate(int,bool *);
		virtual long SetButtonClassAcceptsEnterKey(bool);
		virtual long SetDefaultButtonTracking(bool);
		virtual long SetFocus(Element *);
		virtual long SetParameter(_GUID const &,void *);
		virtual long SetRegisteredDefaultButton(Element *);
	};

};

namespace DuiHelper
{
	class CButton
	{
	protected:
		virtual void HandleEvent(DirectUI::Event *);
	};

	class CControl
	{
	protected:
		virtual bool IsEventOwnedByControl(DirectUI::Event *);
		virtual void HandleEvent(DirectUI::Event *);
	public:
		CControl(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,DirectUI::Element *);
		void Disable();
		void Enable();
		void RemoveFromPage();
		void SetBorderStyle(int);
		void SetPageElement(DirectUI::Element *);
		void SetText(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
		void ShowOnPage(int);
		~CControl();
	};

	struct CControlList
	{
		void Add(CControl *);
		~CControlList();
	};

	struct CIcon
	{
		CIcon(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,DirectUI::Element *);
		void SetIconFromResources(HINSTANCE__ * const,unsigned int,unsigned long);
		~CIcon();
	};

	struct CMemberFunctionEventHandler<CCertificatePage>
	{
		virtual void operator()(DirectUI::Event *);
	};

	struct CMemberFunctionEventHandler<CGenericCredentialPage>
	{
		virtual void operator()(DirectUI::Event *);
	};

	struct CMemberFunctionEventHandler<CHubPage>
	{
		virtual void operator()(DirectUI::Event *);
	};

	struct CMemberFunctionEventHandler<CWindowsCredentialPage>
	{
		virtual void operator()(DirectUI::Event *);
	};

	class CNavigationPaneCplLink
	{
	protected:
		virtual void PopulateLinkSpecificProperties(CControlPanelNavLink *,int);
	public:
		CNavigationPaneCplLink(HINSTANCE__ *,unsigned int,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
	};

	struct CNavigationPaneLink
	{
		CNavigationPaneLink(HINSTANCE__ *,unsigned int);
		virtual void OnClicked();
		virtual ~CNavigationPaneLink();
	};

	class CNavigationPaneLinks
	{
		void PopulateNavigationLinksFromVector(CControlPanelNavLinks *,bool,int);
	public:
		CNavigationPaneLinks(IUnknown *);
		void OnNavTaskLinkClicked(int);
		void UpdateNavigationPane();
	};

	struct CRepeater
	{
		void Clear();
		void PopulateData(DirectUI::IDataEngine *);
	};

	struct CTextBox
	{
		CTextBox(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,DirectUI::Element *);
		KeyRing::CSecureString<unsigned short,std::char_traits<unsigned short> > GetEncodedContentString();
		std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetContentString();
		void SetContentString(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
		void SetEncodedContentString(KeyRing::CSecureString<unsigned short,std::char_traits<unsigned short> > const &);
	};

	struct CTextBoxListener
	{
		virtual bool OnListenedPropertyChanging(DirectUI::Element *,DirectUI::PropertyInfo const *,int,DirectUI::Value *,DirectUI::Value *);
		virtual void OnListenedEvent(DirectUI::Element *,DirectUI::Event *);
		virtual void OnListenedInput(DirectUI::Element *,DirectUI::InputEvent *);
		virtual void OnListenedPropertyChanged(DirectUI::Element *,DirectUI::PropertyInfo const *,int,DirectUI::Value *,DirectUI::Value *);
		virtual void OnListenerAttach(DirectUI::Element *);
		virtual void OnListenerDetach(DirectUI::Element *);
	};

};

struct ElementEx
{
	long Initialize(unsigned int,DirectUI::Element *,unsigned long *);
	static DirectUI::IClassInfo * Class;
	static long Register();
	virtual DirectUI::IClassInfo * GetClassInfoW();
	virtual void OnPropertyChanged(DirectUI::PropertyInfo const *,int,DirectUI::Value *,DirectUI::Value *);
};

class FrameProvider
{
protected:
	virtual ~FrameProvider();
public:
	FrameProvider(HINSTANCE__ *,unsigned short const *);
	long Init();
	virtual long CreateDUI(DirectUI::IXElementCP *,HWND__ * *);
	virtual long GetSite(_GUID const &,void * *);
	virtual long LayoutInitialized();
	virtual long Notify(unsigned short const *);
	virtual long OnContentsChanged();
	virtual long OnFolderChanged();
	virtual long OnInnerElementDestroyed();
	virtual long OnNavigateAway();
	virtual long OnSelectedItemChanged();
	virtual long OnSelectionChanged();
	virtual long OptionallyTakeInitialFocus(int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long QueryService(_GUID const &,_GUID const &,void * *);
	virtual long SetResourceID(unsigned int);
	virtual long SetSite(IUnknown *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct GenericCredentialDataEngine
{
	virtual DirectUI::IDataEntry * GetEntry(unsigned int);
	virtual unsigned int GetSize();
	virtual ~GenericCredentialDataEngine();
};

struct IVaultSecurable
{
	virtual ~IVaultSecurable();
};

namespace KeyRing
{
	struct CSecureString<unsigned short,std::char_traits<unsigned short> >
	{
		CSecureString<unsigned short,std::char_traits<unsigned short> > & operator=(CSecureString<unsigned short,std::char_traits<unsigned short> > const &);
		CSecureString<unsigned short,std::char_traits<unsigned short> >();
		CSecureString<unsigned short,std::char_traits<unsigned short> >(CSecureString<unsigned short,std::char_traits<unsigned short> > const &);
		void assign(unsigned short const *);
		~CSecureString<unsigned short,std::char_traits<unsigned short> >();
	};

	struct SecureAllocator<unsigned short>
	{
		unsigned short * allocate(unsigned __int64,void const *);
		void deallocate(unsigned short *,unsigned __int64);
	};

};

namespace KeyRingDataModel
{
	class CCertificateContext
	{
		std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetCertNameString(_CERT_CONTEXT const *,bool);
		void InitializeCertificateContext(_CERT_CONTEXT const *);
	public:
		CCertificateContext(_CERT_CONTEXT const *);
		CCertificateContext(_CERT_CONTEXT const *,KeyRing::CSecureString<unsigned short,std::char_traits<unsigned short> > const &);
		~CCertificateContext();
	};

	class CCertificateCredential
	{
		void RetrieveCertificateFieldsFromStore(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70>);
	public:
		CCertificateCredential(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,_FILETIME,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,unsigned long,unsigned long);
		virtual long GetProperty(unsigned short const *,unsigned short * *,bool *);
		virtual void * GetActual();
	};

	struct CCredential
	{
		CCredential(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,void * const,_FILETIME,unsigned long);
		std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetCredentialName();
		virtual ~CCredential();
	};

	struct CGenericCredential
	{
		std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetTarget();
		virtual long GetProperty(unsigned short const *,unsigned short * *,bool *);
		virtual void * GetActual();
	};

	class CKeyRing
	{
		std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetExpandedLocation(unsigned short * const);
		std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetSchemaNameFromId(_GUID,void *);
		void DeleteCredentialOnSystem(unsigned short * const,unsigned short * const,void * const,_GUID const *);
		void ProcessSingleOtherCredential(_VAULT_ITEM *,void *);
		void ProcessSingleSspCredential(_VAULT_ITEM *,void *);
		void ProcessSingleVaultItem(_VAULT_ITEM *,void *);
		void ProcessSingleWebVaultItem(_VAULT_ITEM *);
	public:
		CGenericCredential * GetGenericCredentialByTarget(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
		CKeyRing(_GUID const &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
		CWindowsCredential * GetWindowsCredentialByTarget(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
		bool GenericCredentialExistsOnSystem(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
		bool GetMatchingItemFromVault(void *,unsigned short * const,unsigned short * const,void * const,_GUID const *,HWND__ *,_VAULT_ITEM * *);
		bool ReadWebCredentialPasswordOnSystem(CWebCredential &,HWND__ *);
		bool UserConsentForShowPassword(HWND__ *);
		bool WindowsCredentialExistsOnSystem(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
		virtual long GetProperty(unsigned short const *,unsigned short * *,bool *);
		virtual void * GetActual();
		virtual ~CKeyRing();
		void CreateCertificateCredentialOnSystem(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,KeyRing::CSecureString<unsigned short,std::char_traits<unsigned short> > const &,unsigned long);
		void CreateGenericCredentialOnSystem(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,KeyRing::CSecureString<unsigned short,std::char_traits<unsigned short> > const &,bool,unsigned long,unsigned long);
		void CreateWindowsCredentialOnSystem(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,KeyRing::CSecureString<unsigned short,std::char_traits<unsigned short> > const &,bool,unsigned long,unsigned long);
		void DeleteCertificateCredentialOnSystem(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
		void DeleteGenericCredentialOnSystem(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
		void DeleteOtherCredentialOnSystem(_GUID,Sharp::Util::CSharedPtr<_VAULT_ITEM_ELEMENT>,Sharp::Util::CSharedPtr<_VAULT_ITEM_ELEMENT>,void * const);
		void DeleteWebCredentialOnSystem(CWStringWithNull const &,CWStringWithNull const &,void * const);
		void DeleteWindowsCredentialOnSystem(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
		void ReadCredentialsFromSystem();
	};

	class CKeyRingData
	{
		Sharp::Util::CSharedPtr<CKeyRing> ReadKeyRingInformationFromSystem(_GUID const &);
	public:
		CKeyRing * GetKeyRingById(_GUID &);
		std::vector<Sharp::Util::CSharedPtr<CKeyRing>,std::allocator<Sharp::Util::CSharedPtr<CKeyRing> > > & GetAvailableKeyRings();
		virtual DirectUI::IDataEntry * GetEntry(unsigned int);
		virtual unsigned int GetSize();
		virtual ~CKeyRingData();
		void ReadKeyRingsFromSystem(bool);
	};

	struct COtherCredential
	{
		COtherCredential(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,_FILETIME,_GUID,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,_VAULT_ITEM_ELEMENT *,_VAULT_ITEM_ELEMENT *,void * const,unsigned long);
		Sharp::Util::CSharedPtr<_VAULT_ITEM_ELEMENT> GetIdentity();
		Sharp::Util::CSharedPtr<_VAULT_ITEM_ELEMENT> GetResource();
		virtual long GetProperty(unsigned short const *,unsigned short * *,bool *);
		virtual void * GetActual();
		virtual ~COtherCredential();
	};

	struct CWStringWithNull
	{
		~CWStringWithNull();
	};

	struct CWebCredential
	{
		virtual long GetProperty(unsigned short const *,unsigned short * *,bool *);
		virtual void * GetActual();
	};

	struct CWindowsCredential
	{
		std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetTarget();
		virtual long GetProperty(unsigned short const *,unsigned short * *,bool *);
		virtual void * GetActual();
	};

	bool IsGuestToken();
	std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> ConvertFiletimeToStringRepresentation(_FILETIME);
	std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetFriendlyNameForCredmanCredential(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &,bool,unsigned long);
	std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetPersistenceLevelName(unsigned long);
};

struct OtherCredentialDataEngine
{
	virtual DirectUI::IDataEntry * GetEntry(unsigned int);
	virtual unsigned int GetSize();
	virtual ~OtherCredentialDataEngine();
};

namespace Sharp
{
	namespace Util
	{
		class CClassLevelLockable<CVaultUXSqmLogger>
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

		class CRefCount
		{
		protected:
			virtual ~CRefCount();
		};

		struct CScopedPtr<CControlPanelNavLink>
		{
			~CScopedPtr<CControlPanelNavLink>();
		};

		struct CScopedPtr<CPageBase>
		{
			void Reset(CPageBase *);
			~CScopedPtr<CPageBase>();
		};

		struct CSharedPtr<DuiHelper::CButton>
		{
			struct CRefCountHolder
			{
				virtual ~CRefCountHolder();
			};

			CSharedPtr<DuiHelper::CButton>(DuiHelper::CButton *);
			~CSharedPtr<DuiHelper::CButton>();
		};

		struct CSharedPtr<DuiHelper::CEventHandler>
		{
			CSharedPtr<DuiHelper::CEventHandler> & operator=(CSharedPtr<DuiHelper::CEventHandler> const &);
			CSharedPtr<DuiHelper::CEventHandler>(DuiHelper::CEventHandler *);
			void Reset(DuiHelper::CEventHandler *);
			~CSharedPtr<DuiHelper::CEventHandler>();
		};

		struct CSharedPtr<DuiHelper::CLabel>
		{
			struct CRefCountHolder
			{
				virtual ~CRefCountHolder();
			};

			CSharedPtr<DuiHelper::CLabel>(DuiHelper::CLabel *);
			~CSharedPtr<DuiHelper::CLabel>();
		};

		struct CSharedPtr<DuiHelper::CNavigationPaneLink>
		{
			CSharedPtr<DuiHelper::CNavigationPaneLink> & operator=(CSharedPtr<DuiHelper::CNavigationPaneLink> const &);
			CSharedPtr<DuiHelper::CNavigationPaneLink>(DuiHelper::CNavigationPaneLink *);
			~CSharedPtr<DuiHelper::CNavigationPaneLink>();
		};

		struct CSharedPtr<DuiHelper::CNavigationPaneLinks>
		{
			CSharedPtr<DuiHelper::CNavigationPaneLinks>(DuiHelper::CNavigationPaneLinks *);
			~CSharedPtr<DuiHelper::CNavigationPaneLinks>();
		};

		struct CSharedPtr<DuiHelper::CPane>
		{
			struct CRefCountHolder
			{
				virtual ~CRefCountHolder();
			};

			CSharedPtr<DuiHelper::CPane>(DuiHelper::CPane *);
			~CSharedPtr<DuiHelper::CPane>();
		};

		struct CSharedPtr<DuiHelper::CRepeater>
		{
			struct CRefCountHolder
			{
				virtual ~CRefCountHolder();
			};

			CSharedPtr<DuiHelper::CRepeater>(DuiHelper::CRepeater *);
			~CSharedPtr<DuiHelper::CRepeater>();
		};

		struct CSharedPtr<DuiHelper::CTextBox>
		{
			struct CRefCountHolder
			{
				virtual ~CRefCountHolder();
			};

			CSharedPtr<DuiHelper::CTextBox>(DuiHelper::CTextBox *);
			~CSharedPtr<DuiHelper::CTextBox>();
		};

		struct CSharedPtr<DuiHelper::CTextBoxListener>
		{
			CSharedPtr<DuiHelper::CTextBoxListener>(DuiHelper::CTextBoxListener *);
			~CSharedPtr<DuiHelper::CTextBoxListener>();
		};

		struct CSharedPtr<KeyRingDataModel::CCertificateContext>
		{
			CSharedPtr<KeyRingDataModel::CCertificateContext>(KeyRingDataModel::CCertificateContext *);
			void Reset(KeyRingDataModel::CCertificateContext *);
			~CSharedPtr<KeyRingDataModel::CCertificateContext>();
		};

		struct CSharedPtr<KeyRingDataModel::CCredential>
		{
			CSharedPtr<KeyRingDataModel::CCredential> & operator=(CSharedPtr<KeyRingDataModel::CCredential> const &);
			CSharedPtr<KeyRingDataModel::CCredential>(KeyRingDataModel::CCredential *);
			~CSharedPtr<KeyRingDataModel::CCredential>();
		};

		struct CSharedPtr<KeyRingDataModel::CKeyRing>
		{
			CSharedPtr<KeyRingDataModel::CKeyRing> & operator=(CSharedPtr<KeyRingDataModel::CKeyRing> const &);
			CSharedPtr<KeyRingDataModel::CKeyRing>(KeyRingDataModel::CKeyRing *);
			~CSharedPtr<KeyRingDataModel::CKeyRing>();
		};

		struct CSharedPtr<_VAULT_ITEM_ELEMENT>
		{
			CSharedPtr<_VAULT_ITEM_ELEMENT>(_VAULT_ITEM_ELEMENT *);
			void Reset(_VAULT_ITEM_ELEMENT *);
			~CSharedPtr<_VAULT_ITEM_ELEMENT>();
		};

		class CSingletonHolder<CVaultUXSqmLogger,CDefaultLifetime,CClassLevelLockable>
		{
			static CVaultUXSqmLogger * gm_pTheInstance;
			static bool gm_fDestroyed;
			static void DestroySingleton();
		public:
			static CVaultUXSqmLogger & Instance();
		};

		struct CSmartHandle<HICON__ *,ICON_HANDLE_RELEASER>
		{
			~CSmartHandle<HICON__ *,ICON_HANDLE_RELEASER>();
		};

		struct CSmartHandle<_CERT_CONTEXT const *,CERTIFICATE_CONTEXT_HANDLE_RELEASER>
		{
			~CSmartHandle<_CERT_CONTEXT const *,CERTIFICATE_CONTEXT_HANDLE_RELEASER>();
		};

		struct CSmartHandle<unsigned short *,RPC_WSTRING_RELEASER>
		{
			~CSmartHandle<unsigned short *,RPC_WSTRING_RELEASER>();
		};

		struct CSmartHandle<void *,CERTIFICATE_STORE_HANDLE_RELEASER>
		{
			~CSmartHandle<void *,CERTIFICATE_STORE_HANDLE_RELEASER>();
		};

		struct CSmartHandle<void *,COM_DATA_RELEASER>
		{
			~CSmartHandle<void *,COM_DATA_RELEASER>();
		};

		struct CSmartHandle<void *,CREDMAN_DATA_RELEASER>
		{
			~CSmartHandle<void *,CREDMAN_DATA_RELEASER>();
		};

		struct CSmartHandle<void *,HANDLE_RELEASER>
		{
			~CSmartHandle<void *,HANDLE_RELEASER>();
		};

		struct CSmartHandle<void *,VAULT_DATA_HANDLE_RELEASER>
		{
			~CSmartHandle<void *,VAULT_DATA_HANDLE_RELEASER>();
		};

		struct CSmartHandle<void *,VAULT_HANDLE_RELEASER>
		{
			~CSmartHandle<void *,VAULT_HANDLE_RELEASER>();
		};

		namespace StringHandler
		{
			std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> & Format(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> &,HINSTANCE__ *,unsigned int,...);
			std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> & Format(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> &,unsigned short const *,...);
			std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> & ToLowercase<std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> >(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> &);
			std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GuidToString(_GUID const &);
			std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> Load(HINSTANCE__ *,unsigned int);
		};

		struct standard_exception
		{
			standard_exception(long,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
			standard_exception(standard_exception const &);
			virtual ~standard_exception();
		};

		long GetLastHResult();
		long HResultFromStdException(exception const &);
		long Win32ErrorToHResult(unsigned long);
	};

};

struct WebCredentialDataEngine
{
	virtual DirectUI::IDataEntry * GetEntry(unsigned int);
	virtual unsigned int GetSize();
	virtual ~WebCredentialDataEngine();
};

struct WindowsCredentialDataEngine
{
	virtual DirectUI::IDataEntry * GetEntry(unsigned int);
	virtual unsigned int GetSize();
	virtual ~WindowsCredentialDataEngine();
};

struct data_model_exception
{
	data_model_exception(data_model_exception const &);
	data_model_exception(long);
	virtual ~data_model_exception();
};

struct dui_helper_exception
{
	dui_helper_exception(dui_helper_exception const &);
	dui_helper_exception(long);
	virtual ~dui_helper_exception();
};

struct exception
{
	exception(exception const &);
	virtual char const * what();
};

struct keyring_ui_exception
{
	keyring_ui_exception(keyring_ui_exception const &);
	keyring_ui_exception(long);
	virtual ~keyring_ui_exception();
};

namespace std
{
	struct _String_base
	{
		static void _Xlen();
		static void _Xran();
	};

	class _Tree<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >
	{
	protected:
		_Tree<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::iterator _Insert(bool,_Tree_nod<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::_Node *,pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > const &);
		_Tree_nod<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::_Node * _Buynode();
		_Tree_nod<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::_Node * _Buynode(_Tree_nod<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::_Node *,_Tree_nod<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::_Node *,_Tree_nod<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::_Node *,pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > const &,char);
		void _Erase(_Tree_nod<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::_Node *);
	public:
		_Tree<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::iterator insert(_Tree<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::iterator,pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > const &);
		pair<_Tree<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::iterator,bool> insert(pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > const &);
		~_Tree<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >();
	};

	class _Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >
	{
	protected:
		_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator _Insert(bool,_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *,pair<unsigned long const ,SE> const &);
		_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node * _Buynode();
		_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node * _Buynode(_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *,_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *,_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *,pair<unsigned long const ,SE> const &,char);
		void _Erase(_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *);
	public:
		_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator insert(_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::iterator,pair<unsigned long const ,SE> const &);
		~_Tree<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >();
	};

	struct allocator<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> >
	{
		void deallocate(Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> *,unsigned __int64);
	};

	struct allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> >
	{
		void deallocate(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> *,unsigned __int64);
	};

	struct allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> >
	{
		void deallocate(Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> *,unsigned __int64);
	};

	struct allocator<_List_nod<DuiHelper::CControl *,allocator<DuiHelper::CControl *> >::_Node>
	{
		void deallocate(_List_nod<DuiHelper::CControl *,allocator<DuiHelper::CControl *> >::_Node *,unsigned __int64);
	};

	struct allocator<_Tree_nod<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::_Node>
	{
		void deallocate(_Tree_nod<_Tmap_traits<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > >,0> >::_Node *,unsigned __int64);
	};

	struct allocator<_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node>
	{
		void deallocate(_Tree_nod<_Tmap_traits<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> >,0> >::_Node *,unsigned __int64);
	};

	struct allocator<unsigned char>
	{
		void deallocate(unsigned char *,unsigned __int64);
	};

	struct allocator<unsigned short>
	{
		void deallocate(unsigned short *,unsigned __int64);
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
		void _Copy(unsigned __int64,unsigned __int64);
		void _Tidy(bool,unsigned __int64);
	public:
		basic_string<char,char_traits<char>,allocator<char>,_STL70> & assign(basic_string<char,char_traits<char>,allocator<char>,_STL70> const &,unsigned __int64,unsigned __int64);
		basic_string<char,char_traits<char>,allocator<char>,_STL70> & assign(char const *,unsigned __int64);
		basic_string<char,char_traits<char>,allocator<char>,_STL70> & erase(unsigned __int64,unsigned __int64);
		basic_string<char,char_traits<char>,allocator<char>,_STL70>(char const *);
		~basic_string<char,char_traits<char>,allocator<char>,_STL70>();
	};

	class basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>
	{
	protected:
		bool _Grow(unsigned __int64,bool);
		void _Copy(unsigned __int64,unsigned __int64);
		void _Tidy(bool,unsigned __int64);
	public:
		basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> & append(basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const &,unsigned __int64,unsigned __int64);
		basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> & append(unsigned short const *);
		basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> & assign(basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const &,unsigned __int64,unsigned __int64);
		basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> & assign(unsigned short const *);
		basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> & assign<_Vector_iterator<unsigned short,allocator<unsigned short> > >(_Vector_iterator<unsigned short,allocator<unsigned short> >,_Vector_iterator<unsigned short,allocator<unsigned short> >);
		basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> & erase(unsigned __int64,unsigned __int64);
		basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> & replace(unsigned __int64,unsigned __int64,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const &,unsigned __int64,unsigned __int64);
		basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> substr(unsigned __int64,unsigned __int64);
		basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>(unsigned short const *);
		int compare(basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const &);
		int compare(unsigned short const *);
		unsigned __int64 find(unsigned short const *,unsigned __int64,unsigned __int64);
		void _Construct<_Vector_iterator<unsigned short,allocator<unsigned short> > >(_Vector_iterator<unsigned short,allocator<unsigned short> >,_Vector_iterator<unsigned short,allocator<unsigned short> >,forward_iterator_tag);
		~basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>();
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

	class list<DuiHelper::CControl *,allocator<DuiHelper::CControl *> >
	{
	protected:
		_List_nod<DuiHelper::CControl *,allocator<DuiHelper::CControl *> >::_Node * _Buynode();
		_List_nod<DuiHelper::CControl *,allocator<DuiHelper::CControl *> >::_Node * _Buynode(_List_nod<DuiHelper::CControl *,allocator<DuiHelper::CControl *> >::_Node *,_List_nod<DuiHelper::CControl *,allocator<DuiHelper::CControl *> >::_Node *,DuiHelper::CControl * const &);
	public:
		~list<DuiHelper::CControl *,allocator<DuiHelper::CControl *> >();
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

	struct map<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > > >
	{
		basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> & operator[](basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const &);
		~map<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70>,less<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >,allocator<pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> > > >();
	};

	struct map<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> > >
	{
		SE & operator[](unsigned long const &);
		~map<unsigned long,SE,less<unsigned long>,allocator<pair<unsigned long const ,SE> > >();
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

	struct pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >
	{
		~pair<basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> const ,basic_string<unsigned short,char_traits<unsigned short>,allocator<unsigned short>,_STL70> >();
	};

	class vector<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink>,allocator<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> *,Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> *);
		void _Insert_n(_Vector_iterator<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink>,allocator<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> > >,unsigned __int64,Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> const &);
	public:
		~vector<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink>,allocator<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> > >();
	};

	class vector<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> *,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> *);
		void _Insert_n(_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,unsigned __int64,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &);
	public:
		_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > > erase(_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >);
		~vector<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >();
	};

	class vector<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> > >
	{
	protected:
		static void _Xlen();
		void _Destroy(Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> *,Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> *);
		void _Insert_n(_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> > >,unsigned __int64,Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> const &);
	public:
		~vector<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> > >();
	};

	struct vector<unsigned char,allocator<unsigned char> >
	{
		void reserve(unsigned __int64);
		~vector<unsigned char,allocator<unsigned char> >();
	};

	class vector<unsigned short,KeyRing::SecureAllocator<unsigned short> >
	{
	protected:
		static void _Xlen();
		void _Insert_n(_Vector_iterator<unsigned short,KeyRing::SecureAllocator<unsigned short> >,unsigned __int64,unsigned short const &);
	public:
		void _Insert<_Vector_const_iterator<unsigned short,KeyRing::SecureAllocator<unsigned short> > >(_Vector_iterator<unsigned short,KeyRing::SecureAllocator<unsigned short> >,_Vector_const_iterator<unsigned short,KeyRing::SecureAllocator<unsigned short> >,_Vector_const_iterator<unsigned short,KeyRing::SecureAllocator<unsigned short> >,forward_iterator_tag);
		void resize(unsigned __int64);
		~vector<unsigned short,KeyRing::SecureAllocator<unsigned short> >();
	};

	class vector<unsigned short,allocator<unsigned short> >
	{
	protected:
		static void _Xlen();
		void _Insert_n(_Vector_iterator<unsigned short,allocator<unsigned short> >,unsigned __int64,unsigned short const &);
		void _Tidy();
	public:
		void _Construct_n(unsigned __int64,unsigned short const &);
		void resize(unsigned __int64);
		~vector<unsigned short,allocator<unsigned short> >();
	};

	Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> * _Uninit_copy<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> *,Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> *,allocator<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> > >(Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> *,Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> *,Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> *,std::allocator<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> * _Uninit_copy<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> *,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> *,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> *,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> *,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> *,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> * _Uninit_copy<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> *,Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> *,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> > >(Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> *,Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> *,Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> *,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	char const * const _bad_alloc_Message;
	nothrow_t const std::nothrow;
	std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > > find_if<_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,KeyRingDataModel::CertificateCredentialComparison>(std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,KeyRingDataModel::CertificateCredentialComparison);
	std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > > find_if<_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,KeyRingDataModel::GenericCredentialComparison>(std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,KeyRingDataModel::GenericCredentialComparison);
	std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > > find_if<_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,KeyRingDataModel::OtherCredentialComparison>(std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,KeyRingDataModel::OtherCredentialComparison);
	std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > > find_if<_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,KeyRingDataModel::WindowsCredentialComparison>(std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,KeyRingDataModel::WindowsCredentialComparison);
	std::pair<std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > > > _Unguarded_partition<_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,bool (*)(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &)>(std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,bool (*)(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &));
	unsigned char * _Uninit_copy<_Vector_iterator<unsigned char,allocator<unsigned char> >,unsigned char *,allocator<unsigned char> >(std::_Vector_iterator<unsigned char,std::allocator<unsigned char> >,std::_Vector_iterator<unsigned char,std::allocator<unsigned char> >,unsigned char *,std::allocator<unsigned char> &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	unsigned short * _Uninit_copy<_Vector_const_iterator<unsigned short,KeyRing::SecureAllocator<unsigned short> >,unsigned short *,KeyRing::SecureAllocator<unsigned short> >(std::_Vector_const_iterator<unsigned short,KeyRing::SecureAllocator<unsigned short> >,std::_Vector_const_iterator<unsigned short,KeyRing::SecureAllocator<unsigned short> >,unsigned short *,KeyRing::SecureAllocator<unsigned short> &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Adjust_heap<_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,__int64,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,bool (*)(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &)>(std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,__int64,__int64,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,bool (*)(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &));
	void _Med3<_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,bool (*)(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &)>(std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,bool (*)(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &));
	void _Sort<_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,__int64,bool (*)(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &)>(std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,__int64,bool (*)(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &));
	void _Uninit_fill_n<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> *,unsigned __int64,Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink>,allocator<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> > >(Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> *,unsigned __int64,Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> const &,std::allocator<Sharp::Util::CSharedPtr<DuiHelper::CNavigationPaneLink> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> *,unsigned __int64,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> *,unsigned __int64,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void _Uninit_fill_n<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> *,unsigned __int64,Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> > >(Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> *,unsigned __int64,Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> const &,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CKeyRing> > &,std::_Nonscalar_ptr_iterator_tag,std::_Range_checked_iterator_tag);
	void fill<unsigned short *,unsigned short>(unsigned short *,unsigned short *,unsigned short const &);
	void rotate<_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > > >(std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >,std::_Vector_iterator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential>,std::allocator<Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> > >);
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
			long Return_GetLastError(void *,unsigned int,char const *);
			void FailFast_Unexpected(void *,unsigned int,char const *);
			void Return_Hr(void *,unsigned int,char const *,long);
			void Return_Hr_NoOriginate(void *,unsigned int,char const *,long);
			void _FailFastImmediate_Unexpected();
			void _FailFast_GetLastError(void *,unsigned int,char const *);
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
		unsigned char (* g_pfnRtlDllShutdownInProgress)();
		unsigned char * WriteResultString<char const *>(unsigned char *,unsigned char *,char const *,char const * *);
		unsigned char RtlDllShutdownInProgress();
		unsigned long ReportFailure_GetLastError(void *,unsigned int,char const *,char const *,char const *,void *,FailureType);
		unsigned short * LogStringPrintf(unsigned short *,unsigned short const *,unsigned short const *,...);
		void (* g_pfnDebugBreak)();
		void (* g_pfnGetContextAndNotifyFailure)(FailureInfo *,char *,unsigned __int64);
		void (* g_pfnLoggingCallback)(FailureInfo const &);
		void (* g_pfnOriginateCallback)(FailureType,long);
		void (* g_pfnTelemetryCallback)(bool,FailureInfo const &);
		void (* g_pfnThrowResultException)(FailureInfo const &);
		void DebugBreak();
		void GetContextAndNotifyFailure(FailureInfo *,char *,unsigned __int64);
		void LogFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,unsigned short const *,bool,unsigned short *,unsigned __int64,char *,unsigned __int64,FailureInfo *);
		void ReportFailure(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long,unsigned short const *,details::ReportFailureOptions);
		void ReportFailure_Hr(void *,unsigned int,char const *,char const *,char const *,void *,FailureType,long);
	};

	namespace details_abi
	{
		struct ProcessLocalStorageData<ProcessLocalData>
		{
			static long Acquire(char const *,ProcessLocalStorageData<ProcessLocalData> * *);
			void Release();
		};

		class SemaphoreValue
		{
			static long GetValueFromSemaphore(void *,long *);
			static long TryGetValueInternal(unsigned short const *,bool,unsigned __int64 *,bool *);
		};

		struct ThreadLocalData
		{
			void SetLastError(FailureInfo const &);
			~ThreadLocalData();
		};

		struct ThreadLocalFailureInfo
		{
			void Set(FailureInfo const &,unsigned int);
		};

		details_abi::ProcessLocalStorage<details_abi::ProcessLocalData> * g_pProcessLocalData;
		details_abi::ThreadLocalData * GetThreadLocalDataCache(bool);
	};

	bool (* g_pfnIsDebuggerPresent)();
	bool g_fBreakOnFailure;
	bool g_fIsDebuggerPresent;
	long GetFailureLogString(unsigned short *,unsigned __int64,wil::FailureInfo const &);
};

HINSTANCE__ * g_wil_details_ntdllModuleHandle;
_VAULT_ITEM_ELEMENT * FindItemElement(_VAULT_ITEM *,VAULT_SCHEMA_ELEMENT_ID);
bool CertificateCredentialSortOrderPredicate(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &);
bool GenericCredentialSortOrderPredicate(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &);
bool GetUserConsent(HWND__ *);
bool IsEmptyOrWhitespaceString(std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> const &);
bool NameSortOrderPredicate(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &);
bool WebCredentialSortOrderPredicate(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &);
bool WindowCredentialSortOrderPredicate(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &);
int NavLinksDPA_DeleteCB(CControlPanelNavLink *,void *);
int UserNameSortOrderPredicate(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &);
int WebSiteSortOrderPredicate(Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &,Sharp::Util::CSharedPtr<KeyRingDataModel::CCredential> const &);
long DUIFramework_SetFocusByFocusIndicator(DirectUI::Element *);
long DUIFramework_SetRegisteredDefaultButton(IObjectWithSite *,DirectUI::Element *);
long StringCchCatW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
long g_cLocks;
std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> GetGenericErrorMessage(long,UserOperation);
unsigned long ConvertCredmanToVaultCredential(_CREDENTIALW *,_VAULT_ITEM * *);
unsigned long ConvertVaultAttributeToCredmanAttribute(_CREDENTIAL_ATTRIBUTEW *,_ATTRIBUTE *,unsigned char *,unsigned long,unsigned long *);
unsigned long ConvertVaultToCredmanCredential(_VAULT_ITEM *,_CREDENTIALW * *,unsigned long);
unsigned long DuplicateAttribute(IVaultAllocator *,_ATTRIBUTE *,unsigned long *,_ATTRIBUTE * *);
unsigned long GetCredElement(_VAULT_ITEM_ELEMENT *,VAULT_ELEMENT_TYPE,void *,unsigned long,unsigned long *,unsigned char);
unsigned long GetItemElementSize(_VAULT_ITEM_ELEMENT *,VAULT_ELEMENT_TYPE,unsigned long *,unsigned char);
unsigned long SetItemElementAlloc(VAULT_SCHEMA_ELEMENT_ID,_VAULT_VARIANT *,_VAULT_ITEM_ELEMENT * *);
unsigned long ValidatePassword(void *,unsigned long,unsigned char *,unsigned long);
unsigned long VaultEnumerateGenericCredentials(unsigned long,unsigned long *,_VAULT_ITEM * * *);
unsigned long VaultVariantDuplicate(IVaultAllocator *,_VAULT_VARIANT *,_VAULT_VARIANT *);
unsigned long VaultVariantGetRawData(_VAULT_VARIANT *,unsigned char * *,unsigned long *);
void * operator new(unsigned __int64);
void * operator new(unsigned __int64,std::nothrow_t const &);
void AutoDereference<CVaultSid>(CVaultSid *);
void CheckCredmanSupportedTypes(bool &,bool &,bool &);
void DUI_SendContentsChangedToUnknown(IUnknown *,__int64);
void DUI_SendFolderChangedToUnknown(IUnknown *,__int64);
void DUI_SendInitializationToUnknown(IUnknown *,__int64);
void DUI_SendNavigateAwayToUnknown(IUnknown *,__int64);
void DUI_SendNotificationToUnknown(IUnknown *,__int64);
void DUI_SendSelectedItemChangedToUnknown(IUnknown *,__int64);
void DUI_SendSelectionChangedToUnknown(IUnknown *,__int64);
void DUI_SetSiteOnUnknown(IUnknown *,__int64);
void DUI_WalkIUnknownElements(DirectUI::Element *,void (*)(IUnknown *,__int64),__int64);
void FormatErrorCodeStrings(long,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> &,std::basic_string<unsigned short,std::char_traits<unsigned short>,std::allocator<unsigned short>,_STL70> &);
void SetupButtonWithEventHandler(CPageBase &,unsigned short const *,Sharp::Util::CSharedPtr<DuiHelper::CButton> &,Sharp::Util::CSharedPtr<DuiHelper::CEventHandler>,DuiHelper::CControlList *,bool);
void SetupLabel(CPageBase &,unsigned short const *,Sharp::Util::CSharedPtr<DuiHelper::CLabel> &,bool);
void SetupPane(CPageBase &,unsigned short const *,Sharp::Util::CSharedPtr<DuiHelper::CPane> &);
void SetupRepeater(CPageBase &,unsigned short const *,Sharp::Util::CSharedPtr<DuiHelper::CRepeater> &);
void SetupTextBoxWithEventHandler(CPageBase &,unsigned short const *,Sharp::Util::CSharedPtr<DuiHelper::CTextBox> &,Sharp::Util::CSharedPtr<DuiHelper::CEventHandler>,DuiHelper::CControlList *,bool);
void ShellPrivateTraceEvent(_GUID const *,unsigned long,unsigned __int64,unsigned char);
void VaultFreeGenericCredential(_VAULT_ITEM *);
void VaultFreeGenericCreds(_VAULT_ITEM * *,unsigned long);
void VaultFreeVariant(IVaultAllocator *,_VAULT_VARIANT *);
void operator delete(void *);
void operator delete(void *,std::nothrow_t const &);
void operator delete(void *,void *);
