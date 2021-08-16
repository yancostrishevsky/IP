#include <stdio.h>
#include <stdlib.h>
int polowki(int *tab, int n)
{
    int *tablica = malloc(sizeof(int) * n);
    int *tablica2 = malloc(sizeof(int) * n);
    int suma = 0;  
    int suma2 = 0;
    int m = n;
    for (int i = 0; i < n; ++i)
    {
        suma += tab[i];
        tablica[i] = suma;
        m -= 1;
        suma2 += tab[m];
        tablica2[m] = suma2;
    }
    
    for (int i = 0; i < n; i++)
        if (tablica[i] == tablica2[i])
            return i;

    return 0;
}

int main()
{
    int n, m;
    scanf("%d ", &n);
    int *tab = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {scanf("%d", &m);
        tab[i] =m ;
    }
    printf("%d",polowki(tab,n));
    return 0;
}