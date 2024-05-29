// Diego Alonso Ibarra Galindo
// Desplegar el Total de una llamada telefónica
// Elaborado: 13/02/2024
// DAIG_ACT2_11.cpp

#include <stdio.h>
int main() 
{
    float minutos, subtot, iva, tot;
    int ops;
    printf("Ingrese los minutos de la llamada: ");
    scanf("%f", &minutos);
    printf("Ingrese el tipo de llamada: \n1-Llamada Local \n2-Llamada Nacional \n3-Llamada Internacional \n >");
    scanf("%d", &ops);
    if (ops==1)
    {
        subtot = 3.0;
    }
    else if (ops==2)
    {
        if (minutos <= 3) 
        { 
            subtot = 7.0;
        } 
        else 
        {
            subtot = 7.0 + (minutos - 3) * 2.0;
        }
    }
    else if (ops==3)
    {
        if (minutos <= 2) 
        {
            subtot = 9.0;
        } 
        else 
        {
            subtot = 9.0 + (minutos - 2) * 4.0;
        }
    }
    else
    {
        printf("Tipo de llamada incorrecto.\n");
        return 1;
    }
    iva = subtot * 0.16;
    tot = subtot + iva;
    printf("\nSubtotal: %.2f\n", subtot);
    printf("IVA (16%%): %.2f\n", iva);
    printf("Total: %.2f\n", tot);
    return 0;
}

