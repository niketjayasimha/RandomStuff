#include <stdio.h>

typedef long long int big;

big merge(big *A, big p, big q, big r)
{
	int counted; //BOOL 0 - False, 1 - True
	big largest, inversions, i, j, k;
	big n1 = q - p + 1;
	big n2 = r - q;
	big L[n1 + 2], R[n2 + 2];
	L[0] = R[0] = -8439;
	for(i = 1; i <= n1; i++)
		L[i] = A[p + i - 1];
	for(j = 1; j <= n2; j++)
		R[j] = A[q + j];
	if(L[n1] < R[n2])
		largest = R[n2];
	else
		largest = L[n1];
	L[n1 + 1] = largest + 1;
	R[n2 + 1] = largest + 1;

	i = j = 1;
	inversions = 0;
	counted = 0;
	for(k = p ; k <= r; k++)
	{
		if(counted == 0 && R[j] < L[i])
		{
			inversions += n1 - i + 1;
			counted = 1;
		}
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
			counted = 0;
		}
	}
	return inversions;
}

big inv_cnt(big *A, big p, big r)
{
	big inversions = 0;
	if(p < r)
	{
		big q = (p + r) / 2;
		inversions += inv_cnt(A, p, q);
		inversions += inv_cnt(A, q + 1, r);
		inversions += merge(A, p, q, r);
	}
	return inversions;
}

int main()
{
	int t, n, i;
	big A[200101];
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
			scanf("%lld", &A[i]);
		A[0] = -37834;
		getchar();

		printf("%lld\n", inv_cnt(A, 1, n));
	}
	return 0;
}
