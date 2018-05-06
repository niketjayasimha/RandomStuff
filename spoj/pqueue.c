#include <stdio.h>
int main()
{
	int t, n, m, i, j, index, max, nqueue, minutes;
	int jobs[100];
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",&jobs[i]);
		max = -1;
		for(i = 0; i < n; ++i)
			max = (max<jobs[i])? jobs[i] : max;

		nqueue = n;
		index = 0;
		minutes = 0;
		for(;;)
		{
			if(jobs[index] == max)
			{
				if(index == m) 
				{
					minutes = minutes + 1; 
					break;
				}
				jobs[index] = -1;
				nqueue = nqueue - 1;
				minutes += 1;
				max = -1;
				for(i=0;i<n;i++)
					max = (max<jobs[i])? jobs[i] : max;
			}
			index = (index + 1) % n;
		}
		printf("%d\n", minutes);
	}
	return 0;
}
