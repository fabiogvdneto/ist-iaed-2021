#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack* build() {
	stack *s = (stack*) malloc(sizeof(stack));

	s->v = malloc(sizeof(int)*INITIAL_CAPACITY);
	s->cap = INITIAL_CAPACITY;
	s->sz = 0;

	return s;
}

void push(stack *s, int e) {
	if (s->cap == s->sz) {
		s->v = realloc(s->v, sizeof(int)*(s->cap += 4));
	}

	s->v[(s->sz)++] = e;
}

int top(stack *s) {
	return s->v[s->sz-1];
}

int pop(stack *s) {
	return s->v[--s->sz];
} 

int is_empty(stack *s) {
	return !(s->sz);
}

void destroy(stack *s) {
	free(s->v);
	free(s);
}
