/*
Dada uma linha de texto, você deve encontrar as frequências de cada um dos caracteres presentes nela. As linhas fornecidas não conterão nenhum dos primeiros 32 ou dos últimos 128 caracteres da tabela ASCII. É claro que não estamos levando em conta o caracter de fim de linha.

Entrada
A entrada contém vários casos de teste. Cada caso de teste é composto por uma única linha de texto com até 1000 caracteres.

Saída
Imprima o valor ASCII de todos os caracteres presentes e a sua frequência de acordo com o formato abaixo. Uma linha em branco deverá separar 2 conjuntos de saída. Imprima os caracteres ASCII em ordem ascendente de frequência. Se dois caracteres estiverem presentes com a mesma quantidade de frequência, imprima primeiro o caracter que tem valor ASCII maior. A entrada é terminada por final de arquivo (EOF).

Exemplo de Entrada	
AAABBC
122333

Exemplo de Saída
67 1
66 2
65 3

49 1
50 2
51 3
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Estrutura para armazenar o caractere ASCII e sua frequência
typedef struct {
    char ascii;
    unsigned short frequencia;
} Dados;

// Função interna para ordenar utilizando o algoritmo Quicksort
void quickSortInterno(Dados *caractere, int inicio, int fim);

// Função principal de ordenação utilizando Quicksort
void quickSort(Dados *caractere, int tam);

// Função de ordenação secundária utilizando Insertion Sort
void insertionSort(Dados *caractere, unsigned short tam);

int main() {
    unsigned short i, j, k, z = 0;
    char texto[1001];
    short frequencia;
    bool foivisto[1001];
    Dados caractere[1001];

    // Enquanto houver entrada para processar
    while (scanf(" %[^\n]", texto) != EOF) {
        k = 0;

        // Inicializa o vetor de controle de caracteres vistos
        memset(foivisto, false, sizeof(foivisto));

        // Percorre cada caractere na linha de texto
        for (i = 0; texto[i]; i++) {
            frequencia = 0;

            // Se o caractere atual não foi visto ainda
            if (!foivisto[i]) {
                // Conta a frequência do caractere na linha
                for (j = 0; texto[j]; j++) {
                    if (texto[i] == texto[j]) {
                        foivisto[j] = true; // Marca como visto
                        frequencia++; // Incrementa a frequência
                    }
                }

                // Armazena o caractere e sua frequência na estrutura Dados
                caractere[k].ascii = texto[i];
                caractere[k].frequencia = frequencia;
                k++;
            }
        }

        // Ordena primeiro por ASCII utilizando Quicksort
        quickSort(caractere, k);

        // Em caso de empate na frequência, ordena por frequência usando Insertion Sort
        insertionSort(caractere, k);

        // Imprime uma linha em branco entre conjuntos de saída
        if (z)
            printf("\n");
        else
            z++;

        // Imprime os resultados ordenados
        for (i = 0; i < k; i++)
            printf("%hhd %hu\n", caractere[i].ascii, caractere[i].frequencia);
    }
}

// Implementação do Quicksort para ordenar por ASCII
void quickSortInterno(Dados *caractere, int inicio, int fim) {
    Dados pivo, temp;
    int i, j;

    if (fim - inicio > 0) {
        if (inicio < fim) {
            i = inicio;
            j = fim;
            pivo = caractere[(i + j) / 2]; // Escolhe o pivô

            // Particiona o array em torno do pivô
            do {
                while (caractere[i].ascii > pivo.ascii)
                    i++;
                while (caractere[j].ascii < pivo.ascii)
                    j--;

                if (i <= j) {
                    temp = caractere[i];
                    caractere[i] = caractere[j];
                    caractere[j] = temp;
                    i++;
                    j--;
                }
            } while (i <= j);

            // Chama recursivamente para as partições restantes
            quickSortInterno(caractere, inicio, j);
            quickSortInterno(caractere, i, fim);
        }
    }
}

// Função principal de ordenação utilizando Quicksort
void quickSort(Dados *caractere, int tam) {
    quickSortInterno(caractere, 0, tam - 1);
}

// Implementação do Insertion Sort para ordenar por frequência em caso de empate
void insertionSort(Dados *caractere, unsigned short tam) {
    short i = 1, j;
    Dados pivo;

    while (i < tam) {
        j = i - 1;
        pivo = caractere[i];

        // Move os elementos maiores que o pivô para a direita
        while (j >= 0 && caractere[j].frequencia > pivo.frequencia) {
            caractere[j + 1] = caractere[j];
            j--;
        }

        caractere[j + 1] = pivo; // Insere o pivô na posição correta
        i++;
    }
}
