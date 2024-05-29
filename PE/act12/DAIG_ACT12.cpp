// Diego Alonso Ibarra Galindo
// Programa con menú para cargar, agregar, buscar, ordenar, mostrar y generar archivos de registros
// Elaborado: 1/05/2024  Modificado: 5/05/2024
// DAIG_ACT12.cpp
#include "_curp.h"

// Prototipos de funciones
int menu();
void opciones();
void cargarArchivo(Alumno cargAlum[], int *numAlumnos);
void mostrarTodo(Alumno cargAlum[], int *numAlumnos);
void agregarAutomatico(Alumno alumnos[], int *numAlumnos);
void agregarManual(Alumno alumnos[], int *numAlumnos);
void eliminarRegistro(Alumno alumnos[], int *numAlumnos);
void buscar(Alumno alumnos[], int numAlumnos);
int buscarSecuencial(Alumno alumnos[], int numAlumnos, int matricula);
int buscarBinaria(Alumno alumnos[], int numAlumnos, int matricula);
void ordenarPorMatricula(Alumno alumnos[], int numAlumnos);
void ordenarBurbuja(Alumno alumnos[], int numAlumnos);
void intercambiar(Alumno *a, Alumno *b);
int separar(Alumno alumnos[], int inicio, int fin);
void quickSort(Alumno alumnos[], int inicio, int fin);
void ordenarQuickSort(Alumno alumnos[], int numAlumnos);
void imprimir(Alumno alumnos[], int numAlumnos);
void imprimir_pagina(Alumno alumnos[], int numAlumnos, int pagina_actual);
void guardarEnArchivoTXT(Alumno alumnos[], int numAlumnos);
void generarArchivo(Alumno alumnos[], int numAlumnos);
void guardarRegistrosDAT(Alumno alumnos[], int numAlumnos);
void guardarRegistros(Alumno alumnos[], int numAlumnos);
void imprimirRegistrosDAT();

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
    printf("1.- CARGAR ARCHIVO\n");
    printf("2.- AGREGAR (%d)\n", AUTOMATICOS);
    printf("3.- ELIMINAR REGISTRO (logico)\n");
    printf("4.- BUSCAR\n");
    printf("5.- ORDENAR\n");
    printf("6.- MOSTRAR TODO\n");
    printf("7.- GENERAR ARCHIVO TXT\n");
    printf("0.- SALIR\n");
    printf("ESCOGE UNA OPCION: ");
    opcion = validar_num(0, 7);

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
        case 1: // cargar
            cargarArchivo(alumnos, &numAlumnos);
            // agregarAutomatico(alumnos, &numAlumnos);
            // guardarRegistros(alumnos, numAlumnos);
            break;
        case 2: // agregar
            agregarAutomatico(alumnos, &numAlumnos);
            guardarEnArchivoTXT(alumnos, numAlumnos);
            break;
        case 3: // eliminar
            // imprimir(alumnos, numAlumnos);
            eliminarRegistro(alumnos, &numAlumnos);
            break;
        case 4: // buscar
            buscar(alumnos, numAlumnos);
            break;
        case 5:
            ordenarPorMatricula(alumnos, numAlumnos);
            break;
        case 6:
            // imprimir(alumnos, numAlumnos);
            mostrarTodo(alumnos, &numAlumnos);
            pause();
            break;
        case 7:
        generarArchivo(alumnos, numAlumnos);
            pause();
            break;
        case 0:
            printf("Saliendo del programa... ");
            anima(1);
            break;
        default:
            error("OPCION NO VALIDA");
        }
    } while (opcion != 0);
}

//*********************
void cargarArchivo(Alumno cargAlum[], int *numAlumnos)
{
    if (c)
    {
        error("ARCHIVO YA CARGADO");
    }
    else
    {
        FILE *archivo;
        archivo = fopen("datos.txt", "r"); //  lectura
        Alumno tempAlumno;
        if (archivo == NULL)
        {
            error("ERROR AL ABRIR EL ARCHIVO");

            return;
        }
        printf("cargado\n");
        pause();
        char id[10];
        while (!feof(archivo))
        {
            fscanf(archivo, "%s %d %s %s %s %d %s",
                   id, &tempAlumno.matricula, tempAlumno.nombre.nombre, tempAlumno.nombre.apPaterno,
                   tempAlumno.nombre.apMaterno, &tempAlumno.edad, tempAlumno.sexos);

            tempAlumno.status = 1;
            cargAlum[(*numAlumnos)++] = tempAlumno;
        }
        fclose(archivo); // Cerrar el archivo
    }
    c = TRUE;
}
//*********************
void mostrarTodo(Alumno cargAlum[], int *numAlumnos)
{
    int op;
    int contador = 0;

    do
    {
        cls();
        int i = 0;
        while (contador < *numAlumnos)
        {
            if (i < 40)
            {
                if (cargAlum[contador].status == 1)
                {
                    printf("| %4d\t| %-9d | %-16s | %-16s | %-17s\t|  %-3d  | %-10s |\n",
                           contador, cargAlum[contador].matricula, cargAlum[contador].nombre.nombre, cargAlum[contador].nombre.apPaterno,
                           cargAlum[contador].nombre.apMaterno, cargAlum[contador].edad, cargAlum[contador].sexos);
                    i++;
                }
                contador++;
            }
            else
            {
                break;
            }
        }
        printf("\n1. Para ver mas registros\n");
        printf("2. Para terminar\n");
        printf("Seleccione: ");
        op = validar_num(1, 2);
    } while (op == 1);
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



        alumnos[*numAlumnos + i].edad = calcularEdad(anioAleatorio, mesAleatorio, diaAleatorio);

        if (indiceNombre < 15)
        {
            strcpy(alumnos[*numAlumnos + i].sexos, "MASCULINO");
            // alumnos[*numAlumnos + i].sexos = "hombre";
        }
        else
        {
            strcpy(alumnos[*numAlumnos + i].sexos, "FEMENINO");

            // alumnos[*numAlumnos + i].sexos = 'mujer';
        }
        // asignarEstadoAleatorio(&alumnos[*numAlumnos + i]);

        // printf("\n%d\n", alumnos[*numAlumnos + i].matricula); //mensaje de depuracion
        // printf("%s\n", alumnos[*numAlumnos + i].nombre.nombre); //mensaje de depuracion
        // printf("%s\n", alumnos[*numAlumnos + i].nombre.apPaterno);  //mensaje de depuracion
        // printf("%s\n", alumnos[*numAlumnos + i].nombre.apMaterno);  //mensaje de depuracion
        // printf("%d\n", alumnos[*numAlumnos + i].sexo);  //mensaje de depuracion
        // printf("                 curp\n");

        // generarCURP(alumnos[*numAlumnos + i].curp, alumnos[*numAlumnos + i].nombre.apPaterno,
        //             alumnos[*numAlumnos + i].nombre.apMaterno, alumnos[*numAlumnos + i].nombre.nombre,
        //            anioAleatorio, mesAleatorio, diaAleatorio, alumnos[*numAlumnos + i].sexo, alumnos[*numAlumnos + i].est);

        // printf("%s\n", alumnos[*numAlumnos + i].curp); //mensaje de depuracion
    }

    *numAlumnos += AUTOMATICOS;
    generados += AUTOMATICOS;
    orden = 0;
    c = TRUE;
    printf("Se agregaron %d registros automaticos correctamente.\n", AUTOMATICOS);
    pause();
}

//*************************
void agregarManual(Alumno alumnos[], int *numAlumnos)
{
    TextColor(DEF);

    // cls(); // Verificar si hay espacio disponible para agregar mas alumnos
    if (*numAlumnos >= MAX_ALUMNOS)
    {
        TextColor(ROJO);
        printf("No se pueden agregar mas alumnos. El limite es de %d.\n", MAX_ALUMNOS);
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
            continue; // Repetir si no es valido

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
    // do
    // {
    //   printf("Edad: ");
    //   alumnos[*numAlumnos].edad = validar_num();
    //   if (alumnos[*numAlumnos].edad != -1 && (1 > alumnos[*numAlumnos].edad ||
    //                                           alumnos[*numAlumnos].edad > 80))
    //   {
    //     printf("Entre 1- 80 \n");
    //     pause();
    //     borrarlinea(3);
    //     alumnos[*numAlumnos].edad = -1;
    //   }

    // } while (alumnos[*numAlumnos].edad == -1);

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

    if (orden != 1)
    {
        if (numAlumnos > 300)
        {
            printf("\nQHICKSHORT.\n");
            ordenarQuickSort(alumnos, numAlumnos);
        }
        else
        {
            printf("\nBURBUJA.\n");
            ordenarBurbuja(alumnos, numAlumnos);
        }
    }
    else
    {
        error("LISTA YA ORDENADA");
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
void intercambiar(Alumno *a, Alumno *b)
{
    Alumno temp = *a;
    *a = *b;
    *b = temp;
}

int separar(Alumno alumnos[], int inicio, int fin)
{
    int pivot = alumnos[fin].matricula; // Utiliza el último elemento del arreglo como pivote
    int i = inicio - 1;

    for (int j = inicio; j <= fin - 1; j++) // tera a través del arreglo desde el inicio hasta el índice anterior al pivote
    {
        if (alumnos[j].matricula < pivot)
        {
            i++;
            intercambiar(&alumnos[i], &alumnos[j]); // Si encuentra un elemento menor que el pivote
                                                    // lo mueve a la parte izquierda del arreglo, representada por i
        }
    }
    intercambiar(&alumnos[i + 1], &alumnos[fin]); // Al final del ciclo, mueve el pivote a su posición correcta
                                                  // colocando todos los elementos menores a su izquierda y los mayores a su derecha.
    return i + 1;                                 // Devuelve la posición final del pivote
}

void quickSort(Alumno alumnos[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int pivot = separar(alumnos, inicio, fin);
        quickSort(alumnos, inicio, pivot - 1);
        quickSort(alumnos, pivot + 1, fin);
    }
}

void ordenarQuickSort(Alumno alumnos[], int numAlumnos)
{
    quickSort(alumnos, 0, numAlumnos - 1);
    printf("\nAlumnos ordenados.\n");
    orden = 1;
    pause();
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
    archivo = fopen("datos.txt", "a"); //  escritura

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.");
        return;
    }

    for (int i = numAlumnos - generados; i < numAlumnos; i++)
    {
        if (alumnos[i].status == 1)
        {
            // char sexo;
            // if (alumnos[i].sexo == 1)
            // {
            //     sexo = 'H'; // H para hombre
            // }
            // else
            // {
            //     sexo = 'M'; // M para mujer
            // }
            fprintf(archivo, "\n %3d.-  %-12d%-16s%-17s%-20s%-3d     %-10s",
                    i, alumnos[i].matricula, alumnos[i].nombre.nombre, alumnos[i].nombre.apPaterno,
                    alumnos[i].nombre.apMaterno, alumnos[i].edad, alumnos[i].sexos);
        }
    }
    // fprintf(archivo, "=================================================================================================================================\n");
    // fprintf(archivo, "| Total de alumnos: %-80d\t\t\t\t\t        |\n", numAlumnos);
    // fprintf(archivo, "=================================================================================================================================\n\n");

    fclose(archivo); // Cerrar el archivo
}

void generarArchivo(Alumno alumnos[], int numAlumnos)
{
    char nombreArchivo[100]; // Variable para almacenar el nombre del archivo

    // Solicitar al usuario el nombre del archivo
    printf("Ingrese el nombre del archivo: ");
    fgets(nombreArchivo, sizeof(nombreArchivo), stdin);

    // Eliminar el salto de línea del final del nombre del archivo
    nombreArchivo[strcspn(nombreArchivo, "\n")] = 0;

    // Agregar la extensión ".txt" al nombre del archivo
    strcat(nombreArchivo, ".txt");

    FILE *archivo;
    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.");
        return;
    }
    fprintf(archivo, "============================================================================================\n");
    fprintf(archivo, "| No.\t| Matricula | Nombre        | Apellido Paterno | Apellido Materno | Edad | Sexo     |\n");
    fprintf(archivo, "============================================================================================\n");
    for (int i = 0; i < numAlumnos; i++)
    {
        if (alumnos[i].status == 1)
        {

            fprintf(archivo, " %3d.-  %-12d%-16s%-17s%-20s%-3d     %-10s\n",
                    i, alumnos[i].matricula, alumnos[i].nombre.nombre, alumnos[i].nombre.apPaterno,
                    alumnos[i].nombre.apMaterno, alumnos[i].edad, alumnos[i].sexos);
        }
    }
    // fprintf(archivo, "=================================================================================================================================\n");
    // fprintf(archivo, "| Total de alumnos: %-80d\t\t\t\t\t        |\n", numAlumnos);
    // fprintf(archivo, "=================================================================================================================================\n\n");

    fclose(archivo); // Cerrar el archivo
}

void guardarRegistrosDAT(Alumno alumnos[], int numAlumnos)
{
    FILE *archivo;
    archivo = fopen("registros.dat", "ab");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        pause();
        return;
    }

    // Alumno alumnoExistente;
    // while (fread(&alumnoExistente, sizeof(Alumno), 1, archivo) == 1)
    // {
    //   // por si quisiera mostrar lo guardado
    // }

    // Escribir el nuevo al final del anterior
    fwrite(alumnos, sizeof(Alumno), numAlumnos, archivo);

    fclose(archivo);
}

void guardarRegistros(Alumno alumnos[], int numAlumnos)
{
    guardarRegistrosDAT(alumnos, numAlumnos);
}

void imprimirRegistrosDAT()
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
    printf("| No.\t| Matricula | Apellido Paterno | Apellido Materno | Nombre\t\t| Fecha      | Edad | Sexo | CURP          |\n");
    printf("================================================================================================================\n");
    int contador = 0;
    Alumno alumno;

    while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1)
    {
        char sexo;
        if (alumno.sexo == 1)
        {
            sexo = 'H'; // H para hombre
        }
        else
        {
            if (alumno.sexo == 2)
            {
                sexo = 'M'; // M para mujer
            }
        }
        printf("| %4d\t| %-9d | %-16s | %-16s | %-17s\t| %02d/%02d/%4d | %-3d  | %-2c   | %-18s |\n",
               contador + 1, alumno.matricula, alumno.nombre.apPaterno, alumno.nombre.apMaterno,
               alumno.nombre.nombre, alumno.fecha.dia, alumno.fecha.mes, alumno.fecha.anio, alumno.edad, sexo, alumno.curp);

        contador++;
    }

    printf("================================================================================================================\n");
    printf("| Total de alumnos: %-80d\t\t\b|\n", contador);
    printf("================================================================================================================\n\n");

    fclose(archivo);
}