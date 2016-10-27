#include <stdio.h>
#include <math.h>
int main()
{
	double N, n;
	for(;;)
	{
		scanf("%lf", &n);
		if(n < 0.0)
			break;
		else
		{
			n--;
			N = (-3.0 + sqrt(9 + 12 * n)) / 6.0;
			if(N - (int)N == 0)
				printf("Y\n");
			else
				printf("N\n");
		}
	}
	return 0;
}
