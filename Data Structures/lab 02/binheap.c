#include <stdio.h>

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i + 1;
}

int parent(int i)
{
	return i/2;
}

int main()
{
	int x;
	printf("Enter the the node number when written in Level Order\n");
	scanf("%d",&x);
	printf("Parent is %d\n",parent(x));
	printf("Left Child is %d\n",left(x));
	printf("Right Child is %d\n",right(x));

	return 0;
}
