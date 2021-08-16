#include <stdio.h>
#include <math.h>

int isPrime(int n)
{

	if (n == 2)
	{
		return 1;
	}
	for (int i = 2; i <= sqrt(n) + 1; i++)
	{
		if (n % i == 0 || n == 1)
			return 0;
	}
	return 1;
}

int modulo(int i)
{
	int flaga = 1;
	int tmp;
	while (i > 0)
	{

		tmp = i / 10;
		if (i % 10 < tmp % 10)
		{
			flaga = 0;
			break;
		}
		i = i / 10;
	}
	if (flaga)
		return 1;
	return 0;
}

void isprimeprime(int n)
{
	int temp;
	for (int i = 1; i <= n; i++)
	{
		temp = i;
		if (modulo(i))
		{
			if (isPrime(temp))
				printf("%d\n", temp);
		}
	}
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
	isprimeprime(n);

	return 0;
}