/* Faça uma função que recebe um valor inteiro e verifica se o valor é positivo, 
negativo ou zero. A função deve retornar 1 para valores  positivos, -1 para 
negativos e 0 para o valor 0. */

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