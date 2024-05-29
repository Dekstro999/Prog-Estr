// Diego Alonso Ibarra Galindo
// lea 3 números y desplegar cuál número es del mayor 
// Elaborado: 09/02/2024
// DAIG_ACT1_04.cpp

#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Ingrese el 1er numero: ");
    scanf("%d", &num1);
    printf("Ingrese el 2do numero: ");
    scanf("%d", &num2);
    printf("Ingrese el 3er numero: ");
    scanf("%d", &num3);

    if (num1 >= num2 && num1 >= num3) {
        printf("El primer numero (%d) es el mayor.\n", num1); 
    } else if (num2 >= num1 && num2 >= num3) {
        printf("El segundo numero (%d) es el mayor.\n", num2);
    } else {
        printf("El tercer numero (%d) es el mayor.\n", num3);
    }

    return 0;
}
