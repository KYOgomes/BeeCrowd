/*
Resolva o exercicio em C:
Você lembra daquela estação de trem da cidade PopPush? Apenas para relembrar, existe uma estação de trem em um país incrivelmente acidentado. Além disso, a estação foi construída no século passado e infelizmente os fundos eram muito limitados. Em um determinado trecho foi possível construir apenas uma pista e, a solução encontrada para transportar as cargas nos dois sentidos foi construir uma estação que permitisse desconectar os vagões de uma locomotiva e conectar em outra, que iria em outro sentido.

Cada trem que chega na direção A é manobrado e seus vagões continuam na direção B, reorganizados conforme o chefe da estação deseja. Ao chegar pelo lado A, cada vagão é desconectado e vai até a estação e depois segue para a direção B, para ser conectado na segunda locomotiva. Você pode desconectar quantos trens deseja na estação, mas o vagão que entra na estação só pode sair pelo lado B e uma vez que ele sai, não pode mais entrar novamente.

Todos vagões são identificados pelas letras minúsculas (a até z). Isto significa 26 vagões no máximo. O chefe da organização dos vagões precisa agora que você ajude a resolver para ele, através de um programa, qual a sequência de movimentos é necessária para obter a saída desejada após a entrada na estação, seguindo para a direção B. O movimento de entrada e saída da estação é descrito respectivamente pelas letras I e R (Insere e Remove). Utilizando a figura dada como exemplo, a entrada e,t,d,a para uma saída desejada d,a,t,e, resulta nos movimentos I,I,I,R,I,R,R,R

Entrada
A entrada consiste em vários casos de teste, onde cada caso de teste é composto por 3 linhas. A primeira das 3 linhas contém um número inteiro N que representa o número total de vagões. A segunda linha contém a sequência dos vagões que vêm do lado A e a Terceira linha contém a sequência que o chefe de organização deseja como saída para o lado B. A última linha de entrada contém apenas 0, indicando o fim da entrada.

Saída
O arquivo de saída contém a quantidade de linhas correspondente ao número de casos de teste de entrada. Cada linha de saída contém uma sequência de I e R conforme o exemplo. Se não for possível mostrar a saída, as operações devem ser interrompidas e a mensagem "Impossible" deve ser impressa, com um espaço após a sequência.

Exemplo de Entrada	
4
e t d a
d a t e
5
o s t a p
p a t o s
0

Exemplo de Saída
IIIRIRRR
IIIIIRRR Impossible
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

typedef struct {
    char stack[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->stack[++s->top] = c;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->stack[s->top--];
    }
    return '\0';
}

int main() {
    int N;
    while (1) {
        scanf("%d", &N);
        if (N == 0) {
            break;
        }

        char input[N + 1], output[N + 1];

        // Reading input and output sequences
        for (int i = 0; i < N; i++) {
            scanf(" %c", &input[i]);
        }
        input[N] = '\0';

        for (int i = 0; i < N; i++) {
            scanf(" %c", &output[i]);
        }
        output[N] = '\0';

        Stack station;
        init(&station);

        int inIndex = 0, outIndex = 0;
        char result[2 * N + 1];
        int resIndex = 0;

        int possible = 1;

        while (outIndex < N) {
            if (station.top >= 0 && station.stack[station.top] == output[outIndex]) {
                result[resIndex++] = 'R';
                pop(&station);
                outIndex++;
            } else if (inIndex < N) {
                result[resIndex++] = 'I';
                push(&station, input[inIndex]);
                inIndex++;
            } else {
                possible = 0;
                break;
            }
        }

        if (possible) {
            result[resIndex] = '\0';
            printf("%s\n", result);
        } else {
            result[resIndex] = '\0';
            printf("%s Impossible\n", result);
        }
    }

    return 0;
}
