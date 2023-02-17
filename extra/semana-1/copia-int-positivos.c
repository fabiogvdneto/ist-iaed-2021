#include <stdio.h>

int main()
{
	int v = 0;

	while(v >= 0)
	{
		printf("Insira um número positivo para ser copiado: ");
		scanf("%d", &v);
		printf("%d\n", v);
	}

	return 0;
}
