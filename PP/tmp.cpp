#include "StdAfx.h"

_NT_BEGIN

#include <ntlsa.h>
#include "buf.h"

extern OBJECT_ATTRIBUTES zoa;
extern volatile UCHAR guz;

BOOL Impersonate(PCLIENT_ID ClientId)
{
	BOOL f = FALSE;

	HANDLE hThread;

	if (0 <= ZwOpenThread(&hThread, THREAD_DIRECT_IMPERSONATION, &zoa, ClientId))
	{
		static SECURITY_QUALITY_OF_SERVICE sqos = {
			sizeof sqos, SecurityImpersonation, SECURITY_DYNAMIC_TRACKING, FALSE
		};

		if (0 <= ZwImpersonateThread(NtCurrentThread(), hThread, &sqos))
		{
			f = TRUE;
		}
		NtClose(hThread);
	}

	return f;
}

PCWSTR GetLogonTypeName(ULONG LogonType, PWSTR buf, ULONG cch)
{
#define CASE_LT(x) case x: return L#x;

	switch(LogonType)
	{
		CASE_LT(UndefinedLogonType)
			CASE_LT(Interactive)
			CASE_LT(Network)
			CASE_LT(Batch)
			CASE_LT(Service)
			CASE_LT(Proxy)
			CASE_LT(Unlock)
			CASE_LT(NetworkCleartext)
			CASE_LT(NewCredentials)
			CASE_LT(RemoteInteractive)
			CASE_LT(CachedInteractive)
			CASE_LT(CachedRemoteInteractive)
			CASE_LT(CachedUnlock)
	}

	swprintf_s(buf, cch, L"%x", LogonType);
	return buf;
}

PWSTR FormatUserFlags(LONG UserFlags, PWSTR loc_buf, ULONG loc_cch)
{
	static const PCWSTR _S_szFlags[32] = {
		L"GUEST",
		L"NOENCRYPTION",
		L"CACHED_ACCOUNT",
		L"USED_LM_PASSWORD",
		0,
		L"EXTRA_SIDS",
		L"SUBAUTH_SESSION_KEY",
		L"SERVER_TRUST_ACCOUNT",
		L"NTLMV2_ENABLED",
		L"RESOURCE_GROUPS",
		L"PROFILE_PATH_RETURNED",
		L"NT_V2",
		L"LM_V2",
		L"NTLM_V2",
		L"OPTIMIZED",
		L"WINLOGON",
		L"PKINIT",
		L"NO_OPTIMIZED",
		L"NO_ELEVATION",
		L"MANAGED_SERVICE",
	};

	SIZE_T cch = 0;
	PCWSTR pcsz;
	int i = 32;
	do 
	{
		if (_bittest(&UserFlags, --i) && (pcsz = _S_szFlags[i]))
		{
			// \t\t%s\r\n
			cch += wcslen(pcsz) + 4;
		}
	} while (i);

	if (!cch)
	{
		*loc_buf = 0;
		return loc_buf;
	}

	if (PWSTR buf = ++cch > loc_cch ? new WCHAR[cch] : loc_buf)
	{
		PWSTR psz = buf;
		i = 32;
		do 
		{
			if (_bittestandreset(&UserFlags, --i) && (pcsz = _S_szFlags[i]))
			{
				int len = swprintf_s(psz, cch, L"\t\t%s\r\n", pcsz);
				if (0 >= len)
				{
					delete [] buf;
					return 0;
				}
				psz += len, cch -= len;
			}
		} while (UserFlags);

		return buf;
	}

	return 0;
}

BOOL Impersonate(PVOID buf)
{
	union {
		PBYTE pb;
		PVOID pv;
		PSYSTEM_PROCESS_INFORMATION sp;
	};
	pv = buf;
	ULONG NextEntryOffset = 0;

	do 
	{
		pb += NextEntryOffset;

		if (sp->NumberOfThreads )
		{
			if (Impersonate(&sp->TH->ClientId))
			{
				return TRUE;
			}
		}

	} while( NextEntryOffset = sp->NextEntryOffset);

	return FALSE;
}

void Update(WLog& log, PVOID Ptr)
{
	union {
		PBYTE pb;
		PVOID pv;
		PSYSTEM_PROCESS_INFORMATION pspi;
	};

	pv = Ptr;

	ULONG NextEntryOffset = 0, rcb;
	do 
	{
		pb += NextEntryOffset;

		CLIENT_ID cid = { pspi->UniqueProcessId };

		if (cid.UniqueProcess)
		{
			HANDLE hProcess, hToken;

			NTSTATUS status;
			if (0 > (status = NtOpenProcess(&hProcess, PROCESS_QUERY_LIMITED_INFORMATION, &zoa, &cid)))
			{
				log(L"OpenProcess(%p,%wZ)=%x\r\n", cid.UniqueProcess, &pspi->ImageName, status);
			}
			else
			{
				if (0 > (status = NtOpenProcessToken(hProcess, TOKEN_QUERY, &hToken)))
				{
					log(L"OpenProcessToken(%p,%wZ)=%x\r\n", cid.UniqueProcess, &pspi->ImageName, status);
				}
				else
				{
					TOKEN_STATISTICS ts;
					if (0 > (status = NtQueryInformationToken(hToken, TokenStatistics, &ts, sizeof(ts), &rcb)))
					{
						log(L"QueryInformationToken(%p,%wZ)=%x\r\n", cid.UniqueProcess, &pspi->ImageName, status);
					}
					else
					{
						pspi->ReadTransferCount.LowPart = ts.AuthenticationId.LowPart;
						pspi->ReadTransferCount.HighPart = ts.AuthenticationId.HighPart;
					}
					NtClose(hToken);
				}
				NtClose(hProcess);
			}
		}
		else
		{
			pspi->ReadTransferCount.QuadPart = 0;
		}

	} while (NextEntryOffset = pspi->NextEntryOffset);
}

void AddProToLS(WLog& log, PLUID LogonSessionList, PVOID Ptr)
{
	union {
		PBYTE pb;
		PVOID pv;
		PSYSTEM_PROCESS_INFORMATION pspi;
	};

	pv = Ptr;

	TIME_FIELDS tf;
	ULONG NextEntryOffset = 0;

	LARGE_INTEGER li;
	GetSystemTimeAsFileTime((PFILETIME)&li);

	do 
	{
		pb += NextEntryOffset;

		if (LogonSessionList->LowPart == pspi->ReadTransferCount.LowPart && 
			LogonSessionList->HighPart == pspi->ReadTransferCount.HighPart)
		{
			RtlTimeToTimeFields(&pspi->CreateTime, &tf);
			LARGE_INTEGER t;
			t.QuadPart = (li.QuadPart - pspi->CreateTime.QuadPart)/10000000;

			log(L"\t%u %05x(%05x) %d-%02d:%02d:%02d[%u-%02u-%02u %02u:%02u:%02u] %wZ\r\n", 
				pspi->SessionId, 
				(ULONG)(ULONG_PTR)pspi->UniqueProcessId, 
				(ULONG)(ULONG_PTR)pspi->InheritedFromUniqueProcessId,
				(DWORD)(t.QuadPart / (3600*24)), 
				(DWORD)((t.QuadPart / 3600) % 24), 
				(DWORD)((t.QuadPart / 60) % 60), 
				(DWORD)(t.QuadPart % 60),
				tf.Year, tf.Month, tf.Day, tf.Hour, tf.Minute, tf.Second, &pspi->ImageName);
		}

	} while (NextEntryOffset = pspi->NextEntryOffset);
}

PCSTR GetSidNameUseName(SID_NAME_USE snu)
{
	switch (snu)
	{
	case SidTypeUser: return "User";
	case SidTypeGroup: return "Group";
	case SidTypeDomain: return "Domain";
	case SidTypeAlias: return "Alias";
	case SidTypeWellKnownGroup: return "WellKnownGroup";
	case SidTypeDeletedAccount: return "DeletedAccount";
	case SidTypeInvalid: return "Invalid";
	case SidTypeUnknown: return "Unknown";
	case SidTypeComputer: return "Computer";
	case SidTypeLabel: return "Label";
	case SidTypeLogonSession: return "LogonSession";
	}
	return "?";
}

class LSA_LOOKUP
{
	LSA_HANDLE PolicyHandle;
public:
	LSA_LOOKUP()
	{
		LSA_OBJECT_ATTRIBUTES ObjectAttributes = { sizeof(ObjectAttributes) };

		if (0 > LsaOpenPolicy(0, &ObjectAttributes, POLICY_LOOKUP_NAMES, &PolicyHandle))
		{
			PolicyHandle = 0;
		}
	}

	~LSA_LOOKUP()
	{
		if (PolicyHandle)
		{
			LsaClose(PolicyHandle);
		}
	}

	LSA_LOOKUP_HANDLE operator()()
	{
		return PolicyHandle;
	}
};

void DumpSessions(WLog& log, PVOID pspi)
{
	ULONG LogonSessionCount;
	PLUID LogonSessionList;
	NTSTATUS status;
	if (0 > (status = LsaEnumerateLogonSessions(&LogonSessionCount, &LogonSessionList)))
	{
		log(L"LsaEnumerateLogonSessions=%x\r\n", status);
	}
	else
	{
		PVOID Buffer = LogonSessionList;
		if (LogonSessionCount)
		{
			LSA_LOOKUP ll;

			do 
			{
				SECURITY_LOGON_SESSION_DATA *LogonSessionData;
				if (0 > (status = LsaGetLogonSessionData(LogonSessionList, &LogonSessionData)))
				{
					log(L"LsaGetLogonSessionData(%08x-%08x)=%x\r\n", LogonSessionList->HighPart, LogonSessionList->LowPart, status);
				}
				else
				{
					TIME_FIELDS tf;
					WCHAR cc[16], buf[0x80];

					RtlTimeToTimeFields(&LogonSessionData->LogonTime, &tf);

					PWSTR pszFlags = FormatUserFlags(LogonSessionData->UserFlags, buf, _countof(buf));

					log(L"=================================================\r\n"
						L"LogonId:\t%08x-%08x\r\n"
						L"Session:\t%u\r\n"
						L"LogonType:\t%s\r\n" 
						L"UserFlags:\t%08x\r\n"
						L"%s"
						L"LogonTime\t%u-%02u-%02u %02u:%02u:%02u\r\n"
						L"Username:\t%wZ\r\n"
						L"LogonDomain:\t%wZ\r\n"
						L"AuthenticationPackage:\t%wZ\r\n" 
						L"LogonServer:\t%wZ\r\n"
						L"DnsDomainName:\t%wZ\r\n"
						L"Sid:",
						LogonSessionData->LogonId.HighPart, LogonSessionData->LogonId.LowPart,
						LogonSessionData->Session,
						GetLogonTypeName(LogonSessionData->LogonType, cc, _countof(cc)),
						LogonSessionData->UserFlags, pszFlags,
						tf.Year, tf.Month, tf.Day, tf.Hour, tf.Minute, tf.Second,
						&LogonSessionData->UserName, 
						&LogonSessionData->LogonDomain, 
						&LogonSessionData->AuthenticationPackage, 
						&LogonSessionData->LogonServer, 
						&LogonSessionData->DnsDomainName 
						);

					if (pszFlags && pszFlags != buf)
					{
						delete [] pszFlags;
					}

					if (PSID Sid = LogonSessionData->Sid)
					{
						UNICODE_STRING us;

						if (0 > RtlConvertSidToUnicodeString(&us, Sid, TRUE))
						{
							us.Length = 0, us.Buffer = 0;
						}

						PLSA_REFERENCED_DOMAIN_LIST ReferencedDomains;
						PLSA_TRANSLATED_NAME Names;
						ULONG Entries = 0;
						PLSA_TRUST_INFORMATION Domains = 0;

						const static UNICODE_STRING emptyUS{};
						PCUNICODE_STRING Name = &emptyUS;
						PCUNICODE_STRING Domain = &emptyUS;
						SID_NAME_USE Use = SidTypeUnknown;

						if (0 <= (status = LsaLookupSids(ll(), 1, &Sid, &ReferencedDomains, &Names)))
						{
							Entries = ReferencedDomains->Entries;
							Domains = ReferencedDomains->Domains;
							Name = &Names->Name;
							Use = Names->Use;

							ULONG DomainIndex = Names->DomainIndex;

							if (DomainIndex < Entries)
							{
								Domain = &Domains[DomainIndex].Name;
							}
						}

						log(L"\t[%wZ] '%wZ\\%wZ' [%S]\r\n", &us, Domain, Name, GetSidNameUseName(Use));

						if (0 <= status)
						{
							LsaFreeMemory(Names);
							LsaFreeMemory(ReferencedDomains);
						}

						RtlFreeUnicodeString(&us);
					}

					log << '\r' << '\n';

					LsaFreeReturnBuffer(LogonSessionData);

					AddProToLS(log, LogonSessionList, pspi);
				}

			} while (LogonSessionList++, --LogonSessionCount);
		}
		LsaFreeReturnBuffer(Buffer);
	}
}

void els(WLog& log)
{
	NTSTATUS status;
	DWORD cb = 0x40000;
	do 
	{
		status = STATUS_INSUFFICIENT_RESOURCES;

		if (PVOID pv = new BYTE[cb])
		{
			if (0 <= (status = NtQuerySystemInformation(SystemProcessInformation, pv, cb, &cb)))
			{
				if (!Impersonate(pv))
				{
					log(L"Impersonate error\r\n");
				}

				Update(log, pv);
				DumpSessions(log, pv);
			}
			delete [] pv;
		}

	} while (status == STATUS_INFO_LENGTH_MISMATCH);

	if (0 > status)
	{
		log(L"QuerySystemInformation(SystemProcessInformation)=%x\r\n", status);
	}
}

void ShowSessions(HWND hwnd)
{
	if (PWSTR buf = (PWSTR)LocalAlloc(0, 0x80000))
	{
		WLog log(buf, 0x80000);
		els(log);
		SetThreadToken(0, 0);
		log >> hwnd;
	}
}

_NT_END