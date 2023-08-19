################################
.text 

	addi s0, zero, 5
	addi s1, zero, 10
	
for:
	beq  t0, s0, fim
	add  s1, s1, t0
	addi t0, t0, 1
	jal  zero, for
fim:
################################