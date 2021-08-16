#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int is_prime(int x)
{
    int i=5;
    if (x==1 || x==0){return 0;}
    if (x==2 || x==3){return 1;}
    if(x%3==0||x%2==0){return 0;}
    while (i<=sqrt(x))
    {
        if (x%i==0)
        {
            return 0;
        }
        i+=2;
        if (x%i==0)
        {
            return 0;
        }
        i+=4;
    }
    return 1;
}

int kw(int x)
    {
        int sum=0;
        while(x>=1)
        {
            sum+=pow(x%10,2);
            x=x/10;
        }
        if (sum==1)
        {
            return 1;
        }
        if (sum==4)
        {
            return 4;
        }
        else{return kw(sum);}
    }
int main()
{
    int l, u,k;
    int cnt=0;
    scanf("%d %d %d",&l,&u,&k);
    while (l<=u)
    {

        if(is_prime(l) && kw(l) ==1 )
        {

            cnt++;
            if (cnt==k)
            {
                printf("%d",l);
                return 0;
            }
        }
        l++;
    }
    printf("%d",-1);

    return 0;
}