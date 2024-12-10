/*
O Professor solicitou que você escreva um programa que converta uma expressão na forma infixa (como usualmente conhecemos) para uma expressão na forma posfixa. Como você sabe, os termos in (no meio) e pos (depois) se referem à posição dos operadores. O programa terá que lidar somente com operadores binários +,-,*,/,^, parênteses, letras e números. Um exemplo seria uma expressão como:
(A*B+2*C^3)/2*A. O programa deve converter esta expressão (infixa) para a expressão posfixa: AB*2C3^*+2/A*
 

Entrada
A primeira linha da entrada contém um valor inteiro N (N < 1000), que indica o número de casos de teste. Cada caso de teste a seguir é uma expressão válida na forma infixa, com até 300 caracteres.

Saída
Para cada caso, apresente a expressão convertida para a forma posfixa.

Exemplo de Entrada	
3
A*2
(A*2+c-d)/2
(2*4/a^b)/(2*c)

Exemplo de Saída
A2*
A2*c+d-2/
24*ab^/2c*/

// OBS.:  O " */ "  de 24*ab^/2c*/ faz parte da saída


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// Define a estrutura para o nó da pilha
typedef struct pilhaNo {
    char valor;             // Valor armazenado no nó da pilha
    struct pilhaNo* abaixo; // Ponteiro para o próximo nó abaixo na pilha
} PilhaNo;                  // typedef para simplificar referências futuras

// Define a estrutura para a pilha
typedef struct pilha {
    int tamanho;    // Tamanho atual da pilha (quantidade de elementos)
    PilhaNo* topo;  // Ponteiro para o topo da pilha (último elemento inserido)
} Pilha;            // typedef para simplificar referências futuras

// Função para inserir um novo elemento no topo da pilha
void push(Pilha* p, char valor) {
    p->tamanho += 1;                        // Aumenta o tamanho da pilha
    PilhaNo* novoTopo = (PilhaNo*) malloc(sizeof(PilhaNo));  // Aloca memória para um novo nó da pilha

    novoTopo->valor = valor;                // Define o valor do novo nó
    novoTopo->abaixo = p->topo;             // Aponta o novo nó para o antigo topo da pilha
    p->topo = novoTopo;                     // Atualiza o topo da pilha para o novo nó
}

// Função para remover o elemento do topo da pilha
void pop(Pilha* p) {
    if (p->tamanho > 0) {                   // Verifica se a pilha não está vazia
        p->tamanho -= 1;                    // Reduz o tamanho da pilha
        PilhaNo* velhoTopo = p->topo;       // Armazena o endereço do antigo topo da pilha
        p->topo = p->topo->abaixo;          // Atualiza o topo da pilha para o nó abaixo do antigo topo
        free(velhoTopo);                    // Libera a memória do antigo topo da pilha
    }
}

// Função para obter o valor do topo da pilha sem remover
char top(Pilha* p) {
    return p->topo->valor;  // Retorna o valor do topo da pilha
}

// Função para obter o tamanho atual da pilha
int size(Pilha* p) {
    return p->tamanho;  // Retorna o tamanho da pilha
}

// Função para verificar se a pilha está vazia
int empty(Pilha* p) {
    return p->tamanho == 0;  // Retorna verdadeiro se a pilha estiver vazia, falso caso contrário
}

// Função para inicializar a pilha
void inicializa(Pilha* p) {
    p->tamanho = 0;     // Inicializa o tamanho da pilha como zero
    p->topo = NULL;     // Define o topo da pilha como nulo
}

// Função para destruir a pilha liberando toda a memória alocada
void destroi(Pilha* p) {
    while (!empty(p)) {  // Enquanto a pilha não estiver vazia
        pop(p);          // Remove o topo da pilha
    }
}

// Função para determinar a precedência de operadores
int precedencia(char operador) {
    switch (operador) {
        case '+':
        case '-':   return 1;  // Baixa precedência para soma e subtração
        case '*':
        case '/':   return 2;  // Alta precedência para multiplicação e divisão
        default:    return 0;  // Outros operadores têm precedência zero (ou não são operadores válidos)
    }
}

int main() {
    int N, tam;
    Pilha p;
    char expressao[301];

    scanf("%d\n", &N);  // Lê o número de expressões

    for (int k = 0; k < N; ++k) {
        scanf("%s\n", expressao);  // Lê a expressão matemática

        inicializa(&p);  // Inicializa a pilha para cada nova expressão

        tam = strlen(expressao);  // Determina o tamanho da expressão
        for (int i = 0; i < tam; ++i) {
            if (isalpha(expressao[i]) || isdigit(expressao[i])) {
                printf("%c", expressao[i]);  // Se for caractere alfabético ou dígito, imprime diretamente
            } else if (expressao[i] == '(' || expressao[i] == '^') {
                push(&p, expressao[i]);  // Se for '(' ou '^', empilha na pilha
            } else if (expressao[i] == ')') {
                while (!empty(&p) && top(&p) != '(') {
                    printf("%c", top(&p));  // Desempilha e imprime até encontrar '('
                    pop(&p);
                }

                if (!empty(&p))  pop(&p);  // Remove '(' da pilha, se presente
            } else {
                while (!empty(&p) && top(&p) != '(' && precedencia(expressao[i]) <= precedencia(top(&p))) {
                    printf("%c", top(&p));  // Desempilha e imprime enquanto a precedência for maior ou igual
                    pop(&p);
                }

                push(&p, expressao[i]);  // Empilha o operador atual
            }
        }

        while (!empty(&p)) {
            printf("%c", top(&p));  // Desempilha e imprime qualquer operador restante na pilha
            pop(&p);
        }
        printf("\n");  // Nova linha para a próxima expressão
    }

    return 0;
}
