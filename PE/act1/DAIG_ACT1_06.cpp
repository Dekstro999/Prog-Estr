// Diego Alonso Ibarra Galindo
// lea 3 números y desplegar en orden ascendente 
// Elaborado: 09/02/2024
// DAIG_ACT1_06.cpp

#include <stdio.h>

int main() {
    int num1, num2, num3;
    printf("Ingrese el 1er numero: ");
    scanf("%d", &num1);
    printf("Ingrese el 2do numero: ");
    scanf("%d", &num2);
    printf("Ingrese el 3ro numero: ");
    scanf("%d", &num3);

    //ordenamiento de burbuja
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3) {
        int temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    printf("\nLos numeros en orden son: %d, %d, %d\n", num1, num2, num3);

    return 0;
}
