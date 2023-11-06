#include <stdio.h>
#include "header.h"

/* Leitura de todos os dados */
void read_data(student_data student[][MAX_TURMAS], class_data class[])
{
    int n_class, total_students;
    for (n_class = 0; n_class < MAX_TURMAS; n_class++)
    {
        printf("\nTURMA %d\n", n_class + 1);
        printf("Ha quantos alunos na turma? ");
        scanf("%d", &total_students);
        check_number_of_students(&total_students);
        class[n_class].total_alunos = total_students;
        read_student_data(student, n_class, total_students);
    }
}

void read_student_data(student_data student[][MAX_TURMAS], int n_class, int total_students)
{
    int n_student;
    for (n_student = 0; n_student < total_students; n_student++)
    {
        printf("\n\tALUNO %d\n", n_student + 1);
        read_names_by_student(student, n_student, n_class);
        read_grades_by_student(student, n_student, n_class);
        read_absences_by_student(student, n_student, n_class);
    }
}

void read_grades_by_student(student_data student[][MAX_TURMAS], int n_student, int n_class)
{
    int n_grade;
    for (n_grade = 0; n_grade < MAX_NOTAS; n_grade++)
    {
        printf("\t(%d) Nota: ", n_grade + 1);
        scanf("%f", &student[n_student][n_class].notas[n_grade]);
    }
}

void read_names_by_student(student_data student[][MAX_TURMAS], int n_student, int n_class)
{
    printf("\tNome: ");
    scanf("%s", student[n_student][n_class].nome);
}

void read_absences_by_student(student_data student[][MAX_TURMAS], int n_student, int n_class)
{
    printf("\tFaltas: ");
    scanf("%d", &student[n_student][n_class].faltas);
}

void check_number_of_students(int *number_of_students)
{
    while (*number_of_students > 5)
    {
        printf("Nao e permitido mais que 5 alunos!\n"
                "Digite um valor valido. \n\n"
                "Ha quantos alunos na turma? ");
        scanf("%d", number_of_students);
    }
}

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
    counts_zeroed_grades(student, class);
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

void check_student(class_data class[], int *n_student, int *n_class)
{
    
    while (*n_student < 1 || *n_student > class[*n_class].total_alunos)
    {
        printf("Esse aluno nao existe! \n"
                "Digite um valor valido. \n\n"
                "Qual e o numero do aluno? ");
        scanf("%d", n_student);
    }
}

void check_class(int *n_class)
{
    while (*n_class < 1 || *n_class > MAX_TURMAS)
    {
        printf("Essa turma nao existe! \n"
                "Digite um valor valido. \n\n"
                "Qual e o numero da turma? ");
        scanf("%d", n_class);
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

void counts_zeroed_grades(student_data student[][MAX_TURMAS], class_data class[])
{
    int i, j, k, count;

    for (i = 0; i < MAX_TURMAS; i++)
    {
        count = 0;
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
