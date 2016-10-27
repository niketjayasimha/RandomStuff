#include <stdio.h>
int main()
{
	int n, c=0, t, totalc, redc, i, j;
	for(;;)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		int b[n];
		for(i=0;i<n;i++)
			b[i]=0;
		totalc=0;
		redc=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&t);
				totalc+=t;
				b[i]-=t;
				b[j]+=t;
			}
		}
		c++;
		for(i=0;i<n;i++)
		{
			if(b[i]>0)
				redc+=b[i];
		}
		printf("%d. %d %d\n",c,totalc,redc);
	}
	return 0;
}
