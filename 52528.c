#include <stdio.h>
#include <stdlib.h>

int waga(int* tab, int n, int p, int len)
{
    if (n == 0)
        return 1;
    if (p == len)
        return 0;
    return waga(tab, n - tab[p], p + 1, len) || waga(tab, n, p + 1, len) || waga(tab, n + tab[p], p + 1, len);
}

int main()
{
    int m, n, suma, suma2 = 0;
    do
    {
        scanf("%d%d", &n, &suma);
        if (n >= 1 && n <= 100 && suma >= 1 && suma <= 1000000)
            break;
    } while (1);
    int* tab = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        tab[i] = m;
    }

    for (int i = 0; i < n; ++i)
        suma2 += tab[i];
    if (suma2 < suma)
    {
        printf("NO");
        return 0;
    }
    if (waga(tab, suma, 0, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}