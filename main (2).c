#include <stdio.h>   
#include <string.h>  

#define MAX_LIBROS 10  

struct Libro {
    int id;            
    char titulo[100];   
    char autor[50];    
    int anio;          
    char estado[20];   
};

struct Libro biblioteca[MAX_LIBROS];  
int totalLibros = 0;                  // Contador de libros registrados

// Función para registrar un nuevo libro
void registrarLibro() {
    if (totalLibros >= MAX_LIBROS) {
        printf("No caben más libros.\n");
        return;
    }

    // Pedir datos del libro al usuario
    printf("\nID del libro: ");
    scanf("%d", &biblioteca[totalLibros].id);  // Leer ID

    printf("Título: ");
    scanf(" %[^\n]s", biblioteca[totalLibros].titulo);  // Leer título (incluye espacios)

    printf("Autor: ");
    scanf(" %[^\n]s", biblioteca[totalLibros].autor);   // Leer autor (incluye espacios)

    printf("Año: ");
    scanf("%d", &biblioteca[totalLibros].anio);         // Leer año

    strcpy(biblioteca[totalLibros].estado, "Disponible");  //strcpy es una funcion de la libreria string.h y se usa para una cadena de caracteres 

    totalLibros++;  // Incrementar el contador de libros
    printf("Libro agregado.\n");
}

void mostrarLibros() {
    // Verificar si hay libros para mostrar
    if (totalLibros == 0) {
        printf("No hay libros.\n");
        return;
    }

    printf("\nLibros registrados:\n");
    for (int i = 0; i < totalLibros; i++) {
        printf("ID: %d | Título: %s | Autor: %s | Año: %d | Estado: %s\n",
               biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor,
               biblioteca[i].anio, biblioteca[i].estado);
    }
}

void buscarPorID() {
    // Verificar si hay libros registrados
    if (totalLibros == 0) {
        printf("No hay libros.\n");
        return;
    }

    int id;
    printf("\nID del libro a buscar: ");
    scanf("%d", &id);  

   
    for (int i = 0; i < totalLibros; i++) {
        if (biblioteca[i].id == id) {
           
            printf("Libro encontrado:\n");
            printf("Título: %s | Autor: %s | Año: %d | Estado: %s\n",
                   biblioteca[i].titulo, biblioteca[i].autor,
                   biblioteca[i].anio, biblioteca[i].estado);
            return;
        }
    }
    // Si no se encuentra, mostrar mensaje
    printf("Libro no encontrado.\n");
}

// Función principal (menú interactivo)
int main() {
    int opcion;  

    do {
        // Mostrar menú
        printf("\n--- Menú ---\n");
        printf("1. Agregar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar por ID\n");
        printf("0. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);  

        
        switch (opcion) {
            case 1: registrarLibro(); break;  
            case 2: mostrarLibros(); break;   
            case 3: buscarPorID(); break;     
            case 0: printf("Adiós.\n"); break; 
            default: printf("Opción inválida.\n");  
        }
    } while (opcion != 0);  // Repetir hasta que el usuario elija salir (0)

    return 0;  // Fin del programa
}
