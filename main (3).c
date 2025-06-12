/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *file;
	char *filename = "archivos.txt";
	char *message = "Este es un archivo de prueba";

	file = fopen(filename, "w");
	if (file == NULL) {
		printf("Error al crearnel archivo. \n");
		return 1;
	}

	fputs(message, file);

	fclose(file);
	return 0;


}