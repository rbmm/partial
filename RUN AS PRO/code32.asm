.686p

extern ?tmpInitializeProcThreadAttributeList@NT@@YGHPAU_PROC_THREAD_ATTRIBUTE_LIST@@KKPAK@Z : PROC ; int __stdcall NT::tmpInitializeProcThreadAttributeList(struct _PROC_THREAD_ATTRIBUTE_LIST *,unsigned long,unsigned long,unsigned long *)
extern ?tmpUpdateProcThreadAttribute@NT@@YGHPAU_PROC_THREAD_ATTRIBUTE_LIST@@KKPAXK1PAK@Z : PROC ; int __stdcall NT::tmpUpdateProcThreadAttribute(struct _PROC_THREAD_ATTRIBUTE_LIST *,unsigned long,unsigned long,void *,unsigned long,void *,unsigned long *)
extern ?tmpDeleteProcThreadAttributeList@NT@@YGXPAU_PROC_THREAD_ATTRIBUTE_LIST@@@Z : PROC ; void __stdcall NT::tmpDeleteProcThreadAttributeList(struct _PROC_THREAD_ATTRIBUTE_LIST *)

_DATA segment

	__imp__InitializeProcThreadAttributeList@16 DD ?tmpInitializeProcThreadAttributeList@NT@@YGHPAU_PROC_THREAD_ATTRIBUTE_LIST@@KKPAK@Z
	__imp__UpdateProcThreadAttribute@28 DD ?tmpUpdateProcThreadAttribute@NT@@YGHPAU_PROC_THREAD_ATTRIBUTE_LIST@@KKPAXK1PAK@Z
	__imp__DeleteProcThreadAttributeList@4 DD ?tmpDeleteProcThreadAttributeList@NT@@YGXPAU_PROC_THREAD_ATTRIBUTE_LIST@@@Z

_DATA ends

public __imp__InitializeProcThreadAttributeList@16
public __imp__UpdateProcThreadAttribute@28
public __imp__DeleteProcThreadAttributeList@4

END