#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUF_SIZE 1024 // Tamaño del buffer para leer datos

// Función para modificar el texto según el id del proceso hijo
void modifica_text(int id, char *buffer) {
	// Recorre el buffer carácter por carácter
	for (int i = 0; buffer[i] != '\0'; i++) {
    
    	// Modificaciones según el identificador del proceso (cíclico cada 4 procesos)
    	if (id % 4 == 1 && buffer[i] == 'a') {
        	buffer[i] = 'e'; // Cambia 'a' por 'e'
       	 
    	} else if (id % 4 == 2 && buffer[i] == 'c') {
        	buffer[i] = 'k'; // Cambia 'c' por 'k'
       	 
    	} else if (id % 4 == 3 && (i + 1) % 7 == 0) {
        	// Duplica cada séptimo carácter
        	memmove(&buffer[i + 1], &buffer[i], strlen(&buffer[i]) + 1);
        	i++;
    	} else if (id % 4 == 0 && buffer[i] == 'm') {
        	buffer[i] = 'n'; // Cambia 'm' por 'n'
    	}
	}
}

int main(int argc, char *argv[]) {
	// Verificar que se pasa un argumento (número de procesos)
	if (argc != 2) {
    	fprintf(stderr, "Uso: %s <número de procesos>\n", argv[0]);
    	exit(EXIT_FAILURE);
	}

	// Convertir el argumento a entero
	int N = atoi(argv[1]);
	if (N <= 0) {
    	fprintf(stderr, "El número de procesos debe ser mayor que cero.\n");
    	exit(EXIT_FAILURE);
	}

	int pipes[N][2]; // Array de pipes para comunicación entre procesos
	pid_t pid; // Id del proceso

	// Crear las pipes para cada proceso
	for (int i = 0; i < N; i++) {
    	if (pipe(pipes[i]) == -1) {
        	perror("pipe");
        	exit(EXIT_FAILURE);
    	}
	}

	// Crear procesos hijos
	for (int i = 0; i < N; i++) {
    	pid = fork();
    	if (pid == -1) {
        	perror("fork");
        	exit(EXIT_FAILURE);
    	} else if (pid == 0) {
        	// Código del proceso hijo
        	// Redirigir la entrada estándar (stdin) si no es el primer hijo
        	if (i != 0) {
            	dup2(pipes[i - 1][0], STDIN_FILENO);
        	}
        	// Redirigir la salida estándar (stdout) si no es el último hijo
        	if (i != N - 1) {
            	dup2(pipes[i][1], STDOUT_FILENO);
        	}

        	// Cerrar todas las pipes para evitar fugas de descriptores
        	for (int j = 0; j < N; j++) {
            	close(pipes[j][0]);
            	close(pipes[j][1]);
        	}

        	// Leer datos del stdin y aplicar modificaciones
        	char buffer[BUF_SIZE];
        	ssize_t nbytes;
        	while ((nbytes = read(STDIN_FILENO, buffer, BUF_SIZE)) > 0) {
            	buffer[nbytes] = '\0'; // Añadir carácter nulo al final de la cadena
            	modifica_text(i + 1, buffer); // Aplicar modificaciones al texto
            	write(STDOUT_FILENO, buffer, strlen(buffer)); // Escribir el texto modificado al stdout
        	}

        	exit(EXIT_SUCCESS); // Finalizar el proceso hijo
    	}
	}

	// Código del proceso padre
	// Cerrar descriptores de pipes que no se usan en el padre
	for (int i = 0; i < N; i++) {
    	close(pipes[i][0]); // Cerrar el extremo de lectura
    	if (i != N - 1) {
        	close(pipes[i][1]); // Cerrar el extremo de escritura (excepto el último)
    	}
	}

	// Leer de la entrada estándar y escribir a la primera pipe
	char buffer[BUF_SIZE];
	ssize_t nbytes;
	while ((nbytes = read(STDIN_FILENO, buffer, BUF_SIZE)) > 0) {
    	buffer[nbytes] = '\0'; // Añadir carácter nulo al final de la cadena
    	write(pipes[0][1], buffer, strlen(buffer)); // Escribir a la primera pipe
	}

	// Cerrar el extremo de escritura de la primera pipe
	close(pipes[0][1]);

	// Esperar a que todos los procesos hijos terminen
	for (int i = 0; i < N; i++) {
    	wait(NULL); // Esperar a cada proceso hijo
	}

	return 0; // Finalizar el proceso padre
}

