// Diego Alonso Ibarra Galindo
// (1.- HOMBRE 2.- MUJER ) SEXO y desplegar la leyenda “HOLA, ERES HOMBRE ”, “ HOLA, ERES MUJER”
// Elaborado: 13/02/2024
// DAIG_ACT2_04.cpp

#include <stdio.h>

int main()
{
    int opcion;
    printf("\nElija su sexo:\n");
    printf("1. HOMBRE\n");
    printf("2. MUJER\n");
    scanf("%d", &opcion);

    if (opcion == 1) 
    {
        printf("HOLA, ERES HOMBRE\n");
    } 
    else if (opcion == 2) 
    {
        printf("HOLA, ERES MUJER\n");
    } 
    else 
    { 
        printf("Opción inválida\n");
    }
    return 0;
}
