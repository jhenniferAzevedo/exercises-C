#include <stdio.h>

int main(void) 
{
    FILE *file;

    // fopen recebe dois argumentos: nome do arqulivo e uma string.
    // w significa write, então o utilizamos para adicionar algum texto ao arquivo.
    file = fopen("arquivo.txt", "w");

    // fprintf recebe dois argumentos: o ponteiro do arquivo e uma string.
    fprintf(file, "Good morning!");

    // fclose é como fechar e slavar o arquivo.
    fclose(file);

    getchar();
    return 0;
}
