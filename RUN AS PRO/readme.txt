#define LAA(se) {{se},SE_PRIVILEGE_ENABLED|SE_PRIVILEGE_ENABLED_BY_DEFAULT}

#define BEGIN_PRIVILEGES(tp, n) static const struct {ULONG PrivilegeCount;LUID_AND_ATTRIBUTES Privileges[n];} tp = {n,{
#define END_PRIVILEGES }};

BOOL AdjustPrivileges()
{
	BOOL f = FALSE;
	HANDLE hToken;
	if (0 <= NtOpenProcessToken(NtCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
	{
		BEGIN_PRIVILEGES(tp, 2)
			LAA(SE_DEBUG_PRIVILEGE),
			LAA(SE_LOAD_DRIVER_PRIVILEGE)
			END_PRIVILEGES	
			f = (STATUS_SUCCESS == ZwAdjustPrivilegesToken(hToken, FALSE, (PTOKEN_PRIVILEGES)&tp, 0, 0, 0));
		NtClose(hToken);
	}
	return f;
}
static OBJECT_ATTRIBUTES zoa = { sizeof zoa };

NTSTATUS GetSystemToken(PBYTE buf, PHANDLE phSysToken)
{
	NTSTATUS status;

	union {
		PBYTE pb;
		PSYSTEM_PROCESS_INFORMATION pspi;
	};

	pb = buf;
	ULONG NextEntryOffset = 0;

	do 
	{
		pb += NextEntryOffset;

		HANDLE hProcess, hToken, hNewToken;

		if (pspi->InheritedFromUniqueProcessId && pspi->UniqueProcessId && pspi->NumberOfThreads)
		{
			static SECURITY_QUALITY_OF_SERVICE sqos = {
				sizeof sqos, SecurityImpersonation, SECURITY_DYNAMIC_TRACKING, FALSE
			};

			static OBJECT_ATTRIBUTES soa = { sizeof(soa), 0, 0, 0, 0, &sqos };

			if (0 <= NtOpenProcess(&hProcess, PROCESS_QUERY_LIMITED_INFORMATION, &zoa, &pspi->TH->ClientId))
			{
				status = NtOpenProcessToken(hProcess, TOKEN_DUPLICATE, &hToken);

				NtClose(hProcess);

				if (0 <= status)
				{
					status = NtDuplicateToken(hToken, TOKEN_ADJUST_PRIVILEGES|TOKEN_IMPERSONATE, 
						&soa, FALSE, TokenImpersonation, &hNewToken);

					NtClose(hToken);

					goto __v;
				}
			}

			if (0 <= ZwOpenThread(&hProcess, THREAD_DIRECT_IMPERSONATION, &zoa, &pspi->TH->ClientId))
			{
				status = ZwImpersonateThread(NtCurrentThread(), hProcess, &sqos);

				NtClose(hProcess);

				if (0 <= status)
				{
					status = NtOpenThreadTokenEx(NtCurrentThread(), TOKEN_ADJUST_PRIVILEGES|TOKEN_IMPERSONATE,
						FALSE, 0, &hNewToken);

					NtSetInformationThread(NtCurrentThread(), ThreadImpersonationToken, &(hToken = 0), sizeof(hToken));

					goto __v;
				}
			}

			continue;

__v:
			if (0 <= status)
			{
				BEGIN_PRIVILEGES(tp, 4)
					LAA(SE_TCB_PRIVILEGE),
					LAA(SE_DEBUG_PRIVILEGE),
					LAA(SE_INCREASE_QUOTA_PRIVILEGE),
					LAA(SE_ASSIGNPRIMARYTOKEN_PRIVILEGE),
					END_PRIVILEGES	

					if (STATUS_SUCCESS == NtAdjustPrivilegesToken(hNewToken, FALSE, (PTOKEN_PRIVILEGES)&tp, 0, 0, 0))	
					{
						*phSysToken = hNewToken;
						return STATUS_SUCCESS;
					}

					NtClose(hNewToken);
			}
		}

	} while (NextEntryOffset = pspi->NextEntryOffset);

	return STATUS_UNSUCCESSFUL;
}
NTSTATUS SetLowLevel(HANDLE hToken)
{
	TOKEN_MANDATORY_LABEL tml = { { alloca(GetSidLengthRequired(1)), SE_GROUP_INTEGRITY|SE_GROUP_INTEGRITY_ENABLED } };
	static SID_IDENTIFIER_AUTHORITY LabelAuthority = SECURITY_MANDATORY_LABEL_AUTHORITY;
	InitializeSid(tml.Label.Sid, &LabelAuthority, 1);
	*GetSidSubAuthority(tml.Label.Sid, 0) = SECURITY_MANDATORY_LOW_RID;
	return ZwSetInformationToken(hToken, TokenIntegrityLevel, &tml, sizeof(tml));
}

NTSTATUS GetLastNtStatus(BOOL fOk)
{
	if (fOk) return STATUS_SUCCESS;
	NTSTATUS status = RtlGetLastNtStatus();
	ULONG dwError = GetLastError();
	return RtlNtStatusToDosErrorNoTeb(status) == dwError ? status : 0x80000000|(FACILITY_WIN32 << 16)|dwError;
}


NTSTATUS test(HANDLE hProcess, STARTUPINFOEXW* psi)
{
	PROCESS_INFORMATION pi;
	HANDLE hToken, hMyToken;


	NTSTATUS status;
	PVOID stack = alloca(guz);
	ULONG cb = 0, rcb = 0x100;

	SECURITY_ATTRIBUTES sa = { sizeof(sa) };

	// for SECURITY_DESCRIPTOR of new process/thread
	do 
	{
		if (cb < rcb)
		{
			cb = RtlPointerToOffset(sa.lpSecurityDescriptor = alloca(rcb - cb), stack);
		}

		// set security descriptor for a process same as parent process security descriptor
		// otherwise it will be come from the primary token of the creator

		// hProcess need READ_CONTROL
		if (0 <= (status = NtQuerySecurityObject(hProcess, DACL_SECURITY_INFORMATION|LABEL_SECURITY_INFORMATION|
			OWNER_SECURITY_INFORMATION|GROUP_SECURITY_INFORMATION, sa.lpSecurityDescriptor, cb, &rcb)))
		{
			// set Low Intergity label
			PACL Label;
			BOOLEAN bPresent, bDefault;
			if (0 <= RtlGetSaclSecurityDescriptor(sa.lpSecurityDescriptor, &bPresent, &Label, &bDefault))
			{
				ULONG AceCount;
				if (Label && (AceCount = Label->AceCount))
				{
					union {
						PBYTE pb;
						PVOID pv;
						PACE_HEADER pah;
						PSYSTEM_MANDATORY_LABEL_ACE psmla;
					};

					pv = Label + 1;
					do 
					{
						if (pah->AceType == SYSTEM_MANDATORY_LABEL_ACE_TYPE)
						{
							_SID* Sid = (_SID*)&psmla->SidStart;
							if (Sid->SubAuthorityCount == 1)
							{
								Sid->SubAuthority[0] = SECURITY_MANDATORY_LOW_RID;
							}
							break;
						}

					} while (pb += pah->AceSize, --AceCount);
				}
			}

			break;
		}

	} while (status == STATUS_BUFFER_TOO_SMALL);

	if (0 > status)
	{
		return status;
	}

	// the security descriptor for a process token come 
	// from the primary or impersonation token of the creator
	// so set impersonation token for creator (current thread)
	// based on parent process primary token

	// hProcess need PROCESS_QUERY_LIMITED_INFORMATION
	if (0 <= (status = NtOpenProcessToken(hProcess, TOKEN_DUPLICATE, &hToken)))
	{
		static SECURITY_QUALITY_OF_SERVICE sqos = { sizeof(sqos), SecurityImpersonation, SECURITY_DYNAMIC_TRACKING };
		static OBJECT_ATTRIBUTES oa = { sizeof(oa), 0, 0, 0, 0, &sqos };

		status = NtDuplicateToken(hToken, TOKEN_ADJUST_DEFAULT|TOKEN_IMPERSONATE, 
			&oa, FALSE, TokenImpersonation, &hMyToken);

		NtClose(hToken);

		if (0 <= status)
		{
			// need TOKEN_ADJUST_DEFAULT
			if (0 <= (status = SetLowLevel(hMyToken)))
			{
				// need TOKEN_IMPERSONATE
				status = NtSetInformationThread(NtCurrentThread(), ThreadImpersonationToken, &hMyToken, sizeof(hMyToken));
			}
			NtClose(hMyToken);
		}
	}

	if (0 > status)
	{
		return status;
	}

	if (CreateProcessW(L"c:\\windows\\notepad.exe", 0, &sa, &sa, 0, 
		EXTENDED_STARTUPINFO_PRESENT|CREATE_SUSPENDED, 0, 0, &psi->StartupInfo, &pi))
	{
		// set new process intergity level in token
		if (0 <= (status = NtOpenProcessToken(pi.hProcess, TOKEN_ADJUST_DEFAULT, &hToken)))
		{
			status = SetLowLevel(hToken);
			NtClose(hToken);
		}

		if (0 > status)
		{
			TerminateProcess(pi.hProcess, 0);
		}

		ResumeThread(pi.hThread);
		NtClose(pi.hThread);
		NtClose(pi.hProcess);
	}
	else
	{
		status = RtlGetLastNtStatus();
	}

	return status;
}

NTSTATUS test(PCLIENT_ID cid)
{
	PVOID stack = alloca(guz);
	STARTUPINFOEXW si = { { sizeof(si) } };
	SIZE_T size = 0x30;
	ULONG cb = 0;

	do 
	{
		if (cb < size)
		{
			size = cb = RtlPointerToOffset(si.lpAttributeList = (LPPROC_THREAD_ATTRIBUTE_LIST)alloca(size - cb), stack);
		}

		if (InitializeProcThreadAttributeList(si.lpAttributeList, 1, 0, &size))
		{
			HANDLE hProcess;

			NTSTATUS status = NtOpenProcess(&hProcess, READ_CONTROL|PROCESS_CREATE_PROCESS|PROCESS_QUERY_LIMITED_INFORMATION, &zoa, cid);

			if (0 <= status)
			{
				// hProcess need PROCESS_CREATE_PROCESS
				if (UpdateProcThreadAttribute(si.lpAttributeList, 0, 
					PROC_THREAD_ATTRIBUTE_PARENT_PROCESS, &hProcess, sizeof(hProcess), 0, 0))
				{
					test(hProcess, &si);
				}
				else
				{
					status = STATUS_UNSUCCESSFUL;
				}

				NtClose(hProcess);
			}

			DeleteProcThreadAttributeList(si.lpAttributeList);

			return status;
		}

	} while (GetLastError() == ERROR_INSUFFICIENT_BUFFER);

	return STATUS_UNSUCCESSFUL;
}
void ttt()
{
	AdjustPrivileges();
	NTSTATUS status;
	DWORD cb = 0x10000;
	HANDLE hToken;

	do 
	{
		status = STATUS_INSUFFICIENT_RESOURCES;

		if (PBYTE buf = new BYTE[cb])
		{
			if (0 <= (status = ZwQuerySystemInformation(SystemProcessInformation, buf, cb, &cb)))
			{
				if (0 <= GetSystemToken(buf, &hToken))
				{
					status = ZwSetInformationThread(NtCurrentThread(), ThreadImpersonationToken, &hToken, sizeof(hToken));
					NtClose(hToken);
				}
			}

			delete [] buf;
		}

	} while(status == STATUS_INFO_LENGTH_MISMATCH);

	if (0 <= status)
	{
		CLIENT_ID cid1 = {(HANDLE)0x2cc};
		test(&cid1);
		hToken = 0;
		ZwSetInformationThread(NtCurrentThread(), ThreadImpersonationToken, &hToken, sizeof(hToken));
	}
}
