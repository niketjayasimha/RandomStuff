#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int key;
	struct NODE *a[4];
	struct NODE *parent;
	int noc;
};

typedef struct NODE node;
node *root = NULL;

struct BNODE
{
	int key;
	struct BNODE *left;
	struct BNODE *right;
};

typedef struct BNODE bnode;
bnode *broot = NULL;
struct linklist
{

	node *pointer;
	struct linklist *next;
};

typedef struct linklist list;

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

void bin_insert(int val, bnode **leaf)
{
	if(*leaf == NULL)
	{
		*leaf = (bnode *) malloc(sizeof(node));
		(*leaf)->key = val;
		(*leaf)->left = NULL;
		(*leaf)->right = NULL;
	}
	else if(val < (*leaf)->key)
		bin_insert(val, &(*leaf)->left);
	else if(val > (*leaf)->key)
		bin_insert(val, &(*leaf)->right);
}


void create_tree(node **leaf)
{
	int i, exit;
	*leaf = (node *)malloc(sizeof(node));
	enqueue(*leaf);
	while(head != NULL)
	{
		node *y = dequeue();
		printf("Enter key value\n");
		scanf("%d",&y->key);
		printf("Enter number of children for %d\n",y->key);
		scanf("%d",&y->noc);
		
		for(i=0;i<y->noc;i++)
		{
			node *temp = malloc(sizeof(node));
			temp->parent = y;
			y->a[i] = temp;
			enqueue(temp);
		}
	}
	free(head);
	free(tail);
}
int countchild(node *leaf)
{
	int i, count = 0;
	for(i=0; i<4; i++)
	{
		if(leaf->a[i]!= NULL)
			count++;
	}
	return count;
}

node * getchild(node *leaf, int which)
{
	return leaf->a[which];
}

void level_insert(node **leaf)
{
	head = NULL;
	tail = NULL;
	int i;
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
		for(i=0;i<4;i++)
		{
			if(y->a[i] != NULL)
				enqueue(y->a[i]);
		}
		bin_insert(y->key, &broot);
	}
}

void lot(bnode **leaf)
{
	bnode *x = *leaf;
	if(x == NULL)
	{	
		printf("NULL\n");
		return;
	}
	enqueue(x);
	while(head != NULL)
	{
		bnode *y = dequeue();
		if(y->left != NULL)
			enqueue(y->left);
		if(y->right != NULL)
			enqueue(y->right);
		printf("%d\n",y->key);
	}
}

int main()
{
	create_tree(&root);
	level_insert(&root);
	printf("Output when created Binary Tree is traversed by level:\n");
	lot(&broot);
	return 0;
}

