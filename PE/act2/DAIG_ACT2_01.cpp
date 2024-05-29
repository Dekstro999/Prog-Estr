// Diego Alonso Ibarra Galindo
// Lea 4 calificaciones, desplegar el promedio y APROBADO o REPROBADO
// Elaborado: 13/02/2024
// DAIG_ACT2_01.cpp


#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    float cal1, cal2, cal3, cal4, prom; 
    printf ("ingrese la 1ra calif: ");
    scanf("%f", &cal1);
    printf ("ingrese la 2da calif: ");
    scanf("%f", &cal2 );
    printf ("ingrese la 3ra calif: ");
    scanf("%f", &cal3 );
    printf ("ingrese la 4ta calif: ");
    scanf("%f", &cal4 );

    prom=(cal1+cal2+cal3+cal4)/4;

    if (prom>=60)
    {
        printf ("promedio de: %.2f APROBADO" ,prom);
    }
    if (prom<60)
    {
    printf ("\n promedio de: %.2f REPROBADO",prom);
    }

return 0;
}