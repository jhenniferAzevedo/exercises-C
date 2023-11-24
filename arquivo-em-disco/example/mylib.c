#include <stdio.h>
#include "header.h"

int cont = 0;

void createFile() {
    Garage *garagem;

    // cria um ponteiro do tipo file que apontará para um arquivo e abre 
    // o arquivo passando o endereço para o ponteiro com a função de ler 
    // o arquivo.
    FILE *file = fopen("binario", "rb");

    // se o arquivo não existir, cria um novo arquivo.
    if (file == NULL) {
        // lê os dados e retorna o total de cadastros.
        cont = readData(garagem);
        updateFile(garagem, cont);
    }
    fill(garagem, cont);
}

void updateFile(Garage *garagem, int cont) {
    // cria um ponteiro do tipo file que apontará para um arquivo.
    FILE *file;

    // abre o arquivo passando o endereço para o ponteiro com a função de 
    // escrever no arquivo.
    file = fopen("binario", "wb");
    for(int i = 0; i < 2 ; i++) {
        // escreve no arquivo tudo que há no struct Garagem no arquivo file.
        fwrite(&garagem->carro[i], sizeof(Car), 1, file);
    }
    fclose(file);
}

void fill(Garage *garagem, int cont) {
    FILE *file;

    // abre o arquivo passando o endereço para o ponteiro com a função de 
    // ler o arquivo.
    file = fopen("binario", "rb");

    for(int i = 0; i < 2 ; i++) {
        // lê os dados da struct Garagem e salva no arquivo tudo que há nele. 
        fread(&garagem->carro[i], sizeof(Car), 1, file);
    }
    fclose(file);
}
