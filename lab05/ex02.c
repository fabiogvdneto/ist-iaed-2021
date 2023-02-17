#include <stdio.h>

struct complexo
{
	float a, b;
};

int main()
{
	struct complexo res;
	struct complexo addend;

	scanf("%f+%fi\n%f+%fi", &res.a, &res.b, &addend.a, &addend.b);

	res.a += addend.a;
	res.b += addend.b;

	printf("%.2f+%.2fi", res.a, res.b);

	return 0;
}
