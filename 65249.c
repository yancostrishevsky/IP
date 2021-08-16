#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int piwo(long long int n)
{

    int *t = malloc(100 * sizeof(*t));
    for (int i = 0; i < 100; ++i)
    {
        t[i] = 0;
    }

    for (int i = 0; i < 100; i++)
    {
        t[i] = abs(n % (abs(-2)));
        //printf("%d", t[i]);
        n = (n - t[i]) / (-2);
        //printf("%d", n);
    }
    if (n > 0)
        printf("NO");
    else
    {
        for (int j = 0; j < 100; j++)
        {
            if (t[j] != 0)
                printf("%d ", j);
        }
    }
    return 0;
}

int piwo2(long long int n)
{

    int *t = malloc(100 * sizeof(*t));
    for (int i = 0; i < 100; ++i)
    {
        t[i] = 0;
    }
    for (int i = 0; i < 100; i++)
    {
        t[i] = abs(n % 2);
        n = (n + t[i]) / (-2);
    }
    if (n > 0)
        printf("NO");
    else
    {
        for (int j = 0; j < 100; j++)
        {
            if (t[j] != 0)
                printf("%d ", j);
        }
    }
    return 0;
}
int main()
{
    long long int x;
    scanf("%lld", &x);

    piwo(x);
    printf("\n");
    piwo2(x);
    return 0;
}