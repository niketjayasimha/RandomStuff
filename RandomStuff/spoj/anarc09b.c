#include <stdio.h>
long long gcd(long long a, long long b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	long long a, b, g, x, w;
	for(;;)
	{
		scanf("%lld %lld",&a,&b);
		if(a==0 && b==0)
			break;
		g=gcd(a,b);
		if(a>b)
			x=(a/g)*b;
		else
			x=(b/g)*a;
		w=(x/a)*(x/b);
		printf("%lld\n",w);
	}
	return 0;
}
