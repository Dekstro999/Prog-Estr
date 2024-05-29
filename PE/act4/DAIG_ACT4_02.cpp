// Diego Alonso Ibarra Galindo
//menú para realizar conversiones de unidades de medida,
// Elaborado: 24/02/2024 
// DAIG_ACT4_02.cpp

#include <stdio.h>

int main()
{
    int opcion;
    float valor, resultado;

    printf("\n    MENU\n");
    printf("1.- cm a pulgadas\n");
    printf("2.- cm a pies\n");
    printf("3.- Km a millas\n");
    printf("4.- Pulgadas a cm\n");
    printf("5.- pies a cm\n");
    printf("6.- millas a Km\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);

    printf("Ingrese el valor a convertir: ");
    scanf("%f", &valor);

    if (opcion == 1)
    {
        resultado = valor / 2.54;
        printf("%.2f cm equivale a %.2f pulgadas\n", valor, resultado);
    }
    else
    {
        if (opcion == 2)
        {
            resultado = valor / 30.48;
            printf("%.2f cm equivale a %.2f pies\n", valor, resultado);
        }
        else
        {
            if (opcion == 3)
            {
                resultado = valor / 1.60934;
                printf("%.2f Km equivale a %.2f millas\n", valor, resultado);
            }
            else
            {
                if (opcion == 4)
                {
                    resultado = valor * 2.54;
                    printf("%.2f pulgadas equivale a %.2f cm\n", valor, resultado);
                }
                else
                {
                    if (opcion == 5)
                    {
                        resultado = valor * 30.48;
                        printf("%.2f pies equivale a %.2f cm\n", valor, resultado);
                    }
                    else
                    {
                        if (opcion == 6)
                        {
                            resultado = valor * 1.60934;
                            printf("%.2f millas equivale a %.2f Km\n", valor, resultado);
                        }
                        else
                        {
                            printf("Opcion no valida.\n");
                        }
                    }
                }
            }
        }
    }

    return 0;
}
