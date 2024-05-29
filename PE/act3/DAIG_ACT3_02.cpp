// Diego Alonso Ibarra Galindo
// lea 3 números y desplegar cuál número es del medio y su valor..(OPTIMIZADO FORMA DE ARBOL)
// Elaborado: 20/02/2024
// DAIG_ACT3_02.cpp

#include <stdio.h>

int main()
{
    float num1, num2, num3;

    printf("Ingrese el 1er numero: ");
    scanf("%f", &num1);
    printf("Ingrese el 2do numero: ");
    scanf("%f", &num2);
    printf("Ingrese el 3er numero: ");
    scanf("%f", &num3);
    printf("\n");

 	if (num1 <= num2)
	{
		if (num2 <= num3)
		{
			printf("El numero del medio es:%.2f\n", num2);
		}
		else
		{
			if (num1 <= num3)
			{
				printf("El numero del medio es:%.2f\n", num3);
			}
			else
			{
				printf("El numero del medio es:%.2f\n", num1);
			}
		}
	}
	else
	{
		if (num1 <= num3)
		{
			printf("El numero del medio es:%.2f\n", num1);
		}
		else
		{
			if (num2 <= num3)
			{
				printf("El numero del medio es:%.2f\n", num3);
			}
			else
			{
				printf("El numero del medio es:%.2f\n", num2);
			}
		}
	}
	return 0;
}
