#include <stdio.h>
int maxindex(int *A, int n)
{
	int i, max = 0;
	for(i = 0; i < n; i++)
	{
		if(A[i] > A[max])
			max = i;
	}
	return max;
}

int main()
{
	int t, n, m, d, i, max;
	int h[510];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n, &m, &d);
		for(i = 0; i < n; i++)
			scanf("%d",h+i);
		for(i = 0; i < m; i++)
		{
			max = maxindex(h,n);
			if(h[max] - d <= 0)
			{
				printf("NO\n");
				break;
			}
			h[max] -= d;
		}
		if(i == m)
			printf("YES\n");
	}
	return 0;
}
