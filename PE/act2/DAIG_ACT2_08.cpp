// Diego Alonso Ibarra Galindo
// Lea 3 números y desplegar cuál número es del medio y su valor
// Elaborado: 13/02/2024
// DAIG_ACT2_08.cpp


#include <stdio.h>

int main() {
    float num1, num2, num3, medio;

    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%f", &num3);

    if ((num1 <= num2 && num1 >= num3) || (num1 >= num2 && num1 <= num3)) 
    {
        medio = num1;
    } 
    else if ((num2 <= num1 && num2 >= num3) || (num2 >= num1 && num2 <= num3)) 
    {
        medio = num2;
    } 
    else 
    {
        medio = num3;
    }
    printf("El numero del medio es %.2f\n", medio);

    return 0;
}

