#include <stdio.h>

int potencia(int base, int n);

int main()
{
	int base, n;

	printf("Insira a base: ");
	scanf("%d", &base);

	printf("Insira o expoente: ");
	scanf("%d", &n);

	printf("Resultado: %d", potencia(base, n));

	return 0;
}

int potencia(int base, int n)
{
	int result = 1;
	int x;

	if (n < 0) return -1;

	for (x = 0; x < n; x++)
		result *= base;

	return result;
}
