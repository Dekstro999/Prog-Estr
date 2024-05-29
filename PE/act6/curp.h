// Diego Alonso Ibarra Galindo
// programa 100% validada las reglas que Se deben cuplir al generar el curp
// Elaborado: 5/04/2024  Modificado: 12/04/2024
// DAIG_CURP.h

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

// Define colores
#define DEF 7    // Gris claro
#define AZUL 9   // Azul
#define VERDE 10 // Verde
#define CYAN 11  // Cian
#define ROJO 12  // Rojo
#define AMARI 14 // Aarillo

// Estructura para almacenar el nombre completo del estado y su abreviatura
struct Estado
{
  char nombre[40];
  char abreviatura[3];
};

// Array de estructuras que almacena los nombres completos de los estados y sus abreviaturas
struct Estado estados[] = {
    {"Aguascalientes", "AS"},
    {"Baja California", "BC"},
    {"Baja California Sur", "BS"},
    {"Campeche", "CC"},
    {"Coahuila de Zaragoza", "CL"},
    {"Colima", "CM"},
    {"Chiapas", "CS"},
    {"Chihuahua", "CH"},
    {"Ciudad de México", "DF"},
    {"Durango", "DG"},
    {"Guanajuato", "GT"},
    {"Guerrero", "GR"},
    {"Hidalgo", "HG"},
    {"Jalisco", "JC"},
    {"México", "MC"},
    {"Michoacán de Ocampo", "MN"},
    {"Morelos", "MS"},
    {"Nayarit", "NT"},
    {"Nuevo León", "NL"},
    {"Oaxaca", "OC"},
    {"Puebla", "PL"},
    {"Querétaro", "QT"},
    {"Quintana Roo", "QR"},
    {"San Luis Potosí", "SP"},
    {"Sinaloa", "SL"},
    {"Sonora", "SR"},
    {"Tabasco", "TC"},
    {"Tamaulipas", "TS"},
    {"Tlaxcala", "TL"},
    {"Veracruz de Ignacio de la Llave", "VZ"},
    {"Yucatán", "YN"},
    {"Zacatecas", "ZS"},
    {"Nacionalidad Extranjera", "NE"}};

int cantidadEstados = sizeof(estados) / sizeof(estados[0]); // Calcular la cantidad de elementos en el array

// * * * * * PROTOTIPOS * * * * * *

void TextColor(int color);

void anima();
int validar_letras(char *cadena);
int validar_num();
void eliminarNuevaLinea(char *cadena);
void eliminarPrimeraPalabra(char *cadena);

void letrasPaterno(char *inicialP, char *vocalP, char *paterno);
void letrasMaterno(char *inicialMatr, char *materno);
int obtenerInicialNombre(char *inicial, char *nombre);

int esFechaValida(int anio, int mes, int dia);
void ingresarFechaNacimiento(int *anio, int *mes, int *dia, char *siglo);

char siguienteConsonante(char *cadena);
void generarNumeroAleatorio(int *ultiNum);

void convertirMayusculas(char *cadena);

// * * * * DESARROLLO DE FUNCIONES * * * * //

void TextColor(int color)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void anima()
{
  TextColor(AMARI);
  char caracteres[] = "/-\\|"; // Caracteres de la animación
  int num_caracteres = sizeof(caracteres) - 1;
  int tiempo_animacion = 200; // Tiempo en milisegundos entre cambios
  int i;

  printf(" ");

  for (i = 0; i < 20; i++)
  {
    printf(" \b\b\b%c ", caracteres[i % num_caracteres]);
    fflush(stdout);          // Asegura que se muestren los caracteres
    Sleep(tiempo_animacion); // Espera antes de mostrar el siguiente caracter
  }
}

// Función para validar que se ingresen solo letras en una cadena
int validar_letras(char *cadena)
{
  convertirMayusculas(cadena);
  // Reemplazar antes de la validación
  for (int i = 0; cadena[i] != '\0'; ++i)
  {

    switch ((unsigned char)cadena[i])
    {
    case 160: // Á
      cadena[i] = 'A';
      break;
    case 130: // É
      cadena[i] = 'E';
      break;
    case 161: // Í
      cadena[i] = 'I';
      break;
    case 162: // Ó
      cadena[i] = 'O';
      break;
    case 163: // Ú
      cadena[i] = 'U';
      break;
    case 129: // Ü
      cadena[i] = 'U';
      break;
    case 164: // Ñ
      cadena[i] = 'X';
      break;
    }
  }
  // printf("final.%s|\n", cadena); // Mensaje de depuración
  for (int i = 0; cadena[i] != '\0'; ++i)
  {
    if (!isalpha(cadena[i]) && cadena[i] != '\n')
    {
      TextColor(AMARI);
      printf("|");
      TextColor(ROJO);
      printf("     x x x > INGRESE SOLO LETRAS < x x x     ");
      TextColor(AMARI);
      printf("| ");
      system("pause");
      printf("\033[1A\033[K");
      printf("\033[1A\033[K");

      return 0; // Si encuentra un carácter que no es una letra y no es un salto de línea, retorna falso
    }
  }
  return 1;
}
// * * * * * * * * * * * * * * * *
int validar_num()
{
  int num;

  if (scanf("%d", &num) == 1)
  {
    while (getchar() != '\n')
      ;
    return num;
  }
  else
  {
    TextColor(AMARI);
    printf("\033[F\t\t\t\t\t\t\b\b|\n");
    TextColor(ROJO);
    printf("**Invalido. Por favor ingrese solo numeros.**");
    TextColor(DEF);

    system("pause");
    printf("\033[1A\033[K");
    printf("\033[1A\033[K");
    while (getchar() != '\n') // Limpiar el búfer del teclado
      ;
  }
  return -1;
}
// * * * * * * * * * * * * * * * *
void eliminarNuevaLinea(char *cadena)
{
  int longitud = strlen(cadena);
  if (longitud > 0 && cadena[longitud - 1] == '\n')
  {
    cadena[longitud - 1] = '\0';
  }
}

void eliminarPrimeraPalabra(char *cadena)
{
  // Eliminar cualquier espacio al final de la cadena
  int longitud = strlen(cadena);
  while (longitud > 0 && cadena[longitud - 1] == ' ')
  {
    cadena[longitud - 1] = '\0';
    longitud--;
  }

  // Mientras haya un espacio
  while (strchr(cadena, ' ') != NULL)
  {
    // printf("actual.%s|\n", cadena);            // Mensaje de depuración
    char *primerEspacio = strchr(cadena, ' '); // primera posición de espacio en la cadena

    if (primerEspacio != NULL) // al menos un espacio
    {
      strcpy(cadena, primerEspacio + 1); // copy
    }
  }
  // printf("final.%s|\n", cadena); // Mensaje de depuración
}

// * * * * * * * * * * * * * * * *

void letrasPaterno(char *inicialP, char *vocalP, char *paterno)
{
  do
  {
    printf("|");
    TextColor(VERDE);
    printf(" Apellido paterno:  ");
    TextColor(AMARI);
    printf("|  ");
    TextColor(VERDE);
    fgets(paterno, 25, stdin);
    TextColor(AMARI);
    paterno[strcspn(paterno, "\n")] = '\0'; // Eliminamos el enter
    printf("\033[F\t\t\t\t\t\t\b\b|\n");    // Mover el cursor una línea hacia arriba y cerra la tabla
                                            // printf("%*c\n", 30, '|');

    eliminarPrimeraPalabra(paterno);
    convertirMayusculas(paterno);

  } while (!validar_letras(paterno));

  if (strlen(paterno) == 0) // Si la cadena está vacía
  {
    *inicialP = 'X';
    *vocalP = 'X';
    strcpy(paterno, "XXX");
    return;
  }
  else
  {
    convertirMayusculas(paterno);
    *inicialP = paterno[0];

    for (int i = 1; paterno[i] != '\0'; ++i)
    {
      if (paterno[i] == 'A' || paterno[i] == 'E' ||
          paterno[i] == 'I' || paterno[i] == 'O' ||
          paterno[i] == 'U')
      {
        *vocalP = paterno[i];
        return;
      }
    }
  }
}
// * * * * * * * * * * * * * * * *

void letrasMaterno(char *inicialMatr, char *materno)
{
  do
  {

    printf("|");
    TextColor(VERDE);
    printf(" Apellido materno:  ");
    TextColor(AMARI);
    printf("|  ");
    TextColor(VERDE);
    fgets(materno, 20, stdin);
    TextColor(AMARI);
    materno[strcspn(materno, "\n")] = '\0';
    printf("\033[F\t\t\t\t\t\t\b\b|\n");
    eliminarPrimeraPalabra(materno);

  } while (!validar_letras(materno));

  if (strlen(materno) == 0) // Si presiona Enter sin ingresar nada
  {
    *inicialMatr = 'X';
    strcpy(materno, "XXX");
  }
  else
  {
    convertirMayusculas(materno);
    *inicialMatr = materno[0];
  }
}
// * * * * * * * * * * * * * * * *

int obtenerInicialNombre(char *inicial, char *nombre)
{
  char segundoNombre[15];
  do
  {
    printf("|");
    TextColor(VERDE);
    printf(" Primer  nombre:    ");
    TextColor(AMARI);
    printf("|  ");
    TextColor(VERDE);
    // scanf("%s", nombre);
    fgets(nombre, 15, stdin);
    TextColor(AMARI);
    nombre[strcspn(nombre, "\n")] = '\0';
    printf("\033[F\t\t\t\t\t\t\b\b|\n");

  } while (!validar_letras(nombre));
  eliminarPrimeraPalabra(nombre);

  convertirMayusculas(nombre);

  do
  {
    printf("|");
    TextColor(VERDE);
    printf(" Segundo nombre:    ");
    TextColor(AMARI);
    printf("|  ");
    TextColor(VERDE);
    // scanf("%s", segundoNombre);
    fgets(segundoNombre, 15, stdin);
    TextColor(AMARI);
    segundoNombre[strcspn(segundoNombre, "\n")] = '\0';
    eliminarPrimeraPalabra(segundoNombre);
    printf("\033[F\t\t\t\t\t\t\b\b|\n");

  } while (!validar_letras(segundoNombre));
  eliminarPrimeraPalabra(segundoNombre);

  convertirMayusculas(segundoNombre);
  if (strlen(segundoNombre) == 0)
  {
    *inicial = nombre[0];

    return 0;
  }

  if (strcmp(nombre, "MARIA") == 0 || strcmp(nombre, "MA.") == 0 ||
      strcmp(nombre, "MA") == 0 || strcmp(nombre, "M.") == 0 ||
      strcmp(nombre, "M") == 0 || strcmp(nombre, "JOSE") == 0 ||
      strcmp(nombre, "J.") == 0 || strcmp(nombre, "J") == 0)
  {

    *inicial = segundoNombre[0];
    strcpy(nombre, segundoNombre);
  }
  else
  {
    *inicial = nombre[0];
  }
  return 0;
}
// * * * * * * * * * * * * * * * *
//  (no mayor que la fecha actual)
int esFechaValida(int anio, int mes, int dia)
{
  time_t tiempoActual;
  struct tm *infoTiempo;
  time(&tiempoActual);
  infoTiempo = localtime(&tiempoActual);

  int anioActual = infoTiempo->tm_year + 1900;
  int mesActual = infoTiempo->tm_mon + 1;
  int diaActual = infoTiempo->tm_mday;

  if (anio > anioActual)
    return 0;
  else if (anio == anioActual && mes > mesActual)
    return 0;
  else if (anio == anioActual && mes == mesActual && dia > diaActual)
    return 0;

  return 1;
}
// * * * * * * * * * * * * * * * *
void ingresarFechaNacimiento(int *anio, int *mes, int *dia, char *siglo)
{
  int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int errores = 0;
  do
  {
    printf("|- - - - Ingrese la fecha de nacimiento - - - | \n");

    do
    {
      printf("|");
      TextColor(VERDE);
      printf(" > A%co (YYYY):      ", 164);
      TextColor(AMARI);
      printf("|  ");
      TextColor(VERDE);

      *anio = validar_num();
      TextColor(AMARI);
      printf("\033[F\t\t\t\t\t\t\b\b|\n");
      if (*anio == -1)
        continue; // Repetir si no es válido
      if (*anio != -1 && *anio < 1500)
      {
        TextColor(ROJO);
        printf("\033[F\t\t\t\t\t\t\b*\n");
        TextColor(AMARI);
      }
      errores++;
    } while (*anio == -1 || *anio < 1500);

    if (*anio < 2000)
    {
      *siglo = '0';
    }
    else
    {
      if (*anio < 2010)
      {
        *siglo = 'A';
      }
      else
      {
        if (*anio < 2020)
        {
          *siglo = 'B';
        }
        else
        {
          if (*anio < 2030)
          {
            *siglo = 'C';
          }
        }
      }
    }

    // año bisiesto
    if ((*anio % 4 == 0 && *anio % 100 != 0) || (*anio % 400 == 0))
      diasPorMes[2] = 29;
    else
      diasPorMes[2] = 28;

    do
    {
      printf("|");
      TextColor(VERDE);
      printf(" > Mes (MM):        ");
      TextColor(AMARI);
      printf("|  ");
      TextColor(VERDE);

      *mes = validar_num();
      TextColor(AMARI);
      printf("\033[F\t\t\t\t\t\t\b\b|\n");

      if (*mes == -1)
        continue;
      if (*mes != -1 && (*mes < 1 || *mes > 12))
      {
        TextColor(ROJO);
        printf("\033[F\t\t\t\t\t\t\b*\n");
        TextColor(AMARI);
      }

      errores++;

    } while (*mes == -1 || *mes < 1 || *mes > 12);

    do
    {
      printf("|");
      TextColor(VERDE);
      printf(" > Dia (DD):        ");
      TextColor(AMARI);
      printf("|  ");
      TextColor(VERDE);

      *dia = validar_num();
      TextColor(AMARI);
      printf("\033[F\t\t\t\t\t\t\b\b|\n");
      if (*dia == -1)
        continue;
      if (*dia != -1 && (*dia < 1 || *dia > diasPorMes[*mes]))
      {
        TextColor(ROJO);
        printf("\033[F\t\t\t\t\t\t\b*\n");
        TextColor(AMARI);
      }
      errores++;

    } while (*dia == -1 || *dia < 1 || *dia > diasPorMes[*mes]);

    if (!esFechaValida(*anio, *mes, *dia))
    {
      TextColor(AMARI);
      printf("\033[F\t\t\t\t\t\t\b\b|\n");

      printf("|");
      TextColor(ROJO);
      printf(" -  Ingrese una fecha anterior a la actual. - \n");
      TextColor(AMARI);
      printf("\033[F\t\t\t\t\t\t\b\b| ");
      system("pause");

      for (int i = 0; i <= errores + 1; i++)
      {
        printf("\033[1A\033[K");
      }
    }
  } while (!esFechaValida(*anio, *mes, *dia));
  *anio = *anio % 100;
}

char siguienteConsonante(char *str)
{
  int i, longitud = strlen(str);
  for (i = 1; i < longitud; i++)
  {
    if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
    {
      char c = toupper(str[i]);
      if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
      {
        return c; // primera consonante
      }
    }
  }
  return 'X';
}
// * * * * * * * * * * * * * * * *

void generarNumeroAleatorio(int *ultiNum)
{
  *ultiNum = rand() % 10; // entre 0 y 9
}

void convertirMayusculas(char *cadena)
{
  for (int i = 0; cadena[i] != '\0'; ++i)
  {
    cadena[i] = toupper(cadena[i]);
  }
}