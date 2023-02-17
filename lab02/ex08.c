#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);

	float soma;

	for (int x = 0; x < n; x++)
	{
		float valor;
		scanf("%f", &valor);

		soma += valor;
	}

	float media = soma / n;

	printf("%.2f\n", media);

	return 0;
}
