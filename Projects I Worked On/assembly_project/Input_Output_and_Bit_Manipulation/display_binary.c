#include <stdio.h>

// Mock function to simulate hardware interactions in SISA-F
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

// Main function to initialize the process
int main() {
    int w = 0x8888;  // Word-sized variable
    mostra(w);       // Call function to display its binary representation
    return 0;
}

