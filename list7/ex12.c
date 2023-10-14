/* Foi feita uma pesquisa entre os habitantes de uma região. Nela, coletaram
os dados de idade, sexo e salário. Faça um algoritmo que mostre o número total
de pessoas consultadas, a média de salários do grupo e a idade e o sexo da
pessoa que tem o menor salário. Para encerrar a entrada de dados, será inserido
-1 na idade. Considere que pelo menos uma pessoa foi consultada. */

#include <stdio.h>

int main(void)
{
    char sexo, sexoMenorSalario;
    int idade, idadeMenorSalario = 0, totalConsultas = 0;
    float salario, salarioMenor = 1000000, totalMediaSalario = 0;

    printf("* PESQUISA SALARIAL *");
    printf("\nFinalize com -1 no lugar da idade\n");

    printf("\n\tHABITANTE %d\n", totalConsultas + 1);
    printf("\t> idade: ");
    scanf("%d", &idade);

    while (idade == -1)
    {
        printf("\n\tE' necessario consultar ao menos uma pessoa! Digite uma idade valida.\n\n");
        printf("\t> idade: ");
        scanf("%d", &idade);
    }

    do
    {
        printf("\t> sexo (F) ou (M): ");
        scanf(" %c", &sexo);

        printf("\t> salario: R$");
        scanf("%f", &salario);
        totalMediaSalario += salario;
        
        if (salario < salarioMenor)
        {
            salarioMenor = salario;
            idadeMenorSalario = idade;
            sexoMenorSalario = sexo;
        }

        totalConsultas++;
        printf("\n\tHABITANTE %d\n", totalConsultas + 1);
        printf("\t> idade: ");
        scanf("%d", &idade);
    } while (idade != -1);

    totalMediaSalario /= totalConsultas;

    printf("\nRESULTADO DA PESQUISA");
    printf("\n>>> Numero total de pessoas consultadas: %d.", totalConsultas);
    printf("\n>>> Media de salarios do grupo: R$%.2f", totalMediaSalario);
    printf("\n>>> Idade da pessoa que tem o menor salario: %d.", idadeMenorSalario);
    printf("\n>>> Sexo da pessoa que tem o menor salario: ");

    if (sexoMenorSalario == 'F' || sexoMenorSalario == 'f')
    {
        printf("feminino.\n");
    }
    else
    {
        printf("masculino.\n");
    }

    return 0;
}