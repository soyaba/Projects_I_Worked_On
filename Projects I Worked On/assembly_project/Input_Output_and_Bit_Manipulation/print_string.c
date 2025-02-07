#include <stdio.h>

// Mock functions to simulate SISA-F hardware behavior
int in(int register_name) {
    int value;
    printf("Checking register %d status: ", register_name);
    scanf("%d", &value);  // Simulating a hardware register read
    return value;
}

void out(int register_name, char value) {
    printf("Printing '%c' to register %d\n", value, register_name);
}

int main() {
    char frase[30] = "aquest programa funciona";  // String to print
    int i = 0;
    int invar;

    // Check if the printer is ready
    invar = in(0);  // Assuming Rest_imp = 0 (printer status register)
    
    // If ready, send each character of the string
    if (invar == 1) {
        while (frase[i] != '\0') {  // Loop until null terminator
            out(1, frase[i]);  // Assuming Rdat_imp = 1 (printer data register)
            i++;
        }
    }

    return 0;
}

