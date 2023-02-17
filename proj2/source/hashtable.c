/*
 * File: 'hastable.c'.
 * Author: Fábio Neto (ist1104126).
 * Description: An hashtable implementation which alllows more than a single key.
 */

#include "hashtable.h"
#include "stdlib.h"
#include "string.h"

#define TABLE_SIZE 18947

static Link table[TABLE_SIZE] = { NULL };

/*
 * Hashing function.
 */
int hash(char *key) {
	/* Murmur OAAT */

	unsigned int h = 0x12345678;

	while (*key != '\0') {
        h ^= *key++;
        h *= 0x5bd1e995;
        h ^= h >> 15;
    }
	
    return h % TABLE_SIZE;

/* Alternative: DJB2

	unsigned long h = 5381;

    while (*key != '\0')
        h = ((h << 5) + h) + *key++;

    return h % TABLE_SIZE;

*/
}

/*
 * Creates a link with the given key and value and returns it.
 */
Link create_link(char *key, Reservation *val) {
	Link link = (Link) malloc(sizeof(struct node));

	if (!link) exit_no_memory();

	link->key = key;
	link->val = val;

	return link;
}

/*
 * Adds the given key and value to the table.
 */
void table_add(char *key, Reservation *val) {
	int pos = hash(key);
	Link new = create_link(key, val);

	new->next = table[pos];
	table[pos] = new;
}

/*
 * Returns the reservation in the table whose key matches with the given string, or NULL if not found.
 */
Reservation* table_lookup(char *key) {
	Link curr;

	for (curr = table[hash(key)]; curr; curr = curr->next)
		if (!strcmp(curr->key, key))
			return curr->val;

	return NULL;
}

/*
 * Deletes an element from the table whose key matches with the given string,
 * returning it, or NULL if nothing was deleted.
 */
Reservation* table_delete(char *key) {
	int h = hash(key);
	Link prev = NULL;
	Link curr = table[h];

	while (curr) {
		if (!strcmp(curr->key, key)) {
			Reservation *val = curr->val;

			if (prev) {
				prev->next = curr->next;
			} else {
				table[h] = curr->next;
			}

			free(curr);
			return val;
		}

		curr = (prev = curr)->next;
	}

	return NULL;
}

/*
 * Clears the table.
 */
void table_clear() {
	int i;
	Link next;
	for (i = 0; i < TABLE_SIZE; i++) {
		while (table[i]) {
			next = table[i]->next;
			free(table[i]);
			table[i] = next;
		}
	}
}