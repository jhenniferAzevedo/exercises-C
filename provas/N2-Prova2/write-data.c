#include <stdio.h>
#include "mylib.h"

int main(void)
{
    student_data aluno[3][30];
    class_data turma[3] = {0};

    FILE *fptr = fopen("file-on-disk.out", "rb");

    if (fptr == NULL)
    {
        printf(RED_TEXT 
                "\nERROR: Arquivo inexistente.\n"
               RESET_TEXT);
        return 1;
    }

    fread(&aluno, sizeof(student_data), 3 * 30, fptr);
    fread(&turma, sizeof(class_data), 3, fptr);

    show_all_data(turma, aluno);
    fclose(fptr);

    return 0;
}
