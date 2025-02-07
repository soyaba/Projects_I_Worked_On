.include "macros.s"
.include "crt0.s"
.data

    X: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    Y: .word -2, 0, 3, 6, -2, 12, -3, 14, 5, 6
    Z: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

    .balign 2
    .text
    

main:
    MOVI R1, 0
    $MOVEI R2, X
    $MOVEI R3, Y
    $MOVEI R4, Z

for:
    LD R5, 0(R2)   	 
    LD R0, 0(R3)   	 
    ADD R5, R0, R5   	 
    
    MOVI R0, 10
    $CMPGE R0, R1, R0    
    BNZ R0, fi
    ST 0(R4), R5   	 
    ADDI R1, R1, 1
    ADDI R2, R2, 2
    ADDI R3, R3, 2
    ADDI R4, R4, 2
    BZ R0, for

fi:
    HALT


