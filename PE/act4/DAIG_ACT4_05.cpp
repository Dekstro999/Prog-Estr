// Diego Alonso Ibarra Galindo
// Total de una llamada telefónica
// Elaborado: 24/02/2024 
// DAIG_ACT4_05.cpp

#include <stdio.h>

int main()
{
    int minutos, tipoLlamada;
    float subtotal, iva, total;

    printf("Ingrese los minutos de la llamada: ");
    scanf("%d", &minutos);
    printf("Ingrese el tipo de llamada:\n");
    printf("1. Llamada Local\n");
    printf("2. Llamada Nacional\n");
    printf("3. Llamada Internacional\n");
    scanf("%d", &tipoLlamada);

    if (tipoLlamada == 1) // Llamada Local
    {
        subtotal = 3.0; 
    }
    else 
    {
        if (tipoLlamada == 2) // Llamada Nacional
        {
            if (minutos > 3)
            {
                subtotal = 7.0 + (minutos - 3) * 2.0; 
            }
            else
            {
                subtotal = 7.0;
            }
        }
        else 
        {
            if (tipoLlamada == 3) // Llamada Internacional
            {
                if (minutos > 2)
                {
                    subtotal = 9.0 + (minutos - 2) * 4.0;
                }
                else
                {
                    subtotal = 9.0;
                }
            }
            else
            {
                printf("Tipo de llamada incorrecto.\n");
                return 1;
            }
        }
    }
    iva = subtotal * 0.16;
    total = subtotal + iva;

    printf("\nSubtotal: %.2f\n", subtotal);
    printf("IVA (16%%): %.2f\n", iva);
    printf("Total: %.2f\n", total);

    return 0;
}
