#include <stdio.h>
int main()
{
	int t,n,i,j,fact;
	scanf("%d",&t);
	if(t>=1&&t<=100)
	{
		for(i=1;i<=t;i++)
		{
			scanf("%d",&n);
			fact=1;
			if(n>=1&&n<=100)
			{
				for(j=1;j<=n;j++)
				{
					fact*=j;
				}
				printf("%d\n",fact);
			}
		}
	}
	return 0;
}
