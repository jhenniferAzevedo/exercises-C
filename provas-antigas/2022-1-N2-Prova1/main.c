#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
    int resp;
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
            shows_query_per_student(aluno, turma);
            break;
        
        case 2:
            shows_query_per_class(turma);
            break;
        
        case 0:
            puts("\nFinalizando programa...");
            break;
        
        default:
            printf("\nValor Invalido! Digite um valor valido.\n");
            system("pause");
            break;
        }
    } while (resp);

    return 0;
}
