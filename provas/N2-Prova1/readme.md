# 1° Atividade Avaliativa para N2 – 2023/2 08/11/2023

Exercício individual, valendo 4,0 pontos .

Implementar o seguinte problema em linguagem C usando modularização. Não utilizar variáveis globais, os
dados devem se passados como parâmetro. A utilização de arquivo em disco para armazenar as entradas é
recomendável, mas não é obrigatório.

A parte do código que faz a leitura dos dados de entrada deve ser feito hoje na sala de aula. Além das
leituras, você deve organizar a estrutura do programa em um menu que o usuário escolherá a opção
desejada e deve planejar as funções que serão implementadas (adicionar seus protótipos). O restante do
código deve ser finalizado depois e apresentado dia 10/11.

Uma concessionária de veículos mantêm o cadastro de seus veículos desta forma:

- código do veículo (número inteiro);
- código da cor (1 para branco, 2 para preto, 3 para vermelho e 4 para cinza);
- quantidade.

A capacidade máxima de armazenagem nas suas garagens é de 150 veículos. Não permita que sejam
cadastrados mais veículos do que a capacidade.

## Problema

Faça um programa que inicialmente leia os dados dos vários veículos que estão atualmente na
concessionária. Serão cadastrados, no máximo 25 tipos de veículos. Não permita código do veículo
com mesma cor em linhas diferentes.

Após esta leitura inicial, ofereça ao vendedor, sempre que desejar, a possibilidade de consultar um
destes relatórios:

- Relatório geral
    - mostre todos os veículos e seus dados;
    - mostre a quantidade total de veículos;
    - mostre a percentagem de ocupação das garagens.

- Relatório por cor (dada a cor)
    - mostre a quantidade total e todos os veículos desta cor;

- Relatório por código (dado o código)
    - mostre a quantidade total de veículos;
    - mostre todos os veículos com o código e seus dados;
    - mostre a quantidade por veículo, dados o código do veículo e sua cor.
    Se o veículo for encontrado, a busca deve ser interrompida.
    
Pode ocorrer a necessidade de cadastrar um veículo que tenha sido adquirido esporadicamente, então o
programa deve ser capaz de inserir um veículo (apenas 1) a qualquer momento.
