#include <stdio.h>
#include "mylib.h"

int main(void)
{
    student_data aluno[3][30];
    class_data turma[3] = {0};

    FILE *fptr = fopen("file-on-disk.out", "wb");

    if (fptr == NULL)
    {
        printf(RED_TEXT
               "\nERROR: Arquivo inexistente.\n"
               RESET_TEXT);
        return 1;
    }

    read_data(turma, aluno);
    fwrite(&aluno, sizeof(student_data), 3 * 30, fptr);
    fwrite(&turma, sizeof(class_data), 3, fptr);

    printf(GREEN_TEXT 
            "\nArquivo salvo com sucesso!\n\n"
            RESET_TEXT);
    fclose(fptr);
}
