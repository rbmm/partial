#pragma once

#include "common.h"

class __declspec(novtable) ZDllVector
{
	CTcpEndpoint* _vec[8];
	SharedCred* _Cred;
	PULONG _offsets;
	ULONG _N, _ip;
	LONG _n, _id, _ActiveCount;
	BOOLEAN _bSingle, _bStop;

protected:

	ZDllVector(SharedCred* Cred) : _Cred(Cred)
	{
		_offsets = 0, _n = 0, _N = 0, _ip = 0;
		RtlZeroMemory(_vec, sizeof(_vec));
		Cred->AddRef();
	}

	~ZDllVector()
	{
		if (_offsets)
		{
			delete _offsets;
		}
		_Cred->Release();
	}

	void Init(PULONG offsets, ULONG N)
	{
		if (_offsets)
		{
			delete _offsets;
		}
		_offsets = offsets, _N = N, _n = N;
	}

	void Reset()
	{
		_id = 0, _ActiveCount = 1, _bSingle = FALSE, _bStop = FALSE;
	}

	void Single()
	{
		_n = 0, _bSingle = TRUE;
	}

	void set_ip(ULONG ip)
	{
		_ip = ip;
	}

	void Stop(ULONG i, BOOL bClose)
	{
		if (CTcpEndpoint* p = (CTcpEndpoint*)InterlockedExchangePointer((void**)&_vec[i], 0))
		{
			if (bClose)
			{
				p->Close();
			}
			p->Release();
		}
	}

	void StopAll()
	{
		_bStop = TRUE;
		int i = 8;
		do 
		{
			Stop(--i, TRUE);
		} while (i);
	}

	ULONG GetDllCount()
	{
		return _N;
	}

public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual HANDLE get_Root() = 0;
	virtual HWND get_HWND() = 0;

	void IncActive()
	{
		InterlockedIncrement(&_ActiveCount);
	}

	void DecActive()
	{
		if (!InterlockedDecrement(&_ActiveCount))
		{
			PostMessage(get_HWND(), e_stop, 0, 0);
		}
	}

	ULONG get_ID()
	{
		return InterlockedIncrement(&_id) - 1;
	}

	ULONG get_ip()
	{
		return _ip;
	}

	PCSTR GetName(LONG n)
	{
		return 0 > n ? 0 : reinterpret_cast<CNT_MODULE_INFORMATION*>(RtlOffsetToPointer(_offsets, _offsets[n]))->FullPathName;
	}

	PCSTR GetNextName(PLONG pn)
	{
		LONG n = InterlockedDecrement(&_n);
		*pn = n;
		return GetName(n);
	}

	void Register(CTcpEndpoint* p, ULONG i)
	{
		_vec[i] = p;
		p->AddRef();
	}

	void Unregister(ULONG i)
	{
		Stop(i, FALSE);
	}

	BOOLEAN IsSingle()
	{
		return _bSingle;
	}

	BOOLEAN IsStop()
	{
		return _bStop;
	}

	SharedCred* getCred()
	{
		return _Cred;
	}
};

struct SDP 
{
	ZDllVector* task;
	union {
		PWSTR DllFileName;
		struct  
		{
			GUID Signature; 
			PSTR PdbFileName; 
			DWORD Age;
		};
	};
	enum { e_path, e_sign} type;
};

ULONG CreateSingleDownload(SDP* params);