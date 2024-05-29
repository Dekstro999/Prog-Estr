
// Diego Alonso Ibarra Galindo
// Función en C
// Elaborado: 5/03/2024
// DAIG_ACT6_P1_03.cpp

#include <stdio.h>
#include <stdlib.h>
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Fibonacci(void);
void Factorial(void);
void Digitos(void);

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
  // system("CLS");
  printf("   M  E   N   U \n");
  printf("1.- FIBONACCI \n");
  printf("2.- FACTORIAL \n");
  printf("3.- DIGITOS \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf("%d", &op);
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
      Fibonacci();
      break;
    case 2:
      Factorial();
      break;
    case 3:
      Digitos();
      break;
    }
  } while (op != 0);
}

//*********************
void Fibonacci(void)
{
  int n, i = 1, t1 = 0, t2 = 1, siguiente;
  printf("Ingrese la cantidad de terminos de la serie de Fibonacci que desea mostrar: ");
  scanf("%d", &n);
  printf("Serie de Fibonacci:\n");
  do
  {
    printf("- %d\n", t1);
    siguiente = t1 + t2;
    t1 = t2;        // Actualiza t1
    t2 = siguiente; // Actualiza t2
    ++i;
  } while (i <= n);
  system("pause");
}
//*************************
void Factorial(void)
{
  int n, i, num;
  printf("Ingrese numero ");
  scanf("%d", &num);
  printf("Serie FACTORIAL:\n");
  n = num;
  i = n;
  do
  {
    printf("> %5d * %3d ", num, i - 1);
    num = num * (i - 1);
    printf(" = %5d \n", num);
    i--;
  } while (i > 2);
  system("pause");
}
//****************************
void Digitos(void)
{
  int num, cont = 0;
  // Solicitar al usuario que ingrese un número
  printf("Ingresa un numero: ");
  scanf("%d", &num);
  do
  {
    num /= 10;
    cont++;
  } while (num != 0);
  printf("El numero tiene %d digitos.\n", cont);
  system("PAUSE");
}


