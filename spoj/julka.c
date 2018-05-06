#include <stdio.h>
int main()
{
	long long t,m,i;
	for(i=1;i<=10;i++)
	{
		scanf("%lld",&t);
		scanf("%lld",&m);
		printf("%lld\n",(t+m)/2);
		printf("%lld\n",(t-m)/2);
	}
	return 0;
}
