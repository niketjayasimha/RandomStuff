#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int q=0, h=0, t=0;
	char a[5];
	int i, pizza=0, min;
	for(i=0;i<n;i++)
	{
		scanf("%s",a);
		if(strcmp("1/2",a)==0)
			h++;
		else if(strcmp("3/4",a)==0)
			t++;
		else
			q++;
	}
	if(q && t)
	{
		min = (q<t)? q : t;
		q=q-min;
		t=t-min;
		pizza+=min;
	}
	if(q>1)
	{
		h+=q/2;
		q%=2;
	}
	if(h>1)
	{
		pizza+=h/2;
		h%=2;
	}
	if(h||q)
	{
		pizza++;
	}
	printf("%d\n",t+pizza+1);
	return 0;
}
