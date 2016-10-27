#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,n,len;
	char a[50];
	for(;;)
	{
		scanf("%s",a);
		if(strcmp(a,".")==0)
			break;
		scanf("%d",&n);
		len=strlen(a);
		for(i=0;i<n;i++)
			printf("%s",a);
		printf("\n");
		for(i=1;i<len;i++)
		{
			for(j=i;j<len;j++)
				printf("%c",a[j]);
			for(j=0;j<n-1;j++)
				printf("%s",a);
			for(j=0;j<i;j++)
				printf("%c",a[j]);
			printf("\n");
		}
	}
	return 0;
}

