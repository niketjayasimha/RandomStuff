#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	long long int N, i, j, k, rem, x;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld", &N);
		i = 0; x = 0;
		while(x < N)
		{
			i++;
			x = (long long int)(pow(2, i + 1)) - 2;
		}
		x = (long long int)(pow(2, i)) - 2;
		x = N - x - 1;
		
		k = 0;
		char a[100001];
		while(x > 0)
		{
			rem = x % 2;
			a[k++] = rem + '0';
			x /= 2;
		}
		j = i - (--k) - 1;
		for(i = 0; i < j; i++)
			printf("5");

		for(i = k; i >= 0; i--)
		{
			if(a[i] == '0')
				printf("5");
			else
				printf("6");
		}
		printf("\n");
	}
	return 0;
}
