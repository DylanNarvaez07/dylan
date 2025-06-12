#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[50];
    int edad;
    float altura;
} Persona;

void escribirPersona(FILE *file, Persona p) {
    fwrite(&p, sizeof(Persona), 1, file);
}

void leerPersonas(FILE *file) {
    Persona p;
    while (fread(&p, sizeof(Persona), 1, file)) {
        printf("Nombre: %s\n", p.nombre);
        printf("Edad: %d\n", p.edad);
        printf("Altura: %.2f\n\n", p.altura);
    }
}

int main() {
    FILE *file;
    const char *filename = "personas.dat";

    // Crear y abrir el archivo para escritura
    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    // Crear algunas personas y escribirlas en el archivo
    Persona personas[] = {
        {"Juan Perez", 30, 1.75},
        {"Ana Anita", 25, 1.65},
        {"Luis Martinez", 40, 1.80}
    };

    for (int i = 0; i < 3; i++) {
        escribirPersona(file, personas[i]);
    }

    // Cerrar el archivo
    fclose(file);

    // Abrir el archivo para lectura
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    // Leer y mostrar el contenido del archivo
    printf("Contenido del archivo '%s':\n\n", filename);
    leerPersonas(file);

    // Cerrar el archivo
    fclose(file);

    return 0;
}
