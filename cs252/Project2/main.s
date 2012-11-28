	.equ	localRoom, -16
	.equ	index, -14
	.equ	charArray, -10
	.equ	hexNumBit1, -2
	.equ	hexNumBit2, -1
	
        .section        .rodata
prompt:
        .string	"\nEnter a number: "		# 18

errorBadInput:
	.string	"\nNot a 0 or a 1.\n"		# 17

echo:
	.string	"\nYour number: "		# 14

hexEquivalent:
	.string	"\nIn hex: "			# 9

answerOdd:
	.string	"\nYour number is odd.\n"	# 21

answerEven:
	.string	"\nYour number is even.\n"	# 22
	
	.text
.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$localRoom, %rsp

	movl	$1, %edi			# STDIN_FILENO
	movl	$prompt, %esi			# print prompt
	movl	$18, %edx			# 18 chars
	call	write

	movl	$0, index(%rbp)			# index = 0
readNum:	
	call	charin				# reads one character into the al register
	movl	index(%rbp), %eax		# load index value
	cltq					# convert to 64-bit
	movb	%al, charArray(%rbp, %rax, 1)	# charArray[index] = value in al
	addl    $1, index(%rbp)			# increment index
	cmpl	$8, index(%rbp)			# iterated 8 times?
	je	out1				# yes, exit loop
	jmp	readNum				# no, go again

out1:
	movl	$0, index(%rbp)			# index = 0
checkInput:
	movl	index(%rbp), %eax		# load index value
	cltq					# convert to 64-bit
	cmpb	$48, charArray(%rbp, %rax, 1)	# is it 0?
	je	goodInput			# yes, continue
	cmpb	$49, charArray(%rbp, %rax, 1)	# no, then was it 1?
	je	goodInput			# yes, continue
#	movl	$1, %edi			
#	movl	$errorBadInput, %esi		# no to both, print error message
#	movl	$17, %edx		
#	call	write
#	jmp	exit				# and exit program
goodInput:
	addl	$1, index(%rbp)			# increment counter
	cmpl	$8, index(%rbp)			# iterated 8 times?
	je	out2				# yes, exit loop
	jmp	checkInput			# no, go again

out2:
	movl	$1, %edi
	movl	$echo, %esi
	movl	$14, %edx
	call	write
	
	movl	$0, index(%rbp)			# index = 0
loopEcho:
	movl	index(%rbp), %eax
	cltq
	movb	charArray(%rbp, %rax, 1), %al
	call	charout
	addl	$1, index(%rbp)			# increment index
	cmpl	$8, index(%rbp)			# 8th iteration?
	je	out3				# yes, get outta there
	jmp	loopEcho			# no, once more

out3:
	movl	$7, index(%rbp)
	movl	index(%rbp), %eax
	cltq
	cmpb	$49, charArray(%rbp, %rax, 1)
	je	oddPrint
	movl	$1, %edi
	movl	$answerEven, %esi
	movl	$22, %edx
oddPrint:
	movl    $1, %edi
	movl    $answerOdd, %esi
	movl    $21, %edx
	
exit:
	leave
	ret
	