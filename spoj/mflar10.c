#include <stdio.h>
#include <string.h>

int main()
{
	char a[4001];
	char *x;
	char l;
	for(;;)
	{
		gets(a);
		if(a[0] == '*')
			break;
		x = strtok(a, " ");
		l = tolower(a[0]);
		while(x != NULL)
		{
			if(tolower(*x) != l)
				break;
			x = strtok(NULL, " ");
		}

		if(x == NULL)
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}
