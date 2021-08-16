#include <stdio.h>
#include <string.h>
int valueletter(char let)
{
    char alfabet[26]={ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for(int z=25;z>=0;z--)
    {
        if(let==alfabet[z])
        {
            return z;
        }
    }
}
int main() {
    char str[50];
    scanf("%s", &str);
    int n=strlen(str);

    int koniec=0;
    char maxchr[50];
    int letternm=0;
    while(koniec<=n-1)
    {
        int maxvalchar= valueletter(str[koniec]);
        int indekmax=koniec;
        if (koniec==n-1)
        {
            maxchr[letternm]=str[n-1];
            letternm++;
            break;
        }
    for(int i=koniec+1;i<n;i++)
   {

        int act=valueletter(str[i]);
        if(act> maxvalchar)
        {
             maxvalchar=act;
             indekmax=i;

        }
   }
    koniec=indekmax+1;
    maxchr[letternm]=str[indekmax];
    letternm++;
    }

    int dl=strlen(maxchr);
    //printf("%s ", maxchr);
    for(int q=letternm;q<dl;q++)
    {
        maxchr[q]='\0';
    }
    printf("%s",maxchr);

    return 0;
}