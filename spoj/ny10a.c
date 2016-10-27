#include <stdio.h>
#include <string.h>

char *seq[] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};

int main(int argc, char *argv[])
{
	char a[70];
	int i, count;
	int t, n;
	char *s;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",a);
		
		int l = strlen(a);

		printf("%d",n);

		for(i = 0; i < 8; i++)
		{
			count = 0;
			for(s = a; s = strstr(s,seq[i]); s++)
			{
				count++;
			}
			printf(" %d", count);
		}
		printf("\n");
	}
	return 0;
}

