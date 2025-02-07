#include <stdio.h>

// Mock function to simulate SISA-F hardware interactions
int in(int register_name) {
    int value;
    printf("Reading from register %d: ", register_name);
    scanf(" %c", (char *)&value);  // Simulate key press input
    return value;
}

void out(int register_name, int value) {
    printf("Writing value 0x%X to register %d\n", value, register_name);
}

// Function to display the binary representation of a number on screen
void mostra(int i) {
    int col = 16;  // Column position (starting from the rightmost position)
    out(0, 0);     // Rfil_pant (set row to 0)

    do {
        col--;  // Move to the previous column
        out(1, col);            // Rcol_pant (set column position)
        out(2, '0' + (i & 0x1)); // Extract LSB and convert to ASCII ('0' or '1')
        out(3, 0x8000);         // Rcon_pant (apply screen attributes)
        i = i >> 1;             // Shift right to process the next bit
    } while (col > 0);
}

// Main function to handle user input and modify `w`
int main() {
    int w = 0x8888;  // Word-sized variable
    char tecla;
    int invar;

    while (1) {  // Infinite loop
        mostra(w);  // Display `w` in binary

        // Wait for a key press
        do {
            invar = in(0);  // Rest_tec = 0 (keyboard status register)
        } while (invar == 0);

        // Read the pressed key
        tecla = in(1);  // Rdat_tec (keyboard data register)

        // Modify `w` based on key input
        if (tecla == 'A') {
            w = w << 1;  // Logical shift left
        } else if (tecla == 'B') {
            w = w >> 1;  // Logical shift right
        } else if (tecla == 'C') {
            w = (signed int)w >> 1;  // Arithmetic shift right
        } else if (tecla == 'D') {
            w = w / 2;  // Divide by 2
        } else if (tecla >= '0' && tecla <= '9') {
            int n = tecla - '0';
            w = w ^ ((1 << n) - 1);  // Toggle `n` least significant bits
        }
    }

    return 0;
}

