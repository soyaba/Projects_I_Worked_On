.include "macros.s"
.include "crt0.s"


.data

vec:    .byte    'F','i'

.text
main:

   	 movi R2,2;
   	 $movei R1, vec;
   	 movi r0, 0;
   	 out Rcon_imp, r0;
   	 $movei r3,0x8000;
   	 
    for:    CMPEQ r4,r2,r0;
   	 bnz R4, fi_for;
   	 
    do:    in r5, Rest_imp;
   	 bz R5,do;
   	 
   	 ldb r5, 0(R1);
   	 out Rdat_imp, R5;
   	 out Rcon_imp,R3;
   	 addi r1,r1,1;
   	 addi r0,r0,1;
   	 BNZ r2 ,for;
    fi_for:    
    do_2:    in R5,Rest_imp;
   	 bz R5,do_2;
   	 HALT	
