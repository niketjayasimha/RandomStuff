#include <stdio.h>
int main()
{
	double x[4];
	double y[4];
	double area;
	int i, t;
	scanf("%d",&t);
	int cases = 0;
	while(t--)
	{
		cases++;
		area = 0;
		for(i = 0; i < 3; i++)
			scanf("%lf %lf", &x[i], &y[i]);
		x[3] = x[0];
		y[3] = y[0];
		for(i = 0; i < 3; i++)
			area += (x[i]*y[i+1]) - (x[i+1]*y[i]);
		area = area/2;
		if(area < 0)
			area = 0 - area;
		printf("Case %d: %.3lf\n",cases, area);
	}
	return 0;
}
