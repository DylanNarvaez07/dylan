#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    const char *filename = "archivo.txt";
    const char *additional_message = "Añadiendo más información al archivo.\n";
    char buffer[256];

    // Abrir el archivo para añadir información
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error al abrir el archivo para añadir información.\n");
        return 1;
    }

    // Añadir el mensaje al archivo
    fputs(additional_message, file);

    // Cerrar el archivo
    fclose(file);

    // Abrir el archivo para lectura
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    // Leer y mostrar el contenido del archivo
    printf("Contenido del archivo '%s':\n", filename);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Cerrar el archivo
    fclose(file);

    return 0;
}