#include <stdio.h>
#include <math.h>
/*
long long leng(long long n)
{
	long long i;
	double count=0.0;
	for(i=1;i<=n;i++)
		count+=log10(i);
	return (long long)count+1;
}
*/
int main()
{
	int t;
	double a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&a);
		if(a==1||a==0)
			printf("1\n");
		else
			printf("%lld\n",(long long int)floor((log(2*acos(-1)*a)/2+a*(log(a)-1))/log(10))+1);
	}
	return 0;
}
