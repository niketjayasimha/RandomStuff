#include <stdio.h>
int main()
{
	int i,sum=0,n,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		if(n>0)
		sum+=n;
	}
	printf("%d\n",sum);
	return 0;
}
