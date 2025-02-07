#include <stdio.h>

// Mock functions to simulate SISA-F hardware behavior
int in(int register_name) {
    int value;
    printf("Reading from register %d: ", register_name);
    scanf(" %c", (char *)&value);  // Simulate key press input
    return value;
}

void out(int register_name, int value) {
    printf("Writing value 0x%X to register %d\n", value, register_name);
}

// Simulated keyboard mapping (tteclat array)
char tteclat[256];  // Key mapping lookup table

int main() {
    int invar;
    char c;

    // Wait for the first key press
    do {
        invar = in(0);  // Rest_tec = 0 (keyboard status register)
    } while (invar == 0);

    // Repeatedly read and display pressed keys until 'F' is pressed
    do {
        c = in(1);          // Read pressed key from Rdat_tec
        c = tteclat[(unsigned char)c];  // Convert using keyboard mapping

        out(2, 4);       // Set row position (Rfil_pant)
        out(3, 8);       // Set column position (Rcol_pant)
        out(4, c);       // Display character (Rdat_pant)
        out(5, 0x8000);  // Apply display attributes (Rcon_pant)

        invar = in(0);  // Read next key status
    } while (c != 'F');  // Exit loop when 'F' is pressed

    return 0;
}

