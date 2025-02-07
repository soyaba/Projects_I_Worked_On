.include "macros.s"
.include "crt0.s"

.data
w: .word 0x8888

.text

    
main:
    
    while:    $CALL R6,mostra
    
    
    do:    IN R1, Rest_tec;
   	 BZ R1,do;
   	 
   	 $MOVEI R0,tteclat;
   	 in R2, Rdat_tec;
   	 ADD R2,R0,R2;
   	 LDB R2,0(R2);
   	 
   	 $MOVEI R0, w 	 
   	 LD R0, 0(R0)
   	 
   	 $MOVEI R3,'A;
   	 CMPEQ R3,R3,R2;
   	 BNZ R3,A;
   	 
   	 $MOVEI R3,'B;
   	 CMPEQ R3,R3,R2;
   	 BNZ R3,B;
   	 
   	 $MOVEI R3,'C;
   	 CMPEQ R3,R3,R2;
   	 BNZ R3,C;
   	 
   	 $MOVEI R3,'D;
   	 CMPEQ R3,R3,R2;
   	 BNZ R3,D;
   	 
   	 
   	 
   	 MOVI R4,0
   	 MOVI R5,9
   	 
   	 $MOVEI R7,'0'
   	 SUB R2,R2,R7
   	 CMPLE R4,R4,R2
   	 CMPLE R5,R2,R5
   	 AND R4,R4,R5;
   	 BNZ R4, num;
   	 
   	 
   	 
    A:
   	 MOVI R3, 1
   	 SHL R0, R0, R3
   	 BNZ R3, store

    B:
   	 MOVI R3, -1
   	 SHL R0, R0, R3
   	 BNZ R3, store

    C:
   	 MOVI R3, -1
   	 SHA R0, R0, R3
   	 BNZ R3, store

    D:
   	 MOVI R3, 2
   	 DIV R0, R0, R3
   	 BNZ R3, store    
   	 
    num:    MOVI R3,1
   	 SHL R2,R3,R2
   	 ADDI R2,R2,-1
   	 XOR R0,R0,R2
   	 BNZ R2,store
    
    store:    $MOVEI R3, w
   	 ST 0(R3), R0
   	 BNZ R3, while   	 
   	 HALT
    
    
    
    
    
    
mostra:    
   	 $MOVEI R4, 0x8000
   	 $MOVEI R0, w  	 
   	 LD R0, 0(R0) 	 
   	 MOVI R1, 16   
   	   	 

    for:
   	 
   	 ADDI R1, R1, -1    

   	 OUT Rcol_pant, R1
   	 MOVI R2, 0x1    
   	 AND R2, R0, R2	 
   		 
   	 MOVI R3, '0'  	 
   	 ADD R2, R2, R3
   	 OUT Rdat_pant, R2  
   	 OUT Rcon_pant, R4
   	 MOVI R5,-1
   	 SHL R0,R0,R5
   	 BNZ R1, for
   		 JMP R6    
