#include <stdio.h>
int main()
{
	int t;
	long long int third, last3, n, d, a, sum, i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld %lld", &third, &last3, &sum);
		n = (2*sum)/(third + last3);
		d = (last3 - third)/(n - 5);
		a = third - (2*d);
		printf("%lld\n",n);
		for(i = 1; i <= n-1; i++)
			printf("%lld ", a + (i-1)*d);
		printf("%lld\n",a + (n-1)*d);
	}
	return 0;
}
