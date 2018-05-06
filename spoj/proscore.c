#include <stdio.h>

int a[20][20];
int c[2];

int ifcnd1(int n, int p)
{
	int prob[p];
	int i, j;
	for(i = 0; i < p; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(a[j][i] == 1)
			{
				prob[i] = 1;
				break;
			}
			else
				prob[i] = 0;
		}
	}
	for(i = 0; i < p; i++)
	{
		if(prob[i] == 0)
			return 0;
	}
	return 1;
}			

void ifcnd2_3(int n, int p)
{
	int sum[n];
	int min, max;
	int i,j;
	for(i = 0; i < n;i++)
		sum[i] = 0;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < p; j++)
			sum[i] += a[i][j];
	}

	min = sum[0];
	max = 0;

	for(i = 0; i < n; i++)
	{
		if(sum[i] < min)
			min = sum[i];
		if(sum[i] > max)
			max = sum[i];
	}

	if(min == 1)
		c[1] = 1;
	else
		c[1] = 0;
	if(max < p)
		c[0] = 1;
	else
		c[0] = 0;

}

int main()
{
	int t, n, p, i, j;
	int caseno = 0;
	scanf("%d",&t);
	while(t--)
	{
		caseno++;
		scanf("%d %d",&n, &p);
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < p; j++)
			{
				scanf("%d",&a[i][j]);
			}

		}
		ifcnd2_3(n,p);
		//printf("Cdn 1: %d\n",ifcnd1(n,p));
		//printf("Cdn 2: %d\n",c[1]);
		//printf("Cdn 3: %d\n",c[0]);
		printf("Case %d: %d\n",caseno, c[0] + 2*c[1] + 4*ifcnd1(n,p));
	}
	return 0;
}
