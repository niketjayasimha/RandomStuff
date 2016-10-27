#include <stdio.h>
int fact(int n);
int main()
{
	int a,b;
	for(;;)
	{
		scanf("%d %d",&a,&b);
		if(a==-1&&b==-1)
		break;
		else if(a+b==fact(a+b)/(fact(a)*fact(b)))
		printf("%d+%d=%d\n",a,b,(fact(a+b)/(fact(a)*fact(b))));
		else
		printf("%d+%d!=%d\n",a,b,a+b);
	}
	return 0;
}
int fact(int n)
{
	if(n==0||n==1)
	return 1;
	else
	return n*fact(n-1);
}
