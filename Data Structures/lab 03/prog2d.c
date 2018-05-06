#include <stdio.h>
#include <stdlib.h>
int size = 0;
int smallest = 0;
int length = 0;
int *S;
int heapsize()
{
	return size;
}
void buildheap(int *A)
{
	int i, t;
	for(i=2 ; i <= size; i++)
	{
		int j = i;
		while(A[j] < A[j/2] && j > 1)
		{
			t = A[j];
			A[j] = A[j/2];
			A[j/2] = t;
			j = j/2;
		}
	}
}
int main()
{
	int x;
	int i;
	printf("Enter number of elements\n");
	scanf("%d",&x);
	int *S = (int *)malloc((x+1)*sizeof(int));
	size = x;
	S[0] = -1;
	printf("Enter the elements\n");
	for(i=1; i < size+1; i++)
		scanf("%d",&S[i]);
	for(i=1;i<size+1;i++)
		printf("%d ",S[i]);
	printf("\n");
	buildheap(S);
	for(i=1; i < size+1;i++)
		printf("%d ",S[i]);
	printf("\n");
	return 0;
}

