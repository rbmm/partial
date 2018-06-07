#pragma once

#include "../CVINFO/cvinfo.h"

// PDB Stream IDs
#define PDB_STREAM_ROOT   0
#define PDB_STREAM_PDB    1
#define PDB_STREAM_TPI    2
#define PDB_STREAM_DBI    3
#define PDB_STREAM_FPO    5

// =================================================================
// PDB INTERFACE VERSIONS
// =================================================================

#define PDBIntv         20001102

struct PdbFileHeader
{
	CHAR	magic[32]; // PDB_SIGNATURE_200
	ULONG	pageSize;   // 0x0400, 0x0800, 0x1000
	ULONG	freePageMap;   // 0x0009, 0x0005, 0x0002
	ULONG	pagesUsed;   // file size / dPageSize
	ULONG	directorySize;  // in bytes, -1 = free stream
	ULONG	zero;   // stream directory
	ULONG	directoryRoot; // pages containing PDB_ROOT
};

struct PdbHeader
{
	enum { PDBImpv = 20000404 };
	DWORD impv;
	DWORD timeDateStamp;
	DWORD age;
	GUID  signature;
	ULONG cbStings;
	CHAR buf[];
};

struct PdbNameStream 
{
	enum { PDBNamesSig = 0xeffeeffe };
	ULONG sig;
	ULONG ver;//1
	ULONG cbStrings;
	CHAR buf[];
};

struct DbiSecCon
{
	ULONG section : 16;// begin from #1
	ULONG offset;
	ULONG size;
	ULONG flags;//IMAGE_SCN_
	ULONG module : 16;
	ULONG dataCrc;
	ULONG relocCrc;
};

struct DbiSecConArray 
{
	enum { mgc = 0xf12eba2d };

	ULONG magic;
	DbiSecCon arr[];
};

struct SC 
{
	ULONG offset;
	ULONG size;
	ULONG module;
};

struct DbiModuleInfo   
{            
	ULONG opened;                 //  0..3
	DbiSecCon sc;
	USHORT flags;                  // 32..33
	USHORT stream;                 // 34..35
	ULONG cbSyms;                 // 36..39
	ULONG cbOldLines;             // 40..43
	ULONG cbLines;                // 44..57
	USHORT files;                  // 48..49
	USHORT pad1;                   // 50..51
	ULONG offsets;
	ULONG niSource;
	ULONG niCompiler;
	char buf[]; //moduleName + objectName;
};

struct CV_DebugSFile 
{
	DWORD OfsFileName;
	BYTE  cbChecksum;
	CV_SourceChksum_t ChecksumType;
	BYTE Checksum[];
};

struct DbiHeader
{
	enum { DBIImpv = 19990903 };

	ULONG sig;                        // 0..3
	ULONG ver;                        // 4..7
	ULONG age;                        // 8..11
	USHORT gssymStream;                // 12..13
	USHORT vers;                       // 14..15
	USHORT pssymStream;                // 16..17
	USHORT pdbver;                     // 18..19
	USHORT symrecStream;               // 20..21
	USHORT pdbver2;                    // 22..23
	ULONG gpmodiSize;                 // 24..27
	ULONG secconSize;                 // 28..31
	ULONG secmapSize;                 // 32..35
	ULONG filinfSize;                 // 36..39
	ULONG tsmapSize;                  // 40..43
	ULONG mfcIndex;                   // 44..47
	ULONG dbghdrSize;                 // 48..51
	ULONG ecinfoSize;                 // 52..55
	USHORT flags;                      // 56..57
	USHORT machine;                    // 58..59
	ULONG reserved;                   // 60..63
};

struct DbiDbgHdr
{
	USHORT snFPO;                 // 0..1
	USHORT snException;           // 2..3 (deprecated)
	USHORT snFixup;               // 4..5
	USHORT snOmapToSrc;           // 6..7
	USHORT snOmapFromSrc;         // 8..9
	USHORT snSectionHdr;          // 10..11
	USHORT snTokenRidMap;         // 12..13
	USHORT snXdata;               // 14..15
	USHORT snPdata;               // 16..17
	USHORT snNewFPO;              // 18..19
	USHORT snSectionHdrOrig;      // 20..21
};

struct OMAP {
	ULONG  rva;
	ULONG  rvaTo;
};

struct CV_INFO_PDB 
{
	DWORD CvSignature;
	GUID Signature;
	DWORD Age;
	char PdbFileName[];
};

class PdbReader
{
	DbiHeader* _pdh;
	PIMAGE_SECTION_HEADER _pish;
	OMAP* _pvOmapFromSrc;
	PVOID _BaseAddress, _PdbBase;
	DbiSecCon* _pSecContrib;
	PLONG _StreamSizes;
	PULONG _StreamPages;
	PUSHORT _pFileInfo;
	DbiModuleInfo* _modules;
	ULONG _pageSize, _pagesUsed, _nStreams, _nSections, _nOmapFromSrc, _nSecContrib;
	BOOLEAN _bUnmap, _Is64Bit;

	PULONG GetStreamPages(ULONG iStream);

	BOOL Read(ULONG StreamPages[], ULONG ofs, PBYTE pb, ULONG cb);

public:

	BOOL Is64Bit()
	{
		return _Is64Bit;
	}

	BOOL Read(DWORD iStream, DWORD ofs, PVOID pb, DWORD cb)
	{
		PULONG StreamPages = GetStreamPages(iStream);
		return StreamPages ? Read(StreamPages, ofs, (PBYTE)pb, cb) : FALSE;
	}

	BOOL IsOmapExist()
	{
		return _pvOmapFromSrc != 0;
	}

	ULONG rva(ULONG segment, ULONG offset);

	NTSTATUS Init(DbiHeader* pdh, ULONG size, ULONG Age);

	NTSTATUS Init(PdbFileHeader* header, SIZE_T ViewSize, PGUID signature);

	NTSTATUS Init(PVOID BaseAddress, SIZE_T ViewSize, PGUID signature, ULONG Age);

	NTSTATUS getStream(ULONG iStream, void** ppv, PULONG pcb, LONG minSize = 1, ULONG mult = 1);

	SHORT getPublicSymbolsStreamIndex()
	{
		return _pdh->symrecStream;
	}

	DWORD getStreamSize(ULONG iStream)
	{
		return iStream < _nStreams ? _StreamSizes[iStream] : 0;
	}

	DbiModuleInfo* getModuleInfo(ULONG& gpmodiSize)
	{
		gpmodiSize = _pdh->gpmodiSize;
		return (DbiModuleInfo*)(_pdh + 1);
	}

	PUSHORT getFileInfo(ULONG& filinfSize)
	{
		filinfSize = _pdh->filinfSize;
		return _pFileInfo;
	}

	DbiSecCon* getSecCon(ULONG& nSecContrib)
	{
		nSecContrib = _nSecContrib;
		return _pSecContrib;
	}

	void FreeStream(PVOID pv)
	{
		delete pv;
	}

	PdbReader();

	~PdbReader();

	NTSTATUS Open(CV_INFO_PDB* lpcvh, PCWSTR NtSymbolPath = 0);
	NTSTATUS Open(PCWSTR FileName, PCWSTR NtSymbolPath = 0, PGUID Signature = 0, ULONG Age = 0);
};

struct TPIHDR          //  stream header
{
	/*000*/ DWORD   vers;        // implementation version
	/*004*/ LONG    cbHdr;       // header size
	/*008*/ DWORD   tiMin;       // type index base  (0x1000..0xFFFFFF)
	/*00C*/ DWORD   tiMax;       // type index limit (0x1000..0xFFFFFF)
};