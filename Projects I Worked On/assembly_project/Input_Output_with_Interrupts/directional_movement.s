.include "macros.s"
.include "crt0.s"

.data

    ticks:    .word 0
    final:    .byte 0
    tecla:    .byte 'S'
    
.text
    main:
   	 MOVI R4,4
   	 MOVI R3,8
   	 $MOVEI R5,0x8000
   	 $MOVEI R1,'X'
   	 
   	 OUT Rfil_pant, R4
   	 OUT Rcol_pant,R3
   	 OUT Rdat_pant,R1
   	 OUT Rcon_pant,R5
   	 
   	 $MOVEI R0,interrupts_vector
   	 $MOVEI R2,clock
   	 ST 0(R0),R2
   	 MOVI R2,1
   	 OUT Rcon_rel, R2
   	 EI
   		 
   	 $MOVEI R0,interrupts_vector
   	 $MOVEI R2,teclat
   	 ST 2(R0),R2
   	 MOVI R2,1
   	 OUT Rcon_tec, R2
   	 EI   		 
      
    bucle:    $MOVEI R0, final
   	 LDB R2, 0(R0)
   	 BZ R2, bucle
   	 
   	 MOVI R1, 0    
   	 STB 0(R0), R1
   	 
   	 $MOVEI R0, ticks    
   	 ST 0(R0), R1
   	 
   	 
   	 $MOVEI R0, tecla
   	 LDB r2,0(r0)
   	 
   	 
   			 
   	 $movei R1, ' '
   	 OUT Rdat_pant,R1
   	 OUT Rcon_pant,R5
   	 
   	 
   	 $MOVEI R1,'A
   	 CMPEQ R1,R1,R2
   	 BNZ R1,A
   	 
   	 $MOVEI R1,'S
   	 CMPEQ R1,R1,R2
   	 BNZ R1,S
   	 
   	 $MOVEI R1,'L
   	 CMPEQ R1,R1,R2
   	 BNZ R1,L
   	 
   	 $MOVEI R1,'P
   	 CMPEQ R1,R1,R2
   	 BNZ R1,P
   			 
   	 
    S:    
   	 ADDI R3,R3,1
   	 
   	 $MOVEI R1,'S
   	 $MOVEI r2,tecla
   	 STB 0(r2),r1
   	 
   	 $MOVEI R2,64
   	 CMPEQ R2,R2,R3
   	 BNZ R2,fi
   	 BZ r2,imp
   				 
    
    A:    
   	 ADDI R3,R3,-1
   	 
   	 $MOVEI R1,'A
   	 $MOVEI r2,tecla
   	 STB 0(r2),r1
   	 
   	 $MOVeI R2,-1
   	 CMPEQ R2,R2,R3
   	 BNZ R2,fi
   	 BZ R2,imp
   	 
    L:    
   	 
   	 ADDI R4,R4,-1
   	 
   	 $MOVEI R1,'L
   	 $MOVEI r2,tecla
   	 STB 0(r2),r1
   	 
   	 $MOVEI R2,-1
   	 CMPEQ R2,R2,R4
   	 BNZ R2,fi
   	 BZ R2,imp   	 
   	 
   	 
    P:    
   	 
   	 ADDI R4,R4,1
   	 
   	 $MOVEI R1,'P
   	 $MOVEI r2,tecla
   	 STB 0(r2),r1
   	 
   	 MOVI R2,16
   	 CMPEQ R2,R2,R4
   	 BNZ R2,fi
   	 BZ R2,imp
   	 
   	 
   	 
    imp:    
   	 OUT Rfil_pant,R4
   	 OUT Rcol_pant,R3
   	 $MOVEI R1,'X
   	 OUT Rdat_pant,R1
   	 OUT Rcon_pant,R5
   	 BZ R2,bucle    
   		 
   	 
    fi:    HALT
    
    
   	 
   	 

   	 
clock:
   	 $MOVEI R0, ticks  
   	 LD R1, 0(R0)    
   	 ADDI R1,R1,1    
   	 ST 0(R0), R1   	 
   	 MOVI R2, 2
   	 $CMPGE R2, R1, R2    
   	 BZ R2, fiCLK
   	 
   	 MOVI R1, 1    
   	 $MOVEI R0, final
   	 STB 0(R0), R1    
   	 
    fiCLK:  
   	 JMP R6
    
    
teclat:    
   	 
   	 $MOVEI R3, tteclat
   	 IN R1, Rdat_tec
   	 ADD R1, R3, R1
   	 LDB R1, 0(R1)
   	 $MOVEI R0, tecla
   	 STB 0(R0), R1

   	 JMP R6    
    
	
 







