#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "dummy3.h"

#define TEAMNAME "soyaba"

#define ENIGMA2 "2.77UA0.08e10.59g"

#define BRONCEKEY "7a39f"

void main(int argc, char *argv[]) {
    if (argc == 3) {
        float n;
        int e;
        bool error = false;
        int i = 1;
        int pid, exitcode, stat;

        while ((i < argc) && (error == false)) {
            n = atof(argv[i]);
            e = atoi(argv[i]);
            if (n != e) error = true;
            if (n <= 0) error = true;
            i++;
        }

        if (error == false)
            printf("Els numeros son enters.\n");
        else
            printf("Error of usage: %s M, N, on M i N son enters. \n", argv[0]);

        // Capitol
        int acum = 0;
        int m = atoi(argv[1]);
        int fd;
        fd = open("dummy.dat", O_RDONLY);
        int canalpipe[2];
        dummy_checkfile(fd);
        pipe(canalpipe);
        signal(SIGUSR1, ready);
        pid = fork();
        if (pid == 0) {
            close(0);
            dup(fd);
            close(fd);
            close(1);
            dup(canalpipe[1]);
            close(canalpipe[1]);
            close(canalpipe[0]);
            execl("./capitol", "capitol", (char *)0);
        }
        pause();


        // Replicants
        for (int j = 0; j < m; j++) {
            pid = fork();
            if (pid == 0) {
                close(0);
                dup(canalpipe[0]);
                close(canalpipe[0]);
                close(canalpipe[1]);
                close(fd);
                execl("./replicant", "replicant", argv[2], (char *)0);
            }
        }

        // Close extras
        close(fd);
        close(canalpipe[0]);
        close(canalpipe[1]);
        for (i = 0, exitcode = 0; i < m + 1; ++i) {
            wait(&stat);

            if (WIFEXITED(stat)) {
                int8_t code;
                code = WEXITSTATUS(stat);
                exitcode = code;
                printf("Exit code [%d] \n", exitcode);
                acum = acum + exitcode;
            } else
                printf("Error en el estat de sortida del fill\n");
        }
        dummy_testing(acum, ENIGMA2, TEAMNAME, BRONCEKEY);
    } else
        printf("Error of usage: %s M, N, on M i N son enters. \n", argv[0]);
}

