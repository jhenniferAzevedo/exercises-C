/* Elabore um algoritmo que calcule o preço de um terreno de acordo com as seguintes regras:
    1. Se tiver na região Sul, R$150,00 por m² e se estiver na região Norte, R$ 100,00 por m².
    2. Caso o terreno tenha mais de 400 m², este preço terá 25% de acréscimo. 
    3. Se for um terreno de esquina, acrescenta-se R$ 600,00 no preço. 
*/

#include <stdio.h>

int main(void) 
{
    char resposta;
    int regiao;
    float metros, valor;

    printf("> De qual regiao e o terreno? \n(1) Norte ou (2) Sul: ");
    scanf("%d", &regiao);
    
    printf("\n> Quantos metros tem o terreno? ");
    scanf("%f", &metros);
    
    if(regiao == 1) {
        valor = metros * 100;
    } else valor = metros * 150; 

    if(metros > 400) {
        valor *= 1.25;
    }

    printf("\n> O terreno e de esquina? \n(s) sim ou (n) nao: ");
    scanf(" %c", &resposta);
   
    if(resposta == 's'){
        valor += 600;
    }

    printf("O valor do terreno eh R$%.2f.\n", valor);
    return 0;
}