#include "StdAfx.h"

_NT_BEGIN

#include "../inc/rtlframe.h"

struct _EF
{
	HANDLE InheritFromProcessHandle;
};
NTSTATUS MyOpenProcess(PHANDLE ProcessHandle, ULONG DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID Cid);

typedef RTL_FRAME<_EF> EF;

LONG vex(::PEXCEPTION_POINTERS ExceptionInfo)
{
	::PEXCEPTION_RECORD ExceptionRecord = ExceptionInfo->ExceptionRecord;

	if (ExceptionRecord->ExceptionCode != STATUS_SINGLE_STEP) return EXCEPTION_CONTINUE_SEARCH;

	PVOID ExceptionAddress = ExceptionRecord->ExceptionAddress;

	if ((ExceptionAddress != ZwCreateProcessEx) && (ExceptionAddress != ZwCreateProcess)) return EXCEPTION_CONTINUE_SEARCH;

	if (EF* prf = EF::get())
	{
		::_CONTEXT* ContextRecord = ExceptionInfo->ContextRecord;

#ifdef _WIN64 
		ContextRecord->R9
#else
		((PULONG_PTR)ContextRecord->Esp)[4]
#endif
			 = (ULONG_PTR)prf->InheritFromProcessHandle;

		ContextRecord->EFlags |= RESUME_FLAG;
		ContextRecord->Dr7 = 0;
		ContextRecord->Dr3 = 0;
		ContextRecord->Dr2 = 0;
		ContextRecord->ContextFlags |= CONTEXT_DEBUG_REGISTERS;
	}

	return EXCEPTION_CONTINUE_EXECUTION;
}

extern OBJECT_ATTRIBUTES zoa;

NTSTATUS XpCreateProcess(PCWSTR lpApplicationName, 
						 PWSTR lpCommandLine, 
						 DWORD dwCreationFlags, 
						 PVOID lpEnvironment, 
						 PCWSTR lpCurrentDirectory, 
						 PWSTR  lpDesktop,
						 HANDLE UniqueProcessId,
						 PPROCESS_INFORMATION lpProcessInformation)
{
	if (PVOID p = RtlAddVectoredExceptionHandler(TRUE, vex))
	{
		CONTEXT cntx = {};
		cntx.ContextFlags = CONTEXT_DEBUG_REGISTERS;

		cntx.Dr2 = (ULONG_PTR)ZwCreateProcess;
		cntx.Dr3 = (ULONG_PTR)ZwCreateProcessEx;
		cntx.Dr7 = 0x450;

		NTSTATUS status = ZwSetContextThread(NtCurrentThread(), &cntx);
		if (0 <= status)
		{
			CLIENT_ID cid = { UniqueProcessId };
			EF rf;

			if (0 <= (status = MyOpenProcess(&rf.InheritFromProcessHandle, PROCESS_CREATE_PROCESS, &zoa, &cid)))
			{
				STARTUPINFO si = { sizeof(si), 0, lpDesktop };

				status = CreateProcessW(lpApplicationName, lpCommandLine, 0, 0, 0, dwCreationFlags, lpEnvironment, lpCurrentDirectory, &si, lpProcessInformation) ? STATUS_SUCCESS : RtlGetLastNtStatus();
				
				NtClose(rf.InheritFromProcessHandle);
			}

			cntx.Dr2 = 0;
			cntx.Dr3 = 0;
			cntx.Dr7 = 0x400;
			ZwSetContextThread(NtCurrentThread(), &cntx);
		}

		RtlRemoveVectoredExceptionHandler(p);

		return status;
	}

	return STATUS_INSUFFICIENT_RESOURCES;
}

_NT_END