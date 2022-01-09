#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define LOSE -1000
#define WIN 1000
#define EMPTY 12
int MAX_KIER[] = {8, 8, 4, 4, 8, 3, 8, 8, 4, 4, 8, 3, 0};
int MAX_ODL[] = {2, 8, 8, 8, 2, 2, 2, 8, 8, 8, 2, 2, 0};
int WX[12][8] = {{0, 1, 1, 1, 0, -1, -1, -1}, {0, 1, 1, 1, 0, -1, -1, -1}, {0, 1, 0, -1}, {1, 1, -1, -1}, {1, 2, 2, 1, -1, -2, -2, -1}, {-1, 0, 1}, {0, 1, 1, 1, 0, -1, -1, -1}, {0, 1, 1, 1, 0, -1, -1, -1}, {0, 1, 0, -1}, {1, 1, -1, -1}, {1, 2, 2, 1, -1, -2, -2, -1}, {-1, 0, 1}};
int WY[12][8] = {{-1, -1, 0, 1, 1, 1, 0, -1}, {-1, -1, 0, 1, 1, 1, 0, -1}, {-1, 0, 1, 0}, {-1, 1, 1, -1}, {-2, -1, 1, 2, 2, 1, -1, -2}, {-1, -1, -1}, {-1, -1, 0, 1, 1, 1, 0, -1}, {-1, -1, 0, 1, 1, 1, 0, -1}, {-1, 0, 1, 0}, {-1, 1, 1, -1}, {-2, -1, 1, 2, 2, 1, -1, -2}, {1, 1, 1}};
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int ocena(char plansza[8][8])
{
    int ctr = 0;
    int score[13] = {LOSE, -9, -5, -3, -3, -1, WIN, 9, 5, 3, 3, 1, 0};
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            ctr += score[plansza[i][j]];
        }
    }
    return ctr;
}
/*
 0-Krol
 1-Hetman
 2-Wieza
 3-Goniec
 4-Skoczek
 5-Pion
 6-krol
 7-hetman
 8-wieza
 9-goniec
 10-skoczek
 11-pion
 12-puste
 */

int minimax(char board[8][8], int tryb, int *x, int *y, int *o, int *k, int alfa, int beta)
{

    int px, py, dir, dist, dx, dy, kpom, opom, xpom, ypom, wmax = 2 * LOSE, wmin = 2 * WIN;
    int wynik = ocena(board);
    int eob, sob;

    if (tryb == 0 || 2 * wynik > WIN || 2 * wynik < LOSE)
    {
        return wynik;
    }
    if (tryb % 2 == 0)
    {
        for (px = 0; px < 8; px++) //dwie pętle sprawdzaja kazde pole oraz if szukajacy figur komputera
        {
            for (py = 0; py < 8; py++)
            {
                if (board[px][py] >= 6 && board[px][py] < 12) //sprawdza czy na polu stoi figura komputera
                {

                    for (dir = 0; dir < MAX_KIER[board[px][py]]; dir++) //petla mozliwosci ruchow
                    {
                        for (dist = 1; dist < MAX_ODL[board[px][py]]; dist++) //petla dystansu o ile moze sie przesunac
                        {
                            dx = (dist - 1) * WX[board[px][py]][dir];
                            dy = (dist - 1) * WY[board[px][py]][dir];
                            if (dist >= 2 && board[px + dx][py + dy] != EMPTY)
                            {
                                break;
                            }
                            dx = dist * WX[board[px][py]][dir];
                            dy = dist * WY[board[px][py]][dir];
                            if (0 <= px + dx && px + dx < 8 && 0 <= py + dy && py + dy < 8)
                            {
                                if (board[px][py] != 11 || ((dx == 0 && board[px + dx][py + dy] == EMPTY) || (dx != 0 && board[px + dx][py + dy] < 6)))
                                {
                                    if (board[px + dx][py + dy] < 6 || board[px + dx][py + dy] == EMPTY)
                                    {
                                        int last = board[px + dx][py + dy];
                                        int actual = board[px][py];
                                        board[px + dx][py + dy] = board[px][py];
                                        board[px][py] = EMPTY;
                                        if (board[px + dx][py + dy] == 11 && py + dy == 7)
                                        {
                                            board[px + dx][py + dy] = 7;
                                        }
                                        wynik = minimax(board, tryb - 1, &xpom, &ypom, &opom, &kpom, alfa, beta);

                                        if (wmax < wynik)
                                        {
                                            wmax = wynik;
                                            *x = px;
                                            *y = py;
                                            *o = dist;
                                            *k = dir;
                                        }

                                        board[px][py] = actual;
                                        board[px + dx][py + dy] = last;
                                        alfa = max(alfa,wynik);
                                        if(beta<=alfa)
                                            break;

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return wmax;
    }
    else
    {
        for (px = 0; px < 8; px++) //dwie pętle sprawdzaja kazde pole oraz if szukajacy figur gracza
        {
            for (py = 0; py < 8; py++)
            {
                if (board[px][py] < 6)
                {
                    for (dir = 0; dir < MAX_KIER[board[px][py]]; dir++)
                    {
                        for (dist = 1; dist < MAX_ODL[board[px][py]]; dist++)
                        {
                            dx = (dist - 1) * WX[board[px][py]][dir];
                            dy = (dist - 1) * WY[board[px][py]][dir];
                            if (dist >= 2 && board[px + dx][py + dy] != EMPTY)
                            {
                                break;
                            }
                            dx = dist * WX[board[px][py]][dir];
                            dy = dist * WY[board[px][py]][dir];
                            if (0 <= px + dx && px + dx < 8 && 0 <= py + dy && py + dy < 8)
                            {
                                if (board[px][py] != 11 || ((dx == 0 && board[px + dx][py + dy] == EMPTY) || (dx != 0 && board[px + dx][py + dy] >= 6)))
                                {
                                    if (board[px + dx][py + dy] >= 6 || board[px + dx][py + dy] == EMPTY)
                                    {
                                        int last = board[px + dx][py + dy];
                                        int act = board[px][py];
                                        board[px + dx][py + dy] = board[px][py];
                                        board[px][py] = EMPTY;
                                        if (board[px + dx][py + dy] == 5 && py + dy == 0)
                                        {
                                            board[px + dx][py + dy] = 1;
                                        }
                                        wynik = minimax(board, tryb - 1, &xpom, &ypom, &opom, &kpom, alfa, beta);

                                        if (wmin > wynik)
                                        {
                                            wmin = wynik;
                                            *x = px;
                                            *y = py;
                                            *o = dist;
                                            *k = dir;
                                        }
                                        board[px][py] = act;
                                        board[px + dx][py + dy] = last;
                                        beta = min(beta,wynik);
                                        if(beta <=alfa)
                                            break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return wmin;
    }
}


void print_board(char tab[8][8])
{
    char fig[20] = "KHWGSPkhwgsp";
    for (int i = 0; i < 8; i++)
    {

        printf("_____________________________________________     \n");
        //printf("|     |     |     |     |     |     |     |     | \n");
        printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  | \n", fig[tab[i][0]], fig[tab[i][1]], fig[tab[i][2]], fig[tab[i][3]], fig[tab[i][4]], fig[tab[i][5]], fig[tab[i][6]], fig[tab[i][7]]);
        //printf("|     |     |     |     |     |     |     |     | \n");
    }
    printf("_____________________________________________     \n");
}
/*
 0-Krol
 1-Hetman
 2-Wieza
 3-Goniec
 4-Skoczek
 5-Pion
 6-krol
 7-hetman
 8-wieza
 9-goniec
 10-skoczek
 11-pion
 12-puste
 */

int main()
{
    char board[8][8] = {
            8,
            11,
            12,
            12,
            12,
            12,
            5,
            2,
            10,
            11,
            12,
            12,
            12,
            12,
            5,
            4,
            9,
            11,
            12,
            12,
            12,
            12,
            5,
            3,
            6,
            11,
            12,
            12,
            12,
            12,
            5,
            0,
            7,
            11,
            12,
            12,
            12,
            12,
            5,
            1,
            9,
            11,
            12,
            12,
            12,
            12,
            5,
            3,
            10,
            11,
            12,
            12,
            12,
            12,
            5,
            4,
            8,
            11,
            12,
            12,
            12,
            12,
            5,
            2,
    };

    int x, y, o, k, dx, dy, x2, y2, szach;
    int gniazdo, status, gniazdo2, dlugosc, nr=0, end=1;
    int xy[4]={100,100,100,100};
    struct sockaddr_in ser;
    struct sockaddr cli;
    gniazdo = socket(AF_INET, SOCK_STREAM, 0);

    if(gniazdo == -1)
    {
        fputs("blad socket\n", stdout);
        return 0;
    }

    ser.sin_family = AF_INET;
    ser.sin_port = htons(8044);
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
        while (1)
        {
            minimax(board, 4, &x, &y, &o, &k, -1000000, 1000000);
            dx = o * WX[board[x][y]][k];
            dy = o * WY[board[x][y]][k];
            board[x + dx][y + dy] = board[x][y];
            board[x][y] = EMPTY;
            if (board[x + dx][y + dy] == 11 && y + dy == 7)
                board[x + dx][y + dy] = 7;
            //print_board(board);
            szach = minimax(board, 2, &x, &y, &o, &k, -1000000, 1000000);
            if (szach >= WIN)
            {
                board[0][0]='l';
                status = send(gniazdo2, board, sizeof(board), 0);
                end = 0;
                break;
            }
            status = send(gniazdo2, board, sizeof(board), 0);
            status = recv(gniazdo2, xy, sizeof xy, 0);

            board[xy[2]][xy[3]] = board[xy[0]][xy[1]];
            board[xy[0]][xy[1]] = EMPTY;
            if (board[xy[2]][xy[3]] == 5 && y2 == 0)
            {
                board[xy[2]][xy[3]] = 1;
            }
            //print_board(board);
            szach = minimax(board, 2, &x, &y, &o, &k, -1000000, 1000000);
            if (szach <= LOSE)
            {
                board[0][0]='w';
                end = 0;
                status = send(gniazdo2, board, sizeof(board), 0);
                break;
            }
        }
    }
    close(gniazdo);
}
