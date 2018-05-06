#include <stdio.h>
#include <math.h>
int main()
{
	double phi = (1 +sqrt(5))/2;
	int t;
	//long long y;
	double n,y;
	double rt5 = sqrt(5);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&n);
		if(n==0)
			printf("0\n");
		else
		{
			y = (pow((1+rt5)/2,n+1) - pow((1-rt5)/2,n+1))/rt5;
			printf("%.0lf\n",y);
		}
	}
	return 0;
}
