#include <stdio.h>

typedef struct {

	int x, y;

} ponto;

int main() {
	ponto ponto  = { 5, 4 };
	ponto *ponteiro = &p;

	/* Equivalentes: */
	ponto.x = 5;
	(*ponteiro).x = 5;
	ponteiro->x = 5; /* Operador '->' */

	printf("%d %d", ponteiro->x, ponteiro->y);

	return 0;
}
