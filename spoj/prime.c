#include <stdio.h>
#include <math.h>
int a[100010];
int main()
{
	int t,c,i,j,len,m,n,count=0;
	scanf("%d",&t);
	while(t--)
	{
		//printf("Enter m and n\n");
		//printf("Entered while\n");
		scanf("%d %d", &m, &n);
		len = n - m + 1;
		for(i = 0; i < len; i++)
			a[i] = 0;
		for(i = 2; i <= (sqrt(len)+1); i++)
		{
			if(a[i-2] == 0)
			{
				for(j = 2*(i-2); j<len; j += i)
				{
					if(j%i == 0)
						a[j] = 1;
				}
			}
		}
		for(i = 0; i < len; i++)
		{
			//printf("For print\n");
			if(a[i] == 0)
				printf("%d\n", i);
		}
	}
	return 0;
}			
