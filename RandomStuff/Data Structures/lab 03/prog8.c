#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	int key;
	int pri;
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

void insert(int valk, int valp, node **leaf)
{
	if(*leaf == NULL)
	{
		*leaf = (node *) malloc(sizeof(node));
		(*leaf)->key = valk;
		(*leaf)->pri = valp;
		(*leaf)->left = NULL;
		(*leaf)->right = NULL;
	}
	else if(valk < (*leaf)->key)
		insert(valk, valp, &(*leaf)->left);
	else if(valk > (*leaf)->key)
		insert(valk, valp, &(*leaf)->right);
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
		printf("(%d/%d)\n",y->key,y->pri);
	}
}

void ascendsort(int **A, int size)
{
	int i, j, t1, t2;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{
			if(A[1][j] > A[1][j+1])
			{
				t1 = A[1][j];
				A[1][j] = A[1][j+1];
				A[1][j+1] = t1;

				t2 = A[0][j];
				A[0][j] = A[0][j+1];
				A[0][j+1] = t2;
			}
		}
	}
}

void treapcreate(int **A, int size)
{
	int i;
	for(i=0;i<size;i++)
		insert(A[0][i], A[1][i], &root);
}
int main()
{
	int i, j, size;
	printf("Enter number of elements\n");
	scanf("%d",&size);
	int **S = (int **)malloc(2*sizeof(int *));
	for(i=0;i<2;i++)
		S[i] = (int *)malloc(size*sizeof(int));
	printf("Enter %d key pairs\n",size);
	for(i=0;i<size;i++)
	{
		for(j=0;j<2;j++)
			scanf("%d",&S[j][i]);
	}
	ascendsort(S,size);
	treapcreate(S,size);
	printf("Level-order Traversal\n");
	lot(&root);
	return 0;
}

