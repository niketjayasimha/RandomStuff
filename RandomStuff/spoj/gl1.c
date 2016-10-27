#include <stdio.h>
int main()
{
	int i, c=0;
	int a[10];
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	{
		if(c>=100)
			break;
		if(a[i]+c<100)
			c+=a[i];
		else if(a[i]+c==100)
		{	
			c+=a[i];
			break;
		}
		else if(((100-c)>=((c+a[i])-100)))
		{
			c+=a[i];
			break;
		}
		else
			break;
	}
	printf("%d\n",c);
	return 0;
}
