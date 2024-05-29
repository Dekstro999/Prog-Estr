// Diego Alonso Ibarra Galindo
// calcular el promedio final, el menor de los exámenes se anula y el promedio se calcula en base a 4 exámenes.
// Elaborado: 25/02/2024 
// DAIG_ACT4_07.cpp

#include <stdio.h>

int main()
{
    float calif1, calif2, calif3, calif4, calif5, menor, promedio;
    printf("Ingrese la calificacion del examen 1: ");
    scanf("%f", &calif1);
    printf("Ingrese la calificacion del examen 2: ");
    scanf("%f", &calif2);
    printf("Ingrese la calificacion del examen 3: ");
    scanf("%f", &calif3);
    printf("Ingrese la calificacion del examen 4: ");
    scanf("%f", &calif4);
    printf("Ingrese la calificacion del examen 5: ");
    scanf("%f", &calif5);

    menor = calif1;
    if (calif2 < menor)
    {
        menor = calif2;
    }
    if (calif3 < menor)
    {
        menor = calif3;
    }
    if (calif4 < menor)
    {
        menor = calif4;
    }
    if (calif5 < menor)
    {
        menor = calif5;
    }

    promedio = (calif1 + calif2 + calif3 + calif4 + calif5 - menor) / 4.0;

    printf("\nPromedio final: %.2f\n", promedio);

    return 0;
}
