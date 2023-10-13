/* Escreva no monitor a tabuada de multiplicação de um número fornecido pelo usuário */

#include <stdio.h>

int main(void)
{
    int num, cont;

    printf("Escolha um numero para ver a tabuada: ");
    scanf("%d", &num);
		
	printf("\tTabuada do %d\n", num);
    for (cont = 0; cont <= 10; cont++)
    {
        printf("\t> %d x %d = %d\n", num, cont, num * cont);
    }

    return 0;
}