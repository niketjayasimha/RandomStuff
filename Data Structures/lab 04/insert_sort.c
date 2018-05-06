#include <stdio.h>
#define MAXSIZE 10
void isort(int *A)
{
	int i, j, val;
	for(i = 1; i < MAXSIZE ; i++)
	{
		val = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > val)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = val;
	}
}
int main()
{
	int A[MAXSIZE];
	int i;
	printf("Enter %d numbers\n",MAXSIZE);
	for(i = 0; i < MAXSIZE; i++)
		scanf("%d",&A[i]);
	isort(A);
	for(i = 0 ; i < MAXSIZE; i++)
		printf("%d  ",A[i]);
	printf("\n");
	return 0;
}
