#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctime>

int main()
{
    clock_t inicio = clock();

    float r, vol,h;
    printf ("ingrese el radio de la base: ");
    scanf("%f", &r);
    printf ("ingrese la altura del cilidro: ");
    scanf("%f", &h );

    
    vol= M_PI*pow(r,2)*h;

    printf ("El vol del cilindro es: %.4f", vol);

    clock_t fin = clock();  /////
    double time = double(fin - inicio) / CLOCKS_PER_SEC;
    printf("\n%.10f", time);


return 0;
}