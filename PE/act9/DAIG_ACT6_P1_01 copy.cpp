#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definición de constantes
#define TAM_VECTOR 15
#define TAM_MATRIZ 4

// Prototipos de funciones
int msges();
void menu();
int validarNumero(char *input);
void llenarVector(int vector[], int tam);
void llenarMatriz(int matriz[][TAM_MATRIZ]);
void imprimirVector(int vector[], int tam);
void imprimirMatriz(int matriz[][TAM_MATRIZ]);
void ordenarVector(int vector[], int tam);
void buscarEnVector(int vector[], int tam, int valor);

// Función principal
int main()
{
  menu();
  return 0;
}

// Función para mostrar el menú y obtener la opción del usuario
int msges()
{
  int op;
  char input[2];
  printf("   M  E   N   U \n");
  printf("1.- LLENAR VECTOR \n");
  printf("2.- LLENAR MATRIZ \n");
  printf("3.- IMPRIMIR VECTOR \n");
  printf("4.- IMPRIMIR MATRIZ \n");
  printf("5.- ORDENAR VECTOR \n");
  printf("6.- BUSCAR VALOR EN VECTOR \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf("%1s", input);
  fflush(stdin); // Limpiar el buffer de entrada

  if (validarNumero(input))
  {
    printf("No se ingresó un número válido.\n");
    system("pause");
    return 1;
  }
  else
  {
    op = input[1];
  }
  return op;
}

// Función para manejar el menú
void menu()
{
  char op;
  int vector[TAM_VECTOR];
  int matriz[TAM_MATRIZ][TAM_MATRIZ];
  srand(time(NULL)); // Inicializar semilla para números aleatorios

  do
  {
    op = msges();
    switch (op)
    {
    case 1:
      llenarVector(vector, TAM_VECTOR);
      break;
    case 2:
      llenarMatriz(matriz);
      break;
    case 3:
      imprimirVector(vector, TAM_VECTOR);
      break;
    case 4:
      imprimirMatriz(matriz);
      break;
    case 5:
      ordenarVector(vector, TAM_VECTOR);
      break;
    case 6:
    {
      int valor;
      printf("Ingrese el valor a buscar en el vector: ");
      scanf("%d", &valor);
      buscarEnVector(vector, TAM_VECTOR, valor);
    }
    break;
    }
  } while (op != 0);
}

int validarNumero(char *input)
{
  int num = atoi(input);
  if (num == 0 && input[0] != '0')
  {
    return 1; // No se ingresó un número válido
  }
  return 0;
}
// Función para llenar un vector con números aleatorios entre 100 y 200
void llenarVector(int vector[], int tam)
{
  int i, j, aux;
  for (i = 0; i < tam; i++)
  {
    do
    {
      aux = rand() % 101 + 100; // Números entre 100 y 200
      for (j = 0; j < i; j++)
      {
        if (vector[j] == aux)
        {
          break;
        }
      }
    } while (j < i);
    vector[i] = aux;
  }
  system("pause");
}

// Función para llenar una matriz con números aleatorios entre 1 y 16
void llenarMatriz(int matriz[][TAM_MATRIZ])
{
  int i, j;
  for (i = 0; i < TAM_MATRIZ; i++)
  {
    for (j = 0; j < TAM_MATRIZ; j++)
    {
      matriz[i][j] = rand() % 16 + 1; // Números entre 1 y 16
    }
  }
  system("pause");
}

// Función para imprimir un vector
void imprimirVector(int vector[], int tam)
{
  int i;
  printf("Vector: ");
  for (i = 0; i < tam; i++)
  {
    printf("%d ", vector[i]);
  }
  printf("\n");
  system("pause");
}

// Función para imprimir una matriz
void imprimirMatriz(int matriz[][TAM_MATRIZ])
{
  int i, j;
  printf("Matriz:\n");
  for (i = 0; i < TAM_MATRIZ; i++)
  {
    for (j = 0; j < TAM_MATRIZ; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
  system("pause");
}

// Función para ordenar un vector usando el método de la Burbuja mejorada
void ordenarVector(int vector[], int tam)
{
  int i, j, temp;
  for (i = 0; i < tam - 1; i++)
  {
    for (j = 0; j < tam - i - 1; j++)
    {
      if (vector[j] > vector[j + 1])
      {
        temp = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = temp;
      }
    }
  }
  printf("Vector ordenado.\n");
  system("pause");
}

// Función para buscar un valor en un vector usando búsqueda secuencial
void buscarEnVector(int vector[], int tam, int valor)
{
  int i, encontrado = 0;
  for (i = 0; i < tam; i++)
  {
    if (vector[i] == valor)
    {
      printf("El valor %d se encuentra en la posición %d del vector.\n", valor, i);
      encontrado = 1;
      break;
    }
  }
  if (!encontrado)
  {
    printf("El valor %d no se encuentra en el vector.\n", valor);
  }
  system("pause");
}

// int main()
// {
//   char input[100];
//   printf("Ingrese un número: ");
//   scanf("%s", input);
//   if (validarNumero(input))
//   {
//     printf("No se ingresó un número válido.\n");
//   }
//   else
//   {
//     printf("Número válido ingresado: %s\n", input);
//   }
//   return 0;
// }
