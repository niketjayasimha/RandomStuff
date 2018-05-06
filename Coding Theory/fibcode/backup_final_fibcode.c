/*	

	Name: Sriniket Jayasimha
	ID: 201101026
	Contact Number: 7405588314
	email: 201101026@daiict.ac.in

	Program Details:

	This program implements the encoding and decoding of Fibonacci Codes.
	A sample file has been attached which contains 100 random 32-bit 
	integers. Another file contains the corresponding code words of those
	100 numbers.
	Fibonacci coding encodes positive integers into binaray code words.
	Each code word ends with "11" and contains no other instances of "11"
	before the end. This particular attribute makes this code robust
	against insertion and deletion.

	To encode an integer N:
	1.	Find the largest Fibonacci number equal to or less than N; 
		subtract this number from N, keeping track of the remainder.
	2.	If the number subtracted was the ith Fibonacci number F(i), 
		put a 1 in place i−2 in the code word (counting the left most 
		digit as place 0).
	3.	Repeat the previous steps, substituting the remainder for N, 
		until a remainder of 0 is reached.
	4.	Place an additional 1 after the rightmost digit in the code word.

	To decode a codeword N:
	If d(0), d(1), ...., d(k) represent the digits of the code word
	representing N, then we have:

	N = Sigma(i = 0 to k - 1) {d(i) * F(i + 2)}, and d(k) = d(k - 1) = 1
	where F(i) is the ith Fibonacci Number.

	Program Usage:

	For decoding Fibonacci codes: ./a.out -d
	For encoding Fibonacci codes: ./a.out -e
	Then in separate lines, type the codewords or integers you wish to 
	encode or decode.
	The program will run until EOF is detected.
	Use Ctrl + D in Linux or Ctrl + Z in Windows to enter an EOF character.
	Alternatively, you can use I/O redirects (< / >) to give the input to 
	the program or write to a file.

	This C code was compiled using gcc 4.7.2 running on a 64-bit version of 
	Ubuntu 12.10.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

long long decode(char *n)
{
	long long sum = 0;
	int i;
	int k = strlen(n) - 1;
	for(i = 0; i < k; i++)
	{
		sum += (n[i] - '0') * A[i+2];
	}
	return sum;
}

void print_usage()
{
	printf("\n\nUsage:\nFor decoding Fibonacci codes: ./a.out -d\n");
	printf("For encoding Fibonacci codes: ./a.out -e\n");
	printf("Then in separate lines, type the codewords or integers you wish to encode or decode.\n");
	printf("The program will run until EOF is detected.\n");
	printf("Use Ctrl + D in Linux or Ctrl + Z in Windows to enter an EOF character.\n");
	printf("Alternatively, you can use I/O redirects (< / >) to give the input to the program");
	printf(" or write to a file.\n\n\n");
}
	
	

int main(int argc, char *argv[])
{
	gen_fib_seq();
	long long n;
	char s[100];
	if(argc == 1)
	{
		print_usage();
		return 0;
	}
	if(strcmp(argv[1], "-e") == 0)
	{
		while(scanf("%lld", &n) != EOF)
		{
			char *x = encode(n);
			printf("%s\n", x);
		}
	}

	else if(strcmp(argv[1], "-d") == 0)
	{
		while(scanf("%s", s) != EOF)
			printf("%lld\n", decode(s));
	}

	else
		print_usage();
	return 0;
}
