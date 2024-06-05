#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

//  LISTAS

#define MAX_ALUMNOS 2000
#define AUTOMATICOS 100
#define MAX_NOMBRES 30
#define MAX_APELLIDOS 15

typedef struct _nom
{
  char nombre[50];
  char apPaterno[50];
  char apMaterno[50];
} Tname;

typedef struct _fecha
{
  int dia;
  int mes;
  int anio;
} Tfecha;
// estructura Alumno
typedef struct Alumno
{
  int status; // Estado del registro a;
  int matricula;
  Tname nombre;
  char Secnombre[50];
  Tfecha fecha;
  int edad;
  int sexo;
  char est[3];
  char curp[19];
} Alumno;

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
