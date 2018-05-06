#include <stdio.h>
int main()
{
	int x, n, y = 0;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &x);
		y = y ^ x;
	}
	printf("%d\n", y);
	return 0;
}
