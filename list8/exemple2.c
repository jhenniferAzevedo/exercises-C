/* Elabore um algoritmo que gere as senha de uma fila. Para cada pessoa que chega,
devem ser impressos seu nome e o número da senha. Quando o nome for “fim”, encerra-
-se o programa. O número máximo de atendimentos deve ser 50. (exemplo em sala) */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome[30];
    int senha;

    printf("Digite seu nome: ");
    scanf("%s", nome);

    for (senha = 1; strcmp(nome, "fim") && senha <= 50; senha++)
    {
        printf("\nNome: %s.\nSenha: %d.\n", nome, senha);
        printf("\nDigite seu nome: ");
        scanf("%s", nome);
    }
    return 0;
}