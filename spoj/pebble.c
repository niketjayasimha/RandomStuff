#include <stdio.h>
#include <string.h>
int main()
{
	char s[10000];
	int i, l, moves, j, games=0;
	while(scanf("%s",s)!=EOF)
	{
		games++;
		j = 0;
		moves = 0;
		l = strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]=='1')
			{
				moves++;
				for(j=i;j<l;j++)
				{
					if(s[j]=='0')
						s[j]='1';
					else
						s[j]='0';
				}
			}
		}
		printf("Game #%d: %d\n",games,moves);
	}
}
