/* Import libraries */
#include <stdio.h>

/* Define constants */
#define CONSTANTE 0

int main()
{
	int inferior, superior, passo, fahr;
	double celsius;

	printf("Insira o limite inferior: ");
	scanf("%d", &inferior);
	printf("Insira o limite superior: ");
	scanf("%d", &superior);
	printf("Insira o passo: ");
	scanf("%d", &passo);

	fahr = inferior;

	/*
	while (fahr <= superior)
	{
		celsius = 5.0 / 9.0 * (fahr-32);
		printf("%d\t%0.1f\n", fahr, celsius);
		fahr += passo;
	}
	*/

	for (fahr = inferior; fahr <= superior; fahr += passo)
	{
		celsius = 5.0 / 9.0 * (fahr-32);
		printf("%d\t%0.1f\n", fahr, celsius);
	}

	/* Return error code, or 0 if successfull */
	return 0;
}
