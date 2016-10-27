#include <stdio.h>
int main()
{
	int t,n,i;
	double E;
	scanf("%d",&t);
	while(t--)
	{	
		scanf("%d",&n);
		E = 0.0;
		for(i = 1; i <= n; i++)
			E += ((double) n) / ((double) (n - i + 1));
		printf("%0.2lf\n",E);
	}
	return 0;
}	
