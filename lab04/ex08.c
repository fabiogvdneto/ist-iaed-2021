/*
Exercício 8
-----------
(Maior) Escreva um programa que leia dois números inteiros em representação
decimal e imprime o maior desses dois números. Podem assumir que os dois
números têm o mesmo número de algarismos e no máximo 100 carácteres.

Nota: Os números podem ser demasiado grandes para ser guardados numa
variável do tipo long long, por exemplo 9988888888888888888887 e 9988888888888888888888.
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
	int i;
	char num1[MAX];
	char num2[MAX];

	for (i = 0; (i < MAX) && ((num1[i] = getchar()) != ' '); i++);
	for (i = 0; (i < MAX) && ((num2[i] = getchar()) != '\n'); i++);

	num1[i] = '\0';
	num2[i] = '\0';

	puts((strcmp(num1, num2) > 0) ? num1 : num2);

	return 0;
}
