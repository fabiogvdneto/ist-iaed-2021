#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORDS_MAX 10000
#define CHARS_MAX 1000

int main() {
	char *words[WORDS_MAX+1];
	int words_count = 0;

	while (getchar() != '\n' && words_count < WORDS_MAX) {
		char s[CHARS_MAX+1];

		scanf("%s", s);

		words[words_count] = malloc(sizeof(char)*strlen(s)+1);

		strcpy(words[words_count++], s);
	}

	while (words_count-- > 0) {
		printf("%s\n", words[words_count]);
		free(words[words_count]);
	}

	return 0;
}
