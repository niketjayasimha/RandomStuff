#include <stdio.h>
#include <string.h>
int main()
{
	char a[110];
	int i,t;
	int r,b,g;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		r = b = g = 0;
		int l = strlen(a);
		for(i=0;i<l;i++)
		{
			if(a[i] == 'R')
				r++;
			else if(a[i] == 'G')
				g++;
			else if(a[i] == 'B')
				b++;
		}
		if(g%2 == 0 && r%2 == 0 && b%2 == 0)
			printf("%d\n",(g/2) + (b/2) + (r/2));
		else
			printf("UNPAIRED\n");
	}
	return 0;
}


