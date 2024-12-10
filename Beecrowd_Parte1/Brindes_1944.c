#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo um tamanho máximo para as strings
#define MAX_LEN 100

typedef struct Node {
    char data[MAX_LEN];
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Função para inverter uma string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Função para adicionar um nó no início da lista
void addFirst(Node** head, const char* data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Função para remover o primeiro nó da lista
void removeFirst(Node** head) {
    if (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Função para reinicializar a lista com a lista inicial
void resetList(Node** head, Node* initial) {
    while (*head != NULL) {
        removeFirst(head);
    }
    Node* current = initial;
    while (current != NULL) {
        addFirst(head, current->data);
        current = current->next;
    }
}

int main() {
    // Inicializando a lista inicial
    Node* initial = createNode("E C A F");
    Node* painel = createNode("E C A F");

    int brindes = 0;
    int n;
    
    // Leitura do número de iterações
    scanf("%d", &n);
    getchar();  // Consumir a quebra de linha após o número

    for (int i = 0; i < n; i++) {
        char a[MAX_LEN];
        fgets(a, MAX_LEN, stdin);
        a[strcspn(a, "\n")] = '\0';  // Remover a nova linha

        if (strcmp(a, painel->data) == 0) {
            removeFirst(&painel);
            brindes++;
            if (painel == NULL) {
                resetList(&painel, initial);
            }
        } else {
            reverseString(a);
            addFirst(&painel, a);
        }
    }

    printf("%d\n", brindes);

    // Limpar a memória alocada
    while (initial != NULL) {
        removeFirst(&initial);
    }
    while (painel != NULL) {
        removeFirst(&painel);
    }

    return 0;
}
