// Diego Alonso Ibarra Galindo
// Programa con menú para cargar, agregar, buscar, ordenar, mostrar y generar archivos de registros
// Elaborado: 6/05/2024  Modificado: 10/05/2024
// DAIG_ACT13.cpp
#include "_FUN.h"

// Prototipos de funciones
int menu();
void opciones();
void cargarArchivoTXT();
void mostrarTodo(Alumno cargAlum[], int *numAlumnos);
void agregarAutomatico(Alumno alumnos[], int *numAlumnos);
void editarRegistro(Alumno alumnos[], int numAlumnos);
void eliminarRegistro(Alumno alumnos[], int *numAlumnos);
void imprimirbusqueda(Alumno alumnos[], int numAlumnos);
int buscar(Alumno alumnos[], int numAlumnos, int *matricula);

void ordenarPorMatricula(Alumno alumnos[], int numAlumnos);
void imprimir(Alumno alumnos[], int numAlumnos);
void imprimir_pagina(Alumno alumnos[], int numAlumnos, int pagina_actual);
void guardarEnArchivoTXT(Alumno alumnos[], int numAlumnos);
void generarArchivoTXT(Alumno alumnos[], int numAlumnos);
void guardarRegistrosBINARIO(Alumno alumnos[], int numAlumnos);
void cargarArchivoBIN(Alumno cargAlum[], int *numAlumnos);
void mostrarBorrados();
void imprimirRegistrosBINARIO();

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
    interaface(9, 14, 1, 1, "-> MENU <-");
    printRes(1,
             " 1.- AGREGAR (100)",
             " 2.- EDITAR REGISTRO",
             " 3.- ELIMINAR REGISTRI",
             " 4.- BUSCAR",
             " 5.- ORDENAR",
             " 6.- IMPRIMIR",
             " 7.- GENERAR ARCHIVO TXT",
             " 8.- VER ARCHIVO .TXT",
             " 9.- CREAR ARCHIVO BINARIO",
             " 10.- CARGAR ARCHIVO BINARIO",
             " 11.- MOSTRAR  ELIMINADOS",
             " 0.- SALIR",
             "ESCOGE UNA OPCION: ",
             NULL);
    opcion = validar_num(0, 11);

    return opcion;
}

//****************
void opciones()
{
    TextColor(DEF);

    Alumno alumnos[MAX_ALUMNOS];
    int numAlumnos = 0;

    cargarArchivoBIN(alumnos, &numAlumnos);  // cargar al iniciar el programa 

    int opcion;
    do
    {
        do
        {
            opcion = menu();

        } while (opcion == -1);
        switch (opcion)
        {
        case 1: // agregar
            agregarAutomatico(alumnos, &numAlumnos);

            // cargarArchivoTXT(alumnos, &numAlumnos);
            //  agregarAutomatico(alumnos, &numAlumnos);
            //  guardarRegistros(alumnos, numAlumnos);
            break;
        case 2: // editar
            editarRegistro(alumnos, numAlumnos);
            break;
        case 3: // eliminar
            // imprimir(alumnos, numAlumnos);
            eliminarRegistro(alumnos, &numAlumnos);
            break;
        case 4: // buscar
            imprimirbusqueda(alumnos, numAlumnos);
            break;
        case 5: // ordenar
            ordenarPorMatricula(alumnos, numAlumnos);
            break;
        case 6: // imprimir
            imprimir(alumnos, numAlumnos);
            // mostrarTodo(alumnos, &numAlumnos);
            pause();
            break;
        case 7: // generar archivo Txt
            generarArchivoTXT(alumnos, numAlumnos);
            break;
        case 8: // ver archivo Txt
            cargarArchivoTXT();
            pause();
            break;
        case 9: // generar archivo bin
            guardarRegistrosBINARIO(alumnos, numAlumnos);
            pause();
            break;
        case 10: // cargar archivo bin
            cargarArchivoBIN(alumnos, &numAlumnos);
            pause();
            break;
        case 11: // mostrar eliminados
            mostrarBorrados();
            pause();
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
void cargarArchivoTXT()
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
    archivo = fopen(nombreArchivo, "r"); //  lectura
    if (archivo == NULL)
    {
        error("ERROR AL ABRIR EL ARCHIVO");

        return;
    }
    printf("cargado\n");

    int c;
    while ((c = fgetc(archivo)) != EOF)
    {
        printf("%c", c);
    }

    fclose(archivo); // Cerrar el archivo
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
                           contador, cargAlum[contador].key, cargAlum[contador].nombre.nombre, cargAlum[contador].nombre.apPaterno,
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
        colorprintf(ROJO, "No se pueden agregar %d alumnos mas. El limite es de %d.\n", AUTOMATICOS, MAX_ALUMNOS);
        pause();
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < AUTOMATICOS; i++)
    {
        alumnos[*numAlumnos + i].status = 1; // Activo

        int matricula;
        do
        {
            matricula = randomR(300000, 400000);

        } while (buscarSecuencial(alumnos, *numAlumnos, matricula) != -1); // matricula no repetible

        alumnos[*numAlumnos + i].matricula = matricula;
        alumnos[*numAlumnos + i].key = alumnos[*numAlumnos + i].matricula;

        int indApellPat = random(MAX_APELLIDOS);
        int indApellMat = random(MAX_APELLIDOS);
        int indiceNombre = random(MAX_NOMBRES);

        snprintf(alumnos[*numAlumnos + i].nombre.nombre, sizeof(alumnos[*numAlumnos + i].nombre.nombre), "%s",
                 nombres[indiceNombre]);
        snprintf(alumnos[*numAlumnos + i].nombre.apPaterno, sizeof(alumnos[*numAlumnos + i].nombre.apPaterno), "%s",
                 apellidos[indApellPat]);
        snprintf(alumnos[*numAlumnos + i].nombre.apMaterno, sizeof(alumnos[*numAlumnos + i].nombre.apMaterno), "%s",
                 apellidos[indApellMat]);

        alumnos[*numAlumnos + i].edad = randomR(18, 50);

        if (indiceNombre < 15)
        {
            strcpy(alumnos[*numAlumnos + i].sexos, "MASCULINO");
            // alumnos[*numAlumnos + i].sexos = "hombre";
        }
        else
        {
            strcpy(alumnos[*numAlumnos + i].sexos, "FEMENINO");
        }
    }

    *numAlumnos += AUTOMATICOS;
    generados += AUTOMATICOS;
    orden = 0;

    printf("Se agregaron %d registros automaticos correctamente.\n", AUTOMATICOS);
    pause();
}

//*************************

void editar()
{
}

//*************************

void editarRegistro(Alumno alumnos[], int numAlumnos)
{
    int matricula, op = 0;
    int opcion;
    int sexo;
    char cadena[20];
    char esp[8] = "\t\b\b\b\b\b\b";

    int indice = buscar(alumnos, numAlumnos, &matricula);
    if (indice != -1)
    {

        do
        {
            cls();
            interaface(11, 6, 2, 1, "-> EDITAR <-");
            printf("%s 1. Nombre:          \t\t %-20s\n", esp, alumnos[indice].nombre.nombre);
            printf("%s 2. Apellido Paterno:\t\t %-20s\n", esp, alumnos[indice].nombre.apPaterno);
            printf("%s 3. Apellido Materno:\t\t %-20s\n", esp, alumnos[indice].nombre.apMaterno);
            printf("%s 4. Edad:            \t\t %-20d\n", esp, alumnos[indice].edad);
            printf("%s 5. Sexo:            \t\t %-20s\n", esp, alumnos[indice].sexos);
            printf("%s 0. Salir\n\n", esp);

            if (op)
            {
                printf("\n\nDESEA HACER OTRA EDICION? \n");
                printf("1 Para si\n");
                printf("0 Para no\n");
                op = validar_num(0, 1);
                if (op == 0)
                {
                    return;
                }
                borrarlinea(5);
            }

            printf("Seleccione el campo que desea editar (1-5): ");
            opcion = validar_num(0, 5);
            switch (opcion)
            {
            case 1:
                do
                {
                    printf("Ingrese el nuevo nombre: ");
                    leercadena(cadena);

                } while (!validar_letras(cadena));
                strcpy(alumnos[indice].nombre.nombre, cadena);
                colorprintf(VERDE, "Registro actualizado correctamente.\n");
                op = 1;
                break;
            case 2:
                do
                {
                    printf("Ingrese el nuevo apellido paterno: ");
                    leercadena(cadena);

                } while (!validar_letras(cadena));
                strcpy(alumnos[indice].nombre.apPaterno, cadena);

                colorprintf(VERDE, "Registro actualizado correctamente.\n");
                op = 1;
                break;
            case 3:
                do
                {
                    printf("Ingrese el nuevo apellido materno: ");
                    leercadena(cadena);

                } while (!validar_letras(cadena));
                strcpy(alumnos[indice].nombre.apMaterno, cadena);

                colorprintf(VERDE, "Registro actualizado correctamente.\n");
                op = 1;
                break;
            case 4:
                printf("Ingrese la nueva edad: ");
                alumnos[indice].edad = validar_num(1, 100);
                break;
            case 5:
                printf("Ingrese el nuevo sexo\n");
                printf("1 para MASCULINO\n");
                printf("2 para FEMENINO\n");
                sexo = validar_num(1, 2);
                if (sexo == 1)
                {
                    strcpy(alumnos[indice].sexos, "MASCULINO");
                }
                else
                {
                    strcpy(alumnos[indice].sexos, "FEMENINO");
                }
                colorprintf(VERDE, "Registro actualizado correctamente.\n");
                op = 1;
                break;
            case 0:
                printf("salir.\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
            }
        } while (opcion != 0);
    }
    else
    {
        colorprintf(ROJO, "No se encontró ningún alumno con la matrícula proporcionada.\n");
    }
    pause();
}

//****************************
void eliminarRegistro(Alumno alumnos[], int *numAlumnos)
{
    TextColor(DEF);

    printf("\nELIMINAR REGISTRO\n");

    int matricula;
    int indice;
    indice = buscar(alumnos, *numAlumnos, &matricula);

    if (indice != -1)
    {
        // Marcar el registro como inactivo
        alumnos[indice].status = 0;
        colorprintf(VERDE, "El alumno con matricula %d ha sido eliminado correctamente.\n", matricula);
    }
    else
    {
        colorprintf(ROJO, "No se encontró ningún alumno con la matricula %d.\n", matricula);
    }

    pause();
}
void imprimirbusqueda(Alumno alumnos[], int numAlumnos)
{
    int indice;
    int matricula;
    char resp;
    do
    {
        indice = buscar(alumnos, numAlumnos, &matricula);

        if (indice != -1)
        {
            if (alumnos[indice].status != 1)
            {
                colorprintf(ROJO, "****  La matricula %d esta inactiva.\n", matricula);
            }
            printf("La matricula %d fue encontrada en la posicion %d.\n", matricula, indice + 1);
            printf("=================================================================================================================================\n");
            printf("| No.\t| Matricula | Apellido Paterno | Apellido Materno | Nombre\t\t| Edad | Sexo      |\n");
            printf("=================================================================================================================================\n");

            printf("| %4d\t| %-9d | %-16s | %-16s | %-17s\t| %-3d  | %-10s |\n",
                   indice, alumnos[indice].key, alumnos[indice].nombre.apPaterno, alumnos[indice].nombre.apMaterno,
                   alumnos[indice].nombre.nombre, alumnos[indice].edad, alumnos[indice].sexos);
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
int buscar(Alumno alumnos[], int numAlumnos, int *matricula)
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
    printf("| No.\t| Matricula | Apellido Paterno | Apellido Materno | Nombre\t\t| Edad | Sexo          |\n");
    printf("=================================================================================================================================\n");

    for (int i = inicio; i < fin && i < numAlumnos; i++)
    {
        if (alumnos[i].status == 1)
        {

            printf("| %4d\t| %-9d | %-16s | %-16s | %-17s\t| %-3d  | %-13s|\n",
                   i + 1, alumnos[i].key, alumnos[i].nombre.apPaterno, alumnos[i].nombre.apMaterno,
                   alumnos[i].nombre.nombre, alumnos[i].edad, alumnos[i].sexos);
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
        error("Error al abrir el archivo.");
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
                    i, alumnos[i].key, alumnos[i].nombre.nombre, alumnos[i].nombre.apPaterno,
                    alumnos[i].nombre.apMaterno, alumnos[i].edad, alumnos[i].sexos);
        }
    }
    // fprintf(archivo, "=================================================================================================================================\n");
    // fprintf(archivo, "| Total de alumnos: %-80d\t\t\t\t\t        |\n", numAlumnos);
    // fprintf(archivo, "=================================================================================================================================\n\n");

    fclose(archivo); // Cerrar el archivo
}

void generarArchivoTXT(Alumno alumnos[], int numAlumnos)
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
    for (int i = 0; i < numAlumnos; i++)
    {
        if (alumnos[i].status == 1)
        {

            fprintf(archivo, " %3d.-  %-12d%-16s%-17s%-20s%-3d     %-10s\n",
                    i, alumnos[i].key, alumnos[i].nombre.nombre, alumnos[i].nombre.apPaterno,
                    alumnos[i].nombre.apMaterno, alumnos[i].edad, alumnos[i].sexos);
        }
    }
    fprintf(archivo, "====================================================================================================\n");
    // fprintf(archivo, "| Total de alumnos: %-80d\t\t\t\t\t        |\n", numAlumnos);
    // fprintf(archivo, "=================================================================================================================================\n\n");

    fclose(archivo); // Cerrar el archivo
}

void guardarRegistrosBINARIO(Alumno alumnos[], int numAlumnos)
{
    rename("datos.bin", "datos.tmp");

    // Crear el nuevo archivo binario
    FILE *archivo;
    archivo = fopen("datos.bin", "wb");

    if (archivo == NULL)
    {
        error("Error al crear el archivo.");
        return;
    }

    // Escribir los datos del vector en el archivo binario
    if (numAlumnos > 0)
    {
        fwrite(alumnos, sizeof(Alumno), numAlumnos, archivo);
        printf("Archivo binario creado correctamente.\n");
    }
    else
    {
        printf("No hay registros para guardar en el archivo.\n");
    }

    fclose(archivo);
}

void cargarArchivoBIN(Alumno cargAlum[], int *numAlumnos)
{
    if (cargado)
    {
        error("ARCHIVO YA CARGADO");
    }
    else
    {
        FILE *archivo;
        archivo = fopen("datos.bin", "rb");

        if (archivo == NULL)
        {
            printf("El archivo binario no existe.\n");
            return;
        }

        // Leer los datos del archivo binario y cargarlos en el vector
        *numAlumnos = fread(cargAlum, sizeof(Alumno), MAX_ALUMNOS, archivo);

        fclose(archivo);
        printf("Registros cargados correctamente desde el archivo binario.\n");
    }
    cargado = TRUE;
}

void mostrarBorrados()
{
    FILE *archivo;
    archivo = fopen("datos.bin", "rb");

    if (archivo == NULL)
    {
        error("Error al abrir el archivo binario.");
        return;
    }

    printf("REGISTROS BORRADOS:\n");
    printf("================================================================================================================\n");
    printf("| No.\t| Matricula | Apellido Paterno | Apellido Materno | Nombre\t\t| Edad | Sexo |\n");
    printf("================================================================================================================\n");

    int contador = 0;
    Alumno alumno;

    while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1)
    {
        if (alumno.status == 1)
        {
            printf("| %4d\t| %-9d | %-16s | %-16s | %-17s\t| %-3d  | %-2s   |\n",
                   contador + 1, alumno.key, alumno.nombre.apPaterno, alumno.nombre.apMaterno,
                   alumno.nombre.nombre, alumno.edad, alumno.sexos);

            contador++;
        }
    }
    printf("================================================================================================================\n");
    printf("| Total de registros borrados: %-72d\t\t\b|\n", contador);
    printf("================================================================================================================\n\n");

    fclose(archivo);
}

void imprimirRegistrosBINARIO()
{
    FILE *archivo;
    archivo = fopen("registros.dat", "rb");
    if (archivo == NULL)
    {
        error("Error al abrir el archivo.");
        return;
    }
    printf("LISTA DE ALUMNOS (desde archivo DAT)\n");
    printf("================================================================================================================\n");
    printf("| No.\t| Matricula | Apellido Paterno | Apellido Materno | Nombre\t\t| Edad | Sexo |\n");
    printf("================================================================================================================\n");
    int contador = 0;
    Alumno alumno;

    while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1)
    {
        printf("| %4d\t| %-9d | %-16s | %-16s | %-17s\t| %-3d  | %-2s   |\n",
               contador + 1, alumno.key, alumno.nombre.apPaterno, alumno.nombre.apMaterno,
               alumno.nombre.nombre, alumno.edad, alumno.sexos);

        contador++;
    }

    printf("================================================================================================================\n");
    printf("| Total de alumnos: %-80d\t\t\b|\n", contador);
    printf("================================================================================================================\n\n");

    fclose(archivo);
}