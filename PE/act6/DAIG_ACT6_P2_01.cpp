// Diego Alonso Ibarra Galindo
// Función en C
// Elaborado: 8/03/2024  Modificado: 10/03/2024
// DAIG_ACT4_P2_01.cpp

#include <stdio.h>
#include <stdlib.h>
#include "curp.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void calificaciones(void);
void tabla_mult(void);
void suma_prom(void);
void prom_peso(void);
void prom_examen(void);

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
  printf("1.- Calificaciones \n");
  printf("2.- Tabla de multiplicar \n");
  printf("3.- Suma y promedio \n");
  printf("4.- Promedio de peso embarcacion\n");
  printf("5.- Promedio examen \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: \n> ");
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
      calificaciones();
      break;
    case 2:
      tabla_mult();
      break;
    case 3:
      suma_prom();
      break;
    case 4:
      prom_peso();
      break;
    case 5:
      prom_examen();
      break;
    }
  } while (op != 0);
}
//*********************
void calificaciones(void)
{
  int alumnosSinDerecho = 0;

  // Entrada de datos y cálculos
  for (int i = 0; i < 4; i++)
  {
    float calif1, calif2, calif3, calif4, calif5, promedio;
    printf("\nIngrese las calificaciones del alumno %d:\n", i + 1);
    printf("Calificacion de la unidad 1: ");
    scanf("%f", &calif1);
    printf("Calificacion de la unidad 2: ");
    scanf("%f", &calif2);
    printf("Calificacion de la unidad 3: ");
    scanf("%f", &calif3);
    printf("Calificacion de la unidad 4: ");
    scanf("%f", &calif4);
    printf("Calificacion de la unidad 5: ");
    scanf("%f", &calif5);

    promedio = (calif1 + calif2 + calif3 + calif4 + calif5) / 5;
    printf(">>Promedio del alumno %d: %2.2f \n", i + 1, promedio);

    if (promedio < 50)
    {
      alumnosSinDerecho++;
    }
  }
  printf("Cantidad de alumnos sin derecho al examen de nivelacion: %d\n\n", alumnosSinDerecho);
  system("pause");
}
//*************************
void tabla_mult(void)
{
  int n;
  printf("\nIntroduce un numero entero para mostrar su tabla de multiplicar: ");
  scanf("%d", &n);
  printf("Tabla del %d\n", n);
  for (int i = 1; i <= 10; i++)
  {
    printf("%d * %2d = %3d\n", n, i, n * i);
  }
  system("pause");
}
//****************************
void suma_prom(void)
{

  int n, minimo, maximo, i, cont = 0;
  float suma = 0;

  printf("Ingrese la cantidad de numeros que desea ingresar: ");
  scanf("%d", &n);

  printf("Ingrese el valor minimo del rango: ");
  scanf("%d", &minimo);
  printf("Ingrese el valor maximo del rango: ");
  scanf("%d", &maximo);

  printf("Ingrese los numeros:\n");
  for (i = 0; i < n; i++)
  {
    int numero;
    scanf("%d", &numero);
    if (numero >= minimo && numero <= maximo)
    {
      suma += numero;
      cont++;
    }
    else
    {
      printf("^^ Este numero no es valido\n");
    }
  }
  float media = suma / cont;
  printf("Suma de los numeros en el rango: %.2f\n", suma);
  printf("Media aritmetica de los numeros en el rango: %.2f\n", media);

  system("PAUSE");
}
//****************************
void prom_peso(void)
{
  int maxTuris = 10, maxPeso = 700 * 1.15, contTuris = 0, sobrepeso = 0;
  float pesoTuris, sumaPesos = 0;

  printf("Bienvenido a bordo de la embarcacion Finisterra.\n");
  do
  {
    printf("Ingrese el peso del turista %d (kg): ", contTuris + 1);
    scanf("%f", &pesoTuris);

    sumaPesos += pesoTuris;
    contTuris++;
    if (sumaPesos > (maxPeso)) // Verificar si se excede el límite de peso
    {
      sobrepeso = 1;
      break;
    }
  } while (contTuris < maxTuris);

  float promedioPeso = sumaPesos / contTuris;

  printf("\n--- Resultados ---\n");
  printf("Peso total: %.2f\n", sumaPesos);
  printf("Numero de turistas a bordo: %d\n", contTuris);
  printf("Promedio de peso de los turistas (kg): %.2f\n", promedioPeso);
  if (sobrepeso)
  {
    printf("La embarcacion no puede salir debido al sobrepeso.\n");
  }
  else
  {
    printf("La embarcacion puede salir a navegar.\n");
  }

  system("PAUSE");
}
//****************************
void prom_examen(void)
{
  int intento, i = 0;
  float parcial, promedio, total = 0;

  printf("Ingrese el numero del intento para cursar la asignatura (intento maximo: 3): ");
  scanf("%d", &intento);

  printf("Ingrese las notas de los tres examenes parciales:\n");

  do
  {
    printf("Ingrese la nota del examen parcial %d: ", i + 1);
    scanf("%f", &parcial);

    total += parcial;
    i++;
  } while (i < 3);

  promedio = total / 3;
  if (promedio < 60)
  {
    intento++;
  }
  // Determinar el estatus del alumno
  if (intento > 3)
  {
    printf("Lo sentimos, has reprobado la asignatura en tus tres intentos.\n Se te dara de baja academica.\n");
    printf("Promedio: %.2f\n", promedio);
  }
  else
  {
    if (promedio < 60)
    {
      printf("Tu promedio final es %.2f. Debes repetir la materia.\n", promedio);
      printf("Intentos restantes: %d.\n", 4 - intento);
    }
    else
    {
      printf("Has aprobado la asignatura con un promedio final de %.2f.\n", promedio);
    }
  }
  system("PAUSE");
}