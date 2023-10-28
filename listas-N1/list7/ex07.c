/* Deseja-se fazer um levantamento a respeito da ausência de alunos em uma prova
para as 14 turmas existentes. Para cada aluno, será fornecida como entrada a letra
A ou P (ausente ou presente). Calcule a porcentagem de ausências geral das turmas
e informe quantas turmas tiveram ausência superior a 5%. */

#include <stdio.h>
#define QNT_MAX_TURMA 14

int main(void)
{
    char presenca;
    int i, j, porcentagemMaior5 = 0, qntAlunos, ausencias = 0, totalAlunos = 0;
    float porcentagemAusencias;

    for (i = 0; i < QNT_MAX_TURMA; i++)
    {
        printf("\n * TURMA %d * \n", i + 1);
        printf("\tQual a quantidade de alunos dessa turma? ");
        scanf("%d", &qntAlunos);
        totalAlunos += qntAlunos;

        printf("\tdigite A para AUSENTE e P para PRESENTE.\n\n");
        printf("\tLISTA DE FREQUENCIA\n");
        for (j = 0; j < qntAlunos; j++)
        {
            printf("\t>>> Aluno %d: ", j + 1);
            scanf(" %c", &presenca);

            if (presenca == 'A' || presenca == 'a')
            {
                ausencias++;
            }
        }
    }

    porcentagemAusencias = (ausencias * 100) / totalAlunos;

    if (porcentagemAusencias > 5)
    {
        porcentagemMaior5++;
    }

    printf("\n--> Porcentagem de ausencias: %.2f%%", porcentagemAusencias);
    printf("\n--> Turmas com ausencia superior a 5%%: %d\n", porcentagemMaior5);

    return 0;
}