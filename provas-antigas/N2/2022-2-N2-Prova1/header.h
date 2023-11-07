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


/*  */
function();
