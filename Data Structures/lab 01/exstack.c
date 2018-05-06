/* Q5 a
 *	1. Pop upto v1 to temp1.
 *	2. Pop remaining upto v2 to temp2.
 *	3. Pop 1st of temp1 to org.
 *	4. Pop 1st of temp2 to temp1.
 *	5. Pop full temp2 to org.
 *	6. Pop full temp1 to org.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

struct STACK
{
	int s[MAXSIZE];
	int top;
	int bottom ;
};

typedef struct STACK stack;

stack org = { {0,0,0,0,0},0,0};
stack temp1 = {	{0,0,0,0,0},0,0};
stack temp2 = {	{0,0,0,0,0},0,0};

//stack *org = (stack *)malloc(sizeof(stack));
//stack *temp1 = (stack *)malloc(sizeof(stack));
//stack *temp2 = (stack *)malloc(sizeof(stack));


void push(stack *a, int x)
{
	if(a->top > MAXSIZE-1)
	{
		printf("Stack is full\n");
		abort();
	}
	a->s[a->top] = x;
	a->top++;
}

int pop(stack *a)
{
	if(a->bottom == a->top)
	{
		printf("Stack is empty\n");
		abort();
	}

	else
	{
		a->top--;
		return a->s[a->top];

	}
}

void exchange(stack *a, int v1, int v2)
{
	int x;
	while(a->top != a->bottom)
	{
		if(a->s[a->top-1] == v1 || a->s[a->top-1] == v2)
		{
			push(&temp1, pop(a));
			break;
		}
		else
		{
			push(&temp1, pop(a));
			
		}
	}
	while(a->top != a->bottom)
	{
		if(a->s[a->top-1] == v1 || a->s[a->top-1] == v2)
		{
			push(&temp2, pop(a));
			break;
		}
		else
		{
			push(&temp2, pop(a));
		}
	}
	push(a,pop(&temp1));
	push(&temp1, pop(&temp2));

	while(temp2.top != temp2.bottom)
		push(a,pop(&temp2));
	
	while(temp1.top != temp1.bottom)
		push(a,pop(&temp1));	

}
int main()
{
	int i, x, y, z;
	printf("Enter %d values\n",MAXSIZE);
	for(i=0;i<MAXSIZE;i++)
	{
		scanf("%d",&x);
		push(&org,x);
	}
	printf("Enter the two values you want to exchange\n");
	scanf("%d %d",&y,&z);
	exchange(&org,y,z);
	printf("Modified stack is\n");
	for(i=0; i < org.top; i++)
		printf("%d\n",org.s[i]);
	return 0;
}
