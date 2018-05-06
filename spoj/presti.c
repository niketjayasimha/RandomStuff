#include <stdio.h>
#include <math.h>
long long fact(long long x)
{
	long long prod = 1;
	long long i;
	for(i = 1; i <= x; i++)
		prod = prod*i;
	return prod;
}
int main()
{
	int t, i;
	long long input;
	double sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&input);
		sum = 0;
		for(i = 0; i <= input; i++)
		{
			if(i % 2 == 0)
				sum += (double)(fact(input)/fact(i));
			else
				sum -= (double)(fact(input)/fact(i));
		}
		printf("%.0lf\n",sum);
	}
	return 0;
}

