/*
O San Antonio é o time da cidade na NBA. Já foi algumas vezes campeão de sua conferência e revelou vários excelentes jogadores.

Em um campeonato de basquete os times jogam todos entre si em turno único. A vitória vale dois pontos e a derrota vale um ponto (não há empates no basquete). Havendo empates na pontuação do campeonato ﬁca na frente o time com melhor “cesta average” que é dado pela razão entre o número de pontos marcados pelo time dividido pelo número de pontos recebidos (na improvável hipótese de um time vencer todos os jogos do campeonato sem levar cestas seu cesta average é dado pelo número de pontos marcados). Persistindo o empate, leva vantagem quem marcou mais pontos. Ainda havendo empate, o time com o menor número de inscrição na liga ﬁca na frente.

Sua tarefa neste problema é fazer um programa que recebe os resultados dos jogos de um campeonato e imprime a classiﬁcação ﬁnal.

Entrada
São dadas várias instâncias. Para cada instância é dada o número 0 ≤ n ≤ 100 de times no campeonato. O valor n = 0 indica o ﬁm dos dados. A seguir vêm n (n−1) / 2 linhas indicando os resultados das partidas. Em cada linha são dados quatro inteiros x, y, z e w. Os inteiros x e z pertencem ao conjunto {1, 2, . . . , n} e representam os números de inscrição dos times na liga. Os inteiros y e w são, respectivamente, os números de pontos do time x e do time z na partida descrita.

Saída
Para cada instância solucionada, você deverá imprimir um identiﬁcador "Instancia h" em que h é um número inteiro, sequencial e crescente a partir de 1. Na linha seguinte, deve ser impressa a permutação dos inteiros 1 a n da classiﬁcação do campeonato.

Obs: Um espaço em branco deve ser impresso entre cada um desses inteiros e uma linha em branco deve deve ser impressa entre as saídas de dois casos de teste.

Exemplo de Entrada	
5
1 102 2 62
1 128 3 127
1 144 4 80
1 102 5 101
2 62 3 61
2 100 4 80
2 88 5 82
3 79 4 90
3 87 5 100
4 110 5 99
0

Exemplo de Saída
Instancia 1
1 2 4 5 3

*/
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Jogo
typedef struct {
    int time;
    int marcados;
    int recebidos;
} Jogo;

// Definição da estrutura Time
typedef struct {
    int time;
    int pontos;
    int marcados;
    int recebidos;
    float media;
} Time;

// Função para calcular a média
float calcular_media(int marcados, int recebidos) {
    return (recebidos == 0) ? (float)marcados : (float)marcados / recebidos;
}

// Função de comparação para ordenação
int comparar_times(const void *a, const void *b) {
    Time *timeA = (Time *)a;
    Time *timeB = (Time *)b;

    if (timeA->pontos != timeB->pontos)
        return timeB->pontos - timeA->pontos;
    if (timeA->media != timeB->media)
        return (timeB->media > timeA->media) ? 1 : -1;
    if (timeA->marcados != timeB->marcados)
        return timeB->marcados - timeA->marcados;
    return timeA->time - timeB->time;
}

int main() {
    int n, instancia = 0;

    scanf("%d", &n);
    while (n > 0) {
        int num_jogos = (n * (n - 1)) / 2;
        Jogo *resultados = malloc(num_jogos * 2 * sizeof(Jogo));
        Time *times = malloc(n * sizeof(Time));
        int jogo_index = 0;

        // Inicializa os times
        for (int i = 0; i < n; i++) {
            times[i].time = i + 1;
            times[i].pontos = 0;
            times[i].marcados = 0;
            times[i].recebidos = 0;
            times[i].media = 0.0;
        }

        // Leitura dos jogos
        for (int i = 0; i < num_jogos; i++) {
            int time1, pontos1, time2, pontos2;
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);

            resultados[jogo_index].time = time1;
            resultados[jogo_index].marcados = pontos1;
            resultados[jogo_index].recebidos = pontos2;
            jogo_index++;

            resultados[jogo_index].time = time2;
            resultados[jogo_index].marcados = pontos2;
            resultados[jogo_index].recebidos = pontos1;
            jogo_index++;

            // Atualiza os times
            times[time1 - 1].marcados += pontos1;
            times[time1 - 1].recebidos += pontos2;
            times[time2 - 1].marcados += pontos2;
            times[time2 - 1].recebidos += pontos1;

            if (pontos1 > pontos2) {
                times[time1 - 1].pontos += 2;
                times[time2 - 1].pontos += 1;
            } else {
                times[time2 - 1].pontos += 2;
                times[time1 - 1].pontos += 1;
            }
        }

        // Calcula a média dos times
        for (int i = 0; i < n; i++) {
            times[i].media = calcular_media(times[i].marcados, times[i].recebidos);
        }

        // Ordena os times
        qsort(times, n, sizeof(Time), comparar_times);

        // Imprime os resultados
        if (instancia > 0)
            printf("\n");
        printf("Instancia %d\n", ++instancia);

        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", times[i].time);
        }
        printf("\n");

        // Limpeza
        free(resultados);
        free(times);

        scanf("%d", &n);
    }

    return 0;
}
