/*Q5 b 
 *	1. Remove all before start of sequence to temp1.
 *	2. Transfer sequence to temp2.
 *	3. Empty temp2 into temp1.
 *	4. Empty temp1 into org.
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

void reverse(stack *a, int v1, int v2)
{
	while(a->top != a->bottom) // all before sequence to temp1
	{
		if(a->s[a->top-1] == v1 || a->s[a->top-1] == v2)
			break;
		else
		push(&temp1, pop(a));
	}
	push(&temp2, pop(a)); // start of sequence
	while(a->top != a->bottom) // all in sequence to temp2 except end
	{
		if(a->s[a->top-1] == v1 || a->s[a->top-1] == v2)
			break;
		else
		push(&temp2, pop(a));
	}
	push(&temp2, pop(a)); // end of sequence;
	while(temp2.top != temp2.bottom) // temp2 to temp1
		push(&temp1, pop(&temp2));
	while(temp1.top != temp1.bottom)
		push(a, pop(&temp1));
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
	printf("Enter the sequence you want to reverse by entering its end points.\n");
	scanf("%d %d",&y,&z);
	reverse(&org,y,z);
	printf("Modified stack is\n");
	for(i=0; i < org.top; i++)
		printf("%d\n",org.s[i]);
	return 0;
}
