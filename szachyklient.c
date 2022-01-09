#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
void board(char tab[8][8])
{
    char fig[20] = "KHWGSPkhwgsp";
    for (int i = 0; i < 8; i++)
    {

        printf("_____________________________________________     \n");
        //printf("|     |     |     |     |     |     |     |     | \n");
        printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  | \n", fig[tab[0][i]], fig[tab[1][i]], fig[tab[2][i]], fig[tab[3][i]], fig[tab[4][i]], fig[tab[5][i]], fig[tab[6][i]], fig[tab[7][i]]);
        //printf("|     |     |     |     |     |     |     |     | \n");
    }
    printf("_____________________________________________     \n");
}

int main(void)
{
    int status, gniazdo;
    struct sockaddr_in ser;
    char buf[2000];
    char tab[8][8];
    int xy[4];

    gniazdo = socket(AF_INET, SOCK_STREAM, 0);
    if(gniazdo == -1)
    {
        fputs("dziala\n", stdout);
        return 0;
    }

    ser.sin_family = AF_INET;
    ser.sin_port = htons(8044);
    ser.sin_addr.s_addr = inet_addr("127.0.0.1");

    status = connect(gniazdo, (struct sockaddr*)&ser, sizeof ser);
    if(status == -1)
    {
        printf("blad connect\n");
        return 0;
    }



    while(1)
    {
        status = recv(gniazdo, tab, (sizeof tab), 0);

        if(tab[0][0]=='l')
        {
            board(tab);
            printf("Przegrales!\n");
            break;
        }

        else if(tab[0][0]=='w')
        {
            board(tab);
            printf("Wygrales!\n");
            break;
        }

        else if(tab[0][0]=='d')
        {
            board(tab);
            printf("Remis!\n");
            break;
        }

        board(tab);
        printf("Podaj ruch:\n");

        scanf("%d %d %d %d",&xy[0], &xy[1],&xy[2],&xy[3]);
        status = send(gniazdo, xy, sizeof(xy)-1, 0);

    }
    close(gniazdo);
    return 0;

}

