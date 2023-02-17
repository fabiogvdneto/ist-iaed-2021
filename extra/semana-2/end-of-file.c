#include <stdio.h>

int contagem_de_caracteres()
{
    int contador = 0;

    /* EOF = End Of File (on UNIX terminal = Ctrl-D) */
    while (getchar() != EOF)
    {
        contador++;
    }

    printf("Number of chars: %d", contador);

    return 0;
}