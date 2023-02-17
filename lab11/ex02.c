#include <stdio.h>
#include <stdlib.h>

typedef struct stru_node {
	struct stru_node *next;
	int v;
} node;

/* remove the first element of the list and return the new head */
node* pop(node * head);
/* add integer e as the first element of the list and return the new head */
node* push(node * head, int e);
/* frees all memory associated with the list and returns NULL */
node* destroy(node * head);
/* print the elements of the integers in the list, one per line */
void print(node * head);
/* compara duas listas */
int is_eq(node *h1, node *h2);   
/* devolve uma nova lista que corresponda a lista dada invertida */
node* rev(node *head);

int main() {
	char c;
	node *head = NULL;
	node *daeh = NULL;

	while ((c = getchar()) != '\n') head = push(head, c);
	
	daeh = rev(head);

	puts(is_eq(head, daeh) ? "yes" : "no");

	head = destroy(head);
	daeh = destroy(daeh);

	return 0;
}

node* pop(node *head) {
	node *new = head->next;
	free(head);
	return new;
}

node* push(node *head, int e) {
	node *new = malloc(sizeof(node));
	new->next = head;
	new->v = e;
	return new;
}

node* destroy(node *head) {
	while (head) head = pop(head);

	return head;
}

void print(node *head) {
	while (head) {
		printf("%d\n", head->v);
		head = head->next;
	}
}

int is_eq(node *h1, node *h2) {
	while (1) {
		if (!h1 && !h2) return 1;
		if (!h1 || !h2) return 0;

		if (h1->v != h2->v) return 0;

		h1 = h1->next;
		h2 = h2->next;
	}
}

node* rev(node *head) {
	node *newhead = NULL;

	while (head != NULL) {
		newhead = push(newhead, head->v);
		head = head->next;
	}

	return newhead;
}
