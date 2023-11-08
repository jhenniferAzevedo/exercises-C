#define MAX_PERGUNTAS 2
#define MAX_DIAS 5
#define MAX_CLIENTES 20

/* Novo tipo para armazenar os dados dos relatórios. */
typedef struct form_data
{
    int qnts_encontraram,
        qnts_satisfeitos,
        total_clientes,
        ambas_respostas_nao;
    float porcent_sims,
          porcent_naos,
          percent_clientes_satisfeitos_5_dia;
} form_data;


/* Lê os dados do dia especificado. */
void ler_dados_diarios(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms);

/* Lê as respostas de cada usuario e armazena elas, enquanto conta a quantidade de pessoas. */
void ler_dados_cliente(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms, int n_dia);

/* Pergunta se o usuário encontrou o que procurava. */
void ask_question1(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], int n_cliente, int n_dia);

/* Pergunta se o usuário está satisfeito. */
void ask_question2(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], int n_cliente, int n_dia);

/* Pergunta se ainda há usuários. Se não houver, encerra o dia de pesquisa. */
void ask_if_there_are_any_users;

/* Chama todas as funções que calculam os dados. */
void calcular_dados(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms);

/* Pergunta se o usuário encontrou o que procurava. */
void cont_qnts_encontraram(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms);

/* Conta quantos usuários estão satisfeitos. */
void cont_qnts_satisfeitos(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms);

/* Conta quantos usuários responderam não para ambas as perguntas da pesquisa. */
void cont_ambas_respostas_nao(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms);

/* Calcula a porcentagem de respostas positivas e negativas de todo o período de pesquisa. */
void calcula_porcent(form_data forms);

/* Conta quantos usuários ficaram encontraram o que procuravam no quinto dia da pesquisa. */
void cont_encontraram_no_dia_5(int resp_usuario[][MAX_DIAS][MAX_CLIENTES], form_data forms);

/*  */
void mostrar_menu(void);
