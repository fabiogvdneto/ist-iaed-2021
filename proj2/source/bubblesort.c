/*
 * File: 'bubblesort.c'.
 * Author: Fábio Neto.
 * Description: Bubblesort algorithm implementation.
 */

#include "sort.h"
#include "bool.h"

/*
 * Sort a vector using bubble sort algorithm.
 * Receives a vector of indexes, its size and a comparator function.
 */
void sort(int *indexes, int size, int (*cmp)(int, int)) {
	while (size-- > 0) {
		int i;
		bool done = TRUE;

		for (i = 0; i < size; i++) {
			if (cmp(indexes[i], indexes[i+1])) {
				int temp = indexes[i+1];
				indexes[i+1] = indexes[i];
				indexes[i] = temp;
				done = FALSE;
			}
		}

		if (done) break;
	}
}
