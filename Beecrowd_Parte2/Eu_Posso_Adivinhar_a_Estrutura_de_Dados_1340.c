/*
Existe uma estrutura de dados do tipo sacola, suportando duas operações:

1 x
Jogue um elemento x na sacola.

2
Tire um elemento da sacola.

Dada uma sequencia de operações que retornam valores, você vai adivinhar a estrutura de dados. É uma pilha (último-dentro, primeiro-fora), uma fila (primeiro-dentro, primeiro-fora), uma fila de prioridade (sempre tire os elementos grandes por primeiro) ou qualquer outra coisa que você dificilmente consegue imaginar!

Entrada
Existem muitos casos de testes. Cada caso de teste começa com a linha contando um único inteiro n (1 <= n <= 1000). Cada uma das seguintes n linhas é um comando do tipo 1, ou um número inteiro 2, seguido de um número inteiro x. Isso significa que depois de executar um comando do tipo 2, obtemos um elemento x sem erros. O valor de x é sempre um número inteiro, positivo e não maior do que 100. O final da entrada é determinado pelo final do arquivo (EOF). O tamanho do arquivo de entrada não excede 1MB.

Saída
Para cada caso de teste, mostre um dos seguintes:

stack
É definitivamente uma pilha.

queue
É definitivamente uma fila.

priority queue
É definitivamente uma fila de prioridade.

impossible
Não pode ser uma pilha, uma fila ou uma fila de prioridade.

not sure
Pode ser mais de uma das três estruturas mencionadas acima.


Exemplo de Entrada	
6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4

Exemplo de Saída
queue
not sure
impossible
stack
priority queue

*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_N 1005

typedef struct {
    int dados[MAX_N];
    int topo;
} Pilha;

typedef struct {
    int dados[MAX_N];
    int inicio, fim;
} Fila;

typedef struct {
    int dados[MAX_N];
    int tamanho;
} FilaPrioridade;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

void inicializarFilaPrioridade(FilaPrioridade *fp) {
    fp->tamanho = 0;
}

void empilhar(Pilha *p, int numero) {
    p->dados[++p->topo] = numero;
}

void desempilhar(Pilha *p) {
    p->topo--;
}

int topo(Pilha *p) {
    return p->dados[p->topo];
}

void enfileirar(Fila *f, int numero) {
    f->dados[f->fim++] = numero;
}

void desenfileirar(Fila *f) {
    f->inicio++;
}

int frente(Fila *f) {
    return f->dados[f->inicio];
}

void enfileirarPrioridade(FilaPrioridade *fp, int numero) {
    fp->dados[fp->tamanho++] = numero;
}

void desenfileirarPrioridade(FilaPrioridade *fp) {
    int maxIndex = 0;
    for (int i = 1; i < fp->tamanho; ++i) {
        if (fp->dados[i] > fp->dados[maxIndex]) {
            maxIndex = i;
        }
    }
    for (int i = maxIndex; i < fp->tamanho - 1; ++i) {
        fp->dados[i] = fp->dados[i + 1];
    }
    fp->tamanho--;
}

int frentePrioridade(FilaPrioridade *fp) {
    int maxIndex = 0;
    for (int i = 1; i < fp->tamanho; ++i) {
        if (fp->dados[i] > fp->dados[maxIndex]) {
            maxIndex = i;
        }
    }
    return fp->dados[maxIndex];
}

int main() {
    bool p, f, fp;
    Pilha pilha;
    Fila fila;
    FilaPrioridade filaPrioridade;
    int n, operacao, numero;

    while (scanf("%d", &n) == 1) {
        inicializarPilha(&pilha);
        inicializarFila(&fila);
        inicializarFilaPrioridade(&filaPrioridade);

        p = true, f = true, fp = true;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &operacao, &numero);

            if (operacao == 1) {
                if (p) empilhar(&pilha, numero);
                if (f) enfileirar(&fila, numero);
                if (fp) enfileirarPrioridade(&filaPrioridade, numero);
            } else {
                if (p) {
                    if (pilha.topo == -1 || topo(&pilha) != numero)
                        p = false;
                    else
                        desempilhar(&pilha);
                }

                if (f) {
                    if (fila.inicio == fila.fim || frente(&fila) != numero)
                        f = false;
                    else
                        desenfileirar(&fila);
                }

                if (fp) {
                    if (filaPrioridade.tamanho == 0 || frentePrioridade(&filaPrioridade) != numero)
                        fp = false;
                    else
                        desenfileirarPrioridade(&filaPrioridade);
                }
            }
        }

        if (p && !f && !fp)
            printf("stack\n");
        else if (!p && f && !fp)
            printf("queue\n");
        else if (!p && !f && fp)
            printf("priority queue\n");
        else if (!p && !f && !fp)
            printf("impossible\n");
        else
            printf("not sure\n");
    }

    return 0;
}
