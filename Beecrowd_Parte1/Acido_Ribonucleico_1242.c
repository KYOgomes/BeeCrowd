#include <stdio.h>
#include <stdbool.h>

// Definição da estrutura da pilha
#define MAX 1000 // Tamanho máximo da pilha

typedef struct {
    char items[MAX];
    int top;
} Stack;

// Função para inicializar a pilha
void init(Stack *s) {
    s->top = -1;
}

// Função para verificar se a pilha está vazia
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Função para verificar se a pilha está cheia
bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Função para empilhar um elemento
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->items[++s->top] = c;
    }
}

// Função para desempilhar um elemento
void pop(Stack *s) {
    if (!isEmpty(s)) {
        s->top--;
    }
}

// Função para obter o elemento no topo da pilha
char top(Stack *s) {
    return s->items[s->top];
}

// Função para verificar se dois caracteres formam um par válido
bool match(char a, char b) {
    if (a > b) {
        char temp = a;
        a = b;
        b = temp;
    }
    return (a == 'B' && b == 'S') || (a == 'C' && b == 'F');
}

int main() {
    char acid[MAX]; // String para armazenar o ácido ribonucleico
    while (scanf("%s", acid) != EOF) {
        Stack st;
        init(&st);
        int cnt = 0;
        for (int i = 0; acid[i] != '\0'; i++) {
            if (!isEmpty(&st) && match(top(&st), acid[i])) {
                pop(&st);
                cnt++;
            } else {
                push(&st, acid[i]);
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
