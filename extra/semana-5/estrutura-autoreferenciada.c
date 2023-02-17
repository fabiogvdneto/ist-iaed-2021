/*
 * Estrutura em que um campo da estrutura é um apontador para outra estrutura do mesmo tipo
 * Permitem criar estruturas como listas (linkedlist, doubly linkedlists), árvores...
 */

typedef struct {

	ponto *header;
	double x, y;

} point;

/* Constituíção de uma estrutura simplesmente ligada (linkedlist): */

typedef struct {

	ponto point;
	node *next;

} node;

/*
 * Vantagens:
 * - Tamanho ilimitado.
 * - Alocação de memória apenas para os elementos que queremos.
 * - Fácil e rápida inserção e remoção.
 * Desvantagens:
 * - Mais dificil acesso ao n-ésimo elemento.
 */

/* Constituíção de uma estrutura duplamente ligada (doubly linkedlist): */

typedef struct {

	ponto point;
	node *prev;
	node *next;

} node;

/*
 * Vantagens e desvantagens da linkedlist.
 * Vantagens extra:
 * - Podemos percorrer a lista no sentido inverto.
 */
