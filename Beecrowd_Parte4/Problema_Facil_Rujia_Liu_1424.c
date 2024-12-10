#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó para a lista ligada
typedef struct Node {
    int index;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar um índice à lista de ocorrências
void addOccurrence(Node** occurrences, int value, int index) {
    Node* newNode = createNode(index);
    if (occurrences[value] == NULL) {
        occurrences[value] = newNode;
    } else {
        Node* current = occurrences[value];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Função para encontrar a k-ésima ocorrência
int findKthOccurrence(Node** occurrences, int value, int k) {
    Node* current = occurrences[value];
    while (current != NULL && --k > 0) {
        current = current->next;
    }
    if (current != NULL) {
        return current->index;
    }
    return 0;
}

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m) != EOF) {
        int* array = (int*)malloc(n * sizeof(int));
        Node** occurrences = (Node**)calloc(1000001, sizeof(Node*));
        
        // Ler o vetor e armazenar as ocorrências
        for (int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
            addOccurrence(occurrences, array[i], i + 1);
        }
        
        // Processar as consultas
        for (int i = 0; i < m; i++) {
            int k, v;
            scanf("%d %d", &k, &v);
            printf("%d\n", findKthOccurrence(occurrences, v, k));
        }
        
        // Liberar memória
        free(array);
        for (int i = 0; i <= 1000000; i++) {
            Node* current = occurrences[i];
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                free(temp);
            }
        }
        free(occurrences);
    }
    
    return 0;
}