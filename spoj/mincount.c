#include <stdio.h>
int main()
{
	double n, ans;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&n);
		if(n>=6)
			ans=(n/6)*(n+1);
		else
			ans=(n*(n+1))/6;
		printf("%.0lf\n",ans);
	}
	return 0;
}
