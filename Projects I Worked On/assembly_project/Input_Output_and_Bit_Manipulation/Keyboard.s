.include "macros.s"
.include "crt0.s"


.text
    main:
   		 
   		 $MOVEI R3, 0x8000;

   	 do:        IN R1, Rest_tec;
   		 BZ R1,do;
   		 
   		 MOVI R2,4;
   		 MOVI R5, 8;
   		 out Rfil_pant, R2;
   		 out Rcol_pant, R5;
   		 $MOVEI  R4,'A';
   		 out Rdat_pant, R4;
   		 out Rcon_pant, R3;
   		 HALT

