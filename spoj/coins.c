#include <stdio.h>
long long f(long long n);
int main()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
		printf("%lld\n",f(n));
	return 0;
}
long long f(long long n)
{
	long long total;
	if(n/2+n/3+n/4>=n)
		total = f(n/2)+f(n/3)+f(n/4);
	else
		total=n;
	return total;
}
