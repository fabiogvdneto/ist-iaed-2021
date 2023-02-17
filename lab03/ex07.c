#include <stdio.h>

/*
Exercício 7
-----------
(Calculadora) Escreva um programa que receba uma sequência de números e operadores (+, -)
representando uma expressão aritmética e retorna o resultado dessa expressão aritmética.

A sequência no input termina com \n.

Pode supor que cada dois números são sempre separados por espaço, operador, espaço, ie,
' op ', para qualquer um dos 2 operadores acima.

Exemplo: No input 70 + 22 - 3 deverá retornar 89.

Dica: Deverá começar por converter uma sequência de algarismos (carácteres) para um número inteiro.
*/

int apply(int num1, char op, int num2)
{
	if (op == '+') return num1 + num2;
	if (op == '-') return num1 - num2;

	return num1;
}

int main()
{
	int res = 0;
	int num = 0;
	char op = '+'; /* Add the first num to the result. */
	char c;

	while ((c = getchar()) != '\n')
	{
		if (c == ' ')
		{
			res = apply(res, op, num);	
			num = 0;
			op = getchar(); /* operador */

			getchar(); /* espaço */
		}
		else num = (num * 10) + c - 48;
	}

	res = apply(res, op, num);

	printf("%d\n", res);
	return 0;
}
