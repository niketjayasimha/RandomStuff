#include <stdio.h>
#include <math.h>
long long digits(long long n)
{
	int i;
	long long digit=0;
	double dig = 0;
	if(n==1)
		return 1;
	for(i=n;i>=1;i--)
		dig+=log10(i);
	digit = (long long)ceil(dig);
	return digit;
}

int main()
{
	long long digit, n, x, i,j;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&x);
		for(i=x;;i++)
		{
			//printf("%d\n",digits(i));
			if(digits(i)==(x+1))
			{
				printf("%lld\n",i-1);
				break;
			}
		}
	}
	return 0;
}
