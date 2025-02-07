#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "dummy3.h"

void main() {
    char c;
    kill(getppid(), SIGUSR1);
    while (read(0, &c, 1) > 0) {
        write(1, &c, 1);
    }
    exit(0);
}

