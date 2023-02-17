#include <stdio.h>

/*
Exercício 4

(Números) Escreva um programa que leia uma sequência de números separados por
espaços e novas linhas, e imprima a mesma sequência, mas os números no output
não deverão conter 0 no início, por exemplo, 007 deverá imprimir 7.

A excepção é o número 0, que se deverá imprimir como 0.
A sequência no input termina com EOF.

Atenção: Os valores dos números poderão ser superiores ao valor máximo do tipo int
ou qualquer tipo primitivo em C.
*/

int main()
{
	char c;
	int num = 0; /* -1: space, 0: zero, 1: num greather than 0 */

	while ((c = getchar()) != EOF)
	{
		if ((c == ' ') || (c == '\n'))
		{
			if (num == 0) putchar('0');
			
			putchar(c);
			num = -1;
		}
		else
		{
			if (num == -1) num = 0;

			if (num == 0 && c == '0') continue;

			putchar(c);
			num = 1;
		}
	}

	if (num == 0) putchar('0');

	return 0;
}
