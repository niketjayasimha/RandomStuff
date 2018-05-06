#include <stdio.h>
#include <string.h>
int nsys(char [], int);
int main()
{
	char num1[10], num2[10];
	int x1, x2, s, n, l1, l2;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s %s",num1,num2);
		l1=strlen(num1);
		l2=strlen(num2);
		x1=nsys(num1,l1);
		x2=nsys(num2,l2);
		s=x1+x2;
		if(s/1000>=1)
		{
			if(s/1000>1)
				printf("%d",s/1000);
			printf("m");
			s=s%1000;
		}
		if(s/100>=1)
		{
			if(s/100>1)
				printf("%d",s/100);
			printf("c");
			s=s%100;
		}
		if(s/10>=1)
		{
			if(s/10>1)
				printf("%d",s/10);
			printf("x");
			s=s%10;
		}
		if(s>1)
			printf("%d",s);
		if(s>0)
			printf("i");
		printf("\n");
	}
	return 0;
}
int nsys(char a[], int l)
{
	int i,x,num=0;
	for(i=0;i<l;i++)
	{
		if(a[i]>='2' && a[i]<='9')
		{
			x=a[i]-'0';
			i++;
		}
		else
			x=1;
		if(a[i]=='m')
			num+=1000*x;
		else if(a[i]=='c')
			num+=100*x;
		else if(a[i]=='x')
			num+=10*x;
		else
			num+=x;
	}
	return num;
}
