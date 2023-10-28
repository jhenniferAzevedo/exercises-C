/* Escreva no monitor a tabuada de multiplicação do 5 */

#include <stdio.h>

int main(void)
{
    int num = 5, cont = 0;

    printf("\tTabuada do %d\n", num);
    while(cont <= 10)
    {
        printf("\t> %d x %d = %d\n", num, cont, num * cont);
        cont++;
    }

    return 0;
}