// Diego Alonso Ibarra Galindo
// Calcular el salario semanal de un trabajador (salario normal​,  salario extra​by​ salario total​)
// Elaborado: 10/02/2024   Modificado: 11/02/2024
// DAIG_ACT1_07.cpp

#include <stdio.h>
#include <windows.h>

#define COLOR_DEFECTO 7 // Gris claro
#define COLOR_VERDE 10 // Verde
#define COLOR_CYAN 11 // Cian
void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    int hr_t, hrEx, turnNorm=40;
    double salH, salN, salEx, salTot;
    setTextColor(COLOR_CYAN);
    printf("\nIngrese las horas semanales trabajadas: ");
    scanf("%d", &hr_t);
    printf("\nIngrese el salario por hora: ");
    scanf("%lf", &salH);
    //salario normal y extra
    if (hr_t <= turnNorm) {
        salN = hr_t * salH; 
        salEx = 0.0;
    } else {
        hrEx = hr_t - turnNorm;
        if (hrEx <= 9) {
            salN = turnNorm * salH;
            salEx = hrEx * salH * 2; // doble pago
        } else {
            salN = turnNorm * salH;
            salEx = 9 * salH * 2 + (hrEx - 9) * salH * 3; // triple pago
        }
    }
    salTot = salN + salEx;

    setTextColor(COLOR_VERDE);
    printf("\nSalario por hora: $%.2lf\n", salH);
    printf("Horas trabajadas: %d\n", hr_t);
    printf("Salario normal: $%.2lf\n", salN);
    printf("Salario extra: $%.2lf\n", salEx);
    printf("Salario total: $%.2lf\n \n", salTot);
    setTextColor(COLOR_DEFECTO);

    return 0;
}
