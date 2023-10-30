#include <stdio.h>
#include "header.h"

int main(void)
{
    int n1, n2;

    printf("\nDigite dois valores: ");
    scanf("%d %d", &n1, &n2);

    printf("O maior valor e %d.\n\n", maior_valor(n1, n2));
    return 0;
}