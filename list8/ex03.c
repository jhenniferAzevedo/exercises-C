/* Ler 15 números inteiros, mostrar o maior deles e mostrar esses números em ordem inversa da leitura. */

#include <stdio.h>

int main(void)
{
    int i, num[15];
    for (i = 0; i < 15; i++)
    {
        printf("numero inteiro: ");
        scanf("%d", &num[i]);
    }

    printf("\nORDEM INVERSA\n");
    for (i = 14; i >= 0; i--)
    {
        printf("%d ", num[i]);
    }
    printf("\nfim.\n");
    return 0;
}