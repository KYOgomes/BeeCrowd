#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura Problema
typedef struct {
    int criticidade;
    char tipo; // 'V' para vida, 'D' para disciplina
} Problema;

// Função de comparação para ordenar os Problemas
int comparaProblemas(const void *a, const void *b) {
    Problema *p1 = (Problema *)a;
    Problema *p2 = (Problema *)b;
    
    // Problemas de vida ('V') devem vir antes
    if (p1->tipo == 'V' && p2->tipo == 'D') {
        return -1; // p1 vem antes de p2
    } else if (p1->tipo == 'D' && p2->tipo == 'V') {
        return 1; // p2 vem antes de p1
    } else {
        // Mesmo tipo ('V' ou 'D'), ordenar por criticidade
        return p2->criticidade - p1->criticidade; // decrescente
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M); // número de linhas e colunas
    
    // Declaração da matriz de problemas
    Problema matriz[N][M];
    
    // Leitura da matriz de problemas
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char tipo;
            int criticidade;
            scanf("%d%c", &criticidade, &tipo);
            matriz[i][j].criticidade = criticidade;
            matriz[i][j].tipo = tipo;
        }
    }
    
    // Unindo os problemas em uma lista para ordenação
    Problema problemas[N * M];
    int index = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            problemas[index] = matriz[i][j];
            index++;
        }
    }
    
    // Ordenando os problemas utilizando qsort da biblioteca padrão
    qsort(problemas, N * M, sizeof(Problema), comparaProblemas);
    
    // Impressão dos problemas ordenados
    for (int i = 0; i < N * M; i++) {
        printf("%d%c\n", problemas[i].criticidade, problemas[i].tipo);
    }
    
    return 0;
}
