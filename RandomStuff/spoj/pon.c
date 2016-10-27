#include <stdio.h>
#include <string.h>
long long modexp(long long a, long long b, long long n)
{
	int bin[1000];
	long long t;
	long long org=b;
	long long c=0;
	long long d=1;
	long long rem;
	int i=0, endval;
	while(org>0)
	{
		rem=org%2;
		bin[i++]=rem;
		org/=2;
	}
	endval=i-1;
		
	/*	for(i=endval;i>=0;i--)
			printf("%d",bin[i]);
		printf("\n");
	*/
	 
	for(i=endval;i>=0;i--)
	{
		c=2*c;
		d=(d*d)%n;
		if(bin[i]==1)
		{
			c++;
			d=(d*a)%n;
		}
	}
	return d;
}


int main()
{
	long long n;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n==2)
			printf("YES\n");
		else
		{
			if(modexp(2,n-1,n)%n!=1)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}
