
.data
result: .word 0

.text
.align 2
.globl main
main:
	addi $sp, $sp, -4
	sw $ra,0($sp)
	
	addi $a0,$zero,2
	addi $a1,$zero,5
	jal potencia_recursiva
	la $t1,result
        sw $v0, 0($t1)

	lw $ra,0($sp)
	addi $sp,$sp,4
	jr $ra

	
.end main



potencia_recursiva:
	addi $sp,$sp,-8
	sw $ra,4($sp)
	sw $a1,0($sp)
	
	beq $a1,$zero,res1
	addi $t1,$zero,1
	beq $a1,$t1,res2
	div $a1,$a1,2
	jal potencia_recursiva
	
	lw $a1,0($sp)
	add $t3,$a1,$zero
	div $a1,$a1,2
	sub $a1,$t3,$a1
	addi $sp,$sp,-4
	sw $v0,0($sp)
	jal potencia_recursiva
	lw $t4,0($sp)
	addi $sp,$sp,4
	mul $v0,$v0,$t4
	lw $ra,4($sp)
	addi $sp,$sp,8
	jr $ra 

res1:	addi  $v0,$zero,1
	lw $ra,4($sp)
	addi $sp,$sp,8
	jr $ra

res2:	add  $v0,$zero,$a0
	lw $ra,4($sp)
	addi $sp,$sp,8
	jr $ra