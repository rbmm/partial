#include "StdAfx.h"

_NT_BEGIN

// PDB Stream IDs
#define PDB_STREAM_ROOT   0
#define PDB_STREAM_PDB    1
#define PDB_STREAM_TPI    2
#define PDB_STREAM_DBI    3
#define PDB_STREAM_FPO    5

// =================================================================
// PDB INTERFACE VERSIONS
// =================================================================

#define PDBIntv41         920924
#define PDBIntv50       19960502
#define PDBIntv50a      19970116
#define PDBIntv60       19970116
#define PDBIntv61       19980914
#define PDBIntv69       19990511
#define PDBIntv70Dep    20000406
#define PDBIntv70       20001102

#define PDBIntv         PDBIntv70

#define PDBIntvAlt      PDBIntv50
#define PDBIntvAlt2     PDBIntv60
#define PDBIntvAlt3     PDBIntv69

// =================================================================
// PDB IMPLEMENTATION VERSIONS
// =================================================================

#define PDBImpvVC2      19941610
#define PDBImpvVC4      19950623
#define PDBImpvVC41     19950814
#define PDBImpvVC50     19960307
#define PDBImpvVC98     19970604
#define PDBImpvVC70Dep  19990604
#define PDBImpvVC70     20000404

#define PDBImpv         PDBImpvVC70

// =================================================================
// DBI IMPLEMENTATION VERSIONS
// =================================================================

#define DBIImpvV41        930803
#define DBIImpvV50      19960307
#define DBIImpvV60      19970606
#define DBIImpvV70      19990903

#define DBIImpv         DBIImpvV70

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
	DWORD impv;
	DWORD timeDateStamp;
	DWORD age;
	GUID  signature;
};

struct DbiHeader
{
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

class PdbReader  
{
	PVOID _BaseAddress, _PdbBase;
	ULONG _pageSize, _pagesUsed, _nStreams, *_StreamSizes, *_StreamPages;

	PULONG GetStreamPages(ULONG iStream)
	{
		if (iStream < _nStreams)
		{
			ULONG pageSize = _pageSize;
			PULONG StreamSizes = _StreamSizes, StreamPages = _StreamPages;

			do 
			{
				if (ULONG StreamSize = *StreamSizes++)
				{
					StreamPages += (StreamSize + pageSize - 1) / pageSize;
				}
			} while (--iStream);

			return StreamPages;
		}

		return 0;
	}

	BOOL Read(ULONG StreamPages[], ULONG ofs, PBYTE pb, ULONG cb)
	{
		PVOID PdbBase = _PdbBase;
		ULONG cbCopy, pagesUsed = _pagesUsed, Page, PageSize = _pageSize;

		StreamPages += ofs / PageSize;

		if (ofs %= PageSize)
		{
			if ((Page = *StreamPages++) >= pagesUsed) 
			{
				return FALSE;
			}

			memcpy(pb, RtlOffsetToPointer(PdbBase, Page * PageSize) + ofs, cbCopy = min(PageSize - ofs, cb));

			pb += cbCopy, cb -= cbCopy;
		}

		if (cb)
		{
			do 
			{
				if ((Page = *StreamPages++) >= pagesUsed) 
				{
					return FALSE;
				}

				memcpy(pb, RtlOffsetToPointer(PdbBase, Page * PageSize), cbCopy = min(PageSize, cb));

			} while (pb += cbCopy, cb -= cbCopy);
		}

		return TRUE;
	}

	BOOL ValidatePdbHeader(PGUID signature)
	{
		PdbHeader psh;
		return _StreamSizes[PDB_STREAM_PDB] > sizeof(PdbHeader) && 
			Read(PDB_STREAM_PDB, 0, &psh, sizeof(psh)) && 
			psh.impv == PDBImpv && 
			psh.signature == *signature;
	}

public:

	BOOL Read(DWORD iStream, DWORD ofs, PVOID pb, DWORD cb)
	{
		PULONG StreamPages = GetStreamPages(iStream);
		return StreamPages ? Read(StreamPages, ofs, (PBYTE)pb, cb) : FALSE;
	}

	BOOL Init(PdbFileHeader* header, SIZE_T ViewSize, PGUID signature, DWORD Age)
	{
		ULONG pageSize = header->pageSize, pagesUsed = header->pagesUsed;

		if (ViewSize < pageSize * pagesUsed)
		{
			return FALSE;
		}

		ULONG directoryRoot = header->directoryRoot, directorySize = header->directorySize;

		if (directorySize < sizeof(ULONG))
		{
			return FALSE;
		}

		ULONG directoryEnd = ((((directorySize + pageSize - 1) / pageSize) * sizeof(ULONG) + pageSize - 1) / pageSize) + directoryRoot;

		if (directoryEnd <= directoryRoot || directoryEnd > pagesUsed)
		{
			return FALSE;
		}

		PULONG pd = (PULONG)new CHAR[directorySize];
		if (!pd)
		{
			return FALSE;
		}

		_BaseAddress = pd, _PdbBase = header, _pageSize = pageSize, _pagesUsed = pagesUsed;

		if (!Read((PULONG)RtlOffsetToPointer(header, directoryRoot * pageSize), 0, (PBYTE)pd, directorySize))
		{
			return FALSE;
		}

		ULONG nStreams = *pd++;;
		_nStreams = nStreams;
		_StreamSizes = pd, _StreamPages = _StreamSizes + _nStreams;

		if (nStreams <= PDB_STREAM_DBI || directorySize < (1 + nStreams) * sizeof(ULONG))
		{
			return FALSE;
		}

		ULONG i = nStreams, k = 0;
		do 
		{
			k += (*pd++ + pageSize - 1) / pageSize;
		} while (--i);

		ULONG dbiSize = _StreamSizes[PDB_STREAM_DBI];

		DbiHeader dbi;

		return directorySize >= (1 + nStreams + k) * sizeof(ULONG)
			&&
			ValidatePdbHeader(signature)
			&&
			dbiSize >= sizeof(DbiHeader) 
			&& 
			Read(PDB_STREAM_DBI, 0, &dbi, sizeof(DbiHeader))
			&&
			dbi.ver == DBIImpv 
			&&
			dbi.age == Age;
	}

	DWORD getStreamSize(ULONG iStream)
	{
		return iStream < _nStreams ? _StreamSizes[iStream] : 0;
	}

	PdbReader()
	{
		_BaseAddress = 0;
	}

	~PdbReader()
	{
		if (_BaseAddress)
		{
			delete _BaseAddress;
		}
	}
};

NTSTATUS MapFileRO(POBJECT_ATTRIBUTES poa, void** BaseAddress, PSIZE_T ViewSize)
{
	HANDLE hFile, hSection;
	IO_STATUS_BLOCK iosb;

	NTSTATUS status = ZwOpenFile(&hFile, FILE_GENERIC_READ, poa, &iosb, FILE_SHARE_READ, FILE_SYNCHRONOUS_IO_NONALERT);

	if (0 <= status)
	{
		status = ZwCreateSection(&hSection, SECTION_MAP_READ, 0, 0, PAGE_READONLY, SEC_COMMIT, hFile);

		ZwClose(hFile);

		if (0 <= status)
		{
			status = ZwMapViewOfSection(hSection, NtCurrentProcess(), BaseAddress, 0, 0, 0, ViewSize, ViewUnmap, 0, PAGE_READONLY);

			ZwClose(hSection);
		}
	}

	return status;
}

BOOL IsValidPDBExist(POBJECT_ATTRIBUTES poa, PGUID Signature, DWORD Age)
{
	BOOL fOk = FALSE;
	PdbFileHeader* BaseAddress = 0;
	SIZE_T ViewSize = 0;

	if (0 <= MapFileRO(poa, (void**)&BaseAddress, &ViewSize))
	{
		PdbReader pdb;
		fOk = pdb.Init(BaseAddress, ViewSize, Signature, Age);
		ZwUnmapViewOfSection(NtCurrentProcess(), BaseAddress);
	}

	return fOk;
}

_NT_END