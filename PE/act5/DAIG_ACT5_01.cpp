// Diego Alonso Ibarra Galindo
// Función en C
// Elaborado: 1/03/2024  Modificado: 3/03/2024
// DAIG_ACT4_09.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 35

// Prototipos de funciones
int msges();
void menu();                    //
void numerosMenoresN();         //    <<----- F U N C I O N E S
void numerosAleatorios();       //
void numerosEntre100y200();     //
void tablaMultiplicar();        //

int main()
{
    menu();

    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- Numeros enteros positivos menores de n en orden descendente\n");
    printf("2.- Generar 40 numeros aleatorios entre 0 y 200\n");
    printf("3.- Generar 35 numeros aleatorios entre 100 y 200 y mostrar el mayor y el menor\n");
    printf("4.- Mostrar tabla de multiplicar de un numero dado\n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: \n >>");
    scanf("%d", &op);
    return op;
}

void menu()
{
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            numerosMenoresN();
            break;
        case 2:
            numerosAleatorios();
            break;
        case 3:
            numerosEntre100y200();
            break;
        case 4:
            tablaMultiplicar();
            break;
        default:
            if (op != 0)
            { 
                printf("Opcion erronea. Por favor, elige una opcion valida.\n");
                _sleep(3000);   // TIEMPO DE ESPERA DE 3 SEG                                                                                                            
            }
        }
    } while (op != 0);
}

// Función para mostrar numeros enteros positivos menores de n en orden descendente
void numerosMenoresN()
{
    int n;
    printf("\nIntroduce un numero entero positivo: ");
    scanf("%d", &n);
    printf("Numeros enteros positivos menores de %d:\n", n);
    for (int i = n - 1; i > 0; i--)
    {
        printf("%d, ", i);
    }
    printf("\n");
    system("pause");
}

void numerosAleatorios()
{
    srand(time(NULL));
    int pares = 0, impares = 0, sumaPares = 0, sumaImpares = 0;
    printf("\nNumeros aleatorios entre 0 y 200:\n");
    for (int i = 0; i < 40; i++)
    {
        int num = rand() % 201; // Generar un numero aleatorio entre 0 y 200
        printf("\n>> %d ", num);
        if (num % 2 == 0)
        {
            pares++;
            sumaPares += num;
        }
        else
        {
            impares++;
            sumaImpares += num;
        }
    }
    printf("\nCantidad de numeros pares: %d\n", pares);
    printf("Cantidad de numeros impares: %d\n", impares);
    printf("Suma de los numeros pares: %d\n", sumaPares);
    printf("Suma de los numeros impares: %d\n", sumaImpares);
    system("pause");
}

void numerosEntre100y200()
{
    srand(time(NULL));
    int mayor = 100, menor = 200;
    printf("\n35 numeros aleatorios entre 100 y 200:\n");
    for (int i = 0; i < N; i++)
    {
        int num = rand() % 101 + 100; // Generar un numero aleatorio entre 100 y 200
        printf("\n> %d ", num);
        if (num > mayor)
        {
            mayor = num;
        }
        if (num < menor)
        {
            menor = num;
        }
    }
    printf("\nNumero mayor: %d\n", mayor);
    printf("Numero menor: %d\n", menor);
    system("pause");
}

void tablaMultiplicar()
{
    int n;
    printf("\nIntroduce un numero entre 1 y 20 para mostrar su tabla de multiplicar: ");
    scanf("%d", &n);
    printf("Tabla del %d\n", n);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %2d = %3d\n", n, i, n * i);
    }
    system("pause");
}
