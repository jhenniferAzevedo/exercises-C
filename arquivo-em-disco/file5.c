#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    FILE *file;
    file = fopen("string.txt", "r");

    if (file == NULL) 
    {
        printf("Nao foi possivel abrir o arquivo. \n");
        getchar();
        exit(1);
    }

    char frase[100];
    
    // fscanf precisa que o arquivo esteja perfeitamente formatado.
    // ffgets lê os valores do arquivo como uma string,
    while(fgets(frase, 100, file) != NULL)
    {
        printf("%s", frase);
    }

    fclose(file);
    getchar();
    return 0;
}
