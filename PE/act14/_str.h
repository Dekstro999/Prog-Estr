#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

//  LISTAS00
#define MAX_ALUMNOS 3500
#define AUTOMATICOS 1

#define MAX_NOMBRES 30
#define MAX_APELLIDOS 15


typedef int Tkey;

typedef struct _nom
{
    char nombre[50];
    char apPaterno[50];
    char apMaterno[50];
} Tname;


// estructura Alumno
typedef struct Alumno
{
    int status; // Estado del registro a;
    int matricula;
    Tkey key;
    Tname nombre;
    int edad;
    int sexo;
    char sexos[10];
    char est[3];
} Alumno;

typedef struct _indice
{
    Tkey key; // matricula
    int indice;

} Tindice;

// Listas de nombres masculinos y femeninos
char nombres[MAX_NOMBRES][50] = {
    // Nombres masculinos (15)
    "Juan", "Pedro", "Luis", "Carlos", "Diego", "Andres", "Javier", "Raul", "Pablo", "Santiago",
    "Alberto", "Julio", "Fernando", "Manuel", "Antonio",
    // Nombres femeninos
    "Mariana", "Ana", "Laura", "Sofia", "Elena", "Paula", "Carmen", "Sara", "Patricia", "Isabel",
    "Leticia", "Raquel", "Rosa", "Marta", "Natalia"};

char apellidos[MAX_APELLIDOS][50] = {"Gonzalez", "Rodriguez", "Martinez", "Lopez", "Perez", "Gomez",
                                     "Sanchez", "Diaz", "Torres", "Jimenez", "Fernandez", "Ramirez",
                                     "Ruiz", "Vazquez", "Serrano"};

short int orden;
short int cargado = FALSE;
int generados = 0;