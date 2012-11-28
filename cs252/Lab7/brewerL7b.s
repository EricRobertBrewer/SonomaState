	.section	.rodata
.LC0:
	.string	"%c %c %c %c %i %i %i %i\n"

	.text
	.globl 	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$64, %rsp

	movb	$87, -7(%rbp)
	movb	$88, -8(%rbp)
	movb	$89, -9(%rbp)
	movb	$90, -10(%rbp)
	movl	$23, -16(%rbp)
	movl	$24, -20(%rbp)
	movl	$25, -24(%rbp)
	movl	$26, -28(%rbp)

	movl	-28(%rbp), 16(%rsp)
	movl	-24(%rbp), 8(%rsp)
	movl	-20(%rbp), (%rsp)
	movl	-16(%rbp), %r9d
	movl	-10(%rbp), %r8d
	movl	-9(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-7(%rbp), %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call 	printf

	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbx
	leave
	ret
	