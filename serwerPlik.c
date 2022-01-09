#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(void)
{

    int gniazdo, status, gniazdo2, dlugosc, nr=0, end=1;
    char buf[200];
    char buf2[200];
    int ctr = 0;

    struct sockaddr_in ser;
    struct sockaddr cli;


    gniazdo = socket(AF_INET, SOCK_STREAM, 0);
    if(gniazdo == -1)
    {
        fputs("blad socket\n", stdout);
        return 0;
    }


    ser.sin_family = AF_INET;
    ser.sin_port = htons(8017);
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
        gniazdo2 = accept(gniazdo, (struct sockaddr *) &cli, (socklen_t *) &dlugosc);
        if (gniazdo2 == -1) {
            printf("blad accept\n");
            return 0;
        }


        while (1) {
            status = recv(gniazdo2, buf, sizeof buf, 0);
          /*  for (int c = 0; c < strlen(buf); c++) {
                if (buf[c] == '\n')
                    buf[c] = '\0';
            }*/
          buf[status]=0;
            if (buf[0] == 'Q') {
                sprintf(buf, "OK, SERWER KONCZY PRACE");
                end = 0;
                break;
            } else if (buf[0] == 'N') {
                sprintf(buf, "JEESTES KLIENTEM NR %d", nr++);
            } else {

                printf("Nazwa pliku:\n");
                fputs(buf, stdout);
                //fgets(buf, sizeof buf, stdin);
                //int fgetc(FILE *wskaznik);
                FILE *wsk;
                int w;
                wsk = fopen(buf, "r");
                while ((w = fgetc(wsk)) != EOF) {
                    //printf("%c", w);
                    buf2[ctr] = w;
                    ctr++;

                }
                buf2[ctr+1]='\0';
                fclose(wsk);

            }
            ctr = 0;
            status = send(gniazdo2, buf2, strlen(buf2), 0);
            //*buf2='\0';
            //close(gniazdo2);

        }
    }
    close(gniazdo);

    return 0;
}