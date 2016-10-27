#include <stdio.h>
#include <string.h>
int main()
{
	int i, t, l, flag;
	char a[50];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		l = strlen(a);
		flag = 1;
		for(i = 0; i < l/2; i++)
		{
			if(a[i] != a[l-i-1])
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		if(flag == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
