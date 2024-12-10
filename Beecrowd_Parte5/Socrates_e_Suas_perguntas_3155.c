#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar uma consulta
typedef struct {
    int L, R, index;
} Query;

// Função de comparação para ordenar as consultas por blocos
int compareQueries(const void *a, const void *b) {
    Query *query1 = (Query *)a;
    Query *query2 = (Query *)b;
    
    // Ordena por blocos para minimizar a movimentação no array
    int blockSize = 500; // Tamanho do bloco ajustável
    int block1 = query1->L / blockSize;
    int block2 = query2->L / blockSize;
    
    if (block1 != block2) {
        return block1 - block2;
    } else {
        return query1->R - query2->R;
    }
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int array[N + 1];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &array[i]);
    }

    // Leitura das consultas e armazenamento em um array de estruturas Query
    Query queries[Q];
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &queries[i].L, &queries[i].R);
        queries[i].index = i;
    }

    // Ordenar as consultas usando a função de comparação
    qsort(queries, Q, sizeof(Query), compareQueries);

    // Arrays para contagem de frequência
    int count[N + 1];
    int freq[N + 1];
    int answer[Q];

    // Inicialização dos arrays de contagem
    for (int i = 0; i <= N; i++) {
        count[i] = 0;
        freq[i] = 0;
    }

    int currentL = 1, currentR = 0;
    int distinctCount = 0;

    // Função para adicionar um elemento no intervalo
    auto add = [&](int num) {
        int currentCount = count[num];
        int currentFreq = freq[currentCount];
        int newCount = currentCount + 1;
        int newFreq = freq[newCount];

        freq[currentCount]--;
        freq[newCount]++;
        count[num] = newCount;

        if (newCount == num) {
            distinctCount++;
        }
        if (currentCount == num) {
            distinctCount--;
        }
    };

    // Função para remover um elemento do intervalo
    auto remove = [&](int num) {
        int currentCount = count[num];
        int currentFreq = freq[currentCount];
        int newCount = currentCount - 1;
        int newFreq = freq[newCount];

        freq[currentCount]--;
        freq[newCount]++;
        count[num] = newCount;

        if (newCount == num) {
            distinctCount++;
        }
        if (currentCount == num) {
            distinctCount--;
        }
    };

    // Processamento das consultas
    for (int i = 0; i < Q; i++) {
        int L = queries[i].L;
        int R = queries[i].R;
        int index = queries[i].index;

        // Ajustar o intervalo para [L, R]
        while (currentR < R) {
            currentR++;
            add(array[currentR]);
        }
        while (currentR > R) {
            remove(array[currentR]);
            currentR--;
        }
        while (currentL < L) {
            remove(array[currentL]);
            currentL++;
        }
        while (currentL > L) {
            currentL--;
            add(array[currentL]);
        }

        // Calcular a resposta para a consulta atual
        answer[index] = distinctCount;
    }

    // Imprimir as respostas
    for (int i = 0; i < Q; i++) {
        printf("%d\n", answer[i]);
    }

    return 0;
}
