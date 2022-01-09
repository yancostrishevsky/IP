#include <stdio.h>
int check(char tab[3][3])
{
    if (tab[0][0] == 'x' && tab[0][1] == 'x' && tab[0][2] == 'x')
        return 1000;
    if (tab[1][0] == 'x' && tab[1][1] == 'x' && tab[1][2] == 'x')
        return 1000;
    if (tab[2][0] == 'x' && tab[2][1] == 'x' && tab[2][2] == 'x')
        return 1000;
    if (tab[0][0] == 'x' && tab[1][0] == 'x' && tab[2][0] == 'x')
        return 1000;
    if (tab[0][1] == 'x' && tab[1][1] == 'x' && tab[2][1] == 'x')
        return 1000;
    if (tab[0][2] == 'x' && tab[1][2] == 'x' && tab[2][2] == 'x')
        return 1000;
    if (tab[0][0] == 'x' && tab[1][1] == 'x' && tab[2][2] == 'x')
        return 1000;
    if (tab[0][2] == 'x' && tab[1][1] == 'x' && tab[2][0] == 'x')
        return 1000;
    if (tab[0][0] == 'o' && tab[0][1] == 'o' && tab[0][2] == 'o')
        return -1000;
    if (tab[1][0] == 'o' && tab[1][1] == 'o' && tab[1][2] == 'o')
        return -1000;
    if (tab[2][0] == 'o' && tab[2][1] == 'o' && tab[2][2] == 'o')
        return -1000;
    if (tab[0][0] == 'o' && tab[1][0] == 'o' && tab[2][0] == 'o')
        return -1000;
    if (tab[0][1] == 'o' && tab[1][1] == 'o' && tab[2][1] == 'o')
        return -1000;
    if (tab[0][2] == 'o' && tab[1][2] == 'o' && tab[2][2] == 'o')
        return -1000;
    if (tab[0][0] == 'o' && tab[1][1] == 'o' && tab[2][2] == 'o')
        return -1000;
    if (tab[0][2] == 'o' && tab[1][1] == 'o' && tab[2][0] == 'o')
        return -1000;

    return 0;
}
int generator(char tab[3][3], int ctr, int *x, int *y)
{
    int score, xm, ym, px, py, a, b, ctr2 = 1;
    score = check(tab);
    if (ctr <= 0 || score == 1000 || score == -1000)
        return score;
    xm = -2000;
    ym = 2000;
    if (ctr % 2 == 0)
    {
        for (px = 0; px < 3; px++)
            for (py = 0; py < 3; py++)
                if (tab[px][py] == ' ')
                {
                    tab[px][py] = 'x';
                    score = generator(tab, ctr - 1, &a, &b);
                    tab[px][py] = ' ';
                    if (score > xm)
                    {
                        xm = score;
                        *x = px;
                        *y = py;
                    }
                    ctr2 = 0;
                }
        if (ctr2)
            return 0;
        else
            return xm;
    }
    else
    {
        for (px = 0; px < 3; px++)
            for (py = 0; py < 3; py++)
                if (tab[px][py] == ' ')
                {
                    tab[px][py] = 'o';
                    score = generator(tab, ctr - 1, &a, &b);
                    tab[px][py] = ' ';
                    if (score < ym)
                    {
                        ym = score;
                        *x = px;
                        *y = py;
                    }
                    ctr2 = 0;
                }
        if (ctr2)
        {
            return 0;
        }
        else
            return ym;
    }
}
void printboard(char tab[3][3])
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            printf(" |");
            printf("%3c", tab[x][y]);
        }
        printf(" | ");
        printf("\n");
        printf(" ----------------");
        printf("\n");
    }
}
void board(char tab[3][3])
{
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", tab[0][0], tab[0][1], tab[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", tab[1][0], tab[1][1], tab[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", tab[2][0], tab[2][1], tab[2][2]);

    printf("     |     |     \n\n");
}

int main()
{
    char tab[3][3];
    int x, y, scr, ctr = 0;
    for (x = 0; x < 3; x++)
        for (y = 0; y < 3; y++)
            tab[x][y] = ' ';

    while (1)
    {
        generator(tab, 10, &x, &y);

        tab[x][y] = 'x';

        board(tab);
        scr = check(tab);
        if (scr == 1000)
        {
            printf("     YOU LOSE\n");
            return 0;
        }
        if (scr == -1000)
        {
            printf("     YOU WIN\n");
            return 0;
        }
        if (ctr++ == 6)
        {
            printf("     DRAW\n");
            return 0;
        }
        printf("Enter your move as coordinations (row, col)\n");
        /*do
        {
            scanf("%d %d", &x, &y);
        } while (tab[x][y] != ' ');
        {
            printf("Enter correct possition!\n");
            scanf("%d %d", &x, &y);
        }*/
        scanf("%d %d", &x, &y);
        if (tab[x][y] != ' ')
        {
            while (tab[x][y] != ' ')
            {
                printf("Enter correct possition!\n");
                scanf("%d %d", &x, &y);
            }
        }

        tab[x][y] = 'o';
        scr = check(tab);
        if (scr == -1000)
        {
            printf("YOU LOSE");
            return 0;
        }
        if (ctr++ == 6)
        {
            printf("DRAW");
            return 0;
        }
    }
    return 0;
}
