#include "StdAfx.h"
#include <WinInet.h>

_NT_BEGIN

#include "../winz/str.h"
#include "../asio/ssl.h"
#include "../asio/CiclicBuffer.h"
#include "dllVector.h"

BOOL IsValidPDBExist(POBJECT_ATTRIBUTES poa, PGUID Signature, DWORD Age);

//#undef DbgPrint
#define DbgPrintEx /##/

PSTR ParseHTTPStatusLine(PSTR buf, ULONG cb, PULONG pStatusCode, PULONG pdwMajorVersion = 0, PULONG pdwMinorVersion = 0)
{
	PSTR end;

	if (
		cb < 6 ||
		(*buf++|0x20) != 'h' ||
		(*buf++|0x20) != 't' ||
		(*buf++|0x20) != 't' ||
		(*buf++|0x20) != 'p' ||
		*buf++ != '/' ||
		!(end = strnchr(cb - 5, buf, '\n')) || end[-2] != '\r'
		)
	{
		return 0;
	}

	ULONG n = strtoul(buf, &buf, 10);

	if (*buf != '.')
	{
		return 0;
	}

	if (pdwMajorVersion)
	{
		*pdwMajorVersion = n;
	}

	n = strtoul(buf + 1, &buf, 10);

	if (*buf != ' ')
	{
		return 0;
	}

	if (pdwMinorVersion)
	{
		*pdwMinorVersion = n;
	}

	n = strtoul(buf + 1, &buf, 10);

	if (*buf == ' ' || buf == end - 2)
	{
		*pStatusCode = n;
		return end;
	}

	return 0;
}

PSTR ParseHTTPHeaders(PSTR buf, PSTR end, PULONG pLineCount)
{
	ULONG LineCount = 0;

	while (PSTR sz = _strnchr(buf, end, '\n'))
	{
		if (sz == buf + 1 || sz[-2] != '\r')
		{
			return 0;
		}

		if (sz == buf + 2)
		{
			*pLineCount = LineCount;
			return sz;
		}

		do 
		{
			char c = *buf;

			if (c == ':')
			{
				*buf = 0;
				break;
			}

			*buf++ = c | 0x20;

			if (buf == sz)
			{
				return 0;
			}

		} while (buf < sz);

		buf = sz, LineCount++;
	}

	return 0;
}

void GetHTTPHeaders(PSTR buf, ULONG hash[], PSTR values[], ULONG n)
{
	do 
	{
		ULONG cb = (ULONG)strlen(buf);
		*hash++ = RtlComputeCrc32(0, buf, cb);
		*values++ = buf += cb + 1;
		(buf = strnchr(MAXSIZE_T, buf, '\n'))[-2] = 0;
	} while (--n);
}

//ULONG gTlsIndex;

class CFileDownload;

class __declspec(novtable) CyclicBuferExW : public ZRingBuffer
{
public:
	virtual void OnWriteError() = 0;
	virtual void AddRef() = 0;
	virtual void Release() = 0;
};

namespace SI {
	ULONG dwAllocationGranularity, dwPageSize;

	struct __{

		__(){
			SYSTEM_INFO si;
			GetSystemInfo(&si);

			if ((si.dwAllocationGranularity & (si.dwAllocationGranularity - 1)) ||
				(si.dwPageSize & (si.dwPageSize - 1)))
			{
				__debugbreak();
			}

			dwAllocationGranularity = si.dwAllocationGranularity - 1;
			dwPageSize = si.dwPageSize;
		}
	} _;
};

NTSTATUS InitBytesPerSector(HANDLE hFile, PULONG pBytesPerSector)
{
	IO_STATUS_BLOCK iosb;

	union {
		FILE_FS_SECTOR_SIZE_INFORMATION ffssi;
		FILE_FS_SIZE_INFORMATION ffsi;
	};

	NTSTATUS status = NtQueryVolumeInformationFile(hFile, &iosb, &ffssi, sizeof(ffssi), FileFsSectorSizeInformation);

	ULONG BytesPerSector;

	if (0 <= status)
	{
		BytesPerSector = ffssi.PhysicalBytesPerSectorForPerformance;
	}
	else
	{
		status = NtQueryVolumeInformationFile(hFile, &iosb, &ffsi, sizeof(ffsi), FileFsSizeInformation);

		if (0 > status)
		{
			return status;
		}

		BytesPerSector = ffsi.BytesPerSector;
	}

	if ( ((BytesPerSector - 1) & BytesPerSector) || BytesPerSector > 0x10000)
	{
		return STATUS_UNSUCCESSFUL;
	}

	if (BytesPerSector < SI::dwPageSize)
	{
		BytesPerSector = SI::dwPageSize;
	}

	*pBytesPerSector = BytesPerSector;

	return STATUS_SUCCESS;
}

class CFileWriter : public IO_OBJECT
{
	enum { opWrite, opCmp };
	LARGE_INTEGER _ByteOffset, _EndOfFile;
	CyclicBuferExW* _pDD;

	~CFileWriter()
	{
		DbgPrint("%s<%p> %I64x\n", __FUNCTION__, this, _ByteOffset.QuadPart);
		_pDD->Release();
	}

public:

	BOOL IsCreated()
	{
		return getHandleNoLock() != 0;
	}

	CFileWriter(CyclicBuferExW* pDD) : _pDD(pDD)
	{
		DbgPrint("%s<%p>\n", __FUNCTION__, this);
		pDD->AddRef();
	}

	void Cleanup()
	{
		if (HANDLE hFile = getHandleNoLock())
		{
			if (_ByteOffset.QuadPart < _EndOfFile.QuadPart)
			{
				IO_STATUS_BLOCK iosb;
				static FILE_DISPOSITION_INFORMATION fdi = { TRUE };
				NtSetInformationFile(hFile, &iosb, &fdi, sizeof(fdi), FileDispositionInformation);
			}

			Close();
		}
	}

	// return are EndRead will be called
	bool Write(PFILE_SEGMENT_ELEMENT aSegmentArray, ULONG Length)
	{
		DbgPrint("%08x:BeginWrite<%p>(%08x->%I64x)\n", GetCurrentThreadId(), this, Length, _ByteOffset.QuadPart);

		if (_ByteOffset.QuadPart < _EndOfFile.QuadPart)
		{
			if (NT_IRP* irp = new NT_IRP(this, opWrite, 0, 0))
			{
				NTSTATUS status = STATUS_INVALID_HANDLE;

				HANDLE hFile;
				if (LockHandle(hFile))
				{
					status = NtWriteFileGather(hFile, 0, 0, irp, irp, aSegmentArray, Length, &_ByteOffset, 0);
					UnlockHandle();
				}

				irp->CheckNtStatus(status);

				return true;
			}
		}

		_pDD->OnWriteError();

		return false;
	}

	NTSTATUS Create(POBJECT_ATTRIBUTES poa, PLARGE_INTEGER EndOfFile)
	{
		if (getHandleNoLock()) __debugbreak();

		//DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_INFO_LEVEL, "%s<%p>(%wZ, %I64x)\n", __FUNCTION__, this, poa->ObjectName, EndOfFile->QuadPart);

		HANDLE hFile;
		IO_STATUS_BLOCK iosb;

		NTSTATUS status = NtCreateFile(&hFile, DELETE|FILE_WRITE_DATA|FILE_READ_DATA, poa, &iosb,
			EndOfFile, 0, FILE_SHARE_VALID_FLAGS, FILE_OVERWRITE_IF, 
			FILE_NON_DIRECTORY_FILE|FILE_NO_INTERMEDIATE_BUFFERING, 0, 0);

		if (0 > status)
		{
			return status;
		}

		Assign(hFile);

		_ByteOffset.QuadPart = 0;
		_EndOfFile.QuadPart = EndOfFile->QuadPart;

		if (0 <= (status = NT_IRP::RtlBindIoCompletion(hFile)))
		{
			static USHORT cmp = COMPRESSION_FORMAT_NONE;

			if (NT_IRP* irp = new NT_IRP(this, opCmp, 0))
			{
				status = NtFsControlFile(hFile, 0, 0, irp, irp, FSCTL_SET_COMPRESSION, &cmp, sizeof(cmp), 0, 0);

				DbgPrint("%x>SET_COMPRESSION>%x %x %p\n", GetCurrentThreadId(), status, irp->Status, irp->Information);

				irp->CheckNtStatus(status);
			}
		}

		return status;
	}

	void OnWrite(ULONG_PTR dwNumberOfBytesTransfered)
	{
		_ByteOffset.QuadPart += dwNumberOfBytesTransfered;

		if (_EndOfFile.QuadPart <= _ByteOffset.QuadPart)//<
		{
			DbgPrint("%08x:onwrite end<%p>(%08x)\n", GetCurrentThreadId(), this, dwNumberOfBytesTransfered);

			if (_EndOfFile.QuadPart < _ByteOffset.QuadPart)
			{
				IO_STATUS_BLOCK iosb;
				NtSetInformationFile(getHandleNoLock(), &iosb, &_EndOfFile, sizeof(_EndOfFile), FileEndOfFileInformation);
			}
		}

		DbgPrint("\n%08x:+++++++++ OnWriteEnd<%p>(%08x->%I64x) +++++++++\n", GetCurrentThreadId(), this, dwNumberOfBytesTransfered, _ByteOffset.QuadPart);
	}
private:
	void IOCompletionRoutine(CDataPacket* /*packet*/, DWORD Code, NTSTATUS status, ULONG_PTR dwNumberOfBytesTransfered, PVOID /*Pointer*/)
	{
		switch(Code)
		{
		case opCmp:
			if (0 <= status)
			{
				HANDLE hFile;
				if (LockHandle(hFile))
				{
					IO_STATUS_BLOCK iosb;
					NtSetInformationFile(hFile, &iosb, &_EndOfFile, sizeof(_EndOfFile), FileEndOfFileInformation);
					NtSetInformationFile(hFile, &iosb, &_EndOfFile, sizeof(_EndOfFile), FileValidDataLengthInformation);
					UnlockHandle();
				}
			}
			break;
		case opWrite:
			if (0 > status || !dwNumberOfBytesTransfered)
			{
				dwNumberOfBytesTransfered = 0;
				status = false;
			}
			else
			{
				OnWrite(dwNumberOfBytesTransfered);
				status = true;
			}
			_pDD->EndRead((ULONG)dwNumberOfBytesTransfered);
			if (status)
			{
				break;
			}
		default:
			//__debugbreak();
			_pDD->OnWriteError();
		}
	}
};

//////////////////////////////////////////////////////////////////////////
//

class CFileDownloadS : public CSSLEndpoint, public CyclicBuferExW
{
	enum { e_http_head_max_size = 0x4000 };
	LARGE_INTEGER _cbBytesNeed;
	PWSTR _FileName;
	PSTR _http_head_buffer;//e_http_head_max_size
	ZDllVector* _task;
	HANDLE _hRoot;
	HWND _hwnd;
	CFileWriter* _pFileWriter;
	WSABUF _Buffers[2];
	ULONG _dwBufferCount;
	ULONG _dwHeadSize;
	ULONG _dwNumberOfBytesRead;
	ULONG _ip;
	ULONG _BytesPerSector, _MinWriteSize;
	ULONG _id, _n, _dwExtraSize, _dwGetDataSize;
	INTERNET_PORT _nPort;
	BOOLEAN _bHandshakeDone, _bSSL, _bRead, _bRedirected;

private:

	virtual ULONG GetMinReadBufferSize()
	{ 
		return _BytesPerSector; 
	}

	virtual ULONG GetMinWriteBufferSize()
	{ 
		return _MinWriteSize; 
	}

	virtual void OnIoStop()
	{
		_pFileWriter->Cleanup();
		//PostMessage(_hwnd, e_text, _id, (LPARAM)L"IoStop");
		Next();
	}

	virtual void OnWriteError() 
	{
		PostMessage(_hwnd, e_text, _id, (LPARAM)L"WriteError");
		Disconnect();
	}

	virtual bool BeginRead(WSABUF* lpBuffers, ULONG dwBufferCount)
	{
		if (!dwBufferCount)
		{
			return false;
		}

		WSABUF* p = lpBuffers;
		int len;
		ULONG n = dwBufferCount, elementCount = 1, Length = 0;
		do 
		{
			--n;
			if (len = p++->len)
			{
				if (n && (len & (SI::dwPageSize - 1))) 
				{
					__debugbreak();
					return false;
				}
				elementCount += (len +  SI::dwPageSize - 1) / SI::dwPageSize ;
			}
		} while (n);

		union {
			PVOID buf;
			PFILE_SEGMENT_ELEMENT aSegmentArray;
		};

		buf = alloca(elementCount * sizeof(FILE_SEGMENT_ELEMENT));
		PFILE_SEGMENT_ELEMENT pse = aSegmentArray;

		do 
		{
			PCHAR Buffer = lpBuffers->buf;
			if (len = lpBuffers++->len)
			{
				Length += len;
				do 
				{
					pse++->Buffer = PtrToPtr64(Buffer);
				} while (Buffer += SI::dwPageSize, 0 < (len -= SI::dwPageSize));
			}
		} while (--dwBufferCount);

		pse->Buffer = 0;

		DbgPrint("%08x:WriteFrom<%p>(%x)\n", GetCurrentThreadId(), this, Length);

		return _pFileWriter->Write(aSegmentArray, Length & ~(_BytesPerSector - 1));
	}

	virtual ULONG GetRecvBuffers(WSABUF lpBuffers[2], void** ppv)
	{
		DbgPrint("%08x:GetRecvBuffers_0(%x)\n", GetCurrentThreadId(), _dataSize);

		if (!_bHandshakeDone)
		{
			return CTcpEndpoint::GetRecvBuffers(lpBuffers, ppv);
		}

		_dwNumberOfBytesRead = 0;

		ULONG len = 0, data_size = m_packet->getDataSize(), MaximumMessage = getMaximumMessage(), cb = getHeaderSize()+getTrailerSize();

		data_size = data_size > cb ? data_size - cb : 0;

		if (data_size >= MaximumMessage)
		{
			__debugbreak();
			return 0;
		}

		if (ULONG dwBufferCount = _dwBufferCount)
		{
			WSABUF* Buf = _Buffers;
			do 
			{
				len += Buf++->len;
			} while (--dwBufferCount);
		}

		if (len < MaximumMessage)
		{
			__debugbreak();
			return 0;
		}

		*ppv = lpBuffers->buf = m_packet->getFreeBuffer(), lpBuffers->len = m_packet->getFreeSize();

		if (lpBuffers->len > (len -= data_size))
		{
			lpBuffers->len = len;
		}

		DbgPrint("%08x:GetRecvBuffers(%x, %x, %x)\n", GetCurrentThreadId(), data_size, len, m_packet->getFreeSize());

		return 1;
	}

	virtual BOOL OnRecv(PSTR Buf, ULONG cbTransferred)
	{
		_dwNumberOfBytesRead = 0;

		DbgPrint("\n%08x:OnRecv begin(%x) {%x}(%x)\n", GetCurrentThreadId(), cbTransferred, _bHandshakeDone, _dataSize);

		BOOL f = _bSSL ? OnData(Buf, cbTransferred) : OnUserData(Buf, cbTransferred);

		if (_dwNumberOfBytesRead)
		{
			DbgPrint("%08x: ++++ OnRecv:OnReadEnd(%x)(%x)\n", GetCurrentThreadId(), _dwNumberOfBytesRead, _dataSize);

			EndWrite(_dwNumberOfBytesRead);
			// -> ReadTo() can be called from here

			DbgPrint("%08x: ---- OnRecv:OnReadEnd(%x)(%x)\n", GetCurrentThreadId(), _dwNumberOfBytesRead, _dataSize);

			return _bRead ? -1 : 0;
		}

		DbgPrint("%08x: ++++ OnRecv:OnReadContinue\n", GetCurrentThreadId());
		return f;
	}

	virtual bool BeginWrite(WSABUF* lpBuffers, DWORD dwBufferCount)
	{
		if (_bSSL)
		{
			_dwBufferCount = dwBufferCount;
			memcpy(_Buffers, lpBuffers, dwBufferCount * sizeof(WSABUF));

			DbgPrint("%08x:ReadTo(%d) (%p,%x)\n%c\t(%p,%x)\n", GetCurrentThreadId(), dwBufferCount, lpBuffers->buf, lpBuffers->len, dwBufferCount == 1 ? 0 : ' ', lpBuffers[1].buf, lpBuffers[1].len);

			Recv();
		}
		else
		{
			_dwBufferCount = 0;
			if (_bRead)
			{
				DbgPrint("%08x:ReadTo [%x], (%p,%x)\n%c\t(%p,%x)\n", GetCurrentThreadId(), dwBufferCount, lpBuffers->buf, lpBuffers->len, dwBufferCount == 1 ? 0 : ' ', lpBuffers[1].buf, lpBuffers[1].len);

				Recv(lpBuffers, dwBufferCount, GetBuffer());
			}
			else
			{
				DbgPrint("readto:__nop()\n");
			}
		}
		return true;
	}

	virtual BOOL IsServer(PBOOLEAN pbMutualAuth = 0)
	{
		if (pbMutualAuth)
		{
			*pbMutualAuth = FALSE;
		}
		return FALSE;
	}

	virtual void OnDisconnect()
	{
		//DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_INFO_LEVEL, "%s<%p>\n", __FUNCTION__, this);
		
		if (_bRedirected)
		{
			PostMessage(_hwnd, e_text, _id, (LPARAM)L"redirect...");
		}
		else
		{
			PostMessage(_hwnd, e_disconnect, _id, _pFileWriter->IsCreated() && !_cbBytesNeed.QuadPart);
		}

		StopSSL();

		EndWrite(0);
	}

	virtual BOOL OnConnect(ULONG dwError)
	{
		_dwHeadSize = 0;

		PostMessage(_hwnd, e_connect, _id, dwError);
		DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_INFO_LEVEL, "%s<%p>(%u) [%x]\n", __FUNCTION__, this, dwError, _bSSL);

		if (dwError)
		{
			Next();
			return FALSE;
		}

		if (_bSSL && !StartSSL())
		{
			return FALSE;
		}

		ZRingBuffer::Start();

		return  -1;
	}

	virtual ULONG GetConnectData(void** ppSendBuffer)
	{
		return _bSSL ? 0 : (*ppSendBuffer = ZRingBuffer::GetBuffer(), _dwGetDataSize);
	}

	virtual SECURITY_STATUS OnEndHandshake()
	{
		//DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_INFO_LEVEL, "%s<%p>\n", __FUNCTION__, this);
		PostMessage(_hwnd, e_text, _id, (LPARAM)L"EndHandshake");

		_bHandshakeDone = TRUE;

		_MinWriteSize = (getMaximumMessage() + _BytesPerSector - 1) & ~(_BytesPerSector - 1);

		if (ULONG dwError = SendUserData(ZRingBuffer::GetBuffer(), _dwGetDataSize))
		{
			PostMessage(_hwnd, e_send, _id, (LPARAM)dwError);
			return HRESULT_FROM_WIN32(dwError);
		}
		return SEC_E_OK;
	}

	// return size of headers
	ULONG CheckResponce(PSTR Buf, ULONG cbTransferred)
	{
		ULONG StatusCode, LineCount;

		PSTR headers = ParseHTTPStatusLine(Buf, cbTransferred, &StatusCode);

		if (headers)
		{
			enum X : DWORD {
				f_Content_Length = 0x12bc2f1c,
				f_Location = 0x5e9e89cb, /* Location */
			};

			ULONG h;
			BOOL fRedirect = FALSE;

			switch (StatusCode)
			{
			case 200:
				h = f_Content_Length;
				break;
			case 301:
			case 302:
				h = f_Location;
				fRedirect = TRUE;
				break;
			default : return 0;
			}

			if (PSTR body = ParseHTTPHeaders(headers, Buf + cbTransferred, &LineCount))
			{
				if (LineCount)
				{
					PSTR* values = (PSTR*)alloca(LineCount * (sizeof(PSTR) + sizeof(ULONG)));
					PULONG hash = (PULONG)(values + LineCount);
					GetHTTPHeaders(headers, hash, values, LineCount);

					do 
					{
						if (*hash++ == h)
						{
							if (fRedirect)
							{
								URL_COMPONENTSA uc = { sizeof(uc) };
								uc.dwHostNameLength = 1;
								uc.dwUrlPathLength = 1;
								body = *values;
								while (*body == ' ') body++;

								if (InternetCrackUrlA(body, 0, 0, &uc))
								{
									switch (uc.nScheme)
									{
									case INTERNET_SCHEME_HTTP:
										_bSSL = FALSE;
										break;
									case INTERNET_SCHEME_HTTPS:
										_bSSL = TRUE;
										break;
									default: return 0;
									}

									_nPort = _byteswap_ushort(uc.nPort);

									STATIC_ASTRING(format, "GET %.*s HTTP/1.1\r\n"
										"Host: %.*s\r\n"
										"User-Agent: Microsoft-Symbol-Server/10.0.0.0\r\n"
										"Connection: Close\r\n"
										"\r\n");

									if (sizeof(format) + uc.dwHostNameLength + uc.dwUrlPathLength <= ZRingBuffer::GetSize())
									{
										if (PVOID lpszHostName = _malloca(uc.dwHostNameLength))
										{
											memcpy(lpszHostName, uc.lpszHostName, uc.dwHostNameLength);

											PSTR buf = (PSTR)ZRingBuffer::GetBuffer();

											_dwGetDataSize = sprintf(buf, format, 
												uc.dwUrlPathLength, uc.lpszUrlPath, 
												uc.dwHostNameLength, lpszHostName);

											memcpy(buf + _dwGetDataSize, lpszHostName, uc.dwHostNameLength);

											buf[uc.dwHostNameLength + _dwGetDataSize] = 0;

											_bRedirected = TRUE;

											_freea(lpszHostName);
										}
									}

									return 0;
								}
							}
							else
							{
								PSTR c;
								if (ULONG64 size = _strtoui64(*values, &c, 10))
								{
									if (!*c)
									{
										_cbBytesNeed.QuadPart = size;
										return RtlPointerToOffset(Buf, body);
									}
								}
							}

							break;
						}

					} while (values++, --LineCount);
				}
			}
		}

		return 0;
	}

	virtual BOOL OnUserData(PSTR Buf, ULONG cbTransferred)
	{
		DbgPrint("%08x:OnUserData(%p, %x)\n", GetCurrentThreadId(), Buf, cbTransferred);

		ULONG cb, len, dwBufferCount, cbReaded = 0;

		if (!_cbBytesNeed.QuadPart)
		{
			// first recv
			STATIC_ASTRING(empty_line, "\r\n\r\n");

			DbgPrint("_dwHeadSize=%x _http_head_buffer=%p\n", _dwHeadSize, _http_head_buffer);

			if (_dwHeadSize)
			{
				cb = e_http_head_max_size - _dwHeadSize;

				if (cb > cbTransferred)
				{
					cb = cbTransferred;
				}

				memcpy(_http_head_buffer + _dwHeadSize, Buf, cb);

				len = _dwHeadSize, _dwHeadSize += cb;

				if (!strnstr(_dwHeadSize, _http_head_buffer, LP(empty_line)))
				{
					DbgPrint("_dwHeadSize=%x->%x\n", len, _dwHeadSize);

					if (e_http_head_max_size != _dwHeadSize)
					{
						return TRUE;
					}
					PostMessageW(_hwnd, e_text, _id, (LPARAM)L"too big http header");
					_bRead = FALSE;
					return FALSE;
				}

				if (cb = CheckResponce(_http_head_buffer, _dwHeadSize))
				{
					cb -= len;
					DbgPrint("final_1 _dwHeadSize=%x(%x)\n", cb, len);
				}
			}
			else if (strnstr(cbTransferred, Buf, LP(empty_line)))
			{
				cb = CheckResponce(Buf, cbTransferred);
				DbgPrint("final_0 _dwHeadSize=%x\n", cb);
			}
			else
			{
				if (
					cbTransferred >= e_http_head_max_size ||
					(!_http_head_buffer && !(_http_head_buffer = new char[e_http_head_max_size]))
					)
				{
					DbgPrint("bad header\n");
					PostMessageW(_hwnd, e_text, _id, (LPARAM)L"bad http header");
					_bRead = FALSE;
					return FALSE;
				}
				memcpy(_http_head_buffer, Buf, cbTransferred);
				_dwHeadSize = cbTransferred;
				DbgPrint("partial data, first _dwHeadSize=%x\n", cbTransferred);
				return TRUE;
			}

			if (cb)
			{
				// 200 ok

				UNICODE_STRING ObjectName;
				OBJECT_ATTRIBUTES oa = { sizeof(oa), _hRoot, &ObjectName };
				RtlInitUnicodeString(&ObjectName, _FileName);

				NTSTATUS status = _pFileWriter->Create(&oa, &_cbBytesNeed);

				if (_hRoot)
				{
					NtClose(_hRoot);
					_hRoot = 0;
				}

				if (0 > status)
				{
					_bRead = FALSE;
					PostMessageW(_hwnd, e_pdbcreate, _id, (LPARAM)status);
					return FALSE;
				}

				_dwExtraSize = (_BytesPerSector - _cbBytesNeed.LowPart) & (_BytesPerSector - 1);

				PostMessage(_hwnd, e_length, _id, _cbBytesNeed.LowPart);

				if (!(cbTransferred -= cb))
				{
					// yet no data
					return TRUE;// continue read
				}

				Buf += cb;

				if (!_bSSL)
				{
					memcpy(ZRingBuffer::GetBuffer(), Buf, cbTransferred);
				}
			}
			else
			{
				// redirect or fail
				_bRead = FALSE;
				if (!_bRedirected && _task->IsSingle())
				{
					if (CDataPacket* packet = new(cbTransferred+1) CDataPacket)
					{
						memcpy(packet->getData(), Buf, cbTransferred);
						packet->getData()[cbTransferred] = 0;
						if (!PostMessage(_hwnd, e_packet, 0, (LPARAM)packet))
						{
							packet->Release();
						}
					}
				}
				return FALSE;
			}
		}

		if (_dwBufferCount) 
		{
			dwBufferCount = _dwBufferCount;
			WSABUF* pBuf = _Buffers;
			do 
			{
				if (len = pBuf->len)
				{
					memcpy(pBuf->buf, Buf, len = min(len, cbTransferred));
					cbReaded += len, Buf += len, pBuf->len -= len, pBuf->buf += len;
					if (!(cbTransferred -= len))
					{
						break;
					}
				}
			} while (pBuf++, --dwBufferCount);
		}
		else
		{
			cbReaded = cbTransferred;
		}

		DbgPrint("%08x:OnUserData(%x)\n", GetCurrentThreadId(), cbReaded);

		if (cbReaded)
		{
			_dwNumberOfBytesRead += cbReaded;

			if (0 >= (_cbBytesNeed.QuadPart -= cbReaded))
			{
				_bRead = FALSE;
				DbgPrint("%08x:read end (%u)\n", GetCurrentThreadId());
				// read end
				_dwNumberOfBytesRead += _dwExtraSize;
				DbgPrint("%08x:OnUserData-end(%x)\n", GetCurrentThreadId(), cbReaded);
			}

			PostMessage(_hwnd, e_recv, _id, _cbBytesNeed.LowPart);
		}
		else
		{
			__debugbreak();
		}

		return _bRead;
	}

	virtual void OnIp(DWORD ip)
	{
		DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_INFO_LEVEL, "%s<%p>(%s) = %x\n", __FUNCTION__, this, (PSTR)ZRingBuffer::GetBuffer() + _dwGetDataSize, ip);
		if (ip)
		{
			if (ULONG err = Connect(ip, _nPort))
			{
				PostMessage(_hwnd, e_connect, _id, err);
			}
			else
			{
				PostMessage(_hwnd, e_text, _id, (LPARAM)L"connecting...");
				return ;
			}
		}
		else
		{
			PostMessage(_hwnd, e_connect, _id, ERROR_NOT_FOUND);
		}
		Next();
	}

	~CFileDownloadS()
	{
		DbgPrint("%08x:%s<%p>\n", GetCurrentThreadId(), __FUNCTION__, this);
		_bRedirected = FALSE;
		Cleanup();

		if (_http_head_buffer)
		{
			delete [] _http_head_buffer;
		}

		if (PVOID pv = ZRingBuffer::GetBuffer())
		{
			VirtualFree(pv, 0, MEM_RELEASE);
		}

		_task->DecActive();
		_task->Release();
	}

	void Cleanup()
	{
		_cbBytesNeed.QuadPart = 0;
		_bHandshakeDone = FALSE, _bRead = TRUE;

		_dwBufferCount = 0;
		_dwNumberOfBytesRead = 0;

		if (_bRedirected)
		{
			_bRedirected = FALSE;
		}
		else
		{
			_bSSL = FALSE;
			if (_FileName)
			{
				delete [] _FileName;
				_FileName = 0;
			}
			if (_hRoot)
			{
				NtClose(_hRoot);
				_hRoot = 0;
			}
		}
	}

public:

	virtual void AddRef()
	{
		IO_OBJECT::AddRef();
	}

	virtual void Release()
	{
		IO_OBJECT::Release();
	}

	void Start()
	{
		_task->Register(this, _id);
		Next();
	}

	void Next()
	{
		DbgPrint("%s<%p>\n", __FUNCTION__, this);

		BOOLEAN bRedirected = _bRedirected;

		Cleanup();

		if (!_task->IsStop())
		{
			if (bRedirected)
			{
				PostMessage(_hwnd, e_text, _id, (LPARAM)L"resolving host...");
				DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_INFO_LEVEL, "%s<%p>(%s)\n", __FUNCTION__, this, (PSTR)ZRingBuffer::GetBuffer() + _dwGetDataSize);

				DnsToIp((PCSTR)ZRingBuffer::GetBuffer() + _dwGetDataSize, DNS_RTYPE_A, DNS_QUERY_NO_WIRE_QUERY);
				return;
			}

			static volatile UCHAR guz;
			ULONG cb = 0, rcb;
			PVOID stack = alloca(guz);
			PWSTR path = 0;
			STATIC_WSTRING(globalroot, "\\\\.\\global\\globalroot");

			LONG n;

			while (!_task->IsStop())
			{
				if (PCSTR name = _task->GetNextName(&n))
				{
					_n = n;

					rcb = ((ULONG)strlen(name) + 1) << 1;
					BOOL bNtPath = *name == '\\';
					if (bNtPath)
					{
						rcb += sizeof(globalroot) - sizeof(WCHAR);
					}

					if (cb < rcb)
					{
						cb = RtlPointerToOffset(path = (PWSTR)alloca(rcb - cb), stack);
					}

					if (bNtPath)
					{
						swprintf(path, L"%s%S", globalroot, name);
					}
					else
					{
						swprintf(path, L"%S", name);
					}

					NTSTATUS status = GetPdbforPE(path);

					if (status) 
					{
						PostMessage(_hwnd, e_init, _id|(n << 8), status);
						continue;
					}

					if (status = Connect(_task->get_ip(), 0x5000))
					{
						PostMessage(_hwnd, e_connect, _id, status);
					}
					else
					{
						PostMessage(_hwnd, e_name, _id, n);
						return ;// -> Disconnect -> Next
					}
				}

				break;
			}
		}

		_task->Unregister(_id);

		if (_pFileWriter)
		{
			_pFileWriter->Release();
			_pFileWriter = 0;
		}
	}

	CFileDownloadS(ZDllVector* task) : CSSLEndpoint(task->getCred())
	{
		DbgPrint("%s<%p>\n", __FUNCTION__, this);
		_bRedirected = FALSE;
		_pFileWriter = 0;
		_FileName = 0;
		_http_head_buffer = 0;
		_BytesPerSector = 0;
		_MinWriteSize = 0;

		task->AddRef();
		task->IncActive();
		_task = task;
		_hRoot = 0;
		_hwnd = task->get_HWND();
		_id = task->get_ID();
	}

	NTSTATUS GetPdbforPE(PCWSTR lpszName)
	{
		HMODULE hmod = LoadLibraryExW(lpszName, 0, LOAD_LIBRARY_AS_DATAFILE);

		if (!hmod) return RtlGetLastNtStatus();

		NTSTATUS status = STATUS_NOT_FOUND;

		DWORD cb;
		BOOLEAN bMappedAsImage = !((DWORD_PTR)hmod & (PAGE_SIZE - 1));
		PIMAGE_DEBUG_DIRECTORY pidd = (PIMAGE_DEBUG_DIRECTORY)RtlImageDirectoryEntryToData(hmod, bMappedAsImage, IMAGE_DIRECTORY_ENTRY_DEBUG, &cb);
		if (pidd && cb && !(cb % sizeof IMAGE_DEBUG_DIRECTORY))
		{
			do 
			{
				struct CV_INFO_PDB 
				{
					DWORD CvSignature;
					GUID Signature;
					DWORD Age;
					char PdbFileName[];
				};

				if (pidd->Type == IMAGE_DEBUG_TYPE_CODEVIEW && pidd->SizeOfData > sizeof(CV_INFO_PDB))
				{
					if (DWORD PointerToRawData = bMappedAsImage ? pidd->AddressOfRawData : pidd->PointerToRawData)
					{
						CV_INFO_PDB* lpcvh = (CV_INFO_PDB*)RtlOffsetToPointer(PAGE_ALIGN(hmod), PointerToRawData);

						if (lpcvh->CvSignature == 'SDSR')
						{
							PCSTR PdbFileName = lpcvh->PdbFileName, c = strrchr(PdbFileName, L'\\');
							if (c)
							{
								PdbFileName = c + 1;
							}

							status = Init(PdbFileName, &lpcvh->Signature, lpcvh->Age);

							break;
						}
					}
				}

			} while (pidd++, cb -= sizeof IMAGE_DEBUG_DIRECTORY);
		}

		FreeLibrary(hmod);

		return status;
	}

	NTSTATUS AllocateRingBuffer(HANDLE hFile)
	{
		NTSTATUS status = _BytesPerSector ? STATUS_SUCCESS : InitBytesPerSector(hFile, &_BytesPerSector);

		if (0 <= status)
		{
			_MinWriteSize = _BytesPerSector;

			ULONG s = (2*_BytesPerSector + SI::dwAllocationGranularity) & ~SI::dwAllocationGranularity;

			if (s != ZRingBuffer::GetSize())
			{
				PVOID pv = ZRingBuffer::GetBuffer();

				if (pv)
				{
					VirtualFree(pv, 0, MEM_RELEASE);
					ZRingBuffer::Init(0, 0);
					pv = 0;
				}

				SIZE_T size = s;

				if (0 <= (status = ZwAllocateVirtualMemory(NtCurrentProcess(), &pv, 0, &size, MEM_COMMIT, PAGE_READWRITE)))
				{
					ZRingBuffer::Init(pv, s);
				}
			}
		}

		return status;
	}

	NTSTATUS Init(PCSTR PdbFileName, PGUID Signature, DWORD Age)
	{
		Cleanup();

		ULONG UTF8StringByteCount = (ULONG)strlen(PdbFileName) + 1;
		ULONG UnicodeStringLen = MultiByteToWideChar(CP_UTF8, 0, PdbFileName, UTF8StringByteCount, 0, 0);

		if (!UnicodeStringLen)
		{
			return STATUS_UNSUCCESSFUL;
		}

		if (UnicodeStringLen >= MAXSHORT)
		{
			return STATUS_NAME_TOO_LONG;
		}

		if (!(_FileName = new WCHAR[UnicodeStringLen]))
		{
			return STATUS_INSUFF_SERVER_RESOURCES;
		}

		UnicodeStringLen = MultiByteToWideChar(CP_UTF8, 0, PdbFileName, UTF8StringByteCount, _FileName, UnicodeStringLen);

		if (!UnicodeStringLen)
		{
			return STATUS_NAME_TOO_LONG;
		}

		WCHAR sz[256];

		swprintf(sz, L"%08X%04X%04X%02X%02X%02X%02X%02X%02X%02X%02X%x", 
			Signature->Data1, Signature->Data2, Signature->Data3,
			Signature->Data4[0], Signature->Data4[1], Signature->Data4[2], Signature->Data4[3], 
			Signature->Data4[4], Signature->Data4[5], Signature->Data4[6], Signature->Data4[7], Age);

		HANDLE hRoot;
		IO_STATUS_BLOCK iosb;
		UNICODE_STRING ObjectName;
		OBJECT_ATTRIBUTES oa = { sizeof(oa), _task->get_Root(), &ObjectName };
		RtlInitUnicodeString(&ObjectName, _FileName);

		NTSTATUS status = NtCreateFile(&hRoot, FILE_ADD_SUBDIRECTORY|SYNCHRONIZE, &oa, &iosb, 0, 
			0, FILE_SHARE_VALID_FLAGS, FILE_OPEN_IF, FILE_DIRECTORY_FILE, 0, 0);

		//DbgPrintEx ( DPFLTR_DEFAULT_ID, DPFLTR_INFO_LEVEL, "%s<%p>: %wZ\n",  __FUNCTION__, this, &ObjectName);

		if (0 > status)
		{
			return status;
		}

		oa.RootDirectory = hRoot;

		RtlInitUnicodeString(&ObjectName, sz);

		if (0 <= (status = AllocateRingBuffer(hRoot)))
		{
			status = NtCreateFile(&_hRoot, FILE_ADD_SUBDIRECTORY|SYNCHRONIZE, &oa, &iosb, 0, 
				0, FILE_SHARE_VALID_FLAGS, FILE_OPEN_IF, FILE_DIRECTORY_FILE, 0, 0);
		}

		NtClose(oa.RootDirectory);

		if (0 > status)
		{
			return status;
		}

		RtlInitUnicodeString(&ObjectName, _FileName);
		oa.RootDirectory = _hRoot;

		if (IsValidPDBExist(&oa, Signature, Age))
		{
			if (!_task->IsSingle())
			{
				return STATUS_OBJECT_NAME_EXISTS;
			}

			FormatMessage(FORMAT_MESSAGE_IGNORE_INSERTS|FORMAT_MESSAGE_FROM_HMODULE,
				GetModuleHandleW(L"ntdll"), STATUS_OBJECT_NAME_EXISTS, 0, sz, RTL_NUMBER_OF(sz), 0);

			if (MessageBox(_task->get_HWND(), sz, L"Download anyway ?", MB_YESNO|MB_ICONQUESTION) != IDYES)
			{
				return STATUS_OBJECT_NAME_EXISTS;
			}
		}

		STATIC_ASTRING(httpHeader, "GET /download/symbols/"
			"%s/%08X%04X%04X%02X%02X%02X%02X%02X%02X%02X%02X%x/%s HTTP/1.1"
			"\r\nUser-Agent: Microsoft-Symbol-Server/10.0.0.0"
			"\r\nHost: msdl.microsoft.com"
			"\r\nConnection: close\r\n\r\n");

		PSTR buf = (PSTR)ZRingBuffer::GetBuffer();

		_dwGetDataSize = _snprintf(buf, ZRingBuffer::GetSize(),
			httpHeader,
			PdbFileName, Signature->Data1, Signature->Data2, Signature->Data3,
			Signature->Data4[0], Signature->Data4[1], Signature->Data4[2], Signature->Data4[3], 
			Signature->Data4[4], Signature->Data4[5], Signature->Data4[6], Signature->Data4[7], Age, PdbFileName);

		if (_dwGetDataSize >= ZRingBuffer::GetSize())
		{
			return STATUS_UNSUCCESSFUL;
		}

		DbgPrint(buf);

		return status;
	}

	ULONG Create()
	{
		if (!(_pFileWriter = new CFileWriter(this)))
		{
			return ERROR_NO_SYSTEM_RESOURCES;
		}

		if (ULONG dwError = CTcpEndpoint::Create(SI::dwAllocationGranularity + 1))
		{
			return dwError;
		}

		return NOERROR;
	}
};

DWORD WorkItem(ZDllVector* task)
{
	if (CFileDownloadS* p = new CFileDownloadS(task))
	{
		if (!p->Create())
		{
			p->Start();
		}
		p->Release();
	}
	task->DecActive();
	task->Release();
	return 0;
}

ULONG CreateSingleDownload(SDP* params)
{
	ZDllVector* task = params->task;
	ULONG dwError = ERROR_NO_SYSTEM_RESOURCES;

	if (CFileDownloadS* p = new CFileDownloadS(task))
	{
		if (!(dwError = p->Create()) &&
			!(dwError = RtlNtStatusToDosError(params->type == SDP::e_path ? 
			p->GetPdbforPE(params->DllFileName) : p->Init(params->PdbFileName, &params->Signature, params->Age))))
		{
			task->Register(p, 0);
			PostMessage(task->get_HWND(), e_text, task->get_ID(), (LPARAM)L"connecting(0)...");
			dwError = p->Connect(task->get_ip(), 0x5000);
		}

		if (dwError)
		{
			p->Next();
		}
		p->Release();
	}

	return dwError;
}

_NT_END