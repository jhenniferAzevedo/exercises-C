/* Escreva um algoritmo para imprimir os 10 primeiros números inteiros maiores que 100. */

#include <stdio.h>

int main(void)
{
    int num = 100, i;

    for (i = 1; i <= 10; i++)
    {
        printf("%d ", i + num);
    }
    
    printf("\n");
    return 0;
}