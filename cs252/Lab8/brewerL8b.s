	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp

	pushq	%r12
	movq	$65, %r12
	movq	$90, %r10
	
loopStart:	
	movl	$1, %edi
	movq	%r12, %rsi
	movl	$1, %edx
	call	write

	addq	$1, %r12
	cmpb	%r10b, %r12b
	jg	next
	jmp	loopStart
	
next:
	popq	%r12
	leave
	ret
	