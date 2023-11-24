/* Ler a idade de 5 grupos de 13 pessoas e mostrar o número de
pessoas com idade abaixo da média de idades do seu grupo. */

#include <stdio.h>
#define QNT_MAX_GRUPOS 5
#define QNT_MAX_PESSOAS 13

int main(void)
{
    int idades[QNT_MAX_GRUPOS][QNT_MAX_PESSOAS];
    int grupo, pessoa, abaixoDaMedia;
    float mediaIdades = 0;

    for (grupo = 0; grupo < QNT_MAX_GRUPOS; grupo++)
    {
        mediaIdades = 0;

        printf("\n\nGRUPO %d\n", grupo + 1);
        for (pessoa = 0; pessoa < QNT_MAX_PESSOAS; pessoa++)
        {
            printf("> idade da pessoa %d: ", pessoa + 1);
            scanf("%d", &idades[grupo][pessoa]);
            mediaIdades += idades[grupo][pessoa];
        }
        mediaIdades /= QNT_MAX_PESSOAS;
        printf("\nmedia: %.2f\n", mediaIdades);

        abaixoDaMedia = 0;
        for (pessoa = 0; pessoa < QNT_MAX_PESSOAS; pessoa++)
        {
            if (idades[grupo][pessoa] < mediaIdades)
            {
                abaixoDaMedia++;
            }
        }
        printf(">>> idades abaixo da media: %d\n", abaixoDaMedia);
    }

    return 0;
}