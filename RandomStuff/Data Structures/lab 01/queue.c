/*Q2
 */
#include <stdio.h>
#define MAXSIZE 5
int queue[MAXSIZE];

int head = 0;
int tail = 0;

void enqueue(int x)
{
	if(tail>MAXSIZE-1)
	{
		printf("Queue is full\n");
		abort();
	}
	queue[tail++] = x;
}

int dequeue()
{
	int x, i;
	if(head == tail)
	{
		printf("Queue is empty\n");
		abort();
	}
	x = queue[head];
	for(i=0;i<tail-1;i++)
		queue[i] = queue[i+1];
	tail--;
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
	
	while(tail>0)
		printf("%d\n",dequeue());
	printf("Queue after %d dequeues\n",MAXSIZE);
	for(i=0;i<tail;i++)
		printf("%d\n",queue[i]);
	return 0;
}
