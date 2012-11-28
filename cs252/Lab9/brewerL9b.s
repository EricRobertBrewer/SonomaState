	.equ	integer, -40
	.equ	str, -32

	.section	.rodata
prompt:
	.string	"\nEnter an integer: "
I:
	.string	"%i"
	
	.text
	.global	main
	.type	main, @function
	
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp		# make some room
	movl	$0, %r8			# string's length variable
	
	movl	$0, %eax		# no floats
	movl	$prompt, %edi		# 1st function arg for printf
	call	printf			# calls printf

	movl	$0, %eax		# no floats
	leaq	integer(%rbp), %rsi	# 2nd function arg for scanf
	movl	$I, %edi		# 1st function arg for scanf
	call	scanf			# calls scanf

	movb	integer(%rbp), %r10b	# copy integer into r10
	andb	$1, %r10b		# isolate least sig. bit by using bitmask 00000001
	movb	%r10b, str(%rbp)	# copy new integer value into string
	shrl	$1, integer(%rbp)	# shift bits of integer over once
	incl	str(%rbp)		# increment string's pointer
	incl	%r8			# keep track of string's length

	
	