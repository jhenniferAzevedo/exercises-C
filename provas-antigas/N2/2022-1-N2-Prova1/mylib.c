#include <stdio.h>
#include <string.h>
#include "header.h"

void show_menu(void)
{
    int resp;
    printf("\nRelatorios:\n"
           "(0) Finalizar programa \n"
           "(1) Consulta por aluno \n"
           "(2) Consulta por turma \n");
}

void calculate_data(student_data student[][MAX_TURMAS], class_data class[])
{
    calculate_final_average(student, class);
    counts_final_average_8(student, class);
    counts_zeroed_notes(student, class);
    counts_substitute_test(student, class);
    calculate_class_average(student, class);
}

/* Tratamento dos dados referente aos alunos */
void show_stutent_data(student_data student[][MAX_TURMAS], int n_student, int n_class)
{
    int status_final = check_student_status(student, n_student, n_class);
    printf("\n> Nome do estudante: %s \n"
           "> Primeira nota: %.1f \n"
           "> Segunda nota: %.1f \n"
           "> Terceira nota: %.1f \n"
           "> Numero de faltas: %d \n"
           "> Media final: %.1f \n",
           student[n_student][n_class].nome,
           student[n_student][n_class].notas[0],
           student[n_student][n_class].notas[1],
           student[n_student][n_class].notas[2],
           student[n_student][n_class].faltas,
           student[n_student][n_class].media_final);
    show_message(status_final);
}

int check_student_status(student_data student[][MAX_TURMAS], int n_student, int n_class)
{
    int absences = student[n_student][n_class].faltas;
    float final_grade = student[n_student][n_class].media_final;

    if (absences > 10)
    {
        return 0;
    }
    
    if (final_grade < 5)
    {
        return 1;
    }

    if (final_grade >= 7)
    {
        return 2;
    }
    
    return 3;
}

void show_message(int status)
{
    switch (status)
    {
    case 0:
        puts("> Reprovado por falta.");
        break;
    
    case 1:
        puts("> Reprovado por nota.");
        break;
    
    case 2:
        puts("> Certificado Liberado.");
        break;
    
    case 3:
        puts("> Fara substitutiva.");
        break;
    }
}

void calculate_final_average(student_data student[][MAX_TURMAS], class_data class[])
{
    int i, j, k;

    for (i = 0; i < MAX_TURMAS; i++)
    {
        for (j = 0; j < class[i].total_alunos; j++)
        {
            student[j][i].media_final = 0;
            for (k = 0; k < MAX_NOTAS; k++)
            {
                student[j][i].media_final += student[j][i].notas[k];
            }
            student[j][i].media_final /= MAX_NOTAS;
        }
    }
}

/* Tratamento dos dados referente às turmas */
void show_class_data(class_data class[], int n_class)
{
    printf("\n> Quantidade de alunos da turma: %d \n"
           "> Quantidade de alunos com media final maior que 8: %d \n"
           "> Quantidade de alunos que tiraram algum zero: %d \n"
           "> Quantidade de alunos que farao prova substitutiva: %d \n"
           "> Media geral da turma: %.1f \n",
           class[n_class].total_alunos,
           class[n_class].total_medias_acima_8,
           class[n_class].total_nota_zerada,
           class[n_class].total_provas_subst,
           class[n_class].media_geral);
}

void counts_final_average_8(student_data student[][MAX_TURMAS], class_data class[])
{
    int i, j;

    for (i = 0; i < MAX_TURMAS; i++)
    {
        class[i].total_medias_acima_8 = 0;
        for (j = 0; j < class[i].total_alunos; j++)
        {
            if (student[j][i].media_final > 8)
            {
                class[i].total_medias_acima_8++;
            }
        }
    }
}

void counts_zeroed_notes(student_data student[][MAX_TURMAS], class_data class[])
{
    int i, j, k, count = 0;

    for (i = 0; i < MAX_TURMAS; i++)
    {
        class[i].total_nota_zerada = 0;
        for (j = 0; j < class[i].total_alunos; j++)
        {
            for (k = 0; k < MAX_NOTAS; k++)
            {
                if (student[j][i].notas[k] == 0)
                {
                    count++;
                }
            }

            if (count > 0)
            {
                class[i].total_nota_zerada++;
            }
        }
    }
}

void counts_substitute_test(student_data student[][MAX_TURMAS], class_data class[])
{
    int i, j, status;

    for (i = 0; i < MAX_TURMAS; i++)
    {
        class[i].total_provas_subst = 0;
        for (j = 0; j < class[i].total_alunos; j++)
        {
            status = check_student_status(student, j, i);
            if (status == 3)
            {
                class[i].total_provas_subst++;
            }
        }
    }
}

void calculate_class_average(student_data student[][MAX_TURMAS], class_data class[])
{
    int i, j, k;

    for (i = 0; i < MAX_TURMAS; i++)
    {
        class[i].media_geral = 0;
        for (j = 0; j < class[i].total_alunos; j++)
        {
            class[i].media_geral += student[j][i].media_final;
        }
        class[i].media_geral /= class[i].total_alunos;
    }
}
