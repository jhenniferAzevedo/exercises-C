#include <stdio.h>
#include "header.h"

int main()
{
    register_data cadastros[25];
    counter_data contador = {0};

    FILE *fptr = fopen("file-on-disk.out", "wb");

    if (fptr == NULL)
    {
        printf(RED_TEXT
               "\nERROR: Arquivo inexistente.\n"
               RESET_TEXT);
        return 1;
    }

    read_data(cadastros, &contador);
    printf(GREEN_TEXT 
            "\nArquivo salvo com sucesso!\n\n"
            RESET_TEXT);
    fwrite(cadastros, sizeof(register_data), 25, fptr);
    fwrite(&contador, sizeof(counter_data), 1, fptr);
    fclose(fptr);
    return 0;
}

