        .data
data:    .word     0 : 20       # storage for 16x16 matrix of words
out:     .asciiz "The fibonacci numbers are: "
space:   .asciiz " "
         .text

# Ryan O'Connor
# Lab 9 - Fibonnaci
li $t3, 1 #starting num
li $t4, 1 #starting num
li $s1, 18 #counter
la $a0, out # printing the output
li $v0, 4
syscall
li $v0, 1
move $a0, $zero # printing the first 0      
        syscall
la $a0, space
        li $v0, 4
        syscall
loop:   add $t0, $t3, $t4
sub $t4, $t0, $t4 # set t4 to t3
sub $t3, $t3, $t3
add $t3, $t0, $zero # set t3 to t0
li $v0, 1
move $a0, $t0   # printing t0    
        syscall
        
        la $a0, space
        li $v0, 4   # space between nums
        syscall 
        
        subi $s1, $s1, 1 # decrease counter
addi $t0, $t0, 4 # increase array index
bgez $s1, loop # branch if notcounter is greater than or equal to 0
li $v0, 10        # system service 10 is exit
        syscall 