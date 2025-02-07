#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile int ticks = 0;
volatile char final = 0;
volatile char direction = 'S';  // Default movement direction (right)
volatile int col = 8;  // Initial X position
volatile int row = 4;  // Initial Y position

// Interrupt Service Routine (ISR) for the clock
void clock_interrupt() {
    ticks++;

    if (ticks >= 4) {  // Move every 0.4 seconds (assuming 100ms per tick)
        ticks = 0;

        // Erase 'X' at current position
        out(1, col);
        out(2, ' ');
        out(3, 0x8000);

        // Update position based on direction
        if (direction == 'A') {  // Move left
            col--;
        } else if (direction == 'S') {  // Move right
            col++;
        } else if (direction == 'L') {  // Move down
            row++;
        } else if (direction == 'P') {  // Move up
            row--;
        }

        // Stop if 'X' moves out of bounds
        if (col < 0 || col >= 16 || row < 0 || row >= 16) {
            final = 1;
            return;
        }

        // Draw 'X' at new position
        out(0, row);
        out(1, col);
        out(2, 'X');
        out(3, 0x8000);
    }
}

// Interrupt Service Routine (ISR) for the keyboard
void keyboard_interrupt() {
    char key = in(0);  // Read key input

    // Update direction based on key press
    if (key == 'A') {
        direction = 'A';  // Move left
    } else if (key == 'S') {
        direction = 'S';  // Move right
    } else if (key == 'L') {
        direction = 'L';  // Move down
    } else if (key == 'P') {
        direction = 'P';  // Move up
    }
}

int main() {
    // Assign ISR functions to interrupt vectors
    signal(SIGALRM, clock_interrupt);
    signal(SIGUSR1, keyboard_interrupt);

    // Start the clock (assuming 100ms per tick)
    ualarm(100000, 100000);  // Microseconds: 100000 = 100ms

    // Initial position of 'X'
    out(0, row);
    out(1, col);
    out(2, 'X');
    out(3, 0x8000);

    // Enable interrupts and run until 'X' moves off the screen
    while (!final) {}

    return 0;
}

