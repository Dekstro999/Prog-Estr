// Diego Alonso Ibarra Galindo
// Lea 3 números y desplegar los 3 números en orden ascendente
// Elaborado: 13/02/2024
// DAIG_ACT2_09.cpp

#include <stdio.h>

int main() {
    float num1, num2, num3, temp;

    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%f", &num3);
    if (num1 > num2) 
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3) 
    {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if (num1 > num2) 
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    printf("En orden ascendente son: %.2f, %.2f, %.2f\n", num1, num2, num3);
    return 0;
}
