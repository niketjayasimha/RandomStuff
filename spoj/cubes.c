#include <stdio.h>
int cube(int x)
{
	return x*x*x;
}
int main()
{
	int a,b,c,d;
	for(a=2;a<=100;a++)
	{
		for(b=2;;b++)
		{
			if(cube(a)<=cube(b))
				break;
			for(c=b+1;;c++)
			{
				if(cube(a)<=cube(b)+cube(c))
					break;
				for(d=c+1;;d++)
				{
					if(cube(a)==cube(b)+cube(c)+cube(d))
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
					else if(cube(a)<cube(b)+cube(c)+cube(d))
						break;
				}
			}
		}
	}
	return 0;
}
