#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile char final = 0;
volatile char key_pressed = 0;

// Interrupt Service Routine (ISR) for the keyboard
void keyboard_interrupt() {
    key_pressed = in(0);  // Simulating keyboard register (Rest_tec)
    final = 1;  // Signal that a key was pressed
}

int main() {
    final = 0;
    key_pressed = 0;

    // Assign keyboard ISR to interrupt vector
    signal(SIGUSR1, keyboard_interrupt); // Simulate keyboard interrupt

    // Enable keyboard interrupt
    do {
        final = 0;  // Reset flag

        while (!final) {}  // Wait for key press

        // Display pressed key at position [4,8] in inverse mode
        out(0, 4);           // Rfil_pant = row 4
        out(1, 8);           // Rcol_pant = column 8
        out(2, 0x100 + key_pressed);  // Rdat_pant = pressed key in inverse mode
        out(3, 0x8000);      // Rcon_pant = normal attributes

    } while (key_pressed != 'X');  // Stop only when 'X' is pressed

    return 0;
}

