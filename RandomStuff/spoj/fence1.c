#include <stdio.h>
int main()
{
	double area,l;
	double pi=3.14159265358;
	for(;;)
	{
		scanf("%lf",&l);
		if(l==0)
		break;
		area=(l*l)/(2*pi);
		printf("%.2lf\n",area);
	}
	return 0;
}
