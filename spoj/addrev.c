#include <stdio.h>
int rev(int n);
int main()
{
	int t,a,b,sum,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d",&a,&b);
		sum=rev(a)+rev(b);
		printf("%d\n",rev(sum));
	}
	return 0;
}
int rev(int n)
{
	int rem,rv=0;
	while(n>0)
	{
		rem=n%10;
		rv=rv*10+rem;
		n=n/10;
	}
	return rv;
}
	
