#include <stdio.h>
int main()
{
	int a, b, c;
	//int i, j, t;
	//int A[3];

	//scanf("%d %d %d",&A[0], &A[1],&A[2]);

/*	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			if(A[j]>A[j+1])
			{
				t = A[j];
				A[j] = A[j+1];
				A[j+1] = t;
			}
		}
	}

	a = A[0]; b = A[1]; c = A[2];
*/
	scanf("%d %d %d",&a,&b,&c);
	printf("%d\n",((b+a-1)*(c+a-1))-(a*(a-1)));
	return 0;
}
