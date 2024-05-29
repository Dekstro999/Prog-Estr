#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int vector[15];   // Declara el vector
int matriz[4][4]; // Declara la matriz

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
int validar_num();
void llenarVector(int vector[], int tam);
void llenarMatriz(int matriz[4][4]);
void imprimirVector(int vector[], int tam, const char *nombreVector);
void imprimirMatriz(int matriz[][4], int filas, const char *nombreMatriz);
void ordenarVector(int vector[], int tam);
void buscarEnVector(int vector[], int tam, int valor);

//  *** DESARROLLO DE LAS FUNCIONES  ******
int msges()
{
  int op;
  // system("CLS");
  printf("   M  E   N   U \n");
  printf("1.- LLENAR VECTOR \n");
  printf("2.- LLENAR MATRIZ \n");
  printf("3.- IMPRIMIR VECTOR \n");
  printf("4.- IMPRIMIR MATRIZ \n");
  printf("5.- ORDENAR VETOR \n");
  printf("6.- BUSCAR VALOR EN VECTOR \n");
  printf("0.- SALIR  \n");

  op = validar_num();

  return op;
}
//****************
void menu()
{
  int op;
  do
  {
    op = msges();
    switch (op)
    {
    case 1:
      llenarVector(vector, 15);         // 1
      break;
    case 2:
      llenarMatriz(matriz);             // 2
      break;
    case 3:
      imprimirVector(vector, 15, "1");  // 3
      break;
    case 4:
      imprimirMatriz(matriz, 4, "1");   // 4
      break;
    case 5:
      ordenarVector(vector, 15);        // 5
      break;
    case 6:
      int valor;
      printf("Valor a buscar: ");
      scanf("%d", &valor);
      buscarEnVector(vector, 15, valor); // 6
      break;
    }

  } while (op != 0);
}

int validar_num() //funcion para validar que se ingreso solo numeros 
{
  int num;

  printf("Ingrese una opcion: ");
  if (scanf("%d", &num) == 1)
  {
    // Limpiar el búfer del teclado
    while (getchar() != '\n')
      ;
    return num;
  }
  else
  {
    printf("Entrada no valida. Por favor, ingrese solo numeros.\n   \n");
    system("pause");
    // Limpiar el búfer del teclado
    while (getchar() != '\n')
      ;
  }
  return -1;
}

//*********************
void llenarVector(int vector[], int tam) // 1
{
  int numeros[101] = {0}; 
  int i, num;

  srand(time(NULL));

  for (i = 0; i < tam; ++i)
  {
    do
    {
      num = rand() % 101 + 100;
    } while (numeros[num - 100]); // Repetir si el número ya ha sido generado

    vector[i] = num;
    numeros[num - 100] = 1; // Marcar el número como generado
  }

  printf("Vector lleno con exito.\n\n");
  system("pause");
}
//*************************
void llenarMatriz(int matriz[4][4]) // 2
{
  srand(time(NULL));

  int numeros[16] = {0}; // Arreglo números generados

  // Llenar la matriz
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      int numAleatorio;
      do
      {
        numAleatorio = rand() % 16 + 1;
      } while (numeros[numAleatorio - 1]); // Verificar si se genero

      matriz[i][j] = numAleatorio;

      numeros[numAleatorio - 1] = 1; // Marcar como generado
    }
  }
  system("pause");
}
//****************************
void imprimirVector(int vector[], int tam, const char *nombreVector) // 3
{
  printf("Contenido del vector %s:\n", nombreVector);
  for (int i = 0; i < tam; ++i)
  {
    printf("%4d ", vector[i]);
  }
  printf("\n");
  system("PAUSE");
}

//****************************
void imprimirMatriz(int matriz[][4], int filas, const char *nombreMatriz) // 4
{
  printf("Contenido de la matriz %s:\n", nombreMatriz);
  for (int i = 0; i < filas; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      printf("%2d  ", matriz[i][j]);
    }
    printf("\n");
  }
  system("PAUSE");
}

//****************************
void ordenarVector(int vector[], int tam) // 5
{
  int i, j;
  int temp;
  for (i = 0; i < tam - 1; ++i)
  {
    for (j = 0; j < tam - i - 1; ++j)
    {
      if (vector[j] > vector[j + 1])
      {
        temp = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = temp;
      }
    }
  }

  printf("Vector ordenado correctamente.\n\n");
}

//****************************
void buscarEnVector(int vector[], int tam, int valor) // 6
{
  int i;
  int encontrado = 0;

  for (i = 0; i < tam; ++i)
  {
    if (vector[i] == valor)
    {
      printf("El valor %d se encuentra en la posicion [%d] del vector.\n\n", valor, i);
      encontrado = 1;
      break;
    }
  }

  if (!encontrado)
  {
    printf("El valor %d no se encuentra en el vector.\n\n", valor);
  }

  system("pause");
}

//****************************
