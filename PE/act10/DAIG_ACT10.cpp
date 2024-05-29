// Diego Alonso Ibarra Galindo
// ESTRUCTURAS CON LOS DATOS BÁSICOS DE UN ALUMNO
// Elaborado: 10/04/2024  Modificado: 15/04/2024
// DAIG_ACT10.cpp

#include "_curp.h"

// Prototipos de funciones
int menu();
void opciones();
void agregarAutomatico(Alumno alumnos[], int *numAlumnos);
void agregarManual(Alumno alumnos[], int *numAlumnos);
void eliminarRegistro(Alumno alumnos[], int *numAlumnos);
void buscar(Alumno alumnos[], int numAlumnos);
int buscarSecuencial(Alumno alumnos[], int numAlumnos, int matricula);
int buscarBinaria(Alumno alumnos[], int numAlumnos, int matricula);
void ordenarPorMatricula(Alumno alumnos[], int numAlumnos);
void ordenarBurbuja(Alumno alumnos[], int numAlumnos);
void imprimir(Alumno alumnos[], int numAlumnos);
void guardarRegistrosDAT(Alumno alumnos[], int numAlumnos);
void cargarRegistrosDAT(Alumno alumnos[], int *numAlumnos);
void guardarRegistros(Alumno alumnos[], int numAlumnos);
void imprimirRegistrosDAT(Alumno alumnos[], int numAlumnos);

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
  // cls();
  printf("        MENU\n");
  printf("1.- AGREGAR (AUTOM 10 REGISTROS)\n");
  printf("2.- AGREGAR MANUAL\n");
  printf("3.- ELIMINAR REGISTRO (logico)\n");
  printf("4.- BUSCAR\n");
  printf("5.- ORDENAR\n");
  printf("6.- IMPRIMIR\n");
  printf("0.- SALIR\n");
  printf("ESCOGE UNA OPCION: ");
  opcion = validar_num();

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
      guardarRegistros(alumnos, numAlumnos);

      break;
    case 2:
      agregarManual(alumnos, &numAlumnos);
      guardarRegistros(alumnos, numAlumnos);

      break;
    case 3:
      imprimir(alumnos, numAlumnos);
      eliminarRegistro(alumnos, &numAlumnos);
      break;
    case 4:
      buscar(alumnos, numAlumnos);
      break;
    case 5:
      ordenarPorMatricula(alumnos, numAlumnos);
      break;
    case 6:
      imprimir(alumnos, numAlumnos);
      pause();

      break;
    case 0:
      printf("Saliendo del programa... ");
      anima(5);
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

  if (*numAlumnos + 10 > MAX_ALUMNOS)
  {
    TextColor(ROJO);
    printf("No se pueden agregar 10 alumnos mas. El limite es de %d.\n", MAX_ALUMNOS);
    TextColor(DEF);
    pause();
    return;
  }

  srand(time(NULL));

  for (int i = 0; i < 10; i++)
  {
    alumnos[*numAlumnos + i].status = 1; // Activo

    int matricula = randomR(300000, 400000);
    alumnos[*numAlumnos + i].matricula = matricula;

    int indApellPat = random(MAX_APELLIDOS);
    int indApellMat = random(MAX_APELLIDOS);
    int indiceNombre = random(MAX_NOMBRES);

    snprintf(alumnos[*numAlumnos + i].nombre, sizeof(alumnos[*numAlumnos + i].nombre), "%s",
             nombres[indiceNombre]);
    snprintf(alumnos[*numAlumnos + i].apPaterno, sizeof(alumnos[*numAlumnos + i].apPaterno), "%s",
             apellidos[indApellPat]);
    snprintf(alumnos[*numAlumnos + i].apMaterno, sizeof(alumnos[*numAlumnos + i].apMaterno), "%s",
             apellidos[indApellMat]);

    int edad = randomR(17, 90);
    alumnos[*numAlumnos + i].edad = edad;

    if (indiceNombre < 15)
    {
      alumnos[*numAlumnos + i].sexo = 'M';
    }
    else
    {
      alumnos[*numAlumnos + i].sexo = 'F';
    }
  }

  *numAlumnos += 10;
  orden = 0;
  printf("Se agregaron 10 registros automaticos correctamente.\n");
  pause();
}

//*************************
void agregarManual(Alumno alumnos[], int *numAlumnos)
{
  TextColor(DEF);

  // cls(); // Verificar si hay espacio disponible para agregar más alumnos
  if (*numAlumnos >= MAX_ALUMNOS)
  {
    TextColor(ROJO);
    printf("No se pueden agregar más alumnos. El limite es de %d.\n", MAX_ALUMNOS);
    TextColor(DEF);
    pause();
    return;
  }

  printf("Ingrese los datos del nuevo alumno:\n");

  do
  {
    printf("Matricula: ");
    alumnos[*numAlumnos].matricula = validarMatricula();
    if (alumnos[*numAlumnos].matricula == -1)
      continue; // Repetir si no es válido

  } while (alumnos[*numAlumnos].matricula == -1);

  char paterno[40];

  do
  {
    printf("Apellido Paterno: ");
    fgets(paterno, sizeof(paterno), stdin);
    convertirMayusculas(paterno);

  } while (!validar_letras(paterno));
  enter(paterno, alumnos, numAlumnos, "apPaterno");

  char materno[40];
  do
  {
    printf("Apellido Materno: ");
    fgets(materno, sizeof(materno), stdin);
    convertirMayusculas(materno);

  } while (!validar_letras(materno));
  enter(materno, alumnos, numAlumnos, "apMaterno");

  char nombre[40];
  do
  {
    printf("Nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    convertirMayusculas(nombre);

  } while (!validar_letras(nombre));

  enter(nombre, alumnos, numAlumnos, "nombre");
  do
  {
    printf("Edad: ");
    alumnos[*numAlumnos].edad = validar_num();
    if (alumnos[*numAlumnos].edad != -1 && (1 > alumnos[*numAlumnos].edad ||
                                            alumnos[*numAlumnos].edad > 80))
    {
      printf("Entre 1- 80 \n");
      pause();
      borrarlinea(3);
      alumnos[*numAlumnos].edad = -1;
    }

  } while (alumnos[*numAlumnos].edad == -1);

  alumnos[*numAlumnos].sexo = elegirSexo();

  alumnos[*numAlumnos].status = 1; // Marcar el registro como activo
  // Incrementar el contador de alumnos
  (*numAlumnos)++;

  printf("Registro agregado correctamente.\n");
  orden = 0;
  pause();
}

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
    // Marcar el registro como inactivo
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
      if (alumnos[indice].status != 1) // Verificar si el registro esta activo
      {
        TextColor(ROJO);
        printf("****  La matricula %d esta inactiva.\n", matricula);
        TextColor(DEF);
      }
      printf("La matricula %d fue encontrada en la posicion %d.\n", matricula, indice + 1);
      printf("================================================================================================================\n");
      printf("| No.\t| Matricula\t| Apellido Paterno\t| Apellido Materno\t| Nombre\t\t| Edad\t| Sexo |\n");
      printf("================================================================================================================\n");
      printf("| %-3d\t| %-7d\t| %-15s\t| %-15s\t| %-15s\t| %-3d\t| %-2c   |\n",
             indice + 1, alumnos[indice].matricula, alumnos[indice].apPaterno, alumnos[indice].apMaterno,
             alumnos[indice].nombre, alumnos[indice].edad, alumnos[indice].sexo);
      printf("================================================================================================================\n");
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
      return i; // Se encontró la matricula en la posición i
    }
  }
  return -1; // No se encontró la matricula
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

  int opcion;
  do
  {
    cls();
    printf("\nMetodos de Ordenacion:\n");
    printf("1. Burbuja\n");
    printf("2. Otro Metodo (a implementar)\n");
    printf("0. Volver al menu principal\n");
    printf("Seleccione un metodo de ordenacion: ");
    opcion = validar_num();
    if (opcion < 0 || opcion > 2)
    {
      TextColor(ROJO);
      printf("Opcion no valida.\n");
      TextColor(DEF);
      pause();
    }
  } while (opcion < 0 || opcion > 2);

  switch (opcion)
  {
  case 0:
    printf("\nVolviendo al menu principal...\n");
    pause();
    break;
  case 1:
    ordenarBurbuja(alumnos, numAlumnos);
    break;
  case 2:
    printf("\nPROXIMOS.\n");
    pause();
    break;
  }
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
  printf("LISTA DE ALUMNOS\n");
  printf("================================================================================================================\n");
  printf("| No.\t| Matricula\t| Apellido Paterno\t| Apellido Materno\t| Nombre\t\t| Edad\t| Sexo |\n");
  printf("================================================================================================================\n");

  for (int i = 0; i < numAlumnos; i++)
  {
    if (alumnos[i].status == 1) //  si el registro esta activo
    {
      printf("| %-3d\t| %-7d\t| %-15s\t| %-15s\t| %-15s\t| %-3d\t| %-2c   |\n",
             i + 1, alumnos[i].matricula, alumnos[i].apPaterno, alumnos[i].apMaterno,
             alumnos[i].nombre, alumnos[i].edad, alumnos[i].sexo);
    }
  }
  printf("================================================================================================================\n");
  printf("| Total de alumnos: %-80d\t\t\b|\n", numAlumnos);
  printf("================================================================================================================\n\n");
  //imprimirRegistrosDAT(alumnos, numAlumnos);
}

void guardarRegistrosDAT(Alumno alumnos[], int numAlumnos)
{
  FILE *archivo;
  archivo = fopen("registros.dat", "ab+");
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo.\n");
    pause();
    return;
  }

  Alumno alumnoExistente;
  while (fread(&alumnoExistente, sizeof(Alumno), 1, archivo) == 1)
  {
    // por si quisiera mostrar lo guardado
  }

  // Escribir el nuevo al final del anterior
  fwrite(alumnos, sizeof(Alumno), numAlumnos, archivo);

  fclose(archivo);
}

void guardarRegistros(Alumno alumnos[], int numAlumnos)
{
  guardarRegistrosDAT(alumnos, numAlumnos);
}
 
void imprimirRegistrosDAT(Alumno alumnos[], int numAlumnos)
{
  FILE *archivo;
  archivo = fopen("registros.dat", "rb");
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo.\n");
    return;
  }

  printf("LISTA DE ALUMNOS (desde archivo DAT)\n");
  printf("================================================================================================================\n");
  printf("| No.\t| Matricula\t| Apellido Paterno\t| Apellido Materno\t| Nombre\t\t| Edad\t| Sexo |\n");
  printf("================================================================================================================\n");

  int contador = 0;
  Alumno alumno;

  while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1)
  {
    printf("| %-3d\t| %-7d\t| %-15s\t| %-15s\t| %-15s\t| %-3d\t| %-2c   |\n",
           contador + 1, alumno.matricula, alumno.apPaterno, alumno.apMaterno, alumno.nombre, alumno.edad, alumno.sexo);
    contador++;
  }

  printf("================================================================================================================\n");
  printf("| Total de alumnos: %-80d\t\t\b|\n", contador);
  printf("================================================================================================================\n\n");

  fclose(archivo);
}