/* Elabore um algoritmo que calcule o valor recebido por um funcionário, dados
seu salário e número de filhos. Considere que haverá um desconto de imposto de 10% do
salário, se o salário for mais que R$ 3000,00 e de 5% para salários menores. Existe um
auxílio-alimentação de R$300,00 para salários até R$1000,00, e de R$ 150,00 para salários
até R$ 3000,00. Existe ainda um auxílio escola que é de R$200,00 por cada filho. No final,
o usuário terá a opção de fazer novo cálculo ou de finalizar o programa. */

#include <stdio.h>

int main(void)
{
    char op;
    int filhos;
    float salario, imposto, auxilioAlim , auxilioEsc, valorFinal;

    printf("* Calculadora de impostos e auxilios *\n");

    do
    {
        printf("\n\t> valor do salario: R$");
        scanf("%f", &salario);

        printf("\t> numero de filhos: ");
        scanf("%d", &filhos);

        if (salario <= 1000)
        {
            auxilioAlim = 300;
            imposto = 0.95;
        }
        else
        {
            if (salario <= 3000)
            {
                auxilioAlim = 150;
                imposto = 0.95;
            }
            else
            {
                auxilioAlim = 0;
                imposto = 0.9;
            }
        }

        auxilioEsc = filhos * 200;
        valorFinal = (salario + auxilioAlim + auxilioEsc) * imposto;

        printf("\n\t>>> valor final: R$%.2f\n", valorFinal);
        printf("\n\tdeseja fazer um novo calculo?  (s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');

    printf("fim.\n");
    return 0;
}