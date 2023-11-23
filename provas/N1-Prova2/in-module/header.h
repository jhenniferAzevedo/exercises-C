#define MAX_WEEK 15
#define MAX_PRODUC 50

typedef struct counters_data
{
    int producers, lettuce, cabbage, total,
        deliveries[2][MAX_WEEK][MAX_PRODUC];
} counters_data;


/* Lê todos os dados das vendas da cooperativa de distribuição de hortaliças. */
void read_data(counters_data *counter);

/* Pergunta pra cooperativa quantos produtores eles possuem. */
void ask_how_many_producers(counters_data *counter);

/*
    ,
*/