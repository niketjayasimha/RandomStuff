#include <stdio.h>
int main()
{
	int n,k,s,i,j,t;
	int sum=0;
	scanf("%d %d %d",&n,&k,&s);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum>=k*s)
		{
			printf("%d\n",i+1);
			break;
		}
	}
	return 0;
}
