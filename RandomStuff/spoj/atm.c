#include <stdio.h>
int main()
{
	char key[] = {'t','s','r','q','p','o','n','m'};
	int val[] = {5000,1000,500,100,50,10,5,1};
	int i,j,k,t;
	int x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		k = 0;
		int a[] = {0,0,0,0,0,0,0,0};
		for(i = 0; i < 8; i++)
		{
			k = 0;
			for(;;)
			{
				if(x - val[i] < 0)
					break;
				else
				{
					x = x-val[i];
					k++;
				}
			}
			a[i] = k;
		}
		for(i=0;i<8;i++)
		{
			for(j=0;j<a[i];j++)
			{
				printf("%c",key[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
