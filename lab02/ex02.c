#include <stdio.h>

int main()
{
    int a, b;

    printf("Insira 2 números separados por vírgulas: ");
    scanf("%d,%d", &a, &b);

    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("%d\n%d", a, b);

    return 0;
}