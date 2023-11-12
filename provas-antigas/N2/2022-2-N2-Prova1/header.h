#define MAX_CLIENT 2
#define MAX_PRODUCT 3
#define MAX_ORDERS 10

/* Novo tipo para armazenar os dados de cada pedido. */
typedef struct order_data
{
    int qntd_do_produto[MAX_PRODUCT][MAX_ORDERS],
        local_de_entrega, 
        qntd_de_pedidos;
    float peso_do_pedido[MAX_ORDERS],
        media_pesos,
        valor_do_frete;
} order_data;

/* Novo tipo para diminuir a quantidade de parâmetros nos procedimentos/funções de
 * formulário. */
typedef struct reply_data
{
    int n_client,
        n_order,
        n_product,
        answer,
        option;
} reply_data;



/* Lê os dados dos pedidos de cada cliente. */
void read_data(order_data client[]);

/* Lê os dados do cliente especificado. */
void read_client_data(order_data client[], int n_client);

/* Lê a quantidade de produtos por cliente. */
void read_product_data(order_data client[], int n_client, int n_order);

/* Pergunta quais são os produtos que o cliente quer comprar. */
int ask_what_products_user_wants(void);

/* Mostra o menu de produtos disponíveis. */
void show_product_available(void);

/* Verifica se o valor digitado pelo cliente esta entre 1 e 3. 
 * Se não estiver, pede para que ele o troque. */
void check_answer(int *answer);

/* Procura qual formulário deve mortrar pro cliente, e exibe ele na tela. */
void ask_how_many_products(order_data client[], int answer);

/* Pergunta a quantidade do único produto que o cliente quer comprar. */
void ask_how_many_products1(int answer);

/* Pergunta a quantidade dos dois produtos que o cliente quer comprar. */
void ask_how_many_products2(int answer);

/* Pergunta a quantidade dos três produtos que o cliente quer comprar. */
void ask_how_many_products3(int answer);


