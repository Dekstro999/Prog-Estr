// _FUN.h

#include "_str.h"

// Define colores
#define DEF 7    // Gris claro
#define AZUL 9   // Azul
#define VERDE 10 // Verde
#define CYAN 11  // Cian
#define ROJO 12  // Rojo
#define AMARI 14 // Aarillo

// * * * * * PROTOTIPOS * * * * * *
void pause(void);
void cls(void);
void TextColor(int color);
void buffer(void);
void borrarlinea(int num);
void error(const char *error);
int randomR(int inicio, int fin);
int random(int num);

void anima(int seconds);
int validar_letras(char *cadena);
void enter(char buffer[], Alumno alumnos[], int *numAlumnos, const char campo[]);
int validarMatricula();
int validar_num(int menor, int mayor);
char elegirSexo();

int esFechaValida(int anio, int mes, int dia);
void generarFechaAleatoria(int *anio, int *mes, int *dia);
int calcularEdad(int anioNacimiento, int mesNacimiento, int diaNacimiento);
void ingresarFechaNacimiento(int *anio, int *mes, int *dia, char *siglo);

void generarNumeroAleatorio(int *ultiNum);

void convertirMayusculas(char *cadena);

// * * * * DESARROLLO DE FUNCIONES * * * * //
void pause(void)
{
    system("pause");
}
void cls(void)
{
    system("cls");
}

void TextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void error(const char *error)
{
    TextColor(ROJO);
    printf("     x x x > %s < x x x     \n",error);
    TextColor(DEF);
    system("pause");
    borrarlinea(2);
}
void borrarlinea(int num)
{
    for (int i = 1; i <= num; i++)
    {
        printf("\033[1A\033[K");
    }
}
void buffer(void)
{
    // Limpiar el bufer del teclado
    while (getchar() != '\n')
        ;
}
// random en rango inicial - final
int randomR(int inicio, int fin)

{
    int random = rand() % (fin - inicio + 1) + inicio;
    return random;
}
int random(int num)
{
    int random = rand() % (num);
    return random;
}
void anima(int seconds)
{
    TextColor(AMARI);
    char caracteres[] = "/-\\|"; // Caracteres de la animación
    int num_caracteres = sizeof(caracteres) - 1;
    int tiempo_animacion = 200;
    int i;
    seconds = seconds * 5;
    printf(" ");

    for (i = 0; i < seconds; i++)
    {
        printf(" \b\b\b%c ", caracteres[i % num_caracteres]);
        fflush(stdout);          // Asegura que se muestren los caracteres
        Sleep(tiempo_animacion); // Espera antes de mostrar el siguiente caracter
    }
    borrarlinea(1);
    TextColor(DEF);
}

int validar_letras(char *cadena)
{
    convertirMayusculas(cadena);
    // Reemplazar antes de la validación
    for (int i = 0; cadena[i] != '\0'; ++i)
    {

        switch ((unsigned char)cadena[i])
        {
        case 160: // Á
            cadena[i] = 'A';
            break;
        case 130: // É
            cadena[i] = 'E';
            break;
        case 161: // i
            cadena[i] = 'I';
            break;
        case 162: // Ó
            cadena[i] = 'O';
            break;
        case 163: // u
            cadena[i] = 'U';
            break;
        case 129: // Ü
            cadena[i] = 'U';
            break;
        case 164: // Ñ
            cadena[i] = 'X';
            break;
        }
    }
    // printf("final.%s|\n", cadena); // Mensaje de depuración
    for (int i = 0; cadena[i] != '\0'; ++i)
    {
        if (!isalpha(cadena[i]) && cadena[i] != '\n')
        {

            TextColor(ROJO);
            printf("     x x x > INGRESE SOLO LETRAS < x x x     ");
            TextColor(DEF);
            system("pause");
            borrarlinea(2);
            return 0;
        }
    }
    return 1;
}
// * * * * * * * * * * * * * * * *
// funcion para ver si se ngrso enter y remplazar po xxx
void enter(char buffer[], Alumno alumnos[], int *numAlumnos, const char campo[])
{
    if (buffer[0] != '\n')
    { // Si el usuario ingresó algo que no es solo Enter
        if (strcmp(campo, "nombre") == 0)
        {
            sscanf(buffer, "%c", alumnos[*numAlumnos].nombre.nombre); // Almacenar campo nombre
        }
        else if (strcmp(campo, "apPaterno") == 0)
        {
            sscanf(buffer, "%s", alumnos[*numAlumnos].nombre.apMaterno);
        }
        else if (strcmp(campo, "apMaterno") == 0)
        {
            sscanf(buffer, "%s", alumnos[*numAlumnos].nombre.apMaterno);
        }
    }
    else
    { // Si el usuario solo presionó Enter
        if (strcmp(campo, "nombre") == 0)
        {
            strcpy(alumnos[*numAlumnos].nombre.nombre, "XXXXXX");
        }
        else if (strcmp(campo, "apPaterno") == 0)
        {
            strcpy(alumnos[*numAlumnos].nombre.apPaterno, "XXXXXX");
        }
        else if (strcmp(campo, "apMaterno") == 0)
        {
            strcpy(alumnos[*numAlumnos].nombre.apMaterno, "XXXXXX");
        }
    }
}

int validarMatricula()
{
    char matricula[10];

    scanf("%9s", matricula);

    while (getchar() != '\n')
        ;
    for (int i = 0; matricula[i] != '\0'; i++)

    {
        if (!isdigit(matricula[i]))
        {

            printf("Por favor, ingrese solo numeros enteros para la matricula.  ");
            system("pause");
            borrarlinea(2);
            return -1;
        }
    }

    if (strlen(matricula) != 6)
    {
        printf("La longitud de la matricula debe ser de 6 digitos.");
        system("pause");
        borrarlinea(2);
        return -1;
    }

    int matricula_num = atoi(matricula);

    return matricula_num;
}

int validar_num(int menor, int mayor)
{
    char num[10];
    int valid;
    do
    {
        valid = 1;
        scanf("%9s", num);
        while (getchar() != '\n')
            ;

        for (int i = 0; num[i] != '\0'; i++)
        {
            if (!isdigit(num[i]))
            {
                TextColor(AMARI);
                printf("\033[F\t\t\t\t\t\t\b\b|\n");
                printf("|");
                TextColor(ROJO);
                printf("**Invalido. Por favor ingrese solo numeros.**");
                TextColor(DEF);
                printf("| ");
                system("pause");
                borrarlinea(2); // printf("\033[1A\033[K");

                valid = 0;
                break;
            }
        }
        int numero = atoi(num);
        if (valid == 1)
        {
            if (numero < menor || numero > mayor)
            {
                TextColor(AMARI);
                printf("\033[F\t\t\t\t\t\t\b\b|\n");
                printf("|");
                TextColor(ROJO);
                printf("**El numero debe estar entre %d y %d.**", menor, mayor);
                TextColor(DEF);
                printf("| ");
                system("pause");
                borrarlinea(2);

                valid = 0;
            }
        }

    } while (!valid);
    int numero = atoi(num);

    return numero;
}

char elegirSexo()
{
    char genero;
    do
    {
        printf("|");
        // TextColor(VERDE);
        printf(" Genero (M/F):      ");
        // TextColor(AMARI);

        printf("|  ");
        // TextColor(VERDE);
        scanf(" %c", &genero);
        while (getchar() != '\n')
            ; // Limpia el bufer de entrada

        genero = toupper(genero);

        if (genero != 'M' && genero != 'F')
        {
            printf(" | ");
            // TextColor(AMARI);
            printf("\033[F\t\t\t\t\t\t\b\b|\n");
            printf("|");
            TextColor(ROJO);
            printf(" Ingrese M para hombre o F para mujer.\n");
            // TextColor(AMARI);
            printf("\033[F\t\t\t\t\t\t\b\b| ");
            system("pause");
            printf("\033[1A\033[K");
            printf("\033[1A\033[K");
        }
    } while (genero != 'M' && genero != 'F');

    return genero;
}

// * * * * * * * * * * * * * * * *
int esFechaValida(int anio, int mes, int dia)
{
    time_t tiempoActual;
    struct tm *infoTiempo;
    time(&tiempoActual);
    infoTiempo = localtime(&tiempoActual);

    int anioActual = infoTiempo->tm_year + 1900;
    int mesActual = infoTiempo->tm_mon + 1;
    int diaActual = infoTiempo->tm_mday;

    if (anio > anioActual)
    {
        return 0;
    }
    else
    {
        if (anio == anioActual && mes > mesActual)
            return 0;
        else
        {
            if (anio == anioActual && mes == mesActual && dia > diaActual)
                return 0;
        }
    }

    return 1;
}

// Función para generar una fecha aleatoria válida
void generarFechaAleatoria(int *anio, int *mes, int *dia)
{
    time_t tiempoActual;
    struct tm *infoTiempo;
    time(&tiempoActual);
    infoTiempo = localtime(&tiempoActual);

    // Obtener el año actual
    int anioActual = infoTiempo->tm_year + 1900;

    int anioAleatorio = randomR(1970, anioActual);

    int mesAleatorio = rand() % 12 + 1;

    int maxDia;
    if (mesAleatorio == 2)
    {
        // Febrero
        if ((anioAleatorio % 4 == 0 && anioAleatorio % 100 != 0) || anioAleatorio % 400 == 0)
        {
            // Año bisiesto
            maxDia = 29;
        }
        else
        {
            maxDia = 28;
        }
    }
    else
    {
        if (mesAleatorio == 4 || mesAleatorio == 6 || mesAleatorio == 9 || mesAleatorio == 11)
        {
            // Abril, Junio, Septiembre, Noviembre
            maxDia = 30;
        }
        else
        {
            // Resto de los meses
            maxDia = 31;
        }
    }

    int diaAleatorio = rand() % maxDia + 1;

    if (!esFechaValida(anioAleatorio, mesAleatorio, diaAleatorio))
    {
        generarFechaAleatoria(anio, mes, dia);
    }
    else
    {
        *anio = anioAleatorio;
        *mes = mesAleatorio;
        *dia = diaAleatorio;
    }
}
int calcularEdad(int anioNacimiento, int mesNacimiento, int diaNacimiento)
{
    time_t tiempoActual;
    struct tm *infoTiempo;
    time(&tiempoActual);
    infoTiempo = localtime(&tiempoActual);

    // Obtener el año, mes y día actual
    int anioActual = infoTiempo->tm_year + 1900;
    int mesActual = infoTiempo->tm_mon + 1;
    int diaActual = infoTiempo->tm_mday;

    int edad = anioActual - anioNacimiento;

    if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento))
    {
        edad--;
    }

    return edad;
}

// * * * * * * * * * * * * * * * *
void ingresarFechaNacimiento(int *anio, int *mes, int *dia, char *siglo)
{
    int diasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int errores = 0;
    do
    {
        // printf("|- - - - Ingrese la fecha de nacimiento - - - | \n");

        do
        {
            // printf("|");
            // TextColor(VERDE);
            // printf(" > A%co (YYYY):      ", 164);
            // TextColor(AMARI);
            // printf("|  ");
            // TextColor(VERDE);

            //*anio = validar_num(1800, 2100);
            // printf("|- - - - PASO - - - | \n");

            TextColor(AMARI);
            printf("\033[F\t\t\t\t\t\t\b\b|\n");
            if (*anio == -1)
                continue; // Repetir si no es válido
            if (*anio != -1 && *anio < 1500)
            {
                TextColor(ROJO);
                printf("\033[F\t\t\t\t\t\t\b*\n");
                TextColor(AMARI);
            }
            errores++;
        } while (*anio == -1 || *anio < 1500);

        if (*anio < 2000)
        {
            *siglo = '0';
        }
        else
        {
            if (*anio < 2010)
            {
                *siglo = 'A';
            }
            else
            {
                if (*anio < 2020)
                {
                    *siglo = 'B';
                }
                else
                {
                    if (*anio < 2030)
                    {
                        *siglo = 'C';
                    }
                }
            }
        }
        if ((*anio % 4 == 0 && *anio % 100 != 0) || (*anio % 400 == 0))
            diasPorMes[2] = 29;
        else
            diasPorMes[2] = 28;

        do
        {
            // printf("|");
            // TextColor(VERDE);
            // printf(" > Mes (MM):        ");
            // TextColor(AMARI);
            // printf("|  ");
            // TextColor(VERDE);

            // *mes = validar_num(1, 12);
            // TextColor(AMARI);
            // printf("\033[F\t\t\t\t\t\t\b\b|\n");

            if (*mes == -1)
                continue;
            if (*mes != -1 && (*mes < 1 || *mes > 12))
            {
                TextColor(ROJO);
                printf("\033[F\t\t\t\t\t\t\b*\n");
                TextColor(AMARI);
            }

            errores++;

        } while (*mes == -1 || *mes < 1 || *mes > 12);

        do
        {
            // printf("|");
            // TextColor(VERDE);
            // printf(" > Dia (DD):        ");
            // TextColor(AMARI);
            // printf("|  ");
            // TextColor(VERDE);

            // *dia = validar_num(1, 31);
            // TextColor(AMARI);
            // printf("\033[F\t\t\t\t\t\t\b\b|\n");
            if (*dia == -1)
                continue;
            if (*dia != -1 && (*dia < 1 || *dia > diasPorMes[*mes]))
            {
                TextColor(ROJO);
                printf("\033[F\t\t\t\t\t\t\b*\n");
                TextColor(AMARI);
            }
            errores++;

        } while (*dia == -1 || *dia < 1 || *dia > diasPorMes[*mes]);

        if (!esFechaValida(*anio, *mes, *dia)) // Validar la fecha ingresada
        {
            TextColor(AMARI);
            printf("\033[F\t\t\t\t\t\t\b\b|\n");

            printf("|");
            TextColor(ROJO);
            printf(" -  Ingrese una fecha anterior a la actual. - \n");
            TextColor(AMARI);
            printf("\033[F\t\t\t\t\t\t\b\b| ");
            system("pause");

            for (int i = 0; i <= errores + 1; i++)
            {
                printf("\033[1A\033[K");
            }
        }
    } while (!esFechaValida(*anio, *mes, *dia));
    *anio = *anio % 100;

    // printf("anio   >%d\n", *anio);
    // printf("mes    >%d\n", *mes);
    // printf("dia    >%d\n", *dia);
}

void generarNumeroAleatorio(int *ultiNum)
{
    *ultiNum = rand() % 10; // aleatorio entre 0 y 9
}

void convertirMayusculas(char *cadena)
{
    for (int i = 0; cadena[i] != '\0'; ++i)
    {
        cadena[i] = toupper(cadena[i]);
    }
}