#include <stdio.h>
int main()
{
	int i, count, t;
	unsigned long long int n, k;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%llu %llu", &n, &k);
		count = 0;
		if(k == 1)
			printf("Male\n");
		else if(k == 2)
			printf("Female\n");
		else
		{
			k--;
			while(k > 1)
			{
				if(k % 2 != 0)
					count++;
				k /= 2;
			}

			if(count % 2 == 0)
				printf("Female\n");
			else
				printf("Male\n");
		}
	}
	return 0;
}
