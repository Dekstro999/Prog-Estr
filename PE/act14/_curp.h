// _curp.h

#include "_FUN.h"

// Prototipo de función
void imprimirCurp(void);
int validar_numC();
void eliminarNuevaLinea(char *cadena);
void eliminarPrimeraPalabra(char *cadena);

void letrasPaterno(char *inicialP, char *vocalP, char *paterno);
void letrasMaterno(char *inicialMatr, char *materno);
int obtenerInicialNombre(char *inicial, char *nombre);

char siguienteConsonante(char *cadena);

void estadosAbreb(char *abreviaturaEstado);
struct Estado obtenerEstadoAleatorio();
void asignarEstadoAleatorio(Alumno *alumno);
void generarCURP(char *curp, char *paterno, char *materno, char *nombre, int anio, int mes, int dia, char sex, char *est);

// * * * * * * * * * * * * * * * *

void imprimirCurp(void)
{
    char respuesta;

    do
    {
        system("cls");
        char curp[21];
        srand(time(NULL));

        printf("\n\n");
        // TextColor(AMARI);
        printf("%c", 218);
        for (int i = 0; i < 45; i++)
        {

            printf("%c", 196);
        }
        printf("%c\n%c", 191, 179);
        // TextColor(CYAN);
        printf("           -> Ingrese los datos <-           ");
        // TextColor(AMARI);
        printf("%c\n%c", 179, 179);
        // TextColor(CYAN);
        printf(" * Precione [ENTER] si el espacio es vacio   ");
        // TextColor(AMARI);
        printf("%c\n%c", 179, 195);
        for (int i = 0; i < 44; i++)
        {
            if (i == 20)
            {
                printf("%c", 194);
            }
            printf("%c", 196);
        }
        printf("%c\n", 180);

        // generarCURP(curp);
        printf("%c", 179);

        // TextColor(AZUL);
        printf(" CURP generado:     ");
        // TextColor(AMARI);
        printf("|");
        // TextColor(AZUL);

        printf("  %s    ", curp);
        // TextColor(AMARI);
        printf("%c\n%c", 179, 192);

        for (int i = 0; i < 44; i++)
        {
            if (i == 20)
            {
                printf("%c", 193);
            }

            printf("%c", 196);
        }
        printf("%c\n\n", 217);

        printf("\n Desea generar otro CURP? (s/n): ");
        scanf(" %c", &respuesta);
        while (getchar() != '\n')
            ;

    } while (respuesta == 's' || respuesta == 'S');
    printf("\n Cerrando . . .");
    anima(3);
    printf("\033[1A\033[K");

    // TextColor(DEF);
}

// * * * * * * * * * * * * * * * *
int validar_numC()
{
    int num;

    if (scanf("%d", &num) == 1)
    {
        while (getchar() != '\n')
            ;
        return num;
    }
    else
    {
        // TextColor(AMARI);
        printf("\033[F\t\t\t\t\t\t\b\b|\n");
        // TextColor(ROJO);
        printf("**Invalido. Por favor ingrese solo numeros.**");
        // TextColor(DEF);

        system("pause");
        printf("\033[1A\033[K");
        printf("\033[1A\033[K");
        while (getchar() != '\n') // Limpiar el búfer del teclado
            ;
    }
    return -1;
}
// * * * * * * * * * * * * * * * *
void eliminarNuevaLinea(char *cadena)
{
    int longitud = strlen(cadena);
    if (longitud > 0 && cadena[longitud - 1] == '\n')
    {
        cadena[longitud - 1] = '\0';
    }
}

void eliminarPrimeraPalabra(char *cadena)
{
    // Eliminar cualquier espacio al final de la cadena
    int longitud = strlen(cadena);
    while (longitud > 0 && cadena[longitud - 1] == ' ')
    {
        cadena[longitud - 1] = '\0';
        longitud--;
    }

    // Mientras haya un espacio
    while (strchr(cadena, ' ') != NULL)
    {
        // printf("actual.%s|\n", cadena);            // Mensaje de depuración
        char *primerEspacio = strchr(cadena, ' '); // primera posición de espacio en la cadena

        if (primerEspacio != NULL) // al menos un espacio
        {
            strcpy(cadena, primerEspacio + 1); // copy
        }
    }
    // printf("final.%s|\n", cadena); // Mensaje de depuración
}

// * * * * * * * * * * * * * * * *

void letrasPaterno(char *inicialP, char *vocalP, char *paterno)
{
    // do
    // {
    //   // printf("|");
    //   // //TextColor(VERDE);
    //   // printf(" Apellido paterno:  ");
    //   // //TextColor(AMARI);
    //   // printf("|  ");
    //   // //TextColor(VERDE);
    //   // fgets(paterno, 25, stdin);
    //   // TextColor(AMARI);
    //   paterno[strcspn(paterno, "\n")] = '\0'; // Eliminamos el enter
    //   printf("\033[F\t\t\t\t\t\t\b\b|\n");    // Mover el cursor una linea hacia arriba y cerra la tabla
    //                                           // printf("%*c\n", 30, '|');

    //   eliminarPrimeraPalabra(paterno);
    //   convertirMayusculas(paterno);

    // } while (!validar_letras(paterno));

    if (strlen(paterno) == 0) // Si la cadena esta vacia
    {
        *inicialP = 'X';
        *vocalP = 'X';
        strcpy(paterno, "XXX");
        return;
    }
    else
    {
        convertirMayusculas(paterno);
        *inicialP = paterno[0];

        for (int i = 1; paterno[i] != '\0'; ++i)
        {
            if (paterno[i] == 'A' || paterno[i] == 'E' ||
                paterno[i] == 'I' || paterno[i] == 'O' ||
                paterno[i] == 'U')
            {
                *vocalP = paterno[i];
                return;
            }
        }
    }
}
// * * * * * * * * * * * * * * * *

void letrasMaterno(char *inicialMatr, char *materno)
{
    // do
    // {

    //   // printf("|");
    //   // //TextColor(VERDE);
    //   // printf(" Apellido materno:  ");
    //   // //TextColor(AMARI);
    //   // printf("|  ");
    //   // //TextColor(VERDE);
    //   // fgets(materno, 20, stdin);
    //   // TextColor(AMARI);
    //   materno[strcspn(materno, "\n")] = '\0';
    //   printf("\033[F\t\t\t\t\t\t\b\b|\n");
    //   eliminarPrimeraPalabra(materno);

    // } while (!validar_letras(materno));

    if (strlen(materno) == 0) // Si presiona Enter sin ingresar nada
    {
        *inicialMatr = 'X';
        strcpy(materno, "XXX");
    }
    else
    {
        convertirMayusculas(materno);
        *inicialMatr = materno[0];
    }
}
// * * * * * * * * * * * * * * * *

int obtenerInicialNombre(char *inicial, char *nombre)
{
    char segundoNombre[15];
    // do
    // {
    //   // printf("|");
    //   // //TextColor(VERDE);
    //   // printf(" Primer  nombre:    ");
    //   // //TextColor(AMARI);
    //   // printf("|  ");
    //   // //TextColor(VERDE);
    //   // // scanf("%s", nombre);
    //   // fgets(nombre, 15, stdin);
    //   // TextColor(AMARI);
    //   nombre[strcspn(nombre, "\n")] = '\0';
    //   printf("\033[F\t\t\t\t\t\t\b\b|\n");

    // } while (!validar_letras(nombre));
    eliminarPrimeraPalabra(nombre);

    convertirMayusculas(nombre);

    // do
    // {
    //   // printf("|");
    //   // //TextColor(VERDE);
    //   // printf(" Segundo nombre:    ");
    //   // //TextColor(AMARI);
    //   // printf("|  ");
    //   // //TextColor(VERDE);
    //   // // scanf("%s", segundoNombre);
    //   // fgets(segundoNombre, 15, stdin);
    //   // TextColor(AMARI);
    //   segundoNombre[strcspn(segundoNombre, "\n")] = '\0';
    //   eliminarPrimeraPalabra(segundoNombre);
    //   printf("\033[F\t\t\t\t\t\t\b\b|\n");

    // } while (!validar_letras(segundoNombre));
    eliminarPrimeraPalabra(segundoNombre);

    convertirMayusculas(segundoNombre);
    if (strlen(segundoNombre) == 0)
    {
        *inicial = nombre[0];

        return 0;
    }

    if (strcmp(nombre, "MARIA") == 0 || strcmp(nombre, "MA.") == 0 ||
        strcmp(nombre, "MA") == 0 || strcmp(nombre, "M.") == 0 ||
        strcmp(nombre, "M") == 0 || strcmp(nombre, "JOSE") == 0 ||
        strcmp(nombre, "J.") == 0 || strcmp(nombre, "J") == 0)
    {

        *inicial = segundoNombre[0];
        strcpy(nombre, segundoNombre);
    }
    else
    {
        *inicial = nombre[0];
    }
    return 0;
}
// * * * * * * * * * * * * * * * *

char siguienteConsonante(char *str)
{
    int i, longitud = strlen(str);
    for (i = 1; i < longitud; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            char c = toupper(str[i]);
            if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
            {
                return c; // primera consonante
            }
        }
    }
    return 'X';
}

// * * * * * * * * * * * * * * * *
char elegirsexo(int sexo)
{
    // do
    // {
    // printf("|");
    // //TextColor(VERDE);
    // printf(" sexo (H/M):      ");
    // //TextColor(AMARI);

    // printf("|  ");
    // //TextColor(VERDE);
    // scanf(" %c", &sexo);
    // //TextColor(AMARI);
    // printf("\033[F\t\t\t\t\t\t\b\b|\n");
    // // sexo = toupper(sexo);
    // if (sexo != 'H' && sexo != 'M')
    // {
    //   // TextColor(AMARI);
    //   printf("\033[F\t\t\t\t\t\t\b\b|\n");

    //   printf("|");
    //   // TextColor(ROJO);
    //   printf(" ingrese H para hombre o M para mujer.\n");
    //   // TextColor(AMARI);
    //   printf("\033[F\t\t\t\t\t\t\b\b| ");
    //   system("pause");
    //   printf("\033[1A\033[K");
    //   printf("\033[1A\033[K");
    // }
    // } while (sexo != 'H' && sexo != 'M');
    if (sexo == 1)
    {
        return 'H'; // H para hombre
    }
    else
    {
        if (sexo == 2)
        {
            return 'M'; // M para mujer
        }
        else
        {
            return 'X'; // M para mujer
        }
    }
}
// * * * * * * * * * * * * * * * *
void estadosAbreb(char *estado)
{
    // printf("estado  >%s\n", estado);

    // char estado[3];
    int encontrado = 0;
    do
    {
        // printf("|");
        // //TextColor(VERDE);
        // printf(" Estado (abreviado):");
        // //TextColor(AMARI);

        // printf("|  ");
        // //TextColor(VERDE);
        // scanf("%s", estado);
        // TextColor(AMARI);
        // printf("\033[F\t\t\t\t\t\t\b\b|\n");

        // convertirMayusculas(estado);
        // printf("estado  >%s\n", estado);

        for (int i = 0; i < cantidadEstados; i++)
        {
            if (strcmp(estados[i].abreviatura, estado) == 0)
            {
                // strcpy(abreviaturaEstado, estado);
                encontrado = 1;
                return;
            }
        }
        if (!encontrado)
        {
            // TextColor(AMARI);
            printf("\033[F\t\t\t\t\t\t\b\b|\n");

            printf("|");
            // TextColor(ROJO);
            printf(" * *Estado no valida. Intentelo de nuevo.* * \n");
            // TextColor(AMARI);
            printf("\033[F\t\t\t\t\t\t\b\b| ");
            system("pause");
            printf("\033[1A\033[K");
            printf("\033[1A\033[K");
        }
    } while (!encontrado);
}
// * * * * * * * * * * * * * * * *

// Función para obtener un estado aleatorio
struct Estado obtenerEstadoAleatorio()
{
    srand(time(NULL));                              // Inicializar la semilla de la función rand()
    int indiceAleatorio = rand() % cantidadEstados; // Generar un índice aleatorio
    return estados[indiceAleatorio];                // Devolver el estado correspondiente al índice aleatorio
}

// Función para asignar un estado aleatorio a la variable 'est' de un alumno
void asignarEstadoAleatorio(Alumno *alumno)
{
    // Generar un índice aleatorio para seleccionar un estado aleatorio
    int indiceEstado = random(cantidadEstados);

    // Asignar la abreviatura del estado aleatorio a 'est'
    strcpy(alumno->est, estados[indiceEstado].abreviatura);
}
// * * * * * * * * * * * * * * * *

// * * * * * * * * * * * * * * * *
void generarCURP(char *curp, char *paterno, char *materno, char *nombre, int anio, int mes, int dia, char sexo, char *est)
{
    char inicialP, vocalP;
    char inicMatr;
    char inicialNombre;
    char siglo;
    int ulti;

    letrasPaterno(&inicialP, &vocalP, paterno);
    // printf("paterno>%s\n", paterno);
    // printf("inicial>%c\n", inicialP);
    letrasMaterno(&inicMatr, materno);
    // printf("materno>%s\n", materno);
    // printf("inicial>%c\n", inicMatr);

    obtenerInicialNombre(&inicialNombre, nombre);
    // printf("nombre >%s\n", nombre);
    // printf("nombre >%c\n", inicialNombre);
    // printf("fecha  >%d/%d/%d/\n", anio, mes, dia);

    ingresarFechaNacimiento(&anio, &mes, &dia, &siglo);

    // printf("SIGLO  >%c\n", siglo);
    // printf("<>>>>>>>>>>>>>>>>>>>>>> %d/%d/%d <<<<<<<<<<<<<<<\n", dia, mes, anio);

    estadosAbreb(est);
    generarNumeroAleatorio(&ulti);

    curp[0] = inicialP;

    curp[1] = vocalP;
    curp[2] = inicMatr;
    curp[3] = inicialNombre;
    sprintf(&curp[4], "%02d%02d%02d", anio, mes, dia);
    curp[10] = elegirsexo(sexo);
    curp[11] = est[0];
    curp[12] = est[1];
    curp[13] = siguienteConsonante(paterno);
    curp[14] = siguienteConsonante(materno);
    curp[15] = siguienteConsonante(nombre);
    curp[16] = siglo;
    sprintf(&curp[17], "%d", ulti);

    curp[18] = '\0'; // carácter nulo

    char palAntison[][5] = {"BACA", "FALO", "LOCO", "BUEI", "BUEY", "MAME", "MAMO", "MEAR", "MEAS", "MEON",
                            "MION", "COGE", "COJA", "COJE", "COJI", "COJO", "CULO", "FETO", "GUEY", "JOTO",
                            "KACA", "KACO", "KAGA", "KAGO", "KOGE", "KOJO", "KAKA", "KULO", "MOCO", "MULA",
                            "PEDA", "PEDO", "PENE", "PUTA", "PUTO", "QULO", "RATA", "RUIN"};

    size_t numPalb = sizeof(palAntison) / sizeof(palAntison[0]);
    for (size_t i = 0; i < numPalb; ++i)
    {
        if (strncmp(curp, palAntison[i], 4) == 0) // compara 2 cadenas (primeras 4 posiciones)
        {
            curp[1] = 'X';
            break;
        }
    }
}
