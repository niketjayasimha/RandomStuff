#include <stdio.h>
#include <string.h>
int main()
{
	char a[3];
	printf("Ready\n");
	for(;;)
	{
		gets(a);
		if(strcmp(a,"  ")==0)
			break;
		if(strcmp(a,"pq")==0||strcmp(a,"qp")==0||strcmp(a,"db")==0||strcmp(a,"bd")==0)
			printf("Mirrored pair\n");
		else
			printf("Ordinary pair\n");
	}
	return 0;
}
