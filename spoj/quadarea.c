#include <stdio.h>
#include <math.h>
int main()
{
	int i,t;
	double a,b,c,d,area,s;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		s=(a+b+c+d)/2;
		area=sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%lf\n",area);
	}
	return 0;
}
