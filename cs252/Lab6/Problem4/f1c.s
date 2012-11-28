	.text
	.globl 	f1c
	.type 	f1c, @function
f1c:
	pushq	%rbp
	movq	%rsp, %rbp

	movl 	$15, %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	