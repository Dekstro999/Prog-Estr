#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Prototipos de funciones
int msges();
void menu();
void leercadena(char str[]);          // 1
void convMayuscula(char str[]);       // 2
void convMinuscula(char str[]);       // 3
void convCapital(char str[]);         // 4
int contarCaract(char str[]);         // 5
char *invertirCadena(char str[]);     // 6
char *eliminarEspacios(char str[]);   // 7
char *validarCadena(char str[]);      // 8
void funcionesAnteriores(char str[]); // 9
void palindromo(char str[]);

//**** main principal
int main()
{
    menu();
    return 0;
}
// *** DESARROLLO DE LAS FUNCIONES ******
int msges()
{
    int op;
    system("CLS");
    printf(" ME N U \n");
    printf("1. Convertir a Mayusculas \n");
    printf("2. convMinuscula \n");
    printf("3.- convCapital \n");
    printf("4. contarCaract \n");
    printf("5.- invertir cadena \n");
    printf("6. eliminar espacios \n");
    printf("7.- solo de A-Z sin doble espacio \n");
    printf("8. TODO LO ANTERIOR \n");
    printf("9.- PALINDROMO\n");
    printf("0.- SALIR \n");
    printf("ESCOGE UNA OPCION: \n >>");
    scanf("%d", &op);
    return op;
}
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
            convMayuscula(cad);
            break;
        case 2:
            convMinuscula(cad);
            break;
        case 3:
            convCapital(cad);
            break;
        case 4:
            contarCaract(cad);
            break;
        case 5:
            invertirCadena(cad);
            break;
        case 6:
            eliminarEspacios(cad);
            break;
        case 7:
            validarCadena(cad);
            break;
        case 8:
            funcionesAnteriores(cad);
            break;
        case 9:
            palindromo(cad);
            break;
        }
    } while (op != 0);
}
void leercadena(char str[])
{
    system("cls");
    printf("dame la cadena: \n");
    fflush(stdin);
    fgets(str, 30, stdin); // Utilizar fgets() en lugar de gets()
    // Remover el carácter de nueva línea si está presente
    if (str[strlen(str) - 1] == '\n')
    {

        str[strlen(str) - 1] = '\0';
    }
}

void convMayuscula(char str[]) // 1
{
    printf("%s...", str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32; // Convertir a mayúsculas
        }
        i++;
    }
    printf("En mayusculas es: %s\n", str);
    system("PAUSE");
}
void convMinuscula(char str[]) // 2
{
    printf("%s...", str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32; // Convertir a minúsculas
        }
        i++;
    }
    printf("En minusculas es: %s\n", str);
    system("PAUSE");
}
void convCapital(char str[]) // 3
{
    printf("%s...", str);
    int i = 0;

    if (str[i] >= 'a' && str[i] <= 'z') // primera letra a mayúscula
    {
        str[i] = str[i] - 32; // Convertir a mayuscula
    }
    while (str[i] != '\0')
    {
        if (str[i] == ' ' && str[i + 1] != '\0') // Para espacios
        {
            if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
            {
                str[i + 1] = str[i + 1] - 32; // convertir a mayuscula
            }
        }
        i++;
    }
    printf("En capital es: %s\n", str);
    system("PAUSE");
}
int contarCaract(char str[]) // 4
{
    printf("%s...", str);
    int contador = 0;
    while (str[contador] != '\0')
    {
        contador++;
    }
    printf("Tiene %d caracteres \n", contador);
    system("PAUSE");
    return contador;
}
//
char *invertirCadena(char str[]) // 5
{
    printf("%s...", str);
    int longitud = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = longitud - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("%s\n", str);
    system("PAUSE");
    return str;
}
char *eliminarEspacios(char str[]) // 6
{
    printf("%s... ", str);
    int longitud = strlen(str);
    char *nuevacadena = (char *)malloc(longitud * sizeof(char)); // Asignar memoria dinámicamente

    int i, j = 0;
    for (i = 0; i < longitud; i++)
    {
        if (str[i] != ' ')
        {
            nuevacadena[j] = str[i];
            j++;
        }
    }
    nuevacadena[j] = '\0';
    printf("%s \n", nuevacadena);
    system("PAUSE");
    return nuevacadena;
}

char *validarCadena(char str[]) // 7
{
    printf("%s...", str);
    int longitud = strlen(str);
    char *nuevaCadena = (char *)malloc(longitud * sizeof(char));
    int i, j = 0;
    int tieneEspacio = 0;
    if (str[0] == ' ')
    {
        for (i = 0; i < longitud; i++)
        {
            if (str[i] != ' ')
            {
                if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
                {
                    nuevaCadena[j] = str[i];
                    tieneEspacio = 1;
                    j++;
                    break;
                }
                else
                {
                    printf("Cadena invalida. Por favor, ingrese solo caracteres alfanumerico");
                    system("PAUSE");
                    free(nuevaCadena); // Liberar la memoria asignada antes de retornar NULL
                    return NULL;       // cadena no es válida
                }
            }
        }
    }
    else
    {
        if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z')) // Corregir aquí
        {
            nuevaCadena[j] = str[0];
            j++;
        }
        else
        {
            printf("Cadena invalida. Por favor, ingrese solo caracteres alfabeticos");
            system("PAUSE");
            free(nuevaCadena);
            return NULL;
        }
    }
    for (i = 1; i < longitud; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            nuevaCadena[j] = str[i];
            tieneEspacio = 0;
            j++;
        }
        else
        {
            if (str[i] == ' ')
            {
                if (tieneEspacio == 0)
                {
                    nuevaCadena[j] = str[i];
                    tieneEspacio = 1;
                    j++;
                }
            }

            else
            {
                printf("Cadena invalida. Por favor, ingrese solo caracteres alfabeticos");
                system("PAUSE");
                free(nuevaCadena); 
                return NULL;       
            }
        }
    }
    if (nuevaCadena[j - 1] == ' ')
    {
        nuevaCadena[j - 1] = '\0'; // eliminar el último espacio
    }
    else
    {
        nuevaCadena[j] = '\0'; // carácter nulo al final de la nueva cadena
    }
    printf("%s \n", nuevaCadena);
    system("PAUSE");
    return nuevaCadena;
}

void funcionesAnteriores(char str[]) // 8
{
    printf("\n\nFUNCIONES ANTERIORES\n");
    printf("\nCadena original:   %s\n", str);
    convMayuscula(str);
    convMinuscula(str);
    convCapital(str);
    eliminarEspacios(str);
    invertirCadena(str);
}
void palindromo(char str[]) // 9
{
    validarCadena(str);
    convMayuscula(str);
    printf("\n\n%s...", str);
    int longitud = strlen(str);
    int i, j;

    char cadenaLimpia[longitud];
    int indiceLimpio = 0;
    for (i = 0; i < longitud; i++)
    {
        if (str[i] != ' ')
        {
            cadenaLimpia[indiceLimpio++] = toupper(str[i]); // Añade el carácter a cadenaLimpia en mayúsculas si no es un espacio.
        }
    }
    cadenaLimpia[indiceLimpio] = '\0'; // carácter nulo

    int esPalindromo = 1;
    for (i = 0, j = indiceLimpio - 1; i < j; i++, j--)
    {
        if (cadenaLimpia[i] != cadenaLimpia[j]) // Compara los caracteres en posiciones opuestas de la cadena.
        {
            esPalindromo = 0; // al menos 2 de diferentes
            break;
        }
    }
    if (esPalindromo)
    {
        printf("Si es un palindromo\n\n");
    }
    else
    {
        printf("No es un palindromo\n\n");
    }
    system("PAUSE");
}
