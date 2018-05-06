#include <stdio.h>
#include <stdlib.h>

long long int a[1000000];

int main()
{
	int t, i, cases = 1;
	long long int sum, hp, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld", &n);
		sum = hp = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			sum += a[i];
			if(sum < 0)
			{
				hp += sum < 0 ? 0 - sum : sum;
				sum = 0;
			}
		}
		printf("Scenario #%d: %lld\n", cases++, hp + 1);
	}
	return 0;
}
