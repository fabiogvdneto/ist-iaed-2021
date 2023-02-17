#include <stdio.h>

#define STOCK_NAME_SIZE 10

typedef struct
{
	char name[STOCK_NAME_SIZE + 1];
	
	float value;
	float income;
}
Stock;

int main()
{
	Stock best;
	int n;

	scanf("%d", &n);
	
	while (n-- > 0)
	{
		Stock stock;

		scanf("%s%f%f", stock.name, &stock.value, &stock.income);

		if (stock.income > best.income) best = stock;
	}

	printf("%s %.2f %.2f", best.name, best.value, best.income);

	return 0;
}
