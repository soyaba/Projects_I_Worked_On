#include <stdio.h>

// Mock functions to simulate SISA-F hardware behavior
int in(int register_name) {
    int value;
    printf("Checking register %d status: ", register_name);
    scanf("%d", &value);  // Simulating a hardware register read
    return value;
}

void out(int register_name, char *value) {
    printf("Printing '%s' to register %d\n", value, register_name);
}

int main() {
    int invar;

    // Check if the printer is ready
    invar = in(0);  // Assuming Rest_imp = 0 (printer status register)
    
    // If ready, send "Fi" to be printed
    if (invar == 1) {
        out(1, "Fi");  // Assuming Rdat_imp = 1 (printer data register)
    }

    return 0;
}

