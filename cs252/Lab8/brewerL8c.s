	.section	.rodata
instruction:
	.string	"\nJust enter single characters- "
prompt:
	.string	"\nEnter one character: "
response:
	.string	"\nYou entered: %c"
character:
	.string	"%c"
	
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	
	movl	$instruction, %edi
	movl	$0, %eax
	call	printf

iteration:	
	movl	$prompt, %edi
	movl	$0, %eax
	call	printf

	movl	$character, %edi
	movq	%r13, %rsi
	movl	$0, %eax
	call	scanf

	movl	$response, %edi
	movq	%r13, %rsi
	movl	$0, %eax
	call	printf

	cmpb	$'q', (%r13)
	je	next
	jmp	iteration

next:
	leave
	ret
	