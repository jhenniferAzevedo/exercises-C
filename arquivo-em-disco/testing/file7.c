#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    void copiarConteudo(FILE * test1, FILE *test2);
    FILE *test1 = fopen("/home/jhennifer/Documentos/Repositories/exercises-C/arquivo-em-disco/testing/test1.txt", "r");

    if (test1 == NULL) 
    {
        printf("Nao foi possivel abrir o arquivo. \n");
        return 1;
    }

    // caso o endereço do arquivo seja diferente do que estamos
    // executando esse código, podemos fazer assim para acessá-lo.
    FILE *test2 = fopen("/home/jhennifer/Documentos/Repositories/exercises-C/testing/test2.txt", "w");

    copiarConteudo(test1, test2);

    fclose(test1);
    fclose(test2);

    getchar();
    return 0;
}

void copiarConteudo(FILE *test1, FILE *test2)
{
    char leitor[1000];
    while(fgets(leitor, 1000, test1) != NULL)
    {
        fputs(leitor, test2);
    }
}
