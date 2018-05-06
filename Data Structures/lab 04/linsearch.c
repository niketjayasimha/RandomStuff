#include <stdio.h>
#define MAXSIZE 10
int lsearch(int *A, int x)
{
	int i;
	for(i = 0; i < MAXSIZE; i++)
	{
		if(A[i] == x)
			return i;
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
	i = lsearch(A, i);
	if(i == -1)
		printf("Number not present!\n");
	else
		printf("Number found at index %d\n",i);
	return 0;
}
