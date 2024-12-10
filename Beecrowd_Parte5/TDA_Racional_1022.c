/*
A tarefa aqui neste problema é ler uma expressão matemática na forma de dois números Racionais (numerador / denominador) e apresentar o resultado da operação. Cada operando ou operador é separado por um espaço em branco. A sequência de cada linha que contém a expressão a ser lida é: número, caractere, número, caractere, número, caractere, número. A resposta deverá ser apresentada e posteriormente simplificada. Deverá então ser apresentado o sinal de igualdade e em seguida a resposta simplificada. No caso de não ser possível uma simplificação, deve ser apresentada a mesma resposta após o sinal de igualdade.

Considerando N1 e D1 como numerador e denominador da primeira fração, segue a orientação de como deverá ser realizada cada uma das operações:
Soma: (N1*D2 + N2*D1) / (D1*D2)
Subtração: (N1*D2 - N2*D1) / (D1*D2)
Multiplicação: (N1*N2) / (D1*D2)
Divisão: (N1/D1) / (N2/D2), ou seja (N1*D2)/(N2*D1)
Entrada
A entrada contem vários casos de teste. A primeira linha de cada caso de teste contem um inteiro N (1 ≤ N ≤ 1*104), indicando a quantidade de casos de teste que devem ser lidos logo a seguir. Cada caso de teste contém um valor racional X (1 ≤ X ≤ 1000), uma operação (-, +, * ou /) e outro valor racional Y (1 ≤ Y ≤ 1000).

Saída
A saída consiste em um valor racional, seguido de um sinal de igualdade e outro valor racional, que é a simplificação do primeiro valor. No caso do primeiro valor não poder ser simplificado, o mesmo deve ser repetido após o sinal de igualdade.

Exemplo de Entrada	
4
1 / 2 + 3 / 4
1 / 2 - 3 / 4
2 / 3 * 6 / 6
1 / 2 / 3 / 4

Exemplo de Saída
10/8 = 5/4
-2/8 = -1/4
12/18 = 2/3
4/6 = 2/3

*/

#include <stdio.h>

// Definição da estrutura Fracao com typedef para simplificar o uso
typedef struct {
    int num, den;
} Fracao;

// Função para realizar a soma de duas frações
Fracao soma(Fracao f1, Fracao f2)
{
    Fracao retorno;

    // Calcula o numerador da fração resultante
    retorno.num = f1.num * f2.den + f2.num * f1.den;
    // Calcula o denominador da fração resultante
    retorno.den = f1.den * f2.den;

    return retorno;
}

// Função para realizar a subtração de duas frações
Fracao subtracao(Fracao f1, Fracao f2)
{
    Fracao retorno;

    // Calcula o numerador da fração resultante
    retorno.num = f1.num * f2.den - f2.num * f1.den;
    // Calcula o denominador da fração resultante
    retorno.den = f1.den * f2.den;

    return retorno;
}

// Função para realizar a multiplicação de duas frações
Fracao multiplicacao(Fracao f1, Fracao f2)
{
    Fracao retorno;

    // Calcula o numerador da fração resultante
    retorno.num = f1.num * f2.num;
    // Calcula o denominador da fração resultante
    retorno.den = f1.den * f2.den;

    return retorno;
}

// Função para realizar a divisão de duas frações
Fracao divisao(Fracao f1, Fracao f2)
{
    Fracao retorno;

    // Calcula o numerador da fração resultante
    retorno.num = f1.num * f2.den;
    // Calcula o denominador da fração resultante
    retorno.den = f2.num * f1.den;

    return retorno;
}

// Função para calcular o Máximo Divisor Comum (MDC) usando o algoritmo de Euclides
int MDC(int a, int b)
{
    return (b == 0) ? a : MDC(b, a % b);
}

// Função para simplificar uma fração para forma irredutível
Fracao irredutivel(Fracao f)
{
    // Calcula o MDC dos números para simplificação
    int mdc = (f.num < 0) ? MDC(-f.num, f.den) : MDC(f.num, f.den);

    // Simplifica a fração dividindo numerador e denominador pelo MDC
    f.num /= mdc;
    f.den /= mdc;

    return f;
}

int main()
{
    int N;
    char operador;
    Fracao f1, f2, resultado;

    // Leitura do número de operações a serem realizadas
    scanf("%d\n", &N);

    // Loop para processar cada operação
    for (int i = 0; i < N; ++i)
    {
        // Leitura das duas frações e do operador
        scanf("%d / %d %c %d / %d\n", &f1.num, &f1.den, &operador, &f2.num, &f2.den);

        // Seleção da operação com base no operador lido
        switch (operador)
        {
        case '+':
            resultado = soma(f1, f2);
            break;
        case '-':
            resultado = subtracao(f1, f2);
            break;
        case '*':
            resultado = multiplicacao(f1, f2);
            break;
        case '/':
            resultado = divisao(f1, f2);
            break;
        }

        // Impressão da fração resultante antes da simplificação
        printf("%d/%d = ", resultado.num, resultado.den);
        // Simplifica a fração resultante
        resultado = irredutivel(resultado);
        // Impressão da fração resultante simplificada
        printf("%d/%d\n", resultado.num, resultado.den);
    }

    return 0;
}
