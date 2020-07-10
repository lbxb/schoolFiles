  .data
 prompt1: .asciiz "Input an integer: " 
 prompt2: .asciiz "Input another integer: " 
 num1: .word 0:4
 num2: .word 0:4
 overflow: .asciiz "Overflow has occured"
  
  .text
     
     	la $a0, prompt1		#prompt 1
	li $v0, 4
	syscall 
	
	li, $v0, 5		#get num 1
     	syscall 
      	move $s0, $v0
		
	la $a0, prompt2		#prompt 2
	li $v0, 4
	syscall
	 
	li, $v0, 5		#get num 2
	syscall 
	move $s1, $v0
	
	add $s3, $s0, $s1
	move $a0, $s3
	li $v0, 1
      	syscall  
      	
      	lw $t0, 0xffff0000 # load the RCR
	ori $t0, 0x00000002 # set bit 1 of the RCR to enable keyboard interrupts
     	sw $t0, 0xffff0000 # store the value back in the RCR
  
  	mfc0 $t0, $12
	ori $t0, 0x00000800  # enable interrupts globally  bit 11 is keyboard
	mtc0 $t0, $12

	wait: j wait     # use the CPU resources wisely

	.ktext 0x80000180  # location of interrupt code
	move $k0, $a0     # save the state using kernel registers
	move $k1, $v0
	lb $a0, 0xffff0004 # address of RDR (contains byte from keyboard)
	li $v0, 11    # sycall 11 is print_char
	syscall
	move $a0, $k0
	move $v0, $k1
	la $a0, overflow 
	li $v0,  4
	eret     # return from the interrupt
