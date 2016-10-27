#include <stdio.h>
int main()
{
	long long t, n, p;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&p);
		if(p==0)
			printf("Airborne wins.\n");
		else
			printf("Pagfloyd wins.\n");
	}
	return 0;
}
