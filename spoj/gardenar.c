#include <stdio.h>
#include <math.h>

double area(double a, double b, double c)
{
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
	int t;
	double a, b, c, total_area;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lf %lf %lf", &a, &b, &c);
		total_area = (1.5 * area(a, b, c)) + (area(a, a, a) + area(b, b, b) + area(c, c, c)) / 2;
		printf("%0.2lf\n", total_area);
	}
	return 0;
}
