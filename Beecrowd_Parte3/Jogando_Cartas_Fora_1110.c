/*
Dada uma pilha de n cartas enumeradas de 1 até n com a carta 1 no topo e a carta n na base. A seguinte operação é
realizada enquanto tiver 2 ou mais cartas na pilha.

Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha.

Sua tarefa é encontrar a sequência de cartas descartadas e a última carta remanescente.

Cada linha de entrada (com exceção da última) contém um número n ≤ 50. A última linha contém 0 e não deve ser processada. Cada número de entrada produz duas linhas de saída. A primeira linha apresenta a sequência de cartas descartadas e a segunda linha apresenta a carta remanescente.

Entrada
A entrada consiste em um número indeterminado de linhas contendo cada uma um valor de 1 até 50. A última linha contém o valor 0.

Saída
Para cada caso de teste, imprima duas linhas. A primeira linha apresenta a sequência de cartas descartadas, 
cada uma delas separadas por uma vírgula e um espaço. A segunda linha apresenta o número da carta que restou. Nenhuma linha tem espaços extras no início ou no final. Veja exemplo para conferir o formato esperado.

Exemplo de Entrada	
7
19
10
6
0

Exemplo de Saída
Discarded cards: 1, 3, 5, 7, 4, 2
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 4, 8, 12, 16, 2, 10, 18, 14
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
Discarded cards: 1, 3, 5, 2, 6
Remaining card: 4
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct dequeNo {
    int valor;
    struct dequeNo *anterior, *proximo;
} DequeNo;

typedef struct deque {
    int tamanho;
    struct dequeNo *frente, *tras;
} Deque;


void push_front(Deque *d, int valor)
{
    d->tamanho += 1;
    DequeNo *novaFrente = (DequeNo *)malloc(sizeof(DequeNo));

    novaFrente->valor = valor;
    novaFrente->proximo = d->frente;
    if (d->frente != NULL)
        d->frente->anterior = novaFrente;
    d->frente = novaFrente;
    if (d->tras == NULL)
        d->tras = d->frente;
}

void push_back(Deque *d, int valor)
{
    d->tamanho += 1;
    DequeNo *novoTras = (DequeNo *)malloc(sizeof(DequeNo));

    novoTras->valor = valor;
    novoTras->anterior = d->tras;
    if (d->tras != NULL)
        d->tras->proximo = novoTras;
    d->tras = novoTras;
    if (d->frente == NULL)
        d->frente = d->tras;
}

void pop_front(Deque *d)
{
    if (d->tamanho > 0)
    {
        d->tamanho -= 1;
        DequeNo *velhaFrente = d->frente;
        d->frente = d->frente->proximo;
        free(velhaFrente);
    }
}

void pop_back(Deque *d)
{
    if (d->tamanho > 0)
    {
        d->tamanho -= 1;
        DequeNo *velhoTras = d->tras;
        d->tras = d->tras->anterior;
        free(velhoTras);
    }
}

int front(Deque *d)
{
    return d->frente->valor;
}

int back(Deque *d)
{
    return d->tras->valor;
}

int size(Deque *d)
{
    return d->tamanho;
}

int empty(Deque *d)
{
    return d->tamanho == 0;
}

void inicializa(Deque *d)
{
    d->tamanho = 0;
    d->frente = NULL;
    d->tras = NULL;
}

void destroi(Deque *d)
{
    while (!empty(d))
    {
        pop_front(d);
    }
}

int main()
{
    int n, first;
    Deque cartas;

    while (scanf("%d", &n))
    {
        if (!n)
            break;

        inicializa(&cartas);

        for (int i = 1; i <= n; ++i)
        {
            push_back(&cartas, i);
        }

        first = 1;
        printf("Discarded cards: ");
        while (size(&cartas) > 1)
        {
            if (!first)
                printf(", ");
            else
                first = 0;

            printf("%d", front(&cartas));

            pop_front(&cartas);
            push_back(&cartas, front(&cartas));
            pop_front(&cartas);
        }
        printf("\nRemaining card: %d\n", front(&cartas));

        destroi(&cartas);
    }

    return 0;
}