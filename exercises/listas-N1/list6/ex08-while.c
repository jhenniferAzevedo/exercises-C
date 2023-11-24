/* Escreva no monitor a tabuada de multiplicação do 2 ao 10 */

#include <stdio.h>

int main(void)
{
    int n1, n2;

    n1 = 0;
    while (n1 <= 10)
    {
        printf("\n\tTabuada do %d\n", n1);
        n2 = 0;
        while (n2 <= 10)
        {
            printf("\t> %d x %d = %d\n", n1, n2, n1 * n2);
            n2++;
        }
        n1++;
    }
    return 0;
}