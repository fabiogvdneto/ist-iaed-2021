#include "main.h"

int main() {
	while(TRUE) {
		char cmd;

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
			case 'q':
				return EXIT_SUCCESS;
		}
	}

	return EXIT_FAILURE;
}

void execute_a() {
	int pos;
	airport new;

	scanf("%s %s %[^\n]", new.id, new.country, new.city);

	if (!validate_airport_id(new.id)) {
		puts("invalid airport ID");
	} else if (airports_count == AIRPORTS_MAX) {
		puts("too many airports");
	} else if (exists_airport(new.id)) {
		puts("duplicate airport");
	} else {
		/*
		 * Finds the first position whose airport's id is greater than the new one.
		 * Shifts the airports from that position to the right.
		 * Sets the new airport to that position.
		 */
		for (pos = 0; pos < airports_count; pos++) {
			int cmp = strcmp(new.id, airports[pos].id);

			if (cmp > 0) continue;

			if (cmp < 0) {
				int shifter;

				for (shifter = airports_count; shifter > pos; shifter--) {
					airports[shifter] = airports[shifter - 1];
				}

				break;
			}

			puts("duplicate_airport");
			return;
		}

		airports_count++;
		airports[pos] = new;

		printf("airport %s\n", new.id);
	}
}

void execute_l() {
	if (getchar() == '\n') {
		int i = 0;

		while (i < airports_count) print_airport(airports[i++]);

		return;
	}

	do {
		int i;
		airport_id id;

		scanf("%s", id);

		for (i = 0; i < airports_count; i++) {
			if (strcmp(airports[i].id, id)) continue;

			print_airport(airports[i]);
			break;
		}

		if (i == airports_count) printf("%s: no such airport ID\n", id);
	} while (getchar() != '\n');
}

void execute_v() {
	if (getchar() == '\n') {
		int i = 0;
		while (i < flights_count) print_flight(flights[i++]);
	} else {
		flight new;

		scanf("%s %s %s %d-%d-%d %d:%d %d:%d %d",
				new.code, new.departure, new.arrival,
				&new.date.d, &new.date.m, &new.date.y, &new.time.h, &new.time.m,
				&new.duration.h, &new.duration.m, &new.capacity);

		if (!validate_flight_code(new.code))
			puts("invalid flight code");
		else if (exists_flight(new.code, new.date))
			puts("flight already exists");
		else if (!exists_airport(new.departure))
			printf("%s: no such airport ID\n", new.departure);
		else if (!exists_airport(new.arrival))
			printf("%s: no such airport ID\n", new.arrival);
		else if (flights_count == FLIGHTS_MAX)
			puts("too many flights");
		else if (!validate_date(new.date))
			puts("invalid date");
		else if (!validate_flight_duration(new.duration))
			puts("invalid duration");
		else if (!validate_flight_capacity(new.capacity))
			puts("invalid capacity");
		else
			flights[flights_count++] = new;
	}
}

void execute_p() {
	airport_id id;

	scanf("%s", id);

	if (exists_airport(id)) {
		int i, count = 0;
		int departure_mins[FLIGHTS_MAX];
		flight departures[FLIGHTS_MAX];

		/*
		 * For each flight, adds it to the departures vector
		 * and its departure minutes to the departure_mins vector,
		 * while sorting it.
		 */
		for (i = 0; i < flights_count; i++) {
			int pos, mins;
			flight flight = flights[i];

			if (strcmp(flight.departure, id)) continue;

			mins = date_diff(sysdate, flight.date) + time_to_mins(flight.time);

			for (pos = 0; pos < count; pos++) {
				int shifter;

				if (mins >= departure_mins[pos]) continue;

				for (shifter = count; shifter > pos; shifter--) {
					departures[shifter] = departures[shifter - 1];
					departure_mins[shifter] = departure_mins[shifter - 1];
				}

				break;
			}

			count++;
			departures[pos] = flight;
			departure_mins[pos] = mins;
		}

		for (i = 0; i < count; i++) {
			flight f = departures[i];

			printf("%s %s %02d-%02d-%04d %02d:%02d\n",
					f.code, f.arrival, f.date.d, f.date.m, f.date.y, f.time.h, f.time.m);
		}

		return;
	}

	printf("%s: no such airport ID\n", id);
}

void execute_c() {
	airport_id id;

	scanf("%s", id);

	if (exists_airport(id)) {
		int i, count = 0;
		int arrival_mins[FLIGHTS_MAX];
		flight arrivals[FLIGHTS_MAX];

		/*
		 * For each flight, add it to the arrivals vector and
		 * its arrival minutes to the arrival_mins vector,
		 * while sorting it.
		 */
		for (i = 0; i < flights_count; i++) {
			int pos, mins;
			flight flight = flights[i];

			if (strcmp(flight.arrival, id)) continue;

			mins = date_to_mins(flight.date)
				 + time_to_mins(flight.time)
				 + time_to_mins(flight.duration);

			for (pos = 0; pos < count; pos++) {
				int shifter;

				if (mins >= arrival_mins[pos]) continue;

				for (shifter = count; shifter > pos; shifter--) {
					arrivals[shifter] = arrivals[shifter - 1];
					arrival_mins[shifter] = arrival_mins[shifter - 1];
				}

				break;
			}

			count++;
			arrivals[pos] = flight;
			arrival_mins[pos] = mins;
		}

		for (i = 0; i < count; i++) {
			flight f;
			date date;
			time time;

			f = arrivals[i];
			date = mins_to_date(arrival_mins[i]);
			time = mins_to_time(arrival_mins[i]);

			printf("%s %s %02d-%02d-%04d %02d:%02d\n",
					f.code, f.departure, date.d, date.m, date.y, time.h, time.m);
		}

		return;
	}

	printf("%s: no such airport ID\n", id);
}

void execute_t() {
	date new;

	scanf("%d-%d-%d", &new.d, &new.m, &new.y);

	if (!validate_date(new)) {
		puts("invalid date");
	} else {
		sysdate = new;
		printf("%02d-%02d-%04d\n", sysdate.d, sysdate.m, sysdate.y);
	}
}

bool exists_airport(airport_id id) {
	int i = 0;

	while (i < airports_count) if (!strcmp(airports[i++].id, id)) return TRUE;

	return FALSE;
}

bool exists_flight(flight_code code, date date) {
	int i = 0;

	while (i < flights_count) {
		flight f = flights[i++];

		if (!strcmp(f.code, code) && !date_diff(f.date, date)) return TRUE;
	}

	return FALSE;
}

bool validate_airport_id(airport_id id) {
	int i = 0;

	while (id[i] != '\0') if (!isupper(id[i++])) return FALSE;

	return TRUE;
}

bool validate_flight_code(flight_code code) {
	if (isupper(code[0]) && isupper(code[1]) && (code[2] != '0')) {
		int i = 2;

		do {
			if (!isdigit(code[i++])) return FALSE;
		} while(code[i] != '\0');

		return TRUE;
	}

	return FALSE;
}

bool validate_flight_duration(time time) {
	return time_to_mins(time) <= DURATION_MAX;
}

bool validate_flight_capacity(int cap) {
	return (cap >= CAPACITY_MIN) && (cap <= CAPACITY_MAX);
}

bool validate_date(date date) {
	int mins = date_diff(sysdate, date);

	return (mins >= 0) && (mins <= MINUTES_PER_YEAR);
}

int date_diff(date bef, date aft) {
	return date_to_mins(aft) - date_to_mins(bef);
}

int date_to_mins(date date) {
	date.d += date.y * DAYS_PER_YEAR;
	date.d += acc_month_days[date.m-2];

	return date.d * MINUTES_PER_DAY;
}

int time_to_mins(time time) {
	return time.m + (time.h * MINUTES_PER_HOUR);
}

date mins_to_date(int mins) {
	date date = { 0 };

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

time mins_to_time(int mins) {
	time time;

	time.m = mins % MINUTES_PER_HOUR;
	time.h = mins / MINUTES_PER_HOUR % HOURS_PER_DAY;

	return time;
}

void print_airport(airport a) {
	int i = 0;
	int departures = 0;

	while (i < flights_count) if (!strcmp(flights[i++].departure, a.id)) departures++;

	printf("%s %s %s %d\n", a.id, a.city, a.country, departures);
}

void print_flight(flight f) {
	printf("%s %s %s %02d-%02d-%04d %02d:%02d\n",
			f.code, f.departure, f.arrival, f.date.d, f.date.m, f.date.y, f.time.h, f.time.m);
}
