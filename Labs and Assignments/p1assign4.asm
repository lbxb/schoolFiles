.text

main:

lb $t0, 0xffff0000 #load fbit for key
beqz $t0, main
lb $t1, 0xffff0004
sb $t1, 0xffff000c

#loads address of tcr
loop: la $t2, 0xffff0008
beqz $t2, loop
andi $t0, 0x00000000
j main