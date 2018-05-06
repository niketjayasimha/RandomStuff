#include <stdio.h>
#include <math.h>
#define g 9.8
long double sqr(long double);
int main()
{
	int h,v;
	long double range,x,t1,t2;
	for(;;)
	{
		scanf("%d %d",&v,&h);
		if(h==-1&&v==-1)
			break;
		if(v==0)
			range=0;
		else
		{
			long double x = sqrt(sqr(v) + (2*g*h));
			range = v*x/g;
		}
		printf("%llf\n",range);
	}
	return 0;
}
long double sqr(long double n)
{
	return n*n;
}
