#include <stdio.h>
#include <stdlib.h>

#define MAX 101

// Lista de adjacência
int adjList[MAX][MAX];
// Número de vizinhos de cada nó
int neighborsCount[MAX];
// Array de visitados
int visited[MAX];

// Função de busca em profundidade (DFS)
void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < neighborsCount[node]; i++) {
        int neighbor = adjList[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    
    // Inicializando a lista de adjacências e o array de vizinhos
    for (int i = 1; i <= N; i++) {
        neighborsCount[i] = 0;
    }
    
    // Lendo as ligações e populando a lista de adjacências
    for (int i = 0; i < L; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        adjList[X][neighborsCount[X]++] = Y;
        adjList[Y][neighborsCount[Y]++] = X;
    }
    
    // Inicializando o array de visitados
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
    
    // Realizando a DFS a partir do nó 1
    dfs(1);
    
    // Verificando se todos os nós foram visitados
    int completo = 1;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            completo = 0;
            break;
        }
    }
    
    // Imprimindo o resultado
    if (completo) {
        printf("COMPLETO\n");
    } else {
        printf("INCOMPLETO\n");
    }
    
    return 0;
}
