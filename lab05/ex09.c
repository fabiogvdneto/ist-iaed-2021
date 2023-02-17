#include <stdio.h>

typedef struct {

	int d, m, y;

} Date;

typedef struct {

	int h, m;

} Time;

int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int to_minutes(Date, Time);

int main() {
	Date old_date, new_date;
	Time old_time, new_time;
	int old_m, new_m, res;

	scanf("%d-%d-%d%d:%d\n%d-%d-%d%d:%d",
			&old_date.d, &old_date.m, &old_date.y,
			&old_time.h, &old_time.m,
			&new_date.d, &new_date.m, &new_date.y,
			&new_time.h, &new_time.m);
	
	old_m = to_minutes(old_date, old_time);
	new_m = to_minutes(new_date, new_time);

	res = new_m - old_m;

	printf("%d", res);

	return 0;
}

int to_minutes(Date date, Time time) {
	date.d += date.y * 365;
	
	while (date.m-- > 0) date.d += month_days[date.m];

	time.h += date.d * 24;
	time.m += time.h * 60;

	return time.m;
}
