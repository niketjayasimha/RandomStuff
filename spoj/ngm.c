#include <stdio.h>
int main()
{
	long long x;
	scanf("%lld",&x);
	if(x/10*10!=x)
		printf("1\n%d",x-(x/10*10));
	else
		printf("2\n");
	return 0;
}
