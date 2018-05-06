#include <stdio.h>
int main()
{
	int t, n, m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		if(m >= n && n % 2 != 0)
			printf("R\n");
		else if(m >= n && n % 2 == 0)
			printf("L\n");
		else if(m % 2 != 0)
			printf("D\n");
		else
			printf("U\n");
	}
	return 0;
}
