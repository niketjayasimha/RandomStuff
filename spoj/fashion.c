#include <stdio.h>
int main()
{
	int p,t,n,i,j,k,sum;
	scanf("%d",&p);
	for(k=1;k<=p;k++)
	{
		sum=0;
		scanf("%d",&n);
		int hotlvlm[n];
		int hotlvlw[n];
		for(i=0;i<n;i++)
			scanf("%d",&hotlvlm[i]);
		for(i=0;i<n;i++)
			scanf("%d",&hotlvlw[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(hotlvlm[j]>hotlvlm[j+1])
				{
					t=hotlvlm[j];
					hotlvlm[j]=hotlvlm[j+1];
					hotlvlm[j+1]=t;
				}
				if(hotlvlw[j]>hotlvlw[j+1])
				{
					t=hotlvlw[j];
					hotlvlw[j]=hotlvlw[j+1];
					hotlvlw[j+1]=t;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			sum+=hotlvlm[i]*hotlvlw[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}	
