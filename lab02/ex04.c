#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Insira três inteiros separados por vírgula: ");
    scanf("%d,%d,%d", &a, &b, &c);

    if (a > c)
    {
        int temp = a;
        a = c;
        c = temp;
    }

    if (b > c)
    {
        int temp = b;
        b = c;
        c = temp;
    }

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("%d %d %d", a, b, c);
}