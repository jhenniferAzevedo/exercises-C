#include <stdio.h>

int main(void)
{
    char x[10];
    fgets(x, 10, stdin);
    printf("%s", x);

    // freopen redireciona o ponteiro file para o endereço
    // que você informar no último parâmetro.
    freopen("arquivo.txt", "r", stdin);
    
    fgets(x, 100, stdin);
    printf("%s", x);
    return 0;
}
