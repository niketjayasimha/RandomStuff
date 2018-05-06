#include <stdio.h>
int main()
{
	int a1,a2,a3;
	int d1,d2;
	float r1,r2;
	for(;;)
	{
		scanf("%d %d %d",&a1,&a2,&a3);
		if(a1==0&&a2==0&&a3==0)
		break;
		else
		{
			d1=a2-a1;
			d2=a3-a2;
			r1=a2/a1;
			r2=a3/a2;
			if(d1==d2)
			{
				printf("AP %d\n",a3+d1);
			}
			else if(r1==r2)
			{
				printf("GP %d\n",(a3*a2)/a1);
			}
		}
	}
	return 0;
}
