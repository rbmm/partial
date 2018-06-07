namespace ATL
{
	struct CAtlBaseModule
	{
		CAtlBaseModule();
		static bool m_bInitFailed;
		~CAtlBaseModule();
	};

	struct CComCriticalSection
	{
		long Init();
	};

	struct CSimpleArray<HINSTANCE__ *,CSimpleArrayEqualHelper<HINSTANCE__ *> >
	{
		void RemoveAll();
	};

	struct _ATL_BASE_MODULE70
	{
		_ATL_BASE_MODULE70();
	};

	ATL::CAtlBaseModule _AtlBaseModule;
};

struct Allocator
{
	unsigned short * Alloc<unsigned short>(unsigned int);
};

class ArmHazardAvoidance
{
	bool AvoidHazard(unsigned long,unsigned char *,unsigned long,unsigned long *);
	bool F32BitInstr(unsigned char *);
	bool FHazardCandidate(unsigned char *);
public:
	static bool FNeedCheckHazard(IMAGE *,CON *);
	void Do(unsigned long,unsigned long *);
};

struct Array<ARGUMENT_LIST *>
{
	int append(ARGUMENT_LIST * const &);
	int setSize(unsigned int);
};

struct Array<Array<CON *> *>
{
	int append(Array<CON *> * const &);
	int setSize(unsigned int);
	void clear();
	~Array<Array<CON *> *>();
};

struct Array<Array<GRP *> *>
{
	int append(Array<GRP *> * const &);
	int setSize(unsigned int);
	~Array<Array<GRP *> *>();
};

struct Array<Array<PdataMgr::FuncStartEnd> *>
{
	int append(Array<PdataMgr::FuncStartEnd> * const &);
	int setSize(unsigned int);
	~Array<Array<PdataMgr::FuncStartEnd> *>();
};

struct Array<Array<Warbird::WARBIRD_NONLTCG_SYMBOL> *>
{
	int append(Array<Warbird::WARBIRD_NONLTCG_SYMBOL> * const &);
	int setSize(unsigned int);
	~Array<Array<Warbird::WARBIRD_NONLTCG_SYMBOL> *>();
};

struct Array<Array<unsigned __int64> *>
{
	int setSize(unsigned int);
	void clear();
	~Array<Array<unsigned __int64> *>();
};

struct Array<Array<unsigned int> *>
{
	int append(Array<unsigned int> * const &);
	int setSize(unsigned int);
	~Array<Array<unsigned int> *>();
};

struct Array<Array<unsigned long> *>
{
	int append(Array<unsigned long> * const &);
	int setSize(unsigned int);
	~Array<Array<unsigned long> *>();
};

struct Array<BASE_RELOC *>
{
	int setSize(unsigned int);
};

struct Array<CMismatches::ValuePmod>
{
	int append(CMismatches::ValuePmod const &);
	int setSize(unsigned int);
	~Array<CMismatches::ValuePmod>();
};

struct Array<CON *>
{
	Array<CON *>(unsigned int);
	int append(CON * const &);
	int setSize(unsigned int);
	void clear();
	~Array<CON *>();
};

struct Array<CORTCEInfo>
{
	int append(CORTCEInfo const &);
	int setSize(unsigned int);
};

struct Array<CTaskQueue::MSGBLOCKPAIR *>
{
	int append(CTaskQueue::MSGBLOCKPAIR * const &);
	int setSize(unsigned int);
	~Array<CTaskQueue::MSGBLOCKPAIR *>();
};

struct Array<EXPORT>
{
	Array<EXPORT>(unsigned int);
	int append(EXPORT const &);
	int setSize(unsigned int);
};

struct Array<EXTERNAL *>
{
	int append(EXTERNAL * const &);
	int setSize(unsigned int);
	void clear();
	~Array<EXTERNAL *>();
};

struct Array<GRP *>
{
	int append(GRP * const &);
	int setSize(unsigned int);
	~Array<GRP *>();
};

struct Array<ICF_GRP *>
{
	int setSize(unsigned int);
};

struct Array<IMemHandler *>
{
	int setSize(unsigned int);
	void deleteAt(unsigned int);
};

struct Array<ImplicitDllImportInfo>
{
	int append(ImplicitDllImportInfo const &);
	int setSize(unsigned int);
};

struct Array<LIB *>
{
	int setSize(unsigned int);
	~Array<LIB *>();
};

struct Array<LINK_FILE_ID>
{
	int append(LINK_FILE_ID const &);
	int setSize(unsigned int);
	~Array<LINK_FILE_ID>();
};

struct Array<LONG_BRANCH_REGION *>
{
	int append(LONG_BRANCH_REGION * const &);
	int setSize(unsigned int);
	~Array<LONG_BRANCH_REGION *>();
};

struct Array<LSL * *>
{
	int append(LSL * * const &);
	int setSize(unsigned int);
};

struct Array<LongBranch>
{
	int append(LongBranch const &);
	int setSize(unsigned int);
};

struct Array<LongBranchRecord>
{
	int append(LongBranchRecord const &);
	int setSize(unsigned int);
};

struct Array<LongBranchTarget>
{
	int append(LongBranchTarget const &);
	int setSize(unsigned int);
};

struct Array<MOD *>
{
	int append(MOD * const &);
	int setSize(unsigned int);
	void clear();
	~Array<MOD *>();
};

struct Array<Map<CON *,Array<CON *> *,LHashClass2<void *,7,3> > *>
{
	int append(Map<CON *,Array<CON *> *,LHashClass2<void *,7,3> > * const &);
	int setSize(unsigned int);
	~Array<Map<CON *,Array<CON *> *,LHashClass2<void *,7,3> > *>();
};

struct Array<Map<CON *,Array<unsigned long> *,LHashClass2<void *,7,3> > *>
{
	int append(Map<CON *,Array<unsigned long> *,LHashClass2<void *,7,3> > * const &);
	int setSize(unsigned int);
	~Array<Map<CON *,Array<unsigned long> *,LHashClass2<void *,7,3> > *>();
};

struct Array<Map<GRP *,unsigned long,LHashClass2<void *,7,3> > *>
{
	int append(Map<GRP *,unsigned long,LHashClass2<void *,7,3> > * const &);
	int setSize(unsigned int);
	~Array<Map<GRP *,unsigned long,LHashClass2<void *,7,3> > *>();
};

struct Array<Map<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> > *>
{
	int append(Map<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> > * const &);
	int setSize(unsigned int);
	~Array<Map<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> > *>();
};

struct Array<Map<unsigned long,unsigned long,HashClassCRC<unsigned int> > *>
{
	int append(Map<unsigned long,unsigned long,HashClassCRC<unsigned int> > * const &);
	int setSize(unsigned int);
	~Array<Map<unsigned long,unsigned long,HashClassCRC<unsigned int> > *>();
};

struct Array<NODE *>
{
	~Array<NODE *>();
};

struct Array<PdataMgr::FuncStartEnd>
{
	int append(PdataMgr::FuncStartEnd const &);
	int setSize(unsigned int);
};

struct Array<PdataMgr::IntraLBR>
{
	int setSize(unsigned int);
	~Array<PdataMgr::IntraLBR>();
};

struct Array<PdataMgr::PdataIntraLBR>
{
	int setSize(unsigned int);
	~Array<PdataMgr::PdataIntraLBR>();
};

struct Array<PdataMgr::PdataLeafFunc>
{
	int setSize(unsigned int);
	void deleteAt(unsigned int);
	~Array<PdataMgr::PdataLeafFunc>();
};

struct Array<PhaseInfo>
{
	int setSize(unsigned int);
	~Array<PhaseInfo>();
};

struct Array<RVACB>
{
	int append(RVACB const &);
	int setSize(unsigned int);
};

struct Array<SEC *>
{
	int append(SEC * const &);
	int setSize(unsigned int);
	~Array<SEC *>();
};

struct Array<SXDataRecord>
{
	int append(SXDataRecord const &);
	int setSize(unsigned int);
	void clear();
};

struct Array<SXPextRecord>
{
	int append(SXPextRecord const &);
	int setSize(unsigned int);
	void clear();
};

struct Array<SrcHeaderW *>
{
	int append(SrcHeaderW * const &);
	int setSize(unsigned int);
	~Array<SrcHeaderW *>();
};

struct Array<TKMOD>
{
	int append(TKMOD const &);
	int setSize(unsigned int);
	~Array<TKMOD>();
};

struct Array<TkEmitTCEInfo *>
{
	int append(TkEmitTCEInfo * const &);
	int setSize(unsigned int);
	~Array<TkEmitTCEInfo *>();
};

struct Array<TransInfo>
{
	int append(TransInfo const &);
	int setSize(unsigned int);
};

struct Array<WEAK_DEFAULT>
{
	int append(WEAK_DEFAULT const &);
	int setSize(unsigned int);
	~Array<WEAK_DEFAULT>();
};

struct Array<Warbird::CWarbirdLinkerTransformations::PRIVATE_SYMBOL>
{
	int append(Warbird::CWarbirdLinkerTransformations::PRIVATE_SYMBOL const &);
	int setSize(unsigned int);
	~Array<Warbird::CWarbirdLinkerTransformations::PRIVATE_SYMBOL>();
};

struct Array<Warbird::WARBIRD_NONLTCG_SYMBOL>
{
	int append(Warbird::WARBIRD_NONLTCG_SYMBOL const &);
	int setSize(unsigned int);
};

struct Array<char *>
{
	int append(char * const &);
	int setSize(unsigned int);
	~Array<char *>();
};

struct Array<char const *>
{
	int append(char const * const &);
	int setSize(unsigned int);
	~Array<char const *>();
};

struct Array<char>
{
	~Array<char>();
};

struct Array<int>
{
	int append(int const &);
	int setSize(unsigned int);
};

struct Array<tagPGDOBJECTRECORD>
{
	int append(tagPGDOBJECTRECORD const &);
	int setSize(unsigned int);
};

struct Array<unsigned __int64>
{
	int append(unsigned __int64 const &);
	int setSize(unsigned int);
	void clear();
	void deleteAt(unsigned int);
	~Array<unsigned __int64>();
};

struct Array<unsigned char *>
{
	int append(unsigned char * const &);
	int setSize(unsigned int);
	~Array<unsigned char *>();
};

struct Array<unsigned char>
{
	int append(unsigned char const &);
	int setSize(unsigned int);
	~Array<unsigned char>();
};

struct Array<unsigned int>
{
	int append(unsigned int const &);
	int setSize(unsigned int);
	void clear();
	~Array<unsigned int>();
};

struct Array<unsigned long>
{
	Array<unsigned long>(unsigned int);
	int append(unsigned long const &);
	int setSize(unsigned int);
	void clear();
	void fill(unsigned long const &);
	~Array<unsigned long>();
};

struct Array<unsigned short *>
{
	Array<unsigned short *>(unsigned int);
	int append(unsigned short * const &);
	int setSize(unsigned int);
	~Array<unsigned short *>();
};

struct Array<unsigned short const *>
{
	int append(unsigned short const * const &);
	int putAt(unsigned int,unsigned short const * const &);
	int setSize(unsigned int);
	~Array<unsigned short const *>();
};

struct Array<void *>
{
	int append(void * const &);
	int setSize(unsigned int);
	void clear();
	~Array<void *>();
};

class Buffer
{
protected:
	int grow(long);
	int setPbExtent(unsigned char *,unsigned char *);
	static BufferAllocator * GetDefaultAllocator();
public:
	int Alloc(long);
	int Append(unsigned char *,long,unsigned char * *);
	int Append(unsigned char *,unsigned long,unsigned char * *);
	int Ensure(long);
	int Reserve(long,unsigned char * *);
	~Buffer();
};

struct BufferDefaultAllocator
{
	virtual unsigned char * Alloc(long);
	virtual unsigned char * AllocZeroed(long);
	virtual void DeAlloc(unsigned char *);
};

struct CAutoLockT<CLockCS>
{
	~CAutoLockT<CLockCS>();
};

struct CCoffAuxSymT<IMAGE_FILE>
{
	virtual long AryDim(unsigned long *,unsigned long);
	virtual long AuxType(unsigned char *);
	virtual long CLineNo(unsigned long *);
	virtual long CRelocs(unsigned long *);
	virtual long CheckSum(unsigned long *);
	virtual long FcnPLineNo(unsigned long *);
	virtual long FcnPNextFcn(unsigned long *);
	virtual long FileName(unsigned char *,unsigned long);
	virtual long ISection(int *);
	virtual long ImgAuxSym(unsigned char *);
	virtual long Length(unsigned long *);
	virtual long MiscLineNo(unsigned long *);
	virtual long MiscSize(unsigned long *);
	virtual long MiscTotalSize(unsigned long *);
	virtual long NewSymCrc(unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SelType(unsigned char *);
	virtual long TagIndex(unsigned long *);
	virtual long TkFile(unsigned __int64 *);
	virtual long Tocid(unsigned char *);
	virtual long TokenDef(unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CCoffAuxSymT<IMAGE_FILE_EX>
{
	virtual long AryDim(unsigned long *,unsigned long);
	virtual long AuxType(unsigned char *);
	virtual long CLineNo(unsigned long *);
	virtual long CRelocs(unsigned long *);
	virtual long CheckSum(unsigned long *);
	virtual long FcnPLineNo(unsigned long *);
	virtual long FcnPNextFcn(unsigned long *);
	virtual long FileName(unsigned char *,unsigned long);
	virtual long ISection(int *);
	virtual long ImgAuxSym(unsigned char *);
	virtual long Length(unsigned long *);
	virtual long MiscLineNo(unsigned long *);
	virtual long MiscSize(unsigned long *);
	virtual long MiscTotalSize(unsigned long *);
	virtual long NewSymCrc(unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SelType(unsigned char *);
	virtual long TagIndex(unsigned long *);
	virtual long TkFile(unsigned __int64 *);
	virtual long Tocid(unsigned char *);
	virtual long TokenDef(unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CCoffContrib
{
protected:
	_IMAGE_RELOCATION * PImgRelocs(unsigned long,unsigned char *);
	static BLK _blkRelocs;
	static CLinkDataRO * _pldDataRO;
	static CLinkDataRO * _pldDataROAlt;
	static CLinkDataRO * _pldSecName;
public:
	virtual long CLineNo(unsigned long *);
	virtual long CRelocs(unsigned long *);
	virtual long CbContents(unsigned long *);
	virtual long Characteristics(unsigned long *);
	virtual long ISection(unsigned long *);
	virtual long PbContents(unsigned char *,unsigned long,unsigned long *);
	virtual long PbContentsRO(ILinkDataRO * *);
	virtual long PbContentsRW(ILinkDataRW * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long RgLineNo(ILinkDataRO * *);
	virtual long RgRelocs(ILinkDataRO * *);
	virtual long RgRelocsEx(unsigned char *,unsigned long);
	virtual long RgSymbol(unsigned long,ICOFFSymRO * *,IObjectContrib * *);
	virtual long SzSectionName(ILinkDataRO * *);
	virtual long TkFile(unsigned __int64 *);
	virtual long VirtualAddress(unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CCoffEnumSections
{
	virtual long Clone(IEnumContrib * *);
	virtual long Next(unsigned long,IObjectContrib * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CCoffSymROT<IMAGE_FILE>
{
	static CEnumAuxSymsT<IMAGE_FILE> * _pEnumAuxAlt;
	static CEnumAuxSymsT<IMAGE_FILE> * _pEnumAuxCur;
	static CLinkDataRO * _pldSymName;
	static CLinkDataRO * _pldSymNameAlt;
public:
	static void Init();
	virtual long CAuxSym(unsigned char *);
	virtual long EnumAuxSym(IEnumAuxSym * *);
	virtual long ISection(int *);
	virtual long ISym(unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long StorageClass(unsigned char *);
	virtual long SzFile(ILinkDataRO * *);
	virtual long SzName(ILinkDataRO * *);
	virtual long TkFile(unsigned __int64 *);
	virtual long Type(unsigned short *);
	virtual long Value(unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CCoffSymROT<IMAGE_FILE_EX>
{
	static CEnumAuxSymsT<IMAGE_FILE_EX> * _pEnumAuxAlt;
	static CEnumAuxSymsT<IMAGE_FILE_EX> * _pEnumAuxCur;
	static CLinkDataRO * _pldSymName;
	static CLinkDataRO * _pldSymNameAlt;
public:
	static void Init();
	virtual long CAuxSym(unsigned char *);
	virtual long EnumAuxSym(IEnumAuxSym * *);
	virtual long ISection(int *);
	virtual long ISym(unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long StorageClass(unsigned char *);
	virtual long SzFile(ILinkDataRO * *);
	virtual long SzName(ILinkDataRO * *);
	virtual long TkFile(unsigned __int64 *);
	virtual long Type(unsigned short *);
	virtual long Value(unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CCoffSymRWT<IMAGE_FILE>
{
	static CEnumAuxSymsT<IMAGE_FILE> * _pEnumAuxAlt;
	static CEnumAuxSymsT<IMAGE_FILE> * _pEnumAuxCur;
	static CLinkDataRO * _pldSymName;
	static CLinkDataRO * _pldSymNameAlt;
public:
	static void Init();
	virtual long CAuxSym(unsigned char *);
	virtual long EnumAuxSym(IEnumAuxSym * *);
	virtual long ISection(int *);
	virtual long ISym(unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetISection(int);
	virtual long SetType(unsigned short);
	virtual long SetValue(unsigned long);
	virtual long StorageClass(unsigned char *);
	virtual long SzFile(ILinkDataRO * *);
	virtual long SzName(ILinkDataRO * *);
	virtual long TkFile(unsigned __int64 *);
	virtual long Type(unsigned short *);
	virtual long Value(unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CCoffSymRWT<IMAGE_FILE_EX>
{
	static CEnumAuxSymsT<IMAGE_FILE_EX> * _pEnumAuxAlt;
	static CEnumAuxSymsT<IMAGE_FILE_EX> * _pEnumAuxCur;
	static CLinkDataRO * _pldSymName;
	static CLinkDataRO * _pldSymNameAlt;
public:
	static void Init();
	virtual long CAuxSym(unsigned char *);
	virtual long EnumAuxSym(IEnumAuxSym * *);
	virtual long ISection(int *);
	virtual long ISym(unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SetISection(int);
	virtual long SetType(unsigned short);
	virtual long SetValue(unsigned long);
	virtual long StorageClass(unsigned char *);
	virtual long SzFile(ILinkDataRO * *);
	virtual long SzName(ILinkDataRO * *);
	virtual long TkFile(unsigned __int64 *);
	virtual long Type(unsigned short *);
	virtual long Value(unsigned long *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CCoffSymTabROT<IMAGE_FILE>
{
	bool FInit(CObjFileT<IMAGE_FILE> *,unsigned long,bool);
	static CCoffSymROT<IMAGE_FILE> * _pccoffsymAlt;
	static CCoffSymROT<IMAGE_FILE> * _pccoffsymCur;
public:
	static void Init();
	virtual long CSymbols(unsigned long *);
	virtual long EmitCOFFSymbolTable(unsigned char *,unsigned long);
	virtual long EnumCOFFSymRO(IEnumCOFFSymRO * *);
	virtual long GetCOFFSymRO(unsigned long,ICOFFSymRO * *);
	virtual long ISYMNextCOFFSymRO(ICOFFSymRO *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CCoffSymTabROT<IMAGE_FILE_EX>
{
	bool FInit(CObjFileT<IMAGE_FILE_EX> *,unsigned long,bool);
	static CCoffSymROT<IMAGE_FILE_EX> * _pccoffsymAlt;
	static CCoffSymROT<IMAGE_FILE_EX> * _pccoffsymCur;
public:
	static void Init();
	virtual long CSymbols(unsigned long *);
	virtual long EmitCOFFSymbolTable(unsigned char *,unsigned long);
	virtual long EnumCOFFSymRO(IEnumCOFFSymRO * *);
	virtual long GetCOFFSymRO(unsigned long,ICOFFSymRO * *);
	virtual long ISYMNextCOFFSymRO(ICOFFSymRO *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CCoffSymTabRWT<IMAGE_FILE>
{
	static CCoffSymRWT<IMAGE_FILE> * _pccoffsymAlt;
	static CCoffSymRWT<IMAGE_FILE> * _pccoffsymCur;
public:
	static void Init();
	virtual long CSymbols(unsigned long *);
	virtual long EmitCOFFSymbolTable(unsigned char *,unsigned long);
	virtual long EnumCOFFSymRW(IEnumCOFFSymRW * *);
	virtual long GetCOFFSymRW(unsigned long,ICOFFSymRW * *);
	virtual long ISYMNextCOFFSymRW(ICOFFSymRW *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CCoffSymTabRWT<IMAGE_FILE_EX>
{
	static CCoffSymRWT<IMAGE_FILE_EX> * _pccoffsymAlt;
	static CCoffSymRWT<IMAGE_FILE_EX> * _pccoffsymCur;
public:
	static void Init();
	virtual long CSymbols(unsigned long *);
	virtual long EmitCOFFSymbolTable(unsigned char *,unsigned long);
	virtual long EnumCOFFSymRW(IEnumCOFFSymRW * *);
	virtual long GetCOFFSymRW(unsigned long,ICOFFSymRW * *);
	virtual long ISYMNextCOFFSymRW(ICOFFSymRW *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CEnumAuxSymsT<IMAGE_FILE>
{
	static CCoffAuxSymT<IMAGE_FILE> * _pAuxSymAlt;
	static CCoffAuxSymT<IMAGE_FILE> * _pAuxSymCur;
public:
	static void Init();
	virtual long Clone(IEnumAuxSym * *);
	virtual long Next(unsigned long,ICOFFAuxSym * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CEnumAuxSymsT<IMAGE_FILE_EX>
{
	static CCoffAuxSymT<IMAGE_FILE_EX> * _pAuxSymAlt;
	static CCoffAuxSymT<IMAGE_FILE_EX> * _pAuxSymCur;
public:
	static void Init();
	virtual long Clone(IEnumAuxSym * *);
	virtual long Next(unsigned long,ICOFFAuxSym * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CEnumPubsT<IMAGE_FILE>
{
	__MIDL___MIDL_itf_objint_0000_0000_0001 PsymtFromWeak(_IMAGE_SYMBOL *,unsigned long *);
	bool FBuildIsecToIsymMapping();
	bool FInit();
	char const * SzSymForIsym(unsigned long,char * const);
	unsigned long CPublicSymbols();
public:
	virtual long Clone(IEnumPublics * *);
	virtual long Next(unsigned long,IPublicSym * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CEnumPubsT<IMAGE_FILE_EX>
{
	__MIDL___MIDL_itf_objint_0000_0000_0001 PsymtForPImgSym(_IMAGE_SYMBOL_EX *,unsigned long *);
	__MIDL___MIDL_itf_objint_0000_0000_0001 PsymtFromWeak(_IMAGE_SYMBOL_EX *,unsigned long *);
	bool FBuildIsecToIsymMapping();
	bool FComdat(unsigned long,unsigned char *);
	bool FInit();
	char const * SzSymForIsym(unsigned long,char * const);
	unsigned long CPublicSymbols();
public:
	virtual long Clone(IEnumPublics * *);
	virtual long Next(unsigned long,IPublicSym * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CEnumSymROT<IMAGE_FILE>
{
	virtual long Clone(IEnumCOFFSymRO * *);
	virtual long Next(unsigned long,ICOFFSymRO * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CEnumSymROT<IMAGE_FILE_EX>
{
	virtual long Clone(IEnumCOFFSymRO * *);
	virtual long Next(unsigned long,ICOFFSymRO * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CEnumSymRWT<IMAGE_FILE>
{
	virtual long Clone(IEnumCOFFSymRW * *);
	virtual long Next(unsigned long,ICOFFSymRW * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CEnumSymRWT<IMAGE_FILE_EX>
{
	virtual long Clone(IEnumCOFFSymRW * *);
	virtual long Next(unsigned long,ICOFFSymRW * *,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CFileIO
{
	long Close();
	virtual long Read(long,void *,unsigned int);
	virtual long Write(long,void const *,unsigned int);
	~CFileIO();
};

class CImplib
{
	bool FEmitMembers();
	char * SzImportDescriptor();
	char * SzNullThunk();
	static _IMAGE_IMPORT_DESCRIPTOR _NullImportDescriptor;
	static char const * SzExport(bool,bool,char const *,unsigned int *);
	static void ( CImplib::*const * const _rgpfnEmitData)(ImportData *,unsigned char *,unsigned long);
	static void ( CImplib::*const * const _rgpfnEmitRelocs)(ImportData *,unsigned char *,unsigned long);
	static void BuildThunkSectionHeader(_IMAGE_SECTION_HEADER *,unsigned long *,char const *,unsigned int,unsigned short,unsigned long);
	static void ReSortExportNamePtrs(unsigned char *,unsigned long *,unsigned long,unsigned long);
	unsigned int CbCvExportSyms();
	unsigned long CEATEntries(unsigned long);
	unsigned long CsymCreateThunkSymbols();
	void BuildRawDataFromExternTable(BLK *,unsigned long *,unsigned long,unsigned long);
	void CompleteLinkerMembers();
	void CreateImportSymbols(unsigned long *);
	void EmitCvExportSyms(int);
	void EmitDataAndRelocs(bool,ImportData *,unsigned short *,unsigned short,IMPORT_OBJECT_TYPE,IMPORT_OBJECT_NAME_TYPE,char const *,unsigned int,char const *,unsigned int,unsigned int);
	void EmitDataCv(ImportData *,unsigned char *,unsigned long);
	void EmitDataCvThunk(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_BoundIAT(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_CvCompile3(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_CvDelayThunk(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_CvExpThunk(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_CvTailMergeThunk(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_DelayDescr(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_DelayThunk(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_DllName(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_ExternDefn(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_HintName(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_IAT(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_INT(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_NullBoundIAT(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_NullDelayDescr(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_NullIAT(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_NullINT(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_TailMerge(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_TailMergePdata(ImportData *,unsigned char *,unsigned long);
	void EmitDataDL_TailMergeXdata(ImportData *,unsigned char *,unsigned long);
	void EmitDataHintName(ImportData *,unsigned char *,unsigned long);
	void EmitDataIATByName(ImportData *,unsigned char *,unsigned long);
	void EmitDataIATByOrdinal(ImportData *,unsigned char *,unsigned long);
	void EmitDataINTByName(ImportData *,unsigned char *,unsigned long);
	void EmitDataINTByOrdinal(ImportData *,unsigned char *,unsigned long);
	void EmitDataText(ImportData *,unsigned char *,unsigned long);
	void EmitDefLibExternals(Buffer &,StringTableUnique *,unsigned long);
	void EmitDllExportDirectory(unsigned long,unsigned long,bool);
	void EmitExportDataFixups(int,unsigned long,unsigned long,unsigned long,unsigned long);
	void EmitImportDescriptor();
	void EmitLinkerMembers(unsigned long);
	void EmitMember(EXTERNAL *);
	void EmitNullImportDescriptor();
	void EmitNullThunkData();
	void EmitRelocsDL_CvDelayThunk(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsDL_CvExpThunk(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsDL_CvTailMergeThunk(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsDL_DelayDescr(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsDL_DelayThunk(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsDL_ExternDefn(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsDL_IAT(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsDL_INT(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsDL_TailMerge(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsDL_TailMergePdata(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsDebugAssoc(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsIATByName(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsINTByName(ImportData *,unsigned char *,unsigned long);
	void EmitRelocsThunk(ImportData *,unsigned char *,unsigned long);
	void EmitThunk(char const *,bool,unsigned long,bool,unsigned short,bool,_IMAGE_ARCHIVE_MEMBER_HEADER *,_IMAGE_FILE_HEADER *,_IMAGE_SECTION_HEADER *,unsigned char *,ImportData *);
	void GenerateSymbolTable(Buffer &,StringTableUnique *,unsigned long *,unsigned short *,unsigned long,unsigned long,unsigned long *,unsigned long,unsigned long,unsigned long,BLK &);
	void GetDllFilename();
	void GetThunkInfo(bool);
	void IdentifyAssignedOrdinals();
	void Init();
	void MakeDllNames(unsigned short const *);
	void WriteArchive(unsigned long,unsigned long,unsigned long,bool);
public:
	CImplib(IMAGE *);
	CImplib(IMAGE *,int,unsigned short const *,unsigned short,unsigned long);
	int DefLibMain();
	void EmitDelayLoadCode(bool,bool,IMPORT_OBJECT_HEADER const &,int,_IMAGE_FILE_HEADER *,unsigned short,char const *,_IMAGE_SECTION_HEADER *,unsigned char *,ImportData *,bool *);
	void EmitMember(IMPORT_OBJECT_HEADER &,char const *);
	void EmitSpecialLinkerMembers();
	void GenerateThunk(IMPORT_OBJECT_HEADER const &,char const *,bool,_IMAGE_ARCHIVE_MEMBER_HEADER *,_IMAGE_FILE_HEADER *,_IMAGE_SECTION_HEADER *,unsigned char *,ImportData *);
	void GenerateThunk(int,IMPORT_OBJECT_HEADER const &,bool,_IMAGE_ARCHIVE_MEMBER_HEADER *,_IMAGE_FILE_HEADER *,_IMAGE_SECTION_HEADER *,unsigned char *,ImportData *);
	~CImplib();
};

class CImportContrib
{
	virtual void Init(unsigned long,CObjFileBase *,_IMAGE_SECTION_HEADER *);
public:
	virtual long PbContents(unsigned char *,unsigned long,unsigned long *);
	virtual long PbContentsRO(ILinkDataRO * *);
	virtual long PbContentsRW(ILinkDataRW * *);
	virtual long RgRelocs(ILinkDataRO * *);
	virtual long RgRelocsEx(unsigned char *,unsigned long);
};

class CImportEnumSections
{
protected:
	CImportEnumSections(_IMAGE_SECTION_HEADER *,unsigned long,CObjFileBase *,CCoffContrib *);
	bool FInit();
public:
	virtual long Next(unsigned long,IObjectContrib * *,unsigned long *);
	virtual long Reset();
	virtual long Skip(unsigned long);
	virtual unsigned long Release();
};

class CImportObject
{
protected:
	virtual _IMAGE_SYMBOL * ReadSymbolTable(bool);
	virtual bool FComdatIsec(int);
	virtual bool FInit(IMAGE *,void *,LIB *,unsigned short const *,char const *,bool,bool,unsigned long *);
	virtual void LoadStringTable();
	virtual void ReadSectionHeaders(_IMAGE_SECTION_HEADER * *);
	virtual void VerifyOpen();
	void RefreshModuleContent(bool);
public:
	CImportObject(unsigned __int64,bool);
	virtual long EnumContrib(IEnumContrib * *);
	virtual long FImportObj(int *);
	virtual long GetContribForISec(unsigned long,IObjectContrib * *);
	virtual long GetStringTable(ILinkDataRO * *);
	virtual long PbDirectives(ILinkDataRO * *);
	virtual unsigned long Release();
	virtual void IncrInit(unsigned long);
};

struct CLinkCG
{
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CLinkDataRO
{
	virtual long GetDataPointer(unsigned char * *,int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void Init(unsigned char *,unsigned int,bool,bool);
	~CLinkDataRO();
};

struct CLinkDataRW
{
	virtual long GetDataPointer(unsigned char * *,int *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	void Init(unsigned char *,unsigned int,bool,bool);
};

struct CLinkNativeSymbol
{
	virtual long EnumEntryPoints(IEnumCOFFSymRO * *);
	virtual long GetCOFFSym(IObjectContrib *,unsigned long,ICOFFSymRO * *,IObjectContrib * *);
	virtual long GetContrib(IPublicSym *,IObjectContrib * *,char * *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CLinkNotify
{
	virtual long AddExternalFilenames(IEnumExternalFilenames2 *);
	virtual long OnError(ILinkError2 *);
	virtual long OnStatus(unsigned long,unsigned long);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CLockCS
{
	CLockCS();
	~CLockCS();
};

struct CMapToken
{
	virtual long Map(unsigned int,unsigned int);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CMemCoordinator
{
	CMemCoordinator();
	virtual long ListMemory();
	virtual long NotifyOOM();
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long Register(IMemHandler *);
	virtual long Unregister(IMemHandler *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
	~CMemCoordinator();
};

struct CMemHandler
{
	virtual long OnListMemory();
	virtual long OnOOM();
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CMetaError
{
	static unsigned int m_cerror;
	virtual long OnError(long,unsigned int);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CMetadataHandler
{
	virtual long Map(unsigned int,unsigned int);
	virtual long MarkToken(unsigned int);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CMismatches
{
	bool Find(unsigned short const *,unsigned short const * *,MOD * *);
	void Add(unsigned short const *,unsigned short const *,MOD *);
public:
	CMismatches();
	void DetectMismatch(MOD *,unsigned short const *,unsigned short const *);
	~CMismatches();
};

struct COMRefPtr<ICOFFAuxSym>
{
	ICOFFAuxSym * * operator&();
	~COMRefPtr<ICOFFAuxSym>();
};

struct COMRefPtr<ICOFFObj>
{
	ICOFFObj * * operator&();
	~COMRefPtr<ICOFFObj>();
};

struct COMRefPtr<ICOFFSymRO>
{
	ICOFFSymRO * * operator&();
	~COMRefPtr<ICOFFSymRO>();
};

struct COMRefPtr<ICOFFSymRW>
{
	COMRefPtr<ICOFFSymRW>(COMRefPtr<ICOFFSymRW> const &);
	ICOFFSymRW * * operator&();
	~COMRefPtr<ICOFFSymRW>();
};

struct COMRefPtr<ICOFFSymTabRO>
{
	ICOFFSymTabRO * * operator&();
	~COMRefPtr<ICOFFSymTabRO>();
};

struct COMRefPtr<ICOFFSymTabRW>
{
	~COMRefPtr<ICOFFSymTabRW>();
};

struct COMRefPtr<IEnumAuxSym>
{
	IEnumAuxSym * * operator&();
	~COMRefPtr<IEnumAuxSym>();
};

struct COMRefPtr<IEnumCOFFSymRO>
{
	IEnumCOFFSymRO * * operator&();
	~COMRefPtr<IEnumCOFFSymRO>();
};

struct COMRefPtr<IEnumCOFFSymRW>
{
	~COMRefPtr<IEnumCOFFSymRW>();
};

struct COMRefPtr<IEnumContrib>
{
	IEnumContrib * * operator&();
	~COMRefPtr<IEnumContrib>();
};

struct COMRefPtr<IEnumExternalFilenames2>
{
	COMRefPtr<IEnumExternalFilenames2>(COMRefPtr<IEnumExternalFilenames2> const &);
	COMRefPtr<IEnumExternalFilenames2>(IEnumExternalFilenames2 *);
	~COMRefPtr<IEnumExternalFilenames2>();
};

struct COMRefPtr<IEnumExternalFilenames>
{
	~COMRefPtr<IEnumExternalFilenames>();
};

struct COMRefPtr<IEnumPublics>
{
	~COMRefPtr<IEnumPublics>();
};

class COMRefPtr<ILinkDataRO>
{
	void Release();
public:
	ILinkDataRO * * operator&();
	~COMRefPtr<ILinkDataRO>();
};

struct COMRefPtr<ILinkDataRW>
{
	~COMRefPtr<ILinkDataRW>();
};

struct COMRefPtr<IMetaDataAssemblyImport>
{
	~COMRefPtr<IMetaDataAssemblyImport>();
};

struct COMRefPtr<IObjHandler7>
{
	~COMRefPtr<IObjHandler7>();
};

struct COMRefPtr<IObjHandler8>
{
	~COMRefPtr<IObjHandler8>();
};

struct COMRefPtr<IObjectContrib>
{
	IObjectContrib * * operator&();
	~COMRefPtr<IObjectContrib>();
};

struct COMRefPtr<IPublicSym2>
{
	~COMRefPtr<IPublicSym2>();
};

struct COMRefPtr<IPublicSym>
{
	~COMRefPtr<IPublicSym>();
};

struct CON
{
	CON * PconAssoc();
	EXTERNAL * PextAssoc();
	MOD * PmodOrig();
	bool FExportComdatFunc();
	bool FICFCandidate(IMAGE *,char const *,bool,bool,bool);
	unsigned long CRelocSrc();
	unsigned long Isec();
	void Error(unsigned int,...);
	void Fatal(unsigned int,...);
	void Pass2ReadWriteRawData(IMAGE *,IObjectContrib *,COMRefPtr<ICOFFSymTabRW> &,unsigned long const *);
	void Warning(unsigned int,...);
};

class CObjFileBase
{
protected:
	bool FFetchContent(unsigned char *,unsigned long,unsigned long);
	unsigned short * SzComNameObj();
	virtual void VerifyOpen();
public:
	static IObjFile2 * PObjFileFromFile(unsigned short const *,unsigned short const *,IMAGE *,unsigned __int64,unsigned long,LIB *,unsigned short const *,char const *,bool,unsigned long *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

class CObjFileT<IMAGE_FILE>
{
protected:
	bool FIsecOffForRelocIsym(unsigned __int64,int *,unsigned long *);
	bool FLoadSectionHeaderInfo(_IMAGE_SECTION_HEADER *);
	bool FReadSymbolTable(bool);
	static CCoffSymTabROT<IMAGE_FILE> * _pSymTab;
	static CCoffSymTabROT<IMAGE_FILE> * _pSymTabAlt;
	virtual _IMAGE_SYMBOL * ReadSymbolTable(bool);
	virtual bool FComdatIsec(int);
	virtual bool FInit(IMAGE *,void *,LIB *,unsigned short const *,char const *,bool,bool,unsigned long *);
	virtual bool FInit(int,void *,unsigned short const *,unsigned short const *,IMAGE *,unsigned long,LIB *,unsigned short const *,char const *,bool,bool,unsigned long *);
	virtual bool FInitDummy();
	virtual void LoadStringTable();
	virtual void ReadSectionHeaders(_IMAGE_SECTION_HEADER * *);
	void ReadStringTable(int,unsigned short const *,unsigned long);
	void SzFuncFromSecOff(int,unsigned long,ILinkDataRO * *);
public:
	CObjFileT<IMAGE_FILE>(CObjFileBase const &,int);
	CObjFileT<IMAGE_FILE>(unsigned __int64);
	static int IsecFromCoffIsec(int);
	static void Init();
	virtual long BeginOptCaching();
	virtual long CContrib(unsigned long *);
	virtual long COFFTimeStamp(unsigned long *);
	virtual long CSymbols(unsigned long *);
	virtual long Characteristics(unsigned long *);
	virtual long Close(int);
	virtual long CloseCache(int);
	virtual long CloseCoffCon(int);
	virtual long EndOptCaching();
	virtual long EnumContrib(IEnumContrib * *);
	virtual long EnumExternalFilenames(IEnumExternalFilenames * *);
	virtual long EnumPublics(IEnumPublics * *,unsigned __int64);
	virtual long FImportObj(int *);
	virtual long FNative(int *);
	virtual long GetContribForISec(unsigned long,IObjectContrib * *);
	virtual long GetStringTable(ILinkDataRO * *);
	virtual long GetSymbolTableRO(ICOFFSymTabRO * *);
	virtual long GetSymbolTableRW(ICOFFSymTabRW * *);
	virtual long Machine(unsigned short *);
	virtual long ObjtkFromSzSymbol(ILinkDataRO *,unsigned __int64 *);
	virtual long PbDirectives(ILinkDataRO * *);
	virtual long SzRefForIsym(unsigned __int64,ILinkDataRO * *);
	virtual long TimeStamp(unsigned long *);
	virtual void IncrInit(unsigned long);
	virtual ~CObjFileT<IMAGE_FILE>();
};

class CObjFileT<IMAGE_FILE_EX>
{
protected:
	bool FIsecOffForRelocIsym(unsigned __int64,int *,unsigned long *);
	bool FLoadSectionHeaderInfo(_IMAGE_SECTION_HEADER *);
	bool FReadSymbolTable(bool);
	static CCoffSymTabROT<IMAGE_FILE_EX> * _pSymTab;
	static CCoffSymTabROT<IMAGE_FILE_EX> * _pSymTabAlt;
	virtual _IMAGE_SYMBOL_EX * ReadSymbolTable(bool);
	virtual bool FComdatIsec(int);
	virtual bool FInit(IMAGE *,void *,LIB *,unsigned short const *,char const *,bool,bool,unsigned long *);
	virtual bool FInit(int,void *,unsigned short const *,unsigned short const *,IMAGE *,unsigned long,LIB *,unsigned short const *,char const *,bool,bool,unsigned long *);
	virtual bool FInitDummy();
	virtual void LoadStringTable();
	virtual void ReadSectionHeaders(_IMAGE_SECTION_HEADER * *);
	void ReadStringTable(int,unsigned short const *,unsigned long);
	void SzFuncFromSecOff(int,unsigned long,ILinkDataRO * *);
public:
	CObjFileT<IMAGE_FILE_EX>(CObjFileBase const &,int);
	CObjFileT<IMAGE_FILE_EX>(unsigned __int64);
	static void Init();
	virtual long BeginOptCaching();
	virtual long CContrib(unsigned long *);
	virtual long COFFTimeStamp(unsigned long *);
	virtual long CSymbols(unsigned long *);
	virtual long Characteristics(unsigned long *);
	virtual long Close(int);
	virtual long CloseCache(int);
	virtual long CloseCoffCon(int);
	virtual long EndOptCaching();
	virtual long EnumContrib(IEnumContrib * *);
	virtual long EnumExternalFilenames(IEnumExternalFilenames * *);
	virtual long EnumPublics(IEnumPublics * *,unsigned __int64);
	virtual long FImportObj(int *);
	virtual long FNative(int *);
	virtual long GetContribForISec(unsigned long,IObjectContrib * *);
	virtual long GetStringTable(ILinkDataRO * *);
	virtual long GetSymbolTableRO(ICOFFSymTabRO * *);
	virtual long GetSymbolTableRW(ICOFFSymTabRW * *);
	virtual long Machine(unsigned short *);
	virtual long ObjtkFromSzSymbol(ILinkDataRO *,unsigned __int64 *);
	virtual long PbDirectives(ILinkDataRO * *);
	virtual long SzRefForIsym(unsigned __int64,ILinkDataRO * *);
	virtual long TimeStamp(unsigned long *);
	virtual void IncrInit(unsigned long);
	virtual ~CObjFileT<IMAGE_FILE_EX>();
};

struct COffsetPtr<LinkInfoW>
{
	LinkInfoW * GetAddr(void *,LinkInfoW *);
};

struct COffsetPtr<SO>
{
	SO * GetAddr(void *,SO *);
};

struct COffsetPtr<XFIXUP>
{
	XFIXUP * GetAddr(void *,XFIXUP *);
};

struct COffsetPtr<_FPO_DATA>
{
	_FPO_DATA * GetAddr(void *,_FPO_DATA *);
};

struct COffsetPtr<_IMAGE_SECTION_HEADER>
{
	_IMAGE_SECTION_HEADER * GetAddr(void *,_IMAGE_SECTION_HEADER *);
};

struct COffsetPtr<char>
{
	char * GetAddr(void *,char *);
};

struct COffsetPtr<unsigned char>
{
	unsigned char * GetAddr(void *,unsigned char *);
};

struct COffsetPtr<unsigned long>
{
	unsigned long * GetAddr(void *,unsigned long *);
};

struct COffsetPtr<unsigned short>
{
	unsigned short * GetAddr(void *,unsigned short *);
};

struct COffsetPtr<void>
{
	void * GetAddr(void *,void *);
};

struct CPubSymT<IMAGE_FILE>
{
	virtual long FComdat(int *,unsigned char *);
	virtual long ISym(unsigned __int64 *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SymType(__MIDL___MIDL_itf_objint_0000_0000_0001 *);
	virtual long SzName(ILinkDataRO * *);
	virtual long SzNameDefaultSym(ILinkDataRO * *);
	virtual long TkFile(unsigned __int64 *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CPubSymT<IMAGE_FILE_EX>
{
	virtual long FComdat(int *,unsigned char *);
	virtual long ISym(unsigned __int64 *);
	virtual long QueryInterface(_GUID const &,void * *);
	virtual long SymType(__MIDL___MIDL_itf_objint_0000_0000_0001 *);
	virtual long SzName(ILinkDataRO * *);
	virtual long SzNameDefaultSym(ILinkDataRO * *);
	virtual long TkFile(unsigned __int64 *);
	virtual unsigned long AddRef();
	virtual unsigned long Release();
};

struct CQuickBytes
{
	~CQuickBytes();
};

struct CQuickMemoryBase<512,128>
{
	long ReSizeNoThrow(unsigned long);
};

struct CStream
{
	CStream();
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

class CTaskQueue
{
	void AppendBlock(CTaskQueue::MSGBLOCK *,bool);
	void ReleaseBlock(CTaskQueue::MSGBLOCK * &);
	void SignalTypeMergeDone(MOD *);
public:
	CTaskQueue(unsigned int);
	CTaskQueue::STATUS Append(void *,unsigned int,bool,bool);
	CTaskQueue::STATUS Get(void * *,unsigned int *);
	void BlockModWaitingForPCH(DBGOP *);
	void SignalAllModPdbEvents();
	void SignalModWaitingForPCH(MOD *);
	~CTaskQueue();
};

struct CTickCount
{
	CTickCount(_iobuf *,CTickCount *,unsigned short const *);
	bool LapTime(unsigned short const *,unsigned short const *);
	bool LapTimeQPC(unsigned short const *,unsigned short const *);
	bool LapTimeTick(unsigned short const *,unsigned short const *);
	void FinalTime();
	void FinalTimeQPC(unsigned short const *);
	void FinalTimeTick();
	void Reset();
	void WriteFileName(unsigned short const *,bool,bool);
	void WriteTime(unsigned __int64);
	~CTickCount();
};

struct DUMPSTATE
{
	~DUMPSTATE();
};

namespace DecoratedNameGenerator
{
	struct CorSigDecode_t
	{
		CorElementType GetNextParam();
		unsigned int NextToken();
		unsigned long NextULong();
		void SkipFunctionSignature();
	};

	class DecoratedNameGenerator_t
	{
		long ProcessCustomMetaData();
		void ReadAttributeString(void const *);
	public:
		long GenerateDecoratedName();
	};

	void ExtractNamespaceAndTypeName(unsigned short const *,unsigned short *,unsigned int,unsigned short *,unsigned int);
};

struct DiscardRVA
{
	DiscardRVA();
	void Init(bool);
	void append(unsigned long,unsigned long);
};

struct EXTERNAL
{
	EXTERNAL * PextWeak(IMAGE *);
	MOD * PmodOrig(ST *);
	bool FAbsolute();
	bool FFunction();
	bool FPerAppDomain();
	bool FSafeSEH();
	unsigned int TkEmit();
};

struct EnumMap<CON *,Array<CON *> *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<CON *,Array<Warbird::WARBIRD_NONLTCG_SYMBOL> *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<CON *,Array<unsigned int> *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<CON *,Array<unsigned long> *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<CON *,CON *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<CON *,MOD *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<CON *,char const *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<EXTERNAL *,EXTERNAL *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<EXTERNAL *,Map<CON *,Array<unsigned long> *,LHashClass2<void *,7,3> > *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<EXTERNAL *,NODE *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<EXTERNAL *,TKMOD,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<EXTERNAL *,WEAK_DEFAULT,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<EXTERNAL *,unsigned __int64,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<EXTERNAL *,unsigned long,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<GRP *,unsigned long,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<LINK_FILE_ID,MOD *,HashClassCRC<LINK_FILE_ID> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<LONG_BRANCH_REGION *,unsigned long,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<MOD *,Array<CON *> *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<MOD *,CTaskQueue::MSGBLOCKPAIR *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<MOD *,MOD *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<MOD *,Map<CON *,Array<CON *> *,LHashClass2<void *,7,3> > *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<MOD *,Map<GRP *,unsigned long,LHashClass2<void *,7,3> > *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<MOD *,unsigned long,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<SrcHeaderW *,unsigned char *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned int,TkEmitTCEInfo *,HashClassCRC<unsigned int> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned int,unsigned int,HashClassCRC<unsigned int> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned long,Array<GRP *> *,HashClassCRC<unsigned long> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned long,Array<PdataMgr::FuncStartEnd> *,HashClassCRC<unsigned int> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned long,Map<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> > *,HashClass<unsigned long,0> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned long,Map<unsigned long,unsigned long,HashClassCRC<unsigned int> > *,HashClassCRC<unsigned int> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned long,Warbird::CWarbirdLinkerTransformations::PRIVATE_SYMBOL,HashClassCRC<unsigned long> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned long,unsigned long,HashClassCRC<unsigned int> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned long,unsigned long,HashClassCRC<unsigned long> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned long,unsigned long,LHashClass<unsigned long,0> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<unsigned short *,unsigned char,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumMap<void *,unsigned long,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct EnumNMT<char>
{
	virtual int next();
	virtual void get(char const * *,unsigned long *);
	virtual void release();
	virtual void reset();
};

struct Hasher<unsigned long *,unsigned short *>
{
	static unsigned long lhashPbCb(unsigned char *,unsigned int,unsigned long);
};

class Heap
{
	Heap();
	static Heap theHeap;
public:
	static void * hheap;
};

class ICFCompareContext
{
	bool FFoldCONsEx(unsigned long &);
	bool FICFIdenticalCONs();
	bool FICFIdenticalStatics(unsigned char,int,unsigned long,unsigned char,int,unsigned long);
	bool FIdenticalDependencies();
	bool FIdenticalRelocs();
	bool FSameDependency(CON *,CON *);
	static IMAGE * pimage;
public:
	ICFCompareContext(CON *,CON *,unsigned long);
	bool FFoldCONs(unsigned long &);
};

struct ICF_GRP
{
	ICF_GRP(GRP *);
};

struct IDLStuff
{
	IDLStuff();
	~IDLStuff();
};

class IMAGE
{
	CON * GuardGetTargetCon(CON *);
	CON * PconCreateJumpTable();
	MOD * PmodCreate(unsigned short const *,unsigned short const *,unsigned long,LIB *,unsigned long);
	bool FEmitCoffGroupOrPGOPhaseInfo();
	bool FEmitCompilerFeature();
	bool FInferEntryPoint();
	bool FInferSubsystemAndEntry();
	bool FMergeSectionsSzSz(MOD *,char const *,char const *);
	bool FOptimizeDidat(bool &);
	bool FOptimizeTLS(SEC *);
	bool GuardIsAddressTakenFunctionReloc(unsigned short,unsigned char,_IMAGE_RELOCATION *);
	char const * DynValueBaseRelocTableName();
	char const * GuardAddrTakenIATCountName();
	char const * GuardAddrTakenIATTableName();
	char const * GuardFidsCountName();
	char const * GuardFidsTableName();
	char const * GuardFlagsName();
	char const * GuardLongJmpCountName();
	char const * GuardLongJmpTableName();
	unsigned long CbBuildProdidBlock(void * *);
	unsigned long CbCoffContribInfo();
	unsigned long CbPogoInfo();
	unsigned short CsecNonEmpty();
	void AllocateCommon();
	void BaseRelocClustering();
	void CalculateDynValueRelocsSize(unsigned long &);
	void CalculatePtrs(unsigned long *,unsigned long *);
	void CheckForWin32Imports();
	void CheckSubsystemVersion();
	void DefineENCSymbols(CON * *,LEXT * *);
	void DefineImageBaseSymbol();
	void DefineSelfImports(Array<CON *> *,LEXT * *);
	void EmitSectionHeaders();
	void GuardAnalyze();
	void GuardAnalyzeCon(CON *,IObjectContrib *,COMRefPtr<ICOFFSymTabRO> &,MOD *,GUARD_SECTION_TYPE);
	void GuardAnalyzeEntryAndExports();
	void GuardAnalyzeExternal(EXTERNAL *,bool,bool);
	void GuardAnalyzeLib(LIB *);
	void GuardAnalyzeModule(MOD *);
	void GuardCollectExportSuppress();
	void GuardDefineSymbols();
	void GuardLanguageSpecificExceptionHandler();
	void GuardMarkAddrTakenIATEntry(CON *,unsigned long);
	void GuardMarkCON(MOD *,ICOFFSymRO *,GUARD_SECTION_TYPE);
	void GuardMarkFidsFuncCON(CON *,unsigned long,char const *,bool *);
	void GuardMarkLongJmpTarget(CON *,unsigned long);
	void GuardProcessNonComdatCONs();
	void GuardUpdateTableCount(EXTERNAL *,char const *,unsigned long,unsigned long);
	void GuardWriteTable(CON *,IncrHeapArray<unsigned long> *,unsigned long);
	void ICFAnalysis();
	void ImportSemantics();
	void MarkNonICFCandidates();
	void MarkNonPAGESections();
	void Optimize00cfg();
	void OptimizeCFG();
	void OptimizeGids();
	void OptimizeIdata(bool);
	void OptimizeTLS();
	void OrderSections();
	void OrderSemantics();
	void ProcessMergeSwitches();
	void SectionLayout(unsigned long *);
	void SetDefaultSubsystemVersion();
	void SortLibMods();
	void UpdateLongBranchRegion(CON *);
	void UpdateOptionalHeader();
	void VerboseICF();
	void VerboseOrder();
	void WarnDuplicateSections();
	void WriteBaseRelocations();
	void WriteBaseRelocationsToFile(unsigned short const *);
	void WriteCoffContribInfo(CON *);
	void WriteCompilerFeatureSignature(CON *);
	void WriteDebugInfo();
	void WriteENCSymbols();
	void WriteSXdata();
public:
	CON * PconFirstJmpTbl();
	CON * PconNew(MOD *,MOD *,char const *,unsigned long,unsigned long);
	GRP * PgrpNew(char const *,SEC *,SEC *,bool);
	LIB * PlibInstantiateDefaultLib();
	LIB * PlibNew(unsigned short const *,unsigned long);
	LONG_BRANCH_REGION * LBRByIndex(unsigned long);
	LONG_BRANCH_REGION * LBRForPCON(CON *);
	MOD * PmodNew(unsigned short const *,unsigned short const *,unsigned long,LIB *,bool *,unsigned long,bool);
	SEC * PsecFind(MOD *,char const *,unsigned long,bool *);
	SEC * PsecFindFlags(unsigned long,unsigned long);
	SEC * PsecFindGrp(MOD *,char const *,unsigned long);
	SEC * PsecFindIsec(int);
	SEC * PsecFindNoFlags(char const *);
	SEC * PsecFindNoMerge(MOD *,char const *,unsigned long,bool *);
	SEC * PsecNew(MOD *,char const *,unsigned long);
	SEC * PsecNewNoMerge(MOD *,char const *,unsigned long);
	bool FBuildGraph();
	bool FCorNativeRvaEntry(char const *);
	bool FEmitDelayLoadDll(unsigned short const *);
	bool FHasSafeSEHTable();
	bool FMachineType(unsigned long);
	bool FPdbEarlyTypeMerge();
	bool FPureMSIL();
	bool FSafeMSIL();
	bool FSetWinXPLoadConfigSize();
	bool FShouldDefineImageBase();
	char const * MPXArrayEndSymbolName();
	char const * SzImageBaseName();
	int BuildImage();
	static unsigned long ProcessSectionFlags(char const *,unsigned long,unsigned long);
	static unsigned short const * const LinkerThunkSizes;
	unsigned long CThunks();
	unsigned long CalculateSectionSize(SEC *);
	unsigned long CbConPadding(CON *,CON *,unsigned long,bool);
	unsigned long CbHdrPE(unsigned long *);
	unsigned long CbTextSection();
	unsigned long GetLtcgObjTimestamp();
	unsigned long GetRelocations(unsigned long,unsigned long,Array<BASE_RELOC *> *);
	unsigned long LBRCount();
	void AddImageBaseSymbolAndDefine();
	void AddSectionAndGroupSyms();
	void BuildExternalSymbolTable();
	void CheckCRTSection(char const *);
	void CheckUnusedLibs(bool);
	void Checksum();
	void ContribInit();
	void CreateDefaultSections();
	void DefineDynValueFixupSymbols();
	void DisableOptRefBeforeLTCG();
	void EmitRelocations();
	void EmittedDelayLoadDll(unsigned short const *);
	void FixupDynValueRelocation(CON *,unsigned char *,COMRefPtr<ICOFFSymRW>);
	void FreeLongBranchRegions();
	void FreePLibsST(bool);
	void GenerateTransitions();
	void GenerateWinMDFile();
	void GuardCollectExport(EXTERNAL *);
	void GuardCollectRvaForGfids(CON *);
	void GuardCollectRvaForIAT();
	void GuardCollectRvaForIATHelper(SEC *,char const *);
	void GuardCreateFids(LIB *);
	void GuardInit();
	void GuardRemoveStaleLongJmpTargets(CON *);
	void GuardSaveJumpTableSlotRva(EXTERNAL *,unsigned long,unsigned long);
	void GuardUpdateSymbols();
	void IncrInit();
	void IncrPass1();
	void Init();
	void InitializeBaseRelocations();
	void MPXDefineSymbols();
	void MPXInit();
	void Normalize();
	void OpenPDB();
	void Pass1();
	void Pass1Arg(ARGUMENT_LIST *,LIB *);
	void Pass2(Array<CON *> *,LEXT *);
	void PmodUncreate(MOD *);
	void PrepClrResources();
	void ReallocateSpaceForBaseRelocs();
	void RecordDynValueReloc(CON *,char const *,unsigned long);
	void ResetExternalSymbolTable();
	void ResolveEntryPoint(char const *,bool);
	void ResolveExternalsInLibs(bool,bool);
	void ResolveLinkerDefinedSymbols();
	void ResolveLoadConfig();
	void ResolveManagedSymbols(bool);
	void SaveIncrCmdLine();
	void SaveIncrCwd();
	void SetDefaultClrImageType();
	void SetImageBase();
	void SetLoadConfigDirectory();
	void SetMachine(unsigned short const *,unsigned short,bool);
	void UpdateTLSDirectory();
	void WriteComStructures();
	void WriteHeaderPE(int);
	void WriteSectionHeaderPE(int,SEC *,_IMAGE_SECTION_HEADER *);
};

struct ISet
{
	ISet(unsigned int);
	int add(unsigned int);
	int contains(unsigned int);
	~ISet();
};

struct IncrEnumMap<CON *,IncrHeapArray<unsigned long> *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct IncrEnumMap<CON *,IncrHeapMap<unsigned long,unsigned long,LHashClass<unsigned long,0> > *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct IncrEnumMap<CON *,LONG_BRANCH_REGION *,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct IncrEnumMap<EXTERNAL *,WEAK_DEFAULT,LHashClass2<void *,7,3> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
	void get(EXTERNAL * *,WEAK_DEFAULT *);
};

struct IncrEnumMap<unsigned long,PDATACOFFINFO,HashClassCRC<unsigned int> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct IncrEnumMap<unsigned long,unsigned long,LHashClass<unsigned long,0> >
{
	virtual int next();
	virtual void release();
	virtual void reset();
};

struct IncrHeapArray<CON *>
{
	int append(CON * const &);
	int setSize(unsigned int);
	~IncrHeapArray<CON *>();
};

struct IncrHeapArray<EXTERNAL *>
{
	int append(EXTERNAL * const &);
	int setSize(unsigned int);
	~IncrHeapArray<EXTERNAL *>();
};

struct IncrHeapArray<IncrHeapArray<unsigned __int64> *>
{
	int setSize(unsigned int);
	~IncrHeapArray<IncrHeapArray<unsigned __int64> *>();
};

struct IncrHeapArray<IncrHeapArray<unsigned long> *>
{
	int append(IncrHeapArray<unsigned long> * const &);
	int setSize(unsigned int);
	~IncrHeapArray<IncrHeapArray<unsigned long> *>();
};

struct IncrHeapArray<IncrHeapMap<unsigned long,unsigned long,LHashClass<unsigned long,0> > *>
{
	int append(IncrHeapMap<unsigned long,unsigned long,LHashClass<unsigned long,0> > * const &);
	int setSize(unsigned int);
	~IncrHeapArray<IncrHeapMap<unsigned long,unsigned long,LHashClass<unsigned long,0> > *>();
};

struct IncrHeapArray<LONG_BRANCH_REGION *>
{
	int append(LONG_BRANCH_REGION * const &);
	int setSize(unsigned int);
	~IncrHeapArray<LONG_BRANCH_REGION *>();
};

struct IncrHeapArray<PDATACOFFINFO>
{
	int append(PDATACOFFINFO const &);
	int setSize(unsigned int);
	~IncrHeapArray<PDATACOFFINFO>();
};

struct IncrHeapArray<SXDataRecord>
{
	int setSize(unsigned int);
};

struct IncrHeapArray<SXPextRecord>
{
	int setSize(unsigned int);
};

struct IncrHeapArray<WEAK_DEFAULT>
{
	int append(WEAK_DEFAULT const &);
	int setSize(unsigned int);
	~IncrHeapArray<WEAK_DEFAULT>();
};

struct IncrHeapArray<char const *>
{
	int append(char const * const &);
	int setSize(unsigned int);
};

struct IncrHeapArray<unsigned __int64>
{
	int append(unsigned __int64 const &);
	int setSize(unsigned int);
	void deleteAt(unsigned int);
};

struct IncrHeapArray<unsigned long>
{
	IncrHeapArray<unsigned long>(unsigned int);
	int append(unsigned long const &);
	int bsearch(int (*)(void const *,void const *),unsigned long *,unsigned int *);
	int putAt(unsigned int,unsigned long const &);
	int setSize(unsigned int);
	void deleteAt(unsigned int);
	~IncrHeapArray<unsigned long>();
};

struct IncrHeapArray<unsigned short *>
{
	int append(unsigned short * const &);
	int setSize(unsigned int);
};

struct IncrHeapLock
{
	IncrHeapLock(bool,bool);
	~IncrHeapLock();
};

class IncrHeapMap<CON *,IncrHeapArray<unsigned long> *,LHashClass2<void *,7,3> >
{
protected:
	int find(CON *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	IncrHeapMap<CON *,IncrHeapArray<unsigned long> *,LHashClass2<void *,7,3> >(unsigned int);
	int add(CON *,IncrHeapArray<unsigned long> *);
	int map(CON *,IncrHeapArray<unsigned long> * *);
	static void operator delete(void *);
};

class IncrHeapMap<CON *,IncrHeapMap<unsigned long,unsigned long,LHashClass<unsigned long,0> > *,LHashClass2<void *,7,3> >
{
protected:
	int find(CON *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	IncrHeapMap<CON *,IncrHeapMap<unsigned long,unsigned long,LHashClass<unsigned long,0> > *,LHashClass2<void *,7,3> >(unsigned int);
	int add(CON *,IncrHeapMap<unsigned long,unsigned long,LHashClass<unsigned long,0> > *);
	int map(CON *,IncrHeapMap<unsigned long,unsigned long,LHashClass<unsigned long,0> > * *);
	static void operator delete(void *);
};

class IncrHeapMap<CON *,LONG_BRANCH_REGION *,LHashClass2<void *,7,3> >
{
protected:
	int find(CON *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	IncrHeapMap<CON *,LONG_BRANCH_REGION *,LHashClass2<void *,7,3> >(unsigned int);
	int add(CON *,LONG_BRANCH_REGION *);
	int map(CON *,LONG_BRANCH_REGION * *);
	int remove(CON *);
	static void operator delete(void *);
};

class IncrHeapMap<EXTERNAL *,WEAK_DEFAULT,LHashClass2<void *,7,3> >
{
protected:
	int find(EXTERNAL *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	IncrHeapMap<EXTERNAL *,WEAK_DEFAULT,LHashClass2<void *,7,3> >(unsigned int);
	int add(EXTERNAL *,WEAK_DEFAULT);
	int map(EXTERNAL *,WEAK_DEFAULT *);
	int remove(EXTERNAL *);
	static void operator delete(void *);
	void reset();
};

class IncrHeapMap<unsigned long,PDATACOFFINFO,HashClassCRC<unsigned int> >
{
protected:
	int find(unsigned long,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	IncrHeapMap<unsigned long,PDATACOFFINFO,HashClassCRC<unsigned int> >(unsigned int);
	int add(unsigned long,PDATACOFFINFO);
	int map(unsigned long,PDATACOFFINFO *);
	static void operator delete(void *);
};

class IncrHeapMap<unsigned long,unsigned long,LHashClass<unsigned long,0> >
{
protected:
	int find(unsigned long,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	IncrHeapMap<unsigned long,unsigned long,LHashClass<unsigned long,0> >(unsigned int);
	int add(unsigned long,unsigned long);
	int map(unsigned long,unsigned long *);
	static void operator delete(void *);
};

struct IncrISet
{
	~IncrISet();
};

struct JmpTblMgr
{
	CON * PconCreateJmpTbl(IMAGE *,GRP *,unsigned long);
	CON * PconNearestJmpTbl(unsigned long);
	void BuildThunkMap(void const *,unsigned long * *,unsigned long,IMAGE *);
	void UpdateJumpTable(IMAGE *,unsigned long * *,unsigned long *,SO * *,unsigned short *);
	void WriteJumpTable(IMAGE *,unsigned long * *,unsigned long *,SO * *,unsigned short *);
};

struct LIB
{
	MOD * PmodFind(unsigned short const *,unsigned long,bool);
	bool FExtractedMembersModified(IMAGE *,ARGUMENT_LIST *,bool *,bool *,bool *);
	bool FGetMember(char const *,unsigned long *);
	bool FGetMember(unsigned long,unsigned long *);
	bool FLoadArchiveMember(IMAGE *,unsigned long,unsigned long,EXTERNAL *,bool *,bool *,bool,bool);
	unsigned long CMembers();
	void CacheLibMemberInfo(LIB *);
	void ProcessLibMod(ARGUMENT_LIST *,IMAGE *,MOD *,LIB *);
	void ReadSpecialLinkerInterfaceMembers(int);
	void Search(IMAGE *,bool *,bool *,bool,bool);
};

struct LLIBMEM
{
	LIBMEM * SzFind(unsigned short const *);
	void AddToList(unsigned short const *,unsigned long,unsigned long);
	void FreeList();
};

namespace LegacyActivationShim
{
	namespace Util
	{
		struct DelayLoadFunctor<long (unsigned short const *,unsigned short const *,unsigned short const *,unsigned long,unsigned long,unsigned short *,unsigned long,unsigned long *,unsigned short *,unsigned long,unsigned long *)>
		{
			long Init(HINSTANCE__ *,char const *);
			~DelayLoadFunctor<long (unsigned short const *,unsigned short const *,unsigned short const *,unsigned long,unsigned long,unsigned short *,unsigned long,unsigned long *,unsigned short *,unsigned long,unsigned long *)>();
		};

		struct ReleaseHolder<ICLRMetaHost *>
		{
			~ReleaseHolder<ICLRMetaHost *>();
		};

		struct ReleaseHolder<ICLRMetaHostPolicy *>
		{
			~ReleaseHolder<ICLRMetaHostPolicy *>();
		};

		struct ReleaseHolder<ICLRRuntimeInfo *>
		{
			~ReleaseHolder<ICLRRuntimeInfo *>();
		};

		class ZeroInitGlobalSpinLock
		{
			static void Lock(ZeroInitGlobalSpinLock * &);
		};

		HINSTANCE__ * g_hModMscoree;
		ICLRMetaHost * g_pCLRMetaHost;
		ICLRMetaHostPolicy * g_pCLRMetaHostPolicy;
		Util::RuntimeInfo g_runtimeInfo;
		Util::ZeroInitGlobalHMODULEHolder g_hModMscoreeHolder;
		Util::ZeroInitGlobalReleaseHolder<ICLRMetaHost *> g_hCLRMetaHost;
		Util::ZeroInitGlobalReleaseHolder<ICLRMetaHostPolicy *> g_hCLRMetaHostPolicy;
		Util::ZeroInitGlobalReleaseHolder<Util::RuntimeInfo *> g_hRuntimeInfo;
		Util::ZeroInitGlobalSpinLock g_runtimeInfoLock;
		bool HasNewActivationAPIs();
		long CallCLRCreateInstance(_GUID const &,_GUID const &,void * *);
		long GetCLRMetaHost(ICLRMetaHost * *);
		long GetCLRMetaHostPolicy(ICLRMetaHostPolicy * *);
		long GetCLRRuntimeInfo(ICLRRuntimeInfo * *,unsigned short const *,IStream *,unsigned short *,unsigned long *);
		long GetCLRRuntimeInfoHelper(ICLRRuntimeInfo * *,unsigned short const *,IStream *,unsigned short *,unsigned long *,unsigned short *,unsigned long *);
		long GetMSCOREE(HINSTANCE__ * *);
		long GetRuntimeInfo(Util::RuntimeInfo * *,unsigned short const *,IStream *,unsigned short *,unsigned long *);
		long g_runtimeInfoIsInitialized;
		unsigned long g_fHasNewActivationAPIs;
	};

	long ClrCoCreateInstance(_GUID const &,IUnknown *,unsigned long,_GUID const &,void * *);
	long LoadLibraryShim(unsigned short const *,unsigned short const *,void *,HINSTANCE__ * *);
};

class MOD
{
	void Init(IMAGE *,unsigned long,IObjFile2 *,unsigned long);
public:
	CLRIMAGE_TYPE GetCLRType();
	bool FContainCode();
	bool FGetRawDataForIsec(unsigned long,COMRefPtr<ILinkDataRO> &);
	bool FGuarded();
	bool FHasCorMeta();
	bool FILImage();
	bool FImport();
	bool FIsLib();
	bool FThunkable();
	unsigned long FoMember();
	unsigned short * SzComName(unsigned short *,unsigned int);
	unsigned short * SzComNameEx(unsigned short *,unsigned int);
	unsigned short const * SzFile();
	void AddSecContribs(IMAGE *,COMRefPtr<IEnumContrib> &);
	void BuildSymIndexToPdataMap(IMAGE *);
	void Close(bool);
	void EmitDiscardedSymbols(IObjectContrib *,CON *,IMAGE *,CV_DISCARDED_e);
	void Error(unsigned int,...);
	void Fatal(unsigned int,...);
	void GetCOFFObj(IMAGE *);
	void Init(IMAGE *,unsigned long,IObjFile2 *,bool,unsigned long);
	void Pass2(IMAGE *,bool);
	void Pass2InitCommon(IMAGE *);
	void Pass2Worker(IMAGE *);
	void PostNote(unsigned int,...);
	void PrepareEarlyTypeMerge(IMAGE *,bool);
	void ReadImageSecHdrInfo(IEnumContrib * *);
	void UnGetCOFFObj(IMAGE *);
	void Warning(unsigned int,...);
};

class Map<CON *,Array<CON *> *,LHashClass2<void *,7,3> >
{
protected:
	int find(CON *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<CON *,Array<CON *> *,LHashClass2<void *,7,3> >(unsigned int);
	int add(CON *,Array<CON *> *);
	void clear();
};

class Map<CON *,Array<Warbird::WARBIRD_NONLTCG_SYMBOL> *,LHashClass2<void *,7,3> >
{
protected:
	int find(CON *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<CON *,Array<Warbird::WARBIRD_NONLTCG_SYMBOL> *,LHashClass2<void *,7,3> >(unsigned int);
	int add(CON *,Array<Warbird::WARBIRD_NONLTCG_SYMBOL> *);
	int map(CON *,Array<Warbird::WARBIRD_NONLTCG_SYMBOL> * *);
	void clear();
	void reset();
};

class Map<CON *,Array<unsigned int> *,LHashClass2<void *,7,3> >
{
protected:
	int find(CON *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<CON *,Array<unsigned int> *,LHashClass2<void *,7,3> >(unsigned int);
	int add(CON *,Array<unsigned int> *);
	int map(CON *,Array<unsigned int> * *);
	int remove(CON *);
	void clear();
	void reset();
	~Map<CON *,Array<unsigned int> *,LHashClass2<void *,7,3> >();
};

class Map<CON *,Array<unsigned long> *,LHashClass2<void *,7,3> >
{
protected:
	int find(CON *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<CON *,Array<unsigned long> *,LHashClass2<void *,7,3> >(unsigned int);
	int add(CON *,Array<unsigned long> *);
	int map(CON *,Array<unsigned long> * *);
};

class Map<CON *,CON *,LHashClass2<void *,7,3> >
{
protected:
	int find(CON *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<CON *,CON *,LHashClass2<void *,7,3> >(unsigned int);
	int add(CON *,CON *);
	void clear();
	~Map<CON *,CON *,LHashClass2<void *,7,3> >();
};

class Map<CON *,MOD *,LHashClass2<void *,7,3> >
{
protected:
	int find(CON *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
public:
	Map<CON *,MOD *,LHashClass2<void *,7,3> >(unsigned int);
	int add(CON *,MOD *);
	int map(CON *,MOD * *);
};

class Map<CON *,char const *,LHashClass2<void *,7,3> >
{
protected:
	int find(CON *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<CON *,char const *,LHashClass2<void *,7,3> >(unsigned int);
	int add(CON *,char const *);
	int map(CON *,char const * *);
	void clear();
	void reset();
	~Map<CON *,char const *,LHashClass2<void *,7,3> >();
};

class Map<EXTERNAL *,EXTERNAL *,LHashClass2<void *,7,3> >
{
protected:
	int find(EXTERNAL *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<EXTERNAL *,EXTERNAL *,LHashClass2<void *,7,3> >(unsigned int);
	int add(EXTERNAL *,EXTERNAL *);
	int map(EXTERNAL *,EXTERNAL * *);
	int remove(EXTERNAL *);
	void clear();
	void reset();
	~Map<EXTERNAL *,EXTERNAL *,LHashClass2<void *,7,3> >();
};

class Map<EXTERNAL *,Map<CON *,Array<unsigned long> *,LHashClass2<void *,7,3> > *,LHashClass2<void *,7,3> >
{
protected:
	int find(EXTERNAL *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<EXTERNAL *,Map<CON *,Array<unsigned long> *,LHashClass2<void *,7,3> > *,LHashClass2<void *,7,3> >(unsigned int);
	int add(EXTERNAL *,Map<CON *,Array<unsigned long> *,LHashClass2<void *,7,3> > *);
	int map(EXTERNAL *,Map<CON *,Array<unsigned long> *,LHashClass2<void *,7,3> > * *);
};

class Map<EXTERNAL *,NODE *,LHashClass2<void *,7,3> >
{
protected:
	int find(EXTERNAL *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<EXTERNAL *,NODE *,LHashClass2<void *,7,3> >(unsigned int);
	int add(EXTERNAL *,NODE *);
	int map(EXTERNAL *,NODE * *);
	void clear();
	~Map<EXTERNAL *,NODE *,LHashClass2<void *,7,3> >();
};

class Map<EXTERNAL *,TKMOD,LHashClass2<void *,7,3> >
{
protected:
	int find(EXTERNAL *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<EXTERNAL *,TKMOD,LHashClass2<void *,7,3> >(unsigned int);
	int add(EXTERNAL *,TKMOD);
	void clear();
	~Map<EXTERNAL *,TKMOD,LHashClass2<void *,7,3> >();
};

class Map<EXTERNAL *,WEAK_DEFAULT,LHashClass2<void *,7,3> >
{
protected:
	int find(EXTERNAL *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<EXTERNAL *,WEAK_DEFAULT,LHashClass2<void *,7,3> >(unsigned int);
	int add(EXTERNAL *,WEAK_DEFAULT);
	int map(EXTERNAL *,WEAK_DEFAULT *);
};

class Map<EXTERNAL *,unsigned __int64,LHashClass2<void *,7,3> >
{
protected:
	int find(EXTERNAL *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<EXTERNAL *,unsigned __int64,LHashClass2<void *,7,3> >(unsigned int);
	int add(EXTERNAL *,unsigned __int64);
	int map(EXTERNAL *,unsigned __int64 *);
	int remove(EXTERNAL *);
	void clear();
	~Map<EXTERNAL *,unsigned __int64,LHashClass2<void *,7,3> >();
};

class Map<EXTERNAL *,unsigned long,LHashClass2<void *,7,3> >
{
protected:
	int find(EXTERNAL *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<EXTERNAL *,unsigned long,LHashClass2<void *,7,3> >(unsigned int);
	int add(EXTERNAL *,unsigned long);
	int map(EXTERNAL *,unsigned long *);
	void clear();
	~Map<EXTERNAL *,unsigned long,LHashClass2<void *,7,3> >();
};

class Map<GRP *,unsigned long,LHashClass2<void *,7,3> >
{
protected:
	int find(GRP *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<GRP *,unsigned long,LHashClass2<void *,7,3> >(unsigned int);
	int add(GRP *,unsigned long);
};

class Map<LINK_FILE_ID,MOD *,HashClassCRC<LINK_FILE_ID> >
{
protected:
	int find(LINK_FILE_ID,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<LINK_FILE_ID,MOD *,HashClassCRC<LINK_FILE_ID> >(unsigned int);
	int add(LINK_FILE_ID,MOD *);
	int map(LINK_FILE_ID,MOD * *);
	void clear();
	~Map<LINK_FILE_ID,MOD *,HashClassCRC<LINK_FILE_ID> >();
};

class Map<LONG_BRANCH_REGION *,unsigned long,LHashClass2<void *,7,3> >
{
protected:
	int find(LONG_BRANCH_REGION *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<LONG_BRANCH_REGION *,unsigned long,LHashClass2<void *,7,3> >(unsigned int);
	int add(LONG_BRANCH_REGION *,unsigned long);
	void clear();
	~Map<LONG_BRANCH_REGION *,unsigned long,LHashClass2<void *,7,3> >();
};

class Map<MOD *,Array<CON *> *,LHashClass2<void *,7,3> >
{
protected:
	int find(MOD *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<MOD *,Array<CON *> *,LHashClass2<void *,7,3> >(unsigned int);
	int add(MOD *,Array<CON *> *);
	int map(MOD *,Array<CON *> * *);
	int remove(MOD *);
	void clear();
	~Map<MOD *,Array<CON *> *,LHashClass2<void *,7,3> >();
};

class Map<MOD *,CTaskQueue::MSGBLOCKPAIR *,LHashClass2<void *,7,3> >
{
protected:
	int find(MOD *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<MOD *,CTaskQueue::MSGBLOCKPAIR *,LHashClass2<void *,7,3> >(unsigned int);
	int add(MOD *,CTaskQueue::MSGBLOCKPAIR *);
	int map(MOD *,CTaskQueue::MSGBLOCKPAIR * *);
	int remove(MOD *);
	void clear();
};

class Map<MOD *,MOD *,LHashClass2<void *,7,3> >
{
protected:
	int find(MOD *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<MOD *,MOD *,LHashClass2<void *,7,3> >(unsigned int);
	int add(MOD *,MOD *);
	int map(MOD *,MOD * *);
	void clear();
	~Map<MOD *,MOD *,LHashClass2<void *,7,3> >();
};

class Map<MOD *,Map<CON *,Array<CON *> *,LHashClass2<void *,7,3> > *,LHashClass2<void *,7,3> >
{
protected:
	int find(MOD *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
public:
	Map<MOD *,Map<CON *,Array<CON *> *,LHashClass2<void *,7,3> > *,LHashClass2<void *,7,3> >(unsigned int);
	int add(MOD *,Map<CON *,Array<CON *> *,LHashClass2<void *,7,3> > *);
	void clear();
};

class Map<MOD *,Map<GRP *,unsigned long,LHashClass2<void *,7,3> > *,LHashClass2<void *,7,3> >
{
protected:
	int find(MOD *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<MOD *,Map<GRP *,unsigned long,LHashClass2<void *,7,3> > *,LHashClass2<void *,7,3> >(unsigned int);
	int add(MOD *,Map<GRP *,unsigned long,LHashClass2<void *,7,3> > *);
	void clear();
	~Map<MOD *,Map<GRP *,unsigned long,LHashClass2<void *,7,3> > *,LHashClass2<void *,7,3> >();
};

class Map<MOD *,unsigned long,LHashClass2<void *,7,3> >
{
protected:
	int find(MOD *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<MOD *,unsigned long,LHashClass2<void *,7,3> >(unsigned int);
	int add(MOD *,unsigned long);
	int map(MOD *,unsigned long *);
	void clear();
	~Map<MOD *,unsigned long,LHashClass2<void *,7,3> >();
};

class Map<SrcHeaderW *,unsigned char *,LHashClass2<void *,7,3> >
{
protected:
	int find(SrcHeaderW *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<SrcHeaderW *,unsigned char *,LHashClass2<void *,7,3> >(unsigned int);
	int add(SrcHeaderW *,unsigned char *);
	void clear();
	~Map<SrcHeaderW *,unsigned char *,LHashClass2<void *,7,3> >();
};

class Map<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> >
{
protected:
	int find(unsigned __int64,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> >(unsigned int);
	int add(unsigned __int64,char *);
	int map(unsigned __int64,char * *);
	void clear();
};

class Map<unsigned int,TkEmitTCEInfo *,HashClassCRC<unsigned int> >
{
protected:
	int find(unsigned int,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<unsigned int,TkEmitTCEInfo *,HashClassCRC<unsigned int> >(unsigned int);
	int add(unsigned int,TkEmitTCEInfo *);
	int map(unsigned int,TkEmitTCEInfo * *);
	void clear();
	void reset();
	~Map<unsigned int,TkEmitTCEInfo *,HashClassCRC<unsigned int> >();
};

class Map<unsigned int,unsigned int,HashClassCRC<unsigned int> >
{
protected:
	int find(unsigned int,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
public:
	Map<unsigned int,unsigned int,HashClassCRC<unsigned int> >(unsigned int);
	int add(unsigned int,unsigned int);
	int map(unsigned int,unsigned int *);
	void clear();
	~Map<unsigned int,unsigned int,HashClassCRC<unsigned int> >();
};

class Map<unsigned long,Array<GRP *> *,HashClassCRC<unsigned long> >
{
protected:
	int find(unsigned long,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<unsigned long,Array<GRP *> *,HashClassCRC<unsigned long> >(unsigned int);
	int add(unsigned long,Array<GRP *> *);
	int map(unsigned long,Array<GRP *> * *);
	void clear();
	~Map<unsigned long,Array<GRP *> *,HashClassCRC<unsigned long> >();
};

class Map<unsigned long,Array<PdataMgr::FuncStartEnd> *,HashClassCRC<unsigned int> >
{
protected:
	int find(unsigned long,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<unsigned long,Array<PdataMgr::FuncStartEnd> *,HashClassCRC<unsigned int> >(unsigned int);
	int add(unsigned long,Array<PdataMgr::FuncStartEnd> *);
	int map(unsigned long,Array<PdataMgr::FuncStartEnd> * *);
	void clear();
	void reset();
	~Map<unsigned long,Array<PdataMgr::FuncStartEnd> *,HashClassCRC<unsigned int> >();
};

class Map<unsigned long,Map<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> > *,HashClass<unsigned long,0> >
{
protected:
	int find(unsigned long,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<unsigned long,Map<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> > *,HashClass<unsigned long,0> >(unsigned int);
	int add(unsigned long,Map<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> > *);
	int map(unsigned long,Map<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> > * *);
	void clear();
};

class Map<unsigned long,Map<unsigned long,unsigned long,HashClassCRC<unsigned int> > *,HashClassCRC<unsigned int> >
{
protected:
	int find(unsigned long,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<unsigned long,Map<unsigned long,unsigned long,HashClassCRC<unsigned int> > *,HashClassCRC<unsigned int> >(unsigned int);
	int add(unsigned long,Map<unsigned long,unsigned long,HashClassCRC<unsigned int> > *);
	void clear();
	void reset();
};

class Map<unsigned long,Warbird::CWarbirdLinkerTransformations::PRIVATE_SYMBOL,HashClassCRC<unsigned long> >
{
protected:
	int find(unsigned long,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<unsigned long,Warbird::CWarbirdLinkerTransformations::PRIVATE_SYMBOL,HashClassCRC<unsigned long> >(unsigned int);
	int add(unsigned long,Warbird::CWarbirdLinkerTransformations::PRIVATE_SYMBOL);
	int map(unsigned long,Warbird::CWarbirdLinkerTransformations::PRIVATE_SYMBOL *);
	void clear();
	void reset();
};

class Map<unsigned long,unsigned long,HashClassCRC<unsigned int> >
{
protected:
	int find(unsigned long,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<unsigned long,unsigned long,HashClassCRC<unsigned int> >(unsigned int);
	int add(unsigned long,unsigned long);
	void clear();
	~Map<unsigned long,unsigned long,HashClassCRC<unsigned int> >();
};

class Map<unsigned long,unsigned long,HashClassCRC<unsigned long> >
{
protected:
	int find(unsigned long,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
public:
	Map<unsigned long,unsigned long,HashClassCRC<unsigned long> >(unsigned int);
	int add(unsigned long,unsigned long);
	int map(unsigned long,unsigned long *);
	void clear();
};

class Map<unsigned long,unsigned long,LHashClass<unsigned long,0> >
{
protected:
	int find(unsigned long,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<unsigned long,unsigned long,LHashClass<unsigned long,0> >(unsigned int);
	int add(unsigned long,unsigned long);
	int map(unsigned long,unsigned long *);
	void clear();
	~Map<unsigned long,unsigned long,LHashClass<unsigned long,0> >();
};

class Map<unsigned short *,unsigned char,LHashClass2<void *,7,3> >
{
protected:
	int find(unsigned short *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<unsigned short *,unsigned char,LHashClass2<void *,7,3> >(unsigned int);
	int add(unsigned short *,unsigned char);
	void clear();
	~Map<unsigned short *,unsigned char,LHashClass2<void *,7,3> >();
};

class Map<void *,EXTERNAL *,LHashClass2<void *,7,3> >
{
protected:
	int find(void *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<void *,EXTERNAL *,LHashClass2<void *,7,3> >(unsigned int);
	int add(void *,EXTERNAL *);
	int map(void *,EXTERNAL * *);
	void clear();
	void reset();
	~Map<void *,EXTERNAL *,LHashClass2<void *,7,3> >();
};

class Map<void *,unsigned long,LHashClass2<void *,7,3> >
{
protected:
	int find(void *,unsigned int *,unsigned int *,unsigned int *,unsigned int *);
	int grow(bool &);
public:
	Map<void *,unsigned long,LHashClass2<void *,7,3> >(unsigned int);
	int add(void *,unsigned long);
	void clear();
	void reset();
	~Map<void *,unsigned long,LHashClass2<void *,7,3> >();
};

struct MapEmitter
{
	virtual bool Pre();
	virtual bool PreExports();
	virtual bool PreExternals();
	virtual bool PreSections();
	virtual bool PreStatics();
	virtual void Export(char const *,int,bool,char const *);
	virtual void External(char const *,EXTERNAL *,CON *);
	virtual void Section(GRP *,SEC *,bool);
	virtual void Static(char const *,CON *,MOD *,unsigned long,bool);
};

class NMT<char>
{
	int addSz(char const *,unsigned long *);
	int find(char const *,unsigned long *,unsigned int *);
	int grow();
	static unsigned long hashSz(char const *);
	void rehash(unsigned int);
public:
	NMT<char>();
	char * szForNi(unsigned long);
	int addNiForSz(char const *,unsigned long *);
	int reset();
	~NMT<char>();
};

class NMT<unsigned short>
{
	int addSz(unsigned short const *,unsigned long *);
	int find(unsigned short const *,unsigned long *,unsigned int *);
	int grow();
	void rehash(unsigned int);
public:
	NMT<unsigned short>();
	int addNiForSz(unsigned short const *,unsigned long *);
	int reset();
	unsigned short * szForNi(unsigned long);
	~NMT<unsigned short>();
};

namespace PDBCRC32
{
	unsigned long SigForPbCb(unsigned char *,unsigned int,unsigned long);
};

struct PGDEmitter
{
	virtual bool Pre();
	virtual void External(char const *,EXTERNAL *,CON *);
	virtual void Static(char const *,CON *,MOD *,unsigned long,bool);
	~PGDEmitter();
};

struct POOL<4>
{
	struct IMM_BLK
	{
		static void * operator new(unsigned int,bool,unsigned int);
		void * alloc(unsigned int);
	};

	POOL<4>(bool,unsigned int);
	void * alloc(unsigned int);
};

class PdataMgr
{
	static int CompareArmNtRFEs(void const *,void const *);
	static int CompareIa64RFEs(void const *,void const *);
	static int ComparePdataEntries(void const *,void const *);
	static int CompareXFixups(void const *,void const *);
	static void VerifyPdataContents(void *,unsigned long,unsigned short,CON *);
	void UpdatePdataForLBRs(Map<unsigned long,unsigned long,HashClassCRC<unsigned int> > *);
public:
	PdataMgr();
	bool FAddRFEsForPcon(IMAGE *,void *,CON *);
	bool FInitIncr();
	bool FSetCurrentPcon(CON *);
	static bool FUseArmNtPdata(unsigned short);
	static bool FUseCompressedPdata(unsigned short);
	static unsigned int CFixupsPerRFE(unsigned short);
	static void operator delete(void *);
	unsigned long CbRFE();
	void CollectLeafFunctions(IMAGE *,MOD *);
	void GeneratePdataForIntraLBRs(IMAGE *,MOD *);
	void RegisterFunctionSymbol(unsigned long,unsigned long);
	void RegisterIntraLBR(unsigned long,unsigned long);
	void SaveDebugFixup(unsigned short,unsigned short,unsigned long,unsigned long);
	void ScanPdataRelocations(MOD *,CON *,IObjectContrib *,COMRefPtr<ICOFFSymTabRO> &);
	void SortAndEmitPdata(IMAGE *,bool);
	~PdataMgr();
};

struct ST
{
	EXTERNAL * * RgpexternalByModName();
	EXTERNAL * * RgpexternalByName();
	EXTERNAL * LookupExternSz(char const *,bool *,unsigned long);
	EXTERNAL * LookupExternSz(unsigned short const *,bool *);
	EXTERNAL * PexternalEnumerateNext();
	EXTERNAL * SearchExternSz(char const *);
	void AllowInserts();
	void PrintUndefinedExternals(bool,bool);
};

struct STR_LIST
{
	void AddToList(unsigned short const *);
	void FreeList();
};

class SafeStackAllocator<32>
{
protected:
	void * AllocInHeap(unsigned int);
public:
	virtual void * AllocBytes(unsigned int);
	virtual void Free(void *);
	~SafeStackAllocator<32>();
};

class SafeStackAllocator<4096>
{
protected:
	void * AllocInHeap(unsigned int);
public:
	virtual void * AllocBytes(unsigned int);
	virtual void Free(void *);
	~SafeStackAllocator<4096>();
};

struct Stack<CON *>
{
	~Stack<CON *>();
};

struct SymInfoEmitter
{
	unsigned __int64 VABase();
	virtual bool PreExports();
	virtual bool PreExternals();
	virtual bool PreSections();
	virtual bool PreStatics();
	virtual void Export(char const *,int,bool,char const *);
	virtual void Post();
	virtual void PostExports();
	virtual void PostExternals();
	virtual void PostSections();
	virtual void PostStatics();
	virtual void Section(GRP *,SEC *,bool);
};

struct TIME64
{
	bool operator!=(TIME64 const &);
	void GetTime(unsigned short const *,bool *);
};

struct TrampSyms
{
	void CreateSym(unsigned long,unsigned long,unsigned long,unsigned long,int,int);
	void Init(IMAGE *,TRAMP_e,unsigned int,unsigned int);
};

class UniqUTF16StringTable
{
	unsigned short const * szFind(unsigned short const *,LSL * * &,Array<LSL * *> &);
public:
	UniqUTF16StringTable(bool);
	unsigned short const * SzAdd(unsigned short const *,bool *);
	~UniqUTF16StringTable();
};

class VCToolsTelemetryClient
{
	bool IsSwitchItem(unsigned long);
public:
	VCToolsTelemetryClient();
	void AddC2LTCGCodegenItems(unsigned long *,unsigned long);
	void AddItem(unsigned long,unsigned long);
	void AddItemEx(unsigned long,unsigned char *,unsigned long);
	void WriteRawTelemetryData();
	~VCToolsTelemetryClient();
};

namespace VCUtil
{
	long LoadUILibrary(unsigned short const *,unsigned short const *,unsigned long,HINSTANCE__ * *,unsigned short *,unsigned int,unsigned short *,unsigned short * (*)(unsigned short *,unsigned short *));
};

struct WSZTEMPUTF8
{
	~WSZTEMPUTF8();
};

namespace Warbird
{
	class CWarbirdClient
	{
		CWarbirdClient();
		unsigned long GetSegmentType(CON *);
		void CleanupConSymbolTable();
	public:
		int IsEnabled();
		int IsExcludedSymbol(char const *);
		long FinishProcessNonLtcgModule();
		long Initialize(IMAGE *,unsigned short const *,unsigned short const *,unsigned short const *,int,int);
		long RegisterSymbol(char const *,int,unsigned char,CON *,MOD *,unsigned long,int);
		long TransformFunction(Phase);
		static CWarbirdClient * GetInstance();
		void CleanPrivateSymbolTable();
		void SetRegisterNonLtcgSymbol(int);
		void UnInitialize();
		~CWarbirdClient();
	};

	class CWarbirdLinkerTransformations
	{
		EXTERNAL * SearchGlobalSymbolTableAndValidate(char const *);
		long SwapModuleEntryFunction(EXTERNAL *,unsigned long *);
		unsigned long GetSegmentFlags(unsigned long,unsigned long);
	public:
		CON * GetSymbolContribution(char const *,long);
		char * CreatePrivateSymbolKey(char const *,void *);
		long FindPrivateSymbol(char const *,void *,CWarbirdLinkerTransformations::PRIVATE_SYMBOL &);
		long RegisterPrivateSymbol(char const *,unsigned char,CON *,MOD *,unsigned long);
		static CON * GetSelectedCon(CON *);
		virtual long AddSymbolToGuardTable(char const *,void *);
		virtual long AddSymboltoTCEGraph(char const *,long);
		virtual long AddSymboltoTCEGraph(char const *,long,char const *,long);
		virtual long GetContributionLocation(void *,tagWARBIRD_LINK_SYMBOL &);
		virtual long GetImageType(IMAGE_TYPE *);
		virtual long GetRelocations(unsigned long,unsigned long,unsigned long,tagWARBIRD_PRIVATE_RELOCATION_ITEM *,unsigned long &);
		virtual long GetSectionLocation(char const *,unsigned long &,unsigned long &,unsigned long &,long);
		virtual long GetSymbolLocation(char const *,void *,tagWARBIRD_LINK_SYMBOL &,long);
		virtual long GetSymbolRelocsCount(char const *,void *,unsigned long &,long);
		virtual long Log(LogLevel,unsigned short const *);
		virtual long ReadBytes(unsigned long,unsigned char *,unsigned long);
		virtual long ReplaceEntryFunction(char const *,void *,unsigned long *);
		virtual long SetSymbolValue(char const *,void *,unsigned char *,unsigned long,int);
		virtual long WriteBytes(unsigned long,unsigned char *,unsigned long);
		virtual unsigned __int64 GetImageBase();
		virtual unsigned long GetRelocStartRva(unsigned long,unsigned short &,unsigned short &);
		virtual unsigned long SetSectionFlags(char const *,unsigned long,unsigned long);
		virtual unsigned short const * GetBinaryFilename();
		virtual void * CreateSegment(char const *,unsigned long,unsigned long,unsigned long);
		~CWarbirdLinkerTransformations();
	};

	struct CWarbirdServer
	{
		long CreateObfuscator(unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,unsigned long,CObfuscatorBase * *);
		~CWarbirdServer();
	};

	struct tagWARBIRD_SYMBOL
	{
		tagWARBIRD_SYMBOL();
	};

	int WarbirdNonLtcgSymCompare(void const *,void const *);
};

class __B64
{
	static char const * const m_rgchBase64Digits;
	unsigned int UConvertChOneDigit(char);
	void ConvertToUint(char const *);
};

namespace std
{
	class _Hash<_Umap_traits<unsigned long,_VCTools_Telemetry_RawDataEx *,_Uhash_compare<unsigned long,hash<unsigned long>,equal_to<unsigned long> >,allocator<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> >,0> >
	{
	protected:
		_List_unchecked_const_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > >,_Iterator_base0> _End(unsigned int);
		pair<_List_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > >,bool> _Insert<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> &,_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > >(pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> &,_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > >);
		void _Check_size();
		void _Erase_bucket(_List_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > >,unsigned int);
		void _Init(unsigned int);
		void _Insert_bucket(_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > >,_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > >,unsigned int);
		void _Reinsert();
	public:
		_Hash<_Umap_traits<unsigned long,_VCTools_Telemetry_RawDataEx *,_Uhash_compare<unsigned long,hash<unsigned long>,equal_to<unsigned long> >,allocator<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> >,0> >(_Uhash_compare<unsigned long,hash<unsigned long>,equal_to<unsigned long> > const &,allocator<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > const &);
		_List_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > erase(_List_const_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > >);
		float load_factor();
		pair<_List_const_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > >,_List_const_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > > equal_range(unsigned long const &);
		~_Hash<_Umap_traits<unsigned long,_VCTools_Telemetry_RawDataEx *,_Uhash_compare<unsigned long,hash<unsigned long>,equal_to<unsigned long> >,allocator<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> >,0> >();
	};

	struct _List_alloc<_List_base_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *>,allocator<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > >
	{
		_List_node<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *>,void *> * _Buynode0(_List_node<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *>,void *> *,_List_node<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *>,void *> *);
	};

	struct _List_buy<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *>,allocator<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > >
	{
		_List_node<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *>,void *> * _Buynode<unsigned long &,_VCTools_Telemetry_RawDataEx * &>(_List_node<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *>,void *> *,_List_node<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *>,void *> *,unsigned long &,_VCTools_Telemetry_RawDataEx * &);
	};

	struct list<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *>,allocator<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > >
	{
		_List_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > erase(_List_const_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > >);
		void _Insert<unsigned long &,_VCTools_Telemetry_RawDataEx * &>(_List_unchecked_const_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > >,_Iterator_base0>,unsigned long &,_VCTools_Telemetry_RawDataEx * &);
		void clear();
		~list<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *>,allocator<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > >();
	};

	struct unordered_map<unsigned long,_VCTools_Telemetry_RawDataEx *,hash<unsigned long>,equal_to<unsigned long>,allocator<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > >
	{
		~unordered_map<unsigned long,_VCTools_Telemetry_RawDataEx *,hash<unsigned long>,equal_to<unsigned long>,allocator<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > >();
	};

	class vector<_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > >,_Wrap_alloc<allocator<_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > > > >
	{
	protected:
		_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > * _Ufill(_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > *,unsigned int,_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > const *);
		_Vector_iterator<_Vector_val<_Simple_types<_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > > > > _Insert_n(_Vector_const_iterator<_Vector_val<_Simple_types<_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > > > >,unsigned int,_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > const &);
		unsigned int _Grow_to(unsigned int);
		void _Reallocate(unsigned int);
	public:
		~vector<_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > >,_Wrap_alloc<allocator<_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > > > >();
	};

	std::_List_unchecked_iterator<std::_List_val<std::_List_simple_types<std::pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > * _Uninitialized_move_al_unchecked1<_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > *,_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > *,_Wrap_alloc<allocator<_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > > > >(std::_List_unchecked_iterator<std::_List_val<std::_List_simple_types<std::pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > *,std::_List_unchecked_iterator<std::_List_val<std::_List_simple_types<std::pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > *,std::_List_unchecked_iterator<std::_List_val<std::_List_simple_types<std::pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > *,std::_Wrap_alloc<std::_Wrap_alloc<std::allocator<std::_List_unchecked_iterator<std::_List_val<std::_List_simple_types<std::pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > > > > &,std::_General_ptr_iterator_tag,std::_Any_tag);
	void * _Allocate(unsigned int,unsigned int,bool);
	void _Deallocate(void *,unsigned int,unsigned int);
	void _Uninit_alloc_fill_n1<_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > *,unsigned int,_Wrap_alloc<allocator<_List_unchecked_iterator<_List_val<_List_simple_types<pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > > > >(std::_List_unchecked_iterator<std::_List_val<std::_List_simple_types<std::pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > *,unsigned int,std::_List_unchecked_iterator<std::_List_val<std::_List_simple_types<std::pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > const *,std::_Wrap_alloc<std::_Wrap_alloc<std::allocator<std::_List_unchecked_iterator<std::_List_val<std::_List_simple_types<std::pair<unsigned long const ,_VCTools_Telemetry_RawDataEx *> > > > > > > &,std::integral_constant<bool,0>);
};

ALTERNATE_NAME * FindAlternateName(IMAGE const *,char const *);
ARGUMENT_LIST * AddToModList(ARGUMENT_LIST *,unsigned short);
ARGUMENT_LIST * FindInFilenameArguments(unsigned short const *);
ARGUMENT_LIST * PargFindSz(unsigned short const *,NAME_LIST *);
ARGUMENT_LIST * PargFindSzModified(unsigned short const *,NAME_LIST *);
ARGUMENT_LIST * pargFirst;
ARMTOTHUMBTHUNK ArmToThumbThunk;
ARP * ParpParseSz(unsigned short const *,unsigned short const *);
Array<ARGUMENT_LIST *> g_rgResFiles;
Array<CON *> g_rgpconLinkerDefinedRefdInCurMod;
Array<ICF_GRP *> g_rgICFGrp;
Array<ImplicitDllImportInfo> s_rgImplicitDllImportInfo;
Array<TransInfo> * g_prgMToUMTrans;
Array<char *> g_rgszDiscardPublic;
Array<char const *> g_rgszTrimFilePrefix;
Array<tagPGDOBJECTRECORD> g_rgObjRecPGO;
Array<unsigned short *> g_rgszTmdIgnoreTypes;
Array<unsigned short const *> g_rgszCvtcilArgs;
Array<unsigned short const *> g_rgszNatvisNew;
Array<unsigned short const *> g_rgszNatvisRemove;
BASE_RELOC * NextEnmNonAbsBaseReloc(ENM_BASE_RELOC *,IMAGE *);
BASE_RELOC * pbrCur;
BASE_RELOC * rgbr;
BLK blkDirectives;
BUF * PbufAlloc(FI *,unsigned long);
BUF * PbufLRU();
Buffer g_bufCmdLineOptions;
CCONST * PvReallocEx<CCONST>(CCONST *,unsigned int);
CImplib * CreateTmpImplib(IMAGE *,LIB *,int,IMPORT_OBJECT_HEADER const &,_IMAGE_FILE_HEADER *,unsigned short const *,bool);
CImplib * g_pimplib;
CLockCS g_csMsg;
CMemCoordinator * g_memCoordinator;
CMismatches * g_pMismatchMap;
COMDAT_ISYMS * BuildIsecToIsymMapping(CON *,ICOFFSymTabRO *);
CON * PconCreateLBR(IMAGE *,CON *,unsigned long,unsigned long);
CON * PconFindOldPMOD(MOD *,CON *);
CON * PconICFPcon(CON *);
CON * PconSelectedComdat(CON *);
CON * g_pconTextBss;
CON * pconCvSignature;
CON * pconDebugDir;
CTaskQueue * g_ptaskqETM;
CTickCount ticCounter;
CVCOMPILE2 CvCompile2C11;
CVCOMPILE3 CvCompile3;
CVEND const CvEnd;
CVOBJNAME CvObjName;
CVOBJNAME CvObjNameC11;
CVSIG CvSig;
CVTHUNK CvThunk;
CorPinvokeMap GetCallingConventionFromCorSig(unsigned char const *,unsigned long);
DBI * g_pdbi;
DFT dft;
DIS * PdisInitDisasm(DUMPSTATE *,DIS::DIST);
DL * PdlFind(unsigned short const *,DL *);
DTI const * const g_pdti;
Dbg * g_pdbgFpo;
Dbg * g_pdbgOmapFrom;
Dbg * g_pdbgOmapTo;
Dbg * g_pdbgPdata;
Dbg * g_pdbgSectionHdr;
Dbg * g_pdbgSectionHdrOrig;
Dbg * g_pdbgXdata;
Dbg * g_pdbgXfixup;
DbgThunkSymHdr const g_c13SymHdr;
DiscardRVA g_discardRva;
EDGE * PedgeNew_TCE(CON *,CON *,unsigned short,unsigned long,unsigned char,bool);
EDGE * PedgeNew_TCE(CON *,MOD *,unsigned int,bool,unsigned short,unsigned long,unsigned char,bool);
EDGE * PedgeNew_TCE(CON *,unsigned long,unsigned short,unsigned long,unsigned char,bool);
EDGE * PedgeNew_TCE(IMAGE *,EXTERNAL *,bool,EXTERNAL *,bool);
ELEMENT * PelementEnumerateNext_HT(HT *);
ELEMENT * PelementLookup_HT(char const *,HT *,bool,void *,bool *);
ERRINC ChckAbsSym(IMAGE *,char const *,unsigned long,EXTERNAL *,bool);
ERRINC ChckExtSym(char const *,unsigned long,unsigned short,EXTERNAL *,bool);
ERRINC errInc;
EXTERNAL * * RgpexternalSort(ST *,int (*)(void const *,void const *));
EXTERNAL * LookForEntry(IMAGE *,EntryRecord const *,int,bool *,char const * *,unsigned short const * *);
EXTERNAL * LookForMain(IMAGE *,bool *,char const * *,unsigned short const * *);
EXTERNAL * LookForWinMain(IMAGE *,bool *,char const * *,unsigned short const * *);
EXTERNAL * PextEntryPoint(IMAGE *);
EXTERNAL * PextFromTk(IMAGE *,MOD *,unsigned int);
EXTERNAL * TrackNonNativeStatic(char const *,unsigned __int64);
EXTERNAL * pextComEntry;
FEATUREI g_featureInfo;
FI * * rgpfi;
FI * LookupCachedFiles(unsigned short const *,int,int,bool *);
FI * PfiAlloc();
FI * PfiClosedCached(unsigned short const *);
FIXPAG * pfixpagCur;
FIXPAG * pfixpagHead;
GRP * PgrpFind(SEC *,char const *);
GRP * pgrpCvPTypes;
GRP * pgrpCvSymbols;
GRP * pgrpCvTypes;
GRP * pgrpExport;
GRP * pgrpFirstTLS;
GRP * pgrpFpoData;
GRP * pgrpLastTLS;
HINSTANCE__ * DloadKernel32;
ICOFFAuxSym * PICOFFAuxSymComFind(MOD *,COMRefPtr<IEnumAuxSym> &,unsigned char);
IDLStuff g_IDLStuff;
ILINKINFO * PilinkinfoFromMachine(IMAGE *);
ILINKINFO ilinkinfoArm64;
ILINKINFO ilinkinfoArmNT;
ILINKINFO ilinkinfoX86;
IMAGE * g_pimageWinMD;
IMAGE * pimageDump;
IMPORT_OBJECT_TYPE ImportType(unsigned long);
IObjFile2 * PObjFileForFile(unsigned short const *,unsigned short const *,IMAGE *,MOD *,bool *,unsigned long,unsigned long,LIB *,unsigned short const *,char const *,bool,unsigned long *,bool,bool);
IObjHandler6 * g_pILHandler;
ISet g_isetDeletedMods;
LEXT * FindPlextForPext(EXTERNAL const *,LEXT *);
LEXT * g_plextTextBss;
LHEAPV * PlheapvNew(unsigned int,unsigned int);
LIB * AddArchiveArg(IMAGE *,unsigned short const *);
LIB * FindLib(unsigned short const *,LIBS *);
LIB * PlibFind(unsigned short const *,LIB *,bool);
LIB * g_plibModObjs;
LIB * plibCmdLineObjs;
MI * PmiLookupCachedMods(MOD *);
MOD * FindPmodDefiningSym(SYM_DEF *,EXTERNAL *);
MOD * PmodConvertCIL(ARGUMENT_LIST *,MOD *,LIB *,IMAGE *,bool *);
MOD * PmodFindPrevPMOD(MOD *);
MOD * PmodOrig(ICOFFSymRO *,MOD *);
MOD * PmodOrig(ICOFFSymRW *,MOD *);
MOD * PmodOrig(IObjectContrib *,MOD *);
MOD * PmodOrig(char const *);
MOD * PmodPreprocessFile(ARGUMENT_LIST *,LIB *,IMAGE *,bool *);
MOD * PmodProcessObjectFile(ARGUMENT_LIST *,IMAGE *,LIB *);
MOD * g_pmodCIL;
Map<CON *,Array<CON *> *,LHashClass2<void *,7,3> > * CollectAssociativeComdats(MOD *);
Map<CON *,MOD *,LHashClass2<void *,7,3> > * g_pmpCILPconPmod;
Map<CON *,char const *,LHashClass2<void *,7,3> > g_mpPconSzSym;
Map<EXTERNAL *,EXTERNAL *,LHashClass2<void *,7,3> > g_mpMPextUMPext;
Map<EXTERNAL *,TKMOD,LHashClass2<void *,7,3> > g_mppexttkmodComdat;
Map<EXTERNAL *,unsigned __int64,LHashClass2<void *,7,3> > g_mpDllImportPextIsym;
Map<LINK_FILE_ID,MOD *,HashClassCRC<LINK_FILE_ID> > g_mpCmdLineObjFileID;
Map<LONG_BRANCH_REGION *,unsigned long,LHashClass2<void *,7,3> > g_mpLBRsForIncrEmit;
Map<MOD *,MOD *,LHashClass2<void *,7,3> > g_mpLibPmodMap;
Map<SrcHeaderW *,unsigned char *,LHashClass2<void *,7,3> > g_mpSrcHdrToRaw;
Mod * PmodDBIOpenMod(unsigned short const *,unsigned short const *);
NAME_LIST ArchiveFilenameArguments;
NAME_LIST ArchiveFilenameArgumentsPGO;
NAME_LIST DynValueFixupSyms;
NAME_LIST ExportDirectives;
NAME_LIST ExportSwitches;
NAME_LIST FilenameArguments;
NAME_LIST FilenameArgumentsPGO;
NAME_LIST LibPaths;
NAME_LIST MergeSwitches;
NAME_LIST ModFileList;
NAME_LIST ObjectFilenameArguments;
NAME_LIST ObjectFilenameArgumentsPGO;
NAME_LIST PchMapping;
NAME_LIST PdbMapping;
NAME_LIST SwitchArguments;
NAME_LIST SwitchArgumentsPGO;
NAME_LIST WinmdMapping;
NAME_LIST g_nlLTCGMetaOutFilenames;
NODE * PnodePcon(CON *);
NODE * PnodePext(IMAGE *,EXTERNAL *,bool);
PDB * g_ppdb;
PUBSYM32 const * PPubsymLookupExact(DUMPSTATE const *,unsigned long);
PUBSYM32 const * RetrievePublicSymbol(DUMPSTATE const *,unsigned __int64);
RESERVED_SECTION const ReservedSection;
ResHdr g_resHdr;
SEC * PsecApplyMergePsec(SEC *);
SEC * g_psecTextBss;
SEC * psecBaseReloc;
SEC * psecCommon;
SEC * psecData;
SEC * psecDebug;
SEC * psecDelayLoadDescriptor;
SEC * psecDidat2;
SEC * psecDidat5;
SEC * psecException;
SEC * psecExport;
SEC * psecGuardCF;
SEC * psecGuardIds;
SEC * psecIdata2;
SEC * psecIdata5;
SEC * psecImportDescriptor;
SEC * psecReadOnlyData;
SEC * psecResource;
SEC * psecXdata;
SOURCEMAP * psmHead;
SOURCEMAP * psmTail;
ST * g_pstOptRefLtcg;
SWITCH const DefSwitch;
SWITCH_INFO const DefSwitchInfo;
THUMB2LONGBRANCHTHUNK Thumb2LongBranchThunk;
THUMB2LONGBRANCHTHUNK Thumb2LongBranchThunkPGI;
THUNK_INFO const tiARM64;
THUNK_INFO const tiARMNT;
THUNK_INFO const tiX64;
THUNK_INFO const tiX86;
TOOL_TYPE Tool;
TPI * g_pipi;
TPI * g_ptpi;
TrampSyms g_trampSyms;
UTF8_NAME_LIST LastSectionNames;
UTF8_NAME_LIST NoFunctionPadSectionNames;
UTF8_NAME_LIST SectionNames;
VCToolsTelemetryClient g_vc_link_telemetry;
VirtualMemoryDumper vmdumper;
_IMAGE_ARCHIVE_MEMBER_HEADER * ReadArchiveMemberHeader(int);
_IMAGE_FILE_HEADER const DefImageFileHdr;
_IMAGE_OPTIONAL_HEADER64 const DefImageOptionalHdr;
_IMAGE_SECTION_HEADER * GlobalImgSecHdr;
_IMAGE_SECTION_HEADER * PImgSectHdrFromSz(_IMAGE_SECTION_HEADER *,unsigned long,char const *,bool *);
_IMAGE_SECTION_HEADER * PImgSectHdrFromSz(int,_IMAGE_FILE_HEADER *,char const *,bool *);
_IMAGE_SECTION_HEADER const NullSectionHdr;
_IMAGE_SYMBOL * ReadSymbolTableT<_IMAGE_SYMBOL>(int,unsigned long,unsigned long,bool);
_IMAGE_SYMBOL const NullSymbol;
_IMAGE_SYMBOL const g_symCvSymbol0;
_IMAGE_SYMBOL const g_symCvSymbol1;
_IMAGE_SYMBOL_EX * PsymDisasmLookup(DUMPSTATE const *,unsigned __int64,bool,unsigned __int64 *);
_IMAGE_SYMBOL_EX * ReadSymbolTableEx(int,unsigned long,unsigned long,bool,bool);
_IMAGE_SYMBOL_EX * ReadSymbolTableT<_IMAGE_SYMBOL_EX>(int,unsigned long,unsigned long,bool);
_RTL_SRWLOCK g_srwLockILKHeap;
__type_info_node __type_info_root_node;
_iobuf * InfoStream;
_iobuf * OpenClSqmLogFileForWriting(unsigned short const *);
_iobuf * link_fopen(char const *,char const *);
_iobuf * link_wfsopen(unsigned short const *,unsigned short const *,int);
_iobuf * pfileIDE;
_iobuf * pfileReproResponse;
_iobuf * pfileStdOut;
bool (* DBG_QuerySignature2)(_GUID *);
bool (* FSkipRelocation)(CON *,unsigned short,bool);
bool Arm64IsLongBranch(unsigned long,long);
bool ArmLBRNeeded(long,unsigned char,unsigned long);
bool ArmOffsetInRangeThunkType(long,unsigned char,unsigned long);
bool ArmShouldUsePGILongBranch(CON *,CON *);
bool BadFuzzyMatch;
bool CheckAndUpdateLinkerSwitches(IMAGE const *,IMAGE *);
bool CheckHResult(long);
bool CloseHardCachedFile(bool);
bool ColorTkEmit(IMAGE *,unsigned int);
bool ConvertDName(char const *,char *,unsigned int);
bool CvtCilAnObject(IMAGE *,MOD *,unsigned short const *);
bool DBG_CloseModError(DBGCONTEXT *);
bool DbgAddLinesMod_i(DBGCONTEXT *,unsigned short const *,unsigned short,unsigned long,unsigned long,unsigned long,unsigned long,void *,unsigned long);
bool DbgAddLinkInfo_i(DBGCONTEXT *,LinkInfoW *);
bool DbgAddSecContrib2Mod_i(DBGCONTEXT *,CON *,unsigned long);
bool DbgAddSecContribMod_i(DBGCONTEXT *,CON *);
bool DbgAddSymbolsMod_i(DBGCONTEXT *,void *,unsigned long,unsigned long);
bool DbgAddTypesMod_i(CTaskQueue *,void const *,unsigned long,bool &);
bool DbgAppend(DBGCONTEXT *,Dbg *,unsigned long,void const *);
bool DbgClear(DBGCONTEXT *,Dbg *);
bool DbgClearOmap_i(DBGCONTEXT *,bool);
bool DbgClose(DBGCONTEXT *,Dbg *);
bool DbgCloseCachedMod_i(DBGCONTEXT *,LIB *);
bool DbgCloseDBI_i(DBGCONTEXT *);
bool DbgCloseMod_i(DBGCONTEXT *);
bool DbgCloseOmap_i(DBGCONTEXT *,bool);
bool DbgCommitPDB_i(DBGCONTEXT *);
bool DbgCopySrcCore();
bool DbgCreateDBI_i(DBGCONTEXT *);
bool DbgDeleteOmap_i(DBGCONTEXT *);
bool DbgEndTypeMergingMod_i(DBGCONTEXT *);
bool DbgInjectNatvisCore();
bool DbgMergeTypesMod_i(DBGCONTEXT *,void *,unsigned long);
bool DbgNoteDiscardedRVAs_i(DBGCONTEXT *);
bool DbgOpen(DBGCONTEXT *,DBGTYPE,Dbg * *);
bool DbgOpenDBI_i(DBGCONTEXT *,bool);
bool DbgOpenMod_i(DBGCONTEXT *,MOD *);
bool DbgOpenOmap_i(DBGCONTEXT *,bool);
bool DbgQueryNext(DBGCONTEXT *,Dbg *,unsigned long,void *);
bool DbgQuerySignature2(_GUID *);
bool DbgRemoveGlobalRefsMod_i(DBGCONTEXT *);
bool DbgRemovePublicDBI_i(DBGCONTEXT *,char const *);
bool DbgReplace(DBGCONTEXT *,Dbg *,unsigned long,void const *);
bool DbgStQuerySignature2(_GUID *);
bool DbgWaitToCloseMod(MOD *);
bool ErrorReportingCheckOptIn();
bool ErrorReportingDisabled();
bool ExecuteDbgOp(CTaskQueue *,DBGOP *,bool &);
bool ExtendMapView(FI *,unsigned long,unsigned long *);
bool FActivateBuf(FI *,BUF *);
bool FAddressInPdata(unsigned long,unsigned long);
bool FArgOnList(NAME_LIST *,ARGUMENT_LIST const *);
bool FArm64SkipRelocation(CON *,unsigned short,bool);
bool FArmSkipRelocation(CON *,unsigned short,bool);
bool FArmThumbCode(unsigned long);
bool FAssemblyLinkResource();
bool FAssemblyModule();
bool FAssemblyResource();
bool FCheckRefByPMOD(EXTERNAL *,MOD *,IMAGE *,unsigned long *);
bool FComputeMD5Hash(void *,long,unsigned char *);
bool FCorImplictDllImport(IMAGE *,EXTERNAL *,unsigned short const *,unsigned long,bool);
bool FCorSupportLastError(IMAGE *,EXTERNAL *);
bool FCorSupportLastError(IMAGE *,unsigned short const *);
bool FDeactivateBuf(BUF *);
bool FDftObject();
bool FDisasmBuffer(DUMPSTATE *,unsigned short,bool,int,unsigned __int64,unsigned char const *,unsigned int,unsigned int,DUMP_DISASM_BYTES_TYPE);
bool FDisasmSection(DUMPSTATE *,unsigned short,_IMAGE_SECTION_HEADER *,unsigned long,unsigned __int64,unsigned char const *,unsigned long);
bool FDupAssemblyModule(unsigned short const *,ARGUMENT_LIST *);
bool FDupFilename(unsigned short const *,ARGUMENT_LIST *,unsigned short *);
bool FDynInitOrDtor(char const *);
bool FEbcSkipRelocation(CON *,unsigned short,bool);
bool FExists(unsigned short const *);
bool FExistsImplib(unsigned short const *,LIB *,CImplib * *);
bool FExpFileChanged(EXPINFO *);
bool FExportsChanged(EXPINFO *,bool);
bool FFriendAssembly();
bool FGenFileModified(unsigned short const *,unsigned short const *,TIME64 &);
bool FGotVal(ARP const *,unsigned int);
bool FGuardCommonPadSymbol(EXTERNAL *);
bool FHasCorMetaSection(int,unsigned long,_IMAGE_FILE_HEADER &);
bool FICFFolded(CON const *);
bool FICFGetNextBucket(Array<CON *> const &,unsigned long,unsigned long *);
bool FICFSameICFGrp(GRP const *,GRP const *);
bool FILImage(int,unsigned short const *,unsigned long,LinkerInputFileInfo *);
bool FIdenticalRelocs(IMAGE *,_IMAGE_RELOCATION *,_IMAGE_RELOCATION *);
bool FIgnoreWarning(unsigned int);
bool FIncrementalLinkSupported(IMAGE *);
bool FInvalidDelayLoadDll(IMAGE const *,unsigned short const *);
bool FIsANSIConvertible(unsigned short const *);
bool FIsASCIIString(unsigned short const *);
bool FIsConsole(_iobuf *);
bool FIsIncrPtr(void *);
bool FIsRemoteFile(FI *);
bool FIsRunningUnderIDE();
bool FIsSymbolName(DUMPSTATE const *,unsigned long,char const *);
bool FIslandMachine(unsigned long);
bool FLibNamesMatch(unsigned short const *,unsigned short const *);
bool FLoadingImport(int,_IMAGE_FILE_HEADER *,bool,unsigned short const *,char const *);
bool FLocateX64Linker(unsigned short *,unsigned int);
bool FLsnIbFromRva(DUMPSTATE const *,unsigned long,unsigned short *,unsigned long *);
bool FMachineHasPData(unsigned long);
bool FMachineHasXData(unsigned long);
bool FMapPfi(FI *,bool,unsigned long *);
bool FNextEnmBaseReloc(ENM_BASE_RELOC *,IMAGE *);
bool FNextEnmCon(ENM_CON *);
bool FNextEnmEdge(ENM_EDGE *);
bool FNextEnmExtList(ENM_EXT_LIST *);
bool FNextEnmGrp(ENM_GRP *);
bool FNextEnmLib(ENM_LIB *);
bool FNextEnmMod(ENM_MOD *);
bool FNextEnmModExt(ENM_MOD_EXT *);
bool FNextEnmNode(ENM_NODE *);
bool FNextEnmSec(ENM_SEC *);
bool FNextEnmSrc(ENM_SRC *);
bool FNextEnmUndefExt(ENM_UNDEF_EXT *);
bool FNum64FromSz(unsigned short const *,unsigned __int64 *);
bool FNumFromSz(unsigned short const *,unsigned long *);
bool FOrderLTCG();
bool FPOAddFpo(unsigned long,_FPO_DATA *,unsigned long);
bool FPOInit(unsigned long);
bool FPOUpdate(FPOI *);
bool FParseMajorMinorVersion(unsigned short const *,unsigned long &,unsigned long &,bool &);
bool FParseWin32Version(unsigned short const *,unsigned long &,bool &);
bool FPass1DefFile(IMAGE *,unsigned short const *);
bool FPerAppDomainPickAny(COMRefPtr<ICOFFSymRO> &,MOD *);
bool FPextRef(EXTERNAL *);
bool FPrescanSwitch(unsigned short const *,bool *);
bool FPrintSymbolName(DUMPSTATE const *,unsigned short const *,unsigned long);
bool FQueryHeapToMapExistingILK(void *,unsigned long);
bool FRefByModFilesOnly(EXTERNAL *,IMAGE *,unsigned long *);
bool FRelocationOverflow(CON *,IObjectContrib *);
bool FRemoveModule(IMAGE *,unsigned short const *);
bool FResFile(ARGUMENT_LIST *);
bool FResFile(int);
bool FReserveMemory(void *,unsigned int,unsigned long *);
bool FRvaInsideGrps(unsigned long,GRP *,GRP *);
bool FSameAlternateNames(IMAGE const *,IMAGE const *);
bool FSameDelayLoadDllsList(NAME_LIST const *);
bool FSameExport(EXTERNAL *,char const *,char const *,bool,EMODE,unsigned long,bool,bool);
bool FSetEntryPoint(IMAGE *);
bool FSubsetAlternateNames(IMAGE const *,IMAGE const *);
bool FTlsGrp(GRP *);
bool FUTF8(char const *);
bool FUnwindDataFileOffset(IMAGE *,int,unsigned long,unsigned long *);
bool FUseLinkerHandler(LinkerInputFileInfo *,unsigned short const *,unsigned long,unsigned long,bool *);
bool FUselessPCON(IMAGE *,CON *);
bool FUtf8ArgOnList(UTF8_NAME_LIST *,UTF8_ARGUMENT_LIST const *);
bool FValid32BitTarget(unsigned __int64);
bool FValidCorEntry(unsigned int);
bool FValidFileHdr(unsigned short const *,LinkerInputFileHeaderInfo const &);
bool FValidFileOffsetInfo(unsigned long,unsigned long);
bool FValidILKFile(unsigned short const *,bool,IMAGE *,_stat64i32 *,bool);
bool FValidPtrInfo(void *,unsigned long,void *,unsigned long);
bool FValidSecName(unsigned short const *);
bool FValidSubsystemVersion(unsigned short,_IMAGE_OPTIONAL_HEADER64 &,unsigned short,unsigned short,bool);
bool FVerifyDirectivesPMOD(IMAGE *,MOD *,NAME_LIST *);
bool FVerifyEXE(unsigned short const *,IMAGE *);
bool FWarningAsError(unsigned int);
bool FWeakPsymt(__MIDL___MIDL_itf_objint_0000_0000_0001);
bool FWithinSection(_IMAGE_SECTION_HEADER const &,unsigned long);
bool FX64SkipRelocation(CON *,unsigned short,bool);
bool FX86SkipRelocation(CON *,unsigned short,bool);
bool GenerateLTCGInfo(ICOFFObj *,Buffer &);
bool GetDecoratedNameFromTkInput(IMAGE *,unsigned int,unsigned short *,unsigned long,unsigned char const * *,unsigned long *,char *,unsigned long);
bool GetRunningProcessByName(unsigned short const *);
bool GetTempSectionReloc(IObjectContrib *,unsigned long *,_IMAGE_RELOCATION * *);
bool GetVCTelemetryClientDirPath(unsigned short *,unsigned long);
bool GetVCTipPath(unsigned short *,unsigned long);
bool GrowMapTable(FI *);
bool HasUserOptIn(unsigned short *);
bool InvMapTk(IMAGE *,unsigned int,unsigned int,unsigned int *,MOD * *);
bool IsArchiveFile(int);
bool IsDirtyPMOD(MOD *);
bool IsExpObj(unsigned short const *);
bool IsMPXArrayEndLabel(unsigned long,CON *,COMRefPtr<ICOFFSymRW>,unsigned char *);
bool IsMSILSymbol(char const *);
bool IsNDPAvailable(unsigned short const *);
bool IsPogoSupported();
bool IsSameDefn(IMAGE *,EXTERNAL *,unsigned long,LIB *);
bool IsT2MSymbol(char const *);
bool LinkCreateEvent(MOD *,void * &,bool);
bool LinkWaitForSingleObject(MOD *,void * &,bool,bool,bool);
bool LoadPchObject(MOD *,char *);
bool LoadVCTipConfigFile(_VCTIP_ConfigData *);
bool MatchVCTelemetryClientName(unsigned short *);
bool MergeIDL(Array<void *> &,Array<int> &,bool,unsigned short const *);
bool MoveToEndOfPMODsPCON(CON *);
bool NoRefsByCmdLineObjs(EXTERNAL *);
bool OpenDbgMod(DBGCONTEXT *,unsigned short const *,unsigned short const *,Mod * *);
bool ParseSymbolTable<_IMAGE_SYMBOL>(int,char const *,char const *,unsigned long);
bool ParseSymbolTable<_IMAGE_SYMBOL_EX>(int,char const *,char const *,unsigned long);
bool ProcessFileArg(ARGUMENT_LIST *,unsigned short,TIME64 &,unsigned long,unsigned long,unsigned short const *,bool,bool,bool *,bool *,bool *,IMAGE *,LIB *);
bool ReadStringTableMapped(int,long,unsigned long *,char * *,unsigned long);
bool RemoveExtFromDefList(MOD *,EXTERNAL *);
bool SetupWorkerThread(CTaskQueue * *,void * *,unsigned long *,unsigned short const *);
bool ShowWarning(DBGCONTEXT *,unsigned short const *,unsigned int,...);
bool TkFromSz(char const *,unsigned int &);
bool TkFromSzSymbol(char const *,MOD *,unsigned int *,unsigned long *);
bool ValidateFileMatching(ARGUMENT_LIST *,IMAGE *);
bool bv_readBit(void *,unsigned int);
bool bv_setAndReadBit(void *,unsigned int);
bool fDidInitRgci;
bool fDidMachineDependentInit;
bool fErr;
bool fExceptionsOff;
bool fINCR;
bool fImageMappedAsFile;
bool fIncrDBG;
bool fIncrDbFile;
bool fIncrSwitchUsed;
bool fIncrSwitchValue;
bool fMD5DefFilename;
bool fMultipleDefinitions;
bool fNoBaseRelocs;
bool fNoLogo;
bool fOpenedOutFilename;
bool fPdb;
bool fReproducible;
bool fSkipIncrChecks;
bool fStdOutConsole;
bool fTest;
bool fUnInitCOM;
bool fUnInitWarbird;
bool fWarningIsError;
bool fWbrdReportErrors;
bool fWbrdTestEncrypt;
bool g_fArm64SimulatorMode;
bool g_fArmHazardFree;
bool g_fArmSimulatorMode;
bool g_fClearLinkRepro;
bool g_fCvtResFoldDups;
bool g_fEarlyTypeMergeDone;
bool g_fEnableSqm;
bool g_fFastFail;
bool g_fForcePGORepro;
bool g_fForceWinMDVersion12;
bool g_fLBR;
bool g_fLTCG;
bool g_fLTCGStatus;
bool g_fLtcgForcedOff;
bool g_fLtcgIncremental;
bool g_fLtcgIncrementalRebuild;
bool g_fLtcgOutCommandLine;
bool g_fMPX;
bool g_fObjCoffInitialized;
bool g_fPGI;
bool g_fPGO;
bool g_fPGU;
bool g_fPdbDbgST;
bool g_fPdbInProc;
bool g_fPrependUnderscore;
bool g_fPrescanSwitches;
bool g_fReportNonComdatGuardFunc;
bool g_fRetryOnFileOpenFailure;
bool g_fRunBelow4GB;
bool g_fSEHEmpty;
bool g_fSawCIL;
bool g_fSawCORMeta;
bool g_fSawILImage;
bool g_fSawWinRTMeta;
bool g_fSkipUnderscore;
bool g_fStaticLibChanged;
bool g_fUpdateManifest;
bool g_fUseUnsafeThumbDelayThunk;
bool g_fVerbose;
bool g_fWarnZwObjInStaticLib;
calltype * ToolType;
char * * FuzzySearchVariants(IMAGE *,char const *,bool,int *);
char * Dbflags;
char * EntryPointName;
char * FuzzyLookupSz(unsigned short const *,char const *,IMAGE *,bool,bool,bool,bool);
char * ReadStringTable(int,unsigned short const *,long,unsigned long *);
char * ShortName;
char * Strdup(char const *);
char * StringTable;
char * SzDup(char const *);
char * SzDupWsz(unsigned short const *);
char * SzEntryConv(char const *,bool);
char * SzFromFo(int,unsigned long);
char * SzFromRva(DUMPSTATE const *,int,unsigned long);
char * SzHintName(bool,IMPORT_OBJECT_HEADER const *,int,_IMAGE_FILE_HEADER *,bool *,unsigned short *);
char * SzObjectFromSzDyn(char const *);
char * SzObjectFromSzEdge(char const *,bool);
char * SzT2M(char const *,char *,unsigned int);
char * SzTrimFile(char const *);
char * SzUndecorateNameOnly(char const *);
char * SzUtf8Dup(unsigned short const *);
char * strdup_TCE(char const *);
char const * SzCvName(char const *,unsigned int *);
char const * SzEntryConvToDot(char const *);
char const * SzObjSectionName(char const *,char const *);
char const * SzPrependThunk(bool,char const *);
char const * SzSym<_IMAGE_SYMBOL>(_IMAGE_SYMBOL const *,char const *,char * const);
char const * SzSym<_IMAGE_SYMBOL_EX>(_IMAGE_SYMBOL_EX const *,char const *,char * const);
char const * SzSymbol(CON *,COMRefPtr<ICOFFSymRW> const &);
char const * SzUMNFromMN(char const *,unsigned int);
char const * const g_szNullDelayDescriptor;
int (* gpfn_NameMapOpen)(PDB *,int,NameMap * *);
int (* gpfn_PDBExportValidateInterface)(unsigned long);
int (* gpfn_PDBOpen2W)(unsigned short const *,char const *,long *,unsigned short *,unsigned int,PDB * *);
int (* gpfn_PDBOpenEx2W)(unsigned short const *,char const *,long,long *,unsigned short *,unsigned int,PDB * *);
int (* gpfn_PDBOpenValidate5)(unsigned short const *,unsigned short const *,void *,int (*(*)(void *,POVC))(),long *,unsigned short *,unsigned int,PDB * *);
int (* gpfn_PDBRPC)();
int (* gpfn_in_proc_NameMapOpen)(PDB *,int,NameMap * *);
int (* gpfn_in_proc_PDBOpenValidate5)(unsigned short const *,unsigned short const *,void *,int (*(*)(void *,POVC))(),long *,unsigned short *,unsigned int,PDB * *);
int (* pfnLoadStringW)(HINSTANCE__ *,unsigned int,unsigned short *,int);
int (* pfnWow64DisableWow64FsRedirection)(void * *);
int (* pfnWow64RevertWow64FsRedirection)(void *);
int (*PfnDumpQueryCallback(void *,POVC))();
int (*__crt_fast_encode_pointer<int (*)(_RTL_CONDITION_VARIABLE *,_RTL_CRITICAL_SECTION *,unsigned long)>(int (*const)(_RTL_CONDITION_VARIABLE *,_RTL_CRITICAL_SECTION *,unsigned long)))(_RTL_CONDITION_VARIABLE *,_RTL_CRITICAL_SECTION *,unsigned long);
int BaseRelocAddrCompare(void const *,void const *);
int BaseRelocFindContainsRva(void const *,void const *);
int BufferedCloseHard(FI *);
int BufferedOpen(FI *,int,int,bool);
int CleanUp(IMAGE * *,unsigned long *);
int CmpPextDynValueReloc(void const *,void const *);
int Compare(void const *,void const *);
int CompareExternalAddr(void const *,void const *);
int CompareExternalModName(void const *,void const *);
int CompareExternalName(void const *,void const *);
int ComparePsecPsecName(void const *,void const *);
int ComparePsym(void const *,void const *);
int ComparePtrValues(void const *,void const *);
int CompareW(void const *,void const *);
int ControlCHandler(unsigned long);
int CreateLocalDirectory(unsigned short *);
int CvtCilArchive(IMAGE *,ARGUMENT_LIST *);
int CvtCilMain(int,unsigned short * * const);
int CvtCilObject(IMAGE *,ARGUMENT_LIST *);
int DefLibMain(IMAGE *);
int DelayLoadExceptionFilter(unsigned long,_EXCEPTION_POINTERS *,bool);
int DumperMain(int,unsigned short * * const);
int EditorMain(int,unsigned short * * const);
int FCalculateSHA256(unsigned char *,unsigned long,unsigned char * *,unsigned long *);
int FCompareName(unsigned short * *,void *);
int FRvaSourceCmp(void const *,void const *);
int FileClose(int,bool);
int FileIncrDbHandle;
int FileOpen(unsigned short const *,int,int,unsigned long);
int FileOpenMapped(unsigned short const *,int,int,void * *,unsigned int *,unsigned long *,bool);
int FileReadHandle;
int FuzzyCompare(void const *,void const *);
int FuzzyCompareInLib(void const *,void const *);
int HelperMain(int,unsigned short * * const);
int ICFCompareGrp(CON *,CON *);
int ICFCompareIcfGrp(void const *,void const *);
int ICFComparePcon(void const *,void const *);
int IncrBuildImage(IMAGE * *,unsigned long *);
int InfoClose();
int InfoPrintf(unsigned short const *,...);
int InfoPutc(unsigned short);
int InfoPuts(unsigned short const *);
int LibrarianMain(int,unsigned short * * const);
int LinkExceptionFilter(unsigned long,_EXCEPTION_POINTERS *,_EXCEPTION_RECORD *,_CONTEXT *,bool);
int LinkerMain(int,unsigned short * * const);
int MSTAT_CompareAddr(void const *,void const *);
int MappedCloseHard(FI *,bool);
int MappedOpen(FI *,long,bool,unsigned long *,unsigned long);
int MemCoordinator(unsigned int);
int PgoAllowSwitchCmp(void const *,void const *);
int RVACmp(void const *,void const *);
int SXDataGTCmpPcon(void const *,void const *);
int SXDataLTCmpRva(void const *,void const *);
int SpawnFullBuild(bool,unsigned short const *,bool,bool,bool,unsigned short const *);
int StdOutFlush();
int StdOutPrintf(unsigned short const *,...);
int StdOutPutc(unsigned short);
int StdOutPuts(unsigned short const *);
int StdOutVprintf(unsigned short const *,char *);
int TmdTypeFilter(void *,unsigned short const *);
int UpdateCoffTimeDateStamp(unsigned short const *,unsigned long *);
int VerifyPrintf(VerifyPrefix,unsigned short const *,...);
int cmpPcconstPcconst(void const *,void const *);
int cmpPcontribPcontrib(void const *,void const *);
int cmpPfixupPfixupRva(void const *,void const *);
int cmpPmodOffCompare(void const *,void const *);
int cmpPrvaPfixup(void const *,void const *);
int cmpifpo(void const *,void const *);
int comparePhase(void const *,void const *);
int link_fclose(_iobuf *);
int link_fwprintf(_iobuf *,unsigned short const *,...);
int link_vfwprintf(_iobuf *,unsigned short const *,char *);
int swprintf_s<512>(unsigned short (&)[512],unsigned short const *,...);
long (* DBG_QuerySizeFpo)();
long AttachMarshaling(IMetaDataEmit *,unsigned int,unsigned char const *,unsigned long);
long BufferedSeek(FI *,long,int);
long CorSigUncompressData(unsigned char const *,unsigned long,unsigned long *,unsigned long *);
long CreateMarshalAsMemberRef(IMetaDataEmit *,unsigned char const *,unsigned long);
long DbgQuerySizeFpo();
long DbgStQuerySizeFpo();
long ErrorReportingFilter(_EXCEPTION_POINTERS *);
long FileLength(int);
long FileSeekEx(int,long,int,unsigned long *);
long FileTell(int);
long GenerateDecoratedName(unsigned int,IMetaDataImport *,char *,unsigned long,GDNCallingConvention *,unsigned long,void *,unsigned int);
long GetAssemblyRefForMSCORLIB(IMetaDataEmit *,unsigned int *);
long GetAssemblyRefFromName(IMetaDataEmit *,unsigned int *,unsigned short const *);
long GetUserOptInValue(unsigned short const *,bool *);
long IsUserOptedIn(unsigned short const *,bool *,bool *);
long LThumbExtractOffsetForSSPAN12P8N_MEM(unsigned long);
long LThumbExtractOffsetForSSPAN9_MEM(unsigned long);
long LThumbExtractOffsetForSSPAN9_MEM64(unsigned long);
long MappedSeek(FI *,long,int,unsigned long *);
long ReadGroupPolicyOptInValue(bool *,bool *);
long StringCchCopyW(unsigned short *,unsigned int,unsigned short const *);
long StringCchPrintfW(unsigned short *,unsigned int,unsigned short const *,...);
long SzRefFuncToken(ST *,EXTERNAL *,MOD *,ILinkDataRO * *);
long WatsonExceptionFilter(_EXCEPTION_POINTERS *);
long WriteAuxSym<IMAGE_FILE>(IFileIO *,ICOFFAuxSym *,long,unsigned long,unsigned long);
long WriteCoffObj(IFileIO *,IObjFile2 *,ICOFFObj *,unsigned long,bool,unsigned long,SectionInfo *);
long WriteCoffSections(IFileIO *,long,long,ICOFFObj *,StringTableUnique *,unsigned long *,unsigned long *);
long WriteCoffSymbolTableT<IMAGE_FILE>(IFileIO *,long,ICOFFObj *,StringTableUnique *,unsigned long *,unsigned long *);
long WriteCoffSymbolTableT<IMAGE_FILE_EX>(IFileIO *,long,ICOFFObj *,StringTableUnique *,unsigned long *,unsigned long *);
long WriteExtraSection(IFileIO *,long,long,SectionInfo *,unsigned long *);
long WriteLineNumberAuxSym<IMAGE_FILE>(IFileIO *,ICOFFAuxSym *,long,unsigned long);
long WriteWeakAuxSym<IMAGE_FILE>(IFileIO *,ICOFFAuxSym *,long,unsigned long);
long WriteWeakAuxSym<IMAGE_FILE_EX>(IFileIO *,ICOFFAuxSym *,long,unsigned long);
long _CountBytesOfOneArg(unsigned char const *,unsigned long *);
long _GetFixedSigOfVarArg(unsigned char const *,unsigned long,CQuickBytes *,unsigned long *);
long const DosHeaderSize;
long link_ftell(_iobuf *);
tagPGDOBJECTRECORD * PPGDObjRecFromSz(unsigned short const *);
unsigned __int64 Arm64ExtractVirtualAddress(unsigned __int64,unsigned char *);
unsigned __int64 DwlArmEncodeMov32Immediate(unsigned __int64,unsigned long);
unsigned __int64 DwlThumbEncodeMov32Immediate(unsigned __int64,unsigned long);
unsigned __int64 VAAdjust(unsigned long,unsigned __int64);
unsigned char * Arm64LongBranchThunk;
unsigned char * PbMappedRegion(int,unsigned long,unsigned long);
unsigned char * rgbMD5DefFilename;
unsigned char DloadGetSRWLockFunctionPointers();
unsigned char GetLDRScale(unsigned long);
unsigned char OAStub;
unsigned char const * const DosHeaderArray;
unsigned int * g_mpisymtkExternal;
unsigned int AllocSizeAdd(unsigned int,unsigned int);
unsigned int CalcILKMapSize(unsigned int,unsigned int,unsigned int);
unsigned int CbDisassemble(DIS *,DIS *,unsigned int,unsigned __int64,unsigned char const *,unsigned int,bool,bool);
unsigned int CchAddr(DIS const *,unsigned __int64,unsigned short *,unsigned int,unsigned __int64 *);
unsigned int CchAddrCoff(DUMPSTATE const *,unsigned __int64,unsigned short *,unsigned int,unsigned __int64 *);
unsigned int CchAddrGsi(DUMPSTATE const *,unsigned __int64,unsigned short *,unsigned int,unsigned __int64 *);
unsigned int CchAddrGsi16(DUMPSTATE const *,unsigned __int64,unsigned short *,unsigned int,unsigned __int64 *);
unsigned int CchFixup(DIS const *,unsigned __int64,unsigned int,unsigned short *,unsigned int,unsigned __int64 *);
unsigned int CchFixupObject(DIS const *,unsigned __int64,unsigned int,unsigned short *,unsigned int,unsigned __int64 *);
unsigned int CchNoFixup32(DIS const *,unsigned __int64,unsigned int,unsigned short *,unsigned int,unsigned __int64 *);
unsigned int CchNoFixup64(DIS const *,unsigned __int64,unsigned int,unsigned short *,unsigned int,unsigned __int64 *);
unsigned int CchRegrel(DIS const *,DIS::REGA,unsigned long,unsigned short *,unsigned int,unsigned long *);
unsigned int CfixupArm64FromRgimgreloc(_IMAGE_RELOCATION const *,unsigned int);
unsigned int CfixupArm64FromRgxfixup(XFIXUP const *,unsigned int,unsigned long,unsigned long);
unsigned int CfixupArmFromRgimgreloc(_IMAGE_RELOCATION const *,unsigned int);
unsigned int CfixupArmFromRgxfixup(XFIXUP const *,unsigned int,unsigned long,unsigned long);
unsigned int CfixupMipsFromRgxfixup(XFIXUP const *,unsigned int,unsigned long,unsigned long);
unsigned int CfixupSh4FromRgxfixup(XFIXUP const *,unsigned int,unsigned long,unsigned long);
unsigned int CfixupX64FromRgimgreloc(_IMAGE_RELOCATION const *,unsigned int);
unsigned int CfixupX64FromRgxfixup(XFIXUP const *,unsigned int,unsigned long,unsigned long);
unsigned int CfixupX86FromRgimgreloc(_IMAGE_RELOCATION const *,unsigned int);
unsigned int CfixupX86FromRgxfixup(XFIXUP const *,unsigned int,unsigned long,unsigned long);
unsigned int ComDefineMethod(IMAGE *,unsigned short const *,unsigned char const *,unsigned long,unsigned long);
unsigned int CreateUnmanagedEntry(IMAGE *,char const *);
unsigned int FileWrite(int,void const *,unsigned int);
unsigned int IbAppendBlk(BLK *,void const *,unsigned int);
unsigned int IbAppendBlkZ(BLK *,unsigned int);
unsigned int IbAppendStr(BLK *,char const *,bool);
unsigned int IbAppendStr(BLK *,unsigned short const *,bool);
unsigned int TkEmitFromLinkerDefTk(unsigned int);
unsigned int TkEmitFromPTkMod(TKMOD const *);
unsigned int TkFromCoffSym<CON,ICOFFSymRO>(CON *,ICOFFSymRO *);
unsigned int TkFromCoffSym<CON,ICOFFSymRW>(CON *,ICOFFSymRW *);
unsigned int TkFromCoffSym<MOD,ICOFFSymRO>(MOD *,ICOFFSymRO *);
unsigned int TkFromCoffSym<MOD,ICOFFSymRW>(MOD *,ICOFFSymRW *);
unsigned int TkMSVC();
unsigned int TkMscorlib(bool);
unsigned int bitcount(unsigned int);
unsigned int cbRoundPageSize(unsigned int);
unsigned int const * const g_tkCorEncodeToken;
unsigned int cszEcPdb;
unsigned int g_GuardCompatLevel;
unsigned int g_cbExternal;
unsigned int g_tkEntry;
unsigned int g_uPdbQSize;
unsigned int link_fread(void *,unsigned int,unsigned int,_iobuf *);
unsigned int link_fwrite(void const *,unsigned int,unsigned int,_iobuf *);
unsigned int tszlen(unsigned short const *);
unsigned long ( IMAGE::* CbHdr)(unsigned long *);
unsigned long (* DBG_QueryAge)();
unsigned long (* gpfn_SigForPbCb)(unsigned char *,unsigned int,unsigned long);
unsigned long (* pfnCbAdjustForDynamicBase)(IMAGE *,unsigned long,unsigned long,_IMAGE_RELOCATION *,unsigned long);
unsigned long (* pfnDwAdjustSymValue)(CON *,unsigned long,bool);
unsigned long * PvAllocEx<unsigned long,0>(unsigned int);
unsigned long * g_rgMemberStart;
unsigned long * g_rgdwFuncinfo;
unsigned long AdditionalFlagsFromName(unsigned short const *);
unsigned long AppendLongName(StringTableBase *,char const *);
unsigned long BufferedRead(FI *,void *,unsigned long);
unsigned long BufferedWrite(FI *,void const *,unsigned long);
unsigned long BuildLinkerMember(IMAGE *,__int64,unsigned long);
unsigned long CArm64BaseRelocs(IMAGE *,CON *,COMRefPtr<ICOFFSymTabRO> &,unsigned long,_IMAGE_RELOCATION *,unsigned long,unsigned long,unsigned long &);
unsigned long CArmBaseRelocs(IMAGE *,CON *,COMRefPtr<ICOFFSymTabRO> &,unsigned long,_IMAGE_RELOCATION *,unsigned long,unsigned long,unsigned long &);
unsigned long CConOrderLTCG(unsigned long);
unsigned long CEbcBaseRelocs(IMAGE *,CON *,COMRefPtr<ICOFFSymTabRO> &,unsigned long,_IMAGE_RELOCATION *,unsigned long,unsigned long,unsigned long &);
unsigned long CIncludes(LEXT *);
unsigned long CX64BaseRelocs(IMAGE *,CON *,COMRefPtr<ICOFFSymTabRO> &,unsigned long,_IMAGE_RELOCATION *,unsigned long,unsigned long,unsigned long &);
unsigned long CbArm64AdjustForDynamicBase(IMAGE *,unsigned long,unsigned long,_IMAGE_RELOCATION *,unsigned long);
unsigned long CbArmAdjustForDynamicBase(IMAGE *,unsigned long,unsigned long,_IMAGE_RELOCATION *,unsigned long);
unsigned long CbArmOrArm64FuncSizeFromPdata(MOD *,COMRefPtr<ICOFFSymTabRO> &,unsigned long,unsigned long,bool);
unsigned long CbBranchThunk(unsigned long);
unsigned long CbMinBranchLim(unsigned long);
unsigned long CbStringTable(char const *,unsigned int,unsigned int,bool,bool,bool,unsigned long);
unsigned long CbX64AdjustForDynamicBase(IMAGE *,unsigned long,unsigned long,_IMAGE_RELOCATION *,unsigned long);
unsigned long CbX86AdjustForDynamicBase(IMAGE *,unsigned long,unsigned long,_IMAGE_RELOCATION *,unsigned long);
unsigned long CconOrderFile(ST *,IMAGE *,unsigned short const *,unsigned long,bool);
unsigned long ComPrintUndefinedTokens(IMAGE *);
unsigned long CorSigCompressData(unsigned long,void *);
unsigned long CorSigCompressToken(unsigned int,void *);
unsigned long CorSigUncompressBigData(unsigned char const * &);
unsigned long CorSigUncompressData(unsigned char const *,unsigned long *);
unsigned long CorSigUncompressSignedInt(unsigned char const *,int *);
unsigned long CorSigUncompressToken(unsigned char const *,unsigned int *);
unsigned long CountExternTable(ST *,unsigned long *,unsigned long *,unsigned long *);
unsigned long CountLongBranch(void *,unsigned long);
unsigned long CountUniqueTargets(IMAGE *,unsigned long,unsigned long,unsigned long *,unsigned long);
unsigned long CsymDelayCode(unsigned short,bool,bool,bool,bool,unsigned long);
unsigned long DbgQueryAge();
unsigned long DbgStQueryAge();
unsigned long DbgWorker(void *);
unsigned long DloadSectionCommitPermanent;
unsigned long DloadSectionLockCount;
unsigned long DloadSectionOldProtection;
unsigned long DloadSrwLock;
unsigned long DwArmAdjustSymValue(CON *,unsigned long,bool);
unsigned long DwArmExtractMov32Immediate(unsigned __int64);
unsigned long DwMarkConOrdered(CON *,unsigned long);
unsigned long DwThumbEncodeBLX23(long);
unsigned long DwThumbEncodeBranch20(long);
unsigned long DwThumbEncodeBranch24(long);
unsigned long DwThumbEncodeOffsetFor12P8N_MEM(unsigned long,__int64,bool &);
unsigned long DwThumbExtractMov32Immediate(unsigned __int64);
unsigned long EliminateLongBranch(IMAGE *,unsigned long,unsigned long);
unsigned long GetRegistryReadFlags();
unsigned long GetRelocRvaTarget(CON *,COMRefPtr<ICOFFSymTabRW> &,_IMAGE_RELOCATION *);
unsigned long IsODRIgnoreKeyword(unsigned short const *);
unsigned long LargestOrdinal;
unsigned long LayoutCode(IMAGE *,unsigned long,unsigned long,unsigned long *,unsigned long *);
unsigned long LookupLongName(StringTableUnique *,char const *);
unsigned long MappedRead(FI *,void *,unsigned long);
unsigned long MappedWrite(FI *,void const *,unsigned long);
unsigned long MemberSeekBase;
unsigned long MemberSize;
unsigned long RoundUpToNextPowerOf2(unsigned long,unsigned long);
unsigned long RvaAlign(unsigned long,unsigned long);
unsigned long RvaArm64Thunk(IMAGE *,unsigned long,unsigned long,CON *,bool,int,unsigned __int64,bool,unsigned short,unsigned long,bool,unsigned long);
unsigned long RvaArmThunk(IMAGE *,IMAGE::ThunkType,unsigned int,unsigned long,unsigned long,CON *,bool,int,unsigned __int64,bool,unsigned short,bool,unsigned long,bool,unsigned long);
unsigned long RvaMapToSrc(DUMPSTATE const *,unsigned long);
unsigned long SmallestOrdinal;
unsigned long UndefinedSymbols;
unsigned long UpdateBaseRelocs(IMAGE *);
unsigned long VerifyImageSize;
unsigned long cGlobalRgciCon;
unsigned long cdwLBrBVLen;
unsigned long cfixpag;
unsigned long cxfixupCur;
unsigned long fCtrlCSignal;
unsigned long g_cICFIterMax;
unsigned long g_cIntraFuncLBRs;
unsigned long g_cLtcgArgsMac;
unsigned long g_cLtcgArgsMax;
unsigned long g_cbExeMapView;
unsigned long g_cbILKMax;
unsigned long g_cbTextBss;
unsigned long g_cbitsShiftInitialFileSize;
unsigned long g_cntTmd;
unsigned long grfAlign(unsigned long);
unsigned long hProv;
unsigned short * (* gpfn_SzCanonFilename)(unsigned short *);
unsigned short * * argv_LTCG(IMAGE *,unsigned short const *);
unsigned short * * g_rgszLtcgArgs;
unsigned short * * savArgv;
unsigned short * CorGetErrorString(long,bool);
unsigned short * DeterminePDBFilename(IMAGE *,unsigned short const *,unsigned short const *);
unsigned short * ExpandMemberName(char const *,unsigned char *);
unsigned short * FormTokenFromDirective(unsigned short *,unsigned short const *,unsigned short const *,unsigned short *);
unsigned short * PvAllocEx<unsigned short,0>(unsigned int);
unsigned short * ReadDefinitionFile();
unsigned short * Strdup(unsigned short const *);
unsigned short * SzDup(unsigned short const *);
unsigned short * SzGenIncrDbFilename(IMAGE *);
unsigned short * SzGetArgument(unsigned short *,bool *);
unsigned short * SzMachineForCvt(unsigned long);
unsigned short * SzModifyFilename(unsigned short const *,unsigned short const *);
unsigned short * SzOutputSymbolName(char const *,bool);
unsigned short * SzRefFunc(ST *,EXTERNAL *,MOD *);
unsigned short * SzSearchLibEnv(unsigned short const *,unsigned short const *,bool *);
unsigned short * WszDupSz(char const *);
unsigned short * WszDupUtf8(char const *);
unsigned short * WszDupUtf8(char const *,Allocator &);
unsigned short * _find(unsigned short const *);
unsigned short * g_szAltBE;
unsigned short * g_szIncrCmdLine;
unsigned short * g_szPGD;
unsigned short * g_szSqmFilePath;
unsigned short * g_szWinMDVersion;
unsigned short * szCombinedFilenames;
unsigned short * szExportFilename;
unsigned short * szIncrDbFilename;
unsigned short * szPdbAltPath;
unsigned short * szPdbDll;
unsigned short * szPdbFilename;
unsigned short * szReproDir;
unsigned short * szWbrdCfgFilename;
unsigned short * szWbrdDllFilename;
unsigned short * szWbrdLogFilename;
unsigned short * szWbrdSchemaFilename;
unsigned short * szWbrdSummaryFilename;
unsigned short CsecDelayCode(bool,bool,bool,bool);
unsigned short DefaultRelocType(IMAGE *);
unsigned short EnsureCoffObject(IMAGE *,ARGUMENT_LIST *,unsigned long *,IObjFile2 * *,MOD *,bool *);
unsigned short GetRelocationTypeSize(unsigned short,unsigned short);
unsigned short IsDefinitionKeyword(unsigned short const *);
unsigned short IsSectionKeyword(unsigned short const *);
unsigned short ParseAnExport(IMAGE *,unsigned short *);
unsigned short ParseDefExports(IMAGE *);
unsigned short ParseDefNameOrLibrary(IMAGE *,bool);
unsigned short ParseDefSections(unsigned short const *);
unsigned short ParseSizes(unsigned short const *,unsigned short const *);
unsigned short RvaRelocType(IMAGE *);
unsigned short SkipToNextKeyword();
unsigned short WExtraFromPext(EXTERNAL *);
unsigned short WExtraFromScType(unsigned char,unsigned short);
unsigned short const * DbgGetPDBErrorMsg(long);
unsigned short const * GetErrorFormatString(unsigned int);
unsigned short const * SzArm64RelocationType(unsigned short,unsigned short *,bool *);
unsigned short const * SzArmRelocationType(unsigned short,unsigned short *,bool *);
unsigned short const * SzBE();
unsigned short const * SzClass(_IMAGE_SYMBOL_EX *);
unsigned short const * SzClrImageType(CLRIMAGE_TYPE);
unsigned short const * SzClrImageTypeSwitch(CLRIMAGE_TYPE);
unsigned short const * SzCoffMachine(unsigned short);
unsigned short const * SzEbcRelocationType(unsigned short,unsigned short *,bool *);
unsigned short const * SzErrorFromEc(PDBErrors,unsigned short *,unsigned int);
unsigned short const * SzMachine(unsigned long);
unsigned short const * SzMapAssemblyModule(unsigned short const *);
unsigned short const * SzMapSourceFilename(unsigned short const *,unsigned short *,unsigned int);
unsigned short const * SzMipsRelocationType(unsigned short,unsigned short *,bool *);
unsigned short const * SzSh4RelocationType(unsigned short,unsigned short *,bool *);
unsigned short const * SzSubsystemOption(unsigned short);
unsigned short const * SzX64RelocationType(unsigned short,unsigned short *,bool *);
unsigned short const * SzX86RelocationType(unsigned short,unsigned short *,bool *);
unsigned short const * const DefFilename;
unsigned short const * const Delimiters;
unsigned short const * const ImplibFilename;
unsigned short const * const OutFilename;
unsigned short const * const ToolName;
unsigned short const * const g_szFileEdata;
unsigned short const * const g_szIPDBFilename;
unsigned short const * const g_szLTCGMetaOutSuffix;
unsigned short const * const g_szLTCGOutFilename;
unsigned short const * const g_szManifestResConvertedObj;
unsigned short const * const g_szOdrIgnoreFilename;
unsigned short const * const szInfoFilename;
unsigned short const * const szPhase;
unsigned short const * const szWinMDFilename;
unsigned short wMachineFromSz(unsigned short const *);
void ( IMAGE::* WriteHeader)(int);
void ( IMAGE::* WriteSecHeader)(int,SEC *,_IMAGE_SECTION_HEADER *);
void (* ApplyFixups)(CON *,_IMAGE_RELOCATION *,unsigned long,unsigned char *,COMRefPtr<ICOFFSymTabRW> &,IMAGE *,unsigned long,unsigned long const *);
void (* DBG_AddLinesMod)(unsigned short const *,MOD *,unsigned short,unsigned long,unsigned long,unsigned long,unsigned long,void *,unsigned long);
void (* DBG_AddLinkInfo)(IMAGE *);
void (* DBG_AddPublicDBI)(char const *,bool,unsigned short,unsigned long);
void (* DBG_AddSecContrib2Mod)(CON *,MOD *,unsigned long);
void (* DBG_AddSecContribMod)(CON *,MOD *);
void (* DBG_AddSecDBI)(unsigned short,unsigned short,unsigned long,unsigned long);
void (* DBG_AddSymbols2Mod)(void *,unsigned long,MOD *,unsigned long);
void (* DBG_AddSymbolsMod)(void *,unsigned long,MOD *);
void (* DBG_AddThunkMapDBI)(unsigned long *,unsigned long,unsigned long,unsigned short,unsigned long,SO *,unsigned short);
void (* DBG_AddTypesMod)(MOD *,void const *,unsigned long);
void (* DBG_AppendFpo)(unsigned long,_FPO_DATA const *);
void (* DBG_AppendPdata)(unsigned long,unsigned char const *);
void (* DBG_AppendSectionHdr)(unsigned long,_IMAGE_SECTION_HEADER const *);
void (* DBG_AppendXFixup)(unsigned long,XFIXUP const *);
void (* DBG_AppendXdata)(unsigned long,unsigned char const *);
void (* DBG_ClearFpo)();
void (* DBG_ClearOmap)(bool);
void (* DBG_ClearPdata)();
void (* DBG_ClearSectionHdr)();
void (* DBG_ClearXFixup)();
void (* DBG_ClearXdata)();
void (* DBG_CloseCachedMod)(LIB *);
void (* DBG_CloseDBI)();
void (* DBG_CloseFpo)();
void (* DBG_CloseMod)(MOD *);
void (* DBG_CloseOmap)(bool);
void (* DBG_ClosePDB)(unsigned short const *);
void (* DBG_ClosePdata)();
void (* DBG_CloseSectionHdr)();
void (* DBG_CloseXFixup)();
void (* DBG_CloseXdata)();
void (* DBG_CommitPDB)();
void (* DBG_CopySrc)();
void (* DBG_DeleteOmap)();
void (* DBG_EndTypeMergingMod)(MOD *);
void (* DBG_InjectNatvis)();
void (* DBG_MergeTypesMod)(unsigned char *,unsigned long,MOD *);
void (* DBG_NoteDiscardedRVAs)();
void (* DBG_OpenDBI)(IMAGE *,bool);
void (* DBG_OpenFpo)();
void (* DBG_OpenMod)(MOD *,IMAGE *);
void (* DBG_OpenOmap)(bool);
void (* DBG_OpenPDB)(IMAGE *,unsigned short const *);
void (* DBG_OpenPdata)();
void (* DBG_OpenSectionHdr)();
void (* DBG_OpenXFixup)();
void (* DBG_OpenXdata)();
void (* DBG_QueryNextFpo)(unsigned long,_FPO_DATA *);
void (* DBG_RegisterPDBMapping)();
void (* DBG_RemoveGlobalRefsMod)(MOD *);
void (* DBG_RemovePublicDBI)(char const *);
void (* DBG_ResetPDBGuid)(unsigned char *,unsigned long,_GUID *,unsigned long *);
void (* DBG_SetLazyTypes)();
void (* DBG_SetMachineType)(unsigned short);
void (* DloadAcquireSRWLockExclusive)(unsigned long *);
void (* DloadReleaseSRWLockExclusive)(unsigned long *);
void (* pfnValidateDirectives)(IMAGE *);
void (*__crt_fast_encode_pointer<void (*)(_RTL_CONDITION_VARIABLE *)>(void (*const)(_RTL_CONDITION_VARIABLE *)))(_RTL_CONDITION_VARIABLE *);
void * AllocHeap_HT(HT *,LHEAPV * *,unsigned long,unsigned long);
void * Calloc(unsigned int,unsigned int);
void * CreateHeap(void *,unsigned long,bool,unsigned long *);
void * DloadObtainSection(unsigned long *,unsigned long *);
void * LinkHeapAlloc(void *,unsigned long,unsigned int);
void * LinkHeapReAlloc(void *,unsigned long,void *,unsigned int);
void * LinkVirtualAlloc(void *,unsigned int,unsigned long,unsigned long);
void * Malloc(unsigned int);
void * PvAllocEx<0>(unsigned int);
void * PvAllocVirtHeap(LHEAPV * *,unsigned int);
void * PvAllocVirtual(void *,unsigned int,unsigned long,unsigned long);
void * PvRealloc(void *,unsigned int);
void * PvSearchForILKMap();
void * bvBr11Target;
void * bvBr24Target;
void * bvFuncinfo;
void * bvLBrTarget;
void * bvSafeSEH;
void * bvThumbBr23Target;
void * bvThumbBr24Target;
void * operator new(unsigned int,LIFETIME);
void * operator new[](unsigned int);
void AVLBalance(Array<LSL * *> &);
void AVLRotateLeft(LSL * *);
void AVLRotateRight(LSL * *);
void AddAlternateName(IMAGE *,char const *,char const *,bool);
void AddArgToListOnHeap(NAME_LIST *,ARGUMENT_LIST const *);
void AddArgumentToList(MOD *,NAME_LIST *,unsigned short const *,unsigned short const *,bool);
void AddAssemblyLinkResource(unsigned short const *,unsigned short const *,bool);
void AddAssemblyModule(unsigned short const *);
void AddAssemblyModuleMap(unsigned short const *,unsigned short const *);
void AddAssemblyResource(unsigned short const *,unsigned short const *,bool);
void AddCILDeferredPCON(CON *,unsigned __int64);
void AddCompilerArg(unsigned short *);
void AddEntryISYMForPext(EXTERNAL *);
void AddExportToSymbolTable(unsigned short const *,unsigned short const *,bool,EMODE,unsigned long,unsigned short const *,bool,IMAGE *,bool);
void AddExtToList(LPEXT *,bool,EXTERNAL *);
void AddExtToModRefList(MOD *,EXTERNAL *);
void AddExtToMultDefList(EXTERNAL *);
void AddFileArgs(IMAGE *);
void AddOrdinal(unsigned long);
void AddPconMapping(CON *,CON *);
void AddPogoFileInfo(IMAGE *);
void AddPogoLinkInfo(IMAGE *);
void AddPublicMod(IMAGE *,EXTERNAL *);
void AddReferenceExt(EXTERNAL *,MOD *);
void AddSafeSEH(CON *,unsigned long,unsigned short);
void AddSecContribPCON(IMAGE *,CON *);
void AddSectionsToDBI(IMAGE *);
void AddSupportLastErrorDll(unsigned short const *);
void AddToModList(LMOD * *,MOD *);
void AddUtf8ArgToListOnHeap(UTF8_NAME_LIST *,UTF8_ARGUMENT_LIST const *);
void AddUtf8Argument(MOD *,UTF8_NAME_LIST *,unsigned short const *);
void AddUtf8ArgumentToList(MOD *,UTF8_NAME_LIST *,unsigned short const *,char const *);
void AddWeakExtToList(IMAGE *,MOD *,EXTERNAL *,EXTERNAL *);
void AllocBlk(BLK *,unsigned int);
void AllocSpaceForImportPCON(IMAGE *,CON *);
void AllocateCommonPEXT(IMAGE *,EXTERNAL *,unsigned long &);
void AllocateCommonPMOD(IMAGE *,MOD *);
void AppendArg(unsigned short const *);
void AppendList(NAME_LIST &,NAME_LIST *);
void AppendOp(CTaskQueue *,DBGOP *,bool,bool);
void AppendPogoLinkInfo(unsigned short const *);
void AppendPsec(SEC *,SEC *);
void AppendSimpleOp(CTaskQueue *,DbgOpType);
void ApplyArm64Fixups(CON *,_IMAGE_RELOCATION *,unsigned long,unsigned char *,COMRefPtr<ICOFFSymTabRW> &,IMAGE *,unsigned long,unsigned long const *);
void ApplyArmFixups(CON *,_IMAGE_RELOCATION *,unsigned long,unsigned char *,COMRefPtr<ICOFFSymTabRW> &,IMAGE *,unsigned long,unsigned long const *);
void ApplyCommandLineSectionAttributes(IMAGE *,SEC *,bool *);
void ApplyDirectives(IMAGE *,MOD *,unsigned short *);
void ApplyEbcFixups(CON *,_IMAGE_RELOCATION *,unsigned long,unsigned char *,COMRefPtr<ICOFFSymTabRW> &,IMAGE *,unsigned long,unsigned long const *);
void ApplyX64Fixups(CON *,_IMAGE_RELOCATION *,unsigned long,unsigned char *,COMRefPtr<ICOFFSymTabRW> &,IMAGE *,unsigned long,unsigned long const *);
void ApplyX86Fixups(CON *,_IMAGE_RELOCATION *,unsigned long,unsigned char *,COMRefPtr<ICOFFSymTabRW> &,IMAGE *,unsigned long,unsigned long const *);
void Arm64BuildRgfixupFromRgimgreloc(_IMAGE_RELOCATION const *,unsigned int,unsigned char const *,FIXUP *);
void Arm64BuildRgfixupFromRgxfixup(unsigned __int64,unsigned __int64,XFIXUP const *,unsigned int,unsigned long,unsigned long,unsigned char const *,FIXUP *);
void Arm64EmitOneLBR(IMAGE *,LONG_BRANCH_REGION *);
void Arm64EmitThunks(IMAGE *);
void Arm64EncodeVirtualAddress(unsigned char *,unsigned __int64,unsigned __int64);
void Arm64LinkerInit(IMAGE *,bool *);
void Arm64ValidateDirectives(IMAGE *);
void ArmBuildRgfixupFromRgimgreloc(_IMAGE_RELOCATION const *,unsigned int,unsigned char const *,FIXUP *);
void ArmBuildRgfixupFromRgxfixup(unsigned __int64,unsigned __int64,XFIXUP const *,unsigned int,unsigned long,unsigned long,unsigned char const *,FIXUP *);
void ArmEmitLBRThunk(IMAGE *,unsigned long,IMAGE::ThunkType);
void ArmEmitLBRThunks(IMAGE *);
void ArmEmitOneLBR(IMAGE *,LONG_BRANCH_REGION *);
void ArmLinkerInit(IMAGE *,bool *);
void ArmValidateDirectives(IMAGE *);
void AssignThunk2ManagedSymbol(ST *,EXTERNAL *,EXTERNAL *,bool);
void AssignWeakDefinition(EXTERNAL *,EXTERNAL *,ST *);
void AssignWeakExternals(IMAGE *);
void BadExitCleanup();
void BufferedIOInit();
void BuildArgList(MOD *,NAME_LIST *,unsigned short *,UniqUTF16StringTable *);
void BuildCconst(DUMPSTATE *,unsigned short,ISet *,CCONST * *,unsigned int *);
void BuildDumpSymbolTable(DUMPSTATE *,int,unsigned __int64);
void BuildExternalSymbolTable(IMAGE *,bool *,MOD *,unsigned short);
void BuildLibrary(IMAGE *,bool);
void BuildPublicSymbolTable(IMAGE *,bool *,MOD *,unsigned short);
void BuildSectionHeader(SEC *,_IMAGE_SECTION_HEADER *);
void BuildSectionHeader(_IMAGE_SECTION_HEADER *,unsigned long *,char const *,unsigned long,unsigned short,unsigned long);
void BuildTokenMap(IMAGE *);
void CalcDelayLoadSymbols(unsigned char *,unsigned char *,unsigned long *,char const *,char const *,unsigned int,char const *,_IMAGE_SECTION_HEADER *,bool,bool,bool,bool,unsigned long);
void CalcPtrsPMOD(MOD *,MOD *,IMAGE *);
void CheckChangedSafeSeh(IMAGE *);
void CheckDupFilename(unsigned short const *,ARGUMENT_LIST *);
void CheckEnCSettings(IMAGE *,unsigned short const *,bool);
void CheckErrNo();
void CheckForMultDefns(IMAGE *,LPEXT *);
void CheckForReproDir();
void CheckIfMovedDataRefByModFiles(IMAGE *,unsigned long *);
void CheckIncompatibleEdits(unsigned short const *);
void CheckInvalidDelayLoadDlls(IMAGE *);
void CheckManagedDllEntry(IMAGE *);
void CheckModMSIL(IMAGE *,MOD *);
void CheckModMSILType(IMAGE *,MOD *,CLRIMAGE_TYPE);
void CheckModSEH(IMAGE *,MOD *);
void CheckPogoCommandLine(LinkInfoW *);
void CheckSwitchesForIncrementalLink(IMAGE *);
void Cleanup_TCE(IMAGE *,bool);
void CloseHeap();
void CloseReproDir();
void CollectIDL(IMAGE *);
void CollectLocalDbgSyms(DUMPSTATE *,unsigned short,Map<unsigned __int64,char *,LHashClass2<unsigned __int64,8,3> > *);
void CollectLongBranch(IMAGE *,unsigned long,unsigned long);
void CollectLongBranchRecord(CON *,unsigned char,_IMAGE_RELOCATION *,int,char const *,unsigned long,unsigned long,unsigned long);
void CollectWeakAndLazyExterns(MOD *,IMAGE *);
void ColorPCON(IMAGE *,CON *);
void ColorPTKMOD(IMAGE *,TKMOD *);
void ColorPublicPext(IMAGE *,EXTERNAL *);
void ComBuildAssembly(IMAGE *);
void ComCheckMergeErrors(IMAGE *);
void ComCloseAssembly(bool);
void ComInitTCE(IMAGE *);
void ComMetaMergeEnd(IMAGE *);
void ComMetaUpdate(MOD *,unsigned int,unsigned long);
void ComMetaUpdateFromSymbol(IMAGE *,ICOFFSymRW *,MOD *,unsigned long,bool);
void CompressSecMap(SO *,unsigned short,unsigned short);
void ConvertImgSymToImgSymEx(_IMAGE_SYMBOL *,_IMAGE_SYMBOL_EX *);
void ConvertOHdr32To64(unsigned long &,_IMAGE_OPTIONAL_HEADER *,_IMAGE_OPTIONAL_HEADER64 *);
void ConvertOHdr64To32(unsigned long,_IMAGE_OPTIONAL_HEADER64 *,_IMAGE_OPTIONAL_HEADER *);
void ConvertResFile(IMAGE *,ARGUMENT_LIST *,unsigned short const * *);
void ConvertRgImgSymToRgImgSymEx(_IMAGE_SYMBOL *,unsigned long,_IMAGE_SYMBOL_EX *);
void CopyFileToReproDir(unsigned short const *,unsigned short const *,unsigned short const *,unsigned short const *,bool);
void CorError(MOD *,unsigned int,long);
void CorFatal(MOD *,unsigned int,long,bool);
void CorWarning(MOD *,unsigned int,long);
void CountFixupError(IMAGE *);
void CrcEdges(IMAGE *,CON *);
void CreateCORPcons(IMAGE *);
void CreateDelaySectionHeaders(unsigned long,bool,_IMAGE_SECTION_HEADER *,unsigned char *,unsigned long *,unsigned long,char const *,char const *,bool,bool,bool,unsigned long,unsigned long,bool,unsigned long,unsigned long);
void CreateDirective(unsigned short const *);
void CreateGraph_TCE(IMAGE *);
void CreateMember(IMAGE *,LIB *,_IMAGE_FILE_HEADER &,IMPORT_OBJECT_HEADER &,int,bool,bool,char const *,unsigned short const *,_IMAGE_SECTION_HEADER *,unsigned char *,ImportData *,CImplib * *,bool *,bool,_IMAGE_ARCHIVE_MEMBER_HEADER *);
void CvtCilUsage();
void DBG_AddObjAndCompileRecord(IMAGE *,char const *,bool,MOD *);
void DBG_CloseModError(MOD *);
void DBG_EarlyTypeMergeDone();
void DBG_NetModuleReadSrcInfo(unsigned short const *);
void DBG_StripPDB(unsigned short const *,unsigned short const *);
void DBG_SwitchToST();
void DbgAddLinesMod(unsigned short const *,MOD *,unsigned short,unsigned long,unsigned long,unsigned long,unsigned long,void *,unsigned long);
void DbgAddLinkInfo(IMAGE *);
void DbgAddPublicDBI(char const *,bool,unsigned short,unsigned long);
void DbgAddSecContrib2Mod(CON *,MOD *,unsigned long);
void DbgAddSecContribMod(CON *,MOD *);
void DbgAddSecDBI(unsigned short,unsigned short,unsigned long,unsigned long);
void DbgAddSymbols2Mod(void *,unsigned long,MOD *,unsigned long);
void DbgAddSymbolsMod(void *,unsigned long,MOD *);
void DbgAddThunkMapDBI(unsigned long *,unsigned long,unsigned long,unsigned short,unsigned long,SO *,unsigned short);
void DbgAddTypesMod(MOD *,void const *,unsigned long);
void DbgAppendFpo(unsigned long,_FPO_DATA const *);
void DbgAppendPdata(unsigned long,unsigned char const *);
void DbgAppendSectionHdr(unsigned long,_IMAGE_SECTION_HEADER const *);
void DbgAppendXFixup(unsigned long,XFIXUP const *);
void DbgAppendXdata(unsigned long,unsigned char const *);
void DbgClearFpo();
void DbgClearOmap(bool);
void DbgClearPdata();
void DbgClearSectionHdr();
void DbgClearXFixup();
void DbgClearXdata();
void DbgCloseCachedMod(LIB *);
void DbgCloseDBI();
void DbgCloseFpo();
void DbgCloseMod(MOD *);
void DbgCloseOmap(bool);
void DbgClosePDB(unsigned short const *);
void DbgClosePdata();
void DbgCloseSectionHdr();
void DbgCloseXFixup();
void DbgCloseXdata();
void DbgCommitPDB();
void DbgCopySrc();
void DbgDeleteOmap();
void DbgEndTypeMergingMod(MOD *);
void DbgInjectNatvis();
void DbgMergeTypesMod(unsigned char *,unsigned long,MOD *);
void DbgNoteDiscardedRVAs();
void DbgOpenDBI(IMAGE *,bool);
void DbgOpenFpo();
void DbgOpenMod(MOD *,IMAGE *);
void DbgOpenOmap(bool);
void DbgOpenPDB(IMAGE *,unsigned short const *);
void DbgOpenPdata();
void DbgOpenSectionHdr();
void DbgOpenXFixup();
void DbgOpenXdata();
void DbgQueryNextFpo(unsigned long,_FPO_DATA *);
void DbgRegisterPDBMapping();
void DbgRemoveGlobalRefsMod(MOD *);
void DbgRemovePublicDBI(char const *);
void DbgResetPDBGuid(unsigned char *,unsigned long,_GUID *,unsigned long *);
void DbgSetLazyTypes();
void DbgSetMachineType(unsigned short);
void DbgStAddLinesMod(unsigned short const *,MOD *,unsigned short,unsigned long,unsigned long,unsigned long,unsigned long,void *,unsigned long);
void DbgStAddLinkInfo(IMAGE *);
void DbgStAddPublicDBI(char const *,bool,unsigned short,unsigned long);
void DbgStAddSecContrib2Mod(CON *,MOD *,unsigned long);
void DbgStAddSecContribMod(CON *,MOD *);
void DbgStAddSecDBI(unsigned short,unsigned short,unsigned long,unsigned long);
void DbgStAddSymbols2Mod(void *,unsigned long,MOD *,unsigned long);
void DbgStAddSymbolsMod(void *,unsigned long,MOD *);
void DbgStAddSymbolsModHelper(void *,unsigned long,MOD *,unsigned long);
void DbgStAddThunkMapDBI(unsigned long *,unsigned long,unsigned long,unsigned short,unsigned long,SO *,unsigned short);
void DbgStAddTypesMod(MOD *,void const *,unsigned long);
void DbgStAppendFpo(unsigned long,_FPO_DATA const *);
void DbgStAppendPdata(unsigned long,unsigned char const *);
void DbgStAppendSectionHdr(unsigned long,_IMAGE_SECTION_HEADER const *);
void DbgStAppendXFixup(unsigned long,XFIXUP const *);
void DbgStAppendXdata(unsigned long,unsigned char const *);
void DbgStClearFpo();
void DbgStClearOmap(bool);
void DbgStClearPdata();
void DbgStClearSectionHdr();
void DbgStClearXFixup();
void DbgStClearXdata();
void DbgStCloseCachedMod(LIB *);
void DbgStCloseDBI();
void DbgStCloseFpo();
void DbgStCloseMod(MOD *);
void DbgStCloseOmap(bool);
void DbgStClosePDB(unsigned short const *);
void DbgStClosePdata();
void DbgStCloseSectionHdr();
void DbgStCloseXFixup();
void DbgStCloseXdata();
void DbgStCommitPDB();
void DbgStCopySrc();
void DbgStCreateDBI(IMAGE *);
void DbgStDeleteOmap();
void DbgStEndTypeMergingMod(MOD *);
void DbgStInjectNatvis();
void DbgStMergeTypesMod(unsigned char *,unsigned long,MOD *);
void DbgStNoteDiscardedRVAs();
void DbgStOpenDBI(IMAGE *,bool);
void DbgStOpenFpo();
void DbgStOpenMod(MOD *,IMAGE *);
void DbgStOpenOmap(bool);
void DbgStOpenPDB(IMAGE *,unsigned short const *);
void DbgStOpenPdata();
void DbgStOpenSectionHdr();
void DbgStOpenXFixup();
void DbgStOpenXdata();
void DbgStQueryNextFpo(unsigned long,_FPO_DATA *);
void DbgStRegisterPDBMapping();
void DbgStRemoveGlobalRefsMod(MOD *);
void DbgStRemovePublicDBI(char const *);
void DbgStResetPDBGuid(unsigned char *,unsigned long,_GUID *,unsigned long *);
void DbgStSetLazyTypes();
void DbgStSetMachineType(unsigned short);
void DeactivateTaskQueues();
void DefineCtorCustomAttribute(unsigned int,unsigned int,unsigned short const *,unsigned char const *,unsigned long,unsigned char const *,unsigned long);
void DefineImplicitDllImport(IMAGE *,EXTERNAL *,char const *,char const *,bool);
void DefineSEHSymbols(IMAGE *);
void DelExtFromList(LPEXT *,EXTERNAL *);
void DelayLoad(unsigned short const *);
void DeleteBaseRelocs(IMAGE *,unsigned long,unsigned long);
void DetachMiscFromHeap(IMAGE *);
void DeterminePGDFilename();
void DetermineTimeStamps(IMAGE *);
void DisableIncrementalLink(IMAGE *);
void DisableWarning(unsigned int);
void DiscardPCONsLibGroup(LIB *,SEC *,char const *,unsigned short const *);
void DisplayDiscardedPcon(CON *,NODE *);
void DisplayFatal(unsigned short const *,unsigned int,MSGTYPE,bool,unsigned int,char *);
void DisplayMessage(unsigned short const *,unsigned int,MSGTYPE,unsigned int,char *);
void DisplayWarning(unsigned short const *,unsigned int,unsigned int,char *);
void DloadAcquireSectionWriteAccess();
void DloadLock();
void DloadMakePermanentImageCommit(void *,unsigned long);
void DloadProtectSection(unsigned long,unsigned long *);
void DloadReleaseSectionWriteAccess();
void DloadUnlock();
void DoCodeGen(IMAGE *);
void DoMachineDependentInit(IMAGE *);
void DoPass2PMOD(IMAGE *,MOD *,bool);
void DumpArchive(unsigned short const *);
void DumpArchiveExports();
void DumpArchiveMembers(LIB *,unsigned short const *);
void DumpAuxSymbolTableEntry(DUMPSTATE const *,_IMAGE_SYMBOL_EX *,unsigned short,_IMAGE_AUX_SYMBOL_EX *,_IMAGE_SYMBOL_EX *);
void DumpBaseRelocations(DUMPSTATE const *,_IMAGE_BASE_RELOCATION *,unsigned short *,unsigned char const *);
void DumpCOFFObject(LinkerInputFileHeaderInfo const &,bool,unsigned short const *);
void DumpCoffSymbols(DUMPSTATE const *);
void DumpComHeader(DUMPSTATE const *,_IMAGE_SECTION_HEADER *);
void DumpComdatSelection(_IMAGE_AUX_SYMBOL_N *,_IMAGE_SYMBOL_EX *);
void DumpDbgFunctionTable(int,DFT,DUMPSTATE const *,unsigned long,unsigned long);
void DumpDebugData(DUMPSTATE const *,_IMAGE_SECTION_HEADER *,unsigned long);
void DumpDebugDirectories(DUMPSTATE const *,_IMAGE_SECTION_HEADER *);
void DumpDebugDirectory(_IMAGE_DEBUG_DIRECTORY *);
void DumpDebugFile(unsigned short const *);
void DumpDelayLoadDependencies(DUMPSTATE const *,_IMAGE_SECTION_HEADER *);
void DumpDelayLoadImports(DUMPSTATE const *,_IMAGE_SECTION_HEADER *);
void DumpDependencies(DUMPSTATE const *,_IMAGE_SECTION_HEADER *);
void DumpDirectives(unsigned long,unsigned long);
void DumpException(_EXCEPTION_RECORD const *,_CONTEXT const *);
void DumpExports(DUMPSTATE const *,_IMAGE_SECTION_HEADER *);
void DumpFile(unsigned short const *);
void DumpFileType(bool);
void DumpFixup(DUMPSTATE const *,unsigned long,unsigned long,unsigned long);
void DumpFpoData(DUMPSTATE const *,unsigned long,unsigned long,unsigned long);
void DumpFunctionTable(int,DUMPSTATE const *,IMAGE *);
void DumpGuardFlags(unsigned long);
void DumpHeaders(DUMPSTATE *);
void DumpHintWord(DUMPSTATE const *,unsigned long);
void DumpImportObject(int,IMPORT_OBJECT_HEADER const &);
void DumpImports(DUMPSTATE const *,_IMAGE_SECTION_HEADER *);
void DumpLinenumbers(DUMPSTATE const *,unsigned long,short,_IMAGE_SECTION_HEADER *);
void DumpLoadConfig(DUMPSTATE const *,_IMAGE_SECTION_HEADER *);
void DumpMemberHeader(LIB *,_IMAGE_ARCHIVE_MEMBER_HEADER,unsigned long);
void DumpNamePsym(unsigned short const *,_IMAGE_SYMBOL_EX *);
void DumpNotifyDebugDir(void *,int,_IMAGE_DEBUG_DIRECTORY const *);
void DumpNotifyOpenDBG(void *,unsigned short const *,PDBErrors,unsigned short const *);
void DumpNotifyOpenPDB(void *,unsigned short const *,PDBErrors,unsigned short const *);
void DumpObjFunctionTable(int,unsigned short,_IMAGE_SECTION_HEADER *,short);
void DumpObjectFile(bool,unsigned short const *);
void DumpOmap(DUMPSTATE const *,unsigned long,unsigned long,bool,unsigned long);
void DumpPeFile(unsigned short const *);
void DumpRawData(DUMPSTATE *,unsigned __int64,unsigned char const *,unsigned long);
void DumpRelocations(DUMPSTATE const *,_IMAGE_SECTION_HEADER *,unsigned long,unsigned char const *,unsigned long,RCT,int);
void DumpSecContribMap(DUMPSTATE const *);
void DumpSectionHeader(DUMPSTATE const *,int,_IMAGE_SECTION_HEADER *);
void DumpSections(DUMPSTATE *,bool);
void DumpSpecialLinkerInterfaceMembers(LIB *);
void DumpSymbolInfo(_IMAGE_SYMBOL_EX *,unsigned short *,unsigned int);
void DumpSymbolMap(DUMPSTATE const *);
void DumpSymbolTableEntry(_IMAGE_SYMBOL_EX *);
void DumpTLS(DUMPSTATE const *,_IMAGE_SECTION_HEADER *);
void DumpX64UnwindInfo(int,DUMPSTATE const *,unsigned long);
void DumperUsage();
void EbcLinkerInit(IMAGE *,bool *);
void EbcValidateDirectives(IMAGE *);
void EditResource(unsigned short const *,unsigned long);
void EditorFatal(unsigned short const *,unsigned long,...);
void EditorUsage();
void EmitCILDebugInfo(IMAGE *);
void EmitCILDebugInfoMOD(IMAGE *,IObjectContrib * *,COMRefPtr<ICOFFSymTabRW> &,MOD *,Array<CON *> *);
void EmitGlobalsIntoPGD(IMAGE *);
void EmitHelp(unsigned int,unsigned int);
void EmitMapExports(SymInfoEmitter *);
void EmitMapExternals(SymInfoEmitter *);
void EmitMapSections(SymInfoEmitter *);
void EmitMapStatics(SymInfoEmitter *);
void EmitMapSymbol(char const *,EXTERNAL *,CON *,MOD *,bool,unsigned long,unsigned __int64,bool,IMAGE *);
void EmitOffsets(int,ST *,bool);
void EmitStrings(int,ST *,bool);
void EndEnmBaseReloc(ENM_BASE_RELOC *);
void EndEnmCon(ENM_CON *);
void EndEnmEdge(ENM_EDGE *);
void EndEnmExtList(ENM_EXT_LIST *);
void EndEnmGrp(ENM_GRP *);
void EndEnmLib(ENM_LIB *);
void EndEnmMod(ENM_MOD *);
void EndEnmModExt(ENM_MOD_EXT *);
void EndEnmNode(ENM_NODE *);
void EndEnmSec(ENM_SEC *);
void EndEnmSrc(ENM_SRC *);
void EndEnmUndefExt(ENM_UNDEF_EXT *);
void Error(unsigned short const *,unsigned int,...);
void ExcludeLib(unsigned short const *,LIBS *,MOD *);
void ExtractImplibExports(DUMPSTATE const *,unsigned char *,unsigned long,int);
void ExtractMember(IMAGE *);
void Fatal(unsigned short const *,unsigned int,...);
void FatalLine(unsigned short const *,unsigned int,unsigned int,...);
void FatalNoDelete(unsigned short const *,unsigned int,...);
void FeedLinenums(IMAGE *,unsigned long,_IMAGE_LINENUMBER *,unsigned long,CON *,unsigned long,unsigned long);
void FileCloseAll();
void FileCloseMap(int);
void FileInit(unsigned long,unsigned long);
void FilePad(int,unsigned long);
void FileRead(int,void *,unsigned int);
void FileSetSize(int);
void FindSlotForPCON(IMAGE *,CON *);
void FlushBuffer(BUF *);
void ForceDoPass2PMOD(IMAGE *,MOD *,bool);
void FreeArgumentList(NAME_LIST *);
void FreeBlk(BLK *);
void FreeCvtcilArguments();
void FreeDumpstate(DUMPSTATE *);
void FreeExternalSymbolTable(ST * *);
void FreeHeap();
void FreeImage(IMAGE * *,bool);
void FreeMemory(void *);
void FreeModList(LMOD * *);
void FreePCONSpace(CON *,CON *,IMAGE *);
void FreePGDObjRec();
void FreePLIB(LIBS *,LIB *);
void FreePLIBHelper(LIB *,bool);
void FreePLIBs(LIBS *);
void FreePMOD(IMAGE *,MOD *);
void FreePlext<LEXT2>(LEXT2 *);
void FreePv(void *);
void FreeVirtHeap(LHEAPV *);
void FuzzyBsearch(ST *,char const *,Array<char *> &,Array<unsigned short const *> &,bool,bool);
void FuzzyBsearchInLib(LIB *,char const *,Array<char *> &,Array<unsigned short const *> &,bool);
void FuzzyLinearSearchInLib(LIB *,char const *,Array<char *> &,Array<unsigned short const *> &,bool,bool);
void FuzzyLookup(ST *,IMAGE *,bool,bool,bool,bool);
void FuzzyLookupPext(EXTERNAL *,ST *,IMAGE *,bool,bool,bool,bool);
void GenerateFieldTransition(IMAGE *,unsigned short const *,unsigned char const *,unsigned long,char const *,unsigned long);
void GenerateIOBJName();
void GenerateIPDBName();
void GenerateLBR(IMAGE *,unsigned long);
void GenerateMethodTransition(IMAGE *,unsigned short const *,unsigned char const *,unsigned long,char const *,unsigned long,unsigned int);
void GenerateOptimizedLBR(IMAGE *);
void GenerateTransitionIJW(IMAGE *,EXTERNAL *,unsigned int,unsigned char const *,unsigned long,CorPinvokeMap);
void GenerateTransitionPure(IMAGE *,EXTERNAL *,EXTERNAL *,unsigned int,unsigned char const *,unsigned long,CorPinvokeMap);
void GetCorDLLSig(unsigned char const * *,unsigned long *);
void GetFileID(unsigned short const *,LINK_FILE_ID *);
void GetLTCGDllImportSymbols(ILinkDataRO * *);
void GetLTCGEntryPoints(ILinkDataRO * *);
void GetLTCGUnrefSymbols(ILinkDataRO * *,Array<unsigned __int64> &);
void GetPdbModName(MOD *,IMAGE *,unsigned short const * *,unsigned short const * *,unsigned short *,unsigned int);
void GetTmpFile(unsigned short *,unsigned int);
void GetTmpFileWithPath(unsigned short *,unsigned int,unsigned short const *);
void GrowBlk(BLK *,unsigned int);
void GrowILKMap(unsigned int);
void GuardCollectPadSymIndex(CON *,IObjectContrib *,Array<unsigned long> &);
void HandleDefaultError(DBGCONTEXT *);
void HandleDefaultError(DBGCONTEXT *,unsigned short const *,long,unsigned short const *);
void ICFFold(IMAGE *,CON *,CON *,bool);
void ICFLocateICs(Array<CON *> const &,unsigned int,unsigned int,bool *);
void InconsistentMetadata3(IMAGE *,EXTERNAL *,unsigned int);
void InconsistentMetadataError(IMAGE *,EXTERNAL *);
void IncrAllocCommonPMOD(MOD *,IMAGE *);
void IncrAllocateCommon(IMAGE *);
void IncrCalcPtrs(IMAGE *);
void IncrCalcPtrsPMOD(MOD *,LIB *,IMAGE *);
void IncrInitImage(IMAGE * *);
void InferComEntryPoint(IMAGE *);
void InfoOpen(unsigned short const *);
void InitCRC(IMAGE *);
void InitCor(IMAGE *);
void InitEnmExtList(ENM_EXT_LIST *,LPEXT *);
void InitEnmModExt(ENM_MOD_EXT *,EXTERNAL *);
void InitEnmNode(ENM_NODE *,IMAGE *);
void InitExternalSymbolTable(ST * *,unsigned long,unsigned long);
void InitICFGrps();
void InitImage(IMAGE * *);
void InitModFileList(IMAGE *,bool *,bool *,bool *,bool *,bool *,NAME_LIST *,bool);
void InitNodePcon(IMAGE *,CON *,char const *,bool);
void InitNodePublicSymbol(EXTERNAL *,char const *,unsigned long,unsigned __int64 *,bool,NODE * *);
void InitPageSize();
void InitPconPmodMap();
void InitSEHImage(IMAGE *);
void Init_HT(HT * *,unsigned long,unsigned long,unsigned short);
void InitializeDumpstateFromFile(DUMPSTATE *,unsigned short const *,unsigned __int64,unsigned long);
void InitializeDumpstateFromHeader(DUMPSTATE *,LinkerInputFileHeaderInfo const &,unsigned long *);
void InitializeILHandler(IMAGE *,unsigned short const *,LinkerInputFileInfo const &);
void InsertPCONBetween(CON *,CON *,CON *);
void InternalError(unsigned short const *);
void InvokeMIDL(bool,unsigned short);
void LibrarianUsage();
void LinkInvalidParameterHandler(unsigned short const *,unsigned short const *,unsigned short const *,unsigned int,unsigned int);
void LinkOptionsChanged(unsigned short const *,bool);
void LinkerUsage();
void ListLibrary(LIB *);
void LoadCoffSymbolTable(DUMPSTATE *,unsigned long,unsigned short const *);
void LoadInProcPDBAPIs();
void LoadPDBAPIs();
void LoadPchObject(MOD *,Buffer &);
void LoadPchObject(MOD *,ILinkDataRO *);
void LoadPdata(IMAGE *,int,unsigned long,unsigned long,unsigned long,unsigned long,_IMAGE_SECTION_HEADER *,_IMAGE_SECTION_HEADER *,_IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY * *,_IMAGE_CE_RUNTIME_FUNCTION_ENTRY * *,_IMAGE_ARM_RUNTIME_FUNCTION_ENTRY * *,_IMAGE_RUNTIME_FUNCTION_ENTRY * *,unsigned long *,TFIXUP * *,unsigned long *);
void LoadRelocs(IMAGE *,_IMAGE_SECTION_HEADER *,unsigned long,unsigned long,int,TFIXUP * *,unsigned long *);
void LoadSourceMap(IMAGE *);
void LoadSourceMapFile(unsigned short const *);
void LoadStrings(DUMPSTATE *,unsigned short const *,unsigned long);
void LtcgP1BuildExternalSymbolTable(IMAGE *,bool *,MOD *);
void MSILCreateStub(IMAGE *);
void MSILWriteStubEntry(IMAGE *);
void MakeDefaultLib(unsigned short const *,LIBS *);
void MakeEdgePextFromISym(IMAGE *,Array<EXTERNAL *> &,Map<void *,unsigned long,LHashClass2<void *,7,3> > &,Map<void *,EXTERNAL *,LHashClass2<void *,7,3> > &);
void MakeEdgePextFromISym(IMAGE *,MOD *,EXTERNAL * *,unsigned long);
void MakeUniqueSXdata(bool);
void MarkExtern_FuncFixup(char const *,IMAGE *,CON *);
void MarkSymbols(IMAGE *);
void MarkSymbolsUndefinedPMOD(IMAGE *,MOD *);
void MarkToken(unsigned int);
void MergePsec(MOD *,SEC *,SEC *,IMAGE *);
void Message(unsigned int,...);
void MipsBuildRgfixupFromRgxfixup(unsigned __int64,unsigned __int64,XFIXUP const *,unsigned int,unsigned long,unsigned long,unsigned char const *,FIXUP *);
void MovePgrp(char const *,SEC *,SEC *);
void MoveToBeginningOfPSECsListOfPGRPs(GRP *,GRP *);
void MoveToBeginningOfPSECsPGRP(GRP *);
void MoveToEndPSEC(SEC *,SECS *);
void MoveToFreeListPfi(FI *);
void MoveToHeadLRU(BUF *);
void MultDefFound(IMAGE *,LIB *,LPEXT *);
void MultipleMetadataError(IMAGE *,EXTERNAL *);
void MultiplyDefinedSym<CON>(IMAGE *,unsigned short const *,char const *,CON *);
void MultiplyDefinedSym<EXTERNAL>(IMAGE *,unsigned short const *,char const *,EXTERNAL *);
void MultiplyDefinedSym<MOD>(IMAGE *,unsigned short const *,char const *,MOD *);
void NoDefaultLib(unsigned short const *,LIBS *);
void NotePdbUsed(void *,unsigned short const *,int,int);
void NoteTypeMismatch(void *,unsigned short const *,unsigned short const *);
void ObjFileAddExternalFilenames(COMRefPtr<IEnumExternalFilenames2>);
void OnExitCleanup();
void OrderPsecs(SECS *,unsigned int,unsigned long,unsigned long);
void OutOfDiskSpace();
void OutOfILKSpace();
void OutOfMemory();
void OutputInit();
void PDBError(MOD *,long,unsigned short const *);
void PDBError(long,unsigned short const *,unsigned short const *);
void ParseCommandLine(int,unsigned short * const * const,unsigned short const *,unsigned short const *,bool);
void ParseCommandString(unsigned short *);
void ParseExportDirective(unsigned short const *,IMAGE *,bool,unsigned short const *);
void ParseExportDirectives(IMAGE *,NAME_LIST &);
void ParseReserveCommit(unsigned short const *,unsigned __int64 *,unsigned __int64 *);
void ParseSecName(char const *,char const * *);
void ParseSection(unsigned short const *,char const * *,char const * *,unsigned long *,unsigned short const *,unsigned long,bool);
void ParseSymbol(unsigned short const *,unsigned short const *,bool);
void Pass2InitUninitDataPcon(IMAGE *,CON *);
void Pass2PSYM_clr_token(IMAGE *,ICOFFSymRW *,MOD *,int);
void Pass2PSYM_section(IMAGE *,ICOFFSymRW *,MOD *,MOD *);
void Pass2PSYM_static_label(IMAGE *,ICOFFSymRW *,MOD *,MOD *,unsigned char,int);
void Pass2ReadWriteLineNumbersPCON(IMAGE *,IObjectContrib *,CON *);
void PentNew_TCE(MOD *,unsigned int);
void PinvokeNoCallConvError(IMAGE *,EXTERNAL *);
void PogoOpt();
void PostNote(unsigned short const *,unsigned int,...);
void PrepLibForSearching(LIB *);
void PrepareToModifyFile(ARGUMENT_LIST *,bool);
void PrescanCommandLine(int,unsigned short * const * const,unsigned short const *,unsigned short const *);
void PrintCommandLine(unsigned short const * *);
void PrintLogo();
void ProcessAbsSymForIlink(IMAGE *,EXTERNAL *,unsigned long,char const *,bool,MOD *);
void ProcessArgument(unsigned short *,bool,bool,bool);
void ProcessCORMeta(IMAGE *,MOD *,CON *);
void ProcessCommandFile(unsigned short const *);
void ProcessCommonSymForIlink(IMAGE *,EXTERNAL *,unsigned long,char const *,bool,MOD *);
void ProcessCvtCilSwitches(IMAGE *);
void ProcessDumperSwitches();
void ProcessEditorSwitches(int,unsigned short const *,int,long,bool,bool);
void ProcessInitSymReplacingCommonSym(IMAGE *,EXTERNAL *,char const *,bool);
void ProcessLib(int,LIB *);
void ProcessLibrarianSwitches(IMAGE *);
void ProcessLinkerSwitches(IMAGE *,MOD *,bool);
void ProcessManifest(IMAGE *);
void ProcessPGDFile(IMAGE *,bool);
void ProcessPublicSymbolsInModule(IMAGE *,MOD *,bool *,unsigned short);
void ProcessRelocForTCE(CON *,COMRefPtr<ICOFFSymTabRO> &,_IMAGE_RELOCATION *);
void ProcessResFiles(IMAGE *,LIB *,bool);
void ProcessSectionInModule(IMAGE *,MOD *,int,IObjectContrib *,COMRefPtr<ICOFFSymTabRO> &,NAME_LIST *,Array<CON *> &,Array<CON *> &,Array<unsigned long> &,bool &);
void ProcessUndefinedExternals(IMAGE *);
void ProcessWeakExtern(IMAGE *,ICOFFSymTabRO *,ICOFFSymRO *,EXTERNAL *,MOD *,bool *,bool,unsigned short);
void ProcessWeakPublic(IMAGE *,IPublicSym *,EXTERNAL *,MOD *,bool,unsigned short);
void ProcessWildCards(unsigned short const *);
void ReadFileHeader(int,unsigned short const *,LinkerInputFileHeaderInfo *,_IMAGE_FILE_HEADER *);
void ReadHeaders(DUMPSTATE *,unsigned long,unsigned long,bool);
void ReadIncrDbFile(IMAGE * *);
void ReadOptionalHeader(DUMPSTATE *);
void ReadOptionalHeader(int,_IMAGE_OPTIONAL_HEADER64 &,unsigned long &,unsigned long,_IMAGE_DATA_DIRECTORY *);
void ReadPogoLinkInfo();
void ReadSectionHeaders(DUMPSTATE *,unsigned long,unsigned long);
void ReadStringsAndSymbols(DUMPSTATE *,int,unsigned short const *);
void ReadSymsStringsAndRelocs(_IMAGE_RELOCATION * *,unsigned long,CON *);
void ReadpbufCur(FI *);
void ReallocRgci(unsigned long);
void RecordSeenMultiplyDefinedSymbol(IMAGE *);
void RecordSymDef(SYM_DEF * *,EXTERNAL *,MOD *);
void RecordTransitionIJW(IMAGE *,unsigned int,EXTERNAL *);
void ReleaseMovedDataRefList();
void RemoveAllRefsToPext(EXTERNAL *);
void RemoveAssociativeSymbolComdats(EXTERNAL *);
void RemoveConvertTempFilesPNL(NAME_LIST *);
void RemovePCONFromGrp(CON *);
void RemovePextWeakMappings(IMAGE *,MOD *);
void RemovePrevDefn(EXTERNAL *);
void RemoveReferencesPMOD(MOD *);
void RemoveStaleBaseRelocs_TCE(IMAGE *);
void RemoveStaleRefs(IMAGE *,Array<LIB *> &,char const *,SEC *,char const *,SEC *,char const *,SEC *,char const *,SEC *,char const *,SEC *,char const *,SEC *,char const *);
void RemoveStaleRefs_TCE(IMAGE *);
void ReportFatalError(DBGFATALERROR *);
void ReportMultipleMetadataError(IMAGE *,MOD *,unsigned short const *,char const *,unsigned int);
void ResetLibsAndMods(IMAGE *);
void ResetPFI(FI *,bool);
void ResolveAlternateNames(IMAGE *,bool,bool);
void ResolveExistingWeakAndLazyExterns(IMAGE *);
void ResolveWeakExterns(IMAGE *);
void SaveCORTCEInfo(MOD *,unsigned int,int);
void SaveDebugFixup(unsigned short,unsigned short,unsigned long,unsigned long);
void SaveDebugFixupFromImgReloc(CON *,COMRefPtr<ICOFFSymTabRW> &,unsigned long,_IMAGE_RELOCATION *);
void SaveEXEInfo(unsigned short const *,IMAGE *);
void SaveExpFileInfo(EXPINFO *,unsigned short const *,TIME64,bool);
void SaveExportInfo(unsigned short const *,EXPINFO *);
void SaveIDLSymSection(IObjectContrib *,unsigned long);
void SaveImage(IMAGE *,unsigned long *);
void SaveLinkerDefTCEInfo(unsigned int,CON *);
void SavePconTkMOD(CON *,unsigned int,MOD *);
void SaveStaticForMapFile(char const *,CON *,MOD *,unsigned long,bool);
void SaveTkEmitPcon_TCE(unsigned int,CON *);
void SaveTmpFileNameForCleanUp(unsigned short *);
void SearchForDuplicate(IMAGE *,char const *,Array<char *> &,Array<unsigned short const *> &,bool,bool,bool);
void SearchForDuplicateInLibs(IMAGE *,char const *,Array<char *> &,Array<unsigned short const *> &,bool,bool);
void SetAssemblyDebug(IMAGE *);
void SetDefaultAppContainer(IMAGE *);
void SetDefaultDynamicBase(IMAGE *);
void SetDefaultHighEntropyVA(IMAGE *);
void SetDefaultLargeAddressAware(IMAGE *);
void SetDefaultNXCompat(IMAGE *);
void SetDefaultOutFilename(IMAGE *,ARGUMENT_LIST *);
void SetDefaultTSAware(IMAGE *);
void SetDefinedExt(EXTERNAL *,bool,ST *);
void SetFatalError(DBGCONTEXT *,bool,unsigned short const *,unsigned int,...);
void SetFieldRVA(unsigned int,unsigned long);
void SetIdataNullThunkPMOD(MOD *);
void SetLTCGArgs(unsigned short const *);
void SetRVA(unsigned int,unsigned long);
void SetSymbolShortName(char * const,char const *);
void SetupForFullIlinkBuild(IMAGE * *);
void SetupForIncrIlinkBuild(IMAGE * *,void *,unsigned long,bool);
void Sh4BuildRgfixupFromRgxfixup(unsigned __int64,unsigned __int64,XFIXUP const *,unsigned int,unsigned long,unsigned long,unsigned char const *,FIXUP *);
void SlidePbufCur(FI *);
void SortPGRPByPMOD(GRP *);
void SortSectionList(SECS *,unsigned int,int (*)(void const *,void const *));
void SpawnCvtcil(unsigned short const *,unsigned short const *);
void SpawnToRunTool(unsigned short const *,unsigned short const * *,unsigned short const *,unsigned int);
void SqmEmit(unsigned short,unsigned short,unsigned short,unsigned short,unsigned short);
void SqmEmitIncrErr();
void SqmInit();
void StartUploaderProc();
void StoreBaseRelocation(unsigned short,unsigned long,int,unsigned long,bool);
void StrCatToStringTable(unsigned char *,char const *);
void StrCpyToStringTable(unsigned char *,char const *);
void TrackNonNativePublic(EXTERNAL *,unsigned __int64,bool,Map<void *,EXTERNAL *,LHashClass2<void *,7,3> > *);
void TransferLinkerSwitchValues(IMAGE *,IMAGE const *);
void TransitionPFI(FI *,FI * *,FI * *,FI * *,FI * *,bool);
void UnableToExtendMap();
void UpdateCORDirectory(IMAGE *);
void UpdateCORPcons(bool);
void UpdateCrcEdges(IMAGE *,CON *);
void UpdateDebugDir(IMAGE *);
void UpdateExternalSymbol(EXTERNAL *,ST *,CON *,unsigned long,int,unsigned short,MOD *,unsigned short,unsigned int);
void UpdateImgHdrsAndComment(IMAGE *,bool);
void UpdateSEHSymbols(IMAGE *);
void UpdateSXdata(IMAGE *);
void VSetFatalError(DBGCONTEXT *,bool,unsigned short const *,unsigned int,char *);
void ValidateImportHeader(unsigned short const *,IMPORT_OBJECT_HEADER const *);
void Verbose_TCE(IMAGE *);
void VerifyAnObject(IMAGE *,ARGUMENT_LIST *,bool *,unsigned long *,IObjFile2 * *,MOD *);
void VerifyCOREntry(IMAGE *);
void VerifyFilenames(IMAGE *,bool);
void VerifyModuleRef();
void VerifyObjects(IMAGE *);
void VerifyPogoFileTimes(IMAGE *);
void WaitPendingTasks(CTaskQueue *);
void WalkGraphEntryPoints_TCE(IMAGE *);
void WarnExports(EXTERNAL *,char const *,unsigned short const *,unsigned long);
void Warning(unsigned short const *,unsigned int,...);
void WarningConflictingLibs(LIBS *);
void WarningIgnoredExports(unsigned short const *);
void WarningLine(unsigned short const *,unsigned int,unsigned int,...);
void WriteComdatMetainfo(bool);
void WriteFileHeader(int,bool,_IMAGE_FILE_HEADER *,_IMAGE_FILE_HEADER *);
void WriteFpoRecordsToPdb(FPOI *);
void WriteIncrDbFile(IMAGE *);
void WriteLTCGMetaObject(unsigned short const *,IObjFile2 *,ICOFFObj *,NAME_LIST *,unsigned short const *);
void WriteLTCGObject(unsigned short const *,IObjFile2 *,ICOFFObj *,bool,Buffer *);
void WriteMemberHeader(int,char const *,bool,__int64,unsigned short,long,_IMAGE_ARCHIVE_MEMBER_HEADER *);
void WriteSectionHeader(int,_IMAGE_SECTION_HEADER *,_IMAGE_SECTION_HEADER *);
void X64BuildRgfixupFromRgimgreloc(_IMAGE_RELOCATION const *,unsigned int,unsigned char const *,FIXUP *);
void X64BuildRgfixupFromRgxfixup(unsigned __int64,unsigned __int64,XFIXUP const *,unsigned int,unsigned long,unsigned long,unsigned char const *,FIXUP *);
void X64LinkerInit(IMAGE *,bool *);
void X64ValidateDirectives(IMAGE *);
void X86BuildRgfixupFromRgimgreloc(_IMAGE_RELOCATION const *,unsigned int,unsigned char const *,FIXUP *);
void X86BuildRgfixupFromRgxfixup(unsigned __int64,unsigned __int64,XFIXUP const *,unsigned int,unsigned long,unsigned long,unsigned char const *,FIXUP *);
void X86LinkerInit(IMAGE *,bool *);
void X86ValidateDirectives(IMAGE *);
void ZeroPCONSpace(CON *,IMAGE *);
void ZeroPadImageSections(IMAGE *,unsigned char *);
void __empty_global_delete(void *,unsigned int);
void __global_delete(void *,unsigned int);
void __scrt_initialize_type_info();
void const * * ArmThunks;
void dbgprint(unsigned short const *,...);
void dbsetflags(unsigned short const *,unsigned short const *);
void getLocalAppDataPath(unsigned short *,int);
void getSqmLogPath(unsigned short const *,unsigned short *,int);
void operator delete(void *);
void operator delete(void *,unsigned int);
void operator delete[](void *);
void strdup_TCE(char const *,char * *,unsigned int *);
