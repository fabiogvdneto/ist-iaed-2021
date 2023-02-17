#include <stdio.h>

/*
Exercício 5
-----------
(Mensagens) Escreva um programa que leia uma sequência de mensagens e imprima-as,
uma por linha. Cada mensagem é delimitada pelas aspas (carácter "). A mensagem
pode conter uma "escape sequence" - o carácter perde significado especial se for
precedido pelo caracter \ (backslash). Por exemplo, o input "a\"foo\\bar\""
corresponde à mensagem a"foo\bar". Assim o backslash permite incluir aspas na
mensagem tal como a própria backslash.
*/
int main()
{
	int dentro = 0;
	int escape = 0;
	char c;

	while ((c = getchar()) != EOF)
	{
		if (dentro)
		{
			if (escape)
			{
				putchar(c);
				escape = 0;
			}

			else if (c == '\\') escape = 1;

			else if (c == '"')
			{
				dentro = 0;
				putchar('\n');
			}

			else putchar(c);
		}

		else if (c == '"') dentro = 1;
	}

	return 0;
}
