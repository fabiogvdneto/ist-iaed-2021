/*
 * File: 'airport.c'.
 * Author: Fábio Neto (ist1104126).
 * Description: Airport system for managing flights and reservations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airport.h"
#include "ctype.h"
#include "sort.h"
#include "arrays.h"
#include "hashtable.h"

static Date sysdate = { 1, 1, 2022 }; /* The system date. */

static Airport *airports[AIRPORTS_MAX]; /* An array for storing airports. */
static Flight  *flights[FLIGHTS_MAX];   /* An array for storing flights. */

static int airports_count; /* Number of airports currently stored in the airports array. */
static int flights_count;  /* Number of flights currently stored in the flights array. */

/* VALIDATIONS */

/*
 * Returns TRUE if the given date is valid, otherwise FALSE.
 */
bool validate_date(Date date) {
	int mins = date_diff(sysdate, date);
	return (mins >= 0) && (mins <= MINUTES_PER_YEAR);
}

/*
 * Returns TRUE if the given string is a valid airport id, otherwise FALSE.
 */
bool validate_airport_id(char *id) {
	while (*id != '\0') if (!isupper(*id++)) return FALSE;
	return TRUE;
}

/*
 * Returns TRUE if the given string is a valid flight code, otherwise FALSE.
 */
bool validate_flight_code(char *code) {
	int letters = 0;
	int digits  = 0;

	while (code[letters]        != '\0' && isalpha(code[letters])) letters++;
	while (code[letters+digits] != '\0' && isdigit(code[letters+digits])) digits++;

	if (code[letters]        == '0')  return FALSE;
	if (code[letters+digits] != '\0') return FALSE;

	return (letters >= 2) && (letters <= 4) && (digits >= 1) && (digits <= 4);
}

/*
 * Returns TRUE if the given time is a valid flight duration, otherwise FALSE.
 */
bool validate_flight_duration(Time time) {
	return (time_to_mins(time) <= DURATION_MAX);
}

/*
 * Returns TRUE if the given integer is a valid flight capacity, otherwise FALSE.
 */
bool validate_flight_capacity(int cap) {
	return (cap >= CAPACITY_MIN);
}

/* UTILS */

/*
 * Prints (into string) a flight uuid based on its code and date.
 */
void print_flight_uuid(char *string, char *code, Date date) {
	sprintf(string, "%02d%02d%04d%s", date.d, date.m, date.y, code);
}

/*
 * Returns the number of flights departing from the given airport.
 */
int count_departures(Airport *a) {
	int i = 0, count = 0;

	while (i < flights_count)
		if (!strcmp(flights[i++]->departure, a->id))
			count++;

	return count;
}

/*
 * Returns the number of airports currently stored in the system.
 */
int count_airports() {
	return airports_count;
}

/*
 * Returns the number of flights currently stored in the system.
 */
int count_flights() {
	return flights_count;
}

/* DATA MANIPULATION */

/*
 * Updates the system date to the given date.
 */
void update_date(Date date) {
	sysdate = date;
}

/*
 * Compares the two given airports.
 */
int cmp_airports(Airport *a1, Airport *a2) {
	return strcmp(a1->id, a2->id);
}

/*
 * Adds the given airport to the system.
 */
void add_airport(Airport *a) {
	sorted_array_add(a, airports, airports_count++, cmp_airports);
}

/*
 * Adds the given flight to the system.
 */
void add_flight(Flight *f) {
	flights[flights_count++] = f;

	/* Adds the dummy head to the table. */
	table_add(f->uuid, f->reservations);
}

/*
 * Compares the airport id.
 */
int cmp_airport_id(Airport *a, char *id) {
	return strcmp(a->id, id);
}

/*
 * Finds an airport (whose id matches with the given string)
 * and returns its pointer, or NULL if not found.
 */
Airport* find_airport(char *id) {
	int pos = -1;
	binary_search(id, airports, airports_count, cmp_airport_id, pos);
	return (pos == -1) ? NULL : airports[pos];
}

/*
 * Finds a flight (whose code and date matches with the given args)
 * and returns its pointer, or NULL if not found.
 */
Flight* find_flight(char *code, Date date) {
	char uuid[FLIGHT_UUID_SIZE+1];
	Reservation *head;

	print_flight_uuid(uuid, code, date);
	head = table_lookup(uuid);
	
	/* We can access the flight through the dummy head. */
	return head ? head->flight : NULL;
}

/* COMPARES */

/*
 * Compares two flights by departure (being i and j its positions in the array).
 */
int cmp_flight_departures(int i, int j) {
	return (flights[i]->instant > flights[j]->instant);
}

/*
 * Compares two flights by arrival (being i and j its positions in the array).
 */
int cmp_flight_arrivals(int i, int j) {
	return flights[i]->arrival_instant > flights[j]->arrival_instant;
}

/* IO */

/*
 * Prints the given airport to the standard output.
 */
void print_airport(Airport *a) {
	printf("%s %s %s %d\n", a->id, a->city, a->country, count_departures(a));
}

/*
 * Executes print_airport for each airport in the system.
 */
void print_airports() {
	int i = 0;
	while (i < airports_count) print_airport(airports[i++]);
}

/*
 * Prints the given flight to the standard output.
 */
void print_flight(Flight *f) {
	printf("%s %s %s %02d-%02d-%04d %02d:%02d\n",
			f->code, f->departure, f->arrival,
			f->date.d, f->date.m, f->date.y, f->time.h, f->time.m);
}

/*
 * Executes print_flight for each flight in the system.
 */
void print_flights() {
	int i = 0;
	while (i < flights_count) print_flight(flights[i++]);
}

/*
 * Prints all the flights departing from the given airport.
 */
void print_flights_departing(char *id) {
	int matches[FLIGHTS_MAX];
	int i, count = 0;

	for (i = 0; i < flights_count; i++)
		if (!strcmp(flights[i]->departure, id))
			matches[count++] = i;

	sort(matches, count, cmp_flight_departures);

	for (i = 0; i < count; i++) {
		Flight *f = flights[matches[i]];

		printf("%s %s %02d-%02d-%04d %02d:%02d\n",
			f->code, f->arrival, f->date.d, f->date.m,
			f->date.y, f->time.h, f->time.m);
	}
}

/*
 * Prints all the flights arriving to the given airport.
 */
void print_flights_arriving(char *id) {
	int matches[FLIGHTS_MAX];
	int i, count = 0;

	for (i = 0; i < flights_count; i++)
		if (!strcmp(flights[i]->arrival, id) && date_diff(sysdate, mins_to_date(flights[i]->arrival_instant)) >= 0)
			matches[count++] = i;

	sort(matches, count, cmp_flight_arrivals);

	for (i = 0; i < count; i++) {
		Flight *f;
		Date date;
		Time time;

		f    = flights[matches[i]];
		date = mins_to_date(f->arrival_instant);
		time = mins_to_time(f->arrival_instant);

		printf("%s %s %02d-%02d-%04d %02d:%02d\n",
				f->code, f->departure, date.d, date.m, date.y, time.h, time.m);
	}
}

/* PROJECT 2 */

/*
 * Returns the number of available seats in the given flight.
 */
int count_available_seats(Flight *f) {
	return f->capacity - f->occupacity;
}

/*
 * Adds the given reservation to the given flight.
 */
void add_reservation(Flight *f, Reservation *r) {
	Reservation *curr = f->reservations;

	while (curr->next && strcmp(r->code, curr->next->code) > 0) curr = curr->next;

	if (curr->next) curr->next->prev = r;

	r->next = curr->next;
	curr->next = r;
	r->prev = curr;
	r->flight = f;
	f->occupacity += r->seats;

	table_add(r->code, r);
}

/*
 * Frees the memory allocated by the given reservation.
 */
void free_reservation(Reservation *r) {
	free(r->code);
	free(r);
}

/*
 * Frees the memory allocated by the given flight.
 */
void free_flight(Flight *f) {
	Reservation *curr = f->reservations->next;
	Reservation *next;

	while (curr) {
		next = curr->next;
		free_reservation(curr);
		curr = next;
	}

	free(f->reservations);
	free(f);
}

/*
 * Deletes a reservation (whose code matches with the given string),
 * returning TRUE if the reservation got deleted, or FALSE if not found.
 */
bool delete_reservation(char *code) {
	Reservation *r = table_delete(code);

	if (!r) return FALSE;

	r->prev->next = r->next;
	
	if (r->next) r->next->prev = r->prev;

	r->flight->occupacity -= r->seats;

	free_reservation(r);
	return TRUE;
}

/*
 * Deletes a flight (whose code matches with the given string),
 * returning TRUE if the flight got deleted, or FALSE if not found.
 */
bool delete_flights(char *code) {
	int i = 0, j = 0;
	Flight *curr;

	while (i < flights_count) {
		curr = flights[i++];

		if (!strcmp(curr->code, code) && date_diff(sysdate, mins_to_date(curr->arrival_instant)) < 0) {
			table_delete(curr->uuid);
			free_flight(curr);
		} else if (j != i) {
			flights[j++] = curr;
		}
	}

	return ((flights_count = j) != i);
}

/*
 * Returns TRUE if the given reservation exists, otherwise FALSE.
 */
bool exists_reservation(char *code) {
	return (table_lookup(code) != NULL);
}

/*
 * Retuns TRUE if the given string is a valid reservation code, otherwise FALSE.
 */
bool validate_reservation_code(char *code) {
	int size;

	for (size = 0; code[size] != '\0'; size++)
		if (!isupper(code[size]) && !isdigit(code[size]))
			return FALSE;
	
	return (size >= 10);
}

/*
 * Prints all the reservations of the given flight.
 */
void print_reservations(Flight *f) {
	Reservation *curr;
	for (curr = f->reservations->next; curr; curr = curr->next)
		printf("%s %d\n", curr->code, curr->seats);
}

/*
 * Frees all the memory allocated by the system until now.
 */
void free_all() {
	while (flights_count--  > 0) free_flight(flights[flights_count]);
	while (airports_count-- > 0) free(airports[airports_count]);
	table_clear();
}

/*
 * Emergency function, to be executed when memory failed to be allocated.
 * Executes free_all and exit.
 */
void exit_no_memory() {
	puts("No memory");
	free_all();
	exit(EXIT_FAILURE);
}
