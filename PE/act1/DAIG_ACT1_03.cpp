// Diego Alonso Ibarra Galindo
// Lea 3 calificaciones calcule el promedio del alumno
// Elaborado: 09/02/2024
// DAIG_ACT1_03.cpp

#include <stdio.h>

int main()
{
    float cal1, cal2, cal3, prom;

    printf("Ingrese la 1ra calificacion: "); // 1
    scanf("%f", &cal1);
    printf("Ingrese la 2da calificacion: "); // 2
    scanf("%f", &cal2);
    printf("Ingrese la 3ra calificacion: "); // 3
    scanf("%f", &cal3);

    // promedio
    prom = (cal1 + cal2 + cal3) / 3;

    printf("El promedio es de: %.2f\n", prom);

    if (prom < 30)
    {
        printf("Repetir\n");
    }
    else if (prom >= 30 && prom < 60)
    {
        printf("Extraordinario\n");
    }
    else if (prom >= 60 && prom < 70)
    {
        printf("Suficiente\n");
    }
    else if (prom >= 70 && prom < 80)
    {
        printf("Regular\n");
    }
    else if (prom >= 80 && prom < 90)
    {
        printf("Bien\n");
    }
    else if (prom >= 90 && prom < 98)
    {
        printf("Muy bien\n");
    }
    else if (prom >= 98 && prom <= 100)
    {
        printf("Excelente\n");
    }
    else
    {
        printf("Error en promedio\n");
    }

    return 0;
}
