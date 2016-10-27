#include <stdio.h>
#include <math.h>
int main()
{	
	long i,j,t,count=0;
	long long n,pwr;
	scanf("%ld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		count=0;
		for(j=1;;j++)
		{
			pwr=pow(5,j);
			if(pwr>n)
			break;
			else
			count+=(long long)n/pwr;
		}
		printf("%ld\n",count);
	}
	return 0;
}
