#include <stdio.h>
#include <math.h>

double si(long long p, double r, int t, long a);
double ci(long long p, double r, int t, long a);
double round(double a);

int main()
{
	int datasets, i, j, t, option, choice;
	double r, amount, max;
	long long p, a;
	scanf("%d", &datasets);
	while(datasets--)
	{
		scanf("%lld", &p);
		scanf("%d", &t);
		scanf("%d", &option);
		max = 0.0;
		while(option--)
		{

			scanf("%d %lf %lld", &choice, &r, &a);
			if(choice == 0)
				amount = si(p, r, t, a);
			else if(choice == 1)
				amount = ci(p, r, t, a);
			if(amount > max)
				max = amount;
		}
		printf("%.0lf\n", max);
	}
	return 0;
}
double ci(long long p, double r, int t, long a)
{
	double amount = 0.0, intrst;
	while(t--)
	{
		intrst = floor(p * r);
		amount = p + intrst - a;
		p = amount;
	}
	return amount;
}
double si(long long p, double r, int t, long a)
{
	double amount, intrst, ti=0.0;
	while(t--)
	{
		intrst = floor(p * r);
		ti += intrst;
		p -= a;
	}
	return p + ti;
}
