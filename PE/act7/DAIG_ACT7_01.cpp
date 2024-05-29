// Diego Alonso Ibarra Galindo
// Función en C
// Elaborado: 11/03/2024  Modificado: 17/03/2024
// DAIG_ACT7_01.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curp.h"
#include <ctype.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void leercadena(char str[]);
void imprimircadena(char str[]);         // 1
void impRevCad(char str[]);              // 2
void impVertical(char str[]);            // 3
void impRevVertical(char str[]);         // 4
void impMenosLetraDerch(char str[]);     // 5
void impRevMenosLetraDerch(char str[]);  // 6
void impMenosLetraIzq(char str[]);       // 7
void impRevMenosLetraIzq(char str[]);    // 8
void impConsonantesYVocales(char str[]); // 9

//****  main principal  *********
int main()
{
    menu();
    return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- imprimir cadena \n");
    printf("2.- impRevCad \n");
    printf("3.- impVertical \n");
    printf("4.- impRevVertical \n");
    printf("5.- imprimir cadena menos letra derecha \n");
    printf("6.- imprimir cadena al reves menos letra derecha \n");
    printf("7.- imprimir cadena menos letra izquierda \n");
    printf("8.- imprimir cadena al reves menos letra izquierda \n");
    printf("9.- imprimir consonantes y vocales separadas \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: \n >>");
    op = validar_num();
    return op;
}
//****************
void menu()
{
    char cad[30];
    leercadena(cad);

    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            imprimircadena(cad);
            break;
        case 2:
            impRevCad(cad);
            break;
        case 3:
            impVertical(cad);
            break;
        case 4:
            impRevVertical(cad);
            break;
        case 5:
            impMenosLetraDerch(cad);
            break;
        case 6:
            impRevMenosLetraDerch(cad);
            break;
        case 7:
            impMenosLetraIzq(cad);
            break;
        case 8:
            impRevMenosLetraIzq(cad);
            break;
        case 9:
            impConsonantesYVocales(cad);
            break;
        }
    } while (op != 0);
}

//*********************
void leercadena(char str[])
{
    system("cls");
    printf("dame la cadena:  \n");
    fflush(stdin);
    gets(str);
}
//*********************
void imprimircadena(char str[]) //  1
{
    printf("%s\n", str);

    system("PAUSE");
}
//*************************
void impRevCad(char str[]) //  2
{
    int i, j, longitud = strlen(str);
    char temp;

    for (i = 0, j = longitud - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("\n%s\n\n", str);
    system("PAUSE");
}
//****************************
void impVertical(char str[]) // 3
{
    int longitud = strlen(str);
    int i;
    char car;

    for (i = 0; i < longitud; i++)
    {
        car = str[i];

        printf("%c\n", car);
    }
    system("PAUSE");
}
//****************************
void impRevVertical(char str[]) // 4
{
    int longitud = strlen(str);
    int i;
    char car;

    for (i = longitud - 1; i >= 0; i--)
    {
        car = str[i];

        printf("%c\n", car);
    }
    system("PAUSE");
}
//****************************
void impMenosLetraDerch(char str[]) // 5
{

    int longitud = strlen(str);
    int i, j;

    for (i = 0; i < longitud; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%c", str[j]);
        }
        printf("\n");
    }

    system("PAUSE");
}
//****************************
void impRevMenosLetraDerch(char str[]) // 6
{
    int i, j, longitud = strlen(str);

    for (i = longitud; i >= 1; i--)
    {
        for (j = 0; j < i; j++)
        {
            printf("%c", str[j]);
        }
        printf("\n");
    }
    system("PAUSE");
}
//****************************
void impMenosLetraIzq(char str[]) // 7
{
    int i, j, longitud = strlen(str);
    for (i = 0; i < longitud; i++)
    {
        for (j = i; j < longitud; j++)
        {
            printf("%c", str[j]);
        }
        printf("\n");
    }
    system("PAUSE");
}
//****************************
void impRevMenosLetraIzq(char str[]) // 8
{
    int i, j, longitud = strlen(str);
    char temp;

    for (i = 0, j = longitud - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    for (i = 0; i < longitud; i++)
    {
        for (j = i + 1; j < longitud; j++)
        {
            printf("%c", str[j]);
        }
        printf("\n");
    }
    system("PAUSE");
}
//****************************
void impConsonantesYVocales(char str[]) // 9
{
    int i, longitud = strlen(str);
    printf("\n");
    for (i = 1; i < longitud; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            char c = toupper(str[i]);
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                continue; // Si es vocal, no se imprime
            }
            else
            {
                printf("%c", str[i]);
            }
        }
    }
    printf("\n\n");
    for (i = 0; i < longitud; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            char c = toupper(str[i]);
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                printf("%c", str[i]);
            }
        }
    }
    printf("\n");
    system("PAUSE");
}
//****************************
