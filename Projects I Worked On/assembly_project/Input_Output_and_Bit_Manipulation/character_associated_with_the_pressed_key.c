#include <stdio.h>

// Mock functions to simulate hardware interactions in SISA-F
int in(int register_name) {
    int value;
    printf("Reading from register %d: ", register_name);
    scanf("%d", &value);  // Simulates a hardware input
    return value;
}

void out(int register_name, int value) {
    printf("Writing value 0x%X to register %d\n", value, register_name);
}

// Simulated keyboard mapping (tteclat array)
char tteclat[256];  // Assuming a lookup table for key mappings

int main() {
    int invar;
    char c;

    // Wait until a key is pressed
    invar = in(0);  // Assuming Rest_tec = 0
    while (invar == 0) {
        invar = in(0);
    }

    // Read the pressed key and get its mapped value
    c = in(1);       // Assuming Rdat_tec = 1 (register storing the key pressed)
    c = tteclat[(unsigned char)c];  // Convert using tteclat mapping

    // Display the corresponding character at position [4,8]
    out(2, 4);       // Rfil_pant (row) = 4
    out(3, 8);       // Rcol_pant (column) = 8
    out(4, c);       // Rdat_pant (data) = character from tteclat
    out(5, 0x8000);  // Rcon_pant (control register)

    return 0;
}

