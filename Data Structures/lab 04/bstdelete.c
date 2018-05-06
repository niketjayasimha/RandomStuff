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

node * search(node *leaf, int val)
{
	if(leaf == NULL)
		return NULL;
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

void delete(node *leaf, int x)
{
	node *y = search(leaf, x);
	if(y == NULL || leaf == NULL)
		return;
	
	if(y->left == NULL && y->right == NULL)
	{
		if(y == root)
		{	root = NULL;
			return;
		}
		if(y->par->left == y)
			y->par->left = NULL;
		else if(y->par->right == y)
			y->par->right = NULL;
	}
	else if(y->left == NULL || y->right == NULL)
	{
		if(y == root)
		{
			root = (root->left) ? root->left : root->right;
			return;
		}
		if(y->left != NULL)
		{
			node *z = y->left;
			if(y->par->left == y)
			{
				z->par = y->par;
				y->par->left = z;
				free(y);
			}
			else if(y->par->right == y)
			{
				
				z->par = y->par;
				y->par->right= z;
				free(y);
			}
		}

		else if(y->right != NULL)
		{
			node *z = y->right;
			if(y->par->left == y)
			{
				z->par = y->par;
				y->par->left = z;
				free(y);
			}
			else if(y->par->right == y)
			{
				
				z->par = y->par;
				y->par->right= z;
				free(y);
			}
		}
	}
	else
	{
		node *z = successor(leaf, y);
		/*if(y == root)
		{
			int t = root->key;
			root->key = z->key;
			z->key = t;
			delete(root, t);
		}*/
		int t = y->key;
		y->key = z->key;
		z->key = t;
		delete(z, t);
	}
}

int main()
{
	int t;
	char op;
	int x;
	node *y;
	node *temp_par = NULL;
	scanf("%d",&t);
	//getchar();
	while(t--)
	{
		scanf("%*c%c",&op);
		//op = getchar();
		//getchar();
		if(op == 'I')
		{
			scanf("%d",&x);
			//getchar();
			insert(x, &root, temp_par);
			printf("OK\n");
		}
		else if(op == 'F')
		{
			scanf("%d",&x);
			//getchar();
			y = search(root, x);
			if(y == NULL)
				printf("-1\n");
			else
				printf("1\n");
		}
		else if(op == 'M')
		{
			y = tree_max(root);
			if(y == NULL)
				printf("-1\n");
			else
				printf("%d\n",y->key);
		}
		else if(op == 'm')
		{
			y = tree_min(root);
			if(y == NULL)
				printf("-1\n");
			else
				printf("%d\n",y->key);
		}
		else if(op == 'S')
		{
			scanf("%d",&x);
			//getchar();
			y = successor(root, search(root, x));
			if(y == NULL)
				printf("-1\n");
			else
				printf("%d\n",y->key);
		}
		else if(op == 'P')
		{
			scanf("%d",&x);
			//getchar();
			y = predecessor(root, search(root, x));
			if(y == NULL)
				printf("-1\n");
			else
				printf("%d\n",y->key);
		}
		else if(op == 'D')
		{
			scanf("%d",&x);
			delete(root, x);
			printf("OK\n");
		}
	}
	return 0;
}




