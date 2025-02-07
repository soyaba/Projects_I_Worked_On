.include "macros.s"
.include "crt0.s"


.text
    main:
   	 
   		 
   		 $MOVEI R3, 0x8000;
   	 do:    IN R1, Rest_tec;
   		 BZ R1,do;
   		 
   		 
   		 MOVI R2,4;
   		 out Rfil_pant, R2;
   		 MOVI R2, 8;
   		 out Rcol_pant, R2;
   		 
   		 $MOVEI R0,tteclat;
   		 in R2, Rdat_tec;
   		 ADD R2,R0,R2;
   		 LDB R2,0(R2);
   		 out Rdat_pant, R2;
   		 out Rcon_pant, R3;
   		 HALT

