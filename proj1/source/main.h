/*

   LIBRARIES

*/

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*

   MACROS

*/

#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY    24
#define DAYS_PER_YEAR    365
#define MONTHS_PER_YEAR  12

#define MINUTES_PER_DAY  (HOURS_PER_DAY * MINUTES_PER_HOUR)
#define MINUTES_PER_YEAR (MINUTES_PER_DAY * DAYS_PER_YEAR)

#define AIRPORTS_MAX 40
#define FLIGHTS_MAX  30000

#define AIRPORT_ID_SIZE  3
#define FLIGHT_CODE_SIZE 6
#define CITY_SIZE        50
#define COUNTRY_SIZE     30

#define CAPACITY_MIN 10
#define CAPACITY_MAX 100
#define DURATION_MAX (12 * MINUTES_PER_HOUR)

/*

   ENUMS

*/

typedef enum { FALSE, TRUE } bool;

/*

   STRUCTS

*/

typedef struct {

	int d, m, y;

} date;

typedef struct {

	int h, m;

} time;

typedef char airport_id[AIRPORT_ID_SIZE + 1];
typedef char city[CITY_SIZE + 1];
typedef char country[COUNTRY_SIZE + 1];
typedef char flight_code[FLIGHT_CODE_SIZE + 1];

typedef struct {

	airport_id id;
	city city;
	country country;

} airport;

typedef struct {

	flight_code code;
	airport_id departure;
	airport_id arrival;
	date date;
	time time;
	time duration;
	int capacity;

} flight;

/*

   GLOBAL CONSTANTS

*/

/* An array whose elements are the days of each month.  */
const int acc_month_days[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

/*

	GLOBAL VARIABLES

*/

date sysdate = { 1, 1, 2022 }; /* The system date. */

int airports_count; /* Number of airports currently stored in the airports array. */
int flights_count;  /* Number of flights currently stored in the flights array. */

airport airports[AIRPORTS_MAX];  /* An array for storing the airports. */
flight flights[FLIGHTS_MAX]; /* An array for storing the flights. */

/*

   FUNCTIONS

*/

/*
 * Executes command 'a', which adds a new airport to the system.
 * Input: 'a <id> <country> <city>'.
 * Output: 'airport <id>'.
 * Errors:
 * - 'invalid airport ID' if the airport id is not valid;
 * - 'too many airports' if the system cannot handle more airports;
 * - 'duplicate airport' if the airport id is already in use.
 */
void execute_a();

/*
 * Executes command 'l', which lists the airports.
 * Input: 'l [<airport id> ...]'.
 * Output: '<airport id> <city> <country> <number of flights>' (for each airport).
 * Errors:
 * - '<airport id>: no such airport id' if the airport id does not exist.
 */
void execute_l();

/*
 * Executes command 'v', which adds a flight or lists them.
 * Input: 'v [<code>, <departure airport> <arrival airport> <date> <time> <duration> <capacity>]'.
 * Output: '<code> <departure airport> <arrival airport> <date> <time>' (if no arguments provided).
 * Errors:
 * - 'invalid flight code', if the flight code is not valid;
 * - 'flight already exists', if there is a flight with the same code and date;
 * - '<airport id>: no such airport id', if the airport id does not exist;
 * - 'too many flights', if the system cannot handle more airports;
 * - 'invalid date', if the date is in the past or more than 1 year in the future;
 * - 'invalid duration', if the duration is greater than 12 hours;
 * - 'invalid capacity', if the capacity is not a number between 10 and 100.
 */
void execute_v();

/*
 * Executes command 'p', which lists flights departing from a particular airport.
 * Input: 'p <airport id>'.
 * Output: '<flight code> <arrival airport id> <date> <hour>' (for each flight).
 * Errors:
 * - '<airport id>: no such airport id', if the airport id does not exist.
 */
void execute_p();

/*
 * Executes command 'c', which lists flights arriving at a particular airport.
 * Input: 'c <airport id>'.
 * Output: '<flight code> <departure airport id> <arriving date> <arriving hour>'.
 * Errors:
 * - '<airport id>: no such airport id', if the airport id does not exist.
 */
void execute_c();

/*
 * Executes command 't', which updates the system date.
 * Input: 't <date>'.
 * Output: '<date>'.
 * Errors:
 * - 'invalid date', if the date is in the past or more than 1 year in the future.
 */
void execute_t();

/*
 * Returns TRUE if there is already an airport with the given id, otherwise FALSE.
 */
bool exists_airport(airport_id);

/*
 * Returns TRUE if there is a flight with the given code and date, otherwise FALSE.
 */
bool exists_flight(flight_code, date);

/*
 * Returns TRUE if the given airport id is valid, otherwise FALSE.
 */
bool validate_airport_id(airport_id);

/*
 * Returns TRUE if the given flight code is valid, otherwise FALSE.
 */
bool validate_flight_code(flight_code);

/*
 * Returns TRUE if the given duration is valid, otherwise FALSE.
 */
bool validate_flight_duration(time);

/*
 * Returns TRUE if the given capacity is valid, otherwise FALSE.
 */
bool validate_flight_capacity(int);

/*
 * Returns TRUE if the given date is valid, otherwise FALSE.
 */
bool validate_date(date);

/*
 * Returns the difference, in minutes, between the first date and the second.
 */
int date_diff(date, date);

/*
 * Converts the given date to minutes and returns the result.
 */
int date_to_mins(date);

/*
 * Converts the given time to minutes and returns the result.
 */
int time_to_mins(time);

date mins_to_date(int);

/*
 * Adds the given minutes to the given date and returns the result.
 */
date date_plus(date, int);

/*
 * Converts the given minutes to time and returns the result.
 */
time mins_to_time(int);

/*
 * Prints the information related to the given airport.
 */
void print_airport(airport);

/*
 * Prints the information related to the given flight.
 */
void print_flight(flight);
