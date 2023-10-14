/* Um banco concederá um crédito especial, cujo valor é calculado conforme tabela a seguir, aos 
seus clientes de acordo com o saldo médio no último ano. Elabore um algoritmo que, dado o saldo 
médio de um cliente, calcule o valor do crédito. Repita, quantas vezes o usuário quiser. */

/*                  TABELA DOS VALORES
   |  Saldo Médio (R$)   |   Valor do Crédito               |
   |---------------------|----------------------------------|
   |  De 0 a 500         |   Nenhum crédito                 |
   |  De 501 a 1000      |   30% do valor do saldo médio    |
   |  De 1001 a 3000     |   40% do valor do saldo médio    |
   |  Acima de 3001      |   50% do valor do saldo médio    | 
*/

#include <stdio.h>

int main(void)
{
    float saldo;

    printf("\t*** finalize com -1 ***\n");
    printf("Digite o saldo medio do ultimo ano: ");
    scanf("%f", &saldo);

    while(saldo!=-1)
    {
        if (saldo <= 500)
        {
            printf(">>> Nao ha nenhum credito liberado para voce.\n\n");
        }
        else if (saldo <= 1000) { saldo *= 0.3;
            printf(">>> O valor do credito disponivel para voce e de R$%.2f.\n\n", saldo*0.3);
        }
        else if (saldo <= 3000)
        {
            printf(">>> O valor do credito disponivel para voce e de R$%.2f.\n\n", saldo*0.4);
        }
        else
        {
            printf(">>> O valor do credito disponivel para voce e de R$%.2f.\n\n", saldo*0.5);
        }
        
        printf("Digite o saldo medio do ultimo ano: ");
        scanf("%f", &saldo);
    }
    printf("fim.\n\n");
    return 0;
}