#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100000
#define MAX_Q 100000
#define MAX_VAL 1000000000

// Estrutura para representar uma consulta
typedef struct {
    int L, R, index;
} Query;

// Função de comparação para ordenar as queries
int compare_queries(const void *a, const void *b) {
    Query *query1 = (Query *)a;
    Query *query2 = (Query *)b;
    
    // Ordenar primeiro por bloco e depois por R dentro do mesmo bloco
    int block1 = query1->L / blockSize;
    int block2 = query2->L / blockSize;
    
    if (block1 != block2)
        return block1 - block2;
    else
        return query1->R - query2->R;
}

int main() {
    int N, Q;
    int array[MAX_N + 1];
    Query queries[MAX_Q];
    
    // Leitura do tamanho do array e número de consultas
    scanf("%d %d", &N, &Q);
    
    // Leitura dos elementos do array
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &array[i]);
    }
    
    // Leitura das consultas
    for (int i = 0; i < Q; ++i) {
        scanf("%d %d", &queries[i].L, &queries[i].R);
        queries[i].index = i;
    }
    
    // Mo's Algorithm: Ordenação das consultas
    blockSize = (int)sqrt(Q); // Tamanho do bloco
    qsort(queries, Q, sizeof(Query), compare_queries);
    
    // Arrays para contar frequências
    int freq[MAX_VAL + 1] = {0};
    int countFreq[MAX_N + 1] = {0}; // Contagem de frequências
    
    int currentL = 1, currentR = 0;
    int distinctCount = 0;
    int answer[MAX_Q];
    
    // Processamento das consultas
    for (int i = 0; i < Q; ++i) {
        int L = queries[i].L;
        int R = queries[i].R;
        int index = queries[i].index;
        
        // Ajustar o intervalo [currentL, currentR] para [L, R]
        while (currentR < R) {
            currentR++;
            int num = array[currentR];
            
            // Ajustar a frequência do número atual
            freq[num]++;
            
            // Contar a ocorrência de números com frequência igual ao próprio valor
            if (freq[num] == num) {
                countFreq[num]++;
                if (countFreq[num] == num) {
                    distinctCount++;
                }
            }
        }
        
        while (currentR > R) {
            int num = array[currentR];
            
            // Ajustar a frequência do número atual
            freq[num]--;
            
            // Contar a ocorrência de números com frequência igual ao próprio valor
            if (freq[num] == num - 1) {
                countFreq[num]--;
                if (countFreq[num] == num) {
                    distinctCount--;
                }
            }
            
            currentR--;
        }
        
        while (currentL < L) {
            int num = array[currentL];
            
            // Ajustar a frequência do número atual
            freq[num]--;
            
            // Contar a ocorrência de números com frequência igual ao próprio valor
            if (freq[num] == num - 1) {
                countFreq[num]--;
                if (countFreq[num] == num) {
                    distinctCount--;
                }
            }
            
            currentL++;
        }
        
        while (currentL > L) {
            currentL--;
            int num = array[currentL];
            
            // Ajustar a frequência do número atual
            freq[num]++;
            
            // Contar a ocorrência de números com frequência igual ao próprio valor
            if (freq[num] == num) {
                countFreq[num]++;
                if (countFreq[num] == num) {
                    distinctCount++;
                }
            }
        }
        
        // Armazenar a resposta
        answer[index] = distinctCount;
    }
    
    // Imprimir as respostas
    for (int i = 0; i < Q; ++i) {
        printf("%d\n", answer[i]);
    }
    
    return 0;
}
