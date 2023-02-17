#include <stdio.h>

int main()
{
	int n, contagem = 1;
	float min, max;

	printf("Qual o número de reais que pretende inserir? ");
	scanf("%d", &n);

	if (n < 1) return 0;

	printf("Número 1: ");
	scanf("%f", &min);
	max = min;

	while (n > contagem)
	{
		float atual;

		printf("Número %d: ", ++contagem);
		scanf("%f", &atual);

		if (atual > max) max = atual;
		else if (atual < min) min = atual;
	}

	printf("min: %f, max: %f\n", min, max);

	return 0;
}
