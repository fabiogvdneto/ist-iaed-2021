/* Contagem de Aprovacoes e Reprovacoes. */

# include <stdio.h>

int main()
{
	int contador = 0, aprova = 0, nota;

	scanf("%d", &nota);

	while (nota >= 0)
	{
		contador++;
		if (nota >= 10) aprova++;
		scanf("%d", &nota);
	}

	printf("Notas submetidas: %d\n", contador);
	printf("Aprovações: %d\n", aprova);
	printf("Reprovações: %d\n", contador - aprova);

	return 0;
}
