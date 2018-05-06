/*Q2
 */
#include <stdio.h>
#define MAXSIZE 5
int queue1[MAXSIZE];
int queue2[MAXSIZE];

int headq1 = 0;
int tailq1 = 0;
int headq2 = 0;
int tailq2 = 0;

void enqueueq1(int x)
{
	if(tailq1 > MAXSIZE-1)
	{
		printf("Queue 1 is full\n");
		abort();
	}
	queue1[tailq1++] = x;
}

int dequeueq1()
{
	int x, i;
	if(headq1 == tailq1)
	{
		printf("Queue 1 is empty\n");
		abort();
	}
	x = queue1[headq1];
	for(i=0;i<tailq1-1;i++)
		queue1[i] = queue1[i+1];
	tailq1--;
	return x;
}

void enqueueq2(int x)
{
	if(tailq2 > MAXSIZE-1)
	{
		printf("Queue 2 is full\n");
		abort();
	}
	queue2[tailq2++] = x;
}

int dequeueq2()
{
	int x, i;
	if(headq2 == tailq2)
	{
		printf("Queue 2 is empty\n");
		abort();
	}
	x = queue2[headq2];
	for(i=0;i<tailq2-1;i++)
		queue2[i] = queue2[i+1];
	tailq2--;
	return x;
}

void push(int x)
{
	enqueueq1(x);
}

int pop()
{
	int x;
	while(tailq1 != 1)
		enqueueq2(dequeueq1());
	x = dequeueq1();
	while(tailq2 > 0)
		enqueueq1(dequeueq2());
	return x;
}

int main()
{
	int i, x;
	printf("Enter %d values\n",MAXSIZE);
	for(i=0;i<MAXSIZE;i++)
	{
		scanf("%d",&x);
		push(x);
	}
	printf("After %d pops\n",MAXSIZE);
	for(i=0;i<MAXSIZE;i++)
		printf("%d\n",pop());
	return 0;
}
