#include <stdio.h>
// #include "header.h"

void test(int *);
typedef struct name
{
    int code;
    int color;
    int amount;
} register_data;


int main(void) {
    register_data car[10];

    printf("\n\tDigite um valor: ");
    scanf("%d", &car[0].color);
    test(&car[0].color);
    printf("\tEncerrando...\n\n");

    return 0;
}

void test(int *value_color) {
    while (*value_color < 1 || *value_color > 4) {
        printf("\n\tEsse valor e invalido! \n"
               "\tPor favor, digite um numero valido. \n\n"
               "\tCodigo da cor do veiculo: ");
        scanf("%d", value_color);
    }
    return;
}
