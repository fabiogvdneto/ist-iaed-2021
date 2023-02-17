#include <stdio.h>

#define NOTAS_POSSIVEIS 21

int main()
{
	int ocorr[NOTAS_POSSIVEIS];

	for (int x = 0; x < NOTAS_POSSIVEIS; x++)
	{
		ocorr[x] = 0;
	}

	int total = 0, aprova = 0;

	while (1)
	{
		int nota;
		scanf("%d", &nota);

		if (nota < 0) break;
		if (nota >= 10) aprova++;

		ocorr[nota]++;
		total++;
	}

	printf("Total: %d\tAprova: %d\tReprova: %d\n", total, aprova, total-aprova);

	for (int i = 0; i<21; i++)
		printf("Nota: %02d\tOcorr: %d\n", i, ocorr[i]);

	return 0;
}
