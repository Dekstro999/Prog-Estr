// Diego Alonso Ibarra Galindo
// Total de una llamada telefónica (Local, Nacional, Internacional)
// Elaborado: 11/02/2024
// DAIG_ACT1_08.cpp

#include <stdio.h>
#include <windows.h>

#define COLOR_DEFECTO 7 // Gris claro
#define COLOR_VERDE 10 // Verde
#define COLOR_CYAN 11 // Cian

void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int main() {
    int mint, tipo;
    float subtot, iva, total;
    printf("\nIngrese los minutos de la llamada: ");
    scanf("%d", &mint);
    setTextColor(COLOR_VERDE);
    printf("Ingrese el tipo de llamada");
    setTextColor(COLOR_CYAN);
    printf("\n1. Local ");
    printf("\n2. Nacional");
    printf("\n3. Internacional ");
    printf("\n>> ");
    scanf("%d", &tipo);

    switch (tipo) {
        case 1: // llamada Local
            subtot = 3.0; // $3 sin límite
            break;
        case 2: // llamada Nacional
            if (mint <= 3) {
                subtot = 7.0; //$7 3 minutos
            } else {
                subtot = 7.0 + (mint - 3) * 2.0; //$2 adicional
            }
            break;
        case 3: // llamada Internacional
            if (mint <= 2) {
                subtot = 9.0; //$9 2 minutos
            } else {
                subtot = 9.0 + (mint - 2) * 4.0; // $4 adicional
            }
            break;
        default:
            setTextColor(COLOR_DEFECTO);
            printf("Tipo de llamada no válido.\n");
            return 1;
    }
    iva = subtot * 0.16;
    total = subtot + iva;
    setTextColor(COLOR_VERDE);
    printf("\nSubtotal: $%.2f\n", subtot);
    printf("IVA (16%%): $%.2f\n", iva);
    printf("Total: $%.2f\n \n", total);
    setTextColor(COLOR_DEFECTO);
    return 0;
}
