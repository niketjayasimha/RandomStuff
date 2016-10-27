#include <stdio.h>
int main()
{
	long long a[6];
	int i;
	int count = 0;
	for(i=0;i<6;i++)
		scanf("%lld",&a[i]);
	for(i=0;i<6;i++)
	{
		if((a[i]/42 * 42 )==a[i])
			count++;
	}
	if(count == 6)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
