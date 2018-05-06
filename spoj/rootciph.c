#include <stdio.h>
int main()
{
	unsigned long long b,c,d;
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%llu %llu %llu",&b,&c,&d);
		printf("%llu\n",(b*b)-(2*c));
	}
	return 0;
}
