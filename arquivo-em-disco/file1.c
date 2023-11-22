#include <stdio.h>
#include <string.h>

typedef struct name
{
    char nome[100];
    int quantidade;
    float valor;
} primeiro;

void function1(primeiro *this)
{
    strcpy(this->nome, "Bolacha");
    this->quantidade = 10;
    this->valor = 24.9;
}

void printf_product(primeiro this)
{
    printf("\n> Produto: %s."
           "\n> Quantidade: %d."
           "\n> Valor: %.2f \n", 
           this.nome, this.quantidade, this.valor);
}

int main(void) {
    primeiro produto;
    function1(&produto);
    printf_product(produto);
    return 0;
}
