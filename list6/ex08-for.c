/* Escreva no monitor a tabuada de multiplicação do 2 ao 10 */

#include <stdio.h>

int main(void)
{
    int n1, n2;

    for (n1 = 2; n1 <= 10; n1++)
    {
        printf("\n\tTabuada do %d\n", n1);
        for (n2 = 0; n2 <= 10; n2++)
        {
            printf("\t> %d x %d = %d\n", n1, n2, n1 * n2);
        }
    }
    return 0;
}