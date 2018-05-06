/*Q5 c 	
 *Assume queue is : (tail) L3 v2 L2 v1 L1 (head)
 * 	1. L1 to temp1.
 * 	2. v1, L2 to temp2. 
 * 	3. v2 to temp1.
 *	4. v1 to org.
 *	5. L2 to temp1.
 *	6. L3 to temp2.
 *	7. v1 to temp1.
 *	8. L3 to temp1.
 *	9. temp1 to org
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
struct QUEUE
{
	int q[MAXSIZE];
	int head;
	int tail;
};

typedef struct QUEUE queue;

queue org = { {0,0,0,0,0},0,0,};
queue temp1 = {	{0,0,0,0,0},0,0,};
queue temp2 = {	{0,0,0,0,0},0,0,};

void enqueue(queue *a, int x)
{
	if(a->tail>MAXSIZE-1)
	{
		printf("Queue is full\n");
		abort();
	}
	a->q[a->tail++] = x;
}

int dequeue(queue *a)
{
	int x, i;
	if(a->head == a->tail)
	{
		printf("Queue is empty\n");
		abort();
	}
	x = a->q[a->head];
	for(i=0;i<a->tail-1;i++)
		a->q[i] = a->q[i+1];
	a->tail--;
	return x;
}

void exchange(queue *a, int v1 ,int v2)
{
	while(a->head != a->tail) // L1 to temp1 except v1
	{
		if(a->q[a->head] == v1 || a->q[a->head] == v2)
			break;
		else
			enqueue(&temp1, dequeue(a));
	}
	enqueue(&temp2, dequeue(a)); // v1 to temp2
	while(a->head != a->tail) // L2 to temp2 except v2
	{
		if(a->q[a->head] == v1 || a->q[a->head] == v2)
			break;
		else
			enqueue(&temp2, dequeue(a));
	}
	enqueue(&temp1, dequeue(a)); // v2 to temp1
	enqueue(a, dequeue(&temp2)); // v1 to org
	while(temp2.head != temp2.tail) // L2 to temp1
		enqueue(&temp1, dequeue(&temp2));
	while(a->head != a->tail) // L3 to temp2 except v1
	{
		if(a->q[a->head] == v1 || a->q[a->head] == v2)
			break;
		else
			enqueue(&temp2, dequeue(a));
	}
	enqueue(&temp1, dequeue(a)); // v1 to temp1
	while(temp2.head != temp2.tail) // L3 to temp1
		enqueue(&temp1, dequeue(&temp2));
	while(temp1.head != temp1.tail) // temp1 to org
		enqueue(a, dequeue(&temp1));

}

int main()
{
	int i, x, y;
	printf("Enter %d values\n",MAXSIZE);
	for(i=0;i<MAXSIZE;i++)
	{
		scanf("%d",&x);
		enqueue(&org,x);
	}
	printf("Enter the two values you want to exchange\n");
	scanf("%d %d",&x,&y);
	exchange(&org,x,y);
	printf("Modified queue is\n");
	for(i=0; i < org.tail; i++)
		printf("%d\n",org.q[i]);
	return 0;
}
