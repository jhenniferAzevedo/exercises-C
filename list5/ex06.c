/* Modifique o programa do item anterior, para que mostre também
    a. a média geral da turma;
    b. quantos passaram direto;
    c. (DESAFIO) qual foi a maior média final.
*/

#include <stdio.h>

int main(void)
{
    int i, passou_direto = 0;
    float nota1, nota2, media, media_geral = 0, media_maior = 0;

    for (i = 0; i < 10; i++)
    {
        printf("\n\n\tALUNO %d\n", i + 1);
        printf("\t> Nota do primeiro bimestre: ");
        scanf("%f", &nota1);

        printf("\t> Nota do segundo bimestre: ");
        scanf("%f", &nota2);

        media = (nota1 + nota2) / 2;

        if (media >= 7)
        {
            printf("\t>>> passou direto com a nota %.1f.\n", media);
            passou_direto++;
        }
        else
        {
            printf("\t>>> precisara fazer a recuperacao, pois sua nota foi %.1f.\n", media);
        }

        media_geral += media;

        if (media > media_maior)
        {
            media_maior = media;
        }
    }
    media_geral /= i;

    printf("\n>>> Media geral da turma: %.1f\n", media_geral);
    printf(">>> Maior media da turma: %.1f\n", media_maior);
    printf(">>> Quantidade de alunos que passaram direto: %d\n", passou_direto);
    return 0;
}