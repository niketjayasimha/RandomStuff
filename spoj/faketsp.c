#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
	double x1=0.0, y1=0.0, x2, y2, dist=0.0;
	int i,j,k=1;
	int lbps, rbps, cps;
	char a[1000];
	char xs[100],ys[100];
	while(scanf("%[^\t\n]s",a)!=EOF)
	{
		getchar();
		for(i=strlen(a)-1;i>=0;i--)
		{
			if(a[i]==')')
				rbps=i;
			else if(a[i]==',')
				cps=i;
			else if(a[i]=='(')
			{
				lbps=i;
				break;
			}
		}
		for(i=lbps+1,j=0;i<cps,j<10;i++,j++)
			xs[j]=a[i];
		for(i=cps+1,j=0;i<rbps,j<10;i++,j++)
			ys[j]=a[i];
		if(k==1)
		{
			x2=atof(xs);
			y2=atof(ys);
			k++;
		}
		else
		{
			x2=atof(xs);
			y2=atof(ys);
			dist+=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
			printf("The salesman has traveled a total of %.3lf kilometers.\n",dist);
		}
		x1=x2;
		y1=y2;
	}
	return 0;	
}
