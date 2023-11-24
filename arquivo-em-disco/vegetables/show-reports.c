#include <stdio.h>
#include "header.h"

int main(void)
{
    counters_data contador = {0};
    FILE *fptr = fopen("file-on-disk.out", "rb");

    if (fptr == NULL)
    {
        printf(RED_TEXT 
                "\nERROR: Arquivo inexistente.\n"
               RESET_TEXT);
        fclose(fptr);
        return 1;
    }
    
    printf(GREEN_TEXT 
            "\nResgatando dados...\n"
            RESET_TEXT);
    fread(&contador, sizeof(counters_data), 1, fptr);
    fclose(fptr);

    show_reports(contador);
    return 0;
}
