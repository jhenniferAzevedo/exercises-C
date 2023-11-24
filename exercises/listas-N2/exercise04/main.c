#include <stdio.h>
#include "header.h"

int main(void)
{
    int a;
    printf("\nDigite um valor: ");
    scanf("%d", &a);

    switch (sinal(a))
    {
    case 1:
        printf("\nO valor e positivo. \n\n");
        break;

    case -1:
        printf("\nO valor e negativo. \n\n");
        break;

    case 0:
        printf("\nO valor e 0. \n\n");
        break;
    }

    return 0;
}