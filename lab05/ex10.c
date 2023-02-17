#include <stdio.h>

#define DAYS_PER_YEAR 365
#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24
#define MONTHS_PER_YEAR 12

typedef struct {

	int d, m, y;

} Date;

typedef struct {

	int h, m;

} Time;

int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int i, total;

	Date date = { 1, 1, 2022 };
	Time time = { 0 };

	scanf("%d", &total); /* Total of minutes. */

	time.m += total % MINUTES_PER_HOUR;

	total /= MINUTES_PER_HOUR; /* Total of hours. */

	time.h += total % HOURS_PER_DAY;

	total /= HOURS_PER_DAY; /* Total of days. */

	date.y += total / DAYS_PER_YEAR;

	total %= DAYS_PER_YEAR; /* Total of days in 1 year. */

	for (i = 0; total > month_days[i]; i++)
	{
		date.m += month_days[i];
		total -= month_days[i];
	}

	date.m += total;

	printf("%02d-%02d-%04d %02d:%02d", date.d, date.m, date.y, time.h, time.m);

	return 0;
}
