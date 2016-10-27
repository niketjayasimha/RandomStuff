#include <stdio.h>
int main()
{
	int n;
	int i,sum;
	for(;;)
	{
		sum=0;
		scanf("%d",&n);
		if(n==0)
		break;
		for(i=1;i<=n;i++)
		{
			sum+=i*i;
		}
		printf("%d\n",sum);
	}
	return 0;
}
