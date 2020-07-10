.data

.text

	lw $t0, 0xffff0000
	ori $t0, $t0, 0x00000002
	sw $t0, 0xffff0000

	mfc0 $t1, $12 #status
	ori $t1, $t1, 0x00000800
	mtc0 $t1,$12

wait: 	j wait

.ktext 0x80000180

	lb $a0, 0xffff0004

	li $v0, 11
	syscall
	eret
