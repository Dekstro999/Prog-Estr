// Diego Alonso Ibarra Galindo
// Lea 3 calificaciones calcule el promedio del alumno y desplegar:... (OPTIMIZADO FORMA DE ARBOL)
// Elaborado: 20/02/2024  Actualizado: 21/02/2024
// DAIG_ACT3_01.cpp

#include <stdio.h>
int main()
{
    float cal1, cal2, cal3, prom;
    printf("\nIngrese la primera calificacion: ");
    scanf("%f", &cal1);
    printf("\nIngrese la segunda calificacion: ");
    scanf("%f", &cal2);
    printf("\nIngrese la tercera calificacion: ");
    scanf("%f", &cal3);
    prom = (cal1 + cal2 + cal3) / 3;
    printf("\nPromedio: %.2f ", prom);

    if (prom >= 80) 
    {
        if (prom >= 98) 
        {
            if (prom > 100) 
            {
                printf("\nError");
            } else 
            {
                printf("\nExcelente");
            }
        } 
        else 
        {
            if (prom >= 90) 
            {
                printf("\nMuy Bien");
            } 
            else 
            {
                printf("\nBien");
            }
        }
    } 
    else 
    {
        if (prom >= 60) 
        {
            if (prom >= 70) 
            {
                printf("\nRegular");
            } 
            else 
            {
                printf("\nSuficiente");
            }
        } 
        else 
        {
            if (prom > 30) 
            {
                printf("\nExtraordinario");
            } 
            else 
            {
                printf("\nRepetir");
            }
        }
    }

    return 0;
}
