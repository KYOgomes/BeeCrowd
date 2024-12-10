#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L 1000005
#define MAX_N 100005
#define ALPHABET_SIZE 26

char S[MAX_L]; // String principal

// Estrutura de árvore de Fenwick para contagem de caracteres
int freq[MAX_L][ALPHABET_SIZE];

// Estrutura de árvore de Fenwick para primeiras e últimas ocorrências de caracteres
int first_last[MAX_L][ALPHABET_SIZE][2]; // 0 para primeira, 1 para última

// Tamanho da string S
int L;

// Função para atualizar uma árvore de Fenwick
void fenwick_update(int idx, int pos, int val, int tree[MAX_L][ALPHABET_SIZE]) {
    while (pos <= L) {
        tree[pos][idx] += val;
        pos += pos & -pos;
    }
}

// Função para consultar uma árvore de Fenwick
int fenwick_query(int idx, int pos, int tree[MAX_L][ALPHABET_SIZE]) {
    int sum = 0;
    while (pos > 0) {
        sum += tree[pos][idx];
        pos -= pos & -pos;
    }
    return sum;
}

// Função para encontrar a primeira ou última ocorrência de um caractere em um intervalo
int find_occurrence(int idx, int left, int right, int tree[MAX_L][ALPHABET_SIZE][2], int type) {
    int res = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int count = fenwick_query(idx, mid, tree);
        if (count > 0) {
            res = mid;
            if (type == 0) // Procurando primeira ocorrência
                right = mid - 1;
            else // Procurando última ocorrência
                left = mid + 1;
        } else {
            if (type == 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return res;
}

int main() {
    int N;
    scanf("%d %d", &L, &N);

    scanf("%s", S + 1); // Lendo a string S, começando do índice 1

    // Inicializando as estruturas de árvore de Fenwick
    memset(freq, 0, sizeof(freq));
    memset(first_last, 0, sizeof(first_last));

    // Construindo as árvores de Fenwick baseadas na string inicial S
    for (int i = 1; i <= L; ++i) {
        int char_idx = S[i] - 'a';
        fenwick_update(char_idx, i, 1, freq);
        if (first_last[char_idx][0][0] == 0) {
            first_last[char_idx][0][0] = i;
        }
        first_last[char_idx][0][1] = i;
    }

    // Processando as operações
    char op;
    int A, B;
    char C;
    for (int i = 0; i < N; ++i) {
        getchar(); // Captura o \n ou espaço após o número

        scanf("%c", &op);
        
        if (op == '1') {
            scanf("%d %d %c", &A, &B, &C);
            int char_idx = C - 'a';
            int count = fenwick_query(char_idx, B, freq) - fenwick_query(char_idx, A - 1, freq);
            printf("%d\n", count);
        } else if (op =='2') {
            scanf("%d %d %c", &A, &B, &C);
            int char_idx = C - 'a';
            int first_occurrence = find_occurrence(char_idx, A, B, first_last, 0);
            int last_occurrence = find_occurrence(char_idx, A, B, first_last, 1);
            
            if (first_occurrence == -1) {
                printf("-1\n");
            } else {
                printf("%d %d\n", first_occurrence, last_occurrence);
            }
        } else if (op == '3') {
            scanf("%d %d", &A, &B);
            // Invertendo a substring S[A] até S[B]
            int len = (B - A + 1);
            for (int j = 0; j < len / 2; ++j) {
                char tmp = S[A + j];
                S[A + j] = S[B - j];
                S[B - j] = tmp;
            }

            // Atualizando as árvores de Fenwick para refletir a inversão
            for (int j = A; j <= B; ++j) {
                int char_idx1 = S[j] - 'a';
                int char_idx2 = S[B - (j - A)] - 'a';
                
                // Atualizando contagem de caracteres
                fenwick_update(char_idx1, j, 1, freq);
                fenwick_update(char_idx2, B - (j - A) + 1, 1, freq);
                fenwick_update(char_idx1, j + 1, -1, freq);
                fenwick_update(char_idx2, B - (j - A), -1, freq);
                
                // Atualizando primeiras e últimas ocorrências
                if (first_last[char_idx1][0][0] == j) {
                    first_last[char_idx1][0][0] = B - (j - A);
                }
                if (first_last[char_idx2][0][0] == B - (j - A)) {
                    first_last[char_idx2][0][0] = j;
                }
                if (first_last[char_idx1][0][1] == j) {
                    first_last[char_idx1][0][1] = B - (j - A);
                }
                if (first_last[char_idx2][0][1] == B - (j - A)) {
                    first_last[char_idx2][0][1] = j;
                }
            }
        } else if (op == '4') {
            scanf("%d %c", &A, &C);
            // Adicionando o caractere C antes de S[A]
            L++; // Aumenta o tamanho da string
            for (int j = L; j > A; --j) {
                S[j] = S[j - 1];
            }
            S[A] = C;
            
            // Atualizando as árvores de Fenwick para refletir a adição
            int char_idx = C - 'a';
            fenwick_update(char_idx, A, 1, freq);
            if (first_last[char_idx][0][0] == 0) {
                first_last[char_idx][0][0] = A;
            }
            first_last[char_idx][0][1] = A;
        }
    }

    // Imprimindo a string resultante
    printf("%s\n", S + 1);

    return 0;
}
