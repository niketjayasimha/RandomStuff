#include <stdio.h>
int main()
{	
	char a[1000000];
	do{
		gets(a);
	}while(strcmp(a,"\0")!=0);
	return 0;
}	
