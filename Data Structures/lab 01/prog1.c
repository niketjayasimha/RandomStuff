/*Q1
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


void add(int x)
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

list * search(int x)
{
	list *temp;
	temp = head;

	while(temp != NULL)
	{
		if(temp->key == x)
			return temp;
		else
			temp = temp->next;
	}
	return NULL;
}

int delete(int x)
{
	list *temp;
	temp = head;
	if(temp->key == x)
	{	
		head = temp->next;
		return x;
	}
	while(temp->next != NULL)
	{
		if(temp->next->key == x)
		{
			temp->next = temp->next->next;
		}
		else
			temp = temp->next;
	}
	return x;
}

int main()
{
	int x, i;
	printf("Enter 10 values\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&x);
		add(x);
	}
	new = head;
	printf("Printing linked list:\n");
	while(new)
	{
		printf("%d\n",new->key);
		new = new->next;
	}
	printf("Enter value to search\n");
	scanf("%d",&x);
	printf("Search: %p\n",search(x));
	printf("Enter value to delete\n");
	scanf("%d",&x);
	delete(x);
	printf("New Linked List:\n");
	new = head;
	while(new)
	{
		printf("%d\n",new->key);
		new = new->next;
	}
	return 0;
}
