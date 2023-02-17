int soma(int a, int b) { return a + b; }

int main() {
	int (*function)(int, int);

	function = soma;

	printf("%d\n", (*function)(3, 4));

	return 0;
}
