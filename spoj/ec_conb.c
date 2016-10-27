#include <stdio.h>
#include <math.h>

int reverse(int n)
{
	int rev = 0;
	while(n > 0)
	{
		rev *= 2;
		rev += n % 2;
		n /= 2;
	}
	return rev;
}

int main()
{
	int N, a, temp;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d", &a);
		if(a & 1 == 1)
			printf("%d\n", a);
		else
		{
			if(a == 0)
				printf("0\n");
			else
			{
				//temp = rem_zero(a);
				//printf("%d\n", ~a & (0xFFFFFFFF >> temp));
				printf("%d\n", reverse(a));
			}
		}
	}
	return 0;
}
