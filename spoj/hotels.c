#include <stdio.h>
int main()
{
	int a[30000];
	int N,i, j=0;
	long long M, max=0, cur=0;
	scanf("%d %lld",&N,&M);
	for(i=0; i<N; i++)
		scanf("%d",&a[i]);
	for(i=0;i<N;i++)
	{
		cur += a[i];
		while(cur>M)
			cur -= a[j++];
		if(cur > max)
			max = cur;
	}
	printf("%lld\n",max);
	return 0;
}
