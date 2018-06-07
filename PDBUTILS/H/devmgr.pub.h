namespace ATL
{
	struct CAtlBaseModule
	{
		CAtlBaseModule();
		HINSTANCE__ * GetHInstanceAt(int);
		~CAtlBaseModule();
	};

	class CAtlList<CClass *,CElementTraits<CClass *> >
	{
		CAtlList<CClass *,CElementTraits<CClass *> >::CNode * NewNode(CClass * const &,CAtlList<CClass *,CElementTraits<CClass *> >::CNode *,CAtlList<CClass *,CElementTraits<CClass *> >::CNode *);
	public:
		CClass * & GetNext(__POSITION * &);
		__POSITION * AddTail(CClass * const &);
		void RemoveAll();
		~CAtlList<CClass *,CElementTraits<CClass *> >();
	};

	class CAtlList<CDevice *,CElementTraits<CDevice *> >
	{
		CAtlList<CDevice *,CElementTraits<CDevice *> >::CNode * NewNode(CDevice * const &,CAtlList<CDevice *,CElementTraits<CDevice *> >::CNode *,CAtlList<CDevice *,CElementTraits<CDevice *> >::CNode *);
	public:
		CDevice * & GetNext(__POSITION * &);
		__POSITION * AddTail(CDevice * const &);
		void RemoveAll();
		~CAtlList<CDevice *,CElementTraits<CDevice *> >();
	};

	class CAtlList<CDriverFile *,CElementTraits<CDriverFile *> >
	{
		CAtlList<CDriverFile *,CElementTraits<CDriverFile *> >::CNode * NewNode(CDriverFile * const &,CAtlList<CDriverFile *,CElementTraits<CDriverFile *> >::CNode *,CAtlList<CDriverFile *,CElementTraits<CDriverFile *> >::CNode *);
	public:
		CDriverFile * & GetNext(__POSITION * &);
		void RemoveAll();
		~CAtlList<CDriverFile *,CElementTraits<CDriverFile *> >();
	};

	class CAtlList<CFolder *,CElementTraits<CFolder *> >
	{
		CAtlList<CFolder *,CElementTraits<CFolder *> >::CNode * NewNode(CFolder * const &,CAtlList<CFolder *,CElementTraits<CFolder *> >::CNode *,CAtlList<CFolder *,CElementTraits<CFolder *> >::CNode *);
		void FreeNode(CAtlList<CFolder *,CElementTraits<CFolder *> >::CNode *);
	public:
		CFolder * & GetNext(__POSITION * &);
		__POSITION * AddTail(CFolder * const &);
		void RemoveAll();
		~CAtlList<CFolder *,CElementTraits<CFolder *> >();
	};

	class CAtlList<CItemIdentifier *,CElementTraits<CItemIdentifier *> >
	{
		CAtlList<CItemIdentifier *,CElementTraits<CItemIdentifier *> >::CNode * NewNode(CItemIdentifier * const &,CAtlList<CItemIdentifier *,CElementTraits<CItemIdentifier *> >::CNode *,CAtlList<CItemIdentifier *,CElementTraits<CItemIdentifier *> >::CNode *);
	public:
		CItemIdentifier * & GetNext(__POSITION * &);
		void RemoveAll();
		~CAtlList<CItemIdentifier *,CElementTraits<CItemIdentifier *> >();
	};

	class CAtlList<CMachine *,CElementTraits<CMachine *> >
	{
		CAtlList<CMachine *,CElementTraits<CMachine *> >::CNode * NewNode(CMachine * const &,CAtlList<CMachine *,CElementTraits<CMachine *> >::CNode *,CAtlList<CMachine *,CElementTraits<CMachine *> >::CNode *);
		void FreeNode(CAtlList<CMachine *,CElementTraits<CMachine *> >::CNode *);
	public:
		CMachine * & GetNext(__POSITION * &);
		__POSITION * AddTail(CMachine * const &);
		void RemoveAll();
		void RemoveAt(__POSITION *);
		~CAtlList<CMachine *,CElementTraits<CMachine *> >();
	};

	class CAtlList<CPropPageProvider *,CElementTraits<CPropPageProvider *> >
	{
		CAtlList<CPropPageProvider *,CElementTraits<CPropPageProvider *> >::CNode * NewNode(CPropPageProvider * const &,CAtlList<CPropPageProvider *,CElementTraits<CPropPageProvider *> >::CNode *,CAtlList<CPropPageProvider *,CElementTraits<CPropPageProvider *> >::CNode *);
	public:
		CPropPageProvider * & GetNext(__POSITION * &);
		void RemoveAll();
		~CAtlList<CPropPageProvider *,CElementTraits<CPropPageProvider *> >();
	};

	class CAtlList<CResource *,CElementTraits<CResource *> >
	{
		CAtlList<CResource *,CElementTraits<CResource *> >::CNode * NewNode(CResource * const &,CAtlList<CResource *,CElementTraits<CResource *> >::CNode *,CAtlList<CResource *,CElementTraits<CResource *> >::CNode *);
	public:
		CResource * & GetNext(__POSITION * &);
		__POSITION * InsertBefore(__POSITION *,CResource * const &);
		void RemoveAll();
		~CAtlList<CResource *,CElementTraits<CResource *> >();
	};

	struct CAtlList<CScopeItem *,CElementTraits<CScopeItem *> >
	{
		void RemoveAll();
		~CAtlList<CScopeItem *,CElementTraits<CScopeItem *> >();
	};

	class CAtlList<HWND__ *,CElementTraits<HWND__ *> >
	{
		CAtlList<HWND__ *,CElementTraits<HWND__ *> >::CNode * NewNode(HWND__ * const &,CAtlList<HWND__ *,CElementTraits<HWND__ *> >::CNode *,CAtlList<HWND__ *,CElementTraits<HWND__ *> >::CNode *);
		void FreeNode(CAtlList<HWND__ *,CElementTraits<HWND__ *> >::CNode *);
	public:
		HWND__ * & GetNext(__POSITION * &);
		void RemoveAll();
		void RemoveAt(__POSITION *);
		~CAtlList<HWND__ *,CElementTraits<HWND__ *> >();
	};

	class CAtlMap<_DEVPROPKEY,_DEVPROPKEY_INFO *,DEVPROPKEY_TRAITS,CElementTraits<_DEVPROPKEY_INFO *> >
	{
		CAtlMap<_DEVPROPKEY,_DEVPROPKEY_INFO *,DEVPROPKEY_TRAITS,CElementTraits<_DEVPROPKEY_INFO *> >::CNode * CreateNode(_DEVPROPKEY const &,unsigned int,unsigned int);
		CAtlMap<_DEVPROPKEY,_DEVPROPKEY_INFO *,DEVPROPKEY_TRAITS,CElementTraits<_DEVPROPKEY_INFO *> >::CNode * GetNode(_DEVPROPKEY const &,unsigned int &,unsigned int &,CAtlMap<_DEVPROPKEY,_DEVPROPKEY_INFO *,DEVPROPKEY_TRAITS,CElementTraits<_DEVPROPKEY_INFO *> >::CNode * &);
		CAtlMap<_DEVPROPKEY,_DEVPROPKEY_INFO *,DEVPROPKEY_TRAITS,CElementTraits<_DEVPROPKEY_INFO *> >::CNode * NewNode(_DEVPROPKEY const &,unsigned int,unsigned int);
		unsigned int PickSize(unsigned __int64);
		void FreeNode(CAtlMap<_DEVPROPKEY,_DEVPROPKEY_INFO *,DEVPROPKEY_TRAITS,CElementTraits<_DEVPROPKEY_INFO *> >::CNode *);
		void FreePlexes();
		void RemoveNode(CAtlMap<_DEVPROPKEY,_DEVPROPKEY_INFO *,DEVPROPKEY_TRAITS,CElementTraits<_DEVPROPKEY_INFO *> >::CNode *,CAtlMap<_DEVPROPKEY,_DEVPROPKEY_INFO *,DEVPROPKEY_TRAITS,CElementTraits<_DEVPROPKEY_INFO *> >::CNode *);
		void UpdateRehashThresholds();
	public:
		CAtlMap<_DEVPROPKEY,_DEVPROPKEY_INFO *,DEVPROPKEY_TRAITS,CElementTraits<_DEVPROPKEY_INFO *> >(unsigned int,float,float,float,unsigned int);
		__POSITION * SetAt(_DEVPROPKEY const &,_DEVPROPKEY_INFO * const &);
		bool InitHashTable(unsigned int,bool);
		void Rehash(unsigned int);
		void RemoveAll();
		void RemoveAtPos(__POSITION *);
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

	struct CAutoPtr<CBusPropPageProvider>
	{
		~CAutoPtr<CBusPropPageProvider>();
	};

	struct CAutoPtr<CClass>
	{
		~CAutoPtr<CClass>();
	};

	struct CAutoPtr<CClassGeneralPage>
	{
		~CAutoPtr<CClassGeneralPage>();
	};

	struct CAutoPtr<CDevice>
	{
		~CAutoPtr<CDevice>();
	};

	struct CAutoPtr<CDeviceDetailsPage>
	{
		~CAutoPtr<CDeviceDetailsPage>();
	};

	struct CAutoPtr<CDeviceDriverPage>
	{
		~CAutoPtr<CDeviceDriverPage>();
	};

	struct CAutoPtr<CDeviceEventsPage>
	{
		~CAutoPtr<CDeviceEventsPage>();
	};

	struct CAutoPtr<CDeviceGeneralPage>
	{
		~CAutoPtr<CDeviceGeneralPage>();
	};

	struct CAutoPtr<CDevicePowerMgmtPage>
	{
		~CAutoPtr<CDevicePowerMgmtPage>();
	};

	struct CAutoPtr<CDriverFile>
	{
		~CAutoPtr<CDriverFile>();
	};

	struct CAutoPtr<CResource>
	{
		~CAutoPtr<CResource>();
	};

	struct CComCritSecLock<CComCriticalSection>
	{
		long Lock();
	};

	struct CComCriticalSection
	{
		long Init();
	};

	struct CRegKey
	{
		long Close();
		long Create(HKEY__ *,unsigned short const *,unsigned short *,unsigned long,unsigned long,_SECURITY_ATTRIBUTES *,unsigned long *);
		long DeleteSubKey(unsigned short const *);
		long Open(HKEY__ *,unsigned short const *,unsigned long);
		long QueryStringValue(unsigned short const *,unsigned short *,unsigned long *);
		long SetStringValue(unsigned short const *,unsigned short const *,unsigned long);
		~CRegKey();
	};

	class CSimpleStringT<unsigned short,0>
	{
		static CStringData * CloneData(CStringData *);
		void Fork(int);
		void PrepareWrite2(int);
		void Reallocate(int);
		void SetLength(int);
	protected:
		static void Concatenate(CSimpleStringT<unsigned short,0> &,unsigned short const *,int,unsigned short const *,int);
		static void ThrowMemoryException();
	public:
		CSimpleStringT<unsigned short,0>(IAtlStringMgr *);
		static int StringLength(unsigned short const *);
		unsigned short * GetBuffer();
		unsigned short * GetBufferSetLength(int);
		unsigned short operator[](int);
		void Append(unsigned short const *);
		void Append(unsigned short const *,int);
		void Empty();
		void ReleaseBuffer(int);
		void SetString(unsigned short const *,int);
		~CSimpleStringT<unsigned short,0>();
	};

	struct CStringData
	{
		void Release();
	};

	class CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > >
	{
		bool CheckImplicitLoad(void const *);
	public:
		CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > > & TrimLeft();
		CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > > & TrimRight();
		CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > > & operator+=(char const *);
		CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > > & operator=(char const *);
		CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > >();
		CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > >(IAtlStringMgr *);
		CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > >(char const *);
		CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > >(unsigned short const *);
		IAtlStringMgr * GetManager();
		int Compare(unsigned short const *);
		int LoadStringW(HINSTANCE__ *,unsigned int);
		void AppendFormat(unsigned short const *,...);
		void AppendFormatV(unsigned short const *,char *);
		void Format(unsigned short const *,...);
		void FormatV(unsigned short const *,char *);
		~CStringT<unsigned short,StrTraitATL<unsigned short,ChTraitsCRT<unsigned short> > >();
	};

	struct CWin32Heap
	{
		virtual unsigned __int64 GetSize(void *);
		virtual void * Allocate(unsigned __int64);
		virtual void * Reallocate(void *,unsigned __int64);
		virtual void Free(void *);
		virtual ~CWin32Heap();
	};

	struct ChTraitsCRT<unsigned short>
	{
		static void ConvertToBaseType(unsigned short *,int,unsigned short const *,int);
	};

	ATL::ATLSTRINGRESOURCEIMAGE const * _AtlGetStringResourceImage(HINSTANCE__ *,HRSRC__ *,unsigned int);
	ATL::CAtlBaseModule _AtlBaseModule;
	ATL::CAtlStringMgr g_strmgr;
	ATL::CAtlWinModule _AtlWinModule;
	ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > operator+(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > const &,ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > const &);
	ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > operator+(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > const &,unsigned short const *);
	ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > operator+(unsigned short const *,ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > const &);
	ATL::CWin32Heap g_strheap;
	HINSTANCE__ * AtlFindStringResourceInstance(unsigned int,unsigned short);
	long AtlMultiply<unsigned __int64>(unsigned __int64 *,unsigned __int64,unsigned __int64);
	void AtlThrowImpl(long);
};

struct BufferPtr<_GUID>
{
	BufferPtr<_GUID>(unsigned int);
	~BufferPtr<_GUID>();
};

struct BufferPtr<unsigned char>
{
	BufferPtr<unsigned char>(unsigned int);
	~BufferPtr<unsigned char>();
};

struct BufferPtr<unsigned short>
{
	BufferPtr<unsigned short>(unsigned int);
	~BufferPtr<unsigned short>();
};

struct CBusPropPageProvider
{
	virtual int EnumPages(CDevice *,CPropSheetData *);
};

struct CClass
{
	CClass(CMachine *,_GUID *);
	CDevInfoList * GetDevInfoList(HWND__ *);
	virtual CItemIdentifier * CreateIdentifier();
	virtual ~CClass();
	void AddDevice(CDevice *);
	void PropertyChanged();
};

struct CClassFactory
{
	static long GetClassObject(_GUID const &,_GUID const &,void * *);
	static long RegisterAll();
	static long UnregisterAll();
	static long s_Locks;
	static long s_Objects;
	virtual long CreateInstance(IUnknown *,_GUID const &,void * *);
	virtual long LockServer(int);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CClassGeneralPage
{
	virtual int OnInitDialog(_PROPSHEETPAGEW *);
	virtual unsigned int DestroyCallback();
	virtual void UpdateControls(__int64);
};

struct CClassIdentifier
{
	virtual int operator==(CCookie &);
};

struct CCommandLine
{
	void ParseCommandLine(unsigned short const *);
};

class CComponent
{
	CFolder * FindFolder(__int64);
	long SaveFolderPersistData(CFolder *,IStream *,int);
protected:
	long OnAddImages(__int64,IImageList *,__int64);
	long OnContextHelp(__int64,__int64,__int64);
	long OnRestoreView(__int64,__int64,__int64);
	long OnSelect(__int64,__int64,__int64);
	long OnShow(__int64,__int64,__int64);
public:
	int AttachFolderToMachine(CFolder *,CMachine * *);
	long CreateFolderList(CCookie *);
	long LoadScopeIconsForResultPane(IImageList *);
	long UpdateToolbar(CCookie *);
	virtual long AddMenuItems(IDataObject *,IContextMenuCallback *,long *);
	virtual long Command(long,IDataObject *);
	virtual long Compare(__int64,__int64,__int64,int *);
	virtual long CompareObjects(IDataObject *,IDataObject *);
	virtual long ControlbarNotify(_MMC_NOTIFY_TYPE,__int64,__int64);
	virtual long CreatePropertyPages(IPropertySheetCallback *,__int64,IDataObject *);
	virtual long Destroy(__int64);
	virtual long GetClassID(_GUID *);
	virtual long GetDisplayInfo(_RESULTDATAITEM *);
	virtual long GetResultViewType(__int64,unsigned short * *,long *);
	virtual long GetSizeMax(_ULARGE_INTEGER *);
	virtual long Initialize(IConsole *);
	virtual long IsDirty();
	virtual long Load(IStream *);
	virtual long Notify(IDataObject *,_MMC_NOTIFY_TYPE,__int64,__int64);
	virtual long QueryDataObject(__int64,_DATA_OBJECT_TYPES,IDataObject * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long QueryPagesFor(IDataObject *);
	virtual long Save(IStream *,int);
	virtual long SetControlbar(IControlbar *);
	virtual long tvNotify(HWND__ *,__int64,tagTvNotifyCode,__int64,__int64);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CComponentData
{
	long CreateCookieSubtree(CScopeItem *,CCookie *);
	long CreateScopeItems();
	long DoStartupProperties(IPropertySheetCallback *,__int64,IDataObject *);
	long OnExpand(IDataObject *,__int64,__int64);
	long ResetScopeItem(CScopeItem *);
public:
	CComponentData();
	CScopeItem * FindScopeItem(__int64);
	virtual long AddMenuItems(IDataObject *,IContextMenuCallback *,long *);
	virtual long Command(long,IDataObject *);
	virtual long CompareObjects(IDataObject *,IDataObject *);
	virtual long CreateComponent(IComponent * *);
	virtual long CreatePropertyPages(IPropertySheetCallback *,__int64,IDataObject *);
	virtual long Destroy();
	virtual long GetClassID(_GUID *);
	virtual long GetDisplayInfo(_SCOPEDATAITEM *);
	virtual long GetHelpTopic(unsigned short * *);
	virtual long GetSizeMax(_ULARGE_INTEGER *);
	virtual long Initialize(IUnknown *);
	virtual long IsDirty();
	virtual long Load(IStream *);
	virtual long Notify(IDataObject *,_MMC_NOTIFY_TYPE,__int64,__int64);
	virtual long QueryDataObject(__int64,_DATA_OBJECT_TYPES,IDataObject * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long QueryPagesFor(IDataObject *);
	virtual long Save(IStream *,int);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	~CComponentData();
};

struct CComponentDataExtension
{
	virtual _GUID const & GetCoClassID();
	virtual int IsPrimarySnapin();
};

struct CComponentDataPrimary
{
	CComponentDataPrimary();
	virtual _GUID const & GetCoClassID();
	virtual int IsPrimarySnapin();
};

struct CComputer
{
	CComputer(CMachine *,unsigned long);
	virtual CItemIdentifier * CreateIdentifier();
	virtual unsigned long GetDevNode();
};

struct CComputerIdentifier
{
	CComputerIdentifier(CComputer &);
	virtual int operator==(CCookie &);
};

struct CDMCommandLine
{
	virtual void ParseParam(unsigned short const *,int);
	~CDMCommandLine();
};

class CDataObject
{
	virtual long DAdvise(tagFORMATETC *,unsigned long,IAdviseSink *,unsigned long *);
	virtual long DUnadvise(unsigned long);
	virtual long EnumDAdvise(IEnumSTATDATA * *);
	virtual long GetCanonicalFormatEtc(tagFORMATETC *,tagFORMATETC *);
	virtual long QueryGetData(tagFORMATETC *);
	virtual long SetData(tagFORMATETC *,tagSTGMEDIUM *,int);
public:
	static unsigned int m_cfClassGuid;
	static unsigned int m_cfCoClass;
	static unsigned int m_cfDeviceID;
	static unsigned int m_cfDisplayName;
	static unsigned int m_cfMachineName;
	static unsigned int m_cfNodeType;
	static unsigned int m_cfNodeTypeString;
	static unsigned int m_cfSnapinInternal;
	virtual long EnumFormatEtc(unsigned long,IEnumFORMATETC * *);
	virtual long GetData(tagFORMATETC *,tagSTGMEDIUM *);
	virtual long GetDataHere(tagFORMATETC *,tagSTGMEDIUM *);
	virtual long Initialize(_DATA_OBJECT_TYPES,tagCookieType,CCookie *,ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CDevInfoList
{
	int DiGetExtensionPropSheetPage(_SP_DEVINFO_DATA *,int (*)(_PSP *,__int64),unsigned long,__int64);
	int DiTurnOffDiExFlags(_SP_DEVINFO_DATA *,unsigned long);
	int DiTurnOnDiFlags(_SP_DEVINFO_DATA *,unsigned long);
	unsigned long DiGetExFlags(_SP_DEVINFO_DATA *);
	unsigned long DiGetFlags(_SP_DEVINFO_DATA *);
	virtual ~CDevInfoList();
	void DiDestroyDeviceInfoList();
};

class CDevMgrAbout
{
	long LoadResourceOleString(int,unsigned short * *);
public:
	virtual long GetProvider(unsigned short * *);
	virtual long GetSnapinDescription(unsigned short * *);
	virtual long GetSnapinImage(HICON__ * *);
	virtual long GetSnapinVersion(unsigned short * *);
	virtual long GetStaticFolderImage(HBITMAP__ * *,HBITMAP__ * *,HBITMAP__ * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CDevice
{
	ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > GetDeviceID();
	CDevice(CMachine *,CClass *,_SP_DEVINFO_DATA *);
	CDriver * CreateDriver();
	HICON__ * LoadIconW();
	int CanStandardUserUpdateDrivers();
	int DisplayPropertiesAsAdmin(HWND__ *);
	int GetBusGuidString(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	int GetBusTypeGuid(_GUID *);
	int GetInstallError(unsigned long *);
	int HasProblem();
	int IsDeviceUsingInboxDriver();
	int IsDisableable();
	int IsDisabled();
	int IsHidden();
	int IsPCIDevice();
	int IsPhantom();
	int IsRAW();
	int IsStarted();
	int IsStateDisabled();
	int IsStateDisabledInCurrentConfig();
	int IsUninstallable();
	int NeedsRestart();
	int TestDeviceManagerSyncEvent();
	unsigned long EnableDisableDevice(HWND__ *,int);
	virtual CItemIdentifier * CreateIdentifier();
	virtual unsigned long GetDevNode();
	virtual ~CDevice();
	void GetDeviceInfName(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	void GetDriverDateString(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	void GetDriverVersionString(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	void GetInstallSectionName(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	void GetMFGString(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	void GetProviderString(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	void PropertyChanged();
};

class CDeviceDetailsPage
{
	struct _PROPERTY_ENTRY
	{
		_PROPERTY_ENTRY();
		~_PROPERTY_ENTRY();
	};

	static int ComparePropertyEntries(void const *,void const *);
	void CopyToClipboard();
	void DisplayBlob(_DEVPROPKEY *,unsigned char *,unsigned long);
	void DisplayBooleans(unsigned char *,unsigned long);
	void DisplayDword(_DEVPROPKEY *,unsigned long);
	void DisplayError(unsigned long);
	void DisplayFileTimes(_DEVPROPKEY *,unsigned char *,unsigned long);
	void DisplayGuids(unsigned char *,unsigned long);
	void DisplayMultiSzString(unsigned char *);
	void DisplayPowerData(unsigned char *,unsigned long);
	void DisplayString(unsigned short const *);
	void UpdateDetailsText();
protected:
	virtual int OnCommand(unsigned __int64,__int64);
	virtual int OnContextMenu(HWND__ *,unsigned short,unsigned short);
	virtual int OnInitDialog(_PROPSHEETPAGEW *);
	virtual int OnNotify(tagNMHDR *);
	virtual void UpdateControls(__int64);
public:
	CDeviceDetailsPage();
};

class CDeviceDriverPage
{
protected:
	virtual int OnCommand(unsigned __int64,__int64);
	virtual void UpdateControls(__int64);
public:
	CDeviceDriverPage();
	int RollbackDriver(CDevice *,HWND__ *,int *,int *);
	int UninstallDrivers(CDevice *,HWND__ *);
	int UpdateDriver(CDevice *,HWND__ *,int *,int *);
};

class CDeviceEventsPage
{
	static unsigned long EventSubscriptionCallback(_EVT_SUBSCRIBE_NOTIFY_ACTION,void *,void *);
	void CopyToClipboard();
	void InsertEvent(void *);
	void OpenEventViewer();
protected:
	virtual int OnCommand(unsigned __int64,__int64);
	virtual int OnContextMenu(HWND__ *,unsigned short,unsigned short);
	virtual int OnInitDialog(_PROPSHEETPAGEW *);
	virtual int OnNotify(tagNMHDR *);
	virtual void UpdateControls(__int64);
public:
	CDeviceEventsPage();
	virtual ~CDeviceEventsPage();
};

struct CDeviceGeneralPage
{
	CDeviceGeneralPage();
	_PSP * Create(CDevice *);
	virtual int OnCommand(unsigned __int64,__int64);
	virtual int OnInitDialog(_PROPSHEETPAGEW *);
	virtual int OnLastChanceApply();
	virtual int OnQuerySiblings(unsigned __int64,__int64);
	virtual unsigned int DestroyCallback();
	virtual void UpdateControls(__int64);
};

struct CDeviceIdentifier
{
	CDeviceIdentifier(CDevice &);
	virtual int operator==(CCookie &);
};

class CDevicePowerMgmtPage
{
protected:
	virtual int OnApply();
	virtual int OnCommand(unsigned __int64,__int64);
	virtual int OnInitDialog(_PROPSHEETPAGEW *);
	virtual void UpdateControls(__int64);
public:
	CDevicePowerMgmtPage();
};

struct CDialog
{
	static __int64 DialogWndProc(HWND__ *,unsigned int,unsigned __int64,__int64);
	virtual int OnContextMenu(HWND__ *,unsigned short,unsigned short);
	virtual int OnDestroy();
	virtual int OnInitDialog();
	virtual int OnNotify(tagNMHDR *);
	virtual void OnCommand(unsigned __int64,__int64);
	virtual ~CDialog();
};

class CDriver
{
	int GetFullPathFromImagePath(unsigned short const *,unsigned short *,unsigned int);
	static unsigned int ScanQueueCallback(void *,unsigned int,unsigned __int64,unsigned __int64);
	void AddFunctionAndFilterDrivers(CDevice *,void *);
	void CreateFromService(CDevice *,unsigned short const *,void *);
public:
	CDriver();
	int Create(CDevice *);
	int GetFirstDriverFile(CDriverFile * *,void * &);
	int GetNextDriverFile(CDriverFile * *,void * &);
	unsigned __int64 BuildDriverList(int);
	void AddDriverFile(CDriverFile *);
	void GetDriverSignerString(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
};

class CDriverFile
{
	int GetVersionInfo();
public:
	CDriverFile();
	int Create(unsigned short const *,int,unsigned long,unsigned short const *,void *);
	int DriverBlockedNotify();
};

class CDriverFilesDlg
{
	void LaunchDriverBlockedNotify();
	void ShowCurDriverFileDetail();
public:
	virtual int OnDestroy();
	virtual int OnInitDialog();
	virtual int OnNotify(tagNMHDR *);
	virtual void OnCommand(unsigned __int64,__int64);
	virtual ~CDriverFilesDlg();
};

struct CFolder
{
	int SelectView(tagViewType,int);
	unsigned long Release();
	virtual CResultView * GetCurResultView();
	virtual int GetPersistDataSize();
	virtual long AddMenuItems(CCookie *,IContextMenuCallback *,long *);
	virtual long Compare(__int64,__int64,int,int *);
	virtual long CreatePropertyPages(CCookie *,IPropertySheetCallback *,__int64);
	virtual long GetDisplayInfo(_RESULTDATAITEM *);
	virtual long GetPersistData(unsigned char *,int);
	virtual long GetResultViewType(unsigned short * *,long *);
	virtual long MachinePropertyChanged(CMachine *);
	virtual long MenuCommand(CCookie *,long);
	virtual long OnOcxNotify(_MMC_NOTIFY_TYPE,__int64,__int64);
	virtual long OnRestoreView(int *);
	virtual long OnSelect();
	virtual long OnShow(int);
	virtual long QueryPagesFor(CCookie *);
	virtual long Reset();
	virtual long SetPersistData(unsigned char *,int);
	virtual long tvNotify(HWND__ *,CCookie *,tagTvNotifyCode,__int64,__int64);
};

struct CGeneralPage
{
	CGeneralPage();
	long DoBrowse();
	virtual int OnCommand(unsigned __int64,__int64);
	virtual int OnInitDialog(_PROPSHEETPAGEW *);
	virtual int OnReset();
	virtual int OnWizFinish();
};

class CHWTab
{
	CHWTab(unsigned short const * *,int,unsigned long,tagRECT const *);
	int GetDeviceProperty(void *,_DEVPROPKEY const *,_SP_DEVINFO_DATA *,unsigned short *,unsigned long);
	int OnInitDialog(HWND__ *);
	static __int64 DialogProc(HWND__ *,unsigned int,unsigned __int64,__int64);
	static __int64 ParentSubclassProc(HWND__ *,unsigned int,unsigned __int64,__int64,unsigned __int64,unsigned __int64);
	static void operator delete(void *);
	void Initialize(_GUID const *,int,unsigned long,tagRECT const *);
	void OnItemChanged(tagNMLISTVIEW *);
	void OnProperties();
	void OnSetText(unsigned short const *);
	void RebuildDeviceList();
	void RemoveListItems(HWND__ *);
	void RepositionControls();
	void Reset();
	void SetControlPositions(int,int,int,int,unsigned int);
};

struct CItemIdentifier
{
	virtual ~CItemIdentifier();
};

class CMachine
{
	int BuildClassesFromGuidList(_GUID *,unsigned long);
	int CreateClassesAndDevices(unsigned short const *,_GUID *);
	int CreateNotifyWindow();
	void CreateDeviceTree(CDevice *,CDevice *,unsigned long);
	void DestroyClassesAndDevices();
public:
	CDevice * DevNodeToDevice(unsigned long);
	CMachine(unsigned short const *);
	HWND__ * GetClassWindowHandle(_GUID *);
	HWND__ * GetDeviceWindowHandle(unsigned short const *);
	int AttachChildMachine(CMachine *);
	int AttachFolder(CFolder *);
	int CmGetClassGuid(_SP_DEVINFO_DATA *,_GUID *);
	int CmGetCurrentHwProfile(unsigned long *);
	int CmGetDescriptionString(_SP_DEVINFO_DATA *,ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	int CmGetDeviceIDString(unsigned long,ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	int CmGetFirstLogConf(unsigned long,unsigned __int64 *,unsigned long);
	int CmGetHwProfileFlags(unsigned long,unsigned long,unsigned long *);
	int CmGetLastKnownParentDeviceId(_SP_DEVINFO_DATA *,ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	int CmGetNextResDes(unsigned __int64 *,unsigned __int64,unsigned long,unsigned long *);
	int CmGetStatus(unsigned long,unsigned long *,unsigned long *);
	int CmReenumerate(unsigned long,unsigned long);
	int DiBuildClassInfoList(unsigned long,_GUID *,unsigned long,unsigned long *);
	int DiGetClassFriendlyNameString(_GUID *,ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	int DiGetClassPropertyEx(_GUID const *,_DEVPROPKEY const *,unsigned long *,unsigned char *,unsigned long,unsigned long *,unsigned long);
	int DiGetClassPropertyKeysEx(_GUID const *,_DEVPROPKEY *,unsigned long,unsigned long *,unsigned long);
	int DoNotCreateDevice(unsigned long);
	int EnableRefresh(int);
	int GetFirstClass(CClass * *,void * &);
	int GetFirstDevice(CDevice * *,void * &);
	int GetInfDigitalSigner(unsigned short const *,ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	int Initialize(HWND__ *,unsigned short const *,_GUID *);
	int Reenumerate();
	int Refresh();
	int ScheduleRefresh();
	unsigned long CmGetChild(unsigned long);
	virtual ~CMachine();
	void * DiCreateDeviceInfoList(_GUID *,HWND__ *);
	void DetachChildMachine(CMachine *);
};

struct CMachineList
{
	CMachine * FindMachine(unsigned short const *);
	CMachineList();
	int CreateMachine(unsigned short const *,CMachine * *);
	~CMachineList();
};

struct CNotifyRebootRequest
{
	long Release();
};

struct CPowerEnable
{
	int Close();
	int Get(unsigned char &);
	int Open(unsigned short const *);
	int Set(unsigned char);
	virtual ~CPowerEnable();
};

struct CPowerShutdownEnable
{
	CPowerShutdownEnable();
	virtual ~CPowerShutdownEnable();
};

struct CPowerWakeEnable
{
	CPowerWakeEnable();
	virtual ~CPowerWakeEnable();
};

struct CPowerWakeMgmtEnable
{
	virtual ~CPowerWakeMgmtEnable();
};

struct CProblemAgent
{
	CProblemAgent(CDevice *,unsigned long,int);
	int EnableDevice(HWND__ *,CDevice *);
	int FixDriverBlocked(HWND__ *,CDevice *);
	int FixIt(HWND__ *);
	int FixitText(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	int InstructionText(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
	int RestartComputer(HWND__ *,CDevice *);
	int StartTroubleShooter(HWND__ *,CDevice *,unsigned short *,unsigned short *);
	int UpgradeDriver(HWND__ *,CDevice *);
};

struct CPropPageProvider
{
	virtual ~CPropPageProvider();
};

struct CPropSheetData
{
	CPropSheetData();
	int InsertPage(_PSP *,int);
	int PropertyChangeNotify(__int64);
	virtual int Create(HINSTANCE__ *,HWND__ *,unsigned int,__int64);
	void PageCreateNotify(HWND__ *);
	void PageDestroyNotify(HWND__ *);
	~CPropSheetData();
};

class CPropSheetPage
{
protected:
	virtual int OnApply();
	virtual int OnCommand(unsigned __int64,__int64);
	virtual int OnContextMenu(HWND__ *,unsigned short,unsigned short);
	virtual int OnDestroy();
	virtual int OnInitDialog(_PROPSHEETPAGEW *);
	virtual int OnKillActive();
	virtual int OnLastChanceApply();
	virtual int OnNotify(tagNMHDR *);
	virtual int OnQuerySiblings(unsigned __int64,__int64);
	virtual int OnReset();
	virtual int OnSetActive();
	virtual int OnWizBack();
	virtual int OnWizFinish();
	virtual int OnWizNext();
	virtual unsigned int CreateCallback();
	virtual unsigned int DestroyCallback();
	virtual void UpdateControls(__int64);
public:
	CPropSheetPage(HINSTANCE__ *,unsigned int);
	static __int64 PageDlgProc(HWND__ *,unsigned int,unsigned __int64,__int64);
	static unsigned int PageCallback(HWND__ *,unsigned int,_PROPSHEETPAGEW *);
	virtual ~CPropSheetPage();
};

class CRemoveDevDlg
{
	void OnOk();
public:
	virtual int OnDestroy();
	virtual int OnInitDialog();
	virtual void OnCommand(unsigned __int64,__int64);
	virtual ~CRemoveDevDlg();
};

struct CResource
{
	CResource(CDevice *,unsigned long,unsigned __int64,unsigned __int64,int,int);
	virtual CItemIdentifier * CreateIdentifier();
};

struct CResourceIdentifier
{
	CResourceIdentifier(CResource &);
	virtual int operator==(CCookie &);
};

class CResourceList
{
	void CreateSubtreeResourceList(CDevice *,unsigned long,unsigned long,unsigned long);
	void InsertResourceToList(CResource *);
public:
	CResourceList(CMachine *,unsigned long,unsigned long,unsigned long);
	int GetFirst(CResource * *,void * &);
};

struct CResourceType
{
	CResourceType(CMachine *,unsigned long);
	virtual CItemIdentifier * CreateIdentifier();
};

struct CResourceTypeIdentifier
{
	virtual int operator==(CCookie &);
};

struct CResultItem
{
	CResultItem();
	virtual ~CResultItem();
};

class CResultView
{
	long AddLegacyHardware();
	long RemoveDevice(CDevice *);
protected:
	int DisplaySubtree(_TREEITEM *,CCookie *,int *);
	long UpdateConsoleVerbs(CCookie *);
public:
	CResultView(int);
	int DisplayTree();
	long AddMenuItems(CCookie *,IContextMenuCallback *,long *,int);
	long CreatePropertyPages(CCookie *,IPropertySheetCallback *,__int64);
	long DoContextMenu(HWND__ *,CCookie *,tagPOINT *);
	long DoProperties(HWND__ *,CCookie *);
	long MachinePropertyChanged(CMachine *);
	long MenuCommand(CCookie *,long);
	long OnOcxNotify(_MMC_NOTIFY_TYPE,__int64,__int64);
	long tvNotify(HWND__ *,CCookie *,tagTvNotifyCode,__int64,__int64);
	virtual CCookie * GetSelectedCookie();
	virtual long GetDisplayInfo(_RESULTDATAITEM *);
	virtual long OnShow(int);
	virtual ~CResultView();
	void DestroySavedTreeStates();
	void RestoreSavedTreeState(CCookie *);
	void SaveTreeStates(CCookie *);
};

struct CRunDLLCommandLine
{
	CRunDLLCommandLine();
	virtual void ParseParam(unsigned short const *,int);
	~CRunDLLCommandLine();
};

class CScopeItem
{
protected:
	CCookie * FindSelectedCookieData(CResultView * *);
public:
	CScopeItem(tagCookieType,int,int,int,int,int);
	int EnumerateChildren(int,CScopeItem * *);
	long Reset();
	virtual CFolder * CreateFolder(CComponent *);
	virtual int Create();
	virtual long AddMenuItems(IContextMenuCallback *,long *);
	virtual long CreatePropertyPages(IPropertySheetCallback *,__int64);
	virtual long MenuCommand(long);
	virtual long QueryPagesFor();
};

struct CTSEnableDeviceFinishPage
{
	_PSP * Create(CDevice *);
	virtual int OnSetActive();
	virtual int OnWizFinish();
};

struct CTSEnableDeviceIntroPage
{
	_PSP * Create(CDevice *);
	virtual int OnSetActive();
	virtual int OnWizNext();
};

struct CTSRestartComputerFinishPage
{
	_PSP * Create(CDevice *);
	virtual int OnSetActive();
	virtual int OnWizFinish();
};

struct CTString
{
	CTString(char const *);
	~CTString();
};

struct CViewDeviceTree
{
	CViewDeviceTree(int);
	virtual int CreateDeviceTree();
	virtual long OnShow(int);
	virtual ~CViewDeviceTree();
};

class CViewResourceTree
{
	int InsertCookieToTree(CCookie *,CCookie *,int);
	void CreateResourceTree();
public:
	CViewResourceTree(int);
	virtual long OnShow(int);
	virtual ~CViewResourceTree();
};

class CViewTreeByConnection
{
	int CreateSubtree(CCookie *,CCookie *,CDevice *);
public:
	virtual int CreateDeviceTree();
};

struct CViewTreeByType
{
	virtual int CreateDeviceTree();
};

struct CWizard98
{
	CWizard98(HWND__ *,unsigned int);
	static int WizardCallback(HWND__ *,unsigned int,__int64);
};

struct SafeInterfacePtr<IComponent>
{
	~SafeInterfacePtr<IComponent>();
};

struct SafeInterfacePtr<IContextMenuProvider>
{
	~SafeInterfacePtr<IContextMenuProvider>();
};

struct SafeInterfacePtr<IDataObject>
{
	~SafeInterfacePtr<IDataObject>();
};

struct SafeInterfacePtr<IExtendPropertySheet>
{
	~SafeInterfacePtr<IExtendPropertySheet>();
};

struct SafeInterfacePtr<IPropertySheetProvider>
{
	~SafeInterfacePtr<IPropertySheetProvider>();
};

struct SafeInterfacePtr<IStream>
{
	SafeInterfacePtr<IStream>(IStream *);
	~SafeInterfacePtr<IStream>();
};

struct SafeInterfacePtr<IUnknown>
{
	~SafeInterfacePtr<IUnknown>();
};

ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > * g_astrButtonStrings;
ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > EncodeXmlString(unsigned short const *);
ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > g_strDevMgr;
ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > g_strStartupCommand;
ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > g_strStartupDeviceId;
ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > g_strStartupMachineName;
CMachineList g_MachineList;
CMemoryException g_MemoryException;
HINSTANCE__ * g_hInstance;
_DEVPROPKEY_INFO * GetDevPropKeyInfo(_DEVPROPKEY const *);
_GUID const CLSID_DEVMGR;
_GUID const CLSID_DEVMGR_ABOUT;
_GUID const CLSID_DEVMGR_EXTENSION;
_GUID const CLSID_RMTCONFIG;
_GUID const CLSID_SYSTOOLS;
_GUID const IID_IDMTVOCX;
_GUID const IID_ISnapinCallback;
_MMCButton * g_SnapinButtons;
__int64 (* OldDeviceStatusEditProc)(HWND__ *,unsigned int,unsigned __int64,__int64);
__int64 DeviceStatusEditSubProc(HWND__ *,unsigned int,unsigned __int64,__int64);
__int64 dmNotifyWndProc(HWND__ *,unsigned int,unsigned __int64,__int64);
int AddPageCallback(_PSP *,__int64);
int AddPropPageCallback(_PSP *,__int64);
int AddToolTips(HWND__ *,unsigned int,unsigned short const *,HWND__ * *);
int CompareDeviceListItems(__int64,__int64,__int64);
int DeviceAdvancedProperties(HWND__ *,unsigned short const *,unsigned short const *);
int DeviceManager_Execute(HWND__ *,HINSTANCE__ *,unsigned short const *,int);
int DeviceProblemWizard(HWND__ *,unsigned short const *,unsigned short const *);
int DevicePropertiesEx(HWND__ *,unsigned short const *,unsigned short const *,unsigned long,int);
int InitGlobals(HINSTANCE__ *);
int IsBlankChar(unsigned short);
int IsRemoveSubtreeOk(HWND__ *,CDevice *,_SP_REMOVEDEVICE_PARAMS *);
int LoadEnumPropPage32(unsigned short const *,HINSTANCE__ * *,__int64 (**)());
int MsgBoxParam(HWND__ *,int,int,unsigned long,...);
int MyGetComputerName(ATL::CStringT<unsigned short,ATL::StrTraitATL<unsigned short,ATL::ChTraitsCRT<unsigned short> > > &);
int PromptForRestart(HWND__ *,unsigned long,int);
int PropertyRunDeviceTree(HWND__ *,unsigned short const *,unsigned short const *);
int VerifyMachineName(unsigned short const *);
int g_IsAdmin;
int g_bDevMgrTraceLoggingRegistered;
int g_bLoadedStrings;
long AddMenuItem(IContextMenuCallback *,int,int,long,long,long,long);
long ExtractData(IDataObject *,unsigned int,unsigned char *,unsigned long);
long GetProductVersion(unsigned short *,unsigned long);
long StringCchCatW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchCopyW(unsigned short *,unsigned __int64,unsigned short const *);
long StringCchPrintfW(unsigned short *,unsigned __int64,unsigned short const *,...);
tagCookieType CookieType(unsigned long);
tagMMCMenuItem const * const ViewDevicesMenuItems;
tagNodeInfo const * const NodeInfo;
unsigned int GetDeviceProblemText(unsigned long,unsigned short *,unsigned int);
unsigned int g_cfDsObjectPicker;
unsigned long ReenumerateThreadProc(void *);
unsigned long RemoveDeviceThreadProc(void *);
unsigned short * AllocOleTaskString(unsigned short const *);
unsigned short * FormatString(unsigned short const *,...);
unsigned short * GetEventMessageString(void *,void *,_EVT_FORMAT_MESSAGE_FLAGS);
unsigned short * SkipBlankChars(unsigned short *);
void * GetEventRenderData(void *,void *,_EVT_RENDER_FLAGS,unsigned long *);
void * operator new(unsigned __int64);
void * operator new[](unsigned __int64);
void DestroyEventItemData(_EVENT_ITEM_DATA *);
void DeviceProblenWizard_RunDLL(HWND__ *,HINSTANCE__ *,unsigned short const *,int);
void DeviceProperties_RunDLL(HWND__ *,HINSTANCE__ *,unsigned short const *,int);
void ReportCmdLineError(HWND__ *,int);
void _TlgWriteActivityAutoStop<140737488355328,5>(_TlgProvider_t const *,_GUID const *);
void __ArrayUnwind(void *,unsigned __int64,int,void (*)(void *));
void operator delete(void *);
void operator delete(void *,void *);
void operator delete[](void *);
