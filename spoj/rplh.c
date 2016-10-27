#include <stdio.h>
#include <math.h>


int main()
{
	int t, cases = 0;
	double u, d, angle, x;
	double pi = 2*acos(0.0);
	double g = 9.806;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf", &d, &u);
		cases++;
		x = (d*g)/(u*u);
		if(x > 1)
		{
			printf("Scenario #%d: -1\n", cases);
		}
		else
		{
			angle = 90*asin(x)/pi;
			if(angle > 45)
				angle = 90 - angle;
			printf("Scenario #%d: %0.2lf\n", cases, angle);
		}
	}
	return 0;
}
