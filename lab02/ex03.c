#include <stdio.h>

int main()
{
    int n, m;

    printf("N: ");
    scanf("%d", &n);

    printf("M: ");
    scanf("%d", &m);

    /* Imprime "yes" se M for divisor de N, caso contrário imprime "no". */
    if (n % m == 0)
        printf("yes");
    else
        printf("no");
}