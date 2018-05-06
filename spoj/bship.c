#include <stdio.h>
#include <string.h>

char a[2050][2050];

long long exp_count(int m, int n, int s)
{
	int i, j, k, l;
	long long subcount = 0, total = 0;
	for(i = 0; i < m - s + 1; i++)
	{
		for(j = 0; j < n - s + 1; j++)
		{
			for(k = 0; k < s; k++)
			{
				for(l = 0; l < s; l++)
				{
					if(a[i+k][j+l] == 'X')
						subcount++;
				}
			}
			total += subcount;
			subcount = 0;
		}
	}
	return total;
}

int main()
{
	long long area;
	int m, n, s;
	int i, j;
	scanf("%d %d %d", &m, &n, &s);
	for(i = 0; i < m; i++)
		scanf("%s",a[i]);
	long long x = exp_count(m, n, s);
	printf("Total: %lld\n", x);
	area = (m - (s - 1)) * (n - (s - 1));
	double count = ((double)x) / ((double)area);
	//double count = ((double)(s * x)) / (double)(m * n);
	printf("%0.6lf\n", count);
	return 0;
}
