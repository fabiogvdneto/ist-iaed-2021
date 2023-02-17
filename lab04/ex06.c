/*
Exercício 6
-----------
(Manipulação de Strings: Maiúsculas) Escreva um programa que leia uma linha do terminal (use a função do exercício anterior) e que escreve no terminal o mesmo texto, mas com as letras minúsculas substituídas pelas respectivas letras maiúsculas. Implemente a função void maiusculas(char s[]).

Nota: Recorde que a string s é alterada pela função maiusculas.
*/

#include <stdio.h>

#define MAX 80

int leLinha();
void maiusculas(char s[]);

int main()
{
	char s[MAX];

	leLinha(s);
	maiusculas(s);
	puts(s);

	return 0;
}

int leLinha(char s[])
{
	int len = 0;

	for (s[len] = getchar(); len < MAX; s[++len] = getchar())
	{
		if ((s[len] == '\n') || (s[len] == EOF))
		{
			s[len] = '\0';
			break;
		}
	}

	return ++len;
}

void maiusculas(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z') s[i] += 'A' - 'a';
	}
}
