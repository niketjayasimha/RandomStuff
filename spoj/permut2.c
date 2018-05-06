#include <stdio.h>
int main()
{
	int n, a[100000], inv[100000], i;
	for(;;)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			inv[a[i]-1]=i+1;
		}
		for(i=0;i<n;i++)
		{
			if(inv[i]!=a[i])
				break;
		}
		if(i==n)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
	}
	return 0;
}
