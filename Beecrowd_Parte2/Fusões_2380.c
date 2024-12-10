#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura Union-Find
typedef struct {
    int *parent;
    int *rank;
} UnionFind;

// Função para inicializar a estrutura Union-Find
UnionFind* createUnionFind(int size) {
    UnionFind* uf = (UnionFind*) malloc(sizeof(UnionFind));
    uf->parent = (int*) malloc((size + 1) * sizeof(int));
    uf->rank = (int*) malloc((size + 1) * sizeof(int));

    for (int i = 1; i <= size; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }

    return uf;
}

// Função para encontrar o representante (raiz) de um conjunto
int find(UnionFind* uf, int u) {
    if (uf->parent[u] != u) {
        uf->parent[u] = find(uf, uf->parent[u]); // Path compression
    }
    return uf->parent[u];
}

// Função para unir dois conjuntos
void unionSets(UnionFind* uf, int u, int v) {
    int rootU = find(uf, u);
    int rootV = find(uf, v);

    if (rootU != rootV) {
        // Union by rank
        if (uf->rank[rootU] > uf->rank[rootV]) {
            uf->parent[rootV] = rootU;
        } else if (uf->rank[rootU] < uf->rank[rootV]) {
            uf->parent[rootU] = rootV;
        } else {
            uf->parent[rootV] = rootU;
            uf->rank[rootU]++;
        }
    }
}

// Função principal
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    getchar(); // Consumir o newline após os inteiros

    UnionFind* uf = createUnionFind(N);

    for (int i = 0; i < K; i++) {
        char type;
        int A, B;
        scanf(" %c %d %d", &type, &A, &B);

        if (type == 'F') {
            unionSets(uf, A, B);
        } else if (type == 'C') {
            if (find(uf, A) == find(uf, B)) {
                printf("S\n");
            } else {
                printf("N\n");
            }
        }
    }

    // Liberar memória
    free(uf->parent);
    free(uf->rank);
    free(uf);

    return 0;
}
