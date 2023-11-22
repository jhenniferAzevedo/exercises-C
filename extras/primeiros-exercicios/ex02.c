/* Ler a idade de 50 pessoas, mostrar a média das idades, o número de pessoas com
idade abaixo da média, porcentagem de menores de idade e a idade do mais velho. */

#include <stdio.h>
#define QNT_MAX_PESSOAS 50

int main(void)
{
    int pessoa, idade[QNT_MAX_PESSOAS];
    int idadesAbaixoDaMedia = 0, idadeMaisVelho = 0, porcentagemMenorDeIdade = 0;
    float mediaIdades = 0;

    for (pessoa = 0; pessoa < QNT_MAX_PESSOAS; pessoa++)
    {
        printf("idade da pessoa %d: ", pessoa + 1);
        scanf("%d", &idade[pessoa]);
        mediaIdades += idade[pessoa];

        if (idade[pessoa] < 18)
        {
            porcentagemMenorDeIdade++;
        }
        if (idade[pessoa] > idadeMaisVelho)
        {
            idadeMaisVelho = idade[pessoa];
        }
    }

    for (pessoa = 0; pessoa < QNT_MAX_PESSOAS; pessoa++)
    {
        if (idade[pessoa] < mediaIdades)
        {
            idadesAbaixoDaMedia++;
        }
    }

    printf("\n  RESPOSTAS\n");
    printf("media das idades: %.1f\n", mediaIdades / pessoa);
    printf("pessoas com idade abaixo da media: %d\n", idadesAbaixoDaMedia);
    printf("porcentagem de menores de idade: %d%%\n", (porcentagemMenorDeIdade * 100) / pessoa);
    printf("idade da pessoa mais velha: %d\n", idadeMaisVelho);

    return 0;
}