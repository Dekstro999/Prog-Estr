// Diego Alonso Ibarra Galindo
// calcular el salario semanal de un trabajador
// Elaborado: 24/02/2024 
// DAIG_ACT4_04.cpp


#include <stdio.h>

int main()
{
    float hrsT, salH, salN, salEx, salTo;
    const float jornN = 40;
    const float exDob = 2;
    const float exTri = 3;

    printf("Ingrese las horas trabajadas: ");
    scanf("%f", &hrsT);
    printf("Ingrese el salario por hora: ");
    scanf("%f", &salH);

    if (hrsT <= jornN)
    {
        salN = hrsT * salH;
        salEx = 0.0;
    }
    else
    {
        salN = jornN * salH;
        float hrsEx = hrsT - jornN;
        float hrsExDob = (hrsEx < 9) ? hrsEx : 9;     // hrsEx si hrsEx es menor que 9; de lo contrario, será igual a 9.
        float hrsExTri = (hrsEx > 9) ? hrsEx - 9 : 0; // hrsEx - 9 si hrsEx es mayor que 9; de lo contrario, será igual a 0.
        salEx = hrsExDob * salH * exDob + hrsExTri * salH * exTri;
    }

    salTo = salN + salEx;

    // Despliegue de resultados
    printf("\nSalario por hora: %.2f\n", salH);
    printf("Horas trabajadas: %.2f\n", hrsT);
    printf("Salario normal: %.2f\n", salN);
    printf("Salario extra: %.2f\n", salEx);
    printf("Salario total: %.2f\n", salTo);

    return 0;
}
