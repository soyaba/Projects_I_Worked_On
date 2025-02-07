#include <stdio.h>

int main(int argc, char *argv[]) {

	// Verifica que se proporcione exactamente un argumento (nombre del archivo)
	if (argc != 2) return 1;

	// Intenta abrir el archivo en modo lectura
	FILE *fitxer = fopen(argv[1], "r");

	// Si no se puede abrir el archivo, retorna un error
	if (!fitxer) return 1;

	// Buffer para leer cada línea
	char linia[256];

	// Recorre el archivo línea por línea con un contador de líneas
	for (int numero_linia = 1; fgets(linia, sizeof(linia), fitxer); numero_linia++)

    	// Si el número de la línea es par, se imprime
    	if (numero_linia % 2 == 0) printf("%s", linia);

	// Cierra el archivo después de leer
	fclose(fitxer);
	return 0;
}

