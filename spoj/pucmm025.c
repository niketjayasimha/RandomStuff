#include <stdio.h>
#include <string.h>

char a[250];
int div7[] = {1,3,2,-1,-3,-2};

int toint(char x)
{
	return x -'0';
}

int last2(char *A, int l)
{
	return (10*toint(A[l-2])) + (toint(A[l-1]));
}

int last3(char *A, int l)
{
	return 100*toint(A[l-3]) + last2(A,l);
}

int test2(char *A, int l)
{
	return (toint(A[l-1]) % 2 == 0);
}

int test3(int sum)
{
	return (sum % 3 == 0);
}

int test4(char *A, int l)
{
	if(l == 1)
		return (toint(A[0]) % 4 == 0);
	else
		return (last2(A,l) % 4 == 0);
}

int test5(char *A, int l)
{
	int x = toint(A[l-1]);
	return (x == 5 || x == 0);
}

int test6(char *A, int l, int sum)
{
	return test2(A,l) && test3(sum);
}

int test7(int sum)
{
	if(sum % 7 == 0)
		return 1;
	return 0;
}

int test8(char *A, int l)
{
	if(l == 1)
		return (toint(A[0]) % 8 == 0);
	else if(l == 2)
		return (last2(A,l) % 8 == 0);
	else
		return (last3(A,l) % 8 == 0);
}

int test9(int sum)
{
	return (sum % 9 == 0);
}

int main()
{
	int digitsum, div7sum, last2, last3, l, total, i;
	while(scanf("%s",a) != EOF)
	{
		digitsum = 0;
		div7sum = 0;
		int num_occ[10] = {0};
		l = strlen(a);
		for(i = 0; i < l; i++)
		{
			num_occ[toint(a[i])] += 1;
			digitsum += toint(a[i]);
			div7sum += toint(a[l-i-1])*div7[i%6];
		}
		total = num_occ[1] + (test2(a,l) * num_occ[2]) + (test3(digitsum) * num_occ[3]) + (test4(a,l) * num_occ[4]) + (test5(a,l) * num_occ[5]) + (test6(a,l,digitsum) * num_occ[6]) + (test7(div7sum) * num_occ[7]) + (test8(a,l) * num_occ[8]) + (test9(digitsum) * num_occ[9]);
		printf("%d\n",total);
	}
}
