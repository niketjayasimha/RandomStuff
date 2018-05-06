#include <stdio.h>
int main()
{
	float c;
	float i;
	float sum=0;
	for(;;)
	{
		scanf("%f",&c);
		if(c==0.00)
		break;
		else
		{
			sum=0;
			for(i=2.00;;i+=1.00)
			{
				sum+=(1.00/i);
				if(sum>c)
				{
					printf("%d card(s)\n",(int)(i-1.00));
					break;
				}
			}				
		}
	}
}		
