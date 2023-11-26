#define RED_TEXT   "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define RESET_TEXT "\x1b[0m"

typedef struct register_data
{
    int code, color, amount;
} register_data;

typedef struct counter_data
{
    int total_registers,
        total_vehicles,
        vehicles_by_code,
        vehicles_by_color,
        vehicles_by_code_and_color;
} counter_data;


// LEITURAS
void read_data(register_data registration[], 
    counter_data *counter);
void ask_vehicle_code(register_data registration[], 
    int n_register);
void menu_colors(void);
void ask_color_code(register_data registration[], 
    int n_register);
void check_color_code(int *value_color);
int ask_how_many_vehicle(register_data registration[], 
    counter_data *counter, 
    int *n_register);
void count_total_vehicle(register_data registration[], 
    counter_data *counter, 
    int *n_register);
int error_handling_of_max_amount(register_data registration[], 
    counter_data *counter, 
    int *n_register);
int check_status_garage(counter_data *counter);
int show_message_by_status_garage(register_data registration[], 
    counter_data *counter, 
    int *n_register, 
    int status);
void check_existing_registrations(register_data registration[], 
    counter_data *counter, 
    int *n_register);
void add_to_existing_registration(register_data registration[], 
    int *new_register, 
    int old_register);


// RELATÓRIOS
void menu_report(int *answer);
void menu_register(register_data registration[], int i);
void show_reports(register_data registration[],
    counter_data *counter);
void check_vehicles(int amount);


// RELATORIO GERAL
void show_general_report(register_data registration[], 
    counter_data *counter);
void show_all_vehicles(register_data registration[], 
    counter_data *counter);
float calculate_garage_percentage(counter_data *counter);


// RELATÓRIO POR COR
void show_report_by_color(register_data registration[], 
    counter_data *counter);
void show_vehicles_by_color(register_data registration[], 
    counter_data *counter, 
    int n_color);
void count_vehicles_by_color(register_data registration[], 
    counter_data *counter, 
    int n_color);


// 3. RELATÓRIO POR CÓDIGO
void show_report_by_code(register_data registration[], 
    counter_data *counter);
void show_vehicles_by_code(register_data registration[], 
    counter_data *counter, 
    int n_code);
void count_vehicles_by_code(register_data registration[], 
    counter_data *counter, 
    int n_code);


// RELATÓRIO POR CÓDIGO E COR
void show_report_by_color_and_code(register_data registration[], 
    counter_data *counter);
void find_register(register_data registration[], 
    counter_data *counter, 
    int n_color, 
    int n_code);


// INSERIR NOVO VEÍCULO
void add_new_vehicle(register_data registration[], 
    counter_data *counter);
