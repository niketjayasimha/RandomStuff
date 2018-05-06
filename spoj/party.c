#include <stdio.h>
int main()
{
	int cost[100];
	int value[100];
	int b, n, w, sum;
	int A[101][501];
	int i, k;
	for(;;)
	{
		scanf("%d %d",&b, &n);
		if(n == 0 && b == 0)
			break;
		sum = 0;
		for(i = 0; i < n; i++)
			scanf("%d %d",&cost[i], &value[i]);
		for(i = 1; i <= n; i++)
			A[i][0] = 0;
		for(w = 0; w <= b; w++)
			A[0][w] = 0;
		for(i = 1; i <=n; i++)
		{
			for(w = 0; w <= b; w++)
			{
				if(cost[i-1] <= w)
				{
					if(value[i-1] + A[i-1][w-cost[i-1]] > A[i-1][w])
						A[i][w] = value[i-1] + A[i-1][w-cost[i-1]];
					else
						A[i][w] = A[i-1][w];
				}
				else
					A[i][w] = A[i-1][w];
			}
		}
		/*
		i = n; k = b;
		while(i > 0 && k > 0)
		{
			if(A[i][k] != A[i-1][k])
			{
				sum += cost[i];
				i--;
				k = k-cost[i];
			}
			else
				i--;
		}*/
		int x = b;
		while(A[n][b] == A[n][b-1] && b >= 0)
			b -= 1;
		printf("%d %d\n",b, A[n][b]);
	}
	return 0;
}
