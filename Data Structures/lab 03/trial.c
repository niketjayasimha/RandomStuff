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
void heapify(int *A, int i)
{
	printf("Entered heapify\n");
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
/*int * heapify(int *A, int i)
{
	int max;
	if(left(i) <= heapsize(A)-1 && A[left(i)] > A[i])
		max = left(i);
	else
		max = i;
	if(right(i) <= heapsize(A)-1 && A[right(i)] > A[max])
		max = right(i);
	if(max != i)
	{
		int t = A[i];
		A[i] = A[max];
		A[max] = t;
		heapify(A,max);
	}
	return A;
}*/

void buildheap(int *A)
{
	printf("Entered Build heap\n");
	int i;
	for(i = size/2 ; i>=1; i--)
		heapify(A,i);
}

void heapsort(int *A)
{
	int i,t;
	length = heapsize(A);
	printf("Entered sort\n");
	buildheap(A);
	for(i=1;i <= length-1; i++)
	{
		printf("Entered Loop\n");
		t = A[1];
		A[1] = A[size];
		A[size] = t;
		size--;
		heapify(A,1);
	}
	size = length;
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
	{
		for(i=1; i < size+1; i++)
			scanf("%d",&S[i]);
	}
	//printf("%d\n",heapsize(A));
	for(i=1;i<size+1;i++)
		printf("%d ",S[i]);
	printf("\n");
	heapsort(S);
	for(i=1; i < size+1;i++)
		printf("%d ",S[i]);
	printf("\n");
	return 0;
}
