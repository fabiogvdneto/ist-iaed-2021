#include <stdio.h>

int main()
{
	int maior, a, b, c;

	printf("Insira 3 números separados por vírgulas: ");
	scanf("%d,%d,%d", &a, &b, &c);

	maior = (a > b) ? a : b;
	maior = (maior > c) ? maior : c;

	printf("%d", maior);

	return 0;
}