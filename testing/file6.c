#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    FILE *file;
    // a significa append, que, diferente do w, concatena as informações
    // ao invés de sobreescrever o texto já existente.
    file = fopen("string.txt", "a");

    if (file == NULL) 
    {
        printf("Arquivo nao pode ser aberto. \n");
        getchar();
        exit(1);
    }

    char frase[] = "Segunda linha \n";
    char caractere = '3';

    fprintf(file, "Primeira linha. \n");
    fputs(frase, file);
    fputc(caractere, file);

    fclose(file);
    getchar();
    return 0;
}
