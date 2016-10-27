#include <stdio.h>

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%0.8lf\n", 2.0 + ((double)1 / n));
	}
	return 0;
}
