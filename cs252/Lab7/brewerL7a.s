	.section	.rodata
.LC0:
	.string	"Enter one integer: "
.LC1:
	.string "\nIts hexidecimal equivalent: %x"
.LC2:
	.string "%i"
	
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp

	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf

	leaq	-4(%rbp), %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	scanf

	movl	-4(%rbp), %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call 	printf

	movl	$0, %eax
	leave
	ret
	
	