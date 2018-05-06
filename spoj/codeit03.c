#include <stdio.h>

char days[7][15] = 
		{
			"Sunday", "Monday", "Tuesday", "Wednesday", 
			"Thursday", "Friday", "Saturday"
		};

int x[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

int main()
{
	int day, month, year, t, dow;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &day, &month, &year);
		year -= month < 3;
		dow = (year + year/4 - year/100 + year/400 +x[month-1] + day) % 7;
		printf("%s\n", days[dow]);
	}
	return 0;
}
