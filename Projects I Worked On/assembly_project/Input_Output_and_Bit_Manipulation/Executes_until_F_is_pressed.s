.include "macros.s"
.include "crt0.s"


.text
    main:
   	 
   		 MOVI R6,4;
   		 MOVI R7, 8;
   		 
   		 $MOVEI R3, 0x8000;
   	 do:        IN R1, Rest_tec;
   		 BZ R1,do;
   		 
   		 $MOVEI R0,tteclat;
   		 in R2, Rdat_tec;
   		 ADD R2,R0,R2;
   		 LDB R2,0(R2);
   		 
   		 $MOVEI R5,'F;
   		 CMPEQ R4,R5,R2;

   		 out Rfil_pant, R6;
   		 out Rcol_pant, R7;
   		 ADDI R7,R7,1;
   		 out Rdat_pant, R2;
   		 out Rcon_pant, R3;
                           BNZ R4,fi;
   		 BNZ R3,do;
   		 
   	 fi:    
   		 HALT
