#include <stdio.h>
int A[500010];
int flag[4000080];
int main()
{
	int n, i;
	for(i = 0; i < 500011; i++)
	{
		if(A[i-1] - i > 0 && flag[A[i-1] - i] == 0)
		{
			A[i] = A[i-1] - i;
			flag[A[i-1] - i] = 1;
		}
		
		else
		{
			A[i] = A[i-1] + i;
			flag[A[i-1] + i] = 1;
		}
	}
	while(1)
	{
		scanf("%d", &n);
		if(n == -1)
			break;
		printf("%d\n", A[n]);
	}
	return 0;
}
