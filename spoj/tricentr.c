#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	double a, b, c, gna, gnb, gnc, area, HG, R;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lf %lf %lf %lf", &a, &gna, &gnb, &gnc);
		area = 1.5 * gna * a;
		b = (2 * area) / (3 * gnb);
		c = (2 * area) / (3 * gnc);
		R = (a * b * c) / (4 * area);

		if(gna == gnb && gnb == gnc)
			HG = 0;
		else
			HG = (2 * sqrt((9 * R * R) - (a * a + b * b + c * c))) / 3;

		printf("%.3lf %.3lf\n", area, HG);
	}
	return 0;
}
