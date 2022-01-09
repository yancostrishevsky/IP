
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
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

    int gniazdo, status, gniazdo2, dlugosc, nr=0, end=1;
    int xy[2]={100,100};
    char tab[3][3];
    int x, y, scr, ctr = 0;

    for (x = 0; x < 3; x++)
        for (y = 0; y < 3; y++)
            tab[x][y] = ' ';

    struct sockaddr_in ser;
    struct sockaddr cli;
    gniazdo = socket(AF_INET, SOCK_STREAM, 0);

    if(gniazdo == -1)
    {
        fputs("blad socket\n", stdout);
        return 0;
    }

    ser.sin_family = AF_INET;
    ser.sin_port = htons(8040);
    ser.sin_addr.s_addr = inet_addr("127.0.0.1");

    status = bind(gniazdo, (struct sockaddr*)&ser, sizeof ser);

    if(status == -1)
    {
        printf("blad bind\n");
        return 0;
    }

    status = listen(gniazdo, 10);

    if(status == -1)
    {
        printf("blad sluchania\n");
        return 0;
    }

    while(end) {
        dlugosc = sizeof cli;
        gniazdo2 = accept(gniazdo, (struct sockaddr *) &cli, (socklen_t * ) & dlugosc);

        if (gniazdo2 == -1)
        {
            printf("blad accept\n");
            return 0;
        }

        while (1) {
            generator(tab, 10, &x, &y);

            tab[x][y] = 'x';
            scr = check(tab);

            if (scr == 1000)
            {
                tab[0][0]='l';
                status = send(gniazdo2, tab, sizeof(tab), 0);
                end = 0;
                break;
            }

            if (scr == -1000)
            {
                tab[0][0]='w';
                end = 0;
                status = send(gniazdo2, tab, sizeof(tab), 0);
                break;
            }

            if (ctr++ == 6)
            {
                tab[0][0]='d';
                status = send(gniazdo2, tab, sizeof(tab), 0);
                end = 0;
                break;
            }

            status = send(gniazdo2, tab, sizeof(tab), 0);
            status = recv(gniazdo2, xy, sizeof xy, 0);

            printf("Otrzymalem:\n");
            printf("%d %d\n",xy[0],xy[1]);
            tab[xy[0]][xy[1]]='o';
            scr = check(tab);

            if (scr == -1000)
            {
                tab[0][0]='l';
                end = 0;
                status = send(gniazdo2, tab, sizeof(tab), 0);
                break;
            }

            if (ctr++ == 6)
            {
                tab[0][0]='d';
                end = 0;
                status = send(gniazdo2, tab, sizeof(tab), 0);
                break;
            }
        }

       // close(gniazdo2);
    }
    close(gniazdo);
    return 0;
}



