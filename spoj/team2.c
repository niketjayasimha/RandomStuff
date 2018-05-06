#include <stdio.h>

long long int max(long long int a, long long int b) 
{
	return a > b ? a : b;
}

long long int foo(long long int a, long long int b, long long int c, long long int d)
{
	return max(max(a, c) + max(b, d), max(a, b) + max(c, d));
}
int main()
{
	long long int a, b, c, d, x, y, z;
	int cases = 1;
	while(scanf("%lld %lld %lld %lld",&a, &b, &c, &d) != EOF)
	{
		x = foo(a, b, c, d);
		y = foo(a, c, b, d);
		z = foo(a, d, b, c);

		x = max(x, y);
		x = max(x, z);

		printf("Case %d: %lld\n", cases++, x);
	}
	return 0;
}
