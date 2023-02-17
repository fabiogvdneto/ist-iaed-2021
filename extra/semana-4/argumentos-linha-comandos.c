/*
 * argv[0] é o nome do programa.
 * argv[i] é o i-ésimo argumento.
 */

int main(int argc, char *argv[]) {
	int i;

	for (i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}

	putchar('\n');

	return 0;
}
