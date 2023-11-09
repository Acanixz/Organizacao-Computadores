.data
	matriz_A: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99
	matriz_B: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100
	
	msg_inputOrdem: .asciz "Entre com o tamanho do índice das matrizes (máx. = 10)\nValor fornecido: "
	msg_inputIteracao: .asciz "Informe o tipo de iteração\n0 - Linha-coluna\n1 - Coluna-linha\nOpção Escolhida: "
	msg_inputInvalido: .asciz "Valor invalido, tente novamente!\n\n"
	
	linha: .asciz "\n"
	tab: .asciz "\t"
	
.text
#	*************************************************************************
jal zero, main

main:
							# Parametros:
							# a0 = tipo de iteração
							# a1 = ordem da matriz
							# a2 = matriz_A
							# a3 = matriz_B
							
							# Pede a ordem das matrizes
	jal	pedir_ordem
	add	a1, a0, zero				# Posiciona ordem em a1
	
	jal	pedir_iteracao				# OBS: iteração já retorna em a0
	
	la	a2, matriz_A				# Carrega matriz_A
	la	a3, matriz_B				# Carrega matriz_B
	
	addi	t0, zero, 0				# Valor p/ primeiro branch
	addi	t1, zero, 1				# Valor p/ segundo branch
	
	beq	a0, t0, somar_IJ			# Soma com iteração IJ
	beq	a0, t1, somar_JI			# Soma com iteração JI

#	*************************************************************************

pedir_ordem:
							# Imprime string
	addi	a7, zero, 4
	la	a0, msg_inputOrdem
	ecall
	
							# Le inteiro
	addi	a7, zero, 5
	ecall
	
							# Prepara valores inteiros
	addi	t0, zero, 1
	addi	t1, zero, 10
	
							# Comparação de limite
	ble	a0, t0, ordem_fail 			# if input <= 1: jump ordem_fail
	bgt	a0, t1, ordem_fail 			# if input > 10: jump ordem_fail
	
	jalr	zero, ra, 0 				# Retorna pra main
	
ordem_fail:
							# Imprime string
	addi	a7, zero, 4
	la	a0, msg_inputInvalido
	ecall
	
	j	pedir_ordem				# Tenta pedir novamente

#	*************************************************************************

pedir_iteracao:
							# Imprime string
	addi	a7, zero, 4
	la	a0, msg_inputIteracao
	ecall
	
							# Le inteiro
	addi	a7, zero, 5
	ecall
	
							# Prepara valores inteiros
	addi	t0, zero, 0
	addi	t1, zero, 1
	
							# Comparação de limite
	blt	a0, t0, iteracao_fail			# if input < 0: jump ordem_fail
	bgt	a0, t1, iteracao_fail			# if input > 1: jump ordem_fail
	
	jalr	zero, ra, 0				# Retorna pra main

iteracao_fail:
							# Imprime string
	addi	a7, zero, 4
	la	a0, msg_inputInvalido
	ecall
	
	j	pedir_iteracao				# Tenta pedir novamente

#	*************************************************************************

somar_IJ:
							# Parametros:
							# a1 = ordem da matriz
							# a2 = matriz_A (endereço base)
							# a3 = matriz_B (endereço base)
							
							# t0 = iterador i
							# t1 = iterador j
							# t2 = iterador i (posição de memoria)
							# t3 = iterador j (posição de memoria)
							# t4 = i+j (posição de memoria alvo)
							# t5 = matriz_A[i][j]
							# t6 = matriz_B[i][j]
							
							# Durante operação de soma:
							# t2 = valor de matriz_A[i][j]
							# t3 = valor de matriz_B[i][j]
							# t4 = posição de memoria alvo (mantém)
							# a0 = matriz_A[i][j] + matriz_B[i][j]
							
							# OBS: label do for loop usa sufixo _0
							
	add	t0, zero, zero				# Reset iterador i
	add	t1, zero, zero				# Reset iterador j
	for_i_0:
		add	t1, zero, zero			# Reset iterador j
		beq	t0, a1, fim_i_0			# if iterador i == ordem: jump fim_i_0
		for_j_0:
			beq	t1, a1, fim_j_0		# if iterador j == ordem: jump fim_j_0
			
							# Calculo de posição das matrizes
			slli	t2, t0, 2		# t2 = iterador i * 4
			slli	t3, t1, 2		# t3 = iterador j * 4
			mul	t2, t2, a1		# t2 = (i*4*)ordem
			add	t4, t2, t3		# t4 = i + j
			
							# Obtenção das matrizes (endereço)
			add	t5, a2, t4		# t5 = matriz_A(base) + (i+j) [mem. alvo]
			add	t6, a3, t4		# t6 = matriz_B(base) + (i+j) [mem. alvo]
			
							# Carregamento dos valores e soma
			lw	t2, 0(t5)   		# t2 = valor de matriz_A[i][j]
			lw	t3, 0(t6)   		# t3 = valor de matriz_B[i][j]
			add	a0, t2, t3		# a0 = t2 + t3
			
							# Salvamento dos dados e imprime
			addi 	sp, sp, -4 		# Aumenta stack pointer em 4 bytes (1 instrução)
			sw	a0, 0(sp)		# Armazena soma em sp (sem offset)
			addi	a7, zero, 1
			ecall				# Imprime o valor
			addi	a7, zero, 4
			la	a0, tab
			ecall				# Imprime tabulação
			
							# Completa iteração j
			addi	t1, t1, 1		# j++
			jal	zero, for_j_0		# Volta para o começo do for j
fim_i_0:
	j end
	
fim_j_0:
	addi	a7, zero, 4
	la	a0, linha
	ecall						# Imprime \n
	
	addi	t0, t0, 1				# i++
	jal	zero, for_i_0				# Volta para o começo do for i

#	*************************************************************************

somar_JI:
							# Parametros:
							# a1 = ordem da matriz
							# a2 = matriz_A (endereço base)
							# a3 = matriz_B (endereço base)
							
							# t0 = iterador i
							# t1 = iterador j
							# t2 = iterador i (posição de memoria)
							# t3 = iterador j (posição de memoria)
							# t4 = i+j (posição de memoria alvo)
							# t5 = matriz_A[j][i]
							# t6 = matriz_B[j][i]
							
							# Durante operação de soma:
							# t2 = valor de matriz_A[j][i]
							# t3 = valor de matriz_B[j][i]
							# t4 = posição de memoria alvo (mantém)
							# a0 = matriz_A[j][i] + matriz_B[j][i]
							
							# OBS: label do for loop usa sufixo _1
							
	add	t0, zero, zero				# Reset iterador i
	add	t1, zero, zero				# Reset iterador j
	for_i_1:
		add	t1, zero, zero			# Reset iterador j
		beq	t0, a1, fim_i_1			# if iterador i == ordem: jump fim_i_1
		for_j_1:
			beq	t1, a1, fim_j_1		# if iterador j == ordem: jump fim_j_1
			
							# Calculo de posição das matrizes
			slli	t2, t0, 2		# t2 = iterador i * 4
			slli	t3, t1, 2		# t3 = iterador j * 4
			mul	t3, t3, a1		# t3 = (j*4*)ordem
			add	t4, t2, t3		# t4 = i + j
			
							# Obtenção das matrizes (endereço)
			add	t5, a2, t4		# t5 = matriz_A(base) + (i+j) [mem. alvo]
			add	t6, a3, t4		# t6 = matriz_B(base) + (i+j) [mem. alvo]
			
							# Carregamento dos valores e soma
			lw	t2, 0(t5)   		# t2 = valor de matriz_A[i][j]
			lw	t3, 0(t6)   		# t3 = valor de matriz_B[i][j]
			add	a0, t2, t3		# a0 = t2 + t3
			
							# Salvamento dos dados e imprime
			addi 	sp, sp, -4 		# Aumenta stack pointer em 4 bytes (1 instrução)
			sw	a0, 0(sp)		# Armazena soma em sp (sem offset)
			addi	a7, zero, 1
			ecall				# Imprime o valor
			addi	a7, zero, 4
			la	a0, tab
			ecall				# Imprime tabulação
			
							# Completa iteração j
			addi	t1, t1, 1		# j++
			jal	zero, for_j_1		# Volta para o começo do for j
fim_i_1:
	j end
	
fim_j_1:
	addi	a7, zero, 4
	la	a0, linha
	ecall						# Imprime \n
	
	addi	t0, t0, 1				# i++
	jal	zero, for_i_1				# Volta para o começo do for i

#	*************************************************************************

end:
	addi	a7, zero, 10				# Finaliza programa
	ecall
