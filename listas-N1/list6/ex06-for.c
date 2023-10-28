/* Escreva no monitor a tabuada de multiplicação do 5 */

#include <stdio.h>

int main(void)
{
    int num = 5, cont;

    printf("\tTabuada do %d\n", num);
    for (cont = 0; cont <= 10; cont++)
    {
        printf("\t> %d x %d = %d\n", num, cont, num * cont);
    }

    return 0;
}