#include <stdio.h>
int main()
{
	int t, i ,j, y, x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		y = 0;
		for(i=1;i<=x;i++)
		{
			scanf("%d",&j);
			if(j>=i)
				y += j/i;
		}
		if(y%2 == 0)
			printf("BOB\n");
		else
			printf("ALICE\n");
	}
	return 0;
}
