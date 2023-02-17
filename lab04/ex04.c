/*
Exercício 4
-----------
(Manipulação de Strings: Palíndromo) Escreva um programa que leia uma palavra do terminal e verifica
se a palavra é um palíndromo ou não. Uma palavra é um palíndromo se se escrever da mesma maneira
da esquerda para a direita e vice-versa (por exemplo, "AMA" é um palíndromo). Se a palavra é um
palíndromo, o programa deverá imprimir o valor yes, e no, se não é.

Dica: Podem usar scanf("%s", s) para ler uma palavra. Reparem que a string s não pede & no scanf.
*/

#include <stdio.h>
#include <string.h>

#define MAX 80

int main()
{
	char s[MAX];
	int i, j, len = 0;

	scanf("%s", s);

	while (s[len++] != '\0');

	i = 0;
	j = len - 2;

	while (j >= i)
	{
		if (s[i++] != s[j--])
		{
			printf("no");
			return 0;
		}
	}

	printf("yes");
	return 0;
}
