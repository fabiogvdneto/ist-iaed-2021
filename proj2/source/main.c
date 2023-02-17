/*
 * File: 'main.c'.
 * Author: Fábio Neto (ist1104126).
 * Description: A program written to handle airport flights.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airport.h"

#define INPUT_MAX 65535

/*
 * Allocates memory for an airport and reads it in the standard input.
 * Returns the airport created.
 */
Airport* read_airport() {
	Airport* new = (Airport*) malloc(sizeof(Airport));

	if (!new) exit_no_memory();

	scanf("%s %s %[^\n]", new->id, new->country, new->city);

	return new;
}

/*
 * Executes command 'a' (adds a new airport to the system).
 * Input: 'a <id> <country> <city>'.
 * Output: 'airport <id>'.
 * Errors:
 * - 'invalid airport ID' if the airport id is not valid;
 * - 'too many airports' if the system cannot handle more airports;
 * - 'duplicate airport' if the airport id is already in use.
 */
void execute_a() {
	Airport *new = read_airport();

	if (!validate_airport_id(new->id)) {
		puts("invalid airport ID");
	} else if (count_airports() >= AIRPORTS_MAX) {
		puts("too many airports");
	} else if (find_airport(new->id)) {
		puts("duplicate airport");
	} else {
		add_airport(new);
		printf("airport %s\n", new->id);
		return;
	}

	free(new);
}

/*
 * Executes command 'l' (lists the airports).
 * Input: 'l [<airport id> ...]'.
 * Output: '<airport id> <city> <country> <number of flights>' (for each airport).
 * Errors:
 * - '<airport id>: no such airport id' if the airport id does not exist.
 */
void execute_l() {
	if (getchar() == '\n') {
		print_airports();
	} else {
		Airport *airport;
		char id[AIRPORT_ID_SIZE+1];

		do {
			scanf("%s", id);

			if (!(airport = find_airport(id)))
				printf("%s: no such airport ID\n", id);
			else
				print_airport(airport);
		} while (getchar() != '\n');
	}
}

/*
 * Allocates memory for a flight and reads it from the standard input.
 * Returns the flight created.
 */
Flight* read_flight() {
	Flight *new = (Flight*) malloc(sizeof(Flight));

	if (!new) exit_no_memory();

	scanf("%s %s %s %d-%d-%d %d:%d %d:%d %d",
		new->code, new->departure, new->arrival,
		&new->date.d, &new->date.m, &new->date.y, &new->time.h, &new->time.m,
		&new->duration.h, &new->duration.m, &new->capacity);

	/* Dummy Head. */
	new->reservations = (Reservation*) malloc(sizeof(Reservation));

	if (!new->reservations) exit_no_memory();

	new->reservations->flight = new;
	new->reservations->code = NULL;
	new->reservations->prev = NULL;
	new->reservations->next = NULL;
	new->reservations->seats = 0;
	 
	print_flight_uuid(new->uuid, new->code, new->date);

	new->occupacity = 0;
	new->instant = date_to_mins(new->date) + time_to_mins(new->time);
	new->arrival_instant = new->instant + time_to_mins(new->duration);

	return new;
}

/*
 * Executes command 'v' (adds a flight or lists them all).
 * Input: 'v [<code>, <departure airport> <arrival airport> <date> <time> <duration> <capacity>]'.
 * Output: '<code> <departure airport> <arrival airport> <date> <time>'
 * (for each flight, if no arguments provided).
 * Errors:
 * - 'invalid flight code', if the flight code is not valid;
 * - 'flight already exists', if there is a flight with the same code and date;
 * - '<airport id>: no such airport id', if the airport id does not exist;
 * - 'too many flights', if the system cannot handle more airports;
 * - 'invalid date', if the date is in the past or more than 1 year in the future;
 * - 'invalid duration', if the duration is greater than 12 hours;
 * - 'invalid capacity', if the capacity is not a number between 10 and 100.
 */
void execute_v() {
	if (getchar() == '\n') {
		print_flights();
	} else {
		Flight *new = read_flight();

		if (!validate_flight_code(new->code)) {
			puts("invalid flight code");
		} else if (find_flight(new->code, new->date)) {
			puts("flight already exists");
		} else if (!find_airport(new->departure)) {
			printf("%s: no such airport ID\n", new->departure);
		} else if (!find_airport(new->arrival)) {
			printf("%s: no such airport ID\n", new->arrival);
		} else if (count_flights() >= FLIGHTS_MAX) {
			puts("too many flights");
		} else if (!validate_date(new->date)) {
			puts("invalid date");
		} else if (!validate_flight_duration(new->duration)) {
			puts("invalid duration");
		} else if (!validate_flight_capacity(new->capacity)) {
			puts("invalid capacity");
		} else {
			add_flight(new);
			return;
		}
		
		free(new->reservations);
		free(new);
	}
}

/*
 * Executes command 'p' (lists flights departing from a particular airport).
 * Input: 'p <airport id>'.
 * Output: '<flight code> <arrival airport id> <date> <hour>' (for each flight).
 * Errors:
 * - '<airport id>: no such airport id', if the airport id does not exist.
 */
void execute_p() {
	char id[AIRPORT_ID_SIZE+1];

	scanf("%s", id);

	if (!find_airport(id)) {
		printf("%s: no such airport ID\n", id);
	} else {
		print_flights_departing(id);
	}
}

/*
 * Executes command 'c' (lists flights arriving at a particular airport).
 * Input: 'c <airport id>'.
 * Output: '<flight code> <departure airport id> <arriving date> <arriving hour>'.
 * Errors:
 * - '<airport id>: no such airport id', if the airport id does not exist.
 */
void execute_c() {
	char id[AIRPORT_ID_SIZE+1];

	scanf("%s", id);

	if (!find_airport(id)) {
		printf("%s: no such airport ID\n", id);
	} else {
		print_flights_arriving(id);
	}
}

/*
 * Executes command 't' (updates the system date).
 * Input: 't <date>'.
 * Output: '<date>'.
 * Errors:
 * - 'invalid date', if the date is in the past or more than 1 year in the future.
 */
void execute_t() {
	Date new = read_date();

	if (!validate_date(new)) {
		puts("invalid date");
	} else {
		update_date(new);
		print_date(new);
	}
}

/*
 * Allocates memory for a reservation and reads it from the standard input.
 * Retuns the created reservation.
 */
Reservation* read_reservation() {
	char buffer[INPUT_MAX];

	Reservation *r = (Reservation*) malloc(sizeof(Reservation));

	if (!r) exit_no_memory();
	
	scanf("%s %d", buffer, &r->seats);

	r->code = (char*) malloc(sizeof(char)*(strlen(buffer)+1));
	
	if (!r->code) exit_no_memory();

	strcpy(r->code, buffer);

	return r;
}

/*
 * Executes command 'r' (adds a reservation or lists a flight's reservations).
 * Input: 'r <flight code> <date> [<reservation code> <passenger number>]'.
 * Output: '<reservation code> <passenger number>' (for each flight's reservation,
 * if no optional args provided).
 * Errors:
 * - 'invalid reservation code', if the reservation code is not valid.
 * - '<flight code>: flight does not exist', if there is no flight with the given code.
 * - '<reservation code>: flight reservation already used', if there is already a flight with the given code.
 * - 'too many reservations', if the reservation exceeds the capacity of the flight.
 * - 'invalid date', if the date is in the past or more than 1 year in the future.
 * - 'invalid passenger number' if the passenger number is not a positive integer.
 */
void execute_r() {
	char flight_code[FLIGHT_CODE_SIZE+1];
	Date date;
	Flight *flight;

	scanf("%s %d-%d-%d", flight_code, &date.d, &date.m, &date.y);

	if (!(flight = find_flight(flight_code, date))) {
		printf("%s: flight does not exist\n", flight_code);
	} else if (!validate_date(date)) {
		puts("invalid date");
	} else if (getchar() == '\n') {
		print_reservations(flight);
	} else {
		Reservation *new = read_reservation();

		if (!validate_reservation_code(new->code)) {
			puts("invalid reservation code");
		} else if (exists_reservation(new->code)) {
			printf("%s: flight reservation already used\n", new->code);
		} else if (new->seats > count_available_seats(flight)) {
			puts("too many reservations");
		} else if (new->seats <= 0) {
			puts("invalid passenger number");
		} else {
			add_reservation(flight, new);
			return;
		}

		free(new->code);
		free(new);
	}
}

/*
 * Executes command 'e' (deletes a reservation or a flight).
 * Input: 'e <code>'.
 * Errors:
 * - 'not found', if there is no reservation nor flight with the given code.
 */
void execute_e() {
	char code[INPUT_MAX];

	scanf("%s", code);

	if (delete_reservation(code)) return;

	/* Deleting flights is slow so it is better to check if the code is valid first. */
	if (validate_flight_code(code) && delete_flights(code)) return;

	puts("not found");
}

int main() {
	char cmd;

	while (TRUE) {
		switch (cmd = getchar()) {
			case 'a':
				execute_a();
				break;
			case 'l':
				execute_l();
				break;
			case 'v':
				execute_v();
				break;
			case 'p':
				execute_p();
				break;
			case 'c':
				execute_c();
				break;
			case 't':
				execute_t();
				break;
			case 'r':
				execute_r();
				break;
			case 'e':
				execute_e();
				break;
			case 'q':
				free_all();
				return EXIT_SUCCESS;
		}
	}

	free_all();
	return EXIT_FAILURE;
}
