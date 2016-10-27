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

int a[1000];
int i = 0;

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
	a[i++] = leaf->key;
	iot(leaf->right);
}

double median(int x, int n)
{
	int j;
	int k = 0, count = 0;
	int b[1000];
	for(j=0; j < n; j+=x)
	{
		b[k++]= a[j];
		count++;
	}
	if(count % 2 == 0)
		return (double)(b[count/2] + b[count/2 - 1])/2.0;
	else
		return (double)(b[count/2]);
}

int main()
{
	int t, x, n;
	char op;
	node *temp_par = NULL;
	scanf("%d",&t);
	n = t;
	while(t--)
	{
		scanf("%d",&x);
		insert(x, &root, temp_par);
	}
	iot(root);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%*c%c",&op);
		if(op == 'L')
		{
			scanf("%d",&x);
			printf("%d\n",a[n-x]);
		}
		else if(op == 'T')
		{
			scanf("%d",&x);
			printf("%.1lf\n",median(x,n));
		}
	}
	return 0;
}
