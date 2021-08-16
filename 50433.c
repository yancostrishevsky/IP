#include <stdio.h>
#include <math.h>

int fibb(int n)
{
    int a, b, c, ctr;
    a = 0;
    b = 1;
    ctr = 1;
    while (ctr < n)
    {
        c = a + b;
        a = b;
        b = c;
        ctr++;
    }
    return a;
}

int fibo(int n)
{
    int i=1;
    while (fibb(i) * fibb(i + 1) < n)
        i++;
    if (fibb(i) * fibb(i + 1) == n)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    do
    {
        scanf("%d", &n);
        if (n >= 1 && n <= 100000000)
            break;
    } while (1);

    if (fibo(n))
        printf("YES");
    else
        printf("NO");

    return 0;
}