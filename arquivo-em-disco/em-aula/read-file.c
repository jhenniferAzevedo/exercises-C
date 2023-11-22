#include <stdio.h>

int main(void)
{
    FILE *file;
    file = fopen("test-array.out", "rb");

    if(file == NULL)
    {
        printf("Arquivo nao encontrado. \n");
        return 1;
    }

    int array[10][4];
    printf("Lendo e mostrando a matriz do arquivo...\n");
    fread(array, sizeof(int), 10 * 4, file);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d", array[i][j]);
            if(j < 3)
                printf(", ");
            else
                printf(". \n");
        }
    }

    fclose(file);
    return 0;
}
