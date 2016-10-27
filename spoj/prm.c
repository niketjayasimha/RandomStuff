#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,count=0;
	int a[10001];
	a[0]=1;
	a[1]=1;
	for(i=2;i<10001;i++)
		a[i]=0;
	for(i=2;i<=(sqrt(10000)+1);i++)
	{
		if(a[i]==0)
		{
			for(j=2*i;j<=10000;j+=i)
			{
				if(j%i==0)
				a[j]=1;
			}
		}
	}
	for(i=0;i<=10001;i++)
	{
		if(a[i]==0)
			count++;
	}
	printf("%d\n",count);
	return 0;
}
