#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Team para armazenar número e pontos
typedef struct {
    int number;
    int points;
} Team;

// Função de comparação para ordenar os times
int compare(const void *a, const void *b) {
    Team *teamA = (Team *)a;
    Team *teamB = (Team *)b;

    // Primeiro comparar pelo número de pontos (menos pontos primeiro)
    if (teamA->points != teamB->points) {
        return teamA->points - teamB->points;
    } else {
        // Em caso de empate nos pontos, comparar pelos números dos times (menor número primeiro)
        return teamA->number - teamB->number;
    }
}

int main() {
    int caseNumber = 0;
    
    while (1) {
        int V, P, T;
        scanf("%d %d %d", &V, &P, &T);

        if (V == 0 && P == 0 && T == 0) break;

        caseNumber++;

        int checkpoints[P];
        for (int i = 0; i < P; i++) {
            scanf("%d", &checkpoints[i]);
        }

        int times[T][P];
        for (int i = 0; i < T; i++) {
            for (int j = 0; j < P; j++) {
                scanf("%d", &times[i][j]);
            }
        }

        int totalPoints[T];
        for (int i = 0; i < T; i++) {
            totalPoints[i] = 0;
            for (int j = 0; j < P; j++) {
                int expectedTimeInSeconds = (int)((double)checkpoints[j] / V * 3600);
                int actualTimeInSeconds = times[i][j];
                int difference = actualTimeInSeconds - expectedTimeInSeconds;

                if (difference > 0) {
                    // Atraso, penalização de 1 ponto por segundo de atraso
                    int penaltyPoints = difference <= 1200 ? difference : 1200;
                    totalPoints[i] += penaltyPoints;
                } else if (difference < 0) {
                    // Adiantamento, penalização de 2 pontos por segundo de adiantamento
                    int advancePoints = -difference * 2 <= 1200 ? -difference * 2 : 1200;
                    totalPoints[i] += advancePoints;
                }
            }
        }

        // Criar e ordenar times baseado nos pontos totais
        Team teams[T];
        for (int i = 0; i < T; i++) {
            teams[i].number = i + 1;
            teams[i].points = totalPoints[i];
        }

        // Ordenar times usando a função qsort
        qsort(teams, T, sizeof(Team), compare);

        // Saída formatada em ordem decrescente de pontos
        if (caseNumber > 1) {
            printf("\n");
        }

        for (int i = T - 1; i >= 0; i--) {
            printf(" %d", teams[i].number);
        }
        printf("\n");
    }

    return 0;
}
