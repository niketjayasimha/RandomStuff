#include <stdio.h>
int main()
{
	unsigned long long n,m,t,i;
	unsigned long long total,a;
	for(;;)
	{
		scanf("%lld %lld",&n,&m);
		if(m==-1&&n==-1)
			break;
		total=0;
		a=n;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&t);
			total+=t*a;
			a--;
		}
		printf("%lld\n",total*m);
	}
	return 0;
}
