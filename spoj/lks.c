#include <stdio.h>
int main()
{
	int cost[510];
	int value[510];
	int k, n, w, sum;
	int A[510][2000010];
	int i;
	scanf("%d %d",&k, &n);
	sum = 0;
	for(i = 0; i < n; i++)
		scanf("%d %d",&value[i], &cost[i]);
	for(i = 1; i <= n; i++)
		A[i][0] = 0;
	for(w = 0; w <= k; w++)
		A[0][w] = 0;
	for(i = 1; i <=n; i++)
	{
		for(w = 0; w <= k; w++)
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
	int x = k;
	while(A[n][k] == A[n][k-1] && k >= 0)
		k -= 1;
	printf("%d %d\n",k, A[n][k]);
	return 0;
}
