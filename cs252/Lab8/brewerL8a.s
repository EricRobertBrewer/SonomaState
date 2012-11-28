	.section	.rodata
prompt:
	.string	"\nEnter a number: "
integer:
	.string	"%i"
response:
	.string	"\nYou entered: %i"

	.text
	.globl	main
	.type	main, @function
main:
	pushq 	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp

iteration:	
	movl	$prompt, %edi
	movl	$0, %eax
	call 	printf

	movl	$integer, %edi
	leaq	-4(%rbp), %rsi
	movl	$0, %eax
	call    scanf

	movl	$response, %edi
	movl	-4(%rbp), %esi
	movl	$0, %eax
	call	printf
	jmp	iteration

	leave
	ret
	