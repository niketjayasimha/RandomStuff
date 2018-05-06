/*Q3
 */
#include <stdio.h>
#include <stdlib.h>

struct linklist{

	int key;
	struct linklist *next;
		};

typedef struct linklist list; 

list *head = NULL;
list *tail = NULL;
list *new = NULL;


void enqueue(int x)
{
	new = (list *)malloc(sizeof(list));
	new->key = x;
	new->next = NULL;
	if(head == NULL)
		head = new;
	else
		tail->next = new;

	tail = new;
}


int dequeue()
{
	int x;
	list *temp;
	if(head->next != NULL)
	{
		x = head->key;
		temp = head->next;
		head->next = NULL;
		head = temp;
	}
	else
	{
		printf("Queue is Empty\n");
		abort();
	}
	return x;
}

int main()
{
	int i, x;
	list *count;
	printf("Enter 5 values\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&x);
		enqueue(x);
	}

	printf("Values obtained after 2 dequeues\n");

	for(i=0;i<2;i++)
		printf("%d\n",dequeue());
	printf("Queue after 2 dequeues (from front to back)\n");
	count=head;
	while(count != NULL)
	{
		printf("%d\n",count->key);
		count = count->next;
	}
	return 0;
}

