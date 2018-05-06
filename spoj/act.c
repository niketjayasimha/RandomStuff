#include <stdio.h>
#include <string.h>
int main()
{
	int t, n;
	char s[50001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %s",&n,s);
		printf("%c\n",s[strlen(s)-1]);
	}
	return 0;
}
