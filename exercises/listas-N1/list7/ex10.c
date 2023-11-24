/* Um curso de capacitação com 75 alunos possui os seguintes dados a serem registrados
para cada aluno: nome, notas de duas provas e do trabalho, número de aulas que esteve
presente e o número de horas de cada atividade extra que participou (não perguntar o
número de atividades extras do aluno). Para o aluno ser aprovado neste curso ele deve
ter no mínimo 60 pontos somando-se as notas das provas e do trabalho, ter frequentado
pelo menos 50 aulas e ter 200 horas ou mais de atividades extras. Se o aluno não alcançou
60 pontos de nota, mas alcançou os outros quesitos, poderá fazer recuperação caso sua nota
não seja inferior a 50. Elabore um algoritmo que, para cada aluno, receba seus dados e
informe se foi aprovado, reprovado ou fará recuperação. Mostrar também o número de alunos
que farão recuperação, o nome do aluno mais frequente e o número total de atividades extras
registradas (para toda a turma). */

#include <stdio.h>
#include <string.h>
#define QNT_MAX_ALUNOS 75

int main(void)
{
    char nome[20], nome_maior_presenca[20];
    int i, qnt_atividades_por_aluno = 0, qnt_atividades_por_turma = 0;
    int horas_extras_por_atividade, total_horas_extras_por_aluno;
    int presenca, valor_maior_presenca = 0, recuperacao = 0;
    float notaP1, notaP2, notaTrab, notaFinal;

    for (i = 0; i < QNT_MAX_ALUNOS; i++)
    {
        printf("\n* ALUNO %d *\n", i + 1);
        printf("\t> nome: ");
        scanf("%s", nome);

        printf("\t> nota da prova 1: ");
        scanf("%f", &notaP1);

        printf("\t> nota da prova 2: ");
        scanf("%f", &notaP2);

        printf("\t> nota do trabalho: ");
        scanf("%f", &notaTrab);

        printf("\t> quantidade de presencas: ");
        scanf("%d", &presenca);

        qnt_atividades_por_aluno = 0;
        printf("\n\tAgora, digite as horas de cada atividade extra.");
        printf("\n\tCaso nao tenha atividades extras ou deseje finalizar, digite 0.\n");
        printf("\t> horas extras da atividade %d: ", qnt_atividades_por_aluno + 1);
        scanf("%d", &horas_extras_por_atividade);

        total_horas_extras_por_aluno = 0;
        while (horas_extras_por_atividade != 0)
        {
            qnt_atividades_por_aluno++;
            total_horas_extras_por_aluno += horas_extras_por_atividade;
            printf("\t> horas extras da atividade %d: ", qnt_atividades_por_aluno + 1);
            scanf("%d", &horas_extras_por_atividade);
        }
        qnt_atividades_por_turma += qnt_atividades_por_aluno;

        notaFinal = notaP1 + notaP2 + notaTrab;
        printf("\n   tam tam tammmmm...\n   voce ");

        if (notaFinal >= 60 && presenca >= 50 && total_horas_extras_por_aluno >= 200)
        {
            printf("passou!! Boa.\n");
        }
        else if (notaFinal >= 50 && presenca >= 50 && total_horas_extras_por_aluno >= 200)
        {
            printf("fara recuperacao. Boa sorte!\n");
            recuperacao++;
        }
        else
        {
            printf("reprovou :(\n");
        }

        if (presenca > valor_maior_presenca)
        {
            valor_maior_presenca = presenca;
            strcpy(nome_maior_presenca, nome);
        }
        printf("\n\n");
    }

    printf("\n>>> Quantidade de alunos que farao recuperacao: %d.", recuperacao);
    printf("\n>>> O aluno que mais frequentou foi: %s.", nome_maior_presenca);
    printf("\n>>> O numero total de atividades extras de toda a turma foi: %d.\n", qnt_atividades_por_turma);
    return 0;
}