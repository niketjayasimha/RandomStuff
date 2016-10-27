#include <stdio.h>
#include <stdlib.h>

// DEREFERENCING PARENT OF ROOT WILL CAUSE SEGMENTATION FAULT
// CHECK IF ROOT BEFORE DEREFERENCING

struct NODE
{
	int key;
	int height;
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

int max(int a, int b)
{
	return a > b ? a : b;
}

int get_height(node *tree)
{
	if(tree == NULL)
		return -1;
	return max(get_height(tree->left), get_height(tree->right)) + 1;
}

node * left_rotate(node *tree, node *x)
{
	node *y;
	if(x->right != NULL)
	{
		if(x == tree)
		{
			y = x->right;
			x->par  = y;
			x->right = y->left;
			y->left = x;
			root = y;
		}

		else
		{
			y = x->right;
			x->right = y->left;
			y->par = x->par;
			if(x == x->par->left)
				x->par->left = y;
			else
				x->par->right = y;
			x->par = y;
			y->left = x;
		}
	}

	y->height = max( get_height(y->left), get_height(y->right) ) + 1;
	x->height = max( get_height(x->right), y->height ) + 1;

	return y;
}

node * right_rotate(node *tree, node *x)
{
	node *y;
	if(x->left != NULL)
	{
		if(x == tree)
		{
			y = x->left;
			x->par = y;
			x->left = y->right;
			y->right = x;
			root = y;
		}
		else
		{
			y = x->left;
			x->left = y->right;
			y->par = x->par;
			if(x == x->par->left)
				x->par->left = y;
			else
				x->par->right = y;
			x->par = y;
			y->left = x;
		}
	}

	x->height = max( get_height(x->left), get_height(x->right) ) + 1;
	y->height = max( get_height(y->left), x->height) + 1;
	
	return y;
}

node * right_left_rotate(node *tree, node *x)
{
	x->right = right_rotate(root, x->right);
	return left_rotate(root, x);
}

node * left_right_rotate(node *tree, node *x)
{	
	x->left = left_rotate(root, x->left); 
	return right_rotate(root, x);
}

void insert(int val, node **tree, node *parent)
{
	if(*tree == NULL)
	{
		*tree = (node *) malloc(sizeof(node));
		(*tree)->height = 0;
		(*tree)->key = val;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		(*tree)->par = parent;
	}
	else if(val < (*tree)->key)
	{
		insert(val, &(*tree)->left, *tree);
		if( get_height((*tree)->left) - get_height((*tree)->right) == 2)
		{
			if(val < (*tree)->left->key)
				*tree = right_rotate(root, *tree);
			else
				*tree = left_right_rotate(root, *tree);
		}
	}
	else if(val > (*tree)->key)
	{
		insert(val, &(*tree)->right, *tree);
		if( get_height((*tree)->right) - get_height((*tree)->left) == 2)
		{
			if( val > (*tree)->right->key )
				*tree = left_rotate(root, *tree);
			else
				*tree = right_left_rotate(root, *tree);
		}
	}
	
	(*tree)->height = get_height(*tree);
}

void iot(node *tree)
{
	if(tree == NULL)
		return;
	iot(tree->left);
	printf("%d\n",tree->key);
	iot(tree->right);
}


void lot(node *tree)
{
	node *x = tree;
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

void ph(node *tree)
{
	node *x = tree;
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
		printf("Height of %d is : %d\n",y->key,get_height(y));
	}
}

node * search(node *tree, int val)
{
	if(tree->key == val)
		return tree;
	if(tree->key > val)
	{
		if(tree->left == NULL)
			return NULL;
		return search(tree->left, val);
	}
	else
	{
		if(tree->right == NULL)
			return NULL;
		return search(tree->right, val);
	}
}

node * tree_max(node *tree)
{
	if(tree == NULL)
		return NULL;
	while(tree->right != NULL)
		tree = tree->right;
	return tree;
}

node * tree_min(node *tree)
{
	if(tree == NULL)
		return NULL;
	while(tree->left != NULL)
		tree = tree->left;
	return tree;
}

node * successor(node *tree, node *x)
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
		if(x == tree)
			return NULL;
	}
	return x->par;
}

node * predecessor(node *tree, node *x)
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
		if(x == tree)
			return NULL;
	}
	return x->par;
}

void draw_tree(node *tree, int indent)
{
	int i;
	for(i=0;i<indent;i++)
		printf("\t");
	printf("%d\n",tree->key);
	if(tree->right != NULL)
		draw_tree(tree->right, indent + 1);
	if(tree->left != NULL)
		draw_tree(tree->left, indent + 1);
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
	draw_tree(root, 0);

	ph(root);

	return 0;
}

