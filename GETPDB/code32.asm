.686


_TEXT segment public 'CODE'

@strnstr@16 proc
	jecxz @@3
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
@@1:
	repne scasb
	jne @@2
	cmp ecx,ebx
	jb @@2
	mov esi,ebp
	mov edx,edi
	push ecx
	mov ecx,ebx
	repe cmpsb
	pop ecx
	je @@2
	mov edi,edx
	jmp @@1
@@2:
	sete al
	movzx eax,al
	neg eax
	and eax,edi
	pop ebp
	pop ebx
	pop esi
	pop edi
	ret 8
@@3:
	xor eax,eax
	ret 8
@strnstr@16 endp

@strnchr@12 proc
	jecxz @@1
	mov al,[esp + 4]
	push edi
	mov edi,edx
	repne scasb
	sete al
	movzx eax,al
	neg eax
	and eax,edi	
	pop edi
	ret 4
@@1:
	xor eax,eax
	ret 4
@strnchr@12 endp


_TEXT ends

END