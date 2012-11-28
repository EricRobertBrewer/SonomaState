	.text
	.globl	f2b
	.type	f2b, @function
f2b:
	pushq	%rbp
	movq	%rsp, %rbp

	movb	$107, %al
	movq	%rbp, %rsp
	popq	%rbp
	ret
	