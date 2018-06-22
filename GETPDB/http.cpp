#include "StdAfx.h"
#include <WinInet.h>

extern "C"
{
	PSTR __fastcall strnstr(SIZE_T n1, const void* str1, SIZE_T n2, const void* str2);
	PSTR __fastcall strnchr(SIZE_T n1, const void* str1, char c);
	DWORD* __fastcall findDWORD(SIZE_T, DWORD*, DWORD);
}

#define _strnstr(a, b, x) strnstr(RtlPointerToOffset(a, b), a, sizeof(x) - 1, x)
#define _strnstrL(a, b, x) strnstr(RtlPointerToOffset(a, b), a, strlen(x), x)
#define _strnchr(a, b, c) strnchr(RtlPointerToOffset(a, b), a, c)
#define _strnstrS(a, b, s, x) strnstr(RtlPointerToOffset(a, b), a, s, x)

#define LP(str) RTL_NUMBER_OF(str) - 1, str

_NT_BEGIN

#include "../asio/ssl.h"
#include "../asio/CiclicBuffer.h"
#include "dllVector.h"

BOOL IsValidPDBExist(POBJECT_ATTRIBUTES poa, PGUID Signature, DWORD Age);
//
#define DbgPrint /##/

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

//struct STAGE 
//{
//	ULONG n;
//
//	static STAGE* get()
//	{
//		STAGE* p = (STAGE*)TlsGetValue(gTlsIndex);
//		if (!p)
//		{
//			p = new STAGE;
//			p->n = 0;
//			TlsSetValue(gTlsIndex, p);
//		}
//		return p;
//	}
//};

class CFileDownload;

class __declspec(novtable) CyclicBuferExW : public CyclicBuferEx
{
public:
	virtual void WriteBegin() = 0;
	virtual void WriteCompleted() = 0;
	virtual void OnWriteError() = 0;
};

class CFileWriter : public IO_OBJECT
{
	enum { opWrite };
	LARGE_INTEGER _ByteOffset, _EndOfFile;
	CyclicBuferExW* _pDD;

	~CFileWriter()
	{
		DbgPrint("%s<%p> %I64x\n", __FUNCTION__, this, _ByteOffset.QuadPart);
	}

public:

	BOOL IsCreated()
	{
		return m_hFile != 0;
	}

	CFileWriter(CyclicBuferExW* pDD) : _pDD(pDD)
	{
		DbgPrint("%s<%p>\n", __FUNCTION__, this);
	}

	void Cleanup()
	{
		if (m_hFile)
		{
			if (_ByteOffset.QuadPart < _EndOfFile.QuadPart)
			{
				IO_STATUS_BLOCK iosb;
				static FILE_DISPOSITION_INFORMATION fdi = { TRUE };
				NtSetInformationFile(m_hFile, &iosb, &fdi, sizeof(fdi), FileDispositionInformation);
			}

			Close();
		}
	}

	void Write(PFILE_SEGMENT_ELEMENT SegmentArray, ULONG Length)
	{
		//DbgPrint("%08x.%u:BeginWrite<%p>(%08x->%I64x)\n", GetCurrentThreadId(), STAGE::get()->n, this, Length, _ByteOffset.QuadPart);

		if (NT_IRP* irp = new NT_IRP(this, opWrite, 0, 0))
		{
			_pDD->WriteBegin();
			irp->CheckNtStatus(NtWriteFileGather(m_hFile, 0, 0, irp, irp, SegmentArray, Length, &_ByteOffset, 0));
		}
	}

	NTSTATUS Create(POBJECT_ATTRIBUTES poa, PLARGE_INTEGER EndOfFile)
	{
		if (m_hFile) __debugbreak();

		//DbgPrint("<%p>eof=%I64x\n", this, EndOfFile->QuadPart);

		HANDLE hFile;
		IO_STATUS_BLOCK iosb;
		NTSTATUS status = NtCreateFile(&hFile, DELETE|FILE_GENERIC_READ|FILE_GENERIC_WRITE&~FILE_APPEND_DATA, poa, &iosb,
			EndOfFile, 0, FILE_SHARE_VALID_FLAGS, FILE_OVERWRITE_IF, 
			FILE_NON_DIRECTORY_FILE|FILE_NO_INTERMEDIATE_BUFFERING, 0, 0);

		if (0 > status)
		{
			return status;
		}

		_ByteOffset.QuadPart = 0;
		_EndOfFile.QuadPart = EndOfFile->QuadPart;

		static USHORT cmp = COMPRESSION_FORMAT_NONE;
		if (NtFsControlFile(hFile, 0, 0, 0, &iosb, FSCTL_SET_COMPRESSION, &cmp, sizeof(cmp), 0, 0) == STATUS_PENDING)
		{
			WaitForSingleObject(hFile, INFINITE);
		}
		NtSetInformationFile(hFile, &iosb, EndOfFile, sizeof(*EndOfFile), FileEndOfFileInformation);
		if (0 > NtSetInformationFile(hFile, &iosb, EndOfFile, sizeof(*EndOfFile), FileValidDataLengthInformation))
		{
			//__debugbreak();
		}

		Assign(hFile);

		return NT_IRP::RtlBindIoCompletion(hFile);
	}

	BOOL OnWrite(NTSTATUS status, ULONG_PTR dwNumberOfBytesTransfered)
	{
		if (0 > status || !dwNumberOfBytesTransfered) return FALSE;

		//ULONG64 bo = _ByteOffset.QuadPart;

		_ByteOffset.QuadPart += dwNumberOfBytesTransfered;

		if (_EndOfFile.QuadPart <= _ByteOffset.QuadPart)//<
		{
			//DbgPrint("%08x:onwrite end<%p>(%08x)\n", GetCurrentThreadId(), this, dwNumberOfBytesTransfered);
			if (_EndOfFile.QuadPart < _ByteOffset.QuadPart)
			{
				IO_STATUS_BLOCK iosb;
				NtSetInformationFile(m_hFile, &iosb, &_EndOfFile, sizeof(_EndOfFile), FileEndOfFileInformation);
			}

			return TRUE;
		}

		//ULONG n = ++STAGE::get()->n;
		//DbgPrint("\n%08x.%u:+++++++++ OnWriteEnd<%p>(%08x->%I64x) +++++++++\n", GetCurrentThreadId(), n, this, dwNumberOfBytesTransfered, bo);

		_pDD->OnWriteEnd((ULONG)dwNumberOfBytesTransfered);

		//DbgPrint("%08x.%u:-------- OnWriteEnd<%p>(%08x->%I64x) ----------\n", GetCurrentThreadId(), n,
		//	this, dwNumberOfBytesTransfered, bo);

		return TRUE;
	}
private:
	void IOCompletionRoutine(CDataPacket* /*packet*/, DWORD Code, NTSTATUS status, ULONG_PTR dwNumberOfBytesTransfered, PVOID /*Pointer*/)
	{
		switch(Code)
		{
		case opWrite:
			Code = OnWrite(status, dwNumberOfBytesTransfered);
			_pDD->WriteCompleted();
			if (Code)
			{
				break;
			}
		default:
			__debugbreak();
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
	ZDllVector* _task;
	PSTR _http_head_buffer;//e_http_head_max_size
	HANDLE _hRoot;
	HWND _hwnd;
	CFileWriter* _pFileWriter;
	WSABUF _Buffers[2];
	DWORD _dwBufferCount;
	ULONG _dwHeadSize;
	ULONG _dwNumberOfBytesRead;
	ULONG _ip, _dwGetSize;
	DWORD _id, _n;
	INTERNET_PORT _nPort;
	short _nEnd;
	char _state;
	BOOLEAN _bHandshakeDone, _bSSL, _bRead, _bRedirected;
private:

	void DoEnd()
	{
		if (!_InterlockedDecrement16(&_nEnd))
		{
			_pFileWriter->Cleanup();
			Next();
		}
	}

	virtual void WriteBegin() 
	{
		AddRef();
		_InterlockedIncrement16(&_nEnd);
	}

	virtual void WriteCompleted() 
	{
		DoEnd();
		Release();
	}

	virtual void OnWriteError() 
	{
		Disconnect();
	}

	virtual void WriteFrom(PFILE_SEGMENT_ELEMENT SegmentArray, ULONG Len)
	{
		DbgPrint("%08x.%u:WriteFrom<%p>(%x)\n", GetCurrentThreadId(), STAGE::get()->n, this, Len);
		_pFileWriter->Write(SegmentArray, Len);
	}

	virtual ULONG GetRecvBuffers(WSABUF lpBuffers[2], void** ppv)
	{
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

		DbgPrint("%08x.%u:GetRecvBuffers(%x, %x, %x)\n", GetCurrentThreadId(), STAGE::get()->n, data_size, len, m_packet->getFreeSize());

		return 1;
	}

	virtual BOOL OnRecv(PSTR Buf, ULONG cbTransferred)
	{
		_dwNumberOfBytesRead = 0;

		if (_state) __debugbreak();

		//ULONG n = ++STAGE::get()->n;

		//DbgPrint("\n%08x.%u:OnRecv begin(%x)\n", GetCurrentThreadId(), n, cbTransferred);

		BOOL f = _bSSL ? OnData(Buf, cbTransferred) : OnUserData(Buf, cbTransferred);

		if (_dwNumberOfBytesRead)
		{
			DbgPrint("%08x.%u: ++++ OnRecv:OnReadEnd(%x)\n", GetCurrentThreadId(), n, _dwNumberOfBytesRead);

			OnReadEnd(_dwNumberOfBytesRead);
			// -> ReadTo() can be called from here

			DbgPrint("%08x.%u: ---- OnRecv:OnReadEnd(%x)\n", GetCurrentThreadId(), n, _dwNumberOfBytesRead);

			if (!_bSSL)
			{
				return _bRead ? -1 : 0;
			}

			char state = _InterlockedExchangeAdd8(&_state, -1);

			//DbgPrint("%08x.%u:OnRecv end[%d]\n", GetCurrentThreadId(), n, state);

			if (f)
			{
				switch (state)
				{
				case 0:
					return -1;
				case 1:
					return +1;
				default:
					__debugbreak();
					return 0;
				}
			}
		}

		return f;
	}

	virtual void ReadTo(WSABUF* lpBuffers, DWORD dwBufferCount)
	{
		if (_bSSL)
		{
			_dwBufferCount = dwBufferCount;
			memcpy(_Buffers, lpBuffers, dwBufferCount * sizeof(WSABUF));

			char state = _InterlockedExchangeAdd8(&_state, +1);

			//DbgPrint("%08x.%u:ReadTo(%d) [%x], (%p,%x)\n%c\t(%p,%x)\n", 
			//	GetCurrentThreadId(), STAGE::get()->n, state, dwBufferCount,
			//	lpBuffers->buf, lpBuffers->len, dwBufferCount == 1 ? 0 : ' ',
			//	lpBuffers[1].buf, lpBuffers[1].len);

			switch (state)
			{
			case -1:
				Recv();
			case 0:
				break;
			default:
				__debugbreak();
			}
		}
		else
		{
			if (_bRead)
			{
				//DbgPrint("%08x.%u:ReadTo [%x], (%p,%x)\n%c\t(%p,%x)\n", 
				//	GetCurrentThreadId(), STAGE::get()->n, dwBufferCount,
				//	lpBuffers->buf, lpBuffers->len, dwBufferCount == 1 ? 0 : ' ',
				//	lpBuffers[1].buf, lpBuffers[1].len);

				Recv(lpBuffers, dwBufferCount, getBuffer());
			}
			//else
			//{
			//	DbgPrint("readto:__nop()\n");
			//}
		}
	}

	virtual ULONG GetReadMinSize() 
	{ 
		return _bSSL ? getMaximumMessage() : 1; 
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
		if (!_bRedirected)
		{
			PostMessage(_hwnd, e_disconnect, _id, _pFileWriter->IsCreated() && !_cbBytesNeed.QuadPart);
		}
		//DbgPrint("%08x:%s<%p> [%u]\n", GetCurrentThreadId(), __FUNCTION__, this, GetTickCount());

		StopSSL();

		DoEnd();
	}

	virtual BOOL OnConnect(ULONG dwError)
	{
		_dwHeadSize = 0;
		PostMessage(_hwnd, e_connect, _id, dwError);

		return dwError ? (Next(), FALSE) : (_nEnd = 1, _bSSL) ? StartSSL() : OnEndHandshake();
	}

	virtual ULONG GetConnectData(void** ppSendBuffer)
	{
		if (_bSSL)
		{
			return 0;
		}

		*ppSendBuffer = getBuffer();

		return _dwGetSize;
	}

	virtual BOOL OnEndHandshake()
	{
		//DbgPrint("%s<%p>\n", __FUNCTION__, this);

		_bHandshakeDone = TRUE;
		CyclicBuferEx::Start();
		_state = 0;

		return _bSSL ? !SendUserData(getBuffer(), _dwGetSize) : -1;
	}

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
									PSTR buf = (PSTR)alloca(uc.dwUrlPathLength+uc.dwHostNameLength+2);
									sprintf(buf, "%.*s%c%.*s", 
										uc.dwHostNameLength, uc.lpszHostName, 0, uc.dwUrlPathLength, uc.lpszUrlPath);
									_bRedirected = TRUE;
									FormatRequest(buf, buf + uc.dwHostNameLength+1);
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
		DbgPrint("%08x.%u:OnUD(%p, %x)\n", GetCurrentThreadId(), STAGE::get()->n, Buf, cbTransferred);

		ULONG cb = 0, len, dwBufferCount, cbReaded = 0;

		if (!_cbBytesNeed.QuadPart)
		{
//#undef DbgPrint

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
					return FALSE;
				}

				PostMessage(_hwnd, e_length, _id, _cbBytesNeed.LowPart);

				DbgPrint("head size=%x, data size=%x(%x)\n", cb, cbTransferred, cbTransferred - cb);

				if (!(cbTransferred -= cb))
				{
					if (!_bSSL) Start();
					return TRUE;
				}

				Buf += cb;

				if (!_bSSL)
				{
					memcpy(getBuffer(), Buf, cbTransferred);
				}
			}
			else
			{
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
//#define DbgPrint /##/
		}

		if (_bSSL)
		{
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

			if (cbTransferred)
			{
				__debugbreak();
			}
		}
		else
		{
			cbReaded = cbTransferred;
		}

		DbgPrint("%08x.%u:OnUserData(%x)\n", GetCurrentThreadId(), STAGE::get()->n, cbReaded);

		if (cbReaded)
		{
			_dwNumberOfBytesRead += cbReaded;

			if (0 >= (_cbBytesNeed.QuadPart -= cbReaded))
			{
				_bRead = FALSE;
				//DbgPrint("%08x.%u:read end (%u)\n", GetCurrentThreadId(), STAGE::get()->n);
				// read end
				ULONG PageSize = getPageSize();
				_dwNumberOfBytesRead += (PageSize - (getDataSize() + _dwNumberOfBytesRead)) & (PageSize - 1);
				DbgPrint("%08x.%u:OnUserData-end(%x)\n", GetCurrentThreadId(), STAGE::get()->n, cbReaded);
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
		if (ip)
		{
			if (ULONG err = Connect(ip, _nPort))
			{
				PostMessage(_hwnd, e_connect, _id, err);
			}
		}
		else
		{
			PostMessage(_hwnd, e_connect, _id, ERROR_NOT_FOUND);
			Next();
		}
	}

	~CFileDownloadS()
	{
		DbgPrint("%08x:%s<%p>\n", GetCurrentThreadId(), __FUNCTION__, this);
		_bRedirected = FALSE;
		Cleanup();

		if (_pFileWriter)
		{
			_pFileWriter->Release();
		}

		if (_http_head_buffer)
		{
			delete [] _http_head_buffer;
		}
		_task->DecActive();
		_task->Release();
	}

	void Cleanup()
	{
		CyclicBufer::Init();
		_cbBytesNeed.QuadPart = 0;
		_bHandshakeDone = FALSE, _bRead = TRUE, _state = 0;

		_dwBufferCount = 0;
		_dwNumberOfBytesRead = 0;
		_dwHeadSize = 0;

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

	void FormatRequest(PCSTR lpszHostName, PCSTR lpszUrlPath)
	{
		PSTR buf = (char*)getBuffer();
		_dwGetSize = sprintf(buf, 
			"GET %s HTTP/1.1\r\n"
			"Host: %s\r\n"
			"User-Agent: Microsoft-Symbol-Server/10.0.0.0\r\n"
			"Connection: Close\r\n"
			"\r\n", lpszUrlPath, lpszHostName);

		strcpy(buf + _dwGetSize, lpszHostName);
	}
public:

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
				DnsToIp((char*)getBuffer() + _dwGetSize);
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
	}

	CFileDownloadS(ZDllVector* task) : CSSLEndpoint(task->getCred())
	{
		DbgPrint("%s<%p>\n", __FUNCTION__, this);
		_bRedirected = FALSE;
		_pFileWriter = 0;
		_FileName = 0;
		_http_head_buffer = 0;
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

		if (0 > status)
		{
			return status;
		}

		oa.RootDirectory = hRoot;

		RtlInitUnicodeString(&ObjectName, sz);

		status = NtCreateFile(&_hRoot, FILE_ADD_SUBDIRECTORY|SYNCHRONIZE, &oa, &iosb, 0, 
			0, FILE_SHARE_VALID_FLAGS, FILE_OPEN_IF, FILE_DIRECTORY_FILE, 0, 0);

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

		PSTR buf = (char*)getBuffer();

		_dwGetSize = sprintf(buf, 
			httpHeader,
			PdbFileName, Signature->Data1, Signature->Data2, Signature->Data3,
			Signature->Data4[0], Signature->Data4[1], Signature->Data4[2], Signature->Data4[3], 
			Signature->Data4[4], Signature->Data4[5], Signature->Data4[6], Signature->Data4[7], Age, PdbFileName);

		DbgPrint(buf);

		return status;
	}

	ULONG Create()
	{
		if (!(_pFileWriter = new CFileWriter(this)))
		{
			return ERROR_NO_SYSTEM_RESOURCES;
		}

		if (ULONG dwError = CTcpEndpoint::Create(0x10000))
		{
			return dwError;
		}

		return CyclicBufer::Create();
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
			dwError = p->Connect(task->get_ip(), 0x5000);
		}

		p->Release();
	}

	return dwError;
}

_NT_END