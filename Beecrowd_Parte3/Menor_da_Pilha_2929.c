#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERATIONS 1000005
#define MAX_VALUE 1000000009

// Estrutura para representar uma pilha
typedef struct {
    int data[MAX_OPERATIONS];  // Array para armazenar os valores da pilha
    int top;                   // Índice do topo da pilha
} Stack;

// Função para inicializar a pilha
void init(Stack *stack) {
    stack->top = -1;  // Inicializa o topo como -1 indicando pilha vazia
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

// Função para empilhar um elemento na pilha
void push(Stack *stack, int value) {
    stack->top++;
    stack->data[stack->top] = value;
}

// Função para desempilhar um elemento da pilha
int pop(Stack *stack) {
    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

// Função para consultar o menor elemento da pilha
int min(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;  // Caso a pilha esteja vazia
    } else {
        return stack->data[stack->top];  // Retorna o topo da pilha (menor valor)
    }
}

int main() {
    // Inicializa a estrutura da pilha
    Stack stack;
    init(&stack);
    
    int N;
    scanf("%d", &N);
    getchar(); // Captura o \n após o número N
    
    char operation[5];
    int value;
    
    while (N--) {
        scanf("%s", operation);
        
        if (strcmp(operation, "PUSH") == 0) {
            scanf("%d", &value);
            getchar(); // Captura o \n após o valor
            push(&stack, value);
        } else if (strcmp(operation, "POP") == 0) {
            getchar(); // Captura o \n após POP
            if (!isEmpty(&stack)) {
                pop(&stack);
            }
        } else if (strcmp(operation, "MIN") == 0) {
            getchar(); // Captura o \n após MIN
            if (isEmpty(&stack)) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", min(&stack));
            }
        }
    }
    
    return 0;
}
