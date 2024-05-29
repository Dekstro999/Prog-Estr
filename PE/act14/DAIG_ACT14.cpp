// Programa con menú para cargar, agregar, buscar, ordenar, mostrar y generar archivos de registros
// Elaborado: 6/05/2024  Modificado: 10/05/2024
// DAIG_ACT14.cpp
#include "_FUN.h"

// Prototipos de funciones
int menu();
void opciones();
void agregarAutomatico(Alumno alumnos[], Tindice indices[], int *numIndices);
void eliminarRegistro(Alumno alumnos[], Tindice indices[], int *numIndices);
void imprimirbusqueda(Tindice indices[], int numIndice);
int buscar(Tindice alumnos[], int numAlumnos, int *matricula);
void ordenarPorMatricula(Tindice indices[], int numIndices);
void cargarArchivoBIN(Tindice indices[], int *numIndices);
void mostrarTodo(Tindice indices[], int numIndices);
void imprimirRegistrosBINARIO(int status, Tindice indices[], int numIndices);
void generarArchivoTXT(Tindice indices[], int numIndices, int ordenado);

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
    interaface(9, 12, 1, 1, "-> MENU <-");
    printRes(1,
             " 1.- AGREGAR (1)",
             " 2.- ELIMINAR",
             " 3.- BUSCAR",
             " 4.- ORDENAR",
             " 5.- IMPRIMIR REGISTROS (ARCHIVO ORIGINAL)",
             " 6.- IMPRIMIR REGISTROS (ARCHIVO ORDENADO",
             " 7.- GENERAR ARCHIVO .TXT",
             " 8.- EMPAQUETAR",
             " 0.- SALIR",
             "ESCOGE UNA OPCION: ",
             NULL);
    opcion = validar_num(0, 8);

    return opcion;
}

//****************
void opciones()
{
    TextColor(DEF);
    Alumno alumnos[MAX_ALUMNOS];
    Tindice indices[MAX_ALUMNOS];
    int numIndices = 0;

    cargarArchivoBIN(indices, &numIndices); // cargar al iniciar el programa

    int opcion;
    do
    {
        do
        {
            opcion = menu();

        } while (opcion == -1);
        switch (opcion)
        {
        case 1: // agregar               // YA
            for (int i = 0; i < AUTOMATICOS; i++)
            {
                agregarAutomatico(alumnos, indices, &numIndices);
            }
            printf("Se agregaron %d registros automáticos correctamente.\n", AUTOMATICOS);
            pause();
            break;
        case 2: // ELIMINAR               // YA
            eliminarRegistro(alumnos, indices, &numIndices);
            break;
        case 3: // BUSCAR               // YA
            imprimirbusqueda(indices, numIndices);
            break;
        case 4: // ORDENAR
            ordenarPorMatricula(indices, numIndices);
            break;
        case 5: // IMPRIMIR ORIGINAL
        case 6: // IMPRIMIR ORDENADO
            mostrarTodo(indices, numIndices);
            pause();
            break;
        case 7: // generar archivo Txt
            printf("¿Desea generar el archivo ordenado o desordenado? [1] Ordenado [2] Desordenado: ");
            int opcionOrden;
            opcionOrden = validar_num(1, 2);
            generarArchivoTXT(indices, numIndices, opcionOrden == 1);
            break;

            break;
        case 8: // EMPAQUETAR
            error("AUN NO ECHA");
            break;
        case 0:
            printf(" Saliendo del programa... ");
            anima(1);
            break;
        default:
            error("OPCION NO VALIDA");
        }
    } while (opcion != 0);
}

//*********************

//*********************
void cargarArchivoBIN(Tindice indices[], int *numIndices)
{
    FILE *archivo = fopen("datos.bin", "rb");
    if (archivo == NULL)
    {
        error("Error al abrir el archivo binario");
        return;
    }

    Alumno temp;
    int indice = 0;

    while (fread(&temp, sizeof(Alumno), 1, archivo))
    {
        indices[indice].key = temp.matricula;
        indices[indice].indice = indice;
        indice++;
    }

    *numIndices = indice;

    fclose(archivo);
}
//*********************
void agregarAutomatico(Alumno alumnos[], Tindice indices[], int *numIndices)
{
    TextColor(DEF);

    if (*numIndices + AUTOMATICOS > MAX_ALUMNOS)
    {
        colorprintf(ROJO, "No se pueden agregar %d alumnos mas. El limite es de %d.\n", AUTOMATICOS, MAX_ALUMNOS);
        pause();
        return;
    }

    srand(time(NULL));
    Alumno nuevoAlumno;

    nuevoAlumno.status = 1;

    Tkey matricula;
    do
    {
        matricula = randomR(300000, 400000);

    } while (buscarSecuencial(indices, *numIndices, matricula) != -1); // matricula no repetible

    nuevoAlumno.matricula = matricula;
    nuevoAlumno.key = nuevoAlumno.matricula;

    int indApellPat = random(MAX_APELLIDOS);
    int indApellMat = random(MAX_APELLIDOS);
    int indiceNombre = random(MAX_NOMBRES);

    strcpy(nuevoAlumno.nombre.nombre, nombres[indiceNombre]);
    strcpy(nuevoAlumno.nombre.apPaterno, apellidos[indApellPat]);
    strcpy(nuevoAlumno.nombre.apMaterno, apellidos[indApellMat]);

    nuevoAlumno.edad = randomR(18, 50); // edad entre 18 y 30

    if (indiceNombre < 15)
    {
        strcpy(nuevoAlumno.sexos, "MASCULINO");
    }
    else
    {
        strcpy(nuevoAlumno.sexos, "FEMENINO");
    }

    // Agregar el nuevo alumno al arreglo de alumnos
    alumnos[*numIndices] = nuevoAlumno;
    // Actualizar el índice correspondiente en el vector de índices
    indices[*numIndices].key = nuevoAlumno.matricula;
    indices[*numIndices].indice = *numIndices;

    // Actualizar el número total de índices
    *numIndices += AUTOMATICOS;
    orden = 0;

    // Guardar en archivo binario
    FILE *archivo = fopen("datos.bin", "ab");
    if (archivo == NULL)
    {
        error("Error al abrir el archivo binario para agregar.");
        return;
    }
    fwrite(&alumnos[*numIndices - AUTOMATICOS], sizeof(Alumno), AUTOMATICOS, archivo);
    fclose(archivo);
}

//*************************

//****************************

void eliminarRegistro(Alumno alumnos[], Tindice indices[], int *numIndices)
{
    TextColor(DEF);

    printf("\nELIMINAR REGISTRO\n");
    Alumno temp;
    int matricula;
    int indice = buscar(indices, *numIndices, &matricula);

    if (indice != -1)
    {
        // Leer el registro correspondiente del archivo
        FILE *archivo = fopen("datos.bin", "rb+");
        if (archivo == NULL)
        {
            error("Error al abrir el archivo binario.");
            return;
        }
        fseek(archivo, indices[indice].indice * sizeof(Alumno), SEEK_SET);
        fread(&temp, sizeof(Alumno), 1, archivo);

        printf("\nDesea eliminar al alumno [ %s %s %s ] 1 si, 2 no: ",
               temp.nombre.nombre,
               temp.nombre.apPaterno,
               temp.nombre.apMaterno);

        int resp = validar_num(1, 2);
        if (resp == 1)
        {
            temp.status = 0;
            // Actualizar el estado en el archivo binario
            fseek(archivo, indices[indice].indice * sizeof(Alumno), SEEK_SET);
            fwrite(&temp, sizeof(Alumno), 1, archivo);
            fclose(archivo);

            // Actualizar también el arreglo de alumnos en memoria
            alumnos[indice].status = 0;

            colorprintf(VERDE, "El alumno con matricula %d ha sido eliminado correctamente.\n", matricula);
        }
        else
        {
            fclose(archivo);
            return;
        }
    }
    else
    {
        colorprintf(ROJO, "No se encontró ningún alumno con la matricula %d.\n", matricula);
    }

    pause();
}

void imprimirbusqueda(Tindice indices[], int numIndice)
{
    int indice;
    int matricula;
    char resp;
    Alumno temp;
    do
    {
        indice = buscar(indices, numIndice, &matricula);

        if (indice != -1)
        {
            FILE *archivo = fopen("datos.bin", "rb");
            if (archivo == NULL)
            {
                error("Error al abrir el archivo binario.");
                return;
            }

            fseek(archivo, indices[indice].indice * sizeof(Alumno), SEEK_SET);
            fread(&temp, sizeof(Alumno), 1, archivo);
            fclose(archivo);

            if (temp.status == 0)
            {
                colorprintf(ROJO, "**** La matricula %d esta inactiva.\n", matricula);
            }

            printf("La matricula %d fue encontrada en la posicion %d.\n", matricula, indice + 1);
            printf("=================================================================================================================================\n");
            printf("| No.\t| Matricula | Apellido Paterno | Apellido Materno | Nombre\t\t| Edad | Sexo      |\n");
            printf("=================================================================================================================================\n");

            printf("| %4d\t| %-9d | %-16s | %-16s | %-17s\t| %-3d  | %-10s |\n",
                   indices[indice].indice, temp.key, temp.nombre.apPaterno, temp.nombre.apMaterno,
                   temp.nombre.nombre, temp.edad, temp.sexos);
            printf("=================================================================================================================================\n");
        }
        else
        {
            colorprintf(ROJO, "La matricula %d no fue encontrada en la lista.\n", matricula);
        }

        printf("\n Desea buscar otro registro? (s/n): ");
        scanf(" %c", &resp);
        while ((getchar()) != '\n')
            ; // Limpiar el buffer de entrada
        convertirMayusculas(&resp);

    } while (resp == 'S');
}

int buscar(Tindice alumnos[], int numAlumnos, int *matricula)
{

    int indice;
    cls();
    do
    {
        cls();
        printf("\nIngrese la matricula: ");
        *matricula = validarMatricula();
    } while (*matricula == -1);

    if (orden == 0)
    {
        printf("\nSECUENCIAL");
        indice = buscarSecuencial(alumnos, numAlumnos, *matricula);
    }
    else
    {
        printf("\nBINARIA");
        indice = buscarBinaria(alumnos, numAlumnos, *matricula);
    }
    return indice;
}

void ordenarPorMatricula(Tindice indices[], int numIndice)
{
    TextColor(DEF);

    if (orden != 1)
    {
        if (numIndice > 300)
        {
            printf("\nQHICKSHORT.\n");
            ordenarQuickSort(indices, numIndice);
        }
        else
        {
            printf("\nBURBUJA.\n");
            ordenarBurbuja(indices, numIndice);
        }
    }
    else
    {
        error("LISTA YA ORDENADA");
    }
}

void imprimirRegistrosBINARIO(int status, Tindice indices[], int numIndices)
{
    FILE *archivo = fopen("datos.bin", "rb");
    if (archivo == NULL)
    {
        error("Error al abrir el archivo.");
        return;
    }
    int contador = 0;

    printf("LISTA DE ALUMNOS (desde archivo BIN)\n");
    printf("=================================================================================================================================\n");
    printf("| No.\t| Matricula | Apellido Paterno | Apellido Materno | Nombre\t\t| Edad | Sexo          |\n");
    printf("=================================================================================================================================\n");

    if (status)
    {
        for (int i = 0; i < numIndices; i++)
        {
            Alumno alumno;
            fseek(archivo, indices[i].indice * sizeof(Alumno), SEEK_SET);
            fread(&alumno, sizeof(Alumno), 1, archivo);
            if (alumno.status == 1)
            {
                printf("| %4d\t| %-9d | %-16s | %-16s | %-17s\t| %-3d  | %-13s |\n",
                       contador + 1, alumno.key, alumno.nombre.apPaterno, alumno.nombre.apMaterno,
                       alumno.nombre.nombre, alumno.edad, alumno.sexos);
                contador++;
            }
        }
    }
    else
    {
        Alumno alumno;
        while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1)
        {
            if (alumno.status == 1)
            {
                printf("| %4d\t| %-9d | %-16s | %-16s | %-17s\t| %-3d  | %-13s |\n",
                       contador + 1, alumno.key, alumno.nombre.apPaterno, alumno.nombre.apMaterno,
                       alumno.nombre.nombre, alumno.edad, alumno.sexos);
                contador++;
            }
        }
    }
    printf("=================================================================================================================================\n");
    printf("| Total de alumnos: %-4d\t\t\t\t\t\t\t\t\t\t\t\t|\n", contador);
    printf("=================================================================================================================================\n\n");

    fclose(archivo);
}
void mostrarTodo(Tindice indices[], int numIndices)
{
    printf("Desea mostrar los registros ordenados o en el orden normal? [1] Ordenado [2] Normal: ");
    int opcion = validar_num(1, 2);

    switch (opcion)
    {
    case 1:
        ordenarPorMatricula(indices, numIndices);
        imprimirRegistrosBINARIO(1, indices, numIndices);
        break;
    case 2:
        imprimirRegistrosBINARIO(0, indices, numIndices);
        break;
    default:
        break;
    }
}

void generarArchivoTXT(Tindice indices[], int numIndices, int ordenado)
{
    char nombreArchivo[100];

    do
    {
        printf("Ingrese el nombre del archivo: ");
        leercadena(nombreArchivo);
    } while (!validar_letras(nombreArchivo));

    nombreArchivo[strcspn(nombreArchivo, "\n")] = 0;

    strcat(nombreArchivo, ".txt");

    FILE *archivo;
    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL)
    {
        error("Error al abrir el archivo.");
        return;
    }

    fprintf(archivo, "============================================================================================\n");
    fprintf(archivo, "| No.\t| Matricula | Nombre        | Apellido Paterno | Apellido Materno | Edad | Sexo     |\n");
    fprintf(archivo, "============================================================================================\n");

    if (ordenado)
    {
        ordenarPorMatricula(indices, numIndices);
    }

    FILE *archivoBinario = fopen("datos.bin", "rb");
    if (archivoBinario == NULL)
    {
        error("Error al abrir el archivo binario.");
        fclose(archivo);
        return;
    }

    for (int i = 0; i < numIndices; i++)
    {
        Alumno alumno;
        fseek(archivoBinario, indices[i].indice * sizeof(Alumno), SEEK_SET);
        fread(&alumno, sizeof(Alumno), 1, archivoBinario);

        fprintf(archivo, " %3d.-  %-12d%-16s%-17s%-20s%-3d     %-10s\n",
                i + 1, alumno.key, alumno.nombre.nombre, alumno.nombre.apPaterno,
                alumno.nombre.apMaterno, alumno.edad, alumno.sexos);
    }

    fprintf(archivo, "====================================================================================================\n");

    fclose(archivo);        // Cerrar el archivo
    fclose(archivoBinario); // Cerrar el archivo binario
}
