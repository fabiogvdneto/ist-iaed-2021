/*
 * File: 'date.h'.
 * Author: Fábio Neto (ist1104126).
 * Description: An interface for date and time utilities.
 */

#ifndef _DATE_H_
#define _DATE_H_

#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY    24
#define DAYS_PER_YEAR    365
#define MONTHS_PER_YEAR  12

#define MINUTES_PER_DAY  (HOURS_PER_DAY * MINUTES_PER_HOUR)
#define MINUTES_PER_YEAR (MINUTES_PER_DAY * DAYS_PER_YEAR)

typedef struct {
	int d, m, y;
} Date;

typedef struct {
	int h, m;
} Time;

int date_diff(Date, Date);

int date_to_mins(Date);

int time_to_mins(Time);

Date mins_to_date(int);

Time mins_to_time(int);

Date read_date();

Time read_time();

void print_date(Date);

void print_time(Time);

#endif
