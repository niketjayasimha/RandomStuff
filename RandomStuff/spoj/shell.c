#include <stdio.h>
int index(char a[10])
{
	if(strcmp(a,"left")==0)
		return 1;
	else if (strcmp(a,"center")==0)
		return 2;
	else
		return 3;
}

int main()
{
	char s1[10],s2[10];
	int pos; // 1=L, 2=C, 3=R
	int swaps, i;
	for(i=1;i<=10;i++)
	{
		scanf("%s",s1);
		scanf("%d",&swaps);
		getchar();
		pos=index(s1);
		while(swaps--)
		{
			scanf("%s %s",s1,s2);
			if(pos==index(s1))
				pos=index(s2);
			else if(pos==index(s2))
				pos=index(s1);
		}
		if(i==10)
			continue;
		switch(pos)
		{
			case 1: printf("left\n");
				break;
			case 2: printf("center\n");
				break;
			case 3: printf("right\n");
				break;
			default: break;
		}
	}
	return 0;
}
