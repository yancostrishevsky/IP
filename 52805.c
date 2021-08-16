#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BASE 36
char pattern[MAX_BASE + 1] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";



int valueOf(char x, int base)
{
int i;
for (i=0; i<base; i++)
{
if (x == pattern[i])
{
return i;
}
}
return -1;
}

unsigned int convertFrom(char *n, int base)
{
int i, x;
int p = 1;
int result = 0;

if ((base > MAX_BASE) || (base < 2))
return 0;



for (i=strlen(n)-1; i>=0; i--)
{
x = valueOf(n[i], base);
if (x < 0)
{
return 0;
}
result += (x * p);
p *= base;
}

return result;
}




char *convertTo(char *dst, unsigned int n, int base)
{
int i = 0;
int j;
char tmp[100];

if ((base > MAX_BASE) || (base < 2))
return NULL;

if (n == 0)
{
dst[0] = '0';
dst[1] = 0;
}

while (n>0)
{
tmp[i] = pattern[n % base];
n /= base;
i++;
}


for (j=0; j<i; j++)
{
dst[j] = tmp[i-j-1];
}

dst[i] = 0;
return dst;
}







int pow2(x,y)
{
    int wynik=1;
    for(int i=1;i<=y;i++)
    {
        wynik=wynik*x;

    }

    return wynik;
}

int spr_czy(char *z,int sys,int cyfr)
{

    int i =0;
    int res=0;
    while(i<cyfr)
    {
        res=res+pow2(valueOf(z[i],sys),cyfr);

        i++;
    }
    if (res==convertFrom(z,sys))
    {
        return 1;
    }
    else{return 0;}
}
int main()
{
    int c,b;
    scanf("%d%d",&c,&b);
    char z[c];
    z[0]='1';

    for(int u=1;u<c;u++)
    {
        z[u]='0';
    }
    if(c==1){z[0]='0';}
    int f=convertFrom(z,b);
    int tru=1;
    while (f<=(b)*pow2(b,c-1)-1)
    {
            convertTo(z,f,b);

            if(spr_czy(z,b,c))
            {
                printf("%s ",z);
                tru=0;
            }


        f++;
    }
    if(tru) printf("NO");
    return 0;
}