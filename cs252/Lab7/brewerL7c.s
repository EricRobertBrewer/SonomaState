	.section	.rodata
H:
	.string	"H"
i:
	.string "i\n"

	.text
	.globl	main
	.type	main, @function

main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp

	movl	$1, %edx
	movl	$H, %esi
	movl	$1, %edi
	call	write

	movl	$1, %edx
	movl	$i, %esi
	movl	$1, %edi
	call	write

	movl	$0, %eax
	leave
	ret
	