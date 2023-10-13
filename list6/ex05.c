/* Escreva um algoritmo para ler 10 números. Todos os números lidos com valor
inferior a 40 devem ser somados. Escreva o valor final da soma efetuada */

#include <stdio.h>

int main(void)
{
    char sinal;
    int num, somaNum = 0;

    printf("\t*** serao somados apenas os numeros menores que 40 ***\n");
    printf("\t>>> Faca soma e finalize com sinal de igual (x + y =). \n\n\tsoma: ");

    do
    {
        scanf("%d", &num);
        if (num < 40) { somaNum += num; }
        scanf(" %c", &sinal);

    } while (sinal != '=');

    printf("\tresultado: %d\n", somaNum);
    return 0;
}

// responda com while ou do-while