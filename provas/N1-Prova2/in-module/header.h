#define MAX_WEEK 15
#define MAX_PRODUC 50

typedef struct counters_data
{
    int producers, lettuce, cabbage, total,
        deliveries[2][MAX_WEEK][MAX_PRODUC];
} counters_data;

// LEITURA DOS DADOS
void read_data(counters_data *counter);
void ask_how_many_producers(counters_data *counter);
void check_how_many_producers(counters_data *counter);
void read_data_by_week(counters_data *counter);
void read_data_by_producer(counters_data *counter, int n_week);
void ask_how_many_lettuce(counters_data *counter, int n_week, int n_producer);
void ask_how_many_cabbage(counters_data *counter, int n_week, int n_producer);

// RELATÓRIOS
int menu_report();
void check_answer(int *answer);

// RELATÓRIO POR SEMANA
void report_per_week(counters_data counter);
int ask_which_week();
void check_weeks(int *n_week);
void count_vegetables_per_week(counters_data *counter, int n_week);

// RELATÓRIO POR PRODUTOR
void report_per_producer(counters_data counter);
int ask_which_producer(counters_data counter);
void check_producer(counters_data counter, int *n_producer);
void count_vegetables_per_producer(counters_data *counter, int n_producer);

// RELATÓRIO DA ANÁLIDE DE ABASTECIMENTO
void report_per_supply_analysis(counters_data counter);
void count_total_vegetables(counters_data *counter);
void show_total_vegetables(counters_data counter);
void show_message_by_suply(counters_data counter);
void count_total_deliveries(counters_data *counter);
void show_message_by_weeks_without_delivery(counters_data counter);
int count_weeks_without_delivery(counters_data counter);
