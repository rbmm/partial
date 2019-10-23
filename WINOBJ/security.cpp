#include "stdafx.h"

_NT_BEGIN

#include <ntlsa.h>

class WLog
{
	PVOID _BaseAddress;
	ULONG _RegionSize, _Ptr;
public:
	ULONG Init(SIZE_T RegionSize)
	{
		if (_BaseAddress = new BYTE[RegionSize])
		{
			_RegionSize = (ULONG)RegionSize, _Ptr = 0;
			return NOERROR;
		}
		return GetLastError();
	}

	~WLog()
	{
		if (_BaseAddress)
		{
			delete [] _BaseAddress;
		}
	}

	WLog(WLog&) = delete;
	WLog(WLog&&) = delete;

	WLog(): _BaseAddress(0) {  }

	operator PCWSTR()
	{
		return (PCWSTR)_BaseAddress;
	}

	WLog& operator ()(PCWSTR format, ...)
	{
		va_list args;
		va_start(args, format);

		int len = _vscwprintf(format, args);

		if (0 < len)
		{
			ULONG Size = _Ptr + (len + 1) * sizeof(WCHAR);

			if (Size <= _RegionSize)
			{
				len = _vsnwprintf_s((PWSTR)((PBYTE)_BaseAddress + _Ptr), 
					(_RegionSize - _Ptr) / sizeof(WCHAR), _TRUNCATE, format, args);

				if (0 < len)
				{
					_Ptr += len * sizeof(WCHAR);
				}
			}
		}

		return *this;
	}
};

extern volatile UCHAR guz;
//#pragma warning(disable)
const static UNICODE_STRING emptyUS{};
const static OBJECT_ATTRIBUTES zoa = { sizeof(zoa) };

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

NTSTATUS DumpGroups(WLog& log, LSA_LOOKUP_HANDLE PolicyHandle, PTOKEN_GROUPS ptg)
{
	ULONG GroupCount = ptg->GroupCount;

	if (!GroupCount)
	{
		return STATUS_SUCCESS;
	}

	PSID* Sids = (PSID*)alloca(GroupCount * sizeof(PSID)), *pSid = Sids;

	ULONG n = GroupCount;

	PSID_AND_ATTRIBUTES Groups = ptg->Groups;
	do 
	{
		*pSid++ = Groups++->Sid;
	} while (--n);

	PLSA_TRANSLATED_NAME Names = 0;
	PLSA_REFERENCED_DOMAIN_LIST ReferencedDomains = 0;

	ULONG Entries = 0;
	PLSA_TRUST_INFORMATION Domains = 0;

	NTSTATUS status = PolicyHandle ? 
		LsaLookupSids(PolicyHandle, GroupCount, Sids, &ReferencedDomains, &Names) : STATUS_INVALID_HANDLE;

	if (0 <= status)
	{
		Entries = ReferencedDomains->Entries;
		Domains = ReferencedDomains->Domains;
	}

	PVOID bufNames = Names;

	UNICODE_STRING StringSid;
	Groups = ptg->Groups;
	do 
	{
		if (0 > RtlConvertSidToUnicodeString(&StringSid, Groups->Sid, TRUE))
		{
			StringSid.Length = 0;
			StringSid.Buffer = 0;
		}

		PCUNICODE_STRING Name = &emptyUS;
		PCUNICODE_STRING Domain = &emptyUS;
		SID_NAME_USE Use = SidTypeUnknown;

		if (0 <= status)
		{
			ULONG DomainIndex = Names->DomainIndex;

			if (DomainIndex < Entries)
			{
				Domain = &Domains[DomainIndex].Name;
			}

			Name = &Names->Name;
			Use = Names++->Use;
		}

		if (ULONG Attributes = Groups->Attributes)
		{
			char sz[10];

			sz[0] = Attributes & SE_GROUP_MANDATORY ? 'M' : ' ';
			sz[1] = Attributes & SE_GROUP_ENABLED ? 'E' : ' ';
			sz[2] = Attributes & SE_GROUP_ENABLED_BY_DEFAULT ? '+' : ' ';
			sz[3] = Attributes & SE_GROUP_OWNER ? 'O' : ' ';
			sz[4] = Attributes & SE_GROUP_USE_FOR_DENY_ONLY ? 'D' : ' ';
			sz[5] = Attributes & SE_GROUP_INTEGRITY ? 'I' : ' ';
			sz[6] = Attributes & SE_GROUP_INTEGRITY_ENABLED ? '+' : ' ';
			sz[7] = Attributes & SE_GROUP_LOGON_ID ? 'L' : ' ';
			sz[8] = Attributes & SE_GROUP_RESOURCE ? 'R' : ' ';
			sz[9] = 0;

			switch (Use)
			{
			case SidTypeInvalid: 
			case SidTypeUnknown:
				log(L"%08X %S [%wZ] [%S]\r\n", 
					Attributes, sz, &StringSid, GetSidNameUseName(Use));
				break;
			default:
				log(L"%08X %S [%wZ] '%wZ\\%wZ' [%S]\r\n", 
					Attributes, sz, &StringSid, Domain, Name, GetSidNameUseName(Use));
			}
		}
		else
		{
			switch (Use)
			{
			case SidTypeInvalid: 
			case SidTypeUnknown:
				log(L"[%wZ] [%S]\r\n", 
					&StringSid, GetSidNameUseName(Use));
				break;
			default:
				log(L"[%wZ] '%wZ\\%wZ' [%S]\r\n", 
					&StringSid, Domain, Name, GetSidNameUseName(Use));
			}
		}

		RtlFreeUnicodeString(&StringSid);

	} while (Groups++, --GroupCount);

	if (0 <= status)
	{
		LsaFreeMemory(ReferencedDomains);
		LsaFreeMemory(bufNames);
	}

	return status;
}

NTSTATUS DumpACEList(WLog& log, LSA_LOOKUP_HANDLE PolicyHandle, ULONG AceCount, PVOID FirstAce)
{
	union {
		PVOID pv;
		PBYTE pb;
		PACE_HEADER ph;
		PACCESS_ALLOWED_ACE pah;
	};

	pv = FirstAce;

	PSID* Sids = (PSID*)alloca(AceCount * sizeof(PSID)), *pSid = Sids, Sid;

	ULONG SidCount = 0, n = AceCount;

	do 
	{
		if (RtlValidSid(Sid = &pah->SidStart))
		{
			*pSid++ = Sid;
			SidCount++;
		}
		pb += ph->AceSize;
	} while (--n);

	pv = FirstAce;

	PLSA_TRANSLATED_NAME Names = 0;
	PLSA_REFERENCED_DOMAIN_LIST ReferencedDomains = 0;

	ULONG Entries = 0;
	PLSA_TRUST_INFORMATION Domains = 0;

	NTSTATUS status = PolicyHandle ? 
		LsaLookupSids (PolicyHandle, SidCount, Sids, &ReferencedDomains, &Names) : STATUS_INVALID_HANDLE;

	if (0 <= status)
	{
		Entries = ReferencedDomains->Entries;
		Domains = ReferencedDomains->Domains;
	}
	PVOID bufNames = Names;

	char sz[16], sz2[16];

	UNICODE_STRING StringSid;

	do
	{
		if (!RtlValidSid(Sid = &pah->SidStart))
		{
			continue;
		}

		PCUNICODE_STRING Name = &emptyUS;
		PCUNICODE_STRING Domain = &emptyUS;
		SID_NAME_USE Use = SidTypeUnknown;

		if (0 <= status)
		{
			ULONG DomainIndex = Names->DomainIndex;

			if (DomainIndex < Entries)
			{
				Domain = &Domains[DomainIndex].Name;
			}

			Name = &Names->Name;
			Use = Names++->Use;
		}

		ACCESS_MASK Mask = pah->Mask;
		sprintf_s(sz2, "%08X", Mask);

		switch (pah->Header.AceType)
		{
		case ACCESS_ALLOWED_ACE_TYPE:
			sz[0] = 'A', sz[1] = 0;
			break;
		case ACCESS_DENIED_ACE_TYPE:
			sz[0] = 'D', sz[1] = 0;
			break;
		case SYSTEM_MANDATORY_LABEL_ACE_TYPE:
			sz[0] = 'L', sz[1] = 0;
			sz2[0] = Mask & SYSTEM_MANDATORY_LABEL_NO_READ_UP ? 'R' : ' ';
			sz2[1] = Mask & SYSTEM_MANDATORY_LABEL_NO_WRITE_UP ? 'W' : ' ';
			sz2[2] = Mask & SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP ? 'E' : ' ';
			sz2[3] = 0;
			break;
		default:
			sprintf_s(sz, "%u", pah->Header.AceType);
		}

		if (0 > RtlConvertSidToUnicodeString(&StringSid, Sid, TRUE))
		{
			StringSid.Length = 0;
			StringSid.Buffer = 0;
		}

		switch (Use)
		{
		case SidTypeInvalid: 
		case SidTypeUnknown:
			log(L"%S %02X %S [%wZ] [%S]\r\n", sz, ph->AceFlags, sz2, 
				&StringSid, GetSidNameUseName(Use));
			break;
		default:
			log(L"%S %02X %S [%wZ] '%wZ\\%wZ' [%S]\r\n", sz, ph->AceFlags, sz2, 
				&StringSid, Domain, Name, GetSidNameUseName(Use));
		}

		RtlFreeUnicodeString(&StringSid);

	} while (pb += ph->AceSize, --AceCount);

	if (0 <= status)
	{
		LsaFreeMemory(ReferencedDomains);
		LsaFreeMemory(bufNames);
	}

	return status;
}

void DumpSid(WLog& log, LSA_LOOKUP_HANDLE PolicyHandle, PCWSTR Prefix, PSID Sid)
{
	log(Prefix);
	TOKEN_GROUPS tg = { 1, { { Sid, 0 }} };
	DumpGroups(log, PolicyHandle, &tg);
}

void DumpAcl(WLog& log, LSA_LOOKUP_HANDLE PolicyHandle, PACL acl, PCWSTR caption)
{
	log(caption);

	if (!acl)
	{
		log(L"NULL\r\n");
		return;
	}

	if (!acl->AceCount)
	{
		log(L"empty\r\n");
		return;
	}

	log(L"T FL AcessMsK Sid\r\n");

	DumpACEList(log, PolicyHandle, acl->AceCount, acl + 1);
}

void DumpObjectSecurity(WLog& log, LSA_LOOKUP_HANDLE PolicyHandle, HANDLE hObject)
{
	ULONG cb = 0, rcb = 128;

	PVOID stack = alloca(guz);

	union {
		PVOID buf;
		PSECURITY_DESCRIPTOR psd;
	};

	log(L"************************\r\n//++ObjectSecurity\r\n");

	NTSTATUS status;
	do 
	{
		if (cb < rcb)
		{
			cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
		}

		if (0 <= (status = ZwQuerySecurityObject(hObject, 
			PROCESS_TRUST_LABEL_SECURITY_INFORMATION|OWNER_SECURITY_INFORMATION|DACL_SECURITY_INFORMATION|LABEL_SECURITY_INFORMATION, 
			psd, cb, &rcb)))
		{
			//log(L)
			PACL Acl;
			BOOLEAN bPresent, bDefault;

			if (0 <= RtlGetDaclSecurityDescriptor(psd, &bPresent, &Acl, &bDefault))
			{
				DumpAcl(log, PolicyHandle, bPresent ? Acl : 0, L"DACL:\r\n");
			}

			if (0 <= RtlGetSaclSecurityDescriptor(psd, &bPresent, &Acl, &bDefault))
			{
				DumpAcl(log, PolicyHandle, bPresent ? Acl : 0, L"LABEL:\r\n");
			}

			PSID Owner;
			if (0 <= RtlGetOwnerSecurityDescriptor(psd, &Owner, &bDefault) && Owner)
			{
				DumpSid(log, PolicyHandle, L"Owner: ", Owner);
			}

		}

	} while (status == STATUS_BUFFER_TOO_SMALL);

	log(L"************************\r\n//--ObjectSecurity\r\n");
}

void DumpToken(WLog& log, LSA_LOOKUP_HANDLE PolicyHandle, HANDLE hToken, BOOL bReqursive)
{
	DumpObjectSecurity(log, PolicyHandle, hToken);

	ULONG cb = 0, rcb;
	NTSTATUS status;

	union {
		TOKEN_TYPE tp;
		TOKEN_SOURCE ts;
		TOKEN_STATISTICS stat;
		TOKEN_ELEVATION_TYPE tet;
		TOKEN_ELEVATION te;
		ULONG SessionId;
		TOKEN_MANDATORY_POLICY tmp;
		BOOL IsAppContainer;
	};

	CHAR sz[64], sz2[16];
	PSTR fmt, fmt2;
	PVOID stack = alloca(guz);

	union {
		PVOID buf;
		PTOKEN_GROUPS ptg;
		PTOKEN_PRIVILEGES ptp;
		PTOKEN_USER User;
		PTOKEN_OWNER Owner;
		PTOKEN_MANDATORY_LABEL ptml;
		PTOKEN_APPCONTAINER_INFORMATION AppConainer;
		PTOKEN_DEFAULT_DACL ptdd;
		PTOKEN_PRIMARY_GROUP ptpg;
		PTOKEN_SID_INFORMATION ptsi;
	};

	log(L"********************************************************************************\r\n");

	if (0 <= (status = NtQueryInformationToken(hToken, TokenSource, &ts, sizeof(ts), &rcb)))
	{
		log(L"Name:              %.8S\r\n"
			"Identifier:        %08x-%08x\r\n", 
			ts.SourceName, ts.SourceIdentifier.HighPart, ts.SourceIdentifier.LowPart);
	}

	ULONG GroupCount = 0, PrivilegeCount = 0, Attributes;

	if (0 <= (status = NtQueryInformationToken(hToken, TokenStatistics, &stat, sizeof(stat), &rcb)))
	{
		switch (stat.TokenType)
		{
		case TokenPrimary:
			fmt = "Primary";
			break;
		case TokenImpersonation:
			fmt = "Impersonation";
			break;
		default:
			sprintf_s(sz, "%x", stat.TokenType), fmt = sz;
		}

		switch (stat.ImpersonationLevel)
		{
		case SecurityAnonymous:
			fmt2 = "Anonymous";
			break;
		case SecurityIdentification:
			fmt2 = "Identification";
			break;
		case SecurityImpersonation:
			fmt2 = "Impersonation";
			break;
		case SecurityDelegation:
			fmt2 = "Delegation";
			break;
		default:
			sprintf_s(sz2, "%x", stat.ImpersonationLevel), fmt2 = sz2;
		}

		log(L"TokenId:           %08x-%08x\r\n"
			L"LogonId:           %08x-%08x\r\n"
			L"ModifiedId:        %08x-%08x\r\n"
			L"TokenType:         %S\r\n"
			L"ImpersonationLevel %S\r\n"
			L"GroupCount:        %u\r\n"
			L"PrivilegeCount:    %u\r\n",
			stat.TokenId.HighPart, stat.TokenId.LowPart,
			stat.AuthenticationId.HighPart, stat.AuthenticationId.LowPart,
			stat.ModifiedId.HighPart, stat.ModifiedId.LowPart,
			fmt, 
			fmt2,
			GroupCount = stat.GroupCount,
			PrivilegeCount = stat.PrivilegeCount
			);
	}

	if (0 <= (status = NtQueryInformationToken(hToken, TokenSessionId, &SessionId, sizeof(SessionId), &rcb)))
	{
		log(L"SessionId:         %u\r\n", SessionId);
	}

	if (0 <= (status = NtQueryInformationToken(hToken, TokenMandatoryPolicy, &tmp, sizeof(tmp), &rcb)))
	{
		fmt = sz + 1, *sz = '[';
		if (tmp.Policy & TOKEN_MANDATORY_POLICY_NO_WRITE_UP)
		{
			fmt += sprintf(fmt, " NO_WRITE_UP ");
		}
		if (tmp.Policy & TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN)
		{
			fmt += sprintf(fmt, " NEW_PROCESS_MIN ");
		}
		*fmt++ = ']', *fmt++ = 0;
		log(L"Policy:            %u %S\r\n", tmp.Policy, sz);
	}

	if (0 <= (status = NtQueryInformationToken(hToken, TokenElevationType, &tet, sizeof(tet), &rcb)))
	{
		switch (tet)
		{
		case TokenElevationTypeDefault:
			fmt = "Default";
			bReqursive = TRUE;// no linked token
			break;
		case TokenElevationTypeFull:
			fmt = "Full";
			break;
		case TokenElevationTypeLimited:
			fmt = "Limited";
			break;
		default:
			sprintf(sz, "%x", tet), fmt = sz;
		}
		log(L"ElevationType:     %S\r\n", fmt);
	}

	if (0 <= (status = NtQueryInformationToken(hToken, TokenIsAppContainer, &IsAppContainer, sizeof(IsAppContainer), &rcb)))
	{
		if (IsAppContainer)
		{
			log(L"********** Token Is AppContainer **********\r\n", SessionId);

			rcb = MAX_SID_SIZE;

			do 
			{
				if (cb < rcb)
				{
					if (rcb > MAXUSHORT)
					{
						status = STATUS_UNSUCCESSFUL;
						break;
					}

					cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
				}

				if (0 <= (status = NtQueryInformationToken(hToken, TokenAppContainerSid, buf, cb, &rcb)))
				{
					DumpSid(log, PolicyHandle, L"AppContainerSID:   ", AppConainer->TokenAppContainer);
					break;
				}

			} while (status == STATUS_BUFFER_TOO_SMALL);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	// IntegrityLevel

	rcb = MAX_SID_SIZE;

	do 
	{
		if (cb < rcb)
		{
			if (rcb > MAXUSHORT)
			{
				status = STATUS_UNSUCCESSFUL;
				break;
			}

			cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
		}

		if (0 <= (status = NtQueryInformationToken(hToken, TokenIntegrityLevel, buf, cb, &rcb)))
		{
			DumpSid(log, PolicyHandle, L"IntegrityLevel:    ", ptml->Label.Sid);
			break;
		}

	} while (status == STATUS_BUFFER_TOO_SMALL);

	//////////////////////////////////////////////////////////////////////////
	//
	rcb = MAX_SID_SIZE;
	do 
	{
		if (cb < rcb)
		{
			if (rcb > MAXUSHORT)
			{
				status = STATUS_UNSUCCESSFUL;
				break;
			}

			cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
		}

		if (0 <= (status = NtQueryInformationToken(hToken, TokenProcessTrustLevel, buf, cb, &rcb)))
		{
			if (ptsi->Sid)
			{
				DumpSid(log, PolicyHandle, L"TrustLevel:        ", ptsi->Sid);
			}
			break;
		}

	} while (status == STATUS_BUFFER_TOO_SMALL);

	//////////////////////////////////////////////////////////////////////////
	// User

	rcb = MAX_SID_SIZE;

	do 
	{
		if (cb < rcb)
		{
			if (rcb > MAXUSHORT)
			{
				status = STATUS_UNSUCCESSFUL;
				break;
			}

			cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
		}

		if (0 <= (status = NtQueryInformationToken(hToken, TokenUser, buf, cb, &rcb)))
		{
			DumpSid(log, PolicyHandle, L"SID:               ", User->User.Sid);
			break;
		}

	} while (status == STATUS_BUFFER_TOO_SMALL);

	//////////////////////////////////////////////////////////////////////////
	// PrimaryGroup

	rcb = MAX_SID_SIZE;

	do 
	{
		if (cb < rcb)
		{
			if (rcb > MAXUSHORT)
			{
				status = STATUS_UNSUCCESSFUL;
				break;
			}

			cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
		}

		if (0 <= (status = NtQueryInformationToken(hToken, TokenPrimaryGroup, buf, cb, &rcb)))
		{
			DumpSid(log, PolicyHandle, L"Group:             ", ptpg->PrimaryGroup);
			break;
		}

	} while (status == STATUS_BUFFER_TOO_SMALL);

	//////////////////////////////////////////////////////////////////////////
	// Owner

	rcb = MAX_SID_SIZE;

	do 
	{
		if (cb < rcb)
		{
			if (rcb > MAXUSHORT)
			{
				status = STATUS_UNSUCCESSFUL;
				break;
			}

			cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
		}

		if (0 <= (status = NtQueryInformationToken(hToken, TokenOwner, buf, cb, &rcb)))
		{
			DumpSid(log, PolicyHandle, L"Owner:             ", Owner->Owner);
			break;
		}

	} while (status == STATUS_BUFFER_TOO_SMALL);

	//////////////////////////////////////////////////////////////////////////
	// Priviledges

	rcb = FIELD_OFFSET(TOKEN_PRIVILEGES, Privileges[PrivilegeCount]);

	do 
	{
		if (cb < rcb)
		{
			if (rcb > MAXUSHORT)
			{
				status = STATUS_UNSUCCESSFUL;
				break;
			}

			cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
		}

		if (0 <= (status = NtQueryInformationToken(hToken, TokenPrivileges, buf, cb, &rcb)))
		{
			log(L"********************************************************************************\r\n"
				"Priveleges Count:	%u\r\n"
				"********************************************************************************\r\n",
				PrivilegeCount = ptp->PrivilegeCount);

			if (PrivilegeCount)
			{
				PLUID_AND_ATTRIBUTES Privileges = ptp->Privileges;
				do 
				{
					Attributes = Privileges->Attributes;
					fmt = sz - 1;

					*++fmt = ' ';if (Attributes & SE_PRIVILEGE_ENABLED)*fmt = 'E';
					*++fmt = ' ';if (Attributes & SE_PRIVILEGE_ENABLED_BY_DEFAULT)*fmt = '+';
					*++fmt = ' ';if (Attributes & SE_PRIVILEGE_USED_FOR_ACCESS)*fmt = 'A';
					*++fmt = ' ';if (Attributes & SE_PRIVILEGE_REMOVED)*fmt = 'R';
					*++fmt=0;

					PUNICODE_STRING Name;
					if (0 <= LsaLookupPrivilegeName(PolicyHandle, &Privileges->Luid, &Name))
					{
						log(L"%08x %S %wZ\r\n", Attributes, sz, Name);

						LsaFreeMemory(Name->Buffer);
						LsaFreeMemory(Name);
					}
					else
					{
						log(L"%08x %S {%x%x}\r\n", Attributes, sz, Privileges->Luid.HighPart, Privileges->Luid.LowPart );
					}

				} while (Privileges++, --PrivilegeCount);
			}
			break;
		}

	} while (status == STATUS_BUFFER_TOO_SMALL);

	//////////////////////////////////////////////////////////////////////////
	// Groups

	rcb = FIELD_OFFSET(TOKEN_GROUPS, Groups[GroupCount]) + GroupCount * 32;

	do 
	{
		if (cb < rcb)
		{
			if (rcb > MAXUSHORT)
			{
				status = STATUS_UNSUCCESSFUL;
				break;
			}

			cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
		}

		if (0 <= (status = NtQueryInformationToken(hToken, TokenGroups, buf, cb, &rcb)))
		{
			log(L"********************************************************************************\r\n"
				"Group Count:	%u\r\n"
				"********************************************************************************\r\n",
				GroupCount = ptg->GroupCount);

			DumpGroups(log, PolicyHandle, ptg);
			break;
		}

	} while (status == STATUS_BUFFER_TOO_SMALL);

	//////////////////////////////////////////////////////////////////////////
	// Restricted Groups

	rcb = FIELD_OFFSET(TOKEN_GROUPS, Groups[8]);

	do 
	{
		if (cb < rcb)
		{
			if (rcb > MAXUSHORT)
			{
				status = STATUS_UNSUCCESSFUL;
				break;
			}

			cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
		}

		if (0 <= (status = NtQueryInformationToken(hToken, TokenRestrictedSids, buf, cb, &rcb)))
		{
			if (GroupCount = ptg->GroupCount)
			{
				log(L"********************************************************************************\r\n"
					"Restricted Group Count:	%u\r\n"
					"********************************************************************************\r\n",
					GroupCount);

				DumpGroups(log, PolicyHandle, ptg);
			}
			break;
		}

	} while (status == STATUS_BUFFER_TOO_SMALL);

	//////////////////////////////////////////////////////////////////////////
	// DefaultDacl

	rcb = MAX_SID_SIZE;

	do 
	{
		if (cb < rcb)
		{
			if (rcb > MAXUSHORT)
			{
				status = STATUS_UNSUCCESSFUL;
				break;
			}

			cb = RtlPointerToOffset(buf = alloca(rcb - cb), stack);
		}

		if (0 <= (status = NtQueryInformationToken(hToken, TokenDefaultDacl, buf, cb, &rcb)))
		{
			DumpAcl(log, PolicyHandle, ptdd->DefaultDacl, 
				L"*******************************************************************************\r\nDefaultDacl:\r\n");
			break;
		}

	} while (status == STATUS_BUFFER_TOO_SMALL);

	if (!bReqursive)
	{
		TOKEN_LINKED_TOKEN tlt;

		if (0 <= (status = NtQueryInformationToken(hToken, TokenLinkedToken, &tlt, sizeof(tlt), &rcb)))
		{
			log(L"*******************************************************************************\r\n");
			log(L"Linked Token:\r\n");
			DumpToken(log, PolicyHandle, tlt.LinkedToken, TRUE);
			ZwClose(tlt.LinkedToken);
		}
		else
		{
			log(L"TokenLinkedToken fail with %x\r\n", status);
		}
	}
}

void DumpToken(HWND hwnd, HANDLE hToken)
{
	WLog log;
	if (!log.Init(0x10000))
	{
		LSA_LOOKUP ll;

		DumpToken(log, ll(), hToken, FALSE);

		SetWindowTextW(hwnd, log);
	}
}

void DumpObjectSecurity(HWND hwnd, HANDLE hObject)
{
	WLog log;
	if (!log.Init(0x10000))
	{
		LSA_LOOKUP ll;
		DumpObjectSecurity(log, ll(), hObject);

		SetWindowTextW(hwnd, log);
	}
}

_NT_END