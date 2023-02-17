#include <stdio.h>

/*
Exercício 1
-----------
(Quadrado de Números) Escreva um programa que desenhe um quadrado de números como
o que se segue utilizando a função void quadrado(int N);. O valor de N, dado pelo
utilizador, deverá ser obrigatoriamente maior ou igual 2. O tab (carácter '\t')
deve ser usado como o separador.
*/

void quadrado(int n);

int main()
{
	int input;

	scanf("%d", &input);

	quadrado(input);

	return 0;
}

void quadrado(int n)
{
	int y, x = 0; /* x represents rows, y represents columns */

	if (n < 2) return;

	while (x++ < n) /* for each row */
	{
		printf("%d", x);

		y = 1;
		while (y++ < n) /* for each column */
		{
			printf("\t%d", x + y - 1);
		}

		printf("\n");
	}
}