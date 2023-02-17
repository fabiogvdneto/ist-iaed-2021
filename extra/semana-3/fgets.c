#include <stdio.h>

int main()
{
	char name[20];

	printf("Enter your name: ");

	/* Gets an one-line string from the standard input */
	fgets(name, 20, stdin);

	printf("Your name is: %s", name);
}
