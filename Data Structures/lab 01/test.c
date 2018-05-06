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
	else if(head != NULL && tail != NULL && head == tail)
	{
		x = head->key;
		head = NULL;
		tail = NULL;
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
	printf("Enter 1 value\n");
	for(i=0;i<1;i++)
	{
		scanf("%d",&x);
		enqueue(x);
	}

	printf("Values obtained after 1 dequeue\n");

	for(i=0;i<1;i++)
		printf("%d\n",dequeue());
	printf("Queue after 1 dequeue (from front to back)\n");
	count=head;
	while(count != NULL)
	{
		printf("%d\n",count->key);
		count = count->next;
	}
	return 0;
}

