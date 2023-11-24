#include <stdio.h>
#include "library.h"

int main(void)
{
    int vet[5] = {1, 2, 3, 4, 5};

    puts("\n(1) imprime: ");
    imprime1(vet, 5);

    puts("\n\n(2) imprime: ");
    imprime2(vet);

    puts("\n\n(3) imprime: ");
    imprime3(vet, 5);

    puts("\n\n(4) imprime: ");
    int mat[3][4] = {{ 1,   2,   3,   4}, 
                     {50,  60,  70,  80}, 
                     {91, 101, 111, 121}};
    imprime4(mat, 3);

    puts("\n\n(5) imprime: ");
    TipoPessoa pessoa = {30, "João"};
    imprime5(pessoa);

    return 0;
}