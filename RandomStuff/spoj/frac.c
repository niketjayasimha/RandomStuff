#include <stdio.h>
int main()
{	
	int x, y, i;
	double z;
	for(;;)
	{
		scanf("%d %d",&x,&y);
		if(x == 1 && y == 1)
			break;
		z = (double)x/(double)y;
		for(i = 1; i <= y; i++)
		{
			if(x == 1)
			{
				printf("%d\n",y);
				break;
			}
			if((double)1/i < z)
			{
				double p = z-((double)1/i);
				printf("%.0lf %.0lf\n",(double)i,1/p);
				break;
			}
		}
	}
	return 0;
}

