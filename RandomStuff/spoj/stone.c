#include <stdio.h>
int main()
{
	double x[10001];
	double y[10001];
	double area, cx, cy;
	long long n,i;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		area=0;
		cx=0;
		cy=0;
		for(i=0;i<n;i++)
			scanf("%lf %lf",&x[i],&y[i]);
		x[n]=x[0];
		y[n]=y[0];
		for(i=0;i<n;i++)
			area+= (x[i]*y[i+1]) - (x[i+1]*y[i]);
		area=area/2;
		for(i=0;i<n;i++)
		{
			cx+=(x[i]+x[i+1]) * ((x[i]*y[i+1])-(x[i+1]*y[i]));
			cy+=(y[i]+y[i+1]) * ((x[i]*y[i+1])-(x[i+1]*y[i]));
		}
		cx=cx/(6*area);
		cy=cy/(6*area);
		printf("%.2lf %.2lf\n",cx,cy);
	}
	return 0;
}
