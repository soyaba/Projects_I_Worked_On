#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include "dummy2.h"

int main(int argc, char *argv[]) {
    int bytesLlegits;
    char buffer[2000];

    if (argc != 2) exit(-1);

    int N = atoi(argv[1]);

    if (N < 0 || N > 2000) {
        printf("El numero no puede ser menor que cero, mayor que 2000\n");
        exit(-1);
    }

    dummy_init(buffer, N);

    while ((bytesLlegits = read(0, buffer, N)) > 0) {
        dummy_comp(buffer, bytesLlegits);
    }

    dummy_exit();
}

