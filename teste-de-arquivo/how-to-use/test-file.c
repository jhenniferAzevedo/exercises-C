#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *arq = fopen(argv[1], "r");
    int x, y;
    int k = fscanf(arq, "%d %d", &x, &y);

    x += 3;
    y += 3;

    printf("%d %d", x, y);
    fclose(arq);
    return 0;
}
