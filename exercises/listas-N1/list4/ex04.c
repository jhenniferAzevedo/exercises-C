/* Faça um algoritmo que receba dois números e execute uma das operações listadas a seguir de 
acordo com a escolha do usuário. Considere que pode haver erro de entrada no código da operação.
    1. Soma dos números;
    2. Subtração do maior pelo menor;
    3. Divisão do primeiro pelo segundo. */

#include <stdio.h>

int main(void)
{
    int escolha_do_usuario;
    float num1, num2, adc, sub, div;

    printf("\nDigite o dois numeros separados por espaco: ");
    scanf("%f%f", &num1, &num2);

    printf("\nPOSSIVEIS OPERACOES\n");
    printf("(1) realizar a soma dos numeros\n");
    printf("(2) realizar a divisao do primeiro pelo segundo\n");
    printf("(3) realizar a subtracao do maior pelo menor\n");
    
    printf("\nQue operacao voce deseja realizar? ");
    scanf("%d", &escolha_do_usuario);

    
    switch (escolha_do_usuario)
    {
    case 1:
        adc = num1 + num2;
        printf("%.1f + %.1f = %.1f\n", num1, num2, adc);
        break;
    
    case 2:
        if (num2 > 0)
        {
            div = num1 / num2;
            printf("%.1f / %.1f = %.1f\n", num1, num2, div);
        }
        else
        {
            printf("\nNao e possivel dividir por 0!!\n");
        }
        break;
    
    case 3:
        if (num1 > num2)
        {
            sub = num1 - num2;
            printf("%.1f - %.1f = %.1f\n", num1, num2, sub);
        }
        else
        {
            sub = num2 - num1;
            printf("%.1f - %.1f = %.1f\n", num2, num1, sub);
        }
        break;
    
    default:
        printf("\nNumero invalido!\n");
        break;
    }
    return 0;
}