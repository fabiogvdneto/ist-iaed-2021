/*
 * OPERADORES
 * '&': Refere-se ao ponteiro da variável.
 * '*': Refere-se ao conteúdo da variável.
 */

int main() {
	int* x, a; /* Apenas a é um ponteiro! */
	float *y, *z; /* y e z são ponteiros para float. */
	int **xx; /* Ponteiro para um ponteiro para int. */

	a = 43; /* int. */

	x = &a; /* pa passa a guardar endereço de a. */

	a = *x;
	*x = 4; /* Conteúdo de x = 4 (== a = 4) */

	/*
	 * a[i]  = *(a+i)
	 * &a[i] = a+i
	 * a[i]  = x[i]
	 * x[i]  = *(x+i)
	 * a     = p[0]
	 */

	xx = &x;
}
