.data
Y:.word 0
.text
.align 2
.globl main


main:
	addi $sp, $sp, -4
	sw $ra,0($sp)
	
	addi $t0,$zero,10
	addi $t1,$zero,-3
	addi $t2,$zero,2
	addi $t3,$zero,0
	
	addi $a0,$t3,0
	addi $a1,$zero,2

	jal potencia
	
	mul $t4,$t0,$v0
	mul $t5,$t1,$t3
	add $t4,$t4,$t5
	add $t4,$t4,$t2

	la $t1,Y
	sw $t4,0($t1)

	lw $ra,0($sp)
	addi $sp, $sp, 4
	jr $ra

.end main



potencia:

    addi $sp, $sp, -8
    sw $ra,4($sp)
    sw $ra,0($sp)
    
    beq $a1, $zero, res1
    addi $t6,$zero,0
    addi $v0,$zero,1	
    
bucle:    beq $t6,$a1,fi_bucle
	  mul $v0,$v0,$a0
	  addi $t6,$t6,1
          j bucle

fi_bucle:
	  lw $ra, 4($sp)
	  lw $ra, 0($sp)
	  addi $sp, $sp, 8
	  jr $ra

   		 	 
   	 
res1:
	addi $v0, $zero, 1
	lw $ra, 4($sp)
	lw $ra, 0($sp)
	addi $sp, $sp, 8
	jr $ra