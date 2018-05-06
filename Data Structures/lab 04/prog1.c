#include <stdio.h>
#include <stdlib.h>

// DEREFERENCING PARENT OF ROOT WILL CAUSE SEGMENTATION FAULT
// CHECK IF ROOT BEFORE DEREFERENCING

struct NODE
{
	int key;
	struct NODE *left;
	struct NODE *right;
	struct NODE *par;
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

void insert(int val, node **leaf, node *parent)
{
	if(*leaf == NULL)
	{
		*leaf = (node *) malloc(sizeof(node));
		(*leaf)->key = val;
		(*leaf)->left = NULL;
		(*leaf)->right = NULL;
		(*leaf)->par = parent;
	}
	else if(val < (*leaf)->key)
		insert(val, &(*leaf)->left, *leaf);
	else if(val > (*leaf)->key)
		insert(val, &(*leaf)->right, *leaf);
}

void iot(node *leaf)
{
	if(leaf == NULL)
		return;
	iot(leaf->left);
	printf("%d\n",leaf->key);
	iot(leaf->right);
}


void lot(node *leaf)
{
	node *x = leaf;
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

void pp(node *leaf)
{
	node *x = leaf;
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
		if(y->par != NULL)
			printf("Parent of %d is : %d\n",y->key,y->par->key);
	}
}

node * search(node *leaf, int val)
{
	if(leaf->key == val)
		return leaf;
	if(leaf->key > val)
	{
		if(leaf->left == NULL)
			return NULL;
		return search(leaf->left, val);
	}
	else
	{
		if(leaf->right == NULL)
			return NULL;
		return search(leaf->right, val);
	}
}

node * tree_max(node *leaf)
{
	if(leaf == NULL)
		return NULL;
	while(leaf->right != NULL)
		leaf = leaf->right;
	return leaf;
}

node * tree_min(node *leaf)
{
	if(leaf == NULL)
		return NULL;
	while(leaf->left != NULL)
		leaf = leaf->left;
	return leaf;
}

node * successor(node *leaf, node *x)
{
	if(x == NULL)
		return NULL;
	if(x->right != NULL)
		return tree_min(x->right);
	if(x->par == NULL)	// If program runs with SIGSEGV, add root check condition
		return x->par;
	while(x == x->par->right)
	{
		x = x->par;
		if(x == leaf)
			return NULL;
	}
	return x->par;
}

node * predecessor(node *leaf, node *x)
{
	if(x == NULL)
		return NULL;
	if(x->left != NULL)
		return tree_max(x->left);
	if(x->par == NULL)
		return x->par;
	while(x == x->par->left)
	{
		x = x->par;
		if(x == leaf)
			return NULL;
	}
	return x->par;
}

void draw_tree(node *leaf, int indent)
{
	int i;
	for(i=0; i < indent; i++)
		printf("\t");
	printf("%d\n",leaf->key);
	if(leaf->left != NULL)
		draw_tree(leaf->left, indent + 1);
	if(leaf->right != NULL)
		draw_tree(leaf->right, indent + 1);
}

int main()
{
	int i, x;
	node *temp_par = NULL;
	printf("Enter 15 values\n");
	for(i=0;i<15;i++)
	{
		scanf("%d",&x);
		insert(x, &root, temp_par);
	}
	
	////////////////////////////////////////////////////////////////
	
	printf("In-order Traversal\n");
	iot(root);
	
	////////////////////////////////////////////////////////////////
	
	printf("Level-order Traversal\n");
	lot(root);
	
	//pp(root);
	
	////////////////////////////////////////////////////////////////

	printf("Enter the value you want to search for\n");
	scanf("%d",&x);
	node *y = search(root, x);
	if(y == NULL)
		printf("Key value %d wasn't found\n",x);
	else
		printf("Address of node with key value %d is %p\n",x,y);

	/////////////////////////////////////////////////////////////////
	
	printf("Maximum value in tree = %d\n",tree_max(root)->key);
	printf("Maximum value in tree = %d\n",tree_min(root)->key);

	////////////////////////////////////////////////////////////////
	printf("Enter the value whose successor you want to find\n");
	scanf("%d",&x);
	y = successor(root, search(root, x));
	if(y == NULL)
		printf("The given node has no successor\n");
	else
		printf("The successor of %d is %p and its key is %d\n",x,y,y->key);
	
	///////////////////////////////////////////////////////////////

	printf("Enter the value whose predecessor you want to find\n");
	scanf("%d",&x);
	y = predecessor(root, search(root, x));
	if(y == NULL)
		printf("The given node has no predecessor\n");
	else
		printf("The predecessor of %d is %p and its key is %d\n",x,y,y->key);

	//////////////////////////////////////////////////////////////
	return 0;
}

