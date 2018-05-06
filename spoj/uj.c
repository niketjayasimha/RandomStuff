#include <stdio.h>
#include <math.h>
int main()
{
	double d,n;
	for(;;)
	{
		scanf("%lf %lf",&n,&d);
		if(d==0&&n==0)
			break;
		printf("%.0lf\n",pow(n,d));
	}
	return 0;
}
