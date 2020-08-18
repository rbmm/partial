.686


_TEXT segment public 'CODE'

@retz4 proc
	xor eax,eax
	ret 4
@retz4 endp

?strnchr@NT@@YIPADKPBXD@Z proc
	jecxz @retz4
	mov al,[esp + 4]
	xchg edi,edx
	repne scasb
	mov eax,edi
	cmovne eax,ecx
	mov edi,edx
	ret 4
?strnchr@NT@@YIPADKPBXD@Z endp

@retz8 proc
	xor eax,eax
	ret 8
@retz8 endp

?strnstr@NT@@YIPADKPBXK0@Z proc
	jecxz @retz8
	cmp ecx,[esp + 4]
	jb @retz8
	push edi
	push esi
	push ebx
	push ebp
	mov ebx,[esp + 20]
	mov ebp,[esp + 24]
	mov edi,edx
	mov al,[ebp]
	inc ebp
	dec ebx
	sub ecx,ebx
@@1:
	repne scasb
	jne @@2
	mov esi,ebp
	mov edx,edi
	push ecx
	mov ecx,ebx
	test ecx,ecx
	repe cmpsb
	pop ecx
	je @@2
	mov edi,edx
	jmp @@1
@@2:
	mov eax,edi
	cmovne eax,ecx
	pop ebp
	pop ebx
	pop esi
	pop edi
	ret 8
?strnstr@NT@@YIPADKPBXK0@Z endp

_TEXT ends

END