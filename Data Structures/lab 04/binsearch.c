#include <stdio.h>
#define MAXSIZE 10
int bsearch(int *A, int x)
{
	int low = 0, high = MAXSIZE - 1;
	int mid;
	while(low < high)
	{
		mid = (low + high)/2;
		if(x == A[mid])
			return mid;
		else if (x < A[mid])
			high -= 1;
		else
			low += 1;
	}
	return -1;
}
int main()
{
	int A[MAXSIZE];
	int i;
	printf("Enter %d numbers\n",MAXSIZE);
	for(i = 0; i < MAXSIZE; i++)
		scanf("%d",&A[i]);
	printf("Enter the number you want to search for\n");
	scanf("%d",&i);
	i = bsearch(A, i);
	if(i == -1)
		printf("Number not present!\n");
	else
		printf("Number found at index %d\n",i);
	return 0;
}
