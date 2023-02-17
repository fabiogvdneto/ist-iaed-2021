#include <stdio.h>

int main()
{
	int h1, m1, h2, m2;

	scanf("%d:%d%d:%d", &h1, &m1, &h2, &m2);

	m1 += m2;
	h1 += h2 + (m1 / 60);
	m1 %= 60;

	printf("%02d:%02d", h1, m1);

	return 0;
}
