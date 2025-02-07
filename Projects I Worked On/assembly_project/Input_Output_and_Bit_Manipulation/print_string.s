.include "macros.s"
.include "crt0.s"


.data

frase:    .byte 'A','q','u','e','s','t',' ','p','r','o','g','r','a','m','a',' ','f','u','n','c','i','o','n','a';
.text
main:

   	 
   	 $movei R1, frase;
   	 movi r0, 0;
   	 out Rcon_imp, r0;
   	 $movei r3,0x8000;
   	 
    for:    ldb R2,0(r1);
   	 CMPEQ r4,r2,r0;
   	 BNZ r4,fi_for;
   	 
   	 
    do:    in r5, Rest_imp;
   	 bz R5,do;
   	 
   	 ldb r5, 0(R1);
   	 out Rdat_imp, R5;
   	 out Rcon_imp,R3;
   	 addi r1,r1,1;
   	 BNZ r1 ,for;
   	 
    do_2:    in R5,Rest_imp;
   	 bz R5,do_2;
    fi_for:    
HALT	
