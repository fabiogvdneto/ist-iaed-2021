#include <stdio.h>
#include <stdlib.h>

const int acc_month_days[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

typedef struct {
	int d, m, y;
} Date;

int date_to_days(Date date) {
	return date.d + acc_month_days[date.m-2] + (date.y * 365);
}

int isnewer(Date date1, Date date2) {
	return date_to_days(date1) > date_to_days(date2);
}

void sort_dates(Date **dates, int size) {
	int i, j;

	for ((i = 0, j = 0); (i < size); (i++, size--, j = 0)) {
		while (++j < size) {
			if (isnewer(*dates[j-1], *dates[j])) {
				Date *temp = dates[j-1];
				dates[j-1] = dates[j];
				dates[j] = temp;
			}
		}
	}
}

int main() {
	Date **dates;
	int i;
	int amount;

	scanf("%d", &amount);
	
	dates = (Date**) malloc(sizeof(Date*)*amount);

	for (i = 0; i < amount; i++) {
		Date *date = malloc(sizeof(Date));

		scanf("%d-%d-%d", &date->d, &date->m, &date->y);

		dates[i] = date;
	}

	sort_dates(dates, amount);

	for (i = 0; i < amount; i++) {
		printf("%02d-%02d-%04d\n", dates[i]->d, dates[i]->m, dates[i]->y);
		free(dates[i]);
	}

	free(dates);

	return 0;
}
