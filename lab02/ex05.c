#include <stdio.h>

int main()
{
    int n, current = 1;
    printf("Insira um número inteiro: ");
    scanf("%d", &n);

    while (current <= n)
        printf("%d\n", current++);
}