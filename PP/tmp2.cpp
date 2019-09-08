#include "StdAfx.h"

_NT_BEGIN

extern OBJECT_ATTRIBUTES zoa;
extern volatile UCHAR guz;
extern ULONG gNtVersion;

#include "buf.h"

void els(PVOID Buf, WLog& log0, WLog& log)
{
	union {
		PVOID pv;
		PBYTE pb;
		PSYSTEM_PROCESS_INFORMATION pspi;
	};

	pv = Buf;

	LARGE_INTEGER li;
	GetSystemTimeAsFileTime((PFILETIME)&li);

	BOOL bExistProtectionInfo = gNtVersion >= _WIN32_WINNT_WIN8;

	PROCESS_EXTENDED_BASIC_INFORMATION pebi = { sizeof(pebi) };

	ULONG NextEntryOffset = 0, rcb;

	do 
	{
		pb += NextEntryOffset;

		CLIENT_ID cid = { pspi->UniqueProcessId };

		if (cid.UniqueProcess)
		{
			TIME_FIELDS tf;
			RtlTimeToTimeFields(&pspi->CreateTime, &tf);
			LARGE_INTEGER t;
			t.QuadPart = (li.QuadPart - pspi->CreateTime.QuadPart)/10000000;

			HANDLE hProcess;

			NTSTATUS s = NtOpenProcess(&hProcess, PROCESS_QUERY_LIMITED_INFORMATION, &zoa, &cid);

			if (0 <= s)
			{
				if (0 > NtQueryInformationProcess(hProcess, ProcessBasicInformation, &pebi, sizeof(pebi), &rcb))
				{
					pebi.Flags = 0;
				}

				if (pebi.IsProtectedProcess && bExistProtectionInfo)
				{
					PS_PROTECTION ps;

					if (0 <= NtQueryInformationProcess(hProcess, ProcessProtectionInformation, &ps, sizeof(ps), &rcb))
					{
						char sztype[16], szsigner[16];
						PCSTR type = sztype, signer = szsigner;

						switch (ps.Type)
						{
						case PsProtectedTypeNone:
							type = "     None";
							break;
						case PsProtectedTypeProtectedLight:
							type = "    Light";
							break;
						case PsProtectedTypeProtected:
							type = "Protected";
							break;
						default:
							sprintf(sztype, "%9u", ps.Type);
						}

						switch (ps.Signer)
						{
						case PsProtectedSignerNone:
							signer = "None        ";
							break;
						case PsProtectedSignerAuthenticode:
							signer = "Authenticode";
							break;
						case PsProtectedSignerCodeGen:
							signer = "CodeGen     ";
							break;
						case PsProtectedSignerAntimalware:
							signer = "Antimalware ";
							break;
						case PsProtectedSignerLsa:
							signer = "Lsa         ";
							break;
						case PsProtectedSignerWindows:
							signer = "Windows     ";
							break;
						case PsProtectedSignerWinTcb:
							signer = "WinTcb      ";
							break;
						case PsProtectedSignerWinSystem:
							signer = "WinSystem   ";
							break;
						default:
							sprintf(szsigner, "%12u", ps.Signer);
						}

						log0(L"%S.%S {%x} %04x(%04x) %d-%02d:%02d:%02d[%d-%02d-%02d %02d:%02d:%02d] %wZ\r\n",
							type, signer, pspi->SessionId,
							(ULONG)(ULONG_PTR)pspi->UniqueProcessId, 
							(ULONG)(ULONG_PTR)pspi->InheritedFromUniqueProcessId,
							(DWORD)(t.QuadPart / (3600*24)), 
							(DWORD)((t.QuadPart / 3600) % 24), 
							(DWORD)((t.QuadPart / 60) % 60), 
							(DWORD)(t.QuadPart % 60),
							tf.Year, tf.Month, tf.Day, tf.Hour, tf.Minute, tf.Second,
							&pspi->ImageName);
					}
				}

				ULONG f;
				if (0 <= NtQueryInformationProcess(hProcess, ProcessBreakOnTermination, &f, sizeof(f), &rcb) && f)
				{
					pebi.SpareBits = 1;
				}

				log << '[';
				BOOL bInJob;
				if (IsProcessInJob(hProcess, 0, &bInJob))
				{
					log << (bInJob ? 'J' : '.');
				}
				else
				{
					log << '?';
				}

				log << (pebi.IsProtectedProcess ? 'P' : '.')
					<< (pebi.IsWow64Process ? 'W' : '.')
					<< (pebi.IsProcessDeleting ? 'D' : '.')
					<< (pebi.IsCrossSessionCreate ? 'C' : '.')
					<< (pebi.IsFrozen ? 'F' : '.')
					<< (pebi.IsBackground ? 'B' : '.')
					<< (pebi.IsStronglyNamed ? 'N' : '.')
					<< (pebi.IsSecureProcess ? 'S' : '.')
					<< (pebi.IsSubsystemProcess ? 'Y' : '.')
					<< (pebi.SpareBits ? 'T' : '.');

				log(L"] {%x} %04x(%04x) %d-%02d:%02d:%02d[%d-%02d-%02d %02d:%02d:%02d] %wZ\r\n",
					pspi->SessionId,
					(ULONG)(ULONG_PTR)pspi->UniqueProcessId, 
					(ULONG)(ULONG_PTR)pspi->InheritedFromUniqueProcessId,
					(DWORD)(t.QuadPart / (3600*24)), 
					(DWORD)((t.QuadPart / 3600) % 24), 
					(DWORD)((t.QuadPart / 60) % 60), 
					(DWORD)(t.QuadPart % 60),
					tf.Year, tf.Month, tf.Day, tf.Hour, tf.Minute, tf.Second, &pspi->ImageName);

				NtClose(hProcess);
			}
			else
			{
				log(L"fail: %08x %p %wZ\r\n", s, cid.UniqueProcess, &pspi->ImageName);
			}
		}

	} while (NextEntryOffset = pspi->NextEntryOffset);

	log0(L"\r\n"
		L"[J..........] - Process In Job\r\n"
		L"[.P.........] - ProtectedProcess\r\n"
		L"[..W........] - Wow64Process\r\n"
		L"[...D.......] - ProcessDeleting\r\n"
		L"[....C......] - CrossSessionCreate\r\n"
		L"[.....F.....] - Frozen\r\n"
		L"[......B....] - Background\r\n"
		L"[.......N...] - StronglyNamed\r\n"
		L"[........S..] - SecureProcess\r\n"
		L"[.........Y.] - SubsystemProcess\r\n"
		L"[..........T] - BreakOnTermination");
}

void els2(WLog& log0, WLog& log)
{
	NTSTATUS status;
	ULONG cb = 0x20000;

	do 
	{
		status = STATUS_INSUFFICIENT_RESOURCES;

		if (PVOID pv = LocalAlloc(0, cb))
		{
			if (0 <= (status = NtQuerySystemInformation(SystemProcessInformation, pv, cb, &cb)))
			{
				els(pv, log0, log);
			}
			LocalFree(pv);
		}

	} while (status == STATUS_INFO_LENGTH_MISMATCH);

	if (0 > status)
	{
		log(L"QuerySystemInformation(SystemProcessInformation)=%x\r\n", status);
		log[status];
	}
}

void ShowE2(HWND hWndParent, PCWSTR Caption, PCWSTR psz1, PCWSTR psz2, HFONT hFont );

void ShowProtectedProcesses(HWND hwnd, HFONT hFont)
{
	enum { cbAll = 0x20000, cbSmall = 0x2000};
	if (PWSTR buf = new WCHAR[cbAll])
	{
		WLog log0(buf, cbSmall), log((PBYTE)buf + cbSmall, cbAll - cbSmall);
		els2(log0, log);
		ShowE2(hwnd, L"Protected Processes", buf, (PWSTR)((PBYTE)buf + cbSmall), hFont);
		delete [] buf;
	}
}

_NT_END