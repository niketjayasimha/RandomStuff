#include <stdio.h>
#include <string.h>
char key[10000], cipher[10000];
int main()
{
	int t;
	int i,j,k;
	int lkey, lcipher;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s", key);
		scanf("%[^\t\n]s", cipher);
		lkey = strlen(key);

