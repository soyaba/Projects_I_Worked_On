#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void f_alarma(int signum) {
	// Función para manejar la señal de alarma
	printf("Alarma exhaurida\n");
	exit(0);
}

void error(char *m) {
	// Función para manejar errores
	// Muestra el mensaje de error usando perror y finaliza el programa
	perror(m);
	exit(0);
}

int main(int argc, char *argv[]) {
	// Verificación de parámetros de entrada
	if (argc != 3) {
    	printf("Paràmetres incorrectes\n"); // Mensaje de error si no hay 3 parámetros
    	exit(-1);
	} else {
    	char car;        	 
    	char tmp[180], frase[20] = "";
    	int fd, n, cont = 0;  // fd: descriptor del archivo, n: bytes leídos, cont: contador de caracteres
    	bool trobat = false, acaba = false; // Variables booleanas: si se ha encontrado 'z' y si se debe acabar

    	// Intento de abrir el archivo en modo solo lectura
    	if ((fd = open(argv[1], O_RDONLY)) < 0) {
        	// Si falla, se muestra un mensaje de error y se sale del programa
        	sprintf(tmp, "No se puede abrir el fichero %s\n", argv[1]);
        	error(tmp);
    	}

    	// Configuración de la alarma usando signal y alarm
    	signal(SIGALRM, f_alarma);     	// Asociamos la señal SIGALRM a la función f_alarma
    	alarm(atoi(argv[2]));          	// Configuramos la alarma con el número de segundos pasado como parámetro

    	// Bucle para leer el archivo carácter a carácter hasta que se encuentre 'z' o se acabe el archivo
    	while (((n = read(fd, &car, 1)) > 0) && !acaba) {
        	cont++;                   	 
        	strncat(frase, &car, 1);  	 
        	if (car == 'z') trobat = true;
        	if (cont == 20) {         	 
            	if (trobat)           	 
                	acaba = true;     	 
            	else {
                	cont = 0;         	 
                	frase[0] = '\0';  	 
                	sleep(1);         	 
            	}
        	}
    	}

    	// Salida de resultado según si se encontró 'z' o no
    	if (trobat)
        	printf("He trobat una ’z’ aquí: %s\n", frase); // Muestra la frase en la que se encontró 'z'
    	else
        	printf("He llegit tot el fitxer i No hi ha ’z’\n"); // Mensaje si no se encuentra 'z' en todo el archivo
   	 
    	exit(0); // Termina el programa
	}
}

