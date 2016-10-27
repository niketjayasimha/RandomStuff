#include <stdio.h>
// parent = (i-2)/k+1
//
// child j = k*(i-1)+j+1
//
int parent(int i, int k)
{
	return (i-2)/k+1;
}
int child(int i, int j ,int k)
{
	if(j<=k)
		return k*(i-1)+j+1;
	else
		return -1;
}
int main()
{
	printf("%d\n",parent(12,6));
	printf("%d\n",child(6,7,9));
	return 0;
}
