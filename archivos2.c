/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


int main()
{
    FILE *archivo;
    
    archivo = fopen("numero.txt", "w");
    fprintf(archivo, "100");
    fclose(archivo);
    
    archivo = fopen("numero.txt", "r");
    int numero;
    fscanf(archivo, "%d", &numero);
    fclose(archivo);
    
    printf("Numero leido: %d\n", numero);
    

    return 0;
}
