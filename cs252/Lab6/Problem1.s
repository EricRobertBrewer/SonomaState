	.file	"Problem1.c"
	.section	.rodata
.LC0:
	.string	"Enter an integer: "
.LC1:
	.string	"%i"
.LC2:
	.string	"The result is %i\n"
	.text
.globl main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	pushq	%rbx
.LCFI2:
	subq	$24, %rsp
.LCFI3:
	leaq	-20(%rbp), %rax
	movq	%rax, -16(%rbp)
	movl	$305441741, -20(%rbp)
	movl	$-1, %ebx
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movq	-16(%rbp), %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	scanf
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	addl	%eax, %ebx
	movl	%ebx, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	addq	$24, %rsp
	popq	%rbx
	leave
	ret
.LFE2:
	.size	main, .-main
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zR"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x10
	.uleb128 0x1
	.byte	0x3
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 8
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI0-.LFB2
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x6
	.byte	0x4
	.long	.LCFI3-.LCFI1
	.byte	0x83
	.uleb128 0x3
	.align 8
.LEFDE1:
	.ident	"GCC: (GNU) 4.3.0 20080428 (Red Hat 4.3.0-8)"
	.section	.note.GNU-stack,"",@progbits
