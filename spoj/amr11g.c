#include <stdio.h>
#include <string.h>
int main()
{
	int i,l,t,count;
	char a[10000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		count=0;
		l=strlen(a);
		for(i=0;i<l;i++)
		{
			if(a[i]=='D')
			{
				printf("You shall not pass!\n");
				count++;
				break;
			}
		}
		if(count==0)
			printf("Possible\n");
	}
	return 0;
}
