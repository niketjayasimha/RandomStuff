#include <stdio.h>
int main()
{
	int t,i,j,max;
	typedef struct
	{
		char url[101];
		int v;
	}google;
	google a[10];
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++)
	{
		for(j=0;j<10;j++)
		{
			scanf("%s %d",a[j].url,&a[j].v);
		}
		max=0;
		for(j=0;j<10;j++)
		{
			if(a[j].v>max)
				max=a[j].v;
		}
		printf("Case #%d:\n",i+1);
		for(j=0;j<10;j++)
		{
			if(a[j].v==max)
				printf("%s\n",a[j].url);
		}
	}
	return 0;
}
