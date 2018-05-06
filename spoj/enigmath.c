#include <stdio.h>

typedef long long int ll;

ll gcd(ll a, ll b)
{
	if(a == b)
		return a;
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	
	if(~a & 1)
	{
		if(b & 1)
			return gcd(a >> 1, b);
		else
			return gcd(a >> 1, b >> 1) << 1;
	}
	if(~b & 1)
		return gcd(a, b >> 1);
	if(a > b)
		return gcd((a - b) >> 1, b);
	return gcd((b - a) >> 1, a);
}

int main()
{
	int t;
	ll a, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld %lld", &a, &b);
		ll g = gcd(a, b);
		printf("%lld %lld\n", b / g, a / g);
	}
	return 0;
}
