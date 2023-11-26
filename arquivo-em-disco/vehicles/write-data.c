#include <stdio.h>
#include "header.h"

/* Apenas mostra todos os dados que estão guardados no file-on-disk.out */

int main(void)
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

    for (int i = 0; i < contador.total_registers; i++)
    {
        printf("\n> Registro: %d \n"
               "> Código: %d \n"
               "> Cor: %d \n"
               "> Quantidade: %d \n", 
               i, cadastros[i].code, 
               cadastros[i].color, 
               cadastros[i].amount);
    }
    printf("\n>>> Total de Cadastros: %d"
           "\n>>> Total de Veiculos: %d \n\n", 
           contador.total_registers, contador.total_vehicles);

    return 0;
}