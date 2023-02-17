#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int d, m, y;
} Date;

int main() {
	Date *dates;
	int i;
	int amount;

	scanf("%d", &amount);
	
	dates = (Date*) malloc(sizeof(Date)*amount);

	for (i = 0; i < amount; i++) {
		scanf("%d-%d-%d", &dates[i].d, &dates[i].m, &dates[i].y);
	}

	while (i-- > 0) {
		printf("%02d-%02d-%04d\n", dates[i].d, dates[i].m, dates[i].y);
	}

	return 0;
}
