/*
(Manipulação de Strings: Leitura e Escrita de Linhas de Texto) Escreva uma programa que leia caracteres do teclado, carácter a carácter, até encontrar o carácter \n ou EOF e escreve a linha lida no terminal. Implemente a função int leLinha(char s[]) que lê a linha para a string s e devolve o número de caracteres lidos.

Dica: Depois de resolver este exercício, experimente utilizar o comando fgets.
*/

#include <stdio.h>

#define MAX 80

int leLinha(char s[]);

int main()
{
	char s[MAX];

	leLinha(s);
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
