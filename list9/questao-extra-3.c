/* Reveja o exercídio anterior, "Encomenda de Uniformes" (questao-extra-2.c)
e considere que agora a empresa tem 3 unidades e cada unidade tem um número
indeterminado de setores (no máximo 10 setores). Não pergunte quantos setores
cada unidade tem, estes valores devem ser contados.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QNT_MAX_UN 3
#define QNT_MAX_ST 10
#define MAX_POR_FUNC 2
#define TAM_MAX 10

int main(void)
{
    char cor[QNT_MAX_UN][QNT_MAX_ST][TAM_MAX];
    char tecido[QNT_MAX_UN][QNT_MAX_ST][TAM_MAX];

    int funcionariosUN[QNT_MAX_UN] = {0};
    int funcionariosST[QNT_MAX_UN][QNT_MAX_ST];
    int contSetores[QNT_MAX_UN] = {0};
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
    printf("\nfinalize com -1\n");

    // Leitura dos dados de cada unidade
    for (unidade = 0; unidade < QNT_MAX_UN; unidade++)
    {
        printf("\n\tUNIDADE %d\n", unidade + 1);

        for (setor = 0; setor < 10; setor++)
        {
            printf("\nSETOR %d\n", setor + 1);
            printf("> quantidade de funcionarios: ");
            scanf("%d", &funcionariosST[unidade][setor]);

            if (funcionariosST[unidade][setor] < 0) break;

            contSetores[unidade]++;
            funcionariosUN[unidade] += funcionariosST[unidade][setor];

            printf("> cor da camisa: ");
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

            printf("> tecido da calca: ");
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
    printf("(6) total de setores da unidade\n");
    printf("(7) finaliza as verificacoes de relatorios\n");

    printf("\nQual relatorio voce deseja ver? ");
    scanf("%d", &relatorio);

    while (relatorio != 7)
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
            printf("A unidade %d eh a que possui mais funcionarios, com %d.\n\n", indiceMaiorUN, maiorUN);
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

        // Total de setores da unidade
        case 6:
            printf("De qual unidade? ");
            scanf("%d", &unidade);
            printf("A unidade %d possui %d setores.\n\n", unidade,
                   contSetores[unidade - 1]);
            break;
        }

        printf("Qual relatorio voce deseja ver? ");
        scanf("%d", &relatorio);
    }

    printf("finalizando...\n\n");
    system("pause");
    return 0;
}