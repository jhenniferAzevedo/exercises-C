/* Inicializa qualquer vetor inteiro de acordo com a quantidade de elementos que ele possui. */
void init_array(int array[], int size);


// LEITURAS

/* Lê todos os dados dos cadastros registrados. */
void read_data(int registration[][4], int counter[]);

/* Pergunta pro usuário qual é o código do veículo. */
void ask_vehicle_code(int registration[][4], int code_register);

/* Pergunta pro usuário qual é o código da cor. */
void ask_color_code(int registration[][4], int code_register);

/* Mostra o menu de códigos das cores disponíveis. */
void menu_colors(void);

/* Verifica se o código da cor digitado pelo usuário é válido. */
void check_color_code(int registration[][4], int code_register);

/* Pergunta pro usuário qual é o código da cor. */
int ask_how_many_vehicle(int registration[][4], int counter[], int *n_register);

// RELATORIO GERAL

/* Adiciona o valor dititado pelo usuário para a quantidade total de carros que ha na garagem. */
void count_total_vehicle(int registration[][4], int counter[], int *n_register);

/* Faz todo o tratamento de erro para que o usuário não estoure o valor máximo de veículos permitido. */
int error_handling_of_max_amount(int registration[][4], int counte[], int *n_register);

/* Retorna um valor de acordo com a quatidade de carros que há na garagem: 
 * Retorna 0, se o valor digitado ainda estiver abaixo do máximo permitido;
 * Retorna 1, se o valor digitado for igual ao máximo permitido;
 * Retorna 2, se o valor digitado ultrapassar o valor máximo permitido.
 */
int check_status_garage(int counter[]);

/* Mostra uma mensagem de acordo com o status da garagem.
 * Status 0, pergunta se ainda ha veiculos;
 * Status 1, mostra mensagem de encerramento;
 * Status 3, pede para o usuario trocar o valor digitado, caso ultrapasse o máximo permitido;
 */
int show_message_by_status_garage(int registration[][4], int counter[], int *n_register, int status);

/* Verifica se já existe algum cadastro com o mesmo código de veículo e da cor. 
 * Se houver, adiciona o valor digitado ao cadastro existente.
 */
void check_existing_registrations(int registration[][4], int counter[], int *n_register);

/* Adiciona a quantidade de veículos digitada pelo usuário ao cadastro já existente. */
void add_to_existing_registration(int registration[][4], int *new_register, int old_register);

/* Mostra para o usuário o relatório geral. 
 * (todos os veiculos, quantidade total na garagem e percentagem de ocupação) */
void show_general_report(int registration[][4], int counter[]);

/* Mostra todos os cadastros de todos os veículos. */
void show_all_vehicles(int registration[][4], int counter[]);

/* Retorna o valor da porcentagem de ocupação da garagem. */
float calculate_garage_percentage(int counter[]);


// RELATÓRIO POR COR

/* Mostra para o usuário o relátorio por cor dos veículos. */
void show_report_by_color(int registration[][4], int counter[]);

/* Mostra todos os veículos que possuem a cor especificada. */
void show_vehicles_by_color(int registration[][4], int counter[], int n_color);

/* Conta a quantidade de carros da cor especificada que ha na garagem. */
void count_vehicles_by_color(int registration[][4], int counter[], int n_color);


// RELATÓRIO POR CÓDIGO

/* Mostra todos os veículos que possuem o código especificado. */
void show_vehicles_by_code(int registration[][4], int counter[]);




/* Conta a quantidade de carros do codigo especificado que ha na garagem. */
void count_vehicles_by_code(int registration[][4], int counters_max[], int code_register);


/* Mostra o menu nos relatórios. */
void menu_report(void);








void inserir_um_novo_veiculo(int cadastro[][3], int *total_cadastros);

int calcula_total_por_cor(int cadastro[][3], int total_cadastros);

void mostra_cadastros_por_cor(int cadastro[][3], int total_cadastros);

int calcula_total_por_codigo(int cadastro[][3], int total_cadastros);

void mostra_cadastros_por_codigo(int cadastro[][3], int total_cadastros);

int consultar_quantidade_cadastro(int cadastro[][3], int total_cadastros, int codigo_veiculo, int cor_veiculo);








