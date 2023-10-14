/* Ler as notas finais de 3 turmas de no máximo 30 alunos (não perguntar o número de alunos).
   Disponibilizar as seguintes relatórios:
    - Nota individual: Dados número do aluno e número da turma, mostre a nota.
    - Média da turma: Dado número da turma, mostre a média de notas da turma.
    - Alunos acima da média: Dado número da turma, mostre quais alunos tiveram nota maior
    que a média de sua turma.
    - Maior média: Mostre a turma com maior média.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT_MAX_TURMAS 3
#define QNT_MAX_ALUNOS 30

int main(void)
{
    char op;
    int i, j, aluno, turma, turmaMaiorMedia = 0, teste = -1;
    float notasFinais[QNT_MAX_TURMAS][QNT_MAX_ALUNOS], media[QNT_MAX_TURMAS] = {0};

    // Leitura: Nota dos alunos de cada turma
    for (i = 0; i < QNT_MAX_TURMAS; i++)
    {
        printf("\nTURMA %d\n", i + 1);
        for (j = 0; j < QNT_MAX_ALUNOS; j++)
        {
            printf("nota do aluno %d: ", j + 1);
            scanf("%f", &notasFinais[i][j]);

            if (notasFinais[i][j] == -1)
            {
                break;
            }

            media[i] += notasFinais[i][j];
        }
        media[i] /= j;

        // Turma com a maior média
        if (media[i] > teste)
        {
            turmaMaiorMedia = i + 1;
            teste = media[i];
        }
    }

    // Relatório: Nota individual dos alunos
    do
    {
        printf("\n\nNOTA INDIVIDUAL DOS ALUNOS\n");
        printf("Numero da turma: ");
        scanf("%d", &turma);
        printf("Numero do aluno: ");
        scanf("%d", &aluno);

        printf("nota do aluno: %.1f\n", notasFinais[turma - 1][aluno - 1]);
        printf("\ndeseja continuar? (s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');

    // Relatório: Média individual das turmas
    do
    {
        printf("\n\nMEDIA INDIVIDUAL DAS TURMAS\n");
        printf("Numero da turma: ");
        scanf("%d", &turma);

        printf("media da turma: %.1f\n", media[turma - 1]);
        printf("\ndeseja continuar? (s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');

    // Relatório: Alunos acima da média de cada turma
    do
    {
        printf("\n\nALUNOS ACIMA DA MEDIA\n");
        printf("Numero da turma: ");
        scanf("%d", &turma);
        printf("\n");

        for (j = 0; j < QNT_MAX_ALUNOS; j++)
        {
            if (notasFinais[turma - 1][j] > media[turma - 1])
            {
                printf("aluno %d com a nota %.1f\n", j + 1, notasFinais[turma - 1][j]);
            }
        }

        printf("\ndeseja continuar? (s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');

    // Relatório: Turma com a maior média
    printf("\nTURMA COM MAIOR MEDIA: turma %d\n", turmaMaiorMedia);

    system("pause");
    return 0;
}