// Diego Alonso Ibarra Galindo
// calcular el Total a pagar por consumo de agua,
// Elaborado: 25/02/2024 
// DAIG_ACT4_06.cpp

#include <stdio.h>

int main()
{
    float m3_consumidos, subtotal, iva, total;

    // Lectura de los M3 de agua consumidos
    printf("Ingrese los M3 de agua consumidos: ");
    scanf("%f", &m3_consumidos);

    if (m3_consumidos <= 4)
    {
        subtotal = 50.0; // Rango 1
    }
    else 
    {
        if (m3_consumidos <= 15)
        {
            subtotal = 50.0 + (m3_consumidos - 4) * 8.0; // Rango 2
        }
        else 
        {
            if (m3_consumidos <= 50)
            {
                subtotal = 50.0 + 11 * (m3_consumidos - 15); // Rango 3
            }
            else
            {
                subtotal = 50.0 + 11 * (50 - 15) + 11 * (m3_consumidos - 50); // Rango 4
            }
        }
    }
    iva = subtotal * 0.16;
    total = subtotal + iva;

    printf("\nSubtotal: %.2f\n", subtotal);
    printf("IVA (16%%): %.2f\n", iva);
    printf("Total a pagar: %.2f\n", total);

    return 0;
}
