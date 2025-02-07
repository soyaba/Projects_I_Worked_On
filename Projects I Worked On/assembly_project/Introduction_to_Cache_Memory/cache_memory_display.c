#include <stdio.h>

// Function to display cache line information
void print_cache_info(int address, int col, int row) {
    int line = address >> 3;         // Compute memory block
    int line_cache = line & 0x01FF;  // Extract cache line index (512 lines)
    int tag = address >> 12;         // Extract tag bits
    char character;

    printf("Memory Address: 0x%X | Cache Line: %d | Tag: %d\n", address, line_cache, tag);

    // Display cache line in binary format
    printf("Row %d, Column %d: ", row, col);
    while (line_cache != 0) {
        character = (line_cache & 1) + '0';  // Convert to ASCII ('0' or '1')
        printf("%c", character);
        line_cache = line_cache >> 1;  // Shift right for next bit
        col--;
    }
    printf("\n");
}

int main() {
    int i, address, col, row = 4;
    int X[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int Y[] = {-2, 0, 3, 6, -2, 12, -3, 14, 5, 6};
    int Z[10];

    for (i = 0; i < 10; i++) {
        Z[i] = X[i] + Y[i];

        // Cache info for X[i]
        col = 15;
        address = (int)&X[i];
        print_cache_info(address, col, row);

        // Cache info for Y[i]
        col = 30;
        address = (int)&Y[i];
        print_cache_info(address, col, row);

        // Cache info for Z[i]
        col = 45;
        address = (int)&Z[i];
        print_cache_info(address, col, row);

        row++; // Move to the next row for the next iteration
    }

    return 0;
}

