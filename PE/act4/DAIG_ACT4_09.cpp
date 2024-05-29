// Diego Alonso Ibarra Galindo
// CHINCHAMPU (Piedra, Papel, Tijera) (usar selección múltiple)
// Elaborado: 25/02/2024 
// DAIG_ACT4_09.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int play, compu;
    srand(time(NULL));
    compu = (rand() % 3)+1;

    printf("Selecciona tu jugada:\n");
    printf("1.- Piedra\n");
    printf("2.- Papel\n");
    printf("3.- Tijera\n >>");
    scanf("%d", &play);

    if (1 <= play && play <= 3)
    {
        if ((play == 1 && compu == 3) || (play == 2 && compu == 1) || (play == 3 && compu == 2))
        {
            printf("Ganaste!\n");
        }
        else 
        {    
            if ((play == 1 && compu == 1) || (play == 2 && compu == 2) || (play == 3 && compu == 3))
            {
                printf("Empate.\n");
            }
            else
            {
                printf("Perdiste!\n");
            }
        }
        printf("La computadora jugo: ");
        switch (compu)
        {
        case 1:
            printf("Piedra\n");
            break;
        case 2:
            printf("Papel\n");
            break;
        case 3:
            printf("Tijera\n");
            break;
        }
    }
    else
    {
        printf("Jugada invalida\n");
    }

    return 0;
}
