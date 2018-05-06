#include <stdio.h>
#define MAXSIZE 10
int partition(int *A, int first, int last)
{
	int i, j, val, t;
	val = A[last];
	i = first - 1;
	for(j = first; j < last; j++)
	{	
		if(A[j] >= val)
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
void qsort(int *A, int first, int last)
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
	int A[MAXSIZE];
	int i;
	printf("Enter %d numbers\n",MAXSIZE);
	for(i = 0; i < MAXSIZE; i++)
		scanf("%d",&A[i]);
	qsort(A, 0, MAXSIZE - 1);
	for(i = 0 ; i < MAXSIZE; i++)
		printf("%d  ",A[i]);
	printf("\n");
	return 0;
}
