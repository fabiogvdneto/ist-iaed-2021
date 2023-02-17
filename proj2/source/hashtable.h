/*
 * File: 'hashtable.h'.
 * Author: Fábio Neto (ist1104126).
 * Description: A hashtable interface.
 */

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "airport.h"

typedef struct node {
	char *key;
	Reservation *val;
    struct node *next;
} *Link;

void table_add(char*, Reservation*);

Reservation* table_lookup(char*);

Reservation* table_delete(char*);

void table_clear();

#endif