#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int key;
	struct NODE *left;
	struct NODE *right;
};

typedef struct NODE node;

node *root = NULL;

struct linklist
{

	node *pointer; // Queue struct
	struct linklist *next;
};

typedef struct linklist list; // Queue var

list *head = NULL;  // 
list *tail = NULL; // Queue var

list *new; // temp variable for both stack and queue

struct stack_var
{
	list *top;
};

typedef struct stack_var stack;

void push(stack *s, node *x)
{
	new = (list *)malloc(sizeof(list));
	new->pointer = x;
	new->next = s->top;
	s->top = new;
}

node * pop(stack *s)
{
	node *x;
	list *temp;
	if(s->top != NULL)
	{
		x = s->top->pointer;
		temp = s->top->next;
		s->top->next = NULL;
		s->top = temp;
	}
	else
	{
		printf("Stack is Empty\n");
		abort();
	}
	return x;
}


void enqueue(node *x)
{
	new = (list *)malloc(sizeof(list));
	new->pointer = x;
	new->next = NULL;
	if(head == NULL)
		head = new;
	else
		tail->next = new;

	tail = new;
}


node * dequeue()
{
	node *x;
	list *temp;
	if(head->next != NULL)
	{
		x = head->pointer;
		temp = head->next;
		head->next = NULL;
		head = temp;
	}
	else if(head != NULL && tail != NULL && head == tail)
	{
		x = head->pointer;
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

void insert(int val, node **leaf)
{
	if(*leaf == NULL)
	{
		*leaf = (node *) malloc(sizeof(node));
		(*leaf)->key = val;
		(*leaf)->left = NULL;
		(*leaf)->right = NULL;
	}
	else if(val < (*leaf)->key)
		insert(val, &(*leaf)->left);
	else if(val > (*leaf)->key)
		insert(val, &(*leaf)->right);
}

void iot(node **leaf)
{
	if(*leaf == NULL)
		return;
	iot(&(*leaf)->left);
	printf("%d\n",(*leaf)->key);
	iot(&(*leaf)->right);
}

void iiot(node **leaf)
{
	stack *s1 = (stack *)malloc(sizeof(stack));
	node *current = *leaf;
	int done = 0; // boolean
	while(done == 0)
	{
		if(current != NULL)
		{
			push(s1, current);
			current = current->left;
		}
		else
		{
			if(s1->top == NULL)
			{
				done = 1;
			}
			else
			{
				current = pop(s1);
				printf("%d\n",current->key);
				current = current->right;
			}
		}
	}
}

void po_t(node **leaf)
{

	if(*leaf == NULL)
		return;
	po_t(&(*leaf)->left);
	po_t(&(*leaf)->right);
	printf("%d\n",(*leaf)->key);
}

void pr_t(node **leaf)
{
	if(*leaf == NULL)
		return;
	printf("%d\n",(*leaf)->key);
	pr_t(&(*leaf)->left);
	pr_t(&(*leaf)->right);
}

void lot(node **leaf)
{
	node *x = *leaf;
	if(x == NULL)
	{	
		printf("NULL\n");
		return;
	}
	enqueue(x);
	while(head != NULL)
	{
		node *y = dequeue();
		if(y->left != NULL)
			enqueue(y->left);
		if(y->right != NULL)
			enqueue(y->right);
		printf("%d\n",y->key);
	}
}

void z_t(node **leaf)
{

	stack *s1 = (stack *)malloc(sizeof(stack));
	stack *s2 = (stack *)malloc(sizeof(stack));
	stack *curr, *other, *t;
	curr = s1;
	other = s2;

	push(curr, *leaf);
	while(s1->top != NULL || s2->top != NULL)
	{
		while(curr->top != NULL)
		{
			node *x = pop(curr);
			printf("%d\n",x->key);
			if(curr == s1)
			{
				if(x->left != NULL)
					push(other, x->left);
				if(x->right != NULL)
					push(other, x->right);
			}
			if(curr == s2)
			{
				if(x->right != NULL)
					push(other, x->right);
				if(x->left != NULL)
					push(other, x->left);
			}
		}

		t = curr;
		curr = other;
		other = t;
	}
}

int main()
{
	int i, x;
	printf("Enter 15 values\n");
	for(i=0;i<15;i++)
	{
		scanf("%d",&x);
		insert(x, &root);
	}
	printf("In-order Traversal\n");
	iot(&root);
	printf("Iterative In-order Traversal\n");
	iiot(&root);
	printf("Post-order Traversal\n");
	po_t(&root);
	printf("Pre-order Traversal\n");
	pr_t(&root);
	printf("Level-order Traversal\n");
	lot(&root);
	printf("Zig-Zag Traversal\n");
	z_t(&root);
	return 0;
}

