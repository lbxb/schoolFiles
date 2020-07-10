li $t0, 2 #getting 2
mul $t1, $s1,$t0 #2*y


sgt $t2, $s0,$t1
beqz $t2, else	
addiu $s0, $s0,1
j endif	#if (x > 2*y)
else:
addiu $s1, $s1, -1	# x++;
endif:		#else
		 #y--;