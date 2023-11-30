#define RED_TEXT   "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define RESET_TEXT "\x1b[0m"

typedef struct student_data
{
    char nome[50];
    int frequencia,
        status;
    float nota[2],
          media_final;
} student_data;

typedef struct class_data
{
    int total_alunos,
        media_maior_8,
        notas_zeradas,
        farao_substitutiva;
    float media_geral;
} class_data;

// Leituras
void read_data(class_data class[], student_data student[][30]);
void read_student_data(class_data class[], student_data student[][30], int n_class);
void check_frequency(int *frequency);
void check_grade(float *grade, int n);

// Relatorios
void menu_reports(int *answer);
void pause_and_clear(void);
void show_reports(class_data class[], student_data student[][30]);
void show_reports_per_student(class_data class[], student_data student[][30]);
void check_class(int *n_class);
void check_student(class_data class[], int n_class, int *n_student);
void show_data_students(student_data student[][30], int n_class, int n_student);
void calculate_average(student_data student[][30], int n_class, int n_student);
void check_status(student_data student[][30], int n_class, int n_student);
void show_message(int status);
void show_reports_per_class(class_data class[], student_data student[][30]);
void show_data_class(class_data class[], int n_class);
void count_avarage_8(class_data class[], student_data student[][30], int n_class);
void count_grade_zero(class_data class[], student_data student[][30], int n_class);
void count_substitute_exam(class_data class[], student_data student[][30], int n_class);
void calculate_general_avarage(class_data class[], student_data student[][30], int n_class);
