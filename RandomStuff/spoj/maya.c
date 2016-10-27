#include <stdio.h>
#include <string.h>
char a[20][20] = {
			"S", ".", "..", "...", "....",
			"-", ". -", ".. -", "... -", ".... -",
			"- -", ". - -", ".. - -", "... - -", ".... - -",
			"- - -", ". - - -", ".. - - -", "... - - -", ".... - - -"
		 };

int base[7] = {1, 20, 360, 7200, 144000, 2880000, 57600000};
int main()
{
	int n, num, i, j;
	char str[101];
	for(;;)
	{
		scanf("%d", &n);
		if(n == 0)
			break;
		getchar();
		num = 0;
		for(i = n - 1; i >= 0; i--)
		{
			gets(str);
			for(j = 0; j < 20; j++)
			{
				if(!strcmp(str, a[j]))
					break;
			}
			if(j != 0)
				num += base[i] * j;
		}
		printf("%d\n", num);
	}
	return 0;
}
