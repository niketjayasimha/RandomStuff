#include <stdio.h>
int main()
{
	double r;
	int t,i;
	double l;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lf",&r);
		l=(4*r*r)+0.25;
		printf("Case %d: %.2lf\n",i,l);
	}
	return 0;
}
