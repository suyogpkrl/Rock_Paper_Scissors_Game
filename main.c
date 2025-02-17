#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
int game(char, char);
int main()
{
    int n, ps = 0, cs = 0, d = 0;
    char y, c, result, ch = 'y', line[100];
    FILE *file = fopen("scores.txt", "w");

    while (ch == 'y')
    {
        // ramdomizer ko lai code
        srand(time(NULL));
        n = rand() % 100;
        // 33 samma rock, 33-66 samma paper and 66-99 samma scissor
        if (n < 33)
        {
            c = 'r';
        }
        else if ((n > 33) && (n < 66))
        {
            c = 'p';
        }
        else if ((n > 66) && (n < 99))
        {
            c = 's';
        }
    // until user enters r, s and p try again
    start:
        printf("\n\nEnter r for rock \nEnter p for paper\nEnter s for scissor:\n");
        y = getche();
        if ((y != 'r') && (y != 's') && (y != 'p'))
        {
            printf("Try again");
            goto start;
        }
        // function call for result of game
        result = game(y, c);
        if (result == 2)
        {
            printf("\n\n Game Draw!");
            d++;
        }
        else if (result == 1)
        {
            printf("\n\n WOW! You have won");
            ps++;
        }
        else if (result == 0)
        {
            printf("\n\nSyad! you have lost");
            cs++;
        }
        printf("\nYOu choose : %c and Computer choose : %c\n", y, c);
        printf("\n Do you want to continue if Yes press [y]\n");
        ch = getche();

        fprintf(file, "Player:%d\tComputer:%d\tDraw:%d\n", ps, cs, d); // Write text to file
    }
    fclose(file);
    printf("\n\nYou desided no terminate the game");

    file = fopen("scores.txt", "r");
    printf("\n--- Scores from scores.txt ---\n");
    fscanf(file, "Player: %d\nComputer: %d\nDraw: %d\n", ps, cs, d);
    printf("Players win count=%d\nComputers win count=%d\nDraw count=%d", ps, cs, d);
    fclose(file);
}

int game(char y, char c)
{
    // 2 is for draw, 1 is for win and 0 is for loss

    if (y == c)
    {
        return 2;
    }
    else if ((y == 's') && (c == 'p'))
    {
        return 1;
    }
    else if ((y == 'p') && (c == 'r'))
    {
        return 1;
    }
    else if ((y == 'r') && (c == 's'))
    {
        return 1;
    }
    else if ((y == 'p') && (c == 's'))
    {
        return 0;
    }
    else if ((y == 'r') && (c == 'p'))
    {
        return 0;
    }
    else if ((y == 's') && (c == 'r'))
    {
        return 0;
    }
}