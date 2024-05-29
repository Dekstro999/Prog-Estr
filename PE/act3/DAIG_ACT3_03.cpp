// Diego Alonso Ibarra Galindo
//  Algoritmo que lea 3 números y desplegar los 3 números en orden ascendente... (OPTIMIZADO FORMA DE ARBOL)
// Elaborado: 21/02/2024
// DAIG_ACT3_03.cpp

#include <stdio.h>

int main()
{
    float num1, num2, num3;

    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%f", &num3);

    if (num1 <= num2 && num1 <= num3)
    {
        if (num2 <= num3)
        {
            printf("\n%.2f\n %.2f\n %.2f\n", num1, num2, num3);
        }
        else
        {
            printf("\n%.2f\n %.2f\n %.2f\n", num1, num3, num2);
        }
    }
    else
    {
        if (num2 <= num1 && num2 <= num3)
        {
            if (num1 <= num3)
            {
                printf("\n%.2f\n %.2f\n %.2f\n", num2, num1, num3);
            }
            else
            {
                printf("\n%.2f\n %.2f\n %.2f\n", num2, num3, num1);
            }
        }
        else
        {
            if (num1 <= num2)
            {
                printf("\n%.2f\n %.2f\n %.2f\n", num3, num1, num2);
            }
            else
            {
                printf("\n%.2f\n %.2f\n %.2f\n", num3, num2, num1);
            }
        }
    }
    return 0;
}
