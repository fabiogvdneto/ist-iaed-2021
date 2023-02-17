#include <stdio.h> 

int main()
{
	int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int day, month, year, hour, min;

	scanf("%d-%d-%d%d:%d", &day, &month, &year, &hour, &min);

	year -= 2022;
	month -= 1;
	day -= 1;

	day += year * 365;

	while (month-- > 0)
		day += month_days[month];

	hour += day * 24;
	min += hour * 60;

	printf("%d", min);

	return 0;
}
