#include <stdio.h>
int main()
{
	float x, total;
	int N, K, T, F;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&N, &K, &T, &F);
		x=((float)(F-N))/((2*T)*(K-1));
		total=N+(2*T*K*x);
		printf("%d\n",(int)total);
	}
	return 0;
}
