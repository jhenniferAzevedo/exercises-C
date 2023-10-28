/* Uma loja está levantando o valor total de todas as mercadorias em estoque.
Escreva um algoritmo que permita a entrada das seguintes informações: o número
total de mercadorias no estoque e o valor de cada mercadoria. Ao final imprimir
o valor total em estoque e a média de valor das mercadorias. */

#include <stdio.h>

int main(void)
{
    int total, i;
    float valor, media = 0;

    printf("\tQual e o numero de mercadorias? ");
    scanf("%d", &total);

    for (i = 0; i < total; i++)
    {
        printf("\t> valor do produto %d: R$", i + 1);
        scanf("%f", &valor);
        media += valor;
    }

    media /= total;
    printf("\n>>> Valor total de mercadorias no estoque: %d", total);
    printf("\n>>> Media do valor das mercadorias: R$%.2f\n", media);
    return 0;
}