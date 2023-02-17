#include <stdio.h>

int maior_valor(int vetor[], int tam)
{
	int i = 0, res = vetor[0];

	while (++i < tam)
		if (vetor[i] > res)
			res = vetor[i];

	return res;
}

void substitui_minusculas(char s[])
{
	int i = -1;

	while (s[++i] != '\0')
		if ((s[i] >= 'a') && (s[i] <= 'z'))
			s[i] -= 'a' + 'A';
}
