#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct stru_node {
	struct stru_node *next;
	char *v;
} node;

/* remove the first element of the list and return the new head */
node *pop(node *head);
/* add string e as the first element of the list and return the new head */
node *push(node *head, const char *e);
/* frees all memory associated with the list and returns NULL */
node *destroy(node *head);
/* print the elements of the integers in the list, one per line */
void print(node *head);

int main() {
	node *head = NULL;
	char string[MAX + 1];
	char *x = "x";

	while (1) {
		scanf("%s", string);

		if (!strcmp(string, x)) {
			print(head);
			head = destroy(head);
			return 0;
		}

		head = push(head, string);
	}
}

node *pop(node *head) {
	node *newhead = head->next;
	free(head->v);
	free(head);
	return newhead;
}

node *push(node *head, const char *e) {
	node *newhead = malloc(sizeof(node));

	newhead->next = head;
	newhead->v = malloc(sizeof(char)*strlen(e));

	strcpy(newhead->v, e);

	return newhead;
}

node *destroy(node *head) {
	while (head) {
		node *old = head;
		head = head->next;
		free(old->v);
		free(old);
	}

	return head;
}

void print(node *head) {
	while (head) {
		printf("%s\n", head->v);
		head = head->next;
	}
}
