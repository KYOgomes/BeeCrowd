/*
O estábulo onde ficam as renas foi intencionalmente aberto pelo Elfo das Trevas permitindo que cada uma delas corresse e voasse livremente pela fábrica do Papai Noel, causando o maior transtorno. Os elfos estão tentando desesperadamente fazer o possível para deixar o trenó pronto para embarque. Você ficou responsável por colocar cada rena na sua posição correta assim que ela é capturada por um dos outros elfos.

Você sabe que o estábulo segue uma organização baseada na ordem que as renas irão ocupar no trenó. Desta forma, na hora da partida todas podem ser facilmente posicionadas. Diferentemente do que muitos pensam, as renas são posicionadas em uma fila única à frente no trenó. Nem todas as renas do estábulo são utilizadas em cada viagem, isto depende da carga total do trenó.

Você conseguiu a lista com as características que são utilizadas para determinar a ordem de rena. Elas devem ser ordenadas primeiramente de forma decrescente por peso. Caso duas ou mais apresentarem o mesmo peso elas devem ser ordenadas de forma ascendente pela idade, após pela altura e caso ainda persista empate, pelo nome.

Utilizando seu computador mágico de última geração você quer escrever um programa que ordene as renas, de acordo com as características informadas, e exiba somente o número exato de renas que serão utilizadas no trenó (de forma ordenada).

Entrada
Este problema possui diversos casos de teste. A primeira linha de entrada contém um inteiro T (1 ≤ T ≤ 105) que indica o número de casos de teste a seguir. A primeira linha de cada caso de teste contém dois inteiros N e M (5 ≤ N, M ≤ 103) que indicam respectivamente o número total de renas e o número de renas que irão puxar o trenó. Na sequência serão informados uma string S seguida por 2 inteiros P (1 ≤ P ≤ 300) e I (1 ≤ I ≤ 300) e por um número de ponto flutuante A (0.00 ≤ A ≤ 3.00), indicando respectivamente o nome, o peso, a idade e a altura de cada uma das renas. O nome de cada uma das renas é composto somente por uma palavra com até 100 caracteres.

Saída
Para cada caso de teste você deverá exibir a mensagem "CENARIO {i}", onde i indica o caso de teste atual, seguido da posição e o nome de cada umas das M renas que irão puxar o trenó, ordenadas conforme descrito acima

Exemplo de Entrada	
1
9 5
Rudolph 50 100 1.12
Dasher 10 121 1.98
Dancer 10 131 1.14
Prancer 7 142 1.36
Vixen 50 110 1.42
Comet 50 121 1.21
Cupid 50 107 1.45
Donner 30 106 1.23
Blitzen 50 180 1.84

Exemplo de Saída
CENARIO {1}
1 - Rudolph
2 - Cupid
3 - Vixen
4 - Comet
5 - Blitzen
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Rena
typedef struct {
    char nome[100];
    int peso;
    int idade;
    double altura;
} Rena;

// Função de comparação para ordenar renas
int compara_renas(const void *a, const void *b) {
    Rena *r1 = (Rena *)a;
    Rena *r2 = (Rena *)b;

    if (r1->peso != r2->peso)
        return r1->peso > r2->peso ? -1 : 1;
    else if (r1->idade != r2->idade)
        return r1->idade < r2->idade ? -1 : 1;
    else
        return r1->altura < r2->altura ? -1 : 1;
}

int main() {
    int t;
    scanf("%d", &t);  // Leitura do número de cenários

    for (int i = 1; i <= t; ++i) {
        int n, m;
        scanf("%d %d", &n, &m);  // Leitura de n e m

        Rena renas[n];

        // Leitura das renas
        for (int j = 0; j < n; ++j) {
            char nome[100];
            int peso, idade;
            double altura;
            scanf("%s %d %d %lf", nome, &peso, &idade, &altura);
            strcpy(renas[j].nome, nome);
            renas[j].peso = peso;
            renas[j].idade = idade;
            renas[j].altura = altura;
        }

        // Ordenação das renas usando qsort
        qsort(renas, n, sizeof(Rena), compara_renas);

        // Impressão do cenário
        printf("CENARIO {%d}\n", i);
        for (int j = 0; j < m; ++j) {
            printf("%d - %s\n", j + 1, renas[j].nome);
        }
    }

    return 0;
}
