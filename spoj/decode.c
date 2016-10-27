#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int t;
	long long code;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&code);
		char a[50];
		int i = 0;
		while(code > 0)
		{
			long long x = (code - 1)%26;
			char letter = (char)(x+65);
			a[i++] = letter;
			code = (code - (x+1))/26;
		}
		a[i++] = '\0';
		for(i=strlen(a)-1; i >= 0 ;i--)
			printf("%c",a[i]);
		printf("\n");
	}

	return 0;
}


