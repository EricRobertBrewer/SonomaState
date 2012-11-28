	.text
	.globl	f2a
	.type	f2a, @function
f2a:
	pushq	%rbp
	movq	%rsp, %rbp

	movb	$106, %al
	movq	%rbp, %rsp
	popq	%rbp
	ret
	