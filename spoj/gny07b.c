#include <stdio.h>
#include <string.h>
int main()
{
	int t,i;
	float n,ans;
	char unit[4];
	char a[4];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%f %s",&n,unit);
		getchar();
		if(strcmp(unit,"l")==0)
		{
			ans=n*0.2642;
			strcpy(a,"g");
		}
		else if(strcmp(unit,"g")==0)
		{
			ans=n*3.7854;
			strcpy(a,"l");
		}
		else if(strcmp(unit,"kg")==0)
		{
			ans=n*2.2046;
			strcpy(a,"lb");
		}	
		else if(strcmp(unit,"lb")==0)
		{
			ans=n*0.4536;
			strcpy(a,"kg");
		}
		printf("%d %.4f %s\n",i,ans,a);
	}
	return 0;
}
