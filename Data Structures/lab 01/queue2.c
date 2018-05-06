/*Q2
 */
#include <stdio.h>
#define MAXSIZE 5
int stack1[MAXSIZE];
int stack2[MAXSIZE];

int bottomst1 = 0;
int topst1 = 0;
int bottomst2 = 0;
int topst2 = 0;
void pushst1(int x)
{
	if(topst1 > MAXSIZE-1)
	{
		printf("Stack 1 full\n");
		abort();	
	}
	stack1[topst1] = x;
	topst1++;
}

int popst1()
{
	if(bottomst1 == topst1)
	{
		printf("Stack 1 Empty\n");
		abort();
	}

	else
	{
		topst1--;
		return stack1[topst1];

	}
}

void pushst2(int x)
{
	if(topst2 > MAXSIZE-1)
	{
		printf("Stack 2 full\n");
		abort();	
	}
	stack2[topst2] = x;
	topst2++;
}

int popst2()
{
	if(bottomst2 == topst2)
	{
		printf("Stack 2 Empty\n");
		abort();
	}

	else
	{
		topst2--;
		return stack2[topst2];

	}
}

void enqueue(int x)
{
	pushst1(x);
}

int dequeue()
{
	int x;
	while(topst1>=1)
		pushst2(popst1());
	x = popst2();
	while(topst2>=1)
		pushst1(popst2());
	return x;
}

int main()
{
	int i, x;
	printf("Enter %d values\n",MAXSIZE);
	for(i=0;i<MAXSIZE;i++)
	{
		scanf("%d",&x);
		enqueue(x);
	}

	printf("Values obtained after %d dequeues\n",MAXSIZE);

	while(topst1>=1)
		printf("%d\n",dequeue());
	return 0;
}

