.include "macros.s"
.include "crt0.s"
.data
    ticks: .word 0
    seg:   .byte 0
       	.balign 2
    ready: .byte 0
       	.balign 2
    v: .asciz "Aquest programa funciona."
   	.fill 5,1,0
    
.text

main:

    $MOVEI R0, interrupts_vector
    $MOVEI R1, clock
    ST 0(R0), R1   	 
    MOVI R2, 1
    OUT Rcon_rel, R2    
    $MOVEI R1, printer
    ST 2*7(R0), R1
    MOVI R2, 1
    OUT Rcon_imp, R2    
    EI   	 
    $MOVEI R2, v    
    $MOVEI R0, seg

bucle:
    
    LDB R4, 0(R0)
    BZ R4, bucle   	 
    $MOVEI R4, ready
    LDB R4, 0(R0)   	 
    BZ R4, bucle   	 
    MOVI R4, 0
    $MOVEI R5, seg
    STB 0(R5), R4   	 
    $MOVEI R5, ticks
    STB 0(R5), R4   	 
    IN R5, Rest_imp
    LDB R4, 0(R2)   	 
    OUT Rdat_imp, R4    
    $MOVEI R3, 0x8001    
    OUT Rcon_imp, R3
    ADDI R2, R2, 1   	 
    MOVI R5, 0    
    $CMPEQ R5, R4, R5    
    BNZ R5, fi
    BZ R5, bucle    

clock:
    $MOVEI R0, ticks
    LD R1, 0(R0)
    ADDI R1,R1,1
    ST 0(R0), R1   	 
    MOVI R2, 10
    $CMPGE R2, R1, R2    
    BZ R2, fiCLK
    MOVI R1, 1    
    $MOVEI R0, seg
    STB 0(R0), R1   	 

fiCLK:
    JMP R6    
fi:
    HALT

printer:
    $MOVEI R0, ready
    MOVI R1, 1
    STB 0(R0), R1   	 
    JMP R6





