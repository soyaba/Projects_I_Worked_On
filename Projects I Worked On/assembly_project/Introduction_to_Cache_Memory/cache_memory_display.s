.include "macros.s"
.include "crt0.s"
.data
    
    X: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    Y: .word -2, 0, 3, 6, -2, 12, -3, 14, 5, 6
    Z: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0


    .balign 2
    .text
    

main:
   	 MOVI R0, 0
   	 $MOVEI R1, X
   	 $MOVEI R2, Y
   	 $MOVEI R3, Z
   	 MOVI R4,4
   	 
    for:    MOVI R5,10
   	 CMPEQ R5,R5,R0
   	 BNZ R5,fi
   	 
   	 $PUSH R5
   	 
   	 LD R6,0(R1)
   	 LD R5,0(R2)
   	 ADD R5,R5,R6
   	 ST 0(R3),R5
   	 ADDI R0,R0,1
   	 
   	 $PUSH R0,R2,R3
   	 ADDI R0,R1,0
   	 $MOVEI R2,-3
   	 SHL R3,R0,R2
   	 $MOVEI R2,0X01FF
   	 AND R3,R3,R2
   	 $MOVEI R2,-12
   	 SHL R0,R0,R2  #tag
   	 out Rfil_pant,r4
   	 
   	 MOVI R2,'0'
   	 MOVI R6,15
    bucle1: BZ R3,y
   	 MOVI R5,1
   	 AND R2,R3,R5
   	 $MOVEI R5,'0'
   	 ADD R2,R2,R5
   	 OUT Rcol_pant,r6
   	 out Rdat_pant,r2
   	 $MOVEI R5,0X8000
   	 OUT Rcon_pant,r5
   	 $MOVEI R5,-1
   	 SHL R3,R3,R5
   	 ADDI R6,R6,-1
   	 movi r5,1
   	 BNZ R5,bucle1
   	 
    y:    $POP R3,R2
   	 $PUSH R1,R3
   	 
   	 ADDI R0,R2,0
   	 $MOVEI R5,-3
   	 SHL R3,R0,R5
   	 $MOVEI R5,0X01FF
   	 AND R3,R3,R5
   	 $MOVEI R5,-12
   	 SHL R0,R0,R5
   	 OUT Rfil_pant,R4
   	 
   	 MOVI R1,'0'
   	 MOVI R6,30
    bucle2: BZ R3,z
   	 MOVI R5,1
   	 AND R1,R3,R5
   	 $MOVEI R5,'0'
   	 ADD R1,R1,R5
   	 OUT Rcol_pant,r6
   	 out Rdat_pant, r1
   	 $movei r5,0x8000
   	 out Rcon_pant,r5
   	 $movei r5,-1
   	 SHL R3,R3,R5
   	 ADDI R6,R6,-1
   	 movi r5,1
   	 BNZ R5,bucle2
   	 
    z:    $POP R3,R1
   	 $PUSH R1,R2
   	 
   	 ADDI R0,R3,0
   	 $MOVEI R5,-3
   	 SHL R2,R0,R5
   	 $MOVEI R5,0X01FF
   	 AND R2,R2,R5
   	 $MOVEI R5,-12
   	 SHL R0,R0,R5
   	 OUT Rfil_pant,r4
   	 
   	 MOVI R1,'0'
   	 $MOVEI R6,45
    bucle3: BZ r2,fibucle
   	 MOVI R5,1
   	 AND R1,R2,R5
   	 $MOVEI R5,'0'
   	 ADD R1,R1,R5
   	 OUT Rcol_pant,r6
   	 out Rdat_pant,r1
   	 $movei r5,0x8000
   	 out Rcon_pant,r5
   	 $movei r5,-1
   	 SHL R2,R2,R5
   	 ADDI R6,R6,-1
   	 movi r5,1
   	 BNZ R5,bucle3
   	 
    fibucle:$POP R2,R1,R0,R5
   	 ADDI R4,R4,1
   	 ADDI R1,R1,2
   	 ADDI R2,R2,2
   	 ADDI R3,R3,2
   	 BZ R5,for
   	 
    fi:    HALT   				 
    	




