#include <stdio.h>

#define DIM 10

int main()
{
	char str[DIM];

	scanf("%s", str);

	char copia[DIM];

	for (int i = 0; i < DIM; i++)
	{
		copia[i] = str[i];
	}

	printf("%s", copia);

	/*
	MANIPULAÇÃO DE STRINGS
	strcmp (Compara strings: retorna 0 se forem iguais)
	strcpy (Copia string para um vetor pre existente)
	strdup (Duplica strings criando um novo vetor)
	strlen (Tamanho da string)
	*/

	return 0;
}
