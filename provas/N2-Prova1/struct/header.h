/* #define MAX_VEHICLES 150 */
/* #define MAX_REGISTERS 25 */

/* Novo tipo para armazenar os dados de cada cadastro. */
typedef struct register_data
{
    int code, color, amount;
} register_data;

/* Novo tipo para armazenar os dados contados durante o programa. */
typedef struct counter_data
{
    int total_registers,
        total_vehicles,
        vehicles_by_code,
        vehicles_by_color,
        vehicles_by_code_and_color;
} counter_data;


/* Inicializa qualquer vetor inteiro de acordo com a quantidade de elementos que ele possui. */
void init_array(counter_data array, int size);


// LEITURAS

/* Lê todos os dados dos cadastros registrados. */
void read_data(register_data registration[], counter_data counter);

/* Pergunta pro usuário qual é o código do veículo. */
void ask_vehicle_code(register_data registration[], int n_register);

/* Mostra o menu de códigos das cores disponíveis. */
void menu_colors(void);

/* Pergunta pro usuário qual é o código da cor. */
void ask_color_code(register_data registration[], int n_register);

/* Verifica se o código da cor especificada é válido. Se não, pede para trocá-lo*/
void check_color_code(int *value_color);

/* Pergunta pro usuário qual é o código da cor. */
int ask_how_many_vehicle(register_data registration[], counter_data counter, int *n_register);

/* Adiciona o valor dititado pelo usuário para a quantidade total de carros que ha na garagem. */
void count_total_vehicle(register_data registration[], counter_data counter, int *n_register);

/* Faz todo o tratamento de erro para que o usuário não estoure o valor máximo de veículos permitido. */
int error_handling_of_max_amount(register_data registration[], counter_data counter, int *n_register);

/* Retorna um valor de acordo com a quatidade de carros que há na garagem: 
 * Retorna 0, se o valor digitado ainda estiver abaixo do máximo permitido;
 * Retorna 1, se o valor digitado for igual ao máximo permitido;
 * Retorna 2, se o valor digitado ultrapassar o valor máximo permitido.
 */
int check_status_garage(counter_data counter);

/* Mostra uma mensagem de acordo com o status da garagem.
 * Status 0, pergunta se ainda ha veiculos;
 * Status 1, mostra mensagem de encerramento;
 * Status 3, pede para o usuario trocar o valor digitado, caso ultrapasse o máximo permitido;
 */
int show_message_by_status_garage(register_data registration[], counter_data counter, int *n_register, int status);

/* Verifica se já existe algum cadastro com o mesmo código de veículo e da cor. 
 * Se houver, adiciona o valor digitado ao cadastro existente.
 */
void check_existing_registrations(register_data registration[], counter_data counter, int *n_register);

/* Adiciona a quantidade de veículos digitada pelo usuário ao cadastro já existente. */
void add_to_existing_registration(register_data registration[], int *new_register, int old_register);


// RELATÓRIOS

/* Mostra o menu nos relatórios. */
void menu_report(void);

/* Mostra o cadatro e suas informações de acordo com o número do cadastro (i). */
void menu_register(register_data registration[], int i);


// 1. RELATORIO GERAL

/* Mostra para o usuário o relatório geral. 
 * (todos os veiculos, quantidade total na garagem e percentagem de ocupação) */
void show_general_report(register_data registration[], counter_data counter);

/* Mostra todos os cadastros de todos os veículos. */
void show_all_vehicles(register_data registration[], counter_data counter);

/* Retorna o valor da porcentagem de ocupação da garagem. */
float calculate_garage_percentage(counter_data counter);


// 2. RELATÓRIO POR COR

/* Mostra para o usuário um relátorio, dado a cor dos veículos. */
void show_report_by_color(register_data registration[], counter_data counter);

/* Mostra todos os veículos que possuem a cor especificada. */
void show_vehicles_by_color(register_data registration[], counter_data counter, int n_color);

/* Conta a quantidade de veículos da cor especificada que ha na garagem. */
void count_vehicles_by_color(register_data registration[], counter_data counter, int n_color);


// 3. RELATÓRIO POR CÓDIGO

/* Mostra para o usuário um relátorio, dado o código dos veículos. */
void show_report_by_code(register_data registration[], counter_data counter);

/* Mostra todos os veículos que possuem o código especificado. */
void show_vehicles_by_code(register_data registration[], counter_data counter, int n_code);

/* Conta a quantidade de veículos do codigo especificado que ha na garagem. */
void count_vehicles_by_code(register_data registration[], counter_data counter, int n_code);


// 4. RELATÓRIO POR CÓDIGO E COR

/* Mostra para o usuário um relátorio, dado o código e a cor dos veículos. */
void show_report_by_color_and_code(register_data registration[], counter_data counter);

/* Procura os dados registrados no valor do código e cor especificados e exíbi-os.*/
void find_register(register_data registration[], counter_data counter, int n_color, int n_code);


// 5. INSERIR NOVO VEÍCULO

/* Adiciona UM novo veículo. Se o veículo já existir, ele soma o valor ao valor original. */
void add_new_vehicle(register_data registration[], counter_data counter);
