#include <stdio.h>
#include "header.h"

int main(void)
{
    int valor;

    printf("\nDigite um valor: ");
    scanf("%d", &valor);

    if (par(valor))
    {
        printf("O valor é par.\n\n");
    }
    else
    {
        printf("O valor é impar.\n\n");
    }
    return 0;
}