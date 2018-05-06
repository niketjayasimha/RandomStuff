#include <stdio.h>
#define MAXSIZE 10
int min_element(int *A, int offset)
{
	int i, min = 0;
	for(i = 1; i < MAXSIZE - offset; i++)
	{
		if(A[i] < A[min])
			min = i;
	}
	return min + offset;
}
void ssort(int *A)
{
	int i, min, t;
	for(i = 0; i < MAXSIZE; i++)
	{
		min = min_element(A+i, i);
		t = A[i];
		A[i] = A[min];
		A[min] = t;
	}
}
int main()
{
	int A[MAXSIZE];
	int i;
	printf("Enter %d numbers\n",MAXSIZE);
	for(i = 0; i < MAXSIZE; i++)
		scanf("%d",&A[i]);
	ssort(A);
	for(i = 0 ; i < MAXSIZE; i++)
		printf("%d  ",A[i]);
	printf("\n");
	return 0;
}
