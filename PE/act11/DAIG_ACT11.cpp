// Diego Alonso Ibarra Galindo
// Programa con menú para cargar, agregar, buscar, ordenar, mostrar y generar archivos de registros
// Elaborado: 1/05/2024  Modificado: 5/05/2024
// DAIG_ACT11.cpp
#include "_curp.h"

// Prototipos de funciones
int menu();
void opciones();
void agregarAutomatico(Alumno alumnos[], int *numAlumnos);
void eliminarRegistro(Alumno alumnos[], int *numAlumnos);
void buscar(Alumno alumnos[], int numAlumnos);
int buscarSecuencial(Alumno alumnos[], int numAlumnos, int matricula);
int buscarBinaria(Alumno alumnos[], int numAlumnos, int matricula);
void ordenarPorMatricula(Alumno alumnos[], int numAlumnos);
void ordenarBurbuja(Alumno alumnos[], int numAlumnos);
void imprimir(Alumno alumnos[], int numAlumnos);
void imprimir_pagina(Alumno alumnos[], int numAlumnos, int pagina_actual);
void guardarEnArchivoTXT(Alumno alumnos[], int numAlumnos);



short int orden;

//****  main principal  *********
int main()
{
  opciones();

  return 0;
}
//  * * * * * * DESARROLLO DE LAS FUNCIONES  * * * * * *

int menu()
{
  TextColor(DEF);
  int opcion;
  cls();
  printf("\tMENU\n");
  printf("1.- AGREGAR (AUTOM %d REGISTROS)\n", AUTOMATICOS);
  printf("2.- ELIMINAR REGISTRO (logico)\n");
  printf("3.- BUSCAR\n");
  printf("4.- ORDENAR\n");
  printf("5.- IMPRIMIR\n");
  printf("6.- ARCHIVO TXT\n");
  printf("0.- SALIR\n");
  printf("ESCOGE UNA OPCION: ");
  opcion = validar_num(0, 6);

  return opcion;
}

//****************
void opciones()
{
  TextColor(DEF);

  Alumno alumnos[MAX_ALUMNOS];
  int numAlumnos = 0;

  int opcion;
  do
  {
    do
    {
      opcion = menu();

    } while (opcion == -1);
    switch (opcion)
    {
    case 1:
      agregarAutomatico(alumnos, &numAlumnos);

      break;
    case 2:
      imprimir(alumnos, numAlumnos);
      eliminarRegistro(alumnos, &numAlumnos);
      break;
    case 3:
      buscar(alumnos, numAlumnos);
      break;
    case 4:
      ordenarPorMatricula(alumnos, numAlumnos);
      break;
    case 5:
      imprimir(alumnos, numAlumnos);
      pause();

      break;
    case 6:
      guardarEnArchivoTXT(alumnos, numAlumnos);
      pause();

      break;
    case 0:
      printf("Saliendo del programa... ");
      anima(2);
      break;
    default:
      TextColor(ROJO);
      printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
      TextColor(DEF);

      pause();
    }
  } while (opcion != 0);
}

//*********************
void agregarAutomatico(Alumno alumnos[], int *numAlumnos)
{
  TextColor(DEF);

  if (*numAlumnos + AUTOMATICOS > MAX_ALUMNOS)
  {
    TextColor(ROJO);
    printf("No se pueden agregar 10 alumnos mas. El limite es de %d.\n", MAX_ALUMNOS);
    TextColor(DEF);
    pause();
    return;
  }

  srand(time(NULL));

  for (int i = 0; i < AUTOMATICOS; i++)
  {
    alumnos[*numAlumnos + i].status = 1; // Activo

    int matricula = randomR(300000, 400000);
    alumnos[*numAlumnos + i].matricula = matricula;

    int indApellPat = random(MAX_APELLIDOS);
    int indApellMat = random(MAX_APELLIDOS);
    int indiceNombre = random(MAX_NOMBRES);

    snprintf(alumnos[*numAlumnos + i].nombre.nombre, sizeof(alumnos[*numAlumnos + i].nombre.nombre), "%s",
             nombres[indiceNombre]);
    snprintf(alumnos[*numAlumnos + i].nombre.apPaterno, sizeof(alumnos[*numAlumnos + i].nombre.apPaterno), "%s",
             apellidos[indApellPat]);
    snprintf(alumnos[*numAlumnos + i].nombre.apMaterno, sizeof(alumnos[*numAlumnos + i].nombre.apMaterno), "%s",
             apellidos[indApellMat]);

    int anioAleatorio, mesAleatorio, diaAleatorio;
    generarFechaAleatoria(&anioAleatorio, &mesAleatorio, &diaAleatorio);

    alumnos[*numAlumnos + i].fecha.anio = anioAleatorio;
    alumnos[*numAlumnos + i].fecha.mes = mesAleatorio;
    alumnos[*numAlumnos + i].fecha.dia = diaAleatorio;

    alumnos[*numAlumnos + i].edad = calcularEdad(anioAleatorio, mesAleatorio, diaAleatorio);

    if (indiceNombre < 15)
    {
      alumnos[*numAlumnos + i].sexo = 1;
    }
    else
    {
      alumnos[*numAlumnos + i].sexo = 2;
    }
    asignarEstadoAleatorio(&alumnos[*numAlumnos + i]);

    generarCURP(alumnos[*numAlumnos + i].curp, alumnos[*numAlumnos + i].nombre.apPaterno,
                alumnos[*numAlumnos + i].nombre.apMaterno, alumnos[*numAlumnos + i].nombre.nombre,
                anioAleatorio, mesAleatorio, diaAleatorio, alumnos[*numAlumnos + i].sexo, alumnos[*numAlumnos + i].est);
  }

  *numAlumnos += AUTOMATICOS;
  orden = 0;
  printf("Se agregaron %d registros automaticos correctamente.\n", AUTOMATICOS);
  pause();
}

//*************************

//****************************
void eliminarRegistro(Alumno alumnos[], int *numAlumnos)
{
  TextColor(DEF);

  printf("\nELIMINAR REGISTRO\n");

  int matricula;
  printf("Ingrese la matricula del alumno a eliminar: ");
  matricula = validarMatricula();

  int indice;
  if (orden == 0)
  {
    indice = buscarSecuencial(alumnos, *numAlumnos, matricula);
  }
  else
  {
    indice = buscarBinaria(alumnos, *numAlumnos, matricula);
  }

  if (indice != -1)
  {
    alumnos[indice].status = 0;
    printf("El alumno con matricula %d ha sido eliminado correctamente.\n", matricula);
  }
  else
  {
    TextColor(ROJO);
    printf("No se encontró ningún alumno con la matricula %d.\n", matricula);
    TextColor(DEF);
  }

  pause();
}

void buscar(Alumno alumnos[], int numAlumnos)
{
  TextColor(DEF);

  int matricula;
  char resp;
  do
  {
    // cls();
    do
    {
      printf("\nIngrese la matricula a buscar: ");
      matricula = validarMatricula();
      if (matricula == -1)
        borrarlinea(1);
    } while (matricula == -1);

    int indice;
    if (orden == 0)
    {
      indice = buscarSecuencial(alumnos, numAlumnos, matricula);
    }
    else
    {
      indice = buscarBinaria(alumnos, numAlumnos, matricula);
    }

    if (indice != -1)
    {
      if (alumnos[indice].status != 1)
      {
        TextColor(ROJO);
        printf("****  La matricula %d esta inactiva.\n", matricula);
        TextColor(DEF);
      }
      printf("La matricula %d fue encontrada en la posicion %d.\n", matricula, indice + 1);
      printf("=================================================================================================================================\n");
      printf("| No.\t| Matricula | Apellido Paterno | Apellido Materno | Nombre\t\t| Fecha      | Edad | Sexo | CURP\t\t|\n");
      printf("=================================================================================================================================\n");
      char sexo;
      if (alumnos[indice].sexo == 1)
      {
        sexo = 'H'; // H para hombre
      }
      else
      {
        if (alumnos[indice].sexo == 2)
        {
          sexo = 'M'; // M para mujer
        }
      }
      printf("| %4d\t| %-9d | %-16s | %-16s | %-17s\t| %02d/%02d/%4d | %-3d  | %-2c   | %-18s |\n",
             indice + 1, alumnos[indice].matricula, alumnos[indice].nombre.apPaterno, alumnos[indice].nombre.apMaterno,
             alumnos[indice].nombre.nombre, alumnos[indice].fecha.dia, alumnos[indice].fecha.mes, alumnos[indice].fecha.anio,
             alumnos[indice].edad, sexo, alumnos[indice].curp);
      printf("=================================================================================================================================\n");
    }
    else
    {
      TextColor(ROJO);
      printf("La matricula %d no fue encontrada en la lista.\n", matricula);
      TextColor(DEF);
    }

    printf("\n Desea buscar otro registro? (s/n): ");
    scanf(" %c", &resp);
    while ((getchar()) != '\n')
      ; // Limpiar el buffer de entrada
    convertirMayusculas(&resp);

  } while (resp == 'S');
}

int buscarSecuencial(Alumno alumnos[], int numAlumnos, int matricula)
{
  printf("\nSECUENCIAL\n");

  for (int i = 0; i < numAlumnos; i++)
  {
    if (alumnos[i].matricula == matricula)
    {
      return i;
    }
  }
  return -1;
}

int buscarBinaria(Alumno alumnos[], int numAlumnos, int matricula)
{
  printf("\nBINARIA\n ");

  int izq = 0;
  int der = numAlumnos - 1;

  while (izq <= der)
  {
    int medio = izq + (der - izq) / 2;

    if (alumnos[medio].matricula == matricula)
    {
      return medio; // Se encontró la matricula en la posición medio
    }

    if (alumnos[medio].matricula < matricula)
    {
      izq = medio + 1; // Buscar en la mitad der
    }
    else
    {
      der = medio - 1; // Buscar en la mitad izq
    }
  }

  return -1; // No se encontr
}

void ordenarPorMatricula(Alumno alumnos[], int numAlumnos)
{
  TextColor(DEF);
  ordenarBurbuja(alumnos, numAlumnos);
}

void ordenarBurbuja(Alumno alumnos[], int numAlumnos)
{
  if (orden != 1)
  {
    for (int i = 0; i < numAlumnos - 1; i++)
    {
      for (int j = 0; j < numAlumnos - i - 1; j++)
      {
        if (alumnos[j].matricula > alumnos[j + 1].matricula)
        {
          Alumno temp = alumnos[j];
          alumnos[j] = alumnos[j + 1];
          alumnos[j + 1] = temp;
        }
      }
    }
    printf("\nAlumnos ordenados.\n");
    orden = 1;
    pause();
  }
  else
  {
    printf("\nLISTA YA ORDENADA.\n");
    pause();
  }
}

void imprimir(Alumno alumnos[], int numAlumnos)
{
  // cls();
  int pagina_actual = 1;
  char opcion;

  do
  {
    imprimir_pagina(alumnos, numAlumnos, pagina_actual);
    printf("Desea continuar? [S] o [N] ");
    scanf(" %c", &opcion);
    if (opcion == 'S' || opcion == 's')
    {
      pagina_actual++;
    }
  } while (opcion == 'S' || opcion == 's');
  // imprimirRegistrosDAT();
}

void imprimir_pagina(Alumno alumnos[], int numAlumnos, int pagina_actual)
{
  int num_registros_pagina = 40;
  int inicio = (pagina_actual - 1) * num_registros_pagina;
  int fin = inicio + num_registros_pagina;
  printf("- - - LISTA DE ALUMNOS - - -\n");
  printf("=================================================================================================================================\n");
  printf("| No.\t| Matricula | Apellido Paterno | Apellido Materno | Nombre\t\t| Fecha      | Edad | Sexo | CURP\t\t|\n");
  printf("=================================================================================================================================\n");

  for (int i = inicio; i < fin && i < numAlumnos; i++)
  {
    if (alumnos[i].status == 1)
    {
      char sexo;
      if (alumnos[i].sexo == 1)
      {
        sexo = 'H'; // H para hombre
      }
      else
      {
        if (alumnos[i].sexo == 2)
        {
          sexo = 'M'; // M para mujer
        }
      }
      printf("| %4d\t| %-9d | %-16s | %-16s | %-17s\t| %02d/%02d/%4d | %-3d  | %-2c   | %-18s |\n",
             i + 1, alumnos[i].matricula, alumnos[i].nombre.apPaterno, alumnos[i].nombre.apMaterno,
             alumnos[i].nombre.nombre, alumnos[i].fecha.dia, alumnos[i].fecha.mes, alumnos[i].fecha.anio, alumnos[i].edad, sexo, alumnos[i].curp);
    }
  }
  printf("=================================================================================================================================\n");
  printf("| Pagina actual: %-4d\t| Total de alumnos: %-70d\t\t|\n", pagina_actual, numAlumnos);
  printf("=================================================================================================================================\n");
}

void guardarEnArchivoTXT(Alumno alumnos[], int numAlumnos)
{
  FILE *archivo;
  archivo = fopen("BASURITA.txt", "w"); // Abrir el archivo en modo de escritura

  if (archivo == NULL)
  {
    printf("Error al abrir el archivo.");
    return;
  }
  fprintf(archivo, "LISTA DE ALUMNOS\n");
  fprintf(archivo, "=================================================================================================================================\n");
  fprintf(archivo, "| No.\t| Matricula | Apellido Paterno | Apellido Materno | Nombre\t\t\t\t| Fecha      | Edad | Sexo | CURP\t\t\t\t|\n");
  fprintf(archivo, "=================================================================================================================================\n");

  for (int i = 0; i < numAlumnos; i++)
  {
    if (alumnos[i].status == 1)
    {
      char sexo;
      if (alumnos[i].sexo == 1)
      {
        sexo = 'H'; // H para hombre
      }
      else
      {
        sexo = 'M'; // M para mujer
      }
      fprintf(archivo, "| %4d\t| %-9d | %-16s | %-16s | %-17s\t| %02d/%02d/%4d | %-3d  | %-2c   | %-18s |\n",
              i + 1, alumnos[i].matricula, alumnos[i].nombre.apPaterno, alumnos[i].nombre.apMaterno,
              alumnos[i].nombre.nombre, alumnos[i].fecha.dia, alumnos[i].fecha.mes, alumnos[i].fecha.anio, alumnos[i].edad, sexo, alumnos[i].curp);
    }
  }
  fprintf(archivo, "=================================================================================================================================\n");
  fprintf(archivo, "| Total de alumnos: %-80d\t\t\t\t\t        |\n", numAlumnos);
  fprintf(archivo, "=================================================================================================================================\n\n");

  fclose(archivo); // Cerrar el archivo
}
