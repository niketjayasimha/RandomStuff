#include <stdio.h>
int main()
{
	unsigned long long int t,i,j,cno,n,sum;
	scanf("%llu",&t);
	for(i=0;i<t;i++)
	{
		scanf("%llu",&n);
		sum=0;
		for(j=1;j<=n;j++)
		{
			scanf("%llu",&cno);
			sum+=cno;
			sum%=n;
		}
		if(sum==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
