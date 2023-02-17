#include <stdio.h>

int main()
{
	int n;
	int contagem = 2;

	scanf("%d", &n);

	if (n < 0) return 0;

	int divisor = n/2;

	for (divisor; divisor > 1; --divisor)
	{
		if (n % divisor == 0) contagem++;
	}

	printf("%d", contagem);

	return 0;
}
