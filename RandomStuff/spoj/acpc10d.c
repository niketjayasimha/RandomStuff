#include <stdio.h>
int min2(int a, int b)
{
	return (a<b) ? a:b;
}
int min3(int a, int b, int c)
{
	return min2(min2(a,b),c);
}
int min4(int a, int b, int c, int d)
{
	return min2(min3(a,b,c),d);
}
int main()
{
	int n, i, j;
	int c=0;
	int a[100000][3];
	for(;;)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		c++;
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
				scanf("%d",&a[i][j]);
		}
		a[0][0]=a[0][1];
		a[0][2]+=a[0][1];
		for(i=1;i<n;i++)
		{
			j=0;
			a[i][j]+=min2(a[i-1][j],a[i-1][j+1]);
			j++;
			a[i][j]+=min4(a[i-1][j-1],a[i-1][j],a[i-1][j+1],a[i][j-1]);
			j++;
			a[i][j]+=min3(a[i-1][j-1],a[i-1][j],a[i][j-1]);
		}
		printf("%d. %d\n",c,a[n-1][1]);
	}
	return 0;
}
