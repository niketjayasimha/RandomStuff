#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i;
	for(i = 0; i < 100; i++)
		printf("%d\n", rand() % ((int)pow(2, 32)) + 1);
	return 0;
}
