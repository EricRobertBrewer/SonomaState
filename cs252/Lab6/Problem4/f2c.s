	.text
	.globl	f2c
	.type	f2c, @function
f2c:
	pushq	%rbp
	movq	%rsp, %rbp

	movb	$108, %al
	movq	%rbp, %rsp
	popq	%rbp
	ret
	