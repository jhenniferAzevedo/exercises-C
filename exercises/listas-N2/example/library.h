/* Novo tipo. */
struct TipoPessoa{
    int idade;
    char nome[50];
};
typedef struct TipoPessoa TipoPessoa;

/* 1.1° Exemplo com vetores. */
void imprime1(int [], int);

/* 1.2° Exemplo com vetores. */
void imprime2(int [5]);

/* 1.3° Exemplo com vetores. */
void imprime3(int *, int);

/* 2.0° Exemplo com matriz. */
void imprime4(int [][4], int);

/* 3.0° Exemplo com struct */
void imprime5(TipoPessoa);
