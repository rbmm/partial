#include "StdAfx.h"

_NT_BEGIN

#include "PDB.h"

#pragma warning(disable : 4815)

PdbReader::PdbReader()
{
	_bUnmap = FALSE;
	_BaseAddress = 0;
	_pish = 0;
	_pvOmapFromSrc = 0;
	_pdh = 0;
}

PdbReader::~PdbReader()
{
	if (_pish)
	{
		FreeStream(_pish);
	}

	if (_pvOmapFromSrc)
	{
		FreeStream(_pvOmapFromSrc);
	}

	if (_pdh)
	{
		FreeStream(_pdh);
	}

	if (_BaseAddress)
	{
		delete _BaseAddress;
	}

	if (_bUnmap)
	{
		ZwUnmapViewOfSection(NtCurrentProcess(), _PdbBase);
	}
}

PULONG PdbReader::GetStreamPages(ULONG iStream)
{
	if (iStream < _nStreams)
	{
		ULONG pageSize = _pageSize;
		PLONG StreamSizes = _StreamSizes;
		PULONG StreamPages = _StreamPages;

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

BOOL PdbReader::Read(ULONG StreamPages[], ULONG ofs, PBYTE pb, ULONG cb)
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

NTSTATUS PdbReader::getStream(ULONG iStream, void** ppv, PULONG pcb, LONG minSize, ULONG mult)
{
	if (iStream >= _nStreams)
	{
		return STATUS_NOT_FOUND;
	}

	LONG cb = _StreamSizes[iStream];

	if (minSize > cb || cb % mult)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	if (PVOID pv = new CHAR[cb])
	{
		if (Read(iStream, 0, pv, cb))
		{
			*ppv = pv;
			*pcb = cb;
			return STATUS_SUCCESS;
		}

		delete pv;

		return STATUS_INVALID_IMAGE_FORMAT;
	}

	return STATUS_INSUFFICIENT_RESOURCES;
}

ULONG PdbReader::rva(ULONG segment, ULONG offset)
{
	if (segment > _nSections || offset >= _pish[--segment].Misc.VirtualSize)
	{
		return 0;
	}

	offset += _pish[segment].VirtualAddress;

	if (OMAP* pvOmapFromSrc = _pvOmapFromSrc)
	{
		ULONG a = 0, o, r, b = _nOmapFromSrc;
		OMAP *s = 0, *q;

		if (offset < pvOmapFromSrc->rva)
		{
			return 0;
		}

		do 
		{
			o = (a + b) >> 1;

			q = pvOmapFromSrc + o;
			r = q->rva;

			if (r == offset)
			{
				return q->rvaTo;
			}

			if (r < offset)
			{
				s = q;
				a = o + 1;
			}
			else
			{
				b = o;
			}

		} while (a < b);

		return (offset - s->rva) + s->rvaTo;
	}

	return offset;
}

NTSTATUS PdbReader::Init(DbiHeader* pdh, ULONG size, ULONG Age)
{
	if (pdh->ver != DbiHeader::DBIImpv)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	if (Age && pdh->age != Age)
	{
		return STATUS_REVISION_MISMATCH;
	}

#if 1
	switch (pdh->machine)
	{
	case 0:
	case IMAGE_FILE_MACHINE_I386:
		_Is64Bit = FALSE;
		break;
	case IMAGE_FILE_MACHINE_AMD64:
		_Is64Bit = TRUE;
		break;
	default: return STATUS_NOT_SUPPORTED;
	}

#endif

	ULONG a = sizeof(DbiHeader), b = a + pdh->gpmodiSize;

	if (a > b || b > size)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	ULONG secconSize = pdh->secconSize;

	a = b, b = a + secconSize;

	if (a > b || b > size)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	_pSecContrib = 0, _nSecContrib = 0;

	if (secconSize > sizeof(DbiSecConArray))
	{
		ULONG nSC = (secconSize -= sizeof(DbiSecConArray)) / sizeof(DbiSecCon);
		if (nSC && secconSize == nSC * sizeof(DbiSecCon))
		{
			DbiSecConArray* pvSecContrib = (DbiSecConArray*)RtlOffsetToPointer(pdh, a);
			if (pvSecContrib->magic == DbiSecConArray::mgc)
			{
				_pSecContrib = pvSecContrib->arr;
				_nSecContrib = nSC;
			}
		}
	}

	a = b, b = a + pdh->secmapSize;

	if (a > b || b > size)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	a = b, b = a + pdh->filinfSize;

	if (a > b || b > size)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	_pFileInfo = (PUSHORT)RtlOffsetToPointer(pdh, a);

	a = b, b = a + pdh->tsmapSize;

	if (a > b || b > size)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	a = b, b = a + pdh->ecinfoSize;

	if (a > b || b > size)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	a = b, b = a + pdh->dbghdrSize;

	if (a > b || b > size)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	if (sizeof(DbiDbgHdr) > pdh->dbghdrSize)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	DbiDbgHdr* pdbgHdr = (DbiDbgHdr*)RtlOffsetToPointer(pdh, a);

	NTSTATUS status;

	SHORT snOmapFromSrc = pdbgHdr->snOmapFromSrc, snSectionHdr = pdbgHdr->snSectionHdr;

	if (0 < snOmapFromSrc)
	{
		if (0 > (status = getStream(snOmapFromSrc, (void**)&_pvOmapFromSrc, &size, 1, sizeof(OMAP))))
		{
			return status;
		}

		_nOmapFromSrc = size / sizeof(OMAP);
		snSectionHdr = pdbgHdr->snSectionHdrOrig;
	}

	if (0 <= (status = getStream(snSectionHdr, (void**)&_pish, &size, 1, sizeof(IMAGE_SECTION_HEADER))))
	{
		_nSections = size / sizeof(IMAGE_SECTION_HEADER);
	}

	return status;
}

NTSTATUS PdbReader::Init(PdbFileHeader* header, SIZE_T ViewSize, PGUID signature)
{
	ULONG pageSize = header->pageSize, pagesUsed = header->pagesUsed;

	if (ViewSize < pageSize * pagesUsed)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	ULONG directoryRoot = header->directoryRoot, directorySize = header->directorySize;

	if (directorySize < sizeof(ULONG))
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	ULONG directoryEnd = ((((directorySize + pageSize - 1) / pageSize) * sizeof(ULONG) + pageSize - 1) / pageSize) + directoryRoot;

	if (directoryEnd <= directoryRoot || directoryEnd > pagesUsed)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	PULONG pd = (PULONG)new CHAR[directorySize];
	if (!pd)
	{
		return STATUS_INSUFFICIENT_RESOURCES;
	}

	_BaseAddress = pd, _PdbBase = header, _pageSize = pageSize, _pagesUsed = pagesUsed;

	if (!Read((PULONG)RtlOffsetToPointer(header, directoryRoot * pageSize), 0, (PBYTE)pd, directorySize))
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	ULONG nStreams = *pd++;;
	_nStreams = nStreams;
	_StreamSizes = (PLONG)pd, _StreamPages = pd + _nStreams;

	if (nStreams < PDB_STREAM_DBI || directorySize < (1 + nStreams) * sizeof(ULONG))
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	ULONG i = nStreams, k = 0;
	do 
	{
		k += (*pd++ + pageSize - 1) / pageSize;
	} while (--i);

	if (directorySize < (1 + nStreams + k) * sizeof(ULONG))
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	PdbHeader psh;

	if (_StreamSizes[PDB_STREAM_PDB] < sizeof(PdbHeader) || !Read(PDB_STREAM_PDB, 0, &psh, sizeof(psh)) || psh.impv != PdbHeader::PDBImpv)
	{
		return STATUS_INVALID_IMAGE_FORMAT;
	}

	return !signature || *signature == psh.signature ? STATUS_SUCCESS : STATUS_REVISION_MISMATCH;
}

NTSTATUS PdbReader::Init(PVOID BaseAddress, SIZE_T ViewSize, PGUID Signature, ULONG Age)
{
	NTSTATUS status = Init((PdbFileHeader*)BaseAddress, ViewSize, Signature);

	if (0 > status)
	{
		return status;
	}

	ULONG size;
	DbiHeader* pdh;

	if (0 <= (status = getStream(PDB_STREAM_DBI, (void**)&pdh, &size, sizeof(DbiHeader))))
	{
		_pdh = pdh;
		status = Init(pdh, size, Age);
	}

	return status;
}

NTSTATUS MapFileAndClose(HANDLE hFile, void** BaseAddress, PSIZE_T ViewSize)
{
	HANDLE hSection;

	NTSTATUS status = ZwCreateSection(&hSection, SECTION_MAP_READ, 0, 0, PAGE_READONLY, SEC_COMMIT, hFile);

	NtClose(hFile);

	if (0 <= status)
	{
		*BaseAddress = 0, *ViewSize = 0;
		status = ZwMapViewOfSection(hSection, NtCurrentProcess(), BaseAddress, 0, 0, 0, ViewSize, ViewUnmap, 0, PAGE_READONLY);
		NtClose(hSection);
	}

	return status;
}

NTSTATUS OpenNtFile(PHANDLE hFile, PCWSTR FilePath)
{
	UNICODE_STRING ObjectName;
	RtlInitUnicodeString(&ObjectName, FilePath);
	IO_STATUS_BLOCK iosb;
	OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, &ObjectName };
	return NtOpenFile(hFile, FILE_GENERIC_READ, &oa, &iosb, FILE_SHARE_VALID_FLAGS, FILE_SYNCHRONOUS_IO_NONALERT);
}

NTSTATUS OpenDosFile(PHANDLE hFile, PCWSTR FilePath)
{
	UNICODE_STRING ObjectName;
	if (RtlDosPathNameToNtPathName_U(FilePath, &ObjectName, 0, 0))
	{
		IO_STATUS_BLOCK iosb;
		OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, &ObjectName };
		NTSTATUS status = NtOpenFile(hFile, FILE_GENERIC_READ, &oa, &iosb, FILE_SHARE_VALID_FLAGS, FILE_SYNCHRONOUS_IO_NONALERT);
		RtlFreeUnicodeString(&ObjectName);
		return status;
	}

	return STATUS_OBJECT_PATH_INVALID;
}

NTSTATUS OpenPdb(PHANDLE hFile, 
				 PCWSTR PdbFileName, 
				 PCWSTR NtSymbolPath, 
				 PGUID Signature, 
				 ULONG Age)
{
	NTSTATUS status;

	PATH_TYPE pt = RtlDetermineDosPathNameType_U(PdbFileName);

	if (pt == absolutePath)
	{
		// try absolute path
		if (0 <= (status = OpenDosFile(hFile, PdbFileName)))
		{
			return STATUS_SUCCESS;
		}
	}

	if (!NtSymbolPath || !Signature)
	{
		return STATUS_NOT_FOUND;
	}

	PWSTR c = wcsrchr(PdbFileName, '\\');

	if (c)
	{
		PdbFileName = c + 1;
	}

	// try global system path
	SIZE_T cbPdb = (1 + wcslen(PdbFileName)) * sizeof(WCHAR);
	SIZE_T cb = (wcslen(NtSymbolPath) + 42) * sizeof(WCHAR) + 2 * cbPdb;
	PWSTR FilePath = (PWSTR)alloca(cb);

	swprintf(FilePath, L"%s\\%s\\%08X%04X%04X%02X%02X%02X%02X%02X%02X%02X%02X%x\\%s", 
		NtSymbolPath, PdbFileName,
		Signature->Data1, Signature->Data2, Signature->Data3,
		Signature->Data4[0], Signature->Data4[1], Signature->Data4[2], Signature->Data4[3],
		Signature->Data4[4], Signature->Data4[5], Signature->Data4[6], Signature->Data4[7],
		Age, PdbFileName);

	return OpenDosFile(hFile, FilePath);
}

NTSTATUS PdbReader::Open(CV_INFO_PDB* lpcvh, PCWSTR NtSymbolPath)
{
	if (lpcvh->CvSignature != 'SDSR') return STATUS_INVALID_IMAGE_FORMAT;

	PCSTR PdbFileName = lpcvh->PdbFileName;

	ULONG BytesInMultiByteString = (ULONG)strlen(PdbFileName) + 1;

	ULONG cchWideChar = MultiByteToWideChar(CP_UTF8, 0, PdbFileName, BytesInMultiByteString, 0, 0);

	if (!cchWideChar)
	{
		return STATUS_OBJECT_PATH_INVALID;
	}

	PWSTR FileName = (PWSTR)alloca(cchWideChar * sizeof(WCHAR));

	cchWideChar = MultiByteToWideChar(CP_UTF8, 0, PdbFileName, BytesInMultiByteString, FileName, cchWideChar);

	if (!cchWideChar)
	{
		return STATUS_OBJECT_PATH_INVALID;
	}

	return Open(FileName, NtSymbolPath, &lpcvh->Signature, lpcvh->Age);
}

NTSTATUS PdbReader::Open(PCWSTR FileName, PCWSTR NtSymbolPath, PGUID Signature, ULONG Age)
{
	HANDLE hFile;
	NTSTATUS status = OpenPdb(&hFile, FileName, NtSymbolPath, Signature, Age);

	if (0 > status)
	{
		return status;
	}

	PVOID BaseAddress = 0;
	SIZE_T ViewSize = 0;

	status = MapFileAndClose(hFile, &BaseAddress, &ViewSize);

	if (0 > status)
	{
		return status;
	}

	_PdbBase = BaseAddress, _bUnmap = TRUE;

	return Init(BaseAddress, ViewSize, Signature, Age);

}
_NT_END