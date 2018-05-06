#include <stdio.h>
#include <string.h>

int exceed = 0;

char * mirror(char *x, int l)
{
	int i;
	for(i = 0; i < l/2; i++)
		x[l-i-1] = x[i];
	return x;
}

char* get_next(char *x, int l)
{
	int i, carry = 1, n;
	for(i = l % 2 ? l / 2 : (l / 2) - 1; i >= 0; i--)
	{
		n = x[i] + carry - '0';
		if(n <= 9)
		{
			x[i] = n + '0';
			exceed = 0;
			break;
		}
		else
		{
			if(i == 0)
			{
				x[i] = 0 + '0';
				exceed = 1;
			}
			else
			{
				x[i] = (n % 10) + '0';
				carry = n / 10;
			}
		}
	}
	return x;
}

int main()
{
	int t, l;
	char a[1000001], org[1000001];
	char *b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", a);
		l = strlen(a);
		exceed = 0;
		strcpy(org, a);
		b = mirror(a, l);
		if(strcmp(b, org) > 0)
			printf("%s\n", b);
		else
		{
			b = get_next(b, l);
			b = mirror(b, l);
			if(exceed == 1)
				printf("1%s1\n", b + 1);
			else
				printf("%s\n", b);
		}
	}
	return 0;
}
