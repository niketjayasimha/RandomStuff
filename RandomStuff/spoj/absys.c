#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Includes value at index <start> and excludes
 * value at index <end>
 */
char *substr(char *str, int start, int end); 

int main(int argc, char *argv[])
{
	char a[101];
	int pluspos, eqpos, mpos, l;
	int x,y,z,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%*c%*c%[^\t\n]s",a);
		l = strlen(a);
		pluspos = (int)(strchr(a, '+') - a);
		eqpos = (int)(strchr(a, '=') - a);
		mpos = (int)(strchr(a, 'm') - a);

		if(mpos < pluspos)
		{
			y = atoi(substr(a,pluspos+2, eqpos - 1));
			z = atoi(substr(a,eqpos+2, l));
			x = z - y;
		}

		else if(mpos > pluspos && mpos < eqpos)
		{
			x = atoi(substr(a,0,pluspos-1));
			z = atoi(substr(a,eqpos+2, l));
			y = z - x;
		}

		else if(mpos > eqpos)
		{
			x = atoi(substr(a,0,pluspos-1));
			y = atoi(substr(a,pluspos+2,eqpos-1));
			z = x + y;
		}
		printf("%d + %d = %d\n",x,y,z);
	}
	return 0;
}


char *substr(char *str, int start, int end)
{
	char a[101];
	int i;
	int index = 0;
	for(i = start; i < end; i++)
		a[index++] = str[i];
	a[index] = '\0';

	return a;
}
