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
