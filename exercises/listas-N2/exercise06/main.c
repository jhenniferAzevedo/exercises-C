#include <stdio.h>
#include "header.h"

int main(void) 
{
	double valor;
	printf("\nDigite um valor: ");
	scanf("%lf", &valor);
	
	printf("O valor absoluto e %.2f.\n\n", valor_absoluto(valor));
	return 0;
}