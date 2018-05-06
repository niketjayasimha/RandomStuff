/*Q2
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
int stack[MAXSIZE]; 

int bottom = 0;
int top = 0;
void push(int x)
{
	if(top > MAXSIZE-1)
	{
		printf("Stack is full\n");
		abort();
	}
	stack[top] = x;
	top++;
}

int pop()
{
		if(bottom == top)
		{
			printf("Stack is empty\n");
			abort();
		}

		else
		{
			top--;
			return stack[top];
			
		}
}

int main()
{
	int i, x;
	for(i=0;i<MAXSIZE;i++)
	{
		scanf("%d",&x);
		push(x);
	}
	for(i=0;i<MAXSIZE;i++)
		printf("%d\n",pop());
	return 0;
}
