#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
    int n_aluno, n_turma, resp;
    student_data aluno[MAX_ALUNOS][MAX_TURMAS];
    class_data turma[MAX_TURMAS];

    read_data(aluno, turma);
    calculate_data(aluno, turma);

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

            check_all(turma, &n_aluno, &n_turma);
            show_stutent_data(aluno, n_aluno, n_turma);
            system("pause");
            break;
        
        case 2:
            printf("\nQual e o numero da turma? ");
            scanf("%d", &n_turma);
            n_turma--;

            check_class(&n_turma);
            show_class_data(turma, n_turma);
            system("pause");
            break;
        
        case 0:
            puts("\nFinalizando programa...");
            break;
        
        default:
            printf("Valor Invalido! Digite um valor valido.\n");
            system("pause");
            break;
        }
    } while (resp);

    return 0;
}
