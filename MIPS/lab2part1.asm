.data

greet:	.asciiz "Hello! Welcome to Providence College.\nWe have so many classes here!\n"
askname: .asciiz "First off, what is your name? "
name:	.word 0:19
size:	.word 20
greet2: .asciiz "Nice to meet you, "
askclass: .asciiz "What is your favourite class at PC? (3 letters): \n"
class: .word 0:5
classsize: .word 5
greet3:	.asciiz "Thats great! I love "
asknum:	.asciiz "What are your favourite courses in "
course1: .word 1
course2: .word 2
course3: .word 3
closing1: .asciiz "Thanks, "
closing2: .asciiz "I see that you like "
closing3: .asciiz "courses: "
closing4: .asciiz ". That is so great. Thats all for now. Thanks!"
comma:	.asciiz ", "
	
.text

	la $a0, greet
	li $v0, 4
	syscall	
	
	la $a0, askname
	syscall
	
	la $a0, name
	la $t0, size
	lw $a1, 0($t0)
	li $v0, 8
	syscall
	
	la $a0, greet2
	li $v0, 4
	syscall
	
	la $a0, name
	syscall
	
	la $a0, askclass
	syscall
	
	
	la $a0, class
	la $t0, classsize
	lw $a1, 0($t0)
	li $v0, 8
	syscall
	
	la $a0, greet3
	li $v0, 4
	syscall
	
	la $a0, class
	syscall
	
	la $a0, asknum
	li $v0, 4
	syscall
	
	la $a0, class
	syscall
	
	li, $v0, 5
	syscall 
	la $t1, course1
	sw $v0, 0($t1)
	
	li, $v0, 5
	syscall 
	la $t1, course2
	sw $v0, 0($t1)
	
	li, $v0, 5
	syscall 
	la $t1, course3
	sw $v0, 0($t1)
	
	la $a0, closing1
	li $v0, 4
	syscall
	
	la $a0, name
	syscall
	
	la $a0, closing2
	li $v0, 4
	syscall
	
	la $a0, class
	syscall
	
	la $a0, closing3 
	li $v0, 4
	syscall
	
	la $t1, course1
	lw $a0, 0($t1)
	li $v0, 1
	syscall
	
	
	la $a0, comma
	li $v0, 4
	syscall
	
	
	la $t1, course2
	lw $a0, 0($t1)
	li $v0, 1
	syscall
	
	
	la $a0, comma
	li $v0, 4
	syscall 
	
	la $t1, course3
	lw $a0, 0($t1)
	li $v0, 1
	syscall

	la $a0, closing4
	li $v0, 4
	syscall
	
