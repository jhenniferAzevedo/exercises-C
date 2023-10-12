/* Considere um escritório de arquitetura. 
O preço cobrado por um projeto arquitetônico básico é de R$ 20,00 por m².

    * Se o cliente quiser acrescentar os projetos complementares, 
      o preço será de R$ 30,00 por m². 
    * O cliente pode ainda acrescentar o projeto de decoração e/ou
      o projeto estrutural. Pelo projeto de decoração é cobrado R$100,00
      por cômodo e pelo projeto estrutural é cobrado R$ 1200,00. 
    * Se o cadastro do cliente tiver sido feito pela internet, o valor total
      receberá um desconto de 5%. 

Elabore um algoritmo que mostre o valor a ser pago. */

#include<stdio.h>

int main(void)
{
	char resposta;
    int comodos;
    float metros, projeto_final;

    printf("CALCULAR VALOR DO PROJETO ARQUITETONICO\n");
    printf("> Digite o tamanho do projeto em metros quadrados: ");
    scanf("%f", &metros);
    
    projeto_final = metros * 20;
    
    printf("\nA partir de agora, digite (s) para sim e (n) para nao.\n");
    printf("\n> Deseja acrescentar projetos complementares? ");
    scanf(" %c", &resposta);
    
    if(resposta == 's')
    {
        printf("> Em quantos metros quadrados voce deseja acrescentar? ");
        scanf("%f", &metros);
        projeto_final += metros * 30;
    }
    
    printf("\n> Deseja acrescentar algum projeto de decoracao? ");
    scanf(" %c", &resposta);
    
    if(resposta == 's')
    {
        printf("> Em quantos comodos deseja acrescentar? ");
        scanf("%d", &comodos);
        projeto_final += comodos * 100;
    }
    
    printf("\n> Deseja acrescentar algum projeto estrutural? ");
    scanf(" %c", &resposta);
    
    if(resposta == 's')
    {
        printf("> Em quantos comodos deseja acrescentar? ");
        scanf("%d", &comodos);
        projeto_final += comodos * 1200;
    }
    
    printf("\n> De que forma voce realizou seu cadastro?\n");
    printf("(1) online ou (2) presencial: ");
    scanf(" %c", &resposta);
    
    if(resposta == '1')
    {
        projeto_final *= 0.95;
    }
    
    printf("\n\nO valor do projeto de arquitetura sera de R$%.2f.\n", projeto_final);
    return 0;
}