#pragma once

class WorkQueue 
{
	HANDLE _hIOCP;
	HANDLE _hEvent;
	LONG _NumberOfThreads;

public:

	typedef VOID (NTAPI *PWORK_ROUTINE)(PVOID Context, NTSTATUS Status, ULONG_PTR Information);

	WorkQueue();

	~WorkQueue();

	void DecrementThreadCount();

	void WorkThread();

	static DWORD CALLBACK _WorkThread(PVOID pThis);

	BOOL Init();

	BOOL push(PWORK_ROUTINE func, PVOID Context, NTSTATUS Status, ULONG_PTR Information);

	NTSTATUS Stop(BOOL bWait, PLARGE_INTEGER Timeout = 0);

	NTSTATUS Wait(PLARGE_INTEGER Timeout = 0);
};
