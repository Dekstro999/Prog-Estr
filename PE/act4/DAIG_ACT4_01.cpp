// Diego Alonso Ibarra Galindo
// Menú para realizar las 4 operaciones básicas
// Elaborado: 24/02/2024 
// DAIG_ACT4_01.cpp

#include <stdio.h>

int main() {
    int num1, num2, opc;
    float tot;

    printf("Ingrese el 1er numero: ");
    scanf("%d", &num1);
    printf("Ingrese el 2do numero: ");
    scanf("%d", &num2);

    printf("\nMENU\n");
    printf("1.- Suma\n");
    printf("2.- Resta\n");
    printf("3.- Multiplicacion\n");
    printf("4.- Division\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opc);

    if (opc == 1) 
    {
        tot = num1 + num2;
        printf("La suma es: %.2f\n", tot);
    } 
    else 
    {
        if (opc == 2) 
        {
            tot = num1 - num2;
            printf("La resta es: %.2f\n", tot);
        } 
        else 
        {
            if (opc == 3) 
            {
                tot = num1 * num2;
                printf("La multiplicacion es: %.2f\n", tot);
            } 
            else 
            {
                if (opc == 4) 
                {
                    if (num2 != 0) 
                    {
                        tot = (float)num1 / num2;
                        printf("La division es: %.2f\n", tot);
                    } 
                    else 
                    {
                        printf("No se puede dividir por cero.\n");
                    }
                } 
                else 
                {
                    printf("Opcion no valida.\n");
                }
            }
        }
    }
    return 0;
}
