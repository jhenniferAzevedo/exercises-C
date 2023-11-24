/* Elabore um algoritmo que informe a classe eleitoral de uma pessoa a partir de sua idade. 
   Repita, quantas vezes o usuário quiser. 
   
   * Não eleitor (abaixo de 16 anos)
   * Eleitor obrigatório (de 18 a menor de 65 anos)
   * Eleitor facultativo (de 16 a menor de 18 anos e de 65 anos ou mais) 
*/

#include <stdio.h>

int main(void)
{
    char op;
    int idade;
    
    do
    {
        printf("\n\tDigite sua idade: ");
        scanf("%d", &idade);

        if (idade<16)
        {
            printf("\t>>> nao eleitor.");
        }
        else
        {
            if (idade<18 || idade>=65)
            {
                printf("\t>>> eleitor facultativo.");
            }
            else
            {
                printf("\t>>> eleitor obrigatorio.");
            }
        }
        printf("\n\n\tdeseja continuar? \n\t(s) ou (n): ");
        scanf(" %c", &op);
    } while (op != 'n');
    
    printf("fim.\n");
    return 0;
}