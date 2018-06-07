#include "stdafx.h"
#include "common.h"

_NT_BEGIN

struct EXCEPT_FRAME : public RTLFRAME 
{
	HANDLE InheritFromProcessHandle;
};

LONG  OnSingleStep(::PEXCEPTION_POINTERS ExceptionInfo)
{
	::PEXCEPTION_RECORD ExceptionRecord = ExceptionInfo->ExceptionRecord;

	if (ExceptionRecord->ExceptionCode != STATUS_SINGLE_STEP)
		return EXCEPTION_CONTINUE_SEARCH;

	LPVOID ExceptionAddress = ExceptionRecord->ExceptionAddress;

	if ((ExceptionAddress != ZwCreateProcessEx) &&
		(ExceptionAddress != ZwCreateProcess)) 
		return EXCEPTION_CONTINUE_SEARCH;

	RTLFRAME* prf = RtlGetFrame();
	while (prf) if (prf->UserData == OnSingleStep) break;
	if (!prf) return EXCEPTION_CONTINUE_SEARCH;

	::_CONTEXT* ContextRecord = ExceptionInfo->ContextRecord;

#if defined(_X86_) 
	((HANDLE*)(DWORD_PTR)ContextRecord->Esp)[4] = 
		static_cast<EXCEPT_FRAME*>(prf)->InheritFromProcessHandle;
#elif defined(_AMD64_)
	ContextRecord->R9 = (DWORD_PTR)
		static_cast<EXCEPT_FRAME*>(prf)->InheritFromProcessHandle;
#else
#error 
#endif

	static_cast<EXCEPT_FRAME*>(prf)->InheritFromProcessHandle = 0;
	ContextRecord->Dr7 = 0;
	ContextRecord->Dr3 = 0;
	ContextRecord->Dr2 = 0;
	ULONG ContextFlags = ContextRecord->ContextFlags;
	ContextRecord->ContextFlags = CONTEXT_DEBUG_REGISTERS;
	SetThreadContext(NtCurrentThread(), ContextRecord);
	ContextRecord->ContextFlags = ContextFlags;
	return EXCEPTION_CONTINUE_EXECUTION;
}

BOOL CreateProcessWithShim
(
 IN LPCWSTR lpApplicationName, 
 IN LPWSTR lpCommandLine, 
 IN LPSECURITY_ATTRIBUTES lpProcessAttributes, 
 IN LPSECURITY_ATTRIBUTES lpThreadAttributes, 
 IN BOOL bInheritHandles, 
 IN DWORD dwCreationFlags, 
 IN LPVOID lpEnvironment, 
 IN LPCWSTR lpCurrentDirectory, 
 IN LPSTARTUPINFOW lpStartupInfo, 
 OUT LPPROCESS_INFORMATION lpProcessInformation,
 LPCWSTR lpShimDll,
 LPCVOID lpExtraData,
 DWORD cbExtraData,
 HANDLE InheritFromProcessHandle
 )
{
	EXCEPT_FRAME ef;
	LPVOID p = 0;
	::_CONTEXT cntx;
	RtlZeroMemory(&cntx, sizeof cntx);
	cntx.ContextFlags = CONTEXT_DEBUG_REGISTERS;

	ef.InheritFromProcessHandle = 0;

	if (InheritFromProcessHandle != NtCurrentProcess()) {

		p = AddVectoredExceptionHandler(TRUE, OnSingleStep);
		if (!p) return FALSE;

		cntx.Dr2 = 
#ifdef _X86_
			(DWORD)
#endif
			(DWORD_PTR)ZwCreateProcess;
		cntx.Dr3 = 
#ifdef _X86_
			(DWORD)
#endif
			(DWORD_PTR)ZwCreateProcessEx;
		cntx.Dr7 = 0x50;

		if (!SetThreadContext(NtCurrentThread(), &cntx)) {
			RemoveVectoredExceptionHandler(p);
			return FALSE;
		}

		ef.InheritFromProcessHandle = InheritFromProcessHandle;
		RtlPushFrame(&ef);
		ef.UserData = OnSingleStep;
	}

	BOOL fOk = CreateProcessW(lpApplicationName, lpCommandLine,
		lpProcessAttributes, lpThreadAttributes, bInheritHandles,
		dwCreationFlags | (lpShimDll ? CREATE_SUSPENDED : 0), 
		lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);

	if (p) {
		if (ef.InheritFromProcessHandle) {
			cntx.Dr7 = cntx.Dr2 = cntx.Dr3 = 0;
			SetThreadContext(NtCurrentThread(), &cntx);
		}
		RtlPopFrame(&ef);
		RemoveVectoredExceptionHandler(p);
	}

	if (!fOk) return FALSE;
	if (!lpShimDll) return TRUE;

	DWORD nameLen = ((DWORD)wcslen(lpShimDll) + 1) << 1;
	DWORD cb = (nameLen + 15) & ~15;

	HANDLE hProcess = lpProcessInformation->hProcess;
	HANDLE hThread = lpProcessInformation->hThread;

	LPBYTE lpb;
	PROCESS_BASIC_INFORMATION pbi;

	if (ef.InheritFromProcessHandle ||
		(0 > ZwQueryInformationProcess(hProcess, ProcessBasicInformation, &pbi, sizeof pbi, 0)) ||
		!(lpb = (LPBYTE)VirtualAllocEx(hProcess, 0, cbExtraData + cb, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE)) ||
		(0 > ZwWriteVirtualMemory(hProcess, lpb, (LPVOID)lpShimDll, nameLen, 0)) ||
		(0 > ZwWriteVirtualMemory(hProcess, lpb + cb, (LPVOID)lpExtraData, cbExtraData, 0)) ||
		(0 > ZwWriteVirtualMemory(hProcess, &((_PEB*)pbi.PebBaseAddress)->pShimData, &lpb,sizeof LPVOID, 0))) 
	{

		TerminateThread(hThread, STATUS_ABANDONED);
		ZwClose(hThread);
		ZwClose(hProcess);
		RtlZeroMemory(lpProcessInformation, sizeof PROCESS_INFORMATION);
		return FALSE;
	}

	if (!(dwCreationFlags & CREATE_SUSPENDED)) ResumeThread(hThread);

	return TRUE;
}

BOOL CreateProcessWithShim
(
 IN LPCWSTR lpApplicationName, 
 IN LPWSTR lpCommandLine, 
 IN LPSECURITY_ATTRIBUTES lpProcessAttributes, 
 IN LPSECURITY_ATTRIBUTES lpThreadAttributes, 
 IN BOOL bInheritHandles, 
 IN DWORD dwCreationFlags, 
 IN LPVOID lpEnvironment, 
 IN LPCWSTR lpCurrentDirectory, 
 IN LPSTARTUPINFOW lpStartupInfo, 
 OUT LPPROCESS_INFORMATION lpProcessInformation,
 LPCWSTR lpShimDll,
 LPCVOID lpExtraData,
 DWORD cbExtraData,
 DWORD_PTR InheritFromProcessId
 )
{
	HANDLE InheritFromProcessHandle = NtCurrentProcess();

	if (InheritFromProcessId != GetCurrentProcessId()) {

		OBJECT_ATTRIBUTES oa = { sizeof oa };

		CLIENT_ID cid = { (HANDLE)InheritFromProcessId };

		if (0 > ZwOpenProcess(&InheritFromProcessHandle, 
			PROCESS_CREATE_PROCESS, &oa, &cid)) return FALSE;
	}

	BOOL b = CreateProcessWithShim(lpApplicationName, lpCommandLine,
		lpProcessAttributes, lpThreadAttributes, bInheritHandles,
		dwCreationFlags, lpEnvironment, lpCurrentDirectory,
		lpStartupInfo, lpProcessInformation, lpShimDll, lpExtraData,
		cbExtraData, InheritFromProcessHandle);

	if (InheritFromProcessHandle != NtCurrentProcess())
		ZwClose(InheritFromProcessHandle);

	return b;
}

_NT_END