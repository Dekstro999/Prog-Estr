#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

//  LISTAS

#define MAX_ALUMNOS 500
#define MAX_NOMBRES 30
#define MAX_APELLIDOS 15

// estructura Alumno
typedef struct Alumno
{
  int status; // Estado del registro a;
  int matricula;
  char apPaterno[50];
  char apMaterno[50];
  char nombre[50];
  char Secnombre[50];
  int edad;
  char sexo;
} Alumno;

// Listas de nombres masculinos y femeninos
char nombres[MAX_NOMBRES][50] = {
    // Nombres masculinos
    "Juan", "Pedro", "Luis", "Carlos", "Diego", "Andres", "Javier", "Raul", "Pablo", "Santiago",
    "Alberto", "Jose", "Fernando", "Manuel", "Antonio",
    // Nombres femeninos
    "Maria", "Ana", "Laura", "Sofia", "Elena", "Paula", "Carmen", "Sara", "Patricia", "Isabel",
    "Leticia", "Raquel", "Rosa", "Marta", "Natalia"};

char apellidos[MAX_APELLIDOS][50] = {"Gonzalez", "Rodriguez", "Martinez", "Lopez", "Perez", "Gomez",
                                     "Sanchez", "Diaz", "Torres", "Jimenez", "Fernandez", "Ramirez",
                                     "Ruiz", "Vazquez", "Serrano"};



