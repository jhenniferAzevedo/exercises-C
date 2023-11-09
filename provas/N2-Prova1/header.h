/* Inicializa qualquer vetor inteiro de acordo com a quantidade de elementos que ele possui. */
void init_array(int array[], int size);

/* Lê todos os dados dos cadastros registrados. */
void read_data(int registration[][3], int counters_max[], int *total_registrations);

/* Pergunta pro usuário qual é o código do veículo. */
void ask_vehicle_code(int registration[][3], int n_register);

/* Pergunta pro usuário qual é o código da cor. */
void ask_color_code(int registration[][3], int n_register);

/* Verifica se o código da cor digitado pelo usuário é válido. */
void check_color_code(int registration[][3], int n_register);

/* Pergunta pro usuário qual é o código da cor. */
int ask_how_many_vehicle(int registration[][3], int counters_max[], int n_register);

/* Conta a quantidade total de carros que ha na garagem. */
void count_total_vehicle(int registration[][3], int counters_max[], int n_register);

/* Faz todo o tratamento de erro para que o usuário não estoure o valor máximo de veículos permitido. */
int error_handling_of_max_amount(int registration[][3], int counter[], int n_register);

/* Retorna um valor de acordo com a quatidade de carros que há na garagem: 
 * Retorna 0, se o valor digitado ainda estiver abaixo do máximo permitido;
 * Retorna 1, se o valor digitado for igual ao máximo permitido;
 * Retorna 2, se o valor digitado ultrapassar o valor máximo permitido.
 */
int check_status_garage(int counters_max[]);

/* Mostra uma mensagem de acordo com o status da garagem.
 * Status 0, pergunta se ainda ha veiculos;
 * Status 1, mostra mensagem de encerramento;
 * Status 3, pede para o usuario trocar o valor digitado, caso ultrapasse o máximo permitido;
 */
int show_message_by_status_garage(int registration[][3], int counters_max[], int n_register, int status);

/*  */

/* Conta a quantidade de carros do codigo especificado que ha na garagem. */
void count_vehicle_by_color(int registration[][3], int counters_max[], int n_register);

/* Conta a quantidade de carros da cor especificada que ha na garagem. */
void count_vehicle_by_code(int registration[][3], int counters_max[], int n_register);













int gerar_codigo();

void verifica_max_garagem(int total_na_garagem, int cadastro[], int *resposta_usuario);

void verifica_veiculos_iguais(int cadastro[][3], int *veiculo_novo);

float calcula_percent_ocupacao(int cadastro[][3]);

void inserir_um_novo_veiculo(int cadastro[][3], int *total_cadastros);

int calcula_total_por_cor(int cadastro[][3], int total_cadastros);

void mostra_cadastros_por_cor(int cadastro[][3], int total_cadastros);

int calcula_total_por_codigo(int cadastro[][3], int total_cadastros);

void mostra_cadastros_por_codigo(int cadastro[][3], int total_cadastros);

int consultar_quantidade_cadastro(int cadastro[][3], int total_cadastros, int codigo_veiculo, int cor_veiculo);








