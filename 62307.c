#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int add(unsigned long long int n)
{
    unsigned long long int tmp = n;
    while (tmp > 1)
    {
        tmp = tmp / 10;
        n += tmp;
    }
    //printf("%d", n);
    return n;
}
int obliczIloscCyfr(unsigned long long int num)
{
    int iloscCyfr = 0;

    if (num == 0)
        iloscCyfr = 1;

    else
    {
        while (num != 0)
        {
            iloscCyfr++;
            num /= 10;
        }
    }

    return iloscCyfr;
}
unsigned long long int piwo(unsigned long long int n)
{
    //long long int n;
    unsigned long long int low;
    unsigned long long int high;
    unsigned long long int mid;

    //scanf("%lld", &n);
    int dl = obliczIloscCyfr(n);
    // printf("%d ",dl);
    low = pow(10, dl - 1);
    high = pow(10, dl) - 1;
    while (low <= high)
    {
        mid = (high+ low)/2;
        if(add(mid) <n)
            low = mid + 1;
        else if(add(mid)> n)
        high = mid -1;
        else
        {
            return mid;
        }
        

    }
    return 0;
}
int main()
{
    unsigned long long int n;
    unsigned long long int ret;
    
    scanf("%lld", &n);
    if (n > 1000000000000000000 || n < 1)
    {
        printf("-1");
        return 0;
    }
    ret = piwo(n);
    if (piwo(n)== 0)
        printf("-1");
    else
    {
        printf("%lld",ret);
    }

    return 0;
}