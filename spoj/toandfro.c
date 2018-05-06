#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int x, l, i, j, l2r;
	char a[205];
	for(;;)
	{
		scanf("%d",&x);
		if(x == 0)
			break;
		scanf("%s",a);
		l = strlen(a);
		l2r = 1;
		//y = l/x;  x = col, y = row;
		//printf("Length = %d\n",l);
		//printf("Rows = %d\n",y);
		//printf("Columns = %d\n",x);
		for(i = 0; i < x; i++)
		{
			l2r = 1;
			for(j = i; j < l;)
			{
				//if((j / x) % 2 == 0)
				//	l2r = 1;
				//else
				//	l2r = 0;
				if(l2r)
				{
					printf("%c",a[j]);
					j += (2*(x-i))-1;
					l2r = 0;
				}
				else
				{
					printf("%c",a[j]);
					j += 2*i + 1;
					l2r = 1;
				}
				//printf("%c",a[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
