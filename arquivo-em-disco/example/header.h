typedef struct data
{
    /* data */
} data;


typedef struct Car {
    int code;
    int color;
    int quantity;
} Car;

typedef struct Garage {
    Car carro[25];
    int total;
} Garage;

void createFile();
void updateFile(Garage *garagem, int cont);
void corMenu();
int readData(Garage *garagem);
void checkingColor(int *color);
int checkingGaragem(Garage *garagem, int i);
int checkCar(Garage *garagem, int cont, int codigo,  int color, int *id_Existente);
void fill(Garage *garagem, int cont);
void relatorioGeral();