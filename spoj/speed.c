#include <stdio.h>
int mod(int a)
{
	return a < 0 ? 0-a : a;
}
int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int t, a, b, x;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", mod(a - b) / gcd(mod(a),mod(b)));
	}
	return 0;
}
