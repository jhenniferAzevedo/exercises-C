#include <stdio.h>

int main(void) 
{
    FILE *file;
    // r significa read, então o utilizamos para ler os dados de algum arquivo de texto.
    file = fopen("inteiros.txt", "r");

    int x, y, z;

    // fscanf precisa de três parâmetros: nome do arquivo, 
    fscanf(file, "%d %d %d", &x, &y, &z);
    printf("%d %d %d\n", x, y, z);

    fclose(file);
    getchar();
    return 0;
}
