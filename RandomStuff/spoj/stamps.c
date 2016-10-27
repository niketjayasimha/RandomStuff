#include <stdio.h>
int main()
{
	int n,t,k,i,j,need,frnds,sum;
	scanf("%d",&n);
	for(k=1;k<=n;k++)
	{
		sum=0;
		scanf("%d %d",&need,&frnds);
		int a[frnds];
		for(i=0;i<frnds;i++)
			scanf("%d",&a[i]);
		for(i=0;i<frnds;i++)
		{
			for(j=0;j<frnds-1;j++)
			{
				if(a[j]<a[j+1])
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
				}
			}
		}
		for(i=0;i<frnds;i++)
		{
			sum+=a[i];
			if(sum>=need){
				printf("Scenario #%d:\n",k);
				printf("%d\n",i+1);
				break;}
			else if(sum<need&&i==frnds-1){
				printf("Scenario #%d:\n",k);
				printf("impossible\n");}
		}
	}
	return 0;		
}			 		 
