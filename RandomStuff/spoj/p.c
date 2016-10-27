#include <stdio.h>
int org[1000001];
int final[1000001];

int main()
{
	int len, i, j;
	int swaps = 0;
	scanf("%d",&len);
	for(i=0; i < len; i++)
		scanf("%d", &org[i]);
	for(i=0; i < len; i++)
		scanf("%d",&final[i]);
	for(i=0; i < len; i++)
	{
		if(org[i] == final[i])
			continue;
		int trans = final[i];
		int dest = -1;
		for(j=i; j < len; j++)
		{
			if(org[j] == trans)
			{
				dest = j;
				break;
			}
		}
		while(dest != i)
		{
			char t = org[dest];
			org[dest] = org[dest-1];
			org[dest-1] = t;
			dest--;
			swaps++;
		}
	}
	printf("%d\n",swaps);
	return 0;
}
