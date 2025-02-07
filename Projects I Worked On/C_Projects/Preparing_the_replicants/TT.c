#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include "dummy2.h"

#define TEAMNAME "soyaba"
#define ENIGMA1 "protomolecule"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Número de parámetros incorrecto, por favor introdúzcalos nuevamente\n");
        exit(-1);
    }

    int M = atoi(argv[1]);
    float M1 = atof(argv[1]);
    int N = atoi(argv[2]);
    float N1 = atof(argv[2]);

    if (M != M1) {
        printf("El primer parámetro no es entero\n");
        exit(-1);
    }

    if (M <= 0) {
        printf("El primer parámetro debe ser mayor que 0\n");
        exit(-1);
    }

    if (N != N1) {
        printf("El segundo parámetro no es entero\n");
        exit(-1);
    }

    if (N <= 0) {
        printf("El segundo parámetro debe ser mayor que 0\n");
        exit(-1);
    }

    int fd = dummy_open();
    if (fd < 0) {
        printf("Error al abrir el banco de tiempo\n");
        exit(-1);
    }

    int stat, exitcode;
    int acum = 0;
    pid_t pid;

    for (int i = 0; i < M; i++) {
        pid = fork();

        if (pid < 0) {
            printf("Error al crear el proceso replicante\n");
            exit(-1);
        }

        if (pid == 0) { // Código del replicante
            close(0);
            dup(fd);
            close(fd);
            execlp("./replicant", "./replicant", argv[2], (char *)0);
            perror("Error al ejecutar replicant");
            exit(-1);
        }
    }

    if (pid > 0) {
        close(fd);
        for (int i = 0; i < M; i++) {
            wait(&stat);
            if (WIFEXITED(stat)) {
                exitcode = WEXITSTATUS(stat);
                acum += exitcode;
                printf("Código de salida del replicante %d: %d\n", i + 1, exitcode);
            } else {
                printf("El replicante %d no terminó correctamente\n", i + 1);
            }
        }
    }

    if (dummy_test(acum, ENIGMA1, TEAMNAME) != 0) {
        printf("Error en el procesamiento del tiempo\n");
        exit(-1);
    }

    printf("Procesamiento completado exitosamente\n");
    return 0;
}

