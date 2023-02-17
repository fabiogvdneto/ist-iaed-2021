#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);
 
	int contagem = 0, soma = 0;

	for (int x; n > 0; n /= 10)
	{
		contagem++;
		soma += (x = n % 10);
	}

	printf("%d\n", contagem);
	printf("%d\n", soma);

	return 0;
}
