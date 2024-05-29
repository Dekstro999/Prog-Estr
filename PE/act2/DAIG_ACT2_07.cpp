// Diego Alonso Ibarra Galindo
// Lea 3 números y desplegar cuál número es el menor y su valor
// Elaborado: 13/02/2024
// DAIG_ACT2_07.cpp


#include <stdio.h>

int main() {
    float num1, num2, num3, menor;

    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%f", &num3);

    if (num1 <= num2 && num1 <= num3) 
    {
        menor = num1;
    } 
    else if (num2 <= num1 && num2 <= num3) 
    {
        menor = num2;
    } 
    else 
    {
        menor = num3;
    }

    printf("El nimero menor es %.2f\n", menor);

    return 0;
}

