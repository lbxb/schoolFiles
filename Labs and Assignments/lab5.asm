.data

rcr:	.word 0xffff0000
rdr:	.word 0xffff0004

.text
main:
	lw $t0, rcr
	lw $t1, rdr	#had to change this to the actual hex because the program would crash otherwise
	
while:	beqz $t0, exit #while the rcr equals 0
	lbu $t3, 31($t1)  #load the last byte of the rdr into t3 (pretty sure this is the issue that im running into but im not too sure how to fix it)
	move $a0, $t3 #load the rdr into a0

	li $v0, 11 #call the print_char funct
	syscall

exit: 
	j main
	
	
	#So this program crashes everytime i try to run it but i basically tried to follow the instructions word for word by
	#1. setting a loop that checks if the rcr is zero or not (using beqz)
	#2. Tried to get the lowest byte from rdr by calling the 31st number using lbu from the register that has rdr stored in it
	#3. moving that into $a0 and then system calling it and looping the entire program
	
	#i personally think that i just have some misconception about the lbu but for right now, im not too sure what to do.
