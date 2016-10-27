#include <stdio.h>
#define MAXSIZE 10

int max_element(int *A)
{
	int i, max = A[0];
	for(i = 1; i < MAXSIZE; i++)
	{	
		if(A[i] > max)
			max = A[i];
	}
	return max;
}
int min_element(int *A)
{
	int i, min = A[0];
	for(i = 1; i < MAXSIZE; i++)
	{
		if(A[i] < min)
			min = A[i];
	}
	return min;
}
int main()
{
	int A[MAXSIZE], i;
	printf("Enter %d numbers\n",MAXSIZE);
	for(i = 0; i < MAXSIZE; i++)
		scanf("%d",&A[i]);
	printf("Max element is %d\n",max_element(A));
	printf("Min element is %d\n",min_element(A));
	return 0;
}
