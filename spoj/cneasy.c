#include <stdio.h>
#include <string.h>
#include <math.h>

int partition(double *A, int first, int last)
{
	int i, j;
	double val, t;
	val = A[last];
	i = first - 1;
	for(j = first; j < last; j++)
	{	
		if(A[j] <= val)
		{
			i++;
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}
	t = A[i+1];
	A[i+1] = A[last];
	A[last] = t;
	return i+1;
}
void qsort(double *A, int first, int last)
{
	int q;
	if(first < last)
	{	
		q = partition(A, first, last);
		qsort(A, first, q-1);
		qsort(A, q+1, last);
	}
}

int main()
{
	int t,i,n;
	char p[50];
	double a[1050], max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0; i < n; i++)
			scanf("%s %lf", p, a+i);
		qsort(a, 0, n - 1);
		max = 0.0;
		for(i = 0; i < n; i++)
		{
			double x = a[i+1] - a[i];
			//printf("Diff b/w %lf and %lf = %lf\n", a[i+1], a[i], x);
			if(x > max)
				max = x;
		}
		if(360 - a[n-1] + a[0] > max)
			max = 360 - a[n-1] + a[0];
		printf("%d\n",(int)ceil((360 - max) * 12.0));
	}
	return 0;
}
