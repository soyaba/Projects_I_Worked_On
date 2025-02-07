.include "macros.s"
.include "crt0.s"
.data

final: .byte 0
.balign 2

.text

main:
$MOVEI R0, interrupts_vector
$MOVEI R1, teclat
ST 1*2(R0), R1
MOVI R2, 1
OUT Rcon_tec, R2
EI


bucle:
$MOVEI R0, final
LDB R0, 0(R0)
BZ R0, bucle
$MOVEI R3, 0x8000
MOVI R4, 4
OUT Rfil_pant, R4
MOVI R4, 8
OUT Rcol_pant, R4
$MOVEI R5, 0x0100
ADD R0, R0, R5
OUT Rdat_pant, R0
OUT Rcon_pant, R3

teclat:
$MOVEI R3, tteclat
IN R1, Rdat_tec
ADD R1, R3, R1
LDB R1, 0(R1)
$MOVEI R0, final
STB 0(R0), R1
JMP R6

