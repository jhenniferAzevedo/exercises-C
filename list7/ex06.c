/* Faça um algoritmo que receba o preço de um produto e mostre, conforme tabelas a seguir,
o novo preço (preço com aumento), a classificação antes do aumento e a classificação depois
do aumento. Repita, quantas vezes o usuário quiser.

|                   Preço                    | Percentual de aumento |
|--------------------------------------------|-----------------------|
| Até R$ 50,00                               |          10%          |
| Entre R$ 50,00 e R$ 500,00 (inclusive)     |          20%          |
| Acima de R$ 500,00                         |          30%          |

|                   Preço                    |  Classificação  |
|--------------------------------------------|-----------------|
| Até R$ 80,00                               |     Barato      |
| Entre R$ 80,00 e R$ 600,00 (inclusive)     |     Normal      |
| Entre R$ 600,00 e R$ 800,00 (inclusive)    |      Caro       |
| Acima de R$ 800,00                         |    Muito Caro   |

*/

#include <stdio.h>

int main(void)
{
    char op;
    float preco;

    do
    {
        printf(">>> Digite o valor: R$");
        scanf("%f", &preco);
        printf("O preco era considerado ");

        if (preco <= 80) { printf("barato "); }
        else if (preco <= 600) { printf("normal "); }
        else if (preco <= 800) { printf("caro "); }
        else { printf("muito caro "); }

        printf("e depois do aumento ficou ");

        if (preco <= 50) { preco *= 1.1; }
        else if (preco <= 500) { preco *= 1.2; }
        else { preco *= 1.3; }
        

        if (preco <= 80) { printf("barato. \n"); }
        else if (preco <= 600) { printf("normal. \n"); }
        else if (preco <= 800) { printf("caro. \n"); }
        else { printf("muito caro. \n"); }
        
        printf("\nDeseja tentar novamente? (s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');

    printf("fim.\n\n");
    return 0;
}
