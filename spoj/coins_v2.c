#include <stdio.h>
typedef long long ll;
ll A[10000000];

ll max(ll a, ll b)
{
	return a > b ? a : b;
}

ll f(ll n)
{
	//printf("Entered f(n)\n");
	if(n < 10000000)
	{
		if(n == 0)
			return 0;
		if(A[n] == 0)
			A[n] = max(n, f(n/2) + f(n/3) + f(n/4));
		return A[n];
	}
	else
		return max(n, f(n/2) + f(n/3) + f(n/4));
}

int main()
{
	long long n, i;
	for(i = 0; i < 10000000; i++)
		A[i] = 0;
	while(scanf("%lld", &n) != EOF)
	{
		printf("%lld\n", f(n));
	}
	return 0;
}
