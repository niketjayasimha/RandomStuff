#include <stdio.h>
long long gcd(long long a, long long b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}
int main()
{	
	int t;
	long long a, b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		if(a == 1 || b == 1)
			printf("%lld\n",a = (a==1)? b:a);
		else
		{
			printf("%lld\n",(a/gcd(a,b))*b);
		}
	}
	return 0;
}
