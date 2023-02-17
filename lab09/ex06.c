#include <stdio.h>

#define MAX 1000

int main() {
	char s[MAX+1];
	int i;

	scanf("%s", s);

	for (i = 0; *(s+i) != '\0'; i++)
		printf("%s\n", s+i);

	return 0; 
}
