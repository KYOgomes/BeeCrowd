/*
As tabelas Hash, também conhecidas como tabelas de dispersão, armazenam elementos com base no valor absoluto de suas chaves e em técnicas de tratamento de colisões. Para o cálculo do endereço onde deve ser armazenada uma determinada chave, utiliza-se uma função denominada função de dispersão, que transforma a chave em um dos endereços disponíveis na tabela.

Suponha que uma aplicação utilize uma tabela de dispersão com 13 endereços-base (índices de 0 a 12) e empregue a função de dispersão h(x) = x mod 13, em que x representa a chave do elemento cujo endereço-base deve ser calculado.

Se a chave x for igual a 49, a função de dispersão retornará o valor 10, indicando o local onde esta chave deverá ser armazenada. Se a mesma aplicação considerar a inserção da chave 88, o cálculo retornará o mesmo valor 10, ocorrendo neste caso uma colisão. O Tratamento de colisões serve para resolver os conflitos nos casos onde mais de uma chave é mapeada para um mesmo endereço-base da tabela. Este tratamento pode considerar, ou o recálculo do endereço da chave ou o encadeamento externo ou exterior.

O professor gostaria então que você o auxiliasse com um programa que calcula o endereço para inserções de diversas chaves em algumas tabelas, com funções de dispersão e tratamento de colisão por encadeamento exterior.

Entrada
A entrada contém vários casos de teste. A primeira linha de entrada contém um inteiro N indicando a quantidade de casos de teste. Cada caso de teste é composto por duas linhas. A primeira linha contém um valor M (1 ≤ M ≤ 100) que indica a quantidade de endereços-base na tabela (normalmente um número primo) seguido por um espaço e um valor C (1 ≤ C ≤ 200) que indica a quantidade de chaves a serem armazenadas. A segunda linha contém cada uma das chaves (com valor entre 1 e 200), separadas por um espaço em branco.

Saída
A saída deverá ser impressa conforme os exemplos fornecidos abaixo, onde a quantidade de linhas de cada caso de teste é determinada pelo valor de M. Uma linha em branco deverá separar dois conjuntos de saída


Exemplo de Entrada	
2
13 9
44 45 49 70 27 73 92 97 95
7 8
35 12 2 17 19 51 88 86

Exemplo de Saída
0 -> \
1 -> 27 -> 92 -> \
2 -> \
3 -> \
4 -> 95 -> \
5 -> 44 -> 70 -> \
6 -> 45 -> 97 -> \
7 -> \
8 -> 73 -> \
9 -> \
10 -> 49 -> \
11 -> \
12 -> \

0 -> 35 -> \
1 -> \
2 -> 2 -> 51 -> 86 -> \
3 -> 17 -> \
4 -> 88 -> \
5 -> 12 -> 19 -> \
6 -> \
*/

#include <stdlib.h>
#include <stdio.h>

// Definição da estrutura do nó da lista encadeada
typedef struct ListaNo
{
    int valor;              // Valor armazenado no nó
    struct ListaNo *prox;   // Ponteiro para o próximo nó na lista
} ListaNo;

// Definição da estrutura da lista encadeada
typedef struct ListaEncadeada
{
    ListaNo *lista;         // Ponteiro para o primeiro nó da lista
} ListaEncadeada;

// Definição da estrutura da tabela hash
typedef struct TabelaHash
{
    int n;                  // Número de listas na tabela hash
    ListaEncadeada *tabela; // Ponteiro para a tabela hash (array de listas encadeadas)
} TabelaHash;

// Função para inicializar uma lista encadeada
void inicializaLista(ListaEncadeada *l)
{
    l->lista = NULL;  // Inicializa o ponteiro da lista como NULL
}

// Função para destruir um nó da lista recursivamente
void destroiNo(ListaNo *p)
{
    if (p->prox != NULL)
    {
        destroiNo(p->prox); // Chama recursivamente para o próximo nó
    }

    free(p); // Libera a memória do nó atual
}

// Função para destruir uma lista encadeada
void destroiLista(ListaEncadeada *l)
{
    if (l->lista != NULL)
    {
        destroiNo(l->lista); // Chama a função destrói nó para o primeiro nó da lista
    }
}

// Função para adicionar um novo nó no fim da lista encadeada
ListaNo *adicionaNo(ListaNo *p, int valor)
{
    if (p == NULL)
    {
        ListaNo *novo = (ListaNo *)malloc(sizeof(ListaNo)); // Aloca memória para um novo nó
        novo->valor = valor;  // Atribui o valor ao novo nó
        novo->prox = NULL;    // Define o próximo como NULL, pois será o último nó

        return novo; // Retorna o novo nó criado
    }
    else
    {
        p->prox = adicionaNo(p->prox, valor); // Chama recursivamente para o próximo nó
        return p; // Retorna o nó atual
    }
}

// Função para adicionar um elemento (valor) à lista encadeada
void adicionaElemento(ListaEncadeada *l, int valor)
{
    if (l == NULL)
    {
        l = (ListaEncadeada *)malloc(sizeof(ListaEncadeada)); // Aloca memória para a lista encadeada
    }

    l->lista = adicionaNo(l->lista, valor); // Adiciona o valor à lista encadeada
}

// Função para imprimir os elementos da lista encadeada
void imprimeLista(ListaEncadeada *l)
{
    if (l != NULL)
    {
        ListaNo *p = l->lista; // Ponteiro para percorrer a lista

        while (p != NULL)
        {
            printf("%d -> ", p->valor); // Imprime o valor do nó atual
            p = p->prox; // Avança para o próximo nó
        }
    }

    printf("\\\n"); // Imprime '\\' para indicar o final da lista
}

// Função para inicializar a tabela hash com 'n' listas encadeadas vazias
void inicializaTabelaHash(TabelaHash *tabela, int n)
{
    tabela->n = n; // Atribui o número de listas à tabela hash
    tabela->tabela = (ListaEncadeada *)malloc(n * sizeof(ListaEncadeada)); // Aloca memória para a tabela hash como um array de listas encadeadas

    for (int i = 0; i < n; ++i)
    {
        inicializaLista(&(tabela->tabela[i])); // Inicializa cada lista encadeada na tabela hash
    }
}

// Função para destruir a tabela hash, liberando toda a memória alocada
void destroiTabelaHash(TabelaHash *tabela)
{
    for (int i = 0; i < tabela->n; ++i)
    {
        destroiLista(&(tabela->tabela[i])); // Chama a função para destruir cada lista encadeada na tabela hash
    }

    tabela->n = 0; // Reseta o número de listas na tabela para zero
    free(tabela->tabela); // Libera a memória alocada para o array de listas encadeadas
}

// Função para calcular o índice na tabela hash para um dado valor
int funcaoHash(TabelaHash *tabela, int valor)
{
    return valor % tabela->n; // Retorna o resto da divisão do valor pelo número de listas na tabela hash
}

// Função para adicionar um elemento à tabela hash
void adicionaElementoTabela(TabelaHash *tabela, int valor)
{
    int indice = funcaoHash(tabela, valor); // Calcula o índice na tabela hash para o valor dado
    adicionaElemento(&(tabela->tabela[indice]), valor); // Adiciona o valor à lista encadeada correspondente na tabela hash
}

// Função para imprimir toda a tabela hash
void imprimeTabelaHash(TabelaHash *tabela)
{
    for (int i = 0; i < tabela->n; ++i)
    {
        printf("%d -> ", i); // Imprime o índice da lista na tabela hash
        imprimeLista(&(tabela->tabela[i])); // Imprime os elementos da lista encadeada correspondente
    }
}

// Função principal
int main()
{
    int N, M, C, numero;
    TabelaHash th; // Declara uma variável do tipo TabelaHash

    scanf("%d", &N); // Lê o número de casos de teste

    for (int k = 0; k < N; ++k)
    {
        if (k)
            printf("\n");

        scanf("%d %d", &M, &C); // Lê M (número de listas) e C (número de elementos)

        inicializaTabelaHash(&th, M); // Inicializa a tabela hash com M listas encadeadas

        for (int i = 0; i < C; ++i)
        {
            scanf("%d", &numero); // Lê cada número a ser inserido na tabela hash
            adicionaElementoTabela(&th, numero); // Adiciona o número à tabela hash
        }

        imprimeTabelaHash(&th); // Imprime a tabela hash após a inserção dos números

        destroiTabelaHash(&th); // Libera toda a memória alocada para a tabela hash
    }

    return 0; // Retorna 0 para indicar que o programa terminou sem erros
}
