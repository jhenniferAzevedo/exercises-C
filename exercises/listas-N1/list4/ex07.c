/* Uma importadora envia seus produtos para várias regiões do País. Os códigos de destino adotados são: 
1 para Sul, 2 para Norte, 3 e 4 para Leste e 5 a 10 para Oeste. Cada região tem uma alíquota de imposto. 
    1. Para a região Sul, a alíquota é de 10%; 
    2. Para a região Norte, é de 5%; 
    3. Para a região Leste, é de 8%;
    4. Para a região Oeste, é de 9%. 
Elabore um algoritmo que leia o código de destino e imprima o nome do destino e a sua alíquota. */

#include <stdio.h>

int main(void)
{
    int codigo_de_destino;

    printf("Para descobrir o valor da aliquota de imposto da sua regiao, digite o codigo de destino: ");
    scanf("%d", &codigo_de_destino);

    if (codigo_de_destino == 1)
    {
        printf("A regiao Sul possui uma aliquota de 10%%.\n");
    }
    else if (codigo_de_destino == 2)
    {
        printf("A regiao Norte possui uma aliquota de 5%%.\n");
    }
    else if (codigo_de_destino < 5)
    {
        printf("A regiao Leste possui uma aliquota de 8%%.\n");
    }
    else if (codigo_de_destino < 11)
    {
        printf("A regiao Oeste possui uma aliquota de 9%%.\n");
    }
    else
    {
        printf("Infelizmente, nao enviamos para esta regiao.\n");
    }
    
    return 0;
}