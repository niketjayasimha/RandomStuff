#include <stdio.h>
#include <math.h>
int main()
{
	int t, n, sq, sum, i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sq=sqrt(n);
		sum=1;
		for(i=2;i<=sq;i++)
		{
			if(n/i*i==n)
				sum+=i+(n/i);
		}
		if(sq*sq==n)
			sum-=sq;
		printf("%d\n",sum);
	}
	return 0;
}
