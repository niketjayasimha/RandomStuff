#include <stdio.h>
#include <string.h>
int main()
{
	char s[501], t[501];
	int flip,i,moves;
	for(;;)
	{
		scanf("%s %s",s,t);
		moves=0;
		flip=0;
		if(strcmp(s,"*")==0 && strcmp(t,"*")==0)
			break;
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]!=t[i] && !flip)
			{
				moves++;
				flip=1;
			}
			else if(s[i]==t[i])
				flip=0;
		}
		printf("%d\n",moves);
	}
	return 0;
}
