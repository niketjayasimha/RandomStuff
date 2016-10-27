#include <stdio.h>
int main()
{
	int a[10000];
	int i, avg, sum, n;
	for(;;)
	{
		scanf("%d",&n);
		sum=0;
		if(n==-1)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		avg=sum/n;
		if(avg*n!=sum)
			printf("-1\n");
		else
		{
			sum=0;
			for(i=0;i<n;i++)
			{
				if(a[i]>avg)
					sum+=a[i]-avg;
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
