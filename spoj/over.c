#include <stdio.h>
int main()
{
	int t, n, i;
	unsigned long long A[51][2];
	A[0][0] = 1;
	A[0][1] = 1;
	for(i = 1; i < 51; i++)
	{
		A[i][0] = A[i-1][0] + A[i-1][1];
		A[i][1] = A[i][0]+ A[i-1][0];
	}
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%llu\n", A[n][1]);
	}
	return 0;
}
