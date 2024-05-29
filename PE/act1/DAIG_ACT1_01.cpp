// Diego Alonso Ibarra Galindo
// Calcular el volumen de un cilindro
// Elaborado: 09/02/2024
// DAIG_ACT1_01.cpp


#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{

    float r, vol,h;   //radio, volumen, alto
    printf ("ingrese el radio de la base: ");
    scanf("%f", &r);
    printf ("ingrese la altura del cilidro: ");
    scanf("%f", &h );

    vol= M_PI*pow(r,2)*h;

    printf ("El vol del cilindro es: %.4f", vol);

return 0;
}
