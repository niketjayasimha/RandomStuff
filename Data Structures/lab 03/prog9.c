#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int size = 0;
int smallest = 0;
int greatest = 0;
int length = 0;
int *S;
int heapsize(int *A)
{
	return size;
}
void heapify(int *A)
{
	int i;
	for(i=1 ; i <= heapsize(A); i++)
	{
		int x = floorlog2(i);
		if(x%2 == 0)
		{
			if(r(i) <= heapsize(A))
			{
				if(A[r(i)] < A[l(i)])
					smallest = r(i);
				else
					smallest = l(i);
				if(A[i] > A[smallest])
				{
					int t = A[i];
					A[i] = A[smallest];
					A[smallest] = t;
				}
			}
			else if(l(i) <= heapsize(A))
			{
				if(A[i] > A[l(i)])
				{
					int t = A[i];
					A[i] = A[l(i)];
					A[l(i)] = t;
				}
			}
		}
		else
		{
			if(r(i) <= heapsize(A))
			{
				if(A[r(i)] > A[l(i)])
					greatest = r(i);
				else
					greatest = l(i);
				if(A[i] < A[greatest])
				{
					int t = A[i];
					A[i] = A[greatest];
					A[greatest] = t;
				}
			}
			else if(l(i) <= heapsize(A))
			{
				if(A[i] < A[l(i)])
				{
					int t = A[i];
					A[i] = A[l(i)];
					A[l(i)] = t;
				}
			}
		}

	}
}

int floorlog2(int x)
{
	return (int)floor(log(x)/log(2));
}

int l(int x)
{
	return 2*x;
}

int  r(int x)
{
	return 2*x+1;
}

void buildheap(int *A)
{
	heapify(A);
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
