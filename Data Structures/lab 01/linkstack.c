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
list *new;


void push(int x)
{
	new = (list *)malloc(sizeof(list));
	new->key = x;
	new->next = head;
	head = new;
}

int pop()
{
	int x;
	list *temp;
	if(head != NULL)
	{
		x = head->key;
		temp = head->next;
		head->next = NULL;
		head = temp;
	}
	else
	{
		printf("Stack is Empty\n");
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
		push(x);
	}

	printf("Values obtained after 2 pops\n");

	for(i=0;i<2;i++)
		printf("%d\n",pop());
	printf("Stack after 2 pops (from top to bottom)\n");
	count=head;
	while(count != NULL)
	{
		printf("%d\n",count->key);
		count = count->next;
	}
	return 0;
}

