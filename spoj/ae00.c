#include <stdio.h>
int main()
{
	int n,i,j;
	int count=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if((i*j)<=n)
				count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
