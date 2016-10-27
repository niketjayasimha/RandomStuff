#include <stdio.h>
#include <math.h>
int main()
{
	double x,y,g,b;
	for(;;)
	{
		scanf("%lf %lf",&g,&b);
		if(g==-1 && b==-1)
			break;
		x=g/(b+1);
		y=b/(g+1);
		printf("%d\n",(g>b)? (int)ceil(x) : (int)ceil(y));
	}
	return 0;
}
