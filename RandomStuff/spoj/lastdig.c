#include <stdio.h>
typedef long long big;
int mod_exp(big base, big pwr, big mod)
{
	big x = 1;
	while(pwr > 0)
	{
		if(pwr % 2 == 1)
			x = (x * base) % mod;
		pwr = pwr >> 1;
		base = (base * base) % mod;
	}
	return x;
}

int main()
{
	int t,l;
	unsigned long long x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu %llu", &x, &y);
		x = x % 10;
		if(y == 0)
			printf("1\n");
		else
		{
			y = y % 4;
			if(y == 0)
				y = 4;
			printf("%d\n", mod_exp(x, y, 10));
		}
	}
	return 0;
}
