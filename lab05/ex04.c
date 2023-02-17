#include <stdio.h>

#define MAXDIM 100

int ganha(int dim, char tab[MAXDIM][MAXDIM], char jogador);

int main()
{
	char tab[MAXDIM][MAXDIM];
	int d; /* Dimensao do tabuleiro. */
	int n; /* Numero de entradas preenchidas. */

	scanf("%d", &d);
	scanf("%d", &n);

	while (n-- > 0)
	{
		int h, v; /* Posicao horizontal e vertical (0 a d-1). */

		scanf("%d%d ", &h, &v);
		scanf("%c", &tab[h][v]);
	}

	if (ganha(d, tab, 'x'))      putchar('x');
	else if (ganha(d, tab, 'o')) putchar('o');
	else						 putchar('?');

	return 0;
}

int ganha(int dim, char tab[MAXDIM][MAXDIM], char jog)
{
	int x, y;

	for (x = 0; x < dim; x++)
	{
		/* check for combination at column x */
		for (y = 0; y < dim; y++)
		{
			if (tab[x][y] != jog)
				break;
		}

		if (y == dim) return 1;

		/* check for combination at line x */
		for (y = 0; y < dim; y++)
		{
			if (tab[y][x] != jog)
				break;
		}

		if (y == dim) return 1;
	}
	
	for (x = 0; x < dim; x++)
	{
		if (tab[x][x] != jog)
			break;
	}

	if (x == dim) return 1;

	for (x = 0; x < dim; x++)
	{
		if (tab[x][dim - x - 1] != jog)
			break;
	}

	return (x == dim);
}
