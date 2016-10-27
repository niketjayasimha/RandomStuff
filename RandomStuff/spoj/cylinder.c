#include <stdio.h>
#include <math.h>

double max(double x, double y)
{
	return x > y ? x : y;
}

double min(double x, double y)
{
	return x < y ? x : y;
}
int main()
{
	double a, b, v1, v2, r1, r2;
	double pi = acos(-1.0);
	for(;;)
	{
		scanf("%lf %lf", &a, &b);
		if(a == 0 && b == 0)
			break;
		r1 = min(a / 2.0, b / (2.0 * (pi + 1.0)));
		r2 = a / (2.0 * pi);

		v1 = pi * a * r1 * r1;
		v2 = r2 * r2 * ((b * pi) - a);

		//printf("%.3lf\n", v1);
		//printf("%.3lf\n", v2);
		printf("%.3lf\n", max(v1, v2));
	}
	return 0;
}
