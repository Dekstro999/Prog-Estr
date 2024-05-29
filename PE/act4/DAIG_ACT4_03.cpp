// Diego Alonso Ibarra Galindo
// Lea 6 números, desplegar el valor del número mayor.
// Elaborado: 24/02/2024
// DAIG_ACT4_03.cpp

#include <stdio.h>

int main()
{
    int num1, num2, num3, num4, num5, num6, mayor;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);
    printf("Ingrese el cuarto numero: ");
    scanf("%d", &num4);
    printf("Ingrese el quinto numero: ");
    scanf("%d", &num5);
    printf("Ingrese el sexto numero: ");
    scanf("%d", &num6);

    mayor = num1;

    if (num2 > mayor)
    {
        mayor = num2;
    }
    if (num3 > mayor)
    {
        mayor = num3;
    }
    if (num4 > mayor)
    {
        mayor = num4;
    }
    if (num5 > mayor)
    {
        mayor = num5;
    }
    if (num6 > mayor)
    {
        mayor = num6;
    }

    printf("El numero mayor es: %d\n", mayor);

    return 0;
}
