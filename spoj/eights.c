#include <stdio.h>
int main()
{
	long long t, k;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&k);
		switch(k)
		{
			case 1:
				printf("192\n");
				break;
			case 2:
				printf("442\n");
				break;
			case 3:
				printf("692\n");
				break;
			case 4:
				printf("942\n");
				break;
			default:
				switch(k%4)
				{
					case 0:
						printf("%lld",(k/4)-1);
						printf("942\n");
						break;
					case 1:
						printf("%lld",k/4);
						printf("192\n");
						break;
					case 2:
						printf("%lld",k/4);
						printf("442\n");
						break;
					case 3:
						printf("%lld",k/4);
						printf("692\n");
				}
		}
	}
	return 0;
}
