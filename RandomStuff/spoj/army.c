#include <stdio.h>
int main()
{
	int t,i,j,k;
	int ng,nm;
	int wpg,wpm;
	int wpgmax,wpmmax;
	scanf("%d",&t);
	printf("\n");
	for(i=1;i<=t;i++)
	{
		wpgmax=0;wpmmax=0;
		scanf("%d %d",&ng,&nm);
		for(j=1;j<=ng;j++)
		{
			scanf("%d",&wpg);
			if(wpg>wpgmax)
			wpgmax=wpg;
		}
		for(k=1;k<=nm;k++)
		{
			scanf("%d",&wpm);
			if(wpm>wpmmax)
			wpmmax=wpm;
		}
		if(wpgmax>=wpmmax)
		printf("Godzilla\n");
		else
		printf("MechaGodzilla\n");
	}
	return 0;
}
