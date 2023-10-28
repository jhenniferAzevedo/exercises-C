/* Escreva no monitor a tabuada de multiplicação de um número fornecido pelo usuário */

#include <stdio.h>

int main(void)
{
    int num, cont = 0;

    printf("Escolha um numero para ver a tabuada: ");
    scanf("%d", &num);
		
	printf("\tTabuada do %d\n", num);
    while(cont <= 10)
    {
        printf("\t> %d x %d = %d\n", num, cont, num * cont);
        cont++;
    }

    return 0;
}