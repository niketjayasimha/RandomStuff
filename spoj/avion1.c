#include <stdio.h>
#include <string.h>
int main()
{
	char a[20];
	int i;
	int count=0;
	for(i=1;i<=5;i++)
	{
		scanf("%s",a);
		if(strstr(a,"FBI")!=NULL)
			printf("%d\n",i);
		else
			count++;
		if(count==5)
			printf("HE GOT AWAY!\n");
	}
	return 0;
}
