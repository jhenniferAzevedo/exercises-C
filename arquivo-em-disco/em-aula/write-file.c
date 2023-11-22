#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    FILE *file;
    file = fopen("test-array.out", "wb");

    if(file == NULL)
    {
        printf("Arquivo nao encontrado. \n");
        return 1;
    }

    int array[10][4];
    srand(time(NULL));

    printf("Preenchendo e mostrando a matriz...\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            array[i][j] = rand() % 10;
            printf("%d", array[i][j]);

            if (j < 3)
                printf(", ");
            else
                printf(". \n");
        }
    }

    fwrite(array, sizeof(int), 10 * 4, file);
    fclose(file);
    return 0;
}
