#include <stdio.h>
int main()
{
	int a,d,i,j,t;
	for(;;)
	{
		scanf("%d %d",&a,&d);
		if(a==0&&d==0)
			break;
		int ad[a];
		int dd[d];
		for(i=0;i<a;i++)
			scanf("%d",&ad[i]);
		for(i=0;i<d;i++)
			scanf("%d",&dd[i]);
		for(i=0;i<a;i++)
		{
			for(j=0;j<a-1;j++)
			{
				if(ad[j]>ad[j+1])
				{
					t=ad[j];
					ad[j]=ad[j+1];
					ad[j+1]=t;
				}
			}
		}
		for(i=0;i<d;i++)
		{
			for(j=0;j<d-1;j++)
			{
				if(dd[j]>dd[j+1])
				{
					t=dd[j];
					dd[j]=dd[j+1];
					dd[j+1]=t;
				}
			}
		}
		if(dd[0]<=ad[0]&&dd[1]<=ad[0])
			printf("N\n");
		else 
			printf("Y\n");
	}
	return 0;
}
