#include <stdio.h>

/*
Exercício 6
-----------
(Divisível) Escreva um programa que leia um número inteiro positivo a partir do input
(como uma sequência de caráteres até 100 chars) e que decide se o número lido é divisível
por 9.

Se o número for divisível por 9, o programa deverá imprimir a mensagem yes, e deverá
imprimir no no caso contrário.

Atenção: Os valores dos números podem ser superiores ao valor máximo do tipo int ou de
qualquer tipo primitivo em C.

Dica: Um número é divisível por 9 se e só se a soma dos seus algarismos for divisível por 9.
Por exemplo, a soma dos algarismos do número 729 é 18, pelo que é divisível por 9.
O facto pode ser observado pela equação seguinte:
7 x 100 + 2 x 10 + 9 = (7 x 99 + 7) + (2 x 9 + 2) + 9.
*/

int main()
{
	char num[100];
	int i, soma;

	for (i = 0; i < 100; i++)
	{
		num[i] = getchar();

		if (num[i] == EOF) break;
	}

	while (i-- > 0) soma += num[i] - 48;

	printf((soma % 9 == 0) ? "yes\n" : "no\n");

	return 0;
}
