.include "macros.s"
.include "crt0.s"

.data
w: .word 0x8888

.text

    
main:
    $movei r6, mostra
    JAL r6,r6
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
