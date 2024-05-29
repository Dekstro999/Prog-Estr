// Diego Alonso Ibarra Galindo
// Calcular el salario semanal...entrada las​ horas semanales​ trabajadas,el​ salario por hora​ 
// Elaborado: 18/02/2024
// DAIG_ACT2_10.cpp

#include <stdio.h>
int main() 
{
    float hr_trab, sal_hr, sal_norm, sal_ex, tot;
    printf("Ingrese las horas semanales trabajadas: ");
    scanf("%f", &hr_trab);
    printf("Ingrese el salario por hora: ");
    scanf("%f", &sal_hr);
    if (hr_trab <= 40) 
    {
        sal_norm = hr_trab * sal_hr;
        sal_ex = 0;
    } 
    else 
    {
        sal_norm = 40 * sal_hr;
        float hrs_ex = hr_trab - 40;
        if (hrs_ex <= 9) 
        {
            sal_ex = hrs_ex * sal_hr * 2;
        } 
        else 
        {
            sal_ex = (9 * sal_hr * 2) + ((hrs_ex - 9) * sal_hr * 3);
        }
    }
    tot = sal_norm + sal_ex;
    printf("\nSalario por hora: %.2f\n", sal_hr);
    printf("Horas trabajadas: %.2f\n", hr_trab);
    printf("Salario normal: %.2f\n", sal_norm);
    printf("Salario extra: %.2f\n", sal_ex);
    printf("Salario total: %.2f\n", tot);
    return 0;
}
