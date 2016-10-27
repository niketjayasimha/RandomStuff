#include <stdio.h>
int main()
{
	int t,n,a,d,i,sum;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d",&n,&a,&d);
		sum=n*(2*a+(n-1)*d)/2;
		printf("%d\n",sum);
	}
	return 0;
}
