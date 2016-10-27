#include <stdio.h>
#include <math.h>
double log_2(double);
int main()
{
	double n;
	scanf("%lf",&n);
	if(n<=1)
		printf("TAK\n");
	else if((long long)pow(2,log_2(n))==n)
		printf("TAK\n");
	else
		printf("NIE\n");
	return 0;
}
double log_2(double n)
{
	return log(n)/log(2);
}
