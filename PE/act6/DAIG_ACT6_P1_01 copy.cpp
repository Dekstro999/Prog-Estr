// Diego Alonso Ibarra Galindo
// Función en C
// Elaborado: 5/03/2024  Modificado: 10/03/2024
// DAIG_ACT6_P1_01.cpp

#include <stdio.h>
#include <stdlib.h>
#include "curp.h"
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
int Fibonacci(int n);
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
  system("CLS");
  printf("   M  E   N   U \n");
  printf("1.- FIBONACCI \n");
  printf("2.- FACTORIAL \n");
  printf("3.- DIGITOS \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
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
      int num;
      printf("Ingrese numero ");
      scanf("%d", &num);
      for (int i = 0; i < num; i++)
      {
        printf("%d\n", Fibonacci(i));
      }
      system("pause");
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
int Fibonacci(int n)
{
  if (n < 2)
  {
    return n;
  }
  else
  {
    return Fibonacci(n - 1) + Fibonacci(n - 2);
  }
}
//*************************
void Factorial(void)
{
  int n, i;
  long int num;
  printf("Ingrese numero ");
  scanf("%li", &num);
  printf("Serie FACTORIAL:\n");
  n = num;
  for (i = n; i > 2; i--)
  {
    printf("> %15ld * %-5d ", num, i - 1);
    num = num * (i - 1);
    printf(" = %-15ld \n", num);
  }
  printf("\n  Factorial de %2d = %5ld  \n", n, num);

  system("pause");
}
//****************************
void Digitos(void)
{
  int num, cont;
  printf("Ingresa un numero: ");
  scanf("%d", &num);
  for (cont = 0; num != 0; cont++)
  {
    num /= 10;
  }
  printf("El numero tiene %d digitos.\n", cont);
  system("PAUSE");
}
