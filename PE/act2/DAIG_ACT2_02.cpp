// Diego Alonso Ibarra Galindo
// Lea un número entero, y desplegar si el número es “PAR” o “IMPAR”
// Elaborado: 13/02/2024
// DAIG_ACT2_02.cpp


#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int num;
    printf("Ingrese un numero entero: ");
    scanf("%d", &num);

    if (num % 2 == 0) 
    {
        printf("El numero %d es PAR.\n", num);
    } 
    if (num % 2 != 0) 
    {
    printf("El numero %d es IMPAR.\n", num);
    } 
    return 0;
}
