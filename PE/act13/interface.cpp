#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#include "_curp.h"

void interaface(int ancho, int largo, int column, int tamTitulo, const char *titulo);
void printInterf(const char *texto);
int canti(char str[]);
void printRes(int saltos, ...);

int main()
{


    interaface(9, 10, 2, 1, "-> 12345678 <-");
     printInterf("\na l \nin \nea \n2d \na li \nnea \n3ra lin \nea \netc...\n");
    printRes(22, "HOLA", "str2", "str3", NULL);
}

void interaface(int ancho, int largo, int column, int tamTitulo, const char *titulo)
{
    int longi;
    int anchoTotl;
    char Titulo[100];
    strcpy(Titulo, titulo);

    longi = canti(Titulo);
    ancho = ancho * 4;
    anchoTotl = ancho + longi;

    if (column == 2)
    {
        anchoTotl -= 1;
    }

    system("cls");

    printf("\n\n");
    TextColor(AMARI);
    printf("%c", 218);
    for (int i = 0; i <= anchoTotl; i++)
    {
        printf("%c", 196);
    }
    if (column == 2)
    {
        printf("%c", 196);
    }

    printf("%c\n%c", 191, 179);
    TextColor(CYAN);
    for (int i = 0; i < ancho / 2; i++)
    {

        printf(" ");
    }
    printf("%s", titulo);

    TextColor(AMARI);
    for (int i = 0; i < ancho / 2 + 1; i++)
    {

        printf(" ");
    }

    printf("%c\n", 179);
    for (int i = 1; i < tamTitulo; i++)
    {
        printf("%c", 179);
        for (int i = 0; i < anchoTotl + 1; i++)
        {
            if (column == 2)
            {
                if (i == 1)
                {
                    printf(" ");
                }
            }
            printf(" ");
        }
        printf("%c\n", 179);
    }

    printf("%c", 195);
    for (int i = 0; i <= anchoTotl; i++)
    {
        if (column == 2)
        {

            if (i == anchoTotl / 2)
            {
                printf("%c", 194);
            }
        }
        printf("%c", 196);
    }
    printf("%c\n", 180);

    // generarCURP(curp);
    for (int i = 0; i < largo; i++)
    {

        printf("%c", 179);

        for (int i = 0; i <= anchoTotl; i++)
        {
            if (column == 2)
            {

                if (i == anchoTotl / 2)
                {
                    printf("%c", 179);
                }
            }
            printf(" ");
        }
        printf("%c\n", 179);
    }
    // printf("  %s    ", curp);
    printf("%c", 192);

    for (int i = 0; i <= anchoTotl; i++)
    {
        if (column == 2)
            if (i == anchoTotl / 2)
            {
                printf("%c", 193);
            }

        printf("%c", 196);
    }
    printf("%c\n", 217);

    for (int i = 0; i <= largo; i++)
    {
        printf("\033[1A");
    }
}

void printInterf(const char *texto)
{
    TextColor(DEF);
    const char *ptr = texto;
    int linea = 1;

    // Iterar sobre el texto
    while (*ptr != '\0')
    {
        // Imprimir el número de línea
        printf("\t\b\b\b\b\b\b\b");

        printf("%d. ", linea);

        // Imprimir la línea actual hasta encontrar un salto de línea o el final del texto
        while (*ptr != '\n' && *ptr != '\0')
        {
            putchar(*ptr);
            ptr++;
        }

        // Imprimir un salto de línea al final de cada línea
        putchar('\n');

        // Avanzar al siguiente carácter después del salto de línea o al final del texto
        if (*ptr == '\n')
        {
            ptr++;
        }
        linea++;
    }
    printf("\t\b\b\b\b\b\b\b");
}

int canti(char str[]) // 4
{
    printf("%s...", str);
    int contador = 0;
    while (str[contador] != '\0')
    {
        contador++;
    }
    return contador;
}

void printRes(int saltos, ...)
{
    va_list args;
    va_start(args, saltos);
    int saltost = saltos;

    // printf("Resultado: %d\n", resultado);

    // Imprimir cada argumento adicional
    int arg = 1;
    const char *cadena;
    //int numero;
     //printf("%d\n", saltost);

    while ((cadena = va_arg(args, const char *)) != NULL)
    {
        int i=0;
        do
        {
            printf("\t\b\b\b\b\b\b");
            printf(".");
            i++;
        } while (i <= saltost);
        // numero = va_arg(args, int);

        printf("%s\n", cadena);
        arg++;
    }

    va_end(args);
}