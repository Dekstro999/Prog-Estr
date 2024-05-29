#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Prototipos de funciones
void convCapital(char str[]);
char *validarCadena(char str[]);
void generarCURP();

// Función principal
int main()
{
  int opcion;
  do
  {
    printf("\n***** Generador de CURP *****\n");
    generarCURP();
    printf("\n¿Desea generar otro CURP? (1 para Sí, 0 para No): ");
    scanf("%d", &opcion); // Corregir la cadena de formato aquí
  } while (opcion != 0);
  return 0;
}

// Resto del código...

// Función para generar el CURP
void generarCURP()
{
  char nombre[50];
  char apellidoPaterno[50];
  char apellidoMaterno[50];
  char sexo;
  int dia, mes, anio;
  char estado[3];
  char curp[19];

  // Solicitar datos al usuario
  printf("Ingrese el nombre completo: ");
  scanf(" %[^\n]%*c", nombre);
  convCapital(nombre); // Convertir a mayúsculas

  char *nombreValidado = validarCadena(nombre);
  if (nombreValidado == NULL)
  {
    return;
  }
  strcpy(nombre, nombreValidado);

  printf("Ingrese el apellido paterno: ");
  scanf(" %[^\n]%*c", apellidoPaterno);
  convCapital(apellidoPaterno); // Convertir a mayúsculas

  printf("Ingrese el apellido materno: ");
  scanf(" %[^\n]%*c", apellidoMaterno);
  convCapital(apellidoMaterno); // Convertir a mayúsculas

  printf("Ingrese el sexo (H/M): ");
  scanf(" %c", &sexo);

  printf("Ingrese la fecha de nacimiento:\n");
  printf("Día: ");
  scanf("%d", &dia);
  printf("Mes: ");
  scanf("%d", &mes);
  printf("Año: ");
  scanf("%d", &anio);

  printf("Ingrese las primeras dos letras del estado de nacimiento (en mayúsculas): ");
  scanf("%s", estado);

  // Generar CURP
  curp[0] = toupper(apellidoPaterno[0]);
  curp[1] = toupper(apellidoPaterno[1]);
  curp[2] = toupper(apellidoMaterno[0]);
  curp[3] = toupper(nombre[0]);
  sprintf(curp + 4, "%02d%02d%02d%c%c%s", anio % 100, mes, dia, sexo, estado[0], estado[1]);
  curp[16] = '0'; // Dígito verificador temporal
  curp[17] = '1'; // Dígito verificador temporal
  curp[18] = '\0';

  // Imprimir CURP
  printf("El CURP generado es: %s\n", curp);
}

// Función para convertir a mayúsculas
void convCapital(char str[])
{
  int i = 0;
  while (str[i] != '\0')
  {
    str[i] = toupper(str[i]);
    i++;
  }
}

// Función para validar la cadena
char *validarCadena(char str[])
{
  int longitud = strlen(str);
  for (int i = 0; i < longitud; i++)
  {
    if (!isalpha(str[i]) && str[i] != ' ')
    {
      printf("Cadena inválida. Por favor, ingrese solo caracteres alfabéticos y espacios.\n");
      return NULL;
    }
  }
  return str;
}


void separarCadenas(char cadDest1[], char cadDest2[], char cadena[])
{
    int i, j;
    for (i = 0; cadena[i] != ' ' && cadena[i] != '\0'; i++)
    {
        cadDest1[i] = cadena[i];
    }
    cadDest1[i] = '\0'; // Terminar cadena correctamente

    if (cadena[i] == ' ')
    {
        i++; // Saltar espacio
        j = 0;
        while (cadena[i] != '\0')
        {
            cadDest2[j] = cadena[i];
            i++;
            j++;
        }
        cadDest2[j] = '\0'; // Terminar cadena correctamente
    }
    else
    {
        cadDest2[0] = '\0'; // Si no hay segunda cadena, asigna nulo
    }
}