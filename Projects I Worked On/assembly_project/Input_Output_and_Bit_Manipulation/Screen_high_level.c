#include <stdio.h>

// Define mock functions to simulate output in the SISA-F system.
void out(int register_name, int value) {
    printf("Writing value 0x%X to register %d\n", value, register_name);
}

int main() {
    int control = 0x8000;  // Control register for the screen
    int row = 4;           // Row position
    int column = 8;        // Column position
    
    // Set the row once
    out(0, row);  // Assuming Rfil_pant = 0 (register for row)

    // Print 'A' at position [4,8] with inverted attribute
    out(1, column);          // Assuming Rcol_pant = 1 (register for column)
    out(2, 0x100 + 'A');     // Assuming Rdat_pant = 2 (register for data)
    out(3, control);         // Assuming Rcon_pant = 3 (control register)

    // Move to the next column and print 'B' with normal attribute
    column = column + 1; 
    out(1, column);
    out(2, 'B');
    out(3, control);

    return 0;
}

