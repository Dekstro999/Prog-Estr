// Diego Alonso Ibarra Galindo
// Lea 3 calificaciones calcule el promedio del alumno y desplegar:... (por el falso)
// Elaborado: 15/02/2024
// DAIG_ACT2_06.cpp

#include <stdio.h>
int main() 
{
    float cal1, cal2, cal3, promedio;
    printf("Ingrese la primera calificacion: ");
    scanf("%f", &cal1);
    printf("Ingrese la segunda calificacion: ");
    scanf("%f", &cal2);
    printf("Ingrese la tercera calificacion: ");
    scanf("%f", &cal3);
    promedio = (cal1 + cal2 + cal3) / 3;
    if (promedio < 30) 
    {
        printf("Repetir\n");
    } 
    else if (promedio < 60) 
    {
        printf("Extraordinario\n");
    } 
    else if (promedio < 70) 
    {
        printf("Suficiente\n");
    } 
    else if (promedio < 80) 
    {
        printf("Regular\n");
    } 
    else if (promedio < 90) 
    {
        printf("Bien\n");
    } 
    else if (promedio < 98) 
    {
        printf("Muy bien\n");
    } 
    else if (promedio <= 100) 
    {
        printf("Excelente\n");
    } 
    else 
    {
        printf("Error en promedio\n");
    }
    return 0;
}

