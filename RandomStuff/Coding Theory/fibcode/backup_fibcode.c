/*	Name: Sriniket Jayasimha
	ID: 201101026

	f(80) = 23416728348467685

	*/

#include <stdio.h>
#include <stdlib.h>

#define LARGEST_FIB_NO 23416728348467685

long long A[80];
char code[100];
void gen_fib_seq()
{
	A[0] = 0; A[1] = 1;
	int i;
	for(i = 2; i < 80; i++)
		A[i] = A[i-1] + A[i-2];
}

int find_largest_fib(long long n)
{
	int i;
	if(n > LARGEST_FIB_NO)
	{
		printf("Number out of bounds!\n");
		exit(0);
	}
	
	if(n == 1)
		return 2;
	for(i = 0; i < 80; i++)
	{
		if(A[i] == n)
			return i;
		else if (A[i] > n)
			return i - 1;
	}
}

char * encode(long long n)
{
	int i = 0, j = 0;
	for(; j < 100; j++)
		code[j] = '0';
	int rem = n;
	while(rem > 0)
	{
		int index = find_largest_fib(rem);
		rem = rem - A[index];
		code[index - 2] = '1';
		if(i == 0)
		{
			code[index - 1] = '1';
			code[index] = '\0';
			i++;
		}
	}
	return code;
}

int main()
{
	gen_fib_seq();
	long long n;
	while(scanf("%lld", &n) != EOF)
	{
		char *x = encode(n);
		printf("%s\n", x);
	}
	return 0;
}
