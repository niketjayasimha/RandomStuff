#include <stdio.h>
int main()
{
	int n,i;
	int org;
	int num=0,rem=0;
	int count=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		count=0;
		org=a[i];
		while(org>0)
		{
			rem=org%2;
			if(rem==1)
				count++;
			org=org/2;
		}
		printf("%d\n",count);
	}
	return 0;
}		
