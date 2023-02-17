/*
 * File: 'date.c'.
 * Author: Fábio Neto (ist1104126).
 * Description: Date and time utilities.
 */

#include <stdio.h>
#include "date.h"

/* An array whose elements are the accumulated days of each month.  */
static const int acc_month_days[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

/*
 * Returns the difference, in minutes, between the first date and the second.
 */
int date_diff(Date bef, Date aft) {
	return date_to_mins(aft) - date_to_mins(bef);
}

/*
 * Converts the given date to minutes and returns the result.
 */
int date_to_mins(Date date) {
	date.d += date.y * DAYS_PER_YEAR;
	date.d += acc_month_days[date.m-2];

	return date.d * MINUTES_PER_DAY;
}

/*
 * Converts the given time to minutes and returns the result.
 */
int time_to_mins(Time time) {
	return time.m + (time.h * MINUTES_PER_HOUR);
}

/*
 * Converts the given minutes to date and returns the result.
 */
Date mins_to_date(int mins) {
	Date date = { 0 };

	date.d = mins / MINUTES_PER_DAY;

	date.y = date.d / DAYS_PER_YEAR;
	date.d %= DAYS_PER_YEAR;

	if (date.d == 0) {
		date.d = 365;
		date.y--;
	}

	while (date.d > acc_month_days[date.m++]);

	date.d -= acc_month_days[date.m-2];

	return date;
}

/*
 * Converts the given minutes to time and returns the result.
 */
Time mins_to_time(int mins) {
	Time time;

	time.m = mins % MINUTES_PER_HOUR;
	time.h = mins / MINUTES_PER_HOUR % HOURS_PER_DAY;

	return time;
}

/*
 * Reads the date from the standard input and returns it.
 */
Date read_date() {
	Date date;
	scanf("%d-%d-%d", &date.d, &date.m, &date.y);
	return date;
}

/*
 * Reads the time from the standard input and returns it.
 */
Time read_time() {
	Time time;
	scanf("%d:%d", &time.h, &time.m);
	return time;
}

/*
 * Prints the given date to the standard output.
 */
void print_date(Date date) {
	printf("%02d-%02d-%04d\n", date.d, date.m, date.y);
}

/*
 * Prints the given time to the standard output.
 */
void print_time(Time time) {
	printf("%02d:%02d\n", time.h, time.m);
}
