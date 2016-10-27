#include <stdio.h>
int main()
{
	int teamno=0, p1, p2, p3, a1, a2, a3;
	int totaltime, totalatts; //initialize to zero after scanf
	int t1,t2,t3;
	while(scanf("%d %d %d %d %d %d",&p1,&p2,&p3,&a1,&a2,&a3)!=EOF)
	{
		totaltime=0; totalatts=0;
		t1=t2=t3=0;
		teamno++;
		if(p1>0)
		{
			t1=p1+((a1-1)*20*60);
			totalatts+=1;
		}
		if(p2>0)
		{
			t2=p2+((a2-1)*20*60);
			totalatts+=1;
		}
		if(p3>0)
		{
			t3=p3+((a3-1)*20*60);
			totalatts+=1;
		}
		totaltime=t1+t2+t3;
		printf("team %d: %d, %d\n",teamno,totalatts,totaltime);
	}
	return 0;
}
