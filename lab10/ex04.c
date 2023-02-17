#include <stdio.h>
#include "stack.h"

int main() {
	stack *s = build();
	char c;

	while ((c = getchar()) != '\n') {
		switch (c) {
			case '{':
			case '[':
			case '(':
				push(s, c);
				break;
			case '}':
				if (pop(s) == '{') break;

				printf("no");
				return 0;
			case ']':
				if (pop(s) == '[') break;

				printf("no");
				return 0;
			case ')':
				if (pop(s) == '(') break;

				printf("no");
				return 0;
		}
	}

	destroy(s);
	printf("yes");
	return 0;
}
