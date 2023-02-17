/*
Exercício 2
-----------
(Gráfico vertical suspenso) Escreva um programa que peça ao utilizador um número inteiro positivo
n < VECMAX, onde VECMAX=100. Depois, leia n números inteiros positivos. No final o programa deverá
escrever uma representação gráfica dos valores lidos como o que se segue. O gráfico apresentado é o
exemplo para n = 3 e valores 1 3 4.
```
***
 **
 **
  *
```
*/

#include <stdio.h>

#define VECMAX 100

int main()
{
	int n, i;
	int maior = 0;
	int valores[VECMAX];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &valores[i]);

		if (valores[i] > maior) maior = valores[i];
	}

	while (maior-- > 0)
	{
		for (i = 0; i < n; i++)
		{
			if (valores[i]-- > 0) putchar('*');

			else putchar(' ');
		}

		putchar('\n');
	}

	return 0;
}
