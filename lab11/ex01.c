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

int main() {
	int num;
	node *head = NULL;

	scanf("%d", &num);

	while (num) {
		head = push(head, num);
		scanf("%d", &num);
	}

	print(head);
	head = destroy(head);

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
