#include <stdio.h>
int main()
{
	int a[101];
	int i, n, t, max, pos;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		max = a[0];
		for(i=0;i<n;i++)
		{
			if(a[i] > max)
			{	max = a[i];
				pos = i;
			}
		}
		printf("%d\n",pos+1);
	}
	return 0;
}
