#include <inttypes.h>
/* #define MAX_VEHICLES 150 */
/* #define MAX_REGISTERS 25 */

/* Novo tipo para armazenar os dados de cada cadastro. */
typedef struct register_data {
    int code, color, amount;
} register_data;

/* Novo tipo para armazenar os dados contados durante o programa. */
typedef struct counter_data {
    int total_registers,
        total_vehicles,
        vehicles_by_code,
        vehicles_by_color,
        vehicles_by_code_and_color;
} counter_data;