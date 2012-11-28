	.equ	DOWNMASK, 0x20
	.equ	cstrPtr, -8
	.equ	localSize, -32
	
	.text
	.global	toLower
	.type	toLower, @function

toLower:
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$localSize, %rsp

	movq	%rdi, cstrPtr(%rbp)	# character pointer onto stack

LowerLoop:
	movq	cstrPtr(%rbp), %r10	# charcter pointer into r10
	movb	(%r10), %al		# actual character value into al
	cmpb	$0, %al			# null terminator?
	je	next			# yes, end loop

	orb	$DOWNMASK, %al		# make the character lower case
	movb	%al, (%r10)		# put new character at character's old location

	incl	cstrPtr(%rbp)		# increment character pointer
	jmp	LowerLoop		# jump back to conditional statement

next:
	leave
	ret
	