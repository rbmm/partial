.686p

_TEXT segment public 'CODE'

@strnlen@8 proc
	xor eax,eax
	jecxz @@2
	push edi
	mov edi,edx
	repne scasb
	jne @@1
	dec edi
@@1:
	sub edi,edx
	mov eax,edi
	pop edi
@@2:
	ret
@strnlen@8 endp

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
end