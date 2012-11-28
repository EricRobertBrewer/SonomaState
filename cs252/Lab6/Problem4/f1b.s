	.text
	.globl	f1b
	.type	f1b, @function
f1b:
	pushq	%rbp
	movq	%rsp, %rbp

	movl	$10, %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	