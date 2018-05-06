#include <stdio.h>
int main()
{
	int t,c,d,e,j,s,p,i;
	int A[1000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		j=0;
		scanf("%d",&c);
		s=c*(c+1)/2;
		for (;j<s;j++)
			scanf("%d",&A[j]);
		d=c-1;
		j=s-c-1;
		e=0;
		for(;j>=0;j--)
		{
			if(e==d){--d;e=0;}
			p=j+d;
			A[j]+=A[p]>A[p+1]?A[p]:A[p+1];
			++e;
		}
		printf("%d\n",A[0]);
	}     
}

