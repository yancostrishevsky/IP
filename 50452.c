#include <stdio.h>
#include <math.h>

int isPrime(int n)
{

    if (n == 2)
    {
        return 1;
    }
    for (int i = 2; i <= sqrt(n) + 1; ++i)
    {
        if (n % i == 0 || n == 1)
            return 0;
    }
    return 1;
}

int devide(int n)
{
    int suma = 0;
    for (int i = 1; i <= (n / 2); ++i)
    {
        if (n % i == 0)
            suma += i;
    }
    return suma;
}

int euler(int n)
{
    return ((pow(2, n) - 1) * pow(2, n - 1));
}
int main()
{
    int tab[5]= {0};
    int m, n;
    do
    {
        scanf("%d %d", &m, &n);
        if (m >= 1 && n <= 100000000)
            break;
    } while (1);
    int i,sum, counter = 0;
    i = 1;
    while (euler(i) < n)
    {sum = euler(i);
        if (isPrime(i))
        {
            if ((devide(sum) == sum) && sum > m)
            {
                counter++;
                tab[counter - 1] = euler(i);
            }
        }

        //printf("%d", euler(13));
        i++;
    }
    printf("%d \n", counter);
    for (int i = 0; i < 5; ++i)
    {
        if (tab[i] != 0)
        {
            printf("%d ", tab[i]);
        }
    }
    return 0;
}