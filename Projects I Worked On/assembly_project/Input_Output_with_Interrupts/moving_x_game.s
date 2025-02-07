.include "macros.s"
.include "crt0.s"

.data

    ticks:    .word 0
    final:    .byte 0
   	 .balign 2
.text
    main:
   	 MOVI R4,'X
   	 $MOVEI R5,0x8000
   	 MOVI R6,64
   	 MOVI R3,4
   	 
   	 OUT Rfil_pant, R3
   	 MOVI R3,8
   	 OUT Rcol_pant,R3
   	 OUT Rdat_pant,R4
   	 OUT Rcon_pant,R5
   	 
   	 $MOVEI R0,interrupts_vector
   	 $MOVEI R1,clock
   	 ST 0(R0),R1
   	 MOVI R2,1
   	 OUT Rcon_rel, R2
   	 EI
   	 
   	 
   	 $MOVEI r1,' '
   	 $MOVEI R0, final
   	 
   	 
   	 
    bucle:  
   	 LDB R2, 0(R0)
   	 BZ R2, bucle
   	 
   	 MOVI R7, 0
   	 $MOVEI R2, final    
   	 ST 0(R2), R7
   	 
   	 $MOVEI R2, ticks    
   	 STB 0(R2), R7
   	 
   	 OUT Rdat_pant,R1
   	 OUT Rcon_pant,R5
   	 ADDI R3,R3,1
   	 
   	 CMPEQ R2,R6,R3
   	 BNZ R2,fi
   	 OUT Rcol_pant,R3
   	 OUT Rdat_pant,R4
   	 OUT Rcon_pant,R5
   	 

   	 BZ R2,bucle
   	 
    fi:    HALT
    
    
   	 
   	 

   	 
clock:
   	 $MOVEI R0, ticks  
   	 LD R1, 0(R0)    
   	 ADDI R1,R1,1    
   	 ST 0(R0), R1   	 
   	 MOVI R2, 4
   	 $CMPGE R2, R1, R2    
   	 BZ R2, fiCLK
   	 
   	 MOVI R1, 1    
   	 $MOVEI R0, final
   	 STB 0(R0), R1
   	 
   	 
   	 
    fiCLK:  
   	 JMP R6
  





