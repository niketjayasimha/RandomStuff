#include <stdio.h>
#include <string.h>
int main()
{
	int j,t,i,m,k;
	char n[80];
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		scanf("%d",&m);
		getchar();
		scanf("%s",n);
		n[m-1]=' ';	
		printf("%d ",j);
		for(k=0;k<strlen(n);k++)
		{
			if(n[k]!=' ')
				printf("%c",n[k]);
		}
		printf("\n");
	}
	return 0;
}
		
