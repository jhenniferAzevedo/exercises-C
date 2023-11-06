#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
    int n_nota, n_aluno, n_turma, qnt_alunos, resp;
    student_data aluno[MAX_ALUNOS][MAX_TURMAS];
    class_data turma[MAX_TURMAS];

    for (n_turma = 0; n_turma < MAX_TURMAS; n_turma++)
    {
        printf("\nTURMA %d\n", n_turma + 1);
        printf("Ha quantos alunos na turma? ");
        scanf("%d", &qnt_alunos);

        while (qnt_alunos > 5)
        {
            printf("Nao e permitido mais que 5 alunos!\n"
                    "Digite um valor valido. \n\n"
                    "Ha quantos alunos na turma? ");
            scanf("%d", &qnt_alunos);
        }

        turma[n_turma].total_alunos = qnt_alunos;

        for (n_aluno = 0; n_aluno < qnt_alunos; n_aluno++)
        {

            printf("\n\tALUNO %d\n", n_aluno + 1);
            
            printf("\tNome: ");
            scanf("%s", aluno[n_aluno][n_turma].nome);

            for (n_nota = 0; n_nota < MAX_NOTAS; n_nota++)
            {
                printf("\t(%d) Nota: ", n_nota + 1);
                scanf("%f", &aluno[n_aluno][n_turma].notas[n_nota]);
            }

            printf("\tFaltas: ");
            scanf("%d", &aluno[n_aluno][n_turma].faltas);
        }
    }
    
    calculate_data(aluno, turma);

    /* Relatórios */
    do
    {
        system("cls");
        show_menu();
        scanf("%d", &resp);

        switch (resp)
        {
        case 1:
            printf("\nQual e o numero do aluno e sua turma? ");
            scanf("%d %d", &n_aluno, &n_turma);
            n_aluno--;
            n_turma--;

            show_stutent_data(aluno, n_aluno, n_turma);
            system("pause");
            break;
        
        case 2:
            printf("\nQual e o numero da turma? ");
            scanf("%d", &n_turma);
            n_turma--;
            
            show_class_data(turma, n_turma);
            system("pause");
            break;
        
        case 0:
            puts("\nFinalizando programa...");
            break;
        
        default:
            printf("Valor Invalido! Digite um valor valido.\n");
            break;
        }
    } while (resp);

    return 0;
}

/* Curso de 1 ano
 * Total de 2 turmas
 * No máximo 5 alunos
 * Três notas ao longo do ano
 * Media final = media aritmetica dessas notas
 */

/* Inputs
 * Nome 
 * Notas
 * Frequência
 */

/* Consulta por aluno
 * Nome
 * Notas
 * Média final
 * Frequência
 * Mensagem
 */

/* Consulta por turma
 * Total de alunos
 * Total de médias acima de 8
 * Total de provas substitutivas
 * Média das médias
 */

/* Consulta por aluno: Dado o número do aluno e de sua turma, mostre seu nome, suas notas,
 * sua média final, sua frequência e uma das mensagens: “Reprovado por falta”, “Reprovado por
 * nota”, “Certificado Liberado” ou “Fará substitutiva”.
 * 
 * Consulta por turma: Dado o número da turma, mostre quantos alunos tem a turma, quantos
 * tiveram média final acima de 8, quantos alunos tiveram algum zero em suas notas, quantos
 * farão prova substitutiva e qual é a média de notas geral da turma. 
 */