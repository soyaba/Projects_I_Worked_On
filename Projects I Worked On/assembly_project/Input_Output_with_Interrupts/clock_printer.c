#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile int ticks = 0;
volatile char ready = 0;
char frase[] = "aquest programa funciona";

// Interrupt Service Routine (ISR) for the clock
void clock_interrupt() {
    ticks++;  
    if (ticks >= 10) {  // Assuming each tick is 100ms, 10 ticks = 1 second
        ready = 1;  // Signal to print the next character
        ticks = 0;  // Reset the timer
    }
}

// Function to print the string character by character
void print_string(const char *str) {
    int i = 0;
    while (str[i] != '\0') {  // Loop until end of string
        ready = 0;  // Reset flag

        while (!ready) {}  // Wait for the timer interrupt

        out(1, str[i]);  // Send character to printer (Rdat_imp)
        out(2, 0x8001);  // Printer control register (Rcon_imp)
        i++;  // Move to the next character
    }
}

int main() {
    // Assign clock ISR to interrupt vector
    signal(SIGALRM, clock_interrupt);

    // Start the timer (assuming 100ms per tick)
    ualarm(100000, 100000); // Microseconds: 100000 = 100ms

    // Enable interrupts and start printing
    print_string(frase);

    return 0;
}

