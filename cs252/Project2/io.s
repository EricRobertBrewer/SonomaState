	.section	.rodata
integer:
	.string	"%i"

	.text
.globl	charin
	.type	charin, @function
charin:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp

loopRead:	
	movl	$0, %edi		# STDIN_FILENO
	leaq	-4(%rbp), %rsi		# address of in_char
	movl	$1, %edx		# one character
	call	read
	cmpb	$13, -4(%rbp)		# did it read in the carriage return?(!)
	je	loopRead		# if so, try again

	movb	-4(%rbp), %al		# in_char into al
	
	leave
	ret

	
.globl	charout
	.type	charout, @function
charout:
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$16, %rsp

	movb	%al, -4(%rbp)		# data that's stored in al to out_char
	
	movl	$1, %edi		# STDOUT_FILENO
	leaq	-4(%rbp), %rsi		# address of out_char
	movl	$1, %edx		# one character
	call	write

	leave
	ret
	