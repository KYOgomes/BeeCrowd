/*
Resolva a questão abaixo em Java:
Um histograma é um polígono composto por uma seqüência de retângulos alinhados em uma linha de base comum. Os retângulos têm larguras iguais, mas podem ter diferentes alturas. Por exemplo, a figura da esquerda nos mostra um histograma com retângulos de alturas 2, 1, 4, 5, 1, 3, 3, onde a medida 1 é a largura dos retângulos:

Normalmente, histogramas são utilizados para representar distribuições discretas, como a freqüência de caracteres em um texto. Note que a ordem dos retângulos, ou seja, suas alturas, é importante. Calcule a área do maior retângulo de um histograma, que também esteja alinhado com a base. A figura da direita mostra o maior retângulo alinhado no histograma apresentado.

Entrada
A entrada contém vários casos de teste. Cada caso de teste descreve um histograma, e inicia com um inteiro n, que representa o número de retângulos que o compõe. Assuma que 1 ≤ n ≤ 100000. Em seguida, n inteiros h1, ..., hn, onde 0 ≤ hi ≤ 1000000000. Esses números representam as alturas dos retangulos do histograma, da esquerda para a direita. A largura de cada retângulo é 1. Um zero na entrada representa o ultimo caso de teste.

Saída
Para cada caso de teste imprima em uma única linha a área do maior retângulo no histograma especificado. Lembre-se que esse retângulo deve estar alinhado com a base do histograma.

Exemplo de Entrada	
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0

Exemplo de Saída
8
4000
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int calcularMaiorAreaHistograma(int alturas[], int n) {
    int pilha[MAX_N];
    int topo = -1;
    int maiorArea = 0;
    int i = 0;

    while (i < n) {
        if (topo == -1 || alturas[pilha[topo]] <= alturas[i]) {
            pilha[++topo] = i++;
        } else {
            int topoPilha = pilha[topo--];
            int altura = alturas[topoPilha];
            int largura = topo == -1 ? i : i - pilha[topo] - 1;
            int area = altura * largura;
            if (area > maiorArea) {
                maiorArea = area;
            }
        }
    }

    while (topo != -1) {
        int topoPilha = pilha[topo--];
        int altura = alturas[topoPilha];
        int largura = topo == -1 ? i : i - pilha[topo] - 1;
        int area = altura * largura;
        if (area > maiorArea) {
            maiorArea = area;
        }
    }

    return maiorArea;
}

int main() {
    int n;
    int alturas[MAX_N];

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            scanf("%d", &alturas[i]);
        }

        int maiorArea = calcularMaiorAreaHistograma(alturas, n);
        printf("%d\n", maiorArea);
    }

    return 0;
}
