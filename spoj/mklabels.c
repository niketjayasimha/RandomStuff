#include <stdio.h>
long long power(int a, int b)
{
	long long prod = 1;
	int i;
	for(i = 0; i < b; i++)
		prod *= a;
	return prod;
}

int main()
{
	int n, i = 0;
	for(;;)
	{
		scanf("%d",&n);
		i++;
		if(n == 0)
			break;
		printf("Case %d, N = %d, # of different labelings = %lld\n", i, n, power(n, n-2));
	}
	return 0;
}
