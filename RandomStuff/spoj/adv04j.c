#include <stdio.h>
int main()
{
	int t, n, l;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		l = 0;
		while(n > 0)
		{
			if(n == 2)
			{
				l += 2;
				break;
			}

			if(n % 2 == 0)
				n /= 2;
			else
				n = n/2 + 1;
			l++;
		}
		printf("%d\n", l);
	}
	return 0;
}
