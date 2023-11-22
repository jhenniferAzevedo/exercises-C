#include <stdio.h>

int main(void) 
{
    FILE *file;
    file = fopen("inexistente.txt", "r");

    if (file == NULL) 
    {
        printf("Arquivo nao pode ser aberto. \n");
        getchar();
        return 1;
    }

    int x, y, z;

    // fscanf precisa de três parâmetros: nome do arquivo, 
    fscanf(file, "%d %d %d", &x, &y, &z);
    printf("%d %d %d\n", x, y, z);

    fclose(file);
    getchar();
    return 0;
}
