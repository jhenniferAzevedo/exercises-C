#define MAX_TURMAS 2
#define MAX_ALUNOS 5
#define MAX_NOTAS 3

/* Novo tipo para armazenar os dados de cada aluno. */
typedef struct student_data
{
    char nome[50];
    int faltas;
    float notas[MAX_NOTAS],
          media_final;
} student_data;

/* Novo tipo para armazenar os dados de cada turma. */
typedef struct class_data
{
    int total_alunos,
        total_nota_zerada,
        total_medias_acima_8,
        total_provas_subst;
    float media_geral;
} class_data;


/* Lê as notas dos alunos de cada turma. */
/* void read_grades(float grades[][][]); */

/* Mostra o menu de relatórios. */
void show_menu(void);

/* Chama as funções abaixo para calcular todos os dados:
 * calculate_final_average();
 * counts_final_average_8();
 * counts_zeroed_notes();
 * counts_substitute_test();
 * calculate_class_average();
 */
void calculate_data(student_data student[][MAX_TURMAS], class_data class[]);


/* Mostra o relatório do aluno de acordo com seu número e sua turma. */
void show_stutent_data(student_data student[][MAX_TURMAS], int n_student, int n_class);

/* Calcula o valor da média final de cada um dos alunos. */
void calculate_final_average(student_data student[][MAX_TURMAS]);

/* Retorna o status do aluno (aprovado, recuperação, reprovado por nota ou por falta). */
int check_student_status(student_data student[][MAX_TURMAS], int n_student, int n_class);

/* Mostra a mensagem de acordo com o status do aluno. */
void show_message(int status);


/* Mostra o relatório da turma especificada. */
void show_class_data(class_data class[], int n_class);

/* Verfica se as médias finais dos alunos da turma especificada são maiores que 8.
 * Então, esse valor é contado. */
void counts_final_average_8(student_data student[][MAX_TURMAS], class_data class[]);

/* Verifica quais alunos zeraram alguma nota. Então, esse valor é contado. */
void counts_zeroed_notes(student_data student[][MAX_TURMAS], class_data class[]);

/* Verifica quantos alunos farão prova substitutiva. Então, esse valor é contado. */
void counts_substitute_test(student_data student[][MAX_TURMAS], class_data class[]);

/* Calcula o valor da média geral de cada um das turmas. */
void calculate_class_average(student_data student[][MAX_TURMAS], class_data class[]);
