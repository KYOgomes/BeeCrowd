/*
Raju e Meena adoram jogar um jogo diferente com pequenas peças de mármores, chamados Marbles. Eles têm um monte destas peças com números escritos neles. No início, Raju colocaria estes pequenos mármores um após outro em ordem ascendente de números escritos neles. Então Meena gostaria de pedir a Raju para encontrar o primeiro mármore com um certo número. Ele deveria contar 1...2...3. Raju ganha um ponto por cada resposta correta e Meena ganha um ponto se Raju falha. Depois de um número fixo de tentativas, o jogo termina e o jogador com o máximo de pontos vence. Hoje é sua chance de jogar com Raju. Sendo um/a cara esperto/a, você tem em seu favor o computador. Mas não subestime Meena, ela escreveu um programa para monitorar quanto tempo você levará para dar todas as respostas. Portanto, agora escreva o programa, que ajudará você em seu desafio com Raju.

Entrada
A entrada contém vários casos de teste, mas o total de casos é menor do que 65. Cada caso de teste inicia com dois inteiros: N que é o número de mármores e Q que é o número de consultas que Meena deseja fazer. As próximas N linhas conterão os números escritos em cada um dos N mármores. Os números destes mármores não tem qualquer ordem em particular. As seguintes Q linhas irão conter Q consultas. Tenha certeza, nenhum dos números da entrada é maior do que 10000 e nenhum deles é negativo.
A entrada é terminada por um caso de teste onde N = 0 e Q = 0.
Saída
Para cada caso de teste de saída deve haver um número serial do caso de teste. Para cada consulta, escreva uma linha de saída. O formato desta linha dependerá se o número consultado estiver ou não escrito em um dos mármores. Os dois diferentes formatos são descritos abaixo:
'x found at y', se o primeiro marble x foi encontrado na posição y. Posições são numeradas de 1, 2,...  a N.
'x not found', se o marble com o número x não estiver presente.


Exemplo de Entrada	
4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0
Exemplo de Saída
CASE# 1:
5 found at 4
CASE# 2:
2 not found
3 found at 3
*/

#include <stdlib.h>
#include <stdio.h>

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int pesquisaBinaria(int *v, int n, int valor)
{
    int inicio = 0, fim = n, meio;

    while (inicio < fim)
    {
        meio = (inicio + fim) / 2;

        if (v[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio;
    }

    return v[inicio] == valor ? inicio + 1 : -1;
}

int main()
{
    int *marmores;
    int T, N, Q, consulta, resposta;

    T = 1;
    while (scanf("%d %d", &N, &Q))
    {
        if (!N && !Q)
            break;

        marmores = (int *)malloc(sizeof(int) * N);
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &marmores[i]);
        }

        qsort(marmores, N, sizeof(int), comp);

        printf("CASE# %d:\n", T++);
        for (int i = 0; i < Q; ++i)
        {
            scanf("%d", &consulta);

            resposta = pesquisaBinaria(marmores, N, consulta);

            if (resposta == -1)
                printf("%d not found\n", consulta);
            else
                printf("%d found at %d\n", consulta, resposta);
        }

        free(marmores);
    }

    return 0;
}