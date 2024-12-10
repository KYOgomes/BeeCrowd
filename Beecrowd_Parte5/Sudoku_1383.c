/*
O jogo de Sudoku espalhou-se rapidamente por todo o mundo, tornando-se hoje o passatempo mais popular em todo o planeta. Muitas pessoas, entretanto, preenchem a matriz de forma incorreta, desrespeitando as restrições do jogo. Sua tarefa neste problema é escrever um programa que verifica se uma matriz preenchida é ou não uma solução para o problema.

A matriz do jogo é uma matriz de inteiros 9 x 9 . Para ser uma solução do problema, cada linha e coluna deve conter todos os números de 1 a 9. Além disso, se dividirmos a matriz em 9 regiões 3 x 3, cada uma destas regiões também deve conter os números de 1 a 9. O exemplo abaixo mostra uma matriz que é uma solução do problema.

Entrada
São dadas várias instâncias. O primeiro dado é o número n > 0 de matrizes na entrada. Nas linhas seguintes são dadas as n matrizes. Cada matriz é dada em 9 linhas, em que cada linha contém 9 números inteiros.

Saída
Para cada instância seu programa deverá imprimir uma linha dizendo "Instancia k", onde k é o número da instância atual. Na segunda linha, seu programa deverá imprimir "SIM" se a matriz for a solução de um problema de Sudoku, e "NAO" caso contrário. Imprima uma linha em branco após cada instância.

Exemplo de Entrada
2
1 3 2 5 7 9 4 6 8
4 9 8 2 6 1 3 7 5
7 5 6 3 8 4 2 1 9
6 4 3 1 5 8 7 9 2
5 2 1 7 9 3 8 4 6
9 8 7 4 2 6 5 3 1
2 1 4 9 3 5 6 8 7
3 6 5 8 1 7 9 2 4
8 7 9 6 4 2 1 5 3
1 3 2 5 7 9 4 6 8
4 9 8 2 6 1 3 7 5
7 5 6 3 8 4 2 1 9
6 4 3 1 5 8 7 9 2
5 2 1 7 9 3 8 4 6
9 8 7 4 2 6 5 3 1
2 1 4 9 3 5 6 8 7
3 6 5 8 1 7 9 2 4
8 7 9 6 4 2 1 3 5

Exemplo de Saída
Instancia 1
SIM

Instancia 2
NAO
*/
#include <stdio.h>
#include <stdbool.h>

// Função para ordenar uma lista de inteiros (usaremos o Bubble Sort para simplicidade)
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função f
bool f(int s[9][9], int x1, int y1, int x2, int y2) {
    int linha[9];
    int index = 0;

    // Gera a lista de inteiros da submatriz
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            linha[index++] = s[i][j];
        }
    }

    // Ordena a lista
    bubble_sort(linha, 9);

    // Verifica se a lista ordenada contém exatamente 1 a 9
    for (int i = 0; i < 9; i++) {
        if (linha[i] != i + 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int s[9][9];

        // Lê a matriz 9x9
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                scanf("%d", &s[j][k]);
            }
        }

        bool linhas[27];
        int index = 0;

        // Verifica linhas e colunas
        for (int j = 0; j < 9; j++) {
            linhas[index++] = f(s, j, 0, j, 8); // Verifica linha j
            linhas[index++] = f(s, 0, j, 8, j); // Verifica coluna j
        }

        // Verifica subgrades 3x3
        for (int j = 0; j < 9; j += 3) {
            for (int k = 0; k < 9; k += 3) {
                linhas[index++] = f(s, j, k, j + 2, k + 2); // Verifica subgrade 3x3
            }
        }

        // Verifica se todas as condições são verdadeiras
        bool ok = true;
        for (int j = 0; j < 27; j++) {
            if (!linhas[j]) {
                ok = false;
                break;
            }
        }

        printf("Instancia %d\n", i);
        if (ok) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
