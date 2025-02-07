#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile int ticks = 0;
volatile char final = 0;

// Interrupt Service Routine (ISR) for the clock
void clock() {
    ticks++;  
    if (ticks >= 5 * 10) {  // Assuming each tick is 100ms (10 per second)
        final = 1;
    }
}

int main() {
    ticks = 0;
    final = 0;

    // Assign clock ISR to the interrupt vector
    signal(SIGALRM, clock);

    // Start the clock (assuming 100ms per tick)
    ualarm(100000, 100000); // Microseconds: 100000 = 100ms

    // Enable interrupts
    while (!final) {}  // Wait for 5 seconds

    // Display 'A' on screen at position [4,8]
    out(0, 4);       // Rfil_pant = row 4
    out(1, 8);       // Rcol_pant = column 8
    out(2, 'A');     // Rdat_pant = character 'A'
    out(3, 0x8000);  // Rcon_pant = normal attributes

    return 0;
}

