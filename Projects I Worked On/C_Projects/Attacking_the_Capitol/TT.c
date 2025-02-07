
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include "dummy4.h"

#define TEAMNAME "soyaba"
#define ENIGMA3 "belters" 
#define SILVERKEY "ab0df"
#define BRONCEKEY "7a39f"
#define GOLDKEY "0xdbe1f" //para el SIOP Challenge
#define SERVNAME "SIOP-server"
#define SERVADDR "147.83.159.200"
#define SERVPORT 61219
#define CRTLPORT 11219

// Función de manejo de señal
void ready(int signum) {}

void main(int argc, char *argv[]) {
    if (argc == 3) {
        // Validación de argumentos
        float n;
        int e;
        bool error = false;
        int i = 1;

        while ((i < argc) && (error == false)) {
            n = atof(argv[i]);
            e = atoi(argv[i]);
            if (n != e || n <= 0) error = true;
            i++;
        }

        if (error == true) {
            printf("Error of usage: %s M, N, on M i N son enters.\n", argv[0]);
            return;
        }

        printf("Els numeros son enters.\n");

        // Inicialización
        int acum = 0;
        int m = atoi(argv[1]); // Número de replicantes
        int canalpipe[2];
        pipe(canalpipe);
        signal(SIGUSR1, ready);

        // Conexión remota
        int ctrlfd = ctrlconnect(SERVADDR, CRTLPORT, ENIGMA3, TEAMNAME, SILVERKEY, GOLDKEY);
        if (ctrlfd < 0) {
            perror("Error al conectar al canal de control");
            exit(EXIT_FAILURE);
        }

        int fd = connecta(SERVADDR, SERVPORT);
        if (fd < 0) {
            perror("Error al conectar al canal de datos");
            exit(EXIT_FAILURE);
        }

        // Replicants
        for (int j = 0; j < m; j++) {
            int pid = fork();
            if (pid == 0) { // Proceso hijo
                close(0);
                dup(fd);
                close(fd);
                close(canalpipe[1]);
                execl("./replicant", "replicant", argv[2], (char *)0);
                perror("Error al ejecutar replicant");
                exit(EXIT_FAILURE);
            }
        }

        // Cerrar conexiones no necesarias en el padre
        close(fd);
        close(canalpipe[1]);

        // Recoger resultados de replicantes
        for (i = 0; i < m; ++i) {
            int stat;
            wait(&stat);

            if (WIFEXITED(stat)) {
                int exitcode = WEXITSTATUS(stat);
                printf("Exit code [%d]\n", exitcode);
                acum += exitcode;
            } else {
                printf("Error en el estat de sortida del fill\n");
            }
        }

        // Envío del acumulado al Capitol
        char buf[128];
        int nbytes = sprintf(buf, "%d", acum);
        write(ctrlfd, buf, nbytes);

        // Leer respuesta del Capitol
        char buffy[128];
        int len = read(ctrlfd, buffy, sizeof(buffy) - 1);
        if (len > 0) {
            buffy[len] = '\0'; // Terminar cadena
            printf("MISSION: %s\n", buffy);
        } else {
            perror("Error al leer la respuesta del Capitol");
        }

        // Cerrar canal de control
        close(ctrlfd);
    } else {
        printf("Error of usage: %s M, N, on M i N son enters.\n", argv[0]);
    }
}

