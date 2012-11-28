	.text
	.globl	 f1a
	.type	 f1a, @function
f1a:
	pushq 	%rbp
	movq	%rsp, %rbp

	movl 	$5, %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	