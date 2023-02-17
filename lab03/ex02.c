#include <stdio.h>

/*
Exercício 2
-----------
(Pirâmide de Números) Escreva um programa que desenhe uma pirâmide de números
utilizando a função void piramide(int N);. O valor de N, dado pelo utilizador,
deverá ser obrigatoriamente superior ou igual 2. O espaço (carácter ' ') deve ser
usado como o separador.
*/

void piramide(int n);

int main()
{
	int input;

	scanf("%d", &input);

	piramide(input);

	return 0;
}

void piramide(int n)
{
	int i, x = 0; /* x represents rows */

	if (n < 2) return;

	while (x++ < n)
	{
		/* imprime (n - x) espaços. */
		for (i = 0; i < (n - x); i++)
			putchar(' ');

		/* imprime os números de 1 até (x - 1) */
		for (i = 1; i < x; i++)
			printf("%d", i);

		/* imprime os números de x até 1 */
		for (i = x; i > 0; i--)
			printf("%d", i);

		if (x != n) putchar('\n');
	}
}
