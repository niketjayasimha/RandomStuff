#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 405

char stack[MAXSIZE];

int top = 0;

void push(char x)
{
	if(top > MAXSIZE - 1)
	{
		printf("Error : Stack overflow\n");
		abort();
	}
	stack[top] = x;
	top++;
}

char pop()
{
	if(top == 0)
	{
		printf("Error : Stack Empty\n");
		abort();
	}
	top--;
	return stack[top];
}

int priority(char a)
{
	if(a == '+' || a == '-')
		return 1;
	else if(a == '*' || a == '/')
		return 2;
	else
		return 3;
}

int isoperator(char x)
{
	if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
		return 1;
	else
		return 0;
}
int main()
{
	int t, x, i, l;

	char A[MAXSIZE];

	scanf("%d",&t);
	while(t--)
	{
		scanf("%*c%[^\t\n]",A);
		l = strlen(A);
		for(i = 0; i < l; i++)
		{
			if((int)A[i] >= 97 && (int)A[i] <= 122)
				printf("%c",A[i]);
			else if(A[i] == '(')
				push(A[i]);
			else if(A[i] == ')')
			{
				while(stack[top - 1] != '(')
					printf("%c",pop());
				pop();
			}
			else if(isoperator(A[i]))
			{
				while(top != 0)
				{
					if((priority(stack[top - 1]) < priority(A[i]) || stack[top - 1] == '('))
						break;
					printf("%c",pop());
				}
				push(A[i]);
			}
		}
		while(top != 0)
		{
			if(stack[top-1]!='(')
				printf("%c",pop());
		}
		printf("\n");
	}
	return 0;
}

				

