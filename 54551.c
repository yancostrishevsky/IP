#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );}
int main()
{
        int m, n, suma=0, suma2 = 0;
    do
    {
        scanf("%d%d", &n, &suma);
        if (n >= 1 && n <= 1000000000 && suma >= 1 && suma <= 1000000)
            break;
    } while (1);
    int* tab = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        tab[i] = m;
    }
 qsort(tab, n, sizeof(int), cmpfunc);
//for(int j =0;j<n;++j)
//printf("%d ",tab[j]);
int piwo = n-suma;
    for(int i = 0;i < suma;++i)
    {
    
    int max = 0;
    for(int j =piwo;j<n;++j)
    {
        
        if(tab[j] > tab[max])
        max =j;


    }
    tab[max] /= 2;

    }
    for(int i = 0; i<n;i++)
    suma2 += tab[i];

    printf("%d", suma2);
    return 0;
}