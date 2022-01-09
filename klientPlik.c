#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>


int main(void)
{
    int status, gniazdo;
    struct sockaddr_in ser;
    char buf[2000];


    gniazdo = socket(AF_INET, SOCK_STREAM, 0);
    if(gniazdo == -1)
    {
        fputs("dziala\n", stdout);
        return 0;
    }

    ser.sin_family = AF_INET;
    ser.sin_port = htons(8017);
    ser.sin_addr.s_addr = inet_addr("127.0.0.1");

    status = connect(gniazdo, (struct sockaddr*)&ser, sizeof ser);
    if(status == -1)
    {
        printf("blad connect\n");
        return 0;
    }
    while(1) {
        printf("Podaj plik:");
        fgets(buf, sizeof(buf), stdin);


        status = send(gniazdo, buf, strlen(buf)-1, 0);
        status = recv(gniazdo, buf, (sizeof buf) - 1, 0);
        printf("Otrzymalem: %s\n", buf);
        *buf = '\0';
        //fgets(buf, sizeof buf, stdin);




        buf[status] = '\0';
        //printf("Otrzymalem: %s\n", buf);

    }

    return 0;

}