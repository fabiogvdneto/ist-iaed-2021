#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char *value;
	link next;
} *link;

int main() {

}

link new(char *text) {
	link new = (link) malloc(sizeof(struct node));

	new->value = text;

	return new;
}

link lookup(link head, char *text) {
	link e = head;
	
	do {
		if (!strcmp(e->value, text)) return e;
	} while ((e = e->next) != NULL);

	return NULL;
}
