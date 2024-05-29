// Diego Alonso Ibarra Galindo
// Costo de sembrar pasto considerando cada metro cuadrado y alambre necesario para cercar
// Elaborado: 09/02/2024
// DAIG_ACT1_02.cpp

#include <stdio.h>

#define met2 35.50
int main() {
    float longi, ancho, area, tot, cantAl;

    printf("Ingrese la longitud del terreno en metros: ");
    scanf("%f", &longi);
    printf("Ingrese el ancho del terreno en metros: ");
    scanf("%f", &ancho);

    //area del terreno
    area = longi * ancho;
    //costo sembrar pasto
    tot = area * met2;
    //cantidad de alambre
    cantAl = 2 * (longi + ancho);

    printf("\nArea del terreno: %.2f m^2\n", area);
    printf("Costo total de sembrar pasto: $ %.2f\n", tot);
    printf("Cantidad de alambre necesaria para cercar el terreno: %.2f m\n", cantAl);

    return 0;
}

