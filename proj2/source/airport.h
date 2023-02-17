/*
 * File: 'airport.h'
 * Author: Fábio Neto (ist1104126)
 * Description: Interface of an airport system.
 */

#ifndef _AIRPORT_H_
#define _AIRPORT_H_

/* INCLUSIONS */

#include "date.h"
#include "bool.h"

/* MACROS */

#define AIRPORTS_MAX 40
#define FLIGHTS_MAX  30000

#define AIRPORT_ID_SIZE  3
#define FLIGHT_CODE_SIZE 6
/* flight_uuid = dd + mm + yyyy + flight_code */
#define FLIGHT_UUID_SIZE (2+2+4+FLIGHT_CODE_SIZE)
#define CITY_SIZE        50
#define COUNTRY_SIZE     30

#define CAPACITY_MIN 10
#define DURATION_MAX (12 * MINUTES_PER_HOUR)


/* STRUCTS */

typedef struct airport {
	char id[AIRPORT_ID_SIZE+1];
	char country[COUNTRY_SIZE+1];
	char city[CITY_SIZE+1];
} Airport;

struct flight;

typedef struct reservation {
	char *code;
	int seats;
	struct flight *flight;

	/* Each reservation is linked to others whose flight is the same */
	struct reservation *prev;
	struct reservation *next;
} Reservation;

typedef struct flight {
	char uuid[FLIGHT_UUID_SIZE+1]; /* UUID = Date + Code */
	char code[FLIGHT_CODE_SIZE+1];
	char departure[AIRPORT_ID_SIZE+1];
	char arrival[AIRPORT_ID_SIZE+1];
	Date date;
	Time time;
	Time duration;
	int instant; /* Instant (in minutes) = Date + Time */
	int arrival_instant; /* Arrival Instant (in minutes) = Date + Time + Duration */
	int capacity;
	int occupacity;
	struct reservation *reservations; /* List starts with a Dummy Head */
} Flight;

/* UTILS */

void print_flight_uuid(char*, char*, Date);

int count_available_seats(Flight*);

int count_departures(Airport*);

int count_airports();

int count_flights();

/* DATA MANIPULATION */

void update_date(Date);

void add_airport(Airport*);

void add_flight(Flight*);

void add_reservation(Flight*, Reservation*);

bool delete_reservation(char*);

bool delete_flights(char*);

Airport* find_airport(char*);

Flight* find_flight(char*, Date);

bool exists_reservation(char*);

/* VALIDATIONS */

bool validate_date(Date);

bool validate_airport_id(char*);

bool validate_flight_code(char*);

bool validate_flight_duration(Time);

bool validate_flight_capacity(int);

bool validate_reservation_code(char*);

/* IO */

void print_airport(Airport*);

void print_airports();

void print_flight(Flight*);

void print_flights();

void print_flights_departing(char*);

void print_flights_arriving(char*);

void print_reservations(Flight*);

/* MEMORY */

void free_all();

void exit_no_memory();

#endif
