#include <stdio.h>
int mod(int x)
{
	return x < 0 ? 0 - x : x;
}

int main()
{
	int t, mindiff, na, nb, i, j;
	int a[1001], b[1001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&na);
		for(i = 0; i < na; i++)
			scanf("%d",a+i);
		scanf("%d",&nb);
		for(i = 0; i < nb; i++)
			scanf("%d",b+i);
		mindiff = mod(a[0] - b[0]);
		for(i = 0; i < nb; i++)
		{
			for(j = 0; j < na; j++)
			{
				int x = mod(a[j] - b[i]);
				if(x < mindiff)
					mindiff = x;
			}
		}
		printf("%d\n",mindiff);
	}
	return 0;
}
