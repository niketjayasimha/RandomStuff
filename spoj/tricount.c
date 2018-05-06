#include <stdio.h>
int main()
{
	int t,i;
	long long n,sum;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		if(n%2==0)
		sum=n*(n+2)*(2*n+1)/8;
		else
		sum=(n*(n+2)*(2*n+1)-1)/8;
		printf("%lld\n",sum);
	}
	return 0;
}
