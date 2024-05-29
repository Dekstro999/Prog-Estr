// Diego Alonso Ibarra Galindo
// lea 3 números y desplegar cuál número es del medio y su valor
// Elaborado: 06/02/2024
// DAIG_ACT1_05.cpp

#include <stdio.h>
#include <conio.h>
#include <time.h>

int main(){

    clock_t inicio, fin;
    double time;

    int num1, num2, num3; 
    printf("ingresa los numeros:\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    inicio = clock(); /////

if ((num1 >= num2 && num1 <= num3) || (num1 <= num2 && num1 >= num3))
        printf("El valor del medio es: %d\n", num1);
    else if ((num2 >= num1 && num2 <= num3) || (num2 <= num1 && num2 >= num3))
        printf("El valor del medio es: %d\n", num2);
    else
        printf("El valor del medio es: %d\n", num3);

    fin = clock();  /////
    time = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    printf("%.10f", time);

    return 0;
}