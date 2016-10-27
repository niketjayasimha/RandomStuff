#include <stdio.h>
#include <stdlib.h>
int size = 0;
int smallest = 0;
int length = 0;
int *S;
int heapsize(int *A)
{
	return size;
}
void heapify(int *A, int i)
{
	if(2*i+1 <= heapsize(A))
	{
		if(A[2*i+1] < A[2*i])
			smallest = 2*i+1;
		else
			smallest = 2*i;
		
		if(A[i] > A[smallest])
		{
			int t = A[i];
			A[i] = A[smallest];
			A[smallest] = t;
			heapify(A, smallest);
		}
	}
	else if(2*i <= heapsize(A))
	{
		if(A[i] > A[2*i])
		{
			int t = A[i];
			A[i] = A[2*i];
			A[2*i] = t;
		}
	}
}

int left(int x)
{
	return 2*x;
}

int  right(int x)
{
	return 2*x+1;
}

void buildheap(int *A)
{
	int i;
	for(i = size/2 ; i>=1; i--)
		heapify(A,i);
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
