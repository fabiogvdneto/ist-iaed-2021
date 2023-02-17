#include <stdio.h>

/*
Exercício 3
-----------
(Cruz diagonal) Escreva um programa que desenhe uma cruz nas diagonais utilizando
a função void cruz(int N);. O asterisco (carácter '*') deve ser usado para desenhar
a cruz; hífen (carácter '-') deve ser usado como o separador.
*/

void cruz(int n);

int main()
{
	int input;

	scanf("%d", &input);

	cruz(input);

	return 0;
}
void cruz(int n)
{
	int x = 0, y; /* x represents rows, y represents columns */
	
	while (x++ < n) /* x = 1 a n */
	{
		y = 0;

		while (y++ < n) /* y = 1 a n */
		{
			if ((y == x) || (y == (n + 1 -x))) putchar('*');
			else putchar('-');
		}

		if (x != n) printf("\n");
	}
}
