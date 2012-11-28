	.equ	localRoom, -16
	.equ	charArray, -10
	.equ	hexNumBit1, -2
	.equ	hexNumBit2, -1
	
        .section        .rodata
prompt:
        .string	"\nEnter a number: "
errorBadInput:
	.string	"\nNot a 0 or a 1.\n"
echo:
	.string	"\nYour number: "
hexEquivalent:
	.string	"\nIn hex: "
answerOdd:
	.string	"\nYour number is odd.\n"
answerEven:
	.string	"\nYour number is even.\n"
	
	.text
.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$localRoom, %rsp

	movl	$prompt, %edi		# print prompt
	movl	$0, %eax		# no floats
	call	printf
	
	movl	$0, %r10		# loop counter
	leaq	charArray(%rbp), %r11	# address of next character to be written
readNum:	
	call	charin			# reads one character into the al register
	movb	%al, (%r11)		# character onto stack in its position
	addl    $1, %r10		# increment counter
	addl    $1, %r11		# increment character pointer
	cmpl	$8, %r10		# iterated 8 times?
	je	out1			# yes, exit loop
	jmp	readNum			# no, go again

out1:
	movl	$0, %r10		# loop counter
	leaq	charArray(%rbp), %r11	# address of next character to be checked
checkInput:
	cmpb	$48, (%r11)		# is it 0?
	je	goodInput		# yes, continue
	cmpb	$49, (%r11)		# no, then was it 1?
	je	goodInput		# yes, continue
	movl	$errorBadInput, %edi	# no, print error message
	movl	$0, %eax		
	call	printf
	jmp	exit			# and exit program
goodInput:
	addl	$1, %r10		# increment counter
	addl	$1, %r11		# increment character pointer
	cmpl	$8, %r10		# iterated 8 times?
	je	out2			# yes, exit loop
	jmp	checkInput		# no, go again

out2:
	movl	$0, %ax			# running total of hex representation value
	movl	$0, %r10d		# single digit of hex storage
	movb	$7, %cl			# loop counter (stops looping at 0)
	leaq	charArray(%rbp), %r11	# address of next character to be converted
charToHex:	
	movl	$0, %r10d		# 0 into temporary storage again
	addl	(%r11), %r10d		# add character's ASCII value to temp
	subl	$48, %r10d		# subtract ASCII '0' from value, leaving 0 or 1
	sarl	%cl, %r10d		# shift digit left (loop counter) times
	addl	%r10d, %ax		# add shifted digit's value to running total
	cmpb	$0, %cl			# iterated 8 times?
	je	out3			# yes, exit loop
					# no, then
	subb	$1, %cl			# decrement loop counter
	addq	$1, %r11		# increment character pointer
	jmp	charToHex

out3:
	leaq	hexNumBit1(%rbp), %r10	# address of first bit of hex
	leaq	hexNumBit2(%rbp), %r11	# address of second bit of hex

	cmpb	$0, %ah			# is it 0?
	je	.0			# yes, go to 0
	cmpb	$1, %ah
	je	.1
	cmpb	$2, %ah
	je	.2
	cmpb    $3, %ah
	je      .3
	cmpb    $4, %ah
	je      .4
	cmpb    $5, %ah
	je      .5
	cmpb    $6, %ah
	je      .6
	cmpb    $7, %ah
	je      .7
	cmpb    $8, %ah
	je      .8
	cmpb    $9, %ah
	je      .9
	cmpb    $10, %ah
	je      .A
	cmpb    $11, %ah
	je      .B
	cmpb    $12, %ah
	je      .C
	cmpb    $13, %ah
	je      .D
	cmpb    $14, %ah
	je      .E
	
	movb	$70, (%r10)		# if none of these, then it must be F
	jmp	out4
.0:
	movb	$48, (%r10)
	jmp	out4
.1:
	movb    $49, (%r10)
	jmp     out4
.2:
	movb    $50, (%r10)
        jmp     out4
.3:
	movb    $51, (%r10)
	jmp     out4
.4:
	movb    $52, (%r10)
	jmp     out4
.5:
	movb    $53, (%r10)
	jmp     out4
.6:
	movb    $54, (%r10)
	jmp     out4
.7:
	movb    $55, (%r10)
	jmp     out4
.8:
	movb    $56, (%r10)
	jmp     out4
.9:
	movb    $57, (%r10)
	jmp     out4
.A:
	movb    $65, (%r10)
	jmp     out4
.B:
	movb    $66, (%r10)
	jmp     out4
.C:
	movb    $67, (%r10)
	jmp     out4
.D:
	movb    $68, (%r10)
	jmp     out4
.E:
	movb    $69, (%r10)
	jmp     out4

out4:
	
exit:
	leave
	ret
	