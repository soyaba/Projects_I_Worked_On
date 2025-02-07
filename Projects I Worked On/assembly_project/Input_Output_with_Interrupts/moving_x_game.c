#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile int ticks = 0;
volatile int position = 8;
volatile char final = 0;

// Interrupt Service Routine (ISR) for the clock
void clock_interrupt() {
    ticks++;

    if (ticks >= 4) {  // 0.4 seconds assuming 100ms per tick
        ticks = 0;

        // Erase 'X' at the current position
        out(1, position);  // Set column
        out(2, ' ');       // Write space (erase)
        out(3, 0x8000);    // Apply screen attributes

        // Move to the next position
        position++;

        // Stop when 'X' moves off the screen
        if (position >= 16) {
            final = 1;
            return;
        }

        // Draw 'X' at the new position
        out(1, position);
        out(2, 'X');
        out(3, 0x8000);
    }
}

int main() {
    // Assign clock ISR to interrupt vector
    signal(SIGALRM, clock_interrupt);

    // Start the timer (assuming 100ms per tick)
    ualarm(100000, 100000); // Microseconds: 100000 = 100ms

    // Initial position of 'X'
    out(0, 4);     // Row = 4
    out(1, position);
    out(2, 'X');
    out(3, 0x8000);

    // Enable interrupts and run until 'X' moves off the screen
    while (!final) {}

    return 0;
}

