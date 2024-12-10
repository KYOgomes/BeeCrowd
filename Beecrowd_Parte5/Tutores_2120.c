#include <stdio.h>
#include <stdlib.h>

// Estrutura para o nó da árvore binária de busca
typedef struct Node {
    int matricula;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* newNode(int matricula) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->matricula = matricula;
    node->left = node->right = NULL;
    return node;
}

// Função para inserir um novo nó na árvore e retornar o tutor
Node* insert(Node* root, int matricula, int* tutor) {
    Node* current = root;
    Node* parent = NULL;
    while (current != NULL) {
        parent = current;
        if (matricula < current->matricula) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (matricula < parent->matricula) {
        parent->left = newNode(matricula);
    } else {
        parent->right = newNode(matricula);
    }
    *tutor = parent->matricula;
    return parent->left ? parent->left : parent->right;
}

int main() {
    int N, Q;
    scanf("%d", &N);

    int* matriculas = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &matriculas[i]);
    }

    scanf("%d", &Q);
    int* queries = (int*)malloc(Q * sizeof(int));
    for (int i = 0; i < Q; i++) {
        scanf("%d", &queries[i]);
    }

    int* tutors = (int*)malloc(N * sizeof(int));
    Node* root = newNode(matriculas[0]);
    tutors[0] = -1; // O primeiro aluno não possui tutor

    for (int i = 1; i < N; i++) {
        int tutor;
        insert(root, matriculas[i], &tutor);
        tutors[i] = tutor;
    }

    for (int i = 0; i < Q; i++) {
        printf("%d\n", tutors[queries[i] - 1]);
    }

    free(matriculas);
    free(queries);
    free(tutors);
    return 0;
}
