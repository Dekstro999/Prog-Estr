// Diego Alonso Ibarra Galindo
// Función en C
// Elaborado: 19/03/2024  Modificado: 24/03/2024
// DAIG_ACT8_01.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO_VECTOR 10
#define TAMANO_VECTOR3 20
#define FILAS_MATRIZ 4
#define COLUMNAS_MATRIZ 4

// ******PROTOTIPOS************
int menu();
void llenarVectorManualmente(int vector[], int tamano);
void llenarVectorAleatoriamente(int vector[], int tamano);
void llenarVectorConVectores(int vector3[], int tamano3, int vector1[], int vector2[]);
void imprimirVectores(int vector1[], int vector2[], int vector3[], int tamano1, int tamano3);
void llenarMatrizConVectores(int matriz[][COLUMNAS_MATRIZ], int vector1[], int vector2[], int tamano);
void imprimirMatriz(int matriz[][COLUMNAS_MATRIZ]);

int main()
{
    srand(time(NULL)); // numeros aleatorios
    int opcion;
    int vector1[TAMANO_VECTOR] = {0};
    int vector2[TAMANO_VECTOR] = {0};
    int vector3[TAMANO_VECTOR3] = {0};
    int matriz[FILAS_MATRIZ][COLUMNAS_MATRIZ] = {0};

    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1:
            llenarVectorManualmente(vector1, TAMANO_VECTOR);
            break;
        case 2:
            llenarVectorAleatoriamente(vector2, TAMANO_VECTOR);
            break;
        case 3:
            llenarVectorConVectores(vector3, TAMANO_VECTOR3, vector1, vector2);
            break;
        case 4:
            imprimirVectores(vector1, vector2, vector3, TAMANO_VECTOR, TAMANO_VECTOR3);
            break;
        case 5:
            llenarMatrizConVectores(matriz, vector1, vector2, TAMANO_VECTOR);
            break;
        case 6:
            imprimirMatriz(matriz);
            break;
        case 0:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion no valida. Intente de nuevo.\n");
            break;
        }
        printf("\n");
    } while (opcion != 0);
    return 0;
}
//********** DESARROLLO DE FUNCIONES *******
int menu()
{
    int opcion;
    printf("\nMENU\n");
    printf("1.- LLENAR VECTOR 1 (MANUALMENTE)\n");
    printf("2.- LLENAR VECTOR 2 (ALEATORIAMENTE)\n");
    printf("3.- LLENAR VECTOR 3 (CON VECTOR 1 y 2)\n");
    printf("4.- IMPRIMIR VECTORES\n");
    printf("5.- LLENAR MATRIZ 4 X 4 CON VECTOR 1 y 2\n");
    printf("6.- IMPRIMIR MATRIZ\n");
    printf("0.- SALIR\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    fflush(stdin); // limpiar el buffer 
    return opcion;
}
void llenarVectorManualmente(int vector[], int tamano)
{
    printf("\nIngrese %d numeros para el vector(entre 30 y 70):\n", tamano);
    for (int i = 0; i < tamano; i++)
    {
        printf("Ingrese el valor %2d: ", i + 1);
        scanf("%d", &vector[i]);
        fflush(stdin); 
    }
}
void llenarVectorAleatoriamente(int vector[], int tamano)
{
    printf("\nLlenado de vector aleatoriamente . . .\n");
    for (int i = 0; i < tamano; i++)
    {
        vector[i] = rand() % 20 + 1; //  1 - 20
    }
}
void llenarVectorConVectores(int vector3[], int tamano3, int vector1[], int vector2[])
{
    printf("\nLlenado de vector 3 con vector 1 y vector 2 . . .\n");
    for (int i = 0; i < tamano3 / 2; i++)
    {
        vector3[i] = vector1[i];
        vector3[i + tamano3 / 2] = vector2[i];
    }
}
void imprimirVectores(int vector1[], int vector2[], int vector3[], int tamano1, int tamano3)
{
    printf("\nVector 1:\n");
    for (int i = 0; i < tamano1; i++)
    {
        printf("%2d ", vector1[i]);
    }
    printf("\n\nVector 2:\n");
    for (int i = 0; i < tamano1; i++)
    {
        printf("%2d ", vector2[i]);
    }
    printf("\n\nVector 3:\n");
    for (int i = 0; i < tamano3; i++)
    {
        printf("%2d ", vector3[i]);
    }
    printf("\n");
}
void llenarMatrizConVectores(int matriz[][COLUMNAS_MATRIZ], int vector1[], int vector2[], int tamano)
{
    printf("\nLlenado de la matriz con vector 1 y vector 2...\n");
    int indice = 0;
    for (int i = 0; i < FILAS_MATRIZ; i++)
    {
        for (int j = 0; j < COLUMNAS_MATRIZ; j++)
        {
            if (indice < tamano)
            {
                matriz[i][j] = vector1[indice];
            }
            else
            {
                matriz[i][j] = vector2[indice - tamano];
            }
            indice++;
        }
    }
}
void imprimirMatriz(int matriz[][COLUMNAS_MATRIZ])
{
    printf("\nMatriz 4x4:\n");
    for (int i = 0; i < FILAS_MATRIZ; i++)
    {
        for (int j = 0; j < COLUMNAS_MATRIZ; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

