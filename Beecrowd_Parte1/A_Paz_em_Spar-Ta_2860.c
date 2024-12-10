#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Estrutura para representar um nó da lista de adjacências
typedef struct Node {
    int dest;
    int weight;
    struct Node* next;
} Node;

// Estrutura para representar um grafo
typedef struct Graph {
    int V; // Número de vértices
    Node** adjList; // Lista de adjacências
} Graph;

// Função para criar um novo nó da lista de adjacências
Node* createNode(int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com V vértices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*));
    
    for (int i = 0; i < V; ++i)
        graph->adjList[i] = NULL;
    
    return graph;
}

// Função para adicionar uma aresta não direcionada ao grafo
void addEdge(Graph* graph, int src, int dest, int weight) {
    // Adiciona aresta de src para dest
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Adiciona aresta de dest para src
    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Função para liberar a memória alocada para o grafo
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->V; ++i) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph);
}

// Função auxiliar para o algoritmo de Prim
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Algoritmo de Prim para encontrar a Árvore Geradora Mínima (AGM)
long long primMST(Graph* graph) {
    int V = graph->V;
    int parent[V]; // Array para armazenar a árvore geradora mínima
    int key[V];    // Chaves usadas para pegar o peso mínimo de corte

    bool mstSet[V]; // Para representar os vértices incluídos na árvore geradora mínima

    // Inicializa todas as chaves como INFINITO
    // e mstSet[] como falso
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // A chave do primeiro vértice é sempre 0
    key[0] = 0;     // Fazemos o primeiro vértice como raiz da AGM
    parent[0] = -1; // Primeiro vértice não tem pai

    // O grafo contém V vértices, então existem V-1 arestas para adicionar à AGM
    for (int count = 0; count < V - 1; count++) {
        // Escolhe a chave mínima do vértice ainda não incluído
        int u = minKey(key, mstSet, V);

        // Inclui o vértice escolhido na árvore geradora mínima
        mstSet[u] = true;

        // Atualiza as chaves e os pais dos vértices adjacentes do vértice escolhido
        Node* iter = graph->adjList[u];
        while (iter != NULL) {
            int v = iter->dest;
            int weight = iter->weight;

            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
            iter = iter->next;
        }
    }

    // Calcula a maior distância na AGM entre qualquer vértice e seu representante mais próximo
    long long maxDistance = 0;
    for (int i = 1; i < V; i++) {
        maxDistance += key[i];
    }

    return maxDistance;
}

int main() {
    int t; // Quantidade de casos de teste
    scanf("%d", &t);

    while (t--) {
        int n; // Número de cidades
        scanf("%d", &n);

        // Cria o grafo com n vértices
        Graph* graph = createGraph(n);

        // Leitura das arestas do grafo
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            addEdge(graph, a, b, 1); // Todas as arestas têm peso 1
        }

        int q; // Número de novas estradas a serem consideradas
        scanf("%d", &q);

        // Para cada nova estrada
        for (int i = 0; i < q; i++) {
            int u, v;
            scanf("%d %d", &u, &v);

            // Adiciona temporariamente a nova aresta ao grafo
            addEdge(graph, u, v, 1);

            // Calcula a Árvore Geradora Mínima (AGM) e a maior distância
            long long maxDistance = primMST(graph);

            // Remove a nova aresta do grafo para o próximo cálculo
            Node* iter = graph->adjList[u];
            while (iter != NULL) {
                if (iter->dest == v) {
                    Node* temp = iter;
                    iter = iter->next;
                    free(temp);
                    graph->adjList[u] = iter;
                    break;
                }
                iter = iter->next;
            }

            iter = graph->adjList[v];
            while (iter != NULL) {
                if (iter->dest == u) {
                    Node* temp = iter;
                    iter = iter->next;
                    free(temp);
                    graph->adjList[v] = iter;
                    break;
                }
                iter = iter->next;
            }

            // Imprime a maior distância calculada
            printf("%lld\n", maxDistance);
        }

        // Libera o grafo após cada caso de teste
        freeGraph(graph);

        if (t > 0) {
            printf("\n"); // Linha em branco entre os casos de teste
        }
    }

    return 0;
}
