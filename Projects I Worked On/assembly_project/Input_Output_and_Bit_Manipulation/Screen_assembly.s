.include "macros.s"
.include "crt0.s"
.text


main:

           $MOVEI R3, 0x8000;
           MOVI R1, 4;
           MOVI R2, 8;
           OUT Rfil_pant, R1;
           OUT Rcol_pant, R2;
           $MOVEI R4, 0x100+'A';
           OUT Rdat_pant, R4;
           OUT Rcon_pant, R3;
          ADDI R2, R2, 1;
          OUT Rcol_pant, R2;
          $MOVEI R4, 'B';
          OUT Rdat_pant, R4;
          OUT Rcon_pant, R3;

HALT

