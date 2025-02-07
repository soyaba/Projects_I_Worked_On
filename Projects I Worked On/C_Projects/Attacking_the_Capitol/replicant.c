#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "dummy4.h"

void main(int argc, char *argv[]) {
    int i, n, final;
    int bites_llegits;
    char buff[3000];
    if (argc != 2) {
        printf("Error of usage: %s N, on 3000 > N > 0s \n", argv[0]);
    }
    n = atoi(argv[1]);
    if ((n <= 0) || (n > 3000)) {
        printf("Error of usage: %s N, on 3000 > N > 0s \n", argv[0]);
    }

    dummy_init(buff, n);
    final = 0;
    while (!final) {
        bites_llegits = 0;
        bites_llegits = read(0, buff, n);
        if (bites_llegits != 0)
            dummy_calc(buff, bites_llegits);
        else
            final = 1;
    }
    dummy_end();
}

