/*
Exercício 7
-----------
(Manipulação de Strings: Apaga Carácter) Escreva um programa que leia uma linha e um carácter e
escreve no terminal a mesma linha onde todas as ocorrências do carácter foram removidas. Implemente
a função void apagaCaracter(char s[], char c) que apague o carácter c da string s.
*/

#include <stdio.h>

#define MAX 80

void apagaCaracter(char s[], char c);

int main()
{
	int i;
	char linha[MAX];
	char c;

	for (i = 0; i < MAX; i++)
	{
		linha[i] = getchar();

		if (linha[i] == '\n')
		{
			linha[i] = '\0';
			break;
		}
	}

	scanf("%c", &c);	

	apagaCaracter(linha, c);

	printf("%s\n", linha);

	return 0;
}

void apagaCaracter(char s[], char c)
{
	int i = 0, j = 0;
	char x;
	
	while ((x = s[i++]) != '\0')
		if (x != c)
			s[j++] = x;

	s[j] = '\0';
}
