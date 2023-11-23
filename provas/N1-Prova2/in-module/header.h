#define MAX_SEMANAS 15
#define MAX_PRODUTORES 50

typedef struct counters_data
{
    int producers,
        weeks_without_delivery,
        total_delivery,
        total_vegetables[2],
        vegetables_per_week[2][MAX_SEMANAS],
        vegetables_per_producer[2][MAX_PRODUTORES],
        deliveries[2][MAX_SEMANAS][MAX_PRODUTORES];
} counters_data;


/* Lê todos os dados das vendas da cooperativa de distribuição de hortaliças. */
void read_data(counters_data *counter);

/* Pergunta pra cooperativa quantos produtores eles possuem. */
void ask_how_many_producers(counters_data *counter);

