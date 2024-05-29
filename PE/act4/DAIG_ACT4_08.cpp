// Diego Alonso Ibarra Galindo
// CHINCHAMPU (Piedra, Papel, Tijera) (usar condición anidada)
// Elaborado: 25/02/2024 
// DAIG_ACT4_08.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int play, compu;
    srand(time(NULL));
    compu = (rand() % 3) + 1;
    printf("Selecciona tu jugada:\n");
    printf("1 - Piedra\n");
    printf("2 - Papel\n");
    printf("3 - Tijera\n >>");
    scanf("%d", &play);
    if (1 <= play && play <= 3)
    {
        if (play == 1)
        {
            if (compu == 3)
            {
                printf("Ganaste!\n");
            }
            else
            {
                if (compu == 2)
                {
                    printf("Perdiste!\n");
                }
                else
                {
                    printf("Empate.\n");
                }
            }
        }
        else
        {
            if (play == 2)
            {
                if (compu == 1)
                {
                    printf("Ganaste!\n");
                }
                else
                {
                    if (compu == 3)
                    {
                        printf("Perdiste!\n");
                    }
                    else
                    {
                        printf("Empate.\n");
                    }
                }
            }
            else
            {
                if (play == 3)
                {
                    if (compu == 2)
                    {
                        printf("Ganaste!\n");
                    }
                    else
                    {
                        if (compu == 1)
                        {
                            printf("Perdiste!\n");
                        }
                        else
                        {
                            printf("Empate.\n");
                        }
                    }
                }
            }
        }
        printf("La computadora jugo: ");
        if (compu == 1)
        {
            printf("Piedra\n");
        }
        else 
        {
            if (compu == 2)
            {
                printf("Papel\n");
            }
            else
            {
                printf("Tijera\n");
            }
        }
    }
    else
    {
        printf("Jugada no valida\n");
    }
    return 0;
}


