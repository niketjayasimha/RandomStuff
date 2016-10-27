#include <stdio.h>
#include <math.h>
int main()
{
	double phi, pts, R, H, pi=3.14159265358, g=10.0;
	int u, k1, k2, t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&u,&k1,&k2);
		if(k2==0)
			phi=1.57079633;
		else
			phi=atan((double)4*(double)k1/(double)k2);
		phi=(pi-phi)/2;
		R = (u*u*sin(2*phi))/g;
		H = (u*u*sin(phi)*sin(phi))/(2*g);
		pts = (R*k1)+(H*k2);
		printf("%.3lf %.3lf\n",phi,pts);
	}
	return 0;
}
