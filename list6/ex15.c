/* O mesmo exercício anterior, mas agora não será informado o número de mercadorias 
em estoque. Então o funcionamento deverá ser da seguinte forma: ler o valor da 
mercadoria e perguntar ‘MAIS MERCADORIAS (S/N)?’. Ao final, imprimir o valor total 
em estoque e a média de valor das mercadorias em estoque. */

#include <stdio.h>

int main(void)
{
    char op;
    int total = 0;
    float valor, media = 0;

    do
    {
        total++;
        printf("\t> valor do produto %d: R$", total);
        scanf("%f", &valor);
        media += valor;

        printf("\n\tMais mercadorias? (s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');

    media /= total;
    printf("\n>>> Valor total de mercadorias no estoque: %d", total);
    printf("\n>>> Media do valor das mercadorias: R$%.2f\n", media);
    return 0;
}