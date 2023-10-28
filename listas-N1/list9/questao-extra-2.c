/*  Encomenda de Uniformes
Uma empresa fará encomenda de uniformes para seus funcionários em suas 2 unidades.
Cada funcionário receberá 2 calças e 2 blusas de uniforme. A unidade 1 possui 2 setores
e a unidade 2 possui 5 setores. Cada setor escolhe a cor da camiseta (branca, preta ou azul)
e o tecido da calça (tactel ou moletom).

Escreva um algoritmo que receba como entrada o número de funcionários de cada setor e as
características do seu uniforme (cor da camiseta e tecido da calça).

Após as leituras, o algoritmo deve emitir um destes relatórios, de acordo com a escolha do
usuário:

   a. Total de funcionários da unidade (dado o número da unidade, 1 ou 2, mostre o total de
   funcionários da unidade)
   b. Total de funcionários do setor (dado o número da unidade e do setor, mostre o total de
   funcionários deste setor)
   c. Uniforme do setor (dado o número da unidade e do setor, mostre as características do
   uniforme deste setor)
   d. Maior unidade (mostra a unidade que tem mais funcionários)
   e. Total de encomendas (mostre as quantidades de peças que serão encomendadas: quantidade
   de camisetas brancas,
   de camisetas pretas, de camisetas azuis, de calças de tactel e de calças de moletom).

Após a emissão de cada relatório, o programa deve perguntar se o usuário deseja emitir outro
relatório ou se deseja finalizar o programa. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT_MAX_UN 2
#define QNT_MAX_ST 5
#define MAX_POR_FUNC 2
#define TAM_MAX 10

int main(void)
{
    char cor[QNT_MAX_UN][QNT_MAX_ST][TAM_MAX];
    char tecido[QNT_MAX_UN][QNT_MAX_ST][TAM_MAX];

    int funcionariosUN[QNT_MAX_UN] = {0};
    int funcionariosST[QNT_MAX_UN][QNT_MAX_ST];
    int corCamisa[QNT_MAX_UN][QNT_MAX_ST];
    int tecidoCalca[QNT_MAX_UN][QNT_MAX_ST];

    int unidade, setor, relatorio;
    int camisaB = 0, camisaP = 0, camisaA = 0, calcaM = 0, calcaT = 0;
    int maiorUN = 0, indiceMaiorUN;

    // Amostra das opções de uniforme
    printf("\nOpcoes de camisa:\n");
    printf("(1) branca \n(2) preta \n(3) azul");
    printf("\n\nOpcoes de calca:\n");
    printf("(1) moletom \n(2) tectel\n");

    // Leitura dos dados de cada unidade
    for (unidade = 0; unidade < QNT_MAX_UN; unidade++)
    {
        printf("\n* UNIDADE %d *\n", unidade + 1);
        for (setor = 0; setor < QNT_MAX_ST; setor++)
        {
            printf("\n\tSETOR %d\n", setor + 1);
            printf("> quantidade de funcionarios: ");
            scanf("%d", &funcionariosST[unidade][setor]);

            funcionariosUN[unidade] += funcionariosST[unidade][setor];

            printf("\t> cor da camisa: ");
            scanf("%d", &corCamisa[unidade][setor]);

            switch (corCamisa[unidade][setor])
            {
            case 1:
                strcpy(cor[unidade][setor], "branca");
                camisaB += funcionariosST[unidade][setor] * MAX_POR_FUNC;
                break;
            case 2:
                strcpy(cor[unidade][setor], "preta");
                camisaP += funcionariosST[unidade][setor] * MAX_POR_FUNC;
                break;
            case 3:
                strcpy(cor[unidade][setor], "azul");
                camisaA += funcionariosST[unidade][setor] * MAX_POR_FUNC;
                break;
            }

            printf("\t> tecido da calca: ");
            scanf("%d", &tecidoCalca[unidade][setor]);

            switch (tecidoCalca[unidade][setor])
            {
            case 1:
                strcpy(tecido[unidade][setor], "moletom");
                calcaM += funcionariosST[unidade][setor] * MAX_POR_FUNC;
                break;
            case 2:
                strcpy(tecido[unidade][setor], "tectel");
                calcaT += funcionariosST[unidade][setor] * MAX_POR_FUNC;
                break;
            }

            if (unidade == 0 && setor == 1)
            {
                break;
            }
        }

        if (funcionariosUN[unidade] > maiorUN)
        {
            maiorUN = funcionariosUN[unidade];
            indiceMaiorUN = unidade + 1;
        }
    }
    system("cls");

    // Relatórios
    printf("\n\tOPCOES DE RELATORIO\n");
    printf("(1) total de funcionarios da unidade\n");
    printf("(2) total de funcionarios do setor\n");
    printf("(3) caracteristicas do uniforme do setor\n");
    printf("(4) unidade com mais funcionarios\n");
    printf("(5) total de encomendas da empresa\n");
    printf("(6) finaliza as verificacoes de relatorios\n");

    printf("\nQual relatorio voce deseja ver? ");
    scanf("%d", &relatorio);

    while (relatorio != 6)
    {
        switch (relatorio)
        {
        // Total de funcionários da Unidade
        case 1:
            printf("De qual unidade? ");
            scanf("%d", &unidade);
            printf("A unidade %d possui %d funcionarios.\n\n", unidade,
                   funcionariosUN[unidade - 1]);
            break;

        // Total de funcionários do Setor
        case 2:
            printf("De qual unidade? ");
            scanf("%d", &unidade);
            printf("E qual setor? ");
            scanf("%d", &setor);
            printf("O setor %d possui %d funcionarios.\n\n", setor,
                   funcionariosST[unidade - 1][setor - 1]);
            break;

        // Características do uniforme do Setor
        case 3:
            printf("De qual unidade? ");
            scanf("%d", &unidade);
            printf("E qual setor? ");
            scanf("%d", &setor);
            printf("O setor %d utiliza a camisa %s e a calca %s.\n\n", setor,
                   cor[unidade - 1][setor - 1], tecido[unidade - 1][setor - 1]);
            break;

        // Unidade com mais funcionários
        case 4:
            printf("A unidade %d eh a que possui mais funcionarios, com a quantidade "
                   "de %d.\n\n", indiceMaiorUN, maiorUN);
            break;

        // Total de encomendas da empresa
        case 5:
            printf("\nQuantidade de camisas da cor branca: %d\n", camisaB);
            printf("Quantidade de camisas da cor preta: %d\n", camisaP);
            printf("Quantidade de camisas das cor azul: %d\n", camisaA);

            printf("Quantidade de calcas do tecido moletom: %d\n", calcaM);
            printf("Quantidade de calcas do tecido tectel: %d\n", calcaT);

            printf("Total de encomendas: %d\n\n",
                   camisaB + camisaP + camisaA + calcaM + calcaT);
            break;
        
        case 6: break;
        default:
            printf("\nvalor invalido! digite um numero valido.");
        }

        printf("\nQual relatorio voce deseja ver? ");
        scanf("%d", &relatorio);
    }

    printf("fim.\n\n");
    system("pause");
    return 0;
}