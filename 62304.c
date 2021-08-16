#include <stdio.h>
#include <stdlib.h>

long long int square(long long int n) { return n * n; }
  

long long int sum(long long int n)
{
    if (n == 0)
        return 0;
    if (n % 2 == 1) {  
        return square((n + 1) / 2) + sum(n / 2);       
    }
    else { 
        return square(n / 2) + sum(n / 2);
    }
}
  

long long int oddDivSum(int a, long long int b)
{
    return sum(b) - sum(a - 1);
}
  

int main()
{
    long long int n;
    scanf("%lld",&n);
        int a = 0; 
        long long int b = n;
    printf("%lld",oddDivSum(a, b));
    return 0;
}