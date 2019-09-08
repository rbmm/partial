#include "StdAfx.h"

_NT_BEGIN

#include "Queue.h"

WorkQueue::WorkQueue()
{
	_hIOCP = 0;
	_NumberOfThreads = 0;
	_hEvent = 0;
}

WorkQueue::~WorkQueue()
{
	if (_hIOCP)
	{
		NtClose(_hIOCP);
	}

	if (_hEvent)
	{
		NtClose(_hEvent);
	}
}

void WorkQueue::DecrementThreadCount()
{
	if (!InterlockedDecrement(&_NumberOfThreads))
	{
		DbgPrint("-- WorkQueue::stopped --\n");
		ZwSetEvent(_hEvent, 0);
	}
}

void WorkQueue::WorkThread()
{
	HANDLE hIOCP = _hIOCP;
	IO_STATUS_BLOCK iosb;
	PVOID Context;
	PWORK_ROUTINE func;

	for (;;)
	{
		switch (ZwRemoveIoCompletion(hIOCP, (void**)&func, (void**)&Context, &iosb, 0))
		{
		case STATUS_SUCCESS:
			if (func) 
			{
				func(Context, iosb.Status, iosb.Information);
				continue;
			}
			else
			{
		case STATUS_ABANDONED:
				DecrementThreadCount();
				return;
			}
		}
		// ??
		__debugbreak();
	}
}

DWORD CALLBACK WorkQueue::_WorkThread(PVOID pThis)
{
	((WorkQueue*)pThis)->WorkThread();
	FreeLibraryAndExitThread((HMODULE)&__ImageBase, 0);
}

BOOL WorkQueue::Init()
{
	SYSTEM_BASIC_INFORMATION sbi;

	static OBJECT_ATTRIBUTES zoa = { sizeof(zoa) };

	_NumberOfThreads = 1;

	if (0 <= ZwCreateEvent(&_hEvent, EVENT_ALL_ACCESS, 0, NotificationEvent, FALSE) &&
		0 <= ZwQuerySystemInformation(SystemBasicInformation, &sbi, sizeof sbi, 0) && 
		0 <= ZwCreateIoCompletion(&_hIOCP, IO_COMPLETION_ALL_ACCESS, &zoa, sbi.NumberOfProcessors))
	{
		do 
		{
			LdrAddRefDll(0, (HMODULE)&__ImageBase);
			InterlockedIncrement(&_NumberOfThreads);

			if (HANDLE hThread = CreateThread(0, 0, _WorkThread, this, 0, 0))
			{
				NtClose(hThread);
			}
			else
			{
				InterlockedDecrement(&_NumberOfThreads);
				FreeLibrary((HMODULE)&__ImageBase);
			}
		} while (--sbi.NumberOfProcessors);
	}

	DecrementThreadCount();

	return _NumberOfThreads;
}

BOOL WorkQueue::push(PWORK_ROUTINE func, PVOID Context, NTSTATUS Status, ULONG_PTR Information)
{
	return 0 <= ZwSetIoCompletion(_hIOCP, func, Context, Status, Information);
}

NTSTATUS WorkQueue::Stop(BOOL bWait, PLARGE_INTEGER Timeout)
{
	if (LONG n = _NumberOfThreads)
	{
		do 
		{
			ZwSetIoCompletion(_hIOCP, 0, 0, 0, 0);
		} while (--n);
	}

	NTSTATUS status = STATUS_PENDING;

	if (bWait)
	{
		status = Wait(Timeout); 
	}

	return status;
}

NTSTATUS WorkQueue::Wait(PLARGE_INTEGER Timeout /*= 0*/)
{
	// _hEvent will be set in DecrementThreadCount(), when last thread exit
	return ZwWaitForSingleObject(_hEvent, FALSE, Timeout);
}

_NT_END