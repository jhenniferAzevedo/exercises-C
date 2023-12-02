#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "library.h"

// Leituras
void read_data(class_data class[], student_data student[][30])
{
    for (int n_class = 0; n_class < 3; n_class++)
    {
        printf("\nTurma %d\n", n_class + 1);
        read_student_data(class, student, n_class);
    }
}

void read_student_data(class_data class[], student_data student[][30], int n_class)
{
    int answer, n_student = 0;
    do {
        printf("\n\tAluno (%d)\n", n_student + 1);

        printf("\tNome: ");
        scanf("%s", student[n_class][n_student].nome);
        printf("\tFaltas: ");
        scanf("%d", &student[n_class][n_student].faltas);
        check_frequency(&student[n_class][n_student].faltas);

        for (int i = 0; i < 2; i++)
        {
            printf("\tNota %d: ", i + 1);
            scanf("%f", &student[n_class][n_student].nota[i]);
            check_grade(&student[n_class][n_student].nota[i], i);
        }

        n_student++;
        
        printf("\nAinda ha alunos?" 
                "\n(0) Nao"
                "\n(1) Sim \n");
        scanf("%d", &answer);
    } while (answer);

    class[n_class].total_alunos = n_student;
}

void check_frequency(int *frequency)
{
    while (*frequency < 0)
    {
        printf(RED_TEXT 
                "\n\tERROR: Digite numeros positivos! \n"
               RESET_TEXT);
        printf("\tFaltas: ");
        scanf("%d", frequency);
    }
}

void check_grade(float *grade, int n)
{
    while (*grade < 0 || *grade > 10)
    {
        printf(RED_TEXT 
                "\n\tERROR: Digite numeros entre 0 e 10! \n"
               RESET_TEXT);
        printf("\tNota %d: ", n + 1);
        scanf("%f", grade);
    }
}

// Relatórios
void menu_reports(int *answer)
{
    printf("\nOPCOES"
           "\n(0) Finalizar"
           "\n(1) Ver relatorio por aluno"
           "\n(2) Ver relatorio por turma \n"
           "\nQual opcao deseja realizar? ");
    scanf("%d", answer);
}

void pause_and_clear(void)
{
    printf("\nDigite qualquer tecla para continuar...");
    getchar();
    getchar();
    system("clear");
}

void show_reports(class_data class[], student_data student[][30])
{
    int answer;
    do {
        menu_reports(&answer);
        system("clear");

        switch (answer)
        {
        case 1:
            show_reports_per_student(class, student);
            pause_and_clear();
            break;
        case 2:
            show_reports_per_class(class, student);
            pause_and_clear();
            break;
        case 0:
            printf("\nFinalizando...\n");
            break;
        
        default:
            printf(RED_TEXT
                    "\nERROR: Valor invalido!"
                   RESET_TEXT
                    "\nDigite um numero valido.\n");
            pause_and_clear();
        }
    } while (answer);
}

void show_reports_per_student(class_data class[], student_data student[][30])
{
    int n_class, n_student;
    
    printf("De qual turma? ");
    scanf("%d", &n_class);
    check_class(&n_class);

    printf("De qual aluno? ");
    scanf("%d", &n_student);
    check_student(class, n_class, &n_student);

    show_student_data(student, n_class, n_student);
    show_message(check_status(student, n_class, n_student));
}

void check_class(int *n_class)
{
    while (*n_class < 1 || *n_class > 3)
    {
        printf(RED_TEXT "\nERROR: Valor invalido!" RESET_TEXT
               "\nDigite um numero entre 1 e 3."
               "\nDe qual turma? ");
        scanf("%d", n_class);
    }
}

void check_student(class_data class[], int n_class, int *n_student)
{
    while (*n_student < 1 || *n_student > class[n_class].total_alunos)
    {
        printf(RED_TEXT "\nERROR: Valor invalido!" RESET_TEXT
               "\nDigite um numero entre 1 e %d."
               "\nDe qual turma? ",
               class[n_class].total_alunos);
        scanf("%d", n_student);
    }
}

void show_student_data(student_data student[][30], int n_class, int n_student)
{
    calculate_average(student, n_class, n_student);
    printf("\nNome: %s"
           "\nNota 1: %.1f"
           "\nNota 2: %.1f"
           "\nMedia Final: %.1f"
           "\nFaltas: %d",
           student[n_class][n_student].nome, 
           student[n_class][n_student].nota[0],
           student[n_class][n_student].nota[1],
           student[n_class][n_student].media_final,
           student[n_class][n_student].faltas);
}

void calculate_average(student_data student[][30], int n_class, int n_student)
{
    student[n_class][n_student].media_final =
        (student[n_class][n_student].nota[0] +
            student[n_class][n_student].nota[1]) / 2;
}

int check_status()
{
    if (student[n_class][n_student].faltas > 10)
    {
        return 3;
    }

    if (student[n_class][n_student].media_final < 5)
    {
        return 2;
    }

    if (student[n_class][n_student].media_final < 7)
    {
        return 1;
    }

    return 0;
}

void show_message(student_data student[][30], int n_class, int n_student)
{
    if (student[n_class][n_student].faltas > 10)
    {
        printf(RED_TEXT "\nReprovado por falta! \n" RESET_TEXT);
        return;
    }

    if (student[n_class][n_student].media_final < 5)
    {
        printf(RED_TEXT "\nReprovado por nota! \n" RESET_TEXT);
        return;
    }

    if (student[n_class][n_student].media_final < 7)
    {
        printf(GREEN_TEXT "\nFara substitutiva! \n" RESET_TEXT);
        return;
    }

    printf(GREEN_TEXT "\nAprovado! \n" RESET_TEXT);
}

void show_reports_per_class(class_data class[], student_data student[][30])
{
    int n_class;
    
    printf("De qual turma? ");
    scanf("%d", &n_class);
    check_class(&n_class);

    count_avarage_8(class, student, n_class);
    count_grade_zero(class, student, n_class);
    count_substitute_exam(class, student, n_class);
    calculate_general_avarage(class, student, n_class);

    show_class_data(class, n_class);
}

void show_class_data(class_data class[], int n_class)
{
    printf("\nTotal de alunos: %d"
           "\nTotal de alunos com media maior que 8: %d"
           "\nTotal de alunos que tiraram algum zero: %d"
           "\nTotal de alunos que fizeram prova substitutiva: %d"
           "\nMedia geral da turma: %.1f \n",
           class[n_class].total_alunos,
           class[n_class].media_maior_8,
           class[n_class].notas_zeradas,
           class[n_class].farao_substitutiva,
           class[n_class].media_geral);
}

void count_avarage_8(class_data class[], student_data student[][30], int n_class)
{
    for (int i = 0; i < class[n_class].total_alunos; i++)
    {
        calculate_average(student, n_class, i);
        if (student[n_class][i].media_final > 8)
        {
            (class[n_class].media_maior_8)++;
        }
    }
}

void count_grade_zero(class_data class[], student_data student[][30], int n_class)
{
    for (int i = 0; i < class[n_class].total_alunos; i++)
    {
        if (!(student[n_class][i].nota[0] && student[n_class][i].nota[1]))
        {
            (class[n_class].notas_zeradas)++;
        }
    }
}

void count_substitute_exam(class_data class[], student_data student[][30], int n_class)
{
    for (int i = 0; i < class[n_class].total_alunos; i++)
    {
        check_status(student, n_class, i);
        if (student[n_class][i].status == 1)
        {
            (class[n_class].farao_substitutiva)++;
        }
    }
}

void calculate_general_avarage(class_data class[], student_data student[][30], int n_class)
{
    for (int i = 0; i < class[n_class].total_alunos; i++)
    {
        calculate_average(student, n_class, i);
        class[n_class].media_geral += student[n_class][i].media_final;
    }
    class[n_class].media_geral /= class[n_class].total_alunos;
}

void show_all_data(class_data class[], student_data student[][30])
{
    printf(GREEN_TEXT "Carregando dados..." RESET_TEXT);
    for (int i = 0; i < 3; i++)
    {
        printf(GREEN_TEXT "\n>>> Turma (%d)" RESET_TEXT, i + 1);
        for (int j = 0; j < class[i].total_alunos; j++)
        {
            printf(RED_TEXT "\n\nAluno (%d)\n" RESET_TEXT, j + 1);
            show_student_data(student, i, j);
        }
        printf("\n\n");
    }
}
