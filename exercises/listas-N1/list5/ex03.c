/* Escreva os números pares de 1 a 20 no monitor. */

#include <stdio.h>

int main(void)
{
    int i;

    for (i = 1; i <=20; i += 2)
    {
        printf("%d ", i);
    }

    return 0;
}