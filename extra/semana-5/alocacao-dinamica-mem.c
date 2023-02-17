/*
 * Alocação estática de memória: é alocada para nós e libertada quando o scope da variável termina.
 * Alocação dinâmica de memória: é alocada e libertada por nós.
 */

#include <stdio.h>
#include <stdlib.h> /* Necessário para as funções responsáveis pela alocação dinâmica de memória (free, malloc, realloc...). */

int main() {
	int *vec;
	int numInts;

	scanf("%d", &numInts);

	vec = (int*) malloc(sizeof(int)*numInts); /* Aloca memória para 'numInts' inteiros (devolve um ponteiro). */

	free(vec); /* Liberta a memória alocada (recebe um ponteiro). */

	/* Caso semelhante de alocação estática: int vec[100]; */

	scanf("%d", &numInts);

	vec = (int*) realloc(vec, sizeof(int)*numInts);

	/* Atenção: se faltar memória para o malloc/realloc, é retornado NULL. */

	vec = (int*) calloc(100, sizeof(int)); /* Semelhante ao malloc, mas inicializa todos os elementos do vetor a 0. */

	return 0;
}

/* Dica: o valgrind consegue detetar memória alocada que não foi libertada. */
