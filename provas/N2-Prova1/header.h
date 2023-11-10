/* Inicializa qualquer vetor inteiro de acordo com a quantidade de elementos que ele possui. */
void init_array(int array[], int size);


// LEITURAS

/* Lê todos os dados dos cadastros registrados. */
void read_data(int registration[][3], int counter[]);

/* Pergunta pro usuário qual é o código do veículo. */
void ask_vehicle_code(int registration[][3], int code_register);

/* Mostra o menu de códigos das cores disponíveis. */
void menu_colors(void);

/* Pergunta pro usuário qual é o código da cor. */
void ask_color_code(int registration[][3], int code_register);

/* Verifica se o código da cor especificada é válido. Se não, pede para trocá-lo*/
void check_color_code(int *value_color);

/* Pergunta pro usuário qual é o código da cor. */
int ask_how_many_vehicle(int registration[][3], int counter[], int *n_register);


// RELATÓRIOS

/* Mostra o menu nos relatórios. */
void menu_report(void);

/* Mostra o cadatro e suas informações de acordo com o número do cadastro (i). */
void menu_register(int registration[][3], int i);

// 1. RELATORIO GERAL

/* Adiciona o valor dititado pelo usuário para a quantidade total de carros que ha na garagem. */
void count_total_vehicle(int registration[][3], int counter[], int *n_register);

/* Faz todo o tratamento de erro para que o usuário não estoure o valor máximo de veículos permitido. */
int error_handling_of_max_amount(int registration[][3], int counte[], int *n_register);

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
int show_message_by_status_garage(int registration[][3], int counter[], int *n_register, int status);

/* Verifica se já existe algum cadastro com o mesmo código de veículo e da cor. 
 * Se houver, adiciona o valor digitado ao cadastro existente.
 */
void check_existing_registrations(int registration[][3], int counter[], int *n_register);

/* Adiciona a quantidade de veículos digitada pelo usuário ao cadastro já existente. */
void add_to_existing_registration(int registration[][3], int *new_register, int old_register);


/* Mostra para o usuário o relatório geral. 
 * (todos os veiculos, quantidade total na garagem e percentagem de ocupação) */
void show_general_report(int registration[][3], int counter[]);

/* Mostra todos os cadastros de todos os veículos. */
void show_all_vehicles(int registration[][3], int counter[]);

/* Retorna o valor da porcentagem de ocupação da garagem. */
float calculate_garage_percentage(int counter[]);


// 2. RELATÓRIO POR COR

/* Mostra para o usuário um relátorio, dado a cor dos veículos. */
void show_report_by_color(int registration[][3], int counter[]);

/* Mostra todos os veículos que possuem a cor especificada. */
void show_vehicles_by_color(int registration[][3], int counter[], int n_color);

/* Conta a quantidade de veículos da cor especificada que ha na garagem. */
void count_vehicles_by_color(int registration[][3], int counter[], int n_color);


// 3. RELATÓRIO POR CÓDIGO

/* Mostra para o usuário um relátorio, dado o código dos veículos. */
void show_report_by_code(int registration[][3], int counter[]);

/* Mostra todos os veículos que possuem o código especificado. */
void show_vehicles_by_code(int registration[][3], int counter[], int n_code);

/* Conta a quantidade de veículos do codigo especificado que ha na garagem. */
void count_vehicles_by_code(int registration[][3], int counters[], int n_code);


// 4. RELATÓRIO POR CÓDIGO E COR

/* Mostra para o usuário um relátorio, dado o código e a cor dos veículos. */
void show_report_by_color_and_code(int registration[][3], int counter[]);

/* Procura os dados registrados no valor do código e cor especificados e exíbi-os.*/
void find_register(int registration[][3], int counter[], int n_color, int n_code);


// 5. INSERIR NOVO VEÍCULO

/* Adiciona UM novo veículo. Se o veículo já existir, ele soma o valor ao valor original. */
void add_new_vehicle(int registration[][3], int counter[]);
