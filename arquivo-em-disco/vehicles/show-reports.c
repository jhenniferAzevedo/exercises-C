#include <stdio.h>
#include "header.h"

int main()
{
    register_data cadastros[25];
    counter_data contador = {0};

    FILE *fptr = fopen("file-on-disk.out", "rb");

    if (fptr == NULL)
    {
        printf(RED_TEXT 
                "\nERROR: Arquivo inexistente.\n"
               RESET_TEXT);
        return 1;
    }
    
    printf(GREEN_TEXT 
            "\nResgatando dados...\n"
            RESET_TEXT);
    fread(cadastros, sizeof(register_data), 25, fptr);
    fread(&contador, sizeof(counter_data), 1, fptr);
    fclose(fptr);

    int registros = contador.total_registers, 
        veiculos = contador.total_vehicles;
    show_reports(cadastros, &contador);

    if (registros != contador.total_registers ||
            veiculos != contador.total_vehicles)
    {
        fptr = fopen("file-on-disk.out", "wb");
        fwrite(cadastros, sizeof(register_data), 25, fptr);
        fwrite(&contador, sizeof(counter_data), 1, fptr);
        printf(GREEN_TEXT 
            "Arquivo salvo com sucesso!\n\n"
            RESET_TEXT);
        fclose(fptr);
    }
    
    return 0;
}