#include <stdio.h>
#include <stdlib.h>

typedef struct str_node  {
	struct str_node *next, *previous;
	char c;
} node;

typedef struct  {
	struct str_node *head, *last;
} list;

list *mk_list();                 /* cria nova lista vazia */
void  free_list(list *l);        /* liberta toda a memoria associada a lista */
void  add_last(list *l, char c); /* adiciona o char c como o ultimo elemento da lista */
int   is_paly(const list *ls);   /* calcula se a dada lista e um palindromo */

int main() {
	list *l = mk_list();
	char c;

	while ((c = getchar) != '\n') add_last(l, c);

	puts(is_paly(l) ? "yes" : "no");
	free_list(l);

	return 0;
}

list *mk_list() {
	list *l = malloc(sizeof(list));
	l->head = NULL;
	l->last = NULL;
	return l;
}

void free_list(list *l) {
	node *head = l->head;

	while (head) {
		node *old = head;
		head = head->next;
		free(old);
	}

	free(l);
}

void add_last(list *l, char c) {
	node *newlast = malloc(sizeof(node));
	newlast->previous = l->last;
	newlast->next = NULL;
	newlast->c = c;
	l->last = newlast;
}
