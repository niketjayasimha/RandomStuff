#include <stdio.h>
#define MAXSIZE 10
void bsort(int *A)
{
	int i, j, t;
	for(i = 0; i < MAXSIZE; i++)
	{
		for(j = 0; j < MAXSIZE - 1; j++)
		{
			if(A[j] > A[j+1])
			{
				int t = A[j];
				A[j] = A[j+1];
				A[j+1] = t;
			}
		}
	}
}
int main()
{
	int A[MAXSIZE];
	int i;
	printf("Enter %d numbers\n",MAXSIZE);
	for(i = 0; i < MAXSIZE; i++)
		scanf("%d",&A[i]);
	bsort(A);
	for(i = 0 ; i < MAXSIZE; i++)
		printf("%d  ",A[i]);
	printf("\n");
	return 0;
}
